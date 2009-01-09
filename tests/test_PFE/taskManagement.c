 /* 
  * @file taskManagement.c
  * 
  * $Date: 2008/01/17 08:47:19 $
 * $Rev$
 * $Author: LaurentMenard $
 * $URL$
 */

#include "taskManagement.h"

TaskManagementRef taskManagement_alloc(void)
{
	TaskManagementRef t_ref;
	return t_ref;
}

void taskManagement_dealloc(TaskManagementRef self)
{
	/*free(self);*/
}

