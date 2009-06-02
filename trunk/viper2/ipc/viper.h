/*
 * Fabien JUIF
 * 
 * Useful for Trampoline
 *
 * This is the only header to include in Trampoline to have access to the IPC API.
 *
 * Useful to see : 
 *   com.h : 
 *      - st_sh_mem definition
 *      - reg_id_t definition
 *      - dev_id_t definition
 *      - reg_t definition
 *
 *   consts.h :
 *      - semaphores paths
 *
 *   util/fifo.h
 *      - Fifo functions and fifo_t definition
 */
#ifndef __VIPER_H__
#define __VIPER_H__

/** TODO I don't want to import this file. 
 * Beacause namespace is flooded by useless functions and structures.
 * See extern */
#include "com.h" 

/** 
 * Open the shared memory and semaphores next to initialized ipc structure 
 * @param ipc ipc_t structure to initialized, this is in these ipc structure that shared memory and semaphores will be open
 * @param pid the trampoline pid (returns by getpid of unistd.h)
 */
void vp_ipc_get_shared_memory(ipc_t *ipc);

/**
 * Get interruption identifier
 * @param ipc ipc_t structure linked to viper instance
 * @return interruption identifier
 * @return -1 on error
 */
int vp_ipc_get_interruption_id(ipc_t *ipc);

/**
 * Add the modified devices and its modified registers to the FIFO.
 * @param ipc ipc_t structure (contains shared memory and semaphore)
 * @param dev_id the modified device identifier
 * @param mask the modified registers of dev_id mask
 */
void vp_ipc_signal_update(ipc_t *ipc, dev_id_t dev_id, mask_t mask);

/**
 * Write a register
 * @param ipc ipc_t structure (contains shared memory and semaphore)
 * @param reg_id register id which will be modified
 * @param reg pointer to the reg_t structure to copy in reg reg_id
 */
void vp_ipc_write_reg(ipc_t *ipc, reg_id_t reg_id, reg_t *reg);

/**
 * Read a register
 * @param ipc ipc_t structure (contains shared memory and semaphore)
 * @param reg_id register id you want to read
 * @return the reg_t contains of the register identifier reg_id 
 */
reg_t vp_ipc_read_reg(ipc_t *ipc, reg_id_t reg_id);

/**
 * Unlock semaphore to unlock viper
 * @param ipc ipc_t structure (containing shared memory and semaphores)
 */
void vp_ipc_ready(ipc_t *ipc);

/**
 * Waits viper unlocking.
 * @param ipc ipc_t structure (containing shared memory and semaphores)
 */
void vp_ipc_wait_vp(ipc_t *ipc);

#endif /* __VIPER_H__ */
