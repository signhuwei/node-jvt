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
	DC_SCREEN = 0,		//主屏幕
	DC_SCREEN1,			//辅助屏幕
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

/// 文本对齐方式
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
	FONT_NORMAL = 0x0000,		///< 正常字体
	FONT_BOLD = 0x0001,			///< 粗体字
	FONT_SMALL = 0x0002,	
	FONT_ITALIC	= 0x0004,		///< 斜体字
	FONT_OUTLINE	= 0x0008,	///< 环绕(勾边)效果
	FONT_SCALING	= 0x0010,	///< 对不合适的点阵字体进行缩放
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

/// 背景模式
enum BackgroundMode
{
	BM_NORMAL,			///< 正常背景模式
	BM_TRANSPARENT,		///< 透明背景模式
};

enum FontStyle
{
	FS_NORMAL = 0x0000,
	FS_BOLD = 0x0001,
	FS_SMALL = 0x0002,
};

/// 设备上下文事务封装
/// 
class IDC
{
public:

	/// 配置字体大小
	/// \param [in] style 要配置的字体风格
	/// \param [in] size 要配置的字体大小
	static void config(FontStyle style, const Size &size);

	/// 创建设备上下文
	/// \param [in] type 要创建的设备上下文类型
	/// \param [in] width 宽度
	/// \param [in] height 高度
	/// \return 设备上下文句柄
	static IDC *create(int type = DC_SCREEN, int width = 0, int height = 0);

	/// 虚析构函数
	virtual ~IDC();

	/// 更新设备上下文句柄
	virtual void Update() = 0;

	/// 颜色和风格
	/// 设置当前点操作
	/// \param [in] rop 要设置的操作
	virtual void SetRop(int rop= ROP_COPY) = 0;

	/// 设置当前字体属性
	/// \param [in] color 要设置的字体颜色
	/// \param [in] style 支持的字体风格
	virtual void SetFont(RGBA32 color, FontStyle style=FS_NORMAL) = 0;

	/// 设置画笔属性
	/// \param [in] color 画笔的颜色
	/// \param [in] style 画笔风格
	/// \param [in] width 画笔宽度
	virtual void SetPen(RGBA32 color, int style=PS_SOLID, int width=1) = 0;

	/// 设置画刷
	/// \param [in] color 设置画刷的颜色
	/// \param [in] style 画刷风格
	virtual void SetBrush(RGBA32 color, int style=BS_NORMAL) = 0;

	/// 设置文本对齐方式
	/// \param [in] align 要设置的文本对齐方式
	virtual void SetTextAlign(int align = TA_LEFTTOP) = 0;

	/// 设置背景模式
	/// \param [in] mode 要设置的背景模式
	virtual void SetBkMode(int mode) = 0;

	/// 得到当前的背景设置模式
	virtual int GetBkMode() = 0;

	/// 设置背景色
	/// \param [in] color 背景色
	virtual void SetBkColor(RGBA32 color) = 0;

	/// 设置区域风格
	/// \param [in] style 要设置的区域风格enum RgnStyle
	virtual void SetRgnStyle(int style) = 0;

	/// 设置画笔宽度
	virtual void SetPenWidth(int width) = 0;

	/// 得到画笔宽度
	virtual int GetPenWidth() = 0;

	/// 画点
	/// \param [in] x 要画点的x坐标
	/// \param [in] y 要画点的y坐标
	/// \param [in] color 要画点的颜色
	virtual void SetPixel(int x, int y, RGBA32 color) = 0;


	/// 得到指定点的RGB坐标值
	/// \param [in] x X坐标
	/// \param [in] y Y坐标
	/// \return 返回指定点的RGB值，改点的值可能和SetPixel值的返回不同(颜色会转换到COLORDEV,再转换回来)
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
	///开机启动图片缩放处理
	virtual void EnlargeBitmap(PCRECT pRect, BITMAP *pBitmap) = 0;
	/// DC 位图复制
	virtual bool BitBlt(PCRECT pRect, IDC* pDC, int start_x = 0, int start_y = 0) = 0;

	/// DC区域操作
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

	/// 设备坐标到逻辑坐标的转换
	/// \param [in/out] point 要转换坐标的点的设备坐标,转换后坐标的点逻辑坐标
	virtual void DPtoLP(CPoint &point) const = 0;

	/// 设备坐标到逻辑坐标的转换
	/// \param [in/out] rect 要转换坐标的矩形的设备坐标,转换后坐标的矩形逻辑坐标
	virtual void DPtoLP(PRECT pRect) const = 0;

	/// 逻辑坐标到设备坐标的转换
	/// \param [in/out] point 要转换坐标的点的逻辑坐标,转换后坐标的点的逻辑坐标
	virtual void LPtoDP(CPoint &point) const = 0;

	/// 逻辑坐标到设备坐标的转换
	/// \param [in/out] point 要转换坐标的点的逻辑坐标,转换后坐标的点的逻辑坐标
	virtual void LPtoDP(PRECT pRect) const = 0;

	/// 使能DC
	/// \param [in] enable 使能标示
	virtual void Enable(bool enable) = 0;

	/// DC锁定
	virtual void Lock() = 0;
	
	/// DC解锁
	virtual void UnLock() = 0;
	
	/// 得到指定区域的点阵灰度图
	/// \param [in] rect 要获得点阵的区域
	/// \param [out] buf 存放获取后的点阵数据
	/// \param [in/out] length 点阵数据缓冲区长度
	virtual bool GetBitmapBits(const CRect &rect, uchar *buf, int *length) = 0;

	/// 得到指定区域的位图
	/// \param [in] rect 要得到位图的区域
	/// \param [out] bitmap 要存放的位图区域,bitmap需要外部接口释放
	/// \return 指定区域的位图
	virtual bool GetBitmap(const CRect &rect, BITMAP *&bitmap) = 0;

	/// 两种颜色增加上各自的分量，并去掉锁结色
	/// \param [in] c 要加的颜色
	/// \param [in] r Red分量
	/// \param [in] g Green分量
	/// \param [in] b Blue分量
	/// \return 运算后的RGB值
	virtual RGBA32 ModulateColor(RGBA32 c, int r, int g, int b) = 0;

protected:
	IDC();
	IDC(const IDC&);
};

#endif
