#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-11.h"

//----------------------------------------------------------------------------------------------------------------------
//
//Function 'emptyGoilContext'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_goilContext function_emptyGoilContext (C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_goilContext result_context ; // Returned variable
  result_context = GALGAS_goilContext::constructor_new (function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 710)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string (".gtl"), GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 715)), GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("goil_code_generation.galgas", 716)), GALGAS_bool (true), function_defaultDebugSettings (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 718))  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 709)) ;
//---
  return result_context ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyGoilContext [1] = {
  nullptr
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyGoilContext (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_emptyGoilContext (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyGoilContext ("emptyGoilContext",
                                                                  functionWithGenericHeader_emptyGoilContext,
                                                                  & kTypeDescriptor_GALGAS_goilContext,
                                                                  0,
                                                                  functionArgs_emptyGoilContext) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'generate_all'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_generate_5F_all (GALGAS_gtlData inArgument_cfg,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_temp_5F_dir_23447 = function_templates_5F_directory (GALGAS_string ("code"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 735)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, var_temp_5F_dir_23447.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_target_23531 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, var_target_23531.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_gtlContext var_context_23634 = function_emptyGoilContext (inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 741)) ;
          {
          var_context_23634.setter_setTemplateDirectory (function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 743)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 742)) ;
          }
          {
          var_context_23634.setter_setUserTemplateDirectory (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 746)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_code_generation.galgas", 746)).add_operation (GALGAS_string ("/templates"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 746)) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 745)) ;
          }
          {
          var_context_23634.setter_setTemplateExtension (GALGAS_string ("goilTemplate") COMMA_SOURCE_FILE ("goil_code_generation.galgas", 749)) ;
          }
          {
          var_context_23634.insulate (HERE) ;
          cPtr_gtlContext * ptr_24018 = (cPtr_gtlContext *) var_context_23634.ptr () ;
          callExtensionSetter_addModulePath ((cPtr_gtlContext *) ptr_24018, function_templates_5F_directory (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 753)), GALGAS_string ("lib"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 752)) ;
          }
          {
          var_context_23634.setter_setPath (GALGAS_string (gOption_goil_5F_options_target_5F_platform.readProperty_value ()) COMMA_SOURCE_FILE ("goil_code_generation.galgas", 756)) ;
          }
          GALGAS_string var_goilLog_24251 = function_invokeGTL (GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 762)), function_lstring (GALGAS_string ("root template filename"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 763)), GALGAS_string (gOption_goil_5F_options_root.readProperty_value ())  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 761)), var_context_23634, inArgument_cfg, inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 760)) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (gOption_goil_5F_options_generate_5F_log.readProperty_value ()).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_goilLog_24251.method_writeToFile (GALGAS_string ("goil.log"), inCompiler COMMA_SOURCE_FILE ("goil_code_generation.galgas", 771)) ;
            }
          }
        }
      }
      if (kBoolFalse == test_1) {
        inCompiler->printMessage (GALGAS_string ("No target platform given, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 775)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    inCompiler->printMessage (GALGAS_string ("No template directory defined, compiling aborted\n")  COMMA_SOURCE_FILE ("goil_code_generation.galgas", 778)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'getAutosarVersion'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_getAutosarVersion (GALGAS_arxmlNode inArgument_rootNode,
                                GALGAS_lstring & outArgument_iAutosarVersion,
                                GALGAS_lstring & outArgument_iAutosarDescription,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_iAutosarVersion.drop () ; // Release 'out' argument
  outArgument_iAutosarDescription.drop () ; // Release 'out' argument
  GALGAS_lstring var_autosarVersion_7851 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 273)) ;
  GALGAS_lstring var_autosarDescription_7896 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 274)) ;
  GALGAS_arxmlElementList var_autosarNodes_8021 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 277)) ;
  callExtensionMethod_getSubElementsFromName ((cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_8021, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 278)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_8021.getter_count (SOURCE_FILE ("arxml_parser.galgas", 279)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 280)) ;
    }
  }
  GALGAS_arxmlElementList var_adminDataNodes_8238 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 283)) ;
  extensionMethod_getSubElementsFromName (var_autosarNodes_8021, GALGAS_string ("ADMIN-DATA"), var_adminDataNodes_8238, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 284)) ;
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_adminDataNodes_8238.getter_count (SOURCE_FILE ("arxml_parser.galgas", 285)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)), GALGAS_string ("[TPS_ECUC_06004] : Missing AUTOSAR's ADMIN-DATA node."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 286)) ;
    }
  }
  GALGAS_arxmlElementList var_revisions_8477 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 289)) ;
  extensionMethod_getElementsFromName (var_adminDataNodes_8238, GALGAS_string ("DOC-REVISION"), var_revisions_8477, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 290)) ;
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = GALGAS_bool (kIsEqual, var_adminDataNodes_8238.getter_count (SOURCE_FILE ("arxml_parser.galgas", 291)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      TC_Array <C_FixItDescription> fixItArray5 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)), GALGAS_string ("Missing AUTOSAR'S ADMIN-DATA's DOC-REVISION NODE"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 292)) ;
    }
  }
  GALGAS_bool var_version_5F_found_8690 = GALGAS_bool (false) ;
  GALGAS_bool var_issued_5F_by_5F_found_8720 = GALGAS_bool (false) ;
  GALGAS_lstring var_issued_5F_by_8755 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 297)) ;
  cEnumerator_arxmlElementList enumerator_8810 (var_revisions_8477, kENUMERATION_UP) ;
  bool bool_6 = var_version_5F_found_8690.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
  if (enumerator_8810.hasCurrentObject () && bool_6) {
    while (enumerator_8810.hasCurrentObject () && bool_6) {
      var_issued_5F_by_5F_found_8720 = GALGAS_bool (false) ;
      callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_8810.current_node (HERE).ptr (), GALGAS_string ("ISSUED-BY"), var_issued_5F_by_8755, var_issued_5F_by_5F_found_8720, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 302)) ;
      enumGalgasBool test_7 = kBoolTrue ;
      if (kBoolTrue == test_7) {
        GALGAS_bool test_8 = var_issued_5F_by_5F_found_8720 ;
        if (kBoolTrue == test_8.boolEnum ()) {
          test_8 = GALGAS_bool (kIsEqual, var_issued_5F_by_8755.readProperty_string ().objectCompare (GALGAS_string ("AUTOSAR"))) ;
        }
        test_7 = test_8.boolEnum () ;
        if (kBoolTrue == test_7) {
          GALGAS_bool var_description_5F_found_9033 = GALGAS_bool (false) ;
          callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_8810.current_node (HERE).ptr (), GALGAS_string ("REVISION-LABEL"), var_autosarVersion_7851, var_version_5F_found_8690, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 305)) ;
          callExtensionMethod_getProperty ((cPtr_arxmlElementNode *) enumerator_8810.current_node (HERE).ptr (), GALGAS_string ("DATE"), var_autosarDescription_7896, var_description_5F_found_9033, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 306)) ;
        }
      }
      enumerator_8810.gotoNextObject () ;
      if (enumerator_8810.hasCurrentObject ()) {
        bool_6 = var_version_5F_found_8690.operator_not (SOURCE_FILE ("arxml_parser.galgas", 300)).isValidAndTrue () ;
      }
    }
  }
  outArgument_iAutosarVersion = var_autosarVersion_7851 ;
  outArgument_iAutosarDescription = var_autosarDescription_7896 ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'includeConfigs'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_includeConfigs (GALGAS_implementation & ioArgument_imp,
                             GALGAS_applicationDefinition & ioArgument_application,
                             GALGAS_string & ioArgument_fileIncludeList,
                             GALGAS_lstring inArgument_version,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_config_5F_file_5F_name_9573 = GALGAS_string (gOption_goil_5F_options_config.readProperty_value ()) ;
  GALGAS_stringlist var_configFiles_9647 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9573.add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 325)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 324)) ;
  cEnumerator_stringlist enumerator_9906 (var_configFiles_9647, kENUMERATION_DOWN) ;
  while (enumerator_9906.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_9906.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 330)) ;
    enumerator_9906.gotoNextObject () ;
  }
  GALGAS_stringlist var_configVersionFiles_10217 = function_allTemplateFilePaths (GALGAS_string ("config"), var_config_5F_file_5F_name_9573.add_operation (inArgument_version.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)).add_operation (GALGAS_string (".oil"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 336)) ;
  cEnumerator_stringlist enumerator_10369 (var_configVersionFiles_10217, kENUMERATION_DOWN) ;
  while (enumerator_10369.hasCurrentObject ()) {
    cGrammar_goil_5F_file_5F_level_5F_include::_performSourceFileParsing_ (inCompiler, function_lstringWith (enumerator_10369.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)), ioArgument_imp, ioArgument_application, ioArgument_fileIncludeList, GALGAS_bool (false)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 340)) ;
    enumerator_10369.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'nodeToClass'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_nodeToClass (GALGAS_arxmlNode inArgument_rootNode,
                          GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                          GALGAS_arxmlElementValue & outArgument_rootValue,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_rootValue.drop () ; // Release 'out' argument
  GALGAS_arxmlElementList var_autosarNodes_10738 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 351)) ;
  callExtensionMethod_getSubElementsFromName ((cPtr_arxmlNode *) inArgument_rootNode.ptr (), GALGAS_string ("AUTOSAR"), var_autosarNodes_10738, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 352)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_autosarNodes_10738.getter_count (SOURCE_FILE ("arxml_parser.galgas", 353)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)), GALGAS_string ("[TPS_GST_00077] : Missing root AUTOSAR node."), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 354)) ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsStrictSup, var_autosarNodes_10738.getter_count (SOURCE_FILE ("arxml_parser.galgas", 356)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)), GALGAS_string ("[TPS_GST_00077] : Too many AUTOSAR nodes."), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 357)) ;
    }
  }
  GALGAS_arxmlElementNode var_autosarNode_11098 ;
  var_autosarNodes_10738.method_first (var_autosarNode_11098, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 362)) ;
  {
  routine_nodeToClassRes (var_autosarNode_11098, ioArgument_classMap, outArgument_rootValue, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 363)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'nodeToClassRes'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_nodeToClassRes (GALGAS_arxmlElementNode inArgument_currentElement,
                             GALGAS_arxmlMetaClassMap inArgument_classMap,
                             GALGAS_arxmlElementValue & outArgument_elementValue,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_elementValue.drop () ; // Release 'out' argument
  GALGAS_arxmlMetaClass var_currentClass_11372 ;
  inArgument_classMap.method_searchKey (inArgument_currentElement.readProperty_name (), var_currentClass_11372, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 373)) ;
  GALGAS_bool var_textFound_11481 = GALGAS_bool (false) ;
  GALGAS_lstring var_text_11510 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 377))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 377)) ;
  callExtensionMethod_getText ((cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_text_11510, var_textFound_11481, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 378)) ;
  GALGAS_lstring var_type_11628 = var_currentClass_11372.readProperty_name () ;
  outArgument_elementValue = GALGAS_arxmlElementValue::constructor_new (var_type_11628, var_text_11510, GALGAS_arxmlElementValueMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 385)), inArgument_currentElement.readProperty_attributes ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 382)) ;
  GALGAS_arxmlElementList var_subElements_12034 ;
  callExtensionMethod_getSubElements ((cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), var_subElements_12034, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 390)) ;
  cEnumerator_arxmlElementList enumerator_12072 (var_subElements_12034, kENUMERATION_UP) ;
  while (enumerator_12072.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlMetaClass *) var_currentClass_11372.ptr (), enumerator_12072.current_node (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 392)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 392)).boolEnum () ;
      if (kBoolTrue == test_0) {
        TC_Array <C_FixItDescription> fixItArray1 ;
        inCompiler->emitSemanticError (enumerator_12072.current_node (HERE).readProperty_name ().readProperty_location (), GALGAS_string ("The element ").add_operation (enumerator_12072.current_node (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)).add_operation (inArgument_currentElement.readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 394)).add_operation (GALGAS_string (" element.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (GALGAS_string ("Possible elements are :\n "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 395)).add_operation (extensionGetter_string (var_currentClass_11372.readProperty_lElementLegacy (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 396)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 393)) ;
      }
    }
    enumerator_12072.gotoNextObject () ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsNotEqual, inArgument_currentElement.readProperty_name ().readProperty_string ().objectCompare (GALGAS_string ("AUTOSAR"))).boolEnum () ;
    if (kBoolTrue == test_2) {
      cEnumerator_arxmlAttributeMap enumerator_12603 (inArgument_currentElement.readProperty_attributes (), kENUMERATION_UP) ;
      while (enumerator_12603.hasCurrentObject ()) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = callExtensionGetter_hasAttribute ((const cPtr_arxmlMetaClass *) var_currentClass_11372.ptr (), enumerator_12603.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 404)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 404)).boolEnum () ;
          if (kBoolTrue == test_3) {
            TC_Array <C_FixItDescription> fixItArray4 ;
            inCompiler->emitSemanticError (enumerator_12603.current_lkey (HERE).readProperty_location (), GALGAS_string ("The attribute ").add_operation (enumerator_12603.current_lkey (HERE).readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" does not belong to the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (inArgument_currentElement.readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)).add_operation (GALGAS_string (" element.\nPossible "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (GALGAS_string ("attributes are :\n "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 406)).add_operation (extensionGetter_string (var_currentClass_11372.readProperty_lAttributeLegacy (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 407)), fixItArray4  COMMA_SOURCE_FILE ("arxml_parser.galgas", 405)) ;
          }
        }
        enumerator_12603.gotoNextObject () ;
      }
    }
  }
  cEnumerator_arxmlMetaElementList enumerator_13044 (var_currentClass_11372.readProperty_lElementLegacy (), kENUMERATION_UP) ;
  while (enumerator_13044.hasCurrentObject ()) {
    GALGAS_arxmlElementList var_subElements_13112 = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 414)) ;
    callExtensionMethod_getSubElementsFromName ((cPtr_arxmlElementNode *) inArgument_currentElement.ptr (), enumerator_13044.current_lElement (HERE).readProperty_name ().readProperty_string (), var_subElements_13112, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 416)) ;
    GALGAS_uint var_minOccurs_13331 = GALGAS_uint (uint32_t (1U)) ;
    GALGAS_uint var_maxOccurs_13355 = GALGAS_uint (uint32_t (1U)) ;
    enumGalgasBool test_5 = kBoolTrue ;
    if (kBoolTrue == test_5) {
      GALGAS_bool test_6 = GALGAS_bool (kIsNotEqual, enumerator_13044.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
      if (kBoolTrue == test_6.boolEnum ()) {
        test_6 = enumerator_13044.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 424)) ;
      }
      test_5 = test_6.boolEnum () ;
      if (kBoolTrue == test_5) {
        var_minOccurs_13331 = enumerator_13044.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 425)) ;
      }
    }
    enumGalgasBool test_7 = kBoolTrue ;
    if (kBoolTrue == test_7) {
      test_7 = GALGAS_bool (kIsStrictInf, var_subElements_13112.getter_count (SOURCE_FILE ("arxml_parser.galgas", 428)).objectCompare (var_minOccurs_13331)).boolEnum () ;
      if (kBoolTrue == test_7) {
        TC_Array <C_FixItDescription> fixItArray8 ;
        inCompiler->emitSemanticError (inArgument_currentElement.readProperty_name ().readProperty_location (), GALGAS_string ("Missing element ").add_operation (enumerator_13044.current_lElement (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)).add_operation (var_minOccurs_13331.getter_string (SOURCE_FILE ("arxml_parser.galgas", 430)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 430)).add_operation (var_subElements_13112.getter_count (SOURCE_FILE ("arxml_parser.galgas", 431)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 431)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 431)), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 429)) ;
      }
    }
    enumGalgasBool test_9 = kBoolTrue ;
    if (kBoolTrue == test_9) {
      GALGAS_bool test_10 = GALGAS_bool (kIsNotEqual, enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().objectCompare (GALGAS_string ("unbounded"))) ;
      if (kBoolTrue == test_10.boolEnum ()) {
        test_10 = GALGAS_bool (kIsNotEqual, enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
      }
      test_9 = test_10.boolEnum () ;
      if (kBoolTrue == test_9) {
        enumGalgasBool test_11 = kBoolTrue ;
        if (kBoolTrue == test_11) {
          GALGAS_bool test_12 = GALGAS_bool (kIsNotEqual, enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
          if (kBoolTrue == test_12.boolEnum ()) {
            test_12 = enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().getter_isDecimalUnsignedNumber (SOURCE_FILE ("arxml_parser.galgas", 439)) ;
          }
          test_11 = test_12.boolEnum () ;
          if (kBoolTrue == test_11) {
            var_maxOccurs_13355 = enumerator_13044.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 440)) ;
          }
        }
        enumGalgasBool test_13 = kBoolTrue ;
        if (kBoolTrue == test_13) {
          test_13 = GALGAS_bool (kIsStrictSup, var_subElements_13112.getter_count (SOURCE_FILE ("arxml_parser.galgas", 443)).objectCompare (var_maxOccurs_13355)).boolEnum () ;
          if (kBoolTrue == test_13) {
            TC_Array <C_FixItDescription> fixItArray14 ;
            inCompiler->emitSemanticError (inArgument_currentElement.readProperty_name ().readProperty_location (), GALGAS_string ("Too many node ").add_operation (enumerator_13044.current_lElement (HERE).readProperty_name ().readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 444)).add_operation (GALGAS_string (". Minimum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 444)).add_operation (var_minOccurs_13331.getter_string (SOURCE_FILE ("arxml_parser.galgas", 445)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (GALGAS_string (" ; Maximum : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (var_maxOccurs_13355.getter_string (SOURCE_FILE ("arxml_parser.galgas", 445)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (GALGAS_string (". Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 445)).add_operation (var_subElements_13112.getter_count (SOURCE_FILE ("arxml_parser.galgas", 446)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 446)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 446)), fixItArray14  COMMA_SOURCE_FILE ("arxml_parser.galgas", 444)) ;
          }
        }
      }
    }
    cEnumerator_arxmlElementList enumerator_14632 (var_subElements_13112, kENUMERATION_UP) ;
    while (enumerator_14632.hasCurrentObject ()) {
      GALGAS_arxmlElementValue var_subElementValue_14691 ;
      {
      routine_nodeToClassRes (enumerator_14632.current_node (HERE), inArgument_classMap, var_subElementValue_14691, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 453)) ;
      }
      {
      outArgument_elementValue.insulate (HERE) ;
      cPtr_arxmlElementValue * ptr_14777 = (cPtr_arxmlElementValue *) outArgument_elementValue.ptr () ;
      callExtensionSetter_insertElement ((cPtr_arxmlElementValue *) ptr_14777, enumerator_14632.current_node (HERE).readProperty_name (), var_subElementValue_14691, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 454)) ;
      }
      enumerator_14632.gotoNextObject () ;
    }
    enumerator_13044.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'addText'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_addText (GALGAS_arxmlNodeList & ioArgument_nodes,
                      const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                      C_Compiler * inCompiler
                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_s_14956 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 463)) ;
  GALGAS_string var_trimmedString_15006 = var_s_14956.getter_stringByTrimmingWhiteSpaces (SOURCE_FILE ("arxml_parser.galgas", 464)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_trimmedString_15006.getter_count (SOURCE_FILE ("arxml_parser.galgas", 465)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_ls_15108 ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = constinArgument_doNotCondenseWhiteSpaces.boolEnum () ;
        if (kBoolTrue == test_1) {
          var_ls_15108 = GALGAS_lstring::constructor_new (var_s_14956, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 468))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 468)) ;
        }
      }
      if (kBoolFalse == test_1) {
        var_ls_15108 = GALGAS_lstring::constructor_new (var_trimmedString_15006, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 470)) ;
      }
      ioArgument_nodes.addAssign_operation (GALGAS_arxmlTextNode::constructor_new (var_ls_15108  COMMA_SOURCE_FILE ("arxml_parser.galgas", 473))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 473)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'convertToOil'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_convertToOil (GALGAS_implementation & ioArgument_imp,
                           GALGAS_applicationDefinition & ioArgument_application,
                           GALGAS_arxmlElementValue inArgument_rootValue,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_emptyPath_15418 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 482))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 482)) ;
  GALGAS_arxmlElementValueList var_packages_15505 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 485)) ;
  GALGAS_stringlist var_packagesPath_15533 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 486)) ;
  var_packagesPath_15533.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 487)) ;
  var_packagesPath_15533.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 488)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_rootValue.ptr (), var_packagesPath_15533, var_packages_15505, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 489)) ;
  cEnumerator_arxmlElementValueList enumerator_15722 (var_packages_15505, kENUMERATION_UP) ;
  while (enumerator_15722.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage (ioArgument_imp, enumerator_15722.current_value (HERE), var_emptyPath_15418, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 493)) ;
    }
    enumerator_15722.gotoNextObject () ;
  }
  cEnumerator_arxmlElementValueList enumerator_15856 (var_packages_15505, kENUMERATION_UP) ;
  while (enumerator_15856.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage (ioArgument_imp, ioArgument_application, enumerator_15856.current_value (HERE), var_emptyPath_15418, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 498)) ;
    }
    enumerator_15856.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationPackage'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationPackage (GALGAS_implementation & ioArgument_imp,
                                         GALGAS_arxmlElementValue inArgument_packageElement,
                                         GALGAS_lstring inArgument_parentPath,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_16229 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 512)) ;
  GALGAS_lstring var_currentPath_16342 = GALGAS_lstring::constructor_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 515)).add_operation (var_packageName_16229.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 515)), var_packageName_16229.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 515)) ;
  GALGAS_arxmlElementValueList var_definitions_16572 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 519)) ;
  GALGAS_stringlist var_definitionPath_16603 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 520)) ;
  var_definitionPath_16603.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 521)) ;
  var_definitionPath_16603.addAssign_operation (GALGAS_string ("ECUC-MODULE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 522)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_16603, var_definitions_16572, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 523)) ;
  cEnumerator_arxmlElementValueList enumerator_16786 (var_definitions_16572, kENUMERATION_UP) ;
  while (enumerator_16786.hasCurrentObject ()) {
    {
    routine_arxmlImplementationRoot (ioArgument_imp, enumerator_16786.current_value (HERE), var_currentPath_16342, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 525)) ;
    }
    enumerator_16786.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_16962 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 529)) ;
  GALGAS_stringlist var_packagesPath_16990 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 530)) ;
  var_packagesPath_16990.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 531)) ;
  var_packagesPath_16990.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 532)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_16990, var_packages_16962, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 533)) ;
  cEnumerator_arxmlElementValueList enumerator_17160 (var_packages_16962, kENUMERATION_UP) ;
  while (enumerator_17160.hasCurrentObject ()) {
    {
    routine_arxmlImplementationPackage (ioArgument_imp, enumerator_17160.current_value (HERE), var_currentPath_16342, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 535)) ;
    }
    enumerator_17160.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationRoot'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationRoot (GALGAS_implementation & ioArgument_implementation,
                                      GALGAS_arxmlElementValue inArgument_packageElement,
                                      GALGAS_lstring inArgument_parentPath,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_objectName_17422 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 545)) ;
  {
  routine_displayOil (GALGAS_string ("\nIMPLEMENTATION ").add_operation (var_objectName_17422.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 546)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 546)) ;
  }
  GALGAS_lstring var_currentPath_17581 = GALGAS_lstring::constructor_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 549)).add_operation (var_objectName_17422.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 549)), inArgument_parentPath.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 549)) ;
  GALGAS_lstring var_oil_5F_desc_17787 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_17787, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 553)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_17850 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 556)) ;
  GALGAS_stringlist var_subDefsPath_17877 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 557)) ;
  var_subDefsPath_17877.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 558)) ;
  var_subDefsPath_17877.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 559)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_17877, var_subDefs_17850, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 560)) ;
  {
  routine_displayOil (GALGAS_string ("\n{\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 562)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_18121 (var_subDefs_17850, kENUMERATION_UP) ;
  while (enumerator_18121.hasCurrentObject ()) {
    {
    routine_arxmlImplementationObject (ioArgument_implementation, enumerator_18121.current_value (HERE), var_currentPath_17581, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 566)) ;
    }
    enumerator_18121.gotoNextObject () ;
  }
  {
  routine_displayOil (GALGAS_string ("}; /* END IMPLEMENTATION ").add_operation (var_objectName_17422.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 569)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 569)).add_operation (var_oil_5F_desc_17787.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 570)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 570)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 569)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationObject'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationObject (GALGAS_implementation & ioArgument_implementation,
                                        GALGAS_arxmlElementValue inArgument_packageElement,
                                        GALGAS_lstring inArgument_parentPath,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationMap var_imp_18497 = ioArgument_implementation.readProperty_imp () ;
  GALGAS_implementationObjectMap var_objectAttributes_18551 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 579)) ;
  GALGAS_lstring var_objectName_18713 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 583)) ;
  GALGAS_lstring var_currentPath_18824 = GALGAS_lstring::constructor_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 586)).add_operation (var_objectName_18713.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 586)), inArgument_parentPath.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 586)) ;
  GALGAS_lstring var_objectKind_19073 = var_objectName_18713 ;
  var_objectKind_19073.setter_setString (var_objectName_18713.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 591)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 591)) ;
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (var_objectKind_19073.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 593)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 593)) ;
  }
  GALGAS_lbool var_multiple_19297 ;
  {
  routine_arxmlGetMultiplicity (inArgument_packageElement, var_objectName_18713, var_multiple_19297, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 596)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n  {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 597)) ;
  }
  GALGAS_lstring var_oil_5F_desc_19416 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_19416, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 600)) ;
  }
  {
  routine_arxmlImplementationContainer (var_objectAttributes_18551, inArgument_packageElement, var_currentPath_18824, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 603)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  }; /* \"").add_operation (var_oil_5F_desc_19416.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 607)).add_operation (GALGAS_string ("\"*/\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 607)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 607)) ;
  }
  GALGAS_implementationObject var_newObject_19721 = GALGAS_implementationObject::constructor_new (var_multiple_19297, var_objectAttributes_18551  COMMA_SOURCE_FILE ("arxml_parser.galgas", 611)) ;
  GALGAS_implementationObject var_object_19894 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasKey ((const cPtr_implementation *) ioArgument_implementation.ptr (), var_objectName_18713.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 616)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      var_imp_18497.setter_del (var_objectName_18713, var_object_19894, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 617)) ;
      }
      var_object_19894 = callExtensionGetter_mergeImplementationObjectWith ((const cPtr_implementationObject *) var_object_19894.ptr (), var_newObject_19721, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 618)) ;
    }
  }
  if (kBoolFalse == test_0) {
    var_object_19894 = var_newObject_19721 ;
  }
  {
  var_imp_18497.setter_put (var_objectName_18713, var_object_19894, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 624)) ;
  }
  {
  ioArgument_implementation.setter_setImp (var_imp_18497 COMMA_SOURCE_FILE ("arxml_parser.galgas", 625)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainer'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainer (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                           GALGAS_arxmlElementValue inArgument_currentElement,
                                           GALGAS_lstring inArgument_parentPath,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_intParameters_20546 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 636)) ;
  GALGAS_stringlist var_intParametersPath_20579 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 637)) ;
  var_intParametersPath_20579.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 638)) ;
  var_intParametersPath_20579.addAssign_operation (GALGAS_string ("ECUC-INTEGER-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 639)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_intParametersPath_20579, var_intParameters_20546, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 640)) ;
  cEnumerator_arxmlElementValueList enumerator_20786 (var_intParameters_20546, kENUMERATION_UP) ;
  while (enumerator_20786.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_20834 ;
    GALGAS_impType var_type_20865 ;
    {
    routine_arxmlImplementationContainerNumber (var_attributeName_20834, var_type_20865, GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 647)), enumerator_20786.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 645)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_20834, var_type_20865, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 650)) ;
    }
    enumerator_20786.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_floatParameters_21418 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 656)) ;
  GALGAS_stringlist var_floatParametersPath_21453 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 657)) ;
  var_floatParametersPath_21453.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 658)) ;
  var_floatParametersPath_21453.addAssign_operation (GALGAS_string ("ECUC-FLOAT-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 659)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_floatParametersPath_21453, var_floatParameters_21418, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 660)) ;
  cEnumerator_arxmlElementValueList enumerator_21668 (var_floatParameters_21418, kENUMERATION_UP) ;
  while (enumerator_21668.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_21718 ;
    GALGAS_impType var_type_21749 ;
    {
    routine_arxmlImplementationContainerNumber (var_attributeName_21718, var_type_21749, GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 667)), enumerator_21668.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 665)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_21718, var_type_21749, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 670)) ;
    }
    enumerator_21668.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_stringParameters_22289 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 676)) ;
  GALGAS_stringlist var_stringParametersPath_22325 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 677)) ;
  var_stringParametersPath_22325.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 678)) ;
  var_stringParametersPath_22325.addAssign_operation (GALGAS_string ("ECUC-STRING-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 679)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_stringParametersPath_22325, var_stringParameters_22289, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 680)) ;
  cEnumerator_arxmlElementValueList enumerator_22546 (var_stringParameters_22289, kENUMERATION_UP) ;
  while (enumerator_22546.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_22597 ;
    GALGAS_impType var_type_22628 ;
    {
    routine_arxmlImplementationContainerString (var_attributeName_22597, var_type_22628, GALGAS_dataType::constructor_string (SOURCE_FILE ("arxml_parser.galgas", 687)), enumerator_22546.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 685)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_22597, var_type_22628, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 690)) ;
    }
    enumerator_22546.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_booleanParameters_23164 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 696)) ;
  GALGAS_stringlist var_booleanParametersPath_23201 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 697)) ;
  var_booleanParametersPath_23201.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 698)) ;
  var_booleanParametersPath_23201.addAssign_operation (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 699)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_booleanParametersPath_23201, var_booleanParameters_23164, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 700)) ;
  cEnumerator_arxmlElementValueList enumerator_23428 (var_booleanParameters_23164, kENUMERATION_UP) ;
  while (enumerator_23428.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_23480 ;
    GALGAS_impType var_type_23511 ;
    {
    routine_arxmlImplementationContainerBoolean (var_attributeName_23480, var_type_23511, GALGAS_dataType::constructor_boolean (SOURCE_FILE ("arxml_parser.galgas", 707)), enumerator_23428.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 705)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_23480, var_type_23511, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 710)) ;
    }
    enumerator_23428.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_enumParameters_24050 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 716)) ;
  GALGAS_stringlist var_enumParametersPath_24084 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 717)) ;
  var_enumParametersPath_24084.addAssign_operation (GALGAS_string ("PARAMETERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 718)) ;
  var_enumParametersPath_24084.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 719)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_enumParametersPath_24084, var_enumParameters_24050, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 720)) ;
  cEnumerator_arxmlElementValueList enumerator_24300 (var_enumParameters_24050, kENUMERATION_UP) ;
  while (enumerator_24300.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_24349 ;
    GALGAS_impType var_type_24380 ;
    {
    routine_arxmlImplementationContainerEnumeration (var_attributeName_24349, var_type_24380, GALGAS_dataType::constructor_enumeration (SOURCE_FILE ("arxml_parser.galgas", 727)), enumerator_24300.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 725)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_24349, var_type_24380, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 730)) ;
    }
    enumerator_24300.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_structParameters_24945 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 736)) ;
  GALGAS_stringlist var_structParametersPath_24981 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 737)) ;
  var_structParametersPath_24981.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 738)) ;
  var_structParametersPath_24981.addAssign_operation (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 739)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_24981, var_structParameters_24945, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 740)) ;
  cEnumerator_arxmlElementValueList enumerator_25214 (var_structParameters_24945, kENUMERATION_UP) ;
  while (enumerator_25214.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_25265 ;
    GALGAS_impType var_type_25296 ;
    {
    routine_arxmlImplementationContainerStructure (var_attributeName_25265, var_type_25296, GALGAS_dataType::constructor_structType (SOURCE_FILE ("arxml_parser.galgas", 747)), enumerator_25214.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 745)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_25265, var_type_25296, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 750)) ;
    }
    enumerator_25214.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_identParameters_25854 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 756)) ;
  GALGAS_stringlist var_identParametersPath_25889 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 757)) ;
  var_identParametersPath_25889.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 758)) ;
  var_identParametersPath_25889.addAssign_operation (GALGAS_string ("TPL-IDENTIFIER-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 759)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_identParametersPath_25889, var_identParameters_25854, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 760)) ;
  cEnumerator_arxmlElementValueList enumerator_26102 (var_identParameters_25854, kENUMERATION_UP) ;
  while (enumerator_26102.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_26152 ;
    GALGAS_impType var_type_26183 ;
    {
    routine_arxmlImplementationContainerIdentifier (var_attributeName_26152, var_type_26183, GALGAS_dataType::constructor_identifier (SOURCE_FILE ("arxml_parser.galgas", 767)), enumerator_26102.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 765)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_26152, var_type_26183, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 770)) ;
    }
    enumerator_26102.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_refParameters_26745 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 776)) ;
  GALGAS_stringlist var_refParametersPath_26778 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 777)) ;
  var_refParametersPath_26778.addAssign_operation (GALGAS_string ("REFERENCES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 778)) ;
  var_refParametersPath_26778.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 779)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_26778, var_refParameters_26745, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 780)) ;
  cEnumerator_arxmlElementValueList enumerator_26981 (var_refParameters_26745, kENUMERATION_UP) ;
  while (enumerator_26981.hasCurrentObject ()) {
    GALGAS_lstring var_attributeName_27029 ;
    GALGAS_impType var_type_27060 ;
    {
    routine_arxmlImplementationContainerReference (var_attributeName_27029, var_type_27060, GALGAS_dataType::constructor_objectType (SOURCE_FILE ("arxml_parser.galgas", 787)), enumerator_26981.current_value (HERE), inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 785)) ;
    }
    {
    routine_arxmlInsertObjectAttribute (ioArgument_objectAttributes, var_attributeName_27029, var_type_27060, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 790)) ;
    }
    enumerator_26981.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerNumber'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerNumber (GALGAS_lstring & outArgument_objectName,
                                                 GALGAS_impType & outArgument_options,
                                                 const GALGAS_dataType constinArgument_iType,
                                                 GALGAS_arxmlElementValue inArgument_parameter,
                                                 GALGAS_lstring /* inArgument_parentPath */,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_dataType var_type_27685 = constinArgument_iType ;
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 806)) ;
  }
  GALGAS_lbool var_multiple_27839 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_27839, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 809)) ;
  }
  GALGAS_bool var_withAuto_27905 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_27905, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 812)) ;
  }
  GALGAS_lstring var_oil_5F_desc_27994 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_27994, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 815)) ;
  }
  GALGAS_attributeRange var_range_28151 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 821)) ;
    if (kBoolTrue == test_1.boolEnum ()) {
      test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 821)) ;
    }
    test_0 = test_1.boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_min_28243 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MIN"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 822)) ;
      GALGAS_lstring var_max_28300 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("MAX"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 823)) ;
      GALGAS_string var_minSignString_28356 = GALGAS_string::makeEmptyString () ;
      GALGAS_string var_maxSignString_28387 = GALGAS_string::makeEmptyString () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, var_max_28300.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 827)).objectCompare (GALGAS_string ("INF"))).boolEnum () ;
        if (kBoolTrue == test_2) {
          var_max_28300.setter_setString (GALGAS_sint_36__34_::constructor_max (SOURCE_FILE ("arxml_parser.galgas", 828)).getter_string (SOURCE_FILE ("arxml_parser.galgas", 828)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 828)) ;
        }
      }
      GALGAS_bool var_minSign_28542 ;
      {
      routine_arxmlPopSign (var_min_28243, var_minSign_28542, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 831)) ;
      }
      GALGAS_bool var_maxSign_28585 ;
      {
      routine_arxmlPopSign (var_max_28300, var_maxSign_28585, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 832)) ;
      }
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = var_minSign_28542.boolEnum () ;
        if (kBoolTrue == test_3) {
          var_minSignString_28356 = GALGAS_string ("-") ;
          var_type_27685 = GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 837)) ;
        }
      }
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = var_maxSign_28585.boolEnum () ;
        if (kBoolTrue == test_4) {
          var_maxSignString_28387 = GALGAS_string ("-") ;
          var_type_27685 = GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 841)) ;
        }
      }
      {
      routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27685, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 843)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 843)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 843)) ;
      }
      {
      routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 844)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 844)) ;
      }
      GALGAS_object_5F_t var_start_28934 ;
      GALGAS_object_5F_t var_stop_28958 ;
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        GALGAS_bool test_6 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 849)))) ;
        if (kBoolTrue != test_6.boolEnum ()) {
          test_6 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 849)))) ;
        }
        test_5 = test_6.boolEnum () ;
        if (kBoolTrue == test_5) {
          GALGAS_luint_36__34_ var_minVal_29060 = GALGAS_luint_36__34_::constructor_new (var_min_28243.readProperty_string ().getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 851)), var_min_28243.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 850)) ;
          GALGAS_luint_36__34_ var_maxVal_29242 = GALGAS_luint_36__34_::constructor_new (var_max_28300.readProperty_string ().getter_decimalUnsigned_36__34_Number (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 855)), var_max_28300.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 854)) ;
          {
          routine_displayOil (GALGAS_string ("[").add_operation (var_minSignString_28356, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)).add_operation (var_minVal_29060.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 858)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)).add_operation (var_maxSignString_28387, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)).add_operation (var_maxVal_29242.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 859)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 859)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 858)) ;
          }
          var_start_28934 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 860)), var_type_27685, var_minVal_29060, var_minSign_28542, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 860)) ;
          var_stop_28958 = function_checkAndGetIntegerNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 861)), var_type_27685, var_maxVal_29242, var_maxSign_28585, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 861)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 862)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            GALGAS_ldouble var_minVal_29748 = GALGAS_ldouble::constructor_new (var_min_28243.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 864)), var_min_28243.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 863)) ;
            GALGAS_ldouble var_maxVal_29919 = GALGAS_ldouble::constructor_new (var_max_28300.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 868)), var_max_28300.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 867)) ;
            {
            routine_displayOil (GALGAS_string ("[").add_operation (var_minVal_29748.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 871)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)).add_operation (GALGAS_string (" .. "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)).add_operation (var_maxVal_29919.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 871)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 871)) ;
            }
            var_start_28934 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 872)), var_type_27685, var_minVal_29748, var_minSign_28542, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 872)) ;
            var_stop_28958 = function_checkAndGetFloatNumber (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 873)), var_type_27685, var_maxVal_29919, var_maxSign_28585, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 873)) ;
          }
        }
        if (kBoolFalse == test_7) {
          TC_Array <C_FixItDescription> fixItArray8 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 875)), GALGAS_string ("Internal error"), fixItArray8  COMMA_SOURCE_FILE ("arxml_parser.galgas", 875)) ;
          var_start_28934.drop () ; // Release error dropped variable
          var_stop_28958.drop () ; // Release error dropped variable
        }
      }
      var_range_28151 = function_buildRange (var_type_27685, var_start_28934, var_stop_28958, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 877)) ;
    }
  }
  if (kBoolFalse == test_0) {
    {
    routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (var_type_27685, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 879)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 879)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 879)) ;
    }
    {
    routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 880)) ;
    }
    var_range_28151 = GALGAS_noRange::constructor_new (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 881)) ;
  }
  GALGAS_object_5F_t var_defaultValue_30590 ;
  enumGalgasBool test_9 = kBoolTrue ;
  if (kBoolTrue == test_9) {
    test_9 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 886)).boolEnum () ;
    if (kBoolTrue == test_9) {
      GALGAS_lstring var_value_30666 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 887)) ;
      GALGAS_bool var_sign_30788 ;
      {
      routine_arxmlPopSign (var_value_30666, var_sign_30788, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 890)) ;
      }
      enumGalgasBool test_10 = kBoolTrue ;
      if (kBoolTrue == test_10) {
        GALGAS_bool test_11 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 893)))) ;
        if (kBoolTrue != test_11.boolEnum ()) {
          test_11 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("arxml_parser.galgas", 893)))) ;
        }
        test_10 = test_11.boolEnum () ;
        if (kBoolTrue == test_10) {
          GALGAS_luint_36__34_ var_integerValue_30962 = GALGAS_luint_36__34_::constructor_new (var_value_30666.readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 895)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 895)), var_value_30666.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 894)) ;
          {
          routine_displayOil (GALGAS_string (" = ").add_operation (var_integerValue_30962.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 897)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 897)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 897)) ;
          }
          var_defaultValue_30590 = function_checkAndGetIntegerNumber (var_oil_5F_desc_27994, var_type_27685, var_integerValue_30962, var_sign_30788, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 898)) ;
        }
      }
      if (kBoolFalse == test_10) {
        enumGalgasBool test_12 = kBoolTrue ;
        if (kBoolTrue == test_12) {
          test_12 = GALGAS_bool (kIsEqual, var_type_27685.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("arxml_parser.galgas", 902)))).boolEnum () ;
          if (kBoolTrue == test_12) {
            GALGAS_ldouble var_floatValue_31443 = GALGAS_ldouble::constructor_new (var_value_30666.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 904)), var_value_30666.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 903)) ;
            {
            routine_displayOil (GALGAS_string (" = ").add_operation (var_floatValue_31443.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 906)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 906)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 906)) ;
            }
            var_defaultValue_30590 = function_checkAndGetFloatNumber (var_oil_5F_desc_27994, var_type_27685, var_floatValue_31443, var_sign_30788, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 907)) ;
          }
        }
        if (kBoolFalse == test_12) {
          TC_Array <C_FixItDescription> fixItArray13 ;
          inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 912)), GALGAS_string ("Internal error"), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 912)) ;
          var_defaultValue_30590.drop () ; // Release error dropped variable
        }
      }
    }
  }
  if (kBoolFalse == test_9) {
    enumGalgasBool test_14 = kBoolTrue ;
    if (kBoolTrue == test_14) {
      test_14 = var_withAuto_27905.boolEnum () ;
      if (kBoolTrue == test_14) {
        var_defaultValue_30590 = GALGAS_auto::constructor_new (var_oil_5F_desc_27994, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 915)) ;
      }
    }
    if (kBoolFalse == test_14) {
      var_defaultValue_30590 = GALGAS_void::constructor_new (var_oil_5F_desc_27994, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 917)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_27994.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 919)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 919)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 919)) ;
  }
  GALGAS_locationList temp_15 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 922)) ;
  temp_15.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 922)) ;
  GALGAS_lstringlist temp_16 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 926)) ;
  temp_16.addAssign_operation (var_oil_5F_desc_27994  COMMA_SOURCE_FILE ("arxml_parser.galgas", 926)) ;
  outArgument_options = GALGAS_impRangedType::constructor_new (temp_15, var_type_27685, outArgument_objectName, var_multiple_27839.readProperty_bool (), temp_16, var_withAuto_27905, var_defaultValue_30590, var_range_28151  COMMA_SOURCE_FILE ("arxml_parser.galgas", 922)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerString'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerString (GALGAS_lstring & outArgument_objectName,
                                                 GALGAS_impType & outArgument_options,
                                                 const GALGAS_dataType constinArgument_type,
                                                 GALGAS_arxmlElementValue inArgument_parameter,
                                                 GALGAS_lstring /* inArgument_parentPath */,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 939)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 939)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 939)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 942)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 943)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 943)) ;
  }
  GALGAS_lbool var_multiple_32874 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_32874, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 946)) ;
  }
  GALGAS_bool var_withAuto_32940 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_32940, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 949)) ;
  }
  GALGAS_lstring var_oil_5F_desc_33029 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_33029, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 952)) ;
  }
  GALGAS_object_5F_t var_defaultValue_33075 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 957)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_33155 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 958)) ;
      {
      routine_displayOil (GALGAS_string (" = \"").add_operation (var_value_33155.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 959)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 959)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 959)) ;
      }
      var_defaultValue_33075 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_33029, var_value_33155.readProperty_location (), var_value_33155.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 960)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_32940.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_33075 = GALGAS_auto::constructor_new (var_oil_5F_desc_33029, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 966)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_33075 = GALGAS_void::constructor_new (var_oil_5F_desc_33029, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 968)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_33029.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 970)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 970)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 970)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 974)) ;
  temp_2.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 974)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 978)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_33029  COMMA_SOURCE_FILE ("arxml_parser.galgas", 978)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_32874.readProperty_bool (), temp_3, var_withAuto_32940, var_defaultValue_33075  COMMA_SOURCE_FILE ("arxml_parser.galgas", 973)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerBoolean'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerBoolean (GALGAS_lstring & outArgument_objectName,
                                                  GALGAS_impType & outArgument_options,
                                                  const GALGAS_dataType constinArgument_type,
                                                  GALGAS_arxmlElementValue inArgument_parameter,
                                                  GALGAS_lstring inArgument_parentPath,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 991)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 991)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 991)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 994)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 995)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 995)) ;
  }
  GALGAS_bool var_withAuto_34510 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_34510, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 998)) ;
  }
  GALGAS_lbool var_multiple_34604 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_34604, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1001)) ;
  }
  GALGAS_lstring var_oil_5F_desc_34693 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_34693, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1004)) ;
  }
  GALGAS_object_5F_t var_defaultValue_34738 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1008)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_34818 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1009)) ;
      GALGAS_bool var_booleanValue_34888 ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_value_34818.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1011)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_value_34818.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          var_booleanValue_34888 = GALGAS_bool (true) ;
        }
      }
      if (kBoolFalse == test_1) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          GALGAS_bool test_4 = GALGAS_bool (kIsEqual, var_value_34818.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1014)).objectCompare (GALGAS_string ("FALSE"))) ;
          if (kBoolTrue != test_4.boolEnum ()) {
            test_4 = GALGAS_bool (kIsEqual, var_value_34818.readProperty_string ().objectCompare (GALGAS_string ("0"))) ;
          }
          test_3 = test_4.boolEnum () ;
          if (kBoolTrue == test_3) {
            var_booleanValue_34888 = GALGAS_bool (false) ;
          }
        }
        if (kBoolFalse == test_3) {
          var_booleanValue_34888 = GALGAS_bool (false) ;
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (var_value_34818.readProperty_location (), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1019)) ;
        }
      }
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_booleanValue_34888.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1021)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1021)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1021)) ;
      }
      var_defaultValue_34738 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_34693, var_value_34818.readProperty_location (), var_booleanValue_34888, GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1028))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1026))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1022)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_6 = kBoolTrue ;
    if (kBoolTrue == test_6) {
      test_6 = var_withAuto_34510.boolEnum () ;
      if (kBoolTrue == test_6) {
        var_defaultValue_34738 = GALGAS_auto::constructor_new (var_oil_5F_desc_34693, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1032)) ;
      }
    }
    if (kBoolFalse == test_6) {
      var_defaultValue_34738 = GALGAS_void::constructor_new (var_oil_5F_desc_34693, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1034)) ;
    }
  }
  GALGAS_implementationObjectMap var_structAttributes_36004 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1040)) ;
  enumGalgasBool test_7 = kBoolTrue ;
  if (kBoolTrue == test_7) {
    test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SUB-CONTAINERS"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1041)).boolEnum () ;
    if (kBoolTrue == test_7) {
      {
      routine_displayOil (GALGAS_string ("\n    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1042)) ;
      }
      {
      routine_arxmlImplementationContainer (var_structAttributes_36004, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1043)) ;
      }
      {
      routine_displayOil (GALGAS_string ("\n    } : \"").add_operation (var_oil_5F_desc_34693.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1044)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1044)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1044)) ;
      }
    }
  }
  if (kBoolFalse == test_7) {
    {
    routine_displayOil (GALGAS_string (" : \"").add_operation (var_oil_5F_desc_34693.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1046)) ;
    }
  }
  GALGAS_locationList temp_8 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1051)) ;
  temp_8.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1051)) ;
  GALGAS_lstringlist temp_9 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1055)) ;
  temp_9.addAssign_operation (var_oil_5F_desc_34693  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1055)) ;
  outArgument_options = GALGAS_impBoolType::constructor_new (temp_8, constinArgument_type, outArgument_objectName, var_multiple_34604.readProperty_bool (), temp_9, var_withAuto_34510, var_defaultValue_34738, var_structAttributes_36004, var_structAttributes_36004  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1050)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerEnumeration'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerEnumeration (GALGAS_lstring & outArgument_objectName,
                                                      GALGAS_impType & outArgument_options,
                                                      const GALGAS_dataType constinArgument_type,
                                                      GALGAS_arxmlElementValue inArgument_parameter,
                                                      GALGAS_lstring /* inArgument_parentPath */,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1070)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1070)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1070)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1073)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1074)).add_operation (GALGAS_string ("["), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1074)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1074)) ;
  }
  GALGAS_bool var_withAuto_37173 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_37173, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1077)) ;
  }
  GALGAS_lbool var_multiple_37267 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_37267, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1080)) ;
  }
  GALGAS_lstring var_oil_5F_desc_37356 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_37356, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1083)) ;
  }
  GALGAS_enumValues var_enumValues_37446 = GALGAS_enumValues::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1087)) ;
  GALGAS_arxmlElementValueList var_enumElementValues_37507 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1088)) ;
  GALGAS_stringlist var_enumElementValuesPath_37544 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1089)) ;
  var_enumElementValuesPath_37544.addAssign_operation (GALGAS_string ("LITERALS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1090)) ;
  var_enumElementValuesPath_37544.addAssign_operation (GALGAS_string ("ECUC-ENUMERATION-LITERAL-DEF")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1091)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_parameter.ptr (), var_enumElementValuesPath_37544, var_enumElementValues_37507, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1092)) ;
  cEnumerator_arxmlElementValueList enumerator_37770 (var_enumElementValues_37507, kENUMERATION_UP) ;
  while (enumerator_37770.hasCurrentObject ()) {
    GALGAS_lstring var_enumValueName_37822 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) enumerator_37770.current_value (HERE).ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1094)) ;
    {
    var_enumValues_37446.setter_put (var_enumValueName_37822, GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1095)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1095)) ;
    }
    {
    routine_displayOil (var_enumValueName_37822.readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1096)) ;
    }
    if (enumerator_37770.hasNextObject ()) {
      {
      routine_displayOil (GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1098)) ;
      }
    }
    enumerator_37770.gotoNextObject () ;
  }
  {
  routine_displayOil (GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1100)) ;
  }
  GALGAS_object_5F_t var_defaultValue_38090 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1104)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_38170 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1105)) ;
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_value_38170.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1106)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1106)) ;
      }
      var_defaultValue_38090 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_37356, var_value_38170.readProperty_location (), var_value_38170.readProperty_string (), GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1113))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1111))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1107)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_37173.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_38090 = GALGAS_auto::constructor_new (var_oil_5F_desc_37356, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1117)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_38090 = GALGAS_void::constructor_new (var_oil_5F_desc_37356, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1119)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string ("\n : \"").add_operation (var_oil_5F_desc_37356.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1122)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1126)) ;
  temp_2.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1126)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1130)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_37356  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1130)) ;
  outArgument_options = GALGAS_impEnumType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_37267.readProperty_bool (), temp_3, var_withAuto_37173, var_defaultValue_38090, var_enumValues_37446  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1125)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerStructure'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerStructure (GALGAS_lstring & outArgument_objectName,
                                                    GALGAS_impType & outArgument_options,
                                                    const GALGAS_dataType constinArgument_type,
                                                    GALGAS_arxmlElementValue inArgument_parameter,
                                                    GALGAS_lstring inArgument_parentPath,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1145)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1145)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1145)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1148)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1149)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1149)) ;
  }
  GALGAS_lbool var_multiple_39724 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_39724, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1152)) ;
  }
  GALGAS_lstring var_oil_5F_desc_39813 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_39813, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1155)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1157)) ;
  }
  GALGAS_implementationObjectMap var_structAttributes_39880 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1160)) ;
  {
  routine_arxmlImplementationContainer (var_structAttributes_39880, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1161)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n    } : \"").add_operation (var_oil_5F_desc_39813.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1163)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1163)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1163)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1167)) ;
  temp_0.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1167)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1171)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_39813  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1171)) ;
  outArgument_options = GALGAS_impStructType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_39724.readProperty_bool (), temp_1, var_structAttributes_39880  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1166)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerIdentifier'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerIdentifier (GALGAS_lstring & outArgument_objectName,
                                                     GALGAS_impType & outArgument_options,
                                                     const GALGAS_dataType constinArgument_type,
                                                     GALGAS_arxmlElementValue inArgument_parameter,
                                                     GALGAS_lstring /* inArgument_parentPath */,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1183)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1183)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1183)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1186)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1187)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1187)) ;
  }
  GALGAS_lbool var_multiple_40815 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_40815, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1190)) ;
  }
  GALGAS_bool var_withAuto_40881 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_40881, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1193)) ;
  }
  GALGAS_lstring var_oil_5F_desc_40970 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_40970, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1196)) ;
  }
  GALGAS_object_5F_t var_defaultValue_41015 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1200)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_value_41095 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1201)) ;
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_value_41095.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1202)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1202)) ;
      }
      var_defaultValue_41015 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_40970, var_value_41095.readProperty_location (), var_value_41095.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1203)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_withAuto_40881.boolEnum () ;
      if (kBoolTrue == test_1) {
        var_defaultValue_41015 = GALGAS_auto::constructor_new (var_oil_5F_desc_40970, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1209)) ;
      }
    }
    if (kBoolFalse == test_1) {
      var_defaultValue_41015 = GALGAS_void::constructor_new (var_oil_5F_desc_40970, outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1211)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_40970.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1213)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1213)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1213)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1217)) ;
  temp_2.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1217)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1221)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_40970  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1221)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_40815.readProperty_bool (), temp_3, var_withAuto_40881, var_defaultValue_41015  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1216)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlImplementationContainerReference'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlImplementationContainerReference (GALGAS_lstring & outArgument_objectName,
                                                    GALGAS_impType & outArgument_options,
                                                    const GALGAS_dataType constinArgument_type,
                                                    GALGAS_arxmlElementValue inArgument_parameter,
                                                    GALGAS_lstring /* inArgument_parentPath */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_lstring var_objectType_42284 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DESTINATION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1235)) ;
  var_objectType_42284.setter_setString (var_objectType_42284.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1237)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1237)) ;
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_objectType_42284.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1238)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1238)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1241)) ;
  }
  {
  routine_displayOil (GALGAS_string (" ").add_operation (outArgument_objectName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1242)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1242)) ;
  }
  GALGAS_lbool var_multiple_42708 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_42708, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1245)) ;
  }
  GALGAS_lstring var_oil_5F_desc_42797 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_42797, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1248)) ;
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_42797.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1254)) ;
  temp_0.addAssign_operation (outArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1254)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1258)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_42797  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1258)) ;
  outArgument_options = GALGAS_refType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_42708.readProperty_bool (), temp_1, var_objectType_42284  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1253)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionPackage'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionPackage (GALGAS_implementation & ioArgument_imp,
                                     GALGAS_applicationDefinition & ioArgument_application,
                                     GALGAS_arxmlElementValue inArgument_packageElement,
                                     GALGAS_lstring inArgument_parentPath,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_43450 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1274)) ;
  GALGAS_lstring var_currentPath_43563 = GALGAS_lstring::constructor_new (inArgument_parentPath.readProperty_string ().add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1277)).add_operation (var_packageName_43450.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1277)), var_packageName_43450.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1277)) ;
  GALGAS_arxmlElementValueList var_definitions_43790 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1281)) ;
  GALGAS_stringlist var_definitionPath_43821 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1282)) ;
  var_definitionPath_43821.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1283)) ;
  var_definitionPath_43821.addAssign_operation (GALGAS_string ("ECUC-MODULE-CONFIGURATION-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1284)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_43821, var_definitions_43790, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1285)) ;
  cEnumerator_arxmlElementValueList enumerator_44021 (var_definitions_43790, kENUMERATION_UP) ;
  while (enumerator_44021.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionRoot (ioArgument_imp, ioArgument_application, enumerator_44021.current_value (HERE), var_currentPath_43563, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1287)) ;
    }
    enumerator_44021.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_44207 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1291)) ;
  GALGAS_stringlist var_packagesPath_44235 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1292)) ;
  var_packagesPath_44235.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1293)) ;
  var_packagesPath_44235.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1294)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_44235, var_packages_44207, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1295)) ;
  cEnumerator_arxmlElementValueList enumerator_44405 (var_packages_44207, kENUMERATION_UP) ;
  while (enumerator_44405.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage (ioArgument_imp, ioArgument_application, enumerator_44405.current_value (HERE), var_currentPath_43563, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1297)) ;
    }
    enumerator_44405.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionRoot'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionRoot (GALGAS_implementation & ioArgument_imp,
                                  GALGAS_applicationDefinition & ioArgument_application,
                                  GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring /* inArgument_parentPath */,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_cpuName_44697 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1308)) ;
  GALGAS_lstring var_currentPath_44807 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1311)) ;
  GALGAS_objectsMap var_objects_44926 = ioArgument_application.readProperty_objects () ;
  GALGAS_lstring var_oil_5F_desc_45042 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_45042, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1317)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_45105 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1320)) ;
  GALGAS_stringlist var_subDefsPath_45132 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1321)) ;
  var_subDefsPath_45132.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1322)) ;
  var_subDefsPath_45132.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1323)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_45132, var_subDefs_45105, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1324)) ;
  {
  routine_displayOil (GALGAS_string ("\nCPU ").add_operation (var_cpuName_44697.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1326)).add_operation (GALGAS_string ("\n{\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1326)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1326)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_45352 (var_subDefs_45105, kENUMERATION_UP) ;
  while (enumerator_45352.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionObject (ioArgument_imp, var_objects_44926, enumerator_45352.current_value (HERE), var_currentPath_44807, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1329)) ;
    }
    enumerator_45352.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setName (var_cpuName_44697 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1333)) ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_44926 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1334)) ;
  }
  {
  routine_displayOil (GALGAS_string ("}; /* END CPU ").add_operation (var_cpuName_44697.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1336)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1336)).add_operation (var_oil_5F_desc_45042.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1337)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1337)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1336)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionObject'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionObject (GALGAS_implementation & ioArgument_imp,
                                    GALGAS_objectsMap & ioArgument_objects,
                                    GALGAS_arxmlElementValue inArgument_currentElement,
                                    GALGAS_lstring inArgument_parentPath,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_currentPath_45842 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1347)) ;
  GALGAS_lstring var_objectKind_45969 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_currentPath_45842, var_objectKind_45969, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1348)) ;
  }
  GALGAS_implementationObject var_impObjOfKind_46032 = callExtensionGetter_impObject ((const cPtr_implementation *) ioArgument_imp.ptr (), var_objectKind_45969.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1351)) ;
  GALGAS_objectKind var_objectsForKind_46098 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1352))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1352)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objects.getter_hasKey (var_objectKind_45969.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1353)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioArgument_objects.setter_del (var_objectKind_45969, var_objectsForKind_46098, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1354)) ;
      }
    }
  }
  GALGAS_lstring var_objectName_46295 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1358)) ;
  GALGAS_objectAttributes var_object_46411 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1361)) ;
  GALGAS_objectKindMap var_objectsKind_46451 = var_objectsForKind_46098.readProperty_objects () ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_impObjOfKind_46032.readProperty_multiple ().readProperty_bool ().objectCompare (GALGAS_bool (false))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_objectName_46295 = var_objectKind_45969 ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = var_objectsKind_46451.getter_hasKey (var_objectName_46295.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1371)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      var_objectsKind_46451.setter_del (var_objectName_46295, var_object_46411, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1372)) ;
      }
    }
  }
  GALGAS_lstring var_oil_5F_desc_47020 ;
  {
  routine_arxmlGetDescription (inArgument_currentElement, var_oil_5F_desc_47020, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1376)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (var_objectKind_45969.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)).add_operation (var_objectName_46295.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)).add_operation (GALGAS_string ("\n  {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1378)) ;
  }
  {
  routine_arxmlDefinitionContainer (var_impObjOfKind_46032.readProperty_attributes (), var_object_46411, inArgument_currentElement, var_currentPath_45842, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1381)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  } : \"").add_operation (var_oil_5F_desc_47020.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)) ;
  }
  GALGAS_identifierMap var_attributes_47413 = var_object_46411.readProperty_objectParams () ;
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = var_attributes_47413.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("arxml_parser.galgas", 1390)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 1390)).boolEnum () ;
    if (kBoolTrue == test_3) {
      {
      var_attributes_47413.setter_put (GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), var_objectName_46295.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)), GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_47020, var_objectName_46295.readProperty_location (), var_objectName_46295.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1392)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)) ;
      }
      {
      var_object_46411.setter_setObjectParams (var_attributes_47413 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1395)) ;
      }
    }
  }
  {
  var_objectsKind_46451.setter_put (var_objectName_46295, var_object_46411, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1397)) ;
  }
  {
  var_objectsForKind_46098.setter_setObjects (var_objectsKind_46451 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1398)) ;
  }
  {
  ioArgument_objects.setter_put (var_objectKind_45969, var_objectsForKind_46098, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1399)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionContainer'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionContainer (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_currentElement,
                                       GALGAS_lstring inArgument_currentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_textParameters_48205 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1409)) ;
  GALGAS_stringlist var_textParametersPath_48239 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1410)) ;
  var_textParametersPath_48239.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1411)) ;
  var_textParametersPath_48239.addAssign_operation (GALGAS_string ("ECUC-TEXTUAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1412)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_textParametersPath_48239, var_textParameters_48205, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1413)) ;
  GALGAS_arxmlElementValueList var_numParameters_48524 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1416)) ;
  GALGAS_stringlist var_numParametersPath_48557 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1417)) ;
  var_numParametersPath_48557.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1418)) ;
  var_numParametersPath_48557.addAssign_operation (GALGAS_string ("ECUC-NUMERICAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1419)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_numParametersPath_48557, var_numParameters_48524, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1420)) ;
  GALGAS_arxmlElementValueList var_refParameters_48810 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1423)) ;
  GALGAS_stringlist var_refParametersPath_48843 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1424)) ;
  var_refParametersPath_48843.addAssign_operation (GALGAS_string ("REFERENCE-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1425)) ;
  var_refParametersPath_48843.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1426)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_48843, var_refParameters_48810, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1427)) ;
  GALGAS_arxmlElementValueList var_structParameters_49090 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1430)) ;
  GALGAS_stringlist var_structParametersPath_49126 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1431)) ;
  var_structParametersPath_49126.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1432)) ;
  var_structParametersPath_49126.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1433)) ;
  callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_49126, var_structParameters_49090, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1434)) ;
  GALGAS_arxmlElementValueList var_allParameters_49380 = var_numParameters_48524.add_operation (var_textParameters_48205, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1437)).add_operation (var_refParameters_48810, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1438)).add_operation (var_structParameters_49090, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1439)) ;
  cEnumerator_arxmlElementValueList enumerator_49644 (var_allParameters_49380, kENUMERATION_UP) ;
  while (enumerator_49644.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionParameter (constinArgument_types, ioArgument_identifiers, enumerator_49644.current_value (HERE), inArgument_currentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1444)) ;
    }
    enumerator_49644.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlDefinitionParameter'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlDefinitionParameter (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_parameter,
                                       GALGAS_lstring inArgument_parentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t var_val_49953 ;
  GALGAS_lstring var_parameterPath_49972 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1456)) ;
  GALGAS_lstring var_parameterType_50094 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_parameterPath_49972, var_parameterType_50094, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1457)) ;
  }
  GALGAS_bool var_typeOk_50142 = GALGAS_bool (false) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  GALGAS_impType var_type_50168 = GALGAS_impVoid::constructor_new (temp_0, GALGAS_dataType::constructor_void (SOURCE_FILE ("arxml_parser.galgas", 1463)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1463)), GALGAS_bool (false), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1465))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  GALGAS_lstring var_valueType_50439 = callExtensionGetter_getAttributeValueFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), GALGAS_string ("DEST"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1467)) ;
  GALGAS_lstring var_oil_5F_desc_50633 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1472))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1472)) ;
  GALGAS_bool var_isAuto_50791 = GALGAS_bool (false) ;
  GALGAS_lstring var_parameterValue_50817 ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1479)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_parameterValue_50817 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1483)) ;
    }
  }
  if (kBoolFalse == test_1) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1484)).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_parameterValue_50817 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1488)) ;
        var_parameterValue_50817.setter_setString (var_parameterValue_50817.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1490)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1490)) ;
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = GALGAS_bool (kIsEqual, var_parameterType_50094.readProperty_string ().getter_rightSubString (GALGAS_uint (uint32_t (3U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1492)).objectCompare (GALGAS_string ("REF"))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_parameterType_50094.setter_setString (var_parameterType_50094.readProperty_string ().getter_leftSubString (var_parameterType_50094.readProperty_string ().getter_count (SOURCE_FILE ("arxml_parser.galgas", 1494)).substract_operation (GALGAS_uint (uint32_t (3U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1494)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1493)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1493)) ;
          }
        }
        if (kBoolFalse == test_3) {
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, var_parameterType_50094.readProperty_string ().getter_rightSubString (GALGAS_uint (uint32_t (4U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1495)).objectCompare (GALGAS_string ("REFS"))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_parameterType_50094.setter_setString (var_parameterType_50094.readProperty_string ().getter_leftSubString (var_parameterType_50094.readProperty_string ().getter_count (SOURCE_FILE ("arxml_parser.galgas", 1497)).substract_operation (GALGAS_uint (uint32_t (4U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1497)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1496)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1496)) ;
            }
          }
          if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (var_parameterType_50094.readProperty_location (), GALGAS_string ("An object reference must end with REF or REFS"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1499)) ;
          }
        }
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_6 = kBoolTrue ;
      if (kBoolTrue == test_6) {
        GALGAS_bool test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("PARAMETER-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1501)) ;
        if (kBoolTrue != test_7.boolEnum ()) {
          test_7 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("REFERENCE-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1502)) ;
        }
        test_6 = test_7.boolEnum () ;
        if (kBoolTrue == test_6) {
          var_parameterValue_50817 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1506)) ;
        }
      }
      if (kBoolFalse == test_6) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1507)).boolEnum () ;
          if (kBoolTrue == test_8) {
            var_parameterValue_50817 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1511)) ;
            enumGalgasBool test_9 = kBoolTrue ;
            if (kBoolTrue == test_9) {
              GALGAS_bool test_10 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1512)).objectCompare (GALGAS_string ("TRUE"))) ;
              if (kBoolTrue != test_10.boolEnum ()) {
                test_10 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
              }
              test_9 = test_10.boolEnum () ;
              if (kBoolTrue == test_9) {
                var_isAuto_50791 = GALGAS_bool (true) ;
              }
            }
          }
        }
        if (kBoolFalse == test_8) {
          TC_Array <C_FixItDescription> fixItArray11 ;
          inCompiler->emitSemanticError (var_parameterType_50094.readProperty_location (), GALGAS_string ("No value has been found."), fixItArray11  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1517)) ;
          var_parameterValue_50817.drop () ; // Release error dropped variable
        }
      }
    }
  }
  enumGalgasBool test_12 = kBoolTrue ;
  if (kBoolTrue == test_12) {
    test_12 = constinArgument_types.getter_hasKey (var_parameterType_50094.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1521)).boolEnum () ;
    if (kBoolTrue == test_12) {
      constinArgument_types.method_get (var_parameterType_50094, var_type_50168, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1522)) ;
      var_typeOk_50142 = GALGAS_bool (true) ;
      {
      routine_testTypeError (var_type_50168.readProperty_type (), var_valueType_50439, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1525)) ;
      }
    }
  }
  if (kBoolFalse == test_12) {
    TC_Array <C_FixItDescription> fixItArray13 ;
    inCompiler->emitSemanticError (var_parameterType_50094.readProperty_location (), var_parameterType_50094.readProperty_string ().add_operation (GALGAS_string (" is not declared in the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)).add_operation (GALGAS_string ("IMPLEMENTATION."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)) ;
  }
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_parameterType_50094.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1531)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1531)) ;
  }
  GALGAS_implementationObjectMap var_subTypes_53409 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1533)) ;
  GALGAS_objectAttributes var_subAttributes_53477 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1534)) ;
  enumGalgasBool test_14 = kBoolTrue ;
  if (kBoolTrue == test_14) {
    test_14 = var_isAuto_50791.boolEnum () ;
    if (kBoolTrue == test_14) {
      {
      routine_displayOil (GALGAS_string (" = AUTO;"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1543)) ;
      }
      enumGalgasBool test_15 = kBoolTrue ;
      if (kBoolTrue == test_15) {
        test_15 = callExtensionGetter_autoAllowed ((const cPtr_impType *) var_type_50168.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1544)).boolEnum () ;
        if (kBoolTrue == test_15) {
          var_val_49953 = GALGAS_auto::constructor_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1545)) ;
        }
      }
      if (kBoolFalse == test_15) {
        TC_Array <C_FixItDescription> fixItArray16 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1547)), GALGAS_string ("AUTO is not allowed"), fixItArray16  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1547)) ;
        var_val_49953.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_14) {
    enumGalgasBool test_17 = kBoolTrue ;
    if (kBoolTrue == test_17) {
      test_17 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF"))).boolEnum () ;
      if (kBoolTrue == test_17) {
        GALGAS_impEnumType temp_18 ;
        if (var_type_50168.isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_impEnumType *> (var_type_50168.ptr ())) {
            temp_18 = (cPtr_impEnumType *) var_type_50168.ptr () ;
          }else{
            inCompiler->castError ("impEnumType", var_type_50168.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1554)) ;
          }
        }
        GALGAS_impEnumType var_enumType_54289 = temp_18 ;
        enumGalgasBool test_19 = kBoolTrue ;
        if (kBoolTrue == test_19) {
          test_19 = var_enumType_54289.readProperty_valuesMap ().getter_hasKey (var_parameterValue_50817.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1555)).boolEnum () ;
          if (kBoolTrue == test_19) {
            var_enumType_54289.readProperty_valuesMap ().method_get (var_parameterValue_50817, var_subTypes_53409, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1556)) ;
          }
        }
        if (kBoolFalse == test_19) {
          TC_Array <C_FixItDescription> fixItArray20 ;
          inCompiler->emitSemanticError (var_parameterValue_50817.readProperty_location (), var_parameterValue_50817.readProperty_string ().add_operation (GALGAS_string (" ENUM value "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1558)).add_operation (GALGAS_string ("for "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1558)).add_operation (var_parameterType_50094.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)).add_operation (GALGAS_string (" undeclared.\nOne of the following"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)).add_operation (GALGAS_string ("values are expected :\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)).add_operation (function_valueList (var_enumType_54289.readProperty_valuesMap (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1560)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1560)), fixItArray20  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1558)) ;
        }
        {
        routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)) ;
        }
        enumGalgasBool test_21 = kBoolTrue ;
        if (kBoolTrue == test_21) {
          test_21 = GALGAS_bool (kIsNotEqual, var_subTypes_53409.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1564)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
          if (kBoolTrue == test_21) {
            {
            routine_displayOil (GALGAS_string ("\n    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1565)) ;
            }
            {
            routine_arxmlDefinitionContainer (var_subTypes_53409, var_subAttributes_53477, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1566)) ;
            }
            {
            routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1568)) ;
            }
          }
        }
        {
        routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1570)) ;
        }
        var_val_49953 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817.readProperty_string (), var_subAttributes_53477  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1572)) ;
      }
    }
    if (kBoolFalse == test_17) {
      enumGalgasBool test_22 = kBoolTrue ;
      if (kBoolTrue == test_22) {
        test_22 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF"))).boolEnum () ;
        if (kBoolTrue == test_22) {
          GALGAS_impBoolType temp_23 ;
          if (var_type_50168.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_impBoolType *> (var_type_50168.ptr ())) {
              temp_23 = (cPtr_impBoolType *) var_type_50168.ptr () ;
            }else{
              inCompiler->castError ("impBoolType", var_type_50168.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1581)) ;
            }
          }
          GALGAS_impBoolType var_boolType_55423 = temp_23 ;
          GALGAS_bool var_booleanValue_55469 ;
          enumGalgasBool test_24 = kBoolTrue ;
          if (kBoolTrue == test_24) {
            GALGAS_bool test_25 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1583)).objectCompare (GALGAS_string ("TRUE"))) ;
            if (kBoolTrue != test_25.boolEnum ()) {
              test_25 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
            }
            test_24 = test_25.boolEnum () ;
            if (kBoolTrue == test_24) {
              var_subTypes_53409 = var_boolType_55423.readProperty_trueSubAttributes () ;
              var_booleanValue_55469 = GALGAS_bool (true) ;
            }
          }
          if (kBoolFalse == test_24) {
            enumGalgasBool test_26 = kBoolTrue ;
            if (kBoolTrue == test_26) {
              GALGAS_bool test_27 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1587)).objectCompare (GALGAS_string ("FALSE"))) ;
              if (kBoolTrue != test_27.boolEnum ()) {
                test_27 = GALGAS_bool (kIsEqual, var_parameterValue_50817.readProperty_string ().objectCompare (GALGAS_string ("0"))) ;
              }
              test_26 = test_27.boolEnum () ;
              if (kBoolTrue == test_26) {
                var_subTypes_53409 = var_boolType_55423.readProperty_falseSubAttributes () ;
                var_booleanValue_55469 = GALGAS_bool (false) ;
              }
            }
            if (kBoolFalse == test_26) {
              var_booleanValue_55469 = GALGAS_bool (false) ;
              TC_Array <C_FixItDescription> fixItArray28 ;
              inCompiler->emitSemanticError (var_parameterValue_50817.readProperty_location (), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray28  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1593)) ;
            }
          }
          {
          routine_displayOil (GALGAS_string (" = ").add_operation (var_booleanValue_55469.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1596)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1596)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1596)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1596)) ;
          }
          enumGalgasBool test_29 = kBoolTrue ;
          if (kBoolTrue == test_29) {
            test_29 = GALGAS_bool (kIsNotEqual, var_subTypes_53409.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1597)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_29) {
              {
              routine_displayOil (GALGAS_string ("\n    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1598)) ;
              }
              {
              routine_arxmlDefinitionContainer (var_subTypes_53409, var_subAttributes_53477, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1599)) ;
              }
              {
              routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1601)) ;
              }
            }
          }
          {
          routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1603)) ;
          }
          var_val_49953 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_50633, var_parameterType_50094.readProperty_location (), var_booleanValue_55469, var_subAttributes_53477  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1605)) ;
        }
      }
      if (kBoolFalse == test_22) {
        enumGalgasBool test_30 = kBoolTrue ;
        if (kBoolTrue == test_30) {
          test_30 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-INTEGER-PARAM-DEF"))).boolEnum () ;
          if (kBoolTrue == test_30) {
            GALGAS_bool var_sign_56716 ;
            {
            routine_arxmlPopSign (var_parameterValue_50817, var_sign_56716, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1614)) ;
            }
            GALGAS_luint_36__34_ var_integerValue_56740 = GALGAS_luint_36__34_::constructor_new (var_parameterValue_50817.readProperty_string ().getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1617)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 1617)), var_parameterValue_50817.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1616)) ;
            {
            routine_displayOil (GALGAS_string (" = ").add_operation (var_integerValue_56740.readProperty_uint_36__34_ ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 1620)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1620)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1620)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1620)) ;
            }
            var_val_49953 = function_checkAndGetIntegerNumber (var_oil_5F_desc_50633, var_type_50168.readProperty_type (), var_integerValue_56740, var_sign_56716, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1622)) ;
          }
        }
        if (kBoolFalse == test_30) {
          enumGalgasBool test_31 = kBoolTrue ;
          if (kBoolTrue == test_31) {
            test_31 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-FLOAT-PARAM-DEF"))).boolEnum () ;
            if (kBoolTrue == test_31) {
              GALGAS_bool var_sign_57319 ;
              {
              routine_arxmlPopSign (var_parameterValue_50817, var_sign_57319, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1628)) ;
              }
              GALGAS_ldouble var_floatValue_57343 = GALGAS_ldouble::constructor_new (var_parameterValue_50817.readProperty_string ().getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1631)), var_parameterValue_50817.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1630)) ;
              {
              routine_displayOil (GALGAS_string (" = ").add_operation (var_floatValue_57343.readProperty_double ().getter_string (SOURCE_FILE ("arxml_parser.galgas", 1634)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1634)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1634)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1634)) ;
              }
              var_val_49953 = function_checkAndGetFloatNumber (var_oil_5F_desc_50633, var_type_50168.readProperty_type (), var_floatValue_57343, var_sign_57319, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1636)) ;
            }
          }
          if (kBoolFalse == test_31) {
            enumGalgasBool test_32 = kBoolTrue ;
            if (kBoolTrue == test_32) {
              test_32 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-STRING-PARAM-DEF"))).boolEnum () ;
              if (kBoolTrue == test_32) {
                {
                routine_displayOil (GALGAS_string (" = \"").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1642)).add_operation (GALGAS_string ("\";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1642)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1642)) ;
                }
                var_val_49953 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1644)) ;
              }
            }
            if (kBoolFalse == test_32) {
              enumGalgasBool test_33 = kBoolTrue ;
              if (kBoolTrue == test_33) {
                test_33 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-REFERENCE-DEF"))).boolEnum () ;
                if (kBoolTrue == test_33) {
                  {
                  routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1652)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1652)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1652)) ;
                  }
                  var_val_49953 = GALGAS_objectRefAttribute::constructor_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1654)) ;
                }
              }
              if (kBoolFalse == test_33) {
                enumGalgasBool test_34 = kBoolTrue ;
                if (kBoolTrue == test_34) {
                  test_34 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("TPL-IDENTIFIER-DEF"))).boolEnum () ;
                  if (kBoolTrue == test_34) {
                    {
                    routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1662)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1662)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1662)) ;
                    }
                    var_val_49953 = GALGAS_string_5F_class::constructor_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817.readProperty_string ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1664)) ;
                  }
                }
                if (kBoolFalse == test_34) {
                  enumGalgasBool test_35 = kBoolTrue ;
                  if (kBoolTrue == test_35) {
                    test_35 = GALGAS_bool (kIsEqual, var_valueType_50439.readProperty_string ().objectCompare (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF"))).boolEnum () ;
                    if (kBoolTrue == test_35) {
                      GALGAS_impStructType temp_36 ;
                      if (var_type_50168.isValid ()) {
                        if (nullptr != dynamic_cast <const cPtr_impStructType *> (var_type_50168.ptr ())) {
                          temp_36 = (cPtr_impStructType *) var_type_50168.ptr () ;
                        }else{
                          inCompiler->castError ("impStructType", var_type_50168.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1672)) ;
                        }
                      }
                      GALGAS_impStructType var_structType_59236 = temp_36 ;
                      var_subTypes_53409 = var_structType_59236.readProperty_structAttributes () ;
                      {
                      routine_displayOil (GALGAS_string (" ").add_operation (var_parameterValue_50817.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1675)).add_operation (GALGAS_string ("\n    {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1675)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1675)) ;
                      }
                      {
                      routine_arxmlDefinitionContainer (var_subTypes_53409, var_subAttributes_53477, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1676)) ;
                      }
                      {
                      routine_displayOil (GALGAS_string ("    };"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1678)) ;
                      }
                      var_val_49953 = GALGAS_structAttribute::constructor_new (var_oil_5F_desc_50633, var_parameterValue_50817.readProperty_location (), var_parameterValue_50817, var_subAttributes_53477  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)) ;
                    }
                  }
                  if (kBoolFalse == test_35) {
                    TC_Array <C_FixItDescription> fixItArray37 ;
                    inCompiler->emitSemanticError (var_valueType_50439.readProperty_location (), GALGAS_string ("Undefined valueType ").add_operation (var_valueType_50439.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1688)), fixItArray37  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1688)) ;
                    var_val_49953.drop () ; // Release error dropped variable
                    var_typeOk_50142 = GALGAS_bool (false) ;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  {
  routine_displayOil (GALGAS_string ("      /* ARXML Type :").add_operation (var_valueType_50439.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1692)).add_operation (GALGAS_string (" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1692)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1692)) ;
  }
  GALGAS_identifierMap var_idfs_60177 = ioArgument_identifiers.readProperty_objectParams () ;
  enumGalgasBool test_38 = kBoolTrue ;
  if (kBoolTrue == test_38) {
    test_38 = var_type_50168.readProperty_multiple ().boolEnum () ;
    if (kBoolTrue == test_38) {
      enumGalgasBool test_39 = kBoolTrue ;
      if (kBoolTrue == test_39) {
        test_39 = var_idfs_60177.getter_hasKey (var_parameterType_50094.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1699)).boolEnum () ;
        if (kBoolTrue == test_39) {
          GALGAS_object_5F_t var_attributeList_60306 ;
          {
          var_idfs_60177.setter_del (var_parameterType_50094, var_attributeList_60306, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1703)) ;
          }
          if (var_attributeList_60306.isValid ()) {
            if (var_attributeList_60306.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
              GALGAS_multipleAttribute cast_60509_multiAttribute ((cPtr_multipleAttribute *) var_attributeList_60306.ptr ()) ;
              GALGAS_identifierList var_aList_60550 = cast_60509_multiAttribute.readProperty_items () ;
              var_aList_60550.addAssign_operation (var_val_49953  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1707)) ;
              var_val_49953 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1708)), cast_60509_multiAttribute.readProperty_location (), var_aList_60550  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1708)) ;
            }
          }
        }
      }
      if (kBoolFalse == test_39) {
        GALGAS_identifierList var_aList_60820 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1713)) ;
        GALGAS_object_5F_t var_defaultValue_60896 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_type_50168.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1715)) ;
        if (var_defaultValue_60896.isValid ()) {
          if (var_defaultValue_60896.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
            GALGAS_multipleAttribute cast_61023_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_60896.ptr ()) ;
            var_aList_60820 = cast_61023_multiAttribute.readProperty_items () ;
          }
        }
        var_aList_60820.addAssign_operation (var_val_49953  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1725)) ;
        var_val_49953 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1727)), var_val_49953.readProperty_location (), var_aList_60820  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1727)) ;
      }
      enumGalgasBool test_40 = kBoolTrue ;
      if (kBoolTrue == test_40) {
        test_40 = var_idfs_60177.getter_hasKey (var_parameterType_50094.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1729)).boolEnum () ;
        if (kBoolTrue == test_40) {
          GALGAS_object_5F_t var_existingObject_61514 ;
          {
          var_idfs_60177.setter_del (var_parameterType_50094, var_existingObject_61514, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1733)) ;
          }
          {
          var_val_49953.insulate (HERE) ;
          cPtr_object_5F_t * ptr_61592 = (cPtr_object_5F_t *) var_val_49953.ptr () ;
          callExtensionSetter_mergeSubAttributes ((cPtr_object_5F_t *) ptr_61592, var_existingObject_61514, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1734)) ;
          }
        }
      }
    }
  }
  enumGalgasBool test_41 = kBoolTrue ;
  if (kBoolTrue == test_41) {
    test_41 = var_typeOk_50142.boolEnum () ;
    if (kBoolTrue == test_41) {
      {
      var_idfs_60177.setter_put (var_parameterType_50094, var_val_49953, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1740)) ;
      }
    }
  }
  {
  ioArgument_identifiers.setter_setObjectParams (var_idfs_60177 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1742)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'testTypeError'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_testTypeError (GALGAS_dataType inArgument_type,
                            GALGAS_lstring inArgument_valueType,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1753)).objectCompare (inArgument_valueType.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (inArgument_valueType.readProperty_location (), GALGAS_string ("Expected oil type ").add_operation (extensionGetter_oilType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)).add_operation (inArgument_valueType.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1755)).add_operation (GALGAS_string (".\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1755)).add_operation (GALGAS_string (" Fix : Replace it with "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1755)).add_operation (extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1756)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1756)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1754)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'oilEquivalentName'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_oilEquivalentName (GALGAS_lstring inArgument_parentPath,
                                GALGAS_lstring inArgument_currentPath,
                                GALGAS_lstring & outArgument_outName,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outName.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, inArgument_parentPath.readProperty_string ().objectCompare (inArgument_currentPath.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      inArgument_parentPath.setter_setString (inArgument_parentPath.readProperty_string ().getter_stringByDeletingLastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1766)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1766)) ;
    }
  }
  GALGAS_lstring var_objectKind_62451 = GALGAS_lstring::constructor_new (inArgument_currentPath.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1769)), inArgument_currentPath.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1769)) ;
  GALGAS_string var_lastParent_62744 = inArgument_parentPath.readProperty_string ().getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1774)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1774)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_lastParent_62744.objectCompare (GALGAS_string ("OSOS"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_lastParent_62744 = GALGAS_string ("OS") ;
    }
  }
  GALGAS_uint var_lastParentLength_62986 = var_lastParent_62744.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1782)) ;
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_objectKind_62451.readProperty_string ().getter_leftSubString (var_lastParentLength_62986 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1783)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1783)).objectCompare (var_lastParent_62744)).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_objectKind_62451.setter_setString (var_objectKind_62451.readProperty_string ().getter_subStringFromIndex (var_lastParentLength_62986 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1785)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1785)) ;
      var_objectKind_62451.setter_setString (var_objectKind_62451.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1786)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1786)) ;
      outArgument_outName = var_objectKind_62451 ;
    }
  }
  if (kBoolFalse == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (var_objectKind_62451.readProperty_location (), GALGAS_string ("An object must be named by its Parent.\n ").add_operation (GALGAS_string ("Ex : If Task object has Os parent, then the DEFINITION-REF must be "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1789)).add_operation (GALGAS_string ("(...)/Os/OsTask.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1790)).add_operation (GALGAS_string ("Fix : Add \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1791)).add_operation (var_lastParent_62744, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1792)).add_operation (GALGAS_string ("\" to the name of your property."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1792)), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1789)) ;
    outArgument_outName.drop () ; // Release error dropped variable
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetDescription'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetDescription (GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring & outArgument_description,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_description.drop () ; // Release 'out' argument
  outArgument_description = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1801))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1801)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1804)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_arxmlElementValue var_desc_63871 ;
      callExtensionMethod_getElement ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), var_desc_63871, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1805)) ;
      callExtensionMethod_getAllTextsInSelf ((cPtr_arxmlElementValue *) var_desc_63871.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1806)) ;
    }
  }
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1808)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_arxmlElementValue var_desc_64056 ;
      callExtensionMethod_getElement ((cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), var_desc_64056, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1809)) ;
      callExtensionMethod_getAllTextsInSelf ((cPtr_arxmlElementValue *) var_desc_64056.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1810)) ;
    }
  }
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1814)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1814)) ;
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\r"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1817)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1817)) ;
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\\"), GALGAS_string ("\\\\"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1820)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1820)) ;
  outArgument_description.setter_setString (outArgument_description.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("\""), GALGAS_string ("\\\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1823)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1823)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'displayOil'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_displayOil (GALGAS_string inArgument_string,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_goil_5F_options_arxmlDisplayOil.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (inArgument_string  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1832)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetMultiplicity'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetMultiplicity (GALGAS_arxmlElementValue inArgument_element,
                                   GALGAS_lstring inArgument_objectName,
                                   GALGAS_lbool & outArgument_multiple,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_multiple.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1841)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_smultiple_65098 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1842)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_smultiple_65098.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1844)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_smultiple_65098.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (true), var_smultiple_65098.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1846)) ;
          {
          routine_displayOil (GALGAS_string ("[]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1847)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), var_smultiple_65098.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1849)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), inArgument_objectName.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1852)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlPopSign'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlPopSign (GALGAS_lstring & ioArgument_value,
                           GALGAS_bool & outArgument_sign,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_sign.drop () ; // Release 'out' argument
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, ioArgument_value.readProperty_string ().getter_characterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1861)).objectCompare (GALGAS_char (TO_UNICODE (45)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_sign = GALGAS_bool (true) ;
      ioArgument_value.setter_setString (ioArgument_value.readProperty_string ().getter_subStringFromIndex (GALGAS_uint (uint32_t (1U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1863)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1863)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, ioArgument_value.readProperty_string ().getter_characterAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1864)).objectCompare (GALGAS_char (TO_UNICODE (43)))).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_sign = GALGAS_bool (false) ;
        ioArgument_value.setter_setString (ioArgument_value.readProperty_string ().getter_subStringFromIndex (GALGAS_uint (uint32_t (1U)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1866)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1866)) ;
      }
    }
    if (kBoolFalse == test_1) {
      outArgument_sign = GALGAS_bool (false) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetWithAuto'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetWithAuto (GALGAS_arxmlElementValue inArgument_parameter,
                               GALGAS_bool & outArgument_withAuto,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_withAuto.drop () ; // Release 'out' argument
  outArgument_withAuto = GALGAS_bool (false) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1877)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_lstring var_autoString_66006 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1878)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        GALGAS_bool test_2 = GALGAS_bool (kIsEqual, var_autoString_66006.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1879)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_2.boolEnum ()) {
          test_2 = GALGAS_bool (kIsEqual, var_autoString_66006.readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
        }
        test_1 = test_2.boolEnum () ;
        if (kBoolTrue == test_1) {
          outArgument_withAuto = GALGAS_bool (true) ;
          {
          routine_displayOil (GALGAS_string (" WITH_AUTO"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1882)) ;
          }
        }
      }
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlGetName'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlGetName (GALGAS_arxmlElementValue inArgument_parameter,
                           GALGAS_lstring & outArgument_objectName,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_objectName = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1892)) ;
  outArgument_objectName.setter_setString (outArgument_objectName.readProperty_string ().getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1893)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1893)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'arxmlInsertObjectAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_arxmlInsertObjectAttribute (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                         GALGAS_lstring inArgument_attributeName,
                                         GALGAS_impType inArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = ioArgument_objectAttributes.getter_hasKey (inArgument_attributeName.readProperty_string () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1901)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_impType var_previousType_66643 ;
      ioArgument_objectAttributes.method_get (inArgument_attributeName, var_previousType_66643, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1903)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_previousType_66643.readProperty_multiple ().boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_object_5F_t var_previousDefaultValue_66977 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_previousType_66643.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1909)) ;
          GALGAS_object_5F_t var_defaultValue_67051 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) inArgument_type.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1910)) ;
          GALGAS_bool var_oneIsMultiple_67101 = GALGAS_bool (false) ;
          enumGalgasBool test_2 = kBoolTrue ;
          if (kBoolTrue == test_2) {
            test_2 = GALGAS_bool (var_previousDefaultValue_66977.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_oneIsMultiple_67101 = GALGAS_bool (true) ;
            }
          }
          if (kBoolFalse == test_2) {
            enumGalgasBool test_3 = kBoolTrue ;
            if (kBoolTrue == test_3) {
              test_3 = GALGAS_bool (var_defaultValue_67051.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
              if (kBoolTrue == test_3) {
                var_oneIsMultiple_67101 = GALGAS_bool (true) ;
              }
            }
          }
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = var_oneIsMultiple_67101.boolEnum () ;
            if (kBoolTrue == test_4) {
              GALGAS_identifierList var_aList_67512 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1921)) ;
              GALGAS_lstring var_desc_67548 = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1922)) ;
              GALGAS_location var_location_67588 = GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1923)) ;
              if (var_previousDefaultValue_66977.isValid ()) {
                if (var_previousDefaultValue_66977.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                  GALGAS_multipleAttribute cast_67708_multiAttribute ((cPtr_multipleAttribute *) var_previousDefaultValue_66977.ptr ()) ;
                  var_aList_67512 = cast_67708_multiAttribute.readProperty_items () ;
                  var_desc_67548 = cast_67708_multiAttribute.readProperty_oil_5F_desc () ;
                  var_location_67588 = cast_67708_multiAttribute.readProperty_location () ;
                }
              }
              if (var_defaultValue_67051.isValid ()) {
                if (var_defaultValue_67051.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
                  GALGAS_multipleAttribute cast_67968_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_67051.ptr ()) ;
                  var_aList_67512.plusAssign_operation(cast_67968_multiAttribute.readProperty_items (), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1936)) ;
                  enumGalgasBool test_5 = kBoolTrue ;
                  if (kBoolTrue == test_5) {
                    test_5 = GALGAS_bool (kIsEqual, var_desc_67548.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                    if (kBoolTrue == test_5) {
                      var_desc_67548 = cast_67968_multiAttribute.readProperty_oil_5F_desc () ;
                    }
                  }
                  enumGalgasBool test_6 = kBoolTrue ;
                  if (kBoolTrue == test_6) {
                    test_6 = GALGAS_bool (kIsEqual, var_location_67588.objectCompare (GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1940)))).boolEnum () ;
                    if (kBoolTrue == test_6) {
                      var_location_67588 = cast_67968_multiAttribute.readProperty_location () ;
                    }
                  }
                }
              }
              GALGAS_object_5F_t var_newDefault_68305 = GALGAS_multipleAttribute::constructor_new (var_desc_67548, var_location_67588, var_aList_67512  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1946)) ;
              {
              inArgument_type.insulate (HERE) ;
              cPtr_impType * ptr_68413 = (cPtr_impType *) inArgument_type.ptr () ;
              callExtensionSetter_setDefValue ((cPtr_impType *) ptr_68413, var_newDefault_68305, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1949)) ;
              }
              {
              GALGAS_impType joker_68491 ; // Joker input parameter
              ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68491, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1951)) ;
              }
              {
              ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1952)) ;
              }
            }
          }
        }
      }
      enumGalgasBool test_7 = kBoolTrue ;
      if (kBoolTrue == test_7) {
        test_7 = function_checkNewTypeWithinPreviousType (inArgument_attributeName, var_previousType_66643, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1956)).boolEnum () ;
        if (kBoolTrue == test_7) {
          {
          GALGAS_impType joker_68775 ; // Joker input parameter
          ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68775, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1959)) ;
          }
          {
          ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1960)) ;
          }
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    {
    ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1963)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode print'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_print (const GALGAS_uint constinArgument_indentation,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_indent_3613 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 172)) ;
  inCompiler->printMessage (var_indent_3613  COMMA_SOURCE_FILE ("arxml_types.galgas", 173)) ;
  inCompiler->printMessage (GALGAS_string ("NODE \"").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174)).add_operation (GALGAS_string ("\" "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174))  COMMA_SOURCE_FILE ("arxml_types.galgas", 174)) ;
  extensionMethod_print (this->mProperty_attributes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 175)) ;
  inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("arxml_types.galgas", 176)) ;
  extensionMethod_print (this->mProperty_enclosedNodes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 177)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode getElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getElementsFromName (const GALGAS_string constinArgument_nodeName,
                                                        GALGAS_arxmlElementList & ioArgument_nodeList,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (this->mProperty_name.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_arxmlElementNode temp_1 = this ;
      ioArgument_nodeList.addAssign_operation (temp_1  COMMA_SOURCE_FILE ("arxml_types.galgas", 185)) ;
    }
  }
  extensionMethod_getElementsFromName (this->mProperty_enclosedNodes, constinArgument_nodeName, ioArgument_nodeList, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 188)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode getSubElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getSubElementsFromName (const GALGAS_string constinArgument_nodeName,
                                                           GALGAS_arxmlElementList & ioArgument_nodeList,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_arxmlNodeList enumerator_4178 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
  while (enumerator_4178.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (enumerator_4178.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlElementNode).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlElementNode temp_1 ;
        if (enumerator_4178.current_node (HERE).isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_arxmlElementNode *> (enumerator_4178.current_node (HERE).ptr ())) {
            temp_1 = (cPtr_arxmlElementNode *) enumerator_4178.current_node (HERE).ptr () ;
          }else{
            inCompiler->castError ("arxmlElementNode", enumerator_4178.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 197)) ;
          }
        }
        GALGAS_arxmlElementNode var_currentElement_4287 = temp_1 ;
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = GALGAS_bool (kIsEqual, var_currentElement_4287.readProperty_name ().readProperty_string ().objectCompare (constinArgument_nodeName)).boolEnum () ;
          if (kBoolTrue == test_2) {
            ioArgument_nodeList.addAssign_operation (var_currentElement_4287  COMMA_SOURCE_FILE ("arxml_types.galgas", 199)) ;
          }
        }
      }
    }
    enumerator_4178.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlElementNode getProperty'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getProperty (const GALGAS_string constinArgument_nodeName,
                                                GALGAS_lstring & ioArgument_value,
                                                GALGAS_bool & ioArgument_found,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (this->mProperty_name.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_arxmlElementNode temp_1 = this ;
      callExtensionMethod_getText ((cPtr_arxmlElementNode *) temp_1.ptr (), ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 224)) ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 227)).boolEnum () ;
    if (kBoolTrue == test_2) {
      cEnumerator_arxmlNodeList enumerator_4977 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
      bool bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
      if (enumerator_4977.hasCurrentObject () && bool_3) {
        while (enumerator_4977.hasCurrentObject () && bool_3) {
          callExtensionMethod_getProperty ((cPtr_arxmlNode *) enumerator_4977.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 231)) ;
          enumerator_4977.gotoNextObject () ;
          if (enumerator_4977.hasCurrentObject ()) {
            bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
          }
        }
      }
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode print'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_print (const GALGAS_uint constinArgument_indentation,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_indent_5999 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 281)) ;
  inCompiler->printMessage (var_indent_5999  COMMA_SOURCE_FILE ("arxml_types.galgas", 282)) ;
  inCompiler->printMessage (GALGAS_string ("COMMENT \"").add_operation (this->mProperty_comment.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283))  COMMA_SOURCE_FILE ("arxml_types.galgas", 283)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode getElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_getElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                        GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode getSubElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_getSubElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                           GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlCommentNode getProperty'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::method_getProperty (const GALGAS_string /* constinArgument_nodeName */,
                                                GALGAS_lstring & /* ioArgument_value */,
                                                GALGAS_bool & /* ioArgument_found */,
                                                C_Compiler * /* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode print'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_print (const GALGAS_uint constinArgument_indentation,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_indent_6756 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 316)) ;
  inCompiler->printMessage (var_indent_6756  COMMA_SOURCE_FILE ("arxml_types.galgas", 317)) ;
  inCompiler->printMessage (GALGAS_string ("TEXT \"").add_operation (this->mProperty_text.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318))  COMMA_SOURCE_FILE ("arxml_types.galgas", 318)) ;
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode getElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                     GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                     C_Compiler * /* inCompiler */
                                                     COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode getSubElementsFromName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getSubElementsFromName (const GALGAS_string /* constinArgument_nodeName */,
                                                        GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                        C_Compiler * /* inCompiler */
                                                        COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Overriding extension method '@arxmlTextNode getProperty'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getProperty (const GALGAS_string /* constinArgument_nodeName */,
                                             GALGAS_lstring & /* ioArgument_value */,
                                             GALGAS_bool & /* ioArgument_found */,
                                             C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
}
//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'lstringhere'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_lstringhere (GALGAS_lstring & outArgument_string,
                          GALGAS_string inArgument_value,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_string.drop () ; // Release 'out' argument
  outArgument_string = GALGAS_lstring::constructor_new (inArgument_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1148))  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1148)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'fillLegacy'
//
//----------------------------------------------------------------------------------------------------------------------

void routine_fillLegacy (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                         GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist var_sortedInfoList_32029 = ioArgument_classGraph.getter_keyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1155)) ;
  cEnumerator_stringlist enumerator_32083 (var_sortedInfoList_32029, kENUMERATION_UP) ;
  while (enumerator_32083.hasCurrentObject ()) {
    GALGAS_lstring var_lClassName_32146 ;
    {
    routine_lstringhere (var_lClassName_32146, enumerator_32083.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1158)) ;
    }
    GALGAS_arxmlMetaClass var_lClass_32190 ;
    ioArgument_classMap.method_searchKey (var_lClassName_32146, var_lClass_32190, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1160)) ;
    GALGAS_lstringlist var_fromList_32281 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1163)) ;
    {
    var_fromList_32281.setter_insertAtIndex (var_lClass_32190.readProperty_name (), GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1164)) ;
    }
    GALGAS_stringset var_empty_32363 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1165)) ;
    GALGAS_lstringlist var_successorList_32402 = ioArgument_classGraph.getter_accessibleNodesFrom (var_fromList_32281, var_empty_32363, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1166)) ;
    {
    var_lClass_32190.insulate (HERE) ;
    cPtr_arxmlMetaClass * ptr_32555 = (cPtr_arxmlMetaClass *) var_lClass_32190.ptr () ;
    callExtensionSetter_legacyAddParameters ((cPtr_arxmlMetaClass *) ptr_32555, ioArgument_classMap, var_successorList_32402, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1169)) ;
    }
    enumerator_32083.gotoNextObject () ;
  }
}


#include "project_header.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "command_line_interface/C_builtin_CLI_Options.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/F_verbose_output.h"
#include "galgas2/cLexiqueIntrospection.h"
#include "utilities/F_DisplayException.h"

//----------------------------------------------------------------------------------------------------------------------
//
//                      print_tool_help_message                                                  
//
//----------------------------------------------------------------------------------------------------------------------

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//----------------------------------------------------------------------------------------------------------------------

static const char * kSourceFileExtensions [] = {
  "oil",
  "OIL",
  "goilTemplate",
  "arxml",
  nullptr
} ;    

//----------------------------------------------------------------------------------------------------------------------

static const char * kSourceFileHelpMessages [] = {
  "an '.oil' source file",
  "an '.OIL' source file",
  "a Goil template file",
  "an AUTOSAR arxml configuration file",
  nullptr
} ;    

//----------------------------------------------------------------------------------------------------------------------

const char * projectVersionString (void) {
  return "3.1.16" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'before'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'after'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'programRule_0'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 33)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 34)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'programRule_1'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__31_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 38)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 39)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'programRule_2'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__32_ (const GALGAS_lstring /* constinArgument_inSourceFile */,
                                         C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
}


//----------------------------------------------------------------------------------------------------------------------
//
//Routine 'programRule_3'
//
//----------------------------------------------------------------------------------------------------------------------

static void routine_programRule_5F__33_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 48)) ;
  }
  GALGAS_arxmlNode var_root_1354 ;
  var_root_1354.drop () ;
  cGrammar_arxml_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile, var_root_1354, GALGAS_bool (true), GALGAS_bool (true)  COMMA_SOURCE_FILE ("goil_program.galgas", 49)) ;
  callExtensionMethod_print ((cPtr_arxmlNode *) var_root_1354.ptr (), GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("goil_program.galgas", 53)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//                      M A I N    F O R    L I B P M                                            
//
//----------------------------------------------------------------------------------------------------------------------

int mainForLIBPM (int inArgc, const char * inArgv []) {
//--- Analyze Command Line Options
  TC_UniqueArray <C_String> sourceFilesArray ;
  F_Analyze_CLI_Options (inArgc, inArgv,
                         sourceFilesArray,
                         kSourceFileExtensions,
                         kSourceFileHelpMessages,
                         print_tool_help_message) ;
//---
  int returnCode = 0 ; // No error
//--- Set Execution mode
  C_String executionModeOptionErrorMessage ;
  setExecutionMode (executionModeOptionErrorMessage) ;
  if (executionModeOptionErrorMessage.length () > 0) {
    co << executionModeOptionErrorMessage ;
    returnCode = 1 ;
  }else{
  //--- Common lexique object
    C_Compiler * commonCompiler = nullptr ;
    macroMyNew (commonCompiler, C_Compiler (nullptr COMMA_HERE)) ;
    try{
      routine_before (commonCompiler COMMA_HERE) ;
      cLexiqueIntrospection::handleGetKeywordListOption (commonCompiler) ;
      const bool verboseOptionOn = verboseOutput () ;
      for (int32_t i=0 ; i<sourceFilesArray.count () ; i++) {
        const C_String fileExtension = sourceFilesArray (i COMMA_HERE).pathExtension () ;
        const GALGAS_string sfp = GALGAS_string (sourceFilesArray (i COMMA_HERE)) ;
        const GALGAS_location location = commonCompiler->here () ;
        const GALGAS_lstring sourceFilePath (sfp, location) ;
        int r = 0 ;
        if (fileExtension == "oil") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__30_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "OIL") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__31_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "goilTemplate") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__32_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else if (fileExtension == "arxml") {
          switch (executionMode ()) {
          case kExecutionModeNormal :
            routine_programRule_5F__33_ (sourceFilePath, commonCompiler COMMA_HERE) ;
            break ;
          case kExecutionModeLexicalAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=lexical-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeSyntaxAnalysisOnly :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=syntax-only\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeIndexing :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=indexing\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          case kExecutionModeLatex :
            commonCompiler->onTheFlyRunTimeError ("Cannot handle \"--mode=latex\" option: no grammar in program RULE" COMMA_HERE) ;
            break ;
          }
        }else{
          printf ("*** Error: unhandled extension for file '%s' ***\n", sourceFilesArray (i COMMA_HERE).cString (HERE)) ;
          r = 1 ;
        }
        if (r != 0) {
          returnCode = r ;
        }
      }
    //--- Error or warnings ?
      if (totalErrorCount () > 0) {
        returnCode = 1 ; // Error code
      }else if (totalWarningCount () > 0) {
        if (gOption_galgas_5F_builtin_5F_options_treat_5F_warnings_5F_as_5F_error.mValue) {
          returnCode = 1 ; // Error code
          if (verboseOptionOn) {
            printf ("** Note: warnings are treated as errors. **\n") ;
          }
        }
      }
    //--- Epilogue
      routine_after (commonCompiler COMMA_HERE) ;
    //--- Emit JSON issue file ?
      if (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue != "") {
        commonCompiler->writeIssueJSONFile (gOption_generic_5F_cli_5F_options_emit_5F_issue_5F_json_5F_file.mValue) ;
      }
    //--- Display error and warnings count
      if (verboseOptionOn || (totalWarningCount () > 0) || (totalErrorCount () > 0)) {
        C_String message ;
        if (totalWarningCount () == 0) {
          message << "No warning" ;
        }else if (totalWarningCount () == 1) {
          message << "1 warning" ;
        }else{
          message << cStringWithSigned (totalWarningCount ()) << " warnings" ;
        }
        message << ", " ;
        if (totalErrorCount () == 0) {
          message << "no error" ;
        }else if (totalErrorCount () == 1) {
          message << "1 error" ;
        }else{
          message << cStringWithSigned (totalErrorCount ()) << " errors" ;
        }
        message << ".\n" ;
        ggs_printMessage (message COMMA_HERE) ;
      }
    }catch (const ::std::exception & e) {
      F_default_display_exception (e) ;
      returnCode = 1 ; // Error code
    }catch (...) {
      printf ("**** Unknow exception ****\n") ;
      throw ;
    }
    macroDetachSharedObject (commonCompiler) ;
  }
  return returnCode ;
}

