/******************************************************************************
* 系统名称：HHReadWriter
* 文件名称：HHReadWriter.h
* 版本    ：V5.5.0.0
* 说明	  ：该文件提供一些常用定义

* 日    期: 2005年3月10日
  最近更新:	
* 其他说明: 无
******************************************************************************/
#ifndef HHREADWRITER_H
#define HHREADWRITER_H

#define DLLEXPORT_API  extern "C"__declspec(dllexport) 

/*****************************************************************************/
/*********************************  一、宏定义  ******************************/
/*****************************************************************************/
#ifndef HHFILEERROR_H
#define HHFILEERROR_H
#define ERR_FILE_SUCCESS                0
#define ERR_FILE_INVALID_PARAMETER     -1   //参数错误
#define ERR_FILE_INVALID_FILE          -2   //无效的文件
#define ERR_FILE_OPEN_FAIL             -3   //文件打开失败
#define ERR_FILE_INVALID               -4   //无法识别的文件
#define ERR_FILE_NO_OPEN               -5   //文件没有打开
#define ERR_FILE_NO_FRAME              -6   //要取的帧被丢失
#define ERR_FILE_OPER_FAIL             -7   //文件操作失败
#define ERR_FILE_START                 -8   //文件头不能帧退
#define ERR_FILE_OVER                  -9   //文件末尾
#define ERR_FILE_END                   -10   //文件末尾不能播放
#define ERR_STREAM_NOINI               -11  //流没有初始化
#endif 

/*****************************************************************************/
/******************************  二、接口结构类型定义  ***********************/
/*****************************************************************************/
enum eHHFrameType
{
	eType_Frame_A = 0x0d,
	eType_Frame_I = 0x0e,
	eType_Frame_P = 0x0b,
};

typedef struct _tagHHFileFrameInfo
{
	char  cFrameType;
	DWORD dwPlayTime;
	DWORD dwFrameSize;
	union
	{
		DWORD dwAudioEncType;
		DWORD dwVideoEncType;	
	};
	BYTE *pFrameBuffer;
	_tagHHFileFrameInfo()
	{
		memset(this,0,sizeof(_tagHHFileFrameInfo));
	}

	int			m_PlayStatus;	//当前播放状态（正常播放，快进...）
}HHFILEFRAMEINFO;				//帧BUFF用于读取每帧数据

typedef struct _tagHHFileInfo
{	
	DWORD dwFileSize;
	DWORD dwPlayTime;
    DWORD dwReserve[2];
	_tagHHFileInfo()
	{
		memset(this,0,sizeof(_tagHHFileInfo));
	}
}HHFILEINFO;				//帧BUFF用于读取每帧数据




/*****************************************************************************/
/********************************  三、函数接口定义  *************************/
/*****************************************************************************/
//------------------------------  1、文件读取和播放  -------------------------------//
//初始化读
DLLEXPORT_API HANDLE __stdcall HHFile_InitReader();
//释放
DLLEXPORT_API int    __stdcall HHFile_ReleaseReader(HANDLE hReader);
//打开
DLLEXPORT_API int    __stdcall HHFile_OpenFile(     HANDLE hReader, LPCTSTR filelist[], int filenum, DWORD &nTimeLength);
//关闭
DLLEXPORT_API int    __stdcall HHFile_CloseFile(    HANDLE hReader);
//取得文件信息
DLLEXPORT_API int    __stdcall HHFile_GetFileInfo(   HANDLE hReader, DWORD *dwTimeLength, DWORD *dwFileLength);            //得到文件信息
//取得文件Pal信息
DLLEXPORT_API int    __stdcall HHFile_GetFilePal(    HANDLE hReader, DWORD *pdwPal);
//取得下一帧
DLLEXPORT_API int    __stdcall HHFile_GetNextFrame(  HANDLE hReader, HHFILEFRAMEINFO &xFileFrameInfo);
//取得下一帧2
DLLEXPORT_API int    __stdcall HHFile_GetNextFrame2( HANDLE hReader, char &cFrameType,BYTE **ppFrameBuffer,DWORD &dwFrameSize,DWORD &dwEncType,DWORD &dwPlayTime);
//取得位置
DLLEXPORT_API int    __stdcall HHFile_GetPosition(    HANDLE hReader,DWORD *dwPlayedTime);			
//设置播放位置
DLLEXPORT_API int    __stdcall HHFile_SetPosition(    HANDLE hReader,float fOffset);				
//移动播放指针到指定秒
DLLEXPORT_API int    __stdcall HHFile_SeekToSecond(   HANDLE hReader,int nSec);						
//循环播放 
DLLEXPORT_API int    __stdcall HHFile_SetLoop(        HANDLE hReader,bool bIsLoop = true);			
//顺序读 
DLLEXPORT_API int    __stdcall HHFile_SetReadOrder(   HANDLE hReader,bool bIsOrder = true);			
//只取关键帧
DLLEXPORT_API int    __stdcall HHFile_SetReadKeyFrame(HANDLE hReader,bool bIsKeyFrame = false);		

//------------------------------  1、文件写入和播放  -------------------------------//
enum eWriteFileStatus
{
	eStatus_CreateFileSuccess = 1,
	eStatus_CloseFileSuccess  = 2,
	eStatus_CreateFileError  = -1,
	eStatus_WriteFileError   = -2,
};
typedef int (WINAPI *HHWriteFileCB)(LPCTSTR strFileName,DWORD dwStatus,HHFILEINFO *pFileInfo,void *pContext);

//初始化写
DLLEXPORT_API HANDLE __stdcall HHFile_InitWriter();
//释放
DLLEXPORT_API int    __stdcall HHFile_ReleaseWriter( HANDLE hWriter);
//设置BUFFER大小
DLLEXPORT_API int    __stdcall HHFile_SetCacheBufferSize( HANDLE hWriter,long lBufferSize = 500*1024);
//写
DLLEXPORT_API int    __stdcall HHFile_RegWriteFileCB(HANDLE hWriter,HHWriteFileCB pCBWriteFile,void *pContext = NULL);
//输入一帧
DLLEXPORT_API int    __stdcall HHFile_InputFrame(    HANDLE hWriter,BYTE *pFrame,long lFrameSize,DWORD dwEncType = 0);
//开始写
DLLEXPORT_API int    __stdcall HHFile_StartWrite(    HANDLE hWriter,LPCTSTR strFileName);
//取得写信息
DLLEXPORT_API int    __stdcall HHFile_GetWriteInfo(  HANDLE hWriter,HHFILEINFO &xFileInfo);
//停止写
DLLEXPORT_API int    __stdcall HHFile_StopWrite(     HANDLE hWriter);

#endif  