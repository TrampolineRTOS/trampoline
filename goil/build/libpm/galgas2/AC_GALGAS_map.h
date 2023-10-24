//----------------------------------------------------------------------------------------------------------------------
//
//  AC_GALGAS_map : Base class for GALGAS map                                                    
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2008, ..., 2021 Pierre Molinaro.
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

#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/AC_GALGAS_root.h"
#include "galgas2/typeComparisonResult.h"

//----------------------------------------------------------------------------------------------------------------------

class cSharedMapRoot ;
class cMapElement ;
class GALGAS_lstring ;
class GALGAS_string ;
class GALGAS_stringset ;
class GALGAS_lstringlist ;
class GALGAS_stringlist ;
class GALGAS_bool ;
class GALGAS_uint ;
class GALGAS_location ;
class C_LocationInSource ;
class AC_GALGAS_map ;
class capCollectionElement ;
class cCollectionElement ;
class C_Compiler ;
class C_galgas_type_descriptor ;
class capCollectionElementArray ;
class cMapNode ;

//----------------------------------------------------------------------------------------------------------------------
//
//     M A P                                                                                     
//
//----------------------------------------------------------------------------------------------------------------------

class AC_GALGAS_map : public AC_GALGAS_root {
//--------------------------------- Constructor
  protected: AC_GALGAS_map (const bool inActivateReplacementSuggestions) ;

//--------------------------------- Virtual destructor
  public: virtual ~ AC_GALGAS_map (void) ;

//--------------------------------- Handle copy
  public: AC_GALGAS_map (const AC_GALGAS_map & inSource) ;
  public: AC_GALGAS_map & operator = (const AC_GALGAS_map & inSource) ;

//--- count
  public: VIRTUAL_IN_DEBUG uint32_t count (void) const ;

//--- isValid
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return mSharedMap != NULL ; }

//--- drop
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--- Create a new map
  protected: VIRTUAL_IN_DEBUG void makeNewEmptyMap (LOCATION_ARGS) ;

  protected: VIRTUAL_IN_DEBUG void makeNewEmptyMapWithMapToOverride (const AC_GALGAS_map & inMapToOverride
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Insert or Replace
  protected: VIRTUAL_IN_DEBUG void performInsertOrReplace (const capCollectionElement & inAttributes) ;

//--------------------------------- Insert
  private: VIRTUAL_IN_DEBUG void insulate (LOCATION_ARGS) ;
  
  private: VIRTUAL_IN_DEBUG void insulateCurrentAndOverridenMaps (LOCATION_ARGS) ;
  
  protected: VIRTUAL_IN_DEBUG void performInsert (const capCollectionElement & inAttributes,
                                                   C_Compiler * inCompiler,
                                                   const char * inInsertErrorMessage,
                                                   const char * inShadowErrorMessage
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Search for 'with' read only instruction
  public: VIRTUAL_IN_DEBUG const cCollectionElement * readAccessForWithInstruction (const GALGAS_string & inKey) const ;

  public: VIRTUAL_IN_DEBUG cCollectionElement * readWriteAccessForWithInstructionWithErrorMessage (C_Compiler * inCompiler,
                                                                                                    const GALGAS_lstring & inKey,
                                                                                                    const char * inSearchErrorMessage
                                                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Search
  protected: VIRTUAL_IN_DEBUG cMapNode * searchEntryInMap (const C_String & inKey) const ;

  protected: VIRTUAL_IN_DEBUG const cCollectionElement * performSearch (const GALGAS_lstring & inKey,
                                                                         C_Compiler * inCompiler,
                                                                         const char * inSearchErrorMessage
                                                                         COMMA_LOCATION_ARGS) const ;

  protected: VIRTUAL_IN_DEBUG const cMapElement * searchForReadingAttribute (const GALGAS_string & inKey,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  protected: VIRTUAL_IN_DEBUG const cMapElement * searchForKey (const GALGAS_string & inKey) const ;

  protected: VIRTUAL_IN_DEBUG cMapElement * searchForReadWriteAttribute (const GALGAS_string & inKey,
                                                                          const bool inErrorOnUnknownKey,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

  protected: VIRTUAL_IN_DEBUG cMapElement * searchForReadWriteAttribute (const GALGAS_lstring & inKey,
                                                                          C_Compiler * inCompiler,
                                                                          const char * inSearchErrorMessage
                                                                          COMMA_LOCATION_ARGS) ;

  protected: VIRTUAL_IN_DEBUG void getOverridenMap (AC_GALGAS_map & outMap,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- Remove
  protected: VIRTUAL_IN_DEBUG void performRemove (GALGAS_lstring & inKey,
                                                   capCollectionElement & outResult,
                                                   C_Compiler * inCompiler,
                                                   const char * inRemoveErrorMessage
                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Readers
  public: VIRTUAL_IN_DEBUG GALGAS_uint getter_levels (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_hasKey (const GALGAS_string & inKey
                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_hasKeyAtLevel (const GALGAS_string & inKey,
                                                             const GALGAS_uint & inLevel
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_location getter_locationForKey (const GALGAS_string & inKey,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_stringset getter_keySet (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_lstringlist getter_keyList (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG GALGAS_uint getter_count (LOCATION_ARGS) const ;

//--------------------------------- Introspection
  public: virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const override = 0 ;

//--------------------------------- Implementation of reader 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString, const int32_t inIndentation) const override ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const AC_GALGAS_map & inOperand) const ;

//--------------------------------- Internal methods for enumeration
  protected: VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & inEnumerationArray) const ;

//--------------------------------- Properties
  private: cSharedMapRoot * mSharedMap ;
  private: bool mActivateReplacementSuggestions ;
} ;

//----------------------------------------------------------------------------------------------------------------------
