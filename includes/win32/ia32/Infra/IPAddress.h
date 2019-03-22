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

/// \brief IP��ַ������װ
class CIPAddress 
{
public:

	/// ���캯��
	/// \param [in] addr 16����IP��ַ
	CIPAddress(ulong addr = 0);


	/// ���캯��
	/// \param [in] addr �ַ���IP��ַ,��"192.168.0.1"
	CIPAddress(const std::string &addr);


	/// �õ���ʽ������ַ���
	std::string Format() const;


	/// ����IP��ַ
	/// \param [in] addr Ҫ���õ�IP��ַ,��"192.168.0.1"����ʽ
	void SetAddress(const std::string &addr);


	/// ����IP��ַ
	void SetAddress(ulong addr);


	/// �õ�16���Ƶ�IP��ַ
	uint GetAddress() const;

private:
	ulong m_addr;
};
#endif
