#ifndef SERIAL_H
#define SERIAL_H

#include "Compiler.h"

extern FUNC(void, OS_CODE) serial_init(void);

extern FUNC(void, OS_CODE) serial_puts(CONSTP2CONST(char, AUTOMATIC, AUTOMATIC) string);

#endif /* SERIAL_H */
