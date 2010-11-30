#include "tpl_os.h"
#include "tpl_as_protec_hook.h"
#include "app_rs232_driver.h"

#define APP_COMMON_START_SEC_CODE
#include "MemMap.h"

DeclareTask (faulty_task);

void do_work (void)
{
  int i;

  for (i = 0 ; i < (1000 * 1000) ; i++);
  tf_rs232_print ("background worker works\n");
}

TASK(background_worker)
{
  volatile int i;

  for (i = 0 ; i < 4 ; i++)
    do_work ();
  tf_rs232_print ("background worker starts faulty task\n");
  ActivateTask (faulty_task);
  while (1)
    do_work ();

  TerminateTask ();
}

FUNC(void, OS_APPL_CODE) do_stack_overflow (int depth, int *some_data)
{
  volatile int big_var_on_stack[1024];
  register int i;

  if (depth < 100)
  {
    tf_rs232_print ("faulty task: depth = ");
    tf_rs232_print_hex (depth);
    tf_rs232_print ("\n");
    for (i = 0 ; i < 1024 ; i++)
      big_var_on_stack[i] = 0;
    do_stack_overflow (depth + 1, big_var_on_stack);
  }
}

TASK(faulty_task)
{
  tf_rs232_print ("faulty task begins to overflow its stack\n");
  do_stack_overflow (0, (int *)0);

  TerminateTask ();
}

#define APP_COMMON_STOP_SEC_CODE
#include "MemMap.h"

