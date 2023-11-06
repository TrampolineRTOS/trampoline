/**
 * @file tpl_machine_m2sxxx.c
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 *  Trampoline is copyright (c) IRCCyN 2005-2009
 *  Autosar extension is copyright (c) IRCCyN and ESEO 2007-2009
 *  Trampoline and its Autosar extension are protected by the
 *  French intellectual property law.
 *
 *  This software is distributed under a dual licencing scheme
 *  1 - The Lesser GNU Public Licence v2 (LGPLv2)
 *  2 - The BSD Licence
 *
 * @section infos File informations
 *
 */

#include <stdint.h>
#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "system_m2sxxx.h"
#include "m2sxxx.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(void, OS_CODE) tpl_set_systick_timer()
{
	if (SysTick_Config(SystemCoreClock / 1000))
	{
		while(1);
	}
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
