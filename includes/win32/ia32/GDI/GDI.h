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

/// \brief GDI组件
///
class IGDI
{
public:

	typedef TSignal4<uint, uint, uint, int>::SigProc Proc;

	/// 单件实例
	static IGDI *instance(); 

	/// 虚析构函数
	virtual ~IGDI();

	/// 启动GDI组件
	virtual void start() = 0;

	/// 发送人机消息
	/// \param [in] message 消息类型
	/// \param [in] param1 消息参数1
	/// \param [in] param2 消息参数2
	/// \param [in] sync 消息是否同步传递
	virtual bool sendMessage(ulong message, ulong param1, ulong param2, bool sync = false) = 0;

	/// 接收人机消息
	/// \param message 消息类型
	/// \param param1 消息参数1
	/// \param param2 消息参数2
	/// \param wait 消息队列空时是否等待，true-等待，false-返回失败
	virtual bool recvMessage(ulong& message, ulong& param1, ulong& param2, bool wait) = 0;

	/// 注册消息观察者回调函数，用于接收同步消息
	/// \param [in] proc 消息观察者回调函数
	/// \return 注册是否成功
	virtual bool attach(Proc proc) = 0;

	/// 注销消息观察者回调函数
	/// \param [in] proc 消息观察者回调函数
	/// \return 注册是否成功
	virtual bool detach(Proc proc) = 0;
};
#endif
