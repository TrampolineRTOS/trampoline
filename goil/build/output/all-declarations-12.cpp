#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

#include "all-declarations-12.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Routine 'arxmlImplementationContainerStructure'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1150)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1150)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1150)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1153)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1154)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1154)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1154)) ;
  }
  GALGAS_lbool var_multiple_39596 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_39596, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1157)) ;
  }
  GALGAS_lstring var_oil_5F_desc_39681 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_39681, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1160)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1162)) ;
  }
  GALGAS_implementationObjectMap var_structAttributes_39756 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1165)) ;
  {
  routine_arxmlImplementationContainer (var_structAttributes_39756, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1166)) ;
  }
  {
  routine_displayOil (GALGAS_string ("\n"
    "    } : \"").add_operation (var_oil_5F_desc_39681.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1168)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1168)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1168)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1168)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1172)) ;
  temp_0.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1172))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1172)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1176)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_39681  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1176)) ;
  outArgument_options = GALGAS_impStructType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_39596.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1175)), temp_1, var_structAttributes_39756  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1171)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                  Routine 'arxmlImplementationContainerIdentifier'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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
  routine_displayOil (GALGAS_string ("    ").add_operation (extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1188)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1188)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1188)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1191)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1192)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1192)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1192)) ;
  }
  GALGAS_lbool var_multiple_40679 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_40679, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1195)) ;
  }
  GALGAS_bool var_withAuto_40741 ;
  {
  routine_arxmlGetWithAuto (inArgument_parameter, var_withAuto_40741, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1198)) ;
  }
  GALGAS_lstring var_oil_5F_desc_40826 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_40826, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1201)) ;
  }
  GALGAS_object_5F_t var_defaultValue_40871 ;
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1205)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_value_40940 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFAULT-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1206)) ;
    {
    routine_displayOil (GALGAS_string (" = ").add_operation (var_value_40940.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1207)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1207)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1207)) ;
    }
    var_defaultValue_40871 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_40826, var_value_40940.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1210)), var_value_40940.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1211))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1208)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = var_withAuto_40741.boolEnum () ;
    if (kBoolTrue == test_1) {
      var_defaultValue_40871 = GALGAS_auto::constructor_new (var_oil_5F_desc_40826, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1214))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1214)) ;
    }else if (kBoolFalse == test_1) {
      var_defaultValue_40871 = GALGAS_void::constructor_new (var_oil_5F_desc_40826, outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1216))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1216)) ;
    }
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_40826.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1218)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1218)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1218)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1218)) ;
  }
  GALGAS_locationList temp_2 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1222)) ;
  temp_2.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1222))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1222)) ;
  GALGAS_lstringlist temp_3 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1226)) ;
  temp_3.addAssign_operation (var_oil_5F_desc_40826  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1226)) ;
  outArgument_options = GALGAS_impAutoDefaultType::constructor_new (temp_2, constinArgument_type, outArgument_objectName, var_multiple_40679.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1225)), temp_3, var_withAuto_40741, var_defaultValue_40871  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1221)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                   Routine 'arxmlImplementationContainerReference'                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlImplementationContainerReference (GALGAS_lstring & outArgument_objectName,
                                                    GALGAS_impType & outArgument_options,
                                                    const GALGAS_dataType constinArgument_type,
                                                    GALGAS_arxmlElementValue inArgument_parameter,
                                                    GALGAS_lstring /* inArgument_parentPath */,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_options.drop () ; // Release 'out' argument
  GALGAS_lstring var_objectType_42134 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DESTINATION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1240)) ;
  var_objectType_42134.mProperty_string = var_objectType_42134.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1242)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1242)) ;
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_objectType_42134.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1243)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1243)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1243)) ;
  }
  {
  routine_arxmlGetName (inArgument_parameter, outArgument_objectName, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1246)) ;
  }
  {
  routine_displayOil (GALGAS_string (" ").add_operation (outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1247)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1247)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1247)) ;
  }
  GALGAS_lbool var_multiple_42552 ;
  {
  routine_arxmlGetMultiplicity (inArgument_parameter, outArgument_objectName, var_multiple_42552, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1250)) ;
  }
  GALGAS_lstring var_oil_5F_desc_42637 ;
  {
  routine_arxmlGetDescription (inArgument_parameter, var_oil_5F_desc_42637, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1253)) ;
  }
  {
  routine_displayOil (GALGAS_string (": \"").add_operation (var_oil_5F_desc_42637.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1255)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1255)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1255)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1255)) ;
  }
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1259)) ;
  temp_0.addAssign_operation (outArgument_objectName.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1259))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1259)) ;
  GALGAS_lstringlist temp_1 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1263)) ;
  temp_1.addAssign_operation (var_oil_5F_desc_42637  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1263)) ;
  outArgument_options = GALGAS_refType::constructor_new (temp_0, constinArgument_type, outArgument_objectName, var_multiple_42552.getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1262)), temp_1, var_objectType_42134  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1258)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                          Routine 'arxmlDefinitionPackage'                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionPackage (GALGAS_implementation & ioArgument_imp,
                                     GALGAS_applicationDefinition & ioArgument_application,
                                     GALGAS_arxmlElementValue inArgument_packageElement,
                                     GALGAS_lstring inArgument_parentPath,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_packageName_43289 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1279)) ;
  GALGAS_lstring var_currentPath_43398 = GALGAS_lstring::constructor_new (inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1282)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1282)).add_operation (var_packageName_43289.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1282)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1282)), var_packageName_43289.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1283))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1282)) ;
  GALGAS_arxmlElementValueList var_definitions_43621 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1286)) ;
  GALGAS_stringlist var_definitionPath_43655 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1287)) ;
  var_definitionPath_43655.addAssign_operation (GALGAS_string ("ELEMENTS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1288)) ;
  var_definitionPath_43655.addAssign_operation (GALGAS_string ("ECUC-MODULE-CONFIGURATION-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1289)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_definitionPath_43655, var_definitions_43621, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1290)) ;
  cEnumerator_arxmlElementValueList enumerator_43867 (var_definitions_43621, kENUMERATION_UP) ;
  while (enumerator_43867.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionRoot (ioArgument_imp, ioArgument_application, enumerator_43867.current_value (HERE), var_currentPath_43398, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1292)) ;
    }
    enumerator_43867.gotoNextObject () ;
  }
  GALGAS_arxmlElementValueList var_packages_44035 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1296)) ;
  GALGAS_stringlist var_packagesPath_44067 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1297)) ;
  var_packagesPath_44067.addAssign_operation (GALGAS_string ("AR-PACKAGES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1298)) ;
  var_packagesPath_44067.addAssign_operation (GALGAS_string ("AR-PACKAGE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1299)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_packagesPath_44067, var_packages_44035, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1300)) ;
  cEnumerator_arxmlElementValueList enumerator_44245 (var_packages_44035, kENUMERATION_UP) ;
  while (enumerator_44245.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionPackage (ioArgument_imp, ioArgument_application, enumerator_44245.current_value (HERE), var_currentPath_43398, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1302)) ;
    }
    enumerator_44245.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            Routine 'arxmlDefinitionRoot'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionRoot (GALGAS_implementation & ioArgument_imp,
                                  GALGAS_applicationDefinition & ioArgument_application,
                                  GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring /* inArgument_parentPath */,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_cpuName_44520 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1313)) ;
  GALGAS_lstring var_currentPath_44630 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1316)) ;
  GALGAS_objectsMap var_objects_44745 = ioArgument_application.getter_objects (SOURCE_FILE ("arxml_parser.galgas", 1319)) ;
  GALGAS_lstring var_oil_5F_desc_44858 ;
  {
  routine_arxmlGetDescription (inArgument_packageElement, var_oil_5F_desc_44858, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1322)) ;
  }
  GALGAS_arxmlElementValueList var_subDefs_44920 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1325)) ;
  GALGAS_stringlist var_subDefsPath_44951 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1326)) ;
  var_subDefsPath_44951.addAssign_operation (GALGAS_string ("CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1327)) ;
  var_subDefsPath_44951.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1328)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), var_subDefsPath_44951, var_subDefs_44920, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1329)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "CPU ").add_operation (var_cpuName_44520.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1331)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1331)).add_operation (GALGAS_string ("\n"
    "{\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1331)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1331)) ;
  }
  cEnumerator_arxmlElementValueList enumerator_45185 (var_subDefs_44920, kENUMERATION_UP) ;
  while (enumerator_45185.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionObject (ioArgument_imp, var_objects_44745, enumerator_45185.current_value (HERE), var_currentPath_44630, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1334)) ;
    }
    enumerator_45185.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setName (var_cpuName_44520 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1338)) ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_44745 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1339)) ;
  }
  {
  routine_displayOil (GALGAS_string ("}; /* END CPU ").add_operation (var_cpuName_44520.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1341)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1341)).add_operation (GALGAS_string (" : \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1341)).add_operation (var_oil_5F_desc_44858.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1342)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1342)).add_operation (GALGAS_string ("\" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1342)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1341)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           Routine 'arxmlDefinitionObject'                                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionObject (GALGAS_implementation & ioArgument_imp,
                                    GALGAS_objectsMap & ioArgument_objects,
                                    GALGAS_arxmlElementValue inArgument_currentElement,
                                    GALGAS_lstring inArgument_parentPath,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_currentPath_45657 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1352)) ;
  GALGAS_lstring var_objectKind_45779 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_currentPath_45657, var_objectKind_45779, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1353)) ;
  }
  GALGAS_implementationObject var_impObjOfKind_45840 = callExtensionGetter_impObject ((const cPtr_implementation *) ioArgument_imp.ptr (), var_objectKind_45779.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1356)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1356)) ;
  GALGAS_objectKind var_objectsForKind_45908 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1357))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1357)) ;
  const enumGalgasBool test_0 = ioArgument_objects.getter_hasKey (var_objectKind_45779.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1358)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1358)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_objects.setter_del (var_objectKind_45779, var_objectsForKind_45908, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1359)) ;
    }
  }
  GALGAS_lstring var_objectName_46101 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1363)) ;
  GALGAS_objectAttributes var_object_46213 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1366)) ;
  GALGAS_objectKindMap var_objectsKind_46258 = var_objectsForKind_45908.getter_objects (SOURCE_FILE ("arxml_parser.galgas", 1367)) ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_impObjOfKind_45840.getter_multiple (SOURCE_FILE ("arxml_parser.galgas", 1368)).getter_bool (SOURCE_FILE ("arxml_parser.galgas", 1368)).objectCompare (GALGAS_bool (false))).boolEnum () ;
  if (kBoolTrue == test_1) {
    var_objectName_46101 = var_objectKind_45779 ;
  }
  const enumGalgasBool test_2 = var_objectsKind_46258.getter_hasKey (var_objectName_46101.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1376)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1376)).boolEnum () ;
  if (kBoolTrue == test_2) {
    {
    var_objectsKind_46258.setter_del (var_objectName_46101, var_object_46213, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1377)) ;
    }
  }
  GALGAS_lstring var_oil_5F_desc_46820 ;
  {
  routine_arxmlGetDescription (inArgument_currentElement, var_oil_5F_desc_46820, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1381)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  ").add_operation (var_objectKind_45779.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1383)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)).add_operation (var_objectName_46101.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1383)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)).add_operation (GALGAS_string ("\n"
    "  {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1383)) ;
  }
  {
  routine_arxmlDefinitionContainer (var_impObjOfKind_45840.getter_attributes (SOURCE_FILE ("arxml_parser.galgas", 1386)), var_object_46213, inArgument_currentElement, var_currentPath_45657, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1386)) ;
  }
  {
  routine_displayOil (GALGAS_string ("  } : \"").add_operation (var_oil_5F_desc_46820.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1391)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)).add_operation (GALGAS_string ("\";\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1391)) ;
  }
  GALGAS_identifierMap var_attributes_47215 = var_object_46213.getter_objectParams (SOURCE_FILE ("arxml_parser.galgas", 1394)) ;
  const enumGalgasBool test_3 = var_attributes_47215.getter_hasKey (GALGAS_string ("NAME") COMMA_SOURCE_FILE ("arxml_parser.galgas", 1395)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 1395)).boolEnum () ;
  if (kBoolTrue == test_3) {
    {
    var_attributes_47215.setter_put (GALGAS_lstring::constructor_new (GALGAS_string ("NAME"), var_objectName_46101.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1396))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1396)), GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_46820, var_objectName_46101.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1398)), var_objectName_46101.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1399))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1397)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1396)) ;
    }
    {
    var_object_46213.setter_setObjectParams (var_attributes_47215 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1400)) ;
    }
  }
  {
  var_objectsKind_46258.setter_put (var_objectName_46101, var_object_46213, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1402)) ;
  }
  {
  var_objectsForKind_45908.setter_setObjects (var_objectsKind_46258 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1403)) ;
  }
  {
  ioArgument_objects.setter_put (var_objectKind_45779, var_objectsForKind_45908, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1404)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                         Routine 'arxmlDefinitionContainer'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionContainer (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_currentElement,
                                       GALGAS_lstring inArgument_currentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_textParameters_48011 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1414)) ;
  GALGAS_stringlist var_textParametersPath_48049 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1415)) ;
  var_textParametersPath_48049.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1416)) ;
  var_textParametersPath_48049.addAssign_operation (GALGAS_string ("ECUC-TEXTUAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1417)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_textParametersPath_48049, var_textParameters_48011, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1418)) ;
  GALGAS_arxmlElementValueList var_numParameters_48329 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1421)) ;
  GALGAS_stringlist var_numParametersPath_48366 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1422)) ;
  var_numParametersPath_48366.addAssign_operation (GALGAS_string ("PARAMETER-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1423)) ;
  var_numParametersPath_48366.addAssign_operation (GALGAS_string ("ECUC-NUMERICAL-PARAM-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1424)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_numParametersPath_48366, var_numParameters_48329, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1425)) ;
  GALGAS_arxmlElementValueList var_refParameters_48615 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1428)) ;
  GALGAS_stringlist var_refParametersPath_48652 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1429)) ;
  var_refParametersPath_48652.addAssign_operation (GALGAS_string ("REFERENCE-VALUES")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1430)) ;
  var_refParametersPath_48652.addAssign_operation (GALGAS_string ("ECUC-REFERENCE-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1431)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_refParametersPath_48652, var_refParameters_48615, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1432)) ;
  GALGAS_arxmlElementValueList var_structParameters_48898 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1435)) ;
  GALGAS_stringlist var_structParametersPath_48938 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1436)) ;
  var_structParametersPath_48938.addAssign_operation (GALGAS_string ("SUB-CONTAINERS")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1437)) ;
  var_structParametersPath_48938.addAssign_operation (GALGAS_string ("ECUC-CONTAINER-VALUE")  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1438)) ;
  callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) inArgument_currentElement.ptr (), var_structParametersPath_48938, var_structParameters_48898, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1439)) ;
  GALGAS_arxmlElementValueList var_allParameters_49181 = var_numParameters_48329.add_operation (var_textParameters_48011, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1442)).add_operation (var_refParameters_48615, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1443)).add_operation (var_structParameters_48898, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1444)) ;
  cEnumerator_arxmlElementValueList enumerator_49447 (var_allParameters_49181, kENUMERATION_UP) ;
  while (enumerator_49447.hasCurrentObject ()) {
    {
    routine_arxmlDefinitionParameter (constinArgument_types, ioArgument_identifiers, enumerator_49447.current_value (HERE), inArgument_currentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1449)) ;
    }
    enumerator_49447.gotoNextObject () ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                         Routine 'arxmlDefinitionParameter'                                          *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlDefinitionParameter (const GALGAS_implementationObjectMap constinArgument_types,
                                       GALGAS_objectAttributes & ioArgument_identifiers,
                                       GALGAS_arxmlElementValue inArgument_parameter,
                                       GALGAS_lstring inArgument_parentPath,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t var_val_49732 ;
  GALGAS_lstring var_parameterPath_49757 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1461)) ;
  GALGAS_lstring var_parameterType_49879 ;
  {
  routine_oilEquivalentName (inArgument_parentPath, var_parameterPath_49757, var_parameterType_49879, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1462)) ;
  }
  GALGAS_bool var_typeOk_49920 = GALGAS_bool (false) ;
  GALGAS_locationList temp_0 = GALGAS_locationList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1466)) ;
  temp_0.addAssign_operation (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1466))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1466)) ;
  GALGAS_impType var_type_49944 = GALGAS_impVoid::constructor_new (temp_0, GALGAS_dataType::constructor_void (SOURCE_FILE ("arxml_parser.galgas", 1468)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1468)), GALGAS_bool (false), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1470))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1466)) ;
  GALGAS_lstring var_valueType_50216 = callExtensionGetter_getAttributeValueFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("DEFINITION-REF"), GALGAS_string ("DEST"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1472)) ;
  GALGAS_lstring var_oil_5F_desc_50397 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1477))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1477)) ;
  GALGAS_bool var_isAuto_50553 = GALGAS_bool (false) ;
  GALGAS_lstring var_parameterValue_50587 ;
  const enumGalgasBool test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1484)).boolEnum () ;
  if (kBoolTrue == test_1) {
    var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1488)) ;
  }else if (kBoolFalse == test_1) {
    const enumGalgasBool test_2 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1489)).boolEnum () ;
    if (kBoolTrue == test_2) {
      var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("VALUE-REF"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1493)) ;
      var_parameterValue_50587.mProperty_string = var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1495)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1495)) ;
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1497)).getter_rightSubString (GALGAS_uint ((uint32_t) 3U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1497)).objectCompare (GALGAS_string ("REF"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        var_parameterType_49879.mProperty_string = var_parameterType_49879.getter_string (HERE).getter_leftSubString (var_parameterType_49879.getter_string (HERE).getter_length (SOURCE_FILE ("arxml_parser.galgas", 1499)).substract_operation (GALGAS_uint ((uint32_t) 3U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1499)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1498)) ;
      }else if (kBoolFalse == test_3) {
        const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1500)).getter_rightSubString (GALGAS_uint ((uint32_t) 4U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1500)).objectCompare (GALGAS_string ("REFS"))).boolEnum () ;
        if (kBoolTrue == test_4) {
          var_parameterType_49879.mProperty_string = var_parameterType_49879.getter_string (HERE).getter_leftSubString (var_parameterType_49879.getter_string (HERE).getter_length (SOURCE_FILE ("arxml_parser.galgas", 1502)).substract_operation (GALGAS_uint ((uint32_t) 4U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1502)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1501)) ;
        }else if (kBoolFalse == test_4) {
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1504)), GALGAS_string ("An object reference must end with REF or REFS"), fixItArray5  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1504)) ;
        }
      }
    }else if (kBoolFalse == test_2) {
      GALGAS_bool test_6 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("PARAMETER-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1506)) ;
      if (kBoolTrue != test_6.boolEnum ()) {
        test_6 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("REFERENCE-VALUES"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1507)) ;
      }
      const enumGalgasBool test_7 = test_6.boolEnum () ;
      if (kBoolTrue == test_7) {
        var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1511)) ;
      }else if (kBoolFalse == test_7) {
        const enumGalgasBool test_8 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1512)).boolEnum () ;
        if (kBoolTrue == test_8) {
          var_parameterValue_50587 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("IS-AUTO-VALUE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1516)) ;
          GALGAS_bool test_9 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1517)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1517)).objectCompare (GALGAS_string ("TRUE"))) ;
          if (kBoolTrue != test_9.boolEnum ()) {
            test_9 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1518)).objectCompare (GALGAS_string ("1"))) ;
          }
          const enumGalgasBool test_10 = test_9.boolEnum () ;
          if (kBoolTrue == test_10) {
            var_isAuto_50553 = GALGAS_bool (true) ;
          }
        }else if (kBoolFalse == test_8) {
          TC_Array <C_FixItDescription> fixItArray11 ;
          inCompiler->emitSemanticError (var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1522)), GALGAS_string ("No value has been found."), fixItArray11  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1522)) ;
          var_parameterValue_50587.drop () ; // Release error dropped variable
        }
      }
    }
  }
  const enumGalgasBool test_12 = constinArgument_types.getter_hasKey (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1526)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1526)).boolEnum () ;
  if (kBoolTrue == test_12) {
    constinArgument_types.method_get (var_parameterType_49879, var_type_49944, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1527)) ;
    var_typeOk_49920 = GALGAS_bool (true) ;
    {
    routine_testTypeError (var_type_49944.getter_type (SOURCE_FILE ("arxml_parser.galgas", 1530)), var_valueType_50216, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1530)) ;
    }
  }else if (kBoolFalse == test_12) {
    TC_Array <C_FixItDescription> fixItArray13 ;
    inCompiler->emitSemanticError (var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1532)), var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1532)).add_operation (GALGAS_string (" is not declared in the "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1532)).add_operation (GALGAS_string ("IMPLEMENTATION."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1532)), fixItArray13  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1532)) ;
  }
  {
  routine_displayOil (GALGAS_string ("    ").add_operation (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1536)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1536)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1536)) ;
  }
  GALGAS_implementationObjectMap var_subTypes_53173 = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 1538)) ;
  GALGAS_objectAttributes var_subAttributes_53246 = function_emptyObject (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1539)) ;
  const enumGalgasBool test_14 = var_isAuto_50553.boolEnum () ;
  if (kBoolTrue == test_14) {
    {
    routine_displayOil (GALGAS_string (" = AUTO;"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1548)) ;
    }
    const enumGalgasBool test_15 = callExtensionGetter_autoAllowed ((const cPtr_impType *) var_type_49944.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1549)).boolEnum () ;
    if (kBoolTrue == test_15) {
      var_val_49732 = GALGAS_auto::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1550))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1550)) ;
    }else if (kBoolFalse == test_15) {
      TC_Array <C_FixItDescription> fixItArray16 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1552)), GALGAS_string ("AUTO is not allowed"), fixItArray16  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1552)) ;
      var_val_49732.drop () ; // Release error dropped variable
    }
  }else if (kBoolFalse == test_14) {
    const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1555)).objectCompare (GALGAS_string ("ECUC-ENUMERATION-PARAM-DEF"))).boolEnum () ;
    if (kBoolTrue == test_17) {
      GALGAS_impEnumType temp_18 ;
      if (var_type_49944.isValid ()) {
        if (NULL != dynamic_cast <const cPtr_impEnumType *> (var_type_49944.ptr ())) {
          temp_18 = (cPtr_impEnumType *) var_type_49944.ptr () ;
        }else{
          inCompiler->castError ("impEnumType", var_type_49944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1559)) ;
        }
      }
      GALGAS_impEnumType var_enumType_54049 = temp_18 ;
      const enumGalgasBool test_19 = var_enumType_54049.getter_valuesMap (SOURCE_FILE ("arxml_parser.galgas", 1560)).getter_hasKey (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1560)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1560)).boolEnum () ;
      if (kBoolTrue == test_19) {
        var_enumType_54049.getter_valuesMap (SOURCE_FILE ("arxml_parser.galgas", 1561)).method_get (var_parameterValue_50587, var_subTypes_53173, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1561)) ;
      }else if (kBoolFalse == test_19) {
        TC_Array <C_FixItDescription> fixItArray20 ;
        inCompiler->emitSemanticError (var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1563)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1563)).add_operation (GALGAS_string (" ENUM value "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)).add_operation (GALGAS_string ("for "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)).add_operation (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1564)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1564)).add_operation (GALGAS_string (" undeclared.\n"
          "One of the following"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1564)).add_operation (GALGAS_string ("values are expected :\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1564)).add_operation (function_valueList (var_enumType_54049.getter_valuesMap (SOURCE_FILE ("arxml_parser.galgas", 1565)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1565)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1565)), fixItArray20  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1563)) ;
      }
      {
      routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1568)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1568)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1568)) ;
      }
      const enumGalgasBool test_21 = GALGAS_bool (kIsNotEqual, var_subTypes_53173.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1569)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
      if (kBoolTrue == test_21) {
        {
        routine_displayOil (GALGAS_string ("\n"
          "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1570)) ;
        }
        {
        routine_arxmlDefinitionContainer (var_subTypes_53173, var_subAttributes_53246, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1571)) ;
        }
        {
        routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1573)) ;
        }
      }
      {
      routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1575)) ;
      }
      var_val_49732 = GALGAS_enumAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1578)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1579)), var_subAttributes_53246  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1577)) ;
    }else if (kBoolFalse == test_17) {
      const enumGalgasBool test_22 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1582)).objectCompare (GALGAS_string ("ECUC-BOOLEAN-PARAM-DEF"))).boolEnum () ;
      if (kBoolTrue == test_22) {
        GALGAS_impBoolType temp_23 ;
        if (var_type_49944.isValid ()) {
          if (NULL != dynamic_cast <const cPtr_impBoolType *> (var_type_49944.ptr ())) {
            temp_23 = (cPtr_impBoolType *) var_type_49944.ptr () ;
          }else{
            inCompiler->castError ("impBoolType", var_type_49944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1586)) ;
          }
        }
        GALGAS_impBoolType var_boolType_55179 = temp_23 ;
        GALGAS_bool var_booleanValue_55225 ;
        GALGAS_bool test_24 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (HERE).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1588)).objectCompare (GALGAS_string ("TRUE"))) ;
        if (kBoolTrue != test_24.boolEnum ()) {
          test_24 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (HERE).objectCompare (GALGAS_string ("1"))) ;
        }
        const enumGalgasBool test_25 = test_24.boolEnum () ;
        if (kBoolTrue == test_25) {
          var_subTypes_53173 = var_boolType_55179.getter_trueSubAttributes (SOURCE_FILE ("arxml_parser.galgas", 1590)) ;
          var_booleanValue_55225 = GALGAS_bool (true) ;
        }else if (kBoolFalse == test_25) {
          GALGAS_bool test_26 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (HERE).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1592)).objectCompare (GALGAS_string ("FALSE"))) ;
          if (kBoolTrue != test_26.boolEnum ()) {
            test_26 = GALGAS_bool (kIsEqual, var_parameterValue_50587.getter_string (HERE).objectCompare (GALGAS_string ("0"))) ;
          }
          const enumGalgasBool test_27 = test_26.boolEnum () ;
          if (kBoolTrue == test_27) {
            var_subTypes_53173 = var_boolType_55179.getter_falseSubAttributes (SOURCE_FILE ("arxml_parser.galgas", 1594)) ;
            var_booleanValue_55225 = GALGAS_bool (false) ;
          }else if (kBoolFalse == test_27) {
            var_booleanValue_55225 = GALGAS_bool (false) ;
            TC_Array <C_FixItDescription> fixItArray28 ;
            inCompiler->emitSemanticError (var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1598)), GALGAS_string ("A Boolean must be 'true', 'false', '0' or '1'"), fixItArray28  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1598)) ;
          }
        }
        {
        routine_displayOil (GALGAS_string (" = ").add_operation (var_booleanValue_55225.getter_cString (SOURCE_FILE ("arxml_parser.galgas", 1601)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1601)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1601)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1601)) ;
        }
        const enumGalgasBool test_29 = GALGAS_bool (kIsNotEqual, var_subTypes_53173.getter_count (SOURCE_FILE ("arxml_parser.galgas", 1602)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_29) {
          {
          routine_displayOil (GALGAS_string ("\n"
            "    {\n"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1603)) ;
          }
          {
          routine_arxmlDefinitionContainer (var_subTypes_53173, var_subAttributes_53246, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1604)) ;
          }
          {
          routine_displayOil (GALGAS_string ("    }"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1606)) ;
          }
        }
        {
        routine_displayOil (GALGAS_string (";"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1608)) ;
        }
        var_val_49732 = GALGAS_boolAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterType_49879.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1611)), var_booleanValue_55225, var_subAttributes_53246  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1610)) ;
      }else if (kBoolFalse == test_22) {
        const enumGalgasBool test_30 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1615)).objectCompare (GALGAS_string ("ECUC-INTEGER-PARAM-DEF"))).boolEnum () ;
        if (kBoolTrue == test_30) {
          GALGAS_bool var_sign_56460 ;
          {
          routine_arxmlPopSign (var_parameterValue_50587, var_sign_56460, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1619)) ;
          }
          GALGAS_luint_36__34_ var_integerValue_56488 = GALGAS_luint_36__34_::constructor_new (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1622)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1622)).getter_uint_36__34_ (SOURCE_FILE ("arxml_parser.galgas", 1622)), var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1623))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1621)) ;
          {
          routine_displayOil (GALGAS_string (" = ").add_operation (var_integerValue_56488.getter_uint_36__34_ (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 1625)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1625)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1625)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1625)) ;
          }
          var_val_49732 = function_checkAndGetIntegerNumber (var_oil_5F_desc_50397, var_type_49944.getter_type (SOURCE_FILE ("arxml_parser.galgas", 1627)), var_integerValue_56488, var_sign_56460, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1627)) ;
        }else if (kBoolFalse == test_30) {
          const enumGalgasBool test_31 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1629)).objectCompare (GALGAS_string ("ECUC-FLOAT-PARAM-DEF"))).boolEnum () ;
          if (kBoolTrue == test_31) {
            GALGAS_bool var_sign_57047 ;
            {
            routine_arxmlPopSign (var_parameterValue_50587, var_sign_57047, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1633)) ;
            }
            GALGAS_ldouble var_floatValue_57073 = GALGAS_ldouble::constructor_new (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1636)).getter_doubleNumber (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1636)), var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1637))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1635)) ;
            {
            routine_displayOil (GALGAS_string (" = ").add_operation (var_floatValue_57073.getter_double (HERE).getter_string (SOURCE_FILE ("arxml_parser.galgas", 1639)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1639)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1639)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1639)) ;
            }
            var_val_49732 = function_checkAndGetFloatNumber (var_oil_5F_desc_50397, var_type_49944.getter_type (SOURCE_FILE ("arxml_parser.galgas", 1641)), var_floatValue_57073, var_sign_57047, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1641)) ;
          }else if (kBoolFalse == test_31) {
            const enumGalgasBool test_32 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1643)).objectCompare (GALGAS_string ("ECUC-STRING-PARAM-DEF"))).boolEnum () ;
            if (kBoolTrue == test_32) {
              {
              routine_displayOil (GALGAS_string (" = \"").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1647)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1647)).add_operation (GALGAS_string ("\";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1647)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1647)) ;
              }
              var_val_49732 = GALGAS_stringAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1650)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1651))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1649)) ;
            }else if (kBoolFalse == test_32) {
              const enumGalgasBool test_33 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1653)).objectCompare (GALGAS_string ("ECUC-REFERENCE-DEF"))).boolEnum () ;
              if (kBoolTrue == test_33) {
                {
                routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1657)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1657)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1657)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1657)) ;
                }
                var_val_49732 = GALGAS_objectRefAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1660)), var_parameterValue_50587  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1659)) ;
              }else if (kBoolFalse == test_33) {
                const enumGalgasBool test_34 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1663)).objectCompare (GALGAS_string ("TPL-IDENTIFIER-DEF"))).boolEnum () ;
                if (kBoolTrue == test_34) {
                  {
                  routine_displayOil (GALGAS_string (" = ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1667)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1667)).add_operation (GALGAS_string (";"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1667)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1667)) ;
                  }
                  var_val_49732 = GALGAS_string_5F_class::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1670)), var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1671))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1669)) ;
                }else if (kBoolFalse == test_34) {
                  const enumGalgasBool test_35 = GALGAS_bool (kIsEqual, var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1673)).objectCompare (GALGAS_string ("ECUC-PARAM-CONF-CONTAINER-DEF"))).boolEnum () ;
                  if (kBoolTrue == test_35) {
                    GALGAS_impStructType temp_36 ;
                    if (var_type_49944.isValid ()) {
                      if (NULL != dynamic_cast <const cPtr_impStructType *> (var_type_49944.ptr ())) {
                        temp_36 = (cPtr_impStructType *) var_type_49944.ptr () ;
                      }else{
                        inCompiler->castError ("impStructType", var_type_49944.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_parser.galgas", 1677)) ;
                      }
                    }
                    GALGAS_impStructType var_structType_58962 = temp_36 ;
                    var_subTypes_53173 = var_structType_58962.getter_structAttributes (SOURCE_FILE ("arxml_parser.galgas", 1678)) ;
                    {
                    routine_displayOil (GALGAS_string (" ").add_operation (var_parameterValue_50587.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1680)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)).add_operation (GALGAS_string ("\n"
                      "    {\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1680)) ;
                    }
                    {
                    routine_arxmlDefinitionContainer (var_subTypes_53173, var_subAttributes_53246, inArgument_parameter, inArgument_parentPath, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1681)) ;
                    }
                    {
                    routine_displayOil (GALGAS_string ("    };"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1683)) ;
                    }
                    var_val_49732 = GALGAS_structAttribute::constructor_new (var_oil_5F_desc_50397, var_parameterValue_50587.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1686)), var_parameterValue_50587, var_subAttributes_53246  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1685)) ;
                  }else if (kBoolFalse == test_35) {
                    TC_Array <C_FixItDescription> fixItArray37 ;
                    inCompiler->emitSemanticError (var_valueType_50216.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1693)), GALGAS_string ("Undefined valueType ").add_operation (var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1693)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1693)), fixItArray37  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1693)) ;
                    var_val_49732.drop () ; // Release error dropped variable
                    var_typeOk_49920 = GALGAS_bool (false) ;
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
  routine_displayOil (GALGAS_string ("      /* ARXML Type :").add_operation (var_valueType_50216.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1697)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1697)).add_operation (GALGAS_string (" */\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1697)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1697)) ;
  }
  GALGAS_identifierMap var_idfs_59897 = ioArgument_identifiers.getter_objectParams (SOURCE_FILE ("arxml_parser.galgas", 1702)) ;
  const enumGalgasBool test_38 = var_type_49944.getter_multiple (SOURCE_FILE ("arxml_parser.galgas", 1703)).boolEnum () ;
  if (kBoolTrue == test_38) {
    const enumGalgasBool test_39 = var_idfs_59897.getter_hasKey (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1704)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1704)).boolEnum () ;
    if (kBoolTrue == test_39) {
      GALGAS_object_5F_t var_attributeList_60031 ;
      {
      var_idfs_59897.setter_del (var_parameterType_49879, var_attributeList_60031, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1708)) ;
      }
      if (var_attributeList_60031.isValid ()) {
        if (var_attributeList_60031.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
          GALGAS_multipleAttribute cast_60235_multiAttribute ((cPtr_multipleAttribute *) var_attributeList_60031.ptr ()) ;
          GALGAS_identifierList var_aList_60267 = cast_60235_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1711)) ;
          var_aList_60267.addAssign_operation (var_val_49732  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1712)) ;
          var_val_49732 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1713)), cast_60235_multiAttribute.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1714)), var_aList_60267  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1713)) ;
        }
      }
    }else if (kBoolFalse == test_39) {
      GALGAS_identifierList var_aList_60537 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1718)) ;
      GALGAS_object_5F_t var_defaultValue_60616 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_type_49944.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1720)) ;
      if (var_defaultValue_60616.isValid ()) {
        if (var_defaultValue_60616.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
          GALGAS_multipleAttribute cast_60745_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_60616.ptr ()) ;
          var_aList_60537 = cast_60745_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1725)) ;
        }
      }
      var_aList_60537.addAssign_operation (var_val_49732  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1730)) ;
      var_val_49732 = GALGAS_multipleAttribute::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1732)), var_val_49732.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1732)), var_aList_60537  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1732)) ;
    }
    const enumGalgasBool test_40 = var_idfs_59897.getter_hasKey (var_parameterType_49879.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1734)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1734)).boolEnum () ;
    if (kBoolTrue == test_40) {
      GALGAS_object_5F_t var_existingObject_61232 ;
      {
      var_idfs_59897.setter_del (var_parameterType_49879, var_existingObject_61232, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1738)) ;
      }
      {
      var_val_49732.insulate (HERE) ;
      cPtr_object_5F_t * ptr_61299 = (cPtr_object_5F_t *) var_val_49732.ptr () ;
      callExtensionSetter_mergeSubAttributes ((cPtr_object_5F_t *) ptr_61299, var_existingObject_61232, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1739)) ;
      }
    }
  }
  const enumGalgasBool test_41 = var_typeOk_49920.boolEnum () ;
  if (kBoolTrue == test_41) {
    {
    var_idfs_59897.setter_put (var_parameterType_49879, var_val_49732, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1745)) ;
    }
  }
  {
  ioArgument_identifiers.setter_setObjectParams (var_idfs_59897 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1747)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'testTypeError'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_testTypeError (GALGAS_dataType inArgument_type,
                            GALGAS_lstring inArgument_valueType,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1758)).objectCompare (inArgument_valueType.getter_string (HERE))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_valueType.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1759)), GALGAS_string ("Expected oil type ").add_operation (extensionGetter_oilType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)).add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)).add_operation (GALGAS_string (" Found "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)).add_operation (inArgument_valueType.getter_string (HERE), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1760)).add_operation (GALGAS_string (".\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1760)).add_operation (GALGAS_string (" Fix : Replace it with "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1760)).add_operation (extensionGetter_arxmlType (inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1761)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1761)), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1759)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'oilEquivalentName'                                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_oilEquivalentName (GALGAS_lstring inArgument_parentPath,
                                GALGAS_lstring inArgument_currentPath,
                                GALGAS_lstring & outArgument_outName,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outName.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1770)).objectCompare (inArgument_currentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1770)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    inArgument_parentPath.mProperty_string = inArgument_parentPath.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1771)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1771)) ;
  }
  GALGAS_lstring var_objectKind_62165 = GALGAS_lstring::constructor_new (inArgument_currentPath.getter_string (HERE).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1774)), inArgument_currentPath.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1775))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1774)) ;
  GALGAS_string var_lastParent_62458 = inArgument_parentPath.getter_string (HERE).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 1779)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1779)) ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_lastParent_62458.objectCompare (GALGAS_string ("OSOS"))).boolEnum () ;
  if (kBoolTrue == test_1) {
    var_lastParent_62458 = GALGAS_string ("OS") ;
  }
  GALGAS_uint var_lastParentLength_62702 = var_lastParent_62458.getter_length (SOURCE_FILE ("arxml_parser.galgas", 1787)) ;
  const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_objectKind_62165.getter_string (HERE).getter_leftSubString (var_lastParentLength_62702 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1788)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1788)).objectCompare (var_lastParent_62458)).boolEnum () ;
  if (kBoolTrue == test_2) {
    var_objectKind_62165.mProperty_string = var_objectKind_62165.getter_string (HERE).getter_subStringFromIndex (var_lastParentLength_62702 COMMA_SOURCE_FILE ("arxml_parser.galgas", 1790)) ;
    var_objectKind_62165.mProperty_string = var_objectKind_62165.getter_string (HERE).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1791)) ;
    outArgument_outName = var_objectKind_62165 ;
  }else if (kBoolFalse == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (var_objectKind_62165.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1794)), GALGAS_string ("An object must be named by its Parent.\n"
      " ").add_operation (GALGAS_string ("Ex : If Task object has Os parent, then the DEFINITION-REF must be "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1794)).add_operation (GALGAS_string ("(...)/Os/OsTask.\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1795)).add_operation (GALGAS_string ("Fix : Add \""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1796)).add_operation (var_lastParent_62458, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1797)).add_operation (GALGAS_string ("\" to the name of your property."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1797)), fixItArray3  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1794)) ;
    outArgument_outName.drop () ; // Release error dropped variable
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                            Routine 'arxmlGetDescription'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlGetDescription (GALGAS_arxmlElementValue inArgument_packageElement,
                                  GALGAS_lstring & outArgument_description,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_description.drop () ; // Release 'out' argument
  outArgument_description = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1806))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1806)) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1809)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_arxmlElementValue var_desc_63571 ;
    callExtensionMethod_getElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("DESC"), var_desc_63571, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1810)) ;
    callExtensionMethod_getAllTextsInSelf ((const cPtr_arxmlElementValue *) var_desc_63571.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1811)) ;
  }
  const enumGalgasBool test_1 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1813)).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_arxmlElementValue var_desc_63752 ;
    callExtensionMethod_getElement ((const cPtr_arxmlElementValue *) inArgument_packageElement.ptr (), GALGAS_string ("INTRODUCTION"), var_desc_63752, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1814)) ;
    callExtensionMethod_getAllTextsInSelf ((const cPtr_arxmlElementValue *) var_desc_63752.ptr (), GALGAS_string (" "), outArgument_description, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1815)) ;
  }
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1819)).getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1819)) ;
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1822)).getter_stringByReplacingStringByString (GALGAS_string ("\r"), GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1822)) ;
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1825)).getter_stringByReplacingStringByString (GALGAS_string ("\\"), GALGAS_string ("\\\\"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1825)) ;
  outArgument_description.mProperty_string = outArgument_description.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1828)).getter_stringByReplacingStringByString (GALGAS_string ("\""), GALGAS_string ("\\\""), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1828)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                Routine 'displayOil'                                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_displayOil (GALGAS_string inArgument_string,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (gOption_goil_5F_options_arxmlDisplayOil.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    inCompiler->printMessage (inArgument_string  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1837)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                           Routine 'arxmlGetMultiplicity'                                            *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlGetMultiplicity (GALGAS_arxmlElementValue inArgument_element,
                                   GALGAS_lstring inArgument_objectName,
                                   GALGAS_lbool & outArgument_multiple,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_multiple.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1846)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_smultiple_64795 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_element.ptr (), GALGAS_string ("UPPER-MULTIPLICITY-INFINITE"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1847)) ;
    GALGAS_bool test_1 = GALGAS_bool (kIsEqual, var_smultiple_64795.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1849)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1849)).objectCompare (GALGAS_string ("TRUE"))) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      test_1 = GALGAS_bool (kIsEqual, var_smultiple_64795.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1850)).objectCompare (GALGAS_string ("1"))) ;
    }
    const enumGalgasBool test_2 = test_1.boolEnum () ;
    if (kBoolTrue == test_2) {
      outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (true), var_smultiple_64795.getter_location (HERE)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1851)) ;
      {
      routine_displayOil (GALGAS_string ("[]"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1852)) ;
      }
    }else if (kBoolFalse == test_2) {
      outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), var_smultiple_64795.getter_location (HERE)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1854)) ;
    }
  }else if (kBoolFalse == test_0) {
    outArgument_multiple = GALGAS_lbool::constructor_new (GALGAS_bool (false), inArgument_objectName.getter_location (HERE)  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1857)) ;
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'arxmlPopSign'                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlPopSign (GALGAS_lstring & ioArgument_value,
                           GALGAS_bool & outArgument_sign,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_sign.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, ioArgument_value.getter_string (HERE).getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1866)).objectCompare (GALGAS_char (TO_UNICODE (45)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_sign = GALGAS_bool (true) ;
    ioArgument_value.mProperty_string = ioArgument_value.getter_string (HERE).getter_subStringFromIndex (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1868)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, ioArgument_value.getter_string (HERE).getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1869)).objectCompare (GALGAS_char (TO_UNICODE (43)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_sign = GALGAS_bool (false) ;
      ioArgument_value.mProperty_string = ioArgument_value.getter_string (HERE).getter_subStringFromIndex (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1871)) ;
    }else if (kBoolFalse == test_1) {
      outArgument_sign = GALGAS_bool (false) ;
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                             Routine 'arxmlGetWithAuto'                                              *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlGetWithAuto (GALGAS_arxmlElementValue inArgument_parameter,
                               GALGAS_bool & outArgument_withAuto,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_withAuto.drop () ; // Release 'out' argument
  outArgument_withAuto = GALGAS_bool (false) ;
  const enumGalgasBool test_0 = callExtensionGetter_hasElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1882)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_autoString_65700 = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("WITH-AUTO"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1883)) ;
    GALGAS_bool test_1 = GALGAS_bool (kIsEqual, var_autoString_65700.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1884)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1884)).objectCompare (GALGAS_string ("TRUE"))) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      test_1 = GALGAS_bool (kIsEqual, var_autoString_65700.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1885)).objectCompare (GALGAS_string ("1"))) ;
    }
    const enumGalgasBool test_2 = test_1.boolEnum () ;
    if (kBoolTrue == test_2) {
      outArgument_withAuto = GALGAS_bool (true) ;
      {
      routine_displayOil (GALGAS_string (" WITH_AUTO"), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1887)) ;
      }
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'arxmlGetName'                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlGetName (GALGAS_arxmlElementValue inArgument_parameter,
                           GALGAS_lstring & outArgument_objectName,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_objectName.drop () ; // Release 'out' argument
  outArgument_objectName = callExtensionGetter_getTextFromElement ((const cPtr_arxmlElementValue *) inArgument_parameter.ptr (), GALGAS_string ("SHORT-NAME"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1897)) ;
  outArgument_objectName.mProperty_string = outArgument_objectName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1898)).getter_uppercaseString (SOURCE_FILE ("arxml_parser.galgas", 1898)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                        Routine 'arxmlInsertObjectAttribute'                                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_arxmlInsertObjectAttribute (GALGAS_implementationObjectMap & ioArgument_objectAttributes,
                                         GALGAS_lstring inArgument_attributeName,
                                         GALGAS_impType inArgument_type,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = ioArgument_objectAttributes.getter_hasKey (inArgument_attributeName.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1906)) COMMA_SOURCE_FILE ("arxml_parser.galgas", 1906)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_previousType_66335 ;
    ioArgument_objectAttributes.method_get (inArgument_attributeName, var_previousType_66335, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1908)) ;
    const enumGalgasBool test_1 = var_previousType_66335.getter_multiple (SOURCE_FILE ("arxml_parser.galgas", 1911)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_object_5F_t var_previousDefaultValue_66673 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) var_previousType_66335.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1914)) ;
      GALGAS_object_5F_t var_defaultValue_66735 = callExtensionGetter_getDefaultValue ((const cPtr_impType *) inArgument_type.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1915)) ;
      GALGAS_bool var_oneIsMultiple_66786 = GALGAS_bool (false) ;
      const enumGalgasBool test_2 = GALGAS_bool (var_previousDefaultValue_66673.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_oneIsMultiple_66786 = GALGAS_bool (true) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (var_defaultValue_66735.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_oneIsMultiple_66786 = GALGAS_bool (true) ;
        }
      }
      const enumGalgasBool test_4 = var_oneIsMultiple_66786.boolEnum () ;
      if (kBoolTrue == test_4) {
        GALGAS_identifierList var_aList_67189 = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 1926)) ;
        GALGAS_lstring var_desc_67224 = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1927)) ;
        GALGAS_location var_location_67268 = GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1928)) ;
        if (var_previousDefaultValue_66673.isValid ()) {
          if (var_previousDefaultValue_66673.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
            GALGAS_multipleAttribute cast_67394_multiAttribute ((cPtr_multipleAttribute *) var_previousDefaultValue_66673.ptr ()) ;
            var_aList_67189 = cast_67394_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1933)) ;
            var_desc_67224 = cast_67394_multiAttribute.getter_oil_5F_desc (SOURCE_FILE ("arxml_parser.galgas", 1934)) ;
            var_location_67268 = cast_67394_multiAttribute.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1935)) ;
          }
        }
        if (var_defaultValue_66735.isValid ()) {
          if (var_defaultValue_66735.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
            GALGAS_multipleAttribute cast_67654_multiAttribute ((cPtr_multipleAttribute *) var_defaultValue_66735.ptr ()) ;
            var_aList_67189.plusAssign_operation(cast_67654_multiAttribute.getter_items (SOURCE_FILE ("arxml_parser.galgas", 1941)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1941)) ;
            const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, var_desc_67224.getter_string (SOURCE_FILE ("arxml_parser.galgas", 1942)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              var_desc_67224 = cast_67654_multiAttribute.getter_oil_5F_desc (SOURCE_FILE ("arxml_parser.galgas", 1943)) ;
            }
            const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_location_67268.objectCompare (GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_parser.galgas", 1945)))).boolEnum () ;
            if (kBoolTrue == test_6) {
              var_location_67268 = cast_67654_multiAttribute.getter_location (SOURCE_FILE ("arxml_parser.galgas", 1946)) ;
            }
          }
        }
        GALGAS_object_5F_t var_newDefault_67983 = GALGAS_multipleAttribute::constructor_new (var_desc_67224, var_location_67268, var_aList_67189  COMMA_SOURCE_FILE ("arxml_parser.galgas", 1951)) ;
        {
        inArgument_type.insulate (HERE) ;
        cPtr_impType * ptr_68085 = (cPtr_impType *) inArgument_type.ptr () ;
        callExtensionSetter_setDefaultValue ((cPtr_impType *) ptr_68085, var_newDefault_67983, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1954)) ;
        }
        {
        GALGAS_impType joker_68164 ; // Joker input parameter
        ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68164, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1956)) ;
        }
        {
        ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1957)) ;
        }
      }
    }
    const enumGalgasBool test_7 = function_checkNewTypeWithinPreviousType (inArgument_attributeName, var_previousType_66335, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1961)).boolEnum () ;
    if (kBoolTrue == test_7) {
      {
      GALGAS_impType joker_68448 ; // Joker input parameter
      ioArgument_objectAttributes.setter_del (inArgument_attributeName, joker_68448, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1964)) ;
      }
      {
      ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1965)) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    {
    ioArgument_objectAttributes.setter_put (inArgument_attributeName, inArgument_type, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 1968)) ;
    }
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension method '@arxmlElementNode print'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlElementNode_print (const cPtr_arxmlNode * inObject,
                                                    const GALGAS_uint constinArgument_indentation,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  GALGAS_string var_indent_3618 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 172)) ;
  inCompiler->printMessage (var_indent_3618  COMMA_SOURCE_FILE ("arxml_types.galgas", 173)) ;
  inCompiler->printMessage (GALGAS_string ("NODE \"").add_operation (object->mProperty_name.getter_string (SOURCE_FILE ("arxml_types.galgas", 174)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174)).add_operation (GALGAS_string ("\" "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 174))  COMMA_SOURCE_FILE ("arxml_types.galgas", 174)) ;
  extensionMethod_print (object->mProperty_attributes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 175)) ;
  inCompiler->printMessage (GALGAS_string ("\n")  COMMA_SOURCE_FILE ("arxml_types.galgas", 176)) ;
  extensionMethod_print (object->mProperty_enclosedNodes, constinArgument_indentation, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 177)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlElementNode_print (void) {
  enterExtensionMethod_print (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                              extensionMethod_arxmlElementNode_print) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlElementNode_print (defineExtensionMethod_arxmlElementNode_print, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Overriding extension method '@arxmlElementNode getElementsFromName'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlElementNode_getElementsFromName (const cPtr_arxmlNode * inObject,
                                                                  const GALGAS_string constinArgument_nodeName,
                                                                  GALGAS_arxmlElementList & ioArgument_nodeList,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (object->mProperty_name.getter_string (SOURCE_FILE ("arxml_types.galgas", 184)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const GALGAS_arxmlElementNode temp_1 = object ;
    ioArgument_nodeList.addAssign_operation (temp_1  COMMA_SOURCE_FILE ("arxml_types.galgas", 185)) ;
  }
  extensionMethod_getElementsFromName (object->mProperty_enclosedNodes, constinArgument_nodeName, ioArgument_nodeList, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 188)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlElementNode_getElementsFromName (void) {
  enterExtensionMethod_getElementsFromName (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                            extensionMethod_arxmlElementNode_getElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlElementNode_getElementsFromName (defineExtensionMethod_arxmlElementNode_getElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@arxmlElementNode getSubElementsFromName'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlElementNode_getSubElementsFromName (const cPtr_arxmlNode * inObject,
                                                                     const GALGAS_string constinArgument_nodeName,
                                                                     GALGAS_arxmlElementList & ioArgument_nodeList,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  cEnumerator_arxmlNodeList enumerator_4206 (object->mProperty_enclosedNodes, kENUMERATION_UP) ;
  while (enumerator_4206.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (enumerator_4206.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlElementNode).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_arxmlElementNode temp_1 ;
      if (enumerator_4206.current_node (HERE).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_arxmlElementNode *> (enumerator_4206.current_node (HERE).ptr ())) {
          temp_1 = (cPtr_arxmlElementNode *) enumerator_4206.current_node (HERE).ptr () ;
        }else{
          inCompiler->castError ("arxmlElementNode", enumerator_4206.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 197)) ;
        }
      }
      GALGAS_arxmlElementNode var_currentElement_4296 = temp_1 ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_currentElement_4296.getter_name (SOURCE_FILE ("arxml_types.galgas", 198)).getter_string (HERE).objectCompare (constinArgument_nodeName)).boolEnum () ;
      if (kBoolTrue == test_2) {
        ioArgument_nodeList.addAssign_operation (var_currentElement_4296  COMMA_SOURCE_FILE ("arxml_types.galgas", 199)) ;
      }
    }
    enumerator_4206.gotoNextObject () ;
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlElementNode_getSubElementsFromName (void) {
  enterExtensionMethod_getSubElementsFromName (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                               extensionMethod_arxmlElementNode_getSubElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlElementNode_getSubElementsFromName (defineExtensionMethod_arxmlElementNode_getSubElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                             Overriding extension method '@arxmlElementNode getProperty'                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlElementNode_getProperty (const cPtr_arxmlNode * inObject,
                                                          const GALGAS_string constinArgument_nodeName,
                                                          GALGAS_lstring & ioArgument_value,
                                                          GALGAS_bool & ioArgument_found,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = (const cPtr_arxmlElementNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_nodeName.objectCompare (object->mProperty_name.getter_string (SOURCE_FILE ("arxml_types.galgas", 223)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const GALGAS_arxmlElementNode temp_1 = object ;
    callExtensionMethod_getText ((const cPtr_arxmlElementNode *) temp_1.ptr (), ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 224)) ;
  }
  const enumGalgasBool test_2 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 227)).boolEnum () ;
  if (kBoolTrue == test_2) {
    cEnumerator_arxmlNodeList enumerator_4993 (object->mProperty_enclosedNodes, kENUMERATION_UP) ;
    bool bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
    if (enumerator_4993.hasCurrentObject () && bool_3) {
      while (enumerator_4993.hasCurrentObject () && bool_3) {
        callExtensionMethod_getProperty ((const cPtr_arxmlNode *) enumerator_4993.current_node (HERE).ptr (), constinArgument_nodeName, ioArgument_value, ioArgument_found, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 231)) ;
        enumerator_4993.gotoNextObject () ;
        if (enumerator_4993.hasCurrentObject ()) {
          bool_3 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 229)).isValidAndTrue () ;
        }
      }
    }
  }
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlElementNode_getProperty (void) {
  enterExtensionMethod_getProperty (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                    extensionMethod_arxmlElementNode_getProperty) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlElementNode_getProperty (defineExtensionMethod_arxmlElementNode_getProperty, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                Overriding extension method '@arxmlCommentNode print'                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlCommentNode_print (const cPtr_arxmlNode * inObject,
                                                    const GALGAS_uint constinArgument_indentation,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlCommentNode * object = (const cPtr_arxmlCommentNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlCommentNode) ;
  GALGAS_string var_indent_5992 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 281)) ;
  inCompiler->printMessage (var_indent_5992  COMMA_SOURCE_FILE ("arxml_types.galgas", 282)) ;
  inCompiler->printMessage (GALGAS_string ("COMMENT \"").add_operation (object->mProperty_comment.getter_string (SOURCE_FILE ("arxml_types.galgas", 283)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 283))  COMMA_SOURCE_FILE ("arxml_types.galgas", 283)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlCommentNode_print (void) {
  enterExtensionMethod_print (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                              extensionMethod_arxmlCommentNode_print) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlCommentNode_print (defineExtensionMethod_arxmlCommentNode_print, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Overriding extension method '@arxmlCommentNode getElementsFromName'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlCommentNode_getElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                                  const GALGAS_string /* constinArgument_nodeName */,
                                                                  GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlCommentNode_getElementsFromName (void) {
  enterExtensionMethod_getElementsFromName (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                                            extensionMethod_arxmlCommentNode_getElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlCommentNode_getElementsFromName (defineExtensionMethod_arxmlCommentNode_getElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                       Overriding extension method '@arxmlCommentNode getSubElementsFromName'                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlCommentNode_getSubElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                                     const GALGAS_string /* constinArgument_nodeName */,
                                                                     GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                                     C_Compiler * /* inCompiler */
                                                                     COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlCommentNode_getSubElementsFromName (void) {
  enterExtensionMethod_getSubElementsFromName (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                                               extensionMethod_arxmlCommentNode_getSubElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlCommentNode_getSubElementsFromName (defineExtensionMethod_arxmlCommentNode_getSubElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                             Overriding extension method '@arxmlCommentNode getProperty'                             *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlCommentNode_getProperty (const cPtr_arxmlNode * /* inObject */,
                                                          const GALGAS_string /* constinArgument_nodeName */,
                                                          GALGAS_lstring & /* ioArgument_value */,
                                                          GALGAS_bool & /* ioArgument_found */,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlCommentNode_getProperty (void) {
  enterExtensionMethod_getProperty (kTypeDescriptor_GALGAS_arxmlCommentNode.mSlotID,
                                    extensionMethod_arxmlCommentNode_getProperty) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlCommentNode_getProperty (defineExtensionMethod_arxmlCommentNode_getProperty, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                 Overriding extension method '@arxmlTextNode print'                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlTextNode_print (const cPtr_arxmlNode * inObject,
                                                 const GALGAS_uint constinArgument_indentation,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlTextNode * object = (const cPtr_arxmlTextNode *) inObject ;
  macroValidSharedObject (object, cPtr_arxmlTextNode) ;
  GALGAS_string var_indent_6749 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_indentation  COMMA_SOURCE_FILE ("arxml_types.galgas", 316)) ;
  inCompiler->printMessage (var_indent_6749  COMMA_SOURCE_FILE ("arxml_types.galgas", 317)) ;
  inCompiler->printMessage (GALGAS_string ("TEXT \"").add_operation (object->mProperty_text.getter_string (SOURCE_FILE ("arxml_types.galgas", 318)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 318))  COMMA_SOURCE_FILE ("arxml_types.galgas", 318)) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlTextNode_print (void) {
  enterExtensionMethod_print (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                              extensionMethod_arxmlTextNode_print) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlTextNode_print (defineExtensionMethod_arxmlTextNode_print, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                          Overriding extension method '@arxmlTextNode getElementsFromName'                           *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlTextNode_getElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                               const GALGAS_string /* constinArgument_nodeName */,
                                                               GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                               C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlTextNode_getElementsFromName (void) {
  enterExtensionMethod_getElementsFromName (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                            extensionMethod_arxmlTextNode_getElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlTextNode_getElementsFromName (defineExtensionMethod_arxmlTextNode_getElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                         Overriding extension method '@arxmlTextNode getSubElementsFromName'                         *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlTextNode_getSubElementsFromName (const cPtr_arxmlNode * /* inObject */,
                                                                  const GALGAS_string /* constinArgument_nodeName */,
                                                                  GALGAS_arxmlElementList & /* ioArgument_nodeList */,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlTextNode_getSubElementsFromName (void) {
  enterExtensionMethod_getSubElementsFromName (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                               extensionMethod_arxmlTextNode_getSubElementsFromName) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlTextNode_getSubElementsFromName (defineExtensionMethod_arxmlTextNode_getSubElementsFromName, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                              Overriding extension method '@arxmlTextNode getProperty'                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void extensionMethod_arxmlTextNode_getProperty (const cPtr_arxmlNode * /* inObject */,
                                                       const GALGAS_string /* constinArgument_nodeName */,
                                                       GALGAS_lstring & /* ioArgument_value */,
                                                       GALGAS_bool & /* ioArgument_found */,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void defineExtensionMethod_arxmlTextNode_getProperty (void) {
  enterExtensionMethod_getProperty (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                    extensionMethod_arxmlTextNode_getProperty) ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

C_PrologueEpilogue gMethod_arxmlTextNode_getProperty (defineExtensionMethod_arxmlTextNode_getProperty, NULL) ;

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                Routine 'lstringhere'                                                *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_lstringhere (GALGAS_lstring & outArgument_string,
                          GALGAS_string inArgument_value,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_string.drop () ; // Release 'out' argument
  outArgument_string = GALGAS_lstring::constructor_new (inArgument_value, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1193))  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1193)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                Routine 'fillLegacy'                                                 *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

void routine_fillLegacy (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                         GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist var_sortedInfoList_33628 = ioArgument_classGraph.getter_keyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1200)) ;
  cEnumerator_stringlist enumerator_33697 (var_sortedInfoList_33628, kENUMERATION_UP) ;
  while (enumerator_33697.hasCurrentObject ()) {
    GALGAS_lstring var_lClassName_33737 ;
    {
    routine_lstringhere (var_lClassName_33737, enumerator_33697.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1203)) ;
    }
    GALGAS_arxmlMetaClass var_lClass_33777 ;
    ioArgument_classMap.method_searchKey (var_lClassName_33737, var_lClass_33777, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1205)) ;
    GALGAS_lstringlist var_fromList_33870 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1208)) ;
    {
    var_fromList_33870.setter_insertAtIndex (var_lClass_33777.getter_name (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1209)), GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1209)) ;
    }
    GALGAS_stringset var_empty_33945 = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1210)) ;
    GALGAS_lstringlist var_successorList_33988 = ioArgument_classGraph.getter_accessibleNodesFrom (var_fromList_33870, var_empty_33945, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1211)) ;
    {
    var_lClass_33777.insulate (HERE) ;
    cPtr_arxmlMetaClass * ptr_34134 = (cPtr_arxmlMetaClass *) var_lClass_33777.ptr () ;
    callExtensionSetter_legacyAddParameters ((cPtr_arxmlMetaClass *) ptr_34134, ioArgument_classMap, var_successorList_33988, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1214)) ;
    }
    enumerator_33697.gotoNextObject () ;
  }
}


#include "project_header.h"
#include "command_line_interface/F_mainForLIBPM.h"
#include "command_line_interface/F_Analyze_CLI_Options.h"
#include "utilities/F_DisplayException.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "galgas2/F_verbose_output.h"
#include "galgas2/cLexiqueIntrospection.h"
#include "command_line_interface/C_builtin_CLI_Options.h"

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      print_tool_help_message                                                                        *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void print_tool_help_message (void) {
  co << "Compiled with GALGAS revision NUMERO_REVISION_GALGAS\n" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * kSourceFileExtensions [] = {
  "oil",
  "OIL",
  "goilTemplate",
  "arxml",
  NULL
} ;    

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static const char * kSourceFileHelpMessages [] = {
  "an '.oil' source file",
  "an '.OIL' source file",
  "a Goil template file",
  "an AUTOSAR arxml configuration file",
  NULL
} ;    

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

const char * projectVersionString (void) {
  return "3.1.10" ;
}

//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                  Routine 'before'                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_before (C_Compiler * /* inCompiler */
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                                   Routine 'after'                                                   *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_after (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  }
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_0'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__30_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 33)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 34)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_1'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__31_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 38)) ;
  }
  cGrammar_goil_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile  COMMA_SOURCE_FILE ("goil_program.galgas", 39)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_2'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__32_ (const GALGAS_lstring /* constinArgument_inSourceFile */,
                                         C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                                               Routine 'programRule_3'                                               *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

static void routine_programRule_5F__33_ (const GALGAS_lstring constinArgument_inSourceFile,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_checkTemplatesPath (inCompiler  COMMA_SOURCE_FILE ("goil_program.galgas", 48)) ;
  }
  GALGAS_arxmlNode var_root_1353 ;
  var_root_1353.drop () ;
  cGrammar_arxml_5F_grammar::_performSourceFileParsing_ (inCompiler, constinArgument_inSourceFile, var_root_1353, GALGAS_bool (true), GALGAS_bool (true)  COMMA_SOURCE_FILE ("goil_program.galgas", 49)) ;
  callExtensionMethod_print ((const cPtr_arxmlNode *) var_root_1353.ptr (), GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_program.galgas", 53)) ;
}


//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*
//                                                                                                                     *
//                      M A I N    F O R    L I B P M                                                                  *
//                                                                                                                     *
//—————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*

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
    C_Compiler * commonCompiler = NULL ;
    macroMyNew (commonCompiler, C_Compiler (NULL COMMA_HERE)) ;
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
    }catch (const ::std:: exception & e) {
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

