//
//  "$Id: Singleton.h 320 2010-02-05 09:05:42Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//  Description:	  
//  Revisions:	  Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_SINGLETON_H__
#define __INFRA_SINGLETON_H__

#include <map>

/////////////////////////////////////////////////
///////////////// 单件模式
#define PATTERN_SINGLETON_DECLARE(classname)	\
private:										\
	classname();								\
public:											\
	static classname * instance();				\
	virtual ~classname();	

#define PATTERN_SINGLETON_IMPLEMENT(classname)	\
classname * classname::instance()		\
{												\
	static classname * _instance = NULL;		\
	if( NULL == _instance)						\
	{											\
		_instance = new classname;				\
	}											\
	return _instance;							\
}												
/////////////////////////////////////////////////

/////////////////////////////////////////////////
/// 扩展单件模式
#define PATTERN_SINGLETON_EX_DECLARE(classname)		\
private:											\
	classname();									\
public:												\
	static classname *instance(int channel);		\
	virtual ~classname();								

#define PATTERN_SINGLETON_EX_IMPLEMENT(classname)	\
classname *classname::instance(int channel)			\
{													\
	static std::map<int, classname*> _instance;	\
	if (_instance.find(channel) == _instance.end()) \
	{												\
		_instance[channel] = new classname(channel);\
	}												\
	return _instance[channel];						\
}

#endif
