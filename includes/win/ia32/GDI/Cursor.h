//
//  "$Id: Cursor.h 2863 2012-03-26 09:18:37Z chenchangbao $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_CURSOR_H__
#define __GDI_CURSOR_H__

#include "Types.h"
#include <string>

class ICursor
{
public:

	/// 鼠标形状枚举类型
	enum Shape
	{
		shapeNormal,	///< 普通
		shapeBusy,		///< 忙
		shapeWait,		///< 等待
		shapeMove,		///< 移动
		shapeSize1,		///< 正斜拖动
		shapeSize2,		///< 反斜拖动
		shapeSize3,		///< 左右拖动
		shapeSize4,		///< 上下拖动
		shapeZoomin,	///< 放大
		shapeNr			///< 全部
	};

	/// 单件类
	static ICursor* instance();

	/// 虚析构函数
	virtual ~ICursor();

	/// 加载光标
	/// \param [in] path 要加载的光标文件路径(.ico结尾的文件)
	/// \param [in] shape 路径对应的光标形状标示，取enum Shape
	/// \return 加载光标是否成功
	static bool loadCursor(const std::string &path, Shape shape);
	
	/// 设置当前光标形状
	/// \param [in] shape 要设置的光标形状
	virtual void setCursor(Shape shape) = 0;

	/// 得到光标当前的形状
	virtual Shape getCursor() = 0;

	/// 设置光标位置
	/// \param [in] x 要设置光标位置的x坐标
	/// \param [in] y 要设置光标位置的y坐标
	/// \param [in] update 是否更新光标
	virtual void setCursorPos(int x, int y, bool update = false) = 0;

	/// 得到光标当前的位置
	/// \param [out] pPoint 当前光标的位置
	virtual void getCursorPos(PPOINT pPoint) = 0;

	/// 显示,隐藏光标
	/// \param [in] bShow true代表显示光标,false代表影藏光标
	virtual void showCursor(bool bShow) = 0;

	/// 使能,禁用光标
	/// \param [in] 是否使能光标
	virtual void enableCursor(bool bEnable) = 0;
};

#endif
