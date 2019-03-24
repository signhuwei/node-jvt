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

//��Ҫ���ڼ�
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

//�ṹ�������ͳһ��Ϊ����ǰ׺�ĸ�ʽ

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
#define  MAX_POS_FUNC_KEYWORDS 4 //POS���������֧�ֵĹؼ��ָ���


#ifdef _USE_JVT_CLIENT
#define DEFAULT_TCP_PORT 	36123
#else
#define DEFAULT_TCP_PORT	34567
#endif
	

///< �������ṹ����
struct RemoteServerConfig
{
	char ServerName[NAME_PASSWORD_LEN];	///< ������
	IPAddress ip;						///< IP��ַ
	int Port;							///< �˿ں�
	char UserName[NAME_PASSWORD_LEN];		///< �û���
	char Password[NAME_PASSWORD_LEN];		///< ����	
	bool Anonymity;							///< �Ƿ�������¼
};

/// ¼�����ز���
enum RecordDownloadPolicy
{
	DOWNLOADING_AT_NORMALSPEED = 0,	//��ͨ����
	DOWNLOADING_AT_HIGHSPEED,		//��������
};

/// �������
enum TransferPolicy
{
	TRANSFER_POLICY_AUTO,		///< ����Ӧ
	TRANSFER_POLICY_QUALITY,	///< ��������
	TRANSFER_POLICY_FLUENCY,	///< ��������
	TRANSFER_POLICY_TRANSMISSION,///<��������
	TRANSFER_POLICY_NR,
};

/// ���紫��Э������
enum NetTransProtocolType
{
	NET_TRANS_PRO_TCP = 0,
	NET_TRANS_PRO_UDP = 1,
};

///< ��ͨ��������
struct NetCommonConfig
{
	char HostName[NAME_PASSWORD_LEN];	///< ������
	IPAddress HostIP;		///< ����IP
	IPAddress Submask;		///< ��������
	IPAddress Gateway;		///< ����IP
	int HttpPort;			///< HTTP����˿�
	int TCPPort;			///< TCP�����˿�
	int SSLPort;			///< SSL�����˿�
	int UDPPort;			///< UDP�����˿�
	int MaxConn;			///< ���������
	int MonMode;			///< ����Э�� {"TCP","UDP","MCAST",��}
	int MaxBps;				///< �޶�����ֵ
	int TransferPlan;		///< ������� ��TransferPolicy
	bool bUseHSDownLoad;	///< �Ƿ����ø���¼�����ز���	
	char sMac[MAX_MAC_LEN]; ///< MAC��ַ
};

struct NetDevList
{
	std::vector<NetCommonConfig> vNetDevList;
};

///< IPȨ������
struct NetIPFilterConfig
{
	bool Enable;		///< �Ƿ���
	IPAddress BannedList[MAX_FILTERIP_NUM];		///< �������б�
	IPAddress TrustList[MAX_FILTERIP_NUM];		///< �������б�
};

///< �鲥����
struct NetMultiCastConfig
{
	bool Enable;		///< �Ƿ���
	RemoteServerConfig Server;		///< �鲥������
};

///< pppoe����
struct NetPPPoEConfig
{
	bool Enable;		///< �Ƿ���
	RemoteServerConfig Server;		///< PPPOE������
	IPAddress addr;		///< ���ź��õ�IP��ַ
};

///< DDNS����
struct NetDDNSConfig
{
	bool Enable;	///< �Ƿ���
	bool Online;		///< �Ƿ�����
	char DDNSKey[NAME_PASSWORD_LEN];	///< DDNS��������, Ŀǰ��: JUFENG
	char HostName[NAME_PASSWORD_LEN];	///< ������
	RemoteServerConfig Server;		///< DDNS������
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

struct LocalSearchInfo//Զ������Э��
{
	int SearchProtocol;//��ӦTransferProtocol_V2ö��
};

///< ��������ַ����
struct NetDecorderConfig
{
	bool Enable;						///< �Ƿ���
	char UserName[NAME_PASSWORD_LEN];	///< DDNS��������, Ŀǰ��: JUFENG
	char PassWord[NAME_PASSWORD_LEN];	///< ������
	char Address[NAME_PASSWORD_LEN];
	int Protocol;
	int Port;							///< ���������Ӷ˿�
	int Channel;						///< ����������ͨ����
	int Interval;                       ///< ��Ѳ�ļ��ʱ��(s),0:��ʾ����
};

/// ��������ַ����
struct NetDecorderConfigAll
{
	NetDecorderConfig vNetDecorderConfig[N_DECORDR_CH];
};


//��������ַ����v2
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


///< ��������ַ����
struct NetDecorderConfigV3
{
	bool Enable;						///< �Ƿ���
	char UserName[NAME_PASSWORD_LEN];	///< 
	char PassWord[NAME_PASSWORD_LEN];	///< 
	char Address[NAME_URL_LEN];
	int Protocol;
	int Port;							///< ���������Ӷ˿�
	int Channel;						///< ����������ͨ����
	int Interval;                       ///< ��Ѳ�ļ��ʱ��(s),0:��ʾ����
	char ConfName[DECODER_NAME_LEN];	///<��������
	int DevType;						///<�豸����
	int StreamType;						///<���ӵ���������CaptureChannelTypes
	char MainRtspUrl[NAME_URL_LEN];		///<rtspЭ��ʱ��ʾǰ���豸����������ַ
	char SubRtspUrl[NAME_URL_LEN];		///<rtspЭ��ʱ��ʾǰ���豸�ĸ�������ַ
};

/*��������������*/
enum DecorderConnType
{
	CONN_SINGLE = 0, 	/*������*/
	CONN_MULTI = 1,		/*��������Ѳ*/
	CONN_TYPE_NR,
};

/*����ͨ��������*/
struct NetDigitChnConfig
{
	bool Enable;		/*����ͨ���Ƿ���*/		
	int ConnType;		/*�������ͣ�ȡDecoderConnectType��ֵ*/
	int TourIntv;		/*������ʱ��Ѳ���*/
	uint SingleConnId;	/*������ʱ����������ID, ��1��ʼ��0��ʾ��Ч*/
	bool EnCheckTime;	/*������ʱ*/
	std::vector<NetDecorderConfigV3> vNetDecorderConf; /*�����豸ͨ�����ñ�*/
};

/*��������ͨ��������*/
struct NetDecorderConfigAll_V3
{
	NetDigitChnConfig DigitChnConf[N_DECORDR_CH];
};

/*ͨ��ģʽ����*/
struct NetDecorderChnModeConfig
{
	CAPTURE_TOTAL_HVRCAPV2 	HVRTotalCap;
	int HVRCurCapMode;
};

/*����ͨ��״̬*/
struct NetDecorderChnStatus
{
	char ChnName[CHANNEL_NAME_MAX_LEN];
	char pMaxResName[50];
	char	pCurResName[50];
	char pStatus[50];
};


/*��������ͨ��״̬*/
struct NetDecorderChnStatusAll
{
	NetDecorderChnStatus ChnStatusAll[MAX_HVR_CHNCAP];
};

//Pos�豸����
enum PosDevType
{
	POS_TYPE_MANY_LINES, //�������ܽ���Ű���Ʒ��Ϣһ���͹���
	POS_TYPE_ONE_LINE,   //ÿͳ��һ����Ʒ�ͰѸ���Ʒ����Ϣ���͹���
	POS_NR
};

// pos�������
struct NetPosConfig
{
	bool Enable;		/*pos��ͨ��ʹ��*/
	int Devtype;		//pos������
	int Protocol;		//ͨ��Э��
	int Port;		//Э��˿ں�
	bool SnapEnable;       //ץ��ʹ��
	int  StartLine;        //���յ�����Ϣ�Ӷ����п�ʼ��ʾ
	int  WordEncodeType;   //���ֱ����ʽ����ö��ֵ WordEncode ��ʾ
	bool KeyWordEnable;    //�ؼ���д��־����ʹ��
	char SearchWrod[MAX_POS_FUNC_KEYWORDS][16]; //��Ҫ��ӵ���־��ĵ���
	int  HideTime;         //����ͨ����ʾ��pos��Ϣ��ʱ��,��λ���룬0��ʾ���Զ�����
	int res;		//����
};
//����pos���������
struct NetPosConfigAll
{
	NetPosConfig PosConfig[N_SYS_CH];
};

///< ������������
struct NetAlarmCenterConfig
{
	bool bEnable;		///< �Ƿ���
	char sAlarmServerKey[NAME_PASSWORD_LEN];	///< ��������Э����������, 
	///< �������ķ�����
	RemoteServerConfig Server;	
	bool bAlarm;
	bool bLog;
};

struct NetAlarmServerConfigAll
{
	NetAlarmCenterConfig vAlarmServerConfigAll[MAX_ALARMSERVER_TYPE];
};

///< ftp����
struct NetFtpServerConfig{
	bool bEnable;        ///< ������ʹ��     
	RemoteServerConfig Server;	///< FTP������
	char cRemoteDir[MAX_PATH_LENGTH];	///< Զ��Ŀ¼
	int iMaxFileLen;	///< �ļ���󳤶�
};

struct NetFtpAutoUpLoad
{
	bool bEnable;	//��FTP����������������£��Զ��ϴ���Ƶ��FTP������ʹ��
	char reserve[31];//����
};

///< NTP����
enum ENUM_NTP_SYNC_TYPE
{
	NTP_SYNC_CUSTOM = 13, //�ͻ��Լ�����NTP������
	NTP_SYNC_AUTO   = 14, //ʹ���Ʒ�������ΪNTP������
};
struct NetNTPConfig
{
	bool Enable;
	RemoteServerConfig Server;
	int UpdatePeriod; ///< �������ڣ���λ����
	int TimeZone;     ///< ͬ����ʽ����ö��ENUM_NTP_SYNC_TYPE
};

#define  MAX_EMAIL_TITLE_LEN 64
#define  MAX_EMAIL_RECIEVERS  5
///< EMAIL����
struct NetEmailConfig
{
	///< �Ƿ���
	bool Enable;
	///< smtp ��������ַʹ���ַ�����ʽ���
	///< ������ip,Ҳ����������
	RemoteServerConfig Server;
	bool bUseSSL;
	///< ���͵�ַ
	char SendAddr[EMAIL_ADDR_LEN];
	///< �����˵�ַ
	char Recievers[MAX_EMAIL_RECIEVERS][EMAIL_ADDR_LEN];
	///< �ʼ�����
	char Title[MAX_EMAIL_TITLE_LEN];
	///< email��Чʱ��
	TimeSection Schedule[N_MIN_TSECT];
};

//ץ�����ýṹ
struct NetSnifferConfig
{
	IPAddress		SrcIP;			//ץ��Դ��ַ
	int	SrcPort;			//ץ��Դ�˿�
	IPAddress		DestIP;			//ץ��Ŀ���ַ
	int	DestPort;		//ץ��Ŀ��˿�
} ;

#define MAX_ETH_NUM 4

//DHCP
struct NetDHCPConfig
{
	bool bEnable;
	char ifName[32];
};

/// ����������DHCP����
struct NetDHCPConfigAll
{
	NetDHCPConfig vNetDHCPConfig[MAX_ETH_NUM];
};

///< NTP����
struct NetDNSConfig
{
	IPAddress		PrimaryDNS;
	IPAddress		SecondaryDNS;
};


struct DDNSTypeConfigAll
{
	NetDDNSConfig vDDNSTypeAll[MAX_DDNS_TYPE];
};

///< ARSP(����ע�������)���ð�������̩DNS
struct NetARSPConfig
{
	bool bEnable;	///< �Ƿ���
	char sARSPKey[NAME_PASSWORD_LEN];	///< DNS��������
	int iInterval;	///< ������ʱ��
	char sURL[NAME_PASSWORD_LEN];    ///< ��������
	RemoteServerConfig Server;		///< DDNS������
	int nHttpPort;                  ///< ������HTTP�˿�
};

struct NetARSPConfigAll
{
	NetARSPConfig vNetARSPConfigAll[MAX_ARSP_TYPE];
};

enum Net3GType
{
	WIRELESS_AUTOSEL=0,	    ///< �Զ�ѡ��
	WIRELESS_TD_SCDMA=1,	///< TD-SCDMA����
	WIRELESS_WCDMA=2,		///< WCDMA����
	WIRELESS_CDMA_1X=3,     ///< CDMA 1.x����
	WIRELESS_EDGE=4,		///< GPRS����
	WIRELESS_EVDO=5,		///< EVDO����
	WIRELESS_4G=6,
	WIRELESS_MAX
};

struct Net3GConfig
{
	bool bEnable;			  ///< ����ģ��ʹ�ܱ�־
	int iNetType;			  ///< ������������
	std::string strAPN;		  ///< ���������
	std::string strDialNum;   ///< ���ź���
	std::string strUserName;  ///< �����û���
	std::string strPWD;  	  ///< ��������
	IPAddress addr;			  ///< ���ź��õ�IP��ַ
};

///< �ֻ�������ð�������̩DNS
struct NetMoblieConfig
{
	bool bEnable;	///< �Ƿ���
	RemoteServerConfig Server;		///< ������
};

struct NetUPNPConfig
{
	bool bEnable;			  ///< ʹ�ܱ�־
	bool bState;              ///< ״̬
	int iHTTPPort;			  ///< HTTP�˿�
	int iMediaPort;			  ///< ý��˿�
	int iMobliePort;		  ///< �ֻ���ض˿�
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

// ����������Ϣ����
enum AlarmCenterMsgType
{
	ALARMCENTER_ALARM,
	ALARMCENTER_LOG,
};

// ����������Ϣ����
enum AlarmCenterStatus
{
	AC_START,
	AC_STOP,
};

// �澯������Ϣ����
struct NetAlarmCenterMsg
{
	IPAddress HostIP;		///< �豸IP
	int nChannel;           ///< ͨ��
	int nType;              ///< ���� ��AlarmCenterMsgType
	int nStatus;            ///< ״̬ ��AlarmCenterStatus
	SystemTime Time;        ///< ����ʱ��
	std::string strEvent;    ///< �¼�
	std::string strSerialID; ///< �豸���к�
	std::string strDescrip;  ///< ����
};

// RTSP
struct NetRtspConfig
{
	bool bServer;
	bool bClient;
	RemoteServerConfig Server;		///< ������ģʽ
	RemoteServerConfig Client;		///< �ͻ���ģʽ
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


//�ֻ���������
struct NetShortMsgCfg
{
	bool bEnable;       //�����ֻ����ŵĹ����Ƿ�����
	char pDesPhoneNum[MAX_RECIVE_MSG_PHONE_COUNT][16]; //���ն��ŵ��ֻ��ţ���֧��3���ֻ���
	int  sendTimes;     //��Ҫ��ÿ���ֻ����Ͷ��ٴζ���
};

//�ֻ���������
struct NetMultimediaMsgCfg
{
	bool bEnable;				// �����ֻ����ŵĹ����Ƿ�����
	char pDesPhoneNum[MAX_RECIVE_MSG_PHONE_COUNT][16]; //���ղ��ŵ��ֻ��ţ���֧��3���ֻ���
	char pGateWayDomain[40];	// ���ص�ַ��������IP
	int  gateWayPort;			// ���ض˿�
	char pMmscDomain[40];		// ���ŷ�������ַ��IP������
	int  mmscPort;				// ���ŷ������˿ں�
};


//�������ȼ�
struct NetOrderConfig
{
	bool         bEnable;          //�Ƿ������������ȼ�
	int          netCount;         //����������Ŀ
	NetLinkOrder pNetOrder[NM_NR]; //�������ȼ�
	NetLinkOrder pReserve[7-NM_NR];//���µ���������Ԥ��
};

//����ƽ̨��Ϣ����
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

//���۽Ӿ�����ϵͳ
struct	GodEyeConfig
{
	bool	bEnable; 
	char MainServerName[NAME_PASSWORD_LEN]; //������
	int MainPort;	//���˿�
	char ExServerName[NAME_PASSWORD_LEN]; //��������
	int ExPort;	//���ö˿�
};

enum  DigManagerShowStatus
{
	SHOW_NONE,
	SHOW_ALL,
};


//����ͨ����ʾ״̬
struct DigitalManagerShow
{
	int  nDigitalManagerShowSta;
};

//NATʹ�ܣ�MTUֵ
struct NatConfig
{
	bool bEnable;
	int nMTU;
	char serverAddr[64];  //�Ʒ������������IP��ַ��
	int  serverPort;      //�Ʒ���Ķ˿�;
	IPAddress dnsSvr1;//�Ʒ����DNS��������ַ
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

//�ƴ洢������ؽṹ��
struct CloudRecordConfig
{
	int EnableMsk;			//0ȫ���棬1�Ƕ�ʱ�棬2�����棬3��ʱ&& ����
	int StreamType;			//��������
	int AlarmRecTypeMsk;	//��Ҫ�ϴ�¼��ı������ͣ�AlarmRecType��������
	WorkSheet wcWorkSheet;	//��ͨ¼����洢��ʱ���
};

struct CloudRecordConfigAll
{
	CloudRecordConfig vRecordConfigAll[N_SYS_CH]; 
};

struct VPNConfig
{
	bool Enable;		///< �Ƿ���
	IPAddress ServiceIp;						///< ������IP��ַ
	char UserName[NAME_PASSWORD_LEN];		///< �û���
	char Password[NAME_PASSWORD_LEN];		///< ����	
	IPAddress addr;		///< ���ź��õ�IP��ַ
	char ServerName[NAME_PASSWORD_LEN];		///< openvpn��������ַ
	int port;
};

struct NetKeyboardConfig
{
	bool Enable;		///< �Ƿ���
	char sTransProtocol[4];	//����Э��
	int ListenPort;		//�����˿�
	char sParserProtocol[32];
	int deviceaddr;	//�豸��ַ
};

void exchangeServer(CKeyExchange& configExchange, CConfigTable& table, RemoteServerConfig& server);


//���մ���C7ƽ̨����
struct C7PlatformConfig
{
	char pServerAddr[64];//ƽ̨��ַ��IP��ַ������
	int  servPort;       //ƽ̨�˿�
	char pPUID[32];      //PUID
	char pPassword[32];  //����
	char pStatus[64];    //����״̬����LocalSDK���ǿɶ���д�ģ������ط���ֻ��
	char pResv[60];      //����
};

//28181Э������
typedef struct ASB_NET_VSP_CONFIG
{
	bool		bCsEnable;				//ʹ�ܱ��
	char		szCsIP[64];				//��������ַ	(IP)
	short	sCsPort;					//�������˿�
	short	sUdpPort;				//���ط�����udp�˿�
	char		szServerNo[64];			//���������
	char 	szServerDn[64];			//����������(����Ϊ28181���)
	char		szDeviceNO[64];			//�豸���
	char 	szConnPass[64];			//�豸ע������
	int		iHsIntervalTime;			//�������ʱ��,��λ����
	int		iRsAgedTime;			//ע����Ч�ڣ���λΪ��
	char		Camreaid[N_SYS_CH][64];	//ͨ�����
	int		CamreaLevel[N_SYS_CH];	//��������
	char		Alarmid[N_SYS_CH][64];	//�������
	int		AlarmLevel[N_SYS_CH];	//��������
	uint		uiAlarmStateGpinEnable;	//�ⲿ����ʹ��
	uint		uiAlarmStateLoseEnable;	//��Ƶ��ʧ�澯ʹ��
	uint		uiAlarmStateMotionEnable;//��Ƶ��̬���澯ʹ��
	uint		uiAlarmStateBlindEnable;	//��Ļ�ڵ��澯ʹ��
	uint		uiAlarmStatePerformanceEnable;	//ϵͳ�쳣�澯ʹ��
	uint		uiAlarmStateConnectEnable;	//�û����Ӹ澯ʹ��
}ASB_NET_VSP_CONFIG;


struct PMSConfig
{
	bool Enable;		///< �Ƿ���
	char servname[64];		
	int port;
	char boxid[128];
	char resume[24];
};
struct PhoneInfo
{
	char command[NAME_PASSWORD_LEN]; 		///ָ��
	char type[12];								///ʹ�ܣ��ͻ����ַ�����ʽ������
	char asid[128];							///�ֻ�id	
	char username[NAME_PASSWORD_LEN];		///< �û���
	char password[NAME_PASSWORD_LEN];		///< ����	
	char acme[NAME_PASSWORD_LEN];
	char resume[24];
};
struct PhoneAsidList
{
	std::vector<std::string> asidList;
};

typedef struct KaiCongAlarmConfig
{
	bool Enable;		///< �Ƿ���
	char ServerName[NAME_PASSWORD_LEN];	///< ������
	int Port;							///< �˿ں�
	char UserName[NAME_PASSWORD_LEN];		///< �û���
	char Password[NAME_PASSWORD_LEN];		///< ����	
}KaiCongAlarmCfg;

typedef struct XMHeartbeatConfig
{
	bool bEnable;							///< �Ƿ���
	int iInterval;							///< ������ʱ��
	char ServerName[NAME_PASSWORD_LEN];	///< ������
	int Port;								///< �˿ں�
	char UserName[NAME_PASSWORD_LEN];		///< �û���
	char Password[NAME_PASSWORD_LEN];		///< ����
	char resume[24];
}XMHeartbeatCfg;

struct MonitorPlatformConfig
{
	Bool Enable;		///< �Ƿ���
	char servname[NAME_PASSWORD_LEN];
	int port;
	char resume[24];
	char agentid[128];	//�ͻ���id�����ƽ̨ʹ��(��SSJC��ͷ)
	char type[128];		//
};

struct DataLinkConfig
{
	Bool DoProgramEnable;
	Bool NIP2Enable;
};

//���������ƽ̨ͨ�����ã��Ժ��ƶ������
typedef struct NetPlatformCommonCfg
{
	Bool	Enable;
	int Port;									///< �˿ں�
	char ServerName[NAME_PASSWORD_LEN];		///< ������
	char ID[NAME_PASSWORD_LEN];	
	char UserName[NAME_PASSWORD_LEN];		///< �û���
	char Password[NAME_PASSWORD_LEN];		///< ����
	char resume[128];		///Ԥ��
}NetPlatformCommonCfg;

///������
struct NetCommonConfig_V2
{
	char HostName[NAME_PASSWORD_LEN];	///< ������
	IPAddress HostIP;		///< ����IP
	IPAddress Submask;		///< ��������
	IPAddress Gateway;		///< ����IP
	int HttpPort;			///< HTTP����˿�
	int TCPPort;			///< TCP�����˿�
	int SSLPort;			///< SSL�����˿�
	int UDPPort;			///< UDP�����˿�
	int MaxConn;			///< ���������
	int MonMode;			///< ����Э�� {"TCP","UDP","MCAST",��}
	int MaxBps;				///< �޶�����ֵ
	int TransferPlan;		///< ������� ��TransferPolicy
	bool bUseHSDownLoad;	///< �Ƿ����ø���¼�����ز���	
	char sMac[MAX_MAC_LEN]; ///< MAC��ַ
	char sSn[MAX_MAC_LEN]; 	///���к�
	int ChannelNum;			///ͨ����
	int	DeviceType;			///�豸���ͣ���ö��DevType
	char Resume[56];		///����
};

struct NetDevList_V2
{
	std::vector<NetCommonConfig_V2> vNetDevList;
};

typedef struct BaiduCloudCfg
{
	bool enable;
	char APIKey[NAME_TOKEN_LEN];				//Ӧ��API��Կ
	char SecretKey[NAME_TOKEN_LEN];			//Ӧ����Կ
	char AuthorizationCode[NAME_TOKEN_LEN];	//��Ȩ��
	char accessToken[NAME_TOKEN_LEN];		//����Ȩ����
	char refreshToken[NAME_TOKEN_LEN];		//ˢ��Ȩ����
	char deviceID[NAME_TOKEN_LEN];			//�豸ID
	char userCode[NAME_TOKEN_LEN];			//�û���Ȩ��
	char qrcodeUrl[NAME_TOKEN_LEN];			//��ά��
	char streamID[NAME_TOKEN_LEN];			//��ID
	char describe[NAME_TOKEN_LEN];			//�豸����
	int state;								//״̬
	SystemTime refreshTime;					//�ϴ�ˢ��Tokenʱ��
	std::vector<Bool>	channelMain;				//�Ƿ������
	std::vector<Bool>	channelExtra;				//�Ƿ������
	int recordFileMode;						//����¼��ģʽ
	int recordFileSize;						//¼���ļ���С
	int recordFileTime;						//¼���ʱ��
	char resume[128];							///Ԥ��
}BaiduCloudCfg;

//=============================================================================================================
#define DETECT_AREA_NUM		4							//���·��
#define MAX_ROI_AREA		8
#define MAX_OVERSTRP_AREA	4

#if 0

//ʱ��: ��
typedef struct DAY_TIME_S
{
	DWORD			week : 5;							//����
	DWORD			millisec : 10;						//����: 0 ~ 999
	DWORD			second : 6;							//��:	0 ~ 59
	DWORD			minute : 6;							//��:   0 ~ 59
	DWORD			hour : 5;							//ʱ:	0 ~ 23
}DAY_TIME; 


//ʱ��: ʱ��� 
typedef struct SEG_TIME_S
{
	BYTE			bEnable;							//�Ƿ���
	BYTE			byTask;								//����
	BYTE			byRes[2];							//����
	SDK_DAY_TIME_S		stBgnTime;							//��ʼʱ��
	SDK_DAY_TIME_S		stEndTime;							//����ʱ��
}SEG_TIME; 

//�ƻ�ʱ��: �ܼƻ�ʱ��
typedef struct SCHWEEK_TIME_S
{
	SDK_SEG_TIME_S		stSegTime[7][4];					//0: �����죬1: ��һ��2: �ܶ�
}SCHWEEK_TIME;


//��
typedef struct LINE_POINT_S
{
	int			x0;									//x0����
	int			y0;									//y0����
	int			x1;									//x1���
	int			y1;									//y1�߶�
}LINE_POIN;


//��������   rectangle   
typedef struct RECTANGLE_POINT_S
{
	int			x;									//X����
	int			y;									//Y����
	int			w;									//���
	int			h;									//�߶�
}RECTANGLE_POINT;

//�ı������� Quadrilateral   
typedef struct QUADRILATERAL_POINT_S
{
	int			x0;									//X0����
	int			y0;									//Y0����
	int			x1;									//X1����
	int			y1;									//Y1����
	int			x2;									//X2����
	int			y2;									//Y2����
	int			x3;									//X3����
	int			y3;									//Y3����
}QUADRILATERAL_POINT;

//���ܱ��룺
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


//���ܼ�⣺
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


//���ܿ��ƣ�
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


//����������ݽṹ
typedef struct SM_LUMADETECT_S						//size 512
{
	int	bEnable;									//ʹ��
	int sensitivity;								//��ֵ
	char res[504];
}SM_LUMADETECT;

//�ƶ�������ݽṹ
typedef struct SM_MDDETECT_S
{
	int	bEnable;									//ʹ��
	int sensitivity;								//��ֵ
	RECTANGLE_POINT	stMDArea[DETECT_AREA_NUM];			//�ƶ��������
	char res[440];
}SM_MDDETECT;

//�ڵ�������ݽṹ
typedef struct SM_ODDETECT_S
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int sensitivity;								//��ֵ
	RECTANGLE_POINT	stMDArea[DETECT_AREA_NUM];			//�ڵ�����
	char res[432];
}SM_ODDETECT;

//���⾯�������ݽṹ

typedef struct SM_CROSSLINE_S						//512
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int direction[DETECT_AREA_NUM];					//��ⷽ��
	LINE_POIN	stCrossLine[DETECT_AREA_NUM];  	//���������
	char res[420];
}SM_CROSSLINE;


//��������������ݽṹ
typedef struct SM_CROSSAREA_S						//512
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int direction[DETECT_AREA_NUM];					//��ⷽ��
	QUADRILATERAL_POINT stCrossArea[DETECT_AREA_NUM];  	//����
	char  res[356];
} SM_CROSSAREA;

//��ɫ���
typedef struct SM_DETECTCOLOR_S
{
	int	bEnable;									//ʹ��
	int sensitivity;								//��ֵ
	char res[504];
}SM_DETECTCOLOR;

//�������
typedef struct SM_DETECTSOUND_S
{
	int	bEnable;									//ʹ��
	int aType;
	int sensitivity;								//��ֵ
	char res[500];
}SM_DETECTSOUND;


//��������������ݽṹ
typedef struct SM_LOSEOBJ_S
{
	int	bEnable;									//ʹ��
	int time;
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int direction[DETECT_AREA_NUM];					//��ⷽ��
	RECTANGLE_POINT stLoseobjArea[DETECT_AREA_NUM];  	//���������������
	
	char res[416];
}SM_LOSEOBJ;

#endif




//ʱ��: ��
typedef struct DAY_TIME_S
{
	DWORD			week : 5;							//����
	DWORD			millisec : 10;						//����: 0 ~ 999
	DWORD			second : 6;							//��:	0 ~ 59
	DWORD			minute : 6;							//��:   0 ~ 59
	DWORD			hour : 5;							//ʱ:	0 ~ 23
}DAY_TIME; 

//ʱ��: ����
typedef struct DATE_TIME_S
{
	DWORD			second : 6;							//��:  0 ~ 59
	DWORD			minute : 6;							//��:  0 ~ 59
	DWORD			hour : 5;							//ʱ:  0 ~ 23
	DWORD			day : 5;							//��:  1 ~ 31
	DWORD			month : 4;							//��:  1 ~ 12
	DWORD			year : 6;							//��:  2000 ~ 2063
}DATE_TIME;

//ʱ��: ʱ��� 
typedef struct SEG_TIME_S
{
	BYTE			bEnable;							//�Ƿ���
	BYTE			byTask;								//����
	BYTE			byRes[2];							//����
	DAY_TIME		stBgnTime;							//��ʼʱ��
	DAY_TIME		stEndTime;							//����ʱ��
}SEG_TIME; 

//�ƻ�ʱ��: �ܼƻ�ʱ��
typedef struct SCHWEEK_TIME_S
{
	SEG_TIME		stSegTime[7][4];					//0: �����죬1: ��һ��2: �ܶ�
}SCHWEEK_TIME;


//��
typedef struct LINE_POIN_S
{
	int			x0;									//x0����
	int			y0;									//y0����
	int			x1;									//x1���
	int			y1;									//y1�߶�
} LINE_POIN;


//��������   rectangle   
typedef struct RECTANGLE_POINT_S
{
	int			x;									//X����
	int			y;									//Y����
	int			w;									//���
	int			h;									//�߶�
}RECTANGLE_POINT;


//����
typedef struct AREA_RECT_S
{
	short			x;									//X����
	short			y;									//Y����
	short			w;									//���
	short			h;									//�߶�
}AREA_RECT;

//�ı������� _CROSS_RECT_S   

//�ı������� Quadrilateral   
typedef struct QUADRILATERAL_POINT_S
{
	int			x0;									//X0����
	int			y0;									//Y0����
	int			x1;									//X1����
	int			y1;									//Y1����
	int			x2;									//X2����
	int			y2;									//Y2����
	int			x3;									//X3����
	int			y3;									//Y3����
}QUADRILATERAL_POINT;


//����
typedef struct SM_CHN_MASK_S
{
	DWORD			dwChns1;							//bit.0 ~ bit.31  ��ʾͨ�� 1  ~ 32
	DWORD			dwChns2;							//bit.0 ~ bit.31  ��ʾͨ�� 33 ~ 64
}SM_CHN_MASK;

//������������
typedef struct SM_ALARM_HANDLE_S
{
	SM_CHN_MASK		stMaskAlarmOut;						//���������豸�����ͨ��,�������������,Ϊ1��ʾ���������
	DWORD			dwAlarmOutTime;						//���������ʱ��(��)

	SM_CHN_MASK		stMaskAlarmRec;						//����¼��ͨ�� 
	DWORD			dwRecSaveMode;						//bit0: ���ش洢(�������д洢�豸ʱ, ��λ�̶�Ϊ1)  
	//bit2: ftp�ϴ�   
	DWORD			dwRecTime;							//¼���ʱ��(��)

	SM_CHN_MASK		stMaskAlarmSnap;					//����ץ��
	DWORD			dwSnapSaveMode;						//bit0: ���ش洢(�������д洢�豸ʱ, ��λ�̶�Ϊ1)  
	//bit1: email 
	//bit2: ftp�ϴ�   

	DWORD			dwSnapNum;							//����ץ������
	DWORD			dwSnapInterval;						//����ץ��ʱ����(����)  0: ����ץ��

	DWORD			dwUserData1;						//�û�����1(����PC¼��ͨ��)
	DWORD			dwUserData2;						//�û�����2

	DWORD			dwSnapDealy;						//�ӳ�ץ��

	BYTE			bSendEmail;							//��������email
	BYTE			byRes[251];							//����
}SM_ALARM_HANDLE;

//���ܱ��룺
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


//���ܼ�⣺
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

//���ܿ��ƣ�
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

//����������ݽṹ
typedef struct SM_DETECT_BRIGHTNESS_S						//size 512
{
	int	bEnable;								//ʹ��
	int sensitivity;							//��ֵ
	SCHWEEK_TIME	stSchTime;					//����ʱ��
	SM_ALARM_HANDLE	stAlarmHandle;				//��������
	char res[368];
}SM_DETECT_BRIGHTNESS;

//�ƶ�������ݽṹ
typedef struct SM_DETECT_MOTION_S
{
	int	bEnable;									//ʹ��
	int sensitivity;								//��ֵ
	RECTANGLE_POINT	stMDArea[DETECT_AREA_NUM];		//�ڵ�����
	char res[440];
}SM_DETECT_MOTION;

//�ڵ�������ݽṹ
typedef struct SM_DETECT_HIDE_S
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int sensitivity;								//��ֵ
	RECTANGLE_POINT	stMDArea[DETECT_AREA_NUM];			//�ڵ�����
	SCHWEEK_TIME	stSchTime;						//����ʱ��
	SM_ALARM_HANDLE	stAlarmHandle;					//��������
	char res[296];
}SM_DETECT_HIDE;

//���⾯�������ݽṹ
typedef struct SM_DETECT_VIRTUALCORDON_S						//512
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int direction[DETECT_AREA_NUM];					//��ⷽ��
	LINE_POIN	stCrossLine[DETECT_AREA_NUM];  	//���������
	SCHWEEK_TIME_S	stSchTime;						//����ʱ��
	SM_ALARM_HANDLE	stAlarmHandle;					//��������
	char res[284];
}SM_DETECT_VIRTUALCORDON;

//��������������ݽṹ
typedef struct SM_DETECT_CROSSAREA_S
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int direction[DETECT_AREA_NUM];					//��ⷽ��
	QUADRILATERAL_POINT stCrossArea[DETECT_AREA_NUM];  		//����
	SCHWEEK_TIME_S	stSchTime;						//����ʱ��
	SM_ALARM_HANDLE	stAlarmHandle;					//��������
	char  byAreaDisplay;								//��Ƶ����ʾ DM_LINKAGE_PTZ
	char  byTrackerEnable;								//����ʹ��
	char  res[118];
}SM_DETECT_CROSSAREA;

//��ɫ���
typedef struct SM_DETECT_COLOUR_S
{
	int	bEnable;									//ʹ��
	int sensitivity;								//��ֵ
	SCHWEEK_TIME_S	stSchTime;						//����ʱ��
	SM_ALARM_HANDLE	stAlarmHandle;					//��������
	char res[368];
}SM_DETECT_COLOUR;

//�������
typedef struct SM_DETECT_SOUND_S
{
	int	bEnable;									//ʹ��
	int aType;
	int sensitivity;								//��ֵ
	SCHWEEK_TIME_S	stSchTime;						//����ʱ��
	SM_ALARM_HANDLE	stAlarmHandle;					//��������
	char res[364];
}SM_DETECT_SOUND;


//��������������ݽṹ
typedef struct SM_DETECT_GOODS_LEGACY_S
{
	int	bEnable;									//ʹ��
	int time;
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int direction[DETECT_AREA_NUM];					//��ⷽ��
	RECTANGLE_POINT stLoseobjArea[DETECT_AREA_NUM]; //���������������
	SCHWEEK_TIME_S	stSchTime;						//����ʱ��
	SM_ALARM_HANDLE	stAlarmHandle;					//��������
	char res[280];
}SM_DETECT_GOODS_LEGACY;


//===========================================================================================================
//��ȡ�Ƿ��Ѿ��궨
typedef struct MS_CALIBRATION_PARAMETER_S
{
	int nCalibation;  //��������Ƿ��Ѿ��궨 0���� 1����
}MS_CALIBRATION_PARAMETER;

//�������¼�ɹ�ʱ�������������ӻ��ĵ�¼����
typedef struct MS_SUBCAMCONNECT_S
{
	BYTE  	byConnectCmd;	//0������� 1����
	DWORD	dwSlaveIP;		//�ӻ�IP
	DWORD	dwPort;			//�ӻ��˿ں�
	char    sUserName[32];	//�ӻ���¼�û���
	char    sPaasword[32];  //�ӻ���¼����
}MS_SUBCAMCONNECT;

typedef struct MS_ACTION_S
{
	int nAction;              //0--��ʼ�궨  1--��ɱ궨
}MS_ACTION;

//��ӦCMD_CALIBRATE_���� ���á�ȷ����\��ɾ����\��3D�Ŵ�ģʽ����ťʱ���˲���
typedef struct MS_AREA_RECT_S
{	
	int x; 
	int y;
	int nWeight ;
	int nHight;
	int nWndWeight ;	//���ڵ�ʵ�ʿ�
	int nWndHight;		//���ڵ�ʵ�ʸ�
	int nNumber;
	int nCommand;       //1--ȷ�� 2--ɾ�� 3--3D�Ŵ�ģʽʱ������ֵ
	char sRet[4];
}MS_AREA_RECT;


typedef struct MS_CALIBRATION_MODE_S
{
	int nMode;  //0:3D�Ŵ�ģʽ 1:�Զ�����ģʽ
}MS_CALIBRATION_MODE;

typedef struct MS_CALIBRATION_ZOOMTIMES_S
{
	int nZoomTimes;  //�䱶ϵ��
}MS_CALIBRATION_ZOOMTIMES;

//��ʱ����Ҫ
typedef struct MS_PTZ_SPEED_S
{
	BYTE PanSpeed;  //ˮƽ�ٶ�
	BYTE TiltSpeed; //��ֱ�ٶ�
	BYTE ZoomSpeed; //��ֱ�ٶ�

}MS_PTZ_SPEED;


typedef struct MS_CALIBRATION_PTZ_INFO_S
{
	char sCmd;// 0�� ��ȡPTZ��Ϣ  1������PTZλ��
	int nPan; //ˮƽ
	int nTilt;//��ֱ
	int nZoomStep;//�䱶����  

}MS_CALIBRATION_PTZ_INFO;

typedef struct MS_PIC_AREA_POS_S
{
	unsigned int nId;
// 	unsigned short  x;
// 	unsigned short  y;
	int x; 			//֮ǰ�� unsigned short 
	int y;
	//char byRes[32]

}MS_PIC_AREA_POS;

typedef struct MS_Calibrate_Point_S
{
	int nCmd;// 0 :���ӱ궨��  1:ɾ���궨��  2:��ȡ��ǰ��Ϣ 3:ɾ��������Ϣ
	MS_PIC_AREA_POS stPointInfo;
	int nPicWeight;//���� �ο���
	int nPicHight;	//���� �ο��߶�
	char byRes[32];

}MS_Calibrate_Point;



typedef struct _PIC_AREA_POS_S
{
	unsigned int nId;
	int x; 			//֮ǰ�� unsigned short 
	int y;

}PIC_AREA_POS;


#define INV_CALIBRATE_MAX			512
typedef struct MS_ANALY_POINT_S
{
	int nCmd;
	int nNum;//��ǰ�����ڵ�����
	MS_PIC_AREA_POS stPoint[INV_CALIBRATE_MAX]; //�� ���� //��������������
	int nOutNum;//����������
	MS_PIC_AREA_POS stOutPoint[INV_CALIBRATE_MAX]; //�����ڷֱ�����������ꡣ
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
}MS_QUANTU_ENCRYPT; /*ȫͼ��������SDK ����512��Ϊ�洢*/

//ȫͼ����512k�洢 7��ͷ 9��ͷ
#define MS_QT_MEMORY_MAX_BYTE   512*1024				//����ֽ� 512KB
#define MS_QT_MEMORY_MAX_AREA   64					//������ 64 * 8 *1024 
#define MS_QT_MEMORY_LEN		16 * 1024
typedef struct MS_QUANTU_MEMORY
{
	int type; 			//����[0-63]
	int len;			//��д���ַ������� strlen
	char data[MS_QT_MEMORY_LEN];		//����
}MS_QUANTU_MEMORY;

typedef struct OSD_SWITCH
{

	DWORD			title0;	//����0					
	DWORD			title1;	//����1						
	DWORD			title2;	//����2				
	DWORD			title3;	 //����3	
	DWORD			day;						
	DWORD			week;							
	DWORD			time;							
	DWORD			bitRate;
	DWORD			connectNum;						
}OSD_SWITCH;


typedef struct SMART_FRAME_DROP 
{
	DWORD	lowFrameEnable; //0 �� 1��				
}SMART_FRAME_DROP;


typedef struct EXPOSURE_MS_PARAM
{
	DWORD			msMode; //0:slave  1: master			
}EXPOSURE_MS_PARAM;


typedef struct MS_NAMING_S 
{
#define CMD_NAMING_SET_PARAM   		0x1  //�궨����  			param: nData[1-4]
#define CMD_NAMING_SET_ZOOM    		0x2  //���ñ���*/  			param: nData
#define CMD_NAMING_SET_SCANMODE		0x3  //����ɨ��ģʽ     		param: nData    
#define CMD_NAMING_SET_SCANTIMES	0X4  //ɨ�迪ʼ��ɨ��n�κ�ֹͣ 	param: nData[1-4]  

#define CMD_NAMING_SCAN_START   	0x20   //ɨ�迪ʼ
#define CMD_NAMING_SCAN_STOP    	0x21   //ɨ���ֶ�ֹͣ 

	int nCmd;
	int nData; 
	char byRes[128];
}MS_NAMING;

typedef struct MS_NAMING_GET_S
{
	char byEnable; //0:  1�����ܿ���
	char byCalibrate;//0:δ�궨  1:�ѱ궨���ڹ켣��궨����������á�
	char byDomeState; //�������״̬0������ 1����������� 2���켣ѧϰ��/�궨
	char byRes[128];//
}MS_NAMING_GET;
























//=====================================================================================================

typedef struct FA_ImprotFaceImageInfoCallback_s
{
	unsigned int uiSessionId;		///< �ỰID
	int iRet;				///< ����ֵ
	char sName[64];		///< ��������
	char sFileName[64];		///< ֮ǰ�����ͼƬ����
}FA_ImprotFaceImageInfoCallback;

//�ȶԽ��
typedef struct FA_FACECOMPARE_RESULT_ALARM_S		
{
	/*
	unsigned int   	deviceid;
	unsigned int   	channelid;
	unsigned int   	streamid;
	unsigned int   	wbmode;			//�ڰ�����
	unsigned int   	libindex;		//�ڰ�����������
	unsigned int   	libnumber;		//�ڰ�����������
	unsigned char   npicname[64];	//ʵʱ�ȶ�ͼƬ����
	unsigned char   cpicname[64];	//ʵʱ�ȶ�ͼƬ����
	float			result;		    //�ȶԽ��
	unsigned char   SnapTime[32];	////ץ��ʱ��
	unsigned int   	alarmcmd;
	unsigned char	byRes1[64];

	unsigned int   	guest;			//����ͳ��
	unsigned char 	Age;      		//���� 
	unsigned char 	Gender;			//�Ա�
	unsigned char 	Glasses; 		//�۾�  
	unsigned char 	Mask; 			//���
	unsigned char 	Race;			//����  
	unsigned char 	Eye;			//�۾� 	
	unsigned char 	Attractive;		//����ֵ 
	unsigned char	ByRes[117];		//Ԥ��
	*/


	unsigned int	deviceid;
	unsigned int	channelid;
	unsigned int	streamid;
	unsigned int	wbmode; 		//�ڰ�����
	unsigned int	libindex;		//�ڰ�����������
	unsigned int	libnumber;		//�ڰ�����������
	char	picnameComp[64];		//��ͼƬ����
	char	*pCompImgData;			//��ͼƬ����ָ��
	int		iCompImgSize;			//��ͼƬ���ݳ���
	char	picnameSnap[64];		//ʵʱ�ȶ�ͼƬ����
	char	*pSnapImgData;			//ʵʱ�ȶ�ͼƬ����ָ��
	int		iSnapImgSize;			//ʵʱ�ȶ�ͼƬ���ݳ���

	float			result; 		//�ȶԽ��
	unsigned char	SnapTime[32];	//ץ��ʱ��
	unsigned char   cDeviceIP[16];	//�豸IP
	unsigned char	byRes[48];

	unsigned int	guest;			//����ͳ��
	unsigned int	Age;			//���� 
	unsigned int	Gender; 		//�Ա�
	unsigned int	Glasses;		//�۾�	
	unsigned int	Mask;			//���
	unsigned int	Race;			//����	
	unsigned int	Eye;			//�۾�	
	unsigned int	Attractive; 	//����ֵ 
	unsigned int	Beard;			//����
	unsigned int	Emotion;		//����
	unsigned char	ByRes[117]; 	//Ԥ��

	// barney 20180920
	int 			facealarm;		//�������� , Ԥ��
	float			facecharacter[128]; //ljs 20180816

}FA_FACECOMPARE_RESULT_ALARM;  


//�ڰ�����
typedef struct FA_BLACKANDWHITELIST_CONFIG_S
{
	int					 byOutMode;			// 1 ���ļ�����; 2 ͼƬ
	int					 byWbMode;			// 1 ������; 2������
	int				 	 byAllNums;			// ʵ�ʿ���Ŀ
	int				 	 byLibIndex;		//������
	int					 byFileIndex;		//�ļ�����
	int					 byDataSize;		//�ļ���С
	char				 byFileName[64];	//ͼƬ��
	int					 byErrorCode;		//�����룬����XM_WB_ERROR_CODE
	unsigned char		 byRes[36];
}FA_BLACKANDWHITELIST_CONFIG;

//����˽��Э���ϴ�
typedef struct FA_FS_PROTOCOL_S
{
	char szUDPaddr[64];	//������IP
	DWORD dwUDPport;	//�������˿ں�
	BYTE nUDPSDKEnable; //˽��Э���ϴ�ʹ�ܿ���
	BYTE szRes[3];		//����
	BYTE byRes[64];		//����
}FA_FS_PROTOCOL_S;

typedef struct FA_SMART_FACE_S
{
	INT			nEnable;			//����
	INT			nquality;			//������
	BYTE 		nExposureMode; 		//�����ع�ģʽ
	BYTE		nSnapMode;			//ץ��ģʽ
	BYTE 		nTrackmode;			//��������      0:�ر� 1:����
	BYTE		nFtpEnable;			//FTP�ϴ�����	0:�ر� 1:����
	INT			nFaceSize;			//����ʶ����С�ߴ�(60~300)
	INT			nMaxFaceSize;		//�������
	BYTE		nFaceBLC;			//��������
	BYTE		nPicMode;			//ͼƬ�ϴ���ʽ(0������1ԭͼ��2������ԭͼ)
	BYTE 		nParamCheckFlag;
	BYTE		byFaceAreaExpand;	//����ͼƬ�ܱ߱�����չϵ��
	BYTE		byPicPrefixEnable;	//�Զ���ǰ׺����
	CHAR		szPicPrefix[16];	//ͼƬǰ׺
	INT			nTrackFrameNum;		//����ץ��֡��-----����ץ��
	BYTE		bySnapNum;			//���ץ�Ĵ���-----�뿪��ץ��ģʽ
	BYTE		byIntervalTime;		//���ʱ��---���ץ�ģ���Ϊ��λ
	BYTE		byFacePicQual;		//����ͼƬ��������
	BYTE		byFramePicQual;		//ԭͼ��������
	INT			nIntervalFrame;		//���֡��---���ץ�ģ�֡Ϊ��λ
	BYTE		byAttributeEnable;	//�������Կ���
	BYTE		byIntervalSnapNum;	//ץ�Ĵ���------���ץ��ģʽ
	BYTE		byAlignmentRes[2];	//�ֽڶ��룬û���õ�
	INT			nGateIntervalFrame;	//���֡��----բ��ģʽ
	BYTE		byRes[16];
	//BYTE		byRes[24];
}FA_SMART_FACE;


typedef struct  FA_SNAP_FACE_CONFIG_S   
{
	SCHWEEK_TIME	  aTime;			//���ܲ���---����ʱ��
	FA_SMART_FACE    sSmartFace;  
	FA_FS_PROTOCOL_S  stFsProtocols;	//˽��Э��
}FA_SNAP_FACE_CONFIG;

typedef struct _FS_PROTOCOL_S
{
	char szUDPaddr[64];//������IP��ַ
	DWORD dwUDPport;//	�������˿ں�
	BYTE nUDPSDKEnable;//����
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


//������������   384�ֽ�
typedef struct FA_SMART_ALARM_S
{
	BYTE			aEnable;		//��������
	BYTE			aBEnable;		//��������������
	BYTE			aWEnable;		//��������������
	BYTE			aIoEnable;		//IO���ʹ��
	short			aIoTime;		//IO���ʱ�䣨�룩
	BYTE			aIoType;		//IO������ͣ�0����1��
	BYTE			aSimilarity;	//���ƶ� (0-100)
	SCHWEEK_TIME	aTime;			//����ʱ��
	BYTE		 	byRes[40];		
}FA_SMART_ALARM;

//�����㷨�汾��Ϣ
typedef struct FA_SMART_VERSION_INFO_S
{
	char szLib_version[16] ;    //�㷨��汾
	char szModel_version[16];	//ģ�Ͱ汾
	BYTE  nbyLic;				//����				
	BYTE  byRes[7];				//����
}FA_SMART_VERSION_INFO;

//ȫ���������Ӱ�
#define LINKAGE_MAX_USER   10
typedef struct FA_LINKAGE_BIND_S
{
	INT					nEnable;
	DWORD				dwMainIP[LINKAGE_MAX_USER];						//IP��ַ
	DWORD				dwIPAddr[LINKAGE_MAX_USER];						//IP��ַ
	DWORD				dwDataPort[LINKAGE_MAX_USER];					//���ݶ˿�	
	BYTE				Position[LINKAGE_MAX_USER];						//Ԥ��λ   1~255
	BYTE				CrossArea_Num[LINKAGE_MAX_USER];				//��������  1~4
	BYTE				byRes[50];
}FA_LINKAGE_BIND;

//=====================================================================================================

//=====================================================================================================

/*************************************************************************************************/


struct LOGIN_CFG//�޸�ǰ��ip��¼��
{
	std::string sUserName;		///< ��½����
	std::string sPassword;		///< ��½����
	int iEncryptType;			///< ������ܷ�ʽ
};

struct IPSetCfg
{
	int ch;
	int devtype;
	NetCommonConfig netcfg;
	LOGIN_CFG loginPram;
};

//�й������ֻ�����ƽ̨
typedef struct MobileWatchCfg
{
	Bool	Enable;
	char DevID[NAME_ID_LEN];				// �豸����
	char DevKey[NAME_ID_LEN];			// �豸��֤��
	char ManufacturerNo[NAME_ID_LEN];	// ���̱��
	char Mode[NAME_ID_LEN];				// �豸�ͺ� 
	char GroupAddr[NAME_URL_LEN];		// ����ƽ̨��ַ
	char ProvinceAddr[NAME_URL_LEN];		// ʡƽ̨��ַ
	char NatIP[NAME_ID_LEN];				// �豸�������������ַ
	int	NatPort;							// �豸������������˿�
	char BackupNatIP[NAME_ID_LEN];		// �豸���÷����������ַ
	int	BackupNatPort;					// �豸���÷���������˿�
	char TurnIP[NAME_ID_LEN];				// TurnServer��������ַ
	int	TurnPort;						// TurnServer�������˿�
	char BackupTurnIP[NAME_ID_LEN];		// TurnServer���ݷ�������ַ
	int	BackupTurnPort;					// TurnServer���ݷ������˿�
	char FtpIP[NAME_ID_LEN];				// ͼƬ�ϴ�FTP��������ַ
	int	FtpPort;							// ͼƬ�ϴ�FTP�������˿�
	char FtpAccount[NAME_ID_LEN];			// ͼƬ�ϴ�FTP�������ʺ�
	char	FtpPassword[NAME_ID_LEN];		// ͼƬ�ϴ�FTP����������
	char resume[NAME_URL_LEN];			// Ԥ��
}MobileWatchCfg;

struct OSDInfo
{
	int index;//����ͨ�������ʱ�����֮�������ȡֵ0��1
	int nX;//��Χ0-1000
	int nY;//��Χ0-1000
	int nChannel;//Ҫ���õ�ͨ��
	char pOSDStr[128];//Ҫ���ӵ��ַ���
};

struct NKBDeviceConfig
{
	std::vector<NetDecorderConfigV3> vNetDecorderConf; /*�����豸ͨ�����ñ�*/
};

struct PortService
{
	Bool Enable;		///< �Ƿ���
	int port;
};

//�ϴ��������ݵ�ָ��������
struct NetTransCommData
{
	bool bEnable;		///< �Ƿ���
	int SerialType;     ///�������ͣ���ö��CommTypes����,485��0,232��1
	int ServerType;     ///Э����������,��ö��NetTransProtocolType������tcp��0��udp��1
	char ServerAddr[NAME_PASSWORD_LEN];  //��������IP��ַ��
	int  ServerPort;	//�˿�;
	int  ReportTime;	//״̬��Ϣ���ͼ��ʱ�䣬��λ����
};


//wifiģʽ������ã������г���¼���Զ��л�APģʽ
struct NetWifiMode
{
	int autoSwitchAPMode; //ȡֵ  1:�Զ��л���APģʽ(����ģʽ)  0:���Զ��л�
	int reserve[7];
};
//�����ͻ�demo
struct NetUseProgram
{
	bool bEnable;   //�Ƿ���
	char UserName[NAME_PASSWORD_LEN];		///< �û���
	char Password[NAME_PASSWORD_LEN];		///< ����
	int Port;	///< �˿ں�
	char ServerAddr[NAME_PASSWORD_LEN];  //��������IP��ַ��
	char Describe[NAME_TOKEN_LEN];			//�豸����
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

//�ͻ���nas��������
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
	bool bEnable;	///�Ƿ�����
	int   IntevalTime; 	///����ϱ�ʱ��,����
	char AlarmType[NAME_PASSWORD_LEN];	///����
};

/// ����ģʽ����ȡ����Ӧ����
const char *getHvrModeName(int iHvrMode);


//�������Ʒ��������

enum ConsumerProCmd 
{
	CONSUMER_PRO_ADD_DEV,		///< ��ӱ����豸
	CONSUMER_PRO_STOP_ADD_DEV,	///< ֹͣ��ӱ����豸
	CONSUMER_PRO_DEL_DEV,		///< ɾ���Ѿ���ӵı����豸
	CONSUMER_PRO_CHANGE_DEV_NAME,	///< �޸��Ѿ�����豸������
	CONSUMER_PRO_NR				///< �������
};
// ���ݲ��������ȡ��Ӧ������
const char *getConsumerCmdName(int cmd);

struct ConsumerProOpr
{
	int  cmd;		//��ö��ConsumerProCmd
	char pArg1[16]; //CONSUMER_PRO_ADD_DEV ��Ҫ��ӵı����豸����
					//CONSUMER_PRO_DEL_DEV���豸��ID��
					//CONSUMER_PRO_MODE_DEV_NAME���豸��ID��
	char pArg2[32]; //CONSUMER_PRO_CHANGE_DEV_NAME���µ�����
	char res[12];
};

//�������Ʒ��ӵı����豸
struct ConsumerAlarmDev
{
	char pDevID[16];	//�����豸ID������ң����ID
	char pDevType[16];	//�����豸����
	char pDevName[32];	//�����豸�ǳ�
};
struct ConsumerAlarmDevList
{
	std::list<ConsumerAlarmDev> alarmDevList;
};

//�������Ʒ��������豸�������
struct ConsumerCommDevCfg
{
	bool	bCheckX1Remote; //�Ƿ���2.4Gң������û��ע�ᣬ�Ծ����Ƿ�ִ����������
	bool	bKeyAudioTip;	//�Ƿ���������ʾ��
	char	rev[6];
};

//ipv6
struct IPAddressV6
{
	bool bEnable;				//�Ƿ�����ipv6
	char pLocalLinkAddr[32];	//������·��ַ
	char pAddr[64];				//ipv6��ַ
	char pGateway[64];			//����
	int	iPrefix;  				//ipv6ǰ׺����
};


// �������������

enum ENUM_CHECK_FIRMWARE_FREQ
{
	CHECK_FIRMWARE_MANUAL,		//�ֶ������û���¹̼�
	CHECK_FIRMWARE_AUTO,			//��������ȥ��ʱ����¹̼�
	CHECK_FIRMWARE_NR,
};

struct OnlineUpgradeCfg
{
	char cEnable; //�Ƿ�����������������
	char pServerAddr[63];
	int  serverPort;
	int  iFirmwareCheckMode; //�Ƿ��Զ������û���¹̼�����ö��ENUM_CHECK_FIRMWARE_FREQ
	char cAutoUpgrade;		//�Զ��������°汾
	char cAutoUpgradeImp;	//ֻ�Զ�������Ҫ����
	char cIgnoreAllVersion;		//�������а汾��ҳ����ʾ
	char cIgnoreCurVersion;		//���Ե�ǰ�汾��ҳ����ʾ�����ָ��µİ汾��Ҳֻ��ʾһ��
	uint	  IgnoreCurTime;		//���Ե��ĵ�ǰ�汾��ʱ�䣬�� bIgnoreCurVersion����
	char cJustImpVersion;			//ֻ����Ҫ�汾��ʾ
	char rev[3];
};

#endif //__EXCHANGE_AL_NETWORK_EXCHANGE_H__

