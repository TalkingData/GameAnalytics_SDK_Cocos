# TalkingData Game Analytics Cocos SDK

`Game Analytics Cocos2dx` 平台 SDK 由`封装层`和 `Native SDK` 两部分构成，目前`GitHub`上提供了封装层代码，需要从 [TalkingData官网](https://www.talkingdata.com/spa/sdk/#/config) 官网 下载最新版的 `Android` 和 `iOS` 平台 `Native SDK`，组合使用。
 
### <a name="Explain"></a>集成说明 
1. 下载本项目（封装层）到本地；

2. 访问 TalkingData官网 下载最新版的 Android 和 iOS 平台 Game Analytics SDK（ Native SDK）
 	- 方法1：选择 Cocos2d 平台进行功能定制；
 	- 方法2：分别选择 Android 和 iOS 平台进行功能定制，请确保两个平台功能项一致；
<img src="http://i2.kiimg.com/601478/1189fd832c8e3bfd.jpg" width="600px" />

3. 将下载的最新版  `Native SDK` 引入到您的工程中。
	- Android 平台
	将最新的`.jar`文件复制到 `／libs` 目录下
	- iOS
	将最新的`.a`文件复制到 `xcode`项目的`iOS` 目录下
	
4. 按 `Native SDK` 功能选项对封装层代码进行必要的删减，详见“注意事项”第2条；

5. 将 `Cococs SDK `集成您需要统计的工程中，并按 集成文档 进行必要配置和功能调用。

### <a name="Notes"></a>注意事项
1. 分别选择 Android 和 iOS 平台进行功能定制时，请确保两个平台功能项一致。
2. 如果申请 Native SDK 时只选择了部分功能，则需要在本项目中删除未选择功能对应的封装层代码。  
a) 未选择`自定义事件`功能则删除以下3部分
##### android 
	删除 `TalkingDataGameAnalytics/android/TDCCTalkingDataGA.cpp` 文件中如下代码： 
```
	void TDCCTalkingDataGA::onEvent(const char* eventId, EventParamMap* map) {  
	 if (NULL == eventId || strlen(eventId) == 0) {  
	        return;  
	 }
		 TDGAJniMethodInfo t;
		 if (TDGAJniHelper::getStaticMethodInfo(t
		    	, gClass_TalkingDtatGA  
		    	, "onEvent"  
		    	, "(Ljava/lang/String;Ljava/util/Map;)V")) {
		    jobject jparamMap = createJavaMapObject(t.env, map);  
		    jstring jeventId = t.env->NewStringUTF(eventId);  
			t.env->CallStaticVoidMethod(gClass_TalkingDtatGA, t.methodID, jeventId, jparamMap);  
			t.env->DeleteLocalRef(jeventId);  
			t.env->DeleteLocalRef(jparamMap);  
		}
	}
```
##### iOS

```
删除 `TalkingDataGameAnalytics/ios/TDCCTalkingDataGA.mm` 文件中如下代码：

	void TDCCTalkingDataGA::onEvent(const char* eventId, EventParamMap* map) {
    if (NULL == eventId || strlen(eventId) == 0) {
        return;
    }
    
    NSString* pId = [NSString stringWithUTF8String:eventId];
    if (NULL == map) {
        [TalkingDataGA onEvent:pId eventData:NULL];
    } else {
        NSMutableDictionary* dict = [NSMutableDictionary dictionary];
        EventParamMap::iterator it;
        for (it = map->begin(); it != map->end(); it++) {
            std::string key = it->first;
            std::string value = it->second;
            NSString* pKey = [NSString stringWithUTF8String:key.c_str()];
            NSString* pValue = [NSString stringWithUTF8String:value.c_str()];
            [dict setObject:pValue forKey:pKey];
        }
        [TalkingDataGA onEvent:pId eventData:dict];
    }
}
```

```
+ (void)onEvent:(NSString *)eventId eventData:(NSDictionary *)eventData;
```
##### include
```
删除 `TalkingDataGameAnalytics/include/TDCCTalkingDataGA.h` 文件中如下代码： 
static void onEvent(const char* eventId, EventParamMap* map = NULL);
```
