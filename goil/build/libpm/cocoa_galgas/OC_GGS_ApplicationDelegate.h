//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2003, ..., 2019 Pierre Molinaro.
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

#import <Cocoa/Cocoa.h>

//----------------------------------------------------------------------------------------------------------------------

#define GGS_prefix_by_tool_utility           @"PMPrefixByTimeUtility"
#define GGS_selected_tab                     @"GGS_selected_tab"
#define GGS_enable_completion                @"GGS_enable_completion"
#define GGS_build_text_font                  @"GGS_build_window_text_font"
#define GGS_indexed_color                    @"GGS_colors"
#define GGS_named_color                      @"GGS_color_for_style"
#define GGS_named_background_color           @"GGS_background_color_for_style"
#define GGS_named_enable_background          @"GGS_enable_background_color_for_style"
#define GGS_named_font                       @"GGS_font_attribute_for_style"
#define GGS_bool_build_option                @"GGS_bool_build_option"
#define GGS_uint_build_option                @"GGS_uint_build_option"
#define GGS_string_build_option              @"GGS_string_build_option"
#define GGS_preference_window_frame          @"GGS_preference_window_frame"
#define GGS_default_encoding_for_new_file @"GGS_default_encoding_for_new_file"
#define GGS_default_encoding_for_existing_file @"GGS_default_encoding_for_existing_file"
#define GGS_operation_on_opening_file_with_undecidable_encoding @"GGS_operation_on_opening_file_with_undecidable_encoding"
#define GGS_tool_selection_preference @"GGS_tool_selection_preference"

#define GGS_template_background_color  @"GGS_template_background_color"
#define GGS_template_font              @"GGS_template_font"
#define GGS_template_foreground_color  @"GGS_template_foreground_color"
#define GGS_enable_template_background @"GGS_enable_template_foreground_color"

#define GGS_uses_page_guide           @"GGS_USE_PAGE_GUIDE"
#define GGS_page_guide_column         @"GGS_PAGE_GUIDE_COLUMN"
#define GGS_editor_background_color   @"GGS_EDITOR_BACKGROUND_COLOR"
#define GGS_editor_space_for_tab      @"GGS_EDITOR_SPACES_FOR_TAB"

//----------------------------------------------------------------------------------------------------------------------

@class OC_GGS_Document ;
@class OC_GGS_ApplicationDelegate ;
@class PMFontButton ;

//----------------------------------------------------------------------------------------------------------------------

extern OC_GGS_ApplicationDelegate * gCocoaApplicationDelegate ;

//----------------------------------------------------------------------------------------------------------------------

@interface OC_GGS_ApplicationDelegate : NSObject <NSWindowDelegate> {
//--- Text Macros Menu
  @private IBOutlet NSMenu * mTextMacroMenu ;

//--- Preferences Tab View
  @private IBOutlet NSTabView * mPreferencesTabView ;

//--- Tool popup button
  @private IBOutlet NSPopUpButton * mToolPopUpButton ;
  @private NSMutableArray * mToolNameArray ;

//--- Prefix by time utility
  @private IBOutlet NSButton * mPrefixByTimeUtilityCheckBox ;

  @private IBOutlet NSButton * mEnableCompletionCheckBox ;
  @private IBOutlet NSButton * mConvert_CRLF_And_CR_To_LF_AtStartUpButton ;
  @private IBOutlet NSButton * mConvert_HTAB_To_SPACE_AtStartUpButton ;
  @private IBOutlet NSButton * mShowInvisibleCharactersCheckBox ;

//---
  @private IBOutlet NSTextField * mTabInsertsSpacesTextField ;

//--- Preference Window
  @private IBOutlet NSWindow * mPreferenceWindow ;

//--- Preference Window
  @private IBOutlet NSColorWell * mEditorBackgroundColorWell ;

//--- Font build window
  @private IBOutlet PMFontButton * mCurrentBuildWindowFontAndSizeSettingsButton ;

//--- Source preference outlet
  @private IBOutlet NSTextField * mSourcePreferenceStatsTextField ;

//--- Displaying the command line options
  @private NSArray * mCommandLineItemArray ;

//--- Displaying the command line options
  @private IBOutlet NSScrollView * mCommandLineOptionScrollView ;

//--- Displaying the command line
  @private IBOutlet NSTextView * mCommandLineOptionTextView ;

//--- Lexical Coloring Scroll View
  @private IBOutlet NSTabView * mLexicalColoringTabView ;
  @private IBOutlet NSScrollView * mLexicalColoringScrollView ;
  @private IBOutlet NSButton * mSetFontButton ;

//--- Changing all fonts
  @private NSArray * mCurrentFontArray ;

//--- Command line option
  @private NSMutableArray * mBoolOptionArray ;
  @private NSMutableArray * mUIntOptionArray ;
  @private NSMutableArray * mStringOptionArray ;
  @private NSMutableArray * mStringListOptionArray ;
  
//---
  @private IBOutlet NSPopUpButton * mNewDocumentTypePopUpButton ;
  @private IBOutlet NSView * mNewDocumentAccessoryView ;

  @private NSArray * mArrayOfNibTopObjects ;

//--- Page guide
  @private IBOutlet NSButton * mPageGuideCheckbox ;
  @private IBOutlet NSTextField * mPageGuideColumnTextField ;
}

- (NSSet *) allExtensionsOfCurrentApplication ;

- (IBAction) clearSourceDocumentPreferencesEntries: (id) inSender ;

- (IBAction) showAllocationWindow: (id) inSender ;

- (void) updateSourceTextPreferenceCount ;

- (NSArray *) commandLineItemArray ;

- (void) windowDidMove: (NSNotification *) aNotification ;

- (NSTabView *) preferencesTabView ;

- (NSArray *) toolNameArray ;

- (NSInteger) selectedToolIndex ;

- (NSString *) compilerToolPath: (NSInteger) inSelectedToolIndex ;

- (BOOL) prefixByToolUtility ;

- (NSString *) toolUtilityPrefix ;
@end

//----------------------------------------------------------------------------------------------------------------------
