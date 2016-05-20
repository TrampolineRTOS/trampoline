/*
 * tpl_mpc5674f_define.h
 *
 *  Created on: Aug 13, 2015
 *      Author: mf.sassi
 */

#ifndef TPL_MPC5674F_DEFINE_H_
#define TPL_MPC5674F_DEFINE_H_


/* Select one core clock define from the list below and comment others */ 
#define CORE_CLOCK_132MHZ
//#define CORE_CLOCK_260MHZ		
//#define CORE_CLOCK_200MHZ
//#define CORE_CLOCK_150MHZ

/* Define the Peripheral frequency depending on core clock (set in Khz as unit) */
#if defined (CORE_CLOCK_260MHZ)
#define PERIPH_FREQ		130000
#elif defined (CORE_CLOCK_200MHZ)
#define PERIPH_FREQ		100000
#elif defined (CORE_CLOCK_150MHZ)
#define PERIPH_FREQ		75000
#elif defined (CORE_CLOCK_132MHZ)
#define PERIPH_FREQ		66000
#endif

/*
 * The two defines below are used in tpl_init_term.c file:
 * In our case we use PIT as tick source. The value of TPL_TICK_TIMER corresponds to channel that
 * will be used (0,1,2,3). For using Decrementer as source tick, TPL_TICK_TIMER should be set to 20  
 */
#define TPL_TICK_TIMER          0
#define TPL_DECREMENTER         20


#define OS_TICK_PERIOD        	1000  	   						   /* OS tick of 1 millisecond (set in microseconds) */
#define PIT_OS_TICK_VALUE       (OS_TICK_PERIOD*PERIPH_FREQ)/1000  /* Value of Pit load value register to generate tick period */

#endif /* TPL_MPC5674F_DEFINE_H_ */
