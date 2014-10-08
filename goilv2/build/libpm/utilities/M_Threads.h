//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  Collection of macros for using C++11 std::thread.                          *
//                                                                                                                     *
//  This file is part of libpm library                                         *
//                                                                                                                     *
//  Copyright (C) 2012, ..., 2012 Pierre Molinaro.                             *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, École Centrale de Nantes (France)                                     *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

#ifndef THREAD_MACROS_DEFINED
#define THREAD_MACROS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#ifndef LIBPM_MULTI_THREADING
  #error the LIBPM_MULTI_THREADING should be defined
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if LIBPM_MULTI_THREADING_ENABLED == 1
  #include <thread>
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if LIBPM_MULTI_THREADING_ENABLED == 1
  #define macroDeclareStaticMutex(MUTEX_NAME) static std::mutex MUTEX_NAME ;
  #define macroDeclareMutex(MUTEX_NAME)              std::mutex MUTEX_NAME ;
  #define macroDeclareExternMutex(MUTEX_NAME) extern std::mutex MUTEX_NAME ;
#else
  #define macroDeclareStaticMutex(MUTEX_NAME)
  #define macroDeclareMutex(MUTEX_NAME)
  #define macroDeclareExternMutex(MUTEX_NAME)
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if LIBPM_MULTI_THREADING_ENABLED == 1
  #define macroMutexLock(MUTEX_NAME) MUTEX_NAME.lock () ;
#else
  #define macroMutexLock(MUTEX_NAME)
#endif

//---------------------------------------------------------------------------------------------------------------------*

#if LIBPM_MULTI_THREADING_ENABLED == 1
  #define macroMutexUnlock(MUTEX_NAME) MUTEX_NAME.unlock () ;
#else
  #define macroMutexUnlock(MUTEX_NAME)
#endif

//---------------------------------------------------------------------------------------------------------------------*

#endif
