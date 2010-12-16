/*
________________________________________________________________________________________
	Clock configuration files for stm32f103
	stm_clock.h
    GPL licensed code (S. Di Mercurio and P. Acco)
________________________________________________________________________________________
USAGE
	??? is the name of the library i.e. stm_clock
	RELPATH is the relative path from your projetc directory to lib_cm3 directory	
	
   	include RELPATH/lib_cm3/???.c file in your makefile
	copy    RELPATH/lib_cm3/???_config_TEMPLATE.h in your project directory	(noted ./)
	rename  ./???_config_TEMPLATE.h as ./???_config.h in your project directory
	edit    ./???_config.h file for your project (lines with //CONF tags)  
	ensure that ./ path is visible in CC compiler options 
	add "#include "RELPATH/lib_cm3/???.h" in app. code 
	add a call to "Init_???();" at initialisation step of your APP
________________________________________________________________________________________
REVS
	[Acco 06/01/2010] finalisation et commentaires de la première version
		Testée en réel et simulé (utilisation de PWM et USART et CAN)		
________________________________________________________________________________________
TODO
	test _SYSCLK_SOURCE IS_HSI and IS_HSE
	+ Peripheral clock enable  functions
	+ USBCLK, MCO, CSS fonctionalities
	+ RTCCLK IWDGCLK functionalities
	+ TIM1 and TIM2  
 	+ stm32_GetPCLK2() et autres fonctions pour assurer 
	  la compatibilité avec stm32f10x lib
________________________________________________________________________________________
*/

#ifndef __STM_CLOCK
#define __STM_CLOCK

#include "stm_clock_config.h"

//________________________________________________
void Init_Clock_System(void) ;
//	Initialise clocks and wait for their stability
//  DO NOT TRY TO CONFIG ANY PERIPHERALS before this
//   function is executed : config registers are not 
//   clocked  and won't keep any value 




//________________________________________________
extern unsigned int stm32_GetHCLK (void) ;
// return frequency in Hz of the HCLK clock
//   output of AHB prescaler 
// use this function for peripherals programming
// compatible with stm32f10x lib

//________________________________________________
extern unsigned int stm32_GetPCLK1 (void);
// return frequency in Hz of the PCLK1 clock
//   output of APB1 (low speed max 36MHz)
// use this function for peripherals programming
// compatible with stm32f10x lib

//________________________________________________
extern unsigned int stm32_Get_TIMXCLK (void) ; 
// return frequency in Hz of the TIMCCLK clock
//   output of TIM2,3,4,6,7 multiplier (low speed max 36MHz)
// use this function for peripherals programming
// compatible with stm32f10x lib


//________________________________________________
extern unsigned int stm32_GetPCLK2 (void) ;
// return frequency in Hz of the PCLK2 clock
//   output of APB2 (high speed max 72MHz)
// use this function for peripherals programming
// compatible with stm32f10x lib


//________________________________________________
extern unsigned int stm32_Get_TIMxCLK (void) ;
// return frequency in Hz of the TIMxCLK clock
//  output of TIM1 &8 multiplier (high speed max 72MHz)
// use this function for peripherals programming
// compatible with stm32f10x lib

//________________________________________________
extern unsigned int stm32_Get_ADCCLK (void) ;
// return frequency in Hz of the ADCCLK clock
// output of ADC prescaler (max 14MHz)
// use this function for peripherals programming
// compatible with stm32f10x lib


#endif
