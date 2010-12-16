#ifndef __STM_SYSTEM_H__
#define __STM_SYSTEM_H__

#ifndef __STM_REGS_H__
	#include <stm32f10x_lib.h>
#endif /*__STM_REGS_H__ */

/* Registers definition */
/* NVIC and SCB registers are already defined by stm32f10x_lib.h */
/* Other NVIC registers are defined here. 
   Pages are ones of ARM CORTEX Reference Manual (r2p0) (ARM DDI 0337G)*/

#define NVIC_ICTR 	((u32 *)((u32)0xE000E004))  /* Interrupt Controller Type Register, P8-7 */
#define NVIC_ACR 	((u32 *)((u32)0xE000E008))  /* Auxiliary Control Register */

/* Peripheral and user interrupts priority setting */

#define WWDG_VECT_INDEX 			0
#define PVD_VECT_INDEX 				0
#define TAMPER_VECT_INDEX 			0
#define RTC_VECT_INDEX 				0
#define FLASH_VECT_INDEX 			1
#define RCC_VECT_INDEX 				1
#define EXTI0_VECT_INDEX 			1
#define EXTI1_VECT_INDEX 			1
#define EXTI2_VECT_INDEX 			2
#define EXTI3_VECT_INDEX 			2
#define EXTI4_VECT_INDEX 			2
#define DMA1_CHANNEL1_VECT_INDEX 	2
#define DMA1_CHANNEL2_VECT_INDEX 	3
#define DMA1_CHANNEL3_VECT_INDEX 	3
#define DMA1_CHANNEL4_VECT_INDEX 	3
#define DMA1_CHANNEL5_VECT_INDEX 	3
#define DMA1_CHANNEL6_VECT_INDEX 	4
#define DMA1_CHANNEL7_VECT_INDEX 	4
#define ADC1_2_VECT_INDEX 			4
#define USB_HP_CAN_TX_VECT_INDEX 	4
#define USB_LP_CAN_RX0_VECT_INDEX 	5
#define CAN_RX1_VECT_INDEX 			5
#define CAN_SCE_VECT_INDEX 			5
#define EXTI9_5_VECT_INDEX 			5
#define TIM1_BRK_VECT_INDEX 		6
#define TIM1_UP_VECT_INDEX 			6
#define TIM1_TRG_COM_VECT_INDEX 	6
#define TIM1_CC_VECT_INDEX 			6
#define TIM2_VECT_INDEX 			7
#define TIM3_VECT_INDEX 			7
#define TIM4_VECT_INDEX 			7
#define I2C1_EV_VECT_INDEX 			7
#define I2C1_ER_VECT_INDEX 			8
#define I2C2_EV_VECT_INDEX 			8
#define I2C2_ER_VECT_INDEX 			8
#define SPI1_VECT_INDEX 			8
#define SPI2_VECT_INDEX 			9
#define USART1_VECT_INDEX 			9
#define USART2_VECT_INDEX 			9
#define USART3_VECT_INDEX 			9
#define EXTI15_10_VECT_INDEX 		10
#define RTCALARM_VECT_INDEX 		10
#define USBWAKEUP_VECT_INDEX 		10
#define TIM8_BRK_VECT_INDEX 		10
#define TIM8_UP_VECT_INDEX 			11
#define TIM8_TRG_COM_VECT_INDEX 	11
#define TIM8_CC_VECT_INDEX 			11
#define ADC3_VECT_INDEX 			11
#define FSMC_VECT_INDEX 			12
#define SDIO_VECT_INDEX 			12
#define TIM5_VECT_INDEX 			12
#define SPI3_VECT_INDEX 			12
#define UART4_VECT_INDEX 			13
#define UART5_VECT_INDEX 			13
#define TIM6_VECT_INDEX 			13
#define TIM7_VECT_INDEX 			13
#define DMA2_CHANNEL1_VECT_INDEX 	14
#define DMA2_CHANNEL2_VECT_INDEX 	14
#define DMA2_CHANNEL3_VECT_INDEX 	14
#define DMA2_CHANNEL4_5_VECT_INDEX 	14

#define WWDG_VECT_SHIFT 			4
#define PVD_VECT_SHIFT 				12
#define TAMPER_VECT_SHIFT 			20
#define RTC_VECT_SHIFT 				28
#define FLASH_VECT_SHIFT 			4
#define RCC_VECT_SHIFT 				12
#define EXTI0_VECT_SHIFT 			20
#define EXTI1_VECT_SHIFT 			28
#define EXTI2_VECT_SHIFT 			4
#define EXTI3_VECT_SHIFT 			12
#define EXTI4_VECT_SHIFT 			20
#define DMA1_CHANNEL1_VECT_SHIFT 	28
#define DMA1_CHANNEL2_VECT_SHIFT 	4
#define DMA1_CHANNEL3_VECT_SHIFT 	12
#define DMA1_CHANNEL4_VECT_SHIFT 	20
#define DMA1_CHANNEL5_VECT_SHIFT 	28
#define DMA1_CHANNEL6_VECT_SHIFT 	4
#define DMA1_CHANNEL7_VECT_SHIFT 	12
#define ADC1_2_VECT_SHIFT 			20
#define USB_HP_CAN_TX_VECT_SHIFT 	28
#define USB_LP_CAN_RX0_VECT_SHIFT 	4
#define CAN_RX1_VECT_SHIFT 			12
#define CAN_SCE_VECT_SHIFT 			20
#define EXTI9_5_VECT_SHIFT 			28
#define TIM1_BRK_VECT_SHIFT 		4
#define TIM1_UP_VECT_SHIFT 			12
#define TIM1_TRG_COM_VECT_SHIFT 	20
#define TIM1_CC_VECT_SHIFT 			28
#define TIM2_VECT_SHIFT 			4
#define TIM3_VECT_SHIFT 			12
#define TIM4_VECT_SHIFT 			20
#define I2C1_EV_VECT_SHIFT 			28
#define I2C1_ER_VECT_SHIFT 			4
#define I2C2_EV_VECT_SHIFT 			12
#define I2C2_ER_VECT_SHIFT 			20
#define SPI1_VECT_SHIFT 			28
#define SPI2_VECT_SHIFT 			4
#define USART1_VECT_SHIFT 			12
#define USART2_VECT_SHIFT 			20
#define USART3_VECT_SHIFT 			28
#define EXTI15_10_VECT_SHIFT 		4
#define RTCALARM_VECT_SHIFT 		12
#define USBWAKEUP_VECT_SHIFT 		20
#define TIM8_BRK_VECT_SHIFT 		28
#define TIM8_UP_VECT_SHIFT 			4
#define TIM8_TRG_COM_VECT_SHIFT 	12
#define TIM8_CC_VECT_SHIFT 			20
#define ADC3_VECT_SHIFT 			28
#define FSMC_VECT_SHIFT 			4
#define SDIO_VECT_SHIFT 			12
#define TIM5_VECT_SHIFT 			20
#define SPI3_VECT_SHIFT 			28
#define UART4_VECT_SHIFT 			4
#define UART5_VECT_SHIFT 			12
#define TIM6_VECT_SHIFT 			20
#define TIM7_VECT_SHIFT 			28
#define DMA2_CHANNEL1_VECT_SHIFT 	4
#define DMA2_CHANNEL2_VECT_SHIFT 	12
#define DMA2_CHANNEL3_VECT_SHIFT 	20
#define DMA2_CHANNEL4_5_VECT_SHIFT 	28

#define NVIC_SET_PRIO_PERIPH(vector,prio) NVIC->IPR[vector##_VECT_INDEX] = NVIC->IPR[vector##_VECT_INDEX] & ~((u32)(0xF << vector##_VECT_SHIFT));\
								   	      NVIC->IPR[vector##_VECT_INDEX] = NVIC->IPR[vector##_VECT_INDEX] | (prio << vector##_VECT_SHIFT)


/* System interrupts and exception priority setting */
#define MEM_FAULT_VECT_INDEX		0
#define BUS_FAULT_VECT_INDEX		0
#define USAGE_FAULT_VECT_INDEX		0
#define RES1_FAULT_VECT_INDEX		0
#define RES2_FAULT_VECT_INDEX		1
#define RES3_FAULT_VECT_INDEX		1
#define RES4_FAULT_VECT_INDEX		1
#define SVCALL_VECT_INDEX			1
#define DEBUG_VECT_INDEX			2
#define RES5_FAULT_VECT_INDEX		2
#define PENDSV_VECT_INDEX			2
#define SYSTICK_VECT_INDEX			2

#define MEM_FAULT_VECT_SHIFT		4
#define BUS_FAULT_VECT_SHIFT		12
#define USAGE_FAULT_VECT_SHIFT		20
#define RES1_FAULT_VECT_SHIFT		28
#define RES2_FAULT_VECT_SHIFT		4
#define RES3_FAULT_VECT_SHIFT		12
#define RES4_FAULT_VECT_SHIFT		20
#define SVCALL_VECT_SHIFT			28
#define DEBUG_VECT_SHIFT			4
#define RES5_FAULT_VECT_SHIFT		12
#define PENDSV_VECT_SHIFT			20
#define SYSTICK_VECT_SHIFT			28

#define NVIC_SET_PRIO_SYSTEM(vector,prio) SCB->SHPR[vector##_VECT_INDEX] = SCB->SHPR[vector##_VECT_INDEX] & ~((u32)(((u32)0x0F) << vector##_VECT_SHIFT));\
								          SCB->SHPR[vector##_VECT_INDEX] = SCB->SHPR[vector##_VECT_INDEX] | (prio << vector##_VECT_SHIFT)

/* Peripherals interrupts enable/disable/clear and set pending */
#define WWDG_BIT_INDEX 				0
#define PVD_BIT_INDEX 				0
#define TAMPER_BIT_INDEX 			0
#define RTC_BIT_INDEX 				0
#define FLASH_BIT_INDEX 			0
#define RCC_BIT_INDEX 				0
#define EXTI0_BIT_INDEX 			0
#define EXTI1_BIT_INDEX 			0
#define EXTI2_BIT_INDEX 			0
#define EXTI3_BIT_INDEX 			0
#define EXTI4_BIT_INDEX 			0
#define DMA1_CHANNEL1_BIT_INDEX 	0
#define DMA1_CHANNEL2_BIT_INDEX 	0
#define DMA1_CHANNEL3_BIT_INDEX 	0
#define DMA1_CHANNEL4_BIT_INDEX 	0
#define DMA1_CHANNEL5_BIT_INDEX 	0
#define DMA1_CHANNEL6_BIT_INDEX 	0
#define DMA1_CHANNEL7_BIT_INDEX 	0
#define ADC1_2_BIT_INDEX 			0
#define USB_HP_CAN_TX_BIT_INDEX 	0
#define USB_LP_CAN_RX0_BIT_INDEX 	0
#define CAN_RX1_BIT_INDEX 			0
#define CAN_SCE_BIT_INDEX 			0
#define EXTI9_5_BIT_INDEX 			0
#define TIM1_BRK_BIT_INDEX 			0
#define TIM1_UP_BIT_INDEX 			0
#define TIM1_TRG_COM_BIT_INDEX 		0
#define TIM1_CC_BIT_INDEX 			0
#define TIM2_BIT_INDEX 				0
#define TIM3_BIT_INDEX 				0
#define TIM4_BIT_INDEX 				0
#define I2C1_EV_BIT_INDEX 			0

#define I2C1_ER_BIT_INDEX 			1
#define I2C2_EV_BIT_INDEX 			1
#define I2C2_ER_BIT_INDEX 			1
#define SPI1_BIT_INDEX 				1
#define SPI2_BIT_INDEX 				1
#define USART1_BIT_INDEX 			1
#define USART2_BIT_INDEX 			1
#define USART3_BIT_INDEX 			1
#define EXTI15_10_BIT_INDEX 		1
#define RTCALARM_BIT_INDEX 			1
#define USBWAKEUP_BIT_INDEX 		1
#define TIM8_BRK_BIT_INDEX 			1
#define TIM8_UP_BIT_INDEX 			1
#define TIM8_TRG_COM_BIT_INDEX 		1
#define TIM8_CC_BIT_INDEX 			1
#define ADC3_BIT_INDEX 				1
#define FSMC_BIT_INDEX 				1
#define SDIO_BIT_INDEX 				1
#define TIM5_BIT_INDEX 				1
#define SPI3_BIT_INDEX 				1
#define UART4_BIT_INDEX 			1
#define UART5_BIT_INDEX 			1
#define TIM6_BIT_INDEX 				1
#define TIM7_BIT_INDEX 				1
#define DMA2_CHANNEL1_BIT_INDEX 	1
#define DMA2_CHANNEL2_BIT_INDEX 	1
#define DMA2_CHANNEL3_BIT_INDEX 	1
#define DMA2_CHANNEL4_5_BIT_INDEX 	1

#define WWDG_BIT_SHIFT 				0
#define PVD_BIT_SHIFT 				1
#define TAMPER_BIT_SHIFT 			2
#define RTC_BIT_SHIFT 				3
#define FLASH_BIT_SHIFT 			4
#define RCC_BIT_SHIFT 				5
#define EXTI0_BIT_SHIFT 			6
#define EXTI1_BIT_SHIFT 			7
#define EXTI2_BIT_SHIFT 			8
#define EXTI3_BIT_SHIFT 			9
#define EXTI4_BIT_SHIFT 			10
#define DMA1_CHANNEL1_BIT_SHIFT 	11
#define DMA1_CHANNEL2_BIT_SHIFT 	12
#define DMA1_CHANNEL3_BIT_SHIFT 	13
#define DMA1_CHANNEL4_BIT_SHIFT 	14
#define DMA1_CHANNEL5_BIT_SHIFT 	15
#define DMA1_CHANNEL6_BIT_SHIFT 	16
#define DMA1_CHANNEL7_BIT_SHIFT 	17
#define ADC1_2_BIT_SHIFT 			18
#define USB_HP_CAN_TX_BIT_SHIFT 	19
#define USB_LP_CAN_RX0_BIT_SHIFT 	20
#define CAN_RX1_BIT_SHIFT 			21
#define CAN_SCE_BIT_SHIFT 			22
#define EXTI9_5_BIT_SHIFT 			23
#define TIM1_BRK_BIT_SHIFT 			24
#define TIM1_UP_BIT_SHIFT 			25
#define TIM1_TRG_COM_BIT_SHIFT 		26
#define TIM1_CC_BIT_SHIFT 			27
#define TIM2_BIT_SHIFT 				28
#define TIM3_BIT_SHIFT 				29
#define TIM4_BIT_SHIFT 				30
#define I2C1_EV_BIT_SHIFT 			31

#define I2C1_ER_BIT_SHIFT 			0
#define I2C2_EV_BIT_SHIFT 			1
#define I2C2_ER_BIT_SHIFT 			2
#define SPI1_BIT_SHIFT 				3
#define SPI2_BIT_SHIFT 				4
#define USART1_BIT_SHIFT 			5
#define USART2_BIT_SHIFT 			6
#define USART3_BIT_SHIFT 			7
#define EXTI15_10_BIT_SHIFT 		8
#define RTCALARM_BIT_SHIFT 			9
#define USBWAKEUP_BIT_SHIFT 		10
#define TIM8_BRK_BIT_SHIFT 			11
#define TIM8_UP_BIT_SHIFT 			12
#define TIM8_TRG_COM_BIT_SHIFT 		13
#define TIM8_CC_BIT_SHIFT 			14
#define ADC3_BIT_SHIFT 				15
#define FSMC_BIT_SHIFT 				16
#define SDIO_BIT_SHIFT 				17
#define TIM5_BIT_SHIFT 				18
#define SPI3_BIT_SHIFT 				19
#define UART4_BIT_SHIFT 			20
#define UART5_BIT_SHIFT 			21
#define TIM6_BIT_SHIFT 				22
#define TIM7_BIT_SHIFT 				23
#define DMA2_CHANNEL1_BIT_SHIFT 	24
#define DMA2_CHANNEL2_BIT_SHIFT 	25
#define DMA2_CHANNEL3_BIT_SHIFT 	26
#define DMA2_CHANNEL4_5_BIT_SHIFT 	27

#define NVIC_ENABLE_PERIPH_IT(vector) NVIC->ISER[vector##_BIT_INDEX] = NVIC->ISER[vector##_BIT_INDEX] | ((u32)(1 << vector##_BIT_SHIFT))
#define NVIC_DISABLE_PERIPH_IT(vector) NVIC->ICER[vector##_BIT_INDEX] = NVIC->ICER[vector##_BIT_INDEX] | ((u32)(1 << vector##_BIT_SHIFT))
#define NVIC_SET_PENDING_PERIPH_IT(vector) NVIC->ISPR[vector##_BIT_INDEX] = NVIC->ISPR[vector##_BIT_INDEX] | ((u32)(1 << vector##_BIT_SHIFT))
#define NVIC_CLEAR_PENDING_PERIPH_IT(vector) NVIC->ICPR[vector##_BIT_INDEX] = NVIC->ICPR[vector##_BIT_INDEX] | ((u32)(1 << vector##_BIT_SHIFT))

#define NVIC_IS_PENDING_PERIPH_IT(vector) (NVIC->ICPR[vector##_BIT_INDEX] & ((u32)(1 << vector##_BIT_SHIFT)))
#define NVIC_IS_ENABLED_PERIPH_IT(vector) (NVIC->ICER[vector##_BIT_INDEX] & ((u32)(1 << vector##_BIT_SHIFT)))

/* System interrupts enable/disable/clear and set pending */
#define MEM_FAULT_EN_BIT_SHIFT			16
#define BUS_FAULT_EN_BIT_SHIFT			17
#define USAGE_FAULT_EN_BIT_SHIFT		18

#define MEM_FAULT_PENDED_BIT_SHIFT		13
#define BUS_FAULT_PENDED_BIT_SHIFT		14
#define USAGE_FAULT_PENDED_BIT_SHIFT	12
#define SVCALL_PENDED_BIT_SHIFT			15

#define MEM_FAULT_ACT_BIT_SHIFT			0
#define BUS_FAULT_ACT_BIT_SHIFT			1
#define USAGE_FAULT_ACT_BIT_SHIFT		3
#define SYSTICK_ACT_BIT_SHIFT			11
#define SVCALL_ACT_BIT_SHIFT			7
#define DEBUG_ACT_BIT_SHIFT				8
#define PENDSV_ACT_BIT_SHIFT			10

#define NVIC_ENABLE_SYSTEM_IT(vector) (SCB->SHCSR = SCB->SHCSR | ((u32)(1 << vector##_EN_BIT_SHIFT))) 
#define NVIC_DISABLE_SYSTEM_IT(vector) (SCB->SHCSR = SCB->SHCSR & ~((u32)(1 << vector##_EN_BIT_SHIFT)))
#define NVIC_SET_PENDING_SYSTEM_IT(vector) SCB->SHCSR = SCB->SHCSR | ((u32)(1 << vector##_PENDED_BIT_SHIFT))
#define NVIC_CLEAR_PENDING_SYSTEM_IT(vector) SCB->SHCSR = SCB->SHCSR | ((u32)(1 << vector##_PENDED_BIT_SHIFT))
#define NVIC_SET_ACTIVE_SYSTEM_IT(vector) SCB->SHCSR = SCB->SHCSR | ((u32)(1 << vector##_ACT_BIT_SHIFT))
#define NVIC_CLEAR_ACTIVE_SYSTEM_IT(vector) SCB->SHCSR = SCB->SHCSR | ((u32)(1 << vector##_ACT_BIT_SHIFT))

#define NVIC_IS_PENDING_SYSTEM_IT(vector) (SCB->SHCSR & ((u32)(1 << vector##_PENDED_BIT_SHIFT)))
#define NVIC_IS_ACTIVE_SYSTEM_IT(vector) (SCB->SHCSR & ((u32)(1 << vector##_ACT_BIT_SHIFT)))

/* Generate SW interrupt */
#define SYS_RAISE_SW_INTERRUPT(interrupt) (NVIC_STIR=interrupt)

/* Enable/disable global interrupts */
#define SYS_ENABLE_GLOBAL_INTERRUPTS() asm("CPSIE i") 
#define SYS_DISABLE_GLOBAL_INTERRUPTS() asm("CPSID i")
#define SYS_ENABLE_FAULT_INTERRUPTS() asm("CPSIE f")
#define SYS_DISABLE_FAULT_INTERRUPTS() asm("CPSID f")

/* Set base priority mask register */
#define SYS_SET_BASE_PRIORITY_MASK(prio)				\
	asm volatile										\
	(													\
		"	mov r0, %0								\n"	\
		"	msr basepri, r0							\n" \
		::"i"(prio):"r0"								\
	)

/* Set active stack pointer and thread mode privilege level */
#define SYS_USE_PSP_STACK()								\
	asm volatile										\
	(													\
		"   eor r1,r1								\n" \
		"   movw r1, #2								\n" \
		"	mrs r0,control							\n"	\
		"   orr r0, r1								\n" \
		"	msr basepri, r0							\n" \
		"   isb										\n" \
		:::"r0"										\
	)

#define SYS_USE_MSP_STACK()								\
	asm volatile										\
	(													\
		"   eor r1,r1								\n" \
		"   movw r1, #2								\n" \
		"	mrs r0,control							\n"	\
		"   bic r0, r1								\n" \
		"	msr basepri, r0							\n" \
		"   isb										\n" \
		:::"r0"										\
	)

#define SYS_TPL_MODE_UNPRIVILEGED()						\
	asm volatile										\
	(													\
		"   eor r1,r1								\n" \
		"   movw r1, #1								\n" \
		"	mrs r0,control							\n"	\
		"   orr r0, r1								\n" \
		"	msr basepri, r0							\n" \
		"   isb										\n" \
		:::"r0"										\
	)

#define SYS_TPL_MODE_PRIVILEGED()								\
	asm volatile										\
	(													\
		"   eor r1,r1								\n" \
		"   movw r1, #1								\n" \
		"	mrs r0,control							\n"	\
		"   bic r0, r1								\n" \
		"	msr basepri, r0							\n" \
		"   isb										\n" \
		:::"r0"										\
	)

/* Manage sleep mode */
#define SCB_SEVONPEND_BIT 4
#define SCB_SLEEPDEEP_BIT 2
#define SCB_SLEEPONEXIT_BIT	1

#define SCB_WAKEUP_ON_ALL_IT() (SCB_SCR = SCB_SCR | ((u32)(1<<SCB_SEVONPEND_BIT)))
#define SCB_WAKEUP_ON_ENABLED_IT() (SCB_SCR = SCB_SCR & ~((u32)(1<<SCB_SEVONPEND_BIT)))
#define SCB_SET_DEEP_SLEEP() (SCB_SCR = SCB_SCR | ((u32)(1<<SCB_SLEEPDEEP_BIT)))
#define SCB_SET_NORMAL_SLEEP() (SCB_SCR = SCB_SCR & ~((u32)(1<<SCB_SLEEPDEEP_BIT)))
#define SCB_ENABLE_SLEEP_ON_EXIT() (SCB_SCR = SCB_SCR | ((u32)(1<<SCB_SLEEPONEXIT_BIT)))
#define SCB_DISABLE_SLEEP_ON_EXIT() (SCB_SCR = SCB_SCR & ~((u32)(1<<SCB_SLEEPONEXIT_BIT)))

#ifndef _WFE_
	#define _WFE_ (asm("wfe"))
	#define _WFI_ (asm("wfi"))
#endif /* _WFE_ */

/* CPU ID management */
typedef struct _CPUID_STR 
{
    int implementer;
    int variant;
    int partno;
	int revision;
} cpuid_st;

void SCB_Get_CPUID(cpuid_st *id);

/* Vector table offset management*/
#define NVIC_TABLE_IN_SRAM ((u32)(1<<29))
#define NVIC_TABLE_IN_FLASH ((u32)(0))
#define NVIC_TABLE_OFFSET_SHIFT 7

#define NVIC_SET_VECTOR_TABLE(place, offset) (SCB->VTOR = ((u32)(place + (u32)(offset<<NVIC_TABLE_OFFSET_SHIFT))))

/* Miscellaneous actions */
#define SYS_RESET() (SCB->AIRCR = (SCB->AIRCR & 0x0000FFFF) + 0x05FA0000 + (1<<2))

/* Systick management */
/* Systick Control */
#define SYSTICK_EN_BIT					1
#define SYSTICK_CLOCK_BIT				2
#define SYSTICK_OVERFLOW_BIT			16				

#define SYSTICK_ENABLE_IT() (SysTick->CTRL = SysTick->CTRL | ((u32)(1 << SYSTICK_EN_BIT)))
#define SYSTICK_DISABLE_IT() (SysTick->CTRL = SysTick->CTRL & ~((u32)(1 << SYSTICK_EN_BIT)))
#define SYSTICK_CLOCK_AHB() (SysTick->CTRL = SysTick->CTRL | ((u32)(1 << SYSTICK_CLOCK_BIT))) 
#define SYSTICK_CLOCK_AHB_8() (SysTick->CTRL = SysTick->CTRL & ~((u32)(1 << SYSTICK_CLOCK_BIT)))
#define SYSTICK_ENABLE_COUNTER() (SysTick->CTRL = SysTick->CTRL | ((u32)(1))) 
#define SYSTICK_DISABLE_COUNTER() (SysTick->CTRL = SysTick->CTRL & ~((u32)(1)))
#define SYSTICK_IS_OVERFLOW() (SysTick->CTRL & ((u32)(1<<SYSTICK_OVERFLOW_BIT))) 

/* Systick reload managment */
/* Set systick periodic interrupt for a frequency FREQ, expressed in Hz */
#define SYSTICK_SET_PERIOD(FREQ) SysTick->LOAD = (__SYSCLK/FREQ)

#endif /*  __STM_SYSTEM_H__ */
