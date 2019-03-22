//
//  "$Id: ImageManager.h 2029 2011-10-09 07:37:09Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  Modify:			图像管理部分，负责图像的加载与卸载
//

#ifndef __GDI_IMAGE_MANAGER_H__
#define __GDI_IMAGE_MANAGER_H__

#include "Types/Defs.h"
#include "Infra/Singleton.h"
#include "Infra/Mutex.h"
#include "Infra/Packet.h"
#include <string>
#include <map>

/// 图像定义,128字节对齐
struct BITMAP
{
	int		width;		///< 图像宽度
	int		height;		///< 图像高度
	int		format;		///< 颜色格式，取graphics_color_format_t类型值的值。
	int		pitch;		///< 图像跨度
	int		reffrence;	///< 图像引用计数
	uchar*	bits;		///< 图像数据
	int		l,t,r,b;	///< 缩放图片缩放区域,l==r 或者t==b表示该图片不可缩放
	uint	resv[28-6];
};

///
/// \class CImageManger 图像加载，专门用于图像的加载与卸载
/// 
class IImageManager
{
public:

	/// 创建图片管理对象
	static IImageManager* instance();

	/// 虚析构函数
	virtual ~IImageManager();

	/// 装载图像
	/// \param [in] filePath 要装载的图像信息
	/// \return 装载后的图像信息
	virtual BITMAP *loadImage(const char *filePath) = 0;

	/// 卸载图像
	/// \param [in] image 要卸载的图像信息
	virtual bool releaseImage(BITMAP *image) = 0;

	/// 内存图像保存成本地图片
	/// \param [in] image 要保存的内存图像
	/// \param [in] filePath 图像保存路径
	virtual bool saveScreenImage(BITMAP *pImage, const char* filePath) = 0;

	/// 内存图像保存成本地图片，图片文件放在CPacket中
	/// \param [in] image 要保存的内存图像
	/// 返回值: 返回NULL保存失败，非NULL保存成功
	virtual CPacket* saveScreenImage(BITMAP *pImage) = 0;

	/// 图像颜色替换
	/// \param [in] pBitmap 要替换颜色的图像
	/// \param [in] matchColor 要替换的颜色
	/// \param [in] replaceColor 被替换成的颜色
	virtual void replaceImageBits(BITMAP* pBitmap, RGBA32 matchColor, RGBA32 replaceColor) = 0;

	/// 图像位图替换
	virtual void replaceImageBits(BITMAP* pBitmap, RGBA32 matchColor, BITMAP * replaceBitmap, int start_x = 0, int start_y = 0) = 0;
	
	/// 获取图像背景颜色
	/// \param [in] pBitmap 要获取背景色的图像
	/// \param [in] defaultColor 默认背景色
	/// \return 图像背景色
	virtual RGBA32 getImageBkColor(BITMAP* pBitmap, RGBA32 defaultColor) = 0;
};

#define g_ImageManager (*IImageManager::instance())
#endif

