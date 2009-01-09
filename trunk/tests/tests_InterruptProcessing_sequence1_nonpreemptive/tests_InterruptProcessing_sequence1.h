 /* 
  * @file tests_InterruptProcessing_sequence1.h
  * 
 * $Date: 2008/06/12 13:46:35 $
 * $Rev$
 * $Author: GuillaumeNuth $
 * $URL$
 */

#ifndef TESTS_INTERRUPTPROCESSING_SEQUENCE1_H_
#define TESTS_INTERRUPTPROCESSING_SEQUENCE1_H_

typedef struct __InterruptProcessing	InterruptProcessing;
typedef struct __InterruptProcessing*	InterruptProcessingRef;

/*struct which represent the object unless there is no real object*/
struct InterruptProcessing {
	int value;
};

/*allocate the object*/
InterruptProcessingRef InterruptProcessing_alloc(void);

/*desallocate the object*/
void InterruptProcessing_dealloc(InterruptProcessingRef);

/*reference to the suite of test created*/
TestRef InterruptProcessingTest_tests(void);

/*reference to the functions wich run the test*/
void test(void);

/*external definition of the function to the
 * redirection for the output of the test*/
void stdimpl_print(const char* string);

#endif /*TESTS_INTERRUPTPROCESSING_SEQUENCE1_H_*/
