/**
 * @file config.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_app_define.h"

#if WITH_AUTOSAR == YES
	#include "Os.h"
#else
	#include "tpl_os.h"
#endif

#if ALARM_COUNT > 0
	#include "tpl_os_timeobj_kernel.h"
#endif

#include "embUnit.h"
#include "config.h"

#include <signal.h>
#include <unistd.h>
#include <assert.h>

/*
 * @def tpl_send_it1
 *
 * This function send signal SIGTERM to himself (so Trampoline).
 *
 */
void tpl_send_it1(void){
	int ipid;
	ipid = getpid();
	kill(ipid,SIGTERM);
}

/*
 * @def tpl_send_it2
 *
 * This function send signal SIGUSR2 to himself (so Trampoline).
 *
 */
void tpl_send_it2(void){
	int ipid;
	ipid = getpid();
	kill(ipid,SIGUSR2);
}

/*
 * @def tpl_send_it3
 *
 * This function send signal SIGPIPE to himself (so Trampoline).
 *
 */
void tpl_send_it3(void){
	int ipid;
	ipid = getpid();
	kill(ipid,SIGPIPE);
}

/*
 * @def pending_signals
 *
 * This function prints the pending signals. Useful to debug to check if an interrupts has occured or not.
 *
 
void pending_signals(void)
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
*/
#if ALARM_COUNT > 0

extern CONSTP2VAR(tpl_time_obj, AUTOMATIC, OS_APPL_DATA)
tpl_alarm_table[ALARM_COUNT];

/*
 * @def WaitActivationPeriodicAlarm
 *
 * This function wait for alarm periodic alarm expiration
 *
 * @param Alarm Alarm id
 *
 */
void WaitActivationPeriodicAlarm(AlarmType Alarm){
	
	uint32 temp, result_inst_;
	TickType result_inst_tt;
	result_inst_tt = 0;		
	do{
		temp = result_inst_tt;
		result_inst_ = GetAlarm(Alarm,&result_inst_tt);
		/* for debug stdimpl_print("periodic alarm : ticks = %u (temp = %u)\n",result_inst_tt,temp); */
	}while( (temp >= result_inst_tt) || (temp==(0)) );
		
}

/*
 * @def WaitActivationOneShotAlarm
 *
 * This function wait for alarm one shot alarm expiration
 *
 * @param Alarm Alarm id
 *
 */
void WaitActivationOneShotAlarm(AlarmType Alarm){

	int result_inst_;
	TickType result_inst_tt;
	
	do{
		GetAlarm(Alarm,&result_inst_tt);
		/* for debug stdimpl_print("one shot alarm : ticks = %lu\n",result_inst_tt); */
	}while((SetRelAlarm(Alarm, tpl_alarm_table[Alarm]->stat_part->counter->max_allowed_value , 0) == E_OS_STATE));
	
	result_inst_ = CancelAlarm(Alarm); /* Cancel the previous alarm usefull only for the test */
	TEST_ASSERT_EQUAL_INT(E_OK, result_inst_);
	
}

#endif /* ALARM_COUNT > 0 */

#if (COUNTER_COUNT > 0) && (WITH_AUTOSAR == YES)

extern CONSTP2VAR(tpl_counter, OS_VAR, OS_APPL_DATA)
tpl_counter_table[COUNTER_COUNT];

/*
 * @def WaitCounterDeltaValue
 *
 * This function use tpl_counter_table, which is part of memory protection.
 * This function should be executed with trusted funtion
 *
 * @param Counter Counter id
 * @param delta_value Delta value to wait to the counter #Counter
 *
 */
void WaitCounterDeltaValue(CounterType Counter, TickType delta_value){
	
	StatusType status_was;
	TickType value_was, value_exp;
	
	/* if delta_value > OSMAXALLOWEDVALUE */	
	#if defined(__unix__) || defined(__APPLE__)
		assert(delta_value <= tpl_counter_table[Counter]->max_allowed_value);
	#endif
	
	/* find the expected value (value_exp) from the actual value (value_was) and delta value (delta_value) */
	GetCounterValue(Counter, &value_was);
	value_exp = value_was + delta_value;
	
	/* if value_exp is higher than OSMAXALLOXEDVALUE, do value_exp - OSMAXALLOWEDVALUE */
	if(value_exp > tpl_counter_table[Counter]->max_allowed_value){
		value_exp -= (tpl_counter_table[Counter]->max_allowed_value + 1);
	}
	
	do{
		status_was = GetCounterValue(Counter, &value_was);
	}while(value_was != value_exp);
}

#endif /* COUNTER_COUNT > 0 && WITH_AUTOSAR == YES */

/* End of file config.c */
