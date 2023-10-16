/**
 *
 * @file tpl_posix_irq.c
 *
 * @section descr File description
 *
 * Trampoline machine dependant functions implementation
 * for IRQ handling on posix platform
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) CNRS,
 * University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#include "tpl_app_config.h"
#include "tpl_machine_posix.h"
#include "tpl_os_interrupt_kernel.h"

#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_as_timing_protec.h"
#endif

/*
 * Table to store the signals used to emulate
 * IRQs.
 */
#if ISR_COUNT > 0
extern int signal_for_isr_id[ISR_COUNT];
#endif
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
const int signal_for_watchdog = SIGALRM;
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if ((WITH_AUTOSAR == YES) && (SCHEDTABLE_COUNT > 0)) || (ALARM_COUNT > 0)
const int signal_for_counters = SIGUSR2;
#endif

extern volatile int tpl_locking_depth;
extern char tpl_user_task_lock;
extern char tpl_cpt_os_task_lock;

/*
 * The signal set corresponding to enabled interrupts
 */
sigset_t signal_set;

/**
 * Calls tpl_counter_tick() for each counter declared in the application.
 * tpl_call_counter_tick() implementation is an output of the system generator.
 */
extern void tpl_call_counter_tick(void);

/**
 * Enable all interrupts
 */
void tpl_enable_interrupts(void)
{
  if (-1 == sigprocmask(SIG_UNBLOCK, &signal_set, NULL))
  {
    perror("tpl_enable_interrupt failed");
    exit(-1);
  }
}

/**
 * Enable OS interrupts.
 * Same as tpl_enable_interrupts on posix target
 */
void tpl_enable_os_interrupts(void)
{
  tpl_enable_interrupts();
}

/**
 * Disable all interrupts
 */
void tpl_disable_interrupts(void)
{
  if (-1 == sigprocmask(SIG_BLOCK, &signal_set, NULL))
  {
    perror("tpl_disable_interrupts failed");
    exit(-1);
  }
}

/**
 * Disable OS interrupts.
 * Same as tpl_disable on posix target
 */
void tpl_disable_os_interrupts(void)
{
  tpl_disable_interrupts();
}

/*
 * The signal handler used when interrupts are enabled
 */
void tpl_signal_handler(int sig)
{

#if ISR_COUNT > 0
  unsigned int id;
  unsigned char found;
#endif

  tpl_locking_depth++;
  tpl_cpt_os_task_lock++;

#if ((WITH_AUTOSAR == YES) && (SCHEDTABLE_COUNT > 0)) || (ALARM_COUNT > 0)
  if (signal_for_counters == sig)
  {
    tpl_call_counter_tick();
  }
  else
  {
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
    if (signal_for_watchdog == sig)
    {
      /* This function is defined in autosar/tpl_as_timing_protec.c */
      tpl_watchdog_expiration();
    }
    else
    {
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if ISR_COUNT > 0
      id = 0;
      found = (sig == signal_for_isr_id[id]);
      while ((id < ISR_COUNT) && !found)
      {
        id++;
        if (id < ISR_COUNT)
        {
          found = (sig == signal_for_isr_id[id]);
        }
      } /* while((id < ISR_COUNT) && !found) */

      if (found)
      {
        tpl_central_interrupt_handler(id + TASK_COUNT);
      }
      else
      {
        /* Unknown interrupt request ! */
        printf("No ISR is registered for signal %d\n", sig);
        printf("Cowardly exiting!\n");
        tpl_shutdown();
      }
#endif /* ISR_COUNT > 0 */
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
    }
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if ((WITH_AUTOSAR == YES) && (SCHEDTABLE_COUNT > 0)) || (ALARM_COUNT > 0)
  }
#endif /* (defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */

  tpl_locking_depth--;
  tpl_cpt_os_task_lock--;
}

/* Posix platform internal functions */
void tpl_posix_sigblock(const char *error_message)
{
  if (sigprocmask(SIG_BLOCK, &signal_set, NULL) == -1)
  {
    perror(error_message);
    exit(-1);
  }
}

void tpl_posix_sigunblock(const char *error_message)
{
  if (sigprocmask(SIG_UNBLOCK, &signal_set, NULL) == -1)
  {
    perror(error_message);
    exit(-1);
  }
}

void tpl_posix_siginit(void)
{

  struct sigaction sa;
#if ISR_COUNT > 0
  int id;
#endif

  sigemptyset(&signal_set);

  /*
   * init a signal mask to block all signals (aka interrupts)
   */
#if ISR_COUNT > 0
  for (id = 0; id < ISR_COUNT; id++)
  {
    sigaddset(&signal_set, signal_for_isr_id[id]);
  }
#endif
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
  sigaddset(&signal_set, signal_for_watchdog);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if ((WITH_AUTOSAR == YES) && (SCHEDTABLE_COUNT > 0)) || (ALARM_COUNT > 0)
  sigaddset(&signal_set, signal_for_counters);
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */

  /*
   * init the sa structure to install the handler
   */
  sa.sa_handler = tpl_signal_handler;
  sa.sa_mask = signal_set;
  sa.sa_flags = SA_RESTART;
  /*
   * Install the signal handler used to emulate interruptions
   */
#if ISR_COUNT > 0
  for (id = 0; id < ISR_COUNT; id++)
  {
    sigaction(signal_for_isr_id[id], &sa, NULL);
  }
#endif
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
  sigaction(signal_for_watchdog, &sa, NULL);
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if ((WITH_AUTOSAR == YES) && (SCHEDTABLE_COUNT > 0)) || (ALARM_COUNT > 0)
  sigaction(signal_for_counters, &sa, NULL);
#endif /*(defined WITH_AUTOSAR && !defined NO_SCHEDTABLE) || ... */
}
