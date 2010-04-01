#include <stdio.h>
#include "tpl_os.h"
#include "tpl_app_config.h"

#define APP_Task_t1_START_SEC_CONST_32BIT
#include "MemMap.h"

CONST(u32, AUTOMATIC ) CONST_TO_WRITE = 0x55;

#define APP_Task_t1_STOP_SEC_CONST_32BIT
#include "MemMap.h"


#define APP_Task_t1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR (int, AUTOMATIC) trace = 0;
VAR(int, AUTOMATIC) var_t1 = 0;

#define APP_Task_t1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define APP_Task_t2_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, AUTOMATIC) var_t2 = 0;
P2VAR (u32, AUTOMATIC, OS_CODE) write_code; 

#define APP_Task_t2_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define APP_Task_t3_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, AUTOMATIC) var_t3 = 20;
P2VAR (u32, AUTOMATIC, OS_CONST) write_const;

#define APP_Task_t3_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define APP_Task_t4_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, AUTOMATIC) var_t4 = 0;

#define APP_Task_t4_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define APP_ISR_it1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, AUTOMATIC) var_it1 = 0;

#define APP_ISR_it1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define APP_ISR_it2_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, AUTOMATIC) var_it2 = 0;

#define APP_ISR_it2_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


#define APP_Task_t1_START_SEC_CODE
#include "MemMap.h"
FUNC(int, AUTOMATIC) main()
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}
FUNC(void, AUTOMATIC) ProtectionHook(StatusType error)
{
	trace++;
}

FUNC(void, AUTOMATIC) ErrorHook(StatusType error)
{
}

DeclareTask (t2);

TASK(t1)
{
	u32 *ptr;

	var_t1 = 1;
 	var_t2 = 3; /* Try to write in the task 2 data section's */
	ptr = &CONST_TO_WRITE;
	*ptr = 18;
	ActivateTask (t2);
	TerminateTask();
}
#define APP_Task_t1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_Task_t4_START_SEC_CODE
#include "MemMap.h"
TASK(t4)
{
	TerminateTask ();
}
#define APP_Task_t4_STOP_SEC_CODE
#include "MemMap.h"

#define APP_ISR_it2_START_SEC_CODE
#include "MemMap.h"
ISR(it2)
{
	TerminateISR ();
}
#define APP_ISR_it2_STOP_SEC_CODE
#include "MemMap.h"

#define APP_ISR_it1_START_SEC_CODE
#include "MemMap.h"
ISR(it1)
{
	TerminateISR ();
}
#define APP_ISR_it1_STOP_SEC_CODE
#include "MemMap.h"

#define APP_Task_t3_START_SEC_CODE
#include "MemMap.h"
TASK(t3)
{
	TerminateTask ();
}
#define APP_Task_t3_STOP_SEC_CODE
#include "MemMap.h"

#define APP_Task_t2_START_SEC_CODE
#include "MemMap.h"
TASK(t2)
{
	TerminateTask ();
}
#define APP_Task_t2_STOP_SEC_CODE
#include "MemMap.h"

