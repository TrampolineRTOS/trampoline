#ifndef __INTERRUPT_H__
#define __INTERRUPT_H__

//interrupt registers (see MC9328MXL reference manual).
#define INTCNTL     (unsigned int *)0x00223000
#define NIMASK      (unsigned int *)0x00223004
#define INTENNUM    (unsigned int *)0x00223008
#define INTDISNUM   (unsigned int *)0x0022300C
#define INTENABLEH  (unsigned int *)0x00223010
#define INTENABLEL  (unsigned int *)0x00223014
#define INTTYPEH    (unsigned int *)0x00223018
#define INTTYPEL    (unsigned int *)0x0022301C
#define NIPRIORITY7 (unsigned int *)0x00223020
#define NIPRIORITY6 (unsigned int *)0x00223024
#define NIPRIORITY5 (unsigned int *)0x00223028
#define NIPRIORITY4 (unsigned int *)0x0022302C
#define NIPRIORITY3 (unsigned int *)0x00223030
#define NIPRIORITY2 (unsigned int *)0x00223034
#define NIPRIORITY1 (unsigned int *)0x00223038
#define NIPRIORITY0 (unsigned int *)0x0022303C
#define NIVECSR     (unsigned int *)0x00223040
#define FIVECSR     (unsigned int *)0x00223044
#define INTSRCH     (unsigned int *)0x00223048
#define INTSRCL     (unsigned int *)0x0022304C
#define INTFRCH     (unsigned int *)0x00223050
#define INTFRCL     (unsigned int *)0x00223054
#define NIPNDH      (unsigned int *)0x00223058
#define NIPNDL      (unsigned int *)0x0022305C
#define FIPNDH      (unsigned int *)0x00223060
#define FIPNDL      (unsigned int *)0x00223064

void initNormalInterrupt(const unsigned int sourceId,const unsigned int priority);
void initIT();
void forceInterrupt(const unsigned int sourceId);

#endif
