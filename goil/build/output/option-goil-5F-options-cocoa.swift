//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//----------------------------------------------------------------------------------------------------------------------

func enterOptions (_ ioBoolOptionArray : inout [SWIFT_CommandLineOption],
                   _ ioUIntOptionArray : inout [SWIFT_CommandLineOption],
                   _ ioStringOptionArray : inout [SWIFT_CommandLineOption],
                   _ ioStringListOptionArray : inout [SWIFT_CommandLineOption]) {
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "arxmlDisplayOil",
    commandChar: "",
    commandString: "arxmlPrintOil",
    comment: "Display an Oil version while parsing an arxml file",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "generate_log",
    commandChar: "l",
    commandString: "logfile",
    comment: "generate a goil.log file containing the a log of the compilation",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "pierreOption",
    commandChar: "",
    commandString: "pierre",
    comment: "Special option to pass a galgas bug to Pierre",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "warnMultiple",
    commandChar: "",
    commandString: "warn-multiple",
    comment: "Emit a warning if an object not defined for the first time in the implementation does not have the same multiple attribute as in the first definition",
    defaultValue: ""
  ))
  ioStringOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "config",
    commandChar: "c",
    commandString: "config",
    comment: "Specifies the OIL config file used by goil",
    defaultValue: "config"
  ))
  ioStringOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "passOption",
    commandChar: "o",
    commandString: "option",
    comment: "Pass options to the template root script",
    defaultValue: ""
  ))
  ioStringOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "project_dir",
    commandChar: "p",
    commandString: "project",
    comment: "Specifies project directory (by default, the project directory is the name of the oil file, without the .oil extension)",
    defaultValue: ""
  ))
  ioStringOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "root",
    commandChar: "r",
    commandString: "root",
    comment: "Specifies the root template file to use to generate the output files",
    defaultValue: "root"
  ))
  ioStringOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "target_platform",
    commandChar: "t",
    commandString: "target",
    comment: "Specifies target platform. Available target platform are located in machines/ directory. Targets are specified using a path like avr/arduino.",
    defaultValue: ""
  ))
  ioStringOptionArray.append (SWIFT_CommandLineOption (
    domainName: "goil_options",
    identifier: "template_dir",
    commandChar: "",
    commandString: "templates",
    comment: "Specifies template directory (used by goil for code generation)",
    defaultValue: ""
  ))
  ioBoolOptionArray.append (SWIFT_CommandLineOption (
    domainName: "galgas_cli_options",
    identifier: "quiet_output",
    commandChar: "q",
    commandString: "quiet",
    comment: "Quiet output",
    defaultValue: ""
  ))
}

//----------------------------------------------------------------------------------------------------------------------

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2


