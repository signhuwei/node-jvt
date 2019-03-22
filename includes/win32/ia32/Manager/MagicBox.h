//
//  "$Id: MagicBox.h 1858 2011-08-08 05:59:22Z chenchangbao $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  
//

#ifndef __MANAGER_MAGICBOX_H__
#define __MANAGER_MAGICBOX_H__

#include "Infra/Time.h"
#include <Json/value.h>
#include <string>

class IMagicBox
{
public:
	
	/// ����ʵ��
	static IMagicBox *instance();

	/// ����������
	virtual ~IMagicBox();

	/// ����ħ��
	virtual void start() = 0;

	/// �õ���Ʒ������
	virtual const Json::Value &getProductDefinition() = 0;

	/// �ر�ϵͳ
	virtual void shutdown() = 0;

	/// ����ϵͳ
	virtual void reboot() = 0;

	/// �õ�ϵͳ���е�ʱ��
	/// \return ����ϵͳ�ӳ������Ե������ܹ����еķ�����
	virtual uint getRunningTime() = 0;

	/// �õ�ϵͳ����ʱ��
	/// \param [in\out] days ϵͳʹ������
	/// \return ֻ�����ð汾�ýӿڲŷ��سɹ�����ʽ�汾�ýӿڽ�����ʧ��
	virtual bool getTrailDays(int &days) = 0;

	/// ����������
	virtual void beep(uint dwFrequence, uint dwDuration) = 0;

	/// �õ�ϵͳ�ػ�ʱ��
	virtual void getExitTime(DateTime *time) = 0;

	/// �Ƿ���ʾXM����Ϣ
	virtual bool IsShowXMInfo() = 0;

	/// ����CPU���Ź�
	virtual bool WatchDogStart() = 0;
};

#define g_magicBox (*IMagicBox::instance())
#endif 
