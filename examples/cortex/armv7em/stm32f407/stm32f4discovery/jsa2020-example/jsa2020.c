#include "tp.h"
#include "tpl_os.h"

#define APP_Task_task1_START_SEC_CODE

#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void) {
  initBoard();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(task1) { TerminateTask(); }

#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task2) { TerminateTask(); }

#define APP_Task_back_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task3_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task3) { TerminateTask(); }

#define APP_Task_back_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t *file, uint32_t line) {}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
