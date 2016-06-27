#ifndef _ECROBOT_BASE_H_
#define _ECROBOT_BASE_H_

#include "bios.h"
#include "flash_loader.h"
#include "ecrobot_types.h"

#define MAX_STATUS_BAR_LENGTH 16

extern void init_OS_flag(void);
extern void set_OS_flag(void);
extern SINT get_OS_flag(void);
extern void cpp_constructor(void);
extern void cpp_destructor(void);
extern SINT execution_mode(void);
extern void show_splash_screen(void);
extern void show_main_screen(void);
extern void display_status_bar(SINT clear);
extern void show_bd_addr(U8 *bdaddr);
extern void show_bd_addr_err(void);
extern void add_status_info(SINT status);
extern void check_NXT_buttons(void);
/* system boot strap in init.s */
extern void start(void);

#endif
