#include "../tpl_machine_arm.c"
void tpl_enable_os_interrupts(void)
{
    tpl_enable_interrupts();
}
void tpl_disable_os_interrupts(void)
{
    tpl_disable_interrupts();
}
