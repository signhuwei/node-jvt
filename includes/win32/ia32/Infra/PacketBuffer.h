//
//  "$Id: PacketBuffer.h 1639 2011-05-18 02:35:42Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_PACKETBUFFER_H__
#define __INFRA_PACKETBUFFER_H__

class CPacket;

/// Packet数据缓冲管理，通道数不限制，线程安全
/// 
class IPacketBuffer
{
public:
	/// 创建包缓冲管理对象
	static IPacketBuffer *create(int kiloBytes);

	/// 虚析构函数
	virtual ~IPacketBuffer();

	/// 存放数据
	/// \param [in] pPkt 要存入的缓冲数据
	/// \param [in] iChannel 数据所在通道号
	/// \param [in] autoDel 缓冲满时是否自动覆盖
	/// \return 存入数据是否成功
	///	\note 缓冲区满返回失败, 当压入成功时该接口会自动增加引用计数
	virtual bool pushBuffer(int iChannel, CPacket *pPkt, bool autoDel = false) = 0;
	
	/// 存放数据，和popBuffer正相反
	/// \param [in] pPkt 要存入的缓冲数据
	/// \param [in] iChannel 数据所在通道号
	/// \param [in] autoDel 缓冲满时是否自动覆盖
	/// \return 存入数据是否成功
	///	\note 缓冲区满返回失败, 当压入成功时该接口会自动增加引用计数
	virtual bool pushHeadBuffer(int iChannel, CPacket *pPkt) = 0;

	/// 获得数据
	/// \param [out] pPkt 存放获取的缓冲地址
	/// \param [in] iChannel 要取数据的通道
	/// \return 获取数据是否成功
	virtual bool popBuffer(int iChannel, CPacket **pPkt) = 0;	

	///得到队列中pkt的个数
	virtual int getBufferCount(int iChannel) = 0;
	
	/// 清除数据
	virtual void clear(int iChannel) = 0;
};

#endif
