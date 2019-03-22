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

/// \brief Infra��ʱ����ƽ̨��װ
/// 
class CTimer
{
public:
	/// ��ʱ���ص�����
	typedef TFunction1<void, uint> Proc;


	/// ���캯����������ʱ����������Դ
	/// \param [in] name ��ʱ������
	CTimer(const char *name = "NoName");


	/// �������������ٶ�ʱ�����ͷ���Դ
	virtual ~CTimer();


	/// ������ʱ��
	/// \param [in] proc ��ʱ���ص�����
	/// \param [in] delayTime ��ʱ�������ӳ�ʱ��
	/// \param [in] period ��ʱ���������ʱ��
	/// \param [in] param �ص���������
	/// \param [in] timeout ��ʱʱ��
	void Start(Proc proc, uint delayTime, uint period, uint param = 0, uint timeout = 0);


	/// ֹͣ��ʱ��
	/// \param [in] callNow ��ʱ��δ������ʱ�Ƿ����һ�ε���
	void Stop(bool callNow = false);


	/// �õ���ʱ������,����ͨ��SetName()�����캯������
	const char *GetName();


	/// ���ö�ʱ������,����ͨ��GetName()��ȡ
	void SetName(const char *name);

	
	/// ��ʱ���Ƿ�������
	bool IsStarted();


	/// ��ʱ���Ƿ񱻵��ù�
	bool IsCalled();


	/// ��ӡ��ʱ������
	static void DumpThread();

private:
	void *m_timerHandle;
};

#endif
