/*Instance of interruption isr1*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareResource(Resource1);

void tpl_send_it2(void);
void tpl_send_it3(void);

/*test case:test the reaction of the system called with 
 an activation of a isr*/
static void test_isr1_instance(void)
{
	StatusType result_inst_1, result_inst_2, result_inst_4, result_inst_5, result_inst_6;
	
	SCHEDULING_CHECK_INIT(21);
	result_inst_1 = GetResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(21 , E_OK, result_inst_1);
	
	tpl_send_it2();
	
	tpl_send_it3();
	/*it3 trigged*/
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_2 = ReleaseResource(Resource1);
	/*it2 trigged*/
	SCHEDULING_CHECK_AND_EQUAL_INT(25 , E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(26);
	result_inst_4 = GetResource(RES_SCHEDULER);
	SCHEDULING_CHECK_AND_EQUAL_INT(26 , E_OS_ACCESS, result_inst_4);
	
	SCHEDULING_CHECK_INIT(27);
	result_inst_5 = ReleaseResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(27 , E_OS_NOFUNC, result_inst_5);
	
	SCHEDULING_CHECK_INIT(28);
	result_inst_6 = ReleaseResource(RES_SCHEDULER);
	SCHEDULING_CHECK_AND_EQUAL_INT(28 , E_OS_NOFUNC, result_inst_6);
	
	/*t2 trigged after isr1 instance*/
}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq1_isr1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_isr1_instance",test_isr1_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence1",NULL,NULL,fixtures);
	
	return (TestRef)&ResourceManagementTest;
}
