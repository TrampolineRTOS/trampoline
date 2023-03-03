#include "tpl_os.h"
#include "iccom.h"
#include "iccom_ll.h"
//#include "qspi_flash_writer.h"
#include "iccom_commands.h"
//#include "tpl_app_config.h"
//#include "tpl_as_counter_kernel.h"

#define APP_Task_iccom_START_SEC_CODE
#include "tpl_memmap.h"

#include "iccom_commands.h"

extern volatile VAR(uint32, OS_VAR) tpl_time_counter;

//DeclareCounter(Hardware_Counter);
//DeclareCounter(Software_Counter);
//DeclareCounter(SystemCounter);
//DeclareCounter(0);


/* ICCOM protocol */
enum ICCOM_MSG {
    ICCOM_MSG_INVALID,
    ICCOM_MSG_INIT,
    ICCOM_MSG_DATA,
    ICCOM_MSG_ACK
};

#define ICCOM_BUF_MAX_SIZE		2048
#define TIMER_TICK_INTERVAL_NS		(125U)
#define TIMER_TICKS_PER_MS			(1000000U/TIMER_TICK_INTERVAL_NS)
#define HOST_INT_CLEAR_TIMEOUT_MS		(500U*TIMER_TICKS_PER_MS)

uint8 iccom_initalized = 0;
uint8 rx_buffer[ICCOM_BUF_MAX_SIZE];
uint8 tx_buffer[ICCOM_BUF_MAX_SIZE];

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

/*
 * delay comme sur l'arduino
 */
//FUNC(void, OS_CODE) delay(CONST(uint32, AUTOMATIC) howMuch)
//{
//  CONST(uint32, AUTOMATIC) start = tpl_time_counter;
//  while (tpl_time_counter - start < howMuch);
//}

static sint32 iccom_wait_for_out_interrupt_clear(uint32_t timeout_ms)
{
	uint32 out_ctrl_reg;
	TickType start_val, curr_val;

	//JN what is this MAIN_HW_COUNTER?
	//GetCounterValue(MAIN_HW_COUNTER, &start_val);
	//GetCounterValue(Hardware_Counter, &start_val);
	//GetCounterValue(Software_Counter, &start_val);
	//GetCounterValue(SystemCounter, &start_val);
	//GetCounterValue(0, &start_val);
	//GetCounterValue(Software_Counter1, &start_val);
	start_val = tpl_time_counter;
	do {
		iccom_get_out_ctrl_reg(&out_ctrl_reg);
		//JN
		//GetCounterValue(MAIN_HW_COUNTER, &curr_val);
		//GetCounterValue(Hardware_Counter, &curr_val);
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

static void iccom_send(uint8* data, size_t size)
{
	iccom_cta_write(data, size);
	iccom_notify_tx_data(size);
}

static void iccom_handle_rx_msg(size_t size)
{
	struct command_header* in_pkt;
	sint32 ret;
	
	iccom_cta_read(rx_buffer, size);
	iccom_send_rx_data_ack((uint32)size);
	ret = iccom_wait_for_out_interrupt_clear(HOST_INT_CLEAR_TIMEOUT_MS);
	if (ret < 0) {
		// In case of timeout then there's no reason to process the answer
		// further since the host processor will not care about this 
		goto Exit;
	}

	// Casting to the most simple structure in order to get the "cmd_id".
	// Later the proper casting will be done
	in_pkt = (struct command_header*) rx_buffer;
	switch (in_pkt->cmd_id) {
		case READ_FLASH_ID: {
			//struct read_flash_id_command* cmd_pkt = (struct read_flash_id_command*) rx_buffer;
			struct simple_reply_uint32 reply_pkt;
			//uint32 chip_id = flash_read_chip_id();
			reply_pkt.cmd_id = 0;
			reply_pkt.ret_val = 0xB0CAD0;
			iccom_send((uint8*)&reply_pkt, sizeof(struct simple_reply_uint32));
			break;
		}
		//case READ_CHUNK: {
		//	struct read_chunk_command* cmd_pkt = (struct read_chunk_command*) rx_buffer;
		//	struct read_chunk_reply* reply_pkt = (struct read_chunk_reply*) tx_buffer;
		//	reply_pkt->cmd_id = cmd_pkt->cmd_id;
		//	reply_pkt->ret_val = flash_read_chunk(cmd_pkt->start_address,
		//								cmd_pkt->size, reply_pkt->data);
		//	iccom_send((uint8*)reply_pkt, sizeof(struct read_chunk_reply));
		//	break;
		//}
		case ECHO: {
			struct echo_command* cmd_pkt = (struct read_chunk_command*) rx_buffer;
			struct echo_reply* reply_pkt = (struct read_chunk_reply*) tx_buffer;

			// Just copy the data back
			memcpy(reply_pkt, cmd_pkt, size);
			iccom_send((uint8*)reply_pkt, size);
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
	iccom_init();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(iccom) {
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

ISR(iccomIntClear)
{
    iccom_clear_interrupt();
}

#define APP_Task_iccom_STOP_SEC_CODE
#include "tpl_memmap.h"
