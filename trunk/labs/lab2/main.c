#include "tpl_os.h"

#define _XOPEN_SOURCE 500

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/types.h>
#include <sys/wait.h>

int tpl_pid;
const int RAW = 0;
const int COOKED = 1;
int mode;
struct termios saved_mode;

void switch_to_raw() {
  struct termios new_mode;
  if (mode == COOKED) {
    tcgetattr(STDIN_FILENO, &saved_mode);
    new_mode = saved_mode;
    cfmakeraw(&new_mode);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_mode);
    mode = RAW;
	}
}

void switch_to_cooked() {
  if (mode == RAW) {
    tcsetattr(STDIN_FILENO, TCSANOW, &saved_mode);
    mode = COOKED;
  }
}

void handle_int(int sig) {
  kill(tpl_pid, SIGINT);
  wait(NULL);
  switch_to_cooked();
  exit(0);
}

void init_irq_generator() {
  if ((tpl_pid = fork()) == -1) {
    perror("Erreur lors de la creation de trampoline\n");
    exit(-1);
  }	
  if(tpl_pid != 0) {
    signal(SIGINT, handle_int);
    printf("PID = %d\n",tpl_pid);
    switch_to_raw();
    while(1) {
      int read_char;
      read_char = getchar();
      switch(read_char) {
      case 'a' : 
        kill(tpl_pid, SIGPIPE);
        break;
      case 'b' :
        kill(tpl_pid, SIGTRAP);
        break;
      case 'q' :
        raise(SIGINT);
      default :
        ;
      }
    }
  }
}

int main(void) {
  mode = COOKED;
  init_irq_generator();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}
