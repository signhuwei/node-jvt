//
//  "$Id: Upgrader.h 3016 2012-04-13 09:35:20Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __MANAGER_UPGRADER_H__
#define __MANAGER_UPGRADER_H__

#include "Infra/Types.h"

/// \brief ����������
/// 
class IUpgrader
{
public:

	enum UpgradeState
	{
		stateOK,
		stateNoEnoughMemory,
		stateInvalidFomat,
		stateUpdatePartFail,
	};

	/// ���캯�������������Թ������
	static IUpgrader *instance();

	/// ����������
	virtual ~IUpgrader();
	
	/// ������ʼ��
	virtual bool init() = 0;

	/// ׷���������ݺ�setFilePathֻ��ʹ������һ��
	virtual bool putBuffer(uchar *buf, int len) = 0;

	/// ��ʼӦ����������
	virtual bool start(bool sync = false) = 0;

	/// ��ֹ����
	virtual bool abort() = 0;

	/// ��ǰ�Ƿ��Ѿ���ʼ����
	virtual bool started() const = 0;

	virtual bool setFilePath(const char* path) = 0;
};

#endif
