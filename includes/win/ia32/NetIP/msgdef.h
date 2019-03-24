/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * - _explain_
 *
 * Copyright (C) 2005 JUFENG Technologies, All Rights Reserved.
 *
 * $Id: MsgDef.h 1823 2011-07-28 14:01:01Z renxusheng $
 *
 *  Explain:
 *     -explain-
 */
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

#ifndef _MSGDEF_H
#define _MSGDEF_H

#if defined(WIN32)
#pragma pack()
#endif

#include "../Types/Types.h"

#define MSG_VERSION		(0x01)
#define MSG_HEADFLAG	(0xFF)

#define MSG_HEAD_LEN   (sizeof(DVRIP_MSG_HEAD_T))
#define MAX_MSG_DATA_LEN	(64*1024)

typedef struct netipmsg_h
{
	uchar		HeadFlag;		/* head flag = 0xFF */
	uchar		Version;			/* version  */
	uchar		Reserved1;		/* reserved1 */
	uchar		Reserved2;		/* reserved2 */
	uint		SID;					/* session ID */
	uint		Seq;					/* sequence number */
	union
	{
		struct
		{
			uchar		TotalPacket;	/* total packet */
			uchar		CurPacket;		/* current packet */
		}
		#ifdef LINUX
		__attribute__((packed))
		#endif
		c;
		
		struct
		{
			uchar		Channel;			/* channel */
			uchar		EndFlag;			/* end flag */
		}
		#ifdef LINUX
		__attribute__((packed))
		#endif
		m;
	}
	#ifdef LINUX
	__attribute__((packed))
	#endif
	;
	unsigned short		MsgId;			/* mesage id */
	uint		DataLen;			/* data len */
}DVRIP_MSG_HEAD_T;

#if defined(WIN32)
#pragma warning (disable : 4200)
#endif

typedef enum ret_code
{
	OK = 100,
	UNKNOWNERROR = 101,		/// 未知错误
	NOTSUPPORT = 102,		/// 版本不支持
	NOTVALID = 103,			/// 非法请求
	LOGINED = 104,			/// 该用户已经登录
	UNLOGINED = 105,		/// 该用户未登录
	USERORPWDERROR = 106,	/// 用户名密码错误
	NOPOWER = 107,			/// 无权限
	TIMEOUT = 108,			/// 超时
	NOTFOUND = 109,			/// 查找失败，没有找到对应文件
	FOUND = 110,			/// 查找成功，返回全部文件
	FOUNDPART = 111,		/// 查找成功，返回部分文件
	USEREXIST = 112,		/// 该用户已经存在
	USENOTEXIST = 113,		/// 该用户不存在
	GROUPEXIST = 114,		/// 该用户组已经存在
	GROUPNOTEXIST = 115,	/// 该用户组不存在
	PIRATESOFTWARE = 116,	/// 盗版软件
	NEEDREBOOT = 150,		/// 成功，设备需要重启
	NETIP_ERR_MSGFORMATERR = 117,	///< 消息格式错误
	NETIP_ERR_NOPTZPROTOCOL = 118,	///< 未设置云台协议
	NETIP_ERR_NOFILEFOUND = 119,	///< 没有查询到文件
	CONFIG_NOT_ENABLE = 120,	    ///< 配置为启用
	MEDIA_CHN_NOTCONNECT = 121,			//数字通道未连接
	NATCONNET_REACHED_MAX=122,//Nat视频链接达到最大，不允许新的Nat视频链接
	TCPCONNET_REACHED_MAX=123,//Tcp视频链接达到最大，不允许新的Tcp视频链接
}RET_CODE;

//消息类型定义
typedef enum ctrl_msg
{
//C1: 登录,登出,保活
#ifdef _NETIP_PROTOCOL_SPECIAL
	LOGIN_REQ	= 999,
#else
	LOGIN_REQ	= 1000,
#endif
	LOGIN_RSP	= 1001,
	LOGOUT_REQ = 1002,
	LOGOUT_RSP = 1003,
	FORCELOGOUT_REQ = 1004,
	FORCELOGOUT_RSP	= 1005,
	KEEPALIVE_REQ	= 1006,
	KEEPALIVE_RSP	= 1007,

	LOGIN_DAS_REQ	= 1008,
	LOGIN_DAS_RSP	= 1009,

//C2: 系统信息,存储信息
	SYSINFO_REQ	= 1020,
	SYSINFO_RSP	= 1021,

//C3: 编码配置, 遮挡,叠加,图像颜色
//C4: 录像设置
//C5: 动检,遮挡,视频丢失,外部告警,网络告警,存储告警
//C6: 通用网络配置,网络服务配置
//C7: 串口配置
//C8: 云台配置,预置点,巡航
//C9: 本地轮巡,TV调解,视频输入,输出,音频输入
//C10: 通用配置,本地化配置
//C11: 自动维护
	CONFIG_SET = 1040,
	CONFIG_SET_RSP = 1041,
	CONFIG_GET = 1042,
	CONFIG_GET_RSP = 1043,
	DEFAULT_CONFIG_GET = 1044,
	DEFAULT_CONFIG_GET_RSP = 1045,
	CONFIG_CHANNELTILE_SET = 1046,
	CONFIG_CHANNELTILE_SET_RSP = 1047,
	CONFIG_CHANNELTILE_GET = 1048,
	CONFIG_CHANNELTILE_GET_RSP = 1049,

	CONFIG_CHANNELTILE_DOT_SET = 1050,
	CONFIG_CHANNELTILE_DOT_SET_RSP = 1051,

	//系统调试
	SYSTEM_DEBUG_REQ = 1052,
	SYSTEM_DEBUG_RSP = 1053,

//C12: 能力级查询
	ABILITY_GET = 1360,
	ABILITY_GET_RSP = 1361,

//C13: 云台控制
	PTZ_REQ	= 1400,
	PTZ_RSP = 1401,

//C14: 监视控制
	MONITOR_REQ	= 1410,
	MONITOR_RSP	= 1411,
	MONITOR_DATA = 1412,
	MONITOR_CLAIM = 1413,
	MONITOR_CLAIM_RSP = 1414,

//C15: 回放控制
	PLAY_REQ = 1420,
	PLAY_RSP = 1421,
	PLAY_DATA = 1422,
	PLAY_EOF = 1423,
	PLAY_CLAIM = 1424,
	PLAY_CLAIM_RSP = 1425,
	DOWNLOAD_DATA = 1426,

//C16: 语音对讲控制
	TALK_REQ = 1430,
	TALK_RSP = 1431,
	TALK_CU_PU_DATA = 1432,
	TALK_PU_CU_DATA = 1433,
	TALK_CLAIM = 1434,
	TALK_CLAIM_RSP = 1435,
	TALK_NVR_TO_IPC_REQ = 1436, //NVR和其连接的前端开始对讲
	TALK_NVR_TO_IPC_RSP = 1437,

//C17: 文件查询包括录像文件,图片文件,日志文件
	FILESEARCH_REQ = 1440,
	FILESEARCH_RSP = 1441,
	LOGSEARCH_REQ = 1442,
	LOGSEARCH_RSP = 1443,
	FILESEARCH_BYTIME_REQ = 1444,
	FILESEARCH_BYTIME_RSP = 1445,

//C18: 系统管理
	SYSMANAGER_REQ = 1450,
	SYSMANAGER_RSP = 1451,

// 系统时间和录像模式查询
	TIMEQUERY_REQ = 1452,
	TIMEQUERY_RSP = 1453,

//C19: 硬盘管理
	DSIKMANAGER_REQ = 1460,
	DSIKMANAGER_RSP	= 1461,

//C20: 用户管理
	FULLAUTHORITYLIST_GET = 1470,
	FULLAUTHORITYLIST_GET_RSP = 1471,
	USERS_GET	= 1472,
	USERS_GET_RSP = 1473,
	GROUPS_GET = 1474,
	GROUPS_GET_RSP = 1475,
	ADDGROUP_REQ = 1476,
	ADDGROUP_RSP = 1477,
	MODIFYGROUP_REQ = 1478,
	MODIFYGROUP_RSP = 1479,
	DELETEGROUP_REQ = 1480,
	DELETEGROUP_RSP = 1481,
	ADDUSER_REQ = 1482,
	ADDUSER_RSP = 1483,
	MODIFYUSER_REQ = 1484,
	MODIFYUSER_RSP = 1485,
	DELETEUSER_REQ = 1486,
	DELETEUSER_RSP = 1487,
	MODIFYPASSWORD_REQ = 1488,
	MODIFYPASSWORD_RSP = 1489,

//C21: 布警/撤警,告警上报
	GUARD_REQ = 1500,
	GUARD_RSP = 1501,
	UNGUARD_REQ	= 1502,
	UNGUARD_RSP = 1503,
	ALARM_REQ	= 1504,
	ALARM_RSP	= 1505,
	NET_ALARM_REQ = 1506,
	NET_ALARM_RSP = 1507,
	ALARMCENTER_MSG_REQ	= 1508,
	
//C22: 系统升级控制
	UPGRADE_REQ = 1520,
	UPGRADE_RSP	 = 1521,
	UPGRADE_DATA = 1522,
	UPGRADE_DATA_RSP = 1523,
	UPGRADE_PROGRESS = 1524,
	UPGRADE_INFO_REQ = 1525,
	UPGRADE_INFO_RSQ = 1526,

//C23: 设备自动搜索
	IPSEARCH_REQ = 1530,
	IPSEARCH_RSP = 1531,
	IP_SET_REQ = 1532,
	IP_SET_RSP = 1533,

//C24: 系统信息导入导出
	CONFIG_IMPORT_REQ = 1540,
	CONFIG_IMPORT_RSP = 1541,
	CONFIG_EXPORT_REQ = 1542,
	CONFIG_EXPORT_RSP = 1543,
	LOG_EXPORT_REQ = 1544,
	LOG_EXPORT_RSP = 1545,

//C25: 网络键盘
	NET_KEYBOARD_REQ = 1550,
	NET_KEYBOARD_RSP = 1551,

//  网络抓拍
	NET_SNAP_REQ = 1560,
	NET_SNAP_RSP = 1561,

	SET_IFRAME_REQ = 1562,
	SET_IFRAME_RSP = 1563,

//  透明串口
	RS232_READ_REQ = 1570,
	RS232_READ_RSP = 1571,
	RS232_WRITE_REQ = 1572,
	RS232_WRITE_RSP = 1573,
	RS485_READ_REQ = 1574,
	RS485_READ_RSP = 1575,
	RS485_WRITE_REQ = 1576,
	RS485_WRITE_RSP = 1577,

	TRANSPARENT_COMM_REQ = 1578,
	TRANSPARENT_COMM_RSP = 1579,
	RS485_TRANSPARENT_DATA_REQ = 1580,
	RS485_TRANSPARENT_DATA_RSP = 1581,
	RS232_TRANSPARENT_DATA_REQ = 1582,
	RS232_TRANSPARENT_DATA_RSP = 1583,

	

//网络登录时间同步
	SYNC_TIME_REQ = 1590,
	SYNC_TIME_RSP = 1591,
	//ui截图
	PHOTO_GET_REQ = 1600,
	PHOTO_GET_RSP = 1601,

//上传数据
	UPLOAD_DATA_START_REQ = 1610,
	UPLOAD_DATA_START_RSP = 1611,
	UPLOAD_DATA_STOP_REQ = 1612,
	UPLOAD_DATA_STOP_RSP = 1613,
/*1614 - 1629预留MSG，区分上传数据类型*/
	VEHICLE_INFO_REQ = 1614,
	VEHICLE_INFO_RSP = 1615,

	RECORD_STATE_REQ = 1616,
	RECORD_STATE_RSP = 1617,

	DIGITCHN_STATE_REQ = 1618,
	DIGITCHN_STATE_RSP = 1619,

	TITLE_INFO_REQ = 1620,
	TITLE_INFO_RSP = 1621,

//人数统计数据
	CPC_DATA_SEARCH_REQ = 1630,
	CPC_DATA_SEARCH_RSP = 1631,
	CPC_DATA_CLEAR_REQ = 1632,
	CPC_DATA_CLEAR_RSP = 1633,
	
//远程搜索
	NET_LOCALSEARCH_REQ = 1634,
	NET_LOCALSEARCH_RSP = 1635,

//邮件测试
	NET_MAILTEST_REQ = 1636,
	NET_MAILTEST_RSP = 1637,

	//手机信息
	PHONE_INFO_SET = 1638,
	PHONE_INFO_SET_RSP = 1639,

	//硬盘信息
	NET_RECORD_INFO_REQ = 1640,
	NET_RECORD_INFO_RSP = 1641,

	//文件操作，包括删除增加文件夹
	NET_FILE_OPRATE_REQ = 1642,
	NET_FILE_OPRATE_RSP = 1643,
	
	//默认配置导出，就出厂的默认的配置
	NET_CUSTOM_CFG_EXPORT_REQ = 1644,
	NET_CUSTOM_CFG_EXPORT_RSP= 1645,
	
	//本地音频文件搜索
	MUSICFILESEARCH_REQ = 1646,
	MUSICFILESEARCH_RSP = 1647,
	
	//本地音频文件播放控制
	MUSICPLAY_REQ = 1648,
	MUSICPLAY_RSP = 1649,
	
	AUTHORIZATION_REQ = 1650,
	AUTHORIZATION_RSQ = 1651,


	FACE_IMAGE_CLAIM      =    2100,   //抓拍图片认领请求
	FACE_IMAGE_CLAIM_RSP  =    2101,   //抓拍图片认领请求响应
	FACE_IMAGE_REQ        =    2102,   //抓拍图片传送请求
	FACE_IMAGE_RSP        =    2103,   //抓拍图片传送请求响应
	FACE_IMAGE_DATA		  =	   2108,   //人脸抓拍图片数据
	
	FACE_WBLIST_CLAIM       =        2104,   //黑白名单认领请求
	FACE_WBLIST_CLAIM_RSP   =        2105,   //黑白名单认领请求响应
	FACE_WBLIST_REQ         =        2106,   //黑白名单传送请求
	FACE_WBLIST_RSP         =        2107,   //黑白名单传送请求响应

	FACE_WBLIST_COMPARE_CLAIM     =  2109,    //黑白名单比对认领请求
	FACE_WBLIST_COMPARE_CLAIM_RSP =  2110,    //黑白名单比对认领请求响应
	FACE_WBLIST_COMPARE_REQ       =  2111,    //黑白名单比对请求
	FACE_WBLIST_COMPARE_RSP       =  2112,    //黑白名单比对请求响应



	 FACE_JPG_WBLIST_DATA_IN		=  2122,    //黑白名单数据导入,通过图片导入方式
	 FACE_JPG_WBLIST_DATA_INRES		=  2123,    //导入响应
	 FACE_JPG_WBLIST_DATA_OUT		=  2124,    //黑白名单数据导出
	 FACE_JPG_WBLIST_DATA_OUTRES	=  2125,    //导出响应

	 FACE_WBLIST_COMPARE_DATA		=  2128,    //比对结果内容

	 FACE_JPG_WBLIST_SNAP_DATA_IN  	=  2130,	//黑白名单数据导入，通过实时抓拍导入
	 FACE_JPG_WBLIST_SNAP_DATA_INRES  =  2131, 	//远程抓拍导入响应

	 FACE_JPG_FEATURE_OUT		=	2134,	//获取人脸特征值
	 FACE_JPG_FEATURE_OUT_RES	=	2135,

	 //车牌识别
	 CAR_JPG_RESULT_CLAIM       =      2200,     //车牌识别图片认领
	 CAR_JPG_RESULT_CLAIM_RSP   =      2201,     //车牌识别图片认领响应
	 CAR_JPG_RESULT_REQ         =      2202,     //车牌识别图片传送请求
	 CAR_JPG_RESULT_RSP         =      2203,     //车牌识别图片传送请求响应
	 CAR_JPG_RESULT_DATA        =      2204,     //车牌识别结果图片数据
}CMSG_TYPE;

#define KeepAliveCircle 20

enum NetOprResult
{
	oprOK = 0, 	/*操作ok，什么也没返回*/
	oprError,	/*操作失败*/
	oprRespData,/*操作ok，返回回复消息*/
	oprResustData,/*操作ok，返回接收结果*/

};

#endif //_MSGDEF_H

