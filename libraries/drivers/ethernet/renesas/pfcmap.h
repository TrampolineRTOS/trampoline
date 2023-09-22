#ifndef PFCMAP_H
#define PFCMAP_H

/* PFC base */
#define PFC_GP0_BASE        (0xE6050000UL)
#define PFC_GP4_BASE        (0xDFD90000UL)

static const unsigned int PRTGRP_OFFSET[] =
{
  0x0000U,    /* PRTGRP0  */
  0x0000U,    /* PRTGRP1  */
  0x0800U,    /* PRTGRP2  */
  0x0800U,    /* PRTGRP3  */
  0x0000U,    /* PRTGRP4  */
  0x0800U,    /* PRTGRP5  */
  0x0000U,    /* PRTGRP6  */
  0x0800U,    /* PRTGRP7  */
  0x1000U,    /* PRTGRP8  */
  0x1800U,    /* PRTGRP9  */
  0x0000U,    /* PRTGRP10 */
};

#define PFC_GPSR_BmPlTt_OFFSET(m, l, t)    (0x0040U + PFC_GROUPS_OFFSET(m, l, t))

/* PFC[0] = m=0~3, l=1, t=0~2 */
/* PFC[1] = m=0~3, l=0, t=0~2 */
/* PFC[2] = m=0~3, l=4,5, t=0~2 */
/* PFC[3] = m=0~3, l=6~9, t=0~2 */

#define PFC_IPnSR_BmPlTt_OFFSET(n, m, l, t)    (0x0060U + (0x0004U * n) + PFC_GROUPS_OFFSET(m, l, t))

/* PFC[0] = m=0~3, l=1, t=0~2 */
/* PFC[1] = m=0~3, l=0, t=0~2 */
/* PFC[2] = m=0~3, l=4,5, t=0~2 */
/* PFC[3] = m=0~3, l=6~9, t=0~2 */

#define PFC_POC_BmPlTt_OFFSET(m, l, t)    (0x00A0U + PFC_GROUPS_OFFSET(m, l, t))

/* PFC[0] = m=0~3, l=1, t=0~2 */
/* PFC[1] = m=0~3, l=0, t=0~2 */
/* PFC[2] = m=0~3, l=4,5, t=0~2 */
/* PFC[3] = m=0~3, l=6~9, t=0~2 */

#define PFC_DRVnCTRL_BmPlTt_OFFSET(n, m, l, t)    (0x0080U + (0x0004U * n) + PFC_GROUPS_OFFSET(m, l, t))

#define PFC_GROUPS_OFFSET(m, l, t)    (((m) * 0x2000U) + PRTGRP_OFFSET[l] + ((t) * 0x0200U))
/* R/W 32 LSI Multiplexed Pin Setting Mask Register */
#define PFC_PMMR(addr)      ((addr & 0xFFFFF800U) + 0x0000UL)

#define PFC_PORTGP_OFFSET   (0x800U)
#define PFC_GPn_BASE(n)     (((n < 4)? PFC_GP0_BASE : PFC_GP4_BASE) + (PFC_PORTGP_OFFSET * (n % 4)))

#define PFC_GPSR_GPn_DM0(n) (PFC_GPn_BASE(n) + PFC_GPSR_BmPlTt_OFFSET(0,0,0))
#define PFC_IPSRm_GPn_DM0(m, n) (PFC_GPn_BASE(n) + PFC_IPnSR_BmPlTt_OFFSET(m,0,0,0))
/* R/W 32 POC control register0 PortGroup 3 */
#define PFC_POC_GPn_DM0(n)  (PFC_GPn_BASE(n) + PFC_POC_BmPlTt_OFFSET(0,0,0))
/* R/W 32 POC control register0 PortGroup 3 */
#define PFC_DRVCTRLm_GPn_DM0(m, n)  (PFC_GPn_BASE(n) + PFC_DRVnCTRL_BmPlTt_OFFSET(m,0,0,0))

#endif /* PFCMAP_H */
