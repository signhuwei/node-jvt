#include <napi.h>
#include "jvt.h"
#include <VideoNetAPI.h>

#ifdef __APPLE__//Not support but developing ineed
    using namespace SDK_JVTFACE;
#endif
#ifdef __linux__
    using namespace SDK_JVTFACE;
#endif

template<typename T> class ConfigGenner{
    public:
        static const int size = sizeof(T);
        static T New(){
            T cfg;
            memset(&cfg,0,size);
            return cfg;
        }
};

template<SDK_CONFIG_TYPE Q = E_SDK_CONFIG_SYSNORMAL> class ConfigTrait{
    public: 
        typedef SDK_CONFIG_NORMAL TYPE;
        typedef ConfigGenner<TYPE> GEN;
};
#define _CONFIG_TRAIT_(E,T) \
    template<> class ConfigTrait<E>{ \
        public: \
            typedef T TYPE; \
            typedef ConfigGenner<TYPE> GEN; \
    };

_CONFIG_TRAIT_(E_SDK_CONFIG_CAMERA,SDK_CameraParam)
_CONFIG_TRAIT_(E_SDK_CONFIG_ABILITY_CAMERA,SDK_CameraAbility)
_CONFIG_TRAIT_(E_SDK_CFG_PARAM_EX,SDK_CameraParamEx)
_CONFIG_TRAIT_(E_SDK_CFG_VIDEOCOLOR_CUSTOM,SDK_VIDEOCOLOR_PARAM_CUSTOM)
//_CONFIG_TRAIT_(E_SDK_VIDEOCOLOR,SDK_VideoColorConfigAll)
 

#define CONVERT_FUNCTION(type) \
    Napi::Value convert(Napi::Env env,type res){ \
        Napi::Object obj = Napi::Object::New(env);

#define CONVERT_RETURN \
        return obj; \
    }

#define RE_CONVERT_FUNCTION(type) \
    void convert(Napi::Object res,type* obj){ 
#define RE_CONVERT_RETURN \
        return; \
    }

#define COPY_STRING_VALUE(key) \
    static_cast<std::string>(res.Get(#key).As<Napi::String>()).copy((char*)obj->key,sizeof(obj->key),0);
#define COPY_OBJECT_VALUE(key) \
    convert(res.Get(#key).As<Napi::Object>(),&(obj->key));


CONVERT_FUNCTION(SDK_SYSTEM_TIME)
    obj.Set("year",res.year);       	///< 年。   
    obj.Set("month",res.month);	        ///< 月，January = 1, February = 2, and so on.   
    obj.Set("day",res.day);	            ///< 日。   
    obj.Set("hour",res.hour);	        ///< 星期，Sunday = 0, Monday = 1, and so on   
    obj.Set("minute",res.minute);	    ///< 时。   
    obj.Set("second",res.second);	    ///< 分。   
    obj.Set("wday",res.wday);	        ///< 秒。   
    obj.Set("isdst",res.isdst);	        ///< 夏令时标识。   
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_SYSTEM_TIME)
    obj->year = res.Get("year").As<Napi::Number>();
    obj->month = res.Get("month").As<Napi::Number>();
    obj->day = res.Get("day").As<Napi::Number>();
    obj->hour = res.Get("hour").As<Napi::Number>();
    obj->minute = res.Get("minute").As<Napi::Number>();
    obj->second = res.Get("second").As<Napi::Number>();
    obj->wday = res.Get("wday").As<Napi::Number>();
    obj->isdst = res.Get("isdst").As<Napi::Number>();
RE_CONVERT_RETURN

CONVERT_FUNCTION(DSTPoint)
    obj.Set("iYear",res.iYear); 
    obj.Set("iMonth",res.iMonth);	        ///<周1:first  to2 3 4 -1:last one   0:表示使用按日计算的方法[-1,4]  
    obj.Set("iWeek",res.iWeek);	            ///<weekday from sunday=0	[0, 6]
    obj.Set("iWeekDay",res.iWeekDay); 
    obj.Set("Hour",res.Hour); 
    obj.Set("Minute",res.Minute); 
CONVERT_RETURN
RE_CONVERT_FUNCTION(DSTPoint)
    obj->iYear = res.Get("iYear").As<Napi::Number>();
    obj->iMonth = res.Get("iMonth").As<Napi::Number>(); 
    obj->iWeek = res.Get("iWeek").As<Napi::Number>();
    obj->iWeekDay = res.Get("iWeekDay").As<Napi::Number>();
    obj->Hour = res.Get("Hour").As<Napi::Number>();
    obj->Minute = res.Get("Minute").As<Napi::Number>();
RE_CONVERT_RETURN

CONVERT_FUNCTION(SDK_CONFIG_NORMAL)	
    obj.Set("sysTime",convert(env,res.sysTime));   //系统时间
    obj.Set("iLocalNo",res.iLocalNo);    ///< 本机编号:[0, 998] */
    obj.Set("iOverWrite",res.iOverWrite);    ///< 硬盘满时处理 "OverWrite（iOverWrite=1）", "StopRecord（iOverWrite=0）" */		
    #ifdef _WIN32
    obj.Set("iSnapInterval",res.iSnapInterval);			///< 定时抓图的时间间隔，以秒为单位 

    #elif __linux__
    obj.Set("cIranCalendarEnable",res.cIranCalendarEnable);    ///< 是否启用伊朗日历，1表示启用，0表示不启用
    obj.Set("cFontSize",res.cFontSize);    ///< 矢量字体大小
    obj.Set("reserved",res.reserved);
    #endif
    obj.Set("sMachineName",res.sMachineName);    ///< 机器名
    obj.Set("iVideoStartOutPut",res.iVideoStartOutPut);    ///< 输出模式 */
    obj.Set("iAutoLogout",res.iAutoLogout);    ///< 本地菜单自动注销(分钟)	[0, 120]
    obj.Set("iVideoFormat",res.iVideoFormat);    ///< 视频制式:“PAL”:0, “NTSC”:1, “SECAM” */
    obj.Set("iLanguage",res.iLanguage);    ///< 语言选择:“English”, “SimpChinese”, “TradChinese”, “Italian”, “Spanish”, “Japanese”, “Russian”, “French”, “German” */
    obj.Set("iDateFormat",res.iDateFormat);    ///< 日期格式:“YYMMDD”, “MMDDYY”, “DDMMYY” */
    obj.Set("iDateSeparator",res.iDateSeparator);    ///< 日期分割符:“.”, “-”, “/” */
    obj.Set("iTimeFormat",res.iTimeFormat);    ///< 时间格式:“12”, “24” */
    obj.Set("iDSTRule",res.iDSTRule);    ///< 夏令时规则 
    obj.Set("iWorkDay",res.iWorkDay);    ///< 工作日
    obj.Set("dDSTStart",convert(env,res.dDSTStart));    
    obj.Set("dDSTEnd",convert(env,res.dDSTEnd));
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_CONFIG_NORMAL)	
    COPY_OBJECT_VALUE(sysTime)
    
    obj->iLocalNo = res.Get("iLocalNo").As<Napi::Number>();
    obj->iOverWrite = res.Get("iOverWrite").As<Napi::Number>();
    #ifdef _WIN32
    obj->iSnapInterval = res.Get("iSnapInterval").As<Napi::Number>();
    #elif __linux__
    COPY_STRING_VALUE(cIranCalendarEnable)
    COPY_STRING_VALUE(cFontSize)
    COPY_STRING_VALUE(reserved)
    #endif
    COPY_STRING_VALUE(sMachineName)
    
    obj->iVideoStartOutPut = res.Get("iVideoStartOutPut").As<Napi::Number>();
    obj->iAutoLogout = res.Get("iAutoLogout").As<Napi::Number>();
    obj->iVideoFormat = res.Get("iVideoFormat").As<Napi::Number>();
    obj->iLanguage = res.Get("iLanguage").As<Napi::Number>();
    obj->iDateFormat = res.Get("iDateFormat").As<Napi::Number>();
    obj->iDateSeparator = res.Get("iDateSeparator").As<Napi::Number>();
    obj->iTimeFormat = res.Get("iTimeFormat").As<Napi::Number>();
    obj->iDSTRule = res.Get("iDSTRule").As<Napi::Number>();
    obj->iWorkDay = res.Get("iWorkDay").As<Napi::Number>();

    COPY_OBJECT_VALUE(dDSTStart)
    COPY_OBJECT_VALUE(dDSTEnd)
RE_CONVERT_RETURN



CONVERT_FUNCTION(SDK_ExposureCfg)
    obj.Set("level",res.level);  //曝光等级
    obj.Set("leastTime",res.leastTime);  //自动曝光时间下限或手动曝光时间，单位微秒
    obj.Set("mostTime",res.mostTime);  //自动曝光时间上限，单位微秒
    #ifdef _WIN32
    obj.Set("levelTime",res.levelTime); //曝光时间 单位微妙
    #endif
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_ExposureCfg)
    obj->level = res.Get("level").As<Napi::Number>();
    obj->leastTime = res.Get("leastTime").As<Napi::Number>();
    obj->mostTime = res.Get("mostTime").As<Napi::Number>();
    #ifdef _WIN32
    obj->levelTime = res.Get("levelTime").As<Napi::Number>();
    #endif
RE_CONVERT_RETURN

CONVERT_FUNCTION(SDK_GainCfg)
    obj.Set("gain",res.gain);//自动增益上限(自动增益启用)或固定增益值
    obj.Set("autoGain",res.autoGain);//自动增益是否启用，0:不开启  1:开启
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_GainCfg)
    obj->gain = res.Get("gain").As<Napi::Number>();
    obj->autoGain = res.Get("autoGain").As<Napi::Number>();
RE_CONVERT_RETURN

CONVERT_FUNCTION(SDK_CameraParam)
    obj.Set("whiteBalance",res.whiteBalance);           //白平衡
    obj.Set("dayNightColor",res.dayNightColor);         //日夜模式，取值有彩色、自动切换和黑白
    obj.Set("elecLevel",res.elecLevel);                 //参考电平值
    obj.Set("apertureMode",res.apertureMode);           //自动光圈模式
    obj.Set("BLCMode",res.BLCMode);                     //背光补偿模式
    obj.Set("exposureConfig",convert(env,res.exposureConfig));      //曝光配置
    obj.Set("gainConfig",convert(env,res.gainConfig));              //增益配置
    obj.Set("PictureFlip",res.PictureFlip);             //图片上下翻转
    obj.Set("PictureMirror",res.PictureMirror);         //图片左右翻转(镜像)
    obj.Set("RejectFlicker",res.RejectFlicker);         //日光灯防闪功能
    obj.Set("EsShutter",res.EsShutter);                 //电子慢快门功能
    obj.Set("ircut_mode",res.ircut_mode);               //IR-CUT切换 0 = 红外灯同步切换 1 = 自动切换
    obj.Set("dnc_thr",res.dnc_thr);                     //日夜转换阈值
    obj.Set("ae_sensitivity",res.ae_sensitivity);       //ae灵敏度配置
    obj.Set("Day_nfLevel",res.Day_nfLevel);             //noise filter 等级，0-5,0不滤波，1-5 值越大滤波效果越明显
    obj.Set("Night_nfLevel",res.Night_nfLevel);
    obj.Set("Ircut_swap",res.Ircut_swap);               //ircut 正常序= 0        反序= 1
    #ifdef _WIN32
    obj.Set("BLCValue",res.BLCValue);                   //背光补偿值
    #endif
    #ifdef __linux__
    obj.Set("high_light",res.high_light);               //强光抑制功能 0~255,默认是16
    #endif
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_CameraParam)
    obj->whiteBalance = res.Get("whiteBalance").As<Napi::Number>();
    obj->dayNightColor = res.Get("dayNightColor").As<Napi::Number>();
    obj->elecLevel = res.Get("elecLevel").As<Napi::Number>();
    obj->apertureMode = res.Get("apertureMode").As<Napi::Number>();
    obj->BLCMode = res.Get("BLCMode").As<Napi::Number>();

    COPY_OBJECT_VALUE(exposureConfig)
    COPY_OBJECT_VALUE(gainConfig)

    obj->PictureFlip = res.Get("PictureFlip").As<Napi::Number>();
    obj->PictureMirror = res.Get("PictureMirror").As<Napi::Number>();
    obj->RejectFlicker = res.Get("RejectFlicker").As<Napi::Number>();
    obj->EsShutter = res.Get("EsShutter").As<Napi::Number>();
    obj->ircut_mode = res.Get("ircut_mode").As<Napi::Number>();
    obj->dnc_thr = res.Get("dnc_thr").As<Napi::Number>();
    obj->ae_sensitivity = res.Get("ae_sensitivity").As<Napi::Number>();
    obj->Day_nfLevel = res.Get("Day_nfLevel").As<Napi::Number>();
    obj->Night_nfLevel = res.Get("Night_nfLevel").As<Napi::Number>();
    obj->Ircut_swap = res.Get("Ircut_swap").As<Napi::Number>();
    #ifdef _WIN32
    obj->BLCValue = res.Get("BLCValue").As<Napi::Number>();
    #endif
    #ifdef __linux__
    obj->high_light = res.Get("high_light").As<Napi::Number>();
    #endif
RE_CONVERT_RETURN



CONVERT_FUNCTION(SDK_CameraAbility)
    obj.Set("count",res.count);     		//支持曝光速度数量

    Napi::Array speeds = Napi::Array::New(env,res.count);
    for(int i = 0;i < res.count;++i){
        speeds.Set(i,res.speeds[i]);
    }
    obj.Set("speeds",speeds);               //曝光速度

    obj.Set("status",res.status);           //工作状态  >= 0 正常    < 0 异常
    obj.Set("elecLevel",res.elecLevel);     //参考电平值
    obj.Set("luminance",res.luminance);     //平均亮度
    obj.Set("pVersion",res.pVersion);       //xm 2a版本
    #ifdef __linux__
	obj.Set("isFishLens",res.isFishLens);   //是否是鱼眼镜头，如果是，则需要app和PC端做图像校正
	obj.Set("resv1",res.resv1);             //保留，如果增加char型的成员先用这里的
    #endif
	obj.Set("reserve",res.reserve);         //保留，如果增加int型的成员用这里
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_CameraAbility)
    obj->count = res.Get("count").As<Napi::Number>();
    Napi::Array speeds = res.Get("speeds").As<Napi::Array>();
    for(int i = 0;i < obj->count;++i){
        obj->speeds[i] = speeds.Get(i).As<Napi::Number>();
    }
    obj->status = res.Get("status").As<Napi::Number>();
    obj->elecLevel = res.Get("elecLevel").As<Napi::Number>();
    obj->luminance = res.Get("luminance").As<Napi::Number>();

    COPY_STRING_VALUE(pVersion)
    #ifdef __linux__
    COPY_STRING_VALUE(isFishLens)
    COPY_STRING_VALUE(resv1)
    #endif
    COPY_STRING_VALUE(reserve)
RE_CONVERT_RETURN



CONVERT_FUNCTION(SDK_CameraParamEx)
    obj.Set("broadTrends",convert(env,res.broadTrends));       //宽动态  
    #ifdef __linux__                   
    obj.Set("style",res.style);                                //enum SDK_IMG_TYPE            
    obj.Set("exposureTime",res.exposureTime);                  //实际生效的曝光时间                         
    obj.Set("Dis",res.Dis);                                    //电子防抖设置  0:关闭 1:开启**/        
    obj.Set("Ldc",res.Ldc);                                    //镜头畸变校正  0:关闭 1:开启**/        
    obj.Set("AeMeansure",res.AeMeansure);                      //测光模式校正  0:平均测光 1:中央测光**/                     
    obj.Set("LowLuxMode",res.LowLuxMode);                      //微光模式 mode：0 关闭 1开启 ==only imx291                     
    obj.Set("corridor_mode",res.corridor_mode);                //1:走廊模式  0:普通模式                         
    obj.Set("lightRestrainLevel",res.lightRestrainLevel);      // 强光抑制功能0~255，默认16 
    #endif
    int nCount = sizeof(res.res)/sizeof(res.res[0]);
    Napi::Array ress = Napi::Array::New(env,nCount);
    for(int i = 0;i < nCount;++i){
        ress.Set(i,res.res[i]);
    }                             
    obj.Set("res",ress);                                    //冗余           
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_CameraParamEx)
    COPY_OBJECT_VALUE(broadTrends)
    #ifdef __linux__
    obj->style = res.Get("style").As<Napi::Number>();
    obj->exposureTime = res.Get("exposureTime").As<Napi::Number>();
    obj->Dis = res.Get("Dis").As<Napi::Number>();
    obj->Ldc = res.Get("Ldc").As<Napi::Number>();
    obj->AeMeansure = res.Get("AeMeansure").As<Napi::Number>();
    obj->LowLuxMode = res.Get("LowLuxMode").As<Napi::Number>();
    obj->corridor_mode = res.Get("corridor_mode").As<Napi::Number>();
    obj->lightRestrainLevel = res.Get("lightRestrainLevel").As<Napi::Number>();
    #endif
    Napi::Array ress = res.Get("res").As<Napi::Array>();
    for(int i = 0;i < ress.Length();++i){
        obj->res[i] = ress.Get(i).As<Napi::Number>();
    }
RE_CONVERT_RETURN

CONVERT_FUNCTION(SDK_VIDEOCOLOR_PARAM_EX)
    obj.Set("BrightnessRef",res.BrightnessRef);///< 亮度ref1，取值0-100。
    obj.Set("ContrastRef",res.ContrastRef);///< 对比度ref1，取值0-100。
    obj.Set("ContrastThRef",res.ContrastThRef);///< 对比度阀值ref1，取值0-100。
    obj.Set("ContrastSlopeRef",res.ContrastSlopeRef);///< 对比度斜率ref1，取值0-100。
    obj.Set("DarkBlfRef",res.DarkBlfRef);//
    obj.Set("DarkNfRef",res.DarkNfRef);//
    obj.Set("DarkEcPthRef",res.DarkEcPthRef);//
    obj.Set("DarkEcMthRef",res.DarkEcMthRef);//
    obj.Set("DarkDcRef",res.DarkDcRef);//
    obj.Set("CbGain",res.CbGain);///high low middle
    obj.Set("CrGain",res.CrGain);///higg low middle
    obj.Set("reserved",res.reserved);///保留
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_VIDEOCOLOR_PARAM_EX)
    obj->BrightnessRef = res.Get("BrightnessRef").As<Napi::Number>();
    obj->ContrastRef = res.Get("ContrastRef").As<Napi::Number>();
    obj->ContrastThRef = res.Get("ContrastThRef").As<Napi::Number>();
    obj->ContrastSlopeRef = res.Get("ContrastSlopeRef").As<Napi::Number>();
    obj->DarkBlfRef = res.Get("DarkBlfRef").As<Napi::Number>();
    obj->DarkNfRef = res.Get("DarkNfRef").As<Napi::Number>();
    obj->DarkEcPthRef = res.Get("DarkEcPthRef").As<Napi::Number>();
    obj->DarkEcMthRef = res.Get("DarkEcMthRef").As<Napi::Number>();
    obj->DarkDcRef = res.Get("DarkDcRef").As<Napi::Number>();
    obj->CbGain = res.Get("CbGain").As<Napi::Number>();
    obj->CrGain = res.Get("CrGain").As<Napi::Number>();
    obj->reserved = res.Get("reserved").As<Napi::Number>();
RE_CONVERT_RETURN
CONVERT_FUNCTION(SDK_VIDEOCOLOR_PARAM_CUSTOM)
    int nCount = sizeof(res.VideoColor)/sizeof(res.VideoColor[0]);
    Napi::Array VideoColor = Napi::Array::New(env,nCount);
    for(int i = 0;i < nCount;++i){
        VideoColor.Set(i,convert(env,res.VideoColor[i]));
    }
    obj.Set("VideoColor",VideoColor);
    obj.Set("Saturation",res.Saturation);       ///< 饱和度，取值0-100。
    obj.Set("Gain",res.Gain);                   ///< 增益，取值0-100。bit7置位表示自动增益，其他位被忽
    obj.Set("Acutance",res.Acutance);           ///< 锐度，取值0-100
    obj.Set("AeWight",res.AeWight);             ///背光补偿
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_VIDEOCOLOR_PARAM_CUSTOM)
    Napi::Array VideoColor = res.Get("VideoColor").As<Napi::Array>();
    for(int i = 0;i < VideoColor.Length();++i){
        convert(VideoColor.Get(i).As<Napi::Object>(),&(obj->VideoColor[i]));
    }
    obj->Saturation = res.Get("Saturation").As<Napi::Number>();
    obj->Gain = res.Get("Gain").As<Napi::Number>();
    obj->Acutance = res.Get("Acutance").As<Napi::Number>();
    obj->AeWight = res.Get("AeWight").As<Napi::Number>();
RE_CONVERT_RETURN
