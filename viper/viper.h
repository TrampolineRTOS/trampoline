/*
 *  viper.h
 *  viper
 *
 *  Created by Jean-Luc Bechennec on Tue May 03 2005.
 *  Copyright (c) 2005 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __VIPER_H__
#define __VIPER_H__

/* define required by Linux. */
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 600
#endif
#include <unistd.h>
#include <sys/types.h>

#define DATA_FILE_PATH  "/viper.data.%d"
#define CTRL_FILE_PATH  "/viper.ctrl.%d"
#define STAT_FILE_PATH  "/viper.stat.%d"
#define R_SEM_FILE_PATH "/viper.rsem.%d"
#define W_SEM_FILE_PATH "/viper.wsem.%d"
#define SYNCHRO_SEM_FILE_PATH "/viper.wsem.%d"

#define HELLO   0
#define TIMER   1
#define PWROF   2

#define ONE_SHOT	0
#define AUTO		1

struct VP_TIMER_PARAM {
	int            type;  /*  ONE_SHOT or AUTO					*/
	unsigned long  delay; /*  delay of the timer in microseconds  */
	int            sig;   /*  signal to send						*/
};

struct VP_EVENT_PARAM {
    char file_name[256];    /*  File where the events are stored    */
    int  sig;               /*  Signal to send                      */
};

typedef struct VP_TIMER_PARAM vp_timer_param;
typedef struct VP_EVENT_PARAM vp_event_param;

struct VP_COMMAND
{
	int command;	/* command to execute by viper  */
	union {
		vp_event_param  event;
		vp_timer_param  timer;
	}   params;
};

typedef struct VP_COMMAND vp_command;

#define MOTOR_CSG_STOP 0
#define MOTOR_CSG_LEFT 1
#define MOTOR_CSG_RGHT 2

struct VP_CTRL
{
    int motor_csg[2];
};

typedef struct VP_CTRL vp_ctrl;

struct VP_STAT
{
    int motor_pos[2];
};

typedef struct VP_STAT vp_stat;


#endif
