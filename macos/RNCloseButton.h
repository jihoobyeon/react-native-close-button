
#ifdef RCT_NEW_ARCH_ENABLED
#import <RNCloseButtonSpec/RNCloseButtonSpec.h>

@interface RNCloseButton : NSObject <NativeRNCloseButtonSpec, NSWindowDelegate>
#else
#import <React/RCTBridgeModule.h>

@interface RNCloseButton : NSObject <RCTBridgeModule, NSWindowDelegate>
#endif

@end
