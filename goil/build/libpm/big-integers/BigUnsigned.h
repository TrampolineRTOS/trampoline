#pragma once

//--------------------------------------------------------------------------------------------------

#include <cstdint>
#include <vector>

//--------------------------------------------------------------------------------------------------

class BigUnsigned {

//--- Constructors
  public: static BigUnsigned randomNumber (void) ;
  public: BigUnsigned (void) noexcept ;
  public: BigUnsigned (const uint64_t inValue) noexcept ;


//--- Operators
  public: BigUnsigned leftShiftedBy (const uint32_t inShifCount) const ;
  public: BigUnsigned addingU64 (const uint64_t inOperand) const ;
  public: BigUnsigned addingBigUnsigned (const BigUnsigned & inOperand) const ;
  public: BigUnsigned subtractingBigUnsigned (const BigUnsigned & inOperand) const ;
  public: BigUnsigned multiplyingByU64 (const uint64_t inOperand) const ;
  public: void divideByU64 (const uint64_t inDivisor,
                            BigUnsigned & outQuotient,
                            uint64_t & outRemainder) const ;
  public: BigUnsigned multiplyingByBigUnsigned (const BigUnsigned & inOperand) const ;
  public: void divideByBigUnsigned (const BigUnsigned & inDivisor,
                                    BigUnsigned & outQuotient,
                                    BigUnsigned & outRemainder) ;
  public: int compare (const BigUnsigned & inOperand) const ;

  public: BigUnsigned oringWithBigUnsigned (const BigUnsigned & inOperand) const ;
  public: BigUnsigned xoringWithBigUnsigned (const BigUnsigned & inOperand) const ;
  public: BigUnsigned andingWithBigUnsigned (const BigUnsigned & inOperand) const ;
  public: BigUnsigned complemented (void) const ;

  public: void printHex (const char * inName) const ;

//--- Private properties
  private: std::vector <uint64_t> mArray ;
} ;

//--------------------------------------------------------------------------------------------------
