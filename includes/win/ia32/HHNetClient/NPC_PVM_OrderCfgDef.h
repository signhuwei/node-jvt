/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_PVM_OrderCfgDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2013-10-04
 * Description   :  �豸Э��ӿ��������ö���
 *----------------------------------------------------------------------------*/

#ifndef __NPC_PVM_ORDERCFGDEF_H
#define __NPC_PVM_ORDERCFGDEF_H

#include "NPC_TypeDef.h"


//------------------------------------------------------------------------------
//��������
#define NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM						6				//���ʱ�����
#define NPC_D_PVM_CFG_REC_PLAN_TIME_SECT_NUM					6				//¼��ƻ�ʱ�����


//------------------------------------------------------------------------------
//���ù���ID����
#define NPC_D_PVM_CFG_FUNCID_DEV_NAME							1				//�豸���ƣ���ͣʹ�ã�
#define NPC_D_PVM_CFG_FUNCID_DEV_IP								2				//�豸����IP��ַ
#define NPC_D_PVM_CFG_FUNCID_DEV_WIFI							3				//�豸WIFI��Ϣ
#define NPC_D_PVM_CFG_FUNCID_GET_WIFIAP_LIST					4				//��ȡWIFIAP�б�ֻ�л�ȡ���ù��ܣ�
#define NPC_D_PVM_CFG_FUNCID_DEV_CODEC							5				//��������

#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_MOTION_DETECT			6				//�ƶ���ⱨ��
#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_PROBE					7				//̽ͷ���뱨��
#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_BLIND_DETECT				8				//��Ƶ�ڵ����
#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_LOSS_DETECT				9				//��Ƶ��ʧ���
#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_EMAIL                    10				//�����ʼ�����


#define NPC_D_PVM_CFG_FUNCID_DEV_SYS_TIME						20				//�豸ϵͳʱ��
#define NPC_D_PVM_CFG_FUNCID_DEV_INFO							21				//�豸��Ϣ
#define NPC_D_PVM_CFG_FUNCID_CH_NAME							22				//ͨ������
#define NPC_D_PVM_CFG_FUNCID_DEV_SYS_TIME_ZONE                  23				//�豸ϵͳʱ��ʱ��

#define NPC_D_PVM_CFG_FUNCID_CAMERA_PARAM						40				//���������
#define NPC_D_PVM_CFG_FUNCID_CAMERA_VIDEO_COLOR					41				//�����ͼ����ɫ���ò���

#define NPC_D_PVM_CFG_FUNCID_DEV_RECORD_PLAN					50				//¼��ƻ�����
#define NPC_D_PVM_CFG_FUNCID_ALARM_CLOUD_STORAGE				51				//�����ƴ洢����

#define NPC_D_PVM_CFG_FUNCID_STORAGE_QUERY_SIZE					60				//��ѯ�洢������ֻ�л�ȡ���ù��ܣ�
#define NPC_D_PVM_CFG_FUNCID_STORAGE_FORMAT						61				//��ʽ���洢����ֻ���������ù��ܣ�

#define NPC_D_PVM_CFG_FUNCID_DEV_AVENC_VIDEOWIDGET              71				//��Ƶͨ������ʱ����ʾ����

#define NPC_D_PVM_CFG_FUNCID_DEV_LOCK_CONTROL_1                 81				//��������1
#define NPC_D_PVM_CFG_FUNCID_DEV_LOCK_CONTROL_2                 82				//��������2

//------------------------------------------------------------------------------
//�豸����
typedef struct _NPC_S_PVM_IMD_CFG_DEV_NAME
{
	NPC_CHAR									sDevName[64];					//�豸����

} NPC_S_PVM_IMD_CFG_DEV_NAME, *PNPC_S_PVM_IMD_CFG_DEV_NAME;

//�豸����IP��ַ
typedef struct _NPC_S_PVM_IMD_CFG_DEV_IP
{
	NPC_CHAR									sNetcardName[32];				//��������
	NPC_CHAR									sMac[32];						//����MAC��ַ����ʽΪXX-XX-

	NPC_BOOL									bDhcpEnable;					//DHCPʹ��
	NPC_CHAR									sIpaddr[16];					//IP��ַ
	NPC_CHAR									sNetmask[16];					//��������
	NPC_CHAR									sGateway[16];					//���ص�ַ

} NPC_S_PVM_IMD_CFG_DEV_IP, *PNPC_S_PVM_IMD_CFG_DEV_IP;

//�豸WIFI��Ϣ
typedef struct _NPC_S_PVM_IMD_CFG_DEV_WIFI
{
	NPC_CHAR									sNetcardName[32];				//�������ƣ���ѡ��
	NPC_CHAR									sMac[32];						//����MAC��ַ����ѡ��Ϊ�գ���ΪĬ��WIFI����������ʽΪXX-XX-

	NPC_BOOL									bEnable;						//�Ƿ����ã����

	NPC_CHAR									sWifiSSID[32];					//WIFI SSID�����
	NPC_CHAR									sWifiPwd[32];					//WIFI���루���

	NPC_BOOL									bFieldEnable_AuthType;			//�ֶ�ʹ�ܣ���ȫ���ͣ�TRUE��ʾsAuthType�ֶ���Ч��������Ч����ͬ
	NPC_BOOL									bFieldEnable_EncrypType;		//�ֶ�ʹ�ܣ���������
	NPC_BOOL									bFieldEnable_Channel;			//�ֶ�ʹ�ܣ��ŵ���
	NPC_BOOL									bFieldEnable_RSSI;				//�ֶ�ʹ�ܣ��ź�ǿ��

	NPC_CHAR									sAuthType[32];					//��ȫ���ͣ���ѡ��
	NPC_CHAR									sEncrypType[32];				//�������ͣ���ѡ��
	NPC_INT										iChannel;						//�ŵ��ţ���ѡ��
	NPC_INT										iRSSI;							//�ź�ǿ�ȣ���ѡ����ֵ��ΧΪ0~100��0Ϊ�ź���ͣ�100Ϊ�ź���ǿ

	NPC_BOOL									bIfSetNetParam;					//�Ƿ�������������������TRUE�����ã����²�����Ч��FALSE�������ã�����ԭ�������
	NPC_BOOL									bDhcpEnable;					//DHCPʹ�ܣ���ѡ��
	NPC_CHAR									sIpaddr[16];					//IP��ַ����ѡ��
	NPC_CHAR									sNetmask[16];					//�������루��ѡ��
	NPC_CHAR									sGateway[16];					//���ص�ַ����ѡ��

} NPC_S_PVM_IMD_CFG_DEV_WIFI, *PNPC_S_PVM_IMD_CFG_DEV_WIFI;


//������������
typedef struct _NPC_S_PVM_IMD_CFG_DEV_NETWORK_EMAIL
{
    NPC_CHAR												sEMailServerName[128];			//�ʼ���������
    NPC_CHAR												sUserName[128];			//�����¼�˺�
    NPC_CHAR												sUserPwd[128];			//�����¼����
    NPC_BOOL												bAanonymity;				//HTTP�˿ں�
    NPC_INT													iPort;                  //smtp�˿�
    NPC_CHAR												sReceiverEMail[128];    //�ռ�������
    NPC_CHAR												sSendEMail[128];       //�ռ�������
    NPC_CHAR												sTitle[128];            //��������
    struct _ScheduleTime{
        NPC_BOOL										bIfEnable;				//�Ƿ�����
        NPC_S_TD_TIME									tBeginTime;				//��ʼʱ��
        NPC_S_TD_TIME									tEndTime;				//����ʱ��
    } sScheduleTime[2];
    NPC_BOOL                                                bEnableSSL;
    NPC_BOOL                                                bEnable;
    
} NPC_S_PVM_IMD_CFG_DEV_NETWORK_EMAIL, *PNPC_S_PVM_IMD_CFG_DEV_NETWORK_EMAIL;

//widget����
typedef struct _NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE
{
    NPC_CHAR    sBackColor[32];                                 //���ⱳ����ɫ,0x80000000
    NPC_BOOL    bIfEncodeBlend;                                 //�Ƿ���������ʾ
    NPC_CHAR    sFrontColor[32];                                //������ɫ,0xf0ffffff
    NPC_BOOL    bIfPreviewBlend;                                //ȱʡ:true
    NPC_INT     tRelativePos[4];
} NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE, *PNPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE;

//������Ϣ��AVEnc.VideoWidget
typedef struct _NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_TABLE
{
    NPC_INT                                                 iChannelNum;                //ͨ����
    
    struct _VideoWidget{
        
        struct _ChannelTitle{
            NPC_CHAR    sName[128];     //ͨ������
            NPC_CHAR    sSerialNo[128]; //ͨ�����
        } tChannelTitle;                //ͨ������ṹ��
        
        NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE   tChannelTitleAttribute;     //ͨ����������
        NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE   tCovers[8];                 //covers
        NPC_INT                                         iCoversNum;                 //covers��,0
        NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE   tTimeTitleAttribute;        //ͨ����������
        
    }tVideoWidget[64];                          //ͨ����ʱ�������Ϣ
    
} NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_TABLE, *PNPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_TABLE;


//��ȡWIFIAP�б��ýṹ��֮��ΪNPC_S_PVM_IMD_WIFIAP_INFO����
typedef struct _NPC_S_PVM_IMD_CFG_GET_WIFIAP_LIST
{
	NPC_INT										iWifiApNum;						//WIFIAP��

} NPC_S_PVM_IMD_CFG_GET_WIFIAP_LIST, *PNPC_S_PVM_IMD_CFG_GET_WIFIAP_LIST;

//WIFIAP��Ϣ
typedef struct _NPC_S_PVM_IMD_CFG_WIFIAP_INFO
{
	NPC_CHAR									sSSID[32];						//SSID�����
	NPC_CHAR									sAuthType[32];					//��ȫ���ͣ���ѡ��
	NPC_CHAR									sEncrypType[32];				//�������ͣ���ѡ��
	NPC_INT										iChannel;						//�ŵ��ţ���ѡ��
	NPC_INT										iRSSI;							//�ź�ǿ�ȣ���ѡ����ֵ��ΧΪ0~100��0Ϊ�ź���ͣ�100Ϊ�ź���ǿ

} NPC_S_PVM_IMD_CFG_WIFIAP_INFO, *PNPC_S_PVM_IMD_CFG_WIFIAP_INFO;

//������Ϣ
typedef struct _NPC_S_PVM_IMD_CFG_CODEC_INFO
{
	NPC_BOOL									bVideoEnable;					//�Ƿ�������Ƶ
	NPC_BOOL									bAudioEnable;					//�Ƿ�������Ƶ

	struct _VideoFormat
	{
		NPC_INT									iCodecId;						//��Ƶ����ID���μ�NPC_D_MON_CSD_CODEC_ID_VEDIO_*����
		NPC_INT									iResolution;					//�ֱ��ʣ��μ�NPC_D_MON_CSD_VEDIO_RESOLUTION_*����
		NPC_INT									iBitRateControl;				//��������ģʽ���μ�NPC_D_MON_CSD_BITRATECTRL_*���壬�磺"CBR"�̶�������"VBR"�ɱ�������"MBR"�������
		NPC_INT									iBitRate;						//��Ƶ������kbps��
		NPC_INT									iFrameRate;						//��Ƶ֡�ʣ�������ʾ����һ֡������-3��ʾ3��һ֡��ȡֵ��Χ-5~30
		NPC_INT									iGOP;							//I֡���
		NPC_INT									iQuality;						//ͼ��������ֻ���ڿɱ������²������ã�ȡֵ1-6��ֵԽ��ͼ������Խ��

	} tVideoFormat;

	struct _AudioFormat
	{
		NPC_INT									iCodecId;						//��Ƶ����ID���μ�NPC_D_MON_CSD_CODEC_ID_AUDIO_*����
		NPC_INT									iBitRate;						//�����ʣ�kbps��
		NPC_INT									iSampleRate;					//������
		NPC_INT									iMaxVolume;						//�������

	} tAudioFormat;

} NPC_S_PVM_IMD_CFG_CODEC_INFO, *PNPC_S_PVM_IMD_CFG_CODEC_INFO;

//�豸��������
typedef struct _NPC_S_PVM_IMD_CFG_DEV_CODEC
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��

	NPC_INT										iCodecNum;						//������
	NPC_S_PVM_IMD_CFG_CODEC_INFO				tCodecInfo[5];					//������Ϣ����һ��Ϊ���������ڶ���Ϊ������1��������Ϊ������2���������

} NPC_S_PVM_IMD_CFG_DEV_CODEC, *PNPC_S_PVM_IMD_CFG_DEV_CODEC;

//�ƶ���ⱨ������
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��
	NPC_BOOL									bIfEnable;						//�Ƿ������

	NPC_BOOL									bFuncEnable_Level;				//�����Ƿ���Ч�������ȣ�TRUE�������Ȳ�������Ч��FALSE��Ϊ��Ч����ͬ��
	NPC_BOOL									bFuncEnable_Region;				//�����Ƿ���Ч����������
	NPC_BOOL									bFuncEnable_Photo;				//�����Ƿ���Ч������
	NPC_BOOL									bFuncEnable_Record;				//�����Ƿ���Ч��¼��
	NPC_BOOL									bFuncEnable_AlarmOut;			//�����Ƿ���Ч���������
	NPC_BOOL									bFuncEnable_Beep;				//�����Ƿ���Ч������
	NPC_BOOL									bFuncEnable_WeekSect;			//�����Ƿ���Ч�����ʱ���

	NPC_INT										iLevel;							//������
	NPC_DWORD									dwRegion[32];					//�������飬ÿһλΪһ���㣨0��ʾ����⣬1��ʾҪ��⣬��ߵĵ��ڵ�λ����ÿ��32λΪһ�У���һ��˫�֣�����32�У���32*32�ľ��Σ����Ը���ʵ��ͼ�����ѡ�񲿷ֵ㴦��
	NPC_BOOL									bPhotoEnable;					//����ʹ��
	NPC_BOOL									bRecordEnable;					//¼��ʹ��
	NPC_INT										iRecordDelayedTime;				//¼����ʱʱ�䣨�룩
	NPC_BOOL									bAlarmOutEnable;				//�������ʹ��
	NPC_INT										iAlarmOutDelayedTime;			//���������ʱʱ�䣨�룩
    NPC_BOOL									bBeepEnable;					//����ʹ��
	//���ʱ���
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bIfEnable;						//�Ƿ�����
			NPC_S_TD_TIME						tBeginTime;						//��ʼʱ��
			NPC_S_TD_TIME						tEndTime;						//����ʱ��
		} tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
	} tWeekSect[7];
    NPC_BOOL									bEmailEnable;					//�ʼ�֪ͨ
    NPC_CHAR									sRegion[32][32];				//�������飬ÿһλΪһ���㣨0��ʾ����⣬1��ʾҪ��⣬��ߵĵ��ڵ�λ����ÿ��32λΪһ�У���һ��˫�֣�����32�У���32*32�ľ��Σ����Ը���ʵ��ͼ�����ѡ�񲿷ֵ㴦��

} NPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT;


//�ƶ���ⱨ������
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT_UMSP
{
    NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��
    NPC_BOOL									bIfEnable;						//�Ƿ������
    
    NPC_BOOL									bFuncEnable_Level;				//�����Ƿ���Ч�������ȣ�TRUE�������Ȳ�������Ч��FALSE��Ϊ��Ч����ͬ��
    NPC_BOOL									bFuncEnable_Region;				//�����Ƿ���Ч����������
    NPC_BOOL									bFuncEnable_Photo;				//�����Ƿ���Ч������
    NPC_BOOL									bFuncEnable_Record;				//�����Ƿ���Ч��¼��
    NPC_BOOL									bFuncEnable_AlarmOut;			//�����Ƿ���Ч���������
    NPC_BOOL									bFuncEnable_Beep;				//�����Ƿ���Ч������
    NPC_BOOL									bFuncEnable_WeekSect;			//�����Ƿ���Ч�����ʱ���
    
    NPC_INT										iLevel;							//������
    NPC_DWORD									dwRegion[32];					//�������飬ÿһλΪһ���㣨0��ʾ����⣬1��ʾҪ��⣬��ߵĵ��ڵ�λ����ÿ��32λΪһ�У���һ��˫�֣�����32�У���32*32�ľ��Σ����Ը���ʵ��ͼ�����ѡ�񲿷ֵ㴦��
    NPC_BOOL									bPhotoEnable;					//����ʹ��
    NPC_BOOL									bRecordEnable;					//¼��ʹ��
    NPC_INT										iRecordDelayedTime;				//¼����ʱʱ�䣨�룩
    NPC_BOOL									bAlarmOutEnable;				//�������ʹ��
    NPC_INT										iAlarmOutDelayedTime;			//���������ʱʱ�䣨�룩
    NPC_BOOL									bBeepEnable;					//����ʹ��
    
    //���ʱ���
    struct _WeekSect{
        struct _TimeSect{
            NPC_BOOL							bIfEnable;						//�Ƿ�����
            NPC_S_TD_TIME						tBeginTime;						//��ʼʱ��
            NPC_S_TD_TIME						tEndTime;						//����ʱ��
        } tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
    } tWeekSect[7];
    
} NPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT_UMSP, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT_UMSP;

//̽ͷ���뱨������
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_PROBE
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��
	NPC_BOOL									bIfEnable;						//�Ƿ������

	NPC_BOOL									bFuncEnable_SensorType;			//�����Ƿ���Ч�����������ͣ�TRUE�����������Ͳ�������Ч��FALSE��Ϊ��Ч����ͬ��
	NPC_BOOL									bFuncEnable_Photo;				//�����Ƿ���Ч������
	NPC_BOOL									bFuncEnable_Record;				//�����Ƿ���Ч��¼��
	NPC_BOOL									bFuncEnable_AlarmOut;			//�����Ƿ���Ч���������
	NPC_BOOL									bFuncEnable_Beep;				//�����Ƿ���Ч������
	NPC_BOOL									bFuncEnable_WeekSect;			//�����Ƿ���Ч�����ʱ���

	NPC_INT										iSensorType;					//���������ͣ�0�����գ�1������
	NPC_BOOL									bPhotoEnable;					//����ʹ��
	NPC_BOOL									bRecordEnable;					//¼��ʹ��
	NPC_INT										iRecordDelayedTime;				//¼����ʱʱ�䣨�룩
	NPC_BOOL									bAlarmOutEnable;				//�������ʹ��
	NPC_INT										iAlarmOutDelayedTime;			//���������ʱʱ�䣨�룩
	NPC_BOOL									bBeepEnable;					//����ʹ��

	//���ʱ���
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bIfEnable;						//�Ƿ�����
			NPC_S_TD_TIME						tBeginTime;						//��ʼʱ��
			NPC_S_TD_TIME						tEndTime;						//����ʱ��
		} tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
	} tWeekSect[7];

} NPC_S_PVM_IMD_CFG_DEV_ALARM_PROBE, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_PROBE;

//��Ƶ�ڵ�������
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_BLIND_DETECT
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��
	NPC_BOOL									bIfEnable;						//�Ƿ������

	NPC_BOOL									bFuncEnable_Level;				//�����Ƿ���Ч�������ȣ�TRUE�������Ȳ�������Ч��FALSE��Ϊ��Ч����ͬ��
	NPC_BOOL									bFuncEnable_Photo;				//�����Ƿ���Ч������
	NPC_BOOL									bFuncEnable_Record;				//�����Ƿ���Ч��¼��
	NPC_BOOL									bFuncEnable_AlarmOut;			//�����Ƿ���Ч���������
	NPC_BOOL									bFuncEnable_Beep;				//�����Ƿ���Ч������
	NPC_BOOL									bFuncEnable_WeekSect;			//�����Ƿ���Ч�����ʱ���

	NPC_INT										iLevel;							//������
	NPC_BOOL									bPhotoEnable;					//����ʹ��
	NPC_BOOL									bRecordEnable;					//¼��ʹ��
	NPC_INT										iRecordDelayedTime;				//¼����ʱʱ�䣨�룩
	NPC_BOOL									bAlarmOutEnable;				//�������ʹ��
	NPC_INT										iAlarmOutDelayedTime;			//���������ʱʱ�䣨�룩
	NPC_BOOL									bBeepEnable;					//����ʹ��

	//���ʱ���
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bIfEnable;						//�Ƿ�����
			NPC_S_TD_TIME						tBeginTime;						//��ʼʱ��
			NPC_S_TD_TIME						tEndTime;						//����ʱ��
		} tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
	} tWeekSect[7];

} NPC_S_PVM_IMD_CFG_DEV_ALARM_BLIND_DETECT, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_BLIND_DETECT;

//��Ƶ��ʧ������
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_LOSS_DETECT
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��
	NPC_BOOL									bIfEnable;						//�Ƿ������

	NPC_BOOL									bFuncEnable_AlarmOut;			//�����Ƿ���Ч���������
	NPC_BOOL									bFuncEnable_Beep;				//�����Ƿ���Ч������
	NPC_BOOL									bFuncEnable_WeekSect;			//�����Ƿ���Ч�����ʱ���

	NPC_INT										iRecordDelayedTime;				//¼����ʱʱ�䣨�룩
	NPC_BOOL									bAlarmOutEnable;				//�������ʹ��
	NPC_INT										iAlarmOutDelayedTime;			//���������ʱʱ�䣨�룩
	NPC_BOOL									bBeepEnable;					//����ʹ��

	//���ʱ���
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bIfEnable;						//�Ƿ�����
			NPC_S_TD_TIME						tBeginTime;						//��ʼʱ��
			NPC_S_TD_TIME						tEndTime;						//����ʱ��
		} tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
	} tWeekSect[7];

} NPC_S_PVM_IMD_CFG_DEV_ALARM_LOSS_DETECT, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_LOSS_DETECT;


//�豸ϵͳʱ��
typedef struct _NPC_S_PVM_IMD_CFG_DEV_SYS_TIME
{
	NPC_S_TD_DATE_TIME							tDevTime;						//�豸ʱ��

} NPC_S_PVM_IMD_CFG_DEV_SYS_TIME, *PNPC_S_PVM_IMD_CFG_DEV_SYS_TIME;

//�豸��Ϣ
typedef struct _NPC_S_PVM_IMD_CFG_DEV_INFO
{
	NPC_CHAR									sDevType[8];					//�豸����
	NPC_CHAR									sDevVer[36];					//�豸�汾
	NPC_CHAR									sDevModel[32];					//�豸�ͺ�
	NPC_CHAR									sDeviceName[36];				//�豸����
	NPC_CHAR									sMacAddr[32];					//�豸MAC��ַ

	NPC_INT										iVideoChNum;					//��Ƶͨ����
	NPC_INT										iAudioChNum;					//��Ƶͨ����
	NPC_INT										iPtzChNum;						//PTZͨ����
	NPC_INT										iAlarmInputNum;					//����������
	NPC_INT										iAlarmOutputNum;				//���������
	NPC_INT										iDiskNum;						//Ӳ�̸���
	NPC_INT										iSubProtoNum;					//��������
	NPC_BOOL									bIfSupportZeroChannel;			//�Ƿ�֧����ͨ��

} NPC_S_PVM_IMD_CFG_DEV_INFO, *PNPC_S_PVM_IMD_CFG_DEV_INFO;

//ͨ������
typedef struct _NPC_S_PVM_IMD_CFG_CH_NAME
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��
	NPC_CHAR									sChName[64][64];					//ͨ������

} NPC_S_PVM_IMD_CFG_CH_NAME, *PNPC_S_PVM_IMD_CFG_CH_NAME;

//���������
typedef struct _NPC_S_PVM_IMD_CFG_CAMERA_PARAM
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��

	NPC_BOOL									bIfPictureFlip;					//�Ƿ�ͼ��ת

} NPC_S_PVM_IMD_CFG_CAMERA_PARAM, *PNPC_S_PVM_IMD_CFG_CAMERA_PARAM;

//�����ͼ����ɫ���ò���
typedef struct _NPC_S_PVM_IMD_CFG_CAMERA_VIDEO_COLOR
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��

	NPC_INT										iBrightness;					//����
	NPC_INT										iContrast;						//�Աȶ�
	NPC_INT										iGain;							//����
	NPC_INT										iHue;							//ɫ��
	NPC_INT										iSaturation;					//���Ͷ�
	NPC_INT										iWhitebalance;					//��ƽ��

} NPC_S_PVM_IMD_CFG_CAMERA_VIDEO_COLOR, *PNPC_S_PVM_IMD_CFG_CAMERA_VIDEO_COLOR;


//-----------------------------------------------------------------------------------------
//¼��ƻ�����
typedef struct _NPC_S_PVM_IMD_CFG_DEV_RECORD_PLAN
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ������Ч������������Ч��

	NPC_INT										iRecState;						//¼��״̬��0���رգ�1��ʼ��¼��2������¼��

	NPC_INT										iPacketLength;					//ÿ��¼���ļ���¼��ʱ�����Է���Ϊ��λ
	NPC_INT										iPreRecord;						//Ԥ¼ʱ�����룩
	NPC_BOOL									bOpenAudio;						//�Ƿ�����Ƶ¼��
	NPC_INT										iRecStream;						//¼��������0����������1��������

	//��������������¼��״̬Ϊʼ��¼��ʱ��Ч
	NPC_BOOL									bOpenGeneral;					//�Ƿ�������¼�񣨶�ʱ¼��
	NPC_BOOL									bOpenCheckAlarm;				//�Ƿ�����ⱨ��¼���ƶ���������Ƶ�ڵ�����Ƶ��ʧ�ȣ�
	NPC_BOOL									bOpenInputAlarm;				//�Ƿ������뱨��¼��ָ̽ͷ�������ȣ�

	//ʱ��Σ�������¼��ʱ�ò�������Ч��
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bOpenGeneral;					//�Ƿ�������¼�񣨶�ʱ¼��
			NPC_BOOL							bOpenCheckAlarm;				//�Ƿ�����ⱨ��¼���ƶ���������Ƶ�ڵ�����Ƶ��ʧ�ȣ�
			NPC_BOOL							bOpenInputAlarm;				//�Ƿ������뱨��¼��ָ̽ͷ�������ȣ�

			NPC_S_TD_TIME						tBeginTime;						//��ʼʱ��
			NPC_S_TD_TIME						tEndTime;						//����ʱ��
		} tTimeSect[NPC_D_PVM_CFG_REC_PLAN_TIME_SECT_NUM];
	} tWeekSect[7];

} NPC_S_PVM_IMD_CFG_DEV_RECORD_PLAN, *PNPC_S_PVM_IMD_CFG_DEV_RECORD_PLAN;

//�����ƴ洢����
typedef struct _NPC_S_PVM_IMD_CFG_ALARM_CLOUD_STORAGE
{
	NPC_INT										iChNo;							//ͨ���ţ���ѯ������Ϣ��ֻ��ͨ���źͱ���������Ч������������Ч��
	NPC_INT										iAlarmType;						//�������ͣ��μ�NPC_D_MON_CSD_ALARM_EVENT_*����
																				//ֻ�ʺ��ƶ���⡢��Ƶ�ڵ�����Ƶ��ʧ��̽ͷ�����������Ӧ���������屨���ȣ����Ժ������ı������ͣ�

	NPC_BOOL									bOpenAlarmRecord;				//�Ƿ�������¼��
	NPC_INT										iPreRecordTime;					//¼��Ԥ¼ʱ�����룩��ָ¼�Ʊ�������֮ǰ��N���¼��
	NPC_INT										iTotalRecordTime;				//¼��ʱ�����룩

	NPC_BOOL									bOpenAlarmPhotos;				//�Ƿ�����������
	NPC_INT										iPhotosIntervalTime;			//���ռ��ʱ�䣨���룩
	NPC_INT										iPhotosPicNum;					//��������

} NPC_S_PVM_IMD_CFG_ALARM_CLOUD_STORAGE, *PNPC_S_PVM_IMD_CFG_ALARM_CLOUD_STORAGE;


//-----------------------------------------------------------------------------------------
//��ѯ�洢����
typedef struct _NPC_S_PVM_IMD_CFG_STORAGE_QUERY_SIZE
{
	NPC_INT										iStorageNum;					//�洢����
	struct _Storage{
		NPC_INT									iSerialNo;						//���к�
		NPC_DWORD								dwStorageSize;					//�洢��������λΪM��
		NPC_DWORD								dwRemainSize;					//ʣ��ռ䣨��λΪM��
	} tStorage[16];

} NPC_S_PVM_IMD_CFG_STORAGE_QUERY_SIZE, *PNPC_S_PVM_IMD_CFG_STORAGE_QUERY_SIZE;

//��ʽ���洢��
typedef struct _NPC_S_PVM_IMD_CFG_STORAGE_FORMAT
{
	NPC_INT										iSerialNo;						//���кţ����ѯ�洢�����е����к�һ��

} NPC_S_PVM_IMD_CFG_STORAGE_FORMAT, *PNPC_S_PVM_IMD_CFG_STORAGE_FORMAT;



//-----------------------------------------------------------------------------------------
//������ͷ
typedef struct _NPC_S_PVM_IMD_CFG_ABILITY_HEAD
{
	NPC_USHORT									usAbVerNo;						//�������汾��
	NPC_USHORT									usAbDataLen;					//���������ݳ���

} NPC_S_PVM_IMD_CFG_ABILITY_HEAD, *PNPC_S_PVM_IMD_CFG_ABILITY_HEAD;

//�汾һ������������
typedef struct _NPC_S_PVM_IMD_CFG_ABILITY_DATA_V1
{
	struct _Net{
		NPC_BOOL								bIfCableNet;					//�Ƿ�����������
		NPC_BOOL								bIfWifiNet;						//�Ƿ���WIFI����
	} tNet;

	NPC_INT										iCodecSchemeNum;				//���뷽����
	struct _CodecScheme{
		NPC_BOOL								bSupportAudio;					//�Ƿ�֧����Ƶ
		NPC_INT									iStreamNum;						//�����������5��

		struct _SubCh{
			NPC_BYTE							ucVedioCodecTable[4];			//��Ƶ�����б����ֵΪ0��ʾ������ڣ��μ�NPC_D_MON_CSD_CODEC_ID_VEDIO_*����
			NPC_BYTE							ucResolutionTable[16];			//�ֱ����б����ֵΪ0��ʾ������ڣ��μ�NPC_D_MON_CSD_VEDIO_RESOLUTION_*����
			NPC_USHORT							usBitRateStart;					//��Ƶ������Χ��ʼ��kbps��
			NPC_USHORT							usBitRateEnd;					//��Ƶ������Χ������kbps��
			NPC_BYTE							ucFrameRateStart;				//��Ƶ֡�ʷ�Χ��ʼ
			NPC_BYTE							ucFrameRateEnd;					//��Ƶ֡�ʷ�Χ����
			NPC_BYTE							ucGOPStart;						//I֡�����Χ��ʼ
			NPC_BYTE							ucGOPEnd;						//I֡�����Χ����
		} tSubCh[5];															//��ͨ����

		NPC_BYTE								ucUseChTable[32];				//����ͨ����
		NPC_INT									iUseChNum;						//����ͨ����
	} tCodecScheme[8];															//���뷽����

	struct _Alarm{
		NPC_BOOL								bMotionDetect;					//�Ƿ�֧���ƶ����
		NPC_BOOL								bProbeInput;					//�Ƿ�֧��̽ͷ����
		NPC_BOOL								bBlindDetect;					//�Ƿ�֧����Ƶ�ڵ����
		NPC_BOOL								bLossDetect;					//�Ƿ�֧����Ƶ��ʧ���
	} tAlarm;

} NPC_S_PVM_IMD_CFG_ABILITY_DATA_V1, *PNPC_S_PVM_IMD_CFG_ABILITY_DATA_V1;



#endif




