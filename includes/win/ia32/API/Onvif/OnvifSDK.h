// OnvifSDK.h : OnvifSDK DLL 的主头文件


#pragma once

//#ifndef __AFXWIN_H__
//	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
//#endif

#include "resource.h"		// 主符号


// COnvifSDKApp
// 有关此类实现的信息，请参阅 OnvifSDK.cpp
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

//=======================接口定义==================
//SDK 初始化
/*****************************************************************************
 函 数 名  : ONVIF_SDK_Init
 功能描述  : SDK初始化
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   : 
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_Init();

//SDK 退出清理
/*****************************************************************************
 函 数 名  : ONVIF_SDK_CleanUp
 功能描述  : 退出SDK
 输入参数  : 无
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   : 
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_CleanUp();

//获得SDK 的版本信息
/*****************************************************************************
 函 数 名  : ONVIF_SDK_GetVersion
 功能描述  : SDK版本信息
 输入参数  : char *pVersion  
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   : 
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetVersion(char *pVersion);

//获取错误号
/*****************************************************************************
 函 数 名  : ONVIF_SDK_GetLastError
 功能描述  : SDK错误码获取
 输入参数  : char *pErrorInfo  错误码信息
             int size          错误码个数
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   : 
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetLastError(char *pErrorInfo,int size);

//设置网络参数
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SetConnectParam(int timeout,int retry);

//设置设备断开连接的回调
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SetDisconnectCB(EZ_SDK_DisconnectCB disconnectCB, int userData);

//登录
// 0:TCP;	1:UDP ; 2:NAT
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_Login(char *devIP,int devPort,char *username, char *password,int sectype,EZ_SDK_DEV_TYPE clientType,int transType,int *error);

//登出
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_Logout(int loginID);

//订阅报警消息
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_AttachAlarm(int loginID);

//退订报警消息
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_DetachAlarm(int loginID);

//设置设备信息的回调函数
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SetAlarmCB(EZ_SDK_AlarmCB alarmCB, int userData);

//读取能力集
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetDevAbility(int loginID,EZ_SDK_ABILITY_TYPE type,int channel,char *outBuffer,int bufferSize,int* getSize);

//读设备配置
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetDevConfig(int loginID,EZ_SDK_CONFIG_TYPE type,int channel,char *outBuffer,int bufferSize,int* getSize);

//写设备配置
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SetDevConfig(int loginID,EZ_SDK_CONFIG_TYPE type,int channel,char *inBuffer,int bufferSize,int timeout);

//设备信息
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_QueryDevInfo(int loginID,EZ_SDK_INFO_TYPE type,int channel,char *outBuffer,int bufferSize,int* getSize);

//日志查询	
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_QueryLog(int loginID,EZ_SDK_LOG_CONDITION condition,EZ_SDK_LOG_INFO *logInfo,int timeout);

//录像查询,  按照文件方式
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_QueryRecordByFile(int loginID,EZ_SDK_RECORD_CONDITION condition,EZ_SDK_RECORD_FILE *recordFile,int bufferSize,int *getSize,int timeout);

//录像查询,  按照时间方式
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_QueryRecordByTime(int loginID,EZ_SDK_RECORD_CONDITION condition, EZ_SDK_RECORD_TIME *recordTime,int timeout);

//设备管理	
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_DevProc(int loginID,EZ_SDK_PROC_TYPE type,char *inBuffer,int bufferSize);

// 磁盘管理	
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StorageManage(int loginID, EZ_SDK_STORAGE_MANAGE *storageManage);

//用户管理
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_UserManage(int loginID, EZ_SDK_USER_MANAGE *userManage);

//强制I  帧
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_ForceIFrame(int loginID,int channel, EZ_SDK_STREAM_TYPE stream);

//云台控制
//param1, param2, param3 根据扩展功能不同意义不同：
//云台方向设置时：param1为水平步长，param2为垂直步长param3为速度
//预置点操作时param1为预置点值
//巡航线路操作时param1为巡航线路值，param2为预置点值(如果有)
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_PTZ_Control(int loginID,int channel,EZ_SDK_PTZ_OP_CODE opCode,int param1, int param2, int param3,int stop);

//===实时监视===
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartRealPlay(int loginID,EZ_SDK_REALPLAY_REQ req,EZ_SDK_RealDataCB realplayCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopRealPlay(int playHandle);

//===下载和回放===
//下载和回放的区别就是在速度控制上以及是否允许丢包。
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartPlayBackByFile(int loginID,EZ_SDK_PLAYBACK_REQ_BY_FILE req,EZ_SDK_RealDataCB playbackCB,EZ_SDK_ProgressCB progressCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartPlayBackByTime(int loginID,EZ_SDK_PLAYBACK_REQ_BY_TIME req,EZ_SDK_RealDataCB playbackCB,EZ_SDK_ProgressCB progressCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopPlayBack(int playHandle);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_CtrlPlayBack(int playHandle,EZ_SDK_PLAYBACK_OP opCode,int param1);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartDownloadByFile(int loginID,EZ_SDK_PLAYBACK_REQ_BY_FILE req,EZ_SDK_RealDataCB playbackCB,EZ_SDK_ProgressCB progressCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartDownloadByTime(int loginID,EZ_SDK_PLAYBACK_REQ_BY_TIME req,EZ_SDK_RealDataCB playbackCB,EZ_SDK_ProgressCB progressCB,int userData);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopDownload(int playHandle);

ONVIFSDK_API int CALL_METHOD ONVIF_SDK_GetDownloadPos(int playHandle);

//===语音对讲===
/*****************************************************************************
 函 数 名  : ONVIF_SDK_StartTalk
 功能描述  : 开启音频
 输入参数  : int loginID               
             EZ_SDK_RealDataCB talkCB  音频回调函数
             int userData              用户数据
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   :
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartTalk(int loginID,EZ_SDK_RealDataCB talkCB,int userData);

/*****************************************************************************
 函 数 名  : ONVIF_SDK_StopTalk
 功能描述  : 关闭音频
 输入参数  : int talkHandle  
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   : 
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopTalk(int talkHandle);	

/*****************************************************************************
 函 数 名  : ONVIF_SDK_SendTalkData
 功能描述  : 发送语音数据
 输入参数  : int talkHandle  音频句柄
             char *buffer    数据BUFFER
             int size        数据大小
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   :
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SendTalkData(int talkHandle,char *buffer,int size);//8K16bit PCM

//===透明串口===
/*****************************************************************************
 函 数 名  : ONVIF_SDK_StartTransCom
 功能描述  : 开启串口传输
 输入参数  : int loginID    设备ID               
             int comNo                     串口号
             EZ_SDK_RealDataCB transComCB  实时监控数据回调
             int userData                  用户数据
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   :
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StartTransCom(int loginID,int comNo,EZ_SDK_RealDataCB transComCB,int userData);

/*****************************************************************************
 函 数 名  : ONVIF_SDK_StopTransCom
 功能描述  : 停止串口传输
 输入参数  : int loginID  设备ID
             int comNo    串口号
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   :
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_StopTransCom(int loginID,int comNo);

/*****************************************************************************
 函 数 名  : ONVIF_SDK_SendTransComData
 功能描述  : 通过串口发送数据
 输入参数  : int loginID   设备登录ID
             int comNo     串口号
             char *buffer  数据BUFFER
             int size      数据大小
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   : 
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SendTransComData(int loginID,int comNo,char *buffer,int size);

//设备搜索
/*****************************************************************************
 函 数 名  : ONVIF_SDK_SearchDevice
 功能描述  : 搜索设备
 输入参数  : EZ_SDK_SEARCH_DEVICE *deviceBuf  设备信息BUFFER
             int bufCount                     设备信息BUFFER 上限
             int *getCount                    已获取的设备信息数
             int timeout                      超时时间
 输出参数  : 无
 返 回 值  : 
 调用函数  : 
 被调函数  : 
 
 修改历史      :
  1.日    期   : 2012年10月20日
    作    者   :
    修改内容   : 新生成函数

*****************************************************************************/
ONVIFSDK_API int CALL_METHOD ONVIF_SDK_SearchDevice(EZ_SDK_SEARCH_DEVICE *deviceBuf,int bufCount,int *getCount,int timeout);

