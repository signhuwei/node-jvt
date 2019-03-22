// AutoCri.h: interface for the CAutoCri class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTOCRI_H__7E5E6156_1454_4C45_8F5C_B302E01E2150__INCLUDED_)
#define AFX_AUTOCRI_H__7E5E6156_1454_4C45_8F5C_B302E01E2150__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



/*****************************************************************************/

#include <windows.h>

class CAutoCri  
{
public:
	CAutoCri(CRITICAL_SECTION& cs)
	{
		m_pCs = &cs;
		EnterCriticalSection(m_pCs);
	}
	virtual ~CAutoCri()
	{
		if(m_pCs)
		{
			LeaveCriticalSection(m_pCs);
			m_pCs = NULL;
		}
	}
	
protected:
	CAutoCri();
	CAutoCri(const CAutoCri& cri);
	CAutoCri& operator= (const CAutoCri& cri);

private:
	CRITICAL_SECTION*	m_pCs;
};

#endif // !defined(AFX_AUTOCRI_H__7E5E6156_1454_4C45_8F5C_B302E01E2150__INCLUDED_)
