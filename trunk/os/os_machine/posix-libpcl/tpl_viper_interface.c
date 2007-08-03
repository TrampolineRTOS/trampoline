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
#include "viper.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <semaphore.h>

/*
 * Data used to communicate with viper
 */
char data_file_path[32];
char r_sem_file_path[32];
char w_sem_file_path[32];

static sem_t *r_com_sem = NULL;
static sem_t *w_com_sem = NULL;
static int sh_mem = -1; /*  Shared memory id  */
static vp_command *command = NULL;
static pid_t viper_pid = -1;

#define VIPER_PATH "VIPER_PATH"


void viper_kill(void)
{
  if( viper_pid != - 1 )
  {
    fprintf(stderr, "kill viper\n");
    if( kill(viper_pid, SIGHUP) != 0 )
      perror("error viper: ");
  }
}


/*
 * tpl_viper_init create the shared objects to communicate with Viper
 * and launch the viper process
 */
void tpl_viper_init(void)
{
    int  viper_path_ok = 0;
    char *viper_args[] = { NULL, NULL };
    char *viper_env[] = { NULL };
    
    /*  Check the VIPER_PATH environment variable is defined    */
    char *viper_path = getenv(VIPER_PATH);
    
    if (viper_path != NULL)
    {
        if (access(viper_path, X_OK) == 0)
        {
            viper_path_ok = 1;
        }
        else
        {
            printf("VIPER_PATH is defined but viper is not accessible or executable\n");
        }
    }
    else
    {        
        viper_path = "viper/viper";
        if( access( viper_path, X_OK ) != 0 )
        {
            fprintf(stderr,"Error: VIPER_PATH is not defined. Exiting\n");
            exit(1);
        }
        else
        {
            viper_path_ok = 1;
        }
    }
    
    if (viper_path_ok == 1) {
        /*  set up the first and only arg of viper to the path of viper */
        viper_args[0] = viper_path;
        
        /*
         * Init the shared objects (shared memory and semaphores) used to 
         * communicate with Viper
         */
         
        /*  build up the paths for the shared objects    */
        sprintf(data_file_path, DATA_FILE_PATH, getpid());
        sprintf(r_sem_file_path, R_SEM_FILE_PATH, getpid());
        sprintf(w_sem_file_path, W_SEM_FILE_PATH, getpid());
        
        /*  create the shared memory object */
        sh_mem = shm_open(data_file_path, (O_CREAT | O_RDWR ), 0600);
        if (sh_mem < 0) {
            perror("viper: fail to create the shared memory object");
            exit(-1);
        }
        ftruncate(sh_mem,sizeof(vp_command));

        /*  map it  */
        command = mmap(0, sizeof(vp_command), ( PROT_WRITE | PROT_READ ), MAP_SHARED, sh_mem, 0);
        if (command == (void *)-1) {
            perror("viper: unable to map the shared memory object");
            exit(-1);
        }

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

        /*
         * Fork the viper process
         */
        if ((viper_pid = fork()) == 0) {
            /*  Launch viper    */
            if (execve(viper_path, viper_args, viper_env) < 0) {
                printf("%s\n",viper_path);
                perror("viper: unable to launch viper");
                exit(1);
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

void tpl_viper_start_one_shot_timer(int sig, useconds_t delay)
{
    vp_command command_to_send;
    
    command_to_send.command = TIMER;
    command_to_send.params.timer.type = ONE_SHOT;
    command_to_send.params.timer.delay = delay;
    command_to_send.params.timer.sig = sig;
    
    send_viper_command(&command_to_send);
}

void tpl_viper_start_auto_timer(int sig, useconds_t delay)
{
    vp_command command_to_send;
    
    command_to_send.command = TIMER;
    command_to_send.params.timer.type = AUTO;
    command_to_send.params.timer.delay = delay;
    command_to_send.params.timer.sig = sig;
    
    send_viper_command(&command_to_send);
}

