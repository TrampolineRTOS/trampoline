#include "tpl_posixvp_irq_gen.h"
#include "tpl_os.h"

#define _XOPEN_SOURCE 500

#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <unistd.h>

static pid_t tpl_pid = -1;
static bool mode_is_raw = false;
static struct termios saved_mode;
static volatile sig_atomic_t quit_vp = 0;

static uint8_t tpl_posixvp_leds[4] = {0};
static const char *tpl_posixvp_leds_on[4] = {
    "\033[41m \033[0m", "\033[42m \033[0m", "\033[44m \033[0m",
    "\033[43m \033[0m"};
static const char *tpl_posixvp_leds_off = "_";

void print_leds(void)
{
  char output_string[64] = {'\0'};
  strcat(output_string, "LEDS: ");
  for (uint8_t led = 0; led < 4; led++)
  {
    if (tpl_posixvp_leds[led])
    {
      strcat(output_string, tpl_posixvp_leds_on[led]);
    }
    else
    {
      strcat(output_string, tpl_posixvp_leds_off);
    }
  }
  strcat(output_string, "\r\n");
  write(STDOUT_FILENO, output_string, 64);
}

void set_leds(uint8_t leds)
{
  size_t led = 0;
  while (leds > 0 && led < 4)
  {
    if (leds & 0x1)
    {
      tpl_posixvp_leds[led] = 0x1;
    }
    led++;
    leds = leds >> 1;
  }
  print_leds();
}

void reset_leds(uint8_t leds)
{
  size_t led = 0;
  while (leds > 0 && led < 4)
  {
    if (leds & 0x1)
    {
      tpl_posixvp_leds[led] = 0x0;
    }
    led++;
    leds = leds >> 1;
  }
  print_leds();
}

void switch_to_raw(void)
{
  struct termios new_mode;
  if (!mode_is_raw)
  {
    tcgetattr(STDIN_FILENO, &saved_mode);
    new_mode = saved_mode;
    cfmakeraw(&new_mode);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_mode);
    mode_is_raw = true;
  }
}

void switch_to_cooked(void)
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
  if (sig == SIGCHLD)
  {
    wait(NULL);
  }
}

void tpl_posixvp_irq_gen_init(void)
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
  else if (tpl_pid > 0)
  {
    //    printf("PID = %d\n",tpl_pid);
    switch_to_raw();
    while (!quit_vp)
    {
      int read_char;
      read_char = getchar();
      switch (read_char)
      {
      case 'a':
        if (kill(tpl_pid, SIGTERM) == -1)
        {
          fprintf(stderr, "posixvp:a:%s\r\n", strerror(errno));
        }
        break;
      case 'b':
        if (kill(tpl_pid, SIGTRAP) == -1)
        {
          fprintf(stderr, "posixvp:b:%s\r\n", strerror(errno));
        }
        break;
      case 'q':
        quit_vp = 1;
      default:;
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
