/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MEM_Manager.h
 * Version       :  1.1
 * Author        :  CCH
 * DateTime      :  2011-07-20
 * Description   :  NPCϵͳ�ڴ����ģ��
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MEM_MANAGER_H
#define __NPC_MEM_MANAGER_H

#include "NPC_TypeDef.h"


//--------------------------------------------------------------------------------
//�򻺳����������
NPC_BOOL	NPC_F_MEM_MG_AddDataToBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pDataBufSize,			//���ݻ�������С
	IN		PNPC_INT						in_pSjDataLen,				//ʵ�����ݳ���
	IN		PNPC_BYTE						in_pAddDataPos,				//�������ָ��
	IN		NPC_INT							in_iAddDataLen				//������ݳ���
	);

//�������ݵ���������
NPC_BOOL	NPC_F_MEM_MG_SetDataToBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pDataBufSize,			//���ݻ�������С
	IN		PNPC_INT						in_pSjDataLen,				//ʵ�����ݳ���
	IN		PNPC_BYTE						in_pSetDataPos,				//��������ָ��
	IN		NPC_INT							in_iSetDataLen				//�������ݳ���
	);

//����ָ���ڴ�ռ�
NPC_BOOL	NPC_F_MEM_MG_AllocDataBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pDataBufSize,			//���ݻ�������С
	IN		NPC_INT							in_iAllocDataLen			//�������ݳ���
	);

//��չ�ڴ�ռ䣨����ԭ�����ݣ�
NPC_BOOL	NPC_F_MEM_MG_ExpandDataBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pDataBufSize,			//���ݻ�������С
	IN		NPC_INT							in_iOldDataLen,				//ԭ���ݳ���
	IN		NPC_INT							in_iLastBufSize				//�����ڴ��С
	);

//�������ڲ�����
NPC_BOOL	NPC_F_MEM_MG_BufInsideCopy(
	IN		PNPC_BYTE						in_pDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pOldDataLen,				//����ԭ���ȣ����ؿ������ʣ�����ݳ���
	IN		NPC_INT							in_iCutLen					//�ضϳ���
	);


#endif

