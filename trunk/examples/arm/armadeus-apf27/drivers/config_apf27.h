/*
 *
 * Configuration settings for the Armadeus Project apf27 board.
 *
 * Copyright (c) 2008-2009 Eric Jarrige <eric.jarrige@armadeus.org>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 *
 * 2008/08/19 Initial version based on apf9328 configuration file
 * 2008/10/09 Release 1.0 support u-boot 1.3.4
 * 2008/10/25 Release 1.1 added environment version 
 * 2008/11/01 Release 1.2 flash size independant 
 * 2008/11/09 Release 1.3 keep uboot partition locked & source clean-up 
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/*
 * Alphabetical list of all commands that are configured by default.
 * This is essentially all commands minus those that are considered
 * "non-standard" for some reason (memory hogs, requires special
 * hardware, not fully tested, etc.).
 */

#define CONFIG_CMD_AUTOSCRIPT	/* Autoscript Support		*/
#define CONFIG_CMD_BDI		/* bdinfo			*/
#define CONFIG_CMD_BOOTD	/* bootd			*/
#define CONFIG_CMD_CONSOLE	/* coninfo			*/
#define CONFIG_CMD_ECHO		/* echo arguments		*/
#define CONFIG_CMD_ENV		/* saveenv			*/
#define CONFIG_CMD_FLASH	/* flinfo, erase, protect	*/
#define CONFIG_CMD_FPGA		/* FPGA configuration Support	*/
#define CONFIG_CMD_IMI		/* iminfo			*/
#define CONFIG_CMD_IMLS		/* List all found images	*/
#define CONFIG_CMD_ITEST	/* Integer (and string) test	*/
#define CONFIG_CMD_LOADB	/* loadb			*/
#define CONFIG_CMD_LOADS	/* loads			*/
#define CONFIG_CMD_MEMORY	/* md mm nm mw cp cmp crc base loop mtest */
#define CONFIG_CMD_MISC		/* Misc functions like sleep etc*/
#define CONFIG_CMD_NET		/* bootp, tftpboot, rarpboot	*/
#define CONFIG_CMD_NFS		/* NFS support			*/
#define CONFIG_CMD_RUN		/* run command in env variable	*/
#define CONFIG_CMD_SETGETDCR	/* DCR support on 4xx		*/
#define CONFIG_CMD_XIMG		/* Load part of Multi Image	*/


#define CONFIG_ENV_VERSION 	"1.6"
#define CONFIG_IDENT_STRING	" apf27 patch 2.1"

#define CONFIG_ARM926EJS	1	/* this is an ARM926EJS CPU */
#define CONFIG_IMX27		1	/* in a Freescale i.MX27 Chip */
#define CONFIG_APF27		1	/* on a Armadeus project APF27 board */
#undef	CONFIG_USE_IRQ			/* don't need use IRQ/FIQ */

/*
 * Enable the call to misc_init_r() for miscellaneous platform
 * dependent initialization.
 */

#define CONFIG_MISC_INIT_R


/*
 * BOOTP options
 */
#define CONFIG_BOOTP_BOOTFILESIZE
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME

/*
 * Select serial console configuration
 */
#define CONFIG_IMX_SERIAL1
#define CFG_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200, 230400 }
#define CONFIG_BAUDRATE 	115200

/*
 * Definition of u-boot build in commands. Check out CONFIG_CMD_DFL if
 * neccessary in include/cmd_confdefs.h file. (Un)comment for getting
 * functionality or size of u-boot code.
 */


#define CONFIG_CMD_ASKENV	/* ask for env variable		*/
#define CONFIG_CMD_BSP		/* Board Specific functions	*/
#define CONFIG_CMD_CACHE	/* icache, dcache		*/
#define CONFIG_CMD_CDP		/* Cisco Discovery Protocol	*/
#define CONFIG_CMD_DATE		/* support for RTC, date/time...*/
#define CONFIG_CMD_DHCP		/* DHCP Support			*/
#define CONFIG_CMD_DIAG		/* Diagnostics			*/
#define CONFIG_CMD_EEPROM	/* EEPROM read/write support	*/
#define CONFIG_CMD_FAT		/* FAT support			*/
#undef  CONFIG_CMD_FLASH	/* flinfo, erase, protect	*/
#define CONFIG_CMD_I2C		/* I2C serial bus support	*/
#undef  CONFIG_CMD_IMLS		/* List all found images	*/
#define CONFIG_CMD_IMMAP	/* IMMR dump support		*/
#define CONFIG_CMD_JFFS2	/* JFFS2 Support		*/
#define CONFIG_CMD_MII		/* MII support			*/
#define CONFIG_CMD_NAND		/* NAND support			*/
#define CONFIG_CMD_PING		/* ping support			*/
#undef  CONFIG_CMD_PORTIO	/* Port I/O			*/
#undef  CONFIG_CMD_REGINFO	/* Register dump		*/
#define CONFIG_CMD_SAVES	/* save S record dump		*/
#define CONFIG_CMD_SETEXPR	/* setexpr support		*/
#define CONFIG_CMD_SNTP		/* SNTP support			*/
#define CONFIG_CMD_IMX_FUSE	/* iMX fuse access commands	*/

#undef CONFIG_DISPLAY_BOARDINFO
#undef CONFIG_DISPLAY_CPUINFO

/*
 * Select some advanced features of the commande line parser
 */
#define CONFIG_AUTO_COMPLETE 	1	/* Enable auto completion of */
					/* commands using TAB */
#define CFG_HUSH_PARSER		1	/* enable the "hush" shell */
#define CFG_PROMPT_HUSH_PS2	"> "	/* secondary prompt string */
#define CONFIG_CMDLINE_EDITING  1

/*
 * Boot options. Setting delay to -1 stops autostart count down.
 */
#define CONFIG_BOOTDELAY	20

#define CONFIG_BOOTARGS \
	CONFIG_CONSOLE " root=/dev/mtdblock4 rootfstype=jffs2 " MTDPARTS_DEFAULT

#define CONFIG_CONSOLE "console=ttySMX0,"MK_STR(CONFIG_BAUDRATE)
#define CONFIG_MTDMAP   "mxc_nand.0"
#define MTDIDS_DEFAULT	"nand0=" CONFIG_MTDMAP
#define MTDPARTS_DEFAULT "mtdparts=" CONFIG_MTDMAP ":640k(U-boot)ro,"	\
			"384k(U-boot_env),512k(firmware),"		\
			"5M(kernel),"	\
			"-(rootfs)"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"env_version="		CONFIG_ENV_VERSION		"\0"	\
	"fileaddr="		MK_STR(CFG_LOAD_ADDR)		"\0"	\
	"filesize="		MK_STR(CFG_MONITOR_LEN)		"\0"	\
	"console="		CONFIG_CONSOLE			"\0"	\
	"mtdparts="		MTDPARTS_DEFAULT		"\0"	\
	"partition=nand0,3\0"						\
	"uboot_offset="		MK_STR(CFG_MONITOR_OFFSET)	"\0"	\
	"uboot_len="		MK_STR(CFG_MONITOR_LEN)		"\0"	\
	"env_offset="		MK_STR(CFG_ENV_OFFSET)		"\0"	\
	"env_len="		MK_STR(CFG_ENV_SIZE)		"\0"	\
	"firmware_offset="	MK_STR(CONFIG_FIRMWARE_OFFSET)	"\0"	\
	"firmware_len="	MK_STR(CONFIG_FIRMWARE_LEN)	"\0"	\
	"kernel_offset="	MK_STR(CONFIG_KERNEL_OFFSET)	"\0"	\
	"kernel_len="		MK_STR(CONFIG_KERNEL_LEN)	"\0"	\
	"rootfs_offset="	MK_STR(CONFIG_ROOTFS_OFFSET)	"\0"	\
	"rootfs_len="		MK_STR(CONFIG_ROOTFS_LEN)	"\0"	\
	"board_name="		MK_STR(CONFIG_BOARD_NAME)	"\0"	\
	"serverpath="		MK_STR(CONFIG_SRV_PATH)		"\0"	\
	"ntpserverip=217.147.208.1\0"					\
	"mmcroot=/dev/mmcblk0p1\0"					\
	"mmcrootfstype=ext2\0"						\
	"quiet=1\0"						\
	"addnfsargs=setenv bootargs ${bootargs} "			\
		"root=/dev/nfs rw nfsroot=${serverip}:${rootpath}\0"    \
	"addjffsargs=setenv bootargs ${bootargs} "			\
		"root=/dev/mtdblock4 rootfstype=jffs2\0"   		\
	"addubifsargs=setenv bootargs ${bootargs} "			\
		"ubi.mtd=rootfs root=ubi0:rootfs rootfstype=ubifs\0"   		\
	"addmmcargs=setenv bootargs ${bootargs} "			\
		"root=${mmcroot} rootfstype=${mmcrootfstype}\0"   	\
	"addipargs=setenv bootargs ${bootargs} "			\
		"ip=${ipaddr}:${serverip}:${gatewayip}:${netmask}:${hostname}::off \0"\
	"nfsboot=setenv bootargs ${console} ${mtdparts};"		\
		"run addnfsargs addipargs; setenv autostart yes;"	\
		"nboot.jffs2 A0000000 0 ${kernel_offset}\0"		\
	"jffsboot=setenv bootargs ${console} ${mtdparts};"		\
		"run addjffsargs addipargs; setenv autostart yes;"	\
		"nboot.jffs2 A0000000 0 ${kernel_offset}\0"		\
	"ubifsboot=setenv bootargs ${console} ${mtdparts};"		\
		"run addubifsargs addipargs; setenv autostart yes;"	\
		"nboot.jffs2 A0000000 0 ${kernel_offset}\0"		\
	"mmcboot=setenv bootargs ${console} ${mtdparts};"		\
		"run addmmcargs addipargs; setenv autostart yes;"	\
		"nboot.jffs2 A0000000 0 ${kernel_offset}\0"		\
	"firmware_autoload=0\0"					\
	"flash_uboot=nand unlock ${uboot_offset} ${uboot_len};"		\
		"nand erase ${uboot_offset} ${uboot_len};"		\
		"if nand write.jffs2 ${fileaddr} ${uboot_offset} ${filesize};"	\
			"then nand lock; nand unlock ${env_offset};"	\
				"echo Flashing of uboot succeed;"		\
			"else echo Flashing of uboot failed;"		\
		"fi; \0"						\
	"flash_firmware=nand erase ${firmware_offset} ${firmware_len};"\
		"if nand write.jffs2 ${fileaddr} ${firmware_offset} ${filesize} ;"\
			"then echo Flashing of Firmware succeed;"		\
			"else echo Flashing of Firmware failed;"		\
		"fi\0"							\
	"fpga_config=tftpboot ${fileaddr} $firmware_name;"\
		"run flash_firmware;"\
		"fpga load 0 ${fileaddr} ${firmware_len};\0"\
	"flash_kernel=nand erase ${kernel_offset} ${kernel_len};"	\
		"if nand write.jffs2 ${fileaddr} ${kernel_offset} ${filesize} ;"\
			"then echo Flashing of kernel succeed;"		\
			"else echo Flashing of kernel failed;"		\
		"fi\0"							\
	"flash_rootfs=nand erase clean ${rootfs_offset} ${rootfs_len};"	\
		"if nand write.jffs2 ${fileaddr} ${rootfs_offset} ${filesize};"\
			"then echo Flashing of rootfs succeed;"		\
			"else echo Flashing of rootfs failed;"		\
		"fi\0"							\
	"flash_reset_env=nand unlock ${env_offset} ${env_len};"		\
		"nand erase ${env_offset} ${env_len};"			\
		"echo Flash environment variables erased!\0"		\
	"download_uboot=tftpboot ${loadaddr} "				\
		" ${serverpath}${board_name}-u-boot.bin\0"		\
	"download_kernel=tftpboot ${loadaddr} "				\
		" ${serverpath}${board_name}-linux.bin\0"		\
	"download_rootfs=tftpboot ${loadaddr} "				\
		" ${serverpath}${board_name}-rootfs.arm.jffs2\0"	\
	"update_uboot=run download_uboot flash_uboot\0"			\
	"update_kernel=run download_kernel flash_kernel\0"		\
	"update_rootfs=run download_rootfs flash_rootfs\0"		\
	"update_all=run download_kernel flash_kernel download_rootfs "	\
		"flash_rootfs download_uboot flash_uboot\0"		\
	"unlock_regs=mw 10000008 0; mw 10020008 0\0"			\

#define CONFIG_BOOTCOMMAND	"run jffsboot"
#define CFG_AUTOLOAD		"no"

#define CONFIG_MACH_TYPE MACH_TYPE_APF27
#define CONFIG_BOOT_PARAMS_ADDR	0xa0000100

#undef CONFIG_SHOW_BOOT_PROGRESS

#define CONFIG_ETHADDR
#define CONFIG_NETMASK		255.255.255.0
#define CONFIG_IPADDR		192.168.0.10
#define CONFIG_BOARD_NAME	"apf27"
#define CONFIG_HOSTNAME		"apf27"
#define CONFIG_GATEWAYIP	192.168.0.1
#define CONFIG_SERVERIP		192.168.0.2
#define CONFIG_SRV_PATH		""
#define CONFIG_ROOTPATH		"/tftpboot/apf27-root"

/*
 * General options for u-boot. Modify to save memory foot print
 */

#define CFG_LONGHELP
#define CFG_PROMPT		"BIOS> "	/* prompt string      */
#define CFG_CBSIZE		2048		/* console I/O buffer */
#define CFG_PBSIZE (CFG_CBSIZE+sizeof(CFG_PROMPT)+16)	/* print buffer size  */
#define CFG_MAXARGS		16		/* max command args   */
#define CFG_BARGSIZE		CFG_CBSIZE	/* boot args buf size */

#define CFG_MEMTEST_START	0xA0000000	/* memtest test area  */
#define CFG_MEMTEST_END		0xA0300000	/*64MiB -1MiB*/

#define CFG_HZ			1000000		/* incrementer freq: 1 MHz   */

/*
 * Definitions related to passing arguments to kernel.
 */

#define CONFIG_CMDLINE_TAG	1	/* send commandline to Kernel        */
#define CONFIG_SETUP_MEMORY_TAGS 1	/* send memory definition to kernel */
#define CONFIG_INITRD_TAG	1	/* send initrd params                */
#undef	CONFIG_VFD			/* do not send framebuffer setup    */

/*
 * Malloc pool need to host env + 128 Kb reserve for other allocations.
 */
#define CFG_MALLOC_LEN		(CFG_ENV_SIZE + (256<<10) )

#define CFG_GBL_DATA_SIZE	256	/* size in bytes reserved for initial data */

#define CONFIG_STACKSIZE	(256<<10)	/* stack size                 */

#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4<<10)		/* IRQ stack                  */
#define CONFIG_STACKSIZE_FIQ	(4<<10)		/* FIQ stack                  */
#endif

/*
* Clocks configuration
*/
/*
 * PLL configuration
 *
 *  31 | x  |x| x x x x |x x x x x x x x x x |x x|x x x x|x x x x x x x x x x| 0
 *     |CPLM|X|----PD---|--------MFD---------|XXX|--MFI--|-----MFN-----------|
 */

#define CFG_OSC32	32768	/* 32768 or 32000 Hz crystal */
#undef  CFG_OSC26		/* there is no external 26MHz external clock */

/* MPU CLOCK source before PLL  */
/* CONFIG_SYS_CLK_FREQ (2/3 MPLL clock or ext 266 MHZ) */
#ifndef CFG_OSC26
#if (CFG_OSC32 == 32000)
#define CFG_MPCTL0_VAL		0x00211803	/* 398.998 MHz */
#define CFG_MPCTL1_VAL		0
#define CONFIG_MPLL_FREQ	399
#else /* CFG_OSC32 == 32768*/
#define CFG_MPCTL0_VAL		0x01EF15D5	/* 399.000 MHz */
#define CFG_MPCTL1_VAL		0
#define CONFIG_MPLL_FREQ	399
#endif /* CFG_OSC32 */
#else /* CFG_OSC26 in use*/
#define CFG_MPCTL0_VAL		0x00331C23	/* 399.000 MHz */
#define CFG_MPCTL1_VAL		0
#define CONFIG_MPLL_FREQ	399
#endif /* CFG_OSC26 */

#define CONFIG_SYS_CLK_FREQ	(CONFIG_MPLL_FREQ*2/3) /* 266 MHz */

/* Serial clock source before PLL (should be named CFG_SYSPLL_CLK_FREQ) */
#ifndef CFG_OSC26
/*#define CONFIG_SYSPLL_CLK_FREQ	(1024*CFG_OSC32)*/
#if (CFG_OSC32 == 32000)
#define CFG_SPCTL0_VAL		0x04A02419	/* 300.00020 MHz */
#define CFG_SPCTL1_VAL		0
#define CONFIG_SPLL_FREQ	300		/* MHz */
#else /* CFG_OSC32 == 32768*/
#define CFG_SPCTL0_VAL		0x0475206F	/* 299.99937 MHz */
#define CFG_SPCTL1_VAL		0
#define CONFIG_SPLL_FREQ	300		/* MHz */
#endif /* CFG_OSC32 */
#else /* CFG_OSC26 in use*/
/*#define CONFIG_SYSPLL_CLK_FREQ	CFG_OSC26*/
#define CFG_SPCTL0_VAL		0x040C2C07	/* 300 MHz */
#define CFG_SPCTL1_VAL		0x0
#define CONFIG_SPLL_FREQ	300		/* MHz */
#endif /* CFG_OSC26 */

/* ARM bus frequency (have to be a CONFIG_MPLL_FREQ ratio) */
#define CONFIG_ARM_FREQ		399 	/* up to 400 MHz */

/* external bus frequency (have to be a CONFIG_SYS_CLK_FREQ ratio) */
#define CONFIG_HCLK_FREQ	133 	/* (CONFIG_SYS_CLK_FREQ/2) */

#define CONFIG_PERIF1_FREQ	16	/* 16.625 MHz UART, GPT, PWM*/
#define CONFIG_PERIF2_FREQ 	33	/* 33.25 MHz CSPI and SDHC*/
#define CONFIG_PERIF3_FREQ	33	/* 33.25 MHz LCD*/
#define CONFIG_PERIF4_FREQ	33	/* 33.25 MHz CSI*/
#define CONFIG_SSI1_FREQ	66	/* 66.50 MHz SSI1*/
#define CONFIG_SSI2_FREQ	66	/* 66.50 MHz SSI2*/
#define CONFIG_MSHC_FREQ	66	/* 66.50 MHz MSHC*/
#define CONFIG_H264_FREQ	66	/* 66.50 MHz H264*/
#define CONFIG_CLK0_DIV      3  /* Divide CLK0 by 4 */
#define CONFIG_CLK0_EN       1  /* CLK0 enabled */

/* external bus frequency (have to be a CONFIG_HCLK_FREQ ratio) */
#define CONFIG_NFC_FREQ		44	/* NFC Clock up to 44 MHz wh 133MHz*/

/* external serial bus frequency (have to be a CONFIG_SPLL_FREQ ratio) */
#define CONFIG_USB_FREQ		60	/* 60 MHz */

/*
 * SDRAM definition parameter
 */
#define CONFIG_NR_DRAM_BANKS 2

#define CFG_SDRAM_MBYTE_SYZE 128

#if (CFG_SDRAM_MBYTE_SYZE == 8)
/* micron 8MB */
#define CFG_SDRAM_1_BASE	0xA0000000 /* SDRAM bank #1 32bits         */
#define CFG_SDRAM_1_SIZE	0x00800000 /* 8 MB                */
#define CFG_SDRAM_2_BASE	0xB0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_2_SIZE	0x00800000 /* 8 MB                   */
#define CFG_SDRAM_NUM_COL		8  /* 8, 9, 10 or 11 column address bits */
#define CFG_SDRAM_NUM_ROW		11 /* 11, 12 or 13 row address bits */
#define CFG_SDRAM_REFRESH		3  /* 0=OFF 1=2048 2=4096 3=8192 refresh */
#define CFG_SDRAM_EXIT_PWD		25 /* ns exit power down delay */
#define CFG_SDRAM_W2R_DELAY		1  /* write to read cycle delay > 0 */
#define CFG_SDRAM_ROW_PRECHARGE_DELAY	18 /* ns */
#define CFG_SDRAM_TMRD_DELAY		2  /* Load mode register cycle delay 1..4 */
#define CFG_SDRAM_TWR_DELAY		1  /* LPDDR: 0=2ck 1=3ck; SDRAM: 0=1ck 1=2ck*/
#define CFG_SDRAM_RAS_DELAY		42 /* ns ACTIVE-to-PRECHARGE delay */
#define CFG_SDRAM_RRD_DELAY		12 /* ns ACTIVE-to-ACTIVE delay */
#define CFG_SDRAM_RCD_DELAY		18 /* ns Row to Column delay */
#define CFG_SDRAM_RC_DELAY		70 /* ns Row cycle delay (tRFC refresh to command)*/
#define CFG_SDRAM_CLOCK_CYCLE_CL_1	20 /* ns clock cycle time estimated fo CL=1 0=force 3 for lpddr*/
#define CFG_SDRAM_PARTIAL_ARRAY_SR	0  /* 0=full 1=half 2=quater 3=Eighth 4=Sixteenth */
#define CFG_SDRAM_DRIVE_STRENGH		0  /* 0=Full-strength 1=half 2=quater 3=Eighth */
#define CFG_SDRAM_BURST_LENGTH		3  /* 2^N BYTES (N=0..3) */
#define CFG_SDRAM_SINGLE_ACCESS		0  /* 1= single access; 0 = Burst mode */
#endif

#if (CFG_SDRAM_MBYTE_SYZE == 16)
/* micron 16MB */
#define CFG_SDRAM_1_BASE	0xA0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_1_SIZE	0x01000000 /* 16 MB                   */
#define CFG_SDRAM_2_BASE	0xB0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_2_SIZE	0x01000000 /* 16 MB                   */
#define CFG_SDRAM_NUM_COL		8  /* 8, 9, 10 or 11 column address bits */
#define CFG_SDRAM_NUM_ROW		12 /* 11, 12 or 13 row address bits */
#define CFG_SDRAM_REFRESH		3  /* 0=OFF 1=2048 2=4096 3=8192 refresh */
#define CFG_SDRAM_EXIT_PWD		25 /* ns exit power down delay */
#define CFG_SDRAM_W2R_DELAY		1  /* write to read cycle delay > 0 */
#define CFG_SDRAM_ROW_PRECHARGE_DELAY	18 /* ns */
#define CFG_SDRAM_TMRD_DELAY		2  /* Load mode register cycle delay 1..4 */
#define CFG_SDRAM_TWR_DELAY		1  /* LPDDR: 0=2ck 1=3ck; SDRAM: 0=1ck 1=2ck*/
#define CFG_SDRAM_RAS_DELAY		42 /* ns ACTIVE-to-PRECHARGE delay */
#define CFG_SDRAM_RRD_DELAY		12 /* ns ACTIVE-to-ACTIVE delay */
#define CFG_SDRAM_RCD_DELAY		18 /* ns Row to Column delay */
#define CFG_SDRAM_RC_DELAY		70 /* ns Row cycle delay (tRFC refresh to command)*/
#define CFG_SDRAM_CLOCK_CYCLE_CL_1	0 /* ns clock cycle time estimated fo CL=1 0=force 3 for lpddr*/
#define CFG_SDRAM_PARTIAL_ARRAY_SR	0  /* 0=full 1=half 2=quater 3=Eighth 4=Sixteenth */
#define CFG_SDRAM_DRIVE_STRENGH		0  /* 0=Full-strength 1=half 2=quater 3=Eighth */
#define CFG_SDRAM_BURST_LENGTH		3  /* 2^N BYTES (N=0..3) */
#define CFG_SDRAM_SINGLE_ACCESS		0  /* 1= single access; 0 = Burst mode */
#endif

#if (CFG_SDRAM_MBYTE_SYZE == 32)
/* micron 32MB */
#define CFG_SDRAM_1_BASE	0xA0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_1_SIZE	0x02000000 /* 32 MB                   */
#define CFG_SDRAM_2_BASE	0xB0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_2_SIZE	0x02000000 /* 32 MB                   */
#define CFG_SDRAM_NUM_COL		9  /* 8, 9, 10 or 11 column address bits */
#define CFG_SDRAM_NUM_ROW		12 /* 11, 12 or 13 row address bits */
#define CFG_SDRAM_REFRESH		3  /* 0=OFF 1=2048 2=4096 3=8192 refresh */
#define CFG_SDRAM_EXIT_PWD		25 /* ns exit power down delay */
#define CFG_SDRAM_W2R_DELAY		1  /* write to read cycle delay > 0 */
#define CFG_SDRAM_ROW_PRECHARGE_DELAY	18 /* ns */
#define CFG_SDRAM_TMRD_DELAY		2  /* Load mode register cycle delay 1..4 */
#define CFG_SDRAM_TWR_DELAY		1  /* LPDDR: 0=2ck 1=3ck; SDRAM: 0=1ck 1=2ck*/
#define CFG_SDRAM_RAS_DELAY		42 /* ns ACTIVE-to-PRECHARGE delay */
#define CFG_SDRAM_RRD_DELAY		12 /* ns ACTIVE-to-ACTIVE delay */
#define CFG_SDRAM_RCD_DELAY		18 /* ns Row to Column delay */
#define CFG_SDRAM_RC_DELAY		70 /* ns Row cycle delay (tRFC refresh to command)*/
#define CFG_SDRAM_CLOCK_CYCLE_CL_1	0 /* ns clock cycle time estimated fo CL=1 0=force 3 for lpddr*/
#define CFG_SDRAM_PARTIAL_ARRAY_SR	0  /* 0=full 1=half 2=quater 3=Eighth 4=Sixteenth */
#define CFG_SDRAM_DRIVE_STRENGH		0  /* 0=Full-strength 1=half 2=quater 3=Eighth */
#define CFG_SDRAM_BURST_LENGTH		3  /* 2^N BYTES (N=0..3) */
#define CFG_SDRAM_SINGLE_ACCESS		0  /* 1= single access; 0 = Burst mode */
#endif

#if (CFG_SDRAM_MBYTE_SYZE == 64) /* micron MT46H16M32LF -6 */
/* micron 64MB */
#define CFG_SDRAM_1_BASE	0xA0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_1_SIZE	0x04000000 /* 64 MB                   */
#define CFG_SDRAM_2_BASE	0xB0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_2_SIZE	0x04000000 /* 64 MB                   */
#define CFG_SDRAM_NUM_COL		9  /* 8, 9, 10 or 11 column address bits */
#define CFG_SDRAM_NUM_ROW		13 /* 11, 12 or 13 row address bits */
#define CFG_SDRAM_REFRESH		3  /* 0=OFF 1=2048 2=4096 3=8192 refresh */
#define CFG_SDRAM_EXIT_PWD		25 /* ns exit power down delay */
#define CFG_SDRAM_W2R_DELAY		1  /* write to read cycle delay > 0 */
#define CFG_SDRAM_ROW_PRECHARGE_DELAY	18 /* ns */
#define CFG_SDRAM_TMRD_DELAY		2  /* Load mode register cycle delay 1..4 */
#define CFG_SDRAM_TWR_DELAY		1  /* LPDDR: 0=2ck 1=3ck; SDRAM: 0=1ck 1=2ck*/
#define CFG_SDRAM_RAS_DELAY		42 /* ns ACTIVE-to-PRECHARGE delay */
#define CFG_SDRAM_RRD_DELAY		12 /* ns ACTIVE-to-ACTIVE delay */
#define CFG_SDRAM_RCD_DELAY		18 /* ns Row to Column delay */
#define CFG_SDRAM_RC_DELAY		70 /* ns Row cycle delay (tRFC refresh to command)*/
#define CFG_SDRAM_CLOCK_CYCLE_CL_1	0 /* ns clock cycle time estimated fo CL=1 0=force 3 for lpddr*/
#define CFG_SDRAM_PARTIAL_ARRAY_SR	0  /* 0=full 1=half 2=quater 3=Eighth 4=Sixteenth */
#define CFG_SDRAM_DRIVE_STRENGH		0  /* 0=Full-strength 1=half 2=quater 3=Eighth */
#define CFG_SDRAM_BURST_LENGTH		3  /* 2^N BYTES (N=0..3) */
#define CFG_SDRAM_SINGLE_ACCESS		0  /* 1= single access; 0 = Burst mode */
#endif

#if (CFG_SDRAM_MBYTE_SYZE == 128)
/* micron 128MB */
#define CFG_SDRAM_1_BASE	0xA0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_1_SIZE	0x08000000 /* 128 MB                   */
#define CFG_SDRAM_2_BASE	0xB0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_2_SIZE	0x08000000 /* 128 MB                   */
#define CFG_SDRAM_NUM_COL		9  /* 8, 9, 10 or 11 column address bits */
#define CFG_SDRAM_NUM_ROW		14 /* 11, 12 or 13 row address bits */
#define CFG_SDRAM_REFRESH		3  /* 0=OFF 1=2048 2=4096 3=8192 refresh */
#define CFG_SDRAM_EXIT_PWD		25 /* ns exit power down delay */
#define CFG_SDRAM_W2R_DELAY		1  /* write to read cycle delay > 0 */
#define CFG_SDRAM_ROW_PRECHARGE_DELAY	18 /* ns */
#define CFG_SDRAM_TMRD_DELAY		2  /* Load mode register cycle delay 1..4 */
#define CFG_SDRAM_TWR_DELAY		1  /* LPDDR: 0=2ck 1=3ck; SDRAM: 0=1ck 1=2ck*/
#define CFG_SDRAM_RAS_DELAY		42 /* ns ACTIVE-to-PRECHARGE delay */
#define CFG_SDRAM_RRD_DELAY		12 /* ns ACTIVE-to-ACTIVE delay */
#define CFG_SDRAM_RCD_DELAY		18 /* ns Row to Column delay */
#define CFG_SDRAM_RC_DELAY		70 /* ns Row cycle delay (tRFC refresh to command)*/
#define CFG_SDRAM_CLOCK_CYCLE_CL_1	0 /* ns clock cycle time estimated fo CL=1 0=force 3 for lpddr*/
#define CFG_SDRAM_PARTIAL_ARRAY_SR	0  /* 0=full 1=half 2=quater 3=Eighth 4=Sixteenth */
#define CFG_SDRAM_DRIVE_STRENGH		0  /* 0=Full-strength 1=half 2=quater 3=Eighth */
#define CFG_SDRAM_BURST_LENGTH		3  /* 2^N BYTES (N=0..3) */
#define CFG_SDRAM_SINGLE_ACCESS		0  /* 1= single access; 0 = Burst mode */
#endif

#if (CFG_SDRAM_MBYTE_SYZE == 256)
/* micron 256MB */
#define CFG_SDRAM_1_BASE	0xA0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_1_SIZE	0x10000000 /* 256 MB                   */
#define CFG_SDRAM_2_BASE	0xB0000000 /* SDRAM bank #1 32bits    */
#define CFG_SDRAM_2_SIZE	0x10000000 /* 256 MB                   */
#define CFG_SDRAM_NUM_COL		10  /* 8, 9, 10 or 11 column address bits */
#define CFG_SDRAM_NUM_ROW		14 /* 11, 12 or 13 row address bits */
#define CFG_SDRAM_REFRESH		3  /* 0=OFF 1=2048 2=4096 3=8192 refresh */
#define CFG_SDRAM_EXIT_PWD		25 /* ns exit power down delay */
#define CFG_SDRAM_W2R_DELAY		1  /* write to read cycle delay > 0 */
#define CFG_SDRAM_ROW_PRECHARGE_DELAY	18 /* ns */
#define CFG_SDRAM_TMRD_DELAY		2  /* Load mode register cycle delay 1..4 */
#define CFG_SDRAM_TWR_DELAY		1  /* LPDDR: 0=2ck 1=3ck; SDRAM: 0=1ck 1=2ck*/
#define CFG_SDRAM_RAS_DELAY		42 /* ns ACTIVE-to-PRECHARGE delay */
#define CFG_SDRAM_RRD_DELAY		12 /* ns ACTIVE-to-ACTIVE delay */
#define CFG_SDRAM_RCD_DELAY		18 /* ns Row to Column delay */
#define CFG_SDRAM_RC_DELAY		70 /* ns Row cycle delay (tRFC refresh to command)*/
#define CFG_SDRAM_CLOCK_CYCLE_CL_1	0 /* ns clock cycle time estimated fo CL=1 0=force 3 for lpddr*/
#define CFG_SDRAM_PARTIAL_ARRAY_SR	0  /* 0=full 1=half 2=quater 3=Eighth 4=Sixteenth */
#define CFG_SDRAM_DRIVE_STRENGH		0  /* 0=Full-strength 1=half 2=quater 3=Eighth */
#define CFG_SDRAM_BURST_LENGTH		3  /* 2^N BYTES (N=0..3) */
#define CFG_SDRAM_SINGLE_ACCESS		0  /* 1= single access; 0 = Burst mode */
#endif

/*
 * Configuration for no NOR FLASH memory
 */
#define CFG_NO_FLASH

/*=====================*/
/* Flash & Environment */
/*=====================*/
#define IMX27_NAND_16BITS	1
#define CFG_MAX_NAND_DEVICE	1
#define NAND_MAX_CHIPS		1
#define CFG_NAND_BASE		(0xD8000000)
#define CONFIG_BOOT_TRACE_REG	0xAFFFFFF8 /* Addr to store traces of SPL boot */ 
//#define NAND_ALLOW_ERASE_ALL
//#define CONFIG_MTD_NAND_VERIFY_WRITE 1
//#define CFG_NAND_SELECT_DEVICE  0	/* nand driver supports mutipl. chips */
//#define CFG_NFC_DEBUG
//#define CONFIG_MTD_DEBUG
//#define CONFIG_MTD_DEBUG_VERBOSE  3
/*=====================*/

#define CONFIG_JFFS2_NAND	1
#define CONFIG_JFFS2_CMDLINE	1

#define CONFIG_NAND_U_BOOT
#define CFG_NAND_U_BOOT_DST	CFG_LOAD_ADDR	/* Copy SPL+U-Boot here	     */
#define CFG_NAND_U_BOOT_SIZE	CFG_MONITOR_LEN /* Size is the partion size  */
/*
 * Environment setup. Definitions of monitor location and size with
 * definition of environment setup ends up in 2 possibilities.
 * 1. Embeded environment - in u-boot code is space for environment
 * 2. Environment is read from predefined sector of flash
 * Right now we support 2. possiblity, but expecting no env placed
 * on mentioned address right now. This also needs to provide whole
 * sector for it - for us 256Kb is really waste of memory. U-boot uses
 * default env. and until kernel parameters could be sent to kernel
 * env. has no sense to us.
 */

#define	CFG_MONITOR_BASE	0xAFF00000
#define	CFG_MONITOR_OFFSET	0x00000000
#define	CFG_MONITOR_LEN		0x000A0000	/* 640kB ( 5 flash blocks )  */
#undef	CFG_ENV_IS_IN_FLASH 
#define CFG_ENV_IS_IN_NAND	1
/*#define CFG_ENV_IS_NOWHERE
*/
#define	CFG_ENV_OFFSET		0x000A0000	/* NAND offset address for now*/
#define	CFG_ENV_SIZE		0x00020000	/* 128kB  */
#define CFG_ENV_RANGE       0X00060000  /* 384kB ( 3 flash blocks )  */
#define	CONFIG_ENV_OVERWRITE	1		/* env is writable now   */
#define	CONFIG_FIRMWARE_OFFSET	0x00100000
#define	CONFIG_FIRMWARE_LEN	0x00080000	/* 512kB ( 4 flash blocks )  */
#define	CONFIG_KERNEL_OFFSET	0x00180000
#define	CONFIG_KERNEL_LEN	0x00500000	/* 5.0MB */
#define	CONFIG_ROOTFS_OFFSET	0x00680000
#define	CONFIG_ROOTFS_LEN			/* entire flash if not specified ~116MB*/

/*
 * Default load address for user programs and kernel
 */
#define CFG_LOAD_ADDR		0xA0000000
#define	CONFIG_LOADADDR		0xA0000000
#define CFG_TFTP_LOADADDR	0xA0000000

/*
 * Hardware drivers
 */

/* FEC IMX27 ethernet chipset */
#define CONFIG_DRIVER_FEC_IMX27  1
#undef CONFIG_FEC_IMX27_DEBUG

//#define CONFIG_NET_MULTI
#define CONFIG_PHY_ADDR		0x1f
#define CONFIG_MII		1	/* MII PHY management		*/

/*-----------------------------------------------------------------------
 * FPGA stuff
 */
#define CONFIG_FPGA
#define CONFIG_FPGA_COUNT	1
#define CONFIG_FPGA_XILINX
#define CONFIG_FPGA_SPARTAN3
#define CFG_FPGA_WAIT		20000 /* 20 ms */
#define CFG_FPGA_PROG_FEEDBACK
#define CFG_FPGA_CHECK_CTRLC
#define CFG_FPGA_CHECK_ERROR
//#define CONFIG_SYS_FPGA_IS_PROTO /* to be defined with apf27 board prototype*/

/* FPGA program pin configuration */
#define CFG_FPGA_PWR	(GPIO_PORTF | 19)	/* FPGA prog pin  */
#define CFG_FPGA_PRG	(GPIO_PORTF | 11)	/* FPGA prog pin  */
#define CFG_FPGA_CLK	(GPIO_PORTF | 15)	/* FPGA clk pin   */
#define CFG_FPGA_RDATA	0xD6000000		/* FPGA data addr  */
#define CFG_FPGA_WDATA	0xD6000000		/* FPGA data addr  */
#define CFG_FPGA_INIT	(GPIO_PORTF | 12)	/* FPGA init pin  */
#define CFG_FPGA_DONE	(GPIO_PORTF | 9)	/* FPGA done pin  */
#define CFG_FPGA_RW	(GPIO_PORTF | 21)	/* FPGA done pin  */
#define CFG_FPGA_CS	(GPIO_PORTF | 22)	/* FPGA done pin  */
#define CFG_FPGA_SUSPEND (GPIO_PORTF | 10)	/* FPGA done pin  */
#define CFG_FPGA_RESET	(GPIO_PORTF | 7)	/* FPGA done pin  */

/*
 * I2C bus
 */

#define	CONFIG_HARD_I2C		1	/* I2C with hardware support    */

#define CFG_I2C_SPEED		100000	/* 100 kHz */
#define CFG_I2C_SLAVE		0x7F

#define CONFIG_I2C_CMD_TREE
#define CONFIG_I2C_MULTI_BUS	2
#define CFG_I2C_NOPROBES 	{ }

# define CFG_I2C_EEPROM_ADDR	0x50	/* EEPROM 24LC02                */
# define CFG_I2C_EEPROM_ADDR_LEN 1	/* bytes of address             */
/* mask of address bits that overflow into the "EEPROM chip address"    */
/*#define CFG_I2C_EEPROM_ADDR_OVERFLOW	0x00*/
#define CFG_EEPROM_PAGE_WRITE_BITS	3
#define CFG_EEPROM_PAGE_WRITE_DELAY_MS	10	/* takes up to 10 msec */

#define CONFIG_RTC_DS1374
#define CFG_RTC_BUS_NUM		0
/*#define CONFIG_MMC		1
*/
/*
 * External interfaces module
 *
 * CSCRxU_VAL:
 * 31| x | x | x x |x x x x| x x | x | x  |x x x x|16
 *   |SP |WP | BCD |  BCS  | PSZ |PME|SYNC|  DOL  |
 *
 * 15| x x  | x x x x x x | x | x x x x | x x x x |0
 *   | CNC  |     WSC     |EW |   WWS   |   EDC   |
 *
 * CSCRxL_VAL:
 * 31|  x x x x  | x x x x  | x x x x  | x x x x  |16
 *   |    OEA    |   OEN    |   EBWA   |   EBWN   |
 * 15|x x x x| x |x x x |x x x x| x | x | x  | x  | 0
 *   |  CSA  |EBC| DSZ  |  CSN  |PSR|CRE|WRAP|CSEN|
 *
 * CSCRxA_VAL:
 * 31|  x x x x  | x x x x  | x x x x  | x x x x  |16
 *   |   EBRA    |   EBRN   |   RWA    |   RWN    |
 * 15| x | x x |x x x|x x|x x|x x| x | x | x  | x | 0
 *   |MUM| LAH | LBN |LBA|DWW|DCT|WWU|AGE|CNC2|FCE|
 */

/* CS0 configuration for 16 bit nor flash */
#define CFG_CS0U_VAL	0x0000CC03
#define CFG_CS0L_VAL	0xa0330D01
#define CFG_CS0A_VAL	0x00220800

#define CFG_CS1U_VAL	0
#define CFG_CS1L_VAL	0
#define CFG_CS1A_VAL	0

#define CFG_CS2U_VAL	0
#define CFG_CS2L_VAL	0
#define CFG_CS2A_VAL	0

#define CFG_CS3U_VAL	0
#define CFG_CS3L_VAL	0
#define CFG_CS3A_VAL	0

#define CFG_CS4U_VAL	0
#define CFG_CS4L_VAL	0
#define CFG_CS4A_VAL	0

/* FPGA 16 bit data bus */
#define CFG_CS5U_VAL	0x00000600
#define CFG_CS5L_VAL	0x00000D01
#define CFG_CS5A_VAL	0

#define CFG_EIM_VAL	0x00002000

/* FPGA specific settings */
/* CLKO */
#define CFG_CCSR_VAL 0x00000305
/* drive strength CLKO set to 2*/
#define CFG_DSCR10_VAL 0x00020000
/* drive strength A1..A12 set to 2*/
#define CFG_DSCR3_VAL 0x02AAAAA8
/* drive strength ctrl*/
#define CFG_DSCR7_VAL 0x00020880
/* drive strength data*/
#define CFG_DSCR2_VAL 0xAAAAAAAA


/*
 * Default configuration for GPIOs and peripherals
 */
#define CFG_DDIR_A_VAL		0x00000000  
#define CFG_OCR1_A_VAL		0x00000000  
#define CFG_OCR2_A_VAL		0x00000000
#define CFG_ICFA1_A_VAL		0xFFFFFFFF
#define CFG_ICFA2_A_VAL		0xFFFFFFFF
#define CFG_ICFB1_A_VAL		0xFFFFFFFF
#define CFG_ICFB2_A_VAL		0xFFFFFFFF
#define CFG_DR_A_VAL		0x00000000
#define CFG_GIUS_A_VAL		0xFFFFFFFF
#define CFG_ICR1_A_VAL		0x00000000
#define CFG_ICR2_A_VAL		0x00000000
#define CFG_IMR_A_VAL		0x00000000
#define CFG_GPR_A_VAL		0x00000000
#define CFG_PUEN_A_VAL		0xFFFFFFFF

#define CFG_DDIR_B_VAL		0x00000000
#define CFG_OCR1_B_VAL		0x00000000
#define CFG_OCR2_B_VAL		0x00000000
#define CFG_ICFA1_B_VAL		0xFFFFFFFF
#define CFG_ICFA2_B_VAL		0xFFFFFFFF
#define CFG_ICFB1_B_VAL		0xFFFFFFFF
#define CFG_ICFB2_B_VAL		0xFFFFFFFF
#define CFG_DR_B_VAL		0x00000000
#define CFG_GIUS_B_VAL		0xFF3FFFF0
#define CFG_ICR1_B_VAL		0x00000000
#define CFG_ICR2_B_VAL		0x00000000
#define CFG_IMR_B_VAL		0x00000000
#define CFG_GPR_B_VAL		0x00000000
#define CFG_PUEN_B_VAL		0xFFFFFFFF

#define CFG_DDIR_C_VAL		0x00000000
#define CFG_OCR1_C_VAL		0x00000000
#define CFG_OCR2_C_VAL		0x00000000
#define CFG_ICFA1_C_VAL		0xFFFFFFFF
#define CFG_ICFA2_C_VAL		0xFFFFFFFF
#define CFG_ICFB1_C_VAL		0xFFFFFFFF
#define CFG_ICFB2_C_VAL		0xFFFFFFFF
#define CFG_DR_C_VAL		0x00000000
#define CFG_GIUS_C_VAL		0xFFFFFFFF
#define CFG_ICR1_C_VAL		0x00000000
#define CFG_ICR2_C_VAL		0x00000000
#define CFG_IMR_C_VAL		0x00000000
#define CFG_GPR_C_VAL		0x00000000
#define CFG_PUEN_C_VAL		0xFFFFFF87

#define CFG_DDIR_D_VAL		0x00000000
#define CFG_OCR1_D_VAL		0x00000000
#define CFG_OCR2_D_VAL		0x00000000
#define CFG_ICFA1_D_VAL		0xFFFFFFFF
#define CFG_ICFA2_D_VAL		0xFFFFFFFF
#define CFG_ICFB1_D_VAL		0xFFFFFFFF
#define CFG_ICFB2_D_VAL		0xFFFFFFFF
#define CFG_DR_D_VAL		0x00000000
#define CFG_GIUS_D_VAL		0xFFFFFFFF
#define CFG_ICR1_D_VAL		0x00000000
#define CFG_ICR2_D_VAL		0x00000000
#define CFG_IMR_D_VAL		0x00000000
#define CFG_GPR_D_VAL		0x00000000
#define CFG_PUEN_D_VAL		0xFFFFFFFF

#define CFG_DDIR_E_VAL		0x00000000
#define CFG_OCR1_E_VAL		0x00000000
#define CFG_OCR2_E_VAL		0x00000000
#define CFG_ICFA1_E_VAL		0xFFFFFFFF
#define CFG_ICFA2_E_VAL		0xFFFFFFFF
#define CFG_ICFB1_E_VAL		0xFFFFFFFF
#define CFG_ICFB2_E_VAL		0xFFFFFFFF
#define CFG_DR_E_VAL		0x00000000
#define CFG_GIUS_E_VAL		0xFFFFCCF8
#define CFG_ICR1_E_VAL		0x00000000
#define CFG_ICR2_E_VAL		0x00000000
#define CFG_IMR_E_VAL		0x00000000
#define CFG_GPR_E_VAL		0x00000000
#define CFG_PUEN_E_VAL		0xFFFFFFFF

#define CFG_DDIR_F_VAL		0x00000000
#define CFG_OCR1_F_VAL		0x00000000
#define CFG_OCR2_F_VAL		0x00000000
#define CFG_ICFA1_F_VAL		0xFFFFFFFF
#define CFG_ICFA2_F_VAL		0xFFFFFFFF
#define CFG_ICFB1_F_VAL		0xFFFFFFFF
#define CFG_ICFB2_F_VAL		0xFFFFFFFF
#define CFG_DR_F_VAL		0x00000000
#define CFG_GIUS_F_VAL		0xFF7F8000
#define CFG_ICR1_F_VAL		0x00000000
#define CFG_ICR2_F_VAL		0x00000000
#define CFG_IMR_F_VAL		0x00000000
#define CFG_GPR_F_VAL		0x00000000
#define CFG_PUEN_F_VAL		0xFFFFFFFF

/* Enforce DDR signal strengh & enable USB/PP/DMA burst override bits */
#define CFG_GPCR_VAL		0x0003000F

/* LPDDR enable. latency hiding behavior enabled */
//#define CFG_ESDMISC_VAL		ESDMISC_MA10_SHARE+ESDMISC_MDDREN
/*
 * safe value in case of erratic crash during boot 
 *	(seen with some prototype boards)*/
#define CFG_ESDMISC_VAL	ESDMISC_LHD+ESDMISC_MDDREN

/* FMCR select num LPDDR RAMs and nand 16bits, 2KB pages */
#if (CONFIG_NR_DRAM_BANKS == 1)
#define CFG_FMCR_VAL 0xFFFFFFF9
#elif (CONFIG_NR_DRAM_BANKS == 2)
#define CFG_FMCR_VAL 0xFFFFFFFB
#endif

#define CFG_AIPI1_PSR0_VAL	0x20040304 
#define CFG_AIPI1_PSR1_VAL	0xDFFBFCFB 
#define CFG_AIPI2_PSR0_VAL	0x00000000
#define CFG_AIPI2_PSR1_VAL	0xFFFFFFFF

/* PCCR enable DMA FEC I2C1 IIM SDHC1 */
#define CFG_PCCR0_VAL		0x05070400
#define CFG_PCCR1_VAL		0xA14A0408

/* CONFIG_SKIP_LOWLEVEL_INIT bypass lowlevel init in bootstrap mode */
#undef CONFIG_SKIP_LOWLEVEL_INIT

/*
 * From here, there should not be any user configuration.
 * All Equations are automatic
 */

/* fixme none integer value (7.5ns) => 2*hclock = 15ns */
#define CFG_2XHCLK_LGTH		(2000/CONFIG_HCLK_FREQ)	/* ns */

/* USB 60 MHz ; ARM up to 400; HClK up to 133MHz*/
#ifdef CFG_OSC26
#define CSCR_MASK 0x0303800D
#else
#define CSCR_MASK 0x0300800D
#endif
#define CFG_CSCR_VAL\
	(CSCR_MASK 						\
	|((((CONFIG_SPLL_FREQ/CONFIG_USB_FREQ)-1)&0x07)<<28)	\
	|((((CONFIG_MPLL_FREQ/CONFIG_ARM_FREQ)-1)&0x03)<<12)	\
	|((((CONFIG_SYS_CLK_FREQ/CONFIG_HCLK_FREQ)-1)&0x03)<<8))

/* SSIx CLKO NFC H264 MSHC */
#define CFG_PCDR0_VAL\
	(((((CONFIG_SYS_CLK_FREQ/CONFIG_MSHC_FREQ)-1)&0x3F)<<0)	\
	|((((CONFIG_HCLK_FREQ/CONFIG_NFC_FREQ)-1)&0x0F)<<6)	\
	|(((((CONFIG_SYS_CLK_FREQ/CONFIG_H264_FREQ)-2)*2)&0x3F)<<10)\
	|(((((CONFIG_SYS_CLK_FREQ/CONFIG_SSI1_FREQ)-2)*2)&0x3F)<<16)\
	|(((CONFIG_CLK0_DIV)&0x07)<<22)\
	|(((CONFIG_CLK0_EN)&0x01)<<25)\
	|(((((CONFIG_SYS_CLK_FREQ/CONFIG_SSI2_FREQ)-2)*2)&0x3F)<<26))

/* PERCLKx  */
#define CFG_PCDR1_VAL\
	(((((CONFIG_SYS_CLK_FREQ/CONFIG_PERIF1_FREQ)-1)&0x3F)<<0)	\
	|((((CONFIG_SYS_CLK_FREQ/CONFIG_PERIF2_FREQ)-1)&0x3F)<<8)	\
	|((((CONFIG_SYS_CLK_FREQ/CONFIG_PERIF3_FREQ)-1)&0x3F)<<16)	\
	|((((CONFIG_SYS_CLK_FREQ/CONFIG_PERIF4_FREQ)-1)&0x3F)<<24))

/* SDRAM controller programming Values */
#if (((2*CFG_SDRAM_CLOCK_CYCLE_CL_1)>(3*CFG_2XHCLK_LGTH))\
	||(CFG_SDRAM_CLOCK_CYCLE_CL_1<1))
#define REG_FIELD_SCL_VAL 3
#define REG_FIELD_SCLIMX_VAL 0
#else
#define REG_FIELD_SCL_VAL\
	((2*CFG_SDRAM_CLOCK_CYCLE_CL_1+CFG_2XHCLK_LGTH-1)/CFG_2XHCLK_LGTH)
#define REG_FIELD_SCLIMX_VAL REG_FIELD_SCL_VAL
#endif

//#define REG_FIELD_SCL_VAL 3
//#define REG_FIELD_SCLIMX_VAL 3

#if ((2*CFG_SDRAM_RC_DELAY)>(16*CFG_2XHCLK_LGTH))
#define REG_FIELD_SRC_VAL 0
#else
#define REG_FIELD_SRC_VAL\
	((2*CFG_SDRAM_RC_DELAY+CFG_2XHCLK_LGTH-1)/CFG_2XHCLK_LGTH)
#endif

/* TBD Power down timer ; PRCT Bit Field Encoding; burst length 8 ; FP = 0*/
#define REG_ESDCTL_BASE_CONFIG (0x80020485\
				| (((CFG_SDRAM_NUM_ROW-11)&0x7)<<24)\
				| (((CFG_SDRAM_NUM_COL-8)&0x3)<<20)\
				| (((CFG_SDRAM_REFRESH)&0x7)<<13))

#define CFG_NORMAL_RW_CMD	((0x0<<28)+REG_ESDCTL_BASE_CONFIG)
#define CFG_PRECHARGE_CMD	((0x1<<28)+REG_ESDCTL_BASE_CONFIG)
#define CFG_AUTOREFRESH_CMD	((0x2<<28)+REG_ESDCTL_BASE_CONFIG)
#define CFG_SET_MODE_REG_CMD	((0x3<<28)+REG_ESDCTL_BASE_CONFIG)

/* ESDRAMC Configuration Registers : force CL=3 to lpddr */
#define CFG_SDRAM_ESDCFG_REGISTER_VAL (0x0\
	| (((((2*CFG_SDRAM_EXIT_PWD+CFG_2XHCLK_LGTH-1)/CFG_2XHCLK_LGTH)-1)&0x3)<<21)\
	| (((CFG_SDRAM_W2R_DELAY-1)&0x1)<<20)\
	| (((((2*CFG_SDRAM_ROW_PRECHARGE_DELAY+CFG_2XHCLK_LGTH-1)/CFG_2XHCLK_LGTH)-1)&0x3)<<18)\
	| (((CFG_SDRAM_TMRD_DELAY-1)&0x3)<<16)\
	| (((CFG_SDRAM_TWR_DELAY)&0x1)<<15)\
	| (((((2*CFG_SDRAM_RAS_DELAY+CFG_2XHCLK_LGTH-1)/CFG_2XHCLK_LGTH)-1)&0x7)<<12)\
	| (((((2*CFG_SDRAM_RRD_DELAY+CFG_2XHCLK_LGTH-1)/CFG_2XHCLK_LGTH)-1)&0x3)<<10)\
	| (((REG_FIELD_SCLIMX_VAL)&0x3)<<8)\
	| (((((2*CFG_SDRAM_RCD_DELAY+CFG_2XHCLK_LGTH-1)/CFG_2XHCLK_LGTH)-1)&0x7)<<4)\
	| (((REG_FIELD_SRC_VAL)&0x0F)<<0))

/* Issue Mode register Command to SDRAM*/
#define CFG_SDRAM_MODE_REGISTER_VAL\
	((((CFG_SDRAM_BURST_LENGTH)&0x7)<<(0))\
	| (((REG_FIELD_SCL_VAL)&0x7)<<(4))\
	| ((0)<<(3)) /* sequentiql access */ \
	/*| (((CFG_SDRAM_SINGLE_ACCESS)&0x1)<<(1))*/)

/* Issue Extended Mode register Command to SDRAM*/
#define CFG_SDRAM_EXT_MODE_REGISTER_VAL\
	((CFG_SDRAM_PARTIAL_ARRAY_SR<<0)\
	| (CFG_SDRAM_DRIVE_STRENGH<<(5))\
	| (1<<(CFG_SDRAM_NUM_COL+CFG_SDRAM_NUM_ROW+1+2)))

/* Issue Precharge all Command to SDRAM*/
#define CFG_SDRAM_PRECHARGE_ALL_VAL (1<<10)

#endif /* __CONFIG_H */

/* Add a wrapper around the values Buildroot sets. */
#ifndef __BR2_ADDED_CONFIG_H
#define __BR2_ADDED_CONFIG_H
#ifdef CONFIG_HOSTNAME
#undef CONFIG_HOSTNAME
#endif
#define CONFIG_HOSTNAME  "apf27"
#ifdef CONFIG_BOARD_NAME
#undef CONFIG_BOARD_NAME
#endif
#define CONFIG_BOARD_NAME  apf27
#endif /* __BR2_ADDED_CONFIG_H */
