//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'C_galgas_io'                                                                                                      *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1996, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef GALGAS_IO_CLASS_DEFINED
#define GALGAS_IO_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include <typeinfo>

//---------------------------------------------------------------------------------------------------------------------*

#include "strings/C_String.h"
#include "collections/TC_UniqueArray.h"
#include "galgas2/C_LocationInSource.h"
#include "galgas2/C_SourceTextInString.h"
#include "utilities/C_SharedObject.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Exception raised when maximum error count is reached                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class max_error_count_reached_exception : public ::std:: exception {
  public : virtual const char * what (void) const throw () ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Exception raised when maximum warning count is reached                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class max_warning_count_reached_exception : public ::std:: exception {
  public : virtual const char * what (void) const throw () ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     Internal exception thrown when a lexical error has been detected                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class C_lexicalErrorException {
} ;

//---------------------------------------------------------------------------------------------------------------------*

class C_UserCancelException : public ::std::exception {
  public : C_UserCancelException (void) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//   Class used for defining a reserved words table entry                                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class C_unicode_lexique_table_entry {
  public : const utf32 * mEntryString ;
  public : const int16_t mEntryStringLength ;
  public : const int16_t mTokenCode ;

//--- Constructor
  public : C_unicode_lexique_table_entry (const utf32 * inEntryString,
                                          const int16_t inEntryStringLength,
                                          const int16_t inTokenCode) ;
//--- No copy
  public : C_unicode_lexique_table_entry (const C_unicode_lexique_table_entry & inOperand) ;
  private : C_unicode_lexique_table_entry & operator = (const C_unicode_lexique_table_entry &) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                 Token class                                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cToken {
  public : cToken * mNextToken ;
  public : C_LocationInSource mStartLocation ;
  public : C_LocationInSource mEndLocation ;
  public : C_String mTemplateStringBeforeToken ; // Template string before the token
  public : C_String mSeparatorStringBeforeToken ;
  public : int16_t mTokenCode ;

  public : cToken (void) ;
  public : virtual ~cToken (void) ;

//--- No copy
  private : cToken (const cToken &) ;
  private : cToken & operator = (const cToken &) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                 Class for handling parsing context                                                                  *
//          (used by parse ... rewind ... end parse ; instruction)                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class C_parsingContext {
  private : int32_t mParsingArrayIndex ;
  private : C_LocationInSource mLocation ;
  private : cToken * mCurrentTokenPtr ;
  private : utf32 mCurrentChar ;
  private : utf32 mPreviousChar ;
  private : C_String mTemplateString ;

  friend class C_Lexique ;
  
  public : C_parsingContext (void) ;

//--- No copy
  public : C_parsingContext (const C_parsingContext & inSource) ;
  public : C_parsingContext & operator = (const C_parsingContext & inSource) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//         Abstract class for GALGAS input/output                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_String errorOrWarningLocationString (const C_LocationInSource & inErrorLocation,
                                       const C_SourceTextInString * inSourceTextPtr) ;

void constructErrorOrWarningLocationMessage (C_String & ioMessage, 
                                             const C_LocationInSource & inErrorLocation,
                                             const C_SourceTextInString * inSourceTextPtr) ;

//--- Errors count
int32_t maxErrorCount (void) ;

int32_t totalErrorCount (void) ;

//--- Warnings count
int32_t maxWarningCount (void) ;

int32_t totalWarningCount (void) ;
 
void signalParsingError (const C_SourceTextInString * inSourceTextPtr,
                         const C_LocationInSource & inErrorLocation,
                         const C_String & inFoundTokenMessage,
                         const TC_UniqueArray <C_String> & inAcceptedTokenNames
                         COMMA_LOCATION_ARGS) ;

void signalExtractError (const C_SourceTextInString * inSourceTextPtr,
                         const C_LocationInSource & inErrorLocation,
                         const TC_UniqueArray <C_String> & inExpectedClassesErrorStringsArray,
                         const C_String & inActualFoundClassErrorString
                         COMMA_LOCATION_ARGS) ;

void signalCastError (const C_SourceTextInString * inSourceTextPtr,
                      const C_LocationInSource & inErrorLocation,
                      const std::type_info * inBaseClass,
                      const bool inUseKindOfClass,
                      const C_String & inActualFoundClassErrorString
                      COMMA_LOCATION_ARGS) ;

void signalLexicalWarning (const C_SourceTextInString * inSourceTextPtr,
                           const C_LocationInSource & inWarningLocation,
                           const C_String & inLexicalWarningMessage
                           COMMA_LOCATION_ARGS) ;

void signalLexicalError (const C_SourceTextInString * inSourceTextPtr,
                         const C_LocationInSource & inErrorLocation,
                         const C_String & inLexicalErrorMessage
                         COMMA_LOCATION_ARGS) ;

void signalSemanticWarning (const C_SourceTextInString * inSourceTextPtr,
                            const C_LocationInSource & inWarningLocation,
                            const C_String & inWarningMessage
                            COMMA_LOCATION_ARGS) ;

void signalSemanticError (const C_SourceTextInString * inSourceTextPtr,
                          const C_LocationInSource & inErrorLocation,
                          const C_String & inErrorMessage
                          COMMA_LOCATION_ARGS) ;

void signalRunTimeError (const C_String & inErrorMessage
                         COMMA_LOCATION_ARGS) ;

void signalRunTimeWarning (const C_String & inWarningMessage
                           COMMA_LOCATION_ARGS) ;

//--- Fatal error
void fatalError (const C_String & inErrorMessage,
                 const char * inSourceFile,
                 const int inSourceLine) ;

void ggs_printError (const C_SourceTextInString * inSourceTextPtr,
                     const C_LocationInSource & inErrorLocation,
                     const C_String & inMessage
                     COMMA_LOCATION_ARGS) ;

void ggs_printWarning (const C_SourceTextInString * inSourceTextPtr,
                       const C_LocationInSource & inWarningLocation,
                       const C_String & inMessage
                       COMMA_LOCATION_ARGS) ;

void ggs_printFileOperationSuccess (const C_String & inMessage) ;

void ggs_printFileCreationSuccess (const C_String & inMessage) ;

void ggs_printMessage (const C_String & inMessage
                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

/*uint32_t checkedLineCount (void) ;
void incrementCheckedFileCount (const uint32_t inIncrement) ;

//---------------------------------------------------------------------------------------------------------------------*

uint32_t generatedLineCount (void) ;
void incrementGeneratedLileCount (const uint32_t inIncrement) ;

//---------------------------------------------------------------------------------------------------------------------*

uint32_t preservedLineCount (void) ;
void incrementPreservedLileCount (const uint32_t inIncrement) ;

//---------------------------------------------------------------------------------------------------------------------*

uint32_t generatedFileCount (void) ;
void incrementGeneratedFileCount (void) ;
*/
//---------------------------------------------------------------------------------------------------------------------*

#endif
