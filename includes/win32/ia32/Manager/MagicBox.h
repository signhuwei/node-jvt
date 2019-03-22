//
//  "$Id: MagicBox.h 1858 2011-08-08 05:59:22Z chenchangbao $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  
//

#ifndef __MANAGER_MAGICBOX_H__
#define __MANAGER_MAGICBOX_H__

#include "Infra/Time.h"
#include <Json/value.h>
#include <string>

class IMagicBox
{
public:
	
	/// 单件实例
	static IMagicBox *instance();

	/// 虚析构函数
	virtual ~IMagicBox();

	/// 启动魔盒
	virtual void start() = 0;

	/// 得到产品定义表格
	virtual const Json::Value &getProductDefinition() = 0;

	/// 关闭系统
	virtual void shutdown() = 0;

	/// 重启系统
	virtual void reboot() = 0;

	/// 得到系统运行的时间
	/// \return 返回系统从出厂测试到运行总共运行的分钟数
	virtual uint getRunningTime() = 0;

	/// 得到系统试用时间
	/// \param [in\out] days 系统使用天数
	/// \return 只有试用版本该接口才返回成功，正式版本该接口将返回失败
	virtual bool getTrailDays(int &days) = 0;

	/// 蜂鸣器蜂鸣
	virtual void beep(uint dwFrequence, uint dwDuration) = 0;

	/// 得到系统关机时间
	virtual void getExitTime(DateTime *time) = 0;

	/// 是否显示XM的信息
	virtual bool IsShowXMInfo() = 0;

	/// 开启CPU看门狗
	virtual bool WatchDogStart() = 0;
};

#define g_magicBox (*IMagicBox::instance())
#endif 
