//
//  "$Id: CircularQueue.h 776 2010-07-21 05:21:29Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_CIRCULARQUEUE_H__
#define __INFRA_CIRCULARQUEUE_H__


/// 环形队列模板类
///
template <class T> class TCircularQueue 
{
public:
	/// 构造函数，初始化、分配资源
	/// \param [in] maxSize 环形队列大小
	TCircularQueue(int maxSize)
	{
		m_maxSize = maxSize;
		m_queue = new T[maxSize];
		clear();
	}

	/// 析构函数，释放资源
	~TCircularQueue()
	{
		if (m_queue)
		{
			delete [] m_queue;
		}
	}

	/// 往队列末尾压入元素
	/// \param [in] item 要压入的元素
	void push(const T &item)
	{
		m_queue[m_tail] = item;
		m_tail = (m_tail + 1) % m_maxSize;
		if (m_tail == m_front)
		{
			m_front = (m_front + 1) % m_maxSize;
		}
		else 
		{
			m_size++;
		}
	}

	/// 队首元素出列
	void pop()
	{
		if (m_size > 0)
		{
			m_front = (m_front + 1) % m_maxSize;
			m_size--;
		}
	}

	int size()
	{
		return m_size;
	}

	const T *get(int pos)
	{
		if (pos < 0 || pos > m_size)
		{
			return NULL;
		}
		return &m_queue[(m_front + pos) % m_maxSize];
	}

	/// 清空队列
	void clear()
	{
		m_front = m_tail = 0;
		m_size = 0;
	}

private:
	T * m_queue;	
	int m_maxSize;	///< 队列容量
	int m_front;	///< 队首位置
	int m_tail;		///< 队尾位置(最后一个元素的下一位置)
	int m_size;		///< 添加数据的个数
};

#endif
