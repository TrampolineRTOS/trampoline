/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline viper interface stuff
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_viper_interface.h"
#include "tpl_viper.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>

#include "tpl_app_define.h"

/*
 * Data used to communicate with viper (running in the main thread)
 */
static char r_sem_file_path[32];
static char w_sem_file_path[32];
static char synchro_sem_file_path[32];

static sem_t *r_com_sem = NULL;
static sem_t *w_com_sem = NULL;
static sem_t *synchro_sem = NULL;
static vp_command *command = NULL;

static vp_ctrl *ctrl = NULL;
static vp_stat *status = NULL;

/*
 * tpl_viper_init create the shared objects to communicate with Viper
 * and launch the viper process
 */
void tpl_viper_init(void)
{
  /*
   * Init the shared objects (semaphores) used to 
   * communicate with Viper
   */
   
  /*  build up the paths for the shared objects    */
  sprintf(r_sem_file_path, R_SEM_FILE_PATH, getpid());
  sprintf(w_sem_file_path, W_SEM_FILE_PATH, getpid());
  sprintf(synchro_sem_file_path, SYNCHRO_SEM_FILE_PATH, getpid());
  
  ctrl->motor_csg[0] = 0;
  ctrl->motor_csg[1] = 0;

  /*  create the reader semaphore */
  r_com_sem = sem_open(r_sem_file_path, O_CREAT, 0600, 0);
      if (r_com_sem == (void *)SEM_FAILED) {
      perror("viper: unable to create the reader semaphore");
  }

  /*  create the writer semaphore */
  w_com_sem = sem_open(w_sem_file_path, O_CREAT, 0600, 0);
      if (w_com_sem == (void *)SEM_FAILED) {
      perror("viper: unable to create the reading semaphore");
  }

  /*  create the synchro semaphore */
  synchro_sem = sem_open(synchro_sem_file_path, O_CREAT, 0600, 0);
      if (synchro_sem == (void *)SEM_FAILED) {
      perror("viper: unable to create the synchro semaphore");
  }

	else if (1 != viper_pid)
	{
		/* trampoline process waits for viper process */
		if(0 != sem_wait(synchro_sem))
 		{
    			fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    			perror("tpl : sem_wait(viper)");
  		}	

	}

    }
    else
    {
        exit(1);
    }
}

void send_viper_command(vp_command *i_com)
{
  memcpy(command, i_com, sizeof(vp_command));
  if (sem_post(r_com_sem) < 0) {
    perror("viper_test: fail while posting reader semaphore");
  }
  if (sem_wait(w_com_sem) < 0) {
    perror("viper_test: fail while waiting writer semaphore");
  }
}

void tpl_viper_start_one_shot_timer(int sig, unsigned long delay)
{
    vp_command command_to_send;
    
    command_to_send.command = TIMER;
    command_to_send.params.timer.type = ONE_SHOT;
    command_to_send.params.timer.delay = delay;
    command_to_send.params.timer.sig = sig;
    
    send_viper_command(&command_to_send);
}

void tpl_viper_start_auto_timer(int sig, unsigned long delay)
{
    vp_command command_to_send;
    
    command_to_send.command = TIMER;
    command_to_send.params.timer.type = AUTO;
    command_to_send.params.timer.delay = delay;
    command_to_send.params.timer.sig = sig;
    
    send_viper_command(&command_to_send);
}

int tpl_viper_get_motor_pos(int motor)
{
    if (motor >= 0 && motor < 2) {
        return status->motor_pos[motor];
    }
    else {
        return 0;
    }
}

void tpl_viper_set_motor_csg(int motor, int csg)
{
    if (motor >= 0 && motor < 2) {
        ctrl->motor_csg[motor] = csg;
    }
}
