/*
 * This header file is shared between Linux and G4 and it includes all the
 * known iccom commands and replies
 */

#ifndef __ICCOM_COMMANDS_H__
#define __ICCOM_COMMANDS_H__

/*
 * CC-RH has different types compared to Linux, but since this file is shared
 * it should compile on both systems
 */
//#ifdef __rh850__
	typedef uint8	uint8_t;
	typedef uint16	uint16_t;
	typedef uint32	uint32_t;
	typedef sint32	int32_t;
//#endif

enum iccom_command {
	READ_FLASH_ID = 0,
	ERASE_AREA,
	FLASH_CHUNK,
	READ_CHUNK,
};

#define FLASH_PAGE_SIZE			0x100	// 256 bytes
#define FLASH_PAGE_SIZE_MASK	0xFFFFFF00U

// this is the common header shared between all commands
#define CMD_HEADER		\
		uint8_t cmd_id;

#pragma pack(1)
struct command_header {
	CMD_HEADER
};

#pragma pack(1)
struct simple_reply_int32 {
	CMD_HEADER
	int32_t ret_val;
};
#pragma pack(1)
struct simple_reply_uint32 {
	CMD_HEADER
	uint32_t ret_val;
};

#pragma pack(1)
struct read_flash_id_command {
	CMD_HEADER
};

#pragma pack(1)
struct erase_area_command {
	CMD_HEADER
	uint32_t start_address;
	uint32_t size;
};

#pragma pack(1)
struct flash_chunk_command {
	CMD_HEADER
	uint32_t start_address;
	uint32_t size;
	uint8_t data[FLASH_PAGE_SIZE];
};

#pragma pack(1)
struct read_chunk_command {
	CMD_HEADER
	uint32_t start_address;
	uint32_t size;
};

#pragma pack(1)
struct read_chunk_reply {
	CMD_HEADER
	int32_t ret_val;
	uint8_t data[FLASH_PAGE_SIZE];
};

#endif //__ICCOM_COMMANDS_H__
