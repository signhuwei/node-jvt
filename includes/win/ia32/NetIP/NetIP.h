//
//  "$Id: NetIP.h 892 2009-04-16 06:24:53Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __NETIP_STARTUP_H__
#define __NETIP_STARTUP_H__

#include "Infra/Singleton.h"

/// \brief NetIP组件启动封装
///
class CNetIP
{
	PATTERN_SINGLETON_DECLARE(CNetIP);
	
public:

	bool start();
};
#endif
