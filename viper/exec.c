/*
 *  exec.c
 *  viper
 *
 *  Created by Jean-Luc Bechennec on Wed May 04 2005.
 *  Copyright (c) 2005 __MyCompanyName__. All rights reserved.
 *
 */

#include "exec.h"
#include "timer.h"
#include "unistd.h"

void exec_timer(vp_timer_param *);
void exec_shutdown(void);

void exec_timer(vp_timer_param *t_p)
{
	/*  launches the thread of the time */
	vp_timer *timer = vp_create_timer(t_p->type,t_p->delay,t_p->sig);
	vp_start_timer(timer);
}

void exec_shutdown(void)
{
}

void exec_command(vp_command *i_com)
{
	switch (i_com->command) {
		case TIMER: exec_timer(&(i_com->params.timer)); break;
		case PWROF: exec_shutdown(); break;
	}
}
