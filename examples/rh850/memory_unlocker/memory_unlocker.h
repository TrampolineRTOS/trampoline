#ifndef H_MEMORY_UNLOCKER_H
#define H_MEMORY_UNLOCKER_H

#define PROTECTION_DISABLE_KEY 0xA5A5A501

// Register base addresses
#define MCCR_SELB1_base 0xF8F18200
#define PBG20_base  0xFFDE0B00 // P-Bus Group 2L
#define PBG21_base 0xFFDE0C00 // P-Bus Group 2L
#define PBGERRSLV20_base 0xFFDE1000 // P-Bus Group 2L
#define PBG32_base 0xFFC72D00 // P-Bus Group 3
#define PBG33_base 0xFFC72E00 // P-Bus Group 3
#define PBGERRSLV30_base 0xFFC73200 // P-Bus Group 3
#define PBG70_base 0xFFF49400 // P-Bus Group 7
#define PBGERRSLV70_base 0xFFF4A000 // P-Bus Group 7
#define PBG80_base 0xFFF29300 // P-Bus Group 8
#define PBGERRSLV80_base 0xFFF2A000 // P-Bus Group 8
#define HBGERRSLV_PFS_base 0xF8F19700
#define STBC_base 0xFF981000
#define HBG_PFS_base 0xF8F12700

// Register addresses
#define STBY_CTRL (*(volatile unsigned long  *) (MCCR_SELB1_base + 0x0034))

#define PBG20KCPROT (*(volatile unsigned long *) (PBGERRSLV20_base + 0x18))
#define PBG20PROT0_m(m) (*(volatile unsigned long *) (PBG20_base + 0x0 + 0x8 * (m)))
#define PBG20PROT1_m(m) (*(volatile unsigned long *) (PBG20_base + 0x4 + 0x8 * (m)))
#define PBG21PROT0_m(m) (*(volatile unsigned long *) (PBG21_base + 0x0 + 0x8 * (m)))
#define PBG21PROT1_m(m) (*(volatile unsigned long *) (PBG21_base + 0x4 + 0x8 * (m)))

#define PBG30KCPROT (*(volatile unsigned long *) (PBGERRSLV30_base + 0x18))
#define PBG32PROT0_m(m) (*(volatile unsigned long *) (PBG32_base + 0x0 + 0x8 * (m)))
#define PBG32PROT1_m(m) (*(volatile unsigned long *) (PBG32_base + 0x4 + 0x8 * (m)))
#define PBG33PROT0_m(m) (*(volatile unsigned long *) (PBG33_base + 0x0 + 0x8 * (m)))
#define PBG33PROT1_m(m) (*(volatile unsigned long *) (PBG33_base + 0x4 + 0x8 * (m)))

#define PBG70KCPROT (*(volatile unsigned long *) (PBGERRSLV70_base + 0x18))
#define PBG70PROT0_m(m) (*(volatile unsigned long *) (PBG70_base + 0x0 + 0x8 * (m)))
#define PBG70PROT1_m(m) (*(volatile unsigned long *) (PBG70_base + 0x4 + 0x8 * (m)))

#define PBG80KCPROT (*(volatile unsigned long *) (PBGERRSLV80_base + 0x18))
#define PBG80PROT0_m(m) (*(volatile unsigned long *) (PBG80_base + 0x0 + 0x8 * (m)))
#define PBG80PROT1_m(m) (*(volatile unsigned long *) (PBG80_base + 0x4 + 0x8 * (m)))

#define HBGKCPROT_PFS (*(volatile unsigned long *) (HBGERRSLV_PFS_base + 0x18))
#define HBGPROT0_PFS (*(volatile unsigned long *) (HBG_PFS_base))
#define HBGPROT1_PFS (*(volatile unsigned long *) (HBG_PFS_base + 0x4))

#define MSRKCPROT (*(volatile unsigned long *) (STBC_base + 0x710))

#endif
