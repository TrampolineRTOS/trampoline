#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-declarations-9.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed notOp'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_notOp (const cPtr_gtlData * inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 403)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_notOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_notOp (defineExtensionGetter_gtlUnconstructed_notOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed addOp'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_addOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 406)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_addOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_addOp (defineExtensionGetter_gtlUnconstructed_addOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed subOp'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_subOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 409)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_subOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_subOp (defineExtensionGetter_gtlUnconstructed_subOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed mulOp'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_mulOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 412)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_mulOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_mulOp (defineExtensionGetter_gtlUnconstructed_mulOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed divOp'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_divOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 415)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_divOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_divOp (defineExtensionGetter_gtlUnconstructed_divOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed modOp'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_modOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 418)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_modOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_modOp (defineExtensionGetter_gtlUnconstructed_modOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed andOp'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_andOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 421)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_andOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_andOp (defineExtensionGetter_gtlUnconstructed_andOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed orOp'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_orOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 424)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_orOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_orOp (defineExtensionGetter_gtlUnconstructed_orOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed xorOp'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_xorOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 427)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_xorOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_xorOp (defineExtensionGetter_gtlUnconstructed_xorOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed slOp'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_slOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 430)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_slOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_slOp (defineExtensionGetter_gtlUnconstructed_slOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed srOp'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_srOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 433)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_srOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_srOp (defineExtensionGetter_gtlUnconstructed_srOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed neqOp'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_neqOp (const cPtr_gtlData * inObject,
                                                              const GALGAS_gtlData /* constinArgument_right */,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 436)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                              extensionGetter_gtlUnconstructed_neqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_neqOp (defineExtensionGetter_gtlUnconstructed_neqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed eqOp'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_eqOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 439)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_eqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_eqOp (defineExtensionGetter_gtlUnconstructed_eqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed gtOp'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_gtOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 442)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_gtOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_gtOp (defineExtensionGetter_gtlUnconstructed_gtOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed geOp'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_geOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 445)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_geOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_geOp (defineExtensionGetter_gtlUnconstructed_geOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed ltOp'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_ltOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 448)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_ltOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_ltOp (defineExtensionGetter_gtlUnconstructed_ltOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlUnconstructed leOp'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_leOp (const cPtr_gtlData * inObject,
                                                             const GALGAS_gtlData /* constinArgument_right */,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 451)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                             extensionGetter_gtlUnconstructed_leOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_leOp (defineExtensionGetter_gtlUnconstructed_leOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                            Overriding extension getter '@gtlUnconstructed embeddedType'                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_type extensionGetter_gtlUnconstructed_embeddedType (const cPtr_gtlData * inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("unconstructed data provided as argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 456)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                     extensionGetter_gtlUnconstructed_embeddedType) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_embeddedType (defineExtensionGetter_gtlUnconstructed_embeddedType, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                             Overriding extension method '@gtlUnconstructed addMyValue'                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_gtlUnconstructed_addMyValue (const cPtr_gtlData * inObject,
                                                         GALGAS_objectlist & /* ioArgument_objectList */,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("Attempting to pass an unconstructed data to a function"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 461)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_gtlUnconstructed_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                   extensionMethod_gtlUnconstructed_addMyValue) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_gtlUnconstructed_addMyValue (defineExtensionMethod_gtlUnconstructed_addMyValue, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                            Overriding extension getter '@gtlUnconstructed performGetter'                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlUnconstructed_performGetter (const cPtr_gtlData * inObject,
                                                                      const GALGAS_lstring constinArgument_methodName,
                                                                      const GALGAS_gtlDataList constinArgument_arguments,
                                                                      const GALGAS_gtlContext constinArgument_context,
                                                                      const GALGAS_library constinArgument_lib,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlUnconstructed * object = (const cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 474)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 475)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 475)) ;
      }
      const GALGAS_gtlUnconstructed temp_1 = object ;
      result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 477)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 477)), temp_1.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 477))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 476)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 479)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 480)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 480)) ;
        }
        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 482)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 482)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 481)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 484)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 485)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 485)) ;
          }
          result_result = GALGAS_gtlString::constructor_new (object->mProperty_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 487)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 487)), object->mProperty_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 487))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 486)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 489)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 490)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 490)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 492)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 492)), object->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 492))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 491)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 494)).boolEnum () ;
            if (kBoolTrue == test_5) {
              const GALGAS_gtlUnconstructed temp_6 = object ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 495)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 496)), constinArgument_context, constinArgument_lib, temp_6, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 495)) ;
            }
          }
          if (kBoolFalse == test_5) {
            TC_Array <C_FixItDescription> fixItArray7 ;
            inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 503)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 503)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 503)).add_operation (GALGAS_string ("' for unconstructed target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 503)), fixItArray7  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 503)) ;
            result_result.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlUnconstructed_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                      extensionGetter_gtlUnconstructed_performGetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlUnconstructed_performGetter (defineExtensionGetter_gtlUnconstructed_performGetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                            Overriding extension setter '@gtlUnconstructed performSetter'                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionSetter_gtlUnconstructed_performSetter (cPtr_gtlData * inObject,
                                                            const GALGAS_lstring constinArgument_methodName,
                                                            const GALGAS_gtlDataList constinArgument_arguments,
                                                            const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_library constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlUnconstructed * object = (cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 516)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 517)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 517)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 518)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 518)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 518)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 518)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 518)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_16181 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_16181.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 519)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 519)) ;
      }
      object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 520)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 521)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 522)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 522)) ;
        }
        object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 523)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 524)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlUnconstructed temp_4 = object ;
          GALGAS_gtlData var_copy_16486 = temp_4 ;
          callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 526)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 527)), constinArgument_context, constinArgument_lib, var_copy_16486, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 526)) ;
          object->mProperty_where = var_copy_16486.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 533)) ;
          object->mProperty_meta = var_copy_16486.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 534)) ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 536)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 536)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 536)).add_operation (GALGAS_string ("' for unconstructed target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 536)), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 536)) ;
      }
    }
  }
}
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionSetter_gtlUnconstructed_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                      extensionSetter_gtlUnconstructed_performSetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gSetter_gtlUnconstructed_performSetter (defineExtensionSetter_gtlUnconstructed_performSetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType desc'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlType_desc (const cPtr_gtlData * inObject,
                                                   const GALGAS_uint constinArgument_tab,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 550)).add_operation (GALGAS_string ("type: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 550)).add_operation (extensionGetter_typeName (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 551)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 551)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 551)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_desc) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_desc (defineExtensionGetter_gtlType_desc, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType string'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlType_string (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  result_result = extensionGetter_typeName (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 554)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                               extensionGetter_gtlType_string) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_string (defineExtensionGetter_gtlType_string, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlType lstring'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_lstring extensionGetter_gtlType_lstring (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  result_result = GALGAS_lstring::constructor_new (extensionGetter_typeName (object->mProperty_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 557)), object->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 557)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                extensionGetter_gtlType_lstring) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_lstring (defineExtensionGetter_gtlType_lstring, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType bool'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bool extensionGetter_gtlType_bool (const cPtr_gtlData * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a type to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 561)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_bool) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_bool (defineExtensionGetter_gtlType_bool, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType int'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bigint extensionGetter_gtlType_int (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a type to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 565)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                            extensionGetter_gtlType_int) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_int (defineExtensionGetter_gtlType_int, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType float'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_double extensionGetter_gtlType_float (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a type to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 569)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_float) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_float (defineExtensionGetter_gtlType_float, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType plusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_plusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 573)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                               extensionGetter_gtlType_plusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_plusOp (defineExtensionGetter_gtlType_plusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlType minusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_minusOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 576)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                extensionGetter_gtlType_minusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_minusOp (defineExtensionGetter_gtlType_minusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType notOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_notOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 579)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_notOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_notOp (defineExtensionGetter_gtlType_notOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType addOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_addOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 582)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_addOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_addOp (defineExtensionGetter_gtlType_addOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType subOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_subOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 585)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_subOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_subOp (defineExtensionGetter_gtlType_subOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType mulOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_mulOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 588)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_mulOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_mulOp (defineExtensionGetter_gtlType_mulOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType divOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_divOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 591)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_divOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_divOp (defineExtensionGetter_gtlType_divOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType modOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_modOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 594)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_modOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_modOp (defineExtensionGetter_gtlType_modOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType andOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_andOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 597)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_andOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_andOp (defineExtensionGetter_gtlType_andOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType orOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_orOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 600)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_orOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_orOp (defineExtensionGetter_gtlType_orOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType xorOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_xorOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 603)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_xorOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_xorOp (defineExtensionGetter_gtlType_xorOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType slOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_slOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 606)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_slOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_slOp (defineExtensionGetter_gtlType_slOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType srOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_srOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 609)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_srOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_srOp (defineExtensionGetter_gtlType_srOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlType neqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_neqOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlType).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlType temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlType *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlType *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlType", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 613)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 613)), GALGAS_bool (kIsNotEqual, object->mProperty_type.objectCompare (temp_1.getter_type (SOURCE_FILE ("gtl_data_types.galgas", 613))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 613)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 615)), GALGAS_string ("type expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 615)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                              extensionGetter_gtlType_neqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_neqOp (defineExtensionGetter_gtlType_neqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType eqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_eqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlType).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlType temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlType *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlType *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlType", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 620)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 620)), GALGAS_bool (kIsEqual, object->mProperty_type.objectCompare (temp_1.getter_type (SOURCE_FILE ("gtl_data_types.galgas", 620))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 620)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 622)), GALGAS_string ("type expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 622)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_eqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_eqOp (defineExtensionGetter_gtlType_eqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType gtOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_gtOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 626)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_gtOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_gtOp (defineExtensionGetter_gtlType_gtOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType geOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_geOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 629)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_geOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_geOp (defineExtensionGetter_gtlType_geOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType ltOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_ltOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 632)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_ltOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_ltOp (defineExtensionGetter_gtlType_ltOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlType leOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_leOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 635)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                             extensionGetter_gtlType_leOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_leOp (defineExtensionGetter_gtlType_leOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlType embeddedType'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_type extensionGetter_gtlType_embeddedType (const cPtr_gtlData * /* inObject */,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_type) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                     extensionGetter_gtlType_embeddedType) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_embeddedType (defineExtensionGetter_gtlType_embeddedType, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Overriding extension method '@gtlType addMyValue'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_gtlType_addMyValue (const cPtr_gtlData * inObject,
                                                GALGAS_objectlist & ioArgument_objectList,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  ioArgument_objectList.addAssign_operation (object->mProperty_type.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 645))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 645)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_gtlType_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                   extensionMethod_gtlType_addMyValue) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_gtlType_addMyValue (defineExtensionMethod_gtlType_addMyValue, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlType performGetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlType_performGetter (const cPtr_gtlData * inObject,
                                                             const GALGAS_lstring constinArgument_methodName,
                                                             const GALGAS_gtlDataList constinArgument_arguments,
                                                             const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_library constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlType * object = (const cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 658)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 659)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 659)) ;
      }
      const GALGAS_gtlType temp_1 = object ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 661)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 661)), callExtensionGetter_string ((const cPtr_gtlType *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 661))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 660)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 663)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 664)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 664)) ;
        }
        const GALGAS_gtlType temp_3 = object ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 666)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 666)), temp_3.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 666))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 665)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 668)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 669)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 669)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 671)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 671)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 670)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 673)))).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 674)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 674)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (object->mProperty_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 676)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 676)), object->mProperty_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 676))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 675)) ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 678)))).boolEnum () ;
            if (kBoolTrue == test_6) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 679)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 679)) ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 681)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 681)), object->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 681))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 680)) ;
            }
          }
          if (kBoolFalse == test_6) {
            enumGalgasBool test_7 = kBoolTrue ;
            if (kBoolTrue == test_7) {
              test_7 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 683)).boolEnum () ;
              if (kBoolTrue == test_7) {
                const GALGAS_gtlType temp_8 = object ;
                result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 684)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 685)), constinArgument_context, constinArgument_lib, temp_8, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 684)) ;
              }
            }
            if (kBoolFalse == test_7) {
              TC_Array <C_FixItDescription> fixItArray9 ;
              inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 692)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 692)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 692)).add_operation (GALGAS_string ("' for type target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 692)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 692)) ;
              result_result.drop () ; // Release error dropped variable
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlType_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                      extensionGetter_gtlType_performGetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlType_performGetter (defineExtensionGetter_gtlType_performGetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension setter '@gtlType performSetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionSetter_gtlType_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlType * object = (cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 705)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 706)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 706)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 707)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 707)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 707)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 707)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 707)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_22530 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_22530.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 708)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 708)) ;
      }
      object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 709)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 710)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 711)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 711)) ;
        }
        object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 712)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 713)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlType temp_4 = object ;
          GALGAS_gtlData var_copy_22826 = temp_4 ;
          callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 715)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 716)), constinArgument_context, constinArgument_lib, var_copy_22826, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 715)) ;
          GALGAS_gtlType temp_5 ;
          if (var_copy_22826.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlType *> (var_copy_22826.ptr ())) {
              temp_5 = (cPtr_gtlType *) var_copy_22826.ptr () ;
            }else{
              inCompiler->castError ("gtlType", var_copy_22826.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 722)) ;
            }
          }
          object->mProperty_type = temp_5.getter_type (SOURCE_FILE ("gtl_data_types.galgas", 722)) ;
          object->mProperty_where = var_copy_22826.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 723)) ;
          object->mProperty_meta = var_copy_22826.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 724)) ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 726)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 726)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 726)).add_operation (GALGAS_string ("' for type target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 726)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 726)) ;
      }
    }
  }
}
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionSetter_gtlType_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                      extensionSetter_gtlType_performSetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gSetter_gtlType_performSetter (defineExtensionSetter_gtlType_performSetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum desc'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlEnum_desc (const cPtr_gtlData * inObject,
                                                   const GALGAS_uint constinArgument_tab,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 739)).add_operation (GALGAS_string ("enum: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 739)).add_operation (object->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 740)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 740)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_desc) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_desc (defineExtensionGetter_gtlEnum_desc, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum string'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlEnum_string (const cPtr_gtlData * inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  result_result = object->mProperty_value ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                               extensionGetter_gtlEnum_string) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_string (defineExtensionGetter_gtlEnum_string, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlEnum lstring'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_lstring extensionGetter_gtlEnum_lstring (const cPtr_gtlData * inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  result_result = GALGAS_lstring::constructor_new (object->mProperty_value, object->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 746)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                extensionGetter_gtlEnum_lstring) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_lstring (defineExtensionGetter_gtlEnum_lstring, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum bool'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bool extensionGetter_gtlEnum_bool (const cPtr_gtlData * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast an enum to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 750)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_bool) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_bool (defineExtensionGetter_gtlEnum_bool, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum int'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bigint extensionGetter_gtlEnum_int (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast an enum to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 754)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                            extensionGetter_gtlEnum_int) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_int (defineExtensionGetter_gtlEnum_int, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum float'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_double extensionGetter_gtlEnum_float (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast an enum to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 758)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_float) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_float (defineExtensionGetter_gtlEnum_float, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum plusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_plusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 762)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                               extensionGetter_gtlEnum_plusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_plusOp (defineExtensionGetter_gtlEnum_plusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlEnum minusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_minusOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 765)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                extensionGetter_gtlEnum_minusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_minusOp (defineExtensionGetter_gtlEnum_minusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum notOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_notOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 768)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_notOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_notOp (defineExtensionGetter_gtlEnum_notOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum addOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_addOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 771)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_addOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_addOp (defineExtensionGetter_gtlEnum_addOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum subOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_subOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 774)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_subOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_subOp (defineExtensionGetter_gtlEnum_subOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum mulOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_mulOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 777)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_mulOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_mulOp (defineExtensionGetter_gtlEnum_mulOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum divOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_divOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 780)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_divOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_divOp (defineExtensionGetter_gtlEnum_divOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum modOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_modOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 783)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_modOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_modOp (defineExtensionGetter_gtlEnum_modOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum andOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_andOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 786)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_andOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_andOp (defineExtensionGetter_gtlEnum_andOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum orOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_orOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 789)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_orOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_orOp (defineExtensionGetter_gtlEnum_orOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum xorOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_xorOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 792)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_xorOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_xorOp (defineExtensionGetter_gtlEnum_xorOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum slOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_slOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 795)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_slOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_slOp (defineExtensionGetter_gtlEnum_slOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum srOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_srOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 798)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_srOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_srOp (defineExtensionGetter_gtlEnum_srOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlEnum neqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_neqOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlEnum temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 805)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 804)), GALGAS_bool (kIsNotEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 805))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 802)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 808)), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 808)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                              extensionGetter_gtlEnum_neqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_neqOp (defineExtensionGetter_gtlEnum_neqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum eqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_eqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlEnum temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 816)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 815)), GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 816))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 813)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 819)), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 819)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_eqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_eqOp (defineExtensionGetter_gtlEnum_eqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum gtOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_gtOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 823)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_gtOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_gtOp (defineExtensionGetter_gtlEnum_gtOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum geOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_geOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 826)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_geOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_geOp (defineExtensionGetter_gtlEnum_geOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum ltOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_ltOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 829)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_ltOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_ltOp (defineExtensionGetter_gtlEnum_ltOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlEnum leOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_leOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 832)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                             extensionGetter_gtlEnum_leOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_leOp (defineExtensionGetter_gtlEnum_leOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlEnum embeddedType'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_type extensionGetter_gtlEnum_embeddedType (const cPtr_gtlData * inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 837)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                     extensionGetter_gtlEnum_embeddedType) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_embeddedType (defineExtensionGetter_gtlEnum_embeddedType, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Overriding extension method '@gtlEnum addMyValue'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_gtlEnum_addMyValue (const cPtr_gtlData * inObject,
                                                GALGAS_objectlist & /* ioArgument_objectList */,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 842)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_gtlEnum_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                   extensionMethod_gtlEnum_addMyValue) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_gtlEnum_addMyValue (defineExtensionMethod_gtlEnum_addMyValue, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlEnum performGetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlEnum_performGetter (const cPtr_gtlData * inObject,
                                                             const GALGAS_lstring constinArgument_methodName,
                                                             const GALGAS_gtlDataList constinArgument_arguments,
                                                             const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_library constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlEnum * object = (const cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 855)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 856)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 856)) ;
      }
      const GALGAS_gtlEnum temp_1 = object ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 858)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 858)), callExtensionGetter_string ((const cPtr_gtlEnum *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 858))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 857)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 860)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 861)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 861)) ;
        }
        const GALGAS_gtlEnum temp_3 = object ;
        result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 863)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 863)), temp_3.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 863))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 862)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 865)))).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 868)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 868)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 867)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 870)))).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 871)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 871)) ;
            }
            result_result = GALGAS_gtlString::constructor_new (object->mProperty_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 873)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 873)), object->mProperty_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 873))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 872)) ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 875)).boolEnum () ;
            if (kBoolTrue == test_6) {
              const GALGAS_gtlEnum temp_7 = object ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 876)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 877)), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 876)) ;
            }
          }
          if (kBoolFalse == test_6) {
            enumGalgasBool test_8 = kBoolTrue ;
            if (kBoolTrue == test_8) {
              test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 883)))).boolEnum () ;
              if (kBoolTrue == test_8) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 884)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 884)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 886)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 886)), object->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 886))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 885)) ;
              }
            }
            if (kBoolFalse == test_8) {
              TC_Array <C_FixItDescription> fixItArray9 ;
              inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 889)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 889)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 889)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 889)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 889)) ;
              result_result.drop () ; // Release error dropped variable
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlEnum_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                      extensionGetter_gtlEnum_performGetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlEnum_performGetter (defineExtensionGetter_gtlEnum_performGetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension setter '@gtlEnum performSetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionSetter_gtlEnum_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlEnum * object = (cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 902)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 903)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 903)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 904)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 904)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 904)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 904)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 904)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_29009 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_29009.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 905)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 905)) ;
      }
      object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 906)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 907)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 908)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 908)) ;
        }
        object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 909)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 910)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlEnum temp_4 = object ;
          GALGAS_gtlData var_copy_29305 = temp_4 ;
          callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 912)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 913)), constinArgument_context, constinArgument_lib, var_copy_29305, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 912)) ;
          GALGAS_gtlEnum temp_5 ;
          if (var_copy_29305.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlEnum *> (var_copy_29305.ptr ())) {
              temp_5 = (cPtr_gtlEnum *) var_copy_29305.ptr () ;
            }else{
              inCompiler->castError ("gtlEnum", var_copy_29305.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 919)) ;
            }
          }
          object->mProperty_value = temp_5.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 919)) ;
          object->mProperty_where = var_copy_29305.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 920)) ;
          object->mProperty_meta = var_copy_29305.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 921)) ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 923)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 923)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 923)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 923)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 923)) ;
      }
    }
  }
}
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionSetter_gtlEnum_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                      extensionSetter_gtlEnum_performSetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gSetter_gtlEnum_performSetter (defineExtensionSetter_gtlEnum_performSetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar desc'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlChar_desc (const cPtr_gtlData * inObject,
                                                   const GALGAS_uint constinArgument_tab,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 936)).add_operation (GALGAS_string ("char: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 936)).add_operation (object->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 937)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 937)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 937)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_desc) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_desc (defineExtensionGetter_gtlChar_desc, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar string'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlChar_string (const cPtr_gtlData * inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  result_result = object->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 940)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                               extensionGetter_gtlChar_string) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_string (defineExtensionGetter_gtlChar_string, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlChar lstring'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_lstring extensionGetter_gtlChar_lstring (const cPtr_gtlData * inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  result_result = GALGAS_lstring::constructor_new (object->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 943)), object->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 943)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                extensionGetter_gtlChar_lstring) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_lstring (defineExtensionGetter_gtlChar_lstring, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar bool'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bool extensionGetter_gtlChar_bool (const cPtr_gtlData * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a char to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 947)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_bool) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_bool (defineExtensionGetter_gtlChar_bool, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar int'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bigint extensionGetter_gtlChar_int (const cPtr_gtlData * inObject,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  result_result = object->mProperty_value.getter_uint (SOURCE_FILE ("gtl_data_types.galgas", 951)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 951)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                            extensionGetter_gtlChar_int) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_int (defineExtensionGetter_gtlChar_int, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar float'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_double extensionGetter_gtlChar_float (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a char to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 955)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_float) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_float (defineExtensionGetter_gtlChar_float, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar plusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_plusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 959)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                               extensionGetter_gtlChar_plusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_plusOp (defineExtensionGetter_gtlChar_plusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlChar minusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_minusOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 963)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                extensionGetter_gtlChar_minusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_minusOp (defineExtensionGetter_gtlChar_minusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar notOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_notOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 967)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_notOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_notOp (defineExtensionGetter_gtlChar_notOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar addOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_addOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 971)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_addOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_addOp (defineExtensionGetter_gtlChar_addOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar subOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_subOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 975)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_subOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_subOp (defineExtensionGetter_gtlChar_subOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar mulOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_mulOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 979)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_mulOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_mulOp (defineExtensionGetter_gtlChar_mulOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar divOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_divOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 983)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_divOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_divOp (defineExtensionGetter_gtlChar_divOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar modOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_modOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 987)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_modOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_modOp (defineExtensionGetter_gtlChar_modOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar andOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_andOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 991)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_andOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_andOp (defineExtensionGetter_gtlChar_andOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar orOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_orOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 995)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_orOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_orOp (defineExtensionGetter_gtlChar_orOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar xorOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_xorOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 999)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_xorOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_xorOp (defineExtensionGetter_gtlChar_xorOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar slOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_slOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1003)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_slOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_slOp (defineExtensionGetter_gtlChar_slOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar srOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_srOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1007)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_srOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_srOp (defineExtensionGetter_gtlChar_srOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlChar neqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_neqOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1015)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1014)), GALGAS_bool (kIsNotEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1015))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1012)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1018)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1018)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                              extensionGetter_gtlChar_neqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_neqOp (defineExtensionGetter_gtlChar_neqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar eqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_eqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1027)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1026)), GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1027))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1024)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1030)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1030)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_eqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_eqOp (defineExtensionGetter_gtlChar_eqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar gtOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_gtOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1039)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1038)), GALGAS_bool (kIsStrictSup, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1039))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1036)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1042)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1042)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_gtOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_gtOp (defineExtensionGetter_gtlChar_gtOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar geOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_geOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1051)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1050)), GALGAS_bool (kIsSupOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1051))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1048)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1054)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1054)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_geOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_geOp (defineExtensionGetter_gtlChar_geOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar ltOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_ltOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1063)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1062)), GALGAS_bool (kIsStrictInf, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1063))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1060)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1066)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1066)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_ltOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_ltOp (defineExtensionGetter_gtlChar_ltOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlChar leOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_leOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1075)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1074)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1075))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1072)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1078)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1078)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                             extensionGetter_gtlChar_leOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_leOp (defineExtensionGetter_gtlChar_leOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlChar embeddedType'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_type extensionGetter_gtlChar_embeddedType (const cPtr_gtlData * /* inObject */,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_char) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                     extensionGetter_gtlChar_embeddedType) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_embeddedType (defineExtensionGetter_gtlChar_embeddedType, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Overriding extension method '@gtlChar addMyValue'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_gtlChar_addMyValue (const cPtr_gtlData * inObject,
                                                GALGAS_objectlist & ioArgument_objectList,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  ioArgument_objectList.addAssign_operation (object->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1089))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1089)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_gtlChar_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                   extensionMethod_gtlChar_addMyValue) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_gtlChar_addMyValue (defineExtensionMethod_gtlChar_addMyValue, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlChar performGetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlChar_performGetter (const cPtr_gtlData * inObject,
                                                             const GALGAS_lstring constinArgument_methodName,
                                                             const GALGAS_gtlDataList constinArgument_arguments,
                                                             const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_library constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlChar * object = (const cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1102)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1103)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1103)) ;
      }
      const GALGAS_gtlChar temp_1 = object ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1105)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1105)), callExtensionGetter_string ((const cPtr_gtlChar *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1105))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1104)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlnum").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1107)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1108)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1108)) ;
        }
        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1110)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1110)), object->mProperty_value.getter_isalnum (SOURCE_FILE ("gtl_data_types.galgas", 1110))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1109)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isCntrl").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1112)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1113)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1113)) ;
          }
          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1115)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1115)), object->mProperty_value.getter_iscntrl (SOURCE_FILE ("gtl_data_types.galgas", 1115))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1114)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isDigit").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1117)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1118)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1118)) ;
            }
            result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1120)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1120)), object->mProperty_value.getter_isdigit (SOURCE_FILE ("gtl_data_types.galgas", 1120))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1119)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlpha").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1122)))).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1123)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1123)) ;
              }
              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1125)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1125)), object->mProperty_value.getter_isalpha (SOURCE_FILE ("gtl_data_types.galgas", 1125))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1124)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("isLower").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1127)))).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1128)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1128)) ;
                }
                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1130)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1130)), object->mProperty_value.getter_islower (SOURCE_FILE ("gtl_data_types.galgas", 1130))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1129)) ;
              }
            }
            if (kBoolFalse == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("isUpper").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1132)))).boolEnum () ;
                if (kBoolTrue == test_7) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1133)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1133)) ;
                  }
                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1135)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1135)), object->mProperty_value.getter_isupper (SOURCE_FILE ("gtl_data_types.galgas", 1135))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1134)) ;
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("isXDigit").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1137)))).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)) ;
                    }
                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1140)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1140)), object->mProperty_value.getter_isxdigit (SOURCE_FILE ("gtl_data_types.galgas", 1140))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1139)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  enumGalgasBool test_9 = kBoolTrue ;
                  if (kBoolTrue == test_9) {
                    test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1142)))).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1143)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1143)) ;
                      }
                      const GALGAS_gtlChar temp_10 = object ;
                      result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1145)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1145)), temp_10.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1145))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1144)) ;
                    }
                  }
                  if (kBoolFalse == test_9) {
                    enumGalgasBool test_11 = kBoolTrue ;
                    if (kBoolTrue == test_11) {
                      test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1147)))).boolEnum () ;
                      if (kBoolTrue == test_11) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1148)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1148)) ;
                        }
                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1150)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1150)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1149)) ;
                      }
                    }
                    if (kBoolFalse == test_11) {
                      enumGalgasBool test_12 = kBoolTrue ;
                      if (kBoolTrue == test_12) {
                        test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1152)))).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1153)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1153)) ;
                          }
                          result_result = GALGAS_gtlString::constructor_new (object->mProperty_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1155)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1155)), object->mProperty_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1155))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1154)) ;
                        }
                      }
                      if (kBoolFalse == test_12) {
                        enumGalgasBool test_13 = kBoolTrue ;
                        if (kBoolTrue == test_13) {
                          test_13 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1157)).boolEnum () ;
                          if (kBoolTrue == test_13) {
                            const GALGAS_gtlChar temp_14 = object ;
                            result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1158)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1159)), constinArgument_context, constinArgument_lib, temp_14, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1158)) ;
                          }
                        }
                        if (kBoolFalse == test_13) {
                          enumGalgasBool test_15 = kBoolTrue ;
                          if (kBoolTrue == test_15) {
                            test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1165)))).boolEnum () ;
                            if (kBoolTrue == test_15) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1166)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1166)) ;
                              }
                              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1168)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1168)), object->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1168))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1167)) ;
                            }
                          }
                          if (kBoolFalse == test_15) {
                            TC_Array <C_FixItDescription> fixItArray16 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1171)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1171)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1171)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1171)), fixItArray16  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1171)) ;
                            result_result.drop () ; // Release error dropped variable
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
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlChar_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                      extensionGetter_gtlChar_performGetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlChar_performGetter (defineExtensionGetter_gtlChar_performGetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension setter '@gtlChar performSetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionSetter_gtlChar_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlChar * object = (cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1184)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1185)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1185)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1186)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1186)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1186)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1186)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1186)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_37479 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_37479.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1187)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1187)) ;
      }
      object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1188)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1189)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1190)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1190)) ;
        }
        object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1191)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1192)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlChar temp_4 = object ;
          GALGAS_gtlData var_copy_37775 = temp_4 ;
          callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1194)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1195)), constinArgument_context, constinArgument_lib, var_copy_37775, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1194)) ;
          GALGAS_gtlChar temp_5 ;
          if (var_copy_37775.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlChar *> (var_copy_37775.ptr ())) {
              temp_5 = (cPtr_gtlChar *) var_copy_37775.ptr () ;
            }else{
              inCompiler->castError ("gtlChar", var_copy_37775.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1201)) ;
            }
          }
          object->mProperty_value = temp_5.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1201)) ;
          object->mProperty_where = var_copy_37775.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1202)) ;
          object->mProperty_meta = var_copy_37775.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 1203)) ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1205)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1205)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1205)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1205)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1205)) ;
      }
    }
  }
}
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionSetter_gtlChar_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                      extensionSetter_gtlChar_performSetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gSetter_gtlChar_performSetter (defineExtensionSetter_gtlChar_performSetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt desc'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlInt_desc (const cPtr_gtlData * inObject,
                                                  const GALGAS_uint constinArgument_tab,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1218)).add_operation (GALGAS_string ("integer: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1218)).add_operation (object->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1219)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1219)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1219)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_desc) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_desc (defineExtensionGetter_gtlInt_desc, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlInt string'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlInt_string (const cPtr_gtlData * inObject,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = object->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1222)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                               extensionGetter_gtlInt_string) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_string (defineExtensionGetter_gtlInt_string, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlInt lstring'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_lstring extensionGetter_gtlInt_lstring (const cPtr_gtlData * inObject,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = GALGAS_lstring::constructor_new (object->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1225)), object->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1225)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                extensionGetter_gtlInt_lstring) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_lstring (defineExtensionGetter_gtlInt_lstring, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt bool'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bool extensionGetter_gtlInt_bool (const cPtr_gtlData * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast an int to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1229)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_bool) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_bool (defineExtensionGetter_gtlInt_bool, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                      Overriding extension getter '@gtlInt int'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bigint extensionGetter_gtlInt_int (const cPtr_gtlData * inObject,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = object->mProperty_value ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                            extensionGetter_gtlInt_int) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_int (defineExtensionGetter_gtlInt_int, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt float'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_double extensionGetter_gtlInt_float (const cPtr_gtlData * inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = object->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1237)).getter_double (SOURCE_FILE ("gtl_data_types.galgas", 1237)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_float) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_float (defineExtensionGetter_gtlInt_float, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlInt plusOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_plusOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  const GALGAS_gtlInt temp_0 = object ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                               extensionGetter_gtlInt_plusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_plusOp (defineExtensionGetter_gtlInt_plusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlInt minusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_minusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1243)), object->mProperty_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1243))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1243)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                extensionGetter_gtlInt_minusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_minusOp (defineExtensionGetter_gtlInt_minusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt notOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_notOp (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1247)), object->mProperty_value.operator_tilde (SOURCE_FILE ("gtl_data_types.galgas", 1247))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1247)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_notOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_notOp (defineExtensionGetter_gtlInt_notOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt addOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_addOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1255)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1254)), object->mProperty_value.add_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1255)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1255))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1252)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1258)), GALGAS_string ("*int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1258)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_addOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_addOp (defineExtensionGetter_gtlInt_addOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt subOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_subOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1267)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1266)), object->mProperty_value.substract_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1267)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1267))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1264)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1270)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1270)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_subOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_subOp (defineExtensionGetter_gtlInt_subOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt mulOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_mulOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1279)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1278)), object->mProperty_value.multiply_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1279)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1279))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1276)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1282)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1282)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_mulOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_mulOp (defineExtensionGetter_gtlInt_mulOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt divOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_divOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1291)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1290)), object->mProperty_value.divide_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1291)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1291))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1288)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1294)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1294)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_divOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_divOp (defineExtensionGetter_gtlInt_divOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt modOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_modOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1303)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1302)), object->mProperty_value.modulo_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1303)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1303))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1300)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1306)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1306)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_modOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_modOp (defineExtensionGetter_gtlInt_modOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt andOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_andOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1315)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1314)), object->mProperty_value.operator_and (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1315)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1315))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1312)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1318)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1318)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_andOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_andOp (defineExtensionGetter_gtlInt_andOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt orOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_orOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1327)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1326)), object->mProperty_value.operator_or (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1327)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1327))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1324)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1330)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1330)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_orOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_orOp (defineExtensionGetter_gtlInt_orOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt xorOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_xorOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1339)) ;
        }
      }
      result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1338)), object->mProperty_value.operator_xor (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1339)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1339))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1336)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1342)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1342)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_xorOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_xorOp (defineExtensionGetter_gtlInt_xorOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt slOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_slOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1348)) ;
        }
      }
      GALGAS_bigint var_r_41615 = temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1348)) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_r_41615.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1349)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_gtlInt temp_3 ;
          if (constinArgument_right.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
              temp_3 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1353)) ;
            }
          }
          result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1352)), object->mProperty_value.left_shift_operation (temp_3.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1353)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1353)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1353))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1350)) ;
        }
      }
      if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1356)), GALGAS_string ("positive int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1356)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1359)), GALGAS_string ("int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1359)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_slOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_slOp (defineExtensionGetter_gtlInt_slOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt srOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_srOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1365)) ;
        }
      }
      GALGAS_bigint var_r_42049 = temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1365)) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_r_42049.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1366)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_result = GALGAS_gtlInt::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1367)), object->mProperty_value.right_shift_operation (var_r_42049.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1367)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1367))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1367)) ;
        }
      }
      if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1369)), GALGAS_string ("positive int expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1369)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1372)), GALGAS_string ("int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_srOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_srOp (defineExtensionGetter_gtlInt_srOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt neqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_neqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1381)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1380)), GALGAS_bool (kIsNotEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1381))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1378)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1384)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1384)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                              extensionGetter_gtlInt_neqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_neqOp (defineExtensionGetter_gtlInt_neqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt eqOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_eqOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1393)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1392)), GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1393))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1390)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1396)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1396)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_eqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_eqOp (defineExtensionGetter_gtlInt_eqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt gtOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_gtOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1405)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1404)), GALGAS_bool (kIsStrictSup, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1405))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1402)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1408)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1408)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_gtOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_gtOp (defineExtensionGetter_gtlInt_gtOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt geOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_geOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1417)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1416)), GALGAS_bool (kIsSupOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1417))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1414)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1420)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1420)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_geOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_geOp (defineExtensionGetter_gtlInt_geOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt ltOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_ltOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1429)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1428)), GALGAS_bool (kIsStrictInf, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1429))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1426)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1432)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1432)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_ltOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_ltOp (defineExtensionGetter_gtlInt_ltOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlInt leOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_leOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1441)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1440)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1441))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1438)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1444)), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1444)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                             extensionGetter_gtlInt_leOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_leOp (defineExtensionGetter_gtlInt_leOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlInt embeddedType'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_type extensionGetter_gtlInt_embeddedType (const cPtr_gtlData * /* inObject */,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_bigint) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                     extensionGetter_gtlInt_embeddedType) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_embeddedType (defineExtensionGetter_gtlInt_embeddedType, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Overriding extension method '@gtlInt addMyValue'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_gtlInt_addMyValue (const cPtr_gtlData * inObject,
                                               GALGAS_objectlist & ioArgument_objectList,
                                               C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  ioArgument_objectList.addAssign_operation (object->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1455))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1455)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_gtlInt_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                   extensionMethod_gtlInt_addMyValue) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_gtlInt_addMyValue (defineExtensionMethod_gtlInt_addMyValue, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlInt performGetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlInt_performGetter (const cPtr_gtlData * inObject,
                                                            const GALGAS_lstring constinArgument_methodName,
                                                            const GALGAS_gtlDataList constinArgument_arguments,
                                                            const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_library constinArgument_lib,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlInt * object = (const cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1468)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1469)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1469)) ;
      }
      const GALGAS_gtlInt temp_1 = object ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1471)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1471)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1471))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1470)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("padded").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1473)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1474)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1474)) ;
        }
        GALGAS_gtlInt temp_3 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)).ptr ())) {
            temp_3 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)) ;
          }
        }
        GALGAS_uint var_fieldSize_44871 = temp_3.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1475)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)) ;
        const GALGAS_gtlInt temp_4 = object ;
        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1477)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1478)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_4.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479)).getter_stringByLeftAndRightPadding (var_fieldSize_44871, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1476)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("leftPadded").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1481)))).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1482)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1482)) ;
          }
          GALGAS_gtlInt temp_6 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1483)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1483)).ptr ())) {
              temp_6 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1483)).ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1483)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1483)) ;
            }
          }
          GALGAS_uint var_fieldSize_45212 = temp_6.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1483)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1483)) ;
          const GALGAS_gtlInt temp_7 = object ;
          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1485)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1486)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_7.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1487)).getter_stringByLeftPadding (var_fieldSize_45212, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1487))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1484)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("rightPadded").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1489)))).boolEnum () ;
          if (kBoolTrue == test_8) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1490)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1490)) ;
            }
            GALGAS_gtlInt temp_9 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1491)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1491)).ptr ())) {
                temp_9 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1491)).ptr () ;
              }else{
                inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1491)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1491)) ;
              }
            }
            GALGAS_uint var_fieldSize_45547 = temp_9.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1491)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1491)) ;
            const GALGAS_gtlInt temp_10 = object ;
            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1493)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1494)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_10.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1495)).getter_stringByRightPadding (var_fieldSize_45547, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1495))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1492)) ;
          }
        }
        if (kBoolFalse == test_8) {
          enumGalgasBool test_11 = kBoolTrue ;
          if (kBoolTrue == test_11) {
            test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("hexString").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1497)))).boolEnum () ;
            if (kBoolTrue == test_11) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1498)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1498)) ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1500)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1500)), object->mProperty_value.getter_hexString (SOURCE_FILE ("gtl_data_types.galgas", 1500))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1499)) ;
            }
          }
          if (kBoolFalse == test_11) {
            enumGalgasBool test_12 = kBoolTrue ;
            if (kBoolTrue == test_12) {
              test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("xString").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1502)))).boolEnum () ;
              if (kBoolTrue == test_12) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1503)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1503)) ;
                }
                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1505)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1505)), object->mProperty_value.getter_xString (SOURCE_FILE ("gtl_data_types.galgas", 1505))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1504)) ;
              }
            }
            if (kBoolFalse == test_12) {
              enumGalgasBool test_13 = kBoolTrue ;
              if (kBoolTrue == test_13) {
                test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBytes").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1507)))).boolEnum () ;
                if (kBoolTrue == test_13) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1508)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1508)) ;
                  }
                  result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1510)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1511)), object->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1512)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1512)).substract_operation (GALGAS_uint ((uint32_t) 1U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1512)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1512)).divide_operation (GALGAS_uint ((uint32_t) 8U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1512)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1512)).add_operation (GALGAS_uint ((uint32_t) 1U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1512)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1512))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1509)) ;
                }
              }
              if (kBoolFalse == test_13) {
                enumGalgasBool test_14 = kBoolTrue ;
                if (kBoolTrue == test_14) {
                  test_14 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBytes").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1514)))).boolEnum () ;
                  if (kBoolTrue == test_14) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1515)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1515)) ;
                    }
                    result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1517)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1518)), object->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1519)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1519)).substract_operation (GALGAS_uint ((uint32_t) 1U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1519)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1519)).divide_operation (GALGAS_uint ((uint32_t) 8U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1519)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1519)).add_operation (GALGAS_uint ((uint32_t) 1U).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1519)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1519))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1516)) ;
                  }
                }
                if (kBoolFalse == test_14) {
                  enumGalgasBool test_15 = kBoolTrue ;
                  if (kBoolTrue == test_15) {
                    test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBits").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1521)))).boolEnum () ;
                    if (kBoolTrue == test_15) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1522)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1522)) ;
                      }
                      result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1524)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1525)), object->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1526)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1526))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1523)) ;
                    }
                  }
                  if (kBoolFalse == test_15) {
                    enumGalgasBool test_16 = kBoolTrue ;
                    if (kBoolTrue == test_16) {
                      test_16 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBits").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1528)))).boolEnum () ;
                      if (kBoolTrue == test_16) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1529)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1529)) ;
                        }
                        result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1531)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1532)), object->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1533)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1533))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1530)) ;
                      }
                    }
                    if (kBoolFalse == test_16) {
                      enumGalgasBool test_17 = kBoolTrue ;
                      if (kBoolTrue == test_17) {
                        test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("sign").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1535)))).boolEnum () ;
                        if (kBoolTrue == test_17) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1536)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1536)) ;
                          }
                          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1538)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1539)), object->mProperty_value.getter_sign (SOURCE_FILE ("gtl_data_types.galgas", 1540)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1540))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1537)) ;
                        }
                      }
                      if (kBoolFalse == test_17) {
                        enumGalgasBool test_18 = kBoolTrue ;
                        if (kBoolTrue == test_18) {
                          test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInByte").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1542)))).boolEnum () ;
                          if (kBoolTrue == test_18) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1543)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1543)) ;
                            }
                            result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1545)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1546)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1547)).objectCompare (GALGAS_uint ((uint32_t) 8U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1544)) ;
                          }
                        }
                        if (kBoolFalse == test_18) {
                          enumGalgasBool test_19 = kBoolTrue ;
                          if (kBoolTrue == test_19) {
                            test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInByte").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1549)))).boolEnum () ;
                            if (kBoolTrue == test_19) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1550)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1550)) ;
                              }
                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1552)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1553)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1554)).objectCompare (GALGAS_uint ((uint32_t) 8U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1551)) ;
                            }
                          }
                          if (kBoolFalse == test_19) {
                            enumGalgasBool test_20 = kBoolTrue ;
                            if (kBoolTrue == test_20) {
                              test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInShort").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1556)))).boolEnum () ;
                              if (kBoolTrue == test_20) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1557)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1557)) ;
                                }
                                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1559)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1560)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1561)).objectCompare (GALGAS_uint ((uint32_t) 16U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1558)) ;
                              }
                            }
                            if (kBoolFalse == test_20) {
                              enumGalgasBool test_21 = kBoolTrue ;
                              if (kBoolTrue == test_21) {
                                test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInShort").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1563)))).boolEnum () ;
                                if (kBoolTrue == test_21) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1564)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1564)) ;
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1566)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1567)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1568)).objectCompare (GALGAS_uint ((uint32_t) 16U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1565)) ;
                                }
                              }
                              if (kBoolFalse == test_21) {
                                enumGalgasBool test_22 = kBoolTrue ;
                                if (kBoolTrue == test_22) {
                                  test_22 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLong").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1570)))).boolEnum () ;
                                  if (kBoolTrue == test_22) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1571)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1571)) ;
                                    }
                                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1573)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1574)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1575)).objectCompare (GALGAS_uint ((uint32_t) 32U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1572)) ;
                                  }
                                }
                                if (kBoolFalse == test_22) {
                                  enumGalgasBool test_23 = kBoolTrue ;
                                  if (kBoolTrue == test_23) {
                                    test_23 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLong").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1577)))).boolEnum () ;
                                    if (kBoolTrue == test_23) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1578)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1578)) ;
                                      }
                                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1580)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1581)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1582)).objectCompare (GALGAS_uint ((uint32_t) 32U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1579)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_23) {
                                    enumGalgasBool test_24 = kBoolTrue ;
                                    if (kBoolTrue == test_24) {
                                      test_24 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLongLong").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1584)))).boolEnum () ;
                                      if (kBoolTrue == test_24) {
                                        {
                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1585)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1585)) ;
                                        }
                                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1587)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1588)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1589)).objectCompare (GALGAS_uint ((uint32_t) 64U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1586)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_24) {
                                      enumGalgasBool test_25 = kBoolTrue ;
                                      if (kBoolTrue == test_25) {
                                        test_25 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLongLong").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1591)))).boolEnum () ;
                                        if (kBoolTrue == test_25) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1592)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1592)) ;
                                          }
                                          result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1594)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1595)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1596)).objectCompare (GALGAS_uint ((uint32_t) 64U)))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1593)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_25) {
                                        enumGalgasBool test_26 = kBoolTrue ;
                                        if (kBoolTrue == test_26) {
                                          test_26 = GALGAS_bool (kIsEqual, GALGAS_string ("abs").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1598)))).boolEnum () ;
                                          if (kBoolTrue == test_26) {
                                            {
                                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1599)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1599)) ;
                                            }
                                            result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1601)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1602)), object->mProperty_value.getter_abs (SOURCE_FILE ("gtl_data_types.galgas", 1603))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1600)) ;
                                          }
                                        }
                                        if (kBoolFalse == test_26) {
                                          enumGalgasBool test_27 = kBoolTrue ;
                                          if (kBoolTrue == test_27) {
                                            test_27 = GALGAS_bool (kIsEqual, GALGAS_string ("bitAtIndex").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1605)))).boolEnum () ;
                                            if (kBoolTrue == test_27) {
                                              {
                                              routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1606)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1606)) ;
                                              }
                                              GALGAS_gtlInt temp_28 ;
                                              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)).isValid ()) {
                                                if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)).ptr ())) {
                                                  temp_28 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)).ptr () ;
                                                }else{
                                                  inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)) ;
                                                }
                                              }
                                              GALGAS_uint var_index_49743 = temp_28.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1607)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)) ;
                                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1609)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1610)), object->mProperty_value.getter_bitAtIndex (var_index_49743 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1608)) ;
                                            }
                                          }
                                          if (kBoolFalse == test_27) {
                                            enumGalgasBool test_29 = kBoolTrue ;
                                            if (kBoolTrue == test_29) {
                                              test_29 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1613)))).boolEnum () ;
                                              if (kBoolTrue == test_29) {
                                                {
                                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1614)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1614)) ;
                                                }
                                                const GALGAS_gtlInt temp_30 = object ;
                                                result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1616)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1616)), temp_30.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1616))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1615)) ;
                                              }
                                            }
                                            if (kBoolFalse == test_29) {
                                              enumGalgasBool test_31 = kBoolTrue ;
                                              if (kBoolTrue == test_31) {
                                                test_31 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1618)))).boolEnum () ;
                                                if (kBoolTrue == test_31) {
                                                  {
                                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)) ;
                                                  }
                                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1621)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1621)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1620)) ;
                                                }
                                              }
                                              if (kBoolFalse == test_31) {
                                                enumGalgasBool test_32 = kBoolTrue ;
                                                if (kBoolTrue == test_32) {
                                                  test_32 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1623)))).boolEnum () ;
                                                  if (kBoolTrue == test_32) {
                                                    {
                                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1624)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1624)) ;
                                                    }
                                                    result_result = GALGAS_gtlString::constructor_new (object->mProperty_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1626)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1626)), object->mProperty_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1626))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1625)) ;
                                                  }
                                                }
                                                if (kBoolFalse == test_32) {
                                                  enumGalgasBool test_33 = kBoolTrue ;
                                                  if (kBoolTrue == test_33) {
                                                    test_33 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1628)).boolEnum () ;
                                                    if (kBoolTrue == test_33) {
                                                      const GALGAS_gtlInt temp_34 = object ;
                                                      result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1630)), constinArgument_context, constinArgument_lib, temp_34, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)) ;
                                                    }
                                                  }
                                                  if (kBoolFalse == test_33) {
                                                    enumGalgasBool test_35 = kBoolTrue ;
                                                    if (kBoolTrue == test_35) {
                                                      test_35 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1636)))).boolEnum () ;
                                                      if (kBoolTrue == test_35) {
                                                        {
                                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1637)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1637)) ;
                                                        }
                                                        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1639)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1639)), object->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1639))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1638)) ;
                                                      }
                                                    }
                                                    if (kBoolFalse == test_35) {
                                                      TC_Array <C_FixItDescription> fixItArray36 ;
                                                      inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1642)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1642)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)), fixItArray36  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)) ;
                                                      result_result.drop () ; // Release error dropped variable
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
                }
              }
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlInt_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                      extensionGetter_gtlInt_performGetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlInt_performGetter (defineExtensionGetter_gtlInt_performGetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension setter '@gtlInt performSetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionSetter_gtlInt_performSetter (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlInt * object = (cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1655)).objectCompare (GALGAS_string ("setBitAtIndex"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_boolIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1656)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1656)) ;
      }
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1657)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1657)).ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1657)).ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1657)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1657)) ;
        }
      }
      GALGAS_bool var_bit_51449 = temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1657)) ;
      GALGAS_gtlInt temp_2 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1658)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1658)).ptr ())) {
          temp_2 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1658)).ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1658)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1658)) ;
        }
      }
      GALGAS_uint var_index_51514 = temp_2.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1658)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1658)) ;
      {
      object->mProperty_value.setter_setBitAtIndex (var_bit_51449, var_index_51514 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1659)) ;
      }
      object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1660)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1661)).objectCompare (GALGAS_string ("complementBitAtIndex"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)) ;
        }
        GALGAS_gtlInt temp_4 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr ())) {
            temp_4 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)) ;
          }
        }
        GALGAS_uint var_index_51765 = temp_4.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1663)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)) ;
        {
        object->mProperty_value.setter_complementBitAtIndex (var_index_51765 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1664)) ;
        }
        object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1665)) ;
      }
    }
    if (kBoolFalse == test_3) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1666)))).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)) ;
          }
          GALGAS_gtlString temp_6 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr ())) {
              temp_6 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr () ;
            }else{
              inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)) ;
            }
          }
          GALGAS_gtlString var_descriptionToSet_52022 = temp_6 ;
          {
          object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_52022.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1669)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1669)) ;
          }
          object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1670)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1671)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1672)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1672)) ;
            }
            object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1673)) ;
          }
        }
        if (kBoolFalse == test_7) {
          enumGalgasBool test_8 = kBoolTrue ;
          if (kBoolTrue == test_8) {
            test_8 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1674)).boolEnum () ;
            if (kBoolTrue == test_8) {
              const GALGAS_gtlInt temp_9 = object ;
              GALGAS_gtlData var_copy_52317 = temp_9 ;
              callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1676)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1677)), constinArgument_context, constinArgument_lib, var_copy_52317, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1676)) ;
              GALGAS_gtlInt temp_10 ;
              if (var_copy_52317.isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlInt *> (var_copy_52317.ptr ())) {
                  temp_10 = (cPtr_gtlInt *) var_copy_52317.ptr () ;
                }else{
                  inCompiler->castError ("gtlInt", var_copy_52317.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1683)) ;
                }
              }
              object->mProperty_value = temp_10.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1683)) ;
              object->mProperty_where = var_copy_52317.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1684)) ;
              object->mProperty_meta = var_copy_52317.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 1685)) ;
            }
          }
          if (kBoolFalse == test_8) {
            TC_Array <C_FixItDescription> fixItArray11 ;
            inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1687)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1687)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1687)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1687)), fixItArray11  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1687)) ;
          }
        }
      }
    }
  }
}
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionSetter_gtlInt_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                      extensionSetter_gtlInt_performSetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gSetter_gtlInt_performSetter (defineExtensionSetter_gtlInt_performSetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat desc'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlFloat_desc (const cPtr_gtlData * inObject,
                                                    const GALGAS_uint constinArgument_tab,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1700)).add_operation (GALGAS_string ("float: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1700)).add_operation (object->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1701)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1701)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1701)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_desc) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_desc (defineExtensionGetter_gtlFloat_desc, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlFloat string'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlFloat_string (const cPtr_gtlData * inObject,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = object->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1704)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                               extensionGetter_gtlFloat_string) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_string (defineExtensionGetter_gtlFloat_string, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlFloat lstring'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_lstring extensionGetter_gtlFloat_lstring (const cPtr_gtlData * inObject,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = GALGAS_lstring::constructor_new (object->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1707)), object->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1707)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                extensionGetter_gtlFloat_lstring) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_lstring (defineExtensionGetter_gtlFloat_lstring, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat bool'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bool extensionGetter_gtlFloat_bool (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a float to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1711)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_bool) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_bool (defineExtensionGetter_gtlFloat_bool, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlFloat int'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bigint extensionGetter_gtlFloat_int (const cPtr_gtlData * inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = object->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1715)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1715)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                            extensionGetter_gtlFloat_int) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_int (defineExtensionGetter_gtlFloat_int, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat float'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_double extensionGetter_gtlFloat_float (const cPtr_gtlData * inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = object->mProperty_value ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_float) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_float (defineExtensionGetter_gtlFloat_float, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlFloat plusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_plusOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  const GALGAS_gtlFloat temp_0 = object ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                               extensionGetter_gtlFloat_plusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_plusOp (defineExtensionGetter_gtlFloat_plusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlFloat minusOp'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_minusOp (const cPtr_gtlData * inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  result_result = GALGAS_gtlFloat::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1725)), object->mProperty_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1725))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1725)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                extensionGetter_gtlFloat_minusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_minusOp (defineExtensionGetter_gtlFloat_minusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat notOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_notOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1729)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_notOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_notOp (defineExtensionGetter_gtlFloat_notOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat addOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_addOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1737)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1736)), object->mProperty_value.add_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1737)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1737))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1734)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1740)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1740)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_addOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_addOp (defineExtensionGetter_gtlFloat_addOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat subOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_subOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1749)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1748)), object->mProperty_value.substract_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1749)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1749))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1746)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1752)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1752)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_subOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_subOp (defineExtensionGetter_gtlFloat_subOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat mulOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_mulOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1761)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1760)), object->mProperty_value.multiply_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1761)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1761))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1758)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1764)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1764)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_mulOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_mulOp (defineExtensionGetter_gtlFloat_mulOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat divOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_divOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1773)) ;
        }
      }
      result_result = GALGAS_gtlFloat::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1772)), object->mProperty_value.divide_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1773)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1773))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1770)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1776)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1776)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_divOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_divOp (defineExtensionGetter_gtlFloat_divOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat modOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_modOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData /* constinArgument_right */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1781)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_modOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_modOp (defineExtensionGetter_gtlFloat_modOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat andOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_andOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData /* constinArgument_right */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1785)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_andOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_andOp (defineExtensionGetter_gtlFloat_andOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat orOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_orOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1789)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_orOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_orOp (defineExtensionGetter_gtlFloat_orOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat xorOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_xorOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData /* constinArgument_right */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1793)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_xorOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_xorOp (defineExtensionGetter_gtlFloat_xorOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat slOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_slOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1797)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_slOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_slOp (defineExtensionGetter_gtlFloat_slOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat srOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_srOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1801)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_srOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_srOp (defineExtensionGetter_gtlFloat_srOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat neqOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_neqOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1809)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1808)), GALGAS_bool (kIsNotEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1809))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1806)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1812)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1812)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                              extensionGetter_gtlFloat_neqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_neqOp (defineExtensionGetter_gtlFloat_neqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat eqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_eqOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1821)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1820)), GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1821))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1818)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1824)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1824)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_eqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_eqOp (defineExtensionGetter_gtlFloat_eqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat gtOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_gtOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1833)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1832)), GALGAS_bool (kIsStrictSup, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1833))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1830)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1836)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1836)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_gtOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_gtOp (defineExtensionGetter_gtlFloat_gtOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat geOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_geOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1845)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1844)), GALGAS_bool (kIsSupOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1845))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1842)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1848)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1848)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_geOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_geOp (defineExtensionGetter_gtlFloat_geOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat ltOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_ltOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1857)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1856)), GALGAS_bool (kIsStrictInf, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1857))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1854)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1860)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1860)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_ltOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_ltOp (defineExtensionGetter_gtlFloat_ltOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlFloat leOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_leOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1869)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1868)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1869))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1866)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 1872)), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1872)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                             extensionGetter_gtlFloat_leOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_leOp (defineExtensionGetter_gtlFloat_leOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlFloat embeddedType'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_type extensionGetter_gtlFloat_embeddedType (const cPtr_gtlData * /* inObject */,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_double) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                     extensionGetter_gtlFloat_embeddedType) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_embeddedType (defineExtensionGetter_gtlFloat_embeddedType, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension method '@gtlFloat addMyValue'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_gtlFloat_addMyValue (const cPtr_gtlData * inObject,
                                                 GALGAS_objectlist & ioArgument_objectList,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  ioArgument_objectList.addAssign_operation (object->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1883))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1883)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_gtlFloat_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                   extensionMethod_gtlFloat_addMyValue) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_gtlFloat_addMyValue (defineExtensionMethod_gtlFloat_addMyValue, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlFloat performGetter'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlFloat_performGetter (const cPtr_gtlData * inObject,
                                                              const GALGAS_lstring constinArgument_methodName,
                                                              const GALGAS_gtlDataList constinArgument_arguments,
                                                              const GALGAS_gtlContext constinArgument_context,
                                                              const GALGAS_library constinArgument_lib,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlFloat * object = (const cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1896)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1897)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1897)) ;
      }
      const GALGAS_gtlFloat temp_1 = object ;
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1899)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1899)), callExtensionGetter_string ((const cPtr_gtlFloat *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1899))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1898)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("cos").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1901)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1902)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1902)) ;
        }
        result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1904)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1904)), object->mProperty_value.getter_cos (SOURCE_FILE ("gtl_data_types.galgas", 1904))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1903)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("sin").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1906)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1907)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1907)) ;
          }
          result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1909)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1909)), object->mProperty_value.getter_sin (SOURCE_FILE ("gtl_data_types.galgas", 1909))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1908)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("tan").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1911)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1912)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1912)) ;
            }
            result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1914)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1914)), object->mProperty_value.getter_tan (SOURCE_FILE ("gtl_data_types.galgas", 1914))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1913)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("cosDegree").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1916)))).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1917)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1917)) ;
              }
              result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1919)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1919)), object->mProperty_value.getter_cosDegree (SOURCE_FILE ("gtl_data_types.galgas", 1919))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1918)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("sinDegree").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1921)))).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1922)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1922)) ;
                }
                result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1924)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1924)), object->mProperty_value.getter_sinDegree (SOURCE_FILE ("gtl_data_types.galgas", 1924))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1923)) ;
              }
            }
            if (kBoolFalse == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("tanDegree").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1926)))).boolEnum () ;
                if (kBoolTrue == test_7) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1927)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1927)) ;
                  }
                  result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1929)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1929)), object->mProperty_value.getter_tanDegree (SOURCE_FILE ("gtl_data_types.galgas", 1929))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1928)) ;
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("exp").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1931)))).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1932)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1932)) ;
                    }
                    result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1934)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1934)), object->mProperty_value.getter_exp (SOURCE_FILE ("gtl_data_types.galgas", 1934))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1933)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  enumGalgasBool test_9 = kBoolTrue ;
                  if (kBoolTrue == test_9) {
                    test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("logn").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1936)))).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1937)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1937)) ;
                      }
                      result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1939)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1939)), object->mProperty_value.getter_logn (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1939))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1938)) ;
                    }
                  }
                  if (kBoolFalse == test_9) {
                    enumGalgasBool test_10 = kBoolTrue ;
                    if (kBoolTrue == test_10) {
                      test_10 = GALGAS_bool (kIsEqual, GALGAS_string ("log2").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1941)))).boolEnum () ;
                      if (kBoolTrue == test_10) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1942)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1942)) ;
                        }
                        result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1944)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1944)), object->mProperty_value.getter_log_32_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1944))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1943)) ;
                      }
                    }
                    if (kBoolFalse == test_10) {
                      enumGalgasBool test_11 = kBoolTrue ;
                      if (kBoolTrue == test_11) {
                        test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("log10").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1946)))).boolEnum () ;
                        if (kBoolTrue == test_11) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1947)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1947)) ;
                          }
                          result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1949)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1949)), object->mProperty_value.getter_log_31__30_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1949))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1948)) ;
                        }
                      }
                      if (kBoolFalse == test_11) {
                        enumGalgasBool test_12 = kBoolTrue ;
                        if (kBoolTrue == test_12) {
                          test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("sqrt").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1951)))).boolEnum () ;
                          if (kBoolTrue == test_12) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1952)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1952)) ;
                            }
                            result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1954)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1954)), object->mProperty_value.getter_sqrt (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1954))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1953)) ;
                          }
                        }
                        if (kBoolFalse == test_12) {
                          enumGalgasBool test_13 = kBoolTrue ;
                          if (kBoolTrue == test_13) {
                            test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("power").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1956)))).boolEnum () ;
                            if (kBoolTrue == test_13) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_floatArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1957)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1957)) ;
                              }
                              GALGAS_gtlFloat temp_14 ;
                              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1958)).isValid ()) {
                                if (NULL != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1958)).ptr ())) {
                                  temp_14 = (cPtr_gtlFloat *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1958)).ptr () ;
                                }else{
                                  inCompiler->castError ("gtlFloat", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1958)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1958)) ;
                                }
                              }
                              GALGAS_double var_power_60563 = temp_14.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 1958)) ;
                              result_result = GALGAS_gtlFloat::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1960)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1960)), object->mProperty_value.getter_power (var_power_60563, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1960))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1959)) ;
                            }
                          }
                          if (kBoolFalse == test_13) {
                            enumGalgasBool test_15 = kBoolTrue ;
                            if (kBoolTrue == test_15) {
                              test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1962)))).boolEnum () ;
                              if (kBoolTrue == test_15) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)) ;
                                }
                                const GALGAS_gtlFloat temp_16 = object ;
                                result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1965)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1965)), temp_16.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1965))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1964)) ;
                              }
                            }
                            if (kBoolFalse == test_15) {
                              enumGalgasBool test_17 = kBoolTrue ;
                              if (kBoolTrue == test_17) {
                                test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1967)))).boolEnum () ;
                                if (kBoolTrue == test_17) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1968)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1968)) ;
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1970)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1970)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1969)) ;
                                }
                              }
                              if (kBoolFalse == test_17) {
                                enumGalgasBool test_18 = kBoolTrue ;
                                if (kBoolTrue == test_18) {
                                  test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("int").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1972)))).boolEnum () ;
                                  if (kBoolTrue == test_18) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1973)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1973)) ;
                                    }
                                    result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1975)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1975)), object->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1975)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1975))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1974)) ;
                                  }
                                }
                                if (kBoolFalse == test_18) {
                                  enumGalgasBool test_19 = kBoolTrue ;
                                  if (kBoolTrue == test_19) {
                                    test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1977)))).boolEnum () ;
                                    if (kBoolTrue == test_19) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1978)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1978)) ;
                                      }
                                      result_result = GALGAS_gtlString::constructor_new (object->mProperty_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1980)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1980)), object->mProperty_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1980))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1979)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_19) {
                                    enumGalgasBool test_20 = kBoolTrue ;
                                    if (kBoolTrue == test_20) {
                                      test_20 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1982)).boolEnum () ;
                                      if (kBoolTrue == test_20) {
                                        const GALGAS_gtlFloat temp_21 = object ;
                                        result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1983)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1984)), constinArgument_context, constinArgument_lib, temp_21, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1983)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_20) {
                                      enumGalgasBool test_22 = kBoolTrue ;
                                      if (kBoolTrue == test_22) {
                                        test_22 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1990)))).boolEnum () ;
                                        if (kBoolTrue == test_22) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1991)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1991)) ;
                                          }
                                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1993)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1993)), object->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1993))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1992)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_22) {
                                        TC_Array <C_FixItDescription> fixItArray23 ;
                                        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 1996)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1996)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1996)).add_operation (GALGAS_string ("' for float target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1996)), fixItArray23  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1996)) ;
                                        result_result.drop () ; // Release error dropped variable
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
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlFloat_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                      extensionGetter_gtlFloat_performGetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlFloat_performGetter (defineExtensionGetter_gtlFloat_performGetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension setter '@gtlFloat performSetter'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionSetter_gtlFloat_performSetter (cPtr_gtlData * inObject,
                                                    const GALGAS_lstring constinArgument_methodName,
                                                    const GALGAS_gtlDataList constinArgument_arguments,
                                                    const GALGAS_gtlContext constinArgument_context,
                                                    const GALGAS_library constinArgument_lib,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlFloat * object = (cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2009)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2010)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2010)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2011)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2011)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2011)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2011)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2011)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_62456 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_62456.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2012)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2012)) ;
      }
      object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2013)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2014)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2015)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2015)) ;
        }
        object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2016)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2017)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlFloat temp_4 = object ;
          GALGAS_gtlData var_copy_62753 = temp_4 ;
          callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2019)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2020)), constinArgument_context, constinArgument_lib, var_copy_62753, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2019)) ;
          GALGAS_gtlFloat temp_5 ;
          if (var_copy_62753.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlFloat *> (var_copy_62753.ptr ())) {
              temp_5 = (cPtr_gtlFloat *) var_copy_62753.ptr () ;
            }else{
              inCompiler->castError ("gtlFloat", var_copy_62753.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2026)) ;
            }
          }
          object->mProperty_value = temp_5.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2026)) ;
          object->mProperty_where = var_copy_62753.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2027)) ;
          object->mProperty_meta = var_copy_62753.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 2028)) ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2030)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2030)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2030)).add_operation (GALGAS_string ("' for float target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2030)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2030)) ;
      }
    }
  }
}
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionSetter_gtlFloat_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                      extensionSetter_gtlFloat_performSetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gSetter_gtlFloat_performSetter (defineExtensionSetter_gtlFloat_performSetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString desc'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlString_desc (const cPtr_gtlData * inObject,
                                                     const GALGAS_uint constinArgument_tab,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2043)).add_operation (GALGAS_string ("string: \""), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2043)).add_operation (object->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2044)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2044)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_desc) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_desc (defineExtensionGetter_gtlString_desc, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString string'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlString_string (const cPtr_gtlData * inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  result_result = object->mProperty_value ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                               extensionGetter_gtlString_string) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_string (defineExtensionGetter_gtlString_string, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Overriding extension getter '@gtlString lstring'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_lstring extensionGetter_gtlString_lstring (const cPtr_gtlData * inObject,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  result_result = GALGAS_lstring::constructor_new (object->mProperty_value, object->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2049)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                extensionGetter_gtlString_lstring) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_lstring (defineExtensionGetter_gtlString_lstring, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString bool'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bool extensionGetter_gtlString_bool (const cPtr_gtlData * inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a string to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2052)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_bool) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_bool (defineExtensionGetter_gtlString_bool, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString int'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bigint extensionGetter_gtlString_int (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  result_result = object->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2056)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2056)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                            extensionGetter_gtlString_int) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_int (defineExtensionGetter_gtlString_int, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString float'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_double extensionGetter_gtlString_float (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  result_result = object->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2060)).getter_double (SOURCE_FILE ("gtl_data_types.galgas", 2060)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_float) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_float (defineExtensionGetter_gtlString_float, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString plusOp'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_plusOp (const cPtr_gtlData * inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2064)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                               extensionGetter_gtlString_plusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_plusOp (defineExtensionGetter_gtlString_plusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Overriding extension getter '@gtlString minusOp'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_minusOp (const cPtr_gtlData * inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2068)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                extensionGetter_gtlString_minusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_minusOp (defineExtensionGetter_gtlString_minusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString notOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_notOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2072)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_notOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_notOp (defineExtensionGetter_gtlString_notOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString addOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_addOp (const cPtr_gtlData * inObject,
                                                       const GALGAS_gtlData constinArgument_right,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2080)) ;
        }
      }
      result_result = GALGAS_gtlString::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2079)), object->mProperty_value.add_operation (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2080)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2080))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2077)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2083)), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2083)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_addOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_addOp (defineExtensionGetter_gtlString_addOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString subOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_subOp (const cPtr_gtlData * inObject,
                                                       const GALGAS_gtlData /* constinArgument_right */,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2088)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_subOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_subOp (defineExtensionGetter_gtlString_subOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString mulOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_mulOp (const cPtr_gtlData * inObject,
                                                       const GALGAS_gtlData /* constinArgument_right */,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2092)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_mulOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_mulOp (defineExtensionGetter_gtlString_mulOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString divOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_divOp (const cPtr_gtlData * inObject,
                                                       const GALGAS_gtlData /* constinArgument_right */,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2096)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_divOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_divOp (defineExtensionGetter_gtlString_divOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString modOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_modOp (const cPtr_gtlData * inObject,
                                                       const GALGAS_gtlData /* constinArgument_right */,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2100)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_modOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_modOp (defineExtensionGetter_gtlString_modOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString andOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_andOp (const cPtr_gtlData * inObject,
                                                       const GALGAS_gtlData /* constinArgument_right */,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2104)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_andOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_andOp (defineExtensionGetter_gtlString_andOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString orOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_orOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData /* constinArgument_right */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2108)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_orOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_orOp (defineExtensionGetter_gtlString_orOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString xorOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_xorOp (const cPtr_gtlData * inObject,
                                                       const GALGAS_gtlData /* constinArgument_right */,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2112)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_xorOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_xorOp (defineExtensionGetter_gtlString_xorOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString slOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_slOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData /* constinArgument_right */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2116)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_slOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_slOp (defineExtensionGetter_gtlString_slOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString srOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_srOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData /* constinArgument_right */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2120)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_srOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_srOp (defineExtensionGetter_gtlString_srOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlString neqOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_neqOp (const cPtr_gtlData * inObject,
                                                       const GALGAS_gtlData constinArgument_right,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2128)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2127)), GALGAS_bool (kIsNotEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2128))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2125)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2131)), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2131)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                              extensionGetter_gtlString_neqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_neqOp (defineExtensionGetter_gtlString_neqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString eqOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_eqOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2140)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2139)), GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2140))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2137)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2143)), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2143)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_eqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_eqOp (defineExtensionGetter_gtlString_eqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString gtOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_gtOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2152)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2151)), GALGAS_bool (kIsStrictSup, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2152))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2149)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2155)), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2155)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_gtOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_gtOp (defineExtensionGetter_gtlString_gtOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString geOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_geOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2164)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2163)), GALGAS_bool (kIsSupOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2164))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2161)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2167)), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2167)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_geOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_geOp (defineExtensionGetter_gtlString_geOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString ltOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_ltOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2176)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2175)), GALGAS_bool (kIsStrictInf, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2176))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2173)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2179)), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2179)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_ltOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_ltOp (defineExtensionGetter_gtlString_ltOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlString leOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_leOp (const cPtr_gtlData * inObject,
                                                      const GALGAS_gtlData constinArgument_right,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2188)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2187)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2188))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2185)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2191)), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2191)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                             extensionGetter_gtlString_leOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_leOp (defineExtensionGetter_gtlString_leOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlString embeddedType'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_type extensionGetter_gtlString_embeddedType (const cPtr_gtlData * /* inObject */,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_string) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                     extensionGetter_gtlString_embeddedType) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_embeddedType (defineExtensionGetter_gtlString_embeddedType, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension method '@gtlString addMyValue'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_gtlString_addMyValue (const cPtr_gtlData * inObject,
                                                  GALGAS_objectlist & ioArgument_objectList,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  ioArgument_objectList.addAssign_operation (object->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 2202))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2202)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_gtlString_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                   extensionMethod_gtlString_addMyValue) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_gtlString_addMyValue (defineExtensionMethod_gtlString_addMyValue, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Overriding extension getter '@gtlString performGetter'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlString_performGetter (const cPtr_gtlData * inObject,
                                                               const GALGAS_lstring constinArgument_methodName,
                                                               const GALGAS_gtlDataList constinArgument_arguments,
                                                               const GALGAS_gtlContext constinArgument_context,
                                                               const GALGAS_library constinArgument_lib,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlString * object = (const cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2215)).objectCompare (GALGAS_string ("string"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2216)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2216)) ;
      }
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2218)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2218)), object->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2217)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2220)).objectCompare (GALGAS_string ("charAtIndex"))).boolEnum () ;
      if (kBoolTrue == test_1) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2221)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2221)) ;
        }
        GALGAS_gtlInt temp_2 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2222)).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2222)).ptr ())) {
            temp_2 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2222)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2222)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2222)) ;
          }
        }
        GALGAS_uint var_index_68359 = temp_2.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2222)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2222)) ;
        result_result = GALGAS_gtlChar::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2224)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2224)), object->mProperty_value.getter_characterAtIndex (var_index_68359, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2224))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2223)) ;
      }
    }
    if (kBoolFalse == test_1) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2226)).objectCompare (GALGAS_string ("indexOfChar"))).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_charArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2227)) ;
          }
          GALGAS_gtlChar temp_4 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2228)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2228)).ptr ())) {
              temp_4 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2228)).ptr () ;
            }else{
              inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2228)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2228)) ;
            }
          }
          GALGAS_char var_lookedUpChar_68658 = temp_4.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2228)) ;
          GALGAS_uint var_index_68723 = GALGAS_uint ((uint32_t) 0U) ;
          GALGAS_uint var_length_68744 = object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2230)) ;
          GALGAS_bool var_found_68777 = GALGAS_bool (false) ;
          if (var_length_68744.isValid ()) {
            uint32_t variant_68794 = var_length_68744.uintValue () ;
            bool loop_68794 = true ;
            while (loop_68794) {
              GALGAS_bool test_5 = var_found_68777.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2233)) ;
              if (kBoolTrue == test_5.boolEnum ()) {
                test_5 = GALGAS_bool (kIsStrictInf, var_index_68723.objectCompare (var_length_68744)) ;
              }
              loop_68794 = test_5.isValid () ;
              if (loop_68794) {
                loop_68794 = test_5.boolValue () ;
              }
              if (loop_68794 && (0 == variant_68794)) {
                loop_68794 = false ;
                inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2232)) ;
              }
              if (loop_68794) {
                variant_68794 -- ;
                enumGalgasBool test_6 = kBoolTrue ;
                if (kBoolTrue == test_6) {
                  test_6 = GALGAS_bool (kIsEqual, object->mProperty_value.getter_characterAtIndex (var_index_68723, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2234)).objectCompare (var_lookedUpChar_68658)).boolEnum () ;
                  if (kBoolTrue == test_6) {
                    var_found_68777 = GALGAS_bool (true) ;
                  }
                }
                if (kBoolFalse == test_6) {
                  var_index_68723.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2237)) ;
                }
              }
            }
          }
          GALGAS_bigint temp_7 ;
          const enumGalgasBool test_8 = var_found_68777.boolEnum () ;
          if (kBoolTrue == test_8) {
            temp_7 = var_index_68723.getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2243)) ;
          }else if (kBoolFalse == test_8) {
            temp_7 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2243)) ;
          }
          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2241)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2242)), temp_7  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2240)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_9 = kBoolTrue ;
        if (kBoolTrue == test_9) {
          test_9 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2245)).objectCompare (GALGAS_string ("indexOfCharInRange"))).boolEnum () ;
          if (kBoolTrue == test_9) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_charCharArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2246)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2246)) ;
            }
            GALGAS_gtlChar temp_10 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2247)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2247)).ptr ())) {
                temp_10 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2247)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2247)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2247)) ;
              }
            }
            GALGAS_char var_minChar_69247 = temp_10.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2247)) ;
            GALGAS_gtlChar temp_11 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2248)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2248)).ptr ())) {
                temp_11 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2248)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2248)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2248)) ;
              }
            }
            GALGAS_char var_maxChar_69314 = temp_11.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2248)) ;
            GALGAS_uint var_index_69379 = GALGAS_uint ((uint32_t) 0U) ;
            GALGAS_uint var_length_69400 = object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2250)) ;
            GALGAS_bool var_found_69433 = GALGAS_bool (false) ;
            if (var_length_69400.isValid ()) {
              uint32_t variant_69450 = var_length_69400.uintValue () ;
              bool loop_69450 = true ;
              while (loop_69450) {
                GALGAS_bool test_12 = var_found_69433.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2253)) ;
                if (kBoolTrue == test_12.boolEnum ()) {
                  test_12 = GALGAS_bool (kIsStrictInf, var_index_69379.objectCompare (var_length_69400)) ;
                }
                loop_69450 = test_12.isValid () ;
                if (loop_69450) {
                  loop_69450 = test_12.boolValue () ;
                }
                if (loop_69450 && (0 == variant_69450)) {
                  loop_69450 = false ;
                  inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2252)) ;
                }
                if (loop_69450) {
                  variant_69450 -- ;
                  GALGAS_char var_currentChar_69524 = object->mProperty_value.getter_characterAtIndex (var_index_69379, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2254)) ;
                  enumGalgasBool test_13 = kBoolTrue ;
                  if (kBoolTrue == test_13) {
                    GALGAS_bool test_14 = GALGAS_bool (kIsSupOrEqual, var_currentChar_69524.objectCompare (var_minChar_69247)) ;
                    if (kBoolTrue == test_14.boolEnum ()) {
                      test_14 = GALGAS_bool (kIsInfOrEqual, var_currentChar_69524.objectCompare (var_maxChar_69314)) ;
                    }
                    test_13 = test_14.boolEnum () ;
                    if (kBoolTrue == test_13) {
                      var_found_69433 = GALGAS_bool (true) ;
                    }
                  }
                  if (kBoolFalse == test_13) {
                    var_index_69379.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2258)) ;
                  }
                }
              }
            }
            GALGAS_bigint temp_15 ;
            const enumGalgasBool test_16 = var_found_69433.boolEnum () ;
            if (kBoolTrue == test_16) {
              temp_15 = var_index_69379.getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2264)) ;
            }else if (kBoolFalse == test_16) {
              temp_15 = GALGAS_bigint ("-1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2264)) ;
            }
            result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2262)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2263)), temp_15  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2261)) ;
          }
        }
        if (kBoolFalse == test_9) {
          enumGalgasBool test_17 = kBoolTrue ;
          if (kBoolTrue == test_17) {
            test_17 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2266)).objectCompare (GALGAS_string ("containsChar"))).boolEnum () ;
            if (kBoolTrue == test_17) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_charArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2267)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2267)) ;
              }
              GALGAS_gtlChar temp_18 ;
              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2268)).isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2268)).ptr ())) {
                  temp_18 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2268)).ptr () ;
                }else{
                  inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2268)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2268)) ;
                }
              }
              GALGAS_char var_lookedUpChar_69954 = temp_18.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2268)) ;
              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2270)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2271)), object->mProperty_value.getter_containsCharacter (var_lookedUpChar_69954 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2272))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2269)) ;
            }
          }
          if (kBoolFalse == test_17) {
            enumGalgasBool test_19 = kBoolTrue ;
            if (kBoolTrue == test_19) {
              test_19 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2274)).objectCompare (GALGAS_string ("containsCharInRange"))).boolEnum () ;
              if (kBoolTrue == test_19) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_charCharArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2275)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2275)) ;
                }
                GALGAS_gtlChar temp_20 ;
                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2276)).isValid ()) {
                  if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2276)).ptr ())) {
                    temp_20 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2276)).ptr () ;
                  }else{
                    inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2276)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2276)) ;
                  }
                }
                GALGAS_char var_minChar_70277 = temp_20.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2276)) ;
                GALGAS_gtlChar temp_21 ;
                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2277)).isValid ()) {
                  if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2277)).ptr ())) {
                    temp_21 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2277)).ptr () ;
                  }else{
                    inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2277)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2277)) ;
                  }
                }
                GALGAS_char var_maxChar_70344 = temp_21.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2277)) ;
                result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2279)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2280)), object->mProperty_value.getter_containsCharacterInRange (var_minChar_70277, var_maxChar_70344 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2281))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2278)) ;
              }
            }
            if (kBoolFalse == test_19) {
              enumGalgasBool test_22 = kBoolTrue ;
              if (kBoolTrue == test_22) {
                test_22 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2283)).objectCompare (GALGAS_string ("HTMLRepresentation"))).boolEnum () ;
                if (kBoolTrue == test_22) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2284)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2284)) ;
                  }
                  result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2286)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2286)), object->mProperty_value.getter_HTMLRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 2286))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2285)) ;
                }
              }
              if (kBoolFalse == test_22) {
                enumGalgasBool test_23 = kBoolTrue ;
                if (kBoolTrue == test_23) {
                  test_23 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2288)).objectCompare (GALGAS_string ("identifierRepresentation"))).boolEnum () ;
                  if (kBoolTrue == test_23) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2289)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2289)) ;
                    }
                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2291)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2291)), object->mProperty_value.getter_identifierRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 2291))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2290)) ;
                  }
                }
                if (kBoolFalse == test_23) {
                  enumGalgasBool test_24 = kBoolTrue ;
                  if (kBoolTrue == test_24) {
                    test_24 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2293)).objectCompare (GALGAS_string ("fileExists"))).boolEnum () ;
                    if (kBoolTrue == test_24) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2294)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2294)) ;
                      }
                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2296)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2296)), object->mProperty_value.getter_fileExists (SOURCE_FILE ("gtl_data_types.galgas", 2296))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2295)) ;
                    }
                  }
                  if (kBoolFalse == test_24) {
                    enumGalgasBool test_25 = kBoolTrue ;
                    if (kBoolTrue == test_25) {
                      test_25 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2298)).objectCompare (GALGAS_string ("lowercaseString"))).boolEnum () ;
                      if (kBoolTrue == test_25) {
                        {
                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2299)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2299)) ;
                        }
                        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2301)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2301)), object->mProperty_value.getter_lowercaseString (SOURCE_FILE ("gtl_data_types.galgas", 2301))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2300)) ;
                      }
                    }
                    if (kBoolFalse == test_25) {
                      enumGalgasBool test_26 = kBoolTrue ;
                      if (kBoolTrue == test_26) {
                        test_26 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2303)).objectCompare (GALGAS_string ("length"))).boolEnum () ;
                        if (kBoolTrue == test_26) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2304)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2304)) ;
                          }
                          result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2306)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2306)), object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2306)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2306))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2305)) ;
                        }
                      }
                      if (kBoolFalse == test_26) {
                        enumGalgasBool test_27 = kBoolTrue ;
                        if (kBoolTrue == test_27) {
                          GALGAS_bool test_28 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2308)).objectCompare (GALGAS_string ("capitalized"))) ;
                          if (kBoolTrue != test_28.boolEnum ()) {
                            test_28 = GALGAS_bool (kIsEqual, GALGAS_string ("stringByCapitalizingFirstCharacter").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2309)))) ;
                          }
                          test_27 = test_28.boolEnum () ;
                          if (kBoolTrue == test_27) {
                            {
                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2310)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2310)) ;
                            }
                            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2312)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2312)), object->mProperty_value.getter_stringByCapitalizingFirstCharacter (SOURCE_FILE ("gtl_data_types.galgas", 2312))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2311)) ;
                          }
                        }
                        if (kBoolFalse == test_27) {
                          enumGalgasBool test_29 = kBoolTrue ;
                          if (kBoolTrue == test_29) {
                            test_29 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2314)).objectCompare (GALGAS_string ("uppercaseString"))).boolEnum () ;
                            if (kBoolTrue == test_29) {
                              {
                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2315)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2315)) ;
                              }
                              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2317)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2317)), object->mProperty_value.getter_uppercaseString (SOURCE_FILE ("gtl_data_types.galgas", 2317))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2316)) ;
                            }
                          }
                          if (kBoolFalse == test_29) {
                            enumGalgasBool test_30 = kBoolTrue ;
                            if (kBoolTrue == test_30) {
                              test_30 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2319)).objectCompare (GALGAS_string ("unsigned"))).boolEnum () ;
                              if (kBoolTrue == test_30) {
                                {
                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2320)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2320)) ;
                                }
                                result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2322)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2322)), object->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2322)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2322))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2321)) ;
                              }
                            }
                            if (kBoolFalse == test_30) {
                              enumGalgasBool test_31 = kBoolTrue ;
                              if (kBoolTrue == test_31) {
                                test_31 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2324)).objectCompare (GALGAS_string ("subStringExists"))).boolEnum () ;
                                if (kBoolTrue == test_31) {
                                  {
                                  routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2325)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2325)) ;
                                  }
                                  GALGAS_gtlString temp_32 ;
                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2326)).isValid ()) {
                                    if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2326)).ptr ())) {
                                      temp_32 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2326)).ptr () ;
                                    }else{
                                      inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2326)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2326)) ;
                                    }
                                  }
                                  GALGAS_string var_subString_72493 = temp_32.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2326)) ;
                                  GALGAS_uint var_subStringLength_72570 = var_subString_72493.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2327)) ;
                                  GALGAS_uint var_start_72607 = GALGAS_uint ((uint32_t) 0U) ;
                                  GALGAS_uint var_stop_72626 = object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2329)).substract_operation (var_subStringLength_72570, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2329)) ;
                                  GALGAS_bool var_exists_72678 = GALGAS_bool (false) ;
                                  if (object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2331)).isValid ()) {
                                    uint32_t variant_72696 = object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2331)).uintValue () ;
                                    bool loop_72696 = true ;
                                    while (loop_72696) {
                                      GALGAS_bool test_33 = var_exists_72678.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2332)) ;
                                      if (kBoolTrue == test_33.boolEnum ()) {
                                        test_33 = GALGAS_bool (kIsInfOrEqual, var_start_72607.objectCompare (var_stop_72626)) ;
                                      }
                                      loop_72696 = test_33.isValid () ;
                                      if (loop_72696) {
                                        loop_72696 = test_33.boolValue () ;
                                      }
                                      if (loop_72696 && (0 == variant_72696)) {
                                        loop_72696 = false ;
                                        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2331)) ;
                                      }
                                      if (loop_72696) {
                                        variant_72696 -- ;
                                        enumGalgasBool test_34 = kBoolTrue ;
                                        if (kBoolTrue == test_34) {
                                          test_34 = GALGAS_bool (kIsEqual, object->mProperty_value.getter_subString (var_start_72607, var_subStringLength_72570 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2333)).objectCompare (var_subString_72493)).boolEnum () ;
                                          if (kBoolTrue == test_34) {
                                            var_exists_72678 = GALGAS_bool (true) ;
                                          }
                                        }
                                        var_start_72607.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2336)) ;
                                      }
                                    }
                                  }
                                  result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2339)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2339)), var_exists_72678  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2338)) ;
                                }
                              }
                              if (kBoolFalse == test_31) {
                                enumGalgasBool test_35 = kBoolTrue ;
                                if (kBoolTrue == test_35) {
                                  test_35 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2341)).objectCompare (GALGAS_string ("leftSubString"))).boolEnum () ;
                                  if (kBoolTrue == test_35) {
                                    {
                                    routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2342)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2342)) ;
                                    }
                                    GALGAS_gtlInt temp_36 ;
                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2343)).isValid ()) {
                                      if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2343)).ptr ())) {
                                        temp_36 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2343)).ptr () ;
                                      }else{
                                        inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2343)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2343)) ;
                                      }
                                    }
                                    GALGAS_uint var_index_73104 = temp_36.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2343)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2343)) ;
                                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2345)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2345)), object->mProperty_value.getter_leftSubString (var_index_73104 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2345))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2344)) ;
                                  }
                                }
                                if (kBoolFalse == test_35) {
                                  enumGalgasBool test_37 = kBoolTrue ;
                                  if (kBoolTrue == test_37) {
                                    test_37 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2347)).objectCompare (GALGAS_string ("rightSubString"))).boolEnum () ;
                                    if (kBoolTrue == test_37) {
                                      {
                                      routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2348)) ;
                                      }
                                      GALGAS_gtlInt temp_38 ;
                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2349)).isValid ()) {
                                        if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2349)).ptr ())) {
                                          temp_38 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2349)).ptr () ;
                                        }else{
                                          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2349)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2349)) ;
                                        }
                                      }
                                      GALGAS_uint var_index_73397 = temp_38.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2349)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2349)) ;
                                      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2351)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2351)), object->mProperty_value.getter_rightSubString (var_index_73397 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2351))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2350)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_37) {
                                    enumGalgasBool test_39 = kBoolTrue ;
                                    if (kBoolTrue == test_39) {
                                      test_39 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2353)).objectCompare (GALGAS_string ("subString"))).boolEnum () ;
                                      if (kBoolTrue == test_39) {
                                        {
                                        routine_argumentsCheck (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2354)) ;
                                        }
                                        GALGAS_gtlInt temp_40 ;
                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2355)).isValid ()) {
                                          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2355)).ptr ())) {
                                            temp_40 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2355)).ptr () ;
                                          }else{
                                            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2355)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2355)) ;
                                          }
                                        }
                                        GALGAS_uint var_start_73690 = temp_40.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2355)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2355)) ;
                                        GALGAS_gtlInt temp_41 ;
                                        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356)).isValid ()) {
                                          if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356)).ptr ())) {
                                            temp_41 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356)).ptr () ;
                                          }else{
                                            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356)) ;
                                          }
                                        }
                                        GALGAS_uint var_length_73762 = temp_41.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2356)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2356)) ;
                                        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2358)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2358)), object->mProperty_value.getter_subString (var_start_73690, var_length_73762 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2358))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2357)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_39) {
                                      enumGalgasBool test_42 = kBoolTrue ;
                                      if (kBoolTrue == test_42) {
                                        test_42 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2360)).objectCompare (GALGAS_string ("reversedString"))).boolEnum () ;
                                        if (kBoolTrue == test_42) {
                                          {
                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2361)) ;
                                          }
                                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2363)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2363)), object->mProperty_value.getter_reversedString (SOURCE_FILE ("gtl_data_types.galgas", 2363))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2362)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_42) {
                                        enumGalgasBool test_43 = kBoolTrue ;
                                        if (kBoolTrue == test_43) {
                                          test_43 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2365)).objectCompare (GALGAS_string ("componentsSeparatedByString"))).boolEnum () ;
                                          if (kBoolTrue == test_43) {
                                            {
                                            routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2366)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2366)) ;
                                            }
                                            GALGAS_gtlString temp_44 ;
                                            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2367)).isValid ()) {
                                              if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2367)).ptr ())) {
                                                temp_44 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2367)).ptr () ;
                                              }else{
                                                inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2367)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2367)) ;
                                              }
                                            }
                                            GALGAS_string var_separator_74296 = temp_44.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2367)) ;
                                            GALGAS_stringlist var_stringlist_74374 = object->mProperty_value.getter_componentsSeparatedByString (var_separator_74296 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2368)) ;
                                            GALGAS_list var_components_74444 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2369)) ;
                                            cEnumerator_stringlist enumerator_74485 (var_stringlist_74374, kENUMERATION_UP) ;
                                            while (enumerator_74485.hasCurrentObject ()) {
                                              var_components_74444.addAssign_operation (GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2372)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2372)), enumerator_74485.current_mValue (HERE)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2371))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2371)) ;
                                              enumerator_74485.gotoNextObject () ;
                                            }
                                            result_result = GALGAS_gtlList::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2376)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2376)), var_components_74444  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2375)) ;
                                          }
                                        }
                                        if (kBoolFalse == test_43) {
                                          enumGalgasBool test_45 = kBoolTrue ;
                                          if (kBoolTrue == test_45) {
                                            test_45 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2378)).objectCompare (GALGAS_string ("interpretEscape"))).boolEnum () ;
                                            if (kBoolTrue == test_45) {
                                              TC_Array <C_FixItDescription> fixItArray46 ;
                                              inCompiler->emitSemanticWarning (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2379)), GALGAS_string ("deprecated method"), fixItArray46  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2379)) ;
                                              const GALGAS_gtlString temp_47 = object ;
                                              result_result = temp_47 ;
                                            }
                                          }
                                          if (kBoolFalse == test_45) {
                                            enumGalgasBool test_48 = kBoolTrue ;
                                            if (kBoolTrue == test_48) {
                                              test_48 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2381)).objectCompare (GALGAS_string ("columnPrefixedBy"))).boolEnum () ;
                                              if (kBoolTrue == test_48) {
                                                {
                                                routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2382)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2382)) ;
                                                }
                                                GALGAS_gtlString temp_49 ;
                                                if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2383)).isValid ()) {
                                                  if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2383)).ptr ())) {
                                                    temp_49 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2383)).ptr () ;
                                                  }else{
                                                    inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2383)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2383)) ;
                                                  }
                                                }
                                                GALGAS_string var_prefix_74937 = temp_49.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2383)) ;
                                                result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2385)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2386)), var_prefix_74937.add_operation (object->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2387)).getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string ("\n").add_operation (var_prefix_74937, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2387)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2387))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2384)) ;
                                              }
                                            }
                                            if (kBoolFalse == test_48) {
                                              enumGalgasBool test_50 = kBoolTrue ;
                                              if (kBoolTrue == test_50) {
                                                test_50 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2389)).objectCompare (GALGAS_string ("wrap"))).boolEnum () ;
                                                if (kBoolTrue == test_50) {
                                                  {
                                                  routine_argumentsCheck (constinArgument_methodName, function_intIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2390)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2390)) ;
                                                  }
                                                  GALGAS_gtlInt temp_51 ;
                                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2391)).isValid ()) {
                                                    if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2391)).ptr ())) {
                                                      temp_51 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2391)).ptr () ;
                                                    }else{
                                                      inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2391)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2391)) ;
                                                    }
                                                  }
                                                  GALGAS_uint var_width_75274 = temp_51.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2391)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2391)) ;
                                                  GALGAS_gtlInt temp_52 ;
                                                  if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)).isValid ()) {
                                                    if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)).ptr ())) {
                                                      temp_52 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)).ptr () ;
                                                    }else{
                                                      inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)) ;
                                                    }
                                                  }
                                                  GALGAS_uint var_shift_75345 = temp_52.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2392)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2392)) ;
                                                  GALGAS_string var_stringShift_75424 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_shift_75345  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2393)) ;
                                                  GALGAS_stringlist var_paragraphs_75501 = object->mProperty_value.getter_componentsSeparatedByString (GALGAS_string ("\n") COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2394)) ;
                                                  GALGAS_stringlist var_resultParagraphs_75582 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 2395)) ;
                                                  cEnumerator_stringlist enumerator_75631 (var_paragraphs_75501, kENUMERATION_UP) ;
                                                  while (enumerator_75631.hasCurrentObject ()) {
                                                    GALGAS_stringlist var_words_75658 = enumerator_75631.current_mValue (HERE).getter_componentsSeparatedByString (GALGAS_string (" ") COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2397)) ;
                                                    GALGAS_uint var_lineWidth_75727 = GALGAS_uint ((uint32_t) 0U) ;
                                                    GALGAS_string var_line_75750 = GALGAS_string::makeEmptyString () ;
                                                    cEnumerator_stringlist enumerator_75781 (var_words_75658, kENUMERATION_UP) ;
                                                    while (enumerator_75781.hasCurrentObject ()) {
                                                      enumGalgasBool test_53 = kBoolTrue ;
                                                      if (kBoolTrue == test_53) {
                                                        test_53 = GALGAS_bool (kIsNotEqual, enumerator_75781.current_mValue (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                                                        if (kBoolTrue == test_53) {
                                                          enumGalgasBool test_54 = kBoolTrue ;
                                                          if (kBoolTrue == test_54) {
                                                            test_54 = GALGAS_bool (kIsStrictSup, var_lineWidth_75727.add_operation (enumerator_75781.current_mValue (HERE).getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2402)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2402)).objectCompare (var_width_75274)).boolEnum () ;
                                                            if (kBoolTrue == test_54) {
                                                              var_line_75750.plusAssign_operation(GALGAS_string ("\n").add_operation (var_stringShift_75424, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2403)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2403)) ;
                                                              var_lineWidth_75727 = var_shift_75345 ;
                                                            }
                                                          }
                                                          var_lineWidth_75727.plusAssign_operation(enumerator_75781.current_mValue (HERE).getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2406)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2406)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2406)) ;
                                                          var_line_75750.plusAssign_operation(enumerator_75781.current_mValue (HERE).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2407)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2407)) ;
                                                        }
                                                      }
                                                      enumerator_75781.gotoNextObject () ;
                                                    }
                                                    var_resultParagraphs_75582.addAssign_operation (var_line_75750  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2410)) ;
                                                    enumerator_75631.gotoNextObject () ;
                                                  }
                                                  result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2413)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2414)), GALGAS_string::constructor_componentsJoinedByString (var_resultParagraphs_75582, GALGAS_string ("\n")  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2415))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2412)) ;
                                                }
                                              }
                                              if (kBoolFalse == test_50) {
                                                enumGalgasBool test_55 = kBoolTrue ;
                                                if (kBoolTrue == test_55) {
                                                  test_55 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2417)).objectCompare (GALGAS_string ("replaceString"))).boolEnum () ;
                                                  if (kBoolTrue == test_55) {
                                                    {
                                                    routine_argumentsCheck (constinArgument_methodName, function_stringStringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2418)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2418)) ;
                                                    }
                                                    GALGAS_gtlString temp_56 ;
                                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2419)).isValid ()) {
                                                      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2419)).ptr ())) {
                                                        temp_56 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2419)).ptr () ;
                                                      }else{
                                                        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2419)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2419)) ;
                                                      }
                                                    }
                                                    GALGAS_string var_find_76378 = temp_56.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2419)) ;
                                                    GALGAS_gtlString temp_57 ;
                                                    if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2420)).isValid ()) {
                                                      if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2420)).ptr ())) {
                                                        temp_57 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2420)).ptr () ;
                                                      }else{
                                                        inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2420)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2420)) ;
                                                      }
                                                    }
                                                    GALGAS_string var_rep_76445 = temp_57.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2420)) ;
                                                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2422)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2423)), object->mProperty_value.getter_stringByReplacingStringByString (var_find_76378, var_rep_76445, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2424))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2421)) ;
                                                  }
                                                }
                                                if (kBoolFalse == test_55) {
                                                  enumGalgasBool test_58 = kBoolTrue ;
                                                  if (kBoolTrue == test_58) {
                                                    test_58 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2426)).objectCompare (GALGAS_string ("subStringExists"))).boolEnum () ;
                                                    if (kBoolTrue == test_58) {
                                                      {
                                                      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2427)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2427)) ;
                                                      }
                                                      GALGAS_gtlString temp_59 ;
                                                      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2428)).isValid ()) {
                                                        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2428)).ptr ())) {
                                                          temp_59 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2428)).ptr () ;
                                                        }else{
                                                          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2428)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2428)) ;
                                                        }
                                                      }
                                                      GALGAS_string var_subString_76780 = callExtensionGetter_string ((const cPtr_gtlString *) temp_59.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2428)) ;
                                                      GALGAS_uint var_subLength_76852 = var_subString_76780.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2429)) ;
                                                      GALGAS_uint var_start_76889 = GALGAS_uint ((uint32_t) 0U) ;
                                                      GALGAS_uint var_stop_76908 = object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2431)).substract_operation (var_subLength_76852, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2431)) ;
                                                      GALGAS_bool var_exists_76954 = GALGAS_bool (false) ;
                                                      if (object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2433)).isValid ()) {
                                                        uint32_t variant_76971 = object->mProperty_value.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 2433)).uintValue () ;
                                                        bool loop_76971 = true ;
                                                        while (loop_76971) {
                                                          loop_76971 = GALGAS_bool (kIsInfOrEqual, var_start_76889.objectCompare (var_stop_76908)).operator_and (var_exists_76954.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2434)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2434)).isValid () ;
                                                          if (loop_76971) {
                                                            loop_76971 = GALGAS_bool (kIsInfOrEqual, var_start_76889.objectCompare (var_stop_76908)).operator_and (var_exists_76954.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2434)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2434)).boolValue () ;
                                                          }
                                                          if (loop_76971 && (0 == variant_76971)) {
                                                            loop_76971 = false ;
                                                            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_data_types.galgas", 2433)) ;
                                                          }
                                                          if (loop_76971) {
                                                            variant_76971 -- ;
                                                            enumGalgasBool test_60 = kBoolTrue ;
                                                            if (kBoolTrue == test_60) {
                                                              test_60 = GALGAS_bool (kIsEqual, object->mProperty_value.getter_subString (var_start_76889, var_subLength_76852 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2435)).objectCompare (var_subString_76780)).boolEnum () ;
                                                              if (kBoolTrue == test_60) {
                                                                var_exists_76954 = GALGAS_bool (true) ;
                                                              }
                                                            }
                                                            var_start_76889.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2438)) ;
                                                          }
                                                        }
                                                      }
                                                      result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2441)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2442)), var_exists_76954  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2440)) ;
                                                    }
                                                  }
                                                  if (kBoolFalse == test_58) {
                                                    enumGalgasBool test_61 = kBoolTrue ;
                                                    if (kBoolTrue == test_61) {
                                                      test_61 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2445)).objectCompare (GALGAS_string ("envVarExists"))).boolEnum () ;
                                                      if (kBoolTrue == test_61) {
                                                        {
                                                        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2446)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2446)) ;
                                                        }
                                                        result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2448)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2449)), object->mProperty_value.getter_doesEnvironmentVariableExist (SOURCE_FILE ("gtl_data_types.galgas", 2450))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2447)) ;
                                                      }
                                                    }
                                                    if (kBoolFalse == test_61) {
                                                      enumGalgasBool test_62 = kBoolTrue ;
                                                      if (kBoolTrue == test_62) {
                                                        test_62 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2452)).objectCompare (GALGAS_string ("envVar"))).boolEnum () ;
                                                        if (kBoolTrue == test_62) {
                                                          {
                                                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2453)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2453)) ;
                                                          }
                                                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2455)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2456)), GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (object->mProperty_value  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2457))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2454)) ;
                                                        }
                                                      }
                                                      if (kBoolFalse == test_62) {
                                                        enumGalgasBool test_63 = kBoolTrue ;
                                                        if (kBoolTrue == test_63) {
                                                          test_63 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2459)))).boolEnum () ;
                                                          if (kBoolTrue == test_63) {
                                                            {
                                                            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2460)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2460)) ;
                                                            }
                                                            const GALGAS_gtlString temp_64 = object ;
                                                            result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2462)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2462)), temp_64.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 2462))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2461)) ;
                                                          }
                                                        }
                                                        if (kBoolFalse == test_63) {
                                                          enumGalgasBool test_65 = kBoolTrue ;
                                                          if (kBoolTrue == test_65) {
                                                            test_65 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2464)))).boolEnum () ;
                                                            if (kBoolTrue == test_65) {
                                                              {
                                                              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2465)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2465)) ;
                                                              }
                                                              result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2467)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2467)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2466)) ;
                                                            }
                                                          }
                                                          if (kBoolFalse == test_65) {
                                                            enumGalgasBool test_66 = kBoolTrue ;
                                                            if (kBoolTrue == test_66) {
                                                              test_66 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2469)))).boolEnum () ;
                                                              if (kBoolTrue == test_66) {
                                                                {
                                                                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2470)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2470)) ;
                                                                }
                                                                result_result = GALGAS_gtlString::constructor_new (object->mProperty_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2472)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2472)), object->mProperty_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2472))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2471)) ;
                                                              }
                                                            }
                                                            if (kBoolFalse == test_66) {
                                                              enumGalgasBool test_67 = kBoolTrue ;
                                                              if (kBoolTrue == test_67) {
                                                                test_67 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2474)).boolEnum () ;
                                                                if (kBoolTrue == test_67) {
                                                                  const GALGAS_gtlString temp_68 = object ;
                                                                  result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2475)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2476)), constinArgument_context, constinArgument_lib, temp_68, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2475)) ;
                                                                }
                                                              }
                                                              if (kBoolFalse == test_67) {
                                                                enumGalgasBool test_69 = kBoolTrue ;
                                                                if (kBoolTrue == test_69) {
                                                                  test_69 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2482)))).boolEnum () ;
                                                                  if (kBoolTrue == test_69) {
                                                                    {
                                                                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2483)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2483)) ;
                                                                    }
                                                                    result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2485)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2485)), object->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2485))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2484)) ;
                                                                  }
                                                                }
                                                                if (kBoolFalse == test_69) {
                                                                  TC_Array <C_FixItDescription> fixItArray70 ;
                                                                  inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2488)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2488)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2488)).add_operation (GALGAS_string ("' for string target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2488)), fixItArray70  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2488)) ;
                                                                  result_result.drop () ; // Release error dropped variable
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
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlString_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                      extensionGetter_gtlString_performGetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlString_performGetter (defineExtensionGetter_gtlString_performGetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                               Overriding extension setter '@gtlString performSetter'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionSetter_gtlString_performSetter (cPtr_gtlData * inObject,
                                                     const GALGAS_lstring constinArgument_methodName,
                                                     const GALGAS_gtlDataList constinArgument_arguments,
                                                     const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_library constinArgument_lib,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlString * object = (cPtr_gtlString *) inObject ;
  macroValidSharedObject (object, cPtr_gtlString) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2502)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2503)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2503)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2504)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2504)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2504)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2504)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2504)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_79297 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_79297.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2505)) ;
      }
      object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2506)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2507)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2508)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2508)) ;
        }
        object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2509)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("setCharAtIndex").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2510)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_charIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2511)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2511)) ;
          }
          GALGAS_gtlChar temp_4 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2512)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2512)).ptr ())) {
              temp_4 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2512)).ptr () ;
            }else{
              inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2512)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2512)) ;
            }
          }
          GALGAS_char var_charToSet_79653 = temp_4.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2512)) ;
          GALGAS_gtlInt temp_5 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2513)).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2513)).ptr ())) {
              temp_5 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2513)).ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2513)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2513)) ;
            }
          }
          GALGAS_uint var_index_79718 = temp_5.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2513)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2513)) ;
          {
          object->mProperty_value.setter_setCharacterAtIndex (var_charToSet_79653, var_index_79718, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2514)) ;
          }
          object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2515)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("insertCharAtIndex").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2516)))).boolEnum () ;
          if (kBoolTrue == test_6) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_charIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2517)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2517)) ;
            }
            GALGAS_gtlChar temp_7 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2518)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlChar *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2518)).ptr ())) {
                temp_7 = (cPtr_gtlChar *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2518)).ptr () ;
              }else{
                inCompiler->castError ("gtlChar", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2518)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2518)) ;
              }
            }
            GALGAS_char var_charToInsert_79981 = temp_7.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2518)) ;
            GALGAS_gtlInt temp_8 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2519)).isValid ()) {
              if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2519)).ptr ())) {
                temp_8 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2519)).ptr () ;
              }else{
                inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2519)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2519)) ;
              }
            }
            GALGAS_uint var_index_80046 = temp_8.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2519)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2519)) ;
            {
            object->mProperty_value.setter_insertCharacterAtIndex (var_charToInsert_79981, var_index_80046, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2520)) ;
            }
            object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2521)) ;
          }
        }
        if (kBoolFalse == test_6) {
          enumGalgasBool test_9 = kBoolTrue ;
          if (kBoolTrue == test_9) {
            test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("removeCharAtIndex").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2522)))).boolEnum () ;
            if (kBoolTrue == test_9) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2523)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2523)) ;
              }
              GALGAS_gtlInt temp_10 ;
              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2524)).isValid ()) {
                if (NULL != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2524)).ptr ())) {
                  temp_10 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2524)).ptr () ;
                }else{
                  inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2524)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2524)) ;
                }
              }
              GALGAS_uint var_index_80303 = temp_10.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2524)).getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2524)) ;
              {
              GALGAS_char joker_80396 ; // Joker input parameter
              object->mProperty_value.setter_removeCharacterAtIndex (joker_80396, var_index_80303, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2525)) ;
              }
              object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2526)) ;
            }
          }
          if (kBoolFalse == test_9) {
            enumGalgasBool test_11 = kBoolTrue ;
            if (kBoolTrue == test_11) {
              test_11 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2527)).boolEnum () ;
              if (kBoolTrue == test_11) {
                const GALGAS_gtlString temp_12 = object ;
                GALGAS_gtlData var_copy_80500 = temp_12 ;
                callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("string"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2529)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2530)), constinArgument_context, constinArgument_lib, var_copy_80500, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2529)) ;
                GALGAS_gtlString temp_13 ;
                if (var_copy_80500.isValid ()) {
                  if (NULL != dynamic_cast <const cPtr_gtlString *> (var_copy_80500.ptr ())) {
                    temp_13 = (cPtr_gtlString *) var_copy_80500.ptr () ;
                  }else{
                    inCompiler->castError ("gtlString", var_copy_80500.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2536)) ;
                  }
                }
                object->mProperty_value = temp_13.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2536)) ;
                object->mProperty_where = var_copy_80500.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2537)) ;
                object->mProperty_meta = var_copy_80500.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 2538)) ;
              }
            }
            if (kBoolFalse == test_11) {
              TC_Array <C_FixItDescription> fixItArray14 ;
              inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2540)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2540)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2540)).add_operation (GALGAS_string ("' for string target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2540)), fixItArray14  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2540)) ;
            }
          }
        }
      }
    }
  }
}
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionSetter_gtlString_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlString.mSlotID,
                                      extensionSetter_gtlString_performSetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gSetter_gtlString_performSetter (defineExtensionSetter_gtlString_performSetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool desc'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlBool_desc (const cPtr_gtlData * inObject,
                                                   const GALGAS_uint constinArgument_tab,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).add_operation (GALGAS_string ("boolean: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2553)).add_operation (object->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2554)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2554)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_desc) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_desc (defineExtensionGetter_gtlBool_desc, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool string'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlBool_string (const cPtr_gtlData * inObject,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  result_result = object->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2557)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                               extensionGetter_gtlBool_string) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_string (defineExtensionGetter_gtlBool_string, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlBool lstring'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_lstring extensionGetter_gtlBool_lstring (const cPtr_gtlData * inObject,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  result_result = GALGAS_lstring::constructor_new (object->mProperty_value.getter_cString (SOURCE_FILE ("gtl_data_types.galgas", 2560)), object->mProperty_where  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2560)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                extensionGetter_gtlBool_lstring) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_lstring (defineExtensionGetter_gtlBool_lstring, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool bool'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bool extensionGetter_gtlBool_bool (const cPtr_gtlData * inObject,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  result_result = object->mProperty_value ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_bool) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_bool (defineExtensionGetter_gtlBool_bool, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool int'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bigint extensionGetter_gtlBool_int (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  GALGAS_bigint temp_0 ;
  const enumGalgasBool test_1 = object->mProperty_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2568)) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2568)) ;
  }
  result_result = temp_0 ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                            extensionGetter_gtlBool_int) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_int (defineExtensionGetter_gtlBool_int, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool float'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_double extensionGetter_gtlBool_float (const cPtr_gtlData * inObject,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  GALGAS_double temp_0 ;
  const enumGalgasBool test_1 = object->mProperty_value.boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_double (1) ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_double (0) ;
  }
  result_result = temp_0 ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_float) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_float (defineExtensionGetter_gtlBool_float, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool plusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_plusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2576)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                               extensionGetter_gtlBool_plusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_plusOp (defineExtensionGetter_gtlBool_plusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Overriding extension getter '@gtlBool minusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_minusOp (const cPtr_gtlData * inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2580)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                extensionGetter_gtlBool_minusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_minusOp (defineExtensionGetter_gtlBool_minusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool notOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_notOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2584)), object->mProperty_value.operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2584))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2584)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_notOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_notOp (defineExtensionGetter_gtlBool_notOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool addOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_addOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2588)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_addOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_addOp (defineExtensionGetter_gtlBool_addOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool subOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_subOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2592)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_subOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_subOp (defineExtensionGetter_gtlBool_subOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool mulOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_mulOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2596)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_mulOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_mulOp (defineExtensionGetter_gtlBool_mulOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool divOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_divOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2600)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_divOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_divOp (defineExtensionGetter_gtlBool_divOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool modOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_modOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData /* constinArgument_right */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2604)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_modOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_modOp (defineExtensionGetter_gtlBool_modOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool andOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_andOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2612)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2611)), object->mProperty_value.operator_and (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2612)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2612))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2609)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2615)), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2615)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_andOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_andOp (defineExtensionGetter_gtlBool_andOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool orOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_orOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2624)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2623)), object->mProperty_value.operator_or (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2624)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2624))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2621)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2627)), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2627)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_orOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_orOp (defineExtensionGetter_gtlBool_orOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool xorOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_xorOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2636)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2635)), object->mProperty_value.operator_xor (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2636)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2636))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2633)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2639)), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2639)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_xorOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_xorOp (defineExtensionGetter_gtlBool_xorOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool slOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_slOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2644)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_slOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_slOp (defineExtensionGetter_gtlBool_slOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool srOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_srOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("bool forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2648)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_srOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_srOp (defineExtensionGetter_gtlBool_srOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlBool neqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_neqOp (const cPtr_gtlData * inObject,
                                                     const GALGAS_gtlData constinArgument_right,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2656)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2655)), GALGAS_bool (kIsNotEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2656))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2653)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2659)), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2659)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                              extensionGetter_gtlBool_neqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_neqOp (defineExtensionGetter_gtlBool_neqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool eqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_eqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2668)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2667)), GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2668))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2665)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2671)), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2671)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_eqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_eqOp (defineExtensionGetter_gtlBool_eqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool gtOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_gtOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2680)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2679)), GALGAS_bool (kIsStrictSup, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2680))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2677)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2683)), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2683)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_gtOp (void) {
  enterExtensionGetter_gtOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_gtOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_gtOp (defineExtensionGetter_gtlBool_gtOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool geOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_geOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2692)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2691)), GALGAS_bool (kIsSupOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2692))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2689)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2695)), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2695)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_geOp (void) {
  enterExtensionGetter_geOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_geOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_geOp (defineExtensionGetter_gtlBool_geOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool ltOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_ltOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2704)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2703)), GALGAS_bool (kIsStrictInf, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2704))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2701)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2707)), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2707)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_ltOp (void) {
  enterExtensionGetter_ltOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_ltOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_ltOp (defineExtensionGetter_gtlBool_ltOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlBool leOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_leOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlBool).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlBool *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2716)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2715)), GALGAS_bool (kIsInfOrEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2716))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2713)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2719)), GALGAS_string ("bool expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2719)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_leOp (void) {
  enterExtensionGetter_leOp (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                             extensionGetter_gtlBool_leOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_leOp (defineExtensionGetter_gtlBool_leOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension getter '@gtlBool embeddedType'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_type extensionGetter_gtlBool_embeddedType (const cPtr_gtlData * /* inObject */,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_bool) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_embeddedType (void) {
  enterExtensionGetter_embeddedType (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                     extensionGetter_gtlBool_embeddedType) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_embeddedType (defineExtensionGetter_gtlBool_embeddedType, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Overriding extension method '@gtlBool addMyValue'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_gtlBool_addMyValue (const cPtr_gtlData * inObject,
                                                GALGAS_objectlist & ioArgument_objectList,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  ioArgument_objectList.addAssign_operation (object->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 2730))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2730)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_gtlBool_addMyValue (void) {
  enterExtensionMethod_addMyValue (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                   extensionMethod_gtlBool_addMyValue) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_gtlBool_addMyValue (defineExtensionMethod_gtlBool_addMyValue, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension getter '@gtlBool performGetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlBool_performGetter (const cPtr_gtlData * inObject,
                                                             const GALGAS_lstring constinArgument_methodName,
                                                             const GALGAS_gtlDataList constinArgument_arguments,
                                                             const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_library constinArgument_lib,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlBool * object = (const cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2743)).objectCompare (GALGAS_string ("trueOrFalse"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2744)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2744)) ;
      }
      GALGAS_string temp_1 ;
      const enumGalgasBool test_2 = object->mProperty_value.boolEnum () ;
      if (kBoolTrue == test_2) {
        temp_1 = GALGAS_string ("true") ;
      }else if (kBoolFalse == test_2) {
        temp_1 = GALGAS_string ("false") ;
      }
      result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2746)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2747)), temp_1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2745)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2750)).objectCompare (GALGAS_string ("string"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2751)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2751)) ;
        }
        const GALGAS_gtlBool temp_4 = object ;
        result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2753)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2754)), callExtensionGetter_string ((const cPtr_gtlBool *) temp_4.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2755))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2752)) ;
      }
    }
    if (kBoolFalse == test_3) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2757)).objectCompare (GALGAS_string ("yesOrNo"))).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2758)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2758)) ;
          }
          GALGAS_string temp_6 ;
          const enumGalgasBool test_7 = object->mProperty_value.boolEnum () ;
          if (kBoolTrue == test_7) {
            temp_6 = GALGAS_string ("yes") ;
          }else if (kBoolFalse == test_7) {
            temp_6 = GALGAS_string ("no") ;
          }
          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2760)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2761)), temp_6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2759)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2764)).objectCompare (GALGAS_string ("TRUEOrFALSE"))).boolEnum () ;
          if (kBoolTrue == test_8) {
            {
            routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2765)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2765)) ;
            }
            GALGAS_string temp_9 ;
            const enumGalgasBool test_10 = object->mProperty_value.boolEnum () ;
            if (kBoolTrue == test_10) {
              temp_9 = GALGAS_string ("TRUE") ;
            }else if (kBoolFalse == test_10) {
              temp_9 = GALGAS_string ("FALSE") ;
            }
            result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2767)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2768)), temp_9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2766)) ;
          }
        }
        if (kBoolFalse == test_8) {
          enumGalgasBool test_11 = kBoolTrue ;
          if (kBoolTrue == test_11) {
            test_11 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2771)).objectCompare (GALGAS_string ("YESOrNO"))).boolEnum () ;
            if (kBoolTrue == test_11) {
              {
              routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2772)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2772)) ;
              }
              GALGAS_string temp_12 ;
              const enumGalgasBool test_13 = object->mProperty_value.boolEnum () ;
              if (kBoolTrue == test_13) {
                temp_12 = GALGAS_string ("YES") ;
              }else if (kBoolFalse == test_13) {
                temp_12 = GALGAS_string ("NO") ;
              }
              result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2774)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2775)), temp_12  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2773)) ;
            }
          }
          if (kBoolFalse == test_11) {
            enumGalgasBool test_14 = kBoolTrue ;
            if (kBoolTrue == test_14) {
              GALGAS_bool test_15 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2778)).objectCompare (GALGAS_string ("int"))) ;
              if (kBoolTrue != test_15.boolEnum ()) {
                test_15 = GALGAS_bool (kIsEqual, constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2778)).objectCompare (GALGAS_string ("unsigned"))) ;
              }
              test_14 = test_15.boolEnum () ;
              if (kBoolTrue == test_14) {
                {
                routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2779)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2779)) ;
                }
                GALGAS_bigint temp_16 ;
                const enumGalgasBool test_17 = object->mProperty_value.boolEnum () ;
                if (kBoolTrue == test_17) {
                  temp_16 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2783)) ;
                }else if (kBoolFalse == test_17) {
                  temp_16 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2783)) ;
                }
                result_result = GALGAS_gtlInt::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2781)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2782)), temp_16  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2780)) ;
              }
            }
            if (kBoolFalse == test_14) {
              enumGalgasBool test_18 = kBoolTrue ;
              if (kBoolTrue == test_18) {
                test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2785)))).boolEnum () ;
                if (kBoolTrue == test_18) {
                  {
                  routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2786)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2786)) ;
                  }
                  const GALGAS_gtlBool temp_19 = object ;
                  result_result = GALGAS_gtlType::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2788)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2788)), temp_19.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 2788))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2787)) ;
                }
              }
              if (kBoolFalse == test_18) {
                enumGalgasBool test_20 = kBoolTrue ;
                if (kBoolTrue == test_20) {
                  test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2790)))).boolEnum () ;
                  if (kBoolTrue == test_20) {
                    {
                    routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2791)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2791)) ;
                    }
                    result_result = GALGAS_gtlBool::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2793)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2793)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2792)) ;
                  }
                }
                if (kBoolFalse == test_20) {
                  enumGalgasBool test_21 = kBoolTrue ;
                  if (kBoolTrue == test_21) {
                    test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2795)))).boolEnum () ;
                    if (kBoolTrue == test_21) {
                      {
                      routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2796)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2796)) ;
                      }
                      result_result = GALGAS_gtlString::constructor_new (object->mProperty_meta.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2798)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2798)), object->mProperty_meta.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2798))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2797)) ;
                    }
                  }
                  if (kBoolFalse == test_21) {
                    enumGalgasBool test_22 = kBoolTrue ;
                    if (kBoolTrue == test_22) {
                      test_22 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2800)).boolEnum () ;
                      if (kBoolTrue == test_22) {
                        const GALGAS_gtlBool temp_23 = object ;
                        result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2801)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2802)), constinArgument_context, constinArgument_lib, temp_23, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2801)) ;
                      }
                    }
                    if (kBoolFalse == test_22) {
                      enumGalgasBool test_24 = kBoolTrue ;
                      if (kBoolTrue == test_24) {
                        test_24 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2808)))).boolEnum () ;
                        if (kBoolTrue == test_24) {
                          {
                          routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2809)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2809)) ;
                          }
                          result_result = GALGAS_gtlString::constructor_new (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2811)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2811)), object->mProperty_where.getter_locationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2811))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2810)) ;
                        }
                      }
                      if (kBoolFalse == test_24) {
                        TC_Array <C_FixItDescription> fixItArray25 ;
                        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2814)), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2814)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2814)).add_operation (GALGAS_string ("' for boolean target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2814)), fixItArray25  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2814)) ;
                        result_result.drop () ; // Release error dropped variable
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
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlBool_performGetter (void) {
  enterExtensionGetter_performGetter (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                      extensionGetter_gtlBool_performGetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlBool_performGetter (defineExtensionGetter_gtlBool_performGetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension setter '@gtlBool performSetter'                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionSetter_gtlBool_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlBool * object = (cPtr_gtlBool *) inObject ;
  macroValidSharedObject (object, cPtr_gtlBool) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2828)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2829)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2829)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2830)).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2830)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2830)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2830)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2830)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_88937 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_88937.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2831)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2831)) ;
      }
      object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2832)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2833)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2834)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2834)) ;
        }
        object->mProperty_where = constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2835)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2836)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlBool temp_4 = object ;
          GALGAS_gtlData var_copy_89233 = temp_4 ;
          callExtensionMethod_callSetter ((const cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("bool"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2838)).ptr (), constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2839)), constinArgument_context, constinArgument_lib, var_copy_89233, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2838)) ;
          GALGAS_gtlBool temp_5 ;
          if (var_copy_89233.isValid ()) {
            if (NULL != dynamic_cast <const cPtr_gtlBool *> (var_copy_89233.ptr ())) {
              temp_5 = (cPtr_gtlBool *) var_copy_89233.ptr () ;
            }else{
              inCompiler->castError ("gtlBool", var_copy_89233.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2845)) ;
            }
          }
          object->mProperty_value = temp_5.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2845)) ;
          object->mProperty_where = var_copy_89233.getter_where (SOURCE_FILE ("gtl_data_types.galgas", 2846)) ;
          object->mProperty_meta = var_copy_89233.getter_meta (SOURCE_FILE ("gtl_data_types.galgas", 2847)) ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 2849)), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2849)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2849)).add_operation (GALGAS_string ("' for boolean target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2849)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2849)) ;
      }
    }
  }
}
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionSetter_gtlBool_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlBool.mSlotID,
                                      extensionSetter_gtlBool_performSetter) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gSetter_gtlBool_performSetter (defineExtensionSetter_gtlBool_performSetter, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet desc'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlSet_desc (const cPtr_gtlData * inObject,
                                                  const GALGAS_uint constinArgument_tab,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  result_result = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2873)).add_operation (GALGAS_string ("set: @!\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2873)) ;
  cEnumerator_lstringset enumerator_90458 (object->mProperty_value, kENUMERATION_UP) ;
  const bool bool_0 = true ;
  if (enumerator_90458.hasCurrentObject () && bool_0) {
    result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab.add_operation (GALGAS_uint ((uint32_t) 4U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2877))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2877)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2877)) ;
    while (enumerator_90458.hasCurrentObject () && bool_0) {
      result_result.plusAssign_operation(enumerator_90458.current_lkey (HERE).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2879)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2879)) ;
      enumerator_90458.gotoNextObject () ;
      if (enumerator_90458.hasCurrentObject () && bool_0) {
        result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2881)) ;
      }
    }
    result_result.plusAssign_operation(GALGAS_string ("\n"), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2883)) ;
  }
  result_result.plusAssign_operation(GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2885)).add_operation (GALGAS_string ("!\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2885)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2885)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_desc (void) {
  enterExtensionGetter_desc (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                             extensionGetter_gtlSet_desc) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_desc (defineExtensionGetter_gtlSet_desc, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlSet string'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_string extensionGetter_gtlSet_string (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a set to a string"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2889)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_string (void) {
  enterExtensionGetter_string (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                               extensionGetter_gtlSet_string) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_string (defineExtensionGetter_gtlSet_string, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlSet lstring'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_lstring extensionGetter_gtlSet_lstring (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a set to a lstring"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2893)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_lstring (void) {
  enterExtensionGetter_lstring (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                                extensionGetter_gtlSet_lstring) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_lstring (defineExtensionGetter_gtlSet_lstring, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet bool'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bool extensionGetter_gtlSet_bool (const cPtr_gtlData * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a set to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2897)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_bool (void) {
  enterExtensionGetter_bool (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                             extensionGetter_gtlSet_bool) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_bool (defineExtensionGetter_gtlSet_bool, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                      Overriding extension getter '@gtlSet int'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_bigint extensionGetter_gtlSet_int (const cPtr_gtlData * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a set to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2901)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_int (void) {
  enterExtensionGetter_int (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                            extensionGetter_gtlSet_int) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_int (defineExtensionGetter_gtlSet_int, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet float'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_double extensionGetter_gtlSet_float (const cPtr_gtlData * inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("cannot cast a set to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2905)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_float (void) {
  enterExtensionGetter_float (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_float) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_float (defineExtensionGetter_gtlSet_float, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlSet plusOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_plusOp (const cPtr_gtlData * inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2909)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_plusOp (void) {
  enterExtensionGetter_plusOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                               extensionGetter_gtlSet_plusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_plusOp (defineExtensionGetter_gtlSet_plusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                    Overriding extension getter '@gtlSet minusOp'                                    *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_minusOp (const cPtr_gtlData * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2913)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_minusOp (void) {
  enterExtensionGetter_minusOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                                extensionGetter_gtlSet_minusOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_minusOp (defineExtensionGetter_gtlSet_minusOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet notOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_notOp (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2917)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_notOp (void) {
  enterExtensionGetter_notOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_notOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_notOp (defineExtensionGetter_gtlSet_notOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet addOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_addOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  GALGAS_lstringset var_set_91623 = object->mProperty_value ;
  GALGAS_lstring var_element_91650 = callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2922)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = var_set_91623.getter_hasKey (var_element_91650.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2923)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2923)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_set_91623.setter_del (var_element_91650, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2924)) ;
      }
    }
  }
  {
  var_set_91623.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2926)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2926)) ;
  }
  result_result = GALGAS_gtlSet::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2927)), var_set_91623  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2927)) ;
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_addOp (void) {
  enterExtensionGetter_addOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_addOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_addOp (defineExtensionGetter_gtlSet_addOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet subOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_subOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstringset var_resultSet_91947 = object->mProperty_value ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2933)) ;
        }
      }
      cEnumerator_lstringset enumerator_91998 (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2933)), kENUMERATION_UP) ;
      while (enumerator_91998.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_resultSet_91947.getter_hasKey (enumerator_91998.current_lkey (HERE).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2934)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2934)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_91947.setter_del (enumerator_91998.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2935)) ;
            }
          }
        }
        enumerator_91998.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2939)), var_resultSet_91947  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2938)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2942)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2942)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_subOp (void) {
  enterExtensionGetter_subOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_subOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_subOp (defineExtensionGetter_gtlSet_subOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet mulOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_mulOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2947)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_mulOp (void) {
  enterExtensionGetter_mulOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_mulOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_mulOp (defineExtensionGetter_gtlSet_mulOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet divOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_divOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2951)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_divOp (void) {
  enterExtensionGetter_divOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_divOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_divOp (defineExtensionGetter_gtlSet_divOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet modOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_modOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2955)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_modOp (void) {
  enterExtensionGetter_modOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_modOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_modOp (defineExtensionGetter_gtlSet_modOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet andOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_andOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstringset var_resultSet_92714 = GALGAS_lstringset::constructor_emptyMap (SOURCE_FILE ("gtl_data_types.galgas", 2960)) ;
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2961)) ;
        }
      }
      cEnumerator_lstringset enumerator_92773 (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2961)), kENUMERATION_UP) ;
      while (enumerator_92773.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = object->mProperty_value.getter_hasKey (enumerator_92773.current_lkey (HERE).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2962)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2962)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_92714.setter_put (enumerator_92773.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2963)) ;
            }
          }
        }
        enumerator_92773.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2967)), var_resultSet_92714  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2966)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2970)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2970)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_andOp (void) {
  enterExtensionGetter_andOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_andOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_andOp (defineExtensionGetter_gtlSet_andOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet orOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_orOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2976)) ;
        }
      }
      GALGAS_lstringset var_resultSet_93126 = temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 2976)) ;
      cEnumerator_lstringset enumerator_93180 (object->mProperty_value, kENUMERATION_UP) ;
      while (enumerator_93180.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_resultSet_93126.getter_hasKey (enumerator_93180.current_lkey (HERE).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 2978)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2978)).operator_not (SOURCE_FILE ("gtl_data_types.galgas", 2978)).boolEnum () ;
          if (kBoolTrue == test_2) {
            {
            var_resultSet_93126.setter_put (enumerator_93180.current_lkey (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2979)) ;
            }
          }
        }
        enumerator_93180.gotoNextObject () ;
      }
      result_result = GALGAS_gtlSet::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2983)), var_resultSet_93126  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2982)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2986)), GALGAS_string ("set expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2986)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_orOp (void) {
  enterExtensionGetter_orOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                             extensionGetter_gtlSet_orOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_orOp (defineExtensionGetter_gtlSet_orOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet xorOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_xorOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData /* constinArgument_right */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2991)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_xorOp (void) {
  enterExtensionGetter_xorOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_xorOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_xorOp (defineExtensionGetter_gtlSet_xorOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet slOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_slOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2995)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_slOp (void) {
  enterExtensionGetter_slOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                             extensionGetter_gtlSet_slOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_slOp (defineExtensionGetter_gtlSet_slOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet srOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_srOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData /* constinArgument_right */,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (object->mProperty_where, GALGAS_string ("set forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2999)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_srOp (void) {
  enterExtensionGetter_srOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                             extensionGetter_gtlSet_srOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_srOp (defineExtensionGetter_gtlSet_srOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet neqOp'                                     *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_neqOp (const cPtr_gtlData * inObject,
                                                    const GALGAS_gtlData constinArgument_right,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3005)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3005)), GALGAS_bool (kIsNotEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 3005))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3004)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3008)), GALGAS_string ("set expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3008)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_neqOp (void) {
  enterExtensionGetter_neqOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                              extensionGetter_gtlSet_neqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_neqOp (defineExtensionGetter_gtlSet_neqOp, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                     Overriding extension getter '@gtlSet eqOp'                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static GALGAS_gtlData extensionGetter_gtlSet_eqOp (const cPtr_gtlData * inObject,
                                                   const GALGAS_gtlData constinArgument_right,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  const cPtr_gtlSet * object = (const cPtr_gtlSet *) inObject ;
  macroValidSharedObject (object, cPtr_gtlSet) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlSet).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlSet temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_gtlSet *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlSet *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlSet", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3015)) ;
        }
      }
      result_result = GALGAS_gtlBool::constructor_new (object->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3015)), GALGAS_bool (kIsEqual, object->mProperty_value.objectCompare (temp_1.getter_value (SOURCE_FILE ("gtl_data_types.galgas", 3015))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3014)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3018)), GALGAS_string ("set expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 3018)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionGetter_gtlSet_eqOp (void) {
  enterExtensionGetter_eqOp (kTypeDescriptor_GALGAS_gtlSet.mSlotID,
                             extensionGetter_gtlSet_eqOp) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gGetter_gtlSet_eqOp (defineExtensionGetter_gtlSet_eqOp, NULL) ;

