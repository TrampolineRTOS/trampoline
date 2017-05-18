#ifndef TPL_MACHINE_H
#define TPL_MACHINE_H

#include "tpl_machine_riscv.h"

typedef struct RISCV_CONTEXT *tpl_context;

extern struct RISCV_CONTEXT idle_task_context;

/**
 * @def SIZE_OF_IDLE_TASK
 *
 * The size of the stack of the idle task which is also the stack
 * used for machine startup
 */
#define IDLE_STACK_SIZE  300

/*
 * Configuration of systick timer (can be a generic timer if systick is not available
 * on the target) for alarms and schedule tables.
 */
FUNC(void, OS_CODE) tpl_set_systick_timer();

#endif /* TPL_MACHINE_H */

/* End of file tpl_machine.h */