//
//  "$Id: InputMethod.h 447 2010-04-14 12:21:08Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_INPUT_METHOD_H__
#define __GDI_INPUT_METHOD_H__

#include "Types/Defs.h"

class IInputManager
{
public:
	enum KeyInputType
	{
		KI_NUMERIC,		//数字
		KI_UPPERCASE,	//大写字母
		KI_LOWERCASE,	//小写字母
		KI_MARK,		//常用符号
		KI_PINYIN,		//拼音输入
		KI_CONTROL,		//ATM原始控制键
		KI_ALL,
	};

	static IInputManager *instance();
	virtual ~IInputManager();

	virtual bool Open(PCSTR table) = 0;
	virtual void Close() = 0;
	virtual int Filter(PCSTR key) = 0;
	virtual PCSTR GetChar(int offset) = 0;
};

#endif
