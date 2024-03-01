#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-7.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'invokeGTL'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_invokeGTL (class GALGAS_gtlString inArgument0,
                                        class GALGAS_gtlContext inArgument1,
                                        class GALGAS_gtlData inArgument2,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyLib'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_library function_emptyLib (class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyVarContainer'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData function_emptyVarContainer (class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'lstringToGtlString'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlString function_lstringToGtlString (class GALGAS_lstring inArgument0,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringToGtlString'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlString function_stringToGtlString (class GALGAS_string inArgument0,
                                                   class C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyContext'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlContext function_emptyContext (class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'defaultDebugSettings'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_debuggerContext function_defaultDebugSettings (class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'wantGtlStruct'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData function_wantGtlStruct (class GALGAS_gtlData inArgument0,
                                             class C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'wantGtlMap'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData function_wantGtlMap (class GALGAS_gtlData inArgument0,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'wantGtlList'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData function_wantGtlList (class GALGAS_gtlData inArgument0,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'checkArgumentError'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_checkArgumentError (const class GALGAS_lstring constinArgument0,
                                 const class GALGAS_type constinArgument1,
                                 const class GALGAS_gtlData constinArgument2,
                                 const class GALGAS_uint constinArgument3,
                                 class C_Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'validateReturnValue'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData function_validateReturnValue (const class GALGAS_lstring & constinArgument0,
                                                   const class GALGAS_object & constinArgument1,
                                                   class C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'noArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_noArgument (class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'intArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_intArgument (class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'charArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_charArgument (class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'charCharArguments'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_charCharArguments (class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'charIntArguments'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_charIntArguments (class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'floatArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_floatArgument (class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_stringArgument (class C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'stringStringArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_stringStringArgument (class C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'boolIntArguments'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_boolIntArguments (class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'intIntArguments'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_intIntArguments (class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'intAnyArguments'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_intAnyArguments (class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'anyArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_anyArgument (class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'structArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_structArgument (class C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'expressionArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_expressionArgument (class C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'setArgument'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList function_setArgument (class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'argumentsCheck'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_argumentsCheck (const class GALGAS_lstring constinArgument0,
                             class GALGAS_gtlTypedArgumentList inArgument1,
                             class GALGAS_gtlDataList inArgument2,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

