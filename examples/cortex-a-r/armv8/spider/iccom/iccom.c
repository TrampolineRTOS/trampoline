#include "tpl_os.h"
#include "iccom.h"
#include "iccom_ll.h"
#include "iccom_commands.h"
#include <string.h>

#define APP_Task_iccom_START_SEC_CODE
#include "tpl_memmap.h"

#include "iccom_commands.h"

extern volatile VAR(uint32, OS_VAR) tpl_time_counter;

/* ICCOM protocol */
enum ICCOM_MSG {
    ICCOM_MSG_INVALID,
    ICCOM_MSG_INIT,
    ICCOM_MSG_DATA,
    ICCOM_MSG_ACK
};

#define ICCOM_BUF_MAX_SIZE		(TOTAL_CTA_SIZE/2)
#define TIMER_TICK_INTERVAL_NS		(125U)
#define TIMER_TICKS_PER_MS			(1000000U/TIMER_TICK_INTERVAL_NS)
#define HOST_INT_CLEAR_TIMEOUT_MS		(500U*TIMER_TICKS_PER_MS)

uint8 iccom_initalized = 0;

static void iccom_notify_tx_data(size_t message)
{
	iccom_set_out_msg_reg((uint32)message);
	iccom_set_out_ctrl_reg(ICCOM_HW_CONTROL_INIT);
	iccom_set_out_ctrl_reg(ICCOM_CTRL_DATA | ICCOM_CTRL_BUFF_UPPER | ICCOM_CTRL_INT);
}

static void iccom_send_rx_data_ack(uint32 message)
{
	iccom_set_out_msg_reg(message);
	iccom_set_out_ctrl_reg(ICCOM_CTRL_ACK | ICCOM_CTRL_BUFF_BOTTOM | ICCOM_CTRL_INT);
}

static void iccom_send_initialization_ack(void)
{
	iccom_set_out_ctrl_reg(ICCOM_CTRL_INIT_COMPLETED | ICCOM_CTRL_INT);
}

static sint32 iccom_wait_for_out_interrupt_clear(uint32_t timeout_ms)
{
	uint32 out_ctrl_reg;
	TickType start_val, curr_val;

	start_val = tpl_time_counter;
	do {
		iccom_get_out_ctrl_reg(&out_ctrl_reg);
		curr_val = tpl_time_counter;
		// If the host processor doesn't clear the interrupt before the timeout
		// then it's likely that the host application stopped/crashed and this
		// clear will never happen. So we clear it on our side and return an
		// error
		if (curr_val - start_val > timeout_ms) {
			iccom_set_out_ctrl_reg(ICCOM_HW_CONTROL_INIT);
			return -1;
		}
	} while (out_ctrl_reg & ICCOM_CTRL_INT);

	return 0;
}

static void iccom_send(uint8* data, size_t size, uint8_t copy_to_out_cta)
{
	// If this function is called with data already on the CTA buffer,
	// then there is no need to update it
	if (copy_to_out_cta) {
		iccom_cta_write(data, size);
	}
	iccom_notify_tx_data(size);
}

static void iccom_handle_rx_msg(size_t size)
{
	struct command_header* in_pkt;
	sint32 ret;

	// Casting to the most simple structure in order to get the "cmd_id".
	// Later the proper casting will be done
	in_pkt = (struct command_header*) iccom_get_read_cta_ptr();
	iccom_send_rx_data_ack((uint32)size);
	ret = iccom_wait_for_out_interrupt_clear(HOST_INT_CLEAR_TIMEOUT_MS);
	if (ret < 0) {
		// In case of timeout then there's no reason to process the answer
		// further since the host processor will not care about this
		goto Exit;
	}

	switch (in_pkt->cmd_id) {
		case ECHO: {
			struct echo_command* cmd_pkt = (struct echo_command*) in_pkt;
			struct echo_reply* reply_pkt = (struct echo_reply*) iccom_cta_write_cta_ptr();

			// Just copy the data back
			memcpy(reply_pkt, cmd_pkt, size);
			iccom_send((uint8*)reply_pkt, size, 0);
			break;
		}

		default:
			break;
	}
Exit:
	;
}

static void iccom_handle_ack_received(void)
{
	iccom_set_in_ctrl_reg(ICCOM_HW_CONTROL_INIT);
}

enum ICCOM_MSG iccom_get_msg_type(uint32 control)
{
	if (control & ICCOM_CTRL_INIT_COMPLETED)
		return ICCOM_MSG_INIT;
	if (control & ICCOM_CTRL_DATA)
		return ICCOM_MSG_DATA;
	else
		return ICCOM_MSG_ACK;
}

void iccom_init(void)
{
	/* Initialize the HW first*/
	iccom_ll_init();
	/* clear control register */
	iccom_set_out_ctrl_reg(ICCOM_HW_CONTROL_INIT);
	/* clear message register */
	iccom_set_out_msg_reg(0x00000000UL);
}

FUNC(int, OS_APPL_CODE) main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(iccom) {
	iccom_init();
	TerminateTask();
}

ISR(iccomInt)
{
	uint32 target_control = 0;
	uint32 target_message = 0;
	size_t rx_size = 0;

	iccom_get_in_ctrl_reg(&target_control);
	iccom_get_in_msg_reg(&target_message);

	switch (iccom_get_msg_type(target_control)) {
	case ICCOM_MSG_DATA:
		rx_size = (size_t)target_message;
		if (rx_size > ICCOM_BUF_MAX_SIZE)
			rx_size = ICCOM_BUF_MAX_SIZE;
		iccom_handle_rx_msg(rx_size);
		break;
	case ICCOM_MSG_ACK:
		iccom_handle_ack_received();
		break;
	case ICCOM_MSG_INIT:
		iccom_set_out_ctrl_reg(ICCOM_HW_CONTROL_INIT);
		iccom_set_out_msg_reg(0x00000000UL);
		iccom_initalized = 1;
		iccom_send_initialization_ack();
		break;
	default:
		// Unexpected message. Do we need to do something here?
		break;
	}

	CallTerminateISR2();
}

FUNC(void, OS_CODE) ICCOM_INT_ClearFlag(void)
{
    iccom_clear_interrupt();
}

#define APP_Task_iccom_STOP_SEC_CODE
#include "tpl_memmap.h"
