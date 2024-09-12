
#ifdef RCT_NEW_ARCH_ENABLED
#import "RNCloseButtonSpec.h"

@interface CloseButton : NSObject <NativeCloseButtonSpec>
#else
#import <React/RCTBridgeModule.h>

@interface CloseButton : NSObject <RCTBridgeModule>
#endif

@end
