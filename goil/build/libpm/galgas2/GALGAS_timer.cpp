//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  GALGAS_timer                                                                                                       *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2015, ..., 2015 Pierre Molinaro.                                                                     *
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

#include "galgas2/predefined-types.h"
#include "galgas2/C_Compiler.h"

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_timer::GALGAS_timer (void) :
AC_GALGAS_root (),
mIsValid (false),
mTimer () {
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_timer::description (C_String & ioString,
                                    const int32_t /* inIndentation */) const {
  ioString << "<@timer: " ;
  if (!mIsValid) {
    ioString << "not built" ;
  }else{
    ioString << mTimer.timeString () ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_timer GALGAS_timer::constructor_start (UNUSED_LOCATION_ARGS) {
  GALGAS_timer result ;
  result.mIsValid = true ;
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_timer::modifier_stop (UNUSED_LOCATION_ARGS) {
  if (isValid ()) {
    mTimer.stopTimer () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_timer::modifier_resume (UNUSED_LOCATION_ARGS) {
  if (isValid ()) {
    mTimer = C_Timer () ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint GALGAS_timer::getter_msFromStart (UNUSED_LOCATION_ARGS) const {
  GALGAS_uint result ;
  if (isValid ()) {
    result = GALGAS_uint (mTimer.msFromStart ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_timer::getter_string (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (isValid ()) {
    result = GALGAS_string (mTimer.timeString ()) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
