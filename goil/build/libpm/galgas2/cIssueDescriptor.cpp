//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  'cIssueDescriptor'                                                                                                 *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2017, ..., 2017 Pierre Molinaro.                                                                     *
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

#include "galgas2/cIssueDescriptor.h"

//---------------------------------------------------------------------------------------------------------------------*

cIssueDescriptor::cIssueDescriptor (void) :
mIsError (false),
mFile (""),
mLine (0),
mStartColumn (0),
mEndColumn (0),
mMessage ("") {
}

//---------------------------------------------------------------------------------------------------------------------*

cIssueDescriptor::cIssueDescriptor (const bool inIsError,
                                    const C_String & inFile,
                                    const int32_t inLine,
                                    const int32_t inStartColumn,
                                    const int32_t inEndColumn,
                                    const C_String & inMessage) :
mIsError (inIsError),
mFile (inFile),
mLine (inLine),
mStartColumn (inStartColumn),
mEndColumn (inEndColumn),
mMessage (inMessage) {
}

//---------------------------------------------------------------------------------------------------------------------*

cIssueDescriptor::cIssueDescriptor (const cIssueDescriptor & inSource) :
mIsError (inSource.mIsError),
mFile (inSource.mFile),
mLine (inSource.mLine),
mStartColumn (inSource.mStartColumn),
mEndColumn (inSource.mEndColumn),
mMessage (inSource.mMessage) {
}

//---------------------------------------------------------------------------------------------------------------------*

cIssueDescriptor & cIssueDescriptor::operator = (const cIssueDescriptor & inSource) {
  if (this != & inSource) {
    mIsError = inSource.mIsError ;
    mFile = inSource.mFile ;
    mLine = inSource.mLine ;
    mStartColumn = inSource.mStartColumn ;
    mEndColumn = inSource.mEndColumn ;
    mMessage = inSource.mMessage ;
  }
  return *this ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cIssueDescriptor::appendToJSONstring (C_String & ioJSONstring, const bool inIsFirstIssue) const {
  C_String s = mMessage.stringByReplacingStringByString("\n", "\\n") ;
  s = s.stringByReplacingStringByString("\"", "\\\"") ;
  ioJSONstring << (inIsFirstIssue ? "" : ",\n")
               << "  { \"ERROR\" : " << (mIsError ? "true" : "false") << ",\n"
               << "    \"SOURCE\" : \"" << mFile << "\",\n"
               << "    \"LINE\"  : " << cStringWithSigned (mLine) << ",\n"
               << "    \"START_COLUMN\"  : " << cStringWithSigned (mStartColumn) << ",\n"
               << "    \"END_COLUMN\"  : " << cStringWithSigned (mEndColumn) << ",\n"
               << "    \"MESSAGE\" : \"" << s << "\"\n"
               << "  }" ;
}

//---------------------------------------------------------------------------------------------------------------------*
