/*
 *  linux/arch/arm/kernel/smp_twd.c
 *
 *  Copyright (C) 2002 ARM Ltd.
 *  All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/device.h>
#include <linux/smp.h>
#include <linux/jiffies.h>
#include <linux/clockchips.h>
#include <linux/irq.h>
#include <linux/io.h>
#include <linux/cpufreq.h>

#include <asm/smp_twd.h>
#include <asm/hardware/gic.h>

/* set up by the platform code */
void __iomem *twd_base;

static unsigned long twd_timer_rate;
static unsigned long twd_periphclk_prescaler;
static unsigned long twd_cpu_rate;

static void twd_set_mode(enum clock_event_mode mode,
			struct clock_event_device *clk)
{
	unsigned long ctrl = __raw_readl(twd_base + TWD_TIMER_CONTROL);
	ctrl &= TWD_TIMER_CONTROL_PRESCALE_MASK;

	switch (mode) {
	case CLOCK_EVT_MODE_PERIODIC:
		/* timer load already set up */
		ctrl |= TWD_TIMER_CONTROL_ENABLE | TWD_TIMER_CONTROL_IT_ENABLE
			| TWD_TIMER_CONTROL_PERIODIC;
		break;
	case CLOCK_EVT_MODE_ONESHOT:
		/* period set, and timer enabled in 'next_event' hook */
		ctrl |= TWD_TIMER_CONTROL_IT_ENABLE | TWD_TIMER_CONTROL_ONESHOT;
		break;
	case CLOCK_EVT_MODE_UNUSED:
	case CLOCK_EVT_MODE_SHUTDOWN:
	default:
		break;
	}

	__raw_writel(ctrl, twd_base + TWD_TIMER_CONTROL);
}

static int twd_set_next_event(unsigned long evt,
			struct clock_event_device *unused)
{
	unsigned long ctrl = __raw_readl(twd_base + TWD_TIMER_CONTROL);

	ctrl |= TWD_TIMER_CONTROL_ENABLE;

	__raw_writel(evt, twd_base + TWD_TIMER_COUNTER);
	__raw_writel(ctrl, twd_base + TWD_TIMER_CONTROL);

	return 0;
}

/*
 * local_timer_ack: checks for a local timer interrupt.
 *
 * If a local timer interrupt has occurred, acknowledge and return 1.
 * Otherwise, return 0.
 */
int twd_timer_ack(void)
{
	if (__raw_readl(twd_base + TWD_TIMER_INTSTAT)) {
		__raw_writel(1, twd_base + TWD_TIMER_INTSTAT);
		return 1;
	}

	return 0;
}

/*
 * Recalculate the twd prescaler value when the cpu frequency changes. To
 * prevent early timer interrupts, must be called before changing the cpu
 * frequency if the frequency is increasing, or after if the frequency is
 * decreasing.
 */
static void twd_update_prescaler(void *data)
{
	u32 ctrl;
	int prescaler;
	unsigned long periphclk_rate;

	BUG_ON(twd_periphclk_prescaler == 0 || twd_timer_rate == 0);

	periphclk_rate = twd_cpu_rate / twd_periphclk_prescaler;

	prescaler = DIV_ROUND_UP(periphclk_rate, twd_timer_rate);
	prescaler = clamp(prescaler - 1, 0, 0xFF);

	ctrl = __raw_readl(twd_base + TWD_TIMER_CONTROL);
	ctrl &= ~TWD_TIMER_CONTROL_PRESCALE_MASK;
	ctrl |= prescaler << 8;
	__raw_writel(ctrl, twd_base + TWD_TIMER_CONTROL);
}

static int twd_cpufreq_transition(struct notifier_block *nb,
	unsigned long state, void *data)
{
	struct cpufreq_freqs *freqs = data;
	if (((freqs->new > freqs->old) && state == CPUFREQ_PRECHANGE) ||
	    ((freqs->old > freqs->new) && state == CPUFREQ_POSTCHANGE)) {
		/* freqs->new is in kHz, twd_cpu_rate is in Hz */
		twd_cpu_rate = freqs->new * 1000;

		smp_call_function_single(freqs->cpu, twd_update_prescaler,
			NULL, 1);
	}

	return NOTIFY_OK;
}

static struct notifier_block twd_cpufreq_nb = {
	.notifier_call = twd_cpufreq_transition,
};

static int twd_cpufreq_init(void)
{
	if (twd_cpu_rate)
		return cpufreq_register_notifier(&twd_cpufreq_nb,
			CPUFREQ_TRANSITION_NOTIFIER);

	return 0;
}
core_initcall(twd_cpufreq_init);

static void __cpuinit twd_calibrate_rate(unsigned long target_rate,
	unsigned int periphclk_prescaler)
{
	unsigned long load, count;
	u64 waitjiffies;

	/*
	 * If this is the first time round, we need to work out how fast
	 * the timer ticks
	 */
	if (twd_timer_rate == 0) {
		printk(KERN_INFO "Calibrating local timer... ");

		/* Wait for a tick to start */
		waitjiffies = get_jiffies_64() + 1;

		while (get_jiffies_64() < waitjiffies)
			udelay(10);

		/* OK, now the tick has started, let's get the timer going */
		waitjiffies += 5;

				 /* enable, no interrupt or reload */
		__raw_writel(0x1, twd_base + TWD_TIMER_CONTROL);

				 /* maximum value */
		__raw_writel(0xFFFFFFFFU, twd_base + TWD_TIMER_COUNTER);

		while (get_jiffies_64() < waitjiffies)
			udelay(10);

		count = __raw_readl(twd_base + TWD_TIMER_COUNTER);

		twd_timer_rate = (0xFFFFFFFFU - count) * (HZ / 5);

		/*
		 * If a target rate has been requested, adjust the TWD prescaler
		 * to get the closest lower frequency.
		 */
		if (target_rate) {
			twd_periphclk_prescaler = periphclk_prescaler;

			printk("%lu.%02luMHz, setting to ",
				twd_timer_rate / 1000000,
				(twd_timer_rate / 10000) % 100);
			twd_cpu_rate = twd_timer_rate * periphclk_prescaler;
			twd_timer_rate = target_rate;
			twd_update_prescaler(NULL);
		}

		printk("%lu.%02luMHz.\n", twd_timer_rate / 1000000,
			(twd_timer_rate / 10000) % 100);
	} else {
		if (target_rate) {
			BUG_ON(target_rate != twd_timer_rate);
			twd_update_prescaler(NULL);
		}
	}

	load = twd_timer_rate / HZ;

	__raw_writel(load, twd_base + TWD_TIMER_LOAD);
}

/*
 * Setup the local clock events for a CPU.
 */
static void __cpuinit __twd_timer_setup(struct clock_event_device *clk,
	unsigned long target_rate, unsigned int periphclk_prescaler)
{
	unsigned long flags;

	twd_calibrate_rate(target_rate, periphclk_prescaler);

	clk->name = "local_timer";
	clk->features = CLOCK_EVT_FEAT_PERIODIC | CLOCK_EVT_FEAT_ONESHOT |
			CLOCK_EVT_FEAT_C3STOP;
	clk->rating = 350;
	clk->set_mode = twd_set_mode;
	clk->set_next_event = twd_set_next_event;
	clk->shift = 20;
	clk->mult = div_sc(twd_timer_rate, NSEC_PER_SEC, clk->shift);
	clk->max_delta_ns = clockevent_delta2ns(0xffffffff, clk);
	clk->min_delta_ns = clockevent_delta2ns(0xf, clk);

	/* Make sure our local interrupt controller has this enabled */
	local_irq_save(flags);
	irq_to_desc(clk->irq)->status |= IRQ_NOPROBE;
	get_irq_chip(clk->irq)->unmask(clk->irq);
	local_irq_restore(flags);

	clockevents_register_device(clk);
}

void __cpuinit twd_timer_setup_scalable(struct clock_event_device *clk,
	unsigned long target_rate, unsigned int periphclk_prescaler)
{
	__twd_timer_setup(clk, target_rate, periphclk_prescaler);
}

void __cpuinit twd_timer_setup(struct clock_event_device *clk)
{
	__twd_timer_setup(clk, 0, 0);
}

#ifdef CONFIG_HOTPLUG_CPU
/*
 * take a local timer down
 */
void twd_timer_stop(void)
{
	__raw_writel(0, twd_base + TWD_TIMER_CONTROL);
}
#endif
