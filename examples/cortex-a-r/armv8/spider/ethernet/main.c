#include "tpl_os.h"
#include "utils.h"
#include "spider_serial.h"
#include "string.h"
#include "lwip/netif.h"
#include "lwip/ip4_addr.h"
#include "lwip/timeouts.h"
#include "ethif.h"

#define APP_Task_sample_init_START_SEC_CODE
#include "tpl_memmap.h"

ip4_addr_t ip4_addr, net_mask, gateway;
struct netif ethif_netif;

// Is this the right section for the main function??
FUNC(int, OS_APPL_CODE) main(void)
{
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

TASK(sample_init) {
	Serial_Init();

	rswitch_enable_clock_and_reset();
	port_init();

	lwip_init();

	IP4_ADDR(&ip4_addr, 192, 168, 1, 2);
	IP4_ADDR(&net_mask, 255, 255, 255, 0);
	IP4_ADDR(&gateway, 0, 0, 0, 0);

	netif_add(&ethif_netif, &ip4_addr, &net_mask, &gateway, NULL,
				ethif_init, netif_input);

	netif_set_up(&ethif_netif);

	ActivateTask(monitor);

	TerminateTask();
}

#define APP_Task_sample_init_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_sample_init_START_SEC_CODE
#include "tpl_memmap.h"

TASK(monitor) {
	while (1) {
		sys_check_timeouts();
	}
}

#define APP_Task_sample_init_STOP_SEC_CODE
#include "tpl_memmap.h"
