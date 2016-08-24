//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  AC_GALGAS_uniqueMap : Base class for GALGAS map                                                                    *
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2008, ..., 2014 Pierre Molinaro.                                                                     *
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

#ifndef UNIQUE_MAP_BASE_CLASS_DEFINED
#define UNIQUE_MAP_BASE_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/AC_GALGAS_root.h"
#include "galgas2/typeComparisonResult.h"
#include "collections/TC_UniqueArray.h"

//---------------------------------------------------------------------------------------------------------------------*

class cSharedUniqueMapRoot ;
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
class AC_GALGAS_uniqueMap ;
class capCollectionElement ;
class cCollectionElement ;
class C_Compiler ;
class C_galgas_type_descriptor ;
class capCollectionElementArray ;
class cUniqueMapNode ;
class cSharedProxy ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    Data structures for map automaton                                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef enum {
  kMapAutomatonNoIssue,
  kMapAutomatonIssueWarning,
  kMapAutomatonIssueError
} mapAutomatonIssueEnum ;

//---------------------------------------------------------------------------------------------------------------------*

typedef struct {
  const mapAutomatonIssueEnum mIssue ;
  const char * mIssueMessage ;
} cMapAutomatonFinalIssue ;

//---------------------------------------------------------------------------------------------------------------------*

typedef struct {
  const uint32_t mTargetStateIndex ;
  const mapAutomatonIssueEnum mIssue ;
  const char * mIssueMessage ;
} cMapAutomatonTransition ;

//---------------------------------------------------------------------------------------------------------------------*

typedef struct {
  const uint32_t mFirstStateIndex ;
  const uint32_t mLastStateIndex ;
  const uint32_t mResultingStateIndex ;
  const mapAutomatonIssueEnum mIssue ;
  const char * mIssueMessage ;
}cBranchOverrideTransformationDescriptor ;

//---------------------------------------------------------------------------------------------------------------------*

typedef struct {
  const uint32_t mFirstCandidateStateIndex ;
  const uint32_t mSecondCandidateStateIndex ;
  const uint32_t mResultingStateIndex ;
  const mapAutomatonIssueEnum mIssue ;
  const char * mIssueMessage ;
}cBranchOverrideCompatibilityDescriptor ;

//---------------------------------------------------------------------------------------------------------------------*

typedef struct {
  uint32_t mInitialStateIndex ;
  uint32_t mResultingStateIndex ;
}cOverrideStateDescriptor ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     M A P    P R O X Y                                                                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class AC_GALGAS_uniqueMapProxy : public AC_GALGAS_root {
  private : typedef enum {kNotValid, kIsNull, kIsRegular} enumMapProxyState ;

//--------------------------------- Attributes
  private : enumMapProxyState mState ;
  private : cSharedProxy * mSharedProxy ; // refers to map node if kIsRegular
  
//--------------------------------- Constructor
  protected : AC_GALGAS_uniqueMapProxy (void) ;
  
//--------------------------------- Destructor
  protected : virtual ~ AC_GALGAS_uniqueMapProxy (void) ;
  
//--------------------------------- isValid
  public : virtual bool isValid (void) const ;
  
//--------------------------------- drop
  public : virtual void drop (void) ;
  
//--------------------------------- Handle copy
  protected : AC_GALGAS_uniqueMapProxy (const AC_GALGAS_uniqueMapProxy & inSource) ;
  protected : AC_GALGAS_uniqueMapProxy & operator = (const AC_GALGAS_uniqueMapProxy & inSource) ;

//--------------------------------- Attachment management
  private : VIRTUAL_IN_DEBUG void attachProxyToMapNode (cUniqueMapNode * inMapNode) ;

//--------------------------------- Internal make proxy
  protected : VIRTUAL_IN_DEBUG void internalMakeProxy (AC_GALGAS_uniqueMap & ioMap,
                                                       const GALGAS_lstring & inKey
                                                       COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG void internalMakeProxyFromString (AC_GALGAS_uniqueMap & ioMap,
                                                                 const GALGAS_string & inKey
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Internal search key
  protected : VIRTUAL_IN_DEBUG void internalMakeRegularProxyBySearchingKey (const AC_GALGAS_uniqueMap & inMap,
                                                                            const GALGAS_lstring & inKey,
                                                                            const char * inSearchErrorMessage,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Make null proxy
  protected : VIRTUAL_IN_DEBUG void makeNullProxy (LOCATION_ARGS) ;

//--------------------------------- Reader invocation declaration
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_isRegular (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_isNull (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_isSolved (C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_string getter_identifierRepresentation (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_lkey (C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_string getter_key (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- Get attribute list
  protected : const cMapElement * getAttributeListPointer (C_Compiler * inCompiler,
                                                           const char * inReaderName
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const AC_GALGAS_uniqueMapProxy & inOperand) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//     M A P                                                                                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class AC_GALGAS_uniqueMap : public AC_GALGAS_root {
//--------------------------------- Constructor
  protected : AC_GALGAS_uniqueMap (const mapAutomatonIssueEnum inShadowBehaviour,
                                   const C_String & inShadowMessage) ;

//--------------------------------- Virtual destructor
  public : virtual ~ AC_GALGAS_uniqueMap (void) ;

//--------------------------------- Handle copy
  public : AC_GALGAS_uniqueMap (const AC_GALGAS_uniqueMap & inSource) ;
  public : AC_GALGAS_uniqueMap & operator = (const AC_GALGAS_uniqueMap & inSource) ;

//--- count
  public : VIRTUAL_IN_DEBUG uint32_t count (void) const ;

//--- isValid
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mSharedMap != NULL ; }

//--- drop
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--- Create a new map
  protected : VIRTUAL_IN_DEBUG void makeNewEmptyMap (LOCATION_ARGS) ;

//--------------------------------- 'enterEdge' modifier declaration
  public : VIRTUAL_IN_DEBUG void setter_enterEdge (const GALGAS_lstring & inSource,
                                                     const GALGAS_lstring & inTarget
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- 'topologicalSort' method declaration
  public : VIRTUAL_IN_DEBUG void method_topologicalSort (GALGAS_lstringlist & outSortedKeys,
                                                         GALGAS_lstringlist & outUnsortedKeys,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Insert
  protected : VIRTUAL_IN_DEBUG void insertInSharedMap (capCollectionElement & inAttributes,
                                                       C_Compiler * inCompiler,
                                                       const uint32_t inInitialState,
                                                       const char * inInitialStateName,
                                                       const char * inInsertErrorMessage
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Search for 'with' read only instruction
  public : VIRTUAL_IN_DEBUG const cCollectionElement * readAccessForWithInstruction (const GALGAS_string & inKey) const ;

//--------------------------------- Search
  protected : VIRTUAL_IN_DEBUG cUniqueMapNode * searchEntryInMap (const C_String & inKey) const ;

  public : VIRTUAL_IN_DEBUG void findNearestKey (const C_String & inKey,
                                                 TC_UniqueArray <C_String> & ioNearestKeyArray) const ;

  protected : VIRTUAL_IN_DEBUG const cCollectionElement * performSearch (const GALGAS_lstring & inKey,
                                                                         C_Compiler * inCompiler,
                                                                         const char * inSearchErrorMessage
                                                                         COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG const cCollectionElement * performSearch (const GALGAS_lstring & inKey,
                                                                         C_Compiler * inCompiler,
                                                                         const uint32_t inActionIndex,
                                                                         const cMapAutomatonTransition inTransitionArray [],
                                                                         const uint32_t inAutomatonActionCount,
                                                                         #ifndef DO_NOT_GENERATE_CHECKINGS
                                                                           const uint32_t inAutomatonStateCount,
                                                                         #endif
                                                                         const char * inSearchErrorMessage
                                                                         COMMA_LOCATION_ARGS) ;

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

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_bool getter_hasKey (const GALGAS_string & inKey
                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_string getter_edgeGraphvizRepresentation (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_location getter_locationForKey (const GALGAS_string & inKey,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_stringset getter_allKeys (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_lstringlist getter_allKeyList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_uint getter_count (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_uint getter_unsolvedProxyCount (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_lstringlist getter_unsolvedProxyList (LOCATION_ARGS) const ;

//--------------------------------- Introspection
  public : virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const = 0 ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const AC_GALGAS_uniqueMap & inOperand) const ;

//--------------------------------- Internal methods for enumeration
  protected : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                              const typeEnumerationOrder inEnumerationOrder) const ;

//--------------------------------- Internal methods for inserting proxy
  protected : VIRTUAL_IN_DEBUG cUniqueMapNode * performInsertProxy (const C_String & inKey,
                                                                    const GALGAS_location & inLocation
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Check Map Automatons state
  public : VIRTUAL_IN_DEBUG void checkAutomatonStates (const GALGAS_location & inErrorLocation,
                                                       const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- Open override for block
  public : VIRTUAL_IN_DEBUG void openOverride (const cBranchOverrideTransformationDescriptor inBranchBehaviourArray [],
                                               const uint32_t inBranchBehaviourSize,
                                               const cBranchOverrideCompatibilityDescriptor inBranchCombinationArray [],
                                               const uint32_t inBranchCombinationSize,
                                               const char * inBlockName,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Close override for block
  public : VIRTUAL_IN_DEBUG void setter_closeOverride (const GALGAS_location & inErrorLocation,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Branch Handling
  public : VIRTUAL_IN_DEBUG void setter_openBranch (C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void closeBranch (const GALGAS_location & inErrorLocation,
                                              const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                              #ifndef DO_NOT_GENERATE_CHECKINGS
                                                const uint32_t inAutomatonStateCount,
                                              #endif
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Attributes
  private : cSharedUniqueMapRoot * mSharedMap ;
  
//--------------------------------- Handle shadow
  protected : mapAutomatonIssueEnum mShadowBehaviour ;
  protected : C_String mShadowMessage ;

//--------------------------------- Friend
  friend class AC_GALGAS_uniqueMapProxy ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
