// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 LOCALRECORD_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// LOCALRECORD_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
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
	int nFlag;   //掩码表示: bit3: 外部报警 bit2: 视频侦测 bit1: 普通录像
	int nStartTime;
	int nEndTime;
}RECORD_PERIOD,*pRECORD_PERIOD;

typedef struct _RECORD_PLAN_
{	
	int nPeriodNum;
	RECORD_PERIOD recPeriod[6];
}RECORD_PLAN,*pRECORD_PLAN;

//计划录像数据
typedef struct _RECORD_PLAN_DATA_
{
	long lLoginID;  //登陆句柄
	long lDevID;    //设备ID
	char szDevName[64]; //设备名
	int nChannel;   //通道号
	int nAlarmLen;    //报警录像长度,秒为单位
	int nLen;       //录像长度:单位分钟
	RECORD_PLAN RecordPlan[7]; //录像计划时间表
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
	int lLoginID;   //登录ID号
	int lDevID;     //设备ID号
	int nPlayHandle; //播放句柄
	int nChannel;	//通道号
	int nStream;	//0表示主码流，为1表示子码流
	int nMode;		//0：TCP方式,1：UDP方式,2：多播方式,3 - RTP方式，4-音视频分开(TCP)
	int nComType;	//只对组合编码通道有效, 组合编码通道的拼图模式
}H264_DVR_RECORDINFO,*LPH264_DVR_RECORDINFO;

typedef struct{
	int lLoginID;   //登录ID号
	int lDevID;     //设备ID号
	int nChannel;	//通道号
	int nStatus;    //录像状态
}H264_DVR_RECORDSTATUS,*LPH264_DVR_RECORDSTATUS;

typedef struct
{
	int nPackLen;   //打包长度
	int nAlarmPack; //报警录像打包长度
	bool bCover;    //0:不覆盖 1:覆盖
	std::vector<int> vDiskList; //磁盘列表
}DISK_LSIT;

typedef struct _RECORD_ALARMINFO_
{	
	int nDevID;     //设备ID号 
	int nChannel;   //通道号
	int nEvent;     //报警类型
	int nStatus;    //状态: 0: 开始　1: 结束
}RECORD_ALARMINFO,*pRECORD_ALARMINFO;

typedef int(__stdcall *fRealDataCallBack) (long lRealHandle, long dwDataType, unsigned char *pBuffer, long lbufsize, long dwUser);
typedef int (CALLBACK *fRecordCallBack)(char* pMsgInfo, DWORD dwMsgType, fRealDataCallBack fDataCallBack, DWORD dwUser);

/*	$Function		:	RecordPlan_Init
==  ===============================================================
==	Description		:	初始化录像计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_Init(fRecordCallBack fcallback);

/*	$Function		:	RecordPlan_Init
==  ===============================================================
==	Description		:	初始化录像计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_UnInit();

/*	$Function		:	RecordPlan_Start
==  ===============================================================
==	Description		:	开启计划录像
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/	
LOCALRECORD_API bool RecordPlan_Start();

/*	$Function		:	RecordPlan_Stop
==  ===============================================================
==	Description		:	关闭计划录像
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_Stop();

/*	$Function		:	RecordPlan_InsertPlan
==  ===============================================================
==	Description		:	加入录像计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_InsertPlan(RECORD_PLAN_DATA *pPlanData);

/*	$Function		:	RecordPlan_InsertPlan
==  ===============================================================
==	Description		:	修改录像计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_ModPlan(RECORD_PLAN_DATA *pPlanData);

/*	$Function		:	RecordPlan_InsertPlan
==  ===============================================================
==	Description		:	删除录像计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_DelPlan(RECORD_PLAN_DATA *pPlanData);

/*	$Function		:	RecordPlan_InitDisk
==  ===============================================================
==	Description		:	删除录像计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/

LOCALRECORD_API bool RecordPlan_InitDisk(DISK_LSIT *pDiskList);


/*	$Function		:	RecordPlan_SearchFile
==  ===============================================================
==	Description		:	查找录像文件
==	Argument		:	SearchInfo - 查询条件
                        pInfo - 返回的文件信息
						nNum - 最大接受文件信息条数
== 	Return			:	>= 0 - 获得的文件信息条数
                        -1 - 查询失败
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API long RecordPlan_SearchFile(const RECORD_QUERY_PARAM &SearchInfo, H264_DVR_FILE_DATA *pInfo, long nNum);

/*	$Function		:	RecordPlan_AlarmLaunch
==  ===============================================================
==	Description		:	报警信息
==	Argument		:	AlarmInfo - 报警信息
== 	Return			:	TRUE,FALSE
==	Modification	:	2010-08-12     chencb    Create
==  ===============================================================
*/
LOCALRECORD_API bool RecordPlan_AlarmLaunch(const RECORD_ALARMINFO &AlarmInfo);

LOCALRECORD_API long RecordPlan_FindFileByTime(const RECORD_QUERY_PARAM &SearchInfo, H264_DVR_FILE_DATA *pInfo, long nNum, SDK_SearchByTimeResult *lpFileData);

LOCALRECORD_API long RecordPlan_GetDevIDFromLoginID(long lLoginID);

LOCALRECORD_API bool RecordPlan_CheckRecord(RECORD_TYPE& recordType, long lDevID, int nChannelID);
#endif

