//
//  "$Id: MsgQue.h 776 2010-07-21 05:21:29Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_MSGQUE_H__
#define __INFRA_MSGQUE_H__

#include "Types.h"

// Windows���Ѷ���SendMessage�꣬�Ӷ��������ӳ���ʵ�ʱ����ʱ�򲢲���
// SendMessage����������
#ifdef SendMessage
	#undef SendMessage
#endif

/// ��Ϣ���з�װ
///
class CMsgQue
{
public:

	/// ��Ϣ���Ͷ���(������Ϣ���͡�������ʱ���)
	typedef struct tagMSG 
	{
		uint		msg;
		uint		wpa;
		uint		lpa;
		uint		time;
	}MSG;


	/// ���캯��������һ��size���ȵ���Ϣ����
	/// \param [in] size ��Ϣ���г��ȣ����ɽ��ɵ���Ϣ����
	CMsgQue(int size = 1024);


	/// ��������
	virtual ~CMsgQue();


	/// ����Ϣ���з�����Ϣ
	/// \param [in] ��Ϣ����
	/// \param [in] wpa ��Ϣ����
	/// \param [in] lpa ��Ϣ����
	/// \param [in] priority ��Ϣ���ȼ�(��ʱ����)
	/// \return ������Ϣ�Ƿ�ɹ�(��Ϣ���������Ƿ�����Ϣ��ʧ��)
	bool SendMessage (uint msg, uint wpa = 0, uint lpa = 0, uint priority = 0);


	/// ����Ϣ���н�����Ϣ
	/// \param [out] pMsg��Ž��յ�����Ϣ
	/// \param [in] wait �Ƿ�ȴ�������Ϣ���
	/// \return ������Ϣ�Ƿ�ɹ�(�����ȴ�����Ϣ��������û����Ϣ��ʱ�������Ϣ��ʧ��)
	bool RecvMessage (MSG *pMsg, bool wait = true);


	/// �˳���Ϣ���У�ע: �Գ���Ϣ�����Ժ󽫲����ٷ��ͻ��߽�����Ϣ
	void QuitMessage ();


	/// �����Ϣ����
	void ClearMessage();

	
	/// ������Ϣ��������Ϣ����Ŀ
	int GetMessageCount();

	
	/// �õ���Ϣ��������Ϣ���еĳ���
	int GetMessageSize();


	/// ������Ϣ���н��ջ������Ĵ�С
	void SetMessageSize(int size);

private:
	
	void *m_MsgQueImp;
};
#endif
