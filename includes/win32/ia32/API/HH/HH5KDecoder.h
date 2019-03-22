/******************************************************************************
* 系统名称：HH5KDecoder
* 文件名称：HH5KDecoder.h
* 版本    ：V5.5.0.0
* 说明	  ：该模块提供音视频的编解码

* 日    期: 2005年3月10日
  最近更新:	
* 其他说明: 无
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
/*********************************  一、宏定义  ******************************/
/*****************************************************************************/

#define HH5KDECODER_ERR_INVALID_PARAMETER  -1
#define HH5KDECODER_SUCCESS					0

#define HH5KDECODER_YUV_422					0x01
#define HH5KDECODER_YUV_420					0x02
#define HH5KDECODER_RGB_024					0x03

/*****************************************************************************/
/********************************  二、函数接口定义  *************************/
/*****************************************************************************/

//------------------------------  1、视频解码  ----------------------------------//
//初始化视频解码
DLLDECEXPORT_API void* WINAPI HHVideo_InitDecoder();
//释放视频解码
DLLDECEXPORT_API int   WINAPI HHVideo_ReleaseDecoder(void* pDecoder);
//选择新的H.264视频解码
DLLDECEXPORT_API int   WINAPI HHVideo_SelectNewH264( void* pDecoder,  BOOL bNewH264 = TRUE);
//取得视频解码信息
DLLDECEXPORT_API int   WINAPI HHVideo_GetVideoInfo(  void* pDecoder,  BYTE* pEncFrame,long lEncFrameSize,HHAV_INFO *pAVInfo,OUT EXT_FRAME_VIDEO *pFrameInfo);
//设置视频解码模式
DLLDECEXPORT_API int   WINAPI HHVideo_SetDecoderMode(void* pDecoder,  int Out_Stride, int Out_Format);
//设置视频解码参数
DLLDECEXPORT_API int   WINAPI HHVideo_SetDecoderParam(void* pDecoder, BOOL bQulity, BOOL bDoDeInterlace, BOOL bTwoField);
//解码一帧视频
DLLDECEXPORT_API int   WINAPI HHVideo_DecodeOneFrame(void* pDecoder,  BYTE* pEncFrame,long lEncFrameSize, BYTE* pDecBuffer,long &lDecBufSize,HHAV_INFO *pAVInfo = NULL);

//------------------------------  2、音频解码  ----------------------------------//
//初始化音频解码
DLLDECEXPORT_API void* WINAPI HHAudio_InitDecoder();
//释放音频解码
DLLDECEXPORT_API int   WINAPI HHAudio_ReleaseDecoder(void* pDecoder);
//取得音频解码信息
DLLDECEXPORT_API int   WINAPI HHAudio_GetAudioInfo(  void* pDecoder,BYTE* pEncBuf,long lEncSize,HHAV_INFO *pAVInfo,OUT EXT_FRAME_AUDIO *pFrameInfo);
//解码一帧音频
DLLDECEXPORT_API int   WINAPI HHAudio_DecodeData(    void* pDecoder,BYTE *pEncBuf,long lEncSize,BYTE* pDecBuf,long &lDecSize,HHAV_INFO *pAVInfo = NULL);

//------------------------------  3、音频编码  ----------------------------------//
//初始化音频编码
DLLDECEXPORT_API void* WINAPI HHAudio_InitEncoder();
//释放音频编码
DLLDECEXPORT_API int   WINAPI HHAudio_ReleaseEncoder(void* pEncoder);
//取得音频编码信息
DLLDECEXPORT_API int   WINAPI HHAudio_GetEncodeInfo( void* pEncoder,UINT nAudioEncodeType,HHAV_INFO *pAVInfo,OUT EXT_FRAME_AUDIO *pFrameInfo);
//编码一帧音频
DLLDECEXPORT_API int   WINAPI HHAudio_EncodeData(    void* pEncoder,BYTE *pDecBuf, long lDecSize,BYTE* pEncBuf,long &lEncSize,IN EXT_FRAME_AUDIO *pFrameInfo);


#endif 
