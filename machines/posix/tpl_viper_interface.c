/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est prot�g� par la loi sur la propri�t� intellectuelle
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
#include "viper.h"

#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>

#include "tpl_app_define.h"

/*
 * Data used to communicate with viper
 */
static char ctrl_file_path[32];
static char stat_file_path[32];
static char data_file_path[32];
static char r_sem_file_path[32];
static char w_sem_file_path[32];
static char synchro_sem_file_path[32];

static sem_t *r_com_sem = NULL;
static sem_t *w_com_sem = NULL;
static sem_t *synchro_sem = NULL;
static int sh_mem = -1; /*  Shared memory id  */
static vp_command *command = NULL;
static pid_t viper_pid = -1;

static int ctrl_sh_mem = -1;
static int stat_sh_mem = -1;

static vp_ctrl *ctrl = NULL;
static vp_stat *status = NULL;

#define VIPER_PATH "VIPER_PATH"

void viper_kill(void)
{
  if (viper_pid != -1)
  {
    /* fprintf(stderr, "kill viper\n"); */
    if (kill(viper_pid, SIGHUP) != 0)
      perror("error viper: ");
  }
}

/*
 * tpl_viper_init create the shared objects to communicate with Viper
 * and launch the viper process
 */
void tpl_viper_init(void)
{
  int viper_exe_ok = 0;
  char *viper_args[] = {NULL, NULL};
  char *viper_env[] = {NULL};

  /*  Check the VIPER_PATH environment variable is defined    */
  char *viper_path = getenv(VIPER_PATH);
  char viper_exe[256];

  if (viper_path != NULL)
  {
    strncpy(viper_exe, viper_path, 255);
    strcat(viper_exe, "/viper");

    if (access(viper_exe, X_OK) == 0)
    {
      viper_exe_ok = 1;
    }
    else
    {
      printf(
          "VIPER_PATH is defined but viper is not accessible or executable\n");
    }
  }
  else
  {
#ifdef TRAMPOLINE_BASE_PATH
    viper_path = TRAMPOLINE_BASE_PATH "/viper";
#else
    viper_path = "../viper";
#endif
    strncpy(viper_exe, viper_path, 256 - 1 - strlen("/viper"));
    strcat(viper_exe, "/viper");

    if (access(viper_exe, X_OK) != 0)
    {
      fprintf(stderr, "Error: VIPER_PATH is not defined. Exiting\n");
      exit(1);
    }
    else
    {
      viper_exe_ok = 1;
    }
  }

  if (viper_exe_ok == 1)
  {
    /*  set up the first and only arg of viper to the exe of viper */
    viper_args[0] = viper_exe;

    /*
     * Init the shared objects (shared memory and semaphores) used to
     * communicate with Viper
     */

    /*  build up the paths for the shared objects    */
    sprintf(data_file_path, DATA_FILE_PATH, getpid());
    sprintf(r_sem_file_path, R_SEM_FILE_PATH, getpid());
    sprintf(w_sem_file_path, W_SEM_FILE_PATH, getpid());
    sprintf(synchro_sem_file_path, SYNCHRO_SEM_FILE_PATH, getpid());
    sprintf(ctrl_file_path, CTRL_FILE_PATH, getpid());
    sprintf(stat_file_path, STAT_FILE_PATH, getpid());

    /*  create the shared memory objects */
    sh_mem = shm_open(data_file_path, (O_CREAT | O_RDWR), 0600);
    if (sh_mem < 0)
    {
      perror("viper: fail to create the shared memory object");
      exit(-1);
    }
    ftruncate(sh_mem, sizeof(vp_command));

    ctrl_sh_mem = shm_open(ctrl_file_path, (O_CREAT | O_RDWR), 0600);
    if (ctrl_sh_mem < 0)
    {
      perror("viper: fail to open the control shared memory object");
      exit(-1);
    }
    ftruncate(ctrl_sh_mem, sizeof(vp_ctrl));

    stat_sh_mem = shm_open(stat_file_path, (O_CREAT | O_RDWR), 0600);
    if (stat_sh_mem < 0)
    {
      perror("viper: fail to open the status shared memory object");
      exit(-1);
    }
    ftruncate(stat_sh_mem, sizeof(vp_stat));

    /*  map them  */
    command = mmap(0, sizeof(vp_command), (PROT_WRITE | PROT_READ), MAP_SHARED,
                   sh_mem, 0);
    if (command == (void *)-1)
    {
      perror("viper: unable to map the shared memory object");
      exit(-1);
    }

    ctrl = mmap(0, sizeof(vp_ctrl), (PROT_WRITE | PROT_READ), MAP_SHARED,
                ctrl_sh_mem, 0);
    if (ctrl == (void *)-1)
    {
      perror("viper: unable to map the control shared memory object");
      exit(-1);
    }

    status = mmap(0, sizeof(vp_stat), (PROT_WRITE | PROT_READ), MAP_SHARED,
                  stat_sh_mem, 0);
    if (status == (void *)-1)
    {
      perror("viper: unable to map the status shared memory object");
      exit(-1);
    }

    ctrl->motor_csg[0] = 0;
    ctrl->motor_csg[1] = 0;

    /*  create the reader semaphore */
    r_com_sem = sem_open(r_sem_file_path, O_CREAT, 0600, 0);
    if (r_com_sem == (void *)SEM_FAILED)
    {
      perror("viper: unable to create the reader semaphore");
    }

    /*  create the writer semaphore */
    w_com_sem = sem_open(w_sem_file_path, O_CREAT, 0600, 0);
    if (w_com_sem == (void *)SEM_FAILED)
    {
      perror("viper: unable to create the reading semaphore");
    }

    /*  create the synchro semaphore */
    synchro_sem = sem_open(synchro_sem_file_path, O_CREAT, 0600, 0);
    if (synchro_sem == (void *)SEM_FAILED)
    {
      perror("viper: unable to create the synchro semaphore");
    }

    /*
     * Fork the viper process
     */
    if ((viper_pid = fork()) == 0)
    {
      /*  Launch viper    */
      if (execve(viper_exe, viper_args, viper_env) < 0)
      {
        printf("%s\n", viper_exe);
        perror("viper: unable to launch viper");
        exit(1);
      }
      /* We shall never be here */
      perror("viper : why I'm here ?");
      exit(-1);
    }
    else if (1 != viper_pid)
    {
      /* trampoline process waits for viper process */
      if (0 != sem_wait(synchro_sem))
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
  if (sem_post(r_com_sem) < 0)
  {
    perror("viper_test: fail while posting reader semaphore");
  }
  if (sem_wait(w_com_sem) < 0)
  {
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
  if (motor >= 0 && motor < 2)
  {
    return status->motor_pos[motor];
  }
  else
  {
    return 0;
  }
}

void tpl_viper_set_motor_csg(int motor, int csg)
{
  if (motor >= 0 && motor < 2)
  {
    ctrl->motor_csg[motor] = csg;
  }
}
