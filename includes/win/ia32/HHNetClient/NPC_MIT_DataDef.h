/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MIT_DataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2013-01-12
 * Description   :  ���������ģ��
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MIT_DATADEF_H
#define __NPC_MIT_DATADEF_H

#include "NPC_TypeDef.h"


//-----------------------------------------------------------------------------------
//����ID�ṹ
typedef struct _NPC_S_MIT_DATAID_FRAME
{
	NPC_BYTE								ucThreeIndex;						//����������
	NPC_BYTE								ucTwoIndex;							//����������
	NPC_BYTE								ucOneIndex;							//һ��������
	NPC_BYTE								ucAuthCode;							//��֤��

} NPC_S_MIT_DATAID_FRAME, *PNPC_S_MIT_DATAID_FRAME;


//-----------------------------------------------------------------------------------
//��������
typedef struct _NPC_S_MIT_THREE_INDEX_DATA
{
	NPC_DWORD								dwDataId;							//����ID
	PNPC_BYTE								pDataPos;							//����ָ��

} NPC_S_MIT_THREE_INDEX_DATA, *PNPC_S_MIT_THREE_INDEX_DATA;

//��������
typedef struct _NPC_S_MIT_TWO_INDEX_DATA
{
	NPC_S_MIT_THREE_INDEX_DATA				tThreeIndexTable[0x100];			//����������

} NPC_S_MIT_TWO_INDEX_DATA, *PNPC_S_MIT_TWO_INDEX_DATA;

//һ������
typedef struct _NPC_S_MIT_ONE_INDEX_DATA
{
	PNPC_S_MIT_TWO_INDEX_DATA				pTwoIndexTable[0x100];				//����������

} NPC_S_MIT_ONE_INDEX_DATA, *PNPC_S_MIT_ONE_INDEX_DATA;


//-----------------------------------------------------------------------------------
//�������������
typedef struct _NPC_S_MIT_INDEX_TABLE_DATA
{
	PNPC_S_MIT_ONE_INDEX_DATA				pOneIndexTable[0x100];				//һ��������

	NPC_INT									iFindOneIndex;						//��ѯ���е�һ��������
	NPC_INT									iFindTwoIndex;						//��ѯ���еĶ���������
	NPC_INT									iFindThreeIndex;					//��ѯ���е�����������

	NPC_INT									iTotalIndexNum;						//������λ����
	NPC_INT									iValidIndexNum;						//��Ч������
	NPC_INT									iIdleIndexNum;						//��������λ����

	NPC_DWORD								dwIdCreate;							//ID������

} NPC_S_MIT_INDEX_TABLE_DATA, *PNPC_S_MIT_INDEX_TABLE_DATA;


#endif

