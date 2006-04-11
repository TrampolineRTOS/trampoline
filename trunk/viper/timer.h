/*
 *  timer.h
 *  viper
 *
 *  Created by Jean-Luc Bechennec on Mon May 02 2005.
 *  Copyright (c) 2005 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __TIMER_H__
#define __TIMER_H__

#include "viper.h"
#include <pthread.h>

struct VP_TIMER {
	vp_timer_param  tm;
	pthread_t		th;
};

typedef struct VP_TIMER vp_timer;


/*
 * vp_create_timer alloc a timer data structure
 * The timer is not started
 */
vp_timer *vp_create_timer(int type, useconds_t delay, int sig);

/*
 * vp_start_timer starts the timer
 */
int vp_start_timer(vp_timer *timer);

#endif
