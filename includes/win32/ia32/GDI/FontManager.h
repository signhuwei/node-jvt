//
//  "$Id: FontManager.h 744 2010-07-13 07:46:57Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  Modify:			字体管理类，专门负责字体管理
//

#ifndef __GDI_FONTMANAGER_H__
#define __GDI_FONTMANAGER_H__

#include "Types.h"
#include <string>

/// \class IFontManager 字体管理，负责字体相关的管理工作
/// 
class IFontManager
{
public:

	/// 字体轮廓描述结构体,共128字节
	typedef struct tagFontGlyph
	{
		int x;		///< 起始x坐标
		int y;		///< 起始y坐标
		int w;		///< 点阵宽度
		int h;		///< 点整高度
		int showW;	///< 显示的宽度
		ushort code;	///< 字体的unicode编码
		ushort resv;
		uchar* data;		///< 点阵数据二维数组，每个像素暂用一个字节，0-255等级反走样
		int resv2[32-7];	///< 保留字节
	} FontGlyph;

	/// 字体属性描述，128字节对齐
	typedef struct tagLogFont 
	{ 
		ulong lfWidth; 
		ulong lfHeight; 
		uchar lfItalic; 
		uchar lfUnderline; 
		uchar lfStrikeOut; 
		uchar lfBold; 
		uchar lfScaling;
		uchar Reserved[3];
		uint resv[32-4];
	} LogFont; 

	/// 创建实例
	static IFontManager* instance();

	/// 设置字体的点阵文件
	/// \param [in] fontFile 正常字体文件,可以为点阵.bin文件或者.ttf矢量字体文件
	/// \param [in] fontFileSmall 小字体文件，只有fontFile为.bin文件时才有效
	static void config(const std::string &fontFile, const std::string &fontFileSmall);

	/// 虚析构函数
	virtual ~IFontManager();

	/// 得到字符的unicode编码及字符占用字节数
	/// \param [in] 要得到unicode编码的字符
	/// \param [out] 该字符的长度，ASCII码为1字节长度，普通的中文编码为3字节长度,传入需要UTF-8编码格式.
	/// \return 返回unicode编码
	virtual ushort getCharCode(PCSTR pch, int *pn);

	/// 得到字体的轮廓
	/// \param [in] code 字符的unicode编码，通过getCharCode获取
	/// \param [in] fontAttri 字体属性，包括大小等
	/// \param [out] pGlyph 字体轮廓
	/// \return 返回对应字体的点正宽度
	virtual uchar getCharGlyph(ushort code, const LogFont *fontAttri, FontGlyph* pGlyph = NULL) = 0;

	/// 得到字体的长度
	/// \param [in] pStr 要得到字体长度的字符串
	/// \param [in[ len 字符串长度
	/// \param [in] fs 字符大小风格
	/// \return 返回字符串长度
	virtual int getTextExtent(const std::string &text, const LogFont *fontAttri = NULL) = 0;

	/// 得到文本点阵
	/// \param [out] pBuffer 保存输出点阵缓冲
	/// \param [in] size 点阵输出大小
	/// \param [in] text 要获取点整的字符串
	/// \param [in] fontAttri 字体属性
	/// \return 获取点阵数据是否成功
	virtual bool getTextRaster(uchar * pBuffer, const Size &size, const std::string &text, const LogFont *fontAttri = NULL) = 0;

	/// 以文本形式输出点阵
	virtual void printRaster(uchar *buf, const Size &size) = 0;
};

#define g_FontManager (*IFontManager::instance())
#endif
