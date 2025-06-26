#pragma once

//--------------------------------------------------------------------------------------------------

#if (!defined (USE_8_BITS_CHUNKS)) && (!defined (USE_16_BITS_CHUNKS)) && (!defined (USE_32_BITS_CHUNKS))
  #define USE_64_BITS_CHUNKS
#endif

//--------------------------------------------------------------------------------------------------

#ifdef USE_8_BITS_CHUNKS
  #include "chunk-U8.h"
#endif

#ifdef USE_16_BITS_CHUNKS
 #include "chunk-U16.h"
#endif

#ifdef USE_32_BITS_CHUNKS
 #include "chunk-U32.h"
#endif

#ifdef USE_64_BITS_CHUNKS
 #include "chunk-U64.h"
#endif

//--------------------------------------------------------------------------------------------------
// addReportingOverflow
//  Performs ioResult += inOperand
//  If overflow occurs, 1 is added to ioOverflowReport
//--------------------------------------------------------------------------------------------------

inline void addReportingOverflow (ChunkUInt & ioResult,
                                  const ChunkUInt inOperand,
                                  ChunkUInt & ioOverflowReport) {
  const bool overflow = __builtin_add_overflow (ioResult, inOperand, &ioResult) ;
  ioOverflowReport += ChunkUInt (overflow) ;
}

//--------------------------------------------------------------------------------------------------
// subtractReportingOverflow
//  Performs ioResult -= inOperand
//  If overflow occurs, 1 is added to ioOverflowReport
//--------------------------------------------------------------------------------------------------

inline void subtractReportingOverflow (ChunkUInt & ioResult,
                                       const ChunkUInt inOperand,
                                       ChunkUInt & ioOverflowReport) {
  const bool overflow = __builtin_sub_overflow (ioResult, inOperand, &ioResult) ;
  ioOverflowReport += ChunkUInt (overflow) ;
}

//--------------------------------------------------------------------------------------------------
// subtractIgnoringOverflow
//  Performs ioResult -= inOperand
//--------------------------------------------------------------------------------------------------

inline void subtractIgnoringOverflow (ChunkUInt & ioResult,
                                      const ChunkUInt inOperand) {
  __builtin_sub_overflow (ioResult, inOperand, &ioResult) ;
}

//--------------------------------------------------------------------------------------------------
// leftShiftIgnoringOverflow
//  Performs result = inOperand << inShiftCount
//--------------------------------------------------------------------------------------------------

inline ChunkUInt leftShiftIgnoringOverflow (const ChunkUInt inOperand,
                                            const size_t inShiftCount) {
  const ChunkUInt ChunkUIntBitCount = sizeof (ChunkUInt) * 8 ;
  ChunkUInt r = inOperand ;
  if (inShiftCount > 0) {
    r &= (ChunkUInt (1) << (ChunkUIntBitCount - inShiftCount)) - ChunkUInt (1) ;
    r <<= inShiftCount ;
  }
  return r ;
}

//--------------------------------------------------------------------------------------------------
