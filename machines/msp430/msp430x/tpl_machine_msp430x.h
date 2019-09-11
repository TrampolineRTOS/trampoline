#ifndef TPL_MACHINE_CORTEX_H
#define TPL_MACHINE_CORTEX_H

#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_os_internal_types.h"
#include "tpl_os_custom_types.h"

#define TPL_KERN_OFFSET_S_RUNNING     0
#define TPL_KERN_OFFSET_S_ELECTED     2
#define TPL_KERN_OFFSET_RUNNING       4
#define TPL_KERN_OFFSET_ELECTED       6
#define TPL_KERN_OFFSET_RUNNING_ID    8
#define TPL_KERN_OFFSET_ELECTED_ID    12
#define TPL_KERN_OFFSET_NEED_SWITCH   16
#define TPL_KERN_OFFSET_NEED_SCHEDULE 17

//we save 14 registers: from top
// Each register uses 32 bits (20 bits in hardware), but SR and SP are merged.
// --------------------------------------
// |  PC (high)                         | 
// |  PC (low) & SR                     | 
// |  REG_RETARG (ABI dependent) - high | 
// |  REG_RETARG (ABI dependent) - low  | 
// |  ARG (ABIdependent) - high         | 
// |  ARG (ABIdependent) - low          | 
// |  ARG (ABIdependent) - high         | 
// |  ARG (ABIdependent) - low          | 
// |  ARG (ABIdependent) - high         | 
// |  ARG (ABIdependent) - low          | 
// |  R11 - high                        | 
// |  R11 - low                         | 
// |  R10 - high                        | 
// |  R10 - low                         | 
// |  R9  - high                        | 
// |  R9  - low                         | 
// |  R8  - high                        | 
// |  R8  - low                         | 
// |  R7  - high                        | 
// |  R7  - low                         | 
// |  R6  - high                        | 
// |  R6  - low                         | 
// |  R5  - high                        | 
// |  R5  - low                         | 
// |  R4  - high                        | 
// |  R4  - low                         | 
#define MSP430X_CORE_EXCEPTION_FRAME_SIZE ((uint16)52)
#define GPR_ON_EXCEPTION_FRAME  (13<<1) //we reserve 32bits/GPR

extern uint32 tpl_reentrancy_counter;

typedef struct MSP430X_CONTEXT
{
  uint16 stackPointer;  /* General purpose register r4 */
} msp430x_core_context;

typedef uint16 tpl_stack_word;
typedef uint16 tpl_stack_size;

typedef struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size  stack_size;
} tpl_stack;

#define OS_STACK_PATTERN ((uint16)0xBEEF)	//16bit mcu
#define OS_REG_PATTERN ((uint16)0xabcd)	//16bit mcu

#endif
