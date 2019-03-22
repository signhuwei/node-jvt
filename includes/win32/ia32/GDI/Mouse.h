//
//  "$Id: Mouse.h 447 2010-04-14 12:21:08Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_MOUSE_H__
#define __GDI_MOUSE_H__

#include "Types/Defs.h"

class IMouse
{
public:
	/// ������굥��ʵ��
	static IMouse* instance();

	/// ����������
	virtual ~IMouse();

	/// ���������Ч��������
	virtual void setRect(PCRECT pRect) = 0;

	/// ����Ƿ��ҵ�
	virtual bool hasFound() = 0;
};

#endif
