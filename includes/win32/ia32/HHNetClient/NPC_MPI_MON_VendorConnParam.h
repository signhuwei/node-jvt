/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_VendorConnParam.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-26
 * Description   :  �豸���̵����Ӳ�������ͽ���ģ��
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_VENDORCONNPARAM_H
#define __NPC_MPI_MON_VENDORCONNPARAM_H

#include "NPC_TypeDef.h"
#include "NPC_MPI_MON_DataDef.h"


//--------------------ͨ�����Ӳ������úͻ�ȡ----------------------------------------------------------
//����ͨ�����Ӳ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_General_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		NPC_INT								in_iVendorId,				//����ID
	IN		PNPC_CHAR							in_pDevIpAddr,				//�豸IP��ַ
	IN		NPC_USHORT							in_usDevPort,				//�豸�˿ں�
	IN		PNPC_CHAR							in_pUserName,				//�豸�û���
	IN		PNPC_CHAR							in_pUserPwd,				//�豸��¼����
	IN		NPC_INT								in_iChNo					//�豸ͨ���Ż�ID��
	);

//��ȡͨ�����Ӳ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_General_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_INT							out_pVendorId,				//����ID
	OUT		PNPC_CHAR							out_pDevAddr,				//�豸��ַ
	IN		NPC_INT								in_iDevAddrBufSize,			//�豸��ַ��������С
	OUT		PNPC_USHORT							out_pDevPort,				//�豸�˿ں�
	OUT		PNPC_CHAR							out_pUserName,				//�豸�û���
	IN		NPC_INT								in_iUserNameBufSize,		//�豸�û�����������С
	OUT		PNPC_CHAR							out_pUserPwd,				//�豸��¼����
	IN		NPC_INT								in_iUserPwdBufSize,			//�豸��¼���뻺������С
	OUT		PNPC_INT							out_pChNo					//�豸ͨ���Ż�ID��
	);


//--------------------ͨ�����Ӳ������úͻ�ȡ����չ��----------------------------------------------------------
//����ͨ�����Ӳ�������չ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_General_SetConnParamEx(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		NPC_INT								in_iVendorId,				//����ID
	IN		PNPC_CHAR							in_pDevIpAddr,				//�豸IP��ַ
	IN		NPC_USHORT							in_usDevPort,				//�豸�˿ں�
	IN		PNPC_CHAR							in_pUserName,				//�豸�û���
	IN		PNPC_CHAR							in_pUserPwd,				//�豸��¼����
	IN		NPC_INT								in_iChNo,					//�豸ͨ���Ż�ID��
	IN		NPC_INT								in_iStreamNo				//�豸�����ţ�0����������1��������
	);

//��ȡͨ�����Ӳ�������չ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_General_GetConnParamEx(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_INT							out_pVendorId,				//����ID
	OUT		PNPC_CHAR							out_pDevAddr,				//�豸��ַ
	IN		NPC_INT								in_iDevAddrBufSize,			//�豸��ַ��������С
	OUT		PNPC_USHORT							out_pDevPort,				//�豸�˿ں�
	OUT		PNPC_CHAR							out_pUserName,				//�豸�û���
	IN		NPC_INT								in_iUserNameBufSize,		//�豸�û�����������С
	OUT		PNPC_CHAR							out_pUserPwd,				//�豸��¼����
	IN		NPC_INT								in_iUserPwdBufSize,			//�豸��¼���뻺������С
	OUT		PNPC_INT							out_pChNo,					//�豸ͨ���Ż�ID��
	OUT		PNPC_INT							out_pStreamNo				//�豸�����ţ�0����������1��������
	);


//--------------------ͨ��P2P���Ӳ������úͻ�ȡ----------------------------------------------------------
//����ͨ��P2P���Ӳ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_P2PGeneral_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		NPC_INT								in_iVendorId,				//����ID
	IN		PNPC_CHAR							in_pNetAgentDevId,			//��������豸ID
	IN		PNPC_CHAR							in_pDevIpAddr,				//�豸IP��ַ
	IN		NPC_USHORT							in_usDevPort,				//�豸�˿ں�
	IN		PNPC_CHAR							in_pUserName,				//�豸�û���
	IN		PNPC_CHAR							in_pUserPwd,				//�豸��¼����
	IN		NPC_INT								in_iChNo,					//�豸ͨ���Ż�ID��
	IN		NPC_INT								in_iSubStream				//�������ţ�0����������1��������1������
	);

//��ȡͨ��P2P���Ӳ���
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_P2PGeneral_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_INT							out_pVendorId,				//����ID
	OUT		PNPC_CHAR							out_pNetAgentDevId,			//��������豸ID
	IN		NPC_INT								in_iNetAgentDevIdBufSize,	//��������豸ID��������С
	OUT		PNPC_CHAR							out_pDevAddr,				//�豸��ַ��������IP��ַ��
	IN		NPC_INT								in_iDevAddrBufSize,			//�豸��ַ��������С
	OUT		PNPC_USHORT							out_pDevPort,				//�豸�˿ں�
	OUT		PNPC_CHAR							out_pUserName,				//�豸�û���
	IN		NPC_INT								in_iUserNameBufSize,		//�豸�û�����������С
	OUT		PNPC_CHAR							out_pUserPwd,				//�豸��¼����
	IN		NPC_INT								in_iUserPwdBufSize,			//�豸��¼���뻺������С
	OUT		PNPC_INT							out_pChNo,					//�豸ͨ���Ż�ID��
	OUT		PNPC_INT							out_pSubStream				//�������ţ�0����������1��������1������
	);


//------------------------------------------------------------------------------
//�������Ӳ�����������ý�������Э�飨HKSP��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HKSP_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pSrvIpAddr,				//��ý�������IP��ַ
	IN		NPC_USHORT							in_usSrvPort,				//��ý��������˿ں�
	IN		PNPC_CHAR							in_pUserName,				//��ý��������û���
	IN		PNPC_CHAR							in_pUserPwd,				//��ý���������¼����
	IN		NPC_INT								in_iACQID					//�������ACQID
	);

//��ȡ���Ӳ�����������ý�������Э�飨HKSP��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HKSP_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pSrvIpAddr,				//��ý�������IP��ַ
	IN		NPC_INT								in_iSrvIpAddrBufSize,		//��ý�������IP��ַ��������С
	OUT		PNPC_USHORT							out_pSrvPort,				//��ý��������˿ں�
	OUT		PNPC_CHAR							out_pUserName,				//��ý��������û���
	IN		NPC_INT								in_iUserNameBufSize,		//��ý��������û�����������С
	OUT		PNPC_CHAR							out_pUserPwd,				//��ý���������¼����
	IN		NPC_INT								in_iUserPwdBufSize,			//��ý���������¼���뻺������С
	OUT		PNPC_INT							out_pACQID					//�������ACQID
	);


//------------------------------------------------------------------------------
//�������Ӳ������ɶ�������CDSB��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_CDSB_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pSrvIpAddr,				//������ý�������IP��ַ
	IN		NPC_USHORT							in_usSrvPort,				//������ý��������˿ں�
	IN		PNPC_CHAR							in_pUserName,				//������ý��������û���
	IN		PNPC_CHAR							in_pUserPwd,				//������ý���������¼����
	IN		NPC_INT								in_iDevId					//�豸ID��
	);

//��ȡ���Ӳ������ɶ�������CDSB��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_CDSB_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pSrvIpAddr,				//������ý�������IP��ַ
	OUT		PNPC_USHORT							out_pSrvPort,				//������ý��������˿ں�
	OUT		PNPC_CHAR							out_pUserName,				//������ý��������û���
	OUT		PNPC_CHAR							out_pUserPwd,				//������ý���������¼����
	OUT		PNPC_INT							out_pDevId					//�豸ID��
	);


//------------------------------------------------------------------------------
//�������Ӳ������ļ��������FCAM��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_FCAM_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pDirName,				//Ŀ¼��
	IN		NPC_INT								in_iChNo					//�豸ͨ����
	);

//��ȡ���Ӳ������ļ��������FCAM��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_FCAM_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pDirName,				//Ŀ¼��
	OUT		PNPC_INT							out_pChNo					//�豸ͨ����
	);


//------------------------------------------------------------------------------
//�������Ӳ��������Ƽ��ͨѶЭ�飨HMCP��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HMCP_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pDevIpAddr,				//�豸IP��ַ��Ŀ¼��
	IN		NPC_USHORT							in_usDevPort,				//�豸�˿ں�
	IN		PNPC_CHAR							in_pUserName,				//�豸�û���
	IN		PNPC_CHAR							in_pUserPwd,				//�豸��¼����
	IN		NPC_INT								in_iChNo					//�豸ͨ����
	);

//��ȡ���Ӳ��������Ƽ��ͨѶЭ�飨HMCP��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HMCP_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pDevIpAddr,				//�豸IP��ַ��Ŀ¼��
	OUT		PNPC_USHORT							out_pDevPort,				//�豸�˿ں�
	OUT		PNPC_CHAR							out_pUserName,				//�豸�û���
	OUT		PNPC_CHAR							out_pUserPwd,				//�豸��¼����
	OUT		PNPC_INT							out_pChNo					//�豸ͨ����
	);



//------------------------------------------------------------------------------
//�������Ӳ�����������ý��Э�飨OWSP��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_OWSP_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		NPC_INT								in_iDevId,					//�豸ID
	IN		NPC_INT								in_iChNo					//ͨ����
	);

//��ȡ���Ӳ�����������ý��Э�飨OWSP��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_OWSP_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_INT							out_pDevId,					//�豸ID
	OUT		PNPC_INT							out_pChNo					//ͨ����
	);


//------------------------------------------------------------------------------
//�������Ӳ����������豸����Э�飨HDTP��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HDTP_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pDevId,					//�豸ID
	IN		PNPC_CHAR							in_pDevPwd,					//�豸����
	IN		NPC_INT								in_iChNo					//ͨ����
	);

//��ȡ���Ӳ����������豸����Э�飨HDTP��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HDTP_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pDevId,					//�豸ID
	OUT		PNPC_CHAR							out_pDevPwd,				//�豸����
	OUT		PNPC_INT							out_pChNo					//ͨ����
	);


//------------------------------------------------------------------------------
//�������Ӳ����������豸����Э�飨HDTP������չ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HDTP_SetConnParamEx(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pDevId,					//�豸ID
	IN		PNPC_CHAR							in_pDevUser,				//�豸�û���
	IN		PNPC_CHAR							in_pDevPwd,					//�豸����
	IN		NPC_INT								in_iChNo,					//ͨ����
	IN		NPC_INT								in_iStreamNo				//������0����������1��������
	);

//��ȡ���Ӳ����������豸����Э�飨HDTP������չ��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HDTP_GetConnParamEx(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pDevId,					//�豸ID
	OUT		PNPC_CHAR							out_pDevUser,				//�豸�û���
	OUT		PNPC_CHAR							out_pDevPwd,				//�豸����
	OUT		PNPC_INT							out_pChNo,					//ͨ����
	OUT		PNPC_INT							out_pStreamNo				//������0����������1��������
	);


//------------------------------------------------------------------------------
//�������Ӳ������Ϻ�ͨ����SHTL��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_SHTL_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pDevIpAddr,				//�豸IP��ַ
	IN		NPC_USHORT							in_usDevPort,				//�豸�˿ں�
	IN		PNPC_CHAR							in_pUserName,				//�豸�û���
	IN		PNPC_CHAR							in_pUserPwd,				//�豸��¼����
	IN		NPC_INT								in_iChNo,					//�豸ͨ����
	IN		PNPC_CHAR							in_pDevId					//�豸ID
	);

//��ȡ���Ӳ������Ϻ�ͨ����SHTL��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_SHTL_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pDevIpAddr,				//�豸IP��ַ
	OUT		PNPC_USHORT							out_pDevPort,				//�豸�˿ں�
	OUT		PNPC_CHAR							out_pUserName,				//�豸�û���
	OUT		PNPC_CHAR							out_pUserPwd,				//�豸��¼����
	OUT		PNPC_INT							out_pChNo,					//�豸ͨ����
	OUT		PNPC_CHAR							out_pDevId					//�豸ID
	);


//------------------------------------------------------------------------------
//�������Ӳ��������ݺ�����ģʽ��HKPU��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HKPU_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pDevId,					//�豸ID
	IN		NPC_INT								in_iChNo					//�豸ͨ����
	);

//��ȡ���Ӳ��������ݺ�����ģʽ��HKPU��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HKPU_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pDevId,					//�豸ID
	OUT		PNPC_INT							out_pChNo					//�豸ͨ����
	);


//------------------------------------------------------------------------------
//�������Ӳ�����P2P�˵����EPMY��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_EPMY_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pDevId,					//�豸ID���豸UMID��
	IN		NPC_INT								in_iIfConnDestAddr,			//�Ƿ�ʹ��Ŀ���ַ���ӣ�0����ʹ�ã�1��ʹ��
	IN		PNPC_CHAR							in_pDestIpaddr,				//Ŀ��IP��ַ���豸�����ӵ�IP��ַ����in_iIfConnDestAddr����Ϊ1ʱ��Ч
	IN		NPC_USHORT							in_usDestPort,				//Ŀ��˿ں�
	IN		NPC_INT								in_iConnDestChNo,			//���ӵ�Ŀ��ͨ���ţ����Ϊ0����Ϊȱʡͨ���ţ�in_iIfConnDestAddr����Ϊ0ʱ��Ч
	IN		NPC_USHORT							in_usPort					//�˿ں�
	);

//��ȡ���Ӳ�����P2P�˵����EPMY��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_EPMY_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pDevId,					//�豸ID���豸UMID��
	OUT		PNPC_INT							out_pIfConnDestAddr,		//�Ƿ�ʹ��Ŀ���ַ���ӣ�0����ʹ�ã�1��ʹ��
	OUT		PNPC_CHAR							out_pDestIpaddr,			//Ŀ��IP��ַ���豸�����ӵ�IP��ַ����in_iIfConnDestAddr����Ϊ1ʱ��Ч
	OUT		PNPC_USHORT							out_pDestPort,				//Ŀ��˿ں�
	OUT		PNPC_INT							out_pConnDestChNo,			//���ӵ�Ŀ��ͨ���ţ����Ϊ0����Ϊȱʡͨ���ţ�in_iIfConnDestAddr����Ϊ0ʱ��Ч
	OUT		PNPC_USHORT							out_pPort					//�˿ں�
	);


//------------------------------------------------------------------------------
//�������Ӳ����������ɳۣ����кţ���SZLC��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_SZLC_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//���Ӳ�������������������СΪNPC_D_MON_DEV_CONN_PARAM_BUFSIZE�����С
	IN		PNPC_CHAR							in_pDevId,					//�豸ID
	IN		NPC_INT								in_iChNo					//�豸ͨ����
	);

//��ȡ���Ӳ����������ɳۣ����кţ���SZLC��
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_SZLC_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//���Ӳ���������
	OUT		PNPC_CHAR							out_pDevId,					//�豸ID
	OUT		PNPC_INT							out_pChNo					//�豸ͨ����
	);


#endif

