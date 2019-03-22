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

	/// 设置语言路径，必须在所有语言调用之前被调用
	static void config(std::string langpath);

	/// 创建单件实例
	static ILocales *instance();

	/// 设置语言
	/// \note 设置的语言必须在系统支持的语言集列表内，否则失败.
	virtual void setLanguage(std::string language) = 0;

	/// 得到支持的语言列表
	/// \return 系统支持的语言集列表
	virtual const LanguageList& getLanguageList() = 0;
};

PCSTR GetParsedString(PCSTR key);

#endif


