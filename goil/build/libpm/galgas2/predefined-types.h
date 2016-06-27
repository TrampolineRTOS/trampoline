//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef GALGAS2_INCLUDED_DEFINITIONS
#define GALGAS2_INCLUDED_DEFINITIONS

//----------------------------------------------------------------------------------------------------------------------

#include "strings/C_String.h"
#include "time/C_Timer.h"
#include "galgas2/AC_GALGAS_root.h"
#include "galgas2/C_galgas_type_descriptor.h"
#include "galgas2/typeComparisonResult.h"
#include "galgas2/cGenericAbstractEnumerator.h"
#include "galgas2/cEnumerator_range.h"
#include "galgas2/AC_GALGAS_list.h"
#include "galgas2/AC_GALGAS_sortedlist.h"
#include "galgas2/AC_GALGAS_map.h"
#include "galgas2/AC_GALGAS_uniqueMap.h"
#include "galgas2/AC_GALGAS_class.h"
#include "galgas2/AC_GALGAS_enumAssociatedValues.h"
#include "galgas2/AC_GALGAS_graph.h"
#include "galgas2/acPtr_class.h"
#include "command_line_interface/C_BoolCommandLineOption.h"
#include "command_line_interface/C_UIntCommandLineOption.h"
#include "command_line_interface/C_StringCommandLineOption.h"
#include "command_line_interface/C_StringListCommandLineOption.h"
#include "utilities/C_PrologueEpilogue.h"
#include "utilities/C_BigInt.h"

//----------------------------------------------------------------------------------------------------------------------

class C_Compiler ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS__32_lstringlist ;
class GALGAS__32_lstringlist_2D_element ;
class GALGAS__32_stringlist ;
class GALGAS__32_stringlist_2D_element ;
class GALGAS_application ;
class GALGAS_bigint ;
class GALGAS_bigintlist ;
class GALGAS_bigintlist_2D_element ;
class GALGAS_binaryset ;
class GALGAS_bool ;
class GALGAS_char ;
class GALGAS_data ;
class GALGAS_double ;
class GALGAS_filewrapper ;
class GALGAS_function ;
class GALGAS_functionlist ;
class GALGAS_functionlist_2D_element ;
class GALGAS_lbigint ;
class GALGAS_lbigintlist ;
class GALGAS_lbigintlist_2D_element ;
class GALGAS_lbool ;
class GALGAS_lchar ;
class GALGAS_ldouble ;
class GALGAS_location ;
class GALGAS_lsint ;
class GALGAS_lsint_36__34_ ;
class GALGAS_lstring ;
class GALGAS_lstringlist ;
class GALGAS_lstringlist_2D_element ;
class GALGAS_luint ;
class GALGAS_luint_36__34_ ;
class GALGAS_luintlist ;
class GALGAS_luintlist_2D_element ;
class GALGAS_object ;
class GALGAS_objectlist ;
class GALGAS_objectlist_2D_element ;
class GALGAS_range ;
class GALGAS_sint ;
class GALGAS_sint_36__34_ ;
class GALGAS_string ;
class GALGAS_stringlist ;
class GALGAS_stringlist_2D_element ;
class GALGAS_stringset ;
class GALGAS_timer ;
class GALGAS_type ;
class GALGAS_typelist ;
class GALGAS_typelist_2D_element ;
class GALGAS_uint ;
class GALGAS_uint_36__34_ ;
class GALGAS_uint_36__34_list ;
class GALGAS_uint_36__34_list_2D_element ;
class GALGAS_uintlist ;
class GALGAS_uintlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  @application type                                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_application : public AC_GALGAS_root {
//--------------------------------- Accessors
  public : inline bool isValid (void) const { return false ; }
  public : inline void drop (void) { }

//--------------------------------- Default constructor
  public : GALGAS_application (void) ;

//--------------------------------- Destructor (virtual in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_application (void) ;

//--------------------------------- Handle copy
  public : GALGAS_application (const GALGAS_application & inSource) ;
  public : GALGAS_application & operator = (const GALGAS_application & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_application extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_string constructor_boolOptionCommentString (const class GALGAS_string & inOperand0,
                                                                     const class GALGAS_string & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

  public : static GALGAS_char constructor_boolOptionInvocationCharacter (const class GALGAS_string & inOperand0,
                                                                         const class GALGAS_string & inOperand1
                                                                         COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_boolOptionInvocationString (const class GALGAS_string & inOperand0,
                                                                        const class GALGAS_string & inOperand1
                                                                        COMMA_LOCATION_ARGS) ;

  public : static GALGAS__32_stringlist constructor_boolOptionNameList (LOCATION_ARGS) ;

  public : static GALGAS_string constructor_commandLineArgumentAtIndex (const class GALGAS_uint & inOperand0,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

  public : static GALGAS_uint constructor_commandLineArgumentCount (LOCATION_ARGS) ;

  public : static GALGAS_string constructor_galgasVersionString (LOCATION_ARGS) ;

  public : static GALGAS_stringset constructor_keywordIdentifierSet (LOCATION_ARGS) ;

  public : static GALGAS_stringlist constructor_keywordListForIdentifier (const class GALGAS_string & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_projectVersionString (LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringOptionCommentString (const class GALGAS_string & inOperand0,
                                                                       const class GALGAS_string & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

  public : static GALGAS_char constructor_stringOptionInvocationCharacter (const class GALGAS_string & inOperand0,
                                                                           const class GALGAS_string & inOperand1
                                                                           COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringOptionInvocationString (const class GALGAS_string & inOperand0,
                                                                          const class GALGAS_string & inOperand1
                                                                          COMMA_LOCATION_ARGS) ;

  public : static GALGAS__32_stringlist constructor_stringOptionNameList (LOCATION_ARGS) ;

  public : static GALGAS_string constructor_uintOptionCommentString (const class GALGAS_string & inOperand0,
                                                                     const class GALGAS_string & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

  public : static GALGAS_char constructor_uintOptionInvocationCharacter (const class GALGAS_string & inOperand0,
                                                                         const class GALGAS_string & inOperand1
                                                                         COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_uintOptionInvocationString (const class GALGAS_string & inOperand0,
                                                                        const class GALGAS_string & inOperand1
                                                                        COMMA_LOCATION_ARGS) ;

  public : static GALGAS__32_stringlist constructor_uintOptionNameList (LOCATION_ARGS) ;

  public : static GALGAS_bool constructor_verboseOutput (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_application & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_application class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_application ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @bigint type                                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint : public AC_GALGAS_root {
//--------------------------------- Private properties
  private : bool mIsValid ;
  private : C_BigInt mValue ;

//--------------------------------- Accessors
  public : inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_bigint (void) ;

//--------------------------------- Constructor
  public : GALGAS_bigint (const C_BigInt & inValue) ;
  public : GALGAS_bigint (const char * inDecimalString, C_Compiler * inCompiler COMMA_LOCATION_ARGS) ;

//--------------------------------- Destructor
  public : virtual ~ GALGAS_bigint (void) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_bigint extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_bigint constructor_zero (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public : VIRTUAL_IN_DEBUG GALGAS_bigint left_shift_operation (const GALGAS_uint inShiftOperand
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_bigint right_shift_operation (const GALGAS_uint inShiftOperand
                                                                 COMMA_LOCATION_ARGS) const ;

//--------------------------------- & operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint operator_and (const GALGAS_bigint & inOperand
                                                        COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint operator_or (const GALGAS_bigint & inOperand
                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint operator_xor (const GALGAS_bigint & inOperand
                                                        COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint add_operation (const GALGAS_bigint & inOperand,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- - operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint substract_operation (const GALGAS_bigint & inOperand,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint multiply_operation (const GALGAS_bigint & inOperand,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- / operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint divide_operation (const GALGAS_bigint & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- mod operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint modulo_operation (const GALGAS_bigint & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix - operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigint operator_unary_minus (C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;

//--------------------------------- ++, -- operators
  public : VIRTUAL_IN_DEBUG void increment_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void decrement_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_bigint & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_complementBitAtIndex (class GALGAS_uint constinArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setBitAtIndex (class GALGAS_bool constinArgument0,
                                                       class GALGAS_uint constinArgument1
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_ceilDivideBy (class GALGAS_bigint constinArgument0,
                                                      class GALGAS_bigint & outArgument1,
                                                      class GALGAS_bigint & outArgument2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_divideBy (class GALGAS_bigint constinArgument0,
                                                  class GALGAS_bigint & outArgument1,
                                                  class GALGAS_bigint & outArgument2,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_floorDivideBy (class GALGAS_bigint constinArgument0,
                                                       class GALGAS_bigint & outArgument1,
                                                       class GALGAS_bigint & outArgument2,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_abs (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_bitAtIndex (const class GALGAS_uint & constinOperand0
                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_bitCountForSignedRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_bitCountForUnsignedRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_extract_33__32_ForSignedRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_extract_33__32_ForUnsignedRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_extract_36__34_ForSignedRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_extract_36__34_ForUnsignedRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_extract_38_ForSignedRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_extract_38_ForUnsignedRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_fitsInSInt (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_fitsInSInt_36__34_ (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_fitsInUInt (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_fitsInUInt_36__34_ (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isZero (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_sign (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_spacedString (const class GALGAS_uint & constinOperand0
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_bigint class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bigint ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @binaryset type                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

#include "bdd/C_BDD.h"

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_binaryset : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : C_BDD mBDD ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mIsValid = false ; }
  public : inline C_BDD bddValue (void) const { return mBDD ; }

//--------------------------------- Default constructor
  public : GALGAS_binaryset (void) ;

//--------------------------------- Native constructor
  public : GALGAS_binaryset (const C_BDD & inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_binaryset extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_binaryset constructor_binarySetWithBit (const class GALGAS_uint & inOperand0,
                                                                 class C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithEqualComparison (const class GALGAS_uint & inOperand0,
                                                                             const class GALGAS_uint & inOperand1,
                                                                             const class GALGAS_uint & inOperand2,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithEqualToConstant (const class GALGAS_uint & inOperand0,
                                                                             const class GALGAS_uint & inOperand1,
                                                                             const class GALGAS_uint_36__34_ & inOperand2,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithGreaterOrEqualComparison (const class GALGAS_uint & inOperand0,
                                                                                      const class GALGAS_uint & inOperand1,
                                                                                      const class GALGAS_uint & inOperand2,
                                                                                      class C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithGreaterOrEqualToConstant (const class GALGAS_uint & inOperand0,
                                                                                      const class GALGAS_uint & inOperand1,
                                                                                      const class GALGAS_uint_36__34_ & inOperand2,
                                                                                      class C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithLowerOrEqualComparison (const class GALGAS_uint & inOperand0,
                                                                                    const class GALGAS_uint & inOperand1,
                                                                                    const class GALGAS_uint & inOperand2,
                                                                                    class C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithLowerOrEqualToConstant (const class GALGAS_uint & inOperand0,
                                                                                    const class GALGAS_uint & inOperand1,
                                                                                    const class GALGAS_uint_36__34_ & inOperand2,
                                                                                    class C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithNotEqualComparison (const class GALGAS_uint & inOperand0,
                                                                                const class GALGAS_uint & inOperand1,
                                                                                const class GALGAS_uint & inOperand2,
                                                                                class C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithNotEqualToConstant (const class GALGAS_uint & inOperand0,
                                                                                const class GALGAS_uint & inOperand1,
                                                                                const class GALGAS_uint_36__34_ & inOperand2,
                                                                                class C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithPredicateString (const class GALGAS_string & inOperand0,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithStrictGreaterComparison (const class GALGAS_uint & inOperand0,
                                                                                     const class GALGAS_uint & inOperand1,
                                                                                     const class GALGAS_uint & inOperand2,
                                                                                     class C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithStrictGreaterThanConstant (const class GALGAS_uint & inOperand0,
                                                                                       const class GALGAS_uint & inOperand1,
                                                                                       const class GALGAS_uint_36__34_ & inOperand2,
                                                                                       class C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithStrictLowerComparison (const class GALGAS_uint & inOperand0,
                                                                                   const class GALGAS_uint & inOperand1,
                                                                                   const class GALGAS_uint & inOperand2,
                                                                                   class C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_binarySetWithStrictLowerThanConstant (const class GALGAS_uint & inOperand0,
                                                                                     const class GALGAS_uint & inOperand1,
                                                                                     const class GALGAS_uint_36__34_ & inOperand2,
                                                                                     class C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_emptyBinarySet (LOCATION_ARGS) ;

  public : static GALGAS_binaryset constructor_fullBinarySet (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public : VIRTUAL_IN_DEBUG GALGAS_binaryset left_shift_operation (const GALGAS_uint inShiftOperand
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_binaryset right_shift_operation (const GALGAS_uint inShiftOperand
                                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- & operator
  public : VIRTUAL_IN_DEBUG GALGAS_binaryset operator_and (const GALGAS_binaryset & inOperand
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public : VIRTUAL_IN_DEBUG GALGAS_binaryset operator_or (const GALGAS_binaryset & inOperand
                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public : VIRTUAL_IN_DEBUG GALGAS_binaryset operator_xor (const GALGAS_binaryset & inOperand
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public : VIRTUAL_IN_DEBUG GALGAS_binaryset operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_binaryset & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods
  public : static void class_method_setAndTableSize (class GALGAS_uint constinArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public : static void class_method_setNodeTableSize (class GALGAS_uint constinArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_ITE (const class GALGAS_binaryset & constinOperand0,
                                                               const class GALGAS_binaryset & constinOperand1
                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_accessibleStates (const class GALGAS_binaryset & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigValueCount (const class GALGAS_uint & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_binarySetByTranslatingFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                           const class GALGAS_uint & constinOperand1
                                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_compressedStringValueList (const class GALGAS_uint & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_compressedValueCount (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_containsValue (const class GALGAS_uint_36__34_ & constinOperand0,
                                                                    const class GALGAS_uint & constinOperand1,
                                                                    const class GALGAS_uint & constinOperand2
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_equalTo (const class GALGAS_binaryset & constinOperand0
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_existOnBitIndex (const class GALGAS_uint & constinOperand0
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_existOnBitIndexAndBeyond (const class GALGAS_uint & constinOperand0
                                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_existsOnBitRange (const class GALGAS_uint & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_forAllOnBitIndex (const class GALGAS_uint & constinOperand0
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_forAllOnBitIndexAndBeyond (const class GALGAS_uint & constinOperand0
                                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_graphviz (const class GALGAS_stringlist & constinOperand0
                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_graphvizDump (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_greaterOrEqualTo (const class GALGAS_binaryset & constinOperand0
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_implies (const class GALGAS_binaryset & constinOperand0
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isEmpty (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isFull (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_lowerOrEqualTo (const class GALGAS_binaryset & constinOperand0
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_nodeCount (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_notEqualTo (const class GALGAS_binaryset & constinOperand0
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_predicateStringValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_print (const class GALGAS_stringlist & constinOperand0,
                                                              const class GALGAS_uintlist & constinOperand1
                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_significantVariableCount (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_strictGreaterThan (const class GALGAS_binaryset & constinOperand0
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_strictLowerThan (const class GALGAS_binaryset & constinOperand0
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_stringValueList (const class GALGAS_uint & constinOperand0
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_stringValueListWithNameList (const class GALGAS_uint & constinOperand0,
                                                                                        const class GALGAS_stringlist & constinOperand1,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_30__32__31_ (const class GALGAS_uint & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            const class GALGAS_uint & constinOperand2
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_31__30_ (const class GALGAS_uint & constinOperand0,
                                                                        const class GALGAS_uint & constinOperand1
                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_31__30__32_ (const class GALGAS_uint & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            const class GALGAS_uint & constinOperand2
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_31__32__30_ (const class GALGAS_uint & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            const class GALGAS_uint & constinOperand2
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_32__30__31_ (const class GALGAS_uint & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            const class GALGAS_uint & constinOperand2
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_swap_32__31__30_ (const class GALGAS_uint & constinOperand0,
                                                                            const class GALGAS_uint & constinOperand1,
                                                                            const class GALGAS_uint & constinOperand2
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_transformedBy (const class GALGAS_uintlist & constinOperand0
                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_binaryset getter_transitiveClosure (const class GALGAS_uint & constinOperand0
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_uint_36__34_ValueList (const class GALGAS_uint & constinOperand0
                                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_valueCount (const class GALGAS_uint & constinOperand0,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_binaryset class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_binaryset ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                     @bool type                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

typedef enum {kBoolNotValid, kBoolFalse, kBoolTrue} enumGalgasBool ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : bool mBoolValue ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : inline bool isValidAndTrue (void) const { return mIsValid && mBoolValue ; }
  public : inline bool boolValue (void) const { return mBoolValue ; }
  public : enumGalgasBool boolEnum (void) const ;

//--------------------------------- Drop
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mIsValid = false ; }

//--------------------------------- Default constructor
  public : GALGAS_bool (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_bool constructor_default (LOCATION_ARGS) ;

//--------------------------------- Native constructors
  public : GALGAS_bool (const bool inValue) ; // Is built
  public : GALGAS_bool (const bool inBuilt, const bool inValue) ;

//--------------------------------- Constructor for comparison result
  public : GALGAS_bool (const typeComparisonKind inComparisonKind,
                        const typeComparisonResult inComparisonResult) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_bool extractObject (const GALGAS_object & inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public : VIRTUAL_IN_DEBUG GALGAS_bool operator_and (const GALGAS_bool & inOperand
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public : VIRTUAL_IN_DEBUG GALGAS_bool operator_or (const GALGAS_bool & inOperand
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public : VIRTUAL_IN_DEBUG GALGAS_bool operator_xor (const GALGAS_bool & inOperand
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- not operator
  public : VIRTUAL_IN_DEBUG GALGAS_bool operator_not (LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_bool & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_cString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_ocString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_bool class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bool ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                     @char type                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_char : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : utf32 mCharValue ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mIsValid = false ; }
  public : inline utf32 charValue (void) const { return mCharValue ; }

//--------------------------------- Default constructor
  public : GALGAS_char (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_char constructor_default (LOCATION_ARGS) ;

//--------------------------------- Native constructor
  public : GALGAS_char (const utf32 inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_char extractObject (const GALGAS_object & inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_char constructor_replacementCharacter (LOCATION_ARGS) ;

  public : static GALGAS_char constructor_unicodeCharacterWithUnsigned (const class GALGAS_uint & inOperand0
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_char & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeCommand (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeLetter (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeMark (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeNumber (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodePunctuation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeSeparator (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeSymbol (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isalnum (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isalpha (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_iscntrl (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isdigit (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_islower (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isupper (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isxdigit (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_unicodeName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_char getter_unicodeToLower (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_char getter_unicodeToUpper (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_33__32_CharConstantRepresentation (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_char class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_char ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                     @data type                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_data : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : C_Data mData ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mIsValid = false ; }
  public : inline C_Data dataValue (void) const { return mData ; }

//--------------------------------- Default constructor
  public : GALGAS_data (void) ;

//--------------------------------- Native constructors
  public : GALGAS_data (const C_Data & inData) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_data extractObject (const GALGAS_object & inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_data constructor_dataWithContentsOfFile (const class GALGAS_string & inOperand0,
                                                                  class C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

  public : static GALGAS_data constructor_emptyData (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_data & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_appendByte (class GALGAS_uint constinArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_appendData (class GALGAS_data constinArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_appendShortBE (class GALGAS_uint constinArgument0,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_appendShortLE (class GALGAS_uint constinArgument0,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_appendUIntBE (class GALGAS_uint constinArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_appendUIntLE (class GALGAS_uint constinArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_appendUTF_38_String (class GALGAS_string constinArgument0
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_writeToExecutableFile (class GALGAS_string constinArgument0,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_writeToFile (class GALGAS_string constinArgument0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_writeToFileWhenDifferentContents (class GALGAS_string constinArgument0,
                                                                          class GALGAS_bool & outArgument1,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_cStringRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_length (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Enumeration helper methods
  protected : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                              const typeEnumerationOrder inOrder) const ;

//--------------------------------- Friend

  friend class cEnumerator_data ;
 
} ; // End of GALGAS_data class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_data : public cGenericAbstractEnumerator {
  public : cEnumerator_data (const GALGAS_data & inEnumeratedObject,
                             const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_uint current_data (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_uint current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_data ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @double type                                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_double : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : double mDoubleValue ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mIsValid = false ; }
  public : inline double doubleValue (void) const { return mDoubleValue ; }

//--------------------------------- Default constructor
  public : GALGAS_double (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_double constructor_default (LOCATION_ARGS) ;

//--------------------------------- Native constructor
  public : GALGAS_double (const double inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_double extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_double constructor_doubleWithBinaryImage (const class GALGAS_uint_36__34_ & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

  public : static GALGAS_double constructor_pi (LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_double inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public : VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_double inOperand,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public : VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_double inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public : VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_double inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_double add_operation (const GALGAS_double & inOperand,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- - operator
  public : VIRTUAL_IN_DEBUG GALGAS_double substract_operation (const GALGAS_double & inOperand,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public : VIRTUAL_IN_DEBUG GALGAS_double multiply_operation (const GALGAS_double & inOperand,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- / operator
  public : VIRTUAL_IN_DEBUG GALGAS_double divide_operation (const GALGAS_double & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public : VIRTUAL_IN_DEBUG GALGAS_double divide_operation_no_ovf (const GALGAS_double & inOperand) const ;

//--------------------------------- mod operator
  public : VIRTUAL_IN_DEBUG GALGAS_double modulo_operation (const GALGAS_double & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix - operator
  public : VIRTUAL_IN_DEBUG GALGAS_double operator_unary_minus (C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_double & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_binaryImage (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_cos (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_cosDegree (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_exp (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_log_31__30_ (C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_log_32_ (C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_logn (C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_power (const class GALGAS_double & constinOperand0,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_sin (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_sinDegree (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_sqrt (C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_tan (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_tanDegree (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_double class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_double ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  @filewrapper type                                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class cRegularFileWrapper {
  public : const char * mName ;
  public : const char * mExtension ;
  public : const bool mIsTextFile ; // True: text file, false: binary file
  public : const uint32_t mFileLength ;
  public : const char * mContents ;

//--- Constructor
  public : cRegularFileWrapper (const char * inName,
                                const char * inExtension,
                                const bool inIsTextFile,
                                const uint32_t inFileLength,
                                const char * inContents) ;

//--- No copy
  private : cRegularFileWrapper (const cRegularFileWrapper &) ;
  private : cRegularFileWrapper & operator = (const cRegularFileWrapper &) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

class cDirectoryWrapper {
  public : const char * mDirectoryName ;
  public : const uint32_t mFileCount ;
  public : const cRegularFileWrapper * * const mFiles ;
  public : const uint32_t mDirectoryCount ;
  public : const cDirectoryWrapper * * mDirectories ;

//--- Constructor
  public : cDirectoryWrapper (const char * inDirectoryName,
                              const uint32_t inFileCount,
                              const cRegularFileWrapper * * const inFiles,
                              const uint32_t inDirectoryCount,
                              const cDirectoryWrapper * * inDirectories) ;

//--- No copy
  private : cDirectoryWrapper (const cDirectoryWrapper &) ;
  private : cDirectoryWrapper & operator = (const cDirectoryWrapper &) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_filewrapper : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : const cDirectoryWrapper * mRootDirectoryPtr ;
  private : C_String mCurrentDirectory ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return NULL != mRootDirectoryPtr ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mRootDirectoryPtr = NULL ; }

//--------------------------------- Default constructor
  public : GALGAS_filewrapper (void) ;

//--------------------------------- Native constructor
  public : GALGAS_filewrapper (const cDirectoryWrapper & inRootDirectory) ;

//--------------------------------- Handle copy
  public : GALGAS_filewrapper (const GALGAS_filewrapper & inSource) ;
  public : GALGAS_filewrapper & operator = (const GALGAS_filewrapper & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_filewrapper extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_filewrapper & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_setCurrentDirectory (class GALGAS_string constinArgument0,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_absolutePathForPath (const class GALGAS_string & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_allBinaryFilePathes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_allDirectoryPathes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_allFilePathesWithExtension (const class GALGAS_string & constinOperand0
                                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_allTextFilePathes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_data getter_binaryFileContentsAtPath (const class GALGAS_string & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_binaryFilesAtPath (const class GALGAS_string & constinOperand0,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_currentDirectory (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_directoriesAtPath (const class GALGAS_string & constinOperand0,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_directoryExistsAtPath (const class GALGAS_string & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_fileExistsAtPath (const class GALGAS_string & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_textFileContentsAtPath (const class GALGAS_string & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_textFilesAtPath (const class GALGAS_string & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_filewrapper class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_filewrapper ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @function type                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class C_galgas_function_descriptor ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_function : public AC_GALGAS_root {
//--------------------------------- Private data member
  private : const C_galgas_function_descriptor * mFunctionDescriptor ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return NULL != mFunctionDescriptor ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mFunctionDescriptor = NULL ; }
  public : VIRTUAL_IN_DEBUG inline const C_galgas_function_descriptor * functionValue (void) const { return mFunctionDescriptor ; }

//--------------------------------- Default constructor
  public : GALGAS_function (void) ;

//--------------------------------- Destructor (virtual in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_function (void) ;

//--------------------------------- Handle copy
  public : GALGAS_function (const GALGAS_function & inSource) ;
  public : GALGAS_function & operator = (const GALGAS_function & inSource) ;

//--------------------------------- Native constructor
  public : GALGAS_function (const C_galgas_function_descriptor * inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_function extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_functionlist constructor_functionList (LOCATION_ARGS) ;

  public : static GALGAS_function constructor_functionWithName (const class GALGAS_string & inOperand0
                                                                COMMA_LOCATION_ARGS) ;

  public : static GALGAS_bool constructor_isFunctionDefined (const class GALGAS_string & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_function & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_typelist getter_formalParameterTypeList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_object getter_invoke (const class GALGAS_objectlist & constinOperand0,
                                                               const class GALGAS_location & constinOperand1,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_name (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_type getter_resultType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_function class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_function ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @location type                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class C_SourceTextInString ;

//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/C_LocationInSource.h"

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_location : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : C_LocationInSource mStartLocationInSource ;
  private : C_LocationInSource mEndLocationInSource ;
  private : C_SourceTextInString * mSourceText ;
  private : bool mIsValid ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG bool isValidAndNotNowhere (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;
  public : C_LocationInSource startLocation (void) const { return mStartLocationInSource ; }
  public : C_LocationInSource endLocation (void) const { return mEndLocationInSource ; }
  public : C_SourceTextInString * sourceText (void) const { return mSourceText ; }

//--------------------------------- Default constructor
  public : GALGAS_location (void) ;

//--------------------------------- Destructor (virtual in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_location (void) ;

//--------------------------------- Handle copy
  public : GALGAS_location (const GALGAS_location & inSource) ;
  public : GALGAS_location & operator = (const GALGAS_location & inSource) ;

//--------------------------------- Native constructor
  public : GALGAS_location (const C_LocationInSource & inStartLocationInSource,
                            const C_LocationInSource & inEndLocationInSource,
                            C_SourceTextInString * inSourceText) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_location extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_location constructor_here (C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : static GALGAS_location constructor_nowhere (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_location & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_column (C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_file (C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isNowhere (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_line (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_locationIndex (C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_locationString (C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_location class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_location ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @object type                                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class cPtr_object ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_object : public AC_GALGAS_root {
//--------------------------------- Private data member
  private : cPtr_object * mSharedObject ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mSharedObject != NULL ; }
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_object (void) ;

//--------------------------------- Constructor from pointer
  public : GALGAS_object (AC_GALGAS_root * inObjectPointer
                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Destructor (virtual in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_object (void) ;

//--------------------------------- Handle copy
  public : GALGAS_object (const GALGAS_object & inSource) ;
  public : GALGAS_object & operator = (const GALGAS_object & inSource) ;

//--------------------------------- Embedded Object
  public : const AC_GALGAS_root * embeddedObject (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_object extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_object & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_type getter_objectDynamicType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_type getter_objectStaticType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_object class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_object ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                     @sint type                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sint : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : int32_t mSIntValue ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mIsValid = false ; }
  public : inline int32_t intValue (void) const { return mSIntValue ; }

//--------------------------------- Default constructor
  public : GALGAS_sint (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_sint constructor_default (LOCATION_ARGS) ;

//--------------------------------- Native constructor
  public : GALGAS_sint (const int32_t inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sint extractObject (const GALGAS_object & inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_sint constructor_max (LOCATION_ARGS) ;

  public : static GALGAS_sint constructor_min (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public : VIRTUAL_IN_DEBUG GALGAS_sint left_shift_operation (const GALGAS_uint inShiftOperand
                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_sint right_shift_operation (const GALGAS_uint inShiftOperand
                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_sint inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public : VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_sint inOperand,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public : VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_sint inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public : VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_sint inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint operator_and (const GALGAS_sint & inOperand
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint operator_or (const GALGAS_sint & inOperand
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint operator_xor (const GALGAS_sint & inOperand
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint add_operation (const GALGAS_sint & inOperand,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- &+ operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint add_operation_no_ovf (const GALGAS_sint & inOperand) const ;

//--------------------------------- &- operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint substract_operation_no_ovf (const GALGAS_sint & inOperand) const ;

//--------------------------------- - operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint substract_operation (const GALGAS_sint & inOperand,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint multiply_operation (const GALGAS_sint & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- &* operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint multiply_operation_no_ovf (const GALGAS_sint & inOperand) const ;

//--------------------------------- / operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint divide_operation (const GALGAS_sint & inOperand,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint divide_operation_no_ovf (const GALGAS_sint & inOperand) const ;

//--------------------------------- mod operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint modulo_operation (const GALGAS_sint & inOperand,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix - operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint operator_unary_minus (C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix &- operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint operator_unary_minus_no_ovf (void) const ;

//--------------------------------- ++, -- operators
  public : VIRTUAL_IN_DEBUG void increment_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void decrement_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- &++, &-- operators
  public : VIRTUAL_IN_DEBUG void increment_operation_no_overflow (void) ;

  public : VIRTUAL_IN_DEBUG void decrement_operation_no_overflow (void) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canAdd (const class GALGAS_sint & constinOperand0
                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canDivide (const class GALGAS_sint & constinOperand0
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canMultiply (const class GALGAS_sint & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canSubstract (const class GALGAS_sint & constinOperand0
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_double (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_sint class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @sint64 type                                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sint_36__34_ : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : int64_t mSInt64Value ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mIsValid = false ; }
  public : inline int64_t int64Value (void) const { return mSInt64Value ; }

//--------------------------------- Default constructor
  public : GALGAS_sint_36__34_ (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_sint_36__34_ constructor_default (LOCATION_ARGS) ;

//--------------------------------- Native constructor
  public : GALGAS_sint_36__34_ (const int64_t inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sint_36__34_ extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_sint_36__34_ constructor_max (LOCATION_ARGS) ;

  public : static GALGAS_sint_36__34_ constructor_min (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ left_shift_operation (const GALGAS_uint inShiftOperand
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ right_shift_operation (const GALGAS_uint inShiftOperand
                                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public : VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public : VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public : VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_sint_36__34_ inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_and (const GALGAS_sint_36__34_ & inOperand
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_or (const GALGAS_sint_36__34_ & inOperand
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_xor (const GALGAS_sint_36__34_ & inOperand
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ add_operation (const GALGAS_sint_36__34_ & inOperand,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- &+ operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ add_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- &- operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ substract_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- - operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ substract_operation (const GALGAS_sint_36__34_ & inOperand,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ multiply_operation (const GALGAS_sint_36__34_ & inOperand,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- &* operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ multiply_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- / operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ divide_operation (const GALGAS_sint_36__34_ & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ divide_operation_no_ovf (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- mod operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ modulo_operation (const GALGAS_sint_36__34_ & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix - operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_unary_minus (C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- prefix &- operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_ operator_unary_minus_no_ovf (void) const ;

//--------------------------------- ++, -- operators
  public : VIRTUAL_IN_DEBUG void increment_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void decrement_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- &++, &-- operators
  public : VIRTUAL_IN_DEBUG void increment_operation_no_overflow (void) ;

  public : VIRTUAL_IN_DEBUG void decrement_operation_no_overflow (void) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sint_36__34_ & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canAdd (const class GALGAS_sint_36__34_ & constinOperand0
                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canDivide (const class GALGAS_sint_36__34_ & constinOperand0
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canMultiply (const class GALGAS_sint_36__34_ & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canSubstract (const class GALGAS_sint_36__34_ & constinOperand0
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_double (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_sint_36__34_ class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_36__34_ ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @string type                                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const GALGAS_string & inString) ;

//----------------------------------------------------------------------------------------------------------------------

AC_OutputStream & operator << (AC_OutputStream & inStream,
                               const GALGAS_lstring & inString) ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string : public AC_GALGAS_root
 {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : C_String mString ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG void drop (void) ;
  public : inline C_String stringValue (void) const { return mString ; }

//--------------------------------- Default constructor
  public : GALGAS_string (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_string constructor_default (LOCATION_ARGS) ;

//--------------------------------- Constructor for making an empty string
  public : static GALGAS_string makeEmptyString (void) ;

//--------------------------------- Native constructor
  public : GALGAS_string (const C_String & inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_string extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_string constructor_CppChar (const class GALGAS_char & inOperand0
                                                     COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_CppLineComment (LOCATION_ARGS) ;

  public : static GALGAS_string constructor_CppSpaceComment (LOCATION_ARGS) ;

  public : static GALGAS_string constructor_CppString (const class GALGAS_string & inOperand0
                                                       COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_CppTitleComment (const class GALGAS_string & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_componentsJoinedByString (const class GALGAS_stringlist & inOperand0,
                                                                      const class GALGAS_string & inOperand1
                                                                      COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_homeDirectory (LOCATION_ARGS) ;

  public : static GALGAS_string constructor_retrieveAndResetTemplateString (C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringWithContentsOfFile (const class GALGAS_string & inOperand0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringWithCurrentDateTime (LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringWithCurrentDirectory (LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringWithEnvironmentVariable (const class GALGAS_string & inOperand0,
                                                                           class C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringWithEnvironmentVariableOrEmpty (const class GALGAS_string & inOperand0
                                                                                  COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringWithSequenceOfCharacters (const class GALGAS_char & inOperand0,
                                                                            const class GALGAS_uint & inOperand1
                                                                            COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringWithSourceFilePath (C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

  public : static GALGAS_string constructor_stringWithSymbolicLinkContents (const class GALGAS_string & inOperand0,
                                                                            class C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_string inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_string add_operation (const GALGAS_string & inOperand,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_string & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_appendSpacesUntilColumn (class GALGAS_uint constinArgument0,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_decIndentation (class GALGAS_uint constinArgument0,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_incIndentation (class GALGAS_uint constinArgument0,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setCapacity (class GALGAS_uint constinArgument0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setCharacterAtIndex (class GALGAS_char constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_makeDirectory (C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_makeDirectoryAndWriteToExecutableFile (class GALGAS_string constinArgument0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_makeDirectoryAndWriteToFile (class GALGAS_string constinArgument0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_makeSymbolicLinkWithPath (class GALGAS_string constinArgument0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_writeToExecutableFile (class GALGAS_string constinArgument0,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_writeToExecutableFileWhenDifferentContents (class GALGAS_string constinArgument0,
                                                                                    class GALGAS_bool & outArgument1,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_writeToFile (class GALGAS_string constinArgument0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_writeToFileWhenDifferentContents (class GALGAS_string constinArgument0,
                                                                          class GALGAS_bool & outArgument1,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods
  public : static void class_method_deleteFile (class GALGAS_string constinArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public : static void class_method_deleteFileIfExists (class GALGAS_string constinArgument0,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public : static void class_method_generateFile (class GALGAS_string constinArgument0,
                                                  class GALGAS_string constinArgument1,
                                                  class GALGAS_string constinArgument2,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : static void class_method_generateFileWithPattern (class GALGAS_string constinArgument0,
                                                             class GALGAS_string constinArgument1,
                                                             class GALGAS_string constinArgument2,
                                                             class GALGAS_string constinArgument3,
                                                             class GALGAS_string constinArgument4,
                                                             class GALGAS_string constinArgument5,
                                                             class GALGAS_string constinArgument6,
                                                             class GALGAS_string constinArgument7,
                                                             class GALGAS_bool constinArgument8,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

  public : static void class_method_removeDirectoryRecursively (class GALGAS_string constinArgument0,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

  public : static void class_method_removeEmptyDirectory (class GALGAS_string constinArgument0,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_HTMLRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_absolutePathFromPath (const class GALGAS_string & constinOperand0
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_capacity (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_char getter_characterAtIndex (const class GALGAS_uint & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_componentsSeparatedByString (const class GALGAS_string & constinOperand0
                                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_containsCharacter (const class GALGAS_char & constinOperand0
                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_containsCharacterInRange (const class GALGAS_char & constinOperand0,
                                                                               const class GALGAS_char & constinOperand1
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_currentColumn (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_decimalUnsignedNumber (C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_directories (const class GALGAS_bool & constinOperand0
                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_directoriesWithExtensions (const class GALGAS_bool & constinOperand0,
                                                                                      const class GALGAS_stringlist & constinOperand1
                                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_directoryExists (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_doesEnvironmentVariableExist (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_fileExists (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_char getter_firstCharacterOrNul (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_here (C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_hiddenFiles (const class GALGAS_bool & constinOperand0
                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_identifierRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isDecimalUnsignedNumber (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isSymbolicLink (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_char getter_lastCharacter (C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_lastPathComponent (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_leftSubString (const class GALGAS_uint & constinOperand0
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_length (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_lowercaseString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_md_35_ (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_nameRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_nativePathWithUnixPath (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_nowhere (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_pathExtension (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_popen (C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_range getter_range (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_regularFiles (const class GALGAS_bool & constinOperand0
                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_regularFilesWithExtensions (const class GALGAS_bool & constinOperand0,
                                                                                       const class GALGAS_stringlist & constinOperand1
                                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_relativePathFromPath (const class GALGAS_string & constinOperand0
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_reversedString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_rightSubString (const class GALGAS_uint & constinOperand0
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByCapitalizingFirstCharacter (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByDeletingLastPathComponent (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByDeletingPathExtension (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByLeftAndRightPadding (const class GALGAS_uint & constinOperand0,
                                                                                    const class GALGAS_char & constinOperand1
                                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByLeftPadding (const class GALGAS_uint & constinOperand0,
                                                                            const class GALGAS_char & constinOperand1
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByRemovingCharacterAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByReplacingStringByString (const class GALGAS_string & constinOperand0,
                                                                                        const class GALGAS_string & constinOperand1,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByRightPadding (const class GALGAS_uint & constinOperand0,
                                                                             const class GALGAS_char & constinOperand1
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByStandardizingPath (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_stringByTrimmingWhiteSpaces (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_subString (const class GALGAS_uint & constinOperand0,
                                                                  const class GALGAS_uint & constinOperand1
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_subStringFromIndex (const class GALGAS_uint & constinOperand0
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_system (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_unixPathWithNativePath (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_uppercaseString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_33__32_Representation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_38_Representation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_utf_38_RepresentationWithoutDelimiters (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_string class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_string ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @stringset type                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class cSharedStringsetRoot ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_stringset : public AC_GALGAS_root
 {
//--------------------------------- Private data members
  private : cSharedStringsetRoot * mSharedRoot ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mSharedRoot != NULL ; }
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_stringset (void) ;

//--------------------------------- Destructor (virtual in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_stringset (void) ;

//--------------------------------- In debug mode : check method
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : void checkStringset (LOCATION_ARGS) const ;
  #endif

//--------------------------------- Insulate
  protected : void insulate (LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_stringset extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_stringset constructor_emptySet (LOCATION_ARGS) ;

  public : static GALGAS_stringset constructor_setWithLStringList (const class GALGAS_lstringlist & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

  public : static GALGAS_stringset constructor_setWithString (const class GALGAS_string & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

  public : static GALGAS_stringset constructor_setWithStringList (const class GALGAS_stringlist & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Handle copy
  public : GALGAS_stringset (const GALGAS_stringset & inSource) ;
  public : GALGAS_stringset & operator = (const GALGAS_stringset & inSource) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_stringset inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_string & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- & operator
  public : VIRTUAL_IN_DEBUG GALGAS_stringset operator_and (const GALGAS_stringset & inOperand
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public : VIRTUAL_IN_DEBUG GALGAS_stringset operator_or (const GALGAS_stringset & inOperand
                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- - operator
  public : VIRTUAL_IN_DEBUG GALGAS_stringset substract_operation (const GALGAS_stringset & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_stringset & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_removeKey (class GALGAS_string inArgument0
                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_anyString (C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_count (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_hasKey (const class GALGAS_string & constinOperand0
                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_stringList (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Enumeration helper methods
  protected : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                              const typeEnumerationOrder inOrder) const ;

//--------------------------------- Friend

  friend class cEnumerator_stringset ;
 
} ; // End of GALGAS_stringset class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_stringset : public cGenericAbstractEnumerator {
  public : cEnumerator_stringset (const GALGAS_stringset & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_string current_key (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_string current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringset ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                     @timer type                                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_timer : public AC_GALGAS_root {
//--------------------------------- Private properties
  private : bool mIsValid ;
  private : C_Timer mTimer ;

//--------------------------------- Accessors
  public : inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG void drop (void) { mIsValid = false ; }

//--------------------------------- Default constructor
  public : GALGAS_timer (void) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_timer extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_timer constructor_start (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_timer & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_resume (LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_stop (LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRunning (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_msFromStart (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_timer class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_timer ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                     @type type                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_type : public AC_GALGAS_root
 {
//--------------------------------- Private data members
  private : const C_galgas_type_descriptor * mTypeDescriptor ;

//--------------------------------- Accessors
  public : inline bool isValid (void) const { return NULL != mTypeDescriptor ; }
  public : inline void drop (void) { mTypeDescriptor = NULL ; }
  public : inline const C_galgas_type_descriptor * typeValue (void) const { return mTypeDescriptor ; }

//--------------------------------- Default constructor
  public : GALGAS_type (void) ;

//--------------------------------- Destructor (virtual in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_type (void) ;

//--------------------------------- Handle copy
  public : GALGAS_type (const GALGAS_type & inSource) ;
  public : GALGAS_type & operator = (const GALGAS_type & inSource) ;

//--------------------------------- Native constructor
  public : GALGAS_type (const C_galgas_type_descriptor * inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_type extractObject (const GALGAS_object & inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_typelist constructor_typeList (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_type & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_hasSuperclass (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_name (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_type getter_superclass (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_type class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_type ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                     @uint type                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uint : public AC_GALGAS_root {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : uint32_t mUIntValue ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mIsValid = false ; }
  public : inline uint32_t uintValue (void) const { return mUIntValue ; }
  public : inline void increment (void) { mUIntValue ++ ; }

//--------------------------------- Default constructor
  public : GALGAS_uint (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_uint constructor_default (LOCATION_ARGS) ;

//--------------------------------- Native constructors
  public : GALGAS_uint (const uint32_t inValue) ;
  public : GALGAS_uint (const bool inValid, const uint32_t inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint extractObject (const GALGAS_object & inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uint constructor_compilationMode (LOCATION_ARGS) ;

  public : static GALGAS_uint constructor_errorCount (LOCATION_ARGS) ;

  public : static GALGAS_uint constructor_max (LOCATION_ARGS) ;

  public : static GALGAS_uint constructor_valueWithMask (const class GALGAS_uint & inOperand0,
                                                         const class GALGAS_uint & inOperand1,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : static GALGAS_uint constructor_warningCount (LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public : VIRTUAL_IN_DEBUG GALGAS_uint left_shift_operation (const GALGAS_uint inShiftOperand
                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_uint right_shift_operation (const GALGAS_uint inShiftOperand
                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_uint inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public : VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_uint inOperand,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public : VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_uint inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public : VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_uint inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint operator_and (const GALGAS_uint & inOperand
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint operator_or (const GALGAS_uint & inOperand
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint operator_xor (const GALGAS_uint & inOperand
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint add_operation (const GALGAS_uint & inOperand,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- &+ operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint add_operation_no_ovf (const GALGAS_uint & inOperand) const ;

//--------------------------------- &- operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint substract_operation_no_ovf (const GALGAS_uint & inOperand) const ;

//--------------------------------- - operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint substract_operation (const GALGAS_uint & inOperand,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint multiply_operation (const GALGAS_uint & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- &* operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint multiply_operation_no_ovf (const GALGAS_uint & inOperand) const ;

//--------------------------------- / operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint divide_operation (const GALGAS_uint & inOperand,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint divide_operation_no_ovf (const GALGAS_uint & inOperand) const ;

//--------------------------------- mod operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint modulo_operation (const GALGAS_uint & inOperand,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) const ;

//--------------------------------- ++, -- operators
  public : VIRTUAL_IN_DEBUG void increment_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void decrement_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- &++, &-- operators
  public : VIRTUAL_IN_DEBUG void increment_operation_no_overflow (void) ;

  public : VIRTUAL_IN_DEBUG void decrement_operation_no_overflow (void) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canAdd (const class GALGAS_uint & constinOperand0
                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canDivide (const class GALGAS_uint & constinOperand0
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canMultiply (const class GALGAS_uint & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canSubstract (const class GALGAS_uint & constinOperand0
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_double (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isInRange (const class GALGAS_range & constinOperand0
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnicodeValueAssigned (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_lsbIndex (C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_oneBitCount (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_significantBitCount (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_uint class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @uint64 type                                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uint_36__34_ : public AC_GALGAS_root
 {
//--------------------------------- Private data members
  private : bool mIsValid ;
  private : uint64_t mUInt64Value ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mIsValid = false ; }
  public : inline uint64_t uint64Value (void) const { return mUInt64Value ; }

//--------------------------------- Default constructor
  public : GALGAS_uint_36__34_ (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_uint_36__34_ constructor_default (LOCATION_ARGS) ;

//--------------------------------- Native constructor
  public : GALGAS_uint_36__34_ (const uint64_t inValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint_36__34_ extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uint_36__34_ constructor_max (LOCATION_ARGS) ;

  public : static GALGAS_uint_36__34_ constructor_uint_36__34_BaseValueWithCompressedBitString (const class GALGAS_string & inOperand0,
                                                                                                class C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) ;

  public : static GALGAS_uint_36__34_ constructor_uint_36__34_MaskWithCompressedBitString (const class GALGAS_string & inOperand0,
                                                                                           class C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) ;

  public : static GALGAS_uint_36__34_ constructor_uint_36__34_WithBitString (const class GALGAS_string & inOperand0,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- << and >> shift operators
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ left_shift_operation (const GALGAS_uint inShiftOperand
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ right_shift_operation (const GALGAS_uint inShiftOperand
                                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_uint_36__34_ inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- -= operator (with expression)
  public : VIRTUAL_IN_DEBUG void minusAssign_operation (const GALGAS_uint_36__34_ inOperand,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- *= operator (with expression)
  public : VIRTUAL_IN_DEBUG void mulAssign_operation (const GALGAS_uint_36__34_ inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- /= operator (with expression)
  public : VIRTUAL_IN_DEBUG void divAssign_operation (const GALGAS_uint_36__34_ inOperand,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- & operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ operator_and (const GALGAS_uint_36__34_ & inOperand
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- | operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ operator_or (const GALGAS_uint_36__34_ & inOperand
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- ^ operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ operator_xor (const GALGAS_uint_36__34_ & inOperand
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- ~ operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ operator_tilde (LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ add_operation (const GALGAS_uint_36__34_ & inOperand,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- &+ operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ add_operation_no_ovf (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- &- operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ substract_operation_no_ovf (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- - operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ substract_operation (const GALGAS_uint_36__34_ & inOperand,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- * operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ multiply_operation (const GALGAS_uint_36__34_ & inOperand,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- &* operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ multiply_operation_no_ovf (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- / operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ divide_operation (const GALGAS_uint_36__34_ & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- &/ operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ divide_operation_no_ovf (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- mod operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ modulo_operation (const GALGAS_uint_36__34_ & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- ++, -- operators
  public : VIRTUAL_IN_DEBUG void increment_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void decrement_operation (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- &++, &-- operators
  public : VIRTUAL_IN_DEBUG void increment_operation_no_overflow (void) ;

  public : VIRTUAL_IN_DEBUG void decrement_operation_no_overflow (void) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uint_36__34_ & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canAdd (const class GALGAS_uint_36__34_ & constinOperand0
                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canDivide (const class GALGAS_uint_36__34_ & constinOperand0
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canMultiply (const class GALGAS_uint_36__34_ & constinOperand0
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_canSubstract (const class GALGAS_uint_36__34_ & constinOperand0
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_double (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_hexString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_uintSlice (const class GALGAS_uint & constinOperand0,
                                                                const class GALGAS_uint & constinOperand1,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_xString (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_uint_36__34_ class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34_ ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                 @functionlist list                                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_functionlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_functionlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_functionlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_function & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_functionlist extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_functionlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_functionlist constructor_listWithValue (const class GALGAS_function & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_functionlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_function & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_functionlist add_operation (const GALGAS_functionlist & inOperand,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_function constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_function & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_function & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_function & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_function constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_function & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_function & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_function getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_functionlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_functionlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_functionlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_functionlist ;
 
} ; // End of GALGAS_functionlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_functionlist : public cGenericAbstractEnumerator {
  public : cEnumerator_functionlist (const GALGAS_functionlist & inEnumeratedObject,
                                     const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_function current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_functionlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_functionlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @luintlist list                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_luintlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_luintlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_luintlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_luint & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_luintlist extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_luintlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_luintlist constructor_listWithValue (const class GALGAS_luint & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_luintlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_luint & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_luintlist add_operation (const GALGAS_luintlist & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_luint constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_luint & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_luint & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_luint & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_luint constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_luint & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_luint & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_luintlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_luintlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_luintlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_luintlist ;
 
} ; // End of GALGAS_luintlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_luintlist : public cGenericAbstractEnumerator {
  public : cEnumerator_luintlist (const GALGAS_luintlist & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_luint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_luintlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_luintlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  @lstringlist list                                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_lstringlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_lstringlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_lstring & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lstringlist extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lstringlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_lstringlist constructor_listWithValue (const class GALGAS_lstring & inOperand0
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_lstringlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_lstringlist add_operation (const GALGAS_lstringlist & inOperand,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_lstring constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_lstringlist ;
 
} ; // End of GALGAS_lstringlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_lstringlist : public cGenericAbstractEnumerator {
  public : cEnumerator_lstringlist (const GALGAS_lstringlist & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_lstringlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  @objectlist list                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_objectlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_objectlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_objectlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_object & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_objectlist extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_objectlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_objectlist constructor_listWithValue (const class GALGAS_object & inOperand0
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_objectlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_object & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_objectlist add_operation (const GALGAS_objectlist & inOperand,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_object constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_object & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_object & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_object & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_object constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_object & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_object & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_object getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_objectlist ;
 
} ; // End of GALGAS_objectlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_objectlist : public cGenericAbstractEnumerator {
  public : cEnumerator_objectlist (const GALGAS_objectlist & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_object current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_objectlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  @stringlist list                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_stringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_stringlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_stringlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_string & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_stringlist extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_stringlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_stringlist constructor_listWithValue (const class GALGAS_string & inOperand0
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_stringlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_string & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_stringlist add_operation (const GALGAS_stringlist & inOperand,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_string constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_string & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_string & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_string & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_string constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_string & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_string & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_stringlist ;
 
} ; // End of GALGAS_stringlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_stringlist : public cGenericAbstractEnumerator {
  public : cEnumerator_stringlist (const GALGAS_stringlist & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_string current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_stringlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @typelist list                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typelist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_typelist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_typelist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_type & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typelist extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_typelist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_typelist constructor_listWithValue (const class GALGAS_type & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_typelist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_type & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_typelist add_operation (const GALGAS_typelist & inOperand,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_type constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_type & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_type & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_type & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_type constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_type & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_type & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_type getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typelist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typelist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_typelist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_typelist ;
 
} ; // End of GALGAS_typelist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_typelist : public cGenericAbstractEnumerator {
  public : cEnumerator_typelist (const GALGAS_typelist & inEnumeratedObject,
                                 const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_type current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_typelist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typelist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @uintlist list                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uintlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_uintlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_uintlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_uint & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uintlist extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uintlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_uintlist constructor_listWithValue (const class GALGAS_uint & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_uintlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_uint & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_uintlist add_operation (const GALGAS_uintlist & inOperand,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_uint constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_uint & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_uint & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_uint & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_uint constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_uint & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_uint & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uintlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_uintlist ;
 
} ; // End of GALGAS_uintlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_uintlist : public cGenericAbstractEnumerator {
  public : cEnumerator_uintlist (const GALGAS_uintlist & inEnumeratedObject,
                                 const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_uint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_uintlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uintlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  @uint64list list                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uint_36__34_list : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_uint_36__34_list (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_uint_36__34_list (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_uint_36__34_ & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint_36__34_list extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uint_36__34_list constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_uint_36__34_list constructor_listWithValue (const class GALGAS_uint_36__34_ & inOperand0
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_uint_36__34_list inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_uint_36__34_ & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_list add_operation (const GALGAS_uint_36__34_list & inOperand,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_uint_36__34_ constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_uint_36__34_ & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_uint_36__34_ & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_uint_36__34_ & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_uint_36__34_ constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_uint_36__34_ & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_uint_36__34_ & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_list getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_uint_36__34_list ;
 
} ; // End of GALGAS_uint_36__34_list class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_uint_36__34_list : public cGenericAbstractEnumerator {
  public : cEnumerator_uint_36__34_list (const GALGAS_uint_36__34_list & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_uint_36__34_ current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_uint_36__34_list_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34_list ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  @bigintlist list                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigintlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_bigintlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_bigintlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_bigint & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_bigintlist extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_bigintlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_bigintlist constructor_listWithValue (const class GALGAS_bigint & inOperand0
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_bigintlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_bigint & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_bigintlist add_operation (const GALGAS_bigintlist & inOperand,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_bigint constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_bigint & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_bigint & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_bigint & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_bigint constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_bigint & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_bigint & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bigintlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bigintlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bigintlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_bigintlist ;
 
} ; // End of GALGAS_bigintlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_bigintlist : public cGenericAbstractEnumerator {
  public : cEnumerator_bigintlist (const GALGAS_bigintlist & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_bigint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_bigintlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bigintlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  @lbigintlist list                                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lbigintlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_lbigintlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_lbigintlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_lbigint & in_mValue
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lbigintlist extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lbigintlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_lbigintlist constructor_listWithValue (const class GALGAS_lbigint & inOperand0
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_lbigintlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lbigint & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_lbigintlist add_operation (const GALGAS_lbigintlist & inOperand,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lbigint constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lbigint & outArgument0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lbigint & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lbigint & outArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValueAtIndex (class GALGAS_lbigint constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_lbigint & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_lbigint & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lbigint getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lbigintlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lbigintlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lbigintlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_lbigintlist ;
 
} ; // End of GALGAS_lbigintlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_lbigintlist : public cGenericAbstractEnumerator {
  public : cEnumerator_lbigintlist (const GALGAS_lbigintlist & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lbigint current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_lbigintlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lbigintlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  @2stringlist list                                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS__32_stringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS__32_stringlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS__32_stringlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_string & in_mValue_30_,
                                                  const class GALGAS_string & in_mValue_31_
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS__32_stringlist extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS__32_stringlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS__32_stringlist constructor_listWithValue (const class GALGAS_string & inOperand0,
                                                                   const class GALGAS_string & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS__32_stringlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_string & inOperand0,
                                                      const class GALGAS_string & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS__32_stringlist add_operation (const GALGAS__32_stringlist & inOperand,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_string constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       class GALGAS_uint constinArgument2,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_string & outArgument0,
                                                  class GALGAS_string & outArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_string & outArgument0,
                                                 class GALGAS_string & outArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_string & outArgument0,
                                                       class GALGAS_string & outArgument1,
                                                       class GALGAS_uint constinArgument2,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValue_30_AtIndex (class GALGAS_string constinArgument0,
                                                              class GALGAS_uint constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValue_31_AtIndex (class GALGAS_string constinArgument0,
                                                              class GALGAS_uint constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_string & outArgument0,
                                               class GALGAS_string & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_string & outArgument0,
                                              class GALGAS_string & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mValue_30_AtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mValue_31_AtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS__32_stringlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS__32_stringlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS__32_stringlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator__32_stringlist ;
 
} ; // End of GALGAS__32_stringlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator__32_stringlist : public cGenericAbstractEnumerator {
  public : cEnumerator__32_stringlist (const GALGAS__32_stringlist & inEnumeratedObject,
                                       const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_string current_mValue_30_ (LOCATION_ARGS) const ;
  public : class GALGAS_string current_mValue_31_ (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS__32_stringlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_stringlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                 @2lstringlist list                                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS__32_lstringlist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS__32_lstringlist (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS__32_lstringlist (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_lstring & in_mValue_30_,
                                                  const class GALGAS_lstring & in_mValue_31_
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS__32_lstringlist extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS__32_lstringlist constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS__32_lstringlist constructor_listWithValue (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_lstring & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS__32_lstringlist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_lstring & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS__32_lstringlist add_operation (const GALGAS__32_lstringlist & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                       class GALGAS_lstring constinArgument1,
                                                       class GALGAS_uint constinArgument2,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                  class GALGAS_lstring & outArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_lstring & outArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                       class GALGAS_lstring & outArgument1,
                                                       class GALGAS_uint constinArgument2,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValue_30_AtIndex (class GALGAS_lstring constinArgument0,
                                                              class GALGAS_uint constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void setter_setMValue_31_AtIndex (class GALGAS_lstring constinArgument0,
                                                              class GALGAS_uint constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                               class GALGAS_lstring & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                              class GALGAS_lstring & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mValue_30_AtIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mValue_31_AtIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS__32_lstringlist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS__32_lstringlist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS__32_lstringlist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator__32_lstringlist ;
 
} ; // End of GALGAS__32_lstringlist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator__32_lstringlist : public cGenericAbstractEnumerator {
  public : cEnumerator__32_lstringlist (const GALGAS__32_lstringlist & inEnumeratedObject,
                                        const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_mValue_30_ (LOCATION_ARGS) const ;
  public : class GALGAS_lstring current_mValue_31_ (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS__32_lstringlist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @lbool struct                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lbool : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_bool mAttribute_bool ;
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_lbool constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_lbool (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_lbool (void) ;

//--------------------------------- Native constructor
  public : GALGAS_lbool (const GALGAS_bool & in_bool,
                         const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lbool extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lbool constructor_new (const class GALGAS_bool & inOperand0,
                                                const class GALGAS_location & inOperand1
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_lbool & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_bool (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_lbool class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lbool ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @lbigint struct                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lbigint : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_bigint mAttribute_bigint ;
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_lbigint constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_lbigint (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_lbigint (void) ;

//--------------------------------- Native constructor
  public : GALGAS_lbigint (const GALGAS_bigint & in_bigint,
                           const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lbigint extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lbigint constructor_new (const class GALGAS_bigint & inOperand0,
                                                  const class GALGAS_location & inOperand1
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_lbigint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_bigint (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_lbigint class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lbigint ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @lchar struct                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lchar : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_char mAttribute_char ;
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_lchar constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_lchar (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_lchar (void) ;

//--------------------------------- Native constructor
  public : GALGAS_lchar (const GALGAS_char & in_char,
                         const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lchar extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lchar constructor_new (const class GALGAS_char & inOperand0,
                                                const class GALGAS_location & inOperand1
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_lchar & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_char getter_char (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_lchar class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lchar ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @ldouble struct                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_ldouble : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_double mAttribute_double ;
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_ldouble constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_ldouble (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_ldouble (void) ;

//--------------------------------- Native constructor
  public : GALGAS_ldouble (const GALGAS_double & in_double,
                           const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_ldouble extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_ldouble constructor_new (const class GALGAS_double & inOperand0,
                                                  const class GALGAS_location & inOperand1
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_ldouble & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_double (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_ldouble class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ldouble ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @lsint struct                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lsint : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_sint mAttribute_sint ;
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_lsint constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_lsint (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_lsint (void) ;

//--------------------------------- Native constructor
  public : GALGAS_lsint (const GALGAS_sint & in_sint,
                         const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lsint extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lsint constructor_new (const class GALGAS_sint & inOperand0,
                                                const class GALGAS_location & inOperand1
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_lsint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_sint (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_lsint class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lsint ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                @lsint_36__34_ struct                                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lsint_36__34_ : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_sint_36__34_ mAttribute_sint_36__34_ ;
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_lsint_36__34_ constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_lsint_36__34_ (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_lsint_36__34_ (void) ;

//--------------------------------- Native constructor
  public : GALGAS_lsint_36__34_ (const GALGAS_sint_36__34_ & in_sint_36__34_,
                                 const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lsint_36__34_ extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lsint_36__34_ constructor_new (const class GALGAS_sint_36__34_ & inOperand0,
                                                        const class GALGAS_location & inOperand1
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_lsint_36__34_ & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_sint_36__34_ (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_lsint_36__34_ class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lsint_36__34_ ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @lstring struct                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_string mAttribute_string ;
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_lstring constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_lstring (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_lstring (void) ;

//--------------------------------- Native constructor
  public : GALGAS_lstring (const GALGAS_string & in_string,
                           const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lstring extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lstring constructor_new (const class GALGAS_string & inOperand0,
                                                  const class GALGAS_location & inOperand1
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_lstring & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_string (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_lstring class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstring ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @luint struct                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_luint : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_uint mAttribute_uint ;
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_luint constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_luint (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_luint (void) ;

//--------------------------------- Native constructor
  public : GALGAS_luint (const GALGAS_uint & in_uint,
                         const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_luint extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_luint constructor_new (const class GALGAS_uint & inOperand0,
                                                const class GALGAS_location & inOperand1
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_luint & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_uint (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_luint class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_luint ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                @luint_36__34_ struct                                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_luint_36__34_ : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_uint_36__34_ mAttribute_uint_36__34_ ;
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_luint_36__34_ constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_luint_36__34_ (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_luint_36__34_ (void) ;

//--------------------------------- Native constructor
  public : GALGAS_luint_36__34_ (const GALGAS_uint_36__34_ & in_uint_36__34_,
                                 const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_luint_36__34_ extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_luint_36__34_ constructor_new (const class GALGAS_uint_36__34_ & inOperand0,
                                                        const class GALGAS_location & inOperand1
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_luint_36__34_ & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_uint_36__34_ (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_luint_36__34_ class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_luint_36__34_ ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @range struct                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_range : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_uint mAttribute_start ;
  public : GALGAS_uint mAttribute_length ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_range constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_range (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_range (void) ;

//--------------------------------- Native constructor
  public : GALGAS_range (const GALGAS_uint & in_start,
                         const GALGAS_uint & in_length) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_range extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_range constructor_new (const class GALGAS_uint & inOperand0,
                                                const class GALGAS_uint & inOperand1
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_range & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_length (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_start (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_range class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_range ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                           @functionlist_2D_element struct                                           *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_functionlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_function mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_functionlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_functionlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_functionlist_2D_element (const GALGAS_function & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_functionlist_2D_element extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_functionlist_2D_element constructor_new (const class GALGAS_function & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_functionlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_function getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_functionlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_functionlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            @luintlist_2D_element struct                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_luintlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_luint mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_luintlist_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_luintlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_luintlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_luintlist_2D_element (const GALGAS_luint & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_luintlist_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_luintlist_2D_element constructor_new (const class GALGAS_luint & inOperand0
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_luintlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_luint getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_luintlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_luintlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                           @lstringlist_2D_element struct                                            *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstringlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_lstringlist_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_lstringlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_lstringlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_lstringlist_2D_element (const GALGAS_lstring & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lstringlist_2D_element extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lstringlist_2D_element constructor_new (const class GALGAS_lstring & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_lstringlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_lstringlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            @objectlist_2D_element struct                                            *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_objectlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_object mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_objectlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_objectlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_objectlist_2D_element (const GALGAS_object & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_objectlist_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_objectlist_2D_element constructor_new (const class GALGAS_object & inOperand0
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_objectlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_object getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_objectlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            @stringlist_2D_element struct                                            *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_stringlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_string mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_stringlist_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_stringlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_stringlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_stringlist_2D_element (const GALGAS_string & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_stringlist_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_stringlist_2D_element constructor_new (const class GALGAS_string & inOperand0
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_stringlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_stringlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             @typelist_2D_element struct                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_typelist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_type mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_typelist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_typelist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_typelist_2D_element (const GALGAS_type & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_typelist_2D_element extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_typelist_2D_element constructor_new (const class GALGAS_type & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_typelist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_type getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_typelist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_typelist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             @uintlist_2D_element struct                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uintlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_uint mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_uintlist_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_uintlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_uintlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_uintlist_2D_element (const GALGAS_uint & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uintlist_2D_element extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uintlist_2D_element constructor_new (const class GALGAS_uint & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uintlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_uintlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uintlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                         @uint_36__34_list_2D_element struct                                         *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uint_36__34_list_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_uint_36__34_ mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_uint_36__34_list_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_uint_36__34_list_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_uint_36__34_list_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_uint_36__34_list_2D_element (const GALGAS_uint_36__34_ & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint_36__34_list_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uint_36__34_list_2D_element constructor_new (const class GALGAS_uint_36__34_ & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uint_36__34_list_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_uint_36__34_list_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34_list_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            @bigintlist_2D_element struct                                            *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigintlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_bigint mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_bigintlist_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_bigintlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_bigintlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_bigintlist_2D_element (const GALGAS_bigint & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_bigintlist_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_bigintlist_2D_element constructor_new (const class GALGAS_bigint & inOperand0
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_bigintlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bigint getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_bigintlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_bigintlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                           @lbigintlist_2D_element struct                                            *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lbigintlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lbigint mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_lbigintlist_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_lbigintlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_lbigintlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_lbigintlist_2D_element (const GALGAS_lbigint & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lbigintlist_2D_element extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lbigintlist_2D_element constructor_new (const class GALGAS_lbigint & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_lbigintlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lbigint getter_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_lbigintlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lbigintlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                          @_32_stringlist_2D_element struct                                          *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS__32_stringlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_string mAttribute_mValue_30_ ;
  public : GALGAS_string mAttribute_mValue_31_ ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS__32_stringlist_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS__32_stringlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS__32_stringlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS__32_stringlist_2D_element (const GALGAS_string & in_mValue_30_,
                                             const GALGAS_string & in_mValue_31_) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS__32_stringlist_2D_element extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS__32_stringlist_2D_element constructor_new (const class GALGAS_string & inOperand0,
                                                                    const class GALGAS_string & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS__32_stringlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mValue_30_ (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mValue_31_ (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS__32_stringlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_stringlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                         @_32_lstringlist_2D_element struct                                          *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

class GALGAS__32_lstringlist_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_mValue_30_ ;
  public : GALGAS_lstring mAttribute_mValue_31_ ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS__32_lstringlist_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS__32_lstringlist_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS__32_lstringlist_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS__32_lstringlist_2D_element (const GALGAS_lstring & in_mValue_30_,
                                              const GALGAS_lstring & in_mValue_31_) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS__32_lstringlist_2D_element extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS__32_lstringlist_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                     const class GALGAS_lstring & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS__32_lstringlist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mValue_30_ (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mValue_31_ (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS__32_lstringlist_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS__32_lstringlist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/cCollectionElement.h"

//----------------------------------------------------------------------------------------------------------------------

class cMapElement : public cCollectionElement {
//--- Attribut
  public : GALGAS_lstring mAttribute_lkey ;

//--- Default constructor
  public : cMapElement (const GALGAS_lstring & inLKey
                        COMMA_LOCATION_ARGS) ;

//--- No copy
  private : cMapElement (const cMapElement &) ;
  private : cMapElement & operator = (const cMapElement &) ;
} ;

//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/cSortedListElement.h"
#include "galgas2/capSortedListElement.h"
#include "galgas2/C_galgas_function_descriptor.h"
#include "galgas2/cObjectArray.h"


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2
#endif
