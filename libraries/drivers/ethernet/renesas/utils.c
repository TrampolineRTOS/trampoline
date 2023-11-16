#include "tpl_os.h"
#include "utils.h"
#include "pfcmap.h"

#define ETH_CPUCLK_MHZ 1066UL
#define ETH_WAIT_NS(t) \
    { \
        volatile uint32 cnt; \
        for (cnt = 0; \
             cnt < ((((uint32)ETH_CPUCLK_MHZ * ((uint32)t)) / (uint32)1000) + (uint32)1); \
             cnt++); \
    }

/* Module Standby, Software reset */
#define MSTPCR_ETH_1        (*((volatile uint32 *)0xE6152D3CUL)) /* MSTPCR15 Register */
#define MSTPSR_ETH_1        (*((volatile uint32 *)0xE6152E3CUL)) /* MSTPSR15 Register */
#define MSTP_BIT_ETHIP      (uint32)(1 << 5)
#define MSTP_BIT_ETHPHY     (uint32)(1 << 6)

/* CPG */
#define CPG_CPGWPR          (*((volatile uint32 *)0xE6150000UL)) /* CPGWPR Register used to remove MSTPCR write protection */
#define CKCR_ETH_1          (*((volatile uint32 *)0xE61508E8UL)) /* RSW2CKCR Register */
#define CKCR_BIT_ETHIP      (uint32)(1 << 8)

#define SRCR_ETH_1          (*((volatile uint32 *)0xE6152C3CUL)) /* SRCR15 Register */
#define SRSTCLR_ETH_1       (*((volatile uint32 *)0xE6152CBCUL)) /* SRSTCLCR15 Register */
#define SRCR_BIT_ETHIP      (uint32)(1 << 5)
#define SRCR_BIT_ETHPHY     (uint32)(1 << 6)

void rswitch_enable_clock_and_reset(void)
{
    volatile uint32 regval = 0x0UL;

    /* Enable RSW2 clock by writing 0 to CKCR */
    regval = CKCR_ETH_1;                             /* RSW2CKCR */
    if (regval & CKCR_BIT_ETHIP)                     /* 1: Stops the clock */
    {
        regval &= ~CKCR_BIT_ETHIP;
        CKCR_ETH_1 = regval;                           /* 0: Supplies the clock */
        while (CKCR_ETH_1 & CKCR_BIT_ETHIP);           /* Wait for the register value to change */
    }

    /* Supply RSW2 and ETHPHY clock by writing 0 to MSTPSR */
    regval = MSTPSR_ETH_1;
    if (regval & (MSTP_BIT_ETHIP | MSTP_BIT_ETHPHY)) /* If either one is 1(=Stops the clock), execute the process */
    {
        regval &= ~(MSTP_BIT_ETHIP | MSTP_BIT_ETHPHY);
        CPG_CPGWPR = ~regval;                          /* Release MSTPCR write protection by writing the inverse of the value to CPGWPR */
        MSTPCR_ETH_1 = regval;                         /* 0: Supplies the clock */
        while (MSTPSR_ETH_1 & (MSTP_BIT_ETHIP | MSTP_BIT_ETHPHY)); /* Wait for the register value to change */
    }

    /* Reset RSW2 and ETHPHY by writing 1 to SRCR */
    CPG_CPGWPR = ~(SRCR_BIT_ETHIP | SRCR_BIT_ETHPHY); /* Release SRCR write protection by writing the inverse of the value to CPGWR */
    SRCR_ETH_1 = (uint32)(SRCR_BIT_ETHIP | SRCR_BIT_ETHPHY); /* SRCR does not require read-modify write */
    ETH_WAIT_NS(20*1000);

    /* Release the reset RSW2 and ETHPHY by writing 1 to SRSTCLR */
    CPG_CPGWPR = ~(SRCR_BIT_ETHIP | SRCR_BIT_ETHPHY); /* Release SRSTCLR write protection by writing the inverse of the value to CPGWR */
    SRSTCLR_ETH_1 = (uint32)(SRCR_BIT_ETHIP | SRCR_BIT_ETHPHY); /* SRSTCLR does not require read-modify write */
    ETH_WAIT_NS(40*1000);
}

uint32 reg_read32(uint32 addr)
{
    return *((volatile uint32*)addr);
}

void reg_write32(uint32 data, uint32 addr)
{
    *((volatile uint32*)addr) = data;
}

extern volatile VAR(uint32, OS_VAR) tpl_time_counter;
uint32 get_time(void)
{
    return tpl_time_counter;
}

uint32 get_elapsed_time(uint32 start_val)
{
    return (tpl_time_counter - start_val);
}

void ms_delay(uint32 value)
{
    uint32 start_time = get_time();

    while(get_elapsed_time(start_time) < value);
}

void port_init(void)
{
    uint32 dataL;

    /*-------
    * GPSR3[18:0] = 18'b1111111111111111111 
    * = TSNx_AVTP_CAPTURE, TSNx_AVTP_MATCH, TSNx_AVTP_PPS, TSN0_MAGIC, TSNx_PHY_INT, TSNx_LINK, TSNx_MDC, TSNx_MDIO */
    dataL = *((volatile uint32 *)(PFC_GPSR_GPn_DM0(3)));
    dataL &= ~(0x0007FFFFUL);
    dataL |= (0x0007FFFFUL);
    *((volatile uint32 *)(PFC_PMMR(PFC_GPn_BASE(3)))) = ~dataL;
    *((volatile uint32 *)(PFC_GPSR_GPn_DM0(3))) = dataL;

    /*-------
    * DRV0CTRL4  [31:28] AVB0_TXC
    *                    [27:24] AVB0_TX_CTL
    * DRV1CTRL4  [15:12] AVB0_TD3
    *                    [11:8]  AVB0_TD2
    *                    [7:4]   AVB0_TD1
    *                    [3:0]   AVB0_TD0 */
    dataL = *((volatile uint32 *)PFC_DRVCTRLm_GPn_DM0(0,3));
    dataL &= ~0x77777777UL;
    dataL |= 0x33333333UL;
    *((volatile uint32 *)(PFC_PMMR(PFC_GPn_BASE(3)))) = ~dataL;
    *((volatile uint32 *)(PFC_DRVCTRLm_GPn_DM0(0,3))) = dataL;

    dataL = *((volatile uint32 *)PFC_DRVCTRLm_GPn_DM0(1,3));
    dataL &= ~0x77777777UL;
    dataL |= 0x33333333UL;
    *((volatile uint32 *)(PFC_PMMR(PFC_GPn_BASE(3)))) = ~dataL;
    *((volatile uint32 *)(PFC_DRVCTRLm_GPn_DM0(1,3))) = dataL;

    dataL = *((volatile uint32 *)PFC_DRVCTRLm_GPn_DM0(2,3));
    dataL &= ~0x00000777UL;
    dataL |= 0x00000333UL;
    *((volatile uint32 *)(PFC_PMMR(PFC_GPn_BASE(3)))) = ~dataL;
    *((volatile uint32 *)(PFC_DRVCTRLm_GPn_DM0(2,3))) = dataL;

    /* Ether TSN IO voltage level = 1.8V
    * POC3 bit[18:0] = 0 = IO voltage level = 1.8V */
    dataL = *((volatile uint32 *)PFC_POC_GPn_DM0(3));
    dataL &= ~(0x0007FFFFUL);
    *((volatile uint32 *)(PFC_PMMR(PFC_GPn_BASE(3)))) = ~dataL;
    *((volatile uint32 *)(PFC_POC_GPn_DM0(3))) = dataL;
}

#define GICD_ISENABLER     (0xf0000100)

void enable_int(uint32 num)
{
	*((volatile uint32 *)(GICD_ISENABLER + 4 * (num / 32)))  = 1 << (num % 32);
}

void debug_print_buffer(uint8 *buf, uint32 len)
{
    uint32 i = 0;

    for (i = 0; i < len; i++) {
        if ((i != 0) && ((i % 16) == 0)) {
            debug_printf("\n\r");
        }
        debug_printf("%02x ", buf[i]);
    }
    debug_printf("\n\r");
}
