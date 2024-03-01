#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-2.h"

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClassMap map
//
//----------------------------------------------------------------------------------------------------------------------

class cMapElement_arxmlMetaClassMap ;

//----------------------------------------------------------------------------------------------------------------------

extern const char * kSearchErrorMessage_arxmlMetaClassMap_searchKey ;

//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClassMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClassMap (void) ;

//--------------------------------- Handle copy
  public: GALGAS_arxmlMetaClassMap (const GALGAS_arxmlMetaClassMap & inSource) ;
  public: GALGAS_arxmlMetaClassMap & operator = (const GALGAS_arxmlMetaClassMap & inSource) ;
  
//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClassMap extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaClassMap constructor_emptyMap (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlMetaClassMap constructor_mapWithMapToOverride (const class GALGAS_arxmlMetaClassMap & inOperand0
                                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                     const class GALGAS_arxmlMetaClass & inOperand1,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaClassMap add_operation (const GALGAS_arxmlMetaClassMap & inOperand,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_insertKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_arxmlMetaClass constinArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_arxmlMetaClass & outArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setMTypeForKey (class GALGAS_arxmlMetaClass constinArgument0,
                                                       class GALGAS_string constinArgument1,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_arxmlMetaClass & outArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClass getter_mTypeForKey (const class GALGAS_string & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClassMap getter_overriddenMap (C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_searchKey (const class GALGAS_string & constinOperand0,
                                                    class GALGAS_arxmlMetaClass & outOperand1) const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
  public: VIRTUAL_IN_DEBUG cMapElement_arxmlMetaClassMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                              const GALGAS_string & inKey
                                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_arxmlMetaClassMap ;
 
} ; // End of GALGAS_arxmlMetaClassMap class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_arxmlMetaClassMap : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlMetaClassMap (const GALGAS_arxmlMetaClassMap & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public: class GALGAS_arxmlMetaClass current_mType (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlMetaClassMap_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClassMap ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClass  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClass : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClass (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_arxmlMetaClass constructor_default (LOCATION_ARGS) ;

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

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClass extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaClass constructor_new (const class GALGAS_lstring & inOperand0,
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


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClass ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: class for element of '@arxmlMetaClassMap' map
//
//----------------------------------------------------------------------------------------------------------------------

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
 public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClassMap_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

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

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_arxmlMetaClassMap_2D_element constructor_default (LOCATION_ARGS) ;

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

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClassMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaClassMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                            const class GALGAS_arxmlMetaClass & inOperand1
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
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


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClassMap_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClassMap addClassElement'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_addClassElement (class GALGAS_arxmlMetaClassMap & ioObject,
                                      class GALGAS_lstring in_className,
                                      class GALGAS_arxmlMetaElement in_mElement,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaAttributeList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaAttributeList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaAttributeList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_arxmlMetaAttributeList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_arxmlMetaAttribute & in_lAttribute
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaAttributeList extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaAttributeList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlMetaAttributeList constructor_listWithValue (const class GALGAS_arxmlMetaAttribute & inOperand0
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_arxmlMetaAttributeList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_arxmlMetaAttribute & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaAttributeList add_operation (const GALGAS_arxmlMetaAttributeList & inOperand,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_arxmlMetaAttribute constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_arxmlMetaAttribute constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_arxmlMetaAttribute & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_arxmlMetaAttribute & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_arxmlMetaAttribute & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLAttributeAtIndex (class GALGAS_arxmlMetaAttribute constinArgument0,
                                                             class GALGAS_uint constinArgument1,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_arxmlMetaAttribute & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_arxmlMetaAttribute & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaAttribute getter_lAttributeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                     C_Compiler * inCompiler
                                                                                     COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaAttributeList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaAttributeList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaAttributeList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_arxmlMetaAttributeList ;
 
} ; // End of GALGAS_arxmlMetaAttributeList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_arxmlMetaAttributeList : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlMetaAttributeList (const GALGAS_arxmlMetaAttributeList & inEnumeratedObject,
                                              const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_arxmlMetaAttribute current_lAttribute (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlMetaAttributeList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaAttributeList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaElementList list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaElementList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaElementList (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_arxmlMetaElementList (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_arxmlMetaElement & in_lElement
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaElementList extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaElementList constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlMetaElementList constructor_listWithValue (const class GALGAS_arxmlMetaElement & inOperand0
                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_arxmlMetaElementList inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_arxmlMetaElement & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaElementList add_operation (const GALGAS_arxmlMetaElementList & inOperand,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_arxmlMetaElement constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_arxmlMetaElement constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_arxmlMetaElement & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_arxmlMetaElement & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_arxmlMetaElement & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLElementAtIndex (class GALGAS_arxmlMetaElement constinArgument0,
                                                           class GALGAS_uint constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_arxmlMetaElement & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_arxmlMetaElement & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaElement getter_lElementAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaElementList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaElementList getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaElementList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_arxmlMetaElementList ;
 
} ; // End of GALGAS_arxmlMetaElementList class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_arxmlMetaElementList : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlMetaElementList (const GALGAS_arxmlMetaElementList & inEnumeratedObject,
                                            const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_arxmlMetaElement current_lElement (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlMetaElementList_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaElementList ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlMetaClass class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_arxmlMetaClass : public acPtr_class {

//--- Extension getter hasAttribute
  public: virtual class GALGAS_bool getter_hasAttribute (const class GALGAS_string attrName,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter hasElement
  public: virtual class GALGAS_bool getter_hasElement (const class GALGAS_string eleName,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method display
  public: virtual void method_display (class GALGAS_arxmlMetaClassMap classMap,
           class GALGAS_string & ioString,
           C_Compiler * COMMA_LOCATION_ARGS) ;


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
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaElement  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaElement : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaElement (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_arxmlMetaElement constructor_default (LOCATION_ARGS) ;

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

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaElement extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaElement constructor_new (const class GALGAS_lstring & inOperand0,
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


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaElement ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlMetaElement class
//
//----------------------------------------------------------------------------------------------------------------------

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
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass addElement'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_addElement) (class cPtr_arxmlMetaClass * inObject,
                                                                    class GALGAS_arxmlMetaElement inArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_addElement (const int32_t inClassIndex,
                                      extensionSetterSignature_arxmlMetaClass_addElement inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addElement (class cPtr_arxmlMetaClass * inObject,
                                     GALGAS_arxmlMetaElement in_mElement,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClassMap addClassAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_addClassAttribute (class GALGAS_arxmlMetaClassMap & ioObject,
                                        class GALGAS_lstring in_className,
                                        class GALGAS_arxmlMetaAttribute in_mAttribute,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaAttribute  value class
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaAttribute : public AC_GALGAS_value_class {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaAttribute (void) ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_arxmlMetaAttribute constructor_default (LOCATION_ARGS) ;

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

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaAttribute extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaAttribute constructor_new (const class GALGAS_lstring & inOperand0,
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


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaAttribute ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @arxmlMetaAttribute class
//
//----------------------------------------------------------------------------------------------------------------------

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
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass addAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_addAttribute) (class cPtr_arxmlMetaClass * inObject,
                                                                      class GALGAS_arxmlMetaAttribute inArgument0,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_addAttribute (const int32_t inClassIndex,
                                        extensionSetterSignature_arxmlMetaClass_addAttribute inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addAttribute (class cPtr_arxmlMetaClass * inObject,
                                       GALGAS_arxmlMetaAttribute in_mAttribute,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClassMap updateLegacyParameters'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_updateLegacyParameters (class GALGAS_arxmlMetaClassMap & ioObject,
                                             class GALGAS_lstring in_className,
                                             class GALGAS_arxmlMetaElementList in_lElement,
                                             class GALGAS_arxmlMetaAttributeList in_lAttribute,
                                             class C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass legacyUpdate'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_arxmlMetaClass_legacyUpdate) (class cPtr_arxmlMetaClass * inObject,
                                                                      class GALGAS_arxmlMetaElementList inArgument0,
                                                                      class GALGAS_arxmlMetaAttributeList inArgument1,
                                                                      class C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_legacyUpdate (const int32_t inClassIndex,
                                        extensionSetterSignature_arxmlMetaClass_legacyUpdate inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_legacyUpdate (class cPtr_arxmlMetaClass * inObject,
                                       GALGAS_arxmlMetaElementList in_iElement,
                                       GALGAS_arxmlMetaAttributeList in_iAttribute,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaClassMap display'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_display (const class GALGAS_arxmlMetaClassMap inObject,
                              class GALGAS_string & io_ioString,
                              class C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaClass display'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_display (class cPtr_arxmlMetaClass * inObject,
                                  class GALGAS_arxmlMetaClassMap in_classMap,
                                  class GALGAS_string & io_ioString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClassGraph graph
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClassGraph : public AC_GALGAS_graph {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClassGraph (void) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClassGraph extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaClassGraph constructor_emptyGraph (LOCATION_ARGS) ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_addNode (class GALGAS_lstring inArgument0,
                                                class GALGAS_lstring inArgument1,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_circularities (class GALGAS_lstringlist & outArgument0,
                                                      class GALGAS_lstringlist & outArgument1
                                                      COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_depthFirstTopologicalSort (class GALGAS_lstringlist & outArgument0,
                                                                  class GALGAS_lstringlist & outArgument1,
                                                                  class GALGAS_lstringlist & outArgument2,
                                                                  class GALGAS_lstringlist & outArgument3,
                                                                  C_Compiler * inCompiler
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
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_accessibleNodesFrom (const class GALGAS_lstringlist & constinOperand0,
                                                                                const class GALGAS_stringset & constinOperand1,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_nodeList (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClassGraph getter_reversedGraph (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClassGraph getter_subgraphFromNodes (const class GALGAS_lstringlist & constinOperand0,
                                                                                      const class GALGAS_stringset & constinOperand1,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaClassGraph class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClassGraph ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClasslist list
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClasslist : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaClasslist (void) ;

//--------------------------------- List constructor used by listmap
  public: GALGAS_arxmlMetaClasslist (const capCollectionElementArray & inSharedArray) ;

//--------------------------------- Element constructor
  public: static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                 const class GALGAS_arxmlMetaClass & in_lClass
                                                 COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClasslist extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaClasslist constructor_emptyList (LOCATION_ARGS) ;

  public: static class GALGAS_arxmlMetaClasslist constructor_listWithValue (const class GALGAS_arxmlMetaClass & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public: VIRTUAL_IN_DEBUG void plusAssign_operation (const GALGAS_arxmlMetaClasslist inOperand,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public: VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_arxmlMetaClass & inOperand0
                                                     COMMA_LOCATION_ARGS) ;
//--------------------------------- + operator
  public: VIRTUAL_IN_DEBUG GALGAS_arxmlMetaClasslist add_operation (const GALGAS_arxmlMetaClasslist & inOperand,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public: VIRTUAL_IN_DEBUG void setter_append (class GALGAS_arxmlMetaClass constinArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_insertAtIndex (class GALGAS_arxmlMetaClass constinArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popFirst (class GALGAS_arxmlMetaClass & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_popLast (class GALGAS_arxmlMetaClass & outArgument0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_removeAtIndex (class GALGAS_arxmlMetaClass & outArgument0,
                                                      class GALGAS_uint constinArgument1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

  public: VIRTUAL_IN_DEBUG void setter_setLClassAtIndex (class GALGAS_arxmlMetaClass constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public: VIRTUAL_IN_DEBUG void method_first (class GALGAS_arxmlMetaClass & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG void method_last (class GALGAS_arxmlMetaClass & outArgument0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClass getter_lClassAtIndex (const class GALGAS_uint & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClasslist getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClasslist getter_subListToIndex (const class GALGAS_uint & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_arxmlMetaClasslist getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
//--------------------------------- Friend

  friend class cEnumerator_arxmlMetaClasslist ;
 
} ; // End of GALGAS_arxmlMetaClasslist class

//----------------------------------------------------------------------------------------------------------------------
//   Enumerator declaration                                                                      
//----------------------------------------------------------------------------------------------------------------------

class cEnumerator_arxmlMetaClasslist : public cGenericAbstractEnumerator {
  public: cEnumerator_arxmlMetaClasslist (const GALGAS_arxmlMetaClasslist & inEnumeratedObject,
                                          const typeEnumerationOrder inOrder) ;

//--- Current element access
  public: class GALGAS_arxmlMetaClass current_lClass (LOCATION_ARGS) const ;
//--- Current element access
  public: class GALGAS_arxmlMetaClasslist_2D_element current (LOCATION_ARGS) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClasslist ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaClasslist_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaClasslist_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_arxmlMetaClass mProperty_lClass ;
  public: inline GALGAS_arxmlMetaClass readProperty_lClass (void) const {
    return mProperty_lClass ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_arxmlMetaClasslist_2D_element constructor_default (LOCATION_ARGS) ;

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

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaClasslist_2D_element extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaClasslist_2D_element constructor_new (const class GALGAS_arxmlMetaClass & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
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


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaClasslist_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaElementList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaElementList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_arxmlMetaElement mProperty_lElement ;
  public: inline GALGAS_arxmlMetaElement readProperty_lElement (void) const {
    return mProperty_lElement ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_arxmlMetaElementList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaElementList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLElement (const GALGAS_arxmlMetaElement & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lElement = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlMetaElementList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlMetaElementList_2D_element (const GALGAS_arxmlMetaElement & in_lElement) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaElementList_2D_element extractObject (const GALGAS_object & inObject,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaElementList_2D_element constructor_new (const class GALGAS_arxmlMetaElement & inOperand0
                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaElementList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaElementList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaElementList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 1: @arxmlMetaAttributeList_2D_element struct
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_arxmlMetaAttributeList_2D_element : public AC_GALGAS_root {
//--------------------------------- Properties
  public: GALGAS_arxmlMetaAttribute mProperty_lAttribute ;
  public: inline GALGAS_arxmlMetaAttribute readProperty_lAttribute (void) const {
    return mProperty_lAttribute ;
  }

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG bool isValid (void) const override ;
  public: VIRTUAL_IN_DEBUG void drop (void) override ;

//--------------------------------- Default GALGAS constructor
  public: static GALGAS_arxmlMetaAttributeList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public: GALGAS_arxmlMetaAttributeList_2D_element (void) ;

//--------------------------------- Property setters
  public: inline void setter_setLAttribute (const GALGAS_arxmlMetaAttribute & inValue COMMA_UNUSED_LOCATION_ARGS) {
    mProperty_lAttribute = inValue ;
  }

//--------------------------------- Virtual destructor (in debug mode)
  public: virtual ~ GALGAS_arxmlMetaAttributeList_2D_element (void) ;

//--------------------------------- Native constructor
  public: GALGAS_arxmlMetaAttributeList_2D_element (const GALGAS_arxmlMetaAttribute & in_lAttribute) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_arxmlMetaAttributeList_2D_element extractObject (const GALGAS_object & inObject,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_arxmlMetaAttributeList_2D_element constructor_new (const class GALGAS_arxmlMetaAttribute & inOperand0
                                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_arxmlMetaAttributeList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Optional Methods

//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_arxmlMetaAttributeList_2D_element class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_arxmlMetaAttributeList_2D_element ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaElementList string' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string extensionGetter_string (const class GALGAS_arxmlMetaElementList & inObject,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaAttributeList string' (as function)
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string extensionGetter_string (const class GALGAS_arxmlMetaAttributeList & inObject,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//                                            Phase 1: @restrictionType enum                                           *
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_restrictionType : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public: GALGAS_restrictionType (void) ;

//--------------------------------- Enumeration
  public: typedef enum {
    kNotBuilt,
    kEnum_restrictionSimple,
    kEnum_restrictionEnum,
    kEnum_restrictionOther,
    kEnum_restrictionUnused
  } enumeration ;
  
//--------------------------------- Private data member
  private: enumeration mEnum ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return kNotBuilt != mEnum ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mEnum = kNotBuilt ; }
  public: inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_restrictionType extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_restrictionType constructor_restrictionEnum (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionType constructor_restrictionOther (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionType constructor_restrictionSimple (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionType constructor_restrictionUnused (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_restrictionType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionEnum (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionOther (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionSimple (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionUnused (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_restrictionEnum () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionOther () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionSimple () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionUnused () const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_restrictionType class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_restrictionType ;

//----------------------------------------------------------------------------------------------------------------------
//
//                                          Phase 1: @restrictionBaseType enum                                         *
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_restrictionBaseType : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public: GALGAS_restrictionBaseType (void) ;

//--------------------------------- Enumeration
  public: typedef enum {
    kNotBuilt,
    kEnum_restrictionString,
    kEnum_restrictionUint,
    kEnum_restrictionDouble,
    kEnum_restrictionUndef
  } enumeration ;
  
//--------------------------------- Private data member
  private: enumeration mEnum ;

//--------------------------------- Accessors
  public: VIRTUAL_IN_DEBUG inline bool isValid (void) const override { return kNotBuilt != mEnum ; }
  public: VIRTUAL_IN_DEBUG inline void drop (void) override { mEnum = kNotBuilt ; }
  public: inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected: virtual AC_GALGAS_root * clonedObject (void) const override ;

//--------------------------------- Object extraction
  public: static GALGAS_restrictionBaseType extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public: static class GALGAS_restrictionBaseType constructor_restrictionDouble (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionBaseType constructor_restrictionString (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionBaseType constructor_restrictionUint (LOCATION_ARGS) ;

  public: static class GALGAS_restrictionBaseType constructor_restrictionUndef (LOCATION_ARGS) ;

//--------------------------------- Implementation of getter 'description'
  public: VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const override ;
//--------------------------------- Comparison
  public: typeComparisonResult objectCompare (const GALGAS_restrictionBaseType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionDouble (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionString (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionUint (LOCATION_ARGS) const ;

  public: VIRTUAL_IN_DEBUG class GALGAS_bool getter_isRestrictionUndef (LOCATION_ARGS) const ;


//--------------------------------- Optional Methods
  public: VIRTUAL_IN_DEBUG bool optional_restrictionDouble () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionString () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionUint () const ;

  public: VIRTUAL_IN_DEBUG bool optional_restrictionUndef () const ;


//--------------------------------- Introspection
  public: VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const override ;
 
} ; // End of GALGAS_restrictionBaseType class


//----------------------------------------------------------------------------------------------------------------------

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_restrictionBaseType ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlTemplate execute'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_execute (class cPtr_gtlTemplate * inObject,
                                  class GALGAS_gtlContext & io_context,
                                  class GALGAS_gtlData & io_vars,
                                  class GALGAS_library & io_lib,
                                  class GALGAS_string & io_outputString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library functionExists'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_functionExists (const cPtr_library * inObject,
                                                      const class GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library getFunction'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlFunction callExtensionGetter_getFunction (const cPtr_library * inObject,
                                                          const class GALGAS_lstring constin_name,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library putFunction'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_putFunction) (class cPtr_library * inObject,
                                                              const class GALGAS_lstring constinArgument0,
                                                              const class GALGAS_gtlFunction constinArgument1,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_putFunction (const int32_t inClassIndex,
                                       extensionSetterSignature_library_putFunction inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_putFunction (class cPtr_library * inObject,
                                      const GALGAS_lstring constin_name,
                                      const GALGAS_gtlFunction constin_aFunction,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library getterExists'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_getterExists (const cPtr_library * inObject,
                                                    const class GALGAS_string constin_type,
                                                    const class GALGAS_lstring constin_name,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library getGetter'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlGetter callExtensionGetter_getGetter (const cPtr_library * inObject,
                                                      const class GALGAS_string constin_type,
                                                      const class GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlGetter class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlGetter : public cPtr_gtlFunction {

//--- Extension getter callGetter
  public: virtual class GALGAS_gtlData getter_callGetter (const class GALGAS_location fromLocation,
           const class GALGAS_gtlContext context,
           const class GALGAS_library lib,
           const class GALGAS_gtlData target,
           const class GALGAS_gtlDataList actualArguments,
           C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension getter typedName
  public: virtual class GALGAS_lstring getter_typedName (C_Compiler * COMMA_LOCATION_ARGS) const ;


//--- Properties
  public: GALGAS_type mProperty_targetType ;

//--- Constructor
  public: cPtr_gtlGetter (const GALGAS_location & in_where,
                          const GALGAS_lstring & in_name,
                          const GALGAS_gtlArgumentList & in_formalArguments,
                          const GALGAS_gtlInstructionList & in_instructions,
                          const GALGAS_lstring & in_returnVariable,
                          const GALGAS_type & in_targetType
                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_type getter_targetType (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTargetType (GALGAS_type inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library putGetter'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_putGetter) (class cPtr_library * inObject,
                                                            const class GALGAS_lstring constinArgument0,
                                                            const class GALGAS_gtlGetter constinArgument1,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_putGetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putGetter inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_putGetter (class cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlGetter constin_aGetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library setterExists'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_setterExists (const cPtr_library * inObject,
                                                    const class GALGAS_string constin_type,
                                                    const class GALGAS_lstring constin_name,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library getSetter'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlSetter callExtensionGetter_getSetter (const cPtr_library * inObject,
                                                      const class GALGAS_string constin_type,
                                                      const class GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
// Phase 2: pointer class for @gtlSetter class
//
//----------------------------------------------------------------------------------------------------------------------

class cPtr_gtlSetter : public cPtr_gtlExecutableEntity {

//--- Extension getter typedName
  public: virtual class GALGAS_lstring getter_typedName (C_Compiler * COMMA_LOCATION_ARGS) const ;

//--- Extension method callSetter
  public: virtual void method_callSetter (const class GALGAS_location fromLocation,
           class GALGAS_gtlContext context,
           class GALGAS_library lib,
           class GALGAS_gtlData & target,
           const class GALGAS_gtlDataList actualArguments,
           C_Compiler * COMMA_LOCATION_ARGS) ;


//--- Properties
  public: GALGAS_type mProperty_targetType ;

//--- Constructor
  public: cPtr_gtlSetter (const GALGAS_location & in_where,
                          const GALGAS_lstring & in_name,
                          const GALGAS_gtlArgumentList & in_formalArguments,
                          const GALGAS_gtlInstructionList & in_instructions,
                          const GALGAS_type & in_targetType
                          COMMA_LOCATION_ARGS) ;

//--- Duplication
  public: virtual acPtr_class * duplicate (LOCATION_ARGS) const override ;

//--- Attribute accessors
  public: VIRTUAL_IN_DEBUG GALGAS_type getter_targetType (LOCATION_ARGS) const ;
  public: VIRTUAL_IN_DEBUG void setter_setTargetType (GALGAS_type inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public: virtual void description (C_String & ioString,
                                    const int32_t inIndentation) const override ;

  public: virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const override ;

  public: virtual const C_galgas_type_descriptor * classDescriptor (void) const override ;

} ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library putSetter'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_putSetter) (class cPtr_library * inObject,
                                                            const class GALGAS_lstring constinArgument0,
                                                            const class GALGAS_gtlSetter constinArgument1,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_putSetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putSetter inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_putSetter (class cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlSetter constin_aSetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library hasImport'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasImport (const cPtr_library * inObject,
                                                 const class GALGAS_string constin_importPath,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library doImport'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_doImport) (class cPtr_library * inObject,
                                                           const class GALGAS_string constinArgument0,
                                                           class C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_doImport (const int32_t inClassIndex,
                                    extensionSetterSignature_library_doImport inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_doImport (class cPtr_library * inObject,
                                   const GALGAS_string constin_importPath,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library getTemplate'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_library_getTemplate) (class cPtr_library * inObject,
                                                              const class GALGAS_gtlContext constinArgument0,
                                                              class GALGAS_lstring inArgument1,
                                                              class GALGAS_bool inArgument2,
                                                              class GALGAS_library & ioArgument3,
                                                              class GALGAS_bool & outArgument4,
                                                              class GALGAS_gtlTemplate & outArgument5,
                                                              class C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_getTemplate (const int32_t inClassIndex,
                                       extensionSetterSignature_library_getTemplate inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_getTemplate (class cPtr_library * inObject,
                                      const GALGAS_gtlContext constin_context,
                                      GALGAS_lstring in_path,
                                      GALGAS_bool in_ifExists,
                                      GALGAS_library & io_lib,
                                      GALGAS_bool & out_found,
                                      GALGAS_gtlTemplate & out_result,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlVarItemField lstringPath'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_lstringPath (const cPtr_gtlVarItemField * inObject,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlExpression location'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_location callExtensionGetter_location (const cPtr_gtlExpression * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_eval (const class cPtr_gtlExpression * inObject,
                                               const class GALGAS_gtlContext constin_context,
                                               const class GALGAS_gtlData constin_vars,
                                               const class GALGAS_library constin_lib,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData string'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_string callExtensionGetter_string (const class cPtr_gtlData * inObject,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData lstring'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_lstring callExtensionGetter_lstring (const class cPtr_gtlData * inObject,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData int'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bigint callExtensionGetter_int (const class cPtr_gtlData * inObject,
                                             class C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData float'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_double callExtensionGetter_float (const class cPtr_gtlData * inObject,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_plusOp (const class cPtr_gtlData * inObject,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_minusOp (const class cPtr_gtlData * inObject,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData notOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_notOp (const class cPtr_gtlData * inObject,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData addOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_addOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData subOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_subOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_mulOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData divOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_divOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData modOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_modOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData andOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_andOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData orOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_orOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_xorOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData slOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_slOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData srOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_srOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_neqOp (const class cPtr_gtlData * inObject,
                                                const class GALGAS_gtlData constin_right,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_eqOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData leOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_leOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData geOp'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_geOp (const class cPtr_gtlData * inObject,
                                               const class GALGAS_gtlData constin_right,
                                               class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_type callExtensionGetter_embeddedType (const class cPtr_gtlData * inObject,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlData addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_addMyValue (class cPtr_gtlData * inObject,
                                     class GALGAS_objectlist & io_objectList,
                                     class C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_performGetter (const class cPtr_gtlData * inObject,
                                                        const class GALGAS_lstring constin_methodName,
                                                        const class GALGAS_gtlDataList constin_arguments,
                                                        const class GALGAS_gtlContext constin_context,
                                                        const class GALGAS_library constin_lib,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension setter '@gtlData performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_performSetter) (class cPtr_gtlData * inObject,
                                                                const class GALGAS_lstring constinArgument0,
                                                                const class GALGAS_gtlDataList constinArgument1,
                                                                const class GALGAS_gtlContext constinArgument2,
                                                                const class GALGAS_library constinArgument3,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_performSetter (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_performSetter inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_performSetter (class cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_methodName,
                                        const GALGAS_gtlDataList constin_arguments,
                                        const GALGAS_gtlContext constin_context,
                                        const GALGAS_library constin_lib,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlData structField'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_structField (class cPtr_gtlData * inObject,
                                      const class GALGAS_lstring constin_name,
                                      class GALGAS_gtlData & out_result,
                                      class GALGAS_bool & out_found,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData resultField'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlData callExtensionGetter_resultField (const cPtr_gtlData * inObject,
                                                      const class GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setStructFieldAtLevel'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_setStructFieldAtLevel) (class cPtr_gtlData * inObject,
                                                                        const class GALGAS_lstring constinArgument0,
                                                                        const class GALGAS_gtlData constinArgument1,
                                                                        const class GALGAS_uint constinArgument2,
                                                                        class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setStructFieldAtLevel (const int32_t inClassIndex,
                                                 extensionSetterSignature_gtlData_setStructFieldAtLevel inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setStructFieldAtLevel (class cPtr_gtlData * inObject,
                                                const GALGAS_lstring constin_name,
                                                const GALGAS_gtlData constin_data,
                                                const GALGAS_uint constin_level,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData deleteStructField'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_deleteStructField) (class cPtr_gtlData * inObject,
                                                                    const class GALGAS_lstring constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteStructField (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteStructField inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteStructField (class cPtr_gtlData * inObject,
                                            const GALGAS_lstring constin_name,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData hasStructField'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasStructField (const cPtr_gtlData * inObject,
                                                      const class GALGAS_lstring constin_name,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData overrideMap'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlStruct callExtensionGetter_overrideMap (const cPtr_gtlData * inObject,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData overriddenMap'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_gtlStruct callExtensionGetter_overriddenMap (const cPtr_gtlData * inObject,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlData mapItem'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_mapItem (class cPtr_gtlData * inObject,
                                  const class GALGAS_lstring constin_name,
                                  class GALGAS_gtlData & out_result,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData hasMapItem'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasMapItem (const cPtr_gtlData * inObject,
                                                  const class GALGAS_lstring constin_name,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setMapItem'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_setMapItem) (class cPtr_gtlData * inObject,
                                                             const class GALGAS_lstring constinArgument0,
                                                             const class GALGAS_gtlData constinArgument1,
                                                             class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setMapItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_setMapItem inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setMapItem (class cPtr_gtlData * inObject,
                                     const GALGAS_lstring constin_name,
                                     const GALGAS_gtlData constin_data,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData deleteMapItem'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_deleteMapItem) (class cPtr_gtlData * inObject,
                                                                const class GALGAS_lstring constinArgument0,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteMapItem (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_deleteMapItem inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteMapItem (class cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_name,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlData itemAtIndex'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_itemAtIndex (class cPtr_gtlData * inObject,
                                      class GALGAS_gtlData & out_result,
                                      const class GALGAS_gtlInt constin_index,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData hasItemAtIndex'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_bool callExtensionGetter_hasItemAtIndex (const cPtr_gtlData * inObject,
                                                      const class GALGAS_gtlInt constin_index,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setItemAtIndex'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_setItemAtIndex) (class cPtr_gtlData * inObject,
                                                                 const class GALGAS_gtlData constinArgument0,
                                                                 const class GALGAS_gtlInt constinArgument1,
                                                                 class C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setItemAtIndex (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlData_setItemAtIndex inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setItemAtIndex (class cPtr_gtlData * inObject,
                                         const GALGAS_gtlData constin_data,
                                         const GALGAS_gtlInt constin_index,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData deleteItemAtIndex'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_deleteItemAtIndex) (class cPtr_gtlData * inObject,
                                                                    const class GALGAS_gtlInt constinArgument0,
                                                                    class C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteItemAtIndex (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteItemAtIndex inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteItemAtIndex (class cPtr_gtlData * inObject,
                                            const GALGAS_gtlInt constin_index,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData appendItem'
//
//----------------------------------------------------------------------------------------------------------------------

typedef void (*extensionSetterSignature_gtlData_appendItem) (class cPtr_gtlData * inObject,
                                                             const class GALGAS_gtlData constinArgument0,
                                                             class C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_appendItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_appendItem inModifier) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_appendItem (class cPtr_gtlData * inObject,
                                     const GALGAS_gtlData constin_item,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

