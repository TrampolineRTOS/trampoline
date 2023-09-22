#include "eth_gptp.h"
#include "rswitch_regs.h"
#include "utils.h"

/* Note: we are only using Timer0 */

#define PTPTIVC_INIT                0x19000000	/* 320MHz */
#define RCAR_GEN4_PTP_CLOCK_S4      PTPTIVC_INIT

#define PTPRO           RSWITCH_GPTP_ADDR

#define PTPTMEC             PTPRO + 0x0010
#define PTPTMDC             PTPRO + 0x0014
#define PTPTIVC0            PTPRO + 0x0020
#define PTPTOVC00           PTPRO + 0x0030
#define PTPTOVC10           PTPRO + 0x0034
#define PTPTOVC20           PTPRO + 0x0038
#define PTPGPTPTM00         PTPRO + 0x0050
#define PTPGPTPTM10         PTPRO + 0x0054
#define PTPGPTPTM20         PTPRO + 0x0058

void eth_gptp_init(void)
{
    reg_write32(RCAR_GEN4_PTP_CLOCK_S4, PTPTIVC0);
    reg_write32(0x1, PTPTMEC);
}

void eth_gptp_get_time(struct gptp_time *output)
{
    output->nano = reg_read32(PTPGPTPTM00);
    output->seconds = reg_read32(PTPGPTPTM10) + 
                      (((uint64) reg_read32(PTPGPTPTM20)) << 32);
    /* A better implementation might check that none of the above
       registers overflowed while reading others... */
}