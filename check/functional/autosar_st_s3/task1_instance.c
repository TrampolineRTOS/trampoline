/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareCounter(Software_Counter);
DeclareCounter(Software_Counter_bis);
DeclareScheduleTable(sched1);
DeclareScheduleTable(sched2);
DeclareTask(t3);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15;
	TickType TickType_inst_1, TickType_inst_2;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1, ScheduleTableStatusType_inst_2, ScheduleTableStatusType_inst_3, ScheduleTableStatusType_inst_4;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = ActivateTask(t3);
	SCHEDULING_CHECK_AND_EQUAL_INT(2, E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = StartScheduleTableRel(sched1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OK, result_inst_2);

	SCHEDULING_CHECK_INIT(4);
	result_inst_3 = IncrementCounter(Software_Counter);
	/*start schedule table (because StartScheduleTabelRel(x, 1))*/
	/*offset = 0+offset_sched -> t3 and t5*/
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_4 = IncrementCounter(Software_Counter);
	/*offset = 1+offset_sched -> t3 and t4*/
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_4);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_5 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(12, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_1); /*should be RUNNING*/
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_5);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_6 = IncrementCounter(Software_Counter);
	/*offset = 2+offset_sched*/
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OK, result_inst_6);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_7 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(14, SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_2); /*should be RUNNING*/
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_7);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_8 = IncrementCounter(Software_Counter);
	/*offset = 3+offset_sched*/
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK, result_inst_8);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_9 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(16, SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OK, result_inst_9);
	
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_10 = StartScheduleTableRel(sched2, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK, result_inst_10);
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_11 = IncrementCounter(Software_Counter);
	/*start schedule table (because StartScheduleTabelRel(x, 1))*/
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OK, result_inst_11);
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_12 = GetCounterValue(Software_Counter_bis, &TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(19, 0 , TickType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OK, result_inst_12);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_13 = IncrementCounter(Software_Counter);
	/*offset = 1+offset_sched -> t2 and t3*/
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OK, result_inst_13);
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_14 = GetCounterValue(Software_Counter_bis, &TickType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(24, 1 , TickType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_OK, result_inst_14);
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_15 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(25, SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(25,E_OK, result_inst_15);
	
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence3",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}
