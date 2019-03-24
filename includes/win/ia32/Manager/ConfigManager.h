//
//  "$Id: ConfigManager.h 4221 2012-08-21 02:05:51Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __MANAGER_CONFIGMANAGER_H__
#define __MANAGER_CONFIGMANAGER_H__

#include "Infra/Types.h"
#include "Infra/Signals.h"
#include <Json/value.h>
#include "ExchangeAL/Exchange.h"

/// 配置管理实现类
/// 
class IConfigManager
{
public:
	/// 配置应用结果，按位表示，由配置的观察者设置，配置的提交者检查
	enum ConfigApply
	{
		applyOK				= 0,			/// 成功
		applyNeedReboot		= 0x00000002,	/// 需要重启系统
		applyFileError		= 0x00000004,	/// 写文件出错
		applyValiateFailed	= 0x00000020,	/// 验证失败 
		applyNotExist		= 0x00000040,	/// 配置不存在 
		applyNotSave		= 0x00000080,	/// 不要保存到文件
		applyDelaySave		= 0x00000100,	/// 延时保存..
		applyNotWriteLog	= 0x00000200,	/// 不保存日志
	};

	/// 配置更新信号定义，信号的参数分别为配置基类的引用和配置应用的结果。
	/// 观察者函数中可以对配置应用结构进行修改，取ApplyOptions类型的位与值，
	/// 当所有的回调函数被调用后，就可以通过这个值得到整个的应用结果。
	typedef TSignal2<const Json::Value &, int &> Signal;

	/// 配置观察者回调函数定义
	typedef Signal::SigProc Proc;

	/// 配置变更钩子函数，允许用户在修改配置或者设置配置中途变更配置
	/// 目前该操作对配置管理透明，修改后的配置将不会再进行校验相关操作
	/// 配置的合法性需要使用者自己保证
	typedef TSignal2<Json::Value &, int &> HookSignal;

	/// 钩子回调函数
	typedef HookSignal::SigProc HookProc;

public:
	
	/// 获取实例句柄
	static IConfigManager *instance();

	/// 虚析构函数
	virtual ~IConfigManager();

	///< 初始化，启动配置管理
	virtual void start() = 0;

	/// 配置接口
	/// \param [in] firstDir 主配置文件的存放目录
	/// \param [in] secondDir 备份配置文件的存放目录
	/// \param [in] customDir 用户自定义配置文件的存放目录
	static void config(const char *firstDir, const char *secondDir, const char *customDir);

	/// 删除配置文件，需要重启，重启后所有默认被恢复成默认配置
	/// \param user 用户名
	virtual void deleteFile(const char* user = NULL) = 0;

	// 得到最新的配置结构
	/// \param [in] name 配置名称
	/// \param [out] table 配置表
	/// \note name遵循如下语法规则
	/// 单一个字符串将取整个配置
	/// 字符串后跟[%d], .key代表要访问相应的配置项
	/// - "." => 根节点，和name和name.意义一样
	/// - ".key" => 访问配置内名为key的配置项
	/// - ".[n]" => 访问撇之内第n+1个配置项
	/// 以上过程可以递归
	/// 比如访问录像配置name为getConfigName(CFG_RECORD)
	/// 访问第一通道的录像配置name为"Record.[0]"
	/// 访问第一通道录像配置的时间段的配置为"Record.[0].TimeSection"
	virtual bool getConfig(const char* name, Json::Value& table) = 0;

	/// 提交配置，含合法性检查，调用saveFile函数保存文件。
	/// \param name 配置名称
	/// \param table 新的配置
	/// \param index 配置序号
	/// \param user 用户名
	/// \param applyOptions 返回值初始值，取ApplyOptions位与值。
	/// \param notifyParent 回调时通知上层节点的回调函数
	/// \return 配置应用的结果，取ApplyOptions位与值，applyOptions作为返回值的初始值。
	/// \note name的语法参见getConfig()
	virtual int setConfig(const char* name, const Json::Value& table, const char* user = 0, int applyOptions = applyDelaySave) = 0;

	/// 获得最新配置的引用, 该函数只能在配置校验的回调函数里使用
	/// \param [in] name 要取的配置的路径
	virtual const Json::Value& resolveConfig(const char *name) = 0;

	// 得到默认的配置表
	/// \param [in] name 配置名称
	/// \param [out] 配置表
	virtual bool getDefault(const char* name, Json::Value& table) = 0;

	/// 设置默认配置表，一般对每个配置在初始化时调用一次即可，必须在配置使用之前调用
	/// 此函数仅供CConfigManager调用。
	/// \param [in] name 配置名称
	/// \param table 默认配置表
	virtual void setDefault(const char* name, const Json::Value& table, bool bProduceConfig = false) = 0;

	/// 注册配置变化观察者函数。
	/// \param name 配置名称
	/// \param proc 观察者函数
	/// \retval >0 当前已经注册的观察者数目。
	/// \return <0 TSignalN::ErrorCode类型的值。
	virtual int attach(const char* name, Proc proc) = 0;

	/// 注销配置变化观察者函数。
	/// \param name 配置名称
	/// \param proc 观察者函数
	/// \retval >=0 当前已经注册的观察者数目。
	/// \return <0 TSignalN::ErrorCode类型的值。
	virtual int detach(const char* name, Proc proc) = 0;

	/// 注册配置校验观察者函数, 必须配置使用前调用。
	/// \param name 配置名称
	/// \param proc 观察者函数
	/// \retval >0 当前已经注册的观察者数目。
	/// \return <0 TSignalN::ErrorCode类型的值。
	virtual int attachVerify(const char* name, Proc proc) = 0;

	/// 注销配置校验观察者函数。
	/// \param name 配置名称
	/// \param proc 观察者函数
	/// \retval >=0 当前已经注册的观察者数目。
	/// \return  <0 TSignalN::ErrorCode类型的值。
	virtual int detachVerify(const char* name, Proc proc) = 0;

	/// 注册钩子函数
	/// \param [in] name 要观察的配置名称
	/// \param [in] pObj 钩子对象指针
	/// \param [in] proc 钩子函数指针
	/// \retval >= 0 当前已经注册的观察者函数
	/// \retval < 0 TSignalN::ErrorCode类型的值
	virtual int hooks(const char *name, HookProc proc) = 0;

	/// 恢复到上一次正确的配置
	virtual void restore() = 0;

	/// 保存配置文件
	virtual void saveFile() = 0;
};

#define g_configManager (*IConfigManager::instance())
#endif 
