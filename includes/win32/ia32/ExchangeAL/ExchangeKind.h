//
//  "$Id: ExchangeKind.h 18675 2015-12-15 11:21:51Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  Modifiy:		2008-12-05 liwj create the file
//					配置业务层，完成配置业务相关工作
//

#ifndef __EXCHANGE_AL_EXCHANAGE_KIND_H__
#define __EXCHANGE_AL_EXCHANAGE_KIND_H__

#include "Types/Defs.h"
#include <vector>
#include <string>

/// 配置操作相关错误号
enum ConfigErrorNo
{
	CONFIG_OPT_RESTART = ERROR_BEGIN_CONFIG + 1,		///< 需要重启应用程序
	CONFIG_OPT_REBOOT = ERROR_BEGIN_CONFIG + 2,			///< 需要重启系统
	CONFIG_OPT_FILE_ERROR = ERROR_BEGIN_CONFIG + 3,		///< 写文件出错
	CONFIG_OPT_CAPS_ERROR = ERROR_BEGIN_CONFIG + 4,		///< 特性不支持
	CONFIG_OPT_VALIT_ERROR = ERROR_BEGIN_CONFIG + 5,	///< 验证失败 
	CONFIG_OPT_NOT_EXSIST = ERROR_BEGIN_CONFIG + 8,		///< 配置不存在
	CONFIG_OPT_PARSE_FAILED = ERROR_BEGIN_CONFIG + 6,	///< 配置解析出错
};

/// 默认配置种类
enum DefaultConfigKinds
{
	DEFAULT_CFG_GENERAL,			// 普通配置
	DEFAULT_CFG_ENCODE,				// 编码配置
	DEFAULT_CFG_RECORD,				// 录像配置
	DEFAULT_CFG_NET_SERVICE,		// 网络服务
	DEFAULT_CFG_NET_COMMON,			// 通用网络
	DEFAULT_CFG_ALARM,				// 报警
	DEFAULT_CFG_PTZCOMM,			// 云台，串口
	DEFAULT_CFG_USERMANAGER,		// 用户管理
	DEFAULT_CFG_PREVIEW,			// 预览配置
	DEFAULT_CFG_CAMERA_PARAM,		// 网络摄像头配置
	DEFAULT_CFG_END
};

/// 根据默认配置种类DefaultConfigKinds取得相应的名称
const char *getDefaultKindName(int iDefaultKind);

/// 根据配置名得到枚举常量
int getDefaultKindIndex(const char *iDefaultName);

/// 配置种类
enum ConfigKinds
{
	CFG_ENCODE,			///< 编码配置
	CFG_WIDEOWIDGET,	///< 视频物件
	CFG_VIDEOCOLOR,		///< 视频颜色
	CFG_RECORD,			///< 录像配置
	CFG_MOTIONDETECT,	///< 动检配置
	CFG_BLINDDETECT,	///< 遮挡检测
	CFG_LOSSDETECT,		///< 视频丢失
	CFG_LOCALALAEM,		///< 本地报警
	CFG_NETALAEM,		///< 网络报警
	CFG_NETIPCONFLICT,	///< IP地址冲突
	CFG_NETABORT,		///< 网络异常
	CFG_STORAGENOTEXIST,	///< 存储设备不存在
	CFG_STORAGELOWSPACE,	///< 存储设备容量不足
	CFG_STORAGEFAILURE,		///< 存储设备访问失败
	CFG_PTZALARM,			///< 云台报警
	CFG_NETCOMMON,			///< 通用网络配置
	CFG_NETIPFILTER,		///< 白黑名单
	CFG_NETDHCP,		///< DHCP
	CFG_NETDDNS,		///< DDNS
	CFG_NETEMAIL,		///< EMail
	CFG_NETMULTICAST,	///< 多播
	CFG_NETNTP,			///< 时间同步服务
	CFG_NETPPPOE,		///< PPPOE
	CFG_NETDNS,			///< DNS
	CFG_COMM,			///< 串口配置
	CFG_PTZ,			///< 云台配置
	CFG_PTZPRESET,		///< 云台预置点配置
	CFG_PTZTOUR,		///< 
	CFG_TOUR,			///< 轮巡配置
	CFG_GUISET,			///< GUISet配置
	CFG_TVADJUST,		///< TV调节
	CFG_AUDIOINFORMAT,	///< 对讲配置
	CFG_PLAY,			///< 回放
	CFG_GENERAL,		///< 普通配置
	CFG_LOCATION,		///< 本地化配置
	CFG_AUTOMAINTAIN,	///< 自动维护配置
	CFG_CHANNELTITLE,	///< !! 通道名称配置，特殊
	CFG_SNAPSHOT,		///< 图片存储配置
	CFG_COMBINEENCODE,  ///< 组合编码
	CFG_COMBINEENCODEMODE,  ///< 组合编码模式
	CFG_NETFTP,			///< FTP配置
	CFG_NETARSP,		///< ARSP配置
	CFG_NETPLAT_MEGANET, ///< HXHT平台接入
	CFG_NETPLAT_MEGAMOTION, ///< HXHT平台保存的动检参数
	CFG_ABILITY_SUPPORTLANGUAGE,	///< 支持的语言
	CFG_NETDECORDER,	///< 网络解码器配置
	CFG_3GNET,			///< 3G网络配置
	CFG_MOBILE,         ///< 手机监控配置
	CFG_ABILITY_SUPPORTVSTD,	///< 支持的视频制式
	CFG_VIDEOCHANNEL,	///< 支持的视频通道配置
	CFG_CARPLATE,		///< 车牌号配置
	CFG_NETUPNP,           ///< UPNP配置
	CFG_ABILITY_DEVDESC,	///< 设备描述配置
	CFG_STORAGE_POSITION,
	CFG_WIFI,          ///< WIFI
	CFG_SYSTEM_STATE,      ///< 该值废弃，功能已经转入CFG_LAST_SPLIT_STATE和CFG_SYSTEM_TIMING_WORK，但因为库里也有用这些枚举，为避免大量库重新编译，先保留着
	CFG_VIDEOOUT,
	CFG_ABILITY_VGARESOLUTION,	///< 支持的VGA分辨率列表
	CFG_ABILITY_THEMELIST,		///< 支持的GUI主题列表
	CFG_ENCODE_SIMPLIFY,		///< 最新简化版本编码配置
	CFG_RS485,                  ///< 485设备配置
	CFG_NETALARMSERVER,         ///< 报警中心
	CFG_ALARMOUT,               ///< 报警输出
	CFG_NETPLAT_XINWANG,        ///< 新望平台
	CFG_NETPLAT_SHISOU,        ///< 视搜平台
	CFG_NETPLAT_VVEYE,        ///< VVEYE平台
	CFG_MEDIA_WATERMARK,	///< 数字水印配置
	CFG_NETDECORDER_V2,		///< 网络解码器配置V2版本
	CFG_NETPLAT_WELLSUN,    ///< 惠尔森平台
	CFG_ABILITY_ENOCDE,		///< 编码能力集
	CFG_NET_RTSP,		    ///< RTSP配置
	CFG_ABILITY_SERIALNO,		///< 设置序列号
	CFG_NETDECORDER_V3,		//数字通道配置
	CFG_NETDECORDER_CHNMODE,  //通道模式配置
	CFG_NETDECORDER_CHNSTATUS,  //通道状态
	CFG_PRODUCE_TEST,		///<生产测试配置
	CFG_NET_POS,		//POS机配置
	CFG_CAMERA_PARAM,         //网络摄像头参数配置
	CFG_OSD_WIDGET,           //OSD信息位置与状态配置
	CFG_NET_DAS,
	CFG_NETPLAT_NANRUI,       //楠瑞平台接入
	CFG_VOLUME, //音量调节
	CFG_SPOT,                 //SPOT输出
	CFG_PHONE_SHORT_MSG,      //手机短信
	CFG_PHONE_MULTIMEDIA_MSG, //手机彩信
	CFG_CAR_INPUT_EXCHANGE,   //外部信息输入与车辆状态的对应关系
	CFG_CAR_DELAY_TIME,       //车载系统延时配置
	CFG_NET_ORDER,            //网络优先级
	CFG_LOCALSDK_NET_PLATFORM, //网络平台信息设置
	CFG_GPS_TIMING,           //GPS校时相关配置
	CFG_CAR_DISPLAY,          //车载显示配置
	CFG_VIDEO_ANALYZE,        //视频分析(智能DVR)
	CFG_GODEYE_ALARM,		//神眼接警中心系统
	CFG_NAT_STATUS_INFO,	//NAT状态信息
	CFG_ENCODE_STATICPARAM,	//编码器静态参数
	CFG_LOSS_SHOW_STR,		//视频丢失显示字符串
	CFG_DIGMANAGER_SHOW,	//通道管理显示配置
	CFG_VIDEOOUT_PRIORITY,   //显示HDMI VGA优先级别配置
	CFG_NAT,					//NAT功能使能与MTU值配置
	CFG_ANALYZE_LINK,			//智能分析联动配置
	CFG_GUIDE,					//向导配置
	CFG_VIDEOSEQUE,		//CMS风格预览画面配置
	CFG_AUTOLOGIN,				//自动登录配置
	CFG_VPN,
	CFG_RESUME_PTZ_STATE,    //恢复云台状态相关配置
	CFG_NET_LOCALSEARCH,    //远程搜索
	CFG_VOCOLORADJUST, 	///<VO显示调节
	CFG_NETPLAT_KAINENG, //凯能平台
	CFG_PREHVRCAP,	//上次退出系统模式
	CFG_ENCODE_STATICPARAM_V2,	//DVR编码器静态参数
	CFG_C7_PLATFORM,            //安徽创世公司的C7平台配置参数
	CFG_NET_KEYBOARD,	//网络键盘
	CFG_SPVMN_PLATFORM,     //28181协议配置
	CFG_PROFESSION_NVR_MODE, //专业NVR数字通道模式配置
	CFG_PMS,				//手机服务
	CFG_PHONEASIDLIST,		//手机id信息
	CFG_OSD_INFO,           //屏幕提示信息
	CFG_KAICONG,		//凯聪
	CFG_DIGITAL_HIDE,		//通道模式屏蔽 //这个配置已经去掉了
	CFG_DIGITAL_REAL,		//真正支持的通道模式
	CFG_DECODE_PARAM,     //解码最大延时
	CFG_XMHEARTBEAT,		//雄迈心跳配置
	CFG_MONITOR_PLATFORM,	//神州数码监控平台
	CFG_OSD_LOGO,           //编码里增加小logo的配置
	CFG_PARAM_EX,	//摄像头扩展参数
	CFG_NETPLAT_ANJU_P2P,	//安巨P2P
	CFG_CORRESPONDENT_INFO,//用户自定义配置
	CFG_RECORD_STATE,		//录像状态
	CFG_VIDEOCOLOR_CUSTOM,//普天视定制
	CFG_DIGITCHN_STATE,		//数字通道连接状态
	CFG_TITLENAME_INFO,		//通道标题
	CFG_CAR_BOOT_TYPE,		//车载开关机模式
	CFG_SPE_CH_SQE,			//客户定制的特殊轮巡顺序
	CFG_IPC_ALARM,			//IPC网络报警
	CFG_NETPLAT_TUTK_IOTC,	//TUTK IOTC平台配置
	CFG_BAIDU_CLOUD,		//baidu云
	CFG_PMS_MSGNUM,			//手机订阅数
	CFG_AUDIO_OPENED_CH,	//默认开启第几路音频的配置
	CFG_APP_DOWN_LINK,		//用于用户定制下载链接
	CFG_AUTO_CONNECT,	//自动连接配置
	CFG_MOBILE_WATCH,	//中国电信手机看店平台配置
	CFG_BROWSER_LANGUAGE,   //使用浏览器时使用的语言，配置不保存到文件中
	CFG_TIME_ZONE,		//时区配置
	CFG_NETBJLTHY,	//北京龙腾服务器访问配置
	CFG_DIG_TIME_SYN,		//数字通道时间同步配置
	CFG_RECORD_ENABLE,       //是否准备好开始录像和抓图，现在用于日本客户通过串口控制开启和关闭录像功能
	CFG_NKB_DEVICE_LIST,	//网络键盘设备链表
	CFG_EXT_RECORD,			///< 辅助码流录像录像配置
	CFG_CUSTOMIZE_OEMINFO,		//定制OEM客户版本信息
	CFG_DIGITAL_ENCODE, //数字通道精简版编码配置
	CFG_DIGITAL_ABILITY,
	CFG_ENCODECH_DISPLAY,//IE端编码配置显示的前端通道号
	CFG_LAST_SPLIT_STATE,   //最近一次的画面分割模式，用于重启后恢复之前的分割模式
	CFG_SYSTEM_TIMING_WORK, //设备定时开关机时间配置。隐藏在自动维护页面里，要用超级密码登陆才能看到界面
	CFG_GBEYESENV,			///宝威环境监测平台配置
	CFG_PARKING_PORT,		//泊车系统端口号配置
	CFG_SPEEDALARM,			//速度报警
	CFG_TEST_DEV_SET,//工装  测试   信息， 保存至  被测试设备
	CFG_TEST_DEV_CHECK,//工装测试   校验信息 ，保存至被校验设备
	CFG_TRANS_COMM_DATA, //串口数据主动上传到UDP或TCP服务器，其中TCP服务器可以支持双向通信
	CFG_EX_USER_MAP,	//用于保存明文数据
	CFG_DATALINK,	//datalink客户在网络服务中的执行程序使能配置
	CFG_GSENSORALARM,		//GSENSOR报警
	CFG_WIFI_MODE,			//Wifi模式配置，用于行车记录仪切换AP模式
	CFG_PTZPATTERN,			//巡迹配置
	CFG_USER_PROGRAM,		//用户小程序相关启动参数
	CFG_FTP_AUTO_UPLOAD,	//自动上传视频到FTP服务器相关配置
	CFG_SNAP_AUTOUPLOAD,	//深广平台自动抓图上传配置
	CFG_SNAP_ALARMUPLOAD,	//深广平台报警抓图上传配置
	CFG_ALARM_DURATION,		//报警状态延续时间配置
	CFG_NETPLAT_BJHONGTAIHENG,  ///< 北京鸿泰恒平台
	CFG_CLOUD_STORAGE,		//云存储相关配置
	CFG_IDLE_PTZ_STATE,		//云台空闲动作相关配置
	CFG_TX_DEV_INFO,		//腾讯平台注册用设备信息
	CFG_CAMERA_CLEAR_FOG,	//去雾功能配置	
	CFG_CAMERA_MOTOR_CONTROL, //机器人马达控制
	CFG_ENCODE_ADD_BEEP,		//设置编码加入每隔30秒beep声	
	CFG_FISH_EYE_PARAM,		//鱼眼功能参数配置
	CFG_NETPLAT_SPVMN_NAS,	//安徽超清客户的nas服务器配置
	CFG_SPARSH_HEARTBEAT,	//Sparsh客户的心跳功能配置
	CFG_LOGIN_FAILED,		//登录失败时发送邮件，使用结构体:基本事件结构
	CFG_NET_CON_DISCON_TIME,//网络连接与断开时间配置，用于客户定制的将断网期间的图片上传FTP
	CFG_ADDED_ALARM_DEV,	//消费类产品已经添加的传感器，包括门磁、烟感和遥控器等
	CFG_CONSUMER_COMM_DEV_CFG,	//消费类产品外接设备控制配置
	CFG_IPV6_ADDRESS,		//ipv6
	CFG_SERIALPORT_ALARM,	// 串口报警配置	
	CFG_ONLINE_UPGRADE,		// 在线升级相关配置
	CFG_VIDEO_ANALYZE_PUB,	//智能分析使能与算法种类配置(临时配置，并不保存)
	CFG_VIDEO_ANALYZE_PEA,	//智能分析PEA算法配置(临时配置，并不保存)
	CFG_VIDEO_ANALYZE_OSC,	//智能分析OSC算法配置	(临时配置，并不保存)
	CFG_VIDEO_ANALYZE_AVD,	//智能分析AVD算法配置	(临时配置，并不保存)
	CFG_VIDEO_ANALYZE_CPC,	//智能分析CPC算法配置(临时配置，并不保存)
	CFG_EXT_SUB_DEV_ID, 	//扩展的设备子ID
	
	CFG_SMARTDETECTION_CODEC,			//智能编码		by ctf 20170911
	CFG_SMARTDETECTION_DETECT,			//智能检测		by ctf 20170911
	CFG_SMARTDETECTION_CONTROL,			//智能控制		by ctf 20170911
	CFG_SMARTDETECTION_LUMINANCE,		//亮度侦测		by ctf 20170908
	CFG_SMARTDETECTION_MOVE,			//移动侦测		by ctf 20170908
	CFG_SMARTDETECTION_OCCLUSION,		//遮挡侦测		by ctf 20170908
	CFG_SMARTDETECTION_CROSSLINE,		//虚拟警戒线	by ctf 20170908
	CFG_SMARTDETECTION_CROSSAREA,		//区域入侵		by ctf 20170908
	CFG_SMARTDETECTION_COLOR,			//颜色			by ctf 20170908
	CFG_SMARTDETECTION_SOUND,			//声音			by ctf 20170908
	CFG_SMARTDETECTION_LOSEOBJ,			//物品预留		by ctf 20170908

	CFG_CALIBRATION_GET_CAMERA_PARAMETER,		//获取摄像机是否已经标定		by ctf 20180122
	CFG_CALIBRATION_SET_SUBCAMERA_CONNECTINFO,	//设置从机登录信息				by ctf 20180122
	CFG_CALIBRATION_SET_POINTS,					//设置标定坐标(增、删，3D)		by ctf 20180122
	CFG_CALIBRATION_ACTION,						//设置标定（开始、完成）		by ctf 20180122  Action
	CFG_CALIBRATION_MODE,						//标定模式						by ctf 20180122
	CFG_CALIBRATION_ZOOMTIMES,					//变倍系数						by ctf 20180122
	
	CFG_CALIBRATION_PTZINFO,					//获取PTZ参数					by ctf 20180210
	CFG_CALIBRATION_SETINFO_YW,					//参数							by ctf 20180416
	CFG_CALIBRATION_RESULT_YW,					//结果	 Result					by ctf 20180416
	CFG_CALIBRATION_PANOTYPE,
	CFG_CALIBRATION_ENCRYPT,					//全图加密串
	CFG_CALIBRATION_NAMING,						//点名球
	CFG_CALIBRATION_NAMING_GET,						//点名球

	CFG_FACECOMPARE_RESULT_ALARM,				//人脸比对结果报警				by ctf 20180206
	CFG_FACEWB_RESULT_RES,						//人脸黑白名单导入回应			by ctf 20180206

	CFG_FACEWB_COMMON_PARAMETER,				//人脸参数				
	CFG_FACEWB_AREADETECTION,					//人脸侦测区域

	CFG_SMARTFACE_COMMON_PARAMETER,
	CFG_SMARTFACE_AREADETECTION,
	CFG_SMARTFACE_AREASHIELDED,

	CFG_SMARTFACE_VERSION,
	CFG_SMARTFACE_ALARM,

	CFG_LINKAGE_BIND,					//全景联控绑定区域					by jfp 20181101
	CFG_CUSTOMIZED_QT,					//定制-长沙全图用户数据				by jfp 20181115
	CFG_OSD,						//OSD
	CFG_SMART,
	CFG_EXPOSURE,

	CFG_NR,
};

/// 根据配置种类ConfigKinds取得相应名称
const char *getConfigName(int iConfigKind);

/// 根据配置名称得到配置种类常量
int getConfigIndex(const char *sConfigKind);

enum AbilityKinds
{
	ABILITY_SYSTEM_FUNCTION,	///< 系统功能
	ABILITY_ENCODE,				///< 编码功能
	ABILITY_BLIND,				///< 遮挡检测功能
	ABILITY_MOTION,				///< 动态检测功能
	ABILITY_DDNS_TYPES,			///< DDNS服务类型
	ABILITY_COMM_PROTOCOLS,		///< 串口协议
	ABILITY_PTZ_PROTOCOLS,		///< 云台协议
	ABILITY_TALK_ATTRIBUTE,		///< 对讲属性
	ABILITY_MULTI_LANG,			///< 允许设置的语言
	ABILITY_LANG_LIST,			///< 实际支持的语言集
	ABILITY_MULTI_VSTD,			///< 允许设置的视频制式
	ABILITY_VSTD_LIST,			///< 实际支持的视频制式
	ABILITY_UART_PROTOCOLS,		///<458协议
	ABILITY_CAMERA,             ///< 摄像头相关能力集
	ABILITY_NETORDER,           //网络优先级设置能力
	ABILITY_INTELLIGENT,	//智能分析能力集
	ABILITY_NET_CONNECT,	//网络链接能力
	ABILITY_CARSTATUSNUM,	//车载车辆状态数
	ABILITY_VGARESOLUTION,// 支持的VGA分辨率能力集
	ABILITY_ENC_STATICPARAM,	//静态编码能力集
	ABILITY_NET_KEYBOARD,	//网络键盘能力集
	ABILITY_PTZCONTROL,	//PTZ控制能力集
	ABILITY_DECODE_DELEY,	//解码策略能力
	ABILITY_ONVIF_SUB_PROTOCOL,	//onvif子协议
	ABILITY_DIMEN_CODE,//二维码
	ABILITY_MAX_PRE_RECORD,//最大可设置预录时间
	ABILITY_AHD_ENCODE_L, //AHDL能力集
	ABILITY_SUPPORT_EXTSTREAM,	//支持辅码流录像
	ABILITY_KIND_NR,
};

/// 根据能力集获取相应的字符串
const char *getAbilityName(int iAbilityKind);

int getAbilityIndex(const char *sAbilityKind);

/// 系统信息种类
enum DeviceInfoKinds
{
	DEVICE_INFO_SYSTEM,		///< 系统信息
	DEVICE_INFO_STORAGE,	///< 存储设备信息
	DEVICE_INFO_WORKSTATE,	///< 工作状态信息
	DEVICE_INFO_WIFI_AP,    ///< WIFI AP信息
	DEVICE_OEM_INFO,
	DEVICE_INFO_GPS_STATUS, ///< GPS定位信息
	DEVICE_INFO_WIFI_STATUS,///< Wifi连接信息
	DEVICE_INFO_3G_STATUS,  ///< 3G连接信息
	DEVICE_INFO_DAS_STATUS, ///< 主动注册状态
	DEVICE_INFO_NR,
};

const char *getDeviceInfoName(int iDeviceInfoKind);

int getDeviceInfoIndex(const char *sDeviceInfoKind);

/// 基本系统操作
enum SystemOperations
{
	OPERATION_MACHINE,			///< 关机，重启操作
	OPERATION_DEFAULT_CONFIG,	///< 默认配置操作
	OPERATION_PTZ,				///< 云台控制
	OPERATION_MONITOR,			///< 监视控制
	OPERATION_PLAYBACK,			///< 回放控制
	OPERATION_TALK,				///< 语音对讲控制
	OPERATION_DISK_MANAGER,		///< 磁盘管理
	OPERATION_LOG_MANAGER,		///< 日志管理
	OPERATION_SYSTEM_UPGRADE,	///< 系统升级
	OPERATION_FILE_QUERY,		///< 文件查询
	OPERATION_LOG_QUERY,		///< 日志查询
	OPERATION_TIME_SETTING,		///< 设置系统时间
	OPERATION_NET_KEYBOARD,		///< 网络键盘
	OPERATION_NET_ALARM,		///< 网络告警
	OPERATION_SNAP, 		    ///< 网络手动抓图
	OPERATION_TRANS, 			///< 透明串口
	OPERATION_UPDATA,			///< 上传数据
	OPERATION_TIME_SETTING_NORTC,///<对于没有rtc的设备配置时间
	OPERATION_CPCDATA,		///<人数统计查询
	OPERATION_LOCALSEARCH,	///远程搜索操作
	OPERATION_MAILTEST,		///邮件测试
	OPERATION_PHONE,			///手机操作
	OPERATION_STORAGE,		//硬盘信息、文件时间、录像状态
	OPERATION_FILE_CONTRAL,	///文件或文件夹增加删除操作
	OPERATION_MUSICFILE_QUERY,		///< 音频文件查询
	OPERATION_MUSIC_PLAY,			///< 音频播放控制
	OPERATION_DIG_SETIP,		///<设置前端ip
	OPERATION_UTC_TIME_SETTING,///设置UTC时间
	OPERATION_SET_OSDINFO,//OSD信息设置，提供给客户
	OPERATION_SET_OSDINFO_V2,//OSD信息叠加，不保存配置，单行最多叠加31个汉字
	OPERATION_UPGRADE_VERSION_LIST,	///老版本云升级版本列表查询
	OPERATION_UPGRADE_VERSION,		///云升级请求
	OPERATION_FTPTEST,     ///FTP测试
	OPERATION_SET_LOGO,		//视频上叠加雄迈等厂家的LOGO
	OPERATION_CONSUMER_PRO_CMD, //消费类产品特殊命令
	OPERATION_DDNSAPPLY,		//ddns apply按键功能
	OPEARTION_CALENDAR,     //网络查询一个月中有无录像
	OPEARTION_COMPRESS_PICTURE,  //手机端查询缩略图
	OPERATION_NEW_UPGRADE_VERSION_REQ,	///新版云升级版本查询请求
	OPERATION_NEW_UPGRADE_VERSION_REP,	///新版云升级版本查询回复
	OPERATION_NEW_START_UPGRADE,
	OPEARTION_SPLIT_CONTROL,			//切换DVR的预览画面分割模式

	OPEARTION_FACEIMAGE_CONTROL,			//
	OPEARTION_FACECOMPARE_CONTROL,			//Compare
	OPEARTION_FACEWBLIST_CONTROL,			//WbList
	OPEARTION_FACEWBLIST_CONFIG,
	OPEARTION_CARLICENSEPLATE_CONFIG,       //车牌图片
	OPEARTION_GPIO_CONTROL,					//IO控制

	OPERATION_NR,
};

const char *getOperationName(int iOperationKind);

int getOperationIndex(const char *sOperationKind);

typedef enum app_event_code
{
	appEventInit = 0,
	appEventAlarmLocal = 1,
	appEventAlarmNet,
	appEventAlarmManual,
	appEventVideoMotion,
	appEventVideoLoss,
	appEventVideoBlind,
	appEventVideoTitle,
	appEventVideoSplit,
	appEventVideoTour,
	appEventStorageNotExist,
	appEventStorageFailure,
	appEventStorageLowSpace,
	appEventNetAbort,
	appEventComm,
	appEventStorageReadErr,
	appEventStorageWriteErr,
	appEventIPConflict,
	appEventAlarmEmergency,
	appEventDecConnect,
	appEventUpgrade,
	appEventBackup,
	appEventShutdown,
	appEventReboot,
	appEventNewFile,
	appEventVideoAnalyze,
	appEventIPCAlarm,
	appEventSpeedAlarm,
	appEventGSensorAlarm,
	appEventLoginFailed,
	appEventSerialAlarm,
	appEventConsSensorAlarm, //消费类产品绑定的外部设备报警
	appEventBrightness,
	appEventShelter,
	appEventCrossLine,
	appEventCrossArea,
	appEventColor,
	appEventSound,
	appEventLoseOBJ,
	appEventAll
}appEventCode;

const char *getEventName(int iOperationKind);

int getEventIndex(const char *sOperationKind);

// 日志类型
enum LogType
{
	logTypeAll,
	logTypeSystem,	/// 系统日志
	logTypeConfig,	/// 
	logTypeStorage,
	logTypeAlarm,
	logTypeRecord,
	logTypeAccount,
	logTypeAccess,
	logTypeNr,
};

/// 得到日志类型名称
const char *getLogTypeName(int iLogType);

enum LogItemType
{
	logItemReboot,
	logItemShutDown,
	logItemClearLog,
	logItemModifyTime,
	logItemZeroBitrate,
	logItemUpgrade,
	logItemException,
	logItemUpdate,
	logItemSetTime,
	logItemSaveConfig,
	logItemSetDriverType,
	logItemClearDriver,
	logItemStorageDeviceError,
	logItemDiskChanged,
	logItemEventStart,
	logItemEventStop,
	logItemRecord,
	logItemLogIn,
	logItemLogOut,
	logItemAddUser,
	logItemDeleteUser,
	logItemModifyUser,
	logItemModifyPassword,
	logItemAddGroup,
	logItemDeleteGroup,
	logItemModifyGroup,
	logItemAccountRestore,
	logItemFileAccessError,
	logItemFileSearch,
	logItemFileAccess,
	logItemRecoverTime,
	logItemNr,
	logItemSaveSystemState,
};

const char *getLogData(int iLogItemKind);
int getLogType(const char *sLog);


//系统调试相关
enum SystemDebug
{
	DEBUG_CAMERA,
	DEBUG_SHELL,
	DEBUG_CAMERA_SAVE_CMD,
	DEBUG_NR
};

/// 调试种类
enum DebugKinds
{
	DEBUG_OPR_PING_DEV,			///< 
	DEBUG_OPR_PING,				///<执行Ping操作
	DEBUG_OPR_HDD_RW,			///<存储设备执行读写操作
	DEBUG_OPR_USB_RW,			///<USB设备执行读写操作
	DEBUG_OPR_SD_RW,			///<SD卡执行读写操作
	DEBUG_OPR_GETPRODUCTDEFIN,	///<获取设备型号
	DEBUG_OPR_TESTPLAY,			///<播放测试
	DEBUG_OPR_HDDINFO,			///<获取HDDINFO操作
	DEBUG_OPR_TFSIZE,			///<获取TF卡大小操作
	DEBUG_OPR_IRCUTSWITCH,		///<IRCUT切换操作
	DEBUG_OPR_SHOWBPSINFO,		///<
	DEBUG_OPR_NEXTCHANNELPREW,	///<
	DEBUG_OPR_SETMAC,			///<设置MAC操作
	DEBUG_OPR_KEYLIGHT,			///<设置按键指示灯进入测试模式
	DEBUG_OPR_NR,
};

const char *getDebugName(int iDebugKind);
int getDebugKind(const char *pDebugName);

#endif

