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
#include <tpl_os.h>

#include "tpl_os_generated_configuration.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <pcl.h>
#include <assert.h>
#include <sched.h>
#include <pcl.h>

tpl_context idle_task_context = 0;

#ifndef ISR_COUNT

#define ISR_COUNT 0
int signal_for_id[1];

#else

/*
 * table which stores the signals used for interrupt
 * handlers
 */
int signal_for_id[ISR_COUNT];

#endif



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
    while (1) 
      sched_yield();
}


extern void viper_kill(void);

void tpl_shutdown(void)
{
	/* remove ITs */
	if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_shutdown failed");
        exit(-1);
    }
    
  viper_kill();
    /* sleep forever */
  exit(0);
}

volatile int x = 0;
int cnt = 0;
/*
 * tpl_get_task_lock is used to lock a critical section 
 * around the task management in the os.
 */
void tpl_get_task_lock(void)
{
  x++;
    /*
     * block the handling of signals
     */
	/*  fprintf(stderr, "%d-lock\n", cnt++);*/
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_get_lock failed");
        exit(-1);
    }
    
  assert( 0 <= x && x <= 1);
}

/*
 * tpl_release_task_lock is used to unlock a critical section
 * around the task management in the os.
 */
void tpl_release_task_lock(void)
{
	/*  fprintf(stderr, "%d-unlock\n", cnt++);*/
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_release_lock failed");
        exit(-1);
    }
    
  x--;
    
  assert(0 <= x && x <= 1);
}



void tpl_switch_context(
    tpl_context *old_context,
    tpl_context *new_context)
{
  assert( *new_context != co_current() );
  tpl_release_task_lock();  
  if( *new_context == &idle_task_context )
  {
    /* idle_task activation */
    co_call( idle_task_context );
  }
  else
    co_call( *new_context );
    
  tpl_get_task_lock(); 
}


void tpl_switch_context_from_it(
    tpl_context *old_context,
    tpl_context *new_context)
{
  assert( *new_context != co_current() );
  if( *new_context == &idle_task_context )
  {
    /* idle_task activation */
    co_call( idle_task_context );
  }
  else
    co_call( *new_context );

}

#define CO_MIN_SIZE (8*(4 * 1024))

void tpl_osek_func_stub( void* data )
{
  void (*func)() = (void(*)())data;
  
  /* Avoid signal blocking due to a previous call to tpl_init_context in a OS_ISR2 context. */
  if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
      perror("tpl_osek_func_stub failed");
      exit(-1);
  }  
  
  (*func)();
  
  fprintf(stderr, "[OSEK/VDX Spec. 2.2.3 Sec. 4.7] Ending the task without a call to TerminateTask or ChainTask is strictly forbidden and causes undefined behaviour.\n");
  exit(1);
}


static coroutine_t previous_old_co = NULL;

void tpl_init_context(tpl_exec_common *exec_obj)
{
  coroutine_t old_co;
  coroutine_t* co = &(exec_obj->static_desc->context);
  tpl_stack* stack = &(exec_obj->static_desc->stack);

  /* This is the entry func passed as data */
  void* data = (void*) exec_obj->static_desc->entry; 
  int stacksize = stack->stack_size;
  void* stackaddr = stack->stack_zone;  
  
  old_co = *co;
  
  assert( stacksize > 0 );
  assert( stackaddr != NULL );
  assert( data != NULL );
  

  if( stacksize < CO_MIN_SIZE )
  {
     /* co_create will fail if stacksize is < 4096 */
    stacksize = stacksize < CO_MIN_SIZE ? CO_MIN_SIZE : stacksize ;
  }
  
  stackaddr = NULL; /* co_create automatically allocate stack data using malloc. */  
    
  *co = co_create(tpl_osek_func_stub, data, stackaddr, stacksize);
  
  assert( *co != NULL );
  assert( *co != old_co );
  
  /* If old_co != NULL, we should garbage it soon. */
  if( old_co != NULL )
  {
    if( previous_old_co != NULL )
      co_delete( previous_old_co );
    previous_old_co = old_co;
  }
  
}

/* extern tpl_counter counter_descriptor_of_cnt2, counter_descriptor_of_cnt1;
extern void tpl_counter_tick(tpl_counter *counter);

void timer_handler0(int n)
{
/*  assert( n == SIGRTMIN+10 ); */
/*
  tpl_counter_tick(&counter_descriptor_of_cnt1);
}
*/

void quit(int n)
{
  ShutdownOS(E_OK);  
}

/*
 * tpl_init_machine init the virtual processor hosted in
 * a Unix process
 */
void tpl_init_machine(void)
{
  int id;
  struct sigaction sa;

  /*printf("start viper.\n");*/
  /*lx86_init_viper(); */
  
  /*signal(SIGINT, quit);
  signal(SIGHUP, quit); */

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
    sa.sa_flags = SA_RESTART;
    /*
     * Install the signal handler used to emulate interruptions
     */
    for (id = 0; id < ISR_COUNT; id++) {
        sigaction(signal_for_id[id],&sa,NULL);
/*        assert( signal_for_id[id] != SIGRTMIN+10 );*/ /* Avoid SIGRTMIN+10 signal reuse from user App */
    }
    
    /*
     * Install the signal handler used to emulate system timer
     */
/*    sigaddset(&signal_set, SIGRTMIN+10);
     
    sa.sa_handler = timer_handler0;
    sa.sa_mask = signal_set;
    sa.sa_flags = SA_RESTART;
      
    sigaction( SIGRTMIN+10, &sa, 0 );*/


  idle_task_context = co_create( tpl_osek_func_stub, (void*)tpl_sleep, NULL, CO_MIN_SIZE );
  assert( idle_task_context != NULL );
    
    /*
     * block the handling of signals
     */
    if (sigprocmask(SIG_BLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }
    
     /*   lx86_start_one_shot_timer(SIGUSR1,100000); */

    /* Emulate a 10ms timer tick */
/*    lx86_start_auto_timer( SIGRTMIN+10, 8000 ); */
    
    /*
     * unblock the handling of signals
     *//*
    if (sigprocmask(SIG_UNBLOCK,&signal_set,NULL) == -1) {
        perror("tpl_init_machine failed");
        exit(-1);
    }*/
    
}


