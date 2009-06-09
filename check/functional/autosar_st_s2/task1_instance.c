/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareCounter(Software_Counter);
DeclareScheduleTable(INVALID_SCHEDULETABLE);
DeclareScheduleTable(sched1);
DeclareScheduleTable(sched2);
DeclareScheduleTable(sched3);
DeclareScheduleTable(sched4);
DeclareScheduleTable(sched5);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14;
	StatusType result_inst_15, result_inst_16, result_inst_17, result_inst_18, result_inst_19, result_inst_20, result_inst_21, result_inst_22, result_inst_23, result_inst_24, result_inst_25, result_inst_26, result_inst_27;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1, ScheduleTableStatusType_inst_2, ScheduleTableStatusType_inst_3, ScheduleTableStatusType_inst_4, ScheduleTableStatusType_inst_5, ScheduleTableStatusType_inst_6, ScheduleTableStatusType_inst_7;
	ScheduleTableStatusType ScheduleTableStatusType_inst_8, ScheduleTableStatusType_inst_9, ScheduleTableStatusType_inst_10, ScheduleTableStatusType_inst_11, ScheduleTableStatusType_inst_12, ScheduleTableStatusType_inst_13, ScheduleTableStatusType_inst_14;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = StartScheduleTableRel(sched1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(2,SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = NextScheduleTable(INVALID_SCHEDULETABLE, sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OS_ID, result_inst_3);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_4 = NextScheduleTable(sched1, INVALID_SCHEDULETABLE);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_ID, result_inst_4);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_5 = NextScheduleTable(sched1, sched4);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OS_ID, result_inst_5);
	
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_6 = NextScheduleTable(sched2, sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_NOFUNC, result_inst_6);
	
	SCHEDULING_CHECK_INIT(7);
	result_inst_7 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(7,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_2);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OK, result_inst_7);
		
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_8 = NextScheduleTable(sched1, sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OK, result_inst_8);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_9 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(9,SCHEDULETABLE_NEXT , ScheduleTableStatusType_inst_3);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_10 = NextScheduleTable(sched2, sched3);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OS_NOFUNC, result_inst_10);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_11 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(11,SCHEDULETABLE_NEXT , ScheduleTableStatusType_inst_4);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OK, result_inst_11);
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_12 = GetScheduleTableStatus(sched3, &ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(12,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_5);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OK, result_inst_12);
	
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_13 = NextScheduleTable(sched1, sched2);
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_STATE, result_inst_13);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_14 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_6);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(14,SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_6);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_14);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_15 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_7);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(15,SCHEDULETABLE_NEXT , ScheduleTableStatusType_inst_7);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK, result_inst_15);
	
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_16 = NextScheduleTable(sched1, sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OS_STATE, result_inst_16);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_17 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(17,SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_8);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK, result_inst_17);
	
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_18 = NextScheduleTable(sched1, sched3);
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OK, result_inst_18);
	
	SCHEDULING_CHECK_INIT(19);
	result_inst_19 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_9);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(19,SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_9);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OK, result_inst_19);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_20 = GetScheduleTableStatus(sched2, &ScheduleTableStatusType_inst_10);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(20,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_10);
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_20);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_21 = GetScheduleTableStatus(sched3, &ScheduleTableStatusType_inst_11);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(21,SCHEDULETABLE_NEXT , ScheduleTableStatusType_inst_11);
	SCHEDULING_CHECK_AND_EQUAL_INT(21,E_OK, result_inst_21);
	

	SCHEDULING_CHECK_INIT(22);
	result_inst_22 = StartScheduleTableRel(sched3, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OS_STATE, result_inst_22);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_23 = StartScheduleTableAbs(sched3, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(23,E_OS_STATE, result_inst_23);
	
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_24 = StopScheduleTable(sched1);
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_OK, result_inst_24);
	
	SCHEDULING_CHECK_INIT(25);
	result_inst_25 = GetScheduleTableStatus(sched1, &ScheduleTableStatusType_inst_12);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(25,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_12);
	SCHEDULING_CHECK_AND_EQUAL_INT(25,E_OK, result_inst_25);
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_26 = GetScheduleTableStatus(sched3, &ScheduleTableStatusType_inst_13);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(26,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_13);
	SCHEDULING_CHECK_AND_EQUAL_INT(26,E_OK, result_inst_26);
	
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_27 = GetScheduleTableStatus(INVALID_SCHEDULETABLE, &ScheduleTableStatusType_inst_14);
	SCHEDULING_CHECK_AND_EQUAL_INT(27,E_OS_ID, result_inst_27);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}
