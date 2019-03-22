//
//  "$Id: UserManager.h 1908 2011-08-22 05:41:30Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:			2008-11-30 liwj create the file
//  
//

#ifndef __MANAGER_USERMANAGER_H__
#define __MANAGER_USERMANAGER_H__

#include <Json/value.h>
#include <string>

class IUser;
class IUserManager
{
public:
	static IUserManager *instance();

	virtual ~IUserManager();

	/// 用户外部配置接口，必须在用户管理启动前调用
	/// \param [in] adminAuthList 管理用户权限列表
	/// \param [in] userAuthList 管理用户权限数
	static void config(const Json::Value &adminAuthList, const Json::Value &userAuthList, const std::string &p1, const std::string &p2, const std::string &customPath); 

	/// 启动用户管理
	virtual bool start() = 0;

	/// 获取整个权限列表
	virtual const Json::Value& getAuthorityList() const = 0;

	/// 增加组
	/// \param [in] group 要增加的组
	virtual bool addGroup(const Json::Value &group) = 0;

	/// 删除组
	/// \param [in] name 组名
	virtual bool delGroup(const std::string &name) = 0;

	/// 修改组
	/// \param [in] name 要修改的组名
	/// \param [in] newGroup 新组信息
	virtual bool modGroup(const std::string &name, const Json::Value &newGroup) = 0;

	/// 根据组名获取组信息
	/// \param [in] name 要获取组信息的组名
	/// \param [out] group 用户存放组信息,参考<<AuthorityList.doc>>
	virtual bool getGroup(const std::string &name, Json::Value &group) = 0;

	/// 获取所有组信息
	/// \return 所有组的信息, 参考<<AuthorityList.doc>>
	virtual bool getGroupAll(Json::Value &groups) = 0;

	/// 添加用户
	/// \param [in] curUser 要添加的用户 
	/// \param [in] flag 是否加密密码，默认加密
	virtual bool addUser(const Json::Value &curUser, const std::string & flag = "MD5") = 0;

	/// 根据用户名删除用户
	/// \param [in] name 要删除的用户名
	virtual bool delUser(const std::string &name) = 0;

	/// 根据用户名修改信息
	/// \param [in] name 要修改的用户名
	/// \param [in] user 要修改的用户信息, 参见<<AuthorityList.doc>>
	/// \param [in] flag 密码加密标识
	virtual bool modUser(const std::string &name, const Json::Value &user, const std::string & flag = "MD5") = 0;

	/// 根据用户id修改用户密码
	/// \param [in] name 要修改的用户名
	/// \param [in] passwd 新的密码
	/// \param [in] flag 密码是否加密存放
	virtual bool modPassword(const std::string &name, const std::string &passwd, const std::string & flag = "MD5") = 0;

	/// 根据用户名获取用户信息
	/// \param [in] name 要获取用户信息的用户名
	/// \param [out] user 存放用户信息, 参见<<AuthorityList.doc>>
	virtual bool getUser(const std::string &name, Json::Value &user) = 0;

	/// 获取所有用户, 参见<<AuthorityList.doc>>
	/// \return 所有用户的信息
	virtual bool getUserAll(Json::Value &users) = 0;

	/// 还原默认
	virtual bool setDefault() = 0;

	/// 保存所有信息
	virtual bool saveFile() = 0;

	/// 判断用户是否是保留用户
	virtual bool isReservedUser(const std::string& userName) = 0;

	/// 判断用户是否是默认用户
	virtual bool isDefaultUser(const std::string& userName) = 0;

	/// 判断所提交的密码是否合法
	/// \param [in] name 用户名
	/// \param [in] passwd 用户密码
	/// \param [in] flag 密码保存方式，明文或者秘文
	/// \param [in] superPwdValid 暂时用作保留
	virtual bool isPasswdValid(const std::string &name, const std::string &passwd,	const std::string & flag = "MD5",  bool superPwdValid = false) = 0;

	/// 得到所有活动用户的ID列表
	virtual std::vector<int> getActiveUserIdList() = 0;

	/// 得到活动用户
	virtual IUser* getActiveUser(int id) = 0;

	/// 根据用户名得到得到活动用户
	virtual IUser* getActiveUser(const std::string &userName) = 0;

	/// 释放活动用户，必须和GetActiveUser成对调用，并保证间隔尽量短
	virtual void releaseActiveUser(IUser* user) = 0;

	// 地址过滤配置
	virtual void onAccessFilter(const Json::Value& xchg, int& ret) = 0;

	/// 是否是合法的地址
	virtual bool isAllowedAddress(const std::string &address) = 0;

	/// 设置错误编号
	virtual void setLastError(int error) = 0;

	/// 获取错误编号
	virtual int getLastError() const = 0;

	/// 锁定帐户
	/// \param [in] name 要锁定账号的用户名
	/// \param [in] second 要锁定的时间(秒为单位)
	/// \return 锁定用户是否成功
	virtual bool setLock(const std::string &name, int second) = 0;

	/// 是否为锁定帐户
	virtual bool isLockUser(const std::string &name) = 0;

	/// 得到默认用户名
	virtual std::string getDefaultUser() const = 0;

	/// 得到默认用户密码
	virtual std::string getDefaultPassword() const = 0;

	/// 得到锁定周期，ms为单位
	virtual int getLockPeriod() const = 0;

	/// 返回密码错误时的登陆次数
	virtual int getTryLoginTimes() const = 0;

	/// 加入活动用户
	virtual bool addActiveUser(IUser* user) = 0;

	/// 删除活动用户
	virtual bool removeActiveUser(IUser* user) = 0;

	/// 该用户名是否已经登陆
	virtual bool isUserLogined(const std::string& userName) = 0;

	/// 是否为共享用户
	virtual bool isUserSharable(const std::string& userName) = 0;

	/// 指定组是否在使用
	virtual bool isGroupInUse(const std::string &userName) = 0;

	/// 根据用户名查找用户的位置索引
	virtual bool hasAuthorityOf(const std::string &userName, const char* auth) = 0;

	/// 根据用户名查找用户的位置索引
	virtual int findUser(const std::string &userName) = 0;

	/// 根据用户名查找用户的位置索引
	virtual int findGroup(const std::string &groupName) = 0;

	
	///还原预览和回放通道权限
	virtual bool setDefaultChnsAuthority(int devChns) = 0;
};

#define g_userManager (*IUserManager::instance())
#endif
