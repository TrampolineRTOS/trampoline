/*
 * @file tpl_os_kernel_stack.h
 *
 * @section desc File description
 *
 * Trampoline kernel stack structure for PowerPC port
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

#ifndef TPL_OS_KERNEL_STACK_H
#define TPL_OS_KERNEL_STACK_H

      /*  The kernel stack is like that:
        
            |                                 |
            +---------------------------------+
    SP->    |          linkage area           |  The linkage area is a zone
            +---------------------------------+  reserved for the callee when
         +4 |          linkage area           |  calling a C function
            +---------------------------------+
         +8 |        LR of the caller         |
            +---------------------------------+
        +12 |        SP of the caller         |
            +---------------------------------+
        +16 |        CR of the caller         |
            +---------------------------------+
        +20 |               r11               |
            +---------------------------------+
        +24 |               r12               |
            +---------------------------------+
        +28 | return code of the service (r3) |
            +---------------------------------+
        +32 |       calling task/ISR id       |
            +---------------------------------+
        +36 |     tpl_stat_proc_table ptr     |
            +---------------------------------+
        +40 |       tpl_need_switch ptr       |
            +---------------------------------+
        */

#define KERNEL_STACK_SIZE 80
#define KS_FOOTPRINT      44

#define KS_LR             8
#define KS_SP             12
#define KS_CR             16
#define KS_R11            20
#define KS_R12            24
#define KS_RETURN_CODE    28
#define KS_RUNNING_ID     32
#define KS_SPT_PTR        36
#define KS_NSW_PTR        40

/* TPL_OS_KERNEL_STACK_H */
#endif 
