#include "msp430.h"
#include "tpl_os.h"

extern unsigned _chkptStartAddress;
extern unsigned __data_start;
extern unsigned __tpl_end_of_checkpointing_zone;

#if WITH_CHECKPOINTING == YES
#define OS_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_save_checkpoint(){
    // if(tpl_checkpoint_buffer == -1){
    //     return;
    // }
    unsigned *ptr_chkpt = & _chkptStartAddress;
    unsigned *ptr_sram_start = & __data_start;
    unsigned *ptr_sram_stop = & __tpl_end_of_checkpointing_zone;
    
    // if(tpl_checkpoint_buffer == 0){
        while(ptr_sram_start != ptr_sram_stop){
            *ptr_chkpt = *ptr_sram_start;
            ptr_chkpt++;
            ptr_sram_start++;
        }
    // }
    // else{
    //     *ptr_chkpt += 256;
    //     while(ptr_sram_start != ptr_sram_stop){
    //         *ptr_chkpt = *ptr_sram_start;
    //         ptr_chkpt++;
    //         ptr_sram_start++;
    //     }
    // }
    return;
}

FUNC(void, OS_CODE) tpl_load_checkpoint (){
    // if(tpl_checkpoint_buffer == -1){
    //     return;
    // }
    unsigned *ptr_chkpt = & _chkptStartAddress;
    unsigned *ptr_sram_start = & __data_start;
    unsigned *ptr_sram_stop = & __tpl_end_of_checkpointing_zone; 

    // if(tpl_checkpoint_buffer == 0){
        while(ptr_sram_start != ptr_sram_stop){
            *ptr_sram_start = *ptr_chkpt;
            ptr_chkpt++;
            ptr_sram_start++;
        }
    // }
    // else{
    //     *ptr_chkpt += 256;
    //     while(ptr_sram_start != ptr_sram_stop){
    //         *ptr_sram_start = *ptr_chkpt;
    //         ptr_chkpt++;
    //         ptr_sram_start++;
    //     }
    // }
    return;  
}

// FUNC(void, OS_CODE) tpl_save_checkpoint_dma{
    
// }

// FUNC(void, OS_CODE) tpl_load_checkpoint_dma{
    
// }
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
#endif //WITH_CHECKPOINTING

