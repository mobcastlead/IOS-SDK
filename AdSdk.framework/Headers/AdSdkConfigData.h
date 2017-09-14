//
//  AdSdkConfigData.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/4/22.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AdSdkConfigData : NSObject

@property (assign, nonatomic) NSInteger is_okay;
@property (strong, nonatomic) NSArray * slots;
@property (strong, nonatomic) NSString * publisherid;
@property (strong, nonatomic) NSString * appid;
@property (strong, nonatomic) NSString * token;

+(AdSdkConfigData *)shareConfData;

-(void)getConfigerDataWithDictionary:(NSDictionary*)dict;
-(void)setBaseConfig:(NSString *)_publisherid _appid:(NSString*)_appid _token:(NSString *)_token;

@end
