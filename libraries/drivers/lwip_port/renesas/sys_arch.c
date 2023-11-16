#include "lwip/sys.h"
#include "arch/sys_arch.h"
#include "tpl_os.h"
#include <string.h>

#define MS_PER_TICKS 10
extern VAR(uint32, OS_VAR) tpl_time_counter;
extern CONST(tpl_proc_id, AUTOMATIC) INVALID_TASK;

static int hexval(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 0;
}

/* This is needed because "netif.c" uses it and without this implementation
 * this would cause LIBC to be included and that's something we don't want. */
int atoi(const char *num) {
  long value = 0;
  int neg = 0;

  if (num[0] == '0' && num[1] == 'x') {
      // hex
      num += 2;
      while (*num && isxdigit((unsigned char) *num))
          value = value * 16 + hexval(*num++);
  } else {
      // decimal
      if (num[0] == '-') {
          neg = 1;
          num++;
      }
      while (*num && *num >= '0' && *num <= '9')
          value = value * 10 + *num++  - '0';
  }
  if (neg)
      value = -value;
  return value;
}

#if !NO_SYS

struct sys_mbox_msg {
  struct sys_mbox_msg *next;
  void *msg;
};

#define SYS_MBOX_SIZE 128

struct sys_mbox {
  int used;
  int first, last;
  void *msgs[SYS_MBOX_SIZE];
  struct sys_sem *not_empty;
  struct sys_sem *not_full;
  struct sys_sem *mutex;
  int wait_send;
};

struct sys_mbox sys_mbox_list[MAX_NB_MBOX];

#define UNLOCKED 0
#define LOCKED 1

int waiting_task[TASK_COUNT];

struct sys_mutex {
  int used;
  int locked;
};

struct sys_mutex sys_mutex_list[MAX_NB_MUTEX];

struct sys_sem {
  int used;
  unsigned int c;
  struct sys_mutex * mutex;
};

struct sys_sem sys_sem_list[MAX_NB_SEM];


struct sys_thread {
  int dummy;
};

static struct sys_sem *sys_sem_new_internal(u8_t count);

/* Threads */
int debug_printf(const char *format, ...);

lwip_thread_fn threadPtr = NULL;

TASK(tcpip_task) {
	threadPtr(NULL);
  TerminateTask();
}

sys_thread_t sys_thread_new(const char *name, lwip_thread_fn function, void *arg, int stacksize, int prio)
{
  if(!strcmp(TCPIP_THREAD_NAME,name)) {
    threadPtr = function;
    ActivateTask(tcpip_task);
  } else {
    debug_printf("Task %s was not defined\n\r", name);
  }
  
  return NULL;
 }

#if LWIP_TCPIP_CORE_LOCKING
TaskType lwip_core_lock_holder_task_id;
extern sys_mutex_t lock_tcpip_core;

void sys_lock_tcpip_core(void)
{
  sys_mutex_lock(&lock_tcpip_core);
  GetTaskID(&lwip_core_lock_holder_task_id);
}

void sys_unlock_tcpip_core(void)
{
  lwip_core_lock_holder_task_id = INVALID_TASK;
  sys_mutex_unlock(&lock_tcpip_core);
}
#endif /* LWIP_TCPIP_CORE_LOCKING */

TaskType lwip_tcpip_task_id;
void sys_mark_tcpip_thread(void)
{
  GetTaskID(&lwip_tcpip_task_id);
}

void sys_check_core_locking(void)
{
  /* Embedded systems should check we are NOT in an interrupt context here */

  if (lwip_tcpip_task_id != INVALID_TASK) {
    TaskType current_task_id;
    GetTaskID(&current_task_id);

#if LWIP_TCPIP_CORE_LOCKING
    LWIP_ASSERT("Function called without core lock", current_task_id == lwip_core_lock_holder_task_id);
#else /* LWIP_TCPIP_CORE_LOCKING */
//    LWIP_ASSERT("Function called from wrong task", current_task_id == lwip_tcpip_task_id);
#endif /* LWIP_TCPIP_CORE_LOCKING */
  }
}

/*-----------------------------------------------------------------------------------*/
/* Mailbox */
err_t sys_mbox_new(struct sys_mbox **mb, int size)
{
  int i;
  LWIP_ASSERT("mbox != NULL", mb != NULL);
  LWIP_ASSERT("size > 0", size > 0);

  if (size > SYS_MBOX_SIZE) {
    return ERR_MEM;
  }

  for(i=0; i< MAX_NB_MBOX; i++) {
    if(!sys_mbox_list[i].used) {
      break;
    }
  }

  if(i == MAX_NB_MBOX) {
      LWIP_PLATFORM_DIAG(("no more available mbox"));
      return ERR_MEM;
  }

  sys_mbox_list[i].used = 1;
  sys_mbox_list[i].first = sys_mbox_list[i].last = 0;
  sys_mbox_list[i].not_empty = sys_sem_new_internal(0);
  sys_mbox_list[i].not_full = sys_sem_new_internal(0);
  sys_mbox_list[i].mutex = sys_sem_new_internal(1);
  sys_mbox_list[i].wait_send = 0;

  //SYS_STATS_INC_USED(mbox);
  *mb = &sys_mbox_list[i];
  return ERR_OK;
}

void sys_mbox_free(struct sys_mbox **mb)
{
  LWIP_ASSERT("mbox != NULL", mb != NULL);
  LWIP_ASSERT("*mbox != SYS_MBOX_NULL", *mb != SYS_MBOX_NULL);

  struct sys_mbox *mbox = *mb;
  //SYS_STATS_DEC(mbox);
  sys_arch_sem_wait(&mbox->mutex, 0);
  
  sys_sem_free(&mbox->not_empty);
  sys_sem_free(&mbox->not_full);
  sys_sem_free(&mbox->mutex);
  mbox->not_empty = mbox->not_full = mbox->mutex = NULL;

  mbox->used = 0;
}

err_t
sys_mbox_trypost(struct sys_mbox **mb, void *msg)
{
  u8_t first;
  struct sys_mbox *mbox;
  LWIP_ASSERT("invalid mbox", (mb != NULL) && (*mb != NULL));
  mbox = *mb;

  sys_arch_sem_wait(&mbox->mutex, 0);

  LWIP_DEBUGF(SYS_DEBUG, ("sys_mbox_trypost: mbox %p msg %p\n",
                          (void *)mbox, (void *)msg));

  if ((mbox->last + 1) >= (mbox->first + SYS_MBOX_SIZE)) {
    sys_sem_signal(&mbox->mutex);
    return ERR_MEM;
  }

  mbox->msgs[mbox->last % SYS_MBOX_SIZE] = msg;

  if (mbox->last == mbox->first) {
    first = 1;
  } else {
    first = 0;
  }

  mbox->last++;

  if (first) {
    sys_sem_signal(&mbox->not_empty);
  }

  sys_sem_signal(&mbox->mutex);

  return ERR_OK;
}

err_t
sys_mbox_trypost_fromisr(sys_mbox_t *q, void *msg)
{
  return sys_mbox_trypost(q, msg);
}

void sys_mbox_post(struct sys_mbox **mb, void *msg)
{
  u8_t first;
  struct sys_mbox *mbox;
  LWIP_ASSERT("invalid mbox", (mb != NULL) && (*mb != NULL));
  mbox = *mb;

  sys_arch_sem_wait(&mbox->mutex, 0);

  LWIP_DEBUGF(SYS_DEBUG, ("sys_mbox_post: mbox %p msg %p\n", (void *)mbox, (void *)msg));

  while ((mbox->last + 1) >= (mbox->first + SYS_MBOX_SIZE)) {
    mbox->wait_send++;
    sys_sem_signal(&mbox->mutex);
    sys_arch_sem_wait(&mbox->not_full, 0);
    sys_arch_sem_wait(&mbox->mutex, 0);
    mbox->wait_send--;
  }

  mbox->msgs[mbox->last % SYS_MBOX_SIZE] = msg;

  if (mbox->last == mbox->first) {
    first = 1;
  } else {
    first = 0;
  }

  mbox->last++;

  if (first) {
    sys_sem_signal(&mbox->not_empty);
  }

  sys_sem_signal(&mbox->mutex);
}

u32_t sys_arch_mbox_tryfetch(struct sys_mbox **mb, void **msg)
{
  struct sys_mbox *mbox;
  LWIP_ASSERT("invalid mbox", (mb != NULL) && (*mb != NULL));
  mbox = *mb;

  sys_arch_sem_wait(&mbox->mutex, 0);

  if (mbox->first == mbox->last) {
    sys_sem_signal(&mbox->mutex);
    return SYS_MBOX_EMPTY;
  }

  if (msg != NULL) {
    LWIP_DEBUGF(SYS_DEBUG, ("sys_mbox_tryfetch: mbox %p msg %p\n", (void *)mbox, *msg));
    *msg = mbox->msgs[mbox->first % SYS_MBOX_SIZE];
  }
  else{
    LWIP_DEBUGF(SYS_DEBUG, ("sys_mbox_tryfetch: mbox %p, null msg\n", (void *)mbox));
  }

  mbox->first++;

  if (mbox->wait_send) {
    sys_sem_signal(&mbox->not_full);
  }

  sys_sem_signal(&mbox->mutex);

  return 0;
}

u32_t sys_arch_mbox_fetch(struct sys_mbox **mb, void **msg, u32_t timeout)
{
  u32_t time_needed = 0;
  struct sys_mbox *mbox;
  LWIP_ASSERT("invalid mbox", (mb != NULL) && (*mb != NULL));
  mbox = *mb;

  /* The mutex lock is quick so we don't bother with the timeout
     stuff here. */
  sys_arch_sem_wait(&mbox->mutex, 0);

  while (mbox->first == mbox->last) {
    sys_sem_signal(&mbox->mutex);

    /* We block while waiting for a mail to arrive in the mailbox. We
       must be prepared to timeout. */
    if (timeout != 0) {
      time_needed = sys_arch_sem_wait(&mbox->not_empty, timeout);

      if (time_needed == SYS_ARCH_TIMEOUT) {
        return SYS_ARCH_TIMEOUT;
      }
    } else {
      sys_arch_sem_wait(&mbox->not_empty, 0);
    }

    sys_arch_sem_wait(&mbox->mutex, 0);
  }

  if (msg != NULL) {
    LWIP_DEBUGF(SYS_DEBUG, ("sys_mbox_fetch: mbox %p msg %p\n", (void *)mbox, *msg));
    *msg = mbox->msgs[mbox->first % SYS_MBOX_SIZE];
  }
  else{
    LWIP_DEBUGF(SYS_DEBUG, ("sys_mbox_fetch: mbox %p, null msg\n", (void *)mbox));
  }

  mbox->first++;

  if (mbox->wait_send) {
    sys_sem_signal(&mbox->not_full);
  }

  sys_sem_signal(&mbox->mutex);

  return time_needed;
}

/*
 * Don't use tpl_disable_all_interrupts_service() and
 * tpl_enable_all_interrupts_service() because several
 * functions like 'GetTaskID()' can't be called while
 * interrupt disabled
 */
void disable_interrupts() {
  __asm__ volatile ("CPSID IF"); /* Disable interrupts */
  //DisableAllInterrupts();
}

void enable_interrupts() {
  __asm__ volatile ("CPSIE IF"); /* Enable interrupts */
  //EnableAllInterrupts();
}

void wait_synchro(void) {
  TaskType curr_task;
  GetTaskID(&curr_task);
  LWIP_ASSERT("invalid task id", (curr_task<TASK_COUNT));
    
  waiting_task[curr_task] = 1;

  WaitEvent(lwip_sync);

  ClearEvent(lwip_sync);

  waiting_task[curr_task] = 0;
}

void sys_schedule() {
  wait_synchro();
}

void wakeup_waiting_tasks(void){
  for(int i=0; i<TASK_COUNT; i++) {
    if(waiting_task[i]!=0) {
     SetEvent(i, lwip_sync);
    }
  }

}
/*-----------------------------------------------------------------------------------*/
/* Semaphore */
static struct sys_sem *sys_sem_new_internal(u8_t count)
{
  int i;

  LWIP_ASSERT("initial_count invalid (not 0 or 1)",
    (count == 0) || (count == 1));

  for(i=0; i< MAX_NB_SEM; i++) {
    if(!sys_sem_list[i].used) {
      break;
    }
  }

  if(i == MAX_NB_SEM) {
      LWIP_PLATFORM_DIAG(("no more available semaphore"));
      return NULL;
  }

  if(sys_mutex_new(&sys_sem_list[i].mutex) == ERR_MEM) {
      return NULL;
  }

  sys_sem_list[i].used = 1;
  sys_sem_list[i].c = count;

  //SYS_STATS_INC_USED(sem);

  return &sys_sem_list[i];
}

err_t sys_sem_new(struct sys_sem **sem, u8_t count)
{
  LWIP_ASSERT("sem != NULL", sem != NULL);

  *sem = sys_sem_new_internal(count);
  if (*sem == NULL) {
    return ERR_MEM;
  }
  return ERR_OK;
}

void sys_sem_free(struct sys_sem **s)
{
  struct sys_sem *sem;
  LWIP_ASSERT("invalid sem", (s != NULL) && (*s != NULL));
  sem = *s;

  sys_mutex_free(&sem->mutex);

  //SYS_STATS_DEC(sem);
  sem->used = 0;
}

void sys_sem_signal(sys_sem_t *s)
{
  struct sys_sem *sem;
  LWIP_ASSERT("invalid sem", (s != NULL) && (*s != NULL));
  sem = *s;

  sys_mutex_lock(&(sem->mutex));
  sem->c++;

  if (sem->c > 1) {
    sem->c = 1;
  }

  sys_mutex_unlock(&(sem->mutex));
}


u32_t sys_arch_sem_wait(sys_sem_t *s, u32_t timeout_ms)
{
  u32_t time_needed = 0;
  struct sys_sem *sem;
  LWIP_ASSERT("invalid sem", (s != NULL) && (*s != NULL));
  sem = *s;

  sys_mutex_lock(&(sem->mutex));
  if (timeout_ms > 0) {
    u32_t star_ms = sys_now();
    while ((sem->c <= 0) && (sys_now() < star_ms + timeout_ms)) {
      sys_mutex_unlock(&(sem->mutex));
      sys_schedule();
      sys_mutex_lock(&(sem->mutex));
    }

    if (sem->c <= 0) {
      sys_mutex_unlock(&(sem->mutex));
      return SYS_ARCH_TIMEOUT;
    }
  } else {
    while (sem->c <= 0) {
      sys_mutex_unlock(&(sem->mutex));
      sys_schedule();
      sys_mutex_lock(&(sem->mutex));
    }
  }

  sem->c--;
  sys_mutex_unlock(&(sem->mutex));
  return (u32_t)time_needed;
}
/*-----------------------------------------------------------------------------------*/
/* Mutex */
/** Create a new mutex
 * @param mutex pointer to the mutex to create
 * @return a new mutex */

err_t
sys_mutex_new(struct sys_mutex **mutex)
{
  int i;

  disable_interrupts();

  for(i=0; i< MAX_NB_MUTEX; i++) {
    if(!sys_mutex_list[i].used) {
      break;
    }
  }

  if(i == MAX_NB_MUTEX) {
      LWIP_PLATFORM_DIAG(("no more available mutex"));
      enable_interrupts();
      return ERR_MEM;
  }

  sys_mutex_list[i].used = 1;
  sys_mutex_list[i].locked = UNLOCKED;

  *mutex = &sys_mutex_list[i];

  enable_interrupts();

  return ERR_OK;
}

/** Lock a mutex
 * @param mutex the mutex to lock */
void
sys_mutex_lock(struct sys_mutex **mutex)
{
  struct sys_mutex *mtx;

  disable_interrupts();
  mtx = *mutex;

  while(mtx->locked == LOCKED) {
    enable_interrupts();

    wait_synchro();

    disable_interrupts();
  }

  mtx->locked = LOCKED;

  enable_interrupts();
}

/** Unlock a mutex
 * @param mutex the mutex to unlock */
void
sys_mutex_unlock(struct sys_mutex **mutex)
{
  struct sys_mutex *mtx;

  disable_interrupts();
  mtx = *mutex;
  mtx->locked = UNLOCKED;
  enable_interrupts();

  wakeup_waiting_tasks();
}

/** Delete a mutex
 * @param mutex the mutex to delete */
void
sys_mutex_free(struct sys_mutex **mutex)
{
  struct sys_mutex *mtx;

  disable_interrupts();
  mtx = *mutex;
  mtx->used = 0;
  enable_interrupts();
}

#endif /* !NO_SYS */

/* Time */
u32_t sys_now(void) {
#if !NO_SYS
  return tpl_time_counter * MS_PER_TICKS;
#else
  return 0;
#endif
}

/* Init */
void sys_init(void)
{
#if !NO_SYS
  int i;

  for(i = 0; i < TASK_COUNT; i++) {
    waiting_task[i] = 0;
  }

  for(i = 0; i < MAX_NB_MUTEX; i++) {
    sys_mutex_list[i].used = 0;
  }

  for(i = 0; i < MAX_NB_SEM; i++) {
    sys_sem_list[i].used = 0;
  }

  for(i = 0; i < MAX_NB_MBOX; i++) {
    sys_mbox_list[i].used = 0;
  }
#endif /* !NO_SYS */
}

#if SYS_LIGHTWEIGHT_PROT

sys_prot_t
sys_arch_protect(void)
{
  return 0;
}

void
sys_arch_unprotect(sys_prot_t pval)
{
}

#endif /* SYS_LIGHTWEIGHT_PROT */
