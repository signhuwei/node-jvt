//geyijun @ 20120815
//以NetSDK  版本的头文件为基础进行重新整理
//去掉一些历史遗留，使接口更加的简洁易用
//按照下面的顺序进行排列: 

//===规格常数定义===
//定义支持的最大规格宏，确定数组大小用

//===基本数据类型===
//定义一些常用的数据类型，便于后面书写

//===扩展数据类型===
//定义SDK 内中后续结构体常用的类型，便于后面书写

//===错误码枚举===
//定义错误返回码

//===报警接口相关===
//定义报警相关的结构体定义

//===能力集接口相关===
//定义能力集相关的结构体定义

//===信息接口相关===
//定义设备信息相关的结构体定义

//===操作接口相关===
//===存储操作接口===
//===用户管理接口===
//===云台控制接口===
//定义设备操作相关的结构体定义
//包括基本操作，存储操作， 用户管理

//===实时监视接口相关===
//实时监视相关数据结构

//===回放下载接口相关===
//回放下载相关数据结构

//===对讲接口相关===
//对讲相关数据结构

//===透明串口接口相关===
//透明串口相关数据结构

//===设备搜索接口相关===
//设备搜索相关数据结构

//===配置接口相关===
//定义设备操作相关的结构体定义

#ifndef __EZ_SDK_DEF_H__
#define __EZ_SDK_DEF_H__

//=======================规格常数定义==================
//定义支持的最大规模，具体取值由各设备能力集中获得
#define EZ_SDK_NAME_LENGTH			128	//通常字符串长度
#define EZ_SDK_PATH_LENGTH	      		256	//通常路径长度
#define EZ_SDK_MAC_LENGTH       		32  	//MAC地址字符最大长度
#define EZ_SDK_TITLE_LENGTH			64	//常用标题的最大长度
#define EZ_SDK_SERIAL_NUMBER		128	//设备序列号的长度

#define EZ_SDK_CHANNEL_NUM 		32	//视频输入通道个数
#define EZ_SDK_DIGITAL_SOURCE_NUM 32	//一个数字通道支持输入的数据源数
#define EZ_SDK_VIDEOOUT_NUM 		2	//视频输出通道个数	
#define EZ_SDK_EXTRA_STREAM_NUM 	3	//辅码流的最大规格
#define EZ_SDK_NET_INTERFACE_NUM	2	//网卡个数
#define EZ_SDK_ALARMIN_NUM 		8	//报警输入通道个数
#define EZ_SDK_ALARMOUT_NUM 		8	//报警输出通道个数	
#define EZ_SDK_COM_NUM				2	//最大的串口个数	
#define EZ_SDK_DISK_NUM				8	//最大支持的磁盘的个数

#define EZ_SDK_WEEKS_NUM			7	//一星期的天数
#define EZ_SDK_TSECT_NUM			6	//一天的最大时间段数
#define EZ_SDK_MIN_TSECT_NUM		2	//一天的最小时间段数
#define EZ_SDK_COVER_NUM			4	//最大支持的cover的个数
#define EZ_SDK_MD_REGION_ROW		32	//动检区域的最大行数
#define EZ_SDK_MD_REGION_COLUMN	32	//动检区域的最大列数
#define EZ_SDK_RIGHT_TYPE_NUM		128	//最支持的权限的种类
#define EZ_SDK_MAX_GROUP_NUM		50	//最多支持组数
#define EZ_SDK_MAX_USER_NUM		60	//最多支持用户数
#define EZ_SDK_DDNS_TYPE_NUM		6	//支持DDNS  服务的类型个数
#define EZ_SDK_DDNS_NUM			6	//支持DDNS  服务器的个数
#define EZ_SDK_ARSP_NUM			5	//支持ARSP  服务器的个数 
#define EZ_SDK_ALARMSERVER_NUM	5     	//支持报警中心的个数 
#define EZ_SDK_ACCESSFILTER_NUM	64	//IP过滤项个数
#define EZ_SDK_EMAIL_RECV_NUM		8	//EMAIL接收者的最大数量
#define EZ_SDK_MMS_RECV_NUM		8	//MMS接收者的最大数量
#define EZ_SDK_MOBILE_ACT_NUM		8	//拨号唤醒列表的数量
#define EZ_SDK_WIFI_TOKEN_NUM		128	//WIFI 密码 的长度
#define EZ_SDK_WLAN_AP_NUM		32	//最大支持的搜索返回的AP  个数
#define EZ_SDK_RETURN_LOG_NUM		128	//单次返回的日志条数
#define EZ_SDK_UPNP_PORT_NUM		32	//最大支持的UPUP  映射出来的端口的数量

#define EZ_SDK_EXPOSURE_LEVEL_NUM 16	//最大支持的曝光速度等级数
#define EZ_SDK_HVR_CHN_MODE_NUM	32	//HVR 最大支持的通道模式数
#define EZ_SDK_POLYGON_POINT_NUM 	8	//多边形的点数
#define EZ_SDK_PEA_PERIMETER_NUM	1	//支持的PERIMETER规则数
#define EZ_SDK_PEA_TRIPWIRE_NUM	1	//支持的TRIPWIRE规则数
#define EZ_SDK_TRIPWIRE_IN_RULE	8	//在一条规则中允许的线数



//=======================基本数据类型==================
//#include "../../Include/Infra/Types.h"

typedef signed char				schar;
typedef unsigned char			uchar;
typedef unsigned int			uint;
typedef unsigned short			ushort;
typedef unsigned long			ulong;
typedef long long				int64;
typedef unsigned long long		uint64;


typedef struct EZ_Rect{
	int 	left;
	int 	top;
	int 	right;
	int 	bottom;
} EZ_Rect;

typedef struct EZ_Point{
	int 	x;
	int 	y;
} EZ_Point;

typedef struct Line{
	EZ_Point s;
	EZ_Point e;
} Line;

typedef struct _Polygon{
	int	 pointNum;
	EZ_Point point[EZ_SDK_POLYGON_POINT_NUM];
} _Polygon;

typedef struct EZ_Size{
	int 	w;
	int 	h;
} EZ_Size;

typedef struct Color{
	uchar 	r;
	uchar 	g;
	uchar 	b;
	uchar 	a;
} Color;

//=======================扩展数据类型==================

// IP  地址
typedef union 
{
	uchar	c[4];	//"[3]xxx.[2]xxx.[1]xxx.[0]xxx"
	ushort	s[2];
	uint 		l;
}EZ_SDK_IPADDR;

// 系统时间
typedef struct EZ_SDK_SYSTEM_TIME{
	int  year;		//年。   
	int  month;	//月，January = 1, February = 2, and so on.   
	int  day;		//日。   
	int  wday;	//星期，Sunday = 0, Monday = 1, and so on   
	int  hour;		//时。   
	int  minute;	//分。   
	int  second;	//秒。  
}EZ_SDK_SYSTEM_TIME;

//时间段
typedef struct EZ_SDK_TIMESECTION
{
	int 	enable;		//使能mask
	int 	startHour;
	int	startMinute;
	int	startSecond;
	int	endHour;
	int	endMinute;
	int	endSecond;	
}EZ_SDK_TIMESECTION;	

//工作表
typedef struct EZ_SDK_CONFIG_WORKSHEET
{	
	EZ_SDK_TIMESECTION	schedule[EZ_SDK_WEEKS_NUM][EZ_SDK_TSECT_NUM];
}EZ_SDK_CONFIG_WORKSHEET;

//=======================错误码枚举=====================
typedef enum EZ_SDK_RET_CODE
{	
	EZ_SDK_NOERROR					= 0,			//没有错误
	EZ_SDK_SUCCESS					= 1,			//返回成功
	EZ_SDK_NOT_INIT					= -10000,		//SDK未经初始化
	EZ_SDK_INVALID_CMD				= -10001,		//非法请求
	EZ_SDK_INVALID_PARAM				= -10002,		//用户参数不合法
	EZ_SDK_INVALID_HANDLE				= -10003,		//句柄无效	
	EZ_SDK_CLEANUP_ERROR				= -10004,		//SDK清理出错
	EZ_SDK_TIMEOUT					= -10005,		//等待超时
	EZ_SDK_MEMORY_ERROR				= -10006,		//内存错误，创建内存失败
	EZ_SDK_NET_ERROR					= -10007,		//网络错误
	EZ_SDK_OPEN_FILE_ERROR			= -10008,		//打开文件失败
	EZ_SDK_UNKNOWN_ERROR			= -10009,		//未知错误
	EZ_SDK_VERSION_ERROR				= -10010,		//收到数据不正确，可能版本不匹配
	EZ_SDK_NOT_SUPPORT				= -10011,		//不支持
	EZ_SDK_CONNECT_DEVICE_ERROR    	= -10012,		//可能设备不存在
	EZ_SDK_OPEN_CHANNEL_ERROR		= -10013,		//打开通道失败
	EZ_SDK_CLOSE_CHANNEL_ERROR		= -10014,		//关闭通道失败
	EZ_SDK_SUB_CONNECT_ERROR		= -10015,		//建立媒体子连接失败
	EZ_SDK_SUB_CONNECT_SEND_ERROR	= -10016,		//媒体子连接通讯失败
	EZ_SDK_NOPTZPROTOCOL 			= -10017,		//未设置云台协议
	
	// 用户管理部分错误码
	EZ_SDK_NO_POWER					= -11300,		//无权限
	EZ_SDK_PASSWORD_NOT_VALID		= -11301,		//账号密码不对
	EZ_SDK_USER_NOEXIST				= -11302,		//用户不存在
	EZ_SDK_USER_LOCKED				= -11303,		//该用户被锁定
	EZ_SDK_USER_IN_BLACKLIST			= -11304,		//该用户不允许访问(在黑名单中)
	EZ_SDK_USER_HAS_USED				= -11305,		//该用户已经登陆
	EZ_SDK_USER_NOT_LOGIN			= -11306,		//该用户没有登陆
	EZ_SDK_ACCOUNT_INPUT_NOT_VALID 	= -11308,		//用户管理输入不合法
	EZ_SDK_ACCOUNT_OVERLAP			= -11309,		//索引重复
	EZ_SDK_ACCOUNT_OBJECT_NONE		= -11310,		//不存在对象, 用于查询时
	EZ_SDK_ACCOUNT_OBJECT_NOT_VALID= -11311,		//不存在对象
	EZ_SDK_ACCOUNT_OBJECT_IN_USE	= -11312,		//对象正在使用
	EZ_SDK_ACCOUNT_SUBSET_OVERLAP	= -11313,		//子集超范围 (如组的权限超过权限表，用户权限超出组的权限范围等等)
	EZ_SDK_ACCOUNT_PWD_NOT_VALID	= -11314,		//密码不正确
	EZ_SDK_ACCOUNT_PWD_NOT_MATCH	= -11315,		//密码不匹配
	EZ_SDK_ACCOUNT_RESERVED			= -11316,		//保留帐号
	
	//配置管理相关错误码	
	EZ_SDK_CONFIG_ERROR 				= -11400,		//保存配置出错
	EZ_SDK_CONFIG_RESTART			= -11401,		//保存配置后需要重启
	EZ_SDK_CONFIG_REBOOT				= -11402,		//需要重启系统
	EZ_SDK_CONFIG_FILE_ERROR			= -11403,		//写文件出错
	EZ_SDK_CONFIG_CAPS_ERROR			= -11404,		//配置特性不支持
	EZ_SDK_CONFIG_VERIFY_ERROR		= -11405,		//配置校验失败
	EZ_SDK_CONFIG_NOT_EXIST			= -11406,		//请求或者设置的配置不存在
	EZ_SDK_CONFIG_PARSE_FAILED 		= -11407,		//配置解析出错
	//回放控制操作
	EZ_SDK_CTRL_PAUSE_ERROR			= -11500,		//暂停失败
	EZ_SDK_FILE_NOT_FOUND				= -11501,		//查找失败，没有找到对应文件

	//下面的错误是对上面常规错误的补充
	EZ_SDK_TALK_ALAREADY_START 		= -11600,		//对讲已经开启
	EZ_SDK_TALK_NOT_START 			= -11601,		//对讲未开启
	EZ_SDK_UPGRADE_ALAREADY_START 	= -11602, 	//已经开始升级
	EZ_SDK_UPGRADE_NOT_START  		= -11603,		//未开始升级
	EZ_SDK_UPGRADE_DATA_ERROR  		= -11604,		//升级数据错误
	EZ_SDK_UPGRADE_FAILED  			= -11605,		//升级失败
	EZ_SDK_UPGRADE_SUCCESS  			= -11606,		//升级成功

}EZ_SDK_RET_CODE;

//=======================报警接口相关==================
typedef enum EZ_SDK_EVENT_TYPE
{
	EVENT_SYSTEM_INIT = 0,			//系统初始化完成
	EVENT_ALARM_LOCAL,			//本地报警输入
	EVENT_ALARM_NET,				//网络报警
	EVENT_ALARM_MANUAL,			//手动报警
	EVENT_VIDEO_MOTION,			//动态监测
	EVENT_VIDEO_LOSS,				//视频丢失
	EVENT_VIDEO_BLIND,				//视频遮挡
	EVENT_VIDEO_ANALYSE,			//智能报警
	EVENT_NET_ABORT,				//断网监测
	EVENT_NET_IPCONFLICT,			//IP	地址冲突
	EVENT_STORAGE_NOTEXIST,		//磁盘不存在
	EVENT_STORAGE_LOWSPACE,		//磁盘容量低于设定的门限值	
	EVENT_STORAGE_FAILURE,		//磁盘操作失败
	EVENT_STORAGE_READ_ERROR,	//磁盘读失败
	EVENT_STORAGE_WRITE_ERROR,	//磁盘写失败
	EVENT_ALARM_EMERGENCY,		//???
	EVENT_DEC_CONNECT,			//设备连接通道事件
	EVENT_TYPE_NR,
}EZ_SDK_EVENT_TYPE;

//报警信息
typedef struct EZ_SDK_ALARM_INFO{
	int 	channel;		//
	int 	event;		//参见enum EZ_SDK_EVENT_TYPE
	int 	status;		//0-结束，1-开始
	EZ_SDK_SYSTEM_TIME sysTime;	
}EZ_SDK_ALARM_INFO;

//=======================能力集接口相关==================
typedef enum EZ_SDK_ABILITY_TYPE
{
	EZ_ABILITY_GENERAL = 0,	//基本能力信息(输入输出通道数)
	EZ_ABILITY_ALARM,			//报警功能能力集
	EZ_ABILITY_NETAPP,		//支持的网络功能
	EZ_ABILITY_ENCODE,		//编码能力
	EZ_ABILITY_COM,			//串口功能	
	EZ_ABILITY_PTZ,			//云台协议
	EZ_ABILITY_VIDEODETCT,	//视频检测块
	EZ_ABILITY_COVER,			//视频遮挡块
	EZ_ABILITY_DDNS,			//DDNS服务支持类型
	EZ_ABILITY_VIDEOIN,		//摄像头属性配置相关的能力级	
	EZ_ABILITY_NETIP,			//支持的设备操作协议
	EZ_ABILITY_HVR_CH_MODE,	//HVR 支持的通道配置模式
	EZ_ABILITY_IVS,			//智能分析能力集
	EZ_ABILITY_TYPE_NR,
}EZ_SDK_ABILITY_TYPE;

//视频制式
typedef enum EZ_SDK_VIDEO_STANDARD
{
	EZ_PAL = 0,
	EZ_NTSC = 1,
}EZ_SDK_VIDEO_STANDARD;

//语言类型
typedef enum EZ_SDK_LANAGUAGE
{
	EZ_ENGLISH = 0,
	EZ_SIMPCHINESE,
}EZ_SDK_LANAGUAGE;

//码流类型
typedef enum EZ_SDK_STREAM_TYPE 
{
	MAIN= 0,
	EXTRA1=1,
	EXTRA2=2,
	EXTRA3=3,
	SNAP=4,
	STREAM_TYPE_NR,	
}EZ_SDK_STREAM_TYPE;

// 通用图像大小类型	
typedef enum EZ_SDK_IMAGE_SIZE_TYPE
{
	EZ_SDK_D1,			//< 704*576(PAL)	704*480(NTSC)
	EZ_SDK_HD1,		//< 352*576(PAL)	352*480(NTSC)
	EZ_SDK_BCIF,		//< 704*288(PAL)	704*240(NTSC)
	EZ_SDK_CIF,			//< 352*288(PAL)	352*240(NTSC)
	EZ_SDK_QCIF,		//< 176*144(PAL)	176*120(NTSC)
	EZ_SDK_VGA,		//< 640*480
	EZ_SDK_QVGA,		//< 320*240
	EZ_SDK_SVCD,		//< 480*480
	EZ_SDK_QQVGA,		//< 160*128
	EZ_SDK_SVGA,		//< 800*592
	EZ_SDK_XVGA,		//< 1024*768
	EZ_SDK_WXGA,		//< 1280*800
	EZ_SDK_SXGA,		//< 1280*1024 
	EZ_SDK_WSXGA,		//< 1600*1024 
	EZ_SDK_UXGA,		//< 1600*1200
	EZ_SDK_WUXGA,		//< 1920*1200
	EZ_SDK_ND1,		//< 240*192
	EZ_SDK_960H,		//< 928*576(PAL)	928*480(NTSC)
	EZ_SDK_720P,		//< 1280*720
	EZ_SDK_960P,		//< 1280*960
	EZ_SDK_1080P,		//< 1920*1080
	EZ_SDK_2_5M,		//< 1872*1408
	EZ_SDK_5M,			//< 3744*1408
	EZ_SDK_3M,			//< 2048*1536
	EZ_SDK_IMAGE_SIZE_NR,
}EZ_SDK_IMAGE_SIZE_TYPE;

typedef struct EZ_SDK_ABILITY_GENERAL
{
	int  	numVideoInCh;		//视频输入通道数
	int  	numVideoOutCh;		//视频输出通道数
	int  	numVideoStream;		//视频码流数(最大为STREAM_TYPE)
	int  	numAlarmIn;			//报警输入通道数
	int  	numAlarmOut;		//报警输出通道数	
	int 	numCom;			//支持串口的数量0:不支持
	int 	numDisk;			//支持磁盘的数量0:不支持
	int 	numNetInterface;		//支持的网卡的数量
	int	maskLanguage;		//支持的语言掩码,见上面的EZ_SDK_LANAGUAGE
	int	maskStandard;		//支持的制式掩码,见上面的EZ_SDK_VIDEO_STANDARD
	int 	reserve[26];			//
}EZ_SDK_ABILITY_GENERAL;

typedef struct EZ_SDK_ABILITY_ALARM
{
	int 	enableLocalAlarm;			//本地报警
	int 	enableNetAlarm;			//网络报警
	int 	enableIPConlict;			//IP地址冲突
	int 	enableNetAbort;			//网络异常
	int 	enableStorageNotExit;		//存储设备不存在
	int 	enableStorageLowSpace;	//存储设备容量不足
	int 	enableStorageFailure;		//存储设备访问失败
	int 	reserve[26];				//
}EZ_SDK_ABILITY_ALARM;	

typedef struct EZ_SDK_ABILITY_NETAPP
{
	int 	enableDHCP;
	int 	enableDNS;			
	int 	enableIPFILTER;
	int 	enableNTP;
	int 	enableEMAIL;
	int 	enableDDNS;
	int 	enablePPPOE;
	int 	enableRTSP;
	int 	enableWIFI;
	int 	enable3G;
	int 	enableSMS;
	int 	enableMMS;
	int 	enableFTP;
	int 	enableUPNP;
	int 	enableARSP;
	int 	enableALARMCENTER;
	int 	enableDAS;
	int	reserve[16];	//保留	
}EZ_SDK_ABILITY_NETAPP;

typedef struct EZ_SDK_ABILITY_ENCODE
{
	int 	maxEncodePower;		//< 支持的最大编码能力
	int	maxBps;					//< 最高码流Kbps
	int 	numExStream;			//< 辅码流的个数
	int 	enSnapStream;			//< 是否支持抓图码流
	int	channelSync;				//< 每个通道分辨率是否需要同步0-不同步, 1 -同步
	int 	maxPowerCh[EZ_SDK_CHANNEL_NUM];	//< 每个通道支持的最高编码能力
	int 	mainImageSize[EZ_SDK_CHANNEL_NUM];	//< 每个通道每种码流类型支持的图像分辨率, 取EZ_SDK_IMAGE_SIZE_TYPE  的掩码
	int 	extraImageSize[EZ_SDK_CHANNEL_NUM][EZ_SDK_IMAGE_SIZE_NR];	//当主码流设定到某一个分辨率时，所对应的辅码流分辨率范围!
	int	reserve[32];				//保留	
}EZ_SDK_ABILITY_ENCODE;

typedef enum EZ_SDK_COM_FUNC		//支持的串口协议
{
	EZ_COM_CONSOLE = 0,		//无
	EZ_COM_TRANSPORT,		//透明传输
	EZ_COM_PTZCTRL,			//云台控制
	EZ_COM_KEYBOARD,			//键盘接口
	EZ_COM_FUNCTION_NR,
}EZ_SDK_COM_FUNC;	

typedef struct EZ_SDK_ABILITY_COM
{
	int	numCom;						//支持串口的个数
	int 	maskComFun[EZ_SDK_COM_NUM];	//串口的功能掩码(对应于enum EZ_SDK_COM_FUNC)
	int	reserve[32];						//保留	
}EZ_SDK_ABILITY_COM;				

typedef enum EZ_SDK_PTZ_PROTO		//支持的云台协议
{
	PTZ_XXX = 0,							//
	PTZ_PROTO_NR,
}EZ_SDK_PTZ_PROTO;

typedef struct EZ_SDK_ABILITY_PTZ
{
	int 	numPtz;							//支持云台的个数
	int 	maskPtzProto[EZ_SDK_CHANNEL_NUM];	//云台协议掩码(对应于enum EZ_SDK_PTZ_PROTO)
	int	reserve[32];						//保留	
}EZ_SDK_ABILITY_PTZ;

typedef struct EZ_SDK_ABILITY_VIDEODETECT
{	
	int enableBlind;			//是否支持遮挡检测
	int enableLoss;			//是否支持视频丢失检测
	int enableMotion;			//是否支持动态检测
	int enableResult;			//是否能够得到每块区域的检测结果	
	int regionColumns;		//动态检测区域划分的列数
	int regionRows;			//动态检测区域划分的行数
	int	reserve[32];			//保留		
}EZ_SDK_ABILITY_VIDEODETECT;
	
typedef struct EZ_SDK_ABILITY_COVER
{
	int 	numCover;			//区域遮挡块数
	int	reserve[32];			//保留		
}EZ_SDK_ABILITY_COVER;

typedef struct EZ_SDK_ABILITY_DDNS
{
	int  	numDDNS;			//支持的DDNS  的个数
	char typeDDNS[EZ_SDK_DDNS_TYPE_NUM][EZ_SDK_NAME_LENGTH];//支持的协议类型
	int	reserve[32];			//保留		
}EZ_SDK_ABILITY_DDNS;

typedef struct EZ_SDK_ABILITY_VIDEOIN
{
	//基本部分
	int  enableBrightness;		//亮度 是否可调 ；1 可 0不可
	int  enableContrast;		//对比度 可调
	int  enableHue;			//色度 可调
	int  enableSaturation;	 	//饱和度 可调
	//高级功能
	int  enableBacklight;		//背光补偿 支持的背光补偿等级数 0表示不支持背光补偿,1表示支持一级补偿（开,关），2表示支持两级补偿（关,高,低），3表示支持三级补偿（关,高,中,低）
	int  enableColorSwitch;		//彩黑转换 可调
	int  enableMirror;	     		//镜像  1 支持， 0不支持
	int  enableFlip;	         	//翻转  1 支持， 0不支持
	int  enableRejectFlicker;	//是否支持日光灯防闪功能
	int  enableEsShutter;		//是否电子慢快门功能
	int  enableExposure;  		//曝光选择能力 值n， 分三个等级	: 0表示不支持曝光控制，1表示只支持自动曝光, 2~(n-1)表示支持的手动曝光等级
	int  enableLimitedExposure;	//是否支持带时间上下限的自动曝光0-不支持 1-支持
	int  enableCustomExposure;//是否支持用户自定义手动曝光时间0-不支持 1-支持
	int  enableReferenceLevel;	//是否支持参考电平值
	int  enableWhiteBalance;	// 白平衡 0-不支持白平衡，1-支持自动白平衡，2-支持预置白平衡（即情景模式） 3-也支持自定义白平衡
	int  exposureSpeeds[EZ_SDK_EXPOSURE_LEVEL_NUM]; //支持的曝光速度
	//分段效果
	int  enableSectOptions;		//是否支持分段效果设置>1 表示支持的分段数
	int  reserve[16];			//保留
}EZ_SDK_ABILITY_VIDEOIN;

typedef struct EZ_SDK_ABILITY_NETIP
{
	int 	enableXM;		//雄迈协议
	int 	enableDH;		//大华协议
	int 	enableONVIF;	//ONVIF  协议
	int	reserve[16];		//保留	
}EZ_SDK_ABILITY_NETIP;

typedef struct EZ_SDK_HVR_CH_PARAM 
{
	int nD1Chn;			//支持的D1路数
	int n960HChn;		//支持的960H 路数
	int n720PChn;		//支持的720P路数
	int n1080PChn;		//支持的1080P路数
	int nCIFChn;			//支持的CIF 通道数
	int nHD1Chn;			//支持的HD1 通道数
	int nRes[32];
}EZ_SDK_HVR_CH_PARAM;

typedef struct EZ_SDK_HVR_MODE
{
	EZ_SDK_HVR_CH_PARAM	digitalCap;	//支持的数字通道信息
	EZ_SDK_HVR_CH_PARAM	analogCap;	//支持的模拟通道信息
}EZ_SDK_HVR_MODE;

typedef struct EZ_SDK_ABILITY_HVR_CH_MODE
{
	int		modeNum;		//实际支持的模式数
	EZ_SDK_HVR_MODE mode[EZ_SDK_HVR_CHN_MODE_NUM];
	int  		reserve[32];		//保留
}EZ_SDK_ABILITY_HVR_CH_MODE;
		
//智能分析算法模块 
typedef struct EZ_SDK_ABILITY_IVS
{
	int enablePEA;	//区域拌线
	int enableAVD;	//			
	int enableVFD;	//
	int enableOSC;	//物体看护
	int enableCPC;	//物体计数
	//PEA 能力	
	int numPEARules;	//PEA最大规则数
	int reserve[32];	//保留	
}EZ_SDK_ABILITY_IVS;	

//=======================信息接口相关==================
typedef enum EZ_SDK_INFO_TYPE	
{
	GENERAL_INFO = 0,	//基本信息
	TIME_INFO,			//时间信息
	_DISK_INFO,			//硬盘信息
	WORKSTATE_INFO,	//工作状态信息	
	AP_INFO,			//WIFI 信号扫描
	L_3G_INFO	,		// 3G 网络
	DIGITAL_CH_INFO,	//数字通道状态
	NAT_INFO,			//NAT状态信息
	_DDNS_INFO,			//DDNS 注册状态信息
	PPPOE_INFO,			//PPPOE拨号状态信息
	WLAN_INFO,			//WIFI 连接状态信息
	UPNP_INFO,			//UPNP 状态信息
	INFO_NR,			
}EZ_SDK_INFO_TYPE;

typedef enum EZ_SDK_DEV_TYPE
{
	EZ_DEVICE_TYPE_DVR,	// 普通DVR设备
	EZ_DEVICE_TYPE_NVS,	// NVS设备
	EZ_DEVICE_TYPE_IPC,	// IPC设备
	EZ_DEVICE_TYPE_HVR,	//混合dvr
	EZ_DEVICE_TYPE_IVR,	//智能dvr
	EZ_DEVICE_TYPE_MVR,	//车载dvr
	EZ_DEVICE_TYPE_NR
}EZ_SDK_DEV_TYPE;

typedef struct EZ_SDK_GENERAL_INFO
{
	char	serialNo[EZ_SDK_SERIAL_NUMBER];	//设备序列号
	char	softVersion[32];		//软件版本
	char	hardVersion[32];		//硬件版本
	char	encryptVersion[32];	//软件版本
	char	builddate[32];			//编译日期: xxxx-xx-xx:xx:xx
	int	runtime;				//程序运行的时间;单位s
	int	devType;			//设备类型，见EZ_SDK_DEV_TYPE
	char productName[64];		//产品名字
	int	reserve[32];			//
}EZ_SDK_GENERAL_INFO;

typedef struct EZ_SDK_TIME_INFO
{
	EZ_SDK_SYSTEM_TIME curTime;	
}EZ_SDK_TIME_INFO;

typedef enum EZ_SDK_WORKDIR_TYPE
{
	READ_WRITE= 0,	//读写驱动器(常规录像用的)
	READ_ONLY	= 1,	//只读驱动器()
	SNAPSHOT	= 2,	//快照驱动器(存放抓图文件)
	WORKDIR_TYPE_NR,
}EZ_SDK_WORKDIR_TYPE;

typedef struct EZ_SDK_WORKDIR_ONE
{
	EZ_SDK_WORKDIR_TYPE	dirType;	//工作目录类型
	int		isCurrent;		//是否为当前工作盘
	long		totalSpace;		//总容量
	long		leftSpace;		//剩余容量
	long		errorFlag;		//错误标志
	int		logicNo;			//逻辑编号	
	EZ_SDK_SYSTEM_TIME startTime;	//录像开始时间
	EZ_SDK_SYSTEM_TIME endTime;	//录像结束时间
}EZ_SDK_WORKDIR_ONE;

typedef struct EZ_SDK_DISK_ONE
{
	int		physicalNo;	//物理接口编号
	int		physicalType;	//驱动器类型0-SD card; 1-UDisk; 2-IDE ; 3-SATA 4-FTP 5-SAMBA
	int		numPartion;	//分区数目
	EZ_SDK_WORKDIR_ONE	partion[4];
}EZ_SDK_DISK_ONE;

typedef struct EZ_SDK_DISK_INFO
{
	int		numDisk;
	EZ_SDK_DISK_ONE	disk[EZ_SDK_DISK_NUM];
}EZ_SDK_DISK_INFO;

typedef struct EZ_SDK_CHANNLE_STATUS
{
	int 		bitrate;		//码流统计信息
	char		recording;	//是否正在录像
	char 		alarmIn;		//告警输入状态
	char		alarmOut;	//告警输出状态
	char 		videoBlind;	//视频遮挡状态
	char 		videoLoss;	//视频丢失状态
	char 		videoMotion;	//移动侦测状态
	char 		videoAnalyse;//视频分析状态
	int		reserve[32];	
}EZ_SDK_CHANNLE_STATUS;

typedef struct EZ_SDK_WORKSTATUS_INFO
{
	EZ_SDK_CHANNLE_STATUS ch[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_WORKSTATUS_INFO;

typedef struct EZ_SDK_AP_ONE
{
	char	ssid[EZ_SDK_NAME_LENGTH];	
	int	linkMode;		//0:adhoc 1:Infrastructure
	int 	encryption;		//认证+加密类型(联合表示)
						// 0-"Off"关闭;1-"Open"WEP开放型;2-"WEP64Bits" WEP共享密钥型;
						// 3-"WEP128Bits"WEP共享密钥型;5-"WPA_PSK_TKIP";6-"WPA_PSK_AES";
						// 7-"WPA2_PSK_TKIP";8-"WPA2_PSK_AES"
	int	channel;			//通道号
	int	rssi;				//信号强度	
	int	reserve[32];
}EZ_SDK_AP_ONE;		

typedef struct EZ_SDK_AP_INFO
{	
	int		numDevice;
	EZ_SDK_AP_ONE device[EZ_SDK_WLAN_AP_NUM];
}EZ_SDK_AP_INFO;

typedef struct EZ_SDK_3G_INFO	// 3G网络信号强度
{
	int 	status;						//拨号状态(只读)
	EZ_SDK_IPADDR	addr;			//拨号后获得的IP地址	
	//各种网络信号的强度	
	int	rssi_TD_SCDMA;	
	int	rssi_WCDMA;		
	int	rssi_CDMA1x;	
	int	rssi_EDGE;		
	int	rssi_EVDO;		
	int	reserve[32];		
}EZ_SDK_3G_INFO;

typedef struct EZ_SDK_DIGITAL_CH_STATUS
{
	char chname[EZ_SDK_NAME_LENGTH];
	char maxResName[EZ_SDK_NAME_LENGTH];
	char	curResName[EZ_SDK_NAME_LENGTH];
	char status[EZ_SDK_NAME_LENGTH];
}EZ_SDK_DIGITAL_CH_STATUS;

typedef struct EZ_SDK_DIGITAL_CH_INFO	//数字通道状态
{
	EZ_SDK_DIGITAL_CH_STATUS channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_DIGITAL_CH_INFO;

typedef struct EZ_SDK_NAT_INFO	//NAT 状态信息
{
	int	status;	// 0: 1: 2:
	char	infoCode[EZ_SDK_NAME_LENGTH];
}EZ_SDK_NAT_INFO;

typedef struct EZ_SDK_DDNS_INFO
{
	int	status[EZ_SDK_DDNS_NUM];	//是否在线(注册状态，只读)
	int 	reserve[8];		
}EZ_SDK_DDNS_INFO;

typedef struct EZ_SDK_PPPOE_INFO
{
	int 	status;						//拨号状态(只读)
	EZ_SDK_IPADDR	addr;			//拨号后获得的IP地址(只读)
	int 	reserve[8];
} EZ_SDK_PPPOE_INFO;

typedef struct EZ_SDK_WLAN_INFO
{
	int	linkStatus;					//是否连接上AP(只读)
	int 	reserve[8];
} EZ_SDK_WLAN_INFO;

typedef struct EZ_SDK_UPNP_INFO
{
	int	mapState;					//状态, 1: OK 0: NOT;
	int	mappedPort[EZ_SDK_UPNP_PORT_NUM];	//映射后的端口
	int 	reserve[8];
} EZ_SDK_UPNP_INFO;

// 日志查询条件
typedef	enum EZ_SDK_LOG_TYPE
{
	LOG_ALL = 0,
	LOG_SYSTEM,
	LOG_CONFIG,
	_LOG_EVENT,
	LOG_LOGIN,
	LOG_MANAGE,
	LOG_TYPE_NR,
}EZ_SDK_LOG_TYPE;

typedef struct EZ_SDK_LOG_CONDITION
{
	int		typeMask;	//日志类型 掩码,EZ_SDK_LOG_TYPE
	int		startIndex;	//从上次查询的结束时的日志指针
	EZ_SDK_SYSTEM_TIME beginTime;	//开始时间
	EZ_SDK_SYSTEM_TIME endTime;	//结束时间
	int	reserve[8];		
}EZ_SDK_LOG_CONDITION;

typedef struct EZ_SDK_LOG_ITEM
{
	int 	index;			//用来在多次查询的时候指定起始位置
	char type[32];			//日志类型	
	char user[32];			//日志用户	
	char data[128];		//日志数据	
	EZ_SDK_SYSTEM_TIME	time;	//日志时间
	int	reserve[8];	
}EZ_SDK_LOG_ITEM;

typedef struct EZ_SDK_LOG_INFO
{
	int 	numLog;
	EZ_SDK_LOG_ITEM log[EZ_SDK_RETURN_LOG_NUM];
}EZ_SDK_LOG_INFO;

//录像查询条件
typedef	enum EZ_SDK_RECORD_TYPE
{
	_RECORD_ALL = 0,
	_RECORD_TIME,		//普通录像
	RECORD_MOTION,	//视频侦测录像
	RECORD_IVS,		//智能分析录像	
	_RECORD_ALARM,		//外部报警录像
	RECORD_MANUAL,	//手动录像
	SNAP_ALL = 16,		
	SNAP_TIME,			//抓图
	SNAP_MOTION,	
	SNAP_IVS,			
	SNAP_ALARM,		
	SNAP_MANUAL,	
	EZ_RECORD_TYPE_NR,
}EZ_SDK_RECORD_TYPE;

typedef struct EZ_SDK_RECORD_CONDITION
{
	long long channelMask;			//通道号 掩码(0-64通道)
	long	typeMask;				//录像类型掩码,EZ_SDK_RECORD_TYPE
	EZ_SDK_SYSTEM_TIME beginTime;	//开始时间
	EZ_SDK_SYSTEM_TIME endTime;	//结束时间
	int	reserve[8];					//
}EZ_SDK_RECORD_CONDITION;

typedef struct EZ_SDK_RECORD_FILE
{
	char filename[EZ_SDK_NAME_LENGTH];
	int 	channel;						//通道号
	int 	length;						//文件大小单位byte
	EZ_SDK_SYSTEM_TIME beginTime;	//文件开始时间
	EZ_SDK_SYSTEM_TIME endTime;	//文件结束时间
}EZ_SDK_RECORD_FILE;

//每个通道的录像信息
typedef struct EZ_SDK_RECORD_TIME_INFO
{
	int iChannel;						//录像通道号
	unsigned char cRecordBitMap[720];	//录像记录用720个字节的5760位来表示一天中的1440分钟
									//< 0000:无录像 0001:F_COMMON 0002:F_ALERT 0003:F_DYNAMIC 0004:F_CARD 0005:F_HAND
}EZ_SDK_RECORD_TIME_INFO;

typedef struct EZ_SDK_RECORD_TIME
{
	int nInfoNum;					//< 通道的录像记录信息个数
	EZ_SDK_RECORD_TIME_INFO info[EZ_SDK_CHANNEL_NUM];   //< 通道的录像记录信息
}EZ_SDK_RECORD_TIME;

//=======================操作接口相关==================
typedef	enum EZ_SDK_PROC_TYPE
{
	REBOOT_DEV = 0,		//设备重启
	RESET_CONFIG,		//重置配置
	CLEAR_LOG,			//清除日志
	SET_TIME,			//设置时间
	PROC_TYPE_NR,
}EZ_SDK_PROC_TYPE;

typedef struct EZ_SDK_PROC_REBOOT_DEV
{
	int	reserve[8];	
}EZ_SDK_PROC_REBOOT_DEV;

typedef struct EZ_SDK_PROC_RESET_CONFIG
{
	int	generalConfig;	//0: 1:恢复此类配置
	int	encodeConfig;
	int	recordConfig;	
	int	netCommConfig;	
	int	netAppConfig;	
	int	alarmConfig;
	int	comptzConfig;	//云台串口
	int	storageConfig;	//
	int	avioConfig;		//网络摄像头配置
	int	userConfig;		//用户管理
	int	previewConfig;	// 预览配置
	int	reserve[8];		
}EZ_SDK_PROC_RESET_CONFIG;

typedef struct EZ_SDK_PROC_CLEAR_LOG
{
	int	reserve[8];	
}EZ_SDK_PROC_CLEAR_LOG;

typedef struct EZ_SDK_PROC_SET_TIME
{
	EZ_SDK_SYSTEM_TIME time;
	int	reserve[8];
}EZ_SDK_PROC_SET_TIME;

//======================存储操作接口====================
typedef enum EZ_SDK_STORAGE_OP_CODE
{
	SET_TYPE,			//设置类型(工作类型)
	RECOVER,			//恢复错误
	SET_PARTION,		//创建分区
	CLR_PARTION,		//删除分区
	FORMAT_DISK,		//格式化
	FORMAT_PARTION,	//格式化	分区
	STORAGE_MANAGE_CODE_NR,
}EZ_SDK_STORAGE_OP_CODE;

typedef struct EZ_SDK_STORAGE_MANAGE
{
	EZ_SDK_STORAGE_OP_CODE code;	//操作码
	union 
	{
		struct 
		{
			EZ_SDK_WORKDIR_TYPE	dirType;
		}setType;
		struct 
		{
			int 	serialNo;		//磁盘序列号
			int 	partNo;		//分区号
			int 	partSize;		//分区的大小
		}partion;	//SET_PARTION/CLR_PARTION/FORMAT_PARTION,
		struct 
		{
			int 	serialNo;		//磁盘序列号
		}disk;	
	}content;
	int	reserve[8];
}EZ_SDK_STORAGE_MANAGE;

//=======================用户管理接口====================
typedef struct EZ_SDK_USER_INFO
{
	char		username[EZ_SDK_NAME_LENGTH];
	char		password[EZ_SDK_NAME_LENGTH];
	char		groupname[EZ_SDK_NAME_LENGTH];
	char		memo[EZ_SDK_NAME_LENGTH];
	int		rightNum;	
	char		rights[EZ_SDK_RIGHT_TYPE_NUM][EZ_SDK_NAME_LENGTH];	//该用户的权限
	int		reserved;		//是否保留(不可被删除)
	int		shareable;		//本用户是否允许复用1-复用，0-不复用
	int		reserve[8];
}EZ_SDK_USER_INFO;

typedef struct EZ_SDK_GROUP_INFO
{
	char		groupname[EZ_SDK_NAME_LENGTH];
	char		memo[EZ_SDK_NAME_LENGTH]; 
	int		rigthNum;
	char		rights[EZ_SDK_RIGHT_TYPE_NUM][EZ_SDK_NAME_LENGTH];	//该组的权限
	int		reserve[8];
}EZ_SDK_GROUP_INFO;

typedef struct EZ_SDK_ALL_RIGHT_LIST
{
	int		rightNum;	//所有的权限种类
	char		rightList[EZ_SDK_RIGHT_TYPE_NUM][EZ_SDK_NAME_LENGTH];
}EZ_SDK_ALL_RIGHT_LIST;	

typedef struct EZ_SDK_ALL_USER_LIST
{
	int		userNum;	
	EZ_SDK_USER_INFO	userList[EZ_SDK_MAX_USER_NUM];
}EZ_SDK_ALL_USER_LIST;

typedef struct EZ_SDK_ALL_GROUP_LIST
{
	int		groupNum;	
	EZ_SDK_GROUP_INFO	groupList[EZ_SDK_MAX_GROUP_NUM];
}EZ_SDK_ALL_GROUP_LIST;	

typedef struct EZ_SDK_MODIFY_USER
{
	char 		username[EZ_SDK_NAME_LENGTH];	//要修改的用户名
	EZ_SDK_USER_INFO	user;
}EZ_SDK_MODIFY_USER;

typedef struct EZ_SDK_MODIFY_GROUP	
{
	char 		groupname[EZ_SDK_NAME_LENGTH];//要修改的组名
	EZ_SDK_GROUP_INFO	group;
}EZ_SDK_MODIFY_GROUP;

typedef struct EZ_SDK_MODIFY_PSW
{
	char username[EZ_SDK_NAME_LENGTH];
	char password[EZ_SDK_NAME_LENGTH];
	char newPassword[EZ_SDK_NAME_LENGTH];
}EZ_SDK_MODIFY_PSW;

typedef enum EZ_SDK_USER_OP_CODE
{
	GET_RIGHTLIST = 0,	//获取支持的权限列表
	GET_USERS,
	GET_GROUPS,
	ADD_GROUP,
	MODIFY_GROUP,
	DELETE_GROUP,
	ADD_USER,
	MODIFY_USER,
	DELETE_USER,
	MODIFY_PASSWORD,
	USER_MANAGE_CODE_NR,
}EZ_SDK_USER_OP_CODE;

typedef struct EZ_SDK_USER_MANAGE
{
	EZ_SDK_USER_OP_CODE		 code;	
	union 
	{
		EZ_SDK_GROUP_INFO		addGroup;	
		EZ_SDK_MODIFY_GROUP	modifyGroup;	
		EZ_SDK_GROUP_INFO		deleteGroup;	
		EZ_SDK_USER_INFO		addUser;		
		EZ_SDK_MODIFY_USER	modifyUser;	
		EZ_SDK_USER_INFO		deleteUser;	
		EZ_SDK_MODIFY_PSW		modifyPassword;	
	}content;
	int	reserve[8];
}EZ_SDK_USER_MANAGE;	

//=========================云台控制接口==================
typedef enum EZ_SDK_PTZ_OP_CODE
{
	PTZ_OP_UP = 0,			//上
	PTZ_OP_DOWN,			//下
	PTZ_OP_LEFT,			//左
	PTZ_OP_RIGHT,			//右
	PTZ_OP_LEFTUP,			//左上
	PTZ_OP_LEFTDOWN,		//左下
	PTZ_OP_RIGTHTOP,		//右上
	PTZ_OP_RIGTHDOWN,		//右下
	PTZ_OP_ZOOM_IN,		//变倍大
	PTZ_OP_ZOOM_OUT,		//变倍小
	PTZ_OP_FOCUS_FAR,		//焦点后调
	PTZ_OP_FOCUS_NEAR,	//焦点前调
	PTZ_OP_IRIS_OPEN,		//光圈扩大
	PTZ_OP_IRIS_CLOSE,		//光圈缩小	
	
	PTZ_OP_LAMP_ON,		//灯光开
	PTZ_OP_LAMP_OFF,		//灯光关
	
	PTZ_OP_SET_PRESET,		//设置预置点
	PTZ_OP_CLEAR_PRESET,	//清除预置点
	PTZ_OP_GOTO_PRESET,	//转预置点

	PTZ_OP_AUTOPAN_ON,	//开始自动水平旋转	
	PTZ_OP_AUTOPAN_OFF,	//关闭自动水平旋转	
	PTZ_OP_SET_LEFTLIMIT,	//设置左边界
	PTZ_OP_SET_RIGHTLIMIT,//设置右边界
	
	PTZ_OP_AUTOSCAN_ON,	//自动扫描开始
	PTZ_OP_AUTOSCAN_OFF,	//自动扫描开停止

	PTZ_OP_ADD_TOUR,		//巡航配置(并在巡航线路中添加预设点!!!)
	PTZ_OP_DELFROM_TOUR,	//在巡航线路中删除预设点!
	PTZ_OP_DEL_TOUR,		//清除巡航p1巡航线路
	PTZ_OP_START_TOUR,	//开始巡航	
	PTZ_OP_STOP_TOUR,		//停止巡航	
	
	PTZ_OP_GOTO_POSITION,	//快速定位	

	PTZ_OP_AUXON,			//辅助开关,  关闭在子命令中
	PTZ_OP_MENU,			//球机菜单操作，其中包括开，关，确定等等
	PTZ_OP_FLIP,			//镜头翻转
	PTZ_OP_RESET,			//< 云台复位
	PTZ_OP_NR,
}EZ_SDK_PTZ_OP_CODE;

typedef enum EZ_SDK_PTZ_MENU_OP_CODE
{
	PTZ_MENU_OP_ENTER,
	PTZ_MENU_OP_LEAVE,
	PTZ_MENU_OP_OK,
	PTZ_MENU_OP_CANCEL,
	PTZ_MENU_OP_UP,
	PTZ_MENU_OP_DOWN,
	PTZ_MENU_OP_LEFT,
	PTZ_MENU_OP_RIGHT,
	PTZ_MENU_OP_NR,
}EZ_SDK_PTZ_MENU_OP_CODE;

//======================实时监视接口相关===================
typedef struct EZ_SDK_REALPLAY_REQ
{
	int 	channel;			//通道号
	EZ_SDK_STREAM_TYPE stream;	
	int	reserve[32];		
}EZ_SDK_REALPLAY_REQ;

//======================回放下载接口相关===================
typedef struct EZ_SDK_PLAYBACK_REQ_BY_FILE
{
	int 	channel;			//通道号，因为回放连接以通道作为区分
	char filename[EZ_SDK_NAME_LENGTH];	//文件名
	EZ_SDK_SYSTEM_TIME beginTime;		//开始时间
	EZ_SDK_SYSTEM_TIME endTime;			//结束时间
	int	reserve[32];
}EZ_SDK_PLAYBACK_REQ_BY_FILE;

typedef struct EZ_SDK_PLAYBACK_REQ_BY_TIME
{
	int 	channel;					//通道号
	int 	fileType;					//参见EZ_SDK_RECORD_TYPE
	EZ_SDK_SYSTEM_TIME beginTime;	//开始时间
	EZ_SDK_SYSTEM_TIME endTime;	//结束时间
	int	reserve[32];
}EZ_SDK_PLAYBACK_REQ_BY_TIME;

typedef enum EZ_SDK_PACKET_TYPE
{
	FILE_DATA =	0,		//文件数据
	_VIDEO_I_FRAME,		//视频I 帧
	_VIDEO_B_FRAME,		//视频B 帧
	_VIDEO_P_FRAME,		//视频P 帧
	_VIDEO_J_FRAME,		//图片帧
	AUDIO_DATA,		//音频帧
	TRANSCOM_DATA,	//串口数据
	PACKET_TYPE_NR,	//
}EZ_SDK_PACKET_TYPE;

typedef struct EZ_SDK_PACKET_INFO
{
	EZ_SDK_PACKET_TYPE	packetType;	
	EZ_SDK_SYSTEM_TIME	time;	//绝对时间
	uint64	timestamp;			//相对时标ms
	long		frameSeq;			//帧序号
	long		frameRate;			//帧率
	int		width;				//图像宽度
	int		height;				//图像高度
	int		reserve[32];			//
} EZ_SDK_PACKET_INFO;

//回放控制
typedef enum EZ_SDK_PLAYBACK_OP
{
	PLAY_BACK_PAUSE,			//暂停回放
	PLAY_BACK_CONTINUE,		//继续回放
	PLAY_BACK_FAST,			//加速回放
	PLAY_BACK_SLOW,			//减速回放
	PLAY_BACK_SEEK,			//回放定位，时间s为单位 
	PLAY_BACK_SEEK_PERCENT,	//回放定位,百分比 
	PLAY_BACK_OP_NR,
}EZ_SDK_PLAYBACK_OP;	

//设备搜索的返回值
typedef	struct NetInterface 
{
	char 	hostIP[32];
	char subMask[32];
	char 	gateway[32];
	char 	mac[32];
}NetInterface;

typedef struct EZ_SDK_SEARCH_DEVICE
{
	//设备基本信息
	char	serialNo[EZ_SDK_SERIAL_NUMBER];	//设备序列号
	EZ_SDK_DEV_TYPE devType;			//设备类型		
	char productName[64];					//产品名字
	char 	hostname[EZ_SDK_NAME_LENGTH];	//主机名字
	//网卡信息
	NetInterface interfaces[EZ_SDK_NET_INTERFACE_NUM];
	//服务端口信息
	int		tcpPort;	
	int		udpPort;	
	int		httpPort;	
	int		reserve[32];	
}EZ_SDK_SEARCH_DEVICE;

//======================配置接口相关===================
typedef enum EZ_SDK_CONFIG_TYPE
{	
	//GENERAL	
	CONFIG_GENERAL,
	CONFIG_AUTOMAINTAIN,

	//STROAGE	
	CONFIG_STORAGE_GROBAL,
	CONFIG_STORAGE_NOTEXIT,
	CONFIG_STORAGE_FAILURE,
	CONFIG_STORAGE_LOWSPACE,

	//AVIO
	CONFIG_VIDEO_COLOR,
	CONFIG_VIDEO_IN,
	CONFIG_VIDEO_OUT,

	//RECORD
	_CONFIG_RECORD,
	CONFIG_SNAP,

	//ENCODE
	CONFIG_ENCODE,
	CONFIG_VIDEO_WIDGET,
	CONFIG_CHANNELNAME,
	CONFIG_TALKBACK,

	//ALARM
	CONFIG_MOTION_DETECT,
	CONFIG_BLIND_DETECT,
	CONFIG_LOSS_DETECT,
	CONFIG_ALARM_IN,
	CONFIG_ALARM_OUT,

	//NET
	CONFIG_NETWORK,
	CONFIG_DHCP,
	CONFIG_DNS,
	CONFIG_NETABORT,
	CONFIG_IPCONFLICT,
	CONFIG_ACCESSFILTER,
	CONFIG_DDNS,
	CONFIG_NTP,
	
	CONFIG_EMAIL,
	CONFIG_PPPOE,
	EZ_CONFIG_WLAN,
	CONFIG_3G,
	CONFIG_SMS,
	CONFIG_MMS,

	CONFIG_NETIP_COMMON,		//通用的配置
	CONFIG_NETIP_XM,			//雄迈协议
	CONFIG_NETIP_DH,			//大华协议
	CONFIG_NETIP_ONVIF,		//ONVIF  协议

	//COM
	CONFIG_COM,
	CONFIG_PTZ,

	//
	CONFIG_UPNP,
	CONFIG_RTSP,
	CONFIG_FTP_SERVER,			//
	CONFIG_ARSP_SERVER,		//
	CONFIG_ALARMCENTER,		//
	CONFIG_DAS,

	CONFIG_CH_MODE,		//HVR  通道模式配置
	CONFIG_DIGITAL_CH,		//HVR  数字通道的配置

	CONFIG_PEA_RULES,			//PEA 检测规则
	CONFIG_IVS_DETECT,			//IVS 报警配置
	
	CONFIG_WATERMARK,		//水印设置
	CONFIG_ENCODE_STATICPARAM,	//编码器静态参数

	CONFIG_TYPE_NR,
}EZ_SDK_CONFIG_TYPE;

typedef struct EZ_SDK_CONFIG_GENERAL
{
	int 	localNo;				//< 本机编号
	char nameMachine[EZ_SDK_NAME_LENGTH];	//< 机器名称或编号	
	char dateFormat[32];		//日期格式"yyyy-MM-dd HH:mm:ss",
							//yy = 年，不带世纪 
							//yyyy = 年，带世纪
							//M = 非0 起始月 
							//MM = 0 起始月 
							//MMMM = 月名称
							//d = 非0起始日 
							//dd = 0起始日
							//H = 非0起始24小时
							//HH = 0起始24小时 
							//h = 非0起始12小时 
							//hh = 0起始12小时
	int 	standard;			//参考EZ_SDK_VIDEO_STANDARD
	int 	language;			//参见EZ_SDK_LANAGUAGE
	int 	timeFormat;			//时间格式:	'12',	'24'
	int 	workDay;			//工作日
	int 	dstRule;				//夏令时规则 
	EZ_SDK_SYSTEM_TIME	 dstStart;	//夏令时的开始时间
	EZ_SDK_SYSTEM_TIME	 dstEnd;		//夏令时的结束时间
	int 	reserve[32];			
}EZ_SDK_CONFIG_GENERAL;

typedef struct EZ_SDK_CONFIG_AUTOMAINTAIN
{
	int 		autoRebootDay;		//-1表示永不，0~6表示星期日~星期六，7表示每天
	int 		autoRebootHour;		//0-23
	int 		autoRebootMinute;	//0~59
	int 		reserve[29];			
}EZ_SDK_CONFIG_AUTOMAINTAIN;


typedef struct EZ_SDK_CONFIG_STORAGE_GROBAL
{
	int 		holdDays;			//设置文件的保留天数，超过时间的将被删除，0表示永不过期
	int 		enableLog;			//是否记录录像查询等日志
	int 		overWrite;			//是否运行循环覆盖
	int 		reserve[29];			//
}EZ_SDK_CONFIG_STORAGE_GROBAL;

typedef enum EZ_SDK_PTZ_LINK_TYPE
{
	_NONE = 0,
	PRESET,		//预置点
	TOUR,		//巡航
	_PATTERN,	//巡迹
}EZ_SDK_PTZ_LINK_TYPE;

typedef struct EZ_SDK_PTZ_LINK
{
	EZ_SDK_PTZ_LINK_TYPE type;	//联动的类型 
	int		value;				//联动的类型对应的值 
}EZ_SDK_PTZ_LINK;	

typedef struct EZ_SDK_CONFIG_EVENT_HANDLER
{
	EZ_SDK_CONFIG_WORKSHEET	schedule;	//时间配置表
	
	int		enableRecord;	//录像使能	
	int 		maskRecord;		//录像通道掩码	
	int 		latchRecord;		//录像延时时间（秒）	10~300

	int 		enableAlarmOut;	//报警输出使能	
	int 		maskAlarmOut;	//报警输出通道掩码	
	int		latchAlarmOut;	//报警输出延时时间（秒）10~300

	int 		enableSnapshot;	//快照使能
	int 		maskSnapshot;	//快照通道号掩码
	int 		periodSnapshot;	//帧间隔，每隔多少帧抓一张图片，
	int 		timesSnapshot;	//连拍次数	

	int		enableTour;		// 轮巡使能 
	int		maskTour;		// 轮巡掩码 
	
	int		enableMatrix;		// 矩阵使能 
	int		maskMatrix;		// 矩阵掩码 
	
	int		enabelPtzLink;	//云台联动使能	
	EZ_SDK_PTZ_LINK PtzLink[EZ_SDK_CHANNEL_NUM];

	int		enableEmail;		//发送邮件，如果有图片，作为附件
	int		enableMessage;	//上传到报警服务器
	int 		enableBeep;		//蜂鸣
	int		enableVoice;		//语音提示
	int		enableTip;		//屏幕提示
	int		enableFTP;		//启动FTP传输 
	int		enableMsgtoNet;	// 消息上传给网络使能 

	int		dejitter;			//信号去抖动时间，单位为秒
	int		enableLog;		//是否记录日志
	int 		delay;			//设置时先延时再生效

	int		enableSMS;          	//发送短信
	int 		enableMMS;		//发送彩信

	int		enableShowInfo;	//是否在GUI上和编码里显示报警信息
	int		maskShowInfo;	//要联动显示报警信息的通道掩码
	char 		pAlarmInfo[EZ_SDK_NAME_LENGTH];//要显示的报警信息

	int		reserve[32];		
} EVENT_HANDLER;

typedef struct EZ_SDK_CONFIG_STORAGE_NOTEXIT
{
	int 				enable;
	EVENT_HANDLER 	eventHandler;
}EZ_SDK_CONFIG_STORAGE_NOTEXIT;

typedef struct EZ_SDK_CONFIG_STORAGE_FAILURE
{
	int 				enable;
	EVENT_HANDLER 	eventHandler;
}EZ_SDK_CONFIG_STORAGE_FAILURE;

typedef struct EZ_SDK_CONFIG_STORAGE_LOWSPACE
{
	int 				enable;
	int 				lowerLimit;		//硬盘剩余容量下限, 百分数
	EVENT_HANDLER 	eventHandler;
}EZ_SDK_CONFIG_STORAGE_LOWSPACE;

typedef struct  EZ_SDK_CONFIG_COLOR_PARAM
{	
	int 		enable;				//使能
	int 		brightness;			//亮度		0-100		
	int 		contrast;				//对比度	0-100	
	int 		saturation;			//饱和度	0-100	
	int 		hue;					//色度		0-100	
	//
	int 		acutance;          		//锐度 0-15			 
	int		gain;				//增益	0-100 , 第７位置1表示自动增益	
	int		whitebalance;		//自动白电平控制，bit7置位表示开启自动控制.0x0,0x1,0x2分别代表低,中,高等级

	EZ_SDK_TIMESECTION section;	//对应的时间段	
	int 		reserve[3];
}EZ_SDK_CONFIG_COLOR_PARAM;

typedef struct  EZ_SDK_CONFIG_VIDEO_COLOR
{
	EZ_SDK_CONFIG_COLOR_PARAM Color[EZ_SDK_MIN_TSECT_NUM];
}EZ_SDK_CONFIG_VIDEO_COLOR;

typedef struct  EZ_SDK_CONFIG_VIDEO_COLOR_ALL
{
	EZ_SDK_CONFIG_VIDEO_COLOR channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_VIDEO_COLOR_ALL;

typedef struct EZ_SDK_CONFIG_VIDEO_OUT
{
	int	leftMargin;		//TV左边距：0～100 
	int	topMargin;		//TV上边距：0～100 
	int	rightMargin;		//TV右边距：0～100 
	int	bottomMargin;	//TV下边距：0～100 
	int	brightness;		//亮度	：0～100 
	int	contrast;			//对比度：0～100 
	int	satuation;		//色彩饱和度	0~100
	int	hue;				//色调	0~100
	int	width;			//水平分辨率
	int	height;			//垂直分辨率	
	int	bpp;			//颜色深度	
  	int	signalFormat;		//输出信号模式	"Auto","TV","VGA","DVI","HDMI","SDI"
	int	refreshRate;		//刷新频率	
	int	screenPtctEn;		//屏保使能标志 
	int	screenPtctTime;	//屏保时间 
	int	reserve[3];		//保留 
}EZ_SDK_CONFIG_VIDEO_OUT;

typedef struct  EZ_SDK_CONFIG_VIDEO_OUT_ALL
{
	EZ_SDK_CONFIG_VIDEO_OUT channel[EZ_SDK_VIDEOOUT_NUM];
}EZ_SDK_CONFIG_VIDEO_OUT_ALL;

typedef struct  EZ_SDK_CONFIG_SECTOPTION 
{
	EZ_SDK_TIMESECTION section;	//对应的时间段
	int	exposureSensitive;		//曝光灵敏度等级	【1-6】
	int	exposureSpeed;			//取值范围取决于设备能力集：0-自动曝光 1~n-1-手动曝光等级
								//n-带时间上下限的自动曝光 n+1-自定义时间手动曝光 (n表示支持的曝光等级数）
	int	exposureValue1;
	int	exposureValue2;
	int	referenceLevel;			//
	int	whiteBalance;			//白平衡 0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night... -1:custom
	int	gainRed;			
	int	gainGreen;		
	int	gainBlue;		
	int	reserve[16];				//保留 
}EZ_SDK_CONFIG_SECTOPTION;

typedef struct EZ_SDK_CONFIG_VIDEO_IN
{
	int	backlight;	// 背光补偿等级	取值范围取决于设备能力集：
					// 0-关闭
					// 1-背光补偿强度1
					// 2-背光补偿强度2
					// n-最大背光补偿等级数
	int	colorSwitch;	//根据日夜自动切换颜色;0-总是彩色1-根据亮度自动切换2-总是黑白
	int 	mirror;		//是否开启画面镜像功能	
	int	flip;			//是否开启画面翻转功能	
	int	rejectFlicker;	//是否开启日光灯防闪功能				
	int	esShutter;	//是否电子慢快门功能	

	int 	apertureMode;//自动光圈模式
	int 	ircut_mode;	//IR-CUT切换 0 = 红外灯同步切换 1 = 自动切换

	//参数选项
	int	switchMode;	//0-不切换；1-根据亮度切换；2-根据时间切换
	int	brightnessThreshold;	//亮度阈值，小于该亮度时需要切换到夜晚的参数(在第一个和第二个时间段之间切换)
	EZ_SDK_CONFIG_SECTOPTION options[EZ_SDK_MIN_TSECT_NUM];
	
	int	reserve[32];		//保留 
}EZ_SDK_CONFIG_VIDEO_IN;

typedef struct  EZ_SDK_CONFIG_VIDEO_IN_ALL
{
	EZ_SDK_CONFIG_VIDEO_IN channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_VIDEO_IN_ALL;

typedef struct EZ_SDK_CONFIG_RECORD
{	
	int 		mode;				//0-自动录像，1-手动录像，2-关闭录像
	int 		preRecord;			//预录时间，为零时表示关闭 
	int 		streamType;    		//录像码流 0-主码流 1-辅码流1 2-辅码流2 3-辅码流3
	int 		packetLength;		//录像打包长度（分钟）[1, 255]
	int 		redundancy;			//冗余开关
	EZ_SDK_CONFIG_WORKSHEET	schedule;	
	int		reserve[16];			
}EZ_SDK_CONFIG_RECORD;

typedef struct  EZ_SDK_CONFIG_RECORD_ALL
{
	EZ_SDK_CONFIG_RECORD channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_RECORD_ALL;

typedef struct EZ_SDK_CONFIG_SNAP
{
	EZ_SDK_CONFIG_WORKSHEET	schedule;
	int 		mode;				//0-自动抓图，1-手动抓图，2-关闭抓图
	int 		preSnap;				//预抓时间
	int 		streamType;    		//录像码流 0-主码流 1-辅码流1 2-辅码流2 3-辅码流3
	int		reserve[16];			
}EZ_SDK_CONFIG_SNAP_SCHEDULE;

typedef struct  EZ_SDK_CONFIG_SNAP_ALL
{
	EZ_SDK_CONFIG_SNAP_SCHEDULE channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_SNAP_ALL;

//编码配置的类型
typedef enum EZ_SDK_ENCODE_TYPE
{
	ENCODE_TIM = 0,
	ENCODE_MTD = 1,
	ENCODE_ALM = 2,
	ENCODE_TYPE_NR = 3,
}EZ_SDK_ENCODE_TYPE;

typedef struct EZ_SDK_VIDEO_OPTION
{
	int		enable;			//
	int		compression;		//压缩类型
	int		width;			//宽
	int		height;			//高
	int 		ctrlMode;		//码率控制模式						
	int		bitrate;			//码率bps
	int		quality;			//画质
	int		fps;				//帧率
	int 		gop;			//I  帧间隔,单位为帧数
	int 		reserve[8];	
}EZ_SDK_VIDEO_OPTION;

typedef struct EZ_SDK_AUDIO_OPTION
{
	uchar	enable;	
	uchar	compression;		//压缩类型
	int		frequency;		//音频采样频率	
	int		depth;			//采样深度
	int		packetPeriod;		//打包周期ms
	int 		mode;			//编码模式(AMR 时有用)
	int 		reserve[8];	
}EZ_SDK_AUDIO_OPTION;

typedef struct EZ_SDK_ENCODE_OPTION
{
	EZ_SDK_VIDEO_OPTION video;
	EZ_SDK_AUDIO_OPTION audio;
}EZ_SDK_ENCODE_OPTION;

typedef struct EZ_SDK_CONFIG_ENCODE
{
	EZ_SDK_ENCODE_OPTION	mainStream[ENCODE_TYPE_NR];
	EZ_SDK_ENCODE_OPTION	extraStream[EZ_SDK_EXTRA_STREAM_NUM];	//最大支持的辅码流数，
																	//具体由能力集获得!!!
	EZ_SDK_ENCODE_OPTION	snapStream;
}EZ_SDK_CONFIG_ENCODE;

typedef struct  EZ_SDK_CONFIG_ENCODE_ALL
{
	EZ_SDK_CONFIG_ENCODE channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_ENCODE_ALL;

typedef struct  EZ_SDK_CONFIG_WIDGET_ATTR
{
	int 		enable;		//使能
	ulong	fgRGBA;		//前景色
	ulong	bgRGBA;		//背景色
	EZ_Rect		position;		//以8192 X8192  为参考坐标
	int		mainBlend;	//是否叠加到各路码流的标志位
	int		extraBlend[EZ_SDK_EXTRA_STREAM_NUM];
	int		snapBlend;	
	int 		reserve[8];	
}EZ_SDK_CONFIG_WIDGET_ATTR;

typedef struct  EZ_SDK_CONFIG_WIDGET
{
	EZ_SDK_CONFIG_WIDGET_ATTR	covers[EZ_SDK_COVER_NUM];
	EZ_SDK_CONFIG_WIDGET_ATTR timeTitle;
	EZ_SDK_CONFIG_WIDGET_ATTR channelTitle;	
}EZ_SDK_CONFIG_WIDGET;

typedef struct  EZ_SDK_CONFIG_WIDGET_ALL
{
	EZ_SDK_CONFIG_WIDGET channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_WIDGET_ALL;

typedef struct  EZ_SDK_CONFIG_CHANNEL_NAME
{
	char name[EZ_SDK_CHANNEL_NUM][EZ_SDK_NAME_LENGTH];	
}EZ_SDK_CONFIG_CHANNEL_NAME;	

typedef struct  EZ_SDK_CONFIG_TALKBACK
{
	EZ_SDK_AUDIO_OPTION talkback;	
}EZ_SDK_CONFIG_TALKBACK;

typedef struct  EZ_SDK_CONFIG_MOTION_DETECT
{
	int 	enable;		//使能
	int 	level;		//灵敏度 
	char 	region[EZ_SDK_MD_REGION_ROW][EZ_SDK_MD_REGION_COLUMN];
	EVENT_HANDLER eventHandler;	
}EZ_SDK_CONFIG_MOTION_DETECT;

typedef struct  EZ_SDK_CONFIG_MOTION_DETECT_ALL
{
	EZ_SDK_CONFIG_MOTION_DETECT channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_MOTION_DETECT_ALL;

typedef struct  EZ_SDK_CONFIG_BLIND_DETECT
{
	int 	enable;		//使能					
	int 	level;		//灵敏度 
	EVENT_HANDLER eventHandler;	
}EZ_SDK_CONFIG_BLIND_DETECT;	

typedef struct  EZ_SDK_CONFIG_BLIND_DETECT_ALL
{
	EZ_SDK_CONFIG_BLIND_DETECT channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_BLIND_DETECT_ALL;

typedef struct  EZ_SDK_CONFIG_LOSS_DETECT
{
	int 	enable;		//使能
	int 	level;		//灵敏度 
	EVENT_HANDLER eventHandler;	
}EZ_SDK_CONFIG_LOSS_DETECT;	

typedef struct  EZ_SDK_CONFIG_LOSS_DETECT_ALL
{
	EZ_SDK_CONFIG_LOSS_DETECT channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_LOSS_DETECT_ALL;

typedef struct EZ_SDK_CONFIG_ALARM_IN
{
	int	enable;		//使能
	int	sensorType;	//0:常开1:常闭
	char	name[EZ_SDK_NAME_LENGTH];	
	EVENT_HANDLER eventHandler;
}EZ_SDK_CONFIG_ALARM_IN;

typedef struct  EZ_SDK_CONFIG_ALARM_IN_ALL
{
	EZ_SDK_CONFIG_ALARM_IN channel[EZ_SDK_ALARMIN_NUM];
}EZ_SDK_CONFIG_ALARM_IN_ALL;

typedef struct EZ_SDK_CONFIG_ALARM_OUT
{
	char name[EZ_SDK_NAME_LENGTH];	
	int	mode;		//模式0-自动报警，1-强制报警，2-关闭报警
	int 	reserve[8];	
}EZ_SDK_CONFIG_ALARM_OUT;

typedef struct  EZ_SDK_CONFIG_ALARM_OUT_ALL
{
	EZ_SDK_CONFIG_ALARM_OUT channel[EZ_SDK_ALARMOUT_NUM];
}EZ_SDK_CONFIG_ALARM_OUT_ALL;

//远端服务器结构定义
typedef struct EZ_SDK_REMOTE_SERVER
{
	char serverName[EZ_SDK_NAME_LENGTH];		//服务器域名
	EZ_SDK_IPADDR serverip;					//服务器IP 地址
	int	serverport;							//服务端口
	char	username[EZ_SDK_NAME_LENGTH];		//服务器上的用户名
	char	password[EZ_SDK_NAME_LENGTH];		//服务器上的密码
	int	anonymity;							//是否匿名登录
}EZ_SDK_REMOTE_SERVER;

typedef struct EZ_SDK_CONFIG_NETWORK_INTERFACE
{
	char    	name[16];			//网卡名字
	char 		mac[32];				//Mac 地址
	char 		hostIP[32];			//IP 地址	
    	char 		subMask[32];                //子网掩码
    	char		gateWay[32];			//网关 IP	
	int 		reserve[8];	
}EZ_SDK_CONFIG_NETWORK_INTERFACE;

typedef struct EZ_SDK_CONFIG_NETWORK
{
    	char		hostName[EZ_SDK_NAME_LENGTH];			//主机名
    	char		domain[EZ_SDK_NAME_LENGTH];			//所属域
    	char		defaultInterface[EZ_SDK_NAME_LENGTH];	//默认网卡	
	EZ_SDK_CONFIG_NETWORK_INTERFACE interfaces[EZ_SDK_NET_INTERFACE_NUM];	
}EZ_SDK_CONFIG_NETWORK;	

typedef struct EZ_SDK_CONFIG_DHCP_ONE
{
	char 	name[16];	//网卡名字
	int 	enable;		//dhcp 使能标志位
}EZ_SDK_CONFIG_DHCP_ONE;

typedef struct EZ_SDK_CONFIG_DHCP
{
	EZ_SDK_CONFIG_DHCP_ONE  interfaces[EZ_SDK_NET_INTERFACE_NUM];
}EZ_SDK_CONFIG_DHCP;

typedef struct EZ_SDK_CONFIG_DNS
{
	EZ_SDK_IPADDR	primaryDNS;		//主
	EZ_SDK_IPADDR	secondaryDNS;	//次
}EZ_SDK_CONFIG_DNS;

typedef struct EZ_SDK_CONFIG_NETABORT	//断网检测
{
	int 	enable;
	EVENT_HANDLER eventHandler;
}EZ_SDK_CONFIG_NETABORT;

typedef struct EZ_SDK_CONFIG_IPCONFICT	//IP冲突检测
{
	int 	enable;
	EVENT_HANDLER eventHandler;
}EZ_SDK_CONFIG_IPCONFICT;

typedef struct EZ_SDK_CONFIG_ACCESSFILTER
{
	int		enable;	//
	int		type;	// 0:TrustList 1:BannedList
	EZ_SDK_IPADDR bannedList[EZ_SDK_ACCESSFILTER_NUM];	//黑名单列表
	EZ_SDK_IPADDR trustList[EZ_SDK_ACCESSFILTER_NUM];	//白名单列表
}EZ_SDK_CONFIG_ACCESSFILTER;

typedef struct EZ_SDK_CONFIG_DDNS_ONE
{
	int	enable;							//是否启动0-不启动，1-启动	
	char	protocal[EZ_SDK_NAME_LENGTH];	//协议类型目前支持'JUFENG' ," CN99 ", " Oray ", "NO-IP",
	char	hostname[EZ_SDK_NAME_LENGTH];	//就是申请到的域名
	int	keepAlive;						//保活时间，单位分
	EZ_SDK_REMOTE_SERVER server;		//服务器信息
	int 	reserve[8];						
}EZ_SDK_CONFIG_DDNS_ONE;
typedef struct EZ_SDK_CONFIG_DDNS
{
	EZ_SDK_CONFIG_DDNS_ONE server[EZ_SDK_DDNS_NUM];
}EZ_SDK_CONFIG_DDNS;

typedef struct EZ_SDK_CONFIG_NTP
{
	int	enable;			//是否启用NTP
	int	reflesh;			//更新时间周期，单位分
	int	timeZone;		//时区在-12~13,保存的都为0-25
	EZ_SDK_REMOTE_SERVER server;	//服务器信息	
	int 	reserve[8];
}EZ_SDK_CONFIG_NTP;

typedef struct EZ_SDK_CONFIG_EMAIL
{
	int		enable;
	EZ_SDK_REMOTE_SERVER server;			//服务器信息	
	char 		sender[EZ_SDK_NAME_LENGTH];		//"xxx@xxxx.com"
	char 		receivers[EZ_SDK_EMAIL_RECV_NUM][EZ_SDK_NAME_LENGTH];	//收件人列表
	char		title[EZ_SDK_NAME_LENGTH];		//邮件标题
	int		attachEnable;						//是否添加附件
	int		useSSL;							//是否使用ssl  
	EZ_SDK_TIMESECTION section[2];			//email有效时间
	int 		reserve[8];
}EZ_SDK_CONFIG_EMAIL;	

typedef struct EZ_SDK_CONFIG_PPPOE
{
	int		enable;					//
	char		username[EZ_SDK_NAME_LENGTH];	//用户名
	char		password[EZ_SDK_NAME_LENGTH];	//密码
	int 		reserve[8];
} EZ_SDK_CONFIG_PPPOE;

typedef struct EZ_SDK_CONFIG_WLAN
{
       int    	enable;
	char	 	ssid[EZ_SDK_NAME_LENGTH];	
	int 		channel;		//channel
	int		linkMode;	//网络模式0:auto 1:adhoc 2:Infrastructure
	int  	 	encryption;	//认证+加密类型(联合表示)
						// 0-"Off"关闭;1-"Open"WEP开放型;2-"WEP64Bits" WEP共享密钥型;
						// 3-"WEP128Bits"WEP共享密钥型;5-"WPA_PSK_TKIP";6-"WPA_PSK_AES";
						// 7-"WPA2_PSK_TKIP";8-"WPA2_PSK_AES"
	int		keyType; 	//0:Hex 1:ASCII (只在wep模式下有效)
    	char   	keys[EZ_SDK_WIFI_TOKEN_NUM]; 
	int 		reserve[32];	
}EZ_SDK_CONFIG_WLAN;

typedef struct EZ_SDK_CONFIG_3G
{
       int    	enable;			//使能3g   模块
	int		nettype;			//"Auto", "CDMA1x", "EVDO", "TD-SCDMA", "WCDMA", "EDGE"
	char   	apn[EZ_SDK_NAME_LENGTH];		//接入网络
	char   	dailnumber[EZ_SDK_NAME_LENGTH];//拨号号码	
	char   	username[EZ_SDK_NAME_LENGTH];	//用户名	
	char   	password[EZ_SDK_NAME_LENGTH];	//密码	
	//拨号控制相关配置
	int 		activate;				//拨号	使能标志
	int		timeout;				//检测到该连接一段时间没在使用，修改Activate标志为false并设置配置。
	EZ_SDK_CONFIG_WORKSHEET	schedule;	//拨号时间段
	int		enableSMSActivate;	//使能短信唤醒	
	int		listSMSSender[EZ_SDK_MOBILE_ACT_NUM][16];	
	int		enableDialActivate;	//使能拨号唤醒
	int		listDialSender[EZ_SDK_MOBILE_ACT_NUM][16];
	int 		reserve[32];			
}EZ_SDK_CONFIG_3G;

typedef struct EZ_SDK_CONFIG_SMS
{
	int    	enable;			//是否使能
	char		title[EZ_SDK_TITLE_LENGTH];	//标题，或短信 第一行文字
	char		receivers[EZ_SDK_MMS_RECV_NUM][16];	//信息接受者的电话号码	
	char		minInterval;		//信息发送的最短时间间隔，单位秒

	int  		sendTimes;		//??? 需要向每个手机发送多少次短信
	int 		reserve[32];			
}EZ_SDK_CONFIG_SMS;	

typedef struct EZ_SDK_CONFIG_MMS
{
	int    	enable;			//是否使能
	char		title[EZ_SDK_TITLE_LENGTH];	//标题，或短信 第一行文字	
	char		receivers[EZ_SDK_MMS_RECV_NUM][16];	//信息接受者的电话号码	
	char		minInterval;			//信息发送的最短时间间隔，单位秒
	//??? 下面的配置看起来像是不需要的
	char 		gateWayDomain[40];	//网关地址，域名或IP
	int  		gateWayPort;			//网关端口
	char 		mmscDomain[40];		// 彩信服务器地址，IP或域名
	int		mmscPort;			// 彩信服务器端口号
	int 		reserve[32];			
}EZ_SDK_CONFIG_MMS;	

typedef struct EZ_SDK_CONFIG_NETIP_COMMON
{
	int	httpPort;			//HTTP服务端口
	int 	sslPort;			//SSL 侦听端口
	int 	maxConn;		//最大连接数
	int 	maxBps;			//限定码流值
	int 	transPolicy;		//传输策略
	int	useHSDownLoad;	//是否启用高速录像下载测率
}EZ_SDK_CONFIG_NETIP_COMMON;	

typedef struct EZ_SDK_CONFIG_NETIP_XM
{
	int	tcpPort;			//TCP 服务端口
	int	udpPort;			//UDP 服务端口
	int	keepAlive;		//要求登录客户端的保活时间，单位s	
	int 	reserve[32];		
}EZ_SDK_CONFIG_NETIP_XM;

typedef struct EZ_SDK_CONFIG_NETIP_DH
{
	int	port;			//服务端口,只支持TCP  协议
	int	keepAlive;		//要求登录客户端的保活时间，单位s	
	int 	reserve[32];		
}EZ_SDK_CONFIG_NETIP_DH;

typedef struct EZ_SDK_CONFIG_NETIP_ONVIF
{
	int	port;			//服务端口
	int 	reserve[32];		
}EZ_SDK_CONFIG_NETIP_ONVIF;

typedef struct EZ_SDK_CONFIG_COM_ATTR
{
	int	databit;		//数据位取值为,6,7,8 
	int	stopbit;		//停止位1"1", 2"2" 3:"1.5",
	int	parity;		//校验位：0:None 1:Even 2:Odd 3:Space
	int	baudrate;	//波特率
}EZ_SDK_CONFIG_COM_ATTR;

typedef struct EZ_SDK_CONFIG_COM_ONE
{
	int	function;		//参见EZ_SDK_COM_FUNC
	EZ_SDK_CONFIG_COM_ATTR attr;
}EZ_SDK_CONFIG_COM_ONE;

typedef struct EZ_SDK_CONFIG_COM_ALL
{
	EZ_SDK_CONFIG_COM_ONE com[EZ_SDK_COM_NUM];
}EZ_SDK_CONFIG_COM_ALL;

typedef struct EZ_SDK_CONFIG_PTZ_ONE
{
	int	proto;				//参见EZ_SDK_PTZ_PROTO	
	int	address;				//云台设备地址编号 	
	int	numberInMatrixs;		//在矩阵中的统一编号	
	EZ_SDK_CONFIG_COM_ATTR attr;
}EZ_SDK_CONFIG_PTZ_ONE;

typedef struct EZ_SDK_CONFIG_PTZ_ALL
{
	EZ_SDK_CONFIG_PTZ_ONE ptz[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_PTZ_ALL;

//说明，因为UPNP  需要映射处理http端口之外，还设计到
//各种NetIp  的服务端口，所以没有办法直接枚举。
typedef struct EZ_SDK_CONFIG_UPNP
{
	int	enable;			//使能标志
	int	localPort[EZ_SDK_UPNP_PORT_NUM];		//映射前的端口，
	int 	reserve[32];		//	
}EZ_SDK_CONFIG_UPNP;

typedef struct EZ_SDK_CONFIG_RTSP
{
	int	enable;			//使能标志
	int	port;			//服务端口,只支持TCP  协议
	int 	reserve[32];			
}EZ_SDK_CONFIG_RTSP;

typedef struct EZ_SDK_CONFIG_FTP_SERVER
{
	int	enable;							//使能标志
	EZ_SDK_REMOTE_SERVER server;		//FTP服务器
	char remoteDir[EZ_SDK_PATH_LENGTH];	//远程目录
	int	maxFileLen;						//文件最大长度
	int 	reserve[32];			
}EZ_SDK_CONFIG_FTP_SERVER;

typedef struct EZ_SDK_CONFIG_ARSP_SERVER
{
	int	enable;						//使能标志
	char	keys[EZ_SDK_NAME_LENGTH];	//类型名称
	EZ_SDK_REMOTE_SERVER server;	//ARSP服务器
	int 	interval;						//保活间隔时间		
	char sURL[EZ_SDK_NAME_LENGTH];	//本机域名		
	int 	httpPort;						//服务器HTTP端口	
	int 	reserve[32];			
}EZ_SDK_CONFIG_ARSP_SERVER;	

typedef struct EZ_SDK_CONFIG_ARSP_SERVER_ALL
{
	EZ_SDK_CONFIG_ARSP_SERVER servers[EZ_SDK_ARSP_NUM];
}EZ_SDK_CONFIG_ARSP_SERVER_ALL;

typedef struct EZ_SDK_CONFIG_ALARMCENTER
{
	int	enable;						//使能标志
	char	keys[EZ_SDK_NAME_LENGTH];	//报警中心协议类型名称
	EZ_SDK_REMOTE_SERVER server;	//报警中心服务器
	int	isAlarm;						
	int	isLog;						//是否记日志
}EZ_SDK_CONFIG_ALARMCENTER;

typedef	struct EZ_SDK_CONFIG_ALARMCENTER_ALL
{
	EZ_SDK_CONFIG_ALARMCENTER servers[EZ_SDK_ALARMSERVER_NUM];
}EZ_SDK_CONFIG_ALARMCENTER_ALL;

typedef struct EZ_SDK_CONFIG_DAS
{
	int	enable;						//使能标志
	EZ_SDK_REMOTE_SERVER server;	//DAS 服务器
	char devID[EZ_SDK_NAME_LENGTH];	//
	int 	reserve[32];		
}EZ_SDK_CONFIG_DAS;

typedef struct EZ_SDK_CONFIG_CH_MODE
{
	int	modeIndex;					//能力集中的索引
}EZ_SDK_CONFIG_CH_MODE;

typedef enum EZ_SDK_NETIP_TYPE
{
	XM_PROTOCAL = 0,	//雄迈协议
	DH_PROTOCAL,		//大华协议
	ONVIF_PROTOCAL,	//ONVIF   协议
}EZ_SDK_NETIP_TYPE;

//数字通道的数据源配置
typedef struct EZ_SDK_DIGITAL_SOURCE
{
	int	enable;						//使能标志
	EZ_SDK_REMOTE_SERVER server;	//设备地址信息
	EZ_SDK_NETIP_TYPE	protocol;		//选用的NetIP  协议，见EZ_SDK_NETIP_TYPE	
	int 	channel;						//通道号
	int 	streamType;					//码流类型
	int	interval;						//轮巡的间隔时间(s),0:表示永久
	char	cfgName[EZ_SDK_NAME_LENGTH];	//名称
	EZ_SDK_DEV_TYPE devType;		//设备类型
}EZ_SDK_DIGITAL_SOURCE;	

typedef enum EZ_SDK_DIGITAL_CON_TYPE
{
	EZ_SDK_CON_SINGLE = 0, 		//单数据源
	EZ_SDK_CON_MULTI = 1,			//多数据源轮巡
	EZ_SDK_CON_TYPE_NR,		
}EZ_SDK_DIGITAL_CON_TYPE;

typedef struct EZ_SDK_CONFIG_DIGITAL_CH
{
	int	enable;			//使能标志
	EZ_SDK_DIGITAL_CON_TYPE connType;	//连接类型
	int 	tourInterval;		//多连接时轮巡间隔
	int	singleConnId;	//单连接时的连接配置ID, 从1  开始，0  表示无效
	int	enCheckTime;	//开启对时
	EZ_SDK_DIGITAL_SOURCE	inputs[EZ_SDK_DIGITAL_SOURCE_NUM];
}EZ_SDK_CONFIG_DIGITAL_CH;

typedef struct EZ_SDK_CONFIG_DIGITAL_CH_ALL
{
	EZ_SDK_CONFIG_DIGITAL_CH channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_DIGITAL_CH_ALL;

//===============================================
//智能分析灵敏度级别
enum EZ_SDK_IVS_SENSITIVITY
{
	HIGH_SENSITIVITY,         	//高灵敏度
	MIDDLE_SENSITIVITY,	//中灵敏度
	LOW_SENSITIVITY		//低灵敏度
};

enum EZ_SDK_PEA_MODE
{
	TRIPWIRE = 0,		//单绊线
	PERIMETER    		//周界检测
};

//周界检测模式
typedef enum EZ_SDK_PERIMETER_MODE
{
	MODE_INTRUSION = 0,	//入侵
	MODE_ENTER,			//进入
	MODE_EXIT				//离开
}EZ_SDK_PERIMETER_MODE;

//一条区域规则中只设置一个区域
typedef struct EZ_SDK_PERIMETER_RULE
{
	int 	enable;						//是否使能
	int	mode;						//周界检测模式 见EZ_SDK_PERIMETER_MODE
	int	isTypeLimit;					//是否做目标类型限制 
	int	typeHuman;					//目标类别：人(限定类型时使用) 
	int	typeVehicle;					//目标类别：车 
	int 	minDist;						//最小像素距离 
	int 	minTime;						//最短时间 
	int	isDirectionLimit;				//是否做方向限制 
	int 	forbiddenDirection;			//禁止方向角度(单位: 角度) 
	_Polygon 	boundary;				//周界区域信息
}EZ_SDK_PERIMETER_RULE;

//一条拌线规则内可以设置多条线
typedef struct EZ_SDK_ONE_TRIPWIRE
{
	int	isDoubleDirection;				//表示该绊线是否为双向绊线(0: 否, 1: 是) 
	int 	forbiddenDirection;			//禁止方向角度(单位: 角度) 	
	Line 	line;							//
}EZ_SDK_ONE_TRIPWIRE;

//一条拌线规则内可以设置多条线
typedef struct EZ_SDK_TRIPWIRE_RULE
{
	int 	enable;						//是否使能
	int	isTypeLimit;					//是否做目标类型限制 
	int	typeHuman;					//目标类别：人(限定类型时使用) 
	int	typeVehicle;					//目标类别：车 
	int 	minDist;						//最小像素距离 
	int 	minTime;						//最短时间 
	EZ_SDK_ONE_TRIPWIRE	tripwire[EZ_SDK_TRIPWIRE_IN_RULE];//
}EZ_SDK_TRIPWIRE_RULE;

typedef struct EZ_SDK_CONFIG_PEA_RULES
{
	int	showObj;					//是否显示识别出来的物体
	int	showTrack;					//是否显示轨迹
	int	showRule;					//是否显示规则
	int 	level;						//灵敏度
	EZ_SDK_PERIMETER_RULE	perimeterRules[EZ_SDK_PEA_PERIMETER_NUM];	//
	EZ_SDK_TRIPWIRE_RULE	tripwireRules[EZ_SDK_PEA_TRIPWIRE_NUM];	//
}EZ_SDK_CONFIG_PEA_RULES;

typedef struct  EZ_SDK_CONFIG_IVS_DETECT
{
	int 	enable;						//使能ivs
	EVENT_HANDLER eventHandler;		//
}EZ_SDK_CONFIG_IVS_DETECT;	

// 数字水印配置
typedef struct EZ_SDK_CONFIG_WATERMARK
{
	int	enable;		//开启水印
	char	key[8];
	char	userData[16];
}EZ_SDK_CONFIG_WATERMARK;

typedef struct EZ_SDK_CONFIG_WATERMARK_ALL
{
	EZ_SDK_CONFIG_WATERMARK marks[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_WATERMARK_ALL;

//编码器静态参数
typedef struct EZ_SDK_CONFIG_ENCODE_STATICPARAM
{
	int 	profile;	//
	int 	level;	//
	int 	reserve[8];	
}EZ_SDK_CONFIG_ENCODE_STATICPARAM;

typedef struct EZ_SDK_CONFIG_ENCODE_STATICPARAM_ALL
{
	EZ_SDK_CONFIG_ENCODE_STATICPARAM	params[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_ENCODE_STATICPARAM_ALL;


//回调函数原型
//设备断开连接的回调
typedef int (CALL_METHOD *EZ_SDK_DisconnectCB)(int loginID,char *devIP,int devPort,int userData);
	
//设备报警上传的回调
typedef int (CALL_METHOD *EZ_SDK_AlarmCB)(int loginID, EZ_SDK_ALARM_INFO *alarmInfo,int userData);

//实时监视数据回调
typedef int (CALL_METHOD *EZ_SDK_RealDataCB)(int playHandle,EZ_SDK_PACKET_INFO *info,char *buffer,int size,int userData);

//回放下载进度回调
typedef int (CALL_METHOD *EZ_SDK_ProgressCB)(int playHandle,int totalSize,int downloadSize,int userData);

#endif	//__EZ_SDK_DEF_H__