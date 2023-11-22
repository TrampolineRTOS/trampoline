#include <iostream>
#include <cinttypes>

//--------------------------------------------------------------------------------------------------

#include "BigUnsigned.h"
#include "utilities/M_machine.h"
#include "utilities/galgas-random.h"
#include "uint128-multiply-divide.h"

//--------------------------------------------------------------------------------------------------
// https://gcc.gnu.org/onlinedocs/gcc/Integer-Overflow-Builtins.html
// https://fr.wikipedia.org/wiki/Algorithme_de_multiplication_d%27entiers
//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors
#endif

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::randomNumber (void) {
  BigUnsigned result ;
  const size_t randomSize = 1 + size_t (galgas_random ()) % 20 ;
  for (size_t i=0 ; i<randomSize ; i++) {
    result.mArray.push_back (uint64_t (galgas_random ())) ;
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned::BigUnsigned (void) noexcept :
mArray () {
}

//--------------------------------------------------------------------------------------------------

BigUnsigned::BigUnsigned (const uint64_t inValue) noexcept :
mArray () {
  if (inValue != 0) {
    mArray.push_back (inValue) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Shifts
#endif

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::leftShiftedBy (const uint32_t inShiftCount) const {
  BigUnsigned result ;
  if (mArray.size () > 0) {
    const uint32_t shift = inShiftCount % 64 ;
    uint64_t carry = 0 ;
    for (uint32_t i=0 ; i<mArray.size () ; i++) {
      const uint64_t v = mArray [i] ;
      result.mArray.push_back ((v << shift) | carry) ;
      carry = v >> (64 - shift) ;
    }
    if (carry != 0) {
      result.mArray.push_back (uint64_t (carry)) ;
    }
    const uint32_t insertedWordCount = inShiftCount / 64 ;
    if (insertedWordCount > 0) {
      result.mArray.insert (result.mArray.begin (), insertedWordCount, 0) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Add, subtract
#endif

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::addingBigUnsigned (const BigUnsigned & inOperand) const {
  BigUnsigned result ;
  if (mArray.size () == 0) { // Receiver is zero
    result = inOperand ;
  }else if (inOperand.mArray.size () == 0) { // Operand is zero
    result = *this ;
  }else{
    uint64_t carry = 0 ;
    const size_t maxSize = std::max (mArray.size (), inOperand.mArray.size ()) ;
    result.mArray.reserve (maxSize) ;
    const size_t minSize = std::min (mArray.size (), inOperand.mArray.size ()) ;
    for (size_t i=0 ; i<minSize ; i++) {
      const uint64_t v1 = mArray [i] ;
      const uint64_t v2 = inOperand.mArray [i] ;
      const uint64_t sum = v1 + v2 ;
      const bool ovf = sum < v1 ;
      result.mArray.push_back (sum + carry) ;
      carry = ovf ;
    }
    for (size_t i=mArray.size () ; i<maxSize ; i++) {
      const uint64_t v2 = inOperand.mArray [i] ;
      const uint64_t sum = v2 + carry ;
      const bool ovf = sum < v2 ;
      result.mArray.push_back (sum) ;
      carry = ovf ;
    }
    for (size_t i=inOperand.mArray.size () ; i<maxSize ; i++) {
      const uint64_t v2 = mArray [i] ;
      const uint64_t sum = v2 + carry ;
      const bool ovf = sum < v2 ;
      result.mArray.push_back (sum) ;
      carry = ovf ;
    }
    if (carry != 0) {
      result.mArray.push_back (carry) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::subtractingBigUnsigned (const BigUnsigned & inOperand) const {
  BigUnsigned result ;
  int compareResult = compare (inOperand) ;
  if (compareResult < 0) { // Error
    std::cout << "Error " << __FILE__ << ":" << __LINE__ << "\n" ;
    exit (1) ;
  }else if (compareResult > 0) {
    result.mArray.reserve (mArray.size ()) ;
    bool borrow = false ;
    for (size_t i = 0 ; i < mArray.size () ; i++) {
      uint64_t v2 = (i < inOperand.mArray.size ()) ? inOperand.mArray [i] : 0 ;
      if (borrow) {
        v2 ++ ;
        if (v2 == 0) {
          result.mArray.push_back (mArray [i]) ;
          borrow = true ;
        }else{
          const uint64_t r = mArray [i] - v2 ;
          borrow = mArray [i] < v2 ;
          result.mArray.push_back (r) ;
        }
      }else{
        const uint64_t r = mArray [i] - v2 ;
        borrow = mArray [i] < v2 ;
        result.mArray.push_back (r) ;
      }
    }
    if (borrow) {
      std::cout << "Error " << __FILE__ << ":" << __LINE__ << "\n" ;
      exit (1) ;
    }
    while ((result.mArray.size () > 0) && (result.mArray.back () == 0)) {
      result.mArray.pop_back () ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Multiply
#endif

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::multiplyingByBigUnsigned (const BigUnsigned & inOperand) const {
  BigUnsigned result ;
  if ((mArray.size () != 0) && (inOperand.mArray.size () != 0)) { // Operands are not zero
    for (size_t i=0 ; i<inOperand.mArray.size () ; i++) {
      const BigUnsigned r1 = multiplyingByU64 (inOperand.mArray [i]) ;
      const BigUnsigned r2 = r1.leftShiftedBy (64 * uint32_t (i)) ;
      result = result.addingBigUnsigned (r2) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Logic operations
#endif

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::oringWithBigUnsigned (const BigUnsigned & inOperand) const {
  BigUnsigned result ;
  if (mArray.size () == 0) { // Receiver is zero
    result = inOperand ;
  }else if (inOperand.mArray.size () == 0) { // Operand is zero
    result = *this ;
  }else{
    const size_t maxSize = std::max (mArray.size (), inOperand.mArray.size ()) ;
    result.mArray.reserve (maxSize) ;
    const size_t minSize = std::min (mArray.size (), inOperand.mArray.size ()) ;
    for (size_t i=0 ; i<minSize ; i++) {
      result.mArray.push_back (mArray [i] | inOperand.mArray [i]) ;
    }
    for (size_t i=mArray.size () ; i<maxSize ; i++) {
      result.mArray.push_back (inOperand.mArray [i]) ;
    }
    for (size_t i=inOperand.mArray.size () ; i<maxSize ; i++) {
      result.mArray.push_back (mArray [i]) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::xoringWithBigUnsigned (const BigUnsigned & inOperand) const {
  BigUnsigned result ;
  if (mArray.size () == 0) { // Receiver is zero
    result = inOperand ;
  }else if (inOperand.mArray.size () == 0) { // Operand is zero
    result = *this ;
  }else{
    const size_t maxSize = std::max (mArray.size (), inOperand.mArray.size ()) ;
    result.mArray.reserve (maxSize) ;
    const size_t minSize = std::min (mArray.size (), inOperand.mArray.size ()) ;
    for (size_t i=0 ; i<minSize ; i++) {
      result.mArray.push_back (mArray [i] ^ inOperand.mArray [i]) ;
    }
    for (size_t i=mArray.size () ; i<maxSize ; i++) {
      result.mArray.push_back (inOperand.mArray [i]) ;
    }
    for (size_t i=inOperand.mArray.size () ; i<maxSize ; i++) {
      result.mArray.push_back (mArray [i]) ;
    }
    while ((result.mArray.size () > 0) && (result.mArray.back () == 0)) {
      result.mArray.pop_back () ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::andingWithBigUnsigned (const BigUnsigned & inOperand) const {
  BigUnsigned result ;
  if ((mArray.size () != 0) && (inOperand.mArray.size () != 0)) { // Operand are not zero
    const size_t minSize = std::min (mArray.size (), inOperand.mArray.size ()) ;
    result.mArray.reserve (minSize) ;
    for (size_t i=0 ; i<minSize ; i++) {
      result.mArray.push_back (mArray [i] & inOperand.mArray [i]) ;
    }
    while ((result.mArray.size () > 0) && (result.mArray.back () == 0)) {
      result.mArray.pop_back () ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::complemented (void) const {
  BigUnsigned result ;
  result.mArray.reserve (mArray.size ()) ;
  for (size_t i=0 ; i<mArray.size () ; i++) {
    result.mArray.push_back (~ mArray [i]) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Compare
#endif

//--------------------------------------------------------------------------------------------------

int BigUnsigned::compare (const BigUnsigned & inOperand) const {
  int result = 0 ;
  if (mArray.size () < inOperand.mArray.size ()) {
    result = -1 ;
  }else if (mArray.size () > inOperand.mArray.size ()) {
    result = 1 ;
  }else if (mArray.size () > 0) {
    for (int i = int (mArray.size ()) - 1 ; (result == 0) && (i >= 0) ; i--) {
      if (mArray [size_t (i)] < inOperand.mArray [size_t (i)]) {
        result = -1 ;
      }else if (mArray [size_t (i)] > inOperand.mArray [size_t (i)]) {
        result = 1 ;
      }
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Print
#endif

//--------------------------------------------------------------------------------------------------

void BigUnsigned::printHex (const char * inName) const {
  if (mArray.size () == 0) {
    printf ("%s: 0\n", inName) ;
  }else{
    printf ("%s: 0x", inName) ;
    for (int i = int (mArray.size ()) - 1 ; i>= 0 ; i--) {
      printf ("'%0" PRIx64 "X", mArray [size_t (i)]) ;
    }
    printf ("\n") ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Operations with U64
#endif

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::addingU64 (const uint64_t inOperand) const {
  BigUnsigned result ;
  if (mArray.size () == 0) { // Receiver is zero
    if (inOperand != 0) {
      result.mArray.push_back (inOperand) ;
    }
  }else{
    uint64_t carry = inOperand ;
    result.mArray.reserve (mArray.size () + 1) ;
    for (size_t i=0 ; i<mArray.size () ; i++) {
      const uint64_t sum = mArray [i] + carry ;
      result.mArray.push_back (sum) ;
      carry = sum < mArray [i] ;
    }
    if (carry != 0) {
      result.mArray.push_back (carry) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

BigUnsigned BigUnsigned::multiplyingByU64 (const uint64_t inOperand) const {
  BigUnsigned result ;
  if ((mArray.size () != 0) && (inOperand != 0)) { // Operands are not zero
    result.mArray.reserve (mArray.size () + 1) ;
    uint64_t carry = 0 ;
    for (size_t i=0 ; i<mArray.size () ; i++) {
    //--- multiplication 64 x 64 -> 128
      uint64_t high ;
      uint64_t low ;
      mul64x64to128 (mArray [i], inOperand, high, low) ;
    //--- Add carry
      low += carry ;
      high += (low < carry) ;
    //--- Store result
      result.mArray.push_back (low) ;
      carry = high ;
    }
    if (carry != 0) {
      result.mArray.push_back (carry) ;
    }
  }
  return result ;
}

//--------------------------------------------------------------------------------------------------

void BigUnsigned::divideByU64 (const uint64_t inDivisor,
                               BigUnsigned & outQuotient,
                               uint64_t & outRemainder) const {
  if (inDivisor == 0) {
    std::cout << "Error " << __FILE__ << ":" << __LINE__ << "\n" ;
    exit (1) ;
  }else if (inDivisor == 1) {
    outQuotient = *this ;
    outRemainder = 0 ;
  }else if (mArray.size () == 1) {
    outQuotient = BigUnsigned () ;
    outQuotient.mArray.push_back (mArray [0] / inDivisor) ;
    outRemainder = mArray [0] % inDivisor ;
  }else{
    outQuotient = BigUnsigned () ;
    outQuotient.mArray.resize (mArray.size (), 0) ;
    outRemainder = 0 ;
    for (int i = int (mArray.size ()) - 1 ; i >= 0 ; i--) {
      uint64_t quotient ;
      uint64_t r ;
      divmod128by64 (outRemainder, mArray [size_t (i)], inDivisor, quotient, r) ;
      outQuotient.mArray [size_t (i)] = quotient ;
      outRemainder = r ;
    }
    while ((outQuotient.mArray.size () > 0) && (outQuotient.mArray.back () == 0)) {
      outQuotient.mArray.pop_back () ;
    }
  }
}

//--------------------------------------------------------------------------------------------------
// https://copyprogramming.com/howto/mostly-portable-128-by-64-bit-division
// https://www.codeproject.com/Tips/785014/UInt-Division-Modulus

//static void divmod128by64 (const uint64_t inDividendH,
//                           const uint64_t inDividendL,
//                           const uint64_t inDivisor,
//                           uint64_t & outQuotient,
//                           uint64_t & outRemainder) {
//    const uint64_t b = 1ll << 32;
//    uint64_t un1, un0, vn1, vn0, q1, q0, un32, un21, un10, rhat, left, right;
////    size_t s;
//
//    // s = nlz64(v);
//    const int s = __builtin_clzl (inDivisor) ;
//
//    const uint64_t v = inDivisor << s;
//    vn1 = v >> 32;
//    vn0 = v & 0xffffffff;
//
//    if (s > 0)
//    {
//        un32 = (inDividendH << s) | (inDividendL >> (64 - s));
//        un10 = inDividendL << s;
//    }
//    else
//    {
//        un32 = inDividendH;
//        un10 = inDividendL;
//    }
//
//    un1 = un10 >> 32;
//    un0 = un10 & 0xffffffff;
//
//    q1 = un32 / vn1;
//    rhat = un32 % vn1;
//
//    left = q1 * vn0;
//    right = (rhat << 32) + un1;
//again1:
//    if ((q1 >= b) || (left > right))
//    {
//        --q1;
//        rhat += vn1;
//        if (rhat < b)
//        {
//            left -= vn0;
//            right = (rhat << 32) | un1;
//            goto again1;
//        }
//    }
//
//    un21 = (un32 << 32) + (un1 - (q1 * v));
//
//    q0 = un21 / vn1;
//    rhat = un21 % vn1;
//
//    left = q0 * vn0;
//    right = (rhat << 32) | un0;
//again2:
//    if ((q0 >= b) || (left > right))
//    {
//        --q0;
//        rhat += vn1;
//        if (rhat < b)
//        {
//            left -= vn0;
//            right = (rhat << 32) | un0;
//            goto again2;
//        }
//    }
//
//    outRemainder = ((un21 << 32) + (un0 - (q0 * v))) >> s;
//    outQuotient = (q1 << 32) | q0;
//}

//static void div128By64 (const uint64_t inDividendH,
//                        const uint64_t inDividendL,
//                        const uint64_t inDivisor,
//                        uint64_t & outQuotientH,
//                        uint64_t & outQuotientL,
//                        uint64_t & outRemainder) {
//  outQuotientH = inDividendH / inDivisor ;
//  const uint64_t rH = inDividendH % inDivisor ;
//
//  const uint64_t u1 = (op1 & 0xffffffff) ;
//  const uint64_t v1 = (op2 & 0xffffffff) ;
//  uint64_t t = (u1 * v1);
//  const uint64_t w3 = (t & 0xffffffff);
//  uint64_t k = (t >> 32);
//
//  op1 >>= 32;
//  t = (op1 * v1) + k;
//  k = (t & 0xffffffff);
//  uint64_t w1 = (t >> 32);
//
//  op2 >>= 32;
//  t = (u1 * op2) + k;
//  k = (t >> 32);
//
//  outHigh = (op1 * op2) + w1 + k;
//  outLow = (t << 32) + w3;
//}

//--------------------------------------------------------------------------------------------------
