//
//  "$Id: Log.h 874 2010-08-07 08:00:20Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:	
//  
//

#ifndef __MANAGER_LOG_H__
#define __MANAGER_LOG_H__

#include "Infra/Time.h"
#include "Infra/Signals.h"

///
/// 日志管理部分，用于记录系统运行过程中的一些关键事件方便系统的维护和调试，
/// 目前日志全部采用字符串的形式存储方便然日后扩展。
/// 日志内容部分和日志文件头部分分开存放，方便扩展
/// 
class ILog 
{
public:
	/// 日志更新信号定义，信号的参数分别为日志类型，日志数据，日志发生时间
	typedef TSignal3<std::string, std::string, DateTime> SIG_LOG;

	/// 配置观察者回调函数定义
	typedef SIG_LOG::SigProc Proc;

	enum 
	{
		defaultMaxItems		= 2048,		///< 默认的最大日志条数
		itemTypeLength		= 24,		///< 日志项中最大的数据长度
		itemDataLength		= 68,		///< 日志项中最大的数据长度
		itemUserNameLength	= 32,		///< 日志项中最大用户名长度
		itemLength			= 128,		///< 日志项长度
	};

	/// 整个日志项长度128字节
	/// 日志记录格式Year-Month-Day Hour:Minute:Second[User],[Type],[Data]
	struct Item
	{
		char	type[itemTypeLength];		///< 日志类型
		char	data[itemDataLength];		///< 日志内容
		char	user[itemUserNameLength];	///< 日志用户名
		DateTime	time;						///< 事件产生时间
	};

	/// 构造函数
	static ILog* instance();

	/// 虚析构函数
	virtual ~ILog();

	/// \param [in] maxLogItem 最大日志条数
	/// \param [in] logFilePath 日志文件路径
	static void config(int maxLogItem, const char *logFilePath);
	
	/// 记录日志，同时加上日志记录的时间。
	/// \param  type 日志类型，如"SaveConfig"
	/// \param  data 日志数据具体格式有datafmt传入，详细见《配置交换格式.doc》
	virtual void append(const char* type, const char* datafmt = NULL, ...) = 0;

	/// 清除日志，同时自动产生一条清除日志的日志记录。
	/// \param  user 日志产生时对用的用户名。
	virtual void clear(const char *user) = 0;

	/// 得到日志总条数。
	virtual uint size() = 0;

	/// 读取日志项结构
	/// \param pos 日志项数，[0, size()-1]
	/// \param item 日志项。
	/// \return 读取日志是否成功
	virtual bool get(uint pos, Item& item) = 0;

	/// 注册回调, 产生日志时将会调用该回调
	virtual bool attach(Proc proc) = 0;

	/// 注销回调
	virtual bool detach(Proc proc) = 0;

	/// 保存文件
	virtual bool saveFile() = 0;
};

#define g_logManager (*ILog::instance())
#endif
