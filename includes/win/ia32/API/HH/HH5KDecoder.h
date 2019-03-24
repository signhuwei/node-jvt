/******************************************************************************
* ϵͳ���ƣ�HH5KDecoder
* �ļ����ƣ�HH5KDecoder.h
* �汾    ��V5.5.0.0
* ˵��	  ����ģ���ṩ����Ƶ�ı����

* ��    ��: 2005��3��10��
  �������:	
* ����˵��: ��
******************************************************************************/
#ifndef HH5KDecoder_H
#define HH5KDecoder_H

#include "HHAVDefine.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef HHDECODE_INTERFACE
#define DLLDECEXPORT_API __declspec(dllexport)
#else
#define DLLDECEXPORT_API __declspec(dllimport)
#endif

/*****************************************************************************/
/*********************************  һ���궨��  ******************************/
/*****************************************************************************/

#define HH5KDECODER_ERR_INVALID_PARAMETER  -1
#define HH5KDECODER_SUCCESS					0

#define HH5KDECODER_YUV_422					0x01
#define HH5KDECODER_YUV_420					0x02
#define HH5KDECODER_RGB_024					0x03

/*****************************************************************************/
/********************************  ���������ӿڶ���  *************************/
/*****************************************************************************/

//------------------------------  1����Ƶ����  ----------------------------------//
//��ʼ����Ƶ����
DLLDECEXPORT_API void* WINAPI HHVideo_InitDecoder();
//�ͷ���Ƶ����
DLLDECEXPORT_API int   WINAPI HHVideo_ReleaseDecoder(void* pDecoder);
//ѡ���µ�H.264��Ƶ����
DLLDECEXPORT_API int   WINAPI HHVideo_SelectNewH264( void* pDecoder,  BOOL bNewH264 = TRUE);
//ȡ����Ƶ������Ϣ
DLLDECEXPORT_API int   WINAPI HHVideo_GetVideoInfo(  void* pDecoder,  BYTE* pEncFrame,long lEncFrameSize,HHAV_INFO *pAVInfo,OUT EXT_FRAME_VIDEO *pFrameInfo);
//������Ƶ����ģʽ
DLLDECEXPORT_API int   WINAPI HHVideo_SetDecoderMode(void* pDecoder,  int Out_Stride, int Out_Format);
//������Ƶ�������
DLLDECEXPORT_API int   WINAPI HHVideo_SetDecoderParam(void* pDecoder, BOOL bQulity, BOOL bDoDeInterlace, BOOL bTwoField);
//����һ֡��Ƶ
DLLDECEXPORT_API int   WINAPI HHVideo_DecodeOneFrame(void* pDecoder,  BYTE* pEncFrame,long lEncFrameSize, BYTE* pDecBuffer,long &lDecBufSize,HHAV_INFO *pAVInfo = NULL);

//------------------------------  2����Ƶ����  ----------------------------------//
//��ʼ����Ƶ����
DLLDECEXPORT_API void* WINAPI HHAudio_InitDecoder();
//�ͷ���Ƶ����
DLLDECEXPORT_API int   WINAPI HHAudio_ReleaseDecoder(void* pDecoder);
//ȡ����Ƶ������Ϣ
DLLDECEXPORT_API int   WINAPI HHAudio_GetAudioInfo(  void* pDecoder,BYTE* pEncBuf,long lEncSize,HHAV_INFO *pAVInfo,OUT EXT_FRAME_AUDIO *pFrameInfo);
//����һ֡��Ƶ
DLLDECEXPORT_API int   WINAPI HHAudio_DecodeData(    void* pDecoder,BYTE *pEncBuf,long lEncSize,BYTE* pDecBuf,long &lDecSize,HHAV_INFO *pAVInfo = NULL);

//------------------------------  3����Ƶ����  ----------------------------------//
//��ʼ����Ƶ����
DLLDECEXPORT_API void* WINAPI HHAudio_InitEncoder();
//�ͷ���Ƶ����
DLLDECEXPORT_API int   WINAPI HHAudio_ReleaseEncoder(void* pEncoder);
//ȡ����Ƶ������Ϣ
DLLDECEXPORT_API int   WINAPI HHAudio_GetEncodeInfo( void* pEncoder,UINT nAudioEncodeType,HHAV_INFO *pAVInfo,OUT EXT_FRAME_AUDIO *pFrameInfo);
//����һ֡��Ƶ
DLLDECEXPORT_API int   WINAPI HHAudio_EncodeData(    void* pEncoder,BYTE *pDecBuf, long lDecSize,BYTE* pEncBuf,long &lEncSize,IN EXT_FRAME_AUDIO *pFrameInfo);


#endif 
