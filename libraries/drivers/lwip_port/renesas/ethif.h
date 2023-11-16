#ifndef _ETHERNET_IF_H_
#define _ETHERNET_IF_H_

#include "lwip/init.h"
#include "lwip/err.h"
#include "lwip/netif.h"

err_t ethif_init(struct netif *netif);

#endif // _ETHERNET_IF_H_