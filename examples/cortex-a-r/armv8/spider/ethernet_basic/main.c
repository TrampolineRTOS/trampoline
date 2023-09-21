#include "tpl_os.h"
#include "utils.h"
#include "eth_serdes.h"
#include "rswitch.h"
#include "eth_gptp.h"
#include "spider_serial.h"
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

#if 0 /* set to 1 if debug logs are needed */
	debug_msg("## Echo task ##");
	debug_msg("Received:");
	debug_print_buffer(tmp_buffer, tmp_buffer_len);
#endif

	/* check if protocol = ARP */
	if ((tmp_buffer[12]==0x08)&&(tmp_buffer[13]==0x06)) {
		/* Swap MAC addresses */
		memcpy(dst_mac, &tmp_buffer[6], 6);
		memcpy(&tmp_buffer[0], dst_mac, 6);
		/* Send our MAC address */
		tmp_buffer[6] = 0x2E;
		tmp_buffer[7] = 0x09;
		tmp_buffer[8] = 0x0A;
		tmp_buffer[9] = 0x00;
		tmp_buffer[10] = 0x00;
		tmp_buffer[11] = 0x00;

		/* Swap MAC addresses */
		memcpy(src_mac, &tmp_buffer[22], 6);
		memcpy(&tmp_buffer[32], src_mac, 6);
		/* Send our MAC address */
		tmp_buffer[22] = 0x2E;
		tmp_buffer[23] = 0x09;
		tmp_buffer[24] = 0x0A;
		tmp_buffer[25] = 0x00;
		tmp_buffer[26] = 0x00;
		tmp_buffer[27] = 0x00;

		/* Swap IP addresses */
		memcpy(src_mac, &tmp_buffer[28], 4);
		memcpy(dst_mac, &tmp_buffer[38], 4);
		memcpy(&tmp_buffer[28], dst_mac, 4);
		memcpy(&tmp_buffer[38], src_mac, 4);

		/* Answer arp */
		tmp_buffer[21] = 2;
	}

	/* Check if protocol = ICMP (ping) */
	if ((tmp_buffer[12]==0x08)&&(tmp_buffer[13]==0x00)&&(tmp_buffer[23]==0x01)) {
		/* Switch mac addresses */
		memcpy(src_mac, &tmp_buffer[0], 6);
		memcpy(dst_mac, &tmp_buffer[6], 6);
		memcpy(&tmp_buffer[0], dst_mac, 6);
		memcpy(&tmp_buffer[6], src_mac, 6);

		/* Switch IP addresses */
		memcpy(src_mac, &tmp_buffer[26], 4);
		memcpy(dst_mac, &tmp_buffer[30], 4);
		memcpy(&tmp_buffer[26], dst_mac, 4);
		memcpy(&tmp_buffer[30], src_mac, 4);

		/***************************/
		/* Compute header checksum */
		/***************************/
		/* Clear checksum */
		tmp_buffer[24] = 0x0;
		tmp_buffer[25] = 0x0;
		/* Compute sum */
		uint32 checksum = 0x0;
		for(uint8 i=0; i<10; i++) {
			checksum += tmp_buffer[14+2*i] * 0x100;
			checksum += tmp_buffer[15+2*i];
		}
		/* Compute carry */
		while(checksum > 0xffff) {
			checksum = (checksum & 0xffff) + (checksum >> 16);
		}
		/* Compute the ones' complement */
		checksum = 0xffff - checksum;
		/* Update checksum field */
		tmp_buffer[24] = (checksum >> 8) & 0xff;
		tmp_buffer[25] = checksum & 0xff;

		/* Answer ping */
		tmp_buffer[34] = 0;

		/* ICMP checksum */
		/* We only modify the ICMP type for 0x8 (ping request) to 0x0 (ping answer) */
		/* so, no need to compute the checksum, only need to add 8 to it */
		if(tmp_buffer[36]>=0xf8) tmp_buffer[37] = tmp_buffer[37]+1;
		tmp_buffer[36] = tmp_buffer[36] + 8;
	}

	ret = rswitch_send_data(tmp_buffer, tmp_buffer_len);
	if (ret != 0) {
		debug_msg("Send data back: FAILED");
	}

	/* Clear the data for the next iteration */
	memset(tmp_buffer, 0, sizeof(tmp_buffer));
	tmp_buffer_len = 0;

	TerminateTask();
}

#define APP_Task_echo_STOP_SEC_CODE
#include "tpl_memmap.h"