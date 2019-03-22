//
//  "$Id: StorageExchange.h 8439 2013-07-27 05:09:56Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//


#ifndef __EXCHANGEAL_STORAGEEXCHANGE_H__
#define __EXCHANGEAL_STORAGEEXCHANGE_H__
#include "Infra/Time.h"
#include "Types/Defs.h"

/// ¼��洢�豸���ͣ��������͵�һ�ֻ��߶���
struct RecordStorageType
{
	bool SATA_as;
	bool USB_as;
	bool SD_as;
	bool DVD_as;
};

//Ӳ����Ϣ���ļ�ʱ�䡢¼��״̬
typedef struct RecordStorageInfo
{
	uint bStart;//�Ƿ�¼���־λ����
	SystemTime beginTime;//¼��ʼʱ��
	SystemTime endTime;//¼�����ʱ��
	uint storageCapacity;//Ӳ��������
	uint useCapacity;//ʹ������
	int res[16];//����
}StorageInfo;
#endif
