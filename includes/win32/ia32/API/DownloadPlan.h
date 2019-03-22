// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DOWNLOADPLAN_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DOWNLOADPLAN_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
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
==	Description		:	��ʼ�����ؼƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_Init(fDownloadCallBack fcallback);

/*	$Function		:	DownloadPlan_Init
==  ===============================================================
==	Description		:	��ʼ�����ؼƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_SetPath(const char* downloadPath);

DOWNLOADPLAN_API bool DownloadPlan_UnInit();

/*	$Function		:	DownloadPlan_Start
==  ===============================================================
==	Description		:	�����ƻ�����
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/	
DOWNLOADPLAN_API bool DownloadPlan_Start();

/*	$Function		:	DownloadPlan_Stop
==  ===============================================================
==	Description		:	�رռƻ�����
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_Stop();

/*	$Function		:	DownloadPlan_InsertPlan
==  ===============================================================
==	Description		:	�������ؼƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_InsertPlan(DOWNLOAD_PLAN_DATA *pPlanData);

/*	$Function		:	DownloadPlan_InsertPlan
==  ===============================================================
==	Description		:	�޸����ؼƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_ModPlan(DOWNLOAD_PLAN_DATA *pPlanData);

/*	$Function		:	DownloadPlan_InsertPlan
==  ===============================================================
==	Description		:	ɾ�����ؼƻ�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     chencb    Create
==  ===============================================================
*/
DOWNLOADPLAN_API bool DownloadPlan_DelPlan(DOWNLOAD_PLAN_DATA *pPlanData);

DOWNLOADPLAN_API long DownloadPlan_GetDevIDFromLoginID(long lLoginID);

DOWNLOADPLAN_API bool DownloadPlan_CheckDownload(DOWNLOAD_FILE_INFO& fileInfo, long lDevID, int nChannelID);
#endif

