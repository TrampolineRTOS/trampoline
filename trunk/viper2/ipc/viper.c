#include "viper.h"

#include <stdio.h> /* fprintf() */
#include <fcntl.h> /* O_CREAT */
#include <unistd.h> /* getpid() */
#include <sys/mman.h> /* shm_open() mmap() */

#include "com.h"

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
  printf("(DD) Trampoline %d : create_sh_memory()\n", getpid());
#endif

  /* Creates shared memory */
  sprintf(data_file_path, DATA_FILE_PATH, ipc->pid);
  ipc->sh_mem_fd = shm_open(data_file_path, (O_RDWR | O_EXCL), 0600);
  if(-1 == ipc->sh_mem_fd)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("shm_open()");
    return;
  }

#ifdef DEBUG
  printf("(DD) Trampoline %d : map_sh_mem()\n", getpid());
#endif

  /* Map shared memory */
  map_sh_mem(ipc);
}

void vp_ipc_signal_update(ipc_t *ipc, global_ipc_t *global_ipc, dev_id_t dev_id, mask_t mask)
{
  /* Variables */
  modified_reg_t *modified_reg = NULL;

#ifdef DEBUG
  printf("(DD) Trampoline %d : vp_ipc_signal_update()\n", getpid());
#endif

  /* Builds modified_reg */
  modified_reg = (modified_reg_t *)malloc(sizeof(modified_reg_t));
  if(NULL == modified_reg)
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : malloc(Modified_reg) FIFO");
    return ;
  }

  modified_reg->dev = dev_id;
  modified_reg->reg_mask = mask;
  /* Release GIL (Python) */
  //Py_BEGIN_ALLOW_THREADS ?? for read time ?
    
  /* Read time from Viper2 global shared memory (from Trampoline) */
  if(0 != sem_wait(global_ipc->global_sem))
  {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("sem_wait(global_sem)");
      return;
  }  
    
  modified_reg->time = global_ipc->global_sh_mem->global_time;
    
  if(0 != sem_post(global_ipc->global_sem))
  {
      fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
      perror("viper : sem_post(global_sem)");
      return ;
  }    

  /* Semaphore */
  /**  FIFO is full ? (no empty cells) */
  if(0 != sem_trywait(ipc->fifo_empty_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    fprintf(stderr, "viper : FIFO shall never be full.");
    perror("viper : sem_trywait(fifo_empty_cells)");
    return ;
  }

  /* Add new cell into FIFO */
  fifo_push(&ipc->sh_mem->fifo, modified_reg);
    
  /* Semaphore */
  /** FIFO semaphore adding (unlock viper2 reading thread) */
  if(0 != sem_post(ipc->fifo_full_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_post(fifo)");
    return ;
  }

  /* Free memory */
  free(modified_reg);

}

int vp_ipc_get_interruption_id(ipc_t *ipc)
{
  /* Variables */
  int it_id = 0;

#ifdef DEBUG
  printf("(DD) Trampoline %d : vp_ipc_get_interruption_id()\n", getpid());
#endif

  /* Get semaphore */
  if(0 != sem_wait(ipc->it_id_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_wait()");
    return -1;
  }

  it_id = ipc->sh_mem->it_id;

  /* We have read the interruption id */
  /* You could want to reset the interruptions identifiers you have handle after treatement.
   * So you will have to do this :
   *
   * sem_wait()
   * it_id &= ~local
   * sem_post()
   * 
   * Where local is a copy of the mask given by this function
   */
  ipc->sh_mem->it_id = 0x0;
  
  /* Release semaphore : ok I read interruption identifier */
  if(-1 == sem_post(ipc->it_id_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_post()");
    return -1;
  }

  return it_id;
}

void vp_ipc_ready(ipc_t *ipc)
{
#ifdef DEBUG
  printf("(DD) Trampoline %d : vp_ipc_ready()\n", getpid());
#endif
  if(0 != sem_post(ipc->tpl_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_post(viper)");
  }
}

void vp_ipc_wait_vp(ipc_t *ipc)
{
#ifdef DEBUG
  printf("(DD) Trampoline %d : vp_ipc_wait_vp()\n", getpid());
#endif
  if(0 != sem_wait(ipc->vp_sem))
  {
    fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
    perror("viper : sem_wait(trampoline)");
  }
}

/**************************/
/** INTERFACES FUNCTIONS **/
void vp_ipc_get_shared_memory(ipc_t *ipc)
{
#ifdef DEBUG
  printf("(DD) Trampoline %d : vp_ipc_get_shared_memory()\n", getpid());
#endif
  /* Copy pid */
  ipc->pid = getpid();

  /* Init and open semaphores */
  init_ipc_struct(ipc);

  /* Semaphore to wait that viper initialized shared memory */
  vp_ipc_wait_vp(ipc);

#ifdef DEBUG
  printf("(DD) Trampoline %d : Viper ready\n", getpid());
#endif

  /* Create shared memory */
  create_sh_memory(ipc);
}

void vp_ipc_write_reg(ipc_t *ipc, reg_id_t reg_id, reg_t reg)
{
#ifdef DEBUG
  printf("(DD) Trampoline %d : vp_ipc_write_reg() - &ipc=%d\n", getpid(),(int)ipc);
#endif

  write_reg(ipc, reg_id, reg);
}

reg_t vp_ipc_read_reg(ipc_t *ipc, reg_id_t reg_id)
{
#ifdef DEBUG
  printf("(DD) Trampoline %d : vp_ipc_read_reg()\n", getpid());
#endif
  return read_reg(ipc, reg_id);
}




void create_global_sh_memory(global_ipc_t *global_ipc)
{
    /* Variables */
    char data_file_path[FILE_PATH_LEN];
    global_ipc->global_sh_mem = NULL;
    
#ifdef DEBUG
    printf("(DD) Trampoline %d : create_global_sh_memory()\n", getpid());
#endif
    
    /* Creates shared memory */
    sprintf(data_file_path, DATA_FILE_PATH, global_ipc->pid);
    global_ipc->global_sh_mem_fd = shm_open(data_file_path, (O_RDWR | O_EXCL), 0600);
    if(-1 == global_ipc->global_sh_mem_fd)
    {
        fprintf(stderr, "[%d] %s\n", __LINE__, __FILE__);
        perror("shm_open()");
        return;
    }
    
#ifdef DEBUG
    printf("(DD) Trampoline %d : map_global_sh_mem()\n", getpid());
#endif
    
    /* Map shared memory */
    map_global_sh_mem(global_ipc);
}

void vp_ipc_get_global_shared_memory(global_ipc_t *global_ipc)
{
#ifdef DEBUG
    printf("(DD) Trampoline %d (Viper %d) : vp_ipc_get_global_shared_memory()\n", getpid(), getppid());
#endif
    /* Copy pid */
    global_ipc->pid = getppid();
    
    /* Init and open semaphores */
    init_global_ipc_struct(global_ipc);
    
    /* Viper has already initialized the global shared memory */
    
#ifdef DEBUG
    printf("(DD) Trampoline %d : Viper ready\n", getpid());
#endif
    
    /* Create shared memory */
    create_global_sh_memory(global_ipc);
}

/**************************/



