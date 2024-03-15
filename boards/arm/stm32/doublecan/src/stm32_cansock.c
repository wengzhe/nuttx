/****************************************************************************
 * boards/arm/stm32/doublecan/src/stm32_cansock.c
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

#include <debug.h>

#include "stm32_can.h"

#ifdef CONFIG_CAN

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Configuration ************************************************************/

#ifdef CONFIG_STM32_CAN1
#  define CAN1_PORT 1
#endif
#ifdef CONFIG_STM32_CAN2
#  define CAN2_PORT 2
#endif

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: stm32_cansock_setup
 *
 * Description:
 *  Initialize CAN socket interface
 *
 ****************************************************************************/

int stm32_cansock_setup(void)
{
#if defined(CONFIG_STM32_CAN1) || defined(CONFIG_STM32_CAN2)
  int ret;

  /* Call stm32_cansockinitialize() to get an instance of the CAN interface */
#if defined(CONFIG_STM32_CAN1)
  ret = stm32_cansockinitialize(CAN1_PORT);
  if (ret < 0)
    {
      canerr("ERROR:  Failed to get CAN interface %d\n", ret);
      return ret;
    }
#endif

#if defined(CONFIG_STM32_CAN2)
  ret = stm32_cansockinitialize(CAN2_PORT);
  if (ret < 0)
    {
      canerr("ERROR:  Failed to get CAN interface %d\n", ret);
      return ret;
    }
#endif

  return OK;
#else
  return -ENODEV;
#endif
}

#endif /* CONFIG_CAN */
