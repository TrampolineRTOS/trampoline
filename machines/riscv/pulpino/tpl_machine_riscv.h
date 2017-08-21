#ifndef TPL_MACHINE_RISCV_GENERIC_H
#define TPL_MACHINE_RISCV_GENERIC_H

#include "tpl_os_std_types.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"

/**
 * RISCV core registers
 */
struct RISCV_CONTEXT {
    uint32 sp;
    uint32 mepc;
    uint32 mestatus;
    uint32 ra;
    uint32 pile[31];
};

/**
 * RISCV generic platform context
 */
typedef struct RISCV_CONTEXT riscv_context;

/**
 * default size of an element in a stack
 */
typedef uint32 tpl_stack_word;

/**
 * type of a stack size
 */
typedef uint32 tpl_stack_size;

/**
 * Stack definition
 */
struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size  stack_size;
};

/**
 * Stack definition
 */
typedef struct TPL_STACK tpl_stack;

extern VAR (riscv_context, OS_VAR) idle_task_context;

/**
 * Defines the context block of the task "idle"
 */
#define IDLE_CONTEXT &idle_task_context

#define SIZE_OF_IDLE_STACK 200

extern VAR(tpl_stack_word, OS_VAR) idle_stack[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];

/**
 * Defines the stack (void) of the task "idle"
 */
#define IDLE_STACK {idle_stack,SIZE_OF_IDLE_STACK}

/**
 * Defines the entry point of the idle task
 */
#define IDLE_ENTRY tpl_sleep

/**
 * Software interruption handlers
 * TODO: GOIL !
 */
extern FUNC(void, OS_CODE) SOFT_IRQ0_Handler();
extern FUNC(void, OS_CODE) SOFT_IRQ1_Handler();
extern FUNC(void, OS_CODE) SOFT_IRQ2_Handler();

/**
 * Kernel reentrance counter
 */
extern uint32 tpl_reentrancy_counter;

/**
 * Interruption masks to each priority level
 */
CONST(uint32, AUTOMATIC) tpl_priority_interruption_masks[32];


/**
 * Get interruption line from each ISR2 ID
 */
uint32 tpl_vector_from_isr2_id(uint32 id);

/**
 * Stack of kernel priority levels
 */
#define IT_MASKS_STACK_LENGTH 32
uint32 stack_interruption_masks[IT_MASKS_STACK_LENGTH];
void push_interruption_mask(void);
uint32 pop_interruption_mask(void);

uint32 nextISP;

/**
 * Vectors of each interruption
 * TODO: GOIL !
 */
extern uint8 SOFT_IRQ0;
extern uint8 SOFT_IRQ1;
extern uint8 SOFT_IRQ2;
extern uint8 TA_CMP;

#endif /* TPL_MACHINE_RISCV_GENERIC_H */

/* End of file tpl_machine_riscv_generic.h */
