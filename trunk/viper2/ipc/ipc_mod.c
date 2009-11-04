/**
 * Fabien JUIF
 */
#include "ipc_mod.h"

#include <unistd.h> /* access() fork() pid_t */

#include <stdio.h>
#include <stdlib.h> /* malloc() */
#include <signal.h> /* kill() */
#include <fcntl.h> /* O_* constantes */
#include <stdbool.h> /* bool */
#include <sys/mman.h> /* shm_open() mmap() */
#include <Python.h> /* GIL get and release */

#include "consts.h"

/**
 * Create and map the shared memory between viper and a trampoline instance.
 *  If the shared memory already exists, it will be just returned.
 *  Write shared memory and file descriptor in ipc structure.
 *
 * This is viper which creates and truncates the shared memory.
 *  So you must init semaphores before for trampoline waits for this creation.
 *
 * On error, ipc->sh_mem == NULL 
 * @param ipc ipc_t structure associate to the trampoline instance.
 */
void create_sh_memory(ipc_t *ipc)
{
  /* Variables */
  char data_file_path[FILE_PATH_LEN];
  ipc->sh_mem = NULL;

#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : create_sh_memory()\n", ipc->pid);
#endif

  /* Creates shared memory */
  sprintf(data_file_path, DATA_FILE_PATH, ipc->pid);
  ipc->sh_mem_fd = shm_open(data_file_path, (O_CREAT | O_RDWR | O_EXCL), 0600);
  if(-1 == ipc->sh_mem_fd)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("shm_open()");
    return;
  }

  /* We don't need an entire memory page */
  if(-1 == ftruncate(ipc->sh_mem_fd, sizeof(struct st_sh_mem)))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("ftruncate()");
    return;
  }

#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : map_sh_mem()\n", ipc->pid);
#endif

  /* Maps shared memory with size of sh_mem */
  map_sh_mem(ipc);
}

void tpl_ipc_send_it(ipc_t *ipc, int signum, dev_id_t it_id, int verbose)
{
#ifdef DEBUG
printf("(DD) Viper to trampoline %d : tpl_ipc_send_it()\n", ipc->pid);
#endif

  /* Semaphore : Mutex to access interruption id */ 
  if(0 != sem_wait(ipc->it_id_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_wait()");
    return ;
  }

  /* Write the interruption ID on the shared memory */
  dev_id_t previous_it = ipc->sh_mem->it_id;
  if ( (previous_it & it_id) && verbose == 1 ){
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("viper : interrupt identifier already sent by Viper2 but didn't catch by Trampoline");
      return ;
  }
  else{
      ipc->sh_mem->it_id |= it_id;
  }
  
	
  /* Release semaphore */
  if(0 != sem_post(ipc->it_id_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_post()");
    return ;
  }
  
  /* Signal */
  kill(ipc->pid, signum);
}

#ifdef READER_WRITER_SEM
void init_reader_writer(struct st_reader_writer *reader_writer, int pid)
{
  /* Structure variables */
  reader_writer->waitingReaders = 0;
  reader_writer->readers = 0;
  reader_writer->waitingWriters = 0;
  reader_writer->writer = 0;

}
#endif

ipc_t *tpl_ipc_create_instance(char *ipc_path)
{
  /* Variables */
  pid_t pid = 0;
  ipc_t *ipc = NULL;
  int i = 0;
  char *args[] = { NULL, NULL };
  char *env[]  = { NULL };	  /* No environement parameter */

#ifdef DEBUG
  printf("(DD) Viper to trampoline ?? : tpl_ipc_create_instance()\n");
#endif

  /* Can't execute ipc */
  if(0 != access(ipc_path, X_OK))
  {
    fprintf(stderr, 
	"viper : Cannot execute application at : %s\n", 
	ipc_path);
    return NULL;
  }

  /* The only one argument to execute ipc */
  args[0] = ipc_path;

  /* Forks to execute ipc */
  if(0 == (pid = fork())) /* fork: SON */
  {
    if(execve(ipc_path, args, env) < 0)
    {
      fprintf(stderr, "executable' path : %s\n", ipc_path);
      perror("viper : unable to launch the application.");
      exit(-1); /* stop new process */
    }

    /* We shall never be here */
    perror("viper : why I'm here ?");
    exit(-1);
  }

  else if(1 != pid) /* fork: DAD' */
  {
    /* Save ipc's pid */
    ipc = (ipc_t *)malloc(sizeof(ipc_t));
    if(ipc == NULL)
    {
      fprintf(stderr, "ipc's path : %s\n", ipc_path);
      perror("viper : malloc()");
      return NULL;
    }
    ipc->pid = pid;

    /* Initialize structure and open semaphores */
    if(!init_ipc_struct(ipc))
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      fprintf(stderr, "viper : init_ipc_struct()");
      return NULL;
    }

    /* Shared memory */
    create_sh_memory(ipc);
    if(NULL == ipc->sh_mem)
    {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("viper : create_sh_memory()");
      return NULL;
    }

    /* Initialize shared memory */
    ipc->sh_mem->it_id = 0x0; /* not any interruption */
    fifo_init(&ipc->sh_mem->fifo);
    for(i = 0; i < REGISTERS_NB; ++i)
      ipc->sh_mem->reg[i] = 0;

    /* Reader/Writer semaphore structure */
#ifdef READER_WRITER_SEM
    init_reader_writer(&ipc->sh_mem->reader_writer, ipc->pid);
#endif

    /* Unlock semaphore to start trampoline */
    tpl_ipc_ready(ipc);

    /* Waits trampoline */
    tpl_ipc_wait_tpl(ipc);

    return ipc;
  }

  else /* fork: DAD' / ERROR */
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : fork()");
    return NULL;
  }

  return NULL; /* Never here */
}

void tpl_sem_post_fifo_full_sem(ipc_t *ipc)
{    
    /* Closing Viper2 and Trampoline, Viper2 Reading Thread
       has to be unlock by "posting" the fifo_full_sem. */
    if(0 != sem_post(ipc->fifo_full_sem))
    {
        fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
        perror("viper : sem_post(fifo)");
        return ;
    }
}

void tpl_ipc_destroy_instance(ipc_t *ipc)
{
#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_destroy_instance()\n", ipc->pid);
#endif

  /* Kills ipc */
  if(0 != kill(ipc->pid, SIGKILL))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    fprintf(stderr, "trampoline instance is may not be killed\n");
    perror("viper : kill() ipc");
    /** We don't stop viper to try killing other ipc instance */
  }

/* TODO CLOSE READER WRITER SEMAPHORE BEFORE REMOVE SHARED MEMORY */
#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_destroy_instance - removes shared memory\n", ipc->pid);
#endif
  /* Removes shared memory */
  if(0 != close(ipc->sh_mem_fd))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : close(sh_mem_fd)");
  }

  /* Removes semaphores */
#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_destroy_instance - removes Viper semaphore\n", ipc->pid);
#endif
  /** Viper semaphore */
  if(NULL != ipc->vp_sem)
  if(0 != sem_close(ipc->vp_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_close(Viper)");
  }

#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_destroy_instance - removes Trampoline semaphore\n", ipc->pid);
#endif
  /** Trampoline semaphore */
  if(NULL != ipc->tpl_sem)
  if(0 != sem_close(ipc->tpl_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_close(Trampoline)");
  }
  
#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_destroy_instance - removes it_id semaphore\n", ipc->pid);
#endif
  /** it_id semaphore */
  if(NULL != ipc->it_id_sem)
  if(0 != sem_close(ipc->it_id_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_close(Interruption_ID)");
  }

#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_destroy_instance - removes reg semaphore\n", ipc->pid);
#endif
  /** reg semaphore */
#ifdef READER_WRITER_SEM
  /** Writer */
  if(NULL != ipc->writer_sem)
  if(0 != sem_close(ipc->writer_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_close(Reader/writer semaphore : writer)");
  }

  /** Reader */
  if(NULL != ipc->reader_sem)
  if(0 != sem_close(ipc->reader_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_close(Reader/Writer semaphore : reader)");
  }

  /** Mutex */
  if(NULL != ipc->mutex_sem)
  if(0 != sem_close(ipc->mutex_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_close(Reader/Writer semaphore : mutex)");
  }

#else
  if(NULL != ipc->reg_sem)
  if(0 != sem_close(ipc->reg_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_close(Register)");
  }
#endif

#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_destroy_instance - removes fifo full cells semaphore\n", ipc->pid);
#endif
  /** fifo full cells semaphore */
  if(NULL != ipc->fifo_full_sem)
  if(0 != sem_close(ipc->fifo_full_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_close(Fifo_max)");
  }

#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_destroy_instance - removes fifo empty cells semaphore\n", ipc->pid);
#endif
  /** fifo empty cells semaphore */
  if(NULL != ipc->fifo_empty_sem)
  if(0 != sem_close(ipc->fifo_empty_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_close(Fifo)");
  }

  /* Frees ipc data structure */
  free(ipc);
}

void tpl_ipc_ready(ipc_t *ipc)
{
#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_ready()\n", ipc->pid);
#endif

  if(0 != sem_post(ipc->vp_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_post(viper)");
  }
}

void tpl_ipc_wait_tpl(ipc_t *ipc)
{
#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_wait_tpl()\n", ipc->pid);
#endif

  if(0 != sem_wait(ipc->tpl_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_wait(trampoline)");
  }
}

modified_reg_t tpl_ipc_pop_fifo(ipc_t *ipc)
{
  /* Variable */
  modified_reg_t modified_reg = {-1, -1};
  const modified_reg_t modified_reg_err = {-1, -1};

#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_pop_fifo()\n", ipc->pid);
#endif
  /* Release GIL (Python) */
  Py_BEGIN_ALLOW_THREADS

  /* Semaphore */
  /** FIFO is empty ? (no full cells) */
  if(0 != sem_wait(ipc->fifo_full_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_wait(fifo_full_cells)");
    return modified_reg_err;
  }

  /* Get first cell from FIFO */
  modified_reg = fifo_pop(&ipc->sh_mem->fifo);

  /* Semaphore */
  /** FIFO semaphore adding (new empty cell) */
  if(0 != sem_post(ipc->fifo_empty_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_post(fifo_empty_cells)");
    return modified_reg_err;
  }

  /* Get GIL (Python) */
  Py_END_ALLOW_THREADS

  return modified_reg;
}

/***************************/
/** INTERFACES FUNCTIONS **/
pid_t tpl_ipc_get_pid(ipc_t *ipc)
{
#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_get_pid\n", ipc->pid);
#endif

  return ipc->pid;
}

void tpl_ipc_write_reg(ipc_t *ipc, reg_id_t reg_id, reg_t reg)
{
#ifdef DEBUG
	printf("(DD) Viper to trampoline %d : tpl_ipc_write_reg()\n", ipc->pid);
#endif

  write_reg(ipc, reg_id, reg);
}

reg_t tpl_ipc_read_reg(ipc_t *ipc, reg_id_t reg_id)
{
#ifdef DEBUG
  printf("(DD) Viper to trampoline %d : tpl_ipc_read_reg()\n", ipc->pid);
#endif
  return read_reg(ipc, reg_id);
}

/****************************/
