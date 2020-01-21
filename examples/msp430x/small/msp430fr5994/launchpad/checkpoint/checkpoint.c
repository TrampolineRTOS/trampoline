#include "tpl_os.h"
#include "msp430.h"
#include <stdint.h>
#include "tpl_clocks.h"

/* Warning, task data outside of POWER_ON_INIT section won't be initialized */
#define APP_Task_task_serial_TX_START_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"
VAR(uint32_t,AUTOMATIC) dataSRAM = 100;
VAR(uint16_t,AUTOMATIC) adc_conv_ready = 0;
#define APP_Task_task_serial_TX_STOP_SEC_VAR_POWER_ON_INIT_32BIT
#include "tpl_memmap.h"

/* At this date, NON_VOLATILE data is initialized only when flashing firmware */
#define APP_Task_task_serial_TX_START_SEC_VAR_NON_VOLATILE_32BIT
#include "tpl_memmap.h"
VAR(uint32_t,AUTOMATIC) dataFRAM = 100;
#define APP_Task_task_serial_TX_STOP_SEC_VAR_NON_VOLATILE_32BIT
#include "tpl_memmap.h"


#define APP_COMMON_START_SEC_CODE
#include "tpl_memmap.h"

extern void framUpWrite8(const uint16 address, const uint8 data);
extern void framUpWrite16(const uint16 address, const uint16 data);
extern uint8 framUpRead8(const uint16 address);
extern uint16 framUpRead16(const uint16 address);
extern void tpl_save_checkpoint(const uint16 buffer);
extern void tpl_load_checkpoint(const uint16 buffer);

/*----------------------------------------------------------------------------*/
/* io_init                                                                    */
/*----------------------------------------------------------------------------*/
/*
 * init some I/Os of the board:
 * - red   LED1  on P1.0
 * - green LED2  on P1.1
 * - S1 user button on P5.6
 */
FUNC(void, OS_APPL_CODE) io_init()
{
  /*
   * Disable the GPIO power-on default high-impedance mode
   * to activate previously configured port settings
   */
  PM5CTL0 &= ~LOCKLPM5;

  /* set GPIO P1.0 and 1.1 (red LED1 and green LED2) as an output */
  P1DIR |= 0x03;
  P1OUT &= ~1; /* red led off */
  P1OUT &= ~2; /* green led off */

  /* set GPIO P5.5 (button S2) as an input, with internal pull-up */
  P5DIR &= ~(1<<5); /* input                                      */
  P5REN |= 1<<5;    /* pull-up/down resistor enable               */
  P5OUT |= 1<<5;    /* pull-up                                    */
  P5IES &= ~(0<<5); /* low to high interrupt edge selection       */
  //  P5IE  |= 1<<5;    /* interrupt enabled for the button           */

  /* set GPIO P5.6 (button S1) as an input, with internal pull-up */
  P5DIR &= ~(1<<6); /* input                                      */
  P5REN |= 1<<6;    /* pull-up/down resistor enable               */
  P5OUT |= 1<<6;    /* pull-up                                    */
  P5IES &= ~(0<<6); /* low to high interrupt edge selection       */
  //  P5IE  |= 1<<6;    /* interrupt enabled for the button           */
}

/*----------------------------------------------------------------------------*/
/* tpl_adc_init                                                               */
/*----------------------------------------------------------------------------*/
FUNC(void, OS_APPL_CODE) tpl_adc_init(void)
{
	//Initialize the ADC12B Module
  /*
   * Base address of ADC12B Module
   * Use internal ADC12B bit as sample/hold signal to start conversion
   * USE MODOSC 5MHZ Digital Oscillator as clock source
   * Use default clock divider/pre-divider of 1
   * Use Battery monitor and Battery Monitor internal channels
   */
  ADC12_B_initParam initParam;
  initParam.sampleHoldSignalSourceSelect = ADC12_B_SAMPLEHOLDSOURCE_SC;
  initParam.clockSourceSelect            = ADC12_B_CLOCKSOURCE_ACLK;
  initParam.clockSourceDivider           = ADC12_B_CLOCKDIVIDER_1;
  initParam.clockSourcePredivider        = ADC12_B_CLOCKPREDIVIDER__1;
  initParam.internalChannelMap           = ADC12_B_TEMPSENSEMAP;
  //  initParam.internalChannelMap           = ADC12_B_BATTMAP;
  ADC12_B_init(ADC12_B_BASE, &initParam);

  // Enable the ADC12B module
  ADC12_B_enable(ADC12_B_BASE);

  // Sets up the sampling timer pulse mode
  ADC12_B_setupSamplingTimer(ADC12_B_BASE,
                             ADC12_B_CYCLEHOLD_128_CYCLES,
                             ADC12_B_CYCLEHOLD_128_CYCLES,
                             ADC12_B_MULTIPLESAMPLESDISABLE);

  // Maps Temperature Sensor input channel to Memory 0 and select voltage references
  /*
   * Base address of the ADC12B Module
   * Configure memory buffer 0
   * Map input A1 to memory buffer 0
   * Vref+ = IntBuffer
   * Vref- = AVss
   * Memory buffer 0 is not the end of a sequence
   */
  ADC12_B_configureMemoryParam configureMemoryParam;
  configureMemoryParam.memoryBufferControlIndex = ADC12_B_MEMORY_0;
  configureMemoryParam.inputSourceSelect        = ADC12_B_INPUT_TCMAP;
  //  configureMemoryParam.inputSourceSelect        = ADC12_B_INPUT_BATMAP;
  configureMemoryParam.refVoltageSourceSelect   = ADC12_B_VREFPOS_INTBUF_VREFNEG_VSS;
  configureMemoryParam.endOfSequence            = ADC12_B_NOTENDOFSEQUENCE;
  configureMemoryParam.windowComparatorSelect   = ADC12_B_WINDOW_COMPARATOR_DISABLE;
  configureMemoryParam.differentialModeSelect   = ADC12_B_DIFFERENTIAL_MODE_DISABLE;
  ADC12_B_configureMemory(ADC12_B_BASE, &configureMemoryParam);

  // Clear memory buffer 0 interrupt
  ADC12_B_clearInterrupt(ADC12_B_BASE,
                         0,
                         ADC12_B_IFG0
                         );

  // Enable memory buffer 0 interrupt
  ADC12_B_enableInterrupt(ADC12_B_BASE,
                          ADC12_B_IE0,
                          0,
                          0);

  // Configure internal reference
  while(Ref_A_isRefGenBusy(REF_A_BASE));              // If ref generator busy, WAIT
  Ref_A_enableTempSensor(REF_A_BASE);
  Ref_A_setReferenceVoltage(REF_A_BASE, REF_A_VREF2_0V);
  Ref_A_enableReferenceVoltage(REF_A_BASE);
}

uint16 readPowerVoltage(void)
{
  // mesure tension
  //Enable/Start sampling and conversion
  /*
   * Base address of ADC12B Module
   * Start the conversion into memory buffer 0
   * Use the single-channel, single-conversion mode
   */
  ADC12_B_startConversion(ADC12_B_BASE,
                          ADC12_B_MEMORY_0,
                          ADC12_B_SINGLECHANNEL);

  while(adc_conv_ready != 1);
  adc_conv_ready = 0;

  return ADC12_B_getResults(ADC12_B_BASE, ADC12_B_MEMORY_0);
}

/*----------------------------------------------------------------------------*/
/* main function                                                              */
/*----------------------------------------------------------------------------*/
FUNC(int, OS_APPL_CODE) main(void)
{
  io_init();
	tpl_serial_begin();
  tpl_adc_init();

	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

/*----------------------------------------------------------------------------*/
/* function called for a restart                                              */
/* it initializes peripherals                                                 */
/*----------------------------------------------------------------------------*/
FUNC(int, OS_APPL_CODE) restart_main(void)
{
  io_init();
	tpl_serial_begin();
  tpl_adc_init();

	RestartOS();
	return 0;
}

#define APP_COMMON_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_serial_TX_START_SEC_CODE
#include "tpl_memmap.h"
/*----------------------------------------------------------------------------*/
/* TASK serial_TX                                                             */
/*----------------------------------------------------------------------------*/
TASK(task_serial_TX)
{
  //	tpl_serial_print_string("data in SRAM :");
  //	tpl_serial_print_int(dataSRAM,0);
  //	tpl_serial_print_string("\r\n");

  //	tpl_serial_print_string("data in FRAM :");
  //	tpl_serial_print_int(dataFRAM,0);
  //	tpl_serial_print_string("\r\n");

  //	dataSRAM++;
  //	dataFRAM++;
	TerminateTask();
}
#define APP_Task_task_serial_TX_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_task_check_button_START_SEC_CODE
#include "tpl_memmap.h"
/*----------------------------------------------------------------------------*/
/* TASK check button S2                                                       */
/*----------------------------------------------------------------------------*/
TASK(task_check_button)
{
  if(((P5IN >> 5) & 1) == 0) { //button S2 pushed ?
    tpl_serial_print_string("\r\n");
    tpl_serial_print_string("Hibernate");
    Hibernate();
  }

	TerminateTask();
}
#define APP_Task_task_check_button_STOP_SEC_CODE
#include "tpl_memmap.h"

/*----------------------------------------------------------------------------*/
/* TASK checkpoint                                                            */
/*----------------------------------------------------------------------------*/
#define APP_Task_task_energy_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_energy)
{
  uint16 vccRaw;
  //  uint16 vccThresholdRaw;

  vccRaw = readPowerVoltage();

  /*	tpl_serial_print_string("\r\n");
  tpl_serial_print_string("vccRaw = ");
  tpl_serial_print_int(vccRaw,0);
	tpl_serial_print_string("\r\n");
  tpl_serial_print_string("vccPhy = ");*/
#define HIBERNATE_THRESHOLD_RAW (900)
  if (vccRaw < HIBERNATE_THRESHOLD_RAW) {
    //    Hibernate();
  } else {
    TerminateTask ();
  }
  /* On ne doit jamais exécuter la ligne suivante */
  TerminateTask ();
}
#define APP_Task_task_energy_STOP_SEC_CODE
#include "tpl_memmap.h"

/*----------------------------------------------------------------------------*/
/* TASK fibo                                                                  */
/*----------------------------------------------------------------------------*/
#define APP_Task_task_fibo_START_SEC_CODE
#include "tpl_memmap.h"
TASK(task_fibo)
{
  static uint16 l_value_ind_0 = 0;
  static uint16 l_value_ind_1 = 1;
  uint16 l_temp;

  /* Print last value of fibo */
  tpl_serial_print_string("\r\n");
  tpl_serial_print_string("fibo :");
  tpl_serial_print_int(l_value_ind_0,0);

  /* Compute next value of fibo */
  if (l_value_ind_0 > 28000) {
    /* No overflow, restart fibo */
    l_value_ind_0 = 0;
    l_value_ind_1 = 1;
  } else {
    /* compute fibo */
    l_temp = l_value_ind_0 + l_value_ind_1;
    l_value_ind_0 = l_value_ind_1;
    l_value_ind_1 = l_temp;
  }

	TerminateTask();
}
#define APP_Task_task_serial_TX_STOP_SEC_CODE
#include "tpl_memmap.h"

/*----------------------------------------------------------------------------*/
/* ISR ADC12                                                                  */
/*----------------------------------------------------------------------------*/
#define APP_ISR_handler_adc_end_conversion_START_SEC_CODE
#include "tpl_memmap.h"
ISR(handler_adc_end_conversion)
{
  adc_conv_ready = 1;
  ADC12_B_clearInterrupt(ADC12_B_BASE, 0, ADC12_B_IFG0);
}
#define APP_ISR_handler_adc_end_conversion_STOP_SEC_CODE
#include "tpl_memmap.h"
