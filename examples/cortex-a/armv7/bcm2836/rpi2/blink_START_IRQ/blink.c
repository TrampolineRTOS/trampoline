#include "tpl_os.h"

#include "emblib.h"
#include "rpi2_uart.h"

extern unsigned int GETSP ( void );
extern unsigned int GETSPIRQ ( void );
extern unsigned int GETSPSVC ( void );
extern unsigned int GETCPSR ( void );
extern unsigned int GETISR ( void );
extern unsigned int GETVBAR ( void );
extern void enable_irq ( void );

volatile unsigned int nbsvc;

#define LOCAL_ARM_TIMER_LOD 0x3F00B400
#define LOCAL_ARM_TIMER_VAL 0x3F00B404
#define LOCAL_ARM_TIMER_CTL 0x3F00B408
#define LOCAL_ARM_TIMER_CLI 0x3F00B40C
#define LOCAL_ARM_TIMER_RIS 0x3F00B410
#define LOCAL_ARM_TIMER_MIS 0x3F00B414
#define LOCAL_ARM_TIMER_RLD 0x3F00B418
#define LOCAL_ARM_TIMER_DIV 0x3F00B41C
#define LOCAL_ARM_TIMER_CNT 0x3F00B420

#define LOCAL_SYSTIMERCLO 0x3F003004
#define LOCAL_GPFSEL1 0x3F200004
#define LOCAL_GPSET0  0x3F20001C
#define LOCAL_GPCLR0  0x3F200028

#define LOCAL_GPFSEL3 0x3F20000C
#define LOCAL_GPFSEL4 0x3F200010
#define LOCAL_GPSET1  0x3F200020
#define LOCAL_GPCLR1  0x3F20002C

#define LOCAL_IRQ_BASIC 0x3F00B200
#define LOCAL_IRQ_PEND1 0x3F00B204
#define LOCAL_IRQ_PEND2 0x3F00B208
#define LOCAL_IRQ_FIQ_CONTROL 0x3F00B210
#define LOCAL_IRQ_ENABLE_BASIC 0x3F00B218
#define LOCAL_IRQ_DISABLE_BASIC 0x3F00B224

void c_undefined_handler(void) {
  uart_write_string((const unsigned char*)"UNDEFINED [");

  uart_write_string((const unsigned char*)"SP = ");
  hexstring(GETSP());
  uart_write_string((const unsigned char*)"SPIRQ = ");
  hexstring(GETSPIRQ());
  uart_write_string((const unsigned char*)"SPSVC = ");
  hexstring(GETSPSVC());
  uart_write_string((const unsigned char*)"ISR = ");
  hexstring(GETISR());
  uart_write_string((const unsigned char*)"CPSR = ");
  hexstring(GETCPSR());

  uart_write_string((const unsigned char*)"]");
  while(1);
}
void c_prefetch_handler(void) {
  uart_write_string((const unsigned char*)"PREFETCH [");

  uart_write_string((const unsigned char*)"SP = ");
  hexstring(GETSP());
  uart_write_string((const unsigned char*)"SPIRQ = ");
  hexstring(GETSPIRQ());
  uart_write_string((const unsigned char*)"SPSVC = ");
  hexstring(GETSPSVC());
  uart_write_string((const unsigned char*)"ISR = ");
  hexstring(GETISR());
  uart_write_string((const unsigned char*)"CPSR = ");
  hexstring(GETCPSR());

  uart_write_string((const unsigned char*)"]");
  while(1);
}
void c_data_handler(void) {
  uart_write_string((const unsigned char*)"DATA [");

  uart_write_string((const unsigned char*)"SP = ");
  hexstring(GETSP());
  uart_write_string((const unsigned char*)"SPIRQ = ");
  hexstring(GETSPIRQ());
  uart_write_string((const unsigned char*)"SPSVC = ");
  hexstring(GETSPSVC());
  uart_write_string((const unsigned char*)"ISR = ");
  hexstring(GETISR());
  uart_write_string((const unsigned char*)"CPSR = ");
  hexstring(GETCPSR());

  uart_write_string((const unsigned char*)"]");
  while(1);
}
void c_reserved_handler(void) {
  uart_write_string((const unsigned char*)"RESERVED [");

  uart_write_string((const unsigned char*)"SP = ");
  hexstring(GETSP());
  uart_write_string((const unsigned char*)"SPIRQ = ");
  hexstring(GETSPIRQ());
  uart_write_string((const unsigned char*)"SPSVC = ");
  hexstring(GETSPSVC());
  uart_write_string((const unsigned char*)"ISR = ");
  hexstring(GETISR());
  uart_write_string((const unsigned char*)"CPSR = ");
  hexstring(GETCPSR());

  uart_write_string((const unsigned char*)"]");
  while(1);
}
void c_fiq_handler(void) {
  uart_write_string((const unsigned char*)"FIQ [");

  uart_write_string((const unsigned char*)"SP = ");
  hexstring(GETSP());
  uart_write_string((const unsigned char*)"SPIRQ = ");
  hexstring(GETSPIRQ());
  uart_write_string((const unsigned char*)"SPSVC = ");
  hexstring(GETSPSVC());
  uart_write_string((const unsigned char*)"ISR = ");
  hexstring(GETISR());
  uart_write_string((const unsigned char*)"CPSR = ");
  hexstring(GETCPSR());

  uart_write_string((const unsigned char*)"]");
  while(1);
}

void c_irq_handler ( void )
{

  writeToReg(LOCAL_GPSET1,1<<(47-32));

  writeToReg(LOCAL_ARM_TIMER_CLI,0);
}

void c_svc_handler ( void )
{

  writeToReg(LOCAL_GPSET1,1<<(35-32));

}

void c_hang_handler ( void )
{
  uart_write_string((const unsigned char*)"HANG [");

  uart_write_string((const unsigned char*)"SP = ");
  hexstring(GETSP());
  uart_write_string((const unsigned char*)"SPIRQ = ");
  hexstring(GETSPIRQ());
  uart_write_string((const unsigned char*)"SPSVC = ");
  hexstring(GETSPSVC());
  uart_write_string((const unsigned char*)"ISR = ");
  hexstring(GETISR());
  uart_write_string((const unsigned char*)"CPSR = ");
  hexstring(GETCPSR());

  uart_write_string((const unsigned char*)"]");
  while(1);
}

#define APP_Task_blink_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  unsigned int ra;

  uart_init();

  uart_write_string((const unsigned char*)"MAIN");

  writeToReg(LOCAL_IRQ_DISABLE_BASIC,1);

  ra=readFromReg(LOCAL_GPFSEL4);
  ra&=~(7<<21);
  ra|=1<<21;
  writeToReg(LOCAL_GPFSEL4,ra);

  ra=readFromReg(LOCAL_GPFSEL3);
  ra&=~(7<<15);
  ra|=1<<15;
  writeToReg(LOCAL_GPFSEL3,ra);

  writeToReg(LOCAL_GPCLR1,1<<(47-32));
  writeToReg(LOCAL_GPCLR1,1<<(35-32));

  writeToReg(LOCAL_ARM_TIMER_CTL,0x003E0000);
  writeToReg(LOCAL_ARM_TIMER_LOD,10000-1);
  writeToReg(LOCAL_ARM_TIMER_RLD,10000-1);
  writeToReg(LOCAL_ARM_TIMER_DIV,0x000000F9);
  writeToReg(LOCAL_ARM_TIMER_CLI,0);
  writeToReg(LOCAL_IRQ_ENABLE_BASIC,1);

  enable_irq();

  uart_write_string((const unsigned char*)"SP = ");
  hexstring(GETSP());
  uart_write_string((const unsigned char*)"SPIRQ = ");
  hexstring(GETSPIRQ());
  uart_write_string((const unsigned char*)"SPSVC = ");
  hexstring(GETSPSVC());
  uart_write_string((const unsigned char*)"ISR = ");
  hexstring(GETISR());

  uart_write_string((const unsigned char*)"VBAR = ");
  hexstring(GETVBAR());

  uart_write_string((const unsigned char*)"CPSR = ");
  hexstring(GETCPSR());

  writeToReg(LOCAL_ARM_TIMER_CTL,0x003E00A2);
  writeToReg(LOCAL_ARM_TIMER_CLI,0);

  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(blink)
{
  static uint32 compte = 0;

  compte++;
  uart_write_strings((const unsigned char*)"Tache BLINK : ");
  hexstring(compte);

  TerminateTask();
}
#define APP_Task_blink_STOP_SEC_CODE
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
