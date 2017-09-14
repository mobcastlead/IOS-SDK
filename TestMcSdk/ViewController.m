//
//  ViewController.m
//  TestMcSdk
//
//  Created by 冉文龙 on 2017/9/14.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import "ViewController.h"

#import <AdSdk/AdSdk.h>
#import <AdSdk/AdSdkSplash.h>
#import <AdSdk/AdSdkSplashDelegate.h>

#import <AdSdk/AdSdkBanner.h>
#import <AdSdk/AdsSdkBannerDelegate.h>

#import <AdSdk/AdSdkInterstital.h>
#import <AdSdk/AdSdkInterstitalDelegate.h>

//横幅广告位测试ID
#ifndef ADSDK_BANNER_ID
#define ADSDK_BANNER_ID     @"598d49b81ad88e0100043101"
#endif

//插屏广告位测试ID
#ifndef ADSDK_INTERSTITAL_ID
#define ADSDK_INTERSTITAL_ID     @"59b0bd3ec8777601005e599c"
#endif

//开屏广告位测试ID
#ifndef ADSDK_SPLASH_ID
#define ADSDK_SPLASH_ID     @"59b0bdc7c8777601005e59b4"
#endif

static BOOL AdSDKBannerInitFlag = NO;

@interface ViewController () <AdSdkBannerDelegate, AdSdkInterstitalDelegate, AdSdkSplashDelegate>
@property (nonatomic, strong) AdSdkSplash *splash;
@property (nonatomic, strong) AdSdkBanner *banner;
@property (nonatomic, strong) AdSdkInterstital *interstital;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.splash = [AdSdk splashInitAndRequestAd:CGRectMake(0,0,self.view.bounds.size.width,self.view.bounds.size.height) adposid:ADSDK_SPLASH_ID delegate: self];
    
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) initBannerAndInterstitalButton{
    //进入软件  初始化横幅插屏
    UINavigationBar *navBar = [[UINavigationBar alloc]initWithFrame:CGRectMake(0, 20, self.view.bounds.size.width, 40)];
    UINavigationItem *navItem = [[UINavigationItem alloc]initWithTitle:@"Demo"];
    [navBar pushNavigationItem:navItem animated:YES];
    [self.view addSubview:navBar];
    
    UIButton *btnBanner = [UIButton buttonWithType:UIButtonTypeCustom];
    btnBanner.frame = CGRectMake(5, 65, 90, 40);
    btnBanner.backgroundColor = [UIColor blueColor];
    [btnBanner setTitle:@"横幅" forState:UIControlStateNormal];
    [btnBanner addTarget:self action:@selector(bannerAdShow) forControlEvents: UIControlEventTouchUpInside];
    [self.view addSubview:btnBanner];
    
    UIButton *btnInter = [UIButton buttonWithType:UIButtonTypeCustom];
    btnInter.frame = CGRectMake(100, 65, 90, 40);
    btnInter.backgroundColor = [UIColor blueColor];
    [btnInter setTitle:@"插屏" forState:UIControlStateNormal];
    [btnInter addTarget:self action:@selector(interstitalAdShow) forControlEvents: UIControlEventTouchUpInside];
    [self.view addSubview:btnInter];
    
    self.banner = [AdSdk initWithFrame:CGRectMake(0, self.view.bounds.size.height-120, self.view.bounds.size.width, 80) adposid:ADSDK_BANNER_ID delegate:self];
    
    self.interstital = [AdSdk interstitalInitWithFrame:CGRectMake(0,0,301,460) adposid:ADSDK_INTERSTITAL_ID delegate: self];
}

//开屏广告，初始化结果delegate
-(void)splashInitResult:(NSInteger)code{
    NSLog(@"splash initResult Code: %ld", (long)code);
    if (code == (NSInteger)AdSdkSlotInitSuccess) {
        
        [self initBannerAndInterstitalButton];
        
        //展示开屏广告
        [self.view addSubview:self.splash];
        [self.splash load];
    }else{
        [self initBannerAndInterstitalButton];
    }
}

-(void)bannerAdShow{
    if (AdSDKBannerInitFlag) {
        NSLog(@"横幅广告位展示");
        [self.view addSubview:self.banner];
        [self.banner load];
    }
}

-(void)bannerInitResult:(NSInteger)code{
    NSLog(@"banner initResult Code: %ld", (long)code);
    if (code == (NSInteger)AdSdkSlotInitSuccess) {
        AdSDKBannerInitFlag = true;
    }
}

-(void)interstitalAdShow{
    NSLog(@"插屏广告位展示");
    [self.interstital load];
}


-(void)bannerDidLoading{
    NSLog(@"banner will loading");
}

-(void)bannerDidLoadingFinish{
    NSLog(@"banner loading finished");
}

-(void)bannerDidLoadingError:(NSInteger)errorCode{
    NSLog(@"banner loading error errorCode: %ld", (long)errorCode);
}

-(void)bannerReportViewOKay{
    NSLog(@"banner views okay");
}

-(void)bannerLandingPageLoadOkay{
    NSLog(@"落地页跳转完成");
}

-(void)bannerLandingPageLoadError{
    NSLog(@"落地页跳转失败");
}

@end
