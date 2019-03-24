//
//  "$Id: Video.h 5767 2012-12-29 06:13:45Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_VIDEO_H__
#define __PAL_VIDEO_H__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup VideoAPI API Video
/// ��Ƶ����API����Ҫ����Ƶ���������������������ã�����һЩ���������ù��ܡ�
///	\n ��������ͼ:
/// \code
///    =======================================================
///                |                            
///          VideoGetCaps            
///                |                            
///           VideoCreate                      
///      +---------|--------------+----------------------+     
///      |         |(In)          |(Out)                 |(Others)
///      |   VideoSetColor   VideoSwitch         VideoWriteRegister         
///      |   VideoSetCover VideoSetBkColor        VideoReadRegister
///      |   VideoSetVstd   VideoSetTVMargin        VideoMatrix
///      |         |        VideoSetTVColor      VideoSwitchTVMonitor
///      |         |                           VideoSwitchVGAMonitor
///      |         |      VideoSetOutputAdapter          |
///      |         |      VideoSetOutputAdapter          |
///      |         |              |                      |
///      +---------|--------------+----------------------+          
///            VideoDestory   
///                |                            
///    =======================================================
/// \endcode
/// @{

/// ��Ƶ��ʽ����
enum video_standard_t {
	VIDEO_STANDARD_PAL = 0,	///< PAL��ʽ��
	VIDEO_STANDARD_NTSC,	///< NTSC��ʽ��
	VIDEO_STANDARD_SECAM	///< SECAM��ʽ��
};

/// ��Ƶ��ɫ��ʽ
typedef struct VIDEO_COLOR{
	unsigned char	Brightness;		///< ���ȣ�ȡֵ0-100��
	unsigned char	Contrast;		///< �Աȶȣ�ȡֵ0-100��
	unsigned char 	Saturation;		///< ���Ͷȣ�ȡֵ0-100��
	unsigned char 	Hue;			///< ɫ����ȡֵ0-100��
	unsigned char 	Gain;			///< ���棬ȡֵ0-100��bit7��λ��ʾ�Զ����棬����λ�����ԡ�
	unsigned char	WhiteBalance;	///< �Զ��׵�ƽ���ƣ�bit7��λ��ʾ�����Զ�����.0x0,0x1,0x2�ֱ�����,��,�ߵȼ�
	unsigned short	Acutance;       ///< ��ȣ�ȡֵ0-15, ��8λ��ʾˮƽ��ȣ���8Ϊ��ʾ��ֱ��ȡ�
}VIDEO_COLOR;

/// VGA��Ƶ�ֱ���
typedef struct VGA_RESOLUTION {
	int	Width;						///< ˮƽ�ֱ��ʡ�
	int	Height;						///< ��ֱ�ֱ��ʡ�
} VGA_RESOLUTION;


/// ��Ƶ���ǲ�������
enum video_cover_t {
	VIDEO_COVER_WINDOW_CLEAR = 0,	///< ������ڸ�������
	VIDEO_COVER_WINDOW_DRAW,		///< ���ƴ��ڸ�������
	VIDEO_COVER_FULLSCREEN_DRAW,	///< ����ȫ����������
	VIDEO_COVER_FULLSCREEN_CLEAR	///< ���ȫ����������
};

/// ��Ƶ���ǲ���
typedef struct VIDEO_COVER_PARAM
{
	/// ���ǵľ������򣬲������������ϵ��
	VIDEO_RECT	rect;

	/// ������������ʾ����ɫ��16���Ʊ�ʾΪ0x00BBGGRR������ֽڱ�����
	unsigned int		color;

	/// ������������ͣ� ȡvideo_cover_t���͵�ֵ�����ں�ȫ������Ӧ���Ƕ����ģ� 
	/// �������ڵĲ�����Ӱ��ȫ����ȫ���ڵĲ���Ҳ��Ӱ�촰�ڡ� �������ʱ������
	/// ���������ԡ�
	int			enable;
}VIDEO_COVER_PARAM;

/// ��Ƶ�л�����
enum video_switch_t{
	VIDEO_SWITCH_MONITOR = 0,	///< �л������������
	VIDEO_SWITCH_PLAY,			///< �л����ط������
	VIDEO_SWITCH_DECODE,		///< �л������ֽ��������
	VIDEO_SWITCH_MIX,		    ///< �л���ģ������ֽ��������
};

/// ��Ƶ�������������
enum video_output_t{
	VIDEO_OUTPUT_AUTO = 0,	///< �Զ�����豸��
	VIDEO_OUTPUT_VGA,		///< �л���VGA�����
	VIDEO_OUTPUT_TV,		///< �л���TV�����
	VIDEO_OUTPUT_VGA_LCD	///< �л���LCD VGA�����
};

/// �����豸���Խṹ
typedef struct VIDEO_CAPS
{
	/// �Ƿ�֧��TV�����ɫ���á���1��ʾ֧�ָ�ö��ֵ��Ӧ�����ԣ���0��ʾ��֧�֡�
	unsigned char TVColor;
} VIDEO_CAPS;				


/// ������Ƶ�豸
/// 
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int VideoCreate(void);


/// ������Ƶ�豸
/// 
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 ���ٳɹ�
int VideoDestory(void);


/// ������Ƶ����ɫ������
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pColor ָ����ɫ�ṹVIDEO _ COLOR��ָ�롣
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int VideoSetColor(int channel, VIDEO_COLOR * pColor);

/// ͼ��֧�ֵ������б�����
/// \note ��Ϊͼ�����б�����mask 1:������ 0:��������
enum pic_attr
{
	PIC_COLOR, ///< ����,�Աȶ�,ɫ��,����,���Ͷ�
	PIC_BACKLIGHT,///< ���ⲹ��
	PIC_EXPOSAL, 	///< �ع�ѡ��
	PIC_AUTOC2BW, ///< �Զ��ʺ�ת��
	PIC_MIRROR,		//����
	PIC_FLIP,		//��ת
	PIC_MASKNUM,  ///< ����ѡ����
};
 
/// ��Ƶ���ƽṹ
typedef struct VIDEO_CONTROL
{
	unsigned char  Exposure;		///< �ع�ģʽ 1-6:�ֶ��ع�ȼ�; 0:�Զ��ع�
	unsigned char  Backlight;		///< ���ⲹ�� 1:�򿪲���; 0:ֹͣ����
	unsigned char  AutoColor2BW;	///< �Զ��ʺ�ת�� 1:��ת��; 0:ֹͣת��
	unsigned char  Mirror;			//< ����  1 ���� 0��
}VIDEO_CONTROL;
 
/// ������Ƶ�Ŀ��Ʋ�����
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pColor ָ����Ƶ���ƽṹVIDEO_CONTROL��ָ�롣
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int VideoSetControl(int channel, VIDEO_CONTROL * pColor);


/// ���ø�������
/// 
/// \param [in] channel ͨ���š�
/// \param [in] index �ڵ������
/// \param [in] pParam ָ����Ƶ���ǽṹVIDEO_COVER_PARAM��ָ�롣
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
int VideoSetCover(int channel, int index, VIDEO_COVER_PARAM *pParam);


/// ������Ƶ��ʽ��
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwStandard ��Ƶ��ʽ��ȡvideo_standard_t���͵�ֵ��
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int VideoSetVstd(int channel,unsigned int dwStandard);	


/// дһ���ֽڵ���Ƶ�豸�Ĵ�����
/// 
/// \param [in] Chip оƬ��š�
/// \param [in] Page ҳ����š�
/// \param [in] Register �Ĵ�����š�
/// \param [in] Data Ҫд���ֵ��
/// \return ��
void VideoWriteRegister(unsigned char Chip, unsigned char Page, unsigned char Register, unsigned char Data);


/// ����Ƶ�豸�Ĵ�����һ���ֽڡ�
/// 
/// \param [in] Chip оƬ��š�
/// \param [in] Page ҳ����š�
/// \param [in] Register �Ĵ�����š�
/// \return������ֵ��
unsigned char VideoReadRegister(unsigned char Chip, unsigned char Page, unsigned char Register);


/// �л���Ƶ��������͡�
/// \param [in] dwType ��������ͣ�ȡ�±��е�ֵ��
/// \retval 0  �л��ɹ���
/// \retval <0  �л�ʧ�ܡ�
int VideoSwitch(unsigned int dwType);
int VideoSwitchEx(unsigned int dwType, int channel);


/// ����TV����ı߽硣��Ƶ��ʾ��ĳЩ��������ʱ�� 4�����ϻ�����ʧ�����������Ŀ��
/// ��������4���߽�ѹ���ı�����ʹ��Ƶ���ڼ������Ŀ��������ڡ����ڷ�Χ0-100��һ��
/// ʾ��ֵ��ʵ���϶�Ӧ��С�ĳߴ���Ҫ�ڵײ���ת�������ơ�
/// 
/// \param [in] left ��߽���ʣ�ȡֵ0-100�� Ĭ��ֵΪ0��
/// \param [in] top �ϱ߽���ʣ�ȡֵ0-100�� Ĭ��ֵΪ0��
/// \param [in] right �ұ߽���ʣ�ȡֵ0-100�� Ĭ��ֵΪ0��
/// \param [in] bottom �±߽���ʣ�ȡֵ0-100�� Ĭ��ֵΪ0��
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
int VideoSetTVMargin(unsigned char left, unsigned char top, unsigned char right, unsigned char bottom);


/// ����TV�������ɫ��
/// 
/// \param [in] brightness ���ȣ�ȡֵ0-100�� Ĭ��ֵΪ50��
/// \param [in] contrast �Աȶȣ�ȡֵ0-100�� Ĭ��ֵΪ50��
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
int VideoSetTVColor(unsigned char brightness, unsigned char contrast);


/// ������Ƶ��������������͡�
/// 
/// \param [in] type ���������ͣ�ȡvideo_output_t���͵�ֵ��
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
int VideoSetOutputAdapter(unsigned char type);


/// ��ȡ��Ƶ��������������͡�
/// 
/// \param [out] ptype ���������ͣ�ȡvideo_output_t���͵�ֵ��
/// \retval 0  ��ȡ�ɹ���
/// \retval <0  ��ȡʧ�ܡ�
int VideoGetOutputAdapter(unsigned char *ptype);


/// ������Ƶ��������ͨ��������ͨ����
/// 
/// \param [in]  channelIn ��Ƶ����ͨ��
/// \param [in]  channelOut ��Ƶ���ͨ��
/// \retval 0  ��ȡ�ɹ���
/// \retval <0  ��ȡʧ�ܡ�
int VideoMatrix(unsigned char channelIn,unsigned char channelOut);


/// ����TV������
/// 
/// \param [in] open TRUE-��TV��������FALSE-��TV������
/// \retval 0  �����ɹ���
/// \retval <0  ����ʧ�ܡ�
int VideoSwitchTVMonitor(int open);


/// ����VGA������
/// 
/// \param [in] open TRUE-��VGA��������FALSE-��VGA������
/// \retval 0  �����ɹ���
/// \retval <0  ����ʧ�ܡ�
int VideoSwitchVGAMonitor(int open);

/// �õ���Ƶ֧�ֵ����ԡ�
/// 
/// \param [out] pCaps ָ����Ƶ���ԽṹVIDEO_CAPS��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval <0  ��ȡʧ�ܡ�
int VideoGetCaps(VIDEO_CAPS * pCaps);


/// ����û����Ƶ�ļ��ӻ���ı�����ɫ.
/// 
/// \param [in] color Ҫ���õ���ɫ��16���Ʊ�ʾΪ0x00BBGGRR������ֽڱ�����
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int VideoSetBkColor(unsigned int color);


typedef struct tagWHITE_LEVEL_CAPS //Added by wangjun2-20080805
{
	int	 enable;		// Ϊ1��ʾʹ�ܣ�Ϊ0ʱ��ʾ����
}WHITE_LEVEL_CAPS;

int WhiteLevelGetCaps(WHITE_LEVEL_CAPS * pCaps);


/// ����VGA��Ƶ�ֱ���
/// \param [in] resolution Ҫ���õ���Ƶ�ֱ���
/// \retval 0 �ɹ�
/// \retval < 0 ����ʧ��
/// \note Ŀǰ֧���������µķֱ��ʣ�800*600��1024*768��1280*1024��1366*768��1400*900
int VideoSetResolution(const VGA_RESOLUTION *resolution); 

enum Video_OUT_PRIORITY
{
	Video_OUT_PRIORITY_HDMI = 0,
	Video_OUT_PRIORITY_VGA = 1,
};

/// \priority ���ں�˼��ƽ̨����������ʹ��VGA  ���� HDMI,HDMI=0,VGA=1
int VideoSetResolutionV2(const VGA_RESOLUTION *resolution,int priority);

/// ��ȡ��ǰVGA��Ƶ�ֱ���
/// \param [out] resolution Ҫ���õ���Ƶ�ֱ���
/// \retval 0 �ɹ�
/// \retval < 0 ��ȡʧ��
/// \note Ŀǰ֧���������µķֱ��ʣ�800*600��1024*768��1280*1024��1366*768��1400*900
int VideoGetResolution(VGA_RESOLUTION *resolution); 

/*
*Peaking Filter contr
*/
typedef enum 
{
	M_PFC_Bypass = 0,
	M_2dB,
	M_3P5dB,
	M_6dB
}pic_ypfc_mode_t;

/*
*Low Pass Filter control 	 
*/
typedef enum 
{
	M_LPFC_Bypass = 0,
	M_4P2MHZ,
	M_5P6MHZ,
	M_7P2MHZ,
}pic_ylpfc_mode_t;

/*
*Selects the filter to separate the color 
*and brightness information out of the input signal(CVBS)
*/
typedef enum 
{
	M_APT_SPEC = 0,		//Adaptive Comb + special condition
	M_APT,				//Adaptive Comb
	M_2L_C12,			//2line comb (1,2 line)
	M_2L_C23,			//2line comb (2,3 line)
	M_3L_C123,		//3line comb (1,2,3 line)
	M_NOTCH,			//notch filter
	M_APT_NOTCH		//Adaptive comb + notch (auto select)
}pic_comb_mode_t;

/*
*FSC_LOCK_MODE
*/
typedef enum 
{
	M_CONTROL_ERR_0 = 0,
	M_CONTROL_ERR_1,
	M_CONTROL_ERR_2,
	M_CONTROL_ERR_3,
}pic_flerr_mode_t;

typedef enum 
{
	M_VALTER_SIG_GEN_0 = 0,
	M_VALTER_SIG_GEN_1,
	M_VALTER_SIG_GEN_2,
	M_VALTER_SIG_GEN_3
}pic_flgen_mode_t;




/*
*Locking speed control & Tracking Filter selection
*/
typedef enum 
{
	M_LSC_TFC_0 = 0,		//Bypass
	M_LSC_1,						//1/2 Cut
	M_LSC_2,						//1/4 Cut
	M_LSC_3,						//1/8 Cut
	M_LSC_4,						//1/16 Cut
	M_LSC_5,						//1/2 NO Cut
	M_LSC_6,						//1/4 NO Cut
	M_LSC_7,						//1/8 NO Cut
	M_LSC_8,						//1/16 NO Cut
	M_TFC_FASTEST,			//Fastest on Tracking Filter
	M_TFC_FAST,					//Fast on Tracking Filter
	M_TFC_NORMAL,				//Normal on Tracking Filter
	M_TFC_SLOW,					//Slow on Tracking Filter
	M_TFC_SLOWEST				//Slowest on Tracking Filter
}pic_fl_spd_mode_t;

/*
*H_V_SHARPNESS
*/
typedef enum 
{
	M_SHARPNESS_0X = 0,
	M_SHARPNESS_0P5X = 4,
	M_SHARPNESS_1X = 8,
	M_SHARPNESS_2X = 15
}pic_sharpness_mode_t;

/*
* IF Filter SEL
*/
typedef enum 
{
	M_IF_FILTER_BYPASS = 0,
	M_IF_FILTER_0,
	M_IF_FILTER_1,
	M_IF_FILTER_2
}pic_ciffl_mode_t;

/*
* CLP Filter SEL
*/
typedef enum 
{
	M_CLP_FILTER_BYPASS = 0,
	M_CLP_FILTER_0,
	M_CLP_FILTER_1,
	M_CLP_FILTER_2
}pic_clpfl_mode_t;

/*
* CKILL SEL
*/
typedef enum 
{
	M_CKC_BURST_FSC_0 = 0,
	M_CKC_BURST_FSC_1,
	M_CKC_BURST_FSC_2,
	M_CKC_BURST_FSC_3,
	M_CKC_ALWAYS_COLOR_ON,
	M_CKC_ALWAYS_COLOR_OFF,
}pic_ckill_mode_t;

typedef enum 
{
	M_WPD_COUNT_0 =0,
	M_WPD_COUNT_1,
	M_WPD_COUNT_2,
	M_WPD_COUNT_3,
	M_WPD_COUNT_4,
	M_WPD_COUNT_5
}pic_wpdctrl_stavalue_t;

typedef enum 
{
	M_WPD_SAMLEVEL_0 = 0,
	M_WPD_SAMLEVEL_1,
	M_WPD_SAMLEVEL_2,
	M_WPD_SAMLEVEL_3,
	M_WPD_SAMLEVEL_4,
	M_WPD_SAMLEVEL_5,
	M_WPD_SAMLEVEL_6,
	M_WPD_SAMLEVEL_7
}pic_wpdctrl_level_t;

enum pic_wpdmax_level_t
{
	M_WPD_MAX_LEVEL0 = 0,
	M_WPD_MAX_LEVEL1,
	M_WPD_MAX_LEVEL2,
};

typedef struct white_peak_control_t
{
	int swt;
	unsigned char wpd_maxlevel;
	unsigned char wpd_spd;
	pic_wpdctrl_stavalue_t wpd_count;
	pic_wpdctrl_level_t wpd_samlevel;
}white_peak_control;


/// ��Ƶͼ����չ������ʽ
typedef struct VIDEO_EXTPICPARAM{
	unsigned char				Cti;			///< ɫ��˲̬�����˲���,ȡ0/1ֵ��								
	pic_ypfc_mode_t		YPeakFilter;	///< ����ͨ�����ȼ���˲���ȡֵ0-3��
	pic_ylpfc_mode_t	YLowPassFilter;	///< ����ͨ�����ȵ�ͨ�˲���ȡֵ0-3��
	pic_comb_mode_t 	CombMode;		///< ����CVBS�ź�ɫ�Ⱥ����ȷ���ʱ�˲�ѡ��ȡֵ0-6��
	pic_flerr_mode_t 	FsclockerrMode;	///< ɫ���������ģʽѡ��ȡֵ0-3��
	pic_flgen_mode_t	FsclockgenMode;	///< ɫ����ѯ�źŲ���ģʽѡ��ȡֵ0-3��
	pic_fl_spd_mode_t 	FsclockSpd;		///< ɫ�������ٶ�ѡ��ȡֵ0-14��
	pic_ciffl_mode_t	CIFFilter;		///< ɫ���в��˲���ȡֵ0-3��
	pic_clpfl_mode_t	CLowPassFilter;	///< ɫ�ȵ�ͨ�˲���ȡֵ0-3��
	unsigned char	ColorKill;					///< ��ɫ���ƣ�bit3��λ��ʾ�����Զ�����.bit[0]-[2]��ɫģʽѡ��
	unsigned char	retention[32];
}VIDEO_EXTPICPARAM;

int VideoSetExPicParam(int channel, VIDEO_EXTPICPARAM * pExtpicparam);

/// ��Ƶͼ���ʽ
typedef struct VIDEO_PICTURE
{
	unsigned char Exfunc; ///< bit0: LTI,���ȶ����Թ��ɵĸĽ�
	///< bit1: CTI,ɫ�����Թ��ɵĸĽ�
	///< bit2: NEC3DCOMB,Select 3D Comb function on/off on NEC video decoder
	///< bit3: CROSSCOLOR,CCS(Cross Color Suppression) control
	///< bit4: Black & White level Extension/Suppression control
	unsigned char Edgeenhance; ///< Select direction of edge preserving deinterlace
	unsigned char Brightness; ///< ���ȣ�ȡֵ0-255��
	unsigned char Contrast; ///< �Աȶȣ�ȡֵ0-255��
	unsigned char  Saturation; ///< ���Ͷȣ�ȡֵ0-255��
	unsigned char  Hue; ///< ɫ����ȡֵ0-255��
	unsigned char  Sharpness; ///< ��ȣ�ȡֵ0-127��
	unsigned char  Reserve[16]; 
}VIDEO_PICTURE;

/// ��Ƶͼ�����д����ʽ
typedef struct VIDEO_DEINTERLACE{
	unsigned char Deintmode; ///< bit7:Select deinterlace mode (default : Adapt) 
	unsigned char Edgeangle; ///< bit0-3:Select direction of edge preserving deinterlace (default : All)
	unsigned char Motion; ///< bit0:For slow motion demo (default : On)
	///< bit1:Fast motion detection Control (default : Very Fast)
	///< bit2:Motion boundary preserving control (default : On)
	unsigned char Film; ///< bit0-3:Film mode detection Control (default : All)
	///< bit4:  Film bad edit detection and correction function. (default : On)
	unsigned char Nrset; ///< bit0-3:Select 3D Noise Reduction (default : Typ)
	///< bit4:  For noise robust 1 demo (default : On)
	///< bit5:  For noise robust 2 demo (default : On)
	unsigned char NrUltra; ///< UltraNR Level
	unsigned char Reserve[16]; 
}VIDEO_DEINTERLACE;

typedef struct VIDEO_TILOUTPUT
{
	unsigned char	hdelay;	    ///< ��0x00-0x7F��   ˮƽ����ǰ����ʱ��
	unsigned char	vdelay;		///< ��0x00-0x2F��	 ��ֱ����ǰ����ʱ��
	unsigned char	hblkend;	///< ��0x00-0x5F��	 ˮƽ��������ʱ��
	unsigned char	vblkend;	///< ��0x00-0x3F��	 ��ֱ��������ʱ��
}VIDEO_TILOUTPUT;

/// ����ǰ��ͼ�����ʱ��
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pTiloutput ָ��ͼ�����ʱ��ṹVIDEO_TILOUTPUT��ָ�롣
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
int VideoSetTilOutput(int channel, VIDEO_TILOUTPUT *pTiloutput);


enum ad_type
{
	AD_NVP1108 = 0,
	AD_NVP1104B,
	AD_NVP1114A,
	AD_CX25824,
	AD_CX25828,
	AD_TW2868,
	AD_TW2866,	//TW2867,TW2865
	AD_BUFF_TYPE
};

enum ad_color
{
	COLOR_BRIGHTNESS = 0,
	COLOR_CONTRAST,
	COLOR_SATURATION,
	COLOR_HUE,
	COLOR_GAIN,
	COLOR_SHARPNESS,        //���
	COLOR_WHITEBALANCE,     //��ƽ��
	COLOR_BUFF_TYPE
};

enum ad_tioutput
{
	TIOUTPUT_H = 0,
	TIOUTPUT_V,
	TIOUTPUT_BUFF_TYPE
};

enum ad_alarm
{
	AD_VIDEOMOTIONDETECL= 0,	//�ƶ����
	AD_VIDEOLOSSDETECL,			//��Ƶ��ʧ
	AD_VIDEOBINDDETECL,			//��Ƶ�ڵ�
	AD_DETECT_TYPE
};

/// ����AD֧�ֵĹ���
typedef struct AD_CAPTION {
	int	ad_type;						///< AD���͡�
	int	audio_volume_en;				///< ��������֧�֣�֧��1����֧��0
	int	audio_volume_cap;				///< �������������������ֵ��
	int colorcaps;						///< ͼ�����֧�����ͣ�ÿһλ��ʾ���ڵĹ���
	int tioutputcaps;					///< �ڱߵ���֧�����ͣ�
	int tioutput_hvalue;				///< �ڱߵ���ˮƽ����ֵ��Χ
	int tioutput_vvalue;				///< �ڱߵ��ڴ�ֱ����ֵ��Χ
	int ad_alarm_caps;					///< ǰ�˱���֧�����ͣ�ÿһλ��ʾ֧�ֵĹ���
} AD_CAPTION;

int VideoGetADecodeCaption(AD_CAPTION *adcaption); 


/*******************************************************************
 * �������ƣ�VoSetColor
 * �������ܣ�����vo �豸����ɫ
 * ���������vodev -- vo�豸��
 				    pVoCsc -- ��Ӧ����ɫֵ
 * �����������
 * ����ֵ��  0	-- �ɹ�
 *       			 -1	-- ʧ��
 ******************************************************************/
typedef struct tagVOCSC
{
	unsigned char lum;// ���� 0 -100
	unsigned char con;//�Աȶ� 0-100
	unsigned char hue;//ɫ�� 0-100
	unsigned char sat;//���Ͷ� 0 -100
	int resv[3];
}VOCSC;

int VoSetColor(int vodev, VOCSC *pVoCsc);

/*******************************************************************
 * �������ƣ�VoGetColor
 * �������ܣ���ȡvo �豸����ɫ
 * ���������vodev -- vo�豸��
 				    pVoCsc -- ��Ӧ����ɫֵ
 * �����������
 * ����ֵ��  0	-- �ɹ�
 *       			 -1	-- ʧ��
 ******************************************************************/
int VoGetColor(int vodev, VOCSC *pVoCsc);


/// @} end of group


#ifdef __cplusplus
}
#endif

#endif 
