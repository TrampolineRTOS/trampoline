/* Libraries */

#include "tpl_os.h"
#include "lpc22xx.h"
#include "tp_ecn.h"
#include "extint.h"

/* Main */

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  /* io description for external interrupts
   *
   * EINT0 - VIC[14] - P0.1 - P0.16
   * EINT1 - VIC[15] - P0.3 - P0.14
   * EINT2 - VIC[16] - P0.7 - P0.15
   * EINT3 - VIC[17] - P0.9 - P0.20 - P0.30
   */
  /* BUT - EINT0 - P0.16 = 01 */
//  PINSEL1 |= (1 << 0);
//  PINSEL1 |= (0 << 1);
  /* EINT1 - P0.1 = 11 */
  InitExtInt();
  
  /* set io pins for led STAT on the mother board */
  IO1DIR |= (1 << 23);
  IO1SET =  1 << 23; // led off
  IO1CLR =  1 << 23; // led on
  /* set io pins for led D9 on daughter board */
  IO1DIR |= (1 << 20);
  IO1CLR =  1 << 20; // led off
  IO1SET =  1 << 20; // led on
  /* set io pins for led D7 on daughter board */
  IO1DIR |= (1 << 21);
  IO1CLR =  1 << 21; // led off
  IO1SET =  1 << 21; // led on
  /* set io pins for led D8 on daughter board */
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

#define APP_ISR_isr_button1_START_SEC_CODE
#include "tpl_memmap.h"
VAR(uint32, AUTOMATIC) isr1counter = 0;
#define APP_ISR_isr_button1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_button2_START_SEC_CODE
#include "tpl_memmap.h"
VAR(uint32, AUTOMATIC) isr2counter = 0;
#define APP_ISR_isr_button2_STOP_SEC_CODE
#include "tpl_memmap.h"

/* Application */

DeclareTask(task1);
DeclareTask(task2);
DeclareTask(task3);
DeclareResource(lcd_resource);

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
  GetResource(lcd_resource);
  lcd_goto_line_column(1,0);
  lcd_print_string("T1 - ");
  lcd_goto_line_column(1,5);
  lcd_print_unsigned(task1Counter);
  ReleaseResource(lcd_resource);
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
  GetResource(lcd_resource);
  lcd_goto_line_column(2,0);
  lcd_print_string("T2 - ");
  lcd_goto_line_column(2,5);
  lcd_print_unsigned(task2Counter);
  ReleaseResource(lcd_resource);

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
  GetResource(lcd_resource);
  lcd_goto_line_column(3,0);
  lcd_print_string("T3 - ");
  lcd_goto_line_column(3,5);
  lcd_print_unsigned(task3Counter);
  ReleaseResource(lcd_resource);

  TerminateTask();  
}
#define APP_Task_task3_STOP_SEC_CODE
#include "tpl_memmap.h"


#define APP_ISR_isr_button1_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button1)
{
  isr1counter++;
  GetResource(lcd_resource);
  lcd_goto_line_column(1,12);
  lcd_print_string("B1 - ");
  lcd_goto_line_column(1,17);
  lcd_print_unsigned(isr1counter);
  ReleaseResource(lcd_resource);
  
  /* If isr_button1 is an ISR 2 then de comment the line hereafter */
  //CallTerminateISR2();
}
#define APP_ISR_isr_button1_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_ISR_isr_button2_START_SEC_CODE
#include "tpl_memmap.h"
ISR(isr_button2)
{
  isr2counter++;
  GetResource(lcd_resource);
  lcd_goto_line_column(2,12);
  lcd_print_string("B2 - ");
  lcd_goto_line_column(2,17);
  lcd_print_unsigned(0);
  ReleaseResource(lcd_resource);

  CallTerminateISR2();
}
#define APP_ISR_isr_button2_STOP_SEC_CODE
#include "tpl_memmap.h"
