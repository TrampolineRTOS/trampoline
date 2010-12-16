/*
________________________________________________________________________________________
	Clock configuration files for stm32f103
	stm_clock_config[_TEMMPLATE].h
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

#ifndef __STM_CLOCK_CONFIG
#define __STM_CLOCK_CONFIG

#define IS_HSI 1					//DO NOT MODIFIY THIS CONSTANT
#define IS_HSE 2					//DO NOT MODIFIY THIS CONSTANT
#define IS_PLL 3					//DO NOT MODIFIY THIS CONSTANT
#define IS_DIRECT 		(RCC_PLLXTPRE_IS_HSE)				//DO NOT MODIFIY THIS CONSTANT
#define IS_DIVIDED_BY_2 (RCC_PPLXTPRE_IS_HSE_DIV_2)	    	//DO NOT MODIFIY THIS CONSTANT
#define __HSI 8000000UL	  // High Speed Internal RC clock (8MHz) on STM32F103xx


/*_________________________________________________________________________________________
// edit CONFIGURE tags below this line
//________________________________________________________________________________________*/

//_________________________________________________________________________________________
// SYSTEM CLOCK CONFIGURATION

// CONFIGURE crystal frequency of High Speed External clock
// [4000000UL (4MHz) to 16_000_000UL (16MHz)] crystal frequency in Hz (8MHz on MCBSTM32 boards)
#define __HSE 8000000UL

// CONFIGURE SYSCLK source : it can be
//  IS_HSI : for High Speed Internal clock  (the approx. 8MHz local RC clock)
//  IS_HSE : for High Speed External Clock  (the external crystal) 8MHz on MCBSTM32 boards
//  IS_PLL : when using the Phase Locked Loop circuit to multiply frequency ( 72MHz max)
#define _SYSCLK_SOURCE IS_PLL

// CONFIGURE PLL source ONLY if you set _SYSCLK_SOURCE IS_PLL
//  IS_HSI : for High Speed Internal clock  prescaled by 2 (the 8MHz local RC clock)
//  IS_HSE : for High Speed External Clock  (the external crystal) prescaled by 2 or not
#define _PLL_SOURCE IS_HSE
   	
//CONFIGURE pll extern prescaler ONLY IF you set _SYSCLK_SOURCE IS_PLL and _PLL_SOURCE IS_HSE
// 								   OR IF you will set _USBCLK IS_USED
// IS_DIRECT : when PLL input is directly driven by HSE external crystal
// IS_DIVIDED_BY_2 : when PLL input is drived by /2 prescaler of HSE external crystal 
#define _PLLXTPRE IS_DIRECT
	
// CONFIGURE pll multiplication factor  ONLY IF you set _SYSCLK_SOURCE IS_PLL
// 								  		 OR IF you will set _USBCLK IS_USED
// [2 to 16] choose any multiplication factor in this fork 
#define __PLLMULL 5

// end of system clock cnfiguration
//_________________________________________________________________________________________



//_________________________________________________________________________________________
// AUXILIARY PERIPHERALS CLOCK configuration

// CONFIGURE AHB prescaler (presacler that gives clock to APB1,APB2,
//                          SDIO,FSMC,AHB,Cortex system timer and FCLK
// {1,2,4,8,16,64,128,256,512} choose any division factor in this list
//                              (32 is not on the list!)
#define _HPRE	1 

// CONFIGURE PPRE1 APB low-speed prescaler (presacler that gives clock to 
// {1,2,4,8,16} choose any division factor in this list
#define _PPRE1	2 

// CONFIGURE PPRE2 APB high-speed prescaler (presacler that gives clock to 
// {1,2,4,8,16} choose any division factor in this list
#define _PPRE2	1 

// CONFIGURE ADCPRE ADC prescaler 
// {2,4,6,8} choose any division factor in this list
#define _ADCPRE	4

// end of auxiliary peripherals clock configuration
//_________________________________________________________________________________________


/*______________________________________________________________________________________
//              DO NOT EDIT BELOW THIS LINE !!!!!!
//____________________________________________________________________________________*/

//______________________________________________________________________________________
// Control of inputs  
// Evaluation and control of frequencies (generates error message)
// defines __SYSCLK, __HCLK, __PCLK1, __PCLK2, __ADCCLK	 __TIMXCLK __TIMxCLK
#if (__HSE<4000000UL)
#error "Line 35 : __HSE crystal freq. too slow ! should be more than 4000000UL. Forgot a zero buddy ?"
#endif
#if (__HSE>16000000UL)
#error "Line 35 : __HSE crystal freq. too high ! should be less than 16000000UL. Too much zeros buddy ?"
#endif

#if ((_SYSCLK_SOURCE!=IS_HSI)&&(_SYSCLK_SOURCE!=IS_HSE)&&(_SYSCLK_SOURCE!=IS_PLL))
#error "Line 41 : invalid _SYSCLK_SOURCE should be IS_HSI, IS_HSE or IS_PLL"
#endif

#if ((_PLL_SOURCE!=IS_HSI)&&(_PLL_SOURCE!=IS_HSE))
#error "Line 46 : invalid _PLL_SOURCE should be IS_HSI or IS_HSE"
#endif

#if ((_PLLXTPRE!=IS_DIRECT)&&(_PLLXTPRE!=IS_DIVIDED_BY_2))
#error "Line 52 : invalid _PLLXTPRE should be IS_DIRECT or IS_DIVIDED_BY_2"
#endif

#if (__PLLMULL > 16)
	#error "Line 57 : __PLLMULL value too high! Should be from 2 to 16"
#elif (__PLLMULL < 2)
	#error "Line 57 : __PLLMULL value too low! Should be from 2 to 16"
#endif



#if ((_HPRE!=1)&&(_HPRE!=2)&&(_HPRE != 4)&&(_HPRE!=8)&&(_HPRE!=16)&&(_HPRE!=64)&&(_HPRE!=128)&&(_HPRE!=256)&&(_HPRE!=512) )
#error "Line 71 : _HPRE value should be 1,2,4,8,16,64,128,256 or 512 (32 is not on the list!)"
#endif

#if ((_PPRE1!=1)&&(_PPRE1!=2)&&(_PPRE1!=4)&&(_PPRE1!=8)&&(_PPRE1!=16) )
#error "Line 75 : _PPRE1 value should be 1,2,4,8 or 16"
#endif

#if ((_PPRE2!=1)&&(_PPRE2!=2)&&(_PPRE2!=4)&&(_PPRE2!=8)&&(_PPRE2!=16) )
#error "Line 79 : _PPRE2 value should be 1,2,4,8 or 16"
#endif

#if ((_ADCPRE!=2)&&(_ADCPRE!=4)&&(_ADCPRE!=6)&&(_ADCPRE!=8) )
#error "Line 83 : _ADCPRE value should be 2,4,6 or 8"
#endif


// Frequency evaluation and controls

// Eval __SYSCLK	(max is 72 Mz)
#if   (_SYSCLK_SOURCE==IS_HSI)
	#define __SYSCLK (__HSI)
#elif (_SYSCLK_SOURCE==IS_HSE)
	#define __SYSCLK (__HSE)
#elif (_SYSCLK_SOURCE==IS_PLL)
	#if (_PLL_SOURCE==IS_HSI)
		#define INPLL_CLK (__HSI/2)
	#elif(_PLL_SOURCE==IS_HSE)
		#if (_PLLXTPRE==IS_DIRECT)
			#define INPLL_CLK (__HSE)	 	
		#elif (_PLLXTPRE==IS_DIVIDED_BY_2)
			#define INPLL_CLK (__HSE/2)	 	
		#else
			#define INPLL_CLK (3)	 				
		#endif
	#else 
		#define INPLL_CLK (2)
	#endif
	#define __PLLCLK ((__PLLMULL)*(INPLL_CLK))
	#define __SYSCLK (__PLLCLK)
#else
	#define __SYSCLK (1)
#endif
#if ((__SYSCLK)>72000000UL)
	#error "PLL output frequency should not exceed 72 MHz ! Reduce __PLMULL or set _PLLXTPRE to IS_DIVIDED_BY_2"
#endif 

// Eval __HCLK	 output of AHB prescaler connect to SYSCLK
#define __HCLK	((__SYSCLK)/(_HPRE))

// Eval __PCLK1	 output of APB1 (low speed max 36MHz) prescaler 
#define __PCLK1 ((__HCLK)/(_PPRE1))
#if ((__PCLK1)>36000000UL)
	#error "APB1 output frequency should not exceed 36 MHz ! Increase _PPRE1 or _HPRE prescaler ratio"
#endif 
#if (_PPRE1==1)
	#define __TIMXCLK (__PCLK1)
#else
	#define __TIMXCLK (__PCLK1*2UL)
#endif
// Eval __PCLK2	 output of APB2 (High speed) prescaler 
#define __PCLK2 ((__HCLK)/(_PPRE2))
#if (_PPRE2==1)
	#define __TIMxCLK (__PCLK2)
#else
	#define __TIMxCLK (__PCLK2*2UL)
#endif

// Eval __ADCCLK ADC prescaler output (max freq. 14MHz)
#define __ADCCLK ((__PCLK2)/(_ADCPRE))
#if ((__ADCCLK)>14000000UL)
	#error "ADC prescaler output frequency should not exceed 14 MHz ! Increase _ADCPRE or _HPRE prescaler ratio"
#endif 
	
#endif	
			