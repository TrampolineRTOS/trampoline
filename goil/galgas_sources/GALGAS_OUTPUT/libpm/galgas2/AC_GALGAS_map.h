//---------------------------------------------------------------------------*
//                                                                           *
//  AC_GALGAS_map : Base class for GALGAS map                                *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2008, ..., 2010 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#ifndef MAP_BASE_CLASS_DEFINED
#define MAP_BASE_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "AC_GALGAS_root.h"
#include "typeComparisonResult.h"

//---------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------*
//                                                                           *
//     M A P                                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

class AC_GALGAS_map : public AC_GALGAS_root {
//--------------------------------- Constructor
  protected : AC_GALGAS_map (void) ;

//--------------------------------- Virtual destructor
  public : virtual ~ AC_GALGAS_map (void) ;

//--------------------------------- Handle copy
  public : AC_GALGAS_map (const AC_GALGAS_map & inSource) ;
  public : AC_GALGAS_map & operator = (const AC_GALGAS_map & inSource) ;

//--- count
  public : VIRTUAL_IN_DEBUG PMUInt32 count (void) const ;

//--- isValid
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mSharedMap != NULL ; }

//--- drop
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--- Create a new map
  protected : VIRTUAL_IN_DEBUG void makeNewEmptyMap (LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG void makeNewEmptyMapWithMapToOverride (const AC_GALGAS_map & inMapToOverride
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Insert or Replace
  protected : VIRTUAL_IN_DEBUG void performInsertOrReplace (const capCollectionElement & inAttributes) ;

//--------------------------------- Insert
  private : VIRTUAL_IN_DEBUG void insulate (LOCATION_ARGS) ;
  
  protected : VIRTUAL_IN_DEBUG void performInsert (const capCollectionElement & inAttributes,
                                                   C_Compiler * inCompiler,
                                                   const char * inInsertErrorMessage,
                                                   const char * inShadowErrorMessage
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Search for 'with' read only instruction
  public : VIRTUAL_IN_DEBUG const cCollectionElement * readAccessForWithInstruction_hasKey (const GALGAS_string & inKey) const ;

//--------------------------------- Search
  protected : VIRTUAL_IN_DEBUG cMapNode * searchEntryInMap (const C_String & inKey) const ;

  protected : VIRTUAL_IN_DEBUG const cCollectionElement * performSearch (const GALGAS_lstring & inKey,
                                                                         C_Compiler * inCompiler,
                                                                         const char * inSearchErrorMessage
                                                                         COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG const cMapElement * searchForReadingAttribute (const GALGAS_string & inKey,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG cMapElement * searchForReadWriteAttribute (const GALGAS_string & inKey,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG cMapElement * searchForReadWriteAttribute (const GALGAS_lstring & inKey,
                                                                          C_Compiler * inCompiler,
                                                                          const char * inSearchErrorMessage
                                                                          COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG void getOverridenMap (AC_GALGAS_map & outMap) const ;

//--------------------------------- Remove
  protected : VIRTUAL_IN_DEBUG void performRemove (GALGAS_lstring & inKey,
                                                   capCollectionElement & outResult,
                                                   C_Compiler * inCompiler,
                                                   const char * inRemoveErrorMessage
                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_levels (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_hasKey (const GALGAS_string & inKey
                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_hasKeyAtLevel (const GALGAS_string & inKey,
                                                              const GALGAS_uint & inLevel
                                                              COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_location reader_locationForKey (const GALGAS_string & inKey,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_stringset reader_allKeys (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_lstringlist reader_allKeyList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_count (LOCATION_ARGS) const ;

//--------------------------------- Introspection
  public : virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const = 0 ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const PMSInt32 inIndentation) const ;

//--------------------------------- Comparison
  public : VIRTUAL_IN_DEBUG typeComparisonResult objectCompare (const AC_GALGAS_map & inOperand) const ;

//--------------------------------- Internal methods for enumeration
  protected : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                              const typeEnumerationOrder inEnumerationOrder) const ;

//--------------------------------- Attributes
  private : cSharedMapRoot * mSharedMap ;
} ;

//---------------------------------------------------------------------------*

#endif
