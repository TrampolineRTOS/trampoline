#ifndef APP_RS232_DRIVER_H
#define APP_RS232_DRIVER_H

FUNC(void, OS_APPL_CODE) tf_rs232_print_hex (int this_number);

/**
 * wrapper for rs232_print trusted function
 */
FUNC(void, OS_APPL_CODE) tf_rs232_print (char *this_string);

#endif /* APP_RS232_DRIVER_H */
