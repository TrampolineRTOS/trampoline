/**
 * Fabien JUIF
 * 
 *  Useful for Viper
 */
#ifndef __IPC_MOD_H__
#define __IPC_MOD_H__


#include "com.h"

/**
 * Launch one instance of trampoline
 * @param trampoline_path path to the executable
 * @return a ipc_t structure which contains semaphores and shared memory
 * @return NULL if error occurs.
 */
ipc_t *tpl_ipc_create_instance(char *trampoline_path);

void tpl_sem_post_fifo_full_sem(ipc_t *ipc);

/**
 * Kill a trampoline instance and free shared memory and semaphores
 * @param ipc ipc_t structure associate to a trampoline instance you want to kill.
 */
void tpl_ipc_destroy_instance(ipc_t *ipc);

/**
 * Send an interrupt to a trampoline's instance
 *  If you want to use an register to find the device identifier, use tpl_ipc_reg_to_dev()
 * @param ipc ipc_t structure associate to a trampoline instance
 * @param signum shall be SIGUSR2, SIGUSR1 or SIGALARM
 * @param it_id must be a bit set to 1.
 */
void tpl_ipc_send_it(ipc_t *ipc, int signum, dev_id_t it_id);

/**
 * Useful for the python module
 * @return the pid of the trampoline process
 */
pid_t tpl_ipc_get_pid(ipc_t *ipc);

/**
 * Write a register
 * @param ipc ipc_t structure (containing shared memory and semaphores)
 * @param reg_id register id which will be modified
 * @param reg pointer to the reg_t structure to copy in reg reg_id
 */
void tpl_ipc_write_reg(ipc_t *ipc, reg_id_t reg_id, reg_t reg);

/**
 * Read a register
 * @param ipc ipc_t structure (containing shared memory and semaphores)
 * @param reg_id register id you want to read
 * @return the reg_t contains of the register identifier reg_id 
 */
reg_t tpl_ipc_read_reg(ipc_t *ipc, reg_id_t reg_id);

/**
 * Unlock semaphore to unlock trampoline process
 * @param ipc ipc_t structure (containing shared memory and semaphores)
 */
void tpl_ipc_ready(ipc_t *ipc);

/**
 * Waits trampoline unlocking.
 * @param ipc ipc_t structure (containing shared memory and semaphores)
 */
void tpl_ipc_wait_tpl(ipc_t *ipc);

/**
 * @param ipc ipc_t structure (containing shared memory and semaphores)
 * @return the modified registers of a device (device is in the structure too)
 */
modified_reg_t tpl_ipc_pop_fifo(ipc_t *ipc);

#endif /* __IPC_MOD_H__ */
