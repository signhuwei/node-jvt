/******************************************************************************
* ϵͳ���ƣ�HHReadWriter
* �ļ����ƣ�HHReadWriter.h
* �汾    ��V5.5.0.0
* ˵��	  �����ļ��ṩһЩ���ö���

* ��    ��: 2005��3��10��
  �������:	
* ����˵��: ��
******************************************************************************/
#ifndef HHREADWRITER_H
#define HHREADWRITER_H

#define DLLEXPORT_API  extern "C"__declspec(dllexport) 

/*****************************************************************************/
/*********************************  һ���궨��  ******************************/
/*****************************************************************************/
#ifndef HHFILEERROR_H
#define HHFILEERROR_H
#define ERR_FILE_SUCCESS                0
#define ERR_FILE_INVALID_PARAMETER     -1   //��������
#define ERR_FILE_INVALID_FILE          -2   //��Ч���ļ�
#define ERR_FILE_OPEN_FAIL             -3   //�ļ���ʧ��
#define ERR_FILE_INVALID               -4   //�޷�ʶ����ļ�
#define ERR_FILE_NO_OPEN               -5   //�ļ�û�д�
#define ERR_FILE_NO_FRAME              -6   //Ҫȡ��֡����ʧ
#define ERR_FILE_OPER_FAIL             -7   //�ļ�����ʧ��
#define ERR_FILE_START                 -8   //�ļ�ͷ����֡��
#define ERR_FILE_OVER                  -9   //�ļ�ĩβ
#define ERR_FILE_END                   -10   //�ļ�ĩβ���ܲ���
#define ERR_STREAM_NOINI               -11  //��û�г�ʼ��
#endif 

/*****************************************************************************/
/******************************  �����ӿڽṹ���Ͷ���  ***********************/
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

	int			m_PlayStatus;	//��ǰ����״̬���������ţ����...��
}HHFILEFRAMEINFO;				//֡BUFF���ڶ�ȡÿ֡����

typedef struct _tagHHFileInfo
{	
	DWORD dwFileSize;
	DWORD dwPlayTime;
    DWORD dwReserve[2];
	_tagHHFileInfo()
	{
		memset(this,0,sizeof(_tagHHFileInfo));
	}
}HHFILEINFO;				//֡BUFF���ڶ�ȡÿ֡����




/*****************************************************************************/
/********************************  ���������ӿڶ���  *************************/
/*****************************************************************************/
//------------------------------  1���ļ���ȡ�Ͳ���  -------------------------------//
//��ʼ����
DLLEXPORT_API HANDLE __stdcall HHFile_InitReader();
//�ͷ�
DLLEXPORT_API int    __stdcall HHFile_ReleaseReader(HANDLE hReader);
//��
DLLEXPORT_API int    __stdcall HHFile_OpenFile(     HANDLE hReader, LPCTSTR filelist[], int filenum, DWORD &nTimeLength);
//�ر�
DLLEXPORT_API int    __stdcall HHFile_CloseFile(    HANDLE hReader);
//ȡ���ļ���Ϣ
DLLEXPORT_API int    __stdcall HHFile_GetFileInfo(   HANDLE hReader, DWORD *dwTimeLength, DWORD *dwFileLength);            //�õ��ļ���Ϣ
//ȡ���ļ�Pal��Ϣ
DLLEXPORT_API int    __stdcall HHFile_GetFilePal(    HANDLE hReader, DWORD *pdwPal);
//ȡ����һ֡
DLLEXPORT_API int    __stdcall HHFile_GetNextFrame(  HANDLE hReader, HHFILEFRAMEINFO &xFileFrameInfo);
//ȡ����һ֡2
DLLEXPORT_API int    __stdcall HHFile_GetNextFrame2( HANDLE hReader, char &cFrameType,BYTE **ppFrameBuffer,DWORD &dwFrameSize,DWORD &dwEncType,DWORD &dwPlayTime);
//ȡ��λ��
DLLEXPORT_API int    __stdcall HHFile_GetPosition(    HANDLE hReader,DWORD *dwPlayedTime);			
//���ò���λ��
DLLEXPORT_API int    __stdcall HHFile_SetPosition(    HANDLE hReader,float fOffset);				
//�ƶ�����ָ�뵽ָ����
DLLEXPORT_API int    __stdcall HHFile_SeekToSecond(   HANDLE hReader,int nSec);						
//ѭ������ 
DLLEXPORT_API int    __stdcall HHFile_SetLoop(        HANDLE hReader,bool bIsLoop = true);			
//˳��� 
DLLEXPORT_API int    __stdcall HHFile_SetReadOrder(   HANDLE hReader,bool bIsOrder = true);			
//ֻȡ�ؼ�֡
DLLEXPORT_API int    __stdcall HHFile_SetReadKeyFrame(HANDLE hReader,bool bIsKeyFrame = false);		

//------------------------------  1���ļ�д��Ͳ���  -------------------------------//
enum eWriteFileStatus
{
	eStatus_CreateFileSuccess = 1,
	eStatus_CloseFileSuccess  = 2,
	eStatus_CreateFileError  = -1,
	eStatus_WriteFileError   = -2,
};
typedef int (WINAPI *HHWriteFileCB)(LPCTSTR strFileName,DWORD dwStatus,HHFILEINFO *pFileInfo,void *pContext);

//��ʼ��д
DLLEXPORT_API HANDLE __stdcall HHFile_InitWriter();
//�ͷ�
DLLEXPORT_API int    __stdcall HHFile_ReleaseWriter( HANDLE hWriter);
//����BUFFER��С
DLLEXPORT_API int    __stdcall HHFile_SetCacheBufferSize( HANDLE hWriter,long lBufferSize = 500*1024);
//д
DLLEXPORT_API int    __stdcall HHFile_RegWriteFileCB(HANDLE hWriter,HHWriteFileCB pCBWriteFile,void *pContext = NULL);
//����һ֡
DLLEXPORT_API int    __stdcall HHFile_InputFrame(    HANDLE hWriter,BYTE *pFrame,long lFrameSize,DWORD dwEncType = 0);
//��ʼд
DLLEXPORT_API int    __stdcall HHFile_StartWrite(    HANDLE hWriter,LPCTSTR strFileName);
//ȡ��д��Ϣ
DLLEXPORT_API int    __stdcall HHFile_GetWriteInfo(  HANDLE hWriter,HHFILEINFO &xFileInfo);
//ֹͣд
DLLEXPORT_API int    __stdcall HHFile_StopWrite(     HANDLE hWriter);

#endif  