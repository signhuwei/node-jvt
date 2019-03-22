//
//  "$Id: NetWorkExchange.h 18544 2015-12-01 12:03:11Z chenbo $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __EXCHANGE_AL_NETWORK_EXCHANGE_H__
#define __EXCHANGE_AL_NETWORK_EXCHANGE_H__

#include "Types/Defs.h"
#include "ExchangeAL/CommExchange.h"
#include "ExchangeAL/Exchange.h"
#include "ExchangeAL/MediaExchange.h"
#include "PAL/ExDec.h"
#include "PAL/Net.h"
#include <list>

//需要了在加
#if 0
enum NetWorkErrorNo
{
	ACCOUNT_NOT_LOGIN = ERROR_BEGIN_NETCOMMON + 1,
	ACCOUNT_PASSWORD_NOT_VALID = ERROR_BEGIN_NETCOMMON + 2,
	ACCOUNT_USER_NOT_VALID = ERROR_BEGIN_NETCOMMON + 4,
	ACCOUNT_USER_LOCKED = ERROR_BEGIN_NETCOMMON + 5,
	ACCOUNT_USER_IN_BLACKLIST = ERROR_BEGIN_NETCOMMON + 6,
	ACCOUNT_USER_HAS_USED = ERROR_BEGIN_NETCOMMON + 7,
};
#endif 

//结构定义规则统一改为不带前缀的格式

#define  NAME_PASSWORD_LEN  64
#define  DECODER_NAME_LEN	64
#define  EMAIL_ADDR_LEN  64
#define  N_MIN_TSECT 2
#define  N_ALARMSERVERKEY 5
#define  MAX_FILTERIP_NUM 64
#define  MAX_MAC_LEN 32
#define  NAME_TOKEN_LEN 128
#define  NAME_URL_LEN 128
#define  NAME_ID_LEN 64
#define  MAX_POS_FUNC_KEYWORDS 4 //POS功能中最多支持的关键字个数


#ifdef _USE_JVT_CLIENT
#define DEFAULT_TCP_PORT 	36123
#else
#define DEFAULT_TCP_PORT	34567
#endif
	

///< 服务器结构定义
struct RemoteServerConfig
{
	char ServerName[NAME_PASSWORD_LEN];	///< 服务名
	IPAddress ip;						///< IP地址
	int Port;							///< 端口号
	char UserName[NAME_PASSWORD_LEN];		///< 用户名
	char Password[NAME_PASSWORD_LEN];		///< 密码	
	bool Anonymity;							///< 是否匿名登录
};

/// 录象下载策略
enum RecordDownloadPolicy
{
	DOWNLOADING_AT_NORMALSPEED = 0,	//普通下载
	DOWNLOADING_AT_HIGHSPEED,		//高速下载
};

/// 传输策略
enum TransferPolicy
{
	TRANSFER_POLICY_AUTO,		///< 自适应
	TRANSFER_POLICY_QUALITY,	///< 质量优先
	TRANSFER_POLICY_FLUENCY,	///< 流量优先
	TRANSFER_POLICY_TRANSMISSION,///<网传优先
	TRANSFER_POLICY_NR,
};

/// 网络传输协议类型
enum NetTransProtocolType
{
	NET_TRANS_PRO_TCP = 0,
	NET_TRANS_PRO_UDP = 1,
};

///< 普通网络设置
struct NetCommonConfig
{
	char HostName[NAME_PASSWORD_LEN];	///< 主机名
	IPAddress HostIP;		///< 主机IP
	IPAddress Submask;		///< 子网掩码
	IPAddress Gateway;		///< 网关IP
	int HttpPort;			///< HTTP服务端口
	int TCPPort;			///< TCP侦听端口
	int SSLPort;			///< SSL侦听端口
	int UDPPort;			///< UDP侦听端口
	int MaxConn;			///< 最大连接数
	int MonMode;			///< 监视协议 {"TCP","UDP","MCAST",…}
	int MaxBps;				///< 限定码流值
	int TransferPlan;		///< 传输策略 见TransferPolicy
	bool bUseHSDownLoad;	///< 是否启用高速录像下载测率	
	char sMac[MAX_MAC_LEN]; ///< MAC地址
};

struct NetDevList
{
	std::vector<NetCommonConfig> vNetDevList;
};

///< IP权限设置
struct NetIPFilterConfig
{
	bool Enable;		///< 是否开启
	IPAddress BannedList[MAX_FILTERIP_NUM];		///< 黑名单列表
	IPAddress TrustList[MAX_FILTERIP_NUM];		///< 白名单列表
};

///< 组播设置
struct NetMultiCastConfig
{
	bool Enable;		///< 是否开启
	RemoteServerConfig Server;		///< 组播服务器
};

///< pppoe设置
struct NetPPPoEConfig
{
	bool Enable;		///< 是否开启
	RemoteServerConfig Server;		///< PPPOE服务器
	IPAddress addr;		///< 拨号后获得的IP地址
};

///< DDNS设置
struct NetDDNSConfig
{
	bool Enable;	///< 是否开启
	bool Online;		///< 是否在线
	char DDNSKey[NAME_PASSWORD_LEN];	///< DDNS类型名称, 目前有: JUFENG
	char HostName[NAME_PASSWORD_LEN];	///< 主机名
	RemoteServerConfig Server;		///< DDNS服务器
};


enum TransferProtocol
{
	TRANSFER_PROTOCOL_TCP,
	TRANSFER_PROTOCOL_UDP,
	TRANSFER_PROTOCOL_NR,
};


enum TransferProtocol_V2
{
	TRANSFER_PROTOCOL_NETIP,
	TRANSFER_PROTOCOL_ONVIF,
	TRANSFER_PROTOCOL_MAC,
	TRANSFER_PROTOCOL_NAT,
	TRANSFER_PROTOCOL_DAHUA,
	TRANSFER_PROTOCOL_RTSP,
	TRANSFER_PROTOCOL_NR_V2,
	TRANSFER_PROTOCOL_ONVIF_DEFAULT = 128,
	TRANSFER_PROTOCOL_ONVIF_NR_V2,
};

struct LocalSearchInfo//远程搜索协议
{
	int SearchProtocol;//对应TransferProtocol_V2枚举
};

///< 解码器地址设置
struct NetDecorderConfig
{
	bool Enable;						///< 是否开启
	char UserName[NAME_PASSWORD_LEN];	///< DDNS类型名称, 目前有: JUFENG
	char PassWord[NAME_PASSWORD_LEN];	///< 主机名
	char Address[NAME_PASSWORD_LEN];
	int Protocol;
	int Port;							///< 解码器连接端口
	int Channel;						///< 解码器连接通道号
	int Interval;                       ///< 轮巡的间隔时间(s),0:表示永久
};

/// 解码器地址设置
struct NetDecorderConfigAll
{
	NetDecorderConfig vNetDecorderConfig[N_DECORDR_CH];
};


//解码器地址设置v2
struct NetDecorderConfigAll_V2
{
	std::vector<NetDecorderConfig> vNetDecorderVector[N_DECORDR_CH];
};

enum DevType
{
	DEV_TYPE_IPC,
	DEV_TYPE_DVR,
	DEV_TYPE_HVR,
	DEV_TYPE_POEIPC,
	DEV_TYPE_NVR,
	DEV_TYPE_RTSPIPC,
	DEV_TYPE_NR
};


///< 解码器地址设置
struct NetDecorderConfigV3
{
	bool Enable;						///< 是否开启
	char UserName[NAME_PASSWORD_LEN];	///< 
	char PassWord[NAME_PASSWORD_LEN];	///< 
	char Address[NAME_URL_LEN];
	int Protocol;
	int Port;							///< 解码器连接端口
	int Channel;						///< 解码器连接通道号
	int Interval;                       ///< 轮巡的间隔时间(s),0:表示永久
	char ConfName[DECODER_NAME_LEN];	///<配置名称
	int DevType;						///<设备类型
	int StreamType;						///<连接的码流类型CaptureChannelTypes
	char MainRtspUrl[NAME_URL_LEN];		///<rtsp协议时表示前端设备的主码流地址
	char SubRtspUrl[NAME_URL_LEN];		///<rtsp协议时表示前端设备的辅码流地址
};

/*解码器连接类型*/
enum DecorderConnType
{
	CONN_SINGLE = 0, 	/*单连接*/
	CONN_MULTI = 1,		/*多连接轮巡*/
	CONN_TYPE_NR,
};

/*数字通道的配置*/
struct NetDigitChnConfig
{
	bool Enable;		/*数字通道是否开启*/		
	int ConnType;		/*连接类型，取DecoderConnectType的值*/
	int TourIntv;		/*多连接时轮巡间隔*/
	uint SingleConnId;	/*单连接时的连接配置ID, 从1开始，0表示无效*/
	bool EnCheckTime;	/*开启对时*/
	std::vector<NetDecorderConfigV3> vNetDecorderConf; /*网络设备通道配置表*/
};

/*所有数字通道的配置*/
struct NetDecorderConfigAll_V3
{
	NetDigitChnConfig DigitChnConf[N_DECORDR_CH];
};

/*通道模式配置*/
struct NetDecorderChnModeConfig
{
	CAPTURE_TOTAL_HVRCAPV2 	HVRTotalCap;
	int HVRCurCapMode;
};

/*数字通道状态*/
struct NetDecorderChnStatus
{
	char ChnName[CHANNEL_NAME_MAX_LEN];
	char pMaxResName[50];
	char	pCurResName[50];
	char pStatus[50];
};


/*所有数字通道状态*/
struct NetDecorderChnStatusAll
{
	NetDecorderChnStatus ChnStatusAll[MAX_HVR_CHNCAP];
};

//Pos设备类型
enum PosDevType
{
	POS_TYPE_MANY_LINES, //计算完总金额后才把商品信息一起发送过来
	POS_TYPE_ONE_LINE,   //每统计一件商品就把该商品的信息发送过来
	POS_NR
};

// pos相关配置
struct NetPosConfig
{
	bool Enable;		/*pos机通道使能*/
	int Devtype;		//pos机类型
	int Protocol;		//通信协议
	int Port;		//协议端口号
	bool SnapEnable;       //抓拍使能
	int  StartLine;        //对收到的信息从多少行开始显示
	int  WordEncodeType;   //文字编码格式，如枚举值 WordEncode 所示
	bool KeyWordEnable;    //关键字写日志功能使能
	char SearchWrod[MAX_POS_FUNC_KEYWORDS][16]; //需要添加到日志里的单词
	int  HideTime;         //隐藏通道显示的pos信息的时间,单位是秒，0表示不自动隐藏
	int res;		//保留
};
//所有pos机相关配置
struct NetPosConfigAll
{
	NetPosConfig PosConfig[N_SYS_CH];
};

///< 报警中心设置
struct NetAlarmCenterConfig
{
	bool bEnable;		///< 是否开启
	char sAlarmServerKey[NAME_PASSWORD_LEN];	///< 报警中心协议类型名称, 
	///< 报警中心服务器
	RemoteServerConfig Server;	
	bool bAlarm;
	bool bLog;
};

struct NetAlarmServerConfigAll
{
	NetAlarmCenterConfig vAlarmServerConfigAll[MAX_ALARMSERVER_TYPE];
};

///< ftp设置
struct NetFtpServerConfig{
	bool bEnable;        ///< 服务器使能     
	RemoteServerConfig Server;	///< FTP服务器
	char cRemoteDir[MAX_PATH_LENGTH];	///< 远程目录
	int iMaxFileLen;	///< 文件最大长度
};

struct NetFtpAutoUpLoad
{
	bool bEnable;	//在FTP服务器开启的情况下，自动上传视频到FTP服务器使能
	char reserve[31];//保留
};

///< NTP设置
enum ENUM_NTP_SYNC_TYPE
{
	NTP_SYNC_CUSTOM = 13, //客户自己设置NTP服务器
	NTP_SYNC_AUTO   = 14, //使用云服务器作为NTP服务器
};
struct NetNTPConfig
{
	bool Enable;
	RemoteServerConfig Server;
	int UpdatePeriod; ///< 更新周期，单位分钟
	int TimeZone;     ///< 同步方式，如枚举ENUM_NTP_SYNC_TYPE
};

#define  MAX_EMAIL_TITLE_LEN 64
#define  MAX_EMAIL_RECIEVERS  5
///< EMAIL设置
struct NetEmailConfig
{
	///< 是否开启
	bool Enable;
	///< smtp 服务器地址使用字符串形式填充
	///< 可以填ip,也可以填域名
	RemoteServerConfig Server;
	bool bUseSSL;
	///< 发送地址
	char SendAddr[EMAIL_ADDR_LEN];
	///< 接收人地址
	char Recievers[MAX_EMAIL_RECIEVERS][EMAIL_ADDR_LEN];
	///< 邮件主题
	char Title[MAX_EMAIL_TITLE_LEN];
	///< email有效时间
	TimeSection Schedule[N_MIN_TSECT];
};

//抓包配置结构
struct NetSnifferConfig
{
	IPAddress		SrcIP;			//抓包源地址
	int	SrcPort;			//抓包源端口
	IPAddress		DestIP;			//抓包目标地址
	int	DestPort;		//抓包目标端口
} ;

#define MAX_ETH_NUM 4

//DHCP
struct NetDHCPConfig
{
	bool bEnable;
	char ifName[32];
};

/// 所有网卡的DHCP配置
struct NetDHCPConfigAll
{
	NetDHCPConfig vNetDHCPConfig[MAX_ETH_NUM];
};

///< NTP设置
struct NetDNSConfig
{
	IPAddress		PrimaryDNS;
	IPAddress		SecondaryDNS;
};


struct DDNSTypeConfigAll
{
	NetDDNSConfig vDDNSTypeAll[MAX_DDNS_TYPE];
};

///< ARSP(主动注册服务器)设置包括：乐泰DNS
struct NetARSPConfig
{
	bool bEnable;	///< 是否开启
	char sARSPKey[NAME_PASSWORD_LEN];	///< DNS类型名称
	int iInterval;	///< 保活间隔时间
	char sURL[NAME_PASSWORD_LEN];    ///< 本机域名
	RemoteServerConfig Server;		///< DDNS服务器
	int nHttpPort;                  ///< 服务器HTTP端口
};

struct NetARSPConfigAll
{
	NetARSPConfig vNetARSPConfigAll[MAX_ARSP_TYPE];
};

enum Net3GType
{
	WIRELESS_AUTOSEL=0,	    ///< 自动选择
	WIRELESS_TD_SCDMA=1,	///< TD-SCDMA网络
	WIRELESS_WCDMA=2,		///< WCDMA网络
	WIRELESS_CDMA_1X=3,     ///< CDMA 1.x网络
	WIRELESS_EDGE=4,		///< GPRS网络
	WIRELESS_EVDO=5,		///< EVDO网络
	WIRELESS_4G=6,
	WIRELESS_MAX
};

struct Net3GConfig
{
	bool bEnable;			  ///< 无线模块使能标志
	int iNetType;			  ///< 无线网络类型
	std::string strAPN;		  ///< 接入点名称
	std::string strDialNum;   ///< 拨号号码
	std::string strUserName;  ///< 拨号用户名
	std::string strPWD;  	  ///< 拨号密码
	IPAddress addr;			  ///< 拨号后获得的IP地址
};

///< 手机监控设置包括：乐泰DNS
struct NetMoblieConfig
{
	bool bEnable;	///< 是否开启
	RemoteServerConfig Server;		///< 服务器
};

struct NetUPNPConfig
{
	bool bEnable;			  ///< 使能标志
	bool bState;              ///< 状态
	int iHTTPPort;			  ///< HTTP端口
	int iMediaPort;			  ///< 媒体端口
	int iMobliePort;		  ///< 手机监控端口
};

//WIFI
struct NetWifiConfig
{
	bool bEnable;
	std::string strSSID;            //SSID Number
	int nChannel;                   //channel
	std::string strNetType;         //Infra, Adhoc
	std::string strEncrypType;      //NONE, WEP, TKIP, AES
	std::string strAuth;            //OPEN, SHARED, WEPAUTO, WPAPSK, WPA2PSK, WPANONE, WPA, WPA2
	int  nKeyType;                  //0:Hex 1:ASCII
	std::string strKeys;
	IPAddress HostIP;		///< host ip
	IPAddress Submask;		///< netmask
	IPAddress Gateway;		///< gateway
};

// 报警中心消息类型
enum AlarmCenterMsgType
{
	ALARMCENTER_ALARM,
	ALARMCENTER_LOG,
};

// 报警中心消息类型
enum AlarmCenterStatus
{
	AC_START,
	AC_STOP,
};

// 告警中心消息内容
struct NetAlarmCenterMsg
{
	IPAddress HostIP;		///< 设备IP
	int nChannel;           ///< 通道
	int nType;              ///< 类型 见AlarmCenterMsgType
	int nStatus;            ///< 状态 见AlarmCenterStatus
	SystemTime Time;        ///< 发生时间
	std::string strEvent;    ///< 事件
	std::string strSerialID; ///< 设备序列号
	std::string strDescrip;  ///< 描述
};

// RTSP
struct NetRtspConfig
{
	bool bServer;
	bool bClient;
	RemoteServerConfig Server;		///< 服务器模式
	RemoteServerConfig Client;		///< 客户端模式
};

struct DASSerInfo
{
	bool enable;
 	char serAddr[NAME_PASSWORD_LEN];
	int  port;
	char userName[NAME_PASSWORD_LEN];
	char passwd[NAME_PASSWORD_LEN];
	char devID[NAME_PASSWORD_LEN];
};


//手机短信配置
struct NetShortMsgCfg
{
	bool bEnable;       //发送手机短信的功能是否启用
	char pDesPhoneNum[MAX_RECIVE_MSG_PHONE_COUNT][16]; //接收短信的手机号，现支持3个手机号
	int  sendTimes;     //需要向每个手机发送多少次短信
};

//手机彩信配置
struct NetMultimediaMsgCfg
{
	bool bEnable;				// 发送手机彩信的功能是否启用
	char pDesPhoneNum[MAX_RECIVE_MSG_PHONE_COUNT][16]; //接收彩信的手机号，现支持3个手机号
	char pGateWayDomain[40];	// 网关地址，域名或IP
	int  gateWayPort;			// 网关端口
	char pMmscDomain[40];		// 彩信服务器地址，IP或域名
	int  mmscPort;				// 彩信服务器端口号
};


//网络优先级
struct NetOrderConfig
{
	bool         bEnable;          //是否设置网络优先级
	int          netCount;         //网络类型数目
	NetLinkOrder pNetOrder[NM_NR]; //网络优先级
	NetLinkOrder pReserve[7-NM_NR];//给新的网络类型预留
};

//网络平台信息设置
typedef struct LocalSdkNetPlatformConfig
{
	int Enable;
	int nISP;
	char sServerName[32];
	char ID[32];
	char sUserName[32];
	char sPassword[32];
	IPAddress HostIP;		///< host ip
	int port;
}LOCALSDK_NET_PLATFORM_CONFIG;

//神眼接警中心系统
struct	GodEyeConfig
{
	bool	bEnable; 
	char MainServerName[NAME_PASSWORD_LEN]; //主域名
	int MainPort;	//主端口
	char ExServerName[NAME_PASSWORD_LEN]; //备用域名
	int ExPort;	//备用端口
};

enum  DigManagerShowStatus
{
	SHOW_NONE,
	SHOW_ALL,
};


//数字通道显示状态
struct DigitalManagerShow
{
	int  nDigitalManagerShowSta;
};

//NAT使能，MTU值
struct NatConfig
{
	bool bEnable;
	int nMTU;
	char serverAddr[64];  //云服务的域名或者IP地址。
	int  serverPort;      //云服务的端口;
	IPAddress dnsSvr1;//云服务的DNS服务器地址
	IPAddress dnsSvr2;
};

typedef enum 
{
	TimeRec = (int)0x00001,
	AlarmRec = (int)0x00002,
}CloudRecType;

typedef enum 
{
	LocalAlarm = (int)0x00001,
	MotionDetect = (int)0x00002,	
}AlarmRecType;

//云存储配置相关结构体
struct CloudRecordConfig
{
	int EnableMsk;			//0全不存，1是定时存，2报警存，3定时&& 报警
	int StreamType;			//码流类型
	int AlarmRecTypeMsk;	//需要上传录像的报警类型，AlarmRecType类型掩码
	WorkSheet wcWorkSheet;	//普通录像需存储的时间段
};

struct CloudRecordConfigAll
{
	CloudRecordConfig vRecordConfigAll[N_SYS_CH]; 
};

struct VPNConfig
{
	bool Enable;		///< 是否开启
	IPAddress ServiceIp;						///< 服务器IP地址
	char UserName[NAME_PASSWORD_LEN];		///< 用户名
	char Password[NAME_PASSWORD_LEN];		///< 密码	
	IPAddress addr;		///< 拨号后获得的IP地址
	char ServerName[NAME_PASSWORD_LEN];		///< openvpn服务器地址
	int port;
};

struct NetKeyboardConfig
{
	bool Enable;		///< 是否开启
	char sTransProtocol[4];	//传输协议
	int ListenPort;		//监听端口
	char sParserProtocol[32];
	int deviceaddr;	//设备地址
};

void exchangeServer(CKeyExchange& configExchange, CConfigTable& table, RemoteServerConfig& server);


//安徽创世C7平台配置
struct C7PlatformConfig
{
	char pServerAddr[64];//平台地址，IP地址或域名
	int  servPort;       //平台端口
	char pPUID[32];      //PUID
	char pPassword[32];  //密码
	char pStatus[64];    //接入状态，在LocalSDK中是可读可写的，其它地方是只读
	char pResv[60];      //保留
};

//28181协议配置
typedef struct ASB_NET_VSP_CONFIG
{
	bool		bCsEnable;				//使能标记
	char		szCsIP[64];				//服务器地址	(IP)
	short	sCsPort;					//服务器端口
	short	sUdpPort;				//本地服务器udp端口
	char		szServerNo[64];			//服务器编号
	char 	szServerDn[64];			//服务器域名(域名为28181编号)
	char		szDeviceNO[64];			//设备编号
	char 	szConnPass[64];			//设备注册密码
	int		iHsIntervalTime;			//心跳间隔时间,单位是秒
	int		iRsAgedTime;			//注册有效期，单位为秒
	char		Camreaid[N_SYS_CH][64];	//通道编号
	int		CamreaLevel[N_SYS_CH];	//报警级别
	char		Alarmid[N_SYS_CH][64];	//报警编号
	int		AlarmLevel[N_SYS_CH];	//报警级别
	uint		uiAlarmStateGpinEnable;	//外部报警使能
	uint		uiAlarmStateLoseEnable;	//视频丢失告警使能
	uint		uiAlarmStateMotionEnable;//视频动态侦测告警使能
	uint		uiAlarmStateBlindEnable;	//屏幕遮挡告警使能
	uint		uiAlarmStatePerformanceEnable;	//系统异常告警使能
	uint		uiAlarmStateConnectEnable;	//用户连接告警使能
}ASB_NET_VSP_CONFIG;


struct PMSConfig
{
	bool Enable;		///< 是否开启
	char servname[64];		
	int port;
	char boxid[128];
	char resume[24];
};
struct PhoneInfo
{
	char command[NAME_PASSWORD_LEN]; 		///指令
	char type[12];								///使能，客户以字符串形式传过来
	char asid[128];							///手机id	
	char username[NAME_PASSWORD_LEN];		///< 用户名
	char password[NAME_PASSWORD_LEN];		///< 密码	
	char acme[NAME_PASSWORD_LEN];
	char resume[24];
};
struct PhoneAsidList
{
	std::vector<std::string> asidList;
};

typedef struct KaiCongAlarmConfig
{
	bool Enable;		///< 是否开启
	char ServerName[NAME_PASSWORD_LEN];	///< 服务名
	int Port;							///< 端口号
	char UserName[NAME_PASSWORD_LEN];		///< 用户名
	char Password[NAME_PASSWORD_LEN];		///< 密码	
}KaiCongAlarmCfg;

typedef struct XMHeartbeatConfig
{
	bool bEnable;							///< 是否开启
	int iInterval;							///< 保活间隔时间
	char ServerName[NAME_PASSWORD_LEN];	///< 服务名
	int Port;								///< 端口号
	char UserName[NAME_PASSWORD_LEN];		///< 用户名
	char Password[NAME_PASSWORD_LEN];		///< 密码
	char resume[24];
}XMHeartbeatCfg;

struct MonitorPlatformConfig
{
	Bool Enable;		///< 是否开启
	char servname[NAME_PASSWORD_LEN];
	int port;
	char resume[24];
	char agentid[128];	//客户端id，深广平台使用(以SSJC开头)
	char type[128];		//
};

struct DataLinkConfig
{
	Bool DoProgramEnable;
	Bool NIP2Enable;
};

//网络服务定制平台通用配置，以后定制都用这个
typedef struct NetPlatformCommonCfg
{
	Bool	Enable;
	int Port;									///< 端口号
	char ServerName[NAME_PASSWORD_LEN];		///< 服务名
	char ID[NAME_PASSWORD_LEN];	
	char UserName[NAME_PASSWORD_LEN];		///< 用户名
	char Password[NAME_PASSWORD_LEN];		///< 密码
	char resume[128];		///预留
}NetPlatformCommonCfg;

///搜索用
struct NetCommonConfig_V2
{
	char HostName[NAME_PASSWORD_LEN];	///< 主机名
	IPAddress HostIP;		///< 主机IP
	IPAddress Submask;		///< 子网掩码
	IPAddress Gateway;		///< 网关IP
	int HttpPort;			///< HTTP服务端口
	int TCPPort;			///< TCP侦听端口
	int SSLPort;			///< SSL侦听端口
	int UDPPort;			///< UDP侦听端口
	int MaxConn;			///< 最大连接数
	int MonMode;			///< 监视协议 {"TCP","UDP","MCAST",…}
	int MaxBps;				///< 限定码流值
	int TransferPlan;		///< 传输策略 见TransferPolicy
	bool bUseHSDownLoad;	///< 是否启用高速录像下载测率	
	char sMac[MAX_MAC_LEN]; ///< MAC地址
	char sSn[MAX_MAC_LEN]; 	///序列号
	int ChannelNum;			///通道数
	int	DeviceType;			///设备类型，如枚举DevType
	char Resume[56];		///保留
};

struct NetDevList_V2
{
	std::vector<NetCommonConfig_V2> vNetDevList;
};

typedef struct BaiduCloudCfg
{
	bool enable;
	char APIKey[NAME_TOKEN_LEN];				//应用API密钥
	char SecretKey[NAME_TOKEN_LEN];			//应用密钥
	char AuthorizationCode[NAME_TOKEN_LEN];	//授权码
	char accessToken[NAME_TOKEN_LEN];		//访问权限码
	char refreshToken[NAME_TOKEN_LEN];		//刷新权限码
	char deviceID[NAME_TOKEN_LEN];			//设备ID
	char userCode[NAME_TOKEN_LEN];			//用户授权码
	char qrcodeUrl[NAME_TOKEN_LEN];			//二维码
	char streamID[NAME_TOKEN_LEN];			//流ID
	char describe[NAME_TOKEN_LEN];			//设备名称
	int state;								//状态
	SystemTime refreshTime;					//上次刷新Token时间
	std::vector<Bool>	channelMain;				//是否开启标记
	std::vector<Bool>	channelExtra;				//是否开启标记
	int recordFileMode;						//配置录像模式
	int recordFileSize;						//录像文件大小
	int recordFileTime;						//录像最长时间
	char resume[128];							///预留
}BaiduCloudCfg;

//=============================================================================================================
#define DETECT_AREA_NUM		4							//侦测路数
#define MAX_ROI_AREA		8
#define MAX_OVERSTRP_AREA	4

#if 0

//时间: 天
typedef struct DAY_TIME_S
{
	DWORD			week : 5;							//星期
	DWORD			millisec : 10;						//毫秒: 0 ~ 999
	DWORD			second : 6;							//秒:	0 ~ 59
	DWORD			minute : 6;							//分:   0 ~ 59
	DWORD			hour : 5;							//时:	0 ~ 23
}DAY_TIME; 


//时间: 时间段 
typedef struct SEG_TIME_S
{
	BYTE			bEnable;							//是否检测
	BYTE			byTask;								//任务
	BYTE			byRes[2];							//备用
	SDK_DAY_TIME_S		stBgnTime;							//开始时间
	SDK_DAY_TIME_S		stEndTime;							//结束时间
}SEG_TIME; 

//计划时间: 周计划时间
typedef struct SCHWEEK_TIME_S
{
	SDK_SEG_TIME_S		stSegTime[7][4];					//0: 星期天，1: 周一，2: 周二
}SCHWEEK_TIME;


//线
typedef struct LINE_POINT_S
{
	int			x0;									//x0坐标
	int			y0;									//y0坐标
	int			x1;									//x1宽度
	int			y1;									//y1高度
}LINE_POIN;


//矩形区域   rectangle   
typedef struct RECTANGLE_POINT_S
{
	int			x;									//X坐标
	int			y;									//Y坐标
	int			w;									//宽度
	int			h;									//高度
}RECTANGLE_POINT;

//四边形区域 Quadrilateral   
typedef struct QUADRILATERAL_POINT_S
{
	int			x0;									//X0坐标
	int			y0;									//Y0坐标
	int			x1;									//X1坐标
	int			y1;									//Y1坐标
	int			x2;									//X2坐标
	int			y2;									//Y2坐标
	int			x3;									//X3坐标
	int			y3;									//Y3坐标
}QUADRILATERAL_POINT;

//智能编码：
typedef struct SM_AUTOCODEC_CONFIG_S
{
	BYTE bySensitive; // 0  low  1 mid  2 high
	BYTE bySaveCurBitrate;
	BYTE byLowBitrate;
	BYTE byStopTime;
	BYTE byRes[256];
}SM_AUTOCODEC_CONFIG;


typedef struct SM_ROI_CONFIG_S
{
	RECTANGLE_POINT stROIRect; //Roi   area  rect
	INT s32Qp;
	INT dwIndex;
	BYTE byEnable;
	BYTE byAbsQp;
	BYTE byRes[14];
}SM_ROT_CONFIG;

typedef struct SM_SMART_CODEC_CONFIG_S
{
	SM_ROT_CONFIG  stROI[MAX_ROI_AREA];   // 
	SM_AUTOCODEC_CONFIG stAutoCodec;
	BYTE     	 byCodecEnable;  // 0  close,  1  Enable auto update all stream (auto check) ,  2  ROI  (set Rect)
	BYTE 		 byRes1[3];
	BYTE		 byRes[256];	
}SM_SMART_CODEC_CONFIG;


//智能检测：
typedef struct SM_SMART_SHUNTTER_S
{
	BYTE         byshutterEnable;  // 0 close  1 Enable
	BYTE 		 bySensitive;
	BYTE 		 byShowOsd;
	BYTE 		 bySynMotion; //Synchronous motion detecting alarm
	char 		 szOsd[32];
	BYTE		 byRes[256];	
} SM_SMART_SHUNTTER;

typedef struct SM_SMART_OVERSTEP_S
{
	BYTE         byOverStepEnable;  // 0 close  1 Enable
	BYTE 		 bySensitive;
	BYTE 		 byShowOsd;
	BYTE 		 bySynMotion; //Synchronous motion detecting alarm
	RECTANGLE_POINT  stOverStepRect[MAX_OVERSTRP_AREA];
	char 		 szOsd[32];
	BYTE		 byRes[256];	
} SM_SMART_OVERSTEP;


typedef struct SM_SMART_FOCUS_S
{
	BYTE         byAfFocusEnable;  // 0 close  1 Enable
	BYTE 		 bySensitive;
	BYTE 		 byShowOsd;
	BYTE 		 bySynMotion; //Synchronous motion detecting alarm
	DWORD		 dwCurAfVaule;
	DWORD		 dwCurLumaVaule;
	char 		 szOsd[32];
	BYTE		 byAfFocusStudy; // Af Focus Study Again
	BYTE 		 byStudyPresetNum; //Af  Focus Study Preset Num
	BYTE		 byRes1[2];
	BYTE		 byRes[252];	
}SM_SMART_FOCUS;

typedef struct SM_SMART_DETECT_CONFIG_S
{
	SM_SMART_SHUNTTER stSmartShuntter;
	SM_SMART_OVERSTEP stSmartOverStep;	
	SM_SMART_FOCUS	   stSmartFocus;
	BYTE		   byRes[256];
}SM_SMART_DETECT_CONFIG;


//智能控制：
typedef struct SM_SMART_CONTROL_CONFIG_S
{
	BYTE		 bySmartCtlEnable;
	BYTE		 bySmartOpenAlarm;
	BYTE		 bySmartCloseAlarm;
	BYTE		 bySmartCleanHappern;
	BYTE 		 bySmartCleanFlag;
	BYTE		 byRes1[3];
	BYTE		 byRes[512];
} SM_SMART_CONTROL_CONFIG;


//亮度侦测数据结构
typedef struct SM_LUMADETECT_S						//size 512
{
	int	bEnable;									//使能
	int sensitivity;								//阀值
	char res[504];
}SM_LUMADETECT;

//移动侦测数据结构
typedef struct SM_MDDETECT_S
{
	int	bEnable;									//使能
	int sensitivity;								//阀值
	RECTANGLE_POINT	stMDArea[DETECT_AREA_NUM];			//移动侦测区域
	char res[440];
}SM_MDDETECT;

//遮挡侦测数据结构
typedef struct SM_ODDETECT_S
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int sensitivity;								//阀值
	RECTANGLE_POINT	stMDArea[DETECT_AREA_NUM];			//遮挡区域
	char res[432];
}SM_ODDETECT;

//虚拟警戒线数据结构

typedef struct SM_CROSSLINE_S						//512
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int direction[DETECT_AREA_NUM];					//侦测方向
	LINE_POIN	stCrossLine[DETECT_AREA_NUM];  	//侦测虚拟线
	char res[420];
}SM_CROSSLINE;


//区域入侵侦测数据结构
typedef struct SM_CROSSAREA_S						//512
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int direction[DETECT_AREA_NUM];					//侦测方向
	QUADRILATERAL_POINT stCrossArea[DETECT_AREA_NUM];  	//区域
	char  res[356];
} SM_CROSSAREA;

//颜色侦测
typedef struct SM_DETECTCOLOR_S
{
	int	bEnable;									//使能
	int sensitivity;								//阀值
	char res[504];
}SM_DETECTCOLOR;

//声音侦测
typedef struct SM_DETECTSOUND_S
{
	int	bEnable;									//使能
	int aType;
	int sensitivity;								//阀值
	char res[500];
}SM_DETECTSOUND;


//遗留物体侦测数据结构
typedef struct SM_LOSEOBJ_S
{
	int	bEnable;									//使能
	int time;
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int direction[DETECT_AREA_NUM];					//侦测方向
	RECTANGLE_POINT stLoseobjArea[DETECT_AREA_NUM];  	//遗留物体侦测区域
	
	char res[416];
}SM_LOSEOBJ;

#endif




//时间: 天
typedef struct DAY_TIME_S
{
	DWORD			week : 5;							//星期
	DWORD			millisec : 10;						//毫秒: 0 ~ 999
	DWORD			second : 6;							//秒:	0 ~ 59
	DWORD			minute : 6;							//分:   0 ~ 59
	DWORD			hour : 5;							//时:	0 ~ 23
}DAY_TIME; 

//时间: 日期
typedef struct DATE_TIME_S
{
	DWORD			second : 6;							//秒:  0 ~ 59
	DWORD			minute : 6;							//分:  0 ~ 59
	DWORD			hour : 5;							//时:  0 ~ 23
	DWORD			day : 5;							//日:  1 ~ 31
	DWORD			month : 4;							//月:  1 ~ 12
	DWORD			year : 6;							//年:  2000 ~ 2063
}DATE_TIME;

//时间: 时间段 
typedef struct SEG_TIME_S
{
	BYTE			bEnable;							//是否检测
	BYTE			byTask;								//任务
	BYTE			byRes[2];							//备用
	DAY_TIME		stBgnTime;							//开始时间
	DAY_TIME		stEndTime;							//结束时间
}SEG_TIME; 

//计划时间: 周计划时间
typedef struct SCHWEEK_TIME_S
{
	SEG_TIME		stSegTime[7][4];					//0: 星期天，1: 周一，2: 周二
}SCHWEEK_TIME;


//线
typedef struct LINE_POIN_S
{
	int			x0;									//x0坐标
	int			y0;									//y0坐标
	int			x1;									//x1宽度
	int			y1;									//y1高度
} LINE_POIN;


//矩形区域   rectangle   
typedef struct RECTANGLE_POINT_S
{
	int			x;									//X坐标
	int			y;									//Y坐标
	int			w;									//宽度
	int			h;									//高度
}RECTANGLE_POINT;


//区域
typedef struct AREA_RECT_S
{
	short			x;									//X坐标
	short			y;									//Y坐标
	short			w;									//宽度
	short			h;									//高度
}AREA_RECT;

//四边形区域 _CROSS_RECT_S   

//四边形区域 Quadrilateral   
typedef struct QUADRILATERAL_POINT_S
{
	int			x0;									//X0坐标
	int			y0;									//Y0坐标
	int			x1;									//X1坐标
	int			y1;									//Y1坐标
	int			x2;									//X2坐标
	int			y2;									//Y2坐标
	int			x3;									//X3坐标
	int			y3;									//Y3坐标
}QUADRILATERAL_POINT;


//屏蔽
typedef struct SM_CHN_MASK_S
{
	DWORD			dwChns1;							//bit.0 ~ bit.31  表示通道 1  ~ 32
	DWORD			dwChns2;							//bit.0 ~ bit.31  表示通道 33 ~ 64
}SM_CHN_MASK;

//报警联动处理
typedef struct SM_ALARM_HANDLE_S
{
	SM_CHN_MASK		stMaskAlarmOut;						//报警触发设备的输出通道,报警触发的输出,为1表示触发该输出
	DWORD			dwAlarmOutTime;						//报警输出的时间(秒)

	SM_CHN_MASK		stMaskAlarmRec;						//联动录像通道 
	DWORD			dwRecSaveMode;						//bit0: 本地存储(当本地有存储设备时, 此位固定为1)  
	//bit2: ftp上传   
	DWORD			dwRecTime;							//录像的时间(秒)

	SM_CHN_MASK		stMaskAlarmSnap;					//联动抓拍
	DWORD			dwSnapSaveMode;						//bit0: 本地存储(当本地有存储设备时, 此位固定为1)  
	//bit1: email 
	//bit2: ftp上传   

	DWORD			dwSnapNum;							//连续抓拍张数
	DWORD			dwSnapInterval;						//连续抓拍时间间隔(毫秒)  0: 连续抓拍

	DWORD			dwUserData1;						//用户数据1(联动PC录像通道)
	DWORD			dwUserData2;						//用户数据2

	DWORD			dwSnapDealy;						//延迟抓拍

	BYTE			bSendEmail;							//联动发送email
	BYTE			byRes[251];							//备用
}SM_ALARM_HANDLE;

//智能编码：
typedef struct  SM_AUTOCODEC_CONFIG_S
{
	BYTE bySensitive; // 0  low  1 mid  2 high
	BYTE bySaveCurBitrate;
	BYTE byLowBitrate;
	BYTE byStopTime;
	BYTE byRes[256];
} SM_AUTOCODEC_CONFIG;


typedef struct SM_ROI_CONFIG_S
{
	RECTANGLE_POINT stROIRect; //Roi   area  rect
	INT s32Qp;
	INT dwIndex;
	BYTE byEnable;
	BYTE byAbsQp;
	BYTE byRes[14];
}SM_ROT_CONFIG;

typedef struct SM_SMART_CODEC_CONFIG_S
{
	SM_ROT_CONFIG  stROI[MAX_ROI_AREA];   // 
	SM_AUTOCODEC_CONFIG stAutoCodec;
	BYTE     	 byCodecEnable;  // 0  close,  1  Enable auto update all stream (auto check) ,  2  ROI  (set Rect)
	BYTE 		 byRes1[3];
	BYTE		 byRes[256];	
}SM_SMART_CODEC_CONFIG;


//智能检测：
typedef struct SM_SMART_SHUNTTER_S
{
	BYTE         byshutterEnable;  // 0 close  1 Enable
	BYTE 		 bySensitive;
	BYTE 		 byShowOsd;
	BYTE 		 bySynMotion; //Synchronous motion detecting alarm
	char 		 szOsd[32];
	BYTE		 byRes[256];	
} SM_SMART_SHUNTTER;

typedef struct SM_SMART_OVERSTEP_S
{
	BYTE         byOverStepEnable;  // 0 close  1 Enable
	BYTE 		 bySensitive;
	BYTE 		 byShowOsd;
	BYTE 		 bySynMotion; //Synchronous motion detecting alarm
	RECTANGLE_POINT  stOverStepRect[MAX_OVERSTRP_AREA];
	char 		 szOsd[32];
	BYTE		 byRes[256];	
} SM_SMART_OVERSTEP;

typedef struct SM_SMART_FOCUS_S
{
	BYTE         byAfFocusEnable;  // 0 close  1 Enable
	BYTE 		 bySensitive;
	BYTE 		 byShowOsd;
	BYTE 		 bySynMotion; //Synchronous motion detecting alarm
	DWORD		 dwCurAfVaule;
	DWORD		 dwCurLumaVaule;
	char 		 szOsd[32];
	BYTE		 byAfFocusStudy; // Af Focus Study Again
	BYTE 		 byStudyPresetNum; //Af  Focus Study Preset Num
	BYTE		 byRes1[2];
	BYTE		 byRes[252];	
}SM_SMART_FOCUS;

typedef struct SM_SMART_DETECT_CONFIG_S
{
	SM_SMART_SHUNTTER stSmartShuntter;
	SM_SMART_OVERSTEP stSmartOverStep;	
	SM_SMART_FOCUS	   stSmartFocus;
	BYTE		   byRes[256];
} SM_SMART_DETECT_CONFIG;

//智能控制：
typedef struct SM_SMART_CONTROL_CONFIG_S
{
	BYTE		 bySmartCtlEnable;
	BYTE		 bySmartOpenAlarm;
	BYTE		 bySmartCloseAlarm;
	BYTE		 bySmartCleanHappern;
	BYTE 		 bySmartCleanFlag;
	BYTE		 byRes1[3];
	BYTE		 byRes[512];
} SM_SMART_CONTROL_CONFIG;


//detect

//亮度侦测数据结构
typedef struct SM_DETECT_BRIGHTNESS_S						//size 512
{
	int	bEnable;								//使能
	int sensitivity;							//阀值
	SCHWEEK_TIME	stSchTime;					//布防时间
	SM_ALARM_HANDLE	stAlarmHandle;				//报警处理
	char res[368];
}SM_DETECT_BRIGHTNESS;

//移动侦测数据结构
typedef struct SM_DETECT_MOTION_S
{
	int	bEnable;									//使能
	int sensitivity;								//阀值
	RECTANGLE_POINT	stMDArea[DETECT_AREA_NUM];		//遮挡区域
	char res[440];
}SM_DETECT_MOTION;

//遮挡侦测数据结构
typedef struct SM_DETECT_HIDE_S
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int sensitivity;								//阀值
	RECTANGLE_POINT	stMDArea[DETECT_AREA_NUM];			//遮挡区域
	SCHWEEK_TIME	stSchTime;						//布防时间
	SM_ALARM_HANDLE	stAlarmHandle;					//报警处理
	char res[296];
}SM_DETECT_HIDE;

//虚拟警戒线数据结构
typedef struct SM_DETECT_VIRTUALCORDON_S						//512
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int direction[DETECT_AREA_NUM];					//侦测方向
	LINE_POIN	stCrossLine[DETECT_AREA_NUM];  	//侦测虚拟线
	SCHWEEK_TIME_S	stSchTime;						//布防时间
	SM_ALARM_HANDLE	stAlarmHandle;					//报警处理
	char res[284];
}SM_DETECT_VIRTUALCORDON;

//区域入侵侦测数据结构
typedef struct SM_DETECT_CROSSAREA_S
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int direction[DETECT_AREA_NUM];					//侦测方向
	QUADRILATERAL_POINT stCrossArea[DETECT_AREA_NUM];  		//区域
	SCHWEEK_TIME_S	stSchTime;						//布防时间
	SM_ALARM_HANDLE	stAlarmHandle;					//报警处理
	char  byAreaDisplay;								//视频流显示 DM_LINKAGE_PTZ
	char  byTrackerEnable;								//跟踪使能
	char  res[118];
}SM_DETECT_CROSSAREA;

//颜色侦测
typedef struct SM_DETECT_COLOUR_S
{
	int	bEnable;									//使能
	int sensitivity;								//阀值
	SCHWEEK_TIME_S	stSchTime;						//布防时间
	SM_ALARM_HANDLE	stAlarmHandle;					//报警处理
	char res[368];
}SM_DETECT_COLOUR;

//声音侦测
typedef struct SM_DETECT_SOUND_S
{
	int	bEnable;									//使能
	int aType;
	int sensitivity;								//阀值
	SCHWEEK_TIME_S	stSchTime;						//布防时间
	SM_ALARM_HANDLE	stAlarmHandle;					//报警处理
	char res[364];
}SM_DETECT_SOUND;


//遗留物体侦测数据结构
typedef struct SM_DETECT_GOODS_LEGACY_S
{
	int	bEnable;									//使能
	int time;
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int direction[DETECT_AREA_NUM];					//侦测方向
	RECTANGLE_POINT stLoseobjArea[DETECT_AREA_NUM]; //遗留物体侦测区域
	SCHWEEK_TIME_S	stSchTime;						//布防时间
	SM_ALARM_HANDLE	stAlarmHandle;					//报警处理
	char res[280];
}SM_DETECT_GOODS_LEGACY;


//===========================================================================================================
//获取是否已经标定
typedef struct MS_CALIBRATION_PARAMETER_S
{
	int nCalibation;  //该摄像机是否已经标定 0：否 1：是
}MS_CALIBRATION_PARAMETER;

//摄像机登录成功时给主摄像机传入从机的登录参数
typedef struct MS_SUBCAMCONNECT_S
{
	BYTE  	byConnectCmd;	//0：解除绑定 1：绑定
	DWORD	dwSlaveIP;		//从机IP
	DWORD	dwPort;			//从机端口号
	char    sUserName[32];	//从机登录用户名
	char    sPaasword[32];  //从机登录密码
}MS_SUBCAMCONNECT;

typedef struct MS_ACTION_S
{
	int nAction;              //0--开始标定  1--完成标定
}MS_ACTION;

//对应CMD_CALIBRATE_命令 调用“确定”\“删除”\“3D放大模式”按钮时传此参数
typedef struct MS_AREA_RECT_S
{	
	int x; 
	int y;
	int nWeight ;
	int nHight;
	int nWndWeight ;	//窗口的实际宽
	int nWndHight;		//窗口的实际高
	int nNumber;
	int nCommand;       //1--确定 2--删除 3--3D放大模式时的坐标值
	char sRet[4];
}MS_AREA_RECT;


typedef struct MS_CALIBRATION_MODE_S
{
	int nMode;  //0:3D放大模式 1:自动跟踪模式
}MS_CALIBRATION_MODE;

typedef struct MS_CALIBRATION_ZOOMTIMES_S
{
	int nZoomTimes;  //变倍系数
}MS_CALIBRATION_ZOOMTIMES;

//暂时不需要
typedef struct MS_PTZ_SPEED_S
{
	BYTE PanSpeed;  //水平速度
	BYTE TiltSpeed; //垂直速度
	BYTE ZoomSpeed; //垂直速度

}MS_PTZ_SPEED;


typedef struct MS_CALIBRATION_PTZ_INFO_S
{
	char sCmd;// 0： 获取PTZ信息  1：设置PTZ位置
	int nPan; //水平
	int nTilt;//垂直
	int nZoomStep;//变倍步数  

}MS_CALIBRATION_PTZ_INFO;

typedef struct MS_PIC_AREA_POS_S
{
	unsigned int nId;
// 	unsigned short  x;
// 	unsigned short  y;
	int x; 			//之前是 unsigned short 
	int y;
	//char byRes[32]

}MS_PIC_AREA_POS;

typedef struct MS_Calibrate_Point_S
{
	int nCmd;// 0 :增加标定点  1:删除标定点  2:获取当前信息 3:删除所有信息
	MS_PIC_AREA_POS stPointInfo;
	int nPicWeight;//工具 参考宽
	int nPicHight;	//工具 参考高度
	char byRes[32];

}MS_Calibrate_Point;



typedef struct _PIC_AREA_POS_S
{
	unsigned int nId;
	int x; 			//之前是 unsigned short 
	int y;

}PIC_AREA_POS;


#define INV_CALIBRATE_MAX			512
typedef struct MS_ANALY_POINT_S
{
	int nCmd;
	int nNum;//当前画面内点数量
	MS_PIC_AREA_POS stPoint[INV_CALIBRATE_MAX]; //点 坐标 //返回主码流坐标
	int nOutNum;//画面外数量
	MS_PIC_AREA_POS stOutPoint[INV_CALIBRATE_MAX]; //返回在分辨率内外的坐标。
//	char byRes[32];
}MS_ANALY_POINT;


typedef struct MS_PANOTYPE_S
{
	int nPanoType; //1:IMX385_3611 2:IMX385_FISH120 3:IMX385_FISH180 
	
}MS_PANOTYPE;


#define   MS_QUANTU_PRIVATE_ENCRYPT_LEN			512
typedef struct MS_QUANTU_ENCRYPT_S
{
	char	byRes[MS_QUANTU_PRIVATE_ENCRYPT_LEN];
}MS_QUANTU_ENCRYPT; /*全图开发定制SDK 加入512作为存储*/

//全图定制512k存储 7镜头 9镜头
#define MS_QT_MEMORY_MAX_BYTE   512*1024				//最大字节 512KB
#define MS_QT_MEMORY_MAX_AREA   64					//最大分区 64 * 8 *1024 
#define MS_QT_MEMORY_LEN		16 * 1024
typedef struct MS_QUANTU_MEMORY
{
	int type; 			//类型[0-63]
	int len;			//已写入字符串长度 strlen
	char data[MS_QT_MEMORY_LEN];		//数据
}MS_QUANTU_MEMORY;

typedef struct OSD_SWITCH
{

	DWORD			title0;	//标题0					
	DWORD			title1;	//标题1						
	DWORD			title2;	//标题2				
	DWORD			title3;	 //标题3	
	DWORD			day;						
	DWORD			week;							
	DWORD			time;							
	DWORD			bitRate;
	DWORD			connectNum;						
}OSD_SWITCH;


typedef struct SMART_FRAME_DROP 
{
	DWORD	lowFrameEnable; //0 关 1开				
}SMART_FRAME_DROP;


typedef struct EXPOSURE_MS_PARAM
{
	DWORD			msMode; //0:slave  1: master			
}EXPOSURE_MS_PARAM;


typedef struct MS_NAMING_S 
{
#define CMD_NAMING_SET_PARAM   		0x1  //标定区域  			param: nData[1-4]
#define CMD_NAMING_SET_ZOOM    		0x2  //设置倍率*/  			param: nData
#define CMD_NAMING_SET_SCANMODE		0x3  //设置扫描模式     		param: nData    
#define CMD_NAMING_SET_SCANTIMES	0X4  //扫描开始后扫描n次后停止 	param: nData[1-4]  

#define CMD_NAMING_SCAN_START   	0x20   //扫描开始
#define CMD_NAMING_SCAN_STOP    	0x21   //扫描手动停止 

	int nCmd;
	int nData; 
	char byRes[128];
}MS_NAMING;

typedef struct MS_NAMING_GET_S
{
	char byEnable; //0:  1：功能可用
	char byCalibrate;//0:未标定  1:已标定存在轨迹或标定区域点名可用。
	char byDomeState; //球机空闲状态0：空闲 1：球机点名中 2：轨迹学习中/标定
	char byRes[128];//
}MS_NAMING_GET;
























//=====================================================================================================

typedef struct FA_ImprotFaceImageInfoCallback_s
{
	unsigned int uiSessionId;		///< 会话ID
	int iRet;				///< 返回值
	char sName[64];		///< 配置名称
	char sFileName[64];		///< 之前导入的图片名称
}FA_ImprotFaceImageInfoCallback;

//比对结果
typedef struct FA_FACECOMPARE_RESULT_ALARM_S		
{
	/*
	unsigned int   	deviceid;
	unsigned int   	channelid;
	unsigned int   	streamid;
	unsigned int   	wbmode;			//黑白名单
	unsigned int   	libindex;		//黑白名单库索引
	unsigned int   	libnumber;		//黑白名单库里编号
	unsigned char   npicname[64];	//实时比对图片名字
	unsigned char   cpicname[64];	//实时比对图片名字
	float			result;		    //比对结果
	unsigned char   SnapTime[32];	////抓拍时间
	unsigned int   	alarmcmd;
	unsigned char	byRes1[64];

	unsigned int   	guest;			//客流统计
	unsigned char 	Age;      		//年龄 
	unsigned char 	Gender;			//性别
	unsigned char 	Glasses; 		//眼镜  
	unsigned char 	Mask; 			//面具
	unsigned char 	Race;			//种族  
	unsigned char 	Eye;			//眼睛 	
	unsigned char 	Attractive;		//魅力值 
	unsigned char	ByRes[117];		//预留
	*/


	unsigned int	deviceid;
	unsigned int	channelid;
	unsigned int	streamid;
	unsigned int	wbmode; 		//黑白名单
	unsigned int	libindex;		//黑白名单库索引
	unsigned int	libnumber;		//黑白名单库里编号
	char	picnameComp[64];		//库图片名字
	char	*pCompImgData;			//库图片数据指针
	int		iCompImgSize;			//库图片数据长度
	char	picnameSnap[64];		//实时比对图片名字
	char	*pSnapImgData;			//实时比对图片数据指针
	int		iSnapImgSize;			//实时比对图片数据长度

	float			result; 		//比对结果
	unsigned char	SnapTime[32];	//抓拍时间
	unsigned char   cDeviceIP[16];	//设备IP
	unsigned char	byRes[48];

	unsigned int	guest;			//客流统计
	unsigned int	Age;			//年龄 
	unsigned int	Gender; 		//性别
	unsigned int	Glasses;		//眼镜	
	unsigned int	Mask;			//面具
	unsigned int	Race;			//种族	
	unsigned int	Eye;			//眼睛	
	unsigned int	Attractive; 	//魅力值 
	unsigned int	Beard;			//胡须
	unsigned int	Emotion;		//表情
	unsigned char	ByRes[117]; 	//预留

	// barney 20180920
	int 			facealarm;		//人脸报警 , 预留
	float			facecharacter[128]; //ljs 20180816

}FA_FACECOMPARE_RESULT_ALARM;  


//黑白名单
typedef struct FA_BLACKANDWHITELIST_CONFIG_S
{
	int					 byOutMode;			// 1 库文件索引; 2 图片
	int					 byWbMode;			// 1 黑名单; 2白名单
	int				 	 byAllNums;			// 实际库数目
	int				 	 byLibIndex;		//库索引
	int					 byFileIndex;		//文件索引
	int					 byDataSize;		//文件大小
	char				 byFileName[64];	//图片名
	int					 byErrorCode;		//错误码，参照XM_WB_ERROR_CODE
	unsigned char		 byRes[36];
}FA_BLACKANDWHITELIST_CONFIG;

//人脸私有协议上传
typedef struct FA_FS_PROTOCOL_S
{
	char szUDPaddr[64];	//服务器IP
	DWORD dwUDPport;	//服务器端口号
	BYTE nUDPSDKEnable; //私有协议上传使能开关
	BYTE szRes[3];		//保留
	BYTE byRes[64];		//保留
}FA_FS_PROTOCOL_S;

typedef struct FA_SMART_FACE_S
{
	INT			nEnable;			//开关
	INT			nquality;			//灵敏度
	BYTE 		nExposureMode; 		//人脸曝光模式
	BYTE		nSnapMode;			//抓拍模式
	BYTE 		nTrackmode;			//人脸跟踪      0:关闭 1:开启
	BYTE		nFtpEnable;			//FTP上传开关	0:关闭 1:开启
	INT			nFaceSize;			//人脸识别最小尺寸(60~300)
	INT			nMaxFaceSize;		//最大像素
	BYTE		nFaceBLC;			//人脸场景
	BYTE		nPicMode;			//图片上传格式(0人脸；1原图；2人脸及原图)
	BYTE 		nParamCheckFlag;
	BYTE		byFaceAreaExpand;	//人脸图片周边背景扩展系数
	BYTE		byPicPrefixEnable;	//自定义前缀开关
	CHAR		szPicPrefix[16];	//图片前缀
	INT			nTrackFrameNum;		//快速抓拍帧数-----快速抓拍
	BYTE		bySnapNum;			//最大抓拍次数-----离开后抓拍模式
	BYTE		byIntervalTime;		//间隔时间---间隔抓拍，秒为单位
	BYTE		byFacePicQual;		//人脸图片编码质量
	BYTE		byFramePicQual;		//原图编码质量
	INT			nIntervalFrame;		//间隔帧数---间隔抓拍，帧为单位
	BYTE		byAttributeEnable;	//人脸属性开关
	BYTE		byIntervalSnapNum;	//抓拍次数------间隔抓拍模式
	BYTE		byAlignmentRes[2];	//字节对齐，没有用到
	INT			nGateIntervalFrame;	//间隔帧数----闸机模式
	BYTE		byRes[16];
	//BYTE		byRes[24];
}FA_SMART_FACE;


typedef struct  FA_SNAP_FACE_CONFIG_S   
{
	SCHWEEK_TIME	  aTime;			//安周布防---布防时间
	FA_SMART_FACE    sSmartFace;  
	FA_FS_PROTOCOL_S  stFsProtocols;	//私有协议
}FA_SNAP_FACE_CONFIG;

typedef struct _FS_PROTOCOL_S
{
	char szUDPaddr[64];//服务器IP地址
	DWORD dwUDPport;//	服务器端口号
	BYTE nUDPSDKEnable;//开关
	BYTE szRes[3];
	BYTE byRes[64];
}FS_PROTOCOL_S;


typedef struct FA_VI_DECTECT_S
{
	DWORD				dwSize;			
	INT					bEnable;
	AREA_RECT			stFaceMaskArea;
	BYTE				byRes[32];
}FA_VI_DECTECT;

typedef struct FA_VI_SHIELDED_S 
{
	DWORD				dwSize;			
	INT					bEnable;
	AREA_RECT			stFaceArea[4];
	BYTE				byRes[32];
} FA_VI_SHIELDED;


//人脸报警设置   384字节
typedef struct FA_SMART_ALARM_S
{
	BYTE			aEnable;		//报警开关
	BYTE			aBEnable;		//黑名单报警开关
	BYTE			aWEnable;		//白名单报警开关
	BYTE			aIoEnable;		//IO输出使能
	short			aIoTime;		//IO输出时间（秒）
	BYTE			aIoType;		//IO输出类型（0：，1）
	BYTE			aSimilarity;	//相似度 (0-100)
	SCHWEEK_TIME	aTime;			//布防时间
	BYTE		 	byRes[40];		
}FA_SMART_ALARM;

//人脸算法版本信息
typedef struct FA_SMART_VERSION_INFO_S
{
	char szLib_version[16] ;    //算法库版本
	char szModel_version[16];	//模型版本
	BYTE  nbyLic;				//保留				
	BYTE  byRes[7];				//保留
}FA_SMART_VERSION_INFO;

//全景联动主从绑定
#define LINKAGE_MAX_USER   10
typedef struct FA_LINKAGE_BIND_S
{
	INT					nEnable;
	DWORD				dwMainIP[LINKAGE_MAX_USER];						//IP地址
	DWORD				dwIPAddr[LINKAGE_MAX_USER];						//IP地址
	DWORD				dwDataPort[LINKAGE_MAX_USER];					//数据端口	
	BYTE				Position[LINKAGE_MAX_USER];						//预置位   1~255
	BYTE				CrossArea_Num[LINKAGE_MAX_USER];				//区域入侵  1~4
	BYTE				byRes[50];
}FA_LINKAGE_BIND;

//=====================================================================================================

//=====================================================================================================

/*************************************************************************************************/


struct LOGIN_CFG//修改前端ip登录用
{
	std::string sUserName;		///< 登陆名字
	std::string sPassword;		///< 登陆密码
	int iEncryptType;			///< 密码加密方式
};

struct IPSetCfg
{
	int ch;
	int devtype;
	NetCommonConfig netcfg;
	LOGIN_CFG loginPram;
};

//中国电信手机看店平台
typedef struct MobileWatchCfg
{
	Bool	Enable;
	char DevID[NAME_ID_LEN];				// 设备编码
	char DevKey[NAME_ID_LEN];			// 设备验证码
	char ManufacturerNo[NAME_ID_LEN];	// 厂商编号
	char Mode[NAME_ID_LEN];				// 设备型号 
	char GroupAddr[NAME_URL_LEN];		// 集团平台地址
	char ProvinceAddr[NAME_URL_LEN];		// 省平台地址
	char NatIP[NAME_ID_LEN];				// 设备主服务器接入地址
	int	NatPort;							// 设备主服务器接入端口
	char BackupNatIP[NAME_ID_LEN];		// 设备备用服务器接入地址
	int	BackupNatPort;					// 设备备用服务器接入端口
	char TurnIP[NAME_ID_LEN];				// TurnServer服务器地址
	int	TurnPort;						// TurnServer服务器端口
	char BackupTurnIP[NAME_ID_LEN];		// TurnServer备份服务器地址
	int	BackupTurnPort;					// TurnServer备份服务器端口
	char FtpIP[NAME_ID_LEN];				// 图片上传FTP服务器地址
	int	FtpPort;							// 图片上传FTP服务器端口
	char FtpAccount[NAME_ID_LEN];			// 图片上传FTP服务器帐号
	char	FtpPassword[NAME_ID_LEN];		// 图片上传FTP服务器密码
	char resume[NAME_URL_LEN];			// 预留
}MobileWatchCfg;

struct OSDInfo
{
	int index;//设置通道标题和时间标题之外的区域，取值0和1
	int nX;//范围0-1000
	int nY;//范围0-1000
	int nChannel;//要设置的通道
	char pOSDStr[128];//要叠加的字符串
};

struct NKBDeviceConfig
{
	std::vector<NetDecorderConfigV3> vNetDecorderConf; /*网络设备通道配置表*/
};

struct PortService
{
	Bool Enable;		///< 是否开启
	int port;
};

//上传串口数据到指定服务器
struct NetTransCommData
{
	bool bEnable;		///< 是否开启
	int SerialType;     ///串口类型，如枚举CommTypes所述,485是0,232是1
	int ServerType;     ///协议类型名称,如枚举NetTransProtocolType所述，tcp是0，udp是1
	char ServerAddr[NAME_PASSWORD_LEN];  //域名或者IP地址。
	int  ServerPort;	//端口;
	int  ReportTime;	//状态消息发送间隔时间，单位分钟
};


//wifi模式相关配置，用于行车记录仪自动切换AP模式
struct NetWifiMode
{
	int autoSwitchAPMode; //取值  1:自动切换成AP模式(家用模式)  0:不自动切换
	int reserve[7];
};
//启动客户demo
struct NetUseProgram
{
	bool bEnable;   //是否开启
	char UserName[NAME_PASSWORD_LEN];		///< 用户名
	char Password[NAME_PASSWORD_LEN];		///< 密码
	int Port;	///< 端口号
	char ServerAddr[NAME_PASSWORD_LEN];  //域名或者IP地址。
	char Describe[NAME_TOKEN_LEN];			//设备名称
};

//QQ Server CFG for "typedef struct _tx_device_info"
struct TXDeviceCfg
{
	std::string 	DevName;
	std::string 	DevType;
	int 			product_id;
	std::string 	product_secret;
	std::string 	license;
};

//客户的nas服务配置
typedef struct SPVMN_NAS_SERVER
{
	char ServerIP[16];
	int Port;
	std::string RootDir;
	char DowloadIP[16];	
	std::string DowloadPath;
}SPVMN_NAS_SERVER;

struct SparshHeartbeat
{
	bool bEnable;	///是否启用
	int   IntevalTime; 	///间隔上报时间,分钟
	char AlarmType[NAME_PASSWORD_LEN];	///名称
};

/// 根据模式种类取得相应名称
const char *getHvrModeName(int iHvrMode);


//消费类产品特殊命令

enum ConsumerProCmd 
{
	CONSUMER_PRO_ADD_DEV,		///< 添加报警设备
	CONSUMER_PRO_STOP_ADD_DEV,	///< 停止添加报警设备
	CONSUMER_PRO_DEL_DEV,		///< 删除已经添加的报警设备
	CONSUMER_PRO_CHANGE_DEV_NAME,	///< 修改已经添加设备的名称
	CONSUMER_PRO_NR				///< 命令个数
};
// 根据操作命令获取对应的名称
const char *getConsumerCmdName(int cmd);

struct ConsumerProOpr
{
	int  cmd;		//如枚举ConsumerProCmd
	char pArg1[16]; //CONSUMER_PRO_ADD_DEV ：要添加的报警设备类型
					//CONSUMER_PRO_DEL_DEV：设备的ID号
					//CONSUMER_PRO_MODE_DEV_NAME：设备的ID号
	char pArg2[32]; //CONSUMER_PRO_CHANGE_DEV_NAME：新的名称
	char res[12];
};

//消费类产品添加的报警设备
struct ConsumerAlarmDev
{
	char pDevID[16];	//报警设备ID，包括遥控器ID
	char pDevType[16];	//报警设备类型
	char pDevName[32];	//报警设备昵称
};
struct ConsumerAlarmDevList
{
	std::list<ConsumerAlarmDev> alarmDevList;
};

//消费类产品关于外接设备相关配置
struct ConsumerCommDevCfg
{
	bool	bCheckX1Remote; //是否检查2.4G遥控器有没有注册，以决定是否执行它的命令
	bool	bKeyAudioTip;	//是否开启按键提示音
	char	rev[6];
};

//ipv6
struct IPAddressV6
{
	bool bEnable;				//是否启用ipv6
	char pLocalLinkAddr[32];	//本地链路地址
	char pAddr[64];				//ipv6地址
	char pGateway[64];			//网关
	int	iPrefix;  				//ipv6前缀长度
};


// 云在线相关配置

enum ENUM_CHECK_FIRMWARE_FREQ
{
	CHECK_FIRMWARE_MANUAL,		//手动检测有没有新固件
	CHECK_FIRMWARE_AUTO,			//开机后启去定时检测新固件
	CHECK_FIRMWARE_NR,
};

struct OnlineUpgradeCfg
{
	char cEnable; //是否启用在线升级功能
	char pServerAddr[63];
	int  serverPort;
	int  iFirmwareCheckMode; //是否自动检测有没有新固件，如枚举ENUM_CHECK_FIRMWARE_FREQ
	char cAutoUpgrade;		//自动升级到新版本
	char cAutoUpgradeImp;	//只自动升级重要更新
	char cIgnoreAllVersion;		//忽略所有版本的页面提示
	char cIgnoreCurVersion;		//忽略当前版本的页面提示，发现更新的版本后也只提示一次
	uint	  IgnoreCurTime;		//忽略掉的当前版本的时间，与 bIgnoreCurVersion联用
	char cJustImpVersion;			//只有重要版本提示
	char rev[3];
};

#endif //__EXCHANGE_AL_NETWORK_EXCHANGE_H__

