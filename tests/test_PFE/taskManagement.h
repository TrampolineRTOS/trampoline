 /* 
  * @file taskManagement.h
  * 
  * $Date: 2008/01/17 08:47:19 $
 * $Rev$
 * $Author: LaurentMenard $
 * $URL$
 */

#ifndef TASKMANAGEMENT_H_
#define TASKMANAGEMENT_H_

typedef struct __TaskManagement	TaskManagement;
typedef struct __TaskManagement*	TaskManagementRef;

/*struct which represent the object unless there is no real object*/
struct TaskManagement {
	int value;
};

/*allocate the object*/
TaskManagementRef taskManagement_alloc(void);
/*desallocate the object*/
void taskManagement_dealloc(TaskManagementRef);


#endif /*TASKMANAGEMENT_H_*/
