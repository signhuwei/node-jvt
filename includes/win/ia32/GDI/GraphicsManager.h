//
//  "$Id: GraphicsManager.h 447 2010-04-14 12:21:08Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_GRAPHICS_MANAGER_H__
#define __GDI_GRAPHICS_MANAGER_H__

#include "Types.h"
#include "PAL/Garphics.h"

/// 图形设备接口
/// 
class IGraphicsManager 
{
public:

	/// 创建实例
	static IGraphicsManager *instance();

	/// 虚析构函数
	virtual ~IGraphicsManager();

	/// 获取图形绘制缓冲
	/// \param [out] nLayer 指示要获取图形缓冲表面的帧
	/// \param [out] surface 保存获取到的图形帧缓冲结构
	virtual void getSurface(int nLayer, GraphicsSurface *surface) = 0;
	
	/// 得到图层年龄,年龄不同时控件需要更新
	/// \param [in] nLayer 要得到年龄的图层
	/// \return 该图层的年龄
	virtual int getAge(int nLayer) = 0;

	/// 设置图层GUI分辨率
	/// \param [in] 要设置分辨率的图层
	/// \param [in] w x分辨率
	/// \param [in] h y分辨率
	/// \return 设置是否成功
	virtual bool setResolution(int nLayer, int w, int h) = 0;

	/// 更新图形设备缓冲
	/// \return 更新图层是否成功
	virtual bool updateSurface(int nLayer) = 0;


	/// 得到绘制层表面结构
	virtual GraphicsLayer *getGraphicsLayer(int nLayer) = 0;

	/// 得到图形设备矩形区域
	virtual void getRect(int nLayer, PRECT pRect) = 0;

	/// 设置所有图层的GUI透明度
	/// \param [in] alpha alpha透明度
	/// \param [in] delta delta透明度
	virtual void setAlpha(int alpha, int delta = 0) = 0;

	/// 设置所有图层GUI锁结色,锁结色区域只显示视频
	/// \param [in] dwKeyLow 
	/// \param [in] dwKeyHigh
	virtual void setKeyColor(RGBA32 dwKeyLow, RGBA32 dwKeyHigh) = 0;

	/// 得到当前图层的锁结色
	virtual RGBA32 getKeyColor() = 0;
};

#endif
