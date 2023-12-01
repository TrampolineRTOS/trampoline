#ifndef SERIAL_H
#define SERIAL_H

#include "tpl_os.h"

#if __arm__
/* SCIF3 */
#define SCIF_BASE_ADDR                      0xE6C50000
/* HSCIF0 */
#define HSCIF_BASE_ADDR                     0xE6540000
#else
/* SCIF3 */
#define SCIF_BASE_ADDR                      0xD6C50000
/* HSCIF0 */
#define HSCIF_BASE_ADDR                     0xD6540000
#endif

/* BRR computing:
 *   HSBRR: Register value = Internal clock / ( Sr * 2^(2*n + 1) * B) * 10^6 -1
 *   SCBRR: Register value = PCK / ( 64 * 2^(2*n - 1) * B) * 10^6 -1
 *
 *   with:
 *     - PCK: Peripheral module operating frequency (MHz)
 *     - B: Baudrate
 *     - Sr: Sampling rate (8 to 32)
 *     - n: Baudrate generator clock (0 to 3)
 *
 *   In our case:  Internal clock = 266, Sr = 8, PCK = 66 and n = 0
 */
#define HSBRR_1843200BPS              (uint8)(0x08U)
#define HSBRR_921600BPS               (uint8)(0x11U)
#define SCBRR_115200BPS               (uint8)(0x11U)

/* A proper #define must be used between: SCIF_115200BPS, HSCIF_921600BPS and HSCIF_1843200BPS */
#if defined SCIF_115200BPS
#define SERIAL_BASE_ADDR                     SCIF_BASE_ADDR
#define SERIAL_BAUDRATE                      SCBRR_115200BPS
#elif defined HSCIF_921600BPS
#define SERIAL_BASE_ADDR                     HSCIF_BASE_ADDR
#define SERIAL_BAUDRATE                      HSBRR_921600BPS
#elif defined HSCIF_1843200BPS
#define SERIAL_BASE_ADDR                     HSCIF_BASE_ADDR
#define SERIAL_BAUDRATE                      HSBRR_1843200BPS
#else
#error "No baudrate defined for serial communication"
#endif

#define SERIAL_SMR        (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x00))
#define SERIAL_BRR        (*(volatile uint8  *)(SERIAL_BASE_ADDR + 0x04))
#define SERIAL_SCR        (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x08))
#define SERIAL_FTDR       (*(volatile uint8  *)(SERIAL_BASE_ADDR + 0x0C))
#define SERIAL_FSR        (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x10))
#define SERIAL_FRDR       (*(volatile uint8  *)(SERIAL_BASE_ADDR + 0x14))
#define SERIAL_FCR        (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x18))
#define SERIAL_FDR        (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x1C))
#define SERIAL_SPTR       (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x20))
#define SERIAL_LSR        (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x24))
#define SERIAL_DL         (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x30)) /* Only used by SCIF */
#define SERIAL_CKS        (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x34)) /* Only used by SCIF */
#define SERIAL_SRR        (*(volatile uint16 *)(SERIAL_BASE_ADDR + 0x40)) /* Only used by HSCIF */

#define SERIAL_SMR_INIT_VALUE       (0x0000U)

#define SERIAL_SCR_INT_VALUE        (0x0000U)
#define SERIAL_SCR_CKE_MASK         (3U << 0)
#define SERIAL_SCR_CKE_BRG_VALUE    (0x0002U)
#define SERIAL_SCR_CKE_INIT_VALUE   (0x0000U)
#define SERIAL_SCR_RE_MASK          (1U << 4)
#define SERIAL_SCR_TE_MASK          (1U << 5)

#define SERIAL_FSR_INIT_VALUE       (0x0000U)
#define SERIAL_FSR_DR_MASK          (1U << 0)
#define SERIAL_FSR_RDF_MASK         (1U << 1)
#define SERIAL_FSR_BRK_MASK         (1U << 4)
#define SERIAL_FSR_TDFE_MASK        (1U << 5)
#define SERIAL_FSR_TEND_MASK        (1U << 6)
#define SERIAL_FSR_ER_MASK          (1U << 7)
#define SERIAL_RX_READY             (SERIAL_FSR_DR_MASK | SERIAL_FSR_BRK_MASK | SERIAL_FSR_ER_MASK)
#define SERIAL_TX_DONE              (SERIAL_FSR_TDFE_MASK | SERIAL_FSR_TEND_MASK)

#define SERIAL_FCR_INIT_VALUE       (0x0000U)
#define SERIAL_FCR_TFRST_MASK       (1U << 2)
#define SERIAL_FCR_RFRS_MASK        (1U << 1)

#define SERIAL_LSR_INIT_VALUE       (0x0000U)

#define SERIAL_DL_SETTING_VALUE     (0x0008U)

#define SERIAL_CKS_DIV_MASK         (1U << 15)
#define SERIAL_CKS_XIN_MASK         (1U << 14)

#define SERIAL_SRR_SRE              (1U << 15)
#define SERIAL_SRR_SRCYC8           (7U << 0)
#define SERIAL_SRR_VAL              (SERIAL_SRR_SRE | SERIAL_SRR_SRCYC8)

uint32 Serial_Init(void);
void Serial_Tx_Wait(void);
uint32 Serial_Tx(uint8 data);
uint8  Serial_Rx(uint8* data);

#endif
