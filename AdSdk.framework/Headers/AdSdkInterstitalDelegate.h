//
//  AdSdkInterstitalDelegate.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/5/8.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AdSdkInterstitalDelegate <NSObject>

//interstital初始化结果
-(void)interstitalInitResult:(NSInteger)code;

//interstital开始加载
-(void)interstitalDidLoading;

//interstital开始加载完成
-(void)interstitalDidLoadingFinish;

//interstital开始加载失败
-(void)interstitalDidLoadingError:(NSInteger)errorCode;

//interstital曝光链接上报完成
-(void)interstitalReportViewOKay;

//interstital点击链接上报完成
-(void)interstitalReportClickOKay;

//interstital落地页跳转完成
-(void)interstitalLandingPageLoadOkay;

//interstital落地页跳转错误
-(void)interstitalLandingPageLoadError;

//interstital落地页跳转AppStore
-(void)interstitalAppStoreLoadOkay;

//interstital关闭
-(void)interstitalDidDismissScreen;


@end
