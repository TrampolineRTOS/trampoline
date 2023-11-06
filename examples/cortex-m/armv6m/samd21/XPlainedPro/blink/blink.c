#include "tpl_os.h"
//the READY tasks state definition conflicts with registers definition (in sam.h)
#undef READY
#include "sam.h"

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  //led on PB.30
  PORT->Group[1].DIRSET.reg = 1<<30;
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
  PORT->Group[1].OUTTGL.reg= 1<<30;
  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

