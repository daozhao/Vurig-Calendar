//
//  VRGAppDelegate.m
//  Vurig Calendar
//
//  Created by in 't Veen Tjeerd on 5/29/12.
//  Copyright (c) 2012 Vurig. All rights reserved.
//

#import "VRGAppDelegate.h"

#import "VRGViewController.h"
#import "ARCSupporDefine.h"

@implementation VRGAppDelegate

@synthesize window = _window;
@synthesize viewController = _viewController;

- (void)dealloc
{
    [_window release];
    [_viewController release];
    [super don_dealloc];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    self.window = [[[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]] autorelease];

    self.viewController = [[[VRGViewController alloc] init] autorelease];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    return YES;
}

@end
