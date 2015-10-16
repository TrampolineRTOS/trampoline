#include "tp.h"
#include "tpl_os.h"

extern void tpl_set_systick_timer(void);

int etatLed;

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  etatLed = 0;
  
  /* Led Teensy */
  PORTC_PCR5 = (1 << 8); /* Mode GPIO - MUX = 001 */
  GPIOC_PDDR |= (1 << 5); /* 1 bit / pin */ 
  GPIOC_PCOR = (1 << 5);  
//   GPIOC_PSOR = (1 << 5);

  /* Led 0 */
  PORTA_PCR12 = (1 << 8);
  GPIOA_PDDR |= (1 << 12);
  GPIOA_PCOR = (1 << 12);
//   GPIOA_PSOR = (1 << 12);

  /* Led 1 */
  PORTA_PCR13 = (1 << 8);
  GPIOA_PDDR |= (1 << 13);
  GPIOA_PCOR = (1 << 13);
//   GPIOA_PSOR = (1 << 13);

  /* Led 2 */
  PORTD_PCR7 = (1 << 8);
  GPIOD_PDDR |= (1 << 7);
  GPIOD_PCOR = (1 << 7);
//   GPIOD_PSOR = (1 << 7);

  /* Led 3 */
  PORTD_PCR4 = (1 << 8);
  GPIOD_PDDR |= (1 << 4);
  GPIOD_PCOR = (1 << 4);
//   GPIOD_PSOR = (1 << 4);

  /* Led 4 */
  PORTD_PCR2 = (1 << 8);
  GPIOD_PDDR |= (1 << 2);
  GPIOD_PCOR = (1 << 2);
//   GPIOD_PSOR = (1 << 2);

  
//   
//    initBoard();
//   ledOn(LEDBOARD);

//  tpl_set_systick_timer();
  
 StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
  if (etatLed == 0) {
    etatLed = 1;
     GPIOC_PSOR = (1 << 5);
  } else {
    etatLed = 0;
    GPIOC_PCOR = (1 << 5);
  }

  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) PreTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
  }
}

FUNC(void, OS_CODE) PostTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
  }
}

void _init(void)
{
}

// void test_systick()
// {
//   if (etatLed == 0) {
//     etatLed = 1;
//     GPIOC_PSOR = (1 << 5);
//   } else {
//     etatLed = 0;
//     GPIOC_PCOR = (1 << 5);
//   }
// }

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

