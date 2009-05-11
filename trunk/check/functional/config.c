/**
 * @file config.c
 *
 * @section desc File description
 *
 * 
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date:$
 * $Rev:$
 * $Author: fp $
 * $URL:$
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
	sigset_t  sig_set;
	
	int pi = getpid ();
	stdimpl_print("The pid is %d - ",pi);
	
	sigpending(&sig_set);
	
	stdimpl_print("Pending signals are %d ",(int)sig_set);
	
	if (sigismember ( &sig_set,SIGTERM) ) 
		stdimpl_print("SIGTERM is pending \n");
	
	if (sigismember ( &sig_set,SIGUSR2) ) 
		stdimpl_print("SIGUSR2 is pending \n");
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
