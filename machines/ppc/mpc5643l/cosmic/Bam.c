/*
 * @file tpl_init_mmu.s
 *
 * @section desc File description
 *
 * BAM Start Block
 *
 * Copyright (c) 2010 by COSMIC Software
 * Modified by Kamel Hacene for Trampoline OS
 *
 * Trampoline OS
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

/*	define the RCHW value depending on the VLE model
 */
#if (WITH_VLE == YES)
# define RCHW 0x015a
#else
# define RCHW 0x005a
#endif

void tpl_master_core_startup(void);	/* startup address */

#pragma section const {rchw}

/*	RCHW is duplicated at offset 0 and offset 2
 *	to support both variants
 */
const struct bam {
	unsigned short rchw0, rchw2;
	void (*start)(void);
	} __rchw__ = {RCHW, RCHW, tpl_master_core_startup};

