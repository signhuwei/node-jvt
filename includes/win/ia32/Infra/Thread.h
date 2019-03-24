//
//  "$Id: Thread.h 1232 2010-11-02 06:45:19Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_THREAD_H__
#define __INFRA_THREAD_H__

#include "Infra/Singleton.h"
#include "Function.h"
#include "Guard.h"
#include "MsgQue.h"
#include "Types.h"
#include "Semaphore.h"
#include <string>

#ifdef SendMessage
	#undef SendMessage
#endif

class CThreadImp;

/// 线程封装实现类
/// 
class CThread
{
	friend void ThreadBody(void *pdat);
	friend class CThreadManager;

public:
	enum 
	{
		msgThreadOver = 0xcd,
	};


	/// 构造函数
	/// \param [in] pName 线程名称
	/// \param [in] nPriority 线程优先级
	/// \param [in] nMsgQueSize 消息队列长度
	/// \param [in] dwStackSize 线程堆栈大小，为0表示由系统自由分配.
	CThread(const char*pName, int nPriority, int nMsgQueSize = 0, uint dwStackSize = 0);
	
	
	/// 析构函数
	virtual ~CThread();

	
	/// 创建线程
	/// \return 创建线程是否成功
	bool CreateThread();


	/// 销毁线程
	/// \param [in] bWaited 是否等待线程退出
	/// \return 销毁线程是否成功
	bool DestroyThread(bool bWaited = false);


	/// 线程是否已退出
	/// \return 线程是否已退出
	bool IsThreadOver();

	
	/// 得到当前的线程ID
	int	GetThreadID();


	/// 给线程消息队列中发送消息
	/// \param [in] msg 要发送的消息
	/// \param [in] wpa 消息参数
	/// \param [in] lpa 消息参数
	/// \param [in] priority 消息优先级(这个暂时不用)
	/// \return 发送消息是否成功
	bool SendMessage (uint msg, uint wpa = 0, uint lpa = 0, uint priority = 0);


	/// 从消息队列中接收消息
	/// \param [out] pMsg 存放接收到的消息
	/// \param [in] wait 是否等待接收到消息完成
	/// \return 接收消息是否成功
	bool RecvMessage (CMsgQue::MSG *pMsg, bool wait = true);
	
	
	/// 退出接收消息
	void QuitMessage ();


	/// 清楚消息队列中的消息
	void ClearMessage();

	
	///  得到消息队列中消息的数目
	uint GetMessageCount();

	
	/// 虚析构函数
	virtual void ThreadProc() = 0;


	/// 设置线程名称
	int SetThreadName(const char*pName);

	
	/// 设置线程超时时间(MS为单位)
	void SetTimeout(uint milliSeconds);


	/// 线程是否超时
	bool IsTimeout();

	/// 得到调用线程的线程ID
	static int GetCurrentID();

	/// 打印系统线程列表
	static void DumpThreads();

protected:
	volatile bool	m_bLoop;
	
private:
	CThreadImp *m_threadImp;
};

class IThreadLet
{
public:
	typedef TFunction1<void, uint> Proc;

	/// 构造函数
	/// \param [in] pName 线程名称
	/// \param [in] nPriority 线程优先级
	/// \param [in] nMsgQueSize 消息队列长度
	/// \param [in] dwStackSize 线程堆栈大小，为0表示由系统自由分配.
	static IThreadLet *create();

	/// 析构函数
	virtual ~IThreadLet();

	/// 创建线程
	/// \return 创建线程是否成功
	virtual bool run(const char *name, Proc asynProc, uint param, uint timeout) = 0;

	/// 销毁线程
	/// \param [in] bWaited 是否等待线程退出
	/// \return 销毁线程是否成功
	virtual bool stopRun(bool bWaited = false) = 0;


	/// 线程是否已退出
	/// \return 线程是否已退出
	virtual bool isRunning() = 0;


	/// 给线程消息队列中发送消息
	/// \param [in] msg 要发送的消息
	/// \param [in] wpa 消息参数
	/// \param [in] lpa 消息参数
	/// \param [in] priority 消息优先级(这个暂时不用)
	/// \return 发送消息是否成功
	virtual bool sendMessage (uint msg, uint wpa = 0, uint lpa = 0, uint priority = 0) = 0;


	/// 从消息队列中接收消息
	/// \param [out] pMsg 存放接收到的消息
	/// \param [in] wait 是否等待接收到消息完成
	/// \return 接收消息是否成功
	virtual bool recvMessage (CMsgQue::MSG *pMsg, bool wait = true) = 0;


	/// 退出接收消息
	virtual void quitMessage () = 0;


	/// 清楚消息队列中的消息
	virtual void clearMessage() = 0;

	/// 线程是否超时
	virtual bool isTimeout() = 0;


	virtual void setLoop(bool loop) = 0;

	virtual bool getLoop() = 0;

	virtual int getThreadID() = 0;
};

#endif
