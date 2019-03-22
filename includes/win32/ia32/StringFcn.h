#ifndef _string_fcn_h
#define _string_fcn_h

#ifndef WIN32
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdarg.h>
#include <iconv.h>
#else
#include <time.h>
#pragma warning (disable: 4996)
#endif

#ifndef _STRING_
#include <string>
using namespace std;
#endif

#ifndef _VECTOR_
#include <vector>
using namespace std;
#endif

//重载string构造函数
namespace std{

class StringEx : public string
{
public:
	StringEx(const char* sz = NULL):string(sz?sz:""){};
	StringEx(const StringEx& str):string(str){};
	StringEx(const string& str):string(str){};
	const StringEx& operator = (const char* sz){assign(sz?sz:"");return *this;};
	const StringEx& operator = (const StringEx& str){if(this != &str)assign(str);return *this;};
	const StringEx& operator = (const string& str){if(this != &str)assign(str);return *this;};
	operator const char* () const {return c_str();};
	//	
	void MakeLower();
	void MakeUpper();
	void TrimLeft(char trim=' ');
	int Compare(const StringEx& str) const;
	int CompareNoCase(const StringEx& str) const;
	void Replace(const StringEx& strOld , const StringEx& strNew);
	int Find(const StringEx& str,int iStart = 0) const;
	StringEx Left(int nCount) const;
	StringEx Right(int nCount) const;
	StringEx Mid(int nPlace, int nCount = -1) const;
	void Format(const char* szFormat, ...);
	void Decompose(const StringEx& split, vector<StringEx>& arStr) const;

	LONG ToLong() const;
	LONGLONG ToLongLong() const;
};

inline void StringEx::MakeLower()
{
	for(size_t i = 0;i < length();i++)
	{
		if(at(i) > 0)
		{
			if(!islower(at(i)))
			{
				at(i) = (char)tolower(at(i));
			}
		}
	}
}
inline void StringEx::MakeUpper()
{
	for(size_t i = 0;i < length();i++)
	{
		if(at(i) > 0)
		{
			if(!isupper(at(i)))
			{
				at(i) = (char)toupper(at(i));
			}
		}
	}
}
inline void StringEx::TrimLeft(char trim)
{
	for(size_t i = 0;i < length();i++)
	{
		if(at(i) != trim)
		{
			*this = substr(i);
			return;
		}
	}

	*this = "";
}

inline int StringEx::Compare(const StringEx& str) const
{
	return compare(str);
}

inline int StringEx::CompareNoCase(const StringEx& str) const
{
#ifdef WIN32	
	return _stricmp(c_str(),str.c_str());
#else
	return strcasecmp(c_str(),str.c_str());
#endif
}

inline void StringEx::Replace(const StringEx& strOld , const StringEx& strNew)
{
	for(;;)
	{
		string::size_type pos(0);
		if((pos = find(strOld)) != string::npos)
		{
			replace(pos,strOld.length(),strNew);
		}
		else
		{
			break;
		}
	}
}

inline int StringEx::Find(const StringEx& str,int iStart) const
{
	return find(str,iStart);
}

inline StringEx StringEx::Left(int nCount) const
{
	return substr(0,nCount);
}

inline StringEx StringEx::Right(int nCount) const
{
	int nLen = length();
	if(nCount >= nLen)
	{
		return *this;
	}
	else
	{
		return substr(nLen - nCount, nCount);
	}	
}

inline StringEx StringEx::Mid(int nPlace, int nCount) const
{
	return substr(nPlace,nCount);
}

inline void StringEx::Format(const char* szFormat, ...)
{
	char buf[4096];
	va_list ap;
	va_start(ap , szFormat);
	int len = vsnprintf(buf,sizeof(buf) - 1 ,szFormat,ap);
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

	*this = buf;
}

inline void StringEx::Decompose(const StringEx& split, vector<StringEx>& arStr) const
{
	arStr.clear();

	size_type pS = 0;
	size_type pE = find(split);
	
	while(pE != npos)
	{
		arStr.push_back(substr(pS,pE - pS));
		pS = pE + split.length();
		pE = find(split,pS);
	}

	if(pS < length())
	{
		arStr.push_back(substr(pS));
	}

}

inline LONG StringEx::ToLong() const
{
	LONG value = 0;
	sscanf(c_str(),"%d",(int*)&value);
	return value;
}

inline LONGLONG StringEx::ToLongLong() const
{
	LONGLONG value = 0;
#ifdef WIN32
	sscanf(c_str(),"%I64d",&value);
#else
	sscanf(c_str(),"%Ld",&value);
#endif
	return value;
}

#define string StringEx

}//end std

//编码转换函数
inline string StringAsciiToUtf8(const string& str);
inline string StringUtf8ToAscii(const string& str);
#ifdef WIN32
inline wstring StringAsciiToUnicode(const string& str);
inline wstring StringUtf8ToUnicode(const string& str);
inline string StringUnicodeToAscii(const wstring& str);
inline string StringUnicodeToUtf8(const wstring& str);
#endif

//整数转换函数
inline LONG StringToLong(const string& str);
inline LONGLONG	StingToLongLong(const string& str);
inline DWORD_PTR HexStringToPtr(const string& str);
inline string LongToString(LONG value);
inline string LongLongToString(LONGLONG value);
inline string PtrToHexString(DWORD_PTR value);


//时间转换函数
time_t	StringToTime(const string& strTime);
time_t	ShortStringToTime(const string& strTime);
string  TimeToString(const time_t& tm);
string  TimeToShortString(const time_t& tm);

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

//重载字符串拷贝函数
inline char* strncpy(char* dest, const char* source, size_t count)
{
	//assert(dest);
	//assert(count > 0);

	if(source == NULL)
	{
		if(count > 0)
		{
			dest[0] = '\0';
		}
		return dest;
	}

	char* p = dest;
	for(size_t i = 0;i < count;i++)
	{
		if((p[i] = source[i]) == '\0')
		{
			break;
		}
		
	}
	return dest;
}

#ifdef WIN32

inline string StringUnicodeToUtf8(const wstring& str)
{
	int nLen = WideCharToMultiByte(CP_UTF8,0,str.c_str(),-1,NULL,0,NULL,NULL);

	string strAscii;
	strAscii.assign(nLen - 1,0);
	WideCharToMultiByte(CP_UTF8,0,str.c_str(),-1,(LPSTR)strAscii.data(),nLen,NULL,NULL);
	return strAscii;
}
inline int StringUnicodeToUtf8(char *buf, int siz, const wstring &str)
{
	int clen;
	int wlen = str.length();
	while ((clen = WideCharToMultiByte(CP_UTF8,0,str.c_str(),wlen,NULL,0,NULL,NULL)) >= siz)
		--wlen;

	clen = WideCharToMultiByte(CP_UTF8,0,str.c_str(),wlen,buf,siz,NULL,NULL);
	buf[clen] = '\0';
	return clen;
}
template <int siz>
inline int StringUnicodeToUtf8(char (&text)[siz], const wstring &str)
{
	return StringUnicodeToUtf8(text, siz, str);
}
template <int siz>
inline int StringUnicodeToUtf8(unsigned char (&text)[siz], const wstring &str)
{
	return StringUnicodeToUtf8((char*)text, siz, str);
}

inline string StringUnicodeToAscii(const wstring& str)
{
	int nLen = WideCharToMultiByte(CP_ACP,0,str.c_str(),-1,NULL,0,NULL,NULL);

	string strAscii;
	strAscii.assign(nLen - 1,0);
	WideCharToMultiByte(CP_ACP,0,str.c_str(),-1,(LPSTR)strAscii.data(),nLen,NULL,NULL);
	return strAscii;
}

inline wstring StringAsciiToUnicode(const string& str)
{
	wstring wstr;
	int nLen = MultiByteToWideChar(CP_ACP,0,str.c_str(),-1,NULL,0);

	wstr.assign(nLen - 1,0);
	MultiByteToWideChar(CP_ACP,0,str.c_str(),-1,(LPWSTR)wstr.data(),nLen);
	return wstr;
}
inline wstring StringUtf8ToUnicode(const string& str)
{
	wstring wstr;
	int nLen = MultiByteToWideChar(CP_UTF8,0,str.c_str(),-1,NULL,0);

	wstr.assign(nLen - 1,0);
	MultiByteToWideChar(CP_UTF8,0,str.c_str(),-1,(LPWSTR)wstr.data(),nLen);
	return wstr;
}

inline string StringAsciiToUtf8(const string& str)
{
	wstring wstr;
	int nLen = MultiByteToWideChar(CP_ACP,0,str.c_str(),-1,NULL,0);

	wstr.assign(nLen - 1,0);
	MultiByteToWideChar(CP_ACP,0,str.c_str(),-1,(LPWSTR)wstr.data(),nLen);
	//
	string strUtf8;
	nLen = WideCharToMultiByte(CP_UTF8,0,wstr.c_str(),-1,NULL,0,NULL,NULL);
	strUtf8.assign(nLen - 1,0);
	WideCharToMultiByte(CP_UTF8,0,wstr.c_str(),-1,(LPSTR)strUtf8.data(),nLen,NULL,NULL);
	return strUtf8;
}

inline int StringAsciiToUtf8(char *buf, int siz, const string &str)
{
	wstring wstr = StringAsciiToUnicode(str);
	return StringUnicodeToUtf8(buf, siz, wstr);
}
template <int siz>
inline int StringAsciiToUtf8(char (&text)[siz], const string &str)
{
	return StringAsciiToUtf8(text, siz, str);
}
template <int siz>
inline int StringAsciiToUtf8(unsigned char (&text)[siz], const string &str)
{
	return StringAsciiToUtf8((char*)text, siz, str);
}

inline string StringUtf8ToAscii(const string& str)
{
	wstring wstr;
	int nLen = MultiByteToWideChar(CP_UTF8,0,str.c_str(),-1,NULL,0);

	wstr.assign(nLen - 1,0);
	MultiByteToWideChar(CP_UTF8,0,str.c_str(),-1,(LPWSTR)wstr.data(),nLen);
	//
	string strAscii;
	nLen = WideCharToMultiByte(CP_ACP,0,wstr.c_str(),-1,NULL,0,NULL,NULL);
	strAscii.assign(nLen - 1,0);
	WideCharToMultiByte(CP_ACP,0,wstr.c_str(),-1,(LPSTR)strAscii.data(),nLen,NULL,NULL);
	return strAscii;
}

#else

inline string StringAsciiToUtf8(const string& str)
{
	iconv_t cd = iconv_open("UTF-8","GB2312");
	
	char* in = (char*)str.data();
	size_t inLen = str.length();

	char outReal[1024];
	memset(outReal,0,sizeof(outReal));
	size_t outLen = sizeof(outReal) - 1;
	char* out = outReal;
	
	string strOut;
	for(;;)
	{
		iconv(cd,&in,&inLen,&out,&outLen);
		strOut.append(outReal);
		if(inLen > 0)
		{	
			memset(outReal,0,sizeof(outReal));
			outLen = sizeof(outReal) - 1;
			out = outReal;
		}
		else
		{
			break;
		}
	}

	iconv_close(cd);
	return strOut;
}

inline string StringUtf8ToAscii(const string& str)
{
	iconv_t cd = iconv_open("GB2312","UTF-8");
	
	char* in = (char*)str.data();
	size_t inLen = str.length();

	char outReal[1024];
	memset(outReal,0,sizeof(outReal));
	size_t outLen = sizeof(outReal) - 1;
	char* out = outReal;
	
	string strOut;
	for(;;)
	{
		iconv(cd,&in,&inLen,&out,&outLen);
		strOut.append(outReal);
		if(inLen > 0)
		{
			memset(outReal,0,sizeof(outReal));
			outLen = sizeof(outReal) - 1;
			out = outReal;
		}
		else
		{
			break;
		}
	}

	iconv_close(cd);
	return strOut;
}

#endif


inline LONG StringToLong(const string& str)
{
	LONG value = 0;
	sscanf(str.c_str(),"%d",(int*)&value);
	return value;
}

inline LONGLONG	StingToLongLong(const string& str)
{
	LONGLONG value = 0;
#ifdef WIN32
	sscanf(str.c_str(),"%I64d",&value);
#else
	sscanf(str.c_str(),"%Ld",&value);
#endif
	return value;
}

inline DWORD_PTR HexStringToPtr(const string& str)
{
	DWORD_PTR value = 0;
	sscanf(str.c_str(),"%x",(unsigned int*)&value);
	return value;
}

inline string LongToString(LONG value)
{
	char sz[128] = {0};
	sprintf(sz,"%d",(int)value);
	return sz;
}

inline string LongLongToString(LONGLONG value)
{
	char sz[128] = {0};
#ifdef WIN32
	sprintf(sz,"%I64d",value);
#else
	sprintf(sz,"%Ld",value);
#endif
	return sz;
}

inline string PtrToHexString(DWORD_PTR value)
{
	char sz[128] = {0};
	sprintf(sz,"%08x",(unsigned int)value);
	return sz;
}

inline time_t StringToTime(const string& strTime)
{
	struct tm tmLocal;

	sscanf(strTime.c_str(), "%4d-%2d-%2d %2d:%2d:%2d",     
                 &tmLocal.tm_year, 
                 &tmLocal.tm_mon, 
                 &tmLocal.tm_mday, 
                 &tmLocal.tm_hour, 
                 &tmLocal.tm_min,
                 &tmLocal.tm_sec);
           
    tmLocal.tm_year -= 1900;
    tmLocal.tm_mon--;
    tmLocal.tm_isdst = -1;

    return mktime(&tmLocal);
}

inline time_t ShortStringToTime(const string& strTime)
{
	struct tm tmLocal;

	sscanf(strTime.c_str(), "%4d%2d%2d%2d%2d%2d",     
                 &tmLocal.tm_year, 
                 &tmLocal.tm_mon, 
                 &tmLocal.tm_mday, 
                 &tmLocal.tm_hour, 
                 &tmLocal.tm_min,
                 &tmLocal.tm_sec);
           
    tmLocal.tm_year -= 1900;
    tmLocal.tm_mon--;
    tmLocal.tm_isdst = -1;

    return mktime(&tmLocal);
}

inline string TimeToString(const time_t& tm)
{
	struct tm tmLocal;

#ifdef WIN32
	tmLocal = *localtime(&tm);
#else
	localtime_r(&tm, &tmLocal );
#endif
	string strTime;
	strTime.Format("%04d-%02d-%02d %02d:%02d:%02d",
		tmLocal.tm_year+1900, tmLocal.tm_mon+1, tmLocal.tm_mday,
		tmLocal.tm_hour, tmLocal.tm_min,tmLocal.tm_sec);
	return strTime;
}

inline string TimeToShortString(const time_t& tm)
{
	struct tm tmLocal;

#ifdef WIN32
	tmLocal = *localtime(&tm);
#else
	localtime_r(&tm, &tmLocal );
#endif
	string strTime;
	strTime.Format("%04d%02d%02d%02d%02d%02d",
		tmLocal.tm_year+1900, tmLocal.tm_mon+1, tmLocal.tm_mday,
		tmLocal.tm_hour, tmLocal.tm_min,tmLocal.tm_sec);
	return strTime;
}

#endif//_string_fcn_h
