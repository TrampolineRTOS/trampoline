#include "tpl_os.h"
#include "MPC5674F.h"
#include "tpl_mpc5674f_define.h"

/* Variables ---------------------------------------------------------------- */
VAR(int, OS_VAR) switch_count = 0;
VAR(TaskType, OS_VAR) new_task;
VAR(int, AUTOMATIC) titi = 0;
VAR(int, AUTOMATIC) toto = 0;


int PIT_2_ISR_count = 0;
int isr_sw_it7_count = 0;
int isr_sw_it0_count = 0;
int task_gogo_count = 0;



/* Private functions prototypes --------------------------------------------- */
static uint8_t initFMPLL(void);
FUNC(void, OS_CODE) Pit_2_ISR(void);
FUNC(void, OS_CODE) initPIT(uint8_t channel, uint32_t period);
FUNC(void, OS_CODE) PIT_2_ISR(void);
FUNC(void, OS_CODE) SW_IT_0_ISR(void);

/* OS process implementations */
TASK(solonelyfriend);
TASK(iamsolonely);
TASK(gogo);
ISR(isr_sw_it7);
FUNC(void, OS_CODE) isr_sw_it7_ack(void);


FUNC(int, OS_APPL_CODE) main(void)
{
	/* Configure PLL */
	initFMPLL();
	/* Configure pit to generate interrupt each 0,5 ms */
	initPIT(2, 500);
	
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

/* Private functions Implementations --------------------------------------- */

/**
* @brief  Initialization of system frequency
* @param  None 
* @retval None
*/

static uint8_t initFMPLL(void) {

/* F_TODO : Verify the configuration below */
#if defined (CORE_CLOCK_264MHZ)
	FMPLL.ESYNCR2.R = 0x00000002;
	FMPLL.ESYNCR1.R = 0x70040032;																
    while (FMPLL.SYNSR.B.LOCK != 1) {}; 	/* Wait for FMPLL to LOCK  */								
    FMPLL.ESYNCR2.R = 0x00000001;           /* Fsys =264Mhz */
    return 0;

#elif defined (CORE_CLOCK_260MHZ)
    FMPLL.ESYNCR2.R = 0x00000001;   		/* EFRD = 1 "ESYNCR2[26..31]" */
    FMPLL.ESYNCR1.R = 0xF001000A;   		/* EMFD = 0x0A "ESYNCR1[24..31]", EPREDIV = 0x01 "ESYNCR1[12..15]" */  
    while (FMPLL.SYNSR.B.LOCK != 1) {};		/* Wait until lock bit = 1 (PLL is locked) */
    SIU.SYSDIV.R = 0x00000010;      		/* Bypass of SIU_SYSDIV is set to 1 "SIU_SYSDIV[27]" */
    return 0;

/* F_TODO : Verify the configuration below */    
#elif defined (CORE_CLOCK_200MHZ)
    FMPLL.ESYNCR2.R = 0x00000002;								
    FMPLL.ESYNCR1.R = 0x70040022;								
    while (FMPLL.SYNSR.B.LOCK != 1) {}; 	/* Wait for FMPLL to LOCK */								
    FMPLL.ESYNCR2.R = 0x00000001;           /* Fsys =200Mhz */
    return 0;

/* F_TODO : Verify the configuration below */
#elif defined (CORE_CLOCK_150MHz)
    FMPLL.ESYNCR2.R = 0x00000005;								
    FMPLL.ESYNCR1.R = 0x7003002C;								
    while (FMPLL.SYNSR.B.LOCK != 1) {}; 	/* Wait for FMPLL to LOCK */								
    FMPLL.ESYNCR2.R = 0x00000003;           /* Fsys =150Mhz */
    return 0;
    /* configuration verified based on F_crystal=8MHZ */
#elif defined (CORE_CLOCK_132MHZ)
    FMPLL.ESYNCR2.R = 0x00000001;								
    FMPLL.ESYNCR1.R = 0x70010032;								
    while (FMPLL.SYNSR.B.LOCK != 1) {}; 	/* Wait for FMPLL to LOCK */								
    FMPLL.ESYNCR2.R = 0x00000001;           /* Fsys =132Mhz */
    return 0;
        
#else
    return 1;
    
#endif
}

/**
* @brief  Init PIT peripheral 
* @param  channel [0..4]
* @param  period of the timer (in microseconds)
* @retval None
*/
FUNC(void, OS_CODE) initPIT(uint8_t channel, uint32_t period)
{	
	/* turn on PIT */
	PIT.MCR.R = 0x00;
	
	PIT.CH[channel].TCTRL.B.TEN = 0;    					/* disable timer 1 */
	PIT.CH[channel].LDVAL.R = (period*PERIPH_FREQ)/1000;  	/* set the load value to generate the period tick */
	PIT.CH[channel].TCTRL.B.TIE = 1;   						/* enable Timer 1 interrupts */
	PIT.CH[channel].TCTRL.B.TEN = 1;    					/* start timer 1 */
}

/* OS process Implementations ----------------------------------------------- */

TASK(solonelyfriend)
{
  titi = 1;
  titi = toto;
  toto += 5;
  while(1) {}
  TerminateTask();
}

TASK(iamsolonely)
{
  titi = 1;
  titi = toto;
  toto += 3;
  ActivateTask(solonelyfriend);
  TerminateTask();
}

TASK(gogo)
{	
  static char led_state = 0;
  led_state = !led_state;
  toto += 1;
  task_gogo_count++;
  TerminateTask();
}

ISR(isr_sw_it7)
{
  toto += 20;
  if (isr_sw_it0_count - isr_sw_it7_count > 1)
  {
  	  isr_sw_it7_count = 0;
  }
  isr_sw_it7_count++;
  CallTerminateISR2();
}

FUNC(void, OS_CODE) isr_sw_it7_ack(void)
{   
  INTC.SSCIR[7].R = 1;			/* clear the software interrupt flag */
}

FUNC(void, OS_CODE) PIT_2_ISR(void)
{
  static uint8_t select_sw_it = 1;
	
  if(select_sw_it > 0) 
  {
	  INTC.SSCIR[0].R = 2;	 	 /* Activate the software interrupt 0 (ISR1 in the application example) */
	  select_sw_it -= 1;
  }
  else
  {
	  INTC.SSCIR[7].R = 2;	 	 /* Activate the software interrupt 7 (ISR2 in the application example) */
	  select_sw_it += 1;
  }
  
  PIT_2_ISR_count++;
  
  PIT.CH[2].TFLG.B.TIF = 1;  /* Clear the PIT channel 2 interrupt flag */
}

FUNC(void, OS_CODE) SW_IT_0_ISR(void)
{
  toto += 20;  
  isr_sw_it0_count++;
  INTC.SSCIR[0].R = 1;	 	 /* Activate the software interrupt 0 */
}
