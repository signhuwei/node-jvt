//
//  "$Id: Exchange.h 14561 2015-01-07 05:32:19Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:			
//  
//

#ifndef __EXCHANGE_AL_EXCHANGE_H__
#define __EXCHANGE_AL_EXCHANGE_H__

#include "Types/Defs.h"
#include "Infra/Time.h"
#include <Json/reader.h>
#include <Json/writer.h>
#include <stdio.h>

class CKeys
{
	friend class CKeyExchange;
public:
	CKeys(int index)
	{
		m_kind = kindIndex;
		m_value.index = index;
	};

	CKeys(const char* name)
	{
		m_kind = kindName;
		m_value.name = name;
	};

private:
	enum Kind
	{
		kindNone = 0,
		kindIndex,
		kindName
	}m_kind;

	union
	{
		int index;
		const char *name;
	}m_value;
};

struct ConfigPair
{
	const char* name;
	int value;
};

typedef Json::Value CConfigTable;
typedef Json::Reader CConfigReader;
#ifdef _DEBUG
	typedef Json::StyledWriter CConfigWriter;
#else
	typedef Json::FastWriter CConfigWriter;
#endif

/// \class CKeyExchange
/// \brief Json��ֵ����
class CKeyExchange
{
public:
	/// ���ý���״̬��������߻���
	enum EXCHANGE_STATE
	{
		ES_SAVING,
		ES_LOADING,
	};

	void setState(int state);

	int getState() const;

	void exchange(CConfigTable& table, CKeys key, int& value, ConfigPair* map);

	void exchange(CConfigTable& table, CKeys key, int& value);

	void exchange(CConfigTable& table, CKeys key, char& value);

	void exchange(CConfigTable& table, CKeys key, std::string& value);
	
	void exchange(CConfigTable& table, CKeys key, char* value);

	void exchange(CConfigTable& table, CKeys key, uchar* value, int size);

	void exchange(CConfigTable& table, CKeys key, bool& value);

	void exchange(CConfigTable& table, CKeys key, uint& value);

	void exchange(CConfigTable& table, CKeys key, double& value);

	const char* getString(CConfigTable& table, CKeys key);

	int getInt(CConfigTable& table, CKeys key);

	bool getBool(CConfigTable& table, CKeys key);

	bool getDouble(CConfigTable& table, CKeys key);  //2018.03.09 by ctf

	CConfigTable& getTable(CConfigTable& table, CKeys key);

	void exchange(CConfigTable& table, CKeys key,short& value);
private:
	int m_iState;
};

/// Ĭ���������ʽ
struct DefaultRequest
{
	uint uiSessionId;
	std::string sName;		///< ��������
};

/// Ĭ����Ӧ����ʽ
struct DefaultResponse
{
	uint uiSessionId;		///< �ỰID
	int iRet;				///< ����ֵ
	std::string sName;		///< ��������
};

template <class T> void exchangeTable(CConfigTable& table, T& config, int state);
template <class T> void exchangeTableV2(CConfigTable& table, T& config, int state, int nSize);


//////////////////////////////////////////////////////////////////////////
/// T ���ýṹ����
template <class T> class TExchangeAL
{
public:
	TExchangeAL()
	{
	}
	virtual ~TExchangeAL()
	{
	}

	/// �����ַ��������ַ���ת������Ӧ�Ľṹ�壬ͨ�������������ɽ���web����
	/// \param [in] stream Ҫ�������ַ���
	/// \param [in] key ���ö������ڼ�ֵ
	/// \param [out] uiSessionID �ỰID��
	/// \param [out] config ת���ú�Ľṹ
	/// \param [out] pOption ָ��洢������ĸ�����Ϣ
	static void parseConfig(const std::string &stream, const std::string &key, uint &uiSessionID, T &config, int* pOption = NULL)
	{
		CConfigTable table;
		CConfigReader reader;

		reader.parse(stream, table);
		sscanf(table["SessionID"].asCString(), "0x%x", &uiSessionID);
		if (pOption)
		{
			*pOption = table["opt"].asInt();
		}
		
		if (table[key].type() != Json::nullValue)
		{
			::exchangeTable(table[key], config, CKeyExchange::ES_LOADING);
		}
	}

	/// ���л��ַ��������ṹ��ת�����ַ���.ͨ��web�������ɱ�������
	/// \param [in] uiSessionID �ỰID��
	/// \param [in] config Ҫת���Ľṹ
	/// \param [in] key �������ڼ�ֵ
	/// \param [out] ת����������ַ���
	/// \param [in] option ������Ϣ�����Ը�����Ҫ�Լ���ֵ
	static void serizalConfig(uint uiSessionID, /*const*/T& config, const std::string &key, std::string &stream, int option = 0)
	{
		CConfigTable table;
		CConfigWriter writer(stream);
		char buf[32];

		sprintf(buf, "0x%x", uiSessionID);
		table["SessionID"] = buf;
		table["Name"] = key;
		if (option != 0)
		{
			table["opt"] = option;
		}
		::exchangeTable(table[key], config, CKeyExchange::ES_SAVING);
		writer.write(table);
	}

	/// �����ַ��������ַ���ת������Ӧ�Ľṹ�壬ͨ��web��������������Ӧ
	/// \param [in] stream Ҫ�������ַ���
	/// \param [in] key ���ö������ڵļ�ֵ
	/// \param [out] ������õ��ĻỰID��
	/// \param [out] ������õ����û�����ֵ
	/// \param [out] ������Ľṹ��
	/// \param [out] pOption ָ��洢������ĸ�����Ϣ
	static void parseConfig(const std::string &stream, const std::string &key, uint &uiSessionID, int &ret, T&config, int* pOption = NULL)
	{
		CConfigTable table;
		CConfigReader reader;

		reader.parse(stream, table);
		sscanf(table["SessionID"].asCString(), "0x%x", &uiSessionID);
		ret = table["Ret"].asInt();
		if (pOption)
		{
			*pOption = table["opt"].asInt();
		}
		if (table[key].type() != Json::nullValue)
		{
			::exchangeTable(table[key], config, CKeyExchange::ES_LOADING);
		}
	}

	/// ���л��ַ��������ṹ��ת�����ַ���.ͨ��������������web��Ӧ
	/// \param [in]
	/// \param [in] option ������Ϣ�����Ը�����Ҫ�Լ���ֵ
	static void serizalConfig(uint uiSessionID, int ret, /*const*/T& config, const std::string &key, std::string &stream, int option = 0)
	{
		CConfigTable table;
		CConfigWriter writer(stream);
		char buf[32];

		sprintf(buf, "0x%x", uiSessionID);
		table["SessionID"] = buf;
		table["Ret"] = ret;
		table["Name"] = key;
		if (option != 0)
		{
			table["opt"] = option;
		}
		::exchangeTable(table[key], config, CKeyExchange::ES_SAVING);
		writer.write(table);
	}

	/// ���л��ַ��������ṹ��ת�����ַ���.ͨ��������������web��Ӧ
	/// \param [in]
	/// \param [in] option ������Ϣ�����Ը�����Ҫ�Լ���ֵ
	static void serizalConfigV2(uint uiSessionID, int ret, /*const*/T& config, const std::string &key, std::string &stream,int nSize, int option = 0)
	{
		CConfigTable table;
		CConfigWriter writer(stream);
		char buf[32];

		sprintf(buf, "0x%x", uiSessionID);
		table["SessionID"] = buf;
		table["Ret"] = ret;
		table["Name"] = key;
		if (option != 0)
		{
			table["opt"] = option;
		}
		::exchangeTableV2(table[key], config, CKeyExchange::ES_SAVING,nSize);
		writer.write(table);
	}

	/// ��Json���ת���ɽṹ��
	/// \param [in] table Ҫת����Json���
	/// \param [out] ת����Ľṹ��
	static void getConfig(const CConfigTable &table, T &config)
	{
		union Panic_cast
		{
			const CConfigTable *in;
			CConfigTable *out;
		} cast;

		cast.in = &table;

		::exchangeTable(*cast.out, config, CKeyExchange::ES_LOADING);
	}

	/// ���ṹ��ת����Json���
	/// \param [in] config Ҫת���Ľṹ��
	/// \param [out] table ת�������ñ��
	static void setConfig(const T &config, CConfigTable &table)
	{
		union Panic_cast
		{
			const T *in;
			T *out;
		} cast;
		cast.in = &config;
		::exchangeTable(table, *cast.out, CKeyExchange::ES_SAVING);
	}

	/// ����Ľṹ��ת�����ַ���
	static void serizalConfig(const T &config, std::string &stream)
	{
		CConfigTable table;
		CConfigWriter writer(stream);

		union Panic_cast
		{
			const T *in;
			T *out;
		} cast;

		cast.in = &config;
		::exchangeTable(table, *cast.out, CKeyExchange::ES_SAVING);
		writer.write(table);
	}

	/// ���ṹ��ת����Json���
	/// \param [in] config Ҫת���Ľṹ��
	/// \param [out] table ת�������ñ��
	static void setConfigV2(const T &config, CConfigTable &table, int nSize)
	{
		union Panic_cast
		{
			const T *in;
			T *out;
		} cast;
		cast.in = &config;
		::exchangeTableV2(table, *cast.out, CKeyExchange::ES_SAVING, nSize);
	}

	/// ����Ľṹ��ת�����ַ���
	static void serizalConfigV2(const T &config, std::string &stream, int nSize)
	{
		CConfigTable table;
		CConfigWriter writer(stream);

		union Panic_cast
		{
			const T *in;
			T *out;
		} cast;

		cast.in = &config;
		::exchangeTableV2(table, *cast.out, CKeyExchange::ES_SAVING, nSize);
		writer.write(table);
	}
	/// �ַ���ת�������ýṹ
	static void parseConfig(const std::string &stream, T &config)
	{
		CConfigTable table;
		CConfigReader reader;

		reader.parse(stream, table);
		::exchangeTable(table, config, CKeyExchange::ES_LOADING);
	}

	/// ��Json���ת���ɽṹ��
	/// \param [in] table Ҫת����Json���
	/// \param [out] ת����Ľṹ��
	static void getConfigV2(const CConfigTable &table, T &config, int nSize)
	{
		union Panic_cast
		{
			const CConfigTable *in;
			CConfigTable *out;
		} cast;

		cast.in = &table;

		::exchangeTableV2(*cast.out, config, CKeyExchange::ES_LOADING, nSize);
	}
	/// �ַ���ת�������ýṹ
	static void parseConfigV2(const std::string &stream, T &config, int nSize)
	{
		CConfigTable table;
		CConfigReader reader;

		reader.parse(stream, table);
		::exchangeTableV2(table, config, CKeyExchange::ES_LOADING, nSize);
	}
};

void exchangeSysTime(CKeyExchange& configExchange, CConfigTable& table, SystemTime& systime);
int getIndex(ConfigPair *pairs, const char * name);
int getIndex(ConfigPair *pairs, int value);
void getString(const CConfigTable &table, std::string &stream);
#endif

