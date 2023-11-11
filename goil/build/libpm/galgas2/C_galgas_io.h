//----------------------------------------------------------------------------------------------------------------------
//
//  'C_galgas_io'                                                                                
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 1996, ..., 2016 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include <typeinfo>

//----------------------------------------------------------------------------------------------------------------------

#include "strings/C_String.h"
#include "collections/TC_UniqueArray.h"
#include "galgas2/C_LocationInSource.h"
#include "galgas2/C_SourceTextInString.h"
#include "galgas2/C_IssueWithFixIt.h"
#include "utilities/C_SharedObject.h"

//----------------------------------------------------------------------------------------------------------------------

class C_Compiler ;

//----------------------------------------------------------------------------------------------------------------------
//
//  Exception raised when maximum error count is reached                                         
//
//----------------------------------------------------------------------------------------------------------------------

class max_error_count_reached_exception : public::std::exception {
  public: virtual const char * what (void) const throw () ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//  Exception raised when maximum warning count is reached                                       
//
//----------------------------------------------------------------------------------------------------------------------

class max_warning_count_reached_exception : public::std::exception {
  public: virtual const char * what (void) const throw () ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//     Internal exception thrown when a lexical error has been detected                          
//
//----------------------------------------------------------------------------------------------------------------------

class C_lexicalErrorException {
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//   Class used for defining a reserved words table entry                                        
//
//----------------------------------------------------------------------------------------------------------------------

class C_unicode_lexique_table_entry {
  public: const utf32 * mEntryString ;
  public: const int16_t mEntryStringLength ;
  public: const int16_t mTokenCode ;

//--- Constructor
  public: C_unicode_lexique_table_entry (const utf32 * inEntryString,
                                          const int16_t inEntryStringLength,
                                          const int16_t inTokenCode) ;
//--- No copy
  public: C_unicode_lexique_table_entry (const C_unicode_lexique_table_entry & inOperand) ;
  private: C_unicode_lexique_table_entry & operator = (const C_unicode_lexique_table_entry &) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//                 Token class                                                                   
//
//----------------------------------------------------------------------------------------------------------------------

class cToken {
  public: cToken * mNextToken ;
  public: C_LocationInSource mStartLocation ;
  public: C_LocationInSource mEndLocation ;
  public: C_String mTemplateStringBeforeToken ; // Template string before the token
  public: C_String mSeparatorStringBeforeToken ;
  public: int32_t mTokenCode ;

  public: cToken (void) ;
  public: virtual ~cToken (void) ;

//--- No copy
  private: cToken (const cToken &) ;
  private: cToken & operator = (const cToken &) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//                 Class for handling parsing context                                            
//          (used by parse ... rewind ... end parse ; instruction)                               
//
//----------------------------------------------------------------------------------------------------------------------

class C_parsingContext {
  private: int32_t mParsingArrayIndex ;
  private: C_LocationInSource mLocation ;
  private: cToken * mCurrentTokenPtr ;
  private: utf32 mCurrentChar ;
  private: utf32 mPreviousChar ;
  private: C_String mTemplateString ;

  friend class C_Lexique ;
  
  public: C_parsingContext (void) ;

//--- No copy
  public: C_parsingContext (const C_parsingContext & inSource) ;
  public: C_parsingContext & operator = (const C_parsingContext & inSource) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//         Abstract class for GALGAS input/output                                                
//
//----------------------------------------------------------------------------------------------------------------------

//--- Errors count
int32_t maxErrorCount (void) ;

int32_t totalErrorCount (void) ;

//--- Warnings count
int32_t maxWarningCount (void) ;

int32_t totalWarningCount (void) ;
 
void signalParsingError (C_Compiler * inCompiler,
                         const C_SourceTextInString & inSourceText,
                         const C_LocationInSource & inPreviousTokenEndLocation,
                         const C_IssueWithFixIt & inIssue,
                         const C_String & inFoundTokenMessage,
                         const TC_UniqueArray <C_String> & inAcceptedTokenNames
                         COMMA_LOCATION_ARGS) ;

void signalExtractError (C_Compiler * inCompiler,
                         const C_SourceTextInString & inSourceText,
                         const C_IssueWithFixIt & inIssue,
                         const TC_UniqueArray <C_String> & inExpectedClassesErrorStringsArray,
                         const C_String & inActualFoundClassErrorString
                         COMMA_LOCATION_ARGS) ;

void signalCastError (C_Compiler * inCompiler,
                      const C_SourceTextInString & inSourceText,
                      const C_IssueWithFixIt & inIssue,
                      const std::type_info * inBaseClass,
                      const bool inUseKindOfClass,
                      const C_String & inActualFoundClassErrorString
                      COMMA_LOCATION_ARGS) ;

void signalLexicalWarning (C_Compiler * inCompiler,
                           const C_SourceTextInString & inSourceText,
                           const C_IssueWithFixIt & inIssue,
                           const C_String & inLexicalWarningMessage
                           COMMA_LOCATION_ARGS) ;

void signalLexicalError (C_Compiler * inCompiler,
                         const C_SourceTextInString & inSourceText,
                         const C_IssueWithFixIt & inIssue,
                         const C_String & inLexicalErrorMessage
                         COMMA_LOCATION_ARGS) ;

void signalSemanticWarning (C_Compiler * inCompiler,
                            const C_SourceTextInString & inSourceText,
                            const C_IssueWithFixIt & inIssue,
                            const C_String & inWarningMessage
                            COMMA_LOCATION_ARGS) ;

void signalSemanticError (C_Compiler * inCompiler,
                          const C_SourceTextInString & inSourceText,
                          const C_IssueWithFixIt & inIssue,
                          const C_String & inErrorMessage
                          COMMA_LOCATION_ARGS) ;

void signalRunTimeError (C_Compiler * inCompiler,
                         const C_String & inErrorMessage
                         COMMA_LOCATION_ARGS) ;

void signalRunTimeWarning (C_Compiler * inCompiler,
                           const C_String & inWarningMessage
                           COMMA_LOCATION_ARGS) ;

void ggs_printError (C_Compiler * inCompiler,
                     const C_SourceTextInString & inSourceText,
                     const C_IssueWithFixIt & inIssue,
                     const C_String & inMessage
                     COMMA_LOCATION_ARGS) ;

void ggs_printWarning (C_Compiler * inCompiler,
                       const C_SourceTextInString & inSourceText,
                       const C_IssueWithFixIt & inIssue,
                       const C_String & inMessage
                       COMMA_LOCATION_ARGS) ;

void ggs_printFileOperationSuccess (const C_String & inMessage) ;

void ggs_printFileCreationSuccess (const C_String & inMessage) ;

void ggs_printMessage (const C_String & inMessage
                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void fatalError (const C_String & inErrorMessage,
                 const char * inSourceFile,
                 const int inSourceLine) ;

//----------------------------------------------------------------------------------------------------------------------
