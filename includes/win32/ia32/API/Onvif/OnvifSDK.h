// OnvifSDK.h : OnvifSDK DLL ����ͷ�ļ�


#pragma once

//#ifndef __AFXWIN_H__
//	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
//#endif

#include "resource.h"		// ������


// COnvifSDKApp
// �йش���ʵ�ֵ���Ϣ������� OnvifSDK.cpp
//
#ifdef WIN32

#ifdef ONVIFSDK_EXPORTS
#define ONVIFSDK_API  __declspec(dllexport) 
#else
#define ONVIFSDK_API  __declspec(dllimport)
#endif

#define CALLBACK __stdcall
#define CALL_METHOD  __stdcall  //__cdecl

#else	//linux

#define CMS_CLIENT_API	extern "C"
#define CALL_METHOD
#define CALLBACK

#define NULL	0
#define HWND	void*
#define DWORD   unsigned long
#define FALSE   0
#define TRUE	1
#define BOOL    bool

#endif


#include "ez_sdk_def.h"

//=======================�ӿڶ���==================
//SDK ��ʼ��
/*****************************************************************************
 �� �� ��  : ONVIF_SDK_Init
 ��������  : SDK��ʼ��
 �������  : ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   : 
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_Init();

//SDK �˳�����
/*****************************************************************************
 �� �� ��  : ONVIF_SDK_CleanUp
 ��������  : �˳�SDK
 �������  : ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   : 
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_CleanUp();

//���SDK �İ汾��Ϣ
/*****************************************************************************
 �� �� ��  : ONVIF_SDK_GetVersion
 ��������  : SDK�汾��Ϣ
 �������  : char *pVersion  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   : 
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetVersion(char *pVersion);

//��ȡ�����
/*****************************************************************************
 �� �� ��  : ONVIF_SDK_GetLastError
 ��������  : SDK�������ȡ
 �������  : char *pErrorInfo  ��������Ϣ
             int size          ���������
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   : 
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetLastError(char *pErrorInfo,int size);

//�����������
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SetConnectParam(int timeout,int retry);

//�����豸�Ͽ����ӵĻص�
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SetDisconnectCB(EZ_SDK_DisconnectCB disconnectCB, int userData);

//��¼
// 0:TCP;	1:UDP ; 2:NAT
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_Login(char *devIP,int devPort,char *username, char *password,int sectype,EZ_SDK_DEV_TYPE clientType,int transType,int *error);

//�ǳ�
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_Logout(int loginID);

//���ı�����Ϣ
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_AttachAlarm(int loginID);

//�˶�������Ϣ
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_DetachAlarm(int loginID);

//�����豸��Ϣ�Ļص�����
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SetAlarmCB(EZ_SDK_AlarmCB alarmCB, int userData);

//��ȡ������
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetDevAbility(int loginID,EZ_SDK_ABILITY_TYPE type,int channel,char *outBuffer,int bufferSize,int* getSize);

//���豸����
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetDevConfig(int loginID,EZ_SDK_CONFIG_TYPE type,int channel,char *outBuffer,int bufferSize,int* getSize);

//д�豸����
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SetDevConfig(int loginID,EZ_SDK_CONFIG_TYPE type,int channel,char *inBuffer,int bufferSize,int timeout);

//�豸��Ϣ
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_QueryDevInfo(int loginID,EZ_SDK_INFO_TYPE type,int channel,char *outBuffer,int bufferSize,int* getSize);

//��־��ѯ	
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_QueryLog(int loginID,EZ_SDK_LOG_CONDITION condition,EZ_SDK_LOG_INFO *logInfo,int timeout);

//¼���ѯ,  �����ļ���ʽ
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_QueryRecordByFile(int loginID,EZ_SDK_RECORD_CONDITION condition,EZ_SDK_RECORD_FILE *recordFile,int bufferSize,int *getSize,int timeout);

//¼���ѯ,  ����ʱ�䷽ʽ
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_QueryRecordByTime(int loginID,EZ_SDK_RECORD_CONDITION condition, EZ_SDK_RECORD_TIME *recordTime,int timeout);

//�豸����	
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_DevProc(int loginID,EZ_SDK_PROC_TYPE type,char *inBuffer,int bufferSize);

// ���̹���	
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StorageManage(int loginID, EZ_SDK_STORAGE_MANAGE *storageManage);

//�û�����
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_UserManage(int loginID, EZ_SDK_USER_MANAGE *userManage);

//ǿ��I  ֡
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_ForceIFrame(int loginID,int channel, EZ_SDK_STREAM_TYPE stream);

//��̨����
//param1, param2, param3 ������չ���ܲ�ͬ���岻ͬ��
//��̨��������ʱ��param1Ϊˮƽ������param2Ϊ��ֱ����param3Ϊ�ٶ�
//Ԥ�õ����ʱparam1ΪԤ�õ�ֵ
//Ѳ����·����ʱparam1ΪѲ����·ֵ��param2ΪԤ�õ�ֵ(�����)
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_PTZ_Control(int loginID,int channel,EZ_SDK_PTZ_OP_CODE opCode,int param1, int param2, int param3,int stop);

//===ʵʱ����===
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartRealPlay(int loginID,EZ_SDK_REALPLAY_REQ req,EZ_SDK_RealDataCB realplayCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopRealPlay(int playHandle);

//===���غͻط�===
//���غͻطŵ�����������ٶȿ������Լ��Ƿ���������
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartPlayBackByFile(int loginID,EZ_SDK_PLAYBACK_REQ_BY_FILE req,EZ_SDK_RealDataCB playbackCB,EZ_SDK_ProgressCB progressCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartPlayBackByTime(int loginID,EZ_SDK_PLAYBACK_REQ_BY_TIME req,EZ_SDK_RealDataCB playbackCB,EZ_SDK_ProgressCB progressCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopPlayBack(int playHandle);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_CtrlPlayBack(int playHandle,EZ_SDK_PLAYBACK_OP opCode,int param1);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartDownloadByFile(int loginID,EZ_SDK_PLAYBACK_REQ_BY_FILE req,EZ_SDK_RealDataCB playbackCB,EZ_SDK_ProgressCB progressCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartDownloadByTime(int loginID,EZ_SDK_PLAYBACK_REQ_BY_TIME req,EZ_SDK_RealDataCB playbackCB,EZ_SDK_ProgressCB progressCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopDownload(int playHandle);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetDownloadPos(int playHandle);

//===�����Խ�===
/*****************************************************************************
 �� �� ��  : ONVIF_SDK_StartTalk
 ��������  : ������Ƶ
 �������  : int loginID               
             EZ_SDK_RealDataCB talkCB  ��Ƶ�ص�����
             int userData              �û�����
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   :
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartTalk(int loginID,EZ_SDK_RealDataCB talkCB,int userData);

/*****************************************************************************
 �� �� ��  : ONVIF_SDK_StopTalk
 ��������  : �ر���Ƶ
 �������  : int talkHandle  
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   : 
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopTalk(int talkHandle);	

/*****************************************************************************
 �� �� ��  : ONVIF_SDK_SendTalkData
 ��������  : ������������
 �������  : int talkHandle  ��Ƶ���
             char *buffer    ����BUFFER
             int size        ���ݴ�С
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   :
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SendTalkData(int talkHandle,char *buffer,int size);//8K16bit PCM

//===͸������===
/*****************************************************************************
 �� �� ��  : ONVIF_SDK_StartTransCom
 ��������  : �������ڴ���
 �������  : int loginID    �豸ID               
             int comNo                     ���ں�
             EZ_SDK_RealDataCB transComCB  ʵʱ������ݻص�
             int userData                  �û�����
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   :
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartTransCom(int loginID,int comNo,EZ_SDK_RealDataCB transComCB,int userData);

/*****************************************************************************
 �� �� ��  : ONVIF_SDK_StopTransCom
 ��������  : ֹͣ���ڴ���
 �������  : int loginID  �豸ID
             int comNo    ���ں�
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   :
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopTransCom(int loginID,int comNo);

/*****************************************************************************
 �� �� ��  : ONVIF_SDK_SendTransComData
 ��������  : ͨ�����ڷ�������
 �������  : int loginID   �豸��¼ID
             int comNo     ���ں�
             char *buffer  ����BUFFER
             int size      ���ݴ�С
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   : 
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SendTransComData(int loginID,int comNo,char *buffer,int size);

//�豸����
/*****************************************************************************
 �� �� ��  : ONVIF_SDK_SearchDevice
 ��������  : �����豸
 �������  : EZ_SDK_SEARCH_DEVICE *deviceBuf  �豸��ϢBUFFER
             int bufCount                     �豸��ϢBUFFER ����
             int *getCount                    �ѻ�ȡ���豸��Ϣ��
             int timeout                      ��ʱʱ��
 �������  : ��
 �� �� ֵ  : 
 ���ú���  : 
 ��������  : 
 
 �޸���ʷ      :
  1.��    ��   : 2012��10��20��
    ��    ��   :
    �޸�����   : �����ɺ���

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SearchDevice(EZ_SDK_SEARCH_DEVICE *deviceBuf,int bufCount,int *getCount,int timeout);

