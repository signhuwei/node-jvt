//
//  "$Id: Capture.h 17154 2015-08-14 04:59:34Z zhaochanglong $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//


#ifndef __PAL_CAPTURE_H__
#define __PAL_CAPTURE_H__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup CaptureAPI API Capture
/// ��·����������Ƶ����ӿڣ�������Memory�ӿڡ�
///	\n ��������ͼ:
/// \code
///    ============================================
///                   	|    
///             CaptureGetChannelsCap   
///                   	|    
///             CaptureGetChannels   
///                   	|    
///             CaptureSetChannels   
///                   	|    
///             CaptureSysInit   
///                   	|    
///             CaptureCreate   
///                     |
///             CaptureJPEGCreate
///       +-----------|------------------+         
///       |     CaptureSetVstd         CaptureGetChannels
///		  |				|                CaptureGetDspInfo,
///       |   	CaptureSetFormat		CaptureGetCaps,
///    	  |	CaptureSetPacketPolicy	CaptureGetExtCaps      
///       |           	|           	CaptureSetTime   	 
///       |     CaptureStart     		CaptureSetTitle   
///       | +---------|          		CaptureSetCover   
///       | |  CaptureGetBuffer  		CaptureSetVolume  
///       | | CaptureForceIFrame 	CaptureSynchronize
///       | |  CaptureGetVolume          |         
///       | +---------|                  |         
///       |      CaptureStop             |         
///       +-----------|------------------+         
///           CaptureDestroy                       
///                   |                            
///    ============================================


/// ����ͨ������
enum capture_channel_t {
	CHL_MAIN_T = 0,		///< ��ͨ��	��	������1 
	CHL_2END_T = 1,		///< ��ͨ��	��	��������2 
	CHL_3IRD_T = 2,		///< ��ͨ��	��	��������3 
	CHL_4RTH_T = 3,		///< ��ͨ��	��	��������4 
	CHL_JPEG_T = 4,		///< ��ͨ��	��	��JPEGץͼ 
	CHL_FUNCTION_NUM
};

/// ����ʼ����
enum capture_start_t {
	CAPTURE_START_VIDEO = 1,	///< ��Ƶ���뿪��
	CAPTURE_START_AUDIO = 2		///< ��Ƶ���뿪��
};

/// ����ѹ����ʽ����
enum capture_comp_t {
	CAPTURE_COMP_DIVX_MPEG4,	///< DIVX MPEG4��
	CAPTURE_COMP_MS_MPEG4,		///< MS MPEG4��
	CAPTURE_COMP_MPEG2,			///< MPEG2��
	CAPTURE_COMP_MPEG1,			///< MPEG1��
	CAPTURE_COMP_H263,			///< H.263
	CAPTURE_COMP_MJPG,			///< MJPG
	CAPTURE_COMP_FCC_MPEG4,		///< FCC MPEG4
	CAPTURE_COMP_H264,			///< H.264
	CAPTURE_COMP_H265,			///< H.265
	CAPTURE_COMP_NR				///< ö�ٵ�ѹ����׼��Ŀ��
};

/// ������������ģʽ����
enum capture_brc_t {
	CAPTURE_BRC_CBR,			///< �̶�������
	CAPTURE_BRC_VBR,			///< �ɱ�������
	CAPTURE_BRC_MBR,			///< ���������
	CAPTURE_BRC_NR				///< ö�ٵ���������ģʽ��Ŀ��
};

/// ����ֱ�������
/// \note������������ṹʱ��Ҫͬ������Record.cpp����֤��������
enum capture_size_t {
	CAPTURE_SIZE_D1,		///< 720*576(PAL)	720*480(NTSC)
	CAPTURE_SIZE_HD1,		///< 352*576(PAL)	352*480(NTSC)
	CAPTURE_SIZE_BCIF,		///< 720*288(PAL)	720*240(NTSC)
	CAPTURE_SIZE_CIF,		///< 352*288(PAL)	352*240(NTSC)
	CAPTURE_SIZE_QCIF,		///< 176*144(PAL)	176*120(NTSC)
	CAPTURE_SIZE_VGA,		///< 640*480(PAL)	640*480(NTSC)
	CAPTURE_SIZE_QVGA,		///< 320*240(PAL)	320*240(NTSC)
	CAPTURE_SIZE_SVCD,		///< 480*480(PAL)	480*480(NTSC)
	CAPTURE_SIZE_QQVGA,		///< 160*128(PAL)	160*128(NTSC)
	CAPTURE_SIZE_NR = 9,	///< ����ʱ����ȵײ�һ���޸�
	CAPTURE_SIZE_ND1 = 9,   ///< 240*192
	CAPTURE_SIZE_650TVL,    ///< 928*576
	CAPTURE_SIZE_720P,      ///< 1280*720
	CAPTURE_SIZE_1_3M,      ///< 1280*960
	CAPTURE_SIZE_UXGA ,     ///< 1600*1200
	CAPTURE_SIZE_1080P,     ///< 1920*1080
	CAPTURE_SIZE_WUXGA,     ///< 1920*1200
	CAPTURE_SIZE_2_5M,      ///< 1872*1408
	CAPTURE_SIZE_3M,        ///< 2048*1536
	CAPTURE_SIZE_5M,        ///< 3744*1408
	CAPTURE_SIZE_EXT_NR =19,    ///< ö�ٵ�ͼ�δ�С�������Ŀ��
	CAPTURE_SIZE_1080N = 19,     ///< 960*1080
	CAPTURE_SIZE_4M,        ///< 2592*1520
	CAPTURE_SIZE_6M,		///< 3072��2048
	CAPTURE_SIZE_8M,		///< 3264��2448
	CAPTURE_SIZE_12M,		///< 4000*3000
	CAPTURE_SIZE_4K,		///< 4096 * 2160ͨ��/3840*2160��˼
	CAPTURE_SIZE_EXT_V2_NR=25,    ///< ö�ٵ�ͼ�δ�С�������Ŀ��
	CAPTURE_SIZE_720N = 25,  //  640*720
	CAPTURE_SIZE_WSVGA,      ///< 1024*576
	CAPTURE_SIZE_RES2,       // 0*0
	CAPTURE_SIZE_RES3,       // 0*0
	CAPTURE_SIZE_RES4,       // 0*0
	CAPTURE_SIZE_RES5,       // 0*0
	CAPTURE_SIZE_RES6,       // 0*0
	CAPTURE_SIZE_EXT_V3_NR,
};

/// �����豸���Խṹ
typedef struct CAPTURE_CAPS
{
	/// ֧�ֵ�ѹ����׼�����룬λ��Ŷ�Ӧö������capture_comp_t��ÿһ��ֵ��
	/// ��1��ʾ֧�ָ�ö��ֵ��Ӧ�����ԣ���0��ʾ��֧�֡�
	unsigned int Compression;

	/// ֧�ֵ���������ģʽ�����룬λ��Ŷ�Ӧö������capture_brc_t��ÿһ��ֵ��
	/// ��1��ʾ֧�ָ�ö��ֵ��Ӧ�����ԣ���0��ʾ��֧�֡�
	unsigned int BitRateControl;

	/// ֧�ֵ�ͼ���С���͵����룬λ��Ŷ�Ӧö������capture_size_t��ÿһ��ֵ��
	/// ��1��ʾ֧�ָ�ö��ֵ��Ӧ�����ԣ���0��ʾ��֧�֡�
	/// ��V2�汾�ӿ����Ѿ�����ʹ��
	unsigned int ImageSize;

	/// ֧�ֵ�ý�����͵����룬��ö������capture_start_t��ÿһ��ֵ���룬�õ���Ӧ
	/// �����ԡ���1��ʾ֧�ָ�ö��ֵ��Ӧ�����ԣ���0��ʾ��֧�֡�
	unsigned int Media;

	/// ���򸲸ǵ�֧�ֵĿ�����
	int CoverBlocks;

	/// ������
	int Reserved;

	/// ֧�����ı�����ӵĸ�����
	int	TitleCount;

	/// �Ƿ�֧�����򸲸� 0-��֧�֣�1-֧��ʵʱ�����򸲸ǣ� ����������ʱ
	/// �ٶȽϿ죬����ʵʱ���ã� 2-֧�ַ�ʵʱ�����򸲸ǣ�����������ʱ�ٶȽ�����
	/// ֻ�����û�ȷ���������á�  
	int	RegionCover;
} CAPTURE_CAPS;

/// �������ݸ�ʽ�ṹ
typedef struct CAPTURE_FORMAT
{
	unsigned char	Compression;		///< ѹ����׼��ȡcapture_comp_t���͵�ֵ�� 
	unsigned char	BitRateControl; 	///< ��������ģʽ��ȡcapture_brc_t���͵�ֵ�� 
	unsigned char	ImageSize; 			///< ͼ���С��ȡcapture_size_t���͵�ֵ�� 
	unsigned char	ImageQuality;		///< ͼ��������ȡֵ1-6��ֵԽ��ͼ������Խ��,ֻ���ڿɱ������²������á�
	unsigned char	FramesPerSecond;	///< ÿ���ӵ�֡����һ��PAL��1-25֡/�룬NTSC��1-30֡/�롣 
	unsigned char	AVOption;			///< ����Ƶѡ����λ��ʾ��Ƶ�����λ��ʾ��Ƶ 
	unsigned short	BitRate;			///< �ο�����ֵ��KbpsΪ��λ
	unsigned char	GOP; 				///< ֡�������ֵ������ֵ49��99
	unsigned char	reserved[3]; 		///< �����ֽ�
} CAPTURE_FORMAT;


/// ���������Ӳ����ṹ
typedef struct CAPTURE_TITLE_PARAM
{
	/// ������ţ����֧�ֵı�������CaptureGetCaps����ȡ�á����0��Ӧ����
	/// ʱ����⡣ʱ���������ɵײ��ڲ�������width height raster���������ԡ�
	int		index;

	/// �Ƿ���ʾ��0-����ʾ�������������ԣ�1-��ʾ��
	int		enable;

	/// �������Ͻ�x���꣬ȡ8�����������������������ϵ(CIF)��
	unsigned short	x;		

	/// �������Ͻ�y���꣬�������������ϵ(CIF)��
	unsigned short	y;
	
	/// �����ȣ�ȡ8����������					
	unsigned short	width;		

	/// ����߶ȡ�
	unsigned short	height;		

	/// ǰ����ɫ��16���Ʊ�ʾΪ0xAABBGGRR��A(Alpha)��ʾ͸���ȡ�
	/// text color, rgba 8:8:8:8	
	unsigned int	fg_color;
	
	/// ������ɫ��16���Ʊ�ʾΪ0xAABBGGRR��A(Alpha)��ʾ͸���ȡ�
	/// background color, rgba 8:8:8:8	
	unsigned int	bg_color;

	/// ���ⵥɫ�������ݡ�0��ʾ�õ���Ч��1��ʾ�õ���Ч��ÿ���ֽڰ���8�����ص�
	/// ���ݣ�����ߵ����������λ�����ӵ���һ���ֽڶ�Ӧ�ұ�8�����أ�ֱ��һ��
	/// ����������������һ�����صĵ������ݡ�
	unsigned char	*raster;
}CAPTURE_TITLE_PARAM;


/// ���������Ӳ����ṹ V2��
typedef struct CAPTURE_TITLE_PARAM_V2
{
	//0��Ӧʱ����⣬1��Ӧͨ�����⣬2��3����������
	int		index;

	/// �Ƿ���ʾ��0-����ʾ�������������ԣ�1-��ʾ��
	int		enable;

	/// �������Ͻ�x���꣬ȡ8�����������������������ϵ(CIF)��
	unsigned short	x;		

	/// �������Ͻ�y���꣬�������������ϵ(CIF)��
	unsigned short	y;

	/// �����ȣ������ص�ĸ�����ȡ8����������
	unsigned short	width;		

	/// ����߶ȣ������ص�ĸ�����ȡ8����������
	unsigned short	height;	

	/// ǰ����ɫ��16���Ʊ�ʾΪ0xAABBGGRR��A(Alpha)��ʾ͸���ȡ�
	/// text color, rgba 8:8:8:8	
	unsigned int	fg_color;

	/// ������ɫ��16���Ʊ�ʾΪ0xAABBGGRR��A(Alpha)��ʾ͸���ȡ�
	/// background color, rgba 8:8:8:8	
	unsigned int	bg_color;

	//��ɫ��ʽ����ö��ֵGraphicsColorFormat������
	unsigned int    color_format;

	/// ����������ɫֵ�����color_format��ֵΪgraphicsColorRGB555��
	/// ����Ҫ�����ֽ�����ʾһ�����ص���ɫ������pixel�������������
	/// Ӧ���� (width * height * 2)�ֽڡ�
	/// ���pixel��NULL������indexΪ0�����ʾ�ɵײ���Լ�����������ʱ����⡣
	unsigned char	*pixel;

}CAPTURE_TITLE_PARAM_V2;



/// ������������ṹ
typedef struct CAPTURE_DSPINFO 
{
	unsigned int	nMaxEncodePower;	///< DSP ֧�ֵ���߱���������
	unsigned short	nMaxSupportChannel;	///< DSP ֧�����������Ƶͨ������
	unsigned short	bChannelMaxSetSync;	///< DSP ÿͨ���������������Ƿ�ͬ�� 0-��ͬ��, 1 -ͬ����
}CAPTURE_DSPINFO, *PCAPTURE_DSPINFO;

typedef struct tagCAPTURE_DSPINFO_EXT 
{
	unsigned int	nMaxEncodePower;	/*-	DSP ֧�ֵ���߱������� 	-*/
	unsigned short	nMaxSupportChannel;	/*-	DSP ֧�����������Ƶͨ���� 	-*/
	unsigned short	bChannelMaxSetSync; /*-	DSP ÿͨ���������������Ƿ�ͬ�� 0-��ͬ��, 1 -ͬ�� 	-*/
	unsigned int	nMaxDecodePower; /*-	DSP ���������п����ڽ�������� 	-*/
	unsigned int nMaxPowerPerChannel[32];	///< ÿ��ͨ��֧�ֵ���߱�������
	unsigned int ImageSizePerChannel[32];	///< ÿ��ͨ��֧�ֵ�ͼ��ֱ���
	unsigned int	reserved[21]; /*-	�����ֶ� 	-*/
}CAPTURE_DSPINFO_EXT, *PCAPTURE_DSPINFO_EXT;

/// ����������֧�����Խṹ
typedef struct CAPTURE_EXT_STREAM
{
	unsigned int ExtraStream;						///< ��channel_t��λ����ʾ֧�ֵĹ��ܡ�
	unsigned int CaptureSizeMask[CAPTURE_SIZE_NR];	///< ÿһ��ֵ��ʾ��Ӧ�ֱ���֧�ֵĸ�����������Ŀǰֻ�����ڸ�������
}CAPTURE_EXT_STREAM, *pCAPTURE_EXT_STREAM;	

/// ��������
/// ˵���� 
/// ����ͨ��������֧�ֵķֱ�������ȡ����2������: 1 - ��ǰͨ��֧�ֵķֱ��ʼ�uiImageSizePerChannel 2 - ��ǰͨ��֧�ֵ���߱���������uiMaxPowerPerChannel
/// ����������������͸��������ܺ�
/// ����ͨ��������֧�ֵķֱ�������ȡ����3������: 1 - ��ǰͨ��֧�ֵķֱ��ʼ�uiExImageSizePerChannel 2 - ��ǰͨ��֧�ֵ���߱���������uiMaxPowerPerChannel
/// 3 - ���������õķֱ����¸�����֧�ֵķֱ��ʼ�uiExImageSizePerChannelEx
/// iChannelMaxSetSync�� 1 - ��ʾ����ͨ���ķֱ��ʶ�Ҫһ��
typedef struct CAPTURE_CHANNEL_ABILITY  //ʹ���°�CAPTURE_CHANNEL_ABILITYV2��������Ϊ�˼����ϵĵĿ�
{
	unsigned int uiMaxPower;  ///< ÿ��ͨ��֧�ֵ���߱�������
	unsigned int uiImageSize;  ///< ÿ��ͨ��֧�ֵ�ͼ��ֱ���
	unsigned int uiExImageSize;  ///< ÿ��ͨ��֧�ֵĸ�����ͼ��ֱ���
	unsigned int uiExImageSizeEx[CAPTURE_SIZE_EXT_V2_NR]; ///< ָ���������ֱ�����ÿ��ͨ���ĸ�����֧�ֵ�ͼ��ֱ���
	unsigned int uiCompressionMask;   //����ģʽcapture_comp_t����
	unsigned int Resverd; 
}CAPTURE_CHANNEL_ABILITY;

typedef struct CAPTURE_CHANNEL_ABILITYV2
{
	unsigned int uiMaxPower;  ///< ÿ��ͨ��֧�ֵ���߱�������
	unsigned int uiImageSize;  ///< ÿ��ͨ��֧�ֵ�ͼ��ֱ���
	unsigned int uiExImageSize;  ///< ÿ��ͨ��֧�ֵĸ�����ͼ��ֱ���
	unsigned int uiExImageSizeEx[CAPTURE_SIZE_EXT_V3_NR]; ///< ָ���������ֱ�����ÿ��ͨ���ĸ�����֧�ֵ�ͼ��ֱ���
	unsigned int uiCompressionMask;   //����ģʽcapture_comp_t����
	unsigned int uiResverd[7];
}CAPTURE_CHANNEL_ABILITYV2;

typedef struct CAPTURE_DSPINFO_V2 //ʹ���°�CAPTURE_DSPINFO_V3��������Ϊ�˼����ϵĵĿ�
{
	CAPTURE_CAPS Caps;          ///< ������صĸ�����Ϣ
	unsigned int uiMaxEncodePower;      ///< ֧�ֵ��ܱ�������
	unsigned int uiMaxBps;              ///< ֧�ֵ������ʴ�СKbps
	int  iChannelMaxSetSync;    ///< ÿ��ͨ���ֱ����Ƿ���Ҫͬ�� 0-��ͬ��, 1 -ͬ��
	int	 nMaxSupportChannel;	    ///< DSP ֧�����������Ƶͨ����
	unsigned int nMaxDecodePower;    ///< DSP ���������п����ڽ��������
	unsigned int uiStream;           ///< ֧�ֵ���������
	CAPTURE_CHANNEL_ABILITY DspAbility[32];
	unsigned int uiResverd[16];
}CAPTURE_DSPINFO_V2;

typedef struct CAPTURE_DSPINFO_V3
{
	CAPTURE_CAPS Caps;          ///< ������صĸ�����Ϣ
	unsigned int uiMaxEncodePower;      ///< ֧�ֵ��ܱ�������
	unsigned int uiMaxBps;              ///< ֧�ֵ������ʴ�СKbps
	int  iChannelMaxSetSync;    ///< ÿ��ͨ���ֱ����Ƿ���Ҫͬ�� 0-��ͬ��, 1 -ͬ��
	int	 nMaxSupportChannel;	    ///< DSP ֧�����������Ƶͨ����
	unsigned int nMaxDecodePower;    ///< DSP ���������п����ڽ��������
	unsigned int uiStream;           ///< ֧�ֵ���������
	CAPTURE_CHANNEL_ABILITYV2 DspAbility[32];
	unsigned int uiResverd[16];
}CAPTURE_DSPINFO_V3;


/// ����ˮӡ�ṹ�壬��128���ֽ�
#define WM_KEY_LEN  8	/// ��Կ�ַ��������� 
#define WM_CHAR_LEN 16	/// ˮӡ�ַ�����
typedef struct CAPTURE_WM_ATTR_S
{
	unsigned int enable;  				//ˮӡʹ��  1��ʾ��������0��ʾ�ر�
	unsigned char au8Key[WM_KEY_LEN];	/// ����ˮӡ��Կ�ַ��� 
	unsigned char au8User[WM_CHAR_LEN]; /// ����ˮӡ�û��ַ� 
	unsigned char resv[128 - WM_KEY_LEN - WM_CHAR_LEN - 4];
} CAPTURE_WM_ATTR_S;

struct VIDEO_COVER_PARAM;

/// ����ͨ����Ϣ
typedef struct CAPTURE_CHNINFO 
{
	unsigned int	nOrgChannel;	///< �Ӽ�����Ϣ��ȡ����ԭʼ����
	unsigned int	nCustomChannel;	///< Ӧ�ó�������Ƶͨ������
	unsigned int    nRes[8];
}CAPTURE_CHNINFO, *PCAPTURE_CHNINFO;

//ץ������
typedef struct tagCAPTURE_SNAP_CAPS
{
	unsigned int nMaxSupportChannel;
	unsigned int ImageSizePerChannel[32];
	unsigned int reerved[6];
}CAPTURE_SNAP_CAPS;


typedef struct tagCHANNEL_CAPS
{
	int nTotalChannel;       /// �������ͨ����
	int nHostChannel;        /// ��Ƭ֧��ͨ����
	int	nPerSlaveChannel;    /// ÿƬ��Ƭ��ͨ����
	int	nSlaveChipNum   ;    /// ��Ƭ�ĸ���
	int	nSlaveChipAlign;     /// ÿƬ��Ƭ�Ķ���ͨ����
	int	nPlayChannel;        /// �طŵ�ͨ����
	int	reserved[4];
} CHANNEL_CAPS;

/// ���DSP�ı�������
///
int CaptureGetDspInfo(CAPTURE_DSPINFO *pDspInfo); 		 //�Ѿ�������
int CaptureGetDspInfoExt(CAPTURE_DSPINFO_EXT *pDspInfo); //�Ѿ�������

/// �õ������ͨ����Ŀ�����������������ͨ�������������ͨ������󲶻�ͨ���ż�1��
/// 
/// \return�����ͨ����Ŀ��
int CaptureGetChannels(void);

/// ���ò����ͨ����Ŀ�����������������ͨ�������������ͨ������󲶻�ͨ���ż�1��
/// 
/// \return�����ͨ����Ŀ��
int CaptureSetChannels(int nCapture);

/// �õ�����֧�ֵ����ԡ�
/// 
/// \param [out] pCaps ָ�򲶻����ԽṹCAPTURE_CAPS��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
int CaptureGetCaps(CAPTURE_CAPS * pCaps); //�Ѿ�������

//! ��ò���ͨ��������
/// 
/// \param [out] pCaps ָ�򲶻��������ṹCHANNEL_CAPS��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
int CaptureGetChannelsCap(CHANNEL_CAPS * pCaps);

/// �õ�����˫����֧�ֵ����ԡ�������CaptureGetCapsһ�������õ�����˫����֧�ֵ����ԣ�
/// ��������ͨ�������ԡ� 
/// 
/// \param [out] pCaps ָ�򲶻����ԽṹCAPTURE_CAPS��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval 0  ��ȡʧ�ܡ�
int CaptureGetExtCaps(CAPTURE_EXT_STREAM *pCaps);

//��ֱ�ӵ�
/// �õ�������������Ϣ���İ汾ͳһ��һ��3���ӿ�
/// int CaptureGetCaps(CAPTURE_CAPS * pCaps);
/// int CaptureGetDspInfo(CAPTURE_DSPINFO *pDspInfo);
/// int CaptureGetDspInfoExt(CAPTURE_DSPINFO_EXT *pDspInfo);
/// ���Ͻӿڽ��𲽷ϳ�
/// \param [out] pDspInfo ָ�򲶻���������Ϣ�ṹCAPTURE_DSPINFO_V2��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval 0  ��ȡʧ�ܡ�
int CaptureGetDspInfoV2(CAPTURE_DSPINFO_V2 *pDspInfo); //����V3,V2Ϊ�˼����ϵĿ⣬��ʱ����,V3�ٷ�װһ�㣬����CaptureGetDspInfoEx�����ж�V3�Ƿ���ڣ������ڵ���V2

/// \param [out] pDspInfo ָ�򲶻���������Ϣ�ṹCAPTURE_DSPINFO_V3��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval 0  ��ȡʧ�ܡ�
#ifdef LINUX
int CaptureGetDspInfoV3(CAPTURE_DSPINFO_V3 *pDspInfo)  __attribute__ ((weak));
#else
int CaptureGetDspInfoV3(CAPTURE_DSPINFO_V3 *pDspInfo);
#endif

/// \param [out] pDspInfo ָ�򲶻���������Ϣ�ṹCAPTURE_DSPINFO_V3��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval 0  ��ȡʧ�ܡ�
int CaptureGetDspInfoEx(CAPTURE_DSPINFO_V3 *pDspInfo);

/// �õ������豸ϵͳ��ʼ��
/// 
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
int CaptureSysInit();

/// ���������豸
/// 
/// \param [in] channel ͨ���š�
/// \retval 0 ����ʧ��
/// \retval 0 �����ɹ�
int CaptureCreate(int channel);


/// ���ٲ����豸
/// 
/// \param [in] channel ͨ���š�
/// \retval 0 ����ʧ��
/// \retval 0 ���ٳɹ�
int CaptureDestroy(int channel);


/// Ӧ�ó���ʱ���ã� ֪ͨ����ģ��������״̬�� ����д��� ����ģ�顣 
/// 
void CaptureSynchronize(void);


/// ������Ƶ��ʽ��
/// 
/// \param [in]  channel ͨ���š�
/// \param [in]  dwStandard ��Ƶ��ʽ��ȡvideo_standard_t���͵�ֵ��
/// \retval 0  ���óɹ�
/// \retval 0  ����ʧ��
int CaptureSetVstd(int channel,unsigned int dwStandard);	


/// ���ò���ʱ��͸�ʽ��Ӧ�ó�����Ҫ��ʱ���ô˺����벶���ʱ�����ͬ����
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pTime ָ��ϵͳʱ��ṹSYSTEM_TIME��ָ�롣
/// \param [in] datefmt ���ڸ�ʽ��ȡdate_fmtö��ֵ��
/// \param [in] datespc ���ڷָ����ȡdate_specö��ֵ��
/// \param [in] timefmt ʱ���ʽ��ȡtime_fmtö��ֵ��
/// \retval 0  ���óɹ���
/// \retval 0  ����ʧ�ܡ�
int CaptureSetTime(int channel, const SYSTEM_TIME * pTime, int datefmt,int datespc,int timefmt);


/// ���ñ�����ӡ�
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pParam ָ�������ӽṹCAPTURE_TITLE_PARAM��ָ�롣
/// \retval 0   ���óɹ���
/// \retval ��0 ����ʧ�ܡ�
int CaptureSetTitle(int channel, CAPTURE_TITLE_PARAM *pParam);


/// ���ñ�����ӣ�V2�汾��������һ���������ṹ��Ҳ�е�仯
/// 
/// \param [in] channel ͨ���š�
/// \param [in] streamType �������ͣ���ö��ֵcapture_channel_t������.
/// \param [in] pParam ָ�������ӽṹCAPTURE_TITLE_PARAM_V2��ָ�롣
/// \retval 0   ���óɹ���
/// \retval ��0 ����ʧ�ܡ�
int CaptureSetTitleV2(int channel, int streamType, CAPTURE_TITLE_PARAM_V2 *pParam);

/// ���ø�������
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pParam ָ����Ƶ���ǽṹVIDEO_COVER_PARAM��ָ�롣
/// \retval 0  ���óɹ���
/// \retval 0  ����ʧ�ܡ�
int CaptureSetCover(int channel,int index, struct VIDEO_COVER_PARAM *pParam);



/// ���ò����������
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwLVolume ������������ȡֵ0-100��
/// \param [in] dwRVolume ������������ȡֵ0-100��
/// \retval 0  ���óɹ�
/// \retval 0  ����ʧ��
int CaptureSetVolume(int channel, unsigned int dwLVolume, unsigned int dwRVolume);


/// ǿ�Ʊ���������I֡�� 
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwType
/// \retval 0  ���óɹ���
/// \retval 0  ����ʧ�ܡ�
int CaptureForceIFrame(int  channel, unsigned int dwType);

/// ���ò�������ѹ���ĸ�ʽ��
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwType
/// \param [in] pFormat ָ�򲶻��ʽ�ṹCAPTURE_FORMAT��ָ�롣
/// \retval 0  ���óɹ�
/// \retval 0  ����ʧ��
int CaptureSetFormat(int channel, unsigned int dwType, CAPTURE_FORMAT * pFormat);


/// ��ʼ���롣����Ƶ��ʽ������ѡ�ͼ��������֡�ʡ��������Ʒ�ʽ���ֱ��ʡ�����
/// ģʽ�Ȳ������ı�ʱ��Ӧ�ó����ֹͣ����Ȼ�����¿�ʼ����
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwType ������ʾ���������ѡ���capture_channel_t���͵�ֵ����ϡ�
/// \retval 0  ��ʼ�ɹ�
/// \retval 0  ��ʼʧ��
int CaptureStart(int  channel, unsigned int dwType);


/// ֹͣ���룬��ǰ�����������ء�
/// 
/// \param [in]  channel ͨ���š�
/// \param [in]  dwType
/// \retval 0  ֹͣ�ɹ�
/// \retval 0  ֹͣʧ��
int CaptureStop(int  channel, unsigned int dwType);


/// ��ȡ�������ݣ���Ϊ������ʱģʽ���ڴ�����豸�������䣬�豸�õ��ʵ�������
/// �󷵻ء���ʱʱ�������أ����ڴ�����Ѿ�������ݣ�������ʵ�ʵ����ݳ��Ȳ����أ�
/// ���ڴ����û�����ݣ����ش��󣻽���ʱʱ�����õĽ�С������������ݵ�ʵʱ�ԡ�
/// 
/// \param [in] pchannel ͨ���ţ�-1��ʾ������ͨ�������ݣ�������ͨ������Ϊ����
///        ����ֵ���ء�
/// \param [in] pdwType
/// \param [out] phMemory �ڴ����ָ�룬��������ȡ�����ڴ�������ڴ���ʵ�����ݳ�
///        �ȱ�ʾ���񵽵����ݳ��ȡ�
/// \return>=0 ͨ���ţ�������ͨ����Ϊ-1ʱ��
/// \retval 0  ���ɹ�
/// \retval 0  ��ʧ��
int CaptureGetBuffer(int *pchannel, unsigned int *pdwType, void* *phMemory);


/// �Ա���ͨ�����������������ϡ������ɶ��ͨ������Ƶ�����ϳ�һ��������档
/// 
/// \param [in] channel ����ͨ����
/// \param [in] dwMode ����е�ͨ����Ŀ��ȡsplitt���͵�ֵ��
/// \param [in] dwIndex ��ǰͨ����Ŀ����Ϸ�ʽ����š�
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
int CaptureCombine(int channel, unsigned int dwMode, unsigned int dwIndex);

/// ����JPEG����ͨ��
/// 
/// \param [in] channel ����ͨ����
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
/// \�ýӿ���Ҫ��CaptureSetVstdǰ����
int CaptureJPEGCreate(int channel);


/// ���ñ�������ˮӡ����
/// \param [in] channel Ҫ���õ�ͨ��
/// \param [in] pstWM Ҫ����ˮӡ��Ϣ
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
int CaptureSetWmAttr(int channel, const CAPTURE_WM_ATTR_S *pstWM);


/// ���ñ�����Ϣ֡��Ϣ
/// \param [in] channel Ҫ���õ�ͨ��
/// \param [in] pInfo Ҫ���õ���Ϣ
/// \param [in] nLen  ��Ϣ����
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
int CaptureSetInfoFrame(int channel, const unsigned char *pInfo, int nLen);

///��������̬����
typedef struct ENCODE_STATICPARAM
{
	//char reserved[2];
	int  profile;    
	int level;
	int reserved1[4];
} ENCODE_STATICPARAM;

/// ���ñ�������̬������
/// \param [in] channel ͨ���š�
/// \param [in] dwType
/// >= 0 ���óɹ�, =1 �豸��Ҫ����
///   <0 ����ʧ��
int CaptureSetEncodeStaticParam(int channel, unsigned int dwType, ENCODE_STATICPARAM * encode_static_param);

///�����Ƿ�IPC�þ�̬����ӿ�
typedef struct CAPTURE_PROFILE
{
	int profile;//��Ӧcapture_profile_capsö��
	int reserved[4];
}CAPTURE_PROFILE;

enum capture_profile_caps
{
	BS = 0,
	MP,
	HP,
};
///pCapsΪcapture_profile_caps������
int CaptureGetEncodeProfileCaps(int *pCaps);

int CaptureSetEncodeProfile(CAPTURE_PROFILE *pProfile);


//����ʵʱץͼ
int CaptureTrigerSnap(int channel, unsigned int dwType);

//ץ������.�Ż�0��ʾ֧��
int CaptureGetSnapCaps(CAPTURE_SNAP_CAPS *pCaps);

/// ����ͨ��¼��״̬
/// \param [in] nchannel Ҫ���õ�ͨ��
/// \param [in] state ¼��״̬��0:û��¼��;1:����¼��
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
int CaptureSetRecordState(int nchannel, int state);


/// ����ͨ����Ϣ
typedef struct CAPTURE_ExDevAbility
{
	unsigned int	nDisplayResolution;	//��ʾģʽ�ֱ��� ...|1920*1080|1440*900|1280*1024|1280*720|1024*768|800*600
	unsigned int	nDisplayVOType;	    //��ʾ����  ...|SPOT|HDMI|VGA|TV
	unsigned int	nDispLayZoomType;	//��ʾ����  ...|4����|2����|������
	unsigned int    nRes[9];
}CAPTURE_ExDevAbility, *PCAPTURE_ExDevAbility;

/// ����ͨ��¼��״̬
/// 
/// 
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ��?
#ifdef LINUX
int CaptureGetExDevAbility(CAPTURE_ExDevAbility *pExDevAbility)  __attribute__ ((weak));
#else
int CaptureGetExDevAbility(CAPTURE_ExDevAbility *pExDevAbility);
#endif


/// ���ȫ�ٽ���ʱ��Ԥ�������õ�֡��
/// \ return ֡��
#ifdef LINUX
int CaptureGetVencFrame()  __attribute__ ((weak));
#else
int CaptureGetVencFrame();
#endif

#ifdef __cplusplus
}
#endif

#endif

