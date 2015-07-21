/*
 * @file tpl_os_process_stack.h
 *
 * @section desc File description
 *
 * Trampoline process stack structure for PowerPC port
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Autosar extension is copyright (c) IRCCyN and ESEO 2007
 * libpcl port is copyright (c) Jean-Francois Deverge 2006
 * ARM7 port is copyright (c) ESEO 2007
 * hcs12 port is copyright (c) Geensys 2007
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
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

#ifndef TPL_OS_PROCESS_STACK_H
#define TPL_OS_PROCESS_STACK_H

/*
 * The process stack top is like that:
 *       
 * SP     -> | R4                        |
 *           +---------------------------+
 * SP+4   -> | R5                        |
 *           +---------------------------+
 * SP+8   -> | xPSR                      |
 *           |---------------------------|
 *           | PC                        |
 *           |---------------------------|
 *           | LR return address         |
 *           |---------------------------|
 *           | R12                       |
 *           |---------------------------|
 *           | R3 service number         |
 *           |---------------------------|
 *           | R2                        |
 *           |---------------------------|
 *           | R1                        |
 *           |---------------------------|
 * SP+36  -> | R0                        |
 *           +---------------------------+
 *
 * r0 is saved by the API function or by the interrupt handler
 * cr, lr, r12 and r11 are saved when entering the kernel in tpl_sc_handler
 * or by the interrupt handler
 * SRR0 and SRR1 are optionally saved by the tpl_call_trusted_function
 * service that change the stack pointer.
 * the linkage area is reserved for the call of a trusted function
 */

#define PS_FOOTPRINT              	8
#define PS_TRUSTED_FOOTPRINT_IN   	0
#define PS_TRUSTED_FOOTPRINT_OUT  	0

#define PS_R4                     	0
#define PS_R5                     	4
#define PS_R0                     	36

/* TPL_OS_PROCESS_STACK_H */
#endif 
