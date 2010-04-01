#ifndef TPL_MACHINE_ARMADEUS_MEM_PROT_H_
#define TPL_MACHINE_ARMADEUS_MEM_PROT_H_

#include "tpl_os_definitions.h"
#include "tpl_os_mem_prot.h"

/* Size of the page used in this memory protection */
#define PAGE_SIZE                0x1000      /* 4KB */
#define PAGE_BASE_PHY_ADDR       0xFFFFF000


/* TRANSLATION TABLE */
#define TRANS_TBL_SIZE        0x4000    /* Size of a translation table */
#define TRANS_TBL_INDEX_MASK    0xFFF00000  /* Mask used on virtual address 
                         * to define the translation 
                         * table index */
#define TRANS_TBL_PTB_MASK      0xFFFFFC00  /* Mask used on translation table
                         * entry to get the page table
                         * address carried */
#define TRANS_TBL_COARSE_DESC_TYPE  0x11    /* Used for set the type of the 
                         * translation table descriptor as
                         * coarse page table*/
#define ONE_MB            0x100000  /* 1 Mb in hexa */


/* PAGE TABLE */
#define PAGE_TBL_SIZE        0x400    /* Size of a page table 4Kb*/
#define PAGE_TBL_INDEX_MASK      0x000FF000  /* Mask used on virtual address 
                         * to define the page table index */ 
#define PAGE_TBL_SMALL_DESC_TYPE  0x2      /* Used for set the type of the 
                         * page table descriptor as
                         * small page */
/* Access permissions */
#define READ_WRITE          0xFF    /* Read and Write for the page */    
#define READ_ONLY          0xAA    /* Read only for the page */
#define NO_ACCESS           0x55    /* No access for the page */

/* TODO find one more elegant way for count
 * the number of common region */
#define LAST_COMMON_MEM_RGN_TYPE 5        /* Value of the last type of common
                         * memory region */ 
#define EXEC_STACKS_RGN LAST_COMMON_MEM_RGN_TYPE/* Value of the execution mode stacks
                         * memory region */
#define COUNT_EXEC_STACKS_MODE 6         /* Number of execution mode stacks
                         * As user and system share the same stack */

/* Enumerate all types of memory regions and attribute one value
 * is used for find what descriptors must be used in mmu tables */
typedef enum {
  CODE_RGN        = 0,
  CONST_RGN        = 1,
  OSVAR_RGN        = 2,
  VECTOR_TABLE_1_RGN    = 3,
  VECTOR_TABLE_2_RGN    = 4,
  IRQ_STACK_RGN      = EXEC_STACKS_RGN,
  FIQ_STACK_RGN      = EXEC_STACKS_RGN,
  SVC_STACK_RGN      = EXEC_STACKS_RGN,
  ABT_STACK_RGN      = EXEC_STACKS_RGN,
  UND_STACK_RGN      = EXEC_STACKS_RGN,
  USR_STACK_RGN      = EXEC_STACKS_RGN,
  /* regions specific at each process */  
  PRIVATE_VAR_RGN     = LAST_COMMON_MEM_RGN_TYPE + 1,
  PRIVATE_STACK_RGN     = LAST_COMMON_MEM_RGN_TYPE + 2,
  OWN_OSAP_VAR_RGN    = LAST_COMMON_MEM_RGN_TYPE + 3,
  DEVICE_RGN        = LAST_COMMON_MEM_RGN_TYPE + 4
}rgn_type;

/* Structure with two pointers
 * First to the base address of a translation table
 * Second to the base address of a page table */ 
struct MMU_TABLES {
  P2VAR(u32, OS_VAR, OS_VAR) ttb; /* Translation Table Base address */
  P2VAR(u32, OS_VAR, OS_VAR) ptb;  /* Page Table Base address */
};

typedef struct MMU_TABLES mmu_tables;

/* Structure with two variables represent mmu table entry
 * (translation descriptors level 1 and level 2)*/  
struct MP_TBL_DESCRIPTOR{
  VAR(u32, OS_VAR) tt_lvl_1;  /* Translation table entry */
  VAR(u32, OS_VAR) pt_lvl_2;  /* Page table entry */
};

typedef struct MP_TBL_DESCRIPTOR mmu_tbl_desc_pattern;


/* These external variables represent symbols defined in ldscript file.
 * They are used to know where each section has been located.
 */
 
/* These external variables describe common sections
 * Access rights of each common section must be present in each translation
 * table of each memory protection context*/ 
extern void *__SEG_START_CODE_RGN;
extern void *__SEG_END_CODE_RGN;
extern void *__SEG_START_CONST_RGN;
extern void *__SEG_END_CONST_RGN;
extern void *__SEG_START_OS_VAR_RGN;
extern void *__SEG_END_OS_VAR_RGN;
extern void *__SEG_START_VECTOR_TABLE_LVL_1;
extern void *__SEG_END_VECTOR_TABLE_LVL_1;
extern void *__SEG_START_VECTOR_TABLE_LVL_2;
extern void *__SEG_END_VECTOR_TABLE_LVL_2;
extern void *__SEG_START_IRQ_STACK_RGN;
extern void *__SEG_END_IRQ_STACK_RGN;
extern void *__SEG_START_FIQ_STACK_RGN;
extern void *__SEG_END_FIQ_STACK_RGN;
extern void *__SEG_START_SVC_STACK_RGN;
extern void *__SEG_END_SVC_STACK_RGN;
extern void *__SEG_START_ABT_STACK_RGN;
extern void *__SEG_END_ABT_STACK_RGN;
extern void *__SEG_START_UND_STACK_RGN;
extern void *__SEG_END_UND_STACK_RGN;
extern void *__SEG_START_USR_STACK_RGN;
extern void *__SEG_END_USR_STACK_RGN;

/* These external variables describe section of structurs used by the MMU */
extern void *__SEG_START_MMU_TT_RGN;
extern void *__SEG_START_MMU_PT_RGN;


/* FIXME: should be declared somewhere else */
extern CONSTP2CONST(tpl_mem_prot_desc, AUTOMATIC, OS_CONST) tpl_mp_table[TASK_COUNT+ISR_COUNT+1];

extern FUNC(void, OS_CODE) tpl_init_mp();


#endif /*TPL_MACHINE_ARMADEUS_MEM_PROT_H_*/
