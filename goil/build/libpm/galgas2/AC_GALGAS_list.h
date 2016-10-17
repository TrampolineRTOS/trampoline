//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  AC_GALGAS_list : Base class for GALGAS list                                                                        *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2013 Pierre Molinaro.                                                                     *
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

#ifndef AC_GALGAS_LIST_CLASS_DEFINED
#define AC_GALGAS_LIST_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/AC_GALGAS_root.h"
#include "galgas2/typeComparisonResult.h"
#include "galgas2/cCollectionElement.h"

//---------------------------------------------------------------------------------------------------------------------*

class AC_GALGAS_list : public AC_GALGAS_root {
//--- Private properties
  private : capCollectionElementArray mSharedArray ;
  private : bool mIsValid ;

//--- Default constructor
  protected : AC_GALGAS_list (void) ;

//--- Constructor used by list map
  protected : AC_GALGAS_list (const capCollectionElementArray & inSharedArray) ;

//--- Virtual destructor
  public : virtual ~ AC_GALGAS_list (void) ;

//--- count
  public : VIRTUAL_IN_DEBUG uint32_t count (void) const ;

//--- isValid
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mIsValid ; }

//--- drop
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--- Enumeration
  protected : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & outEnumerationArray) const ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const AC_GALGAS_list & inOperand) const ;

//--- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_uint getter_length (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_range getter_range (LOCATION_ARGS) const ;

//--- Description
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;

//--- introspection
  public : virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const = 0 ;

//--- Internal methods for handling list
  protected : VIRTUAL_IN_DEBUG void appendObject (const capCollectionElement & inElementToAdd) ;

  protected : VIRTUAL_IN_DEBUG void insertObjectAtIndex (const capCollectionElement & inElementToAdd,
                                                      const uint32_t inInsertionIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG void removeObjectAtIndex (capCollectionElement & outAttributes,
                                                         const uint32_t inRemoveIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

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
                                                      const GALGAS_range & inRange,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG void subListFromIndex (AC_GALGAS_list & outList,
                                                      const GALGAS_uint & inIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG void subListToIndex (AC_GALGAS_list & outList,
                                                    const GALGAS_uint & inIndex,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG capCollectionElement readObjectAtIndex (const GALGAS_uint & inIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;


  protected : VIRTUAL_IN_DEBUG
  cCollectionElement * uniquelyReferencedPointerAtIndex (const GALGAS_uint & inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  cListMapElement                                                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cListMapElement : public cCollectionElement {
//--- Attributes
  public : C_String mKey ;
  public : capCollectionElementArray mSharedListMapList ;

//--- Default constructor
  public : cListMapElement (const C_String & inKey,
                            const capCollectionElementArray & inSharedList
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
  public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  AC_GALGAS_listmap                                                                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class AC_GALGAS_listmap : public AC_GALGAS_root {
//--- Constructor
  protected : AC_GALGAS_listmap (void) ;

//--- Virtual destructor
  public : virtual ~ AC_GALGAS_listmap (void) ;

//--- Handle copy
  public : AC_GALGAS_listmap (const AC_GALGAS_listmap & inSource) ;
  public : AC_GALGAS_listmap & operator = (const AC_GALGAS_listmap & inSource) ;

//--- count
  public : VIRTUAL_IN_DEBUG uint32_t count (void) const ;

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
                                     const int32_t inIndentation) const ;

//--- Internal methods for enumeration
  protected : virtual void populateEnumerationArray (capCollectionElementArray & inEnumerationArray) const ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const AC_GALGAS_listmap & inOperand) const ;

//--------------------------------- Insulate
  private : VIRTUAL_IN_DEBUG void insulateListMap (LOCATION_ARGS) ;

//--------------------------------- Support for 'listForKey' reader
  protected : capCollectionElementArray listForKey (const GALGAS_string & inKey) const ;

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_uint getter_count (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringset getter_allKeys (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringlist getter_keyList (LOCATION_ARGS) const ;

//--- Attribute
  private : class cSharedListMapRoot * mSharedListMap ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
