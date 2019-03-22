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

/// \brief ϵͳ����̨������
/// ʵ�ּ򵥵Ŀ���̨���ܣ�ʹ������Ҫע���������Ŀ���̨��������
///
class IConsole
{
public:

	typedef TFunction2<int, int, char**> Proc;

	/// ����̨����
	struct Command 
	{
		Proc proc;
		std::string	helpSting;
	};

public:
	/// ���ص���ʵ��
	static IConsole* instance();

	/// ����������
	virtual ~IConsole();

	/// ��������̨
	virtual bool start() = 0;

	/// ֹͣ����̨
	virtual bool stop() = 0;

	/// ע�����̨����
	/// \param [in] cmd Ҫע��Ŀ���̨����
	/// \param [in] cmdDesc ��Ӧ����������������������������������ʾ�ַ�����.
	/// \return ע������ص������Ƿ�ɹ�
	virtual bool attach(const std::string &cmd, const Command &cmdDesc) = 0;

	/// ע������̨����
	/// \param [in] cmd Ҫע��Ŀ���̨����
	/// \return ע������ص������Ƿ�ɹ�
	virtual bool detach(const std::string &cmd) = 0;
};

#endif

