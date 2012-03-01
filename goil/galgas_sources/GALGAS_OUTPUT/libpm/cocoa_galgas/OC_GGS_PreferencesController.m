//---------------------------------------------------------------------------*
//                                                                           *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2003, ..., 2011 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#import "OC_GGS_PreferencesController.h"
#import "OC_GGS_Document.h"
#import "PMFontButton.h"
#import "OC_GGS_CommandLineOption.h"
#import "enterDefaultCommandLineOptions.h"
#import "OC_Lexique.h"
#import "PMCocoaCallsDebug.h"
#import "F_CocoaWrapperForGalgas.h"
#import "OC_GGS_BuildTask.h"

//---------------------------------------------------------------------------*

OC_GGS_PreferencesController * gCocoaGalgasPreferencesController ;

//---------------------------------------------------------------------------*

@implementation OC_GGS_PreferencesController

//---------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    gCocoaGalgasPreferencesController = self ;
    mToolNameArray = [[NSMutableArray alloc] init] ;
  //--- Get command line option list
    mBoolOptionArray = [NSMutableArray new] ;
    mUIntOptionArray = [NSMutableArray new] ;
    mStringOptionArray = [NSMutableArray new] ;
    enterDefaultCommandLineOptions (mBoolOptionArray, mUIntOptionArray, mStringOptionArray) ;
    enterOptions (mBoolOptionArray, mUIntOptionArray, mStringOptionArray) ;
  }
  return self ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   S E T    A P P L I C A T I O N    M E N U    I T E M    T I T L E S     *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) setApplicationMenuItemTitles {
//--- Get application name
  NSDictionary * bundleDictionary = [[NSBundle mainBundle] localizedInfoDictionary] ;
  NSString * applicationName = [bundleDictionary objectForKey: @"CFBundleName"] ;
  if (applicationName != nil) {
  //--- Get menubar : it is application main menu
    NSMenu * menu = [NSApp mainMenu] ;
    menu = [[menu itemAtIndex: 0] submenu] ;
    const NSInteger itemsCount = [menu numberOfItems] ;
    NSInteger i ;
    for (i=0 ; i<itemsCount ; i++) {
      NSMenuItem * item = [menu itemAtIndex: i] ;
      NSString * itemTitle = [item title] ;
      NSMutableString * newItemTitle = [NSMutableString new] ;
      [newItemTitle appendString: itemTitle] ;
      if ([itemTitle isEqualToString: @"About"]) {
        [newItemTitle appendString: @" "] ;
        [newItemTitle appendString: applicationName] ;
      }else if ([itemTitle isEqualToString: @"Hide"]) {
        [newItemTitle appendString: @" "] ;
        [newItemTitle appendString: applicationName] ;
      }else if ([itemTitle isEqualToString: @"Quit"]) {
        [newItemTitle appendString: @" "] ;
        [newItemTitle appendString: applicationName] ;
      }
      [item setTitle: newItemTitle] ;
    }
  }
}

//---------------------------------------------------------------------------*

- (NSArray *) commandLineItemArray {
  return mCommandLineItemArray ;
}

//---------------------------------------------------------------------------*

- (NSTabView *) preferencesTabView {
  return mPreferencesTabView ;
}

//---------------------------------------------------------------------------*

- (NSString *) compilerToolPath {
  NSString * result = @"?" ; // No compiler by default
  const NSInteger indexOfSelectedItem = [mToolPopUpButton indexOfSelectedItem] ;
  if (indexOfSelectedItem >= 0) {
    NSBundle * mb = [NSBundle mainBundle] ;
    NSString * rp = [mb resourcePath] ;
    result = [rp stringByAppendingPathComponent:[mToolNameArray objectAtIndex:indexOfSelectedItem HERE]] ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

- (NSString *) commandLineString {
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
  NSMutableArray * arguments = [NSMutableArray new] ;
//--- Add tool path
  [arguments addObject:[self compilerToolPath]] ;
//--- Add --xml option
 [arguments addObject: @"--xml"] ;
//--- Add boolean options
  for (NSUInteger i=0 ; i<[mBoolOptionArray count] ; i++) {
    OC_GGS_CommandLineOption * option = [mBoolOptionArray objectAtIndex:i HERE] ;
    const bool optionValue = [defaults integerForKey: [NSString stringWithFormat:@"%@_%@", GGS_bool_build_option, [option identifier]]] != 0 ;
    if (optionValue) {
      const char c = [option commandChar] ;
      if (c != '\0') {
        [arguments addObject: [NSString stringWithFormat: @"-%c", c]] ;
      }else{
        NSString * s = [option commandString] ;
        if ([s length] != 0) {
          [arguments addObject: [NSString stringWithFormat: @"--%@", s]] ;
        }
      }
    }
  }
//--- Add integer options
  for (NSUInteger i=0 ; i<[mUIntOptionArray count] ; i++) {
    OC_GGS_CommandLineOption * option = [mUIntOptionArray objectAtIndex:i HERE] ;
    const NSUInteger optionValue = [defaults integerForKey: [NSString stringWithFormat:@"%@_%@", GGS_uint_build_option, [option identifier]]];
    if (optionValue != 0) {
      const char c = [option commandChar] ;
      if (c != '\0') {
        [arguments addObject: [NSString stringWithFormat: @"-%c=%lu", c, optionValue]] ;
      }else{
        NSString * s = [option commandString] ;
        if ([s length] != 0) {
          [arguments addObject: [NSString stringWithFormat: @"--%@=%lu", s, optionValue]] ;
        }
      }
    }
  }
//--- Add string options
  for (NSUInteger i=0 ; i<[mStringOptionArray count] ; i++) {
    OC_GGS_CommandLineOption * option = [mStringOptionArray objectAtIndex:i HERE] ;
    NSString * optionValue = [defaults objectForKey: [NSString stringWithFormat:@"%@_%@", GGS_string_build_option, [option identifier]]];
    if ([optionValue length] > 0) {
      const char c = [option commandChar] ;
      if (c != '\0') {
        [arguments addObject: [NSString stringWithFormat: @"-%c=%@", c, optionValue]] ;
      }else{
        NSString * s = [option commandString] ;
        if ([s length] != 0) {
          [arguments addObject: [NSString stringWithFormat: @"--%@=%@", s, optionValue]] ;
        }
      }
    }
  }
//--- Assign command line option array attribute
  mCommandLineItemArray = arguments ;
//---- Build string for displaying
  NSMutableString * s = [NSMutableString new] ;
  for (NSUInteger i=0 ; i<[arguments count] ; i++) {
    [s appendString:[arguments objectAtIndex:i HERE]] ;
    [s appendString:@" "] ;  
  }
//---
  return s ;
}

//---------------------------------------------------------------------------*

#pragma mark Lexical Coloring

//---------------------------------------------------------------------------*
//                                                                           *
//       S E T    T E X T    C O L O R S    P R E F E R E N C E S            *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) setUpView: (NSView *) ioView
         withCurrentRectangle: (NSRect *) ioRect
         withEnclosingRectangle: (NSRect *) ioEnclosingRect
         withBackgroundColorBindingPath: (NSString *) inBackgroundBindingPath
         withFontBindingPath: (NSString *) inFontBindingPath
         withForegroundColorBindingPath: (NSString *) inForegroundBindingPath
         withSettingTitle: (NSString *) inTitle {
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
//--- Add background color well
  ioRect->origin.x = 10.0 ;
  ioRect->size.width = 40.0 ;
  NSColorWell * colorWell = [[NSColorWell alloc] initWithFrame:*ioRect] ;
  [colorWell setAutoresizingMask: NSViewMaxXMargin | NSViewMinYMargin] ;
  [colorWell
    bind:@"value"
    toObject:udc
    withKeyPath:inBackgroundBindingPath
    options:[NSDictionary dictionaryWithObject:NSUnarchiveFromDataTransformerName forKey:NSValueTransformerNameBindingOption]
  ] ;
  [ioView addSubview:colorWell] ;
  *ioEnclosingRect = NSUnionRect (*ioEnclosingRect, *ioRect) ;
//--- Add "Font" button
  ioRect->origin.x += 50.0 ;
  ioRect->size.width = 200.0 ;
  NSButton * cb = [[PMFontButton alloc] initWithFrame:*ioRect] ;
  [cb setButtonType: NSMomentaryLightButton] ;
  [cb setBezelStyle: NSSmallSquareBezelStyle] ;
  [cb setAutoresizingMask: NSViewMaxXMargin | NSViewMinYMargin] ;
  [cb
    bind:@"fontValue"
    toObject:udc
    withKeyPath:inFontBindingPath
    options:NULL
  ] ;
  [ioView addSubview:cb] ;
  *ioEnclosingRect = NSUnionRect (*ioEnclosingRect, *ioRect) ;
//--- Add foreground color well
  ioRect->origin.x += 210.0 ;
  ioRect->size.width = 40.0 ;
  colorWell = [[NSColorWell alloc] initWithFrame:*ioRect] ;
  [colorWell setAutoresizingMask: NSViewMaxXMargin | NSViewMinYMargin] ;
  [colorWell
    bind:@"value"
    toObject:udc
    withKeyPath:inForegroundBindingPath
    options:[NSDictionary dictionaryWithObject:NSUnarchiveFromDataTransformerName forKey:NSValueTransformerNameBindingOption]
  ] ;
  [ioView addSubview:colorWell] ;
  *ioEnclosingRect = NSUnionRect (*ioEnclosingRect, *ioRect) ;
//--- Add text
  NSTextField * f = [[NSTextField alloc] init] ;
  [f setEditable: NO] ;
  [f setSelectable: NO] ;
  [f setDrawsBackground: NO] ;
  [f setBordered:NO] ;
  [f setAlignment: NSLeftTextAlignment] ;
  [f setAutoresizingMask: NSViewMaxXMargin | NSViewMinYMargin] ;
  [f setStringValue: inTitle] ;
  NSDictionary * d = [NSDictionary dictionaryWithObjectsAndKeys:
    [f font], NSFontAttributeName,
    nil
  ] ;
  ioRect->origin.x += 50.0 ;
  ioRect->size.width = [inTitle sizeWithAttributes:d].width + 30.0 ;
  [f setFrame: *ioRect] ;
  [ioView addSubview: f] ;
  *ioEnclosingRect = NSUnionRect (*ioEnclosingRect, *ioRect) ;
  ioRect->origin.y -= 25.0 ;
}

//---------------------------------------------------------------------------*

- (void) setTextColorsAndFontForTokenizer: (OC_Lexique *) inTokenizer
         atIndex: (NSUInteger) inIndex {
  #define kDefaultColorCount 7
  NSColor * defaultColorArray [kDefaultColorCount] = {
    [NSColor blackColor],
    [NSColor blueColor],
    [NSColor orangeColor],
    [NSColor purpleColor],
    [NSColor redColor],
    [NSColor brownColor],
    [NSColor grayColor]
  } ;
  NSUInteger defaultColorIndex = 0 ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSRect enclosingRect = {{0.0, 0.0}, {10.0, 25.0}} ;
  NSView * view = [[NSView alloc] initWithFrame:enclosingRect] ;
  [view setAutoresizesSubviews:YES] ;
  NSRect r ;
  r.origin.y = enclosingRect.origin.y ;
  r.size.height = 20.0 ;
  NSMutableArray * allFontPreferenceNames = [NSMutableArray new] ;
  if ([inTokenizer isTemplateLexique]) {
  //--- By default, background color is white
    NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_template_background_color, [inTokenizer styleIdentifierForStyleIndex:0]] ;
    if ([ud objectForKey:name] == nil) {
      [[NSUserDefaults standardUserDefaults]
        setObject:[NSArchiver archivedDataWithRootObject:[NSColor whiteColor]]
        forKey:name
      ] ;
    }
  //--- Find a default foreground color
    name = [NSString stringWithFormat:@"%@_%@", GGS_template_foreground_color, [inTokenizer styleIdentifierForStyleIndex:0]] ;
    if ([ud objectForKey:name] == nil) {
      [[NSUserDefaults standardUserDefaults]
        setObject:[NSArchiver archivedDataWithRootObject:defaultColorArray [defaultColorIndex]]
        forKey:name
      ] ;
      // defaultColorIndex = (defaultColorIndex + 1) % kDefaultColorCount ;
      defaultColorIndex = 1 ;
    }
  //--- By default, font is courier 13
    name = [NSString stringWithFormat:@"%@_%@", GGS_template_font, [inTokenizer styleIdentifierForStyleIndex:0]] ;
    [allFontPreferenceNames addObject:name] ;
    if ([ud objectForKey:name] == nil) {
      [[NSUserDefaults standardUserDefaults]
        setObject:[NSArchiver archivedDataWithRootObject:[NSFont fontWithName:@"Courier" size:13.0]]
        forKey:name
      ] ;
    }
    [self
      setUpView: view
      withCurrentRectangle: & r
      withEnclosingRectangle: & enclosingRect
      withBackgroundColorBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_template_background_color, [inTokenizer styleIdentifierForStyleIndex:0]]
      withFontBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_template_font, [inTokenizer styleIdentifierForStyleIndex:0]]
      withForegroundColorBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_template_foreground_color, [inTokenizer styleIdentifierForStyleIndex:0]]
      withSettingTitle:@"Template String"
    ] ;
  }
  UInt32 i ;
  for (i=0; i<[inTokenizer styleCount] ; i++) {
  //--- By default, find an old style foreground color
    NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_named_color, [inTokenizer styleIdentifierForStyleIndex:i]] ;
    // NSLog (@"name '%@'", name) ;
    if ([ud objectForKey:name] == nil) {
    //--- Not found
      NSArray * splitName = [[inTokenizer styleIdentifierForStyleIndex:i] componentsSeparatedByString:@"-"] ;
      if ([splitName count] == 2) {
        NSString * oldName = [NSString stringWithFormat:@"%@_%@", GGS_named_color, [splitName objectAtIndex:1 HERE]] ;
        if ([ud objectForKey:oldName] != nil) {
          [[NSUserDefaults standardUserDefaults]
            setObject:[ud objectForKey:oldName]
            forKey:name
          ] ;
        }
      }
    }
  //--- By default, background color is white
    name = [NSString stringWithFormat:@"%@_%@", GGS_named_background_color, [inTokenizer styleIdentifierForStyleIndex:i]] ;
    if ([ud objectForKey:name] == nil) {
      [[NSUserDefaults standardUserDefaults]
        setObject:[NSArchiver archivedDataWithRootObject:[NSColor whiteColor]]
        forKey:name
      ] ;
    }
  //--- Find a default foreground color
    name = [NSString stringWithFormat:@"%@_%@", GGS_named_color, [inTokenizer styleIdentifierForStyleIndex:i]] ;
    if ([ud objectForKey:name] == nil) {
      [[NSUserDefaults standardUserDefaults]
        setObject:[NSArchiver archivedDataWithRootObject:defaultColorArray [defaultColorIndex]]
        forKey:name
      ] ;
      defaultColorIndex = (defaultColorIndex + 1) % kDefaultColorCount ;
    }
   //--- By default, font is courier 13
    name = [NSString stringWithFormat:@"%@_%@", GGS_named_font, [inTokenizer styleIdentifierForStyleIndex:i]] ;
    [allFontPreferenceNames addObject:name] ;
    if ([ud objectForKey:name] == nil) {
      [[NSUserDefaults standardUserDefaults]
        setObject:[NSArchiver archivedDataWithRootObject:[NSFont fontWithName:@"Courier" size:13.0]]
        forKey:name
      ] ;
    }
  //--- Add User interface items
    [self
      setUpView: view
      withCurrentRectangle: & r
      withEnclosingRectangle: & enclosingRect
      withBackgroundColorBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_named_background_color, [inTokenizer styleIdentifierForStyleIndex:i]]
      withFontBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_named_font, [inTokenizer styleIdentifierForStyleIndex:i]]
      withForegroundColorBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_named_color, [inTokenizer styleIdentifierForStyleIndex:i]]
      withSettingTitle:[inTokenizer styleNameForStyleIndex:i]
    ] ;
  }
  enclosingRect.size.height += 10.0 ;
  enclosingRect.origin.y -= 10.0 ;
  [view setFrame:enclosingRect] ;
//--- Set view to scroll view
  NSString * title = [inTokenizer tabItemTitle] ;
  NSTabViewItem * tvi = [[NSTabViewItem alloc] initWithIdentifier:title] ;
  [tvi setLabel:title] ;
  [mLexicalColoringTabView insertTabViewItem:tvi atIndex:inIndex] ;
//--- Duplicate 'SetFont' Button
//  NSLog (@"ALL NAMES IN PREFERENCES: '%@'", allFontPreferenceNames) ;
  NSButton * setFontButton = [[NSButton alloc] initWithFrame:[mSetFontButton frame]] ;
//  NSData * data = [NSArchiver archivedDataWithRootObject:mSetFontButton] ;
//  NSButton * setFontButton = [NSUnarchiver unarchiveObjectWithData:data] ;
//  [setFontButton setButtonType:[mSetFontButton buttonType]] ;
//  [setFontButton setAutoresizingMask:[mSetFontButton autoresizingMask]] ;
//  NSLog (@"TITLE '%@'", [mSetFontButton title]) ;
  [[setFontButton cell] setRepresentedObject:allFontPreferenceNames] ;
  [setFontButton setTitle:@"Set Font…"] ;
  [setFontButton setState:[mSetFontButton state]] ;
//  [setFontButton setAttributedTitle:[mSetFontButton attributedTitle]] ;
  [setFontButton setBezelStyle:[mSetFontButton bezelStyle]] ;
  [setFontButton setBordered:[mSetFontButton isBordered]] ;
  [setFontButton setAutoresizingMask:NSViewNotSizable] ;
  [setFontButton setTarget:self] ;
  [setFontButton setAction:@selector (setFontAction:)] ;
  [[tvi view] addSubview:setFontButton] ;
//--- IMPORTANT: the following instruction performs actual sizing of tvi view.
  [mLexicalColoringTabView selectTabViewItemAtIndex:inIndex] ;
  NSScrollView * sc = [[NSScrollView alloc] initWithFrame:[mLexicalColoringScrollView frame]] ;
  [sc setHasHorizontalScroller:YES] ;
  [sc setHasVerticalScroller:YES] ;
  [sc setAutohidesScrollers:YES] ;
  [sc setBorderType:[mLexicalColoringScrollView borderType]] ;
  [sc setBackgroundColor:[mLexicalColoringScrollView backgroundColor]] ;
  [sc setDrawsBackground:YES] ;
  [sc setAutoresizesSubviews:YES] ;
  [sc setAutoresizingMask:[mLexicalColoringScrollView autoresizingMask]] ;
  [[tvi view] addSubview:[sc autorelease]] ;
  [sc setDocumentView:[view autorelease]] ;
  // NSRect fff = [[tvi view] frame] ;
  // NSLog (@"%f %f %f %f", fff.origin.x, fff.origin.y, fff.size.width, fff.size.height) ;
}

//---------------------------------------------------------------------------*

- (void) setFontAction: (id) inSender {
//--- Get all preference names
  mCurrentFontArray = [[inSender cell] representedObject] ;
  //NSLog (@"mCurrentFontArray '%@'", mCurrentFontArray) ;
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
  NSString * preferenceName = nil ;
  NSMutableSet * fontSet = [NSMutableSet new] ;
  for (preferenceName in mCurrentFontArray) {
    NSData * data = [defaults objectForKey:preferenceName] ;
    NSFont * f = nil ;
    if (data != nil) {
      f = [NSUnarchiver unarchiveObjectWithData:data] ;
    }
    if (f != nil) {
      [fontSet addObject:f] ;
    }
    //NSLog (@"%@ -> '%@' -> '%@'", preferenceName, data, [f displayName]) ;
  }
  // NSLog (@"Font set : '%@'", fontSet) ;
//--- Set font manager selected fonts
  NSFontManager * fontManager = [NSFontManager sharedFontManager] ;
  if ([fontSet count] == 1) {
    [fontManager setSelectedFont:[fontSet anyObject] isMultiple:NO] ;
  }else if ([fontSet count] > 1) {
    NSFont * f = nil ;
    for (f in fontSet) {
      // NSLog (@"%@", f) ;
      [fontManager setSelectedFont:f isMultiple:YES] ;
    }
  }
//--- Set up font panel
  [fontManager setAction:@selector (changeFont:)] ;
  [fontManager setTarget:self] ;
  [fontManager orderFrontFontPanel:self] ;
}

//---------------------------------------------------------------------------*

- (void) changeFont: (id) inSender {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
//--- Get all preference names
  // NSLog (@"mCurrentFontArray '%@'", mCurrentFontArray) ;
//--- Changing fonts
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
  NSFontManager * fontManager = [NSFontManager sharedFontManager] ;
  NSString * preferenceName = nil ;
  for (preferenceName in mCurrentFontArray) {
    NSData * data = [defaults objectForKey:preferenceName] ;
    NSFont * f = nil ;
    if (data != nil) {
      f = [NSUnarchiver unarchiveObjectWithData:data] ;
    }
    NSFont * newFont = nil ;
    if (f != nil) {
      newFont = [fontManager convertFont:f] ;
    }
    if (newFont != nil) {
      data = [NSArchiver archivedDataWithRootObject:newFont] ;
      [defaults setObject:data forKey:preferenceName] ;
    }
    // NSLog (@"%@ : '%@' -> '%@'", preferenceName, [f displayName], [newFont displayName]) ;
  }
}

//---------------------------------------------------------------------------*

- (void) setTextColorsPreferences {
  NSArray * tokenizerArray = tokenizers () ;
  unsigned t ;
  for (t=0 ; t<[tokenizerArray count] ; t++) {
    OC_Lexique * tokenizer = [tokenizerArray objectAtIndex:t HERE] ;
    [self setTextColorsAndFontForTokenizer:tokenizer atIndex:t] ;
  }
//--- Remove tabview item Model
  [mLexicalColoringTabView removeTabViewItem:[mLexicalColoringTabView tabViewItemAtIndex:[tokenizerArray count]]] ;
  mLexicalColoringScrollView = nil ;
}

//---------------------------------------------------------------------------*

#pragma mark Build Text Macros Menu

//---------------------------------------------------------------------------*

- (void) insertTextMacroWithIndex: (int) inIndex
         titleComponents: (NSArray *) inTitleComponents
         intoMenu: (NSMenu *) inMenu {
 // NSLog (@"[inTitleComponents count] %u, inMenu %@", [inTitleComponents count], inMenu) ;
  if ([inTitleComponents count] == 1) {
    [inMenu
      addItemWithTitle:[inTitleComponents lastObject]
      action:@selector (actionInsertTextMacro:)
      keyEquivalent:@""
    ] ;
    NSMenuItem * item = [inMenu itemAtIndex:[inMenu numberOfItems] - 1] ;
    [item setTag:inIndex] ;
  }else{
  //--- Find or Add menu item
    NSInteger idx = [inMenu indexOfItemWithTitle:[inTitleComponents objectAtIndex:0 HERE]] ;
    if (idx < 0) {
      idx = [inMenu numberOfItems] ;
      [inMenu
        addItemWithTitle:[inTitleComponents objectAtIndex:0 HERE]
        action:NULL
        keyEquivalent:@""
      ] ;
    }
  //---
    NSMenuItem * item = [inMenu itemAtIndex:idx] ;
    NSMenu * submenu = [item submenu] ;
    if (submenu == nil) {
      submenu = [[NSMenu alloc] initWithTitle:@""] ;
      [item setSubmenu:submenu] ;
    }
  //---
    NSMutableArray * components = [[NSMutableArray alloc] init] ;
    [components addObjectsFromArray:inTitleComponents] ;
    [components removeObjectAtIndex:0] ;
  //---
    [self
      insertTextMacroWithIndex:inIndex
      titleComponents:components
      intoMenu:submenu
    ] ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//       B U I L D    T E X T    M A C R O    M E N U                        *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) buildTextMacroMenu {
  // NSLog (@"mTextMacroMenu %@", mTextMacroMenu) ;
  NSArray * tokenizerArray = tokenizers () ;
  UInt32 macroCount = 0 ;
  UInt32 i ;
  for (i=0 ; i<[tokenizerArray count] ; i++) {
    OC_Lexique * tokenizer = [tokenizerArray objectAtIndex:i HERE] ;
    macroCount += [tokenizer textMacroCount] ;
  }
  if (macroCount == 0) {
    NSMenu * mainMenu = [NSApp mainMenu] ;
    [mainMenu removeItemAtIndex:[mainMenu indexOfItemWithSubmenu:mTextMacroMenu]];
  }else{
    for (i=0 ; i<[tokenizerArray count] ; i++) {
      OC_Lexique * tokenizer = [tokenizerArray objectAtIndex:i HERE] ;
      UInt32 j ;
      for (j=0 ; j<[tokenizer textMacroCount] ; j++) {
        NSString * title = [tokenizer textMacroTitleAtIndex:j] ;
        NSArray * components = [title componentsSeparatedByString:@"/"] ;
        [self
          insertTextMacroWithIndex:i
          titleComponents:components
          intoMenu:mTextMacroMenu
        ] ;
      }
    }
  }
}

//---------------------------------------------------------------------------*

#pragma mark Build Option Items

//---------------------------------------------------------------------------*
//                                                                           *
//   B U I L D    B O O L    C O M M A N D    L I N E    O P T I O N S       *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) buildBooleanCommandLineOptionsInView: (NSView *) inView
         enclosingRect: (NSRect *) ioRect {
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  NSRect r  ;
  r.origin.x = 10.0 ;
  r.origin.y = ioRect->origin.y ;
  r.size.height = 20.0 ;
  for (NSUInteger i=0 ; i<[mBoolOptionArray count] ; i++) {
    OC_GGS_CommandLineOption * option = [mBoolOptionArray objectAtIndex:i HERE] ;
    NSButton * cb = [[NSButton alloc] init] ;
    NSString * title = [option title] ;
    NSDictionary * d = [NSDictionary dictionaryWithObjectsAndKeys:
      [cb font], NSFontAttributeName,
      nil
    ] ;
    r.size.width = [title sizeWithAttributes:d].width + 30.0 ;
    r.origin.y -= 25.0 ;
    [cb setFrame:r] ;
    [cb setTitle: title] ;
    [cb setButtonType: NSSwitchButton] ;
    [cb setAutoresizingMask: NSViewMaxXMargin | NSViewMinYMargin] ;
    [cb
      bind:@"value"
      toObject:udc
      withKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_bool_build_option, [option identifier]]
      options:nil
    ] ;
    [inView addSubview:cb] ;
    *ioRect = NSUnionRect (*ioRect, r) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//   B U I L D    U I N T    C O M M A N D    L I N E    O P T I O N S       *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) buildUnsignedIntegerCommandLineOptionsInView: (NSView *) inView
         enclosingRect: (NSRect *) ioRect {
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  NSDictionary * optionDictionary = [NSDictionary
    dictionaryWithObject:[NSNumber numberWithBool:YES]
    forKey:NSContinuouslyUpdatesValueBindingOption
  ] ;
  NSRect r;
  r.origin.x = 10.0 ;
  r.origin.y = ioRect->origin.y ;
  r.size.height = 20.0 ;
  UInt32 i ;
  for (i=0 ; i<[mUIntOptionArray count] ; i++) {
    OC_GGS_CommandLineOption * option = [mUIntOptionArray objectAtIndex:i HERE] ;
  //--- Input text field
    NSTextField * tx = [[NSTextField alloc] init] ;
    [tx setAutoresizingMask: NSViewMaxXMargin | NSViewMinYMargin] ;
  //--- Add formatter
    NSNumberFormatter * format = [[NSNumberFormatter alloc] init] ;
    [format setFormat:@"#0;0;-#0"] ;
    [format setMinimum:[NSDecimalNumber zero]] ;
    [format setAllowsFloats:NO] ;
    [[tx cell] setFormatter:format] ;

    r.origin.x = 10.0 ;
    r.size.width = 80.0 ;
    r.origin.y -= 25.0 ;
    [tx setFrame: r] ;
    [tx setTag: i] ;
    [tx
      bind:@"value"
      toObject:udc
      withKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_uint_build_option, [option identifier]]
      options:optionDictionary
    ] ;
    [inView addSubview: tx] ;
    *ioRect = NSUnionRect (*ioRect, r) ;
  //--- Comment text
    tx = [[NSTextField alloc] init] ;
    NSString * title = [option title] ;
    [tx setTitleWithMnemonic: title] ;
    [tx setAutoresizingMask: NSViewMaxXMargin | NSViewMinYMargin] ;
    NSDictionary * d = [NSDictionary dictionaryWithObjectsAndKeys:
      [tx font], NSFontAttributeName,
      nil
    ] ;
    r.size.width = [title sizeWithAttributes:d].width + 30.0 ;
    r.origin.x = 100.0 ;
    [tx setFrame: r] ;
    [tx setEditable: NO] ;
    [tx setBordered: NO] ;
    [tx setBezeled: NO] ;
    [tx setDrawsBackground: NO] ;
    [inView addSubview: tx] ;
    *ioRect = NSUnionRect (*ioRect, r) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//   B U I L D    U I N T    C O M M A N D    L I N E    O P T I O N S       *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) buildStringCommandLineOptionsInView: (NSView *) inView
         enclosingRect: (NSRect *) ioRect {
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  NSDictionary * optionDictionary = [NSDictionary
    dictionaryWithObject:[NSNumber numberWithBool:YES]
    forKey:NSContinuouslyUpdatesValueBindingOption
  ] ;
  NSRect r;
  r.origin.x = 10.0 ;
  r.origin.y = ioRect->origin.y ;
  r.size.width = 240.0 ;
  r.size.height = 20.0 ;
  NSRect viewFrame = [inView frame] ;
  UInt32 i ;
  for (i=0 ; i<[mStringOptionArray count] ; i++) {
    OC_GGS_CommandLineOption * option = [mStringOptionArray objectAtIndex:i HERE] ;
  //--- Input text field
    NSTextField * tx = [[NSTextField alloc] init] ;
    [tx setAutoresizingMask: NSViewMaxXMargin | NSViewMinYMargin] ;
    r.origin.y -= 25.0 ;
    r.origin.x = 10.0 ;
    r.size.width = 280.0 ;
    [tx setFrame: r] ;
    [tx
      bind:@"value"
      toObject:udc
      withKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_string_build_option, [option identifier]]
      options:optionDictionary
    ] ;
    [inView addSubview:tx] ;
    viewFrame = NSUnionRect (viewFrame, r) ;
  //--- Comment text
    tx = [[NSTextField alloc] init] ;
    NSString * title = [option title] ;
    [tx setTitleWithMnemonic: title] ;
    [tx setAutoresizingMask: NSViewMaxXMargin | NSViewMinYMargin] ;
    NSDictionary * d = [NSDictionary dictionaryWithObjectsAndKeys:
      [tx font], NSFontAttributeName,
      nil
    ] ;
    r.size.width = [title sizeWithAttributes:d].width + 30.0 ;
    r.origin.x = 300.0 ;
    [tx setFrame: r] ;
    [tx setEditable: NO] ;
    [tx setBordered: NO] ;
    [tx setBezeled: NO] ;
    [tx setDrawsBackground: NO] ;
    [inView addSubview: tx] ;
    *ioRect = NSUnionRect (*ioRect, r) ;
  }
}

//---------------------------------------------------------------------------*
//                                                                           *
//   POPULATE TOOL POPUPBUTTON                                               *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) populateToolPopupButtonInView: (NSView *) inView {
//--- Get default settings
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
//--- Populate
  [mToolPopUpButton removeAllItems] ;
  NSString * resourcePath = [[NSBundle mainBundle] resourcePath] ;
  NSFileManager * fm = [[NSFileManager alloc] init] ;
  NSDirectoryEnumerator * dirEnum = [fm enumeratorAtPath:resourcePath];
  NSString * file = [dirEnum nextObject] ;
  while (file != nil) {
    if ([[file pathExtension] isEqualToString: @""]) {
      [mToolPopUpButton addItemWithTitle:file] ;
      [mToolNameArray addObject:file] ;
    }
    file = [dirEnum nextObject] ;
  }
//--- Select popup item from user defaults
  NSInteger selected_item ;
  if ([defaults objectForKey:GGS_tool_selection_preference] == nil) {
    selected_item = 0 ;
  }else{
    selected_item = [defaults integerForKey:GGS_tool_selection_preference] ;
  }
  if ((selected_item >= 0) && (selected_item < [mToolPopUpButton numberOfItems])) {
    [mToolPopUpButton selectItemAtIndex:selected_item] ;
  }else if ([mToolPopUpButton numberOfItems] > 0) {
    [mToolPopUpButton selectItemAtIndex:0] ;
  }
//--- Define target and action
  [mToolPopUpButton setTarget:self] ;
  [mToolPopUpButton setAction:@selector (toolSelectionDidChange:)] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       A W A K E    F R O M    N I B                                       *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) awakeFromNib {
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
//--- Add observer to user defaults changes
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSNotificationCenter  * nc = [NSNotificationCenter defaultCenter] ;
  [nc addObserver:self selector:@selector(preferencesDidChange:) name:NSUserDefaultsDidChangeNotification object:ud] ;
//--- Load tool nibs ?
  NSArray * nibArray = nibsAndClasses () ;
  for (NSUInteger i=0 ; i<[nibArray count] ; i++) {
    NSArray * entry = [nibArray objectAtIndex:i HERE] ;
    NSString * nibName = [entry objectAtIndex:0 HERE] ;
    Class mainClass = [entry objectAtIndex:1 HERE] ;
    id owner = [[mainClass alloc] init] ;
    [NSBundle loadNibNamed:nibName owner:owner] ;
  }
//--- Get default settings
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
//--- Check "Shift Left Inserted space count"
  if ([defaults integerForKey:@"PMShiftLeftInsertedSpaceCount"] == 0) {
    [defaults setInteger:2 forKey:@"PMShiftLeftInsertedSpaceCount"] ;
  }
//--- Bind "Shift Left Inserted space count" Textfield
  [mShiftLeftInsertedSpaceTextField
    bind:@"value"
    toObject:[NSUserDefaultsController sharedUserDefaultsController]
    withKeyPath:@"values.PMShiftLeftInsertedSpaceCount"
    options:[NSDictionary dictionaryWithObject:[NSNumber numberWithBool:YES] forKey:NSContinuouslyUpdatesValueBindingOption]
  ] ;
//--- Make this object delegate of associated window (for tracking window moves and resizes)
  [mPreferenceWindow setDelegate:self] ;
  NSString * preferencesWindowFrameString = [defaults stringForKey:GGS_preference_window_frame] ;
//--- Set application menu item titles
  [self setApplicationMenuItemTitles] ;
//--- Set Preferences Window Title
  NSDictionary * bundleDictionary = [[NSBundle mainBundle] localizedInfoDictionary] ;
  NSString * applicationName = [bundleDictionary objectForKey: @"CFBundleName"] ;
  if (applicationName != nil) {
    NSMutableString * preferencesWindowTitle = [NSMutableString new] ;
    [preferencesWindowTitle appendString: applicationName] ;
    [preferencesWindowTitle appendString: @" Preferences"] ;
    [mPreferenceWindow setTitle: preferencesWindowTitle] ;
  }
//--- Get default font, used when there is no preference setting
  if ([defaults stringForKey:GGS_build_text_font] == nil) {
    NSFont * defaultFont = [NSFont fontWithName:@"Courier-Bold" size:13.0] ;
    [defaults setObject:[NSArchiver archivedDataWithRootObject:defaultFont] forKey:GGS_build_text_font] ;
  }
  [mCurrentBuildWindowFontAndSizeSettingsButton
    bind:@"fontValue"
    toObject:[NSUserDefaultsController sharedUserDefaultsController]
    withKeyPath:[NSString stringWithFormat:@"values.%@", GGS_build_text_font]
    options:NULL
  ] ;
//--- Set show ruler checkbox
  if ([defaults objectForKey:GGS_show_ruler] == nil) {
    [mShowRuleCheckBox setState:YES] ;
    [defaults setBool:YES forKey:GGS_show_ruler] ;
  }else{
    [mShowRuleCheckBox setState:[defaults boolForKey:GGS_show_ruler]] ;
  }
//--- Build text color user interface
  [self setTextColorsPreferences] ;
//--- Check "Verbose" option if not defined
  NSString * keyForVerboseOption = [NSString stringWithFormat:@"%@_%s", GGS_bool_build_option, "verbose"] ;
  NSNumber * verboseOption = [defaults objectForKey:keyForVerboseOption] ;
  if (verboseOption == nil) {
    [defaults setBool:YES forKey:keyForVerboseOption] ;
  }
//---------- OPTIONS TAB ----------
  NSRect enclosingRect = {{0.0, 0.0}, {5.0, 5.0}} ;
  NSView * view = [[NSView alloc] initWithFrame:enclosingRect] ;
  [view setAutoresizesSubviews:YES] ;
  [self populateToolPopupButtonInView:view] ;
//--- Build boolean command line options
  [self buildBooleanCommandLineOptionsInView:view enclosingRect:&enclosingRect] ;
//--- Build unsigned integer command line options
  [self buildUnsignedIntegerCommandLineOptionsInView:view enclosingRect:&enclosingRect] ;
//--- Build string command line options
  [self buildStringCommandLineOptionsInView:view enclosingRect:&enclosingRect] ;
  enclosingRect.size.height += 10.0 ;
  enclosingRect.origin.y -= 10.0 ;
  [view setFrame:enclosingRect] ;
//--- Set view to scroll view
  [mCommandLineOptionScrollView setDocumentView:view] ;
//---
  [mPreferencesTabView
    bind:@"selectedIndex"
    toObject:[NSUserDefaultsController sharedUserDefaultsController]
    withKeyPath:@"values.GGS_selected_tab"
    options:nil
  ] ;
//--- Set preference window frame
  if (preferencesWindowFrameString != nil) {
    [mPreferenceWindow setFrameFromString:preferencesWindowFrameString] ;
  }
//--- Build Text Macro Menu
  [self buildTextMacroMenu] ;
//--- Convert CRLF and CR on document opening
  if ([ud objectForKey:@"PMConvert_CRLF_And_CR_To_LF_AtStartUp"] == nil) {
    [ud setObject:[NSNumber numberWithBool:YES] forKey:@"PMConvert_CRLF_And_CR_To_LF_AtStartUp"] ;
  }
  [mConvert_CRLF_And_CR_To_LF_AtStartUpButton
    bind:@"value"
    toObject:[NSUserDefaultsController sharedUserDefaultsController]
    withKeyPath:@"values.PMConvert_CRLF_And_CR_To_LF_AtStartUp"
    options:NULL
  ] ;
//--- Convert HTAB on document opening
  if ([ud objectForKey:@"PMConvert_HTAB_To_SPACE_AtStartUp"] == nil) {
    [ud setObject:[NSNumber numberWithBool:YES] forKey:@"PMConvert_HTAB_To_SPACE_AtStartUp"] ;
  }
  [mConvert_HTAB_To_SPACE_AtStartUpButton
    bind:@"value"
    toObject:[NSUserDefaultsController sharedUserDefaultsController]
    withKeyPath:@"values.PMConvert_HTAB_To_SPACE_AtStartUp"
    options:NULL
  ] ;
//--- Show Invisible Characters Checkbox
 [mShowInvisibleCharactersCheckBox
    bind:@"value"
    toObject:[NSUserDefaultsController sharedUserDefaultsController]
    withKeyPath:@"values.PMShowInvisibleCharacters"
    options:NULL
  ] ;
//--- Bind command line option text view
  [mCommandLineOptionTextView setFont:[NSFont boldSystemFontOfSize:[NSFont smallSystemFontSize]]] ;
  [mCommandLineOptionTextView bind:@"value" toObject:self withKeyPath:@"commandLineString" options:nil] ;
  [self willChangeValueForKey:@"commandLineString"] ;
  [self  didChangeValueForKey:@"commandLineString"] ;
  [mCommandLineOptionTextView setEditable:NO] ;
//---
  [mLiveCompilationCheckBox
    bind:@"value"
    toObject:[NSUserDefaultsController sharedUserDefaultsController]
    withKeyPath:@"values.PMLiveCompilation"
    options:NULL
  ] ;
//---  
  [self updateSourceTextPreferenceCount] ;
}

//---------------------------------------------------------------------------*

- (void) preferencesDidChange: (id) inUsedArgument {
//  NSLog (@"preferencesDidChange") ;
  [self willChangeValueForKey:@"commandLineString"] ;
  [self  didChangeValueForKey:@"commandLineString"] ;
}

//---------------------------------------------------------------------------*

- (NSArray *) toolNameArray {
  return mToolNameArray ;
}

//---------------------------------------------------------------------------*

#pragma mark Preferences Change

//---------------------------------------------------------------------------*
//                                                                           *
//       C H A N G E    T E X T    R U L E R S    V I S I B I L I T Y        *
//                                                                           *
//---------------------------------------------------------------------------*

- (double) ruleThickness {
  return 50.0 ;
}

//---------------------------------------------------------------------------*

- (IBAction) setTextRulerVisible: (id) inSender {
/*  const BOOL rulerIsVisible = [inSender state] ;
  const float ruleThickness = [self ruleThickness] ;
//--- Update opened documents
  NSArray * docArray = [[NSApplication sharedApplication] orderedDocuments] ;
//  printf ("%u %u\n", [docArray count], rulerIsVisible) ;
  unsigned d ;
  for (d=0 ; d<[docArray count] ; d++) {
    OC_GGS_Document * doc = [docArray objectAtIndex: d HERE] ;
    [doc changeTextRulerVisible:rulerIsVisible forRuleThickness:ruleThickness] ;
  }
//--- Update default setting
  [[NSUserDefaults standardUserDefaults] setBool:rulerIsVisible forKey:GGS_show_ruler] ;*/
}

//---------------------------------------------------------------------------*

- (IBAction) toolSelectionDidChange: (id) inSender {
  const NSInteger selectedToolIndex = [mToolPopUpButton indexOfSelectedItem] ;
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
  [defaults setObject:[NSNumber numberWithInteger:selectedToolIndex] forKey:GGS_tool_selection_preference] ;
  [self willChangeValueForKey:@"commandLineString"] ;
  [self  didChangeValueForKey:@"commandLineString"] ;
}

//---------------------------------------------------------------------------*

#pragma mark Track Window Moving and Resizing

//---------------------------------------------------------------------------*
//                                                                           *
//                              windowDidMove:                               *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) windowDidMove: (NSNotification *) inNotification {
  NSWindow * window = [inNotification object] ;
  NSString * s = [window stringWithSavedFrame] ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  [ud setObject:s forKey:GGS_preference_window_frame] ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                             windowDidResize:                              *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) windowDidResize: (NSNotification *) inNotification {
  NSWindow * window = [inNotification object] ;
  NSString * s = [window stringWithSavedFrame] ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  [ud setObject:s forKey:GGS_preference_window_frame] ;
}

//---------------------------------------------------------------------------*

#pragma mark User Actions

//---------------------------------------------------------------------------*
//                                                                           *
//       O P E N    A N    U N T I T L E D    D O C U M E N T                *
//                    A T    S T A R T U P                                   *
//                                                                           *
//---------------------------------------------------------------------------*

- (BOOL) applicationShouldOpenUntitledFile: (NSApplication *) inSender {
  return NO ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//       A C T I O N    N E W  D O C U M E N T                               *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) changeNewDocumentTypeAction: (id) inSender {
//--- Get Info.plist file
  NSDictionary * infoDictionary = [[NSBundle mainBundle] infoDictionary] ;
  // NSLog (@"infoDictionary '%@'", infoDictionary) ;
  NSArray * allDocumentTypes = [infoDictionary objectForKey:@"CFBundleDocumentTypes"] ;
  // NSLog (@"allDocumentTypes '%@'", allDocumentTypes) ;
  NSDictionary * docTypeDict = [allDocumentTypes objectAtIndex:[inSender tag] HERE] ;
  NSArray * documentTypeExtensions = [docTypeDict objectForKey:@"CFBundleTypeExtensions"] ;
  NSString * extension = [documentTypeExtensions objectAtIndex:0 HERE] ;
  // NSLog (@"extension '%@'", extension) ;
  NSSavePanel * savePanel = [inSender representedObject] ;
  [savePanel setRequiredFileType:extension] ;
}

//---------------------------------------------------------------------------*

- (void) newDocument: (id) inSender {
  NSSavePanel * savePanel = [NSSavePanel savePanel] ;
  [mNewDocumentTypePopUpButton removeAllItems] ;
//--- Get Info.plist file
  NSDictionary * infoDictionary = [[NSBundle mainBundle] infoDictionary] ;
  // NSLog (@"infoDictionary '%@'", infoDictionary) ;
  NSArray * allDocumentTypes = [infoDictionary objectForKey:@"CFBundleDocumentTypes"] ;
  // NSLog (@"allDocumentTypes '%@'", allDocumentTypes) ;
  unsigned i ;
  for (i=0 ; i<[allDocumentTypes count] ; i++) {
    NSDictionary * docTypeDict = [allDocumentTypes objectAtIndex:i HERE] ;
    // NSLog (@"docTypeDict '%@'", docTypeDict) ;
    NSArray * documentTypeExtensions = [docTypeDict objectForKey:@"CFBundleTypeExtensions"] ;
    // NSLog (@"documentTypeExtensions '%@'", documentTypeExtensions) ;
    NSString * documentTypeRole = [docTypeDict objectForKey:@"CFBundleTypeRole"] ;
    // NSLog (@"documentTypeRole '%@'", documentTypeRole) ;
    if ([documentTypeRole isEqualToString:@"Editor"] && ([documentTypeExtensions count] > 0)) {
      NSString * documentTypeName = [docTypeDict objectForKey:@"CFBundleTypeName"] ;
      // NSLog (@"documentTypeName '%@'", documentTypeName) ;
      [mNewDocumentTypePopUpButton addItemWithTitle:documentTypeName] ;
      NSMenuItem * item = [mNewDocumentTypePopUpButton lastItem] ;
      [item setTarget:self] ;
      [item setAction:@selector (changeNewDocumentTypeAction:)] ;
      [item setTag:i] ;
      [item setRepresentedObject:savePanel] ;
    }
  }
//--- Present save panel
  [savePanel setAllowsOtherFileTypes:NO] ;
  [savePanel setCanSelectHiddenExtension:YES] ;
  [savePanel setAccessoryView:mNewDocumentAccessoryView] ;
  [self changeNewDocumentTypeAction:[mNewDocumentTypePopUpButton itemAtIndex:0]] ;
  const NSInteger result = [savePanel runModalForDirectory:nil file:nil] ;
  // NSLog (@"result %d", result) ;
  if (result == NSOKButton) {
    NSString * path = [savePanel filename] ;
    // NSLog (@"path '%@'", path) ;
    NSError * error = nil ;
    if ([[NSData data] writeToFile:path options:NSAtomicWrite error:& error]) {
      NSDocumentController * dc = [NSDocumentController sharedDocumentController] ;
      [dc openDocumentWithContentsOfURL:[NSURL fileURLWithPath:path] display:YES error:nil] ;
    }else{
      [NSApp presentError:error] ;
    }
  }
}

//---------------------------------------------------------------------------*

#pragma mark Run Action

//---------------------------------------------------------------------------*

- (void) appendMessage: (NSString *) inMessage {
  NSTextStorage * ts = [mRunTextView textStorage] ;
  NSRange endOfText = {[ts length], 0} ;
  [mRunTextView replaceCharactersInRange: endOfText withString: inMessage] ;
  endOfText.location += [inMessage length] ;
  [mRunTextView scrollRangeToVisible: endOfText] ;
}

//---------------------------------------------------------------------------*

- (void) runActionFromPreferences: (id) inSender {
  if (mTask == nil) {
  //--- Get line command array
    NSArray * commandLineArray = [self commandLineItemArray] ;
  //--- Command line tool does actually exist ? (First argument is not "?")
    if ([[commandLineArray objectAtIndex:0 HERE] isEqualToString:@"?"]) {
      NSString * s = @"Compilation must be performed by an embedded Command line Tool; no command line Tool are currently embedded by application." ;
      NSAlert *alert = [NSAlert alertWithMessageText:@"Error: Cannot Run"
        defaultButton: nil
        alternateButton: nil
        otherButton: nil
        informativeTextWithFormat:s
      ] ;
      [alert beginSheetModalForWindow:mPreferenceWindow modalDelegate:nil didEndSelector:0 contextInfo:NULL] ;
    }else{
    //--- Disable Run button
      [mRunButton setEnabled:NO] ;
    //--- Empty run text view
      [mRunTextView setString: @""] ;
      const NSRange endOfText = {0, 0} ;
      [mRunTextView setTextColor:[NSColor blackColor] range:endOfText] ;
    //--- Show Run window
      [mRunWindow makeKeyAndOrderFront:self] ;
    //--- Create task
      mTask = [[NSTask alloc] init] ;
      [mTask setLaunchPath:[commandLineArray objectAtIndex:0 HERE]] ;
      [mTask setArguments:[commandLineArray subarrayWithRange:NSMakeRange (1, [commandLineArray count]-1)]] ;
    //--- Set standard output notification
      NSNotificationCenter * center = [NSNotificationCenter defaultCenter] ;
      NSPipe * taskOutput = [NSPipe pipe] ;
      [mTask setStandardOutput: taskOutput] ;
      [mTask setStandardError: taskOutput] ;
      [center
        addObserver: self
        selector: @selector (getDataFromTaskOutput:)
        name: NSFileHandleDataAvailableNotification
        object: [taskOutput fileHandleForReading]
      ] ;
      [[taskOutput fileHandleForReading] waitForDataInBackgroundAndNotify] ;
    //--- Start task
      [mTask launch] ;
    }
  }
}

//---------------------------------------------------------------------------*

- (void) terminateTask {
  [mTask terminate] ;
  [mTask waitUntilExit] ;
  NSNotificationCenter * center = [NSNotificationCenter defaultCenter] ;
  [center removeObserver: self name: NSFileHandleDataAvailableNotification object: [[mTask standardOutput] fileHandleForReading]] ;
  [center removeObserver: self name: NSTaskDidTerminateNotification object:mTask] ;
  const int status = [mTask terminationStatus];
  if (status != 0) {
    [self appendMessage: [NSString stringWithFormat: @"Build task failure, code %d\n", status]] ;
  }
  mTask = nil ;
//--- Enable Run button
  [mRunButton setEnabled:YES] ;
}

//---------------------------------------------------------------------------*

- (void) appendSuccess: (NSString *) inMessage {
//--- Append message
  NSTextStorage * ts = [mRunTextView textStorage] ;
  NSRange endOfText = {[ts length], 0} ;
  [mRunTextView replaceCharactersInRange: endOfText withString: inMessage] ;
  endOfText.length = [inMessage length] ;
  [mRunTextView setTextColor:[NSColor blueColor] range:endOfText] ;
  endOfText.location += endOfText.length ;
  endOfText.length = 0 ;
  [mRunTextView scrollRangeToVisible: endOfText] ;
  [mRunTextView setTextColor:[NSColor blueColor] range:endOfText] ;
}

//---------------------------------------------------------------------------*

- (void) appendError: (NSString *) inMessage {
  NSString * message = [inMessage stringByAppendingString:@"\n"] ;
//--- Append message
  NSTextStorage * ts = [mRunTextView textStorage] ;
  NSRange endOfText = {[ts length], 0} ;
  [mRunTextView replaceCharactersInRange: endOfText withString:message] ;
  endOfText.length = [message length] ;
  [mRunTextView setTextColor:[NSColor redColor] range:endOfText] ;
  endOfText.location += endOfText.length ;
  endOfText.length = 0 ;
  [mRunTextView scrollRangeToVisible: endOfText] ;
  [mRunTextView setTextColor:[NSColor blackColor] range:endOfText] ;
}

//---------------------------------------------------------------------------*

- (void) appendWarning: (NSString *) inMessage {
  NSString * message = [inMessage stringByAppendingString:@"\n"] ;
//--- Append message
  NSTextStorage * ts = [mRunTextView textStorage] ;
  NSRange endOfText = {[ts length], 0} ;
  [mRunTextView replaceCharactersInRange: endOfText withString:message] ;
  endOfText.length = [message length] ;
  [mRunTextView setTextColor:[NSColor orangeColor] range:endOfText] ;
  endOfText.location += endOfText.length ;
  endOfText.length = 0 ;
  [mRunTextView scrollRangeToVisible: endOfText] ;
  [mRunTextView setTextColor:[NSColor blackColor] range:endOfText] ;
}

//---------------------------------------------------------------------------*

- (void) getDataFromTaskOutput: (NSNotification *) inNotification {
  NSFileHandle * f = [inNotification object] ;
  NSData * d = [f availableData] ;
  if ([d length] > 0) {
    NSMutableString * s = [[NSMutableString alloc] initWithData:d encoding:NSUTF8StringEncoding] ;
    const NSUInteger length = [s length] ;
    NSRange range = {0, 0} ;
    NSUInteger style = 1 ; // 1 : message, 2 : success, 3 : warning, 4 : error
    NSUInteger i ;
    for (i=0 ; i<length ; i++) {
      unichar c = [s characterAtIndex:i] ;
      if (c < 5) {
        range.length = i - range.location ;
        if (range.length  > 0) {
          switch (style) {
          case 1 :
            [self appendMessage: [s substringWithRange:range]] ;
            break ;
          case 2 :
            [self appendSuccess: [s substringWithRange:range]] ;
            break ;
          case 3 :
            [self appendWarning: [s substringWithRange:range]] ;
            break ;
          case 4 :
            [self appendError: [s substringWithRange:range]] ;
            break ;
          }
        }
        style = c ;
        range.location = i + 1 ;
      }
    }
    range.length = length - range.location ;
    if (range.length  > 0) {
      switch (style) {
      case 1 :
        [self appendMessage: [s substringWithRange:range]] ;
        break ;
      case 2 :
        [self appendSuccess: [s substringWithRange:range]] ;
        break ;
      case 3 :
        [self appendWarning: [s substringWithRange:range]] ;
        break ;
      case 4 :
        [self appendError: [s substringWithRange:range]] ;
        break ;
      }
    }
  }else{
    [self terminateTask] ;
  }
  [f waitForDataInBackgroundAndNotify] ;
}

//---------------------------------------------------------------------------*

#pragma mark Termination Handling

//---------------------------------------------------------------------------*

- (NSApplicationTerminateReply) applicationShouldTerminate:(NSApplication *)sender {
  BOOL canTerminateApplication = YES ;
  for (OC_GGS_Document * doc in [[NSDocumentController sharedDocumentController] documents]) {
    if (doc.buildTaskIsRunning) {
      canTerminateApplication = NO ;
    }
  }
  if (! canTerminateApplication) {
    const NSInteger response = NSRunAlertPanel (@"Application cannot terminate while some tasks are running.",
                                    @"You can cancel termination, or force tasks to terminate.",
                                    @"Cancel", @"Stop Tasks and Quit", nil) ;
    canTerminateApplication = response == NSAlertAlternateReturn ;
  }
  return canTerminateApplication ? NSTerminateNow : NSTerminateCancel ;
}

//---------------------------------------------------------------------------*

#pragma mark Source text preferences

//---------------------------------------------------------------------------*

- (void) updateSourceTextPreferenceCount {
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSBundle * mb = [NSBundle mainBundle] ;
//  NSLog (@"[mb bundleIdentifier] %@", [mb bundleIdentifier]) ;
//  NSLog (@"[ud persistentDomainNames] %@", [ud persistentDomainNames]) ;
  NSDictionary * dictionaryRepresentation = [ud persistentDomainForName:[mb bundleIdentifier]] ;
  NSArray * allKeys = [dictionaryRepresentation allKeys] ;
  unsigned n = 0 ;
  const NSRange rangeGGS = {0, 4} ;
  const NSRange rangeNS = {0, 2} ;
  unsigned i ;
  for (i=0 ; i<[allKeys count] ; i++) {
    NSString * key = [allKeys objectAtIndex:i HERE] ;
    if (([key compare:@"GGS_" options:NSLiteralSearch range:rangeGGS] != NSOrderedSame) &&
        ([key compare:@"NS" options:NSLiteralSearch range:rangeNS] != NSOrderedSame)) {
      n ++ ;
      // NSLog (@"key '%@'", key) ;
    }
  }
  NSString * s = @"No source document preferences entry." ;
  if (n == 1) {
    s = @"1 source document preferences entry." ;
  }else if (n > 1) {
    s = [NSString stringWithFormat:@"%u source document preferences entries.", n] ;
  }
  [mSourcePreferenceStatsTextField setStringValue:s] ;
}

//---------------------------------------------------------------------------*

- (IBAction) clearSourceDocumentPreferencesEntries: (id) inSender {
  NSBundle * mb = [NSBundle mainBundle] ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSDictionary * dictionaryRepresentation = [ud persistentDomainForName:[mb bundleIdentifier]] ;
  NSArray * allKeys = [[dictionaryRepresentation allKeys] copy] ;
  const NSRange rangeGGS = {0, 4} ;
  const NSRange rangeNS = {0, 2} ;
  unsigned i ;
  for (i=0 ; i<[allKeys count] ; i++) {
    NSString * key = [allKeys objectAtIndex:i HERE] ;
    if (([key compare:@"GGS_" options:NSLiteralSearch range:rangeGGS] != NSOrderedSame) &&
        ([key compare:@"NS" options:NSLiteralSearch range:rangeNS] != NSOrderedSame)) {
      [ud setObject:nil forKey:key] ;
    }
  }
  [ud synchronize] ;
  [self updateSourceTextPreferenceCount] ;
}

//---------------------------------------------------------------------------*

@end
