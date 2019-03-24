//
//  "$Id: DC.h 5392 2012-11-30 09:04:32Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_DC_H__
#define __GDI_DC_H__

#include "Types/Defs.h"
#include "Types.h"

struct BITMAP;
class CRegion;
class CPoint;
class CRect;

enum DCType
{
	DC_SCREEN = 0,		//����Ļ
	DC_SCREEN1,			//������Ļ
	DC_MEMORY
};

enum RasterOperation
{
	ROP_COPY = 0,		//copy operation
	ROP_AND,			//and operation
	ROP_OR,				//or operation
	ROP_XOR,			//xor operation
};

enum RgnStyle
{
	RS_NORMAL = 0x0000, 	//normal
	RS_SUNKEN = 0x0001, 	//sunken
	RS_RAISED = 0x0002, 	//raised
	RS_HOLLOW = 0x0004,		//hollow, no fill
	RS_FLAT	= 0X0008,		//flat, no frame
};

/// �ı����뷽ʽ
enum TextAlignStyle
{
	TA_LEFT = 0x0000,
	TA_XCENTER = 0x0001,
	TA_RIGHT = 0x0002,
	TA_TOP = 0x0000,
	TA_YCENTER = 0x0010,
	TA_BOTTOM = 0x0020,
	TA_LEFTTOP = 0x0000,
	TA_CENTER = 0x0011,
	TA_CHANGELINE = 0x0100,
};

enum FontType
{
	FONT_NORMAL = 0x0000,		///< ��������
	FONT_BOLD = 0x0001,			///< ������
	FONT_SMALL = 0x0002,	
	FONT_ITALIC	= 0x0004,		///< б����
	FONT_OUTLINE	= 0x0008,	///< ����(����)Ч��
	FONT_SCALING	= 0x0010,	///< �Բ����ʵĵ��������������
};

enum PenStyle
{
	PS_SOLID = 0x0000,		//solid
	PS_DOT,					//dot
};

enum BrushStyle
{
	BS_NORMAL = 0x0000,
};

/// ����ģʽ
enum BackgroundMode
{
	BM_NORMAL,			///< ��������ģʽ
	BM_TRANSPARENT,		///< ͸������ģʽ
};

enum FontStyle
{
	FS_NORMAL = 0x0000,
	FS_BOLD = 0x0001,
	FS_SMALL = 0x0002,
};

/// �豸�����������װ
/// 
class IDC
{
public:

	/// ���������С
	/// \param [in] style Ҫ���õ�������
	/// \param [in] size Ҫ���õ������С
	static void config(FontStyle style, const Size &size);

	/// �����豸������
	/// \param [in] type Ҫ�������豸����������
	/// \param [in] width ���
	/// \param [in] height �߶�
	/// \return �豸�����ľ��
	static IDC *create(int type = DC_SCREEN, int width = 0, int height = 0);

	/// ����������
	virtual ~IDC();

	/// �����豸�����ľ��
	virtual void Update() = 0;

	/// ��ɫ�ͷ��
	/// ���õ�ǰ�����
	/// \param [in] rop Ҫ���õĲ���
	virtual void SetRop(int rop= ROP_COPY) = 0;

	/// ���õ�ǰ��������
	/// \param [in] color Ҫ���õ�������ɫ
	/// \param [in] style ֧�ֵ�������
	virtual void SetFont(RGBA32 color, FontStyle style=FS_NORMAL) = 0;

	/// ���û�������
	/// \param [in] color ���ʵ���ɫ
	/// \param [in] style ���ʷ��
	/// \param [in] width ���ʿ��
	virtual void SetPen(RGBA32 color, int style=PS_SOLID, int width=1) = 0;

	/// ���û�ˢ
	/// \param [in] color ���û�ˢ����ɫ
	/// \param [in] style ��ˢ���
	virtual void SetBrush(RGBA32 color, int style=BS_NORMAL) = 0;

	/// �����ı����뷽ʽ
	/// \param [in] align Ҫ���õ��ı����뷽ʽ
	virtual void SetTextAlign(int align = TA_LEFTTOP) = 0;

	/// ���ñ���ģʽ
	/// \param [in] mode Ҫ���õı���ģʽ
	virtual void SetBkMode(int mode) = 0;

	/// �õ���ǰ�ı�������ģʽ
	virtual int GetBkMode() = 0;

	/// ���ñ���ɫ
	/// \param [in] color ����ɫ
	virtual void SetBkColor(RGBA32 color) = 0;

	/// ����������
	/// \param [in] style Ҫ���õ�������enum RgnStyle
	virtual void SetRgnStyle(int style) = 0;

	/// ���û��ʿ��
	virtual void SetPenWidth(int width) = 0;

	/// �õ����ʿ��
	virtual int GetPenWidth() = 0;

	/// ����
	/// \param [in] x Ҫ�����x����
	/// \param [in] y Ҫ�����y����
	/// \param [in] color Ҫ�������ɫ
	virtual void SetPixel(int x, int y, RGBA32 color) = 0;


	/// �õ�ָ�����RGB����ֵ
	/// \param [in] x X����
	/// \param [in] y Y����
	/// \return ����ָ�����RGBֵ���ĵ��ֵ���ܺ�SetPixelֵ�ķ��ز�ͬ(��ɫ��ת����COLORDEV,��ת������)
	virtual RGBA32 GetPixel(int x, int y) = 0;


	virtual void LineTo(int x, int y) = 0;
	virtual void MoveTo(int x, int y) = 0;
	virtual const CPoint GetPos() const = 0;
	virtual void TextOut(PCRECT pRect, PCSTR str, int len=1024) = 0;
	virtual void Rectangle(PCRECT pRect, int ea = 0, int eb = 0) = 0;
	virtual void Trapezoid(int x1, int y1, int w1, int x2, int y2, int w2) = 0;
	virtual void Arc(PCRECT lpRect, Point ptStart, Point ptEnd) = 0;
	virtual void Chord(PCRECT lpRect, Point ptStart, Point ptEnd) = 0;
	virtual void Ellipse(PCRECT lpRect) = 0;
	virtual void Pie(PCRECT lpRect, Point ptStart, Point ptEnd) = 0;
	virtual void Polygon(const Point* lpPoints, int nCount) = 0;	
	virtual void PolyBezier(const Point* lpPoints, int nCount) = 0;
	virtual void FillRgn(CRegion* pRgn) = 0;
	virtual void Bitmap(PCRECT rect, BITMAP *pBitmap) = 0;
	///��������ͼƬ���Ŵ���
	virtual void EnlargeBitmap(PCRECT pRect, BITMAP *pBitmap) = 0;
	/// DC λͼ����
	virtual bool BitBlt(PCRECT pRect, IDC* pDC, int start_x = 0, int start_y = 0) = 0;

	/// DC�������
	virtual bool SubtractRgn(CRegion * pRgn) = 0;
	virtual bool IntersectRgn(CRegion * pRgn) = 0;
	virtual bool UnionRgn(CRegion * pRgn) = 0;
	virtual bool GetRgn(CRegion * pRgn) = 0;
	virtual bool SetRgn(CRegion * pRgn) = 0;
	virtual bool SwapRgn(CRegion * pRgn) = 0;
	virtual bool SubtractRect(PCRECT pRect) = 0;
	virtual bool IntersectRect(PCRECT pRect) = 0;
	virtual bool UnionRect(PCRECT pRect) = 0;
	virtual void SetBound(PCRECT pRect) = 0;

	/// �豸���굽�߼������ת��
	/// \param [in/out] point Ҫת������ĵ���豸����,ת��������ĵ��߼�����
	virtual void DPtoLP(CPoint &point) const = 0;

	/// �豸���굽�߼������ת��
	/// \param [in/out] rect Ҫת������ľ��ε��豸����,ת��������ľ����߼�����
	virtual void DPtoLP(PRECT pRect) const = 0;

	/// �߼����굽�豸�����ת��
	/// \param [in/out] point Ҫת������ĵ���߼�����,ת��������ĵ���߼�����
	virtual void LPtoDP(CPoint &point) const = 0;

	/// �߼����굽�豸�����ת��
	/// \param [in/out] point Ҫת������ĵ���߼�����,ת��������ĵ���߼�����
	virtual void LPtoDP(PRECT pRect) const = 0;

	/// ʹ��DC
	/// \param [in] enable ʹ�ܱ�ʾ
	virtual void Enable(bool enable) = 0;

	/// DC����
	virtual void Lock() = 0;
	
	/// DC����
	virtual void UnLock() = 0;
	
	/// �õ�ָ������ĵ���Ҷ�ͼ
	/// \param [in] rect Ҫ��õ��������
	/// \param [out] buf ��Ż�ȡ��ĵ�������
	/// \param [in/out] length �������ݻ���������
	virtual bool GetBitmapBits(const CRect &rect, uchar *buf, int *length) = 0;

	/// �õ�ָ�������λͼ
	/// \param [in] rect Ҫ�õ�λͼ������
	/// \param [out] bitmap Ҫ��ŵ�λͼ����,bitmap��Ҫ�ⲿ�ӿ��ͷ�
	/// \return ָ�������λͼ
	virtual bool GetBitmap(const CRect &rect, BITMAP *&bitmap) = 0;

	/// ������ɫ�����ϸ��Եķ�������ȥ������ɫ
	/// \param [in] c Ҫ�ӵ���ɫ
	/// \param [in] r Red����
	/// \param [in] g Green����
	/// \param [in] b Blue����
	/// \return ������RGBֵ
	virtual RGBA32 ModulateColor(RGBA32 c, int r, int g, int b) = 0;

protected:
	IDC();
	IDC(const IDC&);
};

#endif
