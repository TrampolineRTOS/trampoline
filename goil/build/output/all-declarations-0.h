#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlDataList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlDataList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_gtlDataList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_gtlDataList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_gtlData & in_data
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlDataList extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlDataList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_gtlDataList constructor_listWithValue (const class GALGAS_gtlData & inOperand0
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_gtlDataList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_gtlData & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlDataList add_operation (const GALGAS_gtlDataList & inOperand,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_gtlData constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_gtlData constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_gtlData & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_gtlData & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_gtlData & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setDataAtIndex (class GALGAS_gtlData constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_gtlData & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_gtlData & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlData getter_dataAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlDataList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlDataList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlDataList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_gtlDataList ;
 
} ; // End of GALGAS_gtlDataList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlDataList : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlDataList (const GALGAS_gtlDataList & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_gtlData current_data (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlDataList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlDataList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlData  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlData (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlData * ptr (void) const {
    return (const cPtr_gtlData *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlData (const cPtr_gtlData * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_location readProperty_where (void) const ;

  public: class GALGAS_lstring readProperty_meta (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlData extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlData & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setMeta (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setWhere (class GALGAS_location inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlData class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlData ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlData class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlData : public acPtr_class {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter hasItemAtIndex
  public: virtual class GALGAS_bool getter_hasItemAtIndex (const class GALGAS_gtlInt index,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter hasMapItem
  public: virtual class GALGAS_bool getter_hasMapItem (const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter hasStructField
  public: virtual class GALGAS_bool getter_hasStructField (const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter location
  public: virtual class GALGAS_location getter_location (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter overriddenMap
  public: virtual class GALGAS_gtlStruct getter_overriddenMap (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter overrideMap
  public: virtual class GALGAS_gtlStruct getter_overrideMap (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter resultField
  public: virtual class GALGAS_gtlData getter_resultField (const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) = 0 ;

//--- Extension method itemAtIndex
  public: virtual void method_itemAtIndex (class GALGAS_gtlData & result,
           const class GALGAS_gtlInt index,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method mapItem
  public: virtual void method_mapItem (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method structField
  public: virtual void method_structField (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           class GALGAS_bool & found,
           C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_location mProperty_where ;
  public: GALGAS_lstring mProperty_meta ;

//--- Constructor
  public: cPtr_gtlData (const GALGAS_location & in_where,
                        const GALGAS_lstring & in_meta
                        COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_location getter_where (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setWhere (GALGAS_location inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_meta (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMeta (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlDataList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlDataList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_gtlData mProperty_data ;
  public: inline GALGAS_gtlData readProperty_data (void) const {
    return mProperty_data ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlDataList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setData (const GALGAS_gtlData & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_data = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlDataList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlDataList_2D_element (const GALGAS_gtlData & in_data) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlDataList_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlDataList_2D_element constructor_new (const class GALGAS_gtlData & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlDataList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlDataList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlDataList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@string stringByAppendingPath' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string extensionGetter_stringByAppendingPath (const class GALGAS_string & inObject,
                                                           const class GALGAS_string & constinArgument0,
                                                           class C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVarMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlVarMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_gtlVarMap_get ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_gtlVarMap_getResult ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVarMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_gtlVarMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_gtlVarMap (const GALGAS_gtlVarMap & inSource) ;
  public: GALGAS_gtlVarMap & operator = (const GALGAS_gtlVarMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVarMap extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlVarMap constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_gtlVarMap constructor_mapWithMapToOverride (const class GALGAS_gtlVarMap & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_gtlData & inOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarMap add_operation (const GALGAS_gtlVarMap & inOperand,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_del (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlData & outArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlData constinArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValueForKey (class GALGAS_gtlData constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlData & outArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_getResult (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_gtlData & outArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlVarMap getter_overriddenMap (C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlData getter_valueForKey (const class GALGAS_string & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_gtlData & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_gtlVarMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                      const GALGAS_string & inKey
                                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_gtlVarMap ;
 
} ; // End of GALGAS_gtlVarMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlVarMap : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlVarMap (const GALGAS_gtlVarMap & inEnumeratedObject,
                                 const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_gtlData current_value (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlVarMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVarMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@gtlVarMap' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlVarMap : public cMapElement {
//--- Map attributes
  public: GALGAS_gtlData mProperty_value ;

//--- Constructor
  public: cMapElement_gtlVarMap (const GALGAS_lstring & inKey,
                                 const GALGAS_gtlData & in_value
                                 COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVarMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVarMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_gtlData mProperty_value ;
  public: inline GALGAS_gtlData readProperty_value (void) const {
    return mProperty_value ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlVarMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setValue (const GALGAS_gtlData & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_value = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlVarMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlVarMap_2D_element (const GALGAS_lstring & in_lkey,
                                       const GALGAS_gtlData & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVarMap_2D_element extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlVarMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_gtlData & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlVarMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlVarMap_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVarMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlVarMap replaceOrCreate'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_replaceOrCreate (class GALGAS_gtlVarMap & ioObject,
                                      const class GALGAS_lstring constin_key,
                                      const class GALGAS_gtlData constin_data,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlVarMap replaceOrCreateAtLevel'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_replaceOrCreateAtLevel (class GALGAS_gtlVarMap & ioObject,
                                             const class GALGAS_lstring constin_key,
                                             const class GALGAS_gtlData constin_data,
                                             const class GALGAS_uint constin_level,
                                             class C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlExpressionMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlExpressionMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_gtlExpressionMap_get ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlExpressionMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_gtlExpressionMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_gtlExpressionMap (const GALGAS_gtlExpressionMap & inSource) ;
  public: GALGAS_gtlExpressionMap & operator = (const GALGAS_gtlExpressionMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlExpressionMap extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlExpressionMap constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_gtlExpressionMap constructor_mapWithMapToOverride (const class GALGAS_gtlExpressionMap & inOperand0
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_gtlExpression & inOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionMap add_operation (const GALGAS_gtlExpressionMap & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_del (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlExpression & outArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlExpression constinArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setExpressionForKey (class GALGAS_gtlExpression constinArgument0,
                                                            class GALGAS_string constinArgument1,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlExpression & outArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_expressionForKey (const class GALGAS_string & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionMap getter_overriddenMap (C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_gtlExpression & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_gtlExpressionMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_gtlExpressionMap ;
 
} ; // End of GALGAS_gtlExpressionMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlExpressionMap : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlExpressionMap (const GALGAS_gtlExpressionMap & inEnumeratedObject,
                                        const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_gtlExpression current_expression (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlExpressionMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExpressionMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlExpression : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlExpression * ptr (void) const {
    return (const cPtr_gtlExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlExpression (const cPtr_gtlExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_location readProperty_where (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlExpression extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setWhere (class GALGAS_location inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@gtlExpressionMap' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlExpressionMap : public cMapElement {
//--- Map attributes
  public: GALGAS_gtlExpression mProperty_expression ;

//--- Constructor
  public: cMapElement_gtlExpressionMap (const GALGAS_lstring & inKey,
                                        const GALGAS_gtlExpression & in_expression
                                        COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlExpressionMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlExpressionMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_gtlExpression mProperty_expression ;
  public: inline GALGAS_gtlExpression readProperty_expression (void) const {
    return mProperty_expression ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlExpressionMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setExpression (const GALGAS_gtlExpression & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_expression = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlExpressionMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlExpressionMap_2D_element (const GALGAS_lstring & in_lkey,
                                              const GALGAS_gtlExpression & in_expression) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlExpressionMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlExpressionMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                           const class GALGAS_gtlExpression & inOperand1
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlExpressionMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlExpressionMap_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExpressionMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlInstructionList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlInstructionList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_gtlInstructionList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_gtlInstructionList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_gtlInstruction & in_instruction
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlInstructionList extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlInstructionList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_gtlInstructionList constructor_listWithValue (const class GALGAS_gtlInstruction & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_gtlInstructionList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_gtlInstruction & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList add_operation (const GALGAS_gtlInstructionList & inOperand,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_gtlInstruction constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_gtlInstruction constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_gtlInstruction & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_gtlInstruction & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_gtlInstruction & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInstructionAtIndex (class GALGAS_gtlInstruction constinArgument0,
                                                              class GALGAS_uint constinArgument1,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_gtlInstruction & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_gtlInstruction & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlInstruction getter_instructionAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_gtlInstructionList ;
 
} ; // End of GALGAS_gtlInstructionList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlInstructionList : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlInstructionList (const GALGAS_gtlInstructionList & inEnumeratedObject,
                                          const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_gtlInstruction current_instruction (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlInstructionList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInstructionList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlInstruction : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlInstruction * ptr (void) const {
    return (const cPtr_gtlInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlInstruction (const cPtr_gtlInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_location readProperty_where (void) const ;

  public: class GALGAS_string readProperty_signature (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlInstruction extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setSignature (class GALGAS_string inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setWhere (class GALGAS_location inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlInstruction : public acPtr_class {

//--- Extension getter location
  public: virtual class GALGAS_location getter_location (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter mayExecuteWithoutError
  public: virtual class GALGAS_bool getter_mayExecuteWithoutError (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter shortLocation
  public: virtual class GALGAS_string getter_shortLocation (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) = 0 ;

//--- Extension method displayWithLocation
  public: virtual void method_displayWithLocation (const class GALGAS_debuggerContext context,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) = 0 ;


//--- Properties
  public: GALGAS_location mProperty_where ;
  public: GALGAS_string mProperty_signature ;

//--- Constructor
  public: cPtr_gtlInstruction (const GALGAS_location & in_where,
                               const GALGAS_string & in_signature
                               COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_location getter_where (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setWhere (GALGAS_location inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_signature (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSignature (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlInstructionList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlInstructionList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_gtlInstruction mProperty_instruction ;
  public: inline GALGAS_gtlInstruction readProperty_instruction (void) const {
    return mProperty_instruction ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlInstructionList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setInstruction (const GALGAS_gtlInstruction & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_instruction = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlInstructionList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlInstructionList_2D_element (const GALGAS_gtlInstruction & in_instruction) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlInstructionList_2D_element extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlInstructionList_2D_element constructor_new (const class GALGAS_gtlInstruction & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlInstructionList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlInstructionList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInstructionList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTemplateMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlTemplateMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_gtlTemplateMap_get ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTemplateMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_gtlTemplateMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_gtlTemplateMap (const GALGAS_gtlTemplateMap & inSource) ;
  public: GALGAS_gtlTemplateMap & operator = (const GALGAS_gtlTemplateMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTemplateMap extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTemplateMap constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_gtlTemplateMap constructor_mapWithMapToOverride (const class GALGAS_gtlTemplateMap & inOperand0
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_gtlTemplate & inOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlTemplateMap add_operation (const GALGAS_gtlTemplateMap & inOperand,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlTemplate constinArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setATemplateForKey (class GALGAS_gtlTemplate constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlTemplate & outArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlTemplate getter_aTemplateForKey (const class GALGAS_string & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlTemplateMap getter_overriddenMap (C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_gtlTemplate & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_gtlTemplateMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_gtlTemplateMap ;
 
} ; // End of GALGAS_gtlTemplateMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlTemplateMap : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlTemplateMap (const GALGAS_gtlTemplateMap & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_gtlTemplate current_aTemplate (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlTemplateMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTemplateMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTemplate  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTemplate : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlTemplate (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlTemplate constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlTemplate * ptr (void) const {
    return (const cPtr_gtlTemplate *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlTemplate (const cPtr_gtlTemplate * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_string readProperty_path (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_program (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTemplate extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTemplate constructor_new (const class GALGAS_string & inOperand0,
                                                           const class GALGAS_gtlInstructionList & inOperand1
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlTemplate & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setPath (class GALGAS_string inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setProgram (class GALGAS_gtlInstructionList inArgument0
                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlTemplate class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTemplate ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@gtlTemplateMap' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlTemplateMap : public cMapElement {
//--- Map attributes
  public: GALGAS_gtlTemplate mProperty_aTemplate ;

//--- Constructor
  public: cMapElement_gtlTemplateMap (const GALGAS_lstring & inKey,
                                      const GALGAS_gtlTemplate & in_aTemplate
                                      COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTemplateMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTemplateMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_gtlTemplate mProperty_aTemplate ;
  public: inline GALGAS_gtlTemplate readProperty_aTemplate (void) const {
    return mProperty_aTemplate ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlTemplateMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_gtlTemplateMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setATemplate (const GALGAS_gtlTemplate & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_aTemplate = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlTemplateMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlTemplateMap_2D_element (const GALGAS_lstring & in_lkey,
                                            const GALGAS_gtlTemplate & in_aTemplate) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTemplateMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTemplateMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                         const class GALGAS_gtlTemplate & inOperand1
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlTemplateMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlTemplateMap_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTemplateMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlTemplateMap getTemplate'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_getTemplate (class GALGAS_gtlTemplateMap & ioObject,
                                  const class GALGAS_gtlContext constin_context,
                                  class GALGAS_lstring in_path,
                                  class GALGAS_bool in_ifExists,
                                  class GALGAS_library & io_lib,
                                  class GALGAS_bool & out_found,
                                  class GALGAS_gtlTemplate & out_result,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @debugCommandInput  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_debugCommandInput : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_debugCommandInput (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_debugCommandInput constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_debugCommandInput * ptr (void) const {
    return (const cPtr_debugCommandInput *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_debugCommandInput (const cPtr_debugCommandInput * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_stringlist readProperty_history (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_debugCommandInput extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_debugCommandInput constructor_new (const class GALGAS_stringlist & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_debugCommandInput & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setHistory (class GALGAS_stringlist inArgument0
                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_debugCommandInput class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_debugCommandInput ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @debugCommandInput class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_debugCommandInput : public acPtr_class {

//--- Extension method listHistory
  public: virtual void method_listHistory (C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_stringlist mProperty_history ;

//--- Constructor
  public: cPtr_debugCommandInput (const GALGAS_stringlist & in_history
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_stringlist getter_history (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setHistory (GALGAS_stringlist inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @debuggerContext  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_debuggerContext : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_debuggerContext (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_debuggerContext constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_debuggerContext * ptr (void) const {
    return (const cPtr_debuggerContext *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_debuggerContext (const cPtr_debuggerContext * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_bool readProperty_debugActive (void) const ;

  public: class GALGAS_bool readProperty_breakOnNext (void) const ;

  public: class GALGAS_bool readProperty_loopOnCommand (void) const ;

  public: class GALGAS_string readProperty_promptColor (void) const ;

  public: class GALGAS_string readProperty_promptFace (void) const ;

  public: class GALGAS_string readProperty_instructionColor (void) const ;

  public: class GALGAS_string readProperty_instructionFace (void) const ;

  public: class GALGAS_string readProperty_outputColor (void) const ;

  public: class GALGAS_string readProperty_outputFace (void) const ;

  public: class GALGAS_string readProperty_warningColor (void) const ;

  public: class GALGAS_string readProperty_warningFace (void) const ;

  public: class GALGAS_bool readProperty_executeDebuggerCommand (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_doList (void) const ;

  public: class GALGAS_gtlBreakpointList readProperty_breakpoints (void) const ;

  public: class GALGAS_gtlExpressionList readProperty_watchpoints (void) const ;

  public: class GALGAS_uint readProperty_nextInstructionIndex (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_instructionList (void) const ;

  public: class GALGAS_gtlInstructionListContextStack readProperty_contextStack (void) const ;

  public: class GALGAS_debugCommandInput readProperty_commandInput (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_debuggerContext extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_debuggerContext constructor_new (const class GALGAS_bool & inOperand0,
                                                               const class GALGAS_bool & inOperand1,
                                                               const class GALGAS_bool & inOperand2,
                                                               const class GALGAS_string & inOperand3,
                                                               const class GALGAS_string & inOperand4,
                                                               const class GALGAS_string & inOperand5,
                                                               const class GALGAS_string & inOperand6,
                                                               const class GALGAS_string & inOperand7,
                                                               const class GALGAS_string & inOperand8,
                                                               const class GALGAS_string & inOperand9,
                                                               const class GALGAS_string & inOperand10,
                                                               const class GALGAS_bool & inOperand11,
                                                               const class GALGAS_gtlInstructionList & inOperand12,
                                                               const class GALGAS_gtlBreakpointList & inOperand13,
                                                               const class GALGAS_gtlExpressionList & inOperand14,
                                                               const class GALGAS_uint & inOperand15,
                                                               const class GALGAS_gtlInstructionList & inOperand16,
                                                               const class GALGAS_gtlInstructionListContextStack & inOperand17,
                                                               const class GALGAS_debugCommandInput & inOperand18
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_debuggerContext & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setBreakOnNext (class GALGAS_bool inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setBreakpoints (class GALGAS_gtlBreakpointList inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setCommandInput (class GALGAS_debugCommandInput inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setContextStack (class GALGAS_gtlInstructionListContextStack inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setDebugActive (class GALGAS_bool inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setDoList (class GALGAS_gtlInstructionList inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setExecuteDebuggerCommand (class GALGAS_bool inArgument0
                                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInstructionColor (class GALGAS_string inArgument0
                                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInstructionFace (class GALGAS_string inArgument0
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInstructionList (class GALGAS_gtlInstructionList inArgument0
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLoopOnCommand (class GALGAS_bool inArgument0
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setNextInstructionIndex (class GALGAS_uint inArgument0
                                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setOutputColor (class GALGAS_string inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setOutputFace (class GALGAS_string inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setPromptColor (class GALGAS_string inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setPromptFace (class GALGAS_string inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setWarningColor (class GALGAS_string inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setWarningFace (class GALGAS_string inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setWatchpoints (class GALGAS_gtlExpressionList inArgument0
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_debuggerContext class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_debuggerContext ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlBreakpointList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlBreakpointList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_gtlBreakpointList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_gtlBreakpointList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_gtlBreakpoint & in_breakpoint
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlBreakpointList extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlBreakpointList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_gtlBreakpointList constructor_listWithValue (const class GALGAS_gtlBreakpoint & inOperand0
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_gtlBreakpointList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_gtlBreakpoint & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlBreakpointList add_operation (const GALGAS_gtlBreakpointList & inOperand,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_gtlBreakpoint constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_gtlBreakpoint constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_gtlBreakpoint & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_gtlBreakpoint & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_gtlBreakpoint & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setBreakpointAtIndex (class GALGAS_gtlBreakpoint constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_gtlBreakpoint & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_gtlBreakpoint & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlBreakpoint getter_breakpointAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlBreakpointList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlBreakpointList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlBreakpointList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_gtlBreakpointList ;
 
} ; // End of GALGAS_gtlBreakpointList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlBreakpointList : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlBreakpointList (const GALGAS_gtlBreakpointList & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_gtlBreakpoint current_breakpoint (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlBreakpointList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlBreakpointList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlExpressionList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlExpressionList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_gtlExpressionList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_gtlExpressionList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_gtlExpression & in_expression
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlExpressionList extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlExpressionList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_gtlExpressionList constructor_listWithValue (const class GALGAS_gtlExpression & inOperand0
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_gtlExpressionList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_gtlExpression & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList add_operation (const GALGAS_gtlExpressionList & inOperand,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_gtlExpression constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_gtlExpression constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_gtlExpression & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_gtlExpression & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_gtlExpression & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setExpressionAtIndex (class GALGAS_gtlExpression constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_gtlExpression & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_gtlExpression & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_expressionAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlExpressionList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_gtlExpressionList ;
 
} ; // End of GALGAS_gtlExpressionList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlExpressionList : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlExpressionList (const GALGAS_gtlExpressionList & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_gtlExpression current_expression (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlExpressionList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExpressionList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlInstructionListContextStack list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlInstructionListContextStack : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_gtlInstructionListContextStack (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_gtlInstructionListContextStack (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_uint & in_nextInstructionIndex,
                                                 const class GALGAS_gtlInstructionList & in_instructionList
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlInstructionListContextStack extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlInstructionListContextStack constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_gtlInstructionListContextStack constructor_listWithValue (const class GALGAS_uint & inOperand0,
                                                                                        const class GALGAS_gtlInstructionList & inOperand1
                                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_gtlInstructionListContextStack inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_uint & inOperand0,
                                                     const class GALGAS_gtlInstructionList & inOperand1
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionListContextStack add_operation (const GALGAS_gtlInstructionListContextStack & inOperand,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_uint constinArgument0,
                                               class GALGAS_gtlInstructionList constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_uint constinArgument0,
                                                      class GALGAS_gtlInstructionList constinArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_uint & outArgument0,
                                                 class GALGAS_gtlInstructionList & outArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_uint & outArgument0,
                                                class GALGAS_gtlInstructionList & outArgument1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_uint & outArgument0,
                                                      class GALGAS_gtlInstructionList & outArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInstructionListAtIndex (class GALGAS_gtlInstructionList constinArgument0,
                                                                  class GALGAS_uint constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setNextInstructionIndexAtIndex (class GALGAS_uint constinArgument0,
                                                                       class GALGAS_uint constinArgument1,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_uint & outArgument0,
                                              class GALGAS_gtlInstructionList & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_uint & outArgument0,
                                             class GALGAS_gtlInstructionList & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_instructionListAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_uint getter_nextInstructionIndexAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionListContextStack getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionListContextStack getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionListContextStack getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_gtlInstructionListContextStack ;
 
} ; // End of GALGAS_gtlInstructionListContextStack class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlInstructionListContextStack : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlInstructionListContextStack (const GALGAS_gtlInstructionListContextStack & inEnumeratedObject,
                                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_uint current_nextInstructionIndex (LOCATION_ARGS) const ;
  public: class GALGAS_gtlInstructionList current_instructionList (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlInstructionListContextStack_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInstructionListContextStack ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @debuggerContext class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_debuggerContext : public acPtr_class {

//--- Extension getter breakOn
  public: virtual class GALGAS_bool getter_breakOn (const class GALGAS_gtlInstruction instruction,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter watchOn
  public: virtual class GALGAS_bool getter_watchOn (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method hereWeAre
  public: virtual void method_hereWeAre (const class GALGAS_uint window,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method listBreakpoints
  public: virtual void method_listBreakpoints (C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method listStepDoInstructions
  public: virtual void method_listStepDoInstructions (C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method listWatchpoints
  public: virtual void method_listWatchpoints (C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_bool mProperty_debugActive ;
  public: GALGAS_bool mProperty_breakOnNext ;
  public: GALGAS_bool mProperty_loopOnCommand ;
  public: GALGAS_string mProperty_promptColor ;
  public: GALGAS_string mProperty_promptFace ;
  public: GALGAS_string mProperty_instructionColor ;
  public: GALGAS_string mProperty_instructionFace ;
  public: GALGAS_string mProperty_outputColor ;
  public: GALGAS_string mProperty_outputFace ;
  public: GALGAS_string mProperty_warningColor ;
  public: GALGAS_string mProperty_warningFace ;
  public: GALGAS_bool mProperty_executeDebuggerCommand ;
  public: GALGAS_gtlInstructionList mProperty_doList ;
  public: GALGAS_gtlBreakpointList mProperty_breakpoints ;
  public: GALGAS_gtlExpressionList mProperty_watchpoints ;
  public: GALGAS_uint mProperty_nextInstructionIndex ;
  public: GALGAS_gtlInstructionList mProperty_instructionList ;
  public: GALGAS_gtlInstructionListContextStack mProperty_contextStack ;
  public: GALGAS_debugCommandInput mProperty_commandInput ;

//--- Constructor
  public: cPtr_debuggerContext (const GALGAS_bool & in_debugActive,
                                const GALGAS_bool & in_breakOnNext,
                                const GALGAS_bool & in_loopOnCommand,
                                const GALGAS_string & in_promptColor,
                                const GALGAS_string & in_promptFace,
                                const GALGAS_string & in_instructionColor,
                                const GALGAS_string & in_instructionFace,
                                const GALGAS_string & in_outputColor,
                                const GALGAS_string & in_outputFace,
                                const GALGAS_string & in_warningColor,
                                const GALGAS_string & in_warningFace,
                                const GALGAS_bool & in_executeDebuggerCommand,
                                const GALGAS_gtlInstructionList & in_doList,
                                const GALGAS_gtlBreakpointList & in_breakpoints,
                                const GALGAS_gtlExpressionList & in_watchpoints,
                                const GALGAS_uint & in_nextInstructionIndex,
                                const GALGAS_gtlInstructionList & in_instructionList,
                                const GALGAS_gtlInstructionListContextStack & in_contextStack,
                                const GALGAS_debugCommandInput & in_commandInput
                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_debugActive (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDebugActive (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_breakOnNext (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setBreakOnNext (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_loopOnCommand (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLoopOnCommand (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_promptColor (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setPromptColor (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_promptFace (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setPromptFace (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_instructionColor (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setInstructionColor (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_instructionFace (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setInstructionFace (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_outputColor (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setOutputColor (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_outputFace (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setOutputFace (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_warningColor (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setWarningColor (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_warningFace (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setWarningFace (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_executeDebuggerCommand (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setExecuteDebuggerCommand (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_doList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDoList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlBreakpointList getter_breakpoints (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setBreakpoints (GALGAS_gtlBreakpointList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_watchpoints (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setWatchpoints (GALGAS_gtlExpressionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_uint getter_nextInstructionIndex (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setNextInstructionIndex (GALGAS_uint inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_instructionList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setInstructionList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionListContextStack getter_contextStack (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setContextStack (GALGAS_gtlInstructionListContextStack inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_debugCommandInput getter_commandInput (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setCommandInput (GALGAS_debugCommandInput inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlContext  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlContext : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlContext (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlContext constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlContext * ptr (void) const {
    return (const cPtr_gtlContext *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlContext (const cPtr_gtlContext * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_prefix (void) const ;

  public: class GALGAS_string readProperty_path (void) const ;

  public: class GALGAS_string readProperty_templateDirectory (void) const ;

  public: class GALGAS_string readProperty_userTemplateDirectory (void) const ;

  public: class GALGAS_string readProperty_templateExtension (void) const ;

  public: class GALGAS_stringlist readProperty_importPath (void) const ;

  public: class GALGAS_gtlDataList readProperty_inputVars (void) const ;

  public: class GALGAS_bool readProperty_propagateError (void) const ;

  public: class GALGAS_debuggerContext readProperty_debuggerContext (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlContext extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlContext constructor_new (const class GALGAS_lstring & inOperand0,
                                                          const class GALGAS_string & inOperand1,
                                                          const class GALGAS_string & inOperand2,
                                                          const class GALGAS_string & inOperand3,
                                                          const class GALGAS_string & inOperand4,
                                                          const class GALGAS_stringlist & inOperand5,
                                                          const class GALGAS_gtlDataList & inOperand6,
                                                          const class GALGAS_bool & inOperand7,
                                                          const class GALGAS_debuggerContext & inOperand8
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlContext & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setDebuggerContext (class GALGAS_debuggerContext inArgument0
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setImportPath (class GALGAS_stringlist inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInputVars (class GALGAS_gtlDataList inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setPath (class GALGAS_string inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setPrefix (class GALGAS_lstring inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setPropagateError (class GALGAS_bool inArgument0
                                                          COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTemplateDirectory (class GALGAS_string inArgument0
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTemplateExtension (class GALGAS_string inArgument0
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setUserTemplateDirectory (class GALGAS_string inArgument0
                                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlContext class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlContext ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlContext class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlContext : public acPtr_class {

//--- Extension getter breakOn
  public: virtual class GALGAS_bool getter_breakOn (const class GALGAS_gtlInstruction instruction,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter breakOnNext
  public: virtual class GALGAS_bool getter_breakOnNext (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter debugActive
  public: virtual class GALGAS_bool getter_debugActive (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter fullPrefix
  public: virtual class GALGAS_lstring getter_fullPrefix (const class GALGAS_gtlData vars,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter fullTemplateFileName
  public: virtual class GALGAS_lstring getter_fullTemplateFileName (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_lstring simpleName,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter loopOnCommand
  public: virtual class GALGAS_bool getter_loopOnCommand (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter outputStyle
  public: virtual class GALGAS_string getter_outputStyle (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter promptStyle
  public: virtual class GALGAS_string getter_promptStyle (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter watchOn
  public: virtual class GALGAS_bool getter_watchOn (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method hereWeAre
  public: virtual void method_hereWeAre (const class GALGAS_uint window,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method listBreakpoints
  public: virtual void method_listBreakpoints (C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method listStepDoInstructions
  public: virtual void method_listStepDoInstructions (C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method listWatchpoints
  public: virtual void method_listWatchpoints (C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_lstring mProperty_prefix ;
  public: GALGAS_string mProperty_path ;
  public: GALGAS_string mProperty_templateDirectory ;
  public: GALGAS_string mProperty_userTemplateDirectory ;
  public: GALGAS_string mProperty_templateExtension ;
  public: GALGAS_stringlist mProperty_importPath ;
  public: GALGAS_gtlDataList mProperty_inputVars ;
  public: GALGAS_bool mProperty_propagateError ;
  public: GALGAS_debuggerContext mProperty_debuggerContext ;

//--- Constructor
  public: cPtr_gtlContext (const GALGAS_lstring & in_prefix,
                           const GALGAS_string & in_path,
                           const GALGAS_string & in_templateDirectory,
                           const GALGAS_string & in_userTemplateDirectory,
                           const GALGAS_string & in_templateExtension,
                           const GALGAS_stringlist & in_importPath,
                           const GALGAS_gtlDataList & in_inputVars,
                           const GALGAS_bool & in_propagateError,
                           const GALGAS_debuggerContext & in_debuggerContext
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setPrefix (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_path (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setPath (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_templateDirectory (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTemplateDirectory (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_userTemplateDirectory (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setUserTemplateDirectory (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_templateExtension (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTemplateExtension (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_stringlist getter_importPath (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setImportPath (GALGAS_stringlist inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlDataList getter_inputVars (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setInputVars (GALGAS_gtlDataList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_propagateError (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setPropagateError (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_debuggerContext getter_debuggerContext (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDebuggerContext (GALGAS_debuggerContext inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlTemplate class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlTemplate : public acPtr_class {

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_string mProperty_path ;
  public: GALGAS_gtlInstructionList mProperty_program ;

//--- Constructor
  public: cPtr_gtlTemplate (const GALGAS_string & in_path,
                            const GALGAS_gtlInstructionList & in_program
                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_path (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setPath (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_program (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setProgram (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @library  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_library : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_library (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_library constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_library * ptr (void) const {
    return (const cPtr_library *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_library (const cPtr_library * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlFuncMap readProperty_funcMap (void) const ;

  public: class GALGAS_gtlGetterMap readProperty_getterMap (void) const ;

  public: class GALGAS_gtlSetterMap readProperty_setterMap (void) const ;

  public: class GALGAS_gtlTemplateMap readProperty_templateMap (void) const ;

  public: class GALGAS_stringset readProperty_doneImports (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_library extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_library constructor_new (const class GALGAS_gtlFuncMap & inOperand0,
                                                       const class GALGAS_gtlGetterMap & inOperand1,
                                                       const class GALGAS_gtlSetterMap & inOperand2,
                                                       const class GALGAS_gtlTemplateMap & inOperand3,
                                                       const class GALGAS_stringset & inOperand4
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_library & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setDoneImports (class GALGAS_stringset inArgument0
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setFuncMap (class GALGAS_gtlFuncMap inArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setGetterMap (class GALGAS_gtlGetterMap inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setSetterMap (class GALGAS_gtlSetterMap inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTemplateMap (class GALGAS_gtlTemplateMap inArgument0
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_library class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_library ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlExecutableEntity  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlExecutableEntity : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlExecutableEntity (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlExecutableEntity constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlExecutableEntity * ptr (void) const {
    return (const cPtr_gtlExecutableEntity *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlExecutableEntity (const cPtr_gtlExecutableEntity * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_location readProperty_where (void) const ;

  public: class GALGAS_lstring readProperty_name (void) const ;

  public: class GALGAS_gtlArgumentList readProperty_formalArguments (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_instructions (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlExecutableEntity extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlExecutableEntity constructor_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_lstring & inOperand1,
                                                                   const class GALGAS_gtlArgumentList & inOperand2,
                                                                   const class GALGAS_gtlInstructionList & inOperand3
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlExecutableEntity & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setFormalArguments (class GALGAS_gtlArgumentList inArgument0
                                                           COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInstructions (class GALGAS_gtlInstructionList inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setName (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setWhere (class GALGAS_location inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlExecutableEntity class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExecutableEntity ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlArgumentList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlArgumentList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_gtlArgumentList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_gtlArgumentList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_bool & in_typed,
                                                 const class GALGAS_type & in_type,
                                                 const class GALGAS_lstring & in_name
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlArgumentList extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlArgumentList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_gtlArgumentList constructor_listWithValue (const class GALGAS_bool & inOperand0,
                                                                         const class GALGAS_type & inOperand1,
                                                                         const class GALGAS_lstring & inOperand2
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_gtlArgumentList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_bool & inOperand0,
                                                     const class GALGAS_type & inOperand1,
                                                     const class GALGAS_lstring & inOperand2
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlArgumentList add_operation (const GALGAS_gtlArgumentList & inOperand,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_bool constinArgument0,
                                               class GALGAS_type constinArgument1,
                                               class GALGAS_lstring constinArgument2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_bool constinArgument0,
                                                      class GALGAS_type constinArgument1,
                                                      class GALGAS_lstring constinArgument2,
                                                      class GALGAS_uint constinArgument3,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_bool & outArgument0,
                                                 class GALGAS_type & outArgument1,
                                                 class GALGAS_lstring & outArgument2,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_bool & outArgument0,
                                                class GALGAS_type & outArgument1,
                                                class GALGAS_lstring & outArgument2,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_bool & outArgument0,
                                                      class GALGAS_type & outArgument1,
                                                      class GALGAS_lstring & outArgument2,
                                                      class GALGAS_uint constinArgument3,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setNameAtIndex (class GALGAS_lstring constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTypeAtIndex (class GALGAS_type constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTypedAtIndex (class GALGAS_bool constinArgument0,
                                                        class GALGAS_uint constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_bool & outArgument0,
                                              class GALGAS_type & outArgument1,
                                              class GALGAS_lstring & outArgument2,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_bool & outArgument0,
                                             class GALGAS_type & outArgument1,
                                             class GALGAS_lstring & outArgument2,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_nameAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlArgumentList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlArgumentList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlArgumentList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_type getter_typeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_typedAtIndex (const class GALGAS_uint & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_gtlArgumentList ;
 
} ; // End of GALGAS_gtlArgumentList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlArgumentList : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlArgumentList (const GALGAS_gtlArgumentList & inEnumeratedObject,
                                       const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_bool current_typed (LOCATION_ARGS) const ;
  public: class GALGAS_type current_type (LOCATION_ARGS) const ;
  public: class GALGAS_lstring current_name (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlArgumentList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlArgumentList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlExecutableEntity class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlExecutableEntity : public acPtr_class {

//--- Extension method checkArguments
  public: virtual void method_checkArguments (const class GALGAS_location fromLocation,
           const class GALGAS_gtlDataList actualArguments,
           class GALGAS_gtlData & entityVariableMap,
           class GALGAS_bool & result,
           C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_location mProperty_where ;
  public: GALGAS_lstring mProperty_name ;
  public: GALGAS_gtlArgumentList mProperty_formalArguments ;
  public: GALGAS_gtlInstructionList mProperty_instructions ;

//--- Constructor
  public: cPtr_gtlExecutableEntity (const GALGAS_location & in_where,
                                    const GALGAS_lstring & in_name,
                                    const GALGAS_gtlArgumentList & in_formalArguments,
                                    const GALGAS_gtlInstructionList & in_instructions
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_location getter_where (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setWhere (GALGAS_location inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlArgumentList getter_formalArguments (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFormalArguments (GALGAS_gtlArgumentList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_instructions (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setInstructions (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlFunction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlFunction : public GALGAS_gtlExecutableEntity {
//--------------------------------- Default constructor
  public: GALGAS_gtlFunction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlFunction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlFunction * ptr (void) const {
    return (const cPtr_gtlFunction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlFunction (const cPtr_gtlFunction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_returnVariable (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlFunction extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlFunction constructor_new (const class GALGAS_location & inOperand0,
                                                           const class GALGAS_lstring & inOperand1,
                                                           const class GALGAS_gtlArgumentList & inOperand2,
                                                           const class GALGAS_gtlInstructionList & inOperand3,
                                                           const class GALGAS_lstring & inOperand4
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlFunction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setReturnVariable (class GALGAS_lstring inArgument0
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlFunction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlFunction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlFuncMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlFuncMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_gtlFuncMap_get ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlFuncMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_gtlFuncMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_gtlFuncMap (const GALGAS_gtlFuncMap & inSource) ;
  public: GALGAS_gtlFuncMap & operator = (const GALGAS_gtlFuncMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlFuncMap extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlFuncMap constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_gtlFuncMap constructor_mapWithMapToOverride (const class GALGAS_gtlFuncMap & inOperand0
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_gtlFunction & inOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlFuncMap add_operation (const GALGAS_gtlFuncMap & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlFunction constinArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setFunctionForKey (class GALGAS_gtlFunction constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlFunction & outArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlFunction getter_functionForKey (const class GALGAS_string & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlFuncMap getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_gtlFunction & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_gtlFuncMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_gtlFuncMap ;
 
} ; // End of GALGAS_gtlFuncMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlFuncMap : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlFuncMap (const GALGAS_gtlFuncMap & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_gtlFunction current_function (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlFuncMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlFuncMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@gtlFuncMap' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlFuncMap : public cMapElement {
//--- Map attributes
  public: GALGAS_gtlFunction mProperty_function ;

//--- Constructor
  public: cMapElement_gtlFuncMap (const GALGAS_lstring & inKey,
                                  const GALGAS_gtlFunction & in_function
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlFunction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlFunction : public cPtr_gtlExecutableEntity {

//--- Extension getter call
  public: virtual class GALGAS_gtlData getter_call (const class GALGAS_location fromLocation,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           const class GALGAS_gtlDataList actualArguments,
           C_Compiler * COMMA_LOCATION_ARGS) const ;


//--- Properties
  public: GALGAS_lstring mProperty_returnVariable ;

//--- Constructor
  public: cPtr_gtlFunction (const GALGAS_location & in_where,
                            const GALGAS_lstring & in_name,
                            const GALGAS_gtlArgumentList & in_formalArguments,
                            const GALGAS_gtlInstructionList & in_instructions,
                            const GALGAS_lstring & in_returnVariable
                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_returnVariable (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setReturnVariable (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlGetter  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlGetter : public GALGAS_gtlFunction {
//--------------------------------- Default constructor
  public: GALGAS_gtlGetter (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlGetter * ptr (void) const {
    return (const cPtr_gtlGetter *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlGetter (const cPtr_gtlGetter * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_type readProperty_targetType (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlGetter extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlGetter constructor_new (const class GALGAS_location & inOperand0,
                                                         const class GALGAS_lstring & inOperand1,
                                                         const class GALGAS_gtlArgumentList & inOperand2,
                                                         const class GALGAS_gtlInstructionList & inOperand3,
                                                         const class GALGAS_lstring & inOperand4,
                                                         const class GALGAS_type & inOperand5
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlGetter & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setTargetType (class GALGAS_type inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlGetter class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGetter ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlGetterMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlGetterMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_gtlGetterMap_get ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlGetterMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_gtlGetterMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_gtlGetterMap (const GALGAS_gtlGetterMap & inSource) ;
  public: GALGAS_gtlGetterMap & operator = (const GALGAS_gtlGetterMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlGetterMap extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlGetterMap constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_gtlGetterMap constructor_mapWithMapToOverride (const class GALGAS_gtlGetterMap & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_gtlGetter & inOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlGetterMap add_operation (const GALGAS_gtlGetterMap & inOperand,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlGetter constinArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTheGetterForKey (class GALGAS_gtlGetter constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlGetter & outArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlGetterMap getter_overriddenMap (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlGetter getter_theGetterForKey (const class GALGAS_string & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_gtlGetter & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_gtlGetterMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                         const GALGAS_string & inKey
                                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_gtlGetterMap ;
 
} ; // End of GALGAS_gtlGetterMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlGetterMap : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlGetterMap (const GALGAS_gtlGetterMap & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_gtlGetter current_theGetter (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlGetterMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGetterMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@gtlGetterMap' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlGetterMap : public cMapElement {
//--- Map attributes
  public: GALGAS_gtlGetter mProperty_theGetter ;

//--- Constructor
  public: cMapElement_gtlGetterMap (const GALGAS_lstring & inKey,
                                    const GALGAS_gtlGetter & in_theGetter
                                    COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlSetter  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlSetter : public GALGAS_gtlExecutableEntity {
//--------------------------------- Default constructor
  public: GALGAS_gtlSetter (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlSetter * ptr (void) const {
    return (const cPtr_gtlSetter *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlSetter (const cPtr_gtlSetter * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_type readProperty_targetType (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlSetter extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlSetter constructor_new (const class GALGAS_location & inOperand0,
                                                         const class GALGAS_lstring & inOperand1,
                                                         const class GALGAS_gtlArgumentList & inOperand2,
                                                         const class GALGAS_gtlInstructionList & inOperand3,
                                                         const class GALGAS_type & inOperand4
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlSetter & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setTargetType (class GALGAS_type inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlSetter class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSetter ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlSetterMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlSetterMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_gtlSetterMap_get ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlSetterMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_gtlSetterMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_gtlSetterMap (const GALGAS_gtlSetterMap & inSource) ;
  public: GALGAS_gtlSetterMap & operator = (const GALGAS_gtlSetterMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlSetterMap extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlSetterMap constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_gtlSetterMap constructor_mapWithMapToOverride (const class GALGAS_gtlSetterMap & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_gtlSetter & inOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlSetterMap add_operation (const GALGAS_gtlSetterMap & inOperand,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlSetter constinArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTheSetterForKey (class GALGAS_gtlSetter constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlSetter & outArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlSetterMap getter_overriddenMap (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlSetter getter_theSetterForKey (const class GALGAS_string & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_gtlSetter & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_gtlSetterMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                         const GALGAS_string & inKey
                                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_gtlSetterMap ;
 
} ; // End of GALGAS_gtlSetterMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlSetterMap : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlSetterMap (const GALGAS_gtlSetterMap & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_gtlSetter current_theSetter (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlSetterMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSetterMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@gtlSetterMap' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlSetterMap : public cMapElement {
//--- Map attributes
  public: GALGAS_gtlSetter mProperty_theSetter ;

//--- Constructor
  public: cMapElement_gtlSetterMap (const GALGAS_lstring & inKey,
                                    const GALGAS_gtlSetter & in_theSetter
                                    COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @library class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_library : public acPtr_class {

//--- Extension getter functionExists
  public: virtual class GALGAS_bool getter_functionExists (const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter getFunction
  public: virtual class GALGAS_gtlFunction getter_getFunction (const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter getGetter
  public: virtual class GALGAS_gtlGetter getter_getGetter (const class GALGAS_string type,
           const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter getSetter
  public: virtual class GALGAS_gtlSetter getter_getSetter (const class GALGAS_string type,
           const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter getterExists
  public: virtual class GALGAS_bool getter_getterExists (const class GALGAS_string type,
           const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter hasImport
  public: virtual class GALGAS_bool getter_hasImport (const class GALGAS_string importPath,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter setterExists
  public: virtual class GALGAS_bool getter_setterExists (const class GALGAS_string type,
           const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const ;


//--- Properties
  public: GALGAS_gtlFuncMap mProperty_funcMap ;
  public: GALGAS_gtlGetterMap mProperty_getterMap ;
  public: GALGAS_gtlSetterMap mProperty_setterMap ;
  public: GALGAS_gtlTemplateMap mProperty_templateMap ;
  public: GALGAS_stringset mProperty_doneImports ;

//--- Constructor
  public: cPtr_library (const GALGAS_gtlFuncMap & in_funcMap,
                        const GALGAS_gtlGetterMap & in_getterMap,
                        const GALGAS_gtlSetterMap & in_setterMap,
                        const GALGAS_gtlTemplateMap & in_templateMap,
                        const GALGAS_stringset & in_doneImports
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlFuncMap getter_funcMap (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFuncMap (GALGAS_gtlFuncMap inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlGetterMap getter_getterMap (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setGetterMap (GALGAS_gtlGetterMap inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlSetterMap getter_setterMap (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSetterMap (GALGAS_gtlSetterMap inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlTemplateMap getter_templateMap (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTemplateMap (GALGAS_gtlTemplateMap inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_stringset getter_doneImports (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDoneImports (GALGAS_stringset inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//LEXIQUE gtl_5F_scanner
//
//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/C_Lexique.h"

//----------------------------------------------------------------------------------------------------------------------
//                    E X T E R N    R O U T I N E S
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//                    E X T E R N    F U N C T I O N S
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//                       T O K E N    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class cTokenFor_gtl_5F_scanner : public cToken {
  public: C_String mLexicalAttribute_a_5F_string ;
  public: utf32 mLexicalAttribute_charValue ;
  public: double mLexicalAttribute_floatValue ;
  public: C_String mLexicalAttribute_functionContent ;
  public: C_String mLexicalAttribute_identifierString ;
  public: C_BigInt mLexicalAttribute_intValue ;
  public: C_String mLexicalAttribute_tokenString ;
  public: uint32_t mLexicalAttribute_uint_33__32_value ;

  public: cTokenFor_gtl_5F_scanner (void) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class C_Lexique_gtl_5F_scanner : public C_Lexique {
//--- Constructors
  public: C_Lexique_gtl_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public: C_Lexique_gtl_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public: static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected: virtual ~ C_Lexique_gtl_5F_scanner (void) {}
  #endif

//--- Scanner mode for template scanner
  private: int32_t mMatchedTemplateDelimiterIndex ;



//--- Terminal symbols enumeration
  public: enum {kToken_,
   kToken_identifier,
   kToken_literal_5F_enum,
   kToken_literal_5F_double,
   kToken_signed_5F_literal_5F_integer_5F_bigint,
   kToken__2D_,
   kToken__2E_,
   kToken__2E__3D_,
   kToken__2E__2E__2E_,
   kToken_literal_5F_char,
   kToken_string,
   kToken_comment,
   kToken_after,
   kToken_before,
   kToken_between,
   kToken_by,
   kToken_default,
   kToken_display,
   kToken_do,
   kToken_down,
   kToken_else,
   kToken_elsif,
   kToken_emptylist,
   kToken_emptymap,
   kToken_end,
   kToken_error,
   kToken_exists,
   kToken_false,
   kToken_for,
   kToken_foreach,
   kToken_from,
   kToken_func,
   kToken_here,
   kToken_if,
   kToken_in,
   kToken_import,
   kToken_listof,
   kToken_let,
   kToken_loop,
   kToken_mapof,
   kToken_mod,
   kToken_no,
   kToken_not,
   kToken_or,
   kToken_print,
   kToken_println,
   kToken_seed,
   kToken_repeat,
   kToken_sort,
   kToken_step,
   kToken_tab,
   kToken_template,
   kToken_then,
   kToken_to,
   kToken_true,
   kToken_typeof,
   kToken_up,
   kToken_yes,
   kToken_warning,
   kToken_while,
   kToken_write,
   kToken_executable,
   kToken_variables,
   kToken_getter,
   kToken_unlet,
   kToken_setter,
   kToken_libraries,
   kToken_input,
   kToken_break,
   kToken__5F__5F_VARS_5F__5F_,
   kToken__2A_,
   kToken__7C_,
   kToken__2C_,
   kToken__2B_,
   kToken__3A__3A_,
   kToken__3E_,
   kToken__3A_,
   kToken__28_,
   kToken__29_,
   kToken__2D__3E_,
   kToken__3F_,
   kToken__3D__3D_,
   kToken__21_,
   kToken__3A__3D_,
   kToken__5B_,
   kToken__5D_,
   kToken__2B__3D_,
   kToken__2D__3D_,
   kToken__2F_,
   kToken__21__3D_,
   kToken__3E__3D_,
   kToken__26_,
   kToken__3C__3D_,
   kToken__7B_,
   kToken__7D_,
   kToken__3C_,
   kToken__5E_,
   kToken__3E__3E_,
   kToken__7E_,
   kToken__3C__2D_,
   kToken__3C__3C_,
   kToken__40_,
   kToken__2A__3D_,
   kToken__2F__3D_,
   kToken__26__3D_,
   kToken__7C__3D_,
   kToken__3C__3C__3D_,
   kToken__3E__3E__3D_,
   kToken_mod_3D_,
   kToken__5E__3D_,
   kToken__40__5B_,
   kToken__40__28_,
   kToken__40__7B_,
   kToken__5B__21_,
   kToken__40__21_,
   kToken__40__3F_} ;

//--- Key words table 'goilTemplateKeyWordList'
  public: static int32_t search_into_goilTemplateKeyWordList (const C_String & inSearchedString) ;

//--- Key words table 'galgasDelimitorsList'
  public: static int32_t search_into_galgasDelimitorsList (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public: GALGAS_lstring synthetizedAttribute_a_5F_string (void) const ;
  public: GALGAS_lchar synthetizedAttribute_charValue (void) const ;
  public: GALGAS_ldouble synthetizedAttribute_floatValue (void) const ;
  public: GALGAS_lstring synthetizedAttribute_functionContent (void) const ;
  public: GALGAS_lstring synthetizedAttribute_identifierString (void) const ;
  public: GALGAS_lbigint synthetizedAttribute_intValue (void) const ;
  public: GALGAS_lstring synthetizedAttribute_tokenString (void) const ;
  public: GALGAS_luint synthetizedAttribute_uint_33__32_value (void) const ;


//--- Attribute access
  public: C_String attributeValue_a_5F_string (void) const ;
  public: utf32 attributeValue_charValue (void) const ;
  public: double attributeValue_floatValue (void) const ;
  public: C_String attributeValue_functionContent (void) const ;
  public: C_String attributeValue_identifierString (void) const ;
  public: C_BigInt attributeValue_intValue (void) const ;
  public: C_String attributeValue_tokenString (void) const ;
  public: uint32_t attributeValue_uint_33__32_value (void) const ;


//--- Indexing keys

//--- Parse lexical token
  protected: void internalParseLexicalToken (cTokenFor_gtl_5F_scanner & token) ;
  protected: virtual bool parseLexicalToken (void) override ;

//--- Get terminal message
  protected: virtual C_String getMessageForTerminal (const int32_t inTerminalSymbol) const override ;

//--- Get terminal count
  public: virtual int32_t terminalVocabularyCount (void) const override { return 115 ; }

//--- Get Token String
  public: virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const override ;

//--- Enter Token
  protected: void enterToken (cTokenFor_gtl_5F_scanner & ioToken) ;

//--- Style name for Latex
  protected: virtual C_String styleNameForIndex (const uint32_t inStyleIndex) const override ;
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const override ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Parser class 'gtl_expression_parser' declaration
//
//----------------------------------------------------------------------------------------------------------------------

class cParser_gtl_5F_expression_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_gtl_5F_expression_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_gtl_5F_argument_5F_list_ (class GALGAS_gtlArgumentList & outArgument0,
                                                       class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_argument_5F_list_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_argument_5F_list_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                 class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_factor_ (class GALGAS_gtlExpression & outArgument0,
                                             class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_factor_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_factor_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_factor_ (class GALGAS_gtlExpression & outArgument0,
                                                         class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_factor_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_factor_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_term_ (class GALGAS_gtlExpression & outArgument0,
                                                       class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_term_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_term_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                           class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_expression_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_expression_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_term_ (class GALGAS_gtlExpression & outArgument0,
                                           class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_term_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_term_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_ (class GALGAS_gtlVarPath & outArgument0,
                                               class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_5F_or_5F_here_ (class GALGAS_gtlVarPath & outArgument0,
                                                             class GALGAS_bool & outArgument1,
                                                             class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_5F_or_5F_here_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_5F_or_5F_here_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_ (GALGAS_gtlExpression & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_ (GALGAS_gtlExpression & outArgument0,
                                                                                C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_ (GALGAS_gtlExpression & outArgument0,
                                                                                  C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_ (GALGAS_gtlExpression & outArgument0,
                                                                                    C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_ (GALGAS_gtlExpression & outArgument0,
                                                                    C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_ (GALGAS_gtlExpression & outArgument0,
                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_ (GALGAS_gtlExpression & outArgument0,
                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_ (GALGAS_gtlExpression & outArgument0,
                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_ (GALGAS_gtlExpression & outArgument0,
                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_ (GALGAS_gtlExpression & outArgument0,
                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i32_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i32_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i32_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i33_ (GALGAS_gtlExpression & outArgument0,
                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i33_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i33_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i34_ (GALGAS_gtlVarPath & outArgument0,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i34_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i34_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i35_ (GALGAS_gtlVarPath & outArgument0,
                                                                                       GALGAS_bool & outArgument1,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i35_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i35_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i36_ (GALGAS_gtlArgumentList & outArgument0,
                                                                                 C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i36_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i36_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_gtl_5F_expression_5F_parser_0 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_1 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_2 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_3 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_4 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_5 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_6 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_7 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_8 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_9 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_10 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_11 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_12 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_13 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_14 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_15 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_16 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_17 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_18 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_19 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_20 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_21 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_22 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_23 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_24 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_25 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_26 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_expression_5F_parser_27 (C_Lexique_gtl_5F_scanner *) = 0 ;


} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Parser class 'gtl_instruction_parser' declaration
//
//----------------------------------------------------------------------------------------------------------------------

class cParser_gtl_5F_instruction_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_gtl_5F_instruction_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_gtl_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                 class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_import_ (class GALGAS_gtlContext inArgument0,
                                             class GALGAS_library & ioArgument1,
                                             class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_import_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_import_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                            class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_instruction_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_instruction_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_sorting_5F_order_ (class GALGAS_lsint & outArgument0,
                                                       class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_sorting_5F_order_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_sorting_5F_order_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_ (class GALGAS_gtlVarPath & outArgument0,
                                               class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_5F_or_5F_here_ (class GALGAS_gtlVarPath & outArgument0,
                                                             class GALGAS_bool & outArgument1,
                                                             class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_5F_or_5F_here_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_5F_or_5F_here_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument0,
                                                                                      C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument0,
                                                                                       C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_ (GALGAS_lsint & outArgument0,
                                                                                  C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_ (GALGAS_gtlContext inArgument0,
                                                                        GALGAS_library & ioArgument1,
                                                                        C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_gtl_5F_instruction_5F_parser_0 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_instruction_5F_parser_1 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_instruction_5F_parser_2 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_instruction_5F_parser_3 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_instruction_5F_parser_4 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_instruction_5F_parser_5 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_instruction_5F_parser_6 (C_Lexique_gtl_5F_scanner *) = 0 ;


} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Parser class 'gtl_parser' declaration
//
//----------------------------------------------------------------------------------------------------------------------

class cParser_gtl_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_gtl_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_gtl_5F_argument_5F_list_ (class GALGAS_gtlArgumentList & outArgument0,
                                                       class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_argument_5F_list_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_argument_5F_list_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                 class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_file_5F_name_ (class GALGAS_gtlExpression & outArgument0,
                                                   class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_file_5F_name_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_file_5F_name_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_import_ (class GALGAS_gtlContext inArgument0,
                                             class GALGAS_library & ioArgument1,
                                             class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_import_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_import_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                            class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_instruction_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_instruction_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_start_5F_symbol_ (class GALGAS_gtlContext inArgument0,
                                                      class GALGAS_library & ioArgument1,
                                                      class GALGAS_gtlInstructionList & outArgument2,
                                                      class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_start_5F_symbol_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_start_5F_symbol_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_template_5F_instruction_ (class GALGAS_gtlInstruction & outArgument0,
                                                              class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_template_5F_instruction_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_template_5F_instruction_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_template_5F_instruction_5F_list_ (class GALGAS_gtlInstructionList & outArgument0,
                                                                      class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_template_5F_instruction_5F_list_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_template_5F_instruction_5F_list_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_ (class GALGAS_gtlVarPath & outArgument0,
                                               class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_5F_or_5F_here_ (class GALGAS_gtlVarPath & outArgument0,
                                                             class GALGAS_bool & outArgument1,
                                                             class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_5F_or_5F_here_parse (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_5F_or_5F_here_indexing (class C_Lexique_gtl_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_ (GALGAS_gtlContext inArgument0,
                                                                 GALGAS_library & ioArgument1,
                                                                 GALGAS_gtlInstructionList & outArgument2,
                                                                 C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_ (GALGAS_gtlInstructionList & outArgument0,
                                                                                 C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument0,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument0,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument0,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument0,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument0,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument0,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument0,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument0,
                                                                         C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument0,
                                                                          C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_ (GALGAS_gtlExpression & outArgument0,
                                                               C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_parse (C_Lexique_gtl_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_indexing (C_Lexique_gtl_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_gtl_5F_parser_0 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_1 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_2 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_3 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_4 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_5 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_6 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_7 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_8 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_9 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_10 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_11 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_12 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_13 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_14 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_15 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_16 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_17 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_18 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_19 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_20 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_21 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_22 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_23 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_24 (C_Lexique_gtl_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_parser_25 (C_Lexique_gtl_5F_scanner *) = 0 ;


} ;

//----------------------------------------------------------------------------------------------------------------------
//  GRAMMAR gtl_grammar
//----------------------------------------------------------------------------------------------------------------------

class cGrammar_gtl_5F_grammar : public cParser_gtl_5F_parser,
                                public cParser_gtl_5F_expression_5F_parser,
                                public cParser_gtl_5F_instruction_5F_parser {
//------------------------------------- 'gtl_argument_list' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_argument_5F_list_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_argument_5F_list_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_argument_5F_list_ (GALGAS_gtlArgumentList & outArgument0,
                                                    C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_expression' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_expression_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_expression_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_expression_ (GALGAS_gtlExpression & outArgument0,
                                              C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_factor' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_factor_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_factor_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_factor_ (GALGAS_gtlExpression & outArgument0,
                                          C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_file_name' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_file_5F_name_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_file_5F_name_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_file_5F_name_ (GALGAS_gtlExpression & outArgument0,
                                                C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_import' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_import_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_import_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_import_ (GALGAS_gtlContext inArgument0,
                                          GALGAS_library & ioArgument1,
                                          C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_relation_factor' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_relation_5F_factor_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_relation_5F_factor_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_relation_5F_factor_ (GALGAS_gtlExpression & outArgument0,
                                                      C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_relation_term' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_relation_5F_term_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_relation_5F_term_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_relation_5F_term_ (GALGAS_gtlExpression & outArgument0,
                                                    C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_simple_expression' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_simple_5F_expression_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_simple_5F_expression_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_simple_5F_expression_ (GALGAS_gtlExpression & outArgument0,
                                                        C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_simple_instruction' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_simple_5F_instruction_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_simple_5F_instruction_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_simple_5F_instruction_ (GALGAS_gtlInstruction & outArgument0,
                                                         C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_sorting_order' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_sorting_5F_order_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_sorting_5F_order_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_sorting_5F_order_ (GALGAS_lsint & outArgument0,
                                                    C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_start_symbol' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_start_5F_symbol_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_start_5F_symbol_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_start_5F_symbol_ (GALGAS_gtlContext inArgument0,
                                                   GALGAS_library & ioArgument1,
                                                   GALGAS_gtlInstructionList & outArgument2,
                                                   C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_gtlContext inArgument0,
                                                  GALGAS_library & ioArgument1,
                                                  GALGAS_gtlInstructionList & outArgument2
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_gtlContext inArgument0,
                                                    GALGAS_library & ioArgument1,
                                                    GALGAS_gtlInstructionList & outArgument2
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (C_Compiler * inCompiler,
                                       const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                 const C_String & inSourceFilePath) ;

//------------------------------------- 'gtl_template_instruction' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_template_5F_instruction_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_template_5F_instruction_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_template_5F_instruction_ (GALGAS_gtlInstruction & outArgument0,
                                                           C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_template_instruction_list' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_template_5F_instruction_5F_list_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_template_5F_instruction_5F_list_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_template_5F_instruction_5F_list_ (GALGAS_gtlInstructionList & outArgument0,
                                                                   C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_term' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_term_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_term_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_term_ (GALGAS_gtlExpression & outArgument0,
                                        C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_variable' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_variable_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_variable_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_variable_ (GALGAS_gtlVarPath & outArgument0,
                                            C_Lexique_gtl_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_variable_or_here' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_variable_5F_or_5F_here_parse (C_Lexique_gtl_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_variable_5F_or_5F_here_indexing (C_Lexique_gtl_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_variable_5F_or_5F_here_ (GALGAS_gtlVarPath & outArgument0,
                                                          GALGAS_bool & outArgument1,
                                                          C_Lexique_gtl_5F_scanner * inCompiler) ;

  public: virtual int32_t select_gtl_5F_parser_0 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_1 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_2 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_3 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_4 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_5 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_6 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_7 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_8 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_9 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_10 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_11 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_12 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_13 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_14 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_15 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_16 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_17 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_18 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_19 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_20 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_21 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_22 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_23 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_24 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_parser_25 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_0 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_1 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_2 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_3 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_4 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_5 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_6 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_7 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_8 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_9 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_10 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_11 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_12 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_13 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_14 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_15 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_16 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_17 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_18 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_19 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_20 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_21 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_22 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_23 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_24 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_25 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_26 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_expression_5F_parser_27 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_0 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_1 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_2 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_3 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_4 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_5 (C_Lexique_gtl_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_instruction_5F_parser_6 (C_Lexique_gtl_5F_scanner *) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlFuncMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlFuncMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_gtlFunction mProperty_function ;
  public: inline GALGAS_gtlFunction readProperty_function (void) const {
    return mProperty_function ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlFuncMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_gtlFuncMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setFunction (const GALGAS_gtlFunction & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_function = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlFuncMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlFuncMap_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_gtlFunction & in_function) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlFuncMap_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlFuncMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                     const class GALGAS_gtlFunction & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlFuncMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlFuncMap_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlFuncMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlGetterMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlGetterMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_gtlGetter mProperty_theGetter ;
  public: inline GALGAS_gtlGetter readProperty_theGetter (void) const {
    return mProperty_theGetter ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlGetterMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setTheGetter (const GALGAS_gtlGetter & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_theGetter = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlGetterMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlGetterMap_2D_element (const GALGAS_lstring & in_lkey,
                                          const GALGAS_gtlGetter & in_theGetter) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlGetterMap_2D_element extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlGetterMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_gtlGetter & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlGetterMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlGetterMap_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGetterMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlSetterMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlSetterMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_gtlSetter mProperty_theSetter ;
  public: inline GALGAS_gtlSetter readProperty_theSetter (void) const {
    return mProperty_theSetter ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlSetterMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setTheSetter (const GALGAS_gtlSetter & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_theSetter = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlSetterMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlSetterMap_2D_element (const GALGAS_lstring & in_lkey,
                                          const GALGAS_gtlSetter & in_theSetter) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlSetterMap_2D_element extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlSetterMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_gtlSetter & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlSetterMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlSetterMap_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSetterMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVarItem  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVarItem : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlVarItem (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlVarItem * ptr (void) const {
    return (const cPtr_gtlVarItem *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlVarItem (const cPtr_gtlVarItem * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVarItem extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlVarItem & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlVarItem class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVarItem ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlVarItem class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlVarItem : public acPtr_class {

//--- Extension getter existsInContext
  public: virtual class GALGAS_bool getter_existsInContext (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter getInContext
  public: virtual class GALGAS_gtlData getter_getInContext (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter location
  public: virtual class GALGAS_location getter_location (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter stringPath
  public: virtual class GALGAS_string getter_stringPath (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (const class GALGAS_string concatString,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension method deleteInContext
  public: virtual void method_deleteInContext (const class GALGAS_gtlContext exeContext,
           class GALGAS_gtlData & context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) = 0 ;

//--- Extension method setInContext
  public: virtual void method_setInContext (const class GALGAS_gtlContext exeContext,
           class GALGAS_gtlData & context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           const class GALGAS_gtlData newData,
           C_Compiler * COMMA_LOCATION_ARGS) = 0 ;


//--- Properties

//--- Constructor
  public: cPtr_gtlVarItem (LOCATION_ARGS) ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlVarItem stringPath'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string callExtensionGetter_stringPath (const class cPtr_gtlVarItem * inObject,
                                                    const class GALGAS_gtlContext constin_exeContext,
                                                    const class GALGAS_gtlData constin_vars,
                                                    const class GALGAS_library constin_lib,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlVarItem location'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_location callExtensionGetter_location (const class cPtr_gtlVarItem * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlVarItem setInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_setInContext (class cPtr_gtlVarItem * inObject,
                                       const class GALGAS_gtlContext constin_exeContext,
                                       class GALGAS_gtlData & io_context,
                                       const class GALGAS_gtlData constin_vars,
                                       const class GALGAS_library constin_lib,
                                       const class GALGAS_gtlVarPath constin_path,
                                       const class GALGAS_gtlData constin_newData,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVarPath list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVarPath : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_gtlVarPath (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_gtlVarPath (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_gtlVarItem & in_item
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVarPath extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlVarPath constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_gtlVarPath constructor_listWithValue (const class GALGAS_gtlVarItem & inOperand0
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_gtlVarPath inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_gtlVarItem & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath add_operation (const GALGAS_gtlVarPath & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_gtlVarItem constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_gtlVarItem constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_gtlVarItem & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_gtlVarItem & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_gtlVarItem & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setItemAtIndex (class GALGAS_gtlVarItem constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_gtlVarItem & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_gtlVarItem & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlVarItem getter_itemAtIndex (const class GALGAS_uint & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlVarPath getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_gtlVarPath ;
 
} ; // End of GALGAS_gtlVarPath class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlVarPath : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlVarPath (const GALGAS_gtlVarPath & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_gtlVarItem current_item (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlVarPath_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVarPath ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlVarItem getInContext'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_getInContext (const class cPtr_gtlVarItem * inObject,
                                                       const class GALGAS_gtlContext constin_exeContext,
                                                       const class GALGAS_gtlData constin_context,
                                                       const class GALGAS_gtlData constin_vars,
                                                       const class GALGAS_library constin_lib,
                                                       const class GALGAS_gtlVarPath constin_path,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlVarItem existsInContext'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_existsInContext (const class cPtr_gtlVarItem * inObject,
                                                       const class GALGAS_gtlContext constin_exeContext,
                                                       const class GALGAS_gtlData constin_context,
                                                       const class GALGAS_gtlData constin_vars,
                                                       const class GALGAS_library constin_lib,
                                                       const class GALGAS_gtlVarPath constin_path,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlVarItem deleteInContext'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_deleteInContext (class cPtr_gtlVarItem * inObject,
                                          const class GALGAS_gtlContext constin_exeContext,
                                          class GALGAS_gtlData & io_context,
                                          const class GALGAS_gtlData constin_vars,
                                          const class GALGAS_library constin_lib,
                                          const class GALGAS_gtlVarPath constin_path,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVarPath_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVarPath_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_gtlVarItem mProperty_item ;
  public: inline GALGAS_gtlVarItem readProperty_item (void) const {
    return mProperty_item ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlVarPath_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setItem (const GALGAS_gtlVarItem & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_item = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlVarPath_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlVarPath_2D_element (const GALGAS_gtlVarItem & in_item) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVarPath_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlVarPath_2D_element constructor_new (const class GALGAS_gtlVarItem & inOperand0
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlVarPath_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlVarPath_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVarPath_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlVarPath pathAsFunctionName' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring extensionGetter_pathAsFunctionName (const class GALGAS_gtlVarPath & inObject,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVarItemField  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVarItemField : public GALGAS_gtlVarItem {
//--------------------------------- Default constructor
  public: GALGAS_gtlVarItemField (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlVarItemField constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlVarItemField * ptr (void) const {
    return (const cPtr_gtlVarItemField *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlVarItemField (const cPtr_gtlVarItemField * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_field (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVarItemField extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlVarItemField constructor_new (const class GALGAS_lstring & inOperand0
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlVarItemField & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setField (class GALGAS_lstring inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlVarItemField class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVarItemField ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlVarItemField class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlVarItemField : public cPtr_gtlVarItem {

//--- Extension getter existsInContext
  public: virtual class GALGAS_bool getter_existsInContext (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter getInContext
  public: virtual class GALGAS_gtlData getter_getInContext (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter location
  public: virtual class GALGAS_location getter_location (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstringPath
  public: virtual class GALGAS_lstring getter_lstringPath (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter stringPath
  public: virtual class GALGAS_string getter_stringPath (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (const class GALGAS_string concatString,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method deleteInContext
  public: virtual void method_deleteInContext (const class GALGAS_gtlContext exeContext,
           class GALGAS_gtlData & context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method setInContext
  public: virtual void method_setInContext (const class GALGAS_gtlContext exeContext,
           class GALGAS_gtlData & context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           const class GALGAS_gtlData newData,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_field ;

//--- Constructor
  public: cPtr_gtlVarItemField (const GALGAS_lstring & in_field
                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_field (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setField (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlVarPath stringPath' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string extensionGetter_stringPath (const class GALGAS_gtlVarPath & inObject,
                                                const class GALGAS_gtlContext & constinArgument0,
                                                const class GALGAS_gtlData & constinArgument1,
                                                const class GALGAS_library & constinArgument2,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVarPath set'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_set (const class GALGAS_gtlVarPath inObject,
                          const class GALGAS_gtlContext constin_exeContext,
                          class GALGAS_gtlData & io_vars,
                          const class GALGAS_library constin_lib,
                          const class GALGAS_gtlData constin_data,
                          class C_Compiler * inCompiler
                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlVarPath get' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData extensionGetter_get (const class GALGAS_gtlVarPath & inObject,
                                          const class GALGAS_gtlContext & constinArgument0,
                                          const class GALGAS_gtlData & constinArgument1,
                                          const class GALGAS_library & constinArgument2,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlVarPath exists' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool extensionGetter_exists (const class GALGAS_gtlVarPath & inObject,
                                          const class GALGAS_gtlContext & constinArgument0,
                                          const class GALGAS_gtlData & constinArgument1,
                                          const class GALGAS_library & constinArgument2,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVarPath delete'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_delete (const class GALGAS_gtlVarPath inObject,
                             const class GALGAS_gtlContext constin_exeContext,
                             class GALGAS_gtlData & io_vars,
                             const class GALGAS_library constin_lib,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlVarPath location' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_location extensionGetter_location (const class GALGAS_gtlVarPath & inObject,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlExpression : public acPtr_class {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension getter location
  public: virtual class GALGAS_location getter_location (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;


//--- Properties
  public: GALGAS_location mProperty_where ;

//--- Constructor
  public: cPtr_gtlExpression (const GALGAS_location & in_where
                              COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_location getter_where (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setWhere (GALGAS_location inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlExpressionList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlExpressionList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_gtlExpression mProperty_expression ;
  public: inline GALGAS_gtlExpression readProperty_expression (void) const {
    return mProperty_expression ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlExpressionList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setExpression (const GALGAS_gtlExpression & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_expression = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlExpressionList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlExpressionList_2D_element (const GALGAS_gtlExpression & in_expression) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlExpressionList_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlExpressionList_2D_element constructor_new (const class GALGAS_gtlExpression & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlExpressionList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlExpressionList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExpressionList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@string gtlType' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_type extensionGetter_gtlType (const class GALGAS_string & inObject,
                                           const class GALGAS_location & constinArgument0,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlBool  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlBool : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlBool (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlBool constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlBool * ptr (void) const {
    return (const cPtr_gtlBool *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlBool (const cPtr_gtlBool * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_bool readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlBool extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlBool constructor_new (const class GALGAS_location & inOperand0,
                                                       const class GALGAS_lstring & inOperand1,
                                                       const class GALGAS_bool & inOperand2
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlBool & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_bool inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlBool class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlBool ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlBool class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlBool : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_bool mProperty_value ;

//--- Constructor
  public: cPtr_gtlBool (const GALGAS_location & in_where,
                        const GALGAS_lstring & in_meta,
                        const GALGAS_bool & in_value
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlChar  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlChar : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlChar (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlChar constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlChar * ptr (void) const {
    return (const cPtr_gtlChar *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlChar (const cPtr_gtlChar * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_char readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlChar extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlChar constructor_new (const class GALGAS_location & inOperand0,
                                                       const class GALGAS_lstring & inOperand1,
                                                       const class GALGAS_char & inOperand2
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlChar & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_char inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlChar class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlChar ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlChar class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlChar : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_char mProperty_value ;

//--- Constructor
  public: cPtr_gtlChar (const GALGAS_location & in_where,
                        const GALGAS_lstring & in_meta,
                        const GALGAS_char & in_value
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_char getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_char inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlEnum  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlEnum : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlEnum (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlEnum constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlEnum * ptr (void) const {
    return (const cPtr_gtlEnum *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlEnum (const cPtr_gtlEnum * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_string readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlEnum extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlEnum constructor_new (const class GALGAS_location & inOperand0,
                                                       const class GALGAS_lstring & inOperand1,
                                                       const class GALGAS_string & inOperand2
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlEnum & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_string inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlEnum class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlEnum ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlEnum class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlEnum : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_string mProperty_value ;

//--- Constructor
  public: cPtr_gtlEnum (const GALGAS_location & in_where,
                        const GALGAS_lstring & in_meta,
                        const GALGAS_string & in_value
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlFloat  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlFloat : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlFloat (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlFloat constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlFloat * ptr (void) const {
    return (const cPtr_gtlFloat *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlFloat (const cPtr_gtlFloat * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_double readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlFloat extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlFloat constructor_new (const class GALGAS_location & inOperand0,
                                                        const class GALGAS_lstring & inOperand1,
                                                        const class GALGAS_double & inOperand2
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlFloat & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_double inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlFloat class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlFloat ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlFloat class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlFloat : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_double mProperty_value ;

//--- Constructor
  public: cPtr_gtlFloat (const GALGAS_location & in_where,
                         const GALGAS_lstring & in_meta,
                         const GALGAS_double & in_value
                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_double getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_double inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlInt  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlInt : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlInt (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlInt constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlInt * ptr (void) const {
    return (const cPtr_gtlInt *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlInt (const cPtr_gtlInt * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_bigint readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlInt extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlInt constructor_new (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_lstring & inOperand1,
                                                      const class GALGAS_bigint & inOperand2
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlInt & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_bigint inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlInt class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInt ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlInt class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlInt : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_bigint mProperty_value ;

//--- Constructor
  public: cPtr_gtlInt (const GALGAS_location & in_where,
                       const GALGAS_lstring & in_meta,
                       const GALGAS_bigint & in_value
                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_bigint getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_bigint inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlList  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlList : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlList (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlList constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlList * ptr (void) const {
    return (const cPtr_gtlList *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlList (const cPtr_gtlList * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_list readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlList extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlList constructor_new (const class GALGAS_location & inOperand0,
                                                       const class GALGAS_lstring & inOperand1,
                                                       const class GALGAS_list & inOperand2
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlList & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_list inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlList class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @list list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_list : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_list (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_list (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_gtlData & in_value
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_list extractObject (const GALGAS_object & inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_list constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_list constructor_listWithValue (const class GALGAS_gtlData & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_list inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_gtlData & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_list add_operation (const GALGAS_list & inOperand,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_gtlData constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_gtlData constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_gtlData & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_gtlData & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_gtlData & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValueAtIndex (class GALGAS_gtlData constinArgument0,
                                                        class GALGAS_uint constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_gtlData & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_gtlData & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_list getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_list getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_list getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlData getter_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_list ;
 
} ; // End of GALGAS_list class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_list : public cGenericAbstractEnumerator {
  public: cEnumerator_list (const GALGAS_list & inEnumeratedObject,
                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_gtlData current_value (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_list_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_list ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlList class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlList : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter hasItemAtIndex
  public: virtual class GALGAS_bool getter_hasItemAtIndex (const class GALGAS_gtlInt index,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method itemAtIndex
  public: virtual void method_itemAtIndex (class GALGAS_gtlData & result,
           const class GALGAS_gtlInt index,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_list mProperty_value ;

//--- Constructor
  public: cPtr_gtlList (const GALGAS_location & in_where,
                        const GALGAS_lstring & in_meta,
                        const GALGAS_list & in_value
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_list getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_list inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlMap  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlMap : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlMap (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlMap constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlMap * ptr (void) const {
    return (const cPtr_gtlMap *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlMap (const cPtr_gtlMap * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarMap readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlMap extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlMap constructor_new (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_lstring & inOperand1,
                                                      const class GALGAS_gtlVarMap & inOperand2
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlMap & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_gtlVarMap inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlMap class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlMap class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlMap : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter hasMapItem
  public: virtual class GALGAS_bool getter_hasMapItem (const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method mapItem
  public: virtual void method_mapItem (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlVarMap mProperty_value ;

//--- Constructor
  public: cPtr_gtlMap (const GALGAS_location & in_where,
                       const GALGAS_lstring & in_meta,
                       const GALGAS_gtlVarMap & in_value
                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarMap getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_gtlVarMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlSet  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlSet : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlSet (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlSet constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlSet * ptr (void) const {
    return (const cPtr_gtlSet *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlSet (const cPtr_gtlSet * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstringset readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlSet extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlSet constructor_new (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_lstring & inOperand1,
                                                      const class GALGAS_lstringset & inOperand2
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlSet & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_lstringset inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlSet class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSet ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @lstringset map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_lstringset ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_lstringset_get ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstringset : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_lstringset (void) ;

//--------------------------------- Handle copy
  public: GALGAS_lstringset (const GALGAS_lstringset & inSource) ;
  public: GALGAS_lstringset & operator = (const GALGAS_lstringset & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lstringset extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_lstringset constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_lstringset constructor_mapWithMapToOverride (const class GALGAS_lstringset & inOperand0
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_lstringset add_operation (const GALGAS_lstringset & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_del (class GALGAS_lstring constinArgument0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lstringset getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_lstringset * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_lstringset ;
 
} ; // End of GALGAS_lstringset class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_lstringset : public cGenericAbstractEnumerator {
  public: cEnumerator_lstringset (const GALGAS_lstringset & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_lstringset_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringset ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@lstringset' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_lstringset : public cMapElement {
//--- Map attributes

//--- Constructor
  public: cMapElement_lstringset (const GALGAS_lstring & inKey
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlSet class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlSet : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstringset mProperty_value ;

//--- Constructor
  public: cPtr_gtlSet (const GALGAS_location & in_where,
                       const GALGAS_lstring & in_meta,
                       const GALGAS_lstringset & in_value
                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstringset getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_lstringset inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlString  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlString : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlString (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlString constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlString * ptr (void) const {
    return (const cPtr_gtlString *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlString (const cPtr_gtlString * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_string readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlString extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlString constructor_new (const class GALGAS_location & inOperand0,
                                                         const class GALGAS_lstring & inOperand1,
                                                         const class GALGAS_string & inOperand2
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlString & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_string inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlString class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlString ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlString class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlString : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_string mProperty_value ;

//--- Constructor
  public: cPtr_gtlString (const GALGAS_location & in_where,
                          const GALGAS_lstring & in_meta,
                          const GALGAS_string & in_value
                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlStruct  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlStruct : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlStruct (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlStruct constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlStruct * ptr (void) const {
    return (const cPtr_gtlStruct *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlStruct (const cPtr_gtlStruct * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarMap readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlStruct extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlStruct constructor_new (const class GALGAS_location & inOperand0,
                                                         const class GALGAS_lstring & inOperand1,
                                                         const class GALGAS_gtlVarMap & inOperand2
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlStruct & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_gtlVarMap inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlStruct class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlStruct ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlStruct class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlStruct : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter hasStructField
  public: virtual class GALGAS_bool getter_hasStructField (const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter overriddenMap
  public: virtual class GALGAS_gtlStruct getter_overriddenMap (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter overrideMap
  public: virtual class GALGAS_gtlStruct getter_overrideMap (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter resultField
  public: virtual class GALGAS_gtlData getter_resultField (const class GALGAS_lstring name,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method structField
  public: virtual void method_structField (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           class GALGAS_bool & found,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlVarMap mProperty_value ;

//--- Constructor
  public: cPtr_gtlStruct (const GALGAS_location & in_where,
                          const GALGAS_lstring & in_meta,
                          const GALGAS_gtlVarMap & in_value
                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarMap getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_gtlVarMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlType  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlType : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlType (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlType * ptr (void) const {
    return (const cPtr_gtlType *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlType (const cPtr_gtlType * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_type readProperty_type (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlType extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlType constructor_new (const class GALGAS_location & inOperand0,
                                                       const class GALGAS_lstring & inOperand1,
                                                       const class GALGAS_type & inOperand2
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlType & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setType (class GALGAS_type inArgument0
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlType class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlType ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlType class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlType : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_type mProperty_type ;

//--- Constructor
  public: cPtr_gtlType (const GALGAS_location & in_where,
                        const GALGAS_lstring & in_meta,
                        const GALGAS_type & in_type
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_type getter_type (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setType (GALGAS_type inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlUnconstructed  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlUnconstructed : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlUnconstructed (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlUnconstructed constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlUnconstructed * ptr (void) const {
    return (const cPtr_gtlUnconstructed *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlUnconstructed (const cPtr_gtlUnconstructed * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlUnconstructed extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlUnconstructed constructor_new (const class GALGAS_location & inOperand0,
                                                                const class GALGAS_lstring & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlUnconstructed & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlUnconstructed class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlUnconstructed ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlUnconstructed class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlUnconstructed : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlUnconstructed (const GALGAS_location & in_where,
                                 const GALGAS_lstring & in_meta
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTypedArgumentList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_gtlTypedArgumentList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_gtlTypedArgumentList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_type & in_type
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTypedArgumentList extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTypedArgumentList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_gtlTypedArgumentList constructor_listWithValue (const class GALGAS_type & inOperand0
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_gtlTypedArgumentList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_type & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlTypedArgumentList add_operation (const GALGAS_gtlTypedArgumentList & inOperand,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_type constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_type constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_type & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_type & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_type & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTypeAtIndex (class GALGAS_type constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_type & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_type & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlTypedArgumentList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlTypedArgumentList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlTypedArgumentList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_type getter_typeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_gtlTypedArgumentList ;
 
} ; // End of GALGAS_gtlTypedArgumentList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlTypedArgumentList : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlTypedArgumentList (const GALGAS_gtlTypedArgumentList & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_type current_type (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlTypedArgumentList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTypedArgumentList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTypedArgumentList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypedArgumentList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_type mProperty_type ;
  public: inline GALGAS_type readProperty_type (void) const {
    return mProperty_type ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlTypedArgumentList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setType (const GALGAS_type & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_type = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlTypedArgumentList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlTypedArgumentList_2D_element (const GALGAS_type & in_type) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTypedArgumentList_2D_element extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTypedArgumentList_2D_element constructor_new (const class GALGAS_type & inOperand0
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlTypedArgumentList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlTypedArgumentList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTypedArgumentList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @list_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_list_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_gtlData mProperty_value ;
  public: inline GALGAS_gtlData readProperty_value (void) const {
    return mProperty_value ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_list_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setValue (const GALGAS_gtlData & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_value = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_list_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_list_2D_element (const GALGAS_gtlData & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_list_2D_element extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_list_2D_element constructor_new (const class GALGAS_gtlData & inOperand0
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_list_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_list_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_list_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @lstringset_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstringset_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_lstringset_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_lstringset_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lstringset_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lstringset_2D_element (const GALGAS_lstring & in_lkey) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lstringset_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_lstringset_2D_element constructor_new (const class GALGAS_lstring & inOperand0
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lstringset_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lstringset_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringset_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlArgumentList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlArgumentList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_bool mProperty_typed ;
  public: inline GALGAS_bool readProperty_typed (void) const {
    return mProperty_typed ;
  }

  public: GALGAS_type mProperty_type ;
  public: inline GALGAS_type readProperty_type (void) const {
    return mProperty_type ;
  }

  public: GALGAS_lstring mProperty_name ;
  public: inline GALGAS_lstring readProperty_name (void) const {
    return mProperty_name ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlArgumentList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setTyped (const GALGAS_bool & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_typed = inValue ;
  }

  public: inline void setter_setType (const GALGAS_type & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_type = inValue ;
  }

  public: inline void setter_setName (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_name = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlArgumentList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlArgumentList_2D_element (const GALGAS_bool & in_typed,
                                             const GALGAS_type & in_type,
                                             const GALGAS_lstring & in_name) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlArgumentList_2D_element extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlArgumentList_2D_element constructor_new (const class GALGAS_bool & inOperand0,
                                                                          const class GALGAS_type & inOperand1,
                                                                          const class GALGAS_lstring & inOperand2
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlArgumentList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlArgumentList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlArgumentList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlProcMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlProcMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_gtlProcMap_get ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlProcMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_gtlProcMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_gtlProcMap (const GALGAS_gtlProcMap & inSource) ;
  public: GALGAS_gtlProcMap & operator = (const GALGAS_gtlProcMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlProcMap extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlProcMap constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_gtlProcMap constructor_mapWithMapToOverride (const class GALGAS_gtlProcMap & inOperand0
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_gtlProcedure & inOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlProcMap add_operation (const GALGAS_gtlProcMap & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlProcedure constinArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setProcedureForKey (class GALGAS_gtlProcedure constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_gtlProcedure & outArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlProcMap getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlProcedure getter_procedureForKey (const class GALGAS_string & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_gtlProcedure & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_gtlProcMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_gtlProcMap ;
 
} ; // End of GALGAS_gtlProcMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlProcMap : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlProcMap (const GALGAS_gtlProcMap & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_gtlProcedure current_procedure (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlProcMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlProcMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlProcedure  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlProcedure : public GALGAS_gtlExecutableEntity {
//--------------------------------- Default constructor
  public: GALGAS_gtlProcedure (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlProcedure constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlProcedure * ptr (void) const {
    return (const cPtr_gtlProcedure *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlProcedure (const cPtr_gtlProcedure * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlProcedure extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlProcedure constructor_new (const class GALGAS_location & inOperand0,
                                                            const class GALGAS_lstring & inOperand1,
                                                            const class GALGAS_gtlArgumentList & inOperand2,
                                                            const class GALGAS_gtlInstructionList & inOperand3
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlProcedure & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlProcedure class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlProcedure ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@gtlProcMap' map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_gtlProcMap : public cMapElement {
//--- Map attributes
  public: GALGAS_gtlProcedure mProperty_procedure ;

//--- Constructor
  public: cMapElement_gtlProcMap (const GALGAS_lstring & inKey,
                                  const GALGAS_gtlProcedure & in_procedure
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlProcMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlProcMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_gtlProcedure mProperty_procedure ;
  public: inline GALGAS_gtlProcedure readProperty_procedure (void) const {
    return mProperty_procedure ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlProcMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_gtlProcMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setProcedure (const GALGAS_gtlProcedure & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_procedure = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlProcMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlProcMap_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_gtlProcedure & in_procedure) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlProcMap_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlProcMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                     const class GALGAS_gtlProcedure & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlProcMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlProcMap_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlProcMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlBinaryExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlBinaryExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlBinaryExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlBinaryExpression * ptr (void) const {
    return (const cPtr_gtlBinaryExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlBinaryExpression (const cPtr_gtlBinaryExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_lSon (void) const ;

  public: class GALGAS_gtlExpression readProperty_rSon (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlBinaryExpression extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlBinaryExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setLSon (class GALGAS_gtlExpression inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setRSon (class GALGAS_gtlExpression inArgument0
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlBinaryExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlBinaryExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlBinaryExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlBinaryExpression : public cPtr_gtlExpression {


//--- Properties
  public: GALGAS_gtlExpression mProperty_lSon ;
  public: GALGAS_gtlExpression mProperty_rSon ;

//--- Constructor
  public: cPtr_gtlBinaryExpression (const GALGAS_location & in_where,
                                    const GALGAS_gtlExpression & in_lSon,
                                    const GALGAS_gtlExpression & in_rSon
                                    COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_lSon (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLSon (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_rSon (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setRSon (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlAddExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlAddExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlAddExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlAddExpression * ptr (void) const {
    return (const cPtr_gtlAddExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlAddExpression (const cPtr_gtlAddExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlAddExpression extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlAddExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                const class GALGAS_gtlExpression & inOperand1,
                                                                const class GALGAS_gtlExpression & inOperand2
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlAddExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlAddExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlAddExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlAddExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlAddExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlAddExpression (const GALGAS_location & in_where,
                                 const GALGAS_gtlExpression & in_lSon,
                                 const GALGAS_gtlExpression & in_rSon
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlAllVarsRef  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlAllVarsRef : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlAllVarsRef (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlAllVarsRef constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlAllVarsRef * ptr (void) const {
    return (const cPtr_gtlAllVarsRef *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlAllVarsRef (const cPtr_gtlAllVarsRef * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlAllVarsRef extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlAllVarsRef constructor_new (const class GALGAS_location & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlAllVarsRef & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlAllVarsRef class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlAllVarsRef ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlAllVarsRef class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlAllVarsRef : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlAllVarsRef (const GALGAS_location & in_where
                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlAndExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlAndExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlAndExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlAndExpression * ptr (void) const {
    return (const cPtr_gtlAndExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlAndExpression (const cPtr_gtlAndExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlAndExpression extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlAndExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                const class GALGAS_gtlExpression & inOperand1,
                                                                const class GALGAS_gtlExpression & inOperand2
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlAndExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlAndExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlAndExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlAndExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlAndExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlAndExpression (const GALGAS_location & in_where,
                                 const GALGAS_gtlExpression & in_lSon,
                                 const GALGAS_gtlExpression & in_rSon
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlDivideExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlDivideExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlDivideExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlDivideExpression * ptr (void) const {
    return (const cPtr_gtlDivideExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlDivideExpression (const cPtr_gtlDivideExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlDivideExpression extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlDivideExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_gtlExpression & inOperand1,
                                                                   const class GALGAS_gtlExpression & inOperand2
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlDivideExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlDivideExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlDivideExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlDivideExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlDivideExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlDivideExpression (const GALGAS_location & in_where,
                                    const GALGAS_gtlExpression & in_lSon,
                                    const GALGAS_gtlExpression & in_rSon
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlEqualExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlEqualExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlEqualExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlEqualExpression * ptr (void) const {
    return (const cPtr_gtlEqualExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlEqualExpression (const cPtr_gtlEqualExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlEqualExpression extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlEqualExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                  const class GALGAS_gtlExpression & inOperand1,
                                                                  const class GALGAS_gtlExpression & inOperand2
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlEqualExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlEqualExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlEqualExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlEqualExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlEqualExpression (const GALGAS_location & in_where,
                                   const GALGAS_gtlExpression & in_lSon,
                                   const GALGAS_gtlExpression & in_rSon
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlExistsExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlExistsExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlExistsExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlExistsExpression constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlExistsExpression * ptr (void) const {
    return (const cPtr_gtlExistsExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlExistsExpression (const cPtr_gtlExistsExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_variable (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlExistsExpression extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlExistsExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_gtlVarPath & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlExistsExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setVariable (class GALGAS_gtlVarPath inArgument0
                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlExistsExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExistsExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlExistsExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlExistsExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_variable ;

//--- Constructor
  public: cPtr_gtlExistsExpression (const GALGAS_location & in_where,
                                    const GALGAS_gtlVarPath & in_variable
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_variable (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setVariable (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlExistsDefaultExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlExistsDefaultExpression : public GALGAS_gtlExistsExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlExistsDefaultExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlExistsDefaultExpression * ptr (void) const {
    return (const cPtr_gtlExistsDefaultExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlExistsDefaultExpression (const cPtr_gtlExistsDefaultExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_defaultValue (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlExistsDefaultExpression extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlExistsDefaultExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                          const class GALGAS_gtlVarPath & inOperand1,
                                                                          const class GALGAS_gtlExpression & inOperand2
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlExistsDefaultExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setDefaultValue (class GALGAS_gtlExpression inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlExistsDefaultExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExistsDefaultExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlExistsDefaultExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlExistsDefaultExpression : public cPtr_gtlExistsExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_defaultValue ;

//--- Constructor
  public: cPtr_gtlExistsDefaultExpression (const GALGAS_location & in_where,
                                           const GALGAS_gtlVarPath & in_variable,
                                           const GALGAS_gtlExpression & in_defaultValue
                                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_defaultValue (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDefaultValue (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlExpr  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlExpr : public GALGAS_gtlData {
//--------------------------------- Default constructor
  public: GALGAS_gtlExpr (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlExpr * ptr (void) const {
    return (const cPtr_gtlExpr *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlExpr (const cPtr_gtlExpr * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlExpr extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlExpr constructor_new (const class GALGAS_location & inOperand0,
                                                       const class GALGAS_lstring & inOperand1,
                                                       const class GALGAS_gtlExpression & inOperand2
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlExpr & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_gtlExpression inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlExpr class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlExpr ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlExpr class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlExpr : public cPtr_gtlData {

//--- Extension getter addOp
  public: virtual class GALGAS_gtlData getter_addOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter andOp
  public: virtual class GALGAS_gtlData getter_andOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter bool
  public: virtual class GALGAS_bool getter_bool (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter desc
  public: virtual class GALGAS_string getter_desc (const class GALGAS_uint tab,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter divOp
  public: virtual class GALGAS_gtlData getter_divOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter embeddedType
  public: virtual class GALGAS_type getter_embeddedType (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter eqOp
  public: virtual class GALGAS_gtlData getter_eqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter float
  public: virtual class GALGAS_double getter_float (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter geOp
  public: virtual class GALGAS_gtlData getter_geOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter gtOp
  public: virtual class GALGAS_gtlData getter_gtOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter int
  public: virtual class GALGAS_bigint getter_int (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter leOp
  public: virtual class GALGAS_gtlData getter_leOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter lstring
  public: virtual class GALGAS_lstring getter_lstring (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter ltOp
  public: virtual class GALGAS_gtlData getter_ltOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter minusOp
  public: virtual class GALGAS_gtlData getter_minusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter modOp
  public: virtual class GALGAS_gtlData getter_modOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mulOp
  public: virtual class GALGAS_gtlData getter_mulOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter neqOp
  public: virtual class GALGAS_gtlData getter_neqOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter notOp
  public: virtual class GALGAS_gtlData getter_notOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter orOp
  public: virtual class GALGAS_gtlData getter_orOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter performGetter
  public: virtual class GALGAS_gtlData getter_performGetter (const class GALGAS_lstring methodName,
           const class GALGAS_gtlDataList arguments,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter plusOp
  public: virtual class GALGAS_gtlData getter_plusOp (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter slOp
  public: virtual class GALGAS_gtlData getter_slOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter srOp
  public: virtual class GALGAS_gtlData getter_srOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter subOp
  public: virtual class GALGAS_gtlData getter_subOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter xorOp
  public: virtual class GALGAS_gtlData getter_xorOp (const class GALGAS_gtlData right,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method addMyValue
  public: virtual void method_addMyValue (class GALGAS_objectlist & objectList,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_value ;

//--- Constructor
  public: cPtr_gtlExpr (const GALGAS_location & in_where,
                        const GALGAS_lstring & in_meta,
                        const GALGAS_gtlExpression & in_value
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlFunctionCallExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlFunctionCallExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlFunctionCallExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlFunctionCallExpression constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlFunctionCallExpression * ptr (void) const {
    return (const cPtr_gtlFunctionCallExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlFunctionCallExpression (const cPtr_gtlFunctionCallExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_functionName (void) const ;

  public: class GALGAS_gtlExpressionList readProperty_functionArguments (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlFunctionCallExpression extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlFunctionCallExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                         const class GALGAS_lstring & inOperand1,
                                                                         const class GALGAS_gtlExpressionList & inOperand2
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlFunctionCallExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setFunctionArguments (class GALGAS_gtlExpressionList inArgument0
                                                             COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setFunctionName (class GALGAS_lstring inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlFunctionCallExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlFunctionCallExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlFunctionCallExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlFunctionCallExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_lstring mProperty_functionName ;
  public: GALGAS_gtlExpressionList mProperty_functionArguments ;

//--- Constructor
  public: cPtr_gtlFunctionCallExpression (const GALGAS_location & in_where,
                                          const GALGAS_lstring & in_functionName,
                                          const GALGAS_gtlExpressionList & in_functionArguments
                                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_functionName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFunctionName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_functionArguments (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFunctionArguments (GALGAS_gtlExpressionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlGetterCallExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlGetterCallExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlGetterCallExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlGetterCallExpression * ptr (void) const {
    return (const cPtr_gtlGetterCallExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlGetterCallExpression (const cPtr_gtlGetterCallExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_target (void) const ;

  public: class GALGAS_lstring readProperty_getterName (void) const ;

  public: class GALGAS_gtlExpressionList readProperty_arguments (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlGetterCallExpression extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlGetterCallExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_gtlExpression & inOperand1,
                                                                       const class GALGAS_lstring & inOperand2,
                                                                       const class GALGAS_gtlExpressionList & inOperand3
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlGetterCallExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setArguments (class GALGAS_gtlExpressionList inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setGetterName (class GALGAS_lstring inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTarget (class GALGAS_gtlExpression inArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlGetterCallExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGetterCallExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlGetterCallExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlGetterCallExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_target ;
  public: GALGAS_lstring mProperty_getterName ;
  public: GALGAS_gtlExpressionList mProperty_arguments ;

//--- Constructor
  public: cPtr_gtlGetterCallExpression (const GALGAS_location & in_where,
                                        const GALGAS_gtlExpression & in_target,
                                        const GALGAS_lstring & in_getterName,
                                        const GALGAS_gtlExpressionList & in_arguments
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_target (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTarget (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_getterName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setGetterName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_arguments (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setArguments (GALGAS_gtlExpressionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlGreaterOrEqualExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlGreaterOrEqualExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlGreaterOrEqualExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlGreaterOrEqualExpression * ptr (void) const {
    return (const cPtr_gtlGreaterOrEqualExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlGreaterOrEqualExpression (const cPtr_gtlGreaterOrEqualExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlGreaterOrEqualExpression extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlGreaterOrEqualExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                           const class GALGAS_gtlExpression & inOperand1,
                                                                           const class GALGAS_gtlExpression & inOperand2
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlGreaterOrEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlGreaterOrEqualExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlGreaterOrEqualExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlGreaterOrEqualExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlGreaterOrEqualExpression (const GALGAS_location & in_where,
                                            const GALGAS_gtlExpression & in_lSon,
                                            const GALGAS_gtlExpression & in_rSon
                                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlGreaterThanExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlGreaterThanExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlGreaterThanExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlGreaterThanExpression * ptr (void) const {
    return (const cPtr_gtlGreaterThanExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlGreaterThanExpression (const cPtr_gtlGreaterThanExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlGreaterThanExpression extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlGreaterThanExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                        const class GALGAS_gtlExpression & inOperand1,
                                                                        const class GALGAS_gtlExpression & inOperand2
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlGreaterThanExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlGreaterThanExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGreaterThanExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlGreaterThanExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlGreaterThanExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlGreaterThanExpression (const GALGAS_location & in_where,
                                         const GALGAS_gtlExpression & in_lSon,
                                         const GALGAS_gtlExpression & in_rSon
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlListOfExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlListOfExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlListOfExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlListOfExpression * ptr (void) const {
    return (const cPtr_gtlListOfExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlListOfExpression (const cPtr_gtlListOfExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_expression (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlListOfExpression extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlListOfExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_gtlExpression & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlListOfExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setExpression (class GALGAS_gtlExpression inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlListOfExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlListOfExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlListOfExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlListOfExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_expression ;

//--- Constructor
  public: cPtr_gtlListOfExpression (const GALGAS_location & in_where,
                                    const GALGAS_gtlExpression & in_expression
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_expression (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setExpression (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlLiteralListExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlLiteralListExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlLiteralListExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlLiteralListExpression constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlLiteralListExpression * ptr (void) const {
    return (const cPtr_gtlLiteralListExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlLiteralListExpression (const cPtr_gtlLiteralListExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpressionList readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlLiteralListExpression extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlLiteralListExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                        const class GALGAS_gtlExpressionList & inOperand1
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlLiteralListExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_gtlExpressionList inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlLiteralListExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLiteralListExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlLiteralListExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlLiteralListExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlExpressionList mProperty_value ;

//--- Constructor
  public: cPtr_gtlLiteralListExpression (const GALGAS_location & in_where,
                                         const GALGAS_gtlExpressionList & in_value
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_gtlExpressionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlLiteralMapExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlLiteralMapExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlLiteralMapExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlLiteralMapExpression constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlLiteralMapExpression * ptr (void) const {
    return (const cPtr_gtlLiteralMapExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlLiteralMapExpression (const cPtr_gtlLiteralMapExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpressionMap readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlLiteralMapExpression extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlLiteralMapExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_gtlExpressionMap & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlLiteralMapExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_gtlExpressionMap inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlLiteralMapExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLiteralMapExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlLiteralMapExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlLiteralMapExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlExpressionMap mProperty_value ;

//--- Constructor
  public: cPtr_gtlLiteralMapExpression (const GALGAS_location & in_where,
                                        const GALGAS_gtlExpressionMap & in_value
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionMap getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_gtlExpressionMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlLiteralSetExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlLiteralSetExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlLiteralSetExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlLiteralSetExpression constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlLiteralSetExpression * ptr (void) const {
    return (const cPtr_gtlLiteralSetExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlLiteralSetExpression (const cPtr_gtlLiteralSetExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpressionList readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlLiteralSetExpression extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlLiteralSetExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_gtlExpressionList & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlLiteralSetExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_gtlExpressionList inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlLiteralSetExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLiteralSetExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlLiteralSetExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlLiteralSetExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlExpressionList mProperty_value ;

//--- Constructor
  public: cPtr_gtlLiteralSetExpression (const GALGAS_location & in_where,
                                        const GALGAS_gtlExpressionList & in_value
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionList getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_gtlExpressionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlLiteralStructExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlLiteralStructExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlLiteralStructExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlLiteralStructExpression constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlLiteralStructExpression * ptr (void) const {
    return (const cPtr_gtlLiteralStructExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlLiteralStructExpression (const cPtr_gtlLiteralStructExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpressionMap readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlLiteralStructExpression extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlLiteralStructExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                          const class GALGAS_gtlExpressionMap & inOperand1
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlLiteralStructExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_gtlExpressionMap inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlLiteralStructExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLiteralStructExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlLiteralStructExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlLiteralStructExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlExpressionMap mProperty_value ;

//--- Constructor
  public: cPtr_gtlLiteralStructExpression (const GALGAS_location & in_where,
                                           const GALGAS_gtlExpressionMap & in_value
                                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpressionMap getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_gtlExpressionMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlLowerOrEqualExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlLowerOrEqualExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlLowerOrEqualExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlLowerOrEqualExpression * ptr (void) const {
    return (const cPtr_gtlLowerOrEqualExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlLowerOrEqualExpression (const cPtr_gtlLowerOrEqualExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlLowerOrEqualExpression extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlLowerOrEqualExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                         const class GALGAS_gtlExpression & inOperand1,
                                                                         const class GALGAS_gtlExpression & inOperand2
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlLowerOrEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlLowerOrEqualExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlLowerOrEqualExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlLowerOrEqualExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlLowerOrEqualExpression (const GALGAS_location & in_where,
                                          const GALGAS_gtlExpression & in_lSon,
                                          const GALGAS_gtlExpression & in_rSon
                                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlLowerThanExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlLowerThanExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlLowerThanExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlLowerThanExpression * ptr (void) const {
    return (const cPtr_gtlLowerThanExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlLowerThanExpression (const cPtr_gtlLowerThanExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlLowerThanExpression extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlLowerThanExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_gtlExpression & inOperand1,
                                                                      const class GALGAS_gtlExpression & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlLowerThanExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlLowerThanExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLowerThanExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlLowerThanExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlLowerThanExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlLowerThanExpression (const GALGAS_location & in_where,
                                       const GALGAS_gtlExpression & in_lSon,
                                       const GALGAS_gtlExpression & in_rSon
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlMapOfStructExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlMapOfStructExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlMapOfStructExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlMapOfStructExpression * ptr (void) const {
    return (const cPtr_gtlMapOfStructExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlMapOfStructExpression (const cPtr_gtlMapOfStructExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_expression (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlMapOfStructExpression extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlMapOfStructExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                        const class GALGAS_gtlExpression & inOperand1
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlMapOfStructExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setExpression (class GALGAS_gtlExpression inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlMapOfStructExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlMapOfStructExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlMapOfStructExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlMapOfStructExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_expression ;

//--- Constructor
  public: cPtr_gtlMapOfStructExpression (const GALGAS_location & in_where,
                                         const GALGAS_gtlExpression & in_expression
                                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_expression (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setExpression (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlMapOfListExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlMapOfListExpression : public GALGAS_gtlMapOfStructExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlMapOfListExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlMapOfListExpression * ptr (void) const {
    return (const cPtr_gtlMapOfListExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlMapOfListExpression (const cPtr_gtlMapOfListExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_key (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlMapOfListExpression extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlMapOfListExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_gtlExpression & inOperand1,
                                                                      const class GALGAS_lstring & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlMapOfListExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setKey (class GALGAS_lstring inArgument0
                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlMapOfListExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlMapOfListExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlMapOfListExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlMapOfListExpression : public cPtr_gtlMapOfStructExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_lstring mProperty_key ;

//--- Constructor
  public: cPtr_gtlMapOfListExpression (const GALGAS_location & in_where,
                                       const GALGAS_gtlExpression & in_expression,
                                       const GALGAS_lstring & in_key
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_key (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setKey (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlUnaryExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlUnaryExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlUnaryExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlUnaryExpression * ptr (void) const {
    return (const cPtr_gtlUnaryExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlUnaryExpression (const cPtr_gtlUnaryExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_son (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlUnaryExpression extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlUnaryExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setSon (class GALGAS_gtlExpression inArgument0
                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlUnaryExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlUnaryExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlUnaryExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlUnaryExpression : public cPtr_gtlExpression {


//--- Properties
  public: GALGAS_gtlExpression mProperty_son ;

//--- Constructor
  public: cPtr_gtlUnaryExpression (const GALGAS_location & in_where,
                                   const GALGAS_gtlExpression & in_son
                                   COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_son (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSon (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlMinusExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlMinusExpression : public GALGAS_gtlUnaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlMinusExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlMinusExpression * ptr (void) const {
    return (const cPtr_gtlMinusExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlMinusExpression (const cPtr_gtlMinusExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlMinusExpression extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlMinusExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                  const class GALGAS_gtlExpression & inOperand1
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlMinusExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlMinusExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlMinusExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlMinusExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlMinusExpression : public cPtr_gtlUnaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlMinusExpression (const GALGAS_location & in_where,
                                   const GALGAS_gtlExpression & in_son
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlModulusExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlModulusExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlModulusExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlModulusExpression * ptr (void) const {
    return (const cPtr_gtlModulusExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlModulusExpression (const cPtr_gtlModulusExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlModulusExpression extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlModulusExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                    const class GALGAS_gtlExpression & inOperand1,
                                                                    const class GALGAS_gtlExpression & inOperand2
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlModulusExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlModulusExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlModulusExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlModulusExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlModulusExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlModulusExpression (const GALGAS_location & in_where,
                                     const GALGAS_gtlExpression & in_lSon,
                                     const GALGAS_gtlExpression & in_rSon
                                     COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlMultiplyExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlMultiplyExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlMultiplyExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlMultiplyExpression * ptr (void) const {
    return (const cPtr_gtlMultiplyExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlMultiplyExpression (const cPtr_gtlMultiplyExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlMultiplyExpression extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlMultiplyExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                     const class GALGAS_gtlExpression & inOperand1,
                                                                     const class GALGAS_gtlExpression & inOperand2
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlMultiplyExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlMultiplyExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlMultiplyExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlMultiplyExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlMultiplyExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlMultiplyExpression (const GALGAS_location & in_where,
                                      const GALGAS_gtlExpression & in_lSon,
                                      const GALGAS_gtlExpression & in_rSon
                                      COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlNotEqualExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlNotEqualExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlNotEqualExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlNotEqualExpression * ptr (void) const {
    return (const cPtr_gtlNotEqualExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlNotEqualExpression (const cPtr_gtlNotEqualExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlNotEqualExpression extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlNotEqualExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                     const class GALGAS_gtlExpression & inOperand1,
                                                                     const class GALGAS_gtlExpression & inOperand2
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlNotEqualExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlNotEqualExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlNotEqualExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlNotEqualExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlNotEqualExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlNotEqualExpression (const GALGAS_location & in_where,
                                      const GALGAS_gtlExpression & in_lSon,
                                      const GALGAS_gtlExpression & in_rSon
                                      COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlNotExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlNotExpression : public GALGAS_gtlUnaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlNotExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlNotExpression * ptr (void) const {
    return (const cPtr_gtlNotExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlNotExpression (const cPtr_gtlNotExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlNotExpression extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlNotExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                const class GALGAS_gtlExpression & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlNotExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlNotExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlNotExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlNotExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlNotExpression : public cPtr_gtlUnaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlNotExpression (const GALGAS_location & in_where,
                                 const GALGAS_gtlExpression & in_son
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlOrExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlOrExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlOrExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlOrExpression * ptr (void) const {
    return (const cPtr_gtlOrExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlOrExpression (const cPtr_gtlOrExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlOrExpression extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlOrExpression constructor_new (const class GALGAS_location & inOperand0,
                                                               const class GALGAS_gtlExpression & inOperand1,
                                                               const class GALGAS_gtlExpression & inOperand2
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlOrExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlOrExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlOrExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlOrExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlOrExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlOrExpression (const GALGAS_location & in_where,
                                const GALGAS_gtlExpression & in_lSon,
                                const GALGAS_gtlExpression & in_rSon
                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlParenthesizedExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlParenthesizedExpression : public GALGAS_gtlUnaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlParenthesizedExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlParenthesizedExpression * ptr (void) const {
    return (const cPtr_gtlParenthesizedExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlParenthesizedExpression (const cPtr_gtlParenthesizedExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlParenthesizedExpression extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlParenthesizedExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                          const class GALGAS_gtlExpression & inOperand1
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlParenthesizedExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlParenthesizedExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlParenthesizedExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlParenthesizedExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlParenthesizedExpression : public cPtr_gtlUnaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlParenthesizedExpression (const GALGAS_location & in_where,
                                           const GALGAS_gtlExpression & in_son
                                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlPlusExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlPlusExpression : public GALGAS_gtlUnaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlPlusExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlPlusExpression * ptr (void) const {
    return (const cPtr_gtlPlusExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlPlusExpression (const cPtr_gtlPlusExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlPlusExpression extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlPlusExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                 const class GALGAS_gtlExpression & inOperand1
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlPlusExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlPlusExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlPlusExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlPlusExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlPlusExpression : public cPtr_gtlUnaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlPlusExpression (const GALGAS_location & in_where,
                                  const GALGAS_gtlExpression & in_son
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlShiftLeftExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlShiftLeftExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlShiftLeftExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlShiftLeftExpression * ptr (void) const {
    return (const cPtr_gtlShiftLeftExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlShiftLeftExpression (const cPtr_gtlShiftLeftExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlShiftLeftExpression extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlShiftLeftExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_gtlExpression & inOperand1,
                                                                      const class GALGAS_gtlExpression & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlShiftLeftExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlShiftLeftExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlShiftLeftExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlShiftLeftExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlShiftLeftExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlShiftLeftExpression (const GALGAS_location & in_where,
                                       const GALGAS_gtlExpression & in_lSon,
                                       const GALGAS_gtlExpression & in_rSon
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlShiftRightExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlShiftRightExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlShiftRightExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlShiftRightExpression * ptr (void) const {
    return (const cPtr_gtlShiftRightExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlShiftRightExpression (const cPtr_gtlShiftRightExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlShiftRightExpression extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlShiftRightExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_gtlExpression & inOperand1,
                                                                       const class GALGAS_gtlExpression & inOperand2
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlShiftRightExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlShiftRightExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlShiftRightExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlShiftRightExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlShiftRightExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlShiftRightExpression (const GALGAS_location & in_where,
                                        const GALGAS_gtlExpression & in_lSon,
                                        const GALGAS_gtlExpression & in_rSon
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlSubstractExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlSubstractExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlSubstractExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlSubstractExpression * ptr (void) const {
    return (const cPtr_gtlSubstractExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlSubstractExpression (const cPtr_gtlSubstractExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlSubstractExpression extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlSubstractExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_gtlExpression & inOperand1,
                                                                      const class GALGAS_gtlExpression & inOperand2
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlSubstractExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlSubstractExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSubstractExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlSubstractExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlSubstractExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlSubstractExpression (const GALGAS_location & in_where,
                                       const GALGAS_gtlExpression & in_lSon,
                                       const GALGAS_gtlExpression & in_rSon
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTerminal  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTerminal : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlTerminal (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlTerminal * ptr (void) const {
    return (const cPtr_gtlTerminal *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlTerminal (const cPtr_gtlTerminal * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlData readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTerminal extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTerminal constructor_new (const class GALGAS_location & inOperand0,
                                                           const class GALGAS_gtlData & inOperand1
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlTerminal & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_gtlData inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlTerminal class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTerminal ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlTerminal class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlTerminal : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlData mProperty_value ;

//--- Constructor
  public: cPtr_gtlTerminal (const GALGAS_location & in_where,
                            const GALGAS_gtlData & in_value
                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlData getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_gtlData inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTypeOfExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTypeOfExpression : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlTypeOfExpression (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlTypeOfExpression constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlTypeOfExpression * ptr (void) const {
    return (const cPtr_gtlTypeOfExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlTypeOfExpression (const cPtr_gtlTypeOfExpression * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_variable (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTypeOfExpression extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTypeOfExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_gtlVarPath & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlTypeOfExpression & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setVariable (class GALGAS_gtlVarPath inArgument0
                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlTypeOfExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTypeOfExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlTypeOfExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlTypeOfExpression : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_variable ;

//--- Constructor
  public: cPtr_gtlTypeOfExpression (const GALGAS_location & in_where,
                                    const GALGAS_gtlVarPath & in_variable
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_variable (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setVariable (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVarItemCollection  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVarItemCollection : public GALGAS_gtlVarItemField {
//--------------------------------- Default constructor
  public: GALGAS_gtlVarItemCollection (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlVarItemCollection * ptr (void) const {
    return (const cPtr_gtlVarItemCollection *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlVarItemCollection (const cPtr_gtlVarItemCollection * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlExpression readProperty_key (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVarItemCollection extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlVarItemCollection constructor_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_gtlExpression & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlVarItemCollection & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setKey (class GALGAS_gtlExpression inArgument0
                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlVarItemCollection class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVarItemCollection ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlVarItemCollection class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlVarItemCollection : public cPtr_gtlVarItemField {

//--- Extension getter existsInContext
  public: virtual class GALGAS_bool getter_existsInContext (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter getInContext
  public: virtual class GALGAS_gtlData getter_getInContext (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringPath
  public: virtual class GALGAS_string getter_stringPath (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (const class GALGAS_string concatString,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method deleteInContext
  public: virtual void method_deleteInContext (const class GALGAS_gtlContext exeContext,
           class GALGAS_gtlData & context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method setInContext
  public: virtual void method_setInContext (const class GALGAS_gtlContext exeContext,
           class GALGAS_gtlData & context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           const class GALGAS_gtlData newData,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlExpression mProperty_key ;

//--- Constructor
  public: cPtr_gtlVarItemCollection (const GALGAS_lstring & in_field,
                                     const GALGAS_gtlExpression & in_key
                                     COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_key (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setKey (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVarItemSubCollection  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVarItemSubCollection : public GALGAS_gtlVarItem {
//--------------------------------- Default constructor
  public: GALGAS_gtlVarItemSubCollection (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlVarItemSubCollection * ptr (void) const {
    return (const cPtr_gtlVarItemSubCollection *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlVarItemSubCollection (const cPtr_gtlVarItemSubCollection * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_location readProperty_subCollectionlocation (void) const ;

  public: class GALGAS_gtlExpression readProperty_key (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVarItemSubCollection extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlVarItemSubCollection constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_gtlExpression & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlVarItemSubCollection & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setKey (class GALGAS_gtlExpression inArgument0
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setSubCollectionlocation (class GALGAS_location inArgument0
                                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlVarItemSubCollection class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVarItemSubCollection ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlVarItemSubCollection class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlVarItemSubCollection : public cPtr_gtlVarItem {

//--- Extension getter existsInContext
  public: virtual class GALGAS_bool getter_existsInContext (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter getInContext
  public: virtual class GALGAS_gtlData getter_getInContext (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter location
  public: virtual class GALGAS_location getter_location (C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringPath
  public: virtual class GALGAS_string getter_stringPath (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (const class GALGAS_string concatString,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method deleteInContext
  public: virtual void method_deleteInContext (const class GALGAS_gtlContext exeContext,
           class GALGAS_gtlData & context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method setInContext
  public: virtual void method_setInContext (const class GALGAS_gtlContext exeContext,
           class GALGAS_gtlData & context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           const class GALGAS_gtlVarPath path,
           const class GALGAS_gtlData newData,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_location mProperty_subCollectionlocation ;
  public: GALGAS_gtlExpression mProperty_key ;

//--- Constructor
  public: cPtr_gtlVarItemSubCollection (const GALGAS_location & in_subCollectionlocation,
                                        const GALGAS_gtlExpression & in_key
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_location getter_subCollectionlocation (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSubCollectionlocation (GALGAS_location inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlExpression getter_key (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setKey (GALGAS_gtlExpression inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVarRef  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVarRef : public GALGAS_gtlExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlVarRef (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlVarRef constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlVarRef * ptr (void) const {
    return (const cPtr_gtlVarRef *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlVarRef (const cPtr_gtlVarRef * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_variableName (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVarRef extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlVarRef constructor_new (const class GALGAS_location & inOperand0,
                                                         const class GALGAS_gtlVarPath & inOperand1
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlVarRef & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setVariableName (class GALGAS_gtlVarPath inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlVarRef class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVarRef ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlVarRef class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlVarRef : public cPtr_gtlExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_variableName ;

//--- Constructor
  public: cPtr_gtlVarRef (const GALGAS_location & in_where,
                          const GALGAS_gtlVarPath & in_variableName
                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_variableName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setVariableName (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlXorExpression  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlXorExpression : public GALGAS_gtlBinaryExpression {
//--------------------------------- Default constructor
  public: GALGAS_gtlXorExpression (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlXorExpression * ptr (void) const {
    return (const cPtr_gtlXorExpression *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlXorExpression (const cPtr_gtlXorExpression * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlXorExpression extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlXorExpression constructor_new (const class GALGAS_location & inOperand0,
                                                                const class GALGAS_gtlExpression & inOperand1,
                                                                const class GALGAS_gtlExpression & inOperand2
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlXorExpression & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlXorExpression class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlXorExpression ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlXorExpression class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlXorExpression : public cPtr_gtlBinaryExpression {

//--- Extension getter eval
  public: virtual class GALGAS_gtlData getter_eval (const class GALGAS_gtlContext context,
           const class GALGAS_gtlData vars,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter stringRepresentation
  public: virtual class GALGAS_string getter_stringRepresentation (C_Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlXorExpression (const GALGAS_location & in_where,
                                 const GALGAS_gtlExpression & in_lSon,
                                 const GALGAS_gtlExpression & in_rSon
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptylstring'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring function_emptylstring (class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@lstring gtlType' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_type extensionGetter_gtlType (const class GALGAS_lstring & inObject,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;


//----------------------------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

extern C_BoolCommandLineOption gOption_gtl_5F_options_debug ;

extern C_BoolCommandLineOption gOption_gtl_5F_options_warnDeprecated ;

//----------------------------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlInstruction location'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_location callExtensionGetter_location (const cPtr_gtlInstruction * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlInstruction execute'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_execute (class cPtr_gtlInstruction * inObject,
                                  class GALGAS_gtlContext & io_context,
                                  class GALGAS_gtlData & io_vars,
                                  class GALGAS_library & io_lib,
                                  class GALGAS_string & io_outputString,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlInstructionList execute'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_execute (const class GALGAS_gtlInstructionList inObject,
                              class GALGAS_gtlContext & io_context,
                              class GALGAS_gtlData & io_vars,
                              class GALGAS_library & io_lib,
                              class GALGAS_string & io_outputString,
                              class C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlStepInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlStepInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlStepInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlStepInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlStepInstruction * ptr (void) const {
    return (const cPtr_gtlStepInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlStepInstruction (const cPtr_gtlStepInstruction * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlStepInstruction extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlStepInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                  const class GALGAS_string & inOperand1
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlStepInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlStepInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlStepInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlStepInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlStepInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlStepInstruction (const GALGAS_location & in_where,
                                   const GALGAS_string & in_signature
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'endc'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string function_endc (class C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext breakOn'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_breakOn (const cPtr_gtlContext * inObject,
                                               class GALGAS_gtlInstruction in_instruction,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext breakOnNext'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_breakOnNext (const cPtr_gtlContext * inObject,
                                                   class C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext debugActive'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_debugActive (const cPtr_gtlContext * inObject,
                                                   class C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext loopOnCommand'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_loopOnCommand (const cPtr_gtlContext * inObject,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext outputStyle'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string callExtensionGetter_outputStyle (const cPtr_gtlContext * inObject,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext promptStyle'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string callExtensionGetter_promptStyle (const cPtr_gtlContext * inObject,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext watchOn'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_watchOn (const cPtr_gtlContext * inObject,
                                               const class GALGAS_gtlContext constin_context,
                                               const class GALGAS_gtlData constin_vars,
                                               const class GALGAS_library constin_lib,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlInstruction mayExecuteWithoutError'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_mayExecuteWithoutError (const cPtr_gtlInstruction * inObject,
                                                              const class GALGAS_gtlContext constin_exeContext,
                                                              const class GALGAS_gtlData constin_context,
                                                              const class GALGAS_library constin_lib,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//LEXIQUE gtl_5F_debugger_5F_scanner
//
//----------------------------------------------------------------------------------------------------------------------

#include "galgas2/C_Lexique.h"

//----------------------------------------------------------------------------------------------------------------------
//                    E X T E R N    R O U T I N E S
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//                    E X T E R N    F U N C T I O N S
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//                       T O K E N    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class cTokenFor_gtl_5F_debugger_5F_scanner : public cToken {
  public: C_String mLexicalAttribute_a_5F_string ;
  public: utf32 mLexicalAttribute_charValue ;
  public: double mLexicalAttribute_floatValue ;
  public: C_String mLexicalAttribute_functionContent ;
  public: C_String mLexicalAttribute_identifierString ;
  public: C_BigInt mLexicalAttribute_intValue ;
  public: C_String mLexicalAttribute_tokenString ;
  public: uint32_t mLexicalAttribute_uint_33__32_value ;

  public: cTokenFor_gtl_5F_debugger_5F_scanner (void) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//----------------------------------------------------------------------------------------------------------------------

class C_Lexique_gtl_5F_debugger_5F_scanner : public C_Lexique {
//--- Constructors
  public: C_Lexique_gtl_5F_debugger_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public: C_Lexique_gtl_5F_debugger_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public: static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected: virtual ~ C_Lexique_gtl_5F_debugger_5F_scanner (void) {}
  #endif



//--- Terminal symbols enumeration
  public: enum {kToken_,
   kToken_identifier,
   kToken_literal_5F_enum,
   kToken_literal_5F_double,
   kToken_signed_5F_literal_5F_integer_5F_bigint,
   kToken__2D_,
   kToken__2E_,
   kToken__2E__3D_,
   kToken__2E__2E__2E_,
   kToken_literal_5F_char,
   kToken_string,
   kToken_comment,
   kToken_default,
   kToken_display,
   kToken_do,
   kToken_emptylist,
   kToken_emptymap,
   kToken_exists,
   kToken_false,
   kToken_list,
   kToken_import,
   kToken_listof,
   kToken_let,
   kToken_mapof,
   kToken_mod,
   kToken_no,
   kToken_not,
   kToken_or,
   kToken_print,
   kToken_sort,
   kToken_step,
   kToken_true,
   kToken_typeof,
   kToken_yes,
   kToken_variables,
   kToken_unlet,
   kToken_libraries,
   kToken_break,
   kToken_watch,
   kToken_by,
   kToken_end,
   kToken_cont,
   kToken_continue,
   kToken_help,
   kToken_if,
   kToken_then,
   kToken_else,
   kToken_elsif,
   kToken_hist,
   kToken_all,
   kToken_load,
   kToken__2A_,
   kToken__7C_,
   kToken__2C_,
   kToken__2B_,
   kToken__3A__3A_,
   kToken__3E_,
   kToken__3A_,
   kToken__28_,
   kToken__29_,
   kToken__2D__3E_,
   kToken__3F_,
   kToken__3D__3D_,
   kToken__21_,
   kToken__3A__3D_,
   kToken__5B_,
   kToken__5D_,
   kToken__2B__3D_,
   kToken__2D__3D_,
   kToken__2F_,
   kToken__21__3D_,
   kToken__3E__3D_,
   kToken__26_,
   kToken__3C__3D_,
   kToken__7B_,
   kToken__7D_,
   kToken__3C_,
   kToken__5E_,
   kToken__3E__3E_,
   kToken__7E_,
   kToken__3C__2D_,
   kToken__3C__3C_,
   kToken__40_,
   kToken__2A__3D_,
   kToken__2F__3D_,
   kToken__26__3D_,
   kToken__7C__3D_,
   kToken__3C__3C__3D_,
   kToken__3E__3E__3D_,
   kToken_mod_3D_,
   kToken__5E__3D_,
   kToken__40__5B_,
   kToken__40__28_,
   kToken__40__7B_,
   kToken__5B__21_,
   kToken__40__21_} ;

//--- Key words table 'goilTemplateKeyWordList'
  public: static int32_t search_into_goilTemplateKeyWordList (const C_String & inSearchedString) ;

//--- Key words table 'galgasDelimitorsList'
  public: static int32_t search_into_galgasDelimitorsList (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public: GALGAS_lstring synthetizedAttribute_a_5F_string (void) const ;
  public: GALGAS_lchar synthetizedAttribute_charValue (void) const ;
  public: GALGAS_ldouble synthetizedAttribute_floatValue (void) const ;
  public: GALGAS_lstring synthetizedAttribute_functionContent (void) const ;
  public: GALGAS_lstring synthetizedAttribute_identifierString (void) const ;
  public: GALGAS_lbigint synthetizedAttribute_intValue (void) const ;
  public: GALGAS_lstring synthetizedAttribute_tokenString (void) const ;
  public: GALGAS_luint synthetizedAttribute_uint_33__32_value (void) const ;


//--- Attribute access
  public: C_String attributeValue_a_5F_string (void) const ;
  public: utf32 attributeValue_charValue (void) const ;
  public: double attributeValue_floatValue (void) const ;
  public: C_String attributeValue_functionContent (void) const ;
  public: C_String attributeValue_identifierString (void) const ;
  public: C_BigInt attributeValue_intValue (void) const ;
  public: C_String attributeValue_tokenString (void) const ;
  public: uint32_t attributeValue_uint_33__32_value (void) const ;


//--- Indexing keys

//--- Parse lexical token
  protected: void internalParseLexicalToken (cTokenFor_gtl_5F_debugger_5F_scanner & token) ;
  protected: virtual bool parseLexicalToken (void) override ;

//--- Get terminal message
  protected: virtual C_String getMessageForTerminal (const int32_t inTerminalSymbol) const override ;

//--- Get terminal count
  public: virtual int32_t terminalVocabularyCount (void) const override { return 95 ; }

//--- Get Token String
  public: virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const override ;

//--- Enter Token
  protected: void enterToken (cTokenFor_gtl_5F_debugger_5F_scanner & ioToken) ;

//--- Style name for Latex
  protected: virtual C_String styleNameForIndex (const uint32_t inStyleIndex) const override ;
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const override ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Parser class 'gtl_debugger_expression_parser' declaration
//
//----------------------------------------------------------------------------------------------------------------------

class cParser_gtl_5F_debugger_5F_expression_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_gtl_5F_debugger_5F_expression_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_gtl_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                 class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_factor_ (class GALGAS_gtlExpression & outArgument0,
                                             class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_factor_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_factor_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_factor_ (class GALGAS_gtlExpression & outArgument0,
                                                         class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_factor_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_factor_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_term_ (class GALGAS_gtlExpression & outArgument0,
                                                       class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_term_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_relation_5F_term_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                           class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_expression_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_simple_5F_expression_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_term_ (class GALGAS_gtlExpression & outArgument0,
                                           class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_term_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_term_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_ (class GALGAS_gtlVarPath & outArgument0,
                                               class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_expression_i0_ (GALGAS_gtlExpression & outArgument0,
                                                                                      C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_expression_i0_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_expression_i0_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_ (GALGAS_gtlExpression & outArgument0,
                                                                                            C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_ (GALGAS_gtlExpression & outArgument0,
                                                                                              C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_ (GALGAS_gtlExpression & outArgument0,
                                                                                                C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_term_i4_ (GALGAS_gtlExpression & outArgument0,
                                                                                C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_term_i4_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_term_i4_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i5_ (GALGAS_gtlExpression & outArgument0,
                                                                                  C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i5_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i5_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i6_ (GALGAS_gtlExpression & outArgument0,
                                                                                  C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i6_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i6_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i7_ (GALGAS_gtlExpression & outArgument0,
                                                                                  C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i7_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i7_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i8_ (GALGAS_gtlExpression & outArgument0,
                                                                                  C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i8_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i8_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i9_ (GALGAS_gtlExpression & outArgument0,
                                                                                  C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i9_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i9_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i10_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i10_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i10_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i11_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i11_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i11_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i12_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i12_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i12_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i13_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i13_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i13_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i14_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i14_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i14_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i15_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i15_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i15_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i16_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i16_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i16_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i17_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i17_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i17_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i18_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i18_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i18_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i19_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i19_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i19_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i20_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i20_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i20_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i21_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i21_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i21_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i22_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i22_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i22_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i23_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i23_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i23_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i24_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i24_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i24_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i25_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i25_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i25_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i26_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i26_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i26_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i27_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i27_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i27_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i28_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i28_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i28_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i29_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i29_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i29_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i30_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i30_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i30_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i31_ (GALGAS_gtlExpression & outArgument0,
                                                                                   C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i31_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_factor_i31_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_variable_i32_ (GALGAS_gtlVarPath & outArgument0,
                                                                                     C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_variable_i32_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_expression_5F_parser_gtl_5F_variable_i32_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_0 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_1 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_2 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_3 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_4 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_5 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_6 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_7 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_8 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_9 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_10 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_11 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_12 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_13 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_14 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_15 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_16 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_17 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_18 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_19 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_20 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_21 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_22 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_23 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;


} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Parser class 'gtl_debugger_parser' declaration
//
//----------------------------------------------------------------------------------------------------------------------

class cParser_gtl_5F_debugger_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_gtl_5F_debugger_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_gtl_5F_debugger_5F_command_ (class GALGAS_gtlInstruction & outArgument0,
                                                          class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_debugger_5F_command_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_debugger_5F_command_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_ (class GALGAS_gtlExpression & outArgument0,
                                                 class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_expression_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_step_5F_do_5F_command_ (class GALGAS_gtlInstruction & outArgument0,
                                                            class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_step_5F_do_5F_command_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_step_5F_do_5F_command_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_step_5F_do_5F_command_5F_list_ (class GALGAS_gtlInstructionList & outArgument0,
                                                                    class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_step_5F_do_5F_command_5F_list_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_step_5F_do_5F_command_5F_list_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_ (class GALGAS_gtlVarPath & outArgument0,
                                               class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_parse (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_gtl_5F_variable_indexing (class C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i0_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i1_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i2_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i3_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i4_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i5_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i6_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i7_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i8_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i8_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i8_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i9_ (GALGAS_gtlInstruction & outArgument0,
                                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i9_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i9_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i10_ (GALGAS_gtlInstruction & outArgument0,
                                                                                  C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i10_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i10_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i11_ (GALGAS_gtlInstruction & outArgument0,
                                                                                  C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i11_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_debugger_5F_command_i11_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i12_ (GALGAS_gtlInstruction & outArgument0,
                                                                                    C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i12_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i12_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i13_ (GALGAS_gtlInstruction & outArgument0,
                                                                                    C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i13_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i13_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i14_ (GALGAS_gtlInstruction & outArgument0,
                                                                                    C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i14_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i14_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i15_ (GALGAS_gtlInstruction & outArgument0,
                                                                                    C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i15_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i15_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i16_ (GALGAS_gtlInstruction & outArgument0,
                                                                                    C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i16_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_i16_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_5F_list_i17_ (GALGAS_gtlInstructionList & outArgument0,
                                                                                            C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_5F_list_i17_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;

  protected: void rule_gtl_5F_debugger_5F_parser_gtl_5F_step_5F_do_5F_command_5F_list_i17_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_0 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_1 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_2 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_3 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_4 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_5 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_6 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_7 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_8 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_9 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_10 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_11 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_12 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;

  protected: virtual int32_t select_gtl_5F_debugger_5F_parser_13 (C_Lexique_gtl_5F_debugger_5F_scanner *) = 0 ;


} ;

//----------------------------------------------------------------------------------------------------------------------
//  GRAMMAR gtl_debugger_grammar
//----------------------------------------------------------------------------------------------------------------------

class cGrammar_gtl_5F_debugger_5F_grammar : public cParser_gtl_5F_debugger_5F_parser,
                                            public cParser_gtl_5F_debugger_5F_expression_5F_parser {
//------------------------------------- 'gtl_debugger_command' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_debugger_5F_command_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_debugger_5F_command_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_debugger_5F_command_ (GALGAS_gtlInstruction & outArgument0,
                                                       C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_gtlInstruction & outArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_gtlInstruction & outArgument0
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (C_Compiler * inCompiler,
                                       const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                 const C_String & inSourceFilePath) ;

//------------------------------------- 'gtl_expression' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_expression_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_expression_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_expression_ (GALGAS_gtlExpression & outArgument0,
                                              C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_factor' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_factor_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_factor_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_factor_ (GALGAS_gtlExpression & outArgument0,
                                          C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_relation_factor' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_relation_5F_factor_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_relation_5F_factor_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_relation_5F_factor_ (GALGAS_gtlExpression & outArgument0,
                                                      C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_relation_term' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_relation_5F_term_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_relation_5F_term_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_relation_5F_term_ (GALGAS_gtlExpression & outArgument0,
                                                    C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_simple_expression' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_simple_5F_expression_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_simple_5F_expression_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_simple_5F_expression_ (GALGAS_gtlExpression & outArgument0,
                                                        C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_step_do_command' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_step_5F_do_5F_command_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_step_5F_do_5F_command_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_step_5F_do_5F_command_ (GALGAS_gtlInstruction & outArgument0,
                                                         C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_step_do_command_list' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_step_5F_do_5F_command_5F_list_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_step_5F_do_5F_command_5F_list_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_step_5F_do_5F_command_5F_list_ (GALGAS_gtlInstructionList & outArgument0,
                                                                 C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_term' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_term_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_term_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_term_ (GALGAS_gtlExpression & outArgument0,
                                        C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//------------------------------------- 'gtl_variable' non terminal
//--- 'parse' label
  public: virtual void nt_gtl_5F_variable_parse (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//--- indexing
  public: virtual void nt_gtl_5F_variable_indexing (C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

//----------- '' label
  public: virtual void nt_gtl_5F_variable_ (GALGAS_gtlVarPath & outArgument0,
                                            C_Lexique_gtl_5F_debugger_5F_scanner * inCompiler) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_0 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_1 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_2 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_3 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_4 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_5 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_6 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_7 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_8 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_9 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_10 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_11 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_12 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_parser_13 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_0 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_1 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_2 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_3 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_4 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_5 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_6 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_7 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_8 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_9 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_10 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_11 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_12 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_13 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_14 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_15 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_16 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_17 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_18 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_19 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_20 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_21 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_22 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;

  public: virtual int32_t select_gtl_5F_debugger_5F_expression_5F_parser_23 (C_Lexique_gtl_5F_debugger_5F_scanner *) ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext executeStepDoList'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_executeStepDoList) (class cPtr_gtlContext * inObject,
                                                                       class GALGAS_gtlContext & ioArgument0,
                                                                       class GALGAS_gtlData & ioArgument1,
                                                                       class GALGAS_library & ioArgument2,
                                                                       class GALGAS_string & ioArgument3,
                                                                       class C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_executeStepDoList (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlContext_executeStepDoList inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_executeStepDoList (class cPtr_gtlContext * inObject,
                                            GALGAS_gtlContext & io_context,
                                            GALGAS_gtlData & io_vars,
                                            GALGAS_library & io_lib,
                                            GALGAS_string & io_outputString,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext getCommand'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_getCommand) (class cPtr_gtlContext * inObject,
                                                                class GALGAS_string & outArgument0,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_getCommand (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlContext_getCommand inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_getCommand (class cPtr_gtlContext * inObject,
                                     GALGAS_string & out_command,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext popInstructionList'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_popInstructionList) (class cPtr_gtlContext * inObject,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_popInstructionList (const int32_t inClassIndex,
                                              extensionSetterSignature_gtlContext_popInstructionList inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_popInstructionList (class cPtr_gtlContext * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext pushInstructionList'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_pushInstructionList) (class cPtr_gtlContext * inObject,
                                                                         const class GALGAS_gtlInstructionList constinArgument0,
                                                                         class C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_pushInstructionList (const int32_t inClassIndex,
                                               extensionSetterSignature_gtlContext_pushInstructionList inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_pushInstructionList (class cPtr_gtlContext * inObject,
                                              const GALGAS_gtlInstructionList constin_instructionList,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext setBreakOnNext'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_setBreakOnNext) (class cPtr_gtlContext * inObject,
                                                                    class GALGAS_bool inArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setBreakOnNext (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlContext_setBreakOnNext inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setBreakOnNext (class cPtr_gtlContext * inObject,
                                         GALGAS_bool in_break,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext setDebugger'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_setDebugger) (class cPtr_gtlContext * inObject,
                                                                 class GALGAS_bool inArgument0,
                                                                 class C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setDebugger (const int32_t inClassIndex,
                                       extensionSetterSignature_gtlContext_setDebugger inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setDebugger (class cPtr_gtlContext * inObject,
                                      GALGAS_bool in_debugOn,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext setLoopOnCommand'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_setLoopOnCommand) (class cPtr_gtlContext * inObject,
                                                                      class GALGAS_bool inArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setLoopOnCommand (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_setLoopOnCommand inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setLoopOnCommand (class cPtr_gtlContext * inObject,
                                           GALGAS_bool in_loopOnCommand,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext setNextInstructionIndex'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlContext_setNextInstructionIndex) (class cPtr_gtlContext * inObject,
                                                                             class GALGAS_uint inArgument0,
                                                                             class C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setNextInstructionIndex (const int32_t inClassIndex,
                                                   extensionSetterSignature_gtlContext_setNextInstructionIndex inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setNextInstructionIndex (class cPtr_gtlContext * inObject,
                                                  GALGAS_uint in_index,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlLetUnconstructedInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlLetUnconstructedInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlLetUnconstructedInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlLetUnconstructedInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlLetUnconstructedInstruction * ptr (void) const {
    return (const cPtr_gtlLetUnconstructedInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlLetUnconstructedInstruction (const cPtr_gtlLetUnconstructedInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_lValue (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlLetUnconstructedInstruction extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlLetUnconstructedInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                              const class GALGAS_string & inOperand1,
                                                                              const class GALGAS_gtlVarPath & inOperand2
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlLetUnconstructedInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setLValue (class GALGAS_gtlVarPath inArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlLetUnconstructedInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLetUnconstructedInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlLetUnconstructedInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlLetUnconstructedInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_lValue ;

//--- Constructor
  public: cPtr_gtlLetUnconstructedInstruction (const GALGAS_location & in_where,
                                               const GALGAS_string & in_signature,
                                               const GALGAS_gtlVarPath & in_lValue
                                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_lValue (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLValue (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlUnletInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlUnletInstruction : public GALGAS_gtlLetUnconstructedInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlUnletInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlUnletInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlUnletInstruction * ptr (void) const {
    return (const cPtr_gtlUnletInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlUnletInstruction (const cPtr_gtlUnletInstruction * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlUnletInstruction extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlUnletInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_string & inOperand1,
                                                                   const class GALGAS_gtlVarPath & inOperand2
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlUnletInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlUnletInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlUnletInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlUnletInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlUnletInstruction : public cPtr_gtlLetUnconstructedInstruction {

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlUnletInstruction (const GALGAS_location & in_where,
                                    const GALGAS_string & in_signature,
                                    const GALGAS_gtlVarPath & in_lValue
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlTemplateStringInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlTemplateStringInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlTemplateStringInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlTemplateStringInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlTemplateStringInstruction * ptr (void) const {
    return (const cPtr_gtlTemplateStringInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlTemplateStringInstruction (const cPtr_gtlTemplateStringInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_string readProperty_value (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlTemplateStringInstruction extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlTemplateStringInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                            const class GALGAS_string & inOperand1,
                                                                            const class GALGAS_string & inOperand2
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlTemplateStringInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_string inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlTemplateStringInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlTemplateStringInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlTemplateStringInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlTemplateStringInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_string mProperty_value ;

//--- Constructor
  public: cPtr_gtlTemplateStringInstruction (const GALGAS_location & in_where,
                                             const GALGAS_string & in_signature,
                                             const GALGAS_string & in_value
                                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlGetColumnInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlGetColumnInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlGetColumnInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlGetColumnInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlGetColumnInstruction * ptr (void) const {
    return (const cPtr_gtlGetColumnInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlGetColumnInstruction (const cPtr_gtlGetColumnInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_destVariable (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlGetColumnInstruction extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlGetColumnInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_string & inOperand1,
                                                                       const class GALGAS_gtlVarPath & inOperand2
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlGetColumnInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setDestVariable (class GALGAS_gtlVarPath inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlGetColumnInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlGetColumnInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlGetColumnInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlGetColumnInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_destVariable ;

//--- Constructor
  public: cPtr_gtlGetColumnInstruction (const GALGAS_location & in_where,
                                        const GALGAS_string & in_signature,
                                        const GALGAS_gtlVarPath & in_destVariable
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_destVariable (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDestVariable (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlThenElsifStatementList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlThenElsifStatementList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_gtlThenElsifStatementList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_gtlThenElsifStatementList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_gtlExpression & in_condition,
                                                 const class GALGAS_gtlInstructionList & in_instructionList
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlThenElsifStatementList extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlThenElsifStatementList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_gtlThenElsifStatementList constructor_listWithValue (const class GALGAS_gtlExpression & inOperand0,
                                                                                   const class GALGAS_gtlInstructionList & inOperand1
                                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_gtlThenElsifStatementList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_gtlExpression & inOperand0,
                                                     const class GALGAS_gtlInstructionList & inOperand1
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_gtlThenElsifStatementList add_operation (const GALGAS_gtlThenElsifStatementList & inOperand,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_gtlExpression constinArgument0,
                                               class GALGAS_gtlInstructionList constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_gtlExpression constinArgument0,
                                                      class GALGAS_gtlInstructionList constinArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_gtlExpression & outArgument0,
                                                 class GALGAS_gtlInstructionList & outArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_gtlExpression & outArgument0,
                                                class GALGAS_gtlInstructionList & outArgument1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_gtlExpression & outArgument0,
                                                      class GALGAS_gtlInstructionList & outArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setConditionAtIndex (class GALGAS_gtlExpression constinArgument0,
                                                            class GALGAS_uint constinArgument1,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setInstructionListAtIndex (class GALGAS_gtlInstructionList constinArgument0,
                                                                  class GALGAS_uint constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_gtlExpression & outArgument0,
                                              class GALGAS_gtlInstructionList & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_gtlExpression & outArgument0,
                                             class GALGAS_gtlInstructionList & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_gtlExpression getter_conditionAtIndex (const class GALGAS_uint & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlInstructionList getter_instructionListAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlThenElsifStatementList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlThenElsifStatementList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                         C_Compiler * inCompiler
                                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_gtlThenElsifStatementList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                           C_Compiler * inCompiler
                                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_gtlThenElsifStatementList ;
 
} ; // End of GALGAS_gtlThenElsifStatementList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_gtlThenElsifStatementList : public cGenericAbstractEnumerator {
  public: cEnumerator_gtlThenElsifStatementList (const GALGAS_gtlThenElsifStatementList & inEnumeratedObject,
                                                 const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_gtlExpression current_condition (LOCATION_ARGS) const ;
  public: class GALGAS_gtlInstructionList current_instructionList (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_gtlThenElsifStatementList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlThenElsifStatementList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlThenElsifStatementList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlThenElsifStatementList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_gtlExpression mProperty_condition ;
  public: inline GALGAS_gtlExpression readProperty_condition (void) const {
    return mProperty_condition ;
  }

  public: GALGAS_gtlInstructionList mProperty_instructionList ;
  public: inline GALGAS_gtlInstructionList readProperty_instructionList (void) const {
    return mProperty_instructionList ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_gtlThenElsifStatementList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setCondition (const GALGAS_gtlExpression & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_condition = inValue ;
  }

  public: inline void setter_setInstructionList (const GALGAS_gtlInstructionList & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_instructionList = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlThenElsifStatementList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlThenElsifStatementList_2D_element (const GALGAS_gtlExpression & in_condition,
                                                       const GALGAS_gtlInstructionList & in_instructionList) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlThenElsifStatementList_2D_element extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlThenElsifStatementList_2D_element constructor_new (const class GALGAS_gtlExpression & inOperand0,
                                                                                    const class GALGAS_gtlInstructionList & inOperand1
                                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlThenElsifStatementList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlThenElsifStatementList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlThenElsifStatementList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlIfStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlIfStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlIfStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlIfStatementInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlIfStatementInstruction * ptr (void) const {
    return (const cPtr_gtlIfStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlIfStatementInstruction (const cPtr_gtlIfStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlThenElsifStatementList readProperty_thenElsifList (void) const ;

  public: class GALGAS_gtlInstructionList readProperty_elseList (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlIfStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlIfStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                         const class GALGAS_string & inOperand1,
                                                                         const class GALGAS_gtlThenElsifStatementList & inOperand2,
                                                                         const class GALGAS_gtlInstructionList & inOperand3
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlIfStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setElseList (class GALGAS_gtlInstructionList inArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setThenElsifList (class GALGAS_gtlThenElsifStatementList inArgument0
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlIfStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlIfStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlIfStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlIfStatementInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlThenElsifStatementList mProperty_thenElsifList ;
  public: GALGAS_gtlInstructionList mProperty_elseList ;

//--- Constructor
  public: cPtr_gtlIfStatementInstruction (const GALGAS_location & in_where,
                                          const GALGAS_string & in_signature,
                                          const GALGAS_gtlThenElsifStatementList & in_thenElsifList,
                                          const GALGAS_gtlInstructionList & in_elseList
                                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlThenElsifStatementList getter_thenElsifList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setThenElsifList (GALGAS_gtlThenElsifStatementList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_gtlInstructionList getter_elseList (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setElseList (GALGAS_gtlInstructionList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlDisplayStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlDisplayStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlDisplayStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlDisplayStatementInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlDisplayStatementInstruction * ptr (void) const {
    return (const cPtr_gtlDisplayStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlDisplayStatementInstruction (const cPtr_gtlDisplayStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_variablePath (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlDisplayStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlDisplayStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                              const class GALGAS_string & inOperand1,
                                                                              const class GALGAS_gtlVarPath & inOperand2
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlDisplayStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setVariablePath (class GALGAS_gtlVarPath inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlDisplayStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlDisplayStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlDisplayStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlDisplayStatementInstruction : public cPtr_gtlInstruction {

//--- Extension getter mayExecuteWithoutError
  public: virtual class GALGAS_bool getter_mayExecuteWithoutError (const class GALGAS_gtlContext exeContext,
           const class GALGAS_gtlData context,
           const class GALGAS_library lib,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_variablePath ;

//--- Constructor
  public: cPtr_gtlDisplayStatementInstruction (const GALGAS_location & in_where,
                                               const GALGAS_string & in_signature,
                                               const GALGAS_gtlVarPath & in_variablePath
                                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_variablePath (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setVariablePath (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @sortingKeyList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sortingKeyList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_sortingKeyList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_sortingKeyList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_lstring & in_key,
                                                 const class GALGAS_lsint & in_order
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_sortingKeyList extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_sortingKeyList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_sortingKeyList constructor_listWithValue (const class GALGAS_lstring & inOperand0,
                                                                        const class GALGAS_lsint & inOperand1
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_sortingKeyList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_lsint & inOperand1
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_sortingKeyList add_operation (const GALGAS_sortingKeyList & inOperand,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_lstring constinArgument0,
                                               class GALGAS_lsint constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                      class GALGAS_lsint constinArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_lsint & outArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                class GALGAS_lsint & outArgument1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                      class GALGAS_lsint & outArgument1,
                                                      class GALGAS_uint constinArgument2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setKeyAtIndex (class GALGAS_lstring constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setOrderAtIndex (class GALGAS_lsint constinArgument0,
                                                        class GALGAS_uint constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                              class GALGAS_lsint & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                             class GALGAS_lsint & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_keyAtIndex (const class GALGAS_uint & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lsint getter_orderAtIndex (const class GALGAS_uint & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sortingKeyList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sortingKeyList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_sortingKeyList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_sortingKeyList ;
 
} ; // End of GALGAS_sortingKeyList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_sortingKeyList : public cGenericAbstractEnumerator {
  public: cEnumerator_sortingKeyList (const GALGAS_sortingKeyList & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_key (LOCATION_ARGS) const ;
  public: class GALGAS_lsint current_order (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_sortingKeyList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sortingKeyList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @sortingKeyList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sortingKeyList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_key ;
  public: inline GALGAS_lstring readProperty_key (void) const {
    return mProperty_key ;
  }

  public: GALGAS_lsint mProperty_order ;
  public: inline GALGAS_lsint readProperty_order (void) const {
    return mProperty_order ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_sortingKeyList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_sortingKeyList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setKey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_key = inValue ;
  }

  public: inline void setter_setOrder (const GALGAS_lsint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_order = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_sortingKeyList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_sortingKeyList_2D_element (const GALGAS_lstring & in_key,
                                            const GALGAS_lsint & in_order) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_sortingKeyList_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_sortingKeyList_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                         const class GALGAS_lsint & inOperand1
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_sortingKeyList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_sortingKeyList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sortingKeyList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlAbstractSortInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlAbstractSortInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlAbstractSortInstruction (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlAbstractSortInstruction * ptr (void) const {
    return (const cPtr_gtlAbstractSortInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlAbstractSortInstruction (const cPtr_gtlAbstractSortInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlVarPath readProperty_variablePath (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlAbstractSortInstruction extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlAbstractSortInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setVariablePath (class GALGAS_gtlVarPath inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlAbstractSortInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlAbstractSortInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlAbstractSortInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlAbstractSortInstruction : public cPtr_gtlInstruction {

//--- Extension getter compare
  public: virtual class GALGAS_sint getter_compare (const class GALGAS_gtlData s1,
           const class GALGAS_gtlData s2,
           C_Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method partition
  public: virtual void method_partition (class GALGAS_list & aList,
           const class GALGAS_uint min,
           const class GALGAS_uint max,
           class GALGAS_uint & pivotIndex,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method sort
  public: virtual void method_sort (class GALGAS_list & aList,
           const class GALGAS_uint min,
           const class GALGAS_uint max,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method swap
  public: virtual void method_swap (class GALGAS_list & aList,
           const class GALGAS_uint index1,
           const class GALGAS_uint index2,
           C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_gtlVarPath mProperty_variablePath ;

//--- Constructor
  public: cPtr_gtlAbstractSortInstruction (const GALGAS_location & in_where,
                                           const GALGAS_string & in_signature,
                                           const GALGAS_gtlVarPath & in_variablePath
                                           COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlVarPath getter_variablePath (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setVariablePath (GALGAS_gtlVarPath inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlAbstractSortInstruction compare'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sint callExtensionGetter_compare (const class cPtr_gtlAbstractSortInstruction * inObject,
                                               const class GALGAS_gtlData constin_s_31_,
                                               const class GALGAS_gtlData constin_s_32_,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlAbstractSortInstruction swap'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_swap (class cPtr_gtlAbstractSortInstruction * inObject,
                               class GALGAS_list & io_aList,
                               const class GALGAS_uint constin_index_31_,
                               const class GALGAS_uint constin_index_32_,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlAbstractSortInstruction partition'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_partition (class cPtr_gtlAbstractSortInstruction * inObject,
                                    class GALGAS_list & io_aList,
                                    const class GALGAS_uint constin_min,
                                    const class GALGAS_uint constin_max,
                                    class GALGAS_uint & io_pivotIndex,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlAbstractSortInstruction sort'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_sort (class cPtr_gtlAbstractSortInstruction * inObject,
                               class GALGAS_list & io_aList,
                               const class GALGAS_uint constin_min,
                               const class GALGAS_uint constin_max,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlSortStatementStructInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlSortStatementStructInstruction : public GALGAS_gtlAbstractSortInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlSortStatementStructInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlSortStatementStructInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlSortStatementStructInstruction * ptr (void) const {
    return (const cPtr_gtlSortStatementStructInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlSortStatementStructInstruction (const cPtr_gtlSortStatementStructInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_sortingKeyList readProperty_sortingKey (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlSortStatementStructInstruction extractObject (const GALGAS_object & inObject,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlSortStatementStructInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                                 const class GALGAS_string & inOperand1,
                                                                                 const class GALGAS_gtlVarPath & inOperand2,
                                                                                 const class GALGAS_sortingKeyList & inOperand3
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlSortStatementStructInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setSortingKey (class GALGAS_sortingKeyList inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlSortStatementStructInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlSortStatementStructInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlSortStatementStructInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlSortStatementStructInstruction : public cPtr_gtlAbstractSortInstruction {

//--- Extension getter compare
  public: virtual class GALGAS_sint getter_compare (const class GALGAS_gtlData s1,
           const class GALGAS_gtlData s2,
           C_Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter compareElements
  public: virtual class GALGAS_sint getter_compareElements (const class GALGAS_gtlData s1,
           const class GALGAS_gtlData s2,
           const class GALGAS_sortingKeyList keyList,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_sortingKeyList mProperty_sortingKey ;

//--- Constructor
  public: cPtr_gtlSortStatementStructInstruction (const GALGAS_location & in_where,
                                                  const GALGAS_string & in_signature,
                                                  const GALGAS_gtlVarPath & in_variablePath,
                                                  const GALGAS_sortingKeyList & in_sortingKey
                                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_sortingKeyList getter_sortingKey (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSortingKey (GALGAS_sortingKeyList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlSortStatementStructInstruction compareElements'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_sint callExtensionGetter_compareElements (const cPtr_gtlSortStatementStructInstruction * inObject,
                                                       const class GALGAS_gtlData constin_s_31_,
                                                       const class GALGAS_gtlData constin_s_32_,
                                                       class GALGAS_sortingKeyList in_keyList,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData bool'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_bool (const class cPtr_gtlData * inObject,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_gtOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData location'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_location callExtensionGetter_location (const cPtr_gtlData * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_ltOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlVariablesInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlVariablesInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlVariablesInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlVariablesInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlVariablesInstruction * ptr (void) const {
    return (const cPtr_gtlVariablesInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlVariablesInstruction (const cPtr_gtlVariablesInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_bool readProperty_shortDisplay (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlVariablesInstruction extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlVariablesInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_string & inOperand1,
                                                                       const class GALGAS_bool & inOperand2
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlVariablesInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setShortDisplay (class GALGAS_bool inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlVariablesInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlVariablesInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlVariablesInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlVariablesInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method displayLong
  public: virtual void method_displayLong (const class GALGAS_gtlData vars,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method displayShort
  public: virtual void method_displayShort (const class GALGAS_gtlData vars,
           C_Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_bool mProperty_shortDisplay ;

//--- Constructor
  public: cPtr_gtlVariablesInstruction (const GALGAS_location & in_where,
                                        const GALGAS_string & in_signature,
                                        const GALGAS_bool & in_shortDisplay
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_shortDisplay (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setShortDisplay (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVariablesInstruction displayShort'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_displayShort (class cPtr_gtlVariablesInstruction * inObject,
                                       const class GALGAS_gtlData constin_vars,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData desc'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string callExtensionGetter_desc (const class cPtr_gtlData * inObject,
                                              const class GALGAS_uint constin_tab,
                                              class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlVariablesInstruction displayLong'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_displayLong (class cPtr_gtlVariablesInstruction * inObject,
                                      const class GALGAS_gtlData constin_vars,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlLibrariesInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlLibrariesInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlLibrariesInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlLibrariesInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlLibrariesInstruction * ptr (void) const {
    return (const cPtr_gtlLibrariesInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlLibrariesInstruction (const cPtr_gtlLibrariesInstruction * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlLibrariesInstruction extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlLibrariesInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                       const class GALGAS_string & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlLibrariesInstruction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlLibrariesInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlLibrariesInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlLibrariesInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlLibrariesInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties

//--- Constructor
  public: cPtr_gtlLibrariesInstruction (const GALGAS_location & in_where,
                                        const GALGAS_string & in_signature
                                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlInputStatementInstruction  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlInputStatementInstruction : public GALGAS_gtlInstruction {
//--------------------------------- Default constructor
  public: GALGAS_gtlInputStatementInstruction (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlInputStatementInstruction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlInputStatementInstruction * ptr (void) const {
    return (const cPtr_gtlInputStatementInstruction *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlInputStatementInstruction (const cPtr_gtlInputStatementInstruction * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_gtlArgumentList readProperty_formalArguments (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlInputStatementInstruction extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlInputStatementInstruction constructor_new (const class GALGAS_location & inOperand0,
                                                                            const class GALGAS_string & inOperand1,
                                                                            const class GALGAS_gtlArgumentList & inOperand2
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlInputStatementInstruction & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setFormalArguments (class GALGAS_gtlArgumentList inArgument0
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlInputStatementInstruction class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInputStatementInstruction ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlInputStatementInstruction class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlInputStatementInstruction : public cPtr_gtlInstruction {

//--- Extension method display
  public: virtual void method_display (C_Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method execute
  public: virtual void method_execute (class GALGAS_gtlContext & context,
           class GALGAS_gtlData & vars,
           class GALGAS_library & lib,
           class GALGAS_string & outputString,
           C_Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_gtlArgumentList mProperty_formalArguments ;

//--- Constructor
  public: cPtr_gtlInputStatementInstruction (const GALGAS_location & in_where,
                                             const GALGAS_string & in_signature,
                                             const GALGAS_gtlArgumentList & in_formalArguments
                                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_gtlArgumentList getter_formalArguments (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFormalArguments (GALGAS_gtlArgumentList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@string loadCommandFile'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_loadCommandFile (const class GALGAS_string inObject,
                                      class GALGAS_gtlContext & io_context,
                                      class GALGAS_gtlData & io_vars,
                                      class GALGAS_library & io_lib,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlInstruction display'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_display (class cPtr_gtlInstruction * inObject,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlBreakpoint  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlBreakpoint : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_gtlBreakpoint (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlBreakpoint constructor_default (LOCATION_ARGS) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_gtlBreakpoint * ptr (void) const {
    return (const cPtr_gtlBreakpoint *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_gtlBreakpoint (const cPtr_gtlBreakpoint * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_string readProperty_fileName (void) const ;

  public: class GALGAS_uint readProperty_lineNum (void) const ;

  public: class GALGAS_string readProperty_signature (void) const ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlBreakpoint extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlBreakpoint constructor_new (const class GALGAS_string & inOperand0,
                                                             const class GALGAS_uint & inOperand1,
                                                             const class GALGAS_string & inOperand2
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlBreakpoint & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setFileName (class GALGAS_string inArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLineNum (class GALGAS_uint inArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setSignature (class GALGAS_string inArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlBreakpoint class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlBreakpoint ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlBreakpoint class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlBreakpoint : public acPtr_class {


//--- Properties
  public: GALGAS_string mProperty_fileName ;
  public: GALGAS_uint mProperty_lineNum ;
  public: GALGAS_string mProperty_signature ;

//--- Constructor
  public: cPtr_gtlBreakpoint (const GALGAS_string & in_fileName,
                              const GALGAS_uint & in_lineNum,
                              const GALGAS_string & in_signature
                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_fileName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFileName (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_uint getter_lineNum (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLineNum (GALGAS_uint inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_signature (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSignature (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlBreakpointList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlBreakpointList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_gtlBreakpoint mProperty_breakpoint ;
  public: inline GALGAS_gtlBreakpoint readProperty_breakpoint (void) const {
    return mProperty_breakpoint ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlBreakpointList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_gtlBreakpointList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setBreakpoint (const GALGAS_gtlBreakpoint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_breakpoint = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlBreakpointList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlBreakpointList_2D_element (const GALGAS_gtlBreakpoint & in_breakpoint) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlBreakpointList_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlBreakpointList_2D_element constructor_new (const class GALGAS_gtlBreakpoint & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlBreakpointList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlBreakpointList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlBreakpointList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @gtlInstructionListContextStack_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlInstructionListContextStack_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_uint mProperty_nextInstructionIndex ;
  public: inline GALGAS_uint readProperty_nextInstructionIndex (void) const {
    return mProperty_nextInstructionIndex ;
  }

  public: GALGAS_gtlInstructionList mProperty_instructionList ;
  public: inline GALGAS_gtlInstructionList readProperty_instructionList (void) const {
    return mProperty_instructionList ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_gtlInstructionListContextStack_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_gtlInstructionListContextStack_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setNextInstructionIndex (const GALGAS_uint & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_nextInstructionIndex = inValue ;
  }

  public: inline void setter_setInstructionList (const GALGAS_gtlInstructionList & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_instructionList = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_gtlInstructionListContextStack_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_gtlInstructionListContextStack_2D_element (const GALGAS_uint & in_nextInstructionIndex,
                                                            const GALGAS_gtlInstructionList & in_instructionList) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_gtlInstructionListContextStack_2D_element extractObject (const GALGAS_object & inObject,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_gtlInstructionListContextStack_2D_element constructor_new (const class GALGAS_uint & inOperand0,
                                                                                         const class GALGAS_gtlInstructionList & inOperand1
                                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_gtlInstructionListContextStack_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_gtlInstructionListContextStack_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_gtlInstructionListContextStack_2D_element ;

