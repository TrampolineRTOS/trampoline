#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-3.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@arxmlElementValueList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_arxmlElementValueList : public cCollectionElement {
  public: GALGAS_arxmlElementValueList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_arxmlElementValueList (const GALGAS_arxmlElementValue & in_value
                                                    COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_arxmlElementValueList (const GALGAS_arxmlElementValueList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlElementValueList::cCollectionElement_arxmlElementValueList (const GALGAS_arxmlElementValue & in_value
                                                                                    COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlElementValueList::cCollectionElement_arxmlElementValueList (const GALGAS_arxmlElementValueList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_value) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_arxmlElementValueList::isValid (void) const {
  return true ; // return mObject.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_arxmlElementValueList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_arxmlElementValueList (mObject.mProperty_value COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_arxmlElementValueList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "value" ":" ;
  mObject.mProperty_value.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_arxmlElementValueList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_arxmlElementValueList * operand = (cCollectionElement_arxmlElementValueList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_arxmlElementValueList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList::GALGAS_arxmlElementValueList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList::GALGAS_arxmlElementValueList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlElementValueList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::constructor_listWithValue (const GALGAS_arxmlElementValue & inOperand0
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlElementValueList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_arxmlElementValueList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                              const GALGAS_arxmlElementValue & in_value
                                                              COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlElementValueList * p = NULL ;
  macroMyNew (p, cCollectionElement_arxmlElementValueList (in_value COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::addAssign_operation (const GALGAS_arxmlElementValue & inOperand0
                                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlElementValueList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{ // Destroy receiver
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_append (GALGAS_arxmlElementValueList_2D_element inElement,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inElement.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlElementValueList (inElement COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_insertAtIndex (const GALGAS_arxmlElementValue inOperand0,
                                                         const GALGAS_uint inInsertionIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlElementValueList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_removeAtIndex (GALGAS_arxmlElementValue & outOperand0,
                                                         const GALGAS_uint inRemoveIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
      if (NULL == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
        outOperand0 = p->mObject.mProperty_value ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_popFirst (GALGAS_arxmlElementValue & outOperand0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_popLast (GALGAS_arxmlElementValue & outOperand0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::method_first (GALGAS_arxmlElementValue & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::method_last (GALGAS_arxmlElementValue & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    outOperand0 = p->mObject.mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::add_operation (const GALGAS_arxmlElementValueList & inOperand,
                                                                          C_Compiler * /* inCompiler */
                                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueList result = GALGAS_arxmlElementValueList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueList result = GALGAS_arxmlElementValueList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueList result = GALGAS_arxmlElementValueList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::plusAssign_operation (const GALGAS_arxmlElementValueList inOperand,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList::setter_setValueAtIndex (GALGAS_arxmlElementValue inOperand,
                                                           GALGAS_uint inIndex,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_value = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValue GALGAS_arxmlElementValueList::getter_valueAtIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlElementValueList * p = (cCollectionElement_arxmlElementValueList *) attributes.ptr () ;
  GALGAS_arxmlElementValue result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
    result = p->mObject.mProperty_value ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlElementValueList::cEnumerator_arxmlElementValueList (const GALGAS_arxmlElementValueList & inEnumeratedObject,
                                                                      const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList_2D_element cEnumerator_arxmlElementValueList::current (LOCATION_ARGS) const {
  const cCollectionElement_arxmlElementValueList * p = (const cCollectionElement_arxmlElementValueList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValue cEnumerator_arxmlElementValueList::current_value (LOCATION_ARGS) const {
  const cCollectionElement_arxmlElementValueList * p = (const cCollectionElement_arxmlElementValueList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlElementValueList) ;
  return p->mObject.mProperty_value ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlElementValueList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValueList ("arxmlElementValueList",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementValueList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValueList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementValueList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementValueList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueList::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList result ;
  const GALGAS_arxmlElementValueList * p = (const GALGAS_arxmlElementValueList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlElementValueList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementValueList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     L E X I Q U E                                                                             
//
//----------------------------------------------------------------------------------------------------------------------

#include "strings/unicode_character_cpp.h"
#include "galgas2/scanner_actions.h"
#include "galgas2/cLexiqueIntrospection.h"

//----------------------------------------------------------------------------------------------------------------------

cTokenFor_arxmlmetaparser_5F_scanner::cTokenFor_arxmlmetaparser_5F_scanner (void) :
mLexicalAttribute_tokenString () {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_arxmlmetaparser_5F_scanner::C_Lexique_arxmlmetaparser_5F_scanner (C_Compiler * inCallerCompiler,
                                                                            const C_String & inSourceFileName
                                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceFileName COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//----------------------------------------------------------------------------------------------------------------------

C_Lexique_arxmlmetaparser_5F_scanner::C_Lexique_arxmlmetaparser_5F_scanner (C_Compiler * inCallerCompiler,
                                                                            const C_String & inSourceString,
                                                                            const C_String & inStringForError
                                                                            COMMA_LOCATION_ARGS) :
C_Lexique (inCallerCompiler, inSourceString, inStringForError COMMA_THERE),
mMatchedTemplateDelimiterIndex (-1) {
}

//----------------------------------------------------------------------------------------------------------------------
//                        Lexical error message list                                             
//----------------------------------------------------------------------------------------------------------------------

static const char * gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectAttributeEnd = "attribute value should be enclosed between apostrophes (') or quotation marks (\")" ;

static const char * gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectCommentError = "incorrect XML comment" ;

//----------------------------------------------------------------------------------------------------------------------
//          Syntax error messages, for every terminal symbol                                     
//----------------------------------------------------------------------------------------------------------------------

//--- Syntax error message for terminal '$comment$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_comment = "a comment" ;

//--- Syntax error message for terminal '$xmlTag$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_xmlTag = "a name" ;

//--- Syntax error message for terminal '$xmlTagValue$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_xmlTagValue = "an attribute value" ;

//--- Syntax error message for terminal '$identifier$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_identifier = "an identifier" ;

//--- Syntax error message for terminal '$<$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C_ = "the '<' delimitor" ;

//--- Syntax error message for terminal '$<xsd:$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C_xsd_3A_ = "the '<xsd:' delimitor" ;

//--- Syntax error message for terminal '$</xsd:$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C__2F_xsd_3A_ = "the '</xsd:' delimitor" ;

//--- Syntax error message for terminal '$<?xml$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C__3F_xml = "the '<\?xml' delimitor" ;

//--- Syntax error message for terminal '$>$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3E_ = "the '>' delimitor" ;

//--- Syntax error message for terminal '$?>$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3F__3E_ = "the '\?>' delimitor" ;

//--- Syntax error message for terminal '$/>$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__2F__3E_ = "the '/>' delimitor" ;

//--- Syntax error message for terminal '$</$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C__2F_ = "the '</' delimitor" ;

//--- Syntax error message for terminal '$=$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3D_ = "the '=' delimitor" ;

//--- Syntax error message for terminal '$group$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_group = "the 'group' keyword" ;

//--- Syntax error message for terminal '$annotation$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_annotation = "the 'annotation' keyword" ;

//--- Syntax error message for terminal '$appinfo$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_appinfo = "the 'appinfo' keyword" ;

//--- Syntax error message for terminal '$attribute$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_attribute = "the 'attribute' keyword" ;

//--- Syntax error message for terminal '$attributeGroup$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_attributeGroup = "the 'attributeGroup' keyword" ;

//--- Syntax error message for terminal '$choice$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_choice = "the 'choice' keyword" ;

//--- Syntax error message for terminal '$complexType$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_complexType = "the 'complexType' keyword" ;

//--- Syntax error message for terminal '$documentation$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_documentation = "the 'documentation' keyword" ;

//--- Syntax error message for terminal '$element$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_element = "the 'element' keyword" ;

//--- Syntax error message for terminal '$enumeration$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_enumeration = "the 'enumeration' keyword" ;

//--- Syntax error message for terminal '$extension$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_extension = "the 'extension' keyword" ;

//--- Syntax error message for terminal '$import$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_import = "the 'import' keyword" ;

//--- Syntax error message for terminal '$maxLength$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_maxLength = "the 'maxLength' keyword" ;

//--- Syntax error message for terminal '$pattern$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_pattern = "the 'pattern' keyword" ;

//--- Syntax error message for terminal '$restriction$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_restriction = "the 'restriction' keyword" ;

//--- Syntax error message for terminal '$schema$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_schema = "the 'schema' keyword" ;

//--- Syntax error message for terminal '$sequence$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_sequence = "the 'sequence' keyword" ;

//--- Syntax error message for terminal '$simpleContent$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_simpleContent = "the 'simpleContent' keyword" ;

//--- Syntax error message for terminal '$simpleType$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_simpleType = "the 'simpleType' keyword" ;

//--- Syntax error message for terminal '$whiteSpace$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_whiteSpace = "the 'whiteSpace' keyword" ;

//--- Syntax error message for terminal '$abstract$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_abstract = "the 'abstract' keyword" ;

//--- Syntax error message for terminal '$attributeFormDefault$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_attributeFormDefault = "the 'attributeFormDefault' keyword" ;

//--- Syntax error message for terminal '$attributeRef$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_attributeRef = "the 'attributeRef' keyword" ;

//--- Syntax error message for terminal '$base$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_base = "the 'base' keyword" ;

//--- Syntax error message for terminal '$category$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_category = "the 'category' keyword" ;

//--- Syntax error message for terminal '$CATEGORY$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_CATEGORY = "the 'CATEGORY' keyword" ;

//--- Syntax error message for terminal '$color$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_color = "the 'color' keyword" ;

//--- Syntax error message for terminal '$customType$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_customType = "the 'customType' keyword" ;

//--- Syntax error message for terminal '$elementFormDefault$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_elementFormDefault = "the 'elementFormDefault' keyword" ;

//--- Syntax error message for terminal '$encoding$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_encoding = "the 'encoding' keyword" ;

//--- Syntax error message for terminal '$enforceMinMultiplicity$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_enforceMinMultiplicity = "the 'enforceMinMultiplicity' keyword" ;

//--- Syntax error message for terminal '$globalElement$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_globalElement = "the 'globalElement' keyword" ;

//--- Syntax error message for terminal '$id$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_id = "the 'id' keyword" ;

//--- Syntax error message for terminal '$latestBindingTime$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_latestBindingTime = "the 'latestBindingTime' keyword" ;

//--- Syntax error message for terminal '$maxOccurs$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_maxOccurs = "the 'maxOccurs' keyword" ;

//--- Syntax error message for terminal '$minOccurs$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_minOccurs = "the 'minOccurs' keyword" ;

//--- Syntax error message for terminal '$mixed$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_mixed = "the 'mixed' keyword" ;

//--- Syntax error message for terminal '$name$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_name = "the 'name' keyword" ;

//--- Syntax error message for terminal '$namePlural$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_namePlural = "the 'namePlural' keyword" ;

//--- Syntax error message for terminal '$namespace$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_namespace = "the 'namespace' keyword" ;

//--- Syntax error message for terminal '$noteType$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_noteType = "the 'noteType' keyword" ;

//--- Syntax error message for terminal '$nsPrefix$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_nsPrefix = "the 'nsPrefix' keyword" ;

//--- Syntax error message for terminal '$qualifiedName$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_qualifiedName = "the 'qualifiedName' keyword" ;

//--- Syntax error message for terminal '$recommendedPackage$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_recommendedPackage = "the 'recommendedPackage' keyword" ;

//--- Syntax error message for terminal '$ref$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_ref = "the 'ref' keyword" ;

//--- Syntax error message for terminal '$roleElement$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_roleElement = "the 'roleElement' keyword" ;

//--- Syntax error message for terminal '$roleWrapperElement$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_roleWrapperElement = "the 'roleWrapperElement' keyword" ;

//--- Syntax error message for terminal '$schemaLocation$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_schemaLocation = "the 'schemaLocation' keyword" ;

//--- Syntax error message for terminal '$sequenceOffset$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_sequenceOffset = "the 'sequenceOffset' keyword" ;

//--- Syntax error message for terminal '$source$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_source = "the 'source' keyword" ;

//--- Syntax error message for terminal '$Splitkey$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_Splitkey = "the 'Splitkey' keyword" ;

//--- Syntax error message for terminal '$Status$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_Status = "the 'Status' keyword" ;

//--- Syntax error message for terminal '$StatusRevisionBegin$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_StatusRevisionBegin = "the 'StatusRevisionBegin' keyword" ;

//--- Syntax error message for terminal '$targetNamespace$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_targetNamespace = "the 'targetNamespace' keyword" ;

//--- Syntax error message for terminal '$type$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_type = "the 'type' keyword" ;

//--- Syntax error message for terminal '$typeElement$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_typeElement = "the 'typeElement' keyword" ;

//--- Syntax error message for terminal '$typeWrapperElement$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_typeWrapperElement = "the 'typeWrapperElement' keyword" ;

//--- Syntax error message for terminal '$use$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_use = "the 'use' keyword" ;

//--- Syntax error message for terminal '$value$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_value = "the 'value' keyword" ;

//--- Syntax error message for terminal '$version$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_version = "the 'version' keyword" ;

//--- Syntax error message for terminal '$xmlns:AR$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_xmlns_3A_AR = "the 'xmlns:AR' keyword" ;

//--- Syntax error message for terminal '$xmlns:xsd$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_xmlns_3A_xsd = "the 'xmlns:xsd' keyword" ;

//--- Syntax error message for terminal '$TODO$' :
static const char * gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_TODO = "the 'TODO' keyword" ;

//----------------------------------------------------------------------------------------------------------------------
//                getMessageForTerminal                                                          
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxmlmetaparser_5F_scanner::getMessageForTerminal (const int16_t inTerminalIndex) const {
  C_String result = "<unknown>" ;
  if ((inTerminalIndex >= 0) && (inTerminalIndex < 77)) {
    static const char * syntaxErrorMessageArray [77] = {kEndOfSourceLexicalErrorMessage,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_comment,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_xmlTag,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_xmlTagValue,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_identifier,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C_,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C_xsd_3A_,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C__2F_xsd_3A_,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C__3F_xml,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3E_,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3F__3E_,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__2F__3E_,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3C__2F_,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner__3D_,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_group,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_annotation,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_appinfo,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_attribute,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_attributeGroup,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_choice,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_complexType,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_documentation,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_element,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_enumeration,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_extension,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_import,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_maxLength,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_pattern,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_restriction,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_schema,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_sequence,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_simpleContent,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_simpleType,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_whiteSpace,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_abstract,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_attributeFormDefault,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_attributeRef,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_base,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_category,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_CATEGORY,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_color,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_customType,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_elementFormDefault,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_encoding,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_enforceMinMultiplicity,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_globalElement,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_id,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_latestBindingTime,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_maxOccurs,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_minOccurs,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_mixed,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_name,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_namePlural,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_namespace,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_noteType,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_nsPrefix,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_qualifiedName,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_recommendedPackage,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_ref,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_roleElement,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_roleWrapperElement,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_schemaLocation,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_sequenceOffset,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_source,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_Splitkey,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_Status,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_StatusRevisionBegin,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_targetNamespace,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_type,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_typeElement,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_typeWrapperElement,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_use,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_value,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_version,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_xmlns_3A_AR,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_xmlns_3A_xsd,
        gSyntaxErrorMessage_arxmlmetaparser_5F_scanner_TODO
    } ;
    result = syntaxErrorMessageArray [inTerminalIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                      U N I C O D E    S T R I N G S                                           
//----------------------------------------------------------------------------------------------------------------------

//--- Unicode string for '$_22_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__22_ [] = {
  TO_UNICODE ('\"'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26__23_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26__23_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('#'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_amp_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_apos_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('s'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_gt_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('g'),
  TO_UNICODE ('t'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_lt_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_26_quot_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_ [] = {
  TO_UNICODE ('&'),
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_27_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__27_ [] = {
  TO_UNICODE ('\''),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2D__2D__3E_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__2D__2D__3E_ [] = {
  TO_UNICODE ('-'),
  TO_UNICODE ('-'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_2F__3E_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__2F__3E_ [] = {
  TO_UNICODE ('/'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3B_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3B_ [] = {
  TO_UNICODE (';'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__21__2D__2D_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C__21__2D__2D_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('!'),
  TO_UNICODE ('-'),
  TO_UNICODE ('-'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__2F_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('/'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__2F_xsd_3A_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_xsd_3A_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('/'),
  TO_UNICODE ('x'),
  TO_UNICODE ('s'),
  TO_UNICODE ('d'),
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C__3F_xml$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C__3F_xml [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('\?'),
  TO_UNICODE ('x'),
  TO_UNICODE ('m'),
  TO_UNICODE ('l'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3C_xsd_3A_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3C_xsd_3A_ [] = {
  TO_UNICODE ('<'),
  TO_UNICODE ('x'),
  TO_UNICODE ('s'),
  TO_UNICODE ('d'),
  TO_UNICODE (':'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3D_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3D_ [] = {
  TO_UNICODE ('='),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3E_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3E_ [] = {
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$_3F__3E_$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner__3F__3E_ [] = {
  TO_UNICODE ('\?'),
  TO_UNICODE ('>'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$CATEGORY$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_CATEGORY [] = {
  TO_UNICODE ('C'),
  TO_UNICODE ('A'),
  TO_UNICODE ('T'),
  TO_UNICODE ('E'),
  TO_UNICODE ('G'),
  TO_UNICODE ('O'),
  TO_UNICODE ('R'),
  TO_UNICODE ('Y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$Splitkey$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_Splitkey [] = {
  TO_UNICODE ('S'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('k'),
  TO_UNICODE ('e'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$Status$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_Status [] = {
  TO_UNICODE ('S'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('u'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$StatusRevisionBegin$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_StatusRevisionBegin [] = {
  TO_UNICODE ('S'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('u'),
  TO_UNICODE ('s'),
  TO_UNICODE ('R'),
  TO_UNICODE ('e'),
  TO_UNICODE ('v'),
  TO_UNICODE ('i'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('B'),
  TO_UNICODE ('e'),
  TO_UNICODE ('g'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$TODO$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_TODO [] = {
  TO_UNICODE ('T'),
  TO_UNICODE ('O'),
  TO_UNICODE ('D'),
  TO_UNICODE ('O'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$abstract$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_abstract [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('b'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$annotation$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_annotation [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('n'),
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$appinfo$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_appinfo [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('p'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$attribute$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_attribute [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$attributeFormDefault$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_attributeFormDefault [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('F'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('m'),
  TO_UNICODE ('D'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$attributeGroup$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_attributeGroup [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('G'),
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('u'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$attributeRef$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_attributeRef [] = {
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('b'),
  TO_UNICODE ('u'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('R'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$base$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_base [] = {
  TO_UNICODE ('b'),
  TO_UNICODE ('a'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$category$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_category [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('g'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$choice$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_choice [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE ('o'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$color$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_color [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('l'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$complexType$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_complexType [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('T'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$customType$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_customType [] = {
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE ('T'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$documentation$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_documentation [] = {
  TO_UNICODE ('d'),
  TO_UNICODE ('o'),
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$element$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_element [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$elementFormDefault$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_elementFormDefault [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('F'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('m'),
  TO_UNICODE ('D'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('a'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$encoding$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_encoding [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('d'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$enforceMinMultiplicity$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_enforceMinMultiplicity [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('f'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE ('M'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('M'),
  TO_UNICODE ('u'),
  TO_UNICODE ('l'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$enumeration$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_enumeration [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('u'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$extension$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_extension [] = {
  TO_UNICODE ('e'),
  TO_UNICODE ('x'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$globalElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_globalElement [] = {
  TO_UNICODE ('g'),
  TO_UNICODE ('l'),
  TO_UNICODE ('o'),
  TO_UNICODE ('b'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$group$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_group [] = {
  TO_UNICODE ('g'),
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('u'),
  TO_UNICODE ('p'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$id$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_id [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$import$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_import [] = {
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('o'),
  TO_UNICODE ('r'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$latestBindingTime$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_latestBindingTime [] = {
  TO_UNICODE ('l'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('B'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE ('T'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$maxLength$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_maxLength [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('x'),
  TO_UNICODE ('L'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('g'),
  TO_UNICODE ('t'),
  TO_UNICODE ('h'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$maxOccurs$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_maxOccurs [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('x'),
  TO_UNICODE ('O'),
  TO_UNICODE ('c'),
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$minOccurs$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_minOccurs [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('n'),
  TO_UNICODE ('O'),
  TO_UNICODE ('c'),
  TO_UNICODE ('c'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('s'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$mixed$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_mixed [] = {
  TO_UNICODE ('m'),
  TO_UNICODE ('i'),
  TO_UNICODE ('x'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$name$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_name [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$namePlural$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_namePlural [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('P'),
  TO_UNICODE ('l'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$namespace$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_namespace [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('p'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$noteType$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_noteType [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('o'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('T'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$nsPrefix$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_nsPrefix [] = {
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE ('P'),
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('x'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$pattern$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_pattern [] = {
  TO_UNICODE ('p'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$qualifiedName$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_qualifiedName [] = {
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('i'),
  TO_UNICODE ('f'),
  TO_UNICODE ('i'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE ('N'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$recommendedPackage$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_recommendedPackage [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('c'),
  TO_UNICODE ('o'),
  TO_UNICODE ('m'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('d'),
  TO_UNICODE ('e'),
  TO_UNICODE ('d'),
  TO_UNICODE ('P'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('k'),
  TO_UNICODE ('a'),
  TO_UNICODE ('g'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$ref$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_ref [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('f'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$restriction$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_restriction [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('t'),
  TO_UNICODE ('r'),
  TO_UNICODE ('i'),
  TO_UNICODE ('c'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$roleElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_roleElement [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$roleWrapperElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_roleWrapperElement [] = {
  TO_UNICODE ('r'),
  TO_UNICODE ('o'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('W'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$schema$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_schema [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$schemaLocation$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_schemaLocation [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('c'),
  TO_UNICODE ('h'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('a'),
  TO_UNICODE ('L'),
  TO_UNICODE ('o'),
  TO_UNICODE ('c'),
  TO_UNICODE ('a'),
  TO_UNICODE ('t'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$sequence$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_sequence [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$sequenceOffset$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_sequenceOffset [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('q'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE ('O'),
  TO_UNICODE ('f'),
  TO_UNICODE ('f'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$simpleContent$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_simpleContent [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('C'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$simpleType$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_simpleType [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('m'),
  TO_UNICODE ('p'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('T'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$source$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_source [] = {
  TO_UNICODE ('s'),
  TO_UNICODE ('o'),
  TO_UNICODE ('u'),
  TO_UNICODE ('r'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$targetNamespace$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_targetNamespace [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('a'),
  TO_UNICODE ('r'),
  TO_UNICODE ('g'),
  TO_UNICODE ('e'),
  TO_UNICODE ('t'),
  TO_UNICODE ('N'),
  TO_UNICODE ('a'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('s'),
  TO_UNICODE ('p'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$type$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_type [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$typeElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_typeElement [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$typeWrapperElement$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_typeWrapperElement [] = {
  TO_UNICODE ('t'),
  TO_UNICODE ('y'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('W'),
  TO_UNICODE ('r'),
  TO_UNICODE ('a'),
  TO_UNICODE ('p'),
  TO_UNICODE ('p'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('E'),
  TO_UNICODE ('l'),
  TO_UNICODE ('e'),
  TO_UNICODE ('m'),
  TO_UNICODE ('e'),
  TO_UNICODE ('n'),
  TO_UNICODE ('t'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$use$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_use [] = {
  TO_UNICODE ('u'),
  TO_UNICODE ('s'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$value$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_value [] = {
  TO_UNICODE ('v'),
  TO_UNICODE ('a'),
  TO_UNICODE ('l'),
  TO_UNICODE ('u'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$version$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_version [] = {
  TO_UNICODE ('v'),
  TO_UNICODE ('e'),
  TO_UNICODE ('r'),
  TO_UNICODE ('s'),
  TO_UNICODE ('i'),
  TO_UNICODE ('o'),
  TO_UNICODE ('n'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$whiteSpace$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_whiteSpace [] = {
  TO_UNICODE ('w'),
  TO_UNICODE ('h'),
  TO_UNICODE ('i'),
  TO_UNICODE ('t'),
  TO_UNICODE ('e'),
  TO_UNICODE ('S'),
  TO_UNICODE ('p'),
  TO_UNICODE ('a'),
  TO_UNICODE ('c'),
  TO_UNICODE ('e'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$xmlns_3A_AR$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_xmlns_3A_AR [] = {
  TO_UNICODE ('x'),
  TO_UNICODE ('m'),
  TO_UNICODE ('l'),
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE (':'),
  TO_UNICODE ('A'),
  TO_UNICODE ('R'),
  TO_UNICODE (0)
} ;

//--- Unicode string for '$xmlns_3A_xsd$'
static const utf32 kUnicodeString_arxmlmetaparser_5F_scanner_xmlns_3A_xsd [] = {
  TO_UNICODE ('x'),
  TO_UNICODE ('m'),
  TO_UNICODE ('l'),
  TO_UNICODE ('n'),
  TO_UNICODE ('s'),
  TO_UNICODE (':'),
  TO_UNICODE ('x'),
  TO_UNICODE ('s'),
  TO_UNICODE ('d'),
  TO_UNICODE (0)
} ;

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'keyWordList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_arxmlmetaparser_5F_scanner_keyWordList = 63 ;

static const C_unicode_lexique_table_entry ktable_for_arxmlmetaparser_5F_scanner_keyWordList [ktable_size_arxmlmetaparser_5F_scanner_keyWordList] = {
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_id, 2, C_Lexique_arxmlmetaparser_5F_scanner::kToken_id),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_ref, 3, C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_use, 3, C_Lexique_arxmlmetaparser_5F_scanner::kToken_use),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_TODO, 4, C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_base, 4, C_Lexique_arxmlmetaparser_5F_scanner::kToken_base),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_name, 4, C_Lexique_arxmlmetaparser_5F_scanner::kToken_name),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_type, 4, C_Lexique_arxmlmetaparser_5F_scanner::kToken_type),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_color, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken_color),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_group, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken_group),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_mixed, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_value, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken_value),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_Status, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_Status),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_choice, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_import, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_import),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_schema, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_source, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken_source),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_appinfo, 7, C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_element, 7, C_Lexique_arxmlmetaparser_5F_scanner::kToken_element),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_pattern, 7, C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_version, 7, C_Lexique_arxmlmetaparser_5F_scanner::kToken_version),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_CATEGORY, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_CATEGORY),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_Splitkey, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_Splitkey),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_abstract, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_category, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_category),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_encoding, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_encoding),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_noteType, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_noteType),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_nsPrefix, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_nsPrefix),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_sequence, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_xmlns_3A_AR, 8, C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_AR),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_attribute, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_extension, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_maxLength, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_maxOccurs, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_minOccurs, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_namespace, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_namespace),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_xmlns_3A_xsd, 9, C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_xsd),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_annotation, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_customType, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_customType),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_namePlural, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_namePlural),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_simpleType, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_whiteSpace, 10, C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_complexType, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_enumeration, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_restriction, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_roleElement, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_typeElement, 11, C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_attributeRef, 12, C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeRef),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_documentation, 13, C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_globalElement, 13, C_Lexique_arxmlmetaparser_5F_scanner::kToken_globalElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_qualifiedName, 13, C_Lexique_arxmlmetaparser_5F_scanner::kToken_qualifiedName),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_simpleContent, 13, C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_attributeGroup, 14, C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_schemaLocation, 14, C_Lexique_arxmlmetaparser_5F_scanner::kToken_schemaLocation),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_sequenceOffset, 14, C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequenceOffset),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_targetNamespace, 15, C_Lexique_arxmlmetaparser_5F_scanner::kToken_targetNamespace),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_latestBindingTime, 17, C_Lexique_arxmlmetaparser_5F_scanner::kToken_latestBindingTime),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_elementFormDefault, 18, C_Lexique_arxmlmetaparser_5F_scanner::kToken_elementFormDefault),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_recommendedPackage, 18, C_Lexique_arxmlmetaparser_5F_scanner::kToken_recommendedPackage),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_roleWrapperElement, 18, C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleWrapperElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_typeWrapperElement, 18, C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeWrapperElement),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_StatusRevisionBegin, 19, C_Lexique_arxmlmetaparser_5F_scanner::kToken_StatusRevisionBegin),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_attributeFormDefault, 20, C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeFormDefault),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner_enforceMinMultiplicity, 22, C_Lexique_arxmlmetaparser_5F_scanner::kToken_enforceMinMultiplicity)
} ;

int16_t C_Lexique_arxmlmetaparser_5F_scanner::search_into_keyWordList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_arxmlmetaparser_5F_scanner_keyWordList, ktable_size_arxmlmetaparser_5F_scanner_keyWordList) ;
}

//----------------------------------------------------------------------------------------------------------------------
//             Key words table 'xmlDelimitorsList'      
//----------------------------------------------------------------------------------------------------------------------

static const int32_t ktable_size_arxmlmetaparser_5F_scanner_xmlDelimitorsList = 9 ;

static const C_unicode_lexique_table_entry ktable_for_arxmlmetaparser_5F_scanner_xmlDelimitorsList [ktable_size_arxmlmetaparser_5F_scanner_xmlDelimitorsList] = {
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C_, 1, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3D_, 1, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3E_, 1, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__2F__3E_, 2, C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_, 2, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3F__3E_, 2, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3F__3E_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C__3F_xml, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__3F_xml),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C_xsd_3A_, 5, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_),
  C_unicode_lexique_table_entry (kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_xsd_3A_, 6, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_)
} ;

int16_t C_Lexique_arxmlmetaparser_5F_scanner::search_into_xmlDelimitorsList (const C_String & inSearchedString) {
  return searchInList (inSearchedString, ktable_for_arxmlmetaparser_5F_scanner_xmlDelimitorsList, ktable_size_arxmlmetaparser_5F_scanner_xmlDelimitorsList) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                          getCurrentTokenString                                                
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxmlmetaparser_5F_scanner::getCurrentTokenString (const cToken * inTokenPtr) const {
  const cTokenFor_arxmlmetaparser_5F_scanner * ptr = (const cTokenFor_arxmlmetaparser_5F_scanner *) inTokenPtr ;
  C_String s ;
  if (ptr == NULL) {
    s.appendCString("$$") ;
  }else{
    switch (ptr->mTokenCode) {
    case kToken_:
      s.appendCString("$$") ;
      break ;
    case kToken_comment:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("comment") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_xmlTag:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("xmlTag") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_xmlTagValue:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("xmlTagValue") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken_identifier:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("identifier") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendUnicodeCharacter (TO_UNICODE (' ') COMMA_HERE) ;
      s.appendCLiteralStringConstant (ptr->mLexicalAttribute_tokenString) ;
      break ;
    case kToken__3C_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C_xsd_3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<xsd:") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__2F_xsd_3A_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("</xsd:") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__3F_xml:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("<\?xml") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString (">") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3F__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("\?>") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__2F__3E_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("/>") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3C__2F_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("</") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken__3D_:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("=") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_group:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("group") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_annotation:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("annotation") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_appinfo:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("appinfo") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_attribute:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("attribute") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_attributeGroup:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("attributeGroup") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_choice:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("choice") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_complexType:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("complexType") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_documentation:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("documentation") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_element:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("element") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_enumeration:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("enumeration") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_extension:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("extension") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_import:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("import") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_maxLength:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("maxLength") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_pattern:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("pattern") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_restriction:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("restriction") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_schema:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("schema") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_sequence:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("sequence") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_simpleContent:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("simpleContent") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_simpleType:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("simpleType") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_whiteSpace:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("whiteSpace") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_abstract:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("abstract") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_attributeFormDefault:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("attributeFormDefault") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_attributeRef:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("attributeRef") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_base:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("base") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_category:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("category") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_CATEGORY:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("CATEGORY") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_color:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("color") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_customType:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("customType") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_elementFormDefault:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("elementFormDefault") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_encoding:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("encoding") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_enforceMinMultiplicity:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("enforceMinMultiplicity") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_globalElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("globalElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_id:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("id") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_latestBindingTime:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("latestBindingTime") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_maxOccurs:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("maxOccurs") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_minOccurs:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("minOccurs") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_mixed:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("mixed") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_name:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("name") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_namePlural:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("namePlural") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_namespace:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("namespace") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_noteType:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("noteType") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_nsPrefix:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("nsPrefix") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_qualifiedName:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("qualifiedName") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_recommendedPackage:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("recommendedPackage") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_ref:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("ref") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_roleElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("roleElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_roleWrapperElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("roleWrapperElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_schemaLocation:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("schemaLocation") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_sequenceOffset:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("sequenceOffset") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_source:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("source") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_Splitkey:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("Splitkey") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_Status:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("Status") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_StatusRevisionBegin:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("StatusRevisionBegin") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_targetNamespace:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("targetNamespace") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_type:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("type") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_typeElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("typeElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_typeWrapperElement:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("typeWrapperElement") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_use:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("use") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_value:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("value") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_version:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("version") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_xmlns_3A_AR:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("xmlns:AR") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_xmlns_3A_xsd:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("xmlns:xsd") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    case kToken_TODO:
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      s.appendCString ("TODO") ;
      s.appendUnicodeCharacter (TO_UNICODE ('$') COMMA_HERE) ;
      break ;
    default:
      break ;
    }
  }
  return s ;
}

//----------------------------------------------------------------------------------------------------------------------
//                           Template Delimiters                                                 
//----------------------------------------------------------------------------------------------------------------------

static const cTemplateDelimiter arxmlmetaparser_5F_scanner_kTemplateDefinitionArray [1] = {
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__3C_, 1, NULL, 0, NULL, false)
} ;

//----------------------------------------------------------------------------------------------------------------------
//                           Template Replacements                                               
//----------------------------------------------------------------------------------------------------------------------

static const cTemplateDelimiter arxmlmetaparser_5F_scanner_kTemplateReplacementArray [6] = {
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_, 5, kUnicodeString_arxmlmetaparser_5F_scanner__26_, 1, NULL, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_, 4, kUnicodeString_arxmlmetaparser_5F_scanner__3C_, 1, NULL, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_, 4, kUnicodeString_arxmlmetaparser_5F_scanner__3E_, 1, NULL, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_, 6, kUnicodeString_arxmlmetaparser_5F_scanner__22_, 1, NULL, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_, 6, kUnicodeString_arxmlmetaparser_5F_scanner__27_, 1, NULL, true),
  cTemplateDelimiter (kUnicodeString_arxmlmetaparser_5F_scanner__26__23_, 2, kUnicodeString_arxmlmetaparser_5F_scanner__3B_, 1, scanner_routine_codePointToUnicode, true)
} ;

//----------------------------------------------------------------------------------------------------------------------
//            Terminal Symbols as end of script in template mark                                 
//----------------------------------------------------------------------------------------------------------------------

static const bool arxmlmetaparser_5F_scanner_kEndOfScriptInTemplateArray [76] = {
  true /* comment */,
  false /* xmlTag */,
  false /* xmlTagValue */,
  false /* identifier */,
  false /* < */,
  false /* <xsd: */,
  false /* </xsd: */,
  false /* <?xml */,
  true /* > */,
  true /* ?> */,
  true /* /> */,
  false /* </ */,
  false /* = */,
  false /* group */,
  false /* annotation */,
  false /* appinfo */,
  false /* attribute */,
  false /* attributeGroup */,
  false /* choice */,
  false /* complexType */,
  false /* documentation */,
  false /* element */,
  false /* enumeration */,
  false /* extension */,
  false /* import */,
  false /* maxLength */,
  false /* pattern */,
  false /* restriction */,
  false /* schema */,
  false /* sequence */,
  false /* simpleContent */,
  false /* simpleType */,
  false /* whiteSpace */,
  false /* abstract */,
  false /* attributeFormDefault */,
  false /* attributeRef */,
  false /* base */,
  false /* category */,
  false /* CATEGORY */,
  false /* color */,
  false /* customType */,
  false /* elementFormDefault */,
  false /* encoding */,
  false /* enforceMinMultiplicity */,
  false /* globalElement */,
  false /* id */,
  false /* latestBindingTime */,
  false /* maxOccurs */,
  false /* minOccurs */,
  false /* mixed */,
  false /* name */,
  false /* namePlural */,
  false /* namespace */,
  false /* noteType */,
  false /* nsPrefix */,
  false /* qualifiedName */,
  false /* recommendedPackage */,
  false /* ref */,
  false /* roleElement */,
  false /* roleWrapperElement */,
  false /* schemaLocation */,
  false /* sequenceOffset */,
  false /* source */,
  false /* Splitkey */,
  false /* Status */,
  false /* StatusRevisionBegin */,
  false /* targetNamespace */,
  false /* type */,
  false /* typeElement */,
  false /* typeWrapperElement */,
  false /* use */,
  false /* value */,
  false /* version */,
  false /* xmlns:AR */,
  false /* xmlns:xsd */,
  false /* TODO */
} ;

//----------------------------------------------------------------------------------------------------------------------
//               INTERNAL PARSE LEXICAL TOKEN                                         
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_arxmlmetaparser_5F_scanner::internalParseLexicalToken (cTokenFor_arxmlmetaparser_5F_scanner & token) {
  bool loop = true ;
  token.mLexicalAttribute_tokenString.setLengthToZero () ;
  mTokenStartLocation = mCurrentLocation ;
  try{
    if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C__21__2D__2D_, 4, true)) {
      do {
        if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_, 5, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('&')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('<')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('>')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\"')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\'')) ;
        }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (',')) || testForInputUTF32CharRange (TO_UNICODE ('.'), TO_UNICODE (1114111))) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else if (notTestForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__2D__2D__3E_, 3, gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectCommentError COMMA_LINE_AND_SOURCE_FILE)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('-')) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      enterDroppedTerminal (kToken_comment) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_xsd_3A_, 6, true)) {
      token.mTokenCode = kToken__3C__2F_xsd_3A_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C_xsd_3A_, 5, true)) {
      token.mTokenCode = kToken__3C_xsd_3A_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C__3F_xml, 5, true)) {
      token.mTokenCode = kToken__3C__3F_xml ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3F__3E_, 2, true)) {
      token.mTokenCode = kToken__3F__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C__2F_, 2, true)) {
      token.mTokenCode = kToken__3C__2F_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__2F__3E_, 2, true)) {
      token.mTokenCode = kToken__2F__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3E_, 1, true)) {
      token.mTokenCode = kToken__3E_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3D_, 1, true)) {
      token.mTokenCode = kToken__3D_ ;
      enterToken (token) ;
    }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__3C_, 1, true)) {
      token.mTokenCode = kToken__3C_ ;
      enterToken (token) ;
    }else if (testForCharWithFunction (isUnicodeLetter)) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        if (testForCharWithFunction (isUnicodeLetter) || testForInputUTF32CharRange (TO_UNICODE ('0'), TO_UNICODE ('9')) || testForInputUTF32Char (TO_UNICODE ('-')) || testForInputUTF32Char (TO_UNICODE (':'))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_keyWordList (token.mLexicalAttribute_tokenString) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = kToken_xmlTag ;
      }
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('\"'))) {
      do {
        if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_, 5, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('&')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('<')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('>')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\"')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\'')) ;
        }else if (notTestForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__22_, 1, gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectAttributeEnd COMMA_LINE_AND_SOURCE_FILE)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_xmlTagValue ;
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('\''))) {
      do {
        if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_amp_3B_, 5, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('&')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_lt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('<')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_gt_3B_, 4, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('>')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_quot_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\"')) ;
        }else if (testForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__26_apos_3B_, 6, true)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, TO_UNICODE ('\'')) ;
        }else if (notTestForInputUTF32String (kUnicodeString_arxmlmetaparser_5F_scanner__27_, 1, gLexicalMessage_arxmlmetaparser_5F_scanner_incorrectAttributeEnd COMMA_LINE_AND_SOURCE_FILE)) {
          ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      token.mTokenCode = kToken_xmlTagValue ;
      enterToken (token) ;
    }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (' '))) {
    }else if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (';')) || testForInputUTF32CharRange (TO_UNICODE ('='), TO_UNICODE (1114111))) {
      do {
        ::scanner_routine_enterCharacterIntoString (*this, token.mLexicalAttribute_tokenString, previousChar ()) ;
        if (testForInputUTF32CharRange (TO_UNICODE (1), TO_UNICODE (';')) || testForInputUTF32CharRange (TO_UNICODE ('='), TO_UNICODE (1114111))) {
        }else{
          loop = false ;
        }
      }while (loop) ;
      loop = true ;
      if (token.mTokenCode == -1) {
        token.mTokenCode = search_into_keyWordList (token.mLexicalAttribute_tokenString) ;
      }
      if (token.mTokenCode == -1) {
        token.mTokenCode = kToken_identifier ;
      }
      enterToken (token) ;
    }else if (testForInputUTF32Char (TO_UNICODE ('\0'))) { // End of source text ? 
      token.mTokenCode = kToken_ ; // Empty string code
    }else{ // Unknown input character
      unknownCharacterLexicalError (LINE_AND_SOURCE_FILE) ;
      token.mTokenCode = -1 ; // No token
      advance () ; // ... go throught unknown character
    }
  }catch (const C_lexicalErrorException &) {
    token.mTokenCode = -1 ; // No token
    advance () ; // ... go throught unknown character
  }
}

//----------------------------------------------------------------------------------------------------------------------
//               P A R S E    L E X I C A L    T O K E N                                         
//----------------------------------------------------------------------------------------------------------------------

bool C_Lexique_arxmlmetaparser_5F_scanner::parseLexicalToken (void) {
  cTokenFor_arxmlmetaparser_5F_scanner token ;
  token.mTokenCode = -1 ;
  while ((token.mTokenCode < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
    if ((mMatchedTemplateDelimiterIndex >= 0)
     && (arxmlmetaparser_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength > 0)
     && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      const bool foundEndDelimitor = testForInputUTF32String (arxmlmetaparser_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndString,
                                                              arxmlmetaparser_5F_scanner_kTemplateDefinitionArray [mMatchedTemplateDelimiterIndex].mEndStringLength,
                                                              true) ;
      if (foundEndDelimitor) {
        mMatchedTemplateDelimiterIndex = -1 ;
      }
    }
    while ((mMatchedTemplateDelimiterIndex < 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      int32_t replacementIndex = 0 ;
      while (replacementIndex >= 0) {
        replacementIndex = findTemplateDelimiterIndex (arxmlmetaparser_5F_scanner_kTemplateReplacementArray, 6) ;
        if (replacementIndex >= 0) {
          if (arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mReplacementFunction == NULL) {
            token.mTemplateStringBeforeToken << arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndString ;
          }else{
            C_String s ;
            while (notTestForInputUTF32String (arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndString,
                                               arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mEndStringLength,
                                               kEndOfSourceLexicalErrorMessage
                                               COMMA_HERE)) {
              s.appendUnicodeCharacter (previousChar () COMMA_HERE) ;
            }
            arxmlmetaparser_5F_scanner_kTemplateReplacementArray [replacementIndex].mReplacementFunction (*this, s, token.mTemplateStringBeforeToken) ;
          }
        }
      }
      mMatchedTemplateDelimiterIndex = findTemplateDelimiterIndex (arxmlmetaparser_5F_scanner_kTemplateDefinitionArray, 1) ;
      if (mMatchedTemplateDelimiterIndex < 0) {
        token.mTemplateStringBeforeToken.appendUnicodeCharacter (mCurrentChar COMMA_HERE) ;
        advance () ;
      }
    }
    if ((mMatchedTemplateDelimiterIndex >= 0) && (UNICODE_VALUE (mCurrentChar) != '\0')) {
      internalParseLexicalToken (token) ;
    }
    if ((token.mTokenCode > 0) && arxmlmetaparser_5F_scanner_kEndOfScriptInTemplateArray [token.mTokenCode - 1]) {
      mMatchedTemplateDelimiterIndex = -1 ;
    }
  
  }
  if (UNICODE_VALUE (mCurrentChar) == '\0') {
    token.mTokenCode = 0 ;
    enterToken (token) ;
  }
  return token.mTokenCode > 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         E N T E R    T O K E N                                                
//----------------------------------------------------------------------------------------------------------------------

void C_Lexique_arxmlmetaparser_5F_scanner::enterToken (cTokenFor_arxmlmetaparser_5F_scanner & ioToken) {
  cTokenFor_arxmlmetaparser_5F_scanner * ptr = NULL ;
  macroMyNew (ptr, cTokenFor_arxmlmetaparser_5F_scanner ()) ;
  ptr->mTokenCode = ioToken.mTokenCode ;
  // ptr->mIsOptional = ioToken.mIsOptional ;
  ptr->mStartLocation = mTokenStartLocation ;
  ptr->mEndLocation = mTokenEndLocation ;
  ptr->mTemplateStringBeforeToken = ioToken.mTemplateStringBeforeToken ;
  ioToken.mTemplateStringBeforeToken = "" ;
  ptr->mLexicalAttribute_tokenString = ioToken.mLexicalAttribute_tokenString ;
  enterTokenFromPointer (ptr) ;
}

//----------------------------------------------------------------------------------------------------------------------
//               A T T R I B U T E   A C C E S S                                                 
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxmlmetaparser_5F_scanner::attributeValue_tokenString (void) const {
  cTokenFor_arxmlmetaparser_5F_scanner * ptr = (cTokenFor_arxmlmetaparser_5F_scanner *) currentTokenPtr (HERE) ;
  return ptr->mLexicalAttribute_tokenString ;
}

//----------------------------------------------------------------------------------------------------------------------
//         A S S I G N    F R O M    A T T R I B U T E                                           
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring C_Lexique_arxmlmetaparser_5F_scanner::synthetizedAttribute_tokenString (void) const {
  cTokenFor_arxmlmetaparser_5F_scanner * ptr = (cTokenFor_arxmlmetaparser_5F_scanner *) currentTokenPtr (HERE) ;
  macroValidSharedObject (ptr, cTokenFor_arxmlmetaparser_5F_scanner) ;
  GALGAS_location currentLocation (ptr->mStartLocation, ptr->mEndLocation, sourceText ()) ;
  GALGAS_string value (ptr->mLexicalAttribute_tokenString) ;
  GALGAS_lstring result (value, currentLocation) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//                         I N T R O S P E C T I O N                                             
//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist C_Lexique_arxmlmetaparser_5F_scanner::symbols (LOCATION_ARGS) {
  GALGAS_stringlist result = GALGAS_stringlist::constructor_emptyList (THERE) ;
  result.addAssign_operation (GALGAS_string ("comment") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("xmlTag") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("xmlTagValue") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("identifier") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<xsd:") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("</xsd:") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("<\?xml") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string (">") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("\?>") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("/>") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("</") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("=") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("group") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("annotation") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("appinfo") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("attribute") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("attributeGroup") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("choice") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("complexType") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("documentation") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("element") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("enumeration") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("extension") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("import") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("maxLength") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("pattern") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("restriction") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("schema") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("sequence") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("simpleContent") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("simpleType") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("whiteSpace") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("abstract") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("attributeFormDefault") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("attributeRef") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("base") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("category") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("CATEGORY") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("color") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("customType") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("elementFormDefault") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("encoding") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("enforceMinMultiplicity") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("globalElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("id") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("latestBindingTime") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("maxOccurs") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("minOccurs") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("mixed") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("name") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("namePlural") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("namespace") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("noteType") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("nsPrefix") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("qualifiedName") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("recommendedPackage") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("ref") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("roleElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("roleWrapperElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("schemaLocation") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("sequenceOffset") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("source") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("Splitkey") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("Status") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("StatusRevisionBegin") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("targetNamespace") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("type") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("typeElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("typeWrapperElement") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("use") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("value") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("version") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("xmlns:AR") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("xmlns:xsd") COMMA_THERE) ;
  result.addAssign_operation (GALGAS_string ("TODO") COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordLists_arxmlmetaparser_5F_scanner (TC_UniqueArray <C_String> & ioList) {
  ioList.appendObject ("arxmlmetaparser_scanner:keyWordList") ;
  ioList.appendObject ("arxmlmetaparser_scanner:xmlDelimitorsList") ;
}

//----------------------------------------------------------------------------------------------------------------------

static void getKeywordsForIdentifier_arxmlmetaparser_5F_scanner (const C_String & inIdentifier,
                                                                 bool & ioFound,
                                                                 TC_UniqueArray <C_String> & ioList) {
  if (inIdentifier == "arxmlmetaparser_scanner:keyWordList") {
    ioFound = true ;
    ioList.appendObject ("id") ;
    ioList.appendObject ("ref") ;
    ioList.appendObject ("use") ;
    ioList.appendObject ("TODO") ;
    ioList.appendObject ("base") ;
    ioList.appendObject ("name") ;
    ioList.appendObject ("type") ;
    ioList.appendObject ("color") ;
    ioList.appendObject ("group") ;
    ioList.appendObject ("mixed") ;
    ioList.appendObject ("value") ;
    ioList.appendObject ("Status") ;
    ioList.appendObject ("choice") ;
    ioList.appendObject ("import") ;
    ioList.appendObject ("schema") ;
    ioList.appendObject ("source") ;
    ioList.appendObject ("appinfo") ;
    ioList.appendObject ("element") ;
    ioList.appendObject ("pattern") ;
    ioList.appendObject ("version") ;
    ioList.appendObject ("CATEGORY") ;
    ioList.appendObject ("Splitkey") ;
    ioList.appendObject ("abstract") ;
    ioList.appendObject ("category") ;
    ioList.appendObject ("encoding") ;
    ioList.appendObject ("noteType") ;
    ioList.appendObject ("nsPrefix") ;
    ioList.appendObject ("sequence") ;
    ioList.appendObject ("xmlns:AR") ;
    ioList.appendObject ("attribute") ;
    ioList.appendObject ("extension") ;
    ioList.appendObject ("maxLength") ;
    ioList.appendObject ("maxOccurs") ;
    ioList.appendObject ("minOccurs") ;
    ioList.appendObject ("namespace") ;
    ioList.appendObject ("xmlns:xsd") ;
    ioList.appendObject ("annotation") ;
    ioList.appendObject ("customType") ;
    ioList.appendObject ("namePlural") ;
    ioList.appendObject ("simpleType") ;
    ioList.appendObject ("whiteSpace") ;
    ioList.appendObject ("complexType") ;
    ioList.appendObject ("enumeration") ;
    ioList.appendObject ("restriction") ;
    ioList.appendObject ("roleElement") ;
    ioList.appendObject ("typeElement") ;
    ioList.appendObject ("attributeRef") ;
    ioList.appendObject ("documentation") ;
    ioList.appendObject ("globalElement") ;
    ioList.appendObject ("qualifiedName") ;
    ioList.appendObject ("simpleContent") ;
    ioList.appendObject ("attributeGroup") ;
    ioList.appendObject ("schemaLocation") ;
    ioList.appendObject ("sequenceOffset") ;
    ioList.appendObject ("targetNamespace") ;
    ioList.appendObject ("latestBindingTime") ;
    ioList.appendObject ("elementFormDefault") ;
    ioList.appendObject ("recommendedPackage") ;
    ioList.appendObject ("roleWrapperElement") ;
    ioList.appendObject ("typeWrapperElement") ;
    ioList.appendObject ("StatusRevisionBegin") ;
    ioList.appendObject ("attributeFormDefault") ;
    ioList.appendObject ("enforceMinMultiplicity") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
  if (inIdentifier == "arxmlmetaparser_scanner:xmlDelimitorsList") {
    ioFound = true ;
    ioList.appendObject ("<") ;
    ioList.appendObject ("=") ;
    ioList.appendObject (">") ;
    ioList.appendObject ("/>") ;
    ioList.appendObject ("</") ;
    ioList.appendObject ("\?>") ;
    ioList.appendObject ("<\?xml") ;
    ioList.appendObject ("<xsd:") ;
    ioList.appendObject ("</xsd:") ;
    ioList.sortArrayUsingCompareMethod() ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static cLexiqueIntrospection lexiqueIntrospection_arxmlmetaparser_5F_scanner
__attribute__ ((used))
__attribute__ ((unused)) (getKeywordLists_arxmlmetaparser_5F_scanner, getKeywordsForIdentifier_arxmlmetaparser_5F_scanner) ;

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   I N D E X    F O R    T E R M I N A L                                           
//----------------------------------------------------------------------------------------------------------------------

uint32_t C_Lexique_arxmlmetaparser_5F_scanner::styleIndexForTerminal (const int32_t inTerminalIndex) const {
  static const uint32_t kTerminalSymbolStyles [77] = {0,
    4 /* arxmlmetaparser_scanner_1_comment */,
    2 /* arxmlmetaparser_scanner_1_xmlTag */,
    3 /* arxmlmetaparser_scanner_1_xmlTagValue */,
    5 /* arxmlmetaparser_scanner_1_identifier */,
    1 /* arxmlmetaparser_scanner_1__3C_ */,
    1 /* arxmlmetaparser_scanner_1__3C_xsd_3A_ */,
    1 /* arxmlmetaparser_scanner_1__3C__2F_xsd_3A_ */,
    1 /* arxmlmetaparser_scanner_1__3C__3F_xml */,
    1 /* arxmlmetaparser_scanner_1__3E_ */,
    1 /* arxmlmetaparser_scanner_1__3F__3E_ */,
    1 /* arxmlmetaparser_scanner_1__2F__3E_ */,
    1 /* arxmlmetaparser_scanner_1__3C__2F_ */,
    1 /* arxmlmetaparser_scanner_1__3D_ */,
    6 /* arxmlmetaparser_scanner_1_group */,
    6 /* arxmlmetaparser_scanner_1_annotation */,
    6 /* arxmlmetaparser_scanner_1_appinfo */,
    6 /* arxmlmetaparser_scanner_1_attribute */,
    6 /* arxmlmetaparser_scanner_1_attributeGroup */,
    6 /* arxmlmetaparser_scanner_1_choice */,
    6 /* arxmlmetaparser_scanner_1_complexType */,
    6 /* arxmlmetaparser_scanner_1_documentation */,
    6 /* arxmlmetaparser_scanner_1_element */,
    6 /* arxmlmetaparser_scanner_1_enumeration */,
    6 /* arxmlmetaparser_scanner_1_extension */,
    6 /* arxmlmetaparser_scanner_1_import */,
    6 /* arxmlmetaparser_scanner_1_maxLength */,
    6 /* arxmlmetaparser_scanner_1_pattern */,
    6 /* arxmlmetaparser_scanner_1_restriction */,
    6 /* arxmlmetaparser_scanner_1_schema */,
    6 /* arxmlmetaparser_scanner_1_sequence */,
    6 /* arxmlmetaparser_scanner_1_simpleContent */,
    6 /* arxmlmetaparser_scanner_1_simpleType */,
    6 /* arxmlmetaparser_scanner_1_whiteSpace */,
    6 /* arxmlmetaparser_scanner_1_abstract */,
    6 /* arxmlmetaparser_scanner_1_attributeFormDefault */,
    6 /* arxmlmetaparser_scanner_1_attributeRef */,
    6 /* arxmlmetaparser_scanner_1_base */,
    6 /* arxmlmetaparser_scanner_1_category */,
    6 /* arxmlmetaparser_scanner_1_CATEGORY */,
    6 /* arxmlmetaparser_scanner_1_color */,
    6 /* arxmlmetaparser_scanner_1_customType */,
    6 /* arxmlmetaparser_scanner_1_elementFormDefault */,
    6 /* arxmlmetaparser_scanner_1_encoding */,
    6 /* arxmlmetaparser_scanner_1_enforceMinMultiplicity */,
    6 /* arxmlmetaparser_scanner_1_globalElement */,
    6 /* arxmlmetaparser_scanner_1_id */,
    6 /* arxmlmetaparser_scanner_1_latestBindingTime */,
    6 /* arxmlmetaparser_scanner_1_maxOccurs */,
    6 /* arxmlmetaparser_scanner_1_minOccurs */,
    6 /* arxmlmetaparser_scanner_1_mixed */,
    6 /* arxmlmetaparser_scanner_1_name */,
    6 /* arxmlmetaparser_scanner_1_namePlural */,
    6 /* arxmlmetaparser_scanner_1_namespace */,
    6 /* arxmlmetaparser_scanner_1_noteType */,
    6 /* arxmlmetaparser_scanner_1_nsPrefix */,
    6 /* arxmlmetaparser_scanner_1_qualifiedName */,
    6 /* arxmlmetaparser_scanner_1_recommendedPackage */,
    6 /* arxmlmetaparser_scanner_1_ref */,
    6 /* arxmlmetaparser_scanner_1_roleElement */,
    6 /* arxmlmetaparser_scanner_1_roleWrapperElement */,
    6 /* arxmlmetaparser_scanner_1_schemaLocation */,
    6 /* arxmlmetaparser_scanner_1_sequenceOffset */,
    6 /* arxmlmetaparser_scanner_1_source */,
    6 /* arxmlmetaparser_scanner_1_Splitkey */,
    6 /* arxmlmetaparser_scanner_1_Status */,
    6 /* arxmlmetaparser_scanner_1_StatusRevisionBegin */,
    6 /* arxmlmetaparser_scanner_1_targetNamespace */,
    6 /* arxmlmetaparser_scanner_1_type */,
    6 /* arxmlmetaparser_scanner_1_typeElement */,
    6 /* arxmlmetaparser_scanner_1_typeWrapperElement */,
    6 /* arxmlmetaparser_scanner_1_use */,
    6 /* arxmlmetaparser_scanner_1_value */,
    6 /* arxmlmetaparser_scanner_1_version */,
    6 /* arxmlmetaparser_scanner_1_xmlns_3A_AR */,
    6 /* arxmlmetaparser_scanner_1_xmlns_3A_xsd */,
    6 /* arxmlmetaparser_scanner_1_TODO */
  } ;
  return (inTerminalIndex >= 0) ? kTerminalSymbolStyles [inTerminalIndex] : 0 ;
}

//----------------------------------------------------------------------------------------------------------------------
//   S T Y L E   N A M E    F O R    S T Y L E    I N D E X                                      
//----------------------------------------------------------------------------------------------------------------------

C_String C_Lexique_arxmlmetaparser_5F_scanner::styleNameForIndex (const uint32_t inStyleIndex) const {
  C_String result ;
  if (inStyleIndex < 7) {
    static const char * kStyleArray [7] = {
      "",
      "delimitersStyle",
      "nameStyle",
      "attributeValue",
      "commentStyle",
      "textStyle",
      "keywordsStyle"
    } ;
    result = kStyleArray [inStyleIndex] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_arxmlMetaClassMap::cMapElement_arxmlMetaClassMap (const GALGAS_lstring & inKey,
                                                              const GALGAS_arxmlMetaClass & in_mType
                                                              COMMA_LOCATION_ARGS) :
cMapElement (inKey COMMA_THERE),
mProperty_mType (in_mType) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cMapElement_arxmlMetaClassMap::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement * cMapElement_arxmlMetaClassMap::copy (void) {
  cMapElement * result = NULL ;
  macroMyNew (result, cMapElement_arxmlMetaClassMap (mProperty_lkey, mProperty_mType COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cMapElement_arxmlMetaClassMap::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "mType" ":" ;
  mProperty_mType.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cMapElement_arxmlMetaClassMap::compare (const cCollectionElement * inOperand) const {
  cMapElement_arxmlMetaClassMap * operand = (cMapElement_arxmlMetaClassMap *) inOperand ;
  typeComparisonResult result = mProperty_lkey.objectCompare (operand->mProperty_lkey) ;
  if (kOperandEqual == result) {
    result = mProperty_mType.objectCompare (operand->mProperty_mType) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap::GALGAS_arxmlMetaClassMap (void) :
AC_GALGAS_map (true) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap::GALGAS_arxmlMetaClassMap (const GALGAS_arxmlMetaClassMap & inSource) :
AC_GALGAS_map (inSource) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap & GALGAS_arxmlMetaClassMap::operator = (const GALGAS_arxmlMetaClassMap & inSource) {
  * ((AC_GALGAS_map *) this) = inSource ;
  return * this ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap GALGAS_arxmlMetaClassMap::constructor_emptyMap (LOCATION_ARGS) {
  GALGAS_arxmlMetaClassMap result ;
  result.makeNewEmptyMap (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap GALGAS_arxmlMetaClassMap::constructor_mapWithMapToOverride (const GALGAS_arxmlMetaClassMap & inMapToOverride
                                                                                     COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClassMap result ;
  result.makeNewEmptyMapWithMapToOverride (inMapToOverride COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap GALGAS_arxmlMetaClassMap::getter_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaClassMap result ;
  getOverridenMap (result, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassMap::addAssign_operation (const GALGAS_lstring & inKey,
                                                    const GALGAS_arxmlMetaClass & inArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  cMapElement_arxmlMetaClassMap * p = NULL ;
  macroMyNew (p, cMapElement_arxmlMetaClassMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "@arxmlMetaClassMap insert error: '%K' already in map" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap GALGAS_arxmlMetaClassMap::add_operation (const GALGAS_arxmlMetaClassMap & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaClassMap result = *this ;
  cEnumerator_arxmlMetaClassMap enumerator (inOperand, kENUMERATION_UP) ;
  while (enumerator.hasCurrentObject ()) {
    result.addAssign_operation (enumerator.current_lkey (HERE), enumerator.current_mType (HERE), inCompiler COMMA_THERE) ;
    enumerator.gotoNextObject () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassMap::setter_insertKey (GALGAS_lstring inKey,
                                                 GALGAS_arxmlMetaClass inArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  cMapElement_arxmlMetaClassMap * p = NULL ;
  macroMyNew (p, cMapElement_arxmlMetaClassMap (inKey, inArgument0 COMMA_HERE)) ;
  capCollectionElement attributes ;
  attributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
  const char * kInsertErrorMessage = "the %K class has already been declared" ;
  const char * kShadowErrorMessage = "" ;
  performInsert (attributes, inCompiler, kInsertErrorMessage, kShadowErrorMessage COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

const char * kSearchErrorMessage_arxmlMetaClassMap_searchKey = "the %K class has not yet been defined" ;

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassMap::method_searchKey (GALGAS_lstring inKey,
                                                 GALGAS_arxmlMetaClass & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  const cMapElement_arxmlMetaClassMap * p = (const cMapElement_arxmlMetaClassMap *) performSearch (inKey,
                                                                                                   inCompiler,
                                                                                                   kSearchErrorMessage_arxmlMetaClassMap_searchKey
                                                                                                   COMMA_THERE) ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_arxmlMetaClassMap) ;
    outArgument0 = p->mProperty_mType ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassMap::setter_removeKey (GALGAS_lstring inKey,
                                                 GALGAS_arxmlMetaClass & outArgument0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  const char * kRemoveErrorMessage = "the %K class does not exists" ;
  capCollectionElement attributes ;
  performRemove (inKey, attributes, inCompiler, kRemoveErrorMessage COMMA_THERE) ;
  cMapElement_arxmlMetaClassMap * p = (cMapElement_arxmlMetaClassMap *) attributes.ptr () ;
  if (NULL == p) {
    outArgument0.drop () ;
  }else{
    macroValidSharedObject (p, cMapElement_arxmlMetaClassMap) ;
    outArgument0 = p->mProperty_mType ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClass GALGAS_arxmlMetaClassMap::getter_mTypeForKey (const GALGAS_string & inKey,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const {
  const cCollectionElement * attributes = searchForReadingAttribute (inKey, inCompiler COMMA_THERE) ;
  const cMapElement_arxmlMetaClassMap * p = (const cMapElement_arxmlMetaClassMap *) attributes ;
  GALGAS_arxmlMetaClass result ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_arxmlMetaClassMap) ;
    result = p->mProperty_mType ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassMap::setter_setMTypeForKey (GALGAS_arxmlMetaClass inAttributeValue,
                                                      GALGAS_string inKey,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  cCollectionElement * attributes = searchForReadWriteAttribute (inKey, true, inCompiler COMMA_THERE) ;
  cMapElement_arxmlMetaClassMap * p = (cMapElement_arxmlMetaClassMap *) attributes ;
  if (NULL != p) {
    macroValidSharedObject (p, cMapElement_arxmlMetaClassMap) ;
    p->mProperty_mType = inAttributeValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

cMapElement_arxmlMetaClassMap * GALGAS_arxmlMetaClassMap::readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                             const GALGAS_string & inKey
                                                                                             COMMA_LOCATION_ARGS) {
  cMapElement_arxmlMetaClassMap * result = (cMapElement_arxmlMetaClassMap *) searchForReadWriteAttribute (inKey, false, inCompiler COMMA_THERE) ;
  macroNullOrValidSharedObject (result, cMapElement_arxmlMetaClassMap) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlMetaClassMap::cEnumerator_arxmlMetaClassMap (const GALGAS_arxmlMetaClassMap & inEnumeratedObject,
                                                              const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap_2D_element cEnumerator_arxmlMetaClassMap::current (LOCATION_ARGS) const {
  const cMapElement_arxmlMetaClassMap * p = (const cMapElement_arxmlMetaClassMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_arxmlMetaClassMap) ;
  return GALGAS_arxmlMetaClassMap_2D_element (p->mProperty_lkey, p->mProperty_mType) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cEnumerator_arxmlMetaClassMap::current_lkey (LOCATION_ARGS) const {
  const cMapElement * p = (const cMapElement *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement) ;
  return p->mProperty_lkey ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClass cEnumerator_arxmlMetaClassMap::current_mType (LOCATION_ARGS) const {
  const cMapElement_arxmlMetaClassMap * p = (const cMapElement_arxmlMetaClassMap *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cMapElement_arxmlMetaClassMap) ;
  return p->mProperty_mType ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlMetaClassMap::optional_searchKey (const GALGAS_string & inKey,
                                                   GALGAS_arxmlMetaClass & outArgument0) const {
  const cMapElement_arxmlMetaClassMap * p = (const cMapElement_arxmlMetaClassMap *) searchForKey (inKey) ;
  const bool result = NULL != p ;
  if (result) {
    macroValidSharedObject (p, cMapElement_arxmlMetaClassMap) ;
    outArgument0 = p->mProperty_mType ;
  }else{
    outArgument0.drop () ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlMetaClassMap generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClassMap ("arxmlMetaClassMap",
                                          NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaClassMap::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClassMap ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaClassMap::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaClassMap (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap GALGAS_arxmlMetaClassMap::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClassMap result ;
  const GALGAS_arxmlMetaClassMap * p = (const GALGAS_arxmlMetaClassMap *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaClassMap *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaClassMap", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaClassMap addClassElement'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_addClassElement (GALGAS_arxmlMetaClassMap & ioObject,
                                      GALGAS_lstring inArgument_className,
                                      GALGAS_arxmlMetaElement inArgument_mElement,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaClass var_modifiedClass_1081 ;
  {
  ioObject.setter_removeKey (inArgument_className, var_modifiedClass_1081, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 39)) ;
  }
  {
  var_modifiedClass_1081.insulate (HERE) ;
  cPtr_arxmlMetaClass * ptr_1147 = (cPtr_arxmlMetaClass *) var_modifiedClass_1081.ptr () ;
  callExtensionSetter_addElement ((cPtr_arxmlMetaClass *) ptr_1147, inArgument_mElement, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 40)) ;
  }
  {
  ioObject.setter_insertKey (inArgument_className, var_modifiedClass_1081, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 41)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaClassMap addClassAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_addClassAttribute (GALGAS_arxmlMetaClassMap & ioObject,
                                        GALGAS_lstring inArgument_className,
                                        GALGAS_arxmlMetaAttribute inArgument_mAttribute,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaClass var_modifiedClass_1352 ;
  {
  ioObject.setter_removeKey (inArgument_className, var_modifiedClass_1352, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 48)) ;
  }
  {
  var_modifiedClass_1352.insulate (HERE) ;
  cPtr_arxmlMetaClass * ptr_1418 = (cPtr_arxmlMetaClass *) var_modifiedClass_1352.ptr () ;
  callExtensionSetter_addAttribute ((cPtr_arxmlMetaClass *) ptr_1418, inArgument_mAttribute, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 49)) ;
  }
  {
  ioObject.setter_insertKey (inArgument_className, var_modifiedClass_1352, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 50)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaClassMap updateLegacyParameters'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionSetter_updateLegacyParameters (GALGAS_arxmlMetaClassMap & ioObject,
                                             GALGAS_lstring inArgument_className,
                                             GALGAS_arxmlMetaElementList inArgument_lElement,
                                             GALGAS_arxmlMetaAttributeList inArgument_lAttribute,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaClass var_modifiedClass_1670 ;
  {
  ioObject.setter_removeKey (inArgument_className, var_modifiedClass_1670, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 58)) ;
  }
  {
  var_modifiedClass_1670.insulate (HERE) ;
  cPtr_arxmlMetaClass * ptr_1736 = (cPtr_arxmlMetaClass *) var_modifiedClass_1670.ptr () ;
  callExtensionSetter_legacyUpdate ((cPtr_arxmlMetaClass *) ptr_1736, inArgument_lElement, inArgument_lAttribute, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 59)) ;
  }
  {
  ioObject.setter_insertKey (inArgument_className, var_modifiedClass_1670, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 60)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaClassMap display'
//
//----------------------------------------------------------------------------------------------------------------------

void extensionMethod_display (const GALGAS_arxmlMetaClassMap inObject,
                              GALGAS_string & ioArgument_ioString,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_arxmlMetaClassMap temp_0 = inObject ;
  cEnumerator_arxmlMetaClassMap enumerator_1898 (temp_0, kENUMERATION_UP) ;
  while (enumerator_1898.hasCurrentObject ()) {
    const GALGAS_arxmlMetaClassMap temp_1 = inObject ;
    callExtensionMethod_display ((cPtr_arxmlMetaClass *) enumerator_1898.current_mType (HERE).ptr (), temp_1, ioArgument_ioString, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 66)) ;
    enumerator_1898.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//'@arxmlMetaClassGraph' graph
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassGraph::GALGAS_arxmlMetaClassGraph (void) :
AC_GALGAS_graph () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassGraph GALGAS_arxmlMetaClassGraph::constructor_emptyGraph (LOCATION_ARGS) {
  GALGAS_arxmlMetaClassGraph result ;
  result.makeNewEmptyGraph (THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassGraph::setter_addNode (GALGAS_lstring inKey,
                                                 GALGAS_lstring inArgument_0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  GALGAS_lstringlist::makeAttributesFromObjects (attributes, inArgument_0 COMMA_THERE) ;
  const char * kErrorMessage = "the %K class has already been declared" ;
  internalAddNode (inKey, kErrorMessage, attributes, inCompiler COMMA_THERE) ;
}


//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassGraph::method_topologicalSort (GALGAS_lstringlist & outSortedList,
                                                         GALGAS_lstringlist & outSortedKeyList,
                                                         GALGAS_lstringlist & outUnsortedList,
                                                         GALGAS_lstringlist & outUnsortedKeyList,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const {
  capCollectionElementArray sortedList ;
  capCollectionElementArray unsortedList ;
  internalTopologicalSort (sortedList, outSortedKeyList, unsortedList, outUnsortedKeyList, inCompiler COMMA_THERE) ;
  outSortedList = GALGAS_lstringlist (sortedList) ;
  outUnsortedList = GALGAS_lstringlist (unsortedList) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassGraph::method_depthFirstTopologicalSort (GALGAS_lstringlist & outSortedList,
                                                                   GALGAS_lstringlist & outSortedKeyList,
                                                                   GALGAS_lstringlist & outUnsortedList,
                                                                   GALGAS_lstringlist & outUnsortedKeyList,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElementArray sortedList ;
  capCollectionElementArray unsortedList ;
  internalDepthFirstTopologicalSort (sortedList, outSortedKeyList, unsortedList, outUnsortedKeyList, inCompiler COMMA_THERE) ;
  outSortedList = GALGAS_lstringlist (sortedList) ;
  outUnsortedList = GALGAS_lstringlist (unsortedList) ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassGraph GALGAS_arxmlMetaClassGraph::getter_reversedGraph (LOCATION_ARGS) const {
  GALGAS_arxmlMetaClassGraph result ;
  result.reversedGraphFromGraph (*this COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassGraph::method_circularities (GALGAS_lstringlist & outInfoList,
                                                       GALGAS_lstringlist & outKeyList
                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElementArray infoList ;
  internalFindCircularities (infoList, outKeyList COMMA_THERE) ;
  outInfoList = GALGAS_lstringlist (infoList) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassGraph::method_nodesWithNoSuccessor (GALGAS_lstringlist & outInfoList,
                                                              GALGAS_lstringlist & outKeyList
                                                              COMMA_LOCATION_ARGS) const {
  capCollectionElementArray infoList ;
  internalNodesWithNoSuccessor (infoList, outKeyList COMMA_THERE) ;
  outInfoList = GALGAS_lstringlist (infoList) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassGraph::method_nodesWithNoPredecessor (GALGAS_lstringlist & outInfoList,
                                                                GALGAS_lstringlist & outKeyList
                                                                COMMA_LOCATION_ARGS) const {
  capCollectionElementArray infoList ;
  internalNodesWithNoPredecessor (infoList, outKeyList COMMA_THERE) ;
  outInfoList = GALGAS_lstringlist (infoList) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassGraph GALGAS_arxmlMetaClassGraph::getter_subgraphFromNodes (const GALGAS_lstringlist & inStartKeyList,
                                                                                 const GALGAS_stringset & inKeysToExclude,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaClassGraph result ;
  subGraph (result, inStartKeyList, inKeysToExclude, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_arxmlMetaClassGraph::getter_nodeList (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist resultingList ;
  if (isValid ()) {
    resultingList = graph () ;
  }
  return resultingList ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_arxmlMetaClassGraph::getter_accessibleNodesFrom (const GALGAS_lstringlist & inStartKeyList,
                                                                           const GALGAS_stringset & inNodesToExclude,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  GALGAS_arxmlMetaClassGraph resultingGraph ;
  subGraph (resultingGraph,
            inStartKeyList,
            inNodesToExclude,
            inCompiler
            COMMA_THERE) ;
  if (resultingGraph.isValid ()) {
    result = resultingGraph.getter_lkeyList (THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlMetaClassGraph generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClassGraph ("arxmlMetaClassGraph",
                                            NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaClassGraph::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClassGraph ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaClassGraph::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaClassGraph (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassGraph GALGAS_arxmlMetaClassGraph::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClassGraph result ;
  const GALGAS_arxmlMetaClassGraph * p = (const GALGAS_arxmlMetaClassGraph *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaClassGraph *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaClassGraph", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@arxmlMetaClasslist' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_arxmlMetaClasslist : public cCollectionElement {
  public: GALGAS_arxmlMetaClasslist_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_arxmlMetaClasslist (const GALGAS_arxmlMetaClass & in_lClass
                                                 COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_arxmlMetaClasslist (const GALGAS_arxmlMetaClasslist_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlMetaClasslist::cCollectionElement_arxmlMetaClasslist (const GALGAS_arxmlMetaClass & in_lClass
                                                                              COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_lClass) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlMetaClasslist::cCollectionElement_arxmlMetaClasslist (const GALGAS_arxmlMetaClasslist_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_lClass) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_arxmlMetaClasslist::isValid (void) const {
  return true ; // return mObject.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_arxmlMetaClasslist::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_arxmlMetaClasslist (mObject.mProperty_lClass COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_arxmlMetaClasslist::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "lClass" ":" ;
  mObject.mProperty_lClass.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_arxmlMetaClasslist::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_arxmlMetaClasslist * operand = (cCollectionElement_arxmlMetaClasslist *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_arxmlMetaClasslist) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist::GALGAS_arxmlMetaClasslist (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist::GALGAS_arxmlMetaClasslist (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist GALGAS_arxmlMetaClasslist::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaClasslist  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist GALGAS_arxmlMetaClasslist::constructor_listWithValue (const GALGAS_arxmlMetaClass & inOperand0
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClasslist result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlMetaClasslist (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_arxmlMetaClasslist::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                           const GALGAS_arxmlMetaClass & in_lClass
                                                           COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlMetaClasslist * p = NULL ;
  macroMyNew (p, cCollectionElement_arxmlMetaClasslist (in_lClass COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::addAssign_operation (const GALGAS_arxmlMetaClass & inOperand0
                                                     COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlMetaClasslist (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{ // Destroy receiver
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::setter_append (GALGAS_arxmlMetaClasslist_2D_element inElement,
                                               C_Compiler * /* inCompiler */
                                               COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inElement.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlMetaClasslist (inElement COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::setter_insertAtIndex (const GALGAS_arxmlMetaClass inOperand0,
                                                      const GALGAS_uint inInsertionIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlMetaClasslist (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::setter_removeAtIndex (GALGAS_arxmlMetaClass & outOperand0,
                                                      const GALGAS_uint inRemoveIndex,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_arxmlMetaClasslist * p = (cCollectionElement_arxmlMetaClasslist *) attributes.ptr () ;
      if (NULL == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_arxmlMetaClasslist) ;
        outOperand0 = p->mObject.mProperty_lClass ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::setter_popFirst (GALGAS_arxmlMetaClass & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaClasslist * p = (cCollectionElement_arxmlMetaClasslist *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaClasslist) ;
    outOperand0 = p->mObject.mProperty_lClass ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::setter_popLast (GALGAS_arxmlMetaClass & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaClasslist * p = (cCollectionElement_arxmlMetaClasslist *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaClasslist) ;
    outOperand0 = p->mObject.mProperty_lClass ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::method_first (GALGAS_arxmlMetaClass & outOperand0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaClasslist * p = (cCollectionElement_arxmlMetaClasslist *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaClasslist) ;
    outOperand0 = p->mObject.mProperty_lClass ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::method_last (GALGAS_arxmlMetaClass & outOperand0,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaClasslist * p = (cCollectionElement_arxmlMetaClasslist *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaClasslist) ;
    outOperand0 = p->mObject.mProperty_lClass ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist GALGAS_arxmlMetaClasslist::add_operation (const GALGAS_arxmlMetaClasslist & inOperand,
                                                                    C_Compiler * /* inCompiler */
                                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlMetaClasslist result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist GALGAS_arxmlMetaClasslist::getter_subListWithRange (const GALGAS_range & inRange,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaClasslist result = GALGAS_arxmlMetaClasslist::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist GALGAS_arxmlMetaClasslist::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaClasslist result = GALGAS_arxmlMetaClasslist::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist GALGAS_arxmlMetaClasslist::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaClasslist result = GALGAS_arxmlMetaClasslist::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::plusAssign_operation (const GALGAS_arxmlMetaClasslist inOperand,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist::setter_setLClassAtIndex (GALGAS_arxmlMetaClass inOperand,
                                                         GALGAS_uint inIndex,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlMetaClasslist * p = (cCollectionElement_arxmlMetaClasslist *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlMetaClasslist) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_lClass = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClass GALGAS_arxmlMetaClasslist::getter_lClassAtIndex (const GALGAS_uint & inIndex,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaClasslist * p = (cCollectionElement_arxmlMetaClasslist *) attributes.ptr () ;
  GALGAS_arxmlMetaClass result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlMetaClasslist) ;
    result = p->mObject.mProperty_lClass ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlMetaClasslist::cEnumerator_arxmlMetaClasslist (const GALGAS_arxmlMetaClasslist & inEnumeratedObject,
                                                                const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist_2D_element cEnumerator_arxmlMetaClasslist::current (LOCATION_ARGS) const {
  const cCollectionElement_arxmlMetaClasslist * p = (const cCollectionElement_arxmlMetaClasslist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlMetaClasslist) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClass cEnumerator_arxmlMetaClasslist::current_lClass (LOCATION_ARGS) const {
  const cCollectionElement_arxmlMetaClasslist * p = (const cCollectionElement_arxmlMetaClasslist *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlMetaClasslist) ;
  return p->mObject.mProperty_lClass ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlMetaClasslist generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClasslist ("arxmlMetaClasslist",
                                           NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaClasslist::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClasslist ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaClasslist::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaClasslist (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist GALGAS_arxmlMetaClasslist::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClasslist result ;
  const GALGAS_arxmlMetaClasslist * p = (const GALGAS_arxmlMetaClasslist *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaClasslist *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaClasslist", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@arxmlMetaElementList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_arxmlMetaElementList : public cCollectionElement {
  public: GALGAS_arxmlMetaElementList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_arxmlMetaElementList (const GALGAS_arxmlMetaElement & in_lElement
                                                   COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_arxmlMetaElementList (const GALGAS_arxmlMetaElementList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlMetaElementList::cCollectionElement_arxmlMetaElementList (const GALGAS_arxmlMetaElement & in_lElement
                                                                                  COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_lElement) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlMetaElementList::cCollectionElement_arxmlMetaElementList (const GALGAS_arxmlMetaElementList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_lElement) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_arxmlMetaElementList::isValid (void) const {
  return true ; // return mObject.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_arxmlMetaElementList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_arxmlMetaElementList (mObject.mProperty_lElement COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_arxmlMetaElementList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "lElement" ":" ;
  mObject.mProperty_lElement.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_arxmlMetaElementList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_arxmlMetaElementList * operand = (cCollectionElement_arxmlMetaElementList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_arxmlMetaElementList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList::GALGAS_arxmlMetaElementList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList::GALGAS_arxmlMetaElementList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaElementList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaElementList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaElementList::constructor_listWithValue (const GALGAS_arxmlMetaElement & inOperand0
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaElementList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlMetaElementList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_arxmlMetaElementList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                             const GALGAS_arxmlMetaElement & in_lElement
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlMetaElementList * p = NULL ;
  macroMyNew (p, cCollectionElement_arxmlMetaElementList (in_lElement COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::addAssign_operation (const GALGAS_arxmlMetaElement & inOperand0
                                                       COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlMetaElementList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{ // Destroy receiver
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::setter_append (GALGAS_arxmlMetaElementList_2D_element inElement,
                                                 C_Compiler * /* inCompiler */
                                                 COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inElement.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlMetaElementList (inElement COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::setter_insertAtIndex (const GALGAS_arxmlMetaElement inOperand0,
                                                        const GALGAS_uint inInsertionIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlMetaElementList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::setter_removeAtIndex (GALGAS_arxmlMetaElement & outOperand0,
                                                        const GALGAS_uint inRemoveIndex,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_arxmlMetaElementList * p = (cCollectionElement_arxmlMetaElementList *) attributes.ptr () ;
      if (NULL == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_arxmlMetaElementList) ;
        outOperand0 = p->mObject.mProperty_lElement ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::setter_popFirst (GALGAS_arxmlMetaElement & outOperand0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaElementList * p = (cCollectionElement_arxmlMetaElementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaElementList) ;
    outOperand0 = p->mObject.mProperty_lElement ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::setter_popLast (GALGAS_arxmlMetaElement & outOperand0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaElementList * p = (cCollectionElement_arxmlMetaElementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaElementList) ;
    outOperand0 = p->mObject.mProperty_lElement ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::method_first (GALGAS_arxmlMetaElement & outOperand0,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaElementList * p = (cCollectionElement_arxmlMetaElementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaElementList) ;
    outOperand0 = p->mObject.mProperty_lElement ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::method_last (GALGAS_arxmlMetaElement & outOperand0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaElementList * p = (cCollectionElement_arxmlMetaElementList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaElementList) ;
    outOperand0 = p->mObject.mProperty_lElement ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaElementList::add_operation (const GALGAS_arxmlMetaElementList & inOperand,
                                                                        C_Compiler * /* inCompiler */
                                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlMetaElementList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaElementList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaElementList result = GALGAS_arxmlMetaElementList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaElementList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaElementList result = GALGAS_arxmlMetaElementList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaElementList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaElementList result = GALGAS_arxmlMetaElementList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::plusAssign_operation (const GALGAS_arxmlMetaElementList inOperand,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList::setter_setLElementAtIndex (GALGAS_arxmlMetaElement inOperand,
                                                             GALGAS_uint inIndex,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlMetaElementList * p = (cCollectionElement_arxmlMetaElementList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlMetaElementList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_lElement = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElement GALGAS_arxmlMetaElementList::getter_lElementAtIndex (const GALGAS_uint & inIndex,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaElementList * p = (cCollectionElement_arxmlMetaElementList *) attributes.ptr () ;
  GALGAS_arxmlMetaElement result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlMetaElementList) ;
    result = p->mObject.mProperty_lElement ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlMetaElementList::cEnumerator_arxmlMetaElementList (const GALGAS_arxmlMetaElementList & inEnumeratedObject,
                                                                    const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList_2D_element cEnumerator_arxmlMetaElementList::current (LOCATION_ARGS) const {
  const cCollectionElement_arxmlMetaElementList * p = (const cCollectionElement_arxmlMetaElementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlMetaElementList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElement cEnumerator_arxmlMetaElementList::current_lElement (LOCATION_ARGS) const {
  const cCollectionElement_arxmlMetaElementList * p = (const cCollectionElement_arxmlMetaElementList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlMetaElementList) ;
  return p->mObject.mProperty_lElement ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlMetaElementList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaElementList ("arxmlMetaElementList",
                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaElementList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaElementList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaElementList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaElementList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaElementList::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaElementList result ;
  const GALGAS_arxmlMetaElementList * p = (const GALGAS_arxmlMetaElementList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaElementList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaElementList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Class for element of '@arxmlMetaAttributeList' list
//
//----------------------------------------------------------------------------------------------------------------------

class cCollectionElement_arxmlMetaAttributeList : public cCollectionElement {
  public: GALGAS_arxmlMetaAttributeList_2D_element mObject ;

//--- Constructors
  public: cCollectionElement_arxmlMetaAttributeList (const GALGAS_arxmlMetaAttribute & in_lAttribute
                                                     COMMA_LOCATION_ARGS) ;
  public: cCollectionElement_arxmlMetaAttributeList (const GALGAS_arxmlMetaAttributeList_2D_element & inElement COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public: virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public: virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public: virtual cCollectionElement * copy (void) ;

//--- Description
  public: virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlMetaAttributeList::cCollectionElement_arxmlMetaAttributeList (const GALGAS_arxmlMetaAttribute & in_lAttribute
                                                                                      COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (in_lAttribute) {
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement_arxmlMetaAttributeList::cCollectionElement_arxmlMetaAttributeList (const GALGAS_arxmlMetaAttributeList_2D_element & inElement COMMA_LOCATION_ARGS) :
cCollectionElement (THERE),
mObject (inElement.mProperty_lAttribute) {
}

//----------------------------------------------------------------------------------------------------------------------

bool cCollectionElement_arxmlMetaAttributeList::isValid (void) const {
  return true ; // return mObject.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

cCollectionElement * cCollectionElement_arxmlMetaAttributeList::copy (void) {
  cCollectionElement * result = NULL ;
  macroMyNew (result, cCollectionElement_arxmlMetaAttributeList (mObject.mProperty_lAttribute COMMA_HERE)) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void cCollectionElement_arxmlMetaAttributeList::description (C_String & ioString, const int32_t inIndentation) const {
  ioString << "\n" ;
  ioString.writeStringMultiple ("| ", inIndentation) ;
  ioString << "lAttribute" ":" ;
  mObject.mProperty_lAttribute.description (ioString, inIndentation) ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cCollectionElement_arxmlMetaAttributeList::compare (const cCollectionElement * inOperand) const {
  cCollectionElement_arxmlMetaAttributeList * operand = (cCollectionElement_arxmlMetaAttributeList *) inOperand ;
  macroValidSharedObject (operand, cCollectionElement_arxmlMetaAttributeList) ;
  return mObject.objectCompare (operand->mObject) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList::GALGAS_arxmlMetaAttributeList (void) :
AC_GALGAS_list () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList::GALGAS_arxmlMetaAttributeList (const capCollectionElementArray & inSharedArray) :
AC_GALGAS_list (inSharedArray) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaAttributeList::constructor_emptyList (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaAttributeList  (capCollectionElementArray ()) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaAttributeList::constructor_listWithValue (const GALGAS_arxmlMetaAttribute & inOperand0
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaAttributeList result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlMetaAttributeList (capCollectionElementArray ()) ;
    capCollectionElement attributes ;
    GALGAS_arxmlMetaAttributeList::makeAttributesFromObjects (attributes, inOperand0 COMMA_THERE) ;
    result.appendObject (attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                               const GALGAS_arxmlMetaAttribute & in_lAttribute
                                                               COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlMetaAttributeList * p = NULL ;
  macroMyNew (p, cCollectionElement_arxmlMetaAttributeList (in_lAttribute COMMA_THERE)) ;
  outAttributes.setPointer (p) ;
  macroDetachSharedObject (p) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::addAssign_operation (const GALGAS_arxmlMetaAttribute & inOperand0
                                                         COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlMetaAttributeList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{ // Destroy receiver
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::setter_append (GALGAS_arxmlMetaAttributeList_2D_element inElement,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inElement.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlMetaAttributeList (inElement COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      appendObject (attributes) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::setter_insertAtIndex (const GALGAS_arxmlMetaAttribute inOperand0,
                                                          const GALGAS_uint inInsertionIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inInsertionIndex.isValid () && inOperand0.isValid ()) {
      cCollectionElement * p = NULL ;
      macroMyNew (p, cCollectionElement_arxmlMetaAttributeList (inOperand0 COMMA_THERE)) ;
      capCollectionElement attributes ;
      attributes.setPointer (p) ;
      macroDetachSharedObject (p) ;
      insertObjectAtIndex (attributes, inInsertionIndex.uintValue (), inCompiler COMMA_THERE) ;
    }else{
      drop () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::setter_removeAtIndex (GALGAS_arxmlMetaAttribute & outOperand0,
                                                          const GALGAS_uint inRemoveIndex,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  if (isValid ()) {
    if (inRemoveIndex.isValid ()) {
      capCollectionElement attributes ;
      removeObjectAtIndex (attributes, inRemoveIndex.uintValue (), inCompiler COMMA_THERE) ;
      cCollectionElement_arxmlMetaAttributeList * p = (cCollectionElement_arxmlMetaAttributeList *) attributes.ptr () ;
      if (NULL == p) {
        outOperand0.drop () ;
        drop () ;
      }else{
        macroValidSharedObject (p, cCollectionElement_arxmlMetaAttributeList) ;
        outOperand0 = p->mObject.mProperty_lAttribute ;
      }
    }else{
      outOperand0.drop () ;
      drop () ;    
    }
  }else{
    outOperand0.drop () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::setter_popFirst (GALGAS_arxmlMetaAttribute & outOperand0,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeFirstObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaAttributeList * p = (cCollectionElement_arxmlMetaAttributeList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaAttributeList) ;
    outOperand0 = p->mObject.mProperty_lAttribute ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::setter_popLast (GALGAS_arxmlMetaAttribute & outOperand0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  capCollectionElement attributes ;
  removeLastObject (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaAttributeList * p = (cCollectionElement_arxmlMetaAttributeList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaAttributeList) ;
    outOperand0 = p->mObject.mProperty_lAttribute ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::method_first (GALGAS_arxmlMetaAttribute & outOperand0,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readFirst (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaAttributeList * p = (cCollectionElement_arxmlMetaAttributeList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaAttributeList) ;
    outOperand0 = p->mObject.mProperty_lAttribute ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::method_last (GALGAS_arxmlMetaAttribute & outOperand0,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes ;
  readLast (attributes, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaAttributeList * p = (cCollectionElement_arxmlMetaAttributeList *) attributes.ptr () ;
  if (NULL == p) {
    outOperand0.drop () ;
  }else{
    macroValidSharedObject (p, cCollectionElement_arxmlMetaAttributeList) ;
    outOperand0 = p->mObject.mProperty_lAttribute ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaAttributeList::add_operation (const GALGAS_arxmlMetaAttributeList & inOperand,
                                                                            C_Compiler * /* inCompiler */
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlMetaAttributeList result ;
  if (isValid () && inOperand.isValid ()) {
    result = *this ;
    result.appendList (inOperand) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaAttributeList::getter_subListWithRange (const GALGAS_range & inRange,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaAttributeList result = GALGAS_arxmlMetaAttributeList::constructor_emptyList (THERE) ;
  subListWithRange (result, inRange, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaAttributeList::getter_subListFromIndex (const GALGAS_uint & inIndex,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaAttributeList result = GALGAS_arxmlMetaAttributeList::constructor_emptyList (THERE) ;
  subListFromIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaAttributeList::getter_subListToIndex (const GALGAS_uint & inIndex,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const {
  GALGAS_arxmlMetaAttributeList result = GALGAS_arxmlMetaAttributeList::constructor_emptyList (THERE) ;
  subListToIndex (result, inIndex, inCompiler COMMA_THERE) ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::plusAssign_operation (const GALGAS_arxmlMetaAttributeList inOperand,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  appendList (inOperand) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList::setter_setLAttributeAtIndex (GALGAS_arxmlMetaAttribute inOperand,
                                                                 GALGAS_uint inIndex,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  cCollectionElement_arxmlMetaAttributeList * p = (cCollectionElement_arxmlMetaAttributeList *) uniquelyReferencedPointerAtIndex (inIndex, inCompiler COMMA_THERE) ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlMetaAttributeList) ;
    macroUniqueSharedObject (p) ;
    p->mObject.mProperty_lAttribute = inOperand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttribute GALGAS_arxmlMetaAttributeList::getter_lAttributeAtIndex (const GALGAS_uint & inIndex,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const {
  capCollectionElement attributes = readObjectAtIndex (inIndex, inCompiler COMMA_THERE) ;
  cCollectionElement_arxmlMetaAttributeList * p = (cCollectionElement_arxmlMetaAttributeList *) attributes.ptr () ;
  GALGAS_arxmlMetaAttribute result ;
  if (NULL != p) {
    macroValidSharedObject (p, cCollectionElement_arxmlMetaAttributeList) ;
    result = p->mObject.mProperty_lAttribute ;
  }
  return result ;
}



//----------------------------------------------------------------------------------------------------------------------

cEnumerator_arxmlMetaAttributeList::cEnumerator_arxmlMetaAttributeList (const GALGAS_arxmlMetaAttributeList & inEnumeratedObject,
                                                                        const typeEnumerationOrder inOrder) :
cGenericAbstractEnumerator (inOrder) {
  inEnumeratedObject.populateEnumerationArray (mEnumerationArray) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList_2D_element cEnumerator_arxmlMetaAttributeList::current (LOCATION_ARGS) const {
  const cCollectionElement_arxmlMetaAttributeList * p = (const cCollectionElement_arxmlMetaAttributeList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlMetaAttributeList) ;
  return p->mObject ;
}


//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttribute cEnumerator_arxmlMetaAttributeList::current_lAttribute (LOCATION_ARGS) const {
  const cCollectionElement_arxmlMetaAttributeList * p = (const cCollectionElement_arxmlMetaAttributeList *) currentObjectPtr (THERE) ;
  macroValidSharedObject (p, cCollectionElement_arxmlMetaAttributeList) ;
  return p->mObject.mProperty_lAttribute ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlMetaAttributeList generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaAttributeList ("arxmlMetaAttributeList",
                                               NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaAttributeList::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaAttributeList ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaAttributeList::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaAttributeList (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaAttributeList::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaAttributeList result ;
  const GALGAS_arxmlMetaAttributeList * p = (const GALGAS_arxmlMetaAttributeList *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaAttributeList *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaAttributeList", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@arxmlMetaElementList string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_string (const GALGAS_arxmlMetaElementList & inObject,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outString ; // Returned variable
  result_outString = GALGAS_string::makeEmptyString () ;
  const GALGAS_arxmlMetaElementList temp_0 = inObject ;
  cEnumerator_arxmlMetaElementList enumerator_8749 (temp_0, kENUMERATION_UP) ;
  while (enumerator_8749.hasCurrentObject ()) {
    result_outString.plusAssign_operation(GALGAS_string ("\"").add_operation (enumerator_8749.current_lElement (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 316)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 316)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 316)) ;
    if (enumerator_8749.hasNextObject ()) {
      result_outString.plusAssign_operation(GALGAS_string (" ; "), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 318)) ;
    }
    enumerator_8749.gotoNextObject () ;
  }
//---
  return result_outString ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@arxmlMetaAttributeList string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_string (const GALGAS_arxmlMetaAttributeList & inObject,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outString ; // Returned variable
  result_outString = GALGAS_string::makeEmptyString () ;
  const GALGAS_arxmlMetaAttributeList temp_0 = inObject ;
  cEnumerator_arxmlMetaAttributeList enumerator_9134 (temp_0, kENUMERATION_UP) ;
  while (enumerator_9134.hasCurrentObject ()) {
    result_outString.plusAssign_operation(GALGAS_string ("\"").add_operation (enumerator_9134.current_lAttribute (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 338)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 338)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 338)) ;
    if (enumerator_9134.hasNextObject ()) {
      result_outString.plusAssign_operation(GALGAS_string (" ; "), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 340)) ;
    }
    enumerator_9134.gotoNextObject () ;
  }
//---
  return result_outString ;
}




//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionType::GALGAS_restrictionType (void) :
mEnum (kNotBuilt) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionType GALGAS_restrictionType::constructor_restrictionSimple (UNUSED_LOCATION_ARGS) {
  GALGAS_restrictionType result ;
  result.mEnum = kEnum_restrictionSimple ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionType GALGAS_restrictionType::constructor_restrictionEnum (UNUSED_LOCATION_ARGS) {
  GALGAS_restrictionType result ;
  result.mEnum = kEnum_restrictionEnum ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionType GALGAS_restrictionType::constructor_restrictionOther (UNUSED_LOCATION_ARGS) {
  GALGAS_restrictionType result ;
  result.mEnum = kEnum_restrictionOther ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionType GALGAS_restrictionType::constructor_restrictionUnused (UNUSED_LOCATION_ARGS) {
  GALGAS_restrictionType result ;
  result.mEnum = kEnum_restrictionUnused ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_restrictionType::optional_restrictionSimple () const {
  const bool ok = mEnum == kEnum_restrictionSimple ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_restrictionType::optional_restrictionEnum () const {
  const bool ok = mEnum == kEnum_restrictionEnum ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_restrictionType::optional_restrictionOther () const {
  const bool ok = mEnum == kEnum_restrictionOther ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_restrictionType::optional_restrictionUnused () const {
  const bool ok = mEnum == kEnum_restrictionUnused ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

static const char * gEnumNameArrayFor_restrictionType [5] = {
  "(not built)",
  "restrictionSimple",
  "restrictionEnum",
  "restrictionOther",
  "restrictionUnused"
} ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_restrictionType::getter_isRestrictionSimple (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_restrictionSimple == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_restrictionType::getter_isRestrictionEnum (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_restrictionEnum == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_restrictionType::getter_isRestrictionOther (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_restrictionOther == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_restrictionType::getter_isRestrictionUnused (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_restrictionUnused == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_restrictionType::description (C_String & ioString,
                                          const int32_t /* inIndentation */) const {
  ioString << "<enum @restrictionType: " << gEnumNameArrayFor_restrictionType [mEnum] ;
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_restrictionType::objectCompare (const GALGAS_restrictionType & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @restrictionType generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_restrictionType ("restrictionType",
                                        NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_restrictionType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_restrictionType ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_restrictionType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_restrictionType (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionType GALGAS_restrictionType::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_restrictionType result ;
  const GALGAS_restrictionType * p = (const GALGAS_restrictionType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_restrictionType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("restrictionType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionBaseType::GALGAS_restrictionBaseType (void) :
mEnum (kNotBuilt) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionBaseType GALGAS_restrictionBaseType::constructor_restrictionString (UNUSED_LOCATION_ARGS) {
  GALGAS_restrictionBaseType result ;
  result.mEnum = kEnum_restrictionString ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionBaseType GALGAS_restrictionBaseType::constructor_restrictionUint (UNUSED_LOCATION_ARGS) {
  GALGAS_restrictionBaseType result ;
  result.mEnum = kEnum_restrictionUint ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionBaseType GALGAS_restrictionBaseType::constructor_restrictionDouble (UNUSED_LOCATION_ARGS) {
  GALGAS_restrictionBaseType result ;
  result.mEnum = kEnum_restrictionDouble ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionBaseType GALGAS_restrictionBaseType::constructor_restrictionUndef (UNUSED_LOCATION_ARGS) {
  GALGAS_restrictionBaseType result ;
  result.mEnum = kEnum_restrictionUndef ;
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_restrictionBaseType::optional_restrictionString () const {
  const bool ok = mEnum == kEnum_restrictionString ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_restrictionBaseType::optional_restrictionUint () const {
  const bool ok = mEnum == kEnum_restrictionUint ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_restrictionBaseType::optional_restrictionDouble () const {
  const bool ok = mEnum == kEnum_restrictionDouble ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_restrictionBaseType::optional_restrictionUndef () const {
  const bool ok = mEnum == kEnum_restrictionUndef ;
  return ok ;
}

//----------------------------------------------------------------------------------------------------------------------

static const char * gEnumNameArrayFor_restrictionBaseType [5] = {
  "(not built)",
  "restrictionString",
  "restrictionUint",
  "restrictionDouble",
  "restrictionUndef"
} ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_restrictionBaseType::getter_isRestrictionString (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_restrictionString == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_restrictionBaseType::getter_isRestrictionUint (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_restrictionUint == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_restrictionBaseType::getter_isRestrictionDouble (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_restrictionDouble == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_restrictionBaseType::getter_isRestrictionUndef (UNUSED_LOCATION_ARGS) const {
  return GALGAS_bool (kNotBuilt != mEnum, kEnum_restrictionUndef == mEnum) ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_restrictionBaseType::description (C_String & ioString,
                                              const int32_t /* inIndentation */) const {
  ioString << "<enum @restrictionBaseType: " << gEnumNameArrayFor_restrictionBaseType [mEnum] ;
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_restrictionBaseType::objectCompare (const GALGAS_restrictionBaseType & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    if (mEnum < inOperand.mEnum) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mEnum > inOperand.mEnum) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = kOperandEqual ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @restrictionBaseType generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_restrictionBaseType ("restrictionBaseType",
                                            NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_restrictionBaseType::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_restrictionBaseType ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_restrictionBaseType::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_restrictionBaseType (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionBaseType GALGAS_restrictionBaseType::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_restrictionBaseType result ;
  const GALGAS_restrictionBaseType * p = (const GALGAS_restrictionBaseType *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_restrictionBaseType *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("restrictionBaseType", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath_2D_element::GALGAS_gtlVarPath_2D_element (void) :
mProperty_item () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath_2D_element::~ GALGAS_gtlVarPath_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath_2D_element::GALGAS_gtlVarPath_2D_element (const GALGAS_gtlVarItem & inOperand0) :
mProperty_item (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath_2D_element GALGAS_gtlVarPath_2D_element::constructor_new (const GALGAS_gtlVarItem & in_item 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlVarPath_2D_element result ;
  if (in_item.isValid ()) {
    result = GALGAS_gtlVarPath_2D_element (in_item) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlVarPath_2D_element::objectCompare (const GALGAS_gtlVarPath_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_item.objectCompare (inOperand.mProperty_item) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlVarPath_2D_element::isValid (void) const {
  return mProperty_item.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath_2D_element::drop (void) {
  mProperty_item.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarPath_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @gtlVarPath-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_item.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlVarPath-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarPath_2D_element ("gtlVarPath-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarPath_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarPath_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarPath_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarPath_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath_2D_element GALGAS_gtlVarPath_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarPath_2D_element result ;
  const GALGAS_gtlVarPath_2D_element * p = (const GALGAS_gtlVarPath_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarPath_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarPath-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList_2D_element::GALGAS_gtlTypedArgumentList_2D_element (void) :
mProperty_type () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList_2D_element::~ GALGAS_gtlTypedArgumentList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList_2D_element::GALGAS_gtlTypedArgumentList_2D_element (const GALGAS_type & inOperand0) :
mProperty_type (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList_2D_element GALGAS_gtlTypedArgumentList_2D_element::constructor_new (const GALGAS_type & in_type 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList_2D_element result ;
  if (in_type.isValid ()) {
    result = GALGAS_gtlTypedArgumentList_2D_element (in_type) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlTypedArgumentList_2D_element::objectCompare (const GALGAS_gtlTypedArgumentList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_type.objectCompare (inOperand.mProperty_type) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlTypedArgumentList_2D_element::isValid (void) const {
  return mProperty_type.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList_2D_element::drop (void) {
  mProperty_type.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypedArgumentList_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @gtlTypedArgumentList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_type.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlTypedArgumentList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTypedArgumentList_2D_element ("gtlTypedArgumentList-element",
                                                        NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTypedArgumentList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTypedArgumentList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTypedArgumentList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTypedArgumentList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList_2D_element GALGAS_gtlTypedArgumentList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList_2D_element result ;
  const GALGAS_gtlTypedArgumentList_2D_element * p = (const GALGAS_gtlTypedArgumentList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTypedArgumentList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTypedArgumentList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList_2D_element::GALGAS_gtlInstructionList_2D_element (void) :
mProperty_instruction () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList_2D_element::~ GALGAS_gtlInstructionList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList_2D_element::GALGAS_gtlInstructionList_2D_element (const GALGAS_gtlInstruction & inOperand0) :
mProperty_instruction (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList_2D_element GALGAS_gtlInstructionList_2D_element::constructor_new (const GALGAS_gtlInstruction & in_instruction 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlInstructionList_2D_element result ;
  if (in_instruction.isValid ()) {
    result = GALGAS_gtlInstructionList_2D_element (in_instruction) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlInstructionList_2D_element::objectCompare (const GALGAS_gtlInstructionList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_instruction.objectCompare (inOperand.mProperty_instruction) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlInstructionList_2D_element::isValid (void) const {
  return mProperty_instruction.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList_2D_element::drop (void) {
  mProperty_instruction.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionList_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @gtlInstructionList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_instruction.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlInstructionList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstructionList_2D_element ("gtlInstructionList-element",
                                                      NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlInstructionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstructionList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlInstructionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstructionList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList_2D_element GALGAS_gtlInstructionList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionList_2D_element result ;
  const GALGAS_gtlInstructionList_2D_element * p = (const GALGAS_gtlInstructionList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInstructionList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstructionList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack_2D_element::GALGAS_gtlInstructionListContextStack_2D_element (void) :
mProperty_nextInstructionIndex (),
mProperty_instructionList () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack_2D_element::~ GALGAS_gtlInstructionListContextStack_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack_2D_element::GALGAS_gtlInstructionListContextStack_2D_element (const GALGAS_uint & inOperand0,
                                                                                                    const GALGAS_gtlInstructionList & inOperand1) :
mProperty_nextInstructionIndex (inOperand0),
mProperty_instructionList (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack_2D_element GALGAS_gtlInstructionListContextStack_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlInstructionListContextStack_2D_element (GALGAS_uint::constructor_default (HERE),
                                                           GALGAS_gtlInstructionList::constructor_emptyList (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack_2D_element GALGAS_gtlInstructionListContextStack_2D_element::constructor_new (const GALGAS_uint & in_nextInstructionIndex,
                                                                                                                    const GALGAS_gtlInstructionList & in_instructionList 
                                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlInstructionListContextStack_2D_element result ;
  if (in_nextInstructionIndex.isValid () && in_instructionList.isValid ()) {
    result = GALGAS_gtlInstructionListContextStack_2D_element (in_nextInstructionIndex, in_instructionList) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlInstructionListContextStack_2D_element::objectCompare (const GALGAS_gtlInstructionListContextStack_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_nextInstructionIndex.objectCompare (inOperand.mProperty_nextInstructionIndex) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_instructionList.objectCompare (inOperand.mProperty_instructionList) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlInstructionListContextStack_2D_element::isValid (void) const {
  return mProperty_nextInstructionIndex.isValid () && mProperty_instructionList.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack_2D_element::drop (void) {
  mProperty_nextInstructionIndex.drop () ;
  mProperty_instructionList.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlInstructionListContextStack_2D_element::description (C_String & ioString,
                                                                    const int32_t inIndentation) const {
  ioString << "<struct @gtlInstructionListContextStack-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_nextInstructionIndex.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_instructionList.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlInstructionListContextStack-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlInstructionListContextStack_2D_element ("gtlInstructionListContextStack-element",
                                                                  NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlInstructionListContextStack_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlInstructionListContextStack_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlInstructionListContextStack_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlInstructionListContextStack_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack_2D_element GALGAS_gtlInstructionListContextStack_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                                  C_Compiler * inCompiler
                                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlInstructionListContextStack_2D_element result ;
  const GALGAS_gtlInstructionListContextStack_2D_element * p = (const GALGAS_gtlInstructionListContextStack_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlInstructionListContextStack_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlInstructionListContextStack-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList_2D_element::GALGAS_gtlBreakpointList_2D_element (void) :
mProperty_breakpoint () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList_2D_element::~ GALGAS_gtlBreakpointList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList_2D_element::GALGAS_gtlBreakpointList_2D_element (const GALGAS_gtlBreakpoint & inOperand0) :
mProperty_breakpoint (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList_2D_element GALGAS_gtlBreakpointList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlBreakpointList_2D_element (GALGAS_gtlBreakpoint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList_2D_element GALGAS_gtlBreakpointList_2D_element::constructor_new (const GALGAS_gtlBreakpoint & in_breakpoint 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlBreakpointList_2D_element result ;
  if (in_breakpoint.isValid ()) {
    result = GALGAS_gtlBreakpointList_2D_element (in_breakpoint) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlBreakpointList_2D_element::objectCompare (const GALGAS_gtlBreakpointList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_breakpoint.objectCompare (inOperand.mProperty_breakpoint) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlBreakpointList_2D_element::isValid (void) const {
  return mProperty_breakpoint.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList_2D_element::drop (void) {
  mProperty_breakpoint.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBreakpointList_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @gtlBreakpointList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_breakpoint.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlBreakpointList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBreakpointList_2D_element ("gtlBreakpointList-element",
                                                     NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlBreakpointList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBreakpointList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlBreakpointList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBreakpointList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList_2D_element GALGAS_gtlBreakpointList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlBreakpointList_2D_element result ;
  const GALGAS_gtlBreakpointList_2D_element * p = (const GALGAS_gtlBreakpointList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBreakpointList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBreakpointList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element::GALGAS_uint_33__32_List_2D_element (void) :
mProperty_location (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element::~ GALGAS_uint_33__32_List_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element::GALGAS_uint_33__32_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_uint & inOperand1) :
mProperty_location (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element GALGAS_uint_33__32_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_33__32_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_uint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element GALGAS_uint_33__32_List_2D_element::constructor_new (const GALGAS_location & in_location,
                                                                                        const GALGAS_uint & in_value 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_33__32_List_2D_element result ;
  if (in_location.isValid () && in_value.isValid ()) {
    result = GALGAS_uint_33__32_List_2D_element (in_location, in_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_uint_33__32_List_2D_element::objectCompare (const GALGAS_uint_33__32_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_uint_33__32_List_2D_element::isValid (void) const {
  return mProperty_location.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List_2D_element::drop (void) {
  mProperty_location.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_33__32_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @uint32List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @uint32List-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_33__32_List_2D_element ("uint32List-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_33__32_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_33__32_List_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_33__32_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_33__32_List_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_33__32_List_2D_element GALGAS_uint_33__32_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_33__32_List_2D_element result ;
  const GALGAS_uint_33__32_List_2D_element * p = (const GALGAS_uint_33__32_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_33__32_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint32List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element::GALGAS_uint_36__34_List_2D_element (void) :
mProperty_location (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element::~ GALGAS_uint_36__34_List_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element::GALGAS_uint_36__34_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_uint_36__34_ & inOperand1) :
mProperty_location (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element GALGAS_uint_36__34_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_uint_36__34_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_uint_36__34_::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element GALGAS_uint_36__34_List_2D_element::constructor_new (const GALGAS_location & in_location,
                                                                                        const GALGAS_uint_36__34_ & in_value 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_List_2D_element result ;
  if (in_location.isValid () && in_value.isValid ()) {
    result = GALGAS_uint_36__34_List_2D_element (in_location, in_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_uint_36__34_List_2D_element::objectCompare (const GALGAS_uint_36__34_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_uint_36__34_List_2D_element::isValid (void) const {
  return mProperty_location.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List_2D_element::drop (void) {
  mProperty_location.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_uint_36__34_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @uint64List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @uint64List-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_uint_36__34_List_2D_element ("uint64List-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_uint_36__34_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_uint_36__34_List_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_uint_36__34_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_uint_36__34_List_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint_36__34_List_2D_element GALGAS_uint_36__34_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_uint_36__34_List_2D_element result ;
  const GALGAS_uint_36__34_List_2D_element * p = (const GALGAS_uint_36__34_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_uint_36__34_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("uint64List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element::GALGAS_sint_33__32_List_2D_element (void) :
mProperty_location (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element::~ GALGAS_sint_33__32_List_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element::GALGAS_sint_33__32_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_sint & inOperand1) :
mProperty_location (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element GALGAS_sint_33__32_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_33__32_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_sint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element GALGAS_sint_33__32_List_2D_element::constructor_new (const GALGAS_location & in_location,
                                                                                        const GALGAS_sint & in_value 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_33__32_List_2D_element result ;
  if (in_location.isValid () && in_value.isValid ()) {
    result = GALGAS_sint_33__32_List_2D_element (in_location, in_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_sint_33__32_List_2D_element::objectCompare (const GALGAS_sint_33__32_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_sint_33__32_List_2D_element::isValid (void) const {
  return mProperty_location.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List_2D_element::drop (void) {
  mProperty_location.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_33__32_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @sint32List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @sint32List-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_33__32_List_2D_element ("sint32List-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_33__32_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_33__32_List_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_33__32_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_33__32_List_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_33__32_List_2D_element GALGAS_sint_33__32_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_33__32_List_2D_element result ;
  const GALGAS_sint_33__32_List_2D_element * p = (const GALGAS_sint_33__32_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_33__32_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint32List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element::GALGAS_sint_36__34_List_2D_element (void) :
mProperty_location (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element::~ GALGAS_sint_36__34_List_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element::GALGAS_sint_36__34_List_2D_element (const GALGAS_location & inOperand0,
                                                                        const GALGAS_sint_36__34_ & inOperand1) :
mProperty_location (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element GALGAS_sint_36__34_List_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sint_36__34_List_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                             GALGAS_sint_36__34_::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element GALGAS_sint_36__34_List_2D_element::constructor_new (const GALGAS_location & in_location,
                                                                                        const GALGAS_sint_36__34_ & in_value 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_List_2D_element result ;
  if (in_location.isValid () && in_value.isValid ()) {
    result = GALGAS_sint_36__34_List_2D_element (in_location, in_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_sint_36__34_List_2D_element::objectCompare (const GALGAS_sint_36__34_List_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_sint_36__34_List_2D_element::isValid (void) const {
  return mProperty_location.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List_2D_element::drop (void) {
  mProperty_location.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sint_36__34_List_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @sint64List-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @sint64List-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sint_36__34_List_2D_element ("sint64List-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sint_36__34_List_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sint_36__34_List_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sint_36__34_List_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sint_36__34_List_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint_36__34_List_2D_element GALGAS_sint_36__34_List_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_sint_36__34_List_2D_element result ;
  const GALGAS_sint_36__34_List_2D_element * p = (const GALGAS_sint_36__34_List_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sint_36__34_List_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sint64List-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element::GALGAS_floatList_2D_element (void) :
mProperty_location (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element::~ GALGAS_floatList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element::GALGAS_floatList_2D_element (const GALGAS_location & inOperand0,
                                                          const GALGAS_double & inOperand1) :
mProperty_location (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element GALGAS_floatList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_floatList_2D_element (GALGAS_location::constructor_nowhere (HERE),
                                      GALGAS_double::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element GALGAS_floatList_2D_element::constructor_new (const GALGAS_location & in_location,
                                                                          const GALGAS_double & in_value 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_floatList_2D_element result ;
  if (in_location.isValid () && in_value.isValid ()) {
    result = GALGAS_floatList_2D_element (in_location, in_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_floatList_2D_element::objectCompare (const GALGAS_floatList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_floatList_2D_element::isValid (void) const {
  return mProperty_location.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList_2D_element::drop (void) {
  mProperty_location.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_floatList_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @floatList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @floatList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_floatList_2D_element ("floatList-element",
                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_floatList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_floatList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_floatList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_floatList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_floatList_2D_element GALGAS_floatList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_floatList_2D_element result ;
  const GALGAS_floatList_2D_element * p = (const GALGAS_floatList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_floatList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("floatList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element::GALGAS_locationList_2D_element (void) :
mProperty_location () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element::~ GALGAS_locationList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element::GALGAS_locationList_2D_element (const GALGAS_location & inOperand0) :
mProperty_location (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element GALGAS_locationList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_locationList_2D_element (GALGAS_location::constructor_nowhere (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element GALGAS_locationList_2D_element::constructor_new (const GALGAS_location & in_location 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_locationList_2D_element result ;
  if (in_location.isValid ()) {
    result = GALGAS_locationList_2D_element (in_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_locationList_2D_element::objectCompare (const GALGAS_locationList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_locationList_2D_element::isValid (void) const {
  return mProperty_location.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList_2D_element::drop (void) {
  mProperty_location.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_locationList_2D_element::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "<struct @locationList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_location.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @locationList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_locationList_2D_element ("locationList-element",
                                                NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_locationList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_locationList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_locationList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_locationList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_locationList_2D_element GALGAS_locationList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_locationList_2D_element result ;
  const GALGAS_locationList_2D_element * p = (const GALGAS_locationList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_locationList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("locationList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList_2D_element::GALGAS_arxmlNodeList_2D_element (void) :
mProperty_node () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList_2D_element::~ GALGAS_arxmlNodeList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList_2D_element::GALGAS_arxmlNodeList_2D_element (const GALGAS_arxmlNode & inOperand0) :
mProperty_node (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList_2D_element GALGAS_arxmlNodeList_2D_element::constructor_new (const GALGAS_arxmlNode & in_node 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlNodeList_2D_element result ;
  if (in_node.isValid ()) {
    result = GALGAS_arxmlNodeList_2D_element (in_node) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_arxmlNodeList_2D_element::objectCompare (const GALGAS_arxmlNodeList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_node.objectCompare (inOperand.mProperty_node) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlNodeList_2D_element::isValid (void) const {
  return mProperty_node.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList_2D_element::drop (void) {
  mProperty_node.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlNodeList_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @arxmlNodeList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_node.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlNodeList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlNodeList_2D_element ("arxmlNodeList-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlNodeList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlNodeList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlNodeList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlNodeList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList_2D_element GALGAS_arxmlNodeList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_arxmlNodeList_2D_element result ;
  const GALGAS_arxmlNodeList_2D_element * p = (const GALGAS_arxmlNodeList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlNodeList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlNodeList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_debuggerContext::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_debuggerContext) ;
  if (kOperandEqual == result) {
    result = mProperty_debugActive.objectCompare (p->mProperty_debugActive) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_breakOnNext.objectCompare (p->mProperty_breakOnNext) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_loopOnCommand.objectCompare (p->mProperty_loopOnCommand) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_promptColor.objectCompare (p->mProperty_promptColor) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_promptFace.objectCompare (p->mProperty_promptFace) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_instructionColor.objectCompare (p->mProperty_instructionColor) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_instructionFace.objectCompare (p->mProperty_instructionFace) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_outputColor.objectCompare (p->mProperty_outputColor) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_outputFace.objectCompare (p->mProperty_outputFace) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_warningColor.objectCompare (p->mProperty_warningColor) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_warningFace.objectCompare (p->mProperty_warningFace) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_executeDebuggerCommand.objectCompare (p->mProperty_executeDebuggerCommand) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_doList.objectCompare (p->mProperty_doList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_breakpoints.objectCompare (p->mProperty_breakpoints) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_watchpoints.objectCompare (p->mProperty_watchpoints) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_nextInstructionIndex.objectCompare (p->mProperty_nextInstructionIndex) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_instructionList.objectCompare (p->mProperty_instructionList) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_contextStack.objectCompare (p->mProperty_contextStack) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_commandInput.objectCompare (p->mProperty_commandInput) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_debuggerContext::objectCompare (const GALGAS_debuggerContext & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debuggerContext::GALGAS_debuggerContext (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debuggerContext GALGAS_debuggerContext::constructor_default (LOCATION_ARGS) {
  return GALGAS_debuggerContext::constructor_new (GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_string::constructor_default (HERE),
                                                  GALGAS_bool::constructor_default (HERE),
                                                  GALGAS_gtlInstructionList::constructor_emptyList (HERE),
                                                  GALGAS_gtlBreakpointList::constructor_emptyList (HERE),
                                                  GALGAS_gtlExpressionList::constructor_emptyList (HERE),
                                                  GALGAS_uint::constructor_default (HERE),
                                                  GALGAS_gtlInstructionList::constructor_emptyList (HERE),
                                                  GALGAS_gtlInstructionListContextStack::constructor_emptyList (HERE),
                                                  GALGAS_debugCommandInput::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debuggerContext::GALGAS_debuggerContext (const cPtr_debuggerContext * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_debuggerContext) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_debuggerContext GALGAS_debuggerContext::constructor_new (const GALGAS_bool & inAttribute_debugActive,
                                                                const GALGAS_bool & inAttribute_breakOnNext,
                                                                const GALGAS_bool & inAttribute_loopOnCommand,
                                                                const GALGAS_string & inAttribute_promptColor,
                                                                const GALGAS_string & inAttribute_promptFace,
                                                                const GALGAS_string & inAttribute_instructionColor,
                                                                const GALGAS_string & inAttribute_instructionFace,
                                                                const GALGAS_string & inAttribute_outputColor,
                                                                const GALGAS_string & inAttribute_outputFace,
                                                                const GALGAS_string & inAttribute_warningColor,
                                                                const GALGAS_string & inAttribute_warningFace,
                                                                const GALGAS_bool & inAttribute_executeDebuggerCommand,
                                                                const GALGAS_gtlInstructionList & inAttribute_doList,
                                                                const GALGAS_gtlBreakpointList & inAttribute_breakpoints,
                                                                const GALGAS_gtlExpressionList & inAttribute_watchpoints,
                                                                const GALGAS_uint & inAttribute_nextInstructionIndex,
                                                                const GALGAS_gtlInstructionList & inAttribute_instructionList,
                                                                const GALGAS_gtlInstructionListContextStack & inAttribute_contextStack,
                                                                const GALGAS_debugCommandInput & inAttribute_commandInput
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_debuggerContext result ;
  if (inAttribute_debugActive.isValid () && inAttribute_breakOnNext.isValid () && inAttribute_loopOnCommand.isValid () && inAttribute_promptColor.isValid () && inAttribute_promptFace.isValid () && inAttribute_instructionColor.isValid () && inAttribute_instructionFace.isValid () && inAttribute_outputColor.isValid () && inAttribute_outputFace.isValid () && inAttribute_warningColor.isValid () && inAttribute_warningFace.isValid () && inAttribute_executeDebuggerCommand.isValid () && inAttribute_doList.isValid () && inAttribute_breakpoints.isValid () && inAttribute_watchpoints.isValid () && inAttribute_nextInstructionIndex.isValid () && inAttribute_instructionList.isValid () && inAttribute_contextStack.isValid () && inAttribute_commandInput.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_debuggerContext (inAttribute_debugActive, inAttribute_breakOnNext, inAttribute_loopOnCommand, inAttribute_promptColor, inAttribute_promptFace, inAttribute_instructionColor, inAttribute_instructionFace, inAttribute_outputColor, inAttribute_outputFace, inAttribute_warningColor, inAttribute_warningFace, inAttribute_executeDebuggerCommand, inAttribute_doList, inAttribute_breakpoints, inAttribute_watchpoints, inAttribute_nextInstructionIndex, inAttribute_instructionList, inAttribute_contextStack, inAttribute_commandInput COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_debuggerContext::readProperty_debugActive (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_debugActive ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_debuggerContext::getter_debugActive (UNUSED_LOCATION_ARGS) const {
  return mProperty_debugActive ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_debuggerContext::readProperty_breakOnNext (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_breakOnNext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_debuggerContext::getter_breakOnNext (UNUSED_LOCATION_ARGS) const {
  return mProperty_breakOnNext ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_debuggerContext::readProperty_loopOnCommand (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_loopOnCommand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_debuggerContext::getter_loopOnCommand (UNUSED_LOCATION_ARGS) const {
  return mProperty_loopOnCommand ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_debuggerContext::readProperty_promptColor (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_promptColor ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_debuggerContext::getter_promptColor (UNUSED_LOCATION_ARGS) const {
  return mProperty_promptColor ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_debuggerContext::readProperty_promptFace (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_promptFace ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_debuggerContext::getter_promptFace (UNUSED_LOCATION_ARGS) const {
  return mProperty_promptFace ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_debuggerContext::readProperty_instructionColor (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_instructionColor ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_debuggerContext::getter_instructionColor (UNUSED_LOCATION_ARGS) const {
  return mProperty_instructionColor ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_debuggerContext::readProperty_instructionFace (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_instructionFace ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_debuggerContext::getter_instructionFace (UNUSED_LOCATION_ARGS) const {
  return mProperty_instructionFace ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_debuggerContext::readProperty_outputColor (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_outputColor ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_debuggerContext::getter_outputColor (UNUSED_LOCATION_ARGS) const {
  return mProperty_outputColor ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_debuggerContext::readProperty_outputFace (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_outputFace ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_debuggerContext::getter_outputFace (UNUSED_LOCATION_ARGS) const {
  return mProperty_outputFace ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_debuggerContext::readProperty_warningColor (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_warningColor ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_debuggerContext::getter_warningColor (UNUSED_LOCATION_ARGS) const {
  return mProperty_warningColor ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_debuggerContext::readProperty_warningFace (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_warningFace ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_debuggerContext::getter_warningFace (UNUSED_LOCATION_ARGS) const {
  return mProperty_warningFace ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_debuggerContext::readProperty_executeDebuggerCommand (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_executeDebuggerCommand ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_debuggerContext::getter_executeDebuggerCommand (UNUSED_LOCATION_ARGS) const {
  return mProperty_executeDebuggerCommand ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_debuggerContext::readProperty_doList (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_doList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_debuggerContext::getter_doList (UNUSED_LOCATION_ARGS) const {
  return mProperty_doList ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList GALGAS_debuggerContext::readProperty_breakpoints (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlBreakpointList () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_breakpoints ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBreakpointList cPtr_debuggerContext::getter_breakpoints (UNUSED_LOCATION_ARGS) const {
  return mProperty_breakpoints ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_debuggerContext::readProperty_watchpoints (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpressionList () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_watchpoints ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList cPtr_debuggerContext::getter_watchpoints (UNUSED_LOCATION_ARGS) const {
  return mProperty_watchpoints ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint GALGAS_debuggerContext::readProperty_nextInstructionIndex (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_uint () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_nextInstructionIndex ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_uint cPtr_debuggerContext::getter_nextInstructionIndex (UNUSED_LOCATION_ARGS) const {
  return mProperty_nextInstructionIndex ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_debuggerContext::readProperty_instructionList (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_instructionList ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_debuggerContext::getter_instructionList (UNUSED_LOCATION_ARGS) const {
  return mProperty_instructionList ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack GALGAS_debuggerContext::readProperty_contextStack (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlInstructionListContextStack () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_contextStack ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionListContextStack cPtr_debuggerContext::getter_contextStack (UNUSED_LOCATION_ARGS) const {
  return mProperty_contextStack ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debugCommandInput GALGAS_debuggerContext::readProperty_commandInput (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_debugCommandInput () ;
  }else{
    const cPtr_debuggerContext * p = (const cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    return p->mProperty_commandInput ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debugCommandInput cPtr_debuggerContext::getter_commandInput (UNUSED_LOCATION_ARGS) const {
  return mProperty_commandInput ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setDebugActive (GALGAS_bool inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_debugActive = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setDebugActive (GALGAS_bool inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_debugActive = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setBreakOnNext (GALGAS_bool inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_breakOnNext = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setBreakOnNext (GALGAS_bool inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_breakOnNext = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setLoopOnCommand (GALGAS_bool inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_loopOnCommand = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setLoopOnCommand (GALGAS_bool inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_loopOnCommand = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setPromptColor (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_promptColor = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setPromptColor (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_promptColor = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setPromptFace (GALGAS_string inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_promptFace = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setPromptFace (GALGAS_string inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_promptFace = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setInstructionColor (GALGAS_string inValue
                                                         COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_instructionColor = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setInstructionColor (GALGAS_string inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_instructionColor = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setInstructionFace (GALGAS_string inValue
                                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_instructionFace = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setInstructionFace (GALGAS_string inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_instructionFace = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setOutputColor (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_outputColor = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setOutputColor (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_outputColor = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setOutputFace (GALGAS_string inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_outputFace = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setOutputFace (GALGAS_string inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_outputFace = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setWarningColor (GALGAS_string inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_warningColor = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setWarningColor (GALGAS_string inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_warningColor = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setWarningFace (GALGAS_string inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_warningFace = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setWarningFace (GALGAS_string inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_warningFace = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setExecuteDebuggerCommand (GALGAS_bool inValue
                                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_executeDebuggerCommand = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setExecuteDebuggerCommand (GALGAS_bool inValue
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_executeDebuggerCommand = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setDoList (GALGAS_gtlInstructionList inValue
                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_doList = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setDoList (GALGAS_gtlInstructionList inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_doList = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setBreakpoints (GALGAS_gtlBreakpointList inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_breakpoints = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setBreakpoints (GALGAS_gtlBreakpointList inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_breakpoints = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setWatchpoints (GALGAS_gtlExpressionList inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_watchpoints = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setWatchpoints (GALGAS_gtlExpressionList inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_watchpoints = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setNextInstructionIndex (GALGAS_uint inValue
                                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_nextInstructionIndex = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setNextInstructionIndex (GALGAS_uint inValue
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_nextInstructionIndex = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setInstructionList (GALGAS_gtlInstructionList inValue
                                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_instructionList = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setInstructionList (GALGAS_gtlInstructionList inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_instructionList = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setContextStack (GALGAS_gtlInstructionListContextStack inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_contextStack = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setContextStack (GALGAS_gtlInstructionListContextStack inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_contextStack = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_debuggerContext::setter_setCommandInput (GALGAS_debugCommandInput inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_debuggerContext * p = (cPtr_debuggerContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_debuggerContext) ;
    p->mProperty_commandInput = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_debuggerContext::setter_setCommandInput (GALGAS_debugCommandInput inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_commandInput = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @debuggerContext class
//----------------------------------------------------------------------------------------------------------------------

cPtr_debuggerContext::cPtr_debuggerContext (const GALGAS_bool & in_debugActive,
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
                                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_debugActive (in_debugActive),
mProperty_breakOnNext (in_breakOnNext),
mProperty_loopOnCommand (in_loopOnCommand),
mProperty_promptColor (in_promptColor),
mProperty_promptFace (in_promptFace),
mProperty_instructionColor (in_instructionColor),
mProperty_instructionFace (in_instructionFace),
mProperty_outputColor (in_outputColor),
mProperty_outputFace (in_outputFace),
mProperty_warningColor (in_warningColor),
mProperty_warningFace (in_warningFace),
mProperty_executeDebuggerCommand (in_executeDebuggerCommand),
mProperty_doList (in_doList),
mProperty_breakpoints (in_breakpoints),
mProperty_watchpoints (in_watchpoints),
mProperty_nextInstructionIndex (in_nextInstructionIndex),
mProperty_instructionList (in_instructionList),
mProperty_contextStack (in_contextStack),
mProperty_commandInput (in_commandInput) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_debuggerContext::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_debuggerContext ;
}

void cPtr_debuggerContext::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@debuggerContext:" ;
  mProperty_debugActive.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_breakOnNext.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_loopOnCommand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_promptColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_promptFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_instructionColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_instructionFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_outputColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_outputFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_warningColor.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_warningFace.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_executeDebuggerCommand.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_doList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_breakpoints.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_watchpoints.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_nextInstructionIndex.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_instructionList.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_contextStack.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_commandInput.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_debuggerContext::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_debuggerContext (mProperty_debugActive, mProperty_breakOnNext, mProperty_loopOnCommand, mProperty_promptColor, mProperty_promptFace, mProperty_instructionColor, mProperty_instructionFace, mProperty_outputColor, mProperty_outputFace, mProperty_warningColor, mProperty_warningFace, mProperty_executeDebuggerCommand, mProperty_doList, mProperty_breakpoints, mProperty_watchpoints, mProperty_nextInstructionIndex, mProperty_instructionList, mProperty_contextStack, mProperty_commandInput COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @debuggerContext generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_debuggerContext ("debuggerContext",
                                        NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_debuggerContext::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_debuggerContext ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_debuggerContext::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_debuggerContext (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debuggerContext GALGAS_debuggerContext::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_debuggerContext result ;
  const GALGAS_debuggerContext * p = (const GALGAS_debuggerContext *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_debuggerContext *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("debuggerContext", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_gtlData::objectCompare (const GALGAS_gtlData & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData::GALGAS_gtlData (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData::GALGAS_gtlData (const cPtr_gtlData * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlData) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_gtlData::readProperty_where (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_location () ;
  }else{
    const cPtr_gtlData * p = (const cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    return p->mProperty_where ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlData::getter_where (UNUSED_LOCATION_ARGS) const {
  return mProperty_where ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlData::readProperty_meta (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlData * p = (const cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    return p->mProperty_meta ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlData::getter_meta (UNUSED_LOCATION_ARGS) const {
  return mProperty_meta ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlData::setter_setWhere (GALGAS_location inValue
                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlData * p = (cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    p->mProperty_where = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlData::setter_setWhere (GALGAS_location inValue
                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_where = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlData::setter_setMeta (GALGAS_lstring inValue
                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlData * p = (cPtr_gtlData *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlData) ;
    p->mProperty_meta = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlData::setter_setMeta (GALGAS_lstring inValue
                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_meta = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlData class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlData::cPtr_gtlData (const GALGAS_location & in_where,
                            const GALGAS_lstring & in_meta
                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_where (in_where),
mProperty_meta (in_meta) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlData generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlData ("gtlData",
                                NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlData::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlData ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlData::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlData (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData GALGAS_gtlData::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  const GALGAS_gtlData * p = (const GALGAS_gtlData *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlData *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlData", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_gtlExpression::objectCompare (const GALGAS_gtlExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression::GALGAS_gtlExpression (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression::GALGAS_gtlExpression (const cPtr_gtlExpression * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_gtlExpression::readProperty_where (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_location () ;
  }else{
    const cPtr_gtlExpression * p = (const cPtr_gtlExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExpression) ;
    return p->mProperty_where ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlExpression::getter_where (UNUSED_LOCATION_ARGS) const {
  return mProperty_where ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpression::setter_setWhere (GALGAS_location inValue
                                            COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlExpression * p = (cPtr_gtlExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExpression) ;
    p->mProperty_where = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlExpression::setter_setWhere (GALGAS_location inValue
                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_where = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlExpression::cPtr_gtlExpression (const GALGAS_location & in_where
                                        COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_where (in_where) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpression ("gtlExpression",
                                      NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlExpression::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpression result ;
  const GALGAS_gtlExpression * p = (const GALGAS_gtlExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlTemplate::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTemplate * p = (const cPtr_gtlTemplate *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTemplate) ;
  if (kOperandEqual == result) {
    result = mProperty_path.objectCompare (p->mProperty_path) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_program.objectCompare (p->mProperty_program) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlTemplate::objectCompare (const GALGAS_gtlTemplate & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplate::GALGAS_gtlTemplate (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplate GALGAS_gtlTemplate::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlTemplate::constructor_new (GALGAS_string::constructor_default (HERE),
                                              GALGAS_gtlInstructionList::constructor_emptyList (HERE)
                                              COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplate::GALGAS_gtlTemplate (const cPtr_gtlTemplate * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTemplate) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplate GALGAS_gtlTemplate::constructor_new (const GALGAS_string & inAttribute_path,
                                                        const GALGAS_gtlInstructionList & inAttribute_program
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplate result ;
  if (inAttribute_path.isValid () && inAttribute_program.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTemplate (inAttribute_path, inAttribute_program COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlTemplate::readProperty_path (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlTemplate * p = (const cPtr_gtlTemplate *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplate) ;
    return p->mProperty_path ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlTemplate::getter_path (UNUSED_LOCATION_ARGS) const {
  return mProperty_path ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList GALGAS_gtlTemplate::readProperty_program (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlInstructionList () ;
  }else{
    const cPtr_gtlTemplate * p = (const cPtr_gtlTemplate *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplate) ;
    return p->mProperty_program ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlInstructionList cPtr_gtlTemplate::getter_program (UNUSED_LOCATION_ARGS) const {
  return mProperty_program ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplate::setter_setPath (GALGAS_string inValue
                                         COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTemplate * p = (cPtr_gtlTemplate *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplate) ;
    p->mProperty_path = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTemplate::setter_setPath (GALGAS_string inValue
                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_path = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplate::setter_setProgram (GALGAS_gtlInstructionList inValue
                                            COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTemplate * p = (cPtr_gtlTemplate *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTemplate) ;
    p->mProperty_program = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTemplate::setter_setProgram (GALGAS_gtlInstructionList inValue
                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_program = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlTemplate class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlTemplate::cPtr_gtlTemplate (const GALGAS_string & in_path,
                                    const GALGAS_gtlInstructionList & in_program
                                    COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_path (in_path),
mProperty_program (in_program) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlTemplate::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplate ;
}

void cPtr_gtlTemplate::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@gtlTemplate:" ;
  mProperty_path.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_program.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlTemplate::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlTemplate (mProperty_path, mProperty_program COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlTemplate generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplate ("gtlTemplate",
                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTemplate::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplate ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTemplate::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplate (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplate GALGAS_gtlTemplate::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplate result ;
  const GALGAS_gtlTemplate * p = (const GALGAS_gtlTemplate *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTemplate *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplate", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlTemplate execute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTemplate::method_execute (GALGAS_gtlContext & ioArgument_context,
                                       GALGAS_gtlData & ioArgument_vars,
                                       GALGAS_library & ioArgument_lib,
                                       GALGAS_string & ioArgument_outputString,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  extensionMethod_execute (this->mProperty_program, ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 269)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_execute (cPtr_gtlTemplate * inObject,
                                  GALGAS_gtlContext & io_context,
                                  GALGAS_gtlData & io_vars,
                                  GALGAS_library & io_lib,
                                  GALGAS_string & io_outputString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlTemplate) ;
    inObject->method_execute  (io_context, io_vars, io_lib, io_outputString, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_library::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_library * p = (const cPtr_library *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_library) ;
  if (kOperandEqual == result) {
    result = mProperty_funcMap.objectCompare (p->mProperty_funcMap) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_getterMap.objectCompare (p->mProperty_getterMap) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_setterMap.objectCompare (p->mProperty_setterMap) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_templateMap.objectCompare (p->mProperty_templateMap) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_doneImports.objectCompare (p->mProperty_doneImports) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_library::objectCompare (const GALGAS_library & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_library::GALGAS_library (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_library GALGAS_library::constructor_default (LOCATION_ARGS) {
  return GALGAS_library::constructor_new (GALGAS_gtlFuncMap::constructor_emptyMap (HERE),
                                          GALGAS_gtlGetterMap::constructor_emptyMap (HERE),
                                          GALGAS_gtlSetterMap::constructor_emptyMap (HERE),
                                          GALGAS_gtlTemplateMap::constructor_emptyMap (HERE),
                                          GALGAS_stringset::constructor_emptySet (HERE)
                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_library::GALGAS_library (const cPtr_library * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_library) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_library GALGAS_library::constructor_new (const GALGAS_gtlFuncMap & inAttribute_funcMap,
                                                const GALGAS_gtlGetterMap & inAttribute_getterMap,
                                                const GALGAS_gtlSetterMap & inAttribute_setterMap,
                                                const GALGAS_gtlTemplateMap & inAttribute_templateMap,
                                                const GALGAS_stringset & inAttribute_doneImports
                                                COMMA_LOCATION_ARGS) {
  GALGAS_library result ;
  if (inAttribute_funcMap.isValid () && inAttribute_getterMap.isValid () && inAttribute_setterMap.isValid () && inAttribute_templateMap.isValid () && inAttribute_doneImports.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_library (inAttribute_funcMap, inAttribute_getterMap, inAttribute_setterMap, inAttribute_templateMap, inAttribute_doneImports COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap GALGAS_library::readProperty_funcMap (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlFuncMap () ;
  }else{
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    return p->mProperty_funcMap ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap cPtr_library::getter_funcMap (UNUSED_LOCATION_ARGS) const {
  return mProperty_funcMap ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap GALGAS_library::readProperty_getterMap (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlGetterMap () ;
  }else{
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    return p->mProperty_getterMap ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap cPtr_library::getter_getterMap (UNUSED_LOCATION_ARGS) const {
  return mProperty_getterMap ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap GALGAS_library::readProperty_setterMap (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlSetterMap () ;
  }else{
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    return p->mProperty_setterMap ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap cPtr_library::getter_setterMap (UNUSED_LOCATION_ARGS) const {
  return mProperty_setterMap ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap GALGAS_library::readProperty_templateMap (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlTemplateMap () ;
  }else{
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    return p->mProperty_templateMap ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap cPtr_library::getter_templateMap (UNUSED_LOCATION_ARGS) const {
  return mProperty_templateMap ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset GALGAS_library::readProperty_doneImports (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_stringset () ;
  }else{
    const cPtr_library * p = (const cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    return p->mProperty_doneImports ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset cPtr_library::getter_doneImports (UNUSED_LOCATION_ARGS) const {
  return mProperty_doneImports ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_library::setter_setFuncMap (GALGAS_gtlFuncMap inValue
                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_library * p = (cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    p->mProperty_funcMap = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_library::setter_setFuncMap (GALGAS_gtlFuncMap inValue
                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_funcMap = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_library::setter_setGetterMap (GALGAS_gtlGetterMap inValue
                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_library * p = (cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    p->mProperty_getterMap = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_library::setter_setGetterMap (GALGAS_gtlGetterMap inValue
                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_getterMap = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_library::setter_setSetterMap (GALGAS_gtlSetterMap inValue
                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_library * p = (cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    p->mProperty_setterMap = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_library::setter_setSetterMap (GALGAS_gtlSetterMap inValue
                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_setterMap = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_library::setter_setTemplateMap (GALGAS_gtlTemplateMap inValue
                                            COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_library * p = (cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    p->mProperty_templateMap = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_library::setter_setTemplateMap (GALGAS_gtlTemplateMap inValue
                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_templateMap = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_library::setter_setDoneImports (GALGAS_stringset inValue
                                            COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_library * p = (cPtr_library *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_library) ;
    p->mProperty_doneImports = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_library::setter_setDoneImports (GALGAS_stringset inValue
                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_doneImports = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @library class
//----------------------------------------------------------------------------------------------------------------------

cPtr_library::cPtr_library (const GALGAS_gtlFuncMap & in_funcMap,
                            const GALGAS_gtlGetterMap & in_getterMap,
                            const GALGAS_gtlSetterMap & in_setterMap,
                            const GALGAS_gtlTemplateMap & in_templateMap,
                            const GALGAS_stringset & in_doneImports
                            COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_funcMap (in_funcMap),
mProperty_getterMap (in_getterMap),
mProperty_setterMap (in_setterMap),
mProperty_templateMap (in_templateMap),
mProperty_doneImports (in_doneImports) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_library::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_library ;
}

void cPtr_library::description (C_String & ioString,
                                const int32_t inIndentation) const {
  ioString << "[@library:" ;
  mProperty_funcMap.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_getterMap.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_setterMap.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_templateMap.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_doneImports.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_library::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_library (mProperty_funcMap, mProperty_getterMap, mProperty_setterMap, mProperty_templateMap, mProperty_doneImports COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @library generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_library ("library",
                                NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_library::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_library ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_library::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_library (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_library GALGAS_library::extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_library result ;
  const GALGAS_library * p = (const GALGAS_library *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_library *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("library", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library functionExists'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_library::getter_functionExists (const GALGAS_lstring constinArgument_name,
                                                 C_Compiler */* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_exists ; // Returned variable
  result_exists = this->mProperty_funcMap.getter_hasKey (constinArgument_name.readProperty_string () COMMA_SOURCE_FILE ("gtl_types.galgas", 330)) ;
//---
  return result_exists ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_functionExists (const cPtr_library * inObject,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_functionExists (in_name, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library getFunction'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFunction cPtr_library::getter_getFunction (const GALGAS_lstring constinArgument_name,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlFunction result_aFunction ; // Returned variable
  this->mProperty_funcMap.method_get (constinArgument_name, result_aFunction, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 337)) ;
//---
  return result_aFunction ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFunction callExtensionGetter_getFunction (const cPtr_library * inObject,
                                                    const GALGAS_lstring in_name,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlFunction result ;
  if (nullptr != inObject) {
    result = inObject->getter_getFunction (in_name, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library putFunction'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_library_putFunction> gExtensionModifierTable_library_putFunction ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_putFunction (const int32_t inClassIndex,
                                       extensionSetterSignature_library_putFunction inModifier) {
  gExtensionModifierTable_library_putFunction.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_putFunction (cPtr_library * inObject,
                                      const GALGAS_lstring constin_name,
                                      const GALGAS_gtlFunction constin_aFunction,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_putFunction f = NULL ;
    if (classIndex < gExtensionModifierTable_library_putFunction.count ()) {
      f = gExtensionModifierTable_library_putFunction (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_putFunction.count ()) {
           f = gExtensionModifierTable_library_putFunction (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_putFunction.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_aFunction, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_library_putFunction (cPtr_library * inObject,
                                                 const GALGAS_lstring constinArgument_name,
                                                 const GALGAS_gtlFunction constinArgument_aFunction,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  object->mProperty_funcMap.setter_put (constinArgument_name, constinArgument_aFunction, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 344)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_library_putFunction (void) {
  enterExtensionSetter_putFunction (kTypeDescriptor_GALGAS_library.mSlotID,
                                    extensionSetter_library_putFunction) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_library_putFunction (void) {
  gExtensionModifierTable_library_putFunction.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_library_putFunction (defineExtensionSetter_library_putFunction,
                                                freeExtensionModifier_library_putFunction) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library getterExists'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_library::getter_getterExists (const GALGAS_string constinArgument_type,
                                               const GALGAS_lstring constinArgument_name,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_exists ; // Returned variable
  result_exists = this->mProperty_getterMap.getter_hasKey (constinArgument_type.add_operation (constinArgument_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 352)) COMMA_SOURCE_FILE ("gtl_types.galgas", 352)) ;
//---
  return result_exists ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_getterExists (const cPtr_library * inObject,
                                              const GALGAS_string in_type,
                                              const GALGAS_lstring in_name,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_getterExists (in_type, in_name, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library getGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetter cPtr_library::getter_getGetter (const GALGAS_string constinArgument_type,
                                                 const GALGAS_lstring constinArgument_name,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlGetter result_aGetter ; // Returned variable
  this->mProperty_getterMap.method_get (GALGAS_lstring::constructor_new (constinArgument_type.add_operation (constinArgument_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 360)), constinArgument_name.readProperty_location ()  COMMA_SOURCE_FILE ("gtl_types.galgas", 360)), result_aGetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 360)) ;
//---
  return result_aGetter ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetter callExtensionGetter_getGetter (const cPtr_library * inObject,
                                                const GALGAS_string in_type,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetter result ;
  if (nullptr != inObject) {
    result = inObject->getter_getGetter (in_type, in_name, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library putGetter'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_library_putGetter> gExtensionModifierTable_library_putGetter ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_putGetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putGetter inModifier) {
  gExtensionModifierTable_library_putGetter.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_putGetter (cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlGetter constin_aGetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_putGetter f = NULL ;
    if (classIndex < gExtensionModifierTable_library_putGetter.count ()) {
      f = gExtensionModifierTable_library_putGetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_putGetter.count ()) {
           f = gExtensionModifierTable_library_putGetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_putGetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_aGetter, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_library_putGetter (cPtr_library * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               const GALGAS_gtlGetter constinArgument_aGetter,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  object->mProperty_getterMap.setter_put (constinArgument_name, constinArgument_aGetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 367)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_library_putGetter (void) {
  enterExtensionSetter_putGetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionSetter_library_putGetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_library_putGetter (void) {
  gExtensionModifierTable_library_putGetter.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_library_putGetter (defineExtensionSetter_library_putGetter,
                                              freeExtensionModifier_library_putGetter) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library setterExists'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_library::getter_setterExists (const GALGAS_string constinArgument_type,
                                               const GALGAS_lstring constinArgument_name,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_exists ; // Returned variable
  result_exists = this->mProperty_setterMap.getter_hasKey (constinArgument_type.add_operation (constinArgument_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 375)) COMMA_SOURCE_FILE ("gtl_types.galgas", 375)) ;
//---
  return result_exists ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_setterExists (const cPtr_library * inObject,
                                              const GALGAS_string in_type,
                                              const GALGAS_lstring in_name,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_setterExists (in_type, in_name, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library getSetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetter cPtr_library::getter_getSetter (const GALGAS_string constinArgument_type,
                                                 const GALGAS_lstring constinArgument_name,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlSetter result_aSetter ; // Returned variable
  this->mProperty_setterMap.method_get (GALGAS_lstring::constructor_new (constinArgument_type.add_operation (constinArgument_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 383)), constinArgument_name.readProperty_location ()  COMMA_SOURCE_FILE ("gtl_types.galgas", 383)), result_aSetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 383)) ;
//---
  return result_aSetter ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetter callExtensionGetter_getSetter (const cPtr_library * inObject,
                                                const GALGAS_string in_type,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetter result ;
  if (nullptr != inObject) {
    result = inObject->getter_getSetter (in_type, in_name, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library putSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_library_putSetter> gExtensionModifierTable_library_putSetter ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_putSetter (const int32_t inClassIndex,
                                     extensionSetterSignature_library_putSetter inModifier) {
  gExtensionModifierTable_library_putSetter.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_putSetter (cPtr_library * inObject,
                                    const GALGAS_lstring constin_name,
                                    const GALGAS_gtlSetter constin_aSetter,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_putSetter f = NULL ;
    if (classIndex < gExtensionModifierTable_library_putSetter.count ()) {
      f = gExtensionModifierTable_library_putSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_putSetter.count ()) {
           f = gExtensionModifierTable_library_putSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_putSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_aSetter, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_library_putSetter (cPtr_library * inObject,
                                               const GALGAS_lstring constinArgument_name,
                                               const GALGAS_gtlSetter constinArgument_aSetter,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  object->mProperty_setterMap.setter_put (constinArgument_name, constinArgument_aSetter, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 390)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_library_putSetter (void) {
  enterExtensionSetter_putSetter (kTypeDescriptor_GALGAS_library.mSlotID,
                                  extensionSetter_library_putSetter) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_library_putSetter (void) {
  gExtensionModifierTable_library_putSetter.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_library_putSetter (defineExtensionSetter_library_putSetter,
                                              freeExtensionModifier_library_putSetter) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@library hasImport'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_library::getter_hasImport (const GALGAS_string constinArgument_importPath,
                                            C_Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = this->mProperty_doneImports.getter_hasKey (constinArgument_importPath COMMA_SOURCE_FILE ("gtl_types.galgas", 397)) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasImport (const cPtr_library * inObject,
                                           const GALGAS_string in_importPath,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_hasImport (in_importPath, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library doImport'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_library_doImport> gExtensionModifierTable_library_doImport ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_doImport (const int32_t inClassIndex,
                                    extensionSetterSignature_library_doImport inModifier) {
  gExtensionModifierTable_library_doImport.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_doImport (cPtr_library * inObject,
                                   const GALGAS_string constin_importPath,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_doImport f = NULL ;
    if (classIndex < gExtensionModifierTable_library_doImport.count ()) {
      f = gExtensionModifierTable_library_doImport (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_doImport.count ()) {
           f = gExtensionModifierTable_library_doImport (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_doImport.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_importPath, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_library_doImport (cPtr_library * inObject,
                                              const GALGAS_string constinArgument_importPath,
                                              C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  object->mProperty_doneImports.addAssign_operation (constinArgument_importPath  COMMA_SOURCE_FILE ("gtl_types.galgas", 403)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_library_doImport (void) {
  enterExtensionSetter_doImport (kTypeDescriptor_GALGAS_library.mSlotID,
                                 extensionSetter_library_doImport) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_library_doImport (void) {
  gExtensionModifierTable_library_doImport.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_library_doImport (defineExtensionSetter_library_doImport,
                                             freeExtensionModifier_library_doImport) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@library getTemplate'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_library_getTemplate> gExtensionModifierTable_library_getTemplate ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_getTemplate (const int32_t inClassIndex,
                                       extensionSetterSignature_library_getTemplate inModifier) {
  gExtensionModifierTable_library_getTemplate.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_getTemplate (cPtr_library * inObject,
                                      const GALGAS_gtlContext constin_context,
                                      GALGAS_lstring in_path,
                                      GALGAS_bool in_ifExists,
                                      GALGAS_library & io_lib,
                                      GALGAS_bool & out_found,
                                      GALGAS_gtlTemplate & out_result,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_found.drop () ;
  out_result.drop () ;
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_library) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_library_getTemplate f = NULL ;
    if (classIndex < gExtensionModifierTable_library_getTemplate.count ()) {
      f = gExtensionModifierTable_library_getTemplate (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_library_getTemplate.count ()) {
           f = gExtensionModifierTable_library_getTemplate (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_library_getTemplate.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_context, in_path, in_ifExists, io_lib, out_found, out_result, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_library_getTemplate (cPtr_library * inObject,
                                                 const GALGAS_gtlContext constinArgument_context,
                                                 GALGAS_lstring inArgument_path,
                                                 GALGAS_bool inArgument_ifExists,
                                                 GALGAS_library & ioArgument_lib,
                                                 GALGAS_bool & outArgument_found,
                                                 GALGAS_gtlTemplate & outArgument_result,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_library * object = inObject ;
  macroValidSharedObject (object, cPtr_library) ;
  {
  extensionSetter_getTemplate (object->mProperty_templateMap, constinArgument_context, inArgument_path, inArgument_ifExists, ioArgument_lib, outArgument_found, outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 415)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_library_getTemplate (void) {
  enterExtensionSetter_getTemplate (kTypeDescriptor_GALGAS_library.mSlotID,
                                    extensionSetter_library_getTemplate) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_library_getTemplate (void) {
  gExtensionModifierTable_library_getTemplate.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_library_getTemplate (defineExtensionSetter_library_getTemplate,
                                                freeExtensionModifier_library_getTemplate) ;

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlVarItemField::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVarItemField * p = (const cPtr_gtlVarItemField *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVarItemField) ;
  if (kOperandEqual == result) {
    result = mProperty_field.objectCompare (p->mProperty_field) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlVarItemField::objectCompare (const GALGAS_gtlVarItemField & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemField::GALGAS_gtlVarItemField (void) :
GALGAS_gtlVarItem () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemField GALGAS_gtlVarItemField::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlVarItemField::constructor_new (GALGAS_lstring::constructor_default (HERE)
                                                  COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemField::GALGAS_gtlVarItemField (const cPtr_gtlVarItemField * inSourcePtr) :
GALGAS_gtlVarItem (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarItemField) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemField GALGAS_gtlVarItemField::constructor_new (const GALGAS_lstring & inAttribute_field
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemField result ;
  if (inAttribute_field.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlVarItemField (inAttribute_field COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlVarItemField::readProperty_field (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlVarItemField * p = (const cPtr_gtlVarItemField *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemField) ;
    return p->mProperty_field ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlVarItemField::getter_field (UNUSED_LOCATION_ARGS) const {
  return mProperty_field ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarItemField::setter_setField (GALGAS_lstring inValue
                                              COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlVarItemField * p = (cPtr_gtlVarItemField *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemField) ;
    p->mProperty_field = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemField::setter_setField (GALGAS_lstring inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_field = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlVarItemField class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlVarItemField::cPtr_gtlVarItemField (const GALGAS_lstring & in_field
                                            COMMA_LOCATION_ARGS) :
cPtr_gtlVarItem (THERE),
mProperty_field (in_field) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlVarItemField::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemField ;
}

void cPtr_gtlVarItemField::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@gtlVarItemField:" ;
  mProperty_field.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlVarItemField::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlVarItemField (mProperty_field COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlVarItemField generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarItemField ("gtlVarItemField",
                                        & kTypeDescriptor_GALGAS_gtlVarItem) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarItemField::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemField ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarItemField::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarItemField (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemField GALGAS_gtlVarItemField::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemField result ;
  const GALGAS_gtlVarItemField * p = (const GALGAS_gtlVarItemField *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarItemField *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarItemField", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlVarItemField lstringPath'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlVarItemField::getter_lstringPath (C_Compiler */* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = this->mProperty_field ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring callExtensionGetter_lstringPath (const cPtr_gtlVarItemField * inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
  if (nullptr != inObject) {
    result = inObject->getter_lstringPath (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlVarItemCollection::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVarItemCollection * p = (const cPtr_gtlVarItemCollection *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVarItemCollection) ;
  if (kOperandEqual == result) {
    result = mProperty_field.objectCompare (p->mProperty_field) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_key.objectCompare (p->mProperty_key) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlVarItemCollection::objectCompare (const GALGAS_gtlVarItemCollection & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemCollection::GALGAS_gtlVarItemCollection (void) :
GALGAS_gtlVarItemField () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemCollection::GALGAS_gtlVarItemCollection (const cPtr_gtlVarItemCollection * inSourcePtr) :
GALGAS_gtlVarItemField (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarItemCollection) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemCollection GALGAS_gtlVarItemCollection::constructor_new (const GALGAS_lstring & inAttribute_field,
                                                                          const GALGAS_gtlExpression & inAttribute_key
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemCollection result ;
  if (inAttribute_field.isValid () && inAttribute_key.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlVarItemCollection (inAttribute_field, inAttribute_key COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlVarItemCollection::readProperty_key (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlVarItemCollection * p = (const cPtr_gtlVarItemCollection *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemCollection) ;
    return p->mProperty_key ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlVarItemCollection::getter_key (UNUSED_LOCATION_ARGS) const {
  return mProperty_key ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarItemCollection::setter_setKey (GALGAS_gtlExpression inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlVarItemCollection * p = (cPtr_gtlVarItemCollection *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemCollection) ;
    p->mProperty_key = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemCollection::setter_setKey (GALGAS_gtlExpression inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_key = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlVarItemCollection class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlVarItemCollection::cPtr_gtlVarItemCollection (const GALGAS_lstring & in_field,
                                                      const GALGAS_gtlExpression & in_key
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlVarItemField (in_field COMMA_THERE),
mProperty_key (in_key) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlVarItemCollection::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemCollection ;
}

void cPtr_gtlVarItemCollection::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@gtlVarItemCollection:" ;
  mProperty_field.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_key.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlVarItemCollection::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlVarItemCollection (mProperty_field, mProperty_key COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlVarItemCollection generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarItemCollection ("gtlVarItemCollection",
                                             & kTypeDescriptor_GALGAS_gtlVarItemField) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarItemCollection::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemCollection ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarItemCollection::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarItemCollection (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemCollection GALGAS_gtlVarItemCollection::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemCollection result ;
  const GALGAS_gtlVarItemCollection * p = (const GALGAS_gtlVarItemCollection *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarItemCollection *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarItemCollection", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlVarItemSubCollection::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVarItemSubCollection * p = (const cPtr_gtlVarItemSubCollection *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVarItemSubCollection) ;
  if (kOperandEqual == result) {
    result = mProperty_subCollectionlocation.objectCompare (p->mProperty_subCollectionlocation) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_key.objectCompare (p->mProperty_key) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlVarItemSubCollection::objectCompare (const GALGAS_gtlVarItemSubCollection & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemSubCollection::GALGAS_gtlVarItemSubCollection (void) :
GALGAS_gtlVarItem () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemSubCollection::GALGAS_gtlVarItemSubCollection (const cPtr_gtlVarItemSubCollection * inSourcePtr) :
GALGAS_gtlVarItem (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarItemSubCollection) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemSubCollection GALGAS_gtlVarItemSubCollection::constructor_new (const GALGAS_location & inAttribute_subCollectionlocation,
                                                                                const GALGAS_gtlExpression & inAttribute_key
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemSubCollection result ;
  if (inAttribute_subCollectionlocation.isValid () && inAttribute_key.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlVarItemSubCollection (inAttribute_subCollectionlocation, inAttribute_key COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location GALGAS_gtlVarItemSubCollection::readProperty_subCollectionlocation (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_location () ;
  }else{
    const cPtr_gtlVarItemSubCollection * p = (const cPtr_gtlVarItemSubCollection *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemSubCollection) ;
    return p->mProperty_subCollectionlocation ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlVarItemSubCollection::getter_subCollectionlocation (UNUSED_LOCATION_ARGS) const {
  return mProperty_subCollectionlocation ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlVarItemSubCollection::readProperty_key (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlVarItemSubCollection * p = (const cPtr_gtlVarItemSubCollection *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemSubCollection) ;
    return p->mProperty_key ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlVarItemSubCollection::getter_key (UNUSED_LOCATION_ARGS) const {
  return mProperty_key ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarItemSubCollection::setter_setSubCollectionlocation (GALGAS_location inValue
                                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlVarItemSubCollection * p = (cPtr_gtlVarItemSubCollection *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemSubCollection) ;
    p->mProperty_subCollectionlocation = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemSubCollection::setter_setSubCollectionlocation (GALGAS_location inValue
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_subCollectionlocation = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarItemSubCollection::setter_setKey (GALGAS_gtlExpression inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlVarItemSubCollection * p = (cPtr_gtlVarItemSubCollection *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarItemSubCollection) ;
    p->mProperty_key = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemSubCollection::setter_setKey (GALGAS_gtlExpression inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_key = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlVarItemSubCollection class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlVarItemSubCollection::cPtr_gtlVarItemSubCollection (const GALGAS_location & in_subCollectionlocation,
                                                            const GALGAS_gtlExpression & in_key
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlVarItem (THERE),
mProperty_subCollectionlocation (in_subCollectionlocation),
mProperty_key (in_key) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlVarItemSubCollection::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemSubCollection ;
}

void cPtr_gtlVarItemSubCollection::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlVarItemSubCollection:" ;
  mProperty_subCollectionlocation.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_key.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlVarItemSubCollection::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlVarItemSubCollection (mProperty_subCollectionlocation, mProperty_key COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlVarItemSubCollection generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarItemSubCollection ("gtlVarItemSubCollection",
                                                & kTypeDescriptor_GALGAS_gtlVarItem) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarItemSubCollection::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarItemSubCollection ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarItemSubCollection::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarItemSubCollection (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarItemSubCollection GALGAS_gtlVarItemSubCollection::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarItemSubCollection result ;
  const GALGAS_gtlVarItemSubCollection * p = (const GALGAS_gtlVarItemSubCollection *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarItemSubCollection *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarItemSubCollection", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlExpression location'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlExpression::getter_location (C_Compiler */* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_location result_result ; // Returned variable
  result_result = this->mProperty_where ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_location callExtensionGetter_location (const cPtr_gtlExpression * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
  if (nullptr != inObject) {
    result = inObject->getter_location (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_gtlUnaryExpression::objectCompare (const GALGAS_gtlUnaryExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlUnaryExpression::GALGAS_gtlUnaryExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlUnaryExpression::GALGAS_gtlUnaryExpression (const cPtr_gtlUnaryExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlUnaryExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlUnaryExpression::readProperty_son (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlUnaryExpression * p = (const cPtr_gtlUnaryExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlUnaryExpression) ;
    return p->mProperty_son ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlUnaryExpression::getter_son (UNUSED_LOCATION_ARGS) const {
  return mProperty_son ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlUnaryExpression::setter_setSon (GALGAS_gtlExpression inValue
                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlUnaryExpression * p = (cPtr_gtlUnaryExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlUnaryExpression) ;
    p->mProperty_son = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlUnaryExpression::setter_setSon (GALGAS_gtlExpression inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_son = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlUnaryExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlUnaryExpression::cPtr_gtlUnaryExpression (const GALGAS_location & in_where,
                                                  const GALGAS_gtlExpression & in_son
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_son (in_son) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlUnaryExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlUnaryExpression ("gtlUnaryExpression",
                                           & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlUnaryExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlUnaryExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlUnaryExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlUnaryExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlUnaryExpression GALGAS_gtlUnaryExpression::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlUnaryExpression result ;
  const GALGAS_gtlUnaryExpression * p = (const GALGAS_gtlUnaryExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlUnaryExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlUnaryExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------



typeComparisonResult GALGAS_gtlBinaryExpression::objectCompare (const GALGAS_gtlBinaryExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBinaryExpression::GALGAS_gtlBinaryExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBinaryExpression::GALGAS_gtlBinaryExpression (const cPtr_gtlBinaryExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlBinaryExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlBinaryExpression::readProperty_lSon (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlBinaryExpression * p = (const cPtr_gtlBinaryExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBinaryExpression) ;
    return p->mProperty_lSon ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlBinaryExpression::getter_lSon (UNUSED_LOCATION_ARGS) const {
  return mProperty_lSon ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlBinaryExpression::readProperty_rSon (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlBinaryExpression * p = (const cPtr_gtlBinaryExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBinaryExpression) ;
    return p->mProperty_rSon ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlBinaryExpression::getter_rSon (UNUSED_LOCATION_ARGS) const {
  return mProperty_rSon ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBinaryExpression::setter_setLSon (GALGAS_gtlExpression inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlBinaryExpression * p = (cPtr_gtlBinaryExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBinaryExpression) ;
    p->mProperty_lSon = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBinaryExpression::setter_setLSon (GALGAS_gtlExpression inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_lSon = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlBinaryExpression::setter_setRSon (GALGAS_gtlExpression inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlBinaryExpression * p = (cPtr_gtlBinaryExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlBinaryExpression) ;
    p->mProperty_rSon = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlBinaryExpression::setter_setRSon (GALGAS_gtlExpression inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_rSon = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlBinaryExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlBinaryExpression::cPtr_gtlBinaryExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlExpression & in_lSon,
                                                    const GALGAS_gtlExpression & in_rSon
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_lSon (in_lSon),
mProperty_rSon (in_rSon) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlBinaryExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlBinaryExpression ("gtlBinaryExpression",
                                            & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlBinaryExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlBinaryExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlBinaryExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlBinaryExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlBinaryExpression GALGAS_gtlBinaryExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlBinaryExpression result ;
  const GALGAS_gtlBinaryExpression * p = (const GALGAS_gtlBinaryExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlBinaryExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlBinaryExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlExpression eval'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_eval (const cPtr_gtlExpression * inObject,
                                         const GALGAS_gtlContext in_context,
                                         const GALGAS_gtlData in_vars,
                                         const GALGAS_library in_lib,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_eval (in_context, in_vars, in_lib, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlTerminal::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTerminal * p = (const cPtr_gtlTerminal *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTerminal) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlTerminal::objectCompare (const GALGAS_gtlTerminal & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTerminal::GALGAS_gtlTerminal (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTerminal::GALGAS_gtlTerminal (const cPtr_gtlTerminal * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTerminal) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTerminal GALGAS_gtlTerminal::constructor_new (const GALGAS_location & inAttribute_where,
                                                        const GALGAS_gtlData & inAttribute_value
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTerminal result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTerminal (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData GALGAS_gtlTerminal::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlData () ;
  }else{
    const cPtr_gtlTerminal * p = (const cPtr_gtlTerminal *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTerminal) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlTerminal::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTerminal::setter_setValue (GALGAS_gtlData inValue
                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTerminal * p = (cPtr_gtlTerminal *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTerminal) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTerminal::setter_setValue (GALGAS_gtlData inValue
                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlTerminal class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlTerminal::cPtr_gtlTerminal (const GALGAS_location & in_where,
                                    const GALGAS_gtlData & in_value
                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlTerminal::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTerminal ;
}

void cPtr_gtlTerminal::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@gtlTerminal:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlTerminal::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlTerminal (mProperty_where, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlTerminal generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTerminal ("gtlTerminal",
                                    & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTerminal::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTerminal ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTerminal::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTerminal (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTerminal GALGAS_gtlTerminal::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlTerminal result ;
  const GALGAS_gtlTerminal * p = (const GALGAS_gtlTerminal *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTerminal *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTerminal", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlVarRef::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlVarRef * p = (const cPtr_gtlVarRef *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlVarRef) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_variableName.objectCompare (p->mProperty_variableName) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlVarRef::objectCompare (const GALGAS_gtlVarRef & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarRef::GALGAS_gtlVarRef (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarRef GALGAS_gtlVarRef::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlVarRef::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                            GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                            COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarRef::GALGAS_gtlVarRef (const cPtr_gtlVarRef * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlVarRef) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarRef GALGAS_gtlVarRef::constructor_new (const GALGAS_location & inAttribute_where,
                                                    const GALGAS_gtlVarPath & inAttribute_variableName
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarRef result ;
  if (inAttribute_where.isValid () && inAttribute_variableName.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlVarRef (inAttribute_where, inAttribute_variableName COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlVarRef::readProperty_variableName (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlVarRef * p = (const cPtr_gtlVarRef *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarRef) ;
    return p->mProperty_variableName ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlVarRef::getter_variableName (UNUSED_LOCATION_ARGS) const {
  return mProperty_variableName ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarRef::setter_setVariableName (GALGAS_gtlVarPath inValue
                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlVarRef * p = (cPtr_gtlVarRef *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlVarRef) ;
    p->mProperty_variableName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlVarRef::setter_setVariableName (GALGAS_gtlVarPath inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_variableName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlVarRef class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlVarRef::cPtr_gtlVarRef (const GALGAS_location & in_where,
                                const GALGAS_gtlVarPath & in_variableName
                                COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_variableName (in_variableName) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlVarRef::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarRef ;
}

void cPtr_gtlVarRef::description (C_String & ioString,
                                  const int32_t inIndentation) const {
  ioString << "[@gtlVarRef:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_variableName.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlVarRef::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlVarRef (mProperty_where, mProperty_variableName COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlVarRef generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarRef ("gtlVarRef",
                                  & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarRef::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarRef ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarRef::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarRef (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarRef GALGAS_gtlVarRef::extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarRef result ;
  const GALGAS_gtlVarRef * p = (const GALGAS_gtlVarRef *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarRef *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarRef", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlAllVarsRef::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlAllVarsRef * p = (const cPtr_gtlAllVarsRef *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlAllVarsRef) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlAllVarsRef::objectCompare (const GALGAS_gtlAllVarsRef & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAllVarsRef::GALGAS_gtlAllVarsRef (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAllVarsRef GALGAS_gtlAllVarsRef::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlAllVarsRef::constructor_new (GALGAS_location::constructor_nowhere (HERE)
                                                COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAllVarsRef::GALGAS_gtlAllVarsRef (const cPtr_gtlAllVarsRef * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlAllVarsRef) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAllVarsRef GALGAS_gtlAllVarsRef::constructor_new (const GALGAS_location & inAttribute_where
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlAllVarsRef result ;
  if (inAttribute_where.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlAllVarsRef (inAttribute_where COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlAllVarsRef class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlAllVarsRef::cPtr_gtlAllVarsRef (const GALGAS_location & in_where
                                        COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlAllVarsRef::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAllVarsRef ;
}

void cPtr_gtlAllVarsRef::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@gtlAllVarsRef:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlAllVarsRef::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlAllVarsRef (mProperty_where COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlAllVarsRef generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlAllVarsRef ("gtlAllVarsRef",
                                      & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlAllVarsRef::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAllVarsRef ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlAllVarsRef::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlAllVarsRef (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAllVarsRef GALGAS_gtlAllVarsRef::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlAllVarsRef result ;
  const GALGAS_gtlAllVarsRef * p = (const GALGAS_gtlAllVarsRef *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlAllVarsRef *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlAllVarsRef", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlParenthesizedExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlParenthesizedExpression * p = (const cPtr_gtlParenthesizedExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlParenthesizedExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_son.objectCompare (p->mProperty_son) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlParenthesizedExpression::objectCompare (const GALGAS_gtlParenthesizedExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlParenthesizedExpression::GALGAS_gtlParenthesizedExpression (void) :
GALGAS_gtlUnaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlParenthesizedExpression::GALGAS_gtlParenthesizedExpression (const cPtr_gtlParenthesizedExpression * inSourcePtr) :
GALGAS_gtlUnaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlParenthesizedExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlParenthesizedExpression GALGAS_gtlParenthesizedExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_gtlExpression & inAttribute_son
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlParenthesizedExpression result ;
  if (inAttribute_where.isValid () && inAttribute_son.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlParenthesizedExpression (inAttribute_where, inAttribute_son COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlParenthesizedExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlParenthesizedExpression::cPtr_gtlParenthesizedExpression (const GALGAS_location & in_where,
                                                                  const GALGAS_gtlExpression & in_son
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlUnaryExpression (in_where, in_son COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlParenthesizedExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlParenthesizedExpression ;
}

void cPtr_gtlParenthesizedExpression::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlParenthesizedExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_son.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlParenthesizedExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlParenthesizedExpression (mProperty_where, mProperty_son COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlParenthesizedExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlParenthesizedExpression ("gtlParenthesizedExpression",
                                                   & kTypeDescriptor_GALGAS_gtlUnaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlParenthesizedExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlParenthesizedExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlParenthesizedExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlParenthesizedExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlParenthesizedExpression GALGAS_gtlParenthesizedExpression::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlParenthesizedExpression result ;
  const GALGAS_gtlParenthesizedExpression * p = (const GALGAS_gtlParenthesizedExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlParenthesizedExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlParenthesizedExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlMinusExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlMinusExpression * p = (const cPtr_gtlMinusExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlMinusExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_son.objectCompare (p->mProperty_son) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlMinusExpression::objectCompare (const GALGAS_gtlMinusExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMinusExpression::GALGAS_gtlMinusExpression (void) :
GALGAS_gtlUnaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMinusExpression::GALGAS_gtlMinusExpression (const cPtr_gtlMinusExpression * inSourcePtr) :
GALGAS_gtlUnaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlMinusExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMinusExpression GALGAS_gtlMinusExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_gtlExpression & inAttribute_son
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlMinusExpression result ;
  if (inAttribute_where.isValid () && inAttribute_son.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlMinusExpression (inAttribute_where, inAttribute_son COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlMinusExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlMinusExpression::cPtr_gtlMinusExpression (const GALGAS_location & in_where,
                                                  const GALGAS_gtlExpression & in_son
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlUnaryExpression (in_where, in_son COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlMinusExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMinusExpression ;
}

void cPtr_gtlMinusExpression::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlMinusExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_son.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlMinusExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlMinusExpression (mProperty_where, mProperty_son COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlMinusExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlMinusExpression ("gtlMinusExpression",
                                           & kTypeDescriptor_GALGAS_gtlUnaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlMinusExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMinusExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlMinusExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlMinusExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMinusExpression GALGAS_gtlMinusExpression::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlMinusExpression result ;
  const GALGAS_gtlMinusExpression * p = (const GALGAS_gtlMinusExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlMinusExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlMinusExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlPlusExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlPlusExpression * p = (const cPtr_gtlPlusExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlPlusExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_son.objectCompare (p->mProperty_son) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlPlusExpression::objectCompare (const GALGAS_gtlPlusExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlPlusExpression::GALGAS_gtlPlusExpression (void) :
GALGAS_gtlUnaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlPlusExpression::GALGAS_gtlPlusExpression (const cPtr_gtlPlusExpression * inSourcePtr) :
GALGAS_gtlUnaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlPlusExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlPlusExpression GALGAS_gtlPlusExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                    const GALGAS_gtlExpression & inAttribute_son
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlPlusExpression result ;
  if (inAttribute_where.isValid () && inAttribute_son.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlPlusExpression (inAttribute_where, inAttribute_son COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlPlusExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlPlusExpression::cPtr_gtlPlusExpression (const GALGAS_location & in_where,
                                                const GALGAS_gtlExpression & in_son
                                                COMMA_LOCATION_ARGS) :
cPtr_gtlUnaryExpression (in_where, in_son COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlPlusExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlPlusExpression ;
}

void cPtr_gtlPlusExpression::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@gtlPlusExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_son.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlPlusExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlPlusExpression (mProperty_where, mProperty_son COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlPlusExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlPlusExpression ("gtlPlusExpression",
                                          & kTypeDescriptor_GALGAS_gtlUnaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlPlusExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlPlusExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlPlusExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlPlusExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlPlusExpression GALGAS_gtlPlusExpression::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlPlusExpression result ;
  const GALGAS_gtlPlusExpression * p = (const GALGAS_gtlPlusExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlPlusExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlPlusExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlNotExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlNotExpression * p = (const cPtr_gtlNotExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlNotExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_son.objectCompare (p->mProperty_son) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlNotExpression::objectCompare (const GALGAS_gtlNotExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlNotExpression::GALGAS_gtlNotExpression (void) :
GALGAS_gtlUnaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlNotExpression::GALGAS_gtlNotExpression (const cPtr_gtlNotExpression * inSourcePtr) :
GALGAS_gtlUnaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlNotExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlNotExpression GALGAS_gtlNotExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_gtlExpression & inAttribute_son
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlNotExpression result ;
  if (inAttribute_where.isValid () && inAttribute_son.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlNotExpression (inAttribute_where, inAttribute_son COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlNotExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlNotExpression::cPtr_gtlNotExpression (const GALGAS_location & in_where,
                                              const GALGAS_gtlExpression & in_son
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlUnaryExpression (in_where, in_son COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlNotExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlNotExpression ;
}

void cPtr_gtlNotExpression::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlNotExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_son.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlNotExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlNotExpression (mProperty_where, mProperty_son COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlNotExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlNotExpression ("gtlNotExpression",
                                         & kTypeDescriptor_GALGAS_gtlUnaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlNotExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlNotExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlNotExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlNotExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlNotExpression GALGAS_gtlNotExpression::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlNotExpression result ;
  const GALGAS_gtlNotExpression * p = (const GALGAS_gtlNotExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlNotExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlNotExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlAddExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlAddExpression * p = (const cPtr_gtlAddExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlAddExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlAddExpression::objectCompare (const GALGAS_gtlAddExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAddExpression::GALGAS_gtlAddExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAddExpression::GALGAS_gtlAddExpression (const cPtr_gtlAddExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlAddExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAddExpression GALGAS_gtlAddExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_gtlExpression & inAttribute_lSon,
                                                                  const GALGAS_gtlExpression & inAttribute_rSon
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlAddExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlAddExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlAddExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlAddExpression::cPtr_gtlAddExpression (const GALGAS_location & in_where,
                                              const GALGAS_gtlExpression & in_lSon,
                                              const GALGAS_gtlExpression & in_rSon
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlAddExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAddExpression ;
}

void cPtr_gtlAddExpression::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlAddExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlAddExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlAddExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlAddExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlAddExpression ("gtlAddExpression",
                                         & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlAddExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAddExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlAddExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlAddExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAddExpression GALGAS_gtlAddExpression::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlAddExpression result ;
  const GALGAS_gtlAddExpression * p = (const GALGAS_gtlAddExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlAddExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlAddExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlSubstractExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlSubstractExpression * p = (const cPtr_gtlSubstractExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlSubstractExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlSubstractExpression::objectCompare (const GALGAS_gtlSubstractExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSubstractExpression::GALGAS_gtlSubstractExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSubstractExpression::GALGAS_gtlSubstractExpression (const cPtr_gtlSubstractExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlSubstractExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSubstractExpression GALGAS_gtlSubstractExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_gtlExpression & inAttribute_lSon,
                                                                              const GALGAS_gtlExpression & inAttribute_rSon
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlSubstractExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlSubstractExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlSubstractExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlSubstractExpression::cPtr_gtlSubstractExpression (const GALGAS_location & in_where,
                                                          const GALGAS_gtlExpression & in_lSon,
                                                          const GALGAS_gtlExpression & in_rSon
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlSubstractExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSubstractExpression ;
}

void cPtr_gtlSubstractExpression::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlSubstractExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlSubstractExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlSubstractExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlSubstractExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSubstractExpression ("gtlSubstractExpression",
                                               & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlSubstractExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSubstractExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlSubstractExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSubstractExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSubstractExpression GALGAS_gtlSubstractExpression::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlSubstractExpression result ;
  const GALGAS_gtlSubstractExpression * p = (const GALGAS_gtlSubstractExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSubstractExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSubstractExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlMultiplyExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlMultiplyExpression * p = (const cPtr_gtlMultiplyExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlMultiplyExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlMultiplyExpression::objectCompare (const GALGAS_gtlMultiplyExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMultiplyExpression::GALGAS_gtlMultiplyExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMultiplyExpression::GALGAS_gtlMultiplyExpression (const cPtr_gtlMultiplyExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlMultiplyExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMultiplyExpression GALGAS_gtlMultiplyExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                            const GALGAS_gtlExpression & inAttribute_lSon,
                                                                            const GALGAS_gtlExpression & inAttribute_rSon
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlMultiplyExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlMultiplyExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlMultiplyExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlMultiplyExpression::cPtr_gtlMultiplyExpression (const GALGAS_location & in_where,
                                                        const GALGAS_gtlExpression & in_lSon,
                                                        const GALGAS_gtlExpression & in_rSon
                                                        COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlMultiplyExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMultiplyExpression ;
}

void cPtr_gtlMultiplyExpression::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@gtlMultiplyExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlMultiplyExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlMultiplyExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlMultiplyExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlMultiplyExpression ("gtlMultiplyExpression",
                                              & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlMultiplyExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMultiplyExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlMultiplyExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlMultiplyExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMultiplyExpression GALGAS_gtlMultiplyExpression::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlMultiplyExpression result ;
  const GALGAS_gtlMultiplyExpression * p = (const GALGAS_gtlMultiplyExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlMultiplyExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlMultiplyExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlDivideExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlDivideExpression * p = (const cPtr_gtlDivideExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlDivideExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlDivideExpression::objectCompare (const GALGAS_gtlDivideExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDivideExpression::GALGAS_gtlDivideExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDivideExpression::GALGAS_gtlDivideExpression (const cPtr_gtlDivideExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlDivideExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDivideExpression GALGAS_gtlDivideExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_gtlExpression & inAttribute_lSon,
                                                                        const GALGAS_gtlExpression & inAttribute_rSon
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlDivideExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlDivideExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlDivideExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlDivideExpression::cPtr_gtlDivideExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlExpression & in_lSon,
                                                    const GALGAS_gtlExpression & in_rSon
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlDivideExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDivideExpression ;
}

void cPtr_gtlDivideExpression::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlDivideExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlDivideExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlDivideExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlDivideExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDivideExpression ("gtlDivideExpression",
                                            & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlDivideExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDivideExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlDivideExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDivideExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDivideExpression GALGAS_gtlDivideExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlDivideExpression result ;
  const GALGAS_gtlDivideExpression * p = (const GALGAS_gtlDivideExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlDivideExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDivideExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlModulusExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlModulusExpression * p = (const cPtr_gtlModulusExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlModulusExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlModulusExpression::objectCompare (const GALGAS_gtlModulusExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlModulusExpression::GALGAS_gtlModulusExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlModulusExpression::GALGAS_gtlModulusExpression (const cPtr_gtlModulusExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlModulusExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlModulusExpression GALGAS_gtlModulusExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                          const GALGAS_gtlExpression & inAttribute_lSon,
                                                                          const GALGAS_gtlExpression & inAttribute_rSon
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlModulusExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlModulusExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlModulusExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlModulusExpression::cPtr_gtlModulusExpression (const GALGAS_location & in_where,
                                                      const GALGAS_gtlExpression & in_lSon,
                                                      const GALGAS_gtlExpression & in_rSon
                                                      COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlModulusExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlModulusExpression ;
}

void cPtr_gtlModulusExpression::description (C_String & ioString,
                                             const int32_t inIndentation) const {
  ioString << "[@gtlModulusExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlModulusExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlModulusExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlModulusExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlModulusExpression ("gtlModulusExpression",
                                             & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlModulusExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlModulusExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlModulusExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlModulusExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlModulusExpression GALGAS_gtlModulusExpression::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlModulusExpression result ;
  const GALGAS_gtlModulusExpression * p = (const GALGAS_gtlModulusExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlModulusExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlModulusExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlAndExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlAndExpression * p = (const cPtr_gtlAndExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlAndExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlAndExpression::objectCompare (const GALGAS_gtlAndExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAndExpression::GALGAS_gtlAndExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAndExpression::GALGAS_gtlAndExpression (const cPtr_gtlAndExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlAndExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAndExpression GALGAS_gtlAndExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_gtlExpression & inAttribute_lSon,
                                                                  const GALGAS_gtlExpression & inAttribute_rSon
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlAndExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlAndExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlAndExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlAndExpression::cPtr_gtlAndExpression (const GALGAS_location & in_where,
                                              const GALGAS_gtlExpression & in_lSon,
                                              const GALGAS_gtlExpression & in_rSon
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlAndExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAndExpression ;
}

void cPtr_gtlAndExpression::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlAndExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlAndExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlAndExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlAndExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlAndExpression ("gtlAndExpression",
                                         & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlAndExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlAndExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlAndExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlAndExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlAndExpression GALGAS_gtlAndExpression::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlAndExpression result ;
  const GALGAS_gtlAndExpression * p = (const GALGAS_gtlAndExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlAndExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlAndExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlOrExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlOrExpression * p = (const cPtr_gtlOrExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlOrExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlOrExpression::objectCompare (const GALGAS_gtlOrExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlOrExpression::GALGAS_gtlOrExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlOrExpression::GALGAS_gtlOrExpression (const cPtr_gtlOrExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlOrExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlOrExpression GALGAS_gtlOrExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                const GALGAS_gtlExpression & inAttribute_lSon,
                                                                const GALGAS_gtlExpression & inAttribute_rSon
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlOrExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlOrExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlOrExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlOrExpression::cPtr_gtlOrExpression (const GALGAS_location & in_where,
                                            const GALGAS_gtlExpression & in_lSon,
                                            const GALGAS_gtlExpression & in_rSon
                                            COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlOrExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlOrExpression ;
}

void cPtr_gtlOrExpression::description (C_String & ioString,
                                        const int32_t inIndentation) const {
  ioString << "[@gtlOrExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlOrExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlOrExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlOrExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlOrExpression ("gtlOrExpression",
                                        & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlOrExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlOrExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlOrExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlOrExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlOrExpression GALGAS_gtlOrExpression::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlOrExpression result ;
  const GALGAS_gtlOrExpression * p = (const GALGAS_gtlOrExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlOrExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlOrExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlXorExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlXorExpression * p = (const cPtr_gtlXorExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlXorExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlXorExpression::objectCompare (const GALGAS_gtlXorExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlXorExpression::GALGAS_gtlXorExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlXorExpression::GALGAS_gtlXorExpression (const cPtr_gtlXorExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlXorExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlXorExpression GALGAS_gtlXorExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                  const GALGAS_gtlExpression & inAttribute_lSon,
                                                                  const GALGAS_gtlExpression & inAttribute_rSon
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlXorExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlXorExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlXorExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlXorExpression::cPtr_gtlXorExpression (const GALGAS_location & in_where,
                                              const GALGAS_gtlExpression & in_lSon,
                                              const GALGAS_gtlExpression & in_rSon
                                              COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlXorExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlXorExpression ;
}

void cPtr_gtlXorExpression::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@gtlXorExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlXorExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlXorExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlXorExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlXorExpression ("gtlXorExpression",
                                         & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlXorExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlXorExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlXorExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlXorExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlXorExpression GALGAS_gtlXorExpression::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlXorExpression result ;
  const GALGAS_gtlXorExpression * p = (const GALGAS_gtlXorExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlXorExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlXorExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlShiftLeftExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlShiftLeftExpression * p = (const cPtr_gtlShiftLeftExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlShiftLeftExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlShiftLeftExpression::objectCompare (const GALGAS_gtlShiftLeftExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlShiftLeftExpression::GALGAS_gtlShiftLeftExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlShiftLeftExpression::GALGAS_gtlShiftLeftExpression (const cPtr_gtlShiftLeftExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlShiftLeftExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlShiftLeftExpression GALGAS_gtlShiftLeftExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_gtlExpression & inAttribute_lSon,
                                                                              const GALGAS_gtlExpression & inAttribute_rSon
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlShiftLeftExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlShiftLeftExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlShiftLeftExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlShiftLeftExpression::cPtr_gtlShiftLeftExpression (const GALGAS_location & in_where,
                                                          const GALGAS_gtlExpression & in_lSon,
                                                          const GALGAS_gtlExpression & in_rSon
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlShiftLeftExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlShiftLeftExpression ;
}

void cPtr_gtlShiftLeftExpression::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlShiftLeftExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlShiftLeftExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlShiftLeftExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlShiftLeftExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlShiftLeftExpression ("gtlShiftLeftExpression",
                                               & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlShiftLeftExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlShiftLeftExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlShiftLeftExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlShiftLeftExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlShiftLeftExpression GALGAS_gtlShiftLeftExpression::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlShiftLeftExpression result ;
  const GALGAS_gtlShiftLeftExpression * p = (const GALGAS_gtlShiftLeftExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlShiftLeftExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlShiftLeftExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlShiftRightExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlShiftRightExpression * p = (const cPtr_gtlShiftRightExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlShiftRightExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlShiftRightExpression::objectCompare (const GALGAS_gtlShiftRightExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlShiftRightExpression::GALGAS_gtlShiftRightExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlShiftRightExpression::GALGAS_gtlShiftRightExpression (const cPtr_gtlShiftRightExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlShiftRightExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlShiftRightExpression GALGAS_gtlShiftRightExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_gtlExpression & inAttribute_lSon,
                                                                                const GALGAS_gtlExpression & inAttribute_rSon
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlShiftRightExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlShiftRightExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlShiftRightExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlShiftRightExpression::cPtr_gtlShiftRightExpression (const GALGAS_location & in_where,
                                                            const GALGAS_gtlExpression & in_lSon,
                                                            const GALGAS_gtlExpression & in_rSon
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlShiftRightExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlShiftRightExpression ;
}

void cPtr_gtlShiftRightExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlShiftRightExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlShiftRightExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlShiftRightExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlShiftRightExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlShiftRightExpression ("gtlShiftRightExpression",
                                                & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlShiftRightExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlShiftRightExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlShiftRightExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlShiftRightExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlShiftRightExpression GALGAS_gtlShiftRightExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlShiftRightExpression result ;
  const GALGAS_gtlShiftRightExpression * p = (const GALGAS_gtlShiftRightExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlShiftRightExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlShiftRightExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlNotEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlNotEqualExpression * p = (const cPtr_gtlNotEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlNotEqualExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlNotEqualExpression::objectCompare (const GALGAS_gtlNotEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlNotEqualExpression::GALGAS_gtlNotEqualExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlNotEqualExpression::GALGAS_gtlNotEqualExpression (const cPtr_gtlNotEqualExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlNotEqualExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlNotEqualExpression GALGAS_gtlNotEqualExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                            const GALGAS_gtlExpression & inAttribute_lSon,
                                                                            const GALGAS_gtlExpression & inAttribute_rSon
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlNotEqualExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlNotEqualExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlNotEqualExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlNotEqualExpression::cPtr_gtlNotEqualExpression (const GALGAS_location & in_where,
                                                        const GALGAS_gtlExpression & in_lSon,
                                                        const GALGAS_gtlExpression & in_rSon
                                                        COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlNotEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlNotEqualExpression ;
}

void cPtr_gtlNotEqualExpression::description (C_String & ioString,
                                              const int32_t inIndentation) const {
  ioString << "[@gtlNotEqualExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlNotEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlNotEqualExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlNotEqualExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlNotEqualExpression ("gtlNotEqualExpression",
                                              & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlNotEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlNotEqualExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlNotEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlNotEqualExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlNotEqualExpression GALGAS_gtlNotEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlNotEqualExpression result ;
  const GALGAS_gtlNotEqualExpression * p = (const GALGAS_gtlNotEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlNotEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlNotEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlEqualExpression * p = (const cPtr_gtlEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlEqualExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlEqualExpression::objectCompare (const GALGAS_gtlEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlEqualExpression::GALGAS_gtlEqualExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlEqualExpression::GALGAS_gtlEqualExpression (const cPtr_gtlEqualExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlEqualExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlEqualExpression GALGAS_gtlEqualExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                      const GALGAS_gtlExpression & inAttribute_lSon,
                                                                      const GALGAS_gtlExpression & inAttribute_rSon
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlEqualExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlEqualExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlEqualExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlEqualExpression::cPtr_gtlEqualExpression (const GALGAS_location & in_where,
                                                  const GALGAS_gtlExpression & in_lSon,
                                                  const GALGAS_gtlExpression & in_rSon
                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEqualExpression ;
}

void cPtr_gtlEqualExpression::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@gtlEqualExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlEqualExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlEqualExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlEqualExpression ("gtlEqualExpression",
                                           & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlEqualExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlEqualExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlEqualExpression GALGAS_gtlEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlEqualExpression result ;
  const GALGAS_gtlEqualExpression * p = (const GALGAS_gtlEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLowerThanExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLowerThanExpression * p = (const cPtr_gtlLowerThanExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLowerThanExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlLowerThanExpression::objectCompare (const GALGAS_gtlLowerThanExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLowerThanExpression::GALGAS_gtlLowerThanExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLowerThanExpression::GALGAS_gtlLowerThanExpression (const cPtr_gtlLowerThanExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLowerThanExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLowerThanExpression GALGAS_gtlLowerThanExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_gtlExpression & inAttribute_lSon,
                                                                              const GALGAS_gtlExpression & inAttribute_rSon
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLowerThanExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLowerThanExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlLowerThanExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlLowerThanExpression::cPtr_gtlLowerThanExpression (const GALGAS_location & in_where,
                                                          const GALGAS_gtlExpression & in_lSon,
                                                          const GALGAS_gtlExpression & in_rSon
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLowerThanExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLowerThanExpression ;
}

void cPtr_gtlLowerThanExpression::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlLowerThanExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLowerThanExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLowerThanExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlLowerThanExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLowerThanExpression ("gtlLowerThanExpression",
                                               & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLowerThanExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLowerThanExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLowerThanExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLowerThanExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLowerThanExpression GALGAS_gtlLowerThanExpression::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlLowerThanExpression result ;
  const GALGAS_gtlLowerThanExpression * p = (const GALGAS_gtlLowerThanExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLowerThanExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLowerThanExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLowerOrEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLowerOrEqualExpression * p = (const cPtr_gtlLowerOrEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLowerOrEqualExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlLowerOrEqualExpression::objectCompare (const GALGAS_gtlLowerOrEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLowerOrEqualExpression::GALGAS_gtlLowerOrEqualExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLowerOrEqualExpression::GALGAS_gtlLowerOrEqualExpression (const cPtr_gtlLowerOrEqualExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLowerOrEqualExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLowerOrEqualExpression GALGAS_gtlLowerOrEqualExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                    const GALGAS_gtlExpression & inAttribute_lSon,
                                                                                    const GALGAS_gtlExpression & inAttribute_rSon
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLowerOrEqualExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLowerOrEqualExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlLowerOrEqualExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlLowerOrEqualExpression::cPtr_gtlLowerOrEqualExpression (const GALGAS_location & in_where,
                                                                const GALGAS_gtlExpression & in_lSon,
                                                                const GALGAS_gtlExpression & in_rSon
                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLowerOrEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression ;
}

void cPtr_gtlLowerOrEqualExpression::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "[@gtlLowerOrEqualExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLowerOrEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLowerOrEqualExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlLowerOrEqualExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression ("gtlLowerOrEqualExpression",
                                                  & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLowerOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLowerOrEqualExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLowerOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLowerOrEqualExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLowerOrEqualExpression GALGAS_gtlLowerOrEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlLowerOrEqualExpression result ;
  const GALGAS_gtlLowerOrEqualExpression * p = (const GALGAS_gtlLowerOrEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLowerOrEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLowerOrEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlGreaterThanExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlGreaterThanExpression * p = (const cPtr_gtlGreaterThanExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlGreaterThanExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlGreaterThanExpression::objectCompare (const GALGAS_gtlGreaterThanExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGreaterThanExpression::GALGAS_gtlGreaterThanExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGreaterThanExpression::GALGAS_gtlGreaterThanExpression (const cPtr_gtlGreaterThanExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlGreaterThanExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGreaterThanExpression GALGAS_gtlGreaterThanExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                  const GALGAS_gtlExpression & inAttribute_lSon,
                                                                                  const GALGAS_gtlExpression & inAttribute_rSon
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlGreaterThanExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlGreaterThanExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlGreaterThanExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlGreaterThanExpression::cPtr_gtlGreaterThanExpression (const GALGAS_location & in_where,
                                                              const GALGAS_gtlExpression & in_lSon,
                                                              const GALGAS_gtlExpression & in_rSon
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlGreaterThanExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGreaterThanExpression ;
}

void cPtr_gtlGreaterThanExpression::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@gtlGreaterThanExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlGreaterThanExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlGreaterThanExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlGreaterThanExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGreaterThanExpression ("gtlGreaterThanExpression",
                                                 & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlGreaterThanExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGreaterThanExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlGreaterThanExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGreaterThanExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGreaterThanExpression GALGAS_gtlGreaterThanExpression::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlGreaterThanExpression result ;
  const GALGAS_gtlGreaterThanExpression * p = (const GALGAS_gtlGreaterThanExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGreaterThanExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGreaterThanExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlGreaterOrEqualExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlGreaterOrEqualExpression * p = (const cPtr_gtlGreaterOrEqualExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlGreaterOrEqualExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lSon.objectCompare (p->mProperty_lSon) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_rSon.objectCompare (p->mProperty_rSon) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlGreaterOrEqualExpression::objectCompare (const GALGAS_gtlGreaterOrEqualExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGreaterOrEqualExpression::GALGAS_gtlGreaterOrEqualExpression (void) :
GALGAS_gtlBinaryExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGreaterOrEqualExpression::GALGAS_gtlGreaterOrEqualExpression (const cPtr_gtlGreaterOrEqualExpression * inSourcePtr) :
GALGAS_gtlBinaryExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlGreaterOrEqualExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGreaterOrEqualExpression GALGAS_gtlGreaterOrEqualExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                        const GALGAS_gtlExpression & inAttribute_lSon,
                                                                                        const GALGAS_gtlExpression & inAttribute_rSon
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlGreaterOrEqualExpression result ;
  if (inAttribute_where.isValid () && inAttribute_lSon.isValid () && inAttribute_rSon.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlGreaterOrEqualExpression (inAttribute_where, inAttribute_lSon, inAttribute_rSon COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlGreaterOrEqualExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlGreaterOrEqualExpression::cPtr_gtlGreaterOrEqualExpression (const GALGAS_location & in_where,
                                                                    const GALGAS_gtlExpression & in_lSon,
                                                                    const GALGAS_gtlExpression & in_rSon
                                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlBinaryExpression (in_where, in_lSon, in_rSon COMMA_THERE) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlGreaterOrEqualExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression ;
}

void cPtr_gtlGreaterOrEqualExpression::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "[@gtlGreaterOrEqualExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lSon.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_rSon.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlGreaterOrEqualExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlGreaterOrEqualExpression (mProperty_where, mProperty_lSon, mProperty_rSon COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlGreaterOrEqualExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression ("gtlGreaterOrEqualExpression",
                                                    & kTypeDescriptor_GALGAS_gtlBinaryExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlGreaterOrEqualExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGreaterOrEqualExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlGreaterOrEqualExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGreaterOrEqualExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGreaterOrEqualExpression GALGAS_gtlGreaterOrEqualExpression::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlGreaterOrEqualExpression result ;
  const GALGAS_gtlGreaterOrEqualExpression * p = (const GALGAS_gtlGreaterOrEqualExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGreaterOrEqualExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGreaterOrEqualExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlGetterCallExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlGetterCallExpression * p = (const cPtr_gtlGetterCallExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_target.objectCompare (p->mProperty_target) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_getterName.objectCompare (p->mProperty_getterName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_arguments.objectCompare (p->mProperty_arguments) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlGetterCallExpression::objectCompare (const GALGAS_gtlGetterCallExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterCallExpression::GALGAS_gtlGetterCallExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterCallExpression::GALGAS_gtlGetterCallExpression (const cPtr_gtlGetterCallExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlGetterCallExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterCallExpression GALGAS_gtlGetterCallExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_gtlExpression & inAttribute_target,
                                                                                const GALGAS_lstring & inAttribute_getterName,
                                                                                const GALGAS_gtlExpressionList & inAttribute_arguments
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterCallExpression result ;
  if (inAttribute_where.isValid () && inAttribute_target.isValid () && inAttribute_getterName.isValid () && inAttribute_arguments.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlGetterCallExpression (inAttribute_where, inAttribute_target, inAttribute_getterName, inAttribute_arguments COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlGetterCallExpression::readProperty_target (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlGetterCallExpression * p = (const cPtr_gtlGetterCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
    return p->mProperty_target ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlGetterCallExpression::getter_target (UNUSED_LOCATION_ARGS) const {
  return mProperty_target ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlGetterCallExpression::readProperty_getterName (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlGetterCallExpression * p = (const cPtr_gtlGetterCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
    return p->mProperty_getterName ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlGetterCallExpression::getter_getterName (UNUSED_LOCATION_ARGS) const {
  return mProperty_getterName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlGetterCallExpression::readProperty_arguments (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpressionList () ;
  }else{
    const cPtr_gtlGetterCallExpression * p = (const cPtr_gtlGetterCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
    return p->mProperty_arguments ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList cPtr_gtlGetterCallExpression::getter_arguments (UNUSED_LOCATION_ARGS) const {
  return mProperty_arguments ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetterCallExpression::setter_setTarget (GALGAS_gtlExpression inValue
                                                       COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlGetterCallExpression * p = (cPtr_gtlGetterCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
    p->mProperty_target = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlGetterCallExpression::setter_setTarget (GALGAS_gtlExpression inValue
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_target = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetterCallExpression::setter_setGetterName (GALGAS_lstring inValue
                                                           COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlGetterCallExpression * p = (cPtr_gtlGetterCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
    p->mProperty_getterName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlGetterCallExpression::setter_setGetterName (GALGAS_lstring inValue
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_getterName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetterCallExpression::setter_setArguments (GALGAS_gtlExpressionList inValue
                                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlGetterCallExpression * p = (cPtr_gtlGetterCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlGetterCallExpression) ;
    p->mProperty_arguments = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlGetterCallExpression::setter_setArguments (GALGAS_gtlExpressionList inValue
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_arguments = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlGetterCallExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlGetterCallExpression::cPtr_gtlGetterCallExpression (const GALGAS_location & in_where,
                                                            const GALGAS_gtlExpression & in_target,
                                                            const GALGAS_lstring & in_getterName,
                                                            const GALGAS_gtlExpressionList & in_arguments
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_target (in_target),
mProperty_getterName (in_getterName),
mProperty_arguments (in_arguments) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlGetterCallExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterCallExpression ;
}

void cPtr_gtlGetterCallExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlGetterCallExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_target.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_getterName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_arguments.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlGetterCallExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlGetterCallExpression (mProperty_where, mProperty_target, mProperty_getterName, mProperty_arguments COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlGetterCallExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetterCallExpression ("gtlGetterCallExpression",
                                                & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlGetterCallExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterCallExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlGetterCallExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetterCallExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterCallExpression GALGAS_gtlGetterCallExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterCallExpression result ;
  const GALGAS_gtlGetterCallExpression * p = (const GALGAS_gtlGetterCallExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGetterCallExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGetterCallExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlFunctionCallExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlFunctionCallExpression * p = (const cPtr_gtlFunctionCallExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlFunctionCallExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_functionName.objectCompare (p->mProperty_functionName) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_functionArguments.objectCompare (p->mProperty_functionArguments) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlFunctionCallExpression::objectCompare (const GALGAS_gtlFunctionCallExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFunctionCallExpression::GALGAS_gtlFunctionCallExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFunctionCallExpression GALGAS_gtlFunctionCallExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlFunctionCallExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                            GALGAS_lstring::constructor_default (HERE),
                                                            GALGAS_gtlExpressionList::constructor_emptyList (HERE)
                                                            COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFunctionCallExpression::GALGAS_gtlFunctionCallExpression (const cPtr_gtlFunctionCallExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlFunctionCallExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFunctionCallExpression GALGAS_gtlFunctionCallExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                    const GALGAS_lstring & inAttribute_functionName,
                                                                                    const GALGAS_gtlExpressionList & inAttribute_functionArguments
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlFunctionCallExpression result ;
  if (inAttribute_where.isValid () && inAttribute_functionName.isValid () && inAttribute_functionArguments.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlFunctionCallExpression (inAttribute_where, inAttribute_functionName, inAttribute_functionArguments COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlFunctionCallExpression::readProperty_functionName (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlFunctionCallExpression * p = (const cPtr_gtlFunctionCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlFunctionCallExpression) ;
    return p->mProperty_functionName ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlFunctionCallExpression::getter_functionName (UNUSED_LOCATION_ARGS) const {
  return mProperty_functionName ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlFunctionCallExpression::readProperty_functionArguments (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpressionList () ;
  }else{
    const cPtr_gtlFunctionCallExpression * p = (const cPtr_gtlFunctionCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlFunctionCallExpression) ;
    return p->mProperty_functionArguments ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList cPtr_gtlFunctionCallExpression::getter_functionArguments (UNUSED_LOCATION_ARGS) const {
  return mProperty_functionArguments ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlFunctionCallExpression::setter_setFunctionName (GALGAS_lstring inValue
                                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlFunctionCallExpression * p = (cPtr_gtlFunctionCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlFunctionCallExpression) ;
    p->mProperty_functionName = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlFunctionCallExpression::setter_setFunctionName (GALGAS_lstring inValue
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_functionName = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlFunctionCallExpression::setter_setFunctionArguments (GALGAS_gtlExpressionList inValue
                                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlFunctionCallExpression * p = (cPtr_gtlFunctionCallExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlFunctionCallExpression) ;
    p->mProperty_functionArguments = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlFunctionCallExpression::setter_setFunctionArguments (GALGAS_gtlExpressionList inValue
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_functionArguments = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlFunctionCallExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlFunctionCallExpression::cPtr_gtlFunctionCallExpression (const GALGAS_location & in_where,
                                                                const GALGAS_lstring & in_functionName,
                                                                const GALGAS_gtlExpressionList & in_functionArguments
                                                                COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_functionName (in_functionName),
mProperty_functionArguments (in_functionArguments) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlFunctionCallExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFunctionCallExpression ;
}

void cPtr_gtlFunctionCallExpression::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "[@gtlFunctionCallExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_functionName.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_functionArguments.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlFunctionCallExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlFunctionCallExpression (mProperty_where, mProperty_functionName, mProperty_functionArguments COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlFunctionCallExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFunctionCallExpression ("gtlFunctionCallExpression",
                                                  & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlFunctionCallExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFunctionCallExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlFunctionCallExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlFunctionCallExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFunctionCallExpression GALGAS_gtlFunctionCallExpression::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlFunctionCallExpression result ;
  const GALGAS_gtlFunctionCallExpression * p = (const GALGAS_gtlFunctionCallExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlFunctionCallExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlFunctionCallExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlExistsExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlExistsExpression * p = (const cPtr_gtlExistsExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlExistsExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_variable.objectCompare (p->mProperty_variable) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlExistsExpression::objectCompare (const GALGAS_gtlExistsExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExistsExpression::GALGAS_gtlExistsExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExistsExpression GALGAS_gtlExistsExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlExistsExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                      GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                      COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExistsExpression::GALGAS_gtlExistsExpression (const cPtr_gtlExistsExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlExistsExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExistsExpression GALGAS_gtlExistsExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_gtlVarPath & inAttribute_variable
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlExistsExpression result ;
  if (inAttribute_where.isValid () && inAttribute_variable.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlExistsExpression (inAttribute_where, inAttribute_variable COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlExistsExpression::readProperty_variable (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlExistsExpression * p = (const cPtr_gtlExistsExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExistsExpression) ;
    return p->mProperty_variable ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlExistsExpression::getter_variable (UNUSED_LOCATION_ARGS) const {
  return mProperty_variable ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExistsExpression::setter_setVariable (GALGAS_gtlVarPath inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlExistsExpression * p = (cPtr_gtlExistsExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExistsExpression) ;
    p->mProperty_variable = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlExistsExpression::setter_setVariable (GALGAS_gtlVarPath inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_variable = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlExistsExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlExistsExpression::cPtr_gtlExistsExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlVarPath & in_variable
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_variable (in_variable) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlExistsExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExistsExpression ;
}

void cPtr_gtlExistsExpression::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlExistsExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_variable.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlExistsExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlExistsExpression (mProperty_where, mProperty_variable COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlExistsExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExistsExpression ("gtlExistsExpression",
                                            & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlExistsExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExistsExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlExistsExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExistsExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExistsExpression GALGAS_gtlExistsExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlExistsExpression result ;
  const GALGAS_gtlExistsExpression * p = (const GALGAS_gtlExistsExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExistsExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExistsExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlExistsDefaultExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlExistsDefaultExpression * p = (const cPtr_gtlExistsDefaultExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlExistsDefaultExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_variable.objectCompare (p->mProperty_variable) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_defaultValue.objectCompare (p->mProperty_defaultValue) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlExistsDefaultExpression::objectCompare (const GALGAS_gtlExistsDefaultExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExistsDefaultExpression::GALGAS_gtlExistsDefaultExpression (void) :
GALGAS_gtlExistsExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExistsDefaultExpression::GALGAS_gtlExistsDefaultExpression (const cPtr_gtlExistsDefaultExpression * inSourcePtr) :
GALGAS_gtlExistsExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlExistsDefaultExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExistsDefaultExpression GALGAS_gtlExistsDefaultExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_gtlVarPath & inAttribute_variable,
                                                                                      const GALGAS_gtlExpression & inAttribute_defaultValue
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlExistsDefaultExpression result ;
  if (inAttribute_where.isValid () && inAttribute_variable.isValid () && inAttribute_defaultValue.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlExistsDefaultExpression (inAttribute_where, inAttribute_variable, inAttribute_defaultValue COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlExistsDefaultExpression::readProperty_defaultValue (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlExistsDefaultExpression * p = (const cPtr_gtlExistsDefaultExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExistsDefaultExpression) ;
    return p->mProperty_defaultValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlExistsDefaultExpression::getter_defaultValue (UNUSED_LOCATION_ARGS) const {
  return mProperty_defaultValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExistsDefaultExpression::setter_setDefaultValue (GALGAS_gtlExpression inValue
                                                                COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlExistsDefaultExpression * p = (cPtr_gtlExistsDefaultExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlExistsDefaultExpression) ;
    p->mProperty_defaultValue = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlExistsDefaultExpression::setter_setDefaultValue (GALGAS_gtlExpression inValue
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_defaultValue = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlExistsDefaultExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlExistsDefaultExpression::cPtr_gtlExistsDefaultExpression (const GALGAS_location & in_where,
                                                                  const GALGAS_gtlVarPath & in_variable,
                                                                  const GALGAS_gtlExpression & in_defaultValue
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlExistsExpression (in_where, in_variable COMMA_THERE),
mProperty_defaultValue (in_defaultValue) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlExistsDefaultExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExistsDefaultExpression ;
}

void cPtr_gtlExistsDefaultExpression::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlExistsDefaultExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_variable.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_defaultValue.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlExistsDefaultExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlExistsDefaultExpression (mProperty_where, mProperty_variable, mProperty_defaultValue COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlExistsDefaultExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExistsDefaultExpression ("gtlExistsDefaultExpression",
                                                   & kTypeDescriptor_GALGAS_gtlExistsExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlExistsDefaultExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExistsDefaultExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlExistsDefaultExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExistsDefaultExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExistsDefaultExpression GALGAS_gtlExistsDefaultExpression::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlExistsDefaultExpression result ;
  const GALGAS_gtlExistsDefaultExpression * p = (const GALGAS_gtlExistsDefaultExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExistsDefaultExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExistsDefaultExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlTypeOfExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlTypeOfExpression * p = (const cPtr_gtlTypeOfExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlTypeOfExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_variable.objectCompare (p->mProperty_variable) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlTypeOfExpression::objectCompare (const GALGAS_gtlTypeOfExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypeOfExpression::GALGAS_gtlTypeOfExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypeOfExpression GALGAS_gtlTypeOfExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlTypeOfExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                      GALGAS_gtlVarPath::constructor_emptyList (HERE)
                                                      COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypeOfExpression::GALGAS_gtlTypeOfExpression (const cPtr_gtlTypeOfExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlTypeOfExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypeOfExpression GALGAS_gtlTypeOfExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_gtlVarPath & inAttribute_variable
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypeOfExpression result ;
  if (inAttribute_where.isValid () && inAttribute_variable.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlTypeOfExpression (inAttribute_where, inAttribute_variable COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath GALGAS_gtlTypeOfExpression::readProperty_variable (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlVarPath () ;
  }else{
    const cPtr_gtlTypeOfExpression * p = (const cPtr_gtlTypeOfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTypeOfExpression) ;
    return p->mProperty_variable ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarPath cPtr_gtlTypeOfExpression::getter_variable (UNUSED_LOCATION_ARGS) const {
  return mProperty_variable ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTypeOfExpression::setter_setVariable (GALGAS_gtlVarPath inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlTypeOfExpression * p = (cPtr_gtlTypeOfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlTypeOfExpression) ;
    p->mProperty_variable = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlTypeOfExpression::setter_setVariable (GALGAS_gtlVarPath inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_variable = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlTypeOfExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlTypeOfExpression::cPtr_gtlTypeOfExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlVarPath & in_variable
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_variable (in_variable) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlTypeOfExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTypeOfExpression ;
}

void cPtr_gtlTypeOfExpression::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlTypeOfExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_variable.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlTypeOfExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlTypeOfExpression (mProperty_where, mProperty_variable COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlTypeOfExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTypeOfExpression ("gtlTypeOfExpression",
                                            & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTypeOfExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTypeOfExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTypeOfExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTypeOfExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTypeOfExpression GALGAS_gtlTypeOfExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlTypeOfExpression result ;
  const GALGAS_gtlTypeOfExpression * p = (const GALGAS_gtlTypeOfExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTypeOfExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTypeOfExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlMapOfStructExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlMapOfStructExpression * p = (const cPtr_gtlMapOfStructExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlMapOfStructExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_expression.objectCompare (p->mProperty_expression) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlMapOfStructExpression::objectCompare (const GALGAS_gtlMapOfStructExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMapOfStructExpression::GALGAS_gtlMapOfStructExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMapOfStructExpression::GALGAS_gtlMapOfStructExpression (const cPtr_gtlMapOfStructExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlMapOfStructExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMapOfStructExpression GALGAS_gtlMapOfStructExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                  const GALGAS_gtlExpression & inAttribute_expression
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlMapOfStructExpression result ;
  if (inAttribute_where.isValid () && inAttribute_expression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlMapOfStructExpression (inAttribute_where, inAttribute_expression COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlMapOfStructExpression::readProperty_expression (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlMapOfStructExpression * p = (const cPtr_gtlMapOfStructExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlMapOfStructExpression) ;
    return p->mProperty_expression ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlMapOfStructExpression::getter_expression (UNUSED_LOCATION_ARGS) const {
  return mProperty_expression ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlMapOfStructExpression::setter_setExpression (GALGAS_gtlExpression inValue
                                                            COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlMapOfStructExpression * p = (cPtr_gtlMapOfStructExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlMapOfStructExpression) ;
    p->mProperty_expression = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlMapOfStructExpression::setter_setExpression (GALGAS_gtlExpression inValue
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_expression = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlMapOfStructExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlMapOfStructExpression::cPtr_gtlMapOfStructExpression (const GALGAS_location & in_where,
                                                              const GALGAS_gtlExpression & in_expression
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_expression (in_expression) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlMapOfStructExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMapOfStructExpression ;
}

void cPtr_gtlMapOfStructExpression::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@gtlMapOfStructExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_expression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlMapOfStructExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlMapOfStructExpression (mProperty_where, mProperty_expression COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlMapOfStructExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlMapOfStructExpression ("gtlMapOfStructExpression",
                                                 & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlMapOfStructExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMapOfStructExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlMapOfStructExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlMapOfStructExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMapOfStructExpression GALGAS_gtlMapOfStructExpression::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlMapOfStructExpression result ;
  const GALGAS_gtlMapOfStructExpression * p = (const GALGAS_gtlMapOfStructExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlMapOfStructExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlMapOfStructExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlMapOfListExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlMapOfListExpression * p = (const cPtr_gtlMapOfListExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlMapOfListExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_expression.objectCompare (p->mProperty_expression) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_key.objectCompare (p->mProperty_key) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlMapOfListExpression::objectCompare (const GALGAS_gtlMapOfListExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMapOfListExpression::GALGAS_gtlMapOfListExpression (void) :
GALGAS_gtlMapOfStructExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMapOfListExpression::GALGAS_gtlMapOfListExpression (const cPtr_gtlMapOfListExpression * inSourcePtr) :
GALGAS_gtlMapOfStructExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlMapOfListExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMapOfListExpression GALGAS_gtlMapOfListExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                              const GALGAS_gtlExpression & inAttribute_expression,
                                                                              const GALGAS_lstring & inAttribute_key
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlMapOfListExpression result ;
  if (inAttribute_where.isValid () && inAttribute_expression.isValid () && inAttribute_key.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlMapOfListExpression (inAttribute_where, inAttribute_expression, inAttribute_key COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlMapOfListExpression::readProperty_key (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlMapOfListExpression * p = (const cPtr_gtlMapOfListExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlMapOfListExpression) ;
    return p->mProperty_key ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlMapOfListExpression::getter_key (UNUSED_LOCATION_ARGS) const {
  return mProperty_key ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlMapOfListExpression::setter_setKey (GALGAS_lstring inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlMapOfListExpression * p = (cPtr_gtlMapOfListExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlMapOfListExpression) ;
    p->mProperty_key = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlMapOfListExpression::setter_setKey (GALGAS_lstring inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_key = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlMapOfListExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlMapOfListExpression::cPtr_gtlMapOfListExpression (const GALGAS_location & in_where,
                                                          const GALGAS_gtlExpression & in_expression,
                                                          const GALGAS_lstring & in_key
                                                          COMMA_LOCATION_ARGS) :
cPtr_gtlMapOfStructExpression (in_where, in_expression COMMA_THERE),
mProperty_key (in_key) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlMapOfListExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMapOfListExpression ;
}

void cPtr_gtlMapOfListExpression::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "[@gtlMapOfListExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_expression.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_key.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlMapOfListExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlMapOfListExpression (mProperty_where, mProperty_expression, mProperty_key COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlMapOfListExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlMapOfListExpression ("gtlMapOfListExpression",
                                               & kTypeDescriptor_GALGAS_gtlMapOfStructExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlMapOfListExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlMapOfListExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlMapOfListExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlMapOfListExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlMapOfListExpression GALGAS_gtlMapOfListExpression::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlMapOfListExpression result ;
  const GALGAS_gtlMapOfListExpression * p = (const GALGAS_gtlMapOfListExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlMapOfListExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlMapOfListExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlListOfExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlListOfExpression * p = (const cPtr_gtlListOfExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlListOfExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_expression.objectCompare (p->mProperty_expression) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlListOfExpression::objectCompare (const GALGAS_gtlListOfExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlListOfExpression::GALGAS_gtlListOfExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlListOfExpression::GALGAS_gtlListOfExpression (const cPtr_gtlListOfExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlListOfExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlListOfExpression GALGAS_gtlListOfExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                        const GALGAS_gtlExpression & inAttribute_expression
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlListOfExpression result ;
  if (inAttribute_where.isValid () && inAttribute_expression.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlListOfExpression (inAttribute_where, inAttribute_expression COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression GALGAS_gtlListOfExpression::readProperty_expression (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpression () ;
  }else{
    const cPtr_gtlListOfExpression * p = (const cPtr_gtlListOfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlListOfExpression) ;
    return p->mProperty_expression ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpression cPtr_gtlListOfExpression::getter_expression (UNUSED_LOCATION_ARGS) const {
  return mProperty_expression ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlListOfExpression::setter_setExpression (GALGAS_gtlExpression inValue
                                                       COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlListOfExpression * p = (cPtr_gtlListOfExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlListOfExpression) ;
    p->mProperty_expression = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlListOfExpression::setter_setExpression (GALGAS_gtlExpression inValue
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_expression = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlListOfExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlListOfExpression::cPtr_gtlListOfExpression (const GALGAS_location & in_where,
                                                    const GALGAS_gtlExpression & in_expression
                                                    COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_expression (in_expression) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlListOfExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlListOfExpression ;
}

void cPtr_gtlListOfExpression::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@gtlListOfExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_expression.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlListOfExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlListOfExpression (mProperty_where, mProperty_expression COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlListOfExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlListOfExpression ("gtlListOfExpression",
                                            & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlListOfExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlListOfExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlListOfExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlListOfExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlListOfExpression GALGAS_gtlListOfExpression::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlListOfExpression result ;
  const GALGAS_gtlListOfExpression * p = (const GALGAS_gtlListOfExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlListOfExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlListOfExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLiteralStructExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLiteralStructExpression * p = (const cPtr_gtlLiteralStructExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLiteralStructExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlLiteralStructExpression::objectCompare (const GALGAS_gtlLiteralStructExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralStructExpression::GALGAS_gtlLiteralStructExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralStructExpression GALGAS_gtlLiteralStructExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLiteralStructExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                             GALGAS_gtlExpressionMap::constructor_emptyMap (HERE)
                                                             COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralStructExpression::GALGAS_gtlLiteralStructExpression (const cPtr_gtlLiteralStructExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLiteralStructExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralStructExpression GALGAS_gtlLiteralStructExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                      const GALGAS_gtlExpressionMap & inAttribute_value
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralStructExpression result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLiteralStructExpression (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap GALGAS_gtlLiteralStructExpression::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpressionMap () ;
  }else{
    const cPtr_gtlLiteralStructExpression * p = (const cPtr_gtlLiteralStructExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralStructExpression) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap cPtr_gtlLiteralStructExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlLiteralStructExpression::setter_setValue (GALGAS_gtlExpressionMap inValue
                                                         COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLiteralStructExpression * p = (cPtr_gtlLiteralStructExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralStructExpression) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLiteralStructExpression::setter_setValue (GALGAS_gtlExpressionMap inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlLiteralStructExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlLiteralStructExpression::cPtr_gtlLiteralStructExpression (const GALGAS_location & in_where,
                                                                  const GALGAS_gtlExpressionMap & in_value
                                                                  COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLiteralStructExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralStructExpression ;
}

void cPtr_gtlLiteralStructExpression::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "[@gtlLiteralStructExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLiteralStructExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLiteralStructExpression (mProperty_where, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlLiteralStructExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLiteralStructExpression ("gtlLiteralStructExpression",
                                                   & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLiteralStructExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralStructExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLiteralStructExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLiteralStructExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralStructExpression GALGAS_gtlLiteralStructExpression::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralStructExpression result ;
  const GALGAS_gtlLiteralStructExpression * p = (const GALGAS_gtlLiteralStructExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLiteralStructExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLiteralStructExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLiteralMapExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLiteralMapExpression * p = (const cPtr_gtlLiteralMapExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLiteralMapExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlLiteralMapExpression::objectCompare (const GALGAS_gtlLiteralMapExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralMapExpression::GALGAS_gtlLiteralMapExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralMapExpression GALGAS_gtlLiteralMapExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLiteralMapExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_gtlExpressionMap::constructor_emptyMap (HERE)
                                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralMapExpression::GALGAS_gtlLiteralMapExpression (const cPtr_gtlLiteralMapExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLiteralMapExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralMapExpression GALGAS_gtlLiteralMapExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_gtlExpressionMap & inAttribute_value
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralMapExpression result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLiteralMapExpression (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap GALGAS_gtlLiteralMapExpression::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpressionMap () ;
  }else{
    const cPtr_gtlLiteralMapExpression * p = (const cPtr_gtlLiteralMapExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralMapExpression) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap cPtr_gtlLiteralMapExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlLiteralMapExpression::setter_setValue (GALGAS_gtlExpressionMap inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLiteralMapExpression * p = (cPtr_gtlLiteralMapExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralMapExpression) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLiteralMapExpression::setter_setValue (GALGAS_gtlExpressionMap inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlLiteralMapExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlLiteralMapExpression::cPtr_gtlLiteralMapExpression (const GALGAS_location & in_where,
                                                            const GALGAS_gtlExpressionMap & in_value
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLiteralMapExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralMapExpression ;
}

void cPtr_gtlLiteralMapExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlLiteralMapExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLiteralMapExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLiteralMapExpression (mProperty_where, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlLiteralMapExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLiteralMapExpression ("gtlLiteralMapExpression",
                                                & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLiteralMapExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralMapExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLiteralMapExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLiteralMapExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralMapExpression GALGAS_gtlLiteralMapExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralMapExpression result ;
  const GALGAS_gtlLiteralMapExpression * p = (const GALGAS_gtlLiteralMapExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLiteralMapExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLiteralMapExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLiteralListExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLiteralListExpression * p = (const cPtr_gtlLiteralListExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLiteralListExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlLiteralListExpression::objectCompare (const GALGAS_gtlLiteralListExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralListExpression::GALGAS_gtlLiteralListExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralListExpression GALGAS_gtlLiteralListExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLiteralListExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                           GALGAS_gtlExpressionList::constructor_emptyList (HERE)
                                                           COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralListExpression::GALGAS_gtlLiteralListExpression (const cPtr_gtlLiteralListExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLiteralListExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralListExpression GALGAS_gtlLiteralListExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                  const GALGAS_gtlExpressionList & inAttribute_value
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralListExpression result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLiteralListExpression (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlLiteralListExpression::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpressionList () ;
  }else{
    const cPtr_gtlLiteralListExpression * p = (const cPtr_gtlLiteralListExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralListExpression) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList cPtr_gtlLiteralListExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlLiteralListExpression::setter_setValue (GALGAS_gtlExpressionList inValue
                                                       COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLiteralListExpression * p = (cPtr_gtlLiteralListExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralListExpression) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLiteralListExpression::setter_setValue (GALGAS_gtlExpressionList inValue
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlLiteralListExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlLiteralListExpression::cPtr_gtlLiteralListExpression (const GALGAS_location & in_where,
                                                              const GALGAS_gtlExpressionList & in_value
                                                              COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLiteralListExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralListExpression ;
}

void cPtr_gtlLiteralListExpression::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "[@gtlLiteralListExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLiteralListExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLiteralListExpression (mProperty_where, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlLiteralListExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLiteralListExpression ("gtlLiteralListExpression",
                                                 & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLiteralListExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralListExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLiteralListExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLiteralListExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralListExpression GALGAS_gtlLiteralListExpression::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralListExpression result ;
  const GALGAS_gtlLiteralListExpression * p = (const GALGAS_gtlLiteralListExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLiteralListExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLiteralListExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlLiteralSetExpression::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlLiteralSetExpression * p = (const cPtr_gtlLiteralSetExpression *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlLiteralSetExpression) ;
  if (kOperandEqual == result) {
    result = mProperty_where.objectCompare (p->mProperty_where) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_value.objectCompare (p->mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlLiteralSetExpression::objectCompare (const GALGAS_gtlLiteralSetExpression & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralSetExpression::GALGAS_gtlLiteralSetExpression (void) :
GALGAS_gtlExpression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralSetExpression GALGAS_gtlLiteralSetExpression::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlLiteralSetExpression::constructor_new (GALGAS_location::constructor_nowhere (HERE),
                                                          GALGAS_gtlExpressionList::constructor_emptyList (HERE)
                                                          COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralSetExpression::GALGAS_gtlLiteralSetExpression (const cPtr_gtlLiteralSetExpression * inSourcePtr) :
GALGAS_gtlExpression (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlLiteralSetExpression) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralSetExpression GALGAS_gtlLiteralSetExpression::constructor_new (const GALGAS_location & inAttribute_where,
                                                                                const GALGAS_gtlExpressionList & inAttribute_value
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralSetExpression result ;
  if (inAttribute_where.isValid () && inAttribute_value.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlLiteralSetExpression (inAttribute_where, inAttribute_value COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList GALGAS_gtlLiteralSetExpression::readProperty_value (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlExpressionList () ;
  }else{
    const cPtr_gtlLiteralSetExpression * p = (const cPtr_gtlLiteralSetExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralSetExpression) ;
    return p->mProperty_value ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList cPtr_gtlLiteralSetExpression::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlLiteralSetExpression::setter_setValue (GALGAS_gtlExpressionList inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlLiteralSetExpression * p = (cPtr_gtlLiteralSetExpression *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlLiteralSetExpression) ;
    p->mProperty_value = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlLiteralSetExpression::setter_setValue (GALGAS_gtlExpressionList inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_value = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlLiteralSetExpression class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlLiteralSetExpression::cPtr_gtlLiteralSetExpression (const GALGAS_location & in_where,
                                                            const GALGAS_gtlExpressionList & in_value
                                                            COMMA_LOCATION_ARGS) :
cPtr_gtlExpression (in_where COMMA_THERE),
mProperty_value (in_value) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlLiteralSetExpression::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralSetExpression ;
}

void cPtr_gtlLiteralSetExpression::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "[@gtlLiteralSetExpression:" ;
  mProperty_where.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_value.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlLiteralSetExpression::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlLiteralSetExpression (mProperty_where, mProperty_value COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @gtlLiteralSetExpression generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlLiteralSetExpression ("gtlLiteralSetExpression",
                                                & kTypeDescriptor_GALGAS_gtlExpression) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlLiteralSetExpression::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlLiteralSetExpression ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlLiteralSetExpression::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlLiteralSetExpression (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlLiteralSetExpression GALGAS_gtlLiteralSetExpression::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlLiteralSetExpression result ;
  const GALGAS_gtlLiteralSetExpression * p = (const GALGAS_gtlLiteralSetExpression *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlLiteralSetExpression *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlLiteralSetExpression", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@type typeName'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string extensionGetter_typeName (const GALGAS_type & inObject,
                                        C_Compiler *
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_typeName ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    const GALGAS_type temp_1 = inObject ;
    test_0 = GALGAS_bool (kIsEqual, temp_1.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_typeName = GALGAS_string ("int") ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      const GALGAS_type temp_3 = inObject ;
      test_2 = GALGAS_bool (kIsEqual, temp_3.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_typeName = GALGAS_string ("char") ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        const GALGAS_type temp_5 = inObject ;
        test_4 = GALGAS_bool (kIsEqual, temp_5.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat))).boolEnum () ;
        if (kBoolTrue == test_4) {
          result_typeName = GALGAS_string ("float") ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          const GALGAS_type temp_7 = inObject ;
          test_6 = GALGAS_bool (kIsEqual, temp_7.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString))).boolEnum () ;
          if (kBoolTrue == test_6) {
            result_typeName = GALGAS_string ("string") ;
          }
        }
        if (kBoolFalse == test_6) {
          enumGalgasBool test_8 = kBoolTrue ;
          if (kBoolTrue == test_8) {
            const GALGAS_type temp_9 = inObject ;
            test_8 = GALGAS_bool (kIsEqual, temp_9.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool))).boolEnum () ;
            if (kBoolTrue == test_8) {
              result_typeName = GALGAS_string ("bool") ;
            }
          }
          if (kBoolFalse == test_8) {
            enumGalgasBool test_10 = kBoolTrue ;
            if (kBoolTrue == test_10) {
              const GALGAS_type temp_11 = inObject ;
              test_10 = GALGAS_bool (kIsEqual, temp_11.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct))).boolEnum () ;
              if (kBoolTrue == test_10) {
                result_typeName = GALGAS_string ("struct") ;
              }
            }
            if (kBoolFalse == test_10) {
              enumGalgasBool test_12 = kBoolTrue ;
              if (kBoolTrue == test_12) {
                const GALGAS_type temp_13 = inObject ;
                test_12 = GALGAS_bool (kIsEqual, temp_13.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlList))).boolEnum () ;
                if (kBoolTrue == test_12) {
                  result_typeName = GALGAS_string ("list") ;
                }
              }
              if (kBoolFalse == test_12) {
                enumGalgasBool test_14 = kBoolTrue ;
                if (kBoolTrue == test_14) {
                  const GALGAS_type temp_15 = inObject ;
                  test_14 = GALGAS_bool (kIsEqual, temp_15.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap))).boolEnum () ;
                  if (kBoolTrue == test_14) {
                    result_typeName = GALGAS_string ("map") ;
                  }
                }
                if (kBoolFalse == test_14) {
                  enumGalgasBool test_16 = kBoolTrue ;
                  if (kBoolTrue == test_16) {
                    const GALGAS_type temp_17 = inObject ;
                    test_16 = GALGAS_bool (kIsEqual, temp_17.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlType))).boolEnum () ;
                    if (kBoolTrue == test_16) {
                      result_typeName = GALGAS_string ("type") ;
                    }
                  }
                  if (kBoolFalse == test_16) {
                    enumGalgasBool test_18 = kBoolTrue ;
                    if (kBoolTrue == test_18) {
                      const GALGAS_type temp_19 = inObject ;
                      test_18 = GALGAS_bool (kIsEqual, temp_19.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum))).boolEnum () ;
                      if (kBoolTrue == test_18) {
                        result_typeName = GALGAS_string ("enum") ;
                      }
                    }
                    if (kBoolFalse == test_18) {
                      enumGalgasBool test_20 = kBoolTrue ;
                      if (kBoolTrue == test_20) {
                        const GALGAS_type temp_21 = inObject ;
                        test_20 = GALGAS_bool (kIsEqual, temp_21.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet))).boolEnum () ;
                        if (kBoolTrue == test_20) {
                          result_typeName = GALGAS_string ("set") ;
                        }
                      }
                      if (kBoolFalse == test_20) {
                        enumGalgasBool test_22 = kBoolTrue ;
                        if (kBoolTrue == test_22) {
                          const GALGAS_type temp_23 = inObject ;
                          test_22 = GALGAS_bool (kIsEqual, temp_23.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed))).boolEnum () ;
                          if (kBoolTrue == test_22) {
                            result_typeName = GALGAS_string ("unconstructed") ;
                          }
                        }
                        if (kBoolFalse == test_22) {
                          result_typeName = GALGAS_string ("-unknown-") ;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
//---
  return result_typeName ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension Getter '@lstring gtlType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type extensionGetter_gtlType (const GALGAS_lstring & inObject,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_type result_type ; // Returned variable
  const GALGAS_lstring temp_0 = inObject ;
  GALGAS_string var_typeName_2291 = temp_0.readProperty_string () ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("int"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt) ;
    }
  }
  if (kBoolFalse == test_1) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("char"))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("float"))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("string"))).boolEnum () ;
          if (kBoolTrue == test_4) {
            result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlString) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("bool"))).boolEnum () ;
            if (kBoolTrue == test_5) {
              result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("struct"))).boolEnum () ;
              if (kBoolTrue == test_6) {
                result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct) ;
              }
            }
            if (kBoolFalse == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("list"))).boolEnum () ;
                if (kBoolTrue == test_7) {
                  result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlList) ;
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("map"))).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlMap) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  enumGalgasBool test_9 = kBoolTrue ;
                  if (kBoolTrue == test_9) {
                    test_9 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("type"))).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlType) ;
                    }
                  }
                  if (kBoolFalse == test_9) {
                    enumGalgasBool test_10 = kBoolTrue ;
                    if (kBoolTrue == test_10) {
                      test_10 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("enum"))).boolEnum () ;
                      if (kBoolTrue == test_10) {
                        result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlEnum) ;
                      }
                    }
                    if (kBoolFalse == test_10) {
                      enumGalgasBool test_11 = kBoolTrue ;
                      if (kBoolTrue == test_11) {
                        test_11 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("set"))).boolEnum () ;
                        if (kBoolTrue == test_11) {
                          result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet) ;
                        }
                      }
                      if (kBoolFalse == test_11) {
                        enumGalgasBool test_12 = kBoolTrue ;
                        if (kBoolTrue == test_12) {
                          test_12 = GALGAS_bool (kIsEqual, var_typeName_2291.objectCompare (GALGAS_string ("unconstructed"))).boolEnum () ;
                          if (kBoolTrue == test_12) {
                            result_type = GALGAS_type (& kTypeDescriptor_GALGAS_gtlUnconstructed) ;
                          }
                        }
                        if (kBoolFalse == test_12) {
                          TC_Array <C_FixItDescription> fixItArray13 ;
                          inCompiler->emitSemanticError (inObject.mProperty_location, GALGAS_string ("unknown type"), fixItArray13  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 80)) ;
                          result_type.drop () ; // Release error dropped variable
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
//---
  return result_type ;
}




//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData location'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlData::getter_location (C_Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_location result_result ; // Returned variable
  result_result = this->mProperty_where ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_location callExtensionGetter_location (const cPtr_gtlData * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_location result ;
  if (nullptr != inObject) {
    result = inObject->getter_location (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData desc'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string callExtensionGetter_desc (const cPtr_gtlData * inObject,
                                        const GALGAS_uint in_tab,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (nullptr != inObject) {
    result = inObject->getter_desc (in_tab, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData string'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string callExtensionGetter_string (const cPtr_gtlData * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
  if (nullptr != inObject) {
    result = inObject->getter_string (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData lstring'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring callExtensionGetter_lstring (const cPtr_gtlData * inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
  if (nullptr != inObject) {
    result = inObject->getter_lstring (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData bool'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_bool (const cPtr_gtlData * inObject,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_bool (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData int'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bigint callExtensionGetter_int (const cPtr_gtlData * inObject,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  GALGAS_bigint result ;
  if (nullptr != inObject) {
    result = inObject->getter_int (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData float'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_double callExtensionGetter_float (const cPtr_gtlData * inObject,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_double result ;
  if (nullptr != inObject) {
    result = inObject->getter_float (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData plusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_plusOp (const cPtr_gtlData * inObject,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_plusOp (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData minusOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_minusOp (const cPtr_gtlData * inObject,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_minusOp (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData notOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_notOp (const cPtr_gtlData * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_notOp (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData addOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_addOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_addOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData subOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_subOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_subOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData mulOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_mulOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_mulOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData divOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_divOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_divOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData modOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_modOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_modOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData andOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_andOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_andOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData orOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_orOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_orOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData xorOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_xorOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_xorOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData slOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_slOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_slOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData srOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_srOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_srOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData neqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_neqOp (const cPtr_gtlData * inObject,
                                          const GALGAS_gtlData in_right,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_neqOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData eqOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_eqOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_eqOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData ltOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_ltOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_ltOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData leOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_leOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_leOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData gtOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_gtOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_gtOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData geOp'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_geOp (const cPtr_gtlData * inObject,
                                         const GALGAS_gtlData in_right,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_geOp (in_right, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData embeddedType'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_type callExtensionGetter_embeddedType (const cPtr_gtlData * inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_type result ;
  if (nullptr != inObject) {
    result = inObject->getter_embeddedType (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension method '@gtlData addMyValue'
//
//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_addMyValue (cPtr_gtlData * inObject,
                                     GALGAS_objectlist & io_objectList,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find method
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    inObject->method_addMyValue (io_objectList, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension getter '@gtlData performGetter'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_performGetter (const cPtr_gtlData * inObject,
                                                  const GALGAS_lstring in_methodName,
                                                  const GALGAS_gtlDataList in_arguments,
                                                  const GALGAS_gtlContext in_context,
                                                  const GALGAS_library in_lib,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_performGetter (in_methodName, in_arguments, in_context, in_lib, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Abstract extension setter '@gtlData performSetter'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_gtlData_performSetter> gExtensionModifierTable_gtlData_performSetter ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_performSetter (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlData_performSetter inModifier) {
  gExtensionModifierTable_gtlData_performSetter.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_gtlData_performSetter (void) {
  gExtensionModifierTable_gtlData_performSetter.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlData_performSetter (NULL,
                                                  freeExtensionModifier_gtlData_performSetter) ;

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_performSetter (cPtr_gtlData * inObject,
                                        const GALGAS_lstring constin_methodName,
                                        const GALGAS_gtlDataList constin_arguments,
                                        const GALGAS_gtlContext constin_context,
                                        const GALGAS_library constin_lib,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_performSetter f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_performSetter.count ()) {
      f = gExtensionModifierTable_gtlData_performSetter (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_performSetter.count ()) {
           f = gExtensionModifierTable_gtlData_performSetter (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_performSetter.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_methodName, constin_arguments, constin_context, constin_lib, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlData structField'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlData::method_structField (const GALGAS_lstring constinArgument_name,
                                       GALGAS_gtlData & outArgument_result,
                                       GALGAS_bool & outArgument_found,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_gtlData temp_0 = this ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.readProperty_location (), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 256)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 256)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 256)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 256)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 256)) ;
  outArgument_result.drop () ; // Release error dropped variable
  outArgument_found.drop () ; // Release error dropped variable
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_structField (cPtr_gtlData * inObject,
                                      const GALGAS_lstring constin_name,
                                      GALGAS_gtlData & out_result,
                                      GALGAS_bool & out_found,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  out_result.drop () ;
  out_found.drop () ;
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    inObject->method_structField  (constin_name, out_result, out_found, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData resultField'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlData::getter_resultField (const GALGAS_lstring constinArgument_name,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  const GALGAS_gtlData temp_0 = this ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.readProperty_location (), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 263)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 263)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 263)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 263)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 263)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlData callExtensionGetter_resultField (const cPtr_gtlData * inObject,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
  if (nullptr != inObject) {
    result = inObject->getter_resultField (in_name, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setStructField'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_gtlData_setStructField> gExtensionModifierTable_gtlData_setStructField ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setStructField (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlData_setStructField inModifier) {
  gExtensionModifierTable_gtlData_setStructField.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setStructField (cPtr_gtlData * inObject,
                                         const GALGAS_lstring constin_name,
                                         const GALGAS_gtlData constin_data,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setStructField f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setStructField.count ()) {
      f = gExtensionModifierTable_gtlData_setStructField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setStructField.count ()) {
           f = gExtensionModifierTable_gtlData_setStructField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setStructField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_data, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlData_setStructField (cPtr_gtlData * inObject,
                                                    const GALGAS_lstring constinArgument_name,
                                                    const GALGAS_gtlData /* constinArgument_data */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.readProperty_location (), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 271)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 271)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 271)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 271)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 271)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlData_setStructField (void) {
  enterExtensionSetter_setStructField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                       extensionSetter_gtlData_setStructField) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_gtlData_setStructField (void) {
  gExtensionModifierTable_gtlData_setStructField.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlData_setStructField (defineExtensionSetter_gtlData_setStructField,
                                                   freeExtensionModifier_gtlData_setStructField) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setStructFieldAtLevel'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_gtlData_setStructFieldAtLevel> gExtensionModifierTable_gtlData_setStructFieldAtLevel ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setStructFieldAtLevel (const int32_t inClassIndex,
                                                 extensionSetterSignature_gtlData_setStructFieldAtLevel inModifier) {
  gExtensionModifierTable_gtlData_setStructFieldAtLevel.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setStructFieldAtLevel (cPtr_gtlData * inObject,
                                                const GALGAS_lstring constin_name,
                                                const GALGAS_gtlData constin_data,
                                                const GALGAS_uint constin_level,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setStructFieldAtLevel f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setStructFieldAtLevel.count ()) {
      f = gExtensionModifierTable_gtlData_setStructFieldAtLevel (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setStructFieldAtLevel.count ()) {
           f = gExtensionModifierTable_gtlData_setStructFieldAtLevel (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setStructFieldAtLevel.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_data, constin_level, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlData_setStructFieldAtLevel (cPtr_gtlData * inObject,
                                                           const GALGAS_lstring constinArgument_name,
                                                           const GALGAS_gtlData /* constinArgument_data */,
                                                           const GALGAS_uint /* constinArgument_level */,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.readProperty_location (), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 280)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 280)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 280)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 280)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 280)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlData_setStructFieldAtLevel (void) {
  enterExtensionSetter_setStructFieldAtLevel (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                              extensionSetter_gtlData_setStructFieldAtLevel) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_gtlData_setStructFieldAtLevel (void) {
  gExtensionModifierTable_gtlData_setStructFieldAtLevel.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlData_setStructFieldAtLevel (defineExtensionSetter_gtlData_setStructFieldAtLevel,
                                                          freeExtensionModifier_gtlData_setStructFieldAtLevel) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData deleteStructField'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_gtlData_deleteStructField> gExtensionModifierTable_gtlData_deleteStructField ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_deleteStructField (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlData_deleteStructField inModifier) {
  gExtensionModifierTable_gtlData_deleteStructField.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_deleteStructField (cPtr_gtlData * inObject,
                                            const GALGAS_lstring constin_name,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_deleteStructField f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_deleteStructField.count ()) {
      f = gExtensionModifierTable_gtlData_deleteStructField (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_deleteStructField.count ()) {
           f = gExtensionModifierTable_gtlData_deleteStructField (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_deleteStructField.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlData_deleteStructField (cPtr_gtlData * inObject,
                                                       const GALGAS_lstring constinArgument_name,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.readProperty_location (), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 286)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 286)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 286)).add_operation (GALGAS_string (" is not a struct"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 286)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 286)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlData_deleteStructField (void) {
  enterExtensionSetter_deleteStructField (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                          extensionSetter_gtlData_deleteStructField) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_gtlData_deleteStructField (void) {
  gExtensionModifierTable_gtlData_deleteStructField.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlData_deleteStructField (defineExtensionSetter_gtlData_deleteStructField,
                                                      freeExtensionModifier_gtlData_deleteStructField) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData hasStructField'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlData::getter_hasStructField (const GALGAS_lstring /* constinArgument_name */,
                                                 C_Compiler */* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasStructField (const cPtr_gtlData * inObject,
                                                const GALGAS_lstring in_name,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_hasStructField (in_name, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData overrideMap'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStruct cPtr_gtlData::getter_overrideMap (C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlStruct result_mapOverriden ; // Returned variable
  const GALGAS_gtlData temp_0 = this ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 299)), GALGAS_string ("INTERNAL ERROR : a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 299)) ;
  result_mapOverriden.drop () ; // Release error dropped variable
//---
  return result_mapOverriden ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStruct callExtensionGetter_overrideMap (const cPtr_gtlData * inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlStruct result ;
  if (nullptr != inObject) {
    result = inObject->getter_overrideMap (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData overriddenMap'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStruct cPtr_gtlData::getter_overriddenMap (C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlStruct result_overriddenMap ; // Returned variable
  const GALGAS_gtlData temp_0 = this ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) temp_0.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 305)), GALGAS_string ("INTERNAL ERROR : a variable map should be a @gtlStruct"), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 305)) ;
  result_overriddenMap.drop () ; // Release error dropped variable
//---
  return result_overriddenMap ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlStruct callExtensionGetter_overriddenMap (const cPtr_gtlData * inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlStruct result ;
  if (nullptr != inObject) {
    result = inObject->getter_overriddenMap (inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@gtlData mapItem'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlData::method_mapItem (const GALGAS_lstring constinArgument_name,
                                   GALGAS_gtlData & outArgument_result,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  const GALGAS_gtlData temp_0 = this ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.readProperty_location (), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 312)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 312)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 312)).add_operation (GALGAS_string (" is not a map"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 312)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 312)) ;
  outArgument_result.drop () ; // Release error dropped variable
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_mapItem (cPtr_gtlData * inObject,
                                  const GALGAS_lstring constin_name,
                                  GALGAS_gtlData & out_result,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  out_result.drop () ;
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    inObject->method_mapItem  (constin_name, out_result, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlData hasMapItem'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlData::getter_hasMapItem (const GALGAS_lstring /* constinArgument_name */,
                                             C_Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
//---
  return result_result ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasMapItem (const cPtr_gtlData * inObject,
                                            const GALGAS_lstring in_name,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_hasMapItem (in_name, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlData setMapItem'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_gtlData_setMapItem> gExtensionModifierTable_gtlData_setMapItem ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setMapItem (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlData_setMapItem inModifier) {
  gExtensionModifierTable_gtlData_setMapItem.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setMapItem (cPtr_gtlData * inObject,
                                     const GALGAS_lstring constin_name,
                                     const GALGAS_gtlData constin_data,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlData) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlData_setMapItem f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlData_setMapItem.count ()) {
      f = gExtensionModifierTable_gtlData_setMapItem (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlData_setMapItem.count ()) {
           f = gExtensionModifierTable_gtlData_setMapItem (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlData_setMapItem.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_name, constin_data, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlData_setMapItem (cPtr_gtlData * inObject,
                                                const GALGAS_lstring constinArgument_name,
                                                const GALGAS_gtlData /* constinArgument_data */,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlData * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlData) ;
  const GALGAS_gtlData temp_0 = object ;
  TC_Array <C_FixItDescription> fixItArray1 ;
  inCompiler->emitSemanticError (constinArgument_name.readProperty_location (), GALGAS_string ("a ").add_operation (extensionGetter_typeName (temp_0.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 326)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 326)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 326)).add_operation (GALGAS_string (" is not a map"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 326)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 326)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlData_setMapItem (void) {
  enterExtensionSetter_setMapItem (kTypeDescriptor_GALGAS_gtlData.mSlotID,
                                   extensionSetter_gtlData_setMapItem) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_gtlData_setMapItem (void) {
  gExtensionModifierTable_gtlData_setMapItem.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlData_setMapItem (defineExtensionSetter_gtlData_setMapItem,
                                               freeExtensionModifier_gtlData_setMapItem) ;

