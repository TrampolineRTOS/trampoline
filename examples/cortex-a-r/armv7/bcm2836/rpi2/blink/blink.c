#include "tpl_os.h"

#include "bcm2836.h"
#include "emblib.h"
#include "rpi2_uart.h"
#include "rpi2_timer.h"
#include "rpi2_trace.h"

volatile unsigned int nbsvc;
extern unsigned int __SP_irq_bot_ ;
extern unsigned int __SP_irq_top_;
extern unsigned int __SP_svc_bot_;
extern unsigned int __SP_svc_top_;
extern unsigned int __SP_usr_bot_;
extern unsigned int __SP_usr_top_;

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void) {
  unsigned int ra;

  uart_init();

  uart_write_string((const unsigned char*)"MAIN");

  ra=readFromReg(GPFSEL4);
  ra&=~(7<<21);
  ra|=1<<21;
  writeToReg(GPFSEL4,ra);

  ra=readFromReg(GPFSEL3);
  ra&=~(7<<15);
  ra|=1<<15;
  writeToReg(GPFSEL3,ra);

  ra=readFromReg(GPFSEL2);
  ra&=~(7<<3);
  ra|=1<<3;
  writeToReg(GPFSEL2,ra);

  writeToReg(GPCLR1,1<<(47-32));
  writeToReg(GPCLR1,1<<(35-32));
  writeToReg(GPCLR0,1<<21);

  /* Setup the system timer interrupt
   * Timer frequency = Clk/250 * 1000
   * PreDivider = 249
   * timer_clock = apb_clock / (PreDivider + 1) = 250MHz / (249 + 1) = 1MHz
   * Load value is 1000 so that the ARM timer raises an IRQ every 1ms
   * 
   */
  RPI_GetArmTimer()->Load = 1000;
  /* Setup the ARM Timer */
  RPI_GetArmTimer()->Control = ARM_TIMER_CTRL_23BIT
                             | ARM_TIMER_CTRL_ENABLE
                             | ARM_TIMER_CTRL_INT_ENABLE
                             | ARM_TIMER_CTRL_PRESCALE_1;
  RPI_GetArmTimer()->PreDivider = 0x000000F9;

  writeToReg(IRQ_ENABLE_BASIC,1);

  enable_irq();

  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink) {
  static uint32 compte = 0;

  compte++;
  uart_write_strings((const unsigned char*)"Tache BLINK : ");
  hexstring(compte);

  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_stacks_START_SEC_CODE
#include "tpl_memmap.h"
TASK(stacks)
{
  uint32 botAddr;
  uint32 topAddr;
  uint32 sp_irq_value;
  uint32 sp_svc_value;
  uint32 sp_usr_value;

  uart_write_string((const unsigned char*)"Tache STACKS");

  __asm volatile ("mrs %0, SP_irq" : "=r" (sp_irq_value));
  __asm volatile ("mrs %0, SP_svc" : "=r" (sp_svc_value));
  __asm volatile ("mov %0, sp" : "=r" (sp_usr_value));

  if ( (sp_irq_value < (uint32)&__SP_irq_bot_) || (sp_irq_value > (uint32)&__SP_irq_top_) ) {
    uart_write_string((const unsigned char*)"SP_irq : ");
    hexstrings((uint32)&__SP_irq_bot_);
    uart_write_strings((const unsigned char*)" | ");
    hexstrings(sp_irq_value);
    uart_write_strings((const unsigned char*)" | ");
    hexstrings((uint32)&__SP_irq_top_);
    uart_write_char((unsigned char)0x0D);
    uart_write_char((unsigned char)0x0A);
  }

  if ( (sp_svc_value < (uint32)&__SP_svc_bot_) || (sp_svc_value > (uint32)&__SP_svc_top_) ) {
    uart_write_string((const unsigned char*)"SP_svc : ");
    hexstrings((uint32)&__SP_svc_bot_);
    uart_write_strings((const unsigned char*)" | ");
    hexstrings(sp_svc_value);
    uart_write_strings((const unsigned char*)" | ");
    hexstrings((uint32)&__SP_svc_top_);
    uart_write_char((unsigned char)0x0D);
    uart_write_char((unsigned char)0x0A);
  }

  // if ( (sp_usr_value < (uint32)&__SP_usr_bot_) || (sp_usr_value > (uint32)&__SP_usr_top_) ) {
  //   uart_write_string((const unsigned char*)"SP_usr : ");
  //   hexstrings((uint32)&__SP_usr_bot_);
  //   uart_write_strings((const unsigned char*)" | ");
  //   hexstrings(sp_usr_value);
  //   uart_write_strings((const unsigned char*)" | ");
  //   hexstrings((uint32)&__SP_usr_top_);
  //   uart_write_char((unsigned char)0x0D);
  //   uart_write_char((unsigned char)0x0A);
  // }

  TerminateTask();
}
#define APP_Task_stacks_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8* file, uint32 line)
{
}

FUNC(void, OS_CODE) PreTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    // ledOn(ORANGE);
  }
}

FUNC(void, OS_CODE) PostTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    // ledOff(ORANGE);
  }
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
