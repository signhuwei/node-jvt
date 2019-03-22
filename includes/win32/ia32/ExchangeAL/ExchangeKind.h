//
//  "$Id: ExchangeKind.h 18675 2015-12-15 11:21:51Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  Modifiy:		2008-12-05 liwj create the file
//					����ҵ��㣬�������ҵ����ع���
//

#ifndef __EXCHANGE_AL_EXCHANAGE_KIND_H__
#define __EXCHANGE_AL_EXCHANAGE_KIND_H__

#include "Types/Defs.h"
#include <vector>
#include <string>

/// ���ò�����ش����
enum ConfigErrorNo
{
	CONFIG_OPT_RESTART = ERROR_BEGIN_CONFIG + 1,		///< ��Ҫ����Ӧ�ó���
	CONFIG_OPT_REBOOT = ERROR_BEGIN_CONFIG + 2,			///< ��Ҫ����ϵͳ
	CONFIG_OPT_FILE_ERROR = ERROR_BEGIN_CONFIG + 3,		///< д�ļ�����
	CONFIG_OPT_CAPS_ERROR = ERROR_BEGIN_CONFIG + 4,		///< ���Բ�֧��
	CONFIG_OPT_VALIT_ERROR = ERROR_BEGIN_CONFIG + 5,	///< ��֤ʧ�� 
	CONFIG_OPT_NOT_EXSIST = ERROR_BEGIN_CONFIG + 8,		///< ���ò�����
	CONFIG_OPT_PARSE_FAILED = ERROR_BEGIN_CONFIG + 6,	///< ���ý�������
};

/// Ĭ����������
enum DefaultConfigKinds
{
	DEFAULT_CFG_GENERAL,			// ��ͨ����
	DEFAULT_CFG_ENCODE,				// ��������
	DEFAULT_CFG_RECORD,				// ¼������
	DEFAULT_CFG_NET_SERVICE,		// �������
	DEFAULT_CFG_NET_COMMON,			// ͨ������
	DEFAULT_CFG_ALARM,				// ����
	DEFAULT_CFG_PTZCOMM,			// ��̨������
	DEFAULT_CFG_USERMANAGER,		// �û�����
	DEFAULT_CFG_PREVIEW,			// Ԥ������
	DEFAULT_CFG_CAMERA_PARAM,		// ��������ͷ����
	DEFAULT_CFG_END
};

/// ����Ĭ����������DefaultConfigKindsȡ����Ӧ������
const char *getDefaultKindName(int iDefaultKind);

/// �����������õ�ö�ٳ���
int getDefaultKindIndex(const char *iDefaultName);

/// ��������
enum ConfigKinds
{
	CFG_ENCODE,			///< ��������
	CFG_WIDEOWIDGET,	///< ��Ƶ���
	CFG_VIDEOCOLOR,		///< ��Ƶ��ɫ
	CFG_RECORD,			///< ¼������
	CFG_MOTIONDETECT,	///< ��������
	CFG_BLINDDETECT,	///< �ڵ����
	CFG_LOSSDETECT,		///< ��Ƶ��ʧ
	CFG_LOCALALAEM,		///< ���ر���
	CFG_NETALAEM,		///< ���籨��
	CFG_NETIPCONFLICT,	///< IP��ַ��ͻ
	CFG_NETABORT,		///< �����쳣
	CFG_STORAGENOTEXIST,	///< �洢�豸������
	CFG_STORAGELOWSPACE,	///< �洢�豸��������
	CFG_STORAGEFAILURE,		///< �洢�豸����ʧ��
	CFG_PTZALARM,			///< ��̨����
	CFG_NETCOMMON,			///< ͨ����������
	CFG_NETIPFILTER,		///< �׺�����
	CFG_NETDHCP,		///< DHCP
	CFG_NETDDNS,		///< DDNS
	CFG_NETEMAIL,		///< EMail
	CFG_NETMULTICAST,	///< �ಥ
	CFG_NETNTP,			///< ʱ��ͬ������
	CFG_NETPPPOE,		///< PPPOE
	CFG_NETDNS,			///< DNS
	CFG_COMM,			///< ��������
	CFG_PTZ,			///< ��̨����
	CFG_PTZPRESET,		///< ��̨Ԥ�õ�����
	CFG_PTZTOUR,		///< 
	CFG_TOUR,			///< ��Ѳ����
	CFG_GUISET,			///< GUISet����
	CFG_TVADJUST,		///< TV����
	CFG_AUDIOINFORMAT,	///< �Խ�����
	CFG_PLAY,			///< �ط�
	CFG_GENERAL,		///< ��ͨ����
	CFG_LOCATION,		///< ���ػ�����
	CFG_AUTOMAINTAIN,	///< �Զ�ά������
	CFG_CHANNELTITLE,	///< !! ͨ���������ã�����
	CFG_SNAPSHOT,		///< ͼƬ�洢����
	CFG_COMBINEENCODE,  ///< ��ϱ���
	CFG_COMBINEENCODEMODE,  ///< ��ϱ���ģʽ
	CFG_NETFTP,			///< FTP����
	CFG_NETARSP,		///< ARSP����
	CFG_NETPLAT_MEGANET, ///< HXHTƽ̨����
	CFG_NETPLAT_MEGAMOTION, ///< HXHTƽ̨����Ķ������
	CFG_ABILITY_SUPPORTLANGUAGE,	///< ֧�ֵ�����
	CFG_NETDECORDER,	///< �������������
	CFG_3GNET,			///< 3G��������
	CFG_MOBILE,         ///< �ֻ��������
	CFG_ABILITY_SUPPORTVSTD,	///< ֧�ֵ���Ƶ��ʽ
	CFG_VIDEOCHANNEL,	///< ֧�ֵ���Ƶͨ������
	CFG_CARPLATE,		///< ���ƺ�����
	CFG_NETUPNP,           ///< UPNP����
	CFG_ABILITY_DEVDESC,	///< �豸��������
	CFG_STORAGE_POSITION,
	CFG_WIFI,          ///< WIFI
	CFG_SYSTEM_STATE,      ///< ��ֵ�����������Ѿ�ת��CFG_LAST_SPLIT_STATE��CFG_SYSTEM_TIMING_WORK������Ϊ����Ҳ������Щö�٣�Ϊ������������±��룬�ȱ�����
	CFG_VIDEOOUT,
	CFG_ABILITY_VGARESOLUTION,	///< ֧�ֵ�VGA�ֱ����б�
	CFG_ABILITY_THEMELIST,		///< ֧�ֵ�GUI�����б�
	CFG_ENCODE_SIMPLIFY,		///< ���¼򻯰汾��������
	CFG_RS485,                  ///< 485�豸����
	CFG_NETALARMSERVER,         ///< ��������
	CFG_ALARMOUT,               ///< �������
	CFG_NETPLAT_XINWANG,        ///< ����ƽ̨
	CFG_NETPLAT_SHISOU,        ///< ����ƽ̨
	CFG_NETPLAT_VVEYE,        ///< VVEYEƽ̨
	CFG_MEDIA_WATERMARK,	///< ����ˮӡ����
	CFG_NETDECORDER_V2,		///< �������������V2�汾
	CFG_NETPLAT_WELLSUN,    ///< �ݶ�ɭƽ̨
	CFG_ABILITY_ENOCDE,		///< ����������
	CFG_NET_RTSP,		    ///< RTSP����
	CFG_ABILITY_SERIALNO,		///< �������к�
	CFG_NETDECORDER_V3,		//����ͨ������
	CFG_NETDECORDER_CHNMODE,  //ͨ��ģʽ����
	CFG_NETDECORDER_CHNSTATUS,  //ͨ��״̬
	CFG_PRODUCE_TEST,		///<������������
	CFG_NET_POS,		//POS������
	CFG_CAMERA_PARAM,         //��������ͷ��������
	CFG_OSD_WIDGET,           //OSD��Ϣλ����״̬����
	CFG_NET_DAS,
	CFG_NETPLAT_NANRUI,       //���ƽ̨����
	CFG_VOLUME, //��������
	CFG_SPOT,                 //SPOT���
	CFG_PHONE_SHORT_MSG,      //�ֻ�����
	CFG_PHONE_MULTIMEDIA_MSG, //�ֻ�����
	CFG_CAR_INPUT_EXCHANGE,   //�ⲿ��Ϣ�����복��״̬�Ķ�Ӧ��ϵ
	CFG_CAR_DELAY_TIME,       //����ϵͳ��ʱ����
	CFG_NET_ORDER,            //�������ȼ�
	CFG_LOCALSDK_NET_PLATFORM, //����ƽ̨��Ϣ����
	CFG_GPS_TIMING,           //GPSУʱ�������
	CFG_CAR_DISPLAY,          //������ʾ����
	CFG_VIDEO_ANALYZE,        //��Ƶ����(����DVR)
	CFG_GODEYE_ALARM,		//���۽Ӿ�����ϵͳ
	CFG_NAT_STATUS_INFO,	//NAT״̬��Ϣ
	CFG_ENCODE_STATICPARAM,	//��������̬����
	CFG_LOSS_SHOW_STR,		//��Ƶ��ʧ��ʾ�ַ���
	CFG_DIGMANAGER_SHOW,	//ͨ��������ʾ����
	CFG_VIDEOOUT_PRIORITY,   //��ʾHDMI VGA���ȼ�������
	CFG_NAT,					//NAT����ʹ����MTUֵ����
	CFG_ANALYZE_LINK,			//���ܷ�����������
	CFG_GUIDE,					//������
	CFG_VIDEOSEQUE,		//CMS���Ԥ����������
	CFG_AUTOLOGIN,				//�Զ���¼����
	CFG_VPN,
	CFG_RESUME_PTZ_STATE,    //�ָ���̨״̬�������
	CFG_NET_LOCALSEARCH,    //Զ������
	CFG_VOCOLORADJUST, 	///<VO��ʾ����
	CFG_NETPLAT_KAINENG, //����ƽ̨
	CFG_PREHVRCAP,	//�ϴ��˳�ϵͳģʽ
	CFG_ENCODE_STATICPARAM_V2,	//DVR��������̬����
	CFG_C7_PLATFORM,            //���մ�����˾��C7ƽ̨���ò���
	CFG_NET_KEYBOARD,	//�������
	CFG_SPVMN_PLATFORM,     //28181Э������
	CFG_PROFESSION_NVR_MODE, //רҵNVR����ͨ��ģʽ����
	CFG_PMS,				//�ֻ�����
	CFG_PHONEASIDLIST,		//�ֻ�id��Ϣ
	CFG_OSD_INFO,           //��Ļ��ʾ��Ϣ
	CFG_KAICONG,		//����
	CFG_DIGITAL_HIDE,		//ͨ��ģʽ���� //��������Ѿ�ȥ����
	CFG_DIGITAL_REAL,		//����֧�ֵ�ͨ��ģʽ
	CFG_DECODE_PARAM,     //���������ʱ
	CFG_XMHEARTBEAT,		//������������
	CFG_MONITOR_PLATFORM,	//����������ƽ̨
	CFG_OSD_LOGO,           //����������Сlogo������
	CFG_PARAM_EX,	//����ͷ��չ����
	CFG_NETPLAT_ANJU_P2P,	//����P2P
	CFG_CORRESPONDENT_INFO,//�û��Զ�������
	CFG_RECORD_STATE,		//¼��״̬
	CFG_VIDEOCOLOR_CUSTOM,//�����Ӷ���
	CFG_DIGITCHN_STATE,		//����ͨ������״̬
	CFG_TITLENAME_INFO,		//ͨ������
	CFG_CAR_BOOT_TYPE,		//���ؿ��ػ�ģʽ
	CFG_SPE_CH_SQE,			//�ͻ����Ƶ�������Ѳ˳��
	CFG_IPC_ALARM,			//IPC���籨��
	CFG_NETPLAT_TUTK_IOTC,	//TUTK IOTCƽ̨����
	CFG_BAIDU_CLOUD,		//baidu��
	CFG_PMS_MSGNUM,			//�ֻ�������
	CFG_AUDIO_OPENED_CH,	//Ĭ�Ͽ����ڼ�·��Ƶ������
	CFG_APP_DOWN_LINK,		//�����û�������������
	CFG_AUTO_CONNECT,	//�Զ���������
	CFG_MOBILE_WATCH,	//�й������ֻ�����ƽ̨����
	CFG_BROWSER_LANGUAGE,   //ʹ�������ʱʹ�õ����ԣ����ò����浽�ļ���
	CFG_TIME_ZONE,		//ʱ������
	CFG_NETBJLTHY,	//�������ڷ�������������
	CFG_DIG_TIME_SYN,		//����ͨ��ʱ��ͬ������
	CFG_RECORD_ENABLE,       //�Ƿ�׼���ÿ�ʼ¼���ץͼ�����������ձ��ͻ�ͨ�����ڿ��ƿ����͹ر�¼����
	CFG_NKB_DEVICE_LIST,	//��������豸����
	CFG_EXT_RECORD,			///< ��������¼��¼������
	CFG_CUSTOMIZE_OEMINFO,		//����OEM�ͻ��汾��Ϣ
	CFG_DIGITAL_ENCODE, //����ͨ��������������
	CFG_DIGITAL_ABILITY,
	CFG_ENCODECH_DISPLAY,//IE�˱���������ʾ��ǰ��ͨ����
	CFG_LAST_SPLIT_STATE,   //���һ�εĻ���ָ�ģʽ������������ָ�֮ǰ�ķָ�ģʽ
	CFG_SYSTEM_TIMING_WORK, //�豸��ʱ���ػ�ʱ�����á��������Զ�ά��ҳ���Ҫ�ó��������½���ܿ�������
	CFG_GBEYESENV,			///�����������ƽ̨����
	CFG_PARKING_PORT,		//����ϵͳ�˿ں�����
	CFG_SPEEDALARM,			//�ٶȱ���
	CFG_TEST_DEV_SET,//��װ  ����   ��Ϣ�� ������  �������豸
	CFG_TEST_DEV_CHECK,//��װ����   У����Ϣ ����������У���豸
	CFG_TRANS_COMM_DATA, //�������������ϴ���UDP��TCP������������TCP����������֧��˫��ͨ��
	CFG_EX_USER_MAP,	//���ڱ�����������
	CFG_DATALINK,	//datalink�ͻ�����������е�ִ�г���ʹ������
	CFG_GSENSORALARM,		//GSENSOR����
	CFG_WIFI_MODE,			//Wifiģʽ���ã������г���¼���л�APģʽ
	CFG_PTZPATTERN,			//Ѳ������
	CFG_USER_PROGRAM,		//�û�С���������������
	CFG_FTP_AUTO_UPLOAD,	//�Զ��ϴ���Ƶ��FTP�������������
	CFG_SNAP_AUTOUPLOAD,	//���ƽ̨�Զ�ץͼ�ϴ�����
	CFG_SNAP_ALARMUPLOAD,	//���ƽ̨����ץͼ�ϴ�����
	CFG_ALARM_DURATION,		//����״̬����ʱ������
	CFG_NETPLAT_BJHONGTAIHENG,  ///< ������̩��ƽ̨
	CFG_CLOUD_STORAGE,		//�ƴ洢�������
	CFG_IDLE_PTZ_STATE,		//��̨���ж����������
	CFG_TX_DEV_INFO,		//��Ѷƽ̨ע�����豸��Ϣ
	CFG_CAMERA_CLEAR_FOG,	//ȥ��������	
	CFG_CAMERA_MOTOR_CONTROL, //������������
	CFG_ENCODE_ADD_BEEP,		//���ñ������ÿ��30��beep��	
	CFG_FISH_EYE_PARAM,		//���۹��ܲ�������
	CFG_NETPLAT_SPVMN_NAS,	//���ճ���ͻ���nas����������
	CFG_SPARSH_HEARTBEAT,	//Sparsh�ͻ���������������
	CFG_LOGIN_FAILED,		//��¼ʧ��ʱ�����ʼ���ʹ�ýṹ��:�����¼��ṹ
	CFG_NET_CON_DISCON_TIME,//����������Ͽ�ʱ�����ã����ڿͻ����ƵĽ������ڼ��ͼƬ�ϴ�FTP
	CFG_ADDED_ALARM_DEV,	//�������Ʒ�Ѿ���ӵĴ������������Ŵš��̸к�ң������
	CFG_CONSUMER_COMM_DEV_CFG,	//�������Ʒ����豸��������
	CFG_IPV6_ADDRESS,		//ipv6
	CFG_SERIALPORT_ALARM,	// ���ڱ�������	
	CFG_ONLINE_UPGRADE,		// ���������������
	CFG_VIDEO_ANALYZE_PUB,	//���ܷ���ʹ�����㷨��������(��ʱ���ã���������)
	CFG_VIDEO_ANALYZE_PEA,	//���ܷ���PEA�㷨����(��ʱ���ã���������)
	CFG_VIDEO_ANALYZE_OSC,	//���ܷ���OSC�㷨����	(��ʱ���ã���������)
	CFG_VIDEO_ANALYZE_AVD,	//���ܷ���AVD�㷨����	(��ʱ���ã���������)
	CFG_VIDEO_ANALYZE_CPC,	//���ܷ���CPC�㷨����(��ʱ���ã���������)
	CFG_EXT_SUB_DEV_ID, 	//��չ���豸��ID
	
	CFG_SMARTDETECTION_CODEC,			//���ܱ���		by ctf 20170911
	CFG_SMARTDETECTION_DETECT,			//���ܼ��		by ctf 20170911
	CFG_SMARTDETECTION_CONTROL,			//���ܿ���		by ctf 20170911
	CFG_SMARTDETECTION_LUMINANCE,		//�������		by ctf 20170908
	CFG_SMARTDETECTION_MOVE,			//�ƶ����		by ctf 20170908
	CFG_SMARTDETECTION_OCCLUSION,		//�ڵ����		by ctf 20170908
	CFG_SMARTDETECTION_CROSSLINE,		//���⾯����	by ctf 20170908
	CFG_SMARTDETECTION_CROSSAREA,		//��������		by ctf 20170908
	CFG_SMARTDETECTION_COLOR,			//��ɫ			by ctf 20170908
	CFG_SMARTDETECTION_SOUND,			//����			by ctf 20170908
	CFG_SMARTDETECTION_LOSEOBJ,			//��ƷԤ��		by ctf 20170908

	CFG_CALIBRATION_GET_CAMERA_PARAMETER,		//��ȡ������Ƿ��Ѿ��궨		by ctf 20180122
	CFG_CALIBRATION_SET_SUBCAMERA_CONNECTINFO,	//���ôӻ���¼��Ϣ				by ctf 20180122
	CFG_CALIBRATION_SET_POINTS,					//���ñ궨����(����ɾ��3D)		by ctf 20180122
	CFG_CALIBRATION_ACTION,						//���ñ궨����ʼ����ɣ�		by ctf 20180122  Action
	CFG_CALIBRATION_MODE,						//�궨ģʽ						by ctf 20180122
	CFG_CALIBRATION_ZOOMTIMES,					//�䱶ϵ��						by ctf 20180122
	
	CFG_CALIBRATION_PTZINFO,					//��ȡPTZ����					by ctf 20180210
	CFG_CALIBRATION_SETINFO_YW,					//����							by ctf 20180416
	CFG_CALIBRATION_RESULT_YW,					//���	 Result					by ctf 20180416
	CFG_CALIBRATION_PANOTYPE,
	CFG_CALIBRATION_ENCRYPT,					//ȫͼ���ܴ�
	CFG_CALIBRATION_NAMING,						//������
	CFG_CALIBRATION_NAMING_GET,						//������

	CFG_FACECOMPARE_RESULT_ALARM,				//�����ȶԽ������				by ctf 20180206
	CFG_FACEWB_RESULT_RES,						//�����ڰ����������Ӧ			by ctf 20180206

	CFG_FACEWB_COMMON_PARAMETER,				//��������				
	CFG_FACEWB_AREADETECTION,					//�����������

	CFG_SMARTFACE_COMMON_PARAMETER,
	CFG_SMARTFACE_AREADETECTION,
	CFG_SMARTFACE_AREASHIELDED,

	CFG_SMARTFACE_VERSION,
	CFG_SMARTFACE_ALARM,

	CFG_LINKAGE_BIND,					//ȫ�����ذ�����					by jfp 20181101
	CFG_CUSTOMIZED_QT,					//����-��ɳȫͼ�û�����				by jfp 20181115
	CFG_OSD,						//OSD
	CFG_SMART,
	CFG_EXPOSURE,

	CFG_NR,
};

/// ������������ConfigKindsȡ����Ӧ����
const char *getConfigName(int iConfigKind);

/// �����������Ƶõ��������ೣ��
int getConfigIndex(const char *sConfigKind);

enum AbilityKinds
{
	ABILITY_SYSTEM_FUNCTION,	///< ϵͳ����
	ABILITY_ENCODE,				///< ���빦��
	ABILITY_BLIND,				///< �ڵ���⹦��
	ABILITY_MOTION,				///< ��̬��⹦��
	ABILITY_DDNS_TYPES,			///< DDNS��������
	ABILITY_COMM_PROTOCOLS,		///< ����Э��
	ABILITY_PTZ_PROTOCOLS,		///< ��̨Э��
	ABILITY_TALK_ATTRIBUTE,		///< �Խ�����
	ABILITY_MULTI_LANG,			///< �������õ�����
	ABILITY_LANG_LIST,			///< ʵ��֧�ֵ����Լ�
	ABILITY_MULTI_VSTD,			///< �������õ���Ƶ��ʽ
	ABILITY_VSTD_LIST,			///< ʵ��֧�ֵ���Ƶ��ʽ
	ABILITY_UART_PROTOCOLS,		///<458Э��
	ABILITY_CAMERA,             ///< ����ͷ���������
	ABILITY_NETORDER,           //�������ȼ���������
	ABILITY_INTELLIGENT,	//���ܷ���������
	ABILITY_NET_CONNECT,	//������������
	ABILITY_CARSTATUSNUM,	//���س���״̬��
	ABILITY_VGARESOLUTION,// ֧�ֵ�VGA�ֱ���������
	ABILITY_ENC_STATICPARAM,	//��̬����������
	ABILITY_NET_KEYBOARD,	//�������������
	ABILITY_PTZCONTROL,	//PTZ����������
	ABILITY_DECODE_DELEY,	//�����������
	ABILITY_ONVIF_SUB_PROTOCOL,	//onvif��Э��
	ABILITY_DIMEN_CODE,//��ά��
	ABILITY_MAX_PRE_RECORD,//��������Ԥ¼ʱ��
	ABILITY_AHD_ENCODE_L, //AHDL������
	ABILITY_SUPPORT_EXTSTREAM,	//֧�ָ�����¼��
	ABILITY_KIND_NR,
};

/// ������������ȡ��Ӧ���ַ���
const char *getAbilityName(int iAbilityKind);

int getAbilityIndex(const char *sAbilityKind);

/// ϵͳ��Ϣ����
enum DeviceInfoKinds
{
	DEVICE_INFO_SYSTEM,		///< ϵͳ��Ϣ
	DEVICE_INFO_STORAGE,	///< �洢�豸��Ϣ
	DEVICE_INFO_WORKSTATE,	///< ����״̬��Ϣ
	DEVICE_INFO_WIFI_AP,    ///< WIFI AP��Ϣ
	DEVICE_OEM_INFO,
	DEVICE_INFO_GPS_STATUS, ///< GPS��λ��Ϣ
	DEVICE_INFO_WIFI_STATUS,///< Wifi������Ϣ
	DEVICE_INFO_3G_STATUS,  ///< 3G������Ϣ
	DEVICE_INFO_DAS_STATUS, ///< ����ע��״̬
	DEVICE_INFO_NR,
};

const char *getDeviceInfoName(int iDeviceInfoKind);

int getDeviceInfoIndex(const char *sDeviceInfoKind);

/// ����ϵͳ����
enum SystemOperations
{
	OPERATION_MACHINE,			///< �ػ�����������
	OPERATION_DEFAULT_CONFIG,	///< Ĭ�����ò���
	OPERATION_PTZ,				///< ��̨����
	OPERATION_MONITOR,			///< ���ӿ���
	OPERATION_PLAYBACK,			///< �طſ���
	OPERATION_TALK,				///< �����Խ�����
	OPERATION_DISK_MANAGER,		///< ���̹���
	OPERATION_LOG_MANAGER,		///< ��־����
	OPERATION_SYSTEM_UPGRADE,	///< ϵͳ����
	OPERATION_FILE_QUERY,		///< �ļ���ѯ
	OPERATION_LOG_QUERY,		///< ��־��ѯ
	OPERATION_TIME_SETTING,		///< ����ϵͳʱ��
	OPERATION_NET_KEYBOARD,		///< �������
	OPERATION_NET_ALARM,		///< ����澯
	OPERATION_SNAP, 		    ///< �����ֶ�ץͼ
	OPERATION_TRANS, 			///< ͸������
	OPERATION_UPDATA,			///< �ϴ�����
	OPERATION_TIME_SETTING_NORTC,///<����û��rtc���豸����ʱ��
	OPERATION_CPCDATA,		///<����ͳ�Ʋ�ѯ
	OPERATION_LOCALSEARCH,	///Զ����������
	OPERATION_MAILTEST,		///�ʼ�����
	OPERATION_PHONE,			///�ֻ�����
	OPERATION_STORAGE,		//Ӳ����Ϣ���ļ�ʱ�䡢¼��״̬
	OPERATION_FILE_CONTRAL,	///�ļ����ļ�������ɾ������
	OPERATION_MUSICFILE_QUERY,		///< ��Ƶ�ļ���ѯ
	OPERATION_MUSIC_PLAY,			///< ��Ƶ���ſ���
	OPERATION_DIG_SETIP,		///<����ǰ��ip
	OPERATION_UTC_TIME_SETTING,///����UTCʱ��
	OPERATION_SET_OSDINFO,//OSD��Ϣ���ã��ṩ���ͻ�
	OPERATION_SET_OSDINFO_V2,//OSD��Ϣ���ӣ����������ã�����������31������
	OPERATION_UPGRADE_VERSION_LIST,	///�ϰ汾�������汾�б��ѯ
	OPERATION_UPGRADE_VERSION,		///����������
	OPERATION_FTPTEST,     ///FTP����
	OPERATION_SET_LOGO,		//��Ƶ�ϵ��������ȳ��ҵ�LOGO
	OPERATION_CONSUMER_PRO_CMD, //�������Ʒ��������
	OPERATION_DDNSAPPLY,		//ddns apply��������
	OPEARTION_CALENDAR,     //�����ѯһ����������¼��
	OPEARTION_COMPRESS_PICTURE,  //�ֻ��˲�ѯ����ͼ
	OPERATION_NEW_UPGRADE_VERSION_REQ,	///�°��������汾��ѯ����
	OPERATION_NEW_UPGRADE_VERSION_REP,	///�°��������汾��ѯ�ظ�
	OPERATION_NEW_START_UPGRADE,
	OPEARTION_SPLIT_CONTROL,			//�л�DVR��Ԥ������ָ�ģʽ

	OPEARTION_FACEIMAGE_CONTROL,			//
	OPEARTION_FACECOMPARE_CONTROL,			//Compare
	OPEARTION_FACEWBLIST_CONTROL,			//WbList
	OPEARTION_FACEWBLIST_CONFIG,
	OPEARTION_CARLICENSEPLATE_CONFIG,       //����ͼƬ
	OPEARTION_GPIO_CONTROL,					//IO����

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
	appEventConsSensorAlarm, //�������Ʒ�󶨵��ⲿ�豸����
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

// ��־����
enum LogType
{
	logTypeAll,
	logTypeSystem,	/// ϵͳ��־
	logTypeConfig,	/// 
	logTypeStorage,
	logTypeAlarm,
	logTypeRecord,
	logTypeAccount,
	logTypeAccess,
	logTypeNr,
};

/// �õ���־��������
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


//ϵͳ�������
enum SystemDebug
{
	DEBUG_CAMERA,
	DEBUG_SHELL,
	DEBUG_CAMERA_SAVE_CMD,
	DEBUG_NR
};

/// ��������
enum DebugKinds
{
	DEBUG_OPR_PING_DEV,			///< 
	DEBUG_OPR_PING,				///<ִ��Ping����
	DEBUG_OPR_HDD_RW,			///<�洢�豸ִ�ж�д����
	DEBUG_OPR_USB_RW,			///<USB�豸ִ�ж�д����
	DEBUG_OPR_SD_RW,			///<SD��ִ�ж�д����
	DEBUG_OPR_GETPRODUCTDEFIN,	///<��ȡ�豸�ͺ�
	DEBUG_OPR_TESTPLAY,			///<���Ų���
	DEBUG_OPR_HDDINFO,			///<��ȡHDDINFO����
	DEBUG_OPR_TFSIZE,			///<��ȡTF����С����
	DEBUG_OPR_IRCUTSWITCH,		///<IRCUT�л�����
	DEBUG_OPR_SHOWBPSINFO,		///<
	DEBUG_OPR_NEXTCHANNELPREW,	///<
	DEBUG_OPR_SETMAC,			///<����MAC����
	DEBUG_OPR_KEYLIGHT,			///<���ð���ָʾ�ƽ������ģʽ
	DEBUG_OPR_NR,
};

const char *getDebugName(int iDebugKind);
int getDebugKind(const char *pDebugName);

#endif

