/*
 *  com.h
 *  viper
 *
 *  Created by Jean-Luc Bechennec on Mon May 02 2005.
 *  Copyright (c) 2005 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __COM_H__
#define __COM_H__

#include "viper.h"

void init_com(void);
void close_com(void);
void read_command(vp_command *);

#endif
