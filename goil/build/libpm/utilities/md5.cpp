/*
 * This is an OpenSSL-compatible implementation of the RSA Data Security, Inc.
 * MD5 Message-Digest Algorithm (RFC 1321).
 *
 * Homepage:
 * http://openwall.info/wiki/people/solar/software/public-domain-source-code/md5
 *
 * Author:
 * Alexander Peslyak, better known as Solar Designer <solar at openwall.com>
 *
 * This software was written by Alexander Peslyak in 2001.  No copyright is
 * claimed, and the software is hereby placed in the public domain.
 * In case this attempt to disclaim copyright and place the software in the
 * public domain is deemed null and void, then the software is
 * Copyright (c) 2001 Alexander Peslyak and it is hereby released to the
 * general public under the following terms:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted.
 *
 * There's ABSOLUTELY NO WARRANTY, express or implied.
 *
 * (This is a heavily cut-down "BSD license".)
 *
 * This differs from Colin Plumb's older public domain implementation in that
 * no exactly 32-bit integer data type is required (any 32-bit or wider
 * unsigned integer data type will do), there's no compile-time endianness
 * configuration, and the function prototypes match OpenSSL's.  No code from
 * Colin Plumb's implementation has been reused; this comment merely compares
 * the properties of the two independent implementations.
 *
 * The primary goals of this implementation are portability and ease of use.
 * It is meant to be fast, but not as fast as possible.  Some known
 * optimizations are not included to reduce source code size and avoid
 * compile-time configuration.
 */
// Modified by Pierre Molinaro 7 february 2024
//-------------------------------------------------------------------------------------------------

#include <string.h>

//-------------------------------------------------------------------------------------------------

#include "md5.h"

//-------------------------------------------------------------------------------------------------

MD5pm::MD5pm (void) {
}

//-------------------------------------------------------------------------------------------------

void MD5pm::appendData (const void * inDataPtr, const size_t inByteCount) {
  size_t currentByteCount = inByteCount ;
  const uint8_t * currentDataPtr = (const uint8_t *) inDataPtr ;

	uint32_t saved_lo = mLo;
	if ((mLo = (saved_lo + currentByteCount) & 0x1fffffff) < saved_lo) {
		mHi++ ;
  }
  mHi += uint32_t (currentByteCount >> 29) ;

	uint32_t used = saved_lo & 0x3f ;

	if (used) {
		uint32_t available = 64 - used ;

		if (currentByteCount < available) {
			memcpy (&mBuffer[used], currentDataPtr, currentByteCount);
			return;
		}

		memcpy (&mBuffer[used], currentDataPtr, available);
		currentDataPtr += available ;
		currentByteCount -= available ;
		body(mBuffer, 64);
	}

	if (currentByteCount >= 64) {
		currentDataPtr = body (currentDataPtr, currentByteCount & ~(unsigned long)0x3f);
		currentByteCount &= 0x3f;
	}

	memcpy(mBuffer, currentDataPtr, currentByteCount);
}

//-------------------------------------------------------------------------------------------------
// The basic MD5 functions
//-------------------------------------------------------------------------------------------------

static uint32_t F (const uint32_t x, const uint32_t y, const uint32_t z) {
  return z ^ (x & (y ^ z)) ;
}

//-------------------------------------------------------------------------------------------------

static uint32_t G (const uint32_t x, const uint32_t y, const uint32_t z) {
  return y ^ (z & (x ^ y)) ;
}

//-------------------------------------------------------------------------------------------------

static uint32_t H (const uint32_t x, const uint32_t y, const uint32_t z) {
  return x ^ y ^ z ;
}

//-------------------------------------------------------------------------------------------------

static uint32_t I (const uint32_t x, const uint32_t y, const uint32_t z) {
  return y ^ (x | ~z) ;
}

//-------------------------------------------------------------------------------------------------

static uint32_t addU32IgnoringOverflow (const uint32_t inA, const uint32_t inB) {
  uint32_t r ;
  __builtin_add_overflow (inA, inB, &r) ;
  return r ;
}

//-------------------------------------------------------------------------------------------------

static uint32_t rotateLeftIgnoringOverflow (const uint32_t inA, const uint32_t inCount) {
  uint32_t r = inA ;
  if (inCount > 0) {
    r &= (1 << (32 - inCount)) - 1 ;
	  r = (r << inCount) | (inA >> (32 - inCount)) ;
  }
  return r ;
}

//-------------------------------------------------------------------------------------------------
// The MD5 transformation for all four rounds.
//-------------------------------------------------------------------------------------------------

static void STEP (uint32_t (*f) (const uint32_t, const uint32_t, const uint32_t),
                  uint32_t & a,
                  const uint32_t b,
                  const uint32_t c,
                  const uint32_t d,
                  uint32_t * block,
                  const uint32_t n,
                  const uint8_t * ptr,
                  const uint32_t t,
                  const uint32_t s) {
  block [n]  = uint32_t (ptr [n * 4 + 0] <<  0) ;
  block [n] |= uint32_t (ptr [n * 4 + 1] <<  8) ;
  block [n] |= uint32_t (ptr [n * 4 + 2] << 16) ;
  block [n] |= uint32_t (ptr [n * 4 + 3] << 24) ;
  a = addU32IgnoringOverflow (a, f (b, c, d)) ;
  a = addU32IgnoringOverflow (a, block [n]) ;
  a = addU32IgnoringOverflow (a, t) ;
  a = rotateLeftIgnoringOverflow (a, s) ;
	a = addU32IgnoringOverflow (a, b) ;
}

//-------------------------------------------------------------------------------------------------

static void STEP2 (uint32_t (*f) (const uint32_t, const uint32_t, const uint32_t),
                   uint32_t & a,
                   const uint32_t b,
                   const uint32_t c,
                   const uint32_t d,
                   const uint32_t x,
                   const uint32_t t,
                   const uint32_t s) {
  a = addU32IgnoringOverflow (a, f (b, c, d)) ;
  a = addU32IgnoringOverflow (a, x) ;
  a = addU32IgnoringOverflow (a, t) ;
	a = rotateLeftIgnoringOverflow (a, s) ;
	a = addU32IgnoringOverflow (a, b) ;
}

//-------------------------------------------------------------------------------------------------
// This processes one or more 64-byte data blocks, but does NOT update the bit
// counters.  There are no alignment requirements.
//-------------------------------------------------------------------------------------------------

const uint8_t * MD5pm::body (const uint8_t * inDataPtr, const size_t inByteLength) {
	const uint8_t * ptr = inDataPtr ;
  size_t currentByteLength = inByteLength ;

	do {
		const uint32_t saved_a = mA ;
		const uint32_t saved_b = mB;
		const uint32_t saved_c = mC;
		const uint32_t saved_d = mD;

/* Round 1 */
		STEP(F, mA, mB, mC, mD, mBlock, 0, ptr, 0xd76aa478, 7) ;
		STEP(F, mD, mA, mB, mC, mBlock, 1, ptr, 0xe8c7b756, 12) ;
		STEP(F, mC, mD, mA, mB, mBlock, 2, ptr, 0x242070db, 17) ;
		STEP(F, mB, mC, mD, mA, mBlock, 3, ptr, 0xc1bdceee, 22) ;
		STEP(F, mA, mB, mC, mD, mBlock, 4, ptr, 0xf57c0faf, 7) ;
		STEP(F, mD, mA, mB, mC, mBlock, 5, ptr, 0x4787c62a, 12) ;
		STEP(F, mC, mD, mA, mB, mBlock, 6, ptr, 0xa8304613, 17) ;
		STEP(F, mB, mC, mD, mA, mBlock, 7, ptr, 0xfd469501, 22) ;
		STEP(F, mA, mB, mC, mD, mBlock, 8, ptr, 0x698098d8, 7) ;
		STEP(F, mD, mA, mB, mC, mBlock, 9, ptr, 0x8b44f7af, 12) ;
		STEP(F, mC, mD, mA, mB, mBlock, 10, ptr, 0xffff5bb1, 17) ;
		STEP(F, mB, mC, mD, mA, mBlock, 11, ptr, 0x895cd7be, 22) ;
		STEP(F, mA, mB, mC, mD, mBlock, 12, ptr, 0x6b901122, 7) ;
		STEP(F, mD, mA, mB, mC, mBlock, 13, ptr, 0xfd987193, 12) ;
		STEP(F, mC, mD, mA, mB, mBlock, 14, ptr, 0xa679438e, 17) ;
		STEP(F, mB, mC, mD, mA, mBlock, 15, ptr, 0x49b40821, 22) ;

/* Round 2 */
		STEP2 (G, mA, mB, mC, mD, mBlock [1], 0xf61e2562, 5) ;
		STEP2 (G, mD, mA, mB, mC, mBlock [6], 0xc040b340, 9) ;
		STEP2 (G, mC, mD, mA, mB, mBlock [11], 0x265e5a51, 14) ;
		STEP2 (G, mB, mC, mD, mA, mBlock [0], 0xe9b6c7aa, 20) ;
		STEP2 (G, mA, mB, mC, mD, mBlock [5], 0xd62f105d, 5) ;
		STEP2 (G, mD, mA, mB, mC, mBlock [10], 0x02441453, 9) ;
		STEP2 (G, mC, mD, mA, mB, mBlock [15], 0xd8a1e681, 14) ;
		STEP2 (G, mB, mC, mD, mA, mBlock [4], 0xe7d3fbc8, 20) ;
		STEP2 (G, mA, mB, mC, mD, mBlock [9], 0x21e1cde6, 5) ;
		STEP2 (G, mD, mA, mB, mC, mBlock [14], 0xc33707d6, 9) ;
		STEP2 (G, mC, mD, mA, mB, mBlock [3], 0xf4d50d87, 14) ;
		STEP2 (G, mB, mC, mD, mA, mBlock [8], 0x455a14ed, 20) ;
		STEP2 (G, mA, mB, mC, mD, mBlock [13], 0xa9e3e905, 5) ;
		STEP2 (G, mD, mA, mB, mC, mBlock [2], 0xfcefa3f8, 9) ;
		STEP2 (G, mC, mD, mA, mB, mBlock [7], 0x676f02d9, 14) ;
		STEP2 (G, mB, mC, mD, mA, mBlock [12], 0x8d2a4c8a, 20) ;

/* Round 3 */
		STEP2 (H, mA, mB, mC, mD, mBlock [5], 0xfffa3942, 4) ;
		STEP2 (H, mD, mA, mB, mC, mBlock [8], 0x8771f681, 11) ;
		STEP2 (H, mC, mD, mA, mB, mBlock [11], 0x6d9d6122, 16) ;
		STEP2 (H, mB, mC, mD, mA, mBlock [14], 0xfde5380c, 23) ;
		STEP2 (H, mA, mB, mC, mD, mBlock [1], 0xa4beea44, 4) ;
		STEP2 (H, mD, mA, mB, mC, mBlock [4], 0x4bdecfa9, 11) ;
		STEP2 (H, mC, mD, mA, mB, mBlock [7], 0xf6bb4b60, 16) ;
		STEP2 (H, mB, mC, mD, mA, mBlock [10], 0xbebfbc70, 23) ;
		STEP2 (H, mA, mB, mC, mD, mBlock [13], 0x289b7ec6, 4) ;
		STEP2 (H, mD, mA, mB, mC, mBlock [0], 0xeaa127fa, 11) ;
		STEP2 (H, mC, mD, mA, mB, mBlock [3], 0xd4ef3085, 16) ;
		STEP2 (H, mB, mC, mD, mA, mBlock [6], 0x04881d05, 23) ;
		STEP2 (H, mA, mB, mC, mD, mBlock [9], 0xd9d4d039, 4) ;
		STEP2 (H, mD, mA, mB, mC, mBlock [12], 0xe6db99e5, 11) ;
		STEP2 (H, mC, mD, mA, mB, mBlock [15], 0x1fa27cf8, 16) ;
		STEP2 (H, mB, mC, mD, mA, mBlock [2], 0xc4ac5665, 23) ;

/* Round 4 */
		STEP2 (I, mA, mB, mC, mD, mBlock [0], 0xf4292244, 6) ;
		STEP2 (I, mD, mA, mB, mC, mBlock [7], 0x432aff97, 10) ;
		STEP2 (I, mC, mD, mA, mB, mBlock [14], 0xab9423a7, 15) ;
		STEP2 (I, mB, mC, mD, mA, mBlock [5], 0xfc93a039, 21) ;
		STEP2 (I, mA, mB, mC, mD, mBlock [12], 0x655b59c3, 6) ;
		STEP2 (I, mD, mA, mB, mC, mBlock [3], 0x8f0ccc92, 10) ;
		STEP2 (I, mC, mD, mA, mB, mBlock [10], 0xffeff47d, 15) ;
		STEP2 (I, mB, mC, mD, mA, mBlock [1], 0x85845dd1, 21) ;
		STEP2 (I, mA, mB, mC, mD, mBlock [8], 0x6fa87e4f, 6) ;
		STEP2 (I, mD, mA, mB, mC, mBlock [15], 0xfe2ce6e0, 10) ;
		STEP2 (I, mC, mD, mA, mB, mBlock [6], 0xa3014314, 15) ;
		STEP2 (I, mB, mC, mD, mA, mBlock [13], 0x4e0811a1, 21) ;
		STEP2 (I, mA, mB, mC, mD, mBlock [4], 0xf7537e82, 6) ;
		STEP2 (I, mD, mA, mB, mC, mBlock [11], 0xbd3af235, 10) ;
		STEP2 (I, mC, mD, mA, mB, mBlock [2], 0x2ad7d2bb, 15) ;
		STEP2 (I, mB, mC, mD, mA, mBlock [9], 0xeb86d391, 21) ;

		mA = addU32IgnoringOverflow (mA, saved_a) ;
		mB = addU32IgnoringOverflow (mB, saved_b) ;
		mC = addU32IgnoringOverflow (mC, saved_c) ;
		mD = addU32IgnoringOverflow (mD, saved_d) ;

		ptr += 64;
	} while (currentByteLength -= 64);

	return ptr;
}

//-------------------------------------------------------------------------------------------------

MD5Digest MD5pm::finalizeAndGetDigest (void) const {
  MD5pm temporary = *this ;
	uint32_t used = temporary.mLo & 0x3f;

	temporary.mBuffer[used] = 0x80 ;
  used += 1 ;

	uint32_t available = 64 - used;

	if (available < 8) {
		memset(&temporary.mBuffer[used], 0, available);
		temporary.body (temporary.mBuffer, 64);
		used = 0;
		available = 64;
	}

	memset (&temporary.mBuffer[used], 0, available - 8);

	temporary.mLo <<= 3;
  temporary.mBuffer [56] = uint8_t (temporary.mLo >>  0) ;
  temporary.mBuffer [57] = uint8_t (temporary.mLo >>  8) ;
  temporary.mBuffer [58] = uint8_t (temporary.mLo >> 16) ;
  temporary.mBuffer [59] = uint8_t (temporary.mLo >> 24) ;
  temporary.mBuffer [60] = uint8_t (temporary.mHi >>  0) ;
  temporary.mBuffer [61] = uint8_t (temporary.mHi >>  8) ;
  temporary.mBuffer [62] = uint8_t (temporary.mHi >> 16) ;
  temporary.mBuffer [63] = uint8_t (temporary.mHi >> 24) ;

	temporary.body (temporary.mBuffer, 64);

  const MD5Digest result (temporary.mA, temporary.mB, temporary.mC, temporary.mD) ;
  return result ;
}

//-------------------------------------------------------------------------------------------------

MD5Digest::MD5Digest (void) {
}

//-------------------------------------------------------------------------------------------------

MD5Digest::MD5Digest (const uint32_t inA, const uint32_t inB, const uint32_t inC, const uint32_t inD) {
  mBuffer [0] = inA ;
  mBuffer [1] = inB ;
  mBuffer [2] = inC ;
  mBuffer [3] = inD ;
}

//-------------------------------------------------------------------------------------------------

uint8_t MD5Digest::operator [] (const size_t inIndex) const {
  uint32_t v = mBuffer [inIndex / 4] ;
  v >>= (inIndex % 4) * 8 ;
  return uint8_t (v) ;
}

//-------------------------------------------------------------------------------------------------
