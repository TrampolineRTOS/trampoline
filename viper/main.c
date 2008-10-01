/*
 * VIPER
 *
 * VIrtual Processor EmulatoR
 *
 * Viper is an add-on of the Unix process version of the Trampoline OS.
 */
 
#include "com.h"
#include "exec.h"
#include "log.h"
#include "control.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

char data_file_path[32];
char r_sem_file_path[32];
char w_sem_file_path[32];

int main (int argc, const char *argv[]) {

	vp_command  command;
        
    init_viper_log();
    
    /*  viper is forked from the application    */
    
    viper_log("Launching");

	/*  init the shared memory and semaphores for
		communication with the osek application executable  */
	init_com();
    
    /*  init motors */
    init_motors();
    
    do {
        read_command(&command);
        exec_command(&command);
    } while (command.command != PWROF);

    close_motors();
    
	close_com();
    
    viper_log("Leaving");
    
    close_viper_log();
    return 0;
}
