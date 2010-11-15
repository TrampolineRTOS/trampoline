/*#include <stdio.h>*/
#include "tpl_os.h"
#include "tpl_as_protec_hook.h"

#define TRACE_OSAP1(val) flags_osap1[count_osap1++] = val
#define TRACE_OSAP2(val) flags_osap2[count_osap2++] = val

#define APP_OS_APP_osap1_START_SEC_CONST_32BIT
#include "MemMap.h"

CONST(u32, AUTOMATIC) OSAP1_CONST_TO_WRITE = 0xBBBBBBBB;
CONST(u32, AUTOMATIC) OSAP1_PRO_HOOK = 0x55555555;

#define APP_OS_APP_osap1_STOP_SEC_CONST_32BIT
#include "MemMap.h"

#define APP_OS_APP_osap2_START_SEC_CONST_32BIT
#include "MemMap.h"

CONST(u32, AUTOMATIC) OSAP2_CONST = 0xAAAAAAAA;

#define APP_OS_APP_osap2_STOP_SEC_CONST_32BIT
#include "MemMap.h"


#define APP_OS_APP_osap1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, AUTOMATIC  ) flags_osap1[15] = {0};
VAR(int, AUTOMATIC  ) count_osap1 = 0;

#define APP_OS_APP_osap1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


#define APP_OS_APP_osap2_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, AUTOMATIC  ) flags_osap2[10] = {0};
VAR(int, AUTOMATIC  ) count_osap2 = 0;

#define APP_OS_APP_osap2_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"


#define APP_Task_t1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

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

#define APP_Task_t5_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(int, AUTOMATIC) var_t5 = 0;

#define APP_Task_t5_STOP_SEC_VAR_UNSPECIFIED
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


#define APP_COMMON_START_SEC_CODE
#include "MemMap.h"

FUNC(void, OS_CODE) ShutdownHook(VAR(StatusType, AUTOMATIC) error)
{
	serial_puts ("Trampoline has shutdown\n");
}

FUNC(int, AUTOMATIC) main()
{
  serial_init();
  serial_puts("Trampoline is starting...\n");
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(StatusType error)
{
	serial_puts ("Protection hook");
  TRACE_OSAP1(OSAP1_PRO_HOOK);

	return PRO_TERMINATETASKISR;
}

FUNC(void, AUTOMATIC) ErrorHook(StatusType error)
{
}

ISR(it1)
{
  serial_puts("it1 comes\n");
  TRACE_OSAP1(6);
  var_it1 = 1;
  var_it1 = 2;
}

TASK(t5)
{
  serial_puts("t5 comes\n");
  TRACE_OSAP2(5);
  var_t5 = count_osap1; /* Try to read in another osap data section's */
  var_t5 = 1;
  var_t5 = 2;
  TerminateTask ();
}

TASK(t4)
{
  serial_puts("t4 comes\n");
  TRACE_OSAP1(4);
  var_t4 = 1;
  var_t4 = 2;
  TerminateTask ();
}

ISR(it2)
{
  serial_puts("it2 comes\n");
  TRACE_OSAP2(7);
  var_it2 = 1;
  ActivateTask (t4);
  TRACE_OSAP2(7);
  var_it2 = 2;
}

TASK(t3)
{
  serial_puts("t3 comes\n");
  TRACE_OSAP1(3); /* Try to write in the own osap data section's */
  TRACE_OSAP2(3); /* Try to write  and read in another osap data section's */
            /* Beware more than one data abort .. */
  var_t3 = 1;
  write_const = (u32*) (&OSAP1_PRO_HOOK); /* Try to read in the const section */
  *write_const = OSAP1_CONST_TO_WRITE; /* Try to write in the const section */
  ActivateTask (t4);
  TRACE_OSAP1(3);
  var_t3 = 2;
  TerminateTask ();
}

TASK(t2)
{
  serial_puts("t2 comes\n");
  TRACE_OSAP2(2);
    var_t2 = var_t3; /* Try to read in another task of another osap data section's */
  var_t2 = (u32) (&main); /* Try to read in the code section */
    write_code = (u32*) var_t2;
    *write_code = OSAP1_CONST_TO_WRITE; /* Try to write in the code section */
    var_t2 = 1;
  ActivateTask (t3);
  TRACE_OSAP2(2);
  var_t2 = 2;
  TerminateTask ();
}

TASK(t1)
{
  serial_puts("t1 step 1\n");
  TRACE_OSAP1(1);
  serial_puts("t1 step 2\n");
  var_t1 = 1; /* Try to write in the own data section's */
  var_t3 = 1; /* Try to write in another taks data section's of the same osap */
  var_t2 = 3; /* Try to write in another task data section's of another osap */
  serial_puts("t1 step 3\n");
  ActivateTask (t3);
  serial_puts("t1 step 4\n");
  TRACE_OSAP1(1);
  var_t1 = 2;
  TerminateTask();
}

#define APP_COMMON_STOP_SEC_CODE
#include "MemMap.h"

