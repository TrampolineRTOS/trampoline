// see counter.oil head of file for information about the compilation process.
//

#include "Arduino.h"
#include "tpl_os.h"

/**
 * configure TIMER2 to generate an interrupt
 * each 1 ms
 */
void timerInit()
{
  TCCR2A = 0;
  TCNT2 = 0;
  // clkio = 16MHz => clk = 250KHz
  TCCR2B = (1 << WGM22) | (1 << CS22); // CTC and clk = Clkio/64
                                       // interrupt each 1ms
  OCR2A = 250 - 1;
  TIMSK2 |= (1 << TOIE2);
  interrupts();
}

void setup()
{
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  timerInit();
}

/** The TASK is activated by the alarm "periodicAl":
 * The alarm "periodicAl" is configured in the .oil file to activate task
 * "periodicTask" each 100 pulses of counter MyCustomCounter .
 * This task is periodic, with a period of 100ms.
 */
TASK(periodicTask)
{
  static unsigned int nb = 0;
  nb++;
  if (nb & 1)
    digitalWrite(13, HIGH); // odd
  else
    digitalWrite(13, LOW); // even
  TerminateTask();
}
