#include <stdio.h>
#include <unistd.h> /* sleep() getpid() rand() */
#include <signal.h>

#include "ipc_mod.h" /* API for viper */

#define IRQ_CHANNEL 7

int main()
{
  /* Variables */
  int cpt = 0;
  ipc_t* trampoline;

  /* Create instance */
  printf("[VPR] Run trampoline instance...\n");
  trampoline = tpl_ipc_create_instance("./trampoline");
  printf("[VPR] Trampoline instance running with pid %d\n", trampoline->pid);

  for(cpt = 0; cpt<10; cpt++) 
  {
    /* Send it */
    printf("[VPR] Send IRQ on channel %d to trampoline\n", IRQ_CHANNEL);
    tpl_ipc_send_it(trampoline, SIGUSR2, IRQ_CHANNEL);
  
    /* Pause */
    sleep(1);

  }

  tpl_ipc_destroy_instance(trampoline);
  free(trampoline);

  printf("[VPR] Stop\n");
  return 0;
}
