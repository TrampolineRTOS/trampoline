#ifndef TPL_MACHINE_CORTEX_H
#define TPL_MACHINE_CORTEX_H

#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"
#include "tpl_kern_stack.h"

#define TPL_KERN_OFFSET_S_RUNNING     0
#define TPL_KERN_OFFSET_S_ELECTED     2
#define TPL_KERN_OFFSET_RUNNING       4
#define TPL_KERN_OFFSET_ELECTED       6
#define TPL_KERN_OFFSET_RUNNING_ID    8
#define TPL_KERN_OFFSET_ELECTED_ID    12
#define TPL_KERN_OFFSET_NEED_SWITCH   16
#define TPL_KERN_OFFSET_NEED_SCHEDULE 17

/*
 * 14 registers are saved (SP is saved in the context and
 * R3 is the constant generator, so it is not saved).
 *
 * In the small memory model, each register takes 16 bits except PC which
 * has its 4 higher bits merged in the SR. However these 4 higher bits are
 * 0000 because everything is located in the first 64kB.
 *
 *    +-------------------+
 *  0 |         r4        | + 00 <- PSP
 *    +-------------------+
 *  1 |         r5        | + 02
 *    +-------------------+
 *  2 |         r6        | + 04
 *    +-------------------+
 *  3 |         r7        | + 06
 *    +-------------------+
 *  4 |         r8        | + 08
 *    +-------------------+
 *  5 |         r9        | + 10
 *    +-------------------+
 *  6 |        r10        | + 12
 *    +-------------------+
 *  7 |        r11        | + 14
 *    +-------------------+
 *  8 |        r12        | + 16
 *    +-------------------+
 *  9 |        r13        | + 18
 *    +-------------------+
 * 10 |        r14        | + 20
 *    +-------------------+
 * 11 |        r15        | + 22
 *    +----+--------------+
 * 12 | PC |      SR      | + 24
 *    +----+--------------+
 * 13 |         PC        | + 26
 *    +-------------------+
 * 14 | CallTerminateXXX  | + 28
 *    +-------------------+
 *
 * The full stack frame is 30 bytes
 *
 * At some point during the system call handler and in an interrupt handler
 * the stacked frame is smaller because a context switch is not yet planned.
 * it is as follow:
 *
 *    +-------------------+
 *  0 |        r11        | + 00 <- PSP
 *    +-------------------+
 *  1 |        r12        | + 02
 *    +-------------------+
 *  2 |        r13        | + 04
 *    +-------------------+
 *  3 |        r14        | + 06
 *    +-------------------+
 *  4 |        r15        | + 08
 *    +----+--------------+
 *  5 | PC |      SR      | + 10
 *    +----+--------------+
 *  6 |         PC        | + 12
 *    +-------------------+
 *  7 | CallTerminateXXX  | + 14
 *    +-------------------+
 */
#define MSP430X_SMALL_FRAME_SIZE ((uint16)30)

#define SR_SMALL_IDX    12
#define PC_SMALL_IDX    13
#define CALL_SMALL_IDX  14 /* call to terminateTask/ISR2 */

#define GPR_ON_SMALL_FRAME  12 /* from r4 to r15 */

/*
 * The reentrancy flag is used to distinguish between a service call`
 * from the application and from a hook.
 * If 0, it ia a call from the application
 * if 1, it is a call from a hook
 */
extern volatile uint8 tpl_reentrancy_flag;

/*
 * The context of the MSP430x small memory model. It contains only the sp
 * on 16 bits
 */
typedef struct MSP430X_SMALL_CONTEXT
{
	uint16 stackPointer;  /* General purpose register r4 */
} msp430x_small_context;

/*
 * Datatypes to store something on the stack and to store the size of
 * the stack (in bytes).
 */
typedef uint16 tpl_stack_word;
typedef uint16 tpl_stack_size;

/*
 * structure used in the static descriptor of a task/ISR2
 * 1 - pointer to the stack
 * 2 - size of the stack (in bytes)
 */
typedef struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size  stack_size;
} tpl_stack;

#define OS_STACK_PATTERN ((uint16)0xbeef)	/* 16bit mcu */
#define OS_REG_PATTERN   ((uint16)0xdead)	/* 16bit mcu */

#endif
