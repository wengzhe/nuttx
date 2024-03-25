/****************************************************************************
 * boards/arm/stm32/stm32er-f407ve/include/board.h
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

#ifndef __BOARDS_ARM_STM32_STM32ER_F407VE_INCLUDE_BOARD_H
#define __BOARDS_ARM_STM32_STM32ER_F407VE_INCLUDE_BOARD_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#ifndef __ASSEMBLY__
#  include <stdint.h>
#  include <stdbool.h>
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Clocking *****************************************************************/

/* The stm32er-f407ve board features a 8MHz crystal and
 * a 32kHz RTC backup crystal.
 *
 * This is the canonical configuration:
 *   System Clock source     : PLL (HSE)
 *   SYSCLK(Hz)              : 168000000    Determined by PLL configuration
 *   HCLK(Hz)                : 168000000    (STM32_RCC_CFGR_HPRE)
 *   AHB Prescaler           : 1            (STM32_RCC_CFGR_HPRE)
 *   APB1 Prescaler          : 4            (STM32_RCC_CFGR_PPRE1)
 *   APB2 Prescaler          : 2            (STM32_RCC_CFGR_PPRE2)
 *   HSE Frequency(Hz)       : 8000000      (STM32_BOARD_XTAL)
 *   PLLM                    : 8            (STM32_PLLCFG_PLLM)
 *   PLLN                    : 336          (STM32_PLLCFG_PLLN)
 *   PLLP                    : 2            (STM32_PLLCFG_PLLP)
 *   PLLQ                    : 7            (STM32_PLLCFG_PLLQ)
 *   Main regulator output
 *     voltage               : Scale1 mode  Needed for high speed SYSCLK
 *   Flash Latency(WS)       : 5
 *   Prefetch Buffer         : OFF
 *   Instruction cache       : ON
 *   Data cache              : ON
 *   Require 48MHz for       : Enabled
 *     USB OTG FS,
 *   SDIO and RNG clock
 */

/* HSI - 16 MHz RC factory-trimmed
 * LSI - 32 KHz RC (30-60KHz, uncalibrated)
 * HSE - On-board crystal frequency is 12MHz
 * LSE - 32.768 kHz
 * STM32F407ZGT6 - too 168Mhz
 */

#define STM32_BOARD_XTAL        8000000ul

#define STM32_HSI_FREQUENCY     16000000ul
#define STM32_LSI_FREQUENCY     32000
#define STM32_HSE_FREQUENCY     STM32_BOARD_XTAL
#define STM32_LSE_FREQUENCY     32768

/* Main PLL Configuration.
 *
 * PLL source is HSE
 * PLL_VCO = (STM32_HSE_FREQUENCY / PLLM) * PLLN
 *         = (8,000,000 / 8) * 336
 *         = 336,000,000
 * SYSCLK  = PLL_VCO / PLLP
 *         = 336,000,000 / 2 = 168,000,000
 * USB OTG FS, SDIO and RNG Clock
 *         =  PLL_VCO / PLLQ
 *         = 336,000,000 / 7 = 48,000,000
 *         = 48,000,000
 *
 *  Xtal     /M  *n  /P         SysClk AHB HCLK  APB1     PCLK1
 * 8Mhz HSE  /8  336 /2 PLLCLK 168Mhz  /1  168    /4     42Mhz
 */

#define STM32_PLLCFG_PLLM       RCC_PLLCFG_PLLM(8)
#define STM32_PLLCFG_PLLN       RCC_PLLCFG_PLLN(336)
#define STM32_PLLCFG_PLLP       RCC_PLLCFG_PLLP_2
#define STM32_PLLCFG_PLLQ       RCC_PLLCFG_PLLQ(7)

#define STM32_SYSCLK_FREQUENCY  168000000ul

/* AHB clock (HCLK) is SYSCLK (168MHz) */

#define STM32_RCC_CFGR_HPRE     RCC_CFGR_HPRE_SYSCLK  /* HCLK  = SYSCLK / 1 */
#define STM32_HCLK_FREQUENCY    STM32_SYSCLK_FREQUENCY

/* APB1 clock (PCLK1) is HCLK/4 (42MHz) */

#define STM32_RCC_CFGR_PPRE1    RCC_CFGR_PPRE1_HCLKd4     /* PCLK1 = HCLK / 4 */
#define STM32_PCLK1_FREQUENCY   (STM32_HCLK_FREQUENCY/4)

/* Timers driven from APB1 will be twice PCLK1 */

#define STM32_APB1_TIM2_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM3_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM4_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM5_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM6_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM7_CLKIN   (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM12_CLKIN  (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM13_CLKIN  (2*STM32_PCLK1_FREQUENCY)
#define STM32_APB1_TIM14_CLKIN  (2*STM32_PCLK1_FREQUENCY)

/* APB2 clock (PCLK2) is HCLK/2  */

#define STM32_RCC_CFGR_PPRE2    RCC_CFGR_PPRE2_HCLKd2     /* PCLK2 = HCLK / 2 */
#define STM32_PCLK2_FREQUENCY   (STM32_HCLK_FREQUENCY/2)

/* Timers driven from APB2 will be twice PCLK2 */

#define STM32_APB2_TIM1_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM8_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM9_CLKIN   (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM10_CLKIN  (2*STM32_PCLK2_FREQUENCY)
#define STM32_APB2_TIM11_CLKIN  (2*STM32_PCLK2_FREQUENCY)

/* Timer Frequencies, if APBx is set to 1, frequency is same as APBx
 * otherwise frequency is 2xAPBx.
 * Note: TIM1,8 are on APB2, others on APB1
 */

#define BOARD_TIM1_FREQUENCY    STM32_HCLK_FREQUENCY
#define BOARD_TIM2_FREQUENCY    STM32_HCLK_FREQUENCY
#define BOARD_TIM3_FREQUENCY    STM32_HCLK_FREQUENCY
#define BOARD_TIM4_FREQUENCY    STM32_HCLK_FREQUENCY
#define BOARD_TIM5_FREQUENCY    STM32_HCLK_FREQUENCY
#define BOARD_TIM6_FREQUENCY    STM32_HCLK_FREQUENCY
#define BOARD_TIM7_FREQUENCY    STM32_HCLK_FREQUENCY
#define BOARD_TIM8_FREQUENCY    STM32_HCLK_FREQUENCY

/* Leds *********************************************************************/

/* LED index values for use with board_userled() */

#define BOARD_LED1                0
#define BOARD_LED_RED             BOARD_LED1
#define BOARD_LED2                1
#define BOARD_LED_BLUE            BOARD_LED2
#define BOARD_NLEDS               2

/* LED bits for use with board_userled_all() */

#define BOARD_LED_RED_BIT         (1 << BOARD_LED_RED)
#define BOARD_LED_BLUE_BIT        (1 << BOARD_LED_BLUE)

/* If CONFIG_ARCH_LEDs is defined, then NuttX will control the status LED of
 * the board.
 * The following definitions describe how NuttX controls the LEDs:
 */

#define LED_STARTED       0  /* LED_STATUS on */
#define LED_HEAPALLOCATE  1  /* no change */
#define LED_IRQSENABLED   2  /* no change */
#define LED_STACKCREATED  3  /* no change */
#define LED_INIRQ         4  /* no change */
#define LED_SIGNAL        5  /* no change */
#define LED_ASSERTION     6  /* LED_STATUS off */
#define LED_PANIC         7  /* LED_STATUS blinking */

/* Button definitions *******************************************************/

#define BUTTON_KEY1    0
#define BUTTON_KEY2    1
#define BUTTON_KEY3    2
#define NUM_BUTTONS    3

#define BUTTON_KEY1_BIT (1 << BUTTON_KEY1)
#define BUTTON_KEY2_BIT (1 << BUTTON_KEY2)
#define BUTTON_KEY3_BIT (1 << BUTTON_KEY3)

/* Alternate function pin selections ****************************************/

/* USART1 */

#define GPIO_USART1_TX    GPIO_USART1_TX_1 /* PA9 */
#define GPIO_USART1_RX    GPIO_USART1_RX_1 /* PA10 */

/* USART2 */

#define GPIO_USART2_TX    GPIO_USART2_TX_1 /* PA2 */
#define GPIO_USART2_RX    GPIO_USART2_RX_1 /* PA3 */

/* USART3 */

#define GPIO_USART3_TX    GPIO_USART3_TX_1 /* PB10 */
#define GPIO_USART3_RX    GPIO_USART3_RX_1 /* PB11 */

/* CAN */

#define GPIO_CAN1_TX      GPIO_CAN1_TX_2   /* PB9 */
#define GPIO_CAN1_RX      GPIO_CAN1_RX_2   /* PB8 */

/* I2C */

#define GPIO_I2C1_SCL     GPIO_I2C1_SCL_1  /* PB6 */
#define GPIO_I2C1_SDA     GPIO_I2C1_SDA_1  /* PB7 */

/* SPI1 */

#define GPIO_SPI1_SCK     GPIO_SPI1_SCK_1  /* PA5 */
#define GPIO_SPI1_MISO    GPIO_SPI1_MISO_1 /* PA6 */
#define GPIO_SPI1_MOSI    GPIO_SPI1_MOSI_1 /* PA7 */

#endif /* __BOARDS_ARM_STM32_STM32ER_F407VE_INCLUDE_BOARD_H */
