/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_LOG_Server.h
 * Version       :  1.1
 * Author        :  CCH
 * DateTime      :  2011-07-24
 * Description   :  NPCϵͳ��־����ģ��
 *----------------------------------------------------------------------------*/

#ifndef __NPC_LOG_SERVER_H
#define __NPC_LOG_SERVER_H

#include "NPC_TypeDef.h"

//--------------------------------------------------------------------------------
//���뵼������
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
//��������
#define NPC_D_LOG_MAX_LOGINFO_LEN				512					//�����־��Ϣ����

//--------------------------------------------------------------------------------
//��־���Ͷ���
#define NPC_D_LOGTYPE_SEVERITY							0			//����
#define NPC_D_LOGTYPE_IMPORTANCE						1			//��Ҫ
#define NPC_D_LOGTYPE_GENERAL							2			//һ��
#define NPC_D_LOGTYPE_PROMPT							3			//��ʾ��Ϣ


//��־��Ϣ���ݽṹ
typedef struct _NPC_S_LOG_INFO_DATA
{
	NPC_CHAR							sLogTime[20];				//��־������ʱ�� ����ʽΪ��YYYY-MM-DD HH:MM:SS
	NPC_INT								iLogType;					//��־���ͣ�0�����أ�1����Ҫ��2��һ�㣬3����ʾ��Ϣ
	NPC_CHAR							sLogInfo[NPC_D_LOG_MAX_LOGINFO_LEN];	//��־��Ϣ����'\0'����

} NPC_S_LOG_INFO_DATA, *PNPC_S_LOG_INFO_DATA;



//-------------------------------------------------------------------------------
#ifdef __cplusplus
extern "C"
{
#endif

//������־Ŀ¼
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetLogDir(
	IN		PNPC_CHAR						in_pLogDir					//��־Ŀ¼�����ΪNULL����Ϊ.\Log
	);

//������־�ļ��������øú����󣬽�ֻдһ���ļ����������ΪNULL����ȡ��������־�ļ�ģʽ����Ŀ¼��ʽ
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetLogFileName(
	IN		PNPC_CHAR						in_pLogFileName				//��־�ļ��������ΪNULL����ȡ�������ļ�ģʽ
	);

//���������־�ļ���С��KB�����ú���ֻ�е���NPC_F_LOG_SR_SetLogFileName����֮�����Ч
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetMaxLogFileSize(
	IN		NPC_DWORD						in_dwMaxFileSize			//����ļ���С��KB����0��ʾ������
	);

//���ý�����־�Ķ��в���
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetRecvLogQueue(
	IN		NPC_HANDLE						in_hRecvLogQueue			//������־�Ķ���
	);

//�����Ƿ���ʾ��־
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetIfShowLog(
	IN		NPC_BOOL						in_bIfShowLog				//�Ƿ���ʾ��־
	);

//�����Ƿ���ʾ��Ϣд����־�ļ�
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetIfShowInfoWriteFile(
	IN		NPC_BOOL						in_bIfShowWrite				//�Ƿ���ʾ��Ϣд�ļ�
	);

//�����Ƿ�ʹ��Ӣ����ʾ��־ͷ
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetIfShowEnglishLogHead(
	IN		NPC_BOOL						in_bIfShowEnglishLogHead	//�Ƿ���ʾӢ����־ͷ
	);

//�����Ƿ�д��־��Ϣ���ļ�
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_SetIfWriteLogToFile(
	IN		NPC_BOOL						in_bIfWriteLogToFile		//�Ƿ�д��־���ļ�
	);


//-------------------------------------------------------------------------------
//������־����
NPC_LOG_API	NPC_BOOL	NPC_F_LOG_SR_StartLogService(
	IN		NPC_USHORT						in_usLogTcpPort				//��־�����˿ں�
	);

//ֹͣ��־����
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_StopLogService();


//-------------------------------------------------------------------------------
//�����ϴ���־�ͻ���
NPC_LOG_API	NPC_BOOL	NPC_F_LOG_SR_StartLogUpClient(
	IN		PNPC_CHAR						in_pLogName,				//��־����
	IN		PNPC_CHAR						in_pLogObjId,				//��־����ID
	IN		PNPC_CHAR						in_pUpSrvIpaddr,			//��־�ϴ�����IP��ַ
	IN		NPC_USHORT						in_usUpSrvPort				//��־�ϴ�����˿ں�
	);

//ֹͣ�ϴ���־�ͻ���
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_StopLogUpClient();


//-------------------------------------------------------------------------------
//д��־
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_WriteLog(
	IN		PNPC_CHAR						in_pLogInfo,				//��־����
	IN		NPC_INT							in_iLogType=NPC_D_LOGTYPE_GENERAL		//��־����
	);

//��ʾ��Ϣ
NPC_LOG_API	NPC_VOID	NPC_F_LOG_SR_ShowInfo(
	IN		PNPC_CHAR						in_pInfo					//��ʾ��Ϣ
	);


#ifdef __cplusplus
}
#endif


#endif


