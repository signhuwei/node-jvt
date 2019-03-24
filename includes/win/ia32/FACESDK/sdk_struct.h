
/******************************************************************************
* 文件名称: sdk_struct.h
* 版本    : V1.0
* 说明	  : 该文件定义人脸抓拍相关结构体
			
* 日    期: 
  最近更新:	 	
* 其他说明: 无
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



//时间: 天
typedef struct _DAY_TIME_S
{
	DWORD			week : 5;							//星期
	DWORD			millisec : 10;						//毫秒: 0 ~ 999
	DWORD			second : 6;							//秒:	0 ~ 59
	DWORD			minute : 6;							//分:   0 ~ 59
	DWORD			hour : 5;							//时:	0 ~ 23
}DAY_TIME_S; 

//时间: 日期
typedef struct _DATE_TIME_S
{
	DWORD			second : 6;							//秒:  0 ~ 59
	DWORD			minute : 6;							//分:  0 ~ 59
	DWORD			hour : 5;							//时:  0 ~ 23
	DWORD			day : 5;							//日:  1 ~ 31
	DWORD			month : 4;							//月:  1 ~ 12
	DWORD			year : 6;							//年:  2000 ~ 2063
}DATE_TIME_S;

//时间: 时间段 
typedef struct _SEG_TIME_S
{
	BYTE			bEnable;							//是否检测
	BYTE			byTask;								//任务
	BYTE			byRes[2];							//备用
	DAY_TIME_S		stBgnTime;							//开始时间
	DAY_TIME_S		stEndTime;							//结束时间
}SEG_TIME_S; 

//布防时间: 周计划时间
typedef struct _SCHWEEK_TIME_S
{
	SEG_TIME_S		stSegTime[7][4];					//0: 星期天，1: 周一，2: 周二
}SCHWEEK_TIME_S;



/***********************************************************************
* 人脸参数结构体	
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
智能分析结构体	
***********************************************************************/
typedef struct _SMART_ANALYSIS_S
{
	SDK_SMART_FACE 		stSmartFace; /*人脸分析接口*/
	SDK_VI_DETECT	stFaceMask;  /*人脸分析区域*/
	
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

