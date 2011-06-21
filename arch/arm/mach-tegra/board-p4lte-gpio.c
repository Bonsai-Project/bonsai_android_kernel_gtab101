
/* linux/arch/arm/mach-tegra/board-p4lte-gpio.c
 * Copyright (C) 2010 Samsung Electronics. All rights reserved.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/kernel.h>
#include <mach/gpio-sec.h>

static struct sec_gpio_cfg_st p4_gpio_table_rev05[] = {
/* dedicated to P4 Main Rev05 */
    {GPIO,	GPIO_USB_SEL2,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MAG_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CP_ON_REV05,			GPIO_OUTPUT,	GPIO_INIT_LEVEL_IPC_BACK_POWERING },
    {GPIO,	GPIO_MAG_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_DOCK_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IFCONSENSE,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_FUEL_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_FUEL_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LIGHT_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_THERMAL_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LIGHT_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_THERMAL_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_PDA_ACTIVE,		GPIO_OUTPUT,	GPIO_LEVEL_HIGH},
    {GPIO,	GPIO_REMOTE_SENSE_IRQ,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_EAR_SEND_END,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LVDS_N_SHDN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMAGE_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMA_N_RST,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMA_BYPASS,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMA_SLEEP,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMAGE_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BT_nRST,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {SPIO,	GPIO_HDMI_HPD,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_F_nRST,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_F_nSTBY,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_PMIC_EN1,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_PMIC_EN2,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_R_nRST,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LIGHT_SENSOR_DVI,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BT_EN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV2,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_USB_SEL1_REV05,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_nTHRM_IRQ,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_PMIC_EN3,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BL_RESET,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_EN1,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MOTOR_EN2,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_OTG_EN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_WLAN_HOST_WAKE,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BT_WAKE,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BT_HOST_WAKE,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_EXT_WAKEUP,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_PHONE_ACTIVE,		GPIO_OUTPUT,	GPIO_INIT_LEVEL_IPC_BACK_POWERING },
    {GPIO,	GPIO_WLAN_EN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMA_PWREN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_FUEL_ALRT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_TA_nCHG,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LCD_LDO_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CP_RST,			GPIO_OUTPUT,	GPIO_INIT_LEVEL_IPC_BACK_POWERING },
    {GPIO,	GPIO_CAM_PMIC_EN4,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_TA_EN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CODEC_LDO_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MICBIAS_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_UART_SEL,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_UART_SEL2,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_PMIC_EN5,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_DET_3_5,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ADC_I2C_SCL_REV05,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ADC_I2C_SDA_REV05,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_I2C_SCL_REV05,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_TA_nCONNECTED_REV05,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_I2C_SDA_REV05,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_V_ACCESSORY_5V_REV05,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ACC_INT_REV05,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LCD_EN_REV05,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_TOUCH_RST,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_TOUCH_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CURR_ADJ,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ADC_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MPU_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ACCESSORY_INT,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_LOGIC_I2C_SCL,	GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_TOUCH_EN_REV05,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_LOGIC_I2C_SDA,	GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_AK8975_INT,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MOTOR_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MOTOR_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ACCESSORY_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV3,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV4,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CODEC_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MHL_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MHL_RST,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_EAR_MICBIAS_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV0,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV1,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CODEC_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_SIM_DETECT,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_FLASH_EN_REV05,    GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    
    /* extra sleep gpio setting. */
    {GPIO,	TEGRA_GPIO_PN6,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PBB1,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PBB4,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PBB5,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PJ6,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PS7,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PK6,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PI7,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PG2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PH2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PI4,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },

    {GPIO,	TEGRA_GPIO_PG4,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PG5,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PG6,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PG7,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PH4,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PH5,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PH6,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PH7,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,  TEGRA_GPIO_PU3,         GPIO_OUTPUT,    GPIO_LEVEL_LOW },
    {GPIO,  TEGRA_GPIO_PV0,         GPIO_OUTPUT,    GPIO_LEVEL_LOW },
    {GPIO,  TEGRA_GPIO_PR5,         GPIO_OUTPUT,    GPIO_LEVEL_LOW },

    {GPIO,  TEGRA_GPIO_PQ5,         GPIO_INPUT, GPIO_LEVEL_NONE },  
    {GPIO,  TEGRA_GPIO_PQ6,         GPIO_INPUT, GPIO_LEVEL_NONE }, 
};

static struct sec_gpio_cfg_st p4_gpio_table[] = {
/* dedicated to P4 Main Rev06 */
    {GPIO,	GPIO_USB_SEL2,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MAG_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CP_ON,			GPIO_OUTPUT,	GPIO_INIT_LEVEL_IPC_BACK_POWERING },
    {GPIO,	GPIO_MAG_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_DOCK_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IFCONSENSE,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_FUEL_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_FUEL_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LIGHT_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_THERMAL_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LIGHT_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_THERMAL_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_PDA_ACTIVE,		GPIO_OUTPUT,	GPIO_LEVEL_HIGH },
    {GPIO,	GPIO_REMOTE_SENSE_IRQ,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_EAR_SEND_END,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LVDS_N_SHDN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMAGE_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMA_N_RST,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMA_BYPASS,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMA_SLEEP,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMAGE_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BT_nRST,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {SPIO,	GPIO_HDMI_HPD,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_F_nRST,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_F_nSTBY,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_PMIC_EN1,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_PMIC_EN2,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_R_nRST,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LIGHT_SENSOR_DVI,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BT_EN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV2,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_USB_SEL1,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_nTHRM_IRQ,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_PMIC_EN3,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BL_RESET,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_EN1,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MOTOR_EN2,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_OTG_EN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_WLAN_HOST_WAKE,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BT_WAKE,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_BT_HOST_WAKE,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_EXT_WAKEUP,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_PHONE_ACTIVE,		GPIO_OUTPUT,	GPIO_INIT_LEVEL_IPC_BACK_POWERING },
    {GPIO,	GPIO_WLAN_EN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_IMA_PWREN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_FUEL_ALRT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LTE_ACTIVE,    GPIO_INPUT,	GPIO_LEVEL_NONE  },        
    {GPIO,	GPIO_TA_nCHG,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LCD_LDO_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CP_RST,			GPIO_OUTPUT,	GPIO_INIT_LEVEL_IPC_BACK_POWERING },
    {GPIO,	GPIO_CAM_PMIC_EN4,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_TA_EN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CODEC_LDO_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MICBIAS_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_UART_SEL,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_UART_SEL2,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_DET_3_5,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ADC_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ADC_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_TA_nCONNECTED,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_LCD_EN,			GPIO_OUTPUT,	GPIO_LEVEL_NONE},
    {GPIO,	GPIO_TOUCH_RST,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_TOUCH_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CURR_ADJ,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ADC_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MPU_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ACCESSORY_INT,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_LOGIC_I2C_SCL,	GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HDMI_LOGIC_I2C_SDA,	GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_AK8975_INT,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MOTOR_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MOTOR_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_ACCESSORY_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV3,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV4,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CODEC_I2C_SDA,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MHL_INT,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_MHL_RST,			GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_EAR_MICBIAS_EN,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV0,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_HW_REV1,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CODEC_I2C_SCL,		GPIO_OUTPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_SIM_DETECT,		GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	GPIO_CAM_FLASH_EN,    GPIO_OUTPUT,	GPIO_LEVEL_LOW  },


    /* extra sleep gpio setting. */
    {GPIO,	TEGRA_GPIO_PN6,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PBB1,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PBB4,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PBB5,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PJ6,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PS7,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PK6,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PI7,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PG2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PH2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {GPIO,	TEGRA_GPIO_PI4,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },

    {GPIO,	TEGRA_GPIO_PG4,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PG5,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PG6,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PG7,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PH4,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PH5,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PH6,			GPIO_INPUT,	GPIO_LEVEL_NONE },
    {GPIO,	TEGRA_GPIO_PH7,			GPIO_INPUT,	GPIO_LEVEL_NONE },


    {GPIO,  TEGRA_GPIO_PU3,         GPIO_OUTPUT,    GPIO_LEVEL_LOW },
    {GPIO,  TEGRA_GPIO_PV0,         GPIO_OUTPUT,    GPIO_LEVEL_LOW },
    {GPIO,  TEGRA_GPIO_PR5,         GPIO_OUTPUT,    GPIO_LEVEL_LOW },

    {GPIO,  TEGRA_GPIO_PQ5,         GPIO_INPUT, GPIO_LEVEL_LOW },
    {GPIO,  TEGRA_GPIO_PQ6,         GPIO_INPUT, GPIO_LEVEL_NONE },
};


static struct sec_slp_gpio_cfg_st p4_sleep_gpio_table_rev05[] = {
/* dedicated to P4 Main Rev05 */
    {YES,	GPIO_USB_SEL2,			GPIO_OUTPUT,	GPIO_LEVEL_HIGH },
    {YES,	GPIO_MAG_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_MAG_I2C_SDA,		GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_DOCK_INT,			GPIO_INPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_IFCONSENSE,		GPIO_INPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_FUEL_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_FUEL_I2C_SDA,		GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_LIGHT_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_THERMAL_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_LIGHT_I2C_SDA,		GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_THERMAL_I2C_SDA,		GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_REMOTE_SENSE_IRQ,		GPIO_INPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_EAR_SEND_END,		GPIO_INPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_LVDS_N_SHDN,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_IMAGE_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_IMA_N_RST,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_IMA_BYPASS,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_IMA_SLEEP,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_IMAGE_I2C_SDA,		GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_BT_nRST,			GPIO_OUTPUT,	GPIO_SLP_HOLD_PREVIOUS_LEVEL  },
    {NO,	GPIO_HDMI_HPD,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_CAM_F_nRST,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_CAM_F_nSTBY,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_CAM_PMIC_EN1,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_CAM_PMIC_EN2,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_CAM_R_nRST,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_LIGHT_SENSOR_DVI,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_BT_EN,			GPIO_OUTPUT,	GPIO_SLP_HOLD_PREVIOUS_LEVEL },
    {NO,	GPIO_HW_REV2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_USB_SEL1_REV05,			GPIO_OUTPUT,	GPIO_LEVEL_HIGH },
    {NO,	GPIO_nTHRM_IRQ,			GPIO_OUTPUT,	GPIO_LEVEL_HIGH  },
    {YES,	GPIO_CAM_PMIC_EN3,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_BL_RESET,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_HDMI_EN1,			GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_220_PMIC_PWRON,		GPIO_OUTPUT,	GPIO_LEVEL_HIGH  },	
    {YES,	GPIO_MOTOR_EN2,			GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_OTG_EN,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_WLAN_HOST_WAKE,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_BT_WAKE,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_BT_HOST_WAKE,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_EXT_WAKEUP,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_PHONE_ACTIVE,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_WLAN_EN,			GPIO_OUTPUT,	GPIO_SLP_HOLD_PREVIOUS_LEVEL  },
    {YES,	GPIO_IMA_PWREN,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_FUEL_ALRT,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_TA_nCHG,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_LCD_LDO_EN,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_CP_RST,			GPIO_OUTPUT,	GPIO_CP_ON_PIN_GROUP_SLP_LEVEL },
    {YES,	GPIO_CAM_PMIC_EN4,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_TA_EN,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_CODEC_LDO_EN,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_MICBIAS_EN,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    //{YES,	GPIO_UART_SEL,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },					/* Need to check uart is working */
    //{YES,	GPIO_UART_SEL2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_CAM_PMIC_EN5,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_DET_3_5,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_ADC_I2C_SCL_REV05,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_ADC_I2C_SDA_REV05,		GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_HDMI_I2C_SCL_REV05,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_TA_nCONNECTED_REV05,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_HDMI_I2C_SDA_REV05,		GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_V_ACCESSORY_5V_REV05,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_LCD_EN_REV05,			GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_TOUCH_RST,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_TOUCH_INT,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_CURR_ADJ,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_ADC_INT,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_MPU_INT,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_ACCESSORY_INT,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_HDMI_LOGIC_I2C_SCL,	GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_TOUCH_EN_REV05,			GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_HDMI_LOGIC_I2C_SDA,	GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_AK8975_INT,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_MOTOR_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_MOTOR_I2C_SDA,		GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {YES,	GPIO_ACCESSORY_EN,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_HW_REV3,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_HW_REV4,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_CODEC_I2C_SDA,		GPIO_OUTPUT,	GPIO_I2C_SDA_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_MHL_INT,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_MHL_RST,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_EAR_MICBIAS_EN,		GPIO_OUTPUT,	GPIO_SLP_HOLD_PREVIOUS_LEVEL  },
    {NO,	GPIO_HW_REV0,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {NO,	GPIO_HW_REV1,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
    {YES,	GPIO_CODEC_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
    {NO,	GPIO_SIM_DETECT,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },

    /* extra sleep gpio setting. */

    {YES,	TEGRA_GPIO_PW6,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* BT_UART_TXD */
    {YES,	TEGRA_GPIO_PW7,			GPIO_INPUT,	GPIO_LEVEL_NONE },		/* BT_UART_RXD */
    {NO,	TEGRA_GPIO_PA1,			GPIO_INPUT,	GPIO_LEVEL_NONE },		/* BT_UART_CTS */
    {NO,	TEGRA_GPIO_PC0,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* BT_UART_RTS */

    {YES,	TEGRA_GPIO_PN0,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* I2S_SYNC */
    {YES,	TEGRA_GPIO_PA2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* VOICE_SYNC */
    {YES,	TEGRA_GPIO_PK0,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* JTAG_SET0 */
    {YES,	TEGRA_GPIO_PK1,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* JTAG_SET1 */

    {YES,	TEGRA_GPIO_PC2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* AP_TXD */
    {YES,	TEGRA_GPIO_PC3,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* AP_RXD */

    {YES,	TEGRA_GPIO_PI1,			GPIO_INPUT,	GPIO_LEVEL_NONE },		/* USB_RECOVERY */
};

static struct sec_slp_gpio_cfg_st p4_sleep_gpio_table[] = {
	{YES,	GPIO_USB_SEL2,			GPIO_OUTPUT,	GPIO_LEVEL_HIGH },
	{YES,	GPIO_MAG_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_FUEL_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_LIGHT_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_THERMAL_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_IMAGE_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_IMA_N_RST,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
	{YES,	GPIO_BT_nRST,			GPIO_OUTPUT,	GPIO_SLP_HOLD_PREVIOUS_LEVEL  },
	{YES,	GPIO_CAM_F_nRST,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
	{YES,	GPIO_CAM_PMIC_EN1,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_CAM_PMIC_EN2,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_LIGHT_SENSOR_DVI,		GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
	{YES,	GPIO_BT_EN,			GPIO_OUTPUT,	GPIO_SLP_HOLD_PREVIOUS_LEVEL },
	{YES,	GPIO_USB_SEL1,			GPIO_OUTPUT,	GPIO_LEVEL_HIGH },
	{YES,	GPIO_CAM_PMIC_EN3,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_HDMI_EN1,			GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_220_PMIC_PWRON,		GPIO_OUTPUT,	GPIO_LEVEL_HIGH  },	
	{YES,	GPIO_MOTOR_EN2,			GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_OTG_EN,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
	{YES,	GPIO_WLAN_EN,			GPIO_OUTPUT,	GPIO_SLP_HOLD_PREVIOUS_LEVEL  },
	{YES,	GPIO_IMA_PWREN,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
	{YES,	GPIO_LCD_LDO_EN,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_CP_RST,			GPIO_OUTPUT,	GPIO_CP_ON_PIN_GROUP_SLP_LEVEL },
	{YES,	GPIO_CAM_PMIC_EN4,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_CODEC_LDO_EN,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_MICBIAS_EN,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	//{YES,	GPIO_UART_SEL,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },					/* Need to check uart is working */
	//{YES,	GPIO_UART_SEL2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
	{YES,	GPIO_ADC_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_HDMI_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_LCD_EN,			GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_HDMI_LOGIC_I2C_SCL,	GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_MOTOR_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_ACCESSORY_EN,		GPIO_OUTPUT,	GPIO_LDO_ENABLE_GROUP_SLEEP_LEVEL  },
	{YES,	GPIO_MHL_RST,			GPIO_OUTPUT,	GPIO_LEVEL_LOW  },
	{YES,	GPIO_EAR_MICBIAS_EN,		GPIO_OUTPUT,	GPIO_SLP_HOLD_PREVIOUS_LEVEL  },
	{YES,	GPIO_CODEC_I2C_SCL,		GPIO_OUTPUT,	GPIO_I2C_SCL_GROUP_SLEEP_LEVEL  },
	{YES,	TEGRA_GPIO_PW6,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* BT_UART_TXD */
	{YES,	TEGRA_GPIO_PW7,			GPIO_INPUT,	GPIO_LEVEL_NONE },		/* BT_UART_RXD */
	{YES,	TEGRA_GPIO_PN0,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* I2S_SYNC */
	{YES,	TEGRA_GPIO_PA2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* VOICE_SYNC */
	{YES,	TEGRA_GPIO_PK0,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* JTAG_SET0 */
	{YES,	TEGRA_GPIO_PK1,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* JTAG_SET1 */
	{YES,	TEGRA_GPIO_PC2,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* AP_TXD */
	{YES,	TEGRA_GPIO_PC3,			GPIO_OUTPUT,	GPIO_LEVEL_LOW },		/* AP_RXD */
	{YES,	TEGRA_GPIO_PI1,			GPIO_INPUT,	GPIO_LEVEL_NONE },		/* USB_RECOVERY */
};


void tegra_gpio_register_table(struct sec_gpio_table_st *gpio_table)
{
    if(system_rev > 0x0A){
        gpio_table->init_gpio_table = p4_gpio_table;
        gpio_table->n_init_gpio_table = ARRAY_SIZE(p4_gpio_table);
        gpio_table->sleep_gpio_table = p4_sleep_gpio_table;
        gpio_table->n_sleep_gpio_table = ARRAY_SIZE(p4_sleep_gpio_table);
    }
    else{
        gpio_table->init_gpio_table = p4_gpio_table_rev05;
        gpio_table->n_init_gpio_table = ARRAY_SIZE(p4_gpio_table_rev05);
        gpio_table->sleep_gpio_table = p4_sleep_gpio_table;
        gpio_table->n_sleep_gpio_table = ARRAY_SIZE(p4_sleep_gpio_table_rev05);
    }
}
