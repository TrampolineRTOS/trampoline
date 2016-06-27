#ifndef _ECROBOT_USB_H_
#define _ECROBOT_USB_H_

#include "ecrobot_types.h"

#define MAX_DEV_NAME_LEN 16
#define MAX_USB_DATA_LEN 64

typedef enum {
	USB_NO_INIT,
	USB_INIT,
	USB_CONNECTED
} USB_STATUS_T;

extern void ecrobot_init_usb(void);
extern SINT ecrobot_set_name_usb(U8* name);
extern   U8 ecrobot_process1ms_usb(void);
extern   U8 ecrobot_is_usb_connected(void);
extern SINT ecrobot_read_usb(U8* buf, U32 off, U32 len);
extern SINT ecrobot_send_usb(U8* buf, U32 off, U32 len);
extern SINT ecrobot_disconnect_usb(void);
extern void ecrobot_term_usb(void);

#endif
