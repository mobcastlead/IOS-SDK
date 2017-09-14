//
//  AdSdkDeviceInfo.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/4/21.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    AdSdkDeviceTypeIphone=4,
    AdSdkDeviceTypeIpad=5,
}AdSdkDeviceType;

@interface AdSdkDeviceInfo : NSObject

+(AdSdkDeviceInfo *)shareDevice;

-(NSString *)getPreferredLanguage;

-(NSString *)getNetworkType;

-(NSString *)getNetworkTypeNumber;

-(NSString *)getCurrentDeviceModel;

-(BOOL)checkNetworkStatus;

//-(NSString *)getCurrentTimeUnix;

-(NSString *)getIDFA;

-(NSString *)getCurrentDate;

/**
 *  提供给应用开发商的标识，但是只取bundle id的前两位。如com.apple.a   com.apple.b  两者生成的idfv是相同的
 *
 *  @return 不是唯一标识
 */
-(NSString *)getIDFV;

/**
 *  屏幕方向
 *
 *  @return 1:竖屏 0:横屏
 */
-(int)getOrientation;

/**
 *  IDFV
 *
 */
-(NSString *)getVendor;

/**
 *  OpenUDID
 *
 */
- (NSString *)getOpenUDID;

/**
 *  获取PLMN Code
 *
 *  @return PLMN Code
 */
-(NSString *)getPLMNCode;

/**
 * 获取MAC地址
 */
-(NSString *)getMacAdress;

/**
 * 获取设备类型
 */
-(NSString *)getDeviceMode;

/**
 *  获取App版本号
 *
 *  @return 版本号
 */
-(NSString*)getVersionNum;

/**
 *  获取app名称
 *
 *  @return app名称
 */
-(NSString *)getAppName;

/**
 *  获取app的bundle id
 *
 *  @return bundle id
 */
-(NSString *)getBundleID;

/**
 *  字符串是否为空
 *
 *  @param str 传入字符串
 *
 *  @return YES 为空 NO 不为空
 */
-(BOOL)isBlankString:(NSString*)str;

/**
 *  判断当前设备是iphone还是ipad
 *
 *  @return 0 手机  1 ipad
 */
-(NSString *)isPhoneOrIpad;

/**
 *  获取系统版本号
 *
 */
-(NSString *)getCurrentVersion;

/**
 *  获取包名
 *
 */
-(NSString *)getBundleName;

- (NSString *)md5:(NSString *)str;

/**
 *  获取局域网IP
 */
-(NSString *)getOutsideIp;

//获取外网IP
-(NSString *)getOutNetIp;

//获取当前语言
- (NSString *)getCurrentLanguage;

-(NSDictionary *)getAdReqDeviceParams;

/**
 *  json解析
 *
 *  @param data 解析数据
 *
 *  @return 字典
 */
+(NSDictionary*)JSONObjectWithData:(NSData*)data;

@end
