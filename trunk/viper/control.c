/*
 *  control.c
 *  viper
 *
 *  Created by Jean-Luc BÈchennec on 08/02/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#include "control.h"
#include "viper.h"

#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>

static char ctrl_file_path[32];
static char stat_file_path[32];
static int  ctrl_sh_mem = -1;
static int  stat_sh_mem = -1;

static pthread_t motor_1;
static pthread_t motor_2;
static int motor_1_idx = 0;
static int motor_2_idx = 1;

vp_ctrl *ctrl = NULL;
vp_stat *status = NULL;

pid_t osek_app_pid;

void viper_log(char *);
void *motor_thread(void *);

void init_motors(void)
{
    /*  init the shared memory for motors   */
    viper_log("Initializing the motors");
    
    osek_app_pid = getppid();
    
    /*  build the shared memory path        */
    sprintf(ctrl_file_path, CTRL_FILE_PATH, osek_app_pid);
    sprintf(stat_file_path, STAT_FILE_PATH, osek_app_pid);
    
    /*  create the shared memory objects     */
    ctrl_sh_mem = shm_open(ctrl_file_path, O_RDWR, S_IRUSR | S_IWUSR);
    if (ctrl_sh_mem < 0) {
		perror("viper: fail to open the control shared memory object");
		exit(-1);
	}
    
    stat_sh_mem = shm_open(stat_file_path, O_RDWR, S_IRUSR | S_IWUSR);
    if (stat_sh_mem < 0) {
		perror("viper: fail to open the status shared memory object");
		exit(-1);
	}
    
    /*  map them  */
    ctrl = mmap(0, sizeof(vp_ctrl), (PROT_WRITE|PROT_READ), MAP_SHARED, ctrl_sh_mem, 0);
    if (ctrl == (void *)-1) {
		perror("viper: unable to map the control shared memory object");
		exit(-1);
	}

    status = mmap(0, sizeof(vp_stat), (PROT_WRITE|PROT_READ), MAP_SHARED, stat_sh_mem, 0);
    if (status == (void *)-1) {
		perror("viper: unable to map the status shared memory object");
		exit(-1);
	}
    
    /*  Set the position to 0   */
    status->motor_pos[0] = 0;
    status->motor_pos[1] = 0;
    
    /*  start the motors        */
    pthread_create(&motor_1,NULL,motor_thread,&motor_1_idx);
    pthread_create(&motor_2,NULL,motor_thread,&motor_2_idx);
}

void close_motors(void)
{
	/*  unmap the shared memory segments */
	if (munmap(ctrl,sizeof(ctrl)) < 0) {
		perror("viper: fail to unmap the control shared memory object");
	}

	if (munmap(status,sizeof(status)) < 0) {
		perror("viper: fail to unmap the status shared memory object");
	}
}

void *motor_thread(void *index)
{
    int idx = *((int *)index);
    while(1) {
        int csg = ctrl->motor_csg[idx];
        
        if (idx == 1) {
            csg = (90 + (rand() % 4)) * csg / 100;
        }
        else {
            csg = (97 + (rand() % 7)) * csg / 100 ;
        }
        
        int pos = status->motor_pos[idx];
        pos += csg;
        if (pos > 16383) {
            pos = 16383;
        }
        if (pos < 0) {
            pos = 0;
        }
        status->motor_pos[idx] = pos;
        usleep(50000);
    }
	pthread_exit(NULL);
    return NULL;
}
