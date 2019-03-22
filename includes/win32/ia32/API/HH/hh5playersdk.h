#ifndef HH5PLAYERSDK_H
#define HH5PLAYERSDK_H

#define DLLEXPORT_API  extern "C"__declspec(dllexport) 

#include <mmsystem.h>
#include "HHAVDefine.h"

//================================================================
//宏定义
//================================================================
#define HH5PLAYER_MAX_PLAER		128											//最多支持128路解码<nPort = 0 ~ 127>

#define HH5PLAYER_MSG_PLAY_END	0xFFFFFFFF									//消息定义<文件播放结束>
																			//非0xFFFFFFFF: 播放进度: 0 ~ 文件时间长度（秒）
typedef	HHAV_INFO		HH5KAV_INFO;
typedef	PHHAV_INFO		PHH5KAV_INFO;

#define HH5PLAYER_STREAM_REALTIME	0
#define HH5PLAYER_STREAME_FILE		1

//================================================================
//SDK初始化,释放 -  化播放器初始化,释放
//================================================================
DLLEXPORT_API int __stdcall HH5PLAYER_InitSDK(HWND hHwnd);					//初始化SDK资源
DLLEXPORT_API int __stdcall HH5PLAYER_ReleaseSDK();							//释放  SDK资源
DLLEXPORT_API int __stdcall HH5PLAYER_InitPlayer(USHORT nPort,HWND hWnd);	//初始化播放器(参见HH5PLAYER_InitPlayer2)
DLLEXPORT_API int __stdcall HH5PLAYER_ReleasePlayer(USHORT nPort);			//释放播放器

//================================================================
//文件播放
//================================================================
DLLEXPORT_API int __stdcall HH5PLAYER_OpenStreamFileM(USHORT nPort,LPCTSTR filelist[], int filenum, DWORD &nTimeLength);
DLLEXPORT_API int __stdcall HH5PLAYER_GetStreamFileInfo(USHORT nPort, DWORD *dwTimeLength, DWORD *dwFileLength, DWORD *dwWidth,DWORD *dwHeight);  //得到文件信息
DLLEXPORT_API int __stdcall HH5PLAYER_Play(USHORT nPort);                      //播放
DLLEXPORT_API int __stdcall HH5PLAYER_FastPlay(USHORT nPort,DWORD nValue);     //快速播放  dwValue 1---1000之间毫秒
DLLEXPORT_API int __stdcall HH5PLAYER_FastPlayBack(USHORT nPort,DWORD nValue); //块退
DLLEXPORT_API int __stdcall HH5PLAYER_FrameGO(USHORT nPort);                   //单帧进
DLLEXPORT_API int __stdcall HH5PLAYER_FrameBack(USHORT nPort);                 //单帧退
DLLEXPORT_API int __stdcall HH5PLAYER_Pause(USHORT nPort);                     //暂停  
DLLEXPORT_API int __stdcall HH5PLAYER_Resume(USHORT nPort);                    //继续
DLLEXPORT_API int __stdcall HH5PLAYER_Stop(USHORT nPort);                      //停止

DLLEXPORT_API int __stdcall HH5PLAYER_GetPlayPosition(USHORT nPort,DWORD *dwPlayedTime);			//得到播放的时间
DLLEXPORT_API int __stdcall HH5PLAYER_SetPlayPosition(USHORT nPort,float fOffset);					//设置播放位置
DLLEXPORT_API int __stdcall HH5PLAYER_SeekToSecond(USHORT nPort,int nSec);							//移动播放指针到指定秒
DLLEXPORT_API int __stdcall HH5PLAYER_SetPlayLoop(USHORT nPort,bool  bIsLoop);						//循环播放 
DLLEXPORT_API int __stdcall HH5PLAYER_RegPlayStatusMsg(USHORT nPort, HWND hWnd, UINT MessageID);	//注册播放状态消息(1.H5PLAYER_MSG_PLAY_END:文件播放结束	2.播放进度:0 ~ 文件时间长度<秒)

//================================================================
//流播放
//================================================================
DLLEXPORT_API int __stdcall HH5PLAYER_OpenStream(USHORT nPort);
DLLEXPORT_API int __stdcall HH5PLAYER_PutDecStreamData(USHORT nPort,PBYTE pBuf, DWORD nSize, int nDataType);
DLLEXPORT_API int __stdcall HH5PLAYER_PutDecStreamDataEx(USHORT nPort,PBYTE pBuf, DWORD nSize, UINT nDataType = 0x10, HH5KAV_INFO *pAVInfo = NULL);	
DLLEXPORT_API int __stdcall HH5PLAYER_StopStream(USHORT nPort);
DLLEXPORT_API int __stdcall HH5PLAYER_CloseStream(USHORT nPort);
DLLEXPORT_API int __stdcall HH5PLAYER_GetStreamFrameSize(USHORT nPort);
DLLEXPORT_API int __stdcall HH5PLAYER_GetAudioFrameSize(USHORT nPort);
DLLEXPORT_API int __stdcall HH5PLAYER_SetStreamPlaySpeed(USHORT nPort, USHORT nSpeed);
DLLEXPORT_API int __stdcall HH5PLAYER_GetStreamPlaySpeed(USHORT nPort);

//fValue:每帧播放时间, 如: 40ms, 33.3ms, bDelayAdjust:是否在有丢帧时, 校准时间(注:若是对关键帧播放,一定要置为false)
DLLEXPORT_API int __stdcall HH5PLAYER_SetStreamPlaySpeed2(USHORT nPort,float fValue,bool bDelayAdjust = true);

//================================================================
//其它
//================================================================
DLLEXPORT_API int __stdcall HH5PLAYER_SetAudio(USHORT nPort,bool bEnabled);         //设置音频
DLLEXPORT_API int __stdcall HH5PLAYER_UpDateImage(USHORT nPort);					//刷新图象
DLLEXPORT_API int __stdcall HH5PLAYER_UpdateBounds(USHORT nPort);					//刷新显示窗口边界  
DLLEXPORT_API int __stdcall HH5PLAYER_SetDisplayhWnd(USHORT nPort,HWND hWnd);		//设置显示窗口
DLLEXPORT_API int __stdcall HH5PLAYER_SetPartDisplay(USHORT nPort,HWND hPartWnd,RECT *pPartRect);	//局部放大显示
DLLEXPORT_API int __stdcall HH5PLAYER_CaptureOnePicture(USHORT nPort,void **bmpbuf,int &bmpsize);	//捕捉当前的图像

DLLEXPORT_API int __stdcall HH5PLAYER_GetVolume(USHORT nPort, long *lpVolume);		//设置音量
DLLEXPORT_API int __stdcall HH5PLAYER_SetVolume(USHORT nPort, long lVolume);		//获取音量

DLLEXPORT_API int __stdcall HH5PLAYER_SetDecoderQulity(bool bQulity);				//0: 高质量  1: 低质量
DLLEXPORT_API int __stdcall HH5PLAYER_SetDecoderParam(bool bZoomIn, bool bDeInterlace, bool bPlayMode = FALSE);		//bZoomIn:		大画面显示
																													//bDeInterlace:	消隔行锯齿
																													//bPlayMode		TRUE  流畅优先	FALSE 实时优先
DLLEXPORT_API int __stdcall HH5PLAYER_SetVideoBufferSize(int nFrameNum = 15);		//当流畅性优先时，缓存的帧数(1 ~ 60)

DLLEXPORT_API int __stdcall HH5PLAYER_ClearAllBuffer(USHORT nPort);										
DLLEXPORT_API int __stdcall HH5PLAYER_ClearVideoBuffer(USHORT nPort);		
DLLEXPORT_API int __stdcall HH5PLAYER_ClearAudioBuffer(USHORT nPort);		
DLLEXPORT_API int __stdcall HH5PLAYER_ClearImage(USHORT nPort, DWORD dwColor = 0);	//清除DirctX表面

//================================================================
//音频编解码
//================================================================
DLLEXPORT_API int   __stdcall HH5PLAYER_AudioEncodeData(unsigned short *BuffIn,   int InNum, BYTE *BuffOut);
DLLEXPORT_API int   __stdcall HH5PLAYER_AudioDecodeData(BYTE *BuffIn,  int InNum, unsigned short  *BuffOut);

/*默认G.726 16kbps*/
DLLEXPORT_API int   __stdcall HH5PLAYER_G726AEncodeData(unsigned short *BuffIn,   int InNum, BYTE *BuffOut);
DLLEXPORT_API int   __stdcall HH5PLAYER_G726ADecodeData(BYTE *BuffIn,  int InNum, unsigned short  *BuffOut);

#define		HH5PLAYER_G722AEncodeData	HH5PLAYER_AudioEncodeData
#define		HH5PLAYER_G722ADecodeData	HH5PLAYER_AudioDecodeData

//================================================================================
//新增函数1: 音频编解码
//================================================================================
//针HH98系列和HH58系列设备提供的接口，可以编解码G.711 G.726 ADPCM格式
DLLEXPORT_API int   __stdcall HH5PLAYER_AudioEncodeDataEx(unsigned short *BuffIn,   int InNum, BYTE *BuffOut, UINT nEncodeType, UINT nBitrate);
DLLEXPORT_API int   __stdcall HH5PLAYER_AudioDecodeDataEx(BYTE *BuffIn,  int InNum, unsigned short  *BuffOut, UINT nEncodeType, UINT nBitrate);

//================================================================================
//新增函数2: 视频解码及视频操作
//================================================================================
DLLEXPORT_API int   __stdcall HH5PLAYER_SelectH264(USHORT nPort,UINT nVersion);				//nVersion 1:old(123),2:new(125)
DLLEXPORT_API int   __stdcall HH5PLAYER_WaitForVerticalBlank(bool bWait = false);			//抗裂痕功能开关 false: 关  true: 开

//注: 当要在在视频图像上叠加图片、画线等时，请用以下函数初始化播放器，并将bSupportDraw设为true(在播放窗口上支持外部或内部HDC)
DLLEXPORT_API int   __stdcall HH5PLAYER_InitPlayer2(USHORT nPort,HWND hWnd,bool bSupportDraw = false);
DLLEXPORT_API int   __stdcall HH5PLAYER_DrawImage( USHORT nPort,int x,int y,unsigned char *pBmpImage,int nSize);
DLLEXPORT_API int   __stdcall HH5PLAYER_DrawText(  USHORT nPort,int x,int y,char *pszText,LOGFONT ft,COLORREF crText,COLORREF crBack = -1/*crBack -1: 透明*/);
DLLEXPORT_API int   __stdcall HH5PLAYER_SetDrawPen(USHORT nPort,int nPenStyle,int nWidth, COLORREF crColor);
DLLEXPORT_API int   __stdcall HH5PLAYER_DrawLine(  USHORT nPort,int x1,int y1,int x2,int y2);
DLLEXPORT_API int   __stdcall HH5PLAYER_DrawRect(  USHORT nPort,int x1,int y1,int x2,int y2);
DLLEXPORT_API int   __stdcall HH5PLAYER_ClearDraw( USHORT nPort,int nType);					//nType: 0 all, 1 image, 2 text, 3 line, rect

typedef int (WINAPI *HHCBOnDraw)(USHORT nPort, HDC hdc, int nWidth, int nHeight, void *pContext);	//支持外部调用HDC
DLLEXPORT_API int   __stdcall HH5PLAYER_RegCBOnDraw(USHORT nPort, HHCBOnDraw pCBOnDraw, void *pContext = NULL);

//================================================================================
//新增函数3: 对讲
//================================================================================
typedef int (WINAPI *HHTalkCaptureData)(BYTE *pBuffer, int nBufLen, DWORD dwContext /*= 0*/, void *pContext /*= NULL*/);

DLLEXPORT_API int __stdcall HH5PLAYER_TKInit(  HWND hWnd, HANDLE &hTalk);
DLLEXPORT_API int __stdcall HH5PLAYER_TKRegCaptureDataCB(HANDLE hTalk,HHTalkCaptureData pCBTalk,DWORD dwContext /*= 0*/,void *pContext /*= NULL*/);

DLLEXPORT_API int __stdcall HH5PLAYER_TKStart( HANDLE hTalk,WAVEFORMATEX *pInFormat, WAVEFORMATEX *pOutFormat);  
DLLEXPORT_API int __stdcall HH5PLAYER_TKStop(  HANDLE hTalk); 

DLLEXPORT_API int __stdcall HH5PLAYER_TKSendToPCData(HANDLE hTalk, BYTE *pBuffer,int nBufLen);
DLLEXPORT_API int __stdcall HH5PLAYER_TKSetVolume(   HANDLE hTalk, long lVolume);	
DLLEXPORT_API int __stdcall HH5PLAYER_TKGetVolume(   HANDLE hTalk, long *lpVolume);

DLLEXPORT_API int __stdcall HH5PLAYER_TKRelease(HANDLE hTalk);

//================================================================================
//新增函数4: 解码后YUV 数据回调
//================================================================================
typedef int (WINAPI *YUVDataCallBack)(USHORT nPort,	
							     unsigned char *YBuf,
							     unsigned char *UBuf,
							     unsigned char *VBuf,
								 unsigned int  nYStride,
								 unsigned int  nUVStride,
								 unsigned int  nWidth,
								 unsigned int  nHeight,
							     unsigned int  nViFormat 	
								 );

DLLEXPORT_API int __stdcall HH5PLAYER_RegYUVDataCallBack(YUVDataCallBack pYUVDataCallBack, bool nDispImage);

//================================================================================
//新增函数5: 设置源缓冲区阀值和剩余数据小于等于阀值时的回调函数指针
//================================================================================
typedef int (WINAPI *HHVideoBufCallBack)(USHORT nPort, DWORD nFrameNum, void *pContext);	

int __stdcall HH5PLAYER_RegVideoBufCallBack(USHORT nPort, DWORD nThreShold, HHVideoBufCallBack pVideoBufCallBack, void *pContext = NULL);
int __stdcall HH5PLAYER_ResetVideoBufFlag(USHORT nPort);

DWORD __stdcall HH5PLAYER_GetSdkVersion();
DWORD __stdcall HH5PLAYER_GetCaps();
int   __stdcall HH5PLAYER_GetPlayer();
int   __stdcall HH5PLAYER_SetStreamPlayMode(USHORT nPort, DWORD nMode, DWORD nThreShold);
int   __stdcall HH5PLAYER_GetStreamPlayMode(USHORT nPort);

//============================================================================================================================================================================================================================================
//不再支持的函数
//============================================================================================================================================================================================================================================
//================================================================
//在新版中，不再支持的函数 
//           1. 多显卡的支持由内部处理
//           2. 在视频图像上叠加图片、画线等，可以通过新增函数实现
//================================================================
DLLEXPORT_API int __stdcall HH5PLAYER_SetDisplayGUID(char *pGuid);				
DLLEXPORT_API int __stdcall HH5PLAYER_SetDisplayGUIDEx(USHORT nPort, char *pGuid);
DLLEXPORT_API int __stdcall HH5PLAYER_SetDisplayWndEx(USHORT nPort,  unsigned int nFirstScreenWidth);

typedef int (WINAPI *DrawImageCallBack)(USHORT nPort,	
							     HDC hdc,
							     unsigned char *pDispBuf,
								 unsigned int  nStride,
								 unsigned int  nDDrawMode
								 );
DLLEXPORT_API int __stdcall HH5PLAYER_RegDrawImageCallBack(DrawImageCallBack pDrawImageCallBack);



#endif  
