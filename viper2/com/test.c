#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tpl_com_ipdu.h"

int main(int args, char* argv[])
{
  tpl_sending_mo s_mo;
  tpl_sending_ipdu ipdu;
  tpl_receiving_mo r_mo;
  int i;

  s_mo.data[0]        = (char) 100;
  s_mo.data[1]        = (char) 205;
  s_mo.data[2]        = (char) 12;
  s_mo.data[3]        = (char) 1;
  s_mo.byte_start     = 2;
  s_mo.bit_start      = 6;
  s_mo.byte_end       = 4;
  s_mo.bit_end        = 3;
  ipdu.nb_message   = 8;

#ifdef DEBUG
  printf("\nMessage object datas :\n");
  printf("-------------------------------------------------------\n");
  printf("Field %d\t\tField %d\t\tField %d\t\tField %d\n", 0, 1, 2 ,3);
  printf("-------------------------------------------------------\n");
  printf("%d\t\t%d\t\t%d\t\t%d\n", s_mo.data[0], s_mo.data[1], s_mo.data[2], s_mo.data[3]);
  printf("-------------------------------------------------------\n");
#endif
  ipdu.buf = calloc(ipdu.nb_message, sizeof(u8));

  tpl_put_message_object_in_ipdu(&ipdu, &s_mo);

#ifdef DEBUG
  printf("\nDelete mo's datas...\n");
#endif
  s_mo.data[0]        = (char) 0;
  s_mo.data[1]        = (char) 0;
  s_mo.data[2]        = (char) 0;
  s_mo.data[3]        = (char) 0;
  r_mo.mo             = s_mo;   

#ifdef DEBUG
  printf("\nTry to get the mo from the I-PDU...\n");
#endif
  tpl_get_message_object_from_ipdu(&ipdu, &r_mo);

  return 0;
}

