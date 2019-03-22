//
//  "$Id: Guard.h 637 2010-06-10 09:52:10Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_GUARD_H__
#define __INFRA_GUARD_H__

#include "Mutex.h"

class CGuard
{
public:
	CGuard(CMutex& Mutex) : m_Mutex(Mutex)
	{
		m_Mutex.Enter();
	}
	
	~CGuard()
	{
		m_Mutex.Leave();
	}
private:
	CMutex &m_Mutex;
};

class CReadWriteGuard
{
public:
	enum GuardTypes
	{
		guardWrite,
		guardRead,
	};
	
	CReadWriteGuard(CReadWriteMutex& Mutex, GuardTypes types = guardWrite) : m_Mutex(Mutex)
	{
		m_guardType = types;
		if (m_guardType == guardWrite)
		{
			m_Mutex.EnterWrite();
		}
		else
		{
			m_Mutex.EnterRead();
		}
	}
	
	~CReadWriteGuard()
	{
		if (m_guardType == guardWrite)
		{
			m_Mutex.LeaveWrite();
		}
		else
		{
			m_Mutex.LeaveRead();
		}
	}

private:
	CReadWriteMutex &m_Mutex;
	GuardTypes m_guardType;
};

#endif
