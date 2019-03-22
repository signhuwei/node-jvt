/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MIT_DataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2013-01-12
 * Description   :  多层索引表模块
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MIT_DATADEF_H
#define __NPC_MIT_DATADEF_H

#include "NPC_TypeDef.h"


//-----------------------------------------------------------------------------------
//数据ID结构
typedef struct _NPC_S_MIT_DATAID_FRAME
{
	NPC_BYTE								ucThreeIndex;						//三级索引号
	NPC_BYTE								ucTwoIndex;							//二级索引号
	NPC_BYTE								ucOneIndex;							//一级索引号
	NPC_BYTE								ucAuthCode;							//认证码

} NPC_S_MIT_DATAID_FRAME, *PNPC_S_MIT_DATAID_FRAME;


//-----------------------------------------------------------------------------------
//三级索引
typedef struct _NPC_S_MIT_THREE_INDEX_DATA
{
	NPC_DWORD								dwDataId;							//数据ID
	PNPC_BYTE								pDataPos;							//数据指针

} NPC_S_MIT_THREE_INDEX_DATA, *PNPC_S_MIT_THREE_INDEX_DATA;

//二级索引
typedef struct _NPC_S_MIT_TWO_INDEX_DATA
{
	NPC_S_MIT_THREE_INDEX_DATA				tThreeIndexTable[0x100];			//三级索引表

} NPC_S_MIT_TWO_INDEX_DATA, *PNPC_S_MIT_TWO_INDEX_DATA;

//一级索引
typedef struct _NPC_S_MIT_ONE_INDEX_DATA
{
	PNPC_S_MIT_TWO_INDEX_DATA				pTwoIndexTable[0x100];				//二级索引表

} NPC_S_MIT_ONE_INDEX_DATA, *PNPC_S_MIT_ONE_INDEX_DATA;


//-----------------------------------------------------------------------------------
//多层索引表数据
typedef struct _NPC_S_MIT_INDEX_TABLE_DATA
{
	PNPC_S_MIT_ONE_INDEX_DATA				pOneIndexTable[0x100];				//一级索引表

	NPC_INT									iFindOneIndex;						//查询空闲的一级索引号
	NPC_INT									iFindTwoIndex;						//查询空闲的二级索引号
	NPC_INT									iFindThreeIndex;					//查询空闲的三级索引号

	NPC_INT									iTotalIndexNum;						//总索引位置数
	NPC_INT									iValidIndexNum;						//有效索引数
	NPC_INT									iIdleIndexNum;						//空闲索引位置数

	NPC_DWORD								dwIdCreate;							//ID创建器

} NPC_S_MIT_INDEX_TABLE_DATA, *PNPC_S_MIT_INDEX_TABLE_DATA;


#endif

