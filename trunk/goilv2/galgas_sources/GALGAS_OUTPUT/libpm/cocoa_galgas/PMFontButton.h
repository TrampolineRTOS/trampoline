//-----------------------------------------------------------------------------*
//                                                                             *
//                          File 'PMFontButton.h'                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>

//-----------------------------------------------------------------------------*

@interface PMFontButton : NSButton {

//--- Attributes for 'fontValue' binding
  @protected id mBoundObjectFor_fontValue ;
  @protected NSString * mKeyPathFor_fontValue ;

  @protected  BOOL mFontButtonBindingEnableState ;
  @protected  BOOL mInheritedEnableState ;

}

//--- Method for 'fontValue' binding
  - (void) applyNewFontValue: (id) inValue ;
  - (void) valueFor_fontValue_didChange_marker: (id) inMarker
           defaultPlaceholder: (id) inDefaultPlaceHolder ;
  - (void) valueFor_fontValue_didChange_NSFont: (NSFont *) inValue ;

@end

//-----------------------------------------------------------------------------*

