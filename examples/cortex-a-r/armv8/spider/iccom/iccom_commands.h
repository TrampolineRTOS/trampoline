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
#ifdef LINUX_TEST_APP
	#include <stdint.h>
#else
	typedef uint8	uint8_t;
	typedef uint16	uint16_t;
	typedef uint32	uint32_t;
	typedef sint32	int32_t;
#endif

enum iccom_command {
	ECHO = 0,
};

#define TOTAL_CTA_SIZE		0x4000
#define ICCOM_BUF_MAX_SIZE	(TOTAL_CTA_SIZE/2) // Max size of each transaction (read/write)

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

#define MAX_ECHO_DATA_SIZE		((TOTAL_CTA_SIZE/2) - sizeof(uint8_t))

#pragma pack(1)
struct echo_command {
	CMD_HEADER
	uint8_t data[MAX_ECHO_DATA_SIZE];
};

#pragma pack(1)
struct echo_reply {
	CMD_HEADER
	uint8_t data[MAX_ECHO_DATA_SIZE];
};

#endif //__ICCOM_COMMANDS_H__
