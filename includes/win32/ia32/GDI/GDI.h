//
//  "$Id: GDI.h 447 2010-04-14 12:21:08Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_STARTUP_H__
#define __GDI_STARTUP_H__

#include "Infra/Types.h"
#include "Infra/Singleton.h"
#include "Infra/Signals.h"

enum xm_msg_t 
{
	XM_FILE_WAKEUP = 0x010000,
	XM_MSG_GUI = 0x020000,
	XM_KEEPALIVE,
	XM_KEYDOWN,		XM_KEYUP,
	XM_MOUSEFOUND,  XM_MOUSELOST,
	XM_MOUSEMOVE,	XM_MOUSEWHEEL,
	XM_LBUTTONDOWN,	XM_LBUTTONUP,	XM_LBUTTONDBLCLK,
	XM_RBUTTONDOWN,	XM_RBUTTONUP,	XM_RBUTTONDBLCLK,
	XM_MBUTTONDOWN,	XM_MBUTTONUP,	XM_MBUTTONDBLCLK,
	XM_DRAW,		XM_SCROLL,		XM_LIST,
	XM_NUMPAD,		XM_CARET,		XM_CHAR,
	XM_TIMER,		XM_INPUTTYPE,	XM_ACTIVATE,
	XM_DEACTIVATE,	XM_COUNTDOWN,
	XM_SYSTEM_END
};

/// \brief GDI���
///
class IGDI
{
public:

	typedef TSignal4<uint, uint, uint, int>::SigProc Proc;

	/// ����ʵ��
	static IGDI *instance(); 

	/// ����������
	virtual ~IGDI();

	/// ����GDI���
	virtual void start() = 0;

	/// �����˻���Ϣ
	/// \param [in] message ��Ϣ����
	/// \param [in] param1 ��Ϣ����1
	/// \param [in] param2 ��Ϣ����2
	/// \param [in] sync ��Ϣ�Ƿ�ͬ������
	virtual bool sendMessage(ulong message, ulong param1, ulong param2, bool sync = false) = 0;

	/// �����˻���Ϣ
	/// \param message ��Ϣ����
	/// \param param1 ��Ϣ����1
	/// \param param2 ��Ϣ����2
	/// \param wait ��Ϣ���п�ʱ�Ƿ�ȴ���true-�ȴ���false-����ʧ��
	virtual bool recvMessage(ulong& message, ulong& param1, ulong& param2, bool wait) = 0;

	/// ע����Ϣ�۲��߻ص����������ڽ���ͬ����Ϣ
	/// \param [in] proc ��Ϣ�۲��߻ص�����
	/// \return ע���Ƿ�ɹ�
	virtual bool attach(Proc proc) = 0;

	/// ע����Ϣ�۲��߻ص�����
	/// \param [in] proc ��Ϣ�۲��߻ص�����
	/// \return ע���Ƿ�ɹ�
	virtual bool detach(Proc proc) = 0;
};
#endif
