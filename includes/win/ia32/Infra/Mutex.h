//
//  "$Id: Mutex.h 2050 2011-10-11 06:40:48Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//
#ifndef __INFRA_MUTEX_H__
#define __INFRA_MUTEX_H__

/// ����������
enum mutex_type
{
	/// ���ٻ�����������ٽ����Ѿ���һ���̻߳�ȡ�������̻߳��߸��߳��ٴλ�ȡʱ��
	/// �����߳�ֱ�ӱ�����
	MUTEX_FAST = 0,

	/// �ݹ黥�������Ѿ���ȡ�ٽ������߳̿��Զ�λ�ȡ�������������ڲ�Ӧ�л�ȡ����
	/// ���������Ҫ��ȫ�ͷ��ٽ�����һ��Ҫ��֤��ȡ�������ͷŴ���һ�¡�
	MUTEX_RECURSIVE,
};

class CMutex
{
public:
	/// ������������
	/// 
	/// \param [in] nType �����������ͣ�ȡmutex_typeö������ֵ
	CMutex(int nType = MUTEX_FAST);

	/// ���ٻ�������
	~CMutex();

	/// �����ٽ�����
	/// \retval true  �����ɹ�
	/// \retval false  ����ʧ��
	bool Enter();

	/// �뿪�ٽ�����
	/// 
	/// \retval true  �����ɹ�
	/// \retval false  ����ʧ��
	bool Leave();

	bool TryEnter();

private:
	void  *m_hMutex;
};

/// ��д����װ
/// 
class CReadWriteMutex  
{
public:
	CReadWriteMutex();
	~CReadWriteMutex();
	bool LeaveRead();	
	bool EnterRead(); 
	bool EnterWrite();
	bool LeaveWrite();
	bool TryEnterRead();
	bool TryEnterWrite();

protected: 
	CReadWriteMutex& operator=( const CReadWriteMutex &rhs );

private:
	void  *m_hrwMutex;
};
#endif 

