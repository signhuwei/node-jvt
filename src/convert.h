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

CONVERT_FUNCTION(DSTPoint)
    obj.Set("iYear",res.iYear); 
    obj.Set("iMonth",res.iMonth);	        ///<周1:first  to2 3 4 -1:last one   0:表示使用按日计算的方法[-1,4]  
    obj.Set("iWeek",res.iWeek);	            ///<weekday from sunday=0	[0, 6]
    obj.Set("iWeekDay",res.iWeekDay); 
CONVERT_RETURN

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
    obj.Set("",convert(env,res.dDSTStart));
CONVERT_RETURN



CONVERT_FUNCTION(SDK_ExposureCfg)
    obj.Set("level",res.level);  //曝光等级
    obj.Set("leastTime",res.leastTime);  //自动曝光时间下限或手动曝光时间，单位微秒
    obj.Set("leastTime",res.mostTime);  //自动曝光时间上限，单位微秒
CONVERT_RETURN

CONVERT_FUNCTION(SDK_GainCfg)
    obj.Set("gain",res.gain);//自动增益上限(自动增益启用)或固定增益值
    obj.Set("autoGain",res.autoGain);//自动增益是否启用，0:不开启  1:开启
CONVERT_RETURN

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