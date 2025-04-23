/**
 * @section descr File description
 *
 * EFM32WG platform specific routines and variables
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
 */

 #include "tpl_os.h"
 #include "tpl_os_interrupt_kernel.h"
 #include "tpl_compiler.h"

FUNC(void, OS_CODE)NMI_Handler(void){
    while (1);
}

FUNC(void, OS_CODE)HardFault_Handler(void){
    while (1);
}

FUNC(void, OS_CODE)MemManage_Handler(void){
    while (1);
}

FUNC(void, OS_CODE)BusFault_Handler(void){
    while (1);
}

FUNC(void, OS_CODE)UsageFault_Handler(void){
    while (1);
}

FUNC(void, OS_CODE)DebugMonitor_Handler(void){
    while (1);
}
