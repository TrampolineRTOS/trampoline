/*
 *  config.c
 *  tramp_project
 *
 *  Created by Florent Pavin on 19/01/09.
 *  Copyright 2009 __IRCYYN__. All rights reserved.
 *
 */

#include <signal.h>
#include <unistd.h>

#include "embUnit.h"
#include "tpl_os.h"

#include "config.h"

void tpl_send_it1(void){
	int ipid;
	ipid = getpid();
	kill(ipid,SIGTERM);
}

void tpl_send_it2(void){
	int ipid;
	ipid = getpid();
	kill(ipid,SIGUSR2);
}

void tpl_send_it3(void){
	int ipid;
	ipid = getpid();
	kill(ipid,SIGPIPE);
}

void signaux_pendants(void)
{
	sigset_t  sig_set; /* liste des signaux bloqués */
	
	int pi = getpid ();
	stdimpl_print("The pid is %d - ",pi);
	
	sigpending(&sig_set);
	
	stdimpl_print("Les signaux pendants sont %d ",sig_set);
	
	if (sigismember ( &sig_set,SIGTERM) ) 
		stdimpl_print("SIGUSR2 pendant \n");
	
	if (sigismember ( &sig_set,SIGUSR2) ) 
		stdimpl_print("SIGUSR2 pendant \n");
}

void WaitActivationPeriodicAlarm(AlarmType Alarm){
	
	u32 temp, result_inst_;
	TickType result_inst_tt;
	result_inst_tt = 0;
	do{
		temp = result_inst_tt;
		result_inst_ = GetAlarm(Alarm,&result_inst_tt);
		/* for debug stdimpl_print("periodic alarm : ticks = %u (temp = %u)\n",result_inst_tt,temp); */
	}while( (temp >= result_inst_tt) || (temp==(0)) );
		
}

void WaitActivationOneShotAlarm(AlarmType Alarm){

	int result_inst_;
	TickType result_inst_tt;
	
	do{
		GetAlarm(Alarm,&result_inst_tt);
		/* for debug stdimpl_print("one shot alarm : ticks = %d\n",result_inst_tt);*/
	}while((SetRelAlarm(Alarm, 1, 0) == E_OS_STATE));
	
	result_inst_ = CancelAlarm(Alarm); /* Cancel the previous alarm usefull only for the test */
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_);
	
}
