#ifndef __LVR_NET_SDK_H__
#define __LVR_NET_SDK_H__

#ifdef __LVR_NET_EXPORT__
#define LVR_NET_API  extern "C" __declspec(dllexport)
#else
#define LVR_NET_API  extern "C" __declspec(dllimport)
#endif


#define MAX_CHANNEL_NUM							32 // 最大通道数
#define MAX_ACCOUNT_NUM							8  // 最大用户数量
#define MAX_ALARMIN_NUM							32 // 最大报警输入数
#define MAX_ALARMOUT_NUM						16 // 最大报警输出数
#define MAX_HARDDISK_NUM						16 // 最大硬盘数
#define MAX_DDNS_NUM							 4 //最大ddns数

// 协议类型
#define TCP_PROTOCOL_MODE						0x00000001 // TCP
#define UDP_PROTOCOL_MODE						0x00000002 // UDP
#define MULTICAST_MODE							0x00000004 // 组播
#define RTP_PROTOCOL_MODE						0x00000008 // RTP
#define SELECT_SUB_STREAM						0x80000000 // 子码流选择

// 回调数据类型
#define	LVR_NET_IFRAME							0x1000 // 视频I帧
#define	LVR_NET_PFRAME							0x2000 // 视频P帧
#define	LVR_NET_BFRAME							0x3000 // 视频B帧
#define	LVR_NET_AUDIO							0x4000 // 音频帧
#define LVR_NET_VIDEOEND						0xD000 // 远程回放最后的视频帧
#define LVR_NET_AUDIOEND						0xE000 // 远程回放最后的音频帧

// 错误代码
#define LVR_NET_RETURN_NO_ERROR                 0 /* 没有错误 */
#define LVR_NET_ERROR_NO_PRIVI                  0x80000001 /* 无此权限 */
#define LVR_NET_ERROR_MUST_REBOOT               0x80000002 /* 需要重启 */
#define LVR_NET_ERROR_INVALID_CMD               0xFFFFFFFF /* 无效命令 */

#define LVR_NET_OUTOF_MEMORY					0x00000001 // 分配内存失败
#define LVR_NET_INVALID_PARAMETER				0x00000002 // 非法参数
#define LVR_NET_SEND_FAIL						0x00000003 // 发送失败
#define LVR_NET_TRY_TIMEOUT						0x00000004 // 重试超时
#define LVR_NET_CONNECT_FAIL					0x00000005 // 服务器连接失败
#define LVR_NET_INVALID_FILE					0x00000006 // 非法文件
#define LVR_NET_LINK_FAIL						0x00000007 // 数据传输建立失败
#define LVR_NET_WINSOCK_INIT					0x00000008 // Winsock库初始化失败
#define LVR_NET_LOGIN_FAIL						0x00000009 // 用户登录失败
#define LVR_NET_TIME_ERROR						0x0000000A // 非法时间参数
#define LVR_NET_LOG_NOMORE						0x0000000B // 没有更多日志
#define LVR_NET_FILE_NOMORE						0x0000000C // 没有更多文件
#define LVR_NET_DDNS_ERROR						0x0000000D // 域名解析错误
#define LVR_NET_INVALID_TIME					0x0000000E // 时间错误
#define LVR_NET_FILE_CREATE_FAIL				0x0000000F // 文件创建失败
#define LVR_NET_VERSION_NOTMATCH				0x00000010 // 服务器软件版本太低
#define LVR_NET_PRECREATE_FAIL					0x00000020 // 视频预创建失败
#define LVR_NET_SERVER_SUSPEND					0x00000030 // 服务器处于挂起状态
#define LVR_NET_REALPLAY_SUSPEND				0x00000040 // 通道处于挂起状态
#define LVR_NET_INTERNAL_ERROR					0x00000050 // 内部错误
#define LVR_NET_NO_PRIVI						0x00000060 // 无此权限


// 云台协议类型
#define PTZ_NO_EXIST							0
#define PROTOCOL_PELCO_D1						1
#define PROTOCOL_PELCO_D2						2
#define PROTOCOL_PELCO_D3						3
#define PROTOCOL_PELCO_D4						4
#define PROTOCOL_PELCO_D5						5
#define PROTOCOL_PELCO_D6						6
#define PROTOCOL_PELCO_D7						7
#define PROTOCOL_PELCO_D8						8

#define PROTOCOL_PELCO_P1						16
#define PROTOCOL_PELCO_P2						17
#define PROTOCOL_PELCO_P3						18
#define PROTOCOL_PTZ_MLP2						19
// #define PROTOCOL_PELCO_P4						12
// #define PROTOCOL_PELCO_P5						13
// #define PROTOCOL_PELCO_P6						14
// #define PROTOCOL_PELCO_P7						15
// #define PROTOCOL_PELCO_P8						16

// 云台控制
#define LVR_NET_TILT_UP							1 // 云台向上
#define LVR_NET_TILT_DOWN						2 // 云台向下
#define LVR_NET_PAN_LEFT						3 // 云台左转
#define LVR_NET_PAN_RIGHT						4 // 云台右转
#define LVR_NET_UP_LEFT							5 // 云台上左
#define LVR_NET_UP_RIGHT						6 // 云台上右
#define LVR_NET_DOWN_LEFT						7 // 云台下左
#define LVR_NET_DOWN_RIGHT						8 // 云台下右
#define LVR_NET_IRIS_SMALL						9 // 光圈缩小
#define LVR_NET_IRIS_BIG						10 // 光圈扩大
#define LVR_NET_FOCUS_NEAR						11 // 焦点前调
#define LVR_NET_FOCUS_FAR						12 // 焦点后调
#define LVR_NET_ZOOM_WIDE						13 // 焦距变大(倍率变大)
#define LVR_NET_ZOOM_TELE						14 // 焦距变小(倍率变小)
#define LVR_NET_SET_PRESET						15 // 设置预置点
#define LVR_NET_CLR_PRESET						16 // 清除预置点
#define LVR_NET_CALL_PRESET						17 // 调用预置点
#define LVR_NET_AUX_ON							18 // 接通辅助设备开关
#define LVR_NET_AUX_OFF							19 // 关闭辅助设备开关
#define LVR_NET_PRESET_ADD						20 // 巡航添加预置点
#define LVR_NET_PRESET_REMOVE					21 // 巡航移除预置点
#define LVR_NET_TOUR_DELAY						22 // 巡航停留时间
#define LVR_NET_TOUR_DELETE						23 // 清除巡航线
#define LVR_NET_TOUR_START						24 // 开始巡航
#define LVR_NET_TOUR_STOP						25 // 停止巡航
#define LVR_NET_PATTERN_BEGIN					26 // 轨迹起点
#define LVR_NET_PATTERN_END						27 // 轨迹终点
#define LVR_NET_PATTERN_RUN						28 // 开始轨迹
#define LVR_NET_PATTERN_STOP					29 // 停止轨迹
#define LVR_NET_SCAN_LEFT						30 // 左边界
#define LVR_NET_SCAN_RIGHT						31 // 右边界
#define LVR_NET_SCAN_START						32 // 边界扫描启动
#define LVR_NET_SCAN_STOP						33 // 边界扫描停止
#define LVR_NET_AUTO_PAN						34 // 云台自动旋转
#define LVR_NET_RESET_PAN						35 // 云台复位

// 参数访问
#define LVR_PARA_DEVICE_INFO					0x1000 // 设备参数LVR_NET_DEVICE_INFO
#define LVR_PARA_DATE_TIME						0x1001 // 时间日期LVR_NET_DATE_TIME
#define LVR_PARA_ENCODE_CONFIG					0x1002 // 编码设置LVR_NET_ENCODE_CONFIG
#define LVR_PARA_SUB_ENCODE						0x1003 // 子码流设置LVR_NET_SUB_ENCODE
#define LVR_PARA_BLEND_CONFIG					0x1004 // 录像叠加LVR_NET_BLEND_CONFIG
#define LVR_PARA_RECORD_MODE					0x1005 // 录像模式LVR_NET_RECORD_MODE
#define LVR_PARA_RECORD_SCHEDULE				0x1006 // 录像计划LVR_NET_RECORD_SCHEDULE
#define LVR_PARA_PTZ_CONFIG						0x1007 // 云台设置LVR_NET_PTZ_CONFIG
#define LVR_PARA_NETWORK_CONFIG					0x1008 // 网络设置LVR_NET_NETWORK_CONFIG
#define LVR_PARA_PPPOE_CONFIG					0x1009 // 拨号设置LVR_NET_PPPOE_CONFIG
#define LVR_PARA_DDNS_CONFIG					0x100A // 拨号设置LVR_NET_DDNS_CONFIG
#define LVR_PARA_EMAIL_CONFIG					0x100B // 邮件设置LVR_NET_EMAIL_CONFIG
#define LVR_PARA_ALARM_CONFIG					0x100C // 报警设置LVR_NET_ALARM_CONFIG
#define LVR_PARA_VIDEO_LOSS						0x100D // 视频丢失设置LVR_NET_VIDEO_LOSS
#define LVR_PARA_MOTION_DETECT					0x100E // 动检设置LVR_NET_MOTION_DETECT
#define LVR_PARA_VIDEO_PRIVACY					0x100F // 隐私遮挡LVR_NET_PRIVACY_CONFIG
#define LVR_PARA_USER_INFO						0x1010 // 用户帐号LVR_NET_USER_INFO
#define LVR_PARA_OUTPUT_SCHEDULE				0x1011 // 输出计划LVR_NET_OUTPUT_SCHEDULE
#define LVR_PARA_VIDEOFORMAT_CONFIG				0x1012 // 视频制式LVR_NET_VEDIO_FORMAT
#define LVR_PARA_TIME_INFO						0x1013 // 时间日期LVR_NET_TIME_CONFIG
#define LVR_PARA_PTZ_ALARM_RELATE				0x1014 // 云台联动
#define LVR_PARA_CHANNELNAME					0x1015 // 通道名称设置
#define LVR_PARA_CHANNELNAMEUTF8				0x1016 // 通道名称设置
#define LVR_PARA_NTP_CONFIG						0x1017 // NTP设置
#define LVR_PARA_OUTPUT_CONFIG					0x1018 // 输出设置
#define LVR_PARA_ONLINE_USERINFO_CONFIG			0x1019 // 在线用户

// 远程控制DVR录像方式
#define REMOTE_RECORD_STOP						0 // 停止录像
#define REMOTE_RECORD_MANUAL					1 // 手动录像
#define REMOTE_RECORD_AUTO						2 // 计划录像


#define NOT_RECORD           0
#define NORMAL_RECORD        1
#define MOTION_RECORD        2
#define ALARM_RECORD         4
#define MOTION_ALARM_RECORD  8

// 视频编码格式
#define ENCODE_FORMAT_QCIF						0 // QCIF编码
#define ENCODE_FORMAT_CIF						1 // CIF编码
#define ENCODE_FORMAT_HD1						3 // HALF D1编码
#define ENCODE_FORMAT_D1I						6 // 隔行D1编码
#define ENCODE_FORMAT_D1P						7 // 逐行D1编码
#define ENCODE_FORMAT_720P						8 // HD720P
#define ENCODE_FORMAT_1080P						9 // HD1080P
#define ENCODE_FORMAT_D1						10// SYSTEMINFO中的GlobalAbility如果包含GLOBAL_D1_INTERVAL属性则表示D1编码是隔行的ENCODE_D1I，否则是ENCODE_D1P

// 录像文件类型
#define LVR_ALL_FILE							0xFF // 全部文件
#define LVR_NORMAL_FILE							0x00 // 普通录像
#define LVR_ALARM_FILE							0x01 // 报警录像
#define LVR_MOTION_FILE							0x02 // 移动侦测录像

// 日志类型
#define LVR_NET_LOG_ALL_LOG							0xFFFFFFFF // 全部日志
#define LVR_NET_LOG_SYSTEM_OPERATE					0x0001 // 系统操作
#define LVR_NET_LOG_SYSTEM_CONFIG					0x0002 // 参数设置
#define LVR_NET_LOG_SYSTEM_ALARM					0x0004 // 报警日志	
#define LVR_NET_LOG_SYSTEM_ERROR					0x0008 // 错误信息
#define LVR_NET_LOG_SYSTEM_UNKNOW					0x00FF	//未知日志类型
//操作类型
#define LVR_NET_LOG_OPERATE_START					0x0001 // 开始
#define LVR_NET_LOG_OPERATE_STOP					0x0002 // 停止
#define LVR_NET_LOG_OPERATE_WRITE					0x0003 // 写入
#define LVR_NET_LOG_OPERATE_READ					0x0004 // 开始
#define LVR_NET_LOG_OPERATE_UNKNOW					0x00FF // 未知操作

// LVR_NET_SYSTEM_ALARM
#define LVR_NET_LOG_ALARM_ALARM						0x0001  // 报警输入
#define LVR_NET_LOG_ALARM_VIDEO_LOSS				0x0002	// 视频丢失				
#define LVR_NET_LOG_ALARM_UNKNOW					0x00FF	// 未知报警类型				

// LVR_NET_SYSTEM_OPERATE
#define LVR_NET_LOG_SYSTEM_POWERON					0x0001	// 系统开始  
#define LVR_NET_LOG_SYSTEM_REBOOT					0x0002	//系统重启
#define LVR_NET_LOG_SYSTEM_POWEROFF					0x0003	//系统关机  
#define LVR_NET_LOG_SYSTEM_UPDATE					0x0004	//系统升级  
#define LVR_NET_LOG_NET_SYSTEM_UPGRADE				0x0005	//网络升级开始  
#define LVR_NET_LOG_USER_LOGIN						0x0006	//用户登录  
#define LVR_NET_LOG_USER_LOGOUT						0x0007	//用户登出  
#define LVR_NET_LOG_HARDDISK_FORMAT					0x0008	//硬盘格式化  
#define LVR_NET_LOG_CONFIG_RESTORE					0x0009	//恢复默认 
#define LVR_NET_LOG_BACKUP_RECORD_FILE				0x000A	//录像备份  
#define LVR_NET_LOG_SEGMENT_RECORD_PLAY				0x000B	//录像回放  
#define LVR_NET_LOG_NET_FILE_DOWNLOAD				0x000C	//录像网络下载  
#define LVR_NET_LOG_RECORD_CONTROL					0x000D	//录像控制  
#define LVR_NET_LOG_ALARM_INPUT_CONTROL				0x000E	//报警控制  
#define LVR_NET_LOG_ABNORMAL_SHUTDOWN				0x000F	//非正常关机  
#define LVR_NET_LOG_SYSTEM_OPERATE_UNKNOW			0xFF	//未知系统操作
//LVR_NET_SYSTEM_CONFIG
#define LVR_NET_LOG_SYSTEM_DATE_TIME				0x0001	//时间设置  
#define LVR_NET_LOG_USER_ACCOUNT					0x0002	//用户管理  
#define LVR_NET_LOG_NET_CONFIG						0x0003	//网络参数  
#define LVR_NET_LOG_NET_PPPOE_CONFIG				0x0004	//拨号设置  
#define LVR_NET_LOG_NET_DDNS_CONFIG					0x0005	//DDNS设置  
#define LVR_NET_LOG_NET_EMAIL_CONFIG				0x0006	//EMAIL设置  
#define LVR_NET_LOG_NET_ACCESS						0x0007	//网络访问权限  
#define LVR_NET_LOG_VIDEO_EFFECT					0x0008	//视频调节  
#define LVR_NET_LOG_RECORD_PLAN_CONFIG				0x0009	//录像计划  
#define LVR_NET_LOG_RECORD_ENCODE_CONFIG			0x000A	//编码参数  
#define LVR_NET_LOG_ALARM_CONFIG					0x000B	//报警参数  
#define LVR_NET_LOG_MOTION_DETECTION_CONFIG			0x000C	//动检设置  
#define LVR_NET_LOG_PTZ_CONFIG						0x000D	//云台参数  
#define LVR_NET_LOG_SYSTEM_CONFIG_UNKNOW			0xFF	//未知系统配置

//LVR_NET_SYSTEM_ERROR
#define LVR_NET_LOG_ALARM_DISK_FULL					0x0001	//录像硬盘满  
#define LVR_NET_LOG_ALARM_NO_DISK					0x0002	//没有硬盘  
#define LVR_NET_LOG_ALARM_DISK_ERROR				0x0003	//硬盘读写错误  
#define LVR_NET_LOG_SYSTEM_ERROR_UNKNOW				0xFF	//未知系统配置

//NTP类型
#define LVR_NTP_NULL							0x00
#define LVR_NTP_NIST							0x01
#define LVR_NTP_ACCN							0x02
#define LVR_NTP_CUSTOM							0x03



//DDNS属性
#define LVR_NET_DOMAIN_CAN_SUBMIT						1 //域名可注册
#define LVR_NET_DOMAIN_CAN_MODIFY						2 //域名可修改
#define LVR_NET_ACCOUNT_CAN_MODIFY						4//帐号可修改 
#define LVR_NET_DDNS_KEEP_ALIVE							8 //域名需保活
#define LVR_NET_POSTFIX_CAN_APPEND						16//后缀可附加
#define LVR_NET_CURRENT_USED_DDNS						64 //当前使用的


//DDNS类型
#define LVR_NET_DDNS_TYPE_NULL						0
#define LVR_NET_DDNS_3322_ORG						1
#define LVR_NET_DDNS_DYNDNS_ORG						2
#define LVR_NET_DDNS_ANYVISION_ORG					3

//NTP服务器类型
#define LVR_NET_NTP_NULL							0
#define LVR_NET_NTP_NIST							1
#define LVR_NET_NTP_ACCN							2
#define LVR_NET_NTP_CUSTOM							3

// LvrNetSetWindowMsg消息类型
#define MSG_EXP_REALPLAY_FAILED					0x1001 // 实时预览初始化异常
#define MSG_EXP_RECORD_CREATE					0x1101 // 录像创建异常
#define MSG_EXP_RECORD_CONFIG					0x1102 // 录像初始化异常
#define MSG_EXP_RECORD_STOP						0x1104 // 码流格式变化,录像停止

#define MSG_EXP_SERVER_CONNECT					0x1501 // 与服务器的连接出现异常
#define MSG_EXP_REALPLAY_CONNECT				0x1502 // 通道连接出现异常
#define MSG_EXP_DATA_RECV						0x1503 // 数据接收出现异常
#define MSG_EXP_CMD_RECV						0x1504 // 命令接收出现异常
#define MSG_EXP_PLAYBACK_RECV					0x1505 // 回放接收出现异常
#define MSG_EXP_DOWNLOAD_RECV					0x1506 // 下载接收出现异常
#define MSG_EXP_UPGRADE_RECV					0x1507 // 升级进度接收失败
#define MSG_EXP_UPGRADE_SEND					0x1508 // 升级发送出现异常

#define MSG_RES_SERVER_CONNECT					0x1601 // 与服务器的连接恢复
#define MSG_RES_REALPLAY_CONNECT				0x1602 // 通道连接恢复

#define MSG_ERR_REALPLAY_NOPRIVI				0x1701 // 视频没有预览权限
#define MSG_ERR_DISCONNECT_SUCCESS				0x1702 // 成功断开连接
#define	MSG_ERR_DISCONNECT_ERROR				0x1703 // 被断开连接失败
#define MSG_ERR_BEENDISCONNECT_SUCCESS			0x1704 // 被断开连接失败
// 回调类型
#define LVR_COMM_ALARM							0x1000 // 报警信息

// 远程回放控制参数
#define LVR_PLAY_START							0x4001 // 开始播放
#define LVR_PLAY_STOP							0x4002 // 停止播放
#define LVR_PLAY_PAUSE							0x4003 // 暂停播放
#define LVR_PLAY_SET_RATE						0x4004 // 设置播放速度
#define LVR_PLAY_GET_RATE						0x4005 // 得到番放速度
#define LVR_PLAY_FRAME							0x4006 // 单帧播放
#define LVR_SET_POS								0x4007 // 设置回放进度
#define LVR_GET_POS								0x4008 // 获取回放进度
#define LVR_GET_FRAMES							0x4009 // 获取已播放的帧数
#define LVR_TOTAL_FRAMES						0x400A // 获取播放文件总帧数
#define LVR_GET_TIME							0x400B // 获取已播放的时间
#define LVR_TOTAL_TIME							0x400C // 获取播放文件总时间


//用户权限
#define	LVR_PRIVI_REC_ENCODE      0          /* 编码设置 */
#define	LVR_PRIVI_SUB_ENCODE      1          /* 子码流 */
#define	LVR_PRIVI_CH_BLEND        2          /* 录像叠加 */
#define	LVR_PRIVI_REC_PLAN        3          /* 录像计划 */
#define	LVR_PRIVI_PTZ_CONFIG      4          /* 云台设置 */
#define	LVR_PRIVI_VIDEO_CONFIG    5          /* 视频设置 */
#define	LVR_PRIVI_MOTION_DETECT   6          /* 移动检测 */
#define	LVR_PRIVI_NET_CONFIG      7          /* 网络设置 */
#define	LVR_PRIVI_PPPOE_CONFIG    8          /* 拨号设置 */
#define	LVR_PRIVI_DDNS_CONFIG     9          /* DDNS设置 */
#define	LVR_PRIVI_EMAIL_CONFIG    10         /* EMAIL设置 */
#define	LVR_PRIVI_NET_ACCESS      11         /* 访问控制 */
#define	LVR_PRIVI_TIME_MACHINE    12         /* 时间编号 */
#define	LVR_PRIVI_DISK_MANAGE     13         /* 硬盘管理 */
#define	LVR_PRIVI_ALARM_CONFIG    14         /* 外部报警 */
#define	LVR_PRIVI_OUTPUT_PLAN     15         /* 输出管理 */
#define	LVR_PRIVI_EXCEPTION_CONFIG 16        /* 异常处理 */
#define	LVR_PRIVI_DISPLAY_CONFIG   17        /* 本地显示 */


#define	LVR_PRIVI_RECORD_CONTROL   0          /* 录像控制 */
#define	LVR_PRIVI_RECORD_BACKUP    1          /* 录像备份 */
#define	LVR_PRIVI_PLAY_CONTROL     2          /* 录像回放 */
#define	LVR_PRIVI_PTZ_CONTROL      3          /* 云台控制 */
#define	LVR_PRIVI_ALARM_CONTROL    4          /* 报警控制 */
#define	LVR_PRIVI_ALARM_CLEAR      5          /* 清除报警 */
#define	LVR_PRIVI_DISPLAY_ADJUST   6          /* 显示调节 */
#define	LVR_PRIVI_LOG_VIEW         7          /* 日志查看 */
#define	LVR_PRIVI_SYSTEM_UPGRADE   8          /* 系统升级 */
#define	LVR_PRIVI_SYSTEM_REBOOT    9          /* 重启系统 */
#define	LVR_PRIVI_SYSTEM_POWEROFF  10         /* 关闭系统 */
#define	LVR_PRIVI_REMOTE_LOGIN     11         /* 远程登录 */
#define	LVR_PRIVI_SYSTEM_ADMIN     12         /* 系统管理 */
#define LVR_PRIVI_ONLINE_USER	   13		  /* 在线用户 */

#define	LVR_PRIVI_CHANNEL_REVIEW   0          /* 通道预览 */

// pDataCallBack实时数据和远程文件回放数据回调
// pBuffer指向标准流数据,dwDataLen数据长度,该指针请不要释放
// 如果是远程回放数据回调,dwDataType为LVR_NET_AUDIOEND、LVR_NET_VIDEOEND表示最后的播放帧
// 如果是远程回放数据已经全部结束时,pBuffer为NULL
// dwTimeStamp是数据时间戳,起始是随机的,1000HZ/秒
// 当该数据为视频时,可以对dwDataFlags使用标志VIDEO_SYSTEM_MASK、ENCODE_FORMAT_MASK获得更多信息
// PAL制式视频分辨率: CIF:352*288 HALF D1:704*288 D1:720*576
// NTSC制式视频分辨率: CIF:352*240 HALF D1:704*240 D1:720*480
#define VIDEO_SYSTEM_MASK		0x0040 // 视频制式 0:PAL 0x40:NTSC
#define ENCODE_FORMAT_MASK		0x0f00 // 编码格式 0x0100:CIF 0x0300:HALF D1 0x0600:D1I(隔行D1) 0x0700:D1P(逐行D1)

typedef void (CALLBACK *pMessageCallBack)(LONG lvrNetHandle, LONG lCommand, CHAR *pBuf, DWORD dwBufLen);
typedef void (CALLBACK *pLvrNetPlayDraw)(LONG lvrHandle, HDC hDC, DWORD dwUser);
typedef void (CALLBACK *pDataCallBack)(LONG lvrHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwDataLen, DWORD dwTimeStamp, DWORD dwDataFlags, DWORD dwUser);
typedef void (CALLBACK *pDevScanCallBack)(CHAR* pBuf);

/* 日期时间 */
typedef struct  {
	DWORD dwYear;				// 年
	DWORD dwMonth;				// 月
	DWORD dwDay;				// 日
	DWORD dwHour;				// 时
	DWORD dwMinute;				// 分
	DWORD dwSecond;				// 秒
}LVR_NET_DATE_TIME, *LPLVR_NET_DATE_TIME;

//SYSTEMINFO中的
//GlobalAbility如果包含GLOBAL_D1_INTERVAL属性则表示D1编码是隔行的ENCODE_D1I，否则是ENCODE_D1P
/* 设备信息 */
typedef struct  {
	BYTE byChannelNum;			// 设备通道数
	BYTE byAlarmInputNum;		// 报警输入数
	BYTE byAlarmOutputNum;		// 报警输出数
	BYTE byAudioInputNum;		// 音频数
    BYTE byDecodeNum;           // 回放解码数
	BYTE byNetPortNum;			// 网口数
    BYTE byDiskPortNum;         // 硬盘接口数
	BYTE bySpotNum;             // SPOT接口数
	BYTE byMicrophoneNum;		// 麦克风接口数
	BYTE bySDPortNum;			// SD接口数
    BYTE byUSBPortNum;          // USB接口数
    BYTE byCVBSPortNum;         // CVBS接口数
    BYTE byVGAPortNum;          // VGA接口数
    BYTE byHDMIPortNum;         // HDMI接口数
	BYTE byRS232PortNum;		// RS232接口数
	BYTE byRS485PortNum;		// RS485接口数
	DWORD dwAlarmInput;			// 报警支持，位表示对应通道，0：不支持，1：支持
    DWORD dwAlarmOutput;        // 报警输出(位)
	DWORD dwSubStream;			// 子码流支持，位表示对应通道，0：不支持，1：支持
	DWORD dwAudioInput;			// 音频支持，位表示对应通道，0：不支持，1：支持
	DWORD dwNetCameraStream;    // 网络串流(位)
    DWORD dwLocalAbility;       // 设备本地属性 LOCAL_UART_PORT0 ... 
    DWORD dwGlobalAbility;      // 设备全局属性 GLOBAL_D1_INTERVAL ... 
    WORD woMotionCellHorzNum;   // 动检区域水平单元数 
    WORD woMotionCellVertNum;   // 动检区域垂直单元数
	DWORD dwCIFChannel;			// CIF编码支持，位表示对应通道，0：不支持，1：支持
	DWORD dwHalfD1Channel;		// Half D1编码支持，位表示对应通道，0：不支持，1：支持
	DWORD dwFullD1Channel;		// Full D1编码支持，位表示对应通道，0：不支持，1：支持
	DWORD dwHD720PChannel;		// HD 720P编码支持，位表示对应通道，0：不支持，1：支持
	DWORD dwHD1080PChannel;		// HD 1080P编码支持，位表示对应通道，0：不支持，1：支持
    WORD byEncodeFrames[2];     // 编码能力(以CIF计算) 0 NTSC 1 PAL
	BYTE byCIFFrameRate[2];		// CIF编码帧率,分别对应NTSC制和PAL制下的最大帧率
	BYTE byHalfD1FrameRate[2];	// Half D1编码帧率,分别对应NTSC制和PAL制下的最大帧率
	BYTE byFullD1FrameRate[2];	// Full D1编码帧率,分别对应NTSC制和PAL制下的最大帧率
	BYTE byHD720PFrameRate;		// HD 720P编码帧率
	BYTE byHD1080PFrameRate;	// HD 1080P编码帧率
	LVR_NET_DATE_TIME IssueDate;// 发布时间
	WORD woLvrMajorVersion;		// 软件版本号
    WORD woLvrMinorVersion;     // GUI版本号
    WORD woMobileVersion;       // 手机版本号
    WORD woMCUVersion;          // MCU版本号
	WORD woHardwareVersion;	    // 硬件版本号
    WORD woFactoryCode;           // 厂商代码
    BYTE bySerialNumber[16];              /* 序列号 */
//    BYTE byReserve[48];          // 保留
//以下定义在主机3版本及以后才有效
	BYTE byConfigPrivi[32];     // 配置权限 PRIVI_REC_ENCODE ~ PRIVI_DISPLAY_CONFIG
    BYTE byControlPrivi[32];    // 操作权限 PRIVI_RECORD_CONTROL ~ PRIVI_SYSTEM_ADMIN
	BYTE byLiveviewPrivi[32];	// 实时预览，每一位代表一个通道，0为关闭，1为打开
	BYTE byRecordPrivi[32];		// 录像，每一位代表一个通道，0为关闭，1为打开 
	BYTE byPlaybackPrivi[32];	// 录像回放，每一位代表一个通道，0为关闭，1为打开 
	BYTE byRemoteViewPrivi[32];	// 远程预览，每一位代表一个通道，0为关闭，1为打开
}LVR_NET_DEVICE_INFO, *LPLVR_NET_DEVICE_INFO;

/* 视频制式 */
typedef struct  {
	DWORD dwVedioFormat;		// 0:NTSC 1:PAL
}LVR_NET_VEDIO_FORMAT, *LPLVR_NET_VEDIO_FORMAT;

/* 时间格式 */
typedef struct  {	
	BYTE byDateMode;			// 日期显示格式 0:月日年, 1:日月年, 2:年月日
	BYTE byTimeMode;			// 时间格式 0:12小时制, 1:24小时制
//	BYTE byTimeZone;			// 时区
	BYTE byDayLight;			// 夏令时
}LVR_NET_TIME_CONFIG, *LPLVR_NET_TIME_CONFIG;

typedef struct {
    BYTE byNtpType;							// NTP类型 NTP_NULL ~ NTP_CUSTOM
    BYTE byTimeZone;						// 时区
    WORD woUpdatePeriods;					// 更新周期(分钟)
    CHAR chNtpServer[32];		// 自定义NTP服务器
    WORD byNtpPort;							// 自定义NTP服务器端口
	BYTE byReserve[2];
} LVR_NET_NTP_CONFIG, *LPLVR_NET_PNTP_CONFIG;

/* 编码参数 */
typedef struct  {
	BYTE byEncodeFormat;		// 编码格式 ENCODE_FORMAT_CIF~ENCODE_FORMAT_D1P，参见LVR_NET_DEVICE_INFO支持的编码格式
	BYTE byBitrateMode;			// 编码码率 0 : VBR, 1 : CBR
	BYTE byEncodeQuality;		// 编码质量 0~5,0：最差，5：最好
	BYTE byFramesRate;			// 帧率，0：最大帧率，参见LVR_NET_DEVICE_INFO对应编码格式的帧率范围
	BYTE byEncodeAudio;			// 音频编码，参见LVR_NET_DEVICE_INFO支持的音频通道
	BYTE byAlarmPreRec;			// 报警预录像
	BYTE byDigitalWatermark;	// 数字水印 0 关闭; 1 打开 */
	BYTE Reserve[5];			// 保留
}LVR_NET_ENCODE_CONFIG, *LPLVR_NET_ENCODE_CONFIG;

/* 子码流参数 */
typedef struct {
	BYTE byEncodeFormat;		// 编码格式 ENCODE_FORMAT_CIF
	BYTE byEncodeQuality;		// 编码质量 0~5, 0：最差，5：最好
	BYTE byEncodeFrames;		// 帧率 0~5, 0:默认帧率
	BYTE Reserve[5];				// 保留
}LVR_NET_SUB_ENCODE, *LPLVR_NET_SUB_ENCODE;

typedef struct {
	CHAR  ChName[32];      /* 通道名 */
}LVR_NET_CHANNEL_NAME, *LPLVR_NET_CHANNEL_NAME;


/* 叠加位置 */
typedef struct  {
	BYTE byTitlePostion;		// 通道名叠加位置 0:左上， 1：左， 2：左下， 3：上， 4：中， 5：下， 6：右上， 7：右， 8：右下
	BYTE byTimePostion;			// 时间叠加位置  0:左上， 1：左， 2：左下， 3：上， 4：中， 5：下， 6：右上， 7：右， 8：右下
	BYTE byLiveTitlePos;			// 通道名叠加使能
	BYTE byLiveTimePos;			// 时间叠加使能
	BYTE  byReserve[4];
}LVR_NET_BLEND_CONFIG, *LPLVR_NET_BLEND_CONFIG;


typedef struct  {
	BYTE byRecordMode[32];                    /* 录像模式 0 手动; 1 计划 */
    BYTE byStartRecord[32];                   /* 录像控制 0 停止; 1 开启 */
}LVR_NET_RECORD_CONTROL ,*LPLVR_NET_RECORD_CONTROL;


/* 录像方式 */
typedef struct  {
	WORD woRecordCover;			// 录像覆盖方式 0 - 循环覆盖；1 - 硬盘满时停止录像
	WORD woRecordTime;			// 录像打包时间(最大120分钟)
}LVR_NET_RECORD_MODE, *LPLVR_NET_RECORD_MODE;


/* 录像计划(一周7天*24小时) */
typedef struct  {
	BYTE lvrRecordSchedule[7][24]; // 0 不录像; 1 定时录像; 4 动检定时录像; 8 报警定时录像; 16 动检和报警定时录像
}LVR_NET_RECORD_SCHEDULE, *LPLVR_NET_RECORD_SCHEDULE;

/* 通讯参数 */
typedef struct  {
	BYTE woBitRate;				// 速率(bps) 0 - 1200, 1 - 2400, 2 - 4800, 3 - 9600, 4 - 19200, 5 - 38400, 6 - 57600, 7 - 115200
	BYTE byDateBit;				// 数据位 DATABIT_4 ~ DATABIT_8
	BYTE byStartBit;			// 起始位 起始位 1
	BYTE byStopBit;				// 停止位 STOPBIT_1 ~ STOPBIT_2 
	BYTE byDataCheck;			//数据校验 CHECK_NULL ~ CHECK_SPACE */
	BYTE byDataControl;			// 流控 0
	BYTE byReceive[2];				// 接收
}LVR_NET_SERIAL_CONFIG, *LPLVR_NET_SERIAL_CONFIG;

/* 云台参数 */
typedef struct  {
	LVR_NET_SERIAL_CONFIG lvrSerial;	// 通讯参数
	WORD byDevType;						// 设备类型 0 - 无, 1 - PelcoD1, 2 - PelcoD2, 2 - PelcoD3,
	WORD byDevAddress;					// 设备地址 0 ~ 255
}LVR_NET_PTZ_CONFIG, *LPLVR_NET_PTZ_CONFIG;


/* 输出管理 */
typedef struct {
    BYTE  byBeepOutputPlan[24];                /* 蜂鸣器 */
    BYTE  byEmailSendPlan[24];                 /* Email发送 */
    BYTE  byAlarmOutputPlan[24];               /* 报警输出 */
    BYTE  byReserve[24];
} LVR_NET_OUTPUTPLAN, *LPLVR_NET_OUTPUTPLAN;

/* 网络参数 */
typedef struct  {
	BOOL bEnableUPnP;			// UPnP支持
	BOOL bEnableDHCP;			// DHCP支持
	CHAR sEthernetIP[16];		// IP地址
	CHAR sEthernetIPMask[16];	// 子网掩码
	CHAR sGatewayIP[16];		// 网关地址
	CHAR sDNSIP[16];			// DNS地址
	WORD woServerPort;			// 服务器端口
	WORD woHttpPort;			// HTTP端口
	WORD woMobilePort;			// 手机访问端口
	BYTE byMacAdderss[6];		// MAC地址(只读)
}LVR_NET_NETWORK_CONFIG, *LPLVR_NET_NETWORK_CONFIG;

typedef struct  {
	CHAR PPPoEUser[32];			// PPPOE用户名
    CHAR PPPoEPassword[32];		// PPPOE密码
    CHAR sPPPoEIP[16];			// PPPoE IP地址(只读)
    BOOL bStartup;				// 自动启用PPPOE
    BOOL bLinkState;			// PPPoE连接状态
}LVR_NET_PPPOE_CONFIG, *LPLVR_NET_PPPOE_CONFIG;


typedef struct  {
	BOOL bSSLEnable;			// SSL登录
    BOOL bAlarmNotify;			// 发生报警通知 主机版本3以下没有此字段
    BOOL bVideoLossNotify;		// 发生视频丢失通知  主机版本3以下没有此字段
    CHAR RecverEmail1[64];		// 接收方地址
    CHAR RecverEmail2[64];		// 接收方地址
    CHAR SMTPServer[64];		// SMTP服务器
    CHAR SenderEmail[64];		// 发送者地址
    CHAR SenderUser[32];		// 用户名
    CHAR SenderPassword[32];	// 密码
//以下属性在主机版本3及以上才有效
	UINT nSmtpPort;				// SMTP端口 未启动SSL的SMTP默认端口为25，启用SSL的SMTP默认端口为485
}LVR_NET_EMAIL_CONFIG, *LPLVR_NET_EMAIL_CONFIG;

typedef struct {
	DWORD  		byDevType;        		/* 设备类型*/
	DWORD		dwDevIP;				/* 设备IP地址*/
    WORD		dwDevPort;				/* 设备端口号*/
	WORD  		byDevChannelsNum;		/* 设备通道数 */
	DWORD 		woDevSwVersion;			/* LVR版本号 */
	DWORD 		woDevHwVersion;			/* 硬件版本号 */
	CHAR		chDevName[32];			/* 设备名称 */
	BYTE  		byDevSerialNumber[16];  /* 序列号 */
	BYTE  		byDevMacAddr[6];		/*  MAC地址 */
   	BYTE  		byReserve[30];
}LVR_NET_DEVSCAN, *LPLVR_NET_DEVSCAN;

/* DDNS设置 */
typedef struct {
    WORD	 woDDNSFlags;                     /* DDNS属性 DOMAIN_CAN_SUBMIT ~ POSTFIX_CAN_APPEND */
    WORD	 woDDNSType;                      /* DDNS类型 */
    CHAR     DDNSName[32];					  /* DDNS名称 */
    CHAR     DDNSDomainName[64];			  /* DDNS域名 */
    CHAR     DDNSUser[32];					  /* DDNS用户名 */
    CHAR     DDNSPassword[32];				  /* DDNS密码 */
    BYTE	 byCurrentState;                  /* 状态 0 未使用; 1 使用 */
    BYTE	 byKeepAliveTime;                 /* 保活时间(分钟) */
    BYTE	 byMinKeepAlive;                  /* 允许最短时间 */
    BYTE	 byMaxKeepAlive;                  /* 允许最长时间 */
	BYTE	 byReserve[21];
} LVR_NET_DDNS_DATA, *LPLVR_NET_DDNS_DATA;

typedef struct {
  LVR_NET_DDNS_DATA lvrDDNS[MAX_DDNS_NUM];
} LVR_NET_DDNS_CONFIG, *LPLVR_NET_DDNS_CONFIG;

typedef struct  {
	BYTE byAlarmType;					// 报警类型 0:常开(N/O), 1:常闭(N/C)
	WORD woDelayTime;					// 报警自动清除(0 ~ 255秒,0:不清除)
	WORD woAlarmUpload;					// 报警上传 
	BOOL bAlarmBeep;					// 蜂鸣器报警
	BYTE byRecChannel[MAX_CHANNEL_NUM];	// 联动录像通道
	BYTE byAlarmOut[MAX_ALARMOUT_NUM];	// 报警输出通道
// 以下属性主机版本3及以上才有效
	BOOL bAlarmSendMail;
}LVR_NET_ALARM_CONFIG, *LPLVR_NET_ALARM_CONFIG;


/* 报警联动 */
typedef struct {
    BYTE byRelatePtzType;      /* 联动类型 RELATE_NULL ~ RELATE_PATTERN */
    BYTE byRelatePtzNum;      /* 联动参数 */
    BYTE byReserve[2];
} LVR_NET_ALARMPTZRELATEDATA, *LPLVR_NET_ALARMPTZRELATEDATA;

typedef struct {
	LVR_NET_ALARMPTZRELATEDATA alarmPTZRelate[MAX_CHANNEL_NUM];
} LVR_NET_ALARMPTZRELATE, *LPLVR_NET_ALARMPTZRELATE;


typedef struct  {
	BOOL bLossBeep;						// 蜂鸣器报警
	BYTE byAlarmOut[MAX_ALARMOUT_NUM];	// 报警输出通道 0:不输出，1：输出
// 以下属性主机版本3及以上才有效
	BOOL bVideoLossSendMail;            // 邮件发送
}LVR_NET_VIDEO_LOSS, *LPLVR_NET_VIDEO_LOSS;

typedef struct  {
	BOOL bMotionBeep;					// 蜂鸣器报警
	WORD woSensitive;					// 灵敏度 0~4,0 - 最不灵敏, 4 - 最灵敏
	BYTE byHorzCell;					// 动检区域水平块数,32
	BYTE byVertCell;					// 动检区域垂直行数，最大24
//	BYTE byDetectArea[24][32];			// 动检区域设置
	BYTE byDetectArea[32][24];			// 动检区域设置
	BYTE byRecChannel[MAX_CHANNEL_NUM];	// 联动录像通道
	BYTE byAlarmOut[MAX_ALARMOUT_NUM];	// 报警输出通道
// 以下属性主机版本3及以上才有效
	BOOL bMotionSendMail;               // 邮件发送 
}LVR_NET_MOTION_DETECT, *LPLVR_NET_MOTION_DETECT;


typedef struct  {
//	DWORD dwPrivacyMode;				// 模式 0：不启用，1：启用
	BYTE byEncEnable;                   // 编码叠加
    BYTE byLiveEnable;                  // 预览叠加
	WORD woPrivacyPosX;					// 区域起始x坐标
	WORD woPrivacyPosY;					// 区域起始y坐标
	WORD woPrivacyWidth;				// 区域宽度
	WORD woPrivacyHeight;				// 区域高度
	BYTE Reserve[2];
}LVR_NET_PRIVACY_CONFIG, *LPLVR_NET_PRIVACY_CONFIG;

#define MAX_ONLINE_USER						20
enum{
	DVR_CONNECT_PC,
	DVR_CONNECT_MOBILE
};

/* 在线用户 主机版本3及以上才有此功能 */
typedef struct{
	CHAR     sUserName[8];		//名称
	CHAR	 sUserIP[16];			            //IP地址
	UINT	 nUserConnectType;                  //连接方式
	BOOL	 bKillConnect;						//断开连接
} ONLINE_USER, *PONLINE_USER;

typedef struct  {
	DWORD dwUserNum;						// 用户数
	ONLINE_USER lvrUser[MAX_ONLINE_USER];	// 用户列表
}LVR_NET_ONLINE_USER, *LPLVR_NET_ONLINE_USER;
/* 帐号信息 */
typedef struct  {
	CHAR sUserName[8];						// 用户名,最大8位,不足8位时以0结尾
	CHAR sPassword[8];						// 密码,最大8位,不足8位时以0结尾
	BYTE byChannelPrivi[32];				// 通道权限 0 关闭; 1 打开 主机版本3及以上无效
	BYTE byConfigPrivi[32];					// 参数设置权限
	BYTE byControlPrivi[32];				// 控制权限
// 以下属性主机版本3及以上才有效
	BYTE byLiveviewPrivi[32];				// 实时预览，每一位代表一个通道，0为关闭，1为打开
	BYTE byRecordPrivi[32];					// 录像，每一位代表一个通道，0为关闭，1为打开 
	BYTE byPlaybackPrivi[32];				// 录像回放，每一位代表一个通道，0为关闭，1为打开 
	BYTE byRemoteViewPrivi[32];				// 远程预览，每一位代表一个通道，0为关闭，1为打开
}LVR_NET_USER_ACCOUNT, *LPLVR_NET_USER_ACCOUNT;

typedef struct  {
	DWORD dwUserNum;								// 用户数
	LVR_NET_USER_ACCOUNT lvrUser[MAX_ACCOUNT_NUM];	// 用户列表
}LVR_NET_USER_INFO, *LPLVR_NET_USER_INFO;

/* 用户密码 */
typedef struct{
	CHAR sUserName[8];			// 用户名(字母或数字)
	CHAR sOldPassword[8];		// 旧密码(字母或数字)
	CHAR sNewPassword[8];		// 新密码(字母或数字)
}LVR_NET_CHANGE_PASSWORD, *PLVR_NET_CHANGE_PASSWORD;

typedef struct  {
	BYTE  byVideoLoss;			// 视频丢失
	BYTE  byVideoCover;			// 视频遮挡
	BYTE  byMotionDetect;		// 动态检测
	BYTE  byChRecord;			// 通道录像
	DWORD dwEncodeBitRate;		// 编码码率
}LVR_NET_CHANNEL_INFO, LPLVR_NET_CHANNEL_INFO;

typedef struct  {
	DWORD dwDiskState;			// 硬盘状态 0 - 正常, 1 - 休眠, 2 - 未格式化, 3 - 读写错误
	DWORD dwDiskCapacity;		// 总容量(MB)
	DWORD dwFreeSpace;			// 可用容量(MB)
}LVR_NET_HARDDISK_INFO, LPLVR_NET_HARDDISK_INFO;

/* 工作状态 */
typedef struct  {
	LVR_NET_CHANNEL_INFO lvrChannel[MAX_CHANNEL_NUM];	// 通道状态
	LVR_NET_HARDDISK_INFO lvrDisk[MAX_HARDDISK_NUM];	// 硬盘状态
	BYTE byAlarmInput[MAX_ALARMIN_NUM];					// 报警输入状态 0: 无，1：撤防，2：布防，3：报警
	BYTE byAlarmOutput[MAX_ALARMOUT_NUM];				// 报警输出状态 0: 无，1：无输出，2：输出
}LVR_NET_WORKING_STATE, *LPLVR_NET_WORKING_STATE;

/* 报警信息 */
typedef struct {
	WORD woAlarmType; // 类型 1 视频丢失 2 动检 3 视频遮挡 4 外部报警 5 报警输出 6 无硬盘 7 硬盘未格式化 8 硬盘满 9 硬盘错误
	WORD woAlarmState; // 状态 0 停止 1 触发
	BYTE byChannel[MAX_CHANNEL_NUM];		// 通道状态 0:正常，1：报警
	BYTE byAlarmInput[MAX_ALARMIN_NUM];		// 报警输入状态 0:正常，1：触发
	BYTE byAlarmOutput[MAX_ALARMOUT_NUM];	// 报警输出状态 0:关闭，1：启动
	BYTE byDiskState[MAX_HARDDISK_NUM];		// 硬盘状态
}LVR_NET_ALARM_STATE, *LPLVR_NET_ALARM_STATE;

typedef struct  {
	LONG  lChannel;				// 浏览通道号
	DWORD dwLinkMode;			// 通信协议,标志SELECT_SUB_STREAM打开子码流
	HWND  hPlayWnd;				// 显示窗口句柄,为NULL时不显示
}LVR_NET_PREVIEW, *LPLVR_NET_PREVIEW;

typedef struct  {
	float fAlpha;				// 透明度 0.0 ~ 1.0
	DWORD dwUser;				// 用户自定义上下文
	COLORREF crMask;			// 透明颜色
	pLvrNetPlayDraw pPlayDraw;	// 函数指针
}LVR_NET_MIXER, *LPLVR_NET_MIXER;


typedef struct  {
	WORD woType;				// 日志类型
	WORD woOperate;				// 操作类型
	DWORD dwLogCommond;			// 操作命令
	LVR_NET_DATE_TIME logTime;	// 日志时间
	CHAR logString[32];			// 日志信息
}LVR_NET_LOG, *LPLVR_NET_LOG;

typedef struct {
	CHAR sFileName[32];			// 文件名
	DWORD dwFileSize;			// 文件大小
	LVR_NET_DATE_TIME startTime;	// 文件的开始时间
	LVR_NET_DATE_TIME stopTime;		// 文件的结束时间
}LVR_NET_FILE, *LPLVR_NET_FILE;

/* 输出管理 */
typedef struct {
	BYTE byBeeperOutput[24];	// 蜂鸣器输出
	BYTE byEmailSend[24];		// 邮件发送
	BYTE byAlarmOutput[24];		// 报警输出
}LVR_NET_OUTPUT_SCHEDULE, *LPLVR_NET_OUTPUT_SCHEDULE;

/* 报警输入 */
typedef struct  {
	BYTE byInState[MAX_ALARMIN_NUM];		// 0: 撤防, 1: 布防
}LVR_NET_ALARM_INPUT, *LPLVR_NET_ALARM_INPUT;

/* 报警输出 */
typedef struct  {
	BYTE byOutState[MAX_ALARMOUT_NUM];		// 0: 关闭, 1: 打开
}LVR_NET_ALARM_OUTPUT, *LPLVR_NET_ALARM_OUTPUT;

LVR_NET_API BOOL __stdcall LvrNetStartup(void);
LVR_NET_API void __stdcall LvrNetCleanup(void);

LVR_NET_API BOOL __stdcall LvrNetCheckEnv(void);
LVR_NET_API DWORD __stdcall LvrNetGetLastError(void);

LVR_NET_API BOOL __stdcall LvrNetConnectTimes(DWORD dwWaitTime, DWORD dwTryTimes);
LVR_NET_API BOOL __stdcall LvrNetSetWindowMsg(HWND hWnd, UINT nMsg);
LVR_NET_API BOOL __stdcall LvrNetSetCallback(pMessageCallBack pUserCallback);

LVR_NET_API BOOL __stdcall LvrNetGetIPByDDNS(CHAR *sDDNS, WORD woDDNSPort, CHAR *sDomainName, WORD woDomainNameLen, CHAR *sGetIP);
LVR_NET_API LONG __stdcall LvrNetLogin(CHAR *sServerIP, WORD woServerPort, CHAR *sUserName, CHAR *sUserPassword, LPLVR_NET_DEVICE_INFO pDeviceInfo);
LVR_NET_API BOOL __stdcall LvrNetLogout(LONG lvrNetHandle, BOOL ActiveDisconnect);

LVR_NET_API BOOL __stdcall LvrNetSetConfig(LONG lvrNetHandle, DWORD dwCommand, LONG lChannel, LPVOID pSetBuffer, DWORD dwBufferSize);
LVR_NET_API BOOL __stdcall LvrNetGetConfig(LONG lvrNetHandle, DWORD dwCommand, LONG lChannel, LPVOID pGetBuffer, DWORD dwBufferSize, LPDWORD pBytesReturned);

LVR_NET_API BOOL __stdcall LvrNetGenKeyFrame(LONG lvrNetHandle, LONG lChannel);
LVR_NET_API BOOL __stdcall LvrNetGenSubKeyFrame(LONG lvrNetHandle, LONG lChannel);

LVR_NET_API LONG __stdcall LvrNetRealPlay(LONG lvrNetHandle, LPLVR_NET_PREVIEW lvrPreview);
LVR_NET_API BOOL __stdcall LvrNetRealDataCallBack(LONG lvrRealHandle, pDataCallBack pUserCallback, DWORD dwUser);
LVR_NET_API BOOL __stdcall LvrNetStopRealPlay(LONG lvrRealHandle);

LVR_NET_API BOOL __stdcall LvrNetSetPlayBuffer(LONG lvrRealHandle, DWORD dwBufferNum);

LVR_NET_API BOOL __stdcall LvrNetOpenSound(LONG lvrHandle);
LVR_NET_API BOOL __stdcall LvrNetCloseSound(LONG lvrHandle);

LVR_NET_API LONG __stdcall LvrNetStartVoiceCom(LONG lvrNetHandle);
LVR_NET_API BOOL __stdcall LvrNetStopVoiceCom(LONG lVoiceComHandle);
LVR_NET_API BOOL __stdcall LvrNetSetVoiceComClientVolume(LONG lVoiceComHandle, LONG lVolume);

LVR_NET_API BOOL __stdcall LvrNetSetVolume(LONG lvrHandle, LONG lBalance, LONG lVolume);
LVR_NET_API BOOL __stdcall LvrNetGetVolume(LONG lvrHandle, LONG *pBalance, LONG *pVolume);

LVR_NET_API	BOOL __stdcall LvrNetPlayMixer(LONG lvrHandle, LPLVR_NET_MIXER lvrMixer);
LVR_NET_API	BOOL __stdcall LvrNetCaptureImage(LONG lvrHandle, CHAR *pImageFile);

LVR_NET_API BOOL __stdcall LvrNetStartSave(LONG lvrRealHandle, CHAR *pFileName);
LVR_NET_API BOOL __stdcall LvrNetStopSave(LONG lvrRealHandle);

LVR_NET_API BOOL __stdcall LvrNetGetDVRWorkState(LONG lvrNetHandle, LPLVR_NET_WORKING_STATE pState);
LVR_NET_API BOOL __stdcall LvrNetRemoteFormatDisk(LONG lvrNetHandle, LONG lDiskNumber);

LVR_NET_API BOOL __stdcall LvrNetGetOnlineUserInfo(LONG lvrNetHandle, LPLVR_NET_ONLINE_USER pGetInfo);
LVR_NET_API BOOL __stdcall LvrNetDisconnectOnlineUser(LONG lvrNetHandle, LPLVR_NET_ONLINE_USER pGetInfo);

LVR_NET_API BOOL __stdcall LvrNetSetAlarmInput(LONG lvrNetHandle, LPLVR_NET_ALARM_INPUT pInput);
LVR_NET_API BOOL __stdcall LvrNetGetAlarmInput(LONG lvrNetHandle, LPLVR_NET_ALARM_INPUT pInput);

LVR_NET_API BOOL __stdcall LvrNetSetAlarmOutput(LONG lvrNetHandle, LPLVR_NET_ALARM_OUTPUT pOutput);
LVR_NET_API BOOL __stdcall LvrNetGetAlarmOutput(LONG lvrNetHandle, LPLVR_NET_ALARM_OUTPUT pOutput);

LVR_NET_API BOOL __stdcall LvrNetSetRecordControl(LONG lvrNetHandle, LPLVR_NET_RECORD_CONTROL pInPut);
LVR_NET_API BOOL __stdcall LvrNetGetRecordControl(LONG lvrNetHandle, LPLVR_NET_RECORD_CONTROL pOutPut);

LVR_NET_API BOOL __stdcall LvrNetSetVideoEffect(LONG lvrRealHandle, DWORD dwBrightness, DWORD dwContrast, DWORD dwSaturation, DWORD dwHue);
LVR_NET_API BOOL __stdcall LvrNetGetVideoEffect(LONG lvrRealHandle, DWORD *pBrightness, DWORD *pContrast, DWORD *pSaturation, DWORD *pHue);

LVR_NET_API BOOL __stdcall LvrNetRemoteKeyControl(LONG lvrNetHandle, LONG lKeyValue);
LVR_NET_API BOOL __stdcall LvrNetRemoteRecControl(LONG lvrNetHandle, LONG lChannel, LONG lRecordType);

LVR_NET_API BOOL __stdcall LvrNetRealPTZControl(LONG lvrRealHandle, DWORD dwCommand, BOOL bStop);
LVR_NET_API BOOL __stdcall LvrNetRealPTZControlWithSpeed(LONG lvrRealHandle, DWORD dwCommand, BOOL bStop, DWORD dwSpeed);
LVR_NET_API BOOL __stdcall LvrNetRealPTZPreset(LONG lvrRealHandle, DWORD dwCommand, DWORD dwPresetNumber);
LVR_NET_API BOOL __stdcall LvrNetRealPTZTrack(LONG lvrRealHandle, DWORD dwCommand);

LVR_NET_API BOOL __stdcall LvrNetPTZControl(LONG lvrNetHandle, LONG lChannel, DWORD dwCommand, BOOL bStop);
LVR_NET_API BOOL __stdcall LvrNetPTZControlWithSpeed(LONG lvrNetHandle, LONG lChannel, DWORD dwCommand, BOOL bStop, DWORD dwSpeed);
LVR_NET_API BOOL __stdcall LvrNetPTZPreset(LONG lvrNetHandle, LONG lChannel, DWORD dwCommand, DWORD dwPresetNumber);
LVR_NET_API BOOL __stdcall LvrNetPTZTrack(LONG lvrNetHandle, LONG lChannel, DWORD dwCommand);

LVR_NET_API LONG __stdcall LvrNetFindFile(LONG lvrNetHandle, LONG lChannel, DWORD dwFileType, BOOL bPlayback, LPLVR_NET_DATE_TIME pStart, LPLVR_NET_DATE_TIME pStop);
LVR_NET_API BOOL __stdcall LvrNetFindNextFile(LONG lvrFileHandle, LPLVR_NET_FILE pLvrFile);
LVR_NET_API BOOL __stdcall LvrNetFindFileClose(LONG lvrFileHandle);

LVR_NET_API LONG __stdcall LvrNetPlayByFile(LONG lvrNetHandle, CHAR *pFile, HWND hPlayWnd);
LVR_NET_API BOOL __stdcall LvrNetPlayControl(LONG lvrPlayHandle, DWORD dwCommand, LPARAM lParam);
LVR_NET_API BOOL __stdcall LvrNetPlayDataCallBack(LONG lvrPlayHandle, pDataCallBack pUserCallback, DWORD dwUser);
LVR_NET_API BOOL __stdcall LvrNetPlayClose(LONG lvrPlayHandle);

LVR_NET_API LONG __stdcall LvrNetStreamDataPlay(HWND hPlayWnd, DWORD dwReserve);
LVR_NET_API BOOL __stdcall LvrNetStreamDataInput(LONG lvrStreamHandle, BYTE *pBuffer, DWORD dwDataLen, DWORD dwTimeStamp, DWORD dwDataFlags);
LVR_NET_API BOOL __stdcall LvrNetStreamPlayClose(LONG lvrStreamHandle);

LVR_NET_API LONG __stdcall LvrNetGetFileByName(LONG lvrNetHandle, CHAR *pGetFile, CHAR *pSaveFile);
LVR_NET_API BOOL __stdcall LvrNetStopGetFile(LONG lvrGetHandle);
LVR_NET_API LONG __stdcall LvrNetGetFilePos(LONG lvrGetHandle);

LVR_NET_API LONG __stdcall LvrNetFindLog(LONG lvrNetHandle, DWORD dwLogType, LPLVR_NET_DATE_TIME pStart, LPLVR_NET_DATE_TIME pStop);
LVR_NET_API BOOL __stdcall LvrNetFindNextLog(LONG lvrLogHandle, LPLVR_NET_LOG pLvrLog);
LVR_NET_API BOOL __stdcall LvrNetFindLogClose(LONG lvrLogHandle);

LVR_NET_API LONG __stdcall LvrNetUpgrade(LONG lvrNetHandle, CHAR *pFileName);
LVR_NET_API LONG __stdcall LvrNetGetUpgradeState(LONG lvrUpgradeHandle, LONG *pComplete);
LVR_NET_API BOOL __stdcall LvrNetStopUpgrade(LONG lvrUpgradeHandle);

LVR_NET_API BOOL __stdcall LvrNetPlaySwitch(LONG lvrNetHandle, DWORD LiveCh, DWORD PlayCh);

LVR_NET_API BOOL __stdcall LvrNetRebootDevice(LONG lvrNetHandle);
LVR_NET_API BOOL __stdcall LvrNetShutdownDevice(LONG lvrNetHandle);

LVR_NET_API BOOL __stdcall LvrNetStartScanDevice(pDevScanCallBack pUserCallback);
LVR_NET_API BOOL __stdcall LvrNetStopScanDevice(void);

LVR_NET_API DWORD __stdcall LvrNetGetSdkVersion(void);

#endif // #ifndef __LVR_NET_SDK_H__
