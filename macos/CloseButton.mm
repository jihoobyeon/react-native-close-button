#import "CloseButton.h"

@implementation CloseButton { BOOL _allowClose; }
- (void)install {

    dispatch_async(dispatch_get_main_queue(), ^{
        [self installWindowDelegate];
    });
}

- (void)installWindowDelegate {
		NSWindow *window = [NSApp mainWindow];
		
		if (window) {
				window.delegate = self;
		}
}

- (BOOL)windowShouldClose:(NSWindow *)window {
    // closeNow() triggred
    if (_allowClose) {
        _allowClose = NO;
        return YES;
    }
	
    // send close event to JavaScript side
    [self emitOnBeforeClose];
	
    // do not close app window until JavaScript does
    return NO;
}

- (void)closeNow {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSWindow *window = [NSApp mainWindow];
				
        if (window) {
            self->_allowClose = YES;
            [window close];
        }
    });
}

- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
	return std::make_shared<facebook::react::NativeCloseButtonSpecJSI>(params);
}

+ (NSString *)moduleName
{
  return @"CloseButton";
}

@end
