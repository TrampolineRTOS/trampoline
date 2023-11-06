#ifndef _BCM2836_H_
#define _BCM2836_H_

#include "tpl_os.h"
#include <stdint.h>

#define BCM2836_PERIPH_BASE	(0x3F000000)
#define PERIPH_BASE         BCM2836_PERIPH_BASE

#define GPIO_OFFSET (0x00200000)
#define GPIO_BASE	 (PERIPH_BASE + GPIO_OFFSET)

#define BCM2836_CLOCK_FREQ (250000000)

/*****************************************************************************
 *                        General Purpose I/O (GPIO)
 *****************************************************************************/
/* -------- GPIO Registers -------- */
#define GPSET0            (GPIO_BASE + 0x0000001C)
#define GPSET1            (GPIO_BASE + 0x00000020)
#define GPCLR0            (GPIO_BASE + 0x00000028)
#define GPCLR1            (GPIO_BASE + 0x0000002C)
#define GPLEV0            (GPIO_BASE + 0x00000034)
#define GPLEV1            (GPIO_BASE + 0x00000038)

#define GPFSEL0           (GPIO_BASE + 0x00000000)
#define GPFSEL1           (GPIO_BASE + 0x00000004)
#define GPFSEL2           (GPIO_BASE + 0x00000008)
#define GPFSEL3           (GPIO_BASE + 0x0000000C)
#define GPFSEL4           (GPIO_BASE + 0x00000010)
#define GPFSEL5           (GPIO_BASE + 0x00000014)

#define GPPUD             (GPIO_BASE + 0x00000094)
#define GPPUDCLK0         (GPIO_BASE + 0x00000098)
#define GPPUDCLK1         (GPIO_BASE + 0x0000009C)

#define GPIO_PUD_OFF      0x00
#define GPIO_PUD_TRISTATE 0x00
#define GPIO_PUD_PULLDOWN 0x01
#define GPIO_PUD_PULLUP   0x02

/* -------- GPIO Functions -------- */
#define GPFN_IN           0x00
#define GPFN_OUT          0x01
#define GPFN_ALT0         0x04
#define GPFN_ALT1         0x05
#define GPFN_ALT2         0x06
#define GPFN_ALT3         0x07
#define GPFN_ALT4         0x03
#define GPFN_ALT5         0x02

#define GPIO0_PAD       0
#define GPIO1_PAD       1
#define GPIO2_PAD       2
#define GPIO3_PAD       3
#define GPIO4_PAD       4
#define GPIO5_PAD       5
#define GPIO6_PAD       6
#define GPIO7_PAD       7
#define GPIO8_PAD       8
#define GPIO9_PAD       9
#define GPIO10_PAD      10
#define GPIO11_PAD      11
#define GPIO12_PAD      12
#define GPIO13_PAD      13
#define GPIO14_PAD      14
#define GPIO15_PAD      15
#define GPIO16_PAD      16
#define GPIO17_PAD      17
#define GPIO18_PAD      18
#define GPIO19_PAD      19
#define GPIO20_PAD      20
#define GPIO21_PAD      21
#define GPIO22_PAD      22
#define GPIO23_PAD      23
#define GPIO24_PAD      24
#define GPIO25_PAD      25
#define GPIO26_PAD      26
#define GPIO27_PAD      27
#define GPIO28_PAD      28
#define GPIO29_PAD      29
#define GPIO30_PAD      30
#define GPIO31_PAD      31
#define GPIO32_PAD      0
#define GPIO33_PAD      1
#define GPIO34_PAD      2
#define GPIO35_PAD      3
#define GPIO36_PAD      4
#define GPIO37_PAD      5
#define GPIO38_PAD      6
#define GPIO39_PAD      7
#define GPIO40_PAD      8
#define GPIO41_PAD      9
#define GPIO42_PAD      10
#define GPIO43_PAD      11
#define GPIO44_PAD      12
#define GPIO45_PAD      13
#define GPIO46_PAD      14
#define GPIO47_PAD      15
#define GPIO48_PAD      16
#define GPIO49_PAD      17
#define GPIO50_PAD      18
#define GPIO51_PAD      19
#define GPIO52_PAD      20
#define GPIO53_PAD      21

#define GPIO0_PORT      &IOPORT0
#define GPIO1_PORT      &IOPORT0
#define GPIO2_PORT      &IOPORT0
#define GPIO3_PORT      &IOPORT0
#define GPIO4_PORT      &IOPORT0
#define GPIO5_PORT      &IOPORT0
#define GPIO6_PORT      &IOPORT0
#define GPIO7_PORT      &IOPORT0
#define GPIO8_PORT      &IOPORT0
#define GPIO9_PORT      &IOPORT0
#define GPIO10_PORT     &IOPORT0
#define GPIO11_PORT     &IOPORT0
#define GPIO12_PORT     &IOPORT0
#define GPIO13_PORT     &IOPORT0
#define GPIO14_PORT     &IOPORT0
#define GPIO15_PORT     &IOPORT0
#define GPIO16_PORT     &IOPORT0
#define GPIO17_PORT     &IOPORT0
#define GPIO18_PORT     &IOPORT0
#define GPIO19_PORT     &IOPORT0
#define GPIO20_PORT     &IOPORT0
#define GPIO21_PORT     &IOPORT0
#define GPIO22_PORT     &IOPORT0
#define GPIO23_PORT     &IOPORT0
#define GPIO24_PORT     &IOPORT0
#define GPIO25_PORT     &IOPORT0
#define GPIO26_PORT     &IOPORT0
#define GPIO27_PORT     &IOPORT0
#define GPIO28_PORT     &IOPORT0
#define GPIO29_PORT     &IOPORT0
#define GPIO30_PORT     &IOPORT0
#define GPIO31_PORT     &IOPORT0
#define GPIO32_PORT     &IOPORT1
#define GPIO33_PORT     &IOPORT1
#define GPIO34_PORT     &IOPORT1
#define GPIO35_PORT     &IOPORT1
#define GPIO36_PORT     &IOPORT1
#define GPIO37_PORT     &IOPORT1
#define GPIO38_PORT     &IOPORT1
#define GPIO39_PORT     &IOPORT1
#define GPIO40_PORT     &IOPORT1
#define GPIO41_PORT     &IOPORT1
#define GPIO42_PORT     &IOPORT1
#define GPIO43_PORT     &IOPORT1
#define GPIO44_PORT     &IOPORT1
#define GPIO45_PORT     &IOPORT1
#define GPIO46_PORT     &IOPORT1
#define GPIO47_PORT     &IOPORT1
#define GPIO48_PORT     &IOPORT1
#define GPIO49_PORT     &IOPORT1
#define GPIO50_PORT     &IOPORT1
#define GPIO51_PORT     &IOPORT1
#define GPIO52_PORT     &IOPORT1
#define GPIO53_PORT     &IOPORT1

/*****************************************************************************
 *                        AUX
 *
 * Cf BCM2835 documentation.
 *
 *****************************************************************************/
#define AUX_BASE        (PERIPH_BASE+0x00215000)
#define AUX_ENABLES     (AUX_BASE+0x00000004)
#define AUX_MU_IO_REG   (AUX_BASE+0x00000040)
#define AUX_MU_IER_REG  (AUX_BASE+0x00000044)
#define AUX_MU_IIR_REG  (AUX_BASE+0x00000048)
#define AUX_MU_LCR_REG  (AUX_BASE+0x0000004C)
#define AUX_MU_MCR_REG  (AUX_BASE+0x00000050)
#define AUX_MU_LSR_REG  (AUX_BASE+0x00000054)
#define AUX_MU_MSR_REG  (AUX_BASE+0x00000058)
#define AUX_MU_SCRATCH  (AUX_BASE+0x0000005C)
#define AUX_MU_CNTL_REG (AUX_BASE+0x00000060)
#define AUX_MU_STAT_REG (AUX_BASE+0x00000064)
#define AUX_MU_BAUD_REG (AUX_BASE+0x00000068)

/*****************************************************************************
 *                        UART
 *
 * Cf BCM2835 documentation, chapter 13, page 175.
 *
 *****************************************************************************/
/* The base address for UART */
#define UART0_OFFSET (0x00001000)
#define UART0_BASE   (GPIO_BASE + UART0_OFFSET)

#define UART0_DR     (UART0_BASE + 0x00000000) /* Data register */
#define UART0_RSRECR (UART0_BASE + 0x00000004) /* Receive status register/error clear register */
#define UART0_FR     (UART0_BASE + 0x00000018)  /* Flag register */
#define UART0_ILPR   (UART0_BASE + 0x00000020) /* Apparently unused according to the documentation */
#define UART0_IBRD   (UART0_BASE + 0x00000024) /* Integer baud rate divisor */
#define UART0_FBRD   (UART0_BASE + 0x00000028) /* Fractional baud rate divisor */
#define UART0_LCRH   (UART0_BASE + 0x0000002C) /* Line control register */
#define UART0_CR     (UART0_BASE + 0x00000030) /* Control register */
#define UART0_IFLS   (UART0_BASE + 0x00000034) /* Interrupt FIFO level select register */
#define UART0_IMSC   (UART0_BASE + 0x00000038) /* Interrupt mask set clear register */
#define UART0_RIS    (UART0_BASE + 0x0000003C) /* Raw interrupt status register */
#define UART0_MIS    (UART0_BASE + 0x00000040) /* Masked interrupt status register */
#define UART0_ICR    (UART0_BASE + 0x00000044) /* Interrupt clear register */
#define UART0_DMACR  (UART0_BASE + 0x00000048) /* DMA control register */
#define UART0_ITCR   (UART0_BASE + 0x00000080) /* Test control register */
#define UART0_ITIP   (UART0_BASE + 0x00000084) /* Integration test input register */
#define UART0_ITOP   (UART0_BASE + 0x00000088) /* Integration test output register */
#define UART0_TDR    (UART0_BASE + 0x0000008C) /* Test data register */


/*****************************************************************************
 *                          ARM Timer
 *
 *****************************************************************************/
#define ARM_TIMER_BASE (PERIPH_BASE + 0x0000B400)
#define ARM_TIMER_LOD  (ARM_TIMER_BASE + 0x00000000)
#define ARM_TIMER_VAL  (ARM_TIMER_BASE + 0x00000004)
#define ARM_TIMER_CTL  (ARM_TIMER_BASE + 0x00000008)
#define ARM_TIMER_CLI  (ARM_TIMER_BASE + 0x0000000C)
#define ARM_TIMER_RIS  (ARM_TIMER_BASE + 0x00000010)
#define ARM_TIMER_MIS  (ARM_TIMER_BASE + 0x00000014)
#define ARM_TIMER_RLD  (ARM_TIMER_BASE + 0x00000018)
#define ARM_TIMER_DIV  (ARM_TIMER_BASE + 0x0000001C)
#define ARM_TIMER_CNT  (ARM_TIMER_BASE + 0x00000020)

/*****************************************************************************
 *                          System Timer
 *
 *****************************************************************************/
#define SYSTIMER_BASE       (PERIPH_BASE + 0x00003000)

#define SYSTIMER_CS         (SYSTIMER_BASE + 0x00000000)
#define SYSTIMER_CLO        (SYSTIMER_BASE + 0x00000004)
#define SYSTIMER_CHI        (SYSTIMER_BASE + 0x00000008)

#define SYSTIMER_CMP0       (SYSTIMER_BASE + 0x0000000C)
#define SYSTIMER_CMP1       (SYSTIMER_BASE + 0x00000010)
#define SYSTIMER_CMP2       (SYSTIMER_BASE + 0x00000014)
#define SYSTIMER_CMP3       (SYSTIMER_BASE + 0x00000018)

#define SYSTIMER_CS_MATCH0  0x01
#define SYSTIMER_CS_MATCH1  0x02
#define SYSTIMER_CS_MATCH2  0x04
#define SYSTIMER_CS_MATCH3  0x08

#define SYSTIMER_IRQEN0     0x01
#define SYSTIMER_IRQEN1     0x02
#define SYSTIMER_IRQEN2     0x04
#define SYSTIMER_IRQEN3     0x08

#define SYSTIMER_CLOCK_FREQ 1000000

/*****************************************************************************
 *                          Interrupts
 *
 *****************************************************************************/
#define IRQ_BASIC         (PERIPH_BASE + 0x0000B200)
#define IRQ_PEND1         (PERIPH_BASE + 0x0000B204)
#define IRQ_PEND2         (PERIPH_BASE + 0x0000B208)
#define IRQ_FIQ_CONTROL   (PERIPH_BASE + 0x0000B210)
#define IRQ_ENABLE1       (PERIPH_BASE + 0x0000B210)
#define IRQ_ENABLE2       (PERIPH_BASE + 0x0000B214)
#define IRQ_ENABLE_BASIC  (PERIPH_BASE + 0x0000B218)
#define IRQ_DISABLE1      (PERIPH_BASE + 0x0000B21C)
#define IRQ_DISABLE2      (PERIPH_BASE + 0x0000B220)
#define IRQ_DISABLE_BASIC (PERIPH_BASE + 0x0000B224)

#define SPI_IRQ           BIT(22)

/*****************************************************************************
 *                          I2C / BSC
 *
 *****************************************************************************/
struct bscdevice_t {
  volatile unsigned int control;
  volatile unsigned int status;
  volatile unsigned int dataLength;
  volatile unsigned int slaveAddress;
  volatile unsigned int dataFifo;
  volatile unsigned int clockDivider;
  volatile unsigned int dataDelay;
  volatile unsigned int clockStretchTimeout;
};

typedef struct bscdevice_t bscdevice_t;

/* Only BSC0 is accessible from the RPi pi header.*/
#define BSC0_ADDR ((bscdevice_t *)0x00205000)
#define BSC1_ADDR ((bscdevice_t *)0x20804000)
#define BSC2_ADDR ((bscdevice_t *)0x20805000)

#define BSC_CLOCK_FREQ 150000000

/* I2C control flags */
#define BSC_I2CEN BIT(15)
#define BSC_INTR  BIT(10)
#define BSC_INTT  BIT(9)
#define BSC_INTD  BIT(8)
#define BSC_ST    BIT(7)
#define BSC_CLEAR BIT(4)
#define BSC_READ  BIT(0)

/* I2C status flags */
#define BSC_TA   BIT(0) /** @brief Transfer active.*/
#define BSC_DONE BIT(1) /** @brief Transfer done.*/
#define BSC_TXW  BIT(2) /** @brief FIFO needs writing.*/
#define BSC_RXR  BIT(3) /** @brief FIFO needs reading.*/
#define BSC_TXD  BIT(4) /** @brief FIFO can accept data.*/
#define BSC_RXD  BIT(5) /** @brief FIFO contains data.*/
#define BSC_TXE  BIT(6) /** @brief FIFO empty.*/
#define BSC_RXF  BIT(7) /** @brief FIFO full.*/
#define BSC_ERR  BIT(8) /** @brief ACK error.*/
#define BSC_CLKT BIT(9) /** @brief Clock stretch timeout.*/

/* Rising/Falling Edge Delay Defaults.*/
#define BSC_DEFAULT_FEDL       0x30
#define BSC_DEFAULT_REDL       0x30

/* Clock Stretch Timeout Defaults.*/
#define BSC_DEFAULT_CLKT       0x40

#define CLEAR_STATUS  BSC_CLKT|BSC_ERR|BSC_DONE

#define START_READ    BSC_I2CEN|BSC_ST|BSC_CLEAR|BSC_READ
#define START_WRITE   BSC_I2CEN|BSC_ST

/*****************************************************************************
 *                          SPI
 *
 *****************************************************************************/
#define SPI0_CS        (GPIO_BASE + 0x00204000) /* @brief SPI Master Control and Status.*/
#define SPI0_FIFO      (GPIO_BASE + 0x00204004) /* @brief SPI Master TX and RX FIFOs.*/
#define SPI0_CLK       (GPIO_BASE + 0x00204008) /* @brief SPI Master Clock Divider.*/
#define SPI0_DLEN      (GPIO_BASE + 0x0020400C) /* @brief SPI Master Data Length.*/
#define SPI0_LTOH      (GPIO_BASE + 0x00204010) /* @brief SPI LOSSI mode TOH.*/
#define SPI0_DC        (GPIO_BASE + 0x00204014) /* @brief SPI DMA DREQ Controls.*/

/* Register masks for SPI0_CS */
#define SPI_CS_LEN_LONG             0x02000000 /* @brief Enable Long data word in Lossi mode if DMA_LEN is set.*/
#define SPI_CS_DMA_LEN              0x01000000 /* @brief Enable DMA mode in Lossi mode.*/
#define SPI_CS_CSPOL2               0x00800000 /* @brief Chip Select 2 Polarity.*/
#define SPI_CS_CSPOL1               0x00400000 /* @brief Chip Select 1 Polarity.*/
#define SPI_CS_CSPOL0               0x00200000 /* @brief Chip Select 0 Polarity.*/
#define SPI_CS_RXF                  0x00100000 /* @brief RXF - RX FIFO Full.*/
#define SPI_CS_RXR                  0x00080000 /* @brief RXR RX FIFO needs Reading ( full).*/
#define SPI_CS_TXD                  0x00040000 /* @brief TXD TX FIFO can accept Data.*/
#define SPI_CS_RXD                  0x00020000 /* @brief RXD RX FIFO contains Data.*/
#define SPI_CS_DONE                 0x00010000 /* @brief Done transfer Done.*/
#define SPI_CS_TE_EN                0x00008000 /* @brief Unused.*/
#define SPI_CS_LMONO                0x00004000 /* @brief Unused.*/
#define SPI_CS_LEN                  0x00002000 /* @brief LEN LoSSI enable.*/
#define SPI_CS_REN                  0x00001000 /* @brief REN Read Enable.*/
#define SPI_CS_ADCS                 0x00000800 /* @brief ADCS Automatically Deassert Chip Select.*/
#define SPI_CS_INTR                 0x00000400 /* @brief INTR Interrupt on RXR.*/
#define SPI_CS_INTD                 0x00000200 /* @brief INTD Interrupt on Done.*/
#define SPI_CS_DMAEN                0x00000100 /* @brief DMAEN DMA Enable.*/
#define SPI_CS_TA                   0x00000080 /* @brief Transfer Active.*/
#define SPI_CS_CSPOL                0x00000040 /* @brief Chip Select Polarity.*/
#define SPI_CS_CLEAR                0x00000030 /* @brief Clear FIFO Clear RX and TX.*/
#define SPI_CS_CLEAR_RX             0x00000020 /* @brief Clear FIFO Clear RX .*/
#define SPI_CS_CLEAR_TX             0x00000010 /* @brief Clear FIFO Clear TX .*/
#define SPI_CS_CPOL                 0x00000008 /* @brief Clock Polarity.*/
#define SPI_CS_CPHA                 0x00000004 /* @brief Clock Phase.*/
#define SPI_CS_CS                   0x00000003 /* @brief Chip Select.*/

/*****************************************************************************
 *                          PWM
 *
 *****************************************************************************/
#define PWM_CTL        (GPIO_BASE + 0x0020C000)
#define PWM_STATUS     (GPIO_BASE + 0x0020C004)

#define PWM0_RANGE     (GPIO_BASE + 0x0020C010)
#define PWM0_DATA      (GPIO_BASE + 0x0020C014)

#define PWM1_RANGE     (GPIO_BASE + 0x0020C020)
#define PWM1_DATA      (GPIO_BASE + 0x0020C024)

#define PWM0_ENABLE    BIT(0)
#define PWM0_MODE_MS   BIT(7)

#define PWM1_ENABLE    BIT(8)
#define PWM1_MODE_MS   BIT(15)

#define PWM_MODE_MS    0xFF

#define GPIO_CLK_PWD   0x5a000000

#define GPIO0_CLK_CTL  (GPIO_BASE + 0x001010A0)
#define GPIO0_CLK_DIV  (GPIO_BASE + 0x001010A4)

/*****************************************************************************
 *                          Power Management
 *                          Watchdog
 *                          Reset
 *
 *****************************************************************************/
#define PM_BASE                  (PERIPH_BASE+0x00100000)
#define PM_RSTC                  (PM_BASE+0x1c)
#define PM_WDOG                  (PM_BASE+0x24)

#define PM_WDOG_RESET            0000000000
#define PM_PASSWORD              0x5a000000
#define PM_WDOG_TIME_SET         0x000fffff
#define PM_RSTC_WRCFG_CLR        0xffffffcf
#define PM_RSTC_WRCFG_SET        0x00000030
#define PM_RSTC_WRCFG_FULL_RESET 0x00000020
#define PM_RSTC_RESET            0x00000102

/*****************************************************************************
 *                          Mailboxes
 *
 *****************************************************************************/
#define CONTROL_BASE        0x40000000
/* Timers interrupt control registers */
#define CORE0_TIMER_IRQCNTL (CONTROL_BASE + 0x00000040)
#define CORE1_TIMER_IRQCNTL (CONTROL_BASE + 0x00000044)
#define CORE2_TIMER_IRQCNTL (CONTROL_BASE + 0x00000048)
#define CORE3_TIMER_IRQCNTL (CONTROL_BASE + 0x0000004C)

/* Where to route timer interrupt to, IRQ/FIQ
 * Setting both the IRQ and FIQ bit gives an FIQ
 */
#define TIMER0_IRQ          0x01
#define TIMER1_IRQ          0x02
#define TIMER2_IRQ          0x04
#define TIMER3_IRQ          0x08
#define TIMER0_FIQ          0x10
#define TIMER1_FIQ          0x20
#define TIMER2_FIQ          0x40
#define TIMER3_FIQ          0x80

/* Mailbox interrupt control registers */
#define CORE0_MBOX_IRQCNTL  (CONTROL_BASE + 0x00000050)
#define CORE1_MBOX_IRQCNTL  (CONTROL_BASE + 0x00000054)
#define CORE2_MBOX_IRQCNTL  (CONTROL_BASE + 0x00000058)
#define CORE3_MBOX_IRQCNTL  (CONTROL_BASE + 0x0000005C)

/* Where to route mailbox interrupt to, IRQ/FIQ
 * Setting both the IRQ and FIQ bit gives an FIQ
 */
#define MBOX0_IRQ           0x01
#define MBOX1_IRQ           0x02
#define MBOX2_IRQ           0x04
#define MBOX3_IRQ           0x08
#define MBOX0_FIQ           0x10
#define MBOX1_FIQ           0x20
#define MBOX2_FIQ           0x40
#define MBOX3_FIQ           0x80

/* IRQ & FIQ source registers */
#define CORE0_IRQ_SOURCE    (CONTROL_BASE + 0x00000060)
#define CORE1_IRQ_SOURCE    (CONTROL_BASE + 0x00000064)
#define CORE2_IRQ_SOURCE    (CONTROL_BASE + 0x00000068)
#define CORE3_IRQ_SOURCE    (CONTROL_BASE + 0x0000006C)
#define CORE0_FIQ_SOURCE    (CONTROL_BASE + 0x00000070)
#define CORE1_FIQ_SOURCE    (CONTROL_BASE + 0x00000074)
#define CORE2_FIQ_SOURCE    (CONTROL_BASE + 0x00000078)
#define CORE3_FIQ_SOURCE    (CONTROL_BASE + 0x0000007C)

/* Interrupt source bits
 * IRQ and FIQ are the same
 * GPU bits can be set for one core only
 */
#define INT_SRC_TIMER0      0x00000001
#define INT_SRC_TIMER1      0x00000002
#define INT_SRC_TIMER2      0x00000004
#define INT_SRC_TIMER3      0x00000008
#define INT_SRC_MBOX0       0x00000010
#define INT_SRC_MBOX1       0x00000020
#define INT_SRC_MBOX2       0x00000040
#define INT_SRC_MBOX3       0x00000080
#define INT_SRC_GPU         0x00000100
#define INT_SRC_PMU         0x00000200

/* Mailbox write-set registers (Write only) */
#define CORE0_MBOX0_SET     (CONTROL_BASE + 0x00000080)
#define CORE0_MBOX1_SET     (CONTROL_BASE + 0x00000084)
#define CORE0_MBOX2_SET     (CONTROL_BASE + 0x00000088)
#define CORE0_MBOX3_SET     (CONTROL_BASE + 0x0000008C)
#define CORE1_MBOX0_SET     (CONTROL_BASE + 0x00000090)
#define CORE1_MBOX1_SET     (CONTROL_BASE + 0x00000094)
#define CORE1_MBOX2_SET     (CONTROL_BASE + 0x00000098)
#define CORE1_MBOX3_SET     (CONTROL_BASE + 0x0000009C)
#define CORE2_MBOX0_SET     (CONTROL_BASE + 0x000000A0)
#define CORE2_MBOX1_SET     (CONTROL_BASE + 0x000000A4)
#define CORE2_MBOX2_SET     (CONTROL_BASE + 0x000000A8)
#define CORE2_MBOX3_SET     (CONTROL_BASE + 0x000000AC)
#define CORE3_MBOX0_SET     (CONTROL_BASE + 0x000000B0)
#define CORE3_MBOX1_SET     (CONTROL_BASE + 0x000000B4)
#define CORE3_MBOX2_SET     (CONTROL_BASE + 0x000000B8)
#define CORE3_MBOX3_SET     (CONTROL_BASE + 0x000000BC)

/* Mailbox write-clear registers (Read & Write) */
#define CORE0_MBOX0_RDCLR   (CONTROL_BASE + 0x000000C0)
#define CORE0_MBOX1_RDCLR   (CONTROL_BASE + 0x000000C4)
#define CORE0_MBOX2_RDCLR   (CONTROL_BASE + 0x000000C8)
#define CORE0_MBOX3_RDCLR   (CONTROL_BASE + 0x000000CC)
#define CORE1_MBOX0_RDCLR   (CONTROL_BASE + 0x000000D0)
#define CORE1_MBOX1_RDCLR   (CONTROL_BASE + 0x000000D4)
#define CORE1_MBOX2_RDCLR   (CONTROL_BASE + 0x000000D8)
#define CORE1_MBOX3_RDCLR   (CONTROL_BASE + 0x000000DC)
#define CORE2_MBOX0_RDCLR   (CONTROL_BASE + 0x000000E0)
#define CORE2_MBOX1_RDCLR   (CONTROL_BASE + 0x000000E4)
#define CORE2_MBOX2_RDCLR   (CONTROL_BASE + 0x000000E8)
#define CORE2_MBOX3_RDCLR   (CONTROL_BASE + 0x000000EC)
#define CORE3_MBOX0_RDCLR   (CONTROL_BASE + 0x000000F0)
#define CORE3_MBOX1_RDCLR   (CONTROL_BASE + 0x000000F4)
#define CORE3_MBOX2_RDCLR   (CONTROL_BASE + 0x000000F8)
#define CORE3_MBOX3_RDCLR   (CONTROL_BASE + 0x000000FC)

#endif /* _BCM2836_H_ */
