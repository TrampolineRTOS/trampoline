#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-4.h"


//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                                                 *
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_uint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_uint_36__34__5F_class * p = (const cPtr_uint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_uint_36__34__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_uint_36__34__5F_class::objectCompare (const GALGAS_uint_36__34__5F_class & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class::GALGAS_uint_36__34__5F_class (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class GALGAS_uint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_uint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                        GALGAS_location::constructor_nowhere (HERE),
                                                        GALGAS_uint_36__34_::constructor_default (HERE)
                                                        COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class::GALGAS_uint_36__34__5F_class (const cPtr_uint_36__34__5F_class * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_uint_36__34__5F_class) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class GALGAS_uint_36__34__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                            const GALGAS_location & inAttribute_location,
                                                                            const GALGAS_uint_36__34_ & inAttribute_value
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_uint_36__34__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_uint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint_36__34_ result ;
  if (NULL != mObjectPtr) {
    const cPtr_uint_36__34__5F_class * p = (const cPtr_uint_36__34__5F_class *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_uint_36__34__5F_class) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ cPtr_uint_36__34__5F_class::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                        Pointer class for @uint64_class class                                        *
//----------------------------------------------------------------------------------------------------------------------

cPtr_uint_36__34__5F_class::cPtr_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                        const GALGAS_location & in_location,
                                                        const GALGAS_uint_36__34_ & in_value
                                                        COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE),
mAttribute_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_uint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34__5F_class ;
}

void cPtr_uint_36__34__5F_class::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@uint64_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_uint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_uint_36__34__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                 @uint64_class type                                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34__5F_class ("uint64_class",
                                              & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34__5F_class GALGAS_uint_36__34__5F_class::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34__5F_class result ;
  const GALGAS_uint_36__34__5F_class * p = (const GALGAS_uint_36__34__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                                                 *
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void_5F_uint_36__34__5F_class::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void_5F_uint_36__34__5F_class * p = (const cPtr_void_5F_uint_36__34__5F_class *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void_5F_uint_36__34__5F_class) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (p->mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_void_5F_uint_36__34__5F_class::objectCompare (const GALGAS_void_5F_uint_36__34__5F_class & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class::GALGAS_void_5F_uint_36__34__5F_class (void) :
GALGAS_uint_36__34__5F_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class GALGAS_void_5F_uint_36__34__5F_class::constructor_default (LOCATION_ARGS) {
  return GALGAS_void_5F_uint_36__34__5F_class::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                                GALGAS_location::constructor_nowhere (HERE),
                                                                GALGAS_uint_36__34_::constructor_default (HERE)
                                                                COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class::GALGAS_void_5F_uint_36__34__5F_class (const cPtr_void_5F_uint_36__34__5F_class * inSourcePtr) :
GALGAS_uint_36__34__5F_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void_5F_uint_36__34__5F_class) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class GALGAS_void_5F_uint_36__34__5F_class::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                                                                            const GALGAS_location & inAttribute_location,
                                                                                            const GALGAS_uint_36__34_ & inAttribute_value
                                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_36__34__5F_class result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void_5F_uint_36__34__5F_class (inAttribute_oil_5F_desc, inAttribute_location, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                     Pointer class for @void_uint64_class class                                      *
//----------------------------------------------------------------------------------------------------------------------

cPtr_void_5F_uint_36__34__5F_class::cPtr_void_5F_uint_36__34__5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                                                        const GALGAS_location & in_location,
                                                                        const GALGAS_uint_36__34_ & in_value
                                                                        COMMA_LOCATION_ARGS) :
cPtr_uint_36__34__5F_class (in_oil_5F_desc, in_location, in_value COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void_5F_uint_36__34__5F_class::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ;
}

void cPtr_void_5F_uint_36__34__5F_class::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "[@void_uint64_class:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void_5F_uint_36__34__5F_class::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void_5F_uint_36__34__5F_class (mAttribute_oil_5F_desc, mAttribute_location, mAttribute_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               @void_uint64_class type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ("void_uint64_class",
                                                      & kTypeDescriptor_GALGAS_uint_36__34__5F_class) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void_5F_uint_36__34__5F_class::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void_5F_uint_36__34__5F_class ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void_5F_uint_36__34__5F_class::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void_5F_uint_36__34__5F_class (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void_5F_uint_36__34__5F_class GALGAS_void_5F_uint_36__34__5F_class::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_void_5F_uint_36__34__5F_class result ;
  const GALGAS_void_5F_uint_36__34__5F_class * p = (const GALGAS_void_5F_uint_36__34__5F_class *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void_5F_uint_36__34__5F_class *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void_uint64_class", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                                                 *
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_void::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_void * p = (const cPtr_void *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_void) ;
  if (kOperandEqual == result) {
    result = mAttribute_oil_5F_desc.objectCompare (p->mAttribute_oil_5F_desc) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_location.objectCompare (p->mAttribute_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_void::objectCompare (const GALGAS_void & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void::GALGAS_void (void) :
GALGAS_object_5F_t () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void GALGAS_void::constructor_default (LOCATION_ARGS) {
  return GALGAS_void::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_location::constructor_nowhere (HERE)
                                       COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void::GALGAS_void (const cPtr_void * inSourcePtr) :
GALGAS_object_5F_t (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_void) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void GALGAS_void::constructor_new (const GALGAS_lstring & inAttribute_oil_5F_desc,
                                          const GALGAS_location & inAttribute_location
                                          COMMA_LOCATION_ARGS) {
  GALGAS_void result ;
  if (inAttribute_oil_5F_desc.isValid () && inAttribute_location.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_void (inAttribute_oil_5F_desc, inAttribute_location COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                            Pointer class for @void class                                            *
//----------------------------------------------------------------------------------------------------------------------

cPtr_void::cPtr_void (const GALGAS_lstring & in_oil_5F_desc,
                      const GALGAS_location & in_location
                      COMMA_LOCATION_ARGS) :
cPtr_object_5F_t (in_oil_5F_desc, in_location COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_void::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void ;
}

void cPtr_void::description (C_String & ioString,
                             const int32_t inIndentation) const {
  ioString << "[@void:" ;
  mAttribute_oil_5F_desc.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mAttribute_location.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_void::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_void (mAttribute_oil_5F_desc, mAttribute_location COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                     @void type                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_void ("void",
                             & kTypeDescriptor_GALGAS_object_5F_t) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_void::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_void ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_void::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_void (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_void GALGAS_void::extractObject (const GALGAS_object & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_void result ;
  const GALGAS_void * p = (const GALGAS_void *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_void *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("void", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                                                 *
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_oil_5F_obj::objectCompare (const GALGAS_oil_5F_obj & inOperand) const {
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

//----------------------------------------------------------------------------------------------------------------------

GALGAS_oil_5F_obj::GALGAS_oil_5F_obj (void) :
AC_GALGAS_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_oil_5F_obj::GALGAS_oil_5F_obj (const cPtr_oil_5F_obj * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_oil_5F_obj) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_oil_5F_obj::getter_desc (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_oil_5F_obj * p = (const cPtr_oil_5F_obj *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_oil_5F_obj) ;
    result = p->mAttribute_desc ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_oil_5F_obj::getter_desc (UNUSED_LOCATION_ARGS) const {
  return mAttribute_desc ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                          Pointer class for @oil_obj class                                           *
//----------------------------------------------------------------------------------------------------------------------

cPtr_oil_5F_obj::cPtr_oil_5F_obj (const GALGAS_lstring & in_desc
                                  COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mAttribute_desc (in_desc) {
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @oil_obj type                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_oil_5F_obj ("oil_obj",
                                   NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_oil_5F_obj::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_oil_5F_obj ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_oil_5F_obj::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_oil_5F_obj (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_oil_5F_obj GALGAS_oil_5F_obj::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_oil_5F_obj result ;
  const GALGAS_oil_5F_obj * p = (const GALGAS_oil_5F_obj *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_oil_5F_obj *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("oil_obj", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

#include "project_header.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "utilities/F_DisplayException.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/F_verbose_output.h"
#include "galgas2/cLexiqueIntrospection.h"

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                      print_tool_help_message                                                                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//----------------------------------------------------------------------------------------------------------------------

static const char * kSourceFileExtensions [] = {
  "oil",
  "OIL",
  "goilTemplate",
  NULL
} ;    

//----------------------------------------------------------------------------------------------------------------------

static const char * kSourceFileHelpMessages [] = {
  "an '.oil' source file",
  "an '.OIL' source file",
  "a Goil template file",
  NULL
} ;    

//----------------------------------------------------------------------------------------------------------------------

const char * projectVersionString (void) {
  return "2.1.28" ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                  Routine 'before'                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   Routine 'after'                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               Routine 'programRule_0'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 33)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 34)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               Routine 'programRule_1'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__31_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 38)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 39)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               Routine 'programRule_2'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__32_ (const GALGAS_lstring /* constinArgument_inSourceFile */,
                                         C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                      M A I N    F O R    L I B P M                                                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <C_String> sourceFilesArray ;
  F_Analyze_CLI_Options (inArgc, inArgv,
                         sourceFilesArray,
                         kSourceFileExtensions,
                         kSourceFileHelpMessages,
                         print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  C_String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    co << executionModeOptionErrorMessage ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    C_Compiler * commonLexique = NULL ;
    macroMyNew (commonLexique, C_Compiler (NULL, "", "" COMMA_HERE)) ;
    try{
      routine_before (commonLexique COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonLexique) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GALGAS_string sfp = GALGAS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GALGAS_location location = commonLexique->here () ;
        const GALGAS_lstring sourceFilePath (sfp, location) ;
        int r = 0 ;
        if (fileExtension == "oil") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__30_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "OIL") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__31_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "goilTemplate") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__32_ (sourceFilePath, commonLexique COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonLexique->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
      }
    //--- Error or warnings ?
      if (totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (totalWarningCount () > 0) {
        if (gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      routine_after (commonLexique COMMA_HERE) ;
    //--- Display error and warnings count
      if (verboseOptionOn || (totalWarningCount () > 0) || (totalErrorCount () > 0)) {
        C_String message ;
        if (totalWarningCount () == 0) {
          message << "No warning" ;
        }else if (totalWarningCount () == 1) {
          message << "1 warning" ;
        }else{
          message << cStringWithSigned (totalWarningCount ()) << " warnings" ;
        }
        message << ", " ;
        if (totalErrorCount () == 0) {
          message << "no error" ;
        }else if (totalErrorCount () == 1) {
          message << "1 error" ;
        }else{
          message << cStringWithSigned (totalErrorCount ()) << " errors" ;
        }
        message << ".\n" ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std:: exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      printf ("**** Unknow exception ****\n") ;
      throw ;
    }
    macroDetachSharedObject (commonLexique) ;
  }
  return returnCode ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                  Extension Getter '@Ttype messageGoilTemplateType'                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_messageGoilTemplateType (const GALGAS_Ttype & inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_Ttype temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_Ttype::kNotBuilt:
    break ;
  case GALGAS_Ttype::kEnum_boolType:
    {
      result_result = GALGAS_string ("bool") ;
    }
    break ;
  case GALGAS_Ttype::kEnum_intType:
    {
      result_result = GALGAS_string ("int") ;
    }
    break ;
  case GALGAS_Ttype::kEnum_floatType:
    {
      result_result = GALGAS_string ("float") ;
    }
    break ;
  case GALGAS_Ttype::kEnum_stringType:
    {
      result_result = GALGAS_string ("string") ;
    }
    break ;
  case GALGAS_Ttype::kEnum_listType:
    {
      result_result = GALGAS_string ("list") ;
    }
    break ;
  case GALGAS_Ttype::kEnum_mapType:
    {
      result_result = GALGAS_string ("map") ;
    }
    break ;
  case GALGAS_Ttype::kEnum_structType:
    {
      result_result = GALGAS_string ("struct") ;
    }
    break ;
  case GALGAS_Ttype::kEnum_enumType:
    {
      result_result = GALGAS_string ("enum") ;
    }
    break ;
  case GALGAS_Ttype::kEnum_functionType:
    {
      result_result = GALGAS_string ("function") ;
    }
    break ;
  case GALGAS_Ttype::kEnum_unconstructedType:
    {
      result_result = GALGAS_string ("unconstructed") ;
    }
    break ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                        Extension Getter '@dataType oilType'                                         *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_oilType (const GALGAS_dataType & inObject,
                                       C_Compiler * /* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_dataType temp_0 = inObject ;
  switch (temp_0.enumValue ()) {
  case GALGAS_dataType::kNotBuilt:
    break ;
  case GALGAS_dataType::kEnum_void:
    {
      result_result = GALGAS_string ("VOID") ;
    }
    break ;
  case GALGAS_dataType::kEnum_uint_33__32_Number:
    {
      result_result = GALGAS_string ("UINT32") ;
    }
    break ;
  case GALGAS_dataType::kEnum_sint_33__32_Number:
    {
      result_result = GALGAS_string ("INT32") ;
    }
    break ;
  case GALGAS_dataType::kEnum_uint_36__34_Number:
    {
      result_result = GALGAS_string ("UINT64") ;
    }
    break ;
  case GALGAS_dataType::kEnum_sint_36__34_Number:
    {
      result_result = GALGAS_string ("INT64") ;
    }
    break ;
  case GALGAS_dataType::kEnum_floatNumber:
    {
      result_result = GALGAS_string ("FLOAT") ;
    }
    break ;
  case GALGAS_dataType::kEnum_string:
    {
      result_result = GALGAS_string ("STRING") ;
    }
    break ;
  case GALGAS_dataType::kEnum_enumeration:
    {
      result_result = GALGAS_string ("ENUM") ;
    }
    break ;
  case GALGAS_dataType::kEnum_boolean:
    {
      result_result = GALGAS_string ("BOOLEAN") ;
    }
    break ;
  case GALGAS_dataType::kEnum_identifier:
    {
      result_result = GALGAS_string ("IDENTIFIER") ;
    }
    break ;
  case GALGAS_dataType::kEnum_objectType:
    {
      result_result = GALGAS_string ("OBJECT_TYPE") ;
    }
    break ;
  case GALGAS_dataType::kEnum_structType:
    {
      result_result = GALGAS_string ("STRUCT") ;
    }
    break ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                 Abstract extension method '@attributeRange enclose'                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_attributeRange_enclose> gExtensionMethodTable_attributeRange_enclose ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_enclose (const int32_t inClassIndex,
                                   extensionMethodSignature_attributeRange_enclose inMethod) {
  gExtensionMethodTable_attributeRange_enclose.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_attributeRange_enclose (void) {
  gExtensionMethodTable_attributeRange_enclose.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_attributeRange_enclose (NULL,
                                                   freeExtensionMethod_attributeRange_enclose) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_enclose (const cPtr_attributeRange * inObject,
                                  GALGAS_bool & out_isWithin,
                                  const GALGAS_attributeRange constin_value,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_isWithin.drop () ;
//--- Find method
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_attributeRange) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_attributeRange_enclose f = NULL ;
    if (classIndex < gExtensionMethodTable_attributeRange_enclose.count ()) {
      f = gExtensionMethodTable_attributeRange_enclose (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_attributeRange_enclose.count ()) {
           f = gExtensionMethodTable_attributeRange_enclose (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_attributeRange_enclose.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, out_isWithin, constin_value, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                    Extension Getter '@enumValues mergeWithEnum'                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues extensionGetter_mergeWithEnum (const GALGAS_enumValues & inObject,
                                                 const GALGAS_enumValues & constinArgument_enumToMerge,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_enumValues result_mergedEnum ; // Returned variable
  result_mergedEnum = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 696)) ;
  const GALGAS_enumValues temp_0 = inObject ;
  cEnumerator_enumValues enumerator_19324 (temp_0, kEnumeration_up) ;
  while (enumerator_19324.hasCurrentObject ()) {
    GALGAS_implementationObjectMap var_attributes_19367 = enumerator_19324.current_subAttributes (HERE) ;
    const enumGalgasBool test_1 = constinArgument_enumToMerge.getter_hasKey (enumerator_19324.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 699)) COMMA_SOURCE_FILE ("implementation_types.galgas", 699)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_implementationObjectMap var_attributesToMerge_19504 ;
      constinArgument_enumToMerge.method_get (enumerator_19324.current_lkey (HERE), var_attributesToMerge_19504, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 700)) ;
      var_attributes_19367 = extensionGetter_mergeImplementationObjectAttributesWith (enumerator_19324.current_subAttributes (HERE), var_attributesToMerge_19504, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 701)) ;
    }
    {
    result_mergedEnum.setter_put (enumerator_19324.current_lkey (HERE), var_attributes_19367, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 703)) ;
    }
    enumerator_19324.gotoNextObject () ;
  }
  cEnumerator_enumValues enumerator_19678 (constinArgument_enumToMerge, kEnumeration_up) ;
  while (enumerator_19678.hasCurrentObject ()) {
    const GALGAS_enumValues temp_2 = inObject ;
    const enumGalgasBool test_3 = temp_2.getter_hasKey (enumerator_19678.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 706)) COMMA_SOURCE_FILE ("implementation_types.galgas", 706)).operator_not (SOURCE_FILE ("implementation_types.galgas", 706)).boolEnum () ;
    if (kBoolTrue == test_3) {
      {
      result_mergedEnum.setter_put (enumerator_19678.current_lkey (HERE), enumerator_19678.current_subAttributes (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 707)) ;
      }
    }
    enumerator_19678.gotoNextObject () ;
  }
//---
  return result_mergedEnum ;
}




//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                      Extension getter '@implementation hasKey'                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <enterExtensionGetter_implementation_hasKey> gExtensionGetterTable_implementation_hasKey ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionGetter_hasKey (const int32_t inClassIndex,
                                  enterExtensionGetter_implementation_hasKey inGetter) {
  gExtensionGetterTable_implementation_hasKey.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasKey (const cPtr_implementation * inObject,
                                        const GALGAS_string & in_key,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_implementation_hasKey f = NULL ;
    if (classIndex < gExtensionGetterTable_implementation_hasKey.count ()) {
      f = gExtensionGetterTable_implementation_hasKey (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_implementation_hasKey.count ()) {
           f = gExtensionGetterTable_implementation_hasKey (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_implementation_hasKey.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_key, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_bool extensionGetter_implementation_hasKey (const cPtr_implementation * inObject,
                                                          const GALGAS_string & constinArgument_key,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  result_result = object->mAttribute_imp.getter_hasKey (constinArgument_key COMMA_SOURCE_FILE ("implementation_types.galgas", 765)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_implementation_hasKey (void) {
  enterExtensionGetter_hasKey (kTypeDescriptor_GALGAS_implementation.mSlotID,
                               extensionGetter_implementation_hasKey) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionGetter_implementation_hasKey (void) {
  gExtensionGetterTable_implementation_hasKey.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_implementation_hasKey (defineExtensionGetter_implementation_hasKey,
                                                  freeExtensionGetter_implementation_hasKey) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                     Extension getter '@implementation hasLKey'                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <enterExtensionGetter_implementation_hasLKey> gExtensionGetterTable_implementation_hasLKey ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionGetter_hasLKey (const int32_t inClassIndex,
                                   enterExtensionGetter_implementation_hasLKey inGetter) {
  gExtensionGetterTable_implementation_hasLKey.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasLKey (const cPtr_implementation * inObject,
                                         const GALGAS_lstring & in_key,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_implementation_hasLKey f = NULL ;
    if (classIndex < gExtensionGetterTable_implementation_hasLKey.count ()) {
      f = gExtensionGetterTable_implementation_hasLKey (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_implementation_hasLKey.count ()) {
           f = gExtensionGetterTable_implementation_hasLKey (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_implementation_hasLKey.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_key, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_bool extensionGetter_implementation_hasLKey (const cPtr_implementation * inObject,
                                                           const GALGAS_lstring & constinArgument_key,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  result_result = object->mAttribute_imp.getter_hasKey (constinArgument_key.getter_string (SOURCE_FILE ("implementation_types.galgas", 771)) COMMA_SOURCE_FILE ("implementation_types.galgas", 771)) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_implementation_hasLKey (void) {
  enterExtensionGetter_hasLKey (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                extensionGetter_implementation_hasLKey) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionGetter_implementation_hasLKey (void) {
  gExtensionGetterTable_implementation_hasLKey.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_implementation_hasLKey (defineExtensionGetter_implementation_hasLKey,
                                                   freeExtensionGetter_implementation_hasLKey) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                    Extension getter '@implementation impObject'                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <enterExtensionGetter_implementation_impObject> gExtensionGetterTable_implementation_impObject ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionGetter_impObject (const int32_t inClassIndex,
                                     enterExtensionGetter_implementation_impObject inGetter) {
  gExtensionGetterTable_implementation_impObject.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObject callExtensionGetter_impObject (const cPtr_implementation * inObject,
                                                           const GALGAS_string & in_objKind,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_implementation_impObject f = NULL ;
    if (classIndex < gExtensionGetterTable_implementation_impObject.count ()) {
      f = gExtensionGetterTable_implementation_impObject (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_implementation_impObject.count ()) {
           f = gExtensionGetterTable_implementation_impObject (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_implementation_impObject.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_objKind, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_implementationObject extensionGetter_implementation_impObject (const cPtr_implementation * inObject,
                                                                             const GALGAS_string & constinArgument_objKind,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObject result_obj ; // Returned variable
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  result_obj = GALGAS_implementationObject::constructor_new (GALGAS_lbool::constructor_new (GALGAS_bool (false), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 777))  COMMA_SOURCE_FILE ("implementation_types.galgas", 777)), GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 777))  COMMA_SOURCE_FILE ("implementation_types.galgas", 777)) ;
  const enumGalgasBool test_0 = object->mAttribute_imp.getter_hasKey (constinArgument_objKind COMMA_SOURCE_FILE ("implementation_types.galgas", 778)).boolEnum () ;
  if (kBoolTrue == test_0) {
    object->mAttribute_imp.method_get (function_lstringWith (constinArgument_objKind, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 779)), result_obj, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 779)) ;
  }
//---
  return result_obj ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_implementation_impObject (void) {
  enterExtensionGetter_impObject (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                  extensionGetter_implementation_impObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionGetter_implementation_impObject (void) {
  gExtensionGetterTable_implementation_impObject.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_implementation_impObject (defineExtensionGetter_implementation_impObject,
                                                     freeExtensionGetter_implementation_impObject) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                 Extension method '@implementation checkTypeForKind'                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_implementation_checkTypeForKind> gExtensionMethodTable_implementation_checkTypeForKind ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_checkTypeForKind (const int32_t inClassIndex,
                                            extensionMethodSignature_implementation_checkTypeForKind inMethod) {
  gExtensionMethodTable_implementation_checkTypeForKind.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_checkTypeForKind (const cPtr_implementation * inObject,
                                           const GALGAS_string constin_objKind,
                                           const GALGAS_string constin_attributeName,
                                           const GALGAS_dataType constin_expectedType,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_implementation_checkTypeForKind f = NULL ;
    if (classIndex < gExtensionMethodTable_implementation_checkTypeForKind.count ()) {
      f = gExtensionMethodTable_implementation_checkTypeForKind (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_implementation_checkTypeForKind.count ()) {
           f = gExtensionMethodTable_implementation_checkTypeForKind (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_implementation_checkTypeForKind.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_objKind, constin_attributeName, constin_expectedType, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_implementation_checkTypeForKind (const cPtr_implementation * inObject,
                                                             const GALGAS_string constinArgument_objKind,
                                                             const GALGAS_string constinArgument_attributeName,
                                                             const GALGAS_dataType constinArgument_expectedType,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  const GALGAS_implementation temp_0 = object ;
  GALGAS_implementationObject var_obj_21646 = callExtensionGetter_impObject ((const cPtr_implementation *) temp_0.ptr (), constinArgument_objKind, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 787)) ;
  {
  routine_checkTypeForAttribute (var_obj_21646.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 788)), constinArgument_attributeName, constinArgument_expectedType, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 788)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_implementation_checkTypeForKind (void) {
  enterExtensionMethod_checkTypeForKind (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                         extensionMethod_implementation_checkTypeForKind) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_implementation_checkTypeForKind (void) {
  gExtensionMethodTable_implementation_checkTypeForKind.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_implementation_checkTypeForKind (defineExtensionMethod_implementation_checkTypeForKind,
                                                            freeExtensionMethod_implementation_checkTypeForKind) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                              Extension method '@implementation checkObjectReferences'                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_implementation_checkObjectReferences> gExtensionMethodTable_implementation_checkObjectReferences ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_checkObjectReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_implementation_checkObjectReferences inMethod) {
  gExtensionMethodTable_implementation_checkObjectReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_checkObjectReferences (const cPtr_implementation * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_implementation_checkObjectReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_implementation_checkObjectReferences.count ()) {
      f = gExtensionMethodTable_implementation_checkObjectReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_implementation_checkObjectReferences.count ()) {
           f = gExtensionMethodTable_implementation_checkObjectReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_implementation_checkObjectReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_implementation_checkObjectReferences (const cPtr_implementation * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  cEnumerator_implementationMap enumerator_21815 (object->mAttribute_imp, kEnumeration_up) ;
  while (enumerator_21815.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_21850 (enumerator_21815.current_obj (HERE).getter_attributes (SOURCE_FILE ("implementation_types.galgas", 793)), kEnumeration_up) ;
    while (enumerator_21850.hasCurrentObject ()) {
      const GALGAS_implementation temp_0 = object ;
      callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_21850.current_type (HERE).ptr (), temp_0, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 794)) ;
      enumerator_21850.gotoNextObject () ;
    }
    enumerator_21815.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_implementation_checkObjectReferences (void) {
  enterExtensionMethod_checkObjectReferences (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                              extensionMethod_implementation_checkObjectReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_implementation_checkObjectReferences (void) {
  gExtensionMethodTable_implementation_checkObjectReferences.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_implementation_checkObjectReferences (defineExtensionMethod_implementation_checkObjectReferences,
                                                                 freeExtensionMethod_implementation_checkObjectReferences) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                 Extension Getter '@implementationObjectMap mergeImplementationObjectAttributesWith'                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap extensionGetter_mergeImplementationObjectAttributesWith (const GALGAS_implementationObjectMap & inObject,
                                                                                        const GALGAS_implementationObjectMap & constinArgument_attributesToMerge,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_mergedAttributes ; // Returned variable
  result_mergedAttributes = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 1015)) ;
  const GALGAS_implementationObjectMap temp_0 = inObject ;
  cEnumerator_implementationObjectMap enumerator_29424 (temp_0, kEnumeration_up) ;
  while (enumerator_29424.hasCurrentObject ()) {
    GALGAS_impType var_merged_29447 = enumerator_29424.current_type (HERE) ;
    const enumGalgasBool test_1 = constinArgument_attributesToMerge.getter_hasKey (enumerator_29424.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1018)) COMMA_SOURCE_FILE ("implementation_types.galgas", 1018)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_typeToMerge_29565 ;
      constinArgument_attributesToMerge.method_get (enumerator_29424.current_lkey (HERE), var_typeToMerge_29565, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1019)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, enumerator_29424.current_type (HERE).getter_dynamicType (SOURCE_FILE ("implementation_types.galgas", 1020)).objectCompare (var_typeToMerge_29565.getter_dynamicType (SOURCE_FILE ("implementation_types.galgas", 1020)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_merged_29447 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_29424.current_type (HERE).ptr (), var_typeToMerge_29565, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1021)) ;
      }else if (kBoolFalse == test_2) {
        GALGAS_location location_3 (enumerator_29424.current_lkey (HERE).getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_3, GALGAS_string ("Redefined type")  COMMA_SOURCE_FILE ("implementation_types.galgas", 1024)) ;
      }
    }
    {
    result_mergedAttributes.setter_put (enumerator_29424.current_lkey (HERE), var_merged_29447, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1027)) ;
    }
    enumerator_29424.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_29854 (constinArgument_attributesToMerge, kEnumeration_up) ;
  while (enumerator_29854.hasCurrentObject ()) {
    const GALGAS_implementationObjectMap temp_4 = inObject ;
    const enumGalgasBool test_5 = temp_4.getter_hasKey (enumerator_29854.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 1030)) COMMA_SOURCE_FILE ("implementation_types.galgas", 1030)).operator_not (SOURCE_FILE ("implementation_types.galgas", 1030)).boolEnum () ;
    if (kBoolTrue == test_5) {
      {
      result_mergedAttributes.setter_put (enumerator_29854.current_lkey (HERE), enumerator_29854.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1031)) ;
      }
    }
    enumerator_29854.gotoNextObject () ;
  }
//---
  return result_mergedAttributes ;
}




//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                    Extension getter '@objectAttributes fieldMap'                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <enterExtensionGetter_objectAttributes_fieldMap> gExtensionGetterTable_objectAttributes_fieldMap ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionGetter_fieldMap (const int32_t inClassIndex,
                                    enterExtensionGetter_objectAttributes_fieldMap inGetter) {
  gExtensionGetterTable_objectAttributes_fieldMap.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMap callExtensionGetter_fieldMap (const cPtr_objectAttributes * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_TfieldMap result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_objectAttributes) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_objectAttributes_fieldMap f = NULL ;
    if (classIndex < gExtensionGetterTable_objectAttributes_fieldMap.count ()) {
      f = gExtensionGetterTable_objectAttributes_fieldMap (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_objectAttributes_fieldMap.count ()) {
           f = gExtensionGetterTable_objectAttributes_fieldMap (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_objectAttributes_fieldMap.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_TfieldMap extensionGetter_objectAttributes_fieldMap (const cPtr_objectAttributes * inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TfieldMap result_result ; // Returned variable
  const cPtr_objectAttributes * object = inObject ;
  macroValidSharedObject (object, cPtr_objectAttributes) ;
  result_result = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 128)) ;
  cEnumerator_identifierMap enumerator_4377 (object->mAttribute_objectParams, kEnumeration_up) ;
  while (enumerator_4377.hasCurrentObject ()) {
    callExtensionMethod_set ((const cPtr_object_5F_t *) enumerator_4377.current_value (HERE).ptr (), enumerator_4377.current_lkey (HERE), result_result, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 130)) ;
    enumerator_4377.gotoNextObject () ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_objectAttributes_fieldMap (void) {
  enterExtensionGetter_fieldMap (kTypeDescriptor_GALGAS_objectAttributes.mSlotID,
                                 extensionGetter_objectAttributes_fieldMap) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionGetter_objectAttributes_fieldMap (void) {
  gExtensionGetterTable_objectAttributes_fieldMap.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_objectAttributes_fieldMap (defineExtensionGetter_objectAttributes_fieldMap,
                                                      freeExtensionGetter_objectAttributes_fieldMap) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                         Extension Getter '@string trimLeft'                                         *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_trimLeft (const GALGAS_string & inObject,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_string temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, temp_0.getter_leftSubString (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("systemConfig.galgas", 137)).objectCompare (GALGAS_string (" "))).boolEnum () ;
  if (kBoolTrue == test_1) {
    const GALGAS_string temp_2 = inObject ;
    const GALGAS_string temp_3 = inObject ;
    result_result = extensionGetter_trimLeft (temp_2.getter_rightSubString (temp_3.getter_length (SOURCE_FILE ("systemConfig.galgas", 138)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 138)) COMMA_SOURCE_FILE ("systemConfig.galgas", 138)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 138)) ;
  }else if (kBoolFalse == test_1) {
    const GALGAS_string temp_4 = inObject ;
    result_result = temp_4 ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                        Extension Getter '@string trimRight'                                         *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_trimRight (const GALGAS_string & inObject,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const GALGAS_string temp_0 = inObject ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, temp_0.getter_rightSubString (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("systemConfig.galgas", 147)).objectCompare (GALGAS_string (" "))).boolEnum () ;
  if (kBoolTrue == test_1) {
    const GALGAS_string temp_2 = inObject ;
    const GALGAS_string temp_3 = inObject ;
    result_result = extensionGetter_trimRight (temp_2.getter_leftSubString (temp_3.getter_length (SOURCE_FILE ("systemConfig.galgas", 148)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 148)) COMMA_SOURCE_FILE ("systemConfig.galgas", 148)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 148)) ;
  }else if (kBoolFalse == test_1) {
    const GALGAS_string temp_4 = inObject ;
    result_result = temp_4 ;
  }
//---
  return result_result ;
}




//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Extension method '@implementation verifyApplication'                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_implementation_verifyApplication> gExtensionMethodTable_implementation_verifyApplication ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_verifyApplication (const int32_t inClassIndex,
                                             extensionMethodSignature_implementation_verifyApplication inMethod) {
  gExtensionMethodTable_implementation_verifyApplication.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyApplication (const cPtr_implementation * inObject,
                                            const GALGAS_applicationDefinition constin_appDef,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementation) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_implementation_verifyApplication f = NULL ;
    if (classIndex < gExtensionMethodTable_implementation_verifyApplication.count ()) {
      f = gExtensionMethodTable_implementation_verifyApplication (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_implementation_verifyApplication.count ()) {
           f = gExtensionMethodTable_implementation_verifyApplication (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_implementation_verifyApplication.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_appDef, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_implementation_verifyApplication (const cPtr_implementation * inObject,
                                                              const GALGAS_applicationDefinition constinArgument_appDef,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_implementation * object = inObject ;
  macroValidSharedObject (object, cPtr_implementation) ;
  cEnumerator_implementationMap enumerator_921 (object->mAttribute_imp, kEnumeration_up) ;
  while (enumerator_921.hasCurrentObject ()) {
    const enumGalgasBool test_0 = constinArgument_appDef.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 35)).getter_hasKey (enumerator_921.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 35)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 35)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_objectKind var_obj_1003 ;
      constinArgument_appDef.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 37)).method_get (enumerator_921.current_lkey (HERE), var_obj_1003, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 37)) ;
      callExtensionMethod_verifyApplication ((const cPtr_implementationObject *) enumerator_921.current_obj (HERE).ptr (), var_obj_1003, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 38)) ;
    }
    enumerator_921.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_implementation_verifyApplication (void) {
  enterExtensionMethod_verifyApplication (kTypeDescriptor_GALGAS_implementation.mSlotID,
                                          extensionMethod_implementation_verifyApplication) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_implementation_verifyApplication (void) {
  gExtensionMethodTable_implementation_verifyApplication.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_implementation_verifyApplication (defineExtensionMethod_implementation_verifyApplication,
                                                             freeExtensionMethod_implementation_verifyApplication) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                             Extension method '@objectAttributes verifyCrossReferences'                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_objectAttributes_verifyCrossReferences> gExtensionMethodTable_objectAttributes_verifyCrossReferences ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_objectAttributes_verifyCrossReferences inMethod) {
  gExtensionMethodTable_objectAttributes_verifyCrossReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (const cPtr_objectAttributes * inObject,
                                                const GALGAS_objectsMap constin_allObjects,
                                                const GALGAS_implementationObjectMap constin_attributes,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_objectAttributes) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_objectAttributes_verifyCrossReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_objectAttributes_verifyCrossReferences.count ()) {
      f = gExtensionMethodTable_objectAttributes_verifyCrossReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_objectAttributes_verifyCrossReferences.count ()) {
           f = gExtensionMethodTable_objectAttributes_verifyCrossReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_objectAttributes_verifyCrossReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_allObjects, constin_attributes, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_objectAttributes_verifyCrossReferences (const cPtr_objectAttributes * inObject,
                                                                    const GALGAS_objectsMap constinArgument_allObjects,
                                                                    const GALGAS_implementationObjectMap constinArgument_attributes,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectAttributes * object = inObject ;
  macroValidSharedObject (object, cPtr_objectAttributes) ;
  cEnumerator_identifierMap enumerator_18622 (object->mAttribute_objectParams, kEnumeration_up) ;
  while (enumerator_18622.hasCurrentObject ()) {
    const enumGalgasBool test_0 = constinArgument_attributes.getter_hasKey (enumerator_18622.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 599)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 599)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_impType var_type_18715 ;
      constinArgument_attributes.method_get (enumerator_18622.current_lkey (HERE), var_type_18715, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 600)) ;
      callExtensionMethod_verifyCrossReferences ((const cPtr_object_5F_t *) enumerator_18622.current_value (HERE).ptr (), constinArgument_allObjects, var_type_18715, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 601)) ;
    }
    enumerator_18622.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_objectAttributes_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_objectAttributes.mSlotID,
                                              extensionMethod_objectAttributes_verifyCrossReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_objectAttributes_verifyCrossReferences (void) {
  gExtensionMethodTable_objectAttributes_verifyCrossReferences.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_objectAttributes_verifyCrossReferences (defineExtensionMethod_objectAttributes_verifyCrossReferences,
                                                                   freeExtensionMethod_objectAttributes_verifyCrossReferences) ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TtypeList_2D_element::GALGAS_TtypeList_2D_element (void) :
mAttribute_mType () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TtypeList_2D_element::~ GALGAS_TtypeList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TtypeList_2D_element::GALGAS_TtypeList_2D_element (const GALGAS_Ttype & inOperand0) :
mAttribute_mType (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TtypeList_2D_element GALGAS_TtypeList_2D_element::constructor_new (const GALGAS_Ttype & inOperand0 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TtypeList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_TtypeList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_TtypeList_2D_element::objectCompare (const GALGAS_TtypeList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_TtypeList_2D_element::isValid (void) const {
  return mAttribute_mType.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TtypeList_2D_element::drop (void) {
  mAttribute_mType.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TtypeList_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @TtypeList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Ttype GALGAS_TtypeList_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               @TtypeList-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_TtypeList_2D_element ("TtypeList-element",
                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_TtypeList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_TtypeList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_TtypeList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_TtypeList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TtypeList_2D_element GALGAS_TtypeList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_TtypeList_2D_element result ;
  const GALGAS_TtypeList_2D_element * p = (const GALGAS_TtypeList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_TtypeList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("TtypeList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMapList_2D_element::GALGAS_TfieldMapList_2D_element (void) :
mAttribute_mMap () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMapList_2D_element::~ GALGAS_TfieldMapList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMapList_2D_element::GALGAS_TfieldMapList_2D_element (const GALGAS_TfieldMap & inOperand0) :
mAttribute_mMap (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMapList_2D_element GALGAS_TfieldMapList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_TfieldMapList_2D_element (GALGAS_TfieldMap::constructor_emptyMap (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMapList_2D_element GALGAS_TfieldMapList_2D_element::constructor_new (const GALGAS_TfieldMap & inOperand0 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TfieldMapList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_TfieldMapList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_TfieldMapList_2D_element::objectCompare (const GALGAS_TfieldMapList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mMap.objectCompare (inOperand.mAttribute_mMap) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_TfieldMapList_2D_element::isValid (void) const {
  return mAttribute_mMap.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TfieldMapList_2D_element::drop (void) {
  mAttribute_mMap.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TfieldMapList_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @TfieldMapList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mMap.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMap GALGAS_TfieldMapList_2D_element::getter_mMap (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mMap ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             @TfieldMapList-element type                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_TfieldMapList_2D_element ("TfieldMapList-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_TfieldMapList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_TfieldMapList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_TfieldMapList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_TfieldMapList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMapList_2D_element GALGAS_TfieldMapList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_TfieldMapList_2D_element result ;
  const GALGAS_TfieldMapList_2D_element * p = (const GALGAS_TfieldMapList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_TfieldMapList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("TfieldMapList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element::GALGAS_uint_33__32_List_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element::~ GALGAS_uint_33__32_List_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element::GALGAS_uint_33__32_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_uint & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element GALGAS_uint_33__32_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_33__32_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_uint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element GALGAS_uint_33__32_List_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                                        const GALGAS_uint & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_33__32_List_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_uint_33__32_List_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_uint_33__32_List_2D_element::objectCompare (const GALGAS_uint_33__32_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_uint_33__32_List_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @uint32List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_uint_33__32_List_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_uint_33__32_List_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @uint32List-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_List_2D_element ("uint32List-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_33__32_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_List_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_33__32_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_List_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element GALGAS_uint_33__32_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_List_2D_element result ;
  const GALGAS_uint_33__32_List_2D_element * p = (const GALGAS_uint_33__32_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_33__32_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element::GALGAS_uint_36__34_List_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element::~ GALGAS_uint_36__34_List_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element::GALGAS_uint_36__34_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_uint_36__34_ & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element GALGAS_uint_36__34_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_36__34_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_uint_36__34_::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element GALGAS_uint_36__34_List_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                                        const GALGAS_uint_36__34_ & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_List_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_uint_36__34_List_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_uint_36__34_List_2D_element::objectCompare (const GALGAS_uint_36__34_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_uint_36__34_List_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @uint64List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_uint_36__34_List_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_ GALGAS_uint_36__34_List_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @uint64List-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_List_2D_element ("uint64List-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_List_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_List_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element GALGAS_uint_36__34_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_List_2D_element result ;
  const GALGAS_uint_36__34_List_2D_element * p = (const GALGAS_uint_36__34_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element::GALGAS_sint_33__32_List_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element::~ GALGAS_sint_33__32_List_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element::GALGAS_sint_33__32_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_sint & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element GALGAS_sint_33__32_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_33__32_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_sint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element GALGAS_sint_33__32_List_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                                        const GALGAS_sint & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_33__32_List_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sint_33__32_List_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_sint_33__32_List_2D_element::objectCompare (const GALGAS_sint_33__32_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_sint_33__32_List_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @sint32List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_sint_33__32_List_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint GALGAS_sint_33__32_List_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @sint32List-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_List_2D_element ("sint32List-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_33__32_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_List_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_33__32_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_List_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element GALGAS_sint_33__32_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_List_2D_element result ;
  const GALGAS_sint_33__32_List_2D_element * p = (const GALGAS_sint_33__32_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element::GALGAS_sint_36__34_List_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element::~ GALGAS_sint_36__34_List_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element::GALGAS_sint_36__34_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_sint_36__34_ & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element GALGAS_sint_36__34_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_sint_36__34_::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element GALGAS_sint_36__34_List_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                                        const GALGAS_sint_36__34_ & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_List_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sint_36__34_List_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_sint_36__34_List_2D_element::objectCompare (const GALGAS_sint_36__34_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_sint_36__34_List_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @sint64List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_sint_36__34_List_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_ GALGAS_sint_36__34_List_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @sint64List-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_List_2D_element ("sint64List-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_36__34_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_List_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_36__34_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_List_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element GALGAS_sint_36__34_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_List_2D_element result ;
  const GALGAS_sint_36__34_List_2D_element * p = (const GALGAS_sint_36__34_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element::GALGAS_floatList_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element::~ GALGAS_floatList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element::GALGAS_floatList_2D_element (const GALGAS_location & inOperand0,
                                                          const GALGAS_double & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element GALGAS_floatList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_floatList_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                      GALGAS_double::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element GALGAS_floatList_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                          const GALGAS_double & inOperand1 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_floatList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_floatList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_floatList_2D_element::objectCompare (const GALGAS_floatList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_floatList_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @floatList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_floatList_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_floatList_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               @floatList-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatList_2D_element ("floatList-element",
                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_floatList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_floatList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element GALGAS_floatList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_floatList_2D_element result ;
  const GALGAS_floatList_2D_element * p = (const GALGAS_floatList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_floatList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element::GALGAS_locationList_2D_element (void) :
mAttribute_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element::~ GALGAS_locationList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element::GALGAS_locationList_2D_element (const GALGAS_location & inOperand0) :
mAttribute_location (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element GALGAS_locationList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_locationList_2D_element (GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element GALGAS_locationList_2D_element::constructor_new (const GALGAS_location & inOperand0 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_locationList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_locationList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_locationList_2D_element::objectCompare (const GALGAS_locationList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_locationList_2D_element::isValid (void) const {
  return mAttribute_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList_2D_element::drop (void) {
  mAttribute_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList_2D_element::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "<struct @locationList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_locationList_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             @locationList-element type                                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_locationList_2D_element ("locationList-element",
                                                NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_locationList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_locationList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_locationList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_locationList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element GALGAS_locationList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_locationList_2D_element result ;
  const GALGAS_locationList_2D_element * p = (const GALGAS_locationList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_locationList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("locationList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                 Abstract extension getter '@impType mergeWithType'                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <enterExtensionGetter_impType_mergeWithType> gExtensionGetterTable_impType_mergeWithType ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionGetter_mergeWithType (const int32_t inClassIndex,
                                         enterExtensionGetter_impType_mergeWithType inGetter) {
  gExtensionGetterTable_impType_mergeWithType.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionGetter_impType_mergeWithType (void) {
  gExtensionGetterTable_impType_mergeWithType.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_impType_mergeWithType (NULL,
                                                  freeExtensionGetter_impType_mergeWithType) ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType callExtensionGetter_mergeWithType (const cPtr_impType * inObject,
                                                  GALGAS_impType in_typeToMerge,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_impType result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_impType_mergeWithType f = NULL ;
    if (classIndex < gExtensionGetterTable_impType_mergeWithType.count ()) {
      f = gExtensionGetterTable_impType_mergeWithType (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_impType_mergeWithType.count ()) {
           f = gExtensionGetterTable_impType_mergeWithType (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_impType_mergeWithType.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_typeToMerge, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                       Extension getter '@impType autoAllowed'                                       *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <enterExtensionGetter_impType_autoAllowed> gExtensionGetterTable_impType_autoAllowed ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionGetter_autoAllowed (const int32_t inClassIndex,
                                       enterExtensionGetter_impType_autoAllowed inGetter) {
  gExtensionGetterTable_impType_autoAllowed.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_autoAllowed (const cPtr_impType * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_impType_autoAllowed f = NULL ;
    if (classIndex < gExtensionGetterTable_impType_autoAllowed.count ()) {
      f = gExtensionGetterTable_impType_autoAllowed (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_impType_autoAllowed.count ()) {
           f = gExtensionGetterTable_impType_autoAllowed (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_impType_autoAllowed.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_bool extensionGetter_impType_autoAllowed (const cPtr_impType * /* inObject */,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_impType_autoAllowed (void) {
  enterExtensionGetter_autoAllowed (kTypeDescriptor_GALGAS_impType.mSlotID,
                                    extensionGetter_impType_autoAllowed) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionGetter_impType_autoAllowed (void) {
  gExtensionGetterTable_impType_autoAllowed.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_impType_autoAllowed (defineExtensionGetter_impType_autoAllowed,
                                                freeExtensionGetter_impType_autoAllowed) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                  Extension method '@impAutoDefaultType setDefault'                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_impAutoDefaultType_setDefault> gExtensionMethodTable_impAutoDefaultType_setDefault ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_setDefault (const int32_t inClassIndex,
                                      extensionMethodSignature_impAutoDefaultType_setDefault inMethod) {
  gExtensionMethodTable_impAutoDefaultType_setDefault.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_setDefault (const cPtr_impAutoDefaultType * inObject,
                                     GALGAS_objectAttributes & io_attributes,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impAutoDefaultType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_impAutoDefaultType_setDefault f = NULL ;
    if (classIndex < gExtensionMethodTable_impAutoDefaultType_setDefault.count ()) {
      f = gExtensionMethodTable_impAutoDefaultType_setDefault (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_impAutoDefaultType_setDefault.count ()) {
           f = gExtensionMethodTable_impAutoDefaultType_setDefault (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_impAutoDefaultType_setDefault.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_attributes, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impAutoDefaultType_setDefault (const cPtr_impAutoDefaultType * inObject,
                                                           GALGAS_objectAttributes & ioArgument_attributes,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impAutoDefaultType * object = inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  const enumGalgasBool test_0 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 489)).getter_hasKey (object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 489)) COMMA_SOURCE_FILE ("implementation_types.galgas", 489)).operator_not (SOURCE_FILE ("implementation_types.galgas", 489)).boolEnum () ;
  if (kBoolTrue == test_0) {
    if (object->mAttribute_defaultValue.isValid ()) {
      if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
      }else if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
        GALGAS_identifierMap var_attr_13330 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 493)) ;
        {
        var_attr_13330.setter_put (object->mAttribute_name, object->mAttribute_defaultValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 494)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_13330 COMMA_SOURCE_FILE ("implementation_types.galgas", 495)) ;
        }
      }else{
        GALGAS_identifierMap var_attr_13526 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 498)) ;
        {
        var_attr_13526.setter_put (object->mAttribute_name, object->mAttribute_defaultValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 499)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_13526 COMMA_SOURCE_FILE ("implementation_types.galgas", 500)) ;
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impAutoDefaultType_setDefault (void) {
  enterExtensionMethod_setDefault (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                   extensionMethod_impAutoDefaultType_setDefault) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_impAutoDefaultType_setDefault (void) {
  gExtensionMethodTable_impAutoDefaultType_setDefault.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impAutoDefaultType_setDefault (defineExtensionMethod_impAutoDefaultType_setDefault,
                                                          freeExtensionMethod_impAutoDefaultType_setDefault) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Extension method '@impType checkAttributeReferences'                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_impType_checkAttributeReferences> gExtensionMethodTable_impType_checkAttributeReferences ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_checkAttributeReferences (const int32_t inClassIndex,
                                                    extensionMethodSignature_impType_checkAttributeReferences inMethod) {
  gExtensionMethodTable_impType_checkAttributeReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_checkAttributeReferences (const cPtr_impType * inObject,
                                                   const GALGAS_implementation constin_imp,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_impType_checkAttributeReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_impType_checkAttributeReferences.count ()) {
      f = gExtensionMethodTable_impType_checkAttributeReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_impType_checkAttributeReferences.count ()) {
           f = gExtensionMethodTable_impType_checkAttributeReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_impType_checkAttributeReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_imp, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impType_checkAttributeReferences (const cPtr_impType * /* inObject */,
                                                              const GALGAS_implementation /* constinArgument_imp */,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impType.mSlotID,
                                                 extensionMethod_impType_checkAttributeReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_impType_checkAttributeReferences (void) {
  gExtensionMethodTable_impType_checkAttributeReferences.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impType_checkAttributeReferences (defineExtensionMethod_impType_checkAttributeReferences,
                                                             freeExtensionMethod_impType_checkAttributeReferences) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                       Extension getter '@implementationObject mergeImplementationObjectWith'                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <enterExtensionGetter_implementationObject_mergeImplementationObjectWith> gExtensionGetterTable_implementationObject_mergeImplementationObjectWith ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionGetter_mergeImplementationObjectWith (const int32_t inClassIndex,
                                                         enterExtensionGetter_implementationObject_mergeImplementationObjectWith inGetter) {
  gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObject callExtensionGetter_mergeImplementationObjectWith (const cPtr_implementationObject * inObject,
                                                                               const GALGAS_implementationObject & in_objToMerge,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) {
  GALGAS_implementationObject result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementationObject) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_implementationObject_mergeImplementationObjectWith f = NULL ;
    if (classIndex < gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.count ()) {
      f = gExtensionGetterTable_implementationObject_mergeImplementationObjectWith (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.count ()) {
           f = gExtensionGetterTable_implementationObject_mergeImplementationObjectWith (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_objToMerge, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_implementationObject extensionGetter_implementationObject_mergeImplementationObjectWith (const cPtr_implementationObject * inObject,
                                                                                                       const GALGAS_implementationObject & constinArgument_objToMerge,
                                                                                                       C_Compiler * inCompiler
                                                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObject result_mergedObj ; // Returned variable
  const cPtr_implementationObject * object = inObject ;
  macroValidSharedObject (object, cPtr_implementationObject) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_multiple.objectCompare (constinArgument_objToMerge.getter_multiple (SOURCE_FILE ("implementation_types.galgas", 986)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (gOption_goil_5F_options_warnMultiple.getter_value ()).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_location location_2 (constinArgument_objToMerge.getter_multiple (SOURCE_FILE ("implementation_types.galgas", 988)).getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticWarning (location_2, GALGAS_string ("multiple redefinition")  COMMA_SOURCE_FILE ("implementation_types.galgas", 988)) ;
      GALGAS_location location_3 (object->mAttribute_multiple.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticWarning (location_3, GALGAS_string ("was defined here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 989)) ;
    }
  }
  result_mergedObj = GALGAS_implementationObject::constructor_new (object->mAttribute_multiple, extensionGetter_mergeImplementationObjectAttributesWith (object->mAttribute_attributes, constinArgument_objToMerge.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 1002)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 1002))  COMMA_SOURCE_FILE ("implementation_types.galgas", 1002)) ;
//---
  return result_mergedObj ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_implementationObject_mergeImplementationObjectWith (void) {
  enterExtensionGetter_mergeImplementationObjectWith (kTypeDescriptor_GALGAS_implementationObject.mSlotID,
                                                      extensionGetter_implementationObject_mergeImplementationObjectWith) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionGetter_implementationObject_mergeImplementationObjectWith (void) {
  gExtensionGetterTable_implementationObject_mergeImplementationObjectWith.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_implementationObject_mergeImplementationObjectWith (defineExtensionGetter_implementationObject_mergeImplementationObjectWith,
                                                                               freeExtensionGetter_implementationObject_mergeImplementationObjectWith) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                          Extension method '@object_t set'                                           *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_object_5F_t_set> gExtensionMethodTable_object_5F_t_set ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_set (const int32_t inClassIndex,
                               extensionMethodSignature_object_5F_t_set inMethod) {
  gExtensionMethodTable_object_5F_t_set.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_set (const cPtr_object_5F_t * inObject,
                              const GALGAS_lstring constin_name,
                              GALGAS_TfieldMap & io_result,
                              C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_object_5F_t) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_object_5F_t_set f = NULL ;
    if (classIndex < gExtensionMethodTable_object_5F_t_set.count ()) {
      f = gExtensionMethodTable_object_5F_t_set (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_object_5F_t_set.count ()) {
           f = gExtensionMethodTable_object_5F_t_set (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_object_5F_t_set.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_name, io_result, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_object_5F_t_set (const cPtr_object_5F_t * /* inObject */,
                                             const GALGAS_lstring constinArgument_name,
                                             GALGAS_TfieldMap & /* ioArgument_result */,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 28)), GALGAS_string ("Attribute: ").add_operation (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 28)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 28)).add_operation (GALGAS_string (", Internal error"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 28))  COMMA_SOURCE_FILE ("systemConfig.galgas", 28)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_object_5F_t_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_object_5F_t.mSlotID,
                            extensionMethod_object_5F_t_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_object_5F_t_set (void) {
  gExtensionMethodTable_object_5F_t_set.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_object_5F_t_set (defineExtensionMethod_object_5F_t_set,
                                            freeExtensionMethod_object_5F_t_set) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                          Extension getter '@applicationDefinition applicationWithDefaults'                          *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <enterExtensionGetter_applicationDefinition_applicationWithDefaults> gExtensionGetterTable_applicationDefinition_applicationWithDefaults ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionGetter_applicationWithDefaults (const int32_t inClassIndex,
                                                   enterExtensionGetter_applicationDefinition_applicationWithDefaults inGetter) {
  gExtensionGetterTable_applicationDefinition_applicationWithDefaults.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_applicationDefinition callExtensionGetter_applicationWithDefaults (const cPtr_applicationDefinition * inObject,
                                                                          const GALGAS_implementation & in_imp,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_applicationDefinition result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_applicationDefinition) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_applicationDefinition_applicationWithDefaults f = NULL ;
    if (classIndex < gExtensionGetterTable_applicationDefinition_applicationWithDefaults.count ()) {
      f = gExtensionGetterTable_applicationDefinition_applicationWithDefaults (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_applicationDefinition_applicationWithDefaults.count ()) {
           f = gExtensionGetterTable_applicationDefinition_applicationWithDefaults (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_applicationDefinition_applicationWithDefaults.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_imp, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_applicationDefinition extensionGetter_applicationDefinition_applicationWithDefaults (const cPtr_applicationDefinition * inObject,
                                                                                                   const GALGAS_implementation & /* constinArgument_imp */,
                                                                                                   C_Compiler * /* inCompiler */
                                                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_applicationDefinition result_result ; // Returned variable
  const cPtr_applicationDefinition * object = inObject ;
  macroValidSharedObject (object, cPtr_applicationDefinition) ;
  const GALGAS_applicationDefinition temp_0 = object ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_applicationDefinition_applicationWithDefaults (void) {
  enterExtensionGetter_applicationWithDefaults (kTypeDescriptor_GALGAS_applicationDefinition.mSlotID,
                                                extensionGetter_applicationDefinition_applicationWithDefaults) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionGetter_applicationDefinition_applicationWithDefaults (void) {
  gExtensionGetterTable_applicationDefinition_applicationWithDefaults.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_applicationDefinition_applicationWithDefaults (defineExtensionGetter_applicationDefinition_applicationWithDefaults,
                                                                          freeExtensionGetter_applicationDefinition_applicationWithDefaults) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                             Extension method '@implementationObject verifyApplication'                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_implementationObject_verifyApplication> gExtensionMethodTable_implementationObject_verifyApplication ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_verifyApplication (const int32_t inClassIndex,
                                             extensionMethodSignature_implementationObject_verifyApplication inMethod) {
  gExtensionMethodTable_implementationObject_verifyApplication.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyApplication (const cPtr_implementationObject * inObject,
                                            const GALGAS_objectKind constin_objectsOfKind,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_implementationObject) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_implementationObject_verifyApplication f = NULL ;
    if (classIndex < gExtensionMethodTable_implementationObject_verifyApplication.count ()) {
      f = gExtensionMethodTable_implementationObject_verifyApplication (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_implementationObject_verifyApplication.count ()) {
           f = gExtensionMethodTable_implementationObject_verifyApplication (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_implementationObject_verifyApplication.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_objectsOfKind, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_implementationObject_verifyApplication (const cPtr_implementationObject * inObject,
                                                                    const GALGAS_objectKind constinArgument_objectsOfKind,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_implementationObject * object = inObject ;
  macroValidSharedObject (object, cPtr_implementationObject) ;
  cEnumerator_objectKindMap enumerator_1305 (constinArgument_objectsOfKind.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 46)), kEnumeration_up) ;
  while (enumerator_1305.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_1334 (object->mAttribute_attributes, kEnumeration_up) ;
    while (enumerator_1334.hasCurrentObject ()) {
      callExtensionMethod_verifyApplication ((const cPtr_impType *) enumerator_1334.current_type (HERE).ptr (), enumerator_1305.current_attributes (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 48)) ;
      enumerator_1334.gotoNextObject () ;
    }
    enumerator_1305.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_implementationObject_verifyApplication (void) {
  enterExtensionMethod_verifyApplication (kTypeDescriptor_GALGAS_implementationObject.mSlotID,
                                          extensionMethod_implementationObject_verifyApplication) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_implementationObject_verifyApplication (void) {
  gExtensionMethodTable_implementationObject_verifyApplication.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_implementationObject_verifyApplication (defineExtensionMethod_implementationObject_verifyApplication,
                                                                   freeExtensionMethod_implementationObject_verifyApplication) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                    Extension method '@impType verifyApplication'                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_impType_verifyApplication> gExtensionMethodTable_impType_verifyApplication ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_verifyApplication (const int32_t inClassIndex,
                                             extensionMethodSignature_impType_verifyApplication inMethod) {
  gExtensionMethodTable_impType_verifyApplication.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyApplication (const cPtr_impType * inObject,
                                            const GALGAS_objectAttributes constin_attrs,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_impType_verifyApplication f = NULL ;
    if (classIndex < gExtensionMethodTable_impType_verifyApplication.count ()) {
      f = gExtensionMethodTable_impType_verifyApplication (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_impType_verifyApplication.count ()) {
           f = gExtensionMethodTable_impType_verifyApplication (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_impType_verifyApplication.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_attrs, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impType_verifyApplication (const cPtr_impType * inObject,
                                                       const GALGAS_objectAttributes constinArgument_attrs,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impType * object = inObject ;
  macroValidSharedObject (object, cPtr_impType) ;
  cEnumerator_identifierMap enumerator_1580 (constinArgument_attrs.getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 56)), kEnumeration_up) ;
  while (enumerator_1580.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_1580.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 57)).objectCompare (object->mAttribute_name.getter_string (SOURCE_FILE ("semantic_verification.galgas", 57)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_impType temp_1 = object ;
      callExtensionMethod_verifyMultipleType ((const cPtr_impType *) temp_1.ptr (), enumerator_1580.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 58)) ;
    }
    enumerator_1580.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impType_verifyApplication (void) {
  enterExtensionMethod_verifyApplication (kTypeDescriptor_GALGAS_impType.mSlotID,
                                          extensionMethod_impType_verifyApplication) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_impType_verifyApplication (void) {
  gExtensionMethodTable_impType_verifyApplication.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impType_verifyApplication (defineExtensionMethod_impType_verifyApplication,
                                                      freeExtensionMethod_impType_verifyApplication) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                       Extension method '@impType verifyType'                                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_impType_verifyType> gExtensionMethodTable_impType_verifyType ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_verifyType (const int32_t inClassIndex,
                                      extensionMethodSignature_impType_verifyType inMethod) {
  gExtensionMethodTable_impType_verifyType.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyType (const cPtr_impType * inObject,
                                     const GALGAS_object_5F_t constin_attr,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_impType_verifyType f = NULL ;
    if (classIndex < gExtensionMethodTable_impType_verifyType.count ()) {
      f = gExtensionMethodTable_impType_verifyType (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_impType_verifyType.count ()) {
           f = gExtensionMethodTable_impType_verifyType (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_impType_verifyType.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_attr, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impType_verifyType (const cPtr_impType * /* inObject */,
                                                const GALGAS_object_5F_t constinArgument_attr,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 66)), GALGAS_string ("Internal error, a generic type should not be instantiated")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 66)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impType.mSlotID,
                                   extensionMethod_impType_verifyType) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_impType_verifyType (void) {
  gExtensionMethodTable_impType_verifyType.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impType_verifyType (defineExtensionMethod_impType_verifyType,
                                               freeExtensionMethod_impType_verifyType) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Extension method '@impType verifyMultipleType'                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_impType_verifyMultipleType> gExtensionMethodTable_impType_verifyMultipleType ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_verifyMultipleType (const int32_t inClassIndex,
                                              extensionMethodSignature_impType_verifyMultipleType inMethod) {
  gExtensionMethodTable_impType_verifyMultipleType.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyMultipleType (const cPtr_impType * inObject,
                                             const GALGAS_object_5F_t constin_attr,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_impType) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_impType_verifyMultipleType f = NULL ;
    if (classIndex < gExtensionMethodTable_impType_verifyMultipleType.count ()) {
      f = gExtensionMethodTable_impType_verifyMultipleType (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_impType_verifyMultipleType.count ()) {
           f = gExtensionMethodTable_impType_verifyMultipleType (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_impType_verifyMultipleType.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_attr, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impType_verifyMultipleType (const cPtr_impType * inObject,
                                                        const GALGAS_object_5F_t constinArgument_attr,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impType * object = inObject ;
  macroValidSharedObject (object, cPtr_impType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
      GALGAS_multipleAttribute cast_2080_ma ((cPtr_multipleAttribute *) constinArgument_attr.ptr ()) ;
      cEnumerator_identifierList enumerator_2108 (cast_2080_ma.getter_items (SOURCE_FILE ("semantic_verification.galgas", 74)), kEnumeration_up) ;
      while (enumerator_2108.hasCurrentObject ()) {
        const GALGAS_impType temp_0 = object ;
        callExtensionMethod_verifyType ((const cPtr_impType *) temp_0.ptr (), enumerator_2108.current_item (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 75)) ;
        enumerator_2108.gotoNextObject () ;
      }
    }else{
      const GALGAS_impType temp_1 = object ;
      callExtensionMethod_verifyType ((const cPtr_impType *) temp_1.ptr (), constinArgument_attr, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 78)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impType_verifyMultipleType (void) {
  enterExtensionMethod_verifyMultipleType (kTypeDescriptor_GALGAS_impType.mSlotID,
                                           extensionMethod_impType_verifyMultipleType) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_impType_verifyMultipleType (void) {
  gExtensionMethodTable_impType_verifyMultipleType.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impType_verifyMultipleType (defineExtensionMethod_impType_verifyMultipleType,
                                                       freeExtensionMethod_impType_verifyMultipleType) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Extension method '@objectsMap verifyCrossReferences'                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_verifyCrossReferences (const GALGAS_objectsMap inObject,
                                            const GALGAS_implementation constinArgument_imp,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_objectsMap temp_0 = inObject ;
  cEnumerator_objectsMap enumerator_18146 (temp_0, kEnumeration_up) ;
  while (enumerator_18146.hasCurrentObject ()) {
    GALGAS_implementationObject var_obj_18201 ;
    constinArgument_imp.getter_imp (SOURCE_FILE ("semantic_verification.galgas", 580)).method_get (enumerator_18146.current_lkey (HERE), var_obj_18201, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 580)) ;
    const GALGAS_objectsMap temp_1 = inObject ;
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectKind *) enumerator_18146.current_objectsOfKind (HERE).ptr (), temp_1, var_obj_18201, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 581)) ;
    enumerator_18146.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                 Extension method '@object_t verifyCrossReferences'                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_object_5F_t_verifyCrossReferences> gExtensionMethodTable_object_5F_t_verifyCrossReferences ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_object_5F_t_verifyCrossReferences inMethod) {
  gExtensionMethodTable_object_5F_t_verifyCrossReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                const GALGAS_objectsMap constin_allObjects,
                                                const GALGAS_impType constin_type,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_object_5F_t) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_object_5F_t_verifyCrossReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_object_5F_t_verifyCrossReferences.count ()) {
      f = gExtensionMethodTable_object_5F_t_verifyCrossReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_object_5F_t_verifyCrossReferences.count ()) {
           f = gExtensionMethodTable_object_5F_t_verifyCrossReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_object_5F_t_verifyCrossReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_allObjects, constin_type, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_object_5F_t_verifyCrossReferences (const cPtr_object_5F_t * /* inObject */,
                                                               const GALGAS_objectsMap /* constinArgument_allObjects */,
                                                               const GALGAS_impType /* constinArgument_type */,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_object_5F_t_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_object_5F_t.mSlotID,
                                              extensionMethod_object_5F_t_verifyCrossReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_object_5F_t_verifyCrossReferences (void) {
  gExtensionMethodTable_object_5F_t_verifyCrossReferences.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_object_5F_t_verifyCrossReferences (defineExtensionMethod_object_5F_t_verifyCrossReferences,
                                                              freeExtensionMethod_object_5F_t_verifyCrossReferences) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                           Extension method '@applicationDefinition verifyCrossReferences'                           *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_applicationDefinition_verifyCrossReferences> gExtensionMethodTable_applicationDefinition_verifyCrossReferences ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_applicationDefinition_verifyCrossReferences inMethod) {
  gExtensionMethodTable_applicationDefinition_verifyCrossReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (const cPtr_applicationDefinition * inObject,
                                                const GALGAS_implementation constin_imp,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_applicationDefinition) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_applicationDefinition_verifyCrossReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_applicationDefinition_verifyCrossReferences.count ()) {
      f = gExtensionMethodTable_applicationDefinition_verifyCrossReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_applicationDefinition_verifyCrossReferences.count ()) {
           f = gExtensionMethodTable_applicationDefinition_verifyCrossReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_applicationDefinition_verifyCrossReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_imp, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_applicationDefinition_verifyCrossReferences (const cPtr_applicationDefinition * inObject,
                                                                         const GALGAS_implementation constinArgument_imp,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_applicationDefinition * object = inObject ;
  macroValidSharedObject (object, cPtr_applicationDefinition) ;
  extensionMethod_verifyCrossReferences (object->mAttribute_objects, constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 667)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_applicationDefinition_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_applicationDefinition.mSlotID,
                                              extensionMethod_applicationDefinition_verifyCrossReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_applicationDefinition_verifyCrossReferences (void) {
  gExtensionMethodTable_applicationDefinition_verifyCrossReferences.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_applicationDefinition_verifyCrossReferences (defineExtensionMethod_applicationDefinition_verifyCrossReferences,
                                                                        freeExtensionMethod_applicationDefinition_verifyCrossReferences) ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TvarPath_2D_element::GALGAS_TvarPath_2D_element (void) :
mAttribute_item (),
mAttribute_key (),
mAttribute_idx () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TvarPath_2D_element::~ GALGAS_TvarPath_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TvarPath_2D_element::GALGAS_TvarPath_2D_element (const GALGAS_lstring & inOperand0,
                                                        const GALGAS_lstring & inOperand1,
                                                        const GALGAS_lsint & inOperand2) :
mAttribute_item (inOperand0),
mAttribute_key (inOperand1),
mAttribute_idx (inOperand2) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TvarPath_2D_element GALGAS_TvarPath_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_TvarPath_2D_element (GALGAS_lstring::constructor_default (HERE),
                                     GALGAS_lstring::constructor_default (HERE),
                                     GALGAS_lsint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TvarPath_2D_element GALGAS_TvarPath_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_lstring & inOperand1,
                                                                        const GALGAS_lsint & inOperand2 
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TvarPath_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_TvarPath_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_TvarPath_2D_element::objectCompare (const GALGAS_TvarPath_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_item.objectCompare (inOperand.mAttribute_item) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_key.objectCompare (inOperand.mAttribute_key) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_idx.objectCompare (inOperand.mAttribute_idx) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_TvarPath_2D_element::isValid (void) const {
  return mAttribute_item.isValid () && mAttribute_key.isValid () && mAttribute_idx.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TvarPath_2D_element::drop (void) {
  mAttribute_item.drop () ;
  mAttribute_key.drop () ;
  mAttribute_idx.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TvarPath_2D_element::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "<struct @TvarPath-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_item.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_key.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_idx.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_TvarPath_2D_element::getter_item (UNUSED_LOCATION_ARGS) const {
  return mAttribute_item ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_TvarPath_2D_element::getter_key (UNUSED_LOCATION_ARGS) const {
  return mAttribute_key ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint GALGAS_TvarPath_2D_element::getter_idx (UNUSED_LOCATION_ARGS) const {
  return mAttribute_idx ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               @TvarPath-element type                                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_TvarPath_2D_element ("TvarPath-element",
                                            NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_TvarPath_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_TvarPath_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_TvarPath_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_TvarPath_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TvarPath_2D_element GALGAS_TvarPath_2D_element::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_TvarPath_2D_element result ;
  const GALGAS_TvarPath_2D_element * p = (const GALGAS_TvarPath_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_TvarPath_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("TvarPath-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element::GALGAS_sortingKeyList_2D_element (void) :
mAttribute_key (),
mAttribute_order () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element::~ GALGAS_sortingKeyList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element::GALGAS_sortingKeyList_2D_element (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_lsint & inOperand1) :
mAttribute_key (inOperand0),
mAttribute_order (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element GALGAS_sortingKeyList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sortingKeyList_2D_element (GALGAS_lstring::constructor_default (HERE),
                                           GALGAS_lsint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element GALGAS_sortingKeyList_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                    const GALGAS_lsint & inOperand1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sortingKeyList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sortingKeyList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_sortingKeyList_2D_element::objectCompare (const GALGAS_sortingKeyList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_key.objectCompare (inOperand.mAttribute_key) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_order.objectCompare (inOperand.mAttribute_order) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_sortingKeyList_2D_element::isValid (void) const {
  return mAttribute_key.isValid () && mAttribute_order.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList_2D_element::drop (void) {
  mAttribute_key.drop () ;
  mAttribute_order.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @sortingKeyList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_key.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_order.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_sortingKeyList_2D_element::getter_key (UNUSED_LOCATION_ARGS) const {
  return mAttribute_key ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lsint GALGAS_sortingKeyList_2D_element::getter_order (UNUSED_LOCATION_ARGS) const {
  return mAttribute_order ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            @sortingKeyList-element type                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sortingKeyList_2D_element ("sortingKeyList-element",
                                                  NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sortingKeyList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sortingKeyList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sortingKeyList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sortingKeyList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element GALGAS_sortingKeyList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sortingKeyList_2D_element result ;
  const GALGAS_sortingKeyList_2D_element * p = (const GALGAS_sortingKeyList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sortingKeyList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sortingKeyList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element::GALGAS_numberList_2D_element (void) :
mAttribute_location (),
mAttribute_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element::~ GALGAS_numberList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element::GALGAS_numberList_2D_element (const GALGAS_location & inOperand0,
                                                            const GALGAS_object_5F_t & inOperand1) :
mAttribute_location (inOperand0),
mAttribute_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element GALGAS_numberList_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                            const GALGAS_object_5F_t & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_numberList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_numberList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_numberList_2D_element::objectCompare (const GALGAS_numberList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_location.objectCompare (inOperand.mAttribute_location) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_numberList_2D_element::isValid (void) const {
  return mAttribute_location.isValid () && mAttribute_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList_2D_element::drop (void) {
  mAttribute_location.drop () ;
  mAttribute_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @numberList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_numberList_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mAttribute_location ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t GALGAS_numberList_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @numberList-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_numberList_2D_element ("numberList-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_numberList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_numberList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_numberList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_numberList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element GALGAS_numberList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_numberList_2D_element result ;
  const GALGAS_numberList_2D_element * p = (const GALGAS_numberList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_numberList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("numberList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element::GALGAS_implementationObjectMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_type () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element::~ GALGAS_implementationObjectMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element::GALGAS_implementationObjectMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                                      const GALGAS_impType & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_type (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element GALGAS_implementationObjectMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                      const GALGAS_impType & inOperand1 
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_implementationObjectMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_implementationObjectMap_2D_element::objectCompare (const GALGAS_implementationObjectMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_type.objectCompare (inOperand.mAttribute_type) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_implementationObjectMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_type.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationObjectMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_type.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationObjectMap_2D_element::description (C_String & ioString,
                                                             const int32_t inIndentation) const {
  ioString << "<struct @implementationObjectMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_type.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_implementationObjectMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_impType GALGAS_implementationObjectMap_2D_element::getter_type (UNUSED_LOCATION_ARGS) const {
  return mAttribute_type ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                        @implementationObjectMap-element type                                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ("implementationObjectMap-element",
                                                           NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_implementationObjectMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_implementationObjectMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationObjectMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element GALGAS_implementationObjectMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_implementationObjectMap_2D_element result ;
  const GALGAS_implementationObjectMap_2D_element * p = (const GALGAS_implementationObjectMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_implementationObjectMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationObjectMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element::GALGAS_enumValues_2D_element (void) :
mAttribute_lkey (),
mAttribute_subAttributes () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element::~ GALGAS_enumValues_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element::GALGAS_enumValues_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_implementationObjectMap & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_subAttributes (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element GALGAS_enumValues_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_enumValues_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_implementationObjectMap::constructor_emptyMap (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element GALGAS_enumValues_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_implementationObjectMap & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_enumValues_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_enumValues_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_enumValues_2D_element::objectCompare (const GALGAS_enumValues_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_subAttributes.objectCompare (inOperand.mAttribute_subAttributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_enumValues_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_subAttributes.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumValues_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_subAttributes.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumValues_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @enumValues-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_subAttributes.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_enumValues_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap GALGAS_enumValues_2D_element::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_subAttributes ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @enumValues-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_enumValues_2D_element ("enumValues-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_enumValues_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumValues_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_enumValues_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumValues_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element GALGAS_enumValues_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_enumValues_2D_element result ;
  const GALGAS_enumValues_2D_element * p = (const GALGAS_enumValues_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_enumValues_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("enumValues-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element::GALGAS_implementationMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_obj () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element::~ GALGAS_implementationMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element::GALGAS_implementationMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_implementationObject & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_obj (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element GALGAS_implementationMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_implementationMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_implementationObject::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element GALGAS_implementationMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_implementationObject & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_implementationMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_implementationMap_2D_element::objectCompare (const GALGAS_implementationMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_obj.objectCompare (inOperand.mAttribute_obj) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_implementationMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_obj.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_obj.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @implementationMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_obj.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_implementationMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObject GALGAS_implementationMap_2D_element::getter_obj (UNUSED_LOCATION_ARGS) const {
  return mAttribute_obj ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                           @implementationMap-element type                                           *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationMap_2D_element ("implementationMap-element",
                                                     NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_implementationMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_implementationMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element GALGAS_implementationMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_implementationMap_2D_element result ;
  const GALGAS_implementationMap_2D_element * p = (const GALGAS_implementationMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_implementationMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element::GALGAS_identifierMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element::~ GALGAS_identifierMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element::GALGAS_identifierMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_object_5F_t & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element GALGAS_identifierMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_object_5F_t & inOperand1 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_identifierMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_identifierMap_2D_element::objectCompare (const GALGAS_identifierMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_identifierMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierMap_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @identifierMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_identifierMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t GALGAS_identifierMap_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             @identifierMap-element type                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierMap_2D_element ("identifierMap-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_identifierMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_identifierMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element GALGAS_identifierMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_identifierMap_2D_element result ;
  const GALGAS_identifierMap_2D_element * p = (const GALGAS_identifierMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_identifierMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element::GALGAS_identifierList_2D_element (void) :
mAttribute_item () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element::~ GALGAS_identifierList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element::GALGAS_identifierList_2D_element (const GALGAS_object_5F_t & inOperand0) :
mAttribute_item (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element GALGAS_identifierList_2D_element::constructor_new (const GALGAS_object_5F_t & inOperand0 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_identifierList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_identifierList_2D_element::objectCompare (const GALGAS_identifierList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_item.objectCompare (inOperand.mAttribute_item) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_identifierList_2D_element::isValid (void) const {
  return mAttribute_item.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList_2D_element::drop (void) {
  mAttribute_item.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @identifierList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_item.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_object_5F_t GALGAS_identifierList_2D_element::getter_item (UNUSED_LOCATION_ARGS) const {
  return mAttribute_item ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            @identifierList-element type                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierList_2D_element ("identifierList-element",
                                                  NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_identifierList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_identifierList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element GALGAS_identifierList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_identifierList_2D_element result ;
  const GALGAS_identifierList_2D_element * p = (const GALGAS_identifierList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_identifierList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element::GALGAS_stringMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element::~ GALGAS_stringMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element::GALGAS_stringMap_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_string & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element GALGAS_stringMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_stringMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                      GALGAS_string::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element GALGAS_stringMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_string & inOperand1 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_stringMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_stringMap_2D_element::objectCompare (const GALGAS_stringMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_stringMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringMap_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @stringMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_stringMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_stringMap_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               @stringMap-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringMap_2D_element ("stringMap-element",
                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element GALGAS_stringMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_stringMap_2D_element result ;
  const GALGAS_stringMap_2D_element * p = (const GALGAS_stringMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element::GALGAS_lstringMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element::~ GALGAS_lstringMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element::GALGAS_lstringMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_lstring & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element GALGAS_lstringMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lstringMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_lstring::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element GALGAS_lstringMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_lstring & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstringMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_lstringMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lstringMap_2D_element::objectCompare (const GALGAS_lstringMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_value.objectCompare (inOperand.mAttribute_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lstringMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @lstringMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_lstringMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_lstringMap_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mAttribute_value ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @lstringMap-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringMap_2D_element ("lstringMap-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lstringMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lstringMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element GALGAS_lstringMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_lstringMap_2D_element result ;
  const GALGAS_lstringMap_2D_element * p = (const GALGAS_lstringMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_lstringMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element::GALGAS_prefix_5F_map_2D_element (void) :
mAttribute_lkey (),
mAttribute_prefix (),
mAttribute_tag_5F_to_5F_rep () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element::~ GALGAS_prefix_5F_map_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element::GALGAS_prefix_5F_map_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_string & inOperand1,
                                                                  const GALGAS_string & inOperand2) :
mAttribute_lkey (inOperand0),
mAttribute_prefix (inOperand1),
mAttribute_tag_5F_to_5F_rep (inOperand2) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element GALGAS_prefix_5F_map_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_prefix_5F_map_2D_element (GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_string::constructor_default (HERE),
                                          GALGAS_string::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element GALGAS_prefix_5F_map_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_string & inOperand1,
                                                                                  const GALGAS_string & inOperand2 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_prefix_5F_map_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_prefix_5F_map_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_prefix_5F_map_2D_element::objectCompare (const GALGAS_prefix_5F_map_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_prefix.objectCompare (inOperand.mAttribute_prefix) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_tag_5F_to_5F_rep.objectCompare (inOperand.mAttribute_tag_5F_to_5F_rep) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_prefix_5F_map_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_prefix.isValid () && mAttribute_tag_5F_to_5F_rep.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_prefix.drop () ;
  mAttribute_tag_5F_to_5F_rep.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @prefix_map-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_prefix.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_tag_5F_to_5F_rep.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_prefix_5F_map_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_prefix_5F_map_2D_element::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mAttribute_prefix ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_prefix_5F_map_2D_element::getter_tag_5F_to_5F_rep (UNUSED_LOCATION_ARGS) const {
  return mAttribute_tag_5F_to_5F_rep ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @prefix_map-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefix_5F_map_2D_element ("prefix_map-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_prefix_5F_map_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefix_5F_map_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_prefix_5F_map_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefix_5F_map_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element GALGAS_prefix_5F_map_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_prefix_5F_map_2D_element result ;
  const GALGAS_prefix_5F_map_2D_element * p = (const GALGAS_prefix_5F_map_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefix_5F_map_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefix_map-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element::GALGAS_stringset_5F_map_2D_element (void) :
mAttribute_lkey (),
mAttribute_ids () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element::~ GALGAS_stringset_5F_map_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element::GALGAS_stringset_5F_map_2D_element (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_stringset & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_ids (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element GALGAS_stringset_5F_map_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_stringset_5F_map_2D_element (GALGAS_lstring::constructor_default (HERE),
                                             GALGAS_stringset::constructor_emptySet (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element GALGAS_stringset_5F_map_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                        const GALGAS_stringset & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringset_5F_map_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_stringset_5F_map_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_stringset_5F_map_2D_element::objectCompare (const GALGAS_stringset_5F_map_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_ids.objectCompare (inOperand.mAttribute_ids) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_stringset_5F_map_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_ids.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringset_5F_map_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_ids.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringset_5F_map_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @stringset_map-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_ids.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_stringset_5F_map_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset GALGAS_stringset_5F_map_2D_element::getter_ids (UNUSED_LOCATION_ARGS) const {
  return mAttribute_ids ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             @stringset_map-element type                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringset_5F_map_2D_element ("stringset_map-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringset_5F_map_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringset_5F_map_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringset_5F_map_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringset_5F_map_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element GALGAS_stringset_5F_map_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_stringset_5F_map_2D_element result ;
  const GALGAS_stringset_5F_map_2D_element * p = (const GALGAS_stringset_5F_map_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringset_5F_map_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringset_map-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element::GALGAS_ident_5F_list_2D_element (void) :
mAttribute_obj_5F_name () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element::~ GALGAS_ident_5F_list_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element::GALGAS_ident_5F_list_2D_element (const GALGAS_lstring & inOperand0) :
mAttribute_obj_5F_name (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element GALGAS_ident_5F_list_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_ident_5F_list_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element GALGAS_ident_5F_list_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_ident_5F_list_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_ident_5F_list_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_ident_5F_list_2D_element::objectCompare (const GALGAS_ident_5F_list_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_obj_5F_name.objectCompare (inOperand.mAttribute_obj_5F_name) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_ident_5F_list_2D_element::isValid (void) const {
  return mAttribute_obj_5F_name.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_2D_element::drop (void) {
  mAttribute_obj_5F_name.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @ident_list-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_obj_5F_name.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_ident_5F_list_2D_element::getter_obj_5F_name (UNUSED_LOCATION_ARGS) const {
  return mAttribute_obj_5F_name ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @ident_list-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list_2D_element ("ident_list-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_ident_5F_list_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_ident_5F_list_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element GALGAS_ident_5F_list_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_2D_element result ;
  const GALGAS_ident_5F_list_2D_element * p = (const GALGAS_ident_5F_list_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element::GALGAS_ident_5F_list_5F_map_2D_element (void) :
mAttribute_lkey (),
mAttribute_objs () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element::~ GALGAS_ident_5F_list_5F_map_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element::GALGAS_ident_5F_list_5F_map_2D_element (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_ident_5F_list & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_objs (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element GALGAS_ident_5F_list_5F_map_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_ident_5F_list_5F_map_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                 GALGAS_ident_5F_list::constructor_emptyList (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element GALGAS_ident_5F_list_5F_map_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                const GALGAS_ident_5F_list & inOperand1 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_ident_5F_list_5F_map_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_ident_5F_list_5F_map_2D_element::objectCompare (const GALGAS_ident_5F_list_5F_map_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_objs.objectCompare (inOperand.mAttribute_objs) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_ident_5F_list_5F_map_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_objs.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_5F_map_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_objs.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_5F_map_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @ident_list_map-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_objs.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_ident_5F_list_5F_map_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list GALGAS_ident_5F_list_5F_map_2D_element::getter_objs (UNUSED_LOCATION_ARGS) const {
  return mAttribute_objs ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            @ident_list_map-element type                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list_5F_map_2D_element ("ident_list_map-element",
                                                        NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_ident_5F_list_5F_map_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list_5F_map_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_ident_5F_list_5F_map_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list_5F_map_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element GALGAS_ident_5F_list_5F_map_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map_2D_element result ;
  const GALGAS_ident_5F_list_5F_map_2D_element * p = (const GALGAS_ident_5F_list_5F_map_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list_5F_map_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list_map-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element::GALGAS_objectKindMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_attributes () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element::~ GALGAS_objectKindMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element::GALGAS_objectKindMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_objectAttributes & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_attributes (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element GALGAS_objectKindMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_objectKindMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_objectAttributes::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element GALGAS_objectKindMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_objectAttributes & inOperand1 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectKindMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_objectKindMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_objectKindMap_2D_element::objectCompare (const GALGAS_objectKindMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_attributes.objectCompare (inOperand.mAttribute_attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_objectKindMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_attributes.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKindMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_attributes.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKindMap_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @objectKindMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_attributes.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_objectKindMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectAttributes GALGAS_objectKindMap_2D_element::getter_attributes (UNUSED_LOCATION_ARGS) const {
  return mAttribute_attributes ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             @objectKindMap-element type                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectKindMap_2D_element ("objectKindMap-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectKindMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKindMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectKindMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectKindMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element GALGAS_objectKindMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_objectKindMap_2D_element result ;
  const GALGAS_objectKindMap_2D_element * p = (const GALGAS_objectKindMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectKindMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectKindMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element::GALGAS_objectsMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_objectsOfKind () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element::~ GALGAS_objectsMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element::GALGAS_objectsMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_objectKind & inOperand1) :
mAttribute_lkey (inOperand0),
mAttribute_objectsOfKind (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element GALGAS_objectsMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_objectsMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_objectKind::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element GALGAS_objectsMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_objectKind & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectsMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_objectsMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_objectsMap_2D_element::objectCompare (const GALGAS_objectsMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_objectsOfKind.objectCompare (inOperand.mAttribute_objectsOfKind) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_objectsMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_objectsOfKind.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectsMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_objectsOfKind.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectsMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @objectsMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_objectsOfKind.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_objectsMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKind GALGAS_objectsMap_2D_element::getter_objectsOfKind (UNUSED_LOCATION_ARGS) const {
  return mAttribute_objectsOfKind ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              @objectsMap-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectsMap_2D_element ("objectsMap-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectsMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectsMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectsMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectsMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element GALGAS_objectsMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_objectsMap_2D_element result ;
  const GALGAS_objectsMap_2D_element * p = (const GALGAS_objectsMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectsMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectsMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tfunction::GALGAS_Tfunction (void) :
mAttribute_name (),
mAttribute_args (),
mAttribute_content () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tfunction::~ GALGAS_Tfunction (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tfunction::GALGAS_Tfunction (const GALGAS_lstring & inOperand0,
                                    const GALGAS_lstringlist & inOperand1,
                                    const GALGAS_string & inOperand2) :
mAttribute_name (inOperand0),
mAttribute_args (inOperand1),
mAttribute_content (inOperand2) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tfunction GALGAS_Tfunction::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_Tfunction (GALGAS_lstring::constructor_default (HERE),
                           GALGAS_lstringlist::constructor_emptyList (HERE),
                           GALGAS_string::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tfunction GALGAS_Tfunction::constructor_new (const GALGAS_lstring & inOperand0,
                                                    const GALGAS_lstringlist & inOperand1,
                                                    const GALGAS_string & inOperand2 
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tfunction result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_Tfunction (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_Tfunction::objectCompare (const GALGAS_Tfunction & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_name.objectCompare (inOperand.mAttribute_name) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_args.objectCompare (inOperand.mAttribute_args) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_content.objectCompare (inOperand.mAttribute_content) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_Tfunction::isValid (void) const {
  return mAttribute_name.isValid () && mAttribute_args.isValid () && mAttribute_content.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_Tfunction::drop (void) {
  mAttribute_name.drop () ;
  mAttribute_args.drop () ;
  mAttribute_content.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_Tfunction::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "<struct @Tfunction:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_name.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_args.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_content.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_Tfunction::getter_name (UNUSED_LOCATION_ARGS) const {
  return mAttribute_name ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_Tfunction::getter_args (UNUSED_LOCATION_ARGS) const {
  return mAttribute_args ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_Tfunction::getter_content (UNUSED_LOCATION_ARGS) const {
  return mAttribute_content ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   @Tfunction type                                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_Tfunction ("Tfunction",
                                  NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_Tfunction::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_Tfunction ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_Tfunction::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_Tfunction (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tfunction GALGAS_Tfunction::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_Tfunction result ;
  const GALGAS_Tfunction * p = (const GALGAS_Tfunction *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_Tfunction *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("Tfunction", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                               Extension getter '@applicationDefinition templateData'                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <enterExtensionGetter_applicationDefinition_templateData> gExtensionGetterTable_applicationDefinition_templateData ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionGetter_templateData (const int32_t inClassIndex,
                                        enterExtensionGetter_applicationDefinition_templateData inGetter) {
  gExtensionGetterTable_applicationDefinition_templateData.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMap callExtensionGetter_templateData (const cPtr_applicationDefinition * inObject,
                                                   const GALGAS_implementation & in_imp,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  GALGAS_TfieldMap result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_applicationDefinition) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_applicationDefinition_templateData f = NULL ;
    if (classIndex < gExtensionGetterTable_applicationDefinition_templateData.count ()) {
      f = gExtensionGetterTable_applicationDefinition_templateData (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_applicationDefinition_templateData.count ()) {
           f = gExtensionGetterTable_applicationDefinition_templateData (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_applicationDefinition_templateData.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_imp, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_TfieldMap extensionGetter_applicationDefinition_templateData (const cPtr_applicationDefinition * inObject,
                                                                            const GALGAS_implementation & constinArgument_imp,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TfieldMap result_cfg ; // Returned variable
  const cPtr_applicationDefinition * object = inObject ;
  macroValidSharedObject (object, cPtr_applicationDefinition) ;
  result_cfg = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 158)) ;
  {
  routine_addStringValue (result_cfg, function_lstringWith (GALGAS_string ("OILFILENAME"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 164)), GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 164)).getter_lastPathComponent (SOURCE_FILE ("systemConfig.galgas", 164)), function_lstringWith (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 164)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 164)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 164)) ;
  }
  {
  routine_addLStringValue (result_cfg, GALGAS_string ("CPUNAME"), object->mAttribute_name, function_lstringWith (GALGAS_string ("name of the CPU object"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 165)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 165)) ;
  }
  {
  routine_addLStringValue (result_cfg, GALGAS_string ("CPUDESCRIPTION"), object->mAttribute_cpuDescription, function_lstringWith (GALGAS_string ("description of the CPU object"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 166)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 166)) ;
  }
  {
  routine_addLStringValue (result_cfg, GALGAS_string ("OILVERSION"), object->mAttribute_version, function_lstringWith (GALGAS_string ("OIL version"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 167)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 167)) ;
  }
  {
  routine_addLStringValue (result_cfg, GALGAS_string ("OILDESCRIPTION"), object->mAttribute_versionDescription, function_lstringWith (GALGAS_string ("OIL version description"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 168)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 168)) ;
  }
  {
  routine_addStringValue (result_cfg, function_lstringWith (GALGAS_string ("TIMESTAMP"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 169)), GALGAS_string::constructor_stringWithCurrentDateTime (SOURCE_FILE ("systemConfig.galgas", 169)), function_lstringWith (GALGAS_string ("timestamp of OIL compiling"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 169)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 169)) ;
  }
  {
  routine_addStringValue (result_cfg, function_lstringWith (GALGAS_string ("PROJECT"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 170)), function_projectName (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 170)).getter_lastPathComponent (SOURCE_FILE ("systemConfig.galgas", 170)), function_lstringWith (GALGAS_string ("project name"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 170)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 170)) ;
  }
  {
  routine_addStringValue (result_cfg, function_lstringWith (GALGAS_string ("TARGET"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 171)), GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()), function_lstringWith (GALGAS_string ("target architecture/chip/board"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 171)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 171)) ;
  }
  {
  routine_addStringValue (result_cfg, function_lstringWith (GALGAS_string ("TEMPLATEPATH"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 172)), GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ()), function_lstringWith (GALGAS_string ("path of the templates used"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 172)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 172)) ;
  }
  {
  routine_addStringValue (result_cfg, function_lstringWith (GALGAS_string ("ARCH"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 173)), function_arch (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 173)), function_lstringWith (GALGAS_string ("target architecture"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 173)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 173)) ;
  }
  {
  routine_addStringValue (result_cfg, function_lstringWith (GALGAS_string ("CHIP"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 174)), function_chip (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 174)), function_lstringWith (GALGAS_string ("target chip"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 174)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 174)) ;
  }
  {
  routine_addStringValue (result_cfg, function_lstringWith (GALGAS_string ("BOARD"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 175)), function_board (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 175)), function_lstringWith (GALGAS_string ("target board"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 175)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 175)) ;
  }
  {
  routine_addListValue (result_cfg, function_lstringWith (GALGAS_string ("TARGETPATHLIST"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 176)), function_targetPathList (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 176)), function_lstringWith (GALGAS_string ("target path list"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 176)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 176)) ;
  }
  {
  routine_addBoolValue (result_cfg, function_lstringWith (GALGAS_string ("LOGFILE"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 178)), GALGAS_bool (gOption_goil_5F_options_generate_5F_log.getter_value ()), function_lstringWith (GALGAS_string ("Generated a logfile"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 178)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 178)) ;
  }
  GALGAS_TfieldMap var_opts_6624 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 181)) ;
  GALGAS_string var_optionString_6659 = extensionGetter_trimRight (extensionGetter_trimLeft (GALGAS_string (gOption_goil_5F_options_passOption.getter_value ()), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 182)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 182)) ;
  GALGAS_bool test_0 = GALGAS_bool (kIsStrictSup, var_optionString_6659.getter_length (SOURCE_FILE ("systemConfig.galgas", 183)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    test_0 = GALGAS_bool (gOption_goil_5F_options_pierreOption.getter_value ()) ;
  }
  const enumGalgasBool test_1 = test_0.boolEnum () ;
  if (kBoolTrue == test_1) {
    var_opts_6624.drop () ;
    cGrammar_options_5F_grammar::_performSourceStringParsing_ (inCompiler, GALGAS_string (gOption_goil_5F_options_passOption.getter_value ()), GALGAS_string ("Passed options"), var_opts_6624  COMMA_SOURCE_FILE ("systemConfig.galgas", 184)) ;
  }
  {
  routine_addStructValue (result_cfg, function_lstringWith (GALGAS_string ("PASSEDOPTIONS"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 186)), var_opts_6624, function_lstringWith (GALGAS_string ("Passed options from command line"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 186)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 186)) ;
  }
  cEnumerator_objectsMap enumerator_7037 (object->mAttribute_objects, kEnumeration_up) ;
  while (enumerator_7037.hasCurrentObject ()) {
    GALGAS_implementationObject var_implementationObject_7255 ;
    constinArgument_imp.getter_imp (SOURCE_FILE ("systemConfig.galgas", 193)).method_get (enumerator_7037.current_lkey (HERE), var_implementationObject_7255, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 193)) ;
    const enumGalgasBool test_2 = var_implementationObject_7255.getter_multiple (SOURCE_FILE ("systemConfig.galgas", 194)).getter_bool (SOURCE_FILE ("systemConfig.galgas", 194)).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_TfieldMapList var_objs_7369 = GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("systemConfig.galgas", 195)) ;
      cEnumerator_objectKindMap enumerator_7438 (enumerator_7037.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("systemConfig.galgas", 196)), kEnumeration_up) ;
      while (enumerator_7438.hasCurrentObject ()) {
        GALGAS_TfieldMap var_attrs_7466 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) enumerator_7438.current_attributes (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 197)) ;
        var_objs_7369.addAssign_operation (var_attrs_7466  COMMA_SOURCE_FILE ("systemConfig.galgas", 198)) ;
        enumerator_7438.gotoNextObject () ;
      }
      {
      routine_addListValue (result_cfg, enumerator_7037.current_lkey (HERE), var_objs_7369, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 200)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 200)) ;
      }
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, enumerator_7037.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("systemConfig.galgas", 203)).getter_count (SOURCE_FILE ("systemConfig.galgas", 203)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
      if (kBoolTrue == test_3) {
        GALGAS_TfieldMap var_attrs_7688 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 204)) ;
        cEnumerator_objectKindMap enumerator_7754 (enumerator_7037.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("systemConfig.galgas", 205)), kEnumeration_up) ;
        while (enumerator_7754.hasCurrentObject ()) {
          var_attrs_7688 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) enumerator_7754.current_attributes (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 206)) ;
          enumerator_7754.gotoNextObject () ;
        }
        {
        routine_addStructValue (result_cfg, enumerator_7037.current_lkey (HERE), var_attrs_7688, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 208)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 208)) ;
        }
      }
    }
    enumerator_7037.gotoNextObject () ;
  }
//---
  return result_cfg ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_applicationDefinition_templateData (void) {
  enterExtensionGetter_templateData (kTypeDescriptor_GALGAS_applicationDefinition.mSlotID,
                                     extensionGetter_applicationDefinition_templateData) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionGetter_applicationDefinition_templateData (void) {
  gExtensionGetterTable_applicationDefinition_templateData.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_applicationDefinition_templateData (defineExtensionGetter_applicationDefinition_templateData,
                                                               freeExtensionGetter_applicationDefinition_templateData) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Extension method '@objectKind verifyCrossReferences'                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionMethodSignature_objectKind_verifyCrossReferences> gExtensionMethodTable_objectKind_verifyCrossReferences ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_objectKind_verifyCrossReferences inMethod) {
  gExtensionMethodTable_objectKind_verifyCrossReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (const cPtr_objectKind * inObject,
                                                const GALGAS_objectsMap constin_allObjects,
                                                const GALGAS_implementationObject constin_obj,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_objectKind) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_objectKind_verifyCrossReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_objectKind_verifyCrossReferences.count ()) {
      f = gExtensionMethodTable_objectKind_verifyCrossReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_objectKind_verifyCrossReferences.count ()) {
           f = gExtensionMethodTable_objectKind_verifyCrossReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_objectKind_verifyCrossReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_allObjects, constin_obj, inCompiler COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_objectKind_verifyCrossReferences (const cPtr_objectKind * inObject,
                                                              const GALGAS_objectsMap constinArgument_allObjects,
                                                              const GALGAS_implementationObject constinArgument_obj,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectKind * object = inObject ;
  macroValidSharedObject (object, cPtr_objectKind) ;
  cEnumerator_objectKindMap enumerator_18395 (object->mAttribute_objects, kEnumeration_up) ;
  while (enumerator_18395.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) enumerator_18395.current_attributes (HERE).ptr (), constinArgument_allObjects, constinArgument_obj.getter_attributes (SOURCE_FILE ("semantic_verification.galgas", 590)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 590)) ;
    enumerator_18395.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_objectKind_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_objectKind.mSlotID,
                                              extensionMethod_objectKind_verifyCrossReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionMethod_objectKind_verifyCrossReferences (void) {
  gExtensionMethodTable_objectKind_verifyCrossReferences.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_objectKind_verifyCrossReferences (defineExtensionMethod_objectKind_verifyCrossReferences,
                                                             freeExtensionMethod_objectKind_verifyCrossReferences) ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue::GALGAS_Tvalue (void) :
mAttribute_mBigIntValue (),
mAttribute_mFloatValue (),
mAttribute_mStringValue (),
mAttribute_mMapListValue (),
mAttribute_mStructValue (),
mAttribute_mFunctionValue (),
mAttribute_mDescription () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue::~ GALGAS_Tvalue (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue::GALGAS_Tvalue (const GALGAS_bigint & inOperand0,
                              const GALGAS_double & inOperand1,
                              const GALGAS_string & inOperand2,
                              const GALGAS_TfieldMapList & inOperand3,
                              const GALGAS_TfieldMap & inOperand4,
                              const GALGAS_Tfunction & inOperand5,
                              const GALGAS_lstring & inOperand6) :
mAttribute_mBigIntValue (inOperand0),
mAttribute_mFloatValue (inOperand1),
mAttribute_mStringValue (inOperand2),
mAttribute_mMapListValue (inOperand3),
mAttribute_mStructValue (inOperand4),
mAttribute_mFunctionValue (inOperand5),
mAttribute_mDescription (inOperand6) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue GALGAS_Tvalue::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_Tvalue (GALGAS_bigint::constructor_zero (HERE),
                        GALGAS_double::constructor_default (HERE),
                        GALGAS_string::constructor_default (HERE),
                        GALGAS_TfieldMapList::constructor_emptyList (HERE),
                        GALGAS_TfieldMap::constructor_emptyMap (HERE),
                        GALGAS_Tfunction::constructor_default (HERE),
                        GALGAS_lstring::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue GALGAS_Tvalue::constructor_new (const GALGAS_bigint & inOperand0,
                                              const GALGAS_double & inOperand1,
                                              const GALGAS_string & inOperand2,
                                              const GALGAS_TfieldMapList & inOperand3,
                                              const GALGAS_TfieldMap & inOperand4,
                                              const GALGAS_Tfunction & inOperand5,
                                              const GALGAS_lstring & inOperand6 
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid () && inOperand3.isValid () && inOperand4.isValid () && inOperand5.isValid () && inOperand6.isValid ()) {
    result = GALGAS_Tvalue (inOperand0, inOperand1, inOperand2, inOperand3, inOperand4, inOperand5, inOperand6) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_Tvalue::objectCompare (const GALGAS_Tvalue & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mBigIntValue.objectCompare (inOperand.mAttribute_mBigIntValue) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mFloatValue.objectCompare (inOperand.mAttribute_mFloatValue) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mStringValue.objectCompare (inOperand.mAttribute_mStringValue) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mMapListValue.objectCompare (inOperand.mAttribute_mMapListValue) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mStructValue.objectCompare (inOperand.mAttribute_mStructValue) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mFunctionValue.objectCompare (inOperand.mAttribute_mFunctionValue) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mDescription.objectCompare (inOperand.mAttribute_mDescription) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_Tvalue::isValid (void) const {
  return mAttribute_mBigIntValue.isValid () && mAttribute_mFloatValue.isValid () && mAttribute_mStringValue.isValid () && mAttribute_mMapListValue.isValid () && mAttribute_mStructValue.isValid () && mAttribute_mFunctionValue.isValid () && mAttribute_mDescription.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_Tvalue::drop (void) {
  mAttribute_mBigIntValue.drop () ;
  mAttribute_mFloatValue.drop () ;
  mAttribute_mStringValue.drop () ;
  mAttribute_mMapListValue.drop () ;
  mAttribute_mStructValue.drop () ;
  mAttribute_mFunctionValue.drop () ;
  mAttribute_mDescription.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_Tvalue::description (C_String & ioString,
                                 const int32_t inIndentation) const {
  ioString << "<struct @Tvalue:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mBigIntValue.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mFloatValue.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mStringValue.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mMapListValue.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mStructValue.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mFunctionValue.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mDescription.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint GALGAS_Tvalue::getter_mBigIntValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mBigIntValue ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_double GALGAS_Tvalue::getter_mFloatValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFloatValue ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_Tvalue::getter_mStringValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mStringValue ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMapList GALGAS_Tvalue::getter_mMapListValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mMapListValue ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMap GALGAS_Tvalue::getter_mStructValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mStructValue ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tfunction GALGAS_Tvalue::getter_mFunctionValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mFunctionValue ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_Tvalue::getter_mDescription (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mDescription ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                    @Tvalue type                                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_Tvalue ("Tvalue",
                               NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_Tvalue::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_Tvalue ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_Tvalue::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_Tvalue (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue GALGAS_Tvalue::extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_Tvalue result ;
  const GALGAS_Tvalue * p = (const GALGAS_Tvalue *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_Tvalue *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("Tvalue", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMap_2D_element::GALGAS_TfieldMap_2D_element (void) :
mAttribute_lkey (),
mAttribute_mType (),
mAttribute_mValue () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMap_2D_element::~ GALGAS_TfieldMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMap_2D_element::GALGAS_TfieldMap_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_Ttype & inOperand1,
                                                          const GALGAS_Tvalue & inOperand2) :
mAttribute_lkey (inOperand0),
mAttribute_mType (inOperand1),
mAttribute_mValue (inOperand2) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMap_2D_element GALGAS_TfieldMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_Ttype & inOperand1,
                                                                          const GALGAS_Tvalue & inOperand2 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TfieldMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_TfieldMap_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_TfieldMap_2D_element::objectCompare (const GALGAS_TfieldMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_lkey.objectCompare (inOperand.mAttribute_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mValue.objectCompare (inOperand.mAttribute_mValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_TfieldMap_2D_element::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_mType.isValid () && mAttribute_mValue.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TfieldMap_2D_element::drop (void) {
  mAttribute_lkey.drop () ;
  mAttribute_mType.drop () ;
  mAttribute_mValue.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TfieldMap_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @TfieldMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mType.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mValue.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_TfieldMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mAttribute_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Ttype GALGAS_TfieldMap_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue GALGAS_TfieldMap_2D_element::getter_mValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mValue ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               @TfieldMap-element type                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_TfieldMap_2D_element ("TfieldMap-element",
                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_TfieldMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_TfieldMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_TfieldMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_TfieldMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TfieldMap_2D_element GALGAS_TfieldMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_TfieldMap_2D_element result ;
  const GALGAS_TfieldMap_2D_element * p = (const GALGAS_TfieldMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_TfieldMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("TfieldMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TexpressionList_2D_element::GALGAS_TexpressionList_2D_element (void) :
mAttribute_mValue (),
mAttribute_mType () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TexpressionList_2D_element::~ GALGAS_TexpressionList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TexpressionList_2D_element::GALGAS_TexpressionList_2D_element (const GALGAS_Tvalue & inOperand0,
                                                                      const GALGAS_Ttype & inOperand1) :
mAttribute_mValue (inOperand0),
mAttribute_mType (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TexpressionList_2D_element GALGAS_TexpressionList_2D_element::constructor_new (const GALGAS_Tvalue & inOperand0,
                                                                                      const GALGAS_Ttype & inOperand1 
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TexpressionList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_TexpressionList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_TexpressionList_2D_element::objectCompare (const GALGAS_TexpressionList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mValue.objectCompare (inOperand.mAttribute_mValue) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mType.objectCompare (inOperand.mAttribute_mType) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_TexpressionList_2D_element::isValid (void) const {
  return mAttribute_mValue.isValid () && mAttribute_mType.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TexpressionList_2D_element::drop (void) {
  mAttribute_mValue.drop () ;
  mAttribute_mType.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TexpressionList_2D_element::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "<struct @TexpressionList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mValue.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue GALGAS_TexpressionList_2D_element::getter_mValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mValue ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Ttype GALGAS_TexpressionList_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mType ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            @TexpressionList-element type                                            *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_TexpressionList_2D_element ("TexpressionList-element",
                                                   NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_TexpressionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_TexpressionList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_TexpressionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_TexpressionList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TexpressionList_2D_element GALGAS_TexpressionList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_TexpressionList_2D_element result ;
  const GALGAS_TexpressionList_2D_element * p = (const GALGAS_TexpressionList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_TexpressionList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("TexpressionList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TenumationList_2D_element::GALGAS_TenumationList_2D_element (void) :
mAttribute_mEnumeratedValue (),
mAttribute_mPrefix () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TenumationList_2D_element::~ GALGAS_TenumationList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TenumationList_2D_element::GALGAS_TenumationList_2D_element (const GALGAS_Tvalue & inOperand0,
                                                                    const GALGAS_string & inOperand1) :
mAttribute_mEnumeratedValue (inOperand0),
mAttribute_mPrefix (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TenumationList_2D_element GALGAS_TenumationList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_TenumationList_2D_element (GALGAS_Tvalue::constructor_default (HERE),
                                           GALGAS_string::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TenumationList_2D_element GALGAS_TenumationList_2D_element::constructor_new (const GALGAS_Tvalue & inOperand0,
                                                                                    const GALGAS_string & inOperand1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TenumationList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_TenumationList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_TenumationList_2D_element::objectCompare (const GALGAS_TenumationList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mAttribute_mEnumeratedValue.objectCompare (inOperand.mAttribute_mEnumeratedValue) ;
  }
  if (result == kOperandEqual) {
    result = mAttribute_mPrefix.objectCompare (inOperand.mAttribute_mPrefix) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_TenumationList_2D_element::isValid (void) const {
  return mAttribute_mEnumeratedValue.isValid () && mAttribute_mPrefix.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TenumationList_2D_element::drop (void) {
  mAttribute_mEnumeratedValue.drop () ;
  mAttribute_mPrefix.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_TenumationList_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @TenumationList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mAttribute_mEnumeratedValue.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mAttribute_mPrefix.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue GALGAS_TenumationList_2D_element::getter_mEnumeratedValue (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mEnumeratedValue ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_TenumationList_2D_element::getter_mPrefix (UNUSED_LOCATION_ARGS) const {
  return mAttribute_mPrefix ;
}



//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            @TenumationList-element type                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_TenumationList_2D_element ("TenumationList-element",
                                                  NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_TenumationList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_TenumationList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_TenumationList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_TenumationList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_TenumationList_2D_element GALGAS_TenumationList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_TenumationList_2D_element result ;
  const GALGAS_TenumationList_2D_element * p = (const GALGAS_TenumationList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_TenumationList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("TenumationList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Overriding extension method '@noRange enclose'                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_noRange_enclose (const cPtr_attributeRange * /* inObject */,
                                             GALGAS_bool & outArgument_isWithin,
                                             const GALGAS_attributeRange /* constinArgument_value */,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_isWithin = GALGAS_bool (true) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_noRange_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_noRange.mSlotID,
                                extensionMethod_noRange_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_noRange_enclose (defineExtensionMethod_noRange_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                              Overriding extension method '@uint32AttributeSet enclose'                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_uint_33__32_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32_AttributeSet * object = (const cPtr_uint_33__32_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_4277_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_33__32_List enumerator_4315 (cast_4277_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 155)), kEnumeration_up) ;
      while (enumerator_4315.hasCurrentObject ()) {
        GALGAS_bool var_ok_4333 = GALGAS_bool (false) ;
        cEnumerator_uint_33__32_List enumerator_4374 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_4374.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_4315.current_value (HERE).objectCompare (enumerator_4374.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_4333 = GALGAS_bool (true) ;
          }
          enumerator_4374.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_4333 COMMA_SOURCE_FILE ("implementation_types.galgas", 162)) ;
        enumerator_4315.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 165)), GALGAS_string ("Incompatible set. Should be a UINT32 set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 165)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 166)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_uint_33__32_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_33__32_AttributeSet.mSlotID,
                                extensionMethod_uint_33__32_AttributeSet_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_uint_33__32_AttributeSet_enclose (defineExtensionMethod_uint_33__32_AttributeSet_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                              Overriding extension method '@uint64AttributeSet enclose'                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_uint_36__34_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34_AttributeSet * object = (const cPtr_uint_36__34_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_4888_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_uint_36__34_List enumerator_4926 (cast_4888_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 179)), kEnumeration_up) ;
      while (enumerator_4926.hasCurrentObject ()) {
        GALGAS_bool var_ok_4944 = GALGAS_bool (false) ;
        cEnumerator_uint_36__34_List enumerator_4985 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_4985.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_4926.current_value (HERE).objectCompare (enumerator_4985.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_4944 = GALGAS_bool (true) ;
          }
          enumerator_4985.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_4944 COMMA_SOURCE_FILE ("implementation_types.galgas", 186)) ;
        enumerator_4926.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 189)), GALGAS_string ("Incompatible set. Should be a UINT64 set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 189)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 190)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_uint_36__34_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_36__34_AttributeSet.mSlotID,
                                extensionMethod_uint_36__34_AttributeSet_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_uint_36__34_AttributeSet_enclose (defineExtensionMethod_uint_36__34_AttributeSet_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                              Overriding extension method '@sint32AttributeSet enclose'                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_sint_33__32_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32_AttributeSet * object = (const cPtr_sint_33__32_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_5499_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_33__32_List enumerator_5537 (cast_5499_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 203)), kEnumeration_up) ;
      while (enumerator_5537.hasCurrentObject ()) {
        GALGAS_bool var_ok_5555 = GALGAS_bool (false) ;
        cEnumerator_sint_33__32_List enumerator_5596 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_5596.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_5537.current_value (HERE).objectCompare (enumerator_5596.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_5555 = GALGAS_bool (true) ;
          }
          enumerator_5596.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_5555 COMMA_SOURCE_FILE ("implementation_types.galgas", 210)) ;
        enumerator_5537.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 213)), GALGAS_string ("Incompatible set. Should be a INT32 set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 213)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 214)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_sint_33__32_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_33__32_AttributeSet.mSlotID,
                                extensionMethod_sint_33__32_AttributeSet_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_sint_33__32_AttributeSet_enclose (defineExtensionMethod_sint_33__32_AttributeSet_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                              Overriding extension method '@sint64AttributeSet enclose'                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_sint_36__34_AttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                              GALGAS_bool & outArgument_isWithin,
                                                              const GALGAS_attributeRange constinArgument_value,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34_AttributeSet * object = (const cPtr_sint_36__34_AttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34_AttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_6109_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_sint_36__34_List enumerator_6147 (cast_6109_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 227)), kEnumeration_up) ;
      while (enumerator_6147.hasCurrentObject ()) {
        GALGAS_bool var_ok_6165 = GALGAS_bool (false) ;
        cEnumerator_sint_36__34_List enumerator_6206 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_6206.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_6147.current_value (HERE).objectCompare (enumerator_6206.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_6165 = GALGAS_bool (true) ;
          }
          enumerator_6206.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6165 COMMA_SOURCE_FILE ("implementation_types.galgas", 234)) ;
        enumerator_6147.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 237)), GALGAS_string ("Incompatible set. Should be a INT64 set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 237)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 238)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_sint_36__34_AttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_36__34_AttributeSet.mSlotID,
                                extensionMethod_sint_36__34_AttributeSet_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_sint_36__34_AttributeSet_enclose (defineExtensionMethod_sint_36__34_AttributeSet_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                              Overriding extension method '@floatAttributeSet enclose'                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_floatAttributeSet_enclose (const cPtr_attributeRange * inObject,
                                                       GALGAS_bool & outArgument_isWithin,
                                                       const GALGAS_attributeRange constinArgument_value,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_floatAttributeSet * object = (const cPtr_floatAttributeSet *) inObject ;
  macroValidSharedObject (object, cPtr_floatAttributeSet) ;
  outArgument_isWithin = GALGAS_bool (true) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_6717_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      cEnumerator_floatList enumerator_6755 (cast_6717_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 251)), kEnumeration_up) ;
      while (enumerator_6755.hasCurrentObject ()) {
        GALGAS_bool var_ok_6773 = GALGAS_bool (false) ;
        cEnumerator_floatList enumerator_6814 (object->mAttribute_valueList, kEnumeration_up) ;
        while (enumerator_6814.hasCurrentObject ()) {
          const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_6755.current_value (HERE).objectCompare (enumerator_6814.current_value (HERE))).boolEnum () ;
          if (kBoolTrue == test_0) {
            var_ok_6773 = GALGAS_bool (true) ;
          }
          enumerator_6814.gotoNextObject () ;
        }
        outArgument_isWithin = outArgument_isWithin.operator_and (var_ok_6773 COMMA_SOURCE_FILE ("implementation_types.galgas", 258)) ;
        enumerator_6755.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 261)), GALGAS_string ("Incompatible set. Should be a FLOAT set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 261)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 262)) ;
      outArgument_isWithin = GALGAS_bool (false) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_floatAttributeSet_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_floatAttributeSet.mSlotID,
                                extensionMethod_floatAttributeSet_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_floatAttributeSet_enclose (defineExtensionMethod_floatAttributeSet_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                            Overriding extension method '@uint32AttributeMinMax enclose'                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_uint_33__32_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32_AttributeMinMax * object = (const cPtr_uint_33__32_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax) {
      GALGAS_uint_33__32_AttributeMinMax cast_7340_minmax ((cPtr_uint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_7340_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 276)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_7340_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 276)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 276)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32_AttributeSet) {
      GALGAS_uint_33__32_AttributeSet cast_7460_set ((cPtr_uint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_33__32_List enumerator_7513 (cast_7460_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 281)), kEnumeration_up) ;
      while (enumerator_7513.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_7513.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_7513.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 282)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_7513.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 287)), GALGAS_string ("Incompatible set. Should be a UINT32 range or UINT32 set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 287)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 288)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_uint_33__32_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_33__32_AttributeMinMax.mSlotID,
                                extensionMethod_uint_33__32_AttributeMinMax_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_uint_33__32_AttributeMinMax_enclose (defineExtensionMethod_uint_33__32_AttributeMinMax_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                            Overriding extension method '@uint64AttributeMinMax enclose'                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_uint_36__34_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34_AttributeMinMax * object = (const cPtr_uint_36__34_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax) {
      GALGAS_uint_36__34_AttributeMinMax cast_7999_minmax ((cPtr_uint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_7999_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 301)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_7999_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 301)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 301)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34_AttributeSet) {
      GALGAS_uint_36__34_AttributeSet cast_8119_set ((cPtr_uint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_uint_36__34_List enumerator_8172 (cast_8119_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 306)), kEnumeration_up) ;
      while (enumerator_8172.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_8172.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8172.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 307)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_8172.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 312)), GALGAS_string ("Incompatible set. Should be a UINT64 range or UINT64 set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 312)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 313)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_uint_36__34_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_uint_36__34_AttributeMinMax.mSlotID,
                                extensionMethod_uint_36__34_AttributeMinMax_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_uint_36__34_AttributeMinMax_enclose (defineExtensionMethod_uint_36__34_AttributeMinMax_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                            Overriding extension method '@sint32AttributeMinMax enclose'                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_sint_33__32_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32_AttributeMinMax * object = (const cPtr_sint_33__32_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax) {
      GALGAS_sint_33__32_AttributeMinMax cast_8654_minmax ((cPtr_sint_33__32_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_8654_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 326)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_8654_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 326)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 326)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32_AttributeSet) {
      GALGAS_sint_33__32_AttributeSet cast_8774_set ((cPtr_sint_33__32_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_33__32_List enumerator_8827 (cast_8774_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 331)), kEnumeration_up) ;
      while (enumerator_8827.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_8827.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_8827.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 332)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_8827.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 337)), GALGAS_string ("Incompatible set. Should be a INT32 range or INT32 set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 337)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 338)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_sint_33__32_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_33__32_AttributeMinMax.mSlotID,
                                extensionMethod_sint_33__32_AttributeMinMax_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_sint_33__32_AttributeMinMax_enclose (defineExtensionMethod_sint_33__32_AttributeMinMax_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                            Overriding extension method '@sint64AttributeMinMax enclose'                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_sint_36__34_AttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                                 GALGAS_bool & outArgument_isWithin,
                                                                 const GALGAS_attributeRange constinArgument_value,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34_AttributeMinMax * object = (const cPtr_sint_36__34_AttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34_AttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax) {
      GALGAS_sint_36__34_AttributeMinMax cast_9311_minmax ((cPtr_sint_36__34_AttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_9311_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 351)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9311_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 351)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 351)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34_AttributeSet) {
      GALGAS_sint_36__34_AttributeSet cast_9431_set ((cPtr_sint_36__34_AttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_sint_36__34_List enumerator_9484 (cast_9431_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 356)), kEnumeration_up) ;
      while (enumerator_9484.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_9484.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_9484.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 357)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_9484.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 362)), GALGAS_string ("Incompatible set. Should be a INT64 range or INT64 set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 362)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 363)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_sint_36__34_AttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_sint_36__34_AttributeMinMax.mSlotID,
                                extensionMethod_sint_36__34_AttributeMinMax_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_sint_36__34_AttributeMinMax_enclose (defineExtensionMethod_sint_36__34_AttributeMinMax_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                             Overriding extension method '@floatAttributeMinMax enclose'                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_floatAttributeMinMax_enclose (const cPtr_attributeRange * inObject,
                                                          GALGAS_bool & outArgument_isWithin,
                                                          const GALGAS_attributeRange constinArgument_value,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_floatAttributeMinMax * object = (const cPtr_floatAttributeMinMax *) inObject ;
  macroValidSharedObject (object, cPtr_floatAttributeMinMax) ;
  outArgument_isWithin = GALGAS_bool (false) ;
  if (constinArgument_value.isValid ()) {
    if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeMinMax) {
      GALGAS_floatAttributeMinMax cast_9966_minmax ((cPtr_floatAttributeMinMax *) constinArgument_value.ptr ()) ;
      const enumGalgasBool test_0 = GALGAS_bool (kIsSupOrEqual, cast_9966_minmax.getter_min (SOURCE_FILE ("implementation_types.galgas", 376)).objectCompare (object->mAttribute_min)).operator_and (GALGAS_bool (kIsInfOrEqual, cast_9966_minmax.getter_max (SOURCE_FILE ("implementation_types.galgas", 376)).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 376)).boolEnum () ;
      if (kBoolTrue == test_0) {
        outArgument_isWithin = GALGAS_bool (true) ;
      }
    }else if (constinArgument_value.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_floatAttributeSet) {
      GALGAS_floatAttributeSet cast_10085_set ((cPtr_floatAttributeSet *) constinArgument_value.ptr ()) ;
      outArgument_isWithin = GALGAS_bool (true) ;
      cEnumerator_floatList enumerator_10138 (cast_10085_set.getter_valueList (SOURCE_FILE ("implementation_types.galgas", 381)), kEnumeration_up) ;
      while (enumerator_10138.hasCurrentObject ()) {
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictInf, enumerator_10138.current_value (HERE).objectCompare (object->mAttribute_min)).operator_or (GALGAS_bool (kIsStrictSup, enumerator_10138.current_value (HERE).objectCompare (object->mAttribute_max)) COMMA_SOURCE_FILE ("implementation_types.galgas", 382)).boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_isWithin = GALGAS_bool (false) ;
        }
        enumerator_10138.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_value.getter_location (SOURCE_FILE ("implementation_types.galgas", 387)), GALGAS_string ("Incompatible set. Should be a FLOAT range or FLOAT set")  COMMA_SOURCE_FILE ("implementation_types.galgas", 387)) ;
      inCompiler->emitSemanticError (object->mAttribute_location, GALGAS_string ("Previous set was declared here")  COMMA_SOURCE_FILE ("implementation_types.galgas", 388)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_floatAttributeMinMax_enclose (void) {
  enterExtensionMethod_enclose (kTypeDescriptor_GALGAS_floatAttributeMinMax.mSlotID,
                                extensionMethod_floatAttributeMinMax_enclose) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_floatAttributeMinMax_enclose (defineExtensionMethod_floatAttributeMinMax_enclose, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                             Overriding extension getter '@impStructType mergeWithType'                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_impType extensionGetter_impStructType_mergeWithType (const cPtr_impType * inObject,
                                                                   GALGAS_impType inArgument_typeToMerge,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impStructType * object = (const cPtr_impStructType *) inObject ;
  macroValidSharedObject (object, cPtr_impStructType) ;
  GALGAS_impStructType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impStructType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impStructType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 441)) ;
    }
  }
  GALGAS_impStructType var_castTypeToMerge_12033 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedAttributes_12109 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 442)) ;
  cEnumerator_implementationObjectMap enumerator_12150 (object->mAttribute_structAttributes, kEnumeration_up) ;
  while (enumerator_12150.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_12177 = enumerator_12150.current_type (HERE) ;
    const enumGalgasBool test_1 = var_castTypeToMerge_12033.getter_structAttributes (SOURCE_FILE ("implementation_types.galgas", 445)).getter_hasKey (enumerator_12150.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 445)) COMMA_SOURCE_FILE ("implementation_types.galgas", 445)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_subTypeToMerge_12332 ;
      var_castTypeToMerge_12033.getter_structAttributes (SOURCE_FILE ("implementation_types.galgas", 446)).method_get (enumerator_12150.current_lkey (HERE), var_subTypeToMerge_12332, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 446)) ;
      var_mergedAttr_12177 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_12150.current_type (HERE).ptr (), var_subTypeToMerge_12332, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 447)) ;
    }
    {
    var_mergedAttributes_12109.setter_put (enumerator_12150.current_lkey (HERE), var_mergedAttr_12177, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 449)) ;
    }
    enumerator_12150.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impStructType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 452)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 452)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 456)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 456)), var_mergedAttributes_12109  COMMA_SOURCE_FILE ("implementation_types.galgas", 451)) ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_impStructType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impStructType.mSlotID,
                                      extensionGetter_impStructType_mergeWithType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_impStructType_mergeWithType (defineExtensionGetter_impStructType_mergeWithType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Overriding extension getter '@impVoid mergeWithType'                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_impType extensionGetter_impVoid_mergeWithType (const cPtr_impType * inObject,
                                                             GALGAS_impType /* inArgument_typeToMerge */,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impVoid * object = (const cPtr_impVoid *) inObject ;
  macroValidSharedObject (object, cPtr_impVoid) ;
  const GALGAS_impVoid temp_0 = object ;
  result_mergedType = temp_0 ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_impVoid_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impVoid.mSlotID,
                                      extensionGetter_impVoid_mergeWithType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_impVoid_mergeWithType (defineExtensionGetter_impVoid_mergeWithType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                           Overriding extension getter '@impAutoDefaultType mergeWithType'                           *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_impType extensionGetter_impAutoDefaultType_mergeWithType (const cPtr_impType * inObject,
                                                                        GALGAS_impType /* inArgument_typeToMerge */,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  const GALGAS_impAutoDefaultType temp_0 = object ;
  result_mergedType = temp_0 ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_impAutoDefaultType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                      extensionGetter_impAutoDefaultType_mergeWithType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_impAutoDefaultType_mergeWithType (defineExtensionGetter_impAutoDefaultType_mergeWithType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                            Overriding extension getter '@impAutoDefaultType autoAllowed'                            *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_bool extensionGetter_impAutoDefaultType_autoAllowed (const cPtr_impType * inObject,
                                                                   C_Compiler * /* inCompiler */
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  result_result = object->mAttribute_withAuto ;
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_impAutoDefaultType_autoAllowed (void) {
  enterExtensionGetter_autoAllowed (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                    extensionGetter_impAutoDefaultType_autoAllowed) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_impAutoDefaultType_autoAllowed (defineExtensionGetter_impAutoDefaultType_autoAllowed, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Overriding extension getter '@refType mergeWithType'                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_impType extensionGetter_refType_mergeWithType (const cPtr_impType * inObject,
                                                             GALGAS_impType inArgument_typeToMerge,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_refType * object = (const cPtr_refType *) inObject ;
  macroValidSharedObject (object, cPtr_refType) ;
  GALGAS_refType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_refType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("refType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 520)) ;
    }
  }
  GALGAS_refType var_castTypeToMerge_13973 = temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, object->mAttribute_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 521)).objectCompare (var_castTypeToMerge_13973.getter_ref (SOURCE_FILE ("implementation_types.galgas", 521)).getter_string (SOURCE_FILE ("implementation_types.galgas", 521)))).boolEnum () ;
  if (kBoolTrue == test_1) {
    object->mAttribute_ref.log ("ref"  COMMA_SOURCE_FILE ("implementation_types.galgas", 522)) ;
    GALGAS_lstring var_csatRef_14089 = var_castTypeToMerge_13973.getter_ref (SOURCE_FILE ("implementation_types.galgas", 523)) ;
    var_csatRef_14089.log ("csatRef"  COMMA_SOURCE_FILE ("implementation_types.galgas", 524)) ;
    {
    routine_multiError (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 525)), GALGAS_string ("Redefinition of ").add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 525)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 525)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 525)) ;
    }
    {
    routine_multiError (object->mAttribute_locations, GALGAS_string ("Was defined here"), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 526)) ;
    }
  }
  result_mergedType = GALGAS_refType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 529)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 529)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 533)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 533)), object->mAttribute_ref  COMMA_SOURCE_FILE ("implementation_types.galgas", 528)) ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_refType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_refType.mSlotID,
                                      extensionGetter_refType_mergeWithType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_refType_mergeWithType (defineExtensionGetter_refType_mergeWithType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                             Overriding extension getter '@impRangedType mergeWithType'                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_impType extensionGetter_impRangedType_mergeWithType (const cPtr_impType * inObject,
                                                                   GALGAS_impType inArgument_typeToMerge,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impRangedType * object = (const cPtr_impRangedType *) inObject ;
  macroValidSharedObject (object, cPtr_impRangedType) ;
  GALGAS_impRangedType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impRangedType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impRangedType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impRangedType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 576)) ;
    }
  }
  GALGAS_impRangedType var_castTypeToMerge_15339 = temp_0 ;
  const GALGAS_impRangedType temp_1 = object ;
  const enumGalgasBool test_2 = function_checkRanged (temp_1, var_castTypeToMerge_15339, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 577)).boolEnum () ;
  if (kBoolTrue == test_2) {
    result_mergedType = inArgument_typeToMerge ;
  }else if (kBoolFalse == test_2) {
    const GALGAS_impRangedType temp_3 = object ;
    result_mergedType = temp_3 ;
  }
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_impRangedType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impRangedType.mSlotID,
                                      extensionGetter_impRangedType_mergeWithType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_impRangedType_mergeWithType (defineExtensionGetter_impRangedType_mergeWithType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                              Overriding extension getter '@impBoolType mergeWithType'                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_impType extensionGetter_impBoolType_mergeWithType (const cPtr_impType * inObject,
                                                                 GALGAS_impType inArgument_typeToMerge,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  GALGAS_impBoolType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impBoolType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 593)) ;
    }
  }
  GALGAS_impBoolType var_castTypeToMerge_15745 = temp_0 ;
  GALGAS_implementationObjectMap var_mergedTrueAttributes_15823 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 594)) ;
  GALGAS_implementationObjectMap var_mergedFalseAttributes_15884 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 595)) ;
  cEnumerator_implementationObjectMap enumerator_15926 (object->mAttribute_trueSubAttributes, kEnumeration_up) ;
  while (enumerator_15926.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_15953 = enumerator_15926.current_type (HERE) ;
    const enumGalgasBool test_1 = var_castTypeToMerge_15745.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 598)).getter_hasKey (enumerator_15926.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 598)) COMMA_SOURCE_FILE ("implementation_types.galgas", 598)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_impType var_subTypeToMerge_16110 ;
      var_castTypeToMerge_15745.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 599)).method_get (enumerator_15926.current_lkey (HERE), var_subTypeToMerge_16110, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 599)) ;
      var_mergedAttr_15953 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_15926.current_type (HERE).ptr (), var_subTypeToMerge_16110, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 600)) ;
    }
    {
    var_mergedTrueAttributes_15823.setter_put (enumerator_15926.current_lkey (HERE), var_mergedAttr_15953, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 602)) ;
    }
    enumerator_15926.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_16319 (var_castTypeToMerge_15745.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 605)), kEnumeration_up) ;
  while (enumerator_16319.hasCurrentObject ()) {
    const enumGalgasBool test_2 = object->mAttribute_trueSubAttributes.getter_hasKey (enumerator_16319.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 606)) COMMA_SOURCE_FILE ("implementation_types.galgas", 606)).operator_not (SOURCE_FILE ("implementation_types.galgas", 606)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      var_mergedTrueAttributes_15823.setter_put (enumerator_16319.current_lkey (HERE), enumerator_16319.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 607)) ;
      }
    }
    enumerator_16319.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_16475 (object->mAttribute_falseSubAttributes, kEnumeration_up) ;
  while (enumerator_16475.hasCurrentObject ()) {
    GALGAS_impType var_mergedAttr_16502 = enumerator_16475.current_type (HERE) ;
    const enumGalgasBool test_3 = var_castTypeToMerge_15745.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 613)).getter_hasKey (enumerator_16475.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 613)) COMMA_SOURCE_FILE ("implementation_types.galgas", 613)).boolEnum () ;
    if (kBoolTrue == test_3) {
      GALGAS_impType var_subTypeToMerge_16661 ;
      var_castTypeToMerge_15745.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 614)).method_get (enumerator_16475.current_lkey (HERE), var_subTypeToMerge_16661, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 614)) ;
      var_mergedAttr_16502 = callExtensionGetter_mergeWithType ((const cPtr_impType *) enumerator_16475.current_type (HERE).ptr (), var_subTypeToMerge_16661, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 615)) ;
    }
    {
    var_mergedFalseAttributes_15884.setter_put (enumerator_16475.current_lkey (HERE), var_mergedAttr_16502, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 617)) ;
    }
    enumerator_16475.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_16872 (var_castTypeToMerge_15745.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 620)), kEnumeration_up) ;
  while (enumerator_16872.hasCurrentObject ()) {
    const enumGalgasBool test_4 = object->mAttribute_falseSubAttributes.getter_hasKey (enumerator_16872.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 621)) COMMA_SOURCE_FILE ("implementation_types.galgas", 621)).operator_not (SOURCE_FILE ("implementation_types.galgas", 621)).boolEnum () ;
    if (kBoolTrue == test_4) {
      {
      var_mergedTrueAttributes_15823.setter_put (enumerator_16872.current_lkey (HERE), enumerator_16872.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 622)) ;
      }
    }
    enumerator_16872.gotoNextObject () ;
  }
  result_mergedType = GALGAS_impBoolType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 627)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 627)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 631)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 631)), object->mAttribute_withAuto, object->mAttribute_defaultValue, var_mergedTrueAttributes_15823, var_mergedFalseAttributes_15884  COMMA_SOURCE_FILE ("implementation_types.galgas", 626)) ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_impBoolType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                      extensionGetter_impBoolType_mergeWithType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_impBoolType_mergeWithType (defineExtensionGetter_impBoolType_mergeWithType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Overriding extension method '@impBoolType setDefault'                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impBoolType_setDefault (const cPtr_impAutoDefaultType * inObject,
                                                    GALGAS_objectAttributes & ioArgument_attributes,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  if (object->mAttribute_defaultValue.isValid ()) {
    if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_void) {
    }else if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else if (object->mAttribute_defaultValue.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_17462_b ((cPtr_boolAttribute *) object->mAttribute_defaultValue.ptr ()) ;
      const enumGalgasBool test_0 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 647)).getter_hasKey (object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 647)) COMMA_SOURCE_FILE ("implementation_types.galgas", 647)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_identifierMap var_userAttributes_17738 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 650)) ;
        GALGAS_object_5F_t var_value_17790 ;
        var_userAttributes_17738.method_get (object->mAttribute_name, var_value_17790, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 652)) ;
        if (var_value_17790.isValid ()) {
          if (var_value_17790.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
            GALGAS_boolAttribute cast_17892_boolValue ((cPtr_boolAttribute *) var_value_17790.ptr ()) ;
            GALGAS_implementationObjectMap var_subImpAttributes_17946 ;
            const enumGalgasBool test_1 = cast_17892_boolValue.getter_value (SOURCE_FILE ("implementation_types.galgas", 656)).boolEnum () ;
            if (kBoolTrue == test_1) {
              var_subImpAttributes_17946 = object->mAttribute_trueSubAttributes ;
            }else if (kBoolFalse == test_1) {
              var_subImpAttributes_17946 = object->mAttribute_falseSubAttributes ;
            }
            GALGAS_objectAttributes var_subAttributes_18152 = cast_17892_boolValue.getter_subAttributes (SOURCE_FILE ("implementation_types.galgas", 661)) ;
            {
            routine_setDefaultsForType (var_subImpAttributes_17946, var_subAttributes_18152, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 662)) ;
            }
            GALGAS_boolAttribute var_bv_18307 = cast_17892_boolValue ;
            {
            var_bv_18307.setter_setSubAttributes (var_subAttributes_18152 COMMA_SOURCE_FILE ("implementation_types.galgas", 665)) ;
            }
            {
            var_userAttributes_17738.setter_setValueForKey (var_bv_18307, object->mAttribute_name.getter_string (SOURCE_FILE ("implementation_types.galgas", 666)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 666)) ;
            }
            {
            ioArgument_attributes.setter_setObjectParams (var_userAttributes_17738 COMMA_SOURCE_FILE ("implementation_types.galgas", 667)) ;
            }
          }
        }
      }else if (kBoolFalse == test_0) {
        GALGAS_implementationObjectMap var_subImpAttributes_18566 ;
        const enumGalgasBool test_2 = cast_17462_b.getter_value (SOURCE_FILE ("implementation_types.galgas", 671)).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_subImpAttributes_18566 = object->mAttribute_trueSubAttributes ;
        }else if (kBoolFalse == test_2) {
          var_subImpAttributes_18566 = object->mAttribute_falseSubAttributes ;
        }
        GALGAS_objectAttributes var_subAttributes_18752 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 676)) ;
        {
        routine_setDefaultsForType (var_subImpAttributes_18566, var_subAttributes_18752, inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 677)) ;
        }
        GALGAS_boolAttribute var_defaults_18864 = GALGAS_boolAttribute::constructor_new (cast_17462_b.getter_oil_5F_desc (SOURCE_FILE ("implementation_types.galgas", 678)), cast_17462_b.getter_location (SOURCE_FILE ("implementation_types.galgas", 678)), cast_17462_b.getter_value (SOURCE_FILE ("implementation_types.galgas", 678)), var_subAttributes_18752  COMMA_SOURCE_FILE ("implementation_types.galgas", 678)) ;
        GALGAS_identifierMap var_attr_18971 = ioArgument_attributes.getter_objectParams (SOURCE_FILE ("implementation_types.galgas", 679)) ;
        {
        var_attr_18971.setter_put (object->mAttribute_name, var_defaults_18864, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 680)) ;
        }
        {
        ioArgument_attributes.setter_setObjectParams (var_attr_18971 COMMA_SOURCE_FILE ("implementation_types.galgas", 681)) ;
        }
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impBoolType_setDefault (void) {
  enterExtensionMethod_setDefault (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                   extensionMethod_impBoolType_setDefault) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impBoolType_setDefault (defineExtensionMethod_impBoolType_setDefault, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                              Overriding extension getter '@impEnumType mergeWithType'                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_impType extensionGetter_impEnumType_mergeWithType (const cPtr_impType * inObject,
                                                                 GALGAS_impType inArgument_typeToMerge,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_impType result_mergedType ; // Returned variable
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  GALGAS_impEnumType temp_0 ;
  if (inArgument_typeToMerge.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (inArgument_typeToMerge.ptr ())) {
      temp_0 = (cPtr_impEnumType *) inArgument_typeToMerge.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", inArgument_typeToMerge.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("implementation_types.galgas", 716)) ;
    }
  }
  GALGAS_impEnumType var_castTypeToMerge_19913 = temp_0 ;
  result_mergedType = GALGAS_impEnumType::constructor_new (object->mAttribute_locations.add_operation (inArgument_typeToMerge.getter_locations (SOURCE_FILE ("implementation_types.galgas", 718)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 718)), object->mAttribute_type, object->mAttribute_name, object->mAttribute_multiple, object->mAttribute_descs.add_operation (inArgument_typeToMerge.getter_descs (SOURCE_FILE ("implementation_types.galgas", 722)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 722)), object->mAttribute_withAuto, object->mAttribute_defaultValue, extensionGetter_mergeWithEnum (object->mAttribute_valuesMap, var_castTypeToMerge_19913.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 725)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 725))  COMMA_SOURCE_FILE ("implementation_types.galgas", 717)) ;
//---
  return result_mergedType ;
}


//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionGetter_impEnumType_mergeWithType (void) {
  enterExtensionGetter_mergeWithType (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                      extensionGetter_impEnumType_mergeWithType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gGetter_impEnumType_mergeWithType (defineExtensionGetter_impEnumType_mergeWithType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                           Overriding extension method '@refType checkAttributeReferences'                           *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_refType_checkAttributeReferences (const cPtr_impType * inObject,
                                                              const GALGAS_implementation constinArgument_imp,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_refType * object = (const cPtr_refType *) inObject ;
  macroValidSharedObject (object, cPtr_refType) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) constinArgument_imp.ptr (), object->mAttribute_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 943)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 943)).operator_not (SOURCE_FILE ("implementation_types.galgas", 943)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_location location_1 (object->mAttribute_ref.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_1, object->mAttribute_ref.getter_string (SOURCE_FILE ("implementation_types.galgas", 944)).add_operation (GALGAS_string (" object kind does not exist"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 944))  COMMA_SOURCE_FILE ("implementation_types.galgas", 944)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_refType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_refType.mSlotID,
                                                 extensionMethod_refType_checkAttributeReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_refType_checkAttributeReferences (defineExtensionMethod_refType_checkAttributeReferences, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                         Overriding extension method '@impBoolType checkAttributeReferences'                         *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impBoolType_checkAttributeReferences (const cPtr_impType * inObject,
                                                                  const GALGAS_implementation constinArgument_imp,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  cEnumerator_implementationObjectMap enumerator_27499 (object->mAttribute_trueSubAttributes, kEnumeration_up) ;
  while (enumerator_27499.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_27499.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 952)) ;
    enumerator_27499.gotoNextObject () ;
  }
  cEnumerator_implementationObjectMap enumerator_27582 (object->mAttribute_falseSubAttributes, kEnumeration_up) ;
  while (enumerator_27582.hasCurrentObject ()) {
    callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_27582.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 955)) ;
    enumerator_27582.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impBoolType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                                 extensionMethod_impBoolType_checkAttributeReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impBoolType_checkAttributeReferences (defineExtensionMethod_impBoolType_checkAttributeReferences, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                         Overriding extension method '@impEnumType checkAttributeReferences'                         *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impEnumType_checkAttributeReferences (const cPtr_impType * inObject,
                                                                  const GALGAS_implementation constinArgument_imp,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  cEnumerator_enumValues enumerator_27742 (object->mAttribute_valuesMap, kEnumeration_up) ;
  while (enumerator_27742.hasCurrentObject ()) {
    cEnumerator_implementationObjectMap enumerator_27774 (enumerator_27742.current_subAttributes (HERE), kEnumeration_up) ;
    while (enumerator_27774.hasCurrentObject ()) {
      callExtensionMethod_checkAttributeReferences ((const cPtr_impType *) enumerator_27774.current_type (HERE).ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 964)) ;
      enumerator_27774.gotoNextObject () ;
    }
    enumerator_27742.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impEnumType_checkAttributeReferences (void) {
  enterExtensionMethod_checkAttributeReferences (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                                 extensionMethod_impEnumType_checkAttributeReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impEnumType_checkAttributeReferences (defineExtensionMethod_impEnumType_checkAttributeReferences, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                 Overriding extension method '@structAttribute set'                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_structAttribute_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_TfieldMap & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structAttribute * object = (const cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  GALGAS_TfieldMap var_subAttrs_941 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 33)) ;
  {
  routine_addLStringValue (var_subAttrs_941, GALGAS_string ("NAME"), object->mAttribute_structName, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 34)) ;
  }
  {
  routine_addStructValue (ioArgument_result, constinArgument_name, var_subAttrs_941, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 35)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_structAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                            extensionMethod_structAttribute_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_structAttribute_set (defineExtensionMethod_structAttribute_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                  Overriding extension method '@boolAttribute set'                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_boolAttribute_set (const cPtr_object_5F_t * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               GALGAS_TfieldMap & ioArgument_result,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_boolAttribute * object = (const cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  {
  routine_addBoolValue (ioArgument_result, constinArgument_name, object->mAttribute_value, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 48)) ;
  }
  GALGAS_TfieldMap var_subAttrs_1561 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 49)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_subAttrs_1561.getter_count (SOURCE_FILE ("systemConfig.galgas", 50)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_structName_1643 = GALGAS_lstring::constructor_new (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 51)).add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 51)), constinArgument_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 51))  COMMA_SOURCE_FILE ("systemConfig.galgas", 51)) ;
    {
    routine_addStructValue (ioArgument_result, var_structName_1643, var_subAttrs_1561, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 52)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_boolAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                            extensionMethod_boolAttribute_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_boolAttribute_set (defineExtensionMethod_boolAttribute_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                  Overriding extension method '@enumAttribute set'                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_enumAttribute_set (const cPtr_object_5F_t * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               GALGAS_TfieldMap & ioArgument_result,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumAttribute * object = (const cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  {
  routine_addStringValue (ioArgument_result, constinArgument_name, object->mAttribute_value, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 61)) ;
  }
  GALGAS_TfieldMap var_subAttrs_2107 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 62)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_subAttrs_2107.getter_count (SOURCE_FILE ("systemConfig.galgas", 63)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_structName_2189 = GALGAS_lstring::constructor_new (constinArgument_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 64)).add_operation (GALGAS_string ("_S"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 64)), constinArgument_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 64))  COMMA_SOURCE_FILE ("systemConfig.galgas", 64)) ;
    {
    routine_addStructValue (ioArgument_result, var_structName_2189, var_subAttrs_2107, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 65)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_enumAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                            extensionMethod_enumAttribute_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_enumAttribute_set (defineExtensionMethod_enumAttribute_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                 Overriding extension method '@stringAttribute set'                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_stringAttribute_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_TfieldMap & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_stringAttribute * object = (const cPtr_stringAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_stringAttribute) ;
  {
  routine_addStringValue (ioArgument_result, constinArgument_name, object->mAttribute_value, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 70)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_stringAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_stringAttribute.mSlotID,
                            extensionMethod_stringAttribute_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_stringAttribute_set (defineExtensionMethod_stringAttribute_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Overriding extension method '@string_class set'                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_string_5F_class_set (const cPtr_object_5F_t * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 GALGAS_TfieldMap & ioArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_string_5F_class * object = (const cPtr_string_5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_string_5F_class) ;
  {
  routine_addStringValue (ioArgument_result, constinArgument_name, object->mAttribute_value, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 74)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_string_5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_string_5F_class.mSlotID,
                            extensionMethod_string_5F_class_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_string_5F_class_set (defineExtensionMethod_string_5F_class_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Overriding extension method '@objectRefAttribute set'                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_objectRefAttribute_set (const cPtr_object_5F_t * inObject,
                                                    const GALGAS_lstring constinArgument_name,
                                                    GALGAS_TfieldMap & ioArgument_result,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectRefAttribute * object = (const cPtr_objectRefAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_objectRefAttribute) ;
  {
  routine_addStringValue (ioArgument_result, constinArgument_name, object->mAttribute_value.getter_string (SOURCE_FILE ("systemConfig.galgas", 78)), object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 78)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_objectRefAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_objectRefAttribute.mSlotID,
                            extensionMethod_objectRefAttribute_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_objectRefAttribute_set (defineExtensionMethod_objectRefAttribute_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Overriding extension method '@multipleAttribute set'                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_multipleAttribute_set (const cPtr_object_5F_t * inObject,
                                                   const GALGAS_lstring constinArgument_name,
                                                   GALGAS_TfieldMap & ioArgument_result,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_multipleAttribute * object = (const cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  GALGAS_TfieldMapList var_multiple_2820 = GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("systemConfig.galgas", 82)) ;
  cEnumerator_identifierList enumerator_2867 (object->mAttribute_items, kEnumeration_up) ;
  while (enumerator_2867.hasCurrentObject ()) {
    GALGAS_TfieldMap var_multipleItem_2891 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 84)) ;
    if (enumerator_2867.current_item (HERE).isValid ()) {
      if (enumerator_2867.current_item (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
        GALGAS_structAttribute cast_2965_aStruct ((cPtr_structAttribute *) enumerator_2867.current_item (HERE).ptr ()) ;
        {
        routine_addLStringValue (var_multipleItem_2891, GALGAS_string ("NAME"), cast_2965_aStruct.getter_structName (SOURCE_FILE ("systemConfig.galgas", 87)), cast_2965_aStruct.getter_oil_5F_desc (SOURCE_FILE ("systemConfig.galgas", 87)), inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 87)) ;
        }
        GALGAS_TfieldMap var_subAttrs_3084 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) cast_2965_aStruct.getter_subAttributes (SOURCE_FILE ("systemConfig.galgas", 88)).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 88)) ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_subAttrs_3084.getter_count (SOURCE_FILE ("systemConfig.galgas", 89)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_0) {
          cEnumerator_TfieldMap enumerator_3184 (var_subAttrs_3084, kEnumeration_up) ;
          while (enumerator_3184.hasCurrentObject ()) {
            {
            var_multipleItem_2891.setter_insertKey (enumerator_3184.current_lkey (HERE), enumerator_3184.current_mType (HERE), enumerator_3184.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 91)) ;
            }
            enumerator_3184.gotoNextObject () ;
          }
        }
      }else{
        callExtensionMethod_set ((const cPtr_object_5F_t *) enumerator_2867.current_item (HERE).ptr (), GALGAS_lstring::constructor_new (GALGAS_string ("VALUE"), enumerator_2867.current_item (HERE).getter_location (SOURCE_FILE ("systemConfig.galgas", 95))  COMMA_SOURCE_FILE ("systemConfig.galgas", 95)), var_multipleItem_2891, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 95)) ;
      }
    }
    var_multiple_2820.addAssign_operation (var_multipleItem_2891  COMMA_SOURCE_FILE ("systemConfig.galgas", 97)) ;
    enumerator_2867.gotoNextObject () ;
  }
  {
  routine_addListValue (ioArgument_result, constinArgument_name, var_multiple_2820, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 99)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_multipleAttribute_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                            extensionMethod_multipleAttribute_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_multipleAttribute_set (defineExtensionMethod_multipleAttribute_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Overriding extension method '@uint32_class set'                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_uint_33__32__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_TfieldMap & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_33__32__5F_class * object = (const cPtr_uint_33__32__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_uint_33__32__5F_class) ;
  {
  routine_addUnsignedValue (ioArgument_result, constinArgument_name, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 103)), object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 103)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_uint_33__32__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_uint_33__32__5F_class.mSlotID,
                            extensionMethod_uint_33__32__5F_class_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_uint_33__32__5F_class_set (defineExtensionMethod_uint_33__32__5F_class_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Overriding extension method '@sint32_class set'                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_sint_33__32__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_TfieldMap & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_33__32__5F_class * object = (const cPtr_sint_33__32__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_sint_33__32__5F_class) ;
  {
  routine_addSignedValue (ioArgument_result, constinArgument_name, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 107)), object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 107)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_sint_33__32__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_sint_33__32__5F_class.mSlotID,
                            extensionMethod_sint_33__32__5F_class_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_sint_33__32__5F_class_set (defineExtensionMethod_sint_33__32__5F_class_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Overriding extension method '@uint64_class set'                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_uint_36__34__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_TfieldMap & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_uint_36__34__5F_class * object = (const cPtr_uint_36__34__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_uint_36__34__5F_class) ;
  {
  routine_addUnsignedValue (ioArgument_result, constinArgument_name, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 111)), object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 111)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_uint_36__34__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_uint_36__34__5F_class.mSlotID,
                            extensionMethod_uint_36__34__5F_class_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_uint_36__34__5F_class_set (defineExtensionMethod_uint_36__34__5F_class_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Overriding extension method '@sint64_class set'                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_sint_36__34__5F_class_set (const cPtr_object_5F_t * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       GALGAS_TfieldMap & ioArgument_result,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_sint_36__34__5F_class * object = (const cPtr_sint_36__34__5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_sint_36__34__5F_class) ;
  {
  routine_addSignedValue (ioArgument_result, constinArgument_name, object->mAttribute_value.getter_bigint (SOURCE_FILE ("systemConfig.galgas", 115)), object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 115)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_sint_36__34__5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_sint_36__34__5F_class.mSlotID,
                            extensionMethod_sint_36__34__5F_class_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_sint_36__34__5F_class_set (defineExtensionMethod_sint_36__34__5F_class_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Overriding extension method '@float_class set'                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_float_5F_class_set (const cPtr_object_5F_t * inObject,
                                                const GALGAS_lstring constinArgument_name,
                                                GALGAS_TfieldMap & ioArgument_result,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_float_5F_class * object = (const cPtr_float_5F_class *) inObject ;
  macroValidSharedObject (object, cPtr_float_5F_class) ;
  {
  routine_addFloatValue (ioArgument_result, constinArgument_name, object->mAttribute_value, object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 119)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_float_5F_class_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_float_5F_class.mSlotID,
                            extensionMethod_float_5F_class_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_float_5F_class_set (defineExtensionMethod_float_5F_class_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                       Overriding extension method '@auto set'                                       *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_auto_set (const cPtr_object_5F_t * inObject,
                                      const GALGAS_lstring constinArgument_name,
                                      GALGAS_TfieldMap & ioArgument_result,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_auto * object = (const cPtr_auto *) inObject ;
  macroValidSharedObject (object, cPtr_auto) ;
  {
  routine_addEnumValue (ioArgument_result, constinArgument_name, GALGAS_string ("auto"), object->mAttribute_oil_5F_desc, inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 123)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_auto_set (void) {
  enterExtensionMethod_set (kTypeDescriptor_GALGAS_auto.mSlotID,
                            extensionMethod_auto_set) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_auto_set (defineExtensionMethod_auto_set, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                               Overriding extension method '@impStructType verifyType'                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impStructType_verifyType (const cPtr_impType * inObject,
                                                      const GALGAS_object_5F_t constinArgument_attr,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impStructType * object = (const cPtr_impStructType *) inObject ;
  macroValidSharedObject (object, cPtr_impStructType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_structAttribute) {
      GALGAS_structAttribute cast_2379_sa ((cPtr_structAttribute *) constinArgument_attr.ptr ()) ;
      cEnumerator_implementationObjectMap enumerator_2413 (object->mAttribute_structAttributes, kEnumeration_up) ;
      while (enumerator_2413.hasCurrentObject ()) {
        const enumGalgasBool test_0 = cast_2379_sa.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 88)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 88)).getter_hasKey (enumerator_2413.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 88)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 88)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_object_5F_t var_subAttr_2514 ;
          cast_2379_sa.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 90)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 90)).method_get (enumerator_2413.current_lkey (HERE), var_subAttr_2514, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 90)) ;
          callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_2413.current_type (HERE).ptr (), var_subAttr_2514, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 91)) ;
        }
        enumerator_2413.gotoNextObject () ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 95)), GALGAS_string ("STRUCT expected")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 95)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impStructType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impStructType.mSlotID,
                                   extensionMethod_impStructType_verifyType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impStructType_verifyType (defineExtensionMethod_impStructType_verifyType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                  Overriding extension method '@refType verifyType'                                  *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_refType_verifyType (const cPtr_impType * /* inObject */,
                                                const GALGAS_object_5F_t constinArgument_attr,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_objectRefAttribute) {
    }else{
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 105)), GALGAS_string ("object reference expected")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 105)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_refType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_refType.mSlotID,
                                   extensionMethod_refType_verifyType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_refType_verifyType (defineExtensionMethod_refType_verifyType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Overriding extension method '@impBoolType verifyType'                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impBoolType_verifyType (const cPtr_impType * inObject,
                                                    const GALGAS_object_5F_t constinArgument_attr,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impBoolType * object = (const cPtr_impBoolType *) inObject ;
  macroValidSharedObject (object, cPtr_impBoolType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_3136_b ((cPtr_boolAttribute *) constinArgument_attr.ptr ()) ;
      const enumGalgasBool test_0 = cast_3136_b.getter_value (SOURCE_FILE ("semantic_verification.galgas", 114)).boolEnum () ;
      if (kBoolTrue == test_0) {
        cEnumerator_implementationObjectMap enumerator_3195 (object->mAttribute_trueSubAttributes, kEnumeration_up) ;
        while (enumerator_3195.hasCurrentObject ()) {
          const enumGalgasBool test_1 = cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 116)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 116)).getter_hasKey (enumerator_3195.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 116)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 116)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_object_5F_t var_subAttrs_3300 ;
            cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 118)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 118)).method_get (enumerator_3195.current_lkey (HERE), var_subAttrs_3300, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 118)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_3195.current_type (HERE).ptr (), var_subAttrs_3300, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 119)) ;
          }
          enumerator_3195.gotoNextObject () ;
        }
      }else if (kBoolFalse == test_0) {
        cEnumerator_implementationObjectMap enumerator_3478 (object->mAttribute_falseSubAttributes, kEnumeration_up) ;
        while (enumerator_3478.hasCurrentObject ()) {
          const enumGalgasBool test_2 = cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 124)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 124)).getter_hasKey (enumerator_3478.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 124)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 124)).boolEnum () ;
          if (kBoolTrue == test_2) {
            GALGAS_object_5F_t var_subAttrs_3583 ;
            cast_3136_b.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 126)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 126)).method_get (enumerator_3478.current_lkey (HERE), var_subAttrs_3583, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 126)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_3478.current_type (HERE).ptr (), var_subAttrs_3583, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 127)) ;
          }
          enumerator_3478.gotoNextObject () ;
        }
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 132)), GALGAS_string ("BOOLEAN expected")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 132)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impBoolType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impBoolType.mSlotID,
                                   extensionMethod_impBoolType_verifyType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impBoolType_verifyType (defineExtensionMethod_impBoolType_verifyType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Overriding extension method '@impEnumType verifyType'                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impEnumType_verifyType (const cPtr_impType * inObject,
                                                    const GALGAS_object_5F_t constinArgument_attr,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impEnumType * object = (const cPtr_impEnumType *) inObject ;
  macroValidSharedObject (object, cPtr_impEnumType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_enumAttribute) {
      GALGAS_enumAttribute cast_3969_e ((cPtr_enumAttribute *) constinArgument_attr.ptr ()) ;
      const enumGalgasBool test_0 = object->mAttribute_valuesMap.getter_hasKey (cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 141)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 141)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_implementationObjectMap var_validVal_4053 ;
        object->mAttribute_valuesMap.method_get (function_lstringWith (cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 143)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)), var_validVal_4053, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 143)) ;
        cEnumerator_implementationObjectMap enumerator_4136 (var_validVal_4053, kEnumeration_up) ;
        while (enumerator_4136.hasCurrentObject ()) {
          const enumGalgasBool test_1 = cast_3969_e.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 145)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 145)).getter_hasKey (enumerator_4136.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 145)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 145)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_object_5F_t var_subAttrs_4241 ;
            cast_3969_e.getter_subAttributes (SOURCE_FILE ("semantic_verification.galgas", 147)).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 147)).method_get (enumerator_4136.current_lkey (HERE), var_subAttrs_4241, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 147)) ;
            callExtensionMethod_verifyMultipleType ((const cPtr_impType *) enumerator_4136.current_type (HERE).ptr (), var_subAttrs_4241, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 148)) ;
          }
          enumerator_4136.gotoNextObject () ;
        }
      }else if (kBoolFalse == test_0) {
        inCompiler->emitSemanticError (cast_3969_e.getter_location (SOURCE_FILE ("semantic_verification.galgas", 152)), cast_3969_e.getter_value (SOURCE_FILE ("semantic_verification.galgas", 152)).add_operation (GALGAS_string (" is not a valid enum value"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 152))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 152)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("**** @impEnumType ****\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 156)) ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 157)), GALGAS_string ("ENUM expected")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 157)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impEnumType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impEnumType.mSlotID,
                                   extensionMethod_impEnumType_verifyType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impEnumType_verifyType (defineExtensionMethod_impEnumType_verifyType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                            Overriding extension method '@impAutoDefaultType verifyType'                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impAutoDefaultType_verifyType (const cPtr_impType * inObject,
                                                           const GALGAS_object_5F_t constinArgument_attr,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impAutoDefaultType * object = (const cPtr_impAutoDefaultType *) inObject ;
  macroValidSharedObject (object, cPtr_impAutoDefaultType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_string (SOURCE_FILE ("semantic_verification.galgas", 167)))).operator_and (GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 167)))) COMMA_SOURCE_FILE ("semantic_verification.galgas", 167)).boolEnum () ;
      if (kBoolTrue == test_0) {
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 168)), GALGAS_string ("string of identifier expected")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 168)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_identifier (SOURCE_FILE ("semantic_verification.galgas", 171)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 172)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 172))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 172)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
    }else{
      inCompiler->printMessage (GALGAS_string ("*** @impAutoDefaultType ***\n")  COMMA_SOURCE_FILE ("semantic_verification.galgas", 176)) ;
      constinArgument_attr.log ("attr"  COMMA_SOURCE_FILE ("semantic_verification.galgas", 177)) ;
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 178)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 178))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 178)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impAutoDefaultType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impAutoDefaultType.mSlotID,
                                   extensionMethod_impAutoDefaultType_verifyType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impAutoDefaultType_verifyType (defineExtensionMethod_impAutoDefaultType_verifyType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                               Overriding extension method '@impRangedType verifyType'                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_impRangedType_verifyType (const cPtr_impType * inObject,
                                                      const GALGAS_object_5F_t constinArgument_attr,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_impRangedType * object = (const cPtr_impRangedType *) inObject ;
  macroValidSharedObject (object, cPtr_impRangedType) ;
  if (constinArgument_attr.isValid ()) {
    if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 188)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 189)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 189))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 189)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("semantic_verification.galgas", 192)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 193)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 193))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 193)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 196)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 197)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 197))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 197)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("semantic_verification.galgas", 200)))).boolEnum () ;
      if (kBoolTrue == test_3) {
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 201)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 201))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 201)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsNotEqual, object->mAttribute_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("semantic_verification.galgas", 204)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 205)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 205))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 205)) ;
      }
    }else if (constinArgument_attr.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, object->mAttribute_withAuto.objectCompare (GALGAS_bool (false))).boolEnum () ;
      if (kBoolTrue == test_5) {
        inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 209)), GALGAS_string ("AUTO is not allowed for ").add_operation (object->mAttribute_name.getter_string (SOURCE_FILE ("semantic_verification.galgas", 209)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 209))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 209)) ;
      }
    }else{
      inCompiler->emitSemanticError (constinArgument_attr.getter_location (SOURCE_FILE ("semantic_verification.galgas", 213)), extensionGetter_oilType (object->mAttribute_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)).add_operation (GALGAS_string (" expected"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 213))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 213)) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_impRangedType_verifyType (void) {
  enterExtensionMethod_verifyType (kTypeDescriptor_GALGAS_impRangedType.mSlotID,
                                   extensionMethod_impRangedType_verifyType) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_impRangedType_verifyType (defineExtensionMethod_impRangedType_verifyType, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                       Overriding extension method '@multipleAttribute verifyCrossReferences'                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_multipleAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                     const GALGAS_objectsMap constinArgument_allObjects,
                                                                     const GALGAS_impType constinArgument_type,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_multipleAttribute * object = (const cPtr_multipleAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_multipleAttribute) ;
  cEnumerator_identifierList enumerator_19027 (object->mAttribute_items, kEnumeration_up) ;
  while (enumerator_19027.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_object_5F_t *) enumerator_19027.current_item (HERE).ptr (), constinArgument_allObjects, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 617)) ;
    enumerator_19027.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_multipleAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_multipleAttribute.mSlotID,
                                              extensionMethod_multipleAttribute_verifyCrossReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_multipleAttribute_verifyCrossReferences (defineExtensionMethod_multipleAttribute_verifyCrossReferences, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                         Overriding extension method '@boolAttribute verifyCrossReferences'                          *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_boolAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                 const GALGAS_objectsMap constinArgument_allObjects,
                                                                 const GALGAS_impType constinArgument_type,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_boolAttribute * object = (const cPtr_boolAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_boolAttribute) ;
  GALGAS_impBoolType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impBoolType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impBoolType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impBoolType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 625)) ;
    }
  }
  GALGAS_impBoolType var_boolType_19222 = temp_0 ;
  const enumGalgasBool test_1 = object->mAttribute_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19222.getter_trueSubAttributes (SOURCE_FILE ("semantic_verification.galgas", 627)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 627)) ;
  }else if (kBoolFalse == test_1) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_boolType_19222.getter_falseSubAttributes (SOURCE_FILE ("semantic_verification.galgas", 629)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 629)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_boolAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_boolAttribute.mSlotID,
                                              extensionMethod_boolAttribute_verifyCrossReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_boolAttribute_verifyCrossReferences (defineExtensionMethod_boolAttribute_verifyCrossReferences, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                         Overriding extension method '@enumAttribute verifyCrossReferences'                          *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_enumAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                 const GALGAS_objectsMap constinArgument_allObjects,
                                                                 const GALGAS_impType constinArgument_type,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_enumAttribute * object = (const cPtr_enumAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_enumAttribute) ;
  GALGAS_impEnumType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impEnumType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impEnumType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impEnumType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 637)) ;
    }
  }
  GALGAS_impEnumType var_enumType_19578 = temp_0 ;
  GALGAS_lstring var_key_19620 = GALGAS_lstring::constructor_new (object->mAttribute_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 638)) ;
  GALGAS_implementationObjectMap var_expectedAttributes_19729 ;
  var_enumType_19578.getter_valuesMap (SOURCE_FILE ("semantic_verification.galgas", 639)).method_get (var_key_19620, var_expectedAttributes_19729, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 639)) ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_expectedAttributes_19729, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 640)) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_enumAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_enumAttribute.mSlotID,
                                              extensionMethod_enumAttribute_verifyCrossReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_enumAttribute_verifyCrossReferences (defineExtensionMethod_enumAttribute_verifyCrossReferences, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                        Overriding extension method '@structAttribute verifyCrossReferences'                         *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_structAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                   const GALGAS_objectsMap constinArgument_allObjects,
                                                                   const GALGAS_impType constinArgument_type,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_structAttribute * object = (const cPtr_structAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_structAttribute) ;
  GALGAS_impStructType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impStructType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_impStructType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("impStructType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 647)) ;
    }
  }
  GALGAS_impStructType var_structType_19943 = temp_0 ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) object->mAttribute_subAttributes.ptr (), constinArgument_allObjects, var_structType_19943.getter_structAttributes (SOURCE_FILE ("semantic_verification.galgas", 648)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 648)) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_structAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_structAttribute.mSlotID,
                                              extensionMethod_structAttribute_verifyCrossReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_structAttribute_verifyCrossReferences (defineExtensionMethod_structAttribute_verifyCrossReferences, NULL) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                       Overriding extension method '@objectRefAttribute verifyCrossReferences'                       *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static void extensionMethod_objectRefAttribute_verifyCrossReferences (const cPtr_object_5F_t * inObject,
                                                                      const GALGAS_objectsMap constinArgument_allObjects,
                                                                      const GALGAS_impType constinArgument_type,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectRefAttribute * object = (const cPtr_objectRefAttribute *) inObject ;
  macroValidSharedObject (object, cPtr_objectRefAttribute) ;
  GALGAS_refType temp_0 ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_refType *> (constinArgument_type.ptr ())) {
      temp_0 = (cPtr_refType *) constinArgument_type.ptr () ;
    }else{
      inCompiler->castError ("refType", constinArgument_type.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("semantic_verification.galgas", 655)) ;
    }
  }
  GALGAS_refType var_refType_20190 = temp_0 ;
  GALGAS_objectKind var_kindMap_20313 ;
  constinArgument_allObjects.method_get (var_refType_20190.getter_ref (SOURCE_FILE ("semantic_verification.galgas", 657)), var_kindMap_20313, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 657)) ;
  const enumGalgasBool test_1 = var_kindMap_20313.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 658)).getter_hasKey (object->mAttribute_value.getter_string (SOURCE_FILE ("semantic_verification.galgas", 658)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 658)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 658)).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_location location_2 (object->mAttribute_value.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_2, GALGAS_string ("Referenced ").add_operation (var_refType_20190.getter_ref (SOURCE_FILE ("semantic_verification.galgas", 659)).getter_string (SOURCE_FILE ("semantic_verification.galgas", 659)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (": "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (object->mAttribute_value.getter_string (SOURCE_FILE ("semantic_verification.galgas", 659)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)).add_operation (GALGAS_string (" does not exist"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 659))  COMMA_SOURCE_FILE ("semantic_verification.galgas", 659)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionMethod_objectRefAttribute_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_objectRefAttribute.mSlotID,
                                              extensionMethod_objectRefAttribute_verifyCrossReferences) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gMethod_objectRefAttribute_verifyCrossReferences (defineExtensionMethod_objectRefAttribute_verifyCrossReferences, NULL) ;

