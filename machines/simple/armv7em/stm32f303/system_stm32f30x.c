#include <stdint.h>
#include "stm32f3xx.h"

uint32_t SystemCoreClock = 8000000; /* startup frequency */

#if !defined  (HSE_VALUE) 
  #define HSE_VALUE    ((uint32_t)8000000) /*!< Default value of the External oscillator in Hz.
                                                This value can be provided and adapted by the user application. */
#endif /* HSE_VALUE */

#if !defined  (HSI_VALUE)
  #define HSI_VALUE    ((uint32_t)8000000) /*!< Default value of the Internal oscillator in Hz.
                                                This value can be provided and adapted by the user application. */
#endif /* HSI_VALUE */

/* system clock:
 * %%%% STM32F303x8 => 64MHz %%%% STM32F303xE => 72MHz %%%%
 * - use internal HSI RC oscillator => 8MHz
 * - PLL source is HSI => 8MHz
 * - configure PLLx9    => HCLK = 64 or 72MHz
 * - flash needs 2 wait states (F>48MHz)
 * - AHB prescaler not set (1)
 * - APB1 clocks sets to 32 or 36MHz (36 MHz max): but x2 for timers 2,3,6,7
 * - APB2 clocks sets to 64 or 72MHz.
 *
 * */
void SystemInit()
{
	// Must set flash latency (2 wait states): F>48MHz
    FLASH->ACR |= 2 << FLASH_ACR_LATENCY_Pos  // add two wait states
               |  FLASH_ACR_PRFTBE;           // enable prefetch buffer
	
    //clock on APB1 => max 36MHz
	//not divided for timers TIMx
	RCC->CFGR |= 4 << RCC_CFGR_PPRE1_Pos; 

	//make sure that HSI is the system clock
	RCC->CFGR &= ~RCC_CFGR_SW_Msk;		// reset SW configuration (HSI).
	
	RCC->CR &= ~(RCC_CR_PLLON);			// turn off PLL
    while(RCC->CR & RCC_CR_PLLRDY){}	// wait until pll is stopped

    RCC->CFGR &= ~(RCC_CFGR_PLLSRC_Msk); // reset PLLSRC
    #if defined(STM32F303xE)
        // remove prediv PLL by 2 (for 303RE, not available for 303K8)
        RCC->CFGR |= RCC_CFGR_PLLSRC_HSI_PREDIV;
        RCC->CFGR |= (RCC_CFGR_PLLMUL9);	// PLL multiply x9  => 72MHz
    #elif defined(STM32F303x8)
        RCC->CFGR |= (RCC_CFGR_PLLMUL16);	// PLL multiply x16 => 64MHz
    #else
        #error "clock configuration undefined"
    #endif
    RCC->CR |= RCC_CR_PLLON;			// turn on PLL
    while(!(RCC->CR & RCC_CR_PLLRDY)){}

	RCC->CFGR |= RCC_CFGR_SW_PLL;		// PLL is system clock

    /* FPU settings ------------------------------------------------------------*/
	#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
		SCB->CPACR |= ((3UL << 10*2)|(3UL << 11*2));  /* set CP10 and CP11 Full Access */
	#endif
	//update SystemCoreClock value.
	SystemCoreClockUpdate();
}

/** @brief  Update SystemCoreClock variable according to Clock Register Values.
  *         The SystemCoreClock variable contains the core clock (HCLK), it can
  *         be used by the user application to setup the SysTick timer or configure
  *         other parameters.
  * function from ST (BSD licence).
  */

const uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
const uint8_t APBPrescTable[8]  = {0, 0, 0, 0, 1, 2, 3, 4};

void SystemCoreClockUpdate (void)
{
  uint32_t tmp = 0, pllmull = 0, pllsource = 0, predivfactor = 0;

  /* Get SYSCLK source -------------------------------------------------------*/
  tmp = RCC->CFGR & RCC_CFGR_SWS;

  switch (tmp)
  {
    case RCC_CFGR_SWS_HSI:  /* HSI used as system clock */
      SystemCoreClock = HSI_VALUE;
      break;
    case RCC_CFGR_SWS_HSE:  /* HSE used as system clock */
      SystemCoreClock = HSE_VALUE;
      break;
    case RCC_CFGR_SWS_PLL:  /* PLL used as system clock */
      /* Get PLL clock source and multiplication factor ----------------------*/
      pllmull = RCC->CFGR & RCC_CFGR_PLLMUL;
      pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;
      pllmull = ( pllmull >> 18) + 2;

#if defined (STM32F302xE) || defined (STM32F303xE) || defined (STM32F398xx)
        predivfactor = (RCC->CFGR2 & RCC_CFGR2_PREDIV) + 1;
      if (pllsource == RCC_CFGR_PLLSRC_HSE_PREDIV)
      {
        /* HSE oscillator clock selected as PREDIV1 clock entry */
        SystemCoreClock = (HSE_VALUE / predivfactor) * pllmull;
      }
      else
      {
        /* HSI oscillator clock selected as PREDIV1 clock entry */
        SystemCoreClock = (HSI_VALUE / predivfactor) * pllmull;
      }
#else      
      if (pllsource == RCC_CFGR_PLLSRC_HSI_DIV2)
      {
        /* HSI oscillator clock divided by 2 selected as PLL clock entry */
        SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
      }
      else
      {
        predivfactor = (RCC->CFGR2 & RCC_CFGR2_PREDIV) + 1;
        /* HSE oscillator clock selected as PREDIV1 clock entry */
        SystemCoreClock = (HSE_VALUE / predivfactor) * pllmull;
      }
#endif /* STM32F302xE || STM32F303xE || STM32F398xx */
      break;
    default: /* HSI used as system clock */
      SystemCoreClock = HSI_VALUE;
      break;
  }
  /* Compute HCLK clock frequency ----------------*/
  /* Get HCLK prescaler */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
  /* HCLK clock frequency */
  SystemCoreClock >>= tmp;
}

