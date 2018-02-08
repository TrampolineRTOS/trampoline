//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2003, ..., 2014 Pierre Molinaro.                                                                     *
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

#ifdef __OBJC__
  #import <Cocoa/Cocoa.h>
#endif

//---------------------------------------------------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------------------------------------------------*

#if __has_feature(objc_arc)
  #define macroSuperFinalize
#else
  #define macroSuperFinalize [super finalize]
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if __has_feature(objc_arc)
  #define FINALIZE_OR_DEALLOC dealloc
#else
  #define FINALIZE_OR_DEALLOC finalize
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if __has_feature(objc_arc)
  #define ARC_BRIDGE __bridge
#else
  #define ARC_BRIDGE
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if __clang_major__ == 1
  #define PROPERTY_COMMA_ATOMIC
#else
  #define PROPERTY_COMMA_ATOMIC , atomic
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if _clang_major__ == 1
  #define PROPERTY_ATOMIC
#else
  #define PROPERTY_ATOMIC (atomic)
#endif

//---------------------------------------------------------------------------------------------------------------------*
