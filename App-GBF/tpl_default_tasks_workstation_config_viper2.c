/* configuration for viper2 : */

#include "vp_ipc_devices.h"
#include "tpl_machine.h"
#include "tpl_default_tasks_workstation.h"
#include <stdio.h>
#include <time.h>

void dac(int value_to_convert)
{
	vp_ipc_write_reg(&viper, DAC0_DAC0_REG, (reg_t)value_to_convert);
    vp_ipc_signal_update(&viper, DAC0, DAC0_REG);
}

void start_dialoguing_dac(void)
{

}

void stop_dialoguing_dac(void)
{

}

void start_dialoguing_lcd(void)
{

}

void stop_dialoguing_lcd(void)
{

}

void lcd1(char *string)
{
    vp_ipc_write_reg(&viper, LCD1_LCD1_REG0, (reg_t)string[4]);
    vp_ipc_write_reg(&viper, LCD1_LCD1_REG1, (reg_t)string[3]);
    vp_ipc_write_reg(&viper, LCD1_LCD1_REG2, (reg_t)string[2]);
    vp_ipc_write_reg(&viper, LCD1_LCD1_REG3, (reg_t)string[1]);
    vp_ipc_write_reg(&viper, LCD1_LCD1_REG4, (reg_t)string[0]);
    vp_ipc_signal_update(&viper, LCD1, LCD1_REG0 | LCD1_REG1 | LCD1_REG2 | LCD1_REG3 | LCD1_REG4);
}

void lcd2(char *string)
{
    vp_ipc_write_reg(&viper, LCD2_LCD2_REG0, (reg_t)string[6]);
    vp_ipc_write_reg(&viper, LCD2_LCD2_REG1, (reg_t)string[5]);
    vp_ipc_write_reg(&viper, LCD2_LCD2_REG2, (reg_t)string[4]);
    vp_ipc_write_reg(&viper, LCD2_LCD2_REG3, (reg_t)string[3]);
    vp_ipc_write_reg(&viper, LCD2_LCD2_REG4, (reg_t)string[2]);
    vp_ipc_write_reg(&viper, LCD2_LCD2_REG5, (reg_t)string[1]);
    vp_ipc_write_reg(&viper, LCD2_LCD2_REG6, (reg_t)string[0]);
    vp_ipc_signal_update(&viper, LCD2, LCD2_REG0 | LCD2_REG1 | LCD2_REG2 | LCD2_REG3 | LCD2_REG4 | LCD2_REG5 | LCD2_REG6);
}