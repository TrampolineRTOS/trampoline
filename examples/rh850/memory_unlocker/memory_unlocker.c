/** @file memory_unlocker.c
 * Enable registers access for certain peripherals from the Application Domain.
 */
#include <tpl_os.h>
#include "memory_unlocker.h"

FUNC(int, OS_APPL_CODE) main(void)
{
	int channel;

	// Issue an AXI bus stop request
	STBY_CTRL = 0x00000001;

	// P-Bus group 2
	PBG20KCPROT = PROTECTION_DISABLE_KEY; // Write protect release
	PBG20PROT0_m(2) = 0x000000D0; // STBC PBG protection release
	PBG20PROT1_m(2) = 0x040000FF; // STBC PBG protection release SPID=0~7 enable
	PBG21PROT0_m(1) = 0x000000D0; // Port configuration register PBG protection release
	PBG21PROT1_m(1) = 0x040000FF; // Port configuration register PBG protection release　SPID=0~7 enable

	// P-Bus group 3
	PBG30KCPROT = PROTECTION_DISABLE_KEY; // Write protect release
	for (channel = 0; channel < 3; channel++) // Channels 13 to 15 correspond to the RSCFD1 CAN8 to CAN10
		PBG32PROT0_m(channel + 13) = 0x000000D3;
	for (channel = 0; channel < 5; channel++) // Channels 0 to 4 correspond to the RSCFD1 CAN11 to CAN15
		PBG33PROT0_m(channel) = 0x000000D3;
	PBG33PROT0_m(5) = 0x000000D3; // RSCFD1 common registers
	PBG33PROT0_m(7) = 0x000000D3; // RSCFD1 global registers

	// P-Bus group 7
	PBG70KCPROT = PROTECTION_DISABLE_KEY; // Write protect release
	PBG70PROT0_m(3) = 0x000000D0; // RIIC0 PBG protection release
	PBG70PROT1_m(3) = 0x000000FF; // RIIC0 PBG protection release SPID=0~7 enable

	// P-Bus group 8
	PBG80KCPROT = PROTECTION_DISABLE_KEY; // Write protect release
	for (channel = 0; channel < 8; channel++) // Channels 2 to 9 correspond to the RSCFD0 CAN0 to CAN7
		PBG80PROT0_m(channel + 2) = 0x000000D3;
	PBG80PROT0_m(10) = 0x000000D3; // RSCFD0 common registers
	PBG80PROT0_m(12) = 0x000000D3; // RSCFD0 global registers

	// H-Bus
	HBGKCPROT_PFS = PROTECTION_DISABLE_KEY; // Write protect release
	HBGPROT0_PFS = 0x000000D0; // HBG_PFS protection release
	HBGPROT1_PFS = 0x000000FF; // HBG_PFS protection release　SPID=0~7 enable

	// Standby Controller
	MSRKCPROT = PROTECTION_DISABLE_KEY; // Write protect release

	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(unused_task)
{
	TerminateTask();
}
