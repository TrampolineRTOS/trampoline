#ifndef _ECROBOT_BLUETOOTH_H_
#define _ECROBOT_BLUETOOTH_H_

#define BT_BUF_SIZE 254 /* maximum size of Bluetooth Tx/Rx buffer in byte */

extern void ecrobot_init_bt_master(const U8 *bd_addr, const CHAR *pin);
extern void ecrobot_init_bt_slave(const CHAR *pin);
extern void ecrobot_init_bt_connection(void);
extern void ecrobot_term_bt_connection(void);
extern SINT ecrobot_get_bt_status(void);
extern   U8 ecrobot_get_bt_device_address(U8* bd_addr);
extern   U8 ecrobot_get_bt_device_name(CHAR* bd_name);
extern   U8 ecrobot_set_bt_device_name(const CHAR* bd_name);
extern   U8 ecrobot_set_bt_factory_settings(void);
extern  U32 ecrobot_send_bt_packet(U8 *buf, U32 bufLen);
extern  U32 ecrobot_read_bt_packet(U8 *buf, U32 bufLen);

#endif
