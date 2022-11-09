/**
 * \file main.c
 *
 * Adapted from:
 * https://github.com/tinysystems/ImmortalThreads/tree/main/runtime/test/benchmarks/bc/main.c
 */

#include "msp430.h"
#include "tpl_os.h"
#include <stdint.h>

#define SEED 4L
#define ITER 100
#define CHAR_BIT 8

#define APP_COMMON_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void){
    P1DIR |= BIT0 + BIT1;
    P1OUT &= ~(BIT0 + BIT1);

    // tpl_serial_begin(SERIAL_TX_MODE_BLOCK);

    // Disable the GPIO power-on default high-impedance mode
    // to activate previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

#define APP_COMMON_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_bc_main_START_SEC_CODE
#include "tpl_memmap.h"

static char bits[256] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, /* 0   - 15  */
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, /* 16  - 31  */
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, /* 32  - 47  */
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, /* 48  - 63  */
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, /* 64  - 79  */
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, /* 80  - 95  */
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, /* 96  - 111 */
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, /* 112 - 127 */
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, /* 128 - 143 */
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, /* 144 - 159 */
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, /* 160 - 175 */
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, /* 176 - 191 */
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, /* 192 - 207 */
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, /* 208 - 223 */
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, /* 224 - 239 */
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8  /* 240 - 255 */
};

int btbl_bitcnt(uint32_t x) {
  int cnt = bits[((char *)&x)[0] & 0xFF];

  if (0L != (x >>= 8))
    cnt += btbl_bitcnt(x);
  return cnt;
}

int bit_count(uint32_t x) {
  int n = 0;

  if (x)
    do
      n++;
    while (0 != (x = x & (x - 1)));
  return (n);
}

int bitcount(uint32_t i) {
  i = ((i & 0xAAAAAAAAL) >> 1) + (i & 0x55555555L);
  i = ((i & 0xCCCCCCCCL) >> 2) + (i & 0x33333333L);
  i = ((i & 0xF0F0F0F0L) >> 4) + (i & 0x0F0F0F0FL);
  i = ((i & 0xFF00FF00L) >> 8) + (i & 0x00FF00FFL);
  i = ((i & 0xFFFF0000L) >> 16) + (i & 0x0000FFFFL);
  return (int)i;
}

int ntbl_bitcount(uint32_t x) {
  return bits[(int)(x & 0x0000000FUL)] + bits[(int)((x & 0x000000F0UL) >> 4)] +
         bits[(int)((x & 0x00000F00UL) >> 8)] +
         bits[(int)((x & 0x0000F000UL) >> 12)] +
         bits[(int)((x & 0x000F0000UL) >> 16)] +
         bits[(int)((x & 0x00F00000UL) >> 20)] +
         bits[(int)((x & 0x0F000000UL) >> 24)] +
         bits[(int)((x & 0xF0000000UL) >> 28)];
}

int BW_btbl_bitcount(uint32_t x) {
  union {
    unsigned char ch[4];
    long y;
  } U;

  U.y = x;

  return bits[U.ch[0]] + bits[U.ch[1]] + bits[U.ch[3]] + bits[U.ch[2]];
}

int AR_btbl_bitcount(uint32_t x) {
  unsigned char *Ptr = (unsigned char *)&x;
  int Accu;

  Accu = bits[*Ptr++];
  Accu += bits[*Ptr++];
  Accu += bits[*Ptr++];
  Accu += bits[*Ptr];

  return Accu;
}

int ntbl_bitcnt(uint32_t x) {
  int cnt = bits[(int)(x & 0x0000000FL)];

  if (0L != (x >>= 4))
    cnt += ntbl_bitcnt(x);

  return cnt;
}

static int bit_shifter(uint32_t x) {
  int i, n;
  for (i = n = 0; x && (i < (sizeof(uint32_t) * CHAR_BIT)); ++i, x >>= 1)
    n += (int)(x & 1L);
  return n;
}

TASK(bc_main){
  unsigned n_0, n_1, n_2, n_3, n_4, n_5, n_6;
  uint32_t seed;
  unsigned iter;
  unsigned func;
  while (1) {
    n_0 = 0;
    n_1 = 0;
    n_2 = 0;
    n_3 = 0;
    n_4 = 0;
    n_5 = 0;
    n_6 = 0;

    for (func = 0; func < 7; func++) {

      seed = (uint32_t)SEED;
      if (func == 0) {
        for (iter = 0; iter < ITER; ++iter, seed += 13) {
          n_0 += bit_count(seed);
        }
      } else if (func == 1) {
        for (iter = 0; iter < ITER; ++iter, seed += 13) {
          n_1 += bitcount(seed);
        }
      } else if (func == 2) {
        for (iter = 0; iter < ITER; ++iter, seed += 13) {
          n_2 += ntbl_bitcnt(seed);
        }
      } else if (func == 3) {
        for (iter = 0; iter < ITER; ++iter, seed += 13) {
          n_3 += ntbl_bitcount(seed);
        }
      } else if (func == 4) {
        for (iter = 0; iter < ITER; ++iter, seed += 13) {
          n_4 += BW_btbl_bitcount(seed);
        }
      } else if (func == 5) {
        for (iter = 0; iter < ITER; ++iter, seed += 13) {
          n_5 += AR_btbl_bitcount(seed);
        }
      } else if (func == 6) {
        for (iter = 0; iter < ITER; ++iter, seed += 13) {
          n_6 += bit_shifter(seed);
        }
      }
    }

    if (n_0 == 502 && n_1 == 502 && n_2 == 502 && n_3 == 502 && n_4 == 502 &&
        n_5 == 502 && n_6 == 502) {
#ifdef __MSP430__
#if defined(PORT_CONTROL)
      P3OUT ^= 0x02;
      P3OUT ^= 0x02;
#else
	P1OUT = 0x02;
	_BIC_SR(GIE);
	while(1);
#endif
#endif
    } else {
#ifdef __MSP430__
#if defined(PORT_CONTROL)
      P3OUT ^= 0x02;
      P3OUT ^= 0x02;
#else
	P1OUT = 0x01;
	_BIC_SR(GIE);
	while(1);
#endif
#endif
    }
  }
  TerminateTask();
}
#define APP_Task_bc_main_STOP_SEC_CODE
#include "tpl_memmap.h"