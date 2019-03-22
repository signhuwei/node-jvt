//
//  "$Id: NetIPOperation.h 4 2009-06-11 13:01:43Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
// 	Description:	
// 	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:			网络操作码Json格式交换
//

#ifndef __EXCHANGE_AL_NETPLATFORM_OPERATION_H__
#define __EXCHANGE_AL_NETPLATFORM_OPERATION_H__

#include "Types/Defs.h"
#include "NetWorkExchange.h"

struct CONFIG_NET_MEGA
{
	bool bEnable;
	bool bNetManEnable;
	IPAddress ServerIP;
	int iServerPort;
	char sDeviceId[32];
	char sUserName[24];
	char sPasswd[32];
	int iMaxCon;
	int iVideoPort;
	int iAudioPort;
	int iMsgPort;
	int iUpdatePort;
};

struct MegaMotion
{
	/*Rect*/RECT mRect[MAX_COVER_COUNT];
};

struct MegaMotionAll
{
	MegaMotion MotionRect[N_SYS_CH];
};


// 新望平台
struct CONFIG_NET_XINWANG
{
	bool bEnable;
	bool bSyncTime;
	bool bSubStream;
	IPAddress ServerIP;
	int iServerPort;
	int iDownLoadPort;
	char sPasswd[32];
	char szSID[32];
};

// 视搜平台
struct CONFIG_NET_SHISOU
{
	bool bEnable;
	RemoteServerConfig Server;
	char szSID[MAX_USERNAME_LENGTH];
};

// 北京鸿泰恒平台
struct CONFIG_NET_BJHONGTAIHENG
{
	bool bEnable;
	char ServerUrl[64]; //服务器地址
	char DevID[16];     //设备id
	char Password[16];  //设备验证码
	char DevModel[16];     //设备型号
	char SerialNo[20]; //设备序列号	
};

// VVEYE平台
struct CONFIG_NET_VVEYE
{
	bool bEnable;                
	bool bCorpEnable;            //只有在使用企业服务器时才需要设置Server
	RemoteServerConfig Server;
	char szDeviceName[MAX_USERNAME_LENGTH];
};

//WELLSUN平台
struct CONFIG_NET_WELLSUN
{
	bool bEnable;
	RemoteServerConfig Server;
	unsigned int    uiDevID;            //device id
	int nGPSHeartBeat;                  //gps hearbeat
	int nSysHeartBeat;                  //svr hearbeat
};

// 楠瑞平台
struct CONFIG_NET_NANRUI
{
	bool bEnable;
	RemoteServerConfig Server;
	char szSID[MAX_USERNAME_LENGTH];
};

//温州凯能平台
/***用户信息***/ 
typedef union {	//IP addr
	unsigned char	c[4];
	unsigned short	s[2];
	uint	l;
}LOCALSDK_IPAddress;

struct CONFIG_KAINENG_USERINFO
{
	char szUserName[16];           //用户姓名：5个汉字或十个字母;
	char szUserAddr[128];          //用户地址：30个汉字或60个字母;
	char szUserAttr[16];           //用户性质：5个汉字或十个字母；
	
	char szBelongUnit[64];         //归管单位：15个汉字或30个字母;
	char szBelongUnitPhone[16];    //归管单位电话：14位数字；分机用"-" 隔离符;
	
	char szPoliceUnit[64];         //出警单位：15个汉字或30个字母;
	char szPoliceUnitAddr[128];    //出警单位地址：30个汉字或60个字母;
	char szPoliceUnitPhone[16];    //出警单位电话：14位数字；分机用"-"隔离符;
	
	char szPolicePhone[4][16];
	char szPolOrCenPhone[2][16];   //警联/中心电话1、2：14位数字；分机用"-" 隔离符;

	char szFTP[64];                //FTP：50个字符；
	char szEMail[64];              //E-Mail: 50个字符；
	LOCALSDK_IPAddress PoliceIP;   //接警中心IP地址
	int nHttpPort;                 //接警中心IP端口
};

/***设备信息***/
//闲置布防类型枚举
typedef enum GuardType
{
	FORBID = 0,      //禁止
	TEN_MIN,         //十分钟
	THIRTY_MIN,      //三十分钟
	SIXTY_MIN,       //六十分钟
	MAX,
}GUARDTYEP;

struct CONFIG_KAINENG_DEVINFO
{
	char ProbeNum1;                //条件布防：两个下拉框，每个下拉框从 1号到10号探测器选择 ；默认两个为 <1号探测器>
	char ProbeNum2;                //条件布防：两个下拉框，每个下拉框从 1号到10号探测器选择 ；默认两个为 <1号探测器>	
	char nProbeType;			   //条件：下拉框 可选择3种为 <禁止>  <AND>  <OR>  默认为 <禁止>
	char nGuardType;               //闲置布防, 参照GUARDTYEP

	int AlarmTime;                //警笛开启时间：三位数字从000-999  默认为：180
	int nGuardArea;               //有线防区类型：八位数字，每位最小0最大3，即00000000 到33333333;  默认：00000000；
	
	char szRemConAddr[4][4];       //遥控器1-4号地址 ：八位16进制字符允许空（即0-9  A-F），默认为空；
	char szLinDevAddr[6][4];       //联运设备地1-6地址：八位16进制字符允许空（即0-9  A-F），默认为空；
	char szProbeAddr[10][4];       //探测器1-10号地址：八位16进制字符允许空（即0-9  A-F），默认为空；
	
	//定时布撤防
	char szGuardTime[3][9];        //定时布撤防,每组都为char [8] 类型 即00 00 00 00，表达由开始时分到结束时分，不需要年月日期
};


/***联动设置***/
//联动动作枚举
typedef enum KNAlarmLink
{
	LINK_EMPTY = 0,
	LINK_SWITH,
	LINK_10S,
	LINK_30S,
	LINK_60S,
	LINK_200S,
	LINK_600S,
	LINK_METHOD_1,
	LINK_METHOD_2,
	LINK_MAX,
}KNALARMLINK;

struct CONFIG_KAINENG_LINKINFO
{
	char eLink[10][7];        //联动设置,取值为联动动作枚举
};

//凯能定制，3个界面信息全在这里。
struct CONFIG_KAINENG_INFO
{
	CONFIG_KAINENG_USERINFO UserInfo;
	CONFIG_KAINENG_DEVINFO DevInfo;
	CONFIG_KAINENG_LINKINFO LinkInfo;
};

//凯能回调结构体
typedef struct 
{	
	CONFIG_KAINENG_DEVINFO DevInfo;
	CONFIG_KAINENG_LINKINFO LinkInfo;
}LOCALSDK_CBCONFIG_KAINENG_INFO;
#endif
