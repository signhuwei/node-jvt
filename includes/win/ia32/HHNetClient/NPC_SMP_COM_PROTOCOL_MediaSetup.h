/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_SMP_COM_PROTOCOL_MediaSetup.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-11
 * Description   :  流媒体平台通讯媒体建立定义
 *----------------------------------------------------------------------------*/

#ifndef __NPC_SMP_COM_PROTOCOL_MEDIASETUP_H
#define __NPC_SMP_COM_PROTOCOL_MEDIASETUP_H

#include "NPC_TypeDef.h"


//-----------------------------------------------------------------------------------------
//常量定义
#define NPC_D_SMP_COM_MS_SPS_BUFSIZE				64						//SPS参数缓冲区大小
#define NPC_D_SMP_COM_MS_PPS_BUFSIZE				32						//PPS参数缓冲区大小


//-----------------------------------------------------------------------------------------
//RTP/RTCP参数
typedef struct _NPC_S_SMP_COM_MS_RTP_RTCP_PARAM
{
	NPC_CHAR									sSrcIpAddr[NPC_D_FC_IPADDR_BUFSIZE];	//源IP地址
	NPC_USHORT									usSrcRtpPort;							//源RTP端口号
	NPC_USHORT									usSrcRtcpPort;							//源RTCP端口号

	NPC_CHAR									sDestIpAddr[NPC_D_FC_IPADDR_BUFSIZE];	//目的IP地址
	NPC_USHORT									usDestRtpPort;							//目的RTP端口号
	NPC_USHORT									usDestRtcpPort;							//目的RTCP端口号

	NPC_DWORD									dwSsrc;									//同步源ID
	NPC_DWORD									dwStartSeqNo;							//开始序号
	NPC_DWORD									dwStartTimestamp;						//开始时间戳

} NPC_S_SMP_COM_MS_RTP_RTCP_PARAM, *PNPC_S_SMP_COM_MS_RTP_RTCP_PARAM;

//H264参数
typedef struct _NPC_S_SMP_COM_MS_VIDEO_H264_PARAM
{
	NPC_BYTE									sH264SpsBuf[NPC_D_SMP_COM_MS_SPS_BUFSIZE];			//H264的SPS参数缓冲区
	NPC_INT										iH264SpsLen;										//H264的SPS参数长度
	NPC_BYTE									sH264PpsBuf[NPC_D_SMP_COM_MS_PPS_BUFSIZE];			//H264的PPS参数缓冲区
	NPC_INT										iH264PpsLen;										//H264的PPS参数长度

} NPC_S_SMP_COM_MS_VIDEO_H264_PARAM, *PNPC_S_SMP_COM_MS_VIDEO_H264_PARAM;

//AAC参数
typedef struct _NPC_S_SMP_COM_MS_AUDIO_AAC_PARAM
{
	NPC_DWORD									dwProId;					//ProfileId

} NPC_S_SMP_COM_MS_AUDIO_AAC_PARAM, *PNPC_S_SMP_COM_MS_AUDIO_AAC_PARAM;

//视频参数，该结构体后为相应视频编码的参数
typedef struct _NPC_S_SMP_COM_MS_VIDEO_PARAM
{
	NPC_INT										iVideoCodecId;				//视频编码ID
	NPC_INT										iVideoWidth;				//视频宽度
	NPC_INT										iVideoHeight;				//视频高度
	NPC_INT										iVideoBitRate;				//视频码率
	NPC_INT										iVideoFrameRate;			//视频帧率

	NPC_S_SMP_COM_MS_VIDEO_H264_PARAM			tH264Param;					//H264参数

} NPC_S_SMP_COM_MS_VIDEO_PARAM, *PNPC_S_SMP_COM_MS_VIDEO_PARAM;

//音频参数，该结构体后为相应音频编码的参数
typedef struct _NPC_S_SMP_COM_MS_AUDIO_PARAM
{
	NPC_INT										iAudioCodecId;				//音频编码ID
	NPC_INT										iAudioBitRate;				//音频码率
	NPC_INT										iAudioSampleRate;			//音频采样率
	NPC_INT										iAudioChNum;				//音频声道数

	NPC_S_SMP_COM_MS_AUDIO_AAC_PARAM			tAacParam;					//AAC参数

} NPC_S_SMP_COM_MS_AUDIO_PARAM, *PNPC_S_SMP_COM_MS_AUDIO_PARAM;


#endif

