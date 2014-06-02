/*
 *  log.c
 *  viper
 *
 *  Created by Jean-Luc Bechennec on Tue May 31 2005.
 *  Copyright (c) 2005 __MyCompanyName__. All rights reserved.
 *
 */

#include "log.h"
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/wait.h>

#define LOG_FILE_PATH "/tmp/viper%d.log"

static char log_file_path[32];
static FILE *log_file;


void init_viper_log(void)
{
    /*  open the log file   */
    sprintf(log_file_path, LOG_FILE_PATH, getppid());
    log_file = fopen(log_file_path,"w");
}

void close_viper_log(void)
{
    fclose(log_file);
}

void viper_log(const char *msg)
{
    time_t stamp_t = time(NULL);
    char *stamp = ctime(&stamp_t);
    char *ret = strchr(stamp,'\n');
    *ret = '\0';
    
    fprintf(log_file,"[%s] %s\n",stamp,msg);
    fflush(log_file);
    
}
