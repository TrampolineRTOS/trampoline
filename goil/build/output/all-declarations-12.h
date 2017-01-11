#ifndef all_2D_declarations_2D__31__32__ENTITIES_DEFINED
#define all_2D_declarations_2D__31__32__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "all-predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-11.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'arxmlDefinitionRoot'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlDefinitionRoot (class GALGAS_implementation & ioArgument0,
                                  class GALGAS_applicationDefinition & ioArgument1,
                                  class GALGAS_arxmlElementValue inArgument2,
                                  class GALGAS_lstring inArgument3,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'arxmlDefinitionObject'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlDefinitionObject (class GALGAS_implementation & ioArgument0,
                                    class GALGAS_objectsMap & ioArgument1,
                                    class GALGAS_arxmlElementValue inArgument2,
                                    class GALGAS_lstring inArgument3,
                                    class C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Routine 'arxmlDefinitionContainer'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlDefinitionContainer (const class GALGAS_implementationObjectMap constinArgument0,
                                       class GALGAS_objectAttributes & ioArgument1,
                                       class GALGAS_arxmlElementValue inArgument2,
                                       class GALGAS_lstring inArgument3,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'oilEquivalentName'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_oilEquivalentName (class GALGAS_lstring inArgument0,
                                class GALGAS_lstring inArgument1,
                                class GALGAS_lstring & outArgument2,
                                class C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Routine 'arxmlDefinitionParameter'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_arxmlDefinitionParameter (const class GALGAS_implementationObjectMap constinArgument0,
                                       class GALGAS_objectAttributes & ioArgument1,
                                       class GALGAS_arxmlElementValue inArgument2,
                                       class GALGAS_lstring inArgument3,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'testTypeError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_testTypeError (class GALGAS_dataType inArgument0,
                            class GALGAS_lstring inArgument1,
                            class C_Compiler * inCompiler
                            COMMA_LOCATION_ARGS) ;

#endif
