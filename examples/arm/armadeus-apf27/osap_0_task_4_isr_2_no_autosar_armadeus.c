#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"

#define TRACE_OSAP1(val) flags_osap1[count_osap1++] = val

#define APP_osap1_START_SEC_CONST_32BIT
#include "MemMap.h"

CONST(u32, DEMO042NO_APPL_osap1_DATA ) CONST_TO_WRITE = 0x55;

#define APP_osap1_STOP_SEC_CONST_32BIT
#include "MemMap.h"


#define APP_osap1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, DEMO042NO_APPL_osap1_DATA	) flags_osap1[10] = {0};
VAR(int, DEMO042NO_APPL_osap1_DATA	) count_osap1 = 0;

#define APP_osap1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


#define TASK_t1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, DEMO042NO_TASK_t1_DATA) var_t1 = 0;

#define TASK_t1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define TASK_t2_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, DEMO042NO_TASK_t2_DATA) var_t2 = 0;
P2VAR (u32, DEMO042NO_TASK_t2_DATA, OS_CODE) write_code; 

#define TASK_t2_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define TASK_t3_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, DEMO042NO_TASK_t3_DATA) var_t3 = 20;
P2VAR (u32, DEMO042NO_TASK_t2_DATA, OS_CONST) write_const;

#define TASK_t3_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define TASK_t4_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, DEMO042NO_TASK_t4_DATA) var_t4 = 0;

#define TASK_t4_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define ISR_it1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, DEMO042NO_ISR_it1_DATA) var_it1 = 0;

#define ISR_it1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define ISR_it2_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, DEMO042NO_ISR_it2_DATA) var_it2 = 0;

#define ISR_it2_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
FUNC(int, DEMO042NO_APPL_osap1_CODE) main()
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DEMO042NO_APPL_osap1_CODE) ProtectionHook(StatusType error)
{
	TRACE_OSAP1(0x55555555);
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DEMO042NO_APPL_osap1_CODE) ErrorHook(StatusType error)
{
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DEMO042NO_APPL_osap1_CODE) PreTaskHook(void)
{
/* FIXME */
/*    TaskType id;
    GetTaskID(&id);*/
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DEMO042NO_APPL_osap1_CODE) PostTaskHook(void)
{
/*    TaskType id;
    GetTaskID(&id);*/
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DEMO042NO_APPL_osap1_CODE) StartupHook(void)
{
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DEMO042NO_APPL_osap1_CODE) ShutdownHook(StatusType error)
{
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
FUNC(void, DEMO042NO_APPL_osap1_CODE) trap_func(void)
{

}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
TASK(t4)
{
  	var_t4 = 1;
	trap_func ();
  	var_t4 = 2;
	TerminateTask ();
	trap_func ();
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
ISR(it2)
{
	var_it2 = 1;
	trap_func ();
	ActivateTask (t4);
	var_it2 = 2;
	trap_func ();
	TerminateISR ();
	trap_func ();
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
ISR(it1)
{
	var_it1 = 1;
	trap_func ();
	var_it1 = 2;
	TerminateISR ();
	trap_func ();
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
TASK(t3)
{
  	var_t3 = 1;
  	write_const = (u32*) (&CONST_TO_WRITE); /* Try to read in the const section */
  	*write_const = CONST_TO_WRITE; /* Try to write in the const section */
	trap_func ();
	var_t3 = 2;
	TerminateTask ();
	trap_func ();
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
TASK(t2)
{
  	var_t2 = var_t3; /* Try to read in the task 3 data section's */
	var_t2 = (u32) (&trap_func); /* Try to read in the code section */
  	write_code = (u32*) var_t2;
  	*write_code = CONST_TO_WRITE; /* Try to write in the code section */
  	var_t2 = 1;
	trap_func ();
	ActivateTask (t3);
	trap_func ();
	var_t2 = 2;
	TerminateTask ();
	trap_func ();
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_osap1_START_SEC_CODE
#include "MemMap.h"
TASK(t1)
{
  	var_t1 = 1;
  	var_t2 = 3; /* Try to write in the task 2 data section's */
	trap_func ();
	ActivateTask (t2);
	trap_func ();
	var_t1 = 2;
	TerminateTask();
	trap_func ();
}
#define APP_osap1_STOP_SEC_CODE
#include "MemMap.h"

