//---------------------------------------------------------------------------*
//                                                                           *
//  'C_Compiler' : the compiler base class ;                                 *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2009, ..., 2011 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef GALGAS_COMPILER_CLASS_DEFINED
#define GALGAS_COMPILER_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "collections/TC_UniqueArray.h"
#include "strings/C_String.h"
#include "utilities/C_SharedObject.h"
#include "galgas2/C_LocationInSource.h"
#include "galgas2/C_SourceTextInString.h"

//---------------------------------------------------------------------------*

#include <exception>

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define ACCEPT_TERMINAL(t) t
  #define FORMAL_ARG_ACCEPT_TERMINAL const PMSInt16 inExpectedTerminal
#else
  #define ACCEPT_TERMINAL(t)
  #define FORMAL_ARG_ACCEPT_TERMINAL
#endif

//---------------------------------------------------------------------------*

class GALGAS_location ;
class GALGAS_string ;
class GALGAS_lstring ;
class C_galgas_type_descriptor ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 Compiler class                                            *
//                                                                           *
//---------------------------------------------------------------------------*

class C_Compiler : public C_SharedObject {
//--- Constructor and destructor
  public : C_Compiler (C_Compiler * inCallerCompiler,
                       const C_String & inDependencyFileExtension,
                       const C_String & inDependencyFilePath
                       COMMA_LOCATION_ARGS) ;
  public : virtual ~ C_Compiler (void) ;

//--- No copy
  private : C_Compiler (const C_Compiler &) ;
  private : C_Compiler & operator = (const C_Compiler &) ;

//--- Caller compiler (is NULL for top compiler)
  protected : C_Compiler * mCallerCompiler ;

//--- Sent string 
  private : C_String mSentString ;
  private : bool mSentStringIsValid ;
  public : GALGAS_string sentString (void) const ;

//--- Template String
  protected : C_String mTemplateString ;
  protected : C_LocationInSource mTemplateStringLocation ;
  public : GALGAS_string retrieveAndResetTemplateString (void) ;
  public : void resetTemplateString (void) ;

//--- Handling current character and its location
  private : C_SourceTextInString * mSourceTextPtr ;
  protected : C_LocationInSource mCurrentLocation ;

  public : inline C_SourceTextInString * sourceText (void) const {
    return mSourceTextPtr ;
  }

//--- 'loop' intruction variant run-time error
  public : void loopRunTimeVariantError (LOCATION_ARGS) ;

//--- Handle 'here' in GALGAS 2
  public : GALGAS_location here (void) const ;

//--- Source file name
  public : C_String sourceFilePath (void) const ;

//--- Syntax error message for 'end of source':
  protected : static const utf32 kEndOfSourceLexicalErrorMessage [] ;

//--- Location in source
  public : inline C_LocationInSource currentLocationInSource (void) const {
    return mCurrentLocation ;
  }

  public : inline PMSInt32 location (void) const {
    return mCurrentLocation.index () ;
  }

  public : inline PMSInt32 lineNumber (void) const {
    return mCurrentLocation.lineNumber () ;
  }

  public : inline PMSInt32 columnNumber (void) const {
    return mCurrentLocation.columnNumber () ;
  }

//--- Init scanner from source file (for Cocoa GALGAS)
  public : void resetAndLoadSourceFromText (C_SourceTextInString * & ioSourceTextPtr) ; 

//--- Print a message
  public : void printMessage (const GALGAS_string & inMessage COMMA_LOCATION_ARGS) ;
  public : void printMessage (const C_String & inMessage COMMA_LOCATION_ARGS) ;

//--- Print semantic error
  public : void semanticErrorAtLocation (const GALGAS_location & inErrorLocation,
                                         const C_String & inErrorMessage
                                         COMMA_LOCATION_ARGS) ;

//--- Print semantic warning
  public : void semanticWarningAtLocation (const GALGAS_location & inErrorLocation,
                                           const C_String & inWarningMessage
                                           COMMA_LOCATION_ARGS) ;

//--- Signal a run-time error
  public : void onTheFlyRunTimeError (const C_String & inRunTimeErrorMessage COMMA_LOCATION_ARGS) ;

//--- Signal a semantic error
  public : void onTheFlySemanticError (const C_String & inMessage COMMA_LOCATION_ARGS) ;

//--- Signal a semantic warning
  public : void onTheFlySemanticWarning (const C_String & inMessage COMMA_LOCATION_ARGS) ;

//--- Emit a warning
  public : void emitSemanticWarning (const GALGAS_location & inWarningLocation,
                                     const GALGAS_string & inWarningMessage
                                     COMMA_LOCATION_ARGS) ;

//--- Emit an error
  public : void emitSemanticError (const GALGAS_location & inErrorLocation,
                                   const GALGAS_string & inErrorMessage
                                   COMMA_LOCATION_ARGS) ;

//--- Emit an error message with an error message that contains %K espace sequence
  public : void semanticErrorWith_K_message (const GALGAS_lstring & inKey,
                                             TC_UniqueArray <C_String> & ioNearestKeyArray,
                                             const char * in_K_ErrorMessage
                                             COMMA_LOCATION_ARGS) ;

//--- Emit an error message with an error message that contains %K and %L espace sequences
  public : void semanticErrorWith_K_L_message (const GALGAS_lstring & inKey,
                                               const char * in_K_L_ErrorMessage,
                                               const GALGAS_location & inExistingKeyLocation
                                               COMMA_LOCATION_ARGS) ;

//--- Emit an error for on a cast expression failure
  public : void castInExpressionErrorAtLocation (const GALGAS_location & inErrorLocation
                                                 COMMA_LOCATION_ARGS) ;

//--- Emit an error for on a cast expression failure
  public : void extractObjectError (const GALGAS_location & inErrorLocation,
                                    const char * inTargetTypeName,
                                    const C_galgas_type_descriptor * inSourceStaticType
                                    COMMA_LOCATION_ARGS) ;

//--- enterPragma
  private : TC_UniqueArray <C_String> mCheckedVariableList ;
  public : PMSInt32 checkedVariableListEntryCount (void) const ;
  public : C_String checkedVariableAtIndex (const PMSInt32 inIndex COMMA_LOCATION_ARGS) const ;
  public : void enterPragma (const GALGAS_lstring & inPragmaName,
                             const GALGAS_lstring & inPragmaArgument
                             COMMA_LOCATION_ARGS) ;

//--- File read logging
  public : static bool performLogFileRead (void) ;
  
  public : void logFileRead (const C_String & inFilePath) ;
  
//--- File generation
  public : static bool performGeneration (void) ;

//--- Generate file in directory
  public : void generateFile (const C_String & inLineCommentPrefix,
                              const TC_UniqueArray <C_String> & inDirectoriesToExclude,
                              const C_String & inFileName,
                              const C_String & inDefaultUserZone1,
                              const C_String & inGeneratedZone2,
                              const C_String & inDefaultUserZone2,
                              const C_String & inGeneratedZone3) ;

  public : void generateFileInGALGAS_OUTPUT (const C_String & inLineCommentPrefix,
                                             const C_String & inFileName,
                                             const C_String & inDefaultUserZone1,
                                             const C_String & inGeneratedZone2,
                                             const C_String & inDefaultUserZone2,
                                             const C_String & inGeneratedZone3) ;

  public : void
  generateFileFromPathes (const C_String & inStartPath,
                          const TC_UniqueArray <C_String> & inDirectoriesToExclude,
                          const C_String & inLineCommentPrefix,
                          const C_String & inFileName,
                          const C_String & inDefaultUserZone1,
                          const C_String & inGeneratedZone2,
                          const C_String & inDefaultUserZone2,
                          const C_String & inGeneratedZone3) ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//   T R A C E                                                               *
//                                                                           *
//---------------------------------------------------------------------------*

void enableTraceWithPath (const C_String & inSourceFilePath) ;

//---------------------------------------------------------------------------*

bool traceIsEnabled (void) ;

//---------------------------------------------------------------------------*

void appendTrace (const char * inType,
                  const bool inIsBuilt,
                  const C_String & inStringValue) ;

//---------------------------------------------------------------------------*

void closeTrace (void) ;

//---------------------------------------------------------------------------*

#endif
