/**
 * @file cm4_irq.c
 *
 * @section descr File description
 *
 * STM32F4 platform specific routines and variables
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright DG for function and data structures documentation and THUMB2 port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"
#include "bcm2836.h"
#include "emblib.h"
#include "rpi2_timer.h"

/******************************************************************************
 * Exception handlers.
 ******************************************************************************/

/******************************************************************************
 * IRQ acknowledge functions.
 ******************************************************************************/
FUNC(void, OS_CODE) ARM_TIMER_ClearFlag(void);
