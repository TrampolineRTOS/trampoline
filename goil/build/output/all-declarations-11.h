#pragma once

//----------------------------------------------------------------------------------------------------------------------

#include "all-predefined-types.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-10.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyGoilContext'
//
//----------------------------------------------------------------------------------------------------------------------

class GALGAS_goilContext function_emptyGoilContext (class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'nodeToClassRes'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_nodeToClassRes (class GALGAS_arxmlElementNode inArgument0,
                             class GALGAS_arxmlMetaClassMap inArgument1,
                             class GALGAS_arxmlElementValue & outArgument2,
                             class C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionPackage'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionPackage (class GALGAS_implementation & ioArgument0,
                                     class GALGAS_applicationDefinition & ioArgument1,
                                     class GALGAS_arxmlElementValue inArgument2,
                                     class GALGAS_lstring inArgument3,
                                     class C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationPackage'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationPackage (class GALGAS_implementation & ioArgument0,
                                         class GALGAS_arxmlElementValue inArgument1,
                                         class GALGAS_lstring inArgument2,
                                         class C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationRoot'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationRoot (class GALGAS_implementation & ioArgument0,
                                      class GALGAS_arxmlElementValue inArgument1,
                                      class GALGAS_lstring inArgument2,
                                      class C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetDescription'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetDescription (class GALGAS_arxmlElementValue inArgument0,
                                  class GALGAS_lstring & outArgument1,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationObject'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationObject (class GALGAS_implementation & ioArgument0,
                                        class GALGAS_arxmlElementValue inArgument1,
                                        class GALGAS_lstring inArgument2,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetMultiplicity'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetMultiplicity (class GALGAS_arxmlElementValue inArgument0,
                                   class GALGAS_lstring inArgument1,
                                   class GALGAS_lbool & outArgument2,
                                   class C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainer'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainer (class GALGAS_implementationObjectMap & ioArgument0,
                                           class GALGAS_arxmlElementValue inArgument1,
                                           class GALGAS_lstring inArgument2,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerBoolean'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerBoolean (class GALGAS_lstring & outArgument0,
                                                  class GALGAS_impType & outArgument1,
                                                  const class GALGAS_dataType constinArgument2,
                                                  class GALGAS_arxmlElementValue inArgument3,
                                                  class GALGAS_lstring inArgument4,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerEnumeration'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerEnumeration (class GALGAS_lstring & outArgument0,
                                                      class GALGAS_impType & outArgument1,
                                                      const class GALGAS_dataType constinArgument2,
                                                      class GALGAS_arxmlElementValue inArgument3,
                                                      class GALGAS_lstring inArgument4,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerIdentifier'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerIdentifier (class GALGAS_lstring & outArgument0,
                                                     class GALGAS_impType & outArgument1,
                                                     const class GALGAS_dataType constinArgument2,
                                                     class GALGAS_arxmlElementValue inArgument3,
                                                     class GALGAS_lstring inArgument4,
                                                     class C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerNumber'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerNumber (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_impType & outArgument1,
                                                 const class GALGAS_dataType constinArgument2,
                                                 class GALGAS_arxmlElementValue inArgument3,
                                                 class GALGAS_lstring inArgument4,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerReference'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerReference (class GALGAS_lstring & outArgument0,
                                                    class GALGAS_impType & outArgument1,
                                                    const class GALGAS_dataType constinArgument2,
                                                    class GALGAS_arxmlElementValue inArgument3,
                                                    class GALGAS_lstring inArgument4,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerString'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerString (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_impType & outArgument1,
                                                 const class GALGAS_dataType constinArgument2,
                                                 class GALGAS_arxmlElementValue inArgument3,
                                                 class GALGAS_lstring inArgument4,
                                                 class C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerStructure'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerStructure (class GALGAS_lstring & outArgument0,
                                                    class GALGAS_impType & outArgument1,
                                                    const class GALGAS_dataType constinArgument2,
                                                    class GALGAS_arxmlElementValue inArgument3,
                                                    class GALGAS_lstring inArgument4,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlInsertObjectAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlInsertObjectAttribute (class GALGAS_implementationObjectMap & ioArgument0,
                                         class GALGAS_lstring inArgument1,
                                         class GALGAS_impType inArgument2,
                                         class C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetName'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetName (class GALGAS_arxmlElementValue inArgument0,
                           class GALGAS_lstring & outArgument1,
                           class C_Compiler * inCompiler
                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetWithAuto'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetWithAuto (class GALGAS_arxmlElementValue inArgument0,
                               class GALGAS_bool & outArgument1,
                               class C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlPopSign'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlPopSign (class GALGAS_lstring & ioArgument0,
                           class GALGAS_bool & outArgument1,
                           class C_Compiler * inCompiler
                           COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionRoot'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionRoot (class GALGAS_implementation & ioArgument0,
                                  class GALGAS_applicationDefinition & ioArgument1,
                                  class GALGAS_arxmlElementValue inArgument2,
                                  class GALGAS_lstring inArgument3,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionObject'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionObject (class GALGAS_implementation & ioArgument0,
                                    class GALGAS_objectsMap & ioArgument1,
                                    class GALGAS_arxmlElementValue inArgument2,
                                    class GALGAS_lstring inArgument3,
                                    class C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionContainer'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionContainer (const class GALGAS_implementationObjectMap constinArgument0,
                                       class GALGAS_objectAttributes & ioArgument1,
                                       class GALGAS_arxmlElementValue inArgument2,
                                       class GALGAS_lstring inArgument3,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'oilEquivalentName'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_oilEquivalentName (class GALGAS_lstring inArgument0,
                                class GALGAS_lstring inArgument1,
                                class GALGAS_lstring & outArgument2,
                                class C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionParameter'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionParameter (const class GALGAS_implementationObjectMap constinArgument0,
                                       class GALGAS_objectAttributes & ioArgument1,
                                       class GALGAS_arxmlElementValue inArgument2,
                                       class GALGAS_lstring inArgument3,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'testTypeError'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_testTypeError (class GALGAS_dataType inArgument0,
                            class GALGAS_lstring inArgument1,
                            class C_Compiler * inCompiler
                            COMMA_LOCATION_ARGS) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'print'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_print (const class GALGAS_string constinArgument0,
                    class C_Compiler * inCompiler
                    COMMA_LOCATION_ARGS) ;

