/*
 *  timer.c
 *  viper
 *
 *  Created by Jean-Luc Bechennec on Mon May 02 2005.
 *  Copyright (c) 2005 __MyCompanyName__. All rights reserved.
 *
 */

#include "timer.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

extern pid_t osek_app_pid;

void viper_log(const char *);
void *timer_thread(void *);

void *timer_thread(void *args)
{
	int type = ((vp_timer_param *)args)->type;
	useconds_t delay = ((vp_timer_param *)args)->delay;
	int sig = ((vp_timer_param *)args)->sig;
	while(1) {
		if (usleep(delay) != 0) {
            viper_log("Timer failed");
			break;
		}
		kill(osek_app_pid,sig);
/*        viper_log("Sending interrupt"); */
		if (type == ONE_SHOT) {
			break;
		}
	}
	pthread_exit(NULL);
	return NULL;
}

/*
 * vp_create_timer alloc a timer data structure
 * The timer is not started
 */
vp_timer *vp_create_timer(int type, useconds_t delay, int sig)
{
	vp_timer *timer = malloc(sizeof(vp_timer));
	
	if (timer != NULL) {
		/*  alloc was successful, init the tm struct	*/
		timer->tm.type = type;
		timer->tm.delay = delay;
		timer->tm.sig = sig;
	}
	
	return timer;
}

/*
 * vp_start_timer starts the timer
 */
int vp_start_timer(vp_timer *timer)
{
	int result;
	
	result = pthread_create(&(timer->th),NULL,timer_thread,&(timer->tm));
	return result;
}

