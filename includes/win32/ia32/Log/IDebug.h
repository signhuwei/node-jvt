#ifndef __IDEBUG_H__
#define __IDEBUG_H__
#include <string>
class IDebug
{
public:
	enum DEBUG_LEVEL
	{
		DL_OFF		= 0x00, 	//关闭调试
		DL_INFO		= 0x01,		//启动信息
		DL_ERROR 	= 0x02,		//错误信息
		DL_WARNING  = 0x03,		//警告信息
		DL_DEBUG	= 0x04,		//调试信息
		DL_ALL		= 0x0F,		//所有调试信息
	};

	static IDebug *instance();
	
	virtual ~IDebug(){};
	virtual bool RegisterDebug(std::string modeName, int defLevel = DL_ERROR) = 0;
	virtual void UnRegisterDebug(std::string modeName) = 0;
	virtual void Print(std::string modeName, int level, const char *format, ...) = 0;
};
#define g_XMdebug (*IDebug::instance())

#endif

