#ifndef _SDKDEFINE_H
#define _SDKDEFINE_H

/*******************************#Define Global************************************/
#include <map>
#include <afxtempl.h>
#include <VECTOR>

#include "VideoNetAPI.h"
//�ص�����
enum CALLBACK_TYPE
{
	CALLBACK_ALARM_INFO,				//������Ϣ
	CALLBACK_UPDATE_DEVC,				//�����豸��Ϣ
	CALLBACK_CENTER_CONTROL,			//
	CALLBACK_DEVC_DISCONNECT,			//�豸����
	CALLBACK_SUB_DISCONNECT,			//�����ӶϿ�
	CALLBACK_MOBILE_DVR_INFO,			//�ƶ�DVR��Ϣ
	CALLBACK_MEET_DATA,					//����
	CALLBACK_TALKING_DATA,				//�����Խ�
	CALLBACK_MEDIA_DATA,					
	CALLBACK_MEDIA_PLAYBACK_DATA,
	CALLBACK_PLAYBACK_POS,
};
enum VERSION_CLASS
{
	XM_EPSS = 0X0,		//EPSS�汾
	XM_PSS,				//PSS�汾
	XM_MINI,			//����汾
};

enum VENDOR_TYPE
{
	XMDEVC_TYPE = 0,       //����
	HKDEVC_TYPE,       //�����豸
	DHDEVC_TYPE,       //���豸
	HHDEVC_TYPE,		//�ƺ��豸
	ONVIFDEVC_TYPE,		//֧��OnvifЭ����豸
	TMDEVC_TYPE,		//�����豸
	GESSDEVC_TYPE,		//GESS�豸
	KWDEVC_TYPE,		//KINGWAVE�豸
	XMBACK_TYPE,       //�����ط�
	HKBACK_TYPE,        //�����ط�
	DHBACK_TYPE,        //�󻪻ط�
	HHBACK_TYPE,		//�ƺӻط�
	ONVIFBACK_TYPE,		//֧��OnvifЭ����豸�ط�
	TMBACK_TYPE,		//�����ط�
	GESSBACK_TYPE,		//GESS�ط�
	KWBACK_TYPE,		//KINGWAVE�ط�
};

enum DEVC_CLASS
{
	DEVC_NOTHING = 0X0,
	DEVC_DVR,				//һ��DVR
	DEVC_MOBILE_DVR,		//�ƶ�DVR
	DEVC_IPS,				//IP�洢
};

typedef enum _Data_Type
{
	XM_Data_NULL = -1,
	XM_Data_Dev	= 0,											//�豸����
	XM_Data_EicMap,												//���ӵ�ͼ
	XM_Data_RECORD,												//�Զ�¼��
	XM_Data_USER,												//�û�����
	XM_Data_Scheme,												//��Ѳ����
	XM_Data_ORG,												//��֯�ṹ����
	XM_LOCAL_DATA,												//�����޸�
	XM_SSVR_LIST,												//�洢�����б�
	XM_POWER_DEVLIST,											//Ȩ���豸�б�
	XM_ALARM_DATA,												//��������
	XM_USER_LIST,												//�û��б�
	XM_LICENCE_INFO,											//֤����Ϣ
	XM_NTDC_INFO,												//��ý��������������Ϣ
	XM_NRU_INFO,												//�洢��Ԫ�����Ϣ
	XM_LOGDIR_INFO,      										//��־ϵͳĿ¼��Ϣ
	XM_LOGFILE_INFO,     										//��־�ļ���Ϣ
	XM_LOCAL_ALARMDATA,	 										//���ر�������
	XM_LOCAL_ALARM_ENABLE,										//����ʹ��
	XM_DATA_IPS,												//IPS�豸
	XM_DATA_DEV_MOBILE_DVR,										//����ע���豸
	XM_DATA_DEV_MOBILEINFO,										//����ע���豸��Ϣ
	XM_MOBILE_SNAPPIC,											//�ƶ�DVRץͼ����
	XM_DECODER_ENABLE,                                      //������
	XM_Data_All = 255,											//��������
} XM_DataType;

// �豸�¼�ö��.
typedef enum _DEVICE_EVENT										//����Ԫ�ϲ�
{
//EPSS....................................................
	DEVENT_NOTHING = 0x0,
	DEVENT_CONNECT,												// ����.
	DEVENT_DELETE,												// �豸ɾ��.
	DEVENT_TALK,												// �Խ���
	DEVENT_REBOOT,  											// Զ������
	DEVENT_UPGRADE, 											// �豸����
	DEVENT_ALARM,   											// �豸�����¼�
	DEVENT_MULTIVIEW = 19,										// �໭��.ʵʱԤ��,//.Ŀǰnetsdkֻ��һ��Ԥ���ӿ�,�Ժ��������,�ŵȻ���Ԥ��,���������
	DEVENT_MODIFY,												// �޸��豸
	DEVENT_CONNFAIL,											// ����ʧ��
	DEVENT_SYNCHRO, 											// ʱ��ͬ��
	DEVENT_SNAPPIC,												// �ƶ�DVRץͼ

	DEVENT_ADD,													// ����豸
	DEVENT_RELOAD,												//���¸����豸��Ϣ
	DEVENT_STOP_TALK,
	DEVENT_ZONE_ADD,                                            //��������
	DEVENT_ZONE_DEL,                                            //����ɾ��
	DEVENT_ZONE_MODIFY,                                         //�����޸�   

	DEVENT_STARTRECORD,										    //��ʼ¼��
	DEVENT_ENDRECORD,											//ֹͣ¼��

	DEVENT_ENDRECORDCHANGEICON                                  //ֹͣ¼���޸�ͼ��

}DEVICE_EVENT;

// ͨ���¼�ö��.
typedef enum _CHANNEL_EVENT										//����Ԫ�ϲ�
{
//EPSS....................................................
	CHNLENT_NOTHING = 0x0,
	CHNLENT_AV,													// ����Ƶͬʱ����.
	CHNLENT_VIDEO,												// ��Ƶ.
	CHNLENT_AUDIO,												// ��Ƶ.
	CHNLENT_RECORDPLAY,											// ¼�񲥷�.
	CHNLENT_TALK,												// �Խ���
	CHNLENT_VIDEO_EX,											// ˫����ͼ�ڵ��ʵʱ����
	CHNLENT_MULTIVIEW,											// �໭��Ԥ��
	CHNLENT_VIDEO_ALARM,										// ������������
	CHNLENT_MOTION_DETECT,  									// ��̬���
	CHNLENT_CLICK_WND,											// ѡ�񴰿�
	CHNLENT_OPEN_VIDEO,											// ����Ƶ
	CHNLENT_CLOSE_VIDEO,										// �ر���Ƶ

	CHNLENT_SELECTRECORD,										//ѡ��¼��ͨ��
	CHNLENT_ADDRECORD,											//����¼��ͨ��
	CHNLENT_MODIFYRECORD,										//�޸�¼��ͨ��
	CHNLENT_NO_DISKSPACE,										//¼����Ӳ�̿ռ�
	CHNLENT_DISK_ERROR,											//���ܴ�����
	CHNLENT_DEV_DISCONNET,										//�豸����
	CHNLENT_REAL_BACKUP,										//ʵʱ����
	
	CHNLENT_STARTRECORD,										//��ʼ¼��
	CHNLENT_ENDRECORD,											//ֹͣ¼��
	CHNLENT_NODATA,												//������
	CHNLENT_NO_RECORD,											//û��¼���ļ�
	CHNLENT_START_BACKUP,										//��ʼ����
	CHNLENT_STOP_BACKUP,										//ֹͣ�Զ�����,û��������
	CHNLENT_END_BACKUP,											//�Զ����ݽ���
	CHNLENT_MANUAL_BACKUP,										//�ֶ�����
	CHNLENT_STOP_MANUAL,										//ֹͣ�ֶ�����
	CHNLENT_END_MANUAL,											//�ֶ����ݽ���
	CHNLENT_NO_DISKSPACE_BACKUP,								//û�д��̿ռ�
	CHNLENT_NO_POWER,											//û��Ȩ��
}CHANNEL_EVENT;

typedef enum _ALARM_ENUM
{
	ALARM_SENSOR,						//�ⲿ����
	ALARM_MOTION,						//��̬���
	ALARM_LOSS,							//��Ƶ��ʧ
	ALRAM_MASK,							//��Ƶ�ڵ�
	ALARM_VIDEOANALYSE,					//���ܷ���
	ALRAM_DISKFULL,						//Ӳ����
	ALARM_DISKERROR,					//Ӳ�̻�
	ALARM_VideoAnalyze,
	ALARM_DISCONNECT = 20,					//�豸����
	ALARM_SOUND_DETECT,
	ALARM_NM,
}ALARM_ENUM;


//�����û������е�Ȩ������
typedef enum __PowerType
{
	TYPE_MONITOR,						//ʵʱ����
	TYPE_PLAYFILE,						//¼��ط�
	TYPE_UPGRADE,						//Զ������
	TYPE_REMOTE_REBOOT,					//Զ������
	TYPE_REMOTE_CONFIG,					//Զ������
	TYPE_REMOTE_USER_MNG,				//Զ���û�����
	TYPE_PTZ_CTRL,						//��̨����
	TYPE_RECORD_CTRL,					//¼�����
	TYPE_LOCAL_RECORD,					//����¼��
	TYPE_DEVICE_MNG,					//�豸����
	TYPE_PROJECT_MNG,					//��������
	TYPE_EMAP,							//���ӵ�ͼ
	TYPE_SIXWINDOW,						//��Ƶ6����
	TYPE_RECORD_QUERY,					//¼���ѯ
	TYPE_RECORD_DOWNLOAD,				//¼������
	TYPE_RECORD_COPY,					//¼����
	TYPE_CONNDEV_DIRECTLY,				//ֱ���豸
	TYPE_DOOR_CTRL,						//�Ž�����
	TYPE_ALARMDEV_CTRL,					//��������������
}POWER_TYPE;

typedef enum _RECORD_EVENT
{
//EPSS....................................................
	RECORD_NOTHING = 0x0,
	RECORD_PLAY,						//����ط�
	RECORD_TIMEPLAY,					//ʱ��λط�
//.......................................................
	RECORD_STOP,						//�طŽ���
	RECORD_SEARCH,						//ˮӡ��ѯ
	RECORD_SEARCHOVER,					//ˮӡ��ѯ��ֹ
	RECORD_CLOSE,                       //�رջط�
	RECORD_NODATA,						//��ʱ��������
}RECORD_EVENT;



// ҵ���仯�¼���֪ͨ�����.
//............................
enum INFO_EVENT
{
	INFO_NOTHING = 0x0,	
	INFO_CREATE,						// ��ʼ��
	INFO_UPDATECHANNEL,					// ͨ���仯
	INFO_UPDATEDEVICE,					// �豸�仯�������������ӣ�
	INFO_RECORDPLAY,					// ¼���ļ����ţ���������طţ�
	INFO_DESTROY,						// ��ʼ��	
	INFO_STOPPLAY,						// ֹͣ����.
	INFO_SHOWWNDNUM,					// ��ʾ�Ӵ���.
	INFO_SETWNDCOLOR,					// ���ñ����Ӵ���ɫ
	INFO_RESETWNDCOLOR,					// �ָ��Ӵ���ɫ
	INFO_DISCONNECT,					//�쳣�Ͽ�����
	INFO_SETWNDCOLOR_ALARM,				// �����ⲿ�����Ӵ���ɫ
	INFO_SETWNDCOLOR_MOTION,			// ���ö�̬�����Ӵ���ɫ
	INFO_GETWNDCOLOR,					// �õ������Ӵ���ɫ
	INFO_MAX_ONEWND,					//����ȫ��Ļ����
	INFO_RESTORWNDNUM,					//�ָ�ԭʼ����
	INFO_DEVMANAGE,						// �豸����ɾ����
	INFO_CONNECTREALVIDEO,  //����ʵʱ��Ƶ
};


typedef enum _OTHER_LOG_EVENT
{
	NO_RECORD = 0x0,
}OTHER_LOG_EVENT;

//Ȩ�����
enum {
	//�豸���Ȩ��
	//ʵʱ����
	MULTI_MUTUAL_MONITOR1, 	              //ʵʱ����1
	MULTI_MUTUAL_MONITOR2,	              //ʵʱ����2
	MULTI_MUTUAL_MONITOR3,	              //ʵʱ����3
	MULTI_MUTUAL_MONITOR4,	              //ʵʱ����4
	MULTI_MUTUAL_MONITOR5,	              //ʵʱ����5
	MULTI_MUTUAL_MONITOR6,	              //ʵʱ����6
	MULTI_MUTUAL_MONITOR7,	              //ʵʱ����7
	MULTI_MUTUAL_MONITOR8,	              //ʵʱ����8
	MULTI_MUTUAL_MONITOR9,	              //ʵʱ����9
	MULTI_MUTUAL_MONITOR10,	              //ʵʱ����10
	MULTI_MUTUAL_MONITOR11,	              //ʵʱ����11
	MULTI_MUTUAL_MONITOR12,	              //ʵʱ����12
	MULTI_MUTUAL_MONITOR13,	              //ʵʱ����13
	MULTI_MUTUAL_MONITOR14,	              //ʵʱ����14
	MULTI_MUTUAL_MONITOR15,	              //ʵʱ����15
	MULTI_MUTUAL_MONITOR16,	              //ʵʱ����16
		
	//����ط�	
	SINGLE_MUTUAL_PLAYFILE1, 	          //����ط�1	
	SINGLE_MUTUAL_PLAYFILE2, 	          //����ط�2
	SINGLE_MUTUAL_PLAYFILE3, 	          //����ط�3		
	SINGLE_MUTUAL_PLAYFILE4, 	          //����ط�4	
	SINGLE_MUTUAL_PLAYFILE5, 	          //����ط�5	
	SINGLE_MUTUAL_PLAYFILE6, 	          //����ط�6
	SINGLE_MUTUAL_PLAYFILE7, 	          //����ط�7		
	SINGLE_MUTUAL_PLAYFILE8, 	          //����ط�8			
	SINGLE_MUTUAL_PLAYFILE9, 	          //����ط�9	
	SINGLE_MUTUAL_PLAYFILE10, 	          //����ط�10
	SINGLE_MUTUAL_PLAYFILE11, 	          //����ط�11		
	SINGLE_MUTUAL_PLAYFILE12, 	          //����ط�12	
	SINGLE_MUTUAL_PLAYFILE13, 	          //����ط�13	
	SINGLE_MUTUAL_PLAYFILE14, 	          //����ط�14
	SINGLE_MUTUAL_PLAYFILE15, 	          //����ط�15		
	SINGLE_MUTUAL_PLAYFILE16, 	          //����ط�16	

	OTHER_RECORD_CONTROL,					//¼�����
	REMOTE_USER_MANAGE,						//Զ���豸�û�����
	REMOTE_REBOOT_DEVICE,					//Զ������
	RECORD_QUERY,							//¼���ѯ
	RECORD_DOWNLOAD,						//¼������
	RECORD_COPY,							//¼����
	CONNDEV_DIRECTLY,						//ֱ���豸

	END_OF_DEV_RIGHTS,						//�豸���Ȩ�޽���
	
	//�豸�޹�Ȩ��
	LOCAL_RECORD = 100,						//����¼��
	SINGLE_MUTUAL_UPGRADE_BIOS,				//����BIOS
	ELECTRIC_MAP,							//���ӵ�ͼ
	DEVICE_MANAGE,							//�豸����
	PROJECT_MANAGE,							//��������
	MULTI_MUTUAL_CONFIG,					//������Ϣ
	BROADCAST_PAN_CONTROL,					//��̨����
	PROJECT_PLAY,							//��������
	SHOW_SIXWINDOW,							//6������Ƶ
	DOOR_CTRL,								//�Ž�����
	ALARMDEV_CTRL,							//��������������

	END_OF_USER_RIGHTS,						//�豸�޹�Ȩ�޽���
};

//Ȩ�޷�Χ
enum 
{
	//��Ҫ��¼Ȩ�޵Ĺ���
	REGISTER_DEV_RIGHTS_BEGIN = MULTI_MUTUAL_MONITOR1,
	REGISTER_DEV_RIGHTS_END = END_OF_DEV_RIGHTS,
	REGISTER_USER_RIGHTS_BEGIN = LOCAL_RECORD,
	REGISTER_UESR_RIGHTS_END = END_OF_USER_RIGHTS,
};

// ����״̬.
enum PLAY_STUTAS
{
	PLAY_NOTHING = 0x0,	// ��.
	PLAY_REAL,			// ʵʱ����.
	PLAY_MULTIVIEW,     //�໭��Ԥ��
	PLAY_NETBACK,		// ����ط�.
	PLAY_AUTORECORD		//�Զ�¼��
};

//¼������
typedef enum _RECORD_TYPE
{
	RECORD_NORMAL = 0x0,	// ��ʱ¼��
	RECORD_ALARM,			// ����¼��
	RECORD_MD,				// ��̬��ⱨ��
	RECORD_BACKUP,			//����¼��
	RECORD_ALL	=  255,				//����ͨ��
}RECORD_TYPE;

typedef enum _LOG_EVENT
{
	LOGEVENT_NOTHING = 0x0,
	LOGEVENT_DEVICE,
	LOGEVENT_CHANNL,
	LOGEVENT_PROJECT
//	LOGEVENT_DEVICECONNECT,        //�豸��������
//	LOGEVENT_DEVICEDISCONNECT,     //�豸�Ͽ�
//	LOGEVENT_CHANNLCONNECT,        //ͨ������
//	LOGEVENT_CHANNLDISCONNECT     //ͨ���Ͽ�
 	//LOGEVENT_AUTODISCON,     //�Զ��Ͽ�(�����鵽���豸����Ͽ�)

}LOG_EVENT;

typedef enum _LOGENT_STATUS
{
	STATUS_REQUESTING = 0x0,          //������
	STATUS_CONNECT,                 //����
	STATUS_CONNECTFAIL,				//����ʧ��
	STATUS_DISCONNECT ,             //�Ͽ�
	//EPSS............................................
	STATUS_BEGINPROJECT,             //��ʼ��Ѳ     
	STATUS_STOPPROJECT,               //ֹͣ��Ѳ
	//.................................................
	STATUS_VIDEO,					//��ʼ�洢
	STATUS_DISVIDEO,				//ֹͣ�洢 
	STATUS_NODATA,					//ͣס�洢,������
	STATUS_BACKUP,					//��ʼ����
	STATUS_NO_RECORD,				//û��¼���ļ�
	STATUS_MANUAL,					//�ֶ�����
	STATUS_STOP_MANUAL,				//ֹͣ�ֶ�����
	STATUS_STOP_BACKUP,				//ֹͣ�Զ�����
	STATUS_END_MANUAL,				//�����ֶ�����
	STATUS_END_BACKUP,				//�����Զ�����
	STATUS_NO_DISK_BACK,			//û�пռ�
}LOGENT_STATUS;

//�豸�ص�����
typedef enum _CALLTYPE
{
	DEV_ALARM,
	DEV_DISCONNECT,
}Dev_CallType;


//���ڵ�����ö��
typedef enum
{
	ITEM_ORG,		//��֯�ṹ
	ITEM_DEV,		//�豸
	ITEM_CHNNL,		//ͨ��
	ITEM_PREVCHANL,     //Ԥ��ͨ��
	ITEM_REAL_ROOT,	//ʵʱ�洢���ڵ�
	ITEM_BACK_ROOT,	//���ݸ��ڵ�
	ITEM_PROJECT,	//ʵʱ�洢����
	ITEM_BACKUP_PROJECT,	//��DVR�������ݷ���

	ITEM_IPS,		//IP�洢
	ITEM_IPS_DEV,	//ips�豸�µ�DVR
	ITEM_DECODER_DEV,
	ITEM_ALARM_CHANNEL,
	ITEM_DECODER_CHANNEL,
	ITEM_MAIN_CHANNEL,
	ITEM_SUB_CHANNEL,
	ITEM_DECODER_TOURPLAN,
	ITEM_DECODER_PLANNODE,
	ITEM_DECODER_LAYOUT,
	ITEM_DECODER_LAYOUTNODE,
	ITEM_DECODER_PROGRAM,
	ITEM_DECODER_PROGRAMNODE,
	ITEM_DECODER_OUTPUT
}TREE_ITEM_TYPE;

//��֯�ṹ�¼�ö��
typedef enum
{
	ORGENT_ADD,		//���
	ORGENT_MOD,		//�޸�
	ORGENT_DEL,		//ɾ��
}ORG_EVENT;

typedef enum _LOG_TYPE
{
	LOGTYPE_OPERATION = 0x1,//����
	LOGTYPE_ALARM = 0x2,	//�澯
}LOG_TYPE;

#ifdef OEM_YILITUO
typedef enum _LOG_OPERATION_TYPE_
{
	OPERATION_VIDEO = 0,
	OPERATION_PLAYBACK,
	OPERATION_TALK,
	OPERATION_USERMANAGER,
	OPERATION_CLIENTCONFIG,
	OPERATION_DEVICECONFIG,
	OPERATION_SYSTEMCONTROL,
	OPERATION_NUM ,
}LOG_OPERATION_TYPE;
#else
#ifdef OEM_LIANTENG
typedef enum _LOG_OPERATION_TYPE_
{
	OPERATION_VIDEO = 0,
	OPERATION_PLAYBACK,
	OPERATION_TALK,
	OPERATION_BACKUP,
	OPERATION_USERMANAGER,
	OPERATION_MAP,
	OPERATION_CLIENTCONFIG,
	OPERATION_DEVICECONFIG,
	OPERATION_SYSTEMCONTROL,
	OPERATION_COMALARM_CONFIRM,
	OPERATION_COMALARM_ARM,
	OPERATION_COMALARM_DISARM,
	OPERATION_NUM,
}LOG_OPERATION_TYPE;

typedef enum _LOG_ALARM_TYPE_
{
	ALARM_IOTRIGGER = 0,
	ALARM_MOTIONDETECT,
	ALARM_LOSSDETECT,
	ALARM_BLINDDETECT,
	ALARM_VIDEOANALYSEDETECT,
	ALARM_DSIKEEROR,
	ALARM_DISKFULL,
	ALARM_COM,
	ALARM_NUM,
}LOG_ALARM_TYPE;

#else
typedef enum _LOG_OPERATION_TYPE_
{
	OPERATION_VIDEO = 0,
	OPERATION_PLAYBACK,
	OPERATION_TALK,
	OPERATION_BACKUP,
	OPERATION_USERMANAGER,
	OPERATION_MAP,
	OPERATION_CLIENTCONFIG,
	OPERATION_DEVICECONFIG,
	OPERATION_SYSTEMCONTROL,
	OPERATION_NUM,
}LOG_OPERATION_TYPE;

typedef enum _LOG_ALARM_TYPE_
{
	ALARM_IOTRIGGER = 0,
	ALARM_MOTIONDETECT,
	ALARM_LOSSDETECT,
	ALARM_BLINDDETECT,
	ALARM_VIDEOANALYSEDETECT,
	ALARM_DSIKEEROR,
	ALARM_DISKFULL,
	ALARM_NUM,
}LOG_ALARM_TYPE;

#endif //OEM_LIANTENG
#endif //OEM_YILITUO



//Ѱ����ý������е�һЩ����ֵ
enum 
{
	FIND_SECCESS,		//�ɹ�
	REC_FLUX_EXCEED,	//�������ݳ���
	SEND_FLUX_EXCEED,	//�������ݳ���
};

typedef enum _DEV_LOGIN_TYPE_
{
	LOGIN_TYPE_DOMAIN,			//����
	LOGIN_TYPE_IP,				//IP��ַ
	LOGIN_TYPE_ARSP_SERIAL,		// ARSP ���кţ�Ŀǰ���豸mac��ַȥ���м�ָ�����
	LOGIN_TYPE_CLOUD_SERIAL,		// �� ���к� ��Ŀǰ�Ǹ����豸mac��ַ�������һ��16λ�ַ�����
#ifdef ADDALLDEVICESINLAN
	LOGIN_TYPE_MAC					//�ȸ���MAC��ַ�ҵ��������ڵ��豸����½���Ҳ�������MAC�������к����Ʒ�ʽ��½
#endif
}DEV_LOGIN_TYPE;

typedef enum _PLAYBACK_TYPE_
{
	PLAYBACK_TYPE_REMOTE,		//Զ�̻ط�
	PLAYBACK_TYPE_LOCAL		 //���ػط�
}PLAYBACK_TYPE;

typedef enum _DEV_DISCONNECT_TYPE_
{ 
	DISCONNECT_PREVIEW,       //����Ԥ�����豸���ӶϿ�
	DISCONNECT_LOCALRECORD,	  //¼��ƻ����豸���ӶϿ�
	DISCONNECT_DOWNLOADPLAN,  //���ؼƻ�
	DISCONNECT_DECODER,		  //�������豸���ӶϿ�
	DISCONNECT_TYPE_NUM
}DEV_DISCONNECT_TYPE;
struct ModuleFileInfomations
{
	CString		strFullPath;
	CString		strPath;
	CString		strDrive;
	CString		strDir;
	CString		strName;
	CString		strExt;
};

#define _DELETE_(x)											if(x){delete x;x = NULL;}
#define _DEL_ARRAY_(x) 										if(x){delete [] x;x = NULL;}

#define	 LOGIN_FILE											_T("ConfigModule.ini")
#define	 CMS_CONFIG											_T("User.ini")
#define	 CMS_SKIN_DIR										_T("Skin\\")
#define	 CMS_XML_DIR										_T("XML\\")
#define	 CMS_LOG_DIR										_T("LOG")
#define	 CMS_ALARM_LOG										_T("alarmlog.xml")
#define	 CMS_OPR_LOG										_T("oprlog.xml")
#define	 CMS_SOUND_FILE										_T("Sound\\AlarmSound.wav")
#define	 THEME_FILE											_T("theme.ini")

#define	 HEARTBEETINTER										40*1000
#define  DHDEVCPORT											37777 					//���豸�˿�
#define  HKDEVCPORT											8000  					//�����豸�˿�

const char NAME_INVALID_CHARS[]								= {'\\','/','*','?',':','"','<','>','|'}; //�����е���Ч�������ַ������ļ����ļ������Ʋ��ܰ�����Щ�ַ���
const int FILE_BUF_SIZE										= 4096;
const int FILE_TOTAL_NUM									= 2;
//const int TALK_PORT									= 100;   //��H264play.h�ж���Խ��˿�

//��Ѳʱ���,��ʼ�����պͽ���������
const int BYEAR   											= 1981;
const int BMONTH  											= 8;
const int BDAY    											= 21;
const int EYEAR   											= 1982;
const int EMONTH  											= 2;
const int EDAY 	  											= 15;


const int			MAXALARMBUF								= 100;
const int			MAXUSERPSWLENGTH						= 128;
const int			TIMEOUT									= 2000;
const int			MAX_BUF_SIZE 							= 180 * 1024;
static const int	MAXNAMESIZE 							= 64;						//32;
static const int	MAXWNDTOTAL								= 144;		   //���֧����Ƶ������Ϊ128				
static const int	MAXDESSCRIPTION							= 200;
static const int	ALARMFIRSTWND							= 0;		
static const int	ALARMWNDTOTAL							= 4;
static const int	TIMELIMIT								= 90;
static const int	MAXALARMTOTALWND						= 20;						//���������ʾ�Ĵ�����
static const int	MAXPATH 								= 128;						//Ŀǰ��ų���
static const int	MAXDEVIC 								= 16;						//����豸��
static const int	COUNTPREVCHANNL 						= 0;						//Ԥ��ͨ������
static const int	PREVIEWCHANNL 							= NET_MAX_CHANNUM;						//Ԥ��ͨ���� 
static const int	CHANNELS_MAX 							= PREVIEWCHANNL + COUNTPREVCHANNL ;   
static const int	MAX_PSW_LENGTH 							= 256;						

static const int	MAX_IP_SIZE								= 16;
static const int	MAX_SINGLE_BUF_SIZE						= 4 * 1024;					//ÿ����Ƶ���ĳ���
static const int	HEAD_SIZE								= 32;
//static const int	CHANNELS_MAX = 16;
static const int	TOP_HIGHT								= 72;			//����ͼƬ�ĸ�
static const int	MAX_RECORD_FILE							= 100;			//���¼���ļ�������
static const int	MAX_AREA_NODE							= 100;
static const int    MAX_CMS_CHN                             = 1024;
static const int    MAX_SEARCH_DEVICE                       = 500;

#define MAX_HDDECODER_CHANNEL_NUM                           4
#define MAX_TOURPLAN_NUM                                    64
#define DISK_DEL_MIN				                         (256*1024*1024) // �洢�ռ�ֻ��128Mʱ������¼��
#define DISK_FREE_MIN				                         (128*1024*1024) // �洢�ռ�ֻ��128Mʱ������¼��

#define SYSTEM_LOGFILE 										_T("SYSTEMLOG.dat")
#define MAP_FOLDER											_T("Temp_SCMap\\")					//
#define ENERGEBT_RECORD 									_T("Record\\")   //����¼���ļ�����,
#define DH_LOG												_T("LOG\\")
#define LOCAL_MAP_FOLDER									_T("XML\\map\\")
#define REMOTE_MAP_FOLDER									_T("R_map\\")
#define LICENCE_FILE  										_T("Licence.dat")

#ifdef OEM_Airlink
#define	SYSTEM_USER											_T("admin")
#else
#define	SYSTEM_USER											_T("super")
#endif // OEM_Airlink

#define SYSTEM_GROUP										_T("administrator")
#define DATA_XML											_T("xml\\Temp_SCData.xml")
#define ALARM_XML   										_T("xml\\Alarm.xml")				//�����������ݣ���ص�Ԫ�ã�
#define ALARM_WATCH_XML										_T("xml\\Alarm_watch.xml")			//�����������ݣ���ص�Ԫ�ã�
#define ALARM_XML_SHOW										_T("xml\\Alarm_show.xml")			//�����ñ������ݣ�������Ԫ�ã�
#define ALARM_ENABLE_XML 									_T("AlarmEnable.xml")
#define DECODER_ENABLE_XML 									_T("DecoderEnable.xml")
#define ALARM_PERIOD_XML 									_T("xml\\AlarmPeriod.xml")
#define LOGINDATA_XML										_T("xml\\Login_DevData.xml")
#define	XM_DEVICE_XML										_T("Data.xml")
#define	XM_USER_XML											_T("Users.xml")
#define	XM_ALARM_XML										_T("XML\\AlarmPlan.xml")
#define	XM_FILE_XML											_T("XML\\XMLManager.xml")
#define LOCAL_DATA_XML										_T("XML\\Data.xml")
#define LOCAL_USER_XML										_T("XML\\Users.xml")
#define REMOTE_DATA_XML										_T("XML\\R_Data.xml")
#define REMOTE_USER_XML										_T("XML\\R_Users.xml")
#define VIDEO_COLOR_XML 									_T("VideoColor.xml")
#define DECODER_PREPROGRAM_XML								_T("XML\\DecoderPreProgram.xml")

#define	MAX_CHILD  											9							//����ӽ���������
#define XM_DEVICE_DICALARM									0x1009						//�豸���߱���
#define	MAX_NAME_SIZE										64							//�û�������
#define	MAX_DEV_NUM											256							//ÿ��ת�����������ӵ���������
#define MAX_IP_SIZE											16							//IP��ַ����
#define LISTEN_PORT											39999						//�����˿ں�
//#define PACKHEAD_LENGTH										32							//��ͷ����
#define PACKAGEBUF_SIZE										180 * 1024
#define RECEIVE_BUFFER										16 * 1024					//���յ����̶�
#define MAX_TOTAL_CHANNEL									500
#define MAX_IPS_DEV											1000

#define MAX_LENGTH											255							//�û���󳤶�
#define ID_RECORD_CHANNEL									0
#define ID_RECORD_RUNING									1
#define ID_CAM_IAMGE										2
#define ID_DEVICE_CONNECT_IMAGE								3
#define ID_DEVICE_UNCON_IMAGE								4

#define MAX_BACKUP_CHANNEL									50							//�������ͬʱ����ͨ����
#define MAX_CONNECT_DEVNUM									1							//��ת����ÿ�����Ӵ���5̨�豸������

#define DEFAULTBUF_SIZE										16*1024						//Ĭ��ÿ�������С
#define SAVE_BUFF_SIZE										160*1024					//���������С
#define SEND_DATA_LENGTH									4*1024
#define TIMER_ONCE											1							//��ʱ�����
#define N_TSECT												6							//ʱ��θ���
#define MAX_USERNAME_LENGTH									16							//DVR�û�����󳤶�
#define MAX_USER_PSW										16							//DVR������󳤶�
#define DEV_TREEHEIGHT										200							//�豸���߶�
#define DEV_TREEWIDTH										200							//�豸�����
#define MAX_STREAM				2		//����м�������

#define  SPLIT_HIGHT 50
#define  MAX_DECODERCHNNEL_SUP   32                  //��ǰ�豸�������֧�ֽ���ͨ����λ32

#define UM_ICONNOTIFY										WM_USER + 100					//���ͼ��
#define ID_SHOW_WINDOW										WM_USER + 101					//��ʾ����
#define ID_EXIT_SYSTEM										WM_USER + 102					//�˳�ϵͳ
#define ID_SHOW_ABOUT										WM_USER + 103					//����
#define ID_ADD_NETDRIVES									WM_USER + 1111				//�������ӳ����
#define ID_ADD_BACKUP_DISK									WM_USER + 1116				//��ӱ�����
#define ID_MODIFY_BACKUP_DISK								WM_USER + 1119				//�޸ı��ݴ���
#define ID_STOP_RECORD										WM_USER + 1121
#define ID_CONFIG											WM_USER + 1122
#define ID_START_PROJECT									WM_USER + 1123
#define ID_CONFIG_PROJECT									WM_USER + 1124
#define ID_SELECT_ALL										WM_USER + 1125
#define ID_UNSELECT_ALL										WM_USER + 1126
#define ID_REAL_BACKUP										WM_USER + 1127
#define ID_BACKUP_DVR										WM_USER + 1128
#define ID_MANUAL_BACKUP									WM_USER + 1129
#define ID_STOP_MANUAL_BACKUP								WM_USER + 1130
#define IDC_SYSTEMUSER										WM_USER + 3000

typedef struct {
	char nName[64];			//����
	char nVer[64];			//�汾��
	char nPrivided[64];		//�ṩ��
	char nZhuChe[64];		//ע����
	char nLicence[64];		//ע���
	int	 nMaxDay;			//ʹ������(��)
	int  nMaxChannel;		//ͨ����
	char szFirstDay[10];	//�״�ʹ������
	int  nComfirm;			//��֤��
	int  nUsedDay;			//�Ѿ�ʹ������
	BOOL bPSS;				//�Ƿ���PSS
}LICENCE_INFO;

typedef union {	//IP addr
	char	c[4];
	short	s[2];
	long	l;
} UNION_LONG;

typedef struct _ALARM_TYPE
{
	BOOL bEnable;						//�Ƿ���Ч
	BOOL bAutoWatch;					//�Ƿ��Զ�����
	BOOL bSound;						//�Ƿ���ʾ������
	unsigned int	iIgnoredSecond;		//��������ʱ��
	char szSoundPath[256];	//��������·��
	
	_ALARM_TYPE()
	{
		bEnable = TRUE;
		bAutoWatch = FALSE;
		bSound     = FALSE;
		iIgnoredSecond = 5;
		memset( szSoundPath , 0 , sizeof( szSoundPath ) );
	}
}Alarm_Type; //��ͬ���͵ı�������

typedef struct _AREA_INFO
{	
	char szArea[MAXNAMESIZE];                   // ��������
}AREA_INFO,*pAREA_INFO;

typedef struct _DEVICE_INFO
{	
	long			ID;										// Ψһ��ʶ��.
	char			szArea[MAXNAMESIZE];                   // ��������
	char			szDevName[MAXNAMESIZE];   				// ������.
	char			szDevIP[MAXNAMESIZE];     				// ����ip.������DDNS���ʾDDNS����ĵ�ַ
	char            szLanIP[MAXNAMESIZE];                   //����IP 
	char			szUserName[MAXNAMESIZE];  				// ��½�û���.	
	char			szPassWord[MAXNAMESIZE];  				// ��½�û�����.
	char			szHostName[MAXNAMESIZE];				//DDNS������
	int				nTotalChannel;   						// �豸��ͨ����.
	int				nAlarmChannel;							//����ͨ��
	int				nError;          						//�����ֽ�,��¼���豸��½���ص�ʧ����Ϣ
	int				nDDNSFlag;		 						//DDNS��������1:ʹ��, 0:��ʹ��
	DWORD			dwLoginType;		 						// ��½��ʽ   enum DEV_LOGIN_TYPE
	DWORD			dwDevIP;		 						// ����ip.
    DWORD			dwPort;          						// ��½�˿ں�.	
	DWORD			nFlag;           						// �����ֽ�. (�ݼ�¼�豸��¼ID)
	DWORD			dwPos;		 						    //��¼�ڴ����е�λ��
	DWORD			dwTreeItem;								//��¼�豸���еĽڵ��������Խ�ʡ�����¼�
	DWORD			dwOrgID;								//��֯�ṹID
	DEVC_CLASS      devcType;        					    //�豸���ͣ�Ŀǰ������dvr���Ž��豸�������豸����
	VIDEONET_DEVICEINFO  NetDeviceInfo;  				    // DVR�������������DVRӲ�̸�����DVR���ͣ�DVRͨ������
	VENDOR_TYPE     vendorType;                             // ���ң��������󻪣�����,�ƺ�
	DWORD           dwSearchTreeItem;   			        //��¼�������еĽڵ��������Խ�ʡ�����¼���
	int             nLinkMode;                              //����ģʽ,TCP��UDP,0ΪTCP,1ΪUDP
	char			szMacAddress[MAXNAMESIZE];
	int             nARSPStatus;                                 //����ARSP�û�����ȡ���豸�Ƿ����ߡ� 1���ߣ�0������            
}DEVICE_INFO,Devc_Info,In_DeviceInfo,*pDEVICE_INFO;

typedef enum 
{
	 TV_TYPE_NONE = 0,
	 TV_TYPE_LAYOUT = 1,
	 TV_TYPE_TOUR = 2,
	 TV_TYPE_SINGLECAMERA = 3
};

typedef struct DECODER_WND
{
	int nWndNo;
	CRect rtWnd;
	char chName[64];
	int nDecoderID;
	int nDecoderOutput;
	int bConnected;
	int nType;
	int nID;
	int nChannelNo;
	bool bTourStart;
};

typedef struct PREPROGRAM
{
	int nID;
	bool bUse;
	char chName[64];
	DECODER_WND wnd[MAXWNDTOTAL];
};
// ͨ����Ϣ.
typedef struct _CHANNEL_INFO
{
	char				szChnnelName[MAXNAMESIZE];			// ͨ������.
	int					nChnnID;							// ���ڵ�ͼ�ڵ����
	int					nChannelNo;							// ͨ����.
	int					bUserRight;							// �û�Ȩ��(ʹ��).
	int					PreViewChannel;						// Ԥ��ͨ��
	int					nStreamType;						// ��������
	DEVICE_INFO			DeviceInfo;							// �豸��Ϣ.
	int					nCombinType;						// ��ϱ���ģʽ
	DWORD				dwTreeItem;							//��¼�豸���еĽڵ��������Խ�ʡ�����¼�
	int                 nFlag;								//1Ϊѡ��Ϊ¼�� 0 Ϊû�б�ѡ�� 2 Ϊ����¼��
	unsigned int        nWndIndex;
}CHANNEL_INFO,*pCHANNEL_INFO;

typedef struct CameraLayout
{
	int nLayoutID;
	int nUsed;
	char szLayoutName[64];
	int nCameraCount;
	CHANNEL_INFO Cameras[36];
};
typedef struct _HDDECODER_INFO
{	
	long			ID;										// Ψһ��ʶ��.
	char			szDevName[MAXNAMESIZE];   				// ������.
	char			szPassWord[MAXNAMESIZE];  				// ��½�û�����.
	int             nOutPuts; //���ͨ����
	DEVICE_INFO    outputsInfo[MAX_HDDECODER_CHANNEL_NUM];  				
}DECODER_INFO;
// ͨ����Ϣ.
typedef struct _CHANNEL_INFO_EX
{
	char				szChnnelName[MAXNAMESIZE];		// ͨ������.
	int					nFlag;              			//0Ϊͨ������,1Ϊͨ���Ͽ�
	int					nChnnID;						// ���ڵ�ͼ�ڵ����
	int	 				nChannelNo;						// ͨ����.
	int					bUserRight;						// �û�Ȩ��(ʹ��).
	int					PreViewChannel;					//Ԥ��ͨ��
	int					nStreamType;					//��������
	DWORD				dwTreeItem;						//��¼�豸���еĽڵ��������Խ�ʡ�����¼�
	DWORD               dwSearchTreeItem;   			//��¼�������еĽڵ��������Խ�ʡ�����¼���
	NET_RealPlayType		MultiType;						//Ԥ����ʽ
}CHANNEL_INFO_EX,*pCHANNEL_INFO_EX;

// �豸��Ϣ��.
typedef struct _DEVICE_INFO_EX
{
	DEVICE_INFO			DeviceInfo;
	pCHANNEL_INFO_EX	pChnlInfo; 					// ͨ������ͷ��ַ.
	int                 nSize;     					// ͨ�����鵥λ����(ͨ������)
	bool                bIOControlFlag;  			// 12v���ؿ���
	DWORD				dwResarchTreeItem;			// ��¼�������еĽڵ��������Խ�ʡ�����¼���
	char                szAlarmPlanName[MAXNAMESIZE]; //�豸�����ڵı�������
}DEVICE_INFO_EX,Devc_Info_EX,*pDEVICE_INFO_EX;

// �豸״̬.
typedef struct _DEVICE_STATUS
{
	DEVICE_INFO			DeviceInfo;					// �豸��Ϣ.
	DEVICE_EVENT		DeviceEvent;				// �豸�¼�(״̬����).	
	int					nStatus;					// ����״̬(����).
	long				lParam;						// Ԥ����.
}DEVICE_STATUS,*pDEVICE_STATUS;

// ͨ��״̬.
typedef struct _CHANNEL_STATUS
{
	CHANNEL_INFO		ChannelInfo;				// ͨ����Ϣ.
	CHANNEL_EVENT		ChannelEvent;				// ͨ���¼�(״̬����).
	int					nStatus;					// ����״̬(����).
	long				lParam;						// Ԥ����.׼����¼���ž��
}CHANNEL_STATUS,*pCHANNEL_STATUS;


//��֯�ṹ��Ϣ
typedef struct 
{
	long				nID;							//id
	long				lParentID;						//���ڵ�ID	
	char				szName[MAXNAMESIZE];			//����
}ORGANIZATION_INFO;

typedef struct _DISCHANNELINFO
{
	int					nWndID;							//���ں�
	int					nSubWnd;						//�Ӵ��ں�
	int					nChannelNo;
	int                 nStream;                        //��������
	int					PreViewChannel;					//Ԥ��ͨ��
	NET_RealPlayType		MultiType;						//Ԥ����ʽ
}DISCHANNELINFO, *pDISCHANNELINFO;


//�����û�������յ��豸��Ϣ�ṹ
typedef struct _USER_DEVICE_INFO
{
	int					nDeviceID;
	DWORD 				dwPort;
	int					nChannelTotal;
	char				szDevName[MAXNAMESIZE];
	char				szDevIP[MAXNAMESIZE];
}USER_DEVICE_INFO, *pUSER_DEVICE_INFO;


// ͨ������.
//..........
typedef struct _CHANNEL_CTRL
{
	CHANNEL_INFO	ChannelInfo;					// ͨ����Ϣ.
	CHANNEL_EVENT		ChannelEvent;					// ͨ���¼�(״̬����).
	int					nSwith;							// Ҫ��״̬(����).
	long				lParam;							// Ԥ����.
	long				lResevred[5];					//Ԥ����
}CHANNEL_CTRL,*pCHANNEL_CTRL;

// �豸����.
//..........
typedef struct _DEVICE_CTRL
{
	DEVICE_INFO			DeviceInfo;						// �豸��Ϣ.
	DEVICE_EVENT		DeviceEvent;					// �豸�¼�(״̬����).
	int					nSwith;							// Ҫ��״̬(����).
	long				lParam;							// Ԥ����.
}DEVICE_CTRL,*pDEVICE_CTRL;


//����ʹ�ܽṹ
typedef struct _ALARM_ENABLE
{
	long 				lDevID;
	char 				nChannel[NET_MAX_CHANNUM];
}ALARM_ENABLE;


typedef struct _OTHER_LOG
{
	OTHER_LOG_EVENT		LogEvent;      				//������Ϣ������
	long				lParam;						//������
}OTHER_LOG, *pOTHER_LOG;

//�Ͽ��豸��Ϣ
typedef struct _DISDEVINFO
{
	DEVICE_INFO			DeviceInfo;					// �豸��Ϣ.
	DISCHANNELINFO		ChannelInfo[CHANNELS_MAX];	//ͨ����Ϣ
	int					nSize;
	DEV_DISCONNECT_TYPE DisconnectType;
}DISDEVINFO,*p_DisDevInfo;



//��������
typedef struct _RECORD_QUERY_INFO 
{
	DWORD				dwUserData;					//�û����������߳�ʹ��
	DWORD               dwFileHandle;              //�û����������߳�ʹ��
	int                 nQueryMode;                 //0: by name 1: by time
	long				lDevID;						//�豸ID
	unsigned __int64	nChannelNO;					//ͨ����, ��ʱ���ѯʱͨ�����������ʾ
	int					nMaxSize;					//���¼������
	int					nRecType;					//¼������
	int					nRecSource;					//¼����Դ����QUERY_MODE
	char				szCardNO[64];				//��������
	VIDEONET_TIME			BegTime;
	VIDEONET_TIME			EndTime;
	int    iSync;               ///< �Ƿ���Ҫͬ��
}RECORD_QUERY_INFO;

typedef struct _PACKET_BUF
{
	unsigned char		szDataBuf[MAX_BUF_SIZE];
	int					nDataSize;
}PACKET_BUF;

enum QUERY_MODE
{
	DEVICE_BY_NAME, //�豸�طţ����ļ���
	LOCAL_BY_NAME,  //���ػطţ����ļ���
	DEVICE_BY_TIME, //�豸�طţ���ʱ��
	LOCAL_BY_TIME,  //���ػطţ���ʱ��
};

typedef struct _RECORD_QUERY_PARAM
{
	long				lDevID;
	unsigned __int64	nChannelNO;
	int					nMaxSize;					//���¼������
	int					nRecType;					//¼������
	int					nRecSource;					//¼����Դ( 0 - �豸���ļ���  1 - ���ذ��ļ��� 2 - �豸��ʱ�� 3 - ���ذ�ʱ��)
	char				szCardNO[64];				//��������
	VIDEONET_TIME			BeTime;
	VIDEONET_TIME			EndTime;
	int    iSync;               ///< �Ƿ���Ҫͬ��
}RECORD_QUERY_PARAM;

typedef struct _TIME_NETPLAY_PARAM
{
	NEW_NET_TIME			BeTime;
	NEW_NET_TIME			EndTime;
}TIME_NETPLAY_PARAM;

typedef struct _LOG_INFO
{
	LOG_TYPE			type;                    //����,�и澯�Ͳ���
	unsigned int		subType;                 //������, �澯�Ͳ����ֱ��в�ͬ��������
	VIDEONET_TIME		time;                    //����ʱ��
	long				lDevID;					 //�豸ID
	char				DevcName[MAXNAMESIZE];       //�豸��
	char				UserName[MAXNAMESIZE];       //�û���
	LOG_EVENT			event;                       //�¼�
	LOGENT_STATUS       status;                      //�¼�3��״̬,������,�ɹ���ʧ�� 0, 1 , 2
	int					nNo;
	char				DescrInfo[MAXDESSCRIPTION];  //������Ϣ
}LOG_INFO, *pLOG_INFO;

//���ڵ����ݵĽṹ
typedef struct 
{
	TREE_ITEM_TYPE		nItemType;			//�ڵ����ͣ��ο�TREE_ITEM_TYPE
	long				lItemParam;			//�ڵ�����
	long				lReserve;			//��������
}TREE_ITEM_DATA;

typedef struct 
{
	int						nID;					//id
	DWORD					dwTreeItem;				//�豸��λ��
	char					szName[MAXNAMESIZE];	//����
}ORG_MSG_INFO;

//��Ϣ
typedef struct _INFO_TYPE
{
	INFO_EVENT				infoType;				//��Ϣ����
	long					lParam;					// Ԥ����.
}INFO_TYPE;

//��֯�ṹ���
typedef struct _ORG_CTRL
{
	ORG_EVENT				event;
	ORG_MSG_INFO			orgInfo;
}ORG_CTRL;

typedef struct 
{
	long lDevID;
	int nChannelNo;
	long lReserve;
}ALARM_LINK_CHANNEL, DECODER_LINK_CHANNEL;
typedef std::vector<ALARM_LINK_CHANNEL> VectorPort;

typedef struct 
{
	long			lDevID;
	int				nPort;
	VectorPort	vecPortPlan;
}ALARM_LINK_PORT,DECODER_LINK_PORT;

typedef CList<ALARM_LINK_PORT, ALARM_LINK_PORT> LIST_LINK_PLAN;

//��־�¼�������
typedef enum
{
	EN_EVENT_TYP_INFORMATION,	//��Ϣ
		EN_EVENT_TYP_WARNING,		//�澯
		EN_EVENT_TYP_ERROR,			//����
}EN_EVENT_TYP;


//¼���ѯ����
typedef enum 
{
	SEARCH_RECORD_COMMON = 0,
	SEARCH_RECORD_ALARM = 1,
	SEARCH_RECORD_MOTION = 2,
	SEARCH_RECORD_HAND = 0x03,		///< �ֶ�¼��
	SEARCH_RECORD_SNAP = 0x04,		///< ץͼ
}ERECORD_SEARCH_TYPE;





//XML�����̷��ṹ
typedef struct {
	char				Drives[4];
	int					bType;
	char				XMLPath[MAXPATH];
}DRIVES_XML;

//XML����ṹ
typedef struct {
	long				lID;				//��¼ID��
	VIDEONET_TIME			begintime;			//��ʼʱ��
	VIDEONET_TIME			endtime;			//����ʱ��
	char				path[MAXPATH];		//�ļ�·��
}XML_MANAGER;

//XML����ṹ
typedef struct {
	long				lDevID;				//�豸ID
	int					nChnlNo;			//ͨ����
	char				path[MAXPATH];		//�ļ�·��
}CHNL_XML_MANAGER;

//�ļ���Ϣ�ṹ
typedef struct  {
	long	lID;			//��¼ID��
	char Drive[4];			//�̷�
	VIDEONET_TIME begintime;			//��ʼʱ��
	VIDEONET_TIME endtime;			//����ʱ��
	long devID;				//�豸ID
	int nChannelNo;			//ͨ����
	long size;				//��ǰ�ļ���С
	char path[MAXPATH];		//�ļ�·��
	char type;				//�ļ����� RECORD_TYPE
}FILE_RECORD;


//�ͻ���¼����Ϣ�ṹ
typedef struct{
	DEVICE_INFO DeviceInfo;
	FILE_RECORD fileRecord;
}LOCALREC_FILE;

//¼��ͨ���ṹ
typedef struct {	// ��ʱʱ��
	BYTE				StartHour;
	BYTE				StartMin;
	BYTE				StartSec;
	BYTE				EndHour;
	BYTE				EndMin;
	BYTE				EndSec;
	BYTE				State;						//�ڶ�λ�Ƕ�ʱ������λ�Ƕ�̬��⣬����λ�Ǳ���
	BYTE				Reserve;
} TSECT;
typedef struct {
	TSECT				Sector[7][N_TSECT];			//��ʱʱ��7
	BYTE				PreRecord;					//Ԥ¼���أ�ʱ�䣩
	BYTE				Reserved[3];
} CONFIG_RECORD;


//�Զ�¼��ṹ
typedef struct _PSS_RECORD_CONFIG
{
	long				lChannelID;
	int					nChannlNo;
	long				lDevID;
	CONFIG_RECORD		RecordTime;					//ʱ��ṹ
}PSS_RECORD_CONFIG;
//�Զ�¼��ṹ
typedef struct _PSS_HDD_CONFIG
{
	char				szBeginPartition[4];		// ��һ���̷�.
	char				szEndPartition[4];			// ���һ���̷�.
	long				lFileSize;					//�ļ���С
	long				lAlarmSize;					//�����ļ���С
	long				lModSize;					//��̬����ļ���С
	BOOL				bAutoReocrd;				//�Զ�¼��
	BOOL				bOverMode;					//�Զ�����
}PSS_HDD_CONFIG;
//�Զ�¼��ṹ
typedef struct _RECORD_CONFIG
{
	char				szProjectName[16];			//��������
	CONFIG_RECORD		RecordTime;					//ʱ��ṹ
	long				nFileTime;					// ¼���ļ��������.
	bool				bOverMode;					// �Ƿ�ѭ������.
	bool				bAutoRecord;				//�Ƿ��Զ�¼��
	char				szBeginPartition[4];		// ��һ���̷�.
	char				szEndPartition[4];			// ���һ���̷�.
	long				lFileSize;					//�ļ���С
	long				lAlarmSize;					//�����ļ���С
	long				lModSize;					//��̬����ļ���С
	long				lProjectID;					//����ID
	BOOL				bRun;						//�Ƿ���������
	DWORD				dwTreeItem;
}RECORD_CONFIG,*pRECORD_CONFIG;

typedef struct {
	TSECT	Sector[N_TSECT];		//��ʱʱ��7
	BYTE	PreRecord;				//Ԥ¼���أ�ʱ�䣩
	BYTE	Reserved[3];
} B_CONFIG_RECORD;
//��DVR����¼��ṹ
typedef struct _BACKUP_CONFIG
{
	char				szProjectName[16];			//��������
	long				lProjectID;					//����ID
	char				szBeginPartition[4];		// ��һ���̷�.
	char				szEndPartition[4];			// ���һ���̷�.
	TSECT				Sector[2];					//��ʱʱ��2
	B_CONFIG_RECORD		RecordTime;					//ʱ��ṹ
	BOOL				bRun;						//�Ƿ���������
	DWORD				dwTreeItem;
	long			nDaysBefore;
}BACKUP_CONFIG;
//ʱ��
typedef struct 
{
	DWORD dwYear;		//��
	DWORD dwMonth;		//��
	DWORD dwDay;		//��
	DWORD dwHour;		//ʱ
	DWORD dwMinute;		//��
	DWORD dwSecond;		//��
} NET_TIME;
//����ͨ��¼��
typedef struct _MANUAL_BACKUP_CHANNEL
{
	int                 nFlag;              //1Ϊѡ��Ϊ¼�� 0 Ϊû�б�ѡ�� 2 Ϊ����¼��
	int	 				nChannelNo;			// ͨ����.
	char				szChnnelName[MAXNAMESIZE];	// ͨ������.
	DWORD				dwTreeItem;			//��¼�豸���еĽڵ��������Խ�ʡ�����¼�
	DEVICE_INFO			DeviceInfo;
	int					nRecord;
	int					nSwith;				//��¼��Ҫ�������ǹر�
	char				Drive[4];
	NET_TIME			BeTime;
	NET_TIME			EndTime;
}MANUAL_BACKUP_CHANNEL,*pMANUAL_BACKUP_CHANNEL;
typedef enum _MANUAL_EVENT
{
	START_MANUAL = 0x0,
		STOP_MANUAL,
}MANUAL_EVENT;
typedef struct _MANUAL_BACKUP_CTRL
{
	MANUAL_BACKUP_CHANNEL	ManualInfo;		// ͨ����Ϣ.
	MANUAL_EVENT			ManualEvent;	// ͨ���¼�(״̬����).
	int						nSwith;			// Ҫ��״̬(����).
	long					lParam;			// Ԥ����.
}MANUAL_BACKUP_CTRL,*pMANUAL_BACKUP_CTRL;
typedef enum _PROJECT_EVENT
{
	PEVENT_REALTIME,
	PEVENT_BACKUP,
}PROJECT_EVENT;

//����ͨ��¼��
typedef struct _CHANNEL_INFO_RECORD
{
	int                 nFlag;						//1Ϊѡ��Ϊ¼�� 0 Ϊû�б�ѡ�� 2 Ϊ����¼��
	int					nChnnID;					// ���ڵ�ͼ�ڵ����
	int	 				nChannelNo;					// ͨ����.
	char				szChnnelName[MAXNAMESIZE];	// ͨ������.
	DWORD				dwTreeItem;					//��¼�豸���еĽڵ��������Խ�ʡ�����¼�
	DEVICE_INFO			DeviceInfo;
}CHANNEL_INFO_RECORD;

//// ����������
//typedef struct _DECODER_INFO_
//{
//	char szHostAddr[MAXNAMESIZE];
//	char szUserName[MAX_USERNAME_LENGTH];
//	char szPassword[MAX_USER_PSW];
//	int  nPort;
//	char szDesc[MAX_PSW_LENGTH];
//}DECODER_INFO,Decoder_Info,*pDECODER_INFO;

typedef enum
{
	TOUR_STOP = 0,
	TOUR_START,
	TOUR_FAIL,
};

// ��Ѳ����
typedef struct _VIDEO_TOUR_NODE_
{
	int nDevID;     //�豸ID
	int nChannel;   //ͨ����
	int nInterval;  //���ʱ��
	int nStatus;    //0:ֹͣ��Ѳ  1;������Ѳ 2:������Ѳʧ��
	int nVWndID;    //ԭ������ʲô״̬���ǿ������ǹر�
	int nStream;
}VIDEO_TOUR_NODE,*pVIDEO_TOUR_NODE;

// ��������Ѳ����
typedef struct _DECODER_TOUR_NODE_
{
	int nLayoutID;
	CHANNEL_INFO chanInfo;

}DECODER_TOUR_NODE;
typedef std::vector<VIDEO_TOUR_NODE> VectorTourNode;
typedef std::vector<DECODER_TOUR_NODE> VectorDecoderTourNode;

typedef struct _VIDEO_TOUR_PLAN_
{
	int nPlanID;
	CString strName;
	int nIndex;
	VectorTourNode TourNodes;
}VIDEO_TOUR_PLAN,*pVIDEO_TOUR_PLAN;

typedef struct _DECODER_TOUR_PLAN_
{
	int nPlanID;
	CString strName;
	int nIndex;
	int nInterval;
	VectorDecoderTourNode TourNodes;
}DECODER_TOUR_PLAN;

//Task����
enum TASK_STATUS
{
	TASK_STOP = 0,
	TASK_START,
	TASK_FAIL,
};

//Task�ƻ��ڵ�
typedef struct _DEVICE_TASK_NODE_
{
	int nDevID;  //�豸ID
	int nChannel;  //�豸ͨ��
	int nStatus;  //״̬��0Ϊ���ţ�1Ϊֹͣ
	int nStream;  //0Ϊ��������1Ϊ������
	int nRes;  //����������չ
}DEVICE_TASK_NODE, *pDEVICE_TASK_NODE;

typedef std::vector<DEVICE_TASK_NODE> VectorTaskNode;

//Task����
typedef struct _DEVICE_TASK_MAN_
{
	int nTaskID;
	CString strTaskName;
	VectorTaskNode TaskNodes;
}DEVICE_TASK_MAN, *pDEVICE_TASK_MAN;

//////////////////////////////////////////////////////////////////////////
//����ӵ�ͼ�����ݽ����ṹ
#define  MAX_NAME_LEN		128
#define  MAX_FILE_LEN		128
#define  MAX_DESC_LEN		256

enum  ItemType
{
	IMG,			//ͼƬ
	DEV,			//�豸
	CAMERA,			//����ͷ
	ALARMDEV,		//������
};

enum DataType
{
	DATA_DEVICE = 0,	//�豸����	
	DATA_IMAGE	= 1,	//ͼƬ����
	DATA_MAP	= 2,	//��ͼ��Ϣ
	DATA_ALL_DEV,		//�����豸����	

};

enum OperateType
{
	ADD,
	DEL,
	MOD,
};

#define  MAX_WIDTH_NUM		2
#define  MAX_HEIGHT_NUM		48
#define ROOTITEM	0

typedef struct _DEVICEINFO
{
	int		nID;
	int		nType;
	int		nSubType;		//����ͷ��������
	int		nDevId;			//�豸ID
	int		nChnnlNO;		//ͨ����, ��������Ϣ��nType==CAMERAʱ����
	char	szName[MAX_NAME_LEN];
	char	szDesc[MAX_DESC_LEN];
}DEVICEINFO;

//��ͼ���߼�λ������ϵΪ640*480���ڸ���ͼ��ʾʱ��Ҫת��Ϊ����ͼ������ϵ,
//ÿ������С10*10,ÿbit��ʾһ����,�ýṹ��ֻ�е�ͼʹ��
typedef struct _IMAGE_INFO
{
	int		nImageId;
	int     nMainMap;   //����ͼ
	char	szImageName[MAX_NAME_LEN];
	char	szIamgeFile[MAX_FILE_LEN];
	char	szIamgeDesc[MAX_DESC_LEN];	
	int     nArea[MAX_HEIGHT_NUM][MAX_WIDTH_NUM];
}IMAGE_INFO, *pIMAGE_INFO;

typedef struct _MAPITEM
{
	int nID;
	int nParentID;
	int nType;
	int nxPos;
	int nyPos;
}MAPITEM, *pMAPITEM;

struct ChildItem
{
	int nID;
	int nType;
	int xPos;
	int yPos;
};

struct MAPINFO
{
	int nID;
	std::vector<ChildItem> vectorChild;
};


struct MAP_CHANNEL_INFO
{
	int		nID;
	int		nSubType;
	char	szName[MAX_NAME_LEN];
	char	szDesc[MAX_DESC_LEN];
};

struct MAP_ALARMDEV_INFO
{
	int		nID;
	char	szName[MAX_NAME_LEN];
	char	szDesc[MAX_DESC_LEN];
};
struct MAP_DEVICE_INFO
{
	int		nID;
	char	szName[MAX_NAME_LEN];
	char	szDesc[MAX_DESC_LEN];
	MAP_CHANNEL_INFO* pChannelInfo;
	int		nChannelNum;
	MAP_ALARMDEV_INFO* pAlarmDevInfo;
	int		nAlarmDevNum;
};

typedef enum
{
	NO_BACKUP,				//����Ҫ����
	END_BACKUP,				//�Ѿ��������
	BACK_ING,				//���ڱ���
	NEED_BACKUP,			//��Ҫ��������
	PAUSE_BACKUP,			//��ͣ����
	FIRST_BACKUP = 8,		//��һ�α���
	
	END_MANUALBACK = 10,	//�ֶ����ݽ���
	MANUALBACK_ING,
	NEED_MANUALBACK,
	FIRST_MANUALBACK,
	PAUSE_MANUALBACK,		//��ͣ�ֶ�����
}BACKUP_OPERATE;

typedef enum 
{		
	R_MONITOR = 0,				//ʵʱ����
	R_PLAY_BACK,				//�طŵ�ԪȨ��	
	R_BACKUP,					//ʵʱ����
	R_REMOTE_CONFIG,			//�豸Զ������
	R_LOG_VIEW,					//��־����
	R_USER_MANAGER, 			//�û�����			
	R_OPERATE_DEV,				//�豸����			
	R_MAPCTRL,					//���ӵ�ͼ
	R_LOCAL_CONFIG,             //�ͻ�������
	R_PTZ,						//��̨
	R_RIGHT_NUM
}R_USER_RIGHTS;

typedef enum 
{		
	PTZ_FALSE = 0,
	PTZ_TRUE,
	PTZ_FORBID,			//PTZȨ�޽���
}PTZ_RESULT;

//��ʱ����
#define   TIME_ZREA  64  //�ݶ�64��ʱ���
typedef struct _CLOCK_DOWNLOAD_INFO_
{
	int nIndex;  //ʱ��α��
	VIDEONET_TIME BeginTime;  //��ʼʱ�䣬ֻ���嵽Min
	VIDEONET_TIME EndTime;  //����ʱ��,ֻ���嵽Hour
}CLOCK_DOWNLOAD_INFO, *pCLOCK_DOWNLOAD_INFO;

typedef struct _TIME_DOWNLOAD_INFO_
{
	char	 szName[MAX_NAME_LEN];
	int nNum;  //ʱ�����
	CLOCK_DOWNLOAD_INFO Info[TIME_ZREA];
}TIME_DOWNLOAD_INFO;

typedef std::vector<TIME_DOWNLOAD_INFO> TIME_INFO_LIST; //ʱ�����Ϣ

//ͨ��ʱ����Ϣ
typedef struct _CHN_TIME_INFO_
{
	int nNum;
	char szName[MAX_NAME_LEN]; //ʱ�䷽��
}CHN_TIME_INFO;

typedef struct _CHN_INFO_
{
	int nType; //0Ϊ¼��1ΪͼƬ��2Ϊ����
	CHN_TIME_INFO TimeInfo;
	VIDEONET_TIME BeginTime;  //֮ǰ�Ѿ����ص��ļ���ʼ
}CHN_INFO, *pCHN_INFO;
typedef std::map<int, CHN_INFO> MAP_CHN_INFO;  //ͨ��ʱ�����Ϣ

typedef enum KaiCongLink
{
	KAICONG_LINK_CFG,
		KAICONG_RECORD_CFG,
		KAICONG_ALARM_CFG,
		KAICONG_SYS_CFG,
		KAICONG_MAN_TOOL_CFG,
		KAICONG_SYS_INFO_CFG,
		KAICONG_TECHNOLOGY_LOGO,
		KAICONG_ALARM_LOG,
		KAICONG_CFG_MANAGER,
		KAICONG_PLAYBACK
};
typedef enum KaiCongCfgType
{
		KAICONG_TECHNOLOGY_LOGO_LINK=65531,
		KAICONG_SYS_INFO_CFG_LINK,
		KAICONG_MAN_TOOL_CFG_LINK,
		KAICONG_SYS_CFG_LINK,
		KAICONG_ALARM_CFG_LINK,
		KAICONG_RECORD_CFG_LINK,	
};
//////////////////////////////////////////////////////////////////////////
//�����Ƿ�����Ϣ
#define RET_SUCCESS						1		//���سɹ�
#define RET_LOGINED						2		//����ע��ɹ�

//������ʾ�궨��
#define EXCEPTION_ERROR       			-1        //�쳣����,��Դ����ʧ�ܵ� 
#define WAITTIME_OUT          			-2        //�ȴ���ʱ
#define CONNECTCENTER_FAILED  			-3	      //���ӿ�������ʧ��
#define NO_RIGHT              			-4        //û��Ȩ��
#define CONNECTTS_FAILED      			-5        //����ת��������ʧ��
#define CONNECTDEVC_FAILED    			-6        //(ת��������)�����豸ʧ��
#define INVALID_TS            			-7        //��Ч��ת����������ת��������û�����������ע������
#define CONNECTCHANNL_FAILED  			-8        //ת��֪ͨͨ������ʧ��
#define SENDDATATOTS_FAILED   			-9	      //��������ʧ��(��ת��)
#define SENDDATATOCENTER_FAILED		  	-10	      //��������ʧ��(������)
#define DISCONNECT_DEVICE     			-11       //�豸�Ͽ�(�����Ͽ�,�ֶ�����)
#define OPENFILE_FAILED	      			-12	      //�ļ���ʧ��
#define INVALID_USERPSW       			-13       //��Ч���û�������
#define CENTER_DISCONNECT     			-14	      //���ķ���Ͽ�
#define TS_DISCONNECT	      			-15	      //ת���ѶϿ�

#define  MAX_DECODEWND          36 //���������֧�ִ�����
#define  MAX_PLAYBACK_WND		16 //�ط����֧�ִ�����
#define  MAX_DECODERPREVOEW_WND  8
#define  PLAY_DECODE_INDEX      ( MAX_DECODEWND*MAX_DECODERPREVOEW_WND + MAXWNDTOTAL ) //�طſ�ʼ
#define  HH_MAX_PREVIEWWND_NUM	64

//#define COLOR_DEFAULT_BRIGHT            67
//#define COLOR_DEFAULT_CONTRAST          80
//#define COLOR_DEFAULT_HUE               64
//#define COLOR_DEFAULT_SATURATION        80

#define COLOR_DEFAULT_BRIGHT            64
#define COLOR_DEFAULT_CONTRAST          64
#define COLOR_DEFAULT_HUE               64
#define COLOR_DEFAULT_SATURATION        64
#define SPLIT_DEFAULT_VOLUME            100

#define PLAYBACK_MAX_FILE_NUM           64
#define MAX_PLAYBACK_CHANNEL            16


#define CONFIG_PROTOCOL_ONVIF  65534
#define CONFIG_PROTOCOL_MAC    65535
#define CONFIG_PROTOCOL_NR_V2  65536

#define RGB_REC_NORMAL	RGB(0,255,0)
#define RGB_REC_DETECT  RGB(100,100,100)
#define RGB_REC_ALARM  RGB(255,0,0)
#define RGB_REC_HAND   RGB(0,0,255)
#endif
