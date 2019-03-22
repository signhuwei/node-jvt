//
//  "$Id: NetIPAbilitySet.h 18716 2015-12-16 09:26:12Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
// 	Description:	
// 	Revisions:		Year-Month-Day  SVN-Author  Modification
//  Modify:			�������������
//

#ifndef __EXCHANGE_AL_ABILITY_SET_H__
#define __EXCHANGE_AL_ABILITY_SET_H__

#include "Types/Types.h"
#include "CommExchange.h"
#include "MediaExchange.h"
#include "PAL/Capture.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////
/// ϵͳ������
/// ���빦��
enum EncodeFunctionTypes
{
	ENCODE_FUNCTION_TYPE_DOUBLE_STREAM,		///< ˫��������
	ENCODE_FUNCTION_TYPE_COMBINE_STREAM,	///< ��ϱ���
	ENCODE_FUNCTION_TYPE_SNAP_STREAM,		///< ץͼ����
	ENCODE_FUNCTION_TYPE_WATER_MARK,		///< ˮӡ����
	ENCODE_FUNCTION_TYPE_IFRAME_RANGE,		///< I֡���
	ENCODE_FUNCTION_TYPE_LOW_BITRATE,		///< �����������ò�Ʒʹ��
	ENCODE_FUNCTION_TYPE_NR,
};

/// ��������
enum AlarmFucntionTypes
{
	ALARM_FUNCTION_TYPE_MOTION_DETECT,	///< ��̬���
	ALARM_FUNCTION_TYPE_BLIND_DETECT,	///< �����ڵ�
	ALARM_FUNCTION_TYPE_LOSS_DETECT,	///< ������ʧ
	ALARM_FUNCTION_TYPE_LOCAL_ALARM,	///< ���ر���
	ALARM_FUNCTION_TYPE_NET_ALARM,		///< ���籨��
	ALARM_FUNCTION_TYPE_IP_CONFLICT,	///< IP��ַ��ͻ
	ALARM_FUNCTION_TYPE_NET_ABORT,		///< �����쳣
	ALARM_FUNCTION_TYPE_STORAGE_NOTEXIST,	///< �洢�豸������
	ALARM_FUNCTION_TYPE_STORAGE_LOWSPACE,	///< �洢�豸��������
	ALARM_FUNCTION_TYPE_STORAGE_FAILURE,	///< �洢�豸����ʧ��
	ALARM_FUNCTION_TYPE_VIEDO_ANALYZE,      ///< ��Ƶ����
	ALARM_FUNCTION_TYPE_NET_ABORT_EXTEND,	//�����쳣��չ
	ALARM_FUNCTION_TYPE_IPC_ALARM,			//IPC����
	ALARM_FUNCTION_TYPE_NR
};

/// ���������
enum NetServerTypes
{
	NET_SERVER_TYPES_IPFILTER,		///< �׺�����
	NET_SERVER_TYPES_DHCP,			///< DHCP����
	NET_SERVER_TYPES_DDNS,			///< DDNS����
	NET_SERVER_TYPES_EMAIL,			///< Email����
	NET_SERVER_TYPES_MULTICAST,		///< �ಥ����
	NET_SERVER_TYPES_NTP,			///< NTP����
	NET_SERVER_TYPES_PPPOE,
	NET_SERVER_TYPES_DNS,
	NET_SERVER_TYPES_ARSP,			///< ����ע�����
	NET_SERVER_TYPES_3G,            ///< 3G���Ź���
	NET_SERVER_TYPES_MOBILE,			///< �ֻ����
	NET_SERVER_TYPES_UPNP,			///< UPNP
	NET_SERVER_TYPES_FTP,			///< FTP
	NET_SERVER_TYPES_WIFI,			///< WIFI
	NET_SERVER_TYPES_ALARM_CENTER,  ///< �澯����
	NET_SERVER_TYPES_NETPLAT_MEGA,  ///< ���Ż�ͨ
	NET_SERVER_TYPES_NETPLAT_XINWANG,  ///< ����
	NET_SERVER_TYPES_NETPLAT_SHISOU,  ///< ����
	NET_SERVER_TYPES_NETPLAT_VVEYE,  ///< ������
	NET_SERVER_TYPES_RTSP,           ///< RTSP
	NET_SERVER_TYPES_SHORT_MSG,      ///< ���ͱ�������
	NET_SERVER_TYPES_MULTIMEDIA_MSG, ///< ���ʹ���ͼ�Ĳ���
	NET_SERVER_TYPES_DAS,			///<DAS
	NET_SERVER_TYPES_LOCALSDK_PLATFORM,///<����ƽ̨��Ϣ����
	NET_SERVER_TYPES_GOD_EYE,///<���۽Ӿ�����ϵͳ
	NET_SERVER_TYPES_NAT,		///NAT��͸��MTU����
	NET_SERVER_TYPES_VPN,		///VPN����
	NET_SERVER_TYPES_NET_KEYBOARD,	///�����������
	NET_SERVER_TYPES_SPVMN,		///28181Э������
	NET_SERVER_TYPES_PMS,
	NET_SERVER_TYPE_KAICONG,		///��������
	NET_SERVER_TYPE_PROTOCOL_MAC,///֧��MACЭ��
	NET_SERVER_TYPE_XMHEARTBEAT, //��������
	NET_SERVER_TYPES_MONITOR_PLATFORM, //����������ƽ̨
	NET_SERVER_TYPES_ANJUP2P,			//anjuP2P
	NET_SERVER_TYPES_TUTKIOTC,			//TUTK IOTCƽ̨
	NET_SERVER_TYPES_BAIDUCLOUD,		//�ٶ���
	NET_SERVER_TYPES_MOBILWATCH,		//�ֻ�����
	NET_SERVER_TYPES_BJLTHY,				//�������ڷ��ʷ�����ƽ̨
	NET_SERVER_TYPES_OPENVPN,			//openvpn����
	NET_SERVER_TYPES_PROTOCOL_NAT,		//֧��NATЭ��
	NET_SERVER_TYPES_PLATFORM_GBEYES,	//֧�ֻ������ݵ���
	NET_SERVER_TYPES_DATALINK,			//DataLink�ͻ����������ִ�г���ʹ������
	NET_SERVER_TYPES_WIFI_MODE,			//�Ƿ�֧��wifiģʽ�������
	NET_SERVER_TYPES_IPV6,				//֧��ipv6
	NET_SERVER_TYPES_PMS_V2,			//�°�PMSҳ��
	NET_SERVER_TYPES_4G,				//���߲��ŵ�Э���������Ƿ���ʾ4G
	NET_SERVER_TYPES_NR,
};

/// Ԥ������
enum PreviewTypes
{
	PREVIEW_TYPES_TOUR,		///< ��Ѳ
	PREVIEW_TYPES_TALK,		///< GUI��������
	PREVIEW_TYPES_NR
};

///��������
enum CommTypes
{
	COMM_TYPES_RS485,			///<485����
	COMM_TYPES_RS232,			///<232����
	COMM_TYPES_NR
};

///���뷨����
enum InputMethod
{
	NO_SUPPORT_CHINESE,		//��֧����������
	NO_SUPPORT_NR
};

///��ǩ��ʾ
enum TipShow
{
	NO_BEEP_TIP_SHOW,
	NO_FTP_TIP_SHOW,
	NO_EMAIL_TIP_SHOW,
	NO_TIP_SHOW_NR
};

///���ع���
enum MobileDVR
{
	MOBILEDVR_STATUS_EXCHANGE,
	MOBILEDVR_DELAY_SET,
	MOBILEDVR_CARPLATE_SET,
	MOBILEDVR_GPS_TIMING,
	MOBILEDVR_DVR_BOOT_TYPE_SET,
	MOBILEDVR_NR
};

///��������
enum OtherFunction
{
	OTHER_DOWNLOADPAUSE,		//¼��������ͣ����
	OTHER_USB_SUPPORT_RECORD,	//USB֧��¼����
	OTHER_SD_SUPPORT_RECORD,		//SD֧��¼����
	OTHER_ONVIF_CLIENT_SUPPORT,	//�Ƿ�֧��ONVIF�ͻ���
	OTHER_NET_LOCALSEARCH_SUPPORT,	//�Ƿ�֧��Զ������
	OTHER_MAXPLAYBACK_SUPPORT,		//�Ƿ�֧�����ط�ͨ������ʾ
	OTHER_SPECIAL_NVR_SUPPORT,	//�Ƿ���רҵNVR
	OTHER_C7_PLATFORM_SUPPORT,		//֧��C7ƽ̨
	OTHER_MAIL_TEST_SUPPORT,		//֧���ʼ�����
	OTHER_SHOW_OSD_INFO,		//֧����ʾ3��OSD��Ϣ
	OTHER_HIDE_DIGITAL,		//ͨ��ģʽ���ι���	
	OTHER_ACUTANCE_HORIZONTAL,	//ˮƽ���
	OTHER_ACUTANCE_VERTIAL,//��ֱ���
	OTHER_BROAD_TRENDS,		//��̬����
	OTHER_NO_TALK,		//�Խ�����
	OTHER_ALTER_DIGITAL_NAME,	//�޸�����ͨ������OTHER_ALTER_CHANNELTITLE
	OTHER_SHOW_CONNECT_STATUS,      //֧����ʾwifi 3G ����ע��ȵ�����״̬
	OTHER_SUPPORT_ECACT_SEEK,	//֧�ֻطž�׼��λ
	OTHER_UPLOAD_TITLEANDSTATE,		//ͨ�����������ͨ��״̬�ϴ�������
	OTHER_NO_HDD_RECORD,		//��Ӳ��¼��
	OTHER_MUSICFILE_PLAY,		//������Ƶ�ļ�
	OTHER_SUPPORT_SET_DIG_IP,//����ǰ��ip����
	OTHER_VERSION_PRODUCT_TYPE,//֧���ڰ汾��Ϣ����ʾ�豸�ͺ�
	OTHER_SUPPORT_CAMERA_IMG_STYLE,//֧�������ͼ����
	OTHER_SUPPORT_TITLE_ABILITY,//֧���޸�onvif����(����ģ��ͨ������)
	OTHER_SUPPORT_DIMEN_CODE,//֧�ֶ�ά��
	OTHER_SHOWFALSE_CHECKTIME,//���ν�����ʱ��ͬ������
	OTHER_SUPPORT_TIME_ZONE, //֧��ʱ������
	OTHER_SHOW_ALARM_LEVEL_REGION,//��ʾ����ͨ���������ܵ������Ⱥ���������
	OTHER_SUPPORT_POS,//֧��POS����
	OTHER_HDD_LOWSPACE_USE_MB,//Ӳ�̿ռ䲻�㱨��������MB
	OTHER_SUPPORT_CUSTOMIZE_OEMINFO,//����OEM�ͻ��汾��Ϣ
	OTHER_DIGITAL_ENCODE,//����ͨ����������
	OTHER_RESUME_PTZ_STATE,//�����ָ���̨״̬
	OTHER_SUPPORT_SNAP_CFG,//֧��ץͼ����
	OTHER_ABNORMITY_SEND_EMAIL,//�洢�豸���ڼ��洢�쳣���洢�ռ䲻�㷢�ʼ�
	OTHER_SUPPORT_DIGITAL_PRE, //֧������ͨ��Ԥ¼
	OTHER_SUPPORT_WRITE_LOG,   //����ҳ������Ƿ�д��־��ѡ��
	OTHER_SUPPORT_CHANGE_ONVIF_PORT,//֧���޸�onvif�˿�
	OTHER_SUPPORT_COMM_DATA_UPLOAD,  //֧�ִ��������ϴ���ָ��������
	OTHER_SUPPORT_TEXT_PASSWORD,     //��¼�ɷ��������
	OTHER_SUPPORT_CLOUD_UPGRADE,	// ֧��ͨ���������豸����
	OTHER_SUPPORT_USER_PROGRAM,//֧�������ͻ�С����
	OTHER_SUPPORT_MODIFY_FRONT_CFG,//֧���޸�ǰ������
	OTHER_SUPPORT_FTP_TEST,    //�³���֧��FTP֧��FTP���ԣ��ϳ���֧�֡�
	OTHER_SUPPORT_PTZ_IDLE_STATE, //��̨����ʱִ�к��ֲ���������
	OTHER_SUPPORT_IMP_RCD,	//web���Ƿ��ṩ�ؼ�¼��������ѡ��	
	OTHER_SUPPORT_CAMERA_MOTOR_CTRL, //֧�ֻ�����������
	OTHER_SUPPORT_ENCODE_ADD_BEEP,// ��Ƶ����ÿ��30�����beep��	
	OTHER_SUPPORT_FISH_EYE,	        //���۹���������
	OTHER_SUPPORT_SPVMN_NAS_SERVER,	//���ճ���ͻ���nas����������
	OTHER_SUPPORT_SMALL_CHN_TITLE_FONT,  //IE�˴�12*18��ͨ���������
	OTHER_RTSP_CLIENT_SUPPORT,			 //����ͨ���Ƿ�֧��ͨ��RTSP����ǰ���豸
	OTHER_SUPPORT_CFG_CLOUD_UPGRADE, 	//֧���µ���������������
	OTHER_SUPPORT_STORAGE_FAIL_REBOOT,	//ȫ��Ӳ�̳�����Զ�����
	OTHER_SUPPORT_SPLIT_CONTROL,		//�޸�DVR��Ԥ������ָ�ģʽ
	OTHER_NR
};


/// ϵͳ����
struct SystemFunction
{
	bool vEncodeFunction[ENCODE_FUNCTION_TYPE_NR];		///< ���빦��EncodeFunctionTypes
	bool vAlarmFunction[ALARM_FUNCTION_TYPE_NR];		///< ��������AlarmFucntionTypes
	bool vNetServerFunction[NET_SERVER_TYPES_NR];		///< ���������NetServerTypes
	bool vPreviewFunction[PREVIEW_TYPES_NR];			///< Ԥ������PreviewTypes
	bool vCommFunction[COMM_TYPES_NR];			///<��������CommTypes
	bool vInputMethodFunction[NO_SUPPORT_NR];	///<���뷨����InputMethod
	bool vTipShowFunction[NO_TIP_SHOW_NR];//��ǩ��ʾTipShow
	bool vMobileDVRFunction[MOBILEDVR_NR];//���ع���MobileCar
	bool vOtherFunction[OTHER_NR];				//��������OtherFunction
};

//////////////////////////////////////////////////////////////////////////
/// ����������
//by zjh  20170802
/// ������Ϣ
struct EncodeInfo
{
	bool bEnable;			///< ʹ����
	int iStreamType;		///< �������ͣ�capture_channel_t
	bool bHaveAudio;		///< �Ƿ�֧����Ƶ
	uint uiCompression;		///< capture_comp_t������
	uint uiResolution;		///< capture_size_t������
};

/// ��������
/// ˵���� 
/// 1. vCombEncInfo ����ϱ����������ֻ��3000ϵ�е��豸�������������5000֮��Ķ�û��ʹ����
/// 2. vEncodeInfo �Ǹ�������ͨ����������Ϣ��ֻ����������DspAbility.uiImageSize��DspAbility.uiExImageSize��ʵ���ظ��ģ������ǵ�IE�ļ��������û���õ�
///    IE����ʽ�ǵ�DspAbility.uiImageSize��DspAbility.uiExImageSizeΪ0ʱʹ��vEncodeInfo��ͷ������
/// ����ͨ��������֧�ֵķֱ�������ȡ����2������: 1 - ��ǰͨ��֧�ֵķֱ��ʼ�DspAbility.uiImageSize 2 - ��ǰͨ��֧�ֵ���߱���������DspAbility.uiMaxPower
/// ����������������͸��������ܺ�
/// ����ͨ��������֧�ֵķֱ�������ȡ����3������: 1 - ��ǰͨ��֧�ֵķֱ��ʼ�DspAbility.uiExImageSize 2 - ��ǰͨ��֧�ֵ���߱���������DspAbility.uiMaxPower
/// 3 - ���������õķֱ����¸�����֧�ֵķֱ��ʼ�DspAbility.uiExImageSizeEx
/// iChannelMaxSetSync�� 1 - ��ʾ����ͨ���ķֱ��ʶ�Ҫһ��
struct EncodeAbility //�ṹ���д�������������ʹ��memset��ʼ�������ṹ�� sizeof[184 BYTE]
{
	int iMaxEncodePower;		///< ֧�ֵ��ܱ�������
	int iChannelMaxSetSync;		///< ÿ��ͨ���ֱ����Ƿ���Ҫͬ�� 0-��ͬ��, 1 -ͬ��
	int	iMaxBps;				///< ֧�ֵ������ʴ�СKbps
	EncodeInfo vEncodeInfo[CAPTURE_CHN_NR];	///< ������Ϣ
	EncodeInfo vCombEncInfo[CAPTURE_CHN_NR];	///< ��ϱ�����Ϣ
	std::vector<CAPTURE_CHANNEL_ABILITYV2> DspAbility;//sizeof[120 BYTE] 120*32 == 3804 BYTE
};

//by zjh 20170802
struct EncodeAbility_Expand
{
	unsigned int iMaxEncodePower;		///< ֧�ֵ��ܱ�������
	int iChannelMaxSetSync;		///< ÿ��ͨ���ֱ����Ƿ���Ҫͬ�� 0-��ͬ��, 1 -ͬ��
	uint nMaxPowerPerChannel[N_SYS_CH];		///< ÿ��ͨ��֧�ֵ���߱�������
	uint ImageSizePerChannel[N_SYS_CH];		///< ÿ��ͨ��֧�ֵ�ͼ��ֱ���
	uint ExImageSizePerChannel[N_SYS_CH];		///< ÿ��ͨ��֧�ֵĸ�����ͼ��ֱ���
	EncodeInfo vEncodeInfo[CAPTURE_CHN_NR];	///< ������Ϣ
	EncodeInfo vCombEncInfo[CAPTURE_CHN_NR];	///< ��ϱ�����Ϣ
	int	iMaxBps;				///< ֧�ֵ������ʴ�СKbps
	uint ExImageSizePerChannelEx[N_SYS_CH][CAPTURE_IMAGE_SIZE_EXT_NR];	///< ָ���������ֱ�����ÿ��ͨ���ĸ�����֧�ֵ�ͼ��ֱ���
};

struct DigitDevInfo
{
	bool enable; //�����Ƿ���ã������豸ʹ��
	int nCapture;//ģ��ͨ����
	int nAudio;//��Ƶͨ����
	int videoFormat;//��Ƶ��ʽ
	EncodeAbility ability;//��������
};

struct EncodeChDisplay
{
	uint displayChanelMask;	//IE��ʾ�ı�������ͨ��������
};

/// �����ڵ�������
struct BlindDetectFunction
{
	int iBlindConverNum;	///< �����ڵ�����
};

/// ��������������
struct MotionDetectFunction
{
	int iGridRow;
	int iGridColumn;
};

/// ֧�ֵ�DDNS����
struct DDNSServiceFunction
{
	std::vector<std::string> vDDNSTypes;
};

/// ����Э��
struct CommFunction
{
	std::vector<std::string> vCommProtocols;
};

/// ��̨Э��
struct PTZProtocolFunction
{
	std::vector<std::string> vPTZProtocols;
};

/// �Խ���Ƶ��������
struct TalkAudioFormatFunction
{
	AudioInFormatConfigAll audioFormat;
};

/// ����֧��
struct MultiLangFunction
{
	std::vector<std::string> vMultiLanguage;
};

/// ��Ƶ��ʽ֧��
struct MultVstdFunction
{
	std::vector<std::string> vMultiVstd;
};

///�������ȼ�����
struct NetOrderFunction
{
	bool bNetOrder;
};

///������������
struct NetConnectAbility
{
	int nCurTcpNum;
	int nMaxTcpNum;
	int nCurNatNum;
	int nMaxNatNum;
};
///����״̬��
struct CarStatusNum
{
	int iCarStatusNum;
};

/// ֧�ֵ�VGA�ֱ����б�
struct VGAResolutionAbility
{
	std::vector<std::string> vAbilityVGA;
};

//֧�ֵľ�̬�������������
//��ö��EncStaticParamV2
struct EncStaticParamAbility
{
	uint encStaticParam;
};

struct VNetKeyboardAbility
{
	std::vector<std::string> vTransProtocol;
	std::vector<std::string> vParserProtocol;
};

struct PTZControlAbility
{
	uint nPTZPosition;
};

struct DecodeDeleyTimePrame
{
	uint DecodeDeleyTime[DecodeDeley_TYPE_NR];
};
//�������룬������Ϊͨ�ýṹ�����
//EncStaticParamAbility��PTZControlAbility�ȶ�����������ṹ��
//int ��uint Ҳ���Թ������
typedef struct AbilityMask
{
	uint AbilityPram;
}AbilityEnum;

struct DimenCode
{
	int size;
	uchar code[3920];// MAX_MODULESIZE*MAX_MODULESIZE/32*4=3920���ֲ����� MAX_MODULESIZE = 177
};

struct DimenCodeAll
{
	DimenCode sn;
	DimenCode appIOS;
	DimenCode appAndroid;
	DimenCode otherInfo;  //�ͻ��Զ�����Ϣ
};

struct BrowserLanguageType
{
	int type;
};

struct CustomizeOEMInfo
{
	uint typeMask;//����: BITMSK(BURN_OEM_ID),BITMSK(BURN_OEM_PRODUCT),BITMSK(BURN_OEM_SERIAL)
	uint oemID;
	uint oemProduct;
	uint oemSerial;
};

//AHDLͨ�����룬��ͨ��ΪAHDL��1
struct AHDEncodeLMask
{
	uint AHDLMask;
};

///I֡�����Χ
struct Onvif_IFrameRange
{
	int main_min;
	int main_max;
	int sub_min;
	int sub_max;
};

#endif
