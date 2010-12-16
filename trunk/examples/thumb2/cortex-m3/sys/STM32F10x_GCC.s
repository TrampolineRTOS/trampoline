/*****************************************************************************/
/* STM32F10x.s: Startup file for ST STM32F10x device series                  */
/*****************************************************************************/
/* Version: CodeSourcery Sourcery G++ Lite (with CS3)                        */
/* Modifié SDM pour appeler la fonction Startup et non pas _start            */
/*****************************************************************************/


/* 
//*** <<< Use Configuration Wizard in Context Menu >>> *** 
*/


/*
// <h> Stack Configuration
//   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
// </h>
*/

    .equ    Stack_Size, 0x00000200
    .section ".stack", "w"
    .align  3
    .globl  __cs3_stack_mem
    .globl  __cs3_stack_size
__cs3_stack_mem:
    .if     Stack_Size
    .space  Stack_Size
    .endif
    .size   __cs3_stack_mem,  . - __cs3_stack_mem
    .set    __cs3_stack_size, . - __cs3_stack_mem


/*
// <h> Heap Configuration
//   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
// </h>
*/

    .equ    Heap_Size,  0x00001000
    
    .section ".heap", "w"
    .align  3
    .globl  __cs3_heap_start
    .globl  __cs3_heap_end
__cs3_heap_start:
    .if     Heap_Size
    .space  Heap_Size
    .endif
__cs3_heap_end:


/* Vector Table */

    .section ".cs3.interrupt_vector"
    .globl  __cs3_interrupt_vector_cortex_m
    .type   __cs3_interrupt_vector_cortex_m, %object

__cs3_interrupt_vector_cortex_m:
    .long   __cs3_stack                 /* Top of Stack                 */
    .long   __cs3_reset                 /* Reset Handler                */
    .long   NMI_Handler                 /* NMI Handler                  */
    .long   HardFault_Handler           /* Hard Fault Handler           */
    .long   MemManage_Handler           /* MPU Fault Handler            */
    .long   BusFault_Handler            /* Bus Fault Handler            */
    .long   UsageFault_Handler          /* Usage Fault Handler          */
    .long   0                           /* Reserved                     */
    .long   0                           /* Reserved                     */
    .long   0                           /* Reserved                     */
    .long   0                           /* Reserved                     */
    .long   SVC_Handler                 /* SVCall Handler               */
    .long   DebugMon_Handler            /* Debug Monitor Handler        */
    .long   0                           /* Reserved                     */
    .long   PendSV_Handler              /* PendSV Handler               */
    .long   SysTick_Handler             /* SysTick Handler              */

    /* External Interrupts */
    .long   WWDG_IRQHandler             /* Window Watchdog              */
    .long   PVD_IRQHandler              /* PVD through EXTI Line detect */
    .long   TAMPER_IRQHandler           /* Tamper                       */
    .long   RTC_IRQHandler              /* RTC                          */
    .long   FLASH_IRQHandler            /* Flash                        */
    .long   RCC_IRQHandler              /* RCC                          */
    .long   EXTI0_IRQHandler            /* EXTI Line 0                  */
    .long   EXTI1_IRQHandler            /* EXTI Line 1                  */
    .long   EXTI2_IRQHandler            /* EXTI Line 2                  */
    .long   EXTI3_IRQHandler            /* EXTI Line 3                  */
    .long   EXTI4_IRQHandler            /* EXTI Line 4                  */
    .long   DMAChannel1_IRQHandler      /* DMA Channel 1                */
    .long   DMAChannel2_IRQHandler      /* DMA Channel 2                */
    .long   DMAChannel3_IRQHandler      /* DMA Channel 3                */
    .long   DMAChannel4_IRQHandler      /* DMA Channel 4                */
    .long   DMAChannel5_IRQHandler      /* DMA Channel 5                */
    .long   DMAChannel6_IRQHandler      /* DMA Channel 6                */
    .long   DMAChannel7_IRQHandler      /* DMA Channel 7                */
    .long   ADC_IRQHandler              /* ADC                          */
    .long   USB_HP_CAN_TX_IRQHandler    /* USB High Priority or CAN TX  */
    .long   USB_LP_CAN_RX0_IRQHandler   /* USB Low  Priority or CAN RX0 */ 
    .long   CAN_RX1_IRQHandler          /* CAN RX1                      */
    .long   CAN_SCE_IRQHandler          /* CAN SCE                      */
    .long   EXTI9_5_IRQHandler          /* EXTI Line 9..5               */
    .long   TIM1_BRK_IRQHandler         /* TIM1 Break                   */
    .long   TIM1_UP_IRQHandler          /* TIM1 Update                  */
    .long   TIM1_TRG_COM_IRQHandler     /* TIM1 Trigger and Commutation */
    .long   TIM1_CC_IRQHandler          /* TIM1 Capture Compare         */
    .long   TIM2_IRQHandler             /* TIM2                         */
    .long   TIM3_IRQHandler             /* TIM3                         */
    .long   TIM4_IRQHandler             /* TIM4                         */
    .long   I2C1_EV_IRQHandler          /* I2C1 Event                   */
    .long   I2C1_ER_IRQHandler          /* I2C1 Error                   */
    .long   I2C2_EV_IRQHandler          /* I2C2 Event                   */
    .long   I2C2_ER_IRQHandler          /* I2C2 Error                   */
    .long   SPI1_IRQHandler             /* SPI1                         */
    .long   SPI2_IRQHandler             /* SPI2                         */
    .long   USART1_IRQHandler           /* USART1                       */
    .long   USART2_IRQHandler           /* USART2                       */
    .long   USART3_IRQHandler           /* USART3                       */
    .long   EXTI15_10_IRQHandler        /* EXTI Line 15..10             */
    .long   RTCAlarm_IRQHandler         /* RTC Alarm through EXTI Line  */
    .long   USBWakeUp_IRQHandler        /* USB Wakeup from suspend      */

    .size   __cs3_interrupt_vector_cortex_m, . - __cs3_interrupt_vector_cortex_m


    .thumb


/* Reset Handler */

    .section .cs3.reset,"x",%progbits
    .thumb_func
    .globl  __cs3_reset_cortex_m
    .type   __cs3_reset_cortex_m, %function
__cs3_reset_cortex_m:
    .fnstart
    /*LDR     R0,=_start */  
	LDR		R0,=Startup	  
    BX      R0
    .pool
    .cantunwind
    .fnend
    .size   __cs3_reset_cortex_m,.-__cs3_reset_cortex_m

    .section ".text"

/* Exception Handlers */

    .weak   NMI_Handler
    .type   NMI_Handler, %function
NMI_Handler:
    B       .
    .size   NMI_Handler, . - NMI_Handler

    .weak   HardFault_Handler
    .type   HardFault_Handler, %function
HardFault_Handler:
    B       .
    .size   HardFault_Handler, . - HardFault_Handler

    .weak   MemManage_Handler
    .type   MemManage_Handler, %function
MemManage_Handler:
    B       .
    .size   MemManage_Handler, . - MemManage_Handler

    .weak   BusFault_Handler
    .type   BusFault_Handler, %function
BusFault_Handler:
    B       .
    .size   BusFault_Handler, . - BusFault_Handler

    .weak   UsageFault_Handler
    .type   UsageFault_Handler, %function
UsageFault_Handler:
    B       .
    .size   UsageFault_Handler, . - UsageFault_Handler

    .weak   SVC_Handler
    .type   SVC_Handler, %function
SVC_Handler:
    B       .
    .size   SVC_Handler, . - SVC_Handler

    .weak   DebugMon_Handler
    .type   DebugMon_Handler, %function
DebugMon_Handler:
    B       .
    .size   DebugMon_Handler, . - DebugMon_Handler

    .weak   PendSV_Handler
    .type   PendSV_Handler, %function
PendSV_Handler:
    B       .
    .size   PendSV_Handler, . - PendSV_Handler

    .weak   SysTick_Handler
    .type   SysTick_Handler, %function
SysTick_Handler:
    B       .
   .size   SysTick_Handler, . - SysTick_Handler


/* IRQ Handlers */

    .globl  Default_Handler
    .type   Default_Handler, %function
Default_Handler:
    B       .
    .size   Default_Handler, . - Default_Handler

    .macro  IRQ handler
    .weak   \handler
    .set    \handler, Default_Handler
    .endm

    IRQ     WWDG_IRQHandler
    IRQ     PVD_IRQHandler
    IRQ     TAMPER_IRQHandler
    IRQ     RTC_IRQHandler
    IRQ     FLASH_IRQHandler
    IRQ     RCC_IRQHandler
    IRQ     EXTI0_IRQHandler
    IRQ     EXTI1_IRQHandler
    IRQ     EXTI2_IRQHandler
    IRQ     EXTI3_IRQHandler
    IRQ     EXTI4_IRQHandler
    IRQ     DMAChannel1_IRQHandler
    IRQ     DMAChannel2_IRQHandler
    IRQ     DMAChannel3_IRQHandler
    IRQ     DMAChannel4_IRQHandler
    IRQ     DMAChannel5_IRQHandler
    IRQ     DMAChannel6_IRQHandler
    IRQ     DMAChannel7_IRQHandler
    IRQ     ADC_IRQHandler
    IRQ     USB_HP_CAN_TX_IRQHandler
    IRQ     USB_LP_CAN_RX0_IRQHandler
    IRQ     CAN_RX1_IRQHandler
    IRQ     CAN_SCE_IRQHandler
    IRQ     EXTI9_5_IRQHandler
    IRQ     TIM1_BRK_IRQHandler
    IRQ     TIM1_UP_IRQHandler
    IRQ     TIM1_TRG_COM_IRQHandler
    IRQ     TIM1_CC_IRQHandler
    IRQ     TIM2_IRQHandler
    IRQ     TIM3_IRQHandler
    IRQ     TIM4_IRQHandler
    IRQ     I2C1_EV_IRQHandler
    IRQ     I2C1_ER_IRQHandler
    IRQ     I2C2_EV_IRQHandler
    IRQ     I2C2_ER_IRQHandler
    IRQ     SPI1_IRQHandler
    IRQ     SPI2_IRQHandler
    IRQ     USART1_IRQHandler
    IRQ     USART2_IRQHandler
    IRQ     USART3_IRQHandler
    IRQ     EXTI15_10_IRQHandler
    IRQ     RTCAlarm_IRQHandler
    IRQ     USBWakeUp_IRQHandler

    .end
