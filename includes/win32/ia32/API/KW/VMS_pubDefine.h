
#ifndef _VMS_PUBDEFINE_H_
#define _VMS_PUBDEFINE_H_



typedef enum 
{
	channel_ok=0,
	channel_invalid,
	session_invalid,
	thread_get_failed,
	login_failed,
	not_encoder,
	start_failed,
	not_support_mainstream,
	not_support_substream,
	normal_user,
	manager,
	superuser,
} Preview_Response_RetCode;

/* Intercom Info */
typedef enum
{
	PT_PCMU = 0,
	PT_1016 = 1,
	PT_G721 = 2,
	PT_GSM = 3,
	PT_G723 = 4,
	PT_DVI4_8K = 5,
	PT_DVI4_16K = 6,
	PT_LPC = 7,
	PT_PCMA = 8,
	PT_G722 = 9,
	PT_S16BE_STEREO,
	PT_S16BE_MONO = 11,
	PT_QCELP = 12,
	PT_CN = 13,
	PT_MPEGAUDIO = 14,
	PT_G728 = 15,
	PT_DVI4_3 = 16,
	PT_DVI4_4 = 17,
	PT_G729 = 18,
	PT_G711A = 19,
	PT_G711U = 20,
	PT_G726 = 21,
	PT_G729A = 22,
	PT_LPCM = 23,
	PT_CelB = 25,
	PT_JPEG = 26,
	PT_CUSM = 27,
	PT_NV = 28,
	PT_PICW = 29,
	PT_CPV = 30,
	PT_H261 = 31,
	PT_MPEGVIDEO = 32,
	PT_MPEG2TS = 33,
	PT_H263 = 34,
	PT_SPEG = 35,
	PT_MPEG2VIDEO = 36,
	PT_AAC = 37,
	PT_WMA9STD = 38,
	PT_HEAAC = 39,
	PT_PCM_VOICE = 40,
	PT_PCM_AUDIO = 41,
	PT_AACLC = 42,
	PT_MP3 = 43,
	PT_ADPCMA = 49,
	PT_AEC = 50,
	PT_X_LD = 95,
	PT_H264 = 96,
	PT_D_GSM_HR = 200,
	PT_D_GSM_EFR = 201,
	PT_D_L8 = 202,
	PT_D_RED = 203,
	PT_D_VDVI = 204,
	PT_D_BT656 = 220,
	PT_D_H263_1998 = 221,
	PT_D_MP1S = 222,
	PT_D_MP2P = 223,
	PT_D_BMPEG = 224,
	PT_MP4VIDEO = 230,
	PT_MP4AUDIO = 237,
	PT_VC1 = 238,
	PT_JVC_ASF = 255,
	PT_D_AVI = 256,
	PT_MAX = 257,		
	PT_AMR = 1001,
	PT_MJPEG = 1002,
}PAYLOAD_TYPE_E;

typedef enum hiAUDIO_SAMPLE_RATE_E 
{ 
    AUDIO_SAMPLE_RATE_8000   = 8000,    /* 8K sample rate*/
	AUDIO_SAMPLE_RATE_11025  = 11025,   /* 11.025K sample rate*/
	AUDIO_SAMPLE_RATE_16000  = 16000,   /* 16K sample rate*/
	AUDIO_SAMPLE_RATE_22050	 = 22050,   /* 22.050K sample rate*/
	AUDIO_SAMPLE_RATE_24000  = 24000,   /* 24K sample rate*/
	AUDIO_SAMPLE_RATE_32000  = 32000,   /* 32K sample rate*/
	AUDIO_SAMPLE_RATE_44100  = 44100,   /* 44.1K sample rate*/
	AUDIO_SAMPLE_RATE_48000  = 48000,   /* 48K sample rate*/
	AUDIO_SAMPLE_RATE_BUTT,
}AUDIO_SAMPLE_RATE_E; 

typedef enum hiAUDIO_BIT_WIDTH_E
{
    AUDIO_BIT_WIDTH_8   = 0,   /* 8bit width */
	AUDIO_BIT_WIDTH_16  = 1,   /* 16bit width*/
	AUDIO_BIT_WIDTH_32  = 2,   /* 32bit width*/
	AUDIO_BIT_WIDTH_BUTT,
}AUDIO_BIT_WIDTH_E;

typedef enum hiAIO_SOUND_MODE_E
{
    AUDIO_SOUND_MODE_MOMO   =0,/*mono*/
	AUDIO_SOUND_MODE_STEREO =1,/*stereo*/
	AUDIO_SOUND_MODE_BUTT    
}AUDIO_SOUND_MODE_E;

typedef struct hiVMS_Talk_S
{
    int Chn;
    int bRun;
    PAYLOAD_TYPE_E enType; 
    AUDIO_SAMPLE_RATE_E enSamplerate;   /*sample rate*/
    AUDIO_BIT_WIDTH_E   enBitwidth;     /*bit width*/
    AUDIO_SOUND_MODE_E  enSoundmode;    /*mono or stereo*/
}VMS_Talk_S;

/*
channel 为按位设置需要重采I帧的通道号，从低位开始，最低位为第一个通道，如第一个和第三个通道要重采I帧，
则channel 应为0x05 (0b00000101);
streammode 为主/子码流选择，0为主码流需重采，1为子码流重采。
主机回送响应0,-1，0为成功，-1为失败，PC机是否处理响应由PC自行决定。
*/
typedef struct
{
	int channel;
	int streammode;
}enciqr_vms;

typedef int (__stdcall* AudioEncodeCallBack) (void* hDecoder, unsigned char *pBuf,
											 unsigned int DataLen, unsigned __int64 Pts);
#endif