#ifndef _ETH_GPTP_H_
#define _ETH_GPTP_H_

#include "tpl_os.h"

struct gptp_time {
    uint64 seconds;
    uint32 nano;
};

void eth_gptp_init(void);
void eth_gptp_get_time(struct gptp_time *output);

#endif /* _ETH_GPTP_H_ */ 