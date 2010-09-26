/* here are some functions to handle timers (1 and 2) of MC9328MXL (ARM9)
 *
 */ 

#ifndef __TIMER_H__
#define __TIMER_H__

#define TIMER1_IT 59
#define TIMER2_IT 58

//choose between T1 and T2.
#define T1_BASE 0x00202000
#define T2_BASE 0x00203000

// register address (relatively to base).
#define TCTL   0x0
#define TPRER  0x4
#define TCMP   0x8
#define TCR    0xC
#define TCN    0x10
#define TSTAT  0x14

/* get the address of a timer register.
 * @param timerId timer to choose (T1 => id=1 or T2=>every other value)
 * @param regId register to access (TCTL, TPRER, ..)
 * */
unsigned long *timerGetRegisterAddress(unsigned int timerId, unsigned int regId);


#define CLK_16M 0x2
#define CLK_1M  0x4
#define CLK_EXT 0x6
#define CLK_32K 0x8

/** init timer source with source defined just above
 * @param timerId timer to choose (T1 => id=1 or T2=>every other value)
 * @param source timer source (32k, 16M (PERCLK1), 1M or external).
 **/
void timerInit(unsigned int timerId, unsigned int source);

/** set the prescaler for timer source:
 * @param timerId timer to choose (T1 => id=1 or T2=>every other value)
 * @param prescaler prescaler value: 0=>divide by 1, 1=> divide by 2..0xFF =>divide by 256
 */
void timerSetPrescaler(unsigned int timerId, unsigned char prescaler);

/** get the current value of timer:
 * @param timerId timer to choose (T1 => id=1 or T2=>every other value)
 */
unsigned int timerGetValue(unsigned int timerId);

/** init a timer with the correct periodicity (in micro s)
 * @param timerId timer to choose (T1 => id=1 or T2=>every other value)
 * @param period period in us
 */
void timerInitWithPeriodicUS(unsigned int timerId, unsigned int period);


#endif
