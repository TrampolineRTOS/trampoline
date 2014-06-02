/*
 *  com.c
 *  viper
 *
 *  Created by Jean-Luc Bechennec on Mon May 02 2005.
 *  Copyright (c) 2005 __MyCompanyName__. All rights reserved.
 *
 */

#include "com.h"

#include <sys/mman.h>
/*semaphores are not in the same directory for Mac and Linux.*/
#ifdef DARWIN
	#include <sys/semaphore.h>
	#include <sys/stat.h>
#elif defined LINUX
	#include <semaphore.h>
#else
	#error "no ARCH defined in Makefile!"
#endif

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

#define DATA 0
#define SEM  1

static char data_file_path[32];
static char r_sem_file_path[32];
static char w_sem_file_path[32];
static char synchro_sem_file_path[32];

static sem_t *r_com_sem = NULL;
static sem_t *w_com_sem = NULL;
static sem_t *synchro_sem = NULL;
static int sh_mem = -1; /*  Shared memory id	*/
vp_command *command = NULL;

pid_t osek_app_pid;

void viper_log(char *);

void init_com(void)
{
    viper_log("Initializing the communication");
    
    osek_app_pid = getppid();
    
    /*  built the shared memory and semaphore paths */
    sprintf(data_file_path, DATA_FILE_PATH, osek_app_pid);
    sprintf(r_sem_file_path, R_SEM_FILE_PATH, osek_app_pid);
    sprintf(w_sem_file_path, W_SEM_FILE_PATH, osek_app_pid);
    sprintf(synchro_sem_file_path, W_SEM_FILE_PATH, osek_app_pid);
    
	/*  create the shared memory object  */
	sh_mem = shm_open(data_file_path, O_RDWR, S_IRUSR | S_IWUSR);
	if (sh_mem < 0) {
		perror("viper: fail to open the shared memory object");
		exit(-1);
	}
	//ftruncate(sh_mem,sizeof(vp_command));

	/*  map it  */
	command = mmap(0, sizeof(vp_command), PROT_READ, MAP_SHARED, sh_mem, 0);
	if (command == (void *)-1) {
		perror("viper: unable to map the shared memory object");
		exit(-1);
	}
	
	/*  create the reader semaphore	*/
	r_com_sem = sem_open(r_sem_file_path, 0);
	if (r_com_sem == (void *)SEM_FAILED) {
		perror("viper: unable to open the reader semaphore");
	}

	/*  create the writer semaphore	*/
	w_com_sem = sem_open(w_sem_file_path, 0);
	if (w_com_sem == (void *)SEM_FAILED) {
		perror("viper: unable to open the reading semaphore");
	}

	/*  create the synchro semaphore */
        synchro_sem = sem_open(synchro_sem_file_path, 0);
        if (synchro_sem == (void *)SEM_FAILED) {
            perror("viper: unable to create the synchro semaphore");
        }

	/* viper process tells trampoline process that is ready */
	if(0 != sem_post(synchro_sem))
	{
		fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
		perror("viper : sem_post(synchro_sem)");
	}

}

void close_com(void)
{
    viper_log("Closing communication");
    
	/*  delete the semaphores	*/
	if (sem_close(r_com_sem) < 0) {
		perror("viper: unable to close the reader semaphore");
	}
		
	if (sem_close(w_com_sem) < 0) {
		perror("viper: unable to close the writer semaphore");
	}
	
	/*  unmap the shared memory segment */
	if (munmap(command,sizeof(vp_command)) < 0) {
		perror("viper: fail to unmap the shared memory object");
	}
	
	/*  delete the shared memory segment	*/
	if (shm_unlink(data_file_path) < 0) {
		perror("viper: fail to close the shared memory object");
	}
}

void read_command(vp_command *o_com)
{
	if (sem_wait(r_com_sem) < 0) {
		perror("viper: fail while waiting reader semaphore");
	}
	memcpy(o_com, command, sizeof(vp_command));
    
    viper_log("Got command");
    
	if (sem_post(w_com_sem) < 0) {
		perror("viper: fail while posting writer semaphore");
	}
}
