//
//  "$Id: MsgQue.h 776 2010-07-21 05:21:29Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_MSGQUE_H__
#define __INFRA_MSGQUE_H__

#include "Types.h"

// Windows内已定义SendMessage宏，从而导致链接程序实际编译的时候并不是
// SendMessage函数的问题
#ifdef SendMessage
	#undef SendMessage
#endif

/// 消息队列封装
///
class CMsgQue
{
public:

	/// 消息类型定义(包括消息类型、参数、时间戳)
	typedef struct tagMSG 
	{
		uint		msg;
		uint		wpa;
		uint		lpa;
		uint		time;
	}MSG;


	/// 构造函数、构造一个size长度的消息队列
	/// \param [in] size 消息队列长度，最多可接纳的消息数量
	CMsgQue(int size = 1024);


	/// 析构函数
	virtual ~CMsgQue();


	/// 往消息队列发送消息
	/// \param [in] 消息类型
	/// \param [in] wpa 消息参数
	/// \param [in] lpa 消息参数
	/// \param [in] priority 消息优先级(暂时不用)
	/// \return 发送消息是否成功(消息队列已满是发送消息将失败)
	bool SendMessage (uint msg, uint wpa = 0, uint lpa = 0, uint priority = 0);


	/// 从消息队列接收消息
	/// \param [out] pMsg存放接收到的消息
	/// \param [in] wait 是否等待接收消息完成
	/// \return 接受消息是否成功(当不等待，消息队列中又没有消息的时候接受消息将失败)
	bool RecvMessage (MSG *pMsg, bool wait = true);


	/// 退出消息队列，注: 对出消息队列以后将不能再发送或者接收消息
	void QuitMessage ();


	/// 清除消息队列
	void ClearMessage();

	
	/// 返回消息队列中消息的数目
	int GetMessageCount();

	
	/// 得到消息队列中消息队列的长度
	int GetMessageSize();


	/// 设置消息队列接收缓冲区的大小
	void SetMessageSize(int size);

private:
	
	void *m_MsgQueImp;
};
#endif
