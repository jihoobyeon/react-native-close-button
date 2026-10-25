#import "CloseButton.h"

@implementation CloseButton { RCTResponseSenderBlock _toDo; }
- (void)doBeforeClose:(RCTResponseSenderBlock)toDo {
	_toDo = toDo;
	
	dispatch_async(dispatch_get_main_queue(), ^{
		NSWindow *window = [NSApp mainWindow];
		if (window) [window setDelegate:self];
	});
}

- (BOOL)windowShouldClose:(NSWindow *)window {
	if (_toDo)
		dispatch_async(dispatch_get_main_queue(), ^{
			self->_toDo(@[[NSNull null]]);
			self->_toDo = nil;
		});
	return NO;
}

- (void)closeNow {
	dispatch_async(dispatch_get_main_queue(), ^{
    NSWindow *window = [NSApp mainWindow];
		if (window) [window close];
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
