 /**
  * @file TestPrint.c
  * 
  * $Date: 2008/05/20 13:26:19 $
  * $Rev$
  * $Author: GuillaumeNuth $
  * $URL$
  */

#include "embUnit.h"
#include "../../os/os_machine/ARM7/OKI/uart.h"
#include "TestPrint.h"

void stdimpl_print(const char* string){
	UART_envoyer_chaine((const char*)(string));
}
