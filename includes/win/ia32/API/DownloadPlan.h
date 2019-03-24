// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 DOWNLOADPLAN_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// DOWNLOADPLAN_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifndef _DOWNLOADPLAN_H
#define _DOWNLOADPLAN_H

#ifdef DOWNLOADPLAN_EXPORTS
#define DOWNLOADPLAN_API extern "C" __declspec(dllexport)
#else
#define DOWNLOADPLAN_API extern "C" __declspec(dllimport)
#endif
#include "API\\SdkDefine.h"
#include "DownloadPlanDef.h"


typedef int (CALLBACK *fDownloadCallBack)(char* pMsgInfo,DWORD dwMsgType,void* callback,DWORD dwUser);
/*	$Function		:	DownloadPlan_Init
==  ===============================================================
==	Description		:	初始化下载计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_Init(fDownloadCallBack fcallback);

/*	$Function		:	DownloadPlan_Init
==  ===============================================================
==	Description		:	初始化下载计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_SetPath(const char* downloadPath);

DOWNLOADPLAN_API bool DownloadPlan_UnInit();

/*	$Function		:	DownloadPlan_Start
==  ===============================================================
==	Description		:	开启计划下载
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/	
DOWNLOADPLAN_API bool DownloadPlan_Start();

/*	$Function		:	DownloadPlan_Stop
==  ===============================================================
==	Description		:	关闭计划下载
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_Stop();

/*	$Function		:	DownloadPlan_InsertPlan
==  ===============================================================
==	Description		:	加入下载计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_InsertPlan(DOWNLOAD_PLAN_DATA *pPlanData);

/*	$Function		:	DownloadPlan_InsertPlan
==  ===============================================================
==	Description		:	修改下载计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_ModPlan(DOWNLOAD_PLAN_DATA *pPlanData);

/*	$Function		:	DownloadPlan_InsertPlan
==  ===============================================================
==	Description		:	删除下载计划
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_DelPlan(DOWNLOAD_PLAN_DATA *pPlanData);

DOWNLOADPLAN_API long DownloadPlan_GetDevIDFromLoginID(long lLoginID);

DOWNLOADPLAN_API bool DownloadPlan_CheckDownload(DOWNLOAD_FILE_INFO& fileInfo, long lDevID, int nChannelID);
#endif

