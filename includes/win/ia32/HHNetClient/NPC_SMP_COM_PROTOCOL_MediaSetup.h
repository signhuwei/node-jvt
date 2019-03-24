/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_SMP_COM_PROTOCOL_MediaSetup.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-11
 * Description   :  ��ý��ƽ̨ͨѶý�彨������
 *----------------------------------------------------------------------------*/

#ifndef __NPC_SMP_COM_PROTOCOL_MEDIASETUP_H
#define __NPC_SMP_COM_PROTOCOL_MEDIASETUP_H

#include "NPC_TypeDef.h"


//-----------------------------------------------------------------------------------------
//��������
#define NPC_D_SMP_COM_MS_SPS_BUFSIZE				64						//SPS������������С
#define NPC_D_SMP_COM_MS_PPS_BUFSIZE				32						//PPS������������С


//-----------------------------------------------------------------------------------------
//RTP/RTCP����
typedef struct _NPC_S_SMP_COM_MS_RTP_RTCP_PARAM
{
	NPC_CHAR									sSrcIpAddr[NPC_D_FC_IPADDR_BUFSIZE];	//ԴIP��ַ
	NPC_USHORT									usSrcRtpPort;							//ԴRTP�˿ں�
	NPC_USHORT									usSrcRtcpPort;							//ԴRTCP�˿ں�

	NPC_CHAR									sDestIpAddr[NPC_D_FC_IPADDR_BUFSIZE];	//Ŀ��IP��ַ
	NPC_USHORT									usDestRtpPort;							//Ŀ��RTP�˿ں�
	NPC_USHORT									usDestRtcpPort;							//Ŀ��RTCP�˿ں�

	NPC_DWORD									dwSsrc;									//ͬ��ԴID
	NPC_DWORD									dwStartSeqNo;							//��ʼ���
	NPC_DWORD									dwStartTimestamp;						//��ʼʱ���

} NPC_S_SMP_COM_MS_RTP_RTCP_PARAM, *PNPC_S_SMP_COM_MS_RTP_RTCP_PARAM;

//H264����
typedef struct _NPC_S_SMP_COM_MS_VIDEO_H264_PARAM
{
	NPC_BYTE									sH264SpsBuf[NPC_D_SMP_COM_MS_SPS_BUFSIZE];			//H264��SPS����������
	NPC_INT										iH264SpsLen;										//H264��SPS��������
	NPC_BYTE									sH264PpsBuf[NPC_D_SMP_COM_MS_PPS_BUFSIZE];			//H264��PPS����������
	NPC_INT										iH264PpsLen;										//H264��PPS��������

} NPC_S_SMP_COM_MS_VIDEO_H264_PARAM, *PNPC_S_SMP_COM_MS_VIDEO_H264_PARAM;

//AAC����
typedef struct _NPC_S_SMP_COM_MS_AUDIO_AAC_PARAM
{
	NPC_DWORD									dwProId;					//ProfileId

} NPC_S_SMP_COM_MS_AUDIO_AAC_PARAM, *PNPC_S_SMP_COM_MS_AUDIO_AAC_PARAM;

//��Ƶ�������ýṹ���Ϊ��Ӧ��Ƶ����Ĳ���
typedef struct _NPC_S_SMP_COM_MS_VIDEO_PARAM
{
	NPC_INT										iVideoCodecId;				//��Ƶ����ID
	NPC_INT										iVideoWidth;				//��Ƶ���
	NPC_INT										iVideoHeight;				//��Ƶ�߶�
	NPC_INT										iVideoBitRate;				//��Ƶ����
	NPC_INT										iVideoFrameRate;			//��Ƶ֡��

	NPC_S_SMP_COM_MS_VIDEO_H264_PARAM			tH264Param;					//H264����

} NPC_S_SMP_COM_MS_VIDEO_PARAM, *PNPC_S_SMP_COM_MS_VIDEO_PARAM;

//��Ƶ�������ýṹ���Ϊ��Ӧ��Ƶ����Ĳ���
typedef struct _NPC_S_SMP_COM_MS_AUDIO_PARAM
{
	NPC_INT										iAudioCodecId;				//��Ƶ����ID
	NPC_INT										iAudioBitRate;				//��Ƶ����
	NPC_INT										iAudioSampleRate;			//��Ƶ������
	NPC_INT										iAudioChNum;				//��Ƶ������

	NPC_S_SMP_COM_MS_AUDIO_AAC_PARAM			tAacParam;					//AAC����

} NPC_S_SMP_COM_MS_AUDIO_PARAM, *PNPC_S_SMP_COM_MS_AUDIO_PARAM;


#endif

