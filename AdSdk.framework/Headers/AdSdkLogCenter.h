//
//  AdSdkLogCenter.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/4/21.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AdSdkCommConstants.h"

#ifndef RLog
#define RLog(lv, fmt, ...) \
if([[AdSdkLogCenter shareInstance] canLog: lv]){\
    NSLog((@"AdSdk-" "<FUNCTION:%s>: " fmt),__FUNCTION__, ##__VA_ARGS__);\
}
#endif

#ifndef    weakify
#if __has_feature(objc_arc)

#define weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
autoreleasepool{} __weak __typeof__(x) __weak_##x##__ = x; \
_Pragma("clang diagnostic pop")

#else

#define weakify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
autoreleasepool{} __block __typeof__(x) __block_##x##__ = x; \
_Pragma("clang diagnostic pop")

#endif
#endif

#ifndef    strongify
#if __has_feature(objc_arc)

#define strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
try{} @finally{} __typeof__(x) x = __weak_##x##__; \
_Pragma("clang diagnostic pop")

#else

#define strongify( x ) \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wshadow\"") \
try{} @finally{} __typeof__(x) x = __block_##x##__; \
_Pragma("clang diagnostic pop")

#endif
#endif

typedef enum {
    AdSDKLogLevelNone   = 4,
    AdSDKLogLevelError  = 2,
    AdSDKLogLevelDebug  = 1
}AdSDKLogLevel;

typedef enum {
    LD      = 1,
    LE      = 2,
    LN      = 4
}LogLevelName;


@interface AdSdkLogCenter : NSObject

+(AdSdkLogCenter *)shareInstance;
-(BOOL)canLog:(int)levelFlag;
-(void)setLogLevelFlag: (AdSDKLogLevel)levelFlag;
-(AdSDKLogLevel)getLogLevelFlag;
@end
