#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-8.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'trueFalse'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_trueFalse (const class GALGAS_bool & constinArgument0,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'TrueFalse'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_TrueFalse (const class GALGAS_bool & constinArgument0,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'yesNo'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_yesNo (const class GALGAS_bool & constinArgument0,
                                    class C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'TRUEFALSE'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_TRUEFALSE (const class GALGAS_bool & constinArgument0,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'listOfSize'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_list function_listOfSize (class GALGAS_bigint inArgument0,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'version'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_version (class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'majorVersion'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_majorVersion (class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'minorVersion'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_minorVersion (class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'revision'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_revision (class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'currentDir'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_currentDir (class C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'homeDir'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_homeDir (class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'currentDateTime'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_currentDateTime (class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max8bitsUnsignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_38_bitsUnsignedInt (class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max8bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_38_bitsSignedInt (class C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'min8bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_min_38_bitsSignedInt (class C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max16bitsUnsignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_31__36_bitsUnsignedInt (class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max16bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_31__36_bitsSignedInt (class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'min16bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_min_31__36_bitsSignedInt (class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max32bitsUnsignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_33__32_bitsUnsignedInt (class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max32bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_33__32_bitsSignedInt (class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'min32bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_min_33__32_bitsSignedInt (class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max64bitsUnsignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_36__34_bitsUnsignedInt (class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'max64bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_max_36__34_bitsSignedInt (class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'min64bitsSignedInt'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint function_min_36__34_bitsSignedInt (class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'pi'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_double function_pi (class C_Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'underline'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_underline (class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'blink'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_blink (class C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'black'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_black (class C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'green'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_green (class C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'yellow'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_yellow (class C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'blue'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_blue (class C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'magenta'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_magenta (class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'cyan'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_cyan (class C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'darkred'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_darkred (class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'darkgreen'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_darkgreen (class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'darkyellow'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_darkyellow (class C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'darkblue'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_darkblue (class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'darkmagenta'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_darkmagenta (class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'darkcyan'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_darkcyan (class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'white'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_white (class C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'checkEnums'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool function_checkEnums (const class GALGAS_impEnumType & constinArgument0,
                                       const class GALGAS_impEnumType & constinArgument1,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'checkRanged'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool function_checkRanged (const class GALGAS_impRangedType & constinArgument0,
                                        const class GALGAS_impRangedType & constinArgument1,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'floatOrError'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_double function_floatOrError (class GALGAS_object_5F_t inArgument0,
                                           class GALGAS_string inArgument1,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'sint32OrError'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sint function_sint_33__32_OrError (class GALGAS_object_5F_t inArgument0,
                                                class GALGAS_string inArgument1,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'sint64OrError'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sint_36__34_ function_sint_36__34_OrError (class GALGAS_object_5F_t inArgument0,
                                                        class GALGAS_string inArgument1,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'uint32OrError'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uint function_uint_33__32_OrError (class GALGAS_object_5F_t inArgument0,
                                                class GALGAS_string inArgument1,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'uint64OrError'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uint_36__34_ function_uint_36__34_OrError (class GALGAS_object_5F_t inArgument0,
                                                        class GALGAS_string inArgument1,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithUInt32List'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_stringWithUInt_33__32_List (const class GALGAS_uint_33__32_List & constinArgument0,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithUInt64List'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_stringWithUInt_36__34_List (const class GALGAS_uint_36__34_List & constinArgument0,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithSInt32List'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_stringWithSInt_33__32_List (const class GALGAS_sint_33__32_List & constinArgument0,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithSInt64List'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_stringWithSInt_36__34_List (const class GALGAS_sint_36__34_List & constinArgument0,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringWithFloatList'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_stringWithFloatList (const class GALGAS_floatList & constinArgument0,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'uint32ListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uint_33__32_List function_uint_33__32_ListWithNumberList (const class GALGAS_numberList & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'sint32ListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sint_33__32_List function_sint_33__32_ListWithNumberList (const class GALGAS_numberList & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'uint64ListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_uint_36__34_List function_uint_36__34_ListWithNumberList (const class GALGAS_numberList & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'sint64ListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sint_36__34_List function_sint_36__34_ListWithNumberList (const class GALGAS_numberList & constinArgument0,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'floatListWithNumberList'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_floatList function_floatListWithNumberList (const class GALGAS_numberList & constinArgument0,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'multiError'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_multiError (class GALGAS_locationList inArgument0,
                         class GALGAS_string inArgument1,
                         class C_Compiler * inCompiler
                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'setDefaultsForType'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_setDefaultsForType (const class GALGAS_implementationObjectMap constinArgument0,
                                 class GALGAS_objectAttributes & ioArgument1,
                                 class C_Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

