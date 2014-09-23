/* $Id: md5.c,v 1.3 2006-05-01 16:57:31 quentin Exp $ */

/*
 * Implementation of the md5 algorithm as described in RFC1321
 * Copyright (C) 2005 Quentin Carbonneaux <crazyjoke@free.fr>
 * 
 * This file is part of md5sum.
 *
 * md5sum is a free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Softawre Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * md5sum is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should hav received a copy of the GNU General Public License
 * along with md5sum; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "utilities/md5.h"

#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21


#define memcopy(a,b,c) md5_memcopy ((a), (b), (c))
#define memset(a,b,c) md5_memset ((a), (b), (c))

#define GET_UINT32(a,b,i)        \
{              \
  (a) = ( (unsigned int) (b)[(i)  ]      )  \
      | ( (unsigned int) (b)[(i)+1] << 8 )  \
      | ( (unsigned int) (b)[(i)+2] << 16)  \
      | ( (unsigned int) (b)[(i)+3] << 24);  \
}

/* local functions */
static void md5_memcopy (unsigned char *, unsigned char *, const unsigned int);
static void md5_memset (unsigned char *, const unsigned char, const unsigned int);
static void md5_addsize (unsigned char *, md5_size , md5_size);
static void md5_encode (unsigned char *, struct md5_ctx *);

static unsigned char MD5_PADDING [64] = { /* 512 Bits */
  0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/*
 * An easy way to do the md5 sum of a short memory space
 */
unsigned char *md5 (unsigned char *M, md5_size len, unsigned char *_digest)
{
  md5_size buflen = (len > MD5_BUFFER) ? MD5_BUFFER: len;
  struct md5_ctx *context;

  context = (md5_ctx *) malloc (sizeof (struct md5_ctx));
  context->buf = (unsigned char *) malloc (buflen);
  context->size = 0;
  context->bits = 0;

  /* Init registries */
  context->regs.A = 0x67452301;
  context->regs.B = 0xefcdab89;
  context->regs.C = 0x98badcfe;
  context->regs.D = 0x10325476;
  
  do {
    memcopy (context->buf + context->size, M + context->bits, buflen - context->size);
    context->size += buflen - context->size;
    md5_update (context);
  } while (len - context->bits > 64);
  
  md5_final (_digest, context);

        free (context->buf);
  free (context);

  return _digest;
}

void md5_init (struct md5_ctx *context)
{
  context->buf = (unsigned char *) malloc (MD5_BUFFER);
  memset (context->buf, '\0', MD5_BUFFER);
  context->size = 0;
  context->bits = 0;
  
  /* Init registries */
  context->regs.A = 0x67452301;
  context->regs.B = 0xefcdab89;
  context->regs.C = 0x98badcfe;
  context->regs.D = 0x10325476;
}
  
/* md5_size is bytes while the size at the end of the message is in bits ... */
static void md5_addsize (unsigned char *M, md5_size index, md5_size oldlen)
{
  assert (((index * 8) % 512) == 448); /* If padding is not done then exit */

  M[index++] = (unsigned char) ((oldlen << 3) & 0xFF);
  M[index++] = (unsigned char) ((oldlen >> 5) & 0xFF);
  M[index++] = (unsigned char) ((oldlen >> 13) & 0xFF);
  M[index++] = (unsigned char) ((oldlen >> 21) & 0xFF);
  /* Fill with 0 because md5_size is 32 bits long */
  M[index++] = 0; M[index++] = 0;
  M[index++] = 0; M[index++] = 0;
}

/*
 * Update a context by concatenating a new block
 */
void md5_update (struct md5_ctx *context)
{
  unsigned char buffer [64]; /* 512 bits */
  unsigned int i ;
  for (i = 0; context->size - i > 63; i += 64) {
    memcopy (buffer, context->buf + i, 64);
    md5_encode (buffer, context);
    context->bits += 64;
  }
  memcopy (buffer, context->buf + i, context->size - i);
  memcopy (context->buf, buffer, context->size - i);
  context->size -= i;
}

void md5_final (unsigned char *digest, struct md5_ctx *context)
{
  unsigned char buffer [64]; /* 512 bits */
  int i;

  assert (context->size < 64);
  
  if (context->size + 1 > 56) { /* We have to create another block */
    memcopy (buffer, context->buf, context->size);
    memcopy (buffer + context->size, MD5_PADDING, 64 - context->size);
    md5_encode (buffer, context);
    context->bits += context->size;
    context->size = 0;
    /* Proceed final block */
    memset (buffer, '\0', 56);
    /*memcopy (buffer, MD5_PADDING + 1, 56);*/
    md5_addsize (buffer, 56, context->bits);
    md5_encode (buffer, context);
  } else {
    memcopy (buffer, context->buf, context->size);
    context->bits += context->size;

    memcopy (buffer + context->size, MD5_PADDING, 56 - context->size);
    md5_addsize (buffer, 56, context->bits);
    md5_encode (buffer, context);
  }
  /* update digest */
  for (i = 0; i < 4; i++)
    digest [i] = (unsigned char) ((context->regs.A >> (i*8)) & 0xFF);
  for (; i < 8; i++)
    digest [i] = (unsigned char) ((context->regs.B >> ((i-4)*8)) & 0xFF);
  for (; i < 12; i++)
    digest [i] = (unsigned char) ((context->regs.C >> ((i-8)*8)) & 0xFF);
  for (; i < 16; i++)
    digest [i] = (unsigned char) ((context->regs.D >> ((i-12)*8)) & 0xFF);
}

static void md5_encode (unsigned char *buffer, struct md5_ctx *context)
{
  unsigned int a = context->regs.A, b = context->regs.B, c = context->regs.C, d = context->regs.D;
  unsigned int x[16];
  
  GET_UINT32 (x[ 0],buffer, 0);
  GET_UINT32 (x[ 1],buffer, 4);
  GET_UINT32 (x[ 2],buffer, 8);
  GET_UINT32 (x[ 3],buffer,12);
  GET_UINT32 (x[ 4],buffer,16);
  GET_UINT32 (x[ 5],buffer,20);
  GET_UINT32 (x[ 6],buffer,24);
  GET_UINT32 (x[ 7],buffer,28);
  GET_UINT32 (x[ 8],buffer,32);
  GET_UINT32 (x[ 9],buffer,36);
  GET_UINT32 (x[10],buffer,40);
  GET_UINT32 (x[11],buffer,44);
  GET_UINT32 (x[12],buffer,48);
  GET_UINT32 (x[13],buffer,52);
  GET_UINT32 (x[14],buffer,56);
  GET_UINT32 (x[15],buffer,60);

  /* Round 1 */
  FF (a, b, c, d, x[ 0], S11, 0xd76aa478); /* 1 */
  FF (d, a, b, c, x[ 1], S12, 0xe8c7b756); /* 2 */
  FF (c, d, a, b, x[ 2], S13, 0x242070db); /* 3 */
  FF (b, c, d, a, x[ 3], S14, 0xc1bdceee); /* 4 */
  FF (a, b, c, d, x[ 4], S11, 0xf57c0faf); /* 5 */
  FF (d, a, b, c, x[ 5], S12, 0x4787c62a); /* 6 */
  FF (c, d, a, b, x[ 6], S13, 0xa8304613); /* 7 */
  FF (b, c, d, a, x[ 7], S14, 0xfd469501); /* 8 */
  FF (a, b, c, d, x[ 8], S11, 0x698098d8); /* 9 */
  FF (d, a, b, c, x[ 9], S12, 0x8b44f7af); /* 10 */
  FF (c, d, a, b, x[10], S13, 0xffff5bb1); /* 11 */
  FF (b, c, d, a, x[11], S14, 0x895cd7be); /* 12 */
  FF (a, b, c, d, x[12], S11, 0x6b901122); /* 13 */
  FF (d, a, b, c, x[13], S12, 0xfd987193); /* 14 */
  FF (c, d, a, b, x[14], S13, 0xa679438e); /* 15 */
  FF (b, c, d, a, x[15], S14, 0x49b40821); /* 16 */

  /* Round 2 */
  GG (a, b, c, d, x[ 1], S21, 0xf61e2562); /* 17 */
  GG (d, a, b, c, x[ 6], S22, 0xc040b340); /* 18 */
  GG (c, d, a, b, x[11], S23, 0x265e5a51); /* 19 */
  GG (b, c, d, a, x[ 0], S24, 0xe9b6c7aa); /* 20 */
  GG (a, b, c, d, x[ 5], S21, 0xd62f105d); /* 21 */
  GG (d, a, b, c, x[10], S22,  0x2441453); /* 22 */
  GG (c, d, a, b, x[15], S23, 0xd8a1e681); /* 23 */
  GG (b, c, d, a, x[ 4], S24, 0xe7d3fbc8); /* 24 */
  GG (a, b, c, d, x[ 9], S21, 0x21e1cde6); /* 25 */
  GG (d, a, b, c, x[14], S22, 0xc33707d6); /* 26 */
  GG (c, d, a, b, x[ 3], S23, 0xf4d50d87); /* 27 */

  GG (b, c, d, a, x[ 8], S24, 0x455a14ed); /* 28 */
  GG (a, b, c, d, x[13], S21, 0xa9e3e905); /* 29 */
  GG (d, a, b, c, x[ 2], S22, 0xfcefa3f8); /* 30 */
  GG (c, d, a, b, x[ 7], S23, 0x676f02d9); /* 31 */
  GG (b, c, d, a, x[12], S24, 0x8d2a4c8a); /* 32 */

  /* Round 3 */
  HH (a, b, c, d, x[ 5], S31, 0xfffa3942); /* 33 */
  HH (d, a, b, c, x[ 8], S32, 0x8771f681); /* 34 */
  HH (c, d, a, b, x[11], S33, 0x6d9d6122); /* 35 */
  HH (b, c, d, a, x[14], S34, 0xfde5380c); /* 36 */
  HH (a, b, c, d, x[ 1], S31, 0xa4beea44); /* 37 */
  HH (d, a, b, c, x[ 4], S32, 0x4bdecfa9); /* 38 */
  HH (c, d, a, b, x[ 7], S33, 0xf6bb4b60); /* 39 */
  HH (b, c, d, a, x[10], S34, 0xbebfbc70); /* 40 */
  HH (a, b, c, d, x[13], S31, 0x289b7ec6); /* 41 */
  HH (d, a, b, c, x[ 0], S32, 0xeaa127fa); /* 42 */
  HH (c, d, a, b, x[ 3], S33, 0xd4ef3085); /* 43 */
  HH (b, c, d, a, x[ 6], S34,  0x4881d05); /* 44 */
  HH (a, b, c, d, x[ 9], S31, 0xd9d4d039); /* 45 */
  HH (d, a, b, c, x[12], S32, 0xe6db99e5); /* 46 */
  HH (c, d, a, b, x[15], S33, 0x1fa27cf8); /* 47 */
  HH (b, c, d, a, x[ 2], S34, 0xc4ac5665); /* 48 */

  /* Round 4 */
  II (a, b, c, d, x[ 0], S41, 0xf4292244); /* 49 */
  II (d, a, b, c, x[ 7], S42, 0x432aff97); /* 50 */
  II (c, d, a, b, x[14], S43, 0xab9423a7); /* 51 */
  II (b, c, d, a, x[ 5], S44, 0xfc93a039); /* 52 */
  II (a, b, c, d, x[12], S41, 0x655b59c3); /* 53 */
  II (d, a, b, c, x[ 3], S42, 0x8f0ccc92); /* 54 */
  II (c, d, a, b, x[10], S43, 0xffeff47d); /* 55 */
  II (b, c, d, a, x[ 1], S44, 0x85845dd1); /* 56 */
  II (a, b, c, d, x[ 8], S41, 0x6fa87e4f); /* 57 */
  II (d, a, b, c, x[15], S42, 0xfe2ce6e0); /* 58 */
  II (c, d, a, b, x[ 6], S43, 0xa3014314); /* 59 */
  II (b, c, d, a, x[13], S44, 0x4e0811a1); /* 60 */
  II (a, b, c, d, x[ 4], S41, 0xf7537e82); /* 61 */
  II (d, a, b, c, x[11], S42, 0xbd3af235); /* 62 */
  II (c, d, a, b, x[ 2], S43, 0x2ad7d2bb); /* 63 */
  II (b, c, d, a, x[ 9], S44, 0xeb86d391); /* 64 */

  context->regs.A += a;
  context->regs.B += b;
  context->regs.C += c;
  context->regs.D += d;
}

/* OBSOLETE */
static void md5_memcopy (unsigned char *dest, unsigned char *src, unsigned int count)
{
  unsigned int i;
  
  for (i = 0; i < count; i++) {
    dest [i] = src [i];
  }
}

static void md5_memset (unsigned char *p, const unsigned char c, const unsigned int count)
{
  unsigned int i;

  for (i = 0; i < count; i++) {
    p [i] = c;
  }
}
