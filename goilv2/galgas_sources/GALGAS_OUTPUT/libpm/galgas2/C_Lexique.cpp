//---------------------------------------------------------------------------*
//                                                                           *
//  'C_Lexique' : an abstract lexique class ;                                *
//  Galgas generated scanner classes inherit from this class.                *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 1996, ..., 2011 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
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

#include "galgas2/C_Lexique.h"
#include "galgas2/predefined-types.h"
#include "utilities/MF_MemoryControl.h"
#include "collections/TC_LinkedList.h"
#include "strings/unicode_character_cpp.h"
#include "strings/unicode_string_routines.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/cIndexingDictionary.h"
#include "files/C_FileManager.h"

//---------------------------------------------------------------------------*

#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <ctype.h>

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define LINE_AND_SOURCE_FILE , sourceText ()->sourceFilePath ().cString (HERE), lineNumber ()
#else
  #define LINE_AND_SOURCE_FILE 
#endif

//---------------------------------------------------------------------------*

cTemplateDelimiter::
cTemplateDelimiter (const utf32 * inStartString,
                    const PMSInt32 inStartStringLength,
                    const utf32 * inEndString,
                    const PMSInt32 inEndStringLength,
                    void (* inReplacementFunction) (C_Lexique & inLexique, const C_String & inElementString, C_String & ioTemplateString),
                    const bool inDiscardStartString) :
mStartString (inStartString),
mStartStringLength (inStartStringLength),
mEndString (inEndString),
mEndStringLength (inEndStringLength),
mReplacementFunction (inReplacementFunction),
mDiscardStartString (inDiscardStartString) {
}

//---------------------------------------------------------------------------*

cTemplateDelimiter::
cTemplateDelimiter (const cTemplateDelimiter & inOperand) :
mStartString (inOperand.mStartString),
mStartStringLength (inOperand.mStartStringLength),
mEndString (inOperand.mEndString),
mEndStringLength (inOperand.mEndStringLength),
mReplacementFunction (inOperand.mReplacementFunction),
mDiscardStartString (inOperand.mDiscardStartString) {
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Constructors, Destructor
#endif

//---------------------------------------------------------------------------*

C_Lexique::C_Lexique (C_Compiler * inCallerCompiler,
                      const C_String & inDependencyFileExtension,
                      const C_String & inDependencyFilePath,
                      const C_String & inSourceFileName
                      COMMA_LOCATION_ARGS) :
C_Compiler (inCallerCompiler, inDependencyFileExtension, inDependencyFilePath COMMA_THERE),
mIndexingDictionary (NULL),
mFirstToken (NULL),
mLastToken (NULL),
mCurrentTokenPtr (NULL),
mCurrentChar (TO_UNICODE ('\0')),
mPreviousChar (TO_UNICODE ('\0')),
mTokenStartLocation (),
mTokenEndLocation (),
mTriggerNonTerminalSymbolList (),
mDebugDepthCounter (0),
mDebugIsRunning (false),
mLoop (false),
mArrayForSecondPassParsing (),
mIndexForSecondPassParsing (0) {
//---
  if (inSourceFileName.length () > 0) {
    MF_Assert (UNICODE_VALUE (inSourceFileName (0 COMMA_HERE)) == '/',
               "*** SOURCE FILE PATH '%s' IS NOT ABSOLUTE ***\n",
               (PMSInt) inSourceFileName.cString (HERE),
               0) ;
    // printf ("*** '%s'\n", inSourceFileName.cString (HERE)) ;
    /* if (mCallerCompiler != NULL) {
      macroValidPointer (mCallerCompiler) ;
      mCallerCompiler->addDependancyInputFilePath (inSourceFileName) ;
    } */
    logFileRead (inSourceFileName) ;
    bool ok = false ;
    PMTextFileEncoding textFileEncoding ;
    const C_String sourceString = C_FileManager::stringWithContentOfFile (inSourceFileName, textFileEncoding, ok) ;
    if (ok) {
      C_SourceTextInString * sourceTextPtr = NULL ;    
      macroMyNew (sourceTextPtr, C_SourceTextInString (sourceString,
                                                       inSourceFileName,
                                                       false // Do not print source string
                                                       COMMA_HERE)) ;
      resetAndLoadSourceFromText (sourceTextPtr) ;
      mTokenStartLocation.resetWithSourceText (sourceTextPtr) ;
      mTokenEndLocation.resetWithSourceText (sourceTextPtr) ;
      macroDetachSharedObject (sourceTextPtr) ;
    }else if (inCallerCompiler != NULL) {
      C_String errorMessage ; 
      errorMessage << "cannot read '" << inSourceFileName << "': this file does not exist or is not encoded in UTF8" ;
      inCallerCompiler->onTheFlyRunTimeError (errorMessage COMMA_THERE)  ;
    }
  }
  mCurrentChar = (sourceText () == NULL) ? TO_UNICODE ('\0') : sourceText ()->readCharOrNul (0 COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

C_Lexique::C_Lexique (C_Compiler * inCallerCompiler,
                      const C_String & inSourceString,
                      const C_String & inStringForError
                      COMMA_LOCATION_ARGS) :
C_Compiler (inCallerCompiler, "", "" COMMA_THERE),
mIndexingDictionary (NULL),
mFirstToken (NULL),
mLastToken (NULL),
mCurrentTokenPtr (NULL),
mCurrentChar (TO_UNICODE ('\0')),
mPreviousChar (TO_UNICODE ('\0')),
mTokenStartLocation (),
mTokenEndLocation (),
mTriggerNonTerminalSymbolList (),
mDebugDepthCounter (0),
mDebugIsRunning (false),
mLoop (false),
mArrayForSecondPassParsing (),
mIndexForSecondPassParsing (0) {
//--- Init source string
  C_SourceTextInString * sourceTextPtr = NULL ;    
  macroMyNew (sourceTextPtr, C_SourceTextInString (inSourceString,
                                                   inStringForError,
                                                   gOption_galgas_5F_cli_5F_options_verbose_5F_output.mValue
                                                   COMMA_HERE)) ;
  resetAndLoadSourceFromText (sourceTextPtr) ;
  mTokenStartLocation.resetWithSourceText (sourceTextPtr) ;
  mTokenEndLocation.resetWithSourceText (sourceTextPtr) ;
  macroDetachSharedObject (sourceTextPtr) ;
  mCurrentChar = (sourceText () == NULL) ? TO_UNICODE ('\0') : sourceText ()->readCharOrNul (0 COMMA_HERE) ;
}

//---------------------------------------------------------------------------*

C_Lexique::~C_Lexique (void) {
  macroMyDelete (mIndexingDictionary) ;
  mLastToken = NULL ;
  mCurrentTokenPtr = NULL ;
  while (mFirstToken != NULL) {
    cToken * p = mFirstToken->mNextToken ;
    macroMyDelete (mFirstToken) ;
    mFirstToken = p ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Scanner configuration
#endif

//---------------------------------------------------------------------------*

void C_Lexique::enterTokenFromPointer (cToken * inToken) {
  macroValidPointer (inToken) ;
  if (mLastToken == NULL) {
    mFirstToken = inToken ;
  }else{
    mLastToken->mNextToken = inToken ;
  }
  mLastToken = inToken ;
  if (executionModeIsLexicalAnalysisOnly ()) {
    C_String s ;
    for (PMSInt32 i=inToken->mStartLocation.index () ; i<=inToken->mEndLocation.index () ; i++) {
      const utf32 c = ((sourceText () == NULL) ? TO_UNICODE ('\0') : sourceText ()->readCharOrNul (i COMMA_HERE)) ;
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
       << ", column " << cStringWithSigned (inToken->mEndLocation.columnNumber ()) << ")"
       << " \"" << s << "\"" ;
    if (inToken->mTemplateStringBeforeToken.length () > 0) {
      co << ", template '" << inToken->mTemplateStringBeforeToken << "'" ;
    }
    co << "\n" ;
  }
}

//---------------------------------------------------------------------------*

void C_Lexique::resetForSecondPass (void) {
  mCurrentLocation.resetWithSourceText (sourceText ()) ;
  mCurrentChar = (sourceText () == NULL) ? TO_UNICODE ('\0') : sourceText ()->readCharOrNul (0 COMMA_HERE) ;
  mPreviousChar = TO_UNICODE ('\0') ;
  mCurrentTokenPtr = mFirstToken ;
  if (mCurrentTokenPtr != NULL) {
    mTemplateString << mCurrentTokenPtr->mTemplateStringBeforeToken ;
    mCurrentLocation = mCurrentTokenPtr->mEndLocation ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Template Delimiter Scanning
#endif

//---------------------------------------------------------------------------*

PMSInt32 C_Lexique::findTemplateDelimiterIndex (const cTemplateDelimiter inTemplateDelimiterArray [],
                                                const PMSInt32 inTemplateDelimiterArrayLength) {
  PMSInt32 templateIndex = 0 ;
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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Lexical Analysis
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   performLexicalAnalysis                                                  *
//                                                                           *
//---------------------------------------------------------------------------*

void C_Lexique::performLexicalAnalysis (void) {
  if (executionModeIsLexicalAnalysisOnly ()) {
    co << "*** PERFORM LEXICAL ANALYSIS ONLY (--mode=lexical-analysis option) ***\n" ;
  }
  bool loop = true ;
  while (loop) {
    loop = parseLexicalToken () ;
  }
  if (executionModeIsLexicalAnalysisOnly ()) {
    co << "*** END OF LEXICAL ANALYSIS ***\n" ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Methods for scanning                                               *
//                                                                           *
//---------------------------------------------------------------------------*

void C_Lexique::advance (void) {
 // printf ("START ADVANCE\n") ;
  mTokenEndLocation = mCurrentLocation ;
  mPreviousChar = mCurrentChar ;
  if (UNICODE_VALUE (mCurrentChar) != '\0') {
    mCurrentLocation.gotoNextLocation (UNICODE_VALUE (mPreviousChar) == '\n') ;
    if (sourceText () == NULL) {
      mCurrentChar = TO_UNICODE ('\0') ;
    }else{
      mCurrentChar = sourceText ()->readCharOrNul (mCurrentLocation.index () COMMA_HERE) ;
    }
  }
  // printf ("END ADVANCE\n") ;
}

//---------------------------------------------------------------------------*

void C_Lexique::advance (const PMSInt32 inCount) {
  for (PMSInt32 i=0 ; i<inCount ; i++) {
    advance () ;
  }
}

//---------------------------------------------------------------------------*

bool C_Lexique::testForInputUTF32CharRange (const utf32 inLowBound,
                                            const utf32 inHighBound) {
  const bool ok = (UNICODE_VALUE (inLowBound) <= UNICODE_VALUE (mCurrentChar))
     && (UNICODE_VALUE (mCurrentChar) <= UNICODE_VALUE (inHighBound)) ;
  if (ok) {
    advance () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*

bool C_Lexique::testForInputUTF32Char (const utf32 inChar) {
  const bool ok = UNICODE_VALUE (inChar) == UNICODE_VALUE (mCurrentChar) ;
  if (ok) {
    advance () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*

bool C_Lexique::testForCharWithFunction (bool (*inFunction) (const utf32 inUnicodeCharacter)) {
  const bool ok = inFunction (mCurrentChar) ;
  if (ok) {
    advance () ;
  }
  return ok ;
}

//---------------------------------------------------------------------------*

bool C_Lexique::testForInputUTF32String (const utf32 * inTestCstring,
                                         const PMSInt32 inStringLength,
                                         const bool inAdvanceOnMatch) {
  bool ok = sourceText () != NULL ;
//--- Test
  if (ok) {
    ok = utf32_strncmp (sourceText ()->temporaryUTF32StringAtIndex (mCurrentLocation.index (), inStringLength COMMA_HERE),
                        inTestCstring,
                        inStringLength) == 0 ;
  }
//--- Avancer dans la lecture si test ok et fin de source non atteinte
  if (ok && inAdvanceOnMatch) {
    advance (inStringLength) ;
  }
//---
  return ok ;
}

//---------------------------------------------------------------------------*

bool C_Lexique::notTestForInputUTF32String (const utf32 * inTestCstring,
                                            const PMSInt32 inStringLength,
                                            const utf32 * inEndOfFileErrorMessage
                                            COMMA_LOCATION_ARGS) {
  bool ok = UNICODE_VALUE (sourceText ()->readCharOrNul (mCurrentLocation.index () COMMA_HERE)) != '\0' ;
  if (! ok) { // End of input file reached
    lexicalError (inEndOfFileErrorMessage COMMA_THERE) ;
  }else{
  //--- Test
    ok = false ;
    for (PMSInt32 i=0 ; (i<inStringLength) && ! ok ; i++) {
      ok = UNICODE_VALUE (sourceText ()->readCharOrNul (mCurrentLocation.index () + i COMMA_HERE)) != UNICODE_VALUE (* inTestCstring) ;
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

//---------------------------------------------------------------------------*

void C_Lexique::lexicalLog (LOCATION_ARGS) {
  C_String message ;
  message << "LEXICAL LOG:'" ;
  message.appendCLiteralCharConstant (mCurrentChar) ;
  message << "'\n" ;
  printMessage (message COMMA_THERE) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     Search in an ordered list                             *
//          (used for searching into scanner generated tables)               *
//                                                                           *
//---------------------------------------------------------------------------*

PMSInt16 C_Lexique::searchInList (const C_String & inString,
                                  const C_unicode_lexique_table_entry inTable [],
                                  const PMSInt16 inTableSize) {
  const PMSInt32 searchedStringLength = inString.length () ;
  PMSInt16 code = -1 ; // -1 means 'not found'
  PMSInt32 bottom = 0 ;
  PMSInt32 top = inTableSize - 1 ;
  
  while ((code < 0) && (top >= bottom)) {
    const PMSInt32 index = (bottom + top) / 2 ;
    PMSInt32 result = searchedStringLength - inTable [index].mEntryStringLength ;
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

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Handling an error
#endif

//---------------------------------------------------------------------------*

void C_Lexique::internalBottomUpParserError (LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    printf ("*** Fatal error: Internal bottom-up parser error at line %d of file '%s'.\n", IN_SOURCE_LINE, IN_SOURCE_FILE) ;
  #else
    printf ("*** Fatal error: Internal bottom-up parser error.\n") ;
  #endif
  exit (1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//           Lexical error                                                   *
//                                                                           *
//---------------------------------------------------------------------------*

void C_Lexique::unknownCharacterLexicalError (LOCATION_ARGS) {
  C_String errorMessage ;
  errorMessage << "Unknown character: " << unicodeName (mCurrentChar) ;
  lexicalError (errorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

void C_Lexique::lexicalError (const C_String & inLexicalErrorMessage
                              COMMA_LOCATION_ARGS) {
  signalLexicalError (sourceText (),
                      currentLocationInSource (),
                      inLexicalErrorMessage
                      COMMA_THERE) ;
  throw C_lexicalErrorException () ;
}

//---------------------------------------------------------------------------*

void C_Lexique::lexicalErrorAtLocation (const C_String & inLexicalErrorMessage,
                                        const C_LocationInSource & inErrorLocation
                                        COMMA_LOCATION_ARGS) {
  signalLexicalError (sourceText (),
                      inErrorLocation,
                      inLexicalErrorMessage
                      COMMA_THERE) ;
  throw C_lexicalErrorException () ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                Signaler une erreur syntaxique                             *
//                                                                           *
//---------------------------------------------------------------------------*

void C_Lexique::parsingError (const TC_UniqueArray <PMSInt16> & inExpectedTerminalsArray,
                              const PMSInt16 inCurrentTokenCode
                              COMMA_LOCATION_ARGS) {
//--- Build error message
  C_String foundTokenMessage ;
  appendTerminalMessageToSyntaxErrorMessage (inCurrentTokenCode, foundTokenMessage) ;
  const PMSInt32 expectedTerminalsCount = inExpectedTerminalsArray.count () ;
  TC_UniqueArray <C_String> expectedTokenNames (expectedTerminalsCount, C_String () COMMA_HERE) ;
  for (PMSInt32 i=0 ; i<expectedTerminalsCount ; i++) {
    appendTerminalMessageToSyntaxErrorMessage (inExpectedTerminalsArray (i COMMA_HERE), expectedTokenNames (i COMMA_HERE)) ;
  }
//--- Sort expected token name array
  expectedTokenNames.sortArrayUsingCompareMethod () ;
//--- Signal error
  signalParsingError (sourceText (),
                      mCurrentLocation,
                      foundTokenMessage,
                      expectedTokenNames
                      COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Scanner warning
#endif

//---------------------------------------------------------------------------*

void C_Lexique::lexicalWarning (const C_String & inLexicalWarningMessage
                                COMMA_LOCATION_ARGS) {
  signalLexicalWarning (sourceText (),
                        mCurrentLocation,
                        inLexicalWarningMessage
                        COMMA_THERE) ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Top-down parsing
#endif

//---------------------------------------------------------------------------*

//#define TRACE_LL1_PARSING

//---------------------------------------------------------------------------*
//                                                                           *
//   Test if a terminal symbol can be accepted in current context            *
//                                                                           *
//---------------------------------------------------------------------------*

bool C_Lexique::acceptTerminalForErrorSignaling (const PMSInt16 inTerminal,
                                                 const PMSInt16 inProductions [],
                                                 const PMSInt16 inProductionIndexes [],
                                                 const PMSInt16 inFirstProductionIndex [],
                                                 const PMSInt16 inDecisionTable [],
                                                 const PMSInt16 inDecisionTableIndexes [],
                                                 const TC_Array <PMSInt16> & inErrorStack,
                                                 const PMSInt16 inErrorProgramCounter) {
  #ifdef TRACE_LL1_PARSING
    C_String m ;
    appendTerminalMessageToSyntaxErrorMessage (inTerminal, m) ;
    co << "------ Enter 'acceptTerminalForErrorSignaling' with '"
       << m
       << "' ("
       << inTerminal
       << ") terminal and program counter "
       << inErrorProgramCounter ;
    co.flush () ;
  #endif
  bool accept = false ;
  PMSInt16 programCounter = inErrorProgramCounter ;
  TC_Array <PMSInt16> stack = inErrorStack ;
  bool loop = true ;
  while (loop) {
    const PMSInt16 instruction = inProductions [programCounter] ;
    programCounter ++ ;
    if (instruction > 0) { // We reach a terminal
      const PMSInt16 reachedTerminal = (PMSInt16) (instruction - 1) ;
      accept = reachedTerminal == inTerminal ;
      #ifdef TRACE_LL1_PARSING
        m.removeAllObjects () ;
        appendTerminalMessageToSyntaxErrorMessage (reachedTerminal, m) ;
        co << "reached '"
           << m
           << "' terminal"
           << (accept ? " (accepted)" : "")
           << "\n" ;
        co.flush () ;
      #endif
      loop = false ;
    }else if (instruction < 0) { // We reach a nonterminal
      const PMSInt16 reachedNonterminal = (PMSInt16) (- instruction - 1) ;
      #ifdef TRACE_LL1_PARSING
        co << "reached non-terminal "
           << reachedNonterminal
           << "\n" ;
        co.flush () ;
      #endif
      PMSInt16 nonTerminalEntry = inDecisionTableIndexes [reachedNonterminal] ;
      if (inDecisionTable [nonTerminalEntry] < 0) { // Only one rule : call it
        stack.addObject (programCounter) ;
        programCounter = inProductionIndexes [inFirstProductionIndex [reachedNonterminal]] ;
        #ifdef TRACE_LL1_PARSING
          co << "One rule: goto " << programCounter << "\n" ; co.flush () ;
        #endif
      }else{ // More than one rule : test if terminal is accepted, and call rule
        loop = false ;
        PMSInt16 choice = 0 ;
        bool found = false ;
        while ((inDecisionTable [nonTerminalEntry] >= 0) && ! found) {
          while ((inDecisionTable [nonTerminalEntry] >= 0) && ! found) {
            found = inDecisionTable [nonTerminalEntry] == inTerminal ;
            #ifdef TRACE_LL1_PARSING
              m.removeAllObjects () ;
              appendTerminalMessageToSyntaxErrorMessage (inDecisionTable [nonTerminalEntry], m) ;
              co << "try '" << m << "' non terminal" << (found ? " (accepted)": "") << "\n" ; co.flush () ;
            #endif
            if (found) {
              PMSInt16 newProgramCounter = programCounter ;
              TC_Array <PMSInt16> newStack = stack ;
              newStack.addObject (newProgramCounter) ;
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
  #ifdef TRACE_LL1_PARSING
    co << "------ Exit 'acceptTerminalForErrorSignaling' with accept == " << (accept ? "true" : "false") << "\n" ;
  #endif
  return accept ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   Build expected terminals array on syntax error with LL (1) parser       *
//                                                                           *
//---------------------------------------------------------------------------*

void C_Lexique::buildExpectedTerminalsArrayOnSyntaxError (const PMSInt16 inErrorProgramCounter,
                                                          const PMSInt32 inErrorStackCount,
                                                          const TC_Array <PMSInt16> & inStack,
                                                          const TC_Array <PMSInt16> & inErrorStack,
                                                          const PMSInt16 inProductions [],
                                                          const PMSInt16 inProductionIndexes [],
                                                          const PMSInt16 inFirstProductionIndex [],
                                                          const PMSInt16 inDecisionTable [],
                                                          const PMSInt16 inDecisionTableIndexes [],
                                                          TC_UniqueArray <PMSInt16> & outExpectedTerminalsArray) {
//--- First, go to the next non terminal, terminal or end of productions rules
  PMSInt16 programCounter = inErrorProgramCounter ;
  const PMSInt32 countToCopy = inErrorStackCount - inErrorStack.count () ;
  TC_Array <PMSInt16> errorStack (inErrorStackCount COMMA_HERE) ;
  for (PMSInt32 i=0 ; i<countToCopy ; i++) {
    errorStack.addObject (inStack (i COMMA_HERE)) ;
  }
  for (PMSInt32 i=inErrorStack.count () - 1 ; i>=0 ; i--) {
    errorStack.addObject (inErrorStack (i COMMA_HERE)) ;
  }
  #ifdef TRACE_LL1_PARSING
    co << "------ Enter 'buildExpectedTerminalsArrayOnSyntaxError'\n"
       << "programCounter: " << programCounter << ", errorStack: " << errorStack.count() << " value(s):" ;
    for (PMSInt32 i=0 ; i<errorStack.count() ; i++) {
      co << " " << errorStack (i COMMA_HERE) ;
    }
    co << "\n" ;
    co.flush () ;
  #endif
  bool loop = true ;
  while (loop) {
    if (inProductions [programCounter] > 0) { // We reach a terminal (when >0)
      loop = false ;
      #ifdef TRACE_LL1_PARSING
        C_String m ;
        appendTerminalMessageToSyntaxErrorMessage (inProductions [programCounter], m) ;
        co << "Terminal '" << m << "' (" << inProductions [programCounter] << ") reached\n" ;
        co.flush () ;
      #endif
    }else if (inProductions [programCounter] < 0) { // We reach a non terminal (<0)
      const PMSInt16 nonTerminal = (PMSInt16) (- inProductions [programCounter] - 1) ;
      #ifdef TRACE_LL1_PARSING
        co << "Non-Terminal " << nonTerminal << " reached\n" ;
        co.flush () ;
      #endif
    //--- We look if we get a non terminal that has only one production rule
      const PMSInt16 nonTerminalEntry = inDecisionTableIndexes [nonTerminal] ;
      const bool onlyOneRule = inDecisionTable [nonTerminalEntry] < 0 ;
      if (onlyOneRule) { // Go to this rule
        errorStack.addObject ((PMSInt16) (programCounter + 1)) ;
        programCounter = inProductionIndexes [inFirstProductionIndex [nonTerminal]] ;
        #ifdef TRACE_LL1_PARSING
          co << "Only one rule: goto " << programCounter << "\n" ;
          co.flush () ;
        #endif
      }else{
        loop = false ; // Stop searching
      }
    }else if (errorStack.count () > 0) { // Execute a 'return' instruction
      programCounter = errorStack.lastObject (HERE) ;
      errorStack.removeLastObject (HERE) ;
      #ifdef TRACE_LL1_PARSING
        co << "return instruction (goes to " << programCounter << ")\n" ;
        co.flush () ;
      #endif
    }else{ // End of source reached
      #ifdef TRACE_LL1_PARSING
        co << "end of source reached\n" ;
        co.flush () ;
      #endif
      loop = false ;
    }
  }
//--- Decision for build expected terminals array
  if (errorStack.count () == 0) { // We reach end of productions rules
    outExpectedTerminalsArray.addObject (0) ; // 0 is always "end_of_text" terminal symbol
    #ifdef TRACE_LL1_PARSING
      co << "add 'end of source' to outExpectedTerminalsArray\n" ;
      co.flush () ;
    #endif
  }else if (inProductions [programCounter] > 0) { // We reach a terminal symbol
    const PMSInt16 terminalSymbol = (PMSInt16) (inProductions [programCounter] - 1) ;
    outExpectedTerminalsArray.addObject (terminalSymbol) ;
    #ifdef TRACE_LL1_PARSING
      C_String m ;
      appendTerminalMessageToSyntaxErrorMessage (inProductions [programCounter], m) ;
      co << "add '" << m << "' (" << inProductions [programCounter] << ") to outExpectedTerminalsArray\n" ;
      co.flush () ;
    #endif
  }else{  // We reach a non terminal symbol
    const PMSInt16 nonTerminal = (PMSInt16) (- inProductions [programCounter] - 1) ;
    PMSInt16 nonTerminalEntry = inDecisionTableIndexes [nonTerminal] ;
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
          #ifdef TRACE_LL1_PARSING
            C_String m ;
            appendTerminalMessageToSyntaxErrorMessage (inDecisionTable [nonTerminalEntry], m) ;
            co << "add '" << m << "' (" << inDecisionTable [nonTerminalEntry] << ") to outExpectedTerminalsArray\n" ;
            co.flush () ;
          #endif
          outExpectedTerminalsArray.addObject (inDecisionTable [nonTerminalEntry]) ;
        }
        nonTerminalEntry ++ ;
      }
      nonTerminalEntry ++ ;  
    }
  }
  #ifdef TRACE_LL1_PARSING
    co << "------ Exit 'buildExpectedTerminalsArrayOnSyntaxError'\n" ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//   Perform top down parsing (called by LL (1) parser)                      *
//                                                                           *
//---------------------------------------------------------------------------*

static void indentForParseOnly (const PMSInt32 inIndentation) {
  for (PMSInt32 i=1 ; i<inIndentation ; i++) {
    co << "|  " ;
  }
  if (inIndentation > 0) {
    co << "|- " ;
  }
}

//---------------------------------------------------------------------------*

bool C_Lexique::performTopDownParsing (const PMSInt16 inProductions [],
                                       const cProductionNameDescriptor inProductionNames [],
                                       const PMSInt16 inProductionIndexes [],
                                       const PMSInt16 inFirstProductionIndex [],
                                       const PMSInt16 inDecisionTable [],
                                       const PMSInt16 inDecisionTableIndexes [],
                                       const PMSInt16 inProgramCounterInitialValue) {
  bool result = false ;
//--- Lexical analysis
  performLexicalAnalysis () ;
  if (! executionModeIsLexicalAnalysisOnly ()) {
  //--- Variables for generating syntax tree in a form suitable for graphviz
    const bool produceSyntaxTree = gOption_galgas_5F_cli_5F_options_outputConcreteSyntaxTree.mValue ;
    C_String syntaxTreeDescriptionString ;
    TC_Array <PMUInt32> productionUniqueNameStack ;
    PMUInt32 uniqueProductionNameIndex = 0 ;
    PMUInt32 uniqueTerminalIndex = 0 ;
    PMUInt32 currentProductionName = 0 ;
    if (produceSyntaxTree) {
      syntaxTreeDescriptionString << "digraph G {\n"
                                     "  size =\"4,4\";\n" ;
    }
  //---
    PMSInt32 indentationForParseOnly = 0 ;
    cToken * currentTokenPtr = mFirstToken ;
    if (executionModeIsSyntaxAnalysisOnly ()) {
      co << "*** PERFORM TOP-DOWN PARSING ONLY (--mode=syntax-only option) ***\n" ;
    }
    TC_LinkedList <PMSInt16> listForSecondPassParsing ;
    TC_Array <PMSInt16> stack (10000 COMMA_HERE) ;
    TC_Array <PMSInt16> errorStack ;
    PMSInt32 errorStackCount = 0 ;
    bool loop = currentTokenPtr != NULL ;
    result = true ;
    PMSInt16 programCounter = inProgramCounterInitialValue ;
    PMSInt16 errorProgramCounter = inProgramCounterInitialValue ;
    PMSInt16 currentToken = (currentTokenPtr != NULL) ? currentTokenPtr->mTokenCode : ((PMSInt16) -1) ;
    if (currentTokenPtr == NULL) {
      mCurrentLocation.resetLocation () ;
   }else{
      mCurrentLocation = currentTokenPtr->mEndLocation ;
    }
    while (loop) {
    //--- If no current token, get one
      if (currentToken < 0) {
        if (currentTokenPtr == NULL) {
          currentToken = 0 ; // 0 means end of source file
        }else{
          currentTokenPtr = currentTokenPtr->mNextToken ;
          currentToken = (currentTokenPtr != NULL) ? currentTokenPtr->mTokenCode : ((PMSInt16) 0) ;
          if (currentTokenPtr != NULL) {
            mCurrentLocation = currentTokenPtr->mEndLocation ;
          }
        }
      }
      #ifdef TRACE_LL1_PARSING
        co << "---------------------------\n"
              "Current token is " << getCurrentTokenString (currentTokenPtr) << " (#" << currentToken << ")\n" ;
        co.flush () ;
      #endif
    //--- Get instruction to do
      const PMSInt16 instruction = inProductions [programCounter] ;
      programCounter ++ ;
    //--- Instruction is non terminal call ?
      if (instruction < 0) {
      //--- Get entry of nonterminal symbol to parse
        const PMSInt16 nonTerminalToParse = (PMSInt16) (- instruction - 1) ;
        #ifdef TRACE_LL1_PARSING
          co << "Parse non terminal " << cStringWithSigned (nonTerminalToParse) << ": " ;
          co.flush () ;
        #endif
        PMSInt16 nonTerminalEntry = inDecisionTableIndexes [nonTerminalToParse] ;
        if (inDecisionTable [nonTerminalEntry] < 0) { // Means only one production : don't make any choice
          #ifdef TRACE_LL1_PARSING
            co << " ok (only one production)\n" ;
            co.flush () ;
          #endif
          stack.addObject (programCounter) ;
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
            productionUniqueNameStack.addObject (currentProductionName) ;
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
          #ifdef TRACE_LL1_PARSING
            co << " try tokens\n" ; co.flush () ;
          #endif
          PMSInt16 choice = -1 ;
          bool found = false ;
          while ((inDecisionTable [nonTerminalEntry] >= 0) && ! found) {
            while ((inDecisionTable [nonTerminalEntry] >= 0) && ! found) {
              found = currentToken == inDecisionTable [nonTerminalEntry] ;
              #ifdef TRACE_LL1_PARSING
                C_String m ;
                appendTerminalMessageToSyntaxErrorMessage (inDecisionTable [nonTerminalEntry], m) ;
                co << " try " << m << " (" << inDecisionTable [nonTerminalEntry]
                   << ")" << (found ? " (accepted)" : "") << "\n" ;
                co.flush () ;
              #endif
              nonTerminalEntry ++ ;
            }
            choice ++ ;
            nonTerminalEntry ++ ;  
          }
        //--- Found : call production rule
          if (found) {
            stack.addObject (programCounter) ;
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
              productionUniqueNameStack.addObject (currentProductionName) ;
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
            listForSecondPassParsing.insertAtBottom ((PMSInt16) (choice + 1)) ;
          }else{ // Syntax error
            TC_UniqueArray <PMSInt16> expectedTerminalsArray (100 COMMA_HERE) ;
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
            #ifdef TRACE_LL1_PARSING
              co << expectedTerminalsArray.count () << " Token(s) in syntax error message\n" ; co.flush () ;
            #endif
            parsingError (expectedTerminalsArray, currentToken LINE_AND_SOURCE_FILE) ;
            result = loop = false ;
            listForSecondPassParsing.makeListEmpty () ;
          }
        }
    //--- It is a terminal symbol
      }else if (instruction > 0) {
        const PMSInt16 terminalSymbol = (PMSInt16) (instruction - 1) ;
        if (currentToken == terminalSymbol) {
          if (executionModeIsSyntaxAnalysisOnly ()) {
            indentForParseOnly (indentationForParseOnly) ;
            co << getCurrentTokenString (currentTokenPtr) << "\n" ;
          }
          currentToken = -1 ; // Ok, current terminal symbol is no longer available
          if (produceSyntaxTree) {
            syntaxTreeDescriptionString << "  T" << cStringWithUnsigned (uniqueTerminalIndex) << " [shape=ellipse, label=" ;
            syntaxTreeDescriptionString.appendCLiteralStringConstant (getCurrentTokenString (currentTokenPtr)) ;
            syntaxTreeDescriptionString << "];\n"
                                        << "  NT"
                                        << cStringWithUnsigned (currentProductionName)
                                        << " -> T"
                                        << cStringWithUnsigned (uniqueTerminalIndex)
                                        << ";\n" ;
            uniqueTerminalIndex ++ ;
          }
          errorStackCount = stack.count () ;
          errorStack.setCountToZero () ;
          errorProgramCounter = programCounter ;
        }else{ // Error !
          #ifdef TRACE_LL1_PARSING
            co << "ERROR: TOKEN NOT EXPECTED\n" ; co.flush () ;
          #endif
          TC_UniqueArray <PMSInt16> expectedTerminalsArray (100 COMMA_HERE) ;
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
          parsingError (expectedTerminalsArray, currentToken LINE_AND_SOURCE_FILE) ;
          result = loop = false ;
          listForSecondPassParsing.makeListEmpty () ;
        }
    //--- It is the end of a production    
      }else if (stack.count () > 0) {
        #ifdef TRACE_LL1_PARSING
          co << "END OF PRODUCTION REACHED\n" ; co.flush () ;
        #endif
        programCounter = stack.lastObject (HERE) ;
        if (errorStackCount >= stack.count ()) {
          errorStack.addObject (programCounter) ;
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
        TC_UniqueArray <PMSInt16> expectedTerminalsArray (100 COMMA_HERE) ;
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
        parsingError (expectedTerminalsArray, currentToken LINE_AND_SOURCE_FILE) ;
        result = loop = false ;
        listForSecondPassParsing.makeListEmpty () ;
      }
    }
  //--- Output graphviz file
    if (produceSyntaxTree) {
      syntaxTreeDescriptionString << "}\n" ;
      const C_String filePath = sourceFilePath ().stringByDeletingPathExtension () + ".dot" ;
      // printf ("filePath: '%s'\n", filePath.cString (HERE)) ;
      GALGAS_bool fileWritten ;
      GALGAS_string (syntaxTreeDescriptionString).method_writeToFileWhenDifferentContents (GALGAS_string (filePath), fileWritten, this COMMA_HERE) ;
    }
  //--- Set current read location to 0
    listForSecondPassParsing.copyIntoArray (mArrayForSecondPassParsing) ;
    resetForSecondPass () ;
    if (executionModeIsSyntaxAnalysisOnly ()) {
      co << "*** END OF PARSING (success: "
         << (result ? "yes" : "no")
         << ") ***\n" ;
    }
    // printf ("stack capacity: %u, %u %d\n", stack.capacity (), errorStack.capacity (), mArrayForSecondPassParsing.count ()) ;
  }
//---
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Bottom up parsing
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//   Test if a given terminal symbol can be accepted for signaling an error  *
//          (for bottom-up parsing)                                          *
//                                                                           *
//---------------------------------------------------------------------------*

static bool acceptExpectedTerminalForBottomUpParsingError (const PMSInt16 inExpectedTerminal,
                                                           const PMSInt16 inExpectedAction,
                                                           const TC_Array <PMSInt16> & inSLRstack,
                                                           const PMSInt16 inActionTable [],
                                                           const PMUInt32 inActionTableIndex [],
                                                           const PMSInt16 * inSuccessorTable [],
                                                           const PMSInt16 inProductionsTable []) {
  bool accept = inExpectedAction > 1 ; // accept if it is a shift action
  if (! accept) {
    PMSInt16 actionCode = inExpectedAction ;
    TC_Array <PMSInt16> stack (inSLRstack) ; // Duplicate stack
    bool loop = true ;
    while (loop) {
    //--- Perform reduce action
      const PMSInt16 reduceAction = (PMSInt16) (- actionCode - 1) ;
      MF_Assert (reduceAction >= 0, "reduceAction (%lld) < 0", reduceAction, 0) ;
      const PMSInt16 nonTerminal = inProductionsTable [2 * reduceAction] ;
      const PMSInt32 reduceSize = inProductionsTable [2 * reduceAction + 1] ;
      stack.removeLastObjects (2 * reduceSize  COMMA_HERE) ;
   //--- Get Successor state
      const PMSInt32 tempCurrentState = stack.lastObject (HERE) ;
      MF_Assert (tempCurrentState >= 0, "tempCurrentState (%lld) < 0", tempCurrentState, 0) ;
      const PMSInt16 * successorTable = inSuccessorTable [tempCurrentState] ;
      PMSInt16 newCurrentState = -1 ; 
      while (((* successorTable) >= 0) && (newCurrentState < 0)) {
        if ((* successorTable) == nonTerminal) {
          successorTable ++ ;
          newCurrentState = (* successorTable) ;
        }
        successorTable ++ ;
        successorTable ++ ;
      }
      MF_Assert (newCurrentState >= 0, "newCurrentState (%lld) < 0", newCurrentState, 0) ;
      stack.addObject (-1) ; // Enter any value
      stack.addObject (newCurrentState) ; // Enter next current state
    //--- In the state, find action corresponding to expected terminal
      const PMSInt32 currentState = stack (stack.count () - 1 COMMA_HERE) ;
      MF_Assert (currentState >= 0, "currentState (%lld) < 0", currentState, 0) ;
      const PMSInt16 * actionTable = & (inActionTable [inActionTableIndex [currentState]]) ;
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

//---------------------------------------------------------------------------*
//                                                                           *
//   Perform bottom up parsing (called by SLR and LR (1) parsers)            *
//                                                                           *
//---------------------------------------------------------------------------*

#define CHECK_NEW_BOTTOM_UP_PARSING_ERROR_HANDLING

//---------------------------------------------------------------------------*

bool C_Lexique::performBottomUpParsing (const PMSInt16 inActionTable [],
                                        const char * inNonTerminalSymbolNames [],
                                        const PMUInt32 inActionTableIndex [],
                                        const PMSInt16 * inSuccessorTable [],
                                        const PMSInt16 inProductionsTable []) {
  bool result = false ;
  performLexicalAnalysis () ;
  if (! executionModeIsLexicalAnalysisOnly ()) {
    if (executionModeIsSyntaxAnalysisOnly ()) {
      co << "*** PERFORM BOTTOM-UP PARSING ONLY (--mode=syntax-only option) ***\n"
            "  Initial State: S0\n" ;
    }
  //--- Variables for generating syntax tree in a form suitable for graphviz
    const bool produceSyntaxTree = gOption_galgas_5F_cli_5F_options_outputConcreteSyntaxTree.mValue ;
    C_String syntaxTreeDescriptionString ;
    TC_Array <C_String> shiftedElementStack ;
    shiftedElementStack.addObject ("TOP") ;
    PMUInt32 uniqueTerminalIndex = 0 ;
    PMUInt32 currentProductionName = 0 ;
    if (produceSyntaxTree) {
      syntaxTreeDescriptionString << "digraph G {\n"
                                     "  size =\"4,4\";\n" ;
    }
  //--- Perform first pass
    TC_UniqueArray <TC_LinkedList <PMSInt16> > executionList (100 COMMA_HERE) ;
    executionList.addDefaultObjectUsingSwap () ;

    TC_Array <PMSInt16> stack (10000 COMMA_HERE) ;
    stack.addObject (0) ; // Enter initial state
    PMSInt32 errorSignalingUselessEntryOnTopOfStack = 0 ;
    TC_Array <PMSInt16> poppedErrors (1000 COMMA_HERE)  ;
    
    #ifdef CHECK_NEW_BOTTOM_UP_PARSING_ERROR_HANDLING
      TC_Array <PMSInt16> oldErrorStack (10000 COMMA_HERE) ; // used for signaling a syntax error
      oldErrorStack.addObject (0) ; // Enter initial state
    #endif

    cToken * currentTokenPtr = mFirstToken ;
    PMSInt16 currentToken = (currentTokenPtr != NULL) ? currentTokenPtr->mTokenCode : ((PMSInt16) -1) ;
    if (currentTokenPtr == NULL) {
      mCurrentLocation.resetLocation () ;
    }else{
      mCurrentLocation = currentTokenPtr->mEndLocation ;
    }
    bool loop = true ;
    result = true ;
    while (loop) {
      if (currentToken < 0) {
        if (currentTokenPtr == NULL) {
          currentToken = 0 ; // 0 means end of source file
        }else{
          currentTokenPtr = currentTokenPtr->mNextToken ;
          currentToken = (currentTokenPtr != NULL) ? currentTokenPtr->mTokenCode : ((PMSInt16) 0) ;
          if (currentTokenPtr != NULL) {
            mCurrentLocation = currentTokenPtr->mEndLocation ;
          }
        }
      }
    //--- Get Action code -----------------------------------
      const PMSInt32 currentState = stack.lastObject (HERE) ;
      MF_Assert (currentState >= 0, "currentState (%lld) < 0", currentState, 0) ;
      const PMSInt16 * actionTable = & (inActionTable [inActionTableIndex [currentState]]) ;
      PMSInt16 actionCode = 0 ; 
      while (((* actionTable) >= 0) && (actionCode == 0)) {
        if ((* actionTable) == currentToken) {
          actionTable ++ ;
          actionCode = (* actionTable) ;
        }
        actionTable ++ ;
        actionTable ++ ;
      }
    //--- Decision from action code value
      if (actionCode > 1) {
      //--- Shift action ------------------------------------
        actionCode = (PMSInt16) (actionCode - 2) ;
        stack.addObject (-1) ; // Enter any value
        stack.addObject (actionCode) ; // Enter next current state
        #ifdef CHECK_NEW_BOTTOM_UP_PARSING_ERROR_HANDLING
          oldErrorStack = stack ;
        #endif
        poppedErrors.setCountToZero () ;
        errorSignalingUselessEntryOnTopOfStack = 0 ;
        executionList.addDefaultObjectUsingSwap () ;
      //---
        if (produceSyntaxTree) {
          C_String terminalUniqueName ;
          terminalUniqueName << "T" << cStringWithUnsigned (uniqueTerminalIndex) ;
          syntaxTreeDescriptionString << "  " << terminalUniqueName << " [shape=ellipse, label=" ;
          syntaxTreeDescriptionString.appendCLiteralStringConstant (getCurrentTokenString (currentTokenPtr)) ;
          syntaxTreeDescriptionString << "];\n" ;
          shiftedElementStack.addObject (terminalUniqueName) ;
          uniqueTerminalIndex ++ ;
        }
      //--- Parse Only : print terminal symbol
        if (executionModeIsSyntaxAnalysisOnly ()) {
          co << "  [S" << cStringWithSigned (currentState) << ", "
             << getCurrentTokenString (currentTokenPtr)
             << "] |- Shift -> S" << cStringWithSigned (actionCode) << "\n" ;
        }
      //--- Token has been used
        currentToken = -1 ;
        // co <<  "EXTENSION executionList: " << executionList.count () << "\n" ;
      }else if (actionCode < 0) {
      //--- Reduce action ------------------------------------
        actionCode = (PMSInt16) (- actionCode - 1) ;
        MF_Assert (actionCode >= 0, "actionCode (%lld) < 0", actionCode, 0) ;
        const PMSInt16 nonTerminal = inProductionsTable [2 * actionCode] ;
        const PMSInt32 reduceSize = inProductionsTable [2 * actionCode + 1] ;
        const PMSInt32 executionListLength = executionList.count () ;
        for (PMSInt32 i=executionListLength - reduceSize ; i<executionListLength ; i++) {
          executionList (executionListLength -  reduceSize - 1 COMMA_HERE).mergeListAtBottom (executionList (i COMMA_HERE)) ;
        }
        executionList (executionListLength - reduceSize - 1 COMMA_HERE).insertAtTop (actionCode) ;
        executionList.removeLastObjects (reduceSize COMMA_HERE) ; 
        executionList.addDefaultObjectUsingSwap () ;
        const PMSInt32 stackReduceSize = 2 * reduceSize ;
        for (PMSInt32 i=0 ; i<stackReduceSize ; i++) {
          if (errorSignalingUselessEntryOnTopOfStack > 0) {
            errorSignalingUselessEntryOnTopOfStack -- ;
          }else{
            poppedErrors.addObject (stack.lastObject (HERE)) ;
          }
          stack.removeLastObject (HERE) ;
        }
        if (produceSyntaxTree) {
          for (PMSInt32 i=0 ; i<reduceSize ; i++) {
            syntaxTreeDescriptionString << "  NT" << cStringWithUnsigned (currentProductionName)
                                        << " -> " << shiftedElementStack.lastObject (HERE) << ";\n" ;
            shiftedElementStack.removeLastObject (HERE) ;
          }
        }
     //--- Get Successor state
        const PMSInt32 tempCurrentState = stack.lastObject (HERE) ;
        MF_Assert (tempCurrentState >= 0, "tempCurrentState (%lld) < 0", tempCurrentState, 0) ;
        const PMSInt16 * successorTable = inSuccessorTable [tempCurrentState] ;
        PMSInt16 newCurrentState = -1 ; 
        while (((* successorTable) >= 0) && (newCurrentState < 0)) {
          if ((* successorTable) == nonTerminal) {
            successorTable ++ ;
            newCurrentState = (* successorTable) ;
          }
          successorTable ++ ;
          successorTable ++ ;
        }
        MF_Assert (newCurrentState >= 0, "newCurrentState (%lld) < 0", newCurrentState, 0) ;
        stack.addObject (-1) ; // Enter any value
        stack.addObject (newCurrentState) ; // Enter next current state
        errorSignalingUselessEntryOnTopOfStack += 2 ;
        if (produceSyntaxTree) {
          C_String uniqueProductionName ;
          uniqueProductionName << "NT" << cStringWithUnsigned (currentProductionName) ;
          syntaxTreeDescriptionString << "  " << uniqueProductionName
                                      << " [label=\"" << inNonTerminalSymbolNames [nonTerminal] << "\", shape=box];\n" ;
          shiftedElementStack.addObject (uniqueProductionName) ;
          currentProductionName ++ ;
        }
        if (executionModeIsSyntaxAnalysisOnly ()) {
          co << "  [S" << cStringWithSigned (currentState) << ", " << getCurrentTokenString (currentTokenPtr)
             << "] |- Reduce "
             << inNonTerminalSymbolNames [nonTerminal]
             << " -> S"
             << cStringWithSigned (newCurrentState)
             << "\n" ;
        }
      }else if (actionCode == 1) {
      //--- Accept action -----------------------------------
        loop = false ;
        executionList (0 COMMA_HERE).mergeListAtBottom (executionList (1 COMMA_HERE)) ;
        if (executionModeIsSyntaxAnalysisOnly ()) {
          co << "  [S" << cStringWithSigned (currentState) << ", " << getCurrentTokenString (currentTokenPtr) << "] : Accept\n" ;
        }
      }else{
      //--- Parsing error -----------------------------------
        result = false ;
        loop = false ;
      //--- Build error stack
        TC_Array <PMSInt16> actualErrorStack (stack.count () + poppedErrors.count () COMMA_HERE) ;
        // printf ("errorSignalingUselessEntryOnTopOfStack, %d stack.count () %d\n", errorSignalingUselessEntryOnTopOfStack, stack.count ()) ;
        for (PMSInt32 i=0 ; i<(stack.count () - errorSignalingUselessEntryOnTopOfStack) ; i++) {
          actualErrorStack.addObject (stack (i COMMA_HERE)) ;
        }
        // printf ("poppedErrors.count () %d\n", poppedErrors.count ()) ;
        for (PMSInt32 i=poppedErrors.count () - 1 ; i>=0 ; i--) {
          actualErrorStack.addObject (poppedErrors (i COMMA_HERE)) ;
        }
        #ifdef CHECK_NEW_BOTTOM_UP_PARSING_ERROR_HANDLING
          if (actualErrorStack != oldErrorStack) {
            printf ("****** INTERNAL ERROR: WARN PIERRE MOLINARO ************\n") ;
            printf ("oldErrorStack (old way) %d:", oldErrorStack.count ()) ;
            for (PMSInt32 i=0 ; i<oldErrorStack.count () ; i++) {
              printf (" %d", oldErrorStack (i COMMA_HERE)) ;
            }
            printf ("\n") ;
            printf ("actualErrorStack (new way) %d:", actualErrorStack.count ()) ;
            for (PMSInt32 i=0 ; i<actualErrorStack.count () ; i++) {
              printf (" %d", actualErrorStack (i COMMA_HERE)) ;
            }
            printf ("\n") ;
            printf ("********************************************************\n\7") ;
            co.flush () ;
            actualErrorStack = oldErrorStack ;
          }
        #endif
      //---
        TC_UniqueArray <PMSInt16> expectedTerminalsArray (100 COMMA_HERE) ;
        const PMSInt32 currentErrorState = actualErrorStack.lastObject (HERE) ;
        actionTable = & (inActionTable [inActionTableIndex [currentErrorState]]) ;
        while ((* actionTable) >= 0) {
          const PMSInt16 expectedTerminal = * actionTable ;
          actionTable ++ ;
          const PMSInt16 expectedAction = * actionTable ;
          actionTable ++ ;
          const bool terminalAccepted = acceptExpectedTerminalForBottomUpParsingError
                                             (expectedTerminal,
                                              expectedAction,
                                              actualErrorStack,
                                              inActionTable,
                                              inActionTableIndex,
                                              inSuccessorTable,
                                              inProductionsTable) ;
          if (terminalAccepted) {
            expectedTerminalsArray.addObject (expectedTerminal) ;
          }
        }
        parsingError (expectedTerminalsArray, currentToken LINE_AND_SOURCE_FILE) ;
      }
    }
    if (result) {
      executionList (0 COMMA_HERE).copyIntoArray (mArrayForSecondPassParsing) ;
    }
  //--- Output graphviz file
    if (produceSyntaxTree) {
      syntaxTreeDescriptionString << "}\n" ;
      const C_String filePath = sourceFilePath ().stringByDeletingPathExtension () + ".dot" ;
      // printf ("filePath: '%s'\n", filePath.cString (HERE)) ;
      GALGAS_bool fileWritten ;
      GALGAS_string (syntaxTreeDescriptionString).method_writeToFileWhenDifferentContents (GALGAS_string (filePath), fileWritten, this COMMA_HERE) ;
    }
    if (executionModeIsSyntaxAnalysisOnly ()) {
      co << "*** END OF PARSING (success: " << (result ? "yes" : "no") << ") ***\n" ;
    }
  //--- Set current read location to 0
    resetForSecondPass () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Second pass methods
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//                         Get next production index                         *
//                                                                           *
//---------------------------------------------------------------------------*

PMSInt16 C_Lexique::nextProductionIndex (void) {
  PMSInt16 result = 0 ;
  if (mIndexForSecondPassParsing < mArrayForSecondPassParsing.count ()) {
    result = mArrayForSecondPassParsing (mIndexForSecondPassParsing COMMA_HERE) ;
    mIndexForSecondPassParsing ++ ;
  }
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   Accept current token by shifting it                                     *
//                                                                           *
//---------------------------------------------------------------------------*

void C_Lexique::acceptTerminal (FORMAL_ARG_ACCEPT_TERMINAL COMMA_LOCATION_ARGS) {
  #ifndef DO_NOT_GENERATE_CHECKINGS
    PMSInt16 currentTokenCode = 0 ;
  #endif
  if (mCurrentTokenPtr != NULL) {
    #ifndef DO_NOT_GENERATE_CHECKINGS
      currentTokenCode = mCurrentTokenPtr->mTokenCode ;
    #endif
    mCurrentTokenPtr = mCurrentTokenPtr->mNextToken ;
    if (mCurrentTokenPtr != NULL) {
      mTemplateString << mCurrentTokenPtr->mTemplateStringBeforeToken ;
      mTemplateStringLocation = mCurrentTokenPtr->mStartLocation ;
      mCurrentLocation = mCurrentTokenPtr->mEndLocation ;
    }
  }
  #ifndef DO_NOT_GENERATE_CHECKINGS
    if (currentTokenCode != inExpectedTerminal) {
      C_String currentTokenString ;
      appendTerminalMessageToSyntaxErrorMessage (currentTokenCode, currentTokenString) ;
      C_String expectedTokenString ;
      appendTerminalMessageToSyntaxErrorMessage (inExpectedTerminal, expectedTokenString) ;
      MF_AssertThere (false,
                      "Internal second pass parsing error (current token:%s, expected token:%s)",
                      (PMSInt) currentTokenString.cString (HERE),
                      (PMSInt) expectedTokenString.cString (HERE)) ;
    }
  #endif
}

//---------------------------------------------------------------------------*

void C_Lexique::enterIndexing (const PMUInt32 inIndexingKind) {
  if ((NULL != mIndexingDictionary) && (sourceText ()->sourceFilePath ().length () > 0)) {
    const PMUInt32 tokenStartLocation = (PMUInt32) mCurrentTokenPtr->mStartLocation.index () ;
    const PMUInt32 tokenLine = (PMUInt32) mCurrentTokenPtr->mStartLocation.lineNumber () ;
    const PMUInt32 tokenLength  = ((PMUInt32) mCurrentTokenPtr->mEndLocation.index ()) - tokenStartLocation + 1 ;
    C_String indexedKey = sourceText ()->mSourceString.subString ((PMSInt32) tokenStartLocation, (PMSInt32) tokenLength) ;
    mIndexingDictionary->addIndexedKey (inIndexingKind,
                                        indexedKey,
                                        sourceText ()->sourceFilePath (),
                                        tokenLine,
                                        tokenStartLocation,
                                        tokenLength) ;
  }
}

//---------------------------------------------------------------------------*

void C_Lexique::enableIndexing (void) {
  macroMyNew (mIndexingDictionary, cIndexingDictionary) ;
}

//---------------------------------------------------------------------------*

void C_Lexique::generateIndexFile (void) {
  if (NULL != mIndexingDictionary) {
    const C_String sourceFilePath = sourceText ()->sourceFilePath () ;
    C_String indexFilePath = C_FileManager::absolutePathFromPath (indexingDirectory (), sourceFilePath.stringByDeletingLastPathComponent ()) ;
    indexFilePath << "/" << sourceFilePath.lastPathComponent () << ".plist" ;
    mIndexingDictionary->generateIndexFile (indexFilePath) ;
  }
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= Handling Parsing context
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//Handling parsing context (for parse ... rewind ... end parse ; instruction)*
//                                                                           *
//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*

void C_Lexique::setParsingContext (const C_parsingContext & inContext) {
  mIndexForSecondPassParsing = inContext.mParsingArrayIndex ;
  mCurrentTokenPtr = inContext.mCurrentTokenPtr ;
  mCurrentLocation = inContext.mLocation ;
  mCurrentChar = inContext.mCurrentChar ;
  mPreviousChar = inContext.mPreviousChar ;
  mTemplateString = inContext.mTemplateString ;
}

//---------------------------------------------------------------------------*

#ifdef PRAGMA_MARK_ALLOWED
  #pragma mark ========= For Debugging parser
#endif

//---------------------------------------------------------------------------*
//                                                                           *
//  For Debugging parser                                                     *
//                                                                           *
//---------------------------------------------------------------------------*

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
    for (PMUInt16 i=1 ; i<mDebugDepthCounter ; i++) {
      message << "|  " ;
    }
    message << ((mDebugDepthCounter > 0) ? "|- " : "") << inProductionName ;
    if (inLabel != NULL) {
      message << " label '" << inLabel << "'" ;
    }
    if ((inTag != NULL) && (inTag [0] != '\0')) {
      message << " tag '" << inTag << "'" ;
    }
    message << "\n" ;
    ggs_printMessage (message COMMA_HERE) ;
    mDebugDepthCounter ++ ;
  }
}

//---------------------------------------------------------------------------*

void C_Lexique::exitProduction (void) {
  if (mDebugIsRunning) {
    mDebugDepthCounter -- ;
    mDebugIsRunning = mDebugDepthCounter > 0 ;
  }
}

//---------------------------------------------------------------------------*

void C_Lexique::didParseTerminal (const char * inTerminalName,
                                  const C_String & inValue) {
  if (mDebugIsRunning) {
    C_String message ;
    for (PMUInt16 i=1 ; i<mDebugDepthCounter ; i++) {
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

//---------------------------------------------------------------------------*
