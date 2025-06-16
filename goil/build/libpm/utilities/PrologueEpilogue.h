//--------------------------------------------------------------------------------------------------
//
//  GALGAS prologue / epilogue handling class                                                    
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2009, ..., 2010 Pierre Molinaro.
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
//--------------------------------------------------------------------------------------------------

#pragma once

//--------------------------------------------------------------------------------------------------
//
//                 Prologue / Epilogue Action class                                              
//
//--------------------------------------------------------------------------------------------------

class PrologueEpilogue final {
//--- Constructor
  public: PrologueEpilogue (void (* inPrologueAction) (void),
                            void (* inEpilogueAction) (void)) ;

//--- No copy
  private: PrologueEpilogue (PrologueEpilogue &) = delete ;
  private: PrologueEpilogue & operator = (PrologueEpilogue &) = delete ;

//--- Private properties
  private: const PrologueEpilogue * mNextObject ;
  private: void (* mPrologueAction) (void) ;
  private: void (* mEpilogueAction) (void) ;

//--- Running actions
  private: static void runPrologueActions (void) ;
  private: static void runEpilogueActions (void) ;

//--- Friend routine (runs runPrologueActions, runEpilogueActions)
  friend int main (int argc, const char * argv []) ;
} ;

//--------------------------------------------------------------------------------------------------
