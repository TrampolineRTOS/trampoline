/**
 * @file arm926_mmu.h
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
#ifndef ARM926_MMU_H
#define ARM926_MMU_H

#include "tpl_os_internal_types.h"
#include "tpl_os_definitions.h"
#include "tpl_os_mem_prot.h"

/**
 */
typedef enum
{
  CACHEABLE,
  NONCACHEABLE
} CacheableMemoryArea;

/**
 * type must be 1. 
 * See "ARM926EJ-S Technical Reference Manual" for
 * more details.
 */
typedef struct {
  unsigned int type : 2;
  unsigned int unused1 : 2;
  unsigned int must_be_one : 1;
  unsigned int domain : 4;
  unsigned int unused2 : 1;
  unsigned int coarse_page_table_table_address : 22;
} MMU_coarse_page_table_descriptor;

/**
 * type must be 2. 
 * See "ARM926EJ-S Technical Reference Manual" for
 * more details.
 */
typedef struct {
  unsigned int type : 2;
  unsigned int buffered : 1;
  unsigned int cacheable : 1;
  unsigned int must_be_one : 1;
  unsigned int domain : 4;
  unsigned int must_be_zero1 : 1;
  unsigned int access_permission : 2;
  unsigned int must_be_zero2 : 8;
  unsigned int section_base_address : 12;
} MMU_section_descriptor;

/**
 * type must be 3. 
 * See "ARM926EJ-S Technical Reference Manual" for
 * more details.
 */
typedef struct {
  unsigned int type : 2;
  unsigned int unused : 2;
  unsigned int must_be_one : 1;
  unsigned int domain : 4;
  unsigned int must_be_zero : 3;
  unsigned int fine_page_table_base_address : 20;
} MMU_fine_page_table_descriptor;

typedef union {
  u32 raw;
  MMU_coarse_page_table_descriptor coarse;
  MMU_section_descriptor section;
  MMU_fine_page_table_descriptor fine;
} MMU_first_level_descriptor;

typedef MMU_first_level_descriptor MMU_translation_table[4096];

typedef struct {
  unsigned int type : 2;
  unsigned int buffered : 1;
  unsigned int cacheable : 1;
  unsigned int access_permission_0 : 2;
  unsigned int access_permission_1 : 2;
  unsigned int access_permission_2 : 2;
  unsigned int access_permission_3 : 2;
  unsigned int unused : 4;
  unsigned int page_base_address : 16;
} MMU_large_page_descriptor;

typedef struct {
  unsigned int type : 2;
  unsigned int buffered : 1;
  unsigned int cacheable : 1;
  unsigned int access_permission_0 : 2;
  unsigned int access_permission_1 : 2;
  unsigned int access_permission_2 : 2;
  unsigned int access_permission_3 : 2;
  unsigned int page_base_address : 20;
} MMU_small_page_descriptor;

typedef struct {
  unsigned int type : 2;
  unsigned int buffered : 1;
  unsigned int cacheable : 1;
  unsigned int access_permission : 2;
  unsigned int unused : 4;
  unsigned int page_base_address : 22;
} MMU_tiny_page_descriptor;

typedef union {
  u32 raw;
  MMU_large_page_descriptor large_page;
  MMU_small_page_descriptor small_page;
  MMU_tiny_page_descriptor tiny_page;
} MMU_second_level_descriptor;

typedef MMU_second_level_descriptor MMU_coarse_page_table[256];

typedef MMU_second_level_descriptor MMU_fine_page_table[1024];

/**
 * This function clears the MMU tables. It must be called once
 * before any other MMU table setup function.
 *
 * It also prepares the MMU to be enabled (but you need to setup
 * MMU tables first).
 *
 * Note that MMU is not enabled by this function.
 */
extern FUNC(void, OS_CODE) MMU_init (void);

/**
 * This function setup MMU tables of a process for board's specific
 * system areas
 *
 * @param this_process process id for which the area is configured
 *
 * @note this function is given in terminal architecture port (eg armadeus-apf27)
 */
extern FUNC(void, OS_CODE) MMU_set_board_system_areas (tpl_task_id this_process);

/**
 * This function setup MMU tables of a process for a system reserved
 * area. This areas cannot be accessed by an untrusted processes.
 *
 * @param this_process process id for which the area is configured
 * @param from start address of the area
 * @param to address that immediatly follows the area
 * @param cacheable 1 if section is cacheable, otherwise 0
 *
 * @pre from is aligned to 1KByte
 * @pre to point just after the area
 * @pre since #MMU_init_tables call, this area has not been setup (conflicting
 * configurations not detected)
 * @pre this_process is a valid process identifier
 */
extern FUNC(void, OS_CODE) MMU_set_system_area (tpl_task_id this_process, u8 *from, u8 *to, CacheableMemoryArea cacheable);

/**
 * This function setup MMU tables of a process for a read only area.
 *
 * @param this_process process id for which the area is configured
 * @param from start address of the area
 * @param to address that immediatly follows the area
 * @param cacheable 1 if section is cacheable, otherwise 0
 *
 * @pre from is aligned to 1KByte
 * @pre to point just after the area
 * @pre since #MMU_init_tables call, this area has not been setup (conflicting
 * configurations not detected)
 * @pre this_process is a valid process identifier
 */
extern FUNC(void, OS_CODE) MMU_set_readonly_area (tpl_task_id this_process, u8 *from, u8* to, CacheableMemoryArea cacheable);

/**
 * This function setup MMU tables of a process for its read/write accessible areas.
 *
 * @param this_process process id for which the area is configured
 * @param from start address of the area
 * @param to address that immediatly follows the area
 * @param cacheable 1 if section is cacheable, otherwise 0
 *
 * @pre from is aligned to 1KByte
 * @pre to point just after the area
 * @pre since #MMU_init_tables call, this area has not been setup (conflicting
 * configurations not detected)
 * @pre this_process is a valid process identifier
 */
extern FUNC(void, OS_CODE) MMU_set_readwrite_area (tpl_task_id this_process, u8* from, u8 *to, CacheableMemoryArea cacheable);

/**
 * Enables the MMU
 */
FUNC(void, OS_CODE) MMU_enable (void);

/**
 * Disables the MMU
 */
FUNC(void, OS_CODE) MMU_disable (void);

/**
 * Switches the active process in the MMU configuration
 */
FUNC(void, OS_CODE) MMU_set_current_process (tpl_task_id this_process);

#endif /* ARM926_MMU_H */
