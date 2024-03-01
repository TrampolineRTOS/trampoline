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
 * See md5.c for more information.
 */
// Modified by Pierre Molinaro 7 february 2024
//-------------------------------------------------------------------------------------------------

#pragma once

//-------------------------------------------------------------------------------------------------

#include <array>
#include <stdint.h>

//-------------------------------------------------------------------------------------------------

class MD5Digest {
//--- Constructor
  public: MD5Digest (void) ;
  public: MD5Digest (const uint32_t inA, const uint32_t inB, const uint32_t inC, const uint32_t inD) ;

//--- Accessor
  public: uint8_t operator [] (const size_t inIndex) const ;

//--- Private property
  public: std::array <uint32_t, 4> mBuffer = {0} ;
} ;

//-------------------------------------------------------------------------------------------------

class MD5pm final {
//--- Constructor
  public: MD5pm (void) ;

//--- Public methods
  public: void appendData (const void * inDataPtr, const size_t inByteLength) ;

  public: MD5Digest finalizeAndGetDigest (void) const ;

//--- Private methods
 private: const uint8_t * body (const uint8_t * inDataPtr, const size_t inByteLength) ;

//--- Private properties
	private: uint32_t mLo = 0 ;
  private: uint32_t mHi = 0 ;
	private: uint32_t mA = 0x67452301 ;
	private: uint32_t mB = 0xefcdab89 ;
	private: uint32_t mC = 0x98badcfe ;
	private: uint32_t mD = 0x10325476 ;
	private: uint8_t mBuffer [64] ;
	private: uint32_t mBlock [16] ;
} ;

//-------------------------------------------------------------------------------------------------
