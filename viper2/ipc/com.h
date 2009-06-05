/**
 * Fabien JUIF
 * IPC API
 * Useful for Trampoline and Viper
 */
#ifndef __COM_H__
#define __COM_H__

#include <stdlib.h> /* size_t */
#include <semaphore.h> /* sem_t sem_wait() sem_post() */

#include "util/fifo.h"

typedef int64_t reg_t; /* a register do 4 octets */
typedef int64_t reg_id_t;

/**
 * Structure
 * Reader writer semaphore system
 */
#ifdef READER_WRITER_SEM
struct st_reader_writer
{
  int waitingReaders;
  int readers;
  int waitingWriters;
  int writer;
};
#endif

/**
 * Structure,
 *  Shared memory between a trampoline instance an viper 2
 */
struct st_sh_mem
{
  dev_id_t it_id;	/* interruption id (viper to trampoline) */
  fifo_t fifo;		/* fifo container (trampoline to viper) */

#ifdef READER_WRITER_SEM
  struct st_reader_writer reader_writer;
#endif

  reg_t reg[REGISTERS_NB]; /* register array */
};

/**
 * Structure,
 *  Use to regroup semaphores and shared memory
 */
typedef struct st_ipc
{
  pid_t pid; /* Trampoline instance pid, use to create semaphores and share memory paths */

  /* semaphores */
  sem_t *vp_sem; /* Viper handshake */
  sem_t *tpl_sem; /* Trampoline handshake */
  sem_t *it_id_sem; /* Interruption ID acessing */
  sem_t *fifo_full_sem; /* Access fifo to pop (full cells number) */
  sem_t *fifo_empty_sem; /* Access fifo to push (empty cells number) */
#ifdef READER_WRITER_SEM
  sem_t *reader_sem;
  sem_t *writer_sem;
  sem_t *mutex_sem;
#else
  sem_t *reg_sem;   /* Access to reg array */
#endif

  /* shared memory */
  struct st_sh_mem *sh_mem;
  int sh_mem_fd;	    /* file descriptor */
}ipc_t;

/**
 * Initialize all the ipc_t structure
 * @param trampline pointer to structure to initialize
 * @return false if an error occurs
 */
bool init_ipc_struct(ipc_t *ipc);

/**
 * Write a register
 * @param ipc ipc_t structure (contains shared memory and semaphore)
 * @param reg_id register id which will be modified
 * @param reg information to copy in reg reg_id
 */
void write_reg(ipc_t *ipc, reg_id_t reg_id, reg_t reg);

/**
 * Read a register
 * @param ipc ipc_t structure (contains shared memory and semaphore)
 * @param reg_id register id you want to read
 * @return the reg_t contains of the register identifier reg_id 
 */
reg_t read_reg(ipc_t *ipc, reg_id_t reg_id);

/**
 * Map the shared memory
 *
 * @param ipc pointer on a ipc_t structure where the shared memory is created.
 * @return ipc->sh_mem == NULL on error
 */
void map_sh_mem(ipc_t *ipc);

#endif /* __COM_H__ */
