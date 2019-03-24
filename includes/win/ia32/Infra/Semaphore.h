//
//  "$Id: Semaphore.h 156 2009-11-25 04:17:45Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_SEMAPHORE_H__
#define __INFRA_SEMAPHORE_H__

#include "Types.h"

class CSemaphore
{
public:
	/// 创建信号量，分配资源
	/// 
	/// \param [in] dwInitialCount 信号量计数的初始值。
	CSemaphore(int initialCount = 0);
	

	/// 销毁信号量，释放资源
	~CSemaphore();
	

	/// 减少信号量计数。
	/// 
	/// \param [in] hSemaphore 信号量句柄。
	/// \param [in] waitTime
	/// \retval true  操作成功
	/// \retval false  操作失败
	bool Pend(uint wait = 0xFFFFFFFF);
	

	/// 增加信号量计数。
	/// 
	/// \param [in] hSemaphore 信号量句柄。
	/// \retval true  操作成功
	/// \retval false  操作失败
	bool Post();
	
private:

	void *m_hSemphore;

};

#endif
