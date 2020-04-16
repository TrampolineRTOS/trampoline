#include "tpl_os.h"
#include "tpl_posixvp_irq_gen.h"

#define _XOPEN_SOURCE 500

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/wait.h>

static pid_t tpl_pid = -1;
static bool mode_is_raw = false;
static struct termios saved_mode;
static volatile sig_atomic_t quit_vp = 0;

void switch_to_raw()
{
  struct termios new_mode;
  if (! mode_is_raw)
  {
    tcgetattr(STDIN_FILENO, &saved_mode);
    new_mode = saved_mode;
    cfmakeraw(&new_mode);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_mode);
    mode_is_raw = true;
  }
}

void switch_to_cooked()
{
  if (mode_is_raw)
  {
    tcsetattr(STDIN_FILENO, TCSANOW, &saved_mode);
    mode_is_raw = false;
  }
}

void set_quit_vp(int sig)
{
  quit_vp = 1;
  if (sig = SIGCHLD)
  {
    wait(NULL);
  }
}

void tpl_posixvp_irq_gen_init()
{
  struct sigaction set_quit_vp_act;
  struct sigaction prev_chld_act;
  struct sigaction prev_int_act;

  // set handler for SIGCHLD and SIGINT to quit the virtual platform
  memset(&set_quit_vp_act, 0, sizeof(set_quit_vp_act));
  set_quit_vp_act.sa_handler = set_quit_vp;
  sigaction(SIGCHLD, &set_quit_vp_act, &prev_chld_act);
  sigaction(SIGINT, &set_quit_vp_act, &prev_int_act);

  // create a process for tpl
  tpl_pid = fork();
  if (tpl_pid == -1)
  {
    perror("Erreur lors de la creation de trampoline\n");
    exit(-1);
  }
  else if(tpl_pid > 0)
  {
//    printf("PID = %d\n",tpl_pid);
    switch_to_raw();
    while(! quit_vp)
    {
      int read_char;
      read_char = getchar();
      switch(read_char)
      {
        case 'a' :
          kill(tpl_pid, SIGUSR2);
          break;
        case 'b' :
          kill(tpl_pid, SIGTRAP);
          break;
        case 'q' :
          quit_vp = 1;
        default :
          ;
      }
    }
    // kill trampolne process and raise SIGCHLD
    kill(tpl_pid, SIGINT);
  }
  else
  {
    // Child process will proceed with vp init and start the OS
    // We restore the child handler to its default
    sigaction(SIGCHLD, &prev_chld_act, NULL);
    sigaction(SIGINT, &prev_int_act, NULL);

    // Ignore SIGUSR2 and SIGTRAP. Modified later on if ISR are plugged.
    struct sigaction ign_act;
    memset(&ign_act, 0, sizeof(ign_act));
    ign_act.sa_handler = SIG_IGN;
    sigaction(SIGUSR2, &ign_act, NULL);
    sigaction(SIGTRAP, &ign_act, NULL);

    return;
  }
  switch_to_cooked();
  fprintf(stderr, "Exiting virtual platform.\n");
  exit(0);
}

