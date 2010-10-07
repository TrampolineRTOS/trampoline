/**
 * @file apf27_mem_prot.c
 *
 * @section descr File description
 *
 * ARMADEUS platform : high level part of memory protection management
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date: $
 * $Rev: $
 * $Author: $
 * $URL: $
 */
#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_machine_interface.h"
#include "tpl_os_custom_types.h"
#include "tpl_os_definitions.h"
#if WITH_AUTOSAR_TIMING_PROTECTION == YES
#include "tpl_as_timing_protec.h"
#endif /* WITH_AUTOSAR_TIMING_PROTECTION */
#if WITH_AUTOSAR == YES
#include "tpl_as_isr_kernel.h"
#include "tpl_os_kernel.h"
#endif /* WITH_AUTOSAR */

#if WITH_MEMORY_PROTECTION == YES

#include "apf27_mem_prot.h"

#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"

/* Table of the translation tables base address 
 * as idle task is not count inside TASK_COUNT : => +1 */
P2VAR(u32, AUTOMATIC, OS_VAR) ttb_table[TASK_COUNT+ISR_COUNT+1];

#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"
/*
 * Memory region for the common part of each translation tables
 */
VAR(tpl_mem_region, OS_VAR) code_mem_rgn;
VAR(tpl_mem_region, OS_VAR) const_mem_rgn;
VAR(tpl_mem_region, OS_VAR) osvar_mem_rgn;
VAR(tpl_mem_region, OS_VAR) vector_table_lvl_1_mem_rgn; /* to be redefined */
VAR(tpl_mem_region, OS_VAR) vector_table_lvl_2_mem_rgn; /* to be redefined */
VAR(tpl_mem_region, OS_VAR) irq_stack_mem_rgn;
VAR(tpl_mem_region, OS_VAR) fiq_stack_mem_rgn;
VAR(tpl_mem_region, OS_VAR) svc_stack_mem_rgn;
VAR(tpl_mem_region, OS_VAR) abt_stack_mem_rgn;
VAR(tpl_mem_region, OS_VAR) und_stack_mem_rgn;
VAR(tpl_mem_region, OS_VAR) usr_stack_mem_rgn;

/* 
 * structure used for hold the current level 1 and 2
 * translation descriptors
 */
VAR(mmu_tbl_desc_pattern, OS_VAR) mp_tbl_desc_pattern;
#define OS_STOP_SEC_VAR_UNSPECIFIED
#include "tpl_memmap.h"


#define OS_START_SEC_CONST_16BIT
#include "tpl_memmap.h"

CONST(u16, OS_CONST) page_size = PAGE_SIZE; 

#define OS_STOP_SEC_CONST_16BIT
#include "tpl_memmap.h"

/*
 * table of the memory regions must be set in each translation table
 */
#define OS_START_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"
CONSTP2VAR(tpl_mem_region, AUTOMATIC, OS_VAR) 
common_mem_rgn_table[LAST_COMMON_MEM_RGN_TYPE + COUNT_EXEC_STACKS_MODE] =
{
  &code_mem_rgn,
  &const_mem_rgn,
  &osvar_mem_rgn,
  &vector_table_lvl_1_mem_rgn,
  &vector_table_lvl_2_mem_rgn,
  &irq_stack_mem_rgn,
  &fiq_stack_mem_rgn,
  &svc_stack_mem_rgn,
  &abt_stack_mem_rgn,
  &und_stack_mem_rgn,
  &usr_stack_mem_rgn,
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 *  Write in all entries of the table as faulty descriptor
 *
 *  @param    table_base_addr   Base address of the table
 *  @param    table_size    	Size of the table
 *
 */
FUNC(void, OS_CODE) armadeus_init_table(
	P2VAR(u32, OS_VAR, OS_VAR) table_base_addr,
	VAR(u32, OS_VAR) table_size)
{
	/* Pointer on the base address of the table */
	P2VAR(u32, OS_VAR, OS_VAR) first_table_entry = table_base_addr;

	/* Index of the table */
	VAR(u32, OS_VAR) i;

	/* Initialize all the table with fault descriptor */
	for(i = 0; i < table_size ; i++)
		{
		/* Fault descriptor when bit 0:1 at 0 */
			*(first_table_entry + i)= 0;
		}
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 *
 * Write in the corresponding entries of the current page table
 * the page descriptors of the current treated region part.
 *
 * @param    current_page_table    The page table to modify
 * @param    page_desc_pattern    The model of page descriptor
 * @param    current_rgn_start    The starting limit address to describe
 * 	in this page table
 * @param    current_rgn_end    The ending limit address to describe in
 * this page table
 *
 */
FUNC(void, OS_CODE) armadeus_add_page_table_entries (
	P2VAR(u32, OS_VAR, OS_VAR) 	current_page_table,
	VAR(u32, OS_VAR)			page_desc_pattern,
	P2VAR(u32, OS_VAR, OS_VAR) 	current_start,
	P2VAR(u32, OS_VAR, OS_VAR)	current_end)
{
	VAR(u16, OS_VAR)			pt_index_rgn_start; /* Start index of to set */
	VAR(u16, OS_VAR)			pt_index_rgn_end; /* End index to set */
	VAR(u16, OS_VAR) 			pt_index; /* Current index */

	P2VAR(u32, OS_VAR, OS_VAR) 	pt_current_entry; /* Current entry to set */

	VAR(u32, OS_VAR)			mp_l2_page_base_addr; /* Current page base address */

	/* Initialize the page table indexes to the entries represent
	 * the limits of the current treated region */
	pt_index_rgn_start = ((u32)current_start & PAGE_TBL_INDEX_MASK) >> 12;
	pt_index_rgn_end = (((u32)current_end - 0x1) & PAGE_TBL_INDEX_MASK) >> 12;

	/************************************************************
	 *  TODO the way page_base_addr is assign must be different
	 * when Physical Address is different of Virtual Address
	 ************************************************************/
	mp_l2_page_base_addr = (u32)current_start & PAGE_BASE_PHY_ADDR;

	/* From starting to ending index set each entry with the current page
	 * base address and the model of page descriptor */
	for (pt_index = pt_index_rgn_start; pt_index <= pt_index_rgn_end ; pt_index++)
		{
			/* Get the current entry */
			pt_current_entry = current_page_table + pt_index;

			/* To prevent corrupted memory protection structures
			 * if the entry is not empty, locked in infinity loop */
			if (*pt_current_entry != 0)
				while (1);

			/* Set the current entry */
			*pt_current_entry = mp_l2_page_base_addr + page_desc_pattern;

			/* Set the current page base address to the next page */
			mp_l2_page_base_addr += PAGE_SIZE;
		}
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"


#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * Write in the corresponding entries of the current translation table
 * the page table descriptors of the current treated region.
 * Ask to set the corresponding page table entries.
 *
 * @param    mmu_structures.ptb    base address of the current page table
 * @param    mp_patterns    the models of the page table and page descriptors
 * @param    rgn_start     start address of the current region
 * @param    rgn_end    end address of the current region
 *
 * @retval mmu_structures.ptb    base address of the current page table
 */
FUNC(u32*, OS_CODE) armadeus_add_region_in_mmu_tables (
	VAR(mmu_tables, OS_VAR) 	mmu_structures,
	P2VAR(mmu_tbl_desc_pattern, OS_VAR, OS_VAR)	mp_patterns,
	P2VAR(u32, OS_VAR, OS_VAR) 	rgn_start,
	P2VAR(u32, OS_VAR, OS_VAR)	rgn_end)
{
	/* indexes */
	VAR(u16, OS_VAR)			tt_index_rgn_start; /* Start index of to set */
	VAR(u16, OS_VAR)			tt_index_rgn_end; /* End index of to set */
	VAR(u16, OS_VAR) 			tt_index; /* Current index */

	/*current values*/
	P2VAR(u32, OS_VAR, OS_VAR) 	tt_current_entry; /* Current entry to set */
	P2VAR(u32, OS_VAR, OS_VAR) 	current_tt_rgn_start; /* Start of the current part of the region is treated*/
	P2VAR(u32, OS_VAR, OS_VAR) 	current_tt_rgn_end; /* End of the current part of the region is treated*/

	P2VAR(u32, OS_VAR, OS_VAR) 	ptb_saved; /* Backup of the current page table baése address */

	VAR(u32, OS_VAR) 			mp_l1_page_tbl_base_addr; /* Page table base address used for
														   * set the current entry*/

	/* Initialize the translation table indexes to the entries represent
	 * the limits of the current region */
	tt_index_rgn_start = ((u32)rgn_start & TRANS_TBL_INDEX_MASK) >> 20;
	tt_index_rgn_end = (((u32)rgn_end - 0x1) & TRANS_TBL_INDEX_MASK) >> 20;
	/* "- 0x1" because the end symbol in ldscript represent
	 * the first address after the region */

	/* From starting to ending index set each entry with the current page
	 * table base address and the model of page table descriptor */
	for (tt_index = tt_index_rgn_start; tt_index <= tt_index_rgn_end; tt_index++)
	{
		ptb_saved = 0;
		armadeus_init_table(mmu_structures.ptb, PAGE_TBL_SIZE);

		/* Get the current translation table entry */
		tt_current_entry = mmu_structures.ttb + tt_index;

		/* If the current is not empty saved the current page table address and
		 * get the page table address set in the entry */
		if(*tt_current_entry !=0)
		{
			ptb_saved = mmu_structures.ptb;
			mmu_structures.ptb = (u32 *)(*tt_current_entry & TRANS_TBL_PTB_MASK);
		}
		else
		{
		/* If empty set the entry with the current page table address */
			mp_l1_page_tbl_base_addr = (u32)mmu_structures.ptb & TRANS_TBL_PTB_MASK;
			*tt_current_entry = mp_l1_page_tbl_base_addr + mp_patterns -> tt_lvl_1;
		}

		/* Set the limits of virtual memory describe by the current entry */
		current_tt_rgn_start = (u32 *) (tt_index << 20);
		current_tt_rgn_end = current_tt_rgn_start + (ONE_MB >> 2);

		/* Set the limits of virtual memory useful for describe the region
		 * inside the current 1 Mb describe by the current entry */

		if (rgn_start > current_tt_rgn_start)
			current_tt_rgn_start = rgn_start;

		if (rgn_end < current_tt_rgn_end)
			current_tt_rgn_end = rgn_end;

		/* Add the corresponding entries inside the current page table */
		armadeus_add_page_table_entries (mmu_structures.ptb,
										mp_patterns -> pt_lvl_2,
										current_tt_rgn_start,
										current_tt_rgn_end);
		/* Restore the value of the current page table base address
		 * if it was saved or set it to the next one*/
		if(ptb_saved != 0)
			mmu_structures.ptb = ptb_saved;
		else mmu_structures.ptb += (PAGE_TBL_SIZE >> 2);
	}
	return mmu_structures.ptb;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"





	/***************************************************************
 	*
 	* ----------------- For translation table ------------------
 	*
 	*
 	*          	L1 - Coarse page table descriptor
 	* bit
 	*  31                      10 | 9 | 8    5 | 4 | 3 2 | 1 | 0
 	* ------------------------------------------------------------
 	* | Coarse page tbl base addr | 0 | Domain | 1 | 0 0 | 0 | 1 |
 	* ------------------------------------------------------------
 	*
 	* In this portage Domain always equal to 0000
 	*
 	***************************************************************/
 	/**************************************************************
 	*
 	* --------------------- For page table ---------------------
 	*
 	*
 	*              	L2 - Small page descriptor
 	* bit
 	*  31            12 | 11 10 | 9 8 | 7 6 | 5 4 | 3 | 2 | 1 | 0
 	* ------------------------------------------------------------
 	* |  Page base addr |  AP3  | AP2 | AP1 | AP0 | C | B | 1 | 0 |
 	* ------------------------------------------------------------
 	****************************************************************/
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 *
 * Set the patterns for translation table and page table entries.
 *
 * @param    rgn_type  type of the region depend of what type of objects
 * is inside.
 *
 * @retval    mp_l1_l2_patterns    Models of level 1 (page table descriptor)
 * and level 2 (page descriptor) descriptors used
 * to set the entries of translation table and page table
 */
FUNC(mmu_tbl_desc_pattern*, OS_CODE) armadeus_set_mp_table_entries_pattern(
	VAR(u8, OS_VAR) rgn_type)
{
	VAR(u8, OS_VAR) access_perm;
	P2VAR(mmu_tbl_desc_pattern, OS_VAR, OS_VAR)	mp_l1_l2_patterns;


	mp_l1_l2_patterns = &mp_tbl_desc_pattern;


	/* Apply the good access permission */
	switch(rgn_type)
	{
		case PRIVATE_VAR_RGN 	:
		case PRIVATE_STACK_RGN 	:
		case OWN_OSAP_VAR_RGN	:
			access_perm = READ_WRITE;
			break;

		case CODE_RGN 			:
		case CONST_RGN 			:
		case VECTOR_TABLE_1_RGN :
		case VECTOR_TABLE_2_RGN	:
			access_perm = READ_ONLY;
			break;

		case OSVAR_RGN			:
		case EXEC_STACKS_RGN 	:
			access_perm = NO_ACCESS;
			break;

		/* TODO device_rgn memory protection
		 * how on the armadeus-apf27 card the registers of each device
		 * are align on 1K.
		 * One function can easly test if one device is assigned at
		 * one OS-Application.
		 */
		case DEVICE_RGN :
			break;

		default :
			access_perm = NO_ACCESS;
			break;
	}

	/*
	 * Set entries patterns for Coarse Page Table descriptor and
	 * Small Page descriptor
	 */
	mp_l1_l2_patterns -> tt_lvl_1 = TRANS_TBL_COARSE_DESC_TYPE;
	mp_l1_l2_patterns -> pt_lvl_2 = (access_perm << 4) + PAGE_TBL_SMALL_DESC_TYPE;

	return mp_l1_l2_patterns;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"



#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * Calculate de number of regions described by the current
 * memory protection descriptor.
 * For each region launch the table entry pattern setting and
 * the routine for modify tables used by the MMU.
 *
 * @param    mmu_structures.ptb    base address of the current page table
 * @param    target_mp_desc    the current memory protection descriptor
 *
 * @retval    mmu_structures.ptb   base address of the current page table
 *
 */
FUNC(u32*, OS_CODE) armadeus_build_mp_context_specific(
	VAR(mmu_tables, OS_VAR) mmu_structures,
	P2VAR(tpl_mem_prot_desc, OS_VAR, OS_VAR) target_mp_desc)
{

	VAR(u32, OS_VAR) 			how_many_mem_rgn;
	VAR(u8, OS_VAR)				rgn_type;
	P2VAR(u32, OS_VAR, OS_VAR) 	rgn_start;
	P2VAR(u32, OS_VAR, OS_VAR) 	rgn_end;
	P2VAR(tpl_mem_region, OS_VAR, OS_VAR) mem_rgn_desc;
	P2VAR(mmu_tbl_desc_pattern, OS_VAR, OS_VAR)	mp_patterns;
	VAR(u8, OS_VAR)  specific_mem_rgn_index;

	/* The memory protection descriptor is used here like table
	 * as all field have the same type */
	how_many_mem_rgn = (sizeof *target_mp_desc) / sizeof(tpl_mem_region);

	for (specific_mem_rgn_index=0;
		specific_mem_rgn_index < how_many_mem_rgn;
		specific_mem_rgn_index++)
	{
		mem_rgn_desc = (tpl_mem_region *) target_mp_desc + specific_mem_rgn_index;
		rgn_start = 	(u32 *) mem_rgn_desc -> start;
		rgn_end = 		(u32 *) mem_rgn_desc -> end;

		rgn_type = LAST_COMMON_MEM_RGN_TYPE + 1 + specific_mem_rgn_index;
		armadeus_set_mp_table_entries_pattern(rgn_type);

		mmu_structures.ptb =
			armadeus_add_region_in_mmu_tables (mmu_structures, mp_patterns,
											   rgn_start, rgn_end);
	}
	return mmu_structures.ptb;
}

/**
 * For each common region launch the table entry pattern setting and
 * the routine for modify tables used by the MMU.
 *
 * @param    mmu_structures.ptb    base address of the current page table
 * @param    target_mp_desc    the current memory protection descriptor
 *
 * @retval    mmu_structures.ptb   base address of the current page table
 *
 */
FUNC(u32*, OS_CODE) armadeus_build_mp_context_common(
	VAR(mmu_tables, OS_VAR) mmu_structures)
{
	P2VAR(u32, OS_VAR, OS_VAR) 	rgn_start;
	P2VAR(u32, OS_VAR, OS_VAR) 	rgn_end;
	P2VAR(mmu_tbl_desc_pattern, OS_VAR, OS_VAR)	mp_patterns;
	VAR(u8, OS_VAR)  common_mem_rgn_index;

	for (common_mem_rgn_index=0;
		common_mem_rgn_index < LAST_COMMON_MEM_RGN_TYPE + COUNT_EXEC_STACKS_MODE;
		common_mem_rgn_index++)
	{
		rgn_start = 	(u32 *) common_mem_rgn_table[common_mem_rgn_index] -> start;
		rgn_end = 		(u32 *) common_mem_rgn_table[common_mem_rgn_index] -> end;

		if(common_mem_rgn_index < LAST_COMMON_MEM_RGN_TYPE)
			mp_patterns = armadeus_set_mp_table_entries_pattern(common_mem_rgn_index);
		else
			mp_patterns = armadeus_set_mp_table_entries_pattern(LAST_COMMON_MEM_RGN_TYPE);

		mmu_structures.ptb =
			armadeus_add_region_in_mmu_tables (mmu_structures, mp_patterns,
												rgn_start, rgn_end);
	}
	return mmu_structures.ptb;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"



#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 *
 * Build the memory protection structures for each memory
 * protection context.
 *
 */
FUNC(void, OS_CODE) armadeus_build_mp()
{
	/* The current translation and page table base addresses */
	VAR(mmu_tables, OS_VAR) current_mmu_tables;

	/* TODO add HOOK_COUNT*/
	CONST(int, OS_APPL_CONST) nb_mp_ctx = TASK_COUNT + ISR_COUNT;

	/* Pointer on the current memory protection descriptor */
	P2VAR(tpl_mem_prot_desc, OS_VAR, OS_VAR) current_mp_desc;

	/* Index on the table of pointer of translation table base address */
	VAR(int, OS_VAR) ttb_table_index;


	/* Initialize tables base addresses */

	/* The first translation table base address minus TRANS_TBL_SIZE */
	current_mmu_tables.ttb = (u32 *) (&(__SEG_START_MMU_TT_RGN));

	/* The first page table base address minus PAGE_TBL_SIZE */
	current_mmu_tables.ptb = (u32 *) (&(__SEG_START_MMU_PT_RGN));


	/* For each process build memory protection context */
	for (ttb_table_index=0;	ttb_table_index < nb_mp_ctx; ttb_table_index++)
	{
		/* Push the current translation table address in the ttb_table */
		ttb_table[ttb_table_index]= current_mmu_tables.ttb;

		/* Initialize the current translation and page tables */
		armadeus_init_table(current_mmu_tables.ttb, TRANS_TBL_SIZE);

		/* Get the memory protection descriptor of the process*/
		current_mp_desc = tpl_mp_table[ttb_table_index];

		/* Build the part is common to each memory protection context */
		current_mmu_tables.ptb = armadeus_build_mp_context_common (current_mmu_tables);

		/* Build the part is specific to the current memory protection context */
		current_mmu_tables.ptb = armadeus_build_mp_context_specific (current_mmu_tables, current_mp_desc);

		/* Set the new page and translation tables base addresses */
		current_mmu_tables.ttb += (TRANS_TBL_SIZE >> 2);
		/*current_mmu_tables.ptb = current_mmu_tables.ptb + (PAGE_TBL_SIZE >> 2);*/


	}

	/* TODO when idle will become a normal task set mp with it's own
	 * mp descriptor like the other processes */
	armadeus_init_table(current_mmu_tables.ttb, TRANS_TBL_SIZE);

	ttb_table[nb_mp_ctx] = current_mmu_tables.ttb;
	/* Only the memory protection context common part is need as long as
	 * idle task don't have stack and data */
	current_mmu_tables.ptb = armadeus_build_mp_context_common (current_mmu_tables);
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"



#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 *
 * Initialized the common memory protection descriptor
 */
FUNC(void, OS_CODE) armadeus_init_common_mp_descriptor()
{
	/* This descriptor is used for describe in each translation
	 * table, the right accesses of each common regions.
	 * Because when the execution pass in kernel level mode
	 * some accesses are necessary in these regions.
	 * In future, if OS have invoke level just the regions used
	 * in this level are needed*/
	code_mem_rgn.start = &(__SEG_START_CODE_RGN);
  	code_mem_rgn.end = &(__SEG_END_CODE_RGN);
  	const_mem_rgn.start = &(__SEG_START_CONST_RGN);
  	const_mem_rgn.end = &(__SEG_END_CONST_RGN);
  	osvar_mem_rgn.start = &(__SEG_START_OS_VAR_RGN);
  	osvar_mem_rgn.end = &(__SEG_END_OS_VAR_RGN);
  /* TODO: rebuild other system memory region only if required */
/*  	vector_table_lvl_1_mem_rgn.start = &(__SEG_START_VECTOR_TABLE_LVL_1);
  	vector_table_lvl_1_mem_rgn.end = &(__SEG_END_VECTOR_TABLE_LVL_1);
  	vector_table_lvl_2_mem_rgn.start = &(__SEG_START_VECTOR_TABLE_LVL_2);
  	vector_table_lvl_2_mem_rgn.end = &(__SEG_END_VECTOR_TABLE_LVL_2);
  	irq_stack_mem_rgn.start = &(__SEG_START_IRQ_STACK_RGN);
  	irq_stack_mem_rgn.end = &(__SEG_END_IRQ_STACK_RGN);
	fiq_stack_mem_rgn.start = &(__SEG_START_FIQ_STACK_RGN);
	fiq_stack_mem_rgn.end = &(__SEG_END_FIQ_STACK_RGN);
	svc_stack_mem_rgn.start = &(__SEG_START_SVC_STACK_RGN);
	svc_stack_mem_rgn.end = &(__SEG_END_SVC_STACK_RGN);
	abt_stack_mem_rgn.start = &(__SEG_START_ABT_STACK_RGN);
	abt_stack_mem_rgn.end = &(__SEG_END_ABT_STACK_RGN);
	und_stack_mem_rgn.start = &(__SEG_START_UND_STACK_RGN);
	und_stack_mem_rgn.end = &(__SEG_END_UND_STACK_RGN);
	usr_stack_mem_rgn.start = &(__SEG_START_USR_STACK_RGN);
	usr_stack_mem_rgn.end = &(__SEG_END_USR_STACK_RGN);*/
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"



#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/**
 * Launch the initialization of all memory protection descriptors
 * and the memory protection building process.
 */
FUNC(void, OS_CODE) tpl_init_mp()
{
	/* Initialize the common memory protection descriptor */
	armadeus_init_common_mp_descriptor();

	/* Build the memory protection */
	armadeus_build_mp();
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_MEMORY_PROTECTION */

