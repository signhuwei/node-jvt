//
//  "$Id: ImageManager.h 2029 2011-10-09 07:37:09Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  Modify:			ͼ������֣�����ͼ��ļ�����ж��
//

#ifndef __GDI_IMAGE_MANAGER_H__
#define __GDI_IMAGE_MANAGER_H__

#include "Types/Defs.h"
#include "Infra/Singleton.h"
#include "Infra/Mutex.h"
#include "Infra/Packet.h"
#include <string>
#include <map>

/// ͼ����,128�ֽڶ���
struct BITMAP
{
	int		width;		///< ͼ����
	int		height;		///< ͼ��߶�
	int		format;		///< ��ɫ��ʽ��ȡgraphics_color_format_t����ֵ��ֵ��
	int		pitch;		///< ͼ����
	int		reffrence;	///< ͼ�����ü���
	uchar*	bits;		///< ͼ������
	int		l,t,r,b;	///< ����ͼƬ��������,l==r ����t==b��ʾ��ͼƬ��������
	uint	resv[28-6];
};

///
/// \class CImageManger ͼ����أ�ר������ͼ��ļ�����ж��
/// 
class IImageManager
{
public:

	/// ����ͼƬ�������
	static IImageManager* instance();

	/// ����������
	virtual ~IImageManager();

	/// װ��ͼ��
	/// \param [in] filePath Ҫװ�ص�ͼ����Ϣ
	/// \return װ�غ��ͼ����Ϣ
	virtual BITMAP *loadImage(const char *filePath) = 0;

	/// ж��ͼ��
	/// \param [in] image Ҫж�ص�ͼ����Ϣ
	virtual bool releaseImage(BITMAP *image) = 0;

	/// �ڴ�ͼ�񱣴�ɱ���ͼƬ
	/// \param [in] image Ҫ������ڴ�ͼ��
	/// \param [in] filePath ͼ�񱣴�·��
	virtual bool saveScreenImage(BITMAP *pImage, const char* filePath) = 0;

	/// �ڴ�ͼ�񱣴�ɱ���ͼƬ��ͼƬ�ļ�����CPacket��
	/// \param [in] image Ҫ������ڴ�ͼ��
	/// ����ֵ: ����NULL����ʧ�ܣ���NULL����ɹ�
	virtual CPacket* saveScreenImage(BITMAP *pImage) = 0;

	/// ͼ����ɫ�滻
	/// \param [in] pBitmap Ҫ�滻��ɫ��ͼ��
	/// \param [in] matchColor Ҫ�滻����ɫ
	/// \param [in] replaceColor ���滻�ɵ���ɫ
	virtual void replaceImageBits(BITMAP* pBitmap, RGBA32 matchColor, RGBA32 replaceColor) = 0;

	/// ͼ��λͼ�滻
	virtual void replaceImageBits(BITMAP* pBitmap, RGBA32 matchColor, BITMAP * replaceBitmap, int start_x = 0, int start_y = 0) = 0;
	
	/// ��ȡͼ�񱳾���ɫ
	/// \param [in] pBitmap Ҫ��ȡ����ɫ��ͼ��
	/// \param [in] defaultColor Ĭ�ϱ���ɫ
	/// \return ͼ�񱳾�ɫ
	virtual RGBA32 getImageBkColor(BITMAP* pBitmap, RGBA32 defaultColor) = 0;
};

#define g_ImageManager (*IImageManager::instance())
#endif

