/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MEM_Manager.h
 * Version       :  1.1
 * Author        :  CCH
 * DateTime      :  2011-07-20
 * Description   :  NPC系统内存管理模块
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MEM_MANAGER_H
#define __NPC_MEM_MANAGER_H

#include "NPC_TypeDef.h"


//--------------------------------------------------------------------------------
//向缓冲区添加数据
NPC_BOOL	NPC_F_MEM_MG_AddDataToBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pDataBufSize,			//数据缓冲区大小
	IN		PNPC_INT						in_pSjDataLen,				//实际数据长度
	IN		PNPC_BYTE						in_pAddDataPos,				//添加数据指针
	IN		NPC_INT							in_iAddDataLen				//添加数据长度
	);

//设置数据到缓冲区中
NPC_BOOL	NPC_F_MEM_MG_SetDataToBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pDataBufSize,			//数据缓冲区大小
	IN		PNPC_INT						in_pSjDataLen,				//实际数据长度
	IN		PNPC_BYTE						in_pSetDataPos,				//设置数据指针
	IN		NPC_INT							in_iSetDataLen				//设置数据长度
	);

//分配指定内存空间
NPC_BOOL	NPC_F_MEM_MG_AllocDataBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pDataBufSize,			//数据缓冲区大小
	IN		NPC_INT							in_iAllocDataLen			//分配数据长度
	);

//扩展内存空间（保留原有数据）
NPC_BOOL	NPC_F_MEM_MG_ExpandDataBuf(
	IN		PNPC_BYTE*						in_ppDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pDataBufSize,			//数据缓冲区大小
	IN		NPC_INT							in_iOldDataLen,				//原数据长度
	IN		NPC_INT							in_iLastBufSize				//最终内存大小
	);

//缓存区内部拷贝
NPC_BOOL	NPC_F_MEM_MG_BufInsideCopy(
	IN		PNPC_BYTE						in_pDataBuf,				//数据缓冲区指针
	IN		PNPC_INT						in_pOldDataLen,				//数据原长度，返回拷贝后的剩余数据长度
	IN		NPC_INT							in_iCutLen					//截断长度
	);


#endif

