//
//  "$Id: NetIPAbilitySet.h 18716 2015-12-16 09:26:12Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
// 	Description:	
// 	Revisions:		Year-Month-Day  SVN-Author  Modification
//  Modify:			能力集相关配置
//

#ifndef __EXCHANGE_AL_ABILITY_SET_H__
#define __EXCHANGE_AL_ABILITY_SET_H__

#include "Types/Types.h"
#include "CommExchange.h"
#include "MediaExchange.h"
#include "PAL/Capture.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////
/// 系统能力级
/// 编码功能
enum EncodeFunctionTypes
{
	ENCODE_FUNCTION_TYPE_DOUBLE_STREAM,		///< 双码流功能
	ENCODE_FUNCTION_TYPE_COMBINE_STREAM,	///< 组合编码
	ENCODE_FUNCTION_TYPE_SNAP_STREAM,		///< 抓图编码
	ENCODE_FUNCTION_TYPE_WATER_MARK,		///< 水印功能
	ENCODE_FUNCTION_TYPE_IFRAME_RANGE,		///< I帧间隔
	ENCODE_FUNCTION_TYPE_LOW_BITRATE,		///< 低码流，家用产品使用
	ENCODE_FUNCTION_TYPE_NR,
};

/// 报警功能
enum AlarmFucntionTypes
{
	ALARM_FUNCTION_TYPE_MOTION_DETECT,	///< 动态检测
	ALARM_FUNCTION_TYPE_BLIND_DETECT,	///< 视屏遮挡
	ALARM_FUNCTION_TYPE_LOSS_DETECT,	///< 视屏丢失
	ALARM_FUNCTION_TYPE_LOCAL_ALARM,	///< 本地报警
	ALARM_FUNCTION_TYPE_NET_ALARM,		///< 网络报警
	ALARM_FUNCTION_TYPE_IP_CONFLICT,	///< IP地址冲突
	ALARM_FUNCTION_TYPE_NET_ABORT,		///< 网络异常
	ALARM_FUNCTION_TYPE_STORAGE_NOTEXIST,	///< 存储设备不存在
	ALARM_FUNCTION_TYPE_STORAGE_LOWSPACE,	///< 存储设备容量不足
	ALARM_FUNCTION_TYPE_STORAGE_FAILURE,	///< 存储设备访问失败
	ALARM_FUNCTION_TYPE_VIEDO_ANALYZE,      ///< 视频分析
	ALARM_FUNCTION_TYPE_NET_ABORT_EXTEND,	//网络异常扩展
	ALARM_FUNCTION_TYPE_IPC_ALARM,			//IPC报警
	ALARM_FUNCTION_TYPE_NR
};

/// 网络服务功能
enum NetServerTypes
{
	NET_SERVER_TYPES_IPFILTER,		///< 白黑名单
	NET_SERVER_TYPES_DHCP,			///< DHCP功能
	NET_SERVER_TYPES_DDNS,			///< DDNS功能
	NET_SERVER_TYPES_EMAIL,			///< Email功能
	NET_SERVER_TYPES_MULTICAST,		///< 多播功能
	NET_SERVER_TYPES_NTP,			///< NTP功能
	NET_SERVER_TYPES_PPPOE,
	NET_SERVER_TYPES_DNS,
	NET_SERVER_TYPES_ARSP,			///< 主动注册服务
	NET_SERVER_TYPES_3G,            ///< 3G拨号功能
	NET_SERVER_TYPES_MOBILE,			///< 手机监控
	NET_SERVER_TYPES_UPNP,			///< UPNP
	NET_SERVER_TYPES_FTP,			///< FTP
	NET_SERVER_TYPES_WIFI,			///< WIFI
	NET_SERVER_TYPES_ALARM_CENTER,  ///< 告警中心
	NET_SERVER_TYPES_NETPLAT_MEGA,  ///< 互信互通
	NET_SERVER_TYPES_NETPLAT_XINWANG,  ///< 星望
	NET_SERVER_TYPES_NETPLAT_SHISOU,  ///< 视搜
	NET_SERVER_TYPES_NETPLAT_VVEYE,  ///< 威威眼
	NET_SERVER_TYPES_RTSP,           ///< RTSP
	NET_SERVER_TYPES_SHORT_MSG,      ///< 发送报警短信
	NET_SERVER_TYPES_MULTIMEDIA_MSG, ///< 发送带截图的彩信
	NET_SERVER_TYPES_DAS,			///<DAS
	NET_SERVER_TYPES_LOCALSDK_PLATFORM,///<网络平台信息设置
	NET_SERVER_TYPES_GOD_EYE,///<神眼接警中心系统
	NET_SERVER_TYPES_NAT,		///NAT穿透，MTU配置
	NET_SERVER_TYPES_VPN,		///VPN配置
	NET_SERVER_TYPES_NET_KEYBOARD,	///网络键盘配置
	NET_SERVER_TYPES_SPVMN,		///28181协议配置
	NET_SERVER_TYPES_PMS,
	NET_SERVER_TYPE_KAICONG,		///凯聪配置
	NET_SERVER_TYPE_PROTOCOL_MAC,///支持MAC协议
	NET_SERVER_TYPE_XMHEARTBEAT, //雄迈心跳
	NET_SERVER_TYPES_MONITOR_PLATFORM, //神州数码监控平台
	NET_SERVER_TYPES_ANJUP2P,			//anjuP2P
	NET_SERVER_TYPES_TUTKIOTC,			//TUTK IOTC平台
	NET_SERVER_TYPES_BAIDUCLOUD,		//百度云
	NET_SERVER_TYPES_MOBILWATCH,		//手机看店
	NET_SERVER_TYPES_BJLTHY,				//北京龙腾访问服务器平台
	NET_SERVER_TYPES_OPENVPN,			//openvpn配置
	NET_SERVER_TYPES_PROTOCOL_NAT,		//支持NAT协议
	NET_SERVER_TYPES_PLATFORM_GBEYES,	//支持环保数据叠加
	NET_SERVER_TYPES_DATALINK,			//DataLink客户网络服务中执行程序使能配置
	NET_SERVER_TYPES_WIFI_MODE,			//是否支持wifi模式相关配置
	NET_SERVER_TYPES_IPV6,				//支持ipv6
	NET_SERVER_TYPES_PMS_V2,			//新版PMS页面
	NET_SERVER_TYPES_4G,				//无线拨号的协议下拉框是否显示4G
	NET_SERVER_TYPES_NR,
};

/// 预览功能
enum PreviewTypes
{
	PREVIEW_TYPES_TOUR,		///< 轮巡
	PREVIEW_TYPES_TALK,		///< GUI界面配置
	PREVIEW_TYPES_NR
};

///串口类型
enum CommTypes
{
	COMM_TYPES_RS485,			///<485串口
	COMM_TYPES_RS232,			///<232串口
	COMM_TYPES_NR
};

///输入法类型
enum InputMethod
{
	NO_SUPPORT_CHINESE,		//不支持中文输入
	NO_SUPPORT_NR
};

///标签显示
enum TipShow
{
	NO_BEEP_TIP_SHOW,
	NO_FTP_TIP_SHOW,
	NO_EMAIL_TIP_SHOW,
	NO_TIP_SHOW_NR
};

///车载功能
enum MobileDVR
{
	MOBILEDVR_STATUS_EXCHANGE,
	MOBILEDVR_DELAY_SET,
	MOBILEDVR_CARPLATE_SET,
	MOBILEDVR_GPS_TIMING,
	MOBILEDVR_DVR_BOOT_TYPE_SET,
	MOBILEDVR_NR
};

///其他功能
enum OtherFunction
{
	OTHER_DOWNLOADPAUSE,		//录像下载暂停功能
	OTHER_USB_SUPPORT_RECORD,	//USB支持录像功能
	OTHER_SD_SUPPORT_RECORD,		//SD支持录像功能
	OTHER_ONVIF_CLIENT_SUPPORT,	//是否支持ONVIF客户端
	OTHER_NET_LOCALSEARCH_SUPPORT,	//是否支持远程搜索
	OTHER_MAXPLAYBACK_SUPPORT,		//是否支持最大回放通道数显示
	OTHER_SPECIAL_NVR_SUPPORT,	//是否是专业NVR
	OTHER_C7_PLATFORM_SUPPORT,		//支持C7平台
	OTHER_MAIL_TEST_SUPPORT,		//支持邮件测试
	OTHER_SHOW_OSD_INFO,		//支持显示3行OSD信息
	OTHER_HIDE_DIGITAL,		//通道模式屏蔽功能	
	OTHER_ACUTANCE_HORIZONTAL,	//水平锐度
	OTHER_ACUTANCE_VERTIAL,//垂直锐度
	OTHER_BROAD_TRENDS,		//宽动态功能
	OTHER_NO_TALK,		//对讲能力
	OTHER_ALTER_DIGITAL_NAME,	//修改数字通道名称OTHER_ALTER_CHANNELTITLE
	OTHER_SHOW_CONNECT_STATUS,      //支持显示wifi 3G 主动注册等的连接状态
	OTHER_SUPPORT_ECACT_SEEK,	//支持回放精准定位
	OTHER_UPLOAD_TITLEANDSTATE,		//通道标题和数字通道状态上传能力集
	OTHER_NO_HDD_RECORD,		//无硬盘录像
	OTHER_MUSICFILE_PLAY,		//播放音频文件
	OTHER_SUPPORT_SET_DIG_IP,//设置前端ip能力
	OTHER_VERSION_PRODUCT_TYPE,//支持在版本信息里显示设备型号
	OTHER_SUPPORT_CAMERA_IMG_STYLE,//支持摄像机图像风格
	OTHER_SUPPORT_TITLE_ABILITY,//支持修改onvif标题(当做模拟通道处理)
	OTHER_SUPPORT_DIMEN_CODE,//支持二维码
	OTHER_SHOWFALSE_CHECKTIME,//屏蔽解码器时间同步功能
	OTHER_SUPPORT_TIME_ZONE, //支持时区设置
	OTHER_SHOW_ALARM_LEVEL_REGION,//显示数字通道报警功能的灵敏度和区域设置
	OTHER_SUPPORT_POS,//支持POS功能
	OTHER_HDD_LOWSPACE_USE_MB,//硬盘空间不足报警下限用MB
	OTHER_SUPPORT_CUSTOMIZE_OEMINFO,//定制OEM客户版本信息
	OTHER_DIGITAL_ENCODE,//数字通道编码配置
	OTHER_RESUME_PTZ_STATE,//开机恢复云台状态
	OTHER_SUPPORT_SNAP_CFG,//支持抓图配置
	OTHER_ABNORMITY_SEND_EMAIL,//存储设备存在及存储异常及存储空间不足发邮件
	OTHER_SUPPORT_DIGITAL_PRE, //支持数字通道预录
	OTHER_SUPPORT_WRITE_LOG,   //报警页面添加是否写日志勾选框
	OTHER_SUPPORT_CHANGE_ONVIF_PORT,//支持修改onvif端口
	OTHER_SUPPORT_COMM_DATA_UPLOAD,  //支持串口数据上传到指定服务器
	OTHER_SUPPORT_TEXT_PASSWORD,     //记录可反解的密码
	OTHER_SUPPORT_CLOUD_UPGRADE,	// 支持通过云升级设备程序
	OTHER_SUPPORT_USER_PROGRAM,//支持启动客户小程序
	OTHER_SUPPORT_MODIFY_FRONT_CFG,//支持修改前端配置
	OTHER_SUPPORT_FTP_TEST,    //新程序支持FTP支持FTP测试，老程序不支持。
	OTHER_SUPPORT_PTZ_IDLE_STATE, //云台空闲时执行何种操作的配置
	OTHER_SUPPORT_IMP_RCD,	//web端是否提供关键录像搜索的选项	
	OTHER_SUPPORT_CAMERA_MOTOR_CTRL, //支持机器人马达控制
	OTHER_SUPPORT_ENCODE_ADD_BEEP,// 视频编码每隔30秒加入beep声	
	OTHER_SUPPORT_FISH_EYE,	        //鱼眼功能能力集
	OTHER_SUPPORT_SPVMN_NAS_SERVER,	//安徽超清客户的nas服务器配置
	OTHER_SUPPORT_SMALL_CHN_TITLE_FONT,  //IE端传12*18的通道标题点阵
	OTHER_RTSP_CLIENT_SUPPORT,			 //数字通道是否支持通过RTSP连接前端设备
	OTHER_SUPPORT_CFG_CLOUD_UPGRADE, 	//支持新的云升级功能配置
	OTHER_SUPPORT_STORAGE_FAIL_REBOOT,	//全部硬盘出错后自动重启
	OTHER_SUPPORT_SPLIT_CONTROL,		//修改DVR的预览画面分割模式
	OTHER_NR
};


/// 系统功能
struct SystemFunction
{
	bool vEncodeFunction[ENCODE_FUNCTION_TYPE_NR];		///< 编码功能EncodeFunctionTypes
	bool vAlarmFunction[ALARM_FUNCTION_TYPE_NR];		///< 报警功能AlarmFucntionTypes
	bool vNetServerFunction[NET_SERVER_TYPES_NR];		///< 网络服务功能NetServerTypes
	bool vPreviewFunction[PREVIEW_TYPES_NR];			///< 预览功能PreviewTypes
	bool vCommFunction[COMM_TYPES_NR];			///<串口类型CommTypes
	bool vInputMethodFunction[NO_SUPPORT_NR];	///<输入法类型InputMethod
	bool vTipShowFunction[NO_TIP_SHOW_NR];//标签显示TipShow
	bool vMobileDVRFunction[MOBILEDVR_NR];//车载功能MobileCar
	bool vOtherFunction[OTHER_NR];				//其他功能OtherFunction
};

//////////////////////////////////////////////////////////////////////////
/// 编码能力级
//by zjh  20170802
/// 编码信息
struct EncodeInfo
{
	bool bEnable;			///< 使能项
	int iStreamType;		///< 码流类型，capture_channel_t
	bool bHaveAudio;		///< 是否支持音频
	uint uiCompression;		///< capture_comp_t的掩码
	uint uiResolution;		///< capture_size_t的掩码
};

/// 编码能力
/// 说明： 
/// 1. vCombEncInfo 是组合编码的能力级只有3000系列的设备才有这个能力，5000之后的都没有使用了
/// 2. vEncodeInfo 是各个编码通道的能力信息，只描述上面与DspAbility.uiImageSize，DspAbility.uiExImageSize其实是重复的，但考虑到IE的兼容性这个没有拿掉
///    IE处理方式是当DspAbility.uiImageSize和DspAbility.uiExImageSize为0时使用vEncodeInfo里头的描述
/// 编码通道主码流支持的分辨率能力取决于2个方面: 1 - 当前通道支持的分辨率即DspAbility.uiImageSize 2 - 当前通道支持的最高编码能力即DspAbility.uiMaxPower
/// 这个能力是主码流和辅码流的总和
/// 编码通道辅码流支持的分辨率能力取决于3个方面: 1 - 当前通道支持的分辨率即DspAbility.uiExImageSize 2 - 当前通道支持的最高编码能力即DspAbility.uiMaxPower
/// 3 - 主码流设置的分辨率下辅码流支持的分辨率即DspAbility.uiExImageSizeEx
/// iChannelMaxSetSync： 1 - 表示所有通道的分辨率都要一样
struct EncodeAbility //结构体中带有容器，不能使用memset初始化整个结构体 sizeof[184 BYTE]
{
	int iMaxEncodePower;		///< 支持的总编码能力
	int iChannelMaxSetSync;		///< 每个通道分辨率是否需要同步 0-不同步, 1 -同步
	int	iMaxBps;				///< 支持的总码率大小Kbps
	EncodeInfo vEncodeInfo[CAPTURE_CHN_NR];	///< 编码信息
	EncodeInfo vCombEncInfo[CAPTURE_CHN_NR];	///< 组合编码信息
	std::vector<CAPTURE_CHANNEL_ABILITYV2> DspAbility;//sizeof[120 BYTE] 120*32 == 3804 BYTE
};

//by zjh 20170802
struct EncodeAbility_Expand
{
	unsigned int iMaxEncodePower;		///< 支持的总编码能力
	int iChannelMaxSetSync;		///< 每个通道分辨率是否需要同步 0-不同步, 1 -同步
	uint nMaxPowerPerChannel[N_SYS_CH];		///< 每个通道支持的最高编码能力
	uint ImageSizePerChannel[N_SYS_CH];		///< 每个通道支持的图像分辨率
	uint ExImageSizePerChannel[N_SYS_CH];		///< 每个通道支持的辅码流图像分辨率
	EncodeInfo vEncodeInfo[CAPTURE_CHN_NR];	///< 编码信息
	EncodeInfo vCombEncInfo[CAPTURE_CHN_NR];	///< 组合编码信息
	int	iMaxBps;				///< 支持的总码率大小Kbps
	uint ExImageSizePerChannelEx[N_SYS_CH][CAPTURE_IMAGE_SIZE_EXT_NR];	///< 指定主码流分辨率下每个通道的辅码流支持的图像分辨率
};

struct DigitDevInfo
{
	bool enable; //配置是否可用，本地设备使用
	int nCapture;//模拟通道数
	int nAudio;//音频通道数
	int videoFormat;//视频制式
	EncodeAbility ability;//编码能力
};

struct EncodeChDisplay
{
	uint displayChanelMask;	//IE显示的编码配置通道号掩码
};

/// 区域遮挡能力集
struct BlindDetectFunction
{
	int iBlindConverNum;	///< 区域遮挡块数
};

/// 动检区域能力集
struct MotionDetectFunction
{
	int iGridRow;
	int iGridColumn;
};

/// 支持的DDNS类型
struct DDNSServiceFunction
{
	std::vector<std::string> vDDNSTypes;
};

/// 串口协议
struct CommFunction
{
	std::vector<std::string> vCommProtocols;
};

/// 云台协议
struct PTZProtocolFunction
{
	std::vector<std::string> vPTZProtocols;
};

/// 对讲音频能力集合
struct TalkAudioFormatFunction
{
	AudioInFormatConfigAll audioFormat;
};

/// 语言支持
struct MultiLangFunction
{
	std::vector<std::string> vMultiLanguage;
};

/// 视频制式支持
struct MultVstdFunction
{
	std::vector<std::string> vMultiVstd;
};

///网络优先级能力
struct NetOrderFunction
{
	bool bNetOrder;
};

///网络链接能力
struct NetConnectAbility
{
	int nCurTcpNum;
	int nMaxTcpNum;
	int nCurNatNum;
	int nMaxNatNum;
};
///车辆状态数
struct CarStatusNum
{
	int iCarStatusNum;
};

/// 支持的VGA分辨率列表
struct VGAResolutionAbility
{
	std::vector<std::string> vAbilityVGA;
};

//支持的静态编码参数的掩码
//见枚举EncStaticParamV2
struct EncStaticParamAbility
{
	uint encStaticParam;
};

struct VNetKeyboardAbility
{
	std::vector<std::string> vTransProtocol;
	std::vector<std::string> vParserProtocol;
};

struct PTZControlAbility
{
	uint nPTZPosition;
};

struct DecodeDeleyTimePrame
{
	uint DecodeDeleyTime[DecodeDeley_TYPE_NR];
};
//能力掩码，可以作为通用结构体解析
//EncStaticParamAbility、PTZControlAbility等都可以用这个结构体
//int 和uint 也可以共用这个
typedef struct AbilityMask
{
	uint AbilityPram;
}AbilityEnum;

struct DimenCode
{
	int size;
	uchar code[3920];// MAX_MODULESIZE*MAX_MODULESIZE/32*4=3920，局部变量 MAX_MODULESIZE = 177
};

struct DimenCodeAll
{
	DimenCode sn;
	DimenCode appIOS;
	DimenCode appAndroid;
	DimenCode otherInfo;  //客户自定义信息
};

struct BrowserLanguageType
{
	int type;
};

struct CustomizeOEMInfo
{
	uint typeMask;//类型: BITMSK(BURN_OEM_ID),BITMSK(BURN_OEM_PRODUCT),BITMSK(BURN_OEM_SERIAL)
	uint oemID;
	uint oemProduct;
	uint oemSerial;
};

//AHDL通道掩码，该通道为AHDL置1
struct AHDEncodeLMask
{
	uint AHDLMask;
};

///I帧间隔范围
struct Onvif_IFrameRange
{
	int main_min;
	int main_max;
	int sub_min;
	int sub_max;
};

#endif
