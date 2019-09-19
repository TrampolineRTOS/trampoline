/**
 * @file tpl_startup.S
 *
 * @section desc File description
 *
 * Startup code called just after reset of cpu. This code then jumb to the
 * tpl_continue_reset_handler
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c)
 * CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
*
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 */


/**
 * @internal
 *
 * tpl_reset_handler
 *
 * tpl_reset_handler is the first function called after a cpu reset.
 * This function must be referenced at the index 1 of the vector table.
 *
 */

 #define OS_START_SEC_CODE
 #include "tpl_as_memmap.h"

	.section .init, "ax", @progbits
	.global tpl_reset_handler
	.type tpl_reset_handler, %function

tpl_reset_handler:

	/* watchdog support */
/* #if WITH_DISABLE_WDT */
	mov     #0x5a80, &__WDTCTL 
/* #else 
	mov.b	&__WDTCTL, r5
	bis	#0x5a08, r5
	mov	r5, &__wdt_clear_value  
#endif */

	/* disable interrupts at startup
	 * they will be enabled when the first task wil start (including idle task)
	*/
	dint

	/* init stack */
	mov     #_estack-2, r1

	call    #tpl_continue_reset_handler
#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"
