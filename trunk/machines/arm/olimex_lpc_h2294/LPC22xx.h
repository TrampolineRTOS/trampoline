#ifndef LPC2294_CONTROL_REGISTERS_DEFINED
#define LPC2294_CONTROL_REGISTERS_DEFINED

//---------------------------------------------------------------------------*

#include "processor-defines.h"

//---------------------------------------------------------------------------*

/* Vectored Interrupt Controller (VIC) */
#define VICIRQStatus   (*((volatile uint32 *) 0xFFFFF000))
#define VICFIQStatus   (*((volatile uint32 *) 0xFFFFF004))
#define VICRawIntr     (*((volatile uint32 *) 0xFFFFF008))
#define VICIntSelect   (*((volatile uint32 *) 0xFFFFF00C))
#define VICIntEnable   (*((volatile uint32 *) 0xFFFFF010))
#define VICIntEnClr    (*((volatile uint32 *) 0xFFFFF014))
#define VICSoftInt     (*((volatile uint32 *) 0xFFFFF018))
#define VICSoftIntClr  (*((volatile uint32 *) 0xFFFFF01C))
#define VICProtection  (*((volatile uint32 *) 0xFFFFF020))
#define VICVectAddr    (*((volatile uint32 *) 0xFFFFF030))
#define VICDefVectAddr (*((volatile uint32 *) 0xFFFFF034))

#define VICVect(INDEX) (*((volatile uint32 *) (0xFFFFF100 + ((INDEX) << 2))))

#define VICVectAddr0   (*((volatile uint32 *) 0xFFFFF100))
#define VICVectAddr1   (*((volatile uint32 *) 0xFFFFF104))
#define VICVectAddr2   (*((volatile uint32 *) 0xFFFFF108))
#define VICVectAddr3   (*((volatile uint32 *) 0xFFFFF10C))
#define VICVectAddr4   (*((volatile uint32 *) 0xFFFFF110))
#define VICVectAddr5   (*((volatile uint32 *) 0xFFFFF114))
#define VICVectAddr6   (*((volatile uint32 *) 0xFFFFF118))
#define VICVectAddr7   (*((volatile uint32 *) 0xFFFFF11C))
#define VICVectAddr8   (*((volatile uint32 *) 0xFFFFF120))
#define VICVectAddr9   (*((volatile uint32 *) 0xFFFFF124))
#define VICVectAddr10  (*((volatile uint32 *) 0xFFFFF128))
#define VICVectAddr11  (*((volatile uint32 *) 0xFFFFF12C))
#define VICVectAddr12  (*((volatile uint32 *) 0xFFFFF130))
#define VICVectAddr13  (*((volatile uint32 *) 0xFFFFF134))
#define VICVectAddr14  (*((volatile uint32 *) 0xFFFFF138))
#define VICVectAddr15  (*((volatile uint32 *) 0xFFFFF13C))

#define VICVectCntl(INDEX) (*((volatile uint32 *) (0xFFFFF200 + ((INDEX) << 2))))

#define VICVectCntl0   (*((volatile uint32 *) 0xFFFFF200))
#define VICVectCntl1   (*((volatile uint32 *) 0xFFFFF204))
#define VICVectCntl2   (*((volatile uint32 *) 0xFFFFF208))
#define VICVectCntl3   (*((volatile uint32 *) 0xFFFFF20C))
#define VICVectCntl4   (*((volatile uint32 *) 0xFFFFF210))
#define VICVectCntl5   (*((volatile uint32 *) 0xFFFFF214))
#define VICVectCntl6   (*((volatile uint32 *) 0xFFFFF218))
#define VICVectCntl7   (*((volatile uint32 *) 0xFFFFF21C))
#define VICVectCntl8   (*((volatile uint32 *) 0xFFFFF220))
#define VICVectCntl9   (*((volatile uint32 *) 0xFFFFF224))
#define VICVectCntl10  (*((volatile uint32 *) 0xFFFFF228))
#define VICVectCntl11  (*((volatile uint32 *) 0xFFFFF22C))
#define VICVectCntl12  (*((volatile uint32 *) 0xFFFFF230))
#define VICVectCntl13  (*((volatile uint32 *) 0xFFFFF234))
#define VICVectCntl14  (*((volatile uint32 *) 0xFFFFF238))
#define VICVectCntl15  (*((volatile uint32 *) 0xFFFFF23C))

/* Watchdog */
#define WDMOD          (*((volatile uint8 *) 0xE0000000))
#define WDTC           (*((volatile uint32 *) 0xE0000004))
#define WDFEED         (*((volatile uint8 *) 0xE0000008))
#define WDTV           (*((volatile uint32 *) 0xE000000C))

/* Pin Connect Block */
#define PINSEL0        (*((volatile uint32 *) 0xE002C000))
#define PINSEL1        (*((volatile uint32 *) 0xE002C004))
#define	PINSEL2		     (*((volatile uint32 *) 0xE002C014))

/* General Purpose Input/Output (GPIO) */
#define IO0PIN          (*((volatile uint32 *) 0xE0028000))
#define IO0SET          (*((volatile uint32 *) 0xE0028004))
#define IO0DIR          (*((volatile uint32 *) 0xE0028008))
#define IO0CLR          (*((volatile uint32 *) 0xE002800C))
#define IO1PIN          (*((volatile uint32 *) 0xE0028010))
#define IO1SET          (*((volatile uint32 *) 0xE0028014))
#define IO1DIR          (*((volatile uint32 *) 0xE0028018))
#define IO1CLR          (*((volatile uint32 *) 0xE002801C))

/* Memory Accelerator Module (MAM) */
#define MAMCR          (*((volatile uint8 *) 0xE01FC000))
#define MAMTIM         (*((volatile uint8 *) 0xE01FC004))
#define MEMMAP         (*((volatile uint8 *) 0xE01FC040))

/* Phase Locked Loop (PLL) */
#define PLLCON         (*((volatile uint8 *) 0xE01FC080))
#define PLLCFG         (*((volatile uint8 *) 0xE01FC084))
#define PLLSTAT        (*((volatile uint16 *) 0xE01FC088))
#define PLLFEED        (*((volatile uint8 *) 0xE01FC08C))

/* VPB Divider */
#define VPBDIV         (*((volatile uint8 *) 0xE01FC100))

/* Power Control */
#define PCON           (*((volatile uint8 *) 0xE01FC0C0))
#define PCONP          (*((volatile uint32 *) 0xE01FC0C4))

/* External Interrupts */
#define EXTINT         (*((volatile uint8 *) 0xE01FC140))
#define EXTWAKE        (*((volatile uint8 *) 0xE01FC144))
#define EXTMODE        (*((volatile uint8 *) 0xE01FC148))
#define EXTPOLAR       (*((volatile uint8 *) 0xE01FC14C))

/* Timer 0 */
#define TIMER0_IR      (*((volatile uint32 *) 0xE0004000))
#define TIMER0_TCR     (*((volatile uint32 *) 0xE0004004))
#define TIMER0_TC      (*((volatile uint32 *) 0xE0004008))
#define TIMER0_PR      (*((volatile uint32 *) 0xE000400C))
#define TIMER0_PC      (*((volatile uint32 *) 0xE0004010))
#define TIMER0_MCR     (*((volatile uint32 *) 0xE0004014))
#define TIMER0_MR0     (*((volatile uint32 *) 0xE0004018))
#define TIMER0_MR1     (*((volatile uint32 *) 0xE000401C))
#define TIMER0_MR2     (*((volatile uint32 *) 0xE0004020))
#define TIMER0_MR3     (*((volatile uint32 *) 0xE0004024))
#define TIMER0_CCR     (*((volatile uint32 *) 0xE0004028))
#define TIMER0_CR0     (*((volatile uint32 *) 0xE000402C))
#define TIMER0_CR1     (*((volatile uint32 *) 0xE0004030))
#define TIMER0_CR2     (*((volatile uint32 *) 0xE0004034))
#define TIMER0_CR3     (*((volatile uint32 *) 0xE0004038))
#define TIMER0_EMR     (*((volatile uint32 *) 0xE000403C))

/* Timer 1 */
#define TIMER1_IR      (*((volatile uint32 *) 0xE0008000))
#define TIMER1_TCR     (*((volatile uint32 *) 0xE0008004))
#define TIMER1_TC      (*((volatile uint32 *) 0xE0008008))
#define TIMER1_PR      (*((volatile uint32 *) 0xE000800C))
#define TIMER1_PC      (*((volatile uint32 *) 0xE0008010))
#define TIMER1_MCR     (*((volatile uint32 *) 0xE0008014))
#define TIMER1_MR0     (*((volatile uint32 *) 0xE0008018))
#define TIMER1_MR1     (*((volatile uint32 *) 0xE000801C))
#define TIMER1_MR2     (*((volatile uint32 *) 0xE0008020))
#define TIMER1_MR3     (*((volatile uint32 *) 0xE0008024))
#define TIMER1_CCR     (*((volatile uint32 *) 0xE0008028))
#define TIMER1_CR0     (*((volatile uint32 *) 0xE000802C))
#define TIMER1_CR1     (*((volatile uint32 *) 0xE0008030))
#define TIMER1_CR2     (*((volatile uint32 *) 0xE0008034))
#define TIMER1_CR3     (*((volatile uint32 *) 0xE0008038))
#define TIMER1_EMR     (*((volatile uint32 *) 0xE000803C))

/* Pulse Width Modulator (PWM) */
#define PWM_IR         (*((volatile uint32 *) 0xE0014000))
#define PWM_TCR        (*((volatile uint32 *) 0xE0014004))
#define PWM_TC         (*((volatile uint32 *) 0xE0014008))
#define PWM_PR         (*((volatile uint32 *) 0xE001400C))
#define PWM_PC         (*((volatile uint32 *) 0xE0014010))
#define PWM_MCR        (*((volatile uint32 *) 0xE0014014))
#define PWM_MR0        (*((volatile uint32 *) 0xE0014018))
#define PWM_MR1        (*((volatile uint32 *) 0xE001401C))
#define PWM_MR2        (*((volatile uint32 *) 0xE0014020))
#define PWM_MR3        (*((volatile uint32 *) 0xE0014024))
#define PWM_MR4        (*((volatile uint32 *) 0xE0014040))
#define PWM_MR5        (*((volatile uint32 *) 0xE0014044))
#define PWM_MR6        (*((volatile uint32 *) 0xE0014048))
#define PWM_CCR        (*((volatile uint32 *) 0xE0014028))
#define PWM_CR0        (*((volatile uint32 *) 0xE001402C))
#define PWM_CR1        (*((volatile uint32 *) 0xE0014030))
#define PWM_CR2        (*((volatile uint32 *) 0xE0014034))
#define PWM_CR3        (*((volatile uint32 *) 0xE0014038))
#define PWM_EMR        (*((volatile uint32 *) 0xE001403C))
#define PWM_PCR        (*((volatile uint32 *) 0xE001404C))
#define PWM_LER        (*((volatile uint32 *) 0xE0014050))

/* Universal Asynchronous Receiver Transmitter 0 (UART0) */
#define UART0_RBR      (*((volatile uint8 *) 0xE000C000))
#define UART0_THR      (*((volatile uint8 *) 0xE000C000))
#define UART0_IER      (*((volatile uint8 *) 0xE000C004))
#define UART0_IIR      (*((volatile uint8 *) 0xE000C008))
#define UART0_FCR      (*((volatile uint8 *) 0xE000C008))
#define UART0_LCR      (*((volatile uint8 *) 0xE000C00C))
#define UART0_MCR      (*((volatile uint8 *) 0xE000C010))
#define UART0_LSR      (*((volatile uint8 *) 0xE000C014))
#define UART0_MSR      (*((volatile uint8 *) 0xE000C018))
#define UART0_SCR      (*((volatile uint8 *) 0xE000C01C))

#define UART0_DLL      (*((volatile uint8 *) 0xE000C000))
#define UART0_DLM      (*((volatile uint8 *) 0xE000C004))

/* Universal Asynchronous Receiver Transmitter 1 (UART1) */
#define UART1_RBR      (*((volatile uint8 *) 0xE0010000))
#define UART1_THR      (*((volatile uint8 *) 0xE0010000))
#define UART1_IER      (*((volatile uint8 *) 0xE0010004))
#define UART1_IIR      (*((volatile uint8 *) 0xE0010008))
#define UART1_FCR      (*((volatile uint8 *) 0xE0010008))
#define UART1_LCR      (*((volatile uint8 *) 0xE001000C))
#define UART1_MCR      (*((volatile uint8 *) 0xE0010010))
#define UART1_LSR      (*((volatile uint8 *) 0xE0010014))
#define UART1_MSR      (*((volatile uint8 *) 0xE0010018))
#define UART1_SCR      (*((volatile uint8 *) 0xE001001C))

#define UART1_DLL      (*((volatile uint8 *) 0xE0010000))
#define UART1_DLM      (*((volatile uint8 *) 0xE0010004))

/* I2C Interface */
#define I2C_I2CONSET   (*((volatile uint8 *) 0xE001C000))
#define I2C_I2STAT     (*((volatile uint8 *) 0xE001C004))
#define I2C_I2DAT      (*((volatile uint8 *) 0xE001C008))
#define I2C_I2ADR      (*((volatile uint8 *) 0xE001C00C))
#define I2C_I2SCLH     (*((volatile uint16*) 0xE001C010))
#define I2C_I2SCLL     (*((volatile uint16*) 0xE001C014))
#define I2C_I2CONCLR   (*((volatile uint8 *) 0xE001C018))

/* SPI (Serial Peripheral Interface) */
#define SPI_SPCR       (*((volatile uint8 *) 0xE0020000))
#define SPI_SPSR       (*((volatile uint8 *) 0xE0020004))
#define SPI_SPDR       (*((volatile uint8 *) 0xE0020008))
#define SPI_SPCCR      (*((volatile uint8 *) 0xE002000C))
#define SPI_SPTCR      (*((volatile uint8 *) 0xE0020010))
#define SPI_SPTSR      (*((volatile uint8 *) 0xE0020014))
#define SPI_SPTOR      (*((volatile uint8 *) 0xE0020018))
#define SPI_SPINT      (*((volatile uint8 *) 0xE002001C))

/* Real Time Clock */
#define RTC_ILR        (*((volatile uint8 *) 0xE0024000))
#define RTC_CTC        (*((volatile uint16*) 0xE0024004))
#define RTC_CCR        (*((volatile uint8 *) 0xE0024008))
#define RTC_CIIR       (*((volatile uint8 *) 0xE002400C))
#define RTC_AMR        (*((volatile uint8 *) 0xE0024010))
#define RTC_CTIME0     (*((volatile uint32 *) 0xE0024014))
#define RTC_CTIME1     (*((volatile uint32 *) 0xE0024018))
#define RTC_CTIME2     (*((volatile uint32 *) 0xE002401C))
#define RTC_SEC        (*((volatile uint8 *) 0xE0024020))
#define RTC_MIN        (*((volatile uint8 *) 0xE0024024))
#define RTC_HOUR       (*((volatile uint8 *) 0xE0024028))
#define RTC_DOM        (*((volatile uint8 *) 0xE002402C))
#define RTC_DOW        (*((volatile uint8 *) 0xE0024030))
#define RTC_DOY        (*((volatile uint16*) 0xE0024034))
#define RTC_MONTH      (*((volatile uint8 *) 0xE0024038))
#define RTC_YEAR       (*((volatile uint16*) 0xE002403C))
#define RTC_ALSEC      (*((volatile uint8 *) 0xE0024060))
#define RTC_ALMIN      (*((volatile uint8 *) 0xE0024064))
#define RTC_ALHOUR     (*((volatile uint8 *) 0xE0024068))
#define RTC_ALDOM      (*((volatile uint8 *) 0xE002406C))
#define RTC_ALDOW      (*((volatile uint8 *) 0xE0024070))
#define RTC_ALDOY      (*((volatile uint16*) 0xE0024074))
#define RTC_ALMON      (*((volatile uint8 *) 0xE0024078))
#define RTC_ALYEAR     (*((volatile uint16*) 0xE002407C))
#define RTC_PREINT     (*((volatile uint16*) 0xE0024080))
#define RTC_PREFRAC    (*((volatile uint16*) 0xE0024084))

/* Bank Configuration registers */
#define BCFG0          (*((volatile uint32 *) 0xFFE00000))
#define BCFG1          (*((volatile uint32 *) 0xFFE00004))
#define BCFG2          (*((volatile uint32 *) 0xFFE00008))
#define BCFG3          (*((volatile uint32 *) 0xFFE0000C))

/* CAN Controllers */
#define CAN_AMFR          (*((volatile uint32 *) 0xE003C000))
#define CAN_SFF_SA        (*((volatile uint32 *) 0xE003C004))
#define CAN_SFF_GRP_SA    (*((volatile uint32 *) 0xE003C008))
#define CAN_EFF_SA        (*((volatile uint32 *) 0xE003C00C))
#define CAN_EFF_GRP_SA    (*((volatile uint32 *) 0xE003C010))
#define CAN_END_OF_TABLES (*((volatile uint32 *) 0xE003C014))


//---------------------------------------------------------------------------*

#endif
