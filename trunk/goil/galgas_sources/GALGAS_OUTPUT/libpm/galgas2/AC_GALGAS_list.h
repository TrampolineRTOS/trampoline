//---------------------------------------------------------------------------*
//                                                                           *
//  AC_GALGAS_list : Base class for GALGAS list                              *
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

#ifndef AC_GALGAS_LIST_CLASS_DEFINED
#define AC_GALGAS_LIST_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "AC_GALGAS_root.h"
#include "typeComparisonResult.h"
#include "cCollectionElement.h"

//---------------------------------------------------------------------------*

class GALGAS_uint ;
class GALGAS_string ;
class GALGAS_object ;
class C_Compiler ;
class capCollectionElementArray ;
class C_galgas_type_descriptor ;
class capCollectionElement ;
class cCollectionElement ;
class cSharedList ;

//---------------------------------------------------------------------------*
//                                                                           *
//  A C _ G A L G A S _ l i s t                                              *
//                                                                           *
//---------------------------------------------------------------------------*

class AC_GALGAS_list : public AC_GALGAS_root {
//--- Private Data member
  private : cSharedList * mSharedList ;

//--- Default constructor
  public : AC_GALGAS_list (void) ;
  
//--- Constructor used by list map
  public : AC_GALGAS_list (cSharedList * inSharedListPtr) ;

//--- Virtual destructor
  public : virtual ~ AC_GALGAS_list (void) ;

//--- count
  public : VIRTUAL_IN_DEBUG PMUInt32 count (void) const ;

//--- isValid
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mSharedList != NULL ; }

//--- drop
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--- Handle copy
  public : AC_GALGAS_list (const AC_GALGAS_list & inSource) ;
  public : AC_GALGAS_list & operator = (const AC_GALGAS_list & inSource) ;

//--- Create a new list
  protected : VIRTUAL_IN_DEBUG void createNewEmptyList (LOCATION_ARGS) ;

//--- Enumeration
  protected : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & outEnumerationArray,
                                                              const typeEnumerationOrder inEnumerationOrder) const ;

//--------------------------------- Comparison
  public : VIRTUAL_IN_DEBUG typeComparisonResult objectCompare (const AC_GALGAS_list & inOperand) const ;

//--- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_length (LOCATION_ARGS) const ;

//--- Description
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const PMSInt32 inIndentation) const ;

//--- introspection
  public : virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const = 0 ;

//--- Internal methods for handling list
  protected : VIRTUAL_IN_DEBUG void addObject (const capCollectionElement & inElementToAdd) ;
  
  private : VIRTUAL_IN_DEBUG void insulateList (LOCATION_ARGS) ;
  
  protected : VIRTUAL_IN_DEBUG void prependAttributeArray (const capCollectionElement & inElementToPrepend) ;

  protected : VIRTUAL_IN_DEBUG void removeFirstObject (capCollectionElement & outAttributes,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG void removeLastObject (capCollectionElement & outAttributes,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG void readFirst (capCollectionElement & outAttributes,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG void readLast (capCollectionElement & outAttributes,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG void appendList (const AC_GALGAS_list & inList) ;

  protected : VIRTUAL_IN_DEBUG void subListWithRange (AC_GALGAS_list & outList,
                                                      const GALGAS_uint & inIndex,
                                                      const GALGAS_uint & inLength,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG void subListFromIndex (AC_GALGAS_list & outList,
                                                      const GALGAS_uint & inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG capCollectionElement readObjectAtIndex (const GALGAS_uint & inIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;


  protected : VIRTUAL_IN_DEBUG cCollectionElement * objectPointerAtIndex (const GALGAS_uint & inIndex,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

  public : static void makeNewSharedList (cSharedList * & outSharedList COMMA_LOCATION_ARGS) ;

  public : static void insertInSharedList (cSharedList * inSharedList,
                                           const capCollectionElement & inAttributes) ;

  public : static void detachSharedList (cSharedList * & ioSharedList) ;
} ;

//---------------------------------------------------------------------------*

class cListMapElement : public cCollectionElement {
//--- Attributes
  public : C_String mKey ;
  public : cSharedList * mSharedListMapList ;

//--- Default constructor
  public : cListMapElement (const C_String & inKey,
                            cSharedList * inSharedList
                            COMMA_LOCATION_ARGS) ;

//--- Destructor
  public : virtual ~ cListMapElement (void) ;

//--- No copy
  private : cListMapElement (const cListMapElement &) ;
  private : cListMapElement & operator = (const cListMapElement &) ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cCollectionElement * copy (void) ;

//--- Description
  public : virtual void description (C_String & ioString, const PMSInt32 inIndentation) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//  A C _ G A L G A S _ l i s t m a p                                        *
//                                                                           *
//---------------------------------------------------------------------------*

class cSharedListMapRoot ;
class GALGAS_stringset ;
class GALGAS_stringlist ;

//---------------------------------------------------------------------------*

class AC_GALGAS_listmap : public AC_GALGAS_root {
//--- Constructor
  protected : AC_GALGAS_listmap (void) ;

//--- Virtual destructor
  public : virtual ~ AC_GALGAS_listmap (void) ;

//--- Handle copy
  public : AC_GALGAS_listmap (const AC_GALGAS_listmap & inSource) ;
  public : AC_GALGAS_listmap & operator = (const AC_GALGAS_listmap & inSource) ;

//--- count
  public : VIRTUAL_IN_DEBUG PMUInt32 count (void) const ;

//--- isValid
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mSharedListMap != NULL ; }

//--- drop
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--- Create a new empty list map
  protected : VIRTUAL_IN_DEBUG void makeNewEmptyListMap (LOCATION_ARGS) ;

//--- Adding a new object
  protected : void addObjectInListMap (const GALGAS_string & inKey,
                                       capCollectionElement & inAttributeArray) ;
//--- introspection
  public : virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const = 0 ;

//--------------------------------- Implementation of reader 'description'
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

//--- Internal methods for enumeration
  protected : virtual void populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                     const typeEnumerationOrder inEnumerationOrder) const ;

//--------------------------------- Comparison
  public : VIRTUAL_IN_DEBUG typeComparisonResult objectCompare (const AC_GALGAS_listmap & inOperand) const ;

//--------------------------------- Insulate
  private : VIRTUAL_IN_DEBUG void insulateListMap (LOCATION_ARGS) ;

//--------------------------------- Support for 'listForKey' reader
  protected : cSharedList * listForKey (const GALGAS_string & inKey) const ;

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_count (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_stringset reader_allKeys (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_stringlist reader_keyList (LOCATION_ARGS) const ;

//--- Attribute
  private : cSharedListMapRoot * mSharedListMap ;
} ;

//---------------------------------------------------------------------------*

#endif
