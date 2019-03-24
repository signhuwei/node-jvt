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

/// �̷߳�װʵ����
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


	/// ���캯��
	/// \param [in] pName �߳�����
	/// \param [in] nPriority �߳����ȼ�
	/// \param [in] nMsgQueSize ��Ϣ���г���
	/// \param [in] dwStackSize �̶߳�ջ��С��Ϊ0��ʾ��ϵͳ���ɷ���.
	CThread(const char*pName, int nPriority, int nMsgQueSize = 0, uint dwStackSize = 0);
	
	
	/// ��������
	virtual ~CThread();

	
	/// �����߳�
	/// \return �����߳��Ƿ�ɹ�
	bool CreateThread();


	/// �����߳�
	/// \param [in] bWaited �Ƿ�ȴ��߳��˳�
	/// \return �����߳��Ƿ�ɹ�
	bool DestroyThread(bool bWaited = false);


	/// �߳��Ƿ����˳�
	/// \return �߳��Ƿ����˳�
	bool IsThreadOver();

	
	/// �õ���ǰ���߳�ID
	int	GetThreadID();


	/// ���߳���Ϣ�����з�����Ϣ
	/// \param [in] msg Ҫ���͵���Ϣ
	/// \param [in] wpa ��Ϣ����
	/// \param [in] lpa ��Ϣ����
	/// \param [in] priority ��Ϣ���ȼ�(�����ʱ����)
	/// \return ������Ϣ�Ƿ�ɹ�
	bool SendMessage (uint msg, uint wpa = 0, uint lpa = 0, uint priority = 0);


	/// ����Ϣ�����н�����Ϣ
	/// \param [out] pMsg ��Ž��յ�����Ϣ
	/// \param [in] wait �Ƿ�ȴ����յ���Ϣ���
	/// \return ������Ϣ�Ƿ�ɹ�
	bool RecvMessage (CMsgQue::MSG *pMsg, bool wait = true);
	
	
	/// �˳�������Ϣ
	void QuitMessage ();


	/// �����Ϣ�����е���Ϣ
	void ClearMessage();

	
	///  �õ���Ϣ��������Ϣ����Ŀ
	uint GetMessageCount();

	
	/// ����������
	virtual void ThreadProc() = 0;


	/// �����߳�����
	int SetThreadName(const char*pName);

	
	/// �����̳߳�ʱʱ��(MSΪ��λ)
	void SetTimeout(uint milliSeconds);


	/// �߳��Ƿ�ʱ
	bool IsTimeout();

	/// �õ������̵߳��߳�ID
	static int GetCurrentID();

	/// ��ӡϵͳ�߳��б�
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

	/// ���캯��
	/// \param [in] pName �߳�����
	/// \param [in] nPriority �߳����ȼ�
	/// \param [in] nMsgQueSize ��Ϣ���г���
	/// \param [in] dwStackSize �̶߳�ջ��С��Ϊ0��ʾ��ϵͳ���ɷ���.
	static IThreadLet *create();

	/// ��������
	virtual ~IThreadLet();

	/// �����߳�
	/// \return �����߳��Ƿ�ɹ�
	virtual bool run(const char *name, Proc asynProc, uint param, uint timeout) = 0;

	/// �����߳�
	/// \param [in] bWaited �Ƿ�ȴ��߳��˳�
	/// \return �����߳��Ƿ�ɹ�
	virtual bool stopRun(bool bWaited = false) = 0;


	/// �߳��Ƿ����˳�
	/// \return �߳��Ƿ����˳�
	virtual bool isRunning() = 0;


	/// ���߳���Ϣ�����з�����Ϣ
	/// \param [in] msg Ҫ���͵���Ϣ
	/// \param [in] wpa ��Ϣ����
	/// \param [in] lpa ��Ϣ����
	/// \param [in] priority ��Ϣ���ȼ�(�����ʱ����)
	/// \return ������Ϣ�Ƿ�ɹ�
	virtual bool sendMessage (uint msg, uint wpa = 0, uint lpa = 0, uint priority = 0) = 0;


	/// ����Ϣ�����н�����Ϣ
	/// \param [out] pMsg ��Ž��յ�����Ϣ
	/// \param [in] wait �Ƿ�ȴ����յ���Ϣ���
	/// \return ������Ϣ�Ƿ�ɹ�
	virtual bool recvMessage (CMsgQue::MSG *pMsg, bool wait = true) = 0;


	/// �˳�������Ϣ
	virtual void quitMessage () = 0;


	/// �����Ϣ�����е���Ϣ
	virtual void clearMessage() = 0;

	/// �߳��Ƿ�ʱ
	virtual bool isTimeout() = 0;


	virtual void setLoop(bool loop) = 0;

	virtual bool getLoop() = 0;

	virtual int getThreadID() = 0;
};

#endif
