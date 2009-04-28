/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "tpl_os_alarm_kernel.h" /*for INVALID_ALARM*/
#include "tpl_os_generated_configuration.h"

DeclareAlarm(Alarm1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	
	StatusType result_inst_2, result_inst_4, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15, result_inst_16, result_inst_17;
	AlarmBaseType result_inst_1, result_inst_5;
	TickType result_inst_3;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_2 = GetAlarmBase(INVALID_ALARM, &result_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OS_ID, result_inst_2);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_4 = GetAlarm(INVALID_ALARM, &result_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OS_ID, result_inst_4);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_6 = GetAlarmBase(Alarm1, &result_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(3,OSMAXALLOWEDVALUE_Counter1, (int)(result_inst_5.maxallowedvalue));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(3,OSTICKSPERBASE_Counter1, (int)(result_inst_5.ticksperbase));
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(3,OSMINCYCLE_Counter1, (int)(result_inst_5.mincycle));	
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_7 = SetRelAlarm(INVALID_ALARM, 0, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_ID, result_inst_7);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_8 = SetRelAlarm(Alarm1, -1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OS_VALUE, result_inst_8);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_9 = SetRelAlarm(Alarm1, result_inst_5.maxallowedvalue + 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_VALUE, result_inst_9);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_10 = SetRelAlarm(Alarm1, 0, result_inst_5.mincycle - 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OS_VALUE, result_inst_10);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_11 = SetRelAlarm(Alarm1, 0,  result_inst_5.maxallowedvalue + 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_VALUE, result_inst_11);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_12 = SetAbsAlarm(INVALID_ALARM, 0, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OS_ID, result_inst_12);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_13 = SetAbsAlarm(Alarm1, -1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OS_VALUE, result_inst_13);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_14 = SetAbsAlarm(Alarm1, result_inst_5.maxallowedvalue + 1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OS_VALUE, result_inst_14);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_15 = SetAbsAlarm(Alarm1, 0, result_inst_5.mincycle - 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OS_VALUE, result_inst_15);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_16 = SetAbsAlarm(Alarm1, 0,  result_inst_5.maxallowedvalue + 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_VALUE, result_inst_16);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_17 = CancelAlarm(INVALID_ALARM);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OS_ID, result_inst_17);
	
}

/*create the test suite with all the test cases*/
TestRef AlarmsTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AlarmsTest,"AlarmsTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AlarmsTest;
}
