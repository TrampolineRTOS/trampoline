#include "tpl_os.h"
#include "eth_serdes.h"
#include "err_codes.h"
#include "utils.h"

//#define ETH_SERDES_AN_ENABLED

#define ETH_SERDES_CH_NUM      3
#define ETH_SERDES_XPCS_CH0    0UL
#define ETH_SERDES_XPCS_CH1    1UL
#define ETH_SERDES_XPCS_CH2    2UL

/* Maximum Ethernet Timeout Count */
#define ETH_TIMEOUT_COUNT                               63158UL

/* Ethernet SERDES registers Base Address */
#define ETH_SERDES_XPCS0_BASE                           0xE6444000UL
#define ETH_SERDES_XPCS1_BASE                           0xE6444400UL
#define ETH_SERDES_XPCS2_BASE                           0xE6444800UL
/* Ehternet SERDES Bank Register Address */
#define ETH_SERDES_XPCS0_BANK                           0xE64443FCUL
#define ETH_SERDES_XPCS1_BANK                           0xE64447FCUL
#define ETH_SERDES_XPCS2_BANK                           0xE6444BFCUL

uint32 eth_serdes_base_addr[ETH_SERDES_CH_NUM] = {
    ETH_SERDES_XPCS0_BASE,
    ETH_SERDES_XPCS1_BASE,
    ETH_SERDES_XPCS2_BASE
};

uint32 eth_serdes_bank_addr[ETH_SERDES_CH_NUM] = {
    ETH_SERDES_XPCS0_BANK,
    ETH_SERDES_XPCS1_BANK,
    ETH_SERDES_XPCS2_BANK
};

typedef enum {
    ETH_MAC_LAYER_SPEED_10M = 0,
    ETH_MAC_LAYER_SPEED_100M,
    ETH_MAC_LAYER_SPEED_1G,
    ETH_MAC_LAYER_SPEED_2500M,
    ETH_MAC_LAYER_SPEED_10G
} eth_serdes_speed_t;

#define ETH_SERDES_BPS       ETH_MAC_LAYER_SPEED_1G

#define ETH_SERDES_SEL_BANK(ch, value) \
        {*(volatile uint32*)eth_serdes_bank_addr[ch] = (uint32)value;}
#define ETH_SERDES_REG_WRITE(ch, offset, value) \
        {*(volatile uint32*)(eth_serdes_base_addr[ch] + (uint16)offset) = (uint32)value;}
#define ETH_SERDES_REG_READ(ch, offset) \
        (*(volatile uint32*)(eth_serdes_base_addr[ch] + (uint16)offset))

void eth_disable_fuse_ovr(void)
{
    /* Disable Fuse_override_en */
    uint32 address;
    volatile uint32 val;

    address = 0xE6446600;
    val = *((volatile uint32*)address);
    *((volatile uint32*)address) = 0x00000000U;
    val = *((volatile uint32*)address);
    (void) val;
}

static int eth_serdes_wait_for_update(uint32 ch, uint16 offset, uint32 mask,
                                      uint32 exp_val, uint32 timeout)
{
    uint32 start_time;
    uint32 reg_val;

    start_time = get_time();

    do {
        reg_val = ETH_SERDES_REG_READ(ch, offset);
        if ((reg_val & mask) == exp_val) {
            return 0;
        }
    } while (get_elapsed_time(start_time) < timeout);

    return ERR_TIMEOUT;
}

static int eth_serdes_wait_reset(void)
{
    int ch, ret;

    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0180U);
        ret = eth_serdes_wait_for_update(ch, 0x026C, BIT(0), BIT(0), ETH_TIMEOUT_COUNT);
        if (ret != 0) {
            break;
        }
    }
    return ret;
}

static int eth_serdes_initialize_SRAM(void)
{
    int ch, ret;

    ret = eth_serdes_wait_reset();
    if (ret != 0) {
        return ret;
    }

    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0180);
        ETH_SERDES_REG_WRITE(ch, 0x026C, 0x3);
    }
    
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0300U);
        ret = eth_serdes_wait_for_update(ch, 0x0000U, BIT(15), 0UL, ETH_TIMEOUT_COUNT);
        if (ret != 0) {
            break;
        }
    }

    return ret;
}

static void eth_serdes_set_SGMII_common_settings(void)
{
    int ch;
    /* Steps S.4.1 to S.4.5 */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0180);
        ETH_SERDES_REG_WRITE(ch, 0x0244, 0x97);
        ETH_SERDES_REG_WRITE(ch, 0x01D0, 0x60);
        ETH_SERDES_REG_WRITE(ch, 0x01D8, 0x2200);
        ETH_SERDES_REG_WRITE(ch, 0x01D4, 0x0);
        ETH_SERDES_REG_WRITE(ch, 0x01E0, 0x3D);
    }
}

static int eth_serdes_PHY_soft_reset(void)
{
    int ch, ret;

    /* Step:5 */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0380);
        ETH_SERDES_REG_WRITE(ch, 0x0000, 0x8000);
    }

    /* Step:6 */
    ret = eth_serdes_wait_reset();
    if (ret != 0) {
        return ret;
    }

    /* Step:7 */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0180U);
        ETH_SERDES_REG_WRITE(ch, 0x026CU, 0x00000003UL);
    }

    /* Step:8 */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0380U);
        ret = eth_serdes_wait_for_update(ch, 0x0000U, BIT(15), 0UL, ETH_TIMEOUT_COUNT);
        if (ret != 0) {
            return ret;
        }
    }

    return 0;
}

static int eth_serdes_channel_SGMII_common_configuration(uint32 ch)
{
    int ret;

    /* Steps S/SA.9.1 to S/SA.9.14 */
    ETH_SERDES_SEL_BANK(ch, 0x0380);
    ETH_SERDES_REG_WRITE(ch, 0x0000, 0x2000);
    ETH_SERDES_SEL_BANK(ch, 0x0180);
    ETH_SERDES_REG_WRITE(ch, 0x01C0, 0x11);
    ETH_SERDES_REG_WRITE(ch, 0x0248, 0x540);
    ETH_SERDES_REG_WRITE(ch, 0x0258, 0x15);
    ETH_SERDES_REG_WRITE(ch, 0x0144, 0x100);
    ETH_SERDES_REG_WRITE(ch, 0x01A0, 0x0);
    ETH_SERDES_REG_WRITE(ch, 0x00D0, 0x2);
    ETH_SERDES_REG_WRITE(ch, 0x0150, 0x3);
    ETH_SERDES_REG_WRITE(ch, 0x00C8, 0x100);
    ETH_SERDES_REG_WRITE(ch, 0x0148, 0x100);
    ETH_SERDES_REG_WRITE(ch, 0x0174, 0x0);
    ETH_SERDES_REG_WRITE(ch, 0x0160, 0x7);
    ETH_SERDES_REG_WRITE(ch, 0x01AC, 0x0);
    ETH_SERDES_REG_WRITE(ch, 0x00C4, 0x310);

    /* Step: S/SA.9.15 */
    ETH_SERDES_REG_WRITE(ch, 0x00C8, 0x101);

    /* Step: S/SA.9.16 */
    ret = eth_serdes_wait_for_update(ch, 0x00C8, BIT(0), 0x0, ETH_TIMEOUT_COUNT);
    if (ret != 0) {
        return ret;
    }

    /* Step: S/SA.9.17 */
    ETH_SERDES_REG_WRITE(ch, 0x0148, 0x101);

    /* Step: S/SA.9.18 */
    ret = eth_serdes_wait_for_update(ch, 0x0148, BIT(0), 0x0, ETH_TIMEOUT_COUNT);
    if (ret != 0) {
        return ret;
    }

    /* Steps S/SA.9.19 to S/SA.9.24 */
    ETH_SERDES_REG_WRITE(ch, 0x00C4, 0x1310);
    ETH_SERDES_REG_WRITE(ch, 0x00D8, 0x1800);
    ETH_SERDES_REG_WRITE(ch, 0x00DC, 0x0);

    ETH_SERDES_SEL_BANK(ch, 0x0300);
    ETH_SERDES_REG_WRITE(ch, 0x001C, 0x1);
    ETH_SERDES_SEL_BANK(ch, 0x0380);
    ETH_SERDES_REG_WRITE(ch, 0x0000, 0x2100);

    ret = eth_serdes_wait_for_update(ch, 0x0000, BIT(8), 0x0, ETH_TIMEOUT_COUNT);

    return ret;
}

#if defined(ETH_SERDES_AN_ENABLED)
static void eth_serdes_channel_SGMII_enable_AN(uint32 ch, eth_serdes_speed_t LenSpeed)
{
    /* Step: SA.9.25 */
    ETH_SERDES_SEL_BANK(ch, 0x1F00);
    if (ETH_MAC_LAYER_SPEED_1G == ch) {
        /* select when 1Gbps */
        ETH_SERDES_REG_WRITE(ch, 0x0000, 0x140);
    } else {
        /* select when 100Mbps */
        ETH_SERDES_REG_WRITE(ch, 0x0000, 0x2100);
    }
    
    /* Steps SA.9.26 to SA.9.28 */
    ETH_SERDES_SEL_BANK(ch, 0x1F80);
    ETH_SERDES_REG_WRITE(ch, 0x0004, 0x005);
    ETH_SERDES_REG_WRITE(ch, 0x0028, 0x7A1);
    ETH_SERDES_REG_WRITE(ch, 0x0000, 0x208);
}
#endif

#if defined(ETH_SERDES_AN_ENABLED)
static int eth_serdes_channel_set_bps_SGMII_ANON(uint32 ch, eth_serdes_speed_t LenSpeed)
{
    int ret;

    /* Step: SA.10.1 */
    ETH_SERDES_SEL_BANK(ch, 0x1F00);

    /* Mode Selection Method is provisional */
    if (ETH_MAC_LAYER_SPEED_1G == LenSpeed) {
        /* select 1Gbps */
        ETH_SERDES_REG_WRITE(ch, 0x0000, 0x1140);
    } else {
        /* select 100Mbps */
        ETH_SERDES_REG_WRITE(ch, 0x0000, 0x3100);
    }

    /* Step: SA.10.2 */
    ETH_SERDES_SEL_BANK(ch, 0x1F80);
    ret = eth_serdes_wait_for_update(ch, 0x0008, BIT(0), BIT(0), ETH_TIMEOUT_COUNT);
    if (ret != 0) {
        return ret;
    }

    ETH_SERDES_REG_WRITE(ch, 0x0008, 0x0);

    return ret;
}
#endif

static void eth_serdes_channel_set_bps_SGMII_ANOFF(uint32 ch, eth_serdes_speed_t LenSpeed)
{
    /* Step:S.10.1 */
    ETH_SERDES_SEL_BANK(ch, 0x1F00);

    /* Mode Selection Method is provisional */
    if (ETH_MAC_LAYER_SPEED_1G == LenSpeed) {
        /* select 1Gbps */
        ETH_SERDES_REG_WRITE(ch, 0x0000, 0x140);
    } else {
        /* select 100Mbps */
        ETH_SERDES_REG_WRITE(ch, 0x0000, 0x2100);
    }
}

/* Following User's Manual at section 100.6.3 */
int eth_serdes_initialize(void)
{
    int ret, ch;

    /* Step 1: Initialize SRAM */
    ret = eth_serdes_initialize_SRAM();
    if (ret != 0) {
        return ret;
    }

    /* Step 2 */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0380);
        ETH_SERDES_REG_WRITE(ch, 0x03D4, 0x443);
    }

    /* Step 3 */
    eth_serdes_set_SGMII_common_settings();

    /* Step 4 */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0380);
        ETH_SERDES_REG_WRITE(ch, 0X03D0, 0x1);
    }

    /* Steps 5 to 8 */
    ret = eth_serdes_PHY_soft_reset();
    if (ret != 0) {
        return ret;
    }

    /* Step 9 */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        /* Steps S/SA.9.1 to S/SA.9.24 */
        ret = eth_serdes_channel_SGMII_common_configuration(ch);
        if (ret != 0) {
            return ret;
        }
#if defined(ETH_SERDES_AN_ENABLED)
        /* Steps SA.9.25 to SA.9.28 */
        eth_serdes_channel_SGMII_enable_AN(ch, ETH_SERDES_BPS);
#endif
    }

    /* Step 10: */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
#if defined(ETH_SERDES_AN_ENABLED)
        /* Steps SA.10.1 to SA.10.3 */
        ret = eth_serdes_channel_set_bps_SGMII_ANON(ch, ETH_SERDES_BPS);
        if (ret != 0) {
            return ret;
        }
#else
        /* Step: S.10.1 */
        eth_serdes_channel_set_bps_SGMII_ANOFF(ch, ETH_SERDES_BPS);
#endif
    }

    /* Step 11 */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0380);
        ETH_SERDES_REG_WRITE(ch, 0x03C0, 0x0);
    }

    /* Step 12 */
    for (ch = ETH_SERDES_XPCS_CH0; ch < ETH_SERDES_CH_NUM; ch++) {
        ETH_SERDES_SEL_BANK(ch, 0x0380);
        ETH_SERDES_REG_WRITE(ch, 0x03D0, 0x0);
    }

    return 0;
}
