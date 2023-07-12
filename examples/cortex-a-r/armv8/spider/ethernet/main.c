#include "tpl_os.h"
#include "utils.h"
#include "eth_serdes.h"
#include "rswitch.h"
#include "eth_gptp.h"
#include "serial.h"

#define APP_Task_sample_init_START_SEC_CODE
#include "tpl_memmap.h"

// Is this the right section for the main function??
FUNC(int, OS_APPL_CODE) main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(sample_init) {
	int ret;

	Serial_Init();

	rswitch_enable_clock_and_reset();
	port_init();
	// Interrupt initializazion done by Trampoline
	eth_disable_fuse_ovr();

	debug_msg("Initialize SERDES");
	ret = eth_serdes_initialize();
	if (ret != 0) {
		debug_msg("Error in eth_serdes_initialize");
		goto exit;
	}
	debug_msg("SERDES initialization done");

	debug_msg("Initialize RSwitch");
	ret = rswitch_init();
	if (ret != 0) {
		debug_msg("Error in rswitch_init\n");
		goto exit;
	}
	debug_msg("RSwitch initialization done");

	debug_msg("Initialize gPTP");
	eth_gptp_init();

	debug_msg("RSwitch open");
	ret = rswitch_open();
	if (ret != 0) {
		debug_msg("Error in rswitch_open\n");
		goto exit;
	}
	debug_msg("RSwitch completed");

	debug_msg("Initialization completed");
exit:
	TerminateTask();
}

#define APP_Task_sample_init_STOP_SEC_CODE
#include "tpl_memmap.h"