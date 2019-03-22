//
//  "$Id: Wrapper.h 3258 2012-05-11 12:01:12Z chenchangbao $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_WRAPPER_H__
#define __INFRA_WRAPPER_H__
#include <assert.h>

template<class T>
class TWrapper
{
public:
	/// ���캯��������T����
	TWrapper(T *p = NULL)
	{
		m_t = p;
		if (!p)
		{
			m_t = T::create();
		}
	}

	/// ��������������T����
	virtual ~TWrapper()
	{
		delete m_t;
	}

	/// ����T����ָ��
	T* operator->() 
	{
		return m_t; 
	}

	/// ����T����ָ��
	T* operator &() 
	{
		return m_t; 
	}

private:
	T *m_t;
};

template<class T>
class TStrWrapper
{
public:
	/// ���캯��������T����
	TStrWrapper()
	{
		m_t = new T;
		if (m_t == NULL)
		{
			assert(0);
		}
	}

	/// ��������������T����
	virtual ~TStrWrapper()
	{
		delete m_t;
	}

	/// ����T����ָ��
	T* operator->() 
	{
		return m_t; 
	}

	/// ����T����ָ��
	T* operator &() 
	{
		return m_t; 
	}

	T & operator *() 
	{
		return *m_t; 
	}

private:
	T *m_t;
};

#endif
