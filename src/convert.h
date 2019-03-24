#include <napi.h>
#include "jvt.h"

#ifdef __APPLE__//Not support but developing ineed
    using namespace SDK_JVTFACE;
#endif
#ifdef __linux__
    using namespace SDK_JVTFACE;
#endif

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
CONVERT_RETURN
RE_CONVERT_FUNCTION(DSTPoint)
    obj->iYear = res.Get("iYear").As<Napi::Number>();
    obj->iMonth = res.Get("iMonth").As<Napi::Number>(); 
    obj->iWeek = res.Get("iWeek").As<Napi::Number>();
    obj->iWeekDay = res.Get("iWeekDay").As<Napi::Number>();
RE_CONVERT_RETURN

CONVERT_FUNCTION(SDK_CONFIG_NORMAL)	
    obj.Set("sysTime",convert(env,res.sysTime));   //系统时间
    obj.Set("iLocalNo",res.iLocalNo);    ///< 本机编号:[0, 998] */
    obj.Set("iOverWrite",res.iOverWrite);    ///< 硬盘满时处理 "OverWrite（iOverWrite=1）", "StopRecord（iOverWrite=0）" */		
    obj.Set("cIranCalendarEnable",res.cIranCalendarEnable);    ///< 是否启用伊朗日历，1表示启用，0表示不启用
    obj.Set("cFontSize",res.cFontSize);    ///< 矢量字体大小
    obj.Set("reserved",res.reserved);
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
    
    COPY_STRING_VALUE(cIranCalendarEnable)
    COPY_STRING_VALUE(cFontSize)
    COPY_STRING_VALUE(reserved)
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
    obj.Set("leastTime",res.mostTime);  //自动曝光时间上限，单位微秒
CONVERT_RETURN
RE_CONVERT_FUNCTION(SDK_ExposureCfg)
    obj->level = res.Get("level").As<Napi::Number>();
    obj->leastTime = res.Get("leastTime").As<Napi::Number>();
    obj->mostTime = res.Get("mostTime").As<Napi::Number>();
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
    obj.Set("Night_nfLevel",res.Night_nfLevel);    //
    obj.Set("Ircut_swap",res.Ircut_swap);               //ircut 正常序= 0        反序= 1
    obj.Set("high_light",res.high_light);               //强光抑制功能 0~255,默认是16
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
    obj->high_light = res.Get("high_light").As<Napi::Number>();
RE_CONVERT_RETURN



CONVERT_FUNCTION(SDK_CameraAbility)
    obj.Set("count",res.count);     		//支持曝光速度数量

    // Napi::Array speeds = Napi::Array::New(env,sizeof(res.speeds));
    // for(int i = 0;i < sizeof(res.speeds);++i){
    //     speeds.Set(i,res.speeds[i]);
    // }
    obj.Set("speeds",res.speeds);               //曝光速度

    obj.Set("status",res.status);           //工作状态  >= 0 正常    < 0 异常
    obj.Set("elecLevel",res.elecLevel);     //参考电平值
    obj.Set("luminance",res.luminance);     //平均亮度
    obj.Set("pVersion",res.pVersion);       //xm 2a版本
	obj.Set("isFishLens",res.isFishLens);   //是否是鱼眼镜头，如果是，则需要app和PC端做图像校正
	obj.Set("resv1",res.resv1);             //保留，如果增加char型的成员先用这里的
	obj.Set("reserve",res.reserve);         //保留，如果增加int型的成员用这里
CONVERT_RETURN