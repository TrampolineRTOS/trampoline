#ifndef _ETH_H_
#define _ETH_H_

int rswitch_init(void);
int rswitch_open(void);

typedef void (*rx_callback_fn)(uint8 *buf, uint16 len);

void rswitch_regiter_data_received_callback(rx_callback_fn func);
int rswitch_send_data(uint8 *buf, uint16 size);

#endif /* _ETH_H_ */