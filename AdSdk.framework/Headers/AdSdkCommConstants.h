//
//  AdSdkCommConstants.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/4/20.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#ifndef AdSdkCommConstants_h
#define AdSdkCommConstants_h

#import <UIKit/UIKit.h>
#import "AdSdkHttpRequest.h"
#import "AdSdkLogCenter.h"
#import "AdSdkDeviceInfo.h"
#import "AdSdkConfigData.h"

#import "AdSdkBanner.h"
#import "AdsSdkBannerDelegate.h"
#import "AdSdkInterstital.h"
#import "AdSdkInterstitalDelegate.h"
#import "AdSdkSplash.h"
#import "AdSdkSplashDelegate.h"

typedef enum {
    //初始化成功
    AdSdkInitSuccess            = 10001,
    
    //本机网络异常
    AdSdkInitFailWithNet        = 10002,
    
    //本机网络响应非200
    AdSdkInitFailWithResCodeNotOk = 10003,
    
    //AdSdk服务器没有响应
    AdSdkInitFailWithNoRes      = 10004,
    
    //AdSdk服务器没有响应异常
    AdSdkInitFailWithResError   = 10005,
    
    //AdSdk 开发者异常
    AdSdkInitFailWithPublisher  = 10006,
}AdSdkInitErrorCode;

typedef enum {
    //初始化成功
    AdSdkSlotInitSuccess           = 20001,
    
    //初始化成功,但未有请求到广告，开屏时候会使用
    AdSdkSlotInitSuccessWithNoAd   = 20002,
    
    //Sdk未初始化成功
    AdSdkSlotInitFailSdkInitError  = 20003,
    
    //广告位未配置
    AdSdkSlotInitFailSdkPosIdError  = 20004,
    
    //广告位暂停
    AdSdkSlotInitFailSdkPosIdPause  = 20005,
    
    //广告位删除
    AdSdkSlotInitFailSdkPosIdDelete = 20006,
    
    //广告未准备好
    AdSdkSlotLoadFailAdNotReady     = 20007,
    
    //图片加载失败
    AdSdkSlotImgLoadFail            = 20008,
}AdSdkSlotErrorCode;

typedef enum {
    //竖屏
    AdsSdkIOIsPortrait  =1,
    //横屏
    AdsSdkIOIsLandscape =2
}AdsSdkInterfaceOrientation;

//sdk 版本号
#define AdsSdkVersion @"2.0"

//初始化失败后，重新初始化时间间隔
#define AdsSdkInitFaieldRefreshInterval 30

//广告返回间隔，秒
#define AdSdkRequestAdTimeOut 3

//sdk初始化地址
//#define AdsSdkInitAddress @"http://api.sspprod.ad-mex.com/sdk"
#define AdsSdkInitAddress @"http://api.sspprod.ad-mex.com/sdk"

//sdk广告请求地址
//#define AdsSdkAdRequestAddress @"https://adpssp.ad-mex.com/adReqSdk"
#define AdsSdkAdRequestAddress @"http://adpssp.ad-mex.com/adReqSdk"

#endif /* AdSdkCommConstants_h */
