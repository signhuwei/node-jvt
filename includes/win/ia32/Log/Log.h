//
//  "$Id: Log.h 874 2010-08-07 08:00:20Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:	
//  
//

#ifndef __MANAGER_LOG_H__
#define __MANAGER_LOG_H__

#include "Infra/Time.h"
#include "Infra/Signals.h"

///
/// ��־�����֣����ڼ�¼ϵͳ���й����е�һЩ�ؼ��¼�����ϵͳ��ά���͵��ԣ�
/// Ŀǰ��־ȫ�������ַ�������ʽ�洢����Ȼ�պ���չ��
/// ��־���ݲ��ֺ���־�ļ�ͷ���ַֿ���ţ�������չ
/// 
class ILog 
{
public:
	/// ��־�����źŶ��壬�źŵĲ����ֱ�Ϊ��־���ͣ���־���ݣ���־����ʱ��
	typedef TSignal3<std::string, std::string, DateTime> SIG_LOG;

	/// ���ù۲��߻ص���������
	typedef SIG_LOG::SigProc Proc;

	enum 
	{
		defaultMaxItems		= 2048,		///< Ĭ�ϵ������־����
		itemTypeLength		= 24,		///< ��־�����������ݳ���
		itemDataLength		= 68,		///< ��־�����������ݳ���
		itemUserNameLength	= 32,		///< ��־��������û�������
		itemLength			= 128,		///< ��־���
	};

	/// ������־���128�ֽ�
	/// ��־��¼��ʽYear-Month-Day Hour:Minute:Second[User],[Type],[Data]
	struct Item
	{
		char	type[itemTypeLength];		///< ��־����
		char	data[itemDataLength];		///< ��־����
		char	user[itemUserNameLength];	///< ��־�û���
		DateTime	time;						///< �¼�����ʱ��
	};

	/// ���캯��
	static ILog* instance();

	/// ����������
	virtual ~ILog();

	/// \param [in] maxLogItem �����־����
	/// \param [in] logFilePath ��־�ļ�·��
	static void config(int maxLogItem, const char *logFilePath);
	
	/// ��¼��־��ͬʱ������־��¼��ʱ�䡣
	/// \param  type ��־���ͣ���"SaveConfig"
	/// \param  data ��־���ݾ����ʽ��datafmt���룬��ϸ�������ý�����ʽ.doc��
	virtual void append(const char* type, const char* datafmt = NULL, ...) = 0;

	/// �����־��ͬʱ�Զ�����һ�������־����־��¼��
	/// \param  user ��־����ʱ���õ��û�����
	virtual void clear(const char *user) = 0;

	/// �õ���־��������
	virtual uint size() = 0;

	/// ��ȡ��־��ṹ
	/// \param pos ��־������[0, size()-1]
	/// \param item ��־�
	/// \return ��ȡ��־�Ƿ�ɹ�
	virtual bool get(uint pos, Item& item) = 0;

	/// ע��ص�, ������־ʱ������øûص�
	virtual bool attach(Proc proc) = 0;

	/// ע���ص�
	virtual bool detach(Proc proc) = 0;

	/// �����ļ�
	virtual bool saveFile() = 0;
};

#define g_logManager (*ILog::instance())
#endif
