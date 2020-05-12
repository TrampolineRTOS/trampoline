#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include "tpl_posixvp_irq_gen.h"
#include "tpl_os.h"

#define _XOPEN_SOURCE 500


int main(void)
{
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

ISR(apushed) {
  static bool set = true;
  if (set)
  {
    set_leds(RED | GREEN);
  }
  else
  {
    reset_leds(RED | GREEN);
  }
  set = !set;
}

ISR (bpushed) {
  static bool set = true;
  if (set)
  {
    set_leds(YELLOW | BLUE);
  }
  else
  {
    reset_leds(YELLOW | BLUE);
  }
  set = !set;
}
