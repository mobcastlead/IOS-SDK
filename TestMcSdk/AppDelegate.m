//
//  AppDelegate.m
//  TestMcSdk
//
//  Created by 冉文龙 on 2017/9/14.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import "AppDelegate.h"

#import <AdSdk/AdSdk.h>

//测试开发者ID
#ifndef MEXSDK_PUBLISHER_ID
#define MEXSDK_PUBLISHER_ID   @"598d45d21ad88e0100042f5f"
#endif

//测试开发者Token
#ifndef MEXSDK_PUBLISHER_TOKEN
#define MEXSDK_PUBLISHER_TOKEN   @"f1c4d8adbaaa81143bd0055779447513"
#endif

//测试应用ID
#ifndef MEXSDK_APP_ID
#define MEXSDK_APP_ID   @"598d465c1ad88e0100042f6f"
#endif

@interface AppDelegate () <AdSdkDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [AdSdk setSdkLogLevel: AdSDKLogLevelDebug];
    [AdSdk initWithAdSdkToken:MEXSDK_PUBLISHER_TOKEN publisherid:MEXSDK_PUBLISHER_ID appid:MEXSDK_APP_ID failTryCount:2 delegate: self];
    
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}

-(void)AdSdkInitResult:(AdSdkInitErrorCode)errorCode initCount:(NSInteger)initCount{
    NSLog(@"AdSdk init result: code=%d, initCount=%ld", errorCode, (long)initCount);
}

@end
