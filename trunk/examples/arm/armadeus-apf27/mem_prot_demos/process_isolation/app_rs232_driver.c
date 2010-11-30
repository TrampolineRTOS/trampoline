#include "tpl_os.h"
#include "tpl_as_protec_hook.h"
#include "tpl_app_config.h"
#include "serial.h"

#define APP_COMMON_START_SEC_CODE
#include "MemMap.h"

FUNC(void, OS_APPL_CODE) tf_rs232_print_hex (int this_number)
{
  char digit[2];
  int mask;
  int i;

  digit[1] = '\0';
  mask = 0xF000;
  for (i = 0 ; i < 4 ; i++)
  {
    digit[0] = (this_number & mask) >> (3 - i) * 4;
    if (digit[0] < 10)
      digit[0] += '0';
    else
      digit[0] += 'A' - 10;
    tf_rs232_print (digit);
    mask = mask >> 4;
  }
}

/* wrapper for TRUSTED_rs232_print trusted function */
FUNC(void, OS_APPL_CODE) tf_rs232_print (char *this_string)
{
  CallTrustedFunction (rs232_print, (TrustedFunctionParameterRefType)this_string);
}

FUNC(void, OS_APPL_CODE) TRUSTED_rs232_print(
  CONST(TrustedFunctionIndexType, AUTOMATIC) idx,
  CONST(TrustedFunctionParameterRefType, AUTOMATIC) params)
{
  TaskType my_tid;
  char *current_car;

  /* checks the task has access to each character of the string */
#if 0
  if (GetTaskID (&my_tid) != E_OK)
  {
    serial_puts ("rs232_print internal error\n");
    return;
  }
  current_car = (char *)params;
  while (OSMEMORY_IS_READABLE (CheckTaskMemoryAccess (my_tid, current_car, 1)))
  {
    if (*current_car == '\0')
      break;
    current_car++;
  }
  if (!OSMEMORY_IS_READABLE (CheckTaskMemoryAccess (my_tid, current_car, 1)))
  {
    serial_puts ("illegal access\n");
    return;
  }
#endif /* 0 */
  serial_puts ((char *) params);
}

TASK(do_nothing)
{
  TerminateTask ();
}

#define APP_COMMON_STOP_SEC_CODE
#include "MemMap.h"

