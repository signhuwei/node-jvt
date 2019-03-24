//
//  "$Id: ManagerExchange.h 18544 2015-12-01 12:03:11Z chenbo $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:			2008-12-03 liwj create the file
//  
//

#ifndef __EXCHANGEAL_MANAGER_EXCHANGE_H__
#define __EXCHANGEAL_MANAGER_EXCHANGE_H__

#include <vector>
#include <string>
#include "Types/Types.h"
#include "Types/Defs.h"
#include "Infra/Time.h"


enum AccountErrorNo
{
	ACCOUNT_OK = 100,
	ACCOUNT_NOT_LOGIN = ERROR_BEGIN_ACCOUNT + 1,
	ACCOUNT_PASSWORD_NOT_VALID = ERROR_BEGIN_ACCOUNT + 2,
	ACCOUNT_USER_NOT_VALID = ERROR_BEGIN_ACCOUNT + 4,
	ACCOUNT_USER_LOCKED = ERROR_BEGIN_ACCOUNT + 5,
	ACCOUNT_USER_IN_BLACKLIST = ERROR_BEGIN_ACCOUNT + 6,
	ACCOUNT_USER_HAS_USED = ERROR_BEGIN_ACCOUNT + 7,
	ACCOUNT_INPUT_NOT_VALID,	 /// ���벻�Ϸ�
	ACCOUNT_OVERLAP,			/// �����ظ���Ҫ���ӵ��û��Ѿ����ڵ�
	ACCOUNT_OBJECT_NONE,		/// �����ڶ���, ���ڲ�ѯʱ
	ACCOUNT_OBJECT_NOT_VALID,	/// ���󲻴���
	ACCOUNT_OBJECT_IN_USE,		/// Ŀ������ʹ����,���鱻�ã�����ɾ��
	ACCOUNT_SUBSET_OVERLAP,		/// �Ӽ�����Χ (�����Ȩ�޳���Ȩ�ޱ��û�Ȩ�޳������Ȩ�޷�Χ�ȵ�)
	ACCOUNT_PWD_NOT_VALID,		/// ���벻��ȷ
	ACCOUNT_PWD_NOT_MATCH,		/// ���벻ƥ��
	ACCOUNT_RESERVED,			/// �����ʺ�
};

/// ���뱣�淽ʽ�����ܻ��߲�����
enum PasswordEncrypt
{
	PASSWORD_FLAG_PLAIN,	///< ���벻���ܷ�ʽ
	PASSWORD_FLAG_MD5,		///< MD5������ܷ�ʽ
	PASSWORD_FLAG_3DES,		///< 3DES���ܷ�ʽ
	PASSWORD_FLAG_HSQD,		///<�ͻ���ɽ���������ܷ�ʽ(ֻ�жϣ���У��)
	PASSWORD_FLAG_GIGA,		///<�ͻ�GIGA������ܷ�ʽ(ֻ�жϣ���У��)
	PASSWORD_FLAG_NR,		///< ��������
};

/// �û���½��ʽ
enum LoginType
{
	LOGIN_TYPE_GUI,			///< ����GUI��½
	LOGIN_TYPE_CONSOLE,		///< ����̨��½
	LOGIN_TYPE_WEB,			///< WEB��½
	LOGIN_TYPE_SNS,			///< SNS��½
	LOGIN_TYPE_MOBIL,		///< �ƶ��ն˵�½
	LOGIN_TYPE_NETKEYBOARD,	///< ������̵�½
	LOGIN_TYPE_SERVER,		///< ���ķ�������½
	LOGIN_TYPE_AUTOSEARCH,	///< IP�Զ��������ߵ�½
	LOGIN_TYPE_UPGRADE,		///< �������ߵ�½
	LOGIN_TYPE_MEGAEYE,		///< ȫ���۵�½
	LOGIN_TYPE_FUTRUE_HOME,	///< δ����ͥ
	LOGIN_TYPE_XMEYE,		///< xmeye
	LOGIN_TYPE_XM030,		///< xm030�ֻ��ͻ���
	LOGIN_TYPE_NR,			///< ��½����
};

///< �û���½������Ϣ
struct LoginRequest
{
	std::string sUserName;		///< ��½����
	std::string sPassword;		///< ��½����
	int iEncryptType;			///< ������ܷ�ʽ�����ܻ��߲�����
	int iLoginType;				///< ��½��ʽ
};
struct AutoLogin
{
	int iEnable; 				///<�Զ���¼�Ƿ�����1������0�ر�
	LoginRequest LoginInfo;
};
/// �豸����
enum DeviceType
{
	DEVICE_TYPE_DVR,	///< ��ͨDVR�豸
	DEVICE_TYPE_NVS,	///< NVS�豸
	DEVICE_TYPE_IPC,	///< IPC�豸
	DEVICE_TYPE_HVR,	///<���dvr
	DEVICE_TYPE_IVR,	///<����dvr
	DEVICE_TYPE_MVR,	///<����dvr
	DEVICE_TYPE_NR
};

/// ��½������Ӧ
struct LoginResponse
{
	int iChannelNum;		///< ����·��
	int iAliveInterval;		///< ��������(s)
	int iRet;				///< ����ֵ
	int iDeviceType;		///< �豸����
	uint uiSessionId;		///< �ỰID
	int iExtraChannel;		///< ��չͨ����
};

/// �޸��û���������
struct ModifyPasswordRequest
{
	uint uiSessionId;
	int iEncryptType;
	std::string sUserName;
	std::string sPassword;
	std::string sNewPassword;
};

/// �û�������Ϣ
struct UserConfig
{
	UserConfig &operator=(const UserConfig &user);
	std::vector<std::string> authorityList;		// �û�Ȩ���б�
	std::string	group;		// ����
	std::string memo;		// ��ʾ��Ϣ
	std::string userName;	// �û���
	std::string password;	// ����
	bool		reserved;	// �Ƿ��Ǳ����û�
	bool		shareable;	// ���û��Ƿ�ɸ���
};

struct ModifyUserConfig
{
	std::string sUserName;
	UserConfig User;
};

/// ������Ȩ��
struct GroupConfig
{
	GroupConfig &operator=(const GroupConfig &group);
	std::vector<std::string> authorityList;		// �û�Ȩ���б�
	std::string memo;		// ��ʾ��Ϣ
	std::string name;		// ����
};

struct ModifyGroupConfig
{
	std::string sGroupName;
	GroupConfig Group;
};

// ɾ���˺�, ����ɾ���û�������
struct DeleteAccountRequest
{
	uint uiSessionID;
	std::string sName;	
};

const char *getUserLoginType(int iLoginType);
const char *getUserEncType(int iEncType);


/// Ӳ�����������
enum DiskFullPolicy
{	
	DISK_FULL_POLICY_STOP_RECORD,	///< ֹͣ¼��
	DISK_FULL_POLICY_OVERWRITE,		///< ����
	DISK_FULL_POLICY_NR
};

/// ��Ƶ�������������
enum VideoOutputTypes
{
	VIDEOOUT_AUTO = 0,	///< �Զ�����豸��
	VIDEOOUT_VGA,		///< �л���VGA�����
	VIDEOOUT_TV,		///< �л���TV�����
	VIDEOOUT_VGA_LCD,	///< �л���LCD VGA�����
	VIDEOOUT_NR,
};

/// ��Ƶ��ʽ����
enum VideoStandardTypes
{
	VIDEO_STD_PAL = 0,	///< PAL��ʽ��
	VIDEO_STD_NTSC,		///< NTSC��ʽ��
	VIDEO_STD_SECAM		///< SECAM��ʽ��
};

///< ��ͨ����
struct GeneralConfig
{	
	int iLocalNo;				///< �������:[0, 998] 	
	int iOverWrite;				///< Ӳ����ʱ�Ĵ������DiskFullPolicy
	char cIranCalendarEnable;	///< ��������
	char cFontSize;				///< ʸ�������С
	char reserved[2];
	std::string sMachineName;	///< ������
	int iVideoStartOutPut;		///< ���ģʽ 
	int iAutoLogout;			///< ���ز˵��Զ�ע��(����)	[0, 120]
};

/// ����ʱ����
enum DST_RULE_TYPES
{
	DST_RULE_OFF = 0,	///< �ر�����ʱ����
	DST_RULE_ON,		///< ��������ʱ����
	DST_RULE_NR
};

///< ����ʱ�ṹ
struct GeneralDSTPoint
{
	int	iYear;
	int	iMonth;
	int	iWeek;		///<��1:first  to2 3 4 -1:last one   0:��ʾʹ�ð��ռ���ķ���[-1,4]
	int	iWeekDay;	///<weekday from sunday=0	[0, 6]
	int Hour;
	int Minute;
};

///<��������
struct LocationConfig
{
	int iVideoFormat;		///< ��Ƶ��ʽ
	int iLanguage;			///< ����ѡ��
	int iDateFormat;		///< ���ڸ�ʽ
	int iDateSeparator;		///< ���ڷָ��:��.��, ��-��, ��/�� 
	int iTimeFormat;		///< ʱ���ʽ:��12��, ��24�� 
	int iDSTRule;			///< ����ʱ���� 
	int iWorkDay;			///< ������
	GeneralDSTPoint dDSTStart;
	GeneralDSTPoint dDSTEnd;
};

///< �Զ�ά������
struct AutoMaintainConfig
{
	int iAutoRebootDay;				///< �Զ�������������
	int iAutoRebootHour;			///< ��������ʱ��	[0, 23]	
	int iAutoDeleteFilesDays;		///< �Զ�ɾ���ļ�ʱ��[0, 30]
};

//////////////////////////////////////////////////////////////////////////
/// �������������
struct CarPlates
{
	std::string sPlateName;
};

//////////////////////////////////////////////////////////////////////////
/// ϵͳ�����������
struct DeviceDesc
{
	int nAudioIn;			///< ��Ƶ����·��
	int nAlarmIn;			///< ��������·��
	int nAlarmOut;			///< �������·��
	int nTrailDay;			///< ʹ��ʱ��
	std::string sGUITheme;	///< GUI����
	int nRemoteType;        //ң��������(������)
	int nPenaltyDay;       ///< �ͷ�����
	int nlocalPalyMax;	//���ػط����·��
	int nlocalPalyDefault;  //���ػط�Ĭ��·��
	int nCapture;           //����ͨ����
	int nPadType;           //ǰ�������(������)
	bool bEablePlayDefault; //�Ƿ����ûط�Ĭ��·��
	bool bEnableComm;       //����232�����Ƿ�����
	bool bEnablePtz;        //��̨�����Ƿ�����
	char sRemoteName[32];        //ң��������
	char sPadName[32];           //ǰ�������
	bool bEnableNetCommon;        //ͨ����������ҳ��
};

/// ��¼ϵͳ�ϴ�����״̬
struct SystemLastState
{
	int nLastSpt;   ///< ��¼�ϴ��ֶ��л��ָ�ģʽ,�豸����ʱ�л������һ�ηָ�״̬
	int nLastSubSpt;	///< ��¼�ϴ��ֶ��л��ָ�ģʽ,�豸����ʱ�л������һ�ηָ�״̬
};

//�豸�Զ����ػ�����
struct SystemTimingWork
{
	bool	    bAutoBoot;		    ///< �Ƿ������Զ����ػ�����
	TimeSection tsWorkHour;			///< DVR����ʱ���(24Сʱ�ƣ����Ҫ��ʾ���ϵ��ڶ����賿��[20, 8])
};


//����Ӧ�ý������λ��ʾ�������õĹ۲������ã����õ��ύ�߼��
enum CONFIG_APPLY_RET
{
	CONFIG_APPLY_OK = 0,						/// �ɹ�
	CONFIG_APPLY_REBOOT = 0x00000002,			/// ��Ҫ����ϵͳ
	CONFIG_APPLY_FILE_ERROR = 0x00000004,		/// д�ļ�����
	CONFIG_APPLY_CAPS_ERROR = 0x00000008,		/// ���Բ�֧��
	CONFIG_APPLY_GATEWAY_ERROR = 0x00000010,	///��������ʧ��,��Ȼ����Ϊ�ɹ�
	CONFIG_APPLY_VALIT_ERROR = 0x00000020,		/// ��֤ʧ�� 
	CONFIG_APPLY_NOT_EXSIST = 0x00000040,		/// ���ò����� 
	CONFIG_APPLY_NOT_SAVE = 0x00000080,			/// ��Ҫ���浽�ļ�
	CONFIG_APPLY_DELAY_SAVE = 0x00000100,		///��ʱ����..��λռ��ȡֵΪ0x180��ԭ���������ñ����ʱ����Ҫ����
};

struct AbilitySerialNo
{
	std::string serialNo;
	std::string productType;
};

struct ProduceTest
{
	bool TestEnable; //��������ģʽ
};

struct DASLoginInfo
{
	std::string userName;		///< ��½����
	std::string password;		///< ��½����
	int encryptType;			///< ������ܷ�ʽ,PasswordEncrypt
	std::string deviceID;		///<�豸ID
	int devicType;				///<DeviceType
	uint channelNums;			///<�豸ͨ����
};

struct TimeZone
{
	int minuteswest; 	//��UTCʱ��Ĳ�ֵ����λ���ӣ�����Ϊ��
	Bool FistFlag;		//���ڱ�֤��һ��ʹ�õ�ʱ��ʱ�䲻��
};

//¼��ʹ�ܣ�����ֻ���ձ��ͻ�ʹ��
struct RecordEnableConfig
{
	Bool isRecordEnable;  //�Ƿ���Կ���¼��
};

//�û���Ϣ���������û�����һ�£�ֻ����������Base64�����������޸ģ����Է��������
//onvif��½ʱʹ��
struct UserMap
{
	int size;
	UserConfig UserCfg[64];
};

struct AlarmGUIShow
{
	int showDelay;  //�����������ڱ���������Ȼ��ʾ����״̬�ĳ���ʱ��
	int resv[7];
};

//�������������ָ���ʱ�䣬�����ϴ�����ڼ��ͼƬ��FTP
struct NetConDisconTime
{
	SystemTime disconTime;//������ʼʱ��
	SystemTime conTime;   //����ָ�ʱ��
};
//����Ͽ�������ʱ����Ϣ
struct NetConDisconTimeAll
{
	std::vector<NetConDisconTime> timeInfo;		// ����Ͽ�������ʱ���
};

//��չ���豸��ID
struct ExtSubDevID
{
	char primerInter[2];	//�������ܷ�����1���ֽ�
	char AdvInter[2];		//�߼����ܷ�����1���ֽ�
	char wifiType[3];		//wifi���ͣ�2���ֽ�
	char subDevID[2];		//�豸С�ͺ�id,1���ֽ�
	char extProtocol[3];	//��չЭ�� id��2���ֽ�
	char oemSelfDef[3];		//oem�Զ���id��2���ֽ�
	char resv[49];			//����
};

#endif

