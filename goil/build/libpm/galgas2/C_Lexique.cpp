//----------------------------------------------------------------------------------------------------------------------
//
//  'C_Lexique' : an abstract lexique class ;
//  Galgas generated scanner classes inherit from this class.
//
//  This file is part of libpm library
//
//  Copyright (C) 1996, ..., 2023 Pierre Molinaro.
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

#include "galgas2/C_Lexique.h"
#include "all-predefined-types.h"
#include "utilities/MF_MemoryControl.h"
#include "strings/unicode_character_cpp.h"
#include "strings/unicode_string_routines.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/cIndexingDictionary.h"
#include "files/C_FileManager.h"
#include "galgas2/F_verbose_output.h"

//----------------------------------------------------------------------------------------------------------------------

#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define LINE_AND_SOURCE_FILE_FOR_LEXIQUE , sourceText ().sourceFilePath ().cString (HERE), lineNumber ()
#else
  #define LINE_AND_SOURCE_FILE_FOR_LEXIQUE
#endif

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Constructors, Destructor
#endif

//----------------------------------------------------------------------------------------------------------------------

cTemplateDelimiter::
cTemplateDelimiter (const utf32 * inStartString,
                    const int32_t inStartStringLength,
                    const utf32 * inEndString,
                    const int32_t inEndStringLength,
                    void (* inReplacementFunction) (C_Lexique & inLexique, const C_String & inElementString, C_String & ioTemplateString),
                    const bool inDiscardStartString) :
mStartString (inStartString),
mStartStringLength (inStartStringLength),
mEndString (inEndString),
mEndStringLength (inEndStringLength),
mReplacementFunction (inReplacementFunction),
mDiscardStartString (inDiscardStartString) {
}

//----------------------------------------------------------------------------------------------------------------------

cTemplateDelimiter::cTemplateDelimiter (const cTemplateDelimiter & inOperand) :
mStartString (inOperand.mStartString),
mStartStringLength (inOperand.mStartStringLength),
mEndString (inOperand.mEndString),
mEndStringLength (inOperand.mEndStringLength),
mReplacementFunction (inOperand.mReplacementFunction),
mDiscardStartString (inOperand.mDiscardStartString) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique::C_Lexique (C_Compiler * inCallerCompiler,
                      const C_String & inSourceFileName
                      COMMA_LOCATION_ARGS) :
C_Compiler (inCallerCompiler COMMA_THERE),
mIndexingDictionary (nullptr),
mFirstToken (nullptr),
mLastToken (nullptr),
mCurrentTokenPtr (nullptr),
mLastSeparatorIndex (0),
mCurrentChar (TO_UNICODE ('\0')),
mPreviousChar (TO_UNICODE ('\0')),
mTokenStartLocation (),
mTokenEndLocation (),
mTriggerNonTerminalSymbolList (),
mDebugDepthCounter (0),
mDebugIsRunning (false),
mArrayForSecondPassParsing (),
mIndexForSecondPassParsing (0),
mLatexOutputString (),
mLatexNextCharacterToEnterIndex (0) {
//---
  if (inSourceFileName.length () > 0) {
    logFileRead (inSourceFileName) ;
    bool ok = false ;
    PMTextFileEncoding textFileEncoding ;
    const C_String sourceString = C_FileManager::stringWithContentOfFile (inSourceFileName, textFileEncoding, ok) ;
    if (ok) {
      const C_SourceTextInString source (sourceString,
                                         inSourceFileName,
                                         false) ; // Do not print source string
      resetAndLoadSourceFromText (source) ;
      mTokenStartLocation.resetWithSourceText (source) ;
      mTokenEndLocation.resetWithSourceText (source) ;
    }else if (inCallerCompiler != nullptr) {
      C_String errorMessage ; 
      errorMessage << "cannot read '" << inSourceFileName << "': this file does not exist or is not encoded in UTF8" ;
      inCallerCompiler->onTheFlyRunTimeError (errorMessage COMMA_THERE)  ;
    }
  }
  mCurrentChar = sourceText ().readCharOrNul (0 COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique::C_Lexique (C_Compiler * inCallerCompiler,
                      const C_String & inSourceString,
                      const C_String & inStringForError
                      COMMA_LOCATION_ARGS) :
C_Compiler (inCallerCompiler COMMA_THERE),
mIndexingDictionary (nullptr),
mFirstToken (nullptr),
mLastToken (nullptr),
mCurrentTokenPtr (nullptr),
mLastSeparatorIndex (0),
mCurrentChar (TO_UNICODE ('\0')),
mPreviousChar (TO_UNICODE ('\0')),
mTokenStartLocation (),
mTokenEndLocation (),
mTriggerNonTerminalSymbolList (),
mDebugDepthCounter (0),
mDebugIsRunning (false),
mArrayForSecondPassParsing (),
mIndexForSecondPassParsing (0),
mLatexOutputString (),
mLatexNextCharacterToEnterIndex (0) {
  const C_SourceTextInString source (inSourceString, inStringForError, verboseOutput ()) ;
  resetAndLoadSourceFromText (source) ;
  mTokenStartLocation.resetWithSourceText (source) ;
  mTokenEndLocation.resetWithSourceText (source) ;
  mCurrentChar = sourceText ().readCharOrNul (0 COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique::~C_Lexique (void) {
  macroMyDelete (mIndexingDictionary) ;
  mLastToken = nullptr ;
  mCurrentTokenPtr = nullptr ;
  while (mFirstToken != nullptr) {
    cToken * p = mFirstToken->mNextToken ;
    macroMyDelete (mFirstToken) ;
    mFirstToken = p ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Scanner configuration
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::appendLastSeparatorTo (C_String & ioString) const {
  if (nullptr != mLastToken) {
    const int32_t lastSeparatorStart = mLastToken->mEndLocation.index () + 1 ;
    const C_String lastSeparatorString = sourceText ().sourceString ().subStringFromIndex (lastSeparatorStart) ;
    ioString << lastSeparatorString ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::enterTokenFromPointer (cToken * inToken) {
  macroValidPointer (inToken) ;
//--- Append separator and comments
  const int32_t tokenStart = mTokenStartLocation.index () ;
  if (tokenStart > mLastSeparatorIndex) {
    const C_String sep = sourceText ().sourceString ().subString (mLastSeparatorIndex, tokenStart -mLastSeparatorIndex) ;
    inToken->mSeparatorStringBeforeToken << sep ;
  }
  mLastSeparatorIndex = mTokenEndLocation.index () + 1 ;
//--- Enter token in token list
  if (mLastToken == nullptr) {
    mFirstToken = inToken ;
  }else{
    mLastToken->mNextToken = inToken ;
  }
  mLastToken = inToken ;
//---
  if (executionModeIsLexicalAnalysisOnly ()) {
    C_String s ;
    for (int32_t i=inToken->mStartLocation.index () ; i<=inToken->mEndLocation.index () ; i++) {
      const utf32 c = sourceText ().readCharOrNul (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) != '\0') {
        s.appendUnicodeCharacter (c COMMA_HERE) ;
      }
    }
    co << "  " << getCurrentTokenString (inToken)
       << ", from location " << cStringWithSigned (inToken->mStartLocation.index ())
       << " (line " << cStringWithSigned (inToken->mStartLocation.lineNumber ())
       << ", column " << cStringWithSigned (inToken->mStartLocation.columnNumber ()) << ")"
       << " to location " << cStringWithSigned (inToken->mEndLocation.index ())
       << " (line " << cStringWithSigned (inToken->mEndLocation.lineNumber ())
       << ", column " << cStringWithSigned (inToken->mEndLocation.columnNumber ()) << ")" ;
    if (inToken->mTemplateStringBeforeToken.length () > 0) {
      co << ", template '" << inToken->mTemplateStringBeforeToken << "'" ;
    }
    co << "\n" ;
  }else if (executionModeIsLatex ()) {
    while (mLatexNextCharacterToEnterIndex < inToken->mStartLocation.index ()) {
      const utf32 c = sourceText ().readCharOrNul (mLatexNextCharacterToEnterIndex COMMA_HERE) ;
      appendCharacterToLatexFile (c) ;
      mLatexNextCharacterToEnterIndex ++ ;
    }
    const C_String styleName = styleNameForIndex (styleIndexForTerminal (inToken->mTokenCode)) ;
    if (styleName.length () > 0) {
      mLatexOutputString << "\\" << styleName << latexModeStyleSuffixString () << "{" ;
    }
    for (int32_t i=inToken->mStartLocation.index () ; i<=inToken->mEndLocation.index () ; i++) {
      const utf32 c = sourceText ().readCharOrNul (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) != '\0') {
        appendCharacterToLatexFile (c) ;
      }
    }
    if (styleName.length () > 0) {
      mLatexOutputString << "}" ;
    }
  //---
    mLatexNextCharacterToEnterIndex = inToken->mEndLocation.index () + 1 ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::resetForSecondPass (void) {
  mCurrentLocation.resetWithSourceText (sourceText ()) ;
  mCurrentChar = sourceText ().readCharOrNul (0 COMMA_HERE) ;
  mPreviousChar = TO_UNICODE ('\0') ;
  mCurrentTokenPtr = mFirstToken ;
  if (mCurrentTokenPtr != nullptr) {
    mStartLocationForHere = mCurrentTokenPtr->mStartLocation ;
    mEndLocationForHere = mCurrentTokenPtr->mEndLocation ;
    mStartLocationForNext = mCurrentTokenPtr->mStartLocation ;
    mEndLocationForNext = mCurrentTokenPtr->mEndLocation ;
    mTemplateString << mCurrentTokenPtr->mTemplateStringBeforeToken ;
    mCurrentLocation = mCurrentTokenPtr->mEndLocation ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Template Delimiter Scanning
#endif

//----------------------------------------------------------------------------------------------------------------------

int32_t C_Lexique::findTemplateDelimiterIndex (const cTemplateDelimiter inTemplateDelimiterArray [],
                                               const int32_t inTemplateDelimiterArrayLength) {
  int32_t templateIndex = 0 ;
  bool found = false ;
  
  while ((templateIndex < inTemplateDelimiterArrayLength) && ! found) {
    found = testForInputUTF32String (inTemplateDelimiterArray [templateIndex].mStartString,
                                     inTemplateDelimiterArray [templateIndex].mStartStringLength, 
                                     inTemplateDelimiterArray [templateIndex].mDiscardStartString) ;
    templateIndex ++ ;
  }
  templateIndex -- ;
  if (! found) {
    templateIndex = -1 ;
  }
  return templateIndex ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Lexical Analysis
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//   performLexicalAnalysis                                                                      
//
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::performLexicalAnalysis (void) {
  if (executionModeIsLexicalAnalysisOnly ()) {
    co << "*** PERFORM LEXICAL ANALYSIS ONLY (--mode=lexical-only option) ***\n" ;
  }
  bool loop = true ;
  while (loop) {
    loop = parseLexicalToken () ;
  }
  if (executionModeIsLexicalAnalysisOnly ()) {
    co << "*** END OF LEXICAL ANALYSIS ***\n" ;
  }else if (executionModeIsLatex ()) {
    generateLatexFile () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//        Methods for scanning                                                                   
//
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::advance (void) {
  mTokenEndLocation = mCurrentLocation ;
  mPreviousChar = mCurrentChar ;
  if (UNICODE_VALUE (mCurrentChar) != '\0') {
    mCurrentLocation.gotoNextLocation () ;
    mCurrentChar = sourceText ().readCharOrNul (mCurrentLocation.index () COMMA_HERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::advance (const int32_t inCount) {
  for (int32_t i=0 ; i<inCount ; i++) {
    advance () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique::testForInputUTF32CharRange (const utf32 inLowBound,
                                            const utf32 inHighBound) {
  const bool ok = (UNICODE_VALUE (inLowBound) <= UNICODE_VALUE (mCurrentChar))
     && (UNICODE_VALUE (mCurrentChar) <= UNICODE_VALUE (inHighBound)) ;
  if (ok) {
    advance () ;
  }
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique::testForInputUTF32Char (const utf32 inChar) {
  const bool ok = UNICODE_VALUE (inChar) == UNICODE_VALUE (mCurrentChar) ;
  if (ok) {
    advance () ;
  }
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique::testForCharWithFunction (bool (*inFunction) (const utf32 inUnicodeCharacter)) {
  const bool ok = inFunction (mCurrentChar) ;
  if (ok) {
    advance () ;
  }
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique::testForInputUTF32String (const utf32 * inTestCstring,
                                         const int32_t inStringLength,
                                         const bool inAdvanceOnMatch) {
//--- Test
  bool ok = utf32_strncmp (sourceText ().temporaryUTF32StringAtIndex (mCurrentLocation.index () COMMA_HERE),
                           inTestCstring,
                           inStringLength) == 0 ;
//--- Avancer dans la lecture si test ok et fin de source non atteinte
  if (ok && inAdvanceOnMatch) {
    advance (inStringLength) ;
  }
//---
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique::notTestForInputUTF32String (const utf32 * inTestCstring,
                                            const int32_t inStringLength,
                                            const char * inEndOfFileErrorMessage
                                            COMMA_LOCATION_ARGS) {
  bool ok = UNICODE_VALUE (sourceText ().readCharOrNul (mCurrentLocation.index () COMMA_HERE)) != '\0' ;
  if (! ok) { // End of input file reached
    lexicalError (inEndOfFileErrorMessage COMMA_THERE) ;
  }else{
  //--- Test
    ok = false ;
    for (int32_t i=0 ; (i<inStringLength) && ! ok ; i++) {
      ok = UNICODE_VALUE (sourceText ().readCharOrNul (mCurrentLocation.index () + i COMMA_HERE)) != UNICODE_VALUE (* inTestCstring) ;
      inTestCstring ++ ;
    }
    if (ok) {
      advance () ;
    }else{
      advance (inStringLength) ;
    }
  }
//---
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::lexicalLog (LOCATION_ARGS) {
  C_String message ;
  message << "LEXICAL LOG:'" ;
  message.appendCLiteralCharConstant (mCurrentChar) ;
  message << "'\n" ;
  printMessage (message COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//    Search in an ordered list (used for searching into scanner generated tables)               
//
//----------------------------------------------------------------------------------------------------------------------

int32_t C_Lexique::searchInList (const C_String & inString,
                                 const C_unicode_lexique_table_entry inTable [],
                                 const int32_t inTableSize) {
  const int32_t searchedStringLength = inString.length () ;
  int32_t code = -1 ; // -1 means 'not found'
  int32_t bottom = 0 ;
  int32_t top = inTableSize - 1 ;
  
  while ((code < 0) && (top >= bottom)) {
    const int32_t index = (bottom + top) / 2 ;
    int32_t result = searchedStringLength - inTable [index].mEntryStringLength ;
    if (result == 0) {
      result = inString.compare (inTable [index].mEntryString) ;
    }
    if (result < 0) { // <
      top = index - 1 ;
    }else if (result > 0) { // >
      bottom = index + 1 ;
    }else{
      code = inTable [index].mTokenCode ;
    }
  }
  return code ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Handling an error
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::internalBottomUpParserError (LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    printf ("*** Fatal error: Internal bottom-up parser error at line %d of file '%s'.\n", IN_SOURCE_LINE, IN_SOURCE_FILE) ;
  #else
    printf ("*** Fatal error: Internal bottom-up parser error.\n") ;
  #endif
  exit (1) ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//           Lexical error                                                                       
//
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::unknownCharacterLexicalError (LOCATION_ARGS) {
  C_String errorMessage ;
  errorMessage << "Unknown character: " << unicodeName (mCurrentChar)
               << " (Unicode " << cHexStringWithUnsigned (UNICODE_VALUE (mCurrentChar)) << ")" ;
  lexicalError (errorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::lexicalError (const C_String & inLexicalErrorMessage
                              COMMA_LOCATION_ARGS) {
  signalLexicalError (this, sourceText (), C_IssueWithFixIt (mCurrentLocation, mCurrentLocation, TC_Array <C_FixItDescription> ()), inLexicalErrorMessage COMMA_THERE) ;
  if (executionModeIsLatex ()) {
    signalLexicalErrorInLatexOutput () ;
  }
  throw C_lexicalErrorException () ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                Signaler une erreur syntaxique                                                 
//
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::parsingError (const TC_UniqueArray <int32_t> & inExpectedTerminalsArray,
                              const cToken * inPreviousTokenPtr,
                              const cToken * inCurrentTokenPtr,
                              const int32_t inCurrentTokenCode
                              COMMA_LOCATION_ARGS) {
//--- Build error message
  C_String foundTokenMessage = getMessageForTerminal (inCurrentTokenCode) ;
  const int32_t expectedTerminalsCount = inExpectedTerminalsArray.count () ;
  TC_UniqueArray <C_String> expectedTokenNames (expectedTerminalsCount, C_String () COMMA_HERE) ;
  for (int32_t i=0 ; i<expectedTerminalsCount ; i++) {
    expectedTokenNames (i COMMA_HERE) = getMessageForTerminal (inExpectedTerminalsArray (i COMMA_HERE)) ;
  }
//--- Sort expected token name array
  expectedTokenNames.sortArrayUsingCompareMethod () ;
//--- Signal error
  signalParsingError (this,
                      sourceText (),
                      (inPreviousTokenPtr == nullptr) ? C_LocationInSource () : inPreviousTokenPtr->mEndLocation,
                      C_IssueWithFixIt (inCurrentTokenPtr->mStartLocation, inCurrentTokenPtr->mEndLocation, TC_Array <C_FixItDescription> ()),
                      foundTokenMessage,
                      expectedTokenNames COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Scanner warning
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::lexicalWarning (const C_String & inLexicalWarningMessage
                                COMMA_LOCATION_ARGS) { // §
  signalLexicalWarning (this, sourceText (), C_IssueWithFixIt (mCurrentLocation, mCurrentLocation, TC_Array <C_FixItDescription> ()), inLexicalWarningMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Top-down parsing
#endif

//----------------------------------------------------------------------------------------------------------------------

static bool TRACE_LL1_PARSING (void) { return false ; }

//----------------------------------------------------------------------------------------------------------------------
//
//   Test if a terminal symbol can be accepted in current context                                
//
//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique::acceptTerminalForErrorSignaling (const int32_t inTerminal,
                                                 const int32_t inProductions [],
                                                 const int32_t inProductionIndexes [],
                                                 const int32_t inFirstProductionIndex [],
                                                 const int32_t inDecisionTable [],
                                                 const int32_t inDecisionTableIndexes [],
                                                 const TC_Array <int32_t> & inErrorStack,
                                                 const int32_t inErrorProgramCounter) {
  if (TRACE_LL1_PARSING ()) {
    C_String m = getMessageForTerminal (inTerminal) ;
    co << "------ Enter 'acceptTerminalForErrorSignaling' with '"
       << m
       << "' ("
       << inTerminal
       << ") terminal and program counter "
       << inErrorProgramCounter ;
    co.flush () ;
  }
  bool accept = false ;
  int32_t programCounter = inErrorProgramCounter ;
  TC_Array <int32_t> stack = inErrorStack ;
  bool loop = true ;
  while (loop) {
    const int32_t instruction = inProductions [programCounter] ;
    programCounter ++ ;
    if (instruction > 0) { // We reach a terminal
      const int32_t reachedTerminal = (int32_t) (instruction - 1) ;
      accept = reachedTerminal == inTerminal ;
      if (TRACE_LL1_PARSING ()) {
        const C_String m = getMessageForTerminal (reachedTerminal) ;
        co << "reached '"
           << m
           << "' terminal"
           << (accept ? " (accepted)" : "")
           << "\n" ;
        co.flush () ;
      }
      loop = false ;
    }else if (instruction < 0) { // We reach a nonterminal
      const int32_t reachedNonterminal = (int32_t) (- instruction - 1) ;
      if (TRACE_LL1_PARSING ()) {
        co << "reached non-terminal "
           << reachedNonterminal
           << "\n" ;
        co.flush () ;
      }
      int32_t nonTerminalEntry = inDecisionTableIndexes [reachedNonterminal] ;
      if (inDecisionTable [nonTerminalEntry] < 0) { // Only one rule : call it
        stack.appendObject (programCounter) ;
        programCounter = inProductionIndexes [inFirstProductionIndex [reachedNonterminal]] ;
        if (TRACE_LL1_PARSING ()) {
          co << "One rule: goto " << programCounter << "\n" ; co.flush () ;
        }
      }else{ // More than one rule : test if terminal is accepted, and call rule
        loop = false ;
        int32_t choice = 0 ;
        bool found = false ;
        while ((inDecisionTable [nonTerminalEntry] >= 0) && ! found) {
          while ((inDecisionTable [nonTerminalEntry] >= 0) && ! found) {
            found = inDecisionTable [nonTerminalEntry] == inTerminal ;
            if (TRACE_LL1_PARSING ()) {
              const C_String m = getMessageForTerminal (inDecisionTable [nonTerminalEntry]) ;
              co << "try '" << m << "' non terminal" << (found ? " (accepted)": "") << "\n" ; co.flush () ;
            }
            if (found) {
              int32_t newProgramCounter = programCounter ;
              TC_Array <int32_t> newStack = stack ;
              newStack.appendObject (newProgramCounter) ;
              newProgramCounter = inProductionIndexes [inFirstProductionIndex [reachedNonterminal] + choice] ;
              accept = acceptTerminalForErrorSignaling (inTerminal,
                                                        inProductions,
                                                        inProductionIndexes,
                                                        inFirstProductionIndex,
                                                        inDecisionTable,
                                                        inDecisionTableIndexes,
                                                        newStack,
                                                        newProgramCounter) ;
            }
            nonTerminalEntry ++ ;
          }
          nonTerminalEntry ++ ;
          choice ++ ; 
        }
      }
    }else if (stack.count () > 0) { // We reach a END OF PRODUCTION
      programCounter = stack.lastObject (HERE) ;
      stack.removeLastObject (HERE) ;
    }else{ // We reach the end of production rules
      accept = inTerminal == 0 ; // 0 is always "end_of_text" terminal symbol
      loop = false ;
    }
  }
  if (TRACE_LL1_PARSING ()) {
    co << "------ Exit 'acceptTerminalForErrorSignaling' with accept == " << (accept ? "true" : "false") << "\n" ;
  }
  return accept ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Build expected terminals array on syntax error with LL (1) parser                           
//
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::buildExpectedTerminalsArrayOnSyntaxError (const int32_t inErrorProgramCounter,
                                                          const int32_t inErrorStackCount,
                                                          const TC_Array <int32_t> & inStack,
                                                          const TC_Array <int32_t> & inErrorStack,
                                                          const int32_t inProductions [],
                                                          const int32_t inProductionIndexes [],
                                                          const int32_t inFirstProductionIndex [],
                                                          const int32_t inDecisionTable [],
                                                          const int32_t inDecisionTableIndexes [],
                                                          TC_UniqueArray <int32_t> & outExpectedTerminalsArray) {
//--- First, go to the next non terminal, terminal or end of productions rules
  int32_t programCounter = inErrorProgramCounter ;
  const int32_t countToCopy = inErrorStackCount - inErrorStack.count () ;
  TC_Array <int32_t> errorStack (inErrorStackCount COMMA_HERE) ;
  for (int32_t i=0 ; i<countToCopy ; i++) {
    errorStack.appendObject (inStack (i COMMA_HERE)) ;
  }
  for (int32_t i=inErrorStack.count () - 1 ; i>=0 ; i--) {
    errorStack.appendObject (inErrorStack (i COMMA_HERE)) ;
  }
  if (TRACE_LL1_PARSING ()) {
    co << "------ Enter 'buildExpectedTerminalsArrayOnSyntaxError'\n"
       << "programCounter: " << programCounter << ", errorStack: " << errorStack.count() << " value(s):" ;
    for (int32_t i=0 ; i<errorStack.count() ; i++) {
      co << " " << errorStack (i COMMA_HERE) ;
    }
    co << "\n" ;
    co.flush () ;
  }
  bool loop = true ;
  while (loop) {
    if (inProductions [programCounter] > 0) { // We reach a terminal (when >0)
      loop = false ;
      if (TRACE_LL1_PARSING ()) {
        C_String m = getMessageForTerminal (inProductions [programCounter]) ;
        co << "Terminal '" << m << "' (" << inProductions [programCounter] << ") reached\n" ;
        co.flush () ;
      }
    }else if (inProductions [programCounter] < 0) { // We reach a non terminal (<0)
      const int32_t nonTerminal = (int32_t) (- inProductions [programCounter] - 1) ;
      if (TRACE_LL1_PARSING ()) {
        co << "Non-Terminal " << nonTerminal << " reached\n" ;
        co.flush () ;
      }
    //--- We look if we get a non terminal that has only one production rule
      const int32_t nonTerminalEntry = inDecisionTableIndexes [nonTerminal] ;
      const bool onlyOneRule = inDecisionTable [nonTerminalEntry] < 0 ;
      if (onlyOneRule) { // Go to this rule
        errorStack.appendObject ((int32_t) (programCounter + 1)) ;
        programCounter = inProductionIndexes [inFirstProductionIndex [nonTerminal]] ;
        if (TRACE_LL1_PARSING ()) {
          co << "Only one rule: goto " << programCounter << "\n" ;
          co.flush () ;
        }
      }else{
        loop = false ; // Stop searching
      }
    }else if (errorStack.count () > 0) { // Execute a 'return' instruction
      programCounter = errorStack.lastObject (HERE) ;
      errorStack.removeLastObject (HERE) ;
      if (TRACE_LL1_PARSING ()) {
        co << "return instruction (goes to " << programCounter << ")\n" ;
        co.flush () ;
      }
    }else{ // End of source reached
      if (TRACE_LL1_PARSING ()) {
        co << "end of source reached\n" ;
        co.flush () ;
      }
      loop = false ;
    }
  }
//--- Decision for build expected terminals array
  if (errorStack.count () == 0) { // We reach end of productions rules
    outExpectedTerminalsArray.appendObject (0) ; // 0 is always "end_of_text" terminal symbol
    if (TRACE_LL1_PARSING ()) {
      co << "add 'end of source' to outExpectedTerminalsArray\n" ;
      co.flush () ;
    }
  }else if (inProductions [programCounter] > 0) { // We reach a terminal symbol
    const int32_t terminalSymbol = (int32_t) (inProductions [programCounter] - 1) ;
    outExpectedTerminalsArray.appendObject (terminalSymbol) ;
    if (TRACE_LL1_PARSING ()) {
      C_String m = getMessageForTerminal (inProductions [programCounter]) ;
      co << "add '" << m << "' (" << inProductions [programCounter] << ") to outExpectedTerminalsArray\n" ;
      co.flush () ;
    }
  }else{  // We reach a non terminal symbol
    const int32_t nonTerminal = (int32_t) (- inProductions [programCounter] - 1) ;
    int32_t nonTerminalEntry = inDecisionTableIndexes [nonTerminal] ;
    while (inDecisionTable [nonTerminalEntry] >= 0) {
      while (inDecisionTable [nonTerminalEntry] >= 0) {
        const bool ok = acceptTerminalForErrorSignaling (inDecisionTable [nonTerminalEntry],
                                                        inProductions,
                                                        inProductionIndexes,
                                                        inFirstProductionIndex,
                                                        inDecisionTable,
                                                        inDecisionTableIndexes,
                                                        errorStack,
                                                        programCounter) ;
        if (ok) {
          if (TRACE_LL1_PARSING ()) {
            C_String m = getMessageForTerminal (inDecisionTable [nonTerminalEntry]) ;
            co << "add '" << m << "' (" << inDecisionTable [nonTerminalEntry] << ") to outExpectedTerminalsArray\n" ;
            co.flush () ;
          }
          outExpectedTerminalsArray.appendObject (inDecisionTable [nonTerminalEntry]) ;
        }
        nonTerminalEntry ++ ;
      }
      nonTerminalEntry ++ ;  
    }
  }
  if (TRACE_LL1_PARSING ()) {
    co << "------ Exit 'buildExpectedTerminalsArrayOnSyntaxError'\n" ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Perform top down parsing (called by LL (1) parser)                                          
//
//----------------------------------------------------------------------------------------------------------------------

static void indentForParseOnly (const int32_t inIndentation) {
  for (int32_t i=1 ; i<inIndentation ; i++) {
    co << "|  " ;
  }
  if (inIndentation > 0) {
    co << "|- " ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique::performTopDownParsing (const int32_t inProductions [],
                                       const cProductionNameDescriptor inProductionNames [],
                                       const int32_t inProductionIndexes [],
                                       const int32_t inFirstProductionIndex [],
                                       const int32_t inDecisionTable [],
                                       const int32_t inDecisionTableIndexes [],
                                       const int32_t inProgramCounterInitialValue) {
  bool result = false ;
//--- Lexical analysis
  performLexicalAnalysis () ;
  if (! executionModeIsLexicalAnalysisOnly ()) {
  //--- Variables for generating syntax tree in a form suitable for graphviz
    const bool produceSyntaxTree = gOption_galgas_5F_builtin_5F_options_outputConcreteSyntaxTree.mValue
       && (sourceFilePath ().stringByDeletingPathExtension () != "") ;
    C_String syntaxTreeDescriptionString ;
    TC_Array <uint32_t> productionUniqueNameStack ;
    uint32_t uniqueProductionNameIndex = 0 ;
    uint32_t uniqueTerminalIndex = 0 ;
    uint32_t currentProductionName = 0 ;
    if (produceSyntaxTree) {
      syntaxTreeDescriptionString << "digraph G {\n"
                                     "  size =\"4,4\";\n" ;
    }
  //---
    int32_t indentationForParseOnly = 0 ;
    cToken * previousTokenPtr = nullptr ;
    cToken * tokenPtr = mFirstToken ;
    if (executionModeIsSyntaxAnalysisOnly ()) {
      co << "*** PERFORM TOP-DOWN PARSING ONLY (--mode=syntax-only option) ***\n" ;
    }
    TC_UniqueArray <int32_t> listForSecondPassParsing ;
    TC_Array <int32_t> stack (10000 COMMA_HERE) ;
    TC_Array <int32_t> errorStack ;
    int32_t errorStackCount = 0 ;
    bool loop = tokenPtr != nullptr ;
    result = true ;
    int32_t programCounter = inProgramCounterInitialValue ;
    int32_t errorProgramCounter = inProgramCounterInitialValue ;
    int32_t currentToken = (tokenPtr != nullptr) ? tokenPtr->mTokenCode : int32_t (-1) ;
    if (tokenPtr == nullptr) {
      mCurrentLocation.resetLocation () ;
    }else{
      mCurrentLocation = tokenPtr->mEndLocation ;
    }
    while (loop) {
    //--- If no current token, get one
      if (currentToken < 0) {
        if (tokenPtr == nullptr) {
          currentToken = 0 ; // 0 means end of source file
        }else{
          previousTokenPtr = tokenPtr ;
          tokenPtr = tokenPtr->mNextToken ;
          currentToken = (tokenPtr != nullptr) ? tokenPtr->mTokenCode : ((int32_t) 0) ;
          if (tokenPtr != nullptr) {
            mCurrentLocation = tokenPtr->mEndLocation ;
          }
        }
      }
      if (TRACE_LL1_PARSING ()) {
        co << "---------------------------\n"
              "Current token is " << getCurrentTokenString (tokenPtr) << " (#" << currentToken << ")\n" ;
        co.flush () ;
      }
    //--- Get instruction to do
      const int32_t instruction = inProductions [programCounter] ;
      programCounter ++ ;
    //--- Instruction is non terminal call ?
      if (instruction < 0) {
      //--- Get entry of nonterminal symbol to parse
        const int32_t nonTerminalToParse = (int32_t) (- instruction - 1) ;
        if (TRACE_LL1_PARSING ()) {
          co << "Parse non terminal " << cStringWithSigned (nonTerminalToParse) << ": " ;
          co.flush () ;
        }
        int32_t nonTerminalEntry = inDecisionTableIndexes [nonTerminalToParse] ;
        if (inDecisionTable [nonTerminalEntry] < 0) { // Means only one production : don't make any choice
          if (TRACE_LL1_PARSING ()) {
            co << " ok (only one production)\n" ;
            co.flush () ;
          }
          stack.appendObject (programCounter) ;
          programCounter = inProductionIndexes [inFirstProductionIndex [nonTerminalToParse]] ;
          if (produceSyntaxTree) {
            uniqueProductionNameIndex ++ ;
            syntaxTreeDescriptionString << "  NT" << cStringWithUnsigned (uniqueProductionNameIndex) << " [label=\"" << inProductionNames [inFirstProductionIndex [nonTerminalToParse]].mName << "\", shape=box];\n" ;
            if (currentProductionName > 0) {
              syntaxTreeDescriptionString << "  NT"
                                          << cStringWithUnsigned (currentProductionName)
                                          << " -> NT"
                                          << cStringWithUnsigned (uniqueProductionNameIndex)
                                          << ";\n" ;
            }
            productionUniqueNameStack.appendObject (currentProductionName) ;
            currentProductionName = uniqueProductionNameIndex ;
          }
          if (executionModeIsSyntaxAnalysisOnly ()) {
            indentForParseOnly (indentationForParseOnly) ;
            co << inProductionNames [inFirstProductionIndex [nonTerminalToParse]].mName
               << ", file '" << inProductionNames [inFirstProductionIndex [nonTerminalToParse]].mFileName
               << "', line " << cStringWithUnsigned (inProductionNames [inFirstProductionIndex [nonTerminalToParse]].mLineNumber)
               << "\n" ;
            indentationForParseOnly ++ ;
          }
        }else{ //--- There are several choices : find the one to do
          if (TRACE_LL1_PARSING ()) {
            co << " try tokens\n" ; co.flush () ;
          }
          int32_t choice = -1 ;
          bool found = false ;
          while ((inDecisionTable [nonTerminalEntry] >= 0) && ! found) {
            while ((inDecisionTable [nonTerminalEntry] >= 0) && ! found) {
              found = currentToken == inDecisionTable [nonTerminalEntry] ;
              if (TRACE_LL1_PARSING ()) {
                C_String m = getMessageForTerminal (inDecisionTable [nonTerminalEntry]) ;
                co << " try " << m << " (" << inDecisionTable [nonTerminalEntry]
                   << ")" << (found ? " (accepted)" : "") << "\n" ;
                co.flush () ;
              }
              nonTerminalEntry ++ ;
            }
            choice ++ ;
            nonTerminalEntry ++ ;  
          }
        //--- Found : call production rule
          if (found) {
            stack.appendObject (programCounter) ;
            programCounter = inProductionIndexes [inFirstProductionIndex [nonTerminalToParse] + choice] ;
            if (produceSyntaxTree) {
              uniqueProductionNameIndex ++ ;
              syntaxTreeDescriptionString << "  NT" << cStringWithUnsigned (uniqueProductionNameIndex)
                                          << " [label=\"" << inProductionNames [inFirstProductionIndex [nonTerminalToParse] + choice].mName << "\", shape=box];\n" ;
              if (currentProductionName > 0) {
                syntaxTreeDescriptionString << "  NT"
                                            << cStringWithUnsigned (currentProductionName)
                                            << " -> NT"
                                            << cStringWithUnsigned (uniqueProductionNameIndex)
                                            << ";\n" ;
              }
              productionUniqueNameStack.appendObject (currentProductionName) ;
              currentProductionName = uniqueProductionNameIndex ;
            }
            if (executionModeIsSyntaxAnalysisOnly ()) {
              indentForParseOnly (indentationForParseOnly) ;
              co << inProductionNames [inFirstProductionIndex [nonTerminalToParse + choice]].mName
                 << ", file '" << inProductionNames [inFirstProductionIndex [nonTerminalToParse + choice]].mFileName
                 << "', line " << cStringWithUnsigned (inProductionNames [inFirstProductionIndex [nonTerminalToParse + choice]].mLineNumber)
                 << "\n" ;
              indentationForParseOnly ++ ;
            }
            listForSecondPassParsing.appendObject (choice + 1) ;
          }else{ // Syntax error
            TC_UniqueArray <int32_t> expectedTerminalsArray (100 COMMA_HERE) ;
            buildExpectedTerminalsArrayOnSyntaxError (errorProgramCounter,
                                                      errorStackCount,
                                                      stack,
                                                      errorStack,
                                                      inProductions,
                                                      inProductionIndexes,
                                                      inFirstProductionIndex,
                                                      inDecisionTable,
                                                      inDecisionTableIndexes,
                                                      expectedTerminalsArray) ;
            if (TRACE_LL1_PARSING ()) {
              co << expectedTerminalsArray.count () << " Token(s) in syntax error message\n" ; co.flush () ;
            }
            parsingError (expectedTerminalsArray, previousTokenPtr, tokenPtr, currentToken LINE_AND_SOURCE_FILE_FOR_LEXIQUE) ;
            result = loop = false ;
            listForSecondPassParsing.removeAllKeepingCapacity () ;
          }
        }
    //--- It is a terminal symbol
      }else if (instruction > 0) {
        const int32_t terminalSymbol = int32_t (instruction - 1) ;
        if (currentToken == terminalSymbol) {
          if (executionModeIsSyntaxAnalysisOnly ()) {
            indentForParseOnly (indentationForParseOnly) ;
            co << getCurrentTokenString (tokenPtr) << "\n" ;
          }
          currentToken = -1 ; // Ok, current terminal symbol is no longer available
          if (produceSyntaxTree) {
            syntaxTreeDescriptionString << "  T" << cStringWithUnsigned (uniqueTerminalIndex) << " [shape=ellipse, label=" ;
            syntaxTreeDescriptionString.appendCLiteralStringConstant (getCurrentTokenString (tokenPtr)) ;
            syntaxTreeDescriptionString << "];\n"
                                        << "  NT"
                                        << cStringWithUnsigned (currentProductionName)
                                        << " -> T"
                                        << cStringWithUnsigned (uniqueTerminalIndex)
                                        << ";\n" ;
            uniqueTerminalIndex ++ ;
          }
          errorStackCount = stack.count () ;
          errorStack.removeAllKeepingCapacity () ;
          errorProgramCounter = programCounter ;
        }else{ // Error !
          if (TRACE_LL1_PARSING ()) {
            co << "ERROR: TOKEN NOT EXPECTED\n" ; co.flush () ;
          }
          TC_UniqueArray <int32_t> expectedTerminalsArray (100 COMMA_HERE) ;
          buildExpectedTerminalsArrayOnSyntaxError (errorProgramCounter,
                                                    errorStackCount,
                                                    stack,
                                                    errorStack,
                                                    inProductions,
                                                    inProductionIndexes,
                                                    inFirstProductionIndex,
                                                    inDecisionTable,
                                                    inDecisionTableIndexes,
                                                    expectedTerminalsArray) ;
          parsingError (expectedTerminalsArray, previousTokenPtr, tokenPtr, currentToken LINE_AND_SOURCE_FILE_FOR_LEXIQUE) ;
          result = loop = false ;
          listForSecondPassParsing.removeAllKeepingCapacity () ;
        }
    //--- It is the end of a production    
      }else if (stack.count () > 0) {
        if (TRACE_LL1_PARSING ()) {
          co << "END OF PRODUCTION REACHED\n" ; co.flush () ;
        }
        programCounter = stack.lastObject (HERE) ;
        if (errorStackCount >= stack.count ()) {
          errorStack.appendObject (programCounter) ;
        }
        stack.removeLastObject (HERE) ;
        if (produceSyntaxTree) {
          currentProductionName = productionUniqueNameStack.lastObject (HERE) ;
          productionUniqueNameStack.removeLastObject (HERE) ;
        }
        if (executionModeIsSyntaxAnalysisOnly ()) {
          indentationForParseOnly -- ;
        }
    //--- End of start symbol analysis  
      }else if (currentToken == 0) { // We got the "end of text" non terminal : ok
        loop = false ;
      }else{ // We reach the end of text, but current terminal is not "end of text"
      //--- This is a syntax error
        TC_UniqueArray <int32_t> expectedTerminalsArray (100 COMMA_HERE) ;
        buildExpectedTerminalsArrayOnSyntaxError (errorProgramCounter,
                                                  errorStackCount,
                                                  stack,
                                                  errorStack,
                                                  inProductions,
                                                  inProductionIndexes,
                                                  inFirstProductionIndex,
                                                  inDecisionTable,
                                                  inDecisionTableIndexes,
                                                  expectedTerminalsArray) ;     
        parsingError (expectedTerminalsArray, previousTokenPtr, tokenPtr, currentToken LINE_AND_SOURCE_FILE_FOR_LEXIQUE) ;
        result = loop = false ;
        listForSecondPassParsing.removeAllKeepingCapacity () ;
      }
    }
  //--- Output graphviz file
    if (produceSyntaxTree) {
      syntaxTreeDescriptionString << "}\n" ;
      const C_String dotFilePath = sourceFilePath ().stringByDeletingPathExtension () + ".dot" ;
      GALGAS_bool fileWritten ;
      GALGAS_string (syntaxTreeDescriptionString).method_writeToFileWhenDifferentContents (GALGAS_string (dotFilePath), fileWritten, this COMMA_HERE) ;
    }
  //--- Set current read location to 0
    listForSecondPassParsing.copyTo (mArrayForSecondPassParsing) ;
    resetForSecondPass () ;
    if (executionModeIsSyntaxAnalysisOnly ()) {
      co << "*** END OF PARSING (success: "
         << (result ? "yes" : "no")
         << ") ***\n" ;
    }
  }
//---
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Bottom up parsing
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//   Test if a given terminal symbol can be accepted for signaling an error (for bottom-up parsing)                    *
//
//----------------------------------------------------------------------------------------------------------------------

static bool acceptExpectedTerminalForBottomUpParsingError (const int32_t inExpectedTerminal,
                                                           const int32_t inExpectedAction,
                                                           const TC_Array <int32_t> & inSLRstack,
                                                           const int32_t inActionTable [],
                                                           const uint32_t inActionTableIndex [],
                                                           const int32_t * inSuccessorTable [],
                                                           const int32_t inProductionsTable []) {
  bool accept = inExpectedAction > 1 ; // accept if it is a shift action
  if (! accept) {
    int32_t actionCode = inExpectedAction ;
    TC_Array <int32_t> stack (inSLRstack) ; // Duplicate stack
    bool loop = true ;
    while (loop) {
    //--- Perform reduce action
      const int32_t reduceAction = (int32_t) (- actionCode - 1) ;
      MF_Assert (reduceAction >= 0, "reduceAction (%lld) < 0", reduceAction, 0) ;
      const int32_t nonTerminal = inProductionsTable [2 * reduceAction] ;
      const int32_t reduceSize = inProductionsTable [2 * reduceAction + 1] ;
      stack.removeLastObjects (2 * reduceSize  COMMA_HERE) ;
   //--- Get Successor state
      const int32_t tempCurrentState = stack.lastObject (HERE) ;
      MF_Assert (tempCurrentState >= 0, "tempCurrentState (%lld) < 0", tempCurrentState, 0) ;
      const int32_t * successorTable = inSuccessorTable [tempCurrentState] ;
      int32_t newCurrentState = -1 ; 
      while (((* successorTable) >= 0) && (newCurrentState < 0)) {
        if ((* successorTable) == nonTerminal) {
          successorTable ++ ;
          newCurrentState = (* successorTable) ;
        }
        successorTable ++ ;
        successorTable ++ ;
      }
      MF_Assert (newCurrentState >= 0, "newCurrentState (%lld) < 0", newCurrentState, 0) ;
      stack.appendObject (-1) ; // Enter any value
      stack.appendObject (newCurrentState) ; // Enter next current state
    //--- In the state, find action corresponding to expected terminal
      const int32_t currentState = stack (stack.count () - 1 COMMA_HERE) ;
      MF_Assert (currentState >= 0, "currentState (%lld) < 0", currentState, 0) ;
      const int32_t * actionTable = & (inActionTable [inActionTableIndex [currentState]]) ;
      actionCode = 0 ; 
      while (((* actionTable) >= 0) && (actionCode == 0)) {
        if ((* actionTable) == inExpectedTerminal) {
          actionTable ++ ;
          actionCode = (* actionTable) ;
        }
        actionTable ++ ;
        actionTable ++ ;
      }
    //--- action == 0 means the terminal is not expected : exit from loop, and return false
    //--- actionCode > 0 means a shift action is done : so the terminal is accepted : exit and return true
    //--- actionCode < 0 means a reduce action is done, don't exit, and perform the reduce action
      loop = actionCode < 0 ;
      accept = actionCode > 0 ;
    }
  }
  return accept ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Perform bottom up parsing (called by SLR and LR (1) parsers)                                
//
//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique::performBottomUpParsing (const int32_t inActionTable [],
                                        const char * inNonTerminalSymbolNames [],
                                        const uint32_t inActionTableIndex [],
                                        const int32_t * inSuccessorTable [],
                                        const int32_t inProductionsTable []) {
  bool result = false ;
  performLexicalAnalysis () ;
  if (! executionModeIsLexicalAnalysisOnly ()) {
    if (executionModeIsSyntaxAnalysisOnly ()) {
      co << "*** PERFORM BOTTOM-UP PARSING ONLY (--mode=syntax-only option) ***\n"
            "  Initial State: S0\n" ;
    }
  //--- Variables for generating syntax tree in a form suitable for graphviz
    const bool produceSyntaxTree = gOption_galgas_5F_builtin_5F_options_outputConcreteSyntaxTree.mValue
       && (sourceFilePath ().stringByDeletingPathExtension () != "") ;
    C_String syntaxTreeDescriptionString ;
    TC_Array <C_String> shiftedElementStack ;
    shiftedElementStack.appendObject ("TOP") ;
    uint32_t uniqueTerminalIndex = 0 ;
    uint32_t currentProductionName = 0 ;
    if (produceSyntaxTree) {
      syntaxTreeDescriptionString << "digraph G {\n"
                                     "  size =\"4,4\";\n" ;
    }
  //--- Perform first pass
    TC_UniqueArray <TC_UniqueArray <int32_t> > executionList (100 COMMA_HERE) ;
    executionList.appendDefaultObjectUsingSwap () ;

    TC_Array <int32_t> stack (10000 COMMA_HERE) ;
    stack.appendObject (0) ; // Enter initial state
    int32_t errorSignalingUselessEntryOnTopOfStack = 0 ;
    TC_Array <int32_t> poppedErrors (1000 COMMA_HERE)  ;
    cToken * previousTokenPtr = nullptr ;
    cToken * tokenPtr = mFirstToken ;

    int32_t currentToken = int32_t (-1) ;
    if (tokenPtr == nullptr) {
      mCurrentLocation.resetLocation () ;
    }else{
      currentToken = tokenPtr->mTokenCode ;
      mCurrentLocation = tokenPtr->mEndLocation ;
    }
    bool loop = true ;
    result = true ;
    while (loop) {
      if (currentToken < 0) {
        if (tokenPtr == nullptr) {
          currentToken = 0 ; // 0 means end of source file
        }else{
          previousTokenPtr = tokenPtr ;
          tokenPtr = tokenPtr->mNextToken ;
          currentToken = 0 ;
          if (tokenPtr != nullptr) {
            mCurrentLocation = tokenPtr->mEndLocation ;
            currentToken = tokenPtr->mTokenCode ;
          }
        }
      }
    //--- Get Action code -----------------------------------
      const int32_t currentState = stack.lastObject (HERE) ;
      MF_Assert (currentState >= 0, "currentState (%lld) < 0", currentState, 0) ;
      const int32_t * actionTable = & (inActionTable [inActionTableIndex [currentState]]) ;
      int32_t actionCode = 0 ; 
      while (((* actionTable) >= 0) && (actionCode == 0)) {
        if ((* actionTable) == currentToken) {
          actionTable += 1 ;
          actionCode = (* actionTable) ;
        }
        actionTable += 2 ;
      }
    //--- Decision from action code value
      if (actionCode > 1) {
      //--- Token has been used
        currentToken = -1 ;
      //--- Shift action ------------------------------------
        actionCode = int32_t (actionCode - 2) ;
        stack.appendObject (-1) ; // Enter any value
        stack.appendObject (actionCode) ; // Enter next current state
        poppedErrors.removeAllKeepingCapacity () ;
        errorSignalingUselessEntryOnTopOfStack = 0 ;
        executionList.appendDefaultObjectUsingSwap () ;
      //---
        if (produceSyntaxTree) {
          C_String terminalUniqueName ;
          terminalUniqueName << "T" << cStringWithUnsigned (uniqueTerminalIndex) ;
          syntaxTreeDescriptionString << "  " << terminalUniqueName << " [shape=ellipse, label=" ;
          syntaxTreeDescriptionString.appendCLiteralStringConstant (getCurrentTokenString (tokenPtr)) ;
          syntaxTreeDescriptionString << "];\n" ;
          shiftedElementStack.appendObject (terminalUniqueName) ;
          uniqueTerminalIndex ++ ;
        }
      //--- Parse Only : print terminal symbol
        if (executionModeIsSyntaxAnalysisOnly ()) {
          co << "  [S" << cStringWithSigned (currentState) << ", "
             << getCurrentTokenString (tokenPtr)
             << "] |- Shift -> S" << cStringWithSigned (actionCode) << "\n" ;
        }
      }else if (actionCode < 0) {
      //--- Reduce action ------------------------------------
        actionCode = int32_t (- actionCode - 1) ;
        MF_Assert (actionCode >= 0, "actionCode (%lld) < 0", actionCode, 0) ;
        const int32_t nonTerminal = inProductionsTable [2 * actionCode] ;
        const int32_t reduceSize = inProductionsTable [2 * actionCode + 1] ;
        const int32_t executionListLength = executionList.count () ;
        for (int32_t i=executionListLength - reduceSize ; i<executionListLength ; i++) {
          executionList (executionListLength -  reduceSize - 1 COMMA_HERE).appendObjectsFromArray (executionList (i COMMA_HERE)) ;
          executionList (i COMMA_HERE).removeAllKeepingCapacity () ;
        }
        executionList (executionListLength - reduceSize - 1 COMMA_HERE).prependObject (actionCode) ;
        executionList.removeLastObjects (reduceSize COMMA_HERE) ; 
        executionList.appendDefaultObjectUsingSwap () ;
        const int32_t stackReduceSize = 2 * reduceSize ;
        for (int32_t i=0 ; i<stackReduceSize ; i++) {
          if (errorSignalingUselessEntryOnTopOfStack > 0) {
            errorSignalingUselessEntryOnTopOfStack -- ;
          }else{
            poppedErrors.appendObject (stack.lastObject (HERE)) ;
          }
          stack.removeLastObject (HERE) ;
        }
        if (produceSyntaxTree) {
          for (int32_t i=0 ; i<reduceSize ; i++) {
            syntaxTreeDescriptionString << "  NT" << cStringWithUnsigned (currentProductionName)
                                        << " -> " << shiftedElementStack.lastObject (HERE) << ";\n" ;
            shiftedElementStack.removeLastObject (HERE) ;
          }
        }
     //--- Get Successor state
        const int32_t tempCurrentState = stack.lastObject (HERE) ;
        MF_Assert (tempCurrentState >= 0, "tempCurrentState (%lld) < 0", tempCurrentState, 0) ;
        const int32_t * successorTable = inSuccessorTable [tempCurrentState] ;
        int32_t newCurrentState = -1 ; 
        while (((* successorTable) >= 0) && (newCurrentState < 0)) {
          if ((* successorTable) == nonTerminal) {
            successorTable ++ ;
            newCurrentState = (* successorTable) ;
          }
          successorTable ++ ;
          successorTable ++ ;
        }
        MF_Assert (newCurrentState >= 0, "newCurrentState (%lld) < 0", newCurrentState, 0) ;
        stack.appendObject (-1) ; // Enter any value
        stack.appendObject (newCurrentState) ; // Enter next current state
        errorSignalingUselessEntryOnTopOfStack += 2 ;
        if (produceSyntaxTree) {
          C_String uniqueProductionName ;
          uniqueProductionName << "NT" << cStringWithUnsigned (currentProductionName) ;
          syntaxTreeDescriptionString << "  " << uniqueProductionName
                                      << " [label=\"" << inNonTerminalSymbolNames [nonTerminal] << "\", shape=box];\n" ;
          shiftedElementStack.appendObject (uniqueProductionName) ;
          currentProductionName ++ ;
        }
        if (executionModeIsSyntaxAnalysisOnly ()) {
          co << "  [S" << cStringWithSigned (currentState) << ", " << getCurrentTokenString (tokenPtr)
             << "] |- Reduce "
             << inNonTerminalSymbolNames [nonTerminal]
             << " -> S"
             << cStringWithSigned (newCurrentState)
             << "\n" ;
        }
      }else if (actionCode == 1) {
      //--- Accept action -----------------------------------
        loop = false ;
        executionList (0 COMMA_HERE).appendObjectsFromArray (executionList (1 COMMA_HERE)) ;
        executionList (1 COMMA_HERE).removeAllKeepingCapacity () ;
        if (executionModeIsSyntaxAnalysisOnly ()) {
          co << "  [S" << cStringWithSigned (currentState) << ", " << getCurrentTokenString (tokenPtr) << "] : Accept\n" ;
        }
      }else{
      //--- Parsing error -----------------------------------
        result = false ;
        loop = false ;
      //--- Build error stack
        TC_Array <int32_t> actualErrorStack (stack.count () + poppedErrors.count () COMMA_HERE) ;
        for (int32_t i=0 ; i<(stack.count () - errorSignalingUselessEntryOnTopOfStack) ; i++) {
          actualErrorStack.appendObject (stack (i COMMA_HERE)) ;
        }
        for (int32_t i=poppedErrors.count () - 1 ; i>=0 ; i--) {
          actualErrorStack.appendObject (poppedErrors (i COMMA_HERE)) ;
        }
      //---
        TC_UniqueArray <int32_t> expectedTerminalsArray (100 COMMA_HERE) ;
        const int32_t currentErrorState = actualErrorStack.lastObject (HERE) ;
        actionTable = & (inActionTable [inActionTableIndex [currentErrorState]]) ;
        while ((* actionTable) >= 0) {
          const int32_t expectedTerminal = * actionTable ;
          actionTable += 1 ;
          const int32_t expectedAction = * actionTable ;
          actionTable += 1 ;
          const bool terminalAccepted = acceptExpectedTerminalForBottomUpParsingError (
            expectedTerminal,
            expectedAction,
            actualErrorStack,
            inActionTable,
            inActionTableIndex,
            inSuccessorTable,
            inProductionsTable
          ) ;
          if (terminalAccepted) {
            expectedTerminalsArray.appendObject (expectedTerminal) ;
          }
        }
        parsingError (expectedTerminalsArray, previousTokenPtr, tokenPtr, currentToken LINE_AND_SOURCE_FILE_FOR_LEXIQUE) ;
      }
    }
    if (result) {
      executionList (0 COMMA_HERE).copyTo (mArrayForSecondPassParsing) ;
    }
  //--- Output graphviz file
    if (produceSyntaxTree) {
      syntaxTreeDescriptionString << "}\n" ;
      const C_String dotFilePath = sourceFilePath ().stringByDeletingPathExtension () + ".dot" ;
      GALGAS_bool fileWritten ;
      GALGAS_string (syntaxTreeDescriptionString).method_writeToFileWhenDifferentContents (GALGAS_string (dotFilePath), fileWritten, this COMMA_HERE) ;
    }
    if (executionModeIsSyntaxAnalysisOnly ()) {
      co << "*** END OF PARSING (success: " << (result ? "yes" : "no") << ") ***\n" ;
    }
  //--- Set current read location to 0
    resetForSecondPass () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Second pass methods
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//                         Get next production index                                             
//
//----------------------------------------------------------------------------------------------------------------------

int32_t C_Lexique::nextProductionIndex (void) {
  int32_t result = 0 ;
  if (mIndexForSecondPassParsing < mArrayForSecondPassParsing.count ()) {
    result = mArrayForSecondPassParsing (mIndexForSecondPassParsing COMMA_HERE) ;
    mIndexForSecondPassParsing += 1 ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique::separatorString (void) const {
  C_String result ;
  if (mCurrentTokenPtr != nullptr) {
    result = mCurrentTokenPtr->mSeparatorStringBeforeToken ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique::tokenString (void) const {
  C_String result ;
  if (mCurrentTokenPtr != nullptr) {
    const int32_t tokenStart = mCurrentTokenPtr->mStartLocation.index () ;
    const int32_t tokenLength = mCurrentTokenPtr->mEndLocation.index () - tokenStart + 1 ;
    result = sourceText ().sourceString ().subString (tokenStart, tokenLength) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   Accept current token by shifting it                                                         
//
//----------------------------------------------------------------------------------------------------------------------

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define IN_EXPECTED_TERMINAL inExpectedTerminal
#else
  #define IN_EXPECTED_TERMINAL
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::acceptTerminal (const int32_t IN_EXPECTED_TERMINAL COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    int32_t currentTokenCode = 0 ;
  #endif
  if (mCurrentTokenPtr != nullptr) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      currentTokenCode = mCurrentTokenPtr->mTokenCode ;
    #endif
    mStartLocationForHere = mCurrentTokenPtr->mStartLocation ;
    mEndLocationForHere = mCurrentTokenPtr->mEndLocation ;
    mCurrentTokenPtr = mCurrentTokenPtr->mNextToken ;
    if (mCurrentTokenPtr != nullptr) {
      macroValidPointer (mCurrentTokenPtr) ;
      mStartLocationForNext = mCurrentTokenPtr->mStartLocation ;
      mEndLocationForNext = mCurrentTokenPtr->mEndLocation ;
      mTemplateString << mCurrentTokenPtr->mTemplateStringBeforeToken ;
      mTemplateStringLocation = mCurrentTokenPtr->mStartLocation ;
      mCurrentLocation = mCurrentTokenPtr->mEndLocation ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    if (currentTokenCode != inExpectedTerminal) {
      const C_String currentTokenString = getMessageForTerminal (currentTokenCode) ;
      const C_String expectedTokenString = getMessageForTerminal (inExpectedTerminal) ;
      MF_AssertThere (false,
                      "Internal second pass parsing error (current token:%s, expected token:%s)",
                      (intptr_t) currentTokenString.cString (HERE),
                      (intptr_t) expectedTokenString.cString (HERE)) ;
    }
  #endif
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::enterIndexing (const uint32_t inIndexingKind,
                               const char * inIndexedKeyPosfix) {
  if ((nullptr != mIndexingDictionary) && (sourceText ().sourceFilePath ().length () > 0)) {
    const uint32_t tokenStartLocation = (uint32_t) mCurrentTokenPtr->mStartLocation.index () ;
    const uint32_t tokenLine = (uint32_t) mCurrentTokenPtr->mStartLocation.lineNumber () ;
    const uint32_t tokenLength  = ((uint32_t) mCurrentTokenPtr->mEndLocation.index ()) - tokenStartLocation + 1 ;
    C_String indexedKey = sourceText ().sourceString ().subString ((int32_t) tokenStartLocation, (int32_t) tokenLength) + inIndexedKeyPosfix ;
    mIndexingDictionary->addIndexedKey (inIndexingKind,
                                        indexedKey,
                                        sourceText ().sourceFilePath (),
                                        tokenLine,
                                        tokenStartLocation,
                                        tokenLength) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::enableIndexing (void) {
  macroMyNew (mIndexingDictionary, cIndexingDictionary) ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::generateIndexFile (void) {
  if (nullptr != mIndexingDictionary) {
    mIndexingDictionary->generateIndexFile (indexingModeOutputFilePath ()) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Handling Parsing context
#endif

//----------------------------------------------------------------------------------------------------------------------

C_parsingContext C_Lexique::parsingContext (void) const {
  C_parsingContext context ;
  context.mParsingArrayIndex = mIndexForSecondPassParsing ;
  context.mLocation = mCurrentLocation ;
  context.mCurrentChar = mCurrentChar ;
  context.mPreviousChar = mPreviousChar ;
  context.mCurrentTokenPtr = mCurrentTokenPtr ;
  context.mTemplateString = mTemplateString ;
  return context ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::setParsingContext (const C_parsingContext & inContext) {
  mIndexForSecondPassParsing = inContext.mParsingArrayIndex ;
  mCurrentTokenPtr = inContext.mCurrentTokenPtr ;
  mCurrentLocation = inContext.mLocation ;
  mCurrentChar = inContext.mCurrentChar ;
  mPreviousChar = inContext.mPreviousChar ;
  mTemplateString = inContext.mTemplateString ;
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark For Debugging parser
#endif

//----------------------------------------------------------------------------------------------------------------------
//
//  For Debugging parser                                                                         
//
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::enterProduction (const char * inProductionName,
                                 const char * inLabel,
                                 const char * inTag) {
//--- If Debug is not running, check if trigger list contains non terminal 
  if (! mDebugIsRunning) {
    TC_UniqueArray <C_String> stringArray ;
    mTriggerNonTerminalSymbolList.componentsSeparatedByString (inProductionName, stringArray) ;
    mDebugIsRunning = stringArray.count () > 1 ;
  }
  if (mDebugIsRunning) {
    C_String message ;
    for (uint16_t i=1 ; i<mDebugDepthCounter ; i++) {
      message << "|  " ;
    }
    message << ((mDebugDepthCounter > 0) ? "|- " : "") << inProductionName ;
    if (inLabel != nullptr) {
      message << " label '" << inLabel << "'" ;
    }
    if ((inTag != nullptr) && (inTag [0] != '\0')) {
      message << " tag '" << inTag << "'" ;
    }
    message << "\n" ;
    ggs_printMessage (message COMMA_HERE) ;
    mDebugDepthCounter ++ ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::exitProduction (void) {
  if (mDebugIsRunning) {
    mDebugDepthCounter -- ;
    mDebugIsRunning = mDebugDepthCounter > 0 ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::didParseTerminal (const char * inTerminalName,
                                  const C_String & inValue) {
  if (mDebugIsRunning) {
    C_String message ;
    for (uint16_t i=1 ; i<mDebugDepthCounter ; i++) {
      message << "|  " ;
    }
    message << ((mDebugDepthCounter > 0) ? "|- " : "") << inTerminalName ;
    if (inValue.length () > 0) {
      message << inValue ;
    }
    message << "\n" ;
    ggs_printMessage (message COMMA_HERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark Generate Latex file
#endif

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::enterDroppedTerminal (const int32_t inTerminalIndex) {
  if (executionModeIsLatex ()) {
    while (mLatexNextCharacterToEnterIndex < mTokenStartLocation.index ()) {
      const utf32 c = sourceText ().readCharOrNul (mLatexNextCharacterToEnterIndex COMMA_HERE) ;
      appendCharacterToLatexFile (c) ;
      mLatexNextCharacterToEnterIndex += 1 ;
    }
    const C_String styleName = styleNameForIndex (styleIndexForTerminal (inTerminalIndex)) ;
    if (styleName.length () > 0) {
      mLatexOutputString << "\\" << styleName << latexModeStyleSuffixString () << "{" ;
    }
    for (int32_t i=mTokenStartLocation.index () ; i<=mTokenEndLocation.index () ; i++) {
      const utf32 c = sourceText ().readCharOrNul (i COMMA_HERE) ;
      if (UNICODE_VALUE (c) != '\0') {
        appendCharacterToLatexFile (c) ;
      }
    }
    if (styleName.length () > 0) {
      mLatexOutputString << "}" ;
    }
  //---
    mLatexNextCharacterToEnterIndex = mTokenEndLocation.index () + 1 ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::appendCharacterToLatexFile (const utf32 inUnicodeCharacter) {
  switch (UNICODE_VALUE (inUnicodeCharacter)) {
  case '>' : mLatexOutputString << "\\textgreater{}" ; break ;
  case '<' : mLatexOutputString << "\\textless{}" ; break ;
  case '~' : mLatexOutputString << "$\\sim$" ; break ;
  case '^' : mLatexOutputString << "$\\wedge$" ; break ;
  case '|' : mLatexOutputString << "\\textbar{}" ; break ;
  case '&' : mLatexOutputString << "\\&" ; break ;
  case '%' : mLatexOutputString << "\\%" ; break ;
  case '#' : mLatexOutputString << "\\#" ; break ;
  case '$' : mLatexOutputString << "\\$" ; break ;
//  case '`' : mLatexOutputString << "\\`{}" ; break ;
  case ' ' : mLatexOutputString << "\\hspace*{.6em}" ; break ;
  case '\n' : mLatexOutputString << "\\newline\n" ; break ;
  case '{' : mLatexOutputString << "\\{" ; break ;
  case '}' : mLatexOutputString << "\\}" ; break ;
  case '_' : mLatexOutputString << "\\_" ; break ;
  case '\\' : mLatexOutputString << "\\textbackslash{}"  ; break ;
  case '\'' : mLatexOutputString << "\\textquotesingle{}" ; break ;
//  case '"' : mLatexOutputString << "\\textquotedbl{}" ; break ;
  case '"' : mLatexOutputString << "\"" ; break ;
  default:
    mLatexOutputString.appendUnicodeCharacter (inUnicodeCharacter COMMA_HERE) ;
    mLatexOutputString << "{}" ;
    break ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::signalLexicalErrorInLatexOutput (void) {
  mLatexOutputString << "\\lexicalError" << latexModeStyleSuffixString () ;
}

//----------------------------------------------------------------------------------------------------------------------

void C_Lexique::generateLatexFile (void) {
  const C_String latexFilePath = sourceText ().sourceFilePath () + ".tex" ;
//--- Suppress last '\newline'
  const C_String newLine = "\\newline\n" ;
  if (mLatexOutputString.endsWithString (newLine)) {
    mLatexOutputString = mLatexOutputString.subString (0, mLatexOutputString.length () - newLine.length ()) ;
  }
  C_FileManager::writeStringToFile (mLatexOutputString, latexFilePath) ;
}

//----------------------------------------------------------------------------------------------------------------------
