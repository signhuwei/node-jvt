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
		KI_NUMERIC,		//����
		KI_UPPERCASE,	//��д��ĸ
		KI_LOWERCASE,	//Сд��ĸ
		KI_MARK,		//���÷���
		KI_PINYIN,		//ƴ������
		KI_CONTROL,		//ATMԭʼ���Ƽ�
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
