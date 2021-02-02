/*******************************************************************************
 * (c) Copyright 2011-2015 Microsemi SoC Products Group.  All rights reserved.
 *
 * This source file contains SmartFusion2 eNVM driver code.
 *
 * SVN $Revision: 7844 $
 * SVN $Date: 2015-09-22 11:09:31 +0530 (Tue, 22 Sep 2015) $
 */

#include "../../CMSIS/m2sxxx.h"
#include "../../CMSIS/mss_assert.h"
#include "../../CMSIS/system_m2sxxx.h"
#include "mss_nvm.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************/
/* Preprocessor definitions                                               */
/**************************************************************************/
/*     eNVM command codes       */
#define PROG_ADS                        0x08000000u  /* One shot program with data in WD */
#define VERIFY_ADS                      0x10000000u  /* One shot verification with data in WD */
#define USER_UNLOCK                     0x13000000u  /* User unlock */

#define BITS_PER_PAGE                   1024u                   /* Number of bits per page */
#define BYTES_PER_PAGE                  (BITS_PER_PAGE / 8u)    /* Number of bytes per page */

#define NVM_OFFSET_SIGNIFICANT_BITS     0x0007FFFFu
#define NVM1_BOTTOM_OFFSET              0x00040000u
#define NVM1_TOP_OFFSET                 0x0007FFFFu

#define PARAM_LOCK_PAGE_FLAG            0x00000002u
#define ACCESS_DENIED_FLAG_CLEAR        0x00000002u

#define PAGES_PER_BLOCK                 2048u

#define NVM_BOTTOM_OFFSET               0x00000000u
#define NVM_TOP_OFFSET                  0x0007FFFFu
#define NVM_RSV_PROTECTION_OFFSET       0x0007E000u

#define NVM_BASE_ADDRESS                0x60000000u
  
#define PAGE_ADDR_MASK                  0xFFFFFF80u

#define BLOCK1_FIRST_WORD_OFFSET        0x00010000u

#define WD_WORD_SIZE                    32u

#define NB_OF_BYTES_IN_A_WORD           4u

#define MAX_512K_OFFSET                 0x00080000u

#define WRITE_ERROR_MASK                (MSS_NVM_VERIFY_FAIL | \
                                            MSS_NVM_EVERIFY_FAIL | \
                                            MSS_NVM_WVERIFY_FAIL | \
                                            MSS_NVM_PEFAIL_LOCK | \
                                            MSS_NVM_WR_DENIED)
                                        
#define NVM_FREQRNG_MASK                0xFFFFE01Fu
#define NVM_FREQRNG_MAX                 ((uint32_t)0xFF << 5u)     /* FREQRNG is set to 15. */

/*******************************************************************************
 * Combined status definitions
 * Below definitions should be used to decoded the bit encoded status returned 
 * by the function MSS_NVM_get_status().
 */
#define MSS_NVM_BUSY_B                  (1u)                    /* NVM is performing an internal operation */
#define MSS_NVM_VERIFY_FAIL             ((uint32_t)1 << 1u)     /* NVM verify operation failed */
#define MSS_NVM_EVERIFY_FAIL            ((uint32_t)1 << 2u)     /* NVM erase verify operation failed */
#define MSS_NVM_WVERIFY_FAIL            ((uint32_t)1 << 3u)     /* NVM write verify operation failed */
#define MSS_NVM_PEFAIL_LOCK             ((uint32_t)1 << 4u)     /* NVM program / erase operation failed due to page lock */
#define MSS_NVM_WRCNT_OVER              ((uint32_t)1 << 5u)     /* NVM write count overflowed */
#define MSS_NVM_WR_DENIED               ((uint32_t)1 << 18u)    /* NVM write is denied due to protection */

/*******************************************************************************
 * eNVM Block Index values
 */
#define NVM_BLOCK_0                     0u
#define NVM_BLOCK_1                     1u

/**************************************************************************/
/* Global data definitions                                                */
/**************************************************************************/
/**************************************************************************//**
 * Look-up table for NVM blocks.
 */
static NVM_TypeDef * const g_nvm[] = 
{
    ENVM_1,
    ENVM_2
};

static NVM32_TypeDef * const g_nvm32[] =
{
    (NVM32_TypeDef *)ENVM1_BASE,
    (NVM32_TypeDef *)ENVM2_BASE
};

/**************************************************************************/
/* Private function declarations                                          */
/**************************************************************************/
static nvm_status_t request_nvm_access(uint32_t nvm_block_id);
static nvm_status_t get_ctrl_access(uint32_t nvm_offset, uint32_t length);
static void release_ctrl_access(void);
static uint32_t get_remaining_page_length(uint32_t offset, uint32_t length);
static uint32_t wait_nvm_ready(uint32_t block);
static nvm_status_t get_error_code(uint32_t nvm_hw_status);
static nvm_status_t check_protection_reserved_nvm(uint32_t offset, uint32_t length);
static uint32_t protection_check(uint32_t protect_user, uint32_t length);

static void fill_wd_buffer
(
    const uint8_t * p_data,
    uint32_t  length,
    uint32_t block,
    uint32_t offset
);

static uint32_t 
write_nvm
(
    uint32_t addr,
    const uint8_t * pidata,
    uint32_t length,
    uint32_t lock_page,
    uint32_t * p_status
);

/**************************************************************************/
/* Public function definitions                                            */
/**************************************************************************/

/**************************************************************************//**
 * See mss_nvm.h for details of how to use this function.
 */
nvm_status_t
NVM_write
(
    uint32_t start_addr,
    const uint8_t * pidata,
    uint32_t length,
    uint32_t lock_page
)
{
    nvm_status_t status;
    uint32_t nvm_offset;
    uint32_t device_version;
    uint32_t initial_nvm_config;


    /* 
     * SAR 57547: Set the FREQRNG field of the eNVM configuration register 
     * to its maximum value (i.e. 15) to ensure successful writes to eNVM. 
     * Store the value of the eNVM configuration before updating it, so 
     * that the prior configuration can be restored when the eNVM write
     * operation has completed. 
     */
    initial_nvm_config = SYSREG->ENVM_CR;
    SYSREG->ENVM_CR = (initial_nvm_config & NVM_FREQRNG_MASK) | NVM_FREQRNG_MAX;

    /* Check input parameters */
    if((start_addr >= (NVM_BASE_ADDRESS + NVM_TOP_OFFSET)) || \
        ((start_addr >= NVM_TOP_OFFSET) && \
        (start_addr < NVM_BASE_ADDRESS)) || \
        (!pidata) || \
        (!length) || \
        (lock_page > PARAM_LOCK_PAGE_FLAG))
    {
        status =  NVM_INVALID_PARAMETER;
    }
    else
    {
        /*
         * Prevent pages being locked for silicon versions which do not allow
         * locked pages to be unlocked.
         */
        device_version = SYSREG->DEVICE_VERSION;
        if((0x0000F802u == device_version) || (0x0001F802u == device_version))
        {
            lock_page = NVM_DO_NOT_LOCK_PAGE;
        }

        /* Ignore upper address bits to ignore remapping setting. */
        nvm_offset = start_addr & NVM_OFFSET_SIGNIFICANT_BITS;  /* Ignore remapping. */

        status = check_protection_reserved_nvm(nvm_offset, length);

        /* Check  */
        if(NVM_SUCCESS == status)
        {
            /* Gain exclusive access to eNVM controller */
            status = get_ctrl_access(nvm_offset, length);

            /* Write eNVM one page at a time. */
            if(NVM_SUCCESS == status)
            {
                uint32_t remaining_length = length;
                uint32_t errors_and_warnings;
                
                while(remaining_length > 0u)
                {
                    uint32_t length_written;
                    uint32_t nvm_hw_status = 0u;

                    length_written = write_nvm(start_addr + (length - remaining_length),
                                                &pidata[length - remaining_length],
                                                remaining_length,
                                                lock_page,
                                                &nvm_hw_status);

                    /* Check for errors and warnings. */
                    errors_and_warnings = nvm_hw_status & (WRITE_ERROR_MASK | MSS_NVM_WRCNT_OVER);
                    if(errors_and_warnings)
                    {
                       /* 
                        * Ensure that the status returned by the NVM_write()
                        * function is NVM_WRITE_THRESHOLD_WARNING if at least one
                        * of the written eNVM pages indicate a write over
                        * threshold condition.
                        */ 
                        status = get_error_code(nvm_hw_status);
                    }

                    if((NVM_SUCCESS == status) || (NVM_WRITE_THRESHOLD_WARNING == status ))
                    {
                        if(remaining_length > length_written)
                        {
                            remaining_length -= length_written;
                        }
                        else
                        {
                            remaining_length = 0u;
                        }
                    }
                    else
                    {
                        remaining_length = 0u;
                    }
                }

                /* Release eNVM controllers so that other masters can gain access to it. */
                release_ctrl_access();
            }
        }
    }
    
    /* Restore back to original value. */
    SYSREG->ENVM_CR = initial_nvm_config;
    
    return status;
}

/**************************************************************************//**
  Generate error code based on NVM status value.
  
  The hardware nvm status passed as parameter is expected to be masked using the
  following mask:
                (MSS_NVM_VERIFY_FAIL | \
                 MSS_NVM_EVERIFY_FAIL | \
                 MSS_NVM_WVERIFY_FAIL | \
                 MSS_NVM_PEFAIL_LOCK | \
                 MSS_NVM_WRCNT_OVER | \
                 MSS_NVM_WR_DENIED)
  
 */
static nvm_status_t get_error_code(uint32_t nvm_hw_status)
{
    nvm_status_t status;
    
    if(nvm_hw_status & MSS_NVM_WR_DENIED)
    {
        status = NVM_PROTECTION_ERROR;
    }
    else if(nvm_hw_status & MSS_NVM_PEFAIL_LOCK)
    {
        status = NVM_PAGE_LOCK_ERROR;
    }
    else if(nvm_hw_status & (MSS_NVM_VERIFY_FAIL |
            MSS_NVM_EVERIFY_FAIL | MSS_NVM_WVERIFY_FAIL))
    {
        status = NVM_VERIFY_FAILURE;
    }
    else if(nvm_hw_status & MSS_NVM_WRCNT_OVER)
    {
        status = NVM_WRITE_THRESHOLD_WARNING;
    }
    else
    {
        status = NVM_SUCCESS;
    }
    
    return status;
}

/**************************************************************************//**
 * See mss_nvm.h for details of how to use this function.
 */
nvm_status_t
NVM_unlock
(
    uint32_t start_addr,
    uint32_t length
)
{
    nvm_status_t status;
    uint32_t nvm_offset;
    uint32_t first_page;
    uint32_t last_page;
    uint32_t current_page;
    uint32_t current_offset;
    uint32_t initial_nvm_config;

    /* 
     * SAR 57547: Set the FREQRNG field of the eNVM configuration register 
     * to its maximum value (i.e. 15) to ensure successful writes to eNVM. 
     * Store the value of the eNVM configuration before updating it, so 
     * that the prior configuration can be restored when the eNVM write
     * operation has completed. 
     */
    initial_nvm_config = SYSREG->ENVM_CR;
    SYSREG->ENVM_CR = (initial_nvm_config & NVM_FREQRNG_MASK) | NVM_FREQRNG_MAX;
    
    /* Check input parameters */
    if((start_addr >= (NVM_BASE_ADDRESS + NVM_TOP_OFFSET)) || \
        ((start_addr >= NVM_TOP_OFFSET) && \
        (start_addr < NVM_BASE_ADDRESS)) || \
        (!length))
    {
        status =  NVM_INVALID_PARAMETER;
    }
    else
    {
        /* Ignore upper address bits to ignore remapping setting. */
        nvm_offset = start_addr & NVM_OFFSET_SIGNIFICANT_BITS;  /* Ignore remapping. */

        status = check_protection_reserved_nvm(nvm_offset, length);

        /* Check  */
        if(NVM_SUCCESS == status)
        {

            first_page = nvm_offset / BYTES_PER_PAGE;
            last_page = (nvm_offset + (length - 1u)) / BYTES_PER_PAGE;

            /* Gain exclusive access to eNVM controller */
            status = get_ctrl_access(nvm_offset, length);

            /* Unlock eNVM one page at a time. */
            if(NVM_SUCCESS == status)
            {
                uint32_t block;
                uint32_t inc;
                uint32_t * p_nvm32;
                uint32_t errors_and_warnings;


                for(current_page = first_page; (current_page <= last_page) &&
                    ((NVM_SUCCESS == status) ||(NVM_WRITE_THRESHOLD_WARNING == status));
                    ++current_page)
                {
                    uint32_t ctrl_status;

                    if(current_page > PAGES_PER_BLOCK)
                    {
                        block = NVM_BLOCK_1;
                    }
                    else
                    {
                        block = NVM_BLOCK_0;
                    }

                    if(g_nvm[block]->STATUS & MSS_NVM_WR_DENIED)
                    {
                        /* Clear the access denied flag */
                        g_nvm[block]->CLRHINT |= ACCESS_DENIED_FLAG_CLEAR;
                    }

                    current_offset = (current_page << 0x7u);
                    p_nvm32 = (uint32_t *)(NVM_BASE_ADDRESS + current_offset);
                     
                    for(inc = 0u; inc < WD_WORD_SIZE; ++inc)
                    {
                        g_nvm32[block]->WD[inc] = p_nvm32[inc];
                    }
                    
                    g_nvm[block]->PAGE_LOCK = NVM_DO_NOT_LOCK_PAGE;
                    g_nvm[block]->CMD = USER_UNLOCK | (current_offset & PAGE_ADDR_MASK);

                    /* Issue program command */
                    g_nvm[block]->CMD = PROG_ADS | (current_offset & PAGE_ADDR_MASK);

                    /* Wait for NVM to become ready. */
                    ctrl_status = wait_nvm_ready(block);

                    /* Check for errors and warnings. */
                    errors_and_warnings = ctrl_status & (WRITE_ERROR_MASK | MSS_NVM_WRCNT_OVER);
                    if(errors_and_warnings)
                    {
                        uint32_t nvm_hw_status;
                        nvm_hw_status = g_nvm[block]->STATUS;
                        status = get_error_code(nvm_hw_status);
                    }
                }

                /* Release eNVM controllers so that other masters can gain access to it. */
                release_ctrl_access();
            }
        }
    }
    
    /* Restore back to original value. */
    SYSREG->ENVM_CR = initial_nvm_config;
    
    return status;
}

/**************************************************************************/
/* Private function definitions                                            */
/**************************************************************************/

/**************************************************************************//**
 *  Gain access to eNVM controller
 */
#define ACCESS_REQUEST_TIMEOUT      0x00800000u
#define REQUEST_NVM_ACCESS          0x01u
#define CORTEX_M3_ACCESS_GRANTED    0x05u

static uint8_t g_envm_ctrl_locks = 0x00u;

static nvm_status_t request_nvm_access(uint32_t nvm_block_id)
{
    nvm_status_t status = NVM_SUCCESS;
    volatile uint32_t timeout_counter;
    uint32_t access;
    
    /*
     * Use the SystemCoreClock frequency to compute a delay counter value giving
     * us a delay in the 500ms range. This is a very approximate delay.
     */
    timeout_counter = SystemCoreClock / 16u;
    
    /*
     * Gain access to eNVM controller.
     */
    do {
        g_nvm[nvm_block_id]->REQ_ACCESS = REQUEST_NVM_ACCESS;
        access = g_nvm[nvm_block_id]->REQ_ACCESS;
        if(access != CORTEX_M3_ACCESS_GRANTED)
        {
            /*
             * Time out if another AHB master locked access to eNVM to prevent
             * the Cortex-M3 from locking up on eNVM write if some other part
             * of the system fails from releasing the eNVM.
             */
            --timeout_counter;
            if(0u == timeout_counter)
            {
                status = NVM_IN_USE_BY_OTHER_MASTER;
            }
        }
    } while((access != CORTEX_M3_ACCESS_GRANTED) && (NVM_SUCCESS == status));
    
    /*
     * Mark controller as locked if successful so that it will be unlocked by a
     * call to release_ctrl_access.
     */
    if(NVM_SUCCESS == status)
    {
        g_envm_ctrl_locks |= (uint8_t)((uint32_t)0x01 << nvm_block_id);
    }
    
    return status;
}

/**************************************************************************//**
 * Get access to eNVM controller for eNVM0 and eNVM1
 */
static nvm_status_t get_ctrl_access(uint32_t nvm_offset, uint32_t length)
{
    nvm_status_t access_req_status;
    
    /*
     * Gain access to eNVM controller(s).
     */
    if(nvm_offset < NVM1_BOTTOM_OFFSET)
    {
        access_req_status = request_nvm_access(NVM_BLOCK_0);
        if(NVM_SUCCESS == access_req_status)
        {
            uint32_t last_offset;
            last_offset = nvm_offset + (length - 0x1u);
            if(last_offset >= NVM1_BOTTOM_OFFSET)
            {
                access_req_status = request_nvm_access(NVM_BLOCK_1);
                if(NVM_IN_USE_BY_OTHER_MASTER == access_req_status)
                {
                    release_ctrl_access();
                }
            }
        }
    }
    else
    {
        access_req_status = request_nvm_access(NVM_BLOCK_1);
    }
    
    return access_req_status;
}

/**************************************************************************//**
 * Release access to eNVM controllers.
 */
#define NVM_BLOCK_0_LOCK_MASK   0x01u
#define NVM_BLOCK_1_LOCK_MASK   0x02u

static void release_ctrl_access(void)
{
    uint8_t block_locked;
    
    block_locked = g_envm_ctrl_locks & NVM_BLOCK_0_LOCK_MASK;
    if(block_locked)
    {
        g_nvm[NVM_BLOCK_0]->REQ_ACCESS = 0x00u;
        g_envm_ctrl_locks &= ~NVM_BLOCK_0_LOCK_MASK;
    }
    
    block_locked = g_envm_ctrl_locks & NVM_BLOCK_1_LOCK_MASK;
    if(block_locked)
    {
        g_nvm[NVM_BLOCK_1]->REQ_ACCESS = 0x00u;
        g_envm_ctrl_locks &= ~NVM_BLOCK_1_LOCK_MASK;
    }
}

/**************************************************************************//**
 * Wait for NVM to become ready from busy state
 */
static uint32_t wait_nvm_ready(uint32_t block) 
{
    volatile uint32_t ctrl_status;
    uint32_t ctrl_ready;
    uint32_t inc;
    
    /*
     * Wait for NVM to become ready.
     * We must ensure that we can read the ready bit set to 1 twice before we
     * can assume that the other status bits are valid. See SmartFusion2 errata.
     */
    for(inc = 0u; inc < 2u; ++inc)
    {
        do {
            ctrl_status = g_nvm[block]->STATUS;
            ctrl_ready = ctrl_status  & MSS_NVM_BUSY_B;
        } while(0u == ctrl_ready);
    }
    
    return ctrl_status;
}

/**************************************************************************//**
  Write as much data as will fit into the eNVM page corresponding to the
  address "addr" passed as parameter. Return the number of bytes written into
  the page.
  In case of error, return the content of the eNVM controller status register
  into the 32-bit word pointed to by p_status.
 */
static uint32_t 
write_nvm
(
    uint32_t addr,
    const uint8_t * pidata,
    uint32_t  length,
    uint32_t  lock_page,
    uint32_t * p_status
)
{
    uint32_t length_written;
    uint32_t offset;
   
    *p_status = 0u;
    
    offset = addr & NVM_OFFSET_SIGNIFICANT_BITS;  /* Ignore remapping. */
    
    ASSERT(offset <= NVM1_TOP_OFFSET);
    
    /* Adjust length to fit within one page. */
    length_written = get_remaining_page_length(offset, length);
    
    if(offset <= NVM1_TOP_OFFSET)
    {
        uint32_t block;
        volatile uint32_t ctrl_status;
        uint32_t errors;
        
        if(offset < NVM1_BOTTOM_OFFSET)
        {
            block = NVM_BLOCK_0;
        }
        else
        {
            block = NVM_BLOCK_1;
            offset = offset - NVM1_BOTTOM_OFFSET;
        }
        
        if(g_nvm[block]->STATUS & MSS_NVM_WR_DENIED)
        {
            /* Clear the access denied flag */
            g_nvm[block]->CLRHINT |= ACCESS_DENIED_FLAG_CLEAR;
        }

        fill_wd_buffer(pidata, length_written, block, offset);

        /* Set requested locking option. */
        g_nvm[block]->PAGE_LOCK = lock_page;
        
        /* Issue program command */
        g_nvm[block]->CMD = PROG_ADS | (offset & PAGE_ADDR_MASK);
        
        /* Wait for NVM to become ready. */
        ctrl_status = wait_nvm_ready(block);

        /* Check for errors. */
        errors = ctrl_status & WRITE_ERROR_MASK;
        if(errors)
        {
            *p_status = g_nvm[block]->STATUS;
        }
        else
        {
            /* Perform a verify. */
            g_nvm[block]->CMD = VERIFY_ADS | (offset & PAGE_ADDR_MASK);
            /* Wait for NVM to become ready. */
            ctrl_status = wait_nvm_ready(block);

            *p_status = g_nvm[block]->STATUS;
        }
    }
    
    return length_written;
}

/*******************************************************************************
  Return the number of bytes between the offset location and the end of the page
  containing the first offset location. This tells us how many actual bytes can
  be programmed with a single ProgramADS command.
  This also tells us if we are programming a full page. If the return value is
  equal to BYTES_PER_PAGE then we will be programming an entire NVM page.
  Alternatively, this function returning a value other than BYTES_PER_PAGE
  indicates that the WD[] buffer will have to be seeded with the existing
  content of the eNVM before copying the data to program to eNVM into the WD[]
  buffer.
 */
static uint32_t get_remaining_page_length(uint32_t offset, uint32_t length)
{
    uint32_t start_page_plus_one;
    uint32_t last_page;
    
    start_page_plus_one = (offset / BYTES_PER_PAGE) + 1u;
    last_page = (offset + length) / BYTES_PER_PAGE;
    if(last_page >= start_page_plus_one)
    {
        length = BYTES_PER_PAGE - (offset % BYTES_PER_PAGE);
    }
    
    return length;
}

/**************************************************************************//**
 * Fill the eNVM controller write data(WD) buffer with data
 */
static void fill_wd_buffer
(
    const uint8_t * p_data,
    uint32_t  length,
    uint32_t block,
    uint32_t offset
)
{
    uint32_t inc;
    uint32_t wd_offset;
    
    if(length != BYTES_PER_PAGE)
    {
        uint32_t * p_nvm32;
        uint32_t nb_non_written_words;
        uint32_t first_non_written_word;
        /* 
         * Fill beginning of WD[] with current content of NVM page that must not
         * be overwritten.
         */
        p_nvm32 = (uint32_t *)((NVM_BASE_ADDRESS + offset + (block * NVM1_BOTTOM_OFFSET)) & PAGE_ADDR_MASK);
        nb_non_written_words = (offset % BYTES_PER_PAGE) / NB_OF_BYTES_IN_A_WORD;
        if((offset % NB_OF_BYTES_IN_A_WORD) > 0u)
        {
            ++nb_non_written_words;
        }
        for(inc = 0u; (inc < WD_WORD_SIZE) && (inc < nb_non_written_words); ++inc)
        {
            g_nvm32[block]->WD[inc] = p_nvm32[inc];
        }
        
        /*
         * Fill end of WD[] with current content of NVM page that must not be
         * overwritten.
         */
        first_non_written_word = ((offset + length) % BYTES_PER_PAGE) / NB_OF_BYTES_IN_A_WORD;
        nb_non_written_words = (BYTES_PER_PAGE / NB_OF_BYTES_IN_A_WORD) - first_non_written_word;
        
        for(inc = 0u; inc < nb_non_written_words; ++inc)
        {
            g_nvm32[block]->WD[first_non_written_word + inc] = p_nvm32[first_non_written_word + inc];
        }
    }
    
    /*
     * Fill WD[] with data requested to be written into NVM.
     */
    wd_offset = offset % BYTES_PER_PAGE;
    for(inc = 0u; inc < length; ++inc)
    {
        g_nvm[block]->WD[wd_offset + inc] = p_data[inc];
    }
}
/**************************************************************************//**
 * See mss_nvm.h for details of how to use this function.
 */
#define NVM0_BASE_ADDRESS                0x60000000u
#define NVM1_BASE_ADDRESS                0x60040000u

#define AUX_DATA_WC_MASK    0x00FFFFF0
#define AUX_DATA_WC_SHIFT   4

uint32_t
NVM_read_page_write_count
(
    uint32_t addr
)
{
    uint32_t write_count = 0u;
    uint32_t block;
    uint32_t offset;
    uint32_t status;

    if((addr >= (NVM_BASE_ADDRESS + NVM_TOP_OFFSET)) || \
       ((addr >= NVM_TOP_OFFSET) && (addr < NVM_BASE_ADDRESS)))
    {
        write_count = 0u;
    }
    else
    {
        write_count = 0u;
        offset = addr & NVM_OFFSET_SIGNIFICANT_BITS;

        status = check_protection_reserved_nvm(offset, 0u);
        
        if(NVM_SUCCESS == status)
        {  
            /* Gain exclusive access to eNVM controller */
            status = get_ctrl_access(offset, 1u);
        
            /* Read page write counter. */
            if(NVM_SUCCESS == status)
            {
                if(offset < NVM1_BOTTOM_OFFSET)
                {
                    block = NVM_BLOCK_0;
                }
                else
                {
                    block = NVM_BLOCK_1;
                    offset = offset - NVM1_BOTTOM_OFFSET;
                }
        
                g_nvm[block]->NV_PAGE_STATUS |= 0x2u;
        
                if(block == NVM_BLOCK_0)
                {
                    write_count = *((uint32_t *)((NVM0_BASE_ADDRESS + offset) & PAGE_ADDR_MASK));
                }
                else
                {
                    write_count = *((uint32_t *)((NVM1_BASE_ADDRESS + offset) & PAGE_ADDR_MASK));
                }
        
                /* Wait for NVM to become ready. */
                status = wait_nvm_ready(block);
        
                g_nvm[block]->NV_PAGE_STATUS &= ~(0x2u);
            }
        
            /* Release eNVM controllers so that other masters can gain access to it. */
            release_ctrl_access();
        
            /* The write count is contained in bits [24:4] of the page's auxiliary data. */
            write_count = (write_count & AUX_DATA_WC_MASK) >> AUX_DATA_WC_SHIFT;
        }
    }
    return write_count;
}
/**************************************************************************//**
 *
 */
//eNVM0
#define LOWER0_PROTECT_BOTTOM_OFFSET        0x00000000u
#define LOWER0_PROTECT_TOP_OFFSET           0x00000FFFu

#define UPPER0_PROTECT_BOTTOM_OFFSET        0x0003F000u
#define UPPER0_PROTECT_TOP_OFFSET           0x0003FFFFu

//060
#define NVM0_UPPER1_PROTECT_BOTTOM_OFFSET   0x0003D000u
#define NVM0_UPPER1_PROTECT_TOP_OFFSET      0x0003DFFFu

#define NVM0_RSV_OFFSET                     0x0003F800u

#define OO5_UPPER0_PROTECT_BOTTOM_OFFSET    0x0001F000u
#define OO5_UPPER0_PROTECT_TOP_OFFSET       0x0001FFFFu

#define OO5_NVM_RSV_OFFSET                  0x0001F800u

#define O60_NVM_RSV_OFFSET                  0x0003E000u

//eNVM1
//090/150
#define NVM0_UPPER0_PROTECT_BOTTOM_OFFSET   0x0007D000u
#define NVM0_UPPER0_PROTECT_TOP_OFFSET      0x0007DFFFu

#define LOWER1_PROTECT_BOTTOM_OFFSET        0x0007C000u
#define LOWER1_PROTECT_TOP_OFFSET           0x0007CFFFu

#define UPPER1_PROTECT_BOTTOM_OFFSET        0x0007B000u
#define UPPER1_PROTECT_TOP_OFFSET           0x0007BFFFu

#define NVM1_RSV_OFFSET                     0x0007E000u

#define PROTECT_USER_MASK                   0xFFFFu
#define READ_ONLY                           0x1u
#define WRITE_ONLY                          0x8u
#define NO_READ_WRITE                       0x0u
#define READ_WRITE_MASK                     0x9u

#define PROTECTION_ON                       0x1u
#define PROTECTION_OFF                      0x0u
/**************************************************************************//**
 * checking protection region and reserved page address of eNVM
 *
 * 005 device
 *  The 005 device have 128KB of eNVM memory(0x00000 - 0x1FFFF)
 *  0x1F800 - 0x1FFFF - 2KB(16 pages) reserved eNVM memory   
 *  0x00000 - 0x00FFF - 4KB(32 pages) user lower(bottom) protected area of eNVM0 memory.
 *  0x1F000 - 0x1FFFF - 4KB(32 pages) user upper(top) protected area of eNVM0 memory
 *
 * 010/025/050 device
 *  The 010/025/050 device have 256KB of eNVM memory(0x00000 - 0x3FFFF)
 *  0x3F800 - 0x3FFFF - 2KB(16 pages) reserved eNVM memory   
 *  0x00000 - 0x00FFF - 4KB(32 pages) user lower(bottom) protected area of eNVM0 memory.
 *  0x3F000 - 0x3FFFF - 4KB(32 pages) user upper(top) protected area of eNVM0 memory
 *
 * 060 device
 *  The 060 device have 256KB of eNVM memory(0x00000 - 0x3FFFF)
 *  0x3E000 - 0x3FFFF - 8KB(64 pages) reserved eNVM memory   
 *  0x00000 - 0x00FFF - 4KB(32 pages) user lower0(bottom) protected area of eNVM0 memory.
 *  0x3F000 - 0x3FFFF - 4KB(32 pages) user upper0(top) protected area of eNVM0 memory    
 *  0x3E000 - 0x3EFFF - 4KB(32 pages) user lower1(bottom) protected area of eNVM0 memory.
 *  0x3D000 - 0x3DFFF - 4KB(32 pages) user upper1(top) protected area of eNVM0 memory.
 *
 * 090/150 device
 *  The 090/150 device have 512KB of eNVM memory(0x00000 - 0x7FFFF)
 *  0x7E000 - 0x7FFFF - 2KB(64 pages) reserved eNVM memory   
 *  0x00000 - 0x00FFF - 4KB(32 pages) user lower0(bottom) protected area of eNVM0 memory.
 *  0x7D000 - 0x7DFFF - 4KB(32 pages) user upper0(top) protected area of eNVM1 memory    
 *  0x7C000 - 0x7CFFF - 4KB(32 pages) user lower1(bottom) protected area of eNVM1 memory.
 *  0x7B000 - 0x7BFFF - 4KB(32 pages) user upper1(top) protected area of eNVM1 memory.          
 *
 */
static nvm_status_t check_protection_reserved_nvm(uint32_t offset, uint32_t length)
{
    uint32_t device_version;
    uint32_t protection_data;
    uint32_t protection_flag = 0u;
    uint32_t protection_user0;
    uint32_t protection_user1;
    uint32_t protection_user2;
    uint32_t protection_user3;
    uint32_t length_minus_one = 0u;
    nvm_status_t status = NVM_SUCCESS;
    
    if(0u != length)
    {
        length_minus_one = length - 1u;
    }

    device_version = (SYSREG->DEVICE_VERSION & 0xFFFFu);
    
    /* 005 device */
    if((0xF805u == device_version))
    {
        protection_flag = PROTECTION_OFF;
        /* Read eNVM user protect register for lower and upper area protection data */
        protection_data = (SYSREG->ENVM_PROTECT_USER & PROTECT_USER_MASK);
        /* Check whether the eNVM0 lower or upper area is protected or not */
        if(PROTECT_USER_MASK != protection_data)
        {
            protection_user0 = (protection_data & 0x000Fu) & READ_WRITE_MASK;
            protection_user1 = ((protection_data & 0x00F0u) >> 4u) & READ_WRITE_MASK;
            /* Checking NVM0 lower protected area is Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user0) ||(WRITE_ONLY == protection_user0) || \
               (NO_READ_WRITE == protection_user0))
            {   
                /* Check offset is in the range of lower protect memory if it is
                 * then memory protected.
                 */
                if((offset > LOWER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= LOWER0_PROTECT_TOP_OFFSET))
                {
                    protection_flag = protection_check(protection_user0, length);
                }
            }
            /* Checking NVM0 upper protected area is Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user1) ||(WRITE_ONLY == protection_user1) || \
               (NO_READ_WRITE == protection_user1))
            {
                /* Check offset or (offset + length) is in the range of upper 
                 *  protect memory if it is then memory protected.
                 */
                if(((offset >= OO5_UPPER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= OO5_UPPER0_PROTECT_TOP_OFFSET)) || \
                    (((offset + length_minus_one) >= OO5_UPPER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset < OO5_UPPER0_PROTECT_BOTTOM_OFFSET)))
                {
                    protection_flag = protection_check(protection_user1, length);
                }
            }
        }
        /* Check memory is protected or not */
        if(PROTECTION_ON == protection_flag)
        {
            /* Status is protection error if lower or upper area of eNVM0 is protected */
            status = NVM_PROTECTION_ERROR;
        }
        else
        {
            /* Check (offset + length) is out of eNVM memory */
            if((offset + length_minus_one) > OO5_UPPER0_PROTECT_TOP_OFFSET)
            {
                status = NVM_INVALID_PARAMETER;
            }
            else
            {
                /* Check offset is in eNVM reserved memory - 16 pages reserved */
                if(((offset >= OO5_NVM_RSV_OFFSET) && (offset <= OO5_UPPER0_PROTECT_TOP_OFFSET)) || \
                    (((offset + length_minus_one) >= OO5_NVM_RSV_OFFSET) && \
                     (offset < OO5_NVM_RSV_OFFSET)))
                {
                    /* Status is protection error if offset or (offset + length) is 
                     * in reserved area of eNVM
                    */
                    status = NVM_PROTECTION_ERROR;
                }
                else
                {
                    /* Status is success if offset or (offset + length) is 
                     * in RW access of eNVM memory(not protected)
                     */
                    status = NVM_SUCCESS;
                }
            }
        }
    }
    /* 010/025/050 device */
    else if((0xF802u == device_version) || (0xF803u == device_version) || (0xF804u == device_version))
    {    
        protection_flag = PROTECTION_OFF;
        /* Read eNVM user protect register for lower and upper area protection data */
        protection_data = (SYSREG->ENVM_PROTECT_USER & PROTECT_USER_MASK);
        /* Check whether the eNVM0 lower or upper area is protected or not */        
        if(PROTECT_USER_MASK != protection_data)
        {
            protection_user0 = (protection_data & 0x000Fu) & READ_WRITE_MASK;
            protection_user1 = ((protection_data & 0x00F0u) >> 4u) & READ_WRITE_MASK;
            /* Check NVM0 lower protected area is Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user0) ||(WRITE_ONLY == protection_user0) || \
               (NO_READ_WRITE == protection_user0))
            {
                /* Check offset is in the range of lower protect memory if it is
                 * then memory protected.
                 */            
                if((offset > LOWER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= LOWER0_PROTECT_TOP_OFFSET))
                {
                    protection_flag = protection_check(protection_user0, length);
                }
            }
            /* Check NVM0 upper protected area is Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user1) ||(WRITE_ONLY == protection_user1) || \
               (NO_READ_WRITE == protection_user1))
            {
                /* Check offset or (offset + length) is in the range of upper 
                 * protect memory if it is then memory protected.
                 */
                if(((offset >= UPPER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= UPPER0_PROTECT_TOP_OFFSET)) || \
                    (((offset + length_minus_one) >= UPPER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset < UPPER0_PROTECT_BOTTOM_OFFSET)))
                {
                    protection_flag = protection_check(protection_user1, length);
                }
            }
        }
        /* Check lower or upper memory is protected or not */
        if(PROTECTION_ON == protection_flag)
        {
            /* Status is protection error if lower or upper area of eNVM0 is protected */        
            status = NVM_PROTECTION_ERROR;
        }
        else
        {
             /* Check (offset + length) is out of eNVM memory */
            if((offset + length_minus_one) > UPPER0_PROTECT_TOP_OFFSET)
            {
                status = NVM_INVALID_PARAMETER;
            }
            else
            {
                /* Check offset is in eNVM reserved memory - 16 pages reserved */
                if(((offset >= NVM0_RSV_OFFSET) && (offset <= UPPER0_PROTECT_TOP_OFFSET)) || \
                    (((offset + length_minus_one) >= NVM0_RSV_OFFSET) && (offset < NVM0_RSV_OFFSET)))
                {
                    /* Status is protection error if offset or (offset + length) is 
                     * in reserved area of eNVM
                    */
                    status = NVM_PROTECTION_ERROR;
                }
                else
                {
                    /* Status is success if offset or (offset + length) is 
                     * in RW access of eNVM memory(not protected)
                     */
                    status = NVM_SUCCESS;
                }
            }
        }
    }
    /* 060 device */
    else if(0xF808u == device_version)
    {
        protection_flag = PROTECTION_OFF;
        /* Read eNVM user protect register for lower and upper area protection data */
        protection_data = (SYSREG->ENVM_PROTECT_USER & PROTECT_USER_MASK);
        /* Check whether the eNVM0 lower0/1 or upper0/1 area is protected or not */
        if(PROTECT_USER_MASK != protection_data)
        {
            protection_user0 = (protection_data & 0x000Fu) & READ_WRITE_MASK;
            protection_user1 = ((protection_data & 0x00F0u) >> 4u) & READ_WRITE_MASK;
            protection_user2 = ((protection_data & 0x0F00u) >> 8u) & READ_WRITE_MASK;
            protection_user3 = ((protection_data & 0xF000u) >> 12u) & READ_WRITE_MASK;
            
            /* Check NVM0 lower0 protected area is Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user0) ||(WRITE_ONLY == protection_user0) || \
               (NO_READ_WRITE == protection_user0))
            {
                /* Check offset is in the range of lower0 protect memory if it is
                 * then memory protected.
                 */
                if((offset > LOWER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= LOWER0_PROTECT_TOP_OFFSET))
                {
                    protection_flag = protection_check(protection_user0, length);
                }
            }
            /* Check NVM0 upper1 protected area is Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user3) ||(WRITE_ONLY == protection_user3) || \
               (NO_READ_WRITE == protection_user3))
            {
                /* Check offset or (offset + length) is in the range of upper1 
                 *  protect memory if it is then memory protected.
                 */
                if(((offset >= NVM0_UPPER1_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= NVM0_UPPER1_PROTECT_TOP_OFFSET)) || \
                    (((offset + length_minus_one) >= NVM0_UPPER1_PROTECT_BOTTOM_OFFSET) && \
                    (offset < NVM0_UPPER1_PROTECT_BOTTOM_OFFSET)))
                {
                    protection_flag = protection_check(protection_user3, length);
                }
            }
        }
        /* Check lower0 or upper1 memory is protected or not.
         * No protection check for  0x3F000 - 0x3FFFF and 0x3E000 - 0x3EFFF lower1/upper0 
         * protected area of eNVM0 memory because it's fall under eNVM reserved area    
         */
        if(PROTECTION_ON == protection_flag)
        {
            /* Status is protection error if lower0 or upper1 area of eNVM0 is protected */
            status = NVM_PROTECTION_ERROR;
        }
        else
        {
            /* Check (offset + length) is out of eNVM memory*/
            if((offset + length_minus_one) > UPPER0_PROTECT_TOP_OFFSET)
            {
                status = NVM_INVALID_PARAMETER;
            }
            else
            {
                /* Check offset is in eNVM reserved memory - 64 pages reserved */
                if(((offset >= O60_NVM_RSV_OFFSET) && (offset <= UPPER0_PROTECT_TOP_OFFSET)) || \
                   (((offset + length_minus_one) >= O60_NVM_RSV_OFFSET) && \
                   (offset < O60_NVM_RSV_OFFSET)))
                {
                    /* Status is protection error if offset or (offset + length) is 
                     * in reserved area of eNVM
                     */
                    status = NVM_PROTECTION_ERROR;
                }
                else
                {
                    status = NVM_SUCCESS;
                }
            }
        }    
    }
    /* 090/150 device */
    else if((0xF807u == device_version) || (0xF806u == device_version))
    {
        protection_flag = PROTECTION_OFF;
        /* Read eNVM user protect register for lower and upper area protection data */
        protection_data = (SYSREG->ENVM_PROTECT_USER & PROTECT_USER_MASK);
        /* Check whether the eNVM0 and eNVM1 lower or upper area is protected or not */        
        if(PROTECT_USER_MASK != protection_data)
        {
            protection_user0 = (protection_data & 0x000Fu) & READ_WRITE_MASK;
            protection_user1 = ((protection_data & 0x00F0u) >> 4u) & READ_WRITE_MASK;
            protection_user2 = ((protection_data & 0x0F00u) >> 8u) & READ_WRITE_MASK;
            protection_user3 = ((protection_data & 0xF000u) >> 12u) & READ_WRITE_MASK;
            
            /* Check eNVM0 lower0 protected area is Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user0) ||(WRITE_ONLY == protection_user0) || \
               (NO_READ_WRITE == protection_user0))
            {
                /* Check offset is in the range of lower0 protect memory if it is
                 * then memory protected.
                 */
                if((offset > LOWER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= LOWER0_PROTECT_TOP_OFFSET))
                {
                    protection_flag = protection_check(protection_user0, length);
                }
            }
            /* Check eNVM0 upper0 protected area(in eNVM1) is Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user1) ||(WRITE_ONLY == protection_user1) || \
               (NO_READ_WRITE == protection_user1))
            {
                /* Check offset or (offset + length) is in the range of upper0
                 *  protect memory if it is then memory protected.
                 */
                if(((offset >= NVM0_UPPER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= NVM0_UPPER0_PROTECT_TOP_OFFSET)) || \
                    (((offset + length_minus_one) >= NVM0_UPPER0_PROTECT_BOTTOM_OFFSET) && \
                    (offset < NVM0_UPPER0_PROTECT_BOTTOM_OFFSET)))
                {
                    protection_flag = protection_check(protection_user1, length);
                }
            }
            /* Check NVM1 lower1 protected area is Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user2) ||(WRITE_ONLY == protection_user2) || \
               (NO_READ_WRITE == protection_user2))
            {
                /* Check offset or (offset + length)is in the range of lower1 
                 * protect memory if it is then memory protected.
                 */
                if(((offset >= LOWER1_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= LOWER1_PROTECT_TOP_OFFSET)) || \
                    (((offset + length_minus_one) >= LOWER1_PROTECT_BOTTOM_OFFSET) && \
                    (offset < LOWER1_PROTECT_BOTTOM_OFFSET)))
                {
                    protection_flag = protection_check(protection_user2, length);
                }
            }
            /* Checking NVM1 upper protected area for Read or Write or 'No R/W' access */
            if((READ_ONLY == protection_user3) ||(WRITE_ONLY == protection_user3) || \
               (NO_READ_WRITE == protection_user3))
            {
                /* Check offset or (offset + length)is in the range of upper1 
                 * protect memory if it is then memory protected.
                 */
                if(((offset >= UPPER1_PROTECT_BOTTOM_OFFSET) && \
                    (offset <= UPPER1_PROTECT_TOP_OFFSET)) || \
                    (((offset + length_minus_one) >= UPPER1_PROTECT_BOTTOM_OFFSET) && \
                    (offset < UPPER1_PROTECT_BOTTOM_OFFSET)))
                {
                    protection_flag = protection_check(protection_user3, length);
                }
            }
        }
        /* Check lower0/1 and upper0/1 memory is protected or not */
        if(PROTECTION_ON == protection_flag)
        {
           /* Status is protection error if lower or upper area of eNVM0 or 
            * eNVM1 is protected 
            */
            status = NVM_PROTECTION_ERROR;
        }
        else
        {
            /* Check (offset + length) is out of eNVM memory */
            if((offset + length_minus_one) > NVM1_TOP_OFFSET)
            {
                status = NVM_INVALID_PARAMETER;
            }
            else
            {
                /* Check offset is in eNVM reserved memory - 64 pages reserved */
                if(((offset >= NVM1_RSV_OFFSET) && (offset <= NVM1_TOP_OFFSET)) || \
                   (((offset + length_minus_one) >= NVM1_RSV_OFFSET) && \
                   (offset < NVM1_RSV_OFFSET)))
                {
                    /* Status is protection error if offset or (offset + length) is 
                     * in reserved area of eNVM
                     */
                    status = NVM_PROTECTION_ERROR;
                }
                else
                {
                    /* Status is success if offset or (offset + length) is 
                     * in RW access of eNVM memory
                     */
                    status = NVM_SUCCESS;
                }
            }
        }
    }
    return status;
}
/**************************************************************************//**
 * protection_check()
 * if the eNVM0 or eNVM1 lower/upper protected area with Read-Only access, 
 * then NVM_read_page_write_count() function can read the write count value
 * from eNVM page, length is set to zero in the function and return with 
 * protection off 
 * The NVM_write() and NVM_unlock() function parameter length is always
 * greater than zero for read only access and returns protection on.
 *
 * if the eNVM0 or eNVM1 lower/upper protected area with W-Only or No_RW
 * access then return with protection on
 */
static uint32_t protection_check(uint32_t protect_user, uint32_t length)
{    
    uint32_t protect_flag;
    
    /* Check Read Only access for page write count */
    if((READ_ONLY == protect_user) && (0x0u == length))
    {
        protect_flag = PROTECTION_OFF;
    }
    else
    {
        protect_flag = PROTECTION_ON;
    }
    return protect_flag;
}
             
#ifdef __cplusplus
}
#endif

/******************************** END OF FILE ******************************/
