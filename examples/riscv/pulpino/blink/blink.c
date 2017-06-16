#include "tpl_os.h"
#include <spi.h>
#include <gpio.h>
#include <uart.h>
#include <utils.h>
#include <int.h>
#include <string_lib.h>
#include <pulpino.h>
#include <timer.h>

int sleeper = 1;

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

TASK(blink)
{
    int blinker = 1;
    while (1) {
        int_disable();
        printf("Blinking %d !\n", blinker);
        int_enable();
        blinker++;
        sleep_busy(1000);
    }
    TerminateTask();
}

TASK(sleeping)
{
    int_disable();
    printf("Sleeping... %d\n", sleeper);
    int_enable();
    sleeper++;
    sleep_busy(1000);
    TerminateTask();
}
