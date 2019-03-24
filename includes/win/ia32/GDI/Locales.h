//
//  "$Id: Locales.h 744 2010-07-13 07:46:57Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//


#ifndef __GDI_LOCALES_H__
#define __GDI_LOCALES_H__

#include "Types/Defs.h"
#include <string>
#include <vector>

class ILocales
{
public:

	typedef std::vector<std::string> LanguageList;

	/// ��������·�����������������Ե���֮ǰ������
	static void config(std::string langpath);

	/// ��������ʵ��
	static ILocales *instance();

	/// ��������
	/// \note ���õ����Ա�����ϵͳ֧�ֵ����Լ��б��ڣ�����ʧ��.
	virtual void setLanguage(std::string language) = 0;

	/// �õ�֧�ֵ������б�
	/// \return ϵͳ֧�ֵ����Լ��б�
	virtual const LanguageList& getLanguageList() = 0;
};

PCSTR GetParsedString(PCSTR key);

#endif


