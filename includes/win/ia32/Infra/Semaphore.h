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
	/// �����ź�����������Դ
	/// 
	/// \param [in] dwInitialCount �ź��������ĳ�ʼֵ��
	CSemaphore(int initialCount = 0);
	

	/// �����ź������ͷ���Դ
	~CSemaphore();
	

	/// �����ź���������
	/// 
	/// \param [in] hSemaphore �ź��������
	/// \param [in] waitTime
	/// \retval true  �����ɹ�
	/// \retval false  ����ʧ��
	bool Pend(uint wait = 0xFFFFFFFF);
	

	/// �����ź���������
	/// 
	/// \param [in] hSemaphore �ź��������
	/// \retval true  �����ɹ�
	/// \retval false  ����ʧ��
	bool Post();
	
private:

	void *m_hSemphore;

};

#endif
