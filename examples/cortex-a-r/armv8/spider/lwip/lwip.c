#include "tpl_os.h"

#include "spider_serial.h"
#include "printf.h"
#include "utils.h"

#include "ethif.h"

/* lwIP core includes */
#include "lwip/opt.h"
#include "lwip/dhcp.h"
#include "lwip/tcpip.h"

struct netif this_netif;

FUNC(int, OS_APPL_CODE) main(void)
{
	Serial_Init();
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}

#define DHCP 0

TASK(lwip)
{
	debug_msg("init: call");
	struct netif this_netif;
	ip4_addr_t ip4_addr, net_mask, gateway;

	debug_msg("init ethernet low level");
	rswitch_enable_clock_and_reset();
	port_init();

	debug_msg("ethernet_init_inside_thread");
	tcpip_init(NULL,NULL);

	IP4_ADDR(&ip4_addr, 192, 168, 1, 2);
	IP4_ADDR(&net_mask, 255, 255, 255, 0);
	IP4_ADDR(&gateway, 192, 168, 1, 255);
#if DHCP==1
	netif_add( &this_netif, NULL, &net_mask, NULL, NULL, ethif_init, tcpip_input);
#else
	netif_add( &this_netif, &ip4_addr, &net_mask, NULL, NULL, ethif_init, tcpip_input);
#endif

	netif_set_up(&this_netif);

#if DHCP==1
	dhcp_start(&this_netif);
#endif

	debug_msg("init: done");

  	TerminateTask();
}

