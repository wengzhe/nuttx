/****************************************************************************
 * arch/arm/src/efm32/hardware/efm32_emu.h
 *
 * SPDX-License-Identifier: BSD-3-Clause
 * SPDX-FileCopyrightText: 2014 Silicon Laboratories, Inc.
 * SPDX-FileCopyrightText: 2014 Pierre-noel Bouteville . All rights reserved.
 * SPDX-FileCopyrightText: 2014 Gregory Nutt. All rights reserved.
 * SPDX-FileContributor: Pierre-noel Bouteville <pnb990@gmail.com>
 * SPDX-FileContributor: Gregory Nutt <gnutt@nuttx.org>
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Silicon Laboratories, Inc.
 * has no obligation to support this Software. Silicon Laboratories, Inc. is
 * providing the Software "AS IS", with no express or implied warranties of
 * any kind, including, but not limited to, any implied warranties of
 * merchantability or fitness for any particular purpose or warranties
 * against infringement of any proprietary rights of a third party.
 *
 * Silicon Laboratories, Inc. will not be liable for any consequential,
 * incidental, or special damages, or any other relief, or for any claim by
 * any third party, arising from your use of this Software.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

#ifndef __ARCH_ARM_SRC_EFM32_HARDWARE_EFM32_EMU_H
#define __ARCH_ARM_SRC_EFM32_HARDWARE_EFM32_EMU_H

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include "hardware/efm32_memorymap.h"

#if !defined(CONFIG_EFM32_EFM32GG)
#  warning This is the EFM32GG header file; Review/modification needed for this architecture
#endif

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* EMU Register Offsets *****************************************************/

#define EFM32_EMU_CTRL_OFFSET                0x0000  /* Control Register */
#define EFM32_EMU_MEMCTRL_OFFSET             0x0004  /* Memory Control Register */
#define EFM32_EMU_LOCK_OFFSET                0x0008  /* Configuration Lock Register */
#define EFM32_EMU_AUXCTRL_OFFSET             0x0024  /* Auxiliary Control Register */
#define EFM32_EMU_EM4CONF_OFFSET             0x002c  /* Energy mode 4 configuration register */
#define EFM32_EMU_BUCTRL_OFFSET              0x0030  /* Backup Power configuration register */
#define EFM32_EMU_PWRCONF_OFFSET             0x0034  /* Power connection configuration register */
#define EFM32_EMU_BUINACT_OFFSET             0x0038  /* Backup mode inactive configuration register */
#define EFM32_EMU_BUACT_OFFSET               0x003c  /* Backup mode active configuration register */
#define EFM32_EMU_STATUS_OFFSET              0x0040  /* status register */
#define EFM32_EMU_ROUTE_OFFSET               0x0044  /* I/O Routing Register */
#define EFM32_EMU_IF_OFFSET                  0x0048  /* Interrupt Flag Register */
#define EFM32_EMU_IFS_OFFSET                 0x004c  /* Interrupt Flag Set Register */
#define EFM32_EMU_IFC_OFFSET                 0x0050  /* Interrupt Flag Clear Register */
#define EFM32_EMU_IEN_OFFSET                 0x0054  /* Interrupt Enable Register */
#define EFM32_EMU_BUBODBUVINCAL_OFFSET       0x0058  /* BU_VIN Backup BOD calibration */
#define EFM32_EMU_BUBODUNREGCAL_OFFSET       0x005c  /* Unregulated power Backup BOD calibration */

/* EMU Register Addresses ***************************************************/

#define EFM32_EMU_CTRL                       (EFM32_EMU_BASE+EFM32_EMU_CTRL_OFFSET)
#define EFM32_EMU_MEMCTRL                    (EFM32_EMU_BASE+EFM32_EMU_MEMCTRL_OFFSET)
#define EFM32_EMU_LOCK                       (EFM32_EMU_BASE+EFM32_EMU_LOCK_OFFSET)
#define EFM32_EMU_AUXCTRL                    (EFM32_EMU_BASE+EFM32_EMU_AUXCTRL_OFFSET)
#define EFM32_EMU_EM4CONF                    (EFM32_EMU_BASE+EFM32_EMU_EM4CONF_OFFSET)
#define EFM32_EMU_BUCTRL                     (EFM32_EMU_BASE+EFM32_EMU_BUCTRL_OFFSET)
#define EFM32_EMU_PWRCONF                    (EFM32_EMU_BASE+EFM32_EMU_PWRCONF_OFFSET)
#define EFM32_EMU_BUINACT                    (EFM32_EMU_BASE+EFM32_EMU_BUINACT_OFFSET)
#define EFM32_EMU_BUACT                      (EFM32_EMU_BASE+EFM32_EMU_BUACT_OFFSET)
#define EFM32_EMU_STATUS                     (EFM32_EMU_BASE+EFM32_EMU_STATUS_OFFSET)
#define EFM32_EMU_ROUTE                      (EFM32_EMU_BASE+EFM32_EMU_ROUTE_OFFSET)
#define EFM32_EMU_IF                         (EFM32_EMU_BASE+EFM32_EMU_IF_OFFSET)
#define EFM32_EMU_IFS                        (EFM32_EMU_BASE+EFM32_EMU_IFS_OFFSET)
#define EFM32_EMU_IFC                        (EFM32_EMU_BASE+EFM32_EMU_IFC_OFFSET)
#define EFM32_EMU_IEN                        (EFM32_EMU_BASE+EFM32_EMU_IEN_OFFSET)
#define EFM32_EMU_BUBODBUVINCAL              (EFM32_EMU_BASE+EFM32_EMU_BUBODBUVINCAL_OFFSET)
#define EFM32_EMU_BUBODUNREGCAL              (EFM32_EMU_BASE+EFM32_EMU_BUBODUNREGCAL_OFFSET)

/* EMU Register Bit Field Definitions ***************************************/

/* Bit fields for EMU CTRL */

#define _EMU_CTRL_RESETVALUE                 0x00000000UL                      /* Default value for EMU_CTRL */
#define _EMU_CTRL_MASK                       0x0000000FUL                      /* Mask for EMU_CTRL */

#define EMU_CTRL_EMVREG                      (0x1UL << 0)                      /* Energy Mode Voltage Regulator Control */
#define _EMU_CTRL_EMVREG_SHIFT               0                                 /* Shift value for EMU_EMVREG */
#define _EMU_CTRL_EMVREG_MASK                0x1UL                             /* Bit mask for EMU_EMVREG */
#define _EMU_CTRL_EMVREG_DEFAULT             0x00000000UL                      /* Mode DEFAULT for EMU_CTRL */
#define _EMU_CTRL_EMVREG_REDUCED             0x00000000UL                      /* Mode REDUCED for EMU_CTRL */
#define _EMU_CTRL_EMVREG_FULL                0x00000001UL                      /* Mode FULL for EMU_CTRL */
#define EMU_CTRL_EMVREG_DEFAULT              (_EMU_CTRL_EMVREG_DEFAULT << 0)   /* Shifted mode DEFAULT for EMU_CTRL */
#define EMU_CTRL_EMVREG_REDUCED              (_EMU_CTRL_EMVREG_REDUCED << 0)   /* Shifted mode REDUCED for EMU_CTRL */
#define EMU_CTRL_EMVREG_FULL                 (_EMU_CTRL_EMVREG_FULL << 0)      /* Shifted mode FULL for EMU_CTRL */
#define EMU_CTRL_EM2BLOCK                    (0x1UL << 1)                      /* Energy Mode 2 Block */
#define _EMU_CTRL_EM2BLOCK_SHIFT             1                                 /* Shift value for EMU_EM2BLOCK */
#define _EMU_CTRL_EM2BLOCK_MASK              0x2UL                             /* Bit mask for EMU_EM2BLOCK */
#define _EMU_CTRL_EM2BLOCK_DEFAULT           0x00000000UL                      /* Mode DEFAULT for EMU_CTRL */
#define EMU_CTRL_EM2BLOCK_DEFAULT            (_EMU_CTRL_EM2BLOCK_DEFAULT << 1) /* Shifted mode DEFAULT for EMU_CTRL */
#define _EMU_CTRL_EM4CTRL_SHIFT              2                                 /* Shift value for EMU_EM4CTRL */
#define _EMU_CTRL_EM4CTRL_MASK               0xCUL                             /* Bit mask for EMU_EM4CTRL */
#define _EMU_CTRL_EM4CTRL_DEFAULT            0x00000000UL                      /* Mode DEFAULT for EMU_CTRL */
#define EMU_CTRL_EM4CTRL_DEFAULT             (_EMU_CTRL_EM4CTRL_DEFAULT << 2)  /* Shifted mode DEFAULT for EMU_CTRL */

/* Bit fields for EMU MEMCTRL */

#define _EMU_MEMCTRL_RESETVALUE              0x00000000UL                          /* Default value for EMU_MEMCTRL */
#define _EMU_MEMCTRL_MASK                    0x00000007UL                          /* Mask for EMU_MEMCTRL */

#define _EMU_MEMCTRL_POWERDOWN_SHIFT         0                                     /* Shift value for EMU_POWERDOWN */
#define _EMU_MEMCTRL_POWERDOWN_MASK          0x7UL                                 /* Bit mask for EMU_POWERDOWN */
#define _EMU_MEMCTRL_POWERDOWN_DEFAULT       0x00000000UL                          /* Mode DEFAULT for EMU_MEMCTRL */
#define _EMU_MEMCTRL_POWERDOWN_BLK3          0x00000004UL                          /* Mode BLK3 for EMU_MEMCTRL */
#define _EMU_MEMCTRL_POWERDOWN_BLK23         0x00000006UL                          /* Mode BLK23 for EMU_MEMCTRL */
#define _EMU_MEMCTRL_POWERDOWN_BLK123        0x00000007UL                          /* Mode BLK123 for EMU_MEMCTRL */
#define EMU_MEMCTRL_POWERDOWN_DEFAULT        (_EMU_MEMCTRL_POWERDOWN_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_MEMCTRL */
#define EMU_MEMCTRL_POWERDOWN_BLK3           (_EMU_MEMCTRL_POWERDOWN_BLK3 << 0)    /* Shifted mode BLK3 for EMU_MEMCTRL */
#define EMU_MEMCTRL_POWERDOWN_BLK23          (_EMU_MEMCTRL_POWERDOWN_BLK23 << 0)   /* Shifted mode BLK23 for EMU_MEMCTRL */
#define EMU_MEMCTRL_POWERDOWN_BLK123         (_EMU_MEMCTRL_POWERDOWN_BLK123 << 0)  /* Shifted mode BLK123 for EMU_MEMCTRL */

/* Bit fields for EMU LOCK */

#define _EMU_LOCK_RESETVALUE                 0x00000000UL                      /* Default value for EMU_LOCK */
#define _EMU_LOCK_MASK                       0x0000FFFFUL                      /* Mask for EMU_LOCK */

#define _EMU_LOCK_LOCKKEY_SHIFT              0                                 /* Shift value for EMU_LOCKKEY */
#define _EMU_LOCK_LOCKKEY_MASK               0xFFFFUL                          /* Bit mask for EMU_LOCKKEY */
#define _EMU_LOCK_LOCKKEY_DEFAULT            0x00000000UL                      /* Mode DEFAULT for EMU_LOCK */
#define _EMU_LOCK_LOCKKEY_LOCK               0x00000000UL                      /* Mode LOCK for EMU_LOCK */
#define _EMU_LOCK_LOCKKEY_UNLOCKED           0x00000000UL                      /* Mode UNLOCKED for EMU_LOCK */
#define _EMU_LOCK_LOCKKEY_LOCKED             0x00000001UL                      /* Mode LOCKED for EMU_LOCK */
#define _EMU_LOCK_LOCKKEY_UNLOCK             0x0000ADE8UL                      /* Mode UNLOCK for EMU_LOCK */
#define EMU_LOCK_LOCKKEY_DEFAULT             (_EMU_LOCK_LOCKKEY_DEFAULT << 0)  /* Shifted mode DEFAULT for EMU_LOCK */
#define EMU_LOCK_LOCKKEY_LOCK                (_EMU_LOCK_LOCKKEY_LOCK << 0)     /* Shifted mode LOCK for EMU_LOCK */
#define EMU_LOCK_LOCKKEY_UNLOCKED            (_EMU_LOCK_LOCKKEY_UNLOCKED << 0) /* Shifted mode UNLOCKED for EMU_LOCK */
#define EMU_LOCK_LOCKKEY_LOCKED              (_EMU_LOCK_LOCKKEY_LOCKED << 0)   /* Shifted mode LOCKED for EMU_LOCK */
#define EMU_LOCK_LOCKKEY_UNLOCK              (_EMU_LOCK_LOCKKEY_UNLOCK << 0)   /* Shifted mode UNLOCK for EMU_LOCK */

/* Bit fields for EMU AUXCTRL */

#define _EMU_AUXCTRL_RESETVALUE              0x00000000UL                             /* Default value for EMU_AUXCTRL */
#define _EMU_AUXCTRL_MASK                    0x00000101UL                             /* Mask for EMU_AUXCTRL */

#define EMU_AUXCTRL_HRCCLR                   (0x1UL << 0)                             /* Hard Reset Cause Clear */
#define _EMU_AUXCTRL_HRCCLR_SHIFT            0                                        /* Shift value for EMU_HRCCLR */
#define _EMU_AUXCTRL_HRCCLR_MASK             0x1UL                                    /* Bit mask for EMU_HRCCLR */
#define _EMU_AUXCTRL_HRCCLR_DEFAULT          0x00000000UL                             /* Mode DEFAULT for EMU_AUXCTRL */
#define EMU_AUXCTRL_HRCCLR_DEFAULT           (_EMU_AUXCTRL_HRCCLR_DEFAULT << 0)       /* Shifted mode DEFAULT for EMU_AUXCTRL */
#define EMU_AUXCTRL_REDLFXOBOOST             (0x1UL << 8)                             /* Reduce LFXO Start-up Boost Current */
#define _EMU_AUXCTRL_REDLFXOBOOST_SHIFT      8                                        /* Shift value for EMU_REDLFXOBOOST */
#define _EMU_AUXCTRL_REDLFXOBOOST_MASK       0x100UL                                  /* Bit mask for EMU_REDLFXOBOOST */
#define _EMU_AUXCTRL_REDLFXOBOOST_DEFAULT    0x00000000UL                             /* Mode DEFAULT for EMU_AUXCTRL */
#define EMU_AUXCTRL_REDLFXOBOOST_DEFAULT     (_EMU_AUXCTRL_REDLFXOBOOST_DEFAULT << 8) /* Shifted mode DEFAULT for EMU_AUXCTRL */

/* Bit fields for EMU EM4CONF */

#define _EMU_EM4CONF_RESETVALUE              0x00000000UL                            /* Default value for EMU_EM4CONF */
#define _EMU_EM4CONF_MASK                    0x0001001FUL                            /* Mask for EMU_EM4CONF */

#define EMU_EM4CONF_VREGEN                   (0x1UL << 0)                            /* EM4 voltage regulator enable */
#define _EMU_EM4CONF_VREGEN_SHIFT            0                                       /* Shift value for EMU_VREGEN */
#define _EMU_EM4CONF_VREGEN_MASK             0x1UL                                   /* Bit mask for EMU_VREGEN */
#define _EMU_EM4CONF_VREGEN_DEFAULT          0x00000000UL                            /* Mode DEFAULT for EMU_EM4CONF */
#define EMU_EM4CONF_VREGEN_DEFAULT           (_EMU_EM4CONF_VREGEN_DEFAULT << 0)      /* Shifted mode DEFAULT for EMU_EM4CONF */
#define EMU_EM4CONF_BURTCWU                  (0x1UL << 1)                            /* Backup RTC EM4 wakeup enable */
#define _EMU_EM4CONF_BURTCWU_SHIFT           1                                       /* Shift value for EMU_BURTCWU */
#define _EMU_EM4CONF_BURTCWU_MASK            0x2UL                                   /* Bit mask for EMU_BURTCWU */
#define _EMU_EM4CONF_BURTCWU_DEFAULT         0x00000000UL                            /* Mode DEFAULT for EMU_EM4CONF */
#define EMU_EM4CONF_BURTCWU_DEFAULT          (_EMU_EM4CONF_BURTCWU_DEFAULT << 1)     /* Shifted mode DEFAULT for EMU_EM4CONF */
#define _EMU_EM4CONF_OSC_SHIFT               2                                       /* Shift value for EMU_OSC */
#define _EMU_EM4CONF_OSC_MASK                0xCUL                                   /* Bit mask for EMU_OSC */
#define _EMU_EM4CONF_OSC_DEFAULT             0x00000000UL                            /* Mode DEFAULT for EMU_EM4CONF */
#define _EMU_EM4CONF_OSC_ULFRCO              0x00000000UL                            /* Mode ULFRCO for EMU_EM4CONF */
#define _EMU_EM4CONF_OSC_LFRCO               0x00000001UL                            /* Mode LFRCO for EMU_EM4CONF */
#define _EMU_EM4CONF_OSC_LFXO                0x00000002UL                            /* Mode LFXO for EMU_EM4CONF */
#define EMU_EM4CONF_OSC_DEFAULT              (_EMU_EM4CONF_OSC_DEFAULT << 2)         /* Shifted mode DEFAULT for EMU_EM4CONF */
#define EMU_EM4CONF_OSC_ULFRCO               (_EMU_EM4CONF_OSC_ULFRCO << 2)          /* Shifted mode ULFRCO for EMU_EM4CONF */
#define EMU_EM4CONF_OSC_LFRCO                (_EMU_EM4CONF_OSC_LFRCO << 2)           /* Shifted mode LFRCO for EMU_EM4CONF */
#define EMU_EM4CONF_OSC_LFXO                 (_EMU_EM4CONF_OSC_LFXO << 2)            /* Shifted mode LFXO for EMU_EM4CONF */
#define EMU_EM4CONF_BUBODRSTDIS              (0x1UL << 4)                            /* Disable reset from Backup BOD in EM4 */
#define _EMU_EM4CONF_BUBODRSTDIS_SHIFT       4                                       /* Shift value for EMU_BUBODRSTDIS */
#define _EMU_EM4CONF_BUBODRSTDIS_MASK        0x10UL                                  /* Bit mask for EMU_BUBODRSTDIS */
#define _EMU_EM4CONF_BUBODRSTDIS_DEFAULT     0x00000000UL                            /* Mode DEFAULT for EMU_EM4CONF */
#define EMU_EM4CONF_BUBODRSTDIS_DEFAULT      (_EMU_EM4CONF_BUBODRSTDIS_DEFAULT << 4) /* Shifted mode DEFAULT for EMU_EM4CONF */
#define EMU_EM4CONF_LOCKCONF                 (0x1UL << 16)                           /* EM4 configuration lock enable */
#define _EMU_EM4CONF_LOCKCONF_SHIFT          16                                      /* Shift value for EMU_LOCKCONF */
#define _EMU_EM4CONF_LOCKCONF_MASK           0x10000UL                               /* Bit mask for EMU_LOCKCONF */
#define _EMU_EM4CONF_LOCKCONF_DEFAULT        0x00000000UL                            /* Mode DEFAULT for EMU_EM4CONF */
#define EMU_EM4CONF_LOCKCONF_DEFAULT         (_EMU_EM4CONF_LOCKCONF_DEFAULT << 16)   /* Shifted mode DEFAULT for EMU_EM4CONF */

/* Bit fields for EMU BUCTRL */

#define _EMU_BUCTRL_RESETVALUE               0x00000000UL                      /* Default value for EMU_BUCTRL */
#define _EMU_BUCTRL_MASK                     0x00000067UL                      /* Mask for EMU_BUCTRL */

#define EMU_BUCTRL_EN                        (0x1UL << 0)                      /* Enable backup mode */
#define _EMU_BUCTRL_EN_SHIFT                 0                                 /* Shift value for EMU_EN */
#define _EMU_BUCTRL_EN_MASK                  0x1UL                             /* Bit mask for EMU_EN */
#define _EMU_BUCTRL_EN_DEFAULT               0x00000000UL                      /* Mode DEFAULT for EMU_BUCTRL */
#define EMU_BUCTRL_EN_DEFAULT                (_EMU_BUCTRL_EN_DEFAULT << 0)     /* Shifted mode DEFAULT for EMU_BUCTRL */
#define EMU_BUCTRL_STATEN                    (0x1UL << 1)                      /* Enable backup mode status export */
#define _EMU_BUCTRL_STATEN_SHIFT             1                                 /* Shift value for EMU_STATEN */
#define _EMU_BUCTRL_STATEN_MASK              0x2UL                             /* Bit mask for EMU_STATEN */
#define _EMU_BUCTRL_STATEN_DEFAULT           0x00000000UL                      /* Mode DEFAULT for EMU_BUCTRL */
#define EMU_BUCTRL_STATEN_DEFAULT            (_EMU_BUCTRL_STATEN_DEFAULT << 1) /* Shifted mode DEFAULT for EMU_BUCTRL */
#define EMU_BUCTRL_BODCAL                    (0x1UL << 2)                      /* Enable BOD calibration mode */
#define _EMU_BUCTRL_BODCAL_SHIFT             2                                 /* Shift value for EMU_BODCAL */
#define _EMU_BUCTRL_BODCAL_MASK              0x4UL                             /* Bit mask for EMU_BODCAL */
#define _EMU_BUCTRL_BODCAL_DEFAULT           0x00000000UL                      /* Mode DEFAULT for EMU_BUCTRL */
#define EMU_BUCTRL_BODCAL_DEFAULT            (_EMU_BUCTRL_BODCAL_DEFAULT << 2) /* Shifted mode DEFAULT for EMU_BUCTRL */
#define _EMU_BUCTRL_PROBE_SHIFT              5                                 /* Shift value for EMU_PROBE */
#define _EMU_BUCTRL_PROBE_MASK               0x60UL                            /* Bit mask for EMU_PROBE */
#define _EMU_BUCTRL_PROBE_DEFAULT            0x00000000UL                      /* Mode DEFAULT for EMU_BUCTRL */
#define _EMU_BUCTRL_PROBE_DISABLE            0x00000000UL                      /* Mode DISABLE for EMU_BUCTRL */
#define _EMU_BUCTRL_PROBE_VDDDREG            0x00000001UL                      /* Mode VDDDREG for EMU_BUCTRL */
#define _EMU_BUCTRL_PROBE_BUIN               0x00000002UL                      /* Mode BUIN for EMU_BUCTRL */
#define _EMU_BUCTRL_PROBE_BUOUT              0x00000003UL                      /* Mode BUOUT for EMU_BUCTRL */
#define EMU_BUCTRL_PROBE_DEFAULT             (_EMU_BUCTRL_PROBE_DEFAULT << 5)  /* Shifted mode DEFAULT for EMU_BUCTRL */
#define EMU_BUCTRL_PROBE_DISABLE             (_EMU_BUCTRL_PROBE_DISABLE << 5)  /* Shifted mode DISABLE for EMU_BUCTRL */
#define EMU_BUCTRL_PROBE_VDDDREG             (_EMU_BUCTRL_PROBE_VDDDREG << 5)  /* Shifted mode VDDDREG for EMU_BUCTRL */
#define EMU_BUCTRL_PROBE_BUIN                (_EMU_BUCTRL_PROBE_BUIN << 5)     /* Shifted mode BUIN for EMU_BUCTRL */
#define EMU_BUCTRL_PROBE_BUOUT               (_EMU_BUCTRL_PROBE_BUOUT << 5)    /* Shifted mode BUOUT for EMU_BUCTRL */

/* Bit fields for EMU PWRCONF */

#define _EMU_PWRCONF_RESETVALUE              0x00000000UL                           /* Default value for EMU_PWRCONF */
#define _EMU_PWRCONF_MASK                    0x0000001FUL                           /* Mask for EMU_PWRCONF */

#define EMU_PWRCONF_VOUTWEAK                 (0x1UL << 0)                           /* BU_VOUT weak enable */
#define _EMU_PWRCONF_VOUTWEAK_SHIFT          0                                      /* Shift value for EMU_VOUTWEAK */
#define _EMU_PWRCONF_VOUTWEAK_MASK           0x1UL                                  /* Bit mask for EMU_VOUTWEAK */
#define _EMU_PWRCONF_VOUTWEAK_DEFAULT        0x00000000UL                           /* Mode DEFAULT for EMU_PWRCONF */
#define EMU_PWRCONF_VOUTWEAK_DEFAULT         (_EMU_PWRCONF_VOUTWEAK_DEFAULT << 0)   /* Shifted mode DEFAULT for EMU_PWRCONF */
#define EMU_PWRCONF_VOUTMED                  (0x1UL << 1)                           /* BU_VOUT medium enable */
#define _EMU_PWRCONF_VOUTMED_SHIFT           1                                      /* Shift value for EMU_VOUTMED */
#define _EMU_PWRCONF_VOUTMED_MASK            0x2UL                                  /* Bit mask for EMU_VOUTMED */
#define _EMU_PWRCONF_VOUTMED_DEFAULT         0x00000000UL                           /* Mode DEFAULT for EMU_PWRCONF */
#define EMU_PWRCONF_VOUTMED_DEFAULT          (_EMU_PWRCONF_VOUTMED_DEFAULT << 1)    /* Shifted mode DEFAULT for EMU_PWRCONF */
#define EMU_PWRCONF_VOUTSTRONG               (0x1UL << 2)                           /* BU_VOUT strong enable */
#define _EMU_PWRCONF_VOUTSTRONG_SHIFT        2                                      /* Shift value for EMU_VOUTSTRONG */
#define _EMU_PWRCONF_VOUTSTRONG_MASK         0x4UL                                  /* Bit mask for EMU_VOUTSTRONG */
#define _EMU_PWRCONF_VOUTSTRONG_DEFAULT      0x00000000UL                           /* Mode DEFAULT for EMU_PWRCONF */
#define EMU_PWRCONF_VOUTSTRONG_DEFAULT       (_EMU_PWRCONF_VOUTSTRONG_DEFAULT << 2) /* Shifted mode DEFAULT for EMU_PWRCONF */
#define _EMU_PWRCONF_PWRRES_SHIFT            3                                      /* Shift value for EMU_PWRRES */
#define _EMU_PWRCONF_PWRRES_MASK             0x18UL                                 /* Bit mask for EMU_PWRRES */
#define _EMU_PWRCONF_PWRRES_DEFAULT          0x00000000UL                           /* Mode DEFAULT for EMU_PWRCONF */
#define _EMU_PWRCONF_PWRRES_RES0             0x00000000UL                           /* Mode RES0 for EMU_PWRCONF */
#define _EMU_PWRCONF_PWRRES_RES1             0x00000001UL                           /* Mode RES1 for EMU_PWRCONF */
#define _EMU_PWRCONF_PWRRES_RES2             0x00000002UL                           /* Mode RES2 for EMU_PWRCONF */
#define _EMU_PWRCONF_PWRRES_RES3             0x00000003UL                           /* Mode RES3 for EMU_PWRCONF */
#define EMU_PWRCONF_PWRRES_DEFAULT           (_EMU_PWRCONF_PWRRES_DEFAULT << 3)     /* Shifted mode DEFAULT for EMU_PWRCONF */
#define EMU_PWRCONF_PWRRES_RES0              (_EMU_PWRCONF_PWRRES_RES0 << 3)        /* Shifted mode RES0 for EMU_PWRCONF */
#define EMU_PWRCONF_PWRRES_RES1              (_EMU_PWRCONF_PWRRES_RES1 << 3)        /* Shifted mode RES1 for EMU_PWRCONF */
#define EMU_PWRCONF_PWRRES_RES2              (_EMU_PWRCONF_PWRRES_RES2 << 3)        /* Shifted mode RES2 for EMU_PWRCONF */
#define EMU_PWRCONF_PWRRES_RES3              (_EMU_PWRCONF_PWRRES_RES3 << 3)        /* Shifted mode RES3 for EMU_PWRCONF */

/* Bit fields for EMU BUINACT */

#define _EMU_BUINACT_RESETVALUE              0x0000000BUL                          /* Default value for EMU_BUINACT */
#define _EMU_BUINACT_MASK                    0x0000007FUL                          /* Mask for EMU_BUINACT */

#define _EMU_BUINACT_BUENTHRES_SHIFT         0                                     /* Shift value for EMU_BUENTHRES */
#define _EMU_BUINACT_BUENTHRES_MASK          0x7UL                                 /* Bit mask for EMU_BUENTHRES */
#define _EMU_BUINACT_BUENTHRES_DEFAULT       0x00000003UL                          /* Mode DEFAULT for EMU_BUINACT */
#define EMU_BUINACT_BUENTHRES_DEFAULT        (_EMU_BUINACT_BUENTHRES_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_BUINACT */
#define _EMU_BUINACT_BUENRANGE_SHIFT         3                                     /* Shift value for EMU_BUENRANGE */
#define _EMU_BUINACT_BUENRANGE_MASK          0x18UL                                /* Bit mask for EMU_BUENRANGE */
#define _EMU_BUINACT_BUENRANGE_DEFAULT       0x00000001UL                          /* Mode DEFAULT for EMU_BUINACT */
#define EMU_BUINACT_BUENRANGE_DEFAULT        (_EMU_BUINACT_BUENRANGE_DEFAULT << 3) /* Shifted mode DEFAULT for EMU_BUINACT */
#define _EMU_BUINACT_PWRCON_SHIFT            5                                     /* Shift value for EMU_PWRCON */
#define _EMU_BUINACT_PWRCON_MASK             0x60UL                                /* Bit mask for EMU_PWRCON */
#define _EMU_BUINACT_PWRCON_DEFAULT          0x00000000UL                          /* Mode DEFAULT for EMU_BUINACT */
#define _EMU_BUINACT_PWRCON_NONE             0x00000000UL                          /* Mode NONE for EMU_BUINACT */
#define _EMU_BUINACT_PWRCON_BUMAIN           0x00000001UL                          /* Mode BUMAIN for EMU_BUINACT */
#define _EMU_BUINACT_PWRCON_MAINBU           0x00000002UL                          /* Mode MAINBU for EMU_BUINACT */
#define _EMU_BUINACT_PWRCON_NODIODE          0x00000003UL                          /* Mode NODIODE for EMU_BUINACT */
#define EMU_BUINACT_PWRCON_DEFAULT           (_EMU_BUINACT_PWRCON_DEFAULT << 5)    /* Shifted mode DEFAULT for EMU_BUINACT */
#define EMU_BUINACT_PWRCON_NONE              (_EMU_BUINACT_PWRCON_NONE << 5)       /* Shifted mode NONE for EMU_BUINACT */
#define EMU_BUINACT_PWRCON_BUMAIN            (_EMU_BUINACT_PWRCON_BUMAIN << 5)     /* Shifted mode BUMAIN for EMU_BUINACT */
#define EMU_BUINACT_PWRCON_MAINBU            (_EMU_BUINACT_PWRCON_MAINBU << 5)     /* Shifted mode MAINBU for EMU_BUINACT */
#define EMU_BUINACT_PWRCON_NODIODE           (_EMU_BUINACT_PWRCON_NODIODE << 5)    /* Shifted mode NODIODE for EMU_BUINACT */

/* Bit fields for EMU BUACT */

#define _EMU_BUACT_RESETVALUE                0x0000000BUL                        /* Default value for EMU_BUACT */
#define _EMU_BUACT_MASK                      0x0000007FUL                        /* Mask for EMU_BUACT */

#define _EMU_BUACT_BUEXTHRES_SHIFT           0                                   /* Shift value for EMU_BUEXTHRES */
#define _EMU_BUACT_BUEXTHRES_MASK            0x7UL                               /* Bit mask for EMU_BUEXTHRES */
#define _EMU_BUACT_BUEXTHRES_DEFAULT         0x00000003UL                        /* Mode DEFAULT for EMU_BUACT */
#define EMU_BUACT_BUEXTHRES_DEFAULT          (_EMU_BUACT_BUEXTHRES_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_BUACT */
#define _EMU_BUACT_BUEXRANGE_SHIFT           3                                   /* Shift value for EMU_BUEXRANGE */
#define _EMU_BUACT_BUEXRANGE_MASK            0x18UL                              /* Bit mask for EMU_BUEXRANGE */
#define _EMU_BUACT_BUEXRANGE_DEFAULT         0x00000001UL                        /* Mode DEFAULT for EMU_BUACT */
#define EMU_BUACT_BUEXRANGE_DEFAULT          (_EMU_BUACT_BUEXRANGE_DEFAULT << 3) /* Shifted mode DEFAULT for EMU_BUACT */
#define _EMU_BUACT_PWRCON_SHIFT              5                                   /* Shift value for EMU_PWRCON */
#define _EMU_BUACT_PWRCON_MASK               0x60UL                              /* Bit mask for EMU_PWRCON */
#define _EMU_BUACT_PWRCON_DEFAULT            0x00000000UL                        /* Mode DEFAULT for EMU_BUACT */
#define _EMU_BUACT_PWRCON_NONE               0x00000000UL                        /* Mode NONE for EMU_BUACT */
#define _EMU_BUACT_PWRCON_BUMAIN             0x00000001UL                        /* Mode BUMAIN for EMU_BUACT */
#define _EMU_BUACT_PWRCON_MAINBU             0x00000002UL                        /* Mode MAINBU for EMU_BUACT */
#define _EMU_BUACT_PWRCON_NODIODE            0x00000003UL                        /* Mode NODIODE for EMU_BUACT */
#define EMU_BUACT_PWRCON_DEFAULT             (_EMU_BUACT_PWRCON_DEFAULT << 5)    /* Shifted mode DEFAULT for EMU_BUACT */
#define EMU_BUACT_PWRCON_NONE                (_EMU_BUACT_PWRCON_NONE << 5)       /* Shifted mode NONE for EMU_BUACT */
#define EMU_BUACT_PWRCON_BUMAIN              (_EMU_BUACT_PWRCON_BUMAIN << 5)     /* Shifted mode BUMAIN for EMU_BUACT */
#define EMU_BUACT_PWRCON_MAINBU              (_EMU_BUACT_PWRCON_MAINBU << 5)     /* Shifted mode MAINBU for EMU_BUACT */
#define EMU_BUACT_PWRCON_NODIODE             (_EMU_BUACT_PWRCON_NODIODE << 5)    /* Shifted mode NODIODE for EMU_BUACT */

/* Bit fields for EMU STATUS */

#define _EMU_STATUS_RESETVALUE               0x00000000UL                     /* Default value for EMU_STATUS */
#define _EMU_STATUS_MASK                     0x00000001UL                     /* Mask for EMU_STATUS */

#define EMU_STATUS_BURDY                     (0x1UL << 0)                     /* Backup mode ready */
#define _EMU_STATUS_BURDY_SHIFT              0                                /* Shift value for EMU_BURDY */
#define _EMU_STATUS_BURDY_MASK               0x1UL                            /* Bit mask for EMU_BURDY */
#define _EMU_STATUS_BURDY_DEFAULT            0x00000000UL                     /* Mode DEFAULT for EMU_STATUS */
#define EMU_STATUS_BURDY_DEFAULT             (_EMU_STATUS_BURDY_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_STATUS */

/* Bit fields for EMU ROUTE */

#define _EMU_ROUTE_RESETVALUE                0x00000001UL                       /* Default value for EMU_ROUTE */
#define _EMU_ROUTE_MASK                      0x00000001UL                       /* Mask for EMU_ROUTE */

#define EMU_ROUTE_BUVINPEN                   (0x1UL << 0)                       /* BU_VIN Pin Enable */
#define _EMU_ROUTE_BUVINPEN_SHIFT            0                                  /* Shift value for EMU_BUVINPEN */
#define _EMU_ROUTE_BUVINPEN_MASK             0x1UL                              /* Bit mask for EMU_BUVINPEN */
#define _EMU_ROUTE_BUVINPEN_DEFAULT          0x00000001UL                       /* Mode DEFAULT for EMU_ROUTE */
#define EMU_ROUTE_BUVINPEN_DEFAULT           (_EMU_ROUTE_BUVINPEN_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_ROUTE */

/* Bit fields for EMU IF */

#define _EMU_IF_RESETVALUE                   0x00000000UL                 /* Default value for EMU_IF */
#define _EMU_IF_MASK                         0x00000001UL                 /* Mask for EMU_IF */

#define EMU_IF_BURDY                         (0x1UL << 0)                 /* Backup functionality ready Interrupt Flag */
#define _EMU_IF_BURDY_SHIFT                  0                            /* Shift value for EMU_BURDY */
#define _EMU_IF_BURDY_MASK                   0x1UL                        /* Bit mask for EMU_BURDY */
#define _EMU_IF_BURDY_DEFAULT                0x00000000UL                 /* Mode DEFAULT for EMU_IF */
#define EMU_IF_BURDY_DEFAULT                 (_EMU_IF_BURDY_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_IF */

/* Bit fields for EMU IFS */

#define _EMU_IFS_RESETVALUE                  0x00000000UL                  /* Default value for EMU_IFS */
#define _EMU_IFS_MASK                        0x00000001UL                  /* Mask for EMU_IFS */

#define EMU_IFS_BURDY                        (0x1UL << 0)                  /* Set Backup functionality ready Interrupt Flag */
#define _EMU_IFS_BURDY_SHIFT                 0                             /* Shift value for EMU_BURDY */
#define _EMU_IFS_BURDY_MASK                  0x1UL                         /* Bit mask for EMU_BURDY */
#define _EMU_IFS_BURDY_DEFAULT               0x00000000UL                  /* Mode DEFAULT for EMU_IFS */
#define EMU_IFS_BURDY_DEFAULT                (_EMU_IFS_BURDY_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_IFS */

/* Bit fields for EMU IFC */

#define _EMU_IFC_RESETVALUE                  0x00000000UL                  /* Default value for EMU_IFC */
#define _EMU_IFC_MASK                        0x00000001UL                  /* Mask for EMU_IFC */

#define EMU_IFC_BURDY                        (0x1UL << 0)                  /* Clear Backup functionality ready Interrupt Flag */
#define _EMU_IFC_BURDY_SHIFT                 0                             /* Shift value for EMU_BURDY */
#define _EMU_IFC_BURDY_MASK                  0x1UL                         /* Bit mask for EMU_BURDY */
#define _EMU_IFC_BURDY_DEFAULT               0x00000000UL                  /* Mode DEFAULT for EMU_IFC */
#define EMU_IFC_BURDY_DEFAULT                (_EMU_IFC_BURDY_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_IFC */

/* Bit fields for EMU IEN */

#define _EMU_IEN_RESETVALUE                  0x00000000UL                  /* Default value for EMU_IEN */
#define _EMU_IEN_MASK                        0x00000001UL                  /* Mask for EMU_IEN */

#define EMU_IEN_BURDY                        (0x1UL << 0)                  /* Backup functionality ready Interrupt Enable */
#define _EMU_IEN_BURDY_SHIFT                 0                             /* Shift value for EMU_BURDY */
#define _EMU_IEN_BURDY_MASK                  0x1UL                         /* Bit mask for EMU_BURDY */
#define _EMU_IEN_BURDY_DEFAULT               0x00000000UL                  /* Mode DEFAULT for EMU_IEN */
#define EMU_IEN_BURDY_DEFAULT                (_EMU_IEN_BURDY_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_IEN */

/* Bit fields for EMU BUBODBUVINCAL */

#define _EMU_BUBODBUVINCAL_RESETVALUE        0x0000000BUL                            /* Default value for EMU_BUBODBUVINCAL */
#define _EMU_BUBODBUVINCAL_MASK              0x0000001FUL                            /* Mask for EMU_BUBODBUVINCAL */

#define _EMU_BUBODBUVINCAL_THRES_SHIFT       0                                       /* Shift value for EMU_THRES */
#define _EMU_BUBODBUVINCAL_THRES_MASK        0x7UL                                   /* Bit mask for EMU_THRES */
#define _EMU_BUBODBUVINCAL_THRES_DEFAULT     0x00000003UL                            /* Mode DEFAULT for EMU_BUBODBUVINCAL */
#define EMU_BUBODBUVINCAL_THRES_DEFAULT      (_EMU_BUBODBUVINCAL_THRES_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_BUBODBUVINCAL */
#define _EMU_BUBODBUVINCAL_RANGE_SHIFT       3                                       /* Shift value for EMU_RANGE */
#define _EMU_BUBODBUVINCAL_RANGE_MASK        0x18UL                                  /* Bit mask for EMU_RANGE */
#define _EMU_BUBODBUVINCAL_RANGE_DEFAULT     0x00000001UL                            /* Mode DEFAULT for EMU_BUBODBUVINCAL */
#define EMU_BUBODBUVINCAL_RANGE_DEFAULT      (_EMU_BUBODBUVINCAL_RANGE_DEFAULT << 3) /* Shifted mode DEFAULT for EMU_BUBODBUVINCAL */

/* Bit fields for EMU BUBODUNREGCAL */

#define _EMU_BUBODUNREGCAL_RESETVALUE        0x0000000BUL                            /* Default value for EMU_BUBODUNREGCAL */
#define _EMU_BUBODUNREGCAL_MASK              0x0000001FUL                            /* Mask for EMU_BUBODUNREGCAL */

#define _EMU_BUBODUNREGCAL_THRES_SHIFT       0                                       /* Shift value for EMU_THRES */
#define _EMU_BUBODUNREGCAL_THRES_MASK        0x7UL                                   /* Bit mask for EMU_THRES */
#define _EMU_BUBODUNREGCAL_THRES_DEFAULT     0x00000003UL                            /* Mode DEFAULT for EMU_BUBODUNREGCAL */
#define EMU_BUBODUNREGCAL_THRES_DEFAULT      (_EMU_BUBODUNREGCAL_THRES_DEFAULT << 0) /* Shifted mode DEFAULT for EMU_BUBODUNREGCAL */
#define _EMU_BUBODUNREGCAL_RANGE_SHIFT       3                                       /* Shift value for EMU_RANGE */
#define _EMU_BUBODUNREGCAL_RANGE_MASK        0x18UL                                  /* Bit mask for EMU_RANGE */
#define _EMU_BUBODUNREGCAL_RANGE_DEFAULT     0x00000001UL                            /* Mode DEFAULT for EMU_BUBODUNREGCAL */
#define EMU_BUBODUNREGCAL_RANGE_DEFAULT      (_EMU_BUBODUNREGCAL_RANGE_DEFAULT << 3) /* Shifted mode DEFAULT for EMU_BUBODUNREGCAL */

#endif /* __ARCH_ARM_SRC_EFM32_HARDWARE_EFM32_EMU_H */
