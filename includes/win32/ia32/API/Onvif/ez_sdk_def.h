//geyijun @ 20120815
//��NetSDK  �汾��ͷ�ļ�Ϊ����������������
//ȥ��һЩ��ʷ������ʹ�ӿڸ��ӵļ������
//���������˳���������: 

//===���������===
//����֧�ֵ������꣬ȷ�������С��

//===������������===
//����һЩ���õ��������ͣ����ں�����д

//===��չ��������===
//����SDK ���к����ṹ�峣�õ����ͣ����ں�����д

//===������ö��===
//������󷵻���

//===�����ӿ����===
//���屨����صĽṹ�嶨��

//===�������ӿ����===
//������������صĽṹ�嶨��

//===��Ϣ�ӿ����===
//�����豸��Ϣ��صĽṹ�嶨��

//===�����ӿ����===
//===�洢�����ӿ�===
//===�û�����ӿ�===
//===��̨���ƽӿ�===
//�����豸������صĽṹ�嶨��
//���������������洢������ �û�����

//===ʵʱ���ӽӿ����===
//ʵʱ����������ݽṹ

//===�ط����ؽӿ����===
//�ط�����������ݽṹ

//===�Խ��ӿ����===
//�Խ�������ݽṹ

//===͸�����ڽӿ����===
//͸������������ݽṹ

//===�豸�����ӿ����===
//�豸����������ݽṹ

//===���ýӿ����===
//�����豸������صĽṹ�嶨��

#ifndef __EZ_SDK_DEF_H__
#define __EZ_SDK_DEF_H__

//=======================���������==================
//����֧�ֵ�����ģ������ȡֵ�ɸ��豸�������л��
#define EZ_SDK_NAME_LENGTH			128	//ͨ���ַ�������
#define EZ_SDK_PATH_LENGTH	      		256	//ͨ��·������
#define EZ_SDK_MAC_LENGTH       		32  	//MAC��ַ�ַ���󳤶�
#define EZ_SDK_TITLE_LENGTH			64	//���ñ������󳤶�
#define EZ_SDK_SERIAL_NUMBER		128	//�豸���кŵĳ���

#define EZ_SDK_CHANNEL_NUM 		32	//��Ƶ����ͨ������
#define EZ_SDK_DIGITAL_SOURCE_NUM 32	//һ������ͨ��֧�����������Դ��
#define EZ_SDK_VIDEOOUT_NUM 		2	//��Ƶ���ͨ������	
#define EZ_SDK_EXTRA_STREAM_NUM 	3	//�������������
#define EZ_SDK_NET_INTERFACE_NUM	2	//��������
#define EZ_SDK_ALARMIN_NUM 		8	//��������ͨ������
#define EZ_SDK_ALARMOUT_NUM 		8	//�������ͨ������	
#define EZ_SDK_COM_NUM				2	//���Ĵ��ڸ���	
#define EZ_SDK_DISK_NUM				8	//���֧�ֵĴ��̵ĸ���

#define EZ_SDK_WEEKS_NUM			7	//һ���ڵ�����
#define EZ_SDK_TSECT_NUM			6	//һ������ʱ�����
#define EZ_SDK_MIN_TSECT_NUM		2	//һ�����Сʱ�����
#define EZ_SDK_COVER_NUM			4	//���֧�ֵ�cover�ĸ���
#define EZ_SDK_MD_REGION_ROW		32	//����������������
#define EZ_SDK_MD_REGION_COLUMN	32	//����������������
#define EZ_SDK_RIGHT_TYPE_NUM		128	//��֧�ֵ�Ȩ�޵�����
#define EZ_SDK_MAX_GROUP_NUM		50	//���֧������
#define EZ_SDK_MAX_USER_NUM		60	//���֧���û���
#define EZ_SDK_DDNS_TYPE_NUM		6	//֧��DDNS  ��������͸���
#define EZ_SDK_DDNS_NUM			6	//֧��DDNS  �������ĸ���
#define EZ_SDK_ARSP_NUM			5	//֧��ARSP  �������ĸ��� 
#define EZ_SDK_ALARMSERVER_NUM	5     	//֧�ֱ������ĵĸ��� 
#define EZ_SDK_ACCESSFILTER_NUM	64	//IP���������
#define EZ_SDK_EMAIL_RECV_NUM		8	//EMAIL�����ߵ��������
#define EZ_SDK_MMS_RECV_NUM		8	//MMS�����ߵ��������
#define EZ_SDK_MOBILE_ACT_NUM		8	//���Ż����б������
#define EZ_SDK_WIFI_TOKEN_NUM		128	//WIFI ���� �ĳ���
#define EZ_SDK_WLAN_AP_NUM		32	//���֧�ֵ��������ص�AP  ����
#define EZ_SDK_RETURN_LOG_NUM		128	//���η��ص���־����
#define EZ_SDK_UPNP_PORT_NUM		32	//���֧�ֵ�UPUP  ӳ������Ķ˿ڵ�����

#define EZ_SDK_EXPOSURE_LEVEL_NUM 16	//���֧�ֵ��ع��ٶȵȼ���
#define EZ_SDK_HVR_CHN_MODE_NUM	32	//HVR ���֧�ֵ�ͨ��ģʽ��
#define EZ_SDK_POLYGON_POINT_NUM 	8	//����εĵ���
#define EZ_SDK_PEA_PERIMETER_NUM	1	//֧�ֵ�PERIMETER������
#define EZ_SDK_PEA_TRIPWIRE_NUM	1	//֧�ֵ�TRIPWIRE������
#define EZ_SDK_TRIPWIRE_IN_RULE	8	//��һ�����������������



//=======================������������==================
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

//=======================��չ��������==================

// IP  ��ַ
typedef union 
{
	uchar	c[4];	//"[3]xxx.[2]xxx.[1]xxx.[0]xxx"
	ushort	s[2];
	uint 		l;
}EZ_SDK_IPADDR;

// ϵͳʱ��
typedef struct EZ_SDK_SYSTEM_TIME{
	int  year;		//�ꡣ   
	int  month;	//�£�January = 1, February = 2, and so on.   
	int  day;		//�ա�   
	int  wday;	//���ڣ�Sunday = 0, Monday = 1, and so on   
	int  hour;		//ʱ��   
	int  minute;	//�֡�   
	int  second;	//�롣  
}EZ_SDK_SYSTEM_TIME;

//ʱ���
typedef struct EZ_SDK_TIMESECTION
{
	int 	enable;		//ʹ��mask
	int 	startHour;
	int	startMinute;
	int	startSecond;
	int	endHour;
	int	endMinute;
	int	endSecond;	
}EZ_SDK_TIMESECTION;	

//������
typedef struct EZ_SDK_CONFIG_WORKSHEET
{	
	EZ_SDK_TIMESECTION	schedule[EZ_SDK_WEEKS_NUM][EZ_SDK_TSECT_NUM];
}EZ_SDK_CONFIG_WORKSHEET;

//=======================������ö��=====================
typedef enum EZ_SDK_RET_CODE
{	
	EZ_SDK_NOERROR					= 0,			//û�д���
	EZ_SDK_SUCCESS					= 1,			//���سɹ�
	EZ_SDK_NOT_INIT					= -10000,		//SDKδ����ʼ��
	EZ_SDK_INVALID_CMD				= -10001,		//�Ƿ�����
	EZ_SDK_INVALID_PARAM				= -10002,		//�û��������Ϸ�
	EZ_SDK_INVALID_HANDLE				= -10003,		//�����Ч	
	EZ_SDK_CLEANUP_ERROR				= -10004,		//SDK�������
	EZ_SDK_TIMEOUT					= -10005,		//�ȴ���ʱ
	EZ_SDK_MEMORY_ERROR				= -10006,		//�ڴ���󣬴����ڴ�ʧ��
	EZ_SDK_NET_ERROR					= -10007,		//�������
	EZ_SDK_OPEN_FILE_ERROR			= -10008,		//���ļ�ʧ��
	EZ_SDK_UNKNOWN_ERROR			= -10009,		//δ֪����
	EZ_SDK_VERSION_ERROR				= -10010,		//�յ����ݲ���ȷ�����ܰ汾��ƥ��
	EZ_SDK_NOT_SUPPORT				= -10011,		//��֧��
	EZ_SDK_CONNECT_DEVICE_ERROR    	= -10012,		//�����豸������
	EZ_SDK_OPEN_CHANNEL_ERROR		= -10013,		//��ͨ��ʧ��
	EZ_SDK_CLOSE_CHANNEL_ERROR		= -10014,		//�ر�ͨ��ʧ��
	EZ_SDK_SUB_CONNECT_ERROR		= -10015,		//����ý��������ʧ��
	EZ_SDK_SUB_CONNECT_SEND_ERROR	= -10016,		//ý��������ͨѶʧ��
	EZ_SDK_NOPTZPROTOCOL 			= -10017,		//δ������̨Э��
	
	// �û������ִ�����
	EZ_SDK_NO_POWER					= -11300,		//��Ȩ��
	EZ_SDK_PASSWORD_NOT_VALID		= -11301,		//�˺����벻��
	EZ_SDK_USER_NOEXIST				= -11302,		//�û�������
	EZ_SDK_USER_LOCKED				= -11303,		//���û�������
	EZ_SDK_USER_IN_BLACKLIST			= -11304,		//���û����������(�ں�������)
	EZ_SDK_USER_HAS_USED				= -11305,		//���û��Ѿ���½
	EZ_SDK_USER_NOT_LOGIN			= -11306,		//���û�û�е�½
	EZ_SDK_ACCOUNT_INPUT_NOT_VALID 	= -11308,		//�û��������벻�Ϸ�
	EZ_SDK_ACCOUNT_OVERLAP			= -11309,		//�����ظ�
	EZ_SDK_ACCOUNT_OBJECT_NONE		= -11310,		//�����ڶ���, ���ڲ�ѯʱ
	EZ_SDK_ACCOUNT_OBJECT_NOT_VALID= -11311,		//�����ڶ���
	EZ_SDK_ACCOUNT_OBJECT_IN_USE	= -11312,		//��������ʹ��
	EZ_SDK_ACCOUNT_SUBSET_OVERLAP	= -11313,		//�Ӽ�����Χ (�����Ȩ�޳���Ȩ�ޱ��û�Ȩ�޳������Ȩ�޷�Χ�ȵ�)
	EZ_SDK_ACCOUNT_PWD_NOT_VALID	= -11314,		//���벻��ȷ
	EZ_SDK_ACCOUNT_PWD_NOT_MATCH	= -11315,		//���벻ƥ��
	EZ_SDK_ACCOUNT_RESERVED			= -11316,		//�����ʺ�
	
	//���ù�����ش�����	
	EZ_SDK_CONFIG_ERROR 				= -11400,		//�������ó���
	EZ_SDK_CONFIG_RESTART			= -11401,		//�������ú���Ҫ����
	EZ_SDK_CONFIG_REBOOT				= -11402,		//��Ҫ����ϵͳ
	EZ_SDK_CONFIG_FILE_ERROR			= -11403,		//д�ļ�����
	EZ_SDK_CONFIG_CAPS_ERROR			= -11404,		//�������Բ�֧��
	EZ_SDK_CONFIG_VERIFY_ERROR		= -11405,		//����У��ʧ��
	EZ_SDK_CONFIG_NOT_EXIST			= -11406,		//����������õ����ò�����
	EZ_SDK_CONFIG_PARSE_FAILED 		= -11407,		//���ý�������
	//�طſ��Ʋ���
	EZ_SDK_CTRL_PAUSE_ERROR			= -11500,		//��ͣʧ��
	EZ_SDK_FILE_NOT_FOUND				= -11501,		//����ʧ�ܣ�û���ҵ���Ӧ�ļ�

	//����Ĵ����Ƕ����泣�����Ĳ���
	EZ_SDK_TALK_ALAREADY_START 		= -11600,		//�Խ��Ѿ�����
	EZ_SDK_TALK_NOT_START 			= -11601,		//�Խ�δ����
	EZ_SDK_UPGRADE_ALAREADY_START 	= -11602, 	//�Ѿ���ʼ����
	EZ_SDK_UPGRADE_NOT_START  		= -11603,		//δ��ʼ����
	EZ_SDK_UPGRADE_DATA_ERROR  		= -11604,		//�������ݴ���
	EZ_SDK_UPGRADE_FAILED  			= -11605,		//����ʧ��
	EZ_SDK_UPGRADE_SUCCESS  			= -11606,		//�����ɹ�

}EZ_SDK_RET_CODE;

//=======================�����ӿ����==================
typedef enum EZ_SDK_EVENT_TYPE
{
	EVENT_SYSTEM_INIT = 0,			//ϵͳ��ʼ�����
	EVENT_ALARM_LOCAL,			//���ر�������
	EVENT_ALARM_NET,				//���籨��
	EVENT_ALARM_MANUAL,			//�ֶ�����
	EVENT_VIDEO_MOTION,			//��̬���
	EVENT_VIDEO_LOSS,				//��Ƶ��ʧ
	EVENT_VIDEO_BLIND,				//��Ƶ�ڵ�
	EVENT_VIDEO_ANALYSE,			//���ܱ���
	EVENT_NET_ABORT,				//�������
	EVENT_NET_IPCONFLICT,			//IP	��ַ��ͻ
	EVENT_STORAGE_NOTEXIST,		//���̲�����
	EVENT_STORAGE_LOWSPACE,		//�������������趨������ֵ	
	EVENT_STORAGE_FAILURE,		//���̲���ʧ��
	EVENT_STORAGE_READ_ERROR,	//���̶�ʧ��
	EVENT_STORAGE_WRITE_ERROR,	//����дʧ��
	EVENT_ALARM_EMERGENCY,		//???
	EVENT_DEC_CONNECT,			//�豸����ͨ���¼�
	EVENT_TYPE_NR,
}EZ_SDK_EVENT_TYPE;

//������Ϣ
typedef struct EZ_SDK_ALARM_INFO{
	int 	channel;		//
	int 	event;		//�μ�enum EZ_SDK_EVENT_TYPE
	int 	status;		//0-������1-��ʼ
	EZ_SDK_SYSTEM_TIME sysTime;	
}EZ_SDK_ALARM_INFO;

//=======================�������ӿ����==================
typedef enum EZ_SDK_ABILITY_TYPE
{
	EZ_ABILITY_GENERAL = 0,	//����������Ϣ(�������ͨ����)
	EZ_ABILITY_ALARM,			//��������������
	EZ_ABILITY_NETAPP,		//֧�ֵ����繦��
	EZ_ABILITY_ENCODE,		//��������
	EZ_ABILITY_COM,			//���ڹ���	
	EZ_ABILITY_PTZ,			//��̨Э��
	EZ_ABILITY_VIDEODETCT,	//��Ƶ����
	EZ_ABILITY_COVER,			//��Ƶ�ڵ���
	EZ_ABILITY_DDNS,			//DDNS����֧������
	EZ_ABILITY_VIDEOIN,		//����ͷ����������ص�������	
	EZ_ABILITY_NETIP,			//֧�ֵ��豸����Э��
	EZ_ABILITY_HVR_CH_MODE,	//HVR ֧�ֵ�ͨ������ģʽ
	EZ_ABILITY_IVS,			//���ܷ���������
	EZ_ABILITY_TYPE_NR,
}EZ_SDK_ABILITY_TYPE;

//��Ƶ��ʽ
typedef enum EZ_SDK_VIDEO_STANDARD
{
	EZ_PAL = 0,
	EZ_NTSC = 1,
}EZ_SDK_VIDEO_STANDARD;

//��������
typedef enum EZ_SDK_LANAGUAGE
{
	EZ_ENGLISH = 0,
	EZ_SIMPCHINESE,
}EZ_SDK_LANAGUAGE;

//��������
typedef enum EZ_SDK_STREAM_TYPE 
{
	MAIN= 0,
	EXTRA1=1,
	EXTRA2=2,
	EXTRA3=3,
	SNAP=4,
	STREAM_TYPE_NR,	
}EZ_SDK_STREAM_TYPE;

// ͨ��ͼ���С����	
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
	int  	numVideoInCh;		//��Ƶ����ͨ����
	int  	numVideoOutCh;		//��Ƶ���ͨ����
	int  	numVideoStream;		//��Ƶ������(���ΪSTREAM_TYPE)
	int  	numAlarmIn;			//��������ͨ����
	int  	numAlarmOut;		//�������ͨ����	
	int 	numCom;			//֧�ִ��ڵ�����0:��֧��
	int 	numDisk;			//֧�ִ��̵�����0:��֧��
	int 	numNetInterface;		//֧�ֵ�����������
	int	maskLanguage;		//֧�ֵ���������,�������EZ_SDK_LANAGUAGE
	int	maskStandard;		//֧�ֵ���ʽ����,�������EZ_SDK_VIDEO_STANDARD
	int 	reserve[26];			//
}EZ_SDK_ABILITY_GENERAL;

typedef struct EZ_SDK_ABILITY_ALARM
{
	int 	enableLocalAlarm;			//���ر���
	int 	enableNetAlarm;			//���籨��
	int 	enableIPConlict;			//IP��ַ��ͻ
	int 	enableNetAbort;			//�����쳣
	int 	enableStorageNotExit;		//�洢�豸������
	int 	enableStorageLowSpace;	//�洢�豸��������
	int 	enableStorageFailure;		//�洢�豸����ʧ��
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
	int	reserve[16];	//����	
}EZ_SDK_ABILITY_NETAPP;

typedef struct EZ_SDK_ABILITY_ENCODE
{
	int 	maxEncodePower;		//< ֧�ֵ�����������
	int	maxBps;					//< �������Kbps
	int 	numExStream;			//< �������ĸ���
	int 	enSnapStream;			//< �Ƿ�֧��ץͼ����
	int	channelSync;				//< ÿ��ͨ���ֱ����Ƿ���Ҫͬ��0-��ͬ��, 1 -ͬ��
	int 	maxPowerCh[EZ_SDK_CHANNEL_NUM];	//< ÿ��ͨ��֧�ֵ���߱�������
	int 	mainImageSize[EZ_SDK_CHANNEL_NUM];	//< ÿ��ͨ��ÿ����������֧�ֵ�ͼ��ֱ���, ȡEZ_SDK_IMAGE_SIZE_TYPE  ������
	int 	extraImageSize[EZ_SDK_CHANNEL_NUM][EZ_SDK_IMAGE_SIZE_NR];	//���������趨��ĳһ���ֱ���ʱ������Ӧ�ĸ������ֱ��ʷ�Χ!
	int	reserve[32];				//����	
}EZ_SDK_ABILITY_ENCODE;

typedef enum EZ_SDK_COM_FUNC		//֧�ֵĴ���Э��
{
	EZ_COM_CONSOLE = 0,		//��
	EZ_COM_TRANSPORT,		//͸������
	EZ_COM_PTZCTRL,			//��̨����
	EZ_COM_KEYBOARD,			//���̽ӿ�
	EZ_COM_FUNCTION_NR,
}EZ_SDK_COM_FUNC;	

typedef struct EZ_SDK_ABILITY_COM
{
	int	numCom;						//֧�ִ��ڵĸ���
	int 	maskComFun[EZ_SDK_COM_NUM];	//���ڵĹ�������(��Ӧ��enum EZ_SDK_COM_FUNC)
	int	reserve[32];						//����	
}EZ_SDK_ABILITY_COM;				

typedef enum EZ_SDK_PTZ_PROTO		//֧�ֵ���̨Э��
{
	PTZ_XXX = 0,							//
	PTZ_PROTO_NR,
}EZ_SDK_PTZ_PROTO;

typedef struct EZ_SDK_ABILITY_PTZ
{
	int 	numPtz;							//֧����̨�ĸ���
	int 	maskPtzProto[EZ_SDK_CHANNEL_NUM];	//��̨Э������(��Ӧ��enum EZ_SDK_PTZ_PROTO)
	int	reserve[32];						//����	
}EZ_SDK_ABILITY_PTZ;

typedef struct EZ_SDK_ABILITY_VIDEODETECT
{	
	int enableBlind;			//�Ƿ�֧���ڵ����
	int enableLoss;			//�Ƿ�֧����Ƶ��ʧ���
	int enableMotion;			//�Ƿ�֧�ֶ�̬���
	int enableResult;			//�Ƿ��ܹ��õ�ÿ������ļ����	
	int regionColumns;		//��̬������򻮷ֵ�����
	int regionRows;			//��̬������򻮷ֵ�����
	int	reserve[32];			//����		
}EZ_SDK_ABILITY_VIDEODETECT;
	
typedef struct EZ_SDK_ABILITY_COVER
{
	int 	numCover;			//�����ڵ�����
	int	reserve[32];			//����		
}EZ_SDK_ABILITY_COVER;

typedef struct EZ_SDK_ABILITY_DDNS
{
	int  	numDDNS;			//֧�ֵ�DDNS  �ĸ���
	char typeDDNS[EZ_SDK_DDNS_TYPE_NUM][EZ_SDK_NAME_LENGTH];//֧�ֵ�Э������
	int	reserve[32];			//����		
}EZ_SDK_ABILITY_DDNS;

typedef struct EZ_SDK_ABILITY_VIDEOIN
{
	//��������
	int  enableBrightness;		//���� �Ƿ�ɵ� ��1 �� 0����
	int  enableContrast;		//�Աȶ� �ɵ�
	int  enableHue;			//ɫ�� �ɵ�
	int  enableSaturation;	 	//���Ͷ� �ɵ�
	//�߼�����
	int  enableBacklight;		//���ⲹ�� ֧�ֵı��ⲹ���ȼ��� 0��ʾ��֧�ֱ��ⲹ��,1��ʾ֧��һ����������,�أ���2��ʾ֧��������������,��,�ͣ���3��ʾ֧��������������,��,��,�ͣ�
	int  enableColorSwitch;		//�ʺ�ת�� �ɵ�
	int  enableMirror;	     		//����  1 ֧�֣� 0��֧��
	int  enableFlip;	         	//��ת  1 ֧�֣� 0��֧��
	int  enableRejectFlicker;	//�Ƿ�֧���չ�Ʒ�������
	int  enableEsShutter;		//�Ƿ���������Ź���
	int  enableExposure;  		//�ع�ѡ������ ֵn�� �������ȼ�	: 0��ʾ��֧���ع���ƣ�1��ʾֻ֧���Զ��ع�, 2~(n-1)��ʾ֧�ֵ��ֶ��ع�ȼ�
	int  enableLimitedExposure;	//�Ƿ�֧�ִ�ʱ�������޵��Զ��ع�0-��֧�� 1-֧��
	int  enableCustomExposure;//�Ƿ�֧���û��Զ����ֶ��ع�ʱ��0-��֧�� 1-֧��
	int  enableReferenceLevel;	//�Ƿ�֧�ֲο���ƽֵ
	int  enableWhiteBalance;	// ��ƽ�� 0-��֧�ְ�ƽ�⣬1-֧���Զ���ƽ�⣬2-֧��Ԥ�ð�ƽ�⣨���龰ģʽ�� 3-Ҳ֧���Զ����ƽ��
	int  exposureSpeeds[EZ_SDK_EXPOSURE_LEVEL_NUM]; //֧�ֵ��ع��ٶ�
	//�ֶ�Ч��
	int  enableSectOptions;		//�Ƿ�֧�ֶַ�Ч������>1 ��ʾ֧�ֵķֶ���
	int  reserve[16];			//����
}EZ_SDK_ABILITY_VIDEOIN;

typedef struct EZ_SDK_ABILITY_NETIP
{
	int 	enableXM;		//����Э��
	int 	enableDH;		//��Э��
	int 	enableONVIF;	//ONVIF  Э��
	int	reserve[16];		//����	
}EZ_SDK_ABILITY_NETIP;

typedef struct EZ_SDK_HVR_CH_PARAM 
{
	int nD1Chn;			//֧�ֵ�D1·��
	int n960HChn;		//֧�ֵ�960H ·��
	int n720PChn;		//֧�ֵ�720P·��
	int n1080PChn;		//֧�ֵ�1080P·��
	int nCIFChn;			//֧�ֵ�CIF ͨ����
	int nHD1Chn;			//֧�ֵ�HD1 ͨ����
	int nRes[32];
}EZ_SDK_HVR_CH_PARAM;

typedef struct EZ_SDK_HVR_MODE
{
	EZ_SDK_HVR_CH_PARAM	digitalCap;	//֧�ֵ�����ͨ����Ϣ
	EZ_SDK_HVR_CH_PARAM	analogCap;	//֧�ֵ�ģ��ͨ����Ϣ
}EZ_SDK_HVR_MODE;

typedef struct EZ_SDK_ABILITY_HVR_CH_MODE
{
	int		modeNum;		//ʵ��֧�ֵ�ģʽ��
	EZ_SDK_HVR_MODE mode[EZ_SDK_HVR_CHN_MODE_NUM];
	int  		reserve[32];		//����
}EZ_SDK_ABILITY_HVR_CH_MODE;
		
//���ܷ����㷨ģ�� 
typedef struct EZ_SDK_ABILITY_IVS
{
	int enablePEA;	//�������
	int enableAVD;	//			
	int enableVFD;	//
	int enableOSC;	//���忴��
	int enableCPC;	//�������
	//PEA ����	
	int numPEARules;	//PEA��������
	int reserve[32];	//����	
}EZ_SDK_ABILITY_IVS;	

//=======================��Ϣ�ӿ����==================
typedef enum EZ_SDK_INFO_TYPE	
{
	GENERAL_INFO = 0,	//������Ϣ
	TIME_INFO,			//ʱ����Ϣ
	_DISK_INFO,			//Ӳ����Ϣ
	WORKSTATE_INFO,	//����״̬��Ϣ	
	AP_INFO,			//WIFI �ź�ɨ��
	L_3G_INFO	,		// 3G ����
	DIGITAL_CH_INFO,	//����ͨ��״̬
	NAT_INFO,			//NAT״̬��Ϣ
	_DDNS_INFO,			//DDNS ע��״̬��Ϣ
	PPPOE_INFO,			//PPPOE����״̬��Ϣ
	WLAN_INFO,			//WIFI ����״̬��Ϣ
	UPNP_INFO,			//UPNP ״̬��Ϣ
	INFO_NR,			
}EZ_SDK_INFO_TYPE;

typedef enum EZ_SDK_DEV_TYPE
{
	EZ_DEVICE_TYPE_DVR,	// ��ͨDVR�豸
	EZ_DEVICE_TYPE_NVS,	// NVS�豸
	EZ_DEVICE_TYPE_IPC,	// IPC�豸
	EZ_DEVICE_TYPE_HVR,	//���dvr
	EZ_DEVICE_TYPE_IVR,	//����dvr
	EZ_DEVICE_TYPE_MVR,	//����dvr
	EZ_DEVICE_TYPE_NR
}EZ_SDK_DEV_TYPE;

typedef struct EZ_SDK_GENERAL_INFO
{
	char	serialNo[EZ_SDK_SERIAL_NUMBER];	//�豸���к�
	char	softVersion[32];		//����汾
	char	hardVersion[32];		//Ӳ���汾
	char	encryptVersion[32];	//����汾
	char	builddate[32];			//��������: xxxx-xx-xx:xx:xx
	int	runtime;				//�������е�ʱ��;��λs
	int	devType;			//�豸���ͣ���EZ_SDK_DEV_TYPE
	char productName[64];		//��Ʒ����
	int	reserve[32];			//
}EZ_SDK_GENERAL_INFO;

typedef struct EZ_SDK_TIME_INFO
{
	EZ_SDK_SYSTEM_TIME curTime;	
}EZ_SDK_TIME_INFO;

typedef enum EZ_SDK_WORKDIR_TYPE
{
	READ_WRITE= 0,	//��д������(����¼���õ�)
	READ_ONLY	= 1,	//ֻ��������()
	SNAPSHOT	= 2,	//����������(���ץͼ�ļ�)
	WORKDIR_TYPE_NR,
}EZ_SDK_WORKDIR_TYPE;

typedef struct EZ_SDK_WORKDIR_ONE
{
	EZ_SDK_WORKDIR_TYPE	dirType;	//����Ŀ¼����
	int		isCurrent;		//�Ƿ�Ϊ��ǰ������
	long		totalSpace;		//������
	long		leftSpace;		//ʣ������
	long		errorFlag;		//�����־
	int		logicNo;			//�߼����	
	EZ_SDK_SYSTEM_TIME startTime;	//¼��ʼʱ��
	EZ_SDK_SYSTEM_TIME endTime;	//¼�����ʱ��
}EZ_SDK_WORKDIR_ONE;

typedef struct EZ_SDK_DISK_ONE
{
	int		physicalNo;	//����ӿڱ��
	int		physicalType;	//����������0-SD card; 1-UDisk; 2-IDE ; 3-SATA 4-FTP 5-SAMBA
	int		numPartion;	//������Ŀ
	EZ_SDK_WORKDIR_ONE	partion[4];
}EZ_SDK_DISK_ONE;

typedef struct EZ_SDK_DISK_INFO
{
	int		numDisk;
	EZ_SDK_DISK_ONE	disk[EZ_SDK_DISK_NUM];
}EZ_SDK_DISK_INFO;

typedef struct EZ_SDK_CHANNLE_STATUS
{
	int 		bitrate;		//����ͳ����Ϣ
	char		recording;	//�Ƿ�����¼��
	char 		alarmIn;		//�澯����״̬
	char		alarmOut;	//�澯���״̬
	char 		videoBlind;	//��Ƶ�ڵ�״̬
	char 		videoLoss;	//��Ƶ��ʧ״̬
	char 		videoMotion;	//�ƶ����״̬
	char 		videoAnalyse;//��Ƶ����״̬
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
	int 	encryption;		//��֤+��������(���ϱ�ʾ)
						// 0-"Off"�ر�;1-"Open"WEP������;2-"WEP64Bits" WEP������Կ��;
						// 3-"WEP128Bits"WEP������Կ��;5-"WPA_PSK_TKIP";6-"WPA_PSK_AES";
						// 7-"WPA2_PSK_TKIP";8-"WPA2_PSK_AES"
	int	channel;			//ͨ����
	int	rssi;				//�ź�ǿ��	
	int	reserve[32];
}EZ_SDK_AP_ONE;		

typedef struct EZ_SDK_AP_INFO
{	
	int		numDevice;
	EZ_SDK_AP_ONE device[EZ_SDK_WLAN_AP_NUM];
}EZ_SDK_AP_INFO;

typedef struct EZ_SDK_3G_INFO	// 3G�����ź�ǿ��
{
	int 	status;						//����״̬(ֻ��)
	EZ_SDK_IPADDR	addr;			//���ź��õ�IP��ַ	
	//���������źŵ�ǿ��	
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

typedef struct EZ_SDK_DIGITAL_CH_INFO	//����ͨ��״̬
{
	EZ_SDK_DIGITAL_CH_STATUS channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_DIGITAL_CH_INFO;

typedef struct EZ_SDK_NAT_INFO	//NAT ״̬��Ϣ
{
	int	status;	// 0: 1: 2:
	char	infoCode[EZ_SDK_NAME_LENGTH];
}EZ_SDK_NAT_INFO;

typedef struct EZ_SDK_DDNS_INFO
{
	int	status[EZ_SDK_DDNS_NUM];	//�Ƿ�����(ע��״̬��ֻ��)
	int 	reserve[8];		
}EZ_SDK_DDNS_INFO;

typedef struct EZ_SDK_PPPOE_INFO
{
	int 	status;						//����״̬(ֻ��)
	EZ_SDK_IPADDR	addr;			//���ź��õ�IP��ַ(ֻ��)
	int 	reserve[8];
} EZ_SDK_PPPOE_INFO;

typedef struct EZ_SDK_WLAN_INFO
{
	int	linkStatus;					//�Ƿ�������AP(ֻ��)
	int 	reserve[8];
} EZ_SDK_WLAN_INFO;

typedef struct EZ_SDK_UPNP_INFO
{
	int	mapState;					//״̬, 1: OK 0: NOT;
	int	mappedPort[EZ_SDK_UPNP_PORT_NUM];	//ӳ���Ķ˿�
	int 	reserve[8];
} EZ_SDK_UPNP_INFO;

// ��־��ѯ����
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
	int		typeMask;	//��־���� ����,EZ_SDK_LOG_TYPE
	int		startIndex;	//���ϴβ�ѯ�Ľ���ʱ����־ָ��
	EZ_SDK_SYSTEM_TIME beginTime;	//��ʼʱ��
	EZ_SDK_SYSTEM_TIME endTime;	//����ʱ��
	int	reserve[8];		
}EZ_SDK_LOG_CONDITION;

typedef struct EZ_SDK_LOG_ITEM
{
	int 	index;			//�����ڶ�β�ѯ��ʱ��ָ����ʼλ��
	char type[32];			//��־����	
	char user[32];			//��־�û�	
	char data[128];		//��־����	
	EZ_SDK_SYSTEM_TIME	time;	//��־ʱ��
	int	reserve[8];	
}EZ_SDK_LOG_ITEM;

typedef struct EZ_SDK_LOG_INFO
{
	int 	numLog;
	EZ_SDK_LOG_ITEM log[EZ_SDK_RETURN_LOG_NUM];
}EZ_SDK_LOG_INFO;

//¼���ѯ����
typedef	enum EZ_SDK_RECORD_TYPE
{
	_RECORD_ALL = 0,
	_RECORD_TIME,		//��ͨ¼��
	RECORD_MOTION,	//��Ƶ���¼��
	RECORD_IVS,		//���ܷ���¼��	
	_RECORD_ALARM,		//�ⲿ����¼��
	RECORD_MANUAL,	//�ֶ�¼��
	SNAP_ALL = 16,		
	SNAP_TIME,			//ץͼ
	SNAP_MOTION,	
	SNAP_IVS,			
	SNAP_ALARM,		
	SNAP_MANUAL,	
	EZ_RECORD_TYPE_NR,
}EZ_SDK_RECORD_TYPE;

typedef struct EZ_SDK_RECORD_CONDITION
{
	long long channelMask;			//ͨ���� ����(0-64ͨ��)
	long	typeMask;				//¼����������,EZ_SDK_RECORD_TYPE
	EZ_SDK_SYSTEM_TIME beginTime;	//��ʼʱ��
	EZ_SDK_SYSTEM_TIME endTime;	//����ʱ��
	int	reserve[8];					//
}EZ_SDK_RECORD_CONDITION;

typedef struct EZ_SDK_RECORD_FILE
{
	char filename[EZ_SDK_NAME_LENGTH];
	int 	channel;						//ͨ����
	int 	length;						//�ļ���С��λbyte
	EZ_SDK_SYSTEM_TIME beginTime;	//�ļ���ʼʱ��
	EZ_SDK_SYSTEM_TIME endTime;	//�ļ�����ʱ��
}EZ_SDK_RECORD_FILE;

//ÿ��ͨ����¼����Ϣ
typedef struct EZ_SDK_RECORD_TIME_INFO
{
	int iChannel;						//¼��ͨ����
	unsigned char cRecordBitMap[720];	//¼���¼��720���ֽڵ�5760λ����ʾһ���е�1440����
									//< 0000:��¼�� 0001:F_COMMON 0002:F_ALERT 0003:F_DYNAMIC 0004:F_CARD 0005:F_HAND
}EZ_SDK_RECORD_TIME_INFO;

typedef struct EZ_SDK_RECORD_TIME
{
	int nInfoNum;					//< ͨ����¼���¼��Ϣ����
	EZ_SDK_RECORD_TIME_INFO info[EZ_SDK_CHANNEL_NUM];   //< ͨ����¼���¼��Ϣ
}EZ_SDK_RECORD_TIME;

//=======================�����ӿ����==================
typedef	enum EZ_SDK_PROC_TYPE
{
	REBOOT_DEV = 0,		//�豸����
	RESET_CONFIG,		//��������
	CLEAR_LOG,			//�����־
	SET_TIME,			//����ʱ��
	PROC_TYPE_NR,
}EZ_SDK_PROC_TYPE;

typedef struct EZ_SDK_PROC_REBOOT_DEV
{
	int	reserve[8];	
}EZ_SDK_PROC_REBOOT_DEV;

typedef struct EZ_SDK_PROC_RESET_CONFIG
{
	int	generalConfig;	//0: 1:�ָ���������
	int	encodeConfig;
	int	recordConfig;	
	int	netCommConfig;	
	int	netAppConfig;	
	int	alarmConfig;
	int	comptzConfig;	//��̨����
	int	storageConfig;	//
	int	avioConfig;		//��������ͷ����
	int	userConfig;		//�û�����
	int	previewConfig;	// Ԥ������
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

//======================�洢�����ӿ�====================
typedef enum EZ_SDK_STORAGE_OP_CODE
{
	SET_TYPE,			//��������(��������)
	RECOVER,			//�ָ�����
	SET_PARTION,		//��������
	CLR_PARTION,		//ɾ������
	FORMAT_DISK,		//��ʽ��
	FORMAT_PARTION,	//��ʽ��	����
	STORAGE_MANAGE_CODE_NR,
}EZ_SDK_STORAGE_OP_CODE;

typedef struct EZ_SDK_STORAGE_MANAGE
{
	EZ_SDK_STORAGE_OP_CODE code;	//������
	union 
	{
		struct 
		{
			EZ_SDK_WORKDIR_TYPE	dirType;
		}setType;
		struct 
		{
			int 	serialNo;		//�������к�
			int 	partNo;		//������
			int 	partSize;		//�����Ĵ�С
		}partion;	//SET_PARTION/CLR_PARTION/FORMAT_PARTION,
		struct 
		{
			int 	serialNo;		//�������к�
		}disk;	
	}content;
	int	reserve[8];
}EZ_SDK_STORAGE_MANAGE;

//=======================�û�����ӿ�====================
typedef struct EZ_SDK_USER_INFO
{
	char		username[EZ_SDK_NAME_LENGTH];
	char		password[EZ_SDK_NAME_LENGTH];
	char		groupname[EZ_SDK_NAME_LENGTH];
	char		memo[EZ_SDK_NAME_LENGTH];
	int		rightNum;	
	char		rights[EZ_SDK_RIGHT_TYPE_NUM][EZ_SDK_NAME_LENGTH];	//���û���Ȩ��
	int		reserved;		//�Ƿ���(���ɱ�ɾ��)
	int		shareable;		//���û��Ƿ�������1-���ã�0-������
	int		reserve[8];
}EZ_SDK_USER_INFO;

typedef struct EZ_SDK_GROUP_INFO
{
	char		groupname[EZ_SDK_NAME_LENGTH];
	char		memo[EZ_SDK_NAME_LENGTH]; 
	int		rigthNum;
	char		rights[EZ_SDK_RIGHT_TYPE_NUM][EZ_SDK_NAME_LENGTH];	//�����Ȩ��
	int		reserve[8];
}EZ_SDK_GROUP_INFO;

typedef struct EZ_SDK_ALL_RIGHT_LIST
{
	int		rightNum;	//���е�Ȩ������
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
	char 		username[EZ_SDK_NAME_LENGTH];	//Ҫ�޸ĵ��û���
	EZ_SDK_USER_INFO	user;
}EZ_SDK_MODIFY_USER;

typedef struct EZ_SDK_MODIFY_GROUP	
{
	char 		groupname[EZ_SDK_NAME_LENGTH];//Ҫ�޸ĵ�����
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
	GET_RIGHTLIST = 0,	//��ȡ֧�ֵ�Ȩ���б�
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

//=========================��̨���ƽӿ�==================
typedef enum EZ_SDK_PTZ_OP_CODE
{
	PTZ_OP_UP = 0,			//��
	PTZ_OP_DOWN,			//��
	PTZ_OP_LEFT,			//��
	PTZ_OP_RIGHT,			//��
	PTZ_OP_LEFTUP,			//����
	PTZ_OP_LEFTDOWN,		//����
	PTZ_OP_RIGTHTOP,		//����
	PTZ_OP_RIGTHDOWN,		//����
	PTZ_OP_ZOOM_IN,		//�䱶��
	PTZ_OP_ZOOM_OUT,		//�䱶С
	PTZ_OP_FOCUS_FAR,		//������
	PTZ_OP_FOCUS_NEAR,	//����ǰ��
	PTZ_OP_IRIS_OPEN,		//��Ȧ����
	PTZ_OP_IRIS_CLOSE,		//��Ȧ��С	
	
	PTZ_OP_LAMP_ON,		//�ƹ⿪
	PTZ_OP_LAMP_OFF,		//�ƹ��
	
	PTZ_OP_SET_PRESET,		//����Ԥ�õ�
	PTZ_OP_CLEAR_PRESET,	//���Ԥ�õ�
	PTZ_OP_GOTO_PRESET,	//תԤ�õ�

	PTZ_OP_AUTOPAN_ON,	//��ʼ�Զ�ˮƽ��ת	
	PTZ_OP_AUTOPAN_OFF,	//�ر��Զ�ˮƽ��ת	
	PTZ_OP_SET_LEFTLIMIT,	//������߽�
	PTZ_OP_SET_RIGHTLIMIT,//�����ұ߽�
	
	PTZ_OP_AUTOSCAN_ON,	//�Զ�ɨ�迪ʼ
	PTZ_OP_AUTOSCAN_OFF,	//�Զ�ɨ�迪ֹͣ

	PTZ_OP_ADD_TOUR,		//Ѳ������(����Ѳ����·�����Ԥ���!!!)
	PTZ_OP_DELFROM_TOUR,	//��Ѳ����·��ɾ��Ԥ���!
	PTZ_OP_DEL_TOUR,		//���Ѳ��p1Ѳ����·
	PTZ_OP_START_TOUR,	//��ʼѲ��	
	PTZ_OP_STOP_TOUR,		//ֹͣѲ��	
	
	PTZ_OP_GOTO_POSITION,	//���ٶ�λ	

	PTZ_OP_AUXON,			//��������,  �ر�����������
	PTZ_OP_MENU,			//����˵����������а��������أ�ȷ���ȵ�
	PTZ_OP_FLIP,			//��ͷ��ת
	PTZ_OP_RESET,			//< ��̨��λ
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

//======================ʵʱ���ӽӿ����===================
typedef struct EZ_SDK_REALPLAY_REQ
{
	int 	channel;			//ͨ����
	EZ_SDK_STREAM_TYPE stream;	
	int	reserve[32];		
}EZ_SDK_REALPLAY_REQ;

//======================�ط����ؽӿ����===================
typedef struct EZ_SDK_PLAYBACK_REQ_BY_FILE
{
	int 	channel;			//ͨ���ţ���Ϊ�ط�������ͨ����Ϊ����
	char filename[EZ_SDK_NAME_LENGTH];	//�ļ���
	EZ_SDK_SYSTEM_TIME beginTime;		//��ʼʱ��
	EZ_SDK_SYSTEM_TIME endTime;			//����ʱ��
	int	reserve[32];
}EZ_SDK_PLAYBACK_REQ_BY_FILE;

typedef struct EZ_SDK_PLAYBACK_REQ_BY_TIME
{
	int 	channel;					//ͨ����
	int 	fileType;					//�μ�EZ_SDK_RECORD_TYPE
	EZ_SDK_SYSTEM_TIME beginTime;	//��ʼʱ��
	EZ_SDK_SYSTEM_TIME endTime;	//����ʱ��
	int	reserve[32];
}EZ_SDK_PLAYBACK_REQ_BY_TIME;

typedef enum EZ_SDK_PACKET_TYPE
{
	FILE_DATA =	0,		//�ļ�����
	_VIDEO_I_FRAME,		//��ƵI ֡
	_VIDEO_B_FRAME,		//��ƵB ֡
	_VIDEO_P_FRAME,		//��ƵP ֡
	_VIDEO_J_FRAME,		//ͼƬ֡
	AUDIO_DATA,		//��Ƶ֡
	TRANSCOM_DATA,	//��������
	PACKET_TYPE_NR,	//
}EZ_SDK_PACKET_TYPE;

typedef struct EZ_SDK_PACKET_INFO
{
	EZ_SDK_PACKET_TYPE	packetType;	
	EZ_SDK_SYSTEM_TIME	time;	//����ʱ��
	uint64	timestamp;			//���ʱ��ms
	long		frameSeq;			//֡���
	long		frameRate;			//֡��
	int		width;				//ͼ����
	int		height;				//ͼ��߶�
	int		reserve[32];			//
} EZ_SDK_PACKET_INFO;

//�طſ���
typedef enum EZ_SDK_PLAYBACK_OP
{
	PLAY_BACK_PAUSE,			//��ͣ�ط�
	PLAY_BACK_CONTINUE,		//�����ط�
	PLAY_BACK_FAST,			//���ٻط�
	PLAY_BACK_SLOW,			//���ٻط�
	PLAY_BACK_SEEK,			//�طŶ�λ��ʱ��sΪ��λ 
	PLAY_BACK_SEEK_PERCENT,	//�طŶ�λ,�ٷֱ� 
	PLAY_BACK_OP_NR,
}EZ_SDK_PLAYBACK_OP;	

//�豸�����ķ���ֵ
typedef	struct NetInterface 
{
	char 	hostIP[32];
	char subMask[32];
	char 	gateway[32];
	char 	mac[32];
}NetInterface;

typedef struct EZ_SDK_SEARCH_DEVICE
{
	//�豸������Ϣ
	char	serialNo[EZ_SDK_SERIAL_NUMBER];	//�豸���к�
	EZ_SDK_DEV_TYPE devType;			//�豸����		
	char productName[64];					//��Ʒ����
	char 	hostname[EZ_SDK_NAME_LENGTH];	//��������
	//������Ϣ
	NetInterface interfaces[EZ_SDK_NET_INTERFACE_NUM];
	//����˿���Ϣ
	int		tcpPort;	
	int		udpPort;	
	int		httpPort;	
	int		reserve[32];	
}EZ_SDK_SEARCH_DEVICE;

//======================���ýӿ����===================
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

	CONFIG_NETIP_COMMON,		//ͨ�õ�����
	CONFIG_NETIP_XM,			//����Э��
	CONFIG_NETIP_DH,			//��Э��
	CONFIG_NETIP_ONVIF,		//ONVIF  Э��

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

	CONFIG_CH_MODE,		//HVR  ͨ��ģʽ����
	CONFIG_DIGITAL_CH,		//HVR  ����ͨ��������

	CONFIG_PEA_RULES,			//PEA ������
	CONFIG_IVS_DETECT,			//IVS ��������
	
	CONFIG_WATERMARK,		//ˮӡ����
	CONFIG_ENCODE_STATICPARAM,	//��������̬����

	CONFIG_TYPE_NR,
}EZ_SDK_CONFIG_TYPE;

typedef struct EZ_SDK_CONFIG_GENERAL
{
	int 	localNo;				//< �������
	char nameMachine[EZ_SDK_NAME_LENGTH];	//< �������ƻ���	
	char dateFormat[32];		//���ڸ�ʽ"yyyy-MM-dd HH:mm:ss",
							//yy = �꣬�������� 
							//yyyy = �꣬������
							//M = ��0 ��ʼ�� 
							//MM = 0 ��ʼ�� 
							//MMMM = ������
							//d = ��0��ʼ�� 
							//dd = 0��ʼ��
							//H = ��0��ʼ24Сʱ
							//HH = 0��ʼ24Сʱ 
							//h = ��0��ʼ12Сʱ 
							//hh = 0��ʼ12Сʱ
	int 	standard;			//�ο�EZ_SDK_VIDEO_STANDARD
	int 	language;			//�μ�EZ_SDK_LANAGUAGE
	int 	timeFormat;			//ʱ���ʽ:	'12',	'24'
	int 	workDay;			//������
	int 	dstRule;				//����ʱ���� 
	EZ_SDK_SYSTEM_TIME	 dstStart;	//����ʱ�Ŀ�ʼʱ��
	EZ_SDK_SYSTEM_TIME	 dstEnd;		//����ʱ�Ľ���ʱ��
	int 	reserve[32];			
}EZ_SDK_CONFIG_GENERAL;

typedef struct EZ_SDK_CONFIG_AUTOMAINTAIN
{
	int 		autoRebootDay;		//-1��ʾ������0~6��ʾ������~��������7��ʾÿ��
	int 		autoRebootHour;		//0-23
	int 		autoRebootMinute;	//0~59
	int 		reserve[29];			
}EZ_SDK_CONFIG_AUTOMAINTAIN;


typedef struct EZ_SDK_CONFIG_STORAGE_GROBAL
{
	int 		holdDays;			//�����ļ��ı�������������ʱ��Ľ���ɾ����0��ʾ��������
	int 		enableLog;			//�Ƿ��¼¼���ѯ����־
	int 		overWrite;			//�Ƿ�����ѭ������
	int 		reserve[29];			//
}EZ_SDK_CONFIG_STORAGE_GROBAL;

typedef enum EZ_SDK_PTZ_LINK_TYPE
{
	_NONE = 0,
	PRESET,		//Ԥ�õ�
	TOUR,		//Ѳ��
	_PATTERN,	//Ѳ��
}EZ_SDK_PTZ_LINK_TYPE;

typedef struct EZ_SDK_PTZ_LINK
{
	EZ_SDK_PTZ_LINK_TYPE type;	//���������� 
	int		value;				//���������Ͷ�Ӧ��ֵ 
}EZ_SDK_PTZ_LINK;	

typedef struct EZ_SDK_CONFIG_EVENT_HANDLER
{
	EZ_SDK_CONFIG_WORKSHEET	schedule;	//ʱ�����ñ�
	
	int		enableRecord;	//¼��ʹ��	
	int 		maskRecord;		//¼��ͨ������	
	int 		latchRecord;		//¼����ʱʱ�䣨�룩	10~300

	int 		enableAlarmOut;	//�������ʹ��	
	int 		maskAlarmOut;	//�������ͨ������	
	int		latchAlarmOut;	//���������ʱʱ�䣨�룩10~300

	int 		enableSnapshot;	//����ʹ��
	int 		maskSnapshot;	//����ͨ��������
	int 		periodSnapshot;	//֡�����ÿ������֡ץһ��ͼƬ��
	int 		timesSnapshot;	//���Ĵ���	

	int		enableTour;		// ��Ѳʹ�� 
	int		maskTour;		// ��Ѳ���� 
	
	int		enableMatrix;		// ����ʹ�� 
	int		maskMatrix;		// �������� 
	
	int		enabelPtzLink;	//��̨����ʹ��	
	EZ_SDK_PTZ_LINK PtzLink[EZ_SDK_CHANNEL_NUM];

	int		enableEmail;		//�����ʼ��������ͼƬ����Ϊ����
	int		enableMessage;	//�ϴ�������������
	int 		enableBeep;		//����
	int		enableVoice;		//������ʾ
	int		enableTip;		//��Ļ��ʾ
	int		enableFTP;		//����FTP���� 
	int		enableMsgtoNet;	// ��Ϣ�ϴ�������ʹ�� 

	int		dejitter;			//�ź�ȥ����ʱ�䣬��λΪ��
	int		enableLog;		//�Ƿ��¼��־
	int 		delay;			//����ʱ����ʱ����Ч

	int		enableSMS;          	//���Ͷ���
	int 		enableMMS;		//���Ͳ���

	int		enableShowInfo;	//�Ƿ���GUI�Ϻͱ�������ʾ������Ϣ
	int		maskShowInfo;	//Ҫ������ʾ������Ϣ��ͨ������
	char 		pAlarmInfo[EZ_SDK_NAME_LENGTH];//Ҫ��ʾ�ı�����Ϣ

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
	int 				lowerLimit;		//Ӳ��ʣ����������, �ٷ���
	EVENT_HANDLER 	eventHandler;
}EZ_SDK_CONFIG_STORAGE_LOWSPACE;

typedef struct  EZ_SDK_CONFIG_COLOR_PARAM
{	
	int 		enable;				//ʹ��
	int 		brightness;			//����		0-100		
	int 		contrast;				//�Աȶ�	0-100	
	int 		saturation;			//���Ͷ�	0-100	
	int 		hue;					//ɫ��		0-100	
	//
	int 		acutance;          		//��� 0-15			 
	int		gain;				//����	0-100 , �ڣ�λ��1��ʾ�Զ�����	
	int		whitebalance;		//�Զ��׵�ƽ���ƣ�bit7��λ��ʾ�����Զ�����.0x0,0x1,0x2�ֱ�����,��,�ߵȼ�

	EZ_SDK_TIMESECTION section;	//��Ӧ��ʱ���	
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
	int	leftMargin;		//TV��߾ࣺ0��100 
	int	topMargin;		//TV�ϱ߾ࣺ0��100 
	int	rightMargin;		//TV�ұ߾ࣺ0��100 
	int	bottomMargin;	//TV�±߾ࣺ0��100 
	int	brightness;		//����	��0��100 
	int	contrast;			//�Աȶȣ�0��100 
	int	satuation;		//ɫ�ʱ��Ͷ�	0~100
	int	hue;				//ɫ��	0~100
	int	width;			//ˮƽ�ֱ���
	int	height;			//��ֱ�ֱ���	
	int	bpp;			//��ɫ���	
  	int	signalFormat;		//����ź�ģʽ	"Auto","TV","VGA","DVI","HDMI","SDI"
	int	refreshRate;		//ˢ��Ƶ��	
	int	screenPtctEn;		//����ʹ�ܱ�־ 
	int	screenPtctTime;	//����ʱ�� 
	int	reserve[3];		//���� 
}EZ_SDK_CONFIG_VIDEO_OUT;

typedef struct  EZ_SDK_CONFIG_VIDEO_OUT_ALL
{
	EZ_SDK_CONFIG_VIDEO_OUT channel[EZ_SDK_VIDEOOUT_NUM];
}EZ_SDK_CONFIG_VIDEO_OUT_ALL;

typedef struct  EZ_SDK_CONFIG_SECTOPTION 
{
	EZ_SDK_TIMESECTION section;	//��Ӧ��ʱ���
	int	exposureSensitive;		//�ع������ȵȼ�	��1-6��
	int	exposureSpeed;			//ȡֵ��Χȡ�����豸��������0-�Զ��ع� 1~n-1-�ֶ��ع�ȼ�
								//n-��ʱ�������޵��Զ��ع� n+1-�Զ���ʱ���ֶ��ع� (n��ʾ֧�ֵ��ع�ȼ�����
	int	exposureValue1;
	int	exposureValue2;
	int	referenceLevel;			//
	int	whiteBalance;			//��ƽ�� 0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night... -1:custom
	int	gainRed;			
	int	gainGreen;		
	int	gainBlue;		
	int	reserve[16];				//���� 
}EZ_SDK_CONFIG_SECTOPTION;

typedef struct EZ_SDK_CONFIG_VIDEO_IN
{
	int	backlight;	// ���ⲹ���ȼ�	ȡֵ��Χȡ�����豸��������
					// 0-�ر�
					// 1-���ⲹ��ǿ��1
					// 2-���ⲹ��ǿ��2
					// n-��󱳹ⲹ���ȼ���
	int	colorSwitch;	//������ҹ�Զ��л���ɫ;0-���ǲ�ɫ1-���������Զ��л�2-���Ǻڰ�
	int 	mirror;		//�Ƿ������澵����	
	int	flip;			//�Ƿ������淭ת����	
	int	rejectFlicker;	//�Ƿ����չ�Ʒ�������				
	int	esShutter;	//�Ƿ���������Ź���	

	int 	apertureMode;//�Զ���Ȧģʽ
	int 	ircut_mode;	//IR-CUT�л� 0 = �����ͬ���л� 1 = �Զ��л�

	//����ѡ��
	int	switchMode;	//0-���л���1-���������л���2-����ʱ���л�
	int	brightnessThreshold;	//������ֵ��С�ڸ�����ʱ��Ҫ�л���ҹ��Ĳ���(�ڵ�һ���͵ڶ���ʱ���֮���л�)
	EZ_SDK_CONFIG_SECTOPTION options[EZ_SDK_MIN_TSECT_NUM];
	
	int	reserve[32];		//���� 
}EZ_SDK_CONFIG_VIDEO_IN;

typedef struct  EZ_SDK_CONFIG_VIDEO_IN_ALL
{
	EZ_SDK_CONFIG_VIDEO_IN channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_VIDEO_IN_ALL;

typedef struct EZ_SDK_CONFIG_RECORD
{	
	int 		mode;				//0-�Զ�¼��1-�ֶ�¼��2-�ر�¼��
	int 		preRecord;			//Ԥ¼ʱ�䣬Ϊ��ʱ��ʾ�ر� 
	int 		streamType;    		//¼������ 0-������ 1-������1 2-������2 3-������3
	int 		packetLength;		//¼�������ȣ����ӣ�[1, 255]
	int 		redundancy;			//���࿪��
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
	int 		mode;				//0-�Զ�ץͼ��1-�ֶ�ץͼ��2-�ر�ץͼ
	int 		preSnap;				//Ԥץʱ��
	int 		streamType;    		//¼������ 0-������ 1-������1 2-������2 3-������3
	int		reserve[16];			
}EZ_SDK_CONFIG_SNAP_SCHEDULE;

typedef struct  EZ_SDK_CONFIG_SNAP_ALL
{
	EZ_SDK_CONFIG_SNAP_SCHEDULE channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_SNAP_ALL;

//�������õ�����
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
	int		compression;		//ѹ������
	int		width;			//��
	int		height;			//��
	int 		ctrlMode;		//���ʿ���ģʽ						
	int		bitrate;			//����bps
	int		quality;			//����
	int		fps;				//֡��
	int 		gop;			//I  ֡���,��λΪ֡��
	int 		reserve[8];	
}EZ_SDK_VIDEO_OPTION;

typedef struct EZ_SDK_AUDIO_OPTION
{
	uchar	enable;	
	uchar	compression;		//ѹ������
	int		frequency;		//��Ƶ����Ƶ��	
	int		depth;			//�������
	int		packetPeriod;		//�������ms
	int 		mode;			//����ģʽ(AMR ʱ����)
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
	EZ_SDK_ENCODE_OPTION	extraStream[EZ_SDK_EXTRA_STREAM_NUM];	//���֧�ֵĸ���������
																	//���������������!!!
	EZ_SDK_ENCODE_OPTION	snapStream;
}EZ_SDK_CONFIG_ENCODE;

typedef struct  EZ_SDK_CONFIG_ENCODE_ALL
{
	EZ_SDK_CONFIG_ENCODE channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_ENCODE_ALL;

typedef struct  EZ_SDK_CONFIG_WIDGET_ATTR
{
	int 		enable;		//ʹ��
	ulong	fgRGBA;		//ǰ��ɫ
	ulong	bgRGBA;		//����ɫ
	EZ_Rect		position;		//��8192 X8192  Ϊ�ο�����
	int		mainBlend;	//�Ƿ���ӵ���·�����ı�־λ
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
	int 	enable;		//ʹ��
	int 	level;		//������ 
	char 	region[EZ_SDK_MD_REGION_ROW][EZ_SDK_MD_REGION_COLUMN];
	EVENT_HANDLER eventHandler;	
}EZ_SDK_CONFIG_MOTION_DETECT;

typedef struct  EZ_SDK_CONFIG_MOTION_DETECT_ALL
{
	EZ_SDK_CONFIG_MOTION_DETECT channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_MOTION_DETECT_ALL;

typedef struct  EZ_SDK_CONFIG_BLIND_DETECT
{
	int 	enable;		//ʹ��					
	int 	level;		//������ 
	EVENT_HANDLER eventHandler;	
}EZ_SDK_CONFIG_BLIND_DETECT;	

typedef struct  EZ_SDK_CONFIG_BLIND_DETECT_ALL
{
	EZ_SDK_CONFIG_BLIND_DETECT channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_BLIND_DETECT_ALL;

typedef struct  EZ_SDK_CONFIG_LOSS_DETECT
{
	int 	enable;		//ʹ��
	int 	level;		//������ 
	EVENT_HANDLER eventHandler;	
}EZ_SDK_CONFIG_LOSS_DETECT;	

typedef struct  EZ_SDK_CONFIG_LOSS_DETECT_ALL
{
	EZ_SDK_CONFIG_LOSS_DETECT channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_LOSS_DETECT_ALL;

typedef struct EZ_SDK_CONFIG_ALARM_IN
{
	int	enable;		//ʹ��
	int	sensorType;	//0:����1:����
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
	int	mode;		//ģʽ0-�Զ�������1-ǿ�Ʊ�����2-�رձ���
	int 	reserve[8];	
}EZ_SDK_CONFIG_ALARM_OUT;

typedef struct  EZ_SDK_CONFIG_ALARM_OUT_ALL
{
	EZ_SDK_CONFIG_ALARM_OUT channel[EZ_SDK_ALARMOUT_NUM];
}EZ_SDK_CONFIG_ALARM_OUT_ALL;

//Զ�˷������ṹ����
typedef struct EZ_SDK_REMOTE_SERVER
{
	char serverName[EZ_SDK_NAME_LENGTH];		//����������
	EZ_SDK_IPADDR serverip;					//������IP ��ַ
	int	serverport;							//����˿�
	char	username[EZ_SDK_NAME_LENGTH];		//�������ϵ��û���
	char	password[EZ_SDK_NAME_LENGTH];		//�������ϵ�����
	int	anonymity;							//�Ƿ�������¼
}EZ_SDK_REMOTE_SERVER;

typedef struct EZ_SDK_CONFIG_NETWORK_INTERFACE
{
	char    	name[16];			//��������
	char 		mac[32];				//Mac ��ַ
	char 		hostIP[32];			//IP ��ַ	
    	char 		subMask[32];                //��������
    	char		gateWay[32];			//���� IP	
	int 		reserve[8];	
}EZ_SDK_CONFIG_NETWORK_INTERFACE;

typedef struct EZ_SDK_CONFIG_NETWORK
{
    	char		hostName[EZ_SDK_NAME_LENGTH];			//������
    	char		domain[EZ_SDK_NAME_LENGTH];			//������
    	char		defaultInterface[EZ_SDK_NAME_LENGTH];	//Ĭ������	
	EZ_SDK_CONFIG_NETWORK_INTERFACE interfaces[EZ_SDK_NET_INTERFACE_NUM];	
}EZ_SDK_CONFIG_NETWORK;	

typedef struct EZ_SDK_CONFIG_DHCP_ONE
{
	char 	name[16];	//��������
	int 	enable;		//dhcp ʹ�ܱ�־λ
}EZ_SDK_CONFIG_DHCP_ONE;

typedef struct EZ_SDK_CONFIG_DHCP
{
	EZ_SDK_CONFIG_DHCP_ONE  interfaces[EZ_SDK_NET_INTERFACE_NUM];
}EZ_SDK_CONFIG_DHCP;

typedef struct EZ_SDK_CONFIG_DNS
{
	EZ_SDK_IPADDR	primaryDNS;		//��
	EZ_SDK_IPADDR	secondaryDNS;	//��
}EZ_SDK_CONFIG_DNS;

typedef struct EZ_SDK_CONFIG_NETABORT	//�������
{
	int 	enable;
	EVENT_HANDLER eventHandler;
}EZ_SDK_CONFIG_NETABORT;

typedef struct EZ_SDK_CONFIG_IPCONFICT	//IP��ͻ���
{
	int 	enable;
	EVENT_HANDLER eventHandler;
}EZ_SDK_CONFIG_IPCONFICT;

typedef struct EZ_SDK_CONFIG_ACCESSFILTER
{
	int		enable;	//
	int		type;	// 0:TrustList 1:BannedList
	EZ_SDK_IPADDR bannedList[EZ_SDK_ACCESSFILTER_NUM];	//�������б�
	EZ_SDK_IPADDR trustList[EZ_SDK_ACCESSFILTER_NUM];	//�������б�
}EZ_SDK_CONFIG_ACCESSFILTER;

typedef struct EZ_SDK_CONFIG_DDNS_ONE
{
	int	enable;							//�Ƿ�����0-��������1-����	
	char	protocal[EZ_SDK_NAME_LENGTH];	//Э������Ŀǰ֧��'JUFENG' ," CN99 ", " Oray ", "NO-IP",
	char	hostname[EZ_SDK_NAME_LENGTH];	//�������뵽������
	int	keepAlive;						//����ʱ�䣬��λ��
	EZ_SDK_REMOTE_SERVER server;		//��������Ϣ
	int 	reserve[8];						
}EZ_SDK_CONFIG_DDNS_ONE;
typedef struct EZ_SDK_CONFIG_DDNS
{
	EZ_SDK_CONFIG_DDNS_ONE server[EZ_SDK_DDNS_NUM];
}EZ_SDK_CONFIG_DDNS;

typedef struct EZ_SDK_CONFIG_NTP
{
	int	enable;			//�Ƿ�����NTP
	int	reflesh;			//����ʱ�����ڣ���λ��
	int	timeZone;		//ʱ����-12~13,����Ķ�Ϊ0-25
	EZ_SDK_REMOTE_SERVER server;	//��������Ϣ	
	int 	reserve[8];
}EZ_SDK_CONFIG_NTP;

typedef struct EZ_SDK_CONFIG_EMAIL
{
	int		enable;
	EZ_SDK_REMOTE_SERVER server;			//��������Ϣ	
	char 		sender[EZ_SDK_NAME_LENGTH];		//"xxx@xxxx.com"
	char 		receivers[EZ_SDK_EMAIL_RECV_NUM][EZ_SDK_NAME_LENGTH];	//�ռ����б�
	char		title[EZ_SDK_NAME_LENGTH];		//�ʼ�����
	int		attachEnable;						//�Ƿ���Ӹ���
	int		useSSL;							//�Ƿ�ʹ��ssl  
	EZ_SDK_TIMESECTION section[2];			//email��Чʱ��
	int 		reserve[8];
}EZ_SDK_CONFIG_EMAIL;	

typedef struct EZ_SDK_CONFIG_PPPOE
{
	int		enable;					//
	char		username[EZ_SDK_NAME_LENGTH];	//�û���
	char		password[EZ_SDK_NAME_LENGTH];	//����
	int 		reserve[8];
} EZ_SDK_CONFIG_PPPOE;

typedef struct EZ_SDK_CONFIG_WLAN
{
       int    	enable;
	char	 	ssid[EZ_SDK_NAME_LENGTH];	
	int 		channel;		//channel
	int		linkMode;	//����ģʽ0:auto 1:adhoc 2:Infrastructure
	int  	 	encryption;	//��֤+��������(���ϱ�ʾ)
						// 0-"Off"�ر�;1-"Open"WEP������;2-"WEP64Bits" WEP������Կ��;
						// 3-"WEP128Bits"WEP������Կ��;5-"WPA_PSK_TKIP";6-"WPA_PSK_AES";
						// 7-"WPA2_PSK_TKIP";8-"WPA2_PSK_AES"
	int		keyType; 	//0:Hex 1:ASCII (ֻ��wepģʽ����Ч)
    	char   	keys[EZ_SDK_WIFI_TOKEN_NUM]; 
	int 		reserve[32];	
}EZ_SDK_CONFIG_WLAN;

typedef struct EZ_SDK_CONFIG_3G
{
       int    	enable;			//ʹ��3g   ģ��
	int		nettype;			//"Auto", "CDMA1x", "EVDO", "TD-SCDMA", "WCDMA", "EDGE"
	char   	apn[EZ_SDK_NAME_LENGTH];		//��������
	char   	dailnumber[EZ_SDK_NAME_LENGTH];//���ź���	
	char   	username[EZ_SDK_NAME_LENGTH];	//�û���	
	char   	password[EZ_SDK_NAME_LENGTH];	//����	
	//���ſ����������
	int 		activate;				//����	ʹ�ܱ�־
	int		timeout;				//��⵽������һ��ʱ��û��ʹ�ã��޸�Activate��־Ϊfalse���������á�
	EZ_SDK_CONFIG_WORKSHEET	schedule;	//����ʱ���
	int		enableSMSActivate;	//ʹ�ܶ��Ż���	
	int		listSMSSender[EZ_SDK_MOBILE_ACT_NUM][16];	
	int		enableDialActivate;	//ʹ�ܲ��Ż���
	int		listDialSender[EZ_SDK_MOBILE_ACT_NUM][16];
	int 		reserve[32];			
}EZ_SDK_CONFIG_3G;

typedef struct EZ_SDK_CONFIG_SMS
{
	int    	enable;			//�Ƿ�ʹ��
	char		title[EZ_SDK_TITLE_LENGTH];	//���⣬����� ��һ������
	char		receivers[EZ_SDK_MMS_RECV_NUM][16];	//��Ϣ�����ߵĵ绰����	
	char		minInterval;		//��Ϣ���͵����ʱ��������λ��

	int  		sendTimes;		//??? ��Ҫ��ÿ���ֻ����Ͷ��ٴζ���
	int 		reserve[32];			
}EZ_SDK_CONFIG_SMS;	

typedef struct EZ_SDK_CONFIG_MMS
{
	int    	enable;			//�Ƿ�ʹ��
	char		title[EZ_SDK_TITLE_LENGTH];	//���⣬����� ��һ������	
	char		receivers[EZ_SDK_MMS_RECV_NUM][16];	//��Ϣ�����ߵĵ绰����	
	char		minInterval;			//��Ϣ���͵����ʱ��������λ��
	//??? ��������ÿ��������ǲ���Ҫ��
	char 		gateWayDomain[40];	//���ص�ַ��������IP
	int  		gateWayPort;			//���ض˿�
	char 		mmscDomain[40];		// ���ŷ�������ַ��IP������
	int		mmscPort;			// ���ŷ������˿ں�
	int 		reserve[32];			
}EZ_SDK_CONFIG_MMS;	

typedef struct EZ_SDK_CONFIG_NETIP_COMMON
{
	int	httpPort;			//HTTP����˿�
	int 	sslPort;			//SSL �����˿�
	int 	maxConn;		//���������
	int 	maxBps;			//�޶�����ֵ
	int 	transPolicy;		//�������
	int	useHSDownLoad;	//�Ƿ����ø���¼�����ز���
}EZ_SDK_CONFIG_NETIP_COMMON;	

typedef struct EZ_SDK_CONFIG_NETIP_XM
{
	int	tcpPort;			//TCP ����˿�
	int	udpPort;			//UDP ����˿�
	int	keepAlive;		//Ҫ���¼�ͻ��˵ı���ʱ�䣬��λs	
	int 	reserve[32];		
}EZ_SDK_CONFIG_NETIP_XM;

typedef struct EZ_SDK_CONFIG_NETIP_DH
{
	int	port;			//����˿�,ֻ֧��TCP  Э��
	int	keepAlive;		//Ҫ���¼�ͻ��˵ı���ʱ�䣬��λs	
	int 	reserve[32];		
}EZ_SDK_CONFIG_NETIP_DH;

typedef struct EZ_SDK_CONFIG_NETIP_ONVIF
{
	int	port;			//����˿�
	int 	reserve[32];		
}EZ_SDK_CONFIG_NETIP_ONVIF;

typedef struct EZ_SDK_CONFIG_COM_ATTR
{
	int	databit;		//����λȡֵΪ,6,7,8 
	int	stopbit;		//ֹͣλ1"1", 2"2" 3:"1.5",
	int	parity;		//У��λ��0:None 1:Even 2:Odd 3:Space
	int	baudrate;	//������
}EZ_SDK_CONFIG_COM_ATTR;

typedef struct EZ_SDK_CONFIG_COM_ONE
{
	int	function;		//�μ�EZ_SDK_COM_FUNC
	EZ_SDK_CONFIG_COM_ATTR attr;
}EZ_SDK_CONFIG_COM_ONE;

typedef struct EZ_SDK_CONFIG_COM_ALL
{
	EZ_SDK_CONFIG_COM_ONE com[EZ_SDK_COM_NUM];
}EZ_SDK_CONFIG_COM_ALL;

typedef struct EZ_SDK_CONFIG_PTZ_ONE
{
	int	proto;				//�μ�EZ_SDK_PTZ_PROTO	
	int	address;				//��̨�豸��ַ��� 	
	int	numberInMatrixs;		//�ھ����е�ͳһ���	
	EZ_SDK_CONFIG_COM_ATTR attr;
}EZ_SDK_CONFIG_PTZ_ONE;

typedef struct EZ_SDK_CONFIG_PTZ_ALL
{
	EZ_SDK_CONFIG_PTZ_ONE ptz[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_PTZ_ALL;

//˵������ΪUPNP  ��Ҫӳ�䴦��http�˿�֮�⣬����Ƶ�
//����NetIp  �ķ���˿ڣ�����û�а취ֱ��ö�١�
typedef struct EZ_SDK_CONFIG_UPNP
{
	int	enable;			//ʹ�ܱ�־
	int	localPort[EZ_SDK_UPNP_PORT_NUM];		//ӳ��ǰ�Ķ˿ڣ�
	int 	reserve[32];		//	
}EZ_SDK_CONFIG_UPNP;

typedef struct EZ_SDK_CONFIG_RTSP
{
	int	enable;			//ʹ�ܱ�־
	int	port;			//����˿�,ֻ֧��TCP  Э��
	int 	reserve[32];			
}EZ_SDK_CONFIG_RTSP;

typedef struct EZ_SDK_CONFIG_FTP_SERVER
{
	int	enable;							//ʹ�ܱ�־
	EZ_SDK_REMOTE_SERVER server;		//FTP������
	char remoteDir[EZ_SDK_PATH_LENGTH];	//Զ��Ŀ¼
	int	maxFileLen;						//�ļ���󳤶�
	int 	reserve[32];			
}EZ_SDK_CONFIG_FTP_SERVER;

typedef struct EZ_SDK_CONFIG_ARSP_SERVER
{
	int	enable;						//ʹ�ܱ�־
	char	keys[EZ_SDK_NAME_LENGTH];	//��������
	EZ_SDK_REMOTE_SERVER server;	//ARSP������
	int 	interval;						//������ʱ��		
	char sURL[EZ_SDK_NAME_LENGTH];	//��������		
	int 	httpPort;						//������HTTP�˿�	
	int 	reserve[32];			
}EZ_SDK_CONFIG_ARSP_SERVER;	

typedef struct EZ_SDK_CONFIG_ARSP_SERVER_ALL
{
	EZ_SDK_CONFIG_ARSP_SERVER servers[EZ_SDK_ARSP_NUM];
}EZ_SDK_CONFIG_ARSP_SERVER_ALL;

typedef struct EZ_SDK_CONFIG_ALARMCENTER
{
	int	enable;						//ʹ�ܱ�־
	char	keys[EZ_SDK_NAME_LENGTH];	//��������Э����������
	EZ_SDK_REMOTE_SERVER server;	//�������ķ�����
	int	isAlarm;						
	int	isLog;						//�Ƿ����־
}EZ_SDK_CONFIG_ALARMCENTER;

typedef	struct EZ_SDK_CONFIG_ALARMCENTER_ALL
{
	EZ_SDK_CONFIG_ALARMCENTER servers[EZ_SDK_ALARMSERVER_NUM];
}EZ_SDK_CONFIG_ALARMCENTER_ALL;

typedef struct EZ_SDK_CONFIG_DAS
{
	int	enable;						//ʹ�ܱ�־
	EZ_SDK_REMOTE_SERVER server;	//DAS ������
	char devID[EZ_SDK_NAME_LENGTH];	//
	int 	reserve[32];		
}EZ_SDK_CONFIG_DAS;

typedef struct EZ_SDK_CONFIG_CH_MODE
{
	int	modeIndex;					//�������е�����
}EZ_SDK_CONFIG_CH_MODE;

typedef enum EZ_SDK_NETIP_TYPE
{
	XM_PROTOCAL = 0,	//����Э��
	DH_PROTOCAL,		//��Э��
	ONVIF_PROTOCAL,	//ONVIF   Э��
}EZ_SDK_NETIP_TYPE;

//����ͨ��������Դ����
typedef struct EZ_SDK_DIGITAL_SOURCE
{
	int	enable;						//ʹ�ܱ�־
	EZ_SDK_REMOTE_SERVER server;	//�豸��ַ��Ϣ
	EZ_SDK_NETIP_TYPE	protocol;		//ѡ�õ�NetIP  Э�飬��EZ_SDK_NETIP_TYPE	
	int 	channel;						//ͨ����
	int 	streamType;					//��������
	int	interval;						//��Ѳ�ļ��ʱ��(s),0:��ʾ����
	char	cfgName[EZ_SDK_NAME_LENGTH];	//����
	EZ_SDK_DEV_TYPE devType;		//�豸����
}EZ_SDK_DIGITAL_SOURCE;	

typedef enum EZ_SDK_DIGITAL_CON_TYPE
{
	EZ_SDK_CON_SINGLE = 0, 		//������Դ
	EZ_SDK_CON_MULTI = 1,			//������Դ��Ѳ
	EZ_SDK_CON_TYPE_NR,		
}EZ_SDK_DIGITAL_CON_TYPE;

typedef struct EZ_SDK_CONFIG_DIGITAL_CH
{
	int	enable;			//ʹ�ܱ�־
	EZ_SDK_DIGITAL_CON_TYPE connType;	//��������
	int 	tourInterval;		//������ʱ��Ѳ���
	int	singleConnId;	//������ʱ����������ID, ��1  ��ʼ��0  ��ʾ��Ч
	int	enCheckTime;	//������ʱ
	EZ_SDK_DIGITAL_SOURCE	inputs[EZ_SDK_DIGITAL_SOURCE_NUM];
}EZ_SDK_CONFIG_DIGITAL_CH;

typedef struct EZ_SDK_CONFIG_DIGITAL_CH_ALL
{
	EZ_SDK_CONFIG_DIGITAL_CH channel[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_DIGITAL_CH_ALL;

//===============================================
//���ܷ��������ȼ���
enum EZ_SDK_IVS_SENSITIVITY
{
	HIGH_SENSITIVITY,         	//��������
	MIDDLE_SENSITIVITY,	//��������
	LOW_SENSITIVITY		//��������
};

enum EZ_SDK_PEA_MODE
{
	TRIPWIRE = 0,		//������
	PERIMETER    		//�ܽ���
};

//�ܽ���ģʽ
typedef enum EZ_SDK_PERIMETER_MODE
{
	MODE_INTRUSION = 0,	//����
	MODE_ENTER,			//����
	MODE_EXIT				//�뿪
}EZ_SDK_PERIMETER_MODE;

//һ�����������ֻ����һ������
typedef struct EZ_SDK_PERIMETER_RULE
{
	int 	enable;						//�Ƿ�ʹ��
	int	mode;						//�ܽ���ģʽ ��EZ_SDK_PERIMETER_MODE
	int	isTypeLimit;					//�Ƿ���Ŀ���������� 
	int	typeHuman;					//Ŀ�������(�޶�����ʱʹ��) 
	int	typeVehicle;					//Ŀ����𣺳� 
	int 	minDist;						//��С���ؾ��� 
	int 	minTime;						//���ʱ�� 
	int	isDirectionLimit;				//�Ƿ����������� 
	int 	forbiddenDirection;			//��ֹ����Ƕ�(��λ: �Ƕ�) 
	_Polygon 	boundary;				//�ܽ�������Ϣ
}EZ_SDK_PERIMETER_RULE;

//һ�����߹����ڿ������ö�����
typedef struct EZ_SDK_ONE_TRIPWIRE
{
	int	isDoubleDirection;				//��ʾ�ð����Ƿ�Ϊ˫�����(0: ��, 1: ��) 
	int 	forbiddenDirection;			//��ֹ����Ƕ�(��λ: �Ƕ�) 	
	Line 	line;							//
}EZ_SDK_ONE_TRIPWIRE;

//һ�����߹����ڿ������ö�����
typedef struct EZ_SDK_TRIPWIRE_RULE
{
	int 	enable;						//�Ƿ�ʹ��
	int	isTypeLimit;					//�Ƿ���Ŀ���������� 
	int	typeHuman;					//Ŀ�������(�޶�����ʱʹ��) 
	int	typeVehicle;					//Ŀ����𣺳� 
	int 	minDist;						//��С���ؾ��� 
	int 	minTime;						//���ʱ�� 
	EZ_SDK_ONE_TRIPWIRE	tripwire[EZ_SDK_TRIPWIRE_IN_RULE];//
}EZ_SDK_TRIPWIRE_RULE;

typedef struct EZ_SDK_CONFIG_PEA_RULES
{
	int	showObj;					//�Ƿ���ʾʶ�����������
	int	showTrack;					//�Ƿ���ʾ�켣
	int	showRule;					//�Ƿ���ʾ����
	int 	level;						//������
	EZ_SDK_PERIMETER_RULE	perimeterRules[EZ_SDK_PEA_PERIMETER_NUM];	//
	EZ_SDK_TRIPWIRE_RULE	tripwireRules[EZ_SDK_PEA_TRIPWIRE_NUM];	//
}EZ_SDK_CONFIG_PEA_RULES;

typedef struct  EZ_SDK_CONFIG_IVS_DETECT
{
	int 	enable;						//ʹ��ivs
	EVENT_HANDLER eventHandler;		//
}EZ_SDK_CONFIG_IVS_DETECT;	

// ����ˮӡ����
typedef struct EZ_SDK_CONFIG_WATERMARK
{
	int	enable;		//����ˮӡ
	char	key[8];
	char	userData[16];
}EZ_SDK_CONFIG_WATERMARK;

typedef struct EZ_SDK_CONFIG_WATERMARK_ALL
{
	EZ_SDK_CONFIG_WATERMARK marks[EZ_SDK_CHANNEL_NUM];
}EZ_SDK_CONFIG_WATERMARK_ALL;

//��������̬����
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


//�ص�����ԭ��
//�豸�Ͽ����ӵĻص�
typedef int (CALL_METHOD *EZ_SDK_DisconnectCB)(int loginID,char *devIP,int devPort,int userData);
	
//�豸�����ϴ��Ļص�
typedef int (CALL_METHOD *EZ_SDK_AlarmCB)(int loginID, EZ_SDK_ALARM_INFO *alarmInfo,int userData);

//ʵʱ�������ݻص�
typedef int (CALL_METHOD *EZ_SDK_RealDataCB)(int playHandle,EZ_SDK_PACKET_INFO *info,char *buffer,int size,int userData);

//�ط����ؽ��Ȼص�
typedef int (CALL_METHOD *EZ_SDK_ProgressCB)(int playHandle,int totalSize,int downloadSize,int userData);

#endif	//__EZ_SDK_DEF_H__