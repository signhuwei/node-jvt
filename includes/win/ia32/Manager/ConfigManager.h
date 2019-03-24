//
//  "$Id: ConfigManager.h 4221 2012-08-21 02:05:51Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __MANAGER_CONFIGMANAGER_H__
#define __MANAGER_CONFIGMANAGER_H__

#include "Infra/Types.h"
#include "Infra/Signals.h"
#include <Json/value.h>
#include "ExchangeAL/Exchange.h"

/// ���ù���ʵ����
/// 
class IConfigManager
{
public:
	/// ����Ӧ�ý������λ��ʾ�������õĹ۲������ã����õ��ύ�߼��
	enum ConfigApply
	{
		applyOK				= 0,			/// �ɹ�
		applyNeedReboot		= 0x00000002,	/// ��Ҫ����ϵͳ
		applyFileError		= 0x00000004,	/// д�ļ�����
		applyValiateFailed	= 0x00000020,	/// ��֤ʧ�� 
		applyNotExist		= 0x00000040,	/// ���ò����� 
		applyNotSave		= 0x00000080,	/// ��Ҫ���浽�ļ�
		applyDelaySave		= 0x00000100,	/// ��ʱ����..
		applyNotWriteLog	= 0x00000200,	/// ��������־
	};

	/// ���ø����źŶ��壬�źŵĲ����ֱ�Ϊ���û�������ú�����Ӧ�õĽ����
	/// �۲��ߺ����п��Զ�����Ӧ�ýṹ�����޸ģ�ȡApplyOptions���͵�λ��ֵ��
	/// �����еĻص����������ú󣬾Ϳ���ͨ�����ֵ�õ�������Ӧ�ý����
	typedef TSignal2<const Json::Value &, int &> Signal;

	/// ���ù۲��߻ص���������
	typedef Signal::SigProc Proc;

	/// ���ñ�����Ӻ����������û����޸����û�������������;�������
	/// Ŀǰ�ò��������ù���͸�����޸ĺ�����ý������ٽ���У����ز���
	/// ���õĺϷ�����Ҫʹ�����Լ���֤
	typedef TSignal2<Json::Value &, int &> HookSignal;

	/// ���ӻص�����
	typedef HookSignal::SigProc HookProc;

public:
	
	/// ��ȡʵ�����
	static IConfigManager *instance();

	/// ����������
	virtual ~IConfigManager();

	///< ��ʼ�����������ù���
	virtual void start() = 0;

	/// ���ýӿ�
	/// \param [in] firstDir �������ļ��Ĵ��Ŀ¼
	/// \param [in] secondDir ���������ļ��Ĵ��Ŀ¼
	/// \param [in] customDir �û��Զ��������ļ��Ĵ��Ŀ¼
	static void config(const char *firstDir, const char *secondDir, const char *customDir);

	/// ɾ�������ļ�����Ҫ����������������Ĭ�ϱ��ָ���Ĭ������
	/// \param user �û���
	virtual void deleteFile(const char* user = NULL) = 0;

	// �õ����µ����ýṹ
	/// \param [in] name ��������
	/// \param [out] table ���ñ�
	/// \note name��ѭ�����﷨����
	/// ��һ���ַ�����ȡ��������
	/// �ַ������[%d], .key����Ҫ������Ӧ��������
	/// - "." => ���ڵ㣬��name��name.����һ��
	/// - ".key" => ������������Ϊkey��������
	/// - ".[n]" => ����Ʋ֮�ڵ�n+1��������
	/// ���Ϲ��̿��Եݹ�
	/// �������¼������nameΪgetConfigName(CFG_RECORD)
	/// ���ʵ�һͨ����¼������nameΪ"Record.[0]"
	/// ���ʵ�һͨ��¼�����õ�ʱ��ε�����Ϊ"Record.[0].TimeSection"
	virtual bool getConfig(const char* name, Json::Value& table) = 0;

	/// �ύ���ã����Ϸ��Լ�飬����saveFile���������ļ���
	/// \param name ��������
	/// \param table �µ�����
	/// \param index �������
	/// \param user �û���
	/// \param applyOptions ����ֵ��ʼֵ��ȡApplyOptionsλ��ֵ��
	/// \param notifyParent �ص�ʱ֪ͨ�ϲ�ڵ�Ļص�����
	/// \return ����Ӧ�õĽ����ȡApplyOptionsλ��ֵ��applyOptions��Ϊ����ֵ�ĳ�ʼֵ��
	/// \note name���﷨�μ�getConfig()
	virtual int setConfig(const char* name, const Json::Value& table, const char* user = 0, int applyOptions = applyDelaySave) = 0;

	/// ����������õ�����, �ú���ֻ��������У��Ļص�������ʹ��
	/// \param [in] name Ҫȡ�����õ�·��
	virtual const Json::Value& resolveConfig(const char *name) = 0;

	// �õ�Ĭ�ϵ����ñ�
	/// \param [in] name ��������
	/// \param [out] ���ñ�
	virtual bool getDefault(const char* name, Json::Value& table) = 0;

	/// ����Ĭ�����ñ�һ���ÿ�������ڳ�ʼ��ʱ����һ�μ��ɣ�����������ʹ��֮ǰ����
	/// �˺�������CConfigManager���á�
	/// \param [in] name ��������
	/// \param table Ĭ�����ñ�
	virtual void setDefault(const char* name, const Json::Value& table, bool bProduceConfig = false) = 0;

	/// ע�����ñ仯�۲��ߺ�����
	/// \param name ��������
	/// \param proc �۲��ߺ���
	/// \retval >0 ��ǰ�Ѿ�ע��Ĺ۲�����Ŀ��
	/// \return <0 TSignalN::ErrorCode���͵�ֵ��
	virtual int attach(const char* name, Proc proc) = 0;

	/// ע�����ñ仯�۲��ߺ�����
	/// \param name ��������
	/// \param proc �۲��ߺ���
	/// \retval >=0 ��ǰ�Ѿ�ע��Ĺ۲�����Ŀ��
	/// \return <0 TSignalN::ErrorCode���͵�ֵ��
	virtual int detach(const char* name, Proc proc) = 0;

	/// ע������У��۲��ߺ���, ��������ʹ��ǰ���á�
	/// \param name ��������
	/// \param proc �۲��ߺ���
	/// \retval >0 ��ǰ�Ѿ�ע��Ĺ۲�����Ŀ��
	/// \return <0 TSignalN::ErrorCode���͵�ֵ��
	virtual int attachVerify(const char* name, Proc proc) = 0;

	/// ע������У��۲��ߺ�����
	/// \param name ��������
	/// \param proc �۲��ߺ���
	/// \retval >=0 ��ǰ�Ѿ�ע��Ĺ۲�����Ŀ��
	/// \return  <0 TSignalN::ErrorCode���͵�ֵ��
	virtual int detachVerify(const char* name, Proc proc) = 0;

	/// ע�ṳ�Ӻ���
	/// \param [in] name Ҫ�۲����������
	/// \param [in] pObj ���Ӷ���ָ��
	/// \param [in] proc ���Ӻ���ָ��
	/// \retval >= 0 ��ǰ�Ѿ�ע��Ĺ۲��ߺ���
	/// \retval < 0 TSignalN::ErrorCode���͵�ֵ
	virtual int hooks(const char *name, HookProc proc) = 0;

	/// �ָ�����һ����ȷ������
	virtual void restore() = 0;

	/// ���������ļ�
	virtual void saveFile() = 0;
};

#define g_configManager (*IConfigManager::instance())
#endif 
