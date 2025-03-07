/****************************************************************************
 * arch/arm/src/lpc31xx/lpc31_timerisr.c
 *
 * SPDX-License-Identifier: Apache-2.0
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>
#include <time.h>
#include <debug.h>

#include <nuttx/arch.h>
#include <arch/board/board.h>

#include "clock/clock.h"
#include "arm_internal.h"
#include "lpc31_timer.h"
#include "lpc31.h"
#include "lpc31_cgudrvr.h"

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/****************************************************************************
 * Function:  lpc31_timerisr
 *
 * Description:
 *   The timer ISR will perform a variety of services for various portions
 *   of the systems.
 *
 ****************************************************************************/

static int lpc31_timerisr(int irq, uint32_t *regs, void *arg)
{
  /* Clear the lattched timer interrupt (Writing any value to the CLEAR
   * register clears the interrupt generated by the counter timer
   */

  putreg32(1, LPC31_TIMER0_CLEAR);

  /* Process timer interrupt */

  nxsched_process_timer();
  return 0;
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Function:  up_timer_initialize
 *
 * Description:
 *   This function is called during start-up to initialize
 *   the timer interrupt.
 *
 ****************************************************************************/

void up_timer_initialize(void)
{
  uint32_t regval;
  uint64_t load;
  uint64_t freq;

  /* Enable the timer0 system clock */

  lpc31_enableclock(CLKID_TIMER0PCLK);

  /* Soft reset the timer0 module so that we start in a known state */

  lpc31_softreset(RESETID_TIMER0RST);

  /* Set timer load register to 10mS (100Hz).  First, get the frequency
   * of the timer0 module clock (in the AHB0APB1_BASE domain (2)).
   */

  freq = (uint64_t)lpc31_clkfreq(CLKID_TIMER0PCLK, DOMAINID_AHB0APB1);

  /* If the clock is >1MHz, use pre-dividers */

  regval = getreg32(LPC31_TIMER0_CTRL);
  if (freq > 1000000)
    {
      /* Use the divide by 16 pre-divider */

      regval &= ~TIMER_CTRL_PRESCALE_MASK;
      regval |=  TIMER_CTRL_PRESCALE_DIV16;
      freq   >>= 4;
    }

  load = ((freq * (uint64_t)10000) / 1000000);
  putreg32((uint32_t)load, LPC31_TIMER0_LOAD);

  /* Set periodic mode */

  regval |= TIMER_CTRL_PERIODIC;
  putreg32(regval, LPC31_TIMER0_CTRL);

  /* Attach the timer interrupt vector */

  irq_attach(LPC31_IRQ_TMR0, (xcpt_t)lpc31_timerisr, NULL);

  /* Clear any latched timer interrupt (Writing any value to the CLEAR
   * register clears the latched interrupt generated by the counter timer)
   */

  putreg32(1, LPC31_TIMER0_CLEAR);

  /* Enable timers (starts counting) */

  regval |= TIMER_CTRL_ENABLE;
  putreg32(regval, LPC31_TIMER0_CTRL);

  /* Enable timer match interrupts in the interrupt controller */

  up_enable_irq(LPC31_IRQ_TMR0);
}
