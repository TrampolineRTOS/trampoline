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
#include "tpl_kern_stack.h"

#include "msp430.h"

extern FUNC(void, OS_CODE) CallTerminateTask(void);
extern FUNC(void, OS_CODE) CallTerminateISR2(void);
extern FUNC(void, OS_CODE) tpl_init_it_priority();

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_init_context(
  CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
#if WITH_PAINT_REGISTERS == YES || WITH_PAINT_STACK == YES
	VAR(int, AUTOMATIC) i;
#endif

	//pointer to the static descriptor of the process
	CONSTP2CONST(tpl_proc_static, AUTOMATIC, OS_APPL_DATA) the_proc =
		tpl_stat_proc_table[proc_id];

	//pointer to the context of the process
	CONSTP2VAR(msp430x_small_context, AUTOMATIC, OS_APPL_DATA) l_tpl_context =
		the_proc->context;

	//pointer to the stack of the process
	CONSTP2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA) stack =
		the_proc->stack.stack_zone;

	//size of the stack in 16 bit words above the frame
	CONST(uint16, AUTOMATIC) size_of_stack_above_frame =
		(the_proc->stack.stack_size - MSP430X_SMALL_FRAME_SIZE) >> 1;

	//pointer to the exception frame
	CONSTP2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA) frame =
		(tpl_stack_word*)(stack + size_of_stack_above_frame);

#if WITH_PAINT_REGISTERS == YES
	for(i = 0; i < GPR_ON_SMALL_FRAME; i++)
	{
		frame[i] = OS_REG_PATTERN;
	}
#endif

	l_tpl_context->stackPointer = (uint16)frame;

#if WITH_PAINT_STACK == YES
	for(i = 0; i < size_of_stack_above_frame; i++)
	{
		stack[i] = OS_STACK_PATTERN;
	}
#endif

#if TASK_COUNT > 0
	#if   ISR_COUNT > 0
		frame[CALL_SMALL_IDX] = (IS_ROUTINE == the_proc->type) ?
			(uint16)(CallTerminateISR2) :
			(uint16)(CallTerminateTask) ;
	#else
		frame[CALL_SMALL_IDX] = (uint16)(CallTerminateTask);
	#endif
#else
	#if ISR_COUNT > 0
		frame[CALL_SMALL_IDX] = (uint16)(CallTerminateISR2);
	#else
		frame[CALL_SMALL_IDX] = NULL;
	#endif
#endif
	/* status register. Set the GIE bit (Global interrupt) */
	frame[SR_SMALL_IDX] = 0x8;
	/* init the return address to the entry point of the task/ISR2 */
	frame[PC_SMALL_IDX] = (uint16)(the_proc->entry);

#if WITH_AUTOSAR_STACK_MONITORING == YES && WITH_PAINT_STACK == NO
	stack[0] = OS_STACK_PATTERN;
#endif
}

FUNC (void, OS_CODE) tpl_init_machine_generic (void)
{
	#if WITH_MEMORY_PROTECTION == YES
		tpl_init_mpu();	//TODO: mpu not implemented yet
	#endif
}

FUNC(void, OS_CODE) tpl_init_machine_specific (void)
{
	tpl_set_systick_timer(); //TODO a remettre.
	//tpl_init_external_interrupts();
	//tpl_init_it_priority();
}

FUNC(void, OS_CODE) tpl_set_systick_timer()
{
	/* Set up timer TA3 with ACLK. ACLK is set to LFXTCLK at start: 32.768 kHz */
	TA3CCR0 = 0;          /* lock the timer                                    */
	TA3CTL = TASSEL__ACLK /* ACLK                                              */
		| ID__1             /* divide by 1                                       */
		| MC__UP;           /* Up count                                          */
	TA3CCTL0 |= CCIE;     /* enable the compare interrupt                      */
	TA3CCR0 = 32;         /* start with a 1.007 ms period (33/32768)           */
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/*
 * The kernel stack
 */
#define OS_START_SEC_VAR_NOINIT_16BIT
#include "tpl_memmap.h"
CONSTP2VAR(tpl_stack_word, AUTOMATIC, OS_APPL_DATA)
  tpl_kern_stack[TPL_KERNEL_STACK_SIZE];
#define OS_STOP_SEC_VAR_NOINIT_16BIT
#include "tpl_memmap.h"

/*
 * The reentrancy flag is used to distinguish between a service call`
 * from the application and from a hook.
 * If 0, it ia a call from the application
 * if 1, it is a call from a hook
 */
#define OS_START_SEC_VAR_8BIT
#include "tpl_memmap.h"
volatile uint8 tpl_reentrancy_flag = 0;
#define OS_STOP_SEC_VAR_8BIT
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/* TODO Will not work, the GIE bit has to be changed in the saved SR */
void tpl_disable_interrupts()
{
  __disable_interrupt(); /* msp430 intrinsics.h */
}
void tpl_enable_interrupts()
{
  __enable_interrupt();  /* msp430 intrinsics.h */
}
void tpl_disable_os_interrupts()
{
  tpl_disable_interrupts();
}
void tpl_enable_os_interrupts()
{
  tpl_enable_interrupts();
}

void idle_function(void)
{
  while (1) {
#if IDLE_POWER_MODE != ACTIVE_POWER_MODE
    IDLE_LPM;
#endif
  }
}

void tpl_init_machine()
{
  tpl_init_machine_generic();
  tpl_init_machine_specific();
}

void tpl_shutdown()
{
  LPM4;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
