#ifndef __IDEBUG_H__
#define __IDEBUG_H__
#include <string>
class IDebug
{
public:
	enum DEBUG_LEVEL
	{
		DL_OFF		= 0x00, 	//�رյ���
		DL_INFO		= 0x01,		//������Ϣ
		DL_ERROR 	= 0x02,		//������Ϣ
		DL_WARNING  = 0x03,		//������Ϣ
		DL_DEBUG	= 0x04,		//������Ϣ
		DL_ALL		= 0x0F,		//���е�����Ϣ
	};

	static IDebug *instance();
	
	virtual ~IDebug(){};
	virtual bool RegisterDebug(std::string modeName, int defLevel = DL_ERROR) = 0;
	virtual void UnRegisterDebug(std::string modeName) = 0;
	virtual void Print(std::string modeName, int level, const char *format, ...) = 0;
};
#define g_XMdebug (*IDebug::instance())

#endif

