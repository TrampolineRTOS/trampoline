//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//  C_IssueWithFixIt                                                                                                   *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2016, ..., 2016 Pierre Molinaro.                                                                     *
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

#include "galgas2/C_IssueWithFixIt.h"
#include "all-predefined-types.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_FixItDescription::C_FixItDescription (void) :
mKind (kFixItRemove),
mActionString ("") {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_FixItDescription::C_FixItDescription (const EnumFixItKind inKind,
                                        const C_String & inActionString) :
mKind (inKind),
mActionString (inActionString) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_IssueWithFixIt::C_IssueWithFixIt (void) :
mStartLocation (),
mEndLocation (),
mFixItArray () {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_IssueWithFixIt::C_IssueWithFixIt (const C_LocationInSource & inStartLocation,
                                    const C_LocationInSource & inEndLocation,
                                    const TC_Array <C_FixItDescription> & inFixItArray) :
mStartLocation (inStartLocation),
mEndLocation (inEndLocation),
mFixItArray (inFixItArray) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void appendFixItActions (TC_Array <C_FixItDescription> & ioArray,
                         const EnumFixItKind inKind,
                         const GALGAS_stringlist & inList) {
  cEnumerator_stringlist enumerator (inList, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    const C_String s = enumerator.current_mValue (HERE).stringValue () ;
    ioArray.appendObject (C_FixItDescription (inKind, s)) ;
    enumerator.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void appendFixItActions (TC_Array <C_FixItDescription> & ioArray,
                         const EnumFixItKind inKind,
                         const GALGAS_lstringlist & inList) {
  cEnumerator_lstringlist enumerator (inList, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    const C_String s = enumerator.current_mValue (HERE).mProperty_string.stringValue () ;
    ioArray.appendObject (C_FixItDescription (inKind, s)) ;
    enumerator.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void appendFixItActions (TC_Array <C_FixItDescription> & ioArray,
                         const EnumFixItKind inKind,
                         const GALGAS_stringset & inStringSet) {
  cEnumerator_stringset enumerator (inStringSet, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    const C_String s = enumerator.current_key (HERE).stringValue () ;
    ioArray.appendObject (C_FixItDescription (inKind, s)) ;
    enumerator.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void appendFixItActions (TC_Array <C_FixItDescription> & ioArray,
                         const EnumFixItKind inKind,
                         const GALGAS_string & inString) {
  const C_String s = inString.stringValue () ;
  ioArray.appendObject (C_FixItDescription (inKind, s)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
