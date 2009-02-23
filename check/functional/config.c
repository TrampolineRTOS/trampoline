/*
 *  config.c
 *  tramp_project
 *
 *  Created by Florent Pavin on 19/01/09.
 *  Copyright 2009 __IRCYYN__. All rights reserved.
 *
 */


//librariy for kill :
#include <signal.h>
//library for getpid :
#include <unistd.h>

void tpl_send_it1(void){
	int ipid;
	ipid = getpid();
	kill(ipid,SIGUSR1);
}

void tpl_send_it2(void){
	int ipid;
	ipid = getpid();
	kill(ipid,SIGUSR2);
}


#include "embUnit.h"
#include "tpl_os.h"
//Display information in the right way (printf on UNIX...)
#include "config.h"

void WaitActivationPeriodicAlarm(AlarmType Alarm){
	
	u32 temp, result_inst_;
	TickType result_inst_tt;
	result_inst_tt = 0;
	do{
		temp = result_inst_tt;
		result_inst_ = GetAlarm(Alarm,&result_inst_tt);
		//stdimpl_print("periodic alarm : ticks = %u (temp = %u)\n",result_inst_tt,temp);
	}while( (temp >= result_inst_tt) || (temp==(0)) );
		
}

void WaitActivationOneShotAlarm(AlarmType Alarm){

	int result_inst_;
	TickType result_inst_tt;
	
	do{
		GetAlarm(Alarm,&result_inst_tt);
		//stdimpl_print("one shot alarm : ticks = %d\n",result_inst_tt);
	}while((SetRelAlarm(Alarm, 1, 0) == E_OS_STATE));
	
	result_inst_ = CancelAlarm(Alarm); //Cancel the previous alarm usefull only for the test
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_);
	
}

/* It's maybe more usefull if we need just to call a fonction not matter if the alarm is a
 periodic or a one shot alarm.
 
void WaitActivationAlarm(AlarmType Alarm){
	
	AlarmBaseType alarmBase;
	int result_inst_ = GetAlarmBase(Alarm, &alarmBase);
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_);
	
	stdimpl_print("maxallowedvalue : %d\n",alarmBase.maxallowedvalue);
	stdimpl_print("ticksperbase : %d\n",alarmBase.ticksperbase);
	stdimpl_print("mincycle : %d\n",alarmBase.mincycle);
	
	stdimpl_print("maxallowedvalue OS : %d\n",OSMAXALLOWEDVALUE_Counter1);
	stdimpl_print("ticksperbase OS : %d\n",OSTICKSPERBASE_Counter1);
	stdimpl_print("mincycle OS : %d\n",OSMINCYCLE_Counter1);
	
	if(alarmBase.mincycle == 0){
		WaitActivationOneShotAlarm(Alarm);
	}
	else{
		WaitActivationPeriodicAlarm(Alarm);
	}
}*/