/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_Client.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-08
 * Description   :  ��ؿͻ���ͨѶ�ӿڶ��壬�ýӿ�Ϊ�ͻ�������������豸�ṩͨѶ����
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_CLIENT_H
#define __NPC_MPI_MON_CLIENT_H

#include "NPC_TypeDef.h"
#include "NPC_MPI_MON_DataDef.h"
#include "NPC_MPI_MON_Camera.h"


// C++ support
#ifdef __cplusplus
extern "C"
{
#endif


//----------------------------------------------------------------------------------------
//�������������
NPC_MPI_MON_API	NPC_I_MPI_MON_Camera*	NPC_F_MPI_MON_CreateCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId					//[IN]�豸ID
	);

//�����������������
NPC_MPI_MON_API	NPC_I_MPI_MON_Camera*	NPC_F_MPI_MON_CreateCfgCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwVendorId,				//[IN]�豸����
	IN		PNPC_CHAR							in_pUmid,					//[IN]UMID
	IN		PNPC_CHAR							in_pDevUserName,			//[IN]�豸�û���
	IN		PNPC_CHAR							in_pDevPwd					//[IN]�豸����
	);

//�������������
NPC_MPI_MON_API	NPC_VOID	NPC_F_MPI_MON_DestroyCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_I_MPI_MON_Camera*				in_pCamera					//[IN]�����ָ��
	);


//�ײ�汾��Ϣ
NPC_MPI_MON_API		NPC_CHAR	*NPC_F_MPI_MON_CLT_VERSION();
    //----------------------------------------------------------------------------------------
//��ʼ���ͻ��˻���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_InitClientEnv();
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_InitClientLog(IN NPC_BOOL IfShowLog);

//����ʼ���ͻ��˻���
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_UninitClientEnv();

//�����ͻ���ģ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_StartClient(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]������IP��ַ������
	IN		NPC_USHORT							in_usServerPort				//[IN]�������˿ں�
	);

    
//�����ͻ���ģ�飨��չ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_StartClientEx(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]������IP��ַ������
	IN		NPC_USHORT							in_usServerPort,			//[IN]�������˿ں�
	IN		NPC_INT								in_iSaveMode=0				//[IN]����ģʽ��0����������1������
	);

//ֹͣ�ͻ���ģ��
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_StopClient();

//��������״̬
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetNetState(
	IN		NPC_INT								in_iNetConnState			//[IN]��������״̬��0���Ͽ�״̬��1������״̬
	);

//���ÿͻ���ʶ
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetClientFlag(
	IN		NPC_INT								in_iClientFlag				//[IN]�ͻ���ʶ���μ�NPC_D_MON_CLIENT_FLAG_*����
	);

//�����Ƿ��������ָ����ַ�ķ�����������Ҫ������������ȱʡΪFALSE������Ҫ����������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetConnectSpecServer(
	IN		NPC_BOOL							in_bIfConnSpecSrv			//[IN]�Ƿ�����ָ��������
	);

#ifdef _WIN32
//UTF8��GB2312��ת��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CHARSET_Utf8ToGb2312(
	IN		PNPC_CHAR							in_pUtf8Buf,				//[IN]UTF8�������ݻ�����
	IN		NPC_INT								in_iGb2312BufSize,			//[IN]GB2312���ݻ�������С
	OUT		PNPC_CHAR							out_pGb2312Buf				//[OUT]GB2312���ݻ�����
	);

//GB2312��UTF8��ת��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CHARSET_Gb2312ToUtf8(
	IN		PNPC_CHAR							in_pGb2312Buf,				//[IN]GB2312���ݻ�����
	IN		NPC_INT								in_iUtf8BufSize,			//[IN]UTF8���ݻ�������С
	OUT		PNPC_CHAR							out_pUtf8Buf				//[OUT]UTF8���ݻ�����
	);
#endif


//----------------------------------------------------------------------------------------

//������ؿͻ���
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_CreateClient(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]������IP��ַ������
	IN		NPC_USHORT							in_usServerPort,			//[IN]�������˿ںţ���8300
	IN		NPC_INT								in_iSaveMode=0				//[IN]����ģʽ��0����������1������
	);

//���ټ�ؿͻ��˶���
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DestroyClient(
	IN		NPC_HANDLE							in_hMonClient				//[IN]�ͻ��˾��
	);

//�����豸���̱�ʶ���ͻ��˶��Ʊ�ʶ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetVendorClientFlag(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevVendorFlag,			//[IN]�豸���̱�ʶ
	IN		PNPC_CHAR							in_pClientCustomFlag		//[IN]�ͻ��˶��Ʊ�ʶ
	);

//���ӷ�����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ConnectServer(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iTimeout=4000			//[IN]���ӷ������ĳ�ʱʱ�������룩
	);

//�Ͽ�����������
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DisconnectServer(
	IN		NPC_HANDLE							in_hMonClient				//[IN]�ͻ��˾��
	);

//�����ַ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetCharset(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iCharset					//[IN]�ַ������μ�NPC_D_MON_CHARSET_*����
	);

//������־�������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_StartLogNetServer(
	IN		NPC_USHORT							in_usLogListenPort			//[IN]��־�����˿ں�
	);

//ֹͣ��־�������
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_StopLogNetServer();

//������־�ϴ�����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_StartLogUpServer(
	IN		PNPC_CHAR							in_pLogName,				//[IN]��־����
	IN		PNPC_CHAR							in_pLogObjId,				//[IN]��־����ID
	IN		PNPC_CHAR							in_pLogServerAddr,			//[IN]��־������IP��ַ������
	IN		NPC_USHORT							in_usLogServerPort			//[IN]��־�������˿ں�
	);

//ֹͣ��־�ϴ�����
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_StopLogUpServer();

//���÷��ؽ����Ϣ�������࣬ȱʡΪ����
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetMsgLanguage(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iMsgLanguage				//[IN]��Ϣ���������ͣ�0�����ģ�1��Ӣ��
	);

//���õȴ�Ӧ����Ϣ�ĳ�ʱֵ��ȱʡΪ20000����
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetWaitRespTimeout(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iWaitRespTimeout			//[IN]�ȴ�Ӧ����Ϣ�ĳ�ʱֵ�����룩
	);

//����������ȴ�ý�����ĳ�ʱʱ����ȱʡΪ20��
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetWaitMediaStreamTimeout(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iWaitTimeout				//[IN]�ȴ���ʱֵ���룩
	);

//���ü��ֱ���豸�Ƿ����ߵļ��ʱ�䣬ȱʡΪ30�룬�����õ�ֵ��ΧΪ5~3600��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetCheckDevStateIntervalTime(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iIntervalTime			//[IN]�����ʱ�䣨�룩
	);


//----------------------------------------------------------------------------------------
//��ȡ�ͻ������ò�����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetClientConfigTable(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	OUT		PNPC_INT							out_pCfgParamNum,			//[OUT]�ͻ������ò�����
	OUT		PNPC_S_MPI_MON_CLIENT_CONFIG_DATA*	out_ppClientCfgParamTable	//[OUT]�ͻ������ò������ɵײ�����ڴ棬������ʹ����������NPC_F_MPI_MON_CLT_ReleaseClientConfigTable�����ͷ��ڴ�
	);

//�ͷſͻ������ò�����
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ReleaseClientConfigTable(
	IN		PNPC_S_MPI_MON_CLIENT_CONFIG_DATA	in_pClientCfgParamTable		//[IN]�ͻ������ò�����
	);

//��ѯ���°汾
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetNewVerInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iClientType,				//[IN]�ͻ������ͣ��μ�NPC_D_MON_CLIENT_TYPE_����
	IN		PNPC_CHAR							in_pClientCustomFlag,		//[IN]�ͻ��˶��Ʊ�ʶ
	IN		PNPC_CHAR							in_pCurVerNo,				//[IN]��ǰ�汾�ţ���ʽΪ��vA.B.C.D
	OUT		PNPC_CHAR							out_pNewVerNo,				//[OUT]�°汾��
	OUT		PNPC_INT							out_pUpRequire,				//[OUT]����Ҫ��0�����°汾��1�����°汾�����Բ�������2�����°汾���������ſ���ʹ��
	OUT		PNPC_CHAR							out_pFileName,				//[OUT]������װ�ļ���
	OUT		PNPC_INT							out_pFileSize,				//[OUT]�����ļ���С��KB��
	OUT		PNPC_CHAR							out_pUpPromptMsg,			//[OUT]������ʾ��Ϣ
	OUT		PNPC_CHAR							out_pUpDownLinkAddr			//[OUT]����������ص�ַ
	);

//��ȡ�洢��������ַ������TRUE��ʾ�Ѿ���ȡ����FALSE��ʾδ��ȡ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetStorageSrvAddr(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	OUT		PNPC_S_MPI_MON_STORAGE_SRV_ADDR		out_pStorageSrvAddr			//[OUT]�洢��������ַ
	);


//----------------------------------------------------------------------------------------
//��ȡ���Ĵ�����Ϣ�����ش����룬����ֵΪ0��ʾ�ɹ�������Ϊʧ��
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetLastError(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iErrorBufSize,			//[IN]������Ϣ��������С
	OUT		PNPC_CHAR							out_pErrorBuf				//[OUT]������Ϣ�������������߷����ڴ棬���ΪNULL���򲻷��ش�����Ϣ
	);

//��ȡ���Ĵ�����Ϣ�����ش����룬����ֵΪ0��ʾ�ɹ�������Ϊʧ��
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetLastErrorEx(
	IN		NPC_INT								in_iErrorBufSize,			//[IN]������Ϣ��������С
	OUT		PNPC_CHAR							out_pErrorBuf				//[OUT]������Ϣ�������������߷����ڴ棬���ΪNULL���򲻷��ش�����Ϣ
	);

//��ȡ��־�������Ϣ���ײ�ά��һ����־���У�����������־������ö����У����øú������Ӹö���ȡ����־�������ú�����ɾ�����е����ݣ�
//�����ʱ�䲻���ã��ײ㽫ɾ���������־��Ĭ����󱣴�100����־
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetLogData(
	IN		NPC_INT								in_iLogBufSize,				//[IN]��־��Ϣ��������С
	OUT		PNPC_INT							out_pLogInfoType,			//[OUT]��־���ͣ��μ�NPC_D_MON_LOG_INFO_TYPE_*����
	OUT		PNPC_CHAR							out_pLogBuf,				//[OUT]��־��Ϣ�������������߷����ڴ�
	IN		NPC_INT								in_iTimeout					//[IN]��ʱʱ�������룩
	);

//��ȡ��־֪ͨ�¼������������־����ʱ�����¼����ź�
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_GetLogNotifyEvent();

//�����Ƿ�д��־��Ϣ���ļ�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetIfWriteLogToFile(
	IN		NPC_BOOL							in_bIfWriteLogToFile		//[IN]�Ƿ�д��־���ļ�
	);

//������־�ļ�Ŀ¼
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetLogDir(
	IN		PNPC_CHAR							in_pLogDir					//[IN]��־Ŀ¼
	);

//�޸���־���д�С
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetLogQueueSize(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iQueueSize				//[IN]���д�С
	);

//���õ��Կ��أ��������ԣ���ײ㽫����������Ϣ������������־������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetDebugFlag(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_BOOL							in_bEnableDebug				//[IN]ʹ�ܵ��ȣ�TRUE��ʾ������FALSE��ʾ�ر�
	);

//��ȡ�ͻ���״̬��״ֵ̬�μ�NPC_D_MPI_MON_CLIENT_CONN_STATE_*����
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetClientState(
	IN		NPC_HANDLE							in_hMonClient				//[IN]�ͻ��˾��
	);

//��ȡ�ͻ��˶Ͽ�ԭ��ԭ��ֵ�μ�NPC_D_MPI_MON_CLIENT_DISCAUSE_����
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetClientDiscause(
	IN		NPC_HANDLE							in_hMonClient				//[IN]�ͻ��˾��
	);

//��ѯP2P����������״̬��0��δ���ӣ�1���������ӣ�2��������
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_QueryP2pServerConnState(
	IN		NPC_HANDLE							in_hMonClient				//[IN]�ͻ��˾��
	);


//----------------------------------------------------------------------------------------
//ע���ʺ�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Register(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID�����û��ʺ�
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]�û�����
	IN		PNPC_CHAR							in_pClientId				//[IN]�ͻ���ID����ͻ��˱�ʶ����IMSI�ȣ�
	);

//ע���ʺ�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Unregister(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID�����û��ʺ�
	IN		PNPC_CHAR							in_pUserPwd					//[IN]�û�����
	);

//�����Ͷ�����֤�룬���ܵ�ʧ�������£�
//NPC_D_MPI_MON_ERROR_SYS_ERROR
//NPC_D_MPI_MON_ERROR_DBACCESS_FAIL
//NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_NOPERM
//NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_ATBLACK
//NPC_D_MPI_MON_ERROR_ACCOUNT_EXIST
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RequestSendSecurityCode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pMobilePhone,			//[IN]������֤����ֻ�����
	OUT		PNPC_DWORD							out_pCheckId				//[OUT]��֤����ID������֤�룩������ע��ʱʹ�ã���ID��Ч��Ϊ10���ӣ������ã�
	);

//ע���ʺţ�����֤�룩�����ܵ�ʧ�������£�
//NPC_D_MPI_MON_ERROR_SYS_ERROR
//NPC_D_MPI_MON_ERROR_DBACCESS_FAIL
//NPC_D_MPI_MON_ERROR_SECCODE_HAVE_EXPIRED
//NPC_D_MPI_MON_ERROR_SECCODE_ERROR
//NPC_D_MPI_MON_ERROR_ACCOUNT_EXIST
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RegisterBySecurityCode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwCheckId,				//[IN]��֤����ID������֤�룩����NPC_F_MPI_MON_CLT_RequestSendSecurityCode������ȡ������֤����ID
	IN		PNPC_CHAR							in_pSecurityCode,			//[IN]��֤�루�ֻ����յ�����֤�룩
	INOUT	PNPC_CHAR							inout_pUserId,				//[INOUT]�û�ID�����û��ʺţ�����ַ���Ϊ�գ����ɷ����������ʺŲ����أ�����ǿգ�����ø��ֶδ�Ϊ�ʺ�
	INOUT	PNPC_CHAR							inout_pUserPwd,				//[INOUT]�û����룬����ַ���Ϊ�գ����ɷ���������������벢���أ�����ǿգ����������ø��ַ���
	IN		PNPC_CHAR							in_pClientId				//[IN]�ͻ���ID����ͻ��˱�ʶ����IMSI�ȣ�
	);


//----------------------------------------------------------------------------------------
//��������û�ID
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RequestAllocUserId(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pClientId,				//[IN]�ͻ���ID����ͻ��˱�ʶ����IMSI�ȣ���ͬһ���ͻ���ID����һ��ʱ���ڷ�����û�ID��ͬ��
	OUT		PNPC_CHAR							out_pUserId					//[OUT]�û�ID
	);

//ע���ʺţ���չ2���������伤�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RegisterAccountByNoActive(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pClientId,				//[IN]�ͻ���ID����ͻ��˱�ʶ����IMSI�ȣ�
	IN		NPC_INT								in_iClientType,				//[IN]�ͻ������ͣ��μ�NPC_D_MON_CLIENT_TYPE_*����
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID�����û��ʺ�
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]�û�����
	IN		PNPC_CHAR							in_pFindPwdEmail,			//[IN]�һ���������
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û�����
	IN		PNPC_CHAR							in_pLinkTelno				//[IN]��ϵ�绰
	);

//ע���ʺţ���չ2���������伤���V2��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RegisterAccountByNoActive_V2(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pClientId,				//[IN]�ͻ���ID����ͻ��˱�ʶ����IMSI�ȣ�
	IN		NPC_INT								in_iClientType,				//[IN]�ͻ������ͣ��μ�NPC_D_MON_CLIENT_TYPE_*����
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID�����û��ʺ�
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]�û�����
	IN		PNPC_CHAR							in_pFindPwdEmail,			//[IN]�һ���������
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û�����
	IN		PNPC_CHAR							in_pLinkTelno,				//[IN]��ϵ�绰
	IN		PNPC_CHAR							in_pIdentityCard			//[IN]���֤
	);

//��ѯע���ʺŵ����䣬��ע��ʱ������֤�������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryRegEmail(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID
	OUT		PNPC_CHAR							out_pRegEmail				//[OUT]ע������
	);

//�������������ʼ�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SendResetPasswordEmail(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId					//[IN]�û�ID
	);

//��ȡ�󶨵�¼�û�����ֻ����󶨵��û���¼��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetBindLoginUser(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	OUT		PNPC_BOOL							out_pIfBindLogin			//[OUT]�Ƿ�󶨵�¼����ֻ����󶨵��û���¼��
	);

//���ð󶨵�¼�û�����ֻ����󶨵��û���¼��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetBindLoginUser(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_BOOL							in_bIfBindLogin				//[IN]�Ƿ�󶨵�¼����ֻ����󶨵��û���¼��
	);

//��ȡ�豸�������Ȩ�ޣ����Ƿ����������û�����豸��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetDevLimitAddPop(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID���������ID
	OUT		PNPC_BOOL							out_pIfDevReg,				//[OUT]�豸�Ƿ�ע�ᵽ������
	OUT		PNPC_BOOL							out_pIfP2pDev,				//[OUT]�Ƿ�ΪP2P�豸������ΪP2P�豸�������ƹ���
	OUT		PNPC_BOOL							out_pIfLimitAddPop			//[OUT]�Ƿ�������ӣ�TRUE��ʾ�����������û���ӣ�FALSE��ʾ�����û��������
	);

//�����豸�������Ȩ�ޣ����Ƿ����������û�����豸��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetDevLimitAddPop(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID���������ID
	IN		NPC_BOOL							in_bIfLimitAddPop			//[IN]�Ƿ�������ӣ�TRUE��ʾ�����������û���ӣ�FALSE��ʾ�����û��������
	);

NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_LocalDeviceList(
    IN		NPC_HANDLE							in_hMonClient,				//�ͻ��˾��
    IN		PNPC_CHAR							in_pUserId					//�û�ID�����û��ʺ�
    );
//----------------------------------------------------------------------------------------
//�ͻ��˵�¼������TRUE��ʾ��¼�ɹ���FALSE��ʾ��¼ʧ�ܣ�NPC_F_MPI_MON_CLT_GetLastError�ɻ�ȡ�����룬���ܵĴ��������£�
//NPC_D_MPI_MON_ERROR_USERID_ERROR
//NPC_D_MPI_MON_ERROR_USERPWD_ERROR
//NPC_D_MPI_MON_ERROR_USER_PWD_ERROR
//NPC_D_MPI_MON_ERROR_ACCOUNT_HAVE_EXPIRED
//NPC_D_MPI_MON_ERROR_ACCOUNT_NO_ACTIVE
//NPC_D_MPI_MON_ERROR_ACCOUNT_DEBT_STOP
//NPC_D_MPI_MON_ERROR_IPADDR_BAN_LOGIN
//NPC_D_MPI_MON_ERROR_EXEC_ORDER_RET_FAIL
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_LoginEx(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID�����û��ʺ�
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]�û�����
	IN		PNPC_CHAR							in_pClientId,				//[IN]�ͻ���ID����ͻ��˱�ʶ����IMSI�ȣ�
	IN		PNPC_S_MPI_MON_USER_LOGIN_PR_IN_PARAM	in_pPrInParam,			//[IN]��¼��������
	OUT		PNPC_S_MPI_MON_USER_LOGIN_PR_OUT_PARAM	out_pPrOutParam			//[OUT]��¼���ز���
	);

//�ͻ���ע��
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_Logout(
	IN		NPC_HANDLE							in_hMonClient				//[IN]�ͻ��˾��
	);

//��ȡ��ǰ��¼״̬  
//<0����ȡ����  
//0����ʼ״̬
//1���ڲ�״̬
//2����������״̬
//3�����ڵ�¼״̬
//4����¼�ɹ�״̬
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetLoginStatus(
	IN		NPC_HANDLE							in_hMonClient				//�ͻ��˾��
	);

//���¿ͻ�����Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_UpdateClientInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iClientType,				//[IN]�ͻ������ͣ�0��PC��1���ֻ���ƽ��
	IN		PNPC_CHAR							in_pDevVendorName,			//[IN]�豸��������
	IN		PNPC_CHAR							in_pDevName,				//[IN]�豸��Ʒ����
	IN		PNPC_CHAR							in_pDevModel,				//[IN]�豸�ͺ�
	IN		PNPC_CHAR							in_pDevVersion,				//[IN]�豸�汾��
	IN		PNPC_CHAR							in_pDevCPUModel,			//[IN]�豸CPU�ͺ�
	IN		NPC_DWORD							in_dwDevMemorySize,			//[IN]�豸�ڴ��С��MB��
	IN		NPC_DWORD							in_dwDevStorageSize,		//[IN]�豸�洢��С��MB������Ӳ�̻�����
	IN		PNPC_CHAR							in_pDevNetInfo,				//[IN]�豸������Ϣ
	IN		PNPC_CHAR							in_pDevParam1,				//[IN]�豸����1
	IN		PNPC_CHAR							in_pDevParam2,				//[IN]�豸����2
	IN		PNPC_CHAR							in_pDevParam3,				//[IN]�豸����3
	IN		PNPC_CHAR							in_pDevInfo					//[IN]�豸������Ϣ
	);

//�޸��û�����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyUserPwd(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID�����û��ʺ�
	IN		PNPC_CHAR							in_pOldPwd,					//[IN]ԭ����
	IN		PNPC_CHAR							in_pNewPwd					//[IN]������
	);

//��ѯ�û���ȫ��Ȩ�ޱ���Ȩ�޿ɲ��������豸
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryUserGlobalPopedom(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID�����û��ʺ�
	OUT		PNPC_BOOL							out_pIfAllPop,				//[OUT]�Ƿ���ȫ��Ȩ�ޣ����ΪTRUE������Ҫ��ѯ���������й��ܶ�����ʹ��
	OUT		PNPC_INT							out_pPopNum,				//[OUT]Ȩ����
	OUT		PNPC_INT							out_pPopIdTable				//[OUT]Ȩ��ID�����128��Ȩ�ޣ��ɵ����߷����ڴ棬Ȩ��ID�μ�NPC_D_MPI_MON_USER_POP_*����
	);

//��ѯ�û����豸Ȩ�ޱ�����ָ���豸��Ȩ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryUserDevPopedom(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID�����û��ʺ�
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	OUT		PNPC_INT							out_pPopNum,				//[OUT]Ȩ����
	OUT		PNPC_INT							out_pPopIdTable				//[OUT]Ȩ��ID�����128��Ȩ�ޣ��ɵ����߷����ڴ棬Ȩ��ID�μ�NPC_D_MPI_MON_USER_POP_*����
	);

//��ȡ�豸��ʾ��Ϣ�б�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetDevPromptList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	OUT		PNPC_INT							out_pPromptNum,				//[OUT]��ʾ��Ϣ��
	OUT		PNPC_S_MPI_MON_DEV_PROMPT*			out_ppPromptList			//[OUT]��ʾ��Ϣ�б��ɵײ���䣬ʹ�����������NPC_F_MPI_MON_CLT_ReleaseDevPromptList�����ͷ��ڴ�
	);

//�ͷ���ʾ��Ϣ�б�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ReleaseDevPromptList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_PROMPT			in_pPromptList				//[IN]��ʾ��Ϣ�б�
	);

//�������룬��������Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ForgetPwd(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID
	OUT		PNPC_CHAR							out_pSendMsgTypeName		//[OUT]������Ϣ�������ƣ�����š��ʼ�
	);


//----------------------------------------------------------------------------------------
//����豸���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_AddDevNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iNodeType,				//[IN]������ͣ��μ�NPC_D_MPI_MON_DEV_NODE_TYPE_*����
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]����㣬�����ӵĽ��Ϊ���㣬����ֶ�ֵΪNULL
	IN		PNPC_CHAR							in_pNodeName,				//[IN]�������
	IN		NPC_INT								in_iConnMode,				//[IN]����ģʽ���μ�NPC_D_MON_DEV_CONN_MODE_*����
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pConnParam,				//[IN]���Ӳ���
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]������ӵ��豸�������
	);

//����豸��㣨��չ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_AddDevNodeEx(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iNodeType,				//[IN]������ͣ��μ�NPC_D_MPI_MON_DEV_NODE_TYPE_*����
	IN		NPC_DWORD							in_dwParentNodeId,			//[IN]�����ID�����Ϊ0����Ϊ����
	IN		PNPC_CHAR							in_pNodeName,				//[IN]�������
	IN		NPC_INT								in_iConnMode,				//[IN]����ģʽ���μ�NPC_D_MON_DEV_CONN_MODE_*����
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pConnParam,				//[IN]���Ӳ���
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]������ӵ��豸�������
	);

//ɾ���豸���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_DelDevNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode					//[IN]�豸���
	);

//�޸��豸���Ӳ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸���
	IN		PNPC_CHAR							in_pConnParam				//[IN]���Ӳ���
	);

//�޸Ľ������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyNodeName(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸���
	IN		PNPC_CHAR							in_pNodeName				//[IN]�������
	);

//��ѯ�豸��Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDevNodeInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸���
	OUT		PNPC_S_MPI_MON_DEV_INFO				out_pDevInfo				//[OUT]�豸��Ϣ
	);

//�ڷ������в�ѯ�豸��Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_AtSrvQueryDevInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	OUT		PNPC_S_MPI_MON_DEV_INFO				out_pDevInfo				//[OUT]�豸��Ϣ
	);

//��ѯ�豸״̬
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDevState(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸���
	OUT		PNPC_INT							out_pDevState				//[OUT]�豸״̬��0�����ߣ�1�����ߣ�2������
	);

//�����豸���Ӳ�����ѯ�豸ID
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDevIdByConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pConnParam,				//[IN]���Ӳ���
	OUT		PNPC_CHAR							out_pDevId					//[OUT]�豸ID
	);

//��ѯ�豸�б�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDevList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iQueryType,				//[IN]��ѯ���ͣ�0����ѯ�����豸��1����ѯ�����豸��2����ѯ�����豸
	OUT		PNPC_INT							out_pDevNum,				//[OUT]�豸��
	OUT		PNPC_BYTE*							out_ppDevListBuf			//[OUT]�豸�б��������ɸú������䣬�������ͷţ���NPC_S_MPI_MON_DEV_LIST_ITEM�ṹ�����
	);

//�ͷ��豸�б�����
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ReleaseDevListBuf(
	IN		PNPC_BYTE							in_pDevListBuf				//[IN]�豸�б���������NPC_F_MPI_MON_CLT_QueryDevList����������
	);

//��ѯP2P���豸�����Ӳ���������������ΪNPC_D_MON_DEV_CONN_MODE_CLOUD_P2P����NPC_D_MON_DEV_CONN_MODE_CLOUD_STREAM��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryP2pCloudDevConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID���������ID��
	OUT		PNPC_INT							out_pVendorId,				//[OUT]�豸����ID
	OUT		PNPC_CHAR							out_pDevUmid,				//[OUT]�豸UMID
	OUT		PNPC_CHAR							out_pDevUserName,			//[OUT]�豸�û���
	OUT		PNPC_CHAR							out_pDevUserPwd,			//[OUT]�豸����
	OUT		PNPC_INT							out_pDevChNo,				//[OUT]�豸ͨ����
	OUT		PNPC_INT							out_pDevStreamNo			//[OUT]�豸��������
	);

//��ѯֱ���豸�����Ӳ���������������ΪNPC_D_MON_DEV_CONN_MODE_DIRECT��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDirectDevConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID���������ID��
	OUT		PNPC_INT							out_pVendorId,				//[OUT]�豸����ID
	OUT		PNPC_CHAR							out_pDevAddr,				//[OUT]�豸��ַ
	OUT		PNPC_USHORT							out_pDevPort,				//[OUT]�豸�˿ں�
	OUT		PNPC_CHAR							out_pDevUserName,			//[OUT]�豸�û���
	OUT		PNPC_CHAR							out_pDevUserPwd,			//[OUT]�豸����
	OUT		PNPC_INT							out_pDevChNo,				//[OUT]�豸ͨ����
	OUT		PNPC_INT							out_pDevStreamNo			//[OUT]�豸��������
	);



//----------------------------------------------------------------------------------------
//��ѯ�豸�б������б���������NULL��ʾ��ѯʧ�ܣ�ʹ�����б��������NPC_F_MPI_MON_CLT_DevList_Release�����ͷ�
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_DevList_Query(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwQueryNodeId			//[IN]��ѯ���ID����øý��֮�µĽ�㣬ֻ��ѯһ�㣬���Ϊ0��ʾ��ѯ������
	);

//�ͷ��豸�б�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DevList_Release(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_HANDLE							in_hDevList					//[IN]�豸�б�
	);

//�ƶ����豸�б�ĵ�һ��
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DevList_MoveFirst(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_HANDLE							in_hDevList					//[IN]�豸�б�
	);

//��ȡ��һ���豸��Ϣ������NULL��ʾ��ȡ��ɣ��ú���������б���ɾ����¼
NPC_MPI_MON_API		PNPC_S_MPI_MON_DEV_NODE		NPC_F_MPI_MON_CLT_DevList_GetNextDevNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_HANDLE							in_hDevList					//[IN]�豸�б�
	);


//----------------------------------------------------------------------------------------
//���û����PTZ���ƣ�ָԤ�õ��Ѳ��·�����ƣ�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetPtzName(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		NPC_INT								in_iOpFlag,					//[IN]������־��1��ʾ���ã�0��ʾ���
	IN		NPC_INT								in_iPtzType,				//[IN]PTZ���ͣ�0��Ԥ�õ㣬1��Ѳ��·��
	IN		NPC_INT								in_iPtzIndex,				//[IN]PTZ�ţ���Ԥ�õ�Ż�Ѳ��·���ţ�Ԥ�õ��ֵ��ΧΪ1��255��Ѳ��·����ֵ��ΧΪ1��32
	IN		PNPC_CHAR							in_pPtzName					//[IN]PTZ���ƣ�ָԤ�õ��Ѳ��·�������ƣ����15�����ֻ�31���ַ�
	);

//��ѯPTZ�����б������б���������NULL��ʾ��ѯʧ�ܣ�ʹ�����б��������NPC_F_MPI_MON_CLT_PtzNameList_Release�����ͷ�
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_PtzNameList_Query(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId					//[IN]�豸ID
	);

//�ͷ�PTZ�����б�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_PtzNameList_Release(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_HANDLE							in_hPtzNameList				//[IN]PTZ�����б�
	);

//�ƶ���PTZ�����б�ĵ�һ��
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_PtzNameList_MoveFirst(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_HANDLE							in_hPtzNameList				//[IN]PTZ�����б�
	);

//��ȡ��һ��PTZ���ƣ�����NULL��ʾ��ȡ��ɣ��ú���������б���ɾ����¼
NPC_MPI_MON_API		PNPC_S_MPI_MON_PTZ_NAME		NPC_F_MPI_MON_CLT_PtzNameList_GetNextDevNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_HANDLE							in_hPtzNameList				//[IN]PTZ�����б�
	);


//----------------------------------------------------------------------------------------
//�����豸�ľ�γ�����꣬��������ڣ������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Coordinate_SetDevCoor(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		NPC_INT								in_iLongitude,				//[IN]���ȣ���6λΪС�����֣�����Ϊ�������֣�ֵ��ΧΪ-180000000~180000000
	IN		NPC_INT								in_iLatitude				//[IN]γ�ȣ���6λΪС�����֣�����Ϊ�������֣�ֵ��ΧΪ-90000000~90000000
	);

//ɾ���豸�ľ�γ������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Coordinate_DelDevCoor(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId					//[IN]�豸ID
	);


//----------------------------------------------------------------------------------------
//��ѯ�������Ӳ��������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Vendor_QueryConnParamTable(
	IN		NPC_HANDLE								in_hMonClient,			//[IN]�ͻ��˾��
	OUT		PNPC_S_MPI_MON_CONNPARAM_VENDOR_DATA*	out_ppVendorTable,		//[OUT]���̱���NPC_S_MPI_MON_CONNPARAM_VENDOR_DATA��ɵ����飬�ɵײ�����ڴ棬�ϲ�ʹ����������ú����ͷ��ڴ�
	OUT		PNPC_INT								out_pVendorNum			//[OUT]������
	);

//�ͷų������Ӳ�����
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_Vendor_ReleaseConnParamTable(
	IN		PNPC_S_MPI_MON_CONNPARAM_VENDOR_DATA	in_pVendorTable,		//[IN]���̱�
	IN		NPC_INT									in_iVendorNum			//[IN]������
	);


//----------------------------------------------------------------------------------------
//��ȡ������Ϣ������TRUE��ʾ��������Ϣ��FALSE��ʾû��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetPushMsg(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	OUT		PNPC_S_MPI_MON_PUSH_MSG_DATA		out_pPushMsgData,			//[OUT]������Ϣ����
	IN		NPC_INT								in_iTimeout					//[IN]�ȴ���ʱʱ�������룩
	);


//----------------------------------------------------------------------------------------
//�豸��Ȩ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EMP_DevEmpower(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		PNPC_CHAR							in_pPopIdTable,				//[IN]Ȩ��ID���Զ��ŷָ�
	IN		PNPC_CHAR							in_pAccepterUserIdTable		//[IN]�������û�ID���Զ��ŷָ�
	);

//ȡ���豸��Ȩ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EMP_CancelDevEmpower(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		PNPC_CHAR							in_pAccepterUserIdTable		//[IN]�������û�ID���Զ��ŷָ�
	);

//��ѯ�豸�Ľ�����Ȩ�û��б�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EMP_QueryDevAccepterUserList(
	IN		NPC_HANDLE								in_hMonClient,			//[IN]�ͻ��˾��
	IN		PNPC_CHAR								in_pDevId,				//[IN]�豸ID
	OUT		PNPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA*	out_pAccUserTable,		//[OUT]�������û����ɵײ�����ڴ棬ʹ�����������NPC_F_MPI_MON_CLT_EMP_ReleaseDevAccepterUserList�����ͷ�
	OUT		PNPC_INT								out_pAccUserNum			//[OUT]�������û���
	);

//�ͷŽ������û�������
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_EMP_ReleaseDevAccepterUserList(
	IN		PNPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA		in_pAccUserTable		//[IN]�������û����ɵײ�����ڴ棬ʹ����������ú����ͷ�
	);

//��ѯ�豸����Ȩ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EMP_QueryDevEmpowerUserId(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	OUT		PNPC_CHAR							out_pEmpowerUserId			//[OUT]��Ȩ���û�ID
	);


//----------------------------------------------------------------------------------------
//����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetAlarm(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		PNPC_CHAR							in_pAlarmTypeTable			//[IN]�������ͱ��Զ��ŷָ���ֵ�ο�NPC_D_MON_ALARM_TYPE_*����
	);

//��������չ�����ú���Ĭ�Ͽ������͹���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetAlarmEx(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		PNPC_CHAR							in_pAlarmTypeTable,			//[IN]�������ͱ��Զ��ŷָ���ֵ�ο�NPC_D_MON_ALARM_TYPE_*����
	IN		PNPC_CHAR							in_pToken					//[IN]��Ϣ���͵�TOKEN��IPHONEΪ���͵�TOKEN����׿��PCΪ�ͻ���ID
	);

//����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_CancelAlarm(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId					//[IN]�豸ID
	);

//���ò���֪ͨ����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetNotifyParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		NPC_INT								in_iNotifyType,				//[IN]֪ͨ���ͣ��ο�NPC_D_MON_ALARM_NOTIFY_TYPE_*����
	IN		PNPC_CHAR							in_pNotifyParam				//[IN]֪ͨ����������֪ͨ����ȷ��֪ͨ�������ݣ����ֻ�����ΪTOKEN������Ϊ�ֻ����룬EMAILΪEMAIL��ַ
	);

//ȡ������֪ͨ����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_CancelNotifyParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		NPC_INT								in_iNotifyType,				//[IN]֪ͨ���ͣ��ο�NPC_D_MON_ALARM_NOTIFY_TYPE_*����
	IN		PNPC_CHAR							in_pNotifyParam				//[IN]֪ͨ����������֪ͨ����ȷ��֪ͨ�������ݣ����ֻ�����ΪTOKEN������Ϊ�ֻ����룬EMAILΪEMAIL��ַ
	);

//���ñ�������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetAlarmAction(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		NPC_INT								in_iActionType,				//[IN]�������ͣ��ο�NPC_D_MON_ALARM_ACTION_TYPE_*����
	IN		NPC_INT								in_iStopType,				//[IN]ֹͣ���ͣ�0������ֹͣʱֹͣ��1���̶�ʱ��ֹͣ
	IN		NPC_INT								in_iPhotoSpaceTime,			//[IN]���ռ��ʱ�䣨�룩
	IN		NPC_INT								in_iActionTotalTime,		//[IN]������ʱ�䣨�룩
	IN		NPC_INT								in_iPtzCruiseId				//[IN]PTZ����Ѳ��ID
	);

//ȡ����������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_CancelAlarmAction(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		NPC_INT								in_iActionType				//[IN]�������ͣ��ο�NPC_D_MON_ALARM_ACTION_TYPE_*����
	);

//��ѯ������Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_QueryArmInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	OUT		PNPC_S_MPI_MON_ARM_SET_ALARM_INFO	out_pArmInfo				//[OUT]����������Ϣ
	);

//��������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_ArmCtrl(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		NPC_INT								in_iCtrlCode				//[IN]���ƴ��룬�ο�NPC_D_MON_ALARM_CTRL_*����
	);

//��ѯ������¼�����ز�ѯ�б���������NULL��ʾ��ѯʧ�ܣ�������ʹ�����ѯ�б�󣬱ص���NPC_F_MPI_MON_CLT_ARM_ReleaseAlarmRecordList�ͷ�
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Query(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pQueryDevId,				//[IN]��ѯ�豸ID���������ID�������ΪNULL���ֵ�����������Ч
	IN		NPC_INT								in_iQueryAlarmType,			//[IN]��ѯ�������ͣ��ο�NPC_D_MON_ALARM_TYPE_*���壬���Ϊ0����ʾ��������Ч
	IN		PNPC_S_TD_DATE_TIME					in_pQueryBeginTime,			//[IN]��ѯ��ʼʱ�䣬���ΪNULL�����������Ч
	IN		PNPC_S_TD_DATE_TIME					in_pQueryEndTime			//[IN]��ѯ����ʱ�䣬���ΪNULL�����������Ч
	);

//�ͷű�����¼�б�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_ReleaseList(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]������¼�б�
	);

//��¼ָ���ƶ�����һ������ѯ���ʼ״̬Ϊ��һ�������Բ�ѯ����Բ����øú������ú���������ȡ����ٴ���ȡʹ�ã�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_MoveFirst(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]������¼�б�
	);

//��ȡ��һ����¼������NULL��ʾ��ȡ��أ����ص�ָ��ֻ��ʹ�ã������ͷţ��ͷ����ͷű�����¼�б���ͳһ�ͷ�
NPC_MPI_MON_API		PNPC_S_MPI_MON_ARM_ALARM_RECORD		NPC_F_MPI_MON_CLT_ARM_AlarmRecord_GetNext(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]������¼�б�
	);

//ɾ��������¼
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Delete(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pAlarmRecordId			//[IN]������¼ID
	);

//ɾ�����б�����¼
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_DeleteAll(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iDelMode,				//[IN]ɾ��ģʽ��0���û��µ����б�����¼��1���û��µ��豸�ı�����¼
	IN		PNPC_CHAR							in_pDevId					//[IN]�豸ID���������ID����UMID��
	);

//��ȡ�ͻ��˵ı���֪ͨ����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_GetClientAlarmNotifyParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	OUT		PNPC_BOOL							out_pIfMsgNotify			//[OUT]�Ƿ�Ҫ��Ϣ֪ͨ
	);

//���ÿͻ��˵ı���֪ͨ����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetClientAlarmNotifyParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_BOOL							in_bIfMsgNotify				//[IN]�Ƿ�Ҫ��Ϣ֪ͨ
	);

//���¿ͻ���TOKEN
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_UpdateClientToken(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pClientToken				//[IN]�ͻ���TOKEN
	);

//��ȡ�ͻ����Ƿ��������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_GetClientIfRecvPush(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	OUT		PNPC_BOOL							out_pIfRecvPush				//[IN]�Ƿ��������
	);

//���ÿͻ����Ƿ��������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetClientIfRecvPush(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_BOOL							in_bIfRecvPush				//[IN]�Ƿ��������
	);

//��ȡ�ͻ������Ͳ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_GetClientPushParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	OUT		PNPC_BOOL							out_pIfRecvPush,			//[IN]�Ƿ��������
	OUT		PNPC_INT							out_pNotReadCount			//[IN]δ��ȡ��¼��
	);

//���ÿͻ������Ͳ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetClientPushParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_BOOL							in_bEnableIfRecvPush,		//[IN]����in_bIfRecvPush�Ƿ���Ч�����ΪTRUE����ʾin_bIfRecvPush������Ч������Ϊ��Ч���������øò���
	IN		NPC_BOOL							in_bEnableNotReadCount,		//[IN]����in_iNotReadCount�Ƿ���Ч
	IN		NPC_BOOL							in_bIfRecvPush,				//[IN]�Ƿ��������
	IN		NPC_INT								in_iNotReadCount			//[IN]δ��ȡ��¼��
	);

//�����û����ͣ���Ҫ����IOS�ͻ����л��ʺ�ʱʹ�ã�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_ActivateUserPush(
	IN		NPC_HANDLE							in_hMonClient,					//[IN]�ͻ��˾��
	IN		NPC_INT								in_iRecvPushCtrl,				//[IN]���ʺ��Ƿ�������ͣ�0�������ã�1�������գ�2������
	IN		NPC_BOOL							in_bIfDisableOtherUserRecvPush	//[IN]�Ƿ���Ҫ���������ʺŽ�������
	);


//--------------------------------------------------------------------------------------------
//��ѯС��������¼�����ز�ѯ�б���������NULL��ʾ��ѯʧ�ܣ�������ʹ�����ѯ�б�󣬱ص���NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_ReleaseList�ͷ�
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_Query(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_TD_DATE_TIME					in_pQueryBeginTime,			//[IN]��ѯ��ʼʱ�䣬���ΪNULL�����������Ч
	IN		PNPC_S_TD_DATE_TIME					in_pQueryEndTime			//[IN]��ѯ����ʱ�䣬���ΪNULL�����������Ч
	);

//�ͷ�С��������¼�б�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_ReleaseList(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]������¼�б�
	);

//��¼ָ���ƶ�����һ������ѯ���ʼ״̬Ϊ��һ�������Բ�ѯ����Բ����øú������ú���������ȡ����ٴ���ȡʹ�ã�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_MoveFirst(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]������¼�б�
	);

//��ȡ��һ����¼������NULL��ʾ��ȡ��أ����ص�ָ��ֻ��ʹ�ã������ͷţ��ͷ����ͷű�����¼�б���ͳһ�ͷ�
NPC_MPI_MON_API		PNPC_S_MPI_MON_ARM_VILLAGE_ALARM_RECORD		NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_GetNext(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]������¼�б�
	);

//���ñ������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_SetAlarmResult(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pAlarmRecordId,			//[IN]������¼ID
	IN		PNPC_CHAR							in_pAlarmResult				//[IN]�������
	);

//��ȡ֪ͨ����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_GetNotifyLanguage(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iGetType,				//[IN]��ȡ���ͣ�0�����ͣ�1������
	IN		PNPC_CHAR							in_pToken,					//[IN]TOKEN����������ͣ���Ϊ�ֻ�TOKEN��������ţ���Ϊ�ֻ�����
	OUT		PNPC_CHAR							out_pNotifyLanguage			//[OUT]֪ͨ����
	);

//����֪ͨ����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetNotifyLanguage(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iGetType,				//[IN]��ȡ���ͣ�0�����ͣ�1������
	IN		PNPC_CHAR							in_pToken,					//[IN]TOKEN����������ͣ���Ϊ�ֻ�TOKEN��������ţ���Ϊ�ֻ�����
	IN		PNPC_CHAR							in_pNotifyLanguage			//[IN]֪ͨ����
	);


//--------------------------------------------------------------------------------------------
//��֤ȫ��Ȩ�ޣ�����TRUE���д�Ȩ�ޣ�FALSE��ʾ�޴�Ȩ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_CheckGlobalPop(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iPopId					//[IN]Ȩ��ID
	);

//��֤�豸Ȩ�ޣ�����TRUE���д�Ȩ�ޣ�FALSE��ʾ�޴�Ȩ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_CheckDevPop(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸���
	IN		NPC_INT								in_iPopId					//[IN]Ȩ��ID
	);


//--------------------------------------------------------------------------------------------
//��ʼ�����豸
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_StartSearchDev(
	IN		NPC_BOOL							in_bIfAutoRefresh=TRUE,		//[IN]�Ƿ��Զ�ˢ��
	IN		NPC_INT								in_iRefreshIntervalTime=2	//[IN]ˢ�¼��ʱ�䣨�룩
	);

//��ʼ�����豸����չ��
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_StartSearchDevEx(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_BOOL							in_bIfAutoRefresh=TRUE,		//[IN]�Ƿ��Զ�ˢ��
	IN		NPC_INT								in_iRefreshIntervalTime=2	//[IN]ˢ�¼��ʱ�䣨�룩
	);

//ֹͣ�����豸
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_StopSearchDev(
	IN		NPC_HANDLE							in_hSearchDev				//[IN]�����豸���
	);

//����ˢ��ģʽ
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetRefreshMode(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	IN		NPC_BOOL							in_bIfAutoRefresh,			//[IN]�Ƿ��Զ�ˢ��
	IN		NPC_INT								in_iRefreshIntervalTime		//[IN]ˢ�¼��ʱ�䣨�룩
	);

//����ˢ��
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_RequRefresh(
	IN		NPC_HANDLE							in_hSearchDev				//[IN]�����豸���
	);

//��ȡ�����豸�б���ʱ���û�ȡ�豸�б�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetSearchDevTable(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	OUT		PNPC_INT							out_pSearchDevNum,			//[OUT]�豸��
	OUT		PNPC_S_MPI_MON_SEARCH_DEV_DATA*		out_ppSearchDevTable		//[OUT]�����豸�����豸���飬ָ��ָ����ڴ�ռ䣬�ϲ�ֻ��ʹ�ã������޸ĺ��ͷ�
	);

//�޸������豸ID
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifySearchDevId(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	IN		PNPC_CHAR							in_pOldDevId,				//[IN]ԭ�豸ID
	IN		PNPC_CHAR							in_pNewDevId				//[IN]���豸ID
	);

//�޸������豸����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifySearchDevName(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		PNPC_CHAR							in_pDevName					//[IN]�豸����
	);

//�����豸��־��Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_TraceDevLogInfo(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	IN		PNPC_CHAR							in_pDevMac,					//[IN]�豸MAC����ʽΪXX-XX-
	IN		NPC_BOOL							in_bIfOpenTrace				//[IN]�Ƿ�򿪸��٣�TRUE��ʾ�򿪣�FALSE��ʾ�ر�
	);

//��ȡ�豸��־��Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetDevLogInfo(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	IN		PNPC_CHAR							in_pLogBuf,					//[IN]��־�����������ϲ�����ڴ�
	IN		NPC_INT								in_iLogBufSize				//[IN]��־��������С
	);



//--------------------------------------------------------------------------------------------
//��������SDK�豸
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RequSearchSdkDev(
	IN		NPC_HANDLE							in_hSearchDev				//[IN]�����豸���
	);

//��ȡ����SDK�豸�б�ֻ֧���ϲ㵥�̵߳��ú�ʹ���ڴ棩
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetSearchSdkDevTable(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	OUT		PNPC_INT							out_pSearchSdkDevNum,		//[OUT]SDK�豸��
	OUT		PNPC_S_MPI_MON_SEARCH_SDK_DEV_DATA*	out_ppSearchSdkDevTable		//[OUT]����SDK�豸�����豸���飬ָ��ָ����ڴ�ռ䣬�ϲ�ֻ��ʹ�ã������޸ĺ��ͷ�
	);

//����SDK�豸��־��Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_TraceSdkDevLogInfo(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	IN		NPC_UINT							in_uiDevFlag,				//[IN]�豸��ʶ���������豸�����е�һ��
	IN		NPC_BOOL							in_bIfOpenTrace				//[IN]�Ƿ�򿪸��٣�TRUE��ʾ�򿪣�FALSE��ʾ�ر�
	);

//����SDK�豸���Բ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetSdkDevParam(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	IN		NPC_UINT							in_uiDevFlag,				//[IN]�豸��ʶ���������豸�����е�һ��
	IN		NPC_BOOL							in_bIfOpenDebug				//[IN]�Ƿ�򿪵��Կ���
	);

//��ȡSDK�豸��־��Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetSdkDevLogInfo(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]�����豸���
	IN		PNPC_CHAR							in_pLogBuf,					//[IN]��־�����������ϲ�����ڴ�
	IN		NPC_INT								in_iLogBufSize				//[IN]��־��������С
	);


//--------------------------------------------------------------------------------------------
//��ѯNTS�豸�Ĳ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryNtsDevParam(
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	OUT		PNPC_S_MPI_MON_NTS_DEV_PARAM		out_pNtsDevParam			//[OUT]NTS�豸����
	);

//�޸��豸�е�ע���������ַ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevRegSrvAddr(
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]��������ַ��IP��ַ��������
	IN		NPC_USHORT							in_usServerPort				//[IN]�������˿ں�
	);

//�޸��豸�еĸ��ٲ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevTraceParam(
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		NPC_BOOL							in_bIfWriteLogFile,			//[IN]�Ƿ�д��־�ļ�
	IN		NPC_BOOL							in_bIfStartLogNetSrv,		//[IN]�Ƿ���Ҫ������־�������
	IN		NPC_USHORT							in_usLogNetSrvPort,			//[IN]��־�������˿ں�
	IN		NPC_BOOL							in_bIfStartLogUpClient,		//[IN]�Ƿ���Ҫ������־�ϴ��ͻ���
	IN		PNPC_CHAR							in_pLogUpSrvIpaddr,			//[IN]��־�ϴ�����IP��ַ
	IN		NPC_USHORT							in_usLogUpSrvPort			//[IN]��־�ϴ�����˿ں�
	);

//�޸��豸�е��豸ID����UMID��������0��ʾ�ɹ���50����ʾ�����ֶ�����ģʽ��51����ʾ�������ò���ʧ��
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_ModifyDevId(
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]����MAC��ַ����ʽΪ��XX-XX-
	IN		PNPC_CHAR							in_pDevId					//[IN]�豸ID����UMID��
	);

//�޸��豸�е��豸����֤�루ֻ������֤����Ȩģʽ���ã�������0��ʾ�ɹ���50����ʾ������֤����Ȩģʽ��51����ʾ�������ò���ʧ��
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_ModifyDevAuthCode(
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]����MAC��ַ����ʽΪ��XX-XX-
	IN		PNPC_CHAR							in_pAuthCode				//[IN]��Ȩ��
	);

//��ȡ�豸�е���Ȩ�룬����0��ʾ�ɹ���������ʾʧ��
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetDevEmpower(
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]����MAC��ַ����ʽΪ��XX-XX-
	OUT		PNPC_INT							out_pEmpowerMode,			//[OUT]��Ȩģʽ��1��UMID��Ȩģʽ��3����������Ȩģʽ
	OUT		PNPC_CHAR							out_pEmpowerCode,			//[OUT]��Ȩ��
	OUT		PNPC_INT							out_pDevIdType,				//[OUT]�豸ID���ͣ�0���ֶ����÷�ʽ��2����MAC��ַ���ɷ�ʽ����������ļ����豸ID���ڣ��򲻻������ɣ�
	OUT		PNPC_CHAR							out_pDevId					//[OUT]�豸ID
	);

//�����豸�е���Ȩ�룬����0��ʾ�ɹ���50����ʾ������֤����Ȩģʽ��51~54����ʾ�������ò���ʧ��
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_SetDevEmpower(
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]����MAC��ַ����ʽΪ��XX-XX-
	IN		NPC_INT								in_iEmpowerMode,			//[IN]��Ȩģʽ��1��UMID��Ȩģʽ��3����������Ȩģʽ
	IN		PNPC_CHAR							in_pEmpowerCode,			//[IN]��Ȩ��
	IN		NPC_INT								in_iDevIdType,				//[IN]�豸ID���ͣ�0���ֶ����÷�ʽ��2����MAC��ַ���ɷ�ʽ����������ļ����豸ID���ڣ��򲻻������ɣ�
	IN		PNPC_CHAR							in_pDevId					//[IN]�豸ID
	);


//--------------------------------------------------------------------------------------------
//�޸��豸��IP��ַ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevIpaddr(
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]����MAC��ַ����ʽΪ��XX-XX-
	IN		PNPC_CHAR							in_pOldIpaddr,				//[IN]ԴIP��ַ
	IN		PNPC_CHAR							in_pNewIpaddr,				//[IN]��IP��ַ
	IN		PNPC_CHAR							in_pNewNetmask,				//[IN]����������
	IN		PNPC_CHAR							in_pNewGateway				//[IN]�����ص�ַ
	);

//ʹ���豸��DHCP����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EnableDevDhcp(
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]����MAC��ַ����ʽΪ��XX-XX-
	IN		PNPC_CHAR							in_pAdapterName,			//[IN]��������
	IN		NPC_BOOL							in_bEnable					//[IN]ʹ��DHCP��TRUE������DHCP��FALSE������DHCP
	);

//�޸��豸����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevPwd(
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]����MAC��ַ����ʽΪ��XX-XX-
	IN		PNPC_CHAR							in_pOldPwd,					//[IN]ԭ���룬����豸δ���ù����룬��ò���ΪNULL
	IN		PNPC_CHAR							in_pNewPwd					//[IN]������
	);

//�޸��豸����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevName(
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]����MAC��ַ����ʽΪ��XX-XX-
	IN		PNPC_CHAR							in_pDevName					//[IN]�豸����
	);


//--------------------------------------------------------------------------------------------
//���ͨ���豸
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_AddCommonDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwParentNodeId,			//[IN]�����ID�������ӵĽ��Ϊ���㣬����ֶ�ֵΪ0
	IN		NPC_INT								in_iConnMode,				//[IN]����ģʽ���μ�NPC_D_MON_DEV_CONN_MODE_*����
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pName,					//[IN]����
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]�豸UMID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]�豸��ַ
	IN		NPC_USHORT							in_usDevPort,				//[IN]�豸�˿ں�
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iStreamNo,				//[IN]������0����������1��������
	IN		NPC_INT								in_iChNum,					//[IN]ͨ����
	IN		NPC_INT								in_iDevNodeTableSize,		//[IN]�豸�����С���ֽڣ���ӦΪ(in_iChNum+1)*sizeof(NPC_S_MPI_MON_DEV_NODE)
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNodeTable,			//[OUT]������ӵ��豸�����ڴ��ϵ����߷���
	OUT		PNPC_INT							out_pDevNodeNum				//[OUT]�豸�����
	);

//���ͨ�������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_AddCommonCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwParentNodeId,			//[IN]�����ID�������ӵĽ��Ϊ���㣬����ֶ�ֵΪ0
	IN		NPC_INT								in_iConnMode,				//[IN]����ģʽ���μ�NPC_D_MON_DEV_CONN_MODE_*����
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pName,					//[IN]����
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]�豸UMID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]�豸��ַ
	IN		NPC_USHORT							in_usDevPort,				//[IN]�豸�˿ں�
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iStreamNo,				//[IN]������0����������1��������
	IN		NPC_INT								in_iChNo,					//[IN]ͨ����
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]������ӵ��豸�������
	);

//ɾ��ͨ���豸
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_DeleteCommonDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwNodeId					//[IN]���ID��ֵ����0
	);

//�޸�P2P�豸�����Ӳ�������ͣ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_ModifyP2pDevConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwNodeId,				//[IN]���ID��ֵ����0
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID���������ID�ȣ�
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]�豸UMID
	IN		PNPC_CHAR							in_pDevUserName,			//[IN]�豸�û���
	IN		PNPC_CHAR							in_pDevUserPwd,				//[IN]�豸�û�����
	IN		NPC_BOOL							in_bIfModifyStreamNo,		//[IN]�Ƿ���Ҫ�޸�������
	IN		NPC_INT								in_iDevStreamNo				//[IN]�豸�������ţ�0����������1����������i_bIfModifyStreamNoΪTRUE����Ч
	);

//�޸�ͨ���豸�����������
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_ModifyCommonDevAndCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwNodeId,				//[IN]���ID
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]�豸UMID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]�豸��ַ
	IN		NPC_USHORT							in_usDevPort,				//[IN]�豸�˿ں�
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iChNo,					//[IN]ͨ���ţ����Ϊ-1��ʾ���޸ģ����ΪDVR��Ҳ���޸�
	IN		NPC_INT								in_iStreamNo,				//[IN]������0����������1��������
	IN		NPC_BOOL							in_bIfModifyStreamNo		//[IN]�Ƿ���Ҫ�޸�������
	);

//���Ŀ¼���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_AddCatalogNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwParentNodeId,			//[IN]�����ID�������ӵĽ��Ϊ���㣬����ֶ�ֵΪ0
	IN		PNPC_CHAR							in_pNodeName,				//[IN]�������
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]������ӵ��豸�������
	);

//�޸Ľ�����ƣ�����Ŀ¼��DVR����ͷ�����ƣ�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_ModifyNodeName(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_DWORD							in_dwNodeId,				//[IN]���ID
	IN		PNPC_CHAR							in_pNodeName				//[IN]�������
	);


//--------------------------------------------------------------------------------------------
//���P2P���豸
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddP2pCloudDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]����㣬�����ӵĽ��Ϊ���㣬����ֶ�ֵΪNULL
	IN		PNPC_CHAR							in_pName,					//[IN]����
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iStreamNo,				//[IN]������0����������1��������
	IN		NPC_INT								in_iChNum,					//[IN]ͨ����
	IN		NPC_INT								in_iDevNodeTableSize,		//[IN]�豸�����С���ֽڣ���ӦΪ(in_iChNum+1)*sizeof(NPC_S_MPI_MON_DEV_NODE)
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNodeTable,			//[OUT]������ӵ��豸�����ڴ��ϵ����߷���
	OUT		PNPC_INT							out_pDevNodeNum				//[OUT]�豸�����
	);

//���P2P�ƾ�ͷ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddP2pCloudCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]����㣬�����ӵĽ��Ϊ���㣬����ֶ�ֵΪNULL
	IN		PNPC_CHAR							in_pName,					//[IN]����
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iStreamNo,				//[IN]������0����������1��������
	IN		NPC_INT								in_iChNo,					//[IN]ͨ����
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]������ӵ��豸�������
	);

//���ֱ���豸
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddDirectDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]����㣬�����ӵĽ��Ϊ���㣬����ֶ�ֵΪNULL
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pName,					//[IN]����
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]�豸��ַ
	IN		NPC_USHORT							in_usDevPort,				//[IN]�豸�˿�
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iStreamNo,				//[IN]������0����������1��������
	IN		NPC_INT								in_iChNum,					//[IN]ͨ����
	IN		NPC_INT								in_iDevNodeTableSize,		//[IN]�豸�����С���ֽڣ���ӦΪ(in_iChNum+1)*sizeof(NPC_S_MPI_MON_DEV_NODE)
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNodeTable,			//[OUT]������ӵ��豸�����ڴ��ϵ����߷���
	OUT		PNPC_INT							out_pDevNodeNum				//[OUT]�豸�����
	);

//���ֱ����ͷ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddDirectCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]����㣬�����ӵĽ��Ϊ���㣬����ֶ�ֵΪNULL
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pName,					//[IN]�豸����
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]�豸��ַ
	IN		NPC_USHORT							in_usDevPort,				//[IN]�豸�˿�
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iStreamNo,				//[IN]������0����������1��������
	IN		NPC_INT								in_iChNo,					//[IN]ͨ����
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]������ӵ��豸�������
	);

//�������ý���豸
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddCloudStreamDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]����㣬�����ӵĽ��Ϊ���㣬����ֶ�ֵΪNULL
	IN		PNPC_CHAR							in_pName,					//[IN]����
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iStreamNo,				//[IN]������0����������1��������
	IN		NPC_INT								in_iChNum,					//[IN]ͨ����
	IN		NPC_INT								in_iDevNodeTableSize,		//[IN]�豸�����С���ֽڣ���ӦΪ(in_iChNum+1)*sizeof(NPC_S_MPI_MON_DEV_NODE)
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNodeTable,			//[OUT]������ӵ��豸�����ڴ��ϵ����߷���
	OUT		PNPC_INT							out_pDevNodeNum				//[OUT]�豸�����
	);

//�������ý�徵ͷ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddCloudStreamCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]����㣬�����ӵĽ��Ϊ���㣬����ֶ�ֵΪNULL
	IN		PNPC_CHAR							in_pName,					//[IN]����
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iStreamNo,				//[IN]������0����������1��������
	IN		NPC_INT								in_iChNo,					//[IN]ͨ����
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]������ӵ��豸�������
	);


//--------------------------------------------------------------------------------------------
//�޸�P2P���豸
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyP2pCloudDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸�������
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]�Ƿ��޸�����
	IN		NPC_INT								in_iStreamNo				//[IN]������0����������1��������
	);

//�޸�P2P�ƾ�ͷ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyP2pCloudCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸�������
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iChNo,					//[IN]ͨ����
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]�Ƿ��޸�����
	IN		NPC_INT								in_iStreamNo				//[IN]������0����������1��������
	);

//�޸�ֱ���豸
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyDirectDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸�������
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]�豸��ַ
	IN		NPC_USHORT							in_usDevPort,				//[IN]�豸�˿�
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]�Ƿ��޸�����
	IN		NPC_INT								in_iStreamNo				//[IN]������0����������1��������
	);

//�޸�ֱ����ͷ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyDirectCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸�������
	IN		NPC_DWORD							in_dwVendorId,				//[IN]����ID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]�豸��ַ
	IN		NPC_USHORT							in_usDevPort,				//[IN]�豸�˿�
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iChNo,					//[IN]ͨ����
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]�Ƿ��޸�����
	IN		NPC_INT								in_iStreamNo				//[IN]������0����������1��������
	);

//�޸�����ý���豸����DVR��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyCloudStreamDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸�������
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]�Ƿ��޸�����
	IN		NPC_INT								in_iStreamNo				//[IN]������0����������1��������
	);

//�޸�����ý�徵ͷ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyCloudStreamCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]�豸�������
	IN		PNPC_CHAR							in_pDevId,					//[IN]�豸ID����UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]�û���
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]����
	IN		NPC_INT								in_iChNo,					//[IN]ͨ����
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]�Ƿ��޸�����
	IN		NPC_INT								in_iStreamNo				//[IN]������0����������1��������
	);


//------------------------------------------------------------------------------------------------------
//��ȡ�Ͳ���֧�ֵĳ���Э���б�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_GetProVendorList(
	OUT		PNPC_INT							out_pVendorNum,				//[OUT]������
	OUT		PNPC_S_MPI_MON_VENDOR_NAME			out_pVendorTable			//[OUT]���̱����飩���ɵ����߷����ڴ棬��СΪ64*sizeof(NPC_S_MPI_MON_VENDOR_NAME)
	);


//------------------------------------------------------------------------------------------------------
//��ȡ�����ļ�����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_SFI_GetOpFileOrder(
	OUT		PNPC_S_MPI_MON_FILE_OP_ORDER*		out_ppFileOpOrder,			//[OUT]�ļ���������ڴ��ɵͲ���䣬�ϲ�ֻ��ʹ�ã�����Ҫ����NPC_F_MPI_MON_SFI_ReleaseOpFileOrderBuf�����ͷ�
	IN		NPC_INT								in_iTimeout					//[IN]��ʱʱ�������룩
	);

//���ز����ļ�Ӧ����Ϣ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_SFI_ReturnOpFileResp(
	IN		PNPC_S_MPI_MON_FILE_OP_ORDER		in_pFileOpOrder				//[IN]�ļ���������ڴ����ϲ���估�ͷţ��ײ�ֻ��ʹ��
	);

//�ͷ��ļ������������
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_SFI_ReleaseOpFileOrderBuf(
	IN		PNPC_S_MPI_MON_FILE_OP_ORDER		in_pFileOpOrder				//[IN]�ļ����������NPC_F_MPI_MON_SFI_GetOpFileOrder���������Ļ�����
	);

#ifdef _WIN32
//�����ļ���д�߳�
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_SFI_StartFileReadWriteThread();

//�ر��ļ���д�߳�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_SFI_StopFileReadWriteThread();
#endif



//------------------------------------------------------------------------------------------------------
//��ȡ���Ƶ����ò��������������б��������ΪNULL����ʾ����ʧ�ܣ����ò��������ݽṹΪNPC_S_MPI_MON_CLIENT_CONFIG_DATA_V2
//�б������ο�NPC_TOOLS_List.h�ļ��ĺ������ϲ���Ҫ�ͷŸ��б����ú���������δ��¼����µ��ã�
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_GetCustomConfigTable(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iClientType,				//[IN]�ͻ������ͣ��μ�NPC_D_MON_CLIENT_TYPE_*����
	IN		PNPC_CHAR							in_pClientId,				//[IN]�ͻ���ID
	IN		PNPC_CHAR							in_pCustomFlag				//[IN]���Ʊ�ʶ
	);

//��ȡ���Ƶĳ����б����س����б��������ΪNULL����ʾ����ʧ�ܣ����̶�������ݽṹΪNPC_S_MPI_MON_CLIENT_VENDOR_CFG_DATA
//�б������ο�NPC_TOOLS_List.h�ļ��ĺ������ϲ���Ҫ�ͷŸ��б����ú���������δ��¼����µ��ã�
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_GetCustomVendorTable(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		NPC_INT								in_iClientType,				//[IN]�ͻ������ͣ��μ�NPC_D_MON_CLIENT_TYPE_*����
	IN		PNPC_CHAR							in_pClientId,				//[IN]�ͻ���ID
	IN		PNPC_CHAR							in_pCustomFlag				//[IN]���Ʊ�ʶ
	);


//------------------------------------------------------------------------------------------------------
//��ѯϵͳ��Ϣ�б������б������������NPC_F_MPI_MON_CLT_SysMsgList_ReleaseSysMsgList�����ͷ��б�
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_SysMsgList_QuerySysMsgList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pCustomFlag,				//[IN]���Ʊ�ʶ
	OUT		PNPC_INT							out_pMsgNum					//[IN]��Ϣ��
	);

//�ƶ�����һ����Ϣ����ʼΪ��һ����Ϣ��
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SysMsgList_MoveFirstMsg(
	IN		NPC_HANDLE							in_hSysMsgList				//[IN]ϵͳ��Ϣ�б�
	);

//��ȡ��һ����Ϣ������TRUE��ʾ�У�FALSE��ʾû��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SysMsgList_GetNextMsg(
	IN		NPC_HANDLE							in_hSysMsgList,				//[IN]ϵͳ��Ϣ�б�
	OUT		PNPC_S_MPI_MON_SYSTEM_MSG			out_pSysMsg					//[OUT]ϵͳ��Ϣ
	);

//�ͷ�ϵͳ��Ϣ�б�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SysMsgList_ReleaseSysMsgList(
	IN		NPC_HANDLE							in_hSysMsgList				//[IN]ϵͳ��Ϣ�б�
	);


//------------------------------------------------------------------------------------------------------
//��ѯ��ʾ���б������б������������NPC_F_MPI_MON_CLT_DemoList_ReleaseList�����ͷ��б�
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_DemoList_QueryVideodemoList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pCustomFlag,				//[IN]���Ʊ�ʶ
	IN		NPC_INT								in_iLangKind,				//[IN]�������࣬�μ�NPC_D_MON_LAND_KIND_*����
	OUT		PNPC_CHAR							out_pStreamSrvIpaddr,		//[OUT]��ý�������IP��ַ
	OUT		PNPC_USHORT							out_pStreamSrvPort,			//[OUT]��ý��������˿ں�
	OUT		PNPC_INT							out_pDevNum					//[OUT]�豸��
	);

//�ƶ�����һ���豸����ʼΪ��һ���豸��
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DemoList_MoveFirstDev(
	IN		NPC_HANDLE							in_hDemoDevList				//[IN]��ʾ���б�
	);

//��ȡ��һ���豸������TRUE��ʾ�У�FALSE��ʾû��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_DemoList_GetNextDev(
	IN		NPC_HANDLE							in_hDemoDevList,			//[IN]��ʾ���б�
	OUT		PNPC_S_MPI_MON_VIDEO_DEMO_DEV_DATA	out_pDevData				//[OUT]�豸����
	);

//�ͷ���ʾ���б�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DemoList_ReleaseList(
	IN		NPC_HANDLE							in_hDemoDevList				//[IN]��ʾ���б�
	);


//------------------------------------------------------------------------------------------------------
//��ѯ���������ͼURL
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_THUMB_QueryCameraThumbUrl(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pCameraId,				//[IN]�����ID
	OUT		PNPC_CHAR							out_pThumbUrl,				//[OUT]����ͼURL
	OUT		PNPC_BOOL							out_pIfEnable				//[OUT]�Ƿ�����
	);

//�����ϴ����������ͼ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_THUMB_RequUpCameraThumbUrl(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pCameraId,				//[IN]�����ID
	OUT		PNPC_CHAR							out_pThumbUrl,				//[OUT]����ͼURL
	OUT		PNPC_BOOL							out_pIfEnable				//[OUT]�Ƿ�����
	);

//��ѯ�û����������������ͼURL�������б���
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_THUMB_QueryUserAllCameraThumbUrl(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pUserId					//[IN]�û�ID
	);

//�ƶ�����һ��URL����ʼΪ��һ����
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_THUMB_MoveFirst(
	IN		NPC_HANDLE							in_hThumbUrlList			//[IN]����ͼURL�б���
	);

//��ȡ��һ������ͼURL������TRUE��ʾ��ȡ�ɹ���FALSE��ʾû�м�¼
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_THUMB_GetNext(
	IN		NPC_HANDLE							in_hThumbUrlList,			//[IN]����ͼURL�б���
	OUT		PNPC_CHAR							out_pCameraId,				//[OUT]�����ID
	OUT		PNPC_CHAR							out_pThumbUrl,				//[OUT]����ͼURL
	OUT		PNPC_BOOL							out_pIfEnable				//[OUT]�Ƿ�����
	);

//�ͷ�����ͼURL�б�
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_THUMB_ReleaseList(
	IN		NPC_HANDLE							in_hThumbUrlList			//[IN]����ͼURL�б���
	);

//�������������ͼURL�Ƿ����
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_THUMB_SetCameraThumbUrlIfEnable(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾��
	IN		PNPC_CHAR							in_pCameraId,				//[IN]�����ID
	IN		NPC_BOOL							in_bIfEnable				//[IN]�Ƿ�����
	);


//------------------------------------------------------------------------------------------------------
//ת��time_tʱ��ֵΪ�ַ���
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_SNH_Timet2Str(
	IN		NPC_TIME_T							in_tTimeValue,				//[IN]ʱ��ֵ
	OUT		PNPC_CHAR							out_pTimeStr				//[OUT]ʱ���ַ���
	);

//ת���ַ���ʱ��Ϊtime_t
NPC_MPI_MON_API		NPC_TIME_T	NPC_F_MPI_MON_SNH_Str2Timet(
	IN		PNPC_CHAR							in_pTimeStr					//[IN]ʱ���ַ���
	);


//-------------------------------------------------------------------------------------------
//����������Ϣ���շ���
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_AS_StartAlarmRecvServer(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]��������ַ
	IN		NPC_USHORT							in_usServerPort,			//[IN]�������˿ںţ���8300
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID
	IN		NPC_INT								in_iClientType,				//[IN]�ͻ������ͣ��μ�NPC_D_MON_CLIENT_TYPE_*����
	IN		PNPC_CHAR							in_pClientId,				//[IN]�ͻ���ID����ͻ��˱�ʶ����IMSI�ȣ�
	IN		PNPC_CHAR							in_pClientOwner,			//[IN]�ͻ���ʹ����
	IN		PNPC_CHAR							in_pClientLanguage,			//[IN]�ͻ������ԣ��磺Ӣ�ģ�English���������ģ�SimpChinese
	IN		PNPC_CHAR							in_pClientCustomFlag		//[IN]�ͻ��˶��Ʊ�ʶ
	);

//ֹͣ������Ϣ���շ���
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_AS_StopAlarmRecvServer(
	IN		NPC_HANDLE							in_hAlarmRecvServer			//[IN]������Ϣ���շ�����
	);

//��ȡ������Ϣ������TRUE��ʾ��������Ϣ��FALSE��ʾû��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_AS_GetAlarmMsg(
	IN		NPC_HANDLE							in_hAlarmRecvServer,		//[IN]������Ϣ���շ�����
	OUT		PNPC_S_MPI_MON_PUSH_MSG_DATA		out_pPushMsgData,			//[OUT]������Ϣ����
	IN		NPC_INT								in_iTimeout					//[IN]�ȴ���ʱʱ�������룩
	);

//��ѯ����������״̬
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_AS_QuerySrvConnState(
	IN		NPC_HANDLE							in_hAlarmRecvServer,		//[IN]������Ϣ���շ�����
	OUT		PNPC_INT							out_pSrvConnState			//[OUT]����������״̬��0��δ���ӣ�1���������ӣ�2��������
	);

//�Ƿ���Ҫ��ʾ������Ϣ��ȱʡΪ����ʾ
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_AS_IfShowInfoTraceInfo(
	IN		NPC_HANDLE							in_hAlarmRecvServer,		//[IN]������Ϣ���շ�����
	IN		NPC_BOOL							in_bIfShowTraceInfo			//[IN]�Ƿ���ʾ������Ϣ
	);



//----------------------------------------------------------------------------------------
//������ؿͻ��˲����ӷ���������Ҫ����NPC_F_MPI_MON_HNP_DestroyClient���ٿͻ��˶���
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_HNP_CreateClient(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]������IP��ַ������
	IN		NPC_USHORT							in_usServerPort,			//[IN]�������˿ںţ���8300
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID
	IN		NPC_INT								in_iClientType,				//[IN]�ͻ������ͣ��μ�NPC_D_MON_CLIENT_TYPE_*����
	IN		PNPC_CHAR							in_pClientId,				//[IN]�ͻ���ID
	OUT		PNPC_INT							out_pFailCode				//[OUT]ʧ���루�μ�NPC_D_MPI_MON_ERROR_*���壩������ֵΪNULLʱ���ò�����Ч
	);

//���ټ�ؿͻ��˶�����NPC_F_MPI_MON_HNP_CreateClient���������Ŀͻ��˶���
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_HNP_DestroyClient(
	IN		NPC_HANDLE							in_hMonClient				//[IN]�ͻ��˾��
	);


//�޸��û����룬����0��ʾ�ɹ���������ʾʧ�ܣ�ʧ����μ�NPC_D_MPI_MON_ERROR_*����
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_HNP_ModifyUserPwd(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾������NPC_F_MPI_MON_HNP_CreateClient�ú��������Ŀͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID�����û��ʺ�
	IN		PNPC_CHAR							in_pOldPwd,					//[IN]ԭ����
	IN		PNPC_CHAR							in_pNewPwd					//[IN]������
	);

//��ѯע���ʺŵ����䣬��ע��ʱ������֤������䣬����0��ʾ�ɹ���������ʾʧ�ܣ�ʧ����μ�NPC_D_MPI_MON_ERROR_*����
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_HNP_QueryRegEmail(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾������NPC_F_MPI_MON_HNP_CreateClient�ú��������Ŀͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID
	OUT		PNPC_CHAR							out_pRegEmail				//[OUT]ע������
	);

//�������������ʼ�������0��ʾ�ɹ���������ʾʧ�ܣ�ʧ����μ�NPC_D_MPI_MON_ERROR_*����
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_HNP_SendResetPasswordEmail(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]�ͻ��˾������NPC_F_MPI_MON_HNP_CreateClient�ú��������Ŀͻ��˾��
	IN		PNPC_CHAR							in_pUserId,					//[IN]�û�ID
	IN		PNPC_CHAR							in_pSendLanguage			//[IN]�������ԣ��磺Ӣ�ģ�English���������ģ�SimpChinese
	);


// C++ support
#ifdef __cplusplus
}
#endif

#endif

