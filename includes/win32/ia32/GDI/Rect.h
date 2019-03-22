//
//  "$Id: Rect.h 447 2010-04-14 12:21:08Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_RECT_H__
#define __GDI_RECT_H__

#include "Types.h"
#include "Types/Defs.h"

class CSize;
class CPoint;
class CRect;



/////////////////////////////////////////////////////////////////////////////
// CSize - An extent, similar to Windows Size structure.

class CSize : public Size
{
public:

	// Constructors
	// construct an uninitialized size
	CSize() ;
	// create from two integers
	CSize(int initCX, int initCY) ;
	// create from another size
	CSize(Size initSize) ;
	// create from a point
	CSize(Point initPt) ;
	// create from a ulong: w = LOWORD(dw) h = HIWORD(dw)
	CSize(ulong dwSize) ;

	// Operations
	bool operator==(Size size) const ;
	bool operator!=(Size size) const ;
	void operator+=(Size size) ;
	void operator-=(Size size) ;
	void SetSize(int CX, int CY) ;

	// Operators returning CSize values
	CSize operator+(Size size) const ;
	CSize operator-(Size size) const ;
	CSize operator-() const ;

	// Operators returning CPoint values
	CPoint operator+(Point point) const ;
	CPoint operator-(Point point) const ;

	// Operators returning CRect values
	CRect operator+(const Rect* lpRect) const ;
	CRect operator-(const Rect* lpRect) const ;
};

/////////////////////////////////////////////////////////////////////////////
// CPoint - A 2-D point, similar to Windows Point structure.

class CPoint : public tagPoint
{
public:
	// Constructors

	// create an uninitialized point
	CPoint() ;
	// create from two integers
	CPoint(int initX, int initY) ;
	// create from another point
	CPoint(Point initPt) ;
	// create from a size
	CPoint(Size initSize) ;
	// create from an ulong: x = LOWORD(dw) y = HIWORD(dw)
	CPoint(ulong dwPoint) ;

	// Operations
	// translate the point
	void Offset(int xOffset, int yOffset) ;
	void Offset(Point point) ;
	void Offset(Size size) ;
	void SetPoint(int X, int Y) ;

	bool operator==(Point point) const ;
	bool operator!=(Point point) const ;
	void operator+=(Size size) ;
	void operator-=(Size size) ;
	void operator+=(Point point) ;
	void operator-=(Point point) ;

	// Operators returning CPoint values
	CPoint operator+(Size size) const ;
	CPoint operator-(Size size) const ;
	CPoint operator-() const ;
	CPoint operator+(Point point) const ;

	// Operators returning CSize values
	CSize operator-(Point point) const ;

	// Operators returning CRect values
	CRect operator+(const Rect* lpRect) const ;
	CRect operator-(const Rect* lpRect) const ;
};

/////////////////////////////////////////////////////////////////////////////
// CRect - A 2-D rectangle, similar to Windows Rect structure.

class CRect : public Rect
{
	// Constructors
public:
	// uninitialized rectangle
	CRect() ;
	// from left, top, right, and bottom
	CRect(int l, int t, int r, int b) ;
	// copy constructor
	CRect(const Rect& srcRect) ;
	// from a pointer to another rect
	CRect(PCRECT lpSrcRect) ;
	// from a point and size
	CRect(Point point, Size size) ;
	// from two points
	CRect(Point topLeft, Point bottomRight) ;

	// Attributes (in addition to Rect members)

	// retrieves the width
	int Width() const ;
	// returns the height
	int Height() const ;
	// returns the size
	CSize WidthHeight() const ;
	// reference to the top-left point
	CPoint& TopLeft() ;
	// reference to the bottom-right point
	CPoint& BottomRight() ;
	// const reference to the top-left point
	const CPoint& TopLeft() const ;
	// const reference to the bottom-right point
	const CPoint& BottomRight() const ;
	// the geometric center point of the rectangle
	CPoint CenterPoint() const ;
	// swap the left and right
	void SwapLeftRight() ;
	static void SwapLeftRight(Rect * lpRect) ;

	// convert between CRect and PRECT/PCRECT (no need for &)
	operator Rect *() ;
	operator PCRECT() const ;

	// returns TRUE if rectangle has no area
	bool IsRectEmpty() const ;
	// returns TRUE if rectangle is at (0,0) and has no area
	bool IsRectNull() const ;
	// returns TRUE if point is within rectangle
	bool PtInRect(Point point) const ;

	// Operations

	// set rectangle from left, top, right, and bottom
	void SetRect(int x1, int y1, int x2, int y2) ;
	void SetRect(Point topLeft, Point bottomRight) ;
	// empty the rectangle
	void SetRectEmpty() ;
	// copy from another rectangle
	void CopyRect(PCRECT lpSrcRect) ;
	// TRUE if exactly the same as another rectangle
	bool EqualRect(PCRECT lpRect) const ;

	// Inflate rectangle's width and height by
	// x units to the left and right ends of the rectangle
	// and y units to the top and bottom.
	void InflateRect(int x, int y) ;
	// Inflate rectangle's width and height by
	// size.w units to the left and right ends of the rectangle
	// and size.h units to the top and bottom.
	void InflateRect(Size size) ;
	// Inflate rectangle's width and height by moving individual sides.
	// Left side is moved to the left, right side is moved to the right,
	// top is moved up and bottom is moved down.
	void InflateRect(PCRECT lpRect);
	void InflateRect(int l, int t, int r, int b);

	// deflate the rectangle's width and height without
	// moving its top or left
	void DeflateRect(int x, int y) ;
	void DeflateRect(Size size) ;
	void DeflateRect(PCRECT lpRect) ;
	void DeflateRect(int l, int t, int r, int b) ;

	// translate the rectangle by moving its top and left
	void OffsetRect(int x, int y) ;
	void OffsetRect(Size size) ;
	void OffsetRect(Point point) ;
	void NormalizeRect() ;

	// absolute position of rectangle
	void MoveToY(int y) ;
	void MoveToX(int x) ;
	void MoveToXY(int x, int y) ;
	void MoveToXY(Point point) ;

	// set this rectangle to intersection of two others
	bool IntersectRect(PCRECT lpRect1, PCRECT lpRect2) ;

	// set this rectangle to bounding union of two others
	bool UnionRect(PCRECT lpRect1, PCRECT lpRect2) ;

	// set this rectangle to minimum of two others
	bool SubtractRect(PCRECT lpRectSrc1, PCRECT lpRectSrc2) ;

	// Additional Operations
	void operator=(const Rect& srcRect) ;
	bool operator==(const Rect& rect) const ;
	bool operator!=(const Rect& rect) const ;
	void operator+=(Point point) ;
	void operator+=(Size size) ;
	void operator+=(PCRECT lpRect) ;
	void operator-=(Point point) ;
	void operator-=(Size size) ;
	void operator-=(PCRECT lpRect) ;
	void operator&=(const Rect& rect) ;
	void operator|=(const Rect& rect) ;

	// Operators returning CRect values
	CRect operator+(Point point) const ;
	CRect operator-(Point point) const ;
	CRect operator+(PCRECT lpRect) const ;
	CRect operator+(Size size) const ;
	CRect operator-(Size size) const ;
	CRect operator-(PCRECT lpRect) const ;
	CRect operator&(const Rect& rect2) const ;
	CRect operator|(const Rect& rect2) const ;
	CRect MulDiv(int nMultiplier, int nDivisor) const ;
};

bool CopyRect(PRECT lprcDst, const Rect *lprcSrc);
bool EqualRect(const Rect *lprc1, const Rect *lprc2);
bool InflateRect(PRECT rect, int dx, int dy);
bool IntersectRect(PRECT lprcDst, const Rect *lprcSrc1, const Rect *lprcSrc2);
bool IsRectEmpty(const Rect *lprc);
bool OffsetRect(PRECT rect, int dx, int dy);
bool PtInRect(const Rect *lprc, Point pt);
bool SetRect(PRECT lprc,int xLeft, int yTop,int xRight,int yBottom);
bool SetRectEmpty(PRECT lprc);
int SubtractRect(PRECT lprcDst, const Rect *lprcSrc1,  const Rect *lprcSrc2);
bool UnionRect(PRECT lprcDst, const Rect *lprcSrc1,const Rect *lprcSrc2);
void NormalizeRect(PRECT pRect);
bool RectOverRect(PCRECT pRect1, PCRECT pRect2);
bool RectInRect(PCRECT pRect1, PCRECT pRect2);
#endif
