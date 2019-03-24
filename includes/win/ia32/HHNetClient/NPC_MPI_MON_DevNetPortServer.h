/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_DevNetPortServer.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-07-18
 * Description   :  �豸����˿�ӳ�����ģ��
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_DEVNETPORTSERVER_H
#define __NPC_MPI_MON_DEVNETPORTSERVER_H

#include "NPC_TypeDef.h"

//�������붨��
#ifdef _WIN32
	#ifdef _NPC_MPI_MON_DNP_EXPORTS
		#define NPC_MPI_MON_DNP_API __declspec(dllexport)
	#else
		#ifdef _NPC_MPI_MON_DNP_IMPORT
			#define NPC_MPI_MON_DNP_API __declspec(dllimport)
		#else
			#define NPC_MPI_MON_DNP_API
		#endif
	#endif
#else
	#define NPC_MPI_MON_DNP_API
#endif


// C++ support
#ifdef __cplusplus
extern "C"
{
#endif


//----------------------------------------------------------------------------------------
//�����豸����˿�ӳ�����
NPC_MPI_MON_DNP_API		NPC_HANDLE	NPC_F_MPI_MON_DNP_CreateDevNetPortServer(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]������IP��ַ������
	IN		NPC_USHORT							in_usServerPort,			//[IN]�������˿ں�
	IN		PNPC_CHAR							in_pAuthId,					//[IN]��֤ID
	IN		PNPC_CHAR							in_pAuthPwd					//[IN]��֤����
	);

//�����豸����˿�ӳ�����
NPC_MPI_MON_DNP_API		NPC_VOID	NPC_F_MPI_MON_DNP_DestroyDevNetPortServer(
	IN		NPC_HANDLE							in_hDevNetPort				//[IN]�豸����˿�
	);

//���ӳ��˿ڣ�����ֵ��0���ɹ�������ʧ��
//ʧ���룺
//7���ȴ���¼��������ʱ
//8�����ҿ���TCP�����˿�ʧ��
//9����������
//600001���������Ӳ���ʧ��
//600002����������ʧ��
//600004������ӳ��˿�ʧ��
//600009����������
//630001��Э������ϵͳ����ʧ��
//630002�������豸ʧ��
//630004��������Դʧ��
//630006�����ʷ�����ʧ�ܣ����ʳ�ʱ�����ӶϿ������������ʧ�ܣ�
//630009������ԭ��ʧ��
//630101���û�������
//630102���������
//630104���������ӷ�����
//630105��δ���ӷ�����
//630111��Ȩ�޲���
//630112���豸����
NPC_MPI_MON_DNP_API		NPC_INT		NPC_F_MPI_MON_DNP_AddPort(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]�豸����˿�
	IN		PNPC_CHAR							in_pUmid,					//[IN]UMID
	INOUT	PNPC_USHORT							inout_pLocalPort,			//[INOUT]���ض˿ںţ����ֵΪ0������ϵͳ����˿ں�
	IN		NPC_INT								in_iTimeout=20000			//[IN]��ʱʱ�������룩
	);

//���ӳ��˿ڣ�����Ŀ���ַ��������ֵ��0���ɹ�������ʧ��
//ʧ���룺
//7���ȴ���¼��������ʱ
//8�����ҿ���TCP�����˿�ʧ��
//9����������
//600001���������Ӳ���ʧ��
//600002����������ʧ��
//600004������ӳ��˿�ʧ��
//600009����������
//630001��Э������ϵͳ����ʧ��
//630002�������豸ʧ��
//630004��������Դʧ��
//630006�����ʷ�����ʧ�ܣ����ʳ�ʱ�����ӶϿ������������ʧ�ܣ�
//630009������ԭ��ʧ��
//630101���û�������
//630102���������
//630104���������ӷ�����
//630105��δ���ӷ�����
//630111��Ȩ�޲���
//630112���豸����
NPC_MPI_MON_DNP_API		NPC_INT		NPC_F_MPI_MON_DNP_AddPortByDestAddr(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]�豸����˿�
	IN		PNPC_CHAR							in_pUmid,					//[IN]UMID
	IN		PNPC_CHAR							in_pDestIpaddr,				//[IN]Ŀ��IP��ַ���豸�����ӵ�IP��ַ��
	IN		NPC_USHORT							in_usDestPort,				//[IN]Ŀ��˿ں�
	INOUT	PNPC_USHORT							inout_pLocalPort,			//[INOUT]���ض˿ںţ����ֵΪ0������ϵͳ����˿ں�
	IN		NPC_INT								in_iTimeout=20000			//[IN]��ʱʱ�������룩
	);

//���ӳ��˿ڣ�����ָ��ͨ����������ֵ��0���ɹ�������ʧ��
//ʧ���룺
//7���ȴ���¼��������ʱ
//8�����ҿ���TCP�����˿�ʧ��
//9����������
//600001���������Ӳ���ʧ��
//600002����������ʧ��
//600004������ӳ��˿�ʧ��
//600009����������
//630001��Э������ϵͳ����ʧ��
//630002�������豸ʧ��
//630004��������Դʧ��
//630006�����ʷ�����ʧ�ܣ����ʳ�ʱ�����ӶϿ������������ʧ�ܣ�
//630009������ԭ��ʧ��
//630101���û�������
//630102���������
//630104���������ӷ�����
//630105��δ���ӷ�����
//630111��Ȩ�޲���
//630112���豸����
NPC_MPI_MON_DNP_API		NPC_INT		NPC_F_MPI_MON_DNP_AddPortByChNo(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]�豸����˿�
	IN		PNPC_CHAR							in_pUmid,					//[IN]UMID
	IN		NPC_INT								in_iDestChNo,				//[IN]Ŀ��ͨ���ţ�0Ϊȱʡͨ����
	INOUT	PNPC_USHORT							inout_pLocalPort,			//[INOUT]���ض˿ںţ����ֵΪ0������ϵͳ����˿ں�
	IN		NPC_INT								in_iTimeout=20000			//[IN]��ʱʱ�������룩
	);

//ɾ��ӳ��˿�
NPC_MPI_MON_DNP_API		NPC_VOID	NPC_F_MPI_MON_DNP_DelPort(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]�豸����˿�
	IN		NPC_USHORT							in_usLocalPort				//[IN]���ض˿ں�
	);


//----------------------------------------------------------------------------------------
//������������״̬�����أ�0��δ���ӣ�1���������ӣ�2�������ӣ�����9��ʾ����
NPC_MPI_MON_DNP_API		NPC_INT		NPC_F_MPI_MON_DNP_CheckSrvConnState(
	IN		NPC_HANDLE							in_hDevNetPort				//[IN]�豸����˿�
	);


//----------------------------------------------------------------------------------------
//����豸״̬��ѯ�б�
NPC_MPI_MON_DNP_API		NPC_VOID	NPC_F_MPI_MON_DNP_DevState_ClearList(
	IN		NPC_HANDLE							in_hDevNetPort				//[IN]�豸����˿�
	);

//��Ӳ�ѯ�豸
NPC_MPI_MON_DNP_API		NPC_BOOL	NPC_F_MPI_MON_DNP_DevState_AddDev(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]�豸����˿�
	IN		PNPC_CHAR							in_pDevUmid					//[IN]�豸UMID
	);

//�����ѯ�豸״̬�������������ѯ�豸״̬����С��������ѯ���ɣ�
NPC_MPI_MON_DNP_API		NPC_BOOL	NPC_F_MPI_MON_DNP_DevState_RequQueryDevState(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]�豸����˿�
	OUT		PNPC_INT							out_pQueryDevSpaceTime,		//[OUT]��ѯ�豸״̬�ļ��ʱ�䣨�룩
	IN		NPC_INT								in_iTimeout					//[IN]��ʱʱ�������룩
	);

//��ȡ�豸״̬���ڲ�ѯ�б��л�ȡ״̬��
NPC_MPI_MON_DNP_API		NPC_BOOL	NPC_F_MPI_MON_DNP_DevState_GetDevState(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]�豸����˿�
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]�豸UMID
	OUT		PNPC_INT							out_pDevState				//[OUT]�豸״̬��0�����ߣ�1������
	);


//----------------------------------------------------------------------------------------
//��ȡ��־�������Ϣ���ײ�ά��һ����־���У�����������־������ö����У����øú������Ӹö���ȡ����־�������ú�����ɾ�����е����ݣ�
//�����ʱ�䲻���ã��ײ㽫ɾ���������־��Ĭ����󱣴�100����־
NPC_MPI_MON_DNP_API		NPC_BOOL	NPC_F_MPI_MON_DNP_GetLogData(
	IN		NPC_INT								in_iLogBufSize,				//[IN]��־��Ϣ��������С
	OUT		PNPC_INT							out_pLogInfoType,			//[OUT]��־���ͣ��μ�NPC_D_MON_LOG_INFO_TYPE_*����
	OUT		PNPC_CHAR							out_pLogBuf,				//[OUT]��־��Ϣ�������������߷����ڴ�
	IN		NPC_INT								in_iTimeout					//[IN]��ʱʱ�������룩
	);


// C++ support
#ifdef __cplusplus
}
#endif

#endif
