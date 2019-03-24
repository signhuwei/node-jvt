//
//  "$Id: IPAddress.h 14 2009-08-22 07:39:05Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_IPADDRESS_H__
#define __INFRA_IPADDRESS_H__

#include "Types.h"
#include <string>

/// \brief IP地址操作封装
class CIPAddress 
{
public:

	/// 构造函数
	/// \param [in] addr 16进制IP地址
	CIPAddress(ulong addr = 0);


	/// 构造函数
	/// \param [in] addr 字符串IP地址,如"192.168.0.1"
	CIPAddress(const std::string &addr);


	/// 得到格式化后的字符串
	std::string Format() const;


	/// 设置IP地址
	/// \param [in] addr 要设置的IP地址,如"192.168.0.1"的形式
	void SetAddress(const std::string &addr);


	/// 设置IP地址
	void SetAddress(ulong addr);


	/// 得到16进制的IP地址
	uint GetAddress() const;

private:
	ulong m_addr;
};
#endif
