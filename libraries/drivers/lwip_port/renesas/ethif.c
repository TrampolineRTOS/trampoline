#include <string.h>
#include "ethif.h"
#include "utils.h"
#include "eth_serdes.h"
#include "rswitch.h"
#include "eth_gptp.h"
#include "lwip/etharp.h"

static struct netif *netif_ref = NULL;

void ethif_callback(uint8 *data, uint16 len)
{
    struct pbuf *p, *q;
    uint8_t *data_ptr = data;
    err_t ret;

    /* move received packet into a new pbuf */
#if ETH_PAD_SIZE
    len += ETH_PAD_SIZE; /* allow room for Ethernet padding */
#endif
    /* We allocate a pbuf chain of pbufs from the pool. */
    p = pbuf_alloc(PBUF_RAW, len, PBUF_POOL);
    if (p == NULL) {
        debug_msg("Error: unable to allocate memory in %s", __func__);
        return;
    }

#if ETH_PAD_SIZE
    pbuf_remove_header(p, ETH_PAD_SIZE); /* drop the padding word */
#endif
    /* We iterate over the pbuf chain until we have read the entire
     * packet into the pbuf. */
    for (q = p; q != NULL; q = q->next) {
        memcpy(q->payload, data_ptr, q->len);
        data_ptr += q->len;
    }
#if ETH_PAD_SIZE
    pbuf_add_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif

    /* pass all packets to ethernet_input, which decides what packets it supports */
    ret = netif_ref->input(p, netif_ref);
    if (ret != ERR_OK) {
        debug_msg("Error: netif->input returned %d\n", ret);
        pbuf_free(p);
    }
}

static err_t low_level_output(struct netif *netif, struct pbuf *p)
{
    (void) netif;
    struct pbuf *q;
    int ret;

#if ETH_PAD_SIZE
    pbuf_remove_header(p, ETH_PAD_SIZE); /* drop the padding word */
#endif

    for (q = p; q != NULL; q = q->next) {
        /* Send the data from the pbuf to the interface, one pbuf at a
        time. The size of the data in each pbuf is kept in the ->len
        variable. */
        ret = rswitch_send_data(q->payload, q->len);
        if (ret != 0) {
            return ERR_IF;
        }
    }

#if ETH_PAD_SIZE
    pbuf_add_header(p, ETH_PAD_SIZE); /* reclaim the padding word */
#endif

    return ERR_OK;
}

static err_t low_level_init(struct netif *netif)
{
    int ret;

    netif->hwaddr_len = ETHARP_HWADDR_LEN;
    /* This is the same value set in "rswitch.c" */
    netif->hwaddr[0] = 0x74U;
    netif->hwaddr[1] = 0x90U;
    netif->hwaddr[2] = 0x50U;
    netif->hwaddr[3] = 0x00U;
    netif->hwaddr[4] = 0x00U;
    netif->hwaddr[5] = 0x00U;
    netif->mtu = 1500;

    /* device capabilities */
    /* don't set NETIF_FLAG_ETHARP if this device is not an ethernet one */
    netif->flags = NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_ETHERNET | NETIF_FLAG_LINK_UP;

    // Interrupt initializazion done by Trampoline
    eth_disable_fuse_ovr();

    ret = eth_serdes_initialize();
    if (ret != 0) {
        debug_msg("Error in eth_serdes_initialize");
        return ERR_IF;
    }
    debug_msg("SERDES initialization done");

    ret = rswitch_init();
    if (ret != 0) {
        debug_msg("Error in rswitch_init\n");
        return ERR_IF;
    }
    debug_msg("RSwitch initialization done");

    debug_msg("Initialize gPTP");
    eth_gptp_init();

    ret = rswitch_open();
    if (ret != 0) {
        debug_msg("Error in rswitch_open\n");
        return ERR_IF;
    }
    debug_msg("RSwitch open completed");

    rswitch_regiter_data_received_callback(ethif_callback);

    debug_msg("Initialization completed");

    return ERR_OK;
}

err_t ethif_init(struct netif *netif)
{
    debug_msg("%s", __func__);

    netif_ref = netif;

    netif->name[0] = 'r';
    netif->name[1] = 'n';
    netif->mtu = 1500;

    netif->state = NULL; // Set to anything, if necessary

    netif->linkoutput = low_level_output;
    netif->output = etharp_output;

    return low_level_init(netif);
}