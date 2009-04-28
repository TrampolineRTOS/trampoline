/*Instance of task t1*/

#include "embUnit.h"
#include "tpl_os.h"
#include "config.h"

DeclareTask(t2);
DeclareTask(t3);
DeclareResource(Resource1);

/*test case:test the reaction of the system called with 
an activation of a task*/
static void test_t1_instance(void)
{
	
	StatusType result_inst_1,result_inst_2, result_inst_3, result_inst_4;
	
	SCHEDULING_CHECK_INIT(1);
	result_inst_1 = GetResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(1,E_OK, result_inst_1); 
		
	SCHEDULING_CHECK_INIT(2);
	result_inst_2 = ActivateTask(t2);
	SCHEDULING_CHECK_AND_EQUAL_INT(2,E_OK, result_inst_2);
	
	SCHEDULING_CHECK_INIT(3);
	result_inst_3 = ActivateTask(t3);
	SCHEDULING_CHECK_AND_EQUAL_INT(4,E_OK, result_inst_3);
	
	SCHEDULING_CHECK_INIT(5);
	result_inst_4 = ReleaseResource(Resource1);
	SCHEDULING_CHECK_AND_EQUAL_INT(6,E_OK, result_inst_4);

}

/*create the test suite with all the test cases*/
TestRef ResourceManagementTest_seq3_t1_instance(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t1_instance",test_t1_instance)
	};
	EMB_UNIT_TESTCALLER(ResourceManagementTest,"ResourceManagementTest_sequence3",NULL,NULL,fixtures);

	return (TestRef)&ResourceManagementTest;
}
