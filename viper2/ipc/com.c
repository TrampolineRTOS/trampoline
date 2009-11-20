/**
 * Fabien JUIF
 */
#include "com.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h> /* shm_open() mmap() */
#include <unistd.h> /* ftruncate() */
#include <fcntl.h> /* O_* constantes */

#include "consts.h"


/**
 * Using a register, this function return the index to
 *  find this register in the shared memory
 * The register is a complete register ID (it means that
 *  it's device ID | register ID)
 */
int reg2i(reg_id_t n)
{
  int index_reg	    = 0; 
  int index_dev	    = 0;
  int reg_index_max = 0;
  reg_id_t reg_max  = REGISTER_ID_BITS;
  
  reg_id_t reg = n & REGISTER_MASK; /* Only reg */
  dev_id_t dev = (n & DEVICE_MASK) >> REGISTER_ID_BITS;   /* Only device */
  
  /* Find position of the 1 */
  while((reg = reg >> 1) != 0)
    ++index_reg;
  while((dev = dev >> 1) != 0)
    ++index_dev;
  while((reg_max = reg_max >> 1) != 0)
    ++reg_index_max;

  return ((index_dev << reg_index_max) | index_reg); 
}

void map_sh_mem(ipc_t *ipc)
{
  /* Maps shared memory with size of sh_mem */
  ipc->sh_mem = 
    mmap(
	NULL, 
	sizeof(struct st_sh_mem),
	PROT_WRITE, 
	MAP_SHARED, 
	ipc->sh_mem_fd, 
	0	      /* beginin of the shared memory in the memory page */
	);
  if(MAP_FAILED == ipc->sh_mem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("mmap()");
    if(0 != close(ipc->sh_mem_fd))
    {
      perror("close(sh_mem_fd)");
    }
    ipc->sh_mem = NULL;
    return;
  }
}

bool init_ipc_struct(ipc_t *ipc)
{
  /* Variables */
  char vp_sem_file_path[FILE_PATH_LEN];
  char tpl_sem_file_path[FILE_PATH_LEN];
  char it_id_sem_file_path[FILE_PATH_LEN];
  char fifo_full_sem_file_path[FILE_PATH_LEN];
  char fifo_empty_file_path[FILE_PATH_LEN];
#ifdef READER_WRITER_SEM
  char reader_sem_file_path[FILE_PATH_LEN];
  char writer_sem_file_path[FILE_PATH_LEN];
  char mutex_sem_file_path[FILE_PATH_LEN];
#else
  char reg_sem_file_path[FILE_PATH_LEN];
#endif

  /* Creats semaphores files path */
  sprintf(vp_sem_file_path, VP_SEM_FILE_PATH, ipc->pid);
  sprintf(tpl_sem_file_path, TPL_SEM_FILE_PATH, ipc->pid);
  sprintf(it_id_sem_file_path, IT_ID_SEM_FILE_PATH, ipc->pid);
  sprintf(fifo_full_sem_file_path, FIFO_FULL_SEM_FILE_PATH, ipc->pid);
  sprintf(fifo_empty_file_path, FIFO_EMPTY_SEM_FILE_PATH, ipc->pid);
#ifdef READER_WRITER_SEM
  sprintf(reader_sem_file_path, READER_SEM_FILE_PATH, ipc->pid);
  sprintf(writer_sem_file_path, WRITER_SEM_FILE_PATH, ipc->pid);
  sprintf(mutex_sem_file_path, MUTEX_SEM_FILE_PATH, ipc->pid);
#else
  sprintf(reg_sem_file_path, REG_SEM_FILE_PATH, ipc->pid);
#endif
  
  /* Open semaphores */
  /** Viper semaphore */
  ipc->vp_sem = sem_open(vp_sem_file_path, O_CREAT, 0600, 0); /* Block on first wait */
  if((void *)SEM_FAILED == ipc->vp_sem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("IPC : sem_open(Viper_sem)");
    return false;
  }
  
  /** Trampoline semaphore */
  ipc->tpl_sem = sem_open(tpl_sem_file_path, O_CREAT, 0600, 0); /* Block on first wait */
  if((void *)SEM_FAILED == ipc->tpl_sem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("IPC : sem_open(Tpl_sem)");
    return false;
  }

  /** Interruption ID semaphore */
  ipc->it_id_sem = sem_open(it_id_sem_file_path, O_CREAT, 0600, 1); /* 1 : Trampoline don't read before an interruption */
  if((void *)SEM_FAILED == ipc->it_id_sem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("IPC : sem_open(It_ID)");
    return false;
  }

  /** FIFO full cell semaphore */
  ipc->fifo_full_sem = sem_open(fifo_full_sem_file_path, O_CREAT, 0600, 0);
  if((void *)SEM_FAILED == ipc->fifo_full_sem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_open(Fifo_MAX)");
    return false;
  }

  /** FIFO empty cell semaphore */
  ipc->fifo_empty_sem = sem_open(fifo_empty_file_path, O_CREAT, 0600, FIFO_SIZE);
  if((void *)SEM_FAILED == ipc->fifo_empty_sem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_open(Fifo)");
    return false;
  }

#ifdef READER_WRITER_SEM
  /** Reader */
  ipc->reader_sem = sem_open(reader_sem_file_path, O_CREAT, 0600, 0); 
  if((void *)SEM_FAILED == ipc->reader_sem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_open(reader/writer sem : reader)");
    return false;
  }

  /** Writer */
  ipc->writer_sem = sem_open(writer_sem_file_path, O_CREAT, 0600, 0); 
  if((void *)SEM_FAILED == ipc->writer_sem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_open(reader/writer sem : writer)");
    return false;
  }
  
  /** Mutex */
  ipc->mutex_sem = sem_open(mutex_sem_file_path, O_CREAT, 0600, 1); 
  if((void *)SEM_FAILED == ipc->mutex_sem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_open(reader/writer sem : mutex)");
    return false;
  }
#else
  /** Registers access semaphore */
  ipc->reg_sem = sem_open(reg_sem_file_path, O_CREAT, 0600, 1); 
  if((void *)SEM_FAILED == ipc->reg_sem)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_open(Register)");
    return false;
  }
#endif

  /* Shared memory */
  ipc->sh_mem_fd = 0;

  return true;
}


void write_reg(ipc_t *ipc, reg_id_t reg_id, reg_t reg)
{
  /* Semaphore */
#ifdef READER_WRITER_SEM
  int i = 0;

  /** Get structure mutex */
  if(0 != sem_wait(ipc->mutex_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_wait(reader/writer semahore : mutex)");
    return ;
  }

  /** If there is someone other than me I can't write */
  if(ipc->sh_mem->reader_writer.waitingReaders + 
      ipc->sh_mem->reader_writer.readers +
      ipc->sh_mem->reader_writer.writer > 0)
  {
    ++ipc->sh_mem->reader_writer.waitingWriters;
    if(0 != sem_post(ipc->mutex_sem))
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("sem_post(reader/writer semaphore : mutex)");
      return ;
    }

    /* So we wait */
    if(0 != sem_wait(ipc->writer_sem))
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("sem_wait(reader/writer semaphore : writer)");
      return ;
    }
  }
  else /* I'm the only one so I can write */
  {
    ++ipc->sh_mem->reader_writer.writer; 
    if(0 != sem_post(ipc->mutex_sem))
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("sem_post(reader/writer semaphore : mutex)");
      return ;
    }
  }
#else
  /** Get register semaphore */
  if(0 != sem_wait(ipc->reg_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_wait(reg_write)");
    return;
  }
#endif

  /* Writes register */
  ipc->sh_mem->reg[reg2i(reg_id)] = reg;

  /* Release semaphore */
#ifdef READER_WRITER_SEM
  /** Get structure mutex */
  if(0 != sem_wait(ipc->mutex_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_wait(reader/writer semahore : mutex)");
    return ;
  }

  /** No one write */
  ipc->sh_mem->reader_writer.writer = 0;

  /** Writer are the prioritary */
  if(ipc->sh_mem->reader_writer.waitingWriters > 0)
  {
    --ipc->sh_mem->reader_writer.waitingWriters;
    ipc->sh_mem->reader_writer.writer = 1;

    /* Next writer can write */
    if(0 != sem_post(ipc->writer_sem))
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("sem_post(reader/writer semaphore : writer)");
      return ;
    }
  }
  else /* We allow read access to the registers array */
  {
    for(i = 0; i < ipc->sh_mem->reader_writer.waitingReaders; ++i)
    {
      ++ipc->sh_mem->reader_writer.readers;
      if(0 != sem_post(ipc->reader_sem))
      {
        fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
        perror("sem_post(reader/writer semaphore : reader)");
        return ;
      }
    }
  }

  /** Someone else can access to the semaphore structure */
  if(0 != sem_post(ipc->mutex_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_post(reader/writer semaphore : mutex)");
    return ;
  }
#else
  if(0 != sem_post(ipc->reg_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_post(reg_write)");
    return;
  }
#endif
}

reg_t read_reg(ipc_t *ipc, reg_id_t reg_id)
{
  /* Variables */
  reg_t reg = 0;

  /* Semahore */
#ifdef READER_WRITER_SEM
  /** Get structure mutex */
  if(0 != sem_wait(ipc->mutex_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_wait(reader/writer semahore : mutex)");
    return -1;
  }

  /** A writer use the registers array */
  if(ipc->sh_mem->reader_writer.writer == 1)
  {
    /* So we wait */
    ++ipc->sh_mem->reader_writer.waitingReaders;
    if(0 != sem_post(ipc->mutex_sem))
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("sem_post(reader/writer semaphore : mutex)");
      return -1;
    }
    if(0 != sem_wait(ipc->reader_sem))
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("sem_wait(reader/writer semaphore : mutex)");
      return -1;
    }
  }
  else /** No writer, so we can read */
  {
    ++ipc->sh_mem->reader_writer.readers;
    if(0 != sem_post(ipc->mutex_sem))
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("sem_post(reader/writer semaphore : mutex)");
      return -1;
    }
  }
#else
  /** Get register semaphore */
  if(0 != sem_wait(ipc->reg_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_wait(reg_write)");
    return -1;
  }
#endif

  /* Read register */
  reg = ipc->sh_mem->reg[reg2i(reg_id)]; /* Copy because reg could be overlap just after */

  /* Release semaphore */
#ifdef READER_WRITER_SEM
  /** Get structure mutex */
  if(0 != sem_wait(ipc->mutex_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_wait(reader/writer semahore : mutex)");
    return -1;
  }

  /** One reader delete */
  --ipc->sh_mem->reader_writer.readers;

  /** If a writer waits but there is not reader */
  if(ipc->sh_mem->reader_writer.waitingWriters > 0 &&
      ipc->sh_mem->reader_writer.readers == 0)
  {
    --ipc->sh_mem->reader_writer.waitingWriters;
    ipc->sh_mem->reader_writer.writer = 1;

    /* writer can access to the registers array */
    if(0 != sem_post(ipc->writer_sem))
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("sem_post(reader/writer semaphore : writer)");
      return -1;
    }
  }

  /** Release structure access semaphore */
  if(0 != sem_post(ipc->mutex_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_post(reader/writer semaphore : mutex)");
    return -1;
  }

#else
  if(0 != sem_post(ipc->reg_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("sem_post(reg_write)");
    return -1;
  }
#endif

  return reg;
}

void map_global_sh_mem(global_ipc_t *global_ipc)
{
    /* Maps shared memory with size of global_sh_mem */
    global_ipc->global_sh_mem = 
    mmap(
         NULL, 
         sizeof(struct st_global_sh_mem),
         PROT_WRITE, 
         MAP_SHARED, 
         global_ipc->global_sh_mem_fd, 
         0	      /* beginin of the shared memory in the memory page */
         );
    if(MAP_FAILED == global_ipc->global_sh_mem)
    {
        fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
        perror("mmap()");
        if(0 != close(global_ipc->global_sh_mem_fd))
        {
            perror("close(global_sh_mem_fd)");
        }
        global_ipc->global_sh_mem = NULL;
        return;
    }
}

bool init_global_ipc_struct(global_ipc_t *global_ipc)
{
    char global_sem_file_path[FILE_PATH_LEN];
    
    sprintf(global_sem_file_path, GLOBAL_SEM_FILE_PATH, global_ipc->pid);
    
    global_ipc->global_sem = sem_open(global_sem_file_path, O_CREAT, 0600, 1);
    if((void *)SEM_FAILED == global_ipc->global_sem)
    {
        fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
        perror("viper : sem_open(global_ipc)");
        return false;
    }
    
    return true;
    
}
