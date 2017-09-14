//
//  AdSdkHttpRequest.h
//  AdSdk
//
//  Created by 冉文龙 on 2017/4/20.
//  Copyright © 2017年 冉文龙. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AdSdkHttpRequest;
@protocol HttpRequestDelegate <NSObject>
@optional
-(void)request: (AdSdkHttpRequest *) request didReceiveResponse: (NSURLResponse *)response;
-(void)request: (AdSdkHttpRequest *) request didReceiveRawData: (NSData *)data;
-(void)request: (AdSdkHttpRequest *) request didFailWithError: (NSError *)error;
-(void)request: (AdSdkHttpRequest *) request didFinishLoadingWithResult: (id)result;
-(void)request: (AdSdkHttpRequest *) request didReceiveResCode: (NSInteger)code;
@end

typedef enum
{
    HttpRequestPostDataTypeNone,
    HttpRequestPostDataTypeNormal,			// for normal data post, such as "user=name&password=psd"
    HttpRequestPostDataTypeMultipart,        // for uploading images and files.
}HttpRequestPostDataType;

@interface AdSdkHttpRequest : NSObject <NSURLConnectionDelegate>{
    NSString            * _url;
    NSString            * _httpMethod;
    
    NSDictionary        * _params;
    
    NSDictionary        * _httpHeaderFields;
    
    NSURLConnection     * connection;
    
    NSMutableData       * resData;
}

@property (nonatomic, retain) NSString * url;
@property (nonatomic, retain) NSString * httpMethod;
@property (nonatomic, retain) NSDictionary * params;
@property (nonatomic, assign) NSInteger timeout;
@property (nonatomic, retain) NSDictionary * httpHeaderFields;
@property (nonatomic, assign) id<HttpRequestDelegate> delegate;
@property (nonatomic, assign) HttpRequestPostDataType postDataType;

+(AdSdkHttpRequest *) initWithURL: (NSString *)url
                     httpMethod: (NSString *)httpMethod
                           params: (NSDictionary *)params
                 httpHeaderFields: (NSDictionary *)httpHeaderFields
                 shortTimeoutType: (NSInteger)timeout
                     postDataType: (HttpRequestPostDataType)postDataType
                         delegate: (id<HttpRequestDelegate>)delegate;

-(void)asynchronousConnect;

-(NSData *)synchronousConnect;

- (void) disconnect;

@end
