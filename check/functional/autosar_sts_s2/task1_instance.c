/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareScheduleTable(sched_explicit);
DeclareScheduleTable(sched_explicit_next);
DeclareScheduleTable(sched_explicit_autostart);
DeclareScheduleTable(sched_implicit);
DeclareScheduleTable(sched_nosync);
DeclareScheduleTable(INVALID_SCHEDULETABLE);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_3, result_inst_4, result_inst_5, result_inst_6, result_inst_7, result_inst_8, result_inst_9, result_inst_10, result_inst_11, result_inst_12, result_inst_13, result_inst_14, result_inst_15;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = StartScheduleTableSynchron(INVALID_SCHEDULETABLE);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OS_ID, result_inst_1);

	SCHEDULING_CHECK_INIT(3);
	result_inst_2 = StartScheduleTableSynchron(sched_implicit);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_ID, result_inst_2);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_3 = StartScheduleTableSynchron(sched_nosync);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OS_ID, result_inst_3);

	SCHEDULING_CHECK_INIT(7);
	result_inst_4 = SyncScheduleTable(INVALID_SCHEDULETABLE, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_ID, result_inst_4);

	SCHEDULING_CHECK_INIT(9);
	result_inst_5 = SyncScheduleTable(sched_implicit, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OS_ID, result_inst_5);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_6 = SyncScheduleTable(sched_nosync, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OS_ID, result_inst_6);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_7 = SyncScheduleTable(sched_explicit, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OS_STATE, result_inst_7);

	SCHEDULING_CHECK_INIT(15);
	result_inst_8 = StartScheduleTableSynchron(sched_explicit);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK, result_inst_8);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_8 = StartScheduleTableAbs(sched_explicit, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OS_STATE, result_inst_8);
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_8 = StartScheduleTableRel(sched_explicit, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(19,E_OS_STATE, result_inst_8);
	
	SCHEDULING_CHECK_INIT(20);
	result_inst_9 = NextScheduleTable(sched_explicit, sched_explicit_next);
	SCHEDULING_CHECK_AND_EQUAL_INT(20,E_OK, result_inst_9);
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_10 = SyncScheduleTable(sched_explicit_next, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(22,E_OS_STATE, result_inst_10);
	
	SCHEDULING_CHECK_INIT(23);
	result_inst_11 = SyncScheduleTable(sched_explicit, 11);
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_OS_VALUE, result_inst_11);

	SCHEDULING_CHECK_INIT(25);
	result_inst_12 = SetScheduleTableAsync(INVALID_SCHEDULETABLE);
	SCHEDULING_CHECK_AND_EQUAL_INT(26,E_OS_ID, result_inst_12);
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_13 = SetScheduleTableAsync(sched_implicit);
	SCHEDULING_CHECK_AND_EQUAL_INT(28,E_OS_ID, result_inst_13);
	
	SCHEDULING_CHECK_INIT(29);
	result_inst_14 = SetScheduleTableAsync(sched_nosync);
	SCHEDULING_CHECK_AND_EQUAL_INT(30,E_OS_ID, result_inst_14);	
	
	SCHEDULING_CHECK_INIT(31);
	result_inst_15 = StartScheduleTableRel(sched_implicit, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(32,E_OS_ID, result_inst_15);
	
	SCHEDULING_CHECK_INIT(33);
	result_inst_7 = SyncScheduleTable(sched_explicit, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(33,E_OK, result_inst_7);
	
	SCHEDULING_CHECK_INIT(34);
	result_inst_8 = StartScheduleTableAbs(sched_explicit, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(35,E_OS_STATE, result_inst_8);
	
	SCHEDULING_CHECK_INIT(36);
	result_inst_8 = StartScheduleTableRel(sched_explicit, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(37,E_OS_STATE, result_inst_8);
			
}

/*create the test suite with all the test cases*/
TestRef AutosarSTSTest_seq2_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTSTest,"AutosarSTTest_sequence2",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTSTest;
}
