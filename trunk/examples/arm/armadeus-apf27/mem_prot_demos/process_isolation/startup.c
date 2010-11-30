#include "tpl_os.h"
#include "tpl_as_protec_hook.h"
#include "serial.h"

#define APP_COMMON_START_SEC_CODE
#include "MemMap.h"

FUNC(void, OS_CODE) ShutdownHook(VAR(StatusType, AUTOMATIC) error)
{
  serial_puts ("Trampoline has shutdown\n");
}

extern CONSTP2CONST(char, AUTOMATIC, OS_APPL_DATA) proc_name_table[TASK_COUNT + ISR_COUNT];
FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(StatusType error)
{
  TaskType id;

  if (GetTaskID (&id) == E_OK)
  {
    serial_puts ("Protection hook (kill process ");
    serial_puts (proc_name_table[id]);
    serial_puts (")!\n");
  }
  else
    serial_puts ("Error calling GetTaskID, bug in memory protection ?\n");

  return PRO_TERMINATETASKISR;
}

FUNC(void, AUTOMATIC) ErrorHook(StatusType error)
{
  serial_puts ("Error hook !\n");
}


FUNC(int, AUTOMATIC) main()
{
  volatile int i;

  serial_init();
  i = 1000 * 1000;
  while (i--);
  serial_puts("\nTrampoline starts...\n");
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

#define APP_COMMON_STOP_SEC_CODE
#include "MemMap.h"

