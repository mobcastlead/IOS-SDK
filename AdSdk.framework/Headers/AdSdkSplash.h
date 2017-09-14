//
//  AdSdkSplash.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/9/6.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdSdkSplashDelegate.h"

@interface AdSdkSplash : UIView

+(AdSdkSplash *)shareSplash;

@property (nonatomic, weak) id<AdSdkSplashDelegate> _delegate;

//初始化以及请求一个广告
-(instancetype)initAndRequestAd:(CGRect)frame adposid:(NSString*)adposid delegate:(id<AdSdkSplashDelegate>)delegate;

//加载此开屏广告
-(void) load;

@end
