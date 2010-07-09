/*
 *  cplusplus.cpp
 *  
 *
 *  Created by Jean-Luc Béchennec on 09/07/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "tpl_os.h"
#include <stdio.h>

int main()
{
  StartOS(0);
  return 0;
}

TASK(periodic)
{
  static int i = 1;
  printf("Hello %d\n",i);
  i++;
  TerminateTask();
}