#ifndef HH5PLAYERSDK_H
#define HH5PLAYERSDK_H

#define DLLEXPORT_API  extern "C"__declspec(dllexport) 

#include <mmsystem.h>
#include "HHAVDefine.h"

//================================================================
//�궨��
//================================================================
#define HH5PLAYER_MAX_PLAER		128											//���֧��128·����<nPort = 0 ~ 127>

#define HH5PLAYER_MSG_PLAY_END	0xFFFFFFFF									//��Ϣ����<�ļ����Ž���>
																			//��0xFFFFFFFF: ���Ž���: 0 ~ �ļ�ʱ�䳤�ȣ��룩
typedef	HHAV_INFO		HH5KAV_INFO;
typedef	PHHAV_INFO		PHH5KAV_INFO;

#define HH5PLAYER_STREAM_REALTIME	0
#define HH5PLAYER_STREAME_FILE		1

//================================================================
//SDK��ʼ��,�ͷ� -  ����������ʼ��,�ͷ�
//================================================================
DLLEXPORT_API int __stdcall HH5PLAYER_InitSDK(HWND hHwnd);					//��ʼ��SDK��Դ
DLLEXPORT_API int __stdcall HH5PLAYER_ReleaseSDK();							//�ͷ�  SDK��Դ
DLLEXPORT_API int __stdcall HH5PLAYER_InitPlayer(USHORT nPort,HWND hWnd);	//��ʼ��������(�μ�HH5PLAYER_InitPlayer2)
DLLEXPORT_API int __stdcall HH5PLAYER_ReleasePlayer(USHORT nPort);			//�ͷŲ�����

//================================================================
//�ļ�����
//================================================================
DLLEXPORT_API int __stdcall HH5PLAYER_OpenStreamFileM(USHORT nPort,LPCTSTR filelist[], int filenum, DWORD &nTimeLength);
DLLEXPORT_API int __stdcall HH5PLAYER_GetStreamFileInfo(USHORT nPort, DWORD *dwTimeLength, DWORD *dwFileLength, DWORD *dwWidth,DWORD *dwHeight);  //�õ��ļ���Ϣ
DLLEXPORT_API int __stdcall HH5PLAYER_Play(USHORT nPort);                      //����
DLLEXPORT_API int __stdcall HH5PLAYER_FastPlay(USHORT nPort,DWORD nValue);     //���ٲ���  dwValue 1---1000֮�����
DLLEXPORT_API int __stdcall HH5PLAYER_FastPlayBack(USHORT nPort,DWORD nValue); //����
DLLEXPORT_API int __stdcall HH5PLAYER_FrameGO(USHORT nPort);                   //��֡��
DLLEXPORT_API int __stdcall HH5PLAYER_FrameBack(USHORT nPort);                 //��֡��
DLLEXPORT_API int __stdcall HH5PLAYER_Pause(USHORT nPort);                     //��ͣ  
DLLEXPORT_API int __stdcall HH5PLAYER_Resume(USHORT nPort);                    //����
DLLEXPORT_API int __stdcall HH5PLAYER_Stop(USHORT nPort);                      //ֹͣ

DLLEXPORT_API int __stdcall HH5PLAYER_GetPlayPosition(USHORT nPort,DWORD *dwPlayedTime);			//�õ����ŵ�ʱ��
DLLEXPORT_API int __stdcall HH5PLAYER_SetPlayPosition(USHORT nPort,float fOffset);					//���ò���λ��
DLLEXPORT_API int __stdcall HH5PLAYER_SeekToSecond(USHORT nPort,int nSec);							//�ƶ�����ָ�뵽ָ����
DLLEXPORT_API int __stdcall HH5PLAYER_SetPlayLoop(USHORT nPort,bool  bIsLoop);						//ѭ������ 
DLLEXPORT_API int __stdcall HH5PLAYER_RegPlayStatusMsg(USHORT nPort, HWND hWnd, UINT MessageID);	//ע�Ქ��״̬��Ϣ(1.H5PLAYER_MSG_PLAY_END:�ļ����Ž���	2.���Ž���:0 ~ �ļ�ʱ�䳤��<��)

//================================================================
//������
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

//fValue:ÿ֡����ʱ��, ��: 40ms, 33.3ms, bDelayAdjust:�Ƿ����ж�֡ʱ, У׼ʱ��(ע:���ǶԹؼ�֡����,һ��Ҫ��Ϊfalse)
DLLEXPORT_API int __stdcall HH5PLAYER_SetStreamPlaySpeed2(USHORT nPort,float fValue,bool bDelayAdjust = true);

//================================================================
//����
//================================================================
DLLEXPORT_API int __stdcall HH5PLAYER_SetAudio(USHORT nPort,bool bEnabled);         //������Ƶ
DLLEXPORT_API int __stdcall HH5PLAYER_UpDateImage(USHORT nPort);					//ˢ��ͼ��
DLLEXPORT_API int __stdcall HH5PLAYER_UpdateBounds(USHORT nPort);					//ˢ����ʾ���ڱ߽�  
DLLEXPORT_API int __stdcall HH5PLAYER_SetDisplayhWnd(USHORT nPort,HWND hWnd);		//������ʾ����
DLLEXPORT_API int __stdcall HH5PLAYER_SetPartDisplay(USHORT nPort,HWND hPartWnd,RECT *pPartRect);	//�ֲ��Ŵ���ʾ
DLLEXPORT_API int __stdcall HH5PLAYER_CaptureOnePicture(USHORT nPort,void **bmpbuf,int &bmpsize);	//��׽��ǰ��ͼ��

DLLEXPORT_API int __stdcall HH5PLAYER_GetVolume(USHORT nPort, long *lpVolume);		//��������
DLLEXPORT_API int __stdcall HH5PLAYER_SetVolume(USHORT nPort, long lVolume);		//��ȡ����

DLLEXPORT_API int __stdcall HH5PLAYER_SetDecoderQulity(bool bQulity);				//0: ������  1: ������
DLLEXPORT_API int __stdcall HH5PLAYER_SetDecoderParam(bool bZoomIn, bool bDeInterlace, bool bPlayMode = FALSE);		//bZoomIn:		������ʾ
																													//bDeInterlace:	�����о��
																													//bPlayMode		TRUE  ��������	FALSE ʵʱ����
DLLEXPORT_API int __stdcall HH5PLAYER_SetVideoBufferSize(int nFrameNum = 15);		//������������ʱ�������֡��(1 ~ 60)

DLLEXPORT_API int __stdcall HH5PLAYER_ClearAllBuffer(USHORT nPort);										
DLLEXPORT_API int __stdcall HH5PLAYER_ClearVideoBuffer(USHORT nPort);		
DLLEXPORT_API int __stdcall HH5PLAYER_ClearAudioBuffer(USHORT nPort);		
DLLEXPORT_API int __stdcall HH5PLAYER_ClearImage(USHORT nPort, DWORD dwColor = 0);	//���DirctX����

//================================================================
//��Ƶ�����
//================================================================
DLLEXPORT_API int   __stdcall HH5PLAYER_AudioEncodeData(unsigned short *BuffIn,   int InNum, BYTE *BuffOut);
DLLEXPORT_API int   __stdcall HH5PLAYER_AudioDecodeData(BYTE *BuffIn,  int InNum, unsigned short  *BuffOut);

/*Ĭ��G.726 16kbps*/
DLLEXPORT_API int   __stdcall HH5PLAYER_G726AEncodeData(unsigned short *BuffIn,   int InNum, BYTE *BuffOut);
DLLEXPORT_API int   __stdcall HH5PLAYER_G726ADecodeData(BYTE *BuffIn,  int InNum, unsigned short  *BuffOut);

#define		HH5PLAYER_G722AEncodeData	HH5PLAYER_AudioEncodeData
#define		HH5PLAYER_G722ADecodeData	HH5PLAYER_AudioDecodeData

//================================================================================
//��������1: ��Ƶ�����
//================================================================================
//��HH98ϵ�к�HH58ϵ���豸�ṩ�Ľӿڣ����Ա����G.711 G.726 ADPCM��ʽ
DLLEXPORT_API int   __stdcall HH5PLAYER_AudioEncodeDataEx(unsigned short *BuffIn,   int InNum, BYTE *BuffOut, UINT nEncodeType, UINT nBitrate);
DLLEXPORT_API int   __stdcall HH5PLAYER_AudioDecodeDataEx(BYTE *BuffIn,  int InNum, unsigned short  *BuffOut, UINT nEncodeType, UINT nBitrate);

//================================================================================
//��������2: ��Ƶ���뼰��Ƶ����
//================================================================================
DLLEXPORT_API int   __stdcall HH5PLAYER_SelectH264(USHORT nPort,UINT nVersion);				//nVersion 1:old(123),2:new(125)
DLLEXPORT_API int   __stdcall HH5PLAYER_WaitForVerticalBlank(bool bWait = false);			//���Ѻ۹��ܿ��� false: ��  true: ��

//ע: ��Ҫ������Ƶͼ���ϵ���ͼƬ�����ߵ�ʱ���������º�����ʼ��������������bSupportDraw��Ϊtrue(�ڲ��Ŵ�����֧���ⲿ���ڲ�HDC)
DLLEXPORT_API int   __stdcall HH5PLAYER_InitPlayer2(USHORT nPort,HWND hWnd,bool bSupportDraw = false);
DLLEXPORT_API int   __stdcall HH5PLAYER_DrawImage( USHORT nPort,int x,int y,unsigned char *pBmpImage,int nSize);
DLLEXPORT_API int   __stdcall HH5PLAYER_DrawText(  USHORT nPort,int x,int y,char *pszText,LOGFONT ft,COLORREF crText,COLORREF crBack = -1/*crBack -1: ͸��*/);
DLLEXPORT_API int   __stdcall HH5PLAYER_SetDrawPen(USHORT nPort,int nPenStyle,int nWidth, COLORREF crColor);
DLLEXPORT_API int   __stdcall HH5PLAYER_DrawLine(  USHORT nPort,int x1,int y1,int x2,int y2);
DLLEXPORT_API int   __stdcall HH5PLAYER_DrawRect(  USHORT nPort,int x1,int y1,int x2,int y2);
DLLEXPORT_API int   __stdcall HH5PLAYER_ClearDraw( USHORT nPort,int nType);					//nType: 0 all, 1 image, 2 text, 3 line, rect

typedef int (WINAPI *HHCBOnDraw)(USHORT nPort, HDC hdc, int nWidth, int nHeight, void *pContext);	//֧���ⲿ����HDC
DLLEXPORT_API int   __stdcall HH5PLAYER_RegCBOnDraw(USHORT nPort, HHCBOnDraw pCBOnDraw, void *pContext = NULL);

//================================================================================
//��������3: �Խ�
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
//��������4: �����YUV ���ݻص�
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
//��������5: ����Դ��������ֵ��ʣ������С�ڵ��ڷ�ֵʱ�Ļص�����ָ��
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
//����֧�ֵĺ���
//============================================================================================================================================================================================================================================
//================================================================
//���°��У�����֧�ֵĺ��� 
//           1. ���Կ���֧�����ڲ�����
//           2. ����Ƶͼ���ϵ���ͼƬ�����ߵȣ�����ͨ����������ʵ��
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
