//
//  AdSdkBanner.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/4/20.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AdsSdkBannerDelegate.h"

@interface AdSdkBanner : UIView

//横幅广告位代理
@property (nonatomic, weak) id<AdSdkBannerDelegate> _delegate;

//初始化一个横幅广告位
-(instancetype)initWithFrame:(CGRect)frame adposid:(NSString*)adposid delegate:(id<AdSdkBannerDelegate>)delegate;

//加载一个横幅广告
-(void) load;
@end
