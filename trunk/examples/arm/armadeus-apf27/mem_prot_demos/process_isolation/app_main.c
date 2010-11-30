#include "tpl_os.h"
#include "tpl_as_protec_hook.h"
#include "app_rs232_driver.h"

#define APP_Task_background_worker_START_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

CONST(char, AUTOMATIC) secret[] = "You should not see this message\n";

#define APP_Task_background_worker_STOP_SEC_VAR_UNSPECIFIED
#include "MemMap.h"

#define APP_COMMON_START_SEC_CODE
#include "MemMap.h"

DeclareTask (faulty_task1);
DeclareTask (faulty_task2);

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
  tf_rs232_print ("background worker starts faulty task1\n");
  ActivateTask (faulty_task1);
  tf_rs232_print ("background worker starts faulty task2\n");
  ActivateTask (faulty_task2);
  while (1)
    do_work ();

  TerminateTask ();
}

TASK(faulty_task2)
{
  tf_rs232_print ("faulty task1 try to read indirectly the string...\n");
  tf_rs232_print (secret);

  TerminateTask ();
}

TASK(faulty_task1)
{
  char buffer[100];
  char *ptr;
  int i;

  tf_rs232_print ("faulty task1 try to read directly the string...\n");
  i = 0;
  ptr = secret;
  do
  {
    buffer[i++] = *ptr;
  }
  while (*(ptr++) != '\0');
  tf_rs232_print (buffer);

  TerminateTask ();
}

#define APP_COMMON_STOP_SEC_CODE
#include "MemMap.h"

