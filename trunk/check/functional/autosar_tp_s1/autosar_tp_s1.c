
#include "Os.h"
#include "embUnit.h"
#include "config.h" /*for stdimpl_print*/

TestRef AutosarTPTest_seq1_t1_instance1(void);
TestRef AutosarTPTest_seq1_t1_instance2(void);
TestRef AutosarTPTest_seq1_t1_instance3(void);
TestRef AutosarTPTest_seq1_t2_instance(void);
TestRef AutosarTPTest_seq1_t3_instance(void);
TestRef AutosarTPTest_seq1_t4_instance(void);
TestRef AutosarTPTest_seq1_protection_instance1(void);
TestRef AutosarTPTest_seq1_protection_instance2(void);

StatusType instance_protection = 0;
StatusType instance_t1 = 0;
ProtectionReturnType protectiontypetoreturn = PRO_IGNORE;

int main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void ShutdownHook(StatusType error)
{ 
	TestRunner_end();
}

void ErrorHook(StatusType error)
{
  stdimpl_print("ErrorHook : Instance error\n");	
}


ProtectionReturnType ProtectionHook(StatusType Fatalerror)
{
	instance_protection++;
  stdimpl_print("ProtectionHook:%d\n",instance_protection);
	switch (instance_protection)
	{
		case 1 :
		{
      TestRunner_runTest(AutosarTPTest_seq1_protection_instance1());
			break;
		}
		case 2 :
		{
      TestRunner_runTest(AutosarTPTest_seq1_protection_instance2());
			break;
		}
		default:
		{
			stdimpl_print("ProtectionHook : Instance error\n");
			break;
		}
	}
  
  return protectiontypetoreturn;
	
}

TASK(t1)
{
  instance_t1++;
	switch (instance_t1)
	{
		case 1 :
		{
      TestRunner_start();
      TestRunner_runTest(AutosarTPTest_seq1_t1_instance1());
			break;
		}
		case 2 :
		{
      TestRunner_runTest(AutosarTPTest_seq1_t1_instance2());
      break;
		}
		case 3 :
		{
      TestRunner_runTest(AutosarTPTest_seq1_t1_instance3());
      break;
		}
		default:
		{
			stdimpl_print("t1 : Instance error\n");
			break;
		}
	}
}

TASK(t2)
{
  TestRunner_runTest(AutosarTPTest_seq1_t2_instance());
}

TASK(t3)
{
  TestRunner_runTest(AutosarTPTest_seq1_t3_instance());
}

TASK(t4)
{
  TestRunner_runTest(AutosarTPTest_seq1_t4_instance());
  ShutdownOS(E_OK);
}

