/*
 * Flash memory layout
 *
 * 256-32=224kbytes Flash memory is preserved
 * for user application.
 *
 * +------------+
 * |  0x140000  | Flash memory end address (256kbytes)
 * +------------+
 * |            |
 * +------------+
 * |  0x108000  | Flash start page address for user application
 * +------------+
 * | 256 bytes  | Flash record page (end of NXT BIOS)
 * +------------+
 * | 256 bytes  | Flash request page
 * +------------+
 * |            |
 * +------------+
 * |  0x100000  | Flash memory start address (start of NXT BIOS)
 * +------------+
 *
 */

#ifndef _FLASH_LOADER_H_
#define _FLASH_LOADER_H_

#include "flashprog.h"

#define FLASH_START_ADDR          0x00100000

#define MAX_NUM_FLASH_PAGES       (1023 - FLASH_START_PAGE)
/*
 * FLASH_START_PAGE:128 0x108000 = 0x100000 + 128*256(32Kbytes)
 */
#define FLASH_RECORD_START_PAGE   (FLASH_START_PAGE - 1)
#define FLASH_REQUEST_START_PAGE  (FLASH_RECORD_START_PAGE - 1)
#define FLASH_NVMEMORY_START_PAGE (FLASH_REQUEST_START_PAGE - 8)
#define MAX_BIOS_FLASH_PAGE       (FLASH_NVMEMORY_START_PAGE - 1)

#define FLASH_PAGE_SIZE           256
#define DATA_LENGTH 	          64

#define UPLOAD_IN_PROGRESS        0
#define UPLOAD_FINISHED           -1
#define UPLOAD_FAILED             -2
#define UPLOAD_IDLE               -3

#define FLASH_REQUEST             "Jumpin' Jack Flash"

#define	JUMP_TO_APPLICATION		  asm("ldr r5,=0x108000\n"); \
								  asm("bx r5\n");

extern int is_bios_version_equal(void);
extern int set_flash_request(void);
extern int clear_flash_request(void);
extern int has_flash_request(void);
extern void flash_loader(void);

extern void nxt_device_init(void);
#endif
