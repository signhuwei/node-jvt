
#ifndef __DECODE_H264PLAY_H__
#define __DECODE_H264PLAY_H__
#include <time.h>

#define VIDEO_PLAYER_API extern "C" __declspec(dllexport)

#define CALLMETHOD __stdcall
#define CALLBACK __stdcall

#define  FUNC_MAX_PORT 500              //��󲥷�ͨ����

#define TALK_PORT	499
#define TALK_PCM_PORT 500

//Wave coef range;
#define MIN_WAVE_COEF -100
#define MAX_WAVE_COEF 100

//Timer type
#define TIMER_1 1 //Only 16 timers for every process.Default TIMER;
#define TIMER_2 2 //Not limit;But the precision less than TIMER_1; 

//��������
#define BUF_VIDEO_SRC 1    //��ƵԴ����        
#define BUF_AUDIO_SRC 2    //��ƵԴ����
#define BUF_VIDEO_RENDER 3  //�������Ƶ���ݻ���
#define BUF_AUDIO_RENDER 4  //�������Ƶ���ݻ���

//��������
#define	VIDEOPLAYER_NOERROR               0           //û�д���
#define VIDEOPLAYER_PARA_OVER             1           //��������Ƿ���
#define VIDEOPLAYER_ORDER_ERROR           2           //����˳�򲻶ԣ�
#define VIDEOPLAYER_TIMER_ERROR           3           //��ý��ʱ������ʧ�ܣ�
#define VIDEOPLAYER_DEC_VIDEO_ERROR       4	          //��Ƶ����ʧ�ܣ�
#define VIDEOPLAYER_DEC_AUDIO_ERROR       5	          //��Ƶ����ʧ�ܣ�
#define VIDEOPLAYER_ALLOC_MEMORY_ERROR    6		       	//�����ڴ�ʧ�ܣ�
#define VIDEOPLAYER_OPEN_FILE_ERROR       7			   		//�ļ�����ʧ�ܣ�
#define VIDEOPLAYER_CREATE_OBJ_ERROR      8	          //�����߳��¼���ʧ�ܣ�
#define VIDEOPLAYER_CREATE_DDRAW_ERROR		9		       	//����directDrawʧ�ܣ�
#define VIDEOPLAYER_CREATE_OFFSCREEN_ERROR	10		    //������˻���ʧ�ܣ�
#define VIDEOPLAYER_BUF_OVER              11	        //����������������ʧ�ܣ�
#define VIDEOPLAYER_CREATE_SOUND_ERROR    12		      //������Ƶ�豸ʧ�ܣ�
#define VIDEOPLAYER_SET_VOLUME_ERROR      13	        //��������ʧ�ܣ�
#define VIDEOPLAYER_SUPPORT_FILE_ONLY     14		      //ֻ���ڲ����ļ�ʱ����ʹ�ô˽ӿڣ�
#define VIDEOPLAYER_SUPPORT_STREAM_ONLY   15		      //ֻ���ڲ�����ʱ����ʹ�ô˽ӿڣ�
#define VIDEOPLAYER_SYS_NOT_SUPPORT       16		      //ϵͳ��֧�֣�������ֻ�ܹ�����Pentium 3���ϣ�
#define VIDEOPLAYER_FILEHEADER_UNKNOWN    17		      //û���ļ�ͷ��
#define VIDEOPLAYER_VERSION_INCORRECT     18	        //�������ͱ������汾����Ӧ��
#define VIDEOPLAYER_INIT_DECODER_ERROR    19		      //��ʼ��������ʧ�ܣ�
#define VIDEOPLAYER_CHECK_FILE_ERROR      20		      //�ļ�̫�̻������޷�ʶ��
#define VIDEOPLAYER_INIT_TIMER_ERROR      21		      //��ʼ����ý��ʱ��ʧ�ܣ�
#define VIDEOPLAYER_BLT_ERROR             22		      //λ����ʧ�ܣ�
#define VIDEOPLAYER_UPDATE_ERROR          23			   	//��ʾoverlayʧ�ܣ�


//Max display regions.
#define MAX_DISPLAY_WND 4

//Display type
#define DISPLAY_NORMAL  1   
#define DISPLAY_QUARTER 2	

//Display buffers
#define MAX_DIS_FRAMES 50
#define MIN_DIS_FRAMES 6

//Locate by
#define BY_FRAMENUM  1
#define BY_FRAMETIME 2

//Source buffer
#define SOURCE_BUF_MAX	1024*100000
#define SOURCE_BUF_MIN	1024*50

//Stream type
#define STREAME_REALTIME 0
#define STREAME_FILE	 1

//frame type
#define T_AUDIO16	101
#define T_AUDIO8	100

#define T_UYVY		1
#define T_YV12		3
#define T_RGB32		7

//ϵͳ֧�ֵĹ��ܣ����ڰ�λ��ʾϵͳ����
#define SUPPORT_DDRAW		1			// ֧��DIRECTDRAW�������֧�֣��򲥷������ܹ�����
#define SUPPORT_BLT         2			// �Կ�֧��BLT�����������֧�֣��򲥷������ܹ���
#define SUPPORT_BLTFOURCC   4			// �Կ�BLT֧����ɫת����
#define SUPPORT_BLTSHRINKX  8			// �Կ�BLT֧��X����С��
#define SUPPORT_BLTSHRINKY  16		// �Կ�BLT֧��Y����С��
#define SUPPORT_BLTSTRETCHX 32		// �Կ�BLT֧��X��Ŵ�
#define SUPPORT_BLTSTRETCHY 64		// �Կ�BLT֧��Y��Ŵ�
#define SUPPORT_SSE         128		// CPU֧��SSEָ��,Intel Pentium3����֧��SSEָ�
#define SUPPORT_MMX			256		// CPU֧��MMXָ���

typedef enum _MEDIA_FILE_TYPE
{
	MEDIA_FILE_NONE = 0,
	MEDIA_FILE_H264 = 1,
	MEDIA_FILE_AVI = 2,
	MEDIA_FILE_RMVB = 3,
	MEDIA_FILE_MPG4 = 4,
	MEDIA_FILE_NUM
}MEDIA_FILE_TYPE;
typedef enum _PICTURE_FILE_TYPE
{
	PICTURE_FILE_BMP = 0,
	PICTURE_FILE_JPG = 1
		
}PICTURE_FILE_TYPE;

//Frame position
typedef struct{
	long nFilePos;
	long nFrameNum;
	long nFrameTime;
	long nErrorFrameNum;
	SYSTEMTIME *pErrorTime;
	long nErrorLostFrameNum;
	long nErrorFrameSize;
}FRAME_POS,*PFRAME_POS;

// Frame Info
typedef struct{
	long nWidth;		// �������λ���ء��������Ƶ������Ϊ0��
	long nHeight;		// ����ߡ��������Ƶ������Ϊ0��
	long nStamp;		// ʱ����Ϣ����λ���롣
	long nType;			// �������ͣ�T_AUDIO16��T_RGB32�� T_YV12������궨��˵����
	long nFrameRate;	// ����ʱ������ͼ��֡�ʡ�
}FRAME_INFO;

typedef struct 
{
	char *pDataBuf;
	long nSize;
	long nFrameNum;
	BOOL bIsAudio;
	long nReserved;
}FRAME_TYPE;

/// ��������
enum ENCODE_TYPE
{
	StreamTypeEmpty = 0,
	StreamTypeH264 = 2,
	StreamTypeJpeg = 3,
	StreamTypeGeneral = 4,
	StreamTypePCM8 = 7,
	StreamTypeStd = 8
};

/// ͼ��֡����
enum VIDEO_FRAME_TYPE
{
	FrameTypeUnknown = 0,
	FrameTypeVideo = 1,
	FrameTypeAudio = 2,
	FrameTypeData = 3,
};

/// ͼ��֡������
enum VIDEO_FRAME_SUB_TYPE
{
	FrameSubTypeIFrame = 0,
	FrameSubTypePFrame = 1,
	FrameSubTypeBFrame = 2,
	FrameSubTypeSFrame = 3,
	FrameSubTypeDataText = 5,
	FrameSubTypeDataIntl = 6,
};

typedef struct 
{
	unsigned char *pHeader;				///< ֡���ݻ�����ʼ��ַ
	unsigned char *pContent;
	unsigned long nLength;
	unsigned long nFrameLength;

	unsigned int nType;                ///< ��VIDEO_FRAME_TYPE
	unsigned int nSubType;             ///< ��VIDEO_FRAME_SUB_TYPE

	unsigned int nEncodeType;          ///< ��ENCODE_TYPE

	unsigned long nYear;				///< ֡ʱ���
	unsigned long nMonth;
	unsigned long nDay;
	unsigned long nHour;
	unsigned long nMinute;
	unsigned long nSecond;
	unsigned long nTimeStamp;	

	unsigned int  nFrameRate;			///< ��Ƶͼ��֡��
	int nWidth;							///< ��Ƶͼ���С����Ⱥ͸߶�
	int nHeight;
	unsigned long nRequence;

	unsigned int nChannels;
	unsigned int nBitsPerSample;		///< ��Ƶ����λ��
	unsigned int nSamplesPerSecond;		///< ��Ƶ������

	unsigned long nParam1;		// ��չ��
	unsigned long nParam2;		// ��չ��
} VIDEO_FRAME_INFO;


//�������ͣ�Ŀǰֻ֧����Щ
typedef enum 
{
	OSD_TXT_FONT_ARIAL = 1,
	OSD_TXT_FONT_SERIF,
	OSD_TXT_FONT_SANS,
	
	OSD_TXT_FONT_SIMSUN = 101,  // �������壬����
	OSD_TXT_FONT_SIMHEI
} DEFAULT_OSD_TXT_FONT;

typedef struct
{
	int pos_x;			//���λ��(�ٷֱ�)
	int pos_y;
	COLORREF color;		//������ɫ
	char text[256];
	DEFAULT_OSD_TXT_FONT font_type;
	int font_size;		//�Դ��ڵİٷֱ�����ʾ

	HFONT out_ft;		//�������������

	int isBold;			//�Ƿ����
	int isTransparent;	//�Ƿ�͸����ɫ
	COLORREF bkColor;	//����ɫ
} OSD_INFO_TXT;

typedef enum 
{
	STD_FILE_HEAD =	0,	    		// �ļ�ͷ
		STD_VIDEO_I_FRAME = 1,			// ��ƵI֡
		STD_VIDEO_B_FRAME =	2,			// ��ƵB֡
		STD_VIDEO_P_FRAME = 3,			// ��ƵP֡
		STD_VIDEO_BP_FRAME = 4,			// ��ƵBP֡
		STD_VIDEO_BBP_FRAME	= 5,		// ��ƵB֡B֡P֡
		STD_VIDEO_J_FRAME = 6,			// ͼƬ֡
		STD_AUDIO_PACKET = 10,			// ��Ƶ��
}MEDIA_DATA_TYPE;

typedef struct
{
	int		nPacketType;				// ������,MEDIA_DATA_TYPE
	char*	pPacketBuffer;				// ��������ַ
	unsigned int	dwPacketSize;				// ���Ĵ�С
	
	// ����ʱ��
	int		nYear;						// ʱ��:��		
	int		nMonth;						// ʱ��:��
	int		nDay;						// ʱ��:��
	int		nHour;						// ʱ��:ʱ
	int		nMinute;					// ʱ��:��
	int		nSecond;					// ʱ��:��
	unsigned int 	dwTimeStamp;					// ���ʱ���λ����λΪ����	
	unsigned int   dwFrameNum;             //֡���
	unsigned int   dwFrameRate;            //֡��
	unsigned short uWidth;              //ͼ����
	unsigned short uHeight;             //ͼ��߶�
	unsigned int   nAudioEncodeType;          //��Ƶ��������IMA	 9 PCM8_VWIS 12 MS_ADPCM 13 G711A 14
	unsigned int   nBitsPerSample;			//��Ƶ����λ��
	unsigned int   nSamplesPerSecond;       // ��Ƶ������
	unsigned int       Reserved[6];            //����
} STDH264_PACKET_INFO;


// �ص���������
typedef void (CALLBACK *AudioCaptureCallBack)(LPBYTE pDataBuffer, DWORD DataLength, long nUser);
typedef void (CALLBACK *DrawCallBack)(LONG nPort,HDC hDc,LONG nUser);
typedef void (CALLBACK *DrawCallBack_V2)(LONG nPort,HDC hDc,LONG nWWidth,LONG nWHeight,LONG nVWidth,LONG nVHeight,LONG nUser);
typedef void (CALLBACK *DecodeCallBack)(LONG nPort, LPCSTR pBuf,LONG nSize,FRAME_INFO * pFrameInfo, LONG nPlayedFrames);
typedef void (CALLBACK *DisplayCallBack)(LONG nPort,LPCSTR pBuf,LONG nSize,LONG nWidth,LONG nHeight, LONG nStamp,LONG nType,LONG nUser);
typedef void (CALLBACK *FileCallBack)(LONG nPort, LONG nUser);
typedef void (CALLBACK *VerifyCallBack)(LONG nPort, FRAME_POS * pFilePos, DWORD bIsVideo, LONG nUser);
typedef void (CALLBACK *AudioCallBack)(LONG nPort, PBYTE pAudioBuf, LONG nSize, LONG nStamp, LONG nType, LONG nUser);
typedef void (CALLBACK *DemuxCallBack)(LONG nPort, VIDEO_FRAME_INFO *pFrameInfo,LONG nUser);
typedef void (CALLBACK *SourceBufCallBack)(LONG nPort,DWORD nBufSize, LONG nUser);
typedef void (CALLBACK *ImageSizeChangeCallBack)(LONG nPort, LONG nUser);

typedef void (CALLBACK *CoverFileCallBack) (DWORD CurrentPos, DWORD TotoalPos,long dwUser);//ת������

//��Ϣ֡�ص�
typedef void (CALLBACK *InfoFramCallBack)(LONG nPort, LONG nType, LPCSTR pBuf,LONG nSize, LONG nUser);

//����Ϊ����ӿڣ����û������ο�������

VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_OpenFile(LONG nPort, LPCSTR sFileName);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_CloseFile(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_Play(LONG nPort, HWND hWnd);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_Stop(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_Pause(LONG nPort,DWORD nPause);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_Fast(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_Slow(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_NextFrame(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_PrevFrame(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetPlayPos(LONG nPort, FLOAT fRelativePos);
VIDEO_PLAYER_API FLOAT CALLMETHOD 	VideoPlayer_GetPlayPos(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetFileEndMsg(LONG nPort,HWND hWnd,UINT nMsg);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetFileEndCallBack(LONG nPort, FileCallBack pProc,LONG nUser);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetVolume(LONG nPort,WORD nVolume);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_StopSound();
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_PlaySound(LONG nPort);
VIDEO_PLAYER_API BOOL	CALLMETHOD 	VideoPlayer_OpenStream(LONG nPort,PBYTE pFileHeadBuf,DWORD nSize,DWORD nBufPoolSize);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_InputData(LONG nPort,PBYTE pBuf,DWORD nSize);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_CloseStream(LONG nPort);
VIDEO_PLAYER_API LONG  CALLMETHOD 	VideoPlayer_GetCaps();
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetFileTime(LONG nPort);
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetPlayedTime(LONG nPort);
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetPlayedFrames(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_Back(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetDecCallBack(LONG nPort, DecodeCallBack pProc);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetDisplayCallBack(LONG nPort, DisplayCallBack pProc, LONG nUser);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_ConvertToBmpFile(PBYTE pBuf,LONG nSize,LONG nWidth,LONG nHeight, LPCSTR sFileName,char*pDstBuf=NULL);
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetFileTotalFrames(LONG nPort);
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetPlayedTimeEx(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetPlayedTimeEx(LONG nPort,DWORD nTime);
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetCurrentFrameNum(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetStreamOpenMode(LONG nPort,DWORD nMode);
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetSdkVersion();
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetLastError(LONG nPort);
VIDEO_PLAYER_API BOOL  CALLMETHOD 	VideoPlayer_RefreshPlay(LONG nPort);
VIDEO_PLAYER_API BOOL  CALLMETHOD 	VideoPlayer_SetOverlayMode(LONG nPort,BOOL bOverlay,COLORREF colorKey);
VIDEO_PLAYER_API BOOL  CALLMETHOD 	VideoPlayer_GetPictureSize(LONG nPort,LONG *pWidth,LONG *pHeight);
VIDEO_PLAYER_API BOOL  CALLMETHOD 	VideoPlayer_SetPicQuality(LONG nPort,BOOL bHighQuality);
VIDEO_PLAYER_API BOOL  CALLMETHOD 	VideoPlayer_PlaySoundShare(LONG nPort);
VIDEO_PLAYER_API BOOL  CALLMETHOD 	VideoPlayer_StopSoundShare(LONG nPort);
VIDEO_PLAYER_API LONG 	CALLMETHOD 	VideoPlayer_GetStreamOpenMode(LONG nPort);
VIDEO_PLAYER_API LONG 	CALLMETHOD 	VideoPlayer_GetOverlayMode(LONG nPort);
VIDEO_PLAYER_API WORD 	CALLMETHOD 	VideoPlayer_GetVolume(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_GetPictureQuality(LONG nPort,BOOL *bHighQuality);
VIDEO_PLAYER_API DWORD CALLMETHOD	VideoPlayer_GetSourceBufferRemain(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_ResetSourceBuffer(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetSourceBufCallBack(LONG nPort,DWORD nThreShold, SourceBufCallBack pProc, LONG nUser);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_ResetSourceBufFlag(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetDisplayBuf(LONG nPort,DWORD nNum);
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetDisplayBuf(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetFileRefCallBack(LONG nPort, FileCallBack pProc, LONG nUser);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS pFramePos);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_InitDDrawDevice();
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_ReleaseDDrawDevice();
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetDDrawDeviceTotalNums();

VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetDisplayType(LONG nPort,LONG nType);
VIDEO_PLAYER_API LONG 	CALLMETHOD 	VideoPlayer_GetDisplayType(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetDecCBStream(LONG nPort,DWORD nStream);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetDisplayRegion(LONG nPort,DWORD nRegionNum, RECT *pSrcRect, HWND hDestWnd, BOOL bEnable);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_RefreshPlayEx(LONG nPort,DWORD nRegionNum);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_GetRefValue(LONG nPort,BYTE *pBuffer, DWORD *pSize);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_InputVideoData(LONG nPort,PBYTE pBuf,DWORD nSize);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_InputAudioData(LONG nPort,PBYTE pBuf,DWORD nSize);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_RigisterDrawFun(LONG nPort, DrawCallBack pProc,LONG nUser);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetTimerType(LONG nPort,DWORD nTimerType);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_GetTimerType(LONG nPort,DWORD *pTimerType);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_ResetBuffer(LONG nPort,DWORD nBufType);
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetBufferValue(LONG nPort,DWORD nBufType);

VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_AdjustWaveAudio(LONG nPort,LONG nCoefficient);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetVerifyCallBack(LONG nPort, DWORD nBeginTime, DWORD nEndTime, VerifyCallBack pProc, LONG nUser);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetAudioCallBack(LONG nPort, AudioCallBack pProc, LONG nUser);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetImageSizeChangeCallBack(LONG nPort,ImageSizeChangeCallBack pProc,LONG nUser);
VIDEO_PLAYER_API BOOL 	CALLMETHOD	VideoPlayer_SetImageSizeChangeMsg(LONG nPort,HWND hWnd,UINT nMsg);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetColor(LONG nPort, DWORD nRegionNum, LONG nBrightness, LONG nContrast, LONG nSaturation, LONG nHue);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_GetColor(LONG nPort, DWORD nRegionNum, LONG *pBrightness, LONG *pContrast, LONG *pSaturation, LONG *pHue);

VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetMDRange(LONG nPort,RECT* rc,DWORD nVauleBegin,DWORD nValueEnd,DWORD nType);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetMDThreShold(LONG nPort, DWORD ThreShold) ;
VIDEO_PLAYER_API DWORD CALLMETHOD 	VideoPlayer_GetMDPosition(LONG nPort, DWORD Direction, DWORD nFrame, DWORD* MDValue) ;

VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_CatchPic(LONG nPort, LPCSTR sFileName,long ntype=0 ) ;
VIDEO_PLAYER_API LONG  CALLMETHOD 	VideoPlayer_CatchPicBuf(LONG nPort, char* pBuf,LONG len,LONG *width,LONG *height,long ntype=0) ;

VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_StartDataRecord(LONG nPort,  LPCSTR sFileName, LONG nType);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_StopDataRecord(LONG nPort);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_AdjustFluency(LONG nPort, int level);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_AdjustFluencyEx(LONG nPort, int time);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetPlayFPS(LONG nPort, LONG nFPS);
VIDEO_PLAYER_API LONG 	CALLMETHOD 	VideoPlayer_GetPlayFPS(LONG nPort);

VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetDemuxCallBack(LONG nPort, DemuxCallBack pProc, LONG nUser);

VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_StartAudioCapture(AudioCaptureCallBack pProc, LONG nBitsPerSample, LONG nSamplesPerSec, LONG nLength, LONG nUser);
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_StopAudioCapture();
VIDEO_PLAYER_API BOOL  CALLMETHOD	VideoPlayer_GetPort(LONG* nPort);
VIDEO_PLAYER_API BOOL	CALLMETHOD	VideoPlayer_FreePort(LONG nPort);
VIDEO_PLAYER_API COLORREF 	CALLMETHOD	VideoPlayer_GetColorKey(LONG nPort);
VIDEO_PLAYER_API LONG	CALLMETHOD	VideoPlayer_GetFileHeadLength();
VIDEO_PLAYER_API DWORD CALLMETHOD VideoPlayer_GetCurTimeStamp(LONG nPort);

//����osd������Ϣ,������openstream��play֮ǰ���ã�������Ч
VIDEO_PLAYER_API int CALLMETHOD VideoPlayer_SetOsdTex(LONG nPort, OSD_INFO_TXT * txt);
//ɾ��osd������Ϣ,nIndex��VideoPlayer_SetOsdTex�ķ���ֵ
VIDEO_PLAYER_API int CALLMETHOD VideoPlayer_DeleteOsdTex(LONG nPort, int nIndex);
//H264¼���ļ�תAvi¼���ļ�
VIDEO_PLAYER_API int CALLMETHOD VideoPlayer_ConvertFile(const char* pSourceFile,const char* pDestFile,  LONG nType, CoverFileCallBack coverPosCallback, DWORD dwUser);

//��Ϣ֡�ص�
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_SetInfoFrameCallBack(LONG nPort, InfoFramCallBack pProc, LONG nUser);

//ֻ����I֡
VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_OnlyIFrame(LONG nPort, bool bPlayOnlyIFrame);

//��׼H264����д��
VIDEO_PLAYER_API BOOL CALLMETHOD VideoPlayer_InputStdH264Data(LONG nPort,STDH264_PACKET_INFO *infor);

VIDEO_PLAYER_API BOOL 	CALLMETHOD 	VideoPlayer_RigisterDrawFun_V2(LONG nPort, DrawCallBack_V2 pProc,LONG nUser);

#endif

