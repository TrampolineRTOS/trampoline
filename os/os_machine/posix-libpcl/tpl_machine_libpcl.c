/*
 * Trampoline OS
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline posix signals and libpcl process machine dependent stuffs
 *
 */

#include "tpl_machine.h"
#include "tpl_os_internal_types.h"
#include "tpl_viper_interface.h"
#include "tpl_os_interrupts.h"

#include "tpl_os_generated_configuration.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pcl.h>
#include <assert.h>


tpl_context idle_task_context;

/*
  TODO: revoir les lock!!
*/


#ifndef ISR_COUNT
#define ISR_COUNT 0
#endif

/*
 * table which stores the signals used for interrupt
 * handlers
 */
extern int signal_for_id[ISR_COUNT];

/*
 * The signal set corresponding to the enabled interrupts
 */
sigset_t    signal_set;

/*
 * The signal handler used when interrupts are enabled
 */
void tpl_signal_handler(int sig)
{
    unsigned int id;

  printf("signal d'IT\n");
    for (id = 0; id < ISR_COUNT; id++) {
        if (signal_for_id[id] == sig) {
            tpl_central_interrupt_handler(id);
            break;
        }
    }
}

/*
 * tpl_sleep is used by the idle task
 */
void tpl_sleep(void)
{
    while (1) sleep(10);
}

void tpl_shutdown(void)
{
	/* remove ITs */
	if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_shutdown failed");
        exit(-1);
    }
    /* sleep forever */
    while (1) sleep(10);
}

/*
 * tpl_get_task_lock is used to lock a critical section 
 * around the task management in the os.
 */
void tpl_get_task_lock(void)
{
    /*
     * block the handling of signals
     */
	printf("lock\n");
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_get_lock failed");
        exit(-1);
    }
}

/*
 * tpl_release_task_lock is used to unlock a critical section
 * around the task management in the os.
 */
void tpl_release_task_lock(void)
{
	printf("unlock\n");
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_release_lock failed");
        exit(-1);
    }
}



void tpl_switch_context(
    tpl_context *old_context,
    tpl_context *new_context)
{
  co_call( *new_context );
}


void tpl_switch_context_from_it(
    tpl_context *old_context,
    tpl_context *new_context)
{
  co_call( *new_context );
}

#define CO_MIN_SIZE (4 * 1024)

void tpl_osek_func_stub( void* data )
{
  tpl_exec_function* func = (tpl_exec_function*) data;
  
  while(1)
  {
    (*func)();
    co_resume();
  }
}

void tpl_init_context(tpl_exec_common *exec_obj)
{
  coroutine_t* co = &(exec_obj->static_desc->context);
  tpl_stack* stack = &(exec_obj->static_desc->stack);
  
  // This is the entry func passed as data
  void* data = (void*) &(exec_obj->static_desc->entry); 
  
  int stacksize = stack->stack_size;
  void* stackaddr = stack->stack_zone;
  
  assert( stacksize > 0 );
  assert( stackaddr != NULL );
  assert( data != NULL );
  

  if( stacksize < CO_MIN_SIZE )
  {
     // co_create will fail if stacksize is < 4096
    stacksize = stacksize < CO_MIN_SIZE ? CO_MIN_SIZE : stacksize ;
    
    stackaddr = NULL; // co_create will allocate stack data using malloc.
  }
  
  *co = co_create(tpl_osek_func_stub, data, stackaddr, stacksize);
  
  assert( co != NULL );
}


/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
  int id;
  struct sigaction sa;
  printf("start viper.\n");
  lx86_init_viper(); 

  sigemptyset(&signal_set);

    /*
     * init a signal mask to block all signals (aka interrupts)
     */
    for (id = 0; id < ISR_COUNT; id++) {
        sigaddset(&signal_set,signal_for_id[id]);
    }

    /*
     * init the sa structure to install the handler
     */
    sa.sa_handler = tpl_signal_handler;
    sa.sa_mask = signal_set;
    sa.sa_flags = 0;
    /*
     * Install the signal handler used to emulate interruptions
     */
    for (id = 0; id < ISR_COUNT; id++) {
        sigaction(signal_for_id[id],&sa,NULL);
    }
    
    /*
     * block the handling of signals
     */
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
    
    // FIXME : remove this
        lx86_start_one_shot_timer(SIGUSR1,1000000);

    /*
     * unblock the handling of signals
     */
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
}


