//
//  "$Id: Packet.h 637 2010-06-10 09:52:10Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_PACKET_H__
#define __INFRA_PACKET_H__

#include "Types.h"
#include "Singleton.h"

#define PKT_HDR_SIZE 104

class CPacket
{

public:

	CPacket();


	virtual ~CPacket();
	virtual uint PutBuffer(const void * pdat, uint dwLength) = 0;
	virtual uchar *GetBuffer() = 0;

	/// 设置包长度
	virtual uint SetLength(uint dwLength) = 0;

	/// 取数据长度
	virtual uint GetLength() = 0;
	
	/// 获取容量
	virtual uint GetSize() = 0;
	
	/// 取剩余容量
	virtual uint GetLeft() = 0;

	/// 清空包头数据
	virtual uchar *GetHeader() = 0;

	/// 清空包头数据
	virtual void ClearHeader() = 0;

	virtual uint Release() = 0;
	virtual uint AddRef() = 0;
	virtual uint GetRef() = 0;
};

class CPacketManager
{
	PATTERN_SINGLETON_DECLARE(CPacketManager);

public:
	static void config(uchar *pbuf, int packetBufKilo);
	CPacket*	GetPacket(uint dwBytes = 0);
	void		Dump();
	void		DumpNodes();
};

#define g_PacketManager (*CPacketManager::instance())

#endif
