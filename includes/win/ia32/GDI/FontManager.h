//
//  "$Id: FontManager.h 744 2010-07-13 07:46:57Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  Modify:			��������࣬ר�Ÿ����������
//

#ifndef __GDI_FONTMANAGER_H__
#define __GDI_FONTMANAGER_H__

#include "Types.h"
#include <string>

/// \class IFontManager �����������������صĹ�����
/// 
class IFontManager
{
public:

	/// �������������ṹ��,��128�ֽ�
	typedef struct tagFontGlyph
	{
		int x;		///< ��ʼx����
		int y;		///< ��ʼy����
		int w;		///< ������
		int h;		///< �����߶�
		int showW;	///< ��ʾ�Ŀ��
		ushort code;	///< �����unicode����
		ushort resv;
		uchar* data;		///< �������ݶ�ά���飬ÿ����������һ���ֽڣ�0-255�ȼ�������
		int resv2[32-7];	///< �����ֽ�
	} FontGlyph;

	/// ��������������128�ֽڶ���
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

	/// ����ʵ��
	static IFontManager* instance();

	/// ��������ĵ����ļ�
	/// \param [in] fontFile ���������ļ�,����Ϊ����.bin�ļ�����.ttfʸ�������ļ�
	/// \param [in] fontFileSmall С�����ļ���ֻ��fontFileΪ.bin�ļ�ʱ����Ч
	static void config(const std::string &fontFile, const std::string &fontFileSmall);

	/// ����������
	virtual ~IFontManager();

	/// �õ��ַ���unicode���뼰�ַ�ռ���ֽ���
	/// \param [in] Ҫ�õ�unicode������ַ�
	/// \param [out] ���ַ��ĳ��ȣ�ASCII��Ϊ1�ֽڳ��ȣ���ͨ�����ı���Ϊ3�ֽڳ���,������ҪUTF-8�����ʽ.
	/// \return ����unicode����
	virtual ushort getCharCode(PCSTR pch, int *pn);

	/// �õ����������
	/// \param [in] code �ַ���unicode���룬ͨ��getCharCode��ȡ
	/// \param [in] fontAttri �������ԣ�������С��
	/// \param [out] pGlyph ��������
	/// \return ���ض�Ӧ����ĵ������
	virtual uchar getCharGlyph(ushort code, const LogFont *fontAttri, FontGlyph* pGlyph = NULL) = 0;

	/// �õ�����ĳ���
	/// \param [in] pStr Ҫ�õ����峤�ȵ��ַ���
	/// \param [in[ len �ַ�������
	/// \param [in] fs �ַ���С���
	/// \return �����ַ�������
	virtual int getTextExtent(const std::string &text, const LogFont *fontAttri = NULL) = 0;

	/// �õ��ı�����
	/// \param [out] pBuffer ����������󻺳�
	/// \param [in] size ���������С
	/// \param [in] text Ҫ��ȡ�������ַ���
	/// \param [in] fontAttri ��������
	/// \return ��ȡ���������Ƿ�ɹ�
	virtual bool getTextRaster(uchar * pBuffer, const Size &size, const std::string &text, const LogFont *fontAttri = NULL) = 0;

	/// ���ı���ʽ�������
	virtual void printRaster(uchar *buf, const Size &size) = 0;
};

#define g_FontManager (*IFontManager::instance())
#endif
