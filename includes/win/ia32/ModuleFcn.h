#ifndef _ModuleFcn_h
#define _ModuleFcn_h

#include <assert.h>

#ifndef WIN32
#include <sys/time.h>
#include <string.h>
#endif

#ifdef WIN32
#ifndef ASSERT
#define ASSERT assert
#endif
#else
#define ASSERT assert
#endif

//unix导出函数
#ifdef WIN32
#define EXPORT_FCN 
#else
#define EXPORT_FCN	__attribute__((visibility("default")))
#endif


//目录分隔符
#define UNIX_PATH_SEP	"/"
#define WIN_PATH_SEP	"\\"

#ifdef WIN32
#define PATH_SEP		"\\"
#else
#define PATH_SEP		"/"
#endif

//获取模块文件路径
inline string GetModuleFileNameFromAddr(LPVOID p);

//获取模块文件所在目录
inline string GetModuleFilePathFromAddr(LPVOID p);

//获取执行文件路径
inline string GetExecuteFilePath();

#ifndef WIN32
inline DWORD GetTickCount();
inline VOID Sleep(DWORD dwMilliseconds);

inline DWORD GetCurrentThreadId();

#endif


//线程函数
typedef void* (WINAPI *FCN_THREAD_PROC)(void*);

inline HANDLE CreateThread(FCN_THREAD_PROC proc, void* param);
inline void JoinThread(HANDLE hThread);
inline void DetachThread(HANDLE hThread);

//调试输出
inline void OutputDebug(const char* szOut, ...);

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

inline string GetModuleFileNameFromAddr(LPVOID p)
{
#ifdef WIN32
	MEMORY_BASIC_INFORMATION m = {0};
    VirtualQuery(p, &m, sizeof(MEMORY_BASIC_INFORMATION));
	HMODULE hMod = (HMODULE)m.AllocationBase;

	char szModule[MAX_PATH] = {0};
	::GetModuleFileNameA(hMod,szModule,MAX_PATH - 1);
	return szModule;
#else
	FILE* fp = fopen("/proc/self/maps","r");
	if(fp == NULL)
	{
		return string();
	}
	
	char szLine[1024];
	while(!feof(fp))
	{
		fgets(szLine,sizeof(szLine),fp);
		char* pLibName = NULL;
		if(strstr(szLine,"r-xp") && (pLibName = strstr(szLine,"/")))
		{
			unsigned int /*DWORD_PTR*/ dwBegin,dwEnd;
			sscanf(szLine,"%08x-%08x",&dwBegin,&dwEnd);
			if((unsigned int)p >= dwBegin && (unsigned int)p < dwEnd)
			{
				fclose(fp);
				return pLibName;
			}
		}
	}
	fclose(fp);
	return string();
#endif
}

inline string GetModuleFilePathFromAddr(LPVOID p)
{
	string strFile = GetModuleFileNameFromAddr(p);

	return strFile.substr(0,strFile.rfind(PATH_SEP) + 1);
}

inline string GetExecuteFilePath()
{
	char szModule[MAX_PATH] = {0};

#ifdef WIN32
	::GetModuleFileNameA(NULL,szModule,MAX_PATH - 1);
	
#else
	readlink("/proc/self/exe",szModule,MAX_PATH - 1);
#endif

	string str(szModule);		
	return str.substr(0,str.rfind(PATH_SEP) + 1);
}


#ifndef WIN32
inline DWORD GetTickCount()
{
	/*
	tms tm;
	return times(&tm)/(CLOCKS_PER_SEC*1000);
	*/
	timeval current;
	gettimeofday(&current, NULL);
	return current.tv_sec * 1000 + current.tv_usec/1000;
}

inline VOID Sleep(DWORD dwMilliseconds)
{
	timeval tv;
	tv.tv_sec = dwMilliseconds/1000;
	tv.tv_usec = (dwMilliseconds%1000)*1000;
	select(1,NULL,NULL,NULL,&tv);
}

inline DWORD GetCurrentThreadId()
{
	return pthread_self();
}

#endif


inline HANDLE CreateThread(FCN_THREAD_PROC proc, void* param)
{
#ifdef WIN32
    return ::CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)proc,param,0,NULL);
#else
	pthread_t id = NULL;
    pthread_create(&id,NULL,proc,param);
	return (HANDLE)id;
#endif
}

inline void JoinThread(HANDLE hThread)
{
#ifdef WIN32
    ::WaitForSingleObject(hThread,INFINITE);
    CloseHandle(hThread);
#else
    pthread_join((pthread_t)hThread,NULL);
#endif
}

inline void DetachThread(HANDLE hThread)
{
#ifdef WIN32
    CloseHandle(hThread);
#else
    pthread_detach((pthread_t)hThread);
#endif
}

inline void OutputDebug(const char* szOut, ...)
{
	char buf[4096];
	va_list ap;
	va_start(ap , szOut);
	int len = vsnprintf(buf,sizeof(buf) - 1 ,szOut,ap);
	va_end(ap);
	if(len < 0)
	{
		len = 0;
	}
	if(len > sizeof(buf) - 1)
	{
		len = sizeof(buf) - 1;
	}
	buf[len] = 0;

#ifdef WIN32
	OutputDebugStringA(buf);
#else
	printf("%s\r\n",buf);
#endif

}

#endif//_ModuleFcn_h
