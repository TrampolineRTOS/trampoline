#ifndef __FLASHPROG_H__
#  define __FLASHPROG_H__
#  include "mytypes.h"

int flash_write_page(int start_page, U32 *buf, int page_num);
void flash_erase_range(U32 addr, U32 nBytes);
void flash_write(U32 addr, void *buffer, U32 nBytes);
void flash_set_mode(U32 fmcn); 

#define VINTPTR(addr) ((volatile unsigned int *)(addr))
#define VINT(addr) (*(VINTPTR(addr)))


#define FLASH_START_PAGE 128 /* 0x100000 + 32Kbyte(128*256) = 0x108000 */
//#define FLASH_START_PAGE 320
#define FLASH_BASE VINTPTR(0x00100000 + (FLASH_START_PAGE * 256))
#define FLASH_MODE_REG VINT(0xFFFFFF60)
#define FLASH_CMD_REG VINT(0xFFFFFF64)
#define FLASH_STATUS_REG VINT(0xFFFFFF68)

#endif
