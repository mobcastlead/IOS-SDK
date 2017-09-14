//
//  AdSdkDelegate.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/4/26.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdSdkCommConstants.h"

@protocol AdSdkDelegate <NSObject>

//初始化结果
-(void)AdSdkInitResult: (AdSdkInitErrorCode) errorCode
             initCount: (NSInteger)initCount;

@end
