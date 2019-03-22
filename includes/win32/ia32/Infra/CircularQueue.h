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


/// ���ζ���ģ����
///
template <class T> class TCircularQueue 
{
public:
	/// ���캯������ʼ����������Դ
	/// \param [in] maxSize ���ζ��д�С
	TCircularQueue(int maxSize)
	{
		m_maxSize = maxSize;
		m_queue = new T[maxSize];
		clear();
	}

	/// �����������ͷ���Դ
	~TCircularQueue()
	{
		if (m_queue)
		{
			delete [] m_queue;
		}
	}

	/// ������ĩβѹ��Ԫ��
	/// \param [in] item Ҫѹ���Ԫ��
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

	/// ����Ԫ�س���
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

	/// ��ն���
	void clear()
	{
		m_front = m_tail = 0;
		m_size = 0;
	}

private:
	T * m_queue;	
	int m_maxSize;	///< ��������
	int m_front;	///< ����λ��
	int m_tail;		///< ��βλ��(���һ��Ԫ�ص���һλ��)
	int m_size;		///< ������ݵĸ���
};

#endif
