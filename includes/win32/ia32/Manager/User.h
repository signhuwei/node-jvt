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
	/// �����û�
	static IUser *getLocalUser();

	/// �����µ��û�
	static IUser *create();

	/// ��ǰ�û��Ƿ��½�ɹ�
	virtual bool valid() = 0;

	/// �û���½
	/// \param [in] name Ҫ��½���û���
	/// \param [in] passwd �û��ĵ�½����
	/// \param [in] type �ͻ�������
	/// \param [in] flag ���뱣�淽ʽ�����ķ�ʽ�������ķ�ʽ
	/// \param [in] address �ͻ��˵ĵ�ַ������192.168.0.2 ������û�е�ַ
	/// \return ��½�ɹ�����ʧ��
	virtual bool login(const std::string &name, const std::string &passwd, const std::string &loginType, const std::string &flag = "MD5",  const std::string &address = "") = 0;

	/// �û�ע��
	virtual bool logout() = 0;

	/// ��ȡ��½�û���
	virtual const std::string &getName() const = 0;

	/// ��ȡ�ͻ�������
	virtual const std::string &getType() const = 0;

	/// ��ȡ�ͻ��˵�ַ
	virtual const std::string &GetAddress() const = 0;

	/// ��ȡ��Ч���û�ID
	virtual int getId() const = 0;

	/// ���Ȩ���Ƿ���Ч
	virtual bool isValidAuthority(const char *auth) const = 0;

	/// ��ȡ�����
	virtual int getErrorNo() = 0;

	/// Ĭ���û���½
	virtual bool loginDefault() = 0;
};

#define g_localUser (*IUser::getLocalUser())
#endif
