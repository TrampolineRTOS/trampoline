#ifndef TPL_MACHINE_CORTEX_H
#define TPL_MACHINE_CORTEX_H

#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"

#define TPL_KERN_OFFSET_S_RUNNING     0
#define TPL_KERN_OFFSET_S_ELECTED     4
#define TPL_KERN_OFFSET_RUNNING       8
#define TPL_KERN_OFFSET_ELECTED       12
#define TPL_KERN_OFFSET_RUNNING_ID    16
#define TPL_KERN_OFFSET_ELECTED_ID    20
#define TPL_KERN_OFFSET_NEED_SWITCH   24
#define TPL_KERN_OFFSET_NEED_SCHEDULE 25

//we save 14 registers: from top
// Each register uses 32 bits (20 bits in hardware), but SR and SP are merged.
// -----------------------------------------
// | 27  @ of CallTerminate(ISR/Task)      |
// | 26  @ of CallTerminate(ISR/Task)	    |
// | 25  PC (high)                         | 
// | 24  PC (low) & SR                     | 
// | 23  REG_RETARG (ABI dependent) - high | 
// | 22  REG_RETARG (ABI dependent) - low  | 
// | 21  ARG (ABIdependent) - high         | 
// | 20  ARG (ABIdependent) - low          | 
// | 19  ARG (ABIdependent) - high         | 
// | 18  ARG (ABIdependent) - low          | 
// | 17  ARG (ABIdependent) - high         | 
// | 16  ARG (ABIdependent) - low          | 
// | 15  R11 - high                        | 
// | 14  R11 - low                         | 
// | 13  R10 - high                        | 
// | 12  R10 - low                         | 
// | 11  R9  - high                        | 
// | 10  R9  - low                         | 
// |  9  R8  - high                        | 
// |  8  R8  - low                         | 
// |  7  R7  - high                        | 
// |  6  R7  - low                         | 
// |  5  R6  - high                        | 
// |  4  R6  - low                         | 
// |  3  R5  - high                        | 
// |  2  R5  - low                         | 
// |  1  R4  - high                        | 
// |  0  R4  - low                         | 
#define MSP430X_CORE_EXCEPTION_FRAME_SIZE ((uint16)56)

#define SR_IDX    24
#define PC_IDX    25
#define CALL_IDX_LOW  26 		//call to terminateTask/ISR2.
#define CALL_IDX_HIGH  27 		//call to terminateTask/ISR2.

#define GPR_ON_EXCEPTION_FRAME  (12<<1) //we reserve 32bits/GPR

/*
 * The reentrancy flag is used to distinguish between a service call`
 * from the application and from a hook.
 * If 0, it ia a call from the application
 * if 1, it is a call from a hook
 */
extern volatile uint8 tpl_reentrancy_flag;

typedef struct MSP430X_CONTEXT
{
	uint32 stackPointer;  /* General purpose register r4 */
} msp430x_core_context;

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

#define OS_STACK_PATTERN ((uint16)0xbeef)	//16bit mcu
#define OS_REG_PATTERN   ((uint16)0xabcd)	//16bit mcu

#endif
