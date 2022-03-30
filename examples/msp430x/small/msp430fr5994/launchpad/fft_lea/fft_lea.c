#include "tpl_os.h"
#include "msp430.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include "tpl_clocks.h"

/* Input signal parameters */
#define FS                  8192
#define SAMPLES             256
#define SIGNAL_FREQUENCY1   200
#define SIGNAL_AMPLITUDE1   0.6

/* Constants */
#define PI                  3.1415926536

#define APP_Task_fft_START_SEC_LEA_VAR_LEA_16BIT
#include "tpl_memmap.h"

VAR(_q15, AUTOMATIC) input[SAMPLES];

#define APP_Task_fft_STOP_SEC_LEA_VAR_LEA_16BIT
#include "tpl_memmap.h"

/* Function prototypes */
extern void initSignal(void);

#define APP_Task_fft_START_SEC_CODE
#include "tpl_memmap.h"


/*----------------------------------------------------------------------------*/
/* main function                                                              */
/*----------------------------------------------------------------------------*/
FUNC(int, OS_APPL_CODE) main(void)
{
  /* Disable WDT */	
  WDTCTL = WDTPW + WDTHOLD;
  
  P1DIR |= BIT0 + BIT1;
  P1OUT &= ~BIT0;
  P1OUT &= ~BIT1;
  
  PM5CTL0 &= ~LOCKLPM5;
  	
  tpl_serial_begin();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

void initSignal(void){
	msp_status status;
	msp_sinusoid_q15_params sinParams;
    /* Generate Q15 input signal */
    sinParams.length = SAMPLES;
    sinParams.amplitude = _Q15(SIGNAL_AMPLITUDE1);
    sinParams.cosOmega = _Q15(cosf(2*PI*SIGNAL_FREQUENCY1/FS));
    sinParams.sinOmega = _Q15(sinf(2*PI*SIGNAL_FREQUENCY1/FS));
    status = msp_sinusoid_q15(&sinParams, input);
    msp_checkStatus(status);
}
	
//#define APP_COMMON_STOP_SEC_CODE
//#include "tpl_memmap.h"

//#define APP_Task_fft_START_SEC_CODE
//#include "tpl_memmap.h"
/*----------------------------------------------------------------------------*/
/* TASK fft                                                             */
/*----------------------------------------------------------------------------*/
TASK(fft)
{
	P1OUT |= BIT0;
    msp_status status;
    msp_fft_q15_params fftParams;
    int i;
    
    initSignal();
    
    for(i=0; i<SAMPLES; i++){
		tpl_serial_print_int(input[i], 0);
		tpl_serial_print_string("\n");
	}
    /* Initialize the fft parameter structure. */
    fftParams.length = SAMPLES;
    fftParams.bitReverse = true;
    fftParams.twiddleTable = MAP_msp_cmplx_twiddle_table_2048_q15;
    
    status = MAP_msp_fft_fixed_q15(&fftParams, input);
    msp_checkStatus(status);
    for(i=0; i<SAMPLES; i++){
		tpl_serial_print_int(input[i], 0);
		tpl_serial_print_string("\n");
	}
	P1OUT |= BIT1;   	
	TerminateTask();
}
#define APP_Task_fft_STOP_SEC_CODE
#include "tpl_memmap.h"


