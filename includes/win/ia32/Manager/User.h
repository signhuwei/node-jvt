//
//  "$Id: User.h 874 2010-08-07 08:00:20Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:			2008-11-30 liwj create the file
//  
//

#ifndef __MANAGER_USER_H__
#define __MANAGER_USER_H__

#include <string>

class IUser
{
public:
	/// 本地用户
	static IUser *getLocalUser();

	/// 创建新的用户
	static IUser *create();

	/// 当前用户是否登陆成功
	virtual bool valid() = 0;

	/// 用户登陆
	/// \param [in] name 要登陆的用户名
	/// \param [in] passwd 用户的登陆密码
	/// \param [in] type 客户端类型
	/// \param [in] flag 密码保存方式，密文方式或者明文方式
	/// \param [in] address 客户端的地址，比如192.168.0.2 而本地没有地址
	/// \return 登陆成功或者失败
	virtual bool login(const std::string &name, const std::string &passwd, const std::string &loginType, const std::string &flag = "MD5",  const std::string &address = "") = 0;

	/// 用户注销
	virtual bool logout() = 0;

	/// 获取登陆用户名
	virtual const std::string &getName() const = 0;

	/// 获取客户端类型
	virtual const std::string &getType() const = 0;

	/// 获取客户端地址
	virtual const std::string &GetAddress() const = 0;

	/// 获取有效的用户ID
	virtual int getId() const = 0;

	/// 检查权限是否有效
	virtual bool isValidAuthority(const char *auth) const = 0;

	/// 获取错误号
	virtual int getErrorNo() = 0;

	/// 默认用户登陆
	virtual bool loginDefault() = 0;
};

#define g_localUser (*IUser::getLocalUser())
#endif
