//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'C_galgas_io'                                                                                                      *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 1996, ..., 2016 Pierre Molinaro.                                                                     *
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

#include "galgas2/C_galgas_io.h"
#include "streams/C_ConsoleOut.h"
#include "streams/C_ErrorOut.h"
#include "command_line_interface/C_builtin_CLI_Options.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/C_galgas_class_inspector.h"
#include "galgas2/F_verbose_output.h"

//---------------------------------------------------------------------------------------------------------------------*

#include <string.h>
#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

//---------------------------------------------------------------------------------------------------------------------*

C_unicode_lexique_table_entry::C_unicode_lexique_table_entry (const utf32 * inEntryString,
                                                              const int16_t inEntryStringLength,
                                                              const int16_t inTokenCode) :
mEntryString (inEntryString),
mEntryStringLength (inEntryStringLength),
mTokenCode (inTokenCode) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_unicode_lexique_table_entry::C_unicode_lexique_table_entry (const C_unicode_lexique_table_entry & inOperand) :
mEntryString (inOperand.mEntryString),
mEntryStringLength (inOperand.mEntryStringLength),
mTokenCode (inOperand.mTokenCode) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_UserCancelException:: C_UserCancelException (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Exceptions
#endif

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Exception raised when maximum error count is reached                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const char * max_error_count_reached_exception::what (void) const throw () {
  return "The maximum error count is reached" ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Exception raised when maximum warning count is reached                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static const char * kMaxWarning = "The maximum warning count is reached" ;

//---------------------------------------------------------------------------------------------------------------------*

const char * max_warning_count_reached_exception::what (void) const throw () {
  return kMaxWarning ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Class C_galgas_io
#endif

//---------------------------------------------------------------------------------------------------------------------*

int32_t maxErrorCount (void) {
  int32_t result = (int32_t) gOption_galgas_5F_builtin_5F_options_max_5F_errors.mValue ;
  return (result == 0) ? INT32_MAX : result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static int32_t mErrorTotalCount ;

int32_t totalErrorCount (void) {
  return mErrorTotalCount ;
}

//---------------------------------------------------------------------------------------------------------------------*

int32_t maxWarningCount (void) {
  int32_t result = (int32_t) gOption_galgas_5F_builtin_5F_options_max_5F_warnings.mValue ;
  return (result == 0) ? INT32_MAX : result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static int32_t mTotalWarningCount ;

int32_t totalWarningCount (void) {
  return mTotalWarningCount ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    Construct error or warning location message                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static C_String errorOrWarningLocationString (const C_IssueWithFixIt & inIssue,
                                              const C_SourceTextInString * inSourceTextPtr) {
  C_String result ;
  if (inSourceTextPtr != NULL) {
    macroValidSharedObject (inSourceTextPtr, C_SourceTextInString) ;
    const C_String textLine = inSourceTextPtr->getLineForLocation (inIssue.mStartLocation) ;
    result << inSourceTextPtr->sourceFilePath ()
           << ":" << cStringWithSigned (inIssue.mStartLocation.lineNumber ())
           << ":" << cStringWithSigned (inIssue.mStartLocation.columnNumber ())
           << ":" << cStringWithSigned (inIssue.mEndLocation.columnNumber ()) << ":\n" ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static C_String constructErrorOrWarningLocationMessage (const C_String & inMessage,
                                                        const C_IssueWithFixIt & inIssue,
                                                        const C_SourceTextInString * inSourceTextPtr) {
  C_String result ;
  if (inSourceTextPtr == NULL) {
    result << inMessage ;
  }else{
    macroValidSharedObject (inSourceTextPtr, C_SourceTextInString) ;
  //--- Construct message
    result << errorOrWarningLocationString (inIssue, inSourceTextPtr)
           << inMessage ;
    if (verboseOutput ()) {
      const C_String textLine = inSourceTextPtr->getLineForLocation (inIssue.mStartLocation) ;
      result << textLine << "\n" ;
    //--- Underline issue
      for (int32_t i=1 ; i<inIssue.mStartLocation.columnNumber () ; i++) {
        result << "-" ;
      }
      for (int32_t i=inIssue.mStartLocation.columnNumber () ; i <= inIssue.mEndLocation.columnNumber () ; i++) {
        result << "^" ;
      }
      result << "\n" ;
    //--- Add fix it suggestions
      const C_String ZeroWidthSpace = cStringWithUnicodeCharacter (TO_UNICODE (0x200B)) ;
      for (int32_t i=0 ; i<inIssue.mFixItArray.count () ; i++) {
        const C_FixItDescription d = inIssue.mFixItArray (i COMMA_HERE) ;
        switch (d.kind()) {
        case kFixItRemove :
          result << "Fix-it, remove\n" ;
          break ;
        case kFixItReplace :
          result << "Fix-it, replace with " << ZeroWidthSpace << d.actionString() << "\n" ;
          break ;
        case kFixItInsertBefore :
          result << "Fix-it, insert before: " << ZeroWidthSpace << d.actionString() << "\n" ;
          break ;
        case kFixItInsertAfter :
          result << "Fix-it, insert after: " << ZeroWidthSpace << d.actionString() << "\n" ;
          break ;
        }
      }
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    This method is called by lexique for signaling lexical warning                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void signalLexicalWarning (const C_SourceTextInString * inSourceTextPtr,
                           const C_IssueWithFixIt & inIssue,
                           const C_String & inLexicalWarningMessage
                           COMMA_LOCATION_ARGS) {
//--- Increment warning count
  mTotalWarningCount ++ ;
//--- Construct location warning message
  C_String warningMessage ;
//--- Add warning
  warningMessage << (verboseOutput () ? "lexical " : "")
                 << "warning #" << cStringWithSigned (mTotalWarningCount) << ": " << inLexicalWarningMessage << "\n" ;
//--- Print
  ggs_printWarning (inSourceTextPtr, inIssue, warningMessage COMMA_THERE) ;
//--- Warning max count reached ?
  if ((maxWarningCount () > 0) && (totalWarningCount () >= maxWarningCount ())) {
    throw max_warning_count_reached_exception () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    This method is called by lexique for signaling lexical error                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void signalLexicalError (const C_SourceTextInString * inSourceTextPtr,
                         const C_IssueWithFixIt & inIssue,
                         const C_String & inLexicalErrorMessage
                         COMMA_LOCATION_ARGS) {
//--- Increment error count
  mErrorTotalCount ++ ;
//--- Construct parsing error message
  C_String errorMessage ;
  errorMessage << (verboseOutput () ? "lexical " : "")
               << "error #" << cStringWithSigned (mErrorTotalCount) << ": " << inLexicalErrorMessage << "\n" ;
//--- Print
  ggs_printError (inSourceTextPtr, inIssue, errorMessage COMMA_THERE) ;
//--- Error max count reached ?
  if ((maxErrorCount () > 0) && (totalErrorCount () >= maxErrorCount ())) {
    throw max_error_count_reached_exception () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    This method is called by lexique for signaling parsing error                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void signalParsingError (const C_SourceTextInString * inSourceTextPtr,
                         const C_IssueWithFixIt & inIssue,
                         const C_String & inFoundTokenMessage,
                         const TC_UniqueArray <C_String> & inAcceptedTokenNames
                         COMMA_LOCATION_ARGS) {
//--- Increment error count
  mErrorTotalCount ++ ;
//--- Construct location error message
  C_String errorMessage ;
//--- Construct parsing error message
  errorMessage << (verboseOutput () ? "syntax " : "")
               << "error #" << cStringWithSigned (mErrorTotalCount) << ": found " << inFoundTokenMessage <<", expected:\n" ;
  for (int32_t i=0 ; i<inAcceptedTokenNames.count () ; i++) {
    errorMessage << "-  " << inAcceptedTokenNames (i COMMA_HERE) << "\n" ;  
  }
//--- Print
  ggs_printError (inSourceTextPtr, inIssue, errorMessage COMMA_THERE) ;
//--- Error max count reached ?
  if ((maxErrorCount () > 0) && (totalErrorCount () >= maxErrorCount ())) {
    throw max_error_count_reached_exception () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//            Method called for signaling an extract error                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void signalExtractError (const C_SourceTextInString * inSourceTextPtr,
                         const C_IssueWithFixIt & inIssue,
                         const TC_UniqueArray <C_String> & inExpectedClassesErrorStringsArray,
                         const C_String & inActualFoundClassErrorString
                         COMMA_LOCATION_ARGS) {
//--- Increment error count
  mErrorTotalCount ++ ;
//--- Construct location error message
  C_String errorMessage ;
//--- Print extract error
  errorMessage << (verboseOutput () ? "semantic " : "")
               << "error: I have found:\n" ;
  if (! verboseOutput ()) {
    errorMessage << errorOrWarningLocationString (inIssue, inSourceTextPtr)
                 << "error: " ;
  }
  errorMessage << "  - " << inActualFoundClassErrorString <<";\n" ;
  if (! verboseOutput ()) {
    errorMessage << errorOrWarningLocationString (inIssue, inSourceTextPtr)
                 << "error: " ;
  }
  errorMessage << "I was expected:\n" ;
  if (! verboseOutput ()) {
    errorMessage << errorOrWarningLocationString (inIssue, inSourceTextPtr)
                 << "error: " ;
  }
  errorMessage << "  - " << inExpectedClassesErrorStringsArray (0 COMMA_HERE) ;
  for (int32_t i=1 ; i<inExpectedClassesErrorStringsArray.count () ; i++) {
    errorMessage << ";\n" ;
    if (! verboseOutput ()) {
      errorMessage << errorOrWarningLocationString (inIssue, inSourceTextPtr)
                   << "error: " ;
    }
    errorMessage << "  - " << inExpectedClassesErrorStringsArray (i COMMA_HERE) ;  
  }
  errorMessage << ".\n" ;
//--- Print
  ggs_printError (inSourceTextPtr, inIssue, errorMessage COMMA_THERE) ;
//--- Error max count reached ?
  if ((maxErrorCount () > 0) && (totalErrorCount () >= maxErrorCount ())) {
    throw max_error_count_reached_exception () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//            Method called for signaling a cast error                                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void signalCastError (const C_SourceTextInString * inSourceTextPtr,
                      const C_IssueWithFixIt & inIssue,
                      const std::type_info * inBaseClass,
                      const bool inUseKindOfClass,
                      const C_String & inActualFoundClassErrorString
                      COMMA_LOCATION_ARGS) {
//--- Increment error count
  mErrorTotalCount ++ ;
//--- Construct expected class message array
  TC_UniqueArray <C_String> expectedClassMessageArray ;
  const C_galgas_class_inspector * p = C_galgas_class_inspector::root () ;
  bool found = false ;
  while ((p != NULL) && ! found) {
    if (p->mClassID == inBaseClass) {
      found = true ;
      expectedClassMessageArray.addObject (p->mClassMessage) ;
    }
    p = p->mNextClass ;
  }
  if (inUseKindOfClass) {
    TC_UniqueArray <const std::type_info *> classIDarray ;
    classIDarray.addObject (inBaseClass) ;
    bool loop = true ;
    while (loop) {
      loop = false ;
      p = C_galgas_class_inspector::root () ;
      while (p != NULL) {
        if (classIDarray.containsObjectEqualTo (p->mSuperClassID)
          && ! classIDarray.containsObjectEqualTo (p->mClassID)) {
          loop = true ;
          classIDarray.addObject (p->mClassID) ;
          expectedClassMessageArray.addObject (p->mClassMessage) ;
        }
        p = p->mNextClass ;
      }
    }
  }
//--- Print extract error
  C_String errorMessage ;
  expectedClassMessageArray.sortArrayUsingCompareMethod () ;
  errorMessage << (verboseOutput () ? "semantic " : "")
               << "error: I have found:\n" ;
  if (! verboseOutput ()) {
    errorMessage << errorOrWarningLocationString (inIssue, inSourceTextPtr)
                 << "error: " ;
  }
  errorMessage << "  - " << inActualFoundClassErrorString <<";\n" ;
  if (! verboseOutput ()) {
    errorMessage << errorOrWarningLocationString (inIssue, inSourceTextPtr)
                 << "error: " ;
  }
  errorMessage << "I was expected:\n" ;
  if (! verboseOutput ()) {
    errorMessage << errorOrWarningLocationString (inIssue, inSourceTextPtr)
                 << "error: " ;
  }
  if (expectedClassMessageArray.count () > 0) {
    errorMessage << "  - " << expectedClassMessageArray (0 COMMA_HERE) ;
    for (int32_t i=1 ; i<expectedClassMessageArray.count () ; i++) {
      errorMessage << ";\n" ;
      if (! verboseOutput ()) {
        errorMessage << errorOrWarningLocationString (inIssue, inSourceTextPtr)
                     << "error: " ;
      }
      errorMessage << "  - " << expectedClassMessageArray (i COMMA_HERE) ;
    }
  }
  errorMessage << ".\n" ;
//--- Print
  ggs_printError (inSourceTextPtr, inIssue, errorMessage COMMA_THERE) ;
//--- Error max count reached ?
  if ((maxErrorCount () > 0) && (totalErrorCount () >= maxErrorCount ())) {
    throw max_error_count_reached_exception () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void signalSemanticWarning (const C_SourceTextInString * inSourceTextPtr,
                            const C_IssueWithFixIt & inIssue,
                            const C_String & inWarningMessage
                            COMMA_LOCATION_ARGS) {
//--- Increment warning count
  mTotalWarningCount ++ ;
//--- Construct location error message
  C_String warningMessage ;
//--- Add warning
  warningMessage << (verboseOutput () ? "semantic " : "")
                 << "warning #" << cStringWithSigned (mTotalWarningCount) << ": " << inWarningMessage << "\n" ;
//--- Print
  ggs_printWarning (inSourceTextPtr, inIssue, warningMessage COMMA_THERE) ;
//--- Warning max count reached ?
  if ((maxWarningCount () > 0) && (totalWarningCount () >= maxWarningCount ())) {
    throw max_warning_count_reached_exception () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void fatalError (const C_String & inErrorMessage,
                 const char * inSourceFile,
                 const int inSourceLine) {
//--- Increment error count
  mErrorTotalCount ++ ;
//--- Error message
  C_String errorMessage ;
  errorMessage << inErrorMessage << " in file '" << inSourceFile << "', line " << cStringWithSigned (inSourceLine) << "\n" ;
  ggs_printError (NULL, C_IssueWithFixIt (), errorMessage COMMA_HERE) ;
  throw max_error_count_reached_exception () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void signalSemanticError (const C_SourceTextInString * inSourceTextPtr,
                          const C_IssueWithFixIt & inIssue,
                          const C_String & inErrorMessage
                          COMMA_LOCATION_ARGS) {
  const C_LocationInSource inEndErrorLocation = inIssue.mStartLocation ; // §
//--- Increment error count
  mErrorTotalCount ++ ;
//--- Construct location error message
  C_String errorMessage ;
//--- Print error
  errorMessage << "semantic error #" << cStringWithSigned (mErrorTotalCount) << ": " << inErrorMessage << "\n" ;
//--- Print
  ggs_printError (inSourceTextPtr, inIssue, errorMessage COMMA_THERE) ;
//--- Error max count reached ?
  if ((maxErrorCount () > 0) && (totalErrorCount () >= maxErrorCount ())) {
    throw max_error_count_reached_exception () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void signalRunTimeError (const C_String & inRunTimeErrorMessage
                         COMMA_LOCATION_ARGS) {
//--- Increment error count
  mErrorTotalCount ++ ;
//--- Construct location error message
  C_String errorMessage ;
  errorMessage << "Run Time Error #" << cStringWithSigned (mErrorTotalCount) << ": " << inRunTimeErrorMessage << "\n" ;
//--- Print
  ggs_printError (NULL, C_IssueWithFixIt (), errorMessage COMMA_THERE) ;
//--- Error max count reached ?
  if ((maxErrorCount () > 0) && (totalErrorCount () >= maxErrorCount ())) {
    throw max_error_count_reached_exception () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void signalRunTimeWarning (const C_String & inWarningMessage
                           COMMA_LOCATION_ARGS) {
//--- Increment warning count
  mTotalWarningCount ++ ;
//--- Construct location error message
  C_String warningMessage ;
  warningMessage << "Run Time Warning #" << cStringWithSigned (mTotalWarningCount) << ": " << inWarningMessage << "\n" ;
//--- Print
  ggs_printWarning (NULL, C_IssueWithFixIt (), warningMessage COMMA_THERE) ;
//--- Warning max count reached ?
  if ((maxWarningCount () > 0) && (totalWarningCount () >= maxWarningCount ())) {
    throw max_warning_count_reached_exception () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Actual Message Print
#endif

//---------------------------------------------------------------------------------------------------------------------*

static const utf32 COCOA_WARNING_ID = TO_UNICODE (3) ;
static const utf32 COCOA_ERROR_ID   = TO_UNICODE (4) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    Method called for printing an error                                                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void ggs_printError (const C_SourceTextInString * inSourceTextPtr,
                     const C_IssueWithFixIt & inIssue,
                     const C_String & inMessage
                     COMMA_LOCATION_ARGS) {
  C_String errorMessage = constructErrorOrWarningLocationMessage (inMessage, inIssue, inSourceTextPtr) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    if (verboseOutput ()) {
      errorMessage << "[Error raised from file '" << C_String (IN_SOURCE_FILE).lastPathComponent ()
                   << "' at line " << cStringWithSigned (IN_SOURCE_LINE) << "]\n" ;
    }
  #endif
//--- Append source string
  if (! executionModeIsIndexing ()) {
    if (cocoaOutput ()) {
      co.setForeColor (kRedForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co.appendUnicodeCharacter (COCOA_ERROR_ID COMMA_HERE) ;
      co << errorMessage ;
      co.setTextAttribute (kAllAttributesOff) ;
      co << "\n" ;
      co.flush () ;
    }else{
      co.setForeColor (kRedForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << errorMessage ;
      co.setTextAttribute (kAllAttributesOff) ;
      co << "\n" ;
      co.flush () ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    Method called for printing a warning                                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void ggs_printWarning (const C_SourceTextInString * inSourceTextPtr,
                       const C_IssueWithFixIt & inIssue,
                       const C_String & inMessage
                       COMMA_LOCATION_ARGS) {
//---
  C_String warningMessage = constructErrorOrWarningLocationMessage (inMessage, inIssue, inSourceTextPtr) ;
  #ifndef DO_NOT_GENERATE_CHECKINGS
    if (verboseOutput ()) {
      warningMessage << "[Warning raised from file '" << C_String (IN_SOURCE_FILE).lastPathComponent ()
                     << "' at line " << cStringWithSigned (IN_SOURCE_LINE) << "]\n" ;
    }
  #endif
//--- Append source string
  if (inSourceTextPtr != NULL) {
    macroValidSharedObject (inSourceTextPtr, C_SourceTextInString) ;
    inSourceTextPtr->appendSourceContents (warningMessage) ;
  }
  if (! executionModeIsIndexing ()) {
    if (cocoaOutput ()) {
      co.setForeColor (kYellowForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co.appendUnicodeCharacter (COCOA_WARNING_ID COMMA_HERE) ;
      co << warningMessage ;
      co.setTextAttribute (kAllAttributesOff) ;
      co << "\n" ;
      co.flush () ;
    }else{
      co.setForeColor (kYellowForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << warningMessage ;
      co.setTextAttribute (kAllAttributesOff) ;
      co << "\n" ;
      co.flush () ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    Method called for printing a success message                                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void ggs_printFileOperationSuccess (const C_String & inMessage) {
  if (! executionModeIsIndexing ()) {
    if (cocoaOutput ()) {
      co.setForeColor (kGreenForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << inMessage;
      co.setTextAttribute (kAllAttributesOff) ;
      co.flush () ;
    }else{
      co.setForeColor (kGreenForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << inMessage ;
      co.setTextAttribute (kAllAttributesOff) ;
      co.flush () ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    Method called for printing a file creation success                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void ggs_printFileCreationSuccess (const C_String & inMessage) {
  if (! executionModeIsIndexing ()) {
    if (cocoaOutput ()) {
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << inMessage;
      co.setTextAttribute (kAllAttributesOff) ;
      co.flush () ;
    }else{
      co.setForeColor (kBlueForeColor) ;
      co.setTextAttribute (kBoldTextAttribute) ;
      co << inMessage ;
      co.setTextAttribute (kAllAttributesOff) ;
      co.flush () ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//    Methods called for printing a message                                                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void ggs_printMessage (const C_String & inMessage
                       COMMA_LOCATION_ARGS) {
  if (! executionModeIsIndexing ()) {
    C_String message = inMessage ;
    #ifndef DO_NOT_GENERATE_CHECKINGS
      if (verboseOutput ()) {
        message << "[Displayed from file '" << C_String (IN_SOURCE_FILE).lastPathComponent ()
                << "' at line " << cStringWithSigned (IN_SOURCE_LINE) << "]\n" ;
      }
    #endif
    co << message ;
    co.flush () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark cToken
#endif

//---------------------------------------------------------------------------------------------------------------------*

cToken::cToken (void) :
mNextToken (NULL),
mStartLocation (),
mEndLocation (),
mTemplateStringBeforeToken (),
mSeparatorStringBeforeToken (),
mTokenCode (0) {
}

//---------------------------------------------------------------------------------------------------------------------*

cToken::~cToken (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark C_parsingContext
#endif

//---------------------------------------------------------------------------------------------------------------------*

C_parsingContext::C_parsingContext (void) :
mParsingArrayIndex (0),
mLocation (),
mCurrentTokenPtr (NULL),
mCurrentChar (TO_UNICODE ('\0')),
mPreviousChar (TO_UNICODE ('\0')),
mTemplateString () {
} 

//---------------------------------------------------------------------------------------------------------------------*

C_parsingContext::C_parsingContext (const C_parsingContext & inSource) :
mParsingArrayIndex (inSource.mParsingArrayIndex),
mLocation (inSource.mLocation),
mCurrentTokenPtr (inSource.mCurrentTokenPtr),
mCurrentChar (inSource.mCurrentChar),
mPreviousChar (inSource.mPreviousChar),
mTemplateString (inSource.mTemplateString) {
} 

//---------------------------------------------------------------------------------------------------------------------*

C_parsingContext & C_parsingContext::operator = (const C_parsingContext & inSource) {
  mParsingArrayIndex = inSource.mParsingArrayIndex ;
  mLocation = inSource.mLocation ;
  mCurrentTokenPtr = inSource.mCurrentTokenPtr ;
  mCurrentChar = inSource.mCurrentChar ;
  mPreviousChar = inSource.mPreviousChar ;
  mTemplateString = inSource.mTemplateString ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*
