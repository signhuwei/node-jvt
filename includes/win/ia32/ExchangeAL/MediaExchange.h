//
//  "$Id: MediaExchange.h 16444 2015-06-26 10:05:52Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:			�����������ת��
//

#ifndef __EXCHANGE_AL_MEDIA_EXCHANGE_H__
#define __EXCHANGE_AL_MEDIA_EXCHANGE_H__

#include "Exchange.h"
#include "CommExchange.h"
#include "Types/Types.h"
#include "Types/Defs.h"
#include "Infra/Time.h"
#include "PAL/ExDec.h"
#include <Windows.h>

/// �������õ�����
enum EncodeTypeByRecord
{
	ENCODE_TYPE_TIM = 0,
	ENCODE_TYPE_MTD = 1,
	ENCODE_TYPE_ALM = 2,
	ENCODE_TYPE_NUM = 3,
};

/// ������������ģʽ����
enum CaptureBitrateControlType 
{
	CAPTURE_BITRATE_CBR,			///< �̶�������
	CAPTURE_BITRATE_VBR,			///< �ɱ�������
	CAPTURE_BITRATE_MBR,			///< ���������
	CAPTURE_BITRATE_NR				///< ö�ٵ���������ģʽ��Ŀ��
};

/// ����ֱ�������
enum CaptureImageSize 
{
	CAPTURE_IMAGE_SIZE_D1,			///< 704*576(PAL)	704*480(NTSC)
	CAPTURE_IMAGE_SIZE_HD1,			///< 704*288(PAL)	704*240(NTSC)
	CAPTURE_IMAGE_SIZE_BCIF,		///< 352*576(PAL)	352*480(NTSC)
	CAPTURE_IMAGE_SIZE_CIF,			///< 352*288(PAL)	352*240(NTSC)
	CAPTURE_IMAGE_SIZE_QCIF,		///< 176*144(PAL)	176*120(NTSC)
	CAPTURE_IMAGE_SIZE_VGA,			///< 640*480(PAL)	640*480(NTSC)
	CAPTURE_IMAGE_SIZE_QVGA,		///< 320*240(PAL)	320*240(NTSC)
	CAPTURE_IMAGE_SIZE_SVCD,		///< 480*480(PAL)	480*480(NTSC)
	CAPTURE_IMAGE_SIZE_QQVGA,		///< 160*128(PAL)	160*128(NTSC)
	CAPTURE_IMAGE_SIZE_NR = 9,      ///< ö�ٵ�ͼ�δ�С�������Ŀ��
	CAPTURE_IMAGE_SIZE_ND1 = 9,     ///< 240*192
	CAPTURE_IMAGE_SIZE_650TVL,      ///< 926*576
	CAPTURE_IMAGE_SIZE_720P,        ///< 1280*720
	CAPTURE_IMAGE_SIZE_1_3M,        ///< 1280*960
	CAPTURE_IMAGE_SIZE_UXGA ,       ///< 1600*1200
	CAPTURE_IMAGE_SIZE_1080P,       ///< 1920*1080
	CAPTURE_IMAGE_SIZE_WUXGA,       ///< 1920*1200
	CAPTURE_IMAGE_SIZE_2_5M,        ///< 1872*1408
	CAPTURE_IMAGE_SIZE_3M,          ///< 2048*1536
	CAPTURE_IMAGE_SIZE_5M,          ///< 3744*1408
	CAPTURE_IMAGE_SIZE_EXT_NR = 19,
	CAPTURE_IMAGE_SIZE_1080N = 19,     	///< 960*1080
	CAPTURE_IMAGE_SIZE_4M,        		///< 2592*1520
	CAPTURE_IMAGE_SIZE_6M,				///< 3072��2048
	CAPTURE_IMAGE_SIZE_8M,				///< 3264��2448
	CAPTURE_IMAGE_SIZE_12M,				///< 4000*3000
	CAPTURE_IMAGE_SIZE_4K,				///< 4096 * 2160/3840*2160
	CAPTURE_IMAGE_SIZE_EXT_V2_NR =25,
	CAPTURE_IMAGE_SIZE_720N = 25,  		//  640*720
	CAPTURE_IMAGE_SIZE_WSVGA,			///< 1024*576
	CAPTURE_IMAGE_SIZE_RES2,      		// 0*0
	CAPTURE_IMAGE_SIZE_RES3,      		// 0*0
	CAPTURE_IMAGE_SIZE_RES4,      		// 0*0
	CAPTURE_IMAGE_SIZE_RES5,      		// 0*0
	CAPTURE_IMAGE_SIZE_RES6,      		// 0*0
	CAPTURE_IMAGE_SIZE_EXT_V3_NR,
};


/// ����ѹ����ʽ����
enum CaptureCompressType 
{
	CAPTURE_COMPRESS_DIVX_MPEG4,	///< DIVX MPEG4��
	CAPTURE_COMPRESS_MS_MPEG4,		///< MS MPEG4��
	CAPTURE_COMPRESS_MPEG2,			///< MPEG2��
	CAPTURE_COMPRESS_MPEG1,			///< MPEG1��
	CAPTURE_COMPRESS_H263,			///< H.263
	CAPTURE_COMPRESS_MJPG,			///< MJPG
	CAPTURE_COMPRESS_FCC_MPEG4,		///< FCC MPEG4
	CAPTURE_COMPRESS_H264,			///< H.264
	CAPTURE_COMPRESS_H265,			///< H.265
	CAPTURE_COMPRESS_H265_S,		///< H.265+  //add by zjh 2017/08/28
	CAPTURE_COMPRESS_NR				///< ö�ٵ�ѹ����׼��Ŀ��
};

/// ����ͨ������
enum CaptureChannelTypes 
{
	CAPTURE_CHN_MAIN = 0,		///< ��ͨ��	��	������1 
	CAPTURE_CHN_2END = 1,		///< ��ͨ��	��	��������2 
	CAPTURE_CHN_3IRD = 2,		///< ��ͨ��	��	��������3 
	CAPTURE_CHN_4RTH = 3,		///< ��ͨ��	��	��������4 
	CAPTURE_CHN_JPEG = 4,		///< ��ͨ��	��	��JPEGץͼ 
	CAPTURE_CHN_NR,
};

/// ����ѡ��
enum CaptureImageQuality
{
	CAPTURE_IMG_QUALITY_WOREST = 1,		///< ���
	CAPTURE_IMG_QUALITY_WORSE = 2,		///< �ϲ�
	CAPTURE_IMG_QUALITY_GENERAL = 3,	///< һ��
	CAPTURE_IMG_QUALITY_GOOD = 4,		///< ��
	CAPTURE_IMG_QUALITY_BETTER = 5,		///< �Ϻ�
	CAPTURE_IMG_QUALITY_BEST = 6,		///< �ܺ�
	CAPTURE_IMG_QUALITY_NR = 7,
};

/// ��ϱ���ģʽ
enum CombineEncodeMode
{
	COMBINE_ENCODE_MULTIREPLAY = 1,		///< ��·�ط�
	COMBINE_ENCODE_NARROWBAND = 2,		///< խ������
	COMBINE_ENCODE_NR = 3,
};

//���ֱ����ʽ
enum WordEncode
{
	WORD_ENCODE_GB2312,  //���ֱ���GB2312
	WORD_ENCODE_UNICODE, //����� Unicode
	WORD_ENCODE_UTF8,    //UTF-8
};


/// ��Ƶ��ʽ
struct VIDEO_FORMAT
{
	int		iCompression;			//  ѹ��ģʽ 	
	int		iResolution;			//  �ֱ��� ����ö��capture_size_t	
	int		iBitRateControl;		//  �������� ����ö��capture_brc_t
	int		iQuality;				//  �����Ļ��� ����1-6		
	int		nFPS;					//  ֡��ֵ��NTSC/PAL������,������ʾ����һ֡		
	int		nBitRate;				//  0-4096k,���б���Ҫ�ɿͻ��˱��棬�豸ֻ����ʵ�ʵ�����ֵ�������±ꡣ
	int		iGOP;					//  ��������I֮֡��ļ��ʱ�䣬2-12 
};

/// ��Ƶ��ʽ
struct  AUDIO_FORMAT
{
	int		nBitRate;				//  ����kbps	
	int		nFrequency;				//  ����Ƶ��	
	int		nMaxVolume;				//  ���������ֵ
};

/// ý���ʽ
struct MEDIA_FORMAT
{
	VIDEO_FORMAT vfFormat;			//  ��Ƶ��ʽ���� 			
	AUDIO_FORMAT afFormat;			//  ��Ƶ��ʽ���� 
	bool	bVideoEnable;			//  ������Ƶ���� 
	bool	bAudioEnable;			//  ������Ƶ���� 	
};

/// ��������
struct CONFIG_ENCODE
{
	MEDIA_FORMAT dstMainFmt[ENCODE_TYPE_NUM];		//  ��������ʽ 	
	MEDIA_FORMAT dstExtraFmt[MAX_EXTRA_STREAM_TYPE];	//  ��������ʽ 
	MEDIA_FORMAT dstSnapFmt[ENCODE_TYPE_NUM];		//  ץͼ��ʽ 
};

/// ȫͨ����������
struct EncodeConfigAll
{
	CONFIG_ENCODE vEncodeConfigAll[N_SYS_CH];
};

// �򻯰汾��������
/// ý���ʽ
struct MEDIA_FORMAT_SIMPLIIFY
{
	VIDEO_FORMAT vfFormat;			//  ��Ƶ��ʽ���� 			
	bool	bVideoEnable;			//  ������Ƶ���� 
	bool	bAudioEnable;			//  ������Ƶ���� 	
};

/// ��������
struct CONFIG_ENCODE_SIMPLIIFY
{
	MEDIA_FORMAT dstMainFmt;		//  ��������ʽ 	
	MEDIA_FORMAT dstExtraFmt;	//  ��������ʽ 
};

/// ȫͨ����������
struct EncodeConfigAll_SIMPLIIFY
{
	std::vector<CONFIG_ENCODE_SIMPLIIFY> vEncodeConfigAll;//sizeof(CONFIG_ENCODE_SIMPLIIFY) == 88
};

//by zjh 20170802
/// ȫͨ����������
struct EncodeConfigAll_SIMPLIIFY_Expand
{
	CONFIG_ENCODE_SIMPLIIFY vEncodeConfigAll[N_SYS_CH];
};



/// ��ϱ���ͨ������
struct CombEncodeConfigAll
{
	CONFIG_ENCODE vEncodeConfigAll[N_SYS_COMB_CH];
};

/// ��ϱ���ģʽ
struct CombEncodeParam
{
	int iEncodeMode;	 //��CombineEncodeMode
};

struct CombEncodeModeAll
{
	CombEncodeParam vEncodeParam[N_SYS_COMB_CH];
};

/// ��Ƶ����ṹ
struct  VIDEO_WIDGET
{
	RGBA32 rgbaFrontground;		///< �����ǰ��MakeRGB����͸����	
	RGBA32 rgbaBackground;		///< ����ĺ�MakeRGB����͸����	
	RECT/*Rect*/	rcRelativePos;		///< ����߾��������ı���*8191
	bool	bShowInPreview;		///< Ԥ������	
	bool	bShowInEncode;		///< �������
};

/// ��Ƶ�������
struct CONFIG_VIDEOWIDGET
{
	VIDEO_WIDGET	dstCovers[MAX_COVER_COUNT];
	VIDEO_WIDGET	ChannelTitle;
	VIDEO_WIDGET	TimeTitle;
	struct 
	{
		char strName[CHANNEL_NAME_MAX_LEN];
		int64 iSerialNo;	
	} ChannelName;					/// ͨ������
	int				iCoverNum;		/// ��ǰ��ͨ���м������ӵ�����
};

/// ����ͨ�����Ʊ���
struct ChannelNameConfigAll
{
	char channelTitle[N_SYS_CH][CHANNEL_NAME_MAX_LEN];
};

/// ��Ƶ���
struct VideoWidgetConfigAll
{
	CONFIG_VIDEOWIDGET vVideoWidegetConfigAll[N_SYS_CH];
};


//����������Ϣ��ʾλ����״̬����
struct OSDWidgetConfig
{
	VIDEO_WIDGET alarmInfo; //������ʾ��Ϣ
};


//����ͨ����OSD��Ϣ��ʾλ����״̬����
struct OSDWidgetConfigAll
{
	OSDWidgetConfig vOSDWidgetConfigAll[N_SYS_CH];
};


//��Ļ��ʾ��Ϣ
struct OSDInfoConfig
{
	VIDEO_WIDGET OSDInfoWidget;
	char ppInfo[MAX_LINE_PER_OSD_AREA][CHANNEL_NAME_MAX_LEN];
};

//����ͨ������Ļ��ʾ��Ϣ
struct OSDInfoConfigAll
{
	OSDInfoConfig   vOSDInfoAll[N_SYS_CH];
	int strEnc;//�����ʽ,Ĭ��ΪUTF-8,�����κδ�����Ҫ���ڿͻ���������ö�ٲμ�WordEncode
};

#define N_COLOR_SECTION 2

//! ��Ƶ��ɫ�ṹ
struct VIDEOCOLOR_PARAM
{
	int	nBrightness;		///< ����	0-100
	int	nContrast;			///< �Աȶ�	0-100
	int	nSaturation;		///< ���Ͷ�	0-100
	int	nHue;				///< ɫ��	0-100
	int	mGain;				///< ����	0-100 �ڣ�λ��1��ʾ�Զ�����		
	int	mWhitebalance;		///< �Զ��׵�ƽ���ƣ�bit7��λ��ʾ�����Զ�����.0x0,0x1,0x2�ֱ�����,��,�ߵȼ�
	int nAcutance;          ///< ���   0-15
}; 

///< ��Ƶ��ɫ����
struct VIDEOCOLOR
{
	TimeSection			tsTimeSection;		/// ʱ���
	VIDEOCOLOR_PARAM	dstColor;			/// ��ɫ����
	int					iEnable;
};

struct CONFIG_VIDEOCOLOR
{
	VIDEOCOLOR dstVideoColor[N_COLOR_SECTION];
};

struct VideoColorConfigAll
{
	CONFIG_VIDEOCOLOR vVideoColorAll[N_SYS_CH];
};

//�����Ӷ���
//�ͻ�������Ƶ��ɫ�ṹ
typedef struct VIDEOCOLOR_PARAM_EX
{
	int		BrightnessRef;		///< ����ref1��ȡֵ0-100��
	int		ContrastRef;		///< �Աȶ�ref1��ȡֵ0-100��
	int		ContrastThRef;		///< �Աȶȷ�ֵref1��ȡֵ0-100��
	int		ContrastSlopeRef;		///< �Աȶ�б��ref1��ȡֵ0-100��
	int		DarkBlfRef;
	int		DarkNfRef;
	int		DarkEcPthRef;
	int		DarkEcMthRef;
	int		DarkDcRef;
	int		CbGain;	//high low middle
	int		CrGain;	//higg low middle
	int		reserved;	//����
}VIDEOCOLOR_PARAM_EX;

typedef struct VIDEOCOLOR_PARAM_CUSTOM
{
	VIDEOCOLOR_PARAM_EX	VideoColor[3];
	int		Saturation;		///< ���Ͷȣ�ȡֵ0-100��
	int		Gain;			///< ���棬ȡֵ0-100��bit7��λ��ʾ�Զ����棬����λ�����ԡ�
	int		Acutance;		///< ��ȣ�ȡֵ0-100
	int		AeWight;		//���ⲹ��
}VideoColorConfigCustom;

/// ��Ѳ����
enum TourTypes
{
	TOUR_TYPES_MONITOR,		///< ������Ѳ
	TOUR_TYPES_ALARM,		///< ������Ѳ
	TOUR_TYPES_MONTION,		///< ������Ѳ
	TOUR_TYPES_NR,
};

///<��Ѳ����
struct TourConfig
{
	bool bEnable;	///< ������Ѳʹ��	
	int iInterval;	///< ��Ѳʱ����	[5,120]
	int iType;		///< ��Ѳ����
	uint iMask[N_SPLIT];	///< ��Ѳ����, һά����[����ָ�����]
	bool bReturn;     ///< �澯�������Ƿ�ָ���ԭ���Ļ���ָ�ģʽ
};

/// ����ͨ������Ѳ����
struct TourConfigAll
{
	TourConfig vTourConfigAll[TOUR_TYPES_NR];
};


#define MAX_VOCOLOR_TYPE 2

///<VO��ʾ����
struct VOCOLOR
{
	int	DBrightness;		///< ����	0-100
	int	DContrast;			///< �Աȶ�	0-100
	int	DSaturation;		///< ���Ͷ�	0-100
	int	DHue;				///< ɫ��	0-100
	int resv[3];			///����
};

struct VoColorAdjustConfigAll
{
	VOCOLOR VVoColorAdjustConfigAll[MAX_VOCOLOR_TYPE];
};

///< TV��������
struct TVAdjustConfig
{
	/*Rect*/RECT blackMargin;	///< �ڱߵ�������
	/*Rect*/RECT rctMargin;		///<TV��С���ʣ�������ȡֵ��ͬ	[0,100]
	int iBrightness;	///< ����	[0,100]
	int iContrast;		///< �Աȶ�[0,100]
	int iAntiDither;	///< ȥ����[0,100]
};

///< �ط�����
struct PlayBackConfig
{
	int iChannels;			///< �طŻ�����	[0, 16]
	int iVolume[N_SYS_CH];	///< �ط���Ƶ,һά����[ͨ��]
	int iSearchMask;		///< ��ѯ����
	bool bContinue;			///< �Ƿ���������
	int iPlayMode;			///<�ط�ģʽ��ȡֵ��0��ʼ��0��ʾѡ����������߲˵����ĵ�һ��
};

#define SPLITTYPES 6


/// ��Ƶ��������
enum AudioEncodeTypes
{
	AUDIO_ENCODE_NONE = 0,
	AUDIO_ENCODE_G729_8KBIT,
	AUDIO_ENCODE_G726_16KBIT,
	AUDIO_ENCODE_G726_24KBIT,
	AUDIO_ENCODE_G726_32KBIT,
	AUDIO_ENCODE_G726_40KBIT,
	AUDIO_ENCODE_PCM_8TO16BIT,
	AUDIO_ENCODE_PCM_ALAW,
	AUDIO_ENCODE_PCM_ULAW,
	AUDIO_ENCODE_ADPCM8K16BIT,
	AUDIO_ENCODE_ADPCM16K16BIT,
	AUDIO_ENCODE_G711_ALAW,
	AUDIO_ENCODE_MPEG2_LAYER1,
	AUDIO_ENCODE_AMR8K16BIT,
	AUDIO_ENCODE_G711_ULAW,
	AUDIO_ENCODE_IMA_ADPCM_8K16BIT,
	AUDIO_ENCODE_TYPES_NR,
};

/// ��Ƶ�����ʽ�������Խ���
struct AudioInFormatConfig
{
	int iBitRate;	   ///< ������С��kbpsΪ��λ������192kbps��128kbps
	int iSampleRate;   ///< �����ʣ�HzΪ��λ������44100Hz
	int iSampleBit;    ///< ������λ��
	int iEncodeType;   ///< ���뷽ʽ������AudioEncodeTypes����
};

/// �����Խ���ʽ
struct AudioInFormatConfigAll
{
	AudioInFormatConfig vAudioInFormatConfig[AUDIO_ENCODE_TYPES_NR];
};

void AudioInFormatExchange(CConfigTable& table, AudioInFormatConfig& config, int state);

/// ¼������
enum RecordTypes
{
	RECORD_TYPE_COMMON = 0x00,		///< ��ͨ¼��
	RECORD_TYPE_ALARM = 0x01,		///< ����¼��
	RECORD_TYPE_MOTION = 0x02,		///< ����¼��
	RECORD_TYPE_HAND = 0x03,		///< �ֶ�¼��
	RECORD_TYPE_SNAP = 0x04,		///< ץͼ
	RECORD_TYPE_NR,
};

/// ¼��ģʽ����
enum RecordModeTypes
{
	RECORD_MODE_CLOSED,		///< �ر�¼��
	RECORD_MODE_MANUAL,		///< �ֶ�¼��
	RECORD_MODE_CONFIG,		///< ������¼��
	RECORD_MODE_NR,		
};

///< ¼������
struct RecordConfig
{
	int iPreRecord;			///< Ԥ¼ʱ�䣬Ϊ��ʱ��ʾ�ر�	
	bool bRedundancy;		///< ���࿪��
	int iPacketLength;		///< ¼�������ȣ����ӣ�[1, 255]
	int iRecordMode;		///< ¼��ģʽ����RecordModeTypes
	WorkSheet wcWorkSheet;				///< ¼��ʱ���	
	uint typeMask[N_WEEKS][N_TSECT];	///< ¼���������룬��enum RecordTypes
};

struct RecordConfigAll
{
	RecordConfig vRecordConfigAll[N_SYS_CH+N_DECORDR_CH];
};

/// ¼��ģʽ����
enum SnapModeTypes
{
	SNAP_MODE_CLOSED,		///< �ر�ץͼ
	SNAP_MODE_MANUAL,		///< ��ֹץͼ
	SNAP_MODE_CONFIG,		///< ������ץͼ
	SNAP_MODE_NR,		
};

///< ͼƬ����
struct SnapshotConfig
{
	int iPreSnap;			///< ԤץͼƬ��
	bool bRedundancy;		///< ���࿪��
	int iSnapMode;		///< ¼��ģʽ����RecordModeTypes
	WorkSheet wcWorkSheet;				///< ¼��ʱ���	
	uint typeMask[N_WEEKS][N_TSECT];	///< ¼���������룬��enum RecordTypes
};

struct SnapshotConfigAll
{
	SnapshotConfig vSnapshotConfigAll[N_SYS_CH];
};

/// DVRͨ������
enum ChanTypes
{
	CHAN_TYPE_SIMULATE,		///< ģ��ͨ��
	CHAN_TYPE_DIGIT,		///< ����ͨ��
	CHAN_TYPE_NR,		
};

/// ��Ƶͨ������
struct VideoChannel
{
	int iChnType;		///< ͨ������
	int iChn;			///< ͨ����
};

/// ����ˮӡ����
struct WaterMarkConfig
{
	bool	bEnable;		//  ����ˮӡ
	std::string sKey;
	std::string sUserData;
};

struct WaterMarkConfigAll
{
	WaterMarkConfig vWaterMarkConfigAll[N_SYS_CH];
};

// �������ֱ���
struct EncoderPower
{
	int iMaxResolution[N_SYS_CH];	// ���ı���ֱ���
};

//��Ƶ����
/// ��Ƶ����ģʽ����
enum AudioModeTypes
{
	AUDIO_MODE_SINGLE,		///<��ͨ��ģʽ
	AUDIO_MODE_DOUBLE,		///< ˫ͨ��ģʽ
	AUDIO_MODE_NR,		
};

struct AudioVolume
{
	int AudioMode;  //ͨ��ģʽ,�����ͨ��������Ƶͬʱ����
	int iLInVolume; //������
	int iRInVolume; //Ԥ������Ƶ����
	int reserved; //����
};

struct AudioVolumeAll
{
	AudioVolume Volume[N_SYS_CH]; //Ԥ����Ƶ����
};

struct AudioOpenedChannel
{
	uint iChnMask;
};

enum SpotTypes
{
	SpotAsMain, //spot��Ϊ�����
	SpotAsAux,	//sopt��Ϊ�����
	SpotTypeNr
};
///<spot����
struct SpotConfig
{
	int iType;		///<��ʾ�������SpotTypes
	bool bTourEnable;	///< ������Ѳʹ��	
	int iInterval;	///< ��Ѳʱ����	[5,120]
	uint iMask[N_SPLIT];	///< ��Ѳ����, һά����[����ָ�����]
};

struct SpotConfigAll
{
	SpotConfig vSpotAllCfg[MAX_SPOT_NUMBER];
};

struct TopChInfo
{
	int channel;//ͨ����
	int position;//ͨ����λ����Ϣ
};

struct VideoChannelSeq
{
	bool bFullScreen; //�Ƿ�ȫ��
	bool bChannelState[N_SYS_CH + N_DECORDR_CH];//ͨ���Ŀ���״̬
	TopChInfo vTopChSeq[N_SYS_CH + N_DECORDR_CH]; //��������ʾ��ͨ����Ϣ
	int vSplitChSeq[N_SYS_CH + N_DECORDR_CH]; //��Ƶ�ָ���ͨ������ʾ˳��
	int vDecChSeq[N_PLY_CH + N_DECORDR_CH]; //ͨ����Ӧ��������ӳ��˳��
	int vDecChResSeq[N_PLY_CH + N_DECORDR_CH]; //�л�������ǰ����Ľ�����˳��
	int regionIndex;
};

struct OEMChnSeq
{
	int chnSeq[N_SYS_CH];
};

struct VideoChannelManage
{
	int		nHVRCap; 
	int		curMode;
	bool bhide[MAX_HVR_CHNCAP];//��Ӧģʽ�Ƿ�����
	CAPTURE_HVRCAPV2 HVRCap[MAX_HVR_CHNCAP];	//֧�ֵ�ͨ��ģʽ
};

//������Ϣ����
struct CarInfoDisplay
{
	VIDEO_WIDGET  stCarInfoWidget;
	char          pReserve[32];
};

//GPS��Ϣ��ʾ����
struct GPSDisplay
{
	VIDEO_WIDGET  stGPSWidget;
	char          pReserve[32];
};

//���������ʾ����
struct CarDisplay
{
	CarInfoDisplay stCarInfoDisplay;
	GPSDisplay     stGPSDisplay;
};
//����ͨ���ĳ�����ص���ʾ����
struct CarDisplayConfigAll
{
	CarDisplay   carDisplayConfigAll[N_SYS_CH];
};

/*enum Profile_t
{
	BASELINE = 1,
	MAINPROFILE = 2,
	HIGHPROFILE = 3
};*/

enum EncStaticParamV2
{
	ENC_STATICPARAM_BASELINE = 0,	//֧��baseline
	ENC_STATICPARAM_MAINPRO,	//֧��main profile
	ENC_STATICPARAM_HIGHPRO,	//֧��high profile
	ENC_STATICPARAM_NR
};
///��������̬����
struct EncodeStaticParamV2
{
	int profile;
	int reserved1[4];
};

///��������̬����
struct EncodeStaticParam
{
	//char reserved[2]; //ȥ�������ܻᵼ���ֽڶ�������
	int profile;
	int level;
	int reserved1[4];
};


struct EncodeStaticParamAll
{
	EncodeStaticParam	vEncodeStaticParamAll[N_SYS_CH];
};


// ����ͨ��
struct DecodeParam
{
	int iMaxDeleyTime[N_SYS_CH];	// ���Ľ�����ʱ
};


//����logo��������
struct OsdLogoConfig
{
	int  enable;
	int  left;    //ȡֵ 0 ~ 8192
	int  top;     //ȡֵ 0 ~ 8192
	int  fgTrans; //ǰ��͸����, ȡֵ0~255
	int  bgTrans; //����͸���ȣ�ȡֵ0~255,��ͼƬ���Ͻǵ���ɫΪ����ɫ
	char res[12]; //����
};

/// ������ʱ�ȼ�
enum DecodeDeleyTypes
{
	DecodeDeley_0 = 0,
	DecodeDeley_1,
	DecodeDeley_2,
	DecodeDeley_3,
	DecodeDeley_4,
	DecodeDeley_5,
	DecodeDeley_6,
	DecodeDeley_TYPE_NR,
};

enum TimeSynTypes
{
	TST_OFF = 0,
	TST_TIME_UTC,
	TST_TIME_LOCAL,
	TST_TIME_ALL,
	TST_NR,
};

// ����ͨ��ʱ��ͬ��
struct TimeSynParam
{
	int iTimeModel[N_SYS_CH];
};

//���ƽ̨ͼƬ�ϴ���ؽṹ��
struct AutoUpLoadInfo
{
	int ChannelID;
	SystemTime UploadTime;
};

struct AlarmUpLoadinfo
{
	int enable;
	int Pretime;
	int Savetime;
	int snapInterval; //ץͼ���(��λ��)
	char res[8];
};

struct AlarmUpLoadinfoAll
{
	std::vector<AlarmUpLoadinfo> AlarmUpLoadcfgAll;
};

struct UpLoadInfoList
{
	int UploadEN;
	std::vector<AutoUpLoadInfo> AutoInfo;
};
struct EncodeAddBeep
{
	int Enable;       //��1 ��Ƶ����ÿ��30��beep������0û�д˹��� 
	char res[4];
};

//�Ƿ����OSD logo
struct SetLogo
{
	int Enable;
	int	reserve[8];
};

#endif
