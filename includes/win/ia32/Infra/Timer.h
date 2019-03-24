//
//  "$Id: Timer.h 14 2009-08-22 07:39:05Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_TIMER_H__
#define __INFRA_TIMER_H__

#include "Types.h"
#include "Function.h"

/// \brief Infra定时器跨平台封装
/// 
class CTimer
{
public:
	/// 定时器回调函数
	typedef TFunction1<void, uint> Proc;


	/// 构造函数，创建定时器，分配资源
	/// \param [in] name 定时器名称
	CTimer(const char *name = "NoName");


	/// 析构函数，销毁定时器，释放资源
	virtual ~CTimer();


	/// 启动定时器
	/// \param [in] proc 定时器回调函数
	/// \param [in] delayTime 定时器启动延迟时间
	/// \param [in] period 定时器启动间隔时间
	/// \param [in] param 回调函数参数
	/// \param [in] timeout 超时时间
	void Start(Proc proc, uint delayTime, uint period, uint param = 0, uint timeout = 0);


	/// 停止定时器
	/// \param [in] callNow 定时器未被调用时是否进行一次调用
	void Stop(bool callNow = false);


	/// 得到定时器名称,名称通过SetName()或则构造函数传入
	const char *GetName();


	/// 设置定时器名称,名称通过GetName()获取
	void SetName(const char *name);

	
	/// 定时器是否启动过
	bool IsStarted();


	/// 定时器是否被调用过
	bool IsCalled();


	/// 打印定时器名称
	static void DumpThread();

private:
	void *m_timerHandle;
};

#endif
