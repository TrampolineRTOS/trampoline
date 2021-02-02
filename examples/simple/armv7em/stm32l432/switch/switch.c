#include "tpl_os.h"
#include <stdint.h>

void SwitchContext();

void func1()
{
  while (1)
  {
    SwitchContext();
  }
}

void func2()
{
  while (1)
  {
    SwitchContext();
  }
}

uint32_t running = 0;

/* __attribute__ ((aligned (8))) aligns stacks to addresses divisible by 8 */
uint32_t __attribute__((aligned(8))) func1Stack[100];
uint32_t __attribute__((aligned(8))) func2Stack[100];

typedef struct
{
  void (*function)();
  uint32_t *stackPointer;
} TaskDescriptor;

TaskDescriptor func1TD = {func1, func1Stack + 100};
TaskDescriptor func2TD = {func2, func2Stack + 100};

void initContext(TaskDescriptor *desc)
{
  *(--desc->stackPointer) = 0x01000000; /* Push psr */
  *(--desc->stackPointer) = (uint32_t)desc->function;
  desc->stackPointer -= 14;
}

int main(void)
{
  initContext(&func1TD);
  initContext(&func2TD);
  SwitchContext();
  while (1)
    ;
  return 0;
}
