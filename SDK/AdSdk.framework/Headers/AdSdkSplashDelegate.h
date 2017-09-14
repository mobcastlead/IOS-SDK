//
//  AdSdkSplashDelegate.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/9/6.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AdSdkSplashDelegate <NSObject>

-(void)splashInitResult:(NSInteger)code;

-(void)splashDidLoading;

-(void)splashDidLoadingFinish;

-(void)splashDidLoadingError:(NSInteger)errorCode;

-(void)splashReportViewOKay;

-(void)splashReportClickOKay;

-(void)splashLandingPageLoadOkay;

-(void)splashLandingPageLoadError;

-(void)splashAppStoreLoadOkay;

-(void)splashDidDismissScreen;
@end
