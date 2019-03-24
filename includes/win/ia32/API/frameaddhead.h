//FileName:FrameAddHead.h
#ifndef  _FRAME_ADD_HEAD_H_
#define _FRAME_ADD_HEAD_H_

#define H264_HEAD_API extern "C" __declspec(dllexport)

#define CALLMETHOD __stdcall
#define CALLBACK __stdcall

#define H264_HEAD_OK           1   /* Successful result */
#define H264_HEAD_ERROR         -1 /*Error result*/
#define H264_HEAD_ILLEGAL_PARAM   -2 /*差数不合法*/

#define  H264_HEAD_I_FRAME 0
#define  H264_HEAD_P_FRAME 1 
#define  H264_HEAD_AUDIO_PACKET 2 

typedef struct
{
	int		nPacketType;				// 包类型,MEDIA_DATA_TYPE
	char*	pPacketBuffer;				// 缓存区地址
	unsigned int	dwPacketSize;				// 包的大小

	// 绝对时标
	int		nYear;						// 时标:年		
	int		nMonth;						// 时标:月
	int		nDay;						// 时标:日
	int		nHour;						// 时标:时
	int		nMinute;					// 时标:分
	int		nSecond;					// 时标:秒
	unsigned int 	dwTimeStamp;					// 相对时标低位，单位为毫秒	
	unsigned int   dwFrameNum;             //帧序号
	unsigned int   dwFrameRate;            //帧率
	unsigned short uWidth;              //图像宽度
	unsigned short uHeight;             //图像高度
	unsigned int   nAudioEncodeType;          //音频编码类型IMA	 9 PCM8_VWIS 12 MS_ADPCM 13 G711A 14
	unsigned int   nBitsPerSample;			//音频采样位深
	unsigned int   nSamplesPerSecond;       // 音频采样率
	unsigned int       Reserved[6];            //保留
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
