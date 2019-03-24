//
//  "$Id: Region.h 447 2010-04-14 12:21:08Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_REGION_H__
#define __GDI_REGION_H__

#include "Infra/PoolAllocator.h"
#include "Rect.h"
#include <list>

typedef std::list<Rect, pool_allocator<Rect> > PRECTLIST;

class CRegion
{
public:
	CRegion();
	virtual ~CRegion();

	bool CreateRectRgn(PCRECT pRect);
	bool CreateEllipticRgn(PCRECT pRect);
	bool CreatePolygonRgn(PPOINT pPoints, int nCount, int nMode);
	bool CreateRoundRectRgn(int x1, int y1, int x2, int y2, int x3, int y3);

	// Operations
	int CombineRgn(const CRegion* pRgn1, const CRegion* pRgn2, int nCombineMode);
	int CopyRgn(const CRegion* pRgnSrc);
	bool EqualRgn(const CRegion* pRgn) const;
	int GetRgnBox(PRECT lpRect) const;
	bool PtInRegion(int x, int y) const;
	bool PtInRegion(Point point) const;
	bool RectInRegion(PCRECT lpRect) const;

	void Dump();
	void SetRectRgn(PCRECT pRect);
	void SetRgnEmpty();
	bool IsRgnEmpty();

public:
	//
	bool PtInRegion(int x, int y);
	bool RectInRegion(PCRECT pRect);
	//rect operations
	bool SubtractRect(PCRECT pRect);
	bool IntersectRect(PCRECT pRect);
	bool UnionRect(PCRECT pRect);

	//rect 
	PCRECT GetFirstRect();
	PCRECT GetNextRect();
	void GetBoundRect(PRECT pRect) const;

	//region combine 
	bool CopyRgn(CRegion * pRgn);
	bool SubtractRgn(CRegion * pRgn);
	bool IntersectRgn(CRegion * pRgn);
	bool UnionRgn(CRegion * pRgn);
	void OffsetRgn(int x, int y);
	void SwapRgn(CRegion * pRgn);

private:
	void CheckBound();
	
private:
	CRect	m_Bound;
	PRECTLIST m_List;
	PRECTLIST::iterator m_pCurrent;
};



bool LineClipper (const Rect* cliprc, int *_x0, int *_y0, int *_x1, int *_y1);

#endif //__REGION_H__
