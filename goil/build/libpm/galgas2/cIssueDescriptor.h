//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  'cIssueDescriptor'                                                                                                 *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2017, ..., 2017 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@ec-nantes.fr                                                                              *
//                                                                                                                     *
//  LS2N, Laboratoire des Sciences du Numérique de Nantes, ECN, École Centrale de Nantes (France)                      *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#pragma once

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "strings/C_String.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//         cIssueDescriptor                                                                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

class cIssueDescriptor {
//--- Default constructor
  public : cIssueDescriptor (void) ;

//--- Constructor
  public : cIssueDescriptor (const bool inIsError,
                             const C_String & inFile,
                             const int32_t inLine,
                             const int32_t inStartColumn,
                             const int32_t inEndColumn,
                             const C_String & inMessage) ;

//--- Copy constructor
  public : cIssueDescriptor (const cIssueDescriptor & inSource) ;

//--- Assignment
  public : cIssueDescriptor & operator = (const cIssueDescriptor & inSource) ;

//--- Append issue to JSON string
  public : void appendToJSONstring (C_String & ioJSONstring, const bool inIsFirstIssue) const ;

//--- Properties
  private : bool mIsError ; // false: warning
  private : C_String mFile ;
  private : int32_t mLine ;
  private : int32_t mStartColumn ;
  private : int32_t mEndColumn ;
  private : C_String mMessage ;
} ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
