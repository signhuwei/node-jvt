//FileName:FrameAddHead.h
#ifndef  _FRAME_ADD_HEAD_H_
#define _FRAME_ADD_HEAD_H_

#define H264_HEAD_API extern "C" __declspec(dllexport)

#define CALLMETHOD __stdcall
#define CALLBACK __stdcall

#define H264_HEAD_OK           1   /* Successful result */
#define H264_HEAD_ERROR         -1 /*Error result*/
#define H264_HEAD_ILLEGAL_PARAM   -2 /*�������Ϸ�*/

#define  H264_HEAD_I_FRAME 0
#define  H264_HEAD_P_FRAME 1 
#define  H264_HEAD_AUDIO_PACKET 2 

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
} STD_H264_PACKET_INFO;

typedef struct
{
	int FrameType;
	int FrameHeight;
	int FrameWidth;
	int Framelen;
	int FrameRate;
}SDK_FrameInfo;
H264_HEAD_API int CALLMETHOD AddPrivateHead( STD_H264_PACKET_INFO *src, unsigned char *dest, int FrameType, int framelen);


#endif
