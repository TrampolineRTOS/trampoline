#pragma once

//--------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-1.h"

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @floatAttributeMinMax  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_floatAttributeMinMax : public GALGAS_attributeRange {
//--------------------------------- Default constructor
  public: GALGAS_floatAttributeMinMax (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_floatAttributeMinMax * ptr (void) const {
    return (const cPtr_floatAttributeMinMax *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_floatAttributeMinMax (const cPtr_floatAttributeMinMax * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_double readProperty_min (void) const ;

  public: class GALGAS_double readProperty_max (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_floatAttributeMinMax extractObject (const GALGAS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_floatAttributeMinMax class_func_new (const class GALGAS_location & inOperand0,
                                                                   const class GALGAS_double & inOperand1,
                                                                   const class GALGAS_double & inOperand2
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_floatAttributeMinMax & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setMax (class GALGAS_double inArgument0
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMin (class GALGAS_double inArgument0
                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_floatAttributeMinMax class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_floatAttributeMinMax ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @floatAttributeMinMax class
//
//--------------------------------------------------------------------------------------------------

class cPtr_floatAttributeMinMax : public cPtr_attributeRange {

//--- Extension getter contains
  public: virtual class GALGAS_bool getter_contains (const class GALGAS_object_5F_t obj,
           Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter string
  public: virtual class GALGAS_string getter_string (Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method enclose
  public: virtual void method_enclose (class GALGAS_bool & isWithin,
           const class GALGAS_attributeRange value,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_double mProperty_min ;
  public: GALGAS_double mProperty_max ;

//--- Constructor
  public: cPtr_floatAttributeMinMax (const GALGAS_location & in_location,
                                     const GALGAS_double & in_min,
                                     const GALGAS_double & in_max
                                     COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_double getter_min (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMin (GALGAS_double inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_double getter_max (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMax (GALGAS_double inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @locationList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_locationList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_locationList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_locationList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_location & in_location
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_locationList extractObject (const GALGAS_object & inObject,
                                                    Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_locationList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_locationList class_func_listWithValue (const class GALGAS_location & inOperand0
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_locationList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_location & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_locationList add_operation (const GALGAS_locationList & inOperand,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_location constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_location constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_location & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_location & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_location & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLocationAtIndex (class GALGAS_location constinArgument0,
                                                           class GALGAS_uint constinArgument1,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_location & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_location & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_location getter_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_locationList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_locationList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                            Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_locationList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_locationList ;
 
} ; // End of GALGAS_locationList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_locationList : public cGenericAbstractEnumerator {
  public: cEnumerator_locationList (const GALGAS_locationList & inEnumeratedObject,
                                    const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_location current_location (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_locationList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_locationList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @locationList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_locationList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_location mProperty_location ;
  public: inline GALGAS_location readProperty_location (void) const {
    return mProperty_location ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_locationList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLocation (const GALGAS_location & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_location = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_locationList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_locationList_2D_element (const GALGAS_location & in_location) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_locationList_2D_element extractObject (const GALGAS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_locationList_2D_element class_func_new (const class GALGAS_location & inOperand0,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_locationList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_locationList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_locationList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @implementationObjectMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_implementationObjectMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_implementationObjectMap_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_implementationObjectMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_implementationObjectMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_implementationObjectMap (const GALGAS_implementationObjectMap & inSource) ;
  public: GALGAS_implementationObjectMap & operator = (const GALGAS_implementationObjectMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_implementationObjectMap extractObject (const GALGAS_object & inObject,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_implementationObjectMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_implementationObjectMap class_func_mapWithMapToOverride (const class GALGAS_implementationObjectMap & inOperand0
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_impType & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_implementationObjectMap add_operation (const GALGAS_implementationObjectMap & inOperand,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_del (class GALGAS_lstring constinArgument0,
                                            class GALGAS_impType & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_impType constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTypeForKey (class GALGAS_impType constinArgument0,
                                                      class GALGAS_string constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_impType & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_implementationObjectMap getter_overriddenMap (Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_impType getter_typeForKey (const class GALGAS_string & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_impType & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_implementationObjectMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                                    const GALGAS_string & inKey
                                                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_implementationObjectMap ;
 
} ; // End of GALGAS_implementationObjectMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_implementationObjectMap : public cGenericAbstractEnumerator {
  public: cEnumerator_implementationObjectMap (const GALGAS_implementationObjectMap & inEnumeratedObject,
                                               const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_impType current_type (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_implementationObjectMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationObjectMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @impType  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_impType : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_impType (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_impType * ptr (void) const {
    return (const cPtr_impType *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_impType (const cPtr_impType * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_locationList readProperty_locations (void) const ;

  public: class GALGAS_dataType readProperty_type (void) const ;

  public: class GALGAS_lstring readProperty_name (void) const ;

  public: class GALGAS_bool readProperty_multiple (void) const ;

  public: class GALGAS_lstringlist readProperty_descs (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_impType extractObject (const GALGAS_object & inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_impType & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setDescs (class GALGAS_lstringlist inArgument0
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLocations (class GALGAS_locationList inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMultiple (class GALGAS_bool inArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setName (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setType (class GALGAS_dataType inArgument0
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_impType class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impType ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@implementationObjectMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_implementationObjectMap : public cMapElement {
//--- Map attributes
  public: GALGAS_impType mProperty_type ;

//--- Constructor
  public: cMapElement_implementationObjectMap (const GALGAS_lstring & inKey,
                                               const GALGAS_impType & in_type
                                               COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @implementationObjectMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_implementationObjectMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_impType mProperty_type ;
  public: inline GALGAS_impType readProperty_type (void) const {
    return mProperty_type ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_implementationObjectMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setType (const GALGAS_impType & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_type = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_implementationObjectMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_implementationObjectMap_2D_element (const GALGAS_lstring & in_lkey,
                                                     const GALGAS_impType & in_type) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_implementationObjectMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                          Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_implementationObjectMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                                 const class GALGAS_impType & inOperand1,
                                                                                 class Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_implementationObjectMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_implementationObjectMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @enumValues map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_enumValues ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_enumValues_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_enumValues : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_enumValues (void) ;

//--------------------------------- Handle copy
  public: GALGAS_enumValues (const GALGAS_enumValues & inSource) ;
  public: GALGAS_enumValues & operator = (const GALGAS_enumValues & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_enumValues extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_enumValues class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_enumValues class_func_mapWithMapToOverride (const class GALGAS_enumValues & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_implementationObjectMap & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_enumValues add_operation (const GALGAS_enumValues & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_del (class GALGAS_lstring constinArgument0,
                                            class GALGAS_implementationObjectMap & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_implementationObjectMap constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setSubAttributesForKey (class GALGAS_implementationObjectMap constinArgument0,
                                                               class GALGAS_string constinArgument1,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_implementationObjectMap & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_enumValues getter_overriddenMap (Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_implementationObjectMap getter_subAttributesForKey (const class GALGAS_string & constinOperand0,
                                                                                            Compiler * inCompiler
                                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_implementationObjectMap & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_enumValues * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_enumValues ;
 
} ; // End of GALGAS_enumValues class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_enumValues : public cGenericAbstractEnumerator {
  public: cEnumerator_enumValues (const GALGAS_enumValues & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_implementationObjectMap current_subAttributes (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_enumValues_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_enumValues ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@enumValues' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_enumValues : public cMapElement {
//--- Map attributes
  public: GALGAS_implementationObjectMap mProperty_subAttributes ;

//--- Constructor
  public: cMapElement_enumValues (const GALGAS_lstring & inKey,
                                  const GALGAS_implementationObjectMap & in_subAttributes
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @enumValues_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_enumValues_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_implementationObjectMap mProperty_subAttributes ;
  public: inline GALGAS_implementationObjectMap readProperty_subAttributes (void) const {
    return mProperty_subAttributes ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_enumValues_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setSubAttributes (const GALGAS_implementationObjectMap & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_subAttributes = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_enumValues_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_enumValues_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_implementationObjectMap & in_subAttributes) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_enumValues_2D_element extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_enumValues_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_implementationObjectMap & inOperand1,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_enumValues_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_enumValues_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_enumValues_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@enumValues mergeWithEnum' (as function)
//
//--------------------------------------------------------------------------------------------------

class GALGAS_enumValues extensionGetter_mergeWithEnum (const class GALGAS_enumValues & inObject,
                                                       const class GALGAS_enumValues & constinArgument0,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@implementationObjectMap mergeImplementationObjectAttributesWith' (as function)
//
//--------------------------------------------------------------------------------------------------

class GALGAS_implementationObjectMap extensionGetter_mergeImplementationObjectAttributesWith (const class GALGAS_implementationObjectMap & inObject,
                                                                                              const class GALGAS_implementationObjectMap & constinArgument0,
                                                                                              class Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @implementationMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_implementationMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_implementationMap_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_implementationMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_implementationMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_implementationMap (const GALGAS_implementationMap & inSource) ;
  public: GALGAS_implementationMap & operator = (const GALGAS_implementationMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_implementationMap extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_implementationMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_implementationMap class_func_mapWithMapToOverride (const class GALGAS_implementationMap & inOperand0
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_implementationObject & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_implementationMap add_operation (const GALGAS_implementationMap & inOperand,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_del (class GALGAS_lstring constinArgument0,
                                            class GALGAS_implementationObject & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_implementationObject constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setObjForKey (class GALGAS_implementationObject constinArgument0,
                                                     class GALGAS_string constinArgument1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_implementationObject & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_implementationObject getter_objForKey (const class GALGAS_string & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_implementationMap getter_overriddenMap (Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_implementationObject & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_implementationMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                              const GALGAS_string & inKey
                                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_implementationMap ;
 
} ; // End of GALGAS_implementationMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_implementationMap : public cGenericAbstractEnumerator {
  public: cEnumerator_implementationMap (const GALGAS_implementationMap & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_implementationObject current_obj (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_implementationMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @implementationObject  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_implementationObject : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_implementationObject (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_implementationObject * ptr (void) const {
    return (const cPtr_implementationObject *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_implementationObject (const cPtr_implementationObject * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lbool readProperty_multiple (void) const ;

  public: class GALGAS_implementationObjectMap readProperty_attributes (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_implementationObject extractObject (const GALGAS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_implementationObject class_func_new (const class GALGAS_lbool & inOperand0,
                                                                   const class GALGAS_implementationObjectMap & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_implementationObject & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setAttributes (class GALGAS_implementationObjectMap inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMultiple (class GALGAS_lbool inArgument0
                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_implementationObject class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationObject ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@implementationMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_implementationMap : public cMapElement {
//--- Map attributes
  public: GALGAS_implementationObject mProperty_obj ;

//--- Constructor
  public: cMapElement_implementationMap (const GALGAS_lstring & inKey,
                                         const GALGAS_implementationObject & in_obj
                                         COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @implementationMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_implementationMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_implementationObject mProperty_obj ;
  public: inline GALGAS_implementationObject readProperty_obj (void) const {
    return mProperty_obj ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_implementationMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setObj (const GALGAS_implementationObject & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_obj = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_implementationMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_implementationMap_2D_element (const GALGAS_lstring & in_lkey,
                                               const GALGAS_implementationObject & in_obj) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_implementationMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_implementationMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                           const class GALGAS_implementationObject & inOperand1,
                                                                           class Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_implementationMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_implementationMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @implementation  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_implementation : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_implementation (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_implementation * ptr (void) const {
    return (const cPtr_implementation *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_implementation (const cPtr_implementation * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_implementationMap readProperty_imp (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_implementation extractObject (const GALGAS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_implementation class_func_new (const class GALGAS_implementationMap & inOperand0
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_implementation & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setImp (class GALGAS_implementationMap inArgument0
                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_implementation class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementation ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @implementation class
//
//--------------------------------------------------------------------------------------------------

class cPtr_implementation : public acPtr_class {

//--- Extension getter hasKey
  public: virtual class GALGAS_bool getter_hasKey (const class GALGAS_string key,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter hasLKey
  public: virtual class GALGAS_bool getter_hasLKey (const class GALGAS_lstring key,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter impObject
  public: virtual class GALGAS_implementationObject getter_impObject (const class GALGAS_string objKind,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method checkObjectReferences
  public: virtual void method_checkObjectReferences (Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method checkTypeForKind
  public: virtual void method_checkTypeForKind (const class GALGAS_string objKind,
           const class GALGAS_string attributeName,
           const class GALGAS_dataType expectedType,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method verifyApplication
  public: virtual void method_verifyApplication (const class GALGAS_applicationDefinition appDef,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_implementationMap mProperty_imp ;

//--- Constructor
  public: cPtr_implementation (const GALGAS_implementationMap & in_imp
                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_implementationMap getter_imp (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setImp (GALGAS_implementationMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@implementation hasKey'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasKey (const cPtr_implementation * inObject,
                                              const class GALGAS_string constin_key,
                                              class Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@implementation hasLKey'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasLKey (const cPtr_implementation * inObject,
                                               const class GALGAS_lstring constin_key,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@implementation impObject'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_implementationObject callExtensionGetter_impObject (const cPtr_implementation * inObject,
                                                                 const class GALGAS_string constin_objKind,
                                                                 class Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @implementationObject class
//
//--------------------------------------------------------------------------------------------------

class cPtr_implementationObject : public acPtr_class {

//--- Extension getter mergeImplementationObjectWith
  public: virtual class GALGAS_implementationObject getter_mergeImplementationObjectWith (const class GALGAS_implementationObject objToMerge,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method verifyApplication
  public: virtual void method_verifyApplication (const class GALGAS_objectKind objectsOfKind,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_lbool mProperty_multiple ;
  public: GALGAS_implementationObjectMap mProperty_attributes ;

//--- Constructor
  public: cPtr_implementationObject (const GALGAS_lbool & in_multiple,
                                     const GALGAS_implementationObjectMap & in_attributes
                                     COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lbool getter_multiple (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMultiple (GALGAS_lbool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_implementationObjectMap getter_attributes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setAttributes (GALGAS_implementationObjectMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Function 'lstringWith'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring function_lstringWith (class GALGAS_string inArgument0,
                                           class Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@implementation checkTypeForKind'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_checkTypeForKind (class cPtr_implementation * inObject,
                                           const class GALGAS_string constin_objKind,
                                           const class GALGAS_string constin_attributeName,
                                           const class GALGAS_dataType constin_expectedType,
                                           Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'checkTypeForAttribute???'
//
//--------------------------------------------------------------------------------------------------

void routine_checkTypeForAttribute_3F__3F__3F_ (const class GALGAS_implementationObjectMap constinArgument0,
                                                const class GALGAS_string constinArgument1,
                                                const class GALGAS_dataType constinArgument2,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@implementation checkObjectReferences'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_checkObjectReferences (class cPtr_implementation * inObject,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @impType class
//
//--------------------------------------------------------------------------------------------------

class cPtr_impType : public acPtr_class {

//--- Extension getter autoAllowed
  public: virtual class GALGAS_bool getter_autoAllowed (Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter getDefaultValue
  public: virtual class GALGAS_object_5F_t getter_getDefaultValue (Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter mergeWithType
  public: virtual class GALGAS_impType getter_mergeWithType (const class GALGAS_impType typeToMerge,
           Compiler * COMMA_LOCATION_ARGS) const = 0 ;

//--- Extension method checkAttributeReferences
  public: virtual void method_checkAttributeReferences (const class GALGAS_implementation imp,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method verifyApplication
  public: virtual void method_verifyApplication (const class GALGAS_objectAttributes attrs,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method verifyMultipleType
  public: virtual void method_verifyMultipleType (const class GALGAS_object_5F_t attr,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method verifyType
  public: virtual void method_verifyType (const class GALGAS_object_5F_t attr,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_locationList mProperty_locations ;
  public: GALGAS_dataType mProperty_type ;
  public: GALGAS_lstring mProperty_name ;
  public: GALGAS_bool mProperty_multiple ;
  public: GALGAS_lstringlist mProperty_descs ;

//--- Constructor
  public: cPtr_impType (const GALGAS_locationList & in_locations,
                        const GALGAS_dataType & in_type,
                        const GALGAS_lstring & in_name,
                        const GALGAS_bool & in_multiple,
                        const GALGAS_lstringlist & in_descs
                        COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_locationList getter_locations (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLocations (GALGAS_locationList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_dataType getter_type (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setType (GALGAS_dataType inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_multiple (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMultiple (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstringlist getter_descs (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDescs (GALGAS_lstringlist inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@impType checkAttributeReferences'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_checkAttributeReferences (class cPtr_impType * inObject,
                                                   const class GALGAS_implementation constin_imp,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@impType mergeWithType'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_impType callExtensionGetter_mergeWithType (const class cPtr_impType * inObject,
                                                        class GALGAS_impType in_typeToMerge,
                                                        class Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@attributeRange contains'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_contains (const class cPtr_attributeRange * inObject,
                                                const class GALGAS_object_5F_t constin_obj,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@attributeRange string'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string callExtensionGetter_string (const class cPtr_attributeRange * inObject,
                                                class Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//LEXIQUE options_5F_scanner
//
//--------------------------------------------------------------------------------------------------

#include "Lexique.h"

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    R O U T I N E S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    F U N C T I O N S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                       T O K E N    C L A S S
//--------------------------------------------------------------------------------------------------

class cTokenFor_options_5F_scanner : public cToken {
  public: double mLexicalAttribute_floatNumber ;
  public: uint64_t mLexicalAttribute_integerNumber ;
  public: String mLexicalAttribute_key ;
  public: String mLexicalAttribute_number ;
  public: String mLexicalAttribute_string ;

  public: cTokenFor_options_5F_scanner (void) ;
} ;

//--------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//--------------------------------------------------------------------------------------------------

class Lexique_options_5F_scanner : public Lexique {
//--- Constructors
  public: Lexique_options_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public: Lexique_options_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceString,
                       const String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public: static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected: virtual ~ Lexique_options_5F_scanner (void) {}
  #endif



//--- Terminal symbols enumeration
  public: enum {kToken_,
   kToken_idf /* 1 */ ,
   kToken_string /* 2 */ ,
   kToken_uint_5F_number /* 3 */ ,
   kToken_float_5F_number /* 4 */ ,
   kToken__3D_ /* 5 */ ,
   kToken__2C_ /* 6 */ ,
   kToken__2D_ /* 7 */ ,
   kToken__28_ /* 8 */ ,
   kToken__29_ /* 9 */ } ;

//--- Key words table 'optionsDelimiters'
  public: static int32_t search_into_optionsDelimiters (const String & inSearchedString) ;
  

//--- Assign from attribute
  public: GALGAS_ldouble synthetizedAttribute_floatNumber (void) const ;
  public: GALGAS_luint_36__34_ synthetizedAttribute_integerNumber (void) const ;
  public: GALGAS_lstring synthetizedAttribute_key (void) const ;
  public: GALGAS_lstring synthetizedAttribute_number (void) const ;
  public: GALGAS_lstring synthetizedAttribute_string (void) const ;


//--- Attribute access
  public: double attributeValue_floatNumber (void) const ;
  public: uint64_t attributeValue_integerNumber (void) const ;
  public: String attributeValue_key (void) const ;
  public: String attributeValue_number (void) const ;
  public: String attributeValue_string (void) const ;


//--- indexing keys

//--- Parse lexical token
  protected: void internalParseLexicalToken (cTokenFor_options_5F_scanner & token) ;
  protected: virtual bool parseLexicalToken (void) override ;

//--- Get terminal message
  protected: virtual String getMessageForTerminal (const int32_t inTerminalSymbol) const override ;

//--- Get terminal count
  public: virtual int32_t terminalVocabularyCount (void) const override { return 9 ; }

//--- Get Token String
  public: virtual String getCurrentTokenString (const cToken * inTokenPtr) const override ;

//--- Enter Token
  protected: void enterToken (cTokenFor_options_5F_scanner & ioToken) ;

//--- Style name for Latex
  protected: virtual String styleNameForIndex (const uint32_t inStyleIndex) const override ;
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const override ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @identifierMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_identifierMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_identifierMap_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_identifierMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_identifierMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_identifierMap (const GALGAS_identifierMap & inSource) ;
  public: GALGAS_identifierMap & operator = (const GALGAS_identifierMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_identifierMap extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_identifierMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_identifierMap class_func_mapWithMapToOverride (const class GALGAS_identifierMap & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_object_5F_t & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_identifierMap add_operation (const GALGAS_identifierMap & inOperand,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_del (class GALGAS_lstring constinArgument0,
                                            class GALGAS_object_5F_t & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_object_5F_t constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValueForKey (class GALGAS_object_5F_t constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_object_5F_t & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_identifierMap getter_overriddenMap (Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_object_5F_t getter_valueForKey (const class GALGAS_string & constinOperand0,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_object_5F_t & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_identifierMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                          const GALGAS_string & inKey
                                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_identifierMap ;
 
} ; // End of GALGAS_identifierMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_identifierMap : public cGenericAbstractEnumerator {
  public: cEnumerator_identifierMap (const GALGAS_identifierMap & inEnumeratedObject,
                                     const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_object_5F_t current_value (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_identifierMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_identifierMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@identifierMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_identifierMap : public cMapElement {
//--- Map attributes
  public: GALGAS_object_5F_t mProperty_value ;

//--- Constructor
  public: cMapElement_identifierMap (const GALGAS_lstring & inKey,
                                     const GALGAS_object_5F_t & in_value
                                     COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @identifierMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_identifierMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_object_5F_t mProperty_value ;
  public: inline GALGAS_object_5F_t readProperty_value (void) const {
    return mProperty_value ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_identifierMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setValue (const GALGAS_object_5F_t & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_value = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_identifierMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_identifierMap_2D_element (const GALGAS_lstring & in_lkey,
                                           const GALGAS_object_5F_t & in_value) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_identifierMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_identifierMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_object_5F_t & inOperand1,
                                                                       class Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_identifierMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_identifierMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_identifierMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @objectAttributes  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_objectAttributes : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_objectAttributes (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_objectAttributes * ptr (void) const {
    return (const cPtr_objectAttributes *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_objectAttributes (const cPtr_objectAttributes * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_identifierMap readProperty_objectParams (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_objectAttributes extractObject (const GALGAS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_objectAttributes class_func_new (const class GALGAS_identifierMap & inOperand0
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_objectAttributes & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setObjectParams (class GALGAS_identifierMap inArgument0
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_objectAttributes class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectAttributes ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @objectAttributes class
//
//--------------------------------------------------------------------------------------------------

class cPtr_objectAttributes : public acPtr_class {

//--- Extension getter fieldMap
  public: virtual class GALGAS_gtlData getter_fieldMap (Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method verifyCrossReferences
  public: virtual void method_verifyCrossReferences (const class GALGAS_objectsMap allObjects,
           const class GALGAS_implementationObjectMap attributes,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_identifierMap mProperty_objectParams ;

//--- Constructor
  public: cPtr_objectAttributes (const GALGAS_identifierMap & in_objectParams
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_identifierMap getter_objectParams (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setObjectParams (GALGAS_identifierMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@objectAttributes mergeAttributes'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_objectAttributes_mergeAttributes) (class cPtr_objectAttributes * inObject,
                                                                           class GALGAS_objectAttributes inArgument0,
                                                                           class Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_mergeAttributes (const int32_t inClassIndex,
                                           extensionSetterSignature_objectAttributes_mergeAttributes inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_mergeAttributes (class cPtr_objectAttributes * inObject,
                                          GALGAS_objectAttributes in_withAttributes,
                                          Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@object_t mergeSubAttributes'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_object_5F_t_mergeSubAttributes) (class cPtr_object_5F_t * inObject,
                                                                         class GALGAS_object_5F_t inArgument0,
                                                                         class Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_mergeSubAttributes (const int32_t inClassIndex,
                                              extensionSetterSignature_object_5F_t_mergeSubAttributes inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_mergeSubAttributes (class cPtr_object_5F_t * inObject,
                                             GALGAS_object_5F_t in_withObject,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @identifierList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_identifierList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_identifierList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_identifierList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_object_5F_t & in_item
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_identifierList extractObject (const GALGAS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_identifierList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_identifierList class_func_listWithValue (const class GALGAS_object_5F_t & inOperand0
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_identifierList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_object_5F_t & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_identifierList add_operation (const GALGAS_identifierList & inOperand,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_object_5F_t constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_object_5F_t constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_object_5F_t & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_object_5F_t & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_object_5F_t & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setItemAtIndex (class GALGAS_object_5F_t constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_object_5F_t & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_object_5F_t & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_object_5F_t getter_itemAtIndex (const class GALGAS_uint & constinOperand0,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_identifierList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_identifierList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_identifierList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_identifierList ;
 
} ; // End of GALGAS_identifierList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_identifierList : public cGenericAbstractEnumerator {
  public: cEnumerator_identifierList (const GALGAS_identifierList & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_object_5F_t current_item (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_identifierList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_identifierList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @identifierList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_identifierList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_object_5F_t mProperty_item ;
  public: inline GALGAS_object_5F_t readProperty_item (void) const {
    return mProperty_item ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_identifierList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setItem (const GALGAS_object_5F_t & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_item = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_identifierList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_identifierList_2D_element (const GALGAS_object_5F_t & in_item) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_identifierList_2D_element extractObject (const GALGAS_object & inObject,
                                                                 Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_identifierList_2D_element class_func_new (const class GALGAS_object_5F_t & inOperand0,
                                                                        class Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_identifierList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_identifierList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_identifierList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @stringMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_stringMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_stringMap_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_stringMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_stringMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_stringMap (const GALGAS_stringMap & inSource) ;
  public: GALGAS_stringMap & operator = (const GALGAS_stringMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_stringMap extractObject (const GALGAS_object & inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_stringMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_stringMap class_func_mapWithMapToOverride (const class GALGAS_stringMap & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_string & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_stringMap add_operation (const GALGAS_stringMap & inOperand,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_string constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValueForKey (class GALGAS_string constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_string & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_stringMap getter_overriddenMap (Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_valueForKey (const class GALGAS_string & constinOperand0,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_string & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_stringMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                      const GALGAS_string & inKey
                                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_stringMap ;
 
} ; // End of GALGAS_stringMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_stringMap : public cGenericAbstractEnumerator {
  public: cEnumerator_stringMap (const GALGAS_stringMap & inEnumeratedObject,
                                 const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_string current_value (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_stringMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@stringMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_stringMap : public cMapElement {
//--- Map attributes
  public: GALGAS_string mProperty_value ;

//--- Constructor
  public: cMapElement_stringMap (const GALGAS_lstring & inKey,
                                 const GALGAS_string & in_value
                                 COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @stringMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_stringMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_string mProperty_value ;
  public: inline GALGAS_string readProperty_value (void) const {
    return mProperty_value ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_stringMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setValue (const GALGAS_string & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_value = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_stringMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_stringMap_2D_element (const GALGAS_lstring & in_lkey,
                                       const GALGAS_string & in_value) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_stringMap_2D_element extractObject (const GALGAS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_stringMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_string & inOperand1,
                                                                   class Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_stringMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_stringMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lstringMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_lstringMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_lstringMap_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_lstringMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_lstringMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_lstringMap (const GALGAS_lstringMap & inSource) ;
  public: GALGAS_lstringMap & operator = (const GALGAS_lstringMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lstringMap extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lstringMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_lstringMap class_func_mapWithMapToOverride (const class GALGAS_lstringMap & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_lstring & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_lstringMap add_operation (const GALGAS_lstringMap & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_lstring constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValueForKey (class GALGAS_lstring constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_lstring & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lstringMap getter_overriddenMap (Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_valueForKey (const class GALGAS_string & constinOperand0,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_lstring & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_lstringMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_lstringMap ;
 
} ; // End of GALGAS_lstringMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_lstringMap : public cGenericAbstractEnumerator {
  public: cEnumerator_lstringMap (const GALGAS_lstringMap & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_lstring current_value (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_lstringMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@lstringMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_lstringMap : public cMapElement {
//--- Map attributes
  public: GALGAS_lstring mProperty_value ;

//--- Constructor
  public: cMapElement_lstringMap (const GALGAS_lstring & inKey,
                                  const GALGAS_lstring & in_value
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @lstringMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstringMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_lstring mProperty_value ;
  public: inline GALGAS_lstring readProperty_value (void) const {
    return mProperty_value ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_lstringMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setValue (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_value = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_lstringMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_lstringMap_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_lstring & in_value) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_lstringMap_2D_element extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_lstringMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_lstring & inOperand1,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_lstringMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_lstringMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @prefix_map map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_prefix_5F_map ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_prefix_5F_map_prefix ;

//--------------------------------------------------------------------------------------------------

class GALGAS_prefix_5F_map : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_prefix_5F_map (void) ;

//--------------------------------- Handle copy
  public: GALGAS_prefix_5F_map (const GALGAS_prefix_5F_map & inSource) ;
  public: GALGAS_prefix_5F_map & operator = (const GALGAS_prefix_5F_map & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_prefix_5F_map extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_prefix_5F_map class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_prefix_5F_map class_func_mapWithMapToOverride (const class GALGAS_prefix_5F_map & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_string & inOperand1,
                                                     const class GALGAS_string & inOperand2,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_prefix_5F_map add_operation (const GALGAS_prefix_5F_map & inOperand,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_add (class GALGAS_lstring constinArgument0,
                                            class GALGAS_string constinArgument1,
                                            class GALGAS_string constinArgument2,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insert_5F_prefix (class GALGAS_lstring constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         class GALGAS_string constinArgument2,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setPrefixForKey (class GALGAS_string constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTag_5F_to_5F_repForKey (class GALGAS_string constinArgument0,
                                                                  class GALGAS_string constinArgument1,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_prefix (class GALGAS_lstring constinArgument0,
                                               class GALGAS_string & outArgument1,
                                               class GALGAS_string & outArgument2,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_prefix_5F_map getter_overriddenMap (Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_prefixForKey (const class GALGAS_string & constinOperand0,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_string getter_tag_5F_to_5F_repForKey (const class GALGAS_string & constinOperand0,
                                                                              Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_string & outOperand1,
                                                    class GALGAS_string & outOperand2) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_prefix_5F_map * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                          const GALGAS_string & inKey
                                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_prefix_5F_map ;
 
} ; // End of GALGAS_prefix_5F_map class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_prefix_5F_map : public cGenericAbstractEnumerator {
  public: cEnumerator_prefix_5F_map (const GALGAS_prefix_5F_map & inEnumeratedObject,
                                     const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_string current_prefix (LOCATION_ARGS) const ;
  public: class GALGAS_string current_tag_5F_to_5F_rep (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_prefix_5F_map_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_prefix_5F_map ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@prefix_map' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_prefix_5F_map : public cMapElement {
//--- Map attributes
  public: GALGAS_string mProperty_prefix ;
  public: GALGAS_string mProperty_tag_5F_to_5F_rep ;

//--- Constructor
  public: cMapElement_prefix_5F_map (const GALGAS_lstring & inKey,
                                     const GALGAS_string & in_prefix,
                                     const GALGAS_string & in_tag_5F_to_5F_rep
                                     COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @prefix_5F_map_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_prefix_5F_map_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_string mProperty_prefix ;
  public: inline GALGAS_string readProperty_prefix (void) const {
    return mProperty_prefix ;
  }

  public: GALGAS_string mProperty_tag_5F_to_5F_rep ;
  public: inline GALGAS_string readProperty_tag_5F_to_5F_rep (void) const {
    return mProperty_tag_5F_to_5F_rep ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_prefix_5F_map_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setPrefix (const GALGAS_string & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_prefix = inValue ;
  }

  public: inline void setter_setTag_5F_to_5F_rep (const GALGAS_string & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_tag_5F_to_5F_rep = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_prefix_5F_map_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_prefix_5F_map_2D_element (const GALGAS_lstring & in_lkey,
                                           const GALGAS_string & in_prefix,
                                           const GALGAS_string & in_tag_5F_to_5F_rep) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_prefix_5F_map_2D_element extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_prefix_5F_map_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_string & inOperand1,
                                                                       const class GALGAS_string & inOperand2,
                                                                       class Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_prefix_5F_map_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_prefix_5F_map_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_prefix_5F_map_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @stringset_map map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_stringset_5F_map ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_stringset_5F_map_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_stringset_5F_map : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_stringset_5F_map (void) ;

//--------------------------------- Handle copy
  public: GALGAS_stringset_5F_map (const GALGAS_stringset_5F_map & inSource) ;
  public: GALGAS_stringset_5F_map & operator = (const GALGAS_stringset_5F_map & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_stringset_5F_map extractObject (const GALGAS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_stringset_5F_map class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_stringset_5F_map class_func_mapWithMapToOverride (const class GALGAS_stringset_5F_map & inOperand0
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_stringset & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_stringset_5F_map add_operation (const GALGAS_stringset_5F_map & inOperand,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_add (class GALGAS_lstring constinArgument0,
                                            class GALGAS_stringset constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_delete (class GALGAS_lstring constinArgument0,
                                               class GALGAS_stringset & outArgument1,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIdsForKey (class GALGAS_stringset constinArgument0,
                                                     class GALGAS_string constinArgument1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_stringset & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_stringset getter_idsForKey (const class GALGAS_string & constinOperand0,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_stringset_5F_map getter_overriddenMap (Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_stringset & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_stringset_5F_map * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_stringset_5F_map ;
 
} ; // End of GALGAS_stringset_5F_map class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_stringset_5F_map : public cGenericAbstractEnumerator {
  public: cEnumerator_stringset_5F_map (const GALGAS_stringset_5F_map & inEnumeratedObject,
                                        const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_stringset current_ids (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_stringset_5F_map_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringset_5F_map ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@stringset_map' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_stringset_5F_map : public cMapElement {
//--- Map attributes
  public: GALGAS_stringset mProperty_ids ;

//--- Constructor
  public: cMapElement_stringset_5F_map (const GALGAS_lstring & inKey,
                                        const GALGAS_stringset & in_ids
                                        COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @stringset_5F_map_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_stringset_5F_map_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_stringset mProperty_ids ;
  public: inline GALGAS_stringset readProperty_ids (void) const {
    return mProperty_ids ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_stringset_5F_map_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setIds (const GALGAS_stringset & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_ids = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_stringset_5F_map_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_stringset_5F_map_2D_element (const GALGAS_lstring & in_lkey,
                                              const GALGAS_stringset & in_ids) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_stringset_5F_map_2D_element extractObject (const GALGAS_object & inObject,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_stringset_5F_map_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                          const class GALGAS_stringset & inOperand1,
                                                                          class Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_stringset_5F_map_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_stringset_5F_map_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringset_5F_map_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @ident_list list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_ident_5F_list : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_ident_5F_list (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_ident_5F_list (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_lstring & in_obj_5F_name
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_ident_5F_list extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_ident_5F_list class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_ident_5F_list class_func_listWithValue (const class GALGAS_lstring & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_ident_5F_list inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_ident_5F_list add_operation (const GALGAS_ident_5F_list & inOperand,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_lstring constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_lstring & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_lstring & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setObj_5F_nameAtIndex (class GALGAS_lstring constinArgument0,
                                                              class GALGAS_uint constinArgument1,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_obj_5F_nameAtIndex (const class GALGAS_uint & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_ident_5F_list ;
 
} ; // End of GALGAS_ident_5F_list class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_ident_5F_list : public cGenericAbstractEnumerator {
  public: cEnumerator_ident_5F_list (const GALGAS_ident_5F_list & inEnumeratedObject,
                                     const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_obj_5F_name (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_ident_5F_list_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ident_5F_list ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @ident_5F_list_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_ident_5F_list_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_obj_5F_name ;
  public: inline GALGAS_lstring readProperty_obj_5F_name (void) const {
    return mProperty_obj_5F_name ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_ident_5F_list_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setObj_5F_name (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_obj_5F_name = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_ident_5F_list_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_ident_5F_list_2D_element (const GALGAS_lstring & in_obj_5F_name) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_ident_5F_list_2D_element extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_ident_5F_list_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                       class Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_ident_5F_list_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_ident_5F_list_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ident_5F_list_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @ident_list_map map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_ident_5F_list_5F_map ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_ident_5F_list_5F_map_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_ident_5F_list_5F_map : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_ident_5F_list_5F_map (void) ;

//--------------------------------- Handle copy
  public: GALGAS_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inSource) ;
  public: GALGAS_ident_5F_list_5F_map & operator = (const GALGAS_ident_5F_list_5F_map & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_ident_5F_list_5F_map extractObject (const GALGAS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_ident_5F_list_5F_map class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_ident_5F_list_5F_map class_func_mapWithMapToOverride (const class GALGAS_ident_5F_list_5F_map & inOperand0
                                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_ident_5F_list & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_ident_5F_list_5F_map add_operation (const GALGAS_ident_5F_list_5F_map & inOperand,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_add (class GALGAS_lstring constinArgument0,
                                            class GALGAS_ident_5F_list constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_delete (class GALGAS_lstring constinArgument0,
                                               class GALGAS_ident_5F_list & outArgument1,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setObjsForKey (class GALGAS_ident_5F_list constinArgument0,
                                                      class GALGAS_string constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_ident_5F_list & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list getter_objsForKey (const class GALGAS_string & constinOperand0,
                                                                         Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list_5F_map getter_overriddenMap (Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_ident_5F_list & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_ident_5F_list_5F_map * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                                 const GALGAS_string & inKey
                                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_ident_5F_list_5F_map ;
 
} ; // End of GALGAS_ident_5F_list_5F_map class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_ident_5F_list_5F_map : public cGenericAbstractEnumerator {
  public: cEnumerator_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_ident_5F_list current_objs (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_ident_5F_list_5F_map_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ident_5F_list_5F_map ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@ident_list_map' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_ident_5F_list_5F_map : public cMapElement {
//--- Map attributes
  public: GALGAS_ident_5F_list mProperty_objs ;

//--- Constructor
  public: cMapElement_ident_5F_list_5F_map (const GALGAS_lstring & inKey,
                                            const GALGAS_ident_5F_list & in_objs
                                            COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @ident_5F_list_5F_map_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_ident_5F_list_5F_map_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_ident_5F_list mProperty_objs ;
  public: inline GALGAS_ident_5F_list readProperty_objs (void) const {
    return mProperty_objs ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_ident_5F_list_5F_map_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setObjs (const GALGAS_ident_5F_list & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_objs = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_ident_5F_list_5F_map_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_ident_5F_list_5F_map_2D_element (const GALGAS_lstring & in_lkey,
                                                  const GALGAS_ident_5F_list & in_objs) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_ident_5F_list_5F_map_2D_element extractObject (const GALGAS_object & inObject,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_ident_5F_list_5F_map_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                              const class GALGAS_ident_5F_list & inOperand1,
                                                                              class Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_ident_5F_list_5F_map_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_ident_5F_list_5F_map_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ident_5F_list_5F_map_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @autostart_5F_obj  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_autostart_5F_obj : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_autostart_5F_obj (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_autostart_5F_obj * ptr (void) const {
    return (const cPtr_autostart_5F_obj *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_autostart_5F_obj (const cPtr_autostart_5F_obj * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_location readProperty_location (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_autostart_5F_obj extractObject (const GALGAS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_autostart_5F_obj & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setLocation (class GALGAS_location inArgument0
                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_autostart_5F_obj class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_autostart_5F_obj ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @autostart_obj class
//
//--------------------------------------------------------------------------------------------------

class cPtr_autostart_5F_obj : public acPtr_class {


//--- Properties
  public: GALGAS_location mProperty_location ;

//--- Constructor
  public: cPtr_autostart_5F_obj (const GALGAS_location & in_location
                                 COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_location getter_location (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLocation (GALGAS_location inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @autostart_5F_void  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_autostart_5F_void : public GALGAS_autostart_5F_obj {
//--------------------------------- Default constructor
  public: GALGAS_autostart_5F_void (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_autostart_5F_void * ptr (void) const {
    return (const cPtr_autostart_5F_void *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_autostart_5F_void (const cPtr_autostart_5F_void * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_autostart_5F_void extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_autostart_5F_void class_func_new (const class GALGAS_location & inOperand0
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_autostart_5F_void & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_autostart_5F_void class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_autostart_5F_void ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @autostart_void class
//
//--------------------------------------------------------------------------------------------------

class cPtr_autostart_5F_void : public cPtr_autostart_5F_obj {


//--- Properties

//--- Constructor
  public: cPtr_autostart_5F_void (const GALGAS_location & in_location
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @autostart_5F_false  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_autostart_5F_false : public GALGAS_autostart_5F_obj {
//--------------------------------- Default constructor
  public: GALGAS_autostart_5F_false (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_autostart_5F_false * ptr (void) const {
    return (const cPtr_autostart_5F_false *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_autostart_5F_false (const cPtr_autostart_5F_false * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_autostart_5F_false extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_autostart_5F_false class_func_new (const class GALGAS_location & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_autostart_5F_false & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_autostart_5F_false class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_autostart_5F_false ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @autostart_false class
//
//--------------------------------------------------------------------------------------------------

class cPtr_autostart_5F_false : public cPtr_autostart_5F_obj {


//--- Properties

//--- Constructor
  public: cPtr_autostart_5F_false (const GALGAS_location & in_location
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@objectAttributes fieldMap'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_fieldMap (const cPtr_objectAttributes * inObject,
                                                   class Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@object_t set'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_set (class cPtr_object_5F_t * inObject,
                              const class GALGAS_lstring constin_name,
                              class GALGAS_gtlData & io_result,
                              Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@string trimLeft' (as function)
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string extensionGetter_trimLeft (const class GALGAS_string & inObject,
                                              class Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@string trimRight' (as function)
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string extensionGetter_trimRight (const class GALGAS_string & inObject,
                                               class Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@implementation verifyApplication'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyApplication (class cPtr_implementation * inObject,
                                            const class GALGAS_applicationDefinition constin_appDef,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @applicationDefinition  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_applicationDefinition : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_applicationDefinition (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_applicationDefinition * ptr (void) const {
    return (const cPtr_applicationDefinition *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_applicationDefinition (const cPtr_applicationDefinition * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_name (void) const ;

  public: class GALGAS_lstring readProperty_cpuDescription (void) const ;

  public: class GALGAS_lstring readProperty_version (void) const ;

  public: class GALGAS_lstring readProperty_versionDescription (void) const ;

  public: class GALGAS_objectsMap readProperty_objects (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_applicationDefinition extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_applicationDefinition class_func_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_lstring & inOperand1,
                                                                    const class GALGAS_lstring & inOperand2,
                                                                    const class GALGAS_lstring & inOperand3,
                                                                    const class GALGAS_objectsMap & inOperand4
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_applicationDefinition & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setCpuDescription (class GALGAS_lstring inArgument0
                                                          COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setName (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setObjects (class GALGAS_objectsMap inArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setVersion (class GALGAS_lstring inArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setVersionDescription (class GALGAS_lstring inArgument0
                                                              COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_applicationDefinition class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_applicationDefinition ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @objectKind  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_objectKind : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_objectKind (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_objectKind * ptr (void) const {
    return (const cPtr_objectKind *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_objectKind (const cPtr_objectKind * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_objectKindMap readProperty_objects (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_objectKind extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_objectKind class_func_new (const class GALGAS_objectKindMap & inOperand0
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_objectKind & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setObjects (class GALGAS_objectKindMap inArgument0
                                                   COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_objectKind class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectKind ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @objectsMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_objectsMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_objectsMap_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_objectsMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_objectsMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_objectsMap (const GALGAS_objectsMap & inSource) ;
  public: GALGAS_objectsMap & operator = (const GALGAS_objectsMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_objectsMap extractObject (const GALGAS_object & inObject,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_objectsMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_objectsMap class_func_mapWithMapToOverride (const class GALGAS_objectsMap & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_objectKind & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_objectsMap add_operation (const GALGAS_objectsMap & inOperand,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_del (class GALGAS_lstring constinArgument0,
                                            class GALGAS_objectKind & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_objectKind constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setObjectsOfKindForKey (class GALGAS_objectKind constinArgument0,
                                                               class GALGAS_string constinArgument1,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_objectKind & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_objectKind getter_objectsOfKindForKey (const class GALGAS_string & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_objectsMap getter_overriddenMap (Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_objectKind & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_objectsMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_objectsMap ;
 
} ; // End of GALGAS_objectsMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_objectsMap : public cGenericAbstractEnumerator {
  public: cEnumerator_objectsMap (const GALGAS_objectsMap & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_objectKind current_objectsOfKind (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_objectsMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectsMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@objectsMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_objectsMap : public cMapElement {
//--- Map attributes
  public: GALGAS_objectKind mProperty_objectsOfKind ;

//--- Constructor
  public: cMapElement_objectsMap (const GALGAS_lstring & inKey,
                                  const GALGAS_objectKind & in_objectsOfKind
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @applicationDefinition class
//
//--------------------------------------------------------------------------------------------------

class cPtr_applicationDefinition : public acPtr_class {

//--- Extension getter applicationWithDefaults
  public: virtual class GALGAS_applicationDefinition getter_applicationWithDefaults (const class GALGAS_implementation imp,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter templateData
  public: virtual class GALGAS_gtlData getter_templateData (const class GALGAS_implementation imp,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method verifyCrossReferences
  public: virtual void method_verifyCrossReferences (const class GALGAS_implementation imp,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_lstring mProperty_name ;
  public: GALGAS_lstring mProperty_cpuDescription ;
  public: GALGAS_lstring mProperty_version ;
  public: GALGAS_lstring mProperty_versionDescription ;
  public: GALGAS_objectsMap mProperty_objects ;

//--- Constructor
  public: cPtr_applicationDefinition (const GALGAS_lstring & in_name,
                                      const GALGAS_lstring & in_cpuDescription,
                                      const GALGAS_lstring & in_version,
                                      const GALGAS_lstring & in_versionDescription,
                                      const GALGAS_objectsMap & in_objects
                                      COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_cpuDescription (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setCpuDescription (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_version (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setVersion (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_versionDescription (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setVersionDescription (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_objectsMap getter_objects (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setObjects (GALGAS_objectsMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @objectKindMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_objectKindMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_objectKindMap_get ;

//--------------------------------------------------------------------------------------------------

class GALGAS_objectKindMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_objectKindMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_objectKindMap (const GALGAS_objectKindMap & inSource) ;
  public: GALGAS_objectKindMap & operator = (const GALGAS_objectKindMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_objectKindMap extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_objectKindMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_objectKindMap class_func_mapWithMapToOverride (const class GALGAS_objectKindMap & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_objectAttributes & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_objectKindMap add_operation (const GALGAS_objectKindMap & inOperand,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_del (class GALGAS_lstring constinArgument0,
                                            class GALGAS_objectAttributes & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_put (class GALGAS_lstring constinArgument0,
                                            class GALGAS_objectAttributes constinArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setAttributesForKey (class GALGAS_objectAttributes constinArgument0,
                                                            class GALGAS_string constinArgument1,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                            class GALGAS_objectAttributes & outArgument1,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_objectAttributes getter_attributesForKey (const class GALGAS_string & constinOperand0,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_objectKindMap getter_overriddenMap (Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_objectAttributes & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_objectKindMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                          const GALGAS_string & inKey
                                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_objectKindMap ;
 
} ; // End of GALGAS_objectKindMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_objectKindMap : public cGenericAbstractEnumerator {
  public: cEnumerator_objectKindMap (const GALGAS_objectKindMap & inEnumeratedObject,
                                     const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_objectAttributes current_attributes (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_objectKindMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectKindMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@objectKindMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_objectKindMap : public cMapElement {
//--- Map attributes
  public: GALGAS_objectAttributes mProperty_attributes ;

//--- Constructor
  public: cMapElement_objectKindMap (const GALGAS_lstring & inKey,
                                     const GALGAS_objectAttributes & in_attributes
                                     COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @objectKind class
//
//--------------------------------------------------------------------------------------------------

class cPtr_objectKind : public acPtr_class {

//--- Extension method verifyCrossReferences
  public: virtual void method_verifyCrossReferences (const class GALGAS_objectsMap allObjects,
           const class GALGAS_implementationObject obj,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_objectKindMap mProperty_objects ;

//--- Constructor
  public: cPtr_objectKind (const GALGAS_objectKindMap & in_objects
                           COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_objectKindMap getter_objects (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setObjects (GALGAS_objectKindMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@implementationObject verifyApplication'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyApplication (class cPtr_implementationObject * inObject,
                                            const class GALGAS_objectKind constin_objectsOfKind,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @objectsMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_objectsMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_objectKind mProperty_objectsOfKind ;
  public: inline GALGAS_objectKind readProperty_objectsOfKind (void) const {
    return mProperty_objectsOfKind ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_objectsMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setObjectsOfKind (const GALGAS_objectKind & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_objectsOfKind = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_objectsMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_objectsMap_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_objectKind & in_objectsOfKind) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_objectsMap_2D_element extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_objectsMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_objectKind & inOperand1,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_objectsMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_objectsMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectsMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@objectAttributes verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (class cPtr_objectAttributes * inObject,
                                                const class GALGAS_objectsMap constin_allObjects,
                                                const class GALGAS_implementationObjectMap constin_attributes,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@object_t verifyCrossReferences'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_verifyCrossReferences (class cPtr_object_5F_t * inObject,
                                                const class GALGAS_objectsMap constin_allObjects,
                                                const class GALGAS_impType constin_type,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @objectKindMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_objectKindMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_objectAttributes mProperty_attributes ;
  public: inline GALGAS_objectAttributes readProperty_attributes (void) const {
    return mProperty_attributes ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_objectKindMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setAttributes (const GALGAS_objectAttributes & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_attributes = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_objectKindMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_objectKindMap_2D_element (const GALGAS_lstring & in_lkey,
                                           const GALGAS_objectAttributes & in_attributes) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_objectKindMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_objectKindMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_objectAttributes & inOperand1,
                                                                       class Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_objectKindMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_objectKindMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectKindMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//Parser class 'goil_syntax' declaration
//
//--------------------------------------------------------------------------------------------------

class cParser_goil_5F_syntax {
//--- Virtual destructor
  public: virtual ~ cParser_goil_5F_syntax (void) {}

//--- Non terminal declarations
  protected: virtual void nt_OIL_5F_version_ (class GALGAS_lstring & outArgument0,
                                              class GALGAS_lstring & outArgument1,
                                              class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_OIL_5F_version_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_OIL_5F_version_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_application_5F_definition_ (const class GALGAS_implementation constinArgument0,
                                                         class GALGAS_applicationDefinition & ioArgument1,
                                                         class GALGAS_string & ioArgument2,
                                                         const class GALGAS_bool constinArgument3,
                                                         class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_application_5F_definition_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_application_5F_definition_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_boolean_ (class GALGAS_lbool & outArgument0,
                                       class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_boolean_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_boolean_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_description_ (class GALGAS_lstring & outArgument0,
                                           class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_description_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_description_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_file_ (class GALGAS_implementation & ioArgument0,
                                    class GALGAS_applicationDefinition & ioArgument1,
                                    class GALGAS_string & ioArgument2,
                                    const class GALGAS_bool constinArgument3,
                                    class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_file_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_file_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_file_5F_without_5F_include_ (class GALGAS_implementation & ioArgument0,
                                                          class GALGAS_applicationDefinition & ioArgument1,
                                                          class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_file_5F_without_5F_include_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_file_5F_without_5F_include_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_definition_ (class GALGAS_implementation & ioArgument0,
                                                            class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_definition_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_definition_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_cpu_5F_level_ (const class GALGAS_implementation constinArgument0,
                                                       class GALGAS_objectsMap & ioArgument1,
                                                       class GALGAS_string & ioArgument2,
                                                       const class GALGAS_bool constinArgument3,
                                                       class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_cpu_5F_level_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_cpu_5F_level_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_file_5F_level_ (class GALGAS_implementation & ioArgument0,
                                                        class GALGAS_applicationDefinition & ioArgument1,
                                                        class GALGAS_string & ioArgument2,
                                                        const class GALGAS_bool constinArgument3,
                                                        class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_file_5F_level_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_file_5F_level_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_object_5F_level_ (const class GALGAS_implementationObjectMap constinArgument0,
                                                          class GALGAS_objectAttributes & ioArgument1,
                                                          class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_object_5F_level_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_object_5F_level_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_object_5F_definition_5F_list_ (const class GALGAS_implementation constinArgument0,
                                                            class GALGAS_objectsMap & ioArgument1,
                                                            class GALGAS_string & ioArgument2,
                                                            const class GALGAS_bool constinArgument3,
                                                            class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_object_5F_definition_5F_list_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_object_5F_definition_5F_list_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_oil_5F_declaration_ (const class GALGAS_implementationObjectMap constinArgument0,
                                                  class GALGAS_objectAttributes & ioArgument1,
                                                  class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_oil_5F_declaration_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_oil_5F_declaration_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_oil_5F_declaration_5F_list_ (const class GALGAS_implementationObjectMap constinArgument0,
                                                          class GALGAS_objectAttributes & ioArgument1,
                                                          class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_oil_5F_declaration_5F_list_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_oil_5F_declaration_5F_list_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_sign_ (class GALGAS_bool & outArgument0,
                                    class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_sign_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_sign_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_start_ (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_start_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_start_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_goil_5F_syntax_start_i0_ (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_start_i0_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_start_i0_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_file_i1_ (GALGAS_implementation & ioArgument0,
                                                GALGAS_applicationDefinition & ioArgument1,
                                                GALGAS_string & ioArgument2,
                                                const GALGAS_bool constinArgument3,
                                                Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_file_i1_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_file_i1_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_file_5F_without_5F_include_i2_ (GALGAS_implementation & ioArgument0,
                                                                      GALGAS_applicationDefinition & ioArgument1,
                                                                      Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_file_5F_without_5F_include_i2_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_file_5F_without_5F_include_i2_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_sign_i3_ (GALGAS_bool & outArgument0,
                                                Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_sign_i3_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_sign_i3_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_description_i4_ (GALGAS_lstring & outArgument0,
                                                       Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_description_i4_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_description_i4_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_OIL_5F_version_i5_ (GALGAS_lstring & outArgument0,
                                                          GALGAS_lstring & outArgument1,
                                                          Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_OIL_5F_version_i5_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_OIL_5F_version_i5_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_application_5F_definition_i6_ (const GALGAS_implementation constinArgument0,
                                                                     GALGAS_applicationDefinition & ioArgument1,
                                                                     GALGAS_string & ioArgument2,
                                                                     const GALGAS_bool constinArgument3,
                                                                     Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_application_5F_definition_i6_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_application_5F_definition_i6_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_object_5F_definition_5F_list_i7_ (const GALGAS_implementation constinArgument0,
                                                                        GALGAS_objectsMap & ioArgument1,
                                                                        GALGAS_string & ioArgument2,
                                                                        const GALGAS_bool constinArgument3,
                                                                        Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_object_5F_definition_5F_list_i7_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_object_5F_definition_5F_list_i7_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_boolean_i8_ (GALGAS_lbool & outArgument0,
                                                   Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_boolean_i8_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_boolean_i8_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_ (const GALGAS_implementationObjectMap constinArgument0,
                                                                      GALGAS_objectAttributes & ioArgument1,
                                                                      Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_oil_5F_declaration_i10_ (const GALGAS_implementationObjectMap constinArgument0,
                                                               GALGAS_objectAttributes & ioArgument1,
                                                               Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_oil_5F_declaration_i10_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_oil_5F_declaration_i10_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_include_5F_file_5F_level_i11_ (GALGAS_implementation & ioArgument0,
                                                                     GALGAS_applicationDefinition & ioArgument1,
                                                                     GALGAS_string & ioArgument2,
                                                                     const GALGAS_bool constinArgument3,
                                                                     Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_include_5F_file_5F_level_i11_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_include_5F_file_5F_level_i11_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_ (const GALGAS_implementation constinArgument0,
                                                                    GALGAS_objectsMap & ioArgument1,
                                                                    GALGAS_string & ioArgument2,
                                                                    const GALGAS_bool constinArgument3,
                                                                    Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_include_5F_object_5F_level_i13_ (const GALGAS_implementationObjectMap constinArgument0,
                                                                       GALGAS_objectAttributes & ioArgument1,
                                                                       Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_include_5F_object_5F_level_i13_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_goil_5F_syntax_include_5F_object_5F_level_i13_indexing (Lexique_goil_5F_lexique * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_goil_5F_syntax_0 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_1 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_2 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_3 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_4 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_5 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_6 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_7 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_8 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_9 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_10 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_11 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_12 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_13 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_14 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_15 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_16 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_17 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_goil_5F_syntax_18 (Lexique_goil_5F_lexique *) = 0 ;


} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @auto  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_auto : public GALGAS_object_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_auto (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_auto * ptr (void) const {
    return (const cPtr_auto *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_auto (const cPtr_auto * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_auto extractObject (const GALGAS_object & inObject,
                                            Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_auto class_func_new (const class GALGAS_lstring & inOperand0,
                                                   const class GALGAS_location & inOperand1
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_auto & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_auto class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_auto ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @auto class
//
//--------------------------------------------------------------------------------------------------

class cPtr_auto : public cPtr_object_5F_t {

//--- Extension method set
  public: virtual void method_set (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties

//--- Constructor
  public: cPtr_auto (const GALGAS_lstring & in_oil_5F_desc,
                     const GALGAS_location & in_location
                     COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @boolAttribute  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_boolAttribute : public GALGAS_object_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_boolAttribute (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_boolAttribute * ptr (void) const {
    return (const cPtr_boolAttribute *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_boolAttribute (const cPtr_boolAttribute * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_bool readProperty_value (void) const ;

  public: class GALGAS_objectAttributes readProperty_subAttributes (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_boolAttribute extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_boolAttribute class_func_new (const class GALGAS_lstring & inOperand0,
                                                            const class GALGAS_location & inOperand1,
                                                            const class GALGAS_bool & inOperand2,
                                                            const class GALGAS_objectAttributes & inOperand3
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_boolAttribute & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setSubAttributes (class GALGAS_objectAttributes inArgument0
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_bool inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_boolAttribute class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_boolAttribute ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @boolAttribute class
//
//--------------------------------------------------------------------------------------------------

class cPtr_boolAttribute : public cPtr_object_5F_t {

//--- Extension method set
  public: virtual void method_set (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method verifyCrossReferences
  public: virtual void method_verifyCrossReferences (const class GALGAS_objectsMap allObjects,
           const class GALGAS_impType type,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_bool mProperty_value ;
  public: GALGAS_objectAttributes mProperty_subAttributes ;

//--- Constructor
  public: cPtr_boolAttribute (const GALGAS_lstring & in_oil_5F_desc,
                              const GALGAS_location & in_location,
                              const GALGAS_bool & in_value,
                              const GALGAS_objectAttributes & in_subAttributes
                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_objectAttributes getter_subAttributes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSubAttributes (GALGAS_objectAttributes inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @enumAttribute  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_enumAttribute : public GALGAS_object_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_enumAttribute (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_enumAttribute * ptr (void) const {
    return (const cPtr_enumAttribute *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_enumAttribute (const cPtr_enumAttribute * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_string readProperty_value (void) const ;

  public: class GALGAS_objectAttributes readProperty_subAttributes (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_enumAttribute extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_enumAttribute class_func_new (const class GALGAS_lstring & inOperand0,
                                                            const class GALGAS_location & inOperand1,
                                                            const class GALGAS_string & inOperand2,
                                                            const class GALGAS_objectAttributes & inOperand3
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_enumAttribute & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setSubAttributes (class GALGAS_objectAttributes inArgument0
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_string inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_enumAttribute class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_enumAttribute ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @enumAttribute class
//
//--------------------------------------------------------------------------------------------------

class cPtr_enumAttribute : public cPtr_object_5F_t {

//--- Extension method set
  public: virtual void method_set (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method verifyCrossReferences
  public: virtual void method_verifyCrossReferences (const class GALGAS_objectsMap allObjects,
           const class GALGAS_impType type,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_string mProperty_value ;
  public: GALGAS_objectAttributes mProperty_subAttributes ;

//--- Constructor
  public: cPtr_enumAttribute (const GALGAS_lstring & in_oil_5F_desc,
                              const GALGAS_location & in_location,
                              const GALGAS_string & in_value,
                              const GALGAS_objectAttributes & in_subAttributes
                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_objectAttributes getter_subAttributes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSubAttributes (GALGAS_objectAttributes inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @impAutoDefaultType  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_impAutoDefaultType : public GALGAS_impType {
//--------------------------------- Default constructor
  public: GALGAS_impAutoDefaultType (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_impAutoDefaultType * ptr (void) const {
    return (const cPtr_impAutoDefaultType *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_impAutoDefaultType (const cPtr_impAutoDefaultType * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_bool readProperty_withAuto (void) const ;

  public: class GALGAS_object_5F_t readProperty_defaultValue (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_impAutoDefaultType extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_impAutoDefaultType class_func_new (const class GALGAS_locationList & inOperand0,
                                                                 const class GALGAS_dataType & inOperand1,
                                                                 const class GALGAS_lstring & inOperand2,
                                                                 const class GALGAS_bool & inOperand3,
                                                                 const class GALGAS_lstringlist & inOperand4,
                                                                 const class GALGAS_bool & inOperand5,
                                                                 const class GALGAS_object_5F_t & inOperand6
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_impAutoDefaultType & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setDefaultValue (class GALGAS_object_5F_t inArgument0
                                                        COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setWithAuto (class GALGAS_bool inArgument0
                                                    COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_impAutoDefaultType class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impAutoDefaultType ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @impAutoDefaultType class
//
//--------------------------------------------------------------------------------------------------

class cPtr_impAutoDefaultType : public cPtr_impType {

//--- Extension getter autoAllowed
  public: virtual class GALGAS_bool getter_autoAllowed (Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter getDefaultValue
  public: virtual class GALGAS_object_5F_t getter_getDefaultValue (Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension getter mergeWithType
  public: virtual class GALGAS_impType getter_mergeWithType (const class GALGAS_impType typeToMerge,
           Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method setDefault
  public: virtual void method_setDefault (class GALGAS_objectAttributes & attributes,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method verifyType
  public: virtual void method_verifyType (const class GALGAS_object_5F_t attr,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_bool mProperty_withAuto ;
  public: GALGAS_object_5F_t mProperty_defaultValue ;

//--- Constructor
  public: cPtr_impAutoDefaultType (const GALGAS_locationList & in_locations,
                                   const GALGAS_dataType & in_type,
                                   const GALGAS_lstring & in_name,
                                   const GALGAS_bool & in_multiple,
                                   const GALGAS_lstringlist & in_descs,
                                   const GALGAS_bool & in_withAuto,
                                   const GALGAS_object_5F_t & in_defaultValue
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_withAuto (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setWithAuto (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_object_5F_t getter_defaultValue (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDefaultValue (GALGAS_object_5F_t inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @impBoolType  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_impBoolType : public GALGAS_impAutoDefaultType {
//--------------------------------- Default constructor
  public: GALGAS_impBoolType (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_impBoolType * ptr (void) const {
    return (const cPtr_impBoolType *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_impBoolType (const cPtr_impBoolType * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_implementationObjectMap readProperty_trueSubAttributes (void) const ;

  public: class GALGAS_implementationObjectMap readProperty_falseSubAttributes (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_impBoolType extractObject (const GALGAS_object & inObject,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_impBoolType class_func_new (const class GALGAS_locationList & inOperand0,
                                                          const class GALGAS_dataType & inOperand1,
                                                          const class GALGAS_lstring & inOperand2,
                                                          const class GALGAS_bool & inOperand3,
                                                          const class GALGAS_lstringlist & inOperand4,
                                                          const class GALGAS_bool & inOperand5,
                                                          const class GALGAS_object_5F_t & inOperand6,
                                                          const class GALGAS_implementationObjectMap & inOperand7,
                                                          const class GALGAS_implementationObjectMap & inOperand8
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_impBoolType & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setFalseSubAttributes (class GALGAS_implementationObjectMap inArgument0
                                                              COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setTrueSubAttributes (class GALGAS_implementationObjectMap inArgument0
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_impBoolType class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impBoolType ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @impBoolType class
//
//--------------------------------------------------------------------------------------------------

class cPtr_impBoolType : public cPtr_impAutoDefaultType {

//--- Extension getter mergeWithType
  public: virtual class GALGAS_impType getter_mergeWithType (const class GALGAS_impType typeToMerge,
           Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method checkAttributeReferences
  public: virtual void method_checkAttributeReferences (const class GALGAS_implementation imp,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method setDefault
  public: virtual void method_setDefault (class GALGAS_objectAttributes & attributes,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method verifyType
  public: virtual void method_verifyType (const class GALGAS_object_5F_t attr,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_implementationObjectMap mProperty_trueSubAttributes ;
  public: GALGAS_implementationObjectMap mProperty_falseSubAttributes ;

//--- Constructor
  public: cPtr_impBoolType (const GALGAS_locationList & in_locations,
                            const GALGAS_dataType & in_type,
                            const GALGAS_lstring & in_name,
                            const GALGAS_bool & in_multiple,
                            const GALGAS_lstringlist & in_descs,
                            const GALGAS_bool & in_withAuto,
                            const GALGAS_object_5F_t & in_defaultValue,
                            const GALGAS_implementationObjectMap & in_trueSubAttributes,
                            const GALGAS_implementationObjectMap & in_falseSubAttributes
                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_implementationObjectMap getter_trueSubAttributes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTrueSubAttributes (GALGAS_implementationObjectMap inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_implementationObjectMap getter_falseSubAttributes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setFalseSubAttributes (GALGAS_implementationObjectMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @impEnumType  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_impEnumType : public GALGAS_impAutoDefaultType {
//--------------------------------- Default constructor
  public: GALGAS_impEnumType (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_impEnumType * ptr (void) const {
    return (const cPtr_impEnumType *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_impEnumType (const cPtr_impEnumType * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_enumValues readProperty_valuesMap (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_impEnumType extractObject (const GALGAS_object & inObject,
                                                   Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_impEnumType class_func_new (const class GALGAS_locationList & inOperand0,
                                                          const class GALGAS_dataType & inOperand1,
                                                          const class GALGAS_lstring & inOperand2,
                                                          const class GALGAS_bool & inOperand3,
                                                          const class GALGAS_lstringlist & inOperand4,
                                                          const class GALGAS_bool & inOperand5,
                                                          const class GALGAS_object_5F_t & inOperand6,
                                                          const class GALGAS_enumValues & inOperand7
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_impEnumType & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValuesMap (class GALGAS_enumValues inArgument0
                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_impEnumType class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impEnumType ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @impEnumType class
//
//--------------------------------------------------------------------------------------------------

class cPtr_impEnumType : public cPtr_impAutoDefaultType {

//--- Extension getter mergeWithType
  public: virtual class GALGAS_impType getter_mergeWithType (const class GALGAS_impType typeToMerge,
           Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method checkAttributeReferences
  public: virtual void method_checkAttributeReferences (const class GALGAS_implementation imp,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method verifyType
  public: virtual void method_verifyType (const class GALGAS_object_5F_t attr,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_enumValues mProperty_valuesMap ;

//--- Constructor
  public: cPtr_impEnumType (const GALGAS_locationList & in_locations,
                            const GALGAS_dataType & in_type,
                            const GALGAS_lstring & in_name,
                            const GALGAS_bool & in_multiple,
                            const GALGAS_lstringlist & in_descs,
                            const GALGAS_bool & in_withAuto,
                            const GALGAS_object_5F_t & in_defaultValue,
                            const GALGAS_enumValues & in_valuesMap
                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_enumValues getter_valuesMap (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValuesMap (GALGAS_enumValues inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @impRangedType  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_impRangedType : public GALGAS_impAutoDefaultType {
//--------------------------------- Default constructor
  public: GALGAS_impRangedType (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_impRangedType * ptr (void) const {
    return (const cPtr_impRangedType *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_impRangedType (const cPtr_impRangedType * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_attributeRange readProperty_setOrRange (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_impRangedType extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_impRangedType class_func_new (const class GALGAS_locationList & inOperand0,
                                                            const class GALGAS_dataType & inOperand1,
                                                            const class GALGAS_lstring & inOperand2,
                                                            const class GALGAS_bool & inOperand3,
                                                            const class GALGAS_lstringlist & inOperand4,
                                                            const class GALGAS_bool & inOperand5,
                                                            const class GALGAS_object_5F_t & inOperand6,
                                                            const class GALGAS_attributeRange & inOperand7
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_impRangedType & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setSetOrRange (class GALGAS_attributeRange inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_impRangedType class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impRangedType ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @impRangedType class
//
//--------------------------------------------------------------------------------------------------

class cPtr_impRangedType : public cPtr_impAutoDefaultType {

//--- Extension getter mergeWithType
  public: virtual class GALGAS_impType getter_mergeWithType (const class GALGAS_impType typeToMerge,
           Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method verifyType
  public: virtual void method_verifyType (const class GALGAS_object_5F_t attr,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_attributeRange mProperty_setOrRange ;

//--- Constructor
  public: cPtr_impRangedType (const GALGAS_locationList & in_locations,
                              const GALGAS_dataType & in_type,
                              const GALGAS_lstring & in_name,
                              const GALGAS_bool & in_multiple,
                              const GALGAS_lstringlist & in_descs,
                              const GALGAS_bool & in_withAuto,
                              const GALGAS_object_5F_t & in_defaultValue,
                              const GALGAS_attributeRange & in_setOrRange
                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_attributeRange getter_setOrRange (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSetOrRange (GALGAS_attributeRange inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @impStructType  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_impStructType : public GALGAS_impType {
//--------------------------------- Default constructor
  public: GALGAS_impStructType (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_impStructType * ptr (void) const {
    return (const cPtr_impStructType *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_impStructType (const cPtr_impStructType * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_implementationObjectMap readProperty_structAttributes (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_impStructType extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_impStructType class_func_new (const class GALGAS_locationList & inOperand0,
                                                            const class GALGAS_dataType & inOperand1,
                                                            const class GALGAS_lstring & inOperand2,
                                                            const class GALGAS_bool & inOperand3,
                                                            const class GALGAS_lstringlist & inOperand4,
                                                            const class GALGAS_implementationObjectMap & inOperand5
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_impStructType & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setStructAttributes (class GALGAS_implementationObjectMap inArgument0
                                                            COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_impStructType class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impStructType ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @impStructType class
//
//--------------------------------------------------------------------------------------------------

class cPtr_impStructType : public cPtr_impType {

//--- Extension getter mergeWithType
  public: virtual class GALGAS_impType getter_mergeWithType (const class GALGAS_impType typeToMerge,
           Compiler * COMMA_LOCATION_ARGS) const override ;

//--- Extension method verifyType
  public: virtual void method_verifyType (const class GALGAS_object_5F_t attr,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_implementationObjectMap mProperty_structAttributes ;

//--- Constructor
  public: cPtr_impStructType (const GALGAS_locationList & in_locations,
                              const GALGAS_dataType & in_type,
                              const GALGAS_lstring & in_name,
                              const GALGAS_bool & in_multiple,
                              const GALGAS_lstringlist & in_descs,
                              const GALGAS_implementationObjectMap & in_structAttributes
                              COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_implementationObjectMap getter_structAttributes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setStructAttributes (GALGAS_implementationObjectMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @impVoid  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_impVoid : public GALGAS_impType {
//--------------------------------- Default constructor
  public: GALGAS_impVoid (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_impVoid * ptr (void) const {
    return (const cPtr_impVoid *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_impVoid (const cPtr_impVoid * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_impVoid extractObject (const GALGAS_object & inObject,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_impVoid class_func_new (const class GALGAS_locationList & inOperand0,
                                                      const class GALGAS_dataType & inOperand1,
                                                      const class GALGAS_lstring & inOperand2,
                                                      const class GALGAS_bool & inOperand3,
                                                      const class GALGAS_lstringlist & inOperand4
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_impVoid & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_impVoid class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impVoid ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @impVoid class
//
//--------------------------------------------------------------------------------------------------

class cPtr_impVoid : public cPtr_impType {

//--- Extension getter mergeWithType
  public: virtual class GALGAS_impType getter_mergeWithType (const class GALGAS_impType typeToMerge,
           Compiler * COMMA_LOCATION_ARGS) const override ;


//--- Properties

//--- Constructor
  public: cPtr_impVoid (const GALGAS_locationList & in_locations,
                        const GALGAS_dataType & in_type,
                        const GALGAS_lstring & in_name,
                        const GALGAS_bool & in_multiple,
                        const GALGAS_lstringlist & in_descs
                        COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @multipleAttribute  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_multipleAttribute : public GALGAS_object_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_multipleAttribute (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_multipleAttribute * ptr (void) const {
    return (const cPtr_multipleAttribute *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_multipleAttribute (const cPtr_multipleAttribute * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_identifierList readProperty_items (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_multipleAttribute extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_multipleAttribute class_func_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_location & inOperand1,
                                                                const class GALGAS_identifierList & inOperand2
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_multipleAttribute & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setItems (class GALGAS_identifierList inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_multipleAttribute class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_multipleAttribute ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @multipleAttribute class
//
//--------------------------------------------------------------------------------------------------

class cPtr_multipleAttribute : public cPtr_object_5F_t {

//--- Extension method set
  public: virtual void method_set (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method verifyCrossReferences
  public: virtual void method_verifyCrossReferences (const class GALGAS_objectsMap allObjects,
           const class GALGAS_impType type,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_identifierList mProperty_items ;

//--- Constructor
  public: cPtr_multipleAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                  const GALGAS_location & in_location,
                                  const GALGAS_identifierList & in_items
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_identifierList getter_items (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setItems (GALGAS_identifierList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @objectRefAttribute  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_objectRefAttribute : public GALGAS_object_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_objectRefAttribute (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_objectRefAttribute * ptr (void) const {
    return (const cPtr_objectRefAttribute *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_objectRefAttribute (const cPtr_objectRefAttribute * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_value (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_objectRefAttribute extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_objectRefAttribute class_func_new (const class GALGAS_lstring & inOperand0,
                                                                 const class GALGAS_location & inOperand1,
                                                                 const class GALGAS_lstring & inOperand2
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_objectRefAttribute & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_lstring inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_objectRefAttribute class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectRefAttribute ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @objectRefAttribute class
//
//--------------------------------------------------------------------------------------------------

class cPtr_objectRefAttribute : public cPtr_object_5F_t {

//--- Extension method set
  public: virtual void method_set (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method verifyCrossReferences
  public: virtual void method_verifyCrossReferences (const class GALGAS_objectsMap allObjects,
           const class GALGAS_impType type,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_value ;

//--- Constructor
  public: cPtr_objectRefAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                   const GALGAS_location & in_location,
                                   const GALGAS_lstring & in_value
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @stringAttribute  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_stringAttribute : public GALGAS_object_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_stringAttribute (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_stringAttribute * ptr (void) const {
    return (const cPtr_stringAttribute *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_stringAttribute (const cPtr_stringAttribute * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_string readProperty_value (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_stringAttribute extractObject (const GALGAS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_stringAttribute class_func_new (const class GALGAS_lstring & inOperand0,
                                                              const class GALGAS_location & inOperand1,
                                                              const class GALGAS_string & inOperand2
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_stringAttribute & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_string inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_stringAttribute class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringAttribute ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @stringAttribute class
//
//--------------------------------------------------------------------------------------------------

class cPtr_stringAttribute : public cPtr_object_5F_t {

//--- Extension method set
  public: virtual void method_set (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_string mProperty_value ;

//--- Constructor
  public: cPtr_stringAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                const GALGAS_location & in_location,
                                const GALGAS_string & in_value
                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @string_5F_class  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string_5F_class : public GALGAS_object_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_string_5F_class (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_string_5F_class * ptr (void) const {
    return (const cPtr_string_5F_class *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_string_5F_class (const cPtr_string_5F_class * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_string readProperty_value (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_string_5F_class extractObject (const GALGAS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_string_5F_class class_func_new (const class GALGAS_lstring & inOperand0,
                                                              const class GALGAS_location & inOperand1,
                                                              const class GALGAS_string & inOperand2
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_string_5F_class & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setValue (class GALGAS_string inArgument0
                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_string_5F_class class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_string_5F_class ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @string_class class
//
//--------------------------------------------------------------------------------------------------

class cPtr_string_5F_class : public cPtr_object_5F_t {

//--- Extension method set
  public: virtual void method_set (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_string mProperty_value ;

//--- Constructor
  public: cPtr_string_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                const GALGAS_location & in_location,
                                const GALGAS_string & in_value
                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_string getter_value (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setValue (GALGAS_string inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @structAttribute  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_structAttribute : public GALGAS_object_5F_t {
//--------------------------------- Default constructor
  public: GALGAS_structAttribute (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_structAttribute * ptr (void) const {
    return (const cPtr_structAttribute *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_structAttribute (const cPtr_structAttribute * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_structName (void) const ;

  public: class GALGAS_objectAttributes readProperty_subAttributes (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_structAttribute extractObject (const GALGAS_object & inObject,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_structAttribute class_func_new (const class GALGAS_lstring & inOperand0,
                                                              const class GALGAS_location & inOperand1,
                                                              const class GALGAS_lstring & inOperand2,
                                                              const class GALGAS_objectAttributes & inOperand3
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_structAttribute & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setStructName (class GALGAS_lstring inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setSubAttributes (class GALGAS_objectAttributes inArgument0
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_structAttribute class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_structAttribute ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @structAttribute class
//
//--------------------------------------------------------------------------------------------------

class cPtr_structAttribute : public cPtr_object_5F_t {

//--- Extension method set
  public: virtual void method_set (const class GALGAS_lstring name,
           class GALGAS_gtlData & result,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method verifyCrossReferences
  public: virtual void method_verifyCrossReferences (const class GALGAS_objectsMap allObjects,
           const class GALGAS_impType type,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_structName ;
  public: GALGAS_objectAttributes mProperty_subAttributes ;

//--- Constructor
  public: cPtr_structAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                const GALGAS_location & in_location,
                                const GALGAS_lstring & in_structName,
                                const GALGAS_objectAttributes & in_subAttributes
                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_structName (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setStructName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_objectAttributes getter_subAttributes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setSubAttributes (GALGAS_objectAttributes inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Function 'allTemplateFilePaths'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_stringlist function_allTemplateFilePaths (const class GALGAS_string & constinArgument0,
                                                       const class GALGAS_string & constinArgument1,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'checkAndGetFloatNumber'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_object_5F_t function_checkAndGetFloatNumber (const class GALGAS_lstring & constinArgument0,
                                                          const class GALGAS_dataType & constinArgument1,
                                                          const class GALGAS_ldouble & constinArgument2,
                                                          const class GALGAS_bool & constinArgument3,
                                                          class Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'checkAndGetIntegerNumber'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_object_5F_t function_checkAndGetIntegerNumber (const class GALGAS_lstring & constinArgument0,
                                                            const class GALGAS_dataType & constinArgument1,
                                                            const class GALGAS_luint_36__34_ & constinArgument2,
                                                            const class GALGAS_bool & constinArgument3,
                                                            class Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'emptyApplicationDefinition'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_applicationDefinition function_emptyApplicationDefinition (class Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'emptyLString'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring function_emptyLString (class Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'emptyObject'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_objectAttributes function_emptyObject (class Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'stringLBool'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_stringLBool (const class GALGAS_lbool & constinArgument0,
                                          class Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'valueList'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_string function_valueList (const class GALGAS_enumValues & constinArgument0,
                                        class Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@applicationDefinition templateData'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_templateData (const cPtr_applicationDefinition * inObject,
                                                       const class GALGAS_implementation constin_imp,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@impType autoAllowed'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_autoAllowed (const cPtr_impType * inObject,
                                                   class Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension getter '@impType getDefaultValue'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_object_5F_t callExtensionGetter_getDefaultValue (const cPtr_impType * inObject,
                                                              class Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//  GRAMMAR goil_cpu_level_include
//--------------------------------------------------------------------------------------------------

class cGrammar_goil_5F_cpu_5F_level_5F_include : public cParser_goil_5F_syntax {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public: virtual void nt_OIL_5F_version_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_OIL_5F_version_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                           GALGAS_lstring & outArgument1,
                                           Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public: virtual void nt_application_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_application_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public: virtual void nt_description_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_description_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                        Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public: virtual void nt_file_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                 GALGAS_applicationDefinition & ioArgument1,
                                 GALGAS_string & ioArgument2,
                                 const GALGAS_bool inArgument3,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file_without_include' non terminal
//--- 'parse' label
  public: virtual void nt_file_5F_without_5F_include_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_5F_without_5F_include_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_5F_without_5F_include_ (GALGAS_implementation & ioArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_cpu_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_cpu_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                    GALGAS_objectsMap & ioArgument1,
                                                    GALGAS_string & ioArgument2,
                                                    const GALGAS_bool inArgument3,
                                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_file_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_file_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                     GALGAS_applicationDefinition & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_object_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_object_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public: virtual void nt_object_5F_definition_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_object_5F_definition_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                         GALGAS_objectsMap & ioArgument1,
                                                         GALGAS_string & ioArgument2,
                                                         const GALGAS_bool inArgument3,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  const GALGAS_implementation inArgument0,
                                                  GALGAS_objectsMap & ioArgument1,
                                                  GALGAS_string & ioArgument2,
                                                  const GALGAS_bool inArgument3
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    const GALGAS_implementation inArgument0,
                                                    GALGAS_objectsMap & ioArgument1,
                                                    GALGAS_string & ioArgument2,
                                                    const GALGAS_bool inArgument3
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                               GALGAS_objectAttributes & ioArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public: virtual void nt_sign_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_sign_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public: virtual void nt_start_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_start_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_start_ (Lexique_goil_5F_lexique * inCompiler) ;

  public: virtual int32_t select_goil_5F_syntax_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_18 (Lexique_goil_5F_lexique *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//
//Parser class 'implementation_parser' declaration
//
//--------------------------------------------------------------------------------------------------

class cParser_implementation_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_implementation_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_boolean_ (class GALGAS_lbool & outArgument0,
                                       class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_boolean_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_boolean_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_boolean_5F_options_ (class GALGAS_lstring & outArgument0,
                                                  class GALGAS_impType & outArgument1,
                                                  class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_boolean_5F_options_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_boolean_5F_options_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_description_ (class GALGAS_lstring & outArgument0,
                                           class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_description_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_description_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_enum_5F_item_ (class GALGAS_enumValues & ioArgument0,
                                            class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_enum_5F_item_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_enum_5F_item_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_enum_5F_options_ (class GALGAS_lstring & outArgument0,
                                               class GALGAS_impType & outArgument1,
                                               class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_enum_5F_options_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_enum_5F_options_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_identifier_5F_or_5F_attribute_ (class GALGAS_lstring & outArgument0,
                                                             class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_identifier_5F_or_5F_attribute_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_identifier_5F_or_5F_attribute_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_identifier_5F_or_5F_enum_5F_value_ (class GALGAS_lstring & outArgument0,
                                                                 class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_identifier_5F_or_5F_enum_5F_value_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_definition_ (class GALGAS_implementation & ioArgument0,
                                                            class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_definition_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_definition_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_list_ (class GALGAS_implementationObjectMap & ioArgument0,
                                                      class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_list_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_list_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_object_5F_list_ (class GALGAS_implementation & ioArgument0,
                                                                class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_object_5F_list_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_object_5F_list_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_objects_ (class GALGAS_implementation & ioArgument0,
                                                         class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_objects_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_objects_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_type_ (class GALGAS_lstring & outArgument0,
                                                      class GALGAS_impType & outArgument1,
                                                      class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_type_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_implementation_5F_type_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_implementation_5F_level_ (class GALGAS_implementation & ioArgument0,
                                                                  class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_implementation_5F_level_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_implementation_5F_level_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_type_5F_level_ (class GALGAS_implementationObjectMap & ioArgument0,
                                                        class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_type_5F_level_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_include_5F_type_5F_level_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_int_5F_or_5F_float_ (class GALGAS_object_5F_t & outArgument0,
                                                  const class GALGAS_dataType constinArgument1,
                                                  class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_int_5F_or_5F_float_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_int_5F_or_5F_float_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_multiple_ (class GALGAS_bool & outArgument0,
                                        class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_multiple_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_multiple_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_number_5F_options_ (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_impType & outArgument1,
                                                 const class GALGAS_dataType constinArgument2,
                                                 class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_number_5F_options_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_number_5F_options_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_objref_5F_option_ (class GALGAS_lstring & outArgument0,
                                                class GALGAS_impType & outArgument1,
                                                class GALGAS_lstring inArgument2,
                                                class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_objref_5F_option_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_objref_5F_option_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_range_ (class GALGAS_attributeRange & outArgument0,
                                     const class GALGAS_dataType constinArgument1,
                                     class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_range_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_range_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_range_5F_content_ (class GALGAS_attributeRange & outArgument0,
                                                const class GALGAS_dataType constinArgument1,
                                                class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_range_5F_content_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_range_5F_content_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_set_5F_followup_ (class GALGAS_numberList & ioArgument0,
                                               const class GALGAS_dataType constinArgument1,
                                               class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_set_5F_followup_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_set_5F_followup_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_sign_ (class GALGAS_bool & outArgument0,
                                    class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_sign_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_sign_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_string_5F_options_ (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_impType & outArgument1,
                                                 class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_string_5F_options_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_string_5F_options_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_struct_5F_options_ (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_impType & outArgument1,
                                                 class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_struct_5F_options_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_struct_5F_options_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_type_5F_options_ (class GALGAS_lstring & outArgument0,
                                               class GALGAS_impType & outArgument1,
                                               const class GALGAS_dataType constinArgument2,
                                               class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_type_5F_options_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_type_5F_options_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_with_5F_auto_ (class GALGAS_bool & outArgument0,
                                            class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_with_5F_auto_parse (class Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected: virtual void nt_with_5F_auto_indexing (class Lexique_goil_5F_lexique * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_implementation_5F_parser_implementation_5F_definition_i0_ (GALGAS_implementation & ioArgument0,
                                                                                  Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_definition_i0_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_definition_i0_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_ (GALGAS_implementation & ioArgument0,
                                                                                      Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_ (GALGAS_implementation & ioArgument0,
                                                                                        Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_include_5F_type_5F_level_i3_ (GALGAS_implementationObjectMap & ioArgument0,
                                                                              Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_include_5F_type_5F_level_i3_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_objects_i4_ (GALGAS_implementation & ioArgument0,
                                                                               Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_objects_i4_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_objects_i4_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_list_i5_ (GALGAS_implementationObjectMap & ioArgument0,
                                                                            Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_list_i5_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_list_i5_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_type_i6_ (GALGAS_lstring & outArgument0,
                                                                            GALGAS_impType & outArgument1,
                                                                            Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_type_i6_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_implementation_5F_type_i6_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_struct_5F_options_i7_ (GALGAS_lstring & outArgument0,
                                                                       GALGAS_impType & outArgument1,
                                                                       Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_struct_5F_options_i7_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_struct_5F_options_i7_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_objref_5F_option_i8_ (GALGAS_lstring & outArgument0,
                                                                      GALGAS_impType & outArgument1,
                                                                      GALGAS_lstring inArgument2,
                                                                      Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_objref_5F_option_i8_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_objref_5F_option_i8_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_string_5F_options_i9_ (GALGAS_lstring & outArgument0,
                                                                       GALGAS_impType & outArgument1,
                                                                       Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_string_5F_options_i9_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_string_5F_options_i9_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_boolean_5F_options_i10_ (GALGAS_lstring & outArgument0,
                                                                         GALGAS_impType & outArgument1,
                                                                         Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_boolean_5F_options_i10_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_boolean_5F_options_i10_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_enum_5F_item_i11_ (GALGAS_enumValues & ioArgument0,
                                                                   Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_enum_5F_item_i11_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_enum_5F_item_i11_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_enum_5F_options_i12_ (GALGAS_lstring & outArgument0,
                                                                      GALGAS_impType & outArgument1,
                                                                      Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_enum_5F_options_i12_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_enum_5F_options_i12_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_number_5F_options_i13_ (GALGAS_lstring & outArgument0,
                                                                        GALGAS_impType & outArgument1,
                                                                        const GALGAS_dataType constinArgument2,
                                                                        Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_number_5F_options_i13_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_number_5F_options_i13_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_type_5F_options_i14_ (GALGAS_lstring & outArgument0,
                                                                      GALGAS_impType & outArgument1,
                                                                      const GALGAS_dataType constinArgument2,
                                                                      Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_type_5F_options_i14_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_type_5F_options_i14_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_with_5F_auto_i15_ (GALGAS_bool & outArgument0,
                                                                   Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_with_5F_auto_i15_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_with_5F_auto_i15_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_int_5F_or_5F_float_i16_ (GALGAS_object_5F_t & outArgument0,
                                                                         const GALGAS_dataType constinArgument1,
                                                                         Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_int_5F_or_5F_float_i16_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_set_5F_followup_i17_ (GALGAS_numberList & ioArgument0,
                                                                      const GALGAS_dataType constinArgument1,
                                                                      Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_set_5F_followup_i17_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_set_5F_followup_i17_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_range_5F_content_i18_ (GALGAS_attributeRange & outArgument0,
                                                                       const GALGAS_dataType constinArgument1,
                                                                       Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_range_5F_content_i18_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_range_5F_content_i18_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_range_i19_ (GALGAS_attributeRange & outArgument0,
                                                            const GALGAS_dataType constinArgument1,
                                                            Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_range_i19_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_range_i19_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_multiple_i20_ (GALGAS_bool & outArgument0,
                                                               Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_multiple_i20_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_multiple_i20_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_ (GALGAS_lstring & outArgument0,
                                                                                    Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_indexing (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_ (GALGAS_lstring & outArgument0,
                                                                                        Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse (Lexique_goil_5F_lexique * inLexique) ;

  protected: void rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_indexing (Lexique_goil_5F_lexique * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_implementation_5F_parser_0 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_1 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_2 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_3 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_4 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_5 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_6 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_7 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_8 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_9 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_10 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_11 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_12 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_13 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_14 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_15 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_16 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_17 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_18 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_19 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_20 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_21 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_22 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_23 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_24 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_25 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_26 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_27 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_28 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_29 (Lexique_goil_5F_lexique *) = 0 ;

  protected: virtual int32_t select_implementation_5F_parser_30 (Lexique_goil_5F_lexique *) = 0 ;


} ;

//--------------------------------------------------------------------------------------------------
//  GRAMMAR goil_file_level_include
//--------------------------------------------------------------------------------------------------

class cGrammar_goil_5F_file_5F_level_5F_include : public cParser_goil_5F_syntax,
                                                  public cParser_implementation_5F_parser {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public: virtual void nt_OIL_5F_version_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_OIL_5F_version_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                           GALGAS_lstring & outArgument1,
                                           Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public: virtual void nt_application_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_application_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean_options' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public: virtual void nt_description_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_description_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                        Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_item' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_item_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_item_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_item_ (GALGAS_enumValues & ioArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_options' non terminal
//--- 'parse' label
  public: virtual void nt_enum_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_enum_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_enum_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public: virtual void nt_file_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                 GALGAS_applicationDefinition & ioArgument1,
                                 GALGAS_string & ioArgument2,
                                 const GALGAS_bool inArgument3,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  GALGAS_implementation & ioArgument0,
                                                  GALGAS_applicationDefinition & ioArgument1,
                                                  GALGAS_string & ioArgument2,
                                                  const GALGAS_bool inArgument3
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    GALGAS_implementation & ioArgument0,
                                                    GALGAS_applicationDefinition & ioArgument1,
                                                    GALGAS_string & ioArgument2,
                                                    const GALGAS_bool inArgument3
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

//------------------------------------- 'file_without_include' non terminal
//--- 'parse' label
  public: virtual void nt_file_5F_without_5F_include_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_5F_without_5F_include_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_5F_without_5F_include_ (GALGAS_implementation & ioArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_attribute' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_attribute_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_attribute_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & outArgument0,
                                                          Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_enum_value' non terminal
//--- 'parse' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & outArgument0,
                                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_list_ (GALGAS_implementationObjectMap & ioArgument0,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_object_list' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_object_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_object_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_object_5F_list_ (GALGAS_implementation & ioArgument0,
                                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_objects' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_objects_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_objects_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_objects_ (GALGAS_implementation & ioArgument0,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_type' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_type_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_type_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_type_ (GALGAS_lstring & outArgument0,
                                                   GALGAS_impType & outArgument1,
                                                   Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_cpu_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_cpu_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                    GALGAS_objectsMap & ioArgument1,
                                                    GALGAS_string & ioArgument2,
                                                    const GALGAS_bool inArgument3,
                                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_file_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_file_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                     GALGAS_applicationDefinition & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_implementation_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_implementation_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_implementation_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_implementation_5F_level_ (GALGAS_implementation & ioArgument0,
                                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_object_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_object_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_type_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_type_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_type_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & ioArgument0,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'int_or_float' non terminal
//--- 'parse' label
  public: virtual void nt_int_5F_or_5F_float_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_int_5F_or_5F_float_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & outArgument0,
                                               const GALGAS_dataType inArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'multiple' non terminal
//--- 'parse' label
  public: virtual void nt_multiple_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_multiple_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_multiple_ (GALGAS_bool & outArgument0,
                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'number_options' non terminal
//--- 'parse' label
  public: virtual void nt_number_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_number_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_number_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              const GALGAS_dataType inArgument2,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public: virtual void nt_object_5F_definition_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_object_5F_definition_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                         GALGAS_objectsMap & ioArgument1,
                                                         GALGAS_string & ioArgument2,
                                                         const GALGAS_bool inArgument3,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'objref_option' non terminal
//--- 'parse' label
  public: virtual void nt_objref_5F_option_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_objref_5F_option_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_objref_5F_option_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             GALGAS_lstring inArgument2,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                               GALGAS_objectAttributes & ioArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range' non terminal
//--- 'parse' label
  public: virtual void nt_range_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_ (GALGAS_attributeRange & outArgument0,
                                  const GALGAS_dataType inArgument1,
                                  Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range_content' non terminal
//--- 'parse' label
  public: virtual void nt_range_5F_content_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_range_5F_content_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_range_5F_content_ (GALGAS_attributeRange & outArgument0,
                                             const GALGAS_dataType inArgument1,
                                             Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'set_followup' non terminal
//--- 'parse' label
  public: virtual void nt_set_5F_followup_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_set_5F_followup_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_set_5F_followup_ (GALGAS_numberList & ioArgument0,
                                            const GALGAS_dataType inArgument1,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public: virtual void nt_sign_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_sign_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public: virtual void nt_start_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_start_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_start_ (Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'string_options' non terminal
//--- 'parse' label
  public: virtual void nt_string_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_string_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_string_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'struct_options' non terminal
//--- 'parse' label
  public: virtual void nt_struct_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_struct_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_struct_5F_options_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'type_options' non terminal
//--- 'parse' label
  public: virtual void nt_type_5F_options_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_type_5F_options_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_type_5F_options_ (GALGAS_lstring & outArgument0,
                                            GALGAS_impType & outArgument1,
                                            const GALGAS_dataType inArgument2,
                                            Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'with_auto' non terminal
//--- 'parse' label
  public: virtual void nt_with_5F_auto_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_with_5F_auto_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_with_5F_auto_ (GALGAS_bool & outArgument0,
                                         Lexique_goil_5F_lexique * inCompiler) ;

  public: virtual int32_t select_goil_5F_syntax_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_18 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_19 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_20 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_21 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_22 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_23 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_24 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_25 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_26 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_27 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_28 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_29 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_implementation_5F_parser_30 (Lexique_goil_5F_lexique *) ;
} ;

//--------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------
//  GRAMMAR goil_object_level_include
//--------------------------------------------------------------------------------------------------

class cGrammar_goil_5F_object_5F_level_5F_include : public cParser_goil_5F_syntax {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public: virtual void nt_OIL_5F_version_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_OIL_5F_version_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                           GALGAS_lstring & outArgument1,
                                           Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public: virtual void nt_application_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_application_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      GALGAS_string & ioArgument2,
                                                      const GALGAS_bool inArgument3,
                                                      Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public: virtual void nt_boolean_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_boolean_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public: virtual void nt_description_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_description_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                        Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public: virtual void nt_file_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                 GALGAS_applicationDefinition & ioArgument1,
                                 GALGAS_string & ioArgument2,
                                 const GALGAS_bool inArgument3,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file_without_include' non terminal
//--- 'parse' label
  public: virtual void nt_file_5F_without_5F_include_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_file_5F_without_5F_include_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_file_5F_without_5F_include_ (GALGAS_implementation & ioArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public: virtual void nt_implementation_5F_definition_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_implementation_5F_definition_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_cpu_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_cpu_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                    GALGAS_objectsMap & ioArgument1,
                                                    GALGAS_string & ioArgument2,
                                                    const GALGAS_bool inArgument3,
                                                    Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_file_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_file_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                     GALGAS_applicationDefinition & ioArgument1,
                                                     GALGAS_string & ioArgument2,
                                                     const GALGAS_bool inArgument3,
                                                     Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_object_level' non terminal
//--- 'parse' label
  public: virtual void nt_include_5F_object_5F_level_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_include_5F_object_5F_level_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public: virtual void nt_object_5F_definition_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_object_5F_definition_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                         GALGAS_objectsMap & ioArgument1,
                                                         GALGAS_string & ioArgument2,
                                                         const GALGAS_bool inArgument3,
                                                         Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                               GALGAS_objectAttributes & ioArgument1,
                                               Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public: virtual void nt_oil_5F_declaration_5F_list_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_oil_5F_declaration_5F_list_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                       GALGAS_objectAttributes & ioArgument1,
                                                       Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public: static void _performSourceFileParsing_ (Compiler * inCompiler,
                                                  GALGAS_lstring inFileName,
                                                  const GALGAS_implementationObjectMap inArgument0,
                                                  GALGAS_objectAttributes & ioArgument1
                                                  COMMA_LOCATION_ARGS) ;

  public: static void _performSourceStringParsing_ (Compiler * inCompiler,
                                                    GALGAS_string inSourceString,
                                                    GALGAS_string inNameString,
                                                    const GALGAS_implementationObjectMap inArgument0,
                                                    GALGAS_objectAttributes & ioArgument1
                                                    COMMA_LOCATION_ARGS) ;

//--- Indexing
  public: static void performIndexing (Compiler * inCompiler,
                                       const String & inSourceFilePath) ;

//--- Only lexical analysis
  public: static void performOnlyLexicalAnalysis (Compiler * inCompiler,
                                                  const String & inSourceFilePath) ;

//--- Only syntax analysis
  public: static void performOnlySyntaxAnalysis (Compiler * inCompiler,
                                                 const String & inSourceFilePath) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public: virtual void nt_sign_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_sign_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                 Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public: virtual void nt_start_parse (Lexique_goil_5F_lexique * inCompiler) ;

//--- indexing
  public: virtual void nt_start_indexing (Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public: virtual void nt_start_ (Lexique_goil_5F_lexique * inCompiler) ;

  public: virtual int32_t select_goil_5F_syntax_0 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_1 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_2 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_3 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_4 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_5 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_6 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_7 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_8 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_9 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_10 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_11 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_12 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_13 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_14 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_15 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_16 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_17 (Lexique_goil_5F_lexique *) ;

  public: virtual int32_t select_goil_5F_syntax_18 (Lexique_goil_5F_lexique *) ;
} ;

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                               Bool options                                                    
//
//--------------------------------------------------------------------------------------------------

extern C_BoolCommandLineOption gOption_goil_5F_options_arxmlDisplayOil ;

extern C_BoolCommandLineOption gOption_goil_5F_options_warnMultiple ;

extern C_BoolCommandLineOption gOption_goil_5F_options_pierreOption ;

extern C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_log ;

//--------------------------------------------------------------------------------------------------
//
//                               UInt options                                                    
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//                              String options                                                   
//
//--------------------------------------------------------------------------------------------------

extern C_StringCommandLineOption gOption_goil_5F_options_passOption ;

extern C_StringCommandLineOption gOption_goil_5F_options_project_5F_dir ;

extern C_StringCommandLineOption gOption_goil_5F_options_target_5F_platform ;

extern C_StringCommandLineOption gOption_goil_5F_options_template_5F_dir ;

extern C_StringCommandLineOption gOption_goil_5F_options_config ;

extern C_StringCommandLineOption gOption_goil_5F_options_root ;

//--------------------------------------------------------------------------------------------------
//
//                              String List options                                              
//
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//Routine 'file_in_path&'
//
//--------------------------------------------------------------------------------------------------

void routine_file_5F_in_5F_path_26_ (class GALGAS_lstring & ioArgument0,
                                     class Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'generate_all?'
//
//--------------------------------------------------------------------------------------------------

void routine_generate_5F_all_3F_ (class GALGAS_gtlData inArgument0,
                                  class Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'setDefaults?&'
//
//--------------------------------------------------------------------------------------------------

void routine_setDefaults_3F__26_ (const class GALGAS_implementation constinArgument0,
                                  class GALGAS_applicationDefinition & ioArgument1,
                                  class Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'verifyAll??'
//
//--------------------------------------------------------------------------------------------------

void routine_verifyAll_3F__3F_ (const class GALGAS_implementation constinArgument0,
                                const class GALGAS_applicationDefinition constinArgument1,
                                class Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Parser class 'options_parser' declaration
//
//--------------------------------------------------------------------------------------------------

class cParser_options_5F_parser {
//--- Virtual destructor
  public: virtual ~ cParser_options_5F_parser (void) {}

//--- Non terminal declarations
  protected: virtual void nt_list_5F_option_5F_value_ (class GALGAS_gtlData & outArgument0,
                                                       class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_list_5F_option_5F_value_parse (class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_list_5F_option_5F_value_indexing (class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_option_5F_item_ (class GALGAS_gtlData & ioArgument0,
                                              class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_option_5F_item_parse (class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_option_5F_item_indexing (class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_option_5F_parser_5F_start_ (class GALGAS_gtlData & outArgument0,
                                                         class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_option_5F_parser_5F_start_parse (class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_option_5F_parser_5F_start_indexing (class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_option_5F_value_ (class GALGAS_gtlData & outArgument0,
                                               class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_option_5F_value_parse (class Lexique_options_5F_scanner * inLexique) = 0 ;

  protected: virtual void nt_option_5F_value_indexing (class Lexique_options_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected: void rule_options_5F_parser_option_5F_parser_5F_start_i0_ (GALGAS_gtlData & outArgument0,
                                                                        Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_parser_5F_start_i0_parse (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_parser_5F_start_i0_indexing (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_item_i1_ (GALGAS_gtlData & ioArgument0,
                                                             Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_item_i1_parse (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_item_i1_indexing (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i2_ (GALGAS_gtlData & outArgument0,
                                                              Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i2_parse (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i2_indexing (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i3_ (GALGAS_gtlData & outArgument0,
                                                              Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i3_parse (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i3_indexing (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i4_ (GALGAS_gtlData & outArgument0,
                                                              Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i4_parse (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i4_indexing (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i5_ (GALGAS_gtlData & outArgument0,
                                                              Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i5_parse (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i5_indexing (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i6_ (GALGAS_gtlData & outArgument0,
                                                              Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i6_parse (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_option_5F_value_i6_indexing (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_list_5F_option_5F_value_i7_ (GALGAS_gtlData & outArgument0,
                                                                      Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_list_5F_option_5F_value_i7_parse (Lexique_options_5F_scanner * inLexique) ;

  protected: void rule_options_5F_parser_list_5F_option_5F_value_i7_indexing (Lexique_options_5F_scanner * inLexique) ;



//--- Select methods
  protected: virtual int32_t select_options_5F_parser_0 (Lexique_options_5F_scanner *) = 0 ;

  protected: virtual int32_t select_options_5F_parser_1 (Lexique_options_5F_scanner *) = 0 ;

  protected: virtual int32_t select_options_5F_parser_2 (Lexique_options_5F_scanner *) = 0 ;

  protected: virtual int32_t select_options_5F_parser_3 (Lexique_options_5F_scanner *) = 0 ;


} ;

//--------------------------------------------------------------------------------------------------
//
//Function 'lstring'
//
//--------------------------------------------------------------------------------------------------

class GALGAS_lstring function_lstring (class GALGAS_string inArgument0,
                                       class Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setStructField'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_setStructField) (class cPtr_gtlData * inObject,
                                                                 const class GALGAS_lstring constinArgument0,
                                                                 const class GALGAS_gtlData constinArgument1,
                                                                 class Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_setStructField (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlData_setStructField inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_setStructField (class cPtr_gtlData * inObject,
                                         const GALGAS_lstring constin_name,
                                         const GALGAS_gtlData constin_data,
                                         Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//LEXIQUE arxml_5F_scanner
//
//--------------------------------------------------------------------------------------------------

#include "Lexique.h"

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    R O U T I N E S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    F U N C T I O N S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                       T O K E N    C L A S S
//--------------------------------------------------------------------------------------------------

class cTokenFor_arxml_5F_scanner : public cToken {
  public: String mLexicalAttribute_tokenString ;

  public: cTokenFor_arxml_5F_scanner (void) ;
} ;

//--------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//--------------------------------------------------------------------------------------------------

class Lexique_arxml_5F_scanner : public Lexique {
//--- Constructors
  public: Lexique_arxml_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public: Lexique_arxml_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceString,
                       const String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public: static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected: virtual ~ Lexique_arxml_5F_scanner (void) {}
  #endif

//--- Scanner mode for template scanner
  private: int32_t mMatchedTemplateDelimiterIndex ;



//--- Terminal symbols enumeration
  public: enum {kToken_,
   kToken_comment /* 1 */ ,
   kToken_name /* 2 */ ,
   kToken_value /* 3 */ ,
   kToken__3C_ /* 4 */ ,
   kToken__3C__3F_ /* 5 */ ,
   kToken__3E_ /* 6 */ ,
   kToken__3F__3E_ /* 7 */ ,
   kToken__2F__3E_ /* 8 */ ,
   kToken__3C__2F_ /* 9 */ ,
   kToken__3D_ /* 10 */ } ;

//--- Key words table 'xmlDelimitorsList'
  public: static int32_t search_into_xmlDelimitorsList (const String & inSearchedString) ;
  

//--- Assign from attribute
  public: GALGAS_lstring synthetizedAttribute_tokenString (void) const ;


//--- Attribute access
  public: String attributeValue_tokenString (void) const ;


//--- indexing keys

//--- Parse lexical token
  protected: void internalParseLexicalToken (cTokenFor_arxml_5F_scanner & token) ;
  protected: virtual bool parseLexicalToken (void) override ;

//--- Get terminal message
  protected: virtual String getMessageForTerminal (const int32_t inTerminalSymbol) const override ;

//--- Get terminal count
  public: virtual int32_t terminalVocabularyCount (void) const override { return 10 ; }

//--- Get Token String
  public: virtual String getCurrentTokenString (const cToken * inTokenPtr) const override ;

//--- Enter Token
  protected: void enterToken (cTokenFor_arxml_5F_scanner & ioToken) ;

//--- Style name for Latex
  protected: virtual String styleNameForIndex (const uint32_t inStyleIndex) const override ;
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const override ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlAttributeMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_arxmlAttributeMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_arxmlAttributeMap_searchKey ;

//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlAttributeMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_arxmlAttributeMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_arxmlAttributeMap (const GALGAS_arxmlAttributeMap & inSource) ;
  public: GALGAS_arxmlAttributeMap & operator = (const GALGAS_arxmlAttributeMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlAttributeMap extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlAttributeMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlAttributeMap class_func_mapWithMapToOverride (const class GALGAS_arxmlAttributeMap & inOperand0
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_lstring & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlAttributeMap add_operation (const GALGAS_arxmlAttributeMap & inOperand,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_lstring constinArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValueForKey (class GALGAS_lstring constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_lstring & outArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlAttributeMap getter_overriddenMap (Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstring getter_valueForKey (const class GALGAS_string & constinOperand0,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_lstring & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_arxmlAttributeMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                              const GALGAS_string & inKey
                                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_arxmlAttributeMap ;
 
} ; // End of GALGAS_arxmlAttributeMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_arxmlAttributeMap : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlAttributeMap (const GALGAS_arxmlAttributeMap & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_lstring current_value (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlAttributeMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlAttributeMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@arxmlAttributeMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_arxmlAttributeMap : public cMapElement {
//--- Map attributes
  public: GALGAS_lstring mProperty_value ;

//--- Constructor
  public: cMapElement_arxmlAttributeMap (const GALGAS_lstring & inKey,
                                         const GALGAS_lstring & in_value
                                         COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlAttributeMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlAttributeMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_lstring mProperty_value ;
  public: inline GALGAS_lstring readProperty_value (void) const {
    return mProperty_value ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlAttributeMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setValue (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_value = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlAttributeMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlAttributeMap_2D_element (const GALGAS_lstring & in_lkey,
                                               const GALGAS_lstring & in_value) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlAttributeMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlAttributeMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                           const class GALGAS_lstring & inOperand1,
                                                                           class Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlAttributeMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlAttributeMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlAttributeMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlAttributeMap print'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_print (const class GALGAS_arxmlAttributeMap inObject,
                            const class GALGAS_uint constin_indentation,
                            class Compiler * inCompiler
                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlNodeList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlNodeList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_arxmlNodeList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_arxmlNodeList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_arxmlNode & in_node
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlNodeList extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlNodeList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlNodeList class_func_listWithValue (const class GALGAS_arxmlNode & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_arxmlNodeList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_arxmlNode & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlNodeList add_operation (const GALGAS_arxmlNodeList & inOperand,
                                                               Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_arxmlNode constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_arxmlNode constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_arxmlNode & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_arxmlNode & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_arxmlNode & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setNodeAtIndex (class GALGAS_arxmlNode constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_arxmlNode & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_arxmlNode & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlNode getter_nodeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlNodeList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlNodeList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlNodeList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_arxmlNodeList ;
 
} ; // End of GALGAS_arxmlNodeList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_arxmlNodeList : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlNodeList (const GALGAS_arxmlNodeList & inEnumeratedObject,
                                     const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_arxmlNode current_node (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlNodeList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlNodeList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlNode  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlNode : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlNode (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlNode * ptr (void) const {
    return (const cPtr_arxmlNode *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlNode (const cPtr_arxmlNode * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlNode extractObject (const GALGAS_object & inObject,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlNode & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlNode class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlNode ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlNode class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlNode : public acPtr_class {

//--- Extension method getElementsFromName
  public: virtual void method_getElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           Compiler * COMMA_LOCATION_ARGS) = 0 ;

//--- Extension method getProperty
  public: virtual void method_getProperty (const class GALGAS_string nodeName,
           class GALGAS_lstring & value,
           class GALGAS_bool & found,
           Compiler * COMMA_LOCATION_ARGS) = 0 ;

//--- Extension method getSubElementsFromName
  public: virtual void method_getSubElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           Compiler * COMMA_LOCATION_ARGS) = 0 ;

//--- Extension method print
  public: virtual void method_print (const class GALGAS_uint indentation,
           Compiler * COMMA_LOCATION_ARGS) = 0 ;


//--- Properties

//--- Constructor
  public: cPtr_arxmlNode (LOCATION_ARGS) ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override = 0 ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override = 0 ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override = 0 ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlNodeList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlNodeList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_arxmlNode mProperty_node ;
  public: inline GALGAS_arxmlNode readProperty_node (void) const {
    return mProperty_node ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlNodeList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setNode (const GALGAS_arxmlNode & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_node = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlNodeList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlNodeList_2D_element (const GALGAS_arxmlNode & in_node) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlNodeList_2D_element extractObject (const GALGAS_object & inObject,
                                                                Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlNodeList_2D_element class_func_new (const class GALGAS_arxmlNode & inOperand0,
                                                                       class Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlNodeList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlNodeList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlNodeList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlNodeList print'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_print (const class GALGAS_arxmlNodeList inObject,
                            const class GALGAS_uint constin_indentation,
                            class Compiler * inCompiler
                            COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension method '@arxmlNode print'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_print (class cPtr_arxmlNode * inObject,
                                const class GALGAS_uint constin_indentation,
                                class Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlNodeList getElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_getElementsFromName (const class GALGAS_arxmlNodeList inObject,
                                          const class GALGAS_string constin_nodeName,
                                          class GALGAS_arxmlElementList & io_nodeList,
                                          class Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlElementList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlElementList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_arxmlElementList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_arxmlElementList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_arxmlElementNode & in_node
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlElementList extractObject (const GALGAS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlElementList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlElementList class_func_listWithValue (const class GALGAS_arxmlElementNode & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_arxmlElementList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_arxmlElementNode & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlElementList add_operation (const GALGAS_arxmlElementList & inOperand,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_arxmlElementNode constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_arxmlElementNode constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_arxmlElementNode & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_arxmlElementNode & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_arxmlElementNode & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setNodeAtIndex (class GALGAS_arxmlElementNode constinArgument0,
                                                       class GALGAS_uint constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_arxmlElementNode & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_arxmlElementNode & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementNode getter_nodeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_arxmlElementList ;
 
} ; // End of GALGAS_arxmlElementList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_arxmlElementList : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlElementList (const GALGAS_arxmlElementList & inEnumeratedObject,
                                        const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_arxmlElementNode current_node (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlElementList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlElementList ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension method '@arxmlNode getElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getElementsFromName (class cPtr_arxmlNode * inObject,
                                              const class GALGAS_string constin_nodeName,
                                              class GALGAS_arxmlElementList & io_nodeList,
                                              class Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlNodeList getSubElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_getSubElementsFromName (const class GALGAS_arxmlNodeList inObject,
                                             const class GALGAS_string constin_nodeName,
                                             class GALGAS_arxmlElementList & io_nodeList,
                                             class Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension method '@arxmlNode getSubElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getSubElementsFromName (class cPtr_arxmlNode * inObject,
                                                 const class GALGAS_string constin_nodeName,
                                                 class GALGAS_arxmlElementList & io_nodeList,
                                                 class Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlNodeList getProperty'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_getProperty (const class GALGAS_arxmlNodeList inObject,
                                  const class GALGAS_string constin_nodeName,
                                  class GALGAS_lstring & io_value,
                                  class GALGAS_bool & io_found,
                                  class Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Abstract extension method '@arxmlNode getProperty'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_getProperty (class cPtr_arxmlNode * inObject,
                                      const class GALGAS_string constin_nodeName,
                                      class GALGAS_lstring & io_value,
                                      class GALGAS_bool & io_found,
                                      class Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlElementNode  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlElementNode : public GALGAS_arxmlNode {
//--------------------------------- Default constructor
  public: GALGAS_arxmlElementNode (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlElementNode * ptr (void) const {
    return (const cPtr_arxmlElementNode *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlElementNode (const cPtr_arxmlElementNode * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_name (void) const ;

  public: class GALGAS_arxmlAttributeMap readProperty_attributes (void) const ;

  public: class GALGAS_arxmlNodeList readProperty_enclosedNodes (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlElementNode extractObject (const GALGAS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlElementNode class_func_new (const class GALGAS_lstring & inOperand0,
                                                               const class GALGAS_arxmlAttributeMap & inOperand1,
                                                               const class GALGAS_arxmlNodeList & inOperand2
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlElementNode & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setAttributes (class GALGAS_arxmlAttributeMap inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setEnclosedNodes (class GALGAS_arxmlNodeList inArgument0
                                                         COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setName (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlElementNode class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlElementNode ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlElementNode class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlElementNode : public cPtr_arxmlNode {

//--- Extension method getAttribute
  public: virtual void method_getAttribute (class GALGAS_string attributeName,
           class GALGAS_lstring & outAttribute,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method getAttributes
  public: virtual void method_getAttributes (class GALGAS_arxmlAttributeMap & outAttributes,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method getElementsFromName
  public: virtual void method_getElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getName
  public: virtual void method_getName (class GALGAS_lstring & outName,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method getProperty
  public: virtual void method_getProperty (const class GALGAS_string nodeName,
           class GALGAS_lstring & value,
           class GALGAS_bool & found,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getSubElements
  public: virtual void method_getSubElements (class GALGAS_arxmlElementList & nodeList,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method getSubElementsFromName
  public: virtual void method_getSubElementsFromName (const class GALGAS_string nodeName,
           class GALGAS_arxmlElementList & nodeList,
           Compiler * COMMA_LOCATION_ARGS) override ;

//--- Extension method getText
  public: virtual void method_getText (class GALGAS_lstring & value,
           class GALGAS_bool & found,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method print
  public: virtual void method_print (const class GALGAS_uint indentation,
           Compiler * COMMA_LOCATION_ARGS) override ;


//--- Properties
  public: GALGAS_lstring mProperty_name ;
  public: GALGAS_arxmlAttributeMap mProperty_attributes ;
  public: GALGAS_arxmlNodeList mProperty_enclosedNodes ;

//--- Constructor
  public: cPtr_arxmlElementNode (const GALGAS_lstring & in_name,
                                 const GALGAS_arxmlAttributeMap & in_attributes,
                                 const GALGAS_arxmlNodeList & in_enclosedNodes
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlAttributeMap getter_attributes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setAttributes (GALGAS_arxmlAttributeMap inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlNodeList getter_enclosedNodes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setEnclosedNodes (GALGAS_arxmlNodeList inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlElementList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlElementList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_arxmlElementNode mProperty_node ;
  public: inline GALGAS_arxmlElementNode readProperty_node (void) const {
    return mProperty_node ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlElementList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setNode (const GALGAS_arxmlElementNode & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_node = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlElementList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlElementList_2D_element (const GALGAS_arxmlElementNode & in_node) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlElementList_2D_element extractObject (const GALGAS_object & inObject,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlElementList_2D_element class_func_new (const class GALGAS_arxmlElementNode & inOperand0,
                                                                          class Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlElementList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlElementList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlElementList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementList getElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_getElementsFromName (const class GALGAS_arxmlElementList inObject,
                                          const class GALGAS_string constin_nodeName,
                                          class GALGAS_arxmlElementList & io_nodeList,
                                          class Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementList getSubElementsFromName'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_getSubElementsFromName (const class GALGAS_arxmlElementList inObject,
                                             const class GALGAS_string constin_nodeName,
                                             class GALGAS_arxmlElementList & io_nodeList,
                                             class Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementList getProperty'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_getProperty (const class GALGAS_arxmlElementList inObject,
                                  const class GALGAS_string constin_nodeName,
                                  class GALGAS_lstring & io_value,
                                  class GALGAS_bool & io_found,
                                  class Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlDocument  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlDocument : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlDocument (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlDocument * ptr (void) const {
    return (const cPtr_arxmlDocument *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlDocument (const cPtr_arxmlDocument * inSourcePtr) ;

//--------------------------------- Property read access
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlDocument extractObject (const GALGAS_object & inObject,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlDocument class_func_new (LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlDocument & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlDocument class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlDocument ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlDocument class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlDocument : public acPtr_class {


//--- Properties

//--- Constructor
  public: cPtr_arxmlDocument (LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlElementValueMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_arxmlElementValueMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_arxmlElementValueMap_searchKey ;

//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlElementValueMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_arxmlElementValueMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_arxmlElementValueMap (const GALGAS_arxmlElementValueMap & inSource) ;
  public: GALGAS_arxmlElementValueMap & operator = (const GALGAS_arxmlElementValueMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlElementValueMap extractObject (const GALGAS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlElementValueMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlElementValueMap class_func_mapWithMapToOverride (const class GALGAS_arxmlElementValueMap & inOperand0
                                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_arxmlElementValueList & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlElementValueMap add_operation (const GALGAS_arxmlElementValueMap & inOperand,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_arxmlElementValueList constinArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_arxmlElementValueList & outArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValuesForKey (class GALGAS_arxmlElementValueList constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_arxmlElementValueList & outArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementValueMap getter_overriddenMap (Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementValueList getter_valuesForKey (const class GALGAS_string & constinOperand0,
                                                                                   Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_arxmlElementValueList & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_arxmlElementValueMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                                 const GALGAS_string & inKey
                                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_arxmlElementValueMap ;
 
} ; // End of GALGAS_arxmlElementValueMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_arxmlElementValueMap : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlElementValueMap (const GALGAS_arxmlElementValueMap & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_arxmlElementValueList current_values (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlElementValueMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlElementValueMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlElementValueList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlElementValueList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_arxmlElementValueList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_arxmlElementValueList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_arxmlElementValue & in_value
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlElementValueList extractObject (const GALGAS_object & inObject,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlElementValueList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlElementValueList class_func_listWithValue (const class GALGAS_arxmlElementValue & inOperand0
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_arxmlElementValueList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_arxmlElementValue & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlElementValueList add_operation (const GALGAS_arxmlElementValueList & inOperand,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_arxmlElementValue constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_arxmlElementValue constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_arxmlElementValue & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_arxmlElementValue & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_arxmlElementValue & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setValueAtIndex (class GALGAS_arxmlElementValue constinArgument0,
                                                        class GALGAS_uint constinArgument1,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_arxmlElementValue & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_arxmlElementValue & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementValueList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                       Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementValueList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementValueList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                       Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlElementValue getter_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                               Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_arxmlElementValueList ;
 
} ; // End of GALGAS_arxmlElementValueList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_arxmlElementValueList : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlElementValueList (const GALGAS_arxmlElementValueList & inEnumeratedObject,
                                             const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_arxmlElementValue current_value (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlElementValueList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlElementValueList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@arxmlElementValueMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_arxmlElementValueMap : public cMapElement {
//--- Map attributes
  public: GALGAS_arxmlElementValueList mProperty_values ;

//--- Constructor
  public: cMapElement_arxmlElementValueMap (const GALGAS_lstring & inKey,
                                            const GALGAS_arxmlElementValueList & in_values
                                            COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlElementValueMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlElementValueMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_arxmlElementValueList mProperty_values ;
  public: inline GALGAS_arxmlElementValueList readProperty_values (void) const {
    return mProperty_values ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlElementValueMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setValues (const GALGAS_arxmlElementValueList & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_values = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlElementValueMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlElementValueMap_2D_element (const GALGAS_lstring & in_lkey,
                                                  const GALGAS_arxmlElementValueList & in_values) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlElementValueMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                       Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlElementValueMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                              const class GALGAS_arxmlElementValueList & inOperand1,
                                                                              class Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlElementValueMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlElementValueMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlElementValueMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlElementValue  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlElementValue : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlElementValue (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlElementValue * ptr (void) const {
    return (const cPtr_arxmlElementValue *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlElementValue (const cPtr_arxmlElementValue * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_type (void) const ;

  public: class GALGAS_lstring readProperty_text (void) const ;

  public: class GALGAS_arxmlElementValueMap readProperty_elements (void) const ;

  public: class GALGAS_arxmlAttributeMap readProperty_attributes (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlElementValue extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlElementValue class_func_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_lstring & inOperand1,
                                                                const class GALGAS_arxmlElementValueMap & inOperand2,
                                                                const class GALGAS_arxmlAttributeMap & inOperand3
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlElementValue & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setAttributes (class GALGAS_arxmlAttributeMap inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setElements (class GALGAS_arxmlElementValueMap inArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setText (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setType (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlElementValue class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlElementValue ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlElementValue class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlElementValue : public acPtr_class {

//--- Extension getter getAttributeValueFromElement
  public: virtual class GALGAS_lstring getter_getAttributeValueFromElement (const class GALGAS_string elementName,
           const class GALGAS_string attributeName,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter getTextFromElement
  public: virtual class GALGAS_lstring getter_getTextFromElement (const class GALGAS_string elementName,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter hasElement
  public: virtual class GALGAS_bool getter_hasElement (const class GALGAS_string elementName,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method getAllTextsInSelf
  public: virtual void method_getAllTextsInSelf (class GALGAS_string separator,
           class GALGAS_lstring & outString,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method getElement
  public: virtual void method_getElement (class GALGAS_string elementName,
           class GALGAS_arxmlElementValue & outElement,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method getElements
  public: virtual void method_getElements (class GALGAS_string elementName,
           class GALGAS_arxmlElementValueList & outElements,
           Compiler * COMMA_LOCATION_ARGS) ;

//--- Extension method getElementsByPath
  public: virtual void method_getElementsByPath (class GALGAS_stringlist path,
           class GALGAS_arxmlElementValueList & outElements,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_lstring mProperty_type ;
  public: GALGAS_lstring mProperty_text ;
  public: GALGAS_arxmlElementValueMap mProperty_elements ;
  public: GALGAS_arxmlAttributeMap mProperty_attributes ;

//--- Constructor
  public: cPtr_arxmlElementValue (const GALGAS_lstring & in_type,
                                  const GALGAS_lstring & in_text,
                                  const GALGAS_arxmlElementValueMap & in_elements,
                                  const GALGAS_arxmlAttributeMap & in_attributes
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_type (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setType (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_text (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setText (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlElementValueMap getter_elements (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setElements (GALGAS_arxmlElementValueMap inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlAttributeMap getter_attributes (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setAttributes (GALGAS_arxmlAttributeMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlElementValueList_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlElementValueList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_arxmlElementValue mProperty_value ;
  public: inline GALGAS_arxmlElementValue readProperty_value (void) const {
    return mProperty_value ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlElementValueList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setValue (const GALGAS_arxmlElementValue & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_value = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlElementValueList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlElementValueList_2D_element (const GALGAS_arxmlElementValue & in_value) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlElementValueList_2D_element extractObject (const GALGAS_object & inObject,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlElementValueList_2D_element class_func_new (const class GALGAS_arxmlElementValue & inOperand0,
                                                                               class Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlElementValueList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlElementValueList_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlElementValueList_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//LEXIQUE arxmlmetaparser_5F_scanner
//
//--------------------------------------------------------------------------------------------------

#include "Lexique.h"

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    R O U T I N E S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                    E X T E R N    F U N C T I O N S
//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//                       T O K E N    C L A S S
//--------------------------------------------------------------------------------------------------

class cTokenFor_arxmlmetaparser_5F_scanner : public cToken {
  public: String mLexicalAttribute_tokenString ;

  public: cTokenFor_arxmlmetaparser_5F_scanner (void) ;
} ;

//--------------------------------------------------------------------------------------------------
//                     S C A N N E R    C L A S S
//--------------------------------------------------------------------------------------------------

class Lexique_arxmlmetaparser_5F_scanner : public Lexique {
//--- Constructors
  public: Lexique_arxmlmetaparser_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public: Lexique_arxmlmetaparser_5F_scanner (Compiler * inCallerCompiler,
                       const String & inSourceString,
                       const String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public: static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected: virtual ~ Lexique_arxmlmetaparser_5F_scanner (void) {}
  #endif

//--- Scanner mode for template scanner
  private: int32_t mMatchedTemplateDelimiterIndex ;



//--- Terminal symbols enumeration
  public: enum {kToken_,
   kToken_comment /* 1 */ ,
   kToken_xmlTag /* 2 */ ,
   kToken_xmlTagValue /* 3 */ ,
   kToken_identifier /* 4 */ ,
   kToken__3C_ /* 5 */ ,
   kToken__3C_xsd_3A_ /* 6 */ ,
   kToken__3C__2F_xsd_3A_ /* 7 */ ,
   kToken__3C__3F_xml /* 8 */ ,
   kToken__3E_ /* 9 */ ,
   kToken__3F__3E_ /* 10 */ ,
   kToken__2F__3E_ /* 11 */ ,
   kToken__3C__2F_ /* 12 */ ,
   kToken__3D_ /* 13 */ ,
   kToken_group /* 14 */ ,
   kToken_annotation /* 15 */ ,
   kToken_appinfo /* 16 */ ,
   kToken_attribute /* 17 */ ,
   kToken_attributeGroup /* 18 */ ,
   kToken_choice /* 19 */ ,
   kToken_complexType /* 20 */ ,
   kToken_documentation /* 21 */ ,
   kToken_element /* 22 */ ,
   kToken_enumeration /* 23 */ ,
   kToken_extension /* 24 */ ,
   kToken_import /* 25 */ ,
   kToken_maxLength /* 26 */ ,
   kToken_pattern /* 27 */ ,
   kToken_restriction /* 28 */ ,
   kToken_schema /* 29 */ ,
   kToken_sequence /* 30 */ ,
   kToken_simpleContent /* 31 */ ,
   kToken_simpleType /* 32 */ ,
   kToken_whiteSpace /* 33 */ ,
   kToken_abstract /* 34 */ ,
   kToken_attributeFormDefault /* 35 */ ,
   kToken_attributeRef /* 36 */ ,
   kToken_base /* 37 */ ,
   kToken_category /* 38 */ ,
   kToken_CATEGORY /* 39 */ ,
   kToken_color /* 40 */ ,
   kToken_customType /* 41 */ ,
   kToken_elementFormDefault /* 42 */ ,
   kToken_encoding /* 43 */ ,
   kToken_enforceMinMultiplicity /* 44 */ ,
   kToken_globalElement /* 45 */ ,
   kToken_id /* 46 */ ,
   kToken_latestBindingTime /* 47 */ ,
   kToken_maxOccurs /* 48 */ ,
   kToken_minOccurs /* 49 */ ,
   kToken_mixed /* 50 */ ,
   kToken_name /* 51 */ ,
   kToken_namePlural /* 52 */ ,
   kToken_namespace /* 53 */ ,
   kToken_noteType /* 54 */ ,
   kToken_nsPrefix /* 55 */ ,
   kToken_qualifiedName /* 56 */ ,
   kToken_recommendedPackage /* 57 */ ,
   kToken_ref /* 58 */ ,
   kToken_roleElement /* 59 */ ,
   kToken_roleWrapperElement /* 60 */ ,
   kToken_schemaLocation /* 61 */ ,
   kToken_sequenceOffset /* 62 */ ,
   kToken_source /* 63 */ ,
   kToken_Splitkey /* 64 */ ,
   kToken_Status /* 65 */ ,
   kToken_StatusRevisionBegin /* 66 */ ,
   kToken_targetNamespace /* 67 */ ,
   kToken_type /* 68 */ ,
   kToken_typeElement /* 69 */ ,
   kToken_typeWrapperElement /* 70 */ ,
   kToken_use /* 71 */ ,
   kToken_value /* 72 */ ,
   kToken_version /* 73 */ ,
   kToken_xmlns_3A_AR /* 74 */ ,
   kToken_xmlns_3A_xsd /* 75 */ ,
   kToken_TODO /* 76 */ } ;

//--- Key words table 'xmlDelimitorsList'
  public: static int32_t search_into_xmlDelimitorsList (const String & inSearchedString) ;

//--- Key words table 'keyWordList'
  public: static int32_t search_into_keyWordList (const String & inSearchedString) ;
  

//--- Assign from attribute
  public: GALGAS_lstring synthetizedAttribute_tokenString (void) const ;


//--- Attribute access
  public: String attributeValue_tokenString (void) const ;


//--- indexing keys

//--- Parse lexical token
  protected: void internalParseLexicalToken (cTokenFor_arxmlmetaparser_5F_scanner & token) ;
  protected: virtual bool parseLexicalToken (void) override ;

//--- Get terminal message
  protected: virtual String getMessageForTerminal (const int32_t inTerminalSymbol) const override ;

//--- Get terminal count
  public: virtual int32_t terminalVocabularyCount (void) const override { return 76 ; }

//--- Get Token String
  public: virtual String getCurrentTokenString (const cToken * inTokenPtr) const override ;

//--- Enter Token
  protected: void enterToken (cTokenFor_arxmlmetaparser_5F_scanner & ioToken) ;

//--- Style name for Latex
  protected: virtual String styleNameForIndex (const uint32_t inStyleIndex) const override ;
  protected: virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const override ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClassMap map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_arxmlMetaClassMap ;

//--------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_arxmlMetaClassMap_searchKey ;

//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClassMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClassMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_arxmlMetaClassMap (const GALGAS_arxmlMetaClassMap & inSource) ;
  public: GALGAS_arxmlMetaClassMap & operator = (const GALGAS_arxmlMetaClassMap & inSource) ;
  
//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClassMap extractObject (const GALGAS_object & inObject,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaClassMap class_func_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlMetaClassMap class_func_mapWithMapToOverride (const class GALGAS_arxmlMetaClassMap & inOperand0
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_arxmlMetaClass & inOperand1,
                                                     Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaClassMap add_operation (const GALGAS_arxmlMetaClassMap & inOperand,
                                                                   Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_arxmlMetaClass constinArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_arxmlMetaClass & outArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMTypeForKey (class GALGAS_arxmlMetaClass constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_arxmlMetaClass & outArgument1,
                                                  Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClass getter_mTypeForKey (const class GALGAS_string & constinOperand0,
                                                                           Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClassMap getter_overriddenMap (Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_arxmlMetaClass & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_arxmlMetaClassMap * readWriteAccessForWithInstruction (Compiler * inCompiler,
                                                                                              const GALGAS_string & inKey
                                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_arxmlMetaClassMap ;
 
} ; // End of GALGAS_arxmlMetaClassMap class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_arxmlMetaClassMap : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlMetaClassMap (const GALGAS_arxmlMetaClassMap & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_arxmlMetaClass current_mType (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlMetaClassMap_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClassMap ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClass  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClass : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClass (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlMetaClass * ptr (void) const {
    return (const cPtr_arxmlMetaClass *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlMetaClass (const cPtr_arxmlMetaClass * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_name (void) const ;

  public: class GALGAS_bool readProperty_isAbstract (void) const ;

  public: class GALGAS_arxmlMetaElementList readProperty_lElement (void) const ;

  public: class GALGAS_arxmlMetaElementList readProperty_lElementLegacy (void) const ;

  public: class GALGAS_arxmlMetaAttributeList readProperty_lAttribute (void) const ;

  public: class GALGAS_arxmlMetaAttributeList readProperty_lAttributeLegacy (void) const ;

  public: class GALGAS_lstring readProperty_desc (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClass extractObject (const GALGAS_object & inObject,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaClass class_func_new (const class GALGAS_lstring & inOperand0,
                                                             const class GALGAS_bool & inOperand1,
                                                             const class GALGAS_arxmlMetaElementList & inOperand2,
                                                             const class GALGAS_arxmlMetaElementList & inOperand3,
                                                             const class GALGAS_arxmlMetaAttributeList & inOperand4,
                                                             const class GALGAS_arxmlMetaAttributeList & inOperand5,
                                                             const class GALGAS_lstring & inOperand6
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaClass & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setDesc (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setIsAbstract (class GALGAS_bool inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLAttribute (class GALGAS_arxmlMetaAttributeList inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLAttributeLegacy (class GALGAS_arxmlMetaAttributeList inArgument0
                                                            COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLElement (class GALGAS_arxmlMetaElementList inArgument0
                                                    COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLElementLegacy (class GALGAS_arxmlMetaElementList inArgument0
                                                          COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setName (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaClass class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClass ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@arxmlMetaClassMap' map
//
//--------------------------------------------------------------------------------------------------

class cMapElement_arxmlMetaClassMap : public cMapElement {
//--- Map attributes
  public: GALGAS_arxmlMetaClass mProperty_mType ;

//--- Constructor
  public: cMapElement_arxmlMetaClassMap (const GALGAS_lstring & inKey,
                                         const GALGAS_arxmlMetaClass & in_mType
                                         COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cMapElement * copy (void) ;

//--- Description
 public: virtual void description (String & ioString, const int32_t inIndentation) const ;
} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClassMap_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClassMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_lstring mProperty_lkey ;
  public: inline GALGAS_lstring readProperty_lkey (void) const {
    return mProperty_lkey ;
  }

  public: GALGAS_arxmlMetaClass mProperty_mType ;
  public: inline GALGAS_arxmlMetaClass readProperty_mType (void) const {
    return mProperty_mType ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClassMap_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLkey (const GALGAS_lstring & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lkey = inValue ;
  }

  public: inline void setter_setMType (const GALGAS_arxmlMetaClass & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_mType = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlMetaClassMap_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlMetaClassMap_2D_element (const GALGAS_lstring & in_lkey,
                                               const GALGAS_arxmlMetaClass & in_mType) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClassMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaClassMap_2D_element class_func_new (const class GALGAS_lstring & inOperand0,
                                                                           const class GALGAS_arxmlMetaClass & inOperand1,
                                                                           class Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaClassMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaClassMap_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClassMap_2D_element ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClassMap addClassElement'
//
//--------------------------------------------------------------------------------------------------

void extensionSetter_addClassElement (class GALGAS_arxmlMetaClassMap & ioObject,
                                      class GALGAS_lstring in_className,
                                      class GALGAS_arxmlMetaElement in_mElement,
                                      class Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaAttributeList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaAttributeList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaAttributeList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_arxmlMetaAttributeList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_arxmlMetaAttribute & in_lAttribute
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaAttributeList extractObject (const GALGAS_object & inObject,
                                                              Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaAttributeList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlMetaAttributeList class_func_listWithValue (const class GALGAS_arxmlMetaAttribute & inOperand0
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_arxmlMetaAttributeList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_arxmlMetaAttribute & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaAttributeList add_operation (const GALGAS_arxmlMetaAttributeList & inOperand,
                                                                        Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_arxmlMetaAttribute constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_arxmlMetaAttribute constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_arxmlMetaAttribute & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_arxmlMetaAttribute & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_arxmlMetaAttribute & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLAttributeAtIndex (class GALGAS_arxmlMetaAttribute constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_arxmlMetaAttribute & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_arxmlMetaAttribute & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaAttribute getter_lAttributeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                     Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaAttributeList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaAttributeList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaAttributeList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                        Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_arxmlMetaAttributeList ;
 
} ; // End of GALGAS_arxmlMetaAttributeList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_arxmlMetaAttributeList : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlMetaAttributeList (const GALGAS_arxmlMetaAttributeList & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_arxmlMetaAttribute current_lAttribute (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlMetaAttributeList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaAttributeList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaElementList list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaElementList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaElementList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_arxmlMetaElementList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_arxmlMetaElement & in_lElement
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaElementList extractObject (const GALGAS_object & inObject,
                                                            Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaElementList class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlMetaElementList class_func_listWithValue (const class GALGAS_arxmlMetaElement & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_arxmlMetaElementList inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_arxmlMetaElement & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaElementList add_operation (const GALGAS_arxmlMetaElementList & inOperand,
                                                                      Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_arxmlMetaElement constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_arxmlMetaElement constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_arxmlMetaElement & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_arxmlMetaElement & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_arxmlMetaElement & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLElementAtIndex (class GALGAS_arxmlMetaElement constinArgument0,
                                                           class GALGAS_uint constinArgument1,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_arxmlMetaElement & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_arxmlMetaElement & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaElement getter_lElementAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                 Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaElementList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaElementList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaElementList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_arxmlMetaElementList ;
 
} ; // End of GALGAS_arxmlMetaElementList class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_arxmlMetaElementList : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlMetaElementList (const GALGAS_arxmlMetaElementList & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_arxmlMetaElement current_lElement (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlMetaElementList_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaElementList ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlMetaClass class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlMetaClass : public acPtr_class {

//--- Extension getter hasAttribute
  public: virtual class GALGAS_bool getter_hasAttribute (const class GALGAS_string attrName,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter hasElement
  public: virtual class GALGAS_bool getter_hasElement (const class GALGAS_string eleName,
           Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method display
  public: virtual void method_display (class GALGAS_arxmlMetaClassMap classMap,
           class GALGAS_string & ioString,
           Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_lstring mProperty_name ;
  public: GALGAS_bool mProperty_isAbstract ;
  public: GALGAS_arxmlMetaElementList mProperty_lElement ;
  public: GALGAS_arxmlMetaElementList mProperty_lElementLegacy ;
  public: GALGAS_arxmlMetaAttributeList mProperty_lAttribute ;
  public: GALGAS_arxmlMetaAttributeList mProperty_lAttributeLegacy ;
  public: GALGAS_lstring mProperty_desc ;

//--- Constructor
  public: cPtr_arxmlMetaClass (const GALGAS_lstring & in_name,
                               const GALGAS_bool & in_isAbstract,
                               const GALGAS_arxmlMetaElementList & in_lElement,
                               const GALGAS_arxmlMetaElementList & in_lElementLegacy,
                               const GALGAS_arxmlMetaAttributeList & in_lAttribute,
                               const GALGAS_arxmlMetaAttributeList & in_lAttributeLegacy,
                               const GALGAS_lstring & in_desc
                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_bool getter_isAbstract (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setIsAbstract (GALGAS_bool inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaElementList getter_lElement (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLElement (GALGAS_arxmlMetaElementList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaElementList getter_lElementLegacy (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLElementLegacy (GALGAS_arxmlMetaElementList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaAttributeList getter_lAttribute (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLAttribute (GALGAS_arxmlMetaAttributeList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaAttributeList getter_lAttributeLegacy (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setLAttributeLegacy (GALGAS_arxmlMetaAttributeList inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_desc (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setDesc (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaElement  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaElement : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaElement (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlMetaElement * ptr (void) const {
    return (const cPtr_arxmlMetaElement *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlMetaElement (const cPtr_arxmlMetaElement * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_name (void) const ;

  public: class GALGAS_lstring readProperty_type (void) const ;

  public: class GALGAS_lstring readProperty_minOccurs (void) const ;

  public: class GALGAS_lstring readProperty_maxOccurs (void) const ;

  public: class GALGAS_lstring readProperty_prefix (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaElement extractObject (const GALGAS_object & inObject,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaElement class_func_new (const class GALGAS_lstring & inOperand0,
                                                               const class GALGAS_lstring & inOperand1,
                                                               const class GALGAS_lstring & inOperand2,
                                                               const class GALGAS_lstring & inOperand3,
                                                               const class GALGAS_lstring & inOperand4
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaElement & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setMaxOccurs (class GALGAS_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMinOccurs (class GALGAS_lstring inArgument0
                                                     COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setName (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setPrefix (class GALGAS_lstring inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setType (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaElement class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaElement ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlMetaElement class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlMetaElement : public acPtr_class {


//--- Properties
  public: GALGAS_lstring mProperty_name ;
  public: GALGAS_lstring mProperty_type ;
  public: GALGAS_lstring mProperty_minOccurs ;
  public: GALGAS_lstring mProperty_maxOccurs ;
  public: GALGAS_lstring mProperty_prefix ;

//--- Constructor
  public: cPtr_arxmlMetaElement (const GALGAS_lstring & in_name,
                                 const GALGAS_lstring & in_type,
                                 const GALGAS_lstring & in_minOccurs,
                                 const GALGAS_lstring & in_maxOccurs,
                                 const GALGAS_lstring & in_prefix
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_type (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setType (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_minOccurs (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMinOccurs (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_maxOccurs (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setMaxOccurs (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setPrefix (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass addElement'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_addElement) (class cPtr_arxmlMetaClass * inObject,
                                                                    class GALGAS_arxmlMetaElement inArgument0,
                                                                    class Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_addElement (const int32_t inClassIndex,
                                      extensionSetterSignature_arxmlMetaClass_addElement inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_addElement (class cPtr_arxmlMetaClass * inObject,
                                     GALGAS_arxmlMetaElement in_mElement,
                                     Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClassMap addClassAttribute'
//
//--------------------------------------------------------------------------------------------------

void extensionSetter_addClassAttribute (class GALGAS_arxmlMetaClassMap & ioObject,
                                        class GALGAS_lstring in_className,
                                        class GALGAS_arxmlMetaAttribute in_mAttribute,
                                        class Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaAttribute  value class
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaAttribute : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaAttribute (void) ;

//--------------------------------- Embedded object pointer
  public: inline const class cPtr_arxmlMetaAttribute * ptr (void) const {
    return (const cPtr_arxmlMetaAttribute *) mObjectPtr ;
  }

//--------------------------------- Constructor from pointer
  public: GALGAS_arxmlMetaAttribute (const cPtr_arxmlMetaAttribute * inSourcePtr) ;

//--------------------------------- Property read access
  public: class GALGAS_lstring readProperty_name (void) const ;

  public: class GALGAS_lstring readProperty_type (void) const ;

  public: class GALGAS_lstring readProperty_prefix (void) const ;

  public: class GALGAS_lstring readProperty_use (void) const ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaAttribute extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaAttribute class_func_new (const class GALGAS_lstring & inOperand0,
                                                                 const class GALGAS_lstring & inOperand1,
                                                                 const class GALGAS_lstring & inOperand2,
                                                                 const class GALGAS_lstring & inOperand3
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaAttribute & inOperand) const ;

//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_setName (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setPrefix (class GALGAS_lstring inArgument0
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setType (class GALGAS_lstring inArgument0
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setUse (class GALGAS_lstring inArgument0
                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaAttribute class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaAttribute ;

//--------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlMetaAttribute class
//
//--------------------------------------------------------------------------------------------------

class cPtr_arxmlMetaAttribute : public acPtr_class {


//--- Properties
  public: GALGAS_lstring mProperty_name ;
  public: GALGAS_lstring mProperty_type ;
  public: GALGAS_lstring mProperty_prefix ;
  public: GALGAS_lstring mProperty_use ;

//--- Constructor
  public: cPtr_arxmlMetaAttribute (const GALGAS_lstring & in_name,
                                   const GALGAS_lstring & in_type,
                                   const GALGAS_lstring & in_prefix,
                                   const GALGAS_lstring & in_use
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_name (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_type (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setType (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_prefix (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setPrefix (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public: VIRTUAL_IN_DEBUG GALGAS_lstring getter_use (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setUse (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass addAttribute'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_addAttribute) (class cPtr_arxmlMetaClass * inObject,
                                                                      class GALGAS_arxmlMetaAttribute inArgument0,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_addAttribute (const int32_t inClassIndex,
                                        extensionSetterSignature_arxmlMetaClass_addAttribute inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_addAttribute (class cPtr_arxmlMetaClass * inObject,
                                       GALGAS_arxmlMetaAttribute in_mAttribute,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClassMap updateLegacyParameters'
//
//--------------------------------------------------------------------------------------------------

void extensionSetter_updateLegacyParameters (class GALGAS_arxmlMetaClassMap & ioObject,
                                             class GALGAS_lstring in_className,
                                             class GALGAS_arxmlMetaElementList in_lElement,
                                             class GALGAS_arxmlMetaAttributeList in_lAttribute,
                                             class Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass legacyUpdate'
//
//--------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_legacyUpdate) (class cPtr_arxmlMetaClass * inObject,
                                                                      class GALGAS_arxmlMetaElementList inArgument0,
                                                                      class GALGAS_arxmlMetaAttributeList inArgument1,
                                                                      class Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------

void enterExtensionSetter_legacyUpdate (const int32_t inClassIndex,
                                        extensionSetterSignature_arxmlMetaClass_legacyUpdate inModifier) ;

//--------------------------------------------------------------------------------------------------

void callExtensionSetter_legacyUpdate (class cPtr_arxmlMetaClass * inObject,
                                       GALGAS_arxmlMetaElementList in_iElement,
                                       GALGAS_arxmlMetaAttributeList in_iAttribute,
                                       Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaClassMap display'
//
//--------------------------------------------------------------------------------------------------

void extensionMethod_display (const class GALGAS_arxmlMetaClassMap inObject,
                              class GALGAS_string & io_ioString,
                              class Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaClass display'
//
//--------------------------------------------------------------------------------------------------

void callExtensionMethod_display (class cPtr_arxmlMetaClass * inObject,
                                  class GALGAS_arxmlMetaClassMap in_classMap,
                                  class GALGAS_string & io_ioString,
                                  Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClassGraph graph
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClassGraph : public AC_GALGAS_graph {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClassGraph (void) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClassGraph extractObject (const GALGAS_object & inObject,
                                                           Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaClassGraph class_func_emptyGraph (LOCATION_ARGS) ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_addNode (class GALGAS_lstring inArgument0,
                                                class GALGAS_lstring inArgument1,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_circularities (class GALGAS_lstringlist & outArgument0,
                                                      class GALGAS_lstringlist & outArgument1
                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_depthFirstTopologicalSort (class GALGAS_lstringlist & outArgument0,
                                                                  class GALGAS_lstringlist & outArgument1,
                                                                  class GALGAS_lstringlist & outArgument2,
                                                                  class GALGAS_lstringlist & outArgument3,
                                                                  Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_nodesWithNoPredecessor (class GALGAS_lstringlist & outArgument0,
                                                               class GALGAS_lstringlist & outArgument1
                                                               COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_nodesWithNoSuccessor (class GALGAS_lstringlist & outArgument0,
                                                             class GALGAS_lstringlist & outArgument1
                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_topologicalSort (class GALGAS_lstringlist & outArgument0,
                                                        class GALGAS_lstringlist & outArgument1,
                                                        class GALGAS_lstringlist & outArgument2,
                                                        class GALGAS_lstringlist & outArgument3,
                                                        Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_accessibleNodesFrom (const class GALGAS_lstringlist & constinOperand0,
                                                                                const class GALGAS_stringset & constinOperand1,
                                                                                Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_nodeList (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClassGraph getter_reversedGraph (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClassGraph getter_subgraphFromNodes (const class GALGAS_lstringlist & constinOperand0,
                                                                                      const class GALGAS_stringset & constinOperand1,
                                                                                      Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaClassGraph class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClassGraph ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClasslist list
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClasslist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClasslist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_arxmlMetaClasslist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_arxmlMetaClass & in_lClass
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClasslist extractObject (const GALGAS_object & inObject,
                                                          Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaClasslist class_func_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlMetaClasslist class_func_listWithValue (const class GALGAS_arxmlMetaClass & inOperand0
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_arxmlMetaClasslist inOperand,
                                                       class Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_arxmlMetaClass & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaClasslist add_operation (const GALGAS_arxmlMetaClasslist & inOperand,
                                                                    Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_arxmlMetaClass constinArgument0,
                                               Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_arxmlMetaClass constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_arxmlMetaClass & outArgument0,
                                                 Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_arxmlMetaClass & outArgument0,
                                                Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_arxmlMetaClass & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLClassAtIndex (class GALGAS_arxmlMetaClass constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_arxmlMetaClass & outArgument0,
                                              Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_arxmlMetaClass & outArgument0,
                                             Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClass getter_lClassAtIndex (const class GALGAS_uint & constinOperand0,
                                                                             Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClasslist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClasslist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                  Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClasslist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                    Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_arxmlMetaClasslist ;
 
} ; // End of GALGAS_arxmlMetaClasslist class

//--------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//--------------------------------------------------------------------------------------------------

class cEnumerator_arxmlMetaClasslist : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlMetaClasslist (const GALGAS_arxmlMetaClasslist & inEnumeratedObject,
                                          const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_arxmlMetaClass current_lClass (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlMetaClasslist_2D_element current (LOCATION_ARGS) const ;
} ;

//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClasslist ;

//--------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClasslist_2D_element struct
//
//--------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClasslist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_arxmlMetaClass mProperty_lClass ;
  public: inline GALGAS_arxmlMetaClass readProperty_lClass (void) const {
    return mProperty_lClass ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClasslist_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLClass (const GALGAS_arxmlMetaClass & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lClass = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlMetaClasslist_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlMetaClasslist_2D_element (const GALGAS_arxmlMetaClass & in_lClass) ;

//-- Start of type generic part

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClasslist_2D_element extractObject (const GALGAS_object & inObject,
                                                                     Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS class functions
  public: static class GALGAS_arxmlMetaClasslist_2D_element class_func_new (const class GALGAS_arxmlMetaClass & inOperand0,
                                                                            class Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (String & ioString,
                                             const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaClasslist_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaClasslist_2D_element class


//--------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClasslist_2D_element ;

