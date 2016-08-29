#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-1.h"


//---------------------------------------------------------------------------------------------------------------------*

cMapElement_implementationMap::cMapElement_implementationMap (const GALGAS_lstring & inKey,
                                                              const GALGAS_implementationObject & in_obj
                                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_obj (in_obj) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_implementationMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_obj.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_implementationMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_implementationMap (mAttribute_lkey, mAttribute_obj COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_implementationMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "obj" ":" ;
  mAttribute_obj.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_implementationMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_implementationMap * operand = (cMapElement_implementationMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_obj.objectCompare (operand->mAttribute_obj) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap::GALGAS_implementationMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap::GALGAS_implementationMap (const GALGAS_implementationMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap & GALGAS_implementationMap::operator = (const GALGAS_implementationMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap GALGAS_implementationMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_implementationMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap GALGAS_implementationMap::constructor_mapWithMapToOverride (const GALGAS_implementationMap & inMapToOverride
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_implementationMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap GALGAS_implementationMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_implementationMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                    const GALGAS_implementationObject & inArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_implementationMap * p = NULL ;
  macroMyNew (p, cMapElement_implementationMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@implementationMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::setter_put (GALGAS_lstring inKey,
                                           GALGAS_implementationObject inArgument0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  cMapElement_implementationMap * p = NULL ;
  macroMyNew (p, cMapElement_implementationMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_implementationMap_get = "%K does not exists" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::method_get (GALGAS_lstring inKey,
                                           GALGAS_implementationObject & outArgument0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) performSearch (inKey,
                                                                                                     inCompiler,
                                                                                                     kSearchErrorMessage_implementationMap_get
                                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    outArgument0 = p->mAttribute_obj ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::setter_del (GALGAS_lstring inKey,
                                           GALGAS_implementationObject & outArgument0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_implementationMap * p = (cMapElement_implementationMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    outArgument0 = p->mAttribute_obj ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject GALGAS_implementationMap::getter_objForKey (const GALGAS_string & inKey,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) attributes ;
  GALGAS_implementationObject result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    result = p->mAttribute_obj ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap::setter_setObjForKey (GALGAS_implementationObject inAttributeValue,
                                                    GALGAS_string inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_implementationMap * p = (cMapElement_implementationMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_implementationMap) ;
    p->mAttribute_obj = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_implementationMap * GALGAS_implementationMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_implementationMap * result = (cMapElement_implementationMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_implementationMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_implementationMap::cEnumerator_implementationMap (const GALGAS_implementationMap & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap_2D_element cEnumerator_implementationMap::current (LOCATION_ARGS) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationMap) ;
  return GALGAS_implementationMap_2D_element (p->mAttribute_lkey, p->mAttribute_obj) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_implementationMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject cEnumerator_implementationMap::current_obj (LOCATION_ARGS) const {
  const cMapElement_implementationMap * p = (const cMapElement_implementationMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_implementationMap) ;
  return p->mAttribute_obj ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @implementationMap type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationMap ("implementationMap",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_implementationMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_implementationMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap GALGAS_implementationMap::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_implementationMap result ;
  const GALGAS_implementationMap * p = (const GALGAS_implementationMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_implementationMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     L E X I Q U E                                                                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//---------------------------------------------------------------------------------------------------------------------*

cTokenFor_options_5F_scanner::cTokenFor_options_5F_scanner (void) :
mLexicalAttribute_floatNumber (),
mLexicalAttribute_integerNumber (),
mLexicalAttribute_key (),
mLexicalAttribute_number (),
mLexicalAttribute_string () {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_options_5F_scanner::C_Lexique_options_5F_scanner (C_Compiler * inCallerCompiler,
                                                            const C_String & inDependencyFileExtension,
                                                            const C_String & inDependencyFilePath,
                                                            const C_String & inSourceFileName
                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inDependencyFileExtension, inDependencyFilePath, inSourceFileName COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

C_Lexique_options_5F_scanner::C_Lexique_options_5F_scanner (C_Compiler * inCallerCompiler,
                                                            const C_String & inSourceString,
                                                            const C_String & inStringForError
                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                 I N D E X I N G    D I R E C T O R Y                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::indexingDirectory (void) const {
  return "" ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                        Lexical error message list                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

static const char * gLexicalMessage_options_5F_scanner_decimalNumberTooLarge = "decimal number too large" ;

static const char * gLexicalMessage_options_5F_scanner_internalError = "internal error" ;

static const char * gLexicalMessage_options_5F_scanner_unableToConvertToDouble = "Unable to convert the string to double" ;

static const char * gLexicalMessage_options_5F_scanner_unterminatedLitteralString = "Unterminated literal string" ;

//---------------------------------------------------------------------------------------------------------------------*
//          Syntax error messages, for every terminal symbol                                                           *
//---------------------------------------------------------------------------------------------------------------------*

//--- Syntax error message for terminal '$idf$' :
static const char * gSyntaxErrorMessage_options_5F_scanner_idf = "identifier" ;

//--- Syntax error message for terminal '$string$' :
static const char * gSyntaxErrorMessage_options_5F_scanner_string = "literal string" ;

//--- Syntax error message for terminal '$uint_number$' :
static const char * gSyntaxErrorMessage_options_5F_scanner_uint_5F_number = "literal unsigned 64 bits integer" ;

//--- Syntax error message for terminal '$float_number$' :
static const char * gSyntaxErrorMessage_options_5F_scanner_float_5F_number = "literal float" ;

//--- Syntax error message for terminal '$=$' :
static const char * gSyntaxErrorMessage_options_5F_scanner__3D_ = "'=' delimiter" ;

//--- Syntax error message for terminal '$,$' :
static const char * gSyntaxErrorMessage_options_5F_scanner__2C_ = "',' delimiter" ;

//--- Syntax error message for terminal '$-$' :
static const char * gSyntaxErrorMessage_options_5F_scanner__2D_ = "'-' delimiter" ;

//--- Syntax error message for terminal '$($' :
static const char * gSyntaxErrorMessage_options_5F_scanner__28_ = "'(' delimiter" ;

//--- Syntax error message for terminal '$)$' :
static const char * gSyntaxErrorMessage_options_5F_scanner__29_ = "')' delimiter" ;

//---------------------------------------------------------------------------------------------------------------------*
//                getMessageForTerminal                                                                                *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::getMessageForTerminal (const int16_t inTerminalIndex) const {
  static const char * syntaxErrorMessageArray [10] = {kEndOfSourceLexicalErrorMessage,
    gSyntaxErrorMessage_options_5F_scanner_idf,
    gSyntaxErrorMessage_options_5F_scanner_string,
    gSyntaxErrorMessage_options_5F_scanner_uint_5F_number,
    gSyntaxErrorMessage_options_5F_scanner_float_5F_number,
    gSyntaxErrorMessage_options_5F_scanner__3D_,
    gSyntaxErrorMessage_options_5F_scanner__2C_,
    gSyntaxErrorMessage_options_5F_scanner__2D_,
    gSyntaxErrorMessage_options_5F_scanner__28_,
    gSyntaxErrorMessage_options_5F_scanner__29_} ;
  return syntaxErrorMessageArray [inTerminalIndex] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                      U N I C O D E    S T R I N G S                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

//--- Unicode string for '$_28_$'
static const utf32 kUnicodeString_options_5F_scanner__28_ [] = {
  TO_UNICODE ('('),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_29_$'
static const utf32 kUnicodeString_options_5F_scanner__29_ [] = {
  TO_UNICODE (')'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2C_$'
static const utf32 kUnicodeString_options_5F_scanner__2C_ [] = {
  TO_UNICODE (','),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D_$'
static const utf32 kUnicodeString_options_5F_scanner__2D_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_X$'
static const utf32 kUnicodeString_options_5F_scanner__30_X [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('X'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_30_x$'
static const utf32 kUnicodeString_options_5F_scanner__30_x [] = {
  TO_UNICODE ('0'),
  TO_UNICODE ('x'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_options_5F_scanner__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//---------------------------------------------------------------------------------------------------------------------*
//             Key words table 'optionsDelimiters'                            *
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t ktable_size_options_5F_scanner_optionsDelimiters = 5 ;

static const C_unicode_lexique_table_entry ktable_for_options_5F_scanner_optionsDelimiters [ktable_size_options_5F_scanner_optionsDelimiters] = {
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__28_, 1, C_Lexique_options_5F_scanner::kToken__28_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__29_, 1, C_Lexique_options_5F_scanner::kToken__29_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__2C_, 1, C_Lexique_options_5F_scanner::kToken__2C_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__2D_, 1, C_Lexique_options_5F_scanner::kToken__2D_),
  C_unicode_lexique_table_entry (kUnicodeString_options_5F_scanner__3D_, 1, C_Lexique_options_5F_scanner::kToken__3D_)
} ;

int16_t C_Lexique_options_5F_scanner::search_into_optionsDelimiters (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_options_5F_scanner_optionsDelimiters, ktable_size_options_5F_scanner_optionsDelimiters) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                          getCurrentTokenString                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_options_5F_scanner * ptr = (const cTokenFor_options_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_idf:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("idf") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_key) ;
      break ;
    case kToken_string:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("string") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_string) ;
      break ;
    case kToken_uint_5F_number:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("uint_number") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendUnsigned (ptr->mLexicalAttribute_integerNumber) ;
      break ;
    case kToken_float_5F_number:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("float_number") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendDouble (ptr->mLexicalAttribute_floatNumber) ;
      break ;
    case kToken__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (",") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("-") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__28_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("(") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__29_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (")") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                           Template Delimiters                                                                       *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                           Template Replacements                                                                     *
//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//            Terminal Symbols as end of script in template mark                                                       *
//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*
//               P A R S E    L E X I C A L    T O K E N                                                               *
//---------------------------------------------------------------------------------------------------------------------*

bool C_Lexique_options_5F_scanner::parseLexicalToken (void) {
  cTokenFor_options_5F_scanner token ;
  mLoop = true ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    token.mLexicalAttribute_floatNumber = 0.0 ;
    token.mLexicalAttribute_integerNumber = 0 ;
    token.mLexicalAttribute_key.setLengthToZero () ;
    token.mLexicalAttribute_number.setLengthToZero () ;
    token.mLexicalAttribute_string.setLengthToZero () ;
    mTokenStartLocation = mCurrentLocation ;
    try{
      if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_key, previousChar ()) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('z')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('Z')) || testForInputUTF32Char (TO_UNICODE ('_')) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        token.mTokenCode = kToken_idf ;
        enterToken (token) ;
      }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
        do {
          if (testForInputUTF32CharRange (TO_UNICODE (' '), TO_UNICODE ('!')) || testForInputUTF32CharRange (TO_UNICODE ('#'), TO_UNICODE (65533))) {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_string, previousChar ()) ;
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
          token.mTokenCode = kToken_string ;
          enterToken (token) ;
        }else{
          lexicalError (gLexicalMessage_options_5F_scanner_unterminatedLitteralString COMMA_LINE_AND_SOURCE_FILE) ;
        }
      }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__30_x, 2, true) || testForInputUTF32String (kUnicodeString_options_5F_scanner__30_X, 2, true)) {
        do {
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32CharRange (TO_UNICODE ('a'), TO_UNICODE ('f')) || testForInputUTF32CharRange (TO_UNICODE ('A'), TO_UNICODE ('F'))) {
            ::scanner_routine_enterHexDigitIntoUInt64 (*this, previousChar (), token.mLexicalAttribute_integerNumber, gLexicalMessage_options_5F_scanner_decimalNumberTooLarge, gLexicalMessage_options_5F_scanner_internalError) ;
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        token.mTokenCode = kToken_uint_5F_number ;
        enterToken (token) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
        do {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_number, previousChar ()) ;
          ::scanner_routine_enterDigitIntoUInt64 (*this, previousChar (), token.mLexicalAttribute_integerNumber, gLexicalMessage_options_5F_scanner_decimalNumberTooLarge, gLexicalMessage_options_5F_scanner_internalError) ;
          if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
          }else{
            mLoop = false ;
          }
        }while (mLoop) ;
        mLoop = true ;
        if (testForInputUTF32Char (TO_UNICODE ('.'))) {
          do {
            ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_number, previousChar ()) ;
            if (testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9'))) {
            }else{
              mLoop = false ;
            }
          }while (mLoop) ;
          mLoop = true ;
          ::scanner_routine_convertStringToDouble (*this, token.mLexicalAttribute_number, token.mLexicalAttribute_floatNumber, gLexicalMessage_options_5F_scanner_unableToConvertToDouble) ;
          token.mTokenCode = kToken_float_5F_number ;
          enterToken (token) ;
        }else{
          token.mTokenCode = kToken_uint_5F_number ;
          enterToken (token) ;
        }
      }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__3D_, 1, true)) {
        token.mTokenCode = kToken__3D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__2D_, 1, true)) {
        token.mTokenCode = kToken__2D_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__2C_, 1, true)) {
        token.mTokenCode = kToken__2C_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__29_, 1, true)) {
        token.mTokenCode = kToken__29_ ;
        enterToken (token) ;
      }else if (testForInputUTF32String (kUnicodeString_options_5F_scanner__28_, 1, true)) {
        token.mTokenCode = kToken__28_ ;
        enterToken (token) ;
      }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
      }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
        token.mTokenCode = kToken_ ; // Empty string code
      }else{ // Unknown input character
        unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      }
    }catch (const C_lexicalErrorException &) {
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }
  if ((UNICODE_VALUE (mCurrentChar) == '\0') && (token.mTemplateStringBeforeToken.length () > 0)) {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         E N T E R    T O K E N                                                                      *
//---------------------------------------------------------------------------------------------------------------------*

void C_Lexique_options_5F_scanner::enterToken (cTokenFor_options_5F_scanner & ioToken) {
  cTokenFor_options_5F_scanner * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_options_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_floatNumber = ioToken.mLexicalAttribute_floatNumber ;
  ptr->mLexicalAttribute_integerNumber = ioToken.mLexicalAttribute_integerNumber ;
  ptr->mLexicalAttribute_key = ioToken.mLexicalAttribute_key ;
  ptr->mLexicalAttribute_number = ioToken.mLexicalAttribute_number ;
  ptr->mLexicalAttribute_string = ioToken.mLexicalAttribute_string ;
  enterTokenFromPointer (ptr) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//               A T T R I B U T E   A C C E S S                                                                       *
//---------------------------------------------------------------------------------------------------------------------*

double C_Lexique_options_5F_scanner::attributeValue_floatNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_floatNumber ;
}

//---------------------------------------------------------------------------------------------------------------------*

uint64_t C_Lexique_options_5F_scanner::attributeValue_integerNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_integerNumber ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::attributeValue_key (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_key ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::attributeValue_number (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_number ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::attributeValue_string (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  return ptr->mLexicalAttribute_string ;
}

//---------------------------------------------------------------------------------------------------------------------*
//         A S S I G N    F R O M    A T T R I B U T E                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ldouble C_Lexique_options_5F_scanner::synthetizedAttribute_floatNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_double value (ptr->mLexicalAttribute_floatNumber) ;
  GALGAS_ldouble result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ C_Lexique_options_5F_scanner::synthetizedAttribute_integerNumber (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_uint_36__34_ value (ptr->mLexicalAttribute_integerNumber) ;
  GALGAS_luint_36__34_ result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_options_5F_scanner::synthetizedAttribute_key (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_key) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_options_5F_scanner::synthetizedAttribute_number (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_number) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring C_Lexique_options_5F_scanner::synthetizedAttribute_string (void) const {
  cTokenFor_options_5F_scanner * ptr = (cTokenFor_options_5F_scanner *) mCurrentTokenPtr ;
  macroValidSharedObject (ptr, cTokenFor_options_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_string) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                         I N T R O S P E C T I O N                                                                   *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist C_Lexique_options_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("idf") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("string") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("uint_number") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("float_number") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (",") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("-") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("(") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (")") COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordLists_options_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.addObject ("options_scanner:optionsDelimiters") ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void getKeywordsForIdentifier_options_5F_scanner (const C_String & inIdentifier,
                                                         bool & ioFound,
                                                         TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "options_scanner:optionsDelimiters") {
    ioFound = true ;
    ioList.addObject ("(") ;
    ioList.addObject (")") ;
    ioList.addObject (",") ;
    ioList.addObject ("-") ;
    ioList.addObject ("=") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static cLexiqueIntrospection lexiqueIntrospection_options_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_options_5F_scanner, getKeywordsForIdentifier_options_5F_scanner) ;

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

uint32_t C_Lexique_options_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [10] = {0,
    1 /* options_scanner_1_idf */,
    3 /* options_scanner_1_string */,
    4 /* options_scanner_1_uint_5F_number */,
    5 /* options_scanner_1_float_5F_number */,
    2 /* options_scanner_1__3D_ */,
    2 /* options_scanner_1__2C_ */,
    2 /* options_scanner_1__2D_ */,
    2 /* options_scanner_1__28_ */,
    2 /* options_scanner_1__29_ */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                                            *
//---------------------------------------------------------------------------------------------------------------------*

C_String C_Lexique_options_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 6) {
    static const char * kStyleArray [6] = {
      "",
      "identifierStyle",
      "delimitersStyle",
      "stringStyle",
      "integerStyle",
      "floatStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_identifierMap::cMapElement_identifierMap (const GALGAS_lstring & inKey,
                                                      const GALGAS_object_5F_t & in_value
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_identifierMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_identifierMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_identifierMap (mAttribute_lkey, mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_identifierMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_identifierMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_identifierMap * operand = (cMapElement_identifierMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (operand->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap::GALGAS_identifierMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap::GALGAS_identifierMap (const GALGAS_identifierMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap & GALGAS_identifierMap::operator = (const GALGAS_identifierMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap GALGAS_identifierMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_identifierMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap GALGAS_identifierMap::constructor_mapWithMapToOverride (const GALGAS_identifierMap & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_identifierMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap GALGAS_identifierMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_identifierMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_object_5F_t & inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_identifierMap * p = NULL ;
  macroMyNew (p, cMapElement_identifierMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@identifierMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::setter_put (GALGAS_lstring inKey,
                                       GALGAS_object_5F_t inArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  cMapElement_identifierMap * p = NULL ;
  macroMyNew (p, cMapElement_identifierMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_identifierMap_get = "Identifier %K is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::method_get (GALGAS_lstring inKey,
                                       GALGAS_object_5F_t & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) performSearch (inKey,
                                                                                             inCompiler,
                                                                                             kSearchErrorMessage_identifierMap_get
                                                                                             COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::setter_del (GALGAS_lstring inKey,
                                       GALGAS_object_5F_t & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "Identifier %K is not defined" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_identifierMap * p = (cMapElement_identifierMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_identifierMap::getter_valueForKey (const GALGAS_string & inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) attributes ;
  GALGAS_object_5F_t result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap::setter_setValueForKey (GALGAS_object_5F_t inAttributeValue,
                                                  GALGAS_string inKey,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_identifierMap * p = (cMapElement_identifierMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_identifierMap) ;
    p->mAttribute_value = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_identifierMap * GALGAS_identifierMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_identifierMap * result = (cMapElement_identifierMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_identifierMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_identifierMap::cEnumerator_identifierMap (const GALGAS_identifierMap & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap_2D_element cEnumerator_identifierMap::current (LOCATION_ARGS) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_identifierMap) ;
  return GALGAS_identifierMap_2D_element (p->mAttribute_lkey, p->mAttribute_value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_identifierMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t cEnumerator_identifierMap::current_value (LOCATION_ARGS) const {
  const cMapElement_identifierMap * p = (const cMapElement_identifierMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_identifierMap) ;
  return p->mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @identifierMap type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierMap ("identifierMap",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_identifierMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_identifierMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap GALGAS_identifierMap::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_identifierMap result ;
  const GALGAS_identifierMap * p = (const GALGAS_identifierMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_identifierMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@identifierList' list                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_identifierList : public cCollectionElement {
  public : GALGAS_identifierList_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_identifierList (const GALGAS_object_5F_t & in_item
                                              COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_identifierList::cCollectionElement_identifierList (const GALGAS_object_5F_t & in_item
                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_item) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_identifierList::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_identifierList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_identifierList (mObject.mAttribute_item COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_identifierList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "item" ":" ;
  mObject.mAttribute_item.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_identifierList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_identifierList * operand = (cCollectionElement_identifierList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_identifierList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList::GALGAS_identifierList (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList::GALGAS_identifierList (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_identifierList result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::constructor_listWithValue (const GALGAS_object_5F_t & inOperand0
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_identifierList result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_identifierList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                       const GALGAS_object_5F_t & in_item
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement_identifierList * p = NULL ;
  macroMyNew (p, cCollectionElement_identifierList (in_item COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::addAssign_operation (const GALGAS_object_5F_t & inOperand0
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_identifierList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::setter_insertAtIndex (const GALGAS_object_5F_t inOperand0,
                                                  const GALGAS_uint inInsertionIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_identifierList (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::setter_removeAtIndex (GALGAS_object_5F_t & outOperand0,
                                                  const GALGAS_uint inRemoveIndex,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_identifierList) ;
      outOperand0 = p->mObject.mAttribute_item ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::setter_popFirst (GALGAS_object_5F_t & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::setter_popLast (GALGAS_object_5F_t & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::method_first (GALGAS_object_5F_t & outOperand0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::method_last (GALGAS_object_5F_t & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    outOperand0 = p->mObject.mAttribute_item ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::add_operation (const GALGAS_identifierList & inOperand,
                                                            C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_identifierList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_identifierList result = GALGAS_identifierList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_identifierList result = GALGAS_identifierList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_identifierList result = GALGAS_identifierList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList::plusAssign_operation (const GALGAS_identifierList inOperand,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_identifierList::getter_itemAtIndex (const GALGAS_uint & inIndex,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_identifierList * p = (cCollectionElement_identifierList *) attributes.ptr () ;
  GALGAS_object_5F_t result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_identifierList) ;
    result = p->mObject.mAttribute_item ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_identifierList::cEnumerator_identifierList (const GALGAS_identifierList & inEnumeratedObject,
                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList_2D_element cEnumerator_identifierList::current (LOCATION_ARGS) const {
  const cCollectionElement_identifierList * p = (const cCollectionElement_identifierList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_identifierList) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t cEnumerator_identifierList::current_item (LOCATION_ARGS) const {
  const cCollectionElement_identifierList * p = (const cCollectionElement_identifierList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_identifierList) ;
  return p->mObject.mAttribute_item ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @identifierList type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierList ("identifierList",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_identifierList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierList ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_identifierList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierList (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList GALGAS_identifierList::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_identifierList result ;
  const GALGAS_identifierList * p = (const GALGAS_identifierList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_identifierList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_stringMap::cMapElement_stringMap (const GALGAS_lstring & inKey,
                                              const GALGAS_string & in_value
                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_stringMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_stringMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_stringMap (mAttribute_lkey, mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_stringMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_stringMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_stringMap * operand = (cMapElement_stringMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (operand->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap::GALGAS_stringMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap::GALGAS_stringMap (const GALGAS_stringMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap & GALGAS_stringMap::operator = (const GALGAS_stringMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap GALGAS_stringMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_stringMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap GALGAS_stringMap::constructor_mapWithMapToOverride (const GALGAS_stringMap & inMapToOverride
                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_stringMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap GALGAS_stringMap::getter_overriddenMap (C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_stringMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap::addAssign_operation (const GALGAS_lstring & inKey,
                                            const GALGAS_string & inArgument0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  cMapElement_stringMap * p = NULL ;
  macroMyNew (p, cMapElement_stringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@stringMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap::setter_put (GALGAS_lstring inKey,
                                   GALGAS_string inArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
  cMapElement_stringMap * p = NULL ;
  macroMyNew (p, cMapElement_stringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "stringmap key %K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_stringMap_get = "stringmap key %K is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap::method_get (GALGAS_lstring inKey,
                                   GALGAS_string & outArgument0,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) performSearch (inKey,
                                                                                     inCompiler,
                                                                                     kSearchErrorMessage_stringMap_get
                                                                                     COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_stringMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_stringMap::getter_valueForKey (const GALGAS_string & inKey,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) attributes ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringMap) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap::setter_setValueForKey (GALGAS_string inAttributeValue,
                                              GALGAS_string inKey,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_stringMap * p = (cMapElement_stringMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringMap) ;
    p->mAttribute_value = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_stringMap * GALGAS_stringMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                             const GALGAS_string & inKey
                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_stringMap * result = (cMapElement_stringMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_stringMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_stringMap::cEnumerator_stringMap (const GALGAS_stringMap & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap_2D_element cEnumerator_stringMap::current (LOCATION_ARGS) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringMap) ;
  return GALGAS_stringMap_2D_element (p->mAttribute_lkey, p->mAttribute_value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_stringMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_stringMap::current_value (LOCATION_ARGS) const {
  const cMapElement_stringMap * p = (const cMapElement_stringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringMap) ;
  return p->mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @stringMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringMap ("stringMap",
                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_stringMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_stringMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap GALGAS_stringMap::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_stringMap result ;
  const GALGAS_stringMap * p = (const GALGAS_stringMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_lstringMap::cMapElement_lstringMap (const GALGAS_lstring & inKey,
                                                const GALGAS_lstring & in_value
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_value (in_value) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_lstringMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_lstringMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_lstringMap (mAttribute_lkey, mAttribute_value COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_lstringMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mAttribute_value.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_lstringMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_lstringMap * operand = (cMapElement_lstringMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_value.objectCompare (operand->mAttribute_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap::GALGAS_lstringMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap::GALGAS_lstringMap (const GALGAS_lstringMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap & GALGAS_lstringMap::operator = (const GALGAS_lstringMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap GALGAS_lstringMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_lstringMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap GALGAS_lstringMap::constructor_mapWithMapToOverride (const GALGAS_lstringMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_lstringMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap GALGAS_lstringMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_lstringMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_lstring & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_lstringMap * p = NULL ;
  macroMyNew (p, cMapElement_lstringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@lstringMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_lstring inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_lstringMap * p = NULL ;
  macroMyNew (p, cMapElement_lstringMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "lstringmap key %K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_lstringMap_get = "lstringmap key %K is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_lstring & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_lstringMap_get
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    outArgument0 = p->mAttribute_value ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_lstringMap::getter_valueForKey (const GALGAS_string & inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) attributes ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    result = p->mAttribute_value ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap::setter_setValueForKey (GALGAS_lstring inAttributeValue,
                                               GALGAS_string inKey,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_lstringMap * p = (cMapElement_lstringMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_lstringMap) ;
    p->mAttribute_value = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_lstringMap * GALGAS_lstringMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_lstringMap * result = (cMapElement_lstringMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_lstringMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_lstringMap::cEnumerator_lstringMap (const GALGAS_lstringMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap_2D_element cEnumerator_lstringMap::current (LOCATION_ARGS) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_lstringMap) ;
  return GALGAS_lstringMap_2D_element (p->mAttribute_lkey, p->mAttribute_value) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_lstringMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_lstringMap::current_value (LOCATION_ARGS) const {
  const cMapElement_lstringMap * p = (const cMapElement_lstringMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_lstringMap) ;
  return p->mAttribute_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @lstringMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringMap ("lstringMap",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_lstringMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_lstringMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap GALGAS_lstringMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_lstringMap result ;
  const GALGAS_lstringMap * p = (const GALGAS_lstringMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_lstringMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_prefix_5F_map::cMapElement_prefix_5F_map (const GALGAS_lstring & inKey,
                                                      const GALGAS_string & in_prefix,
                                                      const GALGAS_string & in_tag_5F_to_5F_rep
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_prefix (in_prefix),
mAttribute_tag_5F_to_5F_rep (in_tag_5F_to_5F_rep) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_prefix_5F_map::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_prefix.isValid () && mAttribute_tag_5F_to_5F_rep.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_prefix_5F_map::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_prefix_5F_map (mAttribute_lkey, mAttribute_prefix, mAttribute_tag_5F_to_5F_rep COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_prefix_5F_map::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "prefix" ":" ;
  mAttribute_prefix.description (ioString, inIndentation) ;
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "tag_to_rep" ":" ;
  mAttribute_tag_5F_to_5F_rep.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_prefix_5F_map::compare (const cCollectionElement * inOperand) const {
  cMapElement_prefix_5F_map * operand = (cMapElement_prefix_5F_map *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_prefix.objectCompare (operand->mAttribute_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mAttribute_tag_5F_to_5F_rep.objectCompare (operand->mAttribute_tag_5F_to_5F_rep) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map::GALGAS_prefix_5F_map (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map::GALGAS_prefix_5F_map (const GALGAS_prefix_5F_map & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map & GALGAS_prefix_5F_map::operator = (const GALGAS_prefix_5F_map & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_prefix_5F_map result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::constructor_mapWithMapToOverride (const GALGAS_prefix_5F_map & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_prefix_5F_map result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_prefix_5F_map result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_string & inArgument0,
                                                const GALGAS_string & inArgument1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_prefix_5F_map (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@prefix_5F_map insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::setter_add (GALGAS_lstring inKey,
                                       GALGAS_string inArgument0,
                                       GALGAS_string inArgument1,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_prefix_5F_map (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "prefix %K duplicated %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::setter_insert_5F_prefix (GALGAS_lstring inKey,
                                                    GALGAS_string inArgument0,
                                                    GALGAS_string inArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_prefix_5F_map (inKey, inArgument0, inArgument1 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "prefix %K duplicated %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_prefix_5F_map_prefix = "prefix %K is not defined" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::method_prefix (GALGAS_lstring inKey,
                                          GALGAS_string & outArgument0,
                                          GALGAS_string & outArgument1,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) performSearch (inKey,
                                                                                             inCompiler,
                                                                                             kSearchErrorMessage_prefix_5F_map_prefix
                                                                                             COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
    outArgument1.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    outArgument0 = p->mAttribute_prefix ;
    outArgument1 = p->mAttribute_tag_5F_to_5F_rep ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_prefix_5F_map::getter_prefixForKey (const GALGAS_string & inKey,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) attributes ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    result = p->mAttribute_prefix ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_prefix_5F_map::getter_tag_5F_to_5F_repForKey (const GALGAS_string & inKey,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) attributes ;
  GALGAS_string result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    result = p->mAttribute_tag_5F_to_5F_rep ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::setter_setPrefixForKey (GALGAS_string inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_prefix_5F_map * p = (cMapElement_prefix_5F_map *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    p->mAttribute_prefix = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map::setter_setTag_5F_to_5F_repForKey (GALGAS_string inAttributeValue,
                                                             GALGAS_string inKey,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_prefix_5F_map * p = (cMapElement_prefix_5F_map *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
    p->mAttribute_tag_5F_to_5F_rep = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_prefix_5F_map * GALGAS_prefix_5F_map::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_prefix_5F_map * result = (cMapElement_prefix_5F_map *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_prefix_5F_map) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_prefix_5F_map::cEnumerator_prefix_5F_map (const GALGAS_prefix_5F_map & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map_2D_element cEnumerator_prefix_5F_map::current (LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
  return GALGAS_prefix_5F_map_2D_element (p->mAttribute_lkey, p->mAttribute_prefix, p->mAttribute_tag_5F_to_5F_rep) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_prefix_5F_map::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_prefix_5F_map::current_prefix (LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
  return p->mAttribute_prefix ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cEnumerator_prefix_5F_map::current_tag_5F_to_5F_rep (LOCATION_ARGS) const {
  const cMapElement_prefix_5F_map * p = (const cMapElement_prefix_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_prefix_5F_map) ;
  return p->mAttribute_tag_5F_to_5F_rep ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @prefix_map type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefix_5F_map ("prefix_map",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_prefix_5F_map::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefix_5F_map ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_prefix_5F_map::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefix_5F_map (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map GALGAS_prefix_5F_map::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_prefix_5F_map result ;
  const GALGAS_prefix_5F_map * p = (const GALGAS_prefix_5F_map *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefix_5F_map *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefix_map", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_stringset_5F_map::cMapElement_stringset_5F_map (const GALGAS_lstring & inKey,
                                                            const GALGAS_stringset & in_ids
                                                            COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_ids (in_ids) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_stringset_5F_map::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_ids.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_stringset_5F_map::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_stringset_5F_map (mAttribute_lkey, mAttribute_ids COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_stringset_5F_map::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "ids" ":" ;
  mAttribute_ids.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_stringset_5F_map::compare (const cCollectionElement * inOperand) const {
  cMapElement_stringset_5F_map * operand = (cMapElement_stringset_5F_map *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_ids.objectCompare (operand->mAttribute_ids) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map::GALGAS_stringset_5F_map (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map::GALGAS_stringset_5F_map (const GALGAS_stringset_5F_map & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map & GALGAS_stringset_5F_map::operator = (const GALGAS_stringset_5F_map & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_stringset_5F_map result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::constructor_mapWithMapToOverride (const GALGAS_stringset_5F_map & inMapToOverride
                                                                                   COMMA_LOCATION_ARGS) {
  GALGAS_stringset_5F_map result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::getter_overriddenMap (C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  GALGAS_stringset_5F_map result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::addAssign_operation (const GALGAS_lstring & inKey,
                                                   const GALGAS_stringset & inArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cMapElement_stringset_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_stringset_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@stringset_5F_map insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::setter_add (GALGAS_lstring inKey,
                                          GALGAS_stringset inArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  cMapElement_stringset_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_stringset_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "Key %K is already used there" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_stringset_5F_map_get = "Key %K is not there" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::method_get (GALGAS_lstring inKey,
                                          GALGAS_stringset & outArgument0,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_stringset_5F_map_get
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    outArgument0 = p->mAttribute_ids ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::setter_delete (GALGAS_lstring inKey,
                                             GALGAS_stringset & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "Key %K cannot be deleted" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_stringset_5F_map * p = (cMapElement_stringset_5F_map *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    outArgument0 = p->mAttribute_ids ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_stringset_5F_map::getter_idsForKey (const GALGAS_string & inKey,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) attributes ;
  GALGAS_stringset result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    result = p->mAttribute_ids ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map::setter_setIdsForKey (GALGAS_stringset inAttributeValue,
                                                   GALGAS_string inKey,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_stringset_5F_map * p = (cMapElement_stringset_5F_map *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
    p->mAttribute_ids = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_stringset_5F_map * GALGAS_stringset_5F_map::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) {
  cMapElement_stringset_5F_map * result = (cMapElement_stringset_5F_map *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_stringset_5F_map) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_stringset_5F_map::cEnumerator_stringset_5F_map (const GALGAS_stringset_5F_map & inEnumeratedObject,
                                                            const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map_2D_element cEnumerator_stringset_5F_map::current (LOCATION_ARGS) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
  return GALGAS_stringset_5F_map_2D_element (p->mAttribute_lkey, p->mAttribute_ids) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_stringset_5F_map::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset cEnumerator_stringset_5F_map::current_ids (LOCATION_ARGS) const {
  const cMapElement_stringset_5F_map * p = (const cMapElement_stringset_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_stringset_5F_map) ;
  return p->mAttribute_ids ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @stringset_map type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringset_5F_map ("stringset_map",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_stringset_5F_map::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringset_5F_map ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_stringset_5F_map::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringset_5F_map (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map GALGAS_stringset_5F_map::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_stringset_5F_map result ;
  const GALGAS_stringset_5F_map * p = (const GALGAS_stringset_5F_map *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringset_5F_map *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringset_map", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@ident_5F_list' list                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cCollectionElement_ident_5F_list : public cCollectionElement {
  public : GALGAS_ident_5F_list_2D_element mObject ;

//--- Constructor
  public : cCollectionElement_ident_5F_list (const GALGAS_lstring & in_obj_5F_name
                                             COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement_ident_5F_list::cCollectionElement_ident_5F_list (const GALGAS_lstring & in_obj_5F_name
                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_obj_5F_name) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cCollectionElement_ident_5F_list::isValid (void) const {
  return mObject.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cCollectionElement * cCollectionElement_ident_5F_list::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_ident_5F_list (mObject.mAttribute_obj_5F_name COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cCollectionElement_ident_5F_list::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "obj_name" ":" ;
  mObject.mAttribute_obj_5F_name.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cCollectionElement_ident_5F_list::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_ident_5F_list * operand = (cCollectionElement_ident_5F_list *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_ident_5F_list) ;
  return mObject.objectCompare (operand->mObject) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list::GALGAS_ident_5F_list (void) :
AC_GALGAS_list () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list::GALGAS_ident_5F_list (cSharedList * inSharedListPtr) :
AC_GALGAS_list (inSharedListPtr) {
  if (NULL == inSharedListPtr) {
    createNewEmptyList (HERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::constructor_emptyList (LOCATION_ARGS) {
  GALGAS_ident_5F_list result ;
  result.createNewEmptyList (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::constructor_listWithValue (const GALGAS_lstring & inOperand0
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list result ;
  if (inOperand0.isValid ()) {
    result.createNewEmptyList (THERE) ;
    capCollectionElement attributes ;
    GALGAS_ident_5F_list::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.addObject (attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                      const GALGAS_lstring & in_obj_5F_name
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement_ident_5F_list * p = NULL ;
  macroMyNew (p, cCollectionElement_ident_5F_list (in_obj_5F_name COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::addAssign_operation (const GALGAS_lstring & inOperand0
                                                COMMA_LOCATION_ARGS) {
  if (isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_ident_5F_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObject (attributes) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::setter_insertAtIndex (const GALGAS_lstring inOperand0,
                                                 const GALGAS_uint inInsertionIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inInsertionIndex.isValid () && inOperand0.isValid ()) {
    cCollectionElement * p = NULL ;
    macroMyNew (p, cCollectionElement_ident_5F_list (inOperand0 COMMA_THERE)) ;
    capCollectionElement attributes ;
    attributes.setPointer (p) ;
    macroDetachSharedObject (p) ;
    addObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::setter_removeAtIndex (GALGAS_lstring & outOperand0,
                                                 const GALGAS_uint inRemoveIndex,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (isValid () && inRemoveIndex.isValid ()) {
    capCollectionElement attributes ;
    removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
    cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
    if (NULL == p) {
      outOperand0.drop () ;
    }else{
      macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
      outOperand0 = p->mObject.mAttribute_obj_5F_name ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::setter_popFirst (GALGAS_lstring & outOperand0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mAttribute_obj_5F_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::setter_popLast (GALGAS_lstring & outOperand0,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mAttribute_obj_5F_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::method_first (GALGAS_lstring & outOperand0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mAttribute_obj_5F_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::method_last (GALGAS_lstring & outOperand0,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    outOperand0 = p->mObject.mAttribute_obj_5F_name ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::add_operation (const GALGAS_ident_5F_list & inOperand,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::getter_subListWithRange (const GALGAS_range & inRange,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result = GALGAS_ident_5F_list::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result = GALGAS_ident_5F_list::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list result = GALGAS_ident_5F_list::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list::plusAssign_operation (const GALGAS_ident_5F_list inOperand,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_ident_5F_list::getter_obj_5F_nameAtIndex (const GALGAS_uint & inIndex,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_ident_5F_list * p = (cCollectionElement_ident_5F_list *) attributes.ptr () ;
  GALGAS_lstring result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
    result = p->mObject.mAttribute_obj_5F_name ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_ident_5F_list::cEnumerator_ident_5F_list (const GALGAS_ident_5F_list & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_2D_element cEnumerator_ident_5F_list::current (LOCATION_ARGS) const {
  const cCollectionElement_ident_5F_list * p = (const cCollectionElement_ident_5F_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
  return p->mObject ;
}


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_ident_5F_list::current_obj_5F_name (LOCATION_ARGS) const {
  const cCollectionElement_ident_5F_list * p = (const cCollectionElement_ident_5F_list *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_ident_5F_list) ;
  return p->mObject.mAttribute_obj_5F_name ;
}




//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @ident_list type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list ("ident_list",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ident_5F_list::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ident_5F_list::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list result ;
  const GALGAS_ident_5F_list * p = (const GALGAS_ident_5F_list *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_ident_5F_list_5F_map::cMapElement_ident_5F_list_5F_map (const GALGAS_lstring & inKey,
                                                                    const GALGAS_ident_5F_list & in_objs
                                                                    COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_objs (in_objs) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_ident_5F_list_5F_map::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_objs.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_ident_5F_list_5F_map::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_ident_5F_list_5F_map (mAttribute_lkey, mAttribute_objs COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_ident_5F_list_5F_map::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "objs" ":" ;
  mAttribute_objs.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_ident_5F_list_5F_map::compare (const cCollectionElement * inOperand) const {
  cMapElement_ident_5F_list_5F_map * operand = (cMapElement_ident_5F_list_5F_map *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_objs.objectCompare (operand->mAttribute_objs) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map::GALGAS_ident_5F_list_5F_map (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map::GALGAS_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map & GALGAS_ident_5F_list_5F_map::operator = (const GALGAS_ident_5F_list_5F_map & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::constructor_mapWithMapToOverride (const GALGAS_ident_5F_list_5F_map & inMapToOverride
                                                                                           COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::getter_overriddenMap (C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const {
  GALGAS_ident_5F_list_5F_map result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::addAssign_operation (const GALGAS_lstring & inKey,
                                                       const GALGAS_ident_5F_list & inArgument0,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cMapElement_ident_5F_list_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_ident_5F_list_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@ident_5F_list_5F_map insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::setter_add (GALGAS_lstring inKey,
                                              GALGAS_ident_5F_list inArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  cMapElement_ident_5F_list_5F_map * p = NULL ;
  macroMyNew (p, cMapElement_ident_5F_list_5F_map (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "Key %K is already used there" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_ident_5F_list_5F_map_get = "Key %K is not there" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::method_get (GALGAS_lstring inKey,
                                              GALGAS_ident_5F_list & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) performSearch (inKey,
                                                                                                           inCompiler,
                                                                                                           kSearchErrorMessage_ident_5F_list_5F_map_get
                                                                                                           COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    outArgument0 = p->mAttribute_objs ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::setter_delete (GALGAS_lstring inKey,
                                                 GALGAS_ident_5F_list & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "Key %K cannot be deleted" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_ident_5F_list_5F_map * p = (cMapElement_ident_5F_list_5F_map *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    outArgument0 = p->mAttribute_objs ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list_5F_map::getter_objsForKey (const GALGAS_string & inKey,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) attributes ;
  GALGAS_ident_5F_list result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    result = p->mAttribute_objs ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map::setter_setObjsForKey (GALGAS_ident_5F_list inAttributeValue,
                                                        GALGAS_string inKey,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_ident_5F_list_5F_map * p = (cMapElement_ident_5F_list_5F_map *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
    p->mAttribute_objs = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_ident_5F_list_5F_map * GALGAS_ident_5F_list_5F_map::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                   const GALGAS_string & inKey
                                                                                                   COMMA_LOCATION_ARGS) {
  cMapElement_ident_5F_list_5F_map * result = (cMapElement_ident_5F_list_5F_map *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_ident_5F_list_5F_map) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_ident_5F_list_5F_map::cEnumerator_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map_2D_element cEnumerator_ident_5F_list_5F_map::current (LOCATION_ARGS) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
  return GALGAS_ident_5F_list_5F_map_2D_element (p->mAttribute_lkey, p->mAttribute_objs) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_ident_5F_list_5F_map::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list cEnumerator_ident_5F_list_5F_map::current_objs (LOCATION_ARGS) const {
  const cMapElement_ident_5F_list_5F_map * p = (const cMapElement_ident_5F_list_5F_map *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_ident_5F_list_5F_map) ;
  return p->mAttribute_objs ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @ident_list_map type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list_5F_map ("ident_list_map",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ident_5F_list_5F_map::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list_5F_map ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ident_5F_list_5F_map::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list_5F_map (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map GALGAS_ident_5F_list_5F_map::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map result ;
  const GALGAS_ident_5F_list_5F_map * p = (const GALGAS_ident_5F_list_5F_map *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list_5F_map *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list_map", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_objectsMap::cMapElement_objectsMap (const GALGAS_lstring & inKey,
                                                const GALGAS_objectKind & in_objectsOfKind
                                                COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_objectsOfKind (in_objectsOfKind) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_objectsMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_objectsOfKind.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_objectsMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_objectsMap (mAttribute_lkey, mAttribute_objectsOfKind COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_objectsMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "objectsOfKind" ":" ;
  mAttribute_objectsOfKind.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_objectsMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_objectsMap * operand = (cMapElement_objectsMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_objectsOfKind.objectCompare (operand->mAttribute_objectsOfKind) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap::GALGAS_objectsMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap::GALGAS_objectsMap (const GALGAS_objectsMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap & GALGAS_objectsMap::operator = (const GALGAS_objectsMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_objectsMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_objectsMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_objectsMap::constructor_mapWithMapToOverride (const GALGAS_objectsMap & inMapToOverride
                                                                       COMMA_LOCATION_ARGS) {
  GALGAS_objectsMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_objectsMap::getter_overriddenMap (C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_objectsMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::addAssign_operation (const GALGAS_lstring & inKey,
                                             const GALGAS_objectKind & inArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  cMapElement_objectsMap * p = NULL ;
  macroMyNew (p, cMapElement_objectsMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@objectsMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::setter_put (GALGAS_lstring inKey,
                                    GALGAS_objectKind inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  cMapElement_objectsMap * p = NULL ;
  macroMyNew (p, cMapElement_objectsMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_objectsMap_get = "%K does not exists" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::method_get (GALGAS_lstring inKey,
                                    GALGAS_objectKind & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) performSearch (inKey,
                                                                                       inCompiler,
                                                                                       kSearchErrorMessage_objectsMap_get
                                                                                       COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    outArgument0 = p->mAttribute_objectsOfKind ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::setter_del (GALGAS_lstring inKey,
                                    GALGAS_objectKind & outArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_objectsMap * p = (cMapElement_objectsMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    outArgument0 = p->mAttribute_objectsOfKind ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind GALGAS_objectsMap::getter_objectsOfKindForKey (const GALGAS_string & inKey,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) attributes ;
  GALGAS_objectKind result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    result = p->mAttribute_objectsOfKind ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap::setter_setObjectsOfKindForKey (GALGAS_objectKind inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_objectsMap * p = (cMapElement_objectsMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectsMap) ;
    p->mAttribute_objectsOfKind = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_objectsMap * GALGAS_objectsMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                               const GALGAS_string & inKey
                                                                               COMMA_LOCATION_ARGS) {
  cMapElement_objectsMap * result = (cMapElement_objectsMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_objectsMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_objectsMap::cEnumerator_objectsMap (const GALGAS_objectsMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap_2D_element cEnumerator_objectsMap::current (LOCATION_ARGS) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectsMap) ;
  return GALGAS_objectsMap_2D_element (p->mAttribute_lkey, p->mAttribute_objectsOfKind) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_objectsMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind cEnumerator_objectsMap::current_objectsOfKind (LOCATION_ARGS) const {
  const cMapElement_objectsMap * p = (const cMapElement_objectsMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectsMap) ;
  return p->mAttribute_objectsOfKind ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @objectsMap type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectsMap ("objectsMap",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_objectsMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectsMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_objectsMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectsMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap GALGAS_objectsMap::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_objectsMap result ;
  const GALGAS_objectsMap * p = (const GALGAS_objectsMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectsMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectsMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_objectKindMap::cMapElement_objectKindMap (const GALGAS_lstring & inKey,
                                                      const GALGAS_objectAttributes & in_attributes
                                                      COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mAttribute_attributes (in_attributes) {
}

//---------------------------------------------------------------------------------------------------------------------*

bool cMapElement_objectKindMap::isValid (void) const {
  return mAttribute_lkey.isValid () && mAttribute_attributes.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement * cMapElement_objectKindMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_objectKindMap (mAttribute_lkey, mAttribute_attributes COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cMapElement_objectKindMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "attributes" ":" ;
  mAttribute_attributes.description (ioString, inIndentation) ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cMapElement_objectKindMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_objectKindMap * operand = (cMapElement_objectKindMap *) inOperand ;
  typeComparisonResult result = mAttribute_lkey.objectCompare (operand->mAttribute_lkey) ;
  if (kOperandEqual == result) {
    result = mAttribute_attributes.objectCompare (operand->mAttribute_attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap::GALGAS_objectKindMap (void) :
AC_GALGAS_map () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap::GALGAS_objectKindMap (const GALGAS_objectKindMap & inSource) :
AC_GALGAS_map (inSource) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap & GALGAS_objectKindMap::operator = (const GALGAS_objectKindMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap GALGAS_objectKindMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_objectKindMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap GALGAS_objectKindMap::constructor_mapWithMapToOverride (const GALGAS_objectKindMap & inMapToOverride
                                                                             COMMA_LOCATION_ARGS) {
  GALGAS_objectKindMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap GALGAS_objectKindMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_objectKindMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                const GALGAS_objectAttributes & inArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  cMapElement_objectKindMap * p = NULL ;
  macroMyNew (p, cMapElement_objectKindMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@objectKindMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::setter_put (GALGAS_lstring inKey,
                                       GALGAS_objectAttributes inArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  cMapElement_objectKindMap * p = NULL ;
  macroMyNew (p, cMapElement_objectKindMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "%K is duplicated in %L" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

const char * kSearchErrorMessage_objectKindMap_get = "%K does not exists" ;

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::method_get (GALGAS_lstring inKey,
                                       GALGAS_objectAttributes & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) performSearch (inKey,
                                                                                             inCompiler,
                                                                                             kSearchErrorMessage_objectKindMap_get
                                                                                             COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    outArgument0 = p->mAttribute_attributes ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::setter_del (GALGAS_lstring inKey,
                                       GALGAS_objectAttributes & outArgument0,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "%K does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_objectKindMap * p = (cMapElement_objectKindMap *) attributes.ptr () ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    outArgument0 = p->mAttribute_attributes ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes GALGAS_objectKindMap::getter_attributesForKey (const GALGAS_string & inKey,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) attributes ;
  GALGAS_objectAttributes result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    result = p->mAttribute_attributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap::setter_setAttributesForKey (GALGAS_objectAttributes inAttributeValue,
                                                       GALGAS_string inKey,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  cMapElement_objectKindMap * p = (cMapElement_objectKindMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_objectKindMap) ;
    p->mAttribute_attributes = inAttributeValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

cMapElement_objectKindMap * GALGAS_objectKindMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                     const GALGAS_string & inKey
                                                                                     COMMA_LOCATION_ARGS) {
  cMapElement_objectKindMap * result = (cMapElement_objectKindMap *) searchForReadWriteAttribute (inKey, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_objectKindMap) ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

cEnumerator_objectKindMap::cEnumerator_objectKindMap (const GALGAS_objectKindMap & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator () {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray, inOrder) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap_2D_element cEnumerator_objectKindMap::current (LOCATION_ARGS) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectKindMap) ;
  return GALGAS_objectKindMap_2D_element (p->mAttribute_lkey, p->mAttribute_attributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cEnumerator_objectKindMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mAttribute_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes cEnumerator_objectKindMap::current_attributes (LOCATION_ARGS) const {
  const cMapElement_objectKindMap * p = (const cMapElement_objectKindMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_objectKindMap) ;
  return p->mAttribute_attributes ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @objectKindMap type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectKindMap ("objectKindMap",
                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_objectKindMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKindMap ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_objectKindMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectKindMap (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap GALGAS_objectKindMap::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_objectKindMap result ;
  const GALGAS_objectKindMap * p = (const GALGAS_objectKindMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectKindMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectKindMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_start_i0_ (C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_implementation var_imp_955 = GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 39))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 39)) ;
  GALGAS_applicationDefinition var_application_1049 = function_emptyApplicationDefinition (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 40)) ;
  GALGAS_string var_fileIncludeList_1107 = GALGAS_string::makeEmptyString () ;
  GALGAS_lstring var_version_1178 ;
  GALGAS_lstring var_desc_1194 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 46)) ;
  nt_OIL_5F_version_ (var_version_1178, var_desc_1194, inCompiler) ;
  {
  var_application_1049.setter_setVersion (var_version_1178 COMMA_SOURCE_FILE ("goil_syntax.galgas", 48)) ;
  }
  {
  var_application_1049.setter_setVersionDescription (var_desc_1194 COMMA_SOURCE_FILE ("goil_syntax.galgas", 49)) ;
  }
  GALGAS_string var_config_5F_file_5F_name_1358 = GALGAS_string (gOption_goil_5F_options_config.getter_value ()) ;
  GALGAS_stringlist var_configFiles_1452 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_1358.add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 54)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 54)) ;
  cEnumerator_stringlist enumerator_1663 (var_configFiles_1452, kEnumeration_down) ;
  while (enumerator_1663.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_1663.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 58)), var_imp_955, var_application_1049, var_fileIncludeList_1107, GALGAS_bool (false)  COMMA_SOURCE_FILE ("goil_syntax.galgas", 58)) ;
    enumerator_1663.gotoNextObject () ;
  }
  GALGAS_stringlist var_configVersionFiles_1868 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_1358.add_operation (var_version_1178.getter_string (SOURCE_FILE ("goil_syntax.galgas", 62)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 62)).add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 62)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 62)) ;
  cEnumerator_stringlist enumerator_1981 (var_configVersionFiles_1868, kEnumeration_down) ;
  while (enumerator_1981.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_1981.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 65)), var_imp_955, var_application_1049, var_fileIncludeList_1107, GALGAS_bool (false)  COMMA_SOURCE_FILE ("goil_syntax.galgas", 65)) ;
    enumerator_1981.gotoNextObject () ;
  }
  nt_file_ (var_imp_955, var_application_1049, var_fileIncludeList_1107, GALGAS_bool (true), inCompiler) ;
  callExtensionMethod_checkObjectReferences ((const cPtr_implementation *) var_imp_955.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 83)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 85)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_setDefaults (var_imp_955, var_application_1049, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 86)) ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 93)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    routine_verifyAll (var_imp_955, var_application_1049, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 94)) ;
    }
  }
  const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("goil_syntax.galgas", 96)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_2) {
    GALGAS_gtlData var_templateData_2847 = callExtensionGetter_templateData ((const cPtr_applicationDefinition *) var_application_1049.ptr (), var_imp_955, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 97)) ;
    {
    routine_generate_5F_all (var_templateData_2847, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 100)) ;
    }
  }
  var_fileIncludeList_1107 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)).getter_lastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 103)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)).add_operation (var_fileIncludeList_1107, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 103)) ;
  GALGAS_string var_oilDepFileName_3150 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 104)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 104)).add_operation (GALGAS_string ("/build/"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 104)).add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 105)).getter_lastPathComponent (SOURCE_FILE ("goil_syntax.galgas", 105)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 105)).add_operation (GALGAS_string (".dep"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 105)) ;
  var_fileIncludeList_1107.method_writeToFile (var_oilDepFileName_3150, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 107)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_start_i0_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_OIL_5F_version_parse (inCompiler) ;
  nt_file_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_file_i1_ (GALGAS_implementation & ioArgument_imp,
                                                           GALGAS_applicationDefinition & ioArgument_application,
                                                           GALGAS_string & ioArgument_fileIncludeList,
                                                           const GALGAS_bool constinArgument_rootFile,
                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  const enumGalgasBool test_0 = constinArgument_rootFile.operator_not (SOURCE_FILE ("goil_syntax.galgas", 116)).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_fileIncludeList.plusAssign_operation(GALGAS_string (" \\\n"
      " ").add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 117)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 117)), inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 117)) ;
  }
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_goil_5F_syntax_0 (inCompiler)) {
    case 2: {
      nt_include_5F_file_5F_level_ (ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false), inCompiler) ;
    } break ;
    case 3: {
      nt_implementation_5F_definition_ (ioArgument_imp, inCompiler) ;
    } break ;
    case 4: {
      nt_application_5F_definition_ (ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false), inCompiler) ;
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_file_i1_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_0 (inCompiler)) {
    case 2: {
      nt_include_5F_file_5F_level_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_implementation_5F_definition_parse (inCompiler) ;
    } break ;
    case 4: {
      nt_application_5F_definition_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_sign_i2_ (GALGAS_bool & outArgument_signed,
                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_signed.drop () ; // Release 'out' argument
  switch (select_goil_5F_syntax_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 128)) ;
    outArgument_signed = GALGAS_bool (true) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 130)) ;
    outArgument_signed = GALGAS_bool (false) ;
  } break ;
  case 3: {
    outArgument_signed = GALGAS_bool (false) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_sign_i2_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 128)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 130)) ;
  } break ;
  case 3: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_description_i3_ (GALGAS_lstring & outArgument_desc,
                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_desc.drop () ; // Release 'out' argument
  switch (select_goil_5F_syntax_2 (inCompiler)) {
  case 1: {
    outArgument_desc = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 141)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 143)) ;
    GALGAS_lstring var_partialString_4132 ;
    var_partialString_4132 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 145)) ;
    GALGAS_string var_result_4179 = var_partialString_4132.getter_string (SOURCE_FILE ("goil_syntax.galgas", 146)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_goil_5F_syntax_3 (inCompiler)) {
      case 2: {
        var_partialString_4132 = inCompiler->synthetizedAttribute_a_5F_string () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 149)) ;
        GALGAS_string var_toappend_4278 = var_partialString_4132.getter_string (SOURCE_FILE ("goil_syntax.galgas", 150)) ;
        const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_result_4179.getter_rightSubString (GALGAS_uint ((uint32_t) 2U) COMMA_SOURCE_FILE ("goil_syntax.galgas", 151)).objectCompare (GALGAS_string ("\\n"))).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_toappend_4278 = GALGAS_string (" ").add_operation (var_toappend_4278, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 152)) ;
        }
        var_result_4179.plusAssign_operation(var_toappend_4278, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 154)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    outArgument_desc = GALGAS_lstring::constructor_new (var_result_4179.getter_stringByReplacingStringByString (GALGAS_string ("\\n"), GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 156)), var_partialString_4132.getter_location (SOURCE_FILE ("goil_syntax.galgas", 156))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 156)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_description_i3_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_2 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 143)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 145)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_goil_5F_syntax_3 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 149)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_OIL_5F_version_i4_ (GALGAS_lstring & outArgument_version,
                                                                     GALGAS_lstring & outArgument_desc,
                                                                     C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_version.drop () ; // Release 'out' argument
  outArgument_desc.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  outArgument_version = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  nt_description_ (outArgument_desc, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_OIL_5F_version_i4_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  nt_description_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 164)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_application_5F_definition_i5_ (const GALGAS_implementation constinArgument_imp,
                                                                                GALGAS_applicationDefinition & ioArgument_application,
                                                                                GALGAS_string & ioArgument_fileIncludeList,
                                                                                const GALGAS_bool constinArgument_rootFile,
                                                                                C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  GALGAS_lstring var_cpuName_5078 = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  GALGAS_objectsMap var_objects_5104 = ioArgument_application.getter_objects (SOURCE_FILE ("goil_syntax.galgas", 177)) ;
  nt_object_5F_definition_5F_list_ (constinArgument_imp, var_objects_5104, ioArgument_fileIncludeList, constinArgument_rootFile, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  GALGAS_lstring joker_5220 ; // Joker input parameter
  nt_description_ (joker_5220, inCompiler) ;
  joker_5220.drop () ; // Release temporary input variables (joker in source)
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  {
  ioArgument_application.setter_setName (var_cpuName_5078 COMMA_SOURCE_FILE ("goil_syntax.galgas", 180)) ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_5104 COMMA_SOURCE_FILE ("goil_syntax.galgas", 181)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_application_5F_definition_i5_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 176)) ;
  nt_object_5F_definition_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  nt_description_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 179)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_object_5F_definition_5F_list_i6_ (const GALGAS_implementation constinArgument_imp,
                                                                                   GALGAS_objectsMap & ioArgument_objects,
                                                                                   GALGAS_string & ioArgument_fileIncludeList,
                                                                                   const GALGAS_bool constinArgument_rootFile,
                                                                                   C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_4 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_objectKind_5486 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 192)) ;
      GALGAS_implementationObject var_impObjOfKind_5525 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), var_objectKind_5486.getter_string (SOURCE_FILE ("goil_syntax.galgas", 193)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 193)) ;
      GALGAS_objectKind var_objectsForKind_5598 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 194))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 194)) ;
      const enumGalgasBool test_1 = ioArgument_objects.getter_hasKey (var_objectKind_5486.getter_string (SOURCE_FILE ("goil_syntax.galgas", 195)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 195)).boolEnum () ;
      if (kBoolTrue == test_1) {
        const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_impObjOfKind_5525.getter_multiple (SOURCE_FILE ("goil_syntax.galgas", 199)).getter_bool (SOURCE_FILE ("goil_syntax.galgas", 199)).objectCompare (GALGAS_bool (false))).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)), GALGAS_string ("object ").add_operation (var_objectKind_5486.getter_string (SOURCE_FILE ("goil_syntax.galgas", 200)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)).add_operation (GALGAS_string (" may not have multiple instance"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)), fixItArray3  COMMA_SOURCE_FILE ("goil_syntax.galgas", 200)) ;
        }
        {
        ioArgument_objects.setter_del (var_objectKind_5486, var_objectsForKind_5598, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 202)) ;
        }
      }
      GALGAS_lstring var_objectName_6100 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 204)) ;
      GALGAS_objectAttributes var_object_6129 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 205)) ;
      GALGAS_objectKindMap var_objectsKind_6176 = var_objectsForKind_5598.getter_objects (SOURCE_FILE ("goil_syntax.galgas", 206)) ;
      const enumGalgasBool test_4 = var_objectsKind_6176.getter_hasKey (var_objectName_6100.getter_string (SOURCE_FILE ("goil_syntax.galgas", 207)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 207)).boolEnum () ;
      if (kBoolTrue == test_4) {
        {
        var_objectsKind_6176.setter_del (var_objectName_6100, var_object_6129, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 208)) ;
        }
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 210)) ;
      nt_oil_5F_declaration_5F_list_ (var_impObjOfKind_5525.getter_attributes (SOURCE_FILE ("goil_syntax.galgas", 211)), var_object_6129, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 212)) ;
      GALGAS_lstring var_oil_5F_desc_6431 ;
      nt_description_ (var_oil_5F_desc_6431, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 214)) ;
      GALGAS_identifierMap var_attributes_6469 = var_object_6129.getter_objectParams (SOURCE_FILE ("goil_syntax.galgas", 215)) ;
      const enumGalgasBool test_5 = var_attributes_6469.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("goil_syntax.galgas", 216)).operator_not (SOURCE_FILE ("goil_syntax.galgas", 216)).boolEnum () ;
      if (kBoolTrue == test_5) {
        {
        var_attributes_6469.setter_put (GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), var_objectName_6100.getter_location (SOURCE_FILE ("goil_syntax.galgas", 217))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 217)), GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_6431, var_objectName_6100.getter_location (SOURCE_FILE ("goil_syntax.galgas", 217)), var_objectName_6100.getter_string (SOURCE_FILE ("goil_syntax.galgas", 217))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 217)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 217)) ;
        }
        {
        var_object_6129.setter_setObjectParams (var_attributes_6469 COMMA_SOURCE_FILE ("goil_syntax.galgas", 218)) ;
        }
      }
      {
      var_objectsKind_6176.setter_put (var_objectName_6100, var_object_6129, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 220)) ;
      }
      {
      var_objectsForKind_5598.setter_setObjects (var_objectsKind_6176 COMMA_SOURCE_FILE ("goil_syntax.galgas", 221)) ;
      }
      {
      ioArgument_objects.setter_put (var_objectKind_5486, var_objectsForKind_5598, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 222)) ;
      }
    } break ;
    case 3: {
      nt_include_5F_cpu_5F_level_ (constinArgument_imp, ioArgument_objects, ioArgument_fileIncludeList, constinArgument_rootFile, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 192)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 204)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 210)) ;
      nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 212)) ;
      nt_description_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 214)) ;
    } break ;
    case 3: {
      nt_include_5F_cpu_5F_level_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_boolean_i7_ (GALGAS_lbool & outArgument_val,
                                                              C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_val.drop () ; // Release 'out' argument
  switch (select_goil_5F_syntax_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_SOURCE_FILE ("goil_syntax.galgas", 232)) ;
    outArgument_val = GALGAS_lbool::constructor_new (GALGAS_bool (true), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 233))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 233)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_SOURCE_FILE ("goil_syntax.galgas", 235)) ;
    outArgument_val = GALGAS_lbool::constructor_new (GALGAS_bool (false), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 236))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 236)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_boolean_i7_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_SOURCE_FILE ("goil_syntax.galgas", 232)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_SOURCE_FILE ("goil_syntax.galgas", 235)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                                                 GALGAS_objectAttributes & ioArgument_identifiers,
                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_6 (inCompiler)) {
    case 2: {
      nt_oil_5F_declaration_ (constinArgument_types, ioArgument_identifiers, inCompiler) ;
    } break ;
    case 3: {
      nt_include_5F_object_5F_level_ (constinArgument_types, ioArgument_identifiers, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_goil_5F_syntax_6 (inCompiler)) {
    case 2: {
      nt_oil_5F_declaration_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_include_5F_object_5F_level_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_i9_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                                         GALGAS_objectAttributes & ioArgument_identifiers,
                                                                         C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_lstring var_idf_7642 ;
  GALGAS_object_5F_t var_val_7658 ;
  var_idf_7642 = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 257)) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("goil_syntax.galgas", 261)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 261))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 261)) ;
  GALGAS_impType var_type_7730 = GALGAS_impVoid::constructor_new (temp_0, GALGAS_dataType::constructor_void (SOURCE_FILE ("goil_syntax.galgas", 261)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 261)), GALGAS_bool (false), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("goil_syntax.galgas", 261))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 261)) ;
  GALGAS_bool var_typeOk_7829 = GALGAS_bool (false) ;
  const enumGalgasBool test_1 = constinArgument_types.getter_hasKey (var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 263)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 263)).boolEnum () ;
  if (kBoolTrue == test_1) {
    constinArgument_types.method_get (var_idf_7642, var_type_7730, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 264)) ;
    var_typeOk_7829 = GALGAS_bool (true) ;
  }else if (kBoolFalse == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 267)), var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 267)).add_operation (GALGAS_string (" is not declared in the IMPLEMENTATION"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 267)), fixItArray2  COMMA_SOURCE_FILE ("goil_syntax.galgas", 267)) ;
  }
  switch (select_goil_5F_syntax_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 270)) ;
    switch (select_goil_5F_syntax_8 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_value_8113 ;
      var_value_8113 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 274)) ;
      GALGAS_implementationObjectMap var_subTypes_8151 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 275)) ;
      GALGAS_objectAttributes var_subAttributes_8228 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 276)) ;
      switch (var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 277)).enumValue ()) {
      case GALGAS_dataType::kNotBuilt:
        break ;
      case GALGAS_dataType::kEnum_enumeration:
        {
          if (var_type_7730.isValid ()) {
            if (var_type_7730.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
              GALGAS_impEnumType cast_8353_enumType ((cPtr_impEnumType *) var_type_7730.ptr ()) ;
              const enumGalgasBool test_3 = cast_8353_enumType.getter_valuesMap (SOURCE_FILE ("goil_syntax.galgas", 281)).getter_hasKey (var_value_8113.getter_string (SOURCE_FILE ("goil_syntax.galgas", 281)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 281)).boolEnum () ;
              if (kBoolTrue == test_3) {
                cast_8353_enumType.getter_valuesMap (SOURCE_FILE ("goil_syntax.galgas", 282)).method_get (var_value_8113, var_subTypes_8151, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 282)) ;
              }else if (kBoolFalse == test_3) {
                TC_Array <C_FixItDescription> fixItArray4 ;
                inCompiler->emitSemanticError (var_value_8113.getter_location (SOURCE_FILE ("goil_syntax.galgas", 284)), var_value_8113.getter_string (SOURCE_FILE ("goil_syntax.galgas", 284)).add_operation (GALGAS_string (" ENUM value undeclared. One of the following values are expected: "), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 284)).add_operation (function_valueList (cast_8353_enumType.getter_valuesMap (SOURCE_FILE ("goil_syntax.galgas", 284)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 284)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 284)), fixItArray4  COMMA_SOURCE_FILE ("goil_syntax.galgas", 284)) ;
              }
            }
          }
        }
        break ;
      case GALGAS_dataType::kEnum_identifier:
        {
        }
        break ;
      case GALGAS_dataType::kEnum_objectType:
        {
        }
        break ;
      case GALGAS_dataType::kEnum_void:
      case GALGAS_dataType::kEnum_uint_33__32_Number:
      case GALGAS_dataType::kEnum_sint_33__32_Number:
      case GALGAS_dataType::kEnum_uint_36__34_Number:
      case GALGAS_dataType::kEnum_sint_36__34_Number:
      case GALGAS_dataType::kEnum_floatNumber:
      case GALGAS_dataType::kEnum_string:
      case GALGAS_dataType::kEnum_structType:
      case GALGAS_dataType::kEnum_boolean:
        {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 290)), var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 290)).add_operation (GALGAS_string (" is not an ENUM nor and IDENTIFIER nor an object reference"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 290)), fixItArray5  COMMA_SOURCE_FILE ("goil_syntax.galgas", 290)) ;
        }
        break ;
      }
      switch (select_goil_5F_syntax_9 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 293)) ;
        nt_oil_5F_declaration_5F_list_ (var_subTypes_8151, var_subAttributes_8228, inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 295)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_oil_5F_desc_9077 ;
      nt_description_ (var_oil_5F_desc_9077, inCompiler) ;
      const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 298)).objectCompare (GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("goil_syntax.galgas", 298)))).boolEnum () ;
      if (kBoolTrue == test_6) {
        var_val_7658 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_9077, var_value_8113.getter_location (SOURCE_FILE ("goil_syntax.galgas", 299)), var_value_8113.getter_string (SOURCE_FILE ("goil_syntax.galgas", 299)), var_subAttributes_8228  COMMA_SOURCE_FILE ("goil_syntax.galgas", 299)) ;
      }else if (kBoolFalse == test_6) {
        const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 300)).objectCompare (GALGAS_dataType::constructor_objectType (SOURCE_FILE ("goil_syntax.galgas", 300)))).boolEnum () ;
        if (kBoolTrue == test_7) {
          var_val_7658 = GALGAS_objectRefAttribute::constructor_new (var_oil_5F_desc_9077, var_value_8113.getter_location (SOURCE_FILE ("goil_syntax.galgas", 301)), var_value_8113  COMMA_SOURCE_FILE ("goil_syntax.galgas", 301)) ;
        }else if (kBoolFalse == test_7) {
          var_val_7658 = GALGAS_string_5F_class::constructor_new (var_oil_5F_desc_9077, var_value_8113.getter_location (SOURCE_FILE ("goil_syntax.galgas", 303)), var_value_8113.getter_string (SOURCE_FILE ("goil_syntax.galgas", 303))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 303)) ;
        }
      }
    } break ;
    case 2: {
      GALGAS_bool var_sign_9505 ;
      nt_sign_ (var_sign_9505, inCompiler) ;
      switch (select_goil_5F_syntax_10 (inCompiler)) {
      case 1: {
        GALGAS_luint_36__34_ var_value_9583 ;
        var_value_9583 = inCompiler->synthetizedAttribute_integerNumber () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 312)) ;
        GALGAS_lstring var_oil_5F_desc_9657 ;
        nt_description_ (var_oil_5F_desc_9657, inCompiler) ;
        var_val_7658 = function_checkAndGetIntegerNumber (var_oil_5F_desc_9657, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 314)), var_value_9583, var_sign_9505, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 314)) ;
      } break ;
      case 2: {
        GALGAS_ldouble var_value_9789 ;
        var_value_9789 = inCompiler->synthetizedAttribute_floatNumber () ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 318)) ;
        GALGAS_lstring var_oil_5F_desc_9864 ;
        nt_description_ (var_oil_5F_desc_9864, inCompiler) ;
        var_val_7658 = function_checkAndGetFloatNumber (var_oil_5F_desc_9864, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 320)), var_value_9789, var_sign_9505, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 320)) ;
      } break ;
      default:
        break ;
      }
    } break ;
    case 3: {
      GALGAS_lbool var_value_9995 ;
      nt_boolean_ (var_value_9995, inCompiler) ;
      GALGAS_implementationObjectMap var_subTypes_10037 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 326)) ;
      GALGAS_objectAttributes var_subAttributes_10112 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 327)) ;
      const enumGalgasBool test_8 = GALGAS_bool (kIsNotEqual, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 328)).objectCompare (GALGAS_dataType::constructor_boolean (SOURCE_FILE ("goil_syntax.galgas", 328)))).boolEnum () ;
      if (kBoolTrue == test_8) {
        TC_Array <C_FixItDescription> fixItArray9 ;
        inCompiler->emitSemanticError (var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 329)), extensionGetter_oilType (var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 329)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 329)).add_operation (GALGAS_string (" expected, got a BOOLEAN"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 329)), fixItArray9  COMMA_SOURCE_FILE ("goil_syntax.galgas", 329)) ;
      }else if (kBoolFalse == test_8) {
        if (var_type_7730.isValid ()) {
          if (var_type_7730.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
            GALGAS_impBoolType cast_10315_boolType ((cPtr_impBoolType *) var_type_7730.ptr ()) ;
            const enumGalgasBool test_10 = var_value_9995.getter_bool (SOURCE_FILE ("goil_syntax.galgas", 333)).boolEnum () ;
            if (kBoolTrue == test_10) {
              var_subTypes_10037 = cast_10315_boolType.getter_trueSubAttributes (SOURCE_FILE ("goil_syntax.galgas", 334)) ;
            }else if (kBoolFalse == test_10) {
              var_subTypes_10037 = cast_10315_boolType.getter_falseSubAttributes (SOURCE_FILE ("goil_syntax.galgas", 336)) ;
            }
          }
        }
      }
      switch (select_goil_5F_syntax_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 341)) ;
        const enumGalgasBool test_11 = GALGAS_bool (kIsEqual, var_subTypes_10037.getter_count (SOURCE_FILE ("goil_syntax.galgas", 342)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_11) {
          TC_Array <C_FixItDescription> fixItArray12 ;
          inCompiler->emitSemanticError (var_value_9995.getter_location (SOURCE_FILE ("goil_syntax.galgas", 343)), function_stringLBool (var_value_9995, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)).add_operation (GALGAS_string (" value of "), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)).add_operation (var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 343)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)).add_operation (GALGAS_string (" has no sub-attribute"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)), fixItArray12  COMMA_SOURCE_FILE ("goil_syntax.galgas", 343)) ;
        }
        nt_oil_5F_declaration_5F_list_ (var_subTypes_10037, var_subAttributes_10112, inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 346)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      GALGAS_lstring var_oil_5F_desc_10813 ;
      nt_description_ (var_oil_5F_desc_10813, inCompiler) ;
      var_val_7658 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_10813, var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 349)), var_value_9995.getter_bool (SOURCE_FILE ("goil_syntax.galgas", 349)), var_subAttributes_10112  COMMA_SOURCE_FILE ("goil_syntax.galgas", 349)) ;
    } break ;
    case 4: {
      GALGAS_lstring var_literalString_10962 ;
      var_literalString_10962 = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 353)) ;
      GALGAS_lstring var_oil_5F_desc_11035 ;
      nt_description_ (var_oil_5F_desc_11035, inCompiler) ;
      var_val_7658 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_11035, var_literalString_10962.getter_location (SOURCE_FILE ("goil_syntax.galgas", 355)), var_literalString_10962.getter_string (SOURCE_FILE ("goil_syntax.galgas", 355))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 355)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("goil_syntax.galgas", 358)) ;
      GALGAS_lstring var_oil_5F_desc_11208 ;
      nt_description_ (var_oil_5F_desc_11208, inCompiler) ;
      const enumGalgasBool test_13 = callExtensionGetter_autoAllowed ((const cPtr_impType *) var_type_7730.ptr (), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 361)).boolEnum () ;
      if (kBoolTrue == test_13) {
        var_val_7658 = GALGAS_auto::constructor_new (var_oil_5F_desc_11208, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 362))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 362)) ;
      }else if (kBoolFalse == test_13) {
        TC_Array <C_FixItDescription> fixItArray14 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 377)), GALGAS_string ("AUTO is not allowed"), fixItArray14  COMMA_SOURCE_FILE ("goil_syntax.galgas", 377)) ;
        var_val_7658.drop () ; // Release error dropped variable
      }
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    GALGAS_lstring var_name_12039 = inCompiler->synthetizedAttribute_att_5F_token () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 381)) ;
    GALGAS_implementationObjectMap var_subTypes_12056 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("goil_syntax.galgas", 382)) ;
    GALGAS_objectAttributes var_subAttributes_12129 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 383)) ;
    const enumGalgasBool test_15 = GALGAS_bool (kIsNotEqual, var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 385)).objectCompare (GALGAS_dataType::constructor_structType (SOURCE_FILE ("goil_syntax.galgas", 385)))).boolEnum () ;
    if (kBoolTrue == test_15) {
      TC_Array <C_FixItDescription> fixItArray16 ;
      inCompiler->emitSemanticError (var_idf_7642.getter_location (SOURCE_FILE ("goil_syntax.galgas", 386)), extensionGetter_oilType (var_type_7730.getter_type (SOURCE_FILE ("goil_syntax.galgas", 386)), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 386)).add_operation (GALGAS_string (" expected, got a STRUCT"), inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 386)), fixItArray16  COMMA_SOURCE_FILE ("goil_syntax.galgas", 386)) ;
    }else if (kBoolFalse == test_15) {
      if (var_type_7730.isValid ()) {
        if (var_type_7730.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impStructType) {
          GALGAS_impStructType cast_12341_structType ((cPtr_impStructType *) var_type_7730.ptr ()) ;
          var_subTypes_12056 = cast_12341_structType.getter_structAttributes (SOURCE_FILE ("goil_syntax.galgas", 390)) ;
        }
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 393)) ;
    nt_oil_5F_declaration_5F_list_ (var_subTypes_12056, var_subAttributes_12129, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 395)) ;
    GALGAS_lstring var_oil_5F_desc_12533 ;
    nt_description_ (var_oil_5F_desc_12533, inCompiler) ;
    var_val_7658 = GALGAS_structAttribute::constructor_new (var_oil_5F_desc_12533, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 397)), var_name_12039, var_subAttributes_12129  COMMA_SOURCE_FILE ("goil_syntax.galgas", 397)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 399)) ;
  GALGAS_identifierMap var_idfs_12677 = ioArgument_identifiers.getter_objectParams (SOURCE_FILE ("goil_syntax.galgas", 402)) ;
  const enumGalgasBool test_17 = var_type_7730.getter_multiple (SOURCE_FILE ("goil_syntax.galgas", 403)).boolEnum () ;
  if (kBoolTrue == test_17) {
    const enumGalgasBool test_18 = var_idfs_12677.getter_hasKey (var_idf_7642.getter_string (SOURCE_FILE ("goil_syntax.galgas", 404)) COMMA_SOURCE_FILE ("goil_syntax.galgas", 404)).boolEnum () ;
    if (kBoolTrue == test_18) {
      GALGAS_object_5F_t var_attributeList_12801 ;
      {
      var_idfs_12677.setter_del (var_idf_7642, var_attributeList_12801, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 408)) ;
      }
      if (var_attributeList_12801.isValid ()) {
        if (var_attributeList_12801.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
          GALGAS_multipleAttribute cast_12995_multiAttribute ((cPtr_multipleAttribute *) var_attributeList_12801.ptr ()) ;
          GALGAS_identifierList var_aList_13027 = cast_12995_multiAttribute.getter_items (SOURCE_FILE ("goil_syntax.galgas", 411)) ;
          var_aList_13027.addAssign_operation (var_val_7658  COMMA_SOURCE_FILE ("goil_syntax.galgas", 412)) ;
          var_val_7658 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 413)), cast_12995_multiAttribute.getter_location (SOURCE_FILE ("goil_syntax.galgas", 413)), var_aList_13027  COMMA_SOURCE_FILE ("goil_syntax.galgas", 413)) ;
        }
      }
    }else if (kBoolFalse == test_18) {
      var_val_7658 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 416)), var_val_7658.getter_location (SOURCE_FILE ("goil_syntax.galgas", 416)), GALGAS_identifierList::constructor_listWithValue (var_val_7658  COMMA_SOURCE_FILE ("goil_syntax.galgas", 416))  COMMA_SOURCE_FILE ("goil_syntax.galgas", 416)) ;
    }
  }
  const enumGalgasBool test_19 = var_typeOk_7829.boolEnum () ;
  if (kBoolTrue == test_19) {
    {
    var_idfs_12677.setter_put (var_idf_7642, var_val_7658, inCompiler COMMA_SOURCE_FILE ("goil_syntax.galgas", 420)) ;
    }
  }
  {
  ioArgument_identifiers.setter_setObjectParams (var_idfs_12677 COMMA_SOURCE_FILE ("goil_syntax.galgas", 422)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_oil_5F_declaration_i9_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 257)) ;
  switch (select_goil_5F_syntax_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 270)) ;
    switch (select_goil_5F_syntax_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 274)) ;
      switch (select_goil_5F_syntax_9 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 293)) ;
        nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 295)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      nt_sign_parse (inCompiler) ;
      switch (select_goil_5F_syntax_10 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 312)) ;
        nt_description_parse (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("goil_syntax.galgas", 318)) ;
        nt_description_parse (inCompiler) ;
      } break ;
      default:
        break ;
      }
    } break ;
    case 3: {
      nt_boolean_parse (inCompiler) ;
      switch (select_goil_5F_syntax_11 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 341)) ;
        nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 346)) ;
      } break ;
      case 2: {
      } break ;
      default:
        break ;
      }
      nt_description_parse (inCompiler) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 353)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("goil_syntax.galgas", 358)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("goil_syntax.galgas", 381)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 393)) ;
    nt_oil_5F_declaration_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 395)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("goil_syntax.galgas", 399)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_file_5F_level_i10_ (GALGAS_implementation & ioArgument_imp,
                                                                                GALGAS_applicationDefinition & ioArgument_application,
                                                                                GALGAS_string & ioArgument_fileIncludeList,
                                                                                const GALGAS_bool constinArgument_rootFile,
                                                                                C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_13579 = GALGAS_bool (false) ;
  switch (select_goil_5F_syntax_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 433)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 435)) ;
    var_includeIfExists_13579 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_13687 ;
  switch (select_goil_5F_syntax_13 (inCompiler)) {
  case 1: {
    var_file_5F_name_13687 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 439)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_13687, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 440)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_13687 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 442)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_bool test_0 = var_includeIfExists_13579.operator_not (SOURCE_FILE ("goil_syntax.galgas", 444)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    GALGAS_bool test_1 = var_includeIfExists_13579 ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = var_file_5F_name_13687.mAttribute_string.getter_fileExists (SOURCE_FILE ("goil_syntax.galgas", 444)) ;
    }
    test_0 = test_1 ;
  }
  const enumGalgasBool test_2 = test_0.boolEnum () ;
  if (kBoolTrue == test_2) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_13687, ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, constinArgument_rootFile  COMMA_SOURCE_FILE ("goil_syntax.galgas", 445)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 433)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 435)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 439)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 442)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_ (const GALGAS_implementation constinArgument_imp,
                                                                               GALGAS_objectsMap & ioArgument_objects,
                                                                               GALGAS_string & ioArgument_fileIncludeList,
                                                                               const GALGAS_bool constinArgument_rootFile,
                                                                               C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_14126 = GALGAS_bool (false) ;
  switch (select_goil_5F_syntax_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 457)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 459)) ;
    var_includeIfExists_14126 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_14234 ;
  switch (select_goil_5F_syntax_15 (inCompiler)) {
  case 1: {
    var_file_5F_name_14234 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 463)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_14234, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 464)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_14234 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 466)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_bool test_0 = var_includeIfExists_14126.operator_not (SOURCE_FILE ("goil_syntax.galgas", 468)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    GALGAS_bool test_1 = var_includeIfExists_14126 ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = var_file_5F_name_14234.mAttribute_string.getter_fileExists (SOURCE_FILE ("goil_syntax.galgas", 468)) ;
    }
    test_0 = test_1 ;
  }
  const enumGalgasBool test_2 = test_0.boolEnum () ;
  if (kBoolTrue == test_2) {
    cGrammar_goil_5F_cpu_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_14234, constinArgument_imp, ioArgument_objects, ioArgument_fileIncludeList, constinArgument_rootFile  COMMA_SOURCE_FILE ("goil_syntax.galgas", 469)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 457)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 459)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 463)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 466)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_object_5F_level_i12_ (const GALGAS_implementationObjectMap constinArgument_types,
                                                                                  GALGAS_objectAttributes & ioArgument_identifiers,
                                                                                  C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_14641 = GALGAS_bool (false) ;
  switch (select_goil_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 479)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 481)) ;
    var_includeIfExists_14641 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_14749 ;
  switch (select_goil_5F_syntax_17 (inCompiler)) {
  case 1: {
    var_file_5F_name_14749 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 485)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_14749, inCompiler  COMMA_SOURCE_FILE ("goil_syntax.galgas", 486)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_14749 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 488)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_bool test_0 = var_includeIfExists_14641.operator_not (SOURCE_FILE ("goil_syntax.galgas", 490)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    GALGAS_bool test_1 = var_includeIfExists_14641 ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = var_file_5F_name_14749.mAttribute_string.getter_fileExists (SOURCE_FILE ("goil_syntax.galgas", 490)) ;
    }
    test_0 = test_1 ;
  }
  const enumGalgasBool test_2 = test_0.boolEnum () ;
  if (kBoolTrue == test_2) {
    cGrammar_goil_5F_object_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_14749, constinArgument_types, ioArgument_identifiers  COMMA_SOURCE_FILE ("goil_syntax.galgas", 491)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_goil_5F_syntax::rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_goil_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("goil_syntax.galgas", 479)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("goil_syntax.galgas", 481)) ;
  } break ;
  default:
    break ;
  }
  switch (select_goil_5F_syntax_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 485)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("goil_syntax.galgas", 488)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_goil_object_level_include [] = {
// At index 0 : <start>, in file 'goil_syntax.ggs', line 38
  NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 3 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 5 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (15) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 7 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (16) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 9 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 15 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 23 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 25 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (19) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 27 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 29 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 33 : <include_file_level>, in file 'goil_syntax.ggs', line 425
, NONTERMINAL (26) // <select_goil_5F_syntax_12>
, NONTERMINAL (27) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 36 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
, NONTERMINAL (28) // <select_goil_5F_syntax_14>
, NONTERMINAL (29) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 39 : <include_object_level>, in file 'goil_syntax.ggs', line 473
, NONTERMINAL (30) // <select_goil_5F_syntax_16>
, NONTERMINAL (31) // <select_goil_5F_syntax_17>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 42 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 43 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 46 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 49 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 52 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 54 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 56 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 57 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 58 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (17) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 62 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 63 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (17) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 66 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 67 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 76 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 79 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 81 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 83 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, END_PRODUCTION
// At index 84 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 87 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 90 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (22) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 93 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 99 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (23) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 103 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (3) // <sign>
, NONTERMINAL (24) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 106 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (25) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 110 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 113 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 116 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 120 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, END_PRODUCTION
// At index 121 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 124 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 127 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 131 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 134 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 136 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 146 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 150 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 154 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 156 : <>, in file '.ggs', line 0
, NONTERMINAL (9) // <oil_declaration_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_object_level_include [58] = {
 {"<start>", "goil_syntax", 0}, // at index 0
 {"<file>", "goil_syntax", 3}, // at index 1
 {"<sign>", "goil_syntax", 5}, // at index 2
 {"<description>", "goil_syntax", 7}, // at index 3
 {"<OIL_version>", "goil_syntax", 9}, // at index 4
 {"<application_definition>", "goil_syntax", 15}, // at index 5
 {"<object_definition_list>", "goil_syntax", 23}, // at index 6
 {"<boolean>", "goil_syntax", 25}, // at index 7
 {"<oil_declaration_list>", "goil_syntax", 27}, // at index 8
 {"<oil_declaration>", "goil_syntax", 29}, // at index 9
 {"<include_file_level>", "goil_syntax", 33}, // at index 10
 {"<include_cpu_level>", "goil_syntax", 36}, // at index 11
 {"<include_object_level>", "goil_syntax", 39}, // at index 12
 {"<select_goil_5F_syntax_0>", "goil_syntax", 42}, // at index 13
 {"<select_goil_5F_syntax_0>", "goil_syntax", 43}, // at index 14
 {"<select_goil_5F_syntax_0>", "goil_syntax", 46}, // at index 15
 {"<select_goil_5F_syntax_0>", "goil_syntax", 49}, // at index 16
 {"<select_goil_5F_syntax_1>", "goil_syntax", 52}, // at index 17
 {"<select_goil_5F_syntax_1>", "goil_syntax", 54}, // at index 18
 {"<select_goil_5F_syntax_1>", "goil_syntax", 56}, // at index 19
 {"<select_goil_5F_syntax_2>", "goil_syntax", 57}, // at index 20
 {"<select_goil_5F_syntax_2>", "goil_syntax", 58}, // at index 21
 {"<select_goil_5F_syntax_3>", "goil_syntax", 62}, // at index 22
 {"<select_goil_5F_syntax_3>", "goil_syntax", 63}, // at index 23
 {"<select_goil_5F_syntax_4>", "goil_syntax", 66}, // at index 24
 {"<select_goil_5F_syntax_4>", "goil_syntax", 67}, // at index 25
 {"<select_goil_5F_syntax_4>", "goil_syntax", 76}, // at index 26
 {"<select_goil_5F_syntax_5>", "goil_syntax", 79}, // at index 27
 {"<select_goil_5F_syntax_5>", "goil_syntax", 81}, // at index 28
 {"<select_goil_5F_syntax_6>", "goil_syntax", 83}, // at index 29
 {"<select_goil_5F_syntax_6>", "goil_syntax", 84}, // at index 30
 {"<select_goil_5F_syntax_6>", "goil_syntax", 87}, // at index 31
 {"<select_goil_5F_syntax_7>", "goil_syntax", 90}, // at index 32
 {"<select_goil_5F_syntax_7>", "goil_syntax", 93}, // at index 33
 {"<select_goil_5F_syntax_8>", "goil_syntax", 99}, // at index 34
 {"<select_goil_5F_syntax_8>", "goil_syntax", 103}, // at index 35
 {"<select_goil_5F_syntax_8>", "goil_syntax", 106}, // at index 36
 {"<select_goil_5F_syntax_8>", "goil_syntax", 110}, // at index 37
 {"<select_goil_5F_syntax_8>", "goil_syntax", 113}, // at index 38
 {"<select_goil_5F_syntax_9>", "goil_syntax", 116}, // at index 39
 {"<select_goil_5F_syntax_9>", "goil_syntax", 120}, // at index 40
 {"<select_goil_5F_syntax_10>", "goil_syntax", 121}, // at index 41
 {"<select_goil_5F_syntax_10>", "goil_syntax", 124}, // at index 42
 {"<select_goil_5F_syntax_11>", "goil_syntax", 127}, // at index 43
 {"<select_goil_5F_syntax_11>", "goil_syntax", 131}, // at index 44
 {"<select_goil_5F_syntax_12>", "goil_syntax", 132}, // at index 45
 {"<select_goil_5F_syntax_12>", "goil_syntax", 134}, // at index 46
 {"<select_goil_5F_syntax_13>", "goil_syntax", 136}, // at index 47
 {"<select_goil_5F_syntax_13>", "goil_syntax", 138}, // at index 48
 {"<select_goil_5F_syntax_14>", "goil_syntax", 140}, // at index 49
 {"<select_goil_5F_syntax_14>", "goil_syntax", 142}, // at index 50
 {"<select_goil_5F_syntax_15>", "goil_syntax", 144}, // at index 51
 {"<select_goil_5F_syntax_15>", "goil_syntax", 146}, // at index 52
 {"<select_goil_5F_syntax_16>", "goil_syntax", 148}, // at index 53
 {"<select_goil_5F_syntax_16>", "goil_syntax", 150}, // at index 54
 {"<select_goil_5F_syntax_17>", "goil_syntax", 152}, // at index 55
 {"<select_goil_5F_syntax_17>", "goil_syntax", 154}, // at index 56
 {"<>", "", 156} // at index 57
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_object_level_include [58] = {
0, // index 0 : <start>, in file 'goil_syntax.ggs', line 38
3, // index 1 : <file>, in file 'goil_syntax.ggs', line 110
5, // index 2 : <sign>, in file 'goil_syntax.ggs', line 126
7, // index 3 : <description>, in file 'goil_syntax.ggs', line 139
9, // index 4 : <OIL_version>, in file 'goil_syntax.ggs', line 163
15, // index 5 : <application_definition>, in file 'goil_syntax.ggs', line 170
23, // index 6 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
25, // index 7 : <boolean>, in file 'goil_syntax.ggs', line 230
27, // index 8 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
29, // index 9 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
33, // index 10 : <include_file_level>, in file 'goil_syntax.ggs', line 425
36, // index 11 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
39, // index 12 : <include_object_level>, in file 'goil_syntax.ggs', line 473
42, // index 13 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
43, // index 14 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
46, // index 15 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
49, // index 16 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
52, // index 17 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
54, // index 18 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
56, // index 19 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
57, // index 20 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
58, // index 21 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
62, // index 22 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
63, // index 23 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
66, // index 24 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
67, // index 25 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
76, // index 26 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
79, // index 27 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
81, // index 28 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
83, // index 29 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
84, // index 30 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
87, // index 31 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
90, // index 32 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
93, // index 33 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
99, // index 34 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
103, // index 35 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
106, // index 36 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
110, // index 37 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
113, // index 38 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
116, // index 39 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
120, // index 40 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
121, // index 41 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
124, // index 42 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
127, // index 43 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
131, // index 44 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
132, // index 45 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
134, // index 46 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
136, // index 47 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
138, // index 48 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
140, // index 49 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
142, // index 50 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
144, // index 51 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
146, // index 52 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
148, // index 53 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
150, // index 54 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
152, // index 55 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
154, // index 56 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
156 // index 57 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_object_level_include [34] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <sign>
3, // at 4 : <description>
4, // at 5 : <OIL_version>
5, // at 6 : <application_definition>
6, // at 7 : <object_definition_list>
7, // at 8 : <boolean>
8, // at 9 : <oil_declaration_list>
9, // at 10 : <oil_declaration>
10, // at 11 : <include_file_level>
11, // at 12 : <include_cpu_level>
12, // at 13 : <include_object_level>
13, // at 14 : <select_goil_5F_syntax_0>
17, // at 15 : <select_goil_5F_syntax_1>
20, // at 16 : <select_goil_5F_syntax_2>
22, // at 17 : <select_goil_5F_syntax_3>
24, // at 18 : <select_goil_5F_syntax_4>
27, // at 19 : <select_goil_5F_syntax_5>
29, // at 20 : <select_goil_5F_syntax_6>
32, // at 21 : <select_goil_5F_syntax_7>
34, // at 22 : <select_goil_5F_syntax_8>
39, // at 23 : <select_goil_5F_syntax_9>
41, // at 24 : <select_goil_5F_syntax_10>
43, // at 25 : <select_goil_5F_syntax_11>
45, // at 26 : <select_goil_5F_syntax_12>
47, // at 27 : <select_goil_5F_syntax_13>
49, // at 28 : <select_goil_5F_syntax_14>
51, // at 29 : <select_goil_5F_syntax_15>
53, // at 30 : <select_goil_5F_syntax_16>
55, // at 31 : <select_goil_5F_syntax_17>
57, // at 32 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_object_level_include [] = {
// At index 0 : <implementation_definition> no production
// At index 0 : <start> only one production, no choice
  -1,
// At index 1 : <file> only one production, no choice
  -1,
// At index 2 : <sign> only one production, no choice
  -1,
// At index 3 : <description> only one production, no choice
  -1,
// At index 4 : <OIL_version> only one production, no choice
  -1,
// At index 5 : <application_definition> only one production, no choice
  -1,
// At index 6 : <object_definition_list> only one production, no choice
  -1,
// At index 7 : <boolean> only one production, no choice
  -1,
// At index 8 : <oil_declaration_list> only one production, no choice
  -1,
// At index 9 : <oil_declaration> only one production, no choice
  -1,
// At index 10 : <include_file_level> only one production, no choice
  -1,
// At index 11 : <include_cpu_level> only one production, no choice
  -1,
// At index 12 : <include_object_level> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 13 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
-1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 21 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 29 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 34 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 39 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 47 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 52 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 61 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 66 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 81 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 87 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 92 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 98 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 103 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 108 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 113 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 118 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 123 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 128 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_object_level_include [34] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <sign>
3, // at 4 : <description>
4, // at 5 : <OIL_version>
5, // at 6 : <application_definition>
6, // at 7 : <object_definition_list>
7, // at 8 : <boolean>
8, // at 9 : <oil_declaration_list>
9, // at 10 : <oil_declaration>
10, // at 11 : <include_file_level>
11, // at 12 : <include_cpu_level>
12, // at 13 : <include_object_level>
13, // at 14 : <select_goil_5F_syntax_0>
21, // at 15 : <select_goil_5F_syntax_1>
29, // at 16 : <select_goil_5F_syntax_2>
34, // at 17 : <select_goil_5F_syntax_3>
39, // at 18 : <select_goil_5F_syntax_4>
47, // at 19 : <select_goil_5F_syntax_5>
52, // at 20 : <select_goil_5F_syntax_6>
61, // at 21 : <select_goil_5F_syntax_7>
66, // at 22 : <select_goil_5F_syntax_8>
81, // at 23 : <select_goil_5F_syntax_9>
87, // at 24 : <select_goil_5F_syntax_10>
92, // at 25 : <select_goil_5F_syntax_11>
98, // at 26 : <select_goil_5F_syntax_12>
103, // at 27 : <select_goil_5F_syntax_13>
108, // at 28 : <select_goil_5F_syntax_14>
113, // at 29 : <select_goil_5F_syntax_15>
118, // at 30 : <select_goil_5F_syntax_16>
123, // at 31 : <select_goil_5F_syntax_17>
128, // at 32 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * ) {
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & ,
                                C_Lexique_goil_5F_lexique * ) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_object_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_object_level_include, gProductionNames_goil_object_level_include, gProductionIndexes_goil_object_level_include,
                                    gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 156) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                const GALGAS_implementationObjectMap  parameter_1,
                                GALGAS_objectAttributes &  parameter_2
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_object_level_include, gProductionNames_goil_object_level_include, gProductionIndexes_goil_object_level_include,
                                                      gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 156) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_object_5F_level_5F_include grammar ;
        grammar.nt_oil_5F_declaration_5F_list_ (parameter_1, parameter_2, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                const GALGAS_implementationObjectMap  parameter_1,
                                GALGAS_objectAttributes &  parameter_2
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_object_level_include, gProductionNames_goil_object_level_include, gProductionIndexes_goil_object_level_include,
                                                    gFirstProductionIndexes_goil_object_level_include, gDecision_goil_object_level_include, gDecisionIndexes_goil_object_level_include, 156) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_object_5F_level_5F_include grammar ;
      grammar.nt_oil_5F_declaration_5F_list_ (parameter_1, parameter_2, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_object_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_object_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_goil_cpu_level_include [] = {
// At index 0 : <start>, in file 'goil_syntax.ggs', line 38
  NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 3 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 5 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (15) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 7 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (16) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 9 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 15 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 23 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 25 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (19) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 27 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 29 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 33 : <include_file_level>, in file 'goil_syntax.ggs', line 425
, NONTERMINAL (26) // <select_goil_5F_syntax_12>
, NONTERMINAL (27) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 36 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
, NONTERMINAL (28) // <select_goil_5F_syntax_14>
, NONTERMINAL (29) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 39 : <include_object_level>, in file 'goil_syntax.ggs', line 473
, NONTERMINAL (30) // <select_goil_5F_syntax_16>
, NONTERMINAL (31) // <select_goil_5F_syntax_17>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 42 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 43 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 46 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 49 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (14) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 52 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 54 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 56 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 57 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 58 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (17) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 62 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 63 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (17) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 66 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 67 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 76 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (18) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 79 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 81 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 83 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, END_PRODUCTION
// At index 84 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 87 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (20) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 90 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (22) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 93 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 99 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (23) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 103 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (3) // <sign>
, NONTERMINAL (24) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 106 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (25) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 110 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 113 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 116 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 120 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, END_PRODUCTION
// At index 121 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 124 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 127 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 131 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 134 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 136 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 146 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 150 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 154 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 156 : <>, in file '.ggs', line 0
, NONTERMINAL (7) // <object_definition_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_cpu_level_include [58] = {
 {"<start>", "goil_syntax", 0}, // at index 0
 {"<file>", "goil_syntax", 3}, // at index 1
 {"<sign>", "goil_syntax", 5}, // at index 2
 {"<description>", "goil_syntax", 7}, // at index 3
 {"<OIL_version>", "goil_syntax", 9}, // at index 4
 {"<application_definition>", "goil_syntax", 15}, // at index 5
 {"<object_definition_list>", "goil_syntax", 23}, // at index 6
 {"<boolean>", "goil_syntax", 25}, // at index 7
 {"<oil_declaration_list>", "goil_syntax", 27}, // at index 8
 {"<oil_declaration>", "goil_syntax", 29}, // at index 9
 {"<include_file_level>", "goil_syntax", 33}, // at index 10
 {"<include_cpu_level>", "goil_syntax", 36}, // at index 11
 {"<include_object_level>", "goil_syntax", 39}, // at index 12
 {"<select_goil_5F_syntax_0>", "goil_syntax", 42}, // at index 13
 {"<select_goil_5F_syntax_0>", "goil_syntax", 43}, // at index 14
 {"<select_goil_5F_syntax_0>", "goil_syntax", 46}, // at index 15
 {"<select_goil_5F_syntax_0>", "goil_syntax", 49}, // at index 16
 {"<select_goil_5F_syntax_1>", "goil_syntax", 52}, // at index 17
 {"<select_goil_5F_syntax_1>", "goil_syntax", 54}, // at index 18
 {"<select_goil_5F_syntax_1>", "goil_syntax", 56}, // at index 19
 {"<select_goil_5F_syntax_2>", "goil_syntax", 57}, // at index 20
 {"<select_goil_5F_syntax_2>", "goil_syntax", 58}, // at index 21
 {"<select_goil_5F_syntax_3>", "goil_syntax", 62}, // at index 22
 {"<select_goil_5F_syntax_3>", "goil_syntax", 63}, // at index 23
 {"<select_goil_5F_syntax_4>", "goil_syntax", 66}, // at index 24
 {"<select_goil_5F_syntax_4>", "goil_syntax", 67}, // at index 25
 {"<select_goil_5F_syntax_4>", "goil_syntax", 76}, // at index 26
 {"<select_goil_5F_syntax_5>", "goil_syntax", 79}, // at index 27
 {"<select_goil_5F_syntax_5>", "goil_syntax", 81}, // at index 28
 {"<select_goil_5F_syntax_6>", "goil_syntax", 83}, // at index 29
 {"<select_goil_5F_syntax_6>", "goil_syntax", 84}, // at index 30
 {"<select_goil_5F_syntax_6>", "goil_syntax", 87}, // at index 31
 {"<select_goil_5F_syntax_7>", "goil_syntax", 90}, // at index 32
 {"<select_goil_5F_syntax_7>", "goil_syntax", 93}, // at index 33
 {"<select_goil_5F_syntax_8>", "goil_syntax", 99}, // at index 34
 {"<select_goil_5F_syntax_8>", "goil_syntax", 103}, // at index 35
 {"<select_goil_5F_syntax_8>", "goil_syntax", 106}, // at index 36
 {"<select_goil_5F_syntax_8>", "goil_syntax", 110}, // at index 37
 {"<select_goil_5F_syntax_8>", "goil_syntax", 113}, // at index 38
 {"<select_goil_5F_syntax_9>", "goil_syntax", 116}, // at index 39
 {"<select_goil_5F_syntax_9>", "goil_syntax", 120}, // at index 40
 {"<select_goil_5F_syntax_10>", "goil_syntax", 121}, // at index 41
 {"<select_goil_5F_syntax_10>", "goil_syntax", 124}, // at index 42
 {"<select_goil_5F_syntax_11>", "goil_syntax", 127}, // at index 43
 {"<select_goil_5F_syntax_11>", "goil_syntax", 131}, // at index 44
 {"<select_goil_5F_syntax_12>", "goil_syntax", 132}, // at index 45
 {"<select_goil_5F_syntax_12>", "goil_syntax", 134}, // at index 46
 {"<select_goil_5F_syntax_13>", "goil_syntax", 136}, // at index 47
 {"<select_goil_5F_syntax_13>", "goil_syntax", 138}, // at index 48
 {"<select_goil_5F_syntax_14>", "goil_syntax", 140}, // at index 49
 {"<select_goil_5F_syntax_14>", "goil_syntax", 142}, // at index 50
 {"<select_goil_5F_syntax_15>", "goil_syntax", 144}, // at index 51
 {"<select_goil_5F_syntax_15>", "goil_syntax", 146}, // at index 52
 {"<select_goil_5F_syntax_16>", "goil_syntax", 148}, // at index 53
 {"<select_goil_5F_syntax_16>", "goil_syntax", 150}, // at index 54
 {"<select_goil_5F_syntax_17>", "goil_syntax", 152}, // at index 55
 {"<select_goil_5F_syntax_17>", "goil_syntax", 154}, // at index 56
 {"<>", "", 156} // at index 57
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_cpu_level_include [58] = {
0, // index 0 : <start>, in file 'goil_syntax.ggs', line 38
3, // index 1 : <file>, in file 'goil_syntax.ggs', line 110
5, // index 2 : <sign>, in file 'goil_syntax.ggs', line 126
7, // index 3 : <description>, in file 'goil_syntax.ggs', line 139
9, // index 4 : <OIL_version>, in file 'goil_syntax.ggs', line 163
15, // index 5 : <application_definition>, in file 'goil_syntax.ggs', line 170
23, // index 6 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
25, // index 7 : <boolean>, in file 'goil_syntax.ggs', line 230
27, // index 8 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
29, // index 9 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
33, // index 10 : <include_file_level>, in file 'goil_syntax.ggs', line 425
36, // index 11 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
39, // index 12 : <include_object_level>, in file 'goil_syntax.ggs', line 473
42, // index 13 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
43, // index 14 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
46, // index 15 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
49, // index 16 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
52, // index 17 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
54, // index 18 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
56, // index 19 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
57, // index 20 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
58, // index 21 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
62, // index 22 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
63, // index 23 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
66, // index 24 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
67, // index 25 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
76, // index 26 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
79, // index 27 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
81, // index 28 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
83, // index 29 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
84, // index 30 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
87, // index 31 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
90, // index 32 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
93, // index 33 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
99, // index 34 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
103, // index 35 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
106, // index 36 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
110, // index 37 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
113, // index 38 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
116, // index 39 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
120, // index 40 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
121, // index 41 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
124, // index 42 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
127, // index 43 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
131, // index 44 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
132, // index 45 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
134, // index 46 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
136, // index 47 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
138, // index 48 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
140, // index 49 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
142, // index 50 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
144, // index 51 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
146, // index 52 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
148, // index 53 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
150, // index 54 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
152, // index 55 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
154, // index 56 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
156 // index 57 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_cpu_level_include [34] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <sign>
3, // at 4 : <description>
4, // at 5 : <OIL_version>
5, // at 6 : <application_definition>
6, // at 7 : <object_definition_list>
7, // at 8 : <boolean>
8, // at 9 : <oil_declaration_list>
9, // at 10 : <oil_declaration>
10, // at 11 : <include_file_level>
11, // at 12 : <include_cpu_level>
12, // at 13 : <include_object_level>
13, // at 14 : <select_goil_5F_syntax_0>
17, // at 15 : <select_goil_5F_syntax_1>
20, // at 16 : <select_goil_5F_syntax_2>
22, // at 17 : <select_goil_5F_syntax_3>
24, // at 18 : <select_goil_5F_syntax_4>
27, // at 19 : <select_goil_5F_syntax_5>
29, // at 20 : <select_goil_5F_syntax_6>
32, // at 21 : <select_goil_5F_syntax_7>
34, // at 22 : <select_goil_5F_syntax_8>
39, // at 23 : <select_goil_5F_syntax_9>
41, // at 24 : <select_goil_5F_syntax_10>
43, // at 25 : <select_goil_5F_syntax_11>
45, // at 26 : <select_goil_5F_syntax_12>
47, // at 27 : <select_goil_5F_syntax_13>
49, // at 28 : <select_goil_5F_syntax_14>
51, // at 29 : <select_goil_5F_syntax_15>
53, // at 30 : <select_goil_5F_syntax_16>
55, // at 31 : <select_goil_5F_syntax_17>
57, // at 32 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_cpu_level_include [] = {
// At index 0 : <implementation_definition> no production
// At index 0 : <start> only one production, no choice
  -1,
// At index 1 : <file> only one production, no choice
  -1,
// At index 2 : <sign> only one production, no choice
  -1,
// At index 3 : <description> only one production, no choice
  -1,
// At index 4 : <OIL_version> only one production, no choice
  -1,
// At index 5 : <application_definition> only one production, no choice
  -1,
// At index 6 : <object_definition_list> only one production, no choice
  -1,
// At index 7 : <boolean> only one production, no choice
  -1,
// At index 8 : <oil_declaration_list> only one production, no choice
  -1,
// At index 9 : <oil_declaration> only one production, no choice
  -1,
// At index 10 : <include_file_level> only one production, no choice
  -1,
// At index 11 : <include_cpu_level> only one production, no choice
  -1,
// At index 12 : <include_object_level> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 13 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
-1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 21 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 29 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 34 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 39 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 48 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 53 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 61 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 66 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 81 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 87 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 92 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 98 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 103 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 108 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 113 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 118 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 123 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 128 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_cpu_level_include [34] = {
0, // at 0 : <implementation_definition>
0, // at 1 : <start>
1, // at 2 : <file>
2, // at 3 : <sign>
3, // at 4 : <description>
4, // at 5 : <OIL_version>
5, // at 6 : <application_definition>
6, // at 7 : <object_definition_list>
7, // at 8 : <boolean>
8, // at 9 : <oil_declaration_list>
9, // at 10 : <oil_declaration>
10, // at 11 : <include_file_level>
11, // at 12 : <include_cpu_level>
12, // at 13 : <include_object_level>
13, // at 14 : <select_goil_5F_syntax_0>
21, // at 15 : <select_goil_5F_syntax_1>
29, // at 16 : <select_goil_5F_syntax_2>
34, // at 17 : <select_goil_5F_syntax_3>
39, // at 18 : <select_goil_5F_syntax_4>
48, // at 19 : <select_goil_5F_syntax_5>
53, // at 20 : <select_goil_5F_syntax_6>
61, // at 21 : <select_goil_5F_syntax_7>
66, // at 22 : <select_goil_5F_syntax_8>
81, // at 23 : <select_goil_5F_syntax_9>
87, // at 24 : <select_goil_5F_syntax_10>
92, // at 25 : <select_goil_5F_syntax_11>
98, // at 26 : <select_goil_5F_syntax_12>
103, // at 27 : <select_goil_5F_syntax_13>
108, // at 28 : <select_goil_5F_syntax_14>
113, // at 29 : <select_goil_5F_syntax_15>
118, // at 30 : <select_goil_5F_syntax_16>
123, // at 31 : <select_goil_5F_syntax_17>
128, // at 32 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * ) {
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & ,
                                C_Lexique_goil_5F_lexique * ) {
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_cpu_level_include, gProductionNames_goil_cpu_level_include, gProductionIndexes_goil_cpu_level_include,
                                    gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 156) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                const GALGAS_implementation  parameter_1,
                                GALGAS_objectsMap &  parameter_2,
                                GALGAS_string &  parameter_3,
                                const GALGAS_bool  parameter_4
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_cpu_level_include, gProductionNames_goil_cpu_level_include, gProductionIndexes_goil_cpu_level_include,
                                                      gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 156) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_cpu_5F_level_5F_include grammar ;
        grammar.nt_object_5F_definition_5F_list_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                const GALGAS_implementation  parameter_1,
                                GALGAS_objectsMap &  parameter_2,
                                GALGAS_string &  parameter_3,
                                const GALGAS_bool  parameter_4
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_cpu_level_include, gProductionNames_goil_cpu_level_include, gProductionIndexes_goil_cpu_level_include,
                                                    gFirstProductionIndexes_goil_cpu_level_include, gDecision_goil_cpu_level_include, gDecisionIndexes_goil_cpu_level_include, 156) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_cpu_5F_level_5F_include grammar ;
      grammar.nt_object_5F_definition_5F_list_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_cpu_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_cpu_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_parser_5F_start_i0_ (GALGAS_gtlData & outArgument_options,
                                                                                      C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_options.drop () ; // Release 'out' argument
  outArgument_options = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("options_parser.galgas", 32)), function_lstring (GALGAS_string ("Passed options"), inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 32)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("options_parser.galgas", 32))  COMMA_SOURCE_FILE ("options_parser.galgas", 32)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_item_ (outArgument_options, inCompiler) ;
    switch (select_options_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("options_parser.galgas", 35)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_parser_5F_start_i0_parse (C_Lexique_options_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_item_parse (inCompiler) ;
    switch (select_options_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("options_parser.galgas", 35)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_item_i1_ (GALGAS_gtlData & ioArgument_options,
                                                                           C_Lexique_options_5F_scanner * inCompiler) {
  GALGAS_lstring var_key_987 = inCompiler->synthetizedAttribute_key () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) COMMA_SOURCE_FILE ("options_parser.galgas", 42)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("options_parser.galgas", 43)) ;
  GALGAS_gtlData var_opt_1008 ;
  switch (select_options_5F_parser_1 (inCompiler)) {
  case 1: {
    nt_option_5F_value_ (var_opt_1008, inCompiler) ;
  } break ;
  case 2: {
    nt_list_5F_option_5F_value_ (var_opt_1008, inCompiler) ;
  } break ;
  default:
    break ;
  }
  {
  ioArgument_options.insulate (HERE) ; // §ABSTRACT
  cPtr_gtlData * ptr_1094 = (cPtr_gtlData *) ioArgument_options.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_1094, var_key_987, var_opt_1008, inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 50)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_item_i1_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) COMMA_SOURCE_FILE ("options_parser.galgas", 42)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("options_parser.galgas", 43)) ;
  switch (select_options_5F_parser_1 (inCompiler)) {
  case 1: {
    nt_option_5F_value_parse (inCompiler) ;
  } break ;
  case 2: {
    nt_list_5F_option_5F_value_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i2_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_lstring var_str_1191 = inCompiler->synthetizedAttribute_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("options_parser.galgas", 56)) ;
  outArgument_opt = GALGAS_gtlString::constructor_new (var_str_1191.getter_location (SOURCE_FILE ("options_parser.galgas", 57)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 57)), var_str_1191.getter_string (SOURCE_FILE ("options_parser.galgas", 57))  COMMA_SOURCE_FILE ("options_parser.galgas", 57)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i2_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("options_parser.galgas", 56)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i3_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_lstring var_str_1311 = inCompiler->synthetizedAttribute_key () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) COMMA_SOURCE_FILE ("options_parser.galgas", 63)) ;
  outArgument_opt = GALGAS_gtlString::constructor_new (var_str_1311.getter_location (SOURCE_FILE ("options_parser.galgas", 64)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 64)), var_str_1311.getter_string (SOURCE_FILE ("options_parser.galgas", 64))  COMMA_SOURCE_FILE ("options_parser.galgas", 64)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i3_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) COMMA_SOURCE_FILE ("options_parser.galgas", 63)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i4_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_luint_36__34_ var_num_1439 = inCompiler->synthetizedAttribute_integerNumber () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 70)) ;
  outArgument_opt = GALGAS_gtlInt::constructor_new (var_num_1439.getter_location (SOURCE_FILE ("options_parser.galgas", 71)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 71)), var_num_1439.mAttribute_uint_36__34_.getter_bigint (SOURCE_FILE ("options_parser.galgas", 71))  COMMA_SOURCE_FILE ("options_parser.galgas", 71)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i4_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 70)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i5_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_ldouble var_num_1574 = inCompiler->synthetizedAttribute_floatNumber () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 77)) ;
  outArgument_opt = GALGAS_gtlFloat::constructor_new (var_num_1574.getter_location (SOURCE_FILE ("options_parser.galgas", 78)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 78)), var_num_1574.getter_double (SOURCE_FILE ("options_parser.galgas", 78))  COMMA_SOURCE_FILE ("options_parser.galgas", 78)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i5_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 77)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i6_ (GALGAS_gtlData & outArgument_opt,
                                                                            C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("options_parser.galgas", 84)) ;
  switch (select_options_5F_parser_2 (inCompiler)) {
  case 1: {
    GALGAS_luint_36__34_ var_num_1718 = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 86)) ;
    outArgument_opt = GALGAS_gtlInt::constructor_new (var_num_1718.getter_location (SOURCE_FILE ("options_parser.galgas", 87)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 87)), var_num_1718.mAttribute_uint_36__34_.getter_bigint (SOURCE_FILE ("options_parser.galgas", 87)).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 87))  COMMA_SOURCE_FILE ("options_parser.galgas", 87)) ;
  } break ;
  case 2: {
    GALGAS_ldouble var_num_1822 = inCompiler->synthetizedAttribute_floatNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 89)) ;
    outArgument_opt = GALGAS_gtlFloat::constructor_new (var_num_1822.getter_location (SOURCE_FILE ("options_parser.galgas", 90)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 90)), var_num_1822.getter_double (SOURCE_FILE ("options_parser.galgas", 90)).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 90))  COMMA_SOURCE_FILE ("options_parser.galgas", 90)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_option_5F_value_i6_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2D_) COMMA_SOURCE_FILE ("options_parser.galgas", 84)) ;
  switch (select_options_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 86)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) COMMA_SOURCE_FILE ("options_parser.galgas", 89)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_list_5F_option_5F_value_i7_ (GALGAS_gtlData & outArgument_opt,
                                                                                    C_Lexique_options_5F_scanner * inCompiler) {
  outArgument_opt.drop () ; // Release 'out' argument
  GALGAS_list var_listOption_1957 = GALGAS_list::constructor_emptyList (SOURCE_FILE ("options_parser.galgas", 97)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("options_parser.galgas", 98)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlData var_item_2023 ;
    nt_option_5F_value_ (var_item_2023, inCompiler) ;
    var_listOption_1957.addAssign_operation (var_item_2023  COMMA_SOURCE_FILE ("options_parser.galgas", 101)) ;
    switch (select_options_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("options_parser.galgas", 102)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  outArgument_opt = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("options_parser.galgas", 104)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("options_parser.galgas", 104)), var_listOption_1957  COMMA_SOURCE_FILE ("options_parser.galgas", 104)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("options_parser.galgas", 105)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_options_5F_parser::rule_options_5F_parser_list_5F_option_5F_value_i7_parse (C_Lexique_options_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("options_parser.galgas", 98)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_option_5F_value_parse (inCompiler) ;
    switch (select_options_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("options_parser.galgas", 102)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_options_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("options_parser.galgas", 105)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_gtl_debugger_grammar [] = {
// At index 0 : <gtl_expression>, in file 'gtl_expression_parser.ggs', line 33
  NONTERMINAL (4) // <gtl_relation_term>
, NONTERMINAL (13) // <select_gtl_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 3 : <gtl_variable>, in file 'gtl_expression_parser.ggs', line 667
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (34) // <select_gtl_5F_expression_5F_parser_21>
, NONTERMINAL (33) // <select_gtl_5F_expression_5F_parser_20>
, END_PRODUCTION
// At index 7 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 37
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 9 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 52
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) // $step$
, END_PRODUCTION
// At index 11 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 63
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) // $do$
, NONTERMINAL (11) // <select_gtl_5F_debugger_5F_parser_0>
, END_PRODUCTION
// At index 14 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 92
, END_PRODUCTION
// At index 15 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 102
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_let) // $let$
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (12) // <select_gtl_5F_debugger_5F_parser_1>
, END_PRODUCTION
// At index 19 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 216
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_unlet) // $unlet$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 22 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 229
, NONTERMINAL (3) // <gtl_step_do_command>
, END_PRODUCTION
// At index 24 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 236
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_variables) // $variables$
, END_PRODUCTION
// At index 26 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 248
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_display) // $display$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 29 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 261
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_print) // $print$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 32 : <gtl_relation_term>, in file 'gtl_expression_parser.ggs', line 53
, NONTERMINAL (5) // <gtl_relation_factor>
, NONTERMINAL (14) // <select_gtl_5F_expression_5F_parser_1>
, END_PRODUCTION
// At index 35 : <gtl_relation_factor>, in file 'gtl_expression_parser.ggs', line 69
, NONTERMINAL (6) // <gtl_simple_expression>
, NONTERMINAL (15) // <select_gtl_5F_expression_5F_parser_2>
, END_PRODUCTION
// At index 38 : <gtl_simple_expression>, in file 'gtl_expression_parser.ggs', line 117
, NONTERMINAL (7) // <gtl_term>
, NONTERMINAL (16) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 41 : <gtl_term>, in file 'gtl_expression_parser.ggs', line 162
, NONTERMINAL (8) // <gtl_factor>
, NONTERMINAL (17) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 44 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 192
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 48 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 208
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) // $not$
, NONTERMINAL (8) // <gtl_factor>
, END_PRODUCTION
// At index 51 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 220
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7E_) // $~$
, NONTERMINAL (8) // <gtl_factor>
, END_PRODUCTION
// At index 54 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 232
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (8) // <gtl_factor>
, END_PRODUCTION
// At index 57 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 244
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) // $+$
, NONTERMINAL (8) // <gtl_factor>
, END_PRODUCTION
// At index 60 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 256
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_yes) // $yes$
, END_PRODUCTION
// At index 62 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 269
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_no) // $no$
, END_PRODUCTION
// At index 64 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 282
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, END_PRODUCTION
// At index 66 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 295
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double) // $literal_double$
, END_PRODUCTION
// At index 68 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 308
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, END_PRODUCTION
// At index 70 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 321
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char) // $literal_char$
, END_PRODUCTION
// At index 72 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 335
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (18) // <select_gtl_5F_expression_5F_parser_5>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 78 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 369
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (20) // <select_gtl_5F_expression_5F_parser_7>
, END_PRODUCTION
// At index 81 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 401
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) // $exists$
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (23) // <select_gtl_5F_expression_5F_parser_10>
, END_PRODUCTION
// At index 85 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 420
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_typeof) // $typeof$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 88 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 429
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_true) // $true$
, END_PRODUCTION
// At index 90 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 445
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_false) // $false$
, END_PRODUCTION
// At index 92 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 461
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum) // $literal_enum$
, END_PRODUCTION
// At index 94 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 477
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) // $@$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 97 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 514
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptylist) // $emptylist$
, END_PRODUCTION
// At index 99 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 533
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptymap) // $emptymap$
, END_PRODUCTION
// At index 101 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 552
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mapof) // $mapof$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (24) // <select_gtl_5F_expression_5F_parser_11>
, END_PRODUCTION
// At index 105 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 576
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_listof) // $listof$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, END_PRODUCTION
// At index 109 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 587
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__28_) // $@($
, NONTERMINAL (25) // <select_gtl_5F_expression_5F_parser_12>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 113 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 606
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__5B_) // $@[$
, NONTERMINAL (27) // <select_gtl_5F_expression_5F_parser_14>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 117 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 627
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__7B_) // $@{$
, NONTERMINAL (29) // <select_gtl_5F_expression_5F_parser_16>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7D_) // $}$
, END_PRODUCTION
// At index 121 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 648
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__21_) // $@!$
, NONTERMINAL (31) // <select_gtl_5F_expression_5F_parser_18>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) // $!$
, END_PRODUCTION
// At index 125 : <gtl_variable_or_here>, in file 'gtl_expression_parser.ggs', line 702
, NONTERMINAL (37) // <select_gtl_5F_expression_5F_parser_24>
, END_PRODUCTION
// At index 127 : <gtl_argument_list>, in file 'gtl_expression_parser.ggs', line 716
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (38) // <select_gtl_5F_expression_5F_parser_25>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 131 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 68
, NONTERMINAL (3) // <gtl_step_do_command>
, END_PRODUCTION
// At index 133 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 68
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) // $not$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, END_PRODUCTION
// At index 136 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 68
, END_PRODUCTION
// At index 137 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3D_) // $:=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 140 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B__3D_) // $+=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 143 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D__3D_) // $-=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 146 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A__3D_) // $*=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 149 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F__3D_) // $/=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 152 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod_3D_) // $mod=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 155 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) // $<<=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 158 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) // $>>=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 161 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26__3D_) // $&=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 164 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C__3D_) // $|=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 167 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E__3D_) // $^=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 170 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
, END_PRODUCTION
// At index 171 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, END_PRODUCTION
// At index 172 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C_) // $|$
, NONTERMINAL (4) // <gtl_relation_term>
, NONTERMINAL (13) // <select_gtl_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 176 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E_) // $^$
, NONTERMINAL (4) // <gtl_relation_term>
, NONTERMINAL (13) // <select_gtl_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 180 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
, END_PRODUCTION
// At index 181 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26_) // $&$
, NONTERMINAL (5) // <gtl_relation_factor>
, NONTERMINAL (14) // <select_gtl_5F_expression_5F_parser_1>
, END_PRODUCTION
// At index 185 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, END_PRODUCTION
// At index 186 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3D__3D_) // $==$
, NONTERMINAL (6) // <gtl_simple_expression>
, END_PRODUCTION
// At index 189 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21__3D_) // $!=$
, NONTERMINAL (6) // <gtl_simple_expression>
, END_PRODUCTION
// At index 192 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3D_) // $<=$
, NONTERMINAL (6) // <gtl_simple_expression>
, END_PRODUCTION
// At index 195 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3D_) // $>=$
, NONTERMINAL (6) // <gtl_simple_expression>
, END_PRODUCTION
// At index 198 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (6) // <gtl_simple_expression>
, END_PRODUCTION
// At index 201 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) // $<$
, NONTERMINAL (6) // <gtl_simple_expression>
, END_PRODUCTION
// At index 204 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, END_PRODUCTION
// At index 205 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C_) // $<<$
, NONTERMINAL (7) // <gtl_term>
, NONTERMINAL (16) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 209 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E_) // $>>$
, NONTERMINAL (7) // <gtl_term>
, NONTERMINAL (16) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 213 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) // $+$
, NONTERMINAL (7) // <gtl_term>
, NONTERMINAL (16) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 217 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2E_) // $.$
, NONTERMINAL (7) // <gtl_term>
, NONTERMINAL (16) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 221 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (7) // <gtl_term>
, NONTERMINAL (16) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 225 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, END_PRODUCTION
// At index 226 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A_) // $*$
, NONTERMINAL (8) // <gtl_factor>
, NONTERMINAL (17) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 230 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F_) // $/$
, NONTERMINAL (8) // <gtl_factor>
, NONTERMINAL (17) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 234 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod) // $mod$
, NONTERMINAL (8) // <gtl_factor>
, NONTERMINAL (17) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 238 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
, END_PRODUCTION
// At index 239 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (19) // <select_gtl_5F_expression_5F_parser_6>
, END_PRODUCTION
// At index 243 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
, END_PRODUCTION
// At index 244 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (19) // <select_gtl_5F_expression_5F_parser_6>
, END_PRODUCTION
// At index 248 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
, END_PRODUCTION
// At index 249 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (21) // <select_gtl_5F_expression_5F_parser_8>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 253 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (22) // <select_gtl_5F_expression_5F_parser_9>
, END_PRODUCTION
// At index 256 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
, END_PRODUCTION
// At index 257 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
, END_PRODUCTION
// At index 258 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (22) // <select_gtl_5F_expression_5F_parser_9>
, END_PRODUCTION
// At index 262 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_default) // $default$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 267 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
, END_PRODUCTION
// At index 268 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) // $by$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 271 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, END_PRODUCTION
// At index 273 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (26) // <select_gtl_5F_expression_5F_parser_13>
, END_PRODUCTION
// At index 276 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
, END_PRODUCTION
// At index 277 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
, END_PRODUCTION
// At index 278 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (26) // <select_gtl_5F_expression_5F_parser_13>
, END_PRODUCTION
// At index 282 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (28) // <select_gtl_5F_expression_5F_parser_15>
, END_PRODUCTION
// At index 287 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
, END_PRODUCTION
// At index 288 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
, END_PRODUCTION
// At index 289 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (28) // <select_gtl_5F_expression_5F_parser_15>
, END_PRODUCTION
// At index 295 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (30) // <select_gtl_5F_expression_5F_parser_17>
, END_PRODUCTION
// At index 300 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
, END_PRODUCTION
// At index 301 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
, END_PRODUCTION
// At index 302 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (30) // <select_gtl_5F_expression_5F_parser_17>
, END_PRODUCTION
// At index 308 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (32) // <select_gtl_5F_expression_5F_parser_19>
, END_PRODUCTION
// At index 311 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
, END_PRODUCTION
// At index 312 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
, END_PRODUCTION
// At index 313 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (32) // <select_gtl_5F_expression_5F_parser_19>
, END_PRODUCTION
// At index 317 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
, END_PRODUCTION
// At index 318 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3A_) // $::$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (34) // <select_gtl_5F_expression_5F_parser_21>
, NONTERMINAL (33) // <select_gtl_5F_expression_5F_parser_20>
, END_PRODUCTION
// At index 323 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, NONTERMINAL (35) // <select_gtl_5F_expression_5F_parser_22>
, END_PRODUCTION
// At index 328 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
, END_PRODUCTION
// At index 329 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, NONTERMINAL (36) // <select_gtl_5F_expression_5F_parser_23>
, END_PRODUCTION
// At index 334 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
, END_PRODUCTION
// At index 335 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
, END_PRODUCTION
// At index 336 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, NONTERMINAL (36) // <select_gtl_5F_expression_5F_parser_23>
, END_PRODUCTION
// At index 341 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_here) // $here$
, END_PRODUCTION
// At index 343 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 345 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (40) // <select_gtl_5F_expression_5F_parser_27>
, NONTERMINAL (39) // <select_gtl_5F_expression_5F_parser_26>
, END_PRODUCTION
// At index 349 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
, END_PRODUCTION
// At index 350 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
, END_PRODUCTION
// At index 351 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (40) // <select_gtl_5F_expression_5F_parser_27>
, NONTERMINAL (39) // <select_gtl_5F_expression_5F_parser_26>
, END_PRODUCTION
// At index 356 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) // $@$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 360 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
, END_PRODUCTION
// At index 361 : <>, in file '.ggs', line 0
, NONTERMINAL (2) // <gtl_debugger_command>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_gtl_debugger_grammar [129] = {
 {"<gtl_expression>", "gtl_expression_parser", 0}, // at index 0
 {"<gtl_variable>", "gtl_expression_parser", 3}, // at index 1
 {"<gtl_debugger_command>", "gtl_debugger_parser", 7}, // at index 2
 {"<gtl_debugger_command>", "gtl_debugger_parser", 9}, // at index 3
 {"<gtl_debugger_command>", "gtl_debugger_parser", 11}, // at index 4
 {"<gtl_debugger_command>", "gtl_debugger_parser", 14}, // at index 5
 {"<gtl_debugger_command>", "gtl_debugger_parser", 15}, // at index 6
 {"<gtl_debugger_command>", "gtl_debugger_parser", 19}, // at index 7
 {"<gtl_debugger_command>", "gtl_debugger_parser", 22}, // at index 8
 {"<gtl_step_do_command>", "gtl_debugger_parser", 24}, // at index 9
 {"<gtl_step_do_command>", "gtl_debugger_parser", 26}, // at index 10
 {"<gtl_step_do_command>", "gtl_debugger_parser", 29}, // at index 11
 {"<gtl_relation_term>", "gtl_expression_parser", 32}, // at index 12
 {"<gtl_relation_factor>", "gtl_expression_parser", 35}, // at index 13
 {"<gtl_simple_expression>", "gtl_expression_parser", 38}, // at index 14
 {"<gtl_term>", "gtl_expression_parser", 41}, // at index 15
 {"<gtl_factor>", "gtl_expression_parser", 44}, // at index 16
 {"<gtl_factor>", "gtl_expression_parser", 48}, // at index 17
 {"<gtl_factor>", "gtl_expression_parser", 51}, // at index 18
 {"<gtl_factor>", "gtl_expression_parser", 54}, // at index 19
 {"<gtl_factor>", "gtl_expression_parser", 57}, // at index 20
 {"<gtl_factor>", "gtl_expression_parser", 60}, // at index 21
 {"<gtl_factor>", "gtl_expression_parser", 62}, // at index 22
 {"<gtl_factor>", "gtl_expression_parser", 64}, // at index 23
 {"<gtl_factor>", "gtl_expression_parser", 66}, // at index 24
 {"<gtl_factor>", "gtl_expression_parser", 68}, // at index 25
 {"<gtl_factor>", "gtl_expression_parser", 70}, // at index 26
 {"<gtl_factor>", "gtl_expression_parser", 72}, // at index 27
 {"<gtl_factor>", "gtl_expression_parser", 78}, // at index 28
 {"<gtl_factor>", "gtl_expression_parser", 81}, // at index 29
 {"<gtl_factor>", "gtl_expression_parser", 85}, // at index 30
 {"<gtl_factor>", "gtl_expression_parser", 88}, // at index 31
 {"<gtl_factor>", "gtl_expression_parser", 90}, // at index 32
 {"<gtl_factor>", "gtl_expression_parser", 92}, // at index 33
 {"<gtl_factor>", "gtl_expression_parser", 94}, // at index 34
 {"<gtl_factor>", "gtl_expression_parser", 97}, // at index 35
 {"<gtl_factor>", "gtl_expression_parser", 99}, // at index 36
 {"<gtl_factor>", "gtl_expression_parser", 101}, // at index 37
 {"<gtl_factor>", "gtl_expression_parser", 105}, // at index 38
 {"<gtl_factor>", "gtl_expression_parser", 109}, // at index 39
 {"<gtl_factor>", "gtl_expression_parser", 113}, // at index 40
 {"<gtl_factor>", "gtl_expression_parser", 117}, // at index 41
 {"<gtl_factor>", "gtl_expression_parser", 121}, // at index 42
 {"<gtl_variable_or_here>", "gtl_expression_parser", 125}, // at index 43
 {"<gtl_argument_list>", "gtl_expression_parser", 127}, // at index 44
 {"<select_gtl_5F_debugger_5F_parser_0>", "gtl_debugger_parser", 131}, // at index 45
 {"<select_gtl_5F_debugger_5F_parser_0>", "gtl_debugger_parser", 133}, // at index 46
 {"<select_gtl_5F_debugger_5F_parser_0>", "gtl_debugger_parser", 136}, // at index 47
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 137}, // at index 48
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 140}, // at index 49
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 143}, // at index 50
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 146}, // at index 51
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 149}, // at index 52
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 152}, // at index 53
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 155}, // at index 54
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 158}, // at index 55
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 161}, // at index 56
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 164}, // at index 57
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 167}, // at index 58
 {"<select_gtl_5F_debugger_5F_parser_1>", "gtl_debugger_parser", 170}, // at index 59
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 171}, // at index 60
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 172}, // at index 61
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 176}, // at index 62
 {"<select_gtl_5F_expression_5F_parser_1>", "gtl_expression_parser", 180}, // at index 63
 {"<select_gtl_5F_expression_5F_parser_1>", "gtl_expression_parser", 181}, // at index 64
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 185}, // at index 65
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 186}, // at index 66
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 189}, // at index 67
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 192}, // at index 68
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 195}, // at index 69
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 198}, // at index 70
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 201}, // at index 71
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 204}, // at index 72
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 205}, // at index 73
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 209}, // at index 74
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 213}, // at index 75
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 217}, // at index 76
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 221}, // at index 77
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 225}, // at index 78
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 226}, // at index 79
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 230}, // at index 80
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 234}, // at index 81
 {"<select_gtl_5F_expression_5F_parser_5>", "gtl_expression_parser", 238}, // at index 82
 {"<select_gtl_5F_expression_5F_parser_5>", "gtl_expression_parser", 239}, // at index 83
 {"<select_gtl_5F_expression_5F_parser_6>", "gtl_expression_parser", 243}, // at index 84
 {"<select_gtl_5F_expression_5F_parser_6>", "gtl_expression_parser", 244}, // at index 85
 {"<select_gtl_5F_expression_5F_parser_7>", "gtl_expression_parser", 248}, // at index 86
 {"<select_gtl_5F_expression_5F_parser_7>", "gtl_expression_parser", 249}, // at index 87
 {"<select_gtl_5F_expression_5F_parser_8>", "gtl_expression_parser", 253}, // at index 88
 {"<select_gtl_5F_expression_5F_parser_8>", "gtl_expression_parser", 256}, // at index 89
 {"<select_gtl_5F_expression_5F_parser_9>", "gtl_expression_parser", 257}, // at index 90
 {"<select_gtl_5F_expression_5F_parser_9>", "gtl_expression_parser", 258}, // at index 91
 {"<select_gtl_5F_expression_5F_parser_10>", "gtl_expression_parser", 262}, // at index 92
 {"<select_gtl_5F_expression_5F_parser_10>", "gtl_expression_parser", 267}, // at index 93
 {"<select_gtl_5F_expression_5F_parser_11>", "gtl_expression_parser", 268}, // at index 94
 {"<select_gtl_5F_expression_5F_parser_11>", "gtl_expression_parser", 271}, // at index 95
 {"<select_gtl_5F_expression_5F_parser_12>", "gtl_expression_parser", 273}, // at index 96
 {"<select_gtl_5F_expression_5F_parser_12>", "gtl_expression_parser", 276}, // at index 97
 {"<select_gtl_5F_expression_5F_parser_13>", "gtl_expression_parser", 277}, // at index 98
 {"<select_gtl_5F_expression_5F_parser_13>", "gtl_expression_parser", 278}, // at index 99
 {"<select_gtl_5F_expression_5F_parser_14>", "gtl_expression_parser", 282}, // at index 100
 {"<select_gtl_5F_expression_5F_parser_14>", "gtl_expression_parser", 287}, // at index 101
 {"<select_gtl_5F_expression_5F_parser_15>", "gtl_expression_parser", 288}, // at index 102
 {"<select_gtl_5F_expression_5F_parser_15>", "gtl_expression_parser", 289}, // at index 103
 {"<select_gtl_5F_expression_5F_parser_16>", "gtl_expression_parser", 295}, // at index 104
 {"<select_gtl_5F_expression_5F_parser_16>", "gtl_expression_parser", 300}, // at index 105
 {"<select_gtl_5F_expression_5F_parser_17>", "gtl_expression_parser", 301}, // at index 106
 {"<select_gtl_5F_expression_5F_parser_17>", "gtl_expression_parser", 302}, // at index 107
 {"<select_gtl_5F_expression_5F_parser_18>", "gtl_expression_parser", 308}, // at index 108
 {"<select_gtl_5F_expression_5F_parser_18>", "gtl_expression_parser", 311}, // at index 109
 {"<select_gtl_5F_expression_5F_parser_19>", "gtl_expression_parser", 312}, // at index 110
 {"<select_gtl_5F_expression_5F_parser_19>", "gtl_expression_parser", 313}, // at index 111
 {"<select_gtl_5F_expression_5F_parser_20>", "gtl_expression_parser", 317}, // at index 112
 {"<select_gtl_5F_expression_5F_parser_20>", "gtl_expression_parser", 318}, // at index 113
 {"<select_gtl_5F_expression_5F_parser_21>", "gtl_expression_parser", 323}, // at index 114
 {"<select_gtl_5F_expression_5F_parser_21>", "gtl_expression_parser", 328}, // at index 115
 {"<select_gtl_5F_expression_5F_parser_22>", "gtl_expression_parser", 329}, // at index 116
 {"<select_gtl_5F_expression_5F_parser_22>", "gtl_expression_parser", 334}, // at index 117
 {"<select_gtl_5F_expression_5F_parser_23>", "gtl_expression_parser", 335}, // at index 118
 {"<select_gtl_5F_expression_5F_parser_23>", "gtl_expression_parser", 336}, // at index 119
 {"<select_gtl_5F_expression_5F_parser_24>", "gtl_expression_parser", 341}, // at index 120
 {"<select_gtl_5F_expression_5F_parser_24>", "gtl_expression_parser", 343}, // at index 121
 {"<select_gtl_5F_expression_5F_parser_25>", "gtl_expression_parser", 345}, // at index 122
 {"<select_gtl_5F_expression_5F_parser_25>", "gtl_expression_parser", 349}, // at index 123
 {"<select_gtl_5F_expression_5F_parser_26>", "gtl_expression_parser", 350}, // at index 124
 {"<select_gtl_5F_expression_5F_parser_26>", "gtl_expression_parser", 351}, // at index 125
 {"<select_gtl_5F_expression_5F_parser_27>", "gtl_expression_parser", 356}, // at index 126
 {"<select_gtl_5F_expression_5F_parser_27>", "gtl_expression_parser", 360}, // at index 127
 {"<>", "", 361} // at index 128
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_gtl_debugger_grammar [129] = {
0, // index 0 : <gtl_expression>, in file 'gtl_expression_parser.ggs', line 33
3, // index 1 : <gtl_variable>, in file 'gtl_expression_parser.ggs', line 667
7, // index 2 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 37
9, // index 3 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 52
11, // index 4 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 63
14, // index 5 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 92
15, // index 6 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 102
19, // index 7 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 216
22, // index 8 : <gtl_debugger_command>, in file 'gtl_debugger_parser.ggs', line 229
24, // index 9 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 236
26, // index 10 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 248
29, // index 11 : <gtl_step_do_command>, in file 'gtl_debugger_parser.ggs', line 261
32, // index 12 : <gtl_relation_term>, in file 'gtl_expression_parser.ggs', line 53
35, // index 13 : <gtl_relation_factor>, in file 'gtl_expression_parser.ggs', line 69
38, // index 14 : <gtl_simple_expression>, in file 'gtl_expression_parser.ggs', line 117
41, // index 15 : <gtl_term>, in file 'gtl_expression_parser.ggs', line 162
44, // index 16 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 192
48, // index 17 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 208
51, // index 18 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 220
54, // index 19 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 232
57, // index 20 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 244
60, // index 21 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 256
62, // index 22 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 269
64, // index 23 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 282
66, // index 24 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 295
68, // index 25 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 308
70, // index 26 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 321
72, // index 27 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 335
78, // index 28 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 369
81, // index 29 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 401
85, // index 30 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 420
88, // index 31 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 429
90, // index 32 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 445
92, // index 33 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 461
94, // index 34 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 477
97, // index 35 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 514
99, // index 36 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 533
101, // index 37 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 552
105, // index 38 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 576
109, // index 39 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 587
113, // index 40 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 606
117, // index 41 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 627
121, // index 42 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 648
125, // index 43 : <gtl_variable_or_here>, in file 'gtl_expression_parser.ggs', line 702
127, // index 44 : <gtl_argument_list>, in file 'gtl_expression_parser.ggs', line 716
131, // index 45 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 68
133, // index 46 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 68
136, // index 47 : <select_gtl_5F_debugger_5F_parser_0>, in file 'gtl_debugger_parser.ggs', line 68
137, // index 48 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
140, // index 49 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
143, // index 50 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
146, // index 51 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
149, // index 52 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
152, // index 53 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
155, // index 54 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
158, // index 55 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
161, // index 56 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
164, // index 57 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
167, // index 58 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
170, // index 59 : <select_gtl_5F_debugger_5F_parser_1>, in file 'gtl_debugger_parser.ggs', line 107
171, // index 60 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
172, // index 61 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
176, // index 62 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
180, // index 63 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
181, // index 64 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
185, // index 65 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
186, // index 66 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
189, // index 67 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
192, // index 68 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
195, // index 69 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
198, // index 70 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
201, // index 71 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
204, // index 72 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
205, // index 73 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
209, // index 74 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
213, // index 75 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
217, // index 76 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
221, // index 77 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
225, // index 78 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
226, // index 79 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
230, // index 80 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
234, // index 81 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
238, // index 82 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
239, // index 83 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
243, // index 84 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
244, // index 85 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
248, // index 86 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
249, // index 87 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
253, // index 88 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
256, // index 89 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
257, // index 90 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
258, // index 91 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
262, // index 92 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
267, // index 93 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
268, // index 94 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
271, // index 95 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
273, // index 96 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
276, // index 97 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
277, // index 98 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
278, // index 99 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
282, // index 100 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
287, // index 101 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
288, // index 102 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
289, // index 103 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
295, // index 104 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
300, // index 105 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
301, // index 106 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
302, // index 107 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
308, // index 108 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
311, // index 109 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
312, // index 110 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
313, // index 111 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
317, // index 112 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
318, // index 113 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
323, // index 114 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
328, // index 115 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
329, // index 116 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
334, // index 117 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
335, // index 118 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
336, // index 119 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
341, // index 120 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
343, // index 121 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
345, // index 122 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
349, // index 123 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
350, // index 124 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
351, // index 125 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
356, // index 126 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
360, // index 127 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
361 // index 128 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_gtl_debugger_grammar [43] = {
0, // at 0 : <gtl_expression>
1, // at 1 : <gtl_variable>
2, // at 2 : <gtl_debugger_command>
9, // at 3 : <gtl_step_do_command>
12, // at 4 : <gtl_relation_term>
13, // at 5 : <gtl_relation_factor>
14, // at 6 : <gtl_simple_expression>
15, // at 7 : <gtl_term>
16, // at 8 : <gtl_factor>
43, // at 9 : <gtl_variable_or_here>
44, // at 10 : <gtl_argument_list>
45, // at 11 : <select_gtl_5F_debugger_5F_parser_0>
48, // at 12 : <select_gtl_5F_debugger_5F_parser_1>
60, // at 13 : <select_gtl_5F_expression_5F_parser_0>
63, // at 14 : <select_gtl_5F_expression_5F_parser_1>
65, // at 15 : <select_gtl_5F_expression_5F_parser_2>
72, // at 16 : <select_gtl_5F_expression_5F_parser_3>
78, // at 17 : <select_gtl_5F_expression_5F_parser_4>
82, // at 18 : <select_gtl_5F_expression_5F_parser_5>
84, // at 19 : <select_gtl_5F_expression_5F_parser_6>
86, // at 20 : <select_gtl_5F_expression_5F_parser_7>
88, // at 21 : <select_gtl_5F_expression_5F_parser_8>
90, // at 22 : <select_gtl_5F_expression_5F_parser_9>
92, // at 23 : <select_gtl_5F_expression_5F_parser_10>
94, // at 24 : <select_gtl_5F_expression_5F_parser_11>
96, // at 25 : <select_gtl_5F_expression_5F_parser_12>
98, // at 26 : <select_gtl_5F_expression_5F_parser_13>
100, // at 27 : <select_gtl_5F_expression_5F_parser_14>
102, // at 28 : <select_gtl_5F_expression_5F_parser_15>
104, // at 29 : <select_gtl_5F_expression_5F_parser_16>
106, // at 30 : <select_gtl_5F_expression_5F_parser_17>
108, // at 31 : <select_gtl_5F_expression_5F_parser_18>
110, // at 32 : <select_gtl_5F_expression_5F_parser_19>
112, // at 33 : <select_gtl_5F_expression_5F_parser_20>
114, // at 34 : <select_gtl_5F_expression_5F_parser_21>
116, // at 35 : <select_gtl_5F_expression_5F_parser_22>
118, // at 36 : <select_gtl_5F_expression_5F_parser_23>
120, // at 37 : <select_gtl_5F_expression_5F_parser_24>
122, // at 38 : <select_gtl_5F_expression_5F_parser_25>
124, // at 39 : <select_gtl_5F_expression_5F_parser_26>
126, // at 40 : <select_gtl_5F_expression_5F_parser_27>
128, // at 41 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_gtl_debugger_grammar [] = {
// At index 0 : <gtl_expression> only one production, no choice
  -1,
// At index 1 : <gtl_variable> only one production, no choice
  -1,
// At index 2 : <gtl_debugger_command>
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_step, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken_let, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_unlet, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_print, -1, // Choice 7
  -1,
// At index 19 : <gtl_step_do_command>
C_Lexique_gtl_5F_scanner::kToken_variables, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_display, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_print, -1, // Choice 3
  -1,
// At index 26 : <gtl_relation_term> only one production, no choice
  -1,
// At index 27 : <gtl_relation_factor> only one production, no choice
  -1,
// At index 28 : <gtl_simple_expression> only one production, no choice
  -1,
// At index 29 : <gtl_term> only one production, no choice
  -1,
// At index 30 : <gtl_factor>
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_not, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__7E_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__2D_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__2B_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_yes, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken_no, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken_string, -1, // Choice 10
C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, -1, // Choice 11
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 12
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 13
C_Lexique_gtl_5F_scanner::kToken_exists, -1, // Choice 14
C_Lexique_gtl_5F_scanner::kToken_typeof, -1, // Choice 15
C_Lexique_gtl_5F_scanner::kToken_true, -1, // Choice 16
C_Lexique_gtl_5F_scanner::kToken_false, -1, // Choice 17
C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, -1, // Choice 18
C_Lexique_gtl_5F_scanner::kToken__40_, -1, // Choice 19
C_Lexique_gtl_5F_scanner::kToken_emptylist, -1, // Choice 20
C_Lexique_gtl_5F_scanner::kToken_emptymap, -1, // Choice 21
C_Lexique_gtl_5F_scanner::kToken_mapof, -1, // Choice 22
C_Lexique_gtl_5F_scanner::kToken_listof, -1, // Choice 23
C_Lexique_gtl_5F_scanner::kToken__40__28_, -1, // Choice 24
C_Lexique_gtl_5F_scanner::kToken__40__5B_, -1, // Choice 25
C_Lexique_gtl_5F_scanner::kToken__40__7B_, -1, // Choice 26
C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 27
  -1,
// At index 85 : <gtl_variable_or_here> only one production, no choice
  -1,
// At index 86 : <gtl_argument_list> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 87 : <select_gtl_5F_debugger_5F_parser_0>
C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_print, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_not, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 3
  -1,
// At index 96 : <select_gtl_5F_debugger_5F_parser_1>
C_Lexique_gtl_5F_scanner::kToken__3A__3D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2B__3D_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__2D__3D_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__2A__3D_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__2F__3D_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_mod_3D_, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken__26__3D_, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken__7C__3D_, -1, // Choice 10
C_Lexique_gtl_5F_scanner::kToken__5E__3D_, -1, // Choice 11
C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 12
  -1,
// At index 121 : <select_gtl_5F_expression_5F_parser_0>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__7C_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__5E_, -1, // Choice 3
  -1,
// At index 136 : <select_gtl_5F_expression_5F_parser_1>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__26_, -1, // Choice 2
  -1,
// At index 151 : <select_gtl_5F_expression_5F_parser_2>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3D__3D_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__21__3D_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__3C__3D_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__3E__3D_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken__3E_, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 7
  -1,
// At index 177 : <select_gtl_5F_expression_5F_parser_3>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3C__3C_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__3E__3E_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__2B_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__2E_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken__2D_, -1, // Choice 6
  -1,
// At index 207 : <select_gtl_5F_expression_5F_parser_4>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2A_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__2F_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken_mod, -1, // Choice 4
  -1,
// At index 238 : <select_gtl_5F_expression_5F_parser_5>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 2
  -1,
// At index 243 : <select_gtl_5F_expression_5F_parser_6>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 248 : <select_gtl_5F_expression_5F_parser_7>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 2
  -1,
// At index 278 : <select_gtl_5F_expression_5F_parser_8>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 309 : <select_gtl_5F_expression_5F_parser_9>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 314 : <select_gtl_5F_expression_5F_parser_10>
C_Lexique_gtl_5F_scanner::kToken_default, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 344 : <select_gtl_5F_expression_5F_parser_11>
C_Lexique_gtl_5F_scanner::kToken_by, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 349 : <select_gtl_5F_expression_5F_parser_12>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 380 : <select_gtl_5F_expression_5F_parser_13>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 385 : <select_gtl_5F_expression_5F_parser_14>
C_Lexique_gtl_5F_scanner::kToken_string, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 2
  -1,
// At index 390 : <select_gtl_5F_expression_5F_parser_15>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 395 : <select_gtl_5F_expression_5F_parser_16>
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__7D_, -1, // Choice 2
  -1,
// At index 400 : <select_gtl_5F_expression_5F_parser_17>
C_Lexique_gtl_5F_scanner::kToken__7D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 405 : <select_gtl_5F_expression_5F_parser_18>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 2
  -1,
// At index 436 : <select_gtl_5F_expression_5F_parser_19>
C_Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 441 : <select_gtl_5F_expression_5F_parser_20>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3A__3A_, -1, // Choice 2
  -1,
// At index 484 : <select_gtl_5F_expression_5F_parser_21>
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken__3A__3A_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 528 : <select_gtl_5F_expression_5F_parser_22>
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken__3A__3A_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 572 : <select_gtl_5F_expression_5F_parser_23>
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken__3A__3A_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 2
  -1,
// At index 616 : <select_gtl_5F_expression_5F_parser_24>
C_Lexique_gtl_5F_scanner::kToken_here, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 2
  -1,
// At index 621 : <select_gtl_5F_expression_5F_parser_25>
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 626 : <select_gtl_5F_expression_5F_parser_26>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 631 : <select_gtl_5F_expression_5F_parser_27>
C_Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 637 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_gtl_debugger_grammar [43] = {
0, // at 0 : <gtl_expression>
1, // at 1 : <gtl_variable>
2, // at 2 : <gtl_debugger_command>
19, // at 3 : <gtl_step_do_command>
26, // at 4 : <gtl_relation_term>
27, // at 5 : <gtl_relation_factor>
28, // at 6 : <gtl_simple_expression>
29, // at 7 : <gtl_term>
30, // at 8 : <gtl_factor>
85, // at 9 : <gtl_variable_or_here>
86, // at 10 : <gtl_argument_list>
87, // at 11 : <select_gtl_5F_debugger_5F_parser_0>
96, // at 12 : <select_gtl_5F_debugger_5F_parser_1>
121, // at 13 : <select_gtl_5F_expression_5F_parser_0>
136, // at 14 : <select_gtl_5F_expression_5F_parser_1>
151, // at 15 : <select_gtl_5F_expression_5F_parser_2>
177, // at 16 : <select_gtl_5F_expression_5F_parser_3>
207, // at 17 : <select_gtl_5F_expression_5F_parser_4>
238, // at 18 : <select_gtl_5F_expression_5F_parser_5>
243, // at 19 : <select_gtl_5F_expression_5F_parser_6>
248, // at 20 : <select_gtl_5F_expression_5F_parser_7>
278, // at 21 : <select_gtl_5F_expression_5F_parser_8>
309, // at 22 : <select_gtl_5F_expression_5F_parser_9>
314, // at 23 : <select_gtl_5F_expression_5F_parser_10>
344, // at 24 : <select_gtl_5F_expression_5F_parser_11>
349, // at 25 : <select_gtl_5F_expression_5F_parser_12>
380, // at 26 : <select_gtl_5F_expression_5F_parser_13>
385, // at 27 : <select_gtl_5F_expression_5F_parser_14>
390, // at 28 : <select_gtl_5F_expression_5F_parser_15>
395, // at 29 : <select_gtl_5F_expression_5F_parser_16>
400, // at 30 : <select_gtl_5F_expression_5F_parser_17>
405, // at 31 : <select_gtl_5F_expression_5F_parser_18>
436, // at 32 : <select_gtl_5F_expression_5F_parser_19>
441, // at 33 : <select_gtl_5F_expression_5F_parser_20>
484, // at 34 : <select_gtl_5F_expression_5F_parser_21>
528, // at 35 : <select_gtl_5F_expression_5F_parser_22>
572, // at 36 : <select_gtl_5F_expression_5F_parser_23>
616, // at 37 : <select_gtl_5F_expression_5F_parser_24>
621, // at 38 : <select_gtl_5F_expression_5F_parser_25>
626, // at 39 : <select_gtl_5F_expression_5F_parser_26>
631, // at 40 : <select_gtl_5F_expression_5F_parser_27>
637, // at 41 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'gtl_expression' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_expression_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'gtl_variable' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_variable_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_variable_ (GALGAS_gtlVarPath & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'gtl_debugger_command' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_debugger_5F_command_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_debugger_5F_command_ (GALGAS_gtlInstruction & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_gtl_5F_debugger_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_gtl_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_gtl_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_gtl_debugger_grammar, gProductionNames_gtl_debugger_grammar, gProductionIndexes_gtl_debugger_grammar,
                                    gFirstProductionIndexes_gtl_debugger_grammar, gDecision_gtl_debugger_grammar, gDecisionIndexes_gtl_debugger_grammar, 361) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_gtlInstruction &  parameter_1
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_gtl_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_gtl_debugger_grammar, gProductionNames_gtl_debugger_grammar, gProductionIndexes_gtl_debugger_grammar,
                                                      gFirstProductionIndexes_gtl_debugger_grammar, gDecision_gtl_debugger_grammar, gDecisionIndexes_gtl_debugger_grammar, 361) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_gtl_5F_debugger_5F_grammar grammar ;
        grammar.nt_gtl_5F_debugger_5F_command_ (parameter_1, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_gtlInstruction &  parameter_1
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_gtl_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_gtl_debugger_grammar, gProductionNames_gtl_debugger_grammar, gProductionIndexes_gtl_debugger_grammar,
                                                    gFirstProductionIndexes_gtl_debugger_grammar, gDecision_gtl_debugger_grammar, gDecisionIndexes_gtl_debugger_grammar, 361) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_gtl_5F_debugger_5F_grammar grammar ;
      grammar.nt_gtl_5F_debugger_5F_command_ (parameter_1, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'gtl_step_do_command' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_step_5F_do_5F_command_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i7_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i8_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i9_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_step_5F_do_5F_command_ (GALGAS_gtlInstruction & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i7_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i8_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i9_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'gtl_relation_term' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_term_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'gtl_relation_factor' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_factor_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_relation_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'gtl_simple_expression' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_simple_5F_expression_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_simple_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'gtl_term' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_term_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'gtl_factor' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_factor_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_parse(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_parse(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_parse(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_parse(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_parse(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_parse(inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_parse(inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_parse(inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_parse(inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_parse(inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_parse(inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_parse(inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_parse(inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_parse(inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_parse(inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_parse(inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_parse(inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_parse(inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_parse(inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_parse(inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_(parameter_1, inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_(parameter_1, inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_(parameter_1, inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_(parameter_1, inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_(parameter_1, inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_(parameter_1, inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_(parameter_1, inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_(parameter_1, inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_(parameter_1, inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_(parameter_1, inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_(parameter_1, inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_(parameter_1, inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_(parameter_1, inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_(parameter_1, inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_(parameter_1, inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_(parameter_1, inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_(parameter_1, inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_(parameter_1, inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_(parameter_1, inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_(parameter_1, inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'gtl_variable_or_here' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_variable_5F_or_5F_here_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_variable_5F_or_5F_here_ (GALGAS_gtlVarPath & parameter_1,
                                GALGAS_bool & parameter_2,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'gtl_argument_list' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_argument_5F_list_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_parse(inLexique) ;
}

void cGrammar_gtl_5F_debugger_5F_grammar::nt_gtl_5F_argument_5F_list_ (GALGAS_gtlArgumentList & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_gtl_5F_debugger_5F_parser_0' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_0 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_gtl_5F_debugger_5F_parser_1' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_debugger_5F_parser_1 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_0' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_0 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_1' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_1 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_2' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_2 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_3' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_3 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_4' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_4 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_5' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_5 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_6' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_6 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_7' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_7 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_8' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_8 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_9' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_9 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_10' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_10 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_11' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_11 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_12' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_12 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_13' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_13 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_14' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_14 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_15' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_15 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_16' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_16 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_17' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_17 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_18' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_18 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_19' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_19 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_20' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_20 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_21' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_21 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_22' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_22 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_23' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_23 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_24' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_24 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_25' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_25 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_26' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_26 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_27' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_debugger_5F_grammar::select_gtl_5F_expression_5F_parser_27 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_definition_i0_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                       C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  GALGAS_lstring var_implementationName_1955 = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  nt_implementation_5F_object_5F_list_ (ioArgument_implementation, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 59)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 59)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_definition_i0_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 57)) ;
  nt_implementation_5F_object_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 59)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 59)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_implementation_5F_objects_ (ioArgument_implementation, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 66)) ;
    } break ;
    case 3: {
      nt_include_5F_implementation_5F_level_ (ioArgument_implementation, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_implementation_5F_objects_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 66)) ;
    } break ;
    case 3: {
      nt_include_5F_implementation_5F_level_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                             C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_2316 = GALGAS_bool (false) ;
  switch (select_implementation_5F_parser_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("implementation_parser.galgas", 76)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("implementation_parser.galgas", 78)) ;
    var_includeIfExists_2316 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_2424 ;
  switch (select_implementation_5F_parser_2 (inCompiler)) {
  case 1: {
    var_file_5F_name_2424 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 82)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_2424, inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 83)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_2424 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 85)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_bool test_0 = var_includeIfExists_2316.operator_not (SOURCE_FILE ("implementation_parser.galgas", 87)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    GALGAS_bool test_1 = var_includeIfExists_2316 ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = var_file_5F_name_2424.mAttribute_string.getter_fileExists (SOURCE_FILE ("implementation_parser.galgas", 87)) ;
    }
    test_0 = test_1 ;
  }
  const enumGalgasBool test_2 = test_0.boolEnum () ;
  if (kBoolTrue == test_2) {
    cGrammar_goil_5F_implementation_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_2424, ioArgument_implementation  COMMA_SOURCE_FILE ("implementation_parser.galgas", 88)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_1 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("implementation_parser.galgas", 76)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("implementation_parser.galgas", 78)) ;
  } break ;
  default:
    break ;
  }
  switch (select_implementation_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 82)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 85)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_include_5F_type_5F_level_i3_ (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                                                                                   C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_bool var_includeIfExists_2788 = GALGAS_bool (false) ;
  switch (select_implementation_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("implementation_parser.galgas", 97)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("implementation_parser.galgas", 99)) ;
    var_includeIfExists_2788 = GALGAS_bool (true) ;
  } break ;
  default:
    break ;
  }
  GALGAS_lstring var_file_5F_name_2896 ;
  switch (select_implementation_5F_parser_4 (inCompiler)) {
  case 1: {
    var_file_5F_name_2896 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 103)) ;
    {
    routine_file_5F_in_5F_path (var_file_5F_name_2896, inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 104)) ;
    }
  } break ;
  case 2: {
    var_file_5F_name_2896 = inCompiler->synthetizedAttribute_a_5F_string () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 106)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_bool test_0 = var_includeIfExists_2788.operator_not (SOURCE_FILE ("implementation_parser.galgas", 108)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    GALGAS_bool test_1 = var_includeIfExists_2788 ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = var_file_5F_name_2896.mAttribute_string.getter_fileExists (SOURCE_FILE ("implementation_parser.galgas", 108)) ;
    }
    test_0 = test_1 ;
  }
  const enumGalgasBool test_2 = test_0.boolEnum () ;
  if (kBoolTrue == test_2) {
    cGrammar_goil_5F_type_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, var_file_5F_name_2896, ioArgument_objectAttributes  COMMA_SOURCE_FILE ("implementation_parser.galgas", 109)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) COMMA_SOURCE_FILE ("implementation_parser.galgas", 97)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) COMMA_SOURCE_FILE ("implementation_parser.galgas", 99)) ;
  } break ;
  default:
    break ;
  }
  switch (select_implementation_5F_parser_4 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 103)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 106)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_objects_i4_ (GALGAS_implementation & ioArgument_implementation,
                                                                                                    C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_implementationMap var_imp_3918 = ioArgument_implementation.getter_imp (SOURCE_FILE ("implementation_parser.galgas", 138)) ;
  GALGAS_lstring var_objectName_3977 = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 140)) ;
  GALGAS_lbool var_multiple_4017 ;
  switch (select_implementation_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 144)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 144)) ;
    var_multiple_4017 = GALGAS_lbool::constructor_new (GALGAS_bool (true), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 144))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 144)) ;
  } break ;
  case 2: {
    var_multiple_4017 = GALGAS_lbool::constructor_new (GALGAS_bool (false), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 146))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 146)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_implementationObjectMap var_objectAttributes_4234 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 149)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 151)) ;
  nt_implementation_5F_list_ (var_objectAttributes_4234, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 153)) ;
  GALGAS_implementationObject var_newObject_4339 = GALGAS_implementationObject::constructor_new (var_multiple_4017, var_objectAttributes_4234  COMMA_SOURCE_FILE ("implementation_parser.galgas", 155)) ;
  GALGAS_implementationObject var_object_4511 ;
  const enumGalgasBool test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) ioArgument_implementation.ptr (), var_objectName_3977.getter_string (SOURCE_FILE ("implementation_parser.galgas", 160)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 160)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    var_imp_3918.setter_del (var_objectName_3977, var_object_4511, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 161)) ;
    }
    var_object_4511 = callExtensionGetter_mergeImplementationObjectWith ((const cPtr_implementationObject *) var_object_4511.ptr (), var_newObject_4339, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 162)) ;
  }else if (kBoolFalse == test_0) {
    var_object_4511 = var_newObject_4339 ;
  }
  {
  var_imp_3918.setter_put (var_objectName_3977, var_object_4511, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 179)) ;
  }
  {
  ioArgument_implementation.setter_setImp (var_imp_3918 COMMA_SOURCE_FILE ("implementation_parser.galgas", 180)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_objects_i4_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 140)) ;
  switch (select_implementation_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 144)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 144)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 151)) ;
  nt_implementation_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 153)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_list_i5_ (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_6 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attributeName_5239 ;
      GALGAS_impType var_type_5257 ;
      nt_implementation_5F_type_ (var_attributeName_5239, var_type_5257, inCompiler) ;
      const enumGalgasBool test_1 = ioArgument_objectAttributes.getter_hasKey (var_attributeName_5239.getter_string (SOURCE_FILE ("implementation_parser.galgas", 191)) COMMA_SOURCE_FILE ("implementation_parser.galgas", 191)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_impType var_previousType_5394 ;
        ioArgument_objectAttributes.method_get (var_attributeName_5239, var_previousType_5394, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 193)) ;
        const enumGalgasBool test_2 = function_checkNewTypeWithinPreviousType (var_attributeName_5239, var_previousType_5394, var_type_5257, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 197)).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          GALGAS_impType joker_5737 ; // Joker input parameter
          ioArgument_objectAttributes.setter_del (var_attributeName_5239, joker_5737, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 200)) ;
          }
          {
          ioArgument_objectAttributes.setter_put (var_attributeName_5239, var_type_5257, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 201)) ;
          }
        }
      }else if (kBoolFalse == test_1) {
        {
        ioArgument_objectAttributes.setter_put (var_attributeName_5239, var_type_5257, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 204)) ;
        }
      }
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 206)) ;
    } break ;
    case 3: {
      nt_include_5F_type_5F_level_ (ioArgument_objectAttributes, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_list_i5_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_6 (inCompiler)) {
    case 2: {
      nt_implementation_5F_type_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 206)) ;
    } break ;
    case 3: {
      nt_include_5F_type_5F_level_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_type_i6_ (GALGAS_lstring & outArgument_attributeName,
                                                                                                 GALGAS_impType & outArgument_type,
                                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_attributeName.drop () ; // Release 'out' argument
  outArgument_type.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 216)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 216)), inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 218)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 218)), inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 220)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 220)), inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 222)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 222)), inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 224)) ;
    nt_number_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_parser.galgas", 224)), inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) COMMA_SOURCE_FILE ("implementation_parser.galgas", 226)) ;
    nt_enum_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) COMMA_SOURCE_FILE ("implementation_parser.galgas", 228)) ;
    nt_boolean_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) COMMA_SOURCE_FILE ("implementation_parser.galgas", 230)) ;
    nt_string_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) COMMA_SOURCE_FILE ("implementation_parser.galgas", 232)) ;
    nt_type_5F_options_ (outArgument_attributeName, outArgument_type, GALGAS_dataType::constructor_identifier (SOURCE_FILE ("implementation_parser.galgas", 232)), inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 234)) ;
    nt_struct_5F_options_ (outArgument_attributeName, outArgument_type, inCompiler) ;
  } break ;
  case 11: {
    GALGAS_lstring var_typeName_6752 ;
    var_typeName_6752 = inCompiler->synthetizedAttribute_att_5F_token () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 236)) ;
    nt_objref_5F_option_ (outArgument_attributeName, outArgument_type, var_typeName_6752, inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_implementation_5F_type_i6_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 216)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 218)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 220)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 222)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 224)) ;
    nt_number_5F_options_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) COMMA_SOURCE_FILE ("implementation_parser.galgas", 226)) ;
    nt_enum_5F_options_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) COMMA_SOURCE_FILE ("implementation_parser.galgas", 228)) ;
    nt_boolean_5F_options_parse (inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) COMMA_SOURCE_FILE ("implementation_parser.galgas", 230)) ;
    nt_string_5F_options_parse (inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) COMMA_SOURCE_FILE ("implementation_parser.galgas", 232)) ;
    nt_type_5F_options_parse (inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 234)) ;
    nt_struct_5F_options_parse (inCompiler) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 236)) ;
    nt_objref_5F_option_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_struct_5F_options_i7_ (GALGAS_lstring & outArgument_name,
                                                                                            GALGAS_impType & outArgument_options,
                                                                                            C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_implementationObjectMap var_structAttributes_6908 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 243)) ;
  switch (select_implementation_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 245)) ;
    nt_implementation_5F_list_ (var_structAttributes_6908, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 247)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_7076 ;
  nt_multiple_ (var_multiple_7076, inCompiler) ;
  GALGAS_lstring var_description_7122 ;
  nt_description_ (var_description_7122, inCompiler) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 254)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 254))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 254)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 254)) ;
  temp_1.addAssign_operation (var_description_7122  COMMA_SOURCE_FILE ("implementation_parser.galgas", 254)) ;
  outArgument_options = GALGAS_impStructType::constructor_new (temp_0, GALGAS_dataType::constructor_structType (SOURCE_FILE ("implementation_parser.galgas", 254)), outArgument_name, var_multiple_7076, temp_1, var_structAttributes_6908  COMMA_SOURCE_FILE ("implementation_parser.galgas", 254)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_struct_5F_options_i7_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 245)) ;
    nt_implementation_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 247)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  nt_description_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_objref_5F_option_i8_ (GALGAS_lstring & outArgument_name,
                                                                                           GALGAS_impType & outArgument_options,
                                                                                           GALGAS_lstring inArgument_ref,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_ref.getter_string (SOURCE_FILE ("implementation_parser.galgas", 261)).getter_rightSubString (GALGAS_uint ((uint32_t) 5U) COMMA_SOURCE_FILE ("implementation_parser.galgas", 261)).objectCompare (GALGAS_string ("_TYPE"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 262)), GALGAS_string ("an object reference must end with _TYPE"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 262)) ;
  }else if (kBoolFalse == test_0) {
    inArgument_ref = GALGAS_lstring::constructor_new (inArgument_ref.mAttribute_string.getter_leftSubString (inArgument_ref.mAttribute_string.getter_length (SOURCE_FILE ("implementation_parser.galgas", 264)).substract_operation (GALGAS_uint ((uint32_t) 5U), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 264)) COMMA_SOURCE_FILE ("implementation_parser.galgas", 264)), inArgument_ref.getter_location (SOURCE_FILE ("implementation_parser.galgas", 264))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 264)) ;
  }
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_7623 ;
  nt_multiple_ (var_multiple_7623, inCompiler) ;
  GALGAS_lstring var_description_7669 ;
  nt_description_ (var_description_7669, inCompiler) ;
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 271)) ;
  temp_2.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 271))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 271)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 271)) ;
  temp_3.addAssign_operation (var_description_7669  COMMA_SOURCE_FILE ("implementation_parser.galgas", 271)) ;
  outArgument_options = GALGAS_refType::constructor_new (temp_2, GALGAS_dataType::constructor_objectType (SOURCE_FILE ("implementation_parser.galgas", 271)), outArgument_name, var_multiple_7623, temp_3, inArgument_ref  COMMA_SOURCE_FILE ("implementation_parser.galgas", 271)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_objref_5F_option_i8_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  nt_description_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_string_5F_options_i9_ (GALGAS_lstring & outArgument_name,
                                                                                            GALGAS_impType & outArgument_options,
                                                                                            C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_7890 ;
  nt_with_5F_auto_ (var_withAuto_7890, inCompiler) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_7965 ;
  nt_multiple_ (var_multiple_7965, inCompiler) ;
  GALGAS_object_5F_t var_defaultValue_8013 ;
  GALGAS_lstring var_oil_5F_desc_8033 ;
  switch (select_implementation_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 286)) ;
    switch (select_implementation_5F_parser_10 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_stringValue_8102 = inCompiler->synthetizedAttribute_a_5F_string () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 288)) ;
      nt_description_ (var_oil_5F_desc_8033, inCompiler) ;
      var_defaultValue_8013 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_8033, var_stringValue_8102.getter_location (SOURCE_FILE ("implementation_parser.galgas", 290)), var_stringValue_8102.getter_string (SOURCE_FILE ("implementation_parser.galgas", 290))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 290)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 292)) ;
      nt_description_ (var_oil_5F_desc_8033, inCompiler) ;
      var_defaultValue_8013 = GALGAS_auto::constructor_new (var_oil_5F_desc_8033, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 294))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 294)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 296)) ;
      nt_description_ (var_oil_5F_desc_8033, inCompiler) ;
      var_defaultValue_8013 = GALGAS_void::constructor_new (var_oil_5F_desc_8033, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 298))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 298)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_8033, inCompiler) ;
    var_defaultValue_8013 = GALGAS_void::constructor_new (var_oil_5F_desc_8033, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 302))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 302)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 304)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 304))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 304)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 304)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_8033  COMMA_SOURCE_FILE ("implementation_parser.galgas", 304)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_0, GALGAS_dataType::constructor_string (SOURCE_FILE ("implementation_parser.galgas", 304)), outArgument_name, var_multiple_7965, temp_1, var_withAuto_7890, var_defaultValue_8013  COMMA_SOURCE_FILE ("implementation_parser.galgas", 304)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_string_5F_options_i9_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 286)) ;
    switch (select_implementation_5F_parser_10 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) COMMA_SOURCE_FILE ("implementation_parser.galgas", 288)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 292)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 296)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_boolean_5F_options_i10_ (GALGAS_lstring & outArgument_name,
                                                                                              GALGAS_impType & outArgument_options,
                                                                                              C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_8778 ;
  nt_with_5F_auto_ (var_withAuto_8778, inCompiler) ;
  GALGAS_implementationObjectMap var_trueSubAttributes_8826 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 312)) ;
  GALGAS_implementationObjectMap var_falseSubAttributes_8888 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 313)) ;
  switch (select_implementation_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 315)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_SOURCE_FILE ("implementation_parser.galgas", 316)) ;
    switch (select_implementation_5F_parser_12 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 318)) ;
      nt_implementation_5F_list_ (var_trueSubAttributes_8826, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 320)) ;
    } break ;
    case 2: {
      var_trueSubAttributes_8826 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 322)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 324)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_SOURCE_FILE ("implementation_parser.galgas", 325)) ;
    switch (select_implementation_5F_parser_13 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 327)) ;
      nt_implementation_5F_list_ (var_falseSubAttributes_8888, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 329)) ;
    } break ;
    case 2: {
      var_falseSubAttributes_8888 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 331)) ;
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 333)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_9355 ;
  nt_multiple_ (var_multiple_9355, inCompiler) ;
  GALGAS_object_5F_t var_defaultValue_9403 ;
  GALGAS_lstring var_oil_5F_desc_9423 ;
  switch (select_implementation_5F_parser_14 (inCompiler)) {
  case 1: {
    GALGAS_lbool var_boolValue_9453 ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 342)) ;
    nt_boolean_ (var_boolValue_9453, inCompiler) ;
    nt_description_ (var_oil_5F_desc_9423, inCompiler) ;
    var_defaultValue_9403 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_9423, var_boolValue_9453.getter_location (SOURCE_FILE ("implementation_parser.galgas", 344)), var_boolValue_9453.getter_bool (SOURCE_FILE ("implementation_parser.galgas", 344)), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 344))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 344))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 344)) ;
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_9423, inCompiler) ;
    var_defaultValue_9403 = GALGAS_void::constructor_new (var_oil_5F_desc_9423, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 347))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 347)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 349)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 349))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 349)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 349)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_9423  COMMA_SOURCE_FILE ("implementation_parser.galgas", 349)) ;
  outArgument_options = GALGAS_impBoolType::constructor_new (temp_0, GALGAS_dataType::constructor_boolean (SOURCE_FILE ("implementation_parser.galgas", 349)), outArgument_name, var_multiple_9355, temp_1, var_withAuto_8778, var_defaultValue_9403, var_trueSubAttributes_8826, var_falseSubAttributes_8888  COMMA_SOURCE_FILE ("implementation_parser.galgas", 349)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_boolean_5F_options_i10_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  switch (select_implementation_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 315)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) COMMA_SOURCE_FILE ("implementation_parser.galgas", 316)) ;
    switch (select_implementation_5F_parser_12 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 318)) ;
      nt_implementation_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 320)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 324)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) COMMA_SOURCE_FILE ("implementation_parser.galgas", 325)) ;
    switch (select_implementation_5F_parser_13 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 327)) ;
      nt_implementation_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 329)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 333)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 342)) ;
    nt_boolean_parse (inCompiler) ;
    nt_description_parse (inCompiler) ;
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_item_i11_ (GALGAS_enumValues & ioArgument_items,
                                                                                        C_Lexique_goil_5F_lexique * inCompiler) {
  GALGAS_lstring var_enumItem_9980 ;
  GALGAS_implementationObjectMap var_subAttributes_10000 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 355)) ;
  nt_identifier_5F_or_5F_enum_5F_value_ (var_enumItem_9980, inCompiler) ;
  switch (select_implementation_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 358)) ;
    nt_implementation_5F_list_ (var_subAttributes_10000, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 360)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  {
  ioArgument_items.setter_put (var_enumItem_9980, var_subAttributes_10000, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 362)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_item_i11_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_identifier_5F_or_5F_enum_5F_value_parse (inCompiler) ;
  switch (select_implementation_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 358)) ;
    nt_implementation_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 360)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_options_i12_ (GALGAS_lstring & outArgument_name,
                                                                                           GALGAS_impType & outArgument_options,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_10272 ;
  nt_with_5F_auto_ (var_withAuto_10272, inCompiler) ;
  GALGAS_enumValues var_items_10308 = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 370)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 371)) ;
  nt_enum_5F_item_ (var_items_10308, inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_16 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 375)) ;
      nt_enum_5F_item_ (var_items_10308, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 377)) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_10468 ;
  nt_multiple_ (var_multiple_10468, inCompiler) ;
  GALGAS_lstring var_oil_5F_desc_10511 ;
  GALGAS_object_5F_t var_defaultValue_10536 ;
  switch (select_implementation_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 384)) ;
    switch (select_implementation_5F_parser_18 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_stringValue_10591 ;
      var_stringValue_10591 = inCompiler->synthetizedAttribute_att_5F_token () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 387)) ;
      nt_description_ (var_oil_5F_desc_10511, inCompiler) ;
      var_defaultValue_10536 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_10511, var_stringValue_10591.getter_location (SOURCE_FILE ("implementation_parser.galgas", 389)), var_stringValue_10591.getter_string (SOURCE_FILE ("implementation_parser.galgas", 389)), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("implementation_parser.galgas", 389))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 389))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 389)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 391)) ;
      nt_description_ (var_oil_5F_desc_10511, inCompiler) ;
      var_defaultValue_10536 = GALGAS_auto::constructor_new (var_oil_5F_desc_10511, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 393))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 393)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 395)) ;
      nt_description_ (var_oil_5F_desc_10511, inCompiler) ;
      var_defaultValue_10536 = GALGAS_void::constructor_new (var_oil_5F_desc_10511, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 397))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 397)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_10511, inCompiler) ;
    var_defaultValue_10536 = GALGAS_void::constructor_new (var_oil_5F_desc_10511, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 401))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 401)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_1 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 403)) ;
  temp_1.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 403))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 403)) ;
  GALGAS_lstringlist temp_2 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 403)) ;
  temp_2.addAssign_operation (var_oil_5F_desc_10511  COMMA_SOURCE_FILE ("implementation_parser.galgas", 403)) ;
  outArgument_options = GALGAS_impEnumType::constructor_new (temp_1, GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("implementation_parser.galgas", 403)), outArgument_name, var_multiple_10468, temp_2, var_withAuto_10272, var_defaultValue_10536, var_items_10308  COMMA_SOURCE_FILE ("implementation_parser.galgas", 403)) ;
  {
  routine_verifyEnum (outArgument_options, inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 404)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_enum_5F_options_i12_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 371)) ;
  nt_enum_5F_item_parse (inCompiler) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_16 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 375)) ;
      nt_enum_5F_item_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 377)) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 384)) ;
    switch (select_implementation_5F_parser_18 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 387)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 391)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 395)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_number_5F_options_i13_ (GALGAS_lstring & outArgument_name,
                                                                                             GALGAS_impType & outArgument_options,
                                                                                             const GALGAS_dataType constinArgument_type,
                                                                                             C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_11397 ;
  nt_with_5F_auto_ (var_withAuto_11397, inCompiler) ;
  GALGAS_attributeRange var_range_11445 ;
  nt_range_ (var_range_11445, constinArgument_type, inCompiler) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_11519 ;
  nt_multiple_ (var_multiple_11519, inCompiler) ;
  GALGAS_lstring var_oil_5F_desc_11562 ;
  GALGAS_object_5F_t var_defaultValue_11587 ;
  switch (select_implementation_5F_parser_19 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 421)) ;
    switch (select_implementation_5F_parser_20 (inCompiler)) {
    case 1: {
      nt_int_5F_or_5F_float_ (var_defaultValue_11587, constinArgument_type, inCompiler) ;
      var_oil_5F_desc_11562 = var_defaultValue_11587.getter_oil_5F_desc (SOURCE_FILE ("implementation_parser.galgas", 424)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 426)) ;
      nt_description_ (var_oil_5F_desc_11562, inCompiler) ;
      var_defaultValue_11587 = GALGAS_void::constructor_new (var_oil_5F_desc_11562, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 428))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 428)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 430)) ;
      nt_description_ (var_oil_5F_desc_11562, inCompiler) ;
      var_defaultValue_11587 = GALGAS_auto::constructor_new (var_oil_5F_desc_11562, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 432))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 432)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_11562, inCompiler) ;
    var_defaultValue_11587 = GALGAS_void::constructor_new (var_oil_5F_desc_11562, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 436))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 436)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 438)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 438))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 438)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 438)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_11562  COMMA_SOURCE_FILE ("implementation_parser.galgas", 438)) ;
  outArgument_options = GALGAS_impRangedType::constructor_new (temp_0, constinArgument_type, outArgument_name, var_multiple_11519, temp_1, var_withAuto_11397, var_defaultValue_11587, var_range_11445  COMMA_SOURCE_FILE ("implementation_parser.galgas", 438)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_number_5F_options_i13_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  nt_range_parse (inCompiler) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_19 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 421)) ;
    switch (select_implementation_5F_parser_20 (inCompiler)) {
    case 1: {
      nt_int_5F_or_5F_float_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 426)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 430)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_type_5F_options_i14_ (GALGAS_lstring & outArgument_name,
                                                                                           GALGAS_impType & outArgument_options,
                                                                                           const GALGAS_dataType constinArgument_type,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_bool var_withAuto_12252 ;
  nt_with_5F_auto_ (var_withAuto_12252, inCompiler) ;
  nt_identifier_5F_or_5F_attribute_ (outArgument_name, inCompiler) ;
  GALGAS_bool var_multiple_12327 ;
  nt_multiple_ (var_multiple_12327, inCompiler) ;
  GALGAS_object_5F_t var_defaultValue_12375 ;
  GALGAS_lstring var_oil_5F_desc_12395 ;
  switch (select_implementation_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 453)) ;
    switch (select_implementation_5F_parser_22 (inCompiler)) {
    case 1: {
      GALGAS_lstring var_ident_12444 ;
      nt_identifier_5F_or_5F_attribute_ (var_ident_12444, inCompiler) ;
      nt_description_ (var_oil_5F_desc_12395, inCompiler) ;
      var_defaultValue_12375 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_12395, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 458)), var_ident_12444.getter_string (SOURCE_FILE ("implementation_parser.galgas", 458))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 458)) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 460)) ;
      nt_description_ (var_oil_5F_desc_12395, inCompiler) ;
      var_defaultValue_12375 = GALGAS_void::constructor_new (var_oil_5F_desc_12395, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 462))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 462)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 464)) ;
      nt_description_ (var_oil_5F_desc_12395, inCompiler) ;
      var_defaultValue_12375 = GALGAS_auto::constructor_new (var_oil_5F_desc_12395, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 466))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 466)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_ (var_oil_5F_desc_12395, inCompiler) ;
    var_defaultValue_12375 = GALGAS_void::constructor_new (var_oil_5F_desc_12395, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 470))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 470)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 472)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 472))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 472)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("implementation_parser.galgas", 472)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_12395  COMMA_SOURCE_FILE ("implementation_parser.galgas", 472)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_0, constinArgument_type, outArgument_name, var_multiple_12327, temp_1, var_withAuto_12252, var_defaultValue_12375  COMMA_SOURCE_FILE ("implementation_parser.galgas", 472)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_type_5F_options_i14_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_with_5F_auto_parse (inCompiler) ;
  nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
  nt_multiple_parse (inCompiler) ;
  switch (select_implementation_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 453)) ;
    switch (select_implementation_5F_parser_22 (inCompiler)) {
    case 1: {
      nt_identifier_5F_or_5F_attribute_parse (inCompiler) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) COMMA_SOURCE_FILE ("implementation_parser.galgas", 460)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 464)) ;
      nt_description_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_with_5F_auto_i15_ (GALGAS_bool & outArgument_withAuto,
                                                                                        C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_withAuto.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 478)) ;
    outArgument_withAuto = GALGAS_bool (true) ;
  } break ;
  case 2: {
    outArgument_withAuto = GALGAS_bool (false) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_with_5F_auto_i15_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) COMMA_SOURCE_FILE ("implementation_parser.galgas", 478)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_int_5F_or_5F_float_i16_ (GALGAS_object_5F_t & outArgument_num,
                                                                                              const GALGAS_dataType constinArgument_type,
                                                                                              C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_num.drop () ; // Release 'out' argument
  GALGAS_bool var_signed_13245 ;
  nt_sign_ (var_signed_13245, inCompiler) ;
  switch (select_implementation_5F_parser_24 (inCompiler)) {
  case 1: {
    GALGAS_luint_36__34_ var_number_13291 ;
    var_number_13291 = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 491)) ;
    GALGAS_lstring var_oil_5F_desc_13359 ;
    nt_description_ (var_oil_5F_desc_13359, inCompiler) ;
    outArgument_num = function_checkAndGetIntegerNumber (var_oil_5F_desc_13359, constinArgument_type, var_number_13291, var_signed_13245, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 493)) ;
  } break ;
  case 2: {
    GALGAS_ldouble var_number_13452 ;
    var_number_13452 = inCompiler->synthetizedAttribute_floatNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 496)) ;
    GALGAS_lstring var_oil_5F_desc_13520 ;
    nt_description_ (var_oil_5F_desc_13520, inCompiler) ;
    outArgument_num = function_checkAndGetFloatNumber (var_oil_5F_desc_13520, constinArgument_type, var_number_13452, var_signed_13245, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 498)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_sign_parse (inCompiler) ;
  switch (select_implementation_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 491)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 496)) ;
    nt_description_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_set_5F_followup_i17_ (GALGAS_numberList & ioArgument_numbers,
                                                                                           const GALGAS_dataType constinArgument_type,
                                                                                           C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_25 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 507)) ;
      GALGAS_object_5F_t var_num_13706 ;
      nt_int_5F_or_5F_float_ (var_num_13706, constinArgument_type, inCompiler) ;
      ioArgument_numbers.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 510)), var_num_13706  COMMA_SOURCE_FILE ("implementation_parser.galgas", 510)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_set_5F_followup_i17_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_implementation_5F_parser_25 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 507)) ;
      nt_int_5F_or_5F_float_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_5F_content_i18_ (GALGAS_attributeRange & outArgument_range,
                                                                                            const GALGAS_dataType constinArgument_type,
                                                                                            C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_range.drop () ; // Release 'out' argument
  GALGAS_object_5F_t var_start_13869 = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 517)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 517))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 517)) ;
  GALGAS_object_5F_t var_stop_13934 = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 518)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 518))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 518)) ;
  GALGAS_bool var_signed_13997 ;
  nt_sign_ (var_signed_13997, inCompiler) ;
  switch (select_implementation_5F_parser_26 (inCompiler)) {
  case 1: {
    GALGAS_luint_36__34_ var_number_14043 ;
    var_number_14043 = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 523)) ;
    var_start_13869 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 524)), constinArgument_type, var_number_14043, var_signed_13997, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 524)) ;
    nt_int_5F_or_5F_float_ (var_stop_13934, constinArgument_type, inCompiler) ;
    outArgument_range = function_buildRange (constinArgument_type, var_start_13869, var_stop_13934, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 526)) ;
  } break ;
  case 2: {
    GALGAS_luint_36__34_ var_number_14254 ;
    var_number_14254 = inCompiler->synthetizedAttribute_integerNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 529)) ;
    var_start_13869 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 530)), constinArgument_type, var_number_14254, var_signed_13997, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 530)) ;
    switch (select_implementation_5F_parser_27 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 532)) ;
      nt_int_5F_or_5F_float_ (var_stop_13934, constinArgument_type, inCompiler) ;
      outArgument_range = function_buildRange (constinArgument_type, var_start_13869, var_stop_13934, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 533)) ;
    } break ;
    case 2: {
      GALGAS_numberList var_numbers_14483 = GALGAS_numberList::constructor_listWithValue (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 535)), var_start_13869  COMMA_SOURCE_FILE ("implementation_parser.galgas", 535)) ;
      nt_set_5F_followup_ (var_numbers_14483, constinArgument_type, inCompiler) ;
      outArgument_range = function_attributeRangeWithNumberList (var_numbers_14483, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 537)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    GALGAS_ldouble var_number_14667 ;
    var_number_14667 = inCompiler->synthetizedAttribute_floatNumber () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 541)) ;
    var_start_13869 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 542)), constinArgument_type, var_number_14667, var_signed_13997, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 542)) ;
    switch (select_implementation_5F_parser_28 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 544)) ;
      nt_int_5F_or_5F_float_ (var_stop_13934, constinArgument_type, inCompiler) ;
      outArgument_range = function_buildRange (constinArgument_type, var_start_13869, var_stop_13934, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 545)) ;
    } break ;
    case 2: {
      GALGAS_numberList var_numbers_14895 = GALGAS_numberList::constructor_listWithValue (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 547)), var_start_13869  COMMA_SOURCE_FILE ("implementation_parser.galgas", 547)) ;
      nt_set_5F_followup_ (var_numbers_14895, constinArgument_type, inCompiler) ;
      outArgument_range = function_attributeRangeWithNumberList (var_numbers_14895, constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 549)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_5F_content_i18_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  nt_sign_parse (inCompiler) ;
  switch (select_implementation_5F_parser_26 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 523)) ;
    nt_int_5F_or_5F_float_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 529)) ;
    switch (select_implementation_5F_parser_27 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 532)) ;
      nt_int_5F_or_5F_float_parse (inCompiler) ;
    } break ;
    case 2: {
      nt_set_5F_followup_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) COMMA_SOURCE_FILE ("implementation_parser.galgas", 541)) ;
    switch (select_implementation_5F_parser_28 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 544)) ;
      nt_int_5F_or_5F_float_parse (inCompiler) ;
    } break ;
    case 2: {
      nt_set_5F_followup_parse (inCompiler) ;
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_i19_ (GALGAS_attributeRange & outArgument_range,
                                                                                 const GALGAS_dataType constinArgument_rangeType,
                                                                                 C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_range.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_29 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 558)) ;
    nt_range_5F_content_ (outArgument_range, constinArgument_rangeType, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 558)) ;
  } break ;
  case 2: {
    outArgument_range = GALGAS_noRange::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 560))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 560)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_range_i19_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_29 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 558)) ;
    nt_range_5F_content_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 558)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_multiple_i20_ (GALGAS_bool & outArgument_multi,
                                                                                    C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_multi.drop () ; // Release 'out' argument
  switch (select_implementation_5F_parser_30 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 567)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 567)) ;
    outArgument_multi = GALGAS_bool (true) ;
  } break ;
  case 2: {
    outArgument_multi = GALGAS_bool (false) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_multiple_i20_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  switch (select_implementation_5F_parser_30 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 567)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) COMMA_SOURCE_FILE ("implementation_parser.galgas", 567)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_ (GALGAS_lstring & outArgument_name,
                                                                                                         C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_name = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 576)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 576)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_ (GALGAS_lstring & outArgument_name,
                                                                                                             C_Lexique_goil_5F_lexique * inCompiler) {
  outArgument_name.drop () ; // Release 'out' argument
  outArgument_name = inCompiler->synthetizedAttribute_att_5F_token () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 584)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_implementation_5F_parser::rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse (C_Lexique_goil_5F_lexique * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) COMMA_SOURCE_FILE ("implementation_parser.galgas", 584)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_goil_file_level_include [] = {
// At index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
  TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) // $IMPLEMENTATION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (14) // <implementation_object_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 7 : <start>, in file 'goil_syntax.ggs', line 38
, NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 10 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 12 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (37) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 14 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (38) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 16 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 22 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 30 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (41) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (43) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 425
, NONTERMINAL (48) // <select_goil_5F_syntax_12>
, NONTERMINAL (49) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
, NONTERMINAL (50) // <select_goil_5F_syntax_14>
, NONTERMINAL (51) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 46 : <include_object_level>, in file 'goil_syntax.ggs', line 473
, NONTERMINAL (52) // <select_goil_5F_syntax_16>
, NONTERMINAL (53) // <select_goil_5F_syntax_17>
, END_PRODUCTION
// At index 49 : <implementation_object_list>, in file 'implementation_parser.ggs', line 62
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 51 : <include_implementation_level>, in file 'implementation_parser.ggs', line 71
, NONTERMINAL (55) // <select_implementation_5F_parser_1>
, NONTERMINAL (56) // <select_implementation_5F_parser_2>
, END_PRODUCTION
// At index 54 : <include_type_level>, in file 'implementation_parser.ggs', line 92
, NONTERMINAL (57) // <select_implementation_5F_parser_3>
, NONTERMINAL (58) // <select_implementation_5F_parser_4>
, END_PRODUCTION
// At index 57 : <implementation_objects>, in file 'implementation_parser.ggs', line 135
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (59) // <select_implementation_5F_parser_5>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 63 : <implementation_list>, in file 'implementation_parser.ggs', line 183
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 65 : <implementation_type>, in file 'implementation_parser.ggs', line 212
, NONTERMINAL (61) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 67 : <struct_options>, in file 'implementation_parser.ggs', line 240
, NONTERMINAL (62) // <select_implementation_5F_parser_8>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 72 : <objref_option>, in file 'implementation_parser.ggs', line 257
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 76 : <string_options>, in file 'implementation_parser.ggs', line 275
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 81 : <boolean_options>, in file 'implementation_parser.ggs', line 307
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (65) // <select_implementation_5F_parser_11>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (68) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 87 : <enum_item>, in file 'implementation_parser.ggs', line 352
, NONTERMINAL (35) // <identifier_or_enum_value>
, NONTERMINAL (69) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 90 : <enum_options>, in file 'implementation_parser.ggs', line 365
, NONTERMINAL (28) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (71) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <number_options>, in file 'implementation_parser.ggs', line 407
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (32) // <range>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 105 : <type_options>, in file 'implementation_parser.ggs', line 441
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 110 : <with_auto>, in file 'implementation_parser.ggs', line 475
, NONTERMINAL (77) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 112 : <int_or_float>, in file 'implementation_parser.ggs', line 484
, NONTERMINAL (3) // <sign>
, NONTERMINAL (78) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 115 : <set_followup>, in file 'implementation_parser.ggs', line 502
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 117 : <range_content>, in file 'implementation_parser.ggs', line 514
, NONTERMINAL (3) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 120 : <range>, in file 'implementation_parser.ggs', line 554
, NONTERMINAL (83) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 122 : <multiple>, in file 'implementation_parser.ggs', line 564
, NONTERMINAL (84) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 124 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 574
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 126 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 579
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 128 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 135 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 143 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 149 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 153 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 162 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 165 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 167 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 169 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, END_PRODUCTION
// At index 170 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 173 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (44) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 189 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (3) // <sign>
, NONTERMINAL (46) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (47) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 202 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, END_PRODUCTION
// At index 207 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 213 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 217 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, END_PRODUCTION
// At index 218 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 220 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 224 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 228 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 230 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 232 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 234 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 236 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 238 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 240 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 242 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
, END_PRODUCTION
// At index 243 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
, NONTERMINAL (17) // <implementation_objects>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 247 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
, NONTERMINAL (15) // <include_implementation_level>
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 250 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 252 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 254 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 256 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 258 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 260 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 262 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 264 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 266 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 269 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
, END_PRODUCTION
// At index 270 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
, END_PRODUCTION
// At index 271 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
, NONTERMINAL (19) // <implementation_type>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 275 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
, NONTERMINAL (16) // <include_type_level>
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 278 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 281 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (25) // <enum_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (23) // <boolean_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (22) // <string_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (27) // <type_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (20) // <struct_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <objref_option>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 315 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 321 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 327 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (66) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (67) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 338 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
, END_PRODUCTION
// At index 344 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 359 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
, END_PRODUCTION
// At index 361 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 365 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (72) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 373 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 376 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 386 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 389 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 392 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 397 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 400 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 403 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 408 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
, END_PRODUCTION
// At index 416 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (29) // <int_or_float>
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 420 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 423 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (81) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 426 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (82) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 434 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 437 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 439 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (31) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
, END_PRODUCTION
// At index 444 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 447 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
, END_PRODUCTION
// At index 448 : <>, in file '.ggs', line 0
, NONTERMINAL (2) // <file>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_file_level_include [159] = {
 {"<implementation_definition>", "implementation_parser", 0}, // at index 0
 {"<start>", "goil_syntax", 7}, // at index 1
 {"<file>", "goil_syntax", 10}, // at index 2
 {"<sign>", "goil_syntax", 12}, // at index 3
 {"<description>", "goil_syntax", 14}, // at index 4
 {"<OIL_version>", "goil_syntax", 16}, // at index 5
 {"<application_definition>", "goil_syntax", 22}, // at index 6
 {"<object_definition_list>", "goil_syntax", 30}, // at index 7
 {"<boolean>", "goil_syntax", 32}, // at index 8
 {"<oil_declaration_list>", "goil_syntax", 34}, // at index 9
 {"<oil_declaration>", "goil_syntax", 36}, // at index 10
 {"<include_file_level>", "goil_syntax", 40}, // at index 11
 {"<include_cpu_level>", "goil_syntax", 43}, // at index 12
 {"<include_object_level>", "goil_syntax", 46}, // at index 13
 {"<implementation_object_list>", "implementation_parser", 49}, // at index 14
 {"<include_implementation_level>", "implementation_parser", 51}, // at index 15
 {"<include_type_level>", "implementation_parser", 54}, // at index 16
 {"<implementation_objects>", "implementation_parser", 57}, // at index 17
 {"<implementation_list>", "implementation_parser", 63}, // at index 18
 {"<implementation_type>", "implementation_parser", 65}, // at index 19
 {"<struct_options>", "implementation_parser", 67}, // at index 20
 {"<objref_option>", "implementation_parser", 72}, // at index 21
 {"<string_options>", "implementation_parser", 76}, // at index 22
 {"<boolean_options>", "implementation_parser", 81}, // at index 23
 {"<enum_item>", "implementation_parser", 87}, // at index 24
 {"<enum_options>", "implementation_parser", 90}, // at index 25
 {"<number_options>", "implementation_parser", 99}, // at index 26
 {"<type_options>", "implementation_parser", 105}, // at index 27
 {"<with_auto>", "implementation_parser", 110}, // at index 28
 {"<int_or_float>", "implementation_parser", 112}, // at index 29
 {"<set_followup>", "implementation_parser", 115}, // at index 30
 {"<range_content>", "implementation_parser", 117}, // at index 31
 {"<range>", "implementation_parser", 120}, // at index 32
 {"<multiple>", "implementation_parser", 122}, // at index 33
 {"<identifier_or_attribute>", "implementation_parser", 124}, // at index 34
 {"<identifier_or_enum_value>", "implementation_parser", 126}, // at index 35
 {"<select_goil_5F_syntax_0>", "goil_syntax", 128}, // at index 36
 {"<select_goil_5F_syntax_0>", "goil_syntax", 129}, // at index 37
 {"<select_goil_5F_syntax_0>", "goil_syntax", 132}, // at index 38
 {"<select_goil_5F_syntax_0>", "goil_syntax", 135}, // at index 39
 {"<select_goil_5F_syntax_1>", "goil_syntax", 138}, // at index 40
 {"<select_goil_5F_syntax_1>", "goil_syntax", 140}, // at index 41
 {"<select_goil_5F_syntax_1>", "goil_syntax", 142}, // at index 42
 {"<select_goil_5F_syntax_2>", "goil_syntax", 143}, // at index 43
 {"<select_goil_5F_syntax_2>", "goil_syntax", 144}, // at index 44
 {"<select_goil_5F_syntax_3>", "goil_syntax", 148}, // at index 45
 {"<select_goil_5F_syntax_3>", "goil_syntax", 149}, // at index 46
 {"<select_goil_5F_syntax_4>", "goil_syntax", 152}, // at index 47
 {"<select_goil_5F_syntax_4>", "goil_syntax", 153}, // at index 48
 {"<select_goil_5F_syntax_4>", "goil_syntax", 162}, // at index 49
 {"<select_goil_5F_syntax_5>", "goil_syntax", 165}, // at index 50
 {"<select_goil_5F_syntax_5>", "goil_syntax", 167}, // at index 51
 {"<select_goil_5F_syntax_6>", "goil_syntax", 169}, // at index 52
 {"<select_goil_5F_syntax_6>", "goil_syntax", 170}, // at index 53
 {"<select_goil_5F_syntax_6>", "goil_syntax", 173}, // at index 54
 {"<select_goil_5F_syntax_7>", "goil_syntax", 176}, // at index 55
 {"<select_goil_5F_syntax_7>", "goil_syntax", 179}, // at index 56
 {"<select_goil_5F_syntax_8>", "goil_syntax", 185}, // at index 57
 {"<select_goil_5F_syntax_8>", "goil_syntax", 189}, // at index 58
 {"<select_goil_5F_syntax_8>", "goil_syntax", 192}, // at index 59
 {"<select_goil_5F_syntax_8>", "goil_syntax", 196}, // at index 60
 {"<select_goil_5F_syntax_8>", "goil_syntax", 199}, // at index 61
 {"<select_goil_5F_syntax_9>", "goil_syntax", 202}, // at index 62
 {"<select_goil_5F_syntax_9>", "goil_syntax", 206}, // at index 63
 {"<select_goil_5F_syntax_10>", "goil_syntax", 207}, // at index 64
 {"<select_goil_5F_syntax_10>", "goil_syntax", 210}, // at index 65
 {"<select_goil_5F_syntax_11>", "goil_syntax", 213}, // at index 66
 {"<select_goil_5F_syntax_11>", "goil_syntax", 217}, // at index 67
 {"<select_goil_5F_syntax_12>", "goil_syntax", 218}, // at index 68
 {"<select_goil_5F_syntax_12>", "goil_syntax", 220}, // at index 69
 {"<select_goil_5F_syntax_13>", "goil_syntax", 222}, // at index 70
 {"<select_goil_5F_syntax_13>", "goil_syntax", 224}, // at index 71
 {"<select_goil_5F_syntax_14>", "goil_syntax", 226}, // at index 72
 {"<select_goil_5F_syntax_14>", "goil_syntax", 228}, // at index 73
 {"<select_goil_5F_syntax_15>", "goil_syntax", 230}, // at index 74
 {"<select_goil_5F_syntax_15>", "goil_syntax", 232}, // at index 75
 {"<select_goil_5F_syntax_16>", "goil_syntax", 234}, // at index 76
 {"<select_goil_5F_syntax_16>", "goil_syntax", 236}, // at index 77
 {"<select_goil_5F_syntax_17>", "goil_syntax", 238}, // at index 78
 {"<select_goil_5F_syntax_17>", "goil_syntax", 240}, // at index 79
 {"<select_implementation_5F_parser_0>", "implementation_parser", 242}, // at index 80
 {"<select_implementation_5F_parser_0>", "implementation_parser", 243}, // at index 81
 {"<select_implementation_5F_parser_0>", "implementation_parser", 247}, // at index 82
 {"<select_implementation_5F_parser_1>", "implementation_parser", 250}, // at index 83
 {"<select_implementation_5F_parser_1>", "implementation_parser", 252}, // at index 84
 {"<select_implementation_5F_parser_2>", "implementation_parser", 254}, // at index 85
 {"<select_implementation_5F_parser_2>", "implementation_parser", 256}, // at index 86
 {"<select_implementation_5F_parser_3>", "implementation_parser", 258}, // at index 87
 {"<select_implementation_5F_parser_3>", "implementation_parser", 260}, // at index 88
 {"<select_implementation_5F_parser_4>", "implementation_parser", 262}, // at index 89
 {"<select_implementation_5F_parser_4>", "implementation_parser", 264}, // at index 90
 {"<select_implementation_5F_parser_5>", "implementation_parser", 266}, // at index 91
 {"<select_implementation_5F_parser_5>", "implementation_parser", 269}, // at index 92
 {"<select_implementation_5F_parser_6>", "implementation_parser", 270}, // at index 93
 {"<select_implementation_5F_parser_6>", "implementation_parser", 271}, // at index 94
 {"<select_implementation_5F_parser_6>", "implementation_parser", 275}, // at index 95
 {"<select_implementation_5F_parser_7>", "implementation_parser", 278}, // at index 96
 {"<select_implementation_5F_parser_7>", "implementation_parser", 281}, // at index 97
 {"<select_implementation_5F_parser_7>", "implementation_parser", 284}, // at index 98
 {"<select_implementation_5F_parser_7>", "implementation_parser", 287}, // at index 99
 {"<select_implementation_5F_parser_7>", "implementation_parser", 290}, // at index 100
 {"<select_implementation_5F_parser_7>", "implementation_parser", 293}, // at index 101
 {"<select_implementation_5F_parser_7>", "implementation_parser", 296}, // at index 102
 {"<select_implementation_5F_parser_7>", "implementation_parser", 299}, // at index 103
 {"<select_implementation_5F_parser_7>", "implementation_parser", 302}, // at index 104
 {"<select_implementation_5F_parser_7>", "implementation_parser", 305}, // at index 105
 {"<select_implementation_5F_parser_7>", "implementation_parser", 308}, // at index 106
 {"<select_implementation_5F_parser_8>", "implementation_parser", 311}, // at index 107
 {"<select_implementation_5F_parser_8>", "implementation_parser", 315}, // at index 108
 {"<select_implementation_5F_parser_9>", "implementation_parser", 316}, // at index 109
 {"<select_implementation_5F_parser_9>", "implementation_parser", 319}, // at index 110
 {"<select_implementation_5F_parser_10>", "implementation_parser", 321}, // at index 111
 {"<select_implementation_5F_parser_10>", "implementation_parser", 324}, // at index 112
 {"<select_implementation_5F_parser_10>", "implementation_parser", 327}, // at index 113
 {"<select_implementation_5F_parser_11>", "implementation_parser", 330}, // at index 114
 {"<select_implementation_5F_parser_11>", "implementation_parser", 338}, // at index 115
 {"<select_implementation_5F_parser_12>", "implementation_parser", 339}, // at index 116
 {"<select_implementation_5F_parser_12>", "implementation_parser", 343}, // at index 117
 {"<select_implementation_5F_parser_13>", "implementation_parser", 344}, // at index 118
 {"<select_implementation_5F_parser_13>", "implementation_parser", 348}, // at index 119
 {"<select_implementation_5F_parser_14>", "implementation_parser", 349}, // at index 120
 {"<select_implementation_5F_parser_14>", "implementation_parser", 353}, // at index 121
 {"<select_implementation_5F_parser_15>", "implementation_parser", 355}, // at index 122
 {"<select_implementation_5F_parser_15>", "implementation_parser", 359}, // at index 123
 {"<select_implementation_5F_parser_16>", "implementation_parser", 360}, // at index 124
 {"<select_implementation_5F_parser_16>", "implementation_parser", 361}, // at index 125
 {"<select_implementation_5F_parser_17>", "implementation_parser", 365}, // at index 126
 {"<select_implementation_5F_parser_17>", "implementation_parser", 368}, // at index 127
 {"<select_implementation_5F_parser_18>", "implementation_parser", 370}, // at index 128
 {"<select_implementation_5F_parser_18>", "implementation_parser", 373}, // at index 129
 {"<select_implementation_5F_parser_18>", "implementation_parser", 376}, // at index 130
 {"<select_implementation_5F_parser_19>", "implementation_parser", 379}, // at index 131
 {"<select_implementation_5F_parser_19>", "implementation_parser", 382}, // at index 132
 {"<select_implementation_5F_parser_20>", "implementation_parser", 384}, // at index 133
 {"<select_implementation_5F_parser_20>", "implementation_parser", 386}, // at index 134
 {"<select_implementation_5F_parser_20>", "implementation_parser", 389}, // at index 135
 {"<select_implementation_5F_parser_21>", "implementation_parser", 392}, // at index 136
 {"<select_implementation_5F_parser_21>", "implementation_parser", 395}, // at index 137
 {"<select_implementation_5F_parser_22>", "implementation_parser", 397}, // at index 138
 {"<select_implementation_5F_parser_22>", "implementation_parser", 400}, // at index 139
 {"<select_implementation_5F_parser_22>", "implementation_parser", 403}, // at index 140
 {"<select_implementation_5F_parser_23>", "implementation_parser", 406}, // at index 141
 {"<select_implementation_5F_parser_23>", "implementation_parser", 408}, // at index 142
 {"<select_implementation_5F_parser_24>", "implementation_parser", 409}, // at index 143
 {"<select_implementation_5F_parser_24>", "implementation_parser", 412}, // at index 144
 {"<select_implementation_5F_parser_25>", "implementation_parser", 415}, // at index 145
 {"<select_implementation_5F_parser_25>", "implementation_parser", 416}, // at index 146
 {"<select_implementation_5F_parser_26>", "implementation_parser", 420}, // at index 147
 {"<select_implementation_5F_parser_26>", "implementation_parser", 423}, // at index 148
 {"<select_implementation_5F_parser_26>", "implementation_parser", 426}, // at index 149
 {"<select_implementation_5F_parser_27>", "implementation_parser", 429}, // at index 150
 {"<select_implementation_5F_parser_27>", "implementation_parser", 432}, // at index 151
 {"<select_implementation_5F_parser_28>", "implementation_parser", 434}, // at index 152
 {"<select_implementation_5F_parser_28>", "implementation_parser", 437}, // at index 153
 {"<select_implementation_5F_parser_29>", "implementation_parser", 439}, // at index 154
 {"<select_implementation_5F_parser_29>", "implementation_parser", 443}, // at index 155
 {"<select_implementation_5F_parser_30>", "implementation_parser", 444}, // at index 156
 {"<select_implementation_5F_parser_30>", "implementation_parser", 447}, // at index 157
 {"<>", "", 448} // at index 158
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_file_level_include [159] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 230
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 425
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
46, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 473
49, // index 14 : <implementation_object_list>, in file 'implementation_parser.ggs', line 62
51, // index 15 : <include_implementation_level>, in file 'implementation_parser.ggs', line 71
54, // index 16 : <include_type_level>, in file 'implementation_parser.ggs', line 92
57, // index 17 : <implementation_objects>, in file 'implementation_parser.ggs', line 135
63, // index 18 : <implementation_list>, in file 'implementation_parser.ggs', line 183
65, // index 19 : <implementation_type>, in file 'implementation_parser.ggs', line 212
67, // index 20 : <struct_options>, in file 'implementation_parser.ggs', line 240
72, // index 21 : <objref_option>, in file 'implementation_parser.ggs', line 257
76, // index 22 : <string_options>, in file 'implementation_parser.ggs', line 275
81, // index 23 : <boolean_options>, in file 'implementation_parser.ggs', line 307
87, // index 24 : <enum_item>, in file 'implementation_parser.ggs', line 352
90, // index 25 : <enum_options>, in file 'implementation_parser.ggs', line 365
99, // index 26 : <number_options>, in file 'implementation_parser.ggs', line 407
105, // index 27 : <type_options>, in file 'implementation_parser.ggs', line 441
110, // index 28 : <with_auto>, in file 'implementation_parser.ggs', line 475
112, // index 29 : <int_or_float>, in file 'implementation_parser.ggs', line 484
115, // index 30 : <set_followup>, in file 'implementation_parser.ggs', line 502
117, // index 31 : <range_content>, in file 'implementation_parser.ggs', line 514
120, // index 32 : <range>, in file 'implementation_parser.ggs', line 554
122, // index 33 : <multiple>, in file 'implementation_parser.ggs', line 564
124, // index 34 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 574
126, // index 35 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 579
128, // index 36 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
129, // index 37 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
132, // index 38 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
135, // index 39 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
138, // index 40 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
140, // index 41 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
142, // index 42 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
143, // index 43 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
144, // index 44 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
148, // index 45 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
149, // index 46 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
152, // index 47 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
153, // index 48 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
162, // index 49 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
165, // index 50 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
167, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
169, // index 52 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
170, // index 53 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
173, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
176, // index 55 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
179, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
185, // index 57 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
189, // index 58 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
192, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
196, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
199, // index 61 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
202, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
206, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
207, // index 64 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
210, // index 65 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
213, // index 66 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
217, // index 67 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
218, // index 68 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
220, // index 69 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
222, // index 70 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
224, // index 71 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
226, // index 72 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
228, // index 73 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
230, // index 74 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
232, // index 75 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
234, // index 76 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
236, // index 77 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
238, // index 78 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
240, // index 79 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
242, // index 80 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
243, // index 81 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
247, // index 82 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
250, // index 83 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
252, // index 84 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
254, // index 85 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
256, // index 86 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
258, // index 87 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
260, // index 88 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
262, // index 89 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
264, // index 90 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
266, // index 91 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
269, // index 92 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
270, // index 93 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
271, // index 94 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
275, // index 95 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
278, // index 96 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
281, // index 97 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
284, // index 98 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
287, // index 99 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
290, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
293, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
296, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
299, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
302, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
305, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
308, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
311, // index 107 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
315, // index 108 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
316, // index 109 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
319, // index 110 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
321, // index 111 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
324, // index 112 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
327, // index 113 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
330, // index 114 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
338, // index 115 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
339, // index 116 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
343, // index 117 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
344, // index 118 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
348, // index 119 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
349, // index 120 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
353, // index 121 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
355, // index 122 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
359, // index 123 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
360, // index 124 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
361, // index 125 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
365, // index 126 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
368, // index 127 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
370, // index 128 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
373, // index 129 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
376, // index 130 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
379, // index 131 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
382, // index 132 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
384, // index 133 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
386, // index 134 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
389, // index 135 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
392, // index 136 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
395, // index 137 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
397, // index 138 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
400, // index 139 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
403, // index 140 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
406, // index 141 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
408, // index 142 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
409, // index 143 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
412, // index 144 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
415, // index 145 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
416, // index 146 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
420, // index 147 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
423, // index 148 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
426, // index 149 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
429, // index 150 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
432, // index 151 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
434, // index 152 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
437, // index 153 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
439, // index 154 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
443, // index 155 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
444, // index 156 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
447, // index 157 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
448 // index 158 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_file_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
40, // at 37 : <select_goil_5F_syntax_1>
43, // at 38 : <select_goil_5F_syntax_2>
45, // at 39 : <select_goil_5F_syntax_3>
47, // at 40 : <select_goil_5F_syntax_4>
50, // at 41 : <select_goil_5F_syntax_5>
52, // at 42 : <select_goil_5F_syntax_6>
55, // at 43 : <select_goil_5F_syntax_7>
57, // at 44 : <select_goil_5F_syntax_8>
62, // at 45 : <select_goil_5F_syntax_9>
64, // at 46 : <select_goil_5F_syntax_10>
66, // at 47 : <select_goil_5F_syntax_11>
68, // at 48 : <select_goil_5F_syntax_12>
70, // at 49 : <select_goil_5F_syntax_13>
72, // at 50 : <select_goil_5F_syntax_14>
74, // at 51 : <select_goil_5F_syntax_15>
76, // at 52 : <select_goil_5F_syntax_16>
78, // at 53 : <select_goil_5F_syntax_17>
80, // at 54 : <select_implementation_5F_parser_0>
83, // at 55 : <select_implementation_5F_parser_1>
85, // at 56 : <select_implementation_5F_parser_2>
87, // at 57 : <select_implementation_5F_parser_3>
89, // at 58 : <select_implementation_5F_parser_4>
91, // at 59 : <select_implementation_5F_parser_5>
93, // at 60 : <select_implementation_5F_parser_6>
96, // at 61 : <select_implementation_5F_parser_7>
107, // at 62 : <select_implementation_5F_parser_8>
109, // at 63 : <select_implementation_5F_parser_9>
111, // at 64 : <select_implementation_5F_parser_10>
114, // at 65 : <select_implementation_5F_parser_11>
116, // at 66 : <select_implementation_5F_parser_12>
118, // at 67 : <select_implementation_5F_parser_13>
120, // at 68 : <select_implementation_5F_parser_14>
122, // at 69 : <select_implementation_5F_parser_15>
124, // at 70 : <select_implementation_5F_parser_16>
126, // at 71 : <select_implementation_5F_parser_17>
128, // at 72 : <select_implementation_5F_parser_18>
131, // at 73 : <select_implementation_5F_parser_19>
133, // at 74 : <select_implementation_5F_parser_20>
136, // at 75 : <select_implementation_5F_parser_21>
138, // at 76 : <select_implementation_5F_parser_22>
141, // at 77 : <select_implementation_5F_parser_23>
143, // at 78 : <select_implementation_5F_parser_24>
145, // at 79 : <select_implementation_5F_parser_25>
147, // at 80 : <select_implementation_5F_parser_26>
150, // at 81 : <select_implementation_5F_parser_27>
152, // at 82 : <select_implementation_5F_parser_28>
154, // at 83 : <select_implementation_5F_parser_29>
156, // at 84 : <select_implementation_5F_parser_30>
158, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_file_level_include [] = {
// At index 0 : <implementation_definition> only one production, no choice
  -1,
// At index 1 : <start> only one production, no choice
  -1,
// At index 2 : <file> only one production, no choice
  -1,
// At index 3 : <sign> only one production, no choice
  -1,
// At index 4 : <description> only one production, no choice
  -1,
// At index 5 : <OIL_version> only one production, no choice
  -1,
// At index 6 : <application_definition> only one production, no choice
  -1,
// At index 7 : <object_definition_list> only one production, no choice
  -1,
// At index 8 : <boolean> only one production, no choice
  -1,
// At index 9 : <oil_declaration_list> only one production, no choice
  -1,
// At index 10 : <oil_declaration> only one production, no choice
  -1,
// At index 11 : <include_file_level> only one production, no choice
  -1,
// At index 12 : <include_cpu_level> only one production, no choice
  -1,
// At index 13 : <include_object_level> only one production, no choice
  -1,
// At index 14 : <implementation_object_list> only one production, no choice
  -1,
// At index 15 : <include_implementation_level> only one production, no choice
  -1,
// At index 16 : <include_type_level> only one production, no choice
  -1,
// At index 17 : <implementation_objects> only one production, no choice
  -1,
// At index 18 : <implementation_list> only one production, no choice
  -1,
// At index 19 : <implementation_type> only one production, no choice
  -1,
// At index 20 : <struct_options> only one production, no choice
  -1,
// At index 21 : <objref_option> only one production, no choice
  -1,
// At index 22 : <string_options> only one production, no choice
  -1,
// At index 23 : <boolean_options> only one production, no choice
  -1,
// At index 24 : <enum_item> only one production, no choice
  -1,
// At index 25 : <enum_options> only one production, no choice
  -1,
// At index 26 : <number_options> only one production, no choice
  -1,
// At index 27 : <type_options> only one production, no choice
  -1,
// At index 28 : <with_auto> only one production, no choice
  -1,
// At index 29 : <int_or_float> only one production, no choice
  -1,
// At index 30 : <set_followup> only one production, no choice
  -1,
// At index 31 : <range_content> only one production, no choice
  -1,
// At index 32 : <range> only one production, no choice
  -1,
// At index 33 : <multiple> only one production, no choice
  -1,
// At index 34 : <identifier_or_attribute> only one production, no choice
  -1,
// At index 35 : <identifier_or_enum_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 36 : <select_goil_5F_syntax_0>
C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 46 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 55 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 62 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 69 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 77 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 82 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 90 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 95 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 111 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 117 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 122 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 128 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 133 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 138 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 143 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 148 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 153 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 158 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 166 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 171 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 176 : <select_implementation_5F_parser_3>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 181 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 186 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 191 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, C_Lexique_goil_5F_lexique::kToken_INT_33__32_, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, C_Lexique_goil_5F_lexique::kToken_INT_36__34_, C_Lexique_goil_5F_lexique::kToken_FLOAT, C_Lexique_goil_5F_lexique::kToken_ENUM, C_Lexique_goil_5F_lexique::kToken_BOOLEAN, C_Lexique_goil_5F_lexique::kToken_STRING, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 209 : <select_implementation_5F_parser_7>
C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_INT_33__32_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_INT_36__34_, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_FLOAT, -1, // Choice 5
C_Lexique_goil_5F_lexique::kToken_ENUM, -1, // Choice 6
C_Lexique_goil_5F_lexique::kToken_BOOLEAN, -1, // Choice 7
C_Lexique_goil_5F_lexique::kToken_STRING, -1, // Choice 8
C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, -1, // Choice 9
C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 10
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 11
  -1,
// At index 232 : <select_implementation_5F_parser_8>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 237 : <select_implementation_5F_parser_9>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 245 : <select_implementation_5F_parser_10>
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 252 : <select_implementation_5F_parser_11>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 257 : <select_implementation_5F_parser_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 262 : <select_implementation_5F_parser_13>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 2
  -1,
// At index 267 : <select_implementation_5F_parser_14>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 275 : <select_implementation_5F_parser_15>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 281 : <select_implementation_5F_parser_16>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 286 : <select_implementation_5F_parser_17>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 294 : <select_implementation_5F_parser_18>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 301 : <select_implementation_5F_parser_19>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 309 : <select_implementation_5F_parser_20>
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 319 : <select_implementation_5F_parser_21>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 327 : <select_implementation_5F_parser_22>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 334 : <select_implementation_5F_parser_23>
C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 2
  -1,
// At index 340 : <select_implementation_5F_parser_24>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 345 : <select_implementation_5F_parser_25>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 350 : <select_implementation_5F_parser_26>
C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 357 : <select_implementation_5F_parser_27>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 363 : <select_implementation_5F_parser_28>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 369 : <select_implementation_5F_parser_29>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 374 : <select_implementation_5F_parser_30>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3D_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 381 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_file_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
46, // at 37 : <select_goil_5F_syntax_1>
55, // at 38 : <select_goil_5F_syntax_2>
62, // at 39 : <select_goil_5F_syntax_3>
69, // at 40 : <select_goil_5F_syntax_4>
77, // at 41 : <select_goil_5F_syntax_5>
82, // at 42 : <select_goil_5F_syntax_6>
90, // at 43 : <select_goil_5F_syntax_7>
95, // at 44 : <select_goil_5F_syntax_8>
111, // at 45 : <select_goil_5F_syntax_9>
117, // at 46 : <select_goil_5F_syntax_10>
122, // at 47 : <select_goil_5F_syntax_11>
128, // at 48 : <select_goil_5F_syntax_12>
133, // at 49 : <select_goil_5F_syntax_13>
138, // at 50 : <select_goil_5F_syntax_14>
143, // at 51 : <select_goil_5F_syntax_15>
148, // at 52 : <select_goil_5F_syntax_16>
153, // at 53 : <select_goil_5F_syntax_17>
158, // at 54 : <select_implementation_5F_parser_0>
166, // at 55 : <select_implementation_5F_parser_1>
171, // at 56 : <select_implementation_5F_parser_2>
176, // at 57 : <select_implementation_5F_parser_3>
181, // at 58 : <select_implementation_5F_parser_4>
186, // at 59 : <select_implementation_5F_parser_5>
191, // at 60 : <select_implementation_5F_parser_6>
209, // at 61 : <select_implementation_5F_parser_7>
232, // at 62 : <select_implementation_5F_parser_8>
237, // at 63 : <select_implementation_5F_parser_9>
245, // at 64 : <select_implementation_5F_parser_10>
252, // at 65 : <select_implementation_5F_parser_11>
257, // at 66 : <select_implementation_5F_parser_12>
262, // at 67 : <select_implementation_5F_parser_13>
267, // at 68 : <select_implementation_5F_parser_14>
275, // at 69 : <select_implementation_5F_parser_15>
281, // at 70 : <select_implementation_5F_parser_16>
286, // at 71 : <select_implementation_5F_parser_17>
294, // at 72 : <select_implementation_5F_parser_18>
301, // at 73 : <select_implementation_5F_parser_19>
309, // at 74 : <select_implementation_5F_parser_20>
319, // at 75 : <select_implementation_5F_parser_21>
327, // at 76 : <select_implementation_5F_parser_22>
334, // at 77 : <select_implementation_5F_parser_23>
340, // at 78 : <select_implementation_5F_parser_24>
345, // at 79 : <select_implementation_5F_parser_25>
350, // at 80 : <select_implementation_5F_parser_26>
357, // at 81 : <select_implementation_5F_parser_27>
363, // at 82 : <select_implementation_5F_parser_28>
369, // at 83 : <select_implementation_5F_parser_29>
374, // at 84 : <select_implementation_5F_parser_30>
381, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_file_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_file_level_include, gProductionNames_goil_file_level_include, gProductionIndexes_goil_file_level_include,
                                    gFirstProductionIndexes_goil_file_level_include, gDecision_goil_file_level_include, gDecisionIndexes_goil_file_level_include, 448) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_implementation &  parameter_1,
                                GALGAS_applicationDefinition &  parameter_2,
                                GALGAS_string &  parameter_3,
                                const GALGAS_bool  parameter_4
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_file_level_include, gProductionNames_goil_file_level_include, gProductionIndexes_goil_file_level_include,
                                                      gFirstProductionIndexes_goil_file_level_include, gDecision_goil_file_level_include, gDecisionIndexes_goil_file_level_include, 448) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_file_5F_level_5F_include grammar ;
        grammar.nt_file_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_implementation &  parameter_1,
                                GALGAS_applicationDefinition &  parameter_2,
                                GALGAS_string &  parameter_3,
                                const GALGAS_bool  parameter_4
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_file_level_include, gProductionNames_goil_file_level_include, gProductionIndexes_goil_file_level_include,
                                                    gFirstProductionIndexes_goil_file_level_include, gDecision_goil_file_level_include, gDecisionIndexes_goil_file_level_include, 448) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_file_5F_level_5F_include grammar ;
      grammar.nt_file_ (parameter_1, parameter_2, parameter_3, parameter_4, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_object_5F_list_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'include_implementation_level' non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_implementation_5F_level_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_type_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'implementation_objects' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_list' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_type' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'struct_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'objref_option' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'string_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'boolean_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'enum_item' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'enum_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'number_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'type_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'with_auto' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'int_or_float' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'set_followup' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'range_content' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'range' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'multiple' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_attribute' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_enum_value' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse(inLexique) ;
}

void cGrammar_goil_5F_file_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_0' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_1' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_2' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_3' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_4' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_5' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_6' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_7' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_8' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_9' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_10' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_11' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_12' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_13' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_14' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_15' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_16' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_17' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_18' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_19' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_20' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_21' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_22' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_23' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_24' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_25' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_26' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_27' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_28' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_29' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_30' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_file_5F_level_5F_include::select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

