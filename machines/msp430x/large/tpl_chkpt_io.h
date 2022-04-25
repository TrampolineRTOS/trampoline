#ifndef __TPL_CHKPT_IO_H__
#define __TPL_CHKPT_IO_H__
#include "tpl_os.h"

/* Init specific IO so that we can choose
 * hot/cold start during startup.
 */ 
FUNC(void, OS_CODE) tpl_init_io_for_reset_handler(void);

/* test function called during the startup
 * true  => cold start               => main()
 * false => hot  start checkpointing => restart_main()
 * @see tpl_startup.c
 */
FUNC(int, OS_CODE) tpl_cold_startup(void);

#endif
