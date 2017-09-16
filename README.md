# MobcastleAd SDK 接入指南

标签： mc 

---
### 1. 简介

MobcastleAd 媒体管理平台，采买优质媒体流量，实现媒体流量变现需求，媒体接入方式分为：

- API方式
- App SDK方式
- Web站点 JavaScript SDK方式

### 2. IOS SDK 简介

采用Object-C开发，封装.framework方式提供

#### 2.1 包含组件
```
AdSdk.bundle         //SDK所需资源文件
AdSdk.framework      //SDK框架
```

#### 2.2 SDK 接入说明
##### 2.2.1 APP设置

- 于项目中 Build Phases -> Link Binary With Libraries -> add AdSdk.framework AdSdk.bundle

    - 如果编译出现image not found 可以尝试 + New Copy Files Phase 将SDK导入项目中。
    
- 于项目中 Build Phases -> Copy Bundle Resources -> add AdSdk.bundle

- 于项目中 Build Settings -> Other Linker Flags -> $(OTHER_LDFLAGS) -ObjC.
- 设置APP网络
```
    <key>NSAppTransportSecurity</key>
    <dict>
        <key>NSAllowsArbitraryLoads</key>
        <true/>
    </dict>
```

##### 2.2.1 使用指南
- SDK初始化，SDK在正式使用之前，需要pulisherId,appId,publisherToken进行初始化

```
/** 
 * token: MobcastleAd 提供，测试使用：f1c4d8adbaaa81143bd0055779447513
 * publisherid: MobcastleAd 提供，测试使用：598d45d21ad88e0100042f5f
 * appid: MobcastleAd 提供，测试使用：598d465c1ad88e0100042f6f
 * failTryCount: 若初始化有失败，尝试次数
 * delegate: Delegate代理
 */
+(void)initWithAdSdkToken: (NSString *)token
            publisherid: (NSString *)publisherid
                    appid: (NSString *)appid
             failTryCount: (NSInteger)failTryCount
                 delegate: (id<AdSdkDelegate>)delegate;
                 
                 
eg:
//初始化
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [AdSdk initWithAdSdkToken:MEXSDK_PUBLISHER_TOKEN publisherid:MEXSDK_PUBLISHER_ID appid:MEXSDK_APP_ID failTryCount:2 delegate: self];
    
    return YES;
}
//SDK delegate
-(void)AdSdkInitResult:(AdSdkInitErrorCode)errorCode initCount:(NSInteger)initCount{
    NSLog(@"AdSdk init result: code=%d, initCount=%ld", errorCode, (long)initCount);
}
```

- 请求开屏广告
APP启动时候，可以请求插屏广告
参照demo了解

- 请求插屏广告
参照demo了解

- 请求横幅广告
参照demo了解

##### 2.2.2 注意事项
- 广告请求后会在3s内返回，若3s未返回广告，则该次广告请求将不会展示广告。

### 3. Web站点  JavaScript SDK 简介
原生javascript，初始化js对象
获取广告，并进行曝光，点击跳转落地页

#### 3.1 接入流程
- 于MC流量平台注册广告位
- MC平台提供广告位的JS代码，放置您的网站中。

#### 3.2 示例
- js代码样式
```
/**
 *  <div id="MDRS" style="width: 640px; height: 100px; position: relative;" >
 *  id="MDRS" 固定值；
 *
 *  position: relative; style样式中的固定值；
 *
 *  width: 640px; height: 100px; 用户自定义的广告区域（横幅比例，如6:1/3:1之类等）；
 *
 * <script type='text/javascript' src="http://ng.mobcastlead.com/mrc.js"></script> 加载js对象；
 *
 * <script> mobcastlead("b61a48df20e7a6102ff05dbca11aeae7")</script>请求广告，"b61a48df20e7a6102ff05dbca11aeae7"由MC流量平台提供；
 */
<div id="MDRS" style="width: 640px; height: 100px; position: relative;" >
    <script type='text/javascript' src="http://ng.mobcastlead.com/mrc.js"></script>
    <script> mobcastlead("b61a48df20e7a6102ff05dbca11aeae7")</script>
</div>
```

