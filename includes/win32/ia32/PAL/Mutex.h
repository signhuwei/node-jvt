//
//  "$Id: Mutex.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_MUTEX_H__
#define __PAL_MUTEX_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup MutexAPI API Mutex
/// 互斥量API，封装了不同操作系统的互斥量对象。
///	\n 调用流程图:
/// \code
///    ===========================
///                |
///           RWMutexCreate
///                |-------------------+
///      ReadMutexEnter,ReadMutexEnter  |
///                |------------+
///           RWMutexDestory
///                |
///    ===========================
/// \endcode
/// @{


/// 创建读写锁。
/// 
/// \param [out] phMutex 读写锁创建成功时，传出的读写锁句柄。
/// \retval 0  创建成功
/// \retval <0  创建失败
int RWMutexCreate(void * *phMutex);


/// 销毁读写锁。
/// 
/// \param [in] hMutex 读写锁句柄。
/// \retval 0  销毁成功
/// \retval <0 销毁失败
int RWMutexDestory(void * hMutex);


/// 进入读临界区。
/// 
/// \param [in] hMutex 读写锁句柄。
/// \retval 0  操作成功
/// \retval <0  操作失败
int ReadMutexEnter(void * hMutex);


/// 进入写临界区。
/// 
/// \param [in] hMutex 读写锁句柄。
/// \retval 0  操作成功
/// \retval <0  操作失败
int WriteMutexEnter(void * hMutex);

/// 离开读临界区。
/// 
/// \param [in] hMutex 读写锁句柄。
/// \retval 0  操作成功
/// \retval <0  操作失败
int ReadMutexLeave(void * hMutex);

/// 离开写临界区。
/// 
/// \param [in] hMutex 读写锁句柄。
/// \retval 0  操作成功
/// \retval <0  操作失败
int WriteMutexLeave(void * hMutex);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
