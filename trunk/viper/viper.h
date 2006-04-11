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
#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <sys/types.h>

#define DATA_FILE_PATH  "/tmp/viper.data.%d"
#define R_SEM_FILE_PATH "/tmp/viper.rsem.%d"
#define W_SEM_FILE_PATH "/tmp/viper.wsem.%d"

#define HELLO   0
#define TIMER   1
#define PWROF   2

#define ONE_SHOT	0
#define AUTO		1

struct VP_TIMER_PARAM {
	int			type;   /*  ONE_SHOT or AUTO					*/
	useconds_t  delay;  /*  delay of the timer in microseconds  */
	int			sig;	/*  signal to send						*/
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

#endif
