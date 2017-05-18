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

#define EXCEPTION_STACK_SIZE 96
#define F_CPU 25000000

extern void trampolineSystemCounter();
extern void switch_context();

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

/*
 * As kernel mode is non-interruptible, these function does nothing
 */
FUNC(void, OS_CODE) tpl_get_task_lock (void)
{
}

FUNC(void, OS_CODE) tpl_release_task_lock (void)
{
}

/**
 * Enable interrupts
 */
void tpl_enable_interrupts(void)
{
    int_enable();
}

/**
 * Disable interrupts
 */
void tpl_disable_interrupts(void)
{
    int_disable();
}

/**
 * Enable interrupts
 */
void tpl_enable_os_interrupts(void)
{
    int_enable();
}

/**
 * Disable interrupts
 */
void tpl_disable_os_interrupts(void)
{
    int_disable();
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

  /* wake up core */
  ESP = 0x1;
  
  /* stack pointer */
  core_context->sp = ((uint32)the_proc->stack.stack_zone) +
      the_proc->stack.stack_size;
  int sp;
  uint32 *p;
  for (sp = 0; sp < EXCEPTION_STACK_SIZE + 8; sp += 4) {
      p = (uint32*) (core_context->sp);
      *p = 0;
      core_context->sp -= 4;
  }
  
  /* address of the instruction to execute when returning
     from the system call. */
  core_context->mepc = (uint32) the_proc->entry;
}

void tpl_init_machine()
{
    // Activates interruptions and timers
    tpl_enable_interrupts();
    tpl_enable_os_interrupts();
    tpl_enable_counters();

    // Schedules
    tpl_schedule_from_running();
    
    // Sets timer limit in order to get tick frequency of 1kHz
    int tickFrequency = 1000;
    TOCRA = F_CPU / tickFrequency;
    start_timer();

    // Enable interrupts and events
    IER   |= 0xF0FFFFF0;
    EER   |= 0x0000000F;
}

void tpl_shutdown ()
{
    stop_timer();
    tpl_disable_interrupts();
    tpl_disable_os_interrupts();
    exit(0);
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file tpl_machine_riscv_generic.c */
