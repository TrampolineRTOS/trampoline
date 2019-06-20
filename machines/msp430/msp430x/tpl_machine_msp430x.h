#ifndef TPL_MACHINE_MSP430X_H
#define TPL_MACHINE_MSP430X_H

#include "tpl_os_std_types.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_machine.h"
//#include "tpl_os_kernel_stack.h"

/*
 * Definition of kernel access defines
 * Specific to the target
 */

#define TPL_KERN_OFFSET_S_RUNNING       (0)
#define TPL_KERN_OFFSET_S_ELECTED       (4)
#define TPL_KERN_OFFSET_RUNNING         (8)
#define TPL_KERN_OFFSET_ELECTED         (12)
#define TPL_KERN_OFFSET_RUNNING_ID      (16)
#define TPL_KERN_OFFSET_ELECTED_ID      (20)
#define TPL_KERN_OFFSET_NEED_SWITCH     (24)
#define TPL_KERN_OFFSET_NEED_SCHEDULE   (25)

#define MSP430X_CORE_EXCEPTION_FRAME_SIZE 32

#define MSP430X_INITIAL_EXC_RETURN ((uint32)0xFFFB)

typedef struct MSP430X_CONTEXT
{
    uint32 gpr5;
    uint32 gpr6;
    uint32 gpr7;
    uint32 gpr8;
    uint32 gpr9;
    uint32 gpr10;
    uint32 gpr11;

    uint32 stackPointer;
} msp430x_context;

typedef uint32 tpl_stack_word;

typedef uint32 tpl_stack_size;

typedef struct TPL_STACK {
    tpl_stack_word *stack_zone;
    tpl_stack_size stack_size;
} tpl_stack;


#define IDLE_ENTRY tpl_sleep

FUNC (void, OS_CODE) tpl_init_machine_specific (void);

#endif