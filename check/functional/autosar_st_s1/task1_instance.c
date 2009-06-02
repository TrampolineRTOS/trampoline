/*Instance of task t1*/

#include "embUnit.h"
#include "Os.h"

DeclareScheduleTable(INVALID_SCHEDULETABLE);
DeclareScheduleTable(sched_1);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t1_instance(void)
{
	StatusType result_inst_1;
	ScheduleTableStatusType ScheduleTableStatusType_inst_1;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetScheduleTableStatus(sched_1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(1,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(2);
	result_inst_1 = StartScheduleTableRel(INVALID_SCHEDULETABLE, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OS_ID, result_inst_1);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_1 = StartScheduleTableRel(sched_1, 0);
	SCHEDULING_CHECK_AND_EQUAL_INT(3,E_OS_VALUE, result_inst_1);
	
	SCHEDULING_CHECK_INIT(4);
	result_inst_1 = StartScheduleTableRel(sched_1, 200); /* > (OSMAXALLOWEDVALUE - InitOffset) */
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OS_VALUE, result_inst_1);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_1 = StartScheduleTableRel(sched_1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(5,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(6);
	result_inst_1 = GetScheduleTableStatus(sched_1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(6,SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_1);
		
	SCHEDULING_CHECK_INIT(7);
	result_inst_1 = StartScheduleTableRel(sched_1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(7,E_OS_STATE, result_inst_1);
	
	SCHEDULING_CHECK_INIT(8);
	result_inst_1 = StopScheduleTable(INVALID_SCHEDULETABLE);
	SCHEDULING_CHECK_AND_EQUAL_INT(8,E_OS_ID, result_inst_1);
	
	SCHEDULING_CHECK_INIT(9);
	result_inst_1 = StopScheduleTable(sched_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(9,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(10);
	result_inst_1 = GetScheduleTableStatus(sched_1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(10,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(10,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(11);
	result_inst_1 = StopScheduleTable(sched_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(11,E_OS_NOFUNC, result_inst_1);
	
	
	SCHEDULING_CHECK_INIT(12);
	result_inst_1 = StartScheduleTableAbs(INVALID_SCHEDULETABLE, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(12,E_OS_ID, result_inst_1);
	
	SCHEDULING_CHECK_INIT(13);
	result_inst_1 = StartScheduleTableAbs(sched_1, 200); /* > (OSMAXALLOWEDVALUE) */
	SCHEDULING_CHECK_AND_EQUAL_INT(13,E_OS_VALUE, result_inst_1);
	
	SCHEDULING_CHECK_INIT(14);
	result_inst_1 = StartScheduleTableAbs(sched_1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(14,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(15);
	result_inst_1 = GetScheduleTableStatus(sched_1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(15,SCHEDULETABLE_RUNNING , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(15,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(16);
	result_inst_1 = StartScheduleTableAbs(sched_1, 1);
	SCHEDULING_CHECK_AND_EQUAL_INT(16,E_OS_STATE, result_inst_1);
	
	SCHEDULING_CHECK_INIT(17);
	result_inst_1 = StopScheduleTable(sched_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(17,E_OK, result_inst_1);
	
	SCHEDULING_CHECK_INIT(18);
	result_inst_1 = GetScheduleTableStatus(sched_1, &ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(18,SCHEDULETABLE_STOPPED , ScheduleTableStatusType_inst_1);
	SCHEDULING_CHECK_AND_EQUAL_INT(18,E_OK, result_inst_1);
	
}

/*create the test suite with all the test cases*/
TestRef AutosarSTTest_seq1_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(AutosarSTTest,"AutosarSTTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&AutosarSTTest;
}
