#include "tpl_os.h"
#include "utils.h"
#include "eth_serdes.h"
#include "rswitch.h"
#include "eth_gptp.h"
#include "serial.h"
#include "string.h"

#define APP_Task_sample_init_START_SEC_CODE
#include "tpl_memmap.h"

uint8 tmp_buffer[1600];
uint16 tmp_buffer_len = 0;

// Is this the right section for the main function??
FUNC(int, OS_APPL_CODE) main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

void eth_callback(uint8 *data, uint16 len)
{
	/* Copy the data into the local buffer and then activate the Echo task */
	memcpy(tmp_buffer, data, len);
	tmp_buffer_len = len;
	ActivateTask(echo);
}

TASK(sample_init) {
	int ret;

	Serial_Init();

	rswitch_enable_clock_and_reset();
	port_init();
	// Interrupt initializazion done by Trampoline
	eth_disable_fuse_ovr();

	ret = eth_serdes_initialize();
	if (ret != 0) {
		debug_msg("Error in eth_serdes_initialize");
		goto exit;
	}
	debug_msg("SERDES initialization done");

	ret = rswitch_init();
	if (ret != 0) {
		debug_msg("Error in rswitch_init\n");
		goto exit;
	}
	debug_msg("RSwitch initialization done");

	debug_msg("Initialize gPTP");
	eth_gptp_init();

	ret = rswitch_open();
	if (ret != 0) {
		debug_msg("Error in rswitch_open\n");
		goto exit;
	}
	debug_msg("RSwitch open completed");

	rswitch_regiter_data_received_callback(eth_callback);

	debug_msg("Initialization completed");
exit:
	TerminateTask();
}

#define APP_Task_sample_init_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_echo_START_SEC_CODE
#include "tpl_memmap.h"

TASK(echo)
{
	int ret;
	uint8 src_mac[6];
	uint8 dst_mac[6];

	debug_msg("## Echo task ##");

	debug_msg("Received:");
	debug_print_buffer(tmp_buffer, tmp_buffer_len);

	/* Swap MAC addresses just to play a little with the data */
	memcpy(src_mac, &tmp_buffer[0], 6);
	memcpy(dst_mac, &tmp_buffer[6], 6);
	memcpy(&tmp_buffer[0], dst_mac, 6);
	memcpy(&tmp_buffer[6], src_mac, 6);

	ret = rswitch_send_data(tmp_buffer, tmp_buffer_len);
	if (ret != 0) {
		debug_msg("Send data back: FAILED");
	} else {
		debug_msg("Send data back: SUCCESS");
	}

	/* Clear the data for the next iteration */
	memset(tmp_buffer, 0, sizeof(tmp_buffer));
	tmp_buffer_len = 0;

	TerminateTask();
}

#define APP_Task_echo_STOP_SEC_CODE
#include "tpl_memmap.h"