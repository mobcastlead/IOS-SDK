//
//  AdSdkInterstital.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/5/8.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AdSdkInterstitalDelegate.h"


@interface AdSdkInterstital : NSObject

+(AdSdkInterstital *)shareInterstital;

//插屏代理
@property (nonatomic, weak) id<AdSdkInterstitalDelegate> _delegate;

-(void)interstitalInitWithInfo:(CGRect)frame adposid:(NSString *)adposid delegate:(id<AdSdkInterstitalDelegate>)delegate;

//加载一个插屏广告
-(void) load;

@end
