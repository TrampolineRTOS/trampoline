#include <stdlib.h>
#include <stdio.h>

#include "tpl_com_ipdu.h"

/*====================
 *  transfert
 *====================*/

/**
 *  send an ipdu
 *
 *  @param  ipdu  ipdu to send
 */
void tpl_send_ipdu(ipc_t *ipc, tpl_sending_ipdu *ipdu) {
  send_ipdu(ipc, ipdu);
}

/**
 *  recive an ipdu
 *
 *  @param  ipdu  ipdu target
 *  @return       receive ipdu  
 */
void tpl_receive_ipdu(ipc_t *ipc, tpl_receiving_ipdu *ipdu) {
  receive_ipdu(ipc, ipdu);
}

/*====================
 *  data
 *====================*/

typedef struct data_modification_st {
  int ipdu_s_byte; /*  index of the byte to modify in the ipdu                     */
  int bit_start;   /*  index of the bit start in the byte to modify                */
  int bit_end;     /*  index of the bit end in the byte to modify                  */
  int mo_s_byte;   /*  index of the byte of the message object to copy in the ipdu */
}
data_modification_t;

/**
 *  fill a copy data struct array
 *
 *  @param  copy_data_struct    copy data struct array to fill
 *  @param  nb_iteration        maximum number of iteration to do to fill the struct
 *  @param  mo                  message object
 *  @return size_of_copy_data   size of the copy data struct array
 */
int fill_copy_data_struct_array(data_modification_t data_modification[], int nb_iteration, tpl_sending_mo *mo)
{
  /* variables */
  int current_byte = mo->byte_start;
  int current_bit_start = mo->bit_start;
  int data_modification_size = 1;
  int i;

  /* fill the copy data struct */
  for(i = 0; i < nb_iteration; i++) {
    /* take the index of the byte to modify in the I-PDU */
    data_modification[i].ipdu_s_byte = current_byte;
    /* take the index of the bit start in the byte to modify */
    data_modification[i].bit_start = current_bit_start;
    /* take the index of the bit end of the byte to modify */
    if(current_byte != mo->byte_end) {
      if(i == 0) {
        data_modification[i].bit_end = 7;
      }
      else {
        if(data_modification[(i - 1)].bit_end != 7) {
          if(data_modification[(i - 1)].bit_start != 0) {
            data_modification[i].bit_end = data_modification[(i - 1)].bit_start - 1;
          }
          else {
            data_modification[i].bit_end = 7;
          }
        }
        else {
          if(data_modification[(i - 1)].bit_start != 0) {
            data_modification[i].bit_end = data_modification[(i - 1)].bit_start - 1;
          }
        }
      }
    }
    else {
      if( i == 0) {
        data_modification[i].bit_end = mo->bit_end;
      }
      else {
        if(data_modification[(i - 1)].bit_start == 0) {
          data_modification[i].bit_end = mo->bit_end;
        }
        else {
          data_modification[i].bit_end = data_modification[(i - 1)].bit_start - 1;
        }
      }
      if(data_modification[i].bit_end > mo->bit_end) {
        data_modification[i].bit_end = mo->bit_end;
      }
    }
    if(data_modification[i].bit_end > 7) {
      data_modification[i].bit_end = 7;
    }
    /* take the index of the byte of the message object to copy */
    if(i == 0) {
      data_modification[i].mo_s_byte = i;
    }
    else {
      if( data_modification[(i - 1)].bit_start != 0 &&
          data_modification[(i - 1)].bit_end == 7   ) {
        data_modification[i].mo_s_byte = data_modification[(i - 1)].mo_s_byte;
      }
      else {
        data_modification[i].mo_s_byte = data_modification[(i - 1)].mo_s_byte + 1;
      }
    }
    /* increment the current variables */
    if(current_byte != mo->byte_end) {
      if(data_modification[i].bit_end == 7) {
        current_byte++;
        current_bit_start = 0;
      }
      else {
        current_bit_start = data_modification[i].bit_end + 1;
      }
    }
    else {
      if(data_modification[i].bit_end != mo->bit_end) {
        current_bit_start = data_modification[i].bit_end + 1;
      }
    }
    if(current_bit_start > 7) {
      current_bit_start -= 8;
    }
    /* take the size of the array */
    if( current_byte == mo->byte_end                &&
        data_modification[i].bit_end == mo->bit_end &&
        data_modification_size == 1                 ) {
      data_modification_size += i;
    }
  }

#ifdef DEBUG
  /* display the copy data struct array */
  printf("\nDetail of copy step array :\n");
  printf("-----------------------------------------------------------------------------------------\n");
  printf("I-PDU's byte\t\tI-PDU's bit start\t\tI-PDU's bit end\t\tMo's byte\n");
  printf("-----------------------------------------------------------------------------------------\n");
  for(i = 0; i < data_modification_size; i++) {
    printf("%d\t\t\t%d\t\t\t\t%d\t\t\t%d\n", data_modification[i].ipdu_s_byte, data_modification[i].bit_start, data_modification[i].bit_end, data_modification[i].mo_s_byte);
    printf("-----------------------------------------------------------------------------------------\n");
  }
#endif

  return data_modification_size;
}

/**
 *  put a message object in an ipdu
 *
 *  @param  mo    message object to put in an ipdu
 *  @param  ipdu  ipdu where put a message object
 *  @return       modified ipdu
 */
void tpl_put_message_object_in_ipdu(tpl_sending_ipdu *ipdu, tpl_sending_mo *mo)
{
  /* variables */
  int nb_iteration = (mo->byte_end - mo->byte_start + 1) * 2;
  data_modification_t data_modification[nb_iteration];
  int data_modification_size;
  int mask;
  int i;

  /* fill the copy data struct array */
  data_modification_size = fill_copy_data_struct_array(data_modification, nb_iteration, mo);

#ifdef DEBUG
  printf("\nDetail of copy step :\n");
  printf("---------------------------------------------------------------------------------------------\n");
  printf("Mask value\t\tI-PDU's byte index\t\tI-PDU's byte value after copying data\n");
  printf("---------------------------------------------------------------------------------------------\n");
#endif
  /* browse the array and copy data in the I-PDU */
  for(i = 0; i < data_modification_size; i++) {
    mask = ((1 << 8) - 1) - (((1 << (data_modification[i].bit_end + 1)) - 1) - ((1 << data_modification[i].bit_start) - 1));
    ipdu->buf[data_modification[i].ipdu_s_byte] &= mask;
    /* first iteration, take the begining (may be the entire) of the byte to copy */
    if(i == 0) {
      mask = ((1 << (data_modification[i].bit_end + 1)) - 1);
      ipdu->buf[data_modification[i].ipdu_s_byte] |= ((mo->data[data_modification[i].mo_s_byte] << data_modification[i].bit_start) & mask);
    }
    else {
      /* if the byte to copy was already used, take the end of it */
      if(data_modification[i].mo_s_byte == data_modification[(i - 1)].mo_s_byte) {
        if( data_modification[i].ipdu_s_byte == mo->byte_end  &&
            data_modification[i].bit_end == mo->bit_end       ) {
          mask = ((1 << (data_modification[i].bit_end + 1)) - 1);
          ipdu->buf[data_modification[i].ipdu_s_byte] |= ((mo->data[data_modification[i].mo_s_byte] >> (data_modification[(i - 1)].bit_end - data_modification[(i - 1)].bit_start + 1)) & mask);
        }
        else {
          ipdu->buf[data_modification[i].ipdu_s_byte] |= (mo->data[data_modification[i].mo_s_byte] >> (data_modification[(i - 1)].bit_end - data_modification[(i - 1)].bit_start + 1));
        }
      }
      /* else, take the begining (may be the entire) of the byte to copy */
      else {
        mask = ((1 << (data_modification[i].bit_end + 1)) - 1);
        ipdu->buf[data_modification[i].ipdu_s_byte] |= ((mo->data[data_modification[i].mo_s_byte] << data_modification[i].bit_start) & mask);
      }
    }
#ifdef DEBUG
    printf("%d\t\t\t%d\t\t\t\t%d\n", mask, data_modification[i].ipdu_s_byte, ipdu->buf[data_modification[i].ipdu_s_byte]);
    printf("---------------------------------------------------------------------------------------------\n");
#endif
  }
}

/**
 *  get a message object from an ipdu
 *  
 *  @param  ipdu  ipdu to extract the message object
 *  @param  mo    extract message object
 *  @return       extract message object
 */
void tpl_get_message_object_from_ipdu(tpl_receiving_ipdu *ipdu, tpl_receiving_mo *r_mo) {
  /* variables */
  tpl_sending_mo *mo = &r_mo->mo;
  int nb_iteration = (mo->byte_end - mo->byte_start + 1) * 2;
  data_modification_t data_modification[nb_iteration];
  int data_modification_size;
  int mask;
  int i;

  /* fill the copy data struct array */
  data_modification_size = fill_copy_data_struct_array(data_modification, nb_iteration, mo);

  /* Delete the previous mo's datas */
  for(i = 0; i < 4; i++) {
    mo->data[i] = (char) 0;
  }

#ifdef DEBUG
  printf("\nDetail of copy step :\n");
  printf("----------------------------------------------------------------------------------\n");
  printf("Mask value\t\tMo's byte ndex\t\tMo's byte value after copying data\n");
  printf("----------------------------------------------------------------------------------\n");
#endif
  /* browse the array and copy data in the I-PDU */
  for(i = 0; i < data_modification_size; i++) {
    /* first iteration, take the begining (may be the entire) of the byte to copy */
    if(i == 0) {
      mask = 0;
      mo->data[data_modification[i].mo_s_byte] &= mask;
      mask = ((1 << (data_modification[i].bit_end - data_modification[i].bit_start + 1)) - 1);
      mo->data[data_modification[i].mo_s_byte] |= ((ipdu->buf[data_modification[i].ipdu_s_byte] >> data_modification[i].bit_start) & mask);
    }
    else {
      if(data_modification[i].mo_s_byte == data_modification[(i - 1)].mo_s_byte) {
        mask = (1 << (data_modification[(i - 1)].bit_end - data_modification[(i - 1)].bit_start + 1)) - 1;
      }
      else {
        mask = 0;
      }
      mo->data[data_modification[i].mo_s_byte] &= mask;
      /* if the byte to copy was already used, take the end of it */
      if(data_modification[i].mo_s_byte == data_modification[(i - 1)].mo_s_byte) {
        mo->data[data_modification[i].mo_s_byte] |= ipdu->buf[data_modification[i].ipdu_s_byte] << (8 - data_modification[(i - 1)].bit_start);
      }
      /* else, take the begining (may be the entire) of the byte to copy */
      else {
        mask = ((1 << (data_modification[i].bit_end - data_modification[i].bit_start + 1)) - 1);
        mo->data[data_modification[i].mo_s_byte] |= ((ipdu->buf[data_modification[i].ipdu_s_byte] >> data_modification[i].bit_start) & mask);
      }
    }
#ifdef DEBUG
    printf("%d\t\t\t%d\t\t\t%d\n", mask, data_modification[i].mo_s_byte, mo->data[data_modification[i].mo_s_byte]);
    printf("----------------------------------------------------------------------------------\n");
#endif
  }

  r_mo->mo = *mo;
}

