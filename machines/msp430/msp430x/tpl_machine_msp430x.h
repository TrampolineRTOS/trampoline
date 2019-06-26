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
#define TPL_KERN_OFFSET_ELECTED_ID    10
#define TPL_KERN_OFFSET_NEED_SWITCH   12
#define TPL_KERN_OFFSET_NEED_SCHEDULE 13

#define MSP430X_CORE_EXCEPTION_FRAME_SIZE ((uint16)16)

extern uint32 tpl_reentrancy_counter;

typedef struct MSP430X_CONTEXT
{
  uint16 stackPointer;  /* General purpose register r4 */
  uint16 gpr5;          /* General purpose register r5 */
  uint16 gpr6;          /* General purpose register r6 */
  uint16 gpr7;          /* General purpose register r7 */
  uint16 gpr8;          /* General purpose register r8 */
  uint16 gpr9;          /* General purpose register r9 */
  uint16 gpr10;         /* General purpose register r10 */
  uint16 gpr11; 
} msp430x_core_context;

typedef uint16 tpl_stack_word;
typedef uint16 tpl_stack_size;

typedef struct TPL_STACK {
    tpl_stack_word  *stack_zone;
    tpl_stack_size  stack_size;
} tpl_stack;

#define OS_STACK_PATTERN ((uint32)0xDEADBEEF)

#endif