#include "tpl_os.h"
#include "utils.h"
#include "eth_serdes.h"
#include "rswitch.h"

#define debug_msg(x)	do { (void)x; } while(0)

#define APP_Task_sample_init_START_SEC_CODE
#include "tpl_memmap.h"

extern volatile VAR(uint32, OS_VAR) tpl_time_counter;

// Is this the right section for the main function??
FUNC(int, OS_APPL_CODE) main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(sample_init) {
	int ret;

	mcu_init();
	port_init();
	// Interrupt initializazion done by Trampoline
	eth_disable_fuse_ovr();

	ret = eth_serdes_initialize();
	if (ret != 0) {
		debug_msg("Error in serdes initialization\n");
		goto exit;
	}

	rswitch_init();


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
	//CallTerminateISR2();
}

FUNC(void, OS_CODE) ETHA0_ERR_INT_ClearFlag(void)
{

}

#define APP_ISR_etha0_err_int_STOP_SEC_CODE
#include "tpl_memmap.h"