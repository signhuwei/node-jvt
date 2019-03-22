/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MEM_Manager.cpp
 * Version       :  1.1
 * Author        :  CCH
 * DateTime      :  2011-07-20
 * Description   :  NPC系统内存管理模块
 *----------------------------------------------------------------------------*/

#include "NPC_MEM_Manager.h"


//--------------------------------------------------------------------------------
//向缓冲区添加数据
NPC_BOOL	NPC_F_MEM_MG_AddDataToBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pDataBufSize,			//数据缓冲区大小
	IN		PNPC_INT						in_pSjDataLen,				//实际数据长度
	IN		PNPC_BYTE						in_pAddDataPos,				//添加数据指针
	IN		NPC_INT							in_iAddDataLen				//添加数据长度
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

//设置数据到缓冲区中
NPC_BOOL	NPC_F_MEM_MG_SetDataToBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pDataBufSize,			//数据缓冲区大小
	IN		PNPC_INT						in_pSjDataLen,				//实际数据长度
	IN		PNPC_BYTE						in_pSetDataPos,				//设置数据指针
	IN		NPC_INT							in_iSetDataLen				//设置数据长度
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

//分配指定内存空间
NPC_BOOL	NPC_F_MEM_MG_AllocDataBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pDataBufSize,			//数据缓冲区大小
	IN		NPC_INT							in_iAllocDataLen			//分配数据长度
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

//扩展内存空间（保留原有数据）
NPC_BOOL	NPC_F_MEM_MG_ExpandDataBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pDataBufSize,			//数据缓冲区大小
	IN		NPC_INT							in_iOldDataLen,				//原数据长度
	IN		NPC_INT							in_iLastBufSize				//最终内存大小
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

//缓存区内部拷贝
NPC_BOOL	NPC_F_MEM_MG_BufInsideCopy(
	IN		PNPC_BYTE						in_pDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pOldDataLen,				//数据原长度，返回拷贝后的剩余数据长度
	IN		NPC_INT							in_iCutLen					//截断长度
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


