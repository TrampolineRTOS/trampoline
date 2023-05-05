#ifndef __ICCOM_LL_H__
#define __ICCOM_LL_H__

//#include <Platform_Types.h>
#include <tpl_os_std_types.h>
#include <stddef.h>

static const uint32 ICCOM_HW_CONTROL_INIT = 0x00000000UL;

// IMPORTANT: Keep these masks aligned between CA55 and G4MH
#define ICCOM_CTRL_INT				(0x00000001U)
#define ICCOM_CTRL_BUFF_UPPER		(0x00000002U)
#define ICCOM_CTRL_BUFF_BOTTOM		(0x00000004U)
#define ICCOM_CTRL_DATA				(0x00000008U)
#define ICCOM_CTRL_ACK				(0x00000010U)
#define ICCOM_CTRL_INIT_COMPLETED	(0x00000020U)

typedef enum {
    ICCOM_CHANNEL_0 = 0,
} ICCOM_CHANNEL;

/* MFIS HW */
void iccom_ll_init(void);

void iccom_set_out_ctrl_reg(uint32 val);
void iccom_get_out_ctrl_reg(uint32 *pval);
void iccom_set_in_ctrl_reg(uint32 val);
void iccom_get_in_ctrl_reg(uint32 *pval);

void iccom_set_out_msg_reg(uint32 val);
void iccom_get_in_msg_reg(uint32 *pval);

void iccom_clear_interrupt(void);
void iccom_clear_interrupt_locked(void);

void iccom_cta_read(uint8 * buff, size_t size);
void iccom_cta_write(uint8 * buff, size_t size);

uint8* iccom_get_read_cta_ptr(void);
uint8* iccom_cta_write_cta_ptr(void);

#endif //__ICCOM_LL_H__
