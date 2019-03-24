/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MEM_Manager.cpp
 * Version       :  1.1
 * Author        :  CCH
 * DateTime      :  2011-07-20
 * Description   :  NPCϵͳ�ڴ����ģ��
 *----------------------------------------------------------------------------*/

#include "NPC_MEM_Manager.h"


//--------------------------------------------------------------------------------
//�򻺳����������
NPC_BOOL	NPC_F_MEM_MG_AddDataToBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pDataBufSize,			//���ݻ�������С
	IN		PNPC_INT						in_pSjDataLen,				//ʵ�����ݳ���
	IN		PNPC_BYTE						in_pAddDataPos,				//�������ָ��
	IN		NPC_INT							in_iAddDataLen				//������ݳ���
	)
{
	NPC_INT									iLastDataLen;
	PNPC_BYTE								pNewBuf;

	if ( in_ppDataBuf == NULL || 
		in_pDataBufSize == NULL || 
		in_pSjDataLen == NULL || 
		in_pAddDataPos == NULL || 
		*in_pSjDataLen < 0 || 
		in_iAddDataLen <= 0 )
	{
		return FALSE;
	}

	iLastDataLen = *in_pSjDataLen + in_iAddDataLen;

	if ( *in_ppDataBuf == NULL || 
		*in_pDataBufSize < iLastDataLen )
	{
		pNewBuf = (PNPC_BYTE)malloc(iLastDataLen);
		if ( pNewBuf == NULL )
		{
			return FALSE;
		}

		if ( *in_ppDataBuf )
		{
			if ( *in_pSjDataLen > 0 )
				memcpy(pNewBuf, *in_ppDataBuf, *in_pSjDataLen);

			free(*in_ppDataBuf);
			*in_ppDataBuf = NULL;
		}

		*in_ppDataBuf = pNewBuf;
		*in_pDataBufSize = iLastDataLen;

		pNewBuf = NULL;
	}

	memcpy(*in_ppDataBuf+*in_pSjDataLen, in_pAddDataPos, in_iAddDataLen);
	*in_pSjDataLen += in_iAddDataLen;

	return TRUE;
}

//�������ݵ���������
NPC_BOOL	NPC_F_MEM_MG_SetDataToBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pDataBufSize,			//���ݻ�������С
	IN		PNPC_INT						in_pSjDataLen,				//ʵ�����ݳ���
	IN		PNPC_BYTE						in_pSetDataPos,				//��������ָ��
	IN		NPC_INT							in_iSetDataLen				//�������ݳ���
	)
{
	PNPC_BYTE								pTempBuf;

	if ( in_ppDataBuf == NULL || 
		in_pDataBufSize == NULL || 
		in_pSjDataLen == NULL || 
		in_pSetDataPos == NULL || 
		in_iSetDataLen <= 0 )
	{
		return FALSE;
	}

	if ( *in_ppDataBuf == NULL || 
		*in_pDataBufSize < in_iSetDataLen )
	{
		pTempBuf = (PNPC_BYTE)malloc(in_iSetDataLen);
		if ( pTempBuf == NULL )
		{
			return FALSE;
		}

		if ( *in_ppDataBuf )
		{
			free(*in_ppDataBuf);
			*in_ppDataBuf = NULL;
		}

		*in_ppDataBuf = pTempBuf;
		*in_pDataBufSize = in_iSetDataLen;
	}

	memcpy(*in_ppDataBuf, in_pSetDataPos, in_iSetDataLen);
	*in_pSjDataLen = in_iSetDataLen;

	return TRUE;
}

//����ָ���ڴ�ռ�
NPC_BOOL	NPC_F_MEM_MG_AllocDataBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pDataBufSize,			//���ݻ�������С
	IN		NPC_INT							in_iAllocDataLen			//�������ݳ���
	)
{
	PNPC_BYTE								pTempBuf;

	if ( in_ppDataBuf == NULL || 
		in_pDataBufSize == NULL || 
		in_iAllocDataLen < 0 )
	{
		return FALSE;
	}

	if ( *in_ppDataBuf == NULL || 
		*in_pDataBufSize < in_iAllocDataLen )
	{
		pTempBuf = (PNPC_BYTE)malloc(in_iAllocDataLen);
		if ( pTempBuf == NULL )
		{
			return FALSE;
		}

		if ( *in_ppDataBuf )
		{
			free(*in_ppDataBuf);
			*in_ppDataBuf = NULL;
		}

		*in_ppDataBuf = pTempBuf;
		*in_pDataBufSize = in_iAllocDataLen;
	}

	memset(*in_ppDataBuf, 0, in_iAllocDataLen);

	return TRUE;
}

//��չ�ڴ�ռ䣨����ԭ�����ݣ�
NPC_BOOL	NPC_F_MEM_MG_ExpandDataBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pDataBufSize,			//���ݻ�������С
	IN		NPC_INT							in_iOldDataLen,				//ԭ���ݳ���
	IN		NPC_INT							in_iLastBufSize				//�����ڴ��С
	)
{
	PNPC_BYTE								pNewBuf;

	if ( in_ppDataBuf == NULL || 
		in_pDataBufSize == NULL || 
		*in_pDataBufSize < 0 || 
		in_iOldDataLen < 0 || 
		in_iLastBufSize <= 0 )
	{
		return FALSE;
	}

	if ( *in_ppDataBuf == NULL || 
		*in_pDataBufSize < in_iLastBufSize )
	{
		pNewBuf = (PNPC_BYTE)malloc(in_iLastBufSize);
		if ( pNewBuf == NULL )
			return FALSE;

		if ( *in_ppDataBuf )
		{
			if ( in_iOldDataLen > 0 )
				memcpy(pNewBuf, *in_ppDataBuf, in_iOldDataLen);

			free(*in_ppDataBuf);
			*in_ppDataBuf = NULL;
		}

		*in_ppDataBuf = pNewBuf;
		*in_pDataBufSize = in_iLastBufSize;

		pNewBuf = NULL;
	}

	if ( in_iLastBufSize - in_iOldDataLen > 0 )
		memset(*in_ppDataBuf + in_iOldDataLen, 0, in_iLastBufSize - in_iOldDataLen);

	return TRUE;
}

//�������ڲ�����
NPC_BOOL	NPC_F_MEM_MG_BufInsideCopy(
	IN		PNPC_BYTE						in_pDataBuf,				//���ݻ�����ָ��
	IN		PNPC_INT						in_pOldDataLen,				//����ԭ���ȣ����ؿ������ʣ�����ݳ���
	IN		NPC_INT							in_iCutLen					//�ضϳ���
	)
{
	if ( in_pDataBuf == NULL || in_pOldDataLen == NULL || *in_pOldDataLen <= 0 || in_iCutLen <= 0 )
		return FALSE;

	*in_pOldDataLen -= in_iCutLen;
	if ( *in_pOldDataLen > 0 )
	{
		if ( *in_pOldDataLen <= in_iCutLen )
		{
			memcpy(in_pDataBuf, in_pDataBuf+in_iCutLen, *in_pOldDataLen);
		}
		else
		{
			memcpy(in_pDataBuf, in_pDataBuf+in_iCutLen, in_iCutLen);
			memcpy(in_pDataBuf+in_iCutLen, in_pDataBuf+in_iCutLen+in_iCutLen, *in_pOldDataLen - in_iCutLen);
		}
	}
	else
		*in_pOldDataLen = 0;

	return TRUE;
}


