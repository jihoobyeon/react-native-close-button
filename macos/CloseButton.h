
#ifdef RCT_NEW_ARCH_ENABLED
#import <RNCloseButtonSpec/RNCloseButtonSpec.h>

@interface CloseButton : NSObject <NativeCloseButtonSpec, NSWindowDelegate>
#else
#import <React/RCTBridgeModule.h>

@interface CloseButton : NSObject <RCTBridgeModule>
#endif

@end
