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
	/// 构造函数，创建T对象
	TWrapper(T *p = NULL)
	{
		m_t = p;
		if (!p)
		{
			m_t = T::create();
		}
	}

	/// 析构函数，销毁T对象
	virtual ~TWrapper()
	{
		delete m_t;
	}

	/// 返回T对象指针
	T* operator->() 
	{
		return m_t; 
	}

	/// 返回T对象指针
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
	/// 构造函数，创建T对象
	TStrWrapper()
	{
		m_t = new T;
		if (m_t == NULL)
		{
			assert(0);
		}
	}

	/// 析构函数，销毁T对象
	virtual ~TStrWrapper()
	{
		delete m_t;
	}

	/// 返回T对象指针
	T* operator->() 
	{
		return m_t; 
	}

	/// 返回T对象指针
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
