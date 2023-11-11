//----------------------------------------------------------------------------------------------------------------------
//
//  Lexique introspection
//
//  This file is part of libpm library
//
//  Copyright (C) 2016, ..., 2016 Pierre Molinaro.
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

#include "galgas2/cLexiqueIntrospection.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/C_Compiler.h"
#include "files/C_FileManager.h"

//----------------------------------------------------------------------------------------------------------------------

static cLexiqueIntrospection * gLexiqueIntrospectionRoot = nullptr ;

//----------------------------------------------------------------------------------------------------------------------

cLexiqueIntrospection::cLexiqueIntrospection (void (*appendKeywordListNames) (TC_UniqueArray <C_String> & ioList),
                                              Type_getKeywordsForIdentifier getKeywordsForIdentifier) :
mNext (gLexiqueIntrospectionRoot),
mAppendKeywordListNames (appendKeywordListNames),
mGetKeywordsForIdentifier (getKeywordsForIdentifier) {
  gLexiqueIntrospectionRoot = this ;
}

//----------------------------------------------------------------------------------------------------------------------

void cLexiqueIntrospection::getKeywordListNames (TC_UniqueArray <C_String> & outList) {
  outList.setCountToZero () ;
  cLexiqueIntrospection * p = gLexiqueIntrospectionRoot ;
  while (nullptr != p) {
    p->mAppendKeywordListNames (outList) ;
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cLexiqueIntrospection::getKeywordListForIdentifier (const C_String & inIdentifier,
                                                         bool & outFound,
                                                         TC_UniqueArray <C_String> & outList) {
  outFound = false ;
  outList.setCountToZero () ;
  cLexiqueIntrospection * p = gLexiqueIntrospectionRoot ;
  while ((nullptr != p) && !outFound) {
    p->mGetKeywordsForIdentifier (inIdentifier, outFound, outList) ;
    p = p->mNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cLexiqueIntrospection::handleGetKeywordListOption (C_Compiler * inCompiler) {
  const C_String option = gOption_galgas_5F_builtin_5F_options_outputKeywordList.readProperty_value () ;
  if (option != "") {
    const C_String optionFormat = "lexique_name:list_name:columns:prefix:postfix:path" ;
    co << "Option \"--" << gOption_galgas_5F_builtin_5F_options_outputKeywordList.mCommandString
       << "=" << option << "\":\n" ;
    TC_UniqueArray <C_String> components ;
    option.componentsSeparatedByString (":", components) ;
    if (components.count () != 6) {
      C_String message = "invalid option ; should be \"--" ;
      message << gOption_galgas_5F_builtin_5F_options_outputKeywordList.mCommandString << "=" << optionFormat + "\"" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_HERE) ;
    }else if (!components (2 COMMA_HERE).isUnsignedInteger ()) {
      C_String message = "invalid option ; in \"--" ;
      message << gOption_galgas_5F_builtin_5F_options_outputKeywordList.mCommandString << "=" << optionFormat + "\", "
              << "\"columns\" should be an decimal unsigned number" ;
      inCompiler->onTheFlyRunTimeError (message COMMA_HERE) ;
    }else{
      const uint32_t columns = components (2 COMMA_HERE).unsignedIntegerValue () ;
      const C_String prefix = components (3 COMMA_HERE) ;
      const C_String postfix = components (4 COMMA_HERE) ;
      const C_String identifier = components (0 COMMA_HERE) + ":" + components (1 COMMA_HERE) ;
      TC_UniqueArray <C_String> nameList ;
      bool found = false ;
      getKeywordListForIdentifier (identifier, found, nameList) ;
      if (!found) {
        C_String message = "invalid option ; in \"--" ;
        message << gOption_galgas_5F_builtin_5F_options_outputKeywordList.mCommandString << "=" << optionFormat + "\", "
                << "available values for \"lexique_name:list_name\" are:" ;
        TC_UniqueArray <C_String> keywordListNames ; getKeywordListNames (keywordListNames) ;
        for (int32_t i=0 ; i<keywordListNames.count () ; i++) {
          message << "  - " << keywordListNames (i COMMA_HERE) << "\n" ;
        }
        inCompiler->onTheFlyRunTimeError (message COMMA_HERE) ;
      }else{
        uint32_t idx = 0 ;
        C_String s ;
        for (int32_t i=0 ; i<nameList.count() ; i++) {
          s << "  " << prefix << nameList (i COMMA_HERE) << postfix << "  " ;
          idx ++ ;
          if (idx < columns) {
            s << "&" ;
          }else{
            s << " \\\\\n" ;
            idx = 0 ;
          }
        }
        if (idx > 0) {
          for (uint32_t i = idx+1 ; i<columns ; i++) {
            s << "  &  " ;
          }
          s << "  \\\\\n" ;
        }
        const C_String path = components (5 COMMA_HERE) ;
        C_FileManager::writeStringToFile (s, path) ;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

