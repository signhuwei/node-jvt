//
//  "$Id: WatchDog.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_WATCHDOG_H__
#define __PAL_WATCHDOG_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup WatchDogAPI API Watch Dog
/// 看门狗API，软硬件配合来实现系统的故障处理.
/// @{

/// 创建看门狗设备
/// \param 无
/// \retval <0 创建失败
/// \retval 0 创建成功
int WatchdogCreate(void);

/// 销毁看门狗设备
/// \param 无
/// \retval <0 销毁失败
/// \retval 0 销毁成功
int WatchdogDestory(void);

/// 喂狗
/// \param [in] data 要写的数据缓冲地址
/// \param [in] nBytes 写入的数据
/// \return 0 写入成功
/// \return < 0 写入失败
int WatchdogWrite(void* pdata, unsigned int nBytes);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
