#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_application_def.h"
#include "tpl_os_definitions.h"
#include "tpl_os.h"
#include "tpl_os_timeobj_kernel.h"
#if WITH_AUTOSAR == YES
#include "tpl_as_definitions.h"
#endif
#include "tpl_os_interrupt.h"
#include <pulpino.h>
#include <utils.h>
#include <int.h>
#include <timer.h>
#include <uart.h>

#define F_CPU 25000000

extern void trampolineSystemCounter();
extern void switch_context();

uint32 tpl_reentrancy_counter = 0;
uint32 tpl_mestatus = 0x1;
uint8 stack_position = 0;
uint8 TA_CMP = 28;

#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/**
 * Stack for the idle task
 */
VAR(tpl_stack_word, OS_VAR) idle_stack[SIZE_OF_IDLE_STACK/sizeof(tpl_stack_word)];

/**
 * Context for the idle task
 */
VAR (riscv_context, OS_VAR) idle_task_context;

/**
 * Kernel entry counter
 */
volatile VAR (uint32, OS_VAR) nested_kernel_entrance_counter;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"

#define API_START_SEC_CODE
#include "tpl_memmap.h"

#if TASK_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateTask(void);
#endif

#if ISR_COUNT > 0
extern FUNC(void, OS_CODE) CallTerminateISR2(void);
#endif

#define API_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * tpl_sleep is used by the idle task
 */
void idle_function(void)
{
    while (1) {
        sleep();
    }
}

/**
 * Call Terminate Task function when no TerminateTask hasn't been called
 * or when TerminateTask didn't success because of resource hold or
 * interrupts disabled.
 *
 */
extern FUNC(void, OS_CODE) CallTerminateTask(void);


/**
 * Call Terminate ISR2 function when TerminateISR didn't success doing it
 * because of resource hold or interrupts disabled.
 *
 */
extern FUNC(void, OS_CODE) CallTerminateISR2(void);

FUNC(void, OS_CODE) tpl_get_task_lock (void)
{
    tpl_disable_interrupts();
}

FUNC(void, OS_CODE) tpl_release_task_lock (void)
{
    tpl_enable_interrupts();
}

/**
 * Enable interrupts
 */
void tpl_enable_interrupts(void)
{
  // Programates the activation of interruptions
  tpl_mestatus = 1;
}

/**
 * Disable interrupts
 */
void tpl_disable_interrupts(void)
{
    // Programates the deactivation of interruptions
    tpl_mestatus = 0;
}

/**
 * Enable interrupts
 */
void tpl_enable_os_interrupts(void)
{
  tpl_enable_interrupts();
}

/**
 * Disable interrupts
 */
void tpl_disable_os_interrupts(void)
{
  tpl_disable_interrupts();
}

/*
 * tpl_init_context initialize a context to prepare a task to run.
 * It sets up the stack and the entry point
 */
FUNC(void, OS_CODE) tpl_init_context(
    CONST(tpl_proc_id, OS_APPL_DATA) proc_id)
{
  struct RISCV_CONTEXT *core_context;
  const tpl_proc_static *the_proc;

  the_proc = tpl_stat_proc_table[proc_id];
  core_context = the_proc->context;

  /* stack pointer */
  core_context->sp = ((uint32)the_proc->stack.stack_zone) +
      the_proc->stack.stack_size - 32;

  /* Dealing with initial return address */
  core_context->ra = (IS_ROUTINE == the_proc->type) ?
    (uint32)(CallTerminateISR2) :
    (uint32)(CallTerminateTask) ;

  /* address of the instruction to execute when returning
     from the system call. */
  core_context->mepc = (uint32) the_proc->entry;

  /* interrupts enabled */
  core_context->mestatus = 0x1;

  /* Core not sleeping */
  SCR = 0x0;
}

void tpl_init_machine()
{
    // Activates interruptions and timers
    int_enable();

    // Initialize next pending interruptions
    nextISP = 0;

    // Sets timer limit in order to get tick frequency of 1kHz
#if ALARM_COUNT > 0
    int tickFrequency = 1000;
    TOCRA = F_CPU / tickFrequency;
    start_timer();
#endif

    int i;
    for (int i = 0; i < 32; ++i) {
        stack_interruption_masks[i] = tpl_priority_interruption_masks[0];
    }

    // Enable interrupts and events
    IER =  tpl_priority_interruption_masks[0];
    EER |= 0x0000000F;
}

void tpl_shutdown ()
{
    stop_timer();
    tpl_disable_interrupts();
    tpl_disable_os_interrupts();
    uart_wait_tx_done();
    exit(0);
}

// Software Interruptions
__attribute__ ((weak))
FUNC(void, OS_CODE) SOFT_IRQ0_Handler (P2CONST(void, OS_APPL_DATA, AUTOMATIC) a){ for(;;); }
__attribute__ ((weak))
FUNC(void, OS_CODE) SOFT_IRQ1_Handler (P2CONST(void, OS_APPL_DATA, AUTOMATIC) a){ for(;;); }
__attribute__ ((weak))
FUNC(void, OS_CODE) SOFT_IRQ2_Handler (P2CONST(void, OS_APPL_DATA, AUTOMATIC) a){ for(;;); }

FUNC(void, OS_CODE) tpl_ack_irq(void) {
    GET_CURRENT_CORE_ID(core_id);
    GET_TPL_KERN_FOR_CORE_ID(core_id, kern);

    ICP = 2 << tpl_vector_from_isr2_id(TPL_KERN_REF(kern).running_id);
    IER = pop_interruption_mask();

    /* Interruptions are reenabled at the end of an ISR2 */
    tpl_enable_interrupts();
}

void push_interruption_mask(void) {
    stack_interruption_masks[stack_position] = IER;
    stack_position = (stack_position + 1) % IT_MASKS_STACK_LENGTH;
}

uint32 pop_interruption_mask(void) {
    stack_position = (stack_position - 1) % IT_MASKS_STACK_LENGTH;
    uint32 mask = stack_interruption_masks[stack_position];
    return mask;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_machine_riscv_generic.c */
