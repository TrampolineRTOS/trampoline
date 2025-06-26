//--------------------------------------------------------------------------------------------------
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
//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------

#include "String-class.h"
#include "TC_UniqueArray.h"
#include "LocationInSource.h"
#include "SourceTextInString.h"
#include "C_IssueWithFixIt.h"
#include "SharedObject.h"

//--------------------------------------------------------------------------------------------------

#include <typeinfo>
#include <initializer_list>

//--------------------------------------------------------------------------------------------------

class Compiler ;

//--------------------------------------------------------------------------------------------------
//
//  Exception raised when maximum error count is reached                                         
//
//--------------------------------------------------------------------------------------------------

class max_error_count_reached_exception : public::std::exception {
  public: virtual const char * what (void) const throw () ;
} ;

//--------------------------------------------------------------------------------------------------
//
//  Exception raised when maximum warning count is reached                                       
//
//--------------------------------------------------------------------------------------------------

class max_warning_count_reached_exception : public::std::exception {
  public: virtual const char * what (void) const throw () ;
} ;

//--------------------------------------------------------------------------------------------------
//
//     Internal exception thrown when a lexical error has been detected                          
//
//--------------------------------------------------------------------------------------------------

class C_lexicalErrorException {
} ;

//--------------------------------------------------------------------------------------------------
//
//   Class used for defining a reserved words table entry                                        
//
//--------------------------------------------------------------------------------------------------

class C_unicode_lexique_table_entry final {
  public: const std::initializer_list <utf32> mEntryString ;
  public: const int16_t mTokenCode ;

//--- Constructor
  public: C_unicode_lexique_table_entry (const std::initializer_list <utf32> & inEntryString,
                                         const int16_t inTokenCode) ;
//--- Handle copy
  public: C_unicode_lexique_table_entry (const C_unicode_lexique_table_entry & inOperand) ;
  private: C_unicode_lexique_table_entry & operator = (const C_unicode_lexique_table_entry &) = delete ;
} ;

//--------------------------------------------------------------------------------------------------
//
//                 Token class                                                                   
//
//--------------------------------------------------------------------------------------------------

class cToken {
  public: cToken * mNextToken ;
  public: LocationInSource mStartLocation ;
  public: LocationInSource mEndLocation ;
  public: String mTemplateStringBeforeToken ; // Template string before the token
  public: String mSeparatorStringBeforeToken ;
  public: int32_t mTokenCode ;

  public: cToken (void) ;
  public: virtual ~cToken (void) ;

//--- No copy
  private: cToken (const cToken &) ;
  private: cToken & operator = (const cToken &) ;
} ;

//--------------------------------------------------------------------------------------------------
//
//                 Class for handling parsing context                                            
//          (used by parse ... rewind ... end parse ; instruction)                               
//
//--------------------------------------------------------------------------------------------------

class ParsingContext final {
  private: int32_t mParsingArrayIndex ;
  private: LocationInSource mLocation ;
  private: cToken * mCurrentTokenPtr ;
  private: utf32 mCurrentChar ;
  private: utf32 mPreviousChar ;
  private: String mTemplateString ;

  friend class Lexique ;
  
  public: ParsingContext (void) ;

//--- Copy
  public: ParsingContext (const ParsingContext & inSource) ;
  public: ParsingContext & operator = (const ParsingContext & inSource) ;
} ;

//--------------------------------------------------------------------------------------------------
//
//         Abstract class for GALGAS input/output                                                
//
//--------------------------------------------------------------------------------------------------

//--- Errors count
int32_t maxErrorCount (void) ;

int32_t totalErrorCount (void) ;

//--- Warnings count
int32_t maxWarningCount (void) ;

int32_t totalWarningCount (void) ;
 
void signalParsingError (Compiler * inCompiler,
                         const SourceTextInString & inSourceText,
                         const LocationInSource & inPreviousTokenEndLocation,
                         const C_IssueWithFixIt & inIssue,
                         const String & inFoundTokenMessage,
                         const TC_UniqueArray <String> & inAcceptedTokenNames
                         COMMA_LOCATION_ARGS) ;

void signalExtractError (Compiler * inCompiler,
                         const SourceTextInString & inSourceText,
                         const C_IssueWithFixIt & inIssue,
                         const TC_UniqueArray <String> & inExpectedClassesErrorStringsArray,
                         const String & inActualFoundClassErrorString
                         COMMA_LOCATION_ARGS) ;

void signalCastError (Compiler * inCompiler,
                      const SourceTextInString & inSourceText,
                      const C_IssueWithFixIt & inIssue,
                      const std::type_info * inBaseClass,
                      const bool inUseKindOfClass,
                      const String & inActualFoundClassErrorString
                      COMMA_LOCATION_ARGS) ;

void signalLexicalWarning (Compiler * inCompiler,
                           const SourceTextInString & inSourceText,
                           const C_IssueWithFixIt & inIssue,
                           const String & inLexicalWarningMessage
                           COMMA_LOCATION_ARGS) ;

void signalLexicalError (Compiler * inCompiler,
                         const SourceTextInString & inSourceText,
                         const C_IssueWithFixIt & inIssue,
                         const String & inLexicalErrorMessage
                         COMMA_LOCATION_ARGS) ;

void signalSemanticWarning (Compiler * inCompiler,
                            const SourceTextInString & inSourceText,
                            const C_IssueWithFixIt & inIssue,
                            const String & inWarningMessage
                            COMMA_LOCATION_ARGS) ;

void signalSemanticError (Compiler * inCompiler,
                          const SourceTextInString & inSourceText,
                          const C_IssueWithFixIt & inIssue,
                          const String & inErrorMessage
                          COMMA_LOCATION_ARGS) ;

void signalRunTimeError (Compiler * inCompiler,
                         const String & inErrorMessage
                         COMMA_LOCATION_ARGS) ;

void signalRunTimeWarning (Compiler * inCompiler,
                           const String & inWarningMessage
                           COMMA_LOCATION_ARGS) ;

void ggs_printError (Compiler * inCompiler,
                     const SourceTextInString & inSourceText,
                     const C_IssueWithFixIt & inIssue,
                     const String & inMessage
                     COMMA_LOCATION_ARGS) ;

void ggs_printWarning (Compiler * inCompiler,
                       const SourceTextInString & inSourceText,
                       const C_IssueWithFixIt & inIssue,
                       const String & inMessage
                       COMMA_LOCATION_ARGS) ;

void ggs_printFileOperationSuccess (const String & inMessage) ;

void ggs_printFileCreationSuccess (const String & inMessage) ;

void ggs_printMessage (const String & inMessage
                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void fatalError (const String & inErrorMessage,
                 const char * inSourceFile,
                 const int inSourceLine) ;

//--------------------------------------------------------------------------------------------------
