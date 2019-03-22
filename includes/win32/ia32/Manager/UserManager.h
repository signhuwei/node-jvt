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

	/// �û��ⲿ���ýӿڣ��������û���������ǰ����
	/// \param [in] adminAuthList �����û�Ȩ���б�
	/// \param [in] userAuthList �����û�Ȩ����
	static void config(const Json::Value &adminAuthList, const Json::Value &userAuthList, const std::string &p1, const std::string &p2, const std::string &customPath); 

	/// �����û�����
	virtual bool start() = 0;

	/// ��ȡ����Ȩ���б�
	virtual const Json::Value& getAuthorityList() const = 0;

	/// ������
	/// \param [in] group Ҫ���ӵ���
	virtual bool addGroup(const Json::Value &group) = 0;

	/// ɾ����
	/// \param [in] name ����
	virtual bool delGroup(const std::string &name) = 0;

	/// �޸���
	/// \param [in] name Ҫ�޸ĵ�����
	/// \param [in] newGroup ������Ϣ
	virtual bool modGroup(const std::string &name, const Json::Value &newGroup) = 0;

	/// ����������ȡ����Ϣ
	/// \param [in] name Ҫ��ȡ����Ϣ������
	/// \param [out] group �û��������Ϣ,�ο�<<AuthorityList.doc>>
	virtual bool getGroup(const std::string &name, Json::Value &group) = 0;

	/// ��ȡ��������Ϣ
	/// \return ���������Ϣ, �ο�<<AuthorityList.doc>>
	virtual bool getGroupAll(Json::Value &groups) = 0;

	/// ����û�
	/// \param [in] curUser Ҫ��ӵ��û� 
	/// \param [in] flag �Ƿ�������룬Ĭ�ϼ���
	virtual bool addUser(const Json::Value &curUser, const std::string & flag = "MD5") = 0;

	/// �����û���ɾ���û�
	/// \param [in] name Ҫɾ�����û���
	virtual bool delUser(const std::string &name) = 0;

	/// �����û����޸���Ϣ
	/// \param [in] name Ҫ�޸ĵ��û���
	/// \param [in] user Ҫ�޸ĵ��û���Ϣ, �μ�<<AuthorityList.doc>>
	/// \param [in] flag ������ܱ�ʶ
	virtual bool modUser(const std::string &name, const Json::Value &user, const std::string & flag = "MD5") = 0;

	/// �����û�id�޸��û�����
	/// \param [in] name Ҫ�޸ĵ��û���
	/// \param [in] passwd �µ�����
	/// \param [in] flag �����Ƿ���ܴ��
	virtual bool modPassword(const std::string &name, const std::string &passwd, const std::string & flag = "MD5") = 0;

	/// �����û�����ȡ�û���Ϣ
	/// \param [in] name Ҫ��ȡ�û���Ϣ���û���
	/// \param [out] user ����û���Ϣ, �μ�<<AuthorityList.doc>>
	virtual bool getUser(const std::string &name, Json::Value &user) = 0;

	/// ��ȡ�����û�, �μ�<<AuthorityList.doc>>
	/// \return �����û�����Ϣ
	virtual bool getUserAll(Json::Value &users) = 0;

	/// ��ԭĬ��
	virtual bool setDefault() = 0;

	/// ����������Ϣ
	virtual bool saveFile() = 0;

	/// �ж��û��Ƿ��Ǳ����û�
	virtual bool isReservedUser(const std::string& userName) = 0;

	/// �ж��û��Ƿ���Ĭ���û�
	virtual bool isDefaultUser(const std::string& userName) = 0;

	/// �ж����ύ�������Ƿ�Ϸ�
	/// \param [in] name �û���
	/// \param [in] passwd �û�����
	/// \param [in] flag ���뱣�淽ʽ�����Ļ�������
	/// \param [in] superPwdValid ��ʱ��������
	virtual bool isPasswdValid(const std::string &name, const std::string &passwd,	const std::string & flag = "MD5",  bool superPwdValid = false) = 0;

	/// �õ����л�û���ID�б�
	virtual std::vector<int> getActiveUserIdList() = 0;

	/// �õ���û�
	virtual IUser* getActiveUser(int id) = 0;

	/// �����û����õ��õ���û�
	virtual IUser* getActiveUser(const std::string &userName) = 0;

	/// �ͷŻ�û��������GetActiveUser�ɶԵ��ã�����֤���������
	virtual void releaseActiveUser(IUser* user) = 0;

	// ��ַ��������
	virtual void onAccessFilter(const Json::Value& xchg, int& ret) = 0;

	/// �Ƿ��ǺϷ��ĵ�ַ
	virtual bool isAllowedAddress(const std::string &address) = 0;

	/// ���ô�����
	virtual void setLastError(int error) = 0;

	/// ��ȡ������
	virtual int getLastError() const = 0;

	/// �����ʻ�
	/// \param [in] name Ҫ�����˺ŵ��û���
	/// \param [in] second Ҫ������ʱ��(��Ϊ��λ)
	/// \return �����û��Ƿ�ɹ�
	virtual bool setLock(const std::string &name, int second) = 0;

	/// �Ƿ�Ϊ�����ʻ�
	virtual bool isLockUser(const std::string &name) = 0;

	/// �õ�Ĭ���û���
	virtual std::string getDefaultUser() const = 0;

	/// �õ�Ĭ���û�����
	virtual std::string getDefaultPassword() const = 0;

	/// �õ��������ڣ�msΪ��λ
	virtual int getLockPeriod() const = 0;

	/// �����������ʱ�ĵ�½����
	virtual int getTryLoginTimes() const = 0;

	/// �����û�
	virtual bool addActiveUser(IUser* user) = 0;

	/// ɾ����û�
	virtual bool removeActiveUser(IUser* user) = 0;

	/// ���û����Ƿ��Ѿ���½
	virtual bool isUserLogined(const std::string& userName) = 0;

	/// �Ƿ�Ϊ�����û�
	virtual bool isUserSharable(const std::string& userName) = 0;

	/// ָ�����Ƿ���ʹ��
	virtual bool isGroupInUse(const std::string &userName) = 0;

	/// �����û��������û���λ������
	virtual bool hasAuthorityOf(const std::string &userName, const char* auth) = 0;

	/// �����û��������û���λ������
	virtual int findUser(const std::string &userName) = 0;

	/// �����û��������û���λ������
	virtual int findGroup(const std::string &groupName) = 0;

	
	///��ԭԤ���ͻط�ͨ��Ȩ��
	virtual bool setDefaultChnsAuthority(int devChns) = 0;
};

#define g_userManager (*IUserManager::instance())
#endif
