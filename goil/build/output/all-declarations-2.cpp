#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-2.h"


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'dummyFunction'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tfunction function_dummyFunction (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tfunction result_fct ; // Returned variable
  result_fct = GALGAS_Tfunction::constructor_new (GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 81))  COMMA_SOURCE_FILE ("template_semantics.galgas", 81)), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 81)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("template_semantics.galgas", 81)) ;
//---
  return result_fct ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_dummyFunction [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_dummyFunction (C_Compiler * inCompiler,
                                                              const cObjectArray & /* inEffectiveParameterArray */,
                                                              const GALGAS_location & /* inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  return function_dummyFunction (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_dummyFunction ("dummyFunction",
                                                               functionWithGenericHeader_dummyFunction,
                                                               & kTypeDescriptor_GALGAS_Tfunction,
                                                               0,
                                                               functionArgs_dummyFunction) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'valueWithBool'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tvalue function_valueWithBool (const GALGAS_bool & constinArgument_inValue,
                                      const GALGAS_lstring & constinArgument_description,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (constinArgument_inValue.getter_sint_36__34_ (SOURCE_FILE ("template_semantics.galgas", 123)), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 126)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 127)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 128)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 122)) ;
//---
  return result_outValue ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueWithBool [3] = {
  & kTypeDescriptor_GALGAS_bool,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueWithBool (C_Compiler * inCompiler,
                                                              const cObjectArray & inEffectiveParameterArray,
                                                              const GALGAS_location & /* §§ inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithBool (operand0,
                                 operand1,
                                 inCompiler
                                 COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueWithBool ("valueWithBool",
                                                               functionWithGenericHeader_valueWithBool,
                                                               & kTypeDescriptor_GALGAS_Tvalue,
                                                               2,
                                                               functionArgs_valueWithBool) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'valueWithUnsigned'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tvalue function_valueWithUnsigned (const GALGAS_uint_36__34_ & constinArgument_inValue,
                                          const GALGAS_lstring & constinArgument_description,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (constinArgument_inValue.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 139)), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 142)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 143)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 144)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 138)) ;
//---
  return result_outValue ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueWithUnsigned [3] = {
  & kTypeDescriptor_GALGAS_uint_36__34_,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueWithUnsigned (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* §§ inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34_ operand0 = GALGAS_uint_36__34_::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                           inCompiler
                                                                           COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithUnsigned (operand0,
                                     operand1,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueWithUnsigned ("valueWithUnsigned",
                                                                   functionWithGenericHeader_valueWithUnsigned,
                                                                   & kTypeDescriptor_GALGAS_Tvalue,
                                                                   2,
                                                                   functionArgs_valueWithUnsigned) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'valueWithSigned'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tvalue function_valueWithSigned (const GALGAS_sint_36__34_ & constinArgument_inValue,
                                        const GALGAS_lstring & constinArgument_description,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (constinArgument_inValue, GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 158)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 159)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 160)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 154)) ;
//---
  return result_outValue ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueWithSigned [3] = {
  & kTypeDescriptor_GALGAS_sint_36__34_,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueWithSigned (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* §§ inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_sint_36__34_ operand0 = GALGAS_sint_36__34_::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                           inCompiler
                                                                           COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithSigned (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueWithSigned ("valueWithSigned",
                                                                 functionWithGenericHeader_valueWithSigned,
                                                                 & kTypeDescriptor_GALGAS_Tvalue,
                                                                 2,
                                                                 functionArgs_valueWithSigned) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'valueWithFloat'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tvalue function_valueWithFloat (const GALGAS_double & constinArgument_inValue,
                                       const GALGAS_lstring & constinArgument_description,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_sint_36__34_ ((int64_t) 0LL), constinArgument_inValue, GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 174)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 175)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 176)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 170)) ;
//---
  return result_outValue ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueWithFloat [3] = {
  & kTypeDescriptor_GALGAS_double,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueWithFloat (C_Compiler * inCompiler,
                                                               const cObjectArray & inEffectiveParameterArray,
                                                               const GALGAS_location & /* §§ inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_double operand0 = GALGAS_double::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithFloat (operand0,
                                  operand1,
                                  inCompiler
                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueWithFloat ("valueWithFloat",
                                                                functionWithGenericHeader_valueWithFloat,
                                                                & kTypeDescriptor_GALGAS_Tvalue,
                                                                2,
                                                                functionArgs_valueWithFloat) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'valueWithString'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tvalue function_valueWithString (const GALGAS_string & constinArgument_inValue,
                                        const GALGAS_lstring & constinArgument_description,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_sint_36__34_ ((int64_t) 0LL), GALGAS_double (0), constinArgument_inValue, GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 190)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 191)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 192)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 186)) ;
//---
  return result_outValue ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueWithString [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueWithString (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* §§ inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithString (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueWithString ("valueWithString",
                                                                 functionWithGenericHeader_valueWithString,
                                                                 & kTypeDescriptor_GALGAS_Tvalue,
                                                                 2,
                                                                 functionArgs_valueWithString) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'valueWithStruct'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tvalue function_valueWithStruct (const GALGAS_TfieldMap & constinArgument_inValue,
                                        const GALGAS_lstring & constinArgument_description,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_sint_36__34_ ((int64_t) 0LL), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 206)), constinArgument_inValue, function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 208)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 202)) ;
//---
  return result_outValue ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueWithStruct [3] = {
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueWithStruct (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* §§ inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMap operand0 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithStruct (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueWithStruct ("valueWithStruct",
                                                                 functionWithGenericHeader_valueWithStruct,
                                                                 & kTypeDescriptor_GALGAS_Tvalue,
                                                                 2,
                                                                 functionArgs_valueWithStruct) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'valueWithMap'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tvalue function_valueWithMap (const GALGAS_TfieldMap & constinArgument_inValue,
                                     const GALGAS_lstring & constinArgument_description,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_sint_36__34_ ((int64_t) 0LL), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 222)), constinArgument_inValue, function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 224)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 218)) ;
//---
  return result_outValue ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueWithMap [3] = {
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueWithMap (C_Compiler * inCompiler,
                                                             const cObjectArray & inEffectiveParameterArray,
                                                             const GALGAS_location & /* §§ inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMap operand0 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithMap (operand0,
                                operand1,
                                inCompiler
                                COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueWithMap ("valueWithMap",
                                                              functionWithGenericHeader_valueWithMap,
                                                              & kTypeDescriptor_GALGAS_Tvalue,
                                                              2,
                                                              functionArgs_valueWithMap) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'valueWithList'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tvalue function_valueWithList (const GALGAS_TfieldMapList & constinArgument_inValue,
                                      const GALGAS_lstring & constinArgument_description,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_sint_36__34_ ((int64_t) 0LL), GALGAS_double (0), GALGAS_string::makeEmptyString (), constinArgument_inValue, GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 239)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 240)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 234)) ;
//---
  return result_outValue ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueWithList [3] = {
  & kTypeDescriptor_GALGAS_TfieldMapList,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueWithList (C_Compiler * inCompiler,
                                                              const cObjectArray & inEffectiveParameterArray,
                                                              const GALGAS_location & /* §§ inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMapList operand0 = GALGAS_TfieldMapList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithList (operand0,
                                 operand1,
                                 inCompiler
                                 COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueWithList ("valueWithList",
                                                               functionWithGenericHeader_valueWithList,
                                                               & kTypeDescriptor_GALGAS_Tvalue,
                                                               2,
                                                               functionArgs_valueWithList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'valueWithVoid'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_Tvalue function_valueWithVoid (C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_sint_36__34_ ((int64_t) 0LL), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 252)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 253)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 254)), GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 255))  COMMA_SOURCE_FILE ("template_semantics.galgas", 255))  COMMA_SOURCE_FILE ("template_semantics.galgas", 248)) ;
//---
  return result_outValue ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueWithVoid [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueWithVoid (C_Compiler * inCompiler,
                                                              const cObjectArray & /* inEffectiveParameterArray */,
                                                              const GALGAS_location & /* inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  return function_valueWithVoid (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueWithVoid ("valueWithVoid",
                                                               functionWithGenericHeader_valueWithVoid,
                                                               & kTypeDescriptor_GALGAS_Tvalue,
                                                               0,
                                                               functionArgs_valueWithVoid) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'addBoolValue'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addBoolValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                           const GALGAS_lstring constinArgument_inVariableName,
                           const GALGAS_bool constinArgument_inValue,
                           const GALGAS_lstring constinArgument_description,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.modifier_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_semantics.galgas", 267)), function_valueWithBool (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 268)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 265)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'addUnsignedValue'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addUnsignedValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                               const GALGAS_lstring constinArgument_inVariableName,
                               const GALGAS_uint_36__34_ constinArgument_inValue,
                               const GALGAS_lstring constinArgument_description,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.modifier_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_semantics.galgas", 281)), function_valueWithUnsigned (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 282)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 279)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'addSignedValue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addSignedValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                             const GALGAS_lstring constinArgument_inVariableName,
                             const GALGAS_sint_36__34_ constinArgument_inValue,
                             const GALGAS_lstring constinArgument_description,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.modifier_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_semantics.galgas", 296)), function_valueWithSigned (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 297)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 294)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'addFloatValue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addFloatValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                            const GALGAS_lstring constinArgument_inVariableName,
                            const GALGAS_double constinArgument_inValue,
                            const GALGAS_lstring constinArgument_description,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.modifier_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_floatType (SOURCE_FILE ("template_semantics.galgas", 311)), function_valueWithFloat (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 312)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 309)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'addLUnsignedValue'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addLUnsignedValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                                const GALGAS_string constinArgument_inVariableName,
                                const GALGAS_luint_36__34_ constinArgument_inValue,
                                const GALGAS_lstring constinArgument_description,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_addUnsignedValue (ioArgument_ioTemplateVariableMap, GALGAS_lstring::constructor_new (constinArgument_inVariableName, constinArgument_inValue.getter_location (SOURCE_FILE ("template_semantics.galgas", 324))  COMMA_SOURCE_FILE ("template_semantics.galgas", 324)), constinArgument_inValue.getter_uint_36__34_ (SOURCE_FILE ("template_semantics.galgas", 324)), constinArgument_description, inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 324)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'addStringValue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addStringValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                             const GALGAS_lstring constinArgument_inVariableName,
                             const GALGAS_string constinArgument_inValue,
                             const GALGAS_lstring constinArgument_description,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.modifier_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_semantics.galgas", 336)), function_valueWithString (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 334)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'addLStringValue'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addLStringValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                              const GALGAS_string constinArgument_inVariableName,
                              const GALGAS_lstring constinArgument_inValue,
                              const GALGAS_lstring constinArgument_description,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_addStringValue (ioArgument_ioTemplateVariableMap, GALGAS_lstring::constructor_new (constinArgument_inVariableName, constinArgument_inValue.getter_location (SOURCE_FILE ("template_semantics.galgas", 349))  COMMA_SOURCE_FILE ("template_semantics.galgas", 349)), constinArgument_inValue.getter_string (SOURCE_FILE ("template_semantics.galgas", 349)), constinArgument_description, inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 349)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'addListValue'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addListValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                           const GALGAS_lstring constinArgument_inVariableName,
                           const GALGAS_TfieldMapList constinArgument_inValue,
                           const GALGAS_lstring constinArgument_description,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.modifier_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_semantics.galgas", 361)), GALGAS_Tvalue::constructor_new (GALGAS_sint_36__34_ ((int64_t) 0LL), GALGAS_double (0), GALGAS_string::makeEmptyString (), constinArgument_inValue, GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 362)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 362)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 362)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 359)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'addStructValue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addStructValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                             const GALGAS_lstring constinArgument_inVariableName,
                             const GALGAS_TfieldMap constinArgument_inValue,
                             const GALGAS_lstring constinArgument_description,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.modifier_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 376)), GALGAS_Tvalue::constructor_new (GALGAS_sint_36__34_ ((int64_t) 0LL), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 377)), constinArgument_inValue, function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 377)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 377)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 374)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'addEnumValue'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addEnumValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                           const GALGAS_lstring constinArgument_inVariableName,
                           const GALGAS_string constinArgument_inValue,
                           const GALGAS_lstring constinArgument_description,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.modifier_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_enumType (SOURCE_FILE ("template_semantics.galgas", 390)), function_valueWithString (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 391)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 388)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'printPath'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_printPath (const GALGAS_TvarPath constinArgument_path,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_TvarPath enumerator_10137 (constinArgument_path, kEnumeration_up) ;
  while (enumerator_10137.hasCurrentObject ()) {
    inCompiler->printMessage (enumerator_10137.current_item (HERE).getter_string (SOURCE_FILE ("template_semantics.galgas", 409))  COMMA_SOURCE_FILE ("template_semantics.galgas", 409)) ;
    const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, enumerator_10137.current_key (HERE).getter_string (SOURCE_FILE ("template_semantics.galgas", 410)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("[\"").add_operation (enumerator_10137.current_key (HERE).getter_string (SOURCE_FILE ("template_semantics.galgas", 411)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 411)).add_operation (GALGAS_string ("\"]"), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 411))  COMMA_SOURCE_FILE ("template_semantics.galgas", 411)) ;
    }
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, enumerator_10137.current_idx (HERE).getter_sint (SOURCE_FILE ("template_semantics.galgas", 413)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 413)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      inCompiler->printMessage (GALGAS_string ("[").add_operation (enumerator_10137.current_idx (HERE).mAttribute_sint.getter_string (SOURCE_FILE ("template_semantics.galgas", 414)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 414)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 414))  COMMA_SOURCE_FILE ("template_semantics.galgas", 414)) ;
    }
    if (enumerator_10137.hasNextObject ()) {
      inCompiler->printMessage (GALGAS_string ("::")  COMMA_SOURCE_FILE ("template_semantics.galgas", 416)) ;
    }
    enumerator_10137.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'searchField'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_searchField (GALGAS_TvarPath inArgument_variable,
                          const GALGAS_TfieldMap constinArgument_inTemplateFieldMap,
                          GALGAS_Ttype & outArgument_variableType,
                          GALGAS_Tvalue & outArgument_variableValue,
                          GALGAS_location & outArgument_variableLocation,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_variableType.drop () ; // Release 'out' argument
  outArgument_variableValue.drop () ; // Release 'out' argument
  outArgument_variableLocation.drop () ; // Release 'out' argument
  GALGAS_lstring var_field ;
  GALGAS_lstring var_key ;
  GALGAS_lsint var_idx ;
  outArgument_variableLocation = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 431)) ;
  {
  inArgument_variable.modifier_popFirst (var_field, var_key, var_idx, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 432)) ;
  }
  constinArgument_inTemplateFieldMap.method_searchKey (var_field, outArgument_variableType, outArgument_variableValue, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 433)) ;
  const enumGalgasBool test_0 = constinArgument_inTemplateFieldMap.getter_hasKey (var_field.getter_string (SOURCE_FILE ("template_semantics.galgas", 434)) COMMA_SOURCE_FILE ("template_semantics.galgas", 434)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_variableLocation = constinArgument_inTemplateFieldMap.getter_locationForKey (var_field.getter_string (SOURCE_FILE ("template_semantics.galgas", 435)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 435)) ;
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_key.getter_string (SOURCE_FILE ("template_semantics.galgas", 437)).objectCompare (GALGAS_string::makeEmptyString ())).operator_and (GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_semantics.galgas", 437)))) COMMA_SOURCE_FILE ("template_semantics.galgas", 437)).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_TfieldMap var_mapMap = outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 438)) ;
    var_mapMap.method_searchKey (var_key, outArgument_variableType, outArgument_variableValue, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 439)) ;
    const enumGalgasBool test_2 = var_mapMap.getter_hasKey (var_key.getter_string (SOURCE_FILE ("template_semantics.galgas", 440)) COMMA_SOURCE_FILE ("template_semantics.galgas", 440)).boolEnum () ;
    if (kBoolTrue == test_2) {
      outArgument_variableLocation = var_mapMap.getter_locationForKey (var_key.getter_string (SOURCE_FILE ("template_semantics.galgas", 441)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 441)) ;
    }
  }else if (kBoolFalse == test_1) {
    const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, var_idx.getter_sint (SOURCE_FILE ("template_semantics.galgas", 443)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 443)))).operator_and (GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_semantics.galgas", 443)))) COMMA_SOURCE_FILE ("template_semantics.galgas", 443)).boolEnum () ;
    if (kBoolTrue == test_3) {
      GALGAS_TfieldMapList var_mapList = outArgument_variableValue.getter_mMapListValue (SOURCE_FILE ("template_semantics.galgas", 444)) ;
      const enumGalgasBool test_4 = GALGAS_bool (kIsStrictInf, var_idx.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 445)).objectCompare (var_mapList.getter_length (SOURCE_FILE ("template_semantics.galgas", 445)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        outArgument_variableValue.mAttribute_mStructValue = var_mapList.getter_mMapAtIndex (var_idx.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 446)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 446)) ;
        outArgument_variableType = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 447)) ;
      }else if (kBoolFalse == test_4) {
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 449)), GALGAS_string ("index: ").add_operation (var_idx.getter_sint (SOURCE_FILE ("template_semantics.galgas", 449)).getter_string (SOURCE_FILE ("template_semantics.galgas", 449)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 449)).add_operation (GALGAS_string (" >= length:"), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 449)).add_operation (var_mapList.getter_length (SOURCE_FILE ("template_semantics.galgas", 449)).getter_string (SOURCE_FILE ("template_semantics.galgas", 449)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 449))  COMMA_SOURCE_FILE ("template_semantics.galgas", 449)) ;
        outArgument_variableValue.drop () ; // Release error dropped variable
        outArgument_variableType.drop () ; // Release error dropped variable
      }
    }
  }
  const enumGalgasBool test_5 = GALGAS_bool (kIsStrictSup, inArgument_variable.getter_length (SOURCE_FILE ("template_semantics.galgas", 452)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_5) {
    const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 453)))).boolEnum () ;
    if (kBoolTrue == test_6) {
      {
      routine_searchField (inArgument_variable, outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 454)), outArgument_variableType, outArgument_variableValue, outArgument_variableLocation, inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 454)) ;
      }
    }else if (kBoolFalse == test_6) {
      outArgument_variableLocation = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 456)) ;
      GALGAS_location location_7 (var_field.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_7, GALGAS_string ("struct variable expected")  COMMA_SOURCE_FILE ("template_semantics.galgas", 457)) ;
      outArgument_variableValue.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'searchFieldIfExists'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_searchFieldIfExists (GALGAS_TvarPath inArgument_variable,
                                  const GALGAS_TfieldMap constinArgument_inTemplateFieldMap,
                                  GALGAS_Ttype & outArgument_variableType,
                                  GALGAS_Tvalue & outArgument_variableValue,
                                  GALGAS_bool & outArgument_found,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_variableType.drop () ; // Release 'out' argument
  outArgument_variableValue.drop () ; // Release 'out' argument
  outArgument_found.drop () ; // Release 'out' argument
  GALGAS_lstring var_field ;
  GALGAS_lstring var_key ;
  GALGAS_lsint var_idx ;
  {
  inArgument_variable.modifier_popFirst (var_field, var_key, var_idx, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 473)) ;
  }
  const enumGalgasBool test_0 = constinArgument_inTemplateFieldMap.getter_hasKey (var_field.getter_string (SOURCE_FILE ("template_semantics.galgas", 475)) COMMA_SOURCE_FILE ("template_semantics.galgas", 475)).boolEnum () ;
  if (kBoolTrue == test_0) {
    constinArgument_inTemplateFieldMap.method_searchKey (var_field, outArgument_variableType, outArgument_variableValue, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 476)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_key.getter_string (SOURCE_FILE ("template_semantics.galgas", 477)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_semantics.galgas", 478)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        const enumGalgasBool test_3 = outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 479)).getter_hasKey (var_key.getter_string (SOURCE_FILE ("template_semantics.galgas", 479)) COMMA_SOURCE_FILE ("template_semantics.galgas", 479)).boolEnum () ;
        if (kBoolTrue == test_3) {
          outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 480)).method_searchKey (var_key, outArgument_variableType, outArgument_variableValue, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 480)) ;
          outArgument_found = GALGAS_bool (true) ;
        }else if (kBoolFalse == test_3) {
          outArgument_found = GALGAS_bool (false) ;
        }
      }else if (kBoolFalse == test_2) {
        GALGAS_location location_4 (var_key.getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_4, GALGAS_string ("a key is only used in a map")  COMMA_SOURCE_FILE ("template_semantics.galgas", 486)) ;
        outArgument_found.drop () ; // Release error dropped variable
      }
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsNotEqual, var_idx.getter_sint (SOURCE_FILE ("template_semantics.galgas", 488)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 488)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_semantics.galgas", 489)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          const enumGalgasBool test_7 = GALGAS_bool (kIsStrictInf, var_idx.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 490)).objectCompare (outArgument_variableValue.getter_mMapListValue (SOURCE_FILE ("template_semantics.galgas", 490)).getter_length (SOURCE_FILE ("template_semantics.galgas", 490)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            GALGAS_TfieldMapList var_mapList = outArgument_variableValue.getter_mMapListValue (SOURCE_FILE ("template_semantics.galgas", 491)) ;
            outArgument_variableValue.mAttribute_mStructValue = var_mapList.getter_mMapAtIndex (var_idx.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 492)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 492)) ;
            outArgument_variableType = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 493)) ;
            outArgument_found = GALGAS_bool (true) ;
          }else if (kBoolFalse == test_7) {
            outArgument_found = GALGAS_bool (false) ;
          }
        }else if (kBoolFalse == test_6) {
          GALGAS_location location_8 (var_idx.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_8, GALGAS_string ("an index is only used in a list")  COMMA_SOURCE_FILE ("template_semantics.galgas", 499)) ;
          outArgument_found.drop () ; // Release error dropped variable
        }
      }else if (kBoolFalse == test_5) {
        outArgument_found = GALGAS_bool (true) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    outArgument_variableType = GALGAS_Ttype::constructor_unconstructedType (SOURCE_FILE ("template_semantics.galgas", 505)) ;
    outArgument_variableValue = function_valueWithVoid (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 506)) ;
    outArgument_found = GALGAS_bool (false) ;
  }
  const enumGalgasBool test_9 = GALGAS_bool (kIsStrictSup, inArgument_variable.getter_length (SOURCE_FILE ("template_semantics.galgas", 509)).objectCompare (GALGAS_uint ((uint32_t) 0U))).operator_and (outArgument_found COMMA_SOURCE_FILE ("template_semantics.galgas", 509)).boolEnum () ;
  if (kBoolTrue == test_9) {
    const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 510)))).boolEnum () ;
    if (kBoolTrue == test_10) {
      {
      routine_searchFieldIfExists (inArgument_variable, outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 511)), outArgument_variableType, outArgument_variableValue, outArgument_found, inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 511)) ;
      }
    }else if (kBoolFalse == test_10) {
      outArgument_found = GALGAS_bool (false) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'matchAndOperatorForTemplate'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_matchAndOperatorForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                          const GALGAS_Ttype constinArgument_inRightExpressionType,
                                          GALGAS_Ttype & outArgument_outResultType,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1238)), GALGAS_string ("operand type error : (").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1238)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1238)).add_operation (GALGAS_string (" & "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1238)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1239)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1239)).add_operation (GALGAS_string (") is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1239))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1238)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'matchOrOperatorForTemplate'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_matchOrOperatorForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                         const GALGAS_Ttype constinArgument_inRightExpressionType,
                                         GALGAS_Ttype & outArgument_outResultType,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1260)), GALGAS_string ("operand type error : (").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1260)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1260)).add_operation (GALGAS_string (" | "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1260)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1261)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1261)).add_operation (GALGAS_string (") is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1261))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1260)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'matchXorOperatorForTemplate'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_matchXorOperatorForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                          const GALGAS_Ttype constinArgument_inRightExpressionType,
                                          GALGAS_Ttype & outArgument_outResultType,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1282)), GALGAS_string ("operand type error : (").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1282)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1282)).add_operation (GALGAS_string (" | "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1282)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1283)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1283)).add_operation (GALGAS_string (") is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1283))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1282)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'checkNotOperatorForTemplate'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkNotOperatorForTemplate (const GALGAS_Ttype constinArgument_inOperandType,
                                          GALGAS_Ttype & outArgument_outResultType,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_inOperandType.objectCompare (GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_expression_parser.galgas", 1297)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1298)), GALGAS_string ("the 'not' operator is not defined for an ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inOperandType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1299)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1298)).add_operation (GALGAS_string (" type"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1299))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1298)) ;
  }
  outArgument_outResultType = constinArgument_inOperandType ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Routine 'checkBitComplementOperatorForTemplate'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkBitComplementOperatorForTemplate (const GALGAS_Ttype constinArgument_inOperandType,
                                                    GALGAS_Ttype & outArgument_outResultType,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  outArgument_outResultType = constinArgument_inOperandType ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_inOperandType.objectCompare (GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1314)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1315)), GALGAS_string ("the ~ operator is not defined for an ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inOperandType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1316)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1315)).add_operation (GALGAS_string (" type"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1316))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1315)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Routine 'comparison_types_checkForTemplate'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_comparison_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                      const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_enumType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_enumType)) {
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)), GALGAS_string ("comparison between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1336)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1336)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1336))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Routine 'magnitude_comparison_types_checkForTemplate'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_magnitude_5F_comparison_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                                   const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType)) {
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1354)), GALGAS_string ("comparison between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1354)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1354)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1354)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1355)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1355)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1355))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1354)) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Routine 'left_shift_types_checkForTemplate'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_left_5F_shift_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                         const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                         GALGAS_Ttype & outArgument_outResultType,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1373)), GALGAS_string ("shift between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1373)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1373)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1373)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1374)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1374)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1374))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1373)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Routine 'right_shift_types_checkForTemplate'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_right_5F_shift_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                          const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                          GALGAS_Ttype & outArgument_outResultType,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1389)), GALGAS_string ("shift between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1389)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1389)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1389)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1390)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1390)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1390))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1389)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'addition_types_checkForTemplate'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addition_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                    const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                    GALGAS_Ttype & outArgument_outResultType,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1409)), GALGAS_string ("addition between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1409)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1409)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1409)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1410)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1410)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1410))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1409)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Routine 'concatenation_types_checkForTemplate'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_concatenation_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                         const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                         GALGAS_Ttype & outArgument_outResultType,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_listType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_listType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1431)), GALGAS_string ("addition between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1431)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1431)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1431)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1432)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1432)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1432))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1431)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Routine 'substraction_types_checkForTemplate'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_substraction_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                        const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                        GALGAS_Ttype & outArgument_outResultType,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1451)), GALGAS_string ("substraction between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1451)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1451)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1451)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1452)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1452)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1452))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1451)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'multiply_types_checkForTemplate'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_multiply_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                    const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                    GALGAS_Ttype & outArgument_outResultType,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1471)), GALGAS_string ("multiplication between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1471)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1471)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1471)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1472)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1472)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1472))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1471)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Routine 'divide_types_checkForTemplate'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_divide_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                  const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                  GALGAS_Ttype & outArgument_outResultType,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1491)), GALGAS_string ("division between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1491)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1491)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1491)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1492)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1492)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1492))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1491)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Routine 'modulo_types_checkForTemplate'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_modulo_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                  const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                  GALGAS_Ttype & outArgument_outResultType,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1511)), GALGAS_string ("modulo between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1511)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1511)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1511)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1512)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1512)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1512))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1511)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'argumentListSignature'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_argumentListSignature (const GALGAS_TexpressionList & constinArgument_inParameterTypeList,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outResult ; // Returned variable
  result_outResult = GALGAS_string (" this method call has ") ;
  result_outResult.dotAssign_operation (constinArgument_inParameterTypeList.getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1527)).getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1527)).add_operation (GALGAS_string (" argument"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1527))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1527)) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, constinArgument_inParameterTypeList.getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1528)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("s") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }
  result_outResult.dotAssign_operation (temp_0  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1528)) ;
  cEnumerator_TexpressionList enumerator_52336 (constinArgument_inParameterTypeList, kEnumeration_up) ;
  const bool bool_2 = true ;
  if (enumerator_52336.hasCurrentObject () && bool_2) {
    result_outResult.dotAssign_operation (GALGAS_string (": ")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1530)) ;
    while (enumerator_52336.hasCurrentObject () && bool_2) {
      result_outResult.dotAssign_operation (extensionGetter_messageGoilTemplateType (enumerator_52336.current_mType (HERE), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1531))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1531)) ;
      enumerator_52336.gotoNextObject () ;
      if (enumerator_52336.hasCurrentObject () && bool_2) {
        result_outResult.dotAssign_operation (GALGAS_string (", ")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1532)) ;
      }
    }
  }
//---
  return result_outResult ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_argumentListSignature [2] = {
  & kTypeDescriptor_GALGAS_TexpressionList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_argumentListSignature (C_Compiler * inCompiler,
                                                                      const cObjectArray & inEffectiveParameterArray,
                                                                      const GALGAS_location & /* §§ inErrorLocation */
                                                                      COMMA_LOCATION_ARGS) {
  const GALGAS_TexpressionList operand0 = GALGAS_TexpressionList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                 inCompiler
                                                                                 COMMA_THERE) ;
  return function_argumentListSignature (operand0,
                                         inCompiler
                                         COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_argumentListSignature ("argumentListSignature",
                                                                       functionWithGenericHeader_argumentListSignature,
                                                                       & kTypeDescriptor_GALGAS_string,
                                                                       1,
                                                                       functionArgs_argumentListSignature) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Routine 'checkInvocationHasNoArgument'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkInvocationHasNoArgument (const GALGAS_Ttype constinArgument_inType,
                                           const GALGAS_lstring constinArgument_inMethodName,
                                           const GALGAS_TexpressionList constinArgument_inParameterTypeList,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, constinArgument_inParameterTypeList.getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1546)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_location location_1 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_1, GALGAS_string ("calling '").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1547)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1547)).add_operation (GALGAS_string ("' on a "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1547)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1548)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1547)).add_operation (GALGAS_string (" type requires no argument; "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1548)).add_operation (function_argumentListSignature (constinArgument_inParameterTypeList, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1549)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1548))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1547)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'checkInvocationHasArguments'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkInvocationHasArguments (const GALGAS_Ttype constinArgument_inType,
                                          const GALGAS_lstring constinArgument_inMethodName,
                                          const GALGAS_TexpressionList constinArgument_inParameterTypeList,
                                          const GALGAS_Ttype constinArgument_inExpectedType,
                                          const GALGAS_uint constinArgument_argsNumber,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Ttype var_parameterType ;
  GALGAS_Tvalue joker_53459 ; // Joker input parameter
  constinArgument_inParameterTypeList.method_first (joker_53459, var_parameterType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1560)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_inParameterTypeList.getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1561)).objectCompare (constinArgument_argsNumber)).operator_or (GALGAS_bool (kIsNotEqual, var_parameterType.objectCompare (constinArgument_inExpectedType)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1561)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_location location_1 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_1, GALGAS_string ("calling '").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1562)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1562)).add_operation (GALGAS_string ("' on a "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1562)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1563)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1562)).add_operation (GALGAS_string (" type requires "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1563)).add_operation (constinArgument_argsNumber.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1563)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1563)).add_operation (GALGAS_string (" unsigned argument(s); "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1563)).add_operation (function_argumentListSignature (constinArgument_inParameterTypeList, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1564)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1563))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1562)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Routine 'templateMethodInvocation'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_templateMethodInvocation (const GALGAS_Ttype constinArgument_inType,
                                       const GALGAS_Tvalue constinArgument_inValue,
                                       const GALGAS_lstring constinArgument_inMethodName,
                                       GALGAS_TexpressionList inArgument_inParameterTypeList,
                                       GALGAS_Ttype & outArgument_outResultType,
                                       GALGAS_Tvalue & outArgument_outResultValue,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  outArgument_outResultValue.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1581)).objectCompare (GALGAS_string ("description"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1582)) ;
    }
    outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1583)) ;
    outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mDescription (SOURCE_FILE ("template_expression_parser.galgas", 1584)).getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1584)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1584)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1584)) ;
  }else if (kBoolFalse == test_0) {
    switch (constinArgument_inType.enumValue ()) {
    case GALGAS_Ttype::kNotBuilt:
      break ;
    case GALGAS_Ttype::kEnum_boolType:
      {
        const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1588)).objectCompare (GALGAS_string ("trueOrFalse"))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1589)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1590)) ;
          GALGAS_string temp_2 ;
          const enumGalgasBool test_3 = GALGAS_bool (kIsStrictSup, constinArgument_inValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1592)).objectCompare (GALGAS_sint_36__34_ ((int64_t) 0LL))).boolEnum () ;
          if (kBoolTrue == test_3) {
            temp_2 = GALGAS_string ("true") ;
          }else if (kBoolFalse == test_3) {
            temp_2 = GALGAS_string ("false") ;
          }
          outArgument_outResultValue = function_valueWithString (temp_2, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1593)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1591)) ;
        }else if (kBoolFalse == test_1) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1595)).objectCompare (GALGAS_string ("yesOrNo"))).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1596)) ;
            }
            outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1597)) ;
            GALGAS_string temp_5 ;
            const enumGalgasBool test_6 = GALGAS_bool (kIsStrictSup, constinArgument_inValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1599)).objectCompare (GALGAS_sint_36__34_ ((int64_t) 0LL))).boolEnum () ;
            if (kBoolTrue == test_6) {
              temp_5 = GALGAS_string ("yes") ;
            }else if (kBoolFalse == test_6) {
              temp_5 = GALGAS_string ("no") ;
            }
            outArgument_outResultValue = function_valueWithString (temp_5, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1600)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1598)) ;
          }else if (kBoolFalse == test_4) {
            const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1602)).objectCompare (GALGAS_string ("unsigned"))).boolEnum () ;
            if (kBoolTrue == test_7) {
              {
              routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1603)) ;
              }
              outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1604)) ;
              outArgument_outResultValue = constinArgument_inValue ;
            }else if (kBoolFalse == test_7) {
              GALGAS_location location_8 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
              inCompiler->emitSemanticError (location_8, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1607)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1607)).add_operation (GALGAS_string (" template method is not defined"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1607))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1607)) ;
              outArgument_outResultValue.drop () ; // Release error dropped variable
              outArgument_outResultType.drop () ; // Release error dropped variable
            }
          }
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_intType:
      {
        const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1610)).objectCompare (GALGAS_string ("string"))).boolEnum () ;
        if (kBoolTrue == test_9) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1611)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1612)) ;
          outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1613)).getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1613)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1613)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1613)) ;
        }else if (kBoolFalse == test_9) {
          const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1614)).objectCompare (GALGAS_string ("hexString"))).boolEnum () ;
          if (kBoolTrue == test_10) {
            {
            routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1615)) ;
            }
            outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1616)) ;
            outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1617)).getter_uint_36__34_ (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1617)).getter_hexString (SOURCE_FILE ("template_expression_parser.galgas", 1617)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1617)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1617)) ;
          }else if (kBoolFalse == test_10) {
            const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1618)).objectCompare (GALGAS_string ("numberOfBytes"))).operator_or (GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1618)).objectCompare (GALGAS_string ("signedNumberOfBytes"))) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1618)).boolEnum () ;
            if (kBoolTrue == test_11) {
              {
              routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1619)) ;
              }
              outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1620)) ;
              GALGAS_sint_36__34_ var_value = constinArgument_inValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1621)) ;
              GALGAS_uint var_numberOfBytes = GALGAS_uint ((uint32_t) 1U) ;
              const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1624)).objectCompare (GALGAS_string ("signedNumberOfBytes"))).boolEnum () ;
              if (kBoolTrue == test_12) {
                var_value = var_value.multiply_operation (GALGAS_uint ((uint32_t) 2U).getter_sint_36__34_ (SOURCE_FILE ("template_expression_parser.galgas", 1625)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1625)) ;
              }
              GALGAS_uint var_count = GALGAS_uint ((uint32_t) 0U) ;
              if (GALGAS_uint ((uint32_t) 4U).isValid ()) {
                uint32_t variant_56742 = GALGAS_uint ((uint32_t) 4U).uintValue () ;
                bool loop_56742 = true ;
                while (loop_56742) {
                  loop_56742 = GALGAS_bool (kIsStrictInf, var_count.objectCompare (GALGAS_uint ((uint32_t) 4U))).isValid () ;
                  if (loop_56742) {
                    loop_56742 = GALGAS_bool (kIsStrictInf, var_count.objectCompare (GALGAS_uint ((uint32_t) 4U))).boolValue () ;
                  }
                  if (loop_56742 && (0 == variant_56742)) {
                    loop_56742 = false ;
                    inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_expression_parser.galgas", 1628)) ;
                  }
                  if (loop_56742) {
                    variant_56742 -- ;
                    GALGAS_sint_36__34_ var_maxValue = GALGAS_sint_36__34_ ((int64_t) 1LL).left_shift_operation (var_numberOfBytes.multiply_operation (GALGAS_uint ((uint32_t) 8U), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1630)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1630)).substract_operation (GALGAS_sint_36__34_ ((int64_t) 1LL), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1630)) ;
                    const enumGalgasBool test_13 = GALGAS_bool (kIsStrictInf, var_maxValue.objectCompare (var_value)).boolEnum () ;
                    if (kBoolTrue == test_13) {
                      var_numberOfBytes = var_numberOfBytes.multiply_operation (GALGAS_uint ((uint32_t) 2U), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1632)) ;
                    }
                    var_count.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1634)) ;
                  }
                }
              }
              outArgument_outResultValue = function_valueWithUnsigned (var_numberOfBytes.getter_uint_36__34_ (SOURCE_FILE ("template_expression_parser.galgas", 1636)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1636)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1636)) ;
            }else if (kBoolFalse == test_11) {
              const enumGalgasBool test_14 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1637)).objectCompare (GALGAS_string ("numberOfBits"))).operator_or (GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1637)).objectCompare (GALGAS_string ("signedNumberOfBits"))) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1637)).boolEnum () ;
              if (kBoolTrue == test_14) {
                {
                routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1638)) ;
                }
                outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1639)) ;
                GALGAS_sint_36__34_ var_value = constinArgument_inValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1640)) ;
                const enumGalgasBool test_15 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1641)).objectCompare (GALGAS_string ("signedNumberOfBits"))).boolEnum () ;
                if (kBoolTrue == test_15) {
                  var_value = var_value.multiply_operation (GALGAS_uint ((uint32_t) 2U).getter_sint_36__34_ (SOURCE_FILE ("template_expression_parser.galgas", 1642)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1642)) ;
                }
                GALGAS_sint_36__34_ var_numberOfBits = GALGAS_sint_36__34_ ((int64_t) 0LL) ;
                if (GALGAS_uint ((uint32_t) 64U).isValid ()) {
                  uint32_t variant_57515 = GALGAS_uint ((uint32_t) 64U).uintValue () ;
                  bool loop_57515 = true ;
                  while (loop_57515) {
                    loop_57515 = GALGAS_bool (kIsNotEqual, var_value.objectCompare (GALGAS_sint_36__34_ ((int64_t) 0LL))).isValid () ;
                    if (loop_57515) {
                      loop_57515 = GALGAS_bool (kIsNotEqual, var_value.objectCompare (GALGAS_sint_36__34_ ((int64_t) 0LL))).boolValue () ;
                    }
                    if (loop_57515 && (0 == variant_57515)) {
                      loop_57515 = false ;
                      inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_expression_parser.galgas", 1646)) ;
                    }
                    if (loop_57515) {
                      variant_57515 -- ;
                      var_numberOfBits.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1648)) ;
                      var_value = var_value.right_shift_operation (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1649)) ;
                    }
                  }
                }
                outArgument_outResultValue = function_valueWithSigned (var_numberOfBits, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1651)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1651)) ;
              }else if (kBoolFalse == test_14) {
                GALGAS_location location_16 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
                inCompiler->emitSemanticError (location_16, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1653)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1653)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1653)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1653)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1653))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1653)) ;
                outArgument_outResultValue.drop () ; // Release error dropped variable
                outArgument_outResultType.drop () ; // Release error dropped variable
              }
            }
          }
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_stringType:
      {
        const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1656)).objectCompare (GALGAS_string ("HTMLRepresentation"))).boolEnum () ;
        if (kBoolTrue == test_17) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1657)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1658)) ;
          outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1659)).getter_HTMLRepresentation (SOURCE_FILE ("template_expression_parser.galgas", 1659)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1659)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1659)) ;
        }else if (kBoolFalse == test_17) {
          const enumGalgasBool test_18 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1660)).objectCompare (GALGAS_string ("identifierRepresentation"))).boolEnum () ;
          if (kBoolTrue == test_18) {
            {
            routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1661)) ;
            }
            outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1662)) ;
            outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1663)).getter_identifierRepresentation (SOURCE_FILE ("template_expression_parser.galgas", 1663)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1663)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1663)) ;
          }else if (kBoolFalse == test_18) {
            const enumGalgasBool test_19 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1664)).objectCompare (GALGAS_string ("fileExists"))).boolEnum () ;
            if (kBoolTrue == test_19) {
              {
              routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1665)) ;
              }
              outArgument_outResultType = GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_expression_parser.galgas", 1666)) ;
              outArgument_outResultValue = function_valueWithBool (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1667)).getter_fileExists (SOURCE_FILE ("template_expression_parser.galgas", 1667)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1667)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1667)) ;
            }else if (kBoolFalse == test_19) {
              const enumGalgasBool test_20 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1668)).objectCompare (GALGAS_string ("lowercaseString"))).boolEnum () ;
              if (kBoolTrue == test_20) {
                {
                routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1669)) ;
                }
                outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1670)) ;
                outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1671)).getter_lowercaseString (SOURCE_FILE ("template_expression_parser.galgas", 1671)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1671)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1671)) ;
              }else if (kBoolFalse == test_20) {
                const enumGalgasBool test_21 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1672)).objectCompare (GALGAS_string ("length"))).boolEnum () ;
                if (kBoolTrue == test_21) {
                  {
                  routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1673)) ;
                  }
                  outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1674)) ;
                  outArgument_outResultValue = function_valueWithUnsigned (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1675)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1675)).getter_uint_36__34_ (SOURCE_FILE ("template_expression_parser.galgas", 1675)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1675)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1675)) ;
                }else if (kBoolFalse == test_21) {
                  const enumGalgasBool test_22 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1676)).objectCompare (GALGAS_string ("stringByCapitalizingFirstCharacter"))).boolEnum () ;
                  if (kBoolTrue == test_22) {
                    {
                    routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1677)) ;
                    }
                    outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1678)) ;
                    outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1679)).getter_stringByCapitalizingFirstCharacter (SOURCE_FILE ("template_expression_parser.galgas", 1679)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1679)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1679)) ;
                  }else if (kBoolFalse == test_22) {
                    const enumGalgasBool test_23 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1680)).objectCompare (GALGAS_string ("uppercaseString"))).boolEnum () ;
                    if (kBoolTrue == test_23) {
                      {
                      routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1681)) ;
                      }
                      outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1682)) ;
                      outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1683)).getter_uppercaseString (SOURCE_FILE ("template_expression_parser.galgas", 1683)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1683)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1683)) ;
                    }else if (kBoolFalse == test_23) {
                      const enumGalgasBool test_24 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1684)).objectCompare (GALGAS_string ("unsigned"))).boolEnum () ;
                      if (kBoolTrue == test_24) {
                        {
                        routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1685)) ;
                        }
                        outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1686)) ;
                        outArgument_outResultValue = function_valueWithUnsigned (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1687)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1687)).getter_uint_36__34_ (SOURCE_FILE ("template_expression_parser.galgas", 1687)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1687)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1687)) ;
                      }else if (kBoolFalse == test_24) {
                        const enumGalgasBool test_25 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1688)).objectCompare (GALGAS_string ("leftSubString"))).boolEnum () ;
                        if (kBoolTrue == test_25) {
                          {
                          routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1689)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1689)) ;
                          }
                          GALGAS_Tvalue var_parameter ;
                          GALGAS_Ttype joker_60455 ; // Joker input parameter
                          inArgument_inParameterTypeList.method_first (var_parameter, joker_60455, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1691)) ;
                          outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1692)) ;
                          outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1693)).getter_leftSubString (var_parameter.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1693)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1693)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1693)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1693)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1693)) ;
                        }else if (kBoolFalse == test_25) {
                          const enumGalgasBool test_26 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1694)).objectCompare (GALGAS_string ("rightSubString"))).boolEnum () ;
                          if (kBoolTrue == test_26) {
                            {
                            routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1695)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1695)) ;
                            }
                            GALGAS_Tvalue var_parameter ;
                            GALGAS_Ttype joker_60866 ; // Joker input parameter
                            inArgument_inParameterTypeList.method_first (var_parameter, joker_60866, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1697)) ;
                            outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1698)) ;
                            outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1699)).getter_rightSubString (var_parameter.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1699)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1699)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1699)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1699)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1699)) ;
                          }else if (kBoolFalse == test_26) {
                            const enumGalgasBool test_27 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1700)).objectCompare (GALGAS_string ("subString"))).boolEnum () ;
                            if (kBoolTrue == test_27) {
                              {
                              routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1701)), GALGAS_uint ((uint32_t) 2U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1701)) ;
                              }
                              GALGAS_Tvalue var_start = inArgument_inParameterTypeList.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1702)) ;
                              GALGAS_Tvalue var_length = inArgument_inParameterTypeList.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1703)) ;
                              outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1706)) ;
                              outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1707)).getter_subString (var_start.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1707)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1707)), var_length.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1707)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1707)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1707)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1707)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1707)) ;
                            }else if (kBoolFalse == test_27) {
                              const enumGalgasBool test_28 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1708)).objectCompare (GALGAS_string ("reversedString"))).boolEnum () ;
                              if (kBoolTrue == test_28) {
                                {
                                routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1709)) ;
                                }
                                outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1710)) ;
                                outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1711)).getter_reversedString (SOURCE_FILE ("template_expression_parser.galgas", 1711)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1711)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1711)) ;
                              }else if (kBoolFalse == test_28) {
                                const enumGalgasBool test_29 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1712)).objectCompare (GALGAS_string ("componentsSeparatedByString"))).boolEnum () ;
                                if (kBoolTrue == test_29) {
                                  {
                                  routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1713)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1713)) ;
                                  }
                                  GALGAS_Tvalue var_separator ;
                                  GALGAS_Ttype joker_62098 ; // Joker input parameter
                                  inArgument_inParameterTypeList.method_first (var_separator, joker_62098, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1715)) ;
                                  GALGAS_stringlist var_stringlist = constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1716)).getter_componentsSeparatedByString (var_separator.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1716)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1716)) ;
                                  GALGAS_TfieldMapList var_result = GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_expression_parser.galgas", 1717)) ;
                                  cEnumerator_stringlist enumerator_62289 (var_stringlist, kEnumeration_up) ;
                                  while (enumerator_62289.hasCurrentObject ()) {
                                    GALGAS_TfieldMap var_item = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_expression_parser.galgas", 1719)) ;
                                    {
                                    routine_addStringValue (var_item, function_lstringWith (GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1720)), enumerator_62289.current_mValue (HERE), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1720)), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1720)) ;
                                    }
                                    var_result.addAssign_operation (var_item  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1721)) ;
                                    enumerator_62289.gotoNextObject () ;
                                  }
                                  outArgument_outResultType = GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_expression_parser.galgas", 1723)) ;
                                  outArgument_outResultValue = function_valueWithList (var_result, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1724)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1724)) ;
                                }else if (kBoolFalse == test_29) {
                                  const enumGalgasBool test_30 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1725)).objectCompare (GALGAS_string ("interpretEscape"))).boolEnum () ;
                                  if (kBoolTrue == test_30) {
                                    {
                                    routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1726)) ;
                                    }
                                    outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1727)) ;
                                    outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1728)).getter_stringByReplacingStringByString (GALGAS_string ("\\n"), GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1728)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1728)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1728)) ;
                                  }else if (kBoolFalse == test_30) {
                                    const enumGalgasBool test_31 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1729)).objectCompare (GALGAS_string ("columnPrefixedBy"))).boolEnum () ;
                                    if (kBoolTrue == test_31) {
                                      {
                                      routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1730)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1730)) ;
                                      }
                                      GALGAS_Tvalue var_separator ;
                                      GALGAS_Ttype joker_63115 ; // Joker input parameter
                                      inArgument_inParameterTypeList.method_first (var_separator, joker_63115, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1732)) ;
                                      outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1733)) ;
                                      outArgument_outResultValue = function_valueWithString (var_separator.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1734)).add_operation (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1734)).getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string ("\n").add_operation (var_separator.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1734)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1734)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1734)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1734)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1734)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1734)) ;
                                    }else if (kBoolFalse == test_31) {
                                      const enumGalgasBool test_32 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1735)).objectCompare (GALGAS_string ("wrap"))).boolEnum () ;
                                      if (kBoolTrue == test_32) {
                                        {
                                        routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1736)), GALGAS_uint ((uint32_t) 2U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1736)) ;
                                        }
                                        GALGAS_Tvalue var_width ;
                                        {
                                        GALGAS_Ttype joker_63666 ; // Joker input parameter
                                        inArgument_inParameterTypeList.modifier_popFirst (var_width, joker_63666, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1739)) ;
                                        }
                                        GALGAS_Tvalue var_shift ;
                                        {
                                        GALGAS_Ttype joker_63739 ; // Joker input parameter
                                        inArgument_inParameterTypeList.modifier_popFirst (var_shift, joker_63739, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1741)) ;
                                        }
                                        GALGAS_string var_stringshift = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_shift.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1742)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1742))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1742)) ;
                                        GALGAS_string var_result = constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1743)) ;
                                        GALGAS_stringlist var_paragraph = var_result.getter_componentsSeparatedByString (GALGAS_string ("\n") COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1752)) ;
                                        GALGAS_stringlist var_resultParagraph = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("template_expression_parser.galgas", 1753)) ;
                                        cEnumerator_stringlist enumerator_64404 (var_paragraph, kEnumeration_up) ;
                                        while (enumerator_64404.hasCurrentObject ()) {
                                          GALGAS_stringlist var_parts = enumerator_64404.current_mValue (HERE).getter_componentsSeparatedByString (GALGAS_string (" ") COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1755)) ;
                                          GALGAS_sint_36__34_ var_linewidth = GALGAS_sint_36__34_ ((int64_t) 0LL) ;
                                          GALGAS_bool var_newline = GALGAS_bool (true) ;
                                          var_result = GALGAS_string::makeEmptyString () ;
                                          cEnumerator_stringlist enumerator_64604 (var_parts, kEnumeration_up) ;
                                          while (enumerator_64604.hasCurrentObject ()) {
                                            const enumGalgasBool test_33 = GALGAS_bool (kIsStrictSup, var_linewidth.add_operation (enumerator_64604.current_mValue (HERE).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1760)).getter_sint_36__34_ (SOURCE_FILE ("template_expression_parser.galgas", 1760)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1760)).objectCompare (var_width.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1760)))).boolEnum () ;
                                            if (kBoolTrue == test_33) {
                                              var_result.dotAssign_operation (GALGAS_string ("\n").add_operation (var_stringshift, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1761))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1761)) ;
                                              var_linewidth = var_shift.getter_mInt_36__34_Value (SOURCE_FILE ("template_expression_parser.galgas", 1762)) ;
                                              var_newline = GALGAS_bool (true) ;
                                            }
                                            const enumGalgasBool test_34 = GALGAS_bool (kIsEqual, var_newline.objectCompare (GALGAS_bool (false))).boolEnum () ;
                                            if (kBoolTrue == test_34) {
                                              var_linewidth = var_linewidth.add_operation (GALGAS_sint_36__34_ ((int64_t) 1LL), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1766)) ;
                                              var_result.dotAssign_operation (GALGAS_string (" ")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1767)) ;
                                            }
                                            var_linewidth = var_linewidth.add_operation (enumerator_64604.current_mValue (HERE).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1769)).getter_sint_36__34_ (SOURCE_FILE ("template_expression_parser.galgas", 1769)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1769)) ;
                                            var_result.dotAssign_operation (enumerator_64604.current_mValue (HERE)  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1770)) ;
                                            var_newline = GALGAS_bool (false) ;
                                            enumerator_64604.gotoNextObject () ;
                                          }
                                          var_resultParagraph.addAssign_operation (var_result  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1773)) ;
                                          enumerator_64404.gotoNextObject () ;
                                        }
                                        outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1775)) ;
                                        outArgument_outResultValue = function_valueWithString (GALGAS_string::constructor_componentsJoinedByString (var_resultParagraph, GALGAS_string ("\n")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1776)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1776)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1776)) ;
                                      }else if (kBoolFalse == test_32) {
                                        const enumGalgasBool test_35 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1777)).objectCompare (GALGAS_string ("substringExists"))).boolEnum () ;
                                        if (kBoolTrue == test_35) {
                                          {
                                          routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1778)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1778)) ;
                                          }
                                          GALGAS_Tvalue var_subString ;
                                          {
                                          GALGAS_Ttype joker_65513 ; // Joker input parameter
                                          inArgument_inParameterTypeList.modifier_popFirst (var_subString, joker_65513, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1779)) ;
                                          }
                                          GALGAS_uint var_start = GALGAS_uint ((uint32_t) 0U) ;
                                          GALGAS_uint var_stop = constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1781)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1781)).substract_operation (var_subString.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1781)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1781)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1781)) ;
                                          GALGAS_bool var_exists = GALGAS_bool (false) ;
                                          if (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1783)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1783)).isValid ()) {
                                            uint32_t variant_65671 = constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1783)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1783)).uintValue () ;
                                            bool loop_65671 = true ;
                                            while (loop_65671) {
                                              loop_65671 = GALGAS_bool (kIsInfOrEqual, var_start.objectCompare (var_stop)).isValid () ;
                                              if (loop_65671) {
                                                loop_65671 = GALGAS_bool (kIsInfOrEqual, var_start.objectCompare (var_stop)).boolValue () ;
                                              }
                                              if (loop_65671 && (0 == variant_65671)) {
                                                loop_65671 = false ;
                                                inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_expression_parser.galgas", 1783)) ;
                                              }
                                              if (loop_65671) {
                                                variant_65671 -- ;
                                                const enumGalgasBool test_36 = GALGAS_bool (kIsEqual, constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1785)).getter_subString (var_start, var_subString.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1785)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1785)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1785)).objectCompare (var_subString.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1785)))).boolEnum () ;
                                                if (kBoolTrue == test_36) {
                                                  var_exists = GALGAS_bool (true) ;
                                                }
                                                var_start.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1788)) ;
                                              }
                                            }
                                          }
                                          outArgument_outResultType = GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_expression_parser.galgas", 1790)) ;
                                          outArgument_outResultValue = function_valueWithBool (var_exists, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1791)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1791)) ;
                                        }else if (kBoolFalse == test_35) {
                                          GALGAS_location location_37 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
                                          inCompiler->emitSemanticError (location_37, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1793)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1793)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1793)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1793)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1793))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1793)) ;
                                          outArgument_outResultValue.drop () ; // Release error dropped variable
                                          outArgument_outResultType.drop () ; // Release error dropped variable
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_floatType:
      {
        GALGAS_location location_38 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_38, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1796)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1796)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1796)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1796)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1796))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1796)) ;
        outArgument_outResultValue.drop () ; // Release error dropped variable
        outArgument_outResultType.drop () ; // Release error dropped variable
      }
      break ;
    case GALGAS_Ttype::kEnum_listType:
      {
        const enumGalgasBool test_39 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1798)).objectCompare (GALGAS_string ("length"))).boolEnum () ;
        if (kBoolTrue == test_39) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1799)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1800)) ;
          outArgument_outResultValue = function_valueWithUnsigned (constinArgument_inValue.getter_mMapListValue (SOURCE_FILE ("template_expression_parser.galgas", 1801)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1801)).getter_uint_36__34_ (SOURCE_FILE ("template_expression_parser.galgas", 1801)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1801)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1801)) ;
        }else if (kBoolFalse == test_39) {
          const enumGalgasBool test_40 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1802)).objectCompare (GALGAS_string ("first"))).boolEnum () ;
          if (kBoolTrue == test_40) {
            {
            routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1803)) ;
            }
            outArgument_outResultType = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_expression_parser.galgas", 1804)) ;
            GALGAS_TfieldMap var_firstElement ;
            constinArgument_inValue.getter_mMapListValue (SOURCE_FILE ("template_expression_parser.galgas", 1806)).method_first (var_firstElement, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1806)) ;
            outArgument_outResultValue = function_valueWithStruct (var_firstElement, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1807)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1807)) ;
          }else if (kBoolFalse == test_40) {
            const enumGalgasBool test_41 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1808)).objectCompare (GALGAS_string ("last"))).boolEnum () ;
            if (kBoolTrue == test_41) {
              {
              routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1809)) ;
              }
              outArgument_outResultType = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_expression_parser.galgas", 1810)) ;
              GALGAS_TfieldMap var_lastElement ;
              constinArgument_inValue.getter_mMapListValue (SOURCE_FILE ("template_expression_parser.galgas", 1812)).method_last (var_lastElement, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1812)) ;
              outArgument_outResultValue = function_valueWithStruct (var_lastElement, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1813)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1813)) ;
            }else if (kBoolFalse == test_41) {
              GALGAS_location location_42 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
              inCompiler->emitSemanticError (location_42, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1815)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1815)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1815)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1815)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1815))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1815)) ;
              outArgument_outResultValue.drop () ; // Release error dropped variable
              outArgument_outResultType.drop () ; // Release error dropped variable
            }
          }
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_mapType:
      {
        const enumGalgasBool test_43 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1818)).objectCompare (GALGAS_string ("length"))).boolEnum () ;
        if (kBoolTrue == test_43) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1819)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1820)) ;
          outArgument_outResultValue = function_valueWithUnsigned (constinArgument_inValue.getter_mStructValue (SOURCE_FILE ("template_expression_parser.galgas", 1821)).getter_count (SOURCE_FILE ("template_expression_parser.galgas", 1821)).getter_uint_36__34_ (SOURCE_FILE ("template_expression_parser.galgas", 1821)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1821)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1821)) ;
        }else if (kBoolFalse == test_43) {
          GALGAS_location location_44 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_44, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1823)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1823)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1823)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1823)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1823))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1823)) ;
          outArgument_outResultValue.drop () ; // Release error dropped variable
          outArgument_outResultType.drop () ; // Release error dropped variable
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_enumType:
    case GALGAS_Ttype::kEnum_structType:
      {
        GALGAS_location location_45 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_45, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1826)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826)) ;
        outArgument_outResultValue.drop () ; // Release error dropped variable
        outArgument_outResultType.drop () ; // Release error dropped variable
      }
      break ;
    case GALGAS_Ttype::kEnum_unconstructedType:
    case GALGAS_Ttype::kEnum_functionType:
      {
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1828)), GALGAS_string ("internal error, unconstructed type found")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1828)) ;
        outArgument_outResultValue.drop () ; // Release error dropped variable
        outArgument_outResultType.drop () ; // Release error dropped variable
      }
      break ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'typeError'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_typeError (const GALGAS_lstring constinArgument_inFunctionName,
                        const GALGAS_type constinArgument_inActualType,
                        const GALGAS_string constinArgument_inExpectedTypeName,
                        const GALGAS_uint constinArgument_inParameterIndex,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_m = GALGAS_string ("the function requires the parameter ").add_operation (constinArgument_inParameterIndex.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1846)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1846)).add_operation (GALGAS_string (" to be "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1846)).add_operation (constinArgument_inExpectedTypeName, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1847)).add_operation (GALGAS_string ("; its type is "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1847)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_inActualType.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_bool))).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_m.dotAssign_operation (GALGAS_string ("boolean")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1849)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_inActualType.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_uint_36__34_))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_m.dotAssign_operation (GALGAS_string ("unsigned")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1851)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_inActualType.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_string))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_m.dotAssign_operation (GALGAS_string ("string")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1853)) ;
      }else if (kBoolFalse == test_2) {
        var_m.dotAssign_operation (GALGAS_string ("a not allowed type")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1855)) ;
      }
    }
  }
  GALGAS_location location_3 (constinArgument_inFunctionName.getter_location (HERE)) ; // Implicit use of 'location' getter
  inCompiler->emitSemanticError (location_3, var_m  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1857)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'setVariableInPath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setVariableInPath (GALGAS_TvarPath inArgument_path,
                                GALGAS_TfieldMap & ioArgument_ioFieldMap,
                                const GALGAS_Ttype constinArgument_expressionType,
                                const GALGAS_Tvalue constinArgument_enumeratedValue,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_varName ;
  GALGAS_lstring var_key ;
  GALGAS_lsint var_idx ;
  {
  inArgument_path.modifier_popFirst (var_varName, var_key, var_idx, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1340)) ;
  }
  const enumGalgasBool test_0 = ioArgument_ioFieldMap.getter_hasKey (var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1342)) COMMA_SOURCE_FILE ("template_parser.galgas", 1342)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_Ttype var_fieldType ;
    GALGAS_Tvalue var_fieldValue ;
    ioArgument_ioFieldMap.method_searchKey (var_varName, var_fieldType, var_fieldValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1345)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_fieldType.objectCompare (GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_parser.galgas", 1346)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, var_key.getter_string (SOURCE_FILE ("template_parser.galgas", 1348)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_TfieldMap var_items = var_fieldValue.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1350)) ;
        const enumGalgasBool test_3 = var_items.getter_hasKey (var_key.getter_string (SOURCE_FILE ("template_parser.galgas", 1351)) COMMA_SOURCE_FILE ("template_parser.galgas", 1351)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1352)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            var_items.modifier_setMTypeForKey (constinArgument_expressionType, var_key.getter_string (SOURCE_FILE ("template_parser.galgas", 1353)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1353)) ;
            }
            {
            var_items.modifier_setMValueForKey (constinArgument_enumeratedValue, var_key.getter_string (SOURCE_FILE ("template_parser.galgas", 1354)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1354)) ;
            }
          }else if (kBoolFalse == test_4) {
            GALGAS_Ttype var_itemType ;
            GALGAS_Tvalue var_itemValue ;
            var_items.method_searchKey (var_key, var_itemType, var_itemValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1358)) ;
            GALGAS_TfieldMap var_nextFieldMap = var_itemValue.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1359)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1360)) ;
            }
            var_itemValue.mAttribute_mStructValue = var_nextFieldMap ;
            var_itemType = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1362)) ;
            {
            var_items.modifier_setMTypeForKey (var_itemType, var_key.getter_string (SOURCE_FILE ("template_parser.galgas", 1363)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1363)) ;
            }
            {
            var_items.modifier_setMValueForKey (var_itemValue, var_key.getter_string (SOURCE_FILE ("template_parser.galgas", 1364)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1364)) ;
            }
          }
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1367)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            var_items.modifier_insertKey (var_key, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1368)) ;
            }
          }else if (kBoolFalse == test_5) {
            GALGAS_TfieldMap var_nextFieldMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1370)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1371)) ;
            }
            {
            var_items.modifier_insertKey (var_key, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1372)), function_valueWithStruct (var_nextFieldMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1372)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1372)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1372)) ;
            }
          }
        }
        var_fieldValue.mAttribute_mStructValue = var_items ;
        {
        ioArgument_ioFieldMap.modifier_setMTypeForKey (var_fieldType, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1376)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1376)) ;
        }
        {
        ioArgument_ioFieldMap.modifier_setMValueForKey (var_fieldValue, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1377)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1377)) ;
        }
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1379)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_6) {
          {
          ioArgument_ioFieldMap.modifier_setMTypeForKey (constinArgument_expressionType, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1381)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1381)) ;
          }
          {
          ioArgument_ioFieldMap.modifier_setMValueForKey (constinArgument_enumeratedValue, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1382)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1382)) ;
          }
        }else if (kBoolFalse == test_6) {
          GALGAS_TfieldMap var_nextFieldMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1385)) ;
          {
          routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1386)) ;
          }
          {
          ioArgument_ioFieldMap.modifier_setMTypeForKey (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1387)), var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1387)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1387)) ;
          }
          {
          ioArgument_ioFieldMap.modifier_setMValueForKey (function_valueWithStruct (var_nextFieldMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1388)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1388)), var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1388)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1388)) ;
          }
        }
      }
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_fieldType.objectCompare (GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_parser.galgas", 1391)))).boolEnum () ;
      if (kBoolTrue == test_7) {
        const enumGalgasBool test_8 = GALGAS_bool (kIsNotEqual, var_idx.getter_sint (SOURCE_FILE ("template_parser.galgas", 1393)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1393)))).boolEnum () ;
        if (kBoolTrue == test_8) {
          const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1394)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_9) {
            const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, constinArgument_expressionType.objectCompare (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1395)))).boolEnum () ;
            if (kBoolTrue == test_10) {
              GALGAS_TfieldMapList var_theList = var_fieldValue.getter_mMapListValue (SOURCE_FILE ("template_parser.galgas", 1397)) ;
              {
              var_theList.modifier_setMMapAtIndex (constinArgument_enumeratedValue.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1398)), var_idx.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1398)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1398)) ;
              }
              var_fieldValue.mAttribute_mMapListValue = var_theList ;
            }else if (kBoolFalse == test_10) {
              GALGAS_location location_11 (var_varName.getter_location (HERE)) ; // Implicit use of 'location' getter
              inCompiler->emitSemanticError (location_11, GALGAS_string ("struct expression expected")  COMMA_SOURCE_FILE ("template_parser.galgas", 1402)) ;
            }
          }else if (kBoolFalse == test_9) {
            GALGAS_TfieldMapList var_theList = var_fieldValue.getter_mMapListValue (SOURCE_FILE ("template_parser.galgas", 1406)) ;
            GALGAS_TfieldMap var_nextFieldMap = var_theList.getter_mMapAtIndex (var_idx.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1407)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1407)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1408)) ;
            }
            {
            var_theList.modifier_setMMapAtIndex (var_nextFieldMap, var_idx.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1409)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1409)) ;
            }
            var_fieldValue.mAttribute_mMapListValue = var_theList ;
          }
          {
          ioArgument_ioFieldMap.modifier_setMTypeForKey (var_fieldType, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1412)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1412)) ;
          }
          {
          ioArgument_ioFieldMap.modifier_setMValueForKey (var_fieldValue, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1413)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1413)) ;
          }
        }else if (kBoolFalse == test_8) {
          const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1416)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_12) {
            {
            ioArgument_ioFieldMap.modifier_setMTypeForKey (constinArgument_expressionType, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1418)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1418)) ;
            }
            {
            ioArgument_ioFieldMap.modifier_setMValueForKey (constinArgument_enumeratedValue, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1419)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1419)) ;
            }
          }else if (kBoolFalse == test_12) {
            GALGAS_TfieldMap var_nextFieldMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1422)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1423)) ;
            }
            {
            ioArgument_ioFieldMap.modifier_setMTypeForKey (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1424)), var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1424)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1424)) ;
            }
            {
            ioArgument_ioFieldMap.modifier_setMValueForKey (function_valueWithStruct (var_nextFieldMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1425)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1425)), var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1425)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1425)) ;
            }
          }
        }
      }else if (kBoolFalse == test_7) {
        const enumGalgasBool test_13 = GALGAS_bool (kIsEqual, var_fieldType.objectCompare (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1428)))).boolEnum () ;
        if (kBoolTrue == test_13) {
          const enumGalgasBool test_14 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1429)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_14) {
            {
            ioArgument_ioFieldMap.modifier_setMTypeForKey (constinArgument_expressionType, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1431)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1431)) ;
            }
            {
            ioArgument_ioFieldMap.modifier_setMValueForKey (constinArgument_enumeratedValue, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1432)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1432)) ;
            }
          }else if (kBoolFalse == test_14) {
            GALGAS_TfieldMap var_nextFieldMap = var_fieldValue.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1435)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1436)) ;
            }
            var_fieldValue.mAttribute_mStructValue = var_nextFieldMap ;
            {
            ioArgument_ioFieldMap.modifier_setMValueForKey (var_fieldValue, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1439)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1439)) ;
            }
          }
        }else if (kBoolFalse == test_13) {
          const enumGalgasBool test_15 = GALGAS_bool (kIsEqual, var_key.getter_string (SOURCE_FILE ("template_parser.galgas", 1442)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
          if (kBoolTrue == test_15) {
            const enumGalgasBool test_16 = GALGAS_bool (kIsEqual, var_idx.getter_sint (SOURCE_FILE ("template_parser.galgas", 1443)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1443)))).boolEnum () ;
            if (kBoolTrue == test_16) {
              const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1444)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
              if (kBoolTrue == test_17) {
                {
                ioArgument_ioFieldMap.modifier_setMTypeForKey (constinArgument_expressionType, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1446)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1446)) ;
                }
                {
                ioArgument_ioFieldMap.modifier_setMValueForKey (constinArgument_enumeratedValue, var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1447)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1447)) ;
                }
              }else if (kBoolFalse == test_17) {
                GALGAS_TfieldMap var_nextFieldMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1449)) ;
                {
                routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1450)) ;
                }
                {
                ioArgument_ioFieldMap.modifier_setMTypeForKey (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1451)), var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1451)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1451)) ;
                }
                {
                ioArgument_ioFieldMap.modifier_setMValueForKey (function_valueWithStruct (var_nextFieldMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1452)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1452)), var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1452)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1452)) ;
                }
              }
            }else if (kBoolFalse == test_16) {
              GALGAS_location location_18 (var_varName.getter_location (HERE)) ; // Implicit use of 'location' getter
              inCompiler->emitSemanticError (location_18, GALGAS_string ("A list must exist before setting one of its item")  COMMA_SOURCE_FILE ("template_parser.galgas", 1456)) ;
            }
          }else if (kBoolFalse == test_15) {
            GALGAS_TfieldMap var_newMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1460)) ;
            const enumGalgasBool test_19 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1461)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
            if (kBoolTrue == test_19) {
              {
              var_newMap.modifier_insertKey (var_key, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1462)) ;
              }
            }else if (kBoolFalse == test_19) {
              GALGAS_TfieldMap var_nextFieldMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1464)) ;
              {
              routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1465)) ;
              }
              {
              var_newMap.modifier_insertKey (var_key, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1466)), function_valueWithStruct (var_nextFieldMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1466)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1466)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1466)) ;
              }
            }
            {
            ioArgument_ioFieldMap.modifier_setMTypeForKey (GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_parser.galgas", 1468)), var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1468)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1468)) ;
            }
            {
            ioArgument_ioFieldMap.modifier_setMValueForKey (function_valueWithMap (var_newMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1469)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1469)), var_varName.getter_string (SOURCE_FILE ("template_parser.galgas", 1469)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1469)) ;
            }
          }
        }
      }
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_20 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1474)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_20) {
      const enumGalgasBool test_21 = GALGAS_bool (kIsEqual, var_key.getter_string (SOURCE_FILE ("template_parser.galgas", 1475)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_21) {
        const enumGalgasBool test_22 = GALGAS_bool (kIsEqual, var_idx.getter_sint (SOURCE_FILE ("template_parser.galgas", 1476)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1476)))).boolEnum () ;
        if (kBoolTrue == test_22) {
          {
          ioArgument_ioFieldMap.modifier_insertKey (var_varName, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1477)) ;
          }
        }else if (kBoolFalse == test_22) {
          GALGAS_location location_23 (var_varName.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_23, GALGAS_string ("A list must exist before setting one of its item")  COMMA_SOURCE_FILE ("template_parser.galgas", 1480)) ;
        }
      }else if (kBoolFalse == test_21) {
        GALGAS_TfieldMap var_newMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1483)) ;
        {
        var_newMap.modifier_insertKey (var_key, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1484)) ;
        }
        {
        ioArgument_ioFieldMap.modifier_insertKey (var_varName, GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_parser.galgas", 1485)), function_valueWithMap (var_newMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1485)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1485)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1485)) ;
        }
      }
    }else if (kBoolFalse == test_20) {
      const enumGalgasBool test_24 = GALGAS_bool (kIsEqual, var_key.getter_string (SOURCE_FILE ("template_parser.galgas", 1488)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_24) {
        const enumGalgasBool test_25 = GALGAS_bool (kIsEqual, var_idx.getter_sint (SOURCE_FILE ("template_parser.galgas", 1489)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1489)))).boolEnum () ;
        if (kBoolTrue == test_25) {
          GALGAS_TfieldMap var_nextFieldMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1490)) ;
          {
          routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1491)) ;
          }
          {
          ioArgument_ioFieldMap.modifier_insertKey (var_varName, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1492)), function_valueWithStruct (var_nextFieldMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1492)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1492)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1492)) ;
          }
        }else if (kBoolFalse == test_25) {
          GALGAS_location location_26 (var_varName.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_26, GALGAS_string ("A list must exist before setting one of its item")  COMMA_SOURCE_FILE ("template_parser.galgas", 1495)) ;
        }
      }else if (kBoolFalse == test_24) {
        GALGAS_TfieldMap var_newMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1498)) ;
        GALGAS_TfieldMap var_nextFieldMap = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1499)) ;
        {
        routine_setVariableInPath (inArgument_path, var_nextFieldMap, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1500)) ;
        }
        {
        var_newMap.modifier_insertKey (var_key, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1501)), function_valueWithStruct (var_nextFieldMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1501)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1501)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1501)) ;
        }
        {
        ioArgument_ioFieldMap.modifier_insertKey (var_varName, GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_parser.galgas", 1502)), function_valueWithMap (var_newMap, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1502)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1502)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1502)) ;
        }
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'printVariable'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_printVariable (GALGAS_uint inArgument_indent,
                            const GALGAS_Ttype constinArgument_variableType,
                            const GALGAS_Tvalue constinArgument_variableValue,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  inArgument_indent = inArgument_indent.add_operation (GALGAS_uint ((uint32_t) 4U), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1513)) ;
  GALGAS_string var_offset = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), inArgument_indent  COMMA_SOURCE_FILE ("template_parser.galgas", 1514)) ;
  switch (constinArgument_variableType.enumValue ()) {
  case GALGAS_Ttype::kNotBuilt:
    break ;
  case GALGAS_Ttype::kEnum_boolType:
    {
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_variableValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_parser.galgas", 1517)).objectCompare (GALGAS_sint_36__34_ ((int64_t) 1LL))).boolEnum () ;
      if (kBoolTrue == test_0) {
        inCompiler->printMessage (var_offset.add_operation (GALGAS_string ("true\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1518))  COMMA_SOURCE_FILE ("template_parser.galgas", 1518)) ;
      }else if (kBoolFalse == test_0) {
        inCompiler->printMessage (var_offset.add_operation (GALGAS_string ("false\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1520))  COMMA_SOURCE_FILE ("template_parser.galgas", 1520)) ;
      }
    }
    break ;
  case GALGAS_Ttype::kEnum_intType:
    {
      inCompiler->printMessage (var_offset.add_operation (constinArgument_variableValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_parser.galgas", 1523)).getter_string (SOURCE_FILE ("template_parser.galgas", 1523)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1523)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1523))  COMMA_SOURCE_FILE ("template_parser.galgas", 1523)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_floatType:
    {
      inCompiler->printMessage (var_offset.add_operation (constinArgument_variableValue.getter_mFloatValue (SOURCE_FILE ("template_parser.galgas", 1525)).getter_string (SOURCE_FILE ("template_parser.galgas", 1525)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1525)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1525))  COMMA_SOURCE_FILE ("template_parser.galgas", 1525)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_stringType:
    {
      inCompiler->printMessage (var_offset.add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1527)).add_operation (constinArgument_variableValue.getter_mStringValue (SOURCE_FILE ("template_parser.galgas", 1527)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1527)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1527))  COMMA_SOURCE_FILE ("template_parser.galgas", 1527)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_enumType:
    {
      inCompiler->printMessage (var_offset.add_operation (constinArgument_variableValue.getter_mStringValue (SOURCE_FILE ("template_parser.galgas", 1529)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1529)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1529))  COMMA_SOURCE_FILE ("template_parser.galgas", 1529)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_listType:
    {
      cEnumerator_TfieldMapList enumerator_45548 (constinArgument_variableValue.getter_mMapListValue (SOURCE_FILE ("template_parser.galgas", 1531)), kEnumeration_up) ;
      GALGAS_uint index_45511 ((uint32_t) 0) ;
      while (enumerator_45548.hasCurrentObject ()) {
        inCompiler->printMessage (var_offset.add_operation (GALGAS_string ("item at "), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1532)).add_operation (index_45511.getter_string (SOURCE_FILE ("template_parser.galgas", 1532)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1532)).add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1532))  COMMA_SOURCE_FILE ("template_parser.galgas", 1532)) ;
        {
        routine_printVariable (inArgument_indent, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1533)), GALGAS_Tvalue::constructor_new (GALGAS_sint_36__34_ ((int64_t) 0LL), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_parser.galgas", 1533)), enumerator_45548.current_mMap (HERE), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1533)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1533))  COMMA_SOURCE_FILE ("template_parser.galgas", 1533)), inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1533)) ;
        }
        enumerator_45548.gotoNextObject () ;
        index_45511.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1531)) ;
      }
    }
    break ;
  case GALGAS_Ttype::kEnum_mapType:
    {
      cEnumerator_TfieldMap enumerator_45814 (constinArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1536)), kEnumeration_up) ;
      while (enumerator_45814.hasCurrentObject ()) {
        inCompiler->printMessage (var_offset.add_operation (enumerator_45814.current_lkey (HERE).getter_string (SOURCE_FILE ("template_parser.galgas", 1537)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1537)).add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1537))  COMMA_SOURCE_FILE ("template_parser.galgas", 1537)) ;
        {
        routine_printVariable (inArgument_indent, enumerator_45814.current_mType (HERE), enumerator_45814.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1538)) ;
        }
        enumerator_45814.gotoNextObject () ;
      }
    }
    break ;
  case GALGAS_Ttype::kEnum_structType:
    {
      cEnumerator_TfieldMap enumerator_45966 (constinArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1541)), kEnumeration_up) ;
      while (enumerator_45966.hasCurrentObject ()) {
        inCompiler->printMessage (var_offset.add_operation (enumerator_45966.current_lkey (HERE).getter_string (SOURCE_FILE ("template_parser.galgas", 1542)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1542)).add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1542))  COMMA_SOURCE_FILE ("template_parser.galgas", 1542)) ;
        {
        routine_printVariable (inArgument_indent, enumerator_45966.current_mType (HERE), enumerator_45966.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1543)) ;
        }
        enumerator_45966.gotoNextObject () ;
      }
    }
    break ;
  case GALGAS_Ttype::kEnum_unconstructedType:
  case GALGAS_Ttype::kEnum_functionType:
    {
    }
    break ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'structCompare'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint function_structCompare (const GALGAS_TfieldMap & constinArgument_s_31_,
                                    const GALGAS_TfieldMap & constinArgument_s_32_,
                                    GALGAS_sortingKeyList inArgument_fieldList,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint result_result ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, inArgument_fieldList.getter_length (SOURCE_FILE ("template_parser.galgas", 1561)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_field ;
    GALGAS_lsint var_order ;
    {
    inArgument_fieldList.modifier_popFirst (var_field, var_order, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1564)) ;
    }
    GALGAS_Ttype var_s_31_Type ;
    GALGAS_Tvalue var_s_31_Value ;
    constinArgument_s_31_.method_searchKey (var_field, var_s_31_Type, var_s_31_Value, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1567)) ;
    GALGAS_Ttype var_s_32_Type ;
    GALGAS_Tvalue var_s_32_Value ;
    constinArgument_s_32_.method_searchKey (var_field, var_s_32_Type, var_s_32_Value, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1570)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_s_31_Type.objectCompare (var_s_32_Type)).operator_and (GALGAS_bool (kIsEqual, var_s_31_Type.objectCompare (GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_parser.galgas", 1571)))) COMMA_SOURCE_FILE ("template_parser.galgas", 1571)).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, var_s_31_Value.getter_mInt_36__34_Value (SOURCE_FILE ("template_parser.galgas", 1573)).objectCompare (var_s_32_Value.getter_mInt_36__34_Value (SOURCE_FILE ("template_parser.galgas", 1573)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_result = GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1575)).multiply_operation (var_order.getter_sint (SOURCE_FILE ("template_parser.galgas", 1575)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1575)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsStrictSup, var_s_31_Value.getter_mInt_36__34_Value (SOURCE_FILE ("template_parser.galgas", 1577)).objectCompare (var_s_32_Value.getter_mInt_36__34_Value (SOURCE_FILE ("template_parser.galgas", 1577)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_result = GALGAS_sint ((int32_t) 1L).multiply_operation (var_order.getter_sint (SOURCE_FILE ("template_parser.galgas", 1579)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1579)) ;
        }else if (kBoolFalse == test_3) {
          result_result = function_structCompare (constinArgument_s_31_, constinArgument_s_32_, inArgument_fieldList, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1582)) ;
        }
      }
    }else if (kBoolFalse == test_1) {
      GALGAS_location location_4 (var_field.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_4, GALGAS_string ("unsigned sort key required")  COMMA_SOURCE_FILE ("template_parser.galgas", 1586)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_sint ((int32_t) 0L) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_structCompare [4] = {
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_sortingKeyList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_structCompare (C_Compiler * inCompiler,
                                                              const cObjectArray & inEffectiveParameterArray,
                                                              const GALGAS_location & /* §§ inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMap operand0 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_TfieldMap operand1 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_sortingKeyList operand2 = GALGAS_sortingKeyList::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                               inCompiler
                                                                               COMMA_THERE) ;
  return function_structCompare (operand0,
                                 operand1,
                                 operand2,
                                 inCompiler
                                 COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_structCompare ("structCompare",
                                                               functionWithGenericHeader_structCompare,
                                                               & kTypeDescriptor_GALGAS_sint,
                                                               3,
                                                               functionArgs_structCompare) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Routine 'swap'                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_swap (GALGAS_TfieldMapList & ioArgument_t,
                   const GALGAS_uint constinArgument_index_31_,
                   const GALGAS_uint constinArgument_index_32_,
                   C_Compiler * inCompiler
                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TfieldMap var_temp = ioArgument_t.getter_mMapAtIndex (constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1598)) ;
  {
  ioArgument_t.modifier_setMMapAtIndex (ioArgument_t.getter_mMapAtIndex (constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1599)), constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1599)) ;
  }
  {
  ioArgument_t.modifier_setMMapAtIndex (var_temp, constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1600)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'partition'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_partition (GALGAS_TfieldMapList & ioArgument_t,
                        GALGAS_uint inArgument_min,
                        GALGAS_uint inArgument_max,
                        const GALGAS_sortingKeyList constinArgument_fieldList,
                        GALGAS_uint & ioArgument_pivotIndex,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TfieldMap var_pivot = ioArgument_t.getter_mMapAtIndex (ioArgument_pivotIndex, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1609)) ;
  {
  routine_swap (ioArgument_t, ioArgument_pivotIndex, inArgument_max, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1610)) ;
  }
  GALGAS_uint var_storeIndex = inArgument_min ;
  GALGAS_uint var_i = inArgument_min ;
  if (inArgument_max.substract_operation (inArgument_min, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1613)).isValid ()) {
    uint32_t variant_47715 = inArgument_max.substract_operation (inArgument_min, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1613)).uintValue () ;
    bool loop_47715 = true ;
    while (loop_47715) {
      loop_47715 = GALGAS_bool (kIsStrictInf, var_i.objectCompare (inArgument_max)).isValid () ;
      if (loop_47715) {
        loop_47715 = GALGAS_bool (kIsStrictInf, var_i.objectCompare (inArgument_max)).boolValue () ;
      }
      if (loop_47715 && (0 == variant_47715)) {
        loop_47715 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_parser.galgas", 1613)) ;
      }
      if (loop_47715) {
        variant_47715 -- ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, function_structCompare (ioArgument_t.getter_mMapAtIndex (var_i, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1615)), var_pivot, constinArgument_fieldList, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1615)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1615)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          routine_swap (ioArgument_t, var_i, var_storeIndex, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1616)) ;
          }
          var_storeIndex.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1617)) ;
        }
        var_i.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1619)) ;
      }
    }
  }
  {
  routine_swap (ioArgument_t, var_storeIndex, inArgument_max, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1621)) ;
  }
  ioArgument_pivotIndex = var_storeIndex ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'quickSort'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_quickSort (GALGAS_TfieldMapList & ioArgument_t,
                        const GALGAS_uint constinArgument_min,
                        const GALGAS_uint constinArgument_max,
                        const GALGAS_sortingKeyList constinArgument_fieldList,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, constinArgument_min.objectCompare (constinArgument_max)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_uint var_pivotIndex = constinArgument_max.add_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1632)).divide_operation (GALGAS_uint ((uint32_t) 2U), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1632)) ;
    {
    routine_partition (ioArgument_t, constinArgument_min, constinArgument_max, constinArgument_fieldList, var_pivotIndex, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1634)) ;
    }
    {
    routine_quickSort (ioArgument_t, constinArgument_min, var_pivotIndex, constinArgument_fieldList, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1635)) ;
    }
    {
    routine_quickSort (ioArgument_t, var_pivotIndex.add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1636)), constinArgument_max, constinArgument_fieldList, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1636)) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Once function 'allowedFunctions'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_stringset onceFunction_allowedFunctions (C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringset result_outAllowedFunctionSet ; // Returned variable
  result_outAllowedFunctionSet = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("template_invocation.galgas", 28)) ;
  result_outAllowedFunctionSet.addAssign_operation (GALGAS_string ("testFunction")  COMMA_SOURCE_FILE ("template_invocation.galgas", 29)) ;
  result_outAllowedFunctionSet.addAssign_operation (GALGAS_string ("tasks")  COMMA_SOURCE_FILE ("template_invocation.galgas", 30)) ;
  result_outAllowedFunctionSet.addAssign_operation (GALGAS_string ("trueFalse")  COMMA_SOURCE_FILE ("template_invocation.galgas", 31)) ;
  result_outAllowedFunctionSet.addAssign_operation (GALGAS_string ("yesNo")  COMMA_SOURCE_FILE ("template_invocation.galgas", 32)) ;
//---
  return result_outAllowedFunctionSet ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_allowedFunctions = false ;
static GALGAS_stringset gOnceFunctionResult_allowedFunctions ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset function_allowedFunctions (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_allowedFunctions) {
    gOnceFunctionResult_allowedFunctions = onceFunction_allowedFunctions (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_allowedFunctions = true ;
  }
  return gOnceFunctionResult_allowedFunctions ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_allowedFunctions (void) {
  gOnceFunctionResult_allowedFunctions.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_allowedFunctions (NULL,
                                                              releaseOnceFunctionResult_allowedFunctions) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_allowedFunctions [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_allowedFunctions (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_allowedFunctions (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_allowedFunctions ("allowedFunctions",
                                                                  functionWithGenericHeader_allowedFunctions,
                                                                  & kTypeDescriptor_GALGAS_stringset,
                                                                  0,
                                                                  functionArgs_allowedFunctions) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'fullPrefix'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_fullPrefix (const GALGAS_TfieldMap & constinArgument_vars,
                                   const GALGAS_lstring & constinArgument_prefix,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_full ; // Returned variable
  GALGAS_string var_stringPrefix = constinArgument_prefix.getter_string (SOURCE_FILE ("template_invocation.galgas", 40)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_stringPrefix.objectCompare (GALGAS_string ("compiler"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_Ttype var_type ;
    GALGAS_Tvalue var_value ;
    constinArgument_vars.method_searchKey (function_lstringWith (GALGAS_string ("COMPILER"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 44)), var_type, var_value, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 44)) ;
    var_stringPrefix.dotAssign_operation (GALGAS_string ("/").add_operation (var_value.getter_mStringValue (SOURCE_FILE ("template_invocation.galgas", 45)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 45))  COMMA_SOURCE_FILE ("template_invocation.galgas", 45)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_stringPrefix.objectCompare (GALGAS_string ("linker"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_Ttype var_type ;
      GALGAS_Tvalue var_value ;
      constinArgument_vars.method_searchKey (function_lstringWith (GALGAS_string ("LINKER"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 49)), var_type, var_value, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 49)) ;
      var_stringPrefix.dotAssign_operation (GALGAS_string ("/").add_operation (var_value.getter_mStringValue (SOURCE_FILE ("template_invocation.galgas", 50)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 50))  COMMA_SOURCE_FILE ("template_invocation.galgas", 50)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_stringPrefix.objectCompare (GALGAS_string ("assembler"))).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_Ttype var_type ;
        GALGAS_Tvalue var_value ;
        constinArgument_vars.method_searchKey (function_lstringWith (GALGAS_string ("ASSEMBLER"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 54)), var_type, var_value, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 54)) ;
        var_stringPrefix.dotAssign_operation (GALGAS_string ("/").add_operation (var_value.getter_mStringValue (SOURCE_FILE ("template_invocation.galgas", 55)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 55))  COMMA_SOURCE_FILE ("template_invocation.galgas", 55)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_stringPrefix.objectCompare (GALGAS_string ("ROOT"))).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_stringPrefix = GALGAS_string::makeEmptyString () ;
        }
      }
    }
  }
  result_full = var_stringPrefix ;
//---
  return result_full ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_fullPrefix [3] = {
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_fullPrefix (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* §§ inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMap operand0 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_fullPrefix (operand0,
                              operand1,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_fullPrefix ("fullPrefix",
                                                            functionWithGenericHeader_fullPrefix,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            2,
                                                            functionArgs_fullPrefix) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'displayTypeAndValue'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_displayTypeAndValue (const GALGAS_Ttype & constinArgument_inType,
                                            const GALGAS_Tvalue & constinArgument_inValue,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outResult ; // Returned variable
  switch (constinArgument_inType.enumValue ()) {
  case GALGAS_Ttype::kNotBuilt:
    break ;
  case GALGAS_Ttype::kEnum_boolType:
    {
      GALGAS_string temp_0 ;
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_inValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_invocation.galgas", 75)).objectCompare (GALGAS_sint_36__34_ ((int64_t) 1LL))).boolEnum () ;
      if (kBoolTrue == test_1) {
        temp_0 = GALGAS_string ("yes") ;
      }else if (kBoolFalse == test_1) {
        temp_0 = GALGAS_string ("no") ;
      }
      result_outResult = GALGAS_string ("bool: ").add_operation (temp_0, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 75)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_intType:
    {
      result_outResult = GALGAS_string ("unsigned: ").add_operation (constinArgument_inValue.getter_mInt_36__34_Value (SOURCE_FILE ("template_invocation.galgas", 77)).getter_string (SOURCE_FILE ("template_invocation.galgas", 77)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 77)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_floatType:
    {
      result_outResult = GALGAS_string ("float: ").add_operation (constinArgument_inValue.getter_mFloatValue (SOURCE_FILE ("template_invocation.galgas", 79)).getter_string (SOURCE_FILE ("template_invocation.galgas", 79)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 79)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_stringType:
    {
      result_outResult = GALGAS_string ("string: '").add_operation (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_invocation.galgas", 81)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 81)).add_operation (GALGAS_string ("'"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 81)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_listType:
    {
      GALGAS_string temp_2 ;
      const enumGalgasBool test_3 = GALGAS_bool (kIsStrictSup, constinArgument_inValue.getter_mMapListValue (SOURCE_FILE ("template_invocation.galgas", 83)).getter_length (SOURCE_FILE ("template_invocation.galgas", 83)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
      if (kBoolTrue == test_3) {
        temp_2 = GALGAS_string ("s") ;
      }else if (kBoolFalse == test_3) {
        temp_2 = GALGAS_string::makeEmptyString () ;
      }
      result_outResult = GALGAS_string ("list, ").add_operation (constinArgument_inValue.getter_mMapListValue (SOURCE_FILE ("template_invocation.galgas", 83)).getter_length (SOURCE_FILE ("template_invocation.galgas", 83)).getter_string (SOURCE_FILE ("template_invocation.galgas", 83)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 83)).add_operation (GALGAS_string (" element"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 83)).add_operation (temp_2, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 83)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 83)) ;
      cEnumerator_TfieldMapList enumerator_2746 (constinArgument_inValue.getter_mMapListValue (SOURCE_FILE ("template_invocation.galgas", 84)), kEnumeration_up) ;
      GALGAS_uint index_2715 ((uint32_t) 0) ;
      while (enumerator_2746.hasCurrentObject ()) {
        result_outResult.dotAssign_operation (GALGAS_string ("\n"
          "  #").add_operation (index_2715.getter_string (SOURCE_FILE ("template_invocation.galgas", 85)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 85)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 85))  COMMA_SOURCE_FILE ("template_invocation.galgas", 85)) ;
        cEnumerator_TfieldMap enumerator_2824 (enumerator_2746.current_mMap (HERE), kEnumeration_up) ;
        while (enumerator_2824.hasCurrentObject ()) {
          result_outResult.dotAssign_operation (GALGAS_string ("'").add_operation (enumerator_2824.current_lkey (HERE).getter_string (SOURCE_FILE ("template_invocation.galgas", 87)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 87)).add_operation (GALGAS_string ("' "), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 87))  COMMA_SOURCE_FILE ("template_invocation.galgas", 87)) ;
          switch (enumerator_2824.current_mType (HERE).enumValue ()) {
          case GALGAS_Ttype::kNotBuilt:
            break ;
          case GALGAS_Ttype::kEnum_boolType:
            {
              GALGAS_string temp_4 ;
              const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, enumerator_2824.current_mValue (HERE).getter_mInt_36__34_Value (SOURCE_FILE ("template_invocation.galgas", 90)).objectCompare (GALGAS_sint_36__34_ ((int64_t) 1LL))).boolEnum () ;
              if (kBoolTrue == test_5) {
                temp_4 = GALGAS_string ("yes") ;
              }else if (kBoolFalse == test_5) {
                temp_4 = GALGAS_string ("no") ;
              }
              result_outResult.dotAssign_operation (GALGAS_string ("bool: ").add_operation (temp_4, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 90))  COMMA_SOURCE_FILE ("template_invocation.galgas", 90)) ;
            }
            break ;
          case GALGAS_Ttype::kEnum_intType:
            {
              result_outResult.dotAssign_operation (GALGAS_string ("unsigned: ").add_operation (enumerator_2824.current_mValue (HERE).getter_mInt_36__34_Value (SOURCE_FILE ("template_invocation.galgas", 92)).getter_string (SOURCE_FILE ("template_invocation.galgas", 92)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 92))  COMMA_SOURCE_FILE ("template_invocation.galgas", 92)) ;
            }
            break ;
          case GALGAS_Ttype::kEnum_floatType:
            {
              result_outResult.dotAssign_operation (GALGAS_string ("float: ").add_operation (enumerator_2824.current_mValue (HERE).getter_mFloatValue (SOURCE_FILE ("template_invocation.galgas", 94)).getter_string (SOURCE_FILE ("template_invocation.galgas", 94)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 94))  COMMA_SOURCE_FILE ("template_invocation.galgas", 94)) ;
            }
            break ;
          case GALGAS_Ttype::kEnum_stringType:
            {
              result_outResult.dotAssign_operation (GALGAS_string ("string: '").add_operation (enumerator_2824.current_mValue (HERE).getter_mStringValue (SOURCE_FILE ("template_invocation.galgas", 96)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 96)).add_operation (GALGAS_string ("'"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 96))  COMMA_SOURCE_FILE ("template_invocation.galgas", 96)) ;
            }
            break ;
          case GALGAS_Ttype::kEnum_listType:
          case GALGAS_Ttype::kEnum_structType:
          case GALGAS_Ttype::kEnum_mapType:
            {
            }
            break ;
          case GALGAS_Ttype::kEnum_enumType:
            {
            }
            break ;
          case GALGAS_Ttype::kEnum_unconstructedType:
          case GALGAS_Ttype::kEnum_functionType:
            {
              inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 100)), GALGAS_string ("internal error, unconstructed type found")  COMMA_SOURCE_FILE ("template_invocation.galgas", 100)) ;
            }
            break ;
          }
          if (enumerator_2824.hasNextObject ()) {
            result_outResult.dotAssign_operation (GALGAS_string (", ")  COMMA_SOURCE_FILE ("template_invocation.galgas", 102)) ;
          }
          enumerator_2824.gotoNextObject () ;
        }
        enumerator_2746.gotoNextObject () ;
        index_2715.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 84)) ;
      }
    }
    break ;
  case GALGAS_Ttype::kEnum_structType:
  case GALGAS_Ttype::kEnum_mapType:
    {
      result_outResult = GALGAS_string::makeEmptyString () ;
    }
    break ;
  case GALGAS_Ttype::kEnum_enumType:
    {
      result_outResult = GALGAS_string::makeEmptyString () ;
    }
    break ;
  case GALGAS_Ttype::kEnum_unconstructedType:
  case GALGAS_Ttype::kEnum_functionType:
    {
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 110)), GALGAS_string ("internal error, unconstructed type found")  COMMA_SOURCE_FILE ("template_invocation.galgas", 110)) ;
      result_outResult.drop () ; // Release error dropped variable
    }
    break ;
  }
//---
  return result_outResult ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_displayTypeAndValue [3] = {
  & kTypeDescriptor_GALGAS_Ttype,
  & kTypeDescriptor_GALGAS_Tvalue,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_displayTypeAndValue (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* §§ inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_Ttype operand0 = GALGAS_Ttype::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                             inCompiler
                                                             COMMA_THERE) ;
  const GALGAS_Tvalue operand1 = GALGAS_Tvalue::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_displayTypeAndValue (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_displayTypeAndValue ("displayTypeAndValue",
                                                                     functionWithGenericHeader_displayTypeAndValue,
                                                                     & kTypeDescriptor_GALGAS_string,
                                                                     2,
                                                                     functionArgs_displayTypeAndValue) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'displayTemplateVariableMap'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_displayTemplateVariableMap (const GALGAS_TfieldMap constinArgument_inTemplateVariableMap,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_TfieldMap enumerator_3929 (constinArgument_inTemplateVariableMap, kEnumeration_up) ;
  while (enumerator_3929.hasCurrentObject ()) {
    inCompiler->printMessage (GALGAS_string ("'").add_operation (enumerator_3929.current_lkey (HERE).getter_string (SOURCE_FILE ("template_invocation.galgas", 119)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 119)).add_operation (GALGAS_string ("' "), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 119)).add_operation (function_displayTypeAndValue (enumerator_3929.current_mType (HERE), enumerator_3929.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 119)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 119)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 119))  COMMA_SOURCE_FILE ("template_invocation.galgas", 119)) ;
    enumerator_3929.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'displayPathList'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_displayPathList (const GALGAS_stringlist constinArgument_pathList,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->printMessage (GALGAS_string (" -----------------------------------------\n")  COMMA_SOURCE_FILE ("template_invocation.galgas", 125)) ;
  cEnumerator_stringlist enumerator_4147 (constinArgument_pathList, kEnumeration_up) ;
  while (enumerator_4147.hasCurrentObject ()) {
    inCompiler->printMessage (GALGAS_string (" - '").add_operation (enumerator_4147.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 127)).add_operation (GALGAS_string ("'\n"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 127))  COMMA_SOURCE_FILE ("template_invocation.galgas", 127)) ;
    enumerator_4147.gotoNextObject () ;
  }
  inCompiler->printMessage (GALGAS_string (" -----------------------------------------\n")  COMMA_SOURCE_FILE ("template_invocation.galgas", 129)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'findFileInHierarchy'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_findFileInHierarchy (const GALGAS_string constinArgument_file,
                                  const GALGAS_string constinArgument_rootPath,
                                  const GALGAS_string constinArgument_searchPath,
                                  GALGAS_stringlist & ioArgument_searchedPathList,
                                  GALGAS_bool & ioArgument_found,
                                  GALGAS_string & ioArgument_fullPath,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_partialPath = constinArgument_searchPath ;
  if (constinArgument_searchPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 142)).isValid ()) {
    uint32_t variant_4543 = constinArgument_searchPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 142)).uintValue () ;
    bool loop_4543 = true ;
    while (loop_4543) {
      loop_4543 = GALGAS_bool (kIsStrictSup, var_partialPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 143)).objectCompare (GALGAS_uint ((uint32_t) 0U))).operator_and (ioArgument_found.operator_not (SOURCE_FILE ("template_invocation.galgas", 143)) COMMA_SOURCE_FILE ("template_invocation.galgas", 143)).isValid () ;
      if (loop_4543) {
        loop_4543 = GALGAS_bool (kIsStrictSup, var_partialPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 143)).objectCompare (GALGAS_uint ((uint32_t) 0U))).operator_and (ioArgument_found.operator_not (SOURCE_FILE ("template_invocation.galgas", 143)) COMMA_SOURCE_FILE ("template_invocation.galgas", 143)).boolValue () ;
      }
      if (loop_4543 && (0 == variant_4543)) {
        loop_4543 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_invocation.galgas", 142)) ;
      }
      if (loop_4543) {
        variant_4543 -- ;
        GALGAS_string var_fullFilePath = constinArgument_rootPath.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 144)).add_operation (var_partialPath, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 144)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 144)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 144)) ;
        ioArgument_searchedPathList.addAssign_operation (var_fullFilePath  COMMA_SOURCE_FILE ("template_invocation.galgas", 145)) ;
        ioArgument_found = var_fullFilePath.getter_fileExists (SOURCE_FILE ("template_invocation.galgas", 146)) ;
        const enumGalgasBool test_0 = ioArgument_found.boolEnum () ;
        if (kBoolTrue == test_0) {
          ioArgument_fullPath = var_fullFilePath ;
        }else if (kBoolFalse == test_0) {
          var_partialPath = var_partialPath.getter_stringByDeletingLastPathComponent (SOURCE_FILE ("template_invocation.galgas", 150)) ;
        }
      }
    }
  }
  const enumGalgasBool test_1 = ioArgument_found.operator_not (SOURCE_FILE ("template_invocation.galgas", 153)).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_string var_fullFilePath = constinArgument_rootPath.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 154)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 154)) ;
    ioArgument_searchedPathList.addAssign_operation (var_fullFilePath  COMMA_SOURCE_FILE ("template_invocation.galgas", 155)) ;
    ioArgument_found = var_fullFilePath.getter_fileExists (SOURCE_FILE ("template_invocation.galgas", 156)) ;
    const enumGalgasBool test_2 = ioArgument_found.boolEnum () ;
    if (kBoolTrue == test_2) {
      ioArgument_fullPath = var_fullFilePath ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'findAllFilesInHierarchy'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_findAllFilesInHierarchy (const GALGAS_string constinArgument_file,
                                      const GALGAS_string constinArgument_rootPath,
                                      const GALGAS_string constinArgument_searchPath,
                                      GALGAS_stringlist & ioArgument_searchedPathList,
                                      GALGAS_stringlist & ioArgument_fullPaths,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_partialPath = constinArgument_searchPath ;
  if (constinArgument_searchPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 172)).isValid ()) {
    uint32_t variant_5401 = constinArgument_searchPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 172)).uintValue () ;
    bool loop_5401 = true ;
    while (loop_5401) {
      loop_5401 = GALGAS_bool (kIsStrictSup, var_partialPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 173)).objectCompare (GALGAS_uint ((uint32_t) 0U))).isValid () ;
      if (loop_5401) {
        loop_5401 = GALGAS_bool (kIsStrictSup, var_partialPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 173)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolValue () ;
      }
      if (loop_5401 && (0 == variant_5401)) {
        loop_5401 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_invocation.galgas", 172)) ;
      }
      if (loop_5401) {
        variant_5401 -- ;
        GALGAS_string var_fullFilePath = constinArgument_rootPath.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 174)).add_operation (var_partialPath, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 174)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 174)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 174)) ;
        ioArgument_searchedPathList.addAssign_operation (var_fullFilePath  COMMA_SOURCE_FILE ("template_invocation.galgas", 175)) ;
        const enumGalgasBool test_0 = var_fullFilePath.getter_fileExists (SOURCE_FILE ("template_invocation.galgas", 176)).boolEnum () ;
        if (kBoolTrue == test_0) {
          ioArgument_fullPaths.addAssign_operation (var_fullFilePath  COMMA_SOURCE_FILE ("template_invocation.galgas", 177)) ;
        }
        GALGAS_string var_newPartialPath = var_partialPath.getter_stringByDeletingLastPathComponent (SOURCE_FILE ("template_invocation.galgas", 179)) ;
        const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_newPartialPath.objectCompare (var_partialPath)).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_partialPath = GALGAS_string::makeEmptyString () ;
        }else if (kBoolFalse == test_1) {
          var_partialPath = var_newPartialPath ;
        }
      }
    }
  }
  GALGAS_string var_fullFilePath = constinArgument_rootPath.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 186)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 186)) ;
  ioArgument_searchedPathList.addAssign_operation (var_fullFilePath  COMMA_SOURCE_FILE ("template_invocation.galgas", 187)) ;
  const enumGalgasBool test_2 = var_fullFilePath.getter_fileExists (SOURCE_FILE ("template_invocation.galgas", 188)).boolEnum () ;
  if (kBoolTrue == test_2) {
    ioArgument_fullPaths.addAssign_operation (var_fullFilePath  COMMA_SOURCE_FILE ("template_invocation.galgas", 189)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'findFileInPathList'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_findFileInPathList (const GALGAS_string constinArgument_file,
                                 const GALGAS_stringlist constinArgument_rootPathList,
                                 const GALGAS_string constinArgument_searchPath,
                                 GALGAS_stringlist & outArgument_searchedPathList,
                                 GALGAS_bool & outArgument_found,
                                 GALGAS_string & outArgument_fullPath,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_searchedPathList.drop () ; // Release 'out' argument
  outArgument_found.drop () ; // Release 'out' argument
  outArgument_fullPath.drop () ; // Release 'out' argument
  outArgument_searchedPathList = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("template_invocation.galgas", 202)) ;
  outArgument_found = GALGAS_bool (false) ;
  outArgument_fullPath = GALGAS_string::makeEmptyString () ;
  cEnumerator_stringlist enumerator_6389 (constinArgument_rootPathList, kEnumeration_up) ;
  while (enumerator_6389.hasCurrentObject ()) {
    {
    routine_findFileInHierarchy (constinArgument_file, enumerator_6389.current_mValue (HERE), constinArgument_searchPath, outArgument_searchedPathList, outArgument_found, outArgument_fullPath, inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 207)) ;
    }
    enumerator_6389.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'findAllFilesInPathList'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_findAllFilesInPathList (const GALGAS_string constinArgument_file,
                                     const GALGAS_stringlist constinArgument_rootPathList,
                                     const GALGAS_string constinArgument_searchPath,
                                     GALGAS_stringlist & outArgument_searchedPathList,
                                     GALGAS_stringlist & outArgument_fullPaths,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_searchedPathList.drop () ; // Release 'out' argument
  outArgument_fullPaths.drop () ; // Release 'out' argument
  outArgument_searchedPathList = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("template_invocation.galgas", 226)) ;
  outArgument_fullPaths = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("template_invocation.galgas", 227)) ;
  cEnumerator_stringlist enumerator_6910 (constinArgument_rootPathList, kEnumeration_up) ;
  while (enumerator_6910.hasCurrentObject ()) {
    {
    routine_findAllFilesInHierarchy (constinArgument_file, enumerator_6910.current_mValue (HERE), constinArgument_searchPath, outArgument_searchedPathList, outArgument_fullPaths, inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 230)) ;
    }
    enumerator_6910.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'templateInvocation'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_templateInvocation (const GALGAS_lstring constinArgument_inTemplateName,
                                 const GALGAS_string constinArgument_inPrefix,
                                 const GALGAS_string constinArgument_inPath,
                                 const GALGAS_string constinArgument_inTemplateDirectory,
                                 const GALGAS_bool constinArgument_inErrorIfNotFound,
                                 const GALGAS_TfieldMap constinArgument_inTemplateVariableMap,
                                 GALGAS_string & ioArgument_ioResultingString,
                                 GALGAS_bool & outArgument_outNoErrorOccured,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outNoErrorOccured.drop () ; // Release 'out' argument
  outArgument_outNoErrorOccured = GALGAS_bool (true) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("template_invocation.galgas", 252)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_string var_templateDir = constinArgument_inTemplateDirectory ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_templateDir.getter_length (SOURCE_FILE ("template_invocation.galgas", 254)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_location location_2 (constinArgument_inTemplateName.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_2, GALGAS_string ("the '--goil-templates' option or the environment variable GOIL_TEMPLATES is required for generating code")  COMMA_SOURCE_FILE ("template_invocation.galgas", 255)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_3 = var_templateDir.getter_directoryExists (SOURCE_FILE ("template_invocation.galgas", 256)).operator_not (SOURCE_FILE ("template_invocation.galgas", 256)).boolEnum () ;
      if (kBoolTrue == test_3) {
        GALGAS_location location_4 (constinArgument_inTemplateName.getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_4, GALGAS_string ("the template path '").add_operation (var_templateDir, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 257)).add_operation (GALGAS_string ("' exists but is not a valid directory path"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 257))  COMMA_SOURCE_FILE ("template_invocation.galgas", 257)) ;
      }else if (kBoolFalse == test_3) {
        GALGAS_string var_targetDir = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()) ;
        GALGAS_string var_fullTemplateDir ;
        const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, constinArgument_inPrefix.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_5) {
          var_fullTemplateDir = var_templateDir ;
        }else if (kBoolFalse == test_5) {
          var_fullTemplateDir = var_templateDir.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 264)).add_operation (constinArgument_inPrefix, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 264)) ;
        }
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_targetDir.getter_length (SOURCE_FILE ("template_invocation.galgas", 266)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_6) {
          GALGAS_location location_7 (constinArgument_inTemplateName.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_7, GALGAS_string ("the '--target' (or '-t') option is required for generating code")  COMMA_SOURCE_FILE ("template_invocation.galgas", 267)) ;
        }else if (kBoolFalse == test_6) {
          const enumGalgasBool test_8 = var_fullTemplateDir.getter_directoryExists (SOURCE_FILE ("template_invocation.galgas", 268)).operator_not (SOURCE_FILE ("template_invocation.galgas", 268)).boolEnum () ;
          if (kBoolTrue == test_8) {
            GALGAS_location location_9 (constinArgument_inTemplateName.getter_location (HERE)) ; // Implicit use of 'location' getter
            inCompiler->emitSemanticError (location_9, GALGAS_string ("internal. no '").add_operation (var_fullTemplateDir, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 269)).add_operation (GALGAS_string ("' template found"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 269))  COMMA_SOURCE_FILE ("template_invocation.galgas", 269)) ;
          }else if (kBoolFalse == test_8) {
            GALGAS_stringlist var_pathList = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("template_invocation.galgas", 276)) ;
            GALGAS_bool var_found = GALGAS_bool (false) ;
            const enumGalgasBool test_10 = GALGAS_bool (kIsNotEqual, constinArgument_inPath.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
            if (kBoolTrue == test_10) {
              GALGAS_string var_userTemplateDir ;
              const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, constinArgument_inPrefix.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
              if (kBoolTrue == test_11) {
                var_userTemplateDir = constinArgument_inPath ;
              }else if (kBoolFalse == test_11) {
                var_userTemplateDir = constinArgument_inPath.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 283)).add_operation (constinArgument_inPrefix, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 283)) ;
              }
              GALGAS_string var_fullTemplatePath = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("template_invocation.galgas", 285)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 285)).add_operation (var_userTemplateDir, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 285)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 285)).add_operation (constinArgument_inTemplateName.getter_string (SOURCE_FILE ("template_invocation.galgas", 285)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 285)).add_operation (GALGAS_string (".goilTemplate"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 285)) ;
              var_pathList.addAssign_operation (var_fullTemplatePath  COMMA_SOURCE_FILE ("template_invocation.galgas", 286)) ;
              var_found = var_fullTemplatePath.getter_fileExists (SOURCE_FILE ("template_invocation.galgas", 287)) ;
              const enumGalgasBool test_12 = var_found.boolEnum () ;
              if (kBoolTrue == test_12) {
                GALGAS_Tvalue joker_9446 ; // Joker input parameter
                GALGAS_Ttype joker_9449 ; // Joker input parameter
                cGrammar_template_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_fullTemplatePath, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 289))  COMMA_SOURCE_FILE ("template_invocation.galgas", 289)), constinArgument_inPrefix, constinArgument_inPath, constinArgument_inTemplateDirectory, constinArgument_inTemplateVariableMap, ioArgument_ioResultingString, joker_9446, joker_9449  COMMA_SOURCE_FILE ("template_invocation.galgas", 289)) ;
              }
            }
            GALGAS_string var_targetTemplatePartialPath = var_targetDir ;
            if (var_targetDir.getter_length (SOURCE_FILE ("template_invocation.galgas", 293)).isValid ()) {
              uint32_t variant_9543 = var_targetDir.getter_length (SOURCE_FILE ("template_invocation.galgas", 293)).uintValue () ;
              bool loop_9543 = true ;
              while (loop_9543) {
                loop_9543 = GALGAS_bool (kIsStrictSup, var_targetTemplatePartialPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 294)).objectCompare (GALGAS_uint ((uint32_t) 0U))).operator_and (var_found.operator_not (SOURCE_FILE ("template_invocation.galgas", 294)) COMMA_SOURCE_FILE ("template_invocation.galgas", 294)).isValid () ;
                if (loop_9543) {
                  loop_9543 = GALGAS_bool (kIsStrictSup, var_targetTemplatePartialPath.getter_length (SOURCE_FILE ("template_invocation.galgas", 294)).objectCompare (GALGAS_uint ((uint32_t) 0U))).operator_and (var_found.operator_not (SOURCE_FILE ("template_invocation.galgas", 294)) COMMA_SOURCE_FILE ("template_invocation.galgas", 294)).boolValue () ;
                }
                if (loop_9543 && (0 == variant_9543)) {
                  loop_9543 = false ;
                  inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_invocation.galgas", 293)) ;
                }
                if (loop_9543) {
                  variant_9543 -- ;
                  GALGAS_string var_fullTemplatePath = var_fullTemplateDir.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 296)).add_operation (var_targetTemplatePartialPath, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 296)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 296)).add_operation (constinArgument_inTemplateName.getter_string (SOURCE_FILE ("template_invocation.galgas", 296)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 296)).add_operation (GALGAS_string (".goilTemplate"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 296)) ;
                  var_pathList.addAssign_operation (var_fullTemplatePath  COMMA_SOURCE_FILE ("template_invocation.galgas", 297)) ;
                  var_found = var_fullTemplatePath.getter_fileExists (SOURCE_FILE ("template_invocation.galgas", 298)) ;
                  const enumGalgasBool test_13 = var_found.boolEnum () ;
                  if (kBoolTrue == test_13) {
                    GALGAS_Tvalue joker_10101 ; // Joker input parameter
                    GALGAS_Ttype joker_10104 ; // Joker input parameter
                    cGrammar_template_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_fullTemplatePath, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 301))  COMMA_SOURCE_FILE ("template_invocation.galgas", 301)), constinArgument_inPrefix, constinArgument_inPath, constinArgument_inTemplateDirectory, constinArgument_inTemplateVariableMap, ioArgument_ioResultingString, joker_10101, joker_10104  COMMA_SOURCE_FILE ("template_invocation.galgas", 301)) ;
                  }else if (kBoolFalse == test_13) {
                    var_targetTemplatePartialPath = var_targetTemplatePartialPath.getter_stringByDeletingLastPathComponent (SOURCE_FILE ("template_invocation.galgas", 303)) ;
                  }
                }
              }
            }
            const enumGalgasBool test_14 = var_found.operator_not (SOURCE_FILE ("template_invocation.galgas", 306)).boolEnum () ;
            if (kBoolTrue == test_14) {
              GALGAS_string var_fullTemplatePath = var_fullTemplateDir.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 307)).add_operation (constinArgument_inTemplateName.getter_string (SOURCE_FILE ("template_invocation.galgas", 307)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 307)).add_operation (GALGAS_string (".goilTemplate"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 307)) ;
              var_pathList.addAssign_operation (var_fullTemplatePath  COMMA_SOURCE_FILE ("template_invocation.galgas", 308)) ;
              var_found = var_fullTemplatePath.getter_fileExists (SOURCE_FILE ("template_invocation.galgas", 309)) ;
              const enumGalgasBool test_15 = var_found.boolEnum () ;
              if (kBoolTrue == test_15) {
                GALGAS_Tvalue joker_10699 ; // Joker input parameter
                GALGAS_Ttype joker_10702 ; // Joker input parameter
                cGrammar_template_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_fullTemplatePath, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 312))  COMMA_SOURCE_FILE ("template_invocation.galgas", 312)), constinArgument_inPrefix, constinArgument_inPath, constinArgument_inTemplateDirectory, constinArgument_inTemplateVariableMap, ioArgument_ioResultingString, joker_10699, joker_10702  COMMA_SOURCE_FILE ("template_invocation.galgas", 312)) ;
              }
            }
            const enumGalgasBool test_16 = var_found.operator_not (SOURCE_FILE ("template_invocation.galgas", 315)).boolEnum () ;
            if (kBoolTrue == test_16) {
              outArgument_outNoErrorOccured = GALGAS_bool (false) ;
              const enumGalgasBool test_17 = constinArgument_inErrorIfNotFound.boolEnum () ;
              if (kBoolTrue == test_17) {
                GALGAS_string var_m = GALGAS_string ("cannot find a valid path for the '").add_operation (constinArgument_inTemplateName.getter_string (SOURCE_FILE ("template_invocation.galgas", 318)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 318)).add_operation (GALGAS_string ("' template; I have tried:"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 318)) ;
                cEnumerator_stringlist enumerator_10967 (var_pathList, kEnumeration_up) ;
                while (enumerator_10967.hasCurrentObject ()) {
                  var_m.dotAssign_operation (GALGAS_string ("\n"
                    "  - '").add_operation (enumerator_10967.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 320)).add_operation (GALGAS_string ("';"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 320))  COMMA_SOURCE_FILE ("template_invocation.galgas", 320)) ;
                  enumerator_10967.gotoNextObject () ;
                }
                GALGAS_location location_18 (constinArgument_inTemplateName.getter_location (HERE)) ; // Implicit use of 'location' getter
                inCompiler->emitSemanticError (location_18, var_m  COMMA_SOURCE_FILE ("template_invocation.galgas", 322)) ;
              }
            }
          }
        }
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'goil_template'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_goil_5F_template (const GALGAS_string & constinArgument_prefix,
                                         const GALGAS_TfieldMap & constinArgument_cfg,
                                         const GALGAS_string & constinArgument_name,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  {
  GALGAS_bool joker_958 ; // Joker input parameter
  routine_templateInvocation (GALGAS_lstring::constructor_new (constinArgument_name, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_routines.galgas", 34))  COMMA_SOURCE_FILE ("template_routines.galgas", 34)), constinArgument_prefix, GALGAS_string ("templates"), function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("template_routines.galgas", 37)), GALGAS_bool (true), constinArgument_cfg, result_result, joker_958, inCompiler  COMMA_SOURCE_FILE ("template_routines.galgas", 33)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_goil_5F_template [4] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_goil_5F_template (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* §§ inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_TfieldMap operand1 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_goil_5F_template (operand0,
                                    operand1,
                                    operand2,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_goil_5F_template ("goil_template",
                                                                  functionWithGenericHeader_goil_5F_template,
                                                                  & kTypeDescriptor_GALGAS_string,
                                                                  3,
                                                                  functionArgs_goil_5F_template) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'computeTemplate'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_computeTemplate (const GALGAS_string & constinArgument_prefix,
                                        const GALGAS_TfieldMap & constinArgument_cfg,
                                        const GALGAS_string & constinArgument_name,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  {
  GALGAS_bool joker_1247 ; // Joker input parameter
  routine_templateInvocation (GALGAS_lstring::constructor_new (constinArgument_name, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_routines.galgas", 51))  COMMA_SOURCE_FILE ("template_routines.galgas", 51)), constinArgument_prefix, GALGAS_string ("templates"), function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("template_routines.galgas", 54)), GALGAS_bool (true), constinArgument_cfg, result_result, joker_1247, inCompiler  COMMA_SOURCE_FILE ("template_routines.galgas", 50)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_computeTemplate [4] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_computeTemplate (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* §§ inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_TfieldMap operand1 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_computeTemplate (operand0,
                                   operand1,
                                   operand2,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_computeTemplate ("computeTemplate",
                                                                 functionWithGenericHeader_computeTemplate,
                                                                 & kTypeDescriptor_GALGAS_string,
                                                                 3,
                                                                 functionArgs_computeTemplate) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'trueFalse'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_trueFalse (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_inBool.boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("true") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("false") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_trueFalse [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_trueFalse (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* §§ inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_trueFalse (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_trueFalse ("trueFalse",
                                                           functionWithGenericHeader_trueFalse,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_trueFalse) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'TrueFalse'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_TrueFalse (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_inBool.boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("True") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("False") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_TrueFalse [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_TrueFalse (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* §§ inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_TrueFalse (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_TrueFalse ("TrueFalse",
                                                           functionWithGenericHeader_TrueFalse,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_TrueFalse) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Function 'yesNo'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_yesNo (const GALGAS_bool & constinArgument_inBool,
                              C_Compiler * /* inCompiler */
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_inBool.boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("YES") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("NO") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_yesNo [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_yesNo (C_Compiler * inCompiler,
                                                      const cObjectArray & inEffectiveParameterArray,
                                                      const GALGAS_location & /* §§ inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_yesNo (operand0,
                         inCompiler
                         COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_yesNo ("yesNo",
                                                       functionWithGenericHeader_yesNo,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       1,
                                                       functionArgs_yesNo) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'TRUEFALSE'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_TRUEFALSE (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_inBool.boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("TRUE") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("FALSE") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_TRUEFALSE [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_TRUEFALSE (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* §§ inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_TRUEFALSE (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_TRUEFALSE ("TRUEFALSE",
                                                           functionWithGenericHeader_TRUEFALSE,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_TRUEFALSE) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Bool options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_log ("goil_options",
                                         "generate_log",
                                         108,
                                         "logfile",
                                         "generate a goil.log file containing the a log of the compilation") ;

C_BoolCommandLineOption gOption_goil_5F_options_warnMultiple ("goil_options",
                                         "warnMultiple",
                                         0,
                                         "warn-multiple",
                                         "Emit a warning if an object not defined for the first time in the implementation does not have the same multiple attribute as in the first definition") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               UInt options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String options                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_StringCommandLineOption gOption_goil_5F_options_config ("goil_options",
                                         "config",
                                         99,
                                         "config",
                                         "Specifies the OIL config file used by goil",
                                         "config") ;

C_StringCommandLineOption gOption_goil_5F_options_project_5F_dir ("goil_options",
                                         "project_dir",
                                         112,
                                         "project",
                                         "Specifies project directory (by default, the project directory is the name of the oil file, without the .oil extension)",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_target_5F_platform ("goil_options",
                                         "target_platform",
                                         116,
                                         "target",
                                         "Specifies target platform. Available target platform are located in machines/ directory. Targets are specified using a path like avr/arduino.",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_template_5F_dir ("goil_options",
                                         "template_dir",
                                         0,
                                         "templates",
                                         "Specifies template directory (used by goil for code generation)",
                                         "") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String List options                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'checkEnums'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkEnums (const GALGAS_impEnumType & constinArgument_previousEnum,
                                 const GALGAS_impEnumType & constinArgument_newEnum,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  GALGAS_stringset var_newValues = constinArgument_newEnum.getter_valuesMap (SOURCE_FILE ("implementation_parser.galgas", 535)).getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 535)) ;
  GALGAS_stringset var_previousValues = constinArgument_previousEnum.getter_valuesMap (SOURCE_FILE ("implementation_parser.galgas", 536)).getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 536)) ;
  result_inside = GALGAS_bool (kIsEqual, var_newValues.operator_and (var_previousValues COMMA_SOURCE_FILE ("implementation_parser.galgas", 537)).objectCompare (var_newValues)) ;
  const enumGalgasBool test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 538)).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_14790 (constinArgument_newEnum.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 539)), kEnumeration_up) ;
    while (enumerator_14790.hasCurrentObject ()) {
      inCompiler->emitSemanticError (enumerator_14790.current_location (HERE), GALGAS_string ("ENUM is not within previous enum declaration")  COMMA_SOURCE_FILE ("implementation_parser.galgas", 540)) ;
      enumerator_14790.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_14909 (constinArgument_previousEnum.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 542)), kEnumeration_up) ;
    while (enumerator_14909.hasCurrentObject ()) {
      inCompiler->emitSemanticError (enumerator_14909.current_location (HERE), GALGAS_string ("previous ENUM declaration was here")  COMMA_SOURCE_FILE ("implementation_parser.galgas", 543)) ;
      enumerator_14909.gotoNextObject () ;
    }
  }
//---
  return result_inside ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkEnums [3] = {
  & kTypeDescriptor_GALGAS_impEnumType,
  & kTypeDescriptor_GALGAS_impEnumType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkEnums (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* §§ inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_impEnumType operand0 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_impEnumType operand1 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_checkEnums (operand0,
                              operand1,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkEnums ("checkEnums",
                                                            functionWithGenericHeader_checkEnums,
                                                            & kTypeDescriptor_GALGAS_bool,
                                                            2,
                                                            functionArgs_checkEnums) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'checkRanged'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkRanged (const GALGAS_impRangedType & constinArgument_previousRanged,
                                  const GALGAS_impRangedType & constinArgument_newRanged,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  callCategoryMethod_enclose ((const cPtr_attributeRange *) constinArgument_previousRanged.getter_setOrRange (SOURCE_FILE ("implementation_parser.galgas", 556)).ptr (), result_inside, constinArgument_newRanged.getter_setOrRange (SOURCE_FILE ("implementation_parser.galgas", 556)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 556)) ;
  const enumGalgasBool test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 557)).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_15272 (constinArgument_newRanged.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 558)), kEnumeration_up) ;
    while (enumerator_15272.hasCurrentObject ()) {
      inCompiler->emitSemanticError (enumerator_15272.current_location (HERE), GALGAS_string ("new range or set is not within previous range or set declaration")  COMMA_SOURCE_FILE ("implementation_parser.galgas", 559)) ;
      enumerator_15272.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_15413 (constinArgument_previousRanged.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 561)), kEnumeration_up) ;
    while (enumerator_15413.hasCurrentObject ()) {
      inCompiler->emitSemanticError (enumerator_15413.current_location (HERE), GALGAS_string ("previous range or set declaration was here")  COMMA_SOURCE_FILE ("implementation_parser.galgas", 562)) ;
      enumerator_15413.gotoNextObject () ;
    }
  }
//---
  return result_inside ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkRanged [3] = {
  & kTypeDescriptor_GALGAS_impRangedType,
  & kTypeDescriptor_GALGAS_impRangedType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkRanged (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* §§ inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_impRangedType operand0 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_impRangedType operand1 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  return function_checkRanged (operand0,
                               operand1,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkRanged ("checkRanged",
                                                             functionWithGenericHeader_checkRanged,
                                                             & kTypeDescriptor_GALGAS_bool,
                                                             2,
                                                             functionArgs_checkRanged) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Function 'checkNewTypeWithinPreviousType'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkNewTypeWithinPreviousType (const GALGAS_lstring & constinArgument_name,
                                                     const GALGAS_impType & constinArgument_previousType,
                                                     const GALGAS_impType & constinArgument_newType,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_newType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 573)).objectCompare (constinArgument_previousType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 573)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_15728 (constinArgument_newType.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 574)), kEnumeration_up) ;
    while (enumerator_15728.hasCurrentObject ()) {
      inCompiler->emitSemanticError (enumerator_15728.current_location (HERE), constinArgument_name.getter_string (SOURCE_FILE ("implementation_parser.galgas", 575)).add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 575)).add_operation (extensionGetter_oilType (constinArgument_previousType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 575)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 575)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 575))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 575)) ;
      enumerator_15728.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_15860 (constinArgument_previousType.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 577)), kEnumeration_up) ;
    while (enumerator_15860.hasCurrentObject ()) {
      inCompiler->emitSemanticError (enumerator_15860.current_location (HERE), constinArgument_name.getter_string (SOURCE_FILE ("implementation_parser.galgas", 578)).add_operation (GALGAS_string (" was previouly defined here"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 578))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 578)) ;
      enumerator_15860.gotoNextObject () ;
    }
    result_result = GALGAS_bool (false) ;
  }else if (kBoolFalse == test_0) {
    if (constinArgument_previousType.isValid ()) {
      if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_16023_previousEnum ((cPtr_impEnumType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
            GALGAS_impEnumType cast_16079_newEnum ((cPtr_impEnumType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkEnums (cast_16023_previousEnum, cast_16079_newEnum, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 586)) ;
          }
        }
      }else if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
        GALGAS_impRangedType cast_16190_previousRanged ((cPtr_impRangedType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
            GALGAS_impRangedType cast_16250_newRanged ((cPtr_impRangedType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkRanged (cast_16190_previousRanged, cast_16250_newRanged, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 591)) ;
          }
        }
      }else{
        result_result = GALGAS_bool (true) ;
      }
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkNewTypeWithinPreviousType [4] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_impType,
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkNewTypeWithinPreviousType (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* §§ inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand1 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand2 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_checkNewTypeWithinPreviousType (operand0,
                                                  operand1,
                                                  operand2,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkNewTypeWithinPreviousType ("checkNewTypeWithinPreviousType",
                                                                                functionWithGenericHeader_checkNewTypeWithinPreviousType,
                                                                                & kTypeDescriptor_GALGAS_bool,
                                                                                3,
                                                                                functionArgs_checkNewTypeWithinPreviousType) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'buildRange'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange function_buildRange (const GALGAS_dataType & constinArgument_type,
                                           const GALGAS_object_5F_t & constinArgument_start,
                                           const GALGAS_object_5F_t & constinArgument_stop,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 604)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_range = GALGAS_uint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 605)), function_uint_33__32_OrError (constinArgument_start, GALGAS_string ("UINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 605)), function_uint_33__32_OrError (constinArgument_stop, GALGAS_string ("UINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 605))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 605)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 606)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_range = GALGAS_sint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 607)), function_sint_33__32_OrError (constinArgument_start, GALGAS_string ("SINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 607)), function_sint_33__32_OrError (constinArgument_stop, GALGAS_string ("SINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 607))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 607)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 608)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_range = GALGAS_uint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 609)), function_uint_36__34_OrError (constinArgument_start, GALGAS_string ("UINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 609)), function_uint_36__34_OrError (constinArgument_stop, GALGAS_string ("UINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 609))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 609)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 610)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_range = GALGAS_sint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 611)), function_sint_36__34_OrError (constinArgument_start, GALGAS_string ("SINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 611)), function_sint_36__34_OrError (constinArgument_stop, GALGAS_string ("SINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 611))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 611)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_parser.galgas", 612)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            result_range = GALGAS_floatAttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 613)), function_floatOrError (constinArgument_start, GALGAS_string ("FLOAT Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 613)), function_floatOrError (constinArgument_stop, GALGAS_string ("FLOAT Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 613))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 613)) ;
          }else if (kBoolFalse == test_4) {
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 615)), GALGAS_string ("internal. Unknown number type")  COMMA_SOURCE_FILE ("implementation_parser.galgas", 615)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_buildRange [4] = {
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_object_5F_t,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_buildRange (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* §§ inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_dataType operand0 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_object_5F_t operand1 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_object_5F_t operand2 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_buildRange (operand0,
                              operand1,
                              operand2,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_buildRange ("buildRange",
                                                            functionWithGenericHeader_buildRange,
                                                            & kTypeDescriptor_GALGAS_attributeRange,
                                                            3,
                                                            functionArgs_buildRange) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithUInt32List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithUInt_33__32_List (const GALGAS_uint_33__32_List & constinArgument_values,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_33__32_List enumerator_1878 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_1878.hasCurrentObject ()) {
    result_result.dotAssign_operation (enumerator_1878.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 68))  COMMA_SOURCE_FILE ("implementation_types.galgas", 68)) ;
    if (enumerator_1878.hasNextObject ()) {
      result_result.dotAssign_operation (GALGAS_string (", ")  COMMA_SOURCE_FILE ("implementation_types.galgas", 68)) ;
    }
    enumerator_1878.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_uint_33__32_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithUInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* §§ inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_33__32_List operand0 = GALGAS_uint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithUInt_33__32_List ("stringWithUInt32List",
                                                                            functionWithGenericHeader_stringWithUInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_33__32_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithUInt64List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithUInt_36__34_List (const GALGAS_uint_36__34_List & constinArgument_values,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_36__34_List enumerator_2040 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2040.hasCurrentObject ()) {
    result_result.dotAssign_operation (enumerator_2040.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 73))  COMMA_SOURCE_FILE ("implementation_types.galgas", 73)) ;
    if (enumerator_2040.hasNextObject ()) {
      result_result.dotAssign_operation (GALGAS_string (", ")  COMMA_SOURCE_FILE ("implementation_types.galgas", 73)) ;
    }
    enumerator_2040.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithUInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* §§ inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34_List operand0 = GALGAS_uint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithUInt_36__34_List ("stringWithUInt64List",
                                                                            functionWithGenericHeader_stringWithUInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_36__34_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithSInt32List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithSInt_33__32_List (const GALGAS_sint_33__32_List & constinArgument_values,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_33__32_List enumerator_2202 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2202.hasCurrentObject ()) {
    result_result.dotAssign_operation (enumerator_2202.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 78))  COMMA_SOURCE_FILE ("implementation_types.galgas", 78)) ;
    if (enumerator_2202.hasNextObject ()) {
      result_result.dotAssign_operation (GALGAS_string (", ")  COMMA_SOURCE_FILE ("implementation_types.galgas", 78)) ;
    }
    enumerator_2202.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_sint_33__32_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithSInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* §§ inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_33__32_List operand0 = GALGAS_sint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithSInt_33__32_List ("stringWithSInt32List",
                                                                            functionWithGenericHeader_stringWithSInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_33__32_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithSInt64List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithSInt_36__34_List (const GALGAS_sint_36__34_List & constinArgument_values,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_36__34_List enumerator_2364 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2364.hasCurrentObject ()) {
    result_result.dotAssign_operation (enumerator_2364.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 83))  COMMA_SOURCE_FILE ("implementation_types.galgas", 83)) ;
    if (enumerator_2364.hasNextObject ()) {
      result_result.dotAssign_operation (GALGAS_string (", ")  COMMA_SOURCE_FILE ("implementation_types.galgas", 83)) ;
    }
    enumerator_2364.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_sint_36__34_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithSInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* §§ inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_36__34_List operand0 = GALGAS_sint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithSInt_36__34_List ("stringWithSInt64List",
                                                                            functionWithGenericHeader_stringWithSInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_36__34_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithFloatList'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithFloatList (const GALGAS_floatList & constinArgument_values,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_floatList enumerator_2524 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2524.hasCurrentObject ()) {
    result_result.dotAssign_operation (enumerator_2524.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 88))  COMMA_SOURCE_FILE ("implementation_types.galgas", 88)) ;
    if (enumerator_2524.hasNextObject ()) {
      result_result.dotAssign_operation (GALGAS_string (", ")  COMMA_SOURCE_FILE ("implementation_types.galgas", 88)) ;
    }
    enumerator_2524.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithFloatList [2] = {
  & kTypeDescriptor_GALGAS_floatList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithFloatList (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* §§ inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_floatList operand0 = GALGAS_floatList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  return function_stringWithFloatList (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithFloatList ("stringWithFloatList",
                                                                     functionWithGenericHeader_stringWithFloatList,
                                                                     & kTypeDescriptor_GALGAS_string,
                                                                     1,
                                                                     functionArgs_stringWithFloatList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'uint32ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List function_uint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_uint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 92)) ;
  cEnumerator_numberList enumerator_2716 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_2716.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_2716.current_location (HERE), function_uint_33__32_OrError (enumerator_2716.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 94))  COMMA_SOURCE_FILE ("implementation_types.galgas", 94)) ;
    enumerator_2716.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* §§ inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32_ListWithNumberList ("uint32ListWithNumberList",
                                                                                functionWithGenericHeader_uint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_33__32_List,
                                                                                1,
                                                                                functionArgs_uint_33__32_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'sint32ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List function_sint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_sint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 99)) ;
  cEnumerator_numberList enumerator_2914 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_2914.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_2914.current_location (HERE), function_sint_33__32_OrError (enumerator_2914.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 101))  COMMA_SOURCE_FILE ("implementation_types.galgas", 101)) ;
    enumerator_2914.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* §§ inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_33__32_ListWithNumberList ("sint32ListWithNumberList",
                                                                                functionWithGenericHeader_sint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_33__32_List,
                                                                                1,
                                                                                functionArgs_sint_33__32_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'uint64ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List function_uint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_uint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 106)) ;
  cEnumerator_numberList enumerator_3112 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_3112.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3112.current_location (HERE), function_uint_36__34_OrError (enumerator_3112.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 108))  COMMA_SOURCE_FILE ("implementation_types.galgas", 108)) ;
    enumerator_3112.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* §§ inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_36__34_ListWithNumberList ("uint64ListWithNumberList",
                                                                                functionWithGenericHeader_uint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_36__34_List,
                                                                                1,
                                                                                functionArgs_uint_36__34_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'sint64ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List function_sint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 113)) ;
  cEnumerator_numberList enumerator_3310 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_3310.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3310.current_location (HERE), function_sint_36__34_OrError (enumerator_3310.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 115))  COMMA_SOURCE_FILE ("implementation_types.galgas", 115)) ;
    enumerator_3310.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* §§ inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_36__34_ListWithNumberList ("sint64ListWithNumberList",
                                                                                functionWithGenericHeader_sint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_36__34_List,
                                                                                1,
                                                                                functionArgs_sint_36__34_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'floatListWithNumberList'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList function_floatListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_floatList result_result ; // Returned variable
  result_result = GALGAS_floatList::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 120)) ;
  cEnumerator_numberList enumerator_3505 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_3505.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3505.current_location (HERE), function_floatOrError (enumerator_3505.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 122))  COMMA_SOURCE_FILE ("implementation_types.galgas", 122)) ;
    enumerator_3505.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_floatListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_floatListWithNumberList (C_Compiler * inCompiler,
                                                                        const cObjectArray & inEffectiveParameterArray,
                                                                        const GALGAS_location & /* §§ inErrorLocation */
                                                                        COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_floatListWithNumberList (operand0,
                                           inCompiler
                                           COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_floatListWithNumberList ("floatListWithNumberList",
                                                                         functionWithGenericHeader_floatListWithNumberList,
                                                                         & kTypeDescriptor_GALGAS_floatList,
                                                                         1,
                                                                         functionArgs_floatListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Function 'attributeRangeWithNumberList'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange function_attributeRangeWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                             const GALGAS_dataType & constinArgument_type,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 397)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_range = GALGAS_uint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 398)), function_uint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 398))  COMMA_SOURCE_FILE ("implementation_types.galgas", 398)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 399)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_range = GALGAS_sint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 400)), function_sint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 400))  COMMA_SOURCE_FILE ("implementation_types.galgas", 400)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 401)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_range = GALGAS_uint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 402)), function_uint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 402))  COMMA_SOURCE_FILE ("implementation_types.galgas", 402)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 403)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_range = GALGAS_sint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 404)), function_sint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 404))  COMMA_SOURCE_FILE ("implementation_types.galgas", 404)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 405)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            result_range = GALGAS_floatAttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 406)), function_floatListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 406))  COMMA_SOURCE_FILE ("implementation_types.galgas", 406)) ;
          }else if (kBoolFalse == test_4) {
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 408)), GALGAS_string ("internal. Unknown number type")  COMMA_SOURCE_FILE ("implementation_types.galgas", 408)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_attributeRangeWithNumberList [3] = {
  & kTypeDescriptor_GALGAS_numberList,
  & kTypeDescriptor_GALGAS_dataType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_attributeRangeWithNumberList (C_Compiler * inCompiler,
                                                                             const cObjectArray & inEffectiveParameterArray,
                                                                             const GALGAS_location & /* §§ inErrorLocation */
                                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_attributeRangeWithNumberList (operand0,
                                                operand1,
                                                inCompiler
                                                COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_attributeRangeWithNumberList ("attributeRangeWithNumberList",
                                                                              functionWithGenericHeader_attributeRangeWithNumberList,
                                                                              & kTypeDescriptor_GALGAS_attributeRange,
                                                                              2,
                                                                              functionArgs_attributeRangeWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'multiError'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_multiError (GALGAS_locationList inArgument_locations,
                         GALGAS_string inArgument_errorMessage,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_locationList enumerator_13740 (inArgument_locations, kEnumeration_up) ;
  while (enumerator_13740.hasCurrentObject ()) {
    inCompiler->emitSemanticError (enumerator_13740.current_location (HERE), inArgument_errorMessage  COMMA_SOURCE_FILE ("implementation_types.galgas", 508)) ;
    enumerator_13740.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'valueList'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_valueList (const GALGAS_enumValues & constinArgument_values,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_enumValues enumerator_15065 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_15065.hasCurrentObject ()) {
    result_result.dotAssign_operation (enumerator_15065.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 562))  COMMA_SOURCE_FILE ("implementation_types.galgas", 562)) ;
    if (enumerator_15065.hasNextObject ()) {
      result_result.dotAssign_operation (GALGAS_string (", ")  COMMA_SOURCE_FILE ("implementation_types.galgas", 564)) ;
    }
    enumerator_15065.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueList [2] = {
  & kTypeDescriptor_GALGAS_enumValues,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueList (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* §§ inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_enumValues operand0 = GALGAS_enumValues::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_valueList (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueList ("valueList",
                                                           functionWithGenericHeader_valueList,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_valueList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'verifyEnum'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyEnum (const GALGAS_impType constinArgument_anEnum,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_anEnum.isValid ()) {
    if (constinArgument_anEnum.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
      GALGAS_impEnumType cast_20361_realEnum ((cPtr_impEnumType *) constinArgument_anEnum.ptr ()) ;
      if (cast_20361_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 737)).isValid ()) {
        if (cast_20361_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 737)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
          GALGAS_string_5F_class cast_20435_defaultValue ((cPtr_string_5F_class *) cast_20361_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 737)).ptr ()) ;
          const enumGalgasBool test_0 = cast_20361_realEnum.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 739)).getter_hasKey (cast_20435_defaultValue.getter_value (SOURCE_FILE ("implementation_types.galgas", 739)) COMMA_SOURCE_FILE ("implementation_types.galgas", 739)).operator_not (SOURCE_FILE ("implementation_types.galgas", 739)).boolEnum () ;
          if (kBoolTrue == test_0) {
            inCompiler->emitSemanticError (cast_20435_defaultValue.getter_location (SOURCE_FILE ("implementation_types.galgas", 740)), GALGAS_string ("Default enum value does not match any enum value")  COMMA_SOURCE_FILE ("implementation_types.galgas", 740)) ;
          }
        }
      }
    }else{
      cEnumerator_locationList enumerator_20660 (constinArgument_anEnum.getter_locations (SOURCE_FILE ("implementation_types.galgas", 744)), kEnumeration_up) ;
      while (enumerator_20660.hasCurrentObject ()) {
        inCompiler->emitSemanticError (enumerator_20660.current_location (HERE), GALGAS_string ("Internal, not an @impEnumType")  COMMA_SOURCE_FILE ("implementation_types.galgas", 745)) ;
        enumerator_20660.gotoNextObject () ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'checkAndGetIntegerNumber'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_checkAndGetIntegerNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                      const GALGAS_dataType & constinArgument_type,
                                                      const GALGAS_luint_36__34_ & constinArgument_number,
                                                      const GALGAS_bool & constinArgument_signed,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_signed.boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 806)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 807)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 807)).getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 807)).multiply_operation (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 807)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 807))  COMMA_SOURCE_FILE ("implementation_types.galgas", 807)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 808)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 809)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 809)).getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 809)).multiply_operation (GALGAS_sint_36__34_ ((int64_t) 1LL).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 809)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 809))  COMMA_SOURCE_FILE ("implementation_types.galgas", 809)) ;
      }else if (kBoolFalse == test_2) {
        result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 811))  COMMA_SOURCE_FILE ("implementation_types.galgas", 811)) ;
        GALGAS_location location_3 (constinArgument_number.getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_3, extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 812)).add_operation (GALGAS_string (" expected, got a SINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 812))  COMMA_SOURCE_FILE ("implementation_types.galgas", 812)) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 815)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 816)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 816)).getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 816))  COMMA_SOURCE_FILE ("implementation_types.galgas", 816)) ;
    }else if (kBoolFalse == test_4) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 817)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 818)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 818)).getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 818))  COMMA_SOURCE_FILE ("implementation_types.galgas", 818)) ;
      }else if (kBoolFalse == test_5) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 819)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          result_value = GALGAS_uint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 820)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 820)).getter_uint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 820))  COMMA_SOURCE_FILE ("implementation_types.galgas", 820)) ;
        }else if (kBoolFalse == test_6) {
          const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 821)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            result_value = GALGAS_uint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 822)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 822))  COMMA_SOURCE_FILE ("implementation_types.galgas", 822)) ;
          }else if (kBoolFalse == test_7) {
            result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 824))  COMMA_SOURCE_FILE ("implementation_types.galgas", 824)) ;
            GALGAS_location location_8 (constinArgument_number.getter_location (HERE)) ; // Implicit use of 'location' getter
            inCompiler->emitSemanticError (location_8, extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 825)).add_operation (GALGAS_string (" expected, got a UINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 825))  COMMA_SOURCE_FILE ("implementation_types.galgas", 825)) ;
          }
        }
      }
    }
  }
//---
  return result_value ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkAndGetIntegerNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_luint_36__34_,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkAndGetIntegerNumber (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* §§ inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_luint_36__34_ operand2 = GALGAS_luint_36__34_::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetIntegerNumber (operand0,
                                            operand1,
                                            operand2,
                                            operand3,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkAndGetIntegerNumber ("checkAndGetIntegerNumber",
                                                                          functionWithGenericHeader_checkAndGetIntegerNumber,
                                                                          & kTypeDescriptor_GALGAS_object_5F_t,
                                                                          4,
                                                                          functionArgs_checkAndGetIntegerNumber) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'checkAndGetFloatNumber'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_checkAndGetFloatNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                    const GALGAS_dataType & constinArgument_type,
                                                    const GALGAS_ldouble & constinArgument_number,
                                                    const GALGAS_bool & constinArgument_signed,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_signed.boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 837)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 838)), constinArgument_number.getter_double (SOURCE_FILE ("implementation_types.galgas", 838)).multiply_operation (GALGAS_double (1).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 838)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 838))  COMMA_SOURCE_FILE ("implementation_types.galgas", 838)) ;
    }else if (kBoolFalse == test_1) {
      result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 840))  COMMA_SOURCE_FILE ("implementation_types.galgas", 840)) ;
      GALGAS_location location_2 (constinArgument_number.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_2, extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 841)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 841))  COMMA_SOURCE_FILE ("implementation_types.galgas", 841)) ;
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 844)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 845)), constinArgument_number.getter_double (SOURCE_FILE ("implementation_types.galgas", 845))  COMMA_SOURCE_FILE ("implementation_types.galgas", 845)) ;
    }else if (kBoolFalse == test_3) {
      result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 847))  COMMA_SOURCE_FILE ("implementation_types.galgas", 847)) ;
      GALGAS_location location_4 (constinArgument_number.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_4, extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848))  COMMA_SOURCE_FILE ("implementation_types.galgas", 848)) ;
    }
  }
//---
  return result_value ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkAndGetFloatNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_ldouble,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkAndGetFloatNumber (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* §§ inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_ldouble operand2 = GALGAS_ldouble::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetFloatNumber (operand0,
                                          operand1,
                                          operand2,
                                          operand3,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkAndGetFloatNumber ("checkAndGetFloatNumber",
                                                                        functionWithGenericHeader_checkAndGetFloatNumber,
                                                                        & kTypeDescriptor_GALGAS_object_5F_t,
                                                                        4,
                                                                        functionArgs_checkAndGetFloatNumber) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'checkTypeForAttribute'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkTypeForAttribute (const GALGAS_implementationObjectMap constinArgument_obj,
                                    const GALGAS_string constinArgument_attributeName,
                                    const GALGAS_dataType constinArgument_expectedType,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = constinArgument_obj.getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 857)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type ;
    constinArgument_obj.method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 859)), var_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 859)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_type.getter_type (SOURCE_FILE ("implementation_types.galgas", 860)).objectCompare (constinArgument_expectedType)).boolEnum () ;
    if (kBoolTrue == test_1) {
      cEnumerator_locationList enumerator_24175 (var_type.getter_locations (SOURCE_FILE ("implementation_types.galgas", 861)), kEnumeration_up) ;
      while (enumerator_24175.hasCurrentObject ()) {
        inCompiler->emitSemanticError (enumerator_24175.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" is a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 862)).add_operation (extensionGetter_oilType (var_type.getter_type (SOURCE_FILE ("implementation_types.galgas", 862)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 862)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 862))  COMMA_SOURCE_FILE ("implementation_types.galgas", 862)) ;
        inCompiler->emitSemanticError (enumerator_24175.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 863)).add_operation (extensionGetter_oilType (constinArgument_expectedType, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 863)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 863))  COMMA_SOURCE_FILE ("implementation_types.galgas", 863)) ;
        enumerator_24175.gotoNextObject () ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'boolSubAttributes'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap function_boolSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_bool & constinArgument_boolValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 874)) ;
  const enumGalgasBool test_0 = constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 875)).getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 875)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type ;
    constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 877)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877)), var_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877)) ;
    if (var_type.isValid ()) {
      if (var_type.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
        GALGAS_impBoolType cast_24744_boolType ((cPtr_impBoolType *) var_type.ptr ()) ;
        const enumGalgasBool test_1 = constinArgument_boolValue.boolEnum () ;
        if (kBoolTrue == test_1) {
          result_subImplementation = cast_24744_boolType.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 881)) ;
        }else if (kBoolFalse == test_1) {
          result_subImplementation = cast_24744_boolType.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 883)) ;
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_boolSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_boolSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* §§ inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_bool operand2 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_boolSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_boolSubAttributes ("boolSubAttributes",
                                                                   functionWithGenericHeader_boolSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_boolSubAttributes) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'enumSubAttributes'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap function_enumSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_string & constinArgument_enumValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 894)) ;
  const enumGalgasBool test_0 = constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 895)).getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 895)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type ;
    constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 897)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 897)), var_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 897)) ;
    if (var_type.isValid ()) {
      if (var_type.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_25323_enumType ((cPtr_impEnumType *) var_type.ptr ()) ;
        const enumGalgasBool test_1 = cast_25323_enumType.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 900)).getter_hasKey (constinArgument_enumValue COMMA_SOURCE_FILE ("implementation_types.galgas", 900)).boolEnum () ;
        if (kBoolTrue == test_1) {
          cast_25323_enumType.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 901)).method_get (function_lstringWith (constinArgument_enumValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)), result_subImplementation, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)) ;
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_enumSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_enumSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* §§ inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_enumSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_enumSubAttributes ("enumSubAttributes",
                                                                   functionWithGenericHeader_enumSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_enumSubAttributes) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'checkFilters'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkFilters (const GALGAS_implementationObject constinArgument_messageProperty,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap var_filter = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 912)) ;
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 913)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 913)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 914)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 914)) ;
  }
  var_filter = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWDIFFERSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 915)) ;
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 916)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 916)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 917)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 917)) ;
  }
  var_filter = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSMASKEDOLD"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 918)) ;
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 919)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 919)) ;
  }
  var_filter = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISWITHIN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 920)) ;
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 921)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 921)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 922)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 922)) ;
  }
  var_filter = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISOUTSIDE"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 923)) ;
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 924)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 924)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 925)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 925)) ;
  }
  var_filter = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("ONEEVERYN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 926)) ;
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("PERIOD"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 927)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 927)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter, GALGAS_string ("OFFSET"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 928)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 928)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'setDefaultsForType'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setDefaultsForType (const GALGAS_implementationObjectMap constinArgument_impObject,
                                 GALGAS_objectAttributes & ioArgument_objectParams,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_implementationObjectMap enumerator_27966 (constinArgument_impObject, kEnumeration_up) ;
  while (enumerator_27966.hasCurrentObject ()) {
    if (enumerator_27966.current_type (HERE).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (enumerator_27966.current_type (HERE).ptr ())) {
        GALGAS_impAutoDefaultType cast_28027_defaultType ((cPtr_impAutoDefaultType *) enumerator_27966.current_type (HERE).ptr ()) ;
        callCategoryMethod_setDefault ((const cPtr_impAutoDefaultType *) cast_28027_defaultType.ptr (), ioArgument_objectParams, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 976)) ;
      }
    }
    enumerator_27966.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Once function 'emptyLString'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring onceFunction_emptyLString (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29)) ;
//---
  return result_ls ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_emptyLString = false ;
static GALGAS_lstring gOnceFunctionResult_emptyLString ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_emptyLString (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_emptyLString) {
    gOnceFunctionResult_emptyLString = onceFunction_emptyLString (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_emptyLString = true ;
  }
  return gOnceFunctionResult_emptyLString ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_emptyLString (void) {
  gOnceFunctionResult_emptyLString.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_emptyLString (NULL,
                                                          releaseOnceFunctionResult_emptyLString) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyLString [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyLString (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptyLString (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyLString ("emptyLString",
                                                              functionWithGenericHeader_emptyLString,
                                                              & kTypeDescriptor_GALGAS_lstring,
                                                              0,
                                                              functionArgs_emptyLString) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'emptyObject'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_emptyObject (C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_result ; // Returned variable
  result_result = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_basic_types.galgas", 52))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 52)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyObject [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyObject (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_emptyObject (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyObject ("emptyObject",
                                                             functionWithGenericHeader_emptyObject,
                                                             & kTypeDescriptor_GALGAS_objectAttributes,
                                                             0,
                                                             functionArgs_emptyObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'multipleAttributeOrError'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList function_multipleAttributeOrError (const GALGAS_object_5F_t & constinArgument_t,
                                                         const GALGAS_string & constinArgument_att,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_v ; // Returned variable
  result_v = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("goil_basic_types.galgas", 71)) ;
  if (constinArgument_t.isValid ()) {
    if (constinArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
      GALGAS_multipleAttribute cast_1710_l ((cPtr_multipleAttribute *) constinArgument_t.ptr ()) ;
      result_v = cast_1710_l.getter_items (SOURCE_FILE ("goil_basic_types.galgas", 74)) ;
    }else{
      inCompiler->emitSemanticError (constinArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 76)), GALGAS_string ("Internal error, ").add_operation (constinArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 76)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 76))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 76)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_multipleAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_multipleAttributeOrError (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* §§ inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_multipleAttributeOrError (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_multipleAttributeOrError ("multipleAttributeOrError",
                                                                          functionWithGenericHeader_multipleAttributeOrError,
                                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                                          2,
                                                                          functionArgs_multipleAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'boolAttributeOrError'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_boolAttributeOrError (GALGAS_object_5F_t inArgument_t,
                                           GALGAS_string inArgument_att,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_v ; // Returned variable
  result_v = GALGAS_bool (false) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_2046_attribute ((cPtr_boolAttribute *) inArgument_t.ptr ()) ;
      result_v = cast_2046_attribute.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 92)) ;
    }else{
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 94)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 94)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 94))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 94)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_boolAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_boolAttributeOrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* §§ inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_boolAttributeOrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_boolAttributeOrError ("boolAttributeOrError",
                                                                      functionWithGenericHeader_boolAttributeOrError,
                                                                      & kTypeDescriptor_GALGAS_bool,
                                                                      2,
                                                                      functionArgs_boolAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'uint32_or_error'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint function_uint_33__32__5F_or_5F_error (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint ((uint32_t) 0U) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_2567_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_2567_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 123)) ;
    }else{
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 125)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 125))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 125)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32__5F_or_5F_error [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32__5F_or_5F_error (C_Compiler * inCompiler,
                                                                            const cObjectArray & inEffectiveParameterArray,
                                                                            const GALGAS_location & /* §§ inErrorLocation */
                                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32__5F_or_5F_error (operand0,
                                               operand1,
                                               inCompiler
                                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32__5F_or_5F_error ("uint32_or_error",
                                                                             functionWithGenericHeader_uint_33__32__5F_or_5F_error,
                                                                             & kTypeDescriptor_GALGAS_uint,
                                                                             2,
                                                                             functionArgs_uint_33__32__5F_or_5F_error) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'uint32OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint function_uint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint ((uint32_t) 0U) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_2766_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_2766_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 136)) ;
    }else{
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 138)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 138))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 138)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* §§ inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32_OrError ("uint32OrError",
                                                                     functionWithGenericHeader_uint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint,
                                                                     2,
                                                                     functionArgs_uint_33__32_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'sint32OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint function_sint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint result_v ; // Returned variable
  result_v = GALGAS_sint ((int32_t) 0L) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      GALGAS_sint_33__32__5F_class cast_3104_ui ((cPtr_sint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_3104_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 156)) ;
    }else{
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 158)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 158))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 158)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* §§ inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_33__32_OrError ("sint32OrError",
                                                                     functionWithGenericHeader_sint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint,
                                                                     2,
                                                                     functionArgs_sint_33__32_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'uint64OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ function_uint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_uint_36__34_ ((uint64_t) 0ULL) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_3442_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_3442_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 176)) ;
    }else{
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 178)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 178)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 178))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 178)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* §§ inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_36__34_OrError ("uint64OrError",
                                                                     functionWithGenericHeader_uint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint_36__34_,
                                                                     2,
                                                                     functionArgs_uint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'luint64OrError'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ function_luint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                    GALGAS_string inArgument_att,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_3660_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = GALGAS_luint_36__34_::constructor_new (cast_3660_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 188)), cast_3660_ui.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 188))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 188)) ;
    }else{
      result_v = GALGAS_luint_36__34_::constructor_new (GALGAS_uint_36__34_ ((uint64_t) 0ULL), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 190))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 190)) ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 191)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 191)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 191))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 191)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_luint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_luint_36__34_OrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* §§ inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_luint_36__34_OrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_luint_36__34_OrError ("luint64OrError",
                                                                      functionWithGenericHeader_luint_36__34_OrError,
                                                                      & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                      2,
                                                                      functionArgs_luint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'sint64OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ function_sint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_sint_36__34_ ((int64_t) 0LL) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      GALGAS_sint_36__34__5F_class cast_4102_ui ((cPtr_sint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4102_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 209)) ;
    }else{
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 211)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 211)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 211))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 211)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* §§ inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_36__34_OrError ("sint64OrError",
                                                                     functionWithGenericHeader_sint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint_36__34_,
                                                                     2,
                                                                     functionArgs_sint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'floatOrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double function_floatOrError (GALGAS_object_5F_t inArgument_t,
                                     GALGAS_string inArgument_att,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_v ; // Returned variable
  result_v = GALGAS_double (0) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      GALGAS_float_5F_class cast_4452_ui ((cPtr_float_5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4452_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 229)) ;
    }else{
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 231)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 231)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 231))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 231)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_floatOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_floatOrError (C_Compiler * inCompiler,
                                                             const cObjectArray & inEffectiveParameterArray,
                                                             const GALGAS_location & /* §§ inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_floatOrError (operand0,
                                operand1,
                                inCompiler
                                COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_floatOrError ("floatOrError",
                                                              functionWithGenericHeader_floatOrError,
                                                              & kTypeDescriptor_GALGAS_double,
                                                              2,
                                                              functionArgs_floatOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'stringAttributeOrError'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_stringAttributeOrError (const GALGAS_object_5F_t & constinArgument_attribute,
                                                const GALGAS_string & constinArgument_attributeName,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 253)) ;
  if (constinArgument_attribute.isValid ()) {
    if (constinArgument_attribute.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      GALGAS_stringAttribute cast_5004_attribute ((cPtr_stringAttribute *) constinArgument_attribute.ptr ()) ;
      result_result = GALGAS_lstring::constructor_new (cast_5004_attribute.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 256)), cast_5004_attribute.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 256))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 256)) ;
    }else{
      inCompiler->emitSemanticError (constinArgument_attribute.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 258)), GALGAS_string ("Internal error ").add_operation (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 258)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 258))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 258)) ;
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringAttributeOrError (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* §§ inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stringAttributeOrError (operand0,
                                          operand1,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringAttributeOrError ("stringAttributeOrError",
                                                                        functionWithGenericHeader_stringAttributeOrError,
                                                                        & kTypeDescriptor_GALGAS_lstring,
                                                                        2,
                                                                        functionArgs_stringAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'empty_lstring'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_empty_5F_lstring (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 428))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 428)) ;
//---
  return result_ls ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_empty_5F_lstring [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_empty_5F_lstring (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_empty_5F_lstring (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_empty_5F_lstring ("empty_lstring",
                                                                  functionWithGenericHeader_empty_5F_lstring,
                                                                  & kTypeDescriptor_GALGAS_lstring,
                                                                  0,
                                                                  functionArgs_empty_5F_lstring) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'void_obj'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_void_5F_obj (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_v ; // Returned variable
  result_v = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 433)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 433))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 433)) ;
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_void_5F_obj [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_void_5F_obj (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_void_5F_obj (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_void_5F_obj ("void_obj",
                                                             functionWithGenericHeader_void_5F_obj,
                                                             & kTypeDescriptor_GALGAS_object_5F_t,
                                                             0,
                                                             functionArgs_void_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'luint64_value'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ function_luint_36__34__5F_value (const GALGAS_uint_36__34__5F_class & constinArgument_c,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_luint_36__34_::constructor_new (constinArgument_c.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 627)), constinArgument_c.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 627))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 627)) ;
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_luint_36__34__5F_value [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34__5F_class,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_luint_36__34__5F_value (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* §§ inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34__5F_class operand0 = GALGAS_uint_36__34__5F_class::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                             inCompiler
                                                                                             COMMA_THERE) ;
  return function_luint_36__34__5F_value (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_luint_36__34__5F_value ("luint64_value",
                                                                        functionWithGenericHeader_luint_36__34__5F_value,
                                                                        & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                        1,
                                                                        functionArgs_luint_36__34__5F_value) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'projectName'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_projectName (C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_directory ; // Returned variable
  result_directory = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 30)).getter_stringByDeletingPathExtension (SOURCE_FILE ("goil_routines.galgas", 30)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_project_5F_dir.getter_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_directory = GALGAS_string (gOption_goil_5F_options_project_5F_dir.getter_value ()) ;
  }
//---
  return result_directory ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_projectName [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_projectName (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_projectName (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_projectName ("projectName",
                                                             functionWithGenericHeader_projectName,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_projectName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'oil_dir'                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_oil_5F_dir (C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_dir ; // Returned variable
  result_dir = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 37)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_routines.galgas", 37)) ;
//---
  return result_dir ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_oil_5F_dir [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_oil_5F_dir (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_oil_5F_dir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_oil_5F_dir ("oil_dir",
                                                            functionWithGenericHeader_oil_5F_dir,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_oil_5F_dir) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'arch'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_arch (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_arch_5F_name ; // Returned variable
  GALGAS_stringlist var_components = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 45)) ;
  var_components.method_first (result_arch_5F_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 46)) ;
//---
  return result_arch_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_arch [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_arch (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_arch (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_arch ("arch",
                                                      functionWithGenericHeader_arch,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_arch) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'chip'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_chip (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_chip_5F_name ; // Returned variable
  GALGAS_stringlist var_components = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 54)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_components.getter_length (SOURCE_FILE ("goil_routines.galgas", 55)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_chip_5F_name = var_components.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 56)) ;
  }else if (kBoolFalse == test_0) {
    result_chip_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_chip_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_chip [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_chip (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_chip (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_chip ("chip",
                                                      functionWithGenericHeader_chip,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_chip) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Function 'board'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_board (C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_board_5F_name ; // Returned variable
  GALGAS_stringlist var_components = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 68)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_components.getter_length (SOURCE_FILE ("goil_routines.galgas", 69)).objectCompare (GALGAS_uint ((uint32_t) 2U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    GALGAS_string joker_2090 ; // Joker input parameter
    var_components.modifier_popFirst (joker_2090, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 70)) ;
    }
    {
    GALGAS_string joker_2121 ; // Joker input parameter
    var_components.modifier_popFirst (joker_2121, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 71)) ;
    }
    result_board_5F_name = GALGAS_string::constructor_componentsJoinedByString (var_components, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 72)) ;
  }else if (kBoolFalse == test_0) {
    result_board_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_board_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_board [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_board (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_board (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_board ("board",
                                                       functionWithGenericHeader_board,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_board) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'targetPathList'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_TfieldMapList function_targetPathList (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TfieldMapList result_pathList ; // Returned variable
  GALGAS_stringlist var_components = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 82)) ;
  result_pathList = GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 83)) ;
  cEnumerator_stringlist enumerator_2523 (var_components, kEnumeration_up) ;
  while (enumerator_2523.hasCurrentObject ()) {
    GALGAS_TfieldMap var_cont = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("goil_routines.galgas", 85)) ;
    {
    routine_addStringValue (var_cont, function_lstringWith (GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 86)), enumerator_2523.current_mValue (HERE), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 86)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 86)) ;
    }
    result_pathList.addAssign_operation (var_cont  COMMA_SOURCE_FILE ("goil_routines.galgas", 87)) ;
    enumerator_2523.gotoNextObject () ;
  }
//---
  return result_pathList ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_targetPathList [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_targetPathList (C_Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_targetPathList (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_targetPathList ("targetPathList",
                                                                functionWithGenericHeader_targetPathList,
                                                                & kTypeDescriptor_GALGAS_TfieldMapList,
                                                                0,
                                                                functionArgs_targetPathList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'add_path_component'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_add_5F_path_5F_component (GALGAS_string inArgument_path,
                                                 GALGAS_string inArgument_component,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_new_5F_path ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_path.getter_characterAtIndex (inArgument_path.getter_length (SOURCE_FILE ("goil_routines.galgas", 98)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_new_5F_path = inArgument_path.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 99)).add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 99)) ;
  }else if (kBoolFalse == test_0) {
    result_new_5F_path = inArgument_path.add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 101)) ;
  }
//---
  return result_new_5F_path ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_add_5F_path_5F_component [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_add_5F_path_5F_component (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* §§ inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_add_5F_path_5F_component (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_add_5F_path_5F_component ("add_path_component",
                                                                          functionWithGenericHeader_add_5F_path_5F_component,
                                                                          & kTypeDescriptor_GALGAS_string,
                                                                          2,
                                                                          functionArgs_add_5F_path_5F_component) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'rootTemplatesDirectory'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_rootTemplatesDirectory (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_templateDirectory ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_templateDirectory = GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ()) ;
  }else if (kBoolFalse == test_0) {
    GALGAS_string var_env = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_TEMPLATES")  COMMA_SOURCE_FILE ("goil_routines.galgas", 110)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_env.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_templateDirectory = var_env ;
    }else if (kBoolFalse == test_1) {
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)), GALGAS_string ("The templates path is not set. Use --templates option or set the GOIL_TEMPLATES environment variable")  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)) ;
      result_templateDirectory.drop () ; // Release error dropped variable
    }
  }
  result_templateDirectory = result_templateDirectory.getter_unixPathWithNativePath (SOURCE_FILE ("goil_routines.galgas", 117)) ;
  result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 118)) ;
  const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, result_templateDirectory.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 119)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
  if (kBoolTrue == test_2) {
    GALGAS_string var_currentDirectory = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 120)) ;
    result_templateDirectory = var_currentDirectory.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 121)).add_operation (result_templateDirectory, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 121)) ;
    result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 122)) ;
  }
//---
  return result_templateDirectory ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_rootTemplatesDirectory [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_rootTemplatesDirectory (C_Compiler * inCompiler,
                                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  return function_rootTemplatesDirectory (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_rootTemplatesDirectory ("rootTemplatesDirectory",
                                                                        functionWithGenericHeader_rootTemplatesDirectory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        0,
                                                                        functionArgs_rootTemplatesDirectory) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'templates_directory'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_templates_5F_directory (GALGAS_string inArgument_prefix,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_temp_5F_dir ; // Returned variable
  result_temp_5F_dir = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 127)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_temp_5F_dir = function_add_5F_path_5F_component (result_temp_5F_dir, inArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 129)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 131)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_string var_curdir = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 132)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 133)).objectCompare (GALGAS_char (TO_UNICODE (46)))).operator_and (GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 133)).objectCompare (GALGAS_char (TO_UNICODE (47)))) COMMA_SOURCE_FILE ("goil_routines.galgas", 133)).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_temp_5F_dir = result_temp_5F_dir.getter_stringByRemovingCharacterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 134)).getter_stringByRemovingCharacterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 134)) ;
      }
      result_temp_5F_dir = var_curdir.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 136)).add_operation (result_temp_5F_dir, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 136)) ;
    }
    const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (result_temp_5F_dir.getter_length (SOURCE_FILE ("goil_routines.galgas", 138)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 138)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 138)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_temp_5F_dir.dotAssign_operation (GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 139)) ;
    }
  }
//---
  return result_temp_5F_dir ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_templates_5F_directory [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_templates_5F_directory (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* §§ inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templates_5F_directory (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_templates_5F_directory ("templates_directory",
                                                                        functionWithGenericHeader_templates_5F_directory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        1,
                                                                        functionArgs_templates_5F_directory) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'templateFilePath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_templateFilePath (const GALGAS_string & constinArgument_prefix,
                                         const GALGAS_string & constinArgument_file,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_path ; // Returned variable
  GALGAS_stringlist var_components = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 150)) ;
  GALGAS_string var_templateDir = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 151)) ;
  GALGAS_bool var_notFound = GALGAS_bool (true) ;
  GALGAS_bool var_notOver = GALGAS_bool (true) ;
  result_path = GALGAS_string::makeEmptyString () ;
  if (var_components.getter_length (SOURCE_FILE ("goil_routines.galgas", 156)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 156)).isValid ()) {
    uint32_t variant_4971 = var_components.getter_length (SOURCE_FILE ("goil_routines.galgas", 156)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 156)).uintValue () ;
    bool loop_4971 = true ;
    while (loop_4971) {
      loop_4971 = var_notFound.operator_and (var_notOver COMMA_SOURCE_FILE ("goil_routines.galgas", 157)).isValid () ;
      if (loop_4971) {
        loop_4971 = var_notFound.operator_and (var_notOver COMMA_SOURCE_FILE ("goil_routines.galgas", 157)).boolValue () ;
      }
      if (loop_4971 && (0 == variant_4971)) {
        loop_4971 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 156)) ;
      }
      if (loop_4971) {
        variant_4971 -- ;
        GALGAS_string var_targetPath = var_templateDir.add_operation (GALGAS_string::constructor_componentsJoinedByString (var_components, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 158)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 158)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 158)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 158)) ;
        const enumGalgasBool test_0 = var_targetPath.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 160)).boolEnum () ;
        if (kBoolTrue == test_0) {
          var_notFound = GALGAS_bool (false) ;
          result_path = var_targetPath ;
        }
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, var_components.getter_length (SOURCE_FILE ("goil_routines.galgas", 164)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          GALGAS_string joker_5324 ; // Joker input parameter
          var_components.modifier_popLast (joker_5324, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 165)) ;
          }
        }else if (kBoolFalse == test_1) {
          var_notOver = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_path ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_templateFilePath [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_templateFilePath (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* §§ inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templateFilePath (operand0,
                                    operand1,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_templateFilePath ("templateFilePath",
                                                                  functionWithGenericHeader_templateFilePath,
                                                                  & kTypeDescriptor_GALGAS_string,
                                                                  2,
                                                                  functionArgs_templateFilePath) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'allTemplatePaths'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist function_allTemplatePaths (const GALGAS_string & constinArgument_prefix,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 176)) ;
  GALGAS_string var_partialPath = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 177)) ;
  result_paths = GALGAS_stringlist::constructor_listWithValue (var_partialPath  COMMA_SOURCE_FILE ("goil_routines.galgas", 179)) ;
  cEnumerator_stringlist enumerator_5702 (var_components, kEnumeration_up) ;
  while (enumerator_5702.hasCurrentObject ()) {
    var_partialPath = function_add_5F_path_5F_component (var_partialPath, enumerator_5702.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 182)) ;
    {
    result_paths.modifier_insertAtIndex (var_partialPath, GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 183)) ;
    }
    enumerator_5702.gotoNextObject () ;
  }
//---
  return result_paths ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_allTemplatePaths [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_allTemplatePaths (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* §§ inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplatePaths (operand0,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_allTemplatePaths ("allTemplatePaths",
                                                                  functionWithGenericHeader_allTemplatePaths,
                                                                  & kTypeDescriptor_GALGAS_stringlist,
                                                                  1,
                                                                  functionArgs_allTemplatePaths) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'allTemplateFilePaths'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist function_allTemplateFilePaths (const GALGAS_string & constinArgument_prefix,
                                                 const GALGAS_string & constinArgument_file,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 191)) ;
  GALGAS_string var_templateDir = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 192)) ;
  GALGAS_bool var_notOver = GALGAS_bool (true) ;
  result_paths = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 194)) ;
  if (var_components.getter_length (SOURCE_FILE ("goil_routines.galgas", 196)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 196)).isValid ()) {
    uint32_t variant_6137 = var_components.getter_length (SOURCE_FILE ("goil_routines.galgas", 196)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 196)).uintValue () ;
    bool loop_6137 = true ;
    while (loop_6137) {
      loop_6137 = var_notOver.isValid () ;
      if (loop_6137) {
        loop_6137 = var_notOver.boolValue () ;
      }
      if (loop_6137 && (0 == variant_6137)) {
        loop_6137 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 196)) ;
      }
      if (loop_6137) {
        variant_6137 -- ;
        GALGAS_string var_intermediatePath = GALGAS_string::constructor_componentsJoinedByString (var_components, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 198)) ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_intermediatePath.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          var_intermediatePath.dotAssign_operation (GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)) ;
        }
        GALGAS_string var_targetPath = var_templateDir.add_operation (var_intermediatePath, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 200)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 200)) ;
        const enumGalgasBool test_1 = var_targetPath.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 202)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_paths.addAssign_operation (var_targetPath  COMMA_SOURCE_FILE ("goil_routines.galgas", 203)) ;
        }
        const enumGalgasBool test_2 = GALGAS_bool (kIsStrictSup, var_components.getter_length (SOURCE_FILE ("goil_routines.galgas", 205)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          GALGAS_string joker_6566 ; // Joker input parameter
          var_components.modifier_popLast (joker_6566, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 206)) ;
          }
        }else if (kBoolFalse == test_2) {
          var_notOver = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_paths ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_allTemplateFilePaths [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_allTemplateFilePaths (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* §§ inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplateFilePaths (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_allTemplateFilePaths ("allTemplateFilePaths",
                                                                      functionWithGenericHeader_allTemplateFilePaths,
                                                                      & kTypeDescriptor_GALGAS_stringlist,
                                                                      2,
                                                                      functionArgs_allTemplateFilePaths) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Routine 'prefix'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_prefix (GALGAS_prefix_5F_map inArgument_p,
                     GALGAS_string inArgument_key,
                     GALGAS_string & outArgument_val,
                     C_Compiler * inCompiler
                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_val.drop () ; // Release 'out' argument
  GALGAS_lstring var_lkey = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 214))  COMMA_SOURCE_FILE ("goil_routines.galgas", 214)) ;
  GALGAS_string joker_6756 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey, outArgument_val, joker_6756, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 215)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'performReplace'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_performReplace (GALGAS_prefix_5F_map inArgument_p,
                             GALGAS_string inArgument_key,
                             GALGAS_string inArgument_name,
                             GALGAS_string & ioArgument_res,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 219))  COMMA_SOURCE_FILE ("goil_routines.galgas", 219)) ;
  GALGAS_string var_prefix ;
  GALGAS_string var_tag_5F_to_5F_rep ;
  inArgument_p.method_prefix (var_lkey, var_prefix, var_tag_5F_to_5F_rep, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 222)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep, var_prefix.add_operation (inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 223)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 223)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'doReplace'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_doReplace (GALGAS_string & ioArgument_s,
                        GALGAS_string inArgument_o,
                        GALGAS_string inArgument_n,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 227)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'do_replace_default'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_do_5F_replace_5F_default (GALGAS_string & ioArgument_s,
                                       GALGAS_string inArgument_o,
                                       GALGAS_string inArgument_n,
                                       GALGAS_string inArgument_d,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_n.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 232)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_d, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 234)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'replace_no_prefix'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_replace_5F_no_5F_prefix (GALGAS_prefix_5F_map inArgument_p,
                                      GALGAS_string inArgument_key,
                                      GALGAS_string inArgument_name,
                                      GALGAS_string & ioArgument_res,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 239))  COMMA_SOURCE_FILE ("goil_routines.galgas", 239)) ;
  GALGAS_string var_tag_5F_to_5F_rep ;
  GALGAS_string joker_7569 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey, joker_7569, var_tag_5F_to_5F_rep, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 242)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep, inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 243)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'table_core'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_table_5F_core (GALGAS_string inArgument_typename,
                            GALGAS_string inArgument_varname,
                            GALGAS_string inArgument_obj_5F_prefix,
                            GALGAS_stringset inArgument_names,
                            GALGAS_string & ioArgument_header,
                            GALGAS_string & ioArgument_implementation,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_n = GALGAS_uint ((uint32_t) 0U) ;
  cEnumerator_stringset enumerator_8035 (inArgument_names, kEnumeration_up) ;
  while (enumerator_8035.hasCurrentObject ()) {
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 262)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 262)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 262)).add_operation (enumerator_8035.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 262)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 262)).add_operation (var_n.getter_string (SOURCE_FILE ("goil_routines.galgas", 262)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 262)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 262)) ;
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 270)).add_operation (enumerator_8035.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 270)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 270)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 270)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 270)).add_operation (enumerator_8035.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 270)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 270)) ;
    ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("    (tpl_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)).add_operation (inArgument_typename, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)).add_operation (GALGAS_string (" *)&"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)).add_operation (inArgument_obj_5F_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)).add_operation (enumerator_8035.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)) ;
    var_n.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 272)) ;
    const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_n.objectCompare (inArgument_names.getter_count (SOURCE_FILE ("goil_routines.galgas", 273)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string (",\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 274)) ;
    }else if (kBoolFalse == test_0) {
      ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 275)) ;
    }
    enumerator_8035.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'add_to_stringset'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_to_5F_stringset (GALGAS_stringset & ioArgument_ss,
                                     GALGAS_string inArgument_new,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = ioArgument_ss.getter_hasKey (inArgument_new COMMA_SOURCE_FILE ("goil_routines.galgas", 380)).boolEnum () ;
  if (kBoolTrue == test_0) {
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 381)), GALGAS_string ("'").add_operation (inArgument_new, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 381)).add_operation (GALGAS_string ("' is already declared before"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 381))  COMMA_SOURCE_FILE ("goil_routines.galgas", 381)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_ss.addAssign_operation (inArgument_new  COMMA_SOURCE_FILE ("goil_routines.galgas", 383)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'file_in_path'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_file_5F_in_5F_path (GALGAS_lstring & ioArgument_file_5F_name,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_include_5F_path = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_INCLUDE_PATH")  COMMA_SOURCE_FILE ("goil_routines.galgas", 389)) ;
  GALGAS_stringlist var_systemPaths = function_allTemplatePaths (GALGAS_string ("config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 393)) ;
  GALGAS_stringlist var_includePathList ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_include_5F_path.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_includePathList = var_include_5F_path.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("goil_routines.galgas", 396)) ;
  }else if (kBoolFalse == test_0) {
    var_includePathList = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 398)) ;
  }
  GALGAS_stringlist var_path_5F_list = var_includePathList.add_operation (var_systemPaths, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 400)) ;
  GALGAS_bool var_not_5F_found = GALGAS_bool (true) ;
  cEnumerator_stringlist enumerator_12423 (var_path_5F_list, kEnumeration_up) ;
  while (enumerator_12423.hasCurrentObject ()) {
    GALGAS_string var_full_5F_file_5F_path = enumerator_12423.current_mValue (HERE) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path.getter_characterAtIndex (var_full_5F_file_5F_path.getter_length (SOURCE_FILE ("goil_routines.galgas", 406)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 406)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 406)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_full_5F_file_5F_path.dotAssign_operation (GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 407)) ;
      }
    }
    var_full_5F_file_5F_path.dotAssign_operation (ioArgument_file_5F_name.getter_string (SOURCE_FILE ("goil_routines.galgas", 410))  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)) ;
    const enumGalgasBool test_3 = var_full_5F_file_5F_path.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 411)).operator_and (var_not_5F_found COMMA_SOURCE_FILE ("goil_routines.galgas", 411)).boolEnum () ;
    if (kBoolTrue == test_3) {
      ioArgument_file_5F_name = GALGAS_lstring::constructor_new (var_full_5F_file_5F_path, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 412))  COMMA_SOURCE_FILE ("goil_routines.galgas", 412)) ;
      var_not_5F_found = GALGAS_bool (false) ;
    }
    enumerator_12423.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'is_in_lstringlist'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_is_5F_in_5F_lstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      GALGAS_lstring & outArgument_f,
                                      GALGAS_bool & outArgument_p,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_f.drop () ; // Release 'out' argument
  outArgument_p.drop () ; // Release 'out' argument
  outArgument_p = GALGAS_bool (false) ;
  outArgument_f = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 424))  COMMA_SOURCE_FILE ("goil_routines.galgas", 424)) ;
  cEnumerator_lstringlist enumerator_13066 (inArgument_l, kEnumeration_up) ;
  while (enumerator_13066.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_13066.current_mValue (HERE).getter_string (SOURCE_FILE ("goil_routines.galgas", 426)).objectCompare (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 426)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_p = GALGAS_bool (true) ;
      outArgument_f = enumerator_13066.current_mValue (HERE) ;
    }
    enumerator_13066.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'isInLstringlist'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_isInLstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_p ; // Returned variable
  result_p = GALGAS_bool (false) ;
  cEnumerator_lstringlist enumerator_13264 (inArgument_l, kEnumeration_up) ;
  while (enumerator_13264.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_13264.current_mValue (HERE).getter_string (SOURCE_FILE ("goil_routines.galgas", 439)).objectCompare (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 439)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_p = GALGAS_bool (true) ;
    }
    enumerator_13264.gotoNextObject () ;
  }
//---
  return result_p ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_isInLstringlist [3] = {
  & kTypeDescriptor_GALGAS_lstringlist,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_isInLstringlist (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* §§ inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_lstringlist operand0 = GALGAS_lstringlist::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_isInLstringlist (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_isInLstringlist ("isInLstringlist",
                                                                 functionWithGenericHeader_isInLstringlist,
                                                                 & kTypeDescriptor_GALGAS_bool,
                                                                 2,
                                                                 functionArgs_isInLstringlist) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'add_lstring_unique'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_lstring_5F_unique (GALGAS_lstringlist & ioArgument_l,
                                       GALGAS_lstring inArgument_e,
                                       GALGAS_string inArgument_att,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool var_found ;
  GALGAS_lstring var_res ;
  {
  routine_is_5F_in_5F_lstringlist (ioArgument_l, inArgument_e, var_res, var_found, inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 451)) ;
  }
  const enumGalgasBool test_0 = var_found.boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_location location_1 (inArgument_e.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_1, inArgument_att.add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 453)).add_operation (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 453)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 453)).add_operation (GALGAS_string (" has already be listed"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 453))  COMMA_SOURCE_FILE ("goil_routines.galgas", 453)) ;
    GALGAS_location location_2 (var_res.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_2, GALGAS_string ("was listed here")  COMMA_SOURCE_FILE ("goil_routines.galgas", 454)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_l.addAssign_operation (inArgument_e  COMMA_SOURCE_FILE ("goil_routines.galgas", 456)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'set_lstring_if_empty'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_set_5F_lstring_5F_if_5F_empty (GALGAS_lstring & ioArgument_s,
                                            GALGAS_lstring inArgument_ns,
                                            GALGAS_string inArgument_att,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, ioArgument_s.getter_string (SOURCE_FILE ("goil_routines.galgas", 464)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_s = inArgument_ns ;
  }else if (kBoolFalse == test_0) {
    GALGAS_location location_1 (inArgument_ns.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_1, inArgument_att.add_operation (GALGAS_string (" Redefinition"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 467))  COMMA_SOURCE_FILE ("goil_routines.galgas", 467)) ;
    GALGAS_location location_2 (ioArgument_s.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_2, GALGAS_string ("was defined here")  COMMA_SOURCE_FILE ("goil_routines.galgas", 468)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'add_makefile_flag_if_not_empty'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_makefile_5F_flag_5F_if_5F_not_5F_empty (GALGAS_string & ioArgument_receiver,
                                                            GALGAS_string inArgument_flag_5F_name,
                                                            GALGAS_string inArgument_flag_5F_value,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_flag_5F_value.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_receiver.dotAssign_operation (inArgument_flag_5F_name.add_operation (GALGAS_string ("="), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 477)).add_operation (inArgument_flag_5F_value, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 477)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 477))  COMMA_SOURCE_FILE ("goil_routines.galgas", 477)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'lstringWith'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_lstringWith (GALGAS_string inArgument_s,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_r ; // Returned variable
  result_r = GALGAS_lstring::constructor_new (inArgument_s, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 482))  COMMA_SOURCE_FILE ("goil_routines.galgas", 482)) ;
//---
  return result_r ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_lstringWith [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_lstringWith (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* §§ inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_lstringWith (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_lstringWith ("lstringWith",
                                                             functionWithGenericHeader_lstringWith,
                                                             & kTypeDescriptor_GALGAS_lstring,
                                                             1,
                                                             functionArgs_lstringWith) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stripString'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stripString (GALGAS_string inArgument_s,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_r ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 486)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_uint var_first = GALGAS_uint ((uint32_t) 0U) ;
    GALGAS_uint var_last = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 488)) ;
    GALGAS_bool var_finished = GALGAS_bool (false) ;
    if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 491)).isValid ()) {
      uint32_t variant_14296 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 491)).uintValue () ;
      bool loop_14296 = true ;
      while (loop_14296) {
        loop_14296 = var_finished.operator_not (SOURCE_FILE ("goil_routines.galgas", 492)).isValid () ;
        if (loop_14296) {
          loop_14296 = var_finished.operator_not (SOURCE_FILE ("goil_routines.galgas", 492)).boolValue () ;
        }
        if (loop_14296 && (0 == variant_14296)) {
          loop_14296 = false ;
          inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 491)) ;
        }
        if (loop_14296) {
          variant_14296 -- ;
          const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_first, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 493)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
          if (kBoolTrue == test_1) {
            var_first.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 494)) ;
            const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_first.objectCompare (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 495)))).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_finished = GALGAS_bool (true) ;
            }
          }else if (kBoolFalse == test_1) {
            var_finished = GALGAS_bool (true) ;
          }
        }
      }
    }
    var_finished = GALGAS_bool (false) ;
    if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 500)).isValid ()) {
      uint32_t variant_14581 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 500)).uintValue () ;
      bool loop_14581 = true ;
      while (loop_14581) {
        loop_14581 = var_finished.operator_not (SOURCE_FILE ("goil_routines.galgas", 501)).isValid () ;
        if (loop_14581) {
          loop_14581 = var_finished.operator_not (SOURCE_FILE ("goil_routines.galgas", 501)).boolValue () ;
        }
        if (loop_14581 && (0 == variant_14581)) {
          loop_14581 = false ;
          inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 500)) ;
        }
        if (loop_14581) {
          variant_14581 -- ;
          const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_last.substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 502)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 502)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_last.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 503)) ;
            const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_last.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_finished = GALGAS_bool (true) ;
            }
          }else if (kBoolFalse == test_3) {
            var_finished = GALGAS_bool (true) ;
          }
        }
      }
    }
    const enumGalgasBool test_5 = GALGAS_bool (kIsStrictInf, var_first.objectCompare (var_last)).boolEnum () ;
    if (kBoolTrue == test_5) {
      result_r = inArgument_s.getter_subString (var_first, var_last.substract_operation (var_first, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 509)) COMMA_SOURCE_FILE ("goil_routines.galgas", 509)) ;
    }else if (kBoolFalse == test_5) {
      result_r = GALGAS_string::makeEmptyString () ;
    }
  }else if (kBoolFalse == test_0) {
    result_r = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_r ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stripString [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stripString (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* §§ inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stripString (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stripString ("stripString",
                                                             functionWithGenericHeader_stripString,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stripString) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'errorNoFileFound'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_errorNoFileFound (const GALGAS_stringlist constinArgument_searchedPaths,
                               const GALGAS_string constinArgument_kind,
                               const GALGAS_lstring constinArgument_file,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_m = GALGAS_string ("cannot find a valid path for the '").add_operation (constinArgument_file.getter_string (SOURCE_FILE ("goil_routines.galgas", 522)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 522)).add_operation (GALGAS_string ("' "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 522)).add_operation (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 522)).add_operation (GALGAS_string (" file. I have tried:"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 522)) ;
  cEnumerator_stringlist enumerator_15159 (constinArgument_searchedPaths, kEnumeration_up) ;
  while (enumerator_15159.hasCurrentObject ()) {
    var_m.dotAssign_operation (GALGAS_string ("\n"
      "  - '").add_operation (enumerator_15159.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 524)).add_operation (GALGAS_string ("'"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 524))  COMMA_SOURCE_FILE ("goil_routines.galgas", 524)) ;
    enumerator_15159.gotoNextObject () ;
  }
  GALGAS_location location_0 (constinArgument_file.getter_location (HERE)) ; // Implicit use of 'location' getter
  inCompiler->emitSemanticError (location_0, var_m  COMMA_SOURCE_FILE ("goil_routines.galgas", 526)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stringLBool'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringLBool (const GALGAS_lbool & constinArgument_boolValue,
                                    C_Compiler * /* inCompiler */
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_boolValue.getter_bool (SOURCE_FILE ("goil_routines.galgas", 532)).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("TRUE") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("FALSE") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringLBool [2] = {
  & kTypeDescriptor_GALGAS_lbool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringLBool (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* §§ inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_lbool operand0 = GALGAS_lbool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                             inCompiler
                                                             COMMA_THERE) ;
  return function_stringLBool (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringLBool ("stringLBool",
                                                             functionWithGenericHeader_stringLBool,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stringLBool) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'setDefaults'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setDefaults (const GALGAS_implementation constinArgument_imp,
                          GALGAS_applicationDefinition & ioArgument_application,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectsMap var_objects = ioArgument_application.getter_objects (SOURCE_FILE ("defaults.galgas", 32)) ;
  cEnumerator_lstringlist enumerator_980 (var_objects.getter_keyList (SOURCE_FILE ("defaults.galgas", 35)), kEnumeration_up) ;
  while (enumerator_980.hasCurrentObject ()) {
    cMapElement_objectsMap * objectArray_992 = (cMapElement_objectsMap *) var_objects.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_980.current_mValue (HERE), kSearchErrorMessage_objectsMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 36)) ;
    if (NULL != objectArray_992) {
        macroValidSharedObject (objectArray_992, cMapElement_objectsMap) ;
      GALGAS_objectKindMap var_objOfKind = objectArray_992->mAttribute_objectsOfKind.getter_objects (SOURCE_FILE ("defaults.galgas", 37)) ;
      cEnumerator_lstringlist enumerator_1151 (var_objOfKind.getter_keyList (SOURCE_FILE ("defaults.galgas", 38)), kEnumeration_up) ;
      while (enumerator_1151.hasCurrentObject ()) {
        cMapElement_objectKindMap * objectArray_1167 = (cMapElement_objectKindMap *) var_objOfKind.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_1151.current_mValue (HERE), kSearchErrorMessage_objectKindMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 39)) ;
        if (NULL != objectArray_1167) {
            macroValidSharedObject (objectArray_1167, cMapElement_objectKindMap) ;
          GALGAS_implementationObject var_impObject = callCategoryGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_980.current_mValue (HERE).getter_string (SOURCE_FILE ("defaults.galgas", 40)), inCompiler COMMA_SOURCE_FILE ("defaults.galgas", 40)) ;
          {
          routine_setDefaultsForType (var_impObject.getter_attributes (SOURCE_FILE ("defaults.galgas", 41)), objectArray_1167->mAttribute_attributes, inCompiler  COMMA_SOURCE_FILE ("defaults.galgas", 41)) ;
          }
        }
        enumerator_1151.gotoNextObject () ;
      }
      {
      objectArray_992->mAttribute_objectsOfKind.modifier_setObjects (var_objOfKind COMMA_SOURCE_FILE ("defaults.galgas", 44)) ;
      }
    }
    enumerator_980.gotoNextObject () ;
  }
  {
  ioArgument_application.modifier_setObjects (var_objects COMMA_SOURCE_FILE ("defaults.galgas", 48)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'attributeAllowsAuto'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_attributeAllowsAuto (const GALGAS_impType & constinArgument_type,
                                          C_Compiler * /* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_allowsAuto ; // Returned variable
  result_allowsAuto = GALGAS_bool (true) ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (constinArgument_type.ptr ())) {
      GALGAS_impAutoDefaultType cast_6562_autoType ((cPtr_impAutoDefaultType *) constinArgument_type.ptr ()) ;
      const enumGalgasBool test_0 = cast_6562_autoType.getter_withAuto (SOURCE_FILE ("semantic_verification.galgas", 225)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 225)).boolEnum () ;
      if (kBoolTrue == test_0) {
        result_allowsAuto = GALGAS_bool (false) ;
      }
    }else{
      result_allowsAuto = GALGAS_bool (false) ;
    }
  }
//---
  return result_allowsAuto ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_attributeAllowsAuto [2] = {
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_attributeAllowsAuto (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* §§ inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_impType operand0 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_attributeAllowsAuto (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_attributeAllowsAuto ("attributeAllowsAuto",
                                                                     functionWithGenericHeader_attributeAllowsAuto,
                                                                     & kTypeDescriptor_GALGAS_bool,
                                                                     1,
                                                                     functionArgs_attributeAllowsAuto) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'verifyAllAttributes'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAllAttributes (const GALGAS_implementation constinArgument_imp,
                                  const GALGAS_objectsMap constinArgument_objects,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_objectsMap enumerator_6874 (constinArgument_objects, kEnumeration_up) ;
  while (enumerator_6874.hasCurrentObject ()) {
    GALGAS_implementationObject var_impObj = callCategoryGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 242)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 242)) ;
    cEnumerator_objectKindMap enumerator_7042 (enumerator_6874.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("semantic_verification.galgas", 244)), kEnumeration_up) ;
    while (enumerator_7042.hasCurrentObject ()) {
      cEnumerator_implementationObjectMap enumerator_7087 (var_impObj.getter_attributes (SOURCE_FILE ("semantic_verification.galgas", 245)), kEnumeration_up) ;
      while (enumerator_7087.hasCurrentObject ()) {
        const enumGalgasBool test_0 = enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 246)).getter_hasKey (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 246)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 246)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_object_5F_t var_value ;
          enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 250)).method_get (enumerator_7087.current_lkey (HERE), var_value, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 250)) ;
          if (var_value.isValid ()) {
            if (var_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
              const enumGalgasBool test_1 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 254)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 254)).boolEnum () ;
              if (kBoolTrue == test_1) {
                inCompiler->emitSemanticError (var_value.getter_location (SOURCE_FILE ("semantic_verification.galgas", 255)), GALGAS_string ("AUTO value is not allowed for the ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 255)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)) ;
              }
            }
          }
        }else if (kBoolFalse == test_0) {
          const enumGalgasBool test_2 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_and (enumerator_7087.current_type (HERE).getter_multiple (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).boolEnum () ;
          if (kBoolTrue == test_2) {
            GALGAS_location location_3 (enumerator_7042.current_lkey (HERE).getter_location (HERE)) ; // Implicit use of 'location' getter
            inCompiler->emitSemanticError (location_3, GALGAS_string ("In ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7042.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (", attribute "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" is not defined and is not AUTO"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)) ;
          }
        }
        if (enumerator_7087.current_type (HERE).isValid ()) {
          if (enumerator_7087.current_type (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impAutoDefaultType) {
          }
        }
        enumerator_7087.gotoNextObject () ;
      }
      enumerator_7042.gotoNextObject () ;
    }
    enumerator_6874.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'verifyAll'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAll (const GALGAS_implementation constinArgument_imp,
                        const GALGAS_applicationDefinition constinArgument_application,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_verifyAllAttributes (constinArgument_imp, constinArgument_application.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 681)), inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 681)) ;
  }
  callCategoryMethod_verifyApplication ((const cPtr_implementation *) constinArgument_imp.ptr (), constinArgument_application, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 682)) ;
  callCategoryMethod_verifyCrossReferences ((const cPtr_applicationDefinition *) constinArgument_application.ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 685)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Function 'emptyApplicationDefinition'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition function_emptyApplicationDefinition (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_applicationDefinition result_result ; // Returned variable
  result_result = GALGAS_applicationDefinition::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 56)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 57)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 58)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 59)), GALGAS_objectsMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 60))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 55)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyApplicationDefinition [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyApplicationDefinition (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_emptyApplicationDefinition (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyApplicationDefinition ("emptyApplicationDefinition",
                                                                            functionWithGenericHeader_emptyApplicationDefinition,
                                                                            & kTypeDescriptor_GALGAS_applicationDefinition,
                                                                            0,
                                                                            functionArgs_emptyApplicationDefinition) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'osObject'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_osObject (const GALGAS_objectsMap & constinArgument_objects,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_os ; // Returned variable
  GALGAS_objectKind var_objectsForKind ;
  constinArgument_objects.method_get (function_lstringWith (GALGAS_string ("OS"), inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)), var_objectsForKind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)) ;
  GALGAS_lstringlist var_names = var_objectsForKind.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 68)).getter_keyList (SOURCE_FILE ("goil_types_root.galgas", 68)) ;
  GALGAS_lstring var_name ;
  var_names.method_first (var_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 70)) ;
  var_objectsForKind.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 71)).method_get (var_name, result_os, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 71)) ;
//---
  return result_os ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_osObject [2] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_osObject (C_Compiler * inCompiler,
                                                         const cObjectArray & inEffectiveParameterArray,
                                                         const GALGAS_location & /* §§ inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_osObject (operand0,
                            inCompiler
                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_osObject ("osObject",
                                                          functionWithGenericHeader_osObject,
                                                          & kTypeDescriptor_GALGAS_objectAttributes,
                                                          1,
                                                          functionArgs_osObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'objectForKindAndName'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_objectForKindAndName (const GALGAS_objectsMap & constinArgument_objects,
                                                       const GALGAS_string & constinArgument_kind,
                                                       const GALGAS_string & constinArgument_name,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_object ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 79)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_objectKind var_kindObj ;
    constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)), var_kindObj, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)) ;
    const enumGalgasBool test_1 = var_kindObj.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 82)).getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 82)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_kindObj.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 83)).method_get (function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)), result_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)) ;
    }else if (kBoolFalse == test_1) {
      result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 85))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 85)) ;
    }
  }else if (kBoolFalse == test_0) {
    result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 88))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 88)) ;
  }
//---
  return result_object ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_objectForKindAndName [4] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_objectForKindAndName (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* §§ inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_objectForKindAndName (operand0,
                                        operand1,
                                        operand2,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_objectForKindAndName ("objectForKindAndName",
                                                                      functionWithGenericHeader_objectForKindAndName,
                                                                      & kTypeDescriptor_GALGAS_objectAttributes,
                                                                      3,
                                                                      functionArgs_objectForKindAndName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'setObjectForKindAndName'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setObjectForKindAndName (GALGAS_objectsMap & ioArgument_objects,
                                      const GALGAS_string constinArgument_kind,
                                      const GALGAS_string constinArgument_name,
                                      const GALGAS_objectAttributes constinArgument_object,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkind = function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 97)) ;
  GALGAS_lstring var_lname = function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 98)) ;
  GALGAS_objectKind var_kindObj = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 99))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 99)) ;
  const enumGalgasBool test_0 = ioArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 100)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_objects.modifier_del (var_lkind, var_kindObj, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 101)) ;
    }
  }
  GALGAS_objectKindMap var_kindMap = var_kindObj.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 103)) ;
  const enumGalgasBool test_1 = var_kindMap.getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 104)).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    GALGAS_objectAttributes joker_2767 ; // Joker input parameter
    var_kindMap.modifier_del (var_lname, joker_2767, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 105)) ;
    }
  }
  {
  var_kindMap.modifier_put (var_lname, constinArgument_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 107)) ;
  }
  {
  var_kindObj.modifier_setObjects (var_kindMap COMMA_SOURCE_FILE ("goil_types_root.galgas", 108)) ;
  }
  {
  ioArgument_objects.modifier_put (var_lkind, var_kindObj, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 109)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'objectsForKind'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind function_objectsForKind (const GALGAS_objectsMap & constinArgument_objects,
                                           const GALGAS_string & constinArgument_kind,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectKind result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 116)).boolEnum () ;
  if (kBoolTrue == test_0) {
    constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 117)), result_result, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 117)) ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 119))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 119)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_objectsForKind [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_objectsForKind (C_Compiler * inCompiler,
                                                               const cObjectArray & inEffectiveParameterArray,
                                                               const GALGAS_location & /* §§ inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_objectsForKind (operand0,
                                  operand1,
                                  inCompiler
                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_objectsForKind ("objectsForKind",
                                                                functionWithGenericHeader_objectsForKind,
                                                                & kTypeDescriptor_GALGAS_objectKind,
                                                                2,
                                                                functionArgs_objectsForKind) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'listInOS'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList function_listInOS (const GALGAS_objectsMap & constinArgument_objects,
                                         const GALGAS_string & constinArgument_attributeName,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_items ; // Returned variable
  GALGAS_object_5F_t var_itemsContainer ;
  GALGAS_objectAttributes var_os = function_osObject (constinArgument_objects, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 128)) ;
  var_os.getter_objectParams (SOURCE_FILE ("goil_types_root.galgas", 129)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)), var_itemsContainer, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 129)) ;
  result_items = function_multipleAttributeOrError (var_itemsContainer, constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 130)) ;
//---
  return result_items ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_listInOS [3] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_listInOS (C_Compiler * inCompiler,
                                                         const cObjectArray & inEffectiveParameterArray,
                                                         const GALGAS_location & /* §§ inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_listInOS (operand0,
                            operand1,
                            inCompiler
                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_listInOS ("listInOS",
                                                          functionWithGenericHeader_listInOS,
                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                          2,
                                                          functionArgs_listInOS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'generate_signed_type'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_signed_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                         GALGAS_string inArgument_err,
                                         GALGAS_string & outArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_s_38_ = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 7U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 37)) ;
  GALGAS_uint_36__34_ var_max_5F_s_31__36_ = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 15U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 38)) ;
  GALGAS_uint_36__34_ var_max_5F_s_33__32_ = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 31U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 39)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_38_)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_type = GALGAS_string ("s8") ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_31__36_)).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_type = GALGAS_string ("s16") ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_s_33__32_)).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_type = GALGAS_string ("s32") ;
      }else if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)), inArgument_err  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 51)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'generate_unsigned_type'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_unsigned_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                           GALGAS_string inArgument_err,
                                           GALGAS_string & outArgument_type,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38_ = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 8U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 62)) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36_ = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 16U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 63)) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32_ = GALGAS_uint_36__34_ ((uint64_t) 1ULL).left_shift_operation (GALGAS_uint ((uint32_t) 32U) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 64)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_38_)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_type = GALGAS_string ("u8") ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_31__36_)).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_type = GALGAS_string ("u16") ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, inArgument_count.objectCompare (var_max_5F_u_33__32_)).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_type = GALGAS_string ("u32") ;
      }else if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)), inArgument_err  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 76)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'generate_mask_type'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_mask_5F_type (GALGAS_uint_36__34_ inArgument_count,
                                       GALGAS_string inArgument_err,
                                       GALGAS_string & outArgument_type,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_type.drop () ; // Release 'out' argument
  GALGAS_uint_36__34_ var_max_5F_u_38_ = GALGAS_uint_36__34_ ((uint64_t) 8ULL) ;
  GALGAS_uint_36__34_ var_max_5F_u_31__36_ = GALGAS_uint_36__34_ ((uint64_t) 16ULL) ;
  GALGAS_uint_36__34_ var_max_5F_u_33__32_ = GALGAS_uint_36__34_ ((uint64_t) 32ULL) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_38_)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_type = GALGAS_string ("u8") ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_31__36_)).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_type = GALGAS_string ("u16") ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsInfOrEqual, inArgument_count.objectCompare (var_max_5F_u_33__32_)).boolEnum () ;
      if (kBoolTrue == test_2) {
        outArgument_type = GALGAS_string ("u32") ;
      }else if (kBoolFalse == test_2) {
        outArgument_type = GALGAS_string::makeEmptyString () ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)), inArgument_err  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 101)) ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'generate_all'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_all (const GALGAS_TfieldMap constinArgument_cfg,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_temp_5F_dir = function_templates_5F_directory (GALGAS_string ("code"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 695)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_temp_5F_dir.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_string var_target = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_target.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_string var_goilLog = function_computeTemplate (GALGAS_string::makeEmptyString (), constinArgument_cfg, GALGAS_string ("root"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 805)) ;
      const enumGalgasBool test_2 = GALGAS_bool (gOption_goil_5F_options_generate_5F_log.getter_value ()).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_goilLog.method_writeToFile (GALGAS_string ("goil.log"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 807)) ;
      }
    }else if (kBoolFalse == test_1) {
      inCompiler->printMessage (GALGAS_string ("No target platform given, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 827)) ;
    }
  }else if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No template directory defined, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 830)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_applicationDefinition::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_applicationDefinition) ;
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_cpuDescription.objectCompare (p->mAttribute_cpuDescription) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_version.objectCompare (p->mAttribute_version) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_versionDescription.objectCompare (p->mAttribute_versionDescription) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_objects.objectCompare (p->mAttribute_objects) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_applicationDefinition::objectCompare (const GALGAS_applicationDefinition & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition::GALGAS_applicationDefinition (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition GALGAS_applicationDefinition::constructor_default (LOCATION_ARGS) {
  return GALGAS_applicationDefinition::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_objectsMap::constructor_emptyMap (HERE)
                                                        COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition::GALGAS_applicationDefinition (const cPtr_applicationDefinition * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_applicationDefinition) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition GALGAS_applicationDefinition::constructor_new (const GALGAS_lstring & inAttribute_name,
                                                                            const GALGAS_lstring & inAttribute_cpuDescription,
                                                                            const GALGAS_lstring & inAttribute_version,
                                                                            const GALGAS_lstring & inAttribute_versionDescription,
                                                                            const GALGAS_objectsMap & inAttribute_objects
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_applicationDefinition result ;
  if (inAttribute_name.isValid () && inAttribute_cpuDescription.isValid () && inAttribute_version.isValid () && inAttribute_versionDescription.isValid () && inAttribute_objects.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_applicationDefinition (inAttribute_name, inAttribute_cpuDescription, inAttribute_version, inAttribute_versionDescription, inAttribute_objects COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_applicationDefinition::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_applicationDefinition::getter_name (UNUSED_LOCATION_ARGS) const {
  return mAttribute_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_applicationDefinition::getter_cpuDescription (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_cpuDescription ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_applicationDefinition::getter_cpuDescription (UNUSED_LOCATION_ARGS) const {
  return mAttribute_cpuDescription ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_applicationDefinition::getter_version (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_version ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_applicationDefinition::getter_version (UNUSED_LOCATION_ARGS) const {
  return mAttribute_version ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_applicationDefinition::getter_versionDescription (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_versionDescription ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_applicationDefinition::getter_versionDescription (UNUSED_LOCATION_ARGS) const {
  return mAttribute_versionDescription ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_applicationDefinition::getter_objects (UNUSED_LOCATION_ARGS) const {
  GALGAS_objectsMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_applicationDefinition * p = (const cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    result = p->mAttribute_objects ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap cPtr_applicationDefinition::getter_objects (UNUSED_LOCATION_ARGS) const {
  return mAttribute_objects ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::modifier_setName (GALGAS_lstring inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_name = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::modifier_setName (GALGAS_lstring inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_name = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::modifier_setCpuDescription (GALGAS_lstring inValue
                                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_cpuDescription = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::modifier_setCpuDescription (GALGAS_lstring inValue
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_cpuDescription = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::modifier_setVersion (GALGAS_lstring inValue
                                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_version = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::modifier_setVersion (GALGAS_lstring inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_version = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::modifier_setVersionDescription (GALGAS_lstring inValue
                                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_versionDescription = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::modifier_setVersionDescription (GALGAS_lstring inValue
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_versionDescription = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_applicationDefinition::modifier_setObjects (GALGAS_objectsMap inValue
                                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_applicationDefinition * p = (cPtr_applicationDefinition *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_applicationDefinition) ;
    p->mAttribute_objects = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_applicationDefinition::modifier_setObjects (GALGAS_objectsMap inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mAttribute_objects = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @applicationDefinition class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_applicationDefinition::cPtr_applicationDefinition (const GALGAS_lstring & in_name,
                                                        const GALGAS_lstring & in_cpuDescription,
                                                        const GALGAS_lstring & in_version,
                                                        const GALGAS_lstring & in_versionDescription,
                                                        const GALGAS_objectsMap & in_objects
                                                        COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_name (in_name),
mAttribute_cpuDescription (in_cpuDescription),
mAttribute_version (in_version),
mAttribute_versionDescription (in_versionDescription),
mAttribute_objects (in_objects) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_applicationDefinition::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_applicationDefinition ;
}

void cPtr_applicationDefinition::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@applicationDefinition:" ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_cpuDescription.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_version.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_versionDescription.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_objects.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_applicationDefinition::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_applicationDefinition (mAttribute_name, mAttribute_cpuDescription, mAttribute_version, mAttribute_versionDescription, mAttribute_objects COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @applicationDefinition type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_applicationDefinition ("applicationDefinition",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_applicationDefinition::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_applicationDefinition ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_applicationDefinition::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_applicationDefinition (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition GALGAS_applicationDefinition::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_applicationDefinition result ;
  const GALGAS_applicationDefinition * p = (const GALGAS_applicationDefinition *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_applicationDefinition *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("applicationDefinition", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_attributeRange::objectCompare (const GALGAS_attributeRange & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange::GALGAS_attributeRange (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange::GALGAS_attributeRange (const cPtr_attributeRange * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_attributeRange) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_attributeRange::getter_location (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_attributeRange * p = (const cPtr_attributeRange *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_attributeRange) ;
    result = p->mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_attributeRange::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @attributeRange class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_attributeRange::cPtr_attributeRange (const GALGAS_location & in_location
                                          COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_location (in_location) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @attributeRange type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_attributeRange ("attributeRange",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_attributeRange::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_attributeRange ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_attributeRange::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_attributeRange (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange GALGAS_attributeRange::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_attributeRange result ;
  const GALGAS_attributeRange * p = (const GALGAS_attributeRange *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_attributeRange *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("attributeRange", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_floatAttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_floatAttributeMinMax::objectCompare (const GALGAS_floatAttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax::GALGAS_floatAttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_floatAttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                       GALGAS_double::constructor_default (HERE),
                                                       GALGAS_double::constructor_default (HERE)
                                                       COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax::GALGAS_floatAttributeMinMax (const cPtr_floatAttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_floatAttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                          const GALGAS_double & inAttribute_min,
                                                                          const GALGAS_double & inAttribute_max
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_floatAttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_floatAttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (NULL != mObjectPtr) {
    const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double cPtr_floatAttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double GALGAS_floatAttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_double result ;
  if (NULL != mObjectPtr) {
    const cPtr_floatAttributeMinMax * p = (const cPtr_floatAttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double cPtr_floatAttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @floatAttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_floatAttributeMinMax::cPtr_floatAttributeMinMax (const GALGAS_location & in_location,
                                                      const GALGAS_double & in_min,
                                                      const GALGAS_double & in_max
                                                      COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_floatAttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeMinMax ;
}

void cPtr_floatAttributeMinMax::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@floatAttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_floatAttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_floatAttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @floatAttributeMinMax type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatAttributeMinMax ("floatAttributeMinMax",
                                             & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_floatAttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_floatAttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatAttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeMinMax GALGAS_floatAttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeMinMax result ;
  const GALGAS_floatAttributeMinMax * p = (const GALGAS_floatAttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_floatAttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatAttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_floatAttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_floatAttributeSet * p = (const cPtr_floatAttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_floatAttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_floatAttributeSet::objectCompare (const GALGAS_floatAttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet::GALGAS_floatAttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet GALGAS_floatAttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_floatAttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                    GALGAS_floatList::constructor_emptyList (HERE)
                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet::GALGAS_floatAttributeSet (const cPtr_floatAttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_floatAttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet GALGAS_floatAttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                    const GALGAS_floatList & inAttribute_valueList
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_floatAttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList GALGAS_floatAttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_floatList result ;
  if (NULL != mObjectPtr) {
    const cPtr_floatAttributeSet * p = (const cPtr_floatAttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_floatAttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList cPtr_floatAttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @floatAttributeSet class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_floatAttributeSet::cPtr_floatAttributeSet (const GALGAS_location & in_location,
                                                const GALGAS_floatList & in_valueList
                                                COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_floatAttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeSet ;
}

void cPtr_floatAttributeSet::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@floatAttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_floatAttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_floatAttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @floatAttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatAttributeSet ("floatAttributeSet",
                                          & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_floatAttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatAttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_floatAttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatAttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatAttributeSet GALGAS_floatAttributeSet::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_floatAttributeSet result ;
  const GALGAS_floatAttributeSet * p = (const GALGAS_floatAttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_floatAttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatAttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_noRange::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_noRange * p = (const cPtr_noRange *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_noRange) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_noRange::objectCompare (const GALGAS_noRange & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange::GALGAS_noRange (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange GALGAS_noRange::constructor_default (LOCATION_ARGS) {
  return GALGAS_noRange::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                          COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange::GALGAS_noRange (const cPtr_noRange * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_noRange) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange GALGAS_noRange::constructor_new (const GALGAS_location & inAttribute_location
                                                COMMA_LOCATION_ARGS) {
  GALGAS_noRange result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_noRange (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @noRange class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_noRange::cPtr_noRange (const GALGAS_location & in_location
                            COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_noRange::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_noRange ;
}

void cPtr_noRange::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@noRange:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_noRange::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_noRange (mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @noRange type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_noRange ("noRange",
                                & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_noRange::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_noRange ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_noRange::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_noRange (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_noRange GALGAS_noRange::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_noRange result ;
  const GALGAS_noRange * p = (const GALGAS_noRange *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_noRange *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("noRange", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_33__32_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_33__32_AttributeMinMax::objectCompare (const GALGAS_sint_33__32_AttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax::GALGAS_sint_33__32_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_sint::constructor_default (HERE),
                                                              GALGAS_sint::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax::GALGAS_sint_33__32_AttributeMinMax (const cPtr_sint_33__32_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_sint & inAttribute_min,
                                                                                        const GALGAS_sint & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_33__32_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint cPtr_sint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint GALGAS_sint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_33__32_AttributeMinMax * p = (const cPtr_sint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint cPtr_sint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @sint32AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_33__32_AttributeMinMax::cPtr_sint_33__32_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_sint & in_min,
                                                                    const GALGAS_sint & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_33__32_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ;
}

void cPtr_sint_33__32_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@sint32AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_33__32_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_33__32_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @sint32AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ("sint32AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_33__32_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_33__32_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeMinMax GALGAS_sint_33__32_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeMinMax result ;
  const GALGAS_sint_33__32_AttributeMinMax * p = (const GALGAS_sint_33__32_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_33__32_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_33__32_AttributeSet * p = (const cPtr_sint_33__32_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_33__32_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_33__32_AttributeSet::objectCompare (const GALGAS_sint_33__32_AttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet::GALGAS_sint_33__32_AttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet GALGAS_sint_33__32_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_sint_33__32_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet::GALGAS_sint_33__32_AttributeSet (const cPtr_sint_33__32_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_33__32_AttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet GALGAS_sint_33__32_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_sint_33__32_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_33__32_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List GALGAS_sint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_33__32_List result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_33__32_AttributeSet * p = (const cPtr_sint_33__32_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_33__32_AttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List cPtr_sint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @sint32AttributeSet class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_33__32_AttributeSet::cPtr_sint_33__32_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_sint_33__32_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_33__32_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet ;
}

void cPtr_sint_33__32_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@sint32AttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_33__32_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_33__32_AttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @sint32AttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_AttributeSet ("sint32AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_33__32_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_33__32_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_AttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_AttributeSet GALGAS_sint_33__32_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_AttributeSet result ;
  const GALGAS_sint_33__32_AttributeSet * p = (const GALGAS_sint_33__32_AttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_36__34_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_36__34_AttributeMinMax::objectCompare (const GALGAS_sint_36__34_AttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax::GALGAS_sint_36__34_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_sint_36__34_::constructor_default (HERE),
                                                              GALGAS_sint_36__34_::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax::GALGAS_sint_36__34_AttributeMinMax (const cPtr_sint_36__34_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_sint_36__34_ & inAttribute_min,
                                                                                        const GALGAS_sint_36__34_ & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_36__34_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ cPtr_sint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ GALGAS_sint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_36__34_AttributeMinMax * p = (const cPtr_sint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ cPtr_sint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @sint64AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_36__34_AttributeMinMax::cPtr_sint_36__34_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_sint_36__34_ & in_min,
                                                                    const GALGAS_sint_36__34_ & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_36__34_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ;
}

void cPtr_sint_36__34_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@sint64AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_36__34_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_36__34_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @sint64AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ("sint64AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_36__34_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_36__34_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeMinMax GALGAS_sint_36__34_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeMinMax result ;
  const GALGAS_sint_36__34_AttributeMinMax * p = (const GALGAS_sint_36__34_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_sint_36__34_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_sint_36__34_AttributeSet * p = (const cPtr_sint_36__34_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_sint_36__34_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_sint_36__34_AttributeSet::objectCompare (const GALGAS_sint_36__34_AttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet::GALGAS_sint_36__34_AttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet GALGAS_sint_36__34_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_sint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_sint_36__34_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet::GALGAS_sint_36__34_AttributeSet (const cPtr_sint_36__34_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_sint_36__34_AttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet GALGAS_sint_36__34_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_sint_36__34_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_sint_36__34_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List GALGAS_sint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_sint_36__34_List result ;
  if (NULL != mObjectPtr) {
    const cPtr_sint_36__34_AttributeSet * p = (const cPtr_sint_36__34_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_sint_36__34_AttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List cPtr_sint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @sint64AttributeSet class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_sint_36__34_AttributeSet::cPtr_sint_36__34_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_sint_36__34_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_sint_36__34_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet ;
}

void cPtr_sint_36__34_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@sint64AttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_sint_36__34_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_sint_36__34_AttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @sint64AttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_AttributeSet ("sint64AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sint_36__34_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sint_36__34_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_AttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_AttributeSet GALGAS_sint_36__34_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_AttributeSet result ;
  const GALGAS_sint_36__34_AttributeSet * p = (const GALGAS_sint_36__34_AttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_33__32_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_33__32_AttributeMinMax * p = (const cPtr_uint_33__32_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_33__32_AttributeMinMax::objectCompare (const GALGAS_uint_33__32_AttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax::GALGAS_uint_33__32_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax GALGAS_uint_33__32_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_uint::constructor_default (HERE),
                                                              GALGAS_uint::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax::GALGAS_uint_33__32_AttributeMinMax (const cPtr_uint_33__32_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_33__32_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax GALGAS_uint_33__32_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_uint & inAttribute_min,
                                                                                        const GALGAS_uint & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_33__32_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_33__32_AttributeMinMax * p = (const cPtr_uint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_uint_33__32_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_uint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_33__32_AttributeMinMax * p = (const cPtr_uint_33__32_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint cPtr_uint_33__32_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @uint32AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_33__32_AttributeMinMax::cPtr_uint_33__32_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_uint & in_min,
                                                                    const GALGAS_uint & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_33__32_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax ;
}

void cPtr_uint_33__32_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@uint32AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_33__32_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_33__32_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @uint32AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax ("uint32AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_33__32_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_33__32_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeMinMax GALGAS_uint_33__32_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeMinMax result ;
  const GALGAS_uint_33__32_AttributeMinMax * p = (const GALGAS_uint_33__32_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_33__32_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_33__32_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_33__32_AttributeSet * p = (const cPtr_uint_33__32_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_33__32_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_33__32_AttributeSet::objectCompare (const GALGAS_uint_33__32_AttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet::GALGAS_uint_33__32_AttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet GALGAS_uint_33__32_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_uint_33__32_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet::GALGAS_uint_33__32_AttributeSet (const cPtr_uint_33__32_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_33__32_AttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet GALGAS_uint_33__32_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_uint_33__32_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_33__32_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List GALGAS_uint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_33__32_List result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_33__32_AttributeSet * p = (const cPtr_uint_33__32_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_33__32_AttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List cPtr_uint_33__32_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @uint32AttributeSet class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_33__32_AttributeSet::cPtr_uint_33__32_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_uint_33__32_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_33__32_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet ;
}

void cPtr_uint_33__32_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@uint32AttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_33__32_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_33__32_AttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @uint32AttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_AttributeSet ("uint32AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_33__32_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_33__32_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_AttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_AttributeSet GALGAS_uint_33__32_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_AttributeSet result ;
  const GALGAS_uint_33__32_AttributeSet * p = (const GALGAS_uint_33__32_AttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_33__32_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_36__34_AttributeMinMax::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_36__34_AttributeMinMax * p = (const cPtr_uint_36__34_AttributeMinMax *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_min.objectCompare (p->mAttribute_min) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_max.objectCompare (p->mAttribute_max) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_36__34_AttributeMinMax::objectCompare (const GALGAS_uint_36__34_AttributeMinMax & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax::GALGAS_uint_36__34_AttributeMinMax (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax GALGAS_uint_36__34_AttributeMinMax::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                              GALGAS_uint_36__34_::constructor_default (HERE),
                                                              GALGAS_uint_36__34_::constructor_default (HERE)
                                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax::GALGAS_uint_36__34_AttributeMinMax (const cPtr_uint_36__34_AttributeMinMax * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34_AttributeMinMax) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax GALGAS_uint_36__34_AttributeMinMax::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                        const GALGAS_uint_36__34_ & inAttribute_min,
                                                                                        const GALGAS_uint_36__34_ & inAttribute_max
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeMinMax result ;
  if (inAttribute_location.isValid () && inAttribute_min.isValid () && inAttribute_max.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_36__34_AttributeMinMax (inAttribute_location, inAttribute_min, inAttribute_max COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_36__34_AttributeMinMax * p = (const cPtr_uint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
    result = p->mAttribute_min ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ cPtr_uint_36__34_AttributeMinMax::getter_min (UNUSED_LOCATION_ARGS) const {
  return mAttribute_min ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ GALGAS_uint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_36__34_AttributeMinMax * p = (const cPtr_uint_36__34_AttributeMinMax *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeMinMax) ;
    result = p->mAttribute_max ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ cPtr_uint_36__34_AttributeMinMax::getter_max (UNUSED_LOCATION_ARGS) const {
  return mAttribute_max ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                   Pointer class for @uint64AttributeMinMax class                                    *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_36__34_AttributeMinMax::cPtr_uint_36__34_AttributeMinMax (const GALGAS_location & in_location,
                                                                    const GALGAS_uint_36__34_ & in_min,
                                                                    const GALGAS_uint_36__34_ & in_max
                                                                    COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_min (in_min),
mAttribute_max (in_max) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_36__34_AttributeMinMax::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax ;
}

void cPtr_uint_36__34_AttributeMinMax::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@uint64AttributeMinMax:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_min.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_max.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_36__34_AttributeMinMax::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_36__34_AttributeMinMax (mAttribute_location, mAttribute_min, mAttribute_max COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @uint64AttributeMinMax type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax ("uint64AttributeMinMax",
                                                    & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_36__34_AttributeMinMax::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_36__34_AttributeMinMax::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_AttributeMinMax (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeMinMax GALGAS_uint_36__34_AttributeMinMax::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeMinMax result ;
  const GALGAS_uint_36__34_AttributeMinMax * p = (const GALGAS_uint_36__34_AttributeMinMax *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34_AttributeMinMax *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64AttributeMinMax", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_uint_36__34_AttributeSet::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_36__34_AttributeSet * p = (const cPtr_uint_36__34_AttributeSet *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_36__34_AttributeSet) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_valueList.objectCompare (p->mAttribute_valueList) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_uint_36__34_AttributeSet::objectCompare (const GALGAS_uint_36__34_AttributeSet & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet::GALGAS_uint_36__34_AttributeSet (void) :
GALGAS_attributeRange () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet GALGAS_uint_36__34_AttributeSet::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_uint_36__34_List::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet::GALGAS_uint_36__34_AttributeSet (const cPtr_uint_36__34_AttributeSet * inSourcePtr) :
GALGAS_attributeRange (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34_AttributeSet) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet GALGAS_uint_36__34_AttributeSet::constructor_new (const GALGAS_location & inAttribute_location,
                                                                                  const GALGAS_uint_36__34_List & inAttribute_valueList
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeSet result ;
  if (inAttribute_location.isValid () && inAttribute_valueList.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_36__34_AttributeSet (inAttribute_location, inAttribute_valueList COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List GALGAS_uint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_List result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_36__34_AttributeSet * p = (const cPtr_uint_36__34_AttributeSet *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34_AttributeSet) ;
    result = p->mAttribute_valueList ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List cPtr_uint_36__34_AttributeSet::getter_valueList (UNUSED_LOCATION_ARGS) const {
  return mAttribute_valueList ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @uint64AttributeSet class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_uint_36__34_AttributeSet::cPtr_uint_36__34_AttributeSet (const GALGAS_location & in_location,
                                                              const GALGAS_uint_36__34_List & in_valueList
                                                              COMMA_LOCATION_ARGS) :
cPtr_attributeRange (in_location COMMA_THERE),
mAttribute_valueList (in_valueList) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_uint_36__34_AttributeSet::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet ;
}

void cPtr_uint_36__34_AttributeSet::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@uint64AttributeSet:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_valueList.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_uint_36__34_AttributeSet::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_36__34_AttributeSet (mAttribute_location, mAttribute_valueList COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @uint64AttributeSet type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_AttributeSet ("uint64AttributeSet",
                                                 & kTypeDescriptor_GALGAS_attributeRange) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_uint_36__34_AttributeSet::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_uint_36__34_AttributeSet::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_AttributeSet (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_AttributeSet GALGAS_uint_36__34_AttributeSet::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_AttributeSet result ;
  const GALGAS_uint_36__34_AttributeSet * p = (const GALGAS_uint_36__34_AttributeSet *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34_AttributeSet *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64AttributeSet", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_autostart_5F_obj::objectCompare (const GALGAS_autostart_5F_obj & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_obj::GALGAS_autostart_5F_obj (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_obj::GALGAS_autostart_5F_obj (const cPtr_autostart_5F_obj * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_obj) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_autostart_5F_obj::getter_location (UNUSED_LOCATION_ARGS) const {
  GALGAS_location result ;
  if (NULL != mObjectPtr) {
    const cPtr_autostart_5F_obj * p = (const cPtr_autostart_5F_obj *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_autostart_5F_obj) ;
    result = p->mAttribute_location ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location cPtr_autostart_5F_obj::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @autostart_obj class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_autostart_5F_obj::cPtr_autostart_5F_obj (const GALGAS_location & in_location
                                              COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_location (in_location) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @autostart_obj type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_obj ("autostart_obj",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_autostart_5F_obj::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_obj ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_autostart_5F_obj::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_obj (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_obj GALGAS_autostart_5F_obj::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_obj result ;
  const GALGAS_autostart_5F_obj * p = (const GALGAS_autostart_5F_obj *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_autostart_5F_obj *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_obj", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_autostart_5F_false::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_autostart_5F_false * p = (const cPtr_autostart_5F_false *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_autostart_5F_false) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_autostart_5F_false::objectCompare (const GALGAS_autostart_5F_false & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false::GALGAS_autostart_5F_false (void) :
GALGAS_autostart_5F_obj () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::constructor_default (LOCATION_ARGS) {
  return GALGAS_autostart_5F_false::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false::GALGAS_autostart_5F_false (const cPtr_autostart_5F_false * inSourcePtr) :
GALGAS_autostart_5F_obj (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_false) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::constructor_new (const GALGAS_location & inAttribute_location
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_false result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_autostart_5F_false (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @autostart_false class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_autostart_5F_false::cPtr_autostart_5F_false (const GALGAS_location & in_location
                                                  COMMA_LOCATION_ARGS) :
cPtr_autostart_5F_obj (in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_autostart_5F_false::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_false ;
}

void cPtr_autostart_5F_false::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@autostart_false:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_autostart_5F_false::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_autostart_5F_false (mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @autostart_false type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_false ("autostart_false",
                                           & kTypeDescriptor_GALGAS_autostart_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_autostart_5F_false::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_false ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_autostart_5F_false::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_false (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_false GALGAS_autostart_5F_false::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_false result ;
  const GALGAS_autostart_5F_false * p = (const GALGAS_autostart_5F_false *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_autostart_5F_false *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_false", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_autostart_5F_void::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_autostart_5F_void * p = (const cPtr_autostart_5F_void *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_autostart_5F_void) ;
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_autostart_5F_void::objectCompare (const GALGAS_autostart_5F_void & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void::GALGAS_autostart_5F_void (void) :
GALGAS_autostart_5F_obj () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::constructor_default (LOCATION_ARGS) {
  return GALGAS_autostart_5F_void::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void::GALGAS_autostart_5F_void (const cPtr_autostart_5F_void * inSourcePtr) :
GALGAS_autostart_5F_obj (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_autostart_5F_void) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::constructor_new (const GALGAS_location & inAttribute_location
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_void result ;
  if (inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_autostart_5F_void (inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @autostart_void class                                       *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_autostart_5F_void::cPtr_autostart_5F_void (const GALGAS_location & in_location
                                                COMMA_LOCATION_ARGS) :
cPtr_autostart_5F_obj (in_location COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_autostart_5F_void::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_void ;
}

void cPtr_autostart_5F_void::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@autostart_void:" ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_autostart_5F_void::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_autostart_5F_void (mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @autostart_void type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_autostart_5F_void ("autostart_void",
                                          & kTypeDescriptor_GALGAS_autostart_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_autostart_5F_void::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_autostart_5F_void ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_autostart_5F_void::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_autostart_5F_void (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_autostart_5F_void GALGAS_autostart_5F_void::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_autostart_5F_void result ;
  const GALGAS_autostart_5F_void * p = (const GALGAS_autostart_5F_void *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_autostart_5F_void *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("autostart_void", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*



typeComparisonResult GALGAS_impType::objectCompare (const GALGAS_impType & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impType::GALGAS_impType (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impType::GALGAS_impType (const cPtr_impType * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList GALGAS_impType::getter_locations (UNUSED_LOCATION_ARGS) const {
  GALGAS_locationList result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_locations ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_locationList cPtr_impType::getter_locations (UNUSED_LOCATION_ARGS) const {
  return mAttribute_locations ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType GALGAS_impType::getter_type (UNUSED_LOCATION_ARGS) const {
  GALGAS_dataType result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_dataType cPtr_impType::getter_type (UNUSED_LOCATION_ARGS) const {
  return mAttribute_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_impType::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_impType::getter_name (UNUSED_LOCATION_ARGS) const {
  return mAttribute_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_impType::getter_multiple (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_multiple ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_impType::getter_multiple (UNUSED_LOCATION_ARGS) const {
  return mAttribute_multiple ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_impType::getter_descs (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (NULL != mObjectPtr) {
    const cPtr_impType * p = (const cPtr_impType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impType) ;
    result = p->mAttribute_descs ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cPtr_impType::getter_descs (UNUSED_LOCATION_ARGS) const {
  return mAttribute_descs ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                          Pointer class for @impType class                                           *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impType::cPtr_impType (const GALGAS_locationList & in_locations,
                            const GALGAS_dataType & in_type,
                            const GALGAS_lstring & in_name,
                            const GALGAS_bool & in_multiple,
                            const GALGAS_lstringlist & in_descs
                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_locations (in_locations),
mAttribute_type (in_type),
mAttribute_name (in_name),
mAttribute_multiple (in_multiple),
mAttribute_descs (in_descs) {
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    @impType type                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impType ("impType",
                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impType GALGAS_impType::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_impType result ;
  const GALGAS_impType * p = (const GALGAS_impType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_impAutoDefaultType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impAutoDefaultType * p = (const cPtr_impAutoDefaultType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
  if (kOperandEqual == result) {
    result = mAttribute_locations.objectCompare (p->mAttribute_locations) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_descs.objectCompare (p->mAttribute_descs) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_withAuto.objectCompare (p->mAttribute_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_defaultValue.objectCompare (p->mAttribute_defaultValue) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_impAutoDefaultType::objectCompare (const GALGAS_impAutoDefaultType & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impAutoDefaultType::GALGAS_impAutoDefaultType (void) :
GALGAS_impType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impAutoDefaultType::GALGAS_impAutoDefaultType (const cPtr_impAutoDefaultType * inSourcePtr) :
GALGAS_impType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impAutoDefaultType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impAutoDefaultType GALGAS_impAutoDefaultType::constructor_new (const GALGAS_locationList & inAttribute_locations,
                                                                      const GALGAS_dataType & inAttribute_type,
                                                                      const GALGAS_lstring & inAttribute_name,
                                                                      const GALGAS_bool & inAttribute_multiple,
                                                                      const GALGAS_lstringlist & inAttribute_descs,
                                                                      const GALGAS_bool & inAttribute_withAuto,
                                                                      const GALGAS_object_5F_t & inAttribute_defaultValue
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_impAutoDefaultType result ;
  if (inAttribute_locations.isValid () && inAttribute_type.isValid () && inAttribute_name.isValid () && inAttribute_multiple.isValid () && inAttribute_descs.isValid () && inAttribute_withAuto.isValid () && inAttribute_defaultValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_impAutoDefaultType (inAttribute_locations, inAttribute_type, inAttribute_name, inAttribute_multiple, inAttribute_descs, inAttribute_withAuto, inAttribute_defaultValue COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_impAutoDefaultType::getter_withAuto (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_impAutoDefaultType * p = (const cPtr_impAutoDefaultType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
    result = p->mAttribute_withAuto ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_impAutoDefaultType::getter_withAuto (UNUSED_LOCATION_ARGS) const {
  return mAttribute_withAuto ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_impAutoDefaultType::getter_defaultValue (UNUSED_LOCATION_ARGS) const {
  GALGAS_object_5F_t result ;
  if (NULL != mObjectPtr) {
    const cPtr_impAutoDefaultType * p = (const cPtr_impAutoDefaultType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impAutoDefaultType) ;
    result = p->mAttribute_defaultValue ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t cPtr_impAutoDefaultType::getter_defaultValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_defaultValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @impAutoDefaultType class                                     *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impAutoDefaultType::cPtr_impAutoDefaultType (const GALGAS_locationList & in_locations,
                                                  const GALGAS_dataType & in_type,
                                                  const GALGAS_lstring & in_name,
                                                  const GALGAS_bool & in_multiple,
                                                  const GALGAS_lstringlist & in_descs,
                                                  const GALGAS_bool & in_withAuto,
                                                  const GALGAS_object_5F_t & in_defaultValue
                                                  COMMA_LOCATION_ARGS) :
cPtr_impType (in_locations, in_type, in_name, in_multiple, in_descs COMMA_THERE),
mAttribute_withAuto (in_withAuto),
mAttribute_defaultValue (in_defaultValue) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_impAutoDefaultType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impAutoDefaultType ;
}

void cPtr_impAutoDefaultType::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@impAutoDefaultType:" ;
  mAttribute_locations.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_descs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_withAuto.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_defaultValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_impAutoDefaultType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_impAutoDefaultType (mAttribute_locations, mAttribute_type, mAttribute_name, mAttribute_multiple, mAttribute_descs, mAttribute_withAuto, mAttribute_defaultValue COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @impAutoDefaultType type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impAutoDefaultType ("impAutoDefaultType",
                                           & kTypeDescriptor_GALGAS_impType) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impAutoDefaultType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impAutoDefaultType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impAutoDefaultType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impAutoDefaultType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impAutoDefaultType GALGAS_impAutoDefaultType::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_impAutoDefaultType result ;
  const GALGAS_impAutoDefaultType * p = (const GALGAS_impAutoDefaultType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impAutoDefaultType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impAutoDefaultType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_impBoolType::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_impBoolType * p = (const cPtr_impBoolType *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_impBoolType) ;
  if (kOperandEqual == result) {
    result = mAttribute_locations.objectCompare (p->mAttribute_locations) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_type.objectCompare (p->mAttribute_type) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_name.objectCompare (p->mAttribute_name) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_multiple.objectCompare (p->mAttribute_multiple) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_descs.objectCompare (p->mAttribute_descs) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_withAuto.objectCompare (p->mAttribute_withAuto) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_defaultValue.objectCompare (p->mAttribute_defaultValue) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_trueSubAttributes.objectCompare (p->mAttribute_trueSubAttributes) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_falseSubAttributes.objectCompare (p->mAttribute_falseSubAttributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_impBoolType::objectCompare (const GALGAS_impBoolType & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impBoolType::GALGAS_impBoolType (void) :
GALGAS_impAutoDefaultType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impBoolType::GALGAS_impBoolType (const cPtr_impBoolType * inSourcePtr) :
GALGAS_impAutoDefaultType (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_impBoolType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impBoolType GALGAS_impBoolType::constructor_new (const GALGAS_locationList & inAttribute_locations,
                                                        const GALGAS_dataType & inAttribute_type,
                                                        const GALGAS_lstring & inAttribute_name,
                                                        const GALGAS_bool & inAttribute_multiple,
                                                        const GALGAS_lstringlist & inAttribute_descs,
                                                        const GALGAS_bool & inAttribute_withAuto,
                                                        const GALGAS_object_5F_t & inAttribute_defaultValue,
                                                        const GALGAS_implementationObjectMap & inAttribute_trueSubAttributes,
                                                        const GALGAS_implementationObjectMap & inAttribute_falseSubAttributes
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_impBoolType result ;
  if (inAttribute_locations.isValid () && inAttribute_type.isValid () && inAttribute_name.isValid () && inAttribute_multiple.isValid () && inAttribute_descs.isValid () && inAttribute_withAuto.isValid () && inAttribute_defaultValue.isValid () && inAttribute_trueSubAttributes.isValid () && inAttribute_falseSubAttributes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_impBoolType (inAttribute_locations, inAttribute_type, inAttribute_name, inAttribute_multiple, inAttribute_descs, inAttribute_withAuto, inAttribute_defaultValue, inAttribute_trueSubAttributes, inAttribute_falseSubAttributes COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_impBoolType::getter_trueSubAttributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_implementationObjectMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_impBoolType * p = (const cPtr_impBoolType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impBoolType) ;
    result = p->mAttribute_trueSubAttributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap cPtr_impBoolType::getter_trueSubAttributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_trueSubAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_impBoolType::getter_falseSubAttributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_implementationObjectMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_impBoolType * p = (const cPtr_impBoolType *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_impBoolType) ;
    result = p->mAttribute_falseSubAttributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap cPtr_impBoolType::getter_falseSubAttributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_falseSubAttributes ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @impBoolType class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_impBoolType::cPtr_impBoolType (const GALGAS_locationList & in_locations,
                                    const GALGAS_dataType & in_type,
                                    const GALGAS_lstring & in_name,
                                    const GALGAS_bool & in_multiple,
                                    const GALGAS_lstringlist & in_descs,
                                    const GALGAS_bool & in_withAuto,
                                    const GALGAS_object_5F_t & in_defaultValue,
                                    const GALGAS_implementationObjectMap & in_trueSubAttributes,
                                    const GALGAS_implementationObjectMap & in_falseSubAttributes
                                    COMMA_LOCATION_ARGS) :
cPtr_impAutoDefaultType (in_locations, in_type, in_name, in_multiple, in_descs, in_withAuto, in_defaultValue COMMA_THERE),
mAttribute_trueSubAttributes (in_trueSubAttributes),
mAttribute_falseSubAttributes (in_falseSubAttributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_impBoolType::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impBoolType ;
}

void cPtr_impBoolType::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@impBoolType:" ;
  mAttribute_locations.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_multiple.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_descs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_withAuto.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_defaultValue.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_trueSubAttributes.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_falseSubAttributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_impBoolType::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_impBoolType (mAttribute_locations, mAttribute_type, mAttribute_name, mAttribute_multiple, mAttribute_descs, mAttribute_withAuto, mAttribute_defaultValue, mAttribute_trueSubAttributes, mAttribute_falseSubAttributes COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @impBoolType type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_impBoolType ("impBoolType",
                                    & kTypeDescriptor_GALGAS_impAutoDefaultType) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_impBoolType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_impBoolType ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_impBoolType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_impBoolType (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impBoolType GALGAS_impBoolType::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_impBoolType result ;
  const GALGAS_impBoolType * p = (const GALGAS_impBoolType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_impBoolType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("impBoolType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

