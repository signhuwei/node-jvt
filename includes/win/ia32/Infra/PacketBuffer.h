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

/// Packet���ݻ������ͨ���������ƣ��̰߳�ȫ
/// 
class IPacketBuffer
{
public:
	/// ����������������
	static IPacketBuffer *create(int kiloBytes);

	/// ����������
	virtual ~IPacketBuffer();

	/// �������
	/// \param [in] pPkt Ҫ����Ļ�������
	/// \param [in] iChannel ��������ͨ����
	/// \param [in] autoDel ������ʱ�Ƿ��Զ�����
	/// \return ���������Ƿ�ɹ�
	///	\note ������������ʧ��, ��ѹ��ɹ�ʱ�ýӿڻ��Զ��������ü���
	virtual bool pushBuffer(int iChannel, CPacket *pPkt, bool autoDel = false) = 0;
	
	/// ������ݣ���popBuffer���෴
	/// \param [in] pPkt Ҫ����Ļ�������
	/// \param [in] iChannel ��������ͨ����
	/// \param [in] autoDel ������ʱ�Ƿ��Զ�����
	/// \return ���������Ƿ�ɹ�
	///	\note ������������ʧ��, ��ѹ��ɹ�ʱ�ýӿڻ��Զ��������ü���
	virtual bool pushHeadBuffer(int iChannel, CPacket *pPkt) = 0;

	/// �������
	/// \param [out] pPkt ��Ż�ȡ�Ļ����ַ
	/// \param [in] iChannel Ҫȡ���ݵ�ͨ��
	/// \return ��ȡ�����Ƿ�ɹ�
	virtual bool popBuffer(int iChannel, CPacket **pPkt) = 0;	

	///�õ�������pkt�ĸ���
	virtual int getBufferCount(int iChannel) = 0;
	
	/// �������
	virtual void clear(int iChannel) = 0;
};

#endif
