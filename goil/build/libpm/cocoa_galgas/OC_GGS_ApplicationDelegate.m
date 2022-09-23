//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2003, ..., 2020 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

#import "OC_GGS_ColorTransformer.h"
#import "OC_GGS_TextDisplayDescriptor.h"
#import "OC_GGS_ApplicationDelegate.h"
#import "OC_GGS_Document.h"
#import "PMFontButton.h"
#import "OC_GGS_CommandLineOption.h"
#import "enterDefaultCommandLineOptions.h"
#import "OC_Lexique.h"
#import "F_CocoaWrapperForGalgas.h"
#import "PMDebug.h"

//----------------------------------------------------------------------------------------------------------------------

#ifdef PM_HANDLE_UPDATE
  #import "PMApplicationUpdate.h"
#endif

//----------------------------------------------------------------------------------------------------------------------

//#define DEBUG_MESSAGES

//----------------------------------------------------------------------------------------------------------------------

OC_GGS_ApplicationDelegate * gCocoaApplicationDelegate ;

//----------------------------------------------------------------------------------------------------------------------

#ifndef NS_ENUM
  typedef NSUInteger NSAutoresizingMaskOptions ;
#endif

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_GGS_ApplicationDelegate

//----------------------------------------------------------------------------------------------------------------------

- (instancetype) init {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  self = [super init] ;
  if (self) {
    gCocoaApplicationDelegate = self ;
    mToolNameArray = [NSMutableArray new] ;
  //--- Get command line option list
    mBoolOptionArray = [NSMutableArray new] ;
    mUIntOptionArray = [NSMutableArray new] ;
    mStringOptionArray = [NSMutableArray new] ;
    mStringListOptionArray = [NSMutableArray new] ;
    enterDefaultCommandLineOptions (mBoolOptionArray, mUIntOptionArray, mStringOptionArray) ;
    enterOptions (mBoolOptionArray, mUIntOptionArray, mStringOptionArray, mStringListOptionArray) ;
  }
  return self ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//   S E T    A P P L I C A T I O N    M E N U    I T E M    T I T L E S                         
//
//----------------------------------------------------------------------------------------------------------------------

- (void) setApplicationMenuItemTitles {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//--- Get application name
  NSDictionary * bundleDictionary = [[NSBundle mainBundle] localizedInfoDictionary] ;
  NSString * applicationName = [bundleDictionary objectForKey: @"CFBundleName"] ;
  if (applicationName != nil) {
  //--- Get menubar : it is application main menu
    NSMenu * menu = [NSApp mainMenu] ;
    menu = [[menu itemAtIndex: 0] submenu] ;
    const NSInteger itemsCount = [menu numberOfItems] ;
    for (NSInteger i=0 ; i<itemsCount ; i++) {
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

//----------------------------------------------------------------------------------------------------------------------

- (NSArray *) commandLineItemArray {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mCommandLineItemArray ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSTabView *) preferencesTabView {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mPreferencesTabView ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSInteger) selectedToolIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mToolPopUpButton.indexOfSelectedItem ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSString *) compilerToolPath: (NSInteger) inSelectedToolIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSString * result = @"?" ; // No compiler by default
  if (inSelectedToolIndex >= 0) {
    NSBundle * mb = [NSBundle mainBundle] ;
    NSString * rp = [mb resourcePath] ;
    result = [rp stringByAppendingPathComponent:[mToolNameArray objectAtIndex:(NSUInteger) inSelectedToolIndex]] ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

- (BOOL) prefixByToolUtility {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return [[NSUserDefaults standardUserDefaults] boolForKey:GGS_prefix_by_tool_utility] ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSString *) toolUtilityPrefix {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return @"/usr/bin/time" ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSString *) commandLineString {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
  NSMutableArray * arguments = [NSMutableArray new] ;
//--- Add tool path
  [arguments addObject:[self compilerToolPath: [mToolPopUpButton indexOfSelectedItem]]] ;
//--- Add boolean options
  for (NSUInteger i=0 ; i<[mBoolOptionArray count] ; i++) {
    OC_GGS_CommandLineOption * option = [mBoolOptionArray objectAtIndex:i] ;
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
    OC_GGS_CommandLineOption * option = [mUIntOptionArray objectAtIndex:i] ;
    const NSUInteger optionValue = (NSUInteger) [defaults integerForKey: [NSString stringWithFormat:@"%@_%@", GGS_uint_build_option, [option identifier]]];
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
    OC_GGS_CommandLineOption * option = [mStringOptionArray objectAtIndex:i] ;
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
  if ([self prefixByToolUtility]) {
    [s appendString:[self toolUtilityPrefix]] ;
    [s appendString:@" "] ;
  }
  for (NSUInteger i=0 ; i<[arguments count] ; i++) {
    [s appendString:[arguments objectAtIndex:i]] ;
    [s appendString:@" "] ;  
  }
//---
  return s ;
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Lexical Coloring

//----------------------------------------------------------------------------------------------------------------------
//
//       S E T    T E X T    C O L O R S    P R E F E R E N C E S                                
//
//----------------------------------------------------------------------------------------------------------------------

- (void) setUpView: (NSView *) ioView
         withCurrentRectangle: (NSRect *) ioRect
         withEnclosingRectangle: (NSRect *) ioEnclosingRect
         withBackgroundColorBindingPath: (NSString *) inBackgroundBindingPath
         withBackgroundActivationBindingPath: (NSString *) inBackgroundActivationBindingPath
         withFontBindingPath: (NSString *) inFontBindingPath
         withForegroundColorBindingPath: (NSString *) inForegroundBindingPath
         withSettingTitle: (NSString *) inTitle {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSAutoresizingMaskOptions mask = (NSAutoresizingMaskOptions) (NSViewMaxXMargin | NSViewMinYMargin) ;
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  OC_GGS_ColorTransformer * colorTransformer = [OC_GGS_ColorTransformer new] ;
//--- Add background color well
  ioRect->origin.x = 10.0 ;
  ioRect->size.width = 40.0 ;
  NSColorWell * colorWell = [[NSColorWell alloc] initWithFrame:*ioRect] ;
  [colorWell setToolTip: @"Background Color"] ;
  [colorWell setAutoresizingMask: mask] ;
  [colorWell
    bind:@"value"
    toObject:udc
    withKeyPath:inBackgroundBindingPath
    options:[NSDictionary dictionaryWithObject:colorTransformer forKey:NSValueTransformerBindingOption]
  ] ;
  [ioView addSubview:colorWell] ;
  *ioEnclosingRect = NSUnionRect (*ioEnclosingRect, *ioRect) ;
//--- Add associated checkbox
  ioRect->origin.x += 50.0 ;
  ioRect->size.width = 20.0 ;
  NSButton * cb = [[NSButton alloc] initWithFrame:*ioRect] ;
  [cb setToolTip: @"Enable background"] ;
  [cb setButtonType: NSSwitchButton] ;
  [cb setAutoresizingMask: mask] ;
  [cb
    bind:@"value"
    toObject:udc
    withKeyPath:inBackgroundActivationBindingPath
    options:NULL
  ] ;
  [colorWell
    bind:@"hidden"
    toObject:udc
    withKeyPath:inBackgroundActivationBindingPath
    options:[NSDictionary dictionaryWithObjectsAndKeys:
      NSNegateBooleanTransformerName, NSValueTransformerNameBindingOption,
      nil
    ]
  ] ;
  [ioView addSubview:cb] ;
  *ioEnclosingRect = NSUnionRect (*ioEnclosingRect, *ioRect) ;
//--- Add "Font" button
  ioRect->origin.x += 30.0 ;
  ioRect->size.width = 200.0 ;
  cb = [[PMFontButton alloc] initWithFrame:*ioRect] ;
  [cb setToolTip: @"Font"] ;
  [cb setButtonType: NSMomentaryLightButton] ;
  [cb setBezelStyle: NSSmallSquareBezelStyle] ;
  [cb setAutoresizingMask: mask] ;
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
  [colorWell setToolTip: @"Foreground Color"] ;
  [colorWell setAutoresizingMask: mask] ;
  [colorWell
    bind:@"value"
    toObject:udc
    withKeyPath:inForegroundBindingPath
    options:[NSDictionary dictionaryWithObject:colorTransformer forKey:NSValueTransformerBindingOption]
  ] ;
  [ioView addSubview:colorWell] ;
  *ioEnclosingRect = NSUnionRect (*ioEnclosingRect, *ioRect) ;
//--- Add text
  NSTextField * f = [NSTextField new] ;
  [f setEditable: NO] ;
  [f setSelectable: NO] ;
  [f setDrawsBackground: NO] ;
  [f setBordered:NO] ;
  [f setAlignment: NSLeftTextAlignment] ;
  [f setAutoresizingMask: mask] ;
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

//----------------------------------------------------------------------------------------------------------------------

- (void) setTextColorsAndFontForTokenizer: (OC_Lexique *) inTokenizer
         atIndex: (NSUInteger) inIndex {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  #define kDefaultColorCount (7)
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
    OC_GGS_ColorTransformer * colorTransformer = [OC_GGS_ColorTransformer new] ;
//    NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  //--- By default, background color is white
    NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_template_background_color, [inTokenizer styleIdentifierForStyleIndex:0]] ;
    if ([ud objectForKey:name] == nil) {
      [ud
        setObject: [colorTransformer reverseTransformedValue: [NSColor whiteColor]]
        forKey: name
      ] ;
    }else if ([colorTransformer transformedValue: [ud objectForKey:name]] == nil ) {
      NSColor * color = [NSUnarchiver unarchiveObjectWithData: [ud objectForKey:name]] ;
      NSData * archiveData = [colorTransformer reverseTransformedValue: color] ;
      if (archiveData == nil) {
        archiveData = [colorTransformer reverseTransformedValue: [NSColor whiteColor]] ;
      }
      [ud setValue: archiveData forKey: GGS_template_background_color] ;
    }
  //--- Find a default foreground color
    name = [NSString stringWithFormat:@"%@_%@", GGS_template_foreground_color, [inTokenizer styleIdentifierForStyleIndex:0]] ;
    if ([ud objectForKey:name] == nil) {
      [ud
        setObject: [colorTransformer reverseTransformedValue: defaultColorArray [defaultColorIndex]]
        forKey: name
      ] ;
      // defaultColorIndex = (defaultColorIndex + 1) % kDefaultColorCount ;
      defaultColorIndex = 1 ;
    }else if ([colorTransformer transformedValue: [ud objectForKey:name]] == nil ) {
      NSColor * color = [NSUnarchiver unarchiveObjectWithData: [ud objectForKey:name]] ;
      NSData * archiveData = [colorTransformer reverseTransformedValue: color] ;
      if (archiveData == nil) {
        archiveData = [colorTransformer reverseTransformedValue: [NSColor blackColor]] ;
      }
      [ud setValue: archiveData forKey: GGS_template_foreground_color] ;
      defaultColorIndex = 1 ;
    }
      [ud
        setObject: [colorTransformer reverseTransformedValue: defaultColorArray [defaultColorIndex]]
        forKey: name
      ] ;
  //--- By default, font is courier 13
    name = [NSString stringWithFormat:@"%@_%@", GGS_template_font, [inTokenizer styleIdentifierForStyleIndex:0]] ;
    [allFontPreferenceNames addObject:name] ;
    if ([ud objectForKey:name] == nil) {
      [ud
        setObject: [NSArchiver archivedDataWithRootObject:[NSFont fontWithName:@"Courier" size:13.0]]
        forKey:name
      ] ;
    }
    [self
      setUpView: view
      withCurrentRectangle: & r
      withEnclosingRectangle: & enclosingRect
      withBackgroundColorBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_template_background_color, [inTokenizer styleIdentifierForStyleIndex:0]]
      withBackgroundActivationBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_enable_template_background, [inTokenizer styleIdentifierForStyleIndex:0]]
      withFontBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_template_font, [inTokenizer styleIdentifierForStyleIndex:0]]
      withForegroundColorBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_template_foreground_color, [inTokenizer styleIdentifierForStyleIndex:0]]
      withSettingTitle:@"Template String"
    ] ;
  }
  OC_GGS_ColorTransformer * colorTransformer = [OC_GGS_ColorTransformer new] ;
  for (NSInteger i=0; i<(NSInteger) inTokenizer.styleCount ; i++) {
  //--- By default, find an old style foreground color
//    NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_named_color, [inTokenizer styleIdentifierForStyleIndex:i]] ;
//    // NSLog (@"name '%@'", name) ;
//    if ([ud objectForKey: name] == nil) {
//    //--- Not found
//      NSArray * splitName = [[inTokenizer styleIdentifierForStyleIndex:i] componentsSeparatedByString:@"-"] ;
//      if ([splitName count] == 2) {
//        NSString * oldName = [NSString stringWithFormat:@"%@_%@", GGS_named_color, [splitName objectAtIndex:1]] ;
//        if ([ud objectForKey:oldName] != nil) {
//          [[NSUserDefaults standardUserDefaults]
//            setObject:[ud objectForKey:oldName]
//            forKey:name
//          ] ;
//        }
//      }
//    }
  //--- By default, background color is white
    NSString * name = [NSString stringWithFormat:@"%@_%@", GGS_named_background_color, [inTokenizer styleIdentifierForStyleIndex:i]] ;
    NSData * data = [ud objectForKey: name] ;
    if (data == nil) {
      [ud
        setObject: [colorTransformer reverseTransformedValue: [NSColor whiteColor]]
        forKey:name
      ] ;
    }else if ([colorTransformer transformedValue: data] == nil ) {
      NSColor * color = [NSUnarchiver unarchiveObjectWithData: data] ;
      NSData * archiveData = [colorTransformer reverseTransformedValue: color] ;
      if (archiveData == nil) {
        archiveData = [colorTransformer reverseTransformedValue: [NSColor whiteColor]] ;
      }
      [ud setValue: archiveData forKey: name] ;
    }
  //--- Find a default foreground color
    name = [NSString stringWithFormat:@"%@_%@", GGS_named_color, [inTokenizer styleIdentifierForStyleIndex:i]] ;
    data = [ud objectForKey: name] ;
    if (data == nil) {
      [ud
        setObject: [colorTransformer reverseTransformedValue: defaultColorArray [defaultColorIndex]]
        forKey:name
      ] ;
      defaultColorIndex = (defaultColorIndex + 1) % kDefaultColorCount ;
    }else if ([colorTransformer transformedValue: data] == nil ) {
      NSColor * color = [NSUnarchiver unarchiveObjectWithData: data] ;
      NSData * archiveData = [colorTransformer reverseTransformedValue: color] ;
      if (archiveData == nil) {
        archiveData = [colorTransformer reverseTransformedValue: defaultColorArray [defaultColorIndex]] ;
      }
      [ud setValue: archiveData forKey: name] ;
    }
   //--- By default, font is courier 13
    name = [NSString stringWithFormat:@"%@_%@", GGS_named_font, [inTokenizer styleIdentifierForStyleIndex:i]] ;
    [allFontPreferenceNames addObject: name] ;
    if ([ud objectForKey: name] == nil) {
      [ud
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
      withBackgroundActivationBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_named_enable_background, [inTokenizer styleIdentifierForStyleIndex:i]]
      withFontBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_named_font, [inTokenizer styleIdentifierForStyleIndex:i]]
      withForegroundColorBindingPath:[NSString stringWithFormat:@"values.%@_%@", GGS_named_color, [inTokenizer styleIdentifierForStyleIndex:i]]
      withSettingTitle:[inTokenizer styleNameForStyleIndex: i]
    ] ;
  }
  enclosingRect.size.height += 10.0 ;
  enclosingRect.origin.y -= 10.0 ;
  [view setFrame:enclosingRect] ;
//--- Set view to scroll view
  NSString * title = [inTokenizer tabItemTitle] ;
  NSTabViewItem * tvi = [[NSTabViewItem alloc] initWithIdentifier:title] ;
  [tvi setLabel:title] ;
  [mLexicalColoringTabView insertTabViewItem:tvi atIndex: (NSInteger) inIndex] ;
//--- Duplicate 'SetFont' Button
  NSButton * setFontButton = [[NSButton alloc] initWithFrame:[mSetFontButton frame]] ;
  [[setFontButton cell] setRepresentedObject:allFontPreferenceNames] ;
  [setFontButton setTitle:@"Set Font…"] ;
  [setFontButton setState:[mSetFontButton state]] ;
  [setFontButton setBezelStyle:[mSetFontButton bezelStyle]] ;
  [setFontButton setBordered:[mSetFontButton isBordered]] ;
  [setFontButton setAutoresizingMask:NSViewNotSizable] ;
  [setFontButton setTarget:self] ;
  [setFontButton setAction:@selector (setFontAction:)] ;
  [[tvi view] addSubview:setFontButton] ;
//--- IMPORTANT: the following instruction performs actual sizing of tvi view.
  [mLexicalColoringTabView selectTabViewItemAtIndex:(NSInteger) inIndex] ;
  NSScrollView * sc = [[NSScrollView alloc] initWithFrame:[mLexicalColoringScrollView frame]] ;
  [sc setHasHorizontalScroller:YES] ;
  [sc setHasVerticalScroller:YES] ;
  [sc setAutohidesScrollers:YES] ;
  [sc setBorderType:[mLexicalColoringScrollView borderType]] ;
  [sc setBackgroundColor:[mLexicalColoringScrollView backgroundColor]] ;
  [sc setDrawsBackground:YES] ;
  [sc setAutoresizesSubviews:YES] ;
  [sc setAutoresizingMask:[mLexicalColoringScrollView autoresizingMask]] ;
  [[tvi view] addSubview:sc] ;
  [sc setDocumentView:view] ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) setFontAction: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//--- Get all preference names
  mCurrentFontArray = [[inSender cell] representedObject] ;
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
  }
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

//----------------------------------------------------------------------------------------------------------------------

- (void) changeFont: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
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

//----------------------------------------------------------------------------------------------------------------------

- (void) setTextColorsPreferences {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSArray * tokenizerArray = tokenizers () ;
  for (NSUInteger t=0 ; t<[tokenizerArray count] ; t++) {
    OC_Lexique * tokenizer = [tokenizerArray objectAtIndex:t] ;
    [self setTextColorsAndFontForTokenizer:tokenizer atIndex:t] ;
  }
//--- Remove tabview item Model
  [mLexicalColoringTabView removeTabViewItem:[mLexicalColoringTabView tabViewItemAtIndex:(NSInteger) [tokenizerArray count]]] ;
  mLexicalColoringScrollView = nil ;
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Build Text Macros Menu

//----------------------------------------------------------------------------------------------------------------------

- (void) insertTextMacroWithIndex: (NSUInteger) inIndex
         titleComponents: (NSArray *) inTitleComponents
         intoMenu: (NSMenu *) inMenu {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  if ([inTitleComponents count] == 1) {
    [inMenu
      addItemWithTitle:[inTitleComponents lastObject]
      action:@selector (actionInsertTextMacro:)
      keyEquivalent:@""
    ] ;
    NSMenuItem * item = [inMenu itemAtIndex:[inMenu numberOfItems] - 1] ;
    [item setTag:(NSInteger) inIndex] ;
  }else{
  //--- Find or Add menu item
    NSInteger idx = [inMenu indexOfItemWithTitle:[inTitleComponents objectAtIndex:0]] ;
    if (idx < 0) {
      idx = [inMenu numberOfItems] ;
      [inMenu
        addItemWithTitle:[inTitleComponents objectAtIndex:0]
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
    NSMutableArray * components = [NSMutableArray new] ;
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

//----------------------------------------------------------------------------------------------------------------------
//
//       B U I L D    T E X T    M A C R O    M E N U                                            
//
//----------------------------------------------------------------------------------------------------------------------

- (void) buildTextMacroMenu {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSArray * tokenizerArray = tokenizers () ;
  NSUInteger macroCount = 0 ;
  for (OC_Lexique * tokenizer in tokenizerArray) {
    macroCount += [tokenizer textMacroCount] ;
  }
  if (macroCount == 0) {
    NSMenu * mainMenu = [NSApp mainMenu] ;
    [mainMenu removeItemAtIndex:[mainMenu indexOfItemWithSubmenu:mTextMacroMenu]];
  }else{
    for (NSUInteger i=0 ; i<tokenizerArray.count ; i++) {
      OC_Lexique * tokenizer = [tokenizerArray objectAtIndex:i] ;
      for (NSUInteger j=0 ; j<[tokenizer textMacroCount] ; j++) {
        NSString * title = [tokenizer textMacroTitleAtIndex:j] ;
        NSArray * components = [title componentsSeparatedByString:@"/"] ;
        [self
          insertTextMacroWithIndex:j
          titleComponents:components
          intoMenu:mTextMacroMenu
        ] ;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Build Option Items

//----------------------------------------------------------------------------------------------------------------------
//
//   B U I L D    B O O L    C O M M A N D    L I N E    O P T I O N S                           
//
//----------------------------------------------------------------------------------------------------------------------

- (void) buildBooleanCommandLineOptionsInView: (NSView *) inView
         enclosingRect: (NSRect *) ioRect {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSAutoresizingMaskOptions mask = (NSAutoresizingMaskOptions) (NSViewMaxXMargin | NSViewMinYMargin) ;
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  NSRect r  ;
  r.origin.x = 10.0 ;
  r.origin.y = ioRect->origin.y ;
  r.size.height = 20.0 ;
  for (NSUInteger i=0 ; i<[mBoolOptionArray count] ; i++) {
    OC_GGS_CommandLineOption * option = [mBoolOptionArray objectAtIndex:i] ;
    NSButton * cb = [NSButton new] ;
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
    [cb setAutoresizingMask: mask] ;
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

//----------------------------------------------------------------------------------------------------------------------
//
//   B U I L D    U I N T    C O M M A N D    L I N E    O P T I O N S                           
//
//----------------------------------------------------------------------------------------------------------------------

- (void) buildUnsignedIntegerCommandLineOptionsInView: (NSView *) inView
         enclosingRect: (NSRect *) ioRect {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSAutoresizingMaskOptions mask = (NSAutoresizingMaskOptions) (NSViewMaxXMargin | NSViewMinYMargin) ;
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  NSDictionary * optionDictionary = [NSDictionary
    dictionaryWithObject:[NSNumber numberWithBool:YES]
    forKey:NSContinuouslyUpdatesValueBindingOption
  ] ;
  NSRect r;
  r.origin.x = 10.0 ;
  r.origin.y = ioRect->origin.y ;
  r.size.height = 20.0 ;
  for (NSUInteger i=0 ; i<mUIntOptionArray.count ; i++) {
    OC_GGS_CommandLineOption * option = [mUIntOptionArray objectAtIndex:i] ;
  //--- Input text field
    NSTextField * tx = [NSTextField new] ;
    [tx setAutoresizingMask: mask] ;
  //--- Add formatter
    NSNumberFormatter * format = [NSNumberFormatter new] ;
    [format setFormat:@"#0;0;-#0"] ;
    [format setMinimum:[NSDecimalNumber zero]] ;
    [format setAllowsFloats:NO] ;
    [[tx cell] setFormatter:format] ;
    r.origin.x = 10.0 ;
    r.size.width = 80.0 ;
    r.origin.y -= 25.0 ;
    [tx setFrame: r] ;
    [tx setTag: (NSInteger) i] ;
    [tx
      bind:@"value"
      toObject:udc
      withKeyPath:[NSString stringWithFormat:@"values.%@_%@", GGS_uint_build_option, [option identifier]]
      options:optionDictionary
    ] ;
    [inView addSubview: tx] ;
    *ioRect = NSUnionRect (*ioRect, r) ;
  //--- Comment text
    tx = [NSTextField new] ;
    NSString * title = [option title] ;
    [tx setStringValue:title] ;
    [tx setAutoresizingMask: mask] ;
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

//----------------------------------------------------------------------------------------------------------------------
//
//   B U I L D    U I N T    C O M M A N D    L I N E    O P T I O N S                           
//
//----------------------------------------------------------------------------------------------------------------------

- (void) buildStringCommandLineOptionsInView: (NSView *) inView
         enclosingRect: (NSRect *) ioRect {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSAutoresizingMaskOptions mask = (NSAutoresizingMaskOptions) (NSViewMaxXMargin | NSViewMinYMargin) ;
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
  for (NSUInteger i=0 ; i<mStringOptionArray.count ; i++) {
    OC_GGS_CommandLineOption * option = [mStringOptionArray objectAtIndex:i] ;
  //--- Input text field
    NSTextField * tx = [NSTextField new] ;
    [tx setAutoresizingMask: mask] ;
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
    tx = [NSTextField new] ;
    NSString * title = [option title] ;
    [tx setStringValue:title] ;
    [tx setAutoresizingMask: mask] ;
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

//----------------------------------------------------------------------------------------------------------------------
//
//   POPULATE TOOL POPUPBUTTON                                                                   
//
//----------------------------------------------------------------------------------------------------------------------

- (void) populateToolPopupButtonInView: (NSView *) inView {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//--- Get default settings
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
//--- Populate
  [mToolPopUpButton removeAllItems] ;
  NSString * resourcePath = [[NSBundle mainBundle] resourcePath] ;
  NSFileManager * fm = [NSFileManager new] ;
  NSDirectoryEnumerator * dirEnum = [fm enumeratorAtPath:resourcePath];
  NSString * path = dirEnum.nextObject ;
  while (path != nil) {
    if ([path.pathExtension isEqualToString: @""] && (path.stringByDeletingLastPathComponent.length == 0)) {
      [mToolPopUpButton addItemWithTitle:path] ;
      [mToolNameArray addObject:path] ;
    }
    path = dirEnum.nextObject ;
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

//----------------------------------------------------------------------------------------------------------------------
//
//       A W A K E    F R O M    N I B                                                           
//
//----------------------------------------------------------------------------------------------------------------------

- (void) awakeFromNib {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  // NSLog (@"%s", __PRETTY_FUNCTION__) ;
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSNotificationCenter  * nc = [NSNotificationCenter defaultCenter] ;
  OC_GGS_ColorTransformer * colorTransformer = [OC_GGS_ColorTransformer new] ;
//--- Page guide
  if ([ud valueForKey:GGS_uses_page_guide] == nil) {
    [ud setBool:YES forKey:GGS_uses_page_guide] ;
  }
  [mPageGuideCheckbox
    bind:@"value"
    toObject:udc
    withKeyPath:@"values." GGS_uses_page_guide
    options:nil
  ] ;
  [mPageGuideColumnTextField
    bind:@"enabled"
    toObject:udc
    withKeyPath:@"values." GGS_uses_page_guide
    options:nil
  ] ;
  if ([ud valueForKey:GGS_page_guide_column] == nil) {
    [ud setInteger:80 forKey:GGS_page_guide_column] ;
  }
  [mPageGuideColumnTextField
    bind:@"value"
    toObject:udc
    withKeyPath:@"values." GGS_page_guide_column
    options:nil
  ] ;
//--- Editor background color
  NSData * data_GGS_editor_background_color = [ud valueForKey: GGS_editor_background_color] ;
  if (data_GGS_editor_background_color == nil) {
    NSData * archiveData = [colorTransformer reverseTransformedValue: [NSColor whiteColor]] ;
    [ud setValue: archiveData forKey: GGS_editor_background_color] ;
  }else if ([colorTransformer transformedValue: data_GGS_editor_background_color] == nil ) {
    NSColor * color = [NSUnarchiver unarchiveObjectWithData: data_GGS_editor_background_color] ;
    NSData * archiveData = [colorTransformer reverseTransformedValue: color] ;
    if (archiveData == nil) {
      archiveData = [colorTransformer reverseTransformedValue: [NSColor whiteColor]] ;
    }
    [ud setValue: archiveData forKey: GGS_editor_background_color] ;
  }
  [mEditorBackgroundColorWell
    bind:@"value"
    toObject:udc
    withKeyPath:@"values." GGS_editor_background_color
    options:[NSDictionary dictionaryWithObjectsAndKeys:
      colorTransformer, NSValueTransformerBindingOption,
      nil
    ]
  ] ;
//--- Bind « Prefix by time Utility » checkbox
  [mPrefixByTimeUtilityCheckBox
    bind:@"value"
    toObject:udc
    withKeyPath:@"values." GGS_prefix_by_tool_utility
    options:nil
  ] ;
//--- Add observer to user defaults changes
  [nc addObserver: self selector: @selector(preferencesDidChange:) name: NSUserDefaultsDidChangeNotification object: ud] ;
//--- Load tool nibs ?
  NSArray * nibArray = nibsAndClasses () ;
  mArrayOfNibTopObjects = [NSArray array] ;
  for (NSUInteger i=0 ; i<[nibArray count] ; i++) {
    NSArray * entry = [nibArray objectAtIndex:i] ;
    NSString * nibName = [entry objectAtIndex:0] ;
    Class mainClass = [entry objectAtIndex:1] ;
    id owner = [mainClass new] ;
    NSArray * objects = nil ;
    [[NSBundle mainBundle] loadNibNamed:nibName owner:owner topLevelObjects:& objects] ;
    mArrayOfNibTopObjects = [mArrayOfNibTopObjects arrayByAddingObjectsFromArray:objects] ;
  }
//--- Get default settings
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
//--- Tab Key inserts spaces
  if ([defaults integerForKey:GGS_editor_space_for_tab] == 0) {
    [defaults setInteger:2 forKey:GGS_editor_space_for_tab] ;
  }
  [mTabInsertsSpacesTextField
    bind:@"value"
    toObject:udc
    withKeyPath:@"values." GGS_editor_space_for_tab
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
    [mPreferenceWindow setTitle:preferencesWindowTitle] ;
  }
//--- Get default font, used when there is no preference setting
  [mCurrentBuildWindowFontAndSizeSettingsButton
    bind:@"fontValue"
    toObject:udc
    withKeyPath:[NSString stringWithFormat:@"values.%@", GGS_build_text_font]
    options:NULL
  ] ;
  if ([defaults objectForKey:GGS_build_text_font] == nil) {
    NSFont * defaultFont = [NSFont fontWithName:@"Courier" size:13.0] ;
    [defaults setObject:[NSArchiver archivedDataWithRootObject:defaultFont] forKey:GGS_build_text_font] ;
  }
//--- 'Enable Completion' checkbox
  if ([defaults objectForKey:GGS_enable_completion] == nil) {
    [defaults setBool:YES forKey:GGS_enable_completion] ;
  }
  [mEnableCompletionCheckBox
    bind:@"value"
    toObject:udc
    withKeyPath:@"values." GGS_enable_completion
    options:nil
  ] ;
//--- Build text color user interface
  [self setTextColorsPreferences] ;
//--- Check "Verbose" option if not defined
  NSString * keyForVerboseOption = [NSString stringWithFormat:@"%@_%s", GGS_bool_build_option, "verbose"] ;
  NSNumber * verboseOption = [defaults objectForKey:keyForVerboseOption] ;
  if (verboseOption == nil) {
    [defaults setBool:YES forKey: keyForVerboseOption] ;
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
    toObject:udc
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
    toObject:udc
    withKeyPath:@"values.PMConvert_CRLF_And_CR_To_LF_AtStartUp"
    options:NULL
  ] ;
//--- Convert HTAB on document opening
  if ([ud objectForKey:@"PMConvert_HTAB_To_SPACE_AtStartUp"] == nil) {
    [ud setObject:[NSNumber numberWithBool:YES] forKey:@"PMConvert_HTAB_To_SPACE_AtStartUp"] ;
  }
  [mConvert_HTAB_To_SPACE_AtStartUpButton
    bind:@"value"
    toObject:udc
    withKeyPath:@"values.PMConvert_HTAB_To_SPACE_AtStartUp"
    options:NULL
  ] ;
//--- Show Invisible Characters Checkbox
 [mShowInvisibleCharactersCheckBox
    bind:@"value"
    toObject:udc
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
  [self updateSourceTextPreferenceCount] ;
//---
  [mLexicalColoringTabView selectTabViewItemAtIndex:0] ;
//---  
  #ifdef PM_HANDLE_UPDATE
    [PMApplicationUpdate instanciateSingleton] ;
  #endif
}

//----------------------------------------------------------------------------------------------------------------------

- (void) preferencesDidChange: (id) inUsedArgument {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  [self willChangeValueForKey:@"commandLineString"] ;
  [self  didChangeValueForKey:@"commandLineString"] ;
}

//----------------------------------------------------------------------------------------------------------------------

- (NSArray *) toolNameArray {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  return mToolNameArray ;
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Preferences Change

//----------------------------------------------------------------------------------------------------------------------

- (IBAction) toolSelectionDidChange: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  const NSInteger selectedToolIndex = [mToolPopUpButton indexOfSelectedItem] ;
  NSUserDefaults * defaults = [NSUserDefaults standardUserDefaults] ;
  [defaults setObject:[NSNumber numberWithInteger:selectedToolIndex] forKey:GGS_tool_selection_preference] ;
  [self willChangeValueForKey:@"commandLineString"] ;
  [self  didChangeValueForKey:@"commandLineString"] ;
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Track Window Moving and Resizing

//----------------------------------------------------------------------------------------------------------------------
//
//                              windowDidMove:                                                   
//
//----------------------------------------------------------------------------------------------------------------------

- (void) windowDidMove: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSWindow * window = [inNotification object] ;
  NSString * s = [window stringWithSavedFrame] ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  [ud setObject:s forKey:GGS_preference_window_frame] ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//                             windowDidResize:                                                  
//
//----------------------------------------------------------------------------------------------------------------------

- (void) windowDidResize: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSWindow * window = [inNotification object] ;
  NSString * s = [window stringWithSavedFrame] ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  [ud setObject:s forKey:GGS_preference_window_frame] ;
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark User Actions

//----------------------------------------------------------------------------------------------------------------------
//
//       O P E N    A N    U N T I T L E D    D O C U M E N T    A T    S T A R T U P             
//
//----------------------------------------------------------------------------------------------------------------------

- (BOOL) applicationShouldOpenUntitledFile: (NSApplication *) inSender {
  return NO ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//       ALL DOCUMENT EXTENSIONS
//
//----------------------------------------------------------------------------------------------------------------------

- (NSSet *) allExtensionsOfCurrentApplication {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//  NSMutableArray * allTypes = [NSMutableArray new] ;
  NSDictionary * infoDictionary = [[NSBundle mainBundle] infoDictionary] ;
//  NSLog (@"infoDictionary %@", infoDictionary) ;
//  NSArray * allDocumentTypes = [infoDictionary objectForKey: @"CFBundleDocumentTypes"] ;
  NSArray * exportedTypeDeclarations = [infoDictionary objectForKey: @"UTExportedTypeDeclarations"] ;
//  NSLog (@"exportedTypeDeclarations %@", exportedTypeDeclarations) ;
  NSMutableSet * extensionSet = [NSMutableSet new] ;
  for (NSDictionary * exportedType in exportedTypeDeclarations) {
    NSDictionary * tagSpecifDictionary = [exportedType objectForKey: @"UTTypeTagSpecification"] ;
    NSArray * fileExtensions = [tagSpecifDictionary objectForKey: @"public.filename-extension"] ;
    if (fileExtensions.count > 0) {
      [extensionSet addObjectsFromArray: fileExtensions] ;
    }
//    for (NSString * extension in fileExtensions) {
//      NSLog (@"  extension %@", extension) ;
//    }
//    [allTypes addObjectsFromArray:a] ;
  }
  return extensionSet ;
//  return allTypes ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//       A C T I O N    N E W  D O C U M E N T                                                   
//
//----------------------------------------------------------------------------------------------------------------------

- (void) changeNewDocumentTypeAction: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
//--- Get Info.plist file
  NSDictionary * infoDictionary = [[NSBundle mainBundle] infoDictionary] ;
  // NSLog (@"infoDictionary '%@'", infoDictionary) ;
  NSArray * allDocumentTypes = [infoDictionary objectForKey:@"CFBundleDocumentTypes"] ;
  // NSLog (@"allDocumentTypes '%@'", allDocumentTypes) ;
  NSDictionary * docTypeDict = [allDocumentTypes objectAtIndex: (NSUInteger) [inSender tag]] ;
  NSArray * documentTypeExtensions = [docTypeDict objectForKey:@"CFBundleTypeExtensions"] ;
  NSString * extension = [documentTypeExtensions objectAtIndex:0] ;
  // NSLog (@"extension '%@'", extension) ;
  NSSavePanel * savePanel = [inSender representedObject] ;
//  [savePanel setRequiredFileType:extension] ;
  [savePanel setAllowedFileTypes:[NSArray arrayWithObject:extension]] ;
}

//----------------------------------------------------------------------------------------------------------------------

- (void) newDocument: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSSavePanel * savePanel = [NSSavePanel savePanel] ;
  [mNewDocumentTypePopUpButton removeAllItems] ;
//--- Get Info.plist file
  NSDictionary * infoDictionary = [[NSBundle mainBundle] infoDictionary] ;
  // NSLog (@"infoDictionary '%@'", infoDictionary) ;
  NSArray * allDocumentTypes = [infoDictionary objectForKey:@"CFBundleDocumentTypes"] ;
  // NSLog (@"allDocumentTypes '%@'", allDocumentTypes) ;
  for (NSUInteger i=0 ; i<[allDocumentTypes count] ; i++) {
    NSDictionary * docTypeDict = [allDocumentTypes objectAtIndex:i] ;
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
      [item setTag:(NSInteger) i] ;
      [item setRepresentedObject:savePanel] ;
    }
  }
//--- Present save panel
  [savePanel setAllowsOtherFileTypes:NO] ;
  [savePanel setCanSelectHiddenExtension:YES] ;
  [savePanel setAccessoryView:mNewDocumentAccessoryView] ;
  [self changeNewDocumentTypeAction:[mNewDocumentTypePopUpButton itemAtIndex:0]] ;
//  const NSInteger result = [savePanel runModalForDirectory:nil file:nil] ;
  const NSInteger result = [savePanel runModal] ;
  // NSLog (@"result %d", result) ;
  if (result == NSOKButton) {
    NSString * path = savePanel.URL.path ;
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

//----------------------------------------------------------------------------------------------------------------------

- (IBAction) showAllocationWindow: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  showAllocationStatsWindow () ;
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Termination Handling

//----------------------------------------------------------------------------------------------------------------------

- (NSApplicationTerminateReply) applicationShouldTerminate:(NSApplication *)sender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  BOOL canTerminateApplication = YES ;
  for (OC_GGS_Document * doc in [[NSDocumentController sharedDocumentController] documents]) {
    if (doc.mBuildTaskIsRunning) {
      canTerminateApplication = NO ;
    }
  }
  if (! canTerminateApplication) {
    const NSInteger response = NSRunAlertPanel (@"Application cannot terminate while build tasks are running.",
                                    @"You can cancel termination, or force tasks to terminate.",
                                    @"Cancel", @"Stop Tasks and Quit", nil) ;
    canTerminateApplication = response == NSAlertAlternateReturn ;
  }
  return canTerminateApplication ? NSTerminateNow : NSTerminateCancel ;
}

//----------------------------------------------------------------------------------------------------------------------

#pragma mark Source text preferences

//----------------------------------------------------------------------------------------------------------------------

- (void) updateSourceTextPreferenceCount {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSBundle * mb = [NSBundle mainBundle] ;
  NSDictionary * dictionaryRepresentation = [ud persistentDomainForName:[mb bundleIdentifier]] ;
  NSArray * allKeys = [dictionaryRepresentation allKeys] ;
  NSUInteger n = 0 ;
  const NSRange rangeGGS = {0, 4} ;
  const NSRange rangeNS = {0, 2} ;
  for (NSUInteger i=0 ; i<allKeys.count ; i++) {
    NSString * key = [allKeys objectAtIndex:i] ;
    if (([key compare:@"GGS_" options:NSLiteralSearch range:rangeGGS] != NSOrderedSame) &&
        ([key compare:@"NS" options:NSLiteralSearch range:rangeNS] != NSOrderedSame) &&
        (! [key isEqualToString:@"PMConvert_CRLF_And_CR_To_LF_AtStartUp"]) &&
        (! [key isEqualToString:@"PMConvert_HTAB_To_SPACE_AtStartUp"])) {
      n ++ ;
      // NSLog (@"key '%@'", key) ;
    }
  }
  NSString * s = @"No source document preferences entry." ;
  if (n == 1) {
    s = @"1 source document preferences entry." ;
  }else if (n > 1) {
    s = [NSString stringWithFormat:@"%lu source document preferences entries.", n] ;
  }
  [mSourcePreferenceStatsTextField setStringValue:s] ;
}

//----------------------------------------------------------------------------------------------------------------------

- (IBAction) clearSourceDocumentPreferencesEntries: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"%s", __PRETTY_FUNCTION__) ;
  #endif
  NSBundle * mb = [NSBundle mainBundle] ;
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSDictionary * dictionaryRepresentation = [ud persistentDomainForName:[mb bundleIdentifier]] ;
  NSArray * allKeys = [[dictionaryRepresentation allKeys] copy] ;
  const NSRange rangeGGS = {0, 4} ;
  const NSRange rangeNS = {0, 2} ;
  for (NSUInteger i=0 ; i<allKeys.count ; i++) {
    NSString * key = [allKeys objectAtIndex:i] ;
    if (([key compare:@"GGS_" options:NSLiteralSearch range:rangeGGS] != NSOrderedSame) &&
        ([key compare:@"NS" options:NSLiteralSearch range:rangeNS] != NSOrderedSame) &&
        (! [key isEqualToString:@"PMConvert_CRLF_And_CR_To_LF_AtStartUp"]) &&
        (! [key isEqualToString:@"PMConvert_HTAB_To_SPACE_AtStartUp"])) {
      [ud setObject:nil forKey:key] ;
    }
  }
  [ud synchronize] ;
  [self updateSourceTextPreferenceCount] ;
}

//----------------------------------------------------------------------------------------------------------------------

@end
