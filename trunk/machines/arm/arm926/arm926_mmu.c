/**
 * @file arm926_mmu.c
 *
 * @section descr File description
 *
 * Driver for memory management unit of ARM926EJ-S CPU
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

#include "arm926_mmu.h"

/**
 * this is not a variable but a symbol defined by
 * linker. So, &MMU_page_table_count (address of this
 * pseudo variable) gives the number of page tables
 * that are required to describe "self" part of
 * MMU configuration.
 */
extern u8 MMU_page_table_count;

/**
 * this points on the area where page tables will be stored.
 *
 * Note that we cannot know the number of page tables before linking.
 * That's why the linker allocates the right size. To access each
 * page table, the macro page_table should be used
 */
extern u8 MMU_page_tables;

/* the following symbols are defined in the linker script */
extern u8 MMU_page_tables_end;
extern u8 MMU_start_custom_zone;
extern u8 MMU_end_custom_zone;

/**
 * MMU translation tables. There is one for each context.
 */
extern MMU_translation_table MMU_translation_tables[TASK_COUNT+ISR_COUNT+1];

#define TT_INDEX(address) ((((u32)address) >> 20) & 0xFFF)

/**
 * MMU page tables. There is a set of page table for each context.
 * A set of page tables contains as much as needed table to cover
 * the whole trampoline and application (each page table covers
 * 1 MB of memory space).
 *
 * Pages tables are fine page tables filled with tiny pages.
 * 
 * @note The type of this macro's expression is <tt>MMU_second_level_descriptor *</tt>
 *
 * @param process_id related process' identifier
 * @param table_number number of the page table іn the process's page table set
 */
#define PAGE_TABLE_ADDRESS(process_id,table_number) (((MMU_second_level_descriptor*)&MMU_page_tables)+(((process_id)*((u32)&MMU_page_table_count))+(table_number))*1024)

/**
 * returns the index in a fine page table of an address
 */
#define PAGE_TABLE_ENTRY_INDEX(address) ((((u32)address) >> 10) & 0x3FF)

/**
 * Access directly a page table entry of a process. 
 *
 * @note the type of this macro's expression is <tt>MMU_second_level_descriptor</tt>
 *
 * @param process_id related process's identifier
 * @param address any virtual address which is related to the page table entry
 */
#define PAGE_TABLE_ENTRY(process_id,table_number,address) PAGE_TABLE_ADDRESS(process_id,table_number)[PAGE_TABLE_ENTRY_INDEX(address)]

/**
 * gives the index of an address in a translation table
 */
#define TTABLE_INDEX(address) ((((u32)address) >> 20 ) & 0xFFF)

/**
 * Returns the number of tiny page needed for the specified interval
 */
#define PAGE_COUNT(start_address,end_address) ((((u32)end_address - (u32)start_address) >> 10) & 0x3FF)

/**
 * gives a section descriptor for the specified address
 */
#define SYSTEM_SECTION(address) ((MMU_section_descriptor){ \
.type = 2, \
.buffered = 0, \
.cacheable = 0, \
.must_be_one = 1, \
.domain = 0, \
.access_permission = 1, \
.section_base_address = ((address) >> 20) & 0xFFF})

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) MMU_init (void)
{
  u32 *zero_ptr;
  u32 i;
  u32 page_table_total_entries_count;

  /* clears all translation tables */
  zero_ptr = (u32*)&MMU_translation_tables;
  while ((u8*)zero_ptr != (u8*)&MMU_translation_tables+sizeof(MMU_translation_tables))
    *(zero_ptr++) = 0;
  
  /* clears all page tables */
  page_table_total_entries_count  = TASK_COUNT + ISR_COUNT + 1; /* number of processes */
  page_table_total_entries_count *= (u32)&MMU_page_table_count; /* number of page tables in a process' page table set */
  page_table_total_entries_count *= 1024;                       /* number of entries in each (fine) page table */
  zero_ptr = (u32*)&MMU_page_tables;
  for (i = 0 ; i < page_table_total_entries_count ; i++)
    *(zero_ptr++) = 0;
  
  /* setup MMU domains (we use only domain 0 as client, others generates domain fault) */
  __asm__ ("mov r0, #1\n"
           "mcr p15, 0, r0, c3, c0, 0");
}

/**
 * This function allocates a whole section (area of 1MB) with rights for kernel only.
 *
 * @param this_process process for which the area should be allocated
 * @param address first address of the area
 * @param cacheable 1 if section is cacheable, otherwise 0
 *
 * @pre address should be aligned to 1MB boundary
 * @pre size of area is 1MB
 * @pre area is not already configured (no page configured inside it)
 */
FUNC(void, OS_CODE) MMU_set_system_section (tpl_task_id this_process, u32 address, CacheableMemoryArea cacheable)
{
  MMU_first_level_descriptor value = {
    .section = {
      .type = 2,  
      .buffered = 0,
      .cacheable = 0,
      .must_be_one = 1,
      .domain = 0, 
      .must_be_zero1 = 0,
      .access_permission = 1,
      .must_be_zero2 = 0
    }
  };
 
  if (cacheable == CACHEABLE)
  {
    value.section.buffered = 1;
    value.section.cacheable = 1;
  }
    
  value.section.section_base_address = address >> 20;
  MMU_translation_tables[this_process][TT_INDEX(address)].raw = value.raw;
}

/**
 * This function allocateѕ all tiny pages needed for the specified area. Pages are allocated throught
 * the translation table and the page table set of the specified process. Access permissions are applied
 * as given (see parameters for details).
 *
 * @param this_process process for which the area should be allocated
 * @param from first address of the area (must be aligned to 1KB)
 * @param to first address after the area (ie <tt>to</tt> is not included in the area but marks the
 * end of the area
 * @param this_access_permission access permissions to be set, this can be :
 * - 1 : privileged only access (kernel and trusted only)
 * - 2 : read only access (kernel and trusted can also write)
 * - 3 : read and write access (for untrusted, trusted and kernel)
 * @param cacheable 1 if section is cacheable, otherwise 0
 *
 * @pre from must be aligned to 1KByte boundary
 * @pre to must be greater or equals to from
 * @pre this_process must be a valid process identifier
 * @pre this_access_permission must equals to 1, 2 or 3
 * @pre any page in this area must not have been setup by this function for this process
 */
FUNC(void, OS_CODE) MMU_set_tiny_pages_area (tpl_task_id this_process, u8 *from, u8 *to, u8 this_access_permission, CacheableMemoryArea cacheable)
{
  u32 ttable_index;          /* variable index in translation table */
  u32 page_table_number;     /* current page table number in the page table set of the process */
  u8 *current_page_address;  /* start address of current processed page */
  MMU_first_level_descriptor fst_lvl_template = {.fine = {.type = 3, .must_be_one = 1, .domain = 0}};
  MMU_second_level_descriptor scd_lvl_template = {.tiny_page = {.type = 3, .buffered = 1, .cacheable = 1, .access_permission = this_access_permission}}; /* cached */

  if (cacheable == CACHEABLE)
  {
    scd_lvl_template.tiny_page.buffered = 1;
    scd_lvl_template.tiny_page.cacheable = 1;
  }

  if (from != to)
  {
    page_table_number = ((u32)from - (u32)&MMU_start_custom_zone) >> 20;
    current_page_address = from;
    ttable_index = TTABLE_INDEX(from);
    do
    {
      /* set the first level descriptor */
      MMU_translation_tables[this_process][TTABLE_INDEX(current_page_address)].raw = fst_lvl_template.raw;
      MMU_translation_tables[this_process][TTABLE_INDEX(current_page_address)].fine.fine_page_table_base_address =
         ((((u32)(PAGE_TABLE_ADDRESS(this_process,page_table_number))) & 0xFFFFF000) >> 12);
      
      do
      {
        PAGE_TABLE_ENTRY (this_process, page_table_number, current_page_address).raw = scd_lvl_template.raw;
        PAGE_TABLE_ENTRY (this_process, page_table_number, current_page_address).tiny_page.page_base_address =
           (((u32)current_page_address) & 0xFFFFFC00) >> 10;

        current_page_address += 1024; /* next page starts 1KB after */
      }
      while ((((u32)current_page_address) & 0xFFFFF) &&  /* if it ends at MByte boundary, we must set next ttable entry */
             (((u32)current_page_address) < ((u32)to))); 
      ttable_index++;
      page_table_number++;
    }
    while (((u32)current_page_address) < ((u32)to));
  }
}

FUNC(void, OS_CODE) MMU_set_system_area (tpl_task_id this_process, u8 *from, u8 *to, CacheableMemoryArea cacheable)
{
  MMU_set_tiny_pages_area (this_process, from, to, 1, cacheable);
}

FUNC(void, OS_CODE) MMU_set_readonly_area (tpl_task_id this_process, u8 *from, u8* to, CacheableMemoryArea cacheable)
{
  MMU_set_tiny_pages_area (this_process, from, to, 2, cacheable);
}

FUNC(void, OS_CODE) MMU_set_readwrite_area (tpl_task_id this_process, u8* from, u8 *to, CacheableMemoryArea cacheable)
{
  MMU_set_tiny_pages_area (this_process, from, to, 3, cacheable);
}

FUNC(void, OS_CODE) MMU_enable (void)
{
  /* note : we don't have to take care about the following pipelined instructions
   * as virtual addresses equals physical addresses */
  __asm__ ("mrc p15, 0, r1, c1, C0, 0\n"
           "orr r1, r1, #0b11\n"
           "mcr p15, 0, r1, c1, C0, 0");
}

FUNC(void, OS_CODE) MMU_disable (void)
{
  /* note : we don't have to take care about the following pipelined instructions
   * as virtual addresses equals physical addresses */
  __asm__ ("mrc p15, 0, r1, c1, C0, 0\n"
           "bic r1, r1, #0b11\n"
           "mcr p15, 0, r1, c1, C0, 0");
}

FUNC(void, OS_CODE) MMU_set_current_process (tpl_task_id this_process)
{
  register u32 base_address;

  base_address = (u32)&MMU_translation_tables[this_process];

  __asm__ ("mcr p15, 0, %[ba], c2, c0, 0\n" /* sets translation table base address */
           "mcr p15, 0, %[z], c8, c7, 0"   /* invalidate TLB */
           :
           : [ba]"r" (base_address), [z]"r" (0));
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif /* WITH_MEMORY_PROTECTION */

