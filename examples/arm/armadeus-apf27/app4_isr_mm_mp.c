#include "tpl_os.h"
#include "tpl_as_protec_hook.h"
#include "serial.h"
#include "tpl_os_kernel.h" /* to access to tpl_kern */

#define TRACE_SYS(val) flags_sys[count_sys++] = val
#define TRACE_OSAP1(val) flags_osap1[count_osap1++] = val
#define TRACE_OSAP2(val) flags_osap2[count_osap2++] = val
#define TRACE_OSAP3(val) flags_osap3[count_osap3++] = val

#define APP_OS_APP_osap1_START_SEC_CONST_32BIT
#include "MemMap.h"

CONST(u32, AUTOMATIC) osap1_constant = 0xBBBBBBBB;

#define APP_OS_APP_osap1_STOP_SEC_CONST_32BIT
#include "MemMap.h"

#define APP_OS_APP_osap2_START_SEC_CONST_32BIT
#include "MemMap.h"

/* constant size is 1 byte to see if alignement is
 * respected
 */
CONST(u8, AUTOMATIC) osap2_constant = 0xAA;

#define APP_OS_APP_osap2_STOP_SEC_CONST_32BIT
#include "MemMap.h"

#define APP_OS_APP_osap1_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(u32, AUTOMATIC) flags_osap1[15] = {0};
VAR(u32, AUTOMATIC) count_osap1 = 0;

#define APP_OS_APP_osap1_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define APP_OS_APP_osap1_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"

#define OSAP1_LSM_SIZE (2*1024*1024+512*1024)

VAR(u8, AUTOMATIC) osap1_large_shared_memory[OSAP1_LSM_SIZE];

#define APP_OS_APP_osap1_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h"


#define APP_OS_APP_osap2_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(u32, AUTOMATIC) flags_osap2[15] = {0};
VAR(u32, AUTOMATIC) count_osap2 = 0;

#define APP_OS_APP_osap2_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define APP_OS_APP_osap3_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

VAR(u32, AUTOMATIC) flags_osap3[15] = {0};
VAR(u32, AUTOMATIC) count_osap3 = 0;

#define APP_OS_APP_osap3_STOP_SEC_VAR_UNSPECIFIED
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

#define OS_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

u32 flags_sys[15] = {0};
u32 count_sys = 0;

#define OS_STOP_SEC_VAR_UNSPECIFIED
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
  serial_puts("\nTrampoline starts...\n");
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

extern CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) proc_name_table[TASK_COUNT + ISR_COUNT];

FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(StatusType error)
{
  TRACE_SYS(tpl_kern.running_id);
	serial_puts ("Protection hook (kill process ");
  serial_puts (proc_name_table[tpl_kern.running_id]);
  serial_puts (")!\n");

	return PRO_TERMINATETASKISR;
}

FUNC(void, AUTOMATIC) ErrorHook(StatusType error)
{
	serial_puts ("Error hook !\n");
  TRACE_SYS(0xFFFFFFFF);
}

ISR(it1)
{
  serial_puts("it1 comes\n");
}

DeclareTask (t4);

ISR(it2)
{
  serial_puts("it2 comes\n");
  ActivateTask (t4);
}

TASK(t5)
{
	u32 *ptr;

  serial_puts("t5 starts (from trusted OS Application)\n");
  TRACE_OSAP3(50);
  serial_puts("t5 writes on its own data\n");
  var_t5 = 5;
  TRACE_OSAP3(51);
  serial_puts("t5 reads its own data\n");
  var_t5 = count_osap1;
  TRACE_OSAP3(52);
  serial_puts("t5 writes to t2's data\n");
  var_t2 = 5;
  TRACE_OSAP3(53);
  serial_puts("t5 reads to unaligned memory (should raise memory protection exception)\n");
	ptr = (u32 *)1;
	var_t5 = *ptr;
  TRACE_OSAP3(54);
  TerminateTask ();
  TRACE_OSAP3(55);
}

DeclareTask (t1);

TASK(t4)
{
  TRACE_OSAP2(40);
  var_t4 = 4;
  TRACE_OSAP2(41);
  ActivateTask(t1);
  TRACE_OSAP2(42);
  TerminateTask ();
  TRACE_OSAP2(43);
}

TASK(t3)
{
  int i;

  TRACE_OSAP2(30);
  var_t3 = 1; /* write to its own data */
  TRACE_OSAP2(31);
  ActivateTask (t4);
  TRACE_OSAP2(32);
  /* overflow stack */
  for (i = 0 ; i < (1024 * 1024) ; i++)
  {
    __asm__ ("stmfd sp!, {r0-r3}\n"); 
  }
  TRACE_OSAP2(33);
  TerminateTask ();
  TRACE_OSAP2(34);
}

long int factorielle (long int input)
{
  if (input == 0)
    return 1;
  else
    return input * factorielle (input - 1);
}

TASK(t2)
{
  int i;
  int flag;

  TRACE_OSAP1(20);
  flag = 1;
  for (i = 0 ; i < (OSAP1_LSM_SIZE) ; i++)
  {
    if (osap1_large_shared_memory[i] != ((i+1) & 0xFF))
      flag = 0;
  }
  if (flag)
    TRACE_OSAP1(21);
  TRACE_OSAP1(22);
  var_t2 = 2; /* Try to write to own data */
  TRACE_OSAP1(23);
  factorielle (100); /* stress the stack */
  TRACE_OSAP1(24);
  var_t2 = *((u32 *)&main); /* Try to read in the code section */
  TRACE_OSAP1(25);
  *((u32 *)&main) = 4; /* Try to write in the code section */
  TRACE_OSAP1(26);
  TerminateTask ();
  TRACE_OSAP1(27);
}

TASK(t1)
{
  int i;
  TRACE_OSAP1(10);
  for (i = 0 ; i < (OSAP1_LSM_SIZE) ; i++)
  {
    osap1_large_shared_memory[i] = (i+1) & 0xFF; 
  }
  TRACE_OSAP1(11);
  ActivateTask(t2);
  TRACE_OSAP1(12);
  var_t1 = 1; /* Try to write in the own data section's */
  TRACE_OSAP1(13);
  var_t2 = 1; /* Try to write in another taks data section's of the same osap (should raise a protection exception) */
  TerminateTask();
  TRACE_OSAP1(15);
}

TASK(finish_test)
{
  ShutdownOS (E_OK);
}

#define APP_COMMON_STOP_SEC_CODE
#include "MemMap.h"

