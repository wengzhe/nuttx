/****************************************************************************
 * boards/arm/stm32/doublecan/src/stm32_leds.c
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
 * Unless requiRED1 by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <stdbool.h>
#include <debug.h>

#include <nuttx/board.h>
#include <arch/board/board.h>

#include "stm32.h"
#include "doublecan.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Dump GPIO registers */

#ifdef CONFIG_DEBUG_LEDS_INFO
#  define led_dumpgpio(m) stm32_dumpgpio(GPIO_LED_GREEN1, m)
#else
#  define led_dumpgpio(m)
#endif

/****************************************************************************
 * Private Data
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
static bool g_initialized = false;
#endif

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_led_initialize/board_userled_initialize
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
uint32_t stm32_led_initialize(void)
#else
uint32_t board_userled_initialize(void)
#endif
{
  /* Configure all LED GPIO lines */

  led_dumpgpio("board_*led_initialize() Entry)");

  stm32_configgpio(GPIO_LED_RED0);
  stm32_configgpio(GPIO_LED_GREEN0);
  stm32_configgpio(GPIO_LED_RED1);
  stm32_configgpio(GPIO_LED_GREEN1);

  led_dumpgpio("board_*led_initialize() Exit");
  return BOARD_NLEDS;
}

/****************************************************************************
 * Name: board_userled
 ****************************************************************************/

#ifndef CONFIG_ARCH_LEDS
void board_userled(int led, bool ledon)
{
  switch (led) {
    case BOARD_LED_RED0:
      stm32_gpiowrite(GPIO_LED_RED0, !ledon);
      break;
    case BOARD_LED_GREEN0:
      stm32_gpiowrite(GPIO_LED_GREEN0, !ledon);
      break;
    case BOARD_LED_RED1:
      stm32_gpiowrite(GPIO_LED_RED1, !ledon);
      break;
    case BOARD_LED_GREEN1:
      stm32_gpiowrite(GPIO_LED_GREEN1, !ledon);
      break;
    default:
      break;
  }
}
#endif

/****************************************************************************
 * Name: board_userled_all
 ****************************************************************************/

#ifndef CONFIG_ARCH_LEDS
void board_userled_all(uint32_t ledset)
{
  stm32_gpiowrite(GPIO_LED_RED0, (ledset & BOARD_LED_RED0_BIT) == 0);
  stm32_gpiowrite(GPIO_LED_GREEN0, (ledset & BOARD_LED_GREEN0_BIT) == 0);
  stm32_gpiowrite(GPIO_LED_RED1, (ledset & BOARD_LED_RED1_BIT) == 0);
  stm32_gpiowrite(GPIO_LED_GREEN1, (ledset & BOARD_LED_GREEN1_BIT) == 0);
}
#endif

/****************************************************************************
 * Name: board_autoled_on
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void board_autoled_on(int led)
{
  switch (led)
    {
      default:
      case LED_STARTED:
      case LED_HEAPALLOCATE:
      case LED_IRQSENABLED:
        stm32_gpiowrite(GPIO_LED_GREEN0, false);
        stm32_gpiowrite(GPIO_LED_RED0, false);
        break;

      case LED_STACKCREATED:
        stm32_gpiowrite(GPIO_LED_GREEN0, true);
        stm32_gpiowrite(GPIO_LED_RED0, false);
        g_initialized = true;
        break;

      case LED_INIRQ:
      case LED_SIGNAL:
      case LED_ASSERTION:
      case LED_PANIC:
        stm32_gpiowrite(GPIO_LED_RED0, true);
        break;

      case LED_IDLE : /* IDLE */
        stm32_gpiowrite(GPIO_LED_GREEN0, false);
        break;
    }
}
#endif

/****************************************************************************
 * Name: board_autoled_off
 ****************************************************************************/

#ifdef CONFIG_ARCH_LEDS
void board_autoled_off(int led)
{
  switch (led)
    {
      default:
      case LED_STARTED:
      case LED_HEAPALLOCATE:
      case LED_IRQSENABLED:
      case LED_STACKCREATED:
        stm32_gpiowrite(GPIO_LED_GREEN0, false);

      case LED_INIRQ:
      case LED_SIGNAL:
      case LED_ASSERTION:
      case LED_PANIC:
        stm32_gpiowrite(GPIO_LED_RED0, false);
        break;

      case LED_IDLE: /* IDLE */
        stm32_gpiowrite(GPIO_LED_GREEN0, g_initialized);
        break;
    }
}
#endif
