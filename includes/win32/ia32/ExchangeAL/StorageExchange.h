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

/// 录像存储设备类型，以下类型的一种或者多种
struct RecordStorageType
{
	bool SATA_as;
	bool USB_as;
	bool SD_as;
	bool DVD_as;
};

//硬盘信息、文件时间、录像状态
typedef struct RecordStorageInfo
{
	uint bStart;//是否录像标志位掩码
	SystemTime beginTime;//录像开始时间
	SystemTime endTime;//录像结束时间
	uint storageCapacity;//硬盘总容量
	uint useCapacity;//使用容量
	int res[16];//冗余
}StorageInfo;
#endif
