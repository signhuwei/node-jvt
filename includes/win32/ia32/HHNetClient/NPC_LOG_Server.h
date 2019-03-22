/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_LOG_Server.h
 * Version       :  1.1
 * Author        :  CCH
 * DateTime      :  2011-07-24
 * Description   :  NPC系统日志服务模块
 *----------------------------------------------------------------------------*/

#ifndef __NPC_LOG_SERVER_H
#define __NPC_LOG_SERVER_H

#include "NPC_TypeDef.h"

//--------------------------------------------------------------------------------
//导入导出定义
#ifdef _NPC_LOG_EXPORTS
	#define NPC_LOG_API __declspec(dllexport)
#else
	#ifdef _NPC_LOG_IMPORT
		#define NPC_LOG_API __declspec(dllimport)
	#else
		#define NPC_LOG_API
	#endif
#endif


//--------------------------------------------------------------------------------
//常量定义
#define NPC_D_LOG_MAX_LOGINFO_LEN				512					//最大日志信息长度

//--------------------------------------------------------------------------------
//日志类型定义
#define NPC_D_LOGTYPE_SEVERITY							0			//严重
#define NPC_D_LOGTYPE_IMPORTANCE						1			//重要
#define NPC_D_LOGTYPE_GENERAL							2			//一般
#define NPC_D_LOGTYPE_PROMPT							3			//提示信息


//日志消息数据结构
typedef struct _NPC_S_LOG_INFO_DATA
{
	NPC_CHAR							sLogTime[20];				//日志产生的时间 ，格式为：YYYY-MM-DD HH:MM:SS
	NPC_INT								iLogType;					//日志类型，0：严重，1：重要，2：一般，3：提示信息
	NPC_CHAR							sLogInfo[NPC_D_LOG_MAX_LOGINFO_LEN];	//日志信息，以'\0'结束

} NPC_S_LOG_INFO_DATA, *PNPC_S_LOG_INFO_DATA;



//-------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C"
{
#endif

//设置日志目录
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetLogDir(
	IN		PNPC_CHAR						in_pLogDir					//日志目录，如果为NULL，则为.\Log
	);

//设置日志文件名，调用该函数后，将只写一个文件，如果参数为NULL，则取消单个日志文件模式，按目录方式
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetLogFileName(
	IN		PNPC_CHAR						in_pLogFileName				//日志文件名，如果为NULL，则取消单个文件模式
	);

//设置最大日志文件大小（KB），该函数只有调用NPC_F_LOG_SR_SetLogFileName函数之后才有效
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetMaxLogFileSize(
	IN		NPC_DWORD						in_dwMaxFileSize			//最大文件大小（KB），0表示不限制
	);

//设置接收日志的队列参数
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetRecvLogQueue(
	IN		NPC_HANDLE						in_hRecvLogQueue			//接收日志的队列
	);

//设置是否显示日志
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetIfShowLog(
	IN		NPC_BOOL						in_bIfShowLog				//是否显示日志
	);

//设置是否将显示信息写入日志文件
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetIfShowInfoWriteFile(
	IN		NPC_BOOL						in_bIfShowWrite				//是否显示信息写文件
	);

//设置是否使用英文显示日志头
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetIfShowEnglishLogHead(
	IN		NPC_BOOL						in_bIfShowEnglishLogHead	//是否显示英文日志头
	);

//设置是否写日志信息到文件
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetIfWriteLogToFile(
	IN		NPC_BOOL						in_bIfWriteLogToFile		//是否写日志到文件
	);


//-------------------------------------------------------------------------------
//启动日志服务
NPC_LOG_API	NPC_BOOL	NPC_F_LOG_SR_StartLogService(
	IN		NPC_USHORT						in_usLogTcpPort				//日志监听端口号
	);

//停止日志服务
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_StopLogService();


//-------------------------------------------------------------------------------
//启动上传日志客户端
NPC_LOG_API	NPC_BOOL	NPC_F_LOG_SR_StartLogUpClient(
	IN		PNPC_CHAR						in_pLogName,				//日志名称
	IN		PNPC_CHAR						in_pLogObjId,				//日志对象ID
	IN		PNPC_CHAR						in_pUpSrvIpaddr,			//日志上传服务IP地址
	IN		NPC_USHORT						in_usUpSrvPort				//日志上传服务端口号
	);

//停止上传日志客户端
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_StopLogUpClient();


//-------------------------------------------------------------------------------
//写日志
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_WriteLog(
	IN		PNPC_CHAR						in_pLogInfo,				//日志数据
	IN		NPC_INT							in_iLogType=NPC_D_LOGTYPE_GENERAL		//日志类型
	);

//显示信息
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_ShowInfo(
	IN		PNPC_CHAR						in_pInfo					//显示信息
	);


#ifdef __cplusplus
}
#endif


#endif


