#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_application_def.h"
#include "tpl_os_definitions.h"
#include "tpl_os.h"
#if WITH_MEMORY_PROTECTION == YES
#include "tpl_memory_protection.h"
#endif
#if WITH_AUTOSAR == YES
#include "tpl_as_definitions.h"
#endif
#include "tpl_os_interrupt.h"

//include tpl_msp430x_definitions.h generated header
#include "tpl_msp430x_definitions.h"

#define OS_START_SEC_VAR_8BIT
#include "tpl_memmap.h"

tpl_bool tpl_isr2_disabled = FALSE;

#define OS_STOP_SEC_VAR_8BIT
#include "tpl_memmap.h"


#define API_START_SEC_CODE
#include "tpl_memmap.h"

#if TASK_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateTask(void);
#endif
#if ISR_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateISR2();
#endif

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

extern FUNC(void, OS_CODE) tpl_init_external_interrupts();
extern FUNC(void, OS_CODE) tpl_init_it_priority();

FUNC(void, OS_CODE) tpl_init_machine_generic(void) {
#if WITH_MEMORY_PROTECTION == YES
    tpl_init_mp();
#endif
}

FUNC(void, OS_CODE) tpl_init_machine_specific(void) {
    tpl_set_systick_timer();
    tpl_init_external_interrupts();
    tpl_init_it_priority();

    //NVIC_SetPriority(SVCall_IRQn, KERNEL_PRIO_UNSHIFTED);
    //__set_CONTROL(0x3);
    //__ISB();
}

#define GPR_ON_EXCEPTION_FRAME  5
#define LR_IDX                  5
#define PC_IDX                  6
#define xPSR_IDX                7

FUNC(void, OS_CODE) tpl_init_context(CONST(tpl_proc_id, OS_APPL_DATA) proc_id) {
#if WITH_PAINT_REGISTERS == YES || WITH_PAINT_STACK == YES
    VAR(int, AUTOMATIC) i;
#endif

    //the pointer to the static descriptor of the process
    CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) the_proc = tpl_stat_proc_table[proc_id];
    //the pointer to the context of the process
    CONSTP2Var(msp430x_context, AUTOMATIC, OS_APPL_DATA) l_tpl_context = the_proc->context;
    //the pointer to the stack of the process
    CONSTP2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA) stack = the_proc->stack.stack_zone;
    //the size of the stack in 32 bit words above the exception frame
    CONST(uint32, AUTOMATIC) size_of_stack_above_exception_frame = (the_proc->stack.stack_size - MSP430X_CORE_EXCEPTION_FRAME_SIZE);
    //the pointer to th eexception frame
    CONSTP2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA) exception_frame = stack + size_of_stack_above_exception_frame;

#if WITH_PAINT_REGISTERS == YES
    l_tpl_context->gpr4 = 
    l_tpl_context->gpr5 = 
    l_tpl_context->gpr6 = 
    l_tpl_context->gpr7 = 
    l_tpl_context->gpr8 = 
    l_tpl_context->gpr9 = 
    l_tpl_context->gpr10 = 
    l_tpl_context->gpr11 = OS_STACK_PATTERN; 

    for(i = 0; i < GPR_ON_EXCEPTION_FRAME; i++) {
        exception_frame[i] = OS_STACK_PATTERN;
    }
#endif

    l_tpl_context->stackPointer = (uint32)exception_frame;

#if WITH_PAINT_STACK == YES
    for(i = 0; i < size_of_stack_above_exception_frame; i++) {
        stack[i] = OS_STACK_PATTERN;
    }
#endif

#if TASK_COUNT > 0
    #if IS_COUNT > 0
    exception_frame[LR_IDX] = (IS_ROUTINE == the_proc->type) ? (uint32)(CallTerminateISR2) : (uint32)(CallTerminateTask);
    #else
    exception_frame[LR_IDX] = (uint32)(CallTerminateTask);
    #endif
#else
    #if ISR_COUNT > 0
    exception_frame[LR_IDX] = (uint32)(CallTerminateISR2);
    #else
    exception_frame[LR_IDX] = NULL;
    #endif
#endif
    //pc
    exception_frame[PC_IDX] = (uint32)(the_proc->entry);
    //xpsr
    exception_frame[xPSR_IDX] = 0x01000000;

#if WITH_AUTOSAR_STACK_MONITORING == YES && WITH_PAINT_STACK == NO
    (*(uint8 *)(the_proc->stack.stack_zone)) = OS_STACK_PATTERN;
#endif
}

FUNC(uint8, OS_CODE) tpl_check_stack_footprint(CONST(tpl_proc_id, OS_APPL_DATA) proc_id) {
    uint8 tmp;
    /*to do*/
    tmp = 0;
    return tmp;
}

void idle_function(void) {
    while(1);
}

void tpl_init_machine() {
    tpl_init_machine_generic();
    tpl_init_machine_specific();
}

void tpl_shutdown() {
    while(1) {
        __asm__("   wfi ;");
    }
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"