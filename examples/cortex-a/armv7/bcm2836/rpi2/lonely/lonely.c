/* Libraries */

#include "tpl_os.h"

/* Main */

extern void PUT32 ( unsigned int, unsigned int );
extern unsigned int GET32 ( unsigned int );
extern void dummy ( unsigned int );

extern void uart_init ( void );
extern unsigned int uart_lcr ( void );
extern void uart_flush ( void );
extern void uart_send ( unsigned int );
extern unsigned int uart_recv ( void );
extern unsigned int uart_check ( void );
extern void hexstring ( unsigned int );
void leds_off ( void );

#define PBASE 0x3F000000

#define SYSTIMERCLO 0x3F003004
#define GPFSEL3 0x3F20000C
#define GPFSEL4 0x3F200010
#define GPSET1  0x3F200020
#define GPCLR1  0x3F20002C

#define ARM_TIMER_CTL   (PBASE+0x0000B408)
#define ARM_TIMER_CNT   (PBASE+0x0000B420)

#define GPFSEL1         (PBASE+0x00200004)
#define GPSET0          (PBASE+0x0020001C)
#define GPCLR0          (PBASE+0x00200028)
#define GPPUD           (PBASE+0x00200094)
#define GPPUDCLK0       (PBASE+0x00200098)

#define AUX_ENABLES     (PBASE+0x00215004)
#define AUX_MU_IO_REG   (PBASE+0x00215040)
#define AUX_MU_IER_REG  (PBASE+0x00215044)
#define AUX_MU_IIR_REG  (PBASE+0x00215048)
#define AUX_MU_LCR_REG  (PBASE+0x0021504C)
#define AUX_MU_MCR_REG  (PBASE+0x00215050)
#define AUX_MU_LSR_REG  (PBASE+0x00215054)
#define AUX_MU_MSR_REG  (PBASE+0x00215058)
#define AUX_MU_SCRATCH  (PBASE+0x0021505C)
#define AUX_MU_CNTL_REG (PBASE+0x00215060)
#define AUX_MU_STAT_REG (PBASE+0x00215064)
#define AUX_MU_BAUD_REG (PBASE+0x00215068)

//0x01000000 17 seconds
//0x00400000 4 seconds
//#define TIMER_BIT 0x01000000
#define TIMER_BIT 0x00400000

#define GPSET1  0x3F200020
#define GPCLR1  0x3F20002C
#define GPFSEL3 0x3F20000C
#define GPFSEL4 0x3F200010

void hexstrings ( unsigned int d )
{
    //unsigned int ra;
    unsigned int rb;
    unsigned int rc;

    rb=32;
    while(1)
    {
        rb-=4;
        rc=(d>>rb)&0xF;
        if(rc>9) rc+=0x37; else rc+=0x30;
        uart_send(rc);
        if(rb==0) break;
    }
    uart_send(0x20);
}
//------------------------------------------------------------------------
void hexstring ( unsigned int d )
{
    hexstrings(d);
    uart_send(0x0D);
    uart_send(0x0A);
}

void uart_init ( void )
{
    unsigned int ra;

    PUT32(AUX_ENABLES,1);
    PUT32(AUX_MU_IER_REG,0);
    PUT32(AUX_MU_CNTL_REG,0);
    PUT32(AUX_MU_LCR_REG,3);
    PUT32(AUX_MU_MCR_REG,0);
    PUT32(AUX_MU_IER_REG,0);
    PUT32(AUX_MU_IIR_REG,0xC6);
    PUT32(AUX_MU_BAUD_REG,270);
    ra=GET32(GPFSEL1);
    ra&=~(7<<12); //gpio14
    ra|=2<<12;    //alt5
    ra&=~(7<<15); //gpio15
    ra|=2<<15;    //alt5
    PUT32(GPFSEL1,ra);
    PUT32(GPPUD,0);
    for(ra=0;ra<150;ra++) dummy(ra);
    PUT32(GPPUDCLK0,(1<<14)|(1<<15));
    for(ra=0;ra<150;ra++) dummy(ra);
    PUT32(GPPUDCLK0,0);
    PUT32(AUX_MU_CNTL_REG,3);
}

void uart_send ( unsigned int c )
{
    while(1)
    {
        if(GET32(AUX_MU_LSR_REG)&0x20) break;
    }
    PUT32(AUX_MU_IO_REG,c);
}

void init_gpio(void) {
    /* LEDs */
  unsigned int ra;

  ra=GET32(GPFSEL4);
  ra&=~(7<<21);
  ra|=1<<21;
  PUT32(GPFSEL4,ra);

  ra=GET32(GPFSEL3);
  ra&=~(7<<15);
  ra|=1<<15;
  PUT32(GPFSEL3,ra);
}

void leds_off (void) {
  PUT32(GPCLR1,1<<(47-32));
  PUT32(GPCLR1,1<<(35-32));
}

void leds_on (void) {
  PUT32(GPSET1,1<<(47-32));
  PUT32(GPSET1,1<<(35-32));
}

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  unsigned int ra;

  leds_off();
  uart_init();
  leds_on();
  hexstring(0x12345678);

  ra=GET32(GPFSEL4);
  ra&=~(7<<21);
  ra|=1<<21;
  PUT32(GPFSEL4,ra);

  ra=GET32(GPFSEL3);
  ra&=~(7<<15);
  ra|=1<<15;
  PUT32(GPFSEL3,ra);

  while(1)
  {
    PUT32(GPSET1,1<<(47-32));
    PUT32(GPCLR1,1<<(35-32));
    while(1)
    {
        ra=GET32(SYSTIMERCLO);
        if((ra&=TIMER_BIT)==TIMER_BIT) break;
    }
    PUT32(GPCLR1,1<<(47-32));
    PUT32(GPSET1,1<<(35-32));
    while(1)
    {
        ra=GET32(SYSTIMERCLO);
        if((ra&=TIMER_BIT)==0) break;
    }
  }

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
  // InitExtInt();

  /* set io pins for led STAT on the mother board */
  // IO1DIR |= (1 << 23);
  // IO1SET =  1 << 23; // led off
  // IO1CLR =  1 << 23; // led on
  // /* set io pins for led D9 on daughter board */
  // IO1DIR |= (1 << 20);
  // IO1CLR =  1 << 20; // led off
  // IO1SET =  1 << 20; // led on
  // /* set io pins for led D7 on daughter board */
  // IO1DIR |= (1 << 21);
  // IO1CLR =  1 << 21; // led off
  // IO1SET =  1 << 21; // led on
  // /* set io pins for led D8 on daughter board */
  // IO1DIR |= (1 << 22);
  // IO1CLR =  1 << 22; // led off
  // IO1SET =  1 << 22; // led on
  // /* set io pins for led D6 on daughter board -  */
  // IO1DIR |= (1 << 24);
  // IO1CLR =  1 << 24; // led off
  // IO1SET =  1 << 24; // led on
  //
  // open_serial_1(19200);
  // lcd_init();
  // lcd_print_string("Trampoline");

//  StartOS(OSDEFAULTAPPMODE);
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
  // lcd_goto_line_column(1,0);
  // lcd_print_string("T1 - ");
  // lcd_goto_line_column(1,5);
  // lcd_print_unsigned(task1Counter);
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
  // lcd_goto_line_column(2,0);
  // lcd_print_string("T2 - ");
  // lcd_goto_line_column(2,5);
  // lcd_print_unsigned(task2Counter);
  ReleaseResource(lcd_resource);

    if (state == 0) {
      state = 1;
      // IO1SET = 1 << 23;
      // IO1CLR = 1 << 24;
    }
    else {
      state = 0;
      // IO1CLR = 1 << 23;
      // IO1SET = 1 << 24;
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
  // lcd_goto_line_column(3,0);
  // lcd_print_string("T3 - ");
  // lcd_goto_line_column(3,5);
  // lcd_print_unsigned(task3Counter);
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
  // lcd_goto_line_column(1,12);
  // lcd_print_string("B1 - ");
  // lcd_goto_line_column(1,17);
  // lcd_print_unsigned(isr1counter);
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
  // lcd_goto_line_column(2,12);
  // lcd_print_string("B2 - ");
  // lcd_goto_line_column(2,17);
  // lcd_print_unsigned(0);
  ReleaseResource(lcd_resource);

  CallTerminateISR2();
}
#define APP_ISR_isr_button2_STOP_SEC_CODE
#include "tpl_memmap.h"
