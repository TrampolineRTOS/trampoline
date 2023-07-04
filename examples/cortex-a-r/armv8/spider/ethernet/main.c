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

/*****************************************************************************/
/*****************************************************************************/

#define APP_ISR_gwca1_rx_tx_int_START_SEC_CODE
#include "tpl_memmap.h"

ISR(gwca1_rx_tx_int)
{
	debug_msg("gwca1_rx_tx_int");
	//CallTerminateISR2();
}

FUNC(void, OS_CODE) GWCA1_RX_TX_INT_ClearFlag(void)
{

}

#define APP_ISR_gwca1_rx_tx_int_STOP_SEC_CODE
#include "tpl_memmap.h"

/*****************************************************************************/
/*****************************************************************************/

#define APP_ISR_gwca1_rx_ts_int_START_SEC_CODE
#include "tpl_memmap.h"

ISR(gwca1_rx_ts_int)
{
	debug_msg("gwca1_rx_ts_int");
	//CallTerminateISR2();
}

FUNC(void, OS_CODE) GWCA1_RX_TS_INT_ClearFlag(void)
{

}

#define APP_ISR_gwca1_rx_ts_int_STOP_SEC_CODE
#include "tpl_memmap.h"

/*****************************************************************************/
/*****************************************************************************/

#define APP_ISR_coma_err_int_START_SEC_CODE
#include "tpl_memmap.h"

ISR(coma_err_int)
{
	debug_msg("coma_err_int");
	//CallTerminateISR2();
}

FUNC(void, OS_CODE) COMA_ERR_INT_ClearFlag(void)
{

}

#define APP_ISR_coma_err_int_STOP_SEC_CODE
#include "tpl_memmap.h"

/*****************************************************************************/
/*****************************************************************************/

#define APP_ISR_gwca1_err_int_START_SEC_CODE
#include "tpl_memmap.h"

ISR(gwca1_err_int)
{
	debug_msg("gwca1_err_int");
	//CallTerminateISR2();
}

FUNC(void, OS_CODE) GWCA1_ERR_INT_ClearFlag(void)
{

}

#define APP_ISR_gwca1_err_int_STOP_SEC_CODE
#include "tpl_memmap.h"

/*****************************************************************************/
/*****************************************************************************/

#define APP_ISR_etha0_err_int_START_SEC_CODE
#include "tpl_memmap.h"

ISR(etha0_err_int)
{
	debug_msg("etha0_err_int");
	//CallTerminateISR2();
}

FUNC(void, OS_CODE) ETHA0_ERR_INT_ClearFlag(void)
{

}

#define APP_ISR_etha0_err_int_STOP_SEC_CODE
#include "tpl_memmap.h"