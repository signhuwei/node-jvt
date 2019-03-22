//
//  "$Id: Console.h 933 2010-08-14 05:35:06Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __MANAGER_CONSOLE_H__
#define __MANAGER_CONSOLE_H__

#include "Infra/Function.h"
#include <string>

/// \brief 系统控制台管理部分
/// 实现简单的控制台功能，使用是需要注册相关命令的控制台函数即可
///
class IConsole
{
public:

	typedef TFunction2<int, int, char**> Proc;

	/// 控制台命令
	struct Command 
	{
		Proc proc;
		std::string	helpSting;
	};

public:
	/// 返回单件实例
	static IConsole* instance();

	/// 虚析构函数
	virtual ~IConsole();

	/// 开启控制台
	virtual bool start() = 0;

	/// 停止控制台
	virtual bool stop() = 0;

	/// 注册控制台命令
	/// \param [in] cmd 要注册的控制台命令
	/// \param [in] cmdDesc 相应命令的命令描述，包括命令处理函数、命令提示字符串等.
	/// \return 注册命令回调函数是否成功
	virtual bool attach(const std::string &cmd, const Command &cmdDesc) = 0;

	/// 注销控制台命令
	/// \param [in] cmd 要注册的控制台命令
	/// \return 注销命令回调函数是否成功
	virtual bool detach(const std::string &cmd) = 0;
};

#endif

