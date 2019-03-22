// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� LOCALRECORD_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// LOCALRECORD_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifndef _LOCALRECORD_H
#define _LOCALRECORD_H

#ifdef LOCALRECORD_EXPORTS
#define LOCALRECORD_API extern "C" __declspec(dllexport)
#else
#define LOCALRECORD_API extern "C" __declspec(dllimport)
#endif
#include "API\\SdkDefine.h"

typedef struct _RECORD_PERIOD_
{	
	int nFlag;   //�����ʾ: bit3: �ⲿ���� bit2: ��Ƶ��� bit1: ��ͨ¼��
	int nStartTime;
	int nEndTime;
}RECORD_PERIOD,*pRECORD_PERIOD;

typedef struct _RECORD_PLAN_
{	
	int nPeriodNum;
	RECORD_PERIOD recPeriod[6];
}RECORD_PLAN,*pRECORD_PLAN;

//�ƻ�¼������
typedef struct _RECORD_PLAN_DATA_
{
	long lLoginID;  //��½���
	long lDevID;    //�豸ID
	char szDevName[64]; //�豸��
	int nChannel;   //ͨ����
	int nAlarmLen;    //����¼�񳤶�,��Ϊ��λ
	int nLen;       //¼�񳤶�:��λ����
	RECORD_PLAN RecordPlan[7]; //¼��ƻ�ʱ���
}RECORD_PLAN_DATA, *lpRECORD_PLAN_DATA;

typedef enum LOCAL_RECORD_MSG
{
	LOCAL_RECORD_REGISTER,
	LOCAL_RECORD_UNREGISTER,
	LOCAL_RECORD_START,
	LOCAL_RECORD_STOP,
	LOCAL_RECORD_LOGINDEV,
	LOCAL_RECORD_LOGOUTDEV,
};

typedef enum LOCAL_RECORD_TYPE
{
	LOCAL_RECORD_NONE = 0,
	LOCAL_RECORD_NORMAL = 1,
	LOCAL_RECORD_DETECT = 2,
	LOCAL_RECORD_ALARM = 3,
};

typedef struct{
	int lLoginID;   //��¼ID��
	int lDevID;     //�豸ID��
	int nPlayHandle; //���ž��
	int nChannel;	//ͨ����
	int nStream;	//0��ʾ��������Ϊ1��ʾ������
	int nMode;		//0��TCP��ʽ,1��UDP��ʽ,2���ಥ��ʽ,3 - RTP��ʽ��4-����Ƶ�ֿ�(TCP)
	int nComType;	//ֻ����ϱ���ͨ����Ч, ��ϱ���ͨ����ƴͼģʽ
}H264_DVR_RECORDINFO,*LPH264_DVR_RECORDINFO;

typedef struct{
	int lLoginID;   //��¼ID��
	int lDevID;     //�豸ID��
	int nChannel;	//ͨ����
	int nStatus;    //¼��״̬
}H264_DVR_RECORDSTATUS,*LPH264_DVR_RECORDSTATUS;

typedef struct
{
	int nPackLen;   //�������
	int nAlarmPack; //����¼��������
	bool bCover;    //0:������ 1:����
	std::vector<int> vDiskList; //�����б�
}DISK_LSIT;

typedef struct _RECORD_ALARMINFO_
{	
	int nDevID;     //�豸ID�� 
	int nChannel;   //ͨ����
	int nEvent;     //��������
	int nStatus;    //״̬: 0: ��ʼ��1: ����
}RECORD_ALARMINFO,*pRECORD_ALARMINFO;

typedef int(__stdcall *fRealDataCallBack) (long lRealHandle, long dwDataType, unsigned char *pBuffer, long lbufsize, long dwUser);
typedef int (CALLBACK *fRecordCallBack)(char* pMsgInfo, DWORD dwMsgType, fRealDataCallBack fDataCallBack, DWORD dwUser);

/*	$Function		:	RecordPlan_Init
==  ===============================================================
==	Description		:	��ʼ��¼��ƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_Init(fRecordCallBack fcallback);

/*	$Function		:	RecordPlan_Init
==  ===============================================================
==	Description		:	��ʼ��¼��ƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_UnInit();

/*	$Function		:	RecordPlan_Start
==  ===============================================================
==	Description		:	�����ƻ�¼��
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/	
LOCALRECORD_API bool RecordPlan_Start();

/*	$Function		:	RecordPlan_Stop
==  ===============================================================
==	Description		:	�رռƻ�¼��
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_Stop();

/*	$Function		:	RecordPlan_InsertPlan
==  ===============================================================
==	Description		:	����¼��ƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_InsertPlan(RECORD_PLAN_DATA *pPlanData);

/*	$Function		:	RecordPlan_InsertPlan
==  ===============================================================
==	Description		:	�޸�¼��ƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_ModPlan(RECORD_PLAN_DATA *pPlanData);

/*	$Function		:	RecordPlan_InsertPlan
==  ===============================================================
==	Description		:	ɾ��¼��ƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_DelPlan(RECORD_PLAN_DATA *pPlanData);

/*	$Function		:	RecordPlan_InitDisk
==  ===============================================================
==	Description		:	ɾ��¼��ƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/

LOCALRECORD_API bool RecordPlan_InitDisk(DISK_LSIT *pDiskList);


/*	$Function		:	RecordPlan_SearchFile
==  ===============================================================
==	Description		:	����¼���ļ�
==	Argument		:	SearchInfo - ��ѯ����
                        pInfo - ���ص��ļ���Ϣ
						nNum - �������ļ���Ϣ����
== 	Return			:	>= 0 - ��õ��ļ���Ϣ����
                        -1 - ��ѯʧ��
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API long RecordPlan_SearchFile(const RECORD_QUERY_PARAM &SearchInfo, H264_DVR_FILE_DATA *pInfo, long nNum);

/*	$Function		:	RecordPlan_AlarmLaunch
==  ===============================================================
==	Description		:	������Ϣ
==	Argument		:	AlarmInfo - ������Ϣ
== 	Return			:	TRUE,FALSE
==	Modification	:	2010-08-12     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_AlarmLaunch(const RECORD_ALARMINFO &AlarmInfo);

LOCALRECORD_API long RecordPlan_FindFileByTime(const RECORD_QUERY_PARAM &SearchInfo, H264_DVR_FILE_DATA *pInfo, long nNum, SDK_SearchByTimeResult *lpFileData);

LOCALRECORD_API long RecordPlan_GetDevIDFromLoginID(long lLoginID);

LOCALRECORD_API bool RecordPlan_CheckRecord(RECORD_TYPE& recordType, long lDevID, int nChannelID);
#endif

