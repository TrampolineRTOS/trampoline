/* Libraries */

#include "tpl_os.h"
#include "lpc22xx.h"
#include "tp_ecn.h"

/* Main */

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  /* set io pins for led STAT on the mother board */
  IO1DIR |= (1 << 23);
  IO1SET =  1 << 23; // led off
  IO1CLR =  1 << 23; // led on
  /* set io pins for led on daughter board */
  IO1DIR |= (1 << 20);
  IO1CLR =  1 << 20; // led off
//  IO1SET =  1 << 20; // led on
  /* set io pins for led on daughter board */
  IO1DIR |= (1 << 21);
  IO1CLR =  1 << 21; // led off
  IO1SET =  1 << 21; // led on
  /* set io pins for led on daughter board */
  IO1DIR |= (1 << 22);
  IO1CLR =  1 << 22; // led off
  IO1SET =  1 << 22; // led on
  /* set io pins for led D6 on daughter board -  */
  IO1DIR |= (1 << 24);
  IO1CLR =  1 << 24; // led off
  IO1SET =  1 << 24; // led on
    
  open_serial_1(19200);
  lcd_init();
  lcd_print_string("Trampoline");

  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"

/* Vars */
#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, OS_VAR) switch_count = 0;
VAR(TaskType, OS_VAR) new_task;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_task1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(uint32, AUTOMATIC) task1Counter = 0;
#define APP_Task_task1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_task2_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(uint32, AUTOMATIC) task2Counter = 0;
#define APP_Task_task2_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_task3_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(uint32, AUTOMATIC) task3Counter = 0;
#define APP_Task_task3_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

/* Application */

DeclareTask(task1);
DeclareTask(task2);
DeclareTask(task3);

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
void PreTaskHook()
{
  TaskType tid;
  GetTaskID(&tid);
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task1)
{
  task1Counter++;
  lcd_goto_line_column(1,0);
  lcd_print_string("task1");
  lcd_goto_line_column(1,6);
  lcd_print_string("-");
  lcd_goto_line_column(1,8);
  lcd_print_unsigned(task1Counter);
  ActivateTask(task3);

  TerminateTask();  
}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task2)
{
  static int state = 0;
  
  task2Counter++;
  lcd_goto_line_column(2,0);
  lcd_print_string("task2");
  lcd_goto_line_column(2,6);
  lcd_print_string("-");
  lcd_goto_line_column(2,8);
  lcd_print_unsigned(task2Counter);

    if (state == 0) {
      state = 1;
      IO1SET = 1 << 23;
      IO1CLR = 1 << 24;
    }
    else {
      state = 0;
      IO1CLR = 1 << 23;
      IO1SET = 1 << 24;
    }
    TerminateTask();
}
#define APP_Task_task2_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_Task_task3_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task3)
{
  task3Counter++;
  lcd_goto_line_column(3,0);
  lcd_print_string("task3");
  lcd_goto_line_column(3,6);
  lcd_print_string("-");
  lcd_goto_line_column(3,8);
  lcd_print_unsigned(task3Counter);

  TerminateTask();  
}
#define APP_Task_task3_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_ISR_isr_button1_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button1)
{
  lcd_goto_line_column(1,16);
  lcd_print_string("pressed");
}
#define APP_ISR_isr_button1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_button2_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button2)
{
  lcd_goto_line_column(2,16);
  lcd_print_string("pressed");
  CallTerminateISR2();
}
#define APP_ISR_isr_button2_STOP_SEC_CODE
#include "tpl_memmap.h"
