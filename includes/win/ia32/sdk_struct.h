
/******************************************************************************
* �ļ�����: sdk_struct.h
* �汾    : V1.0
* ˵��	  : ���ļ���������ץ����ؽṹ��
			
* ��    ��: 
  �������:	 	
* ����˵��: ��
******************************************************************************/

#include "sdk_device_api.h"
//#include "CommDeviceSDK.h"


#ifndef __SDK_STRUCT_H__
#define __SDK_STRUCT_H__

#ifdef __cplusplus
extern "C" {
#endif

#define XM_COMM_BUFF_SIZE     10*1024

#pragma pack(1)



//ʱ��: ��
typedef struct _DAY_TIME_S
{
	DWORD			week : 5;							//����
	DWORD			millisec : 10;						//����: 0 ~ 999
	DWORD			second : 6;							//��:	0 ~ 59
	DWORD			minute : 6;							//��:   0 ~ 59
	DWORD			hour : 5;							//ʱ:	0 ~ 23
}DAY_TIME_S; 

//ʱ��: ����
typedef struct _DATE_TIME_S
{
	DWORD			second : 6;							//��:  0 ~ 59
	DWORD			minute : 6;							//��:  0 ~ 59
	DWORD			hour : 5;							//ʱ:  0 ~ 23
	DWORD			day : 5;							//��:  1 ~ 31
	DWORD			month : 4;							//��:  1 ~ 12
	DWORD			year : 6;							//��:  2000 ~ 2063
}DATE_TIME_S;

//ʱ��: ʱ��� 
typedef struct _SEG_TIME_S
{
	BYTE			bEnable;							//�Ƿ���
	BYTE			byTask;								//����
	BYTE			byRes[2];							//����
	DAY_TIME_S		stBgnTime;							//��ʼʱ��
	DAY_TIME_S		stEndTime;							//����ʱ��
}SEG_TIME_S; 

//����ʱ��: �ܼƻ�ʱ��
typedef struct _SCHWEEK_TIME_S
{
	SEG_TIME_S		stSegTime[7][4];					//0: �����죬1: ��һ��2: �ܶ�
}SCHWEEK_TIME_S;



/***********************************************************************
* ���������ṹ��	
***********************************************************************/


typedef struct _FS_PROTOCOL_S
{
	char szUDPaddr[64];
	DWORD dwUDPport;	
	BYTE nUDPSDKEnable;
	BYTE szRes[3];
	BYTE byRes[64];
}FS_PROTOCOL_S;

typedef struct _PICTURE_HEAD_S		//size = 92
{
	unsigned short headflag;
	unsigned char  tag;
	unsigned char  frametype;
	unsigned char  frameinfo;
	unsigned char  version;
	unsigned short messageid;
	unsigned short  width;
	unsigned short  height;
	unsigned int   ndatasize;
	unsigned int   deviceid;
	unsigned int   channelid;
	unsigned int   streamid;
	unsigned char  filename[64];

}PICTURE_HEAD, *P_PICTURE_HEAD;


/***********************************************************************
���ܷ����ṹ��	
***********************************************************************/
typedef struct _SMART_ANALYSIS_S
{
	SDK_SMART_FACE 		stSmartFace; /*���������ӿ�*/
	SDK_VI_DETECT	stFaceMask;  /*������������*/
	
	SCHWEEK_TIME_S  stFaceSchTime;	//336bytes
	SDK_SMART_VERSION stSmartVersionInfo;
	FS_PROTOCOL_S    stProtocol;

	BYTE		 byRes[512];
} SMART_ANALYSIS_S;




typedef struct _DVRIP_MSG_HEAD_		//size = 20
{
	unsigned char headflag;
	unsigned char version;
	unsigned char reserved1;
	unsigned char reserved2;
	unsigned int  sessionId;
	unsigned int  sequenceNum;
	unsigned char totalPacket;
	unsigned char curPacket;
	unsigned short messageid;
	unsigned int  datalength;
}DVRIP_MSG_HEAD, *PVRIP_MSG_HEAD;


typedef struct _DVRIP_COMM_BUFF_S
{
	DVRIP_MSG_HEAD stCommMsg;
	char		szBuff[XM_COMM_BUFF_SIZE];
}DVRIP_COMM_BUFF, *PDVRIP_COMM_BUFF;


#pragma pack()

#ifdef __cplusplus
}
#endif

#endif  //End  __SDK_STRUCT_H__

