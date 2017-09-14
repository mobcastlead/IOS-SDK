//
//  AdsSdkBannerDelegate.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/4/20.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>
//#import "AdSdkCommConstants.h"

@protocol AdSdkBannerDelegate <NSObject>

//banner初始化结果
-(void)bannerInitResult:(NSInteger)code;

//banner开始加载
-(void)bannerDidLoading;

//banner开始加载完成
-(void)bannerDidLoadingFinish;

//banner开始加载失败
-(void)bannerDidLoadingError:(NSInteger)errorCode;

//banner曝光链接上报完成
-(void)bannerReportViewOKay;

//banner点击链接上报完成
-(void)bannerReportClickOKay;

//banner落地页跳转完成
-(void)bannerLandingPageLoadOkay;

//banner落地页跳转错误
-(void)bannerLandingPageLoadError;

//banner落地页跳转AppStore
-(void)bannerAppStoreLoadOkay;

//banner关闭
-(void)bannerDidDismissScreen;

@end
