//
//  "$Id: ExtCapture.h 1759 2011-07-09 10:43:15Z chenchangbao $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//


#ifndef __PAL_EXTCAPTURE_H__
#define __PAL_EXTCAPTURE_H__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup ExCaptureAPI API Capture
/// 拼图编码流音视频编码接口，依赖于Memory接口。
///	\n 调用流程图:
/// \code
///    ============================================
///                   	|                            
///             ExCaptureCreate             
///       +-----------|------------------------+         
///       |     ExCaptureSetVstd        CaptureGetChannels
///		  |				|               CaptureGetDspInfo,
///       |   	ExCaptureSetFormat		CaptureGetCaps,
///    	  |	ExCaptureSetPacketPolicy	CaptureGetExtCaps      
///       |           	|				CaptureSetTime   	 
///       |     ExCaptureStart     		CaptureSetTitle   
///       | +-----------|          		CaptureSetCover   
///       | |  ExCaptureGetBuffer  		ExCaptureSetVolume  
///       | | ExCaptureForceIFrame 		ExCaptureSynchronize
///       | |  ExCaptureGetVolume              |         
///       | +----------|                       |         
///       |      ExCaptureStop                 |         
///       +------------|-----------------------+         
///           ExCaptureDestroy                       
///                    |                            
///    ============================================

struct CAPTURE_CAPS;
struct CAPTURE_FORMAT;
struct CAPTURE_TITLE_PARAM;
struct CAPTURE_DSPINFO;
struct CAPTURE_EXT_STREAM;
struct VIDEO_COVER_PARAM;

/// 获得DSP的编码能力
///
int ExCaptureGetDspInfoEx(CAPTURE_DSPINFO *pDspInfo);
/// 得到扩展捕获的通道数目。不包括语音捕获的通道，语音捕获的通道是最大捕获通道号加1。
/// 
/// \return捕获的通道数目。
int ExCaptureGetChannelsEx(void);


/// 得到捕获支持的特性。
/// 
/// \param [out] pCaps 指向捕获特性结构CAPTURE_CAPS的指针。
/// \retval 0  获取成功。
/// \retval 0  获取失败。
int ExCaptureGetCapsEx(CAPTURE_CAPS * pCaps);


/// 得到捕获双码流支持的特性。参数和CaptureGetCaps一样，但得到得是双码流支持得特性，
/// 而不是普通编码特性。 
/// 
/// \param [out] pCaps 指向捕获特性结构CAPTURE_CAPS的指针。
/// \retval 0  获取成功。
/// \retval 0  获取失败。
int ExCaptureGetExtCapsEx(CAPTURE_EXT_STREAM *pCaps);


/// 创建捕获设备
/// 
/// \param [in] channel 通道号。
/// \retval 0 创建失败
/// \retval 0 创建成功
int ExCaptureCreateEx(int channel);


/// 销毁捕获设备
/// 
/// \param [in] channel 通道号。
/// \retval 0 销毁失败
/// \retval 0 销毁成功
int ExCaptureDestroyEx(int channel);


/// 应用程序定时调用， 通知捕获模块检测自身状态， 如果有错误， 重启模块。 
/// 
void ExCaptureSynchronizeEx(void);


/// 设置视频制式。
/// 
/// \param [in]  channel 通道号。
/// \param [in]  dwStandard 视频制式，取video_standard_t类型的值。
/// \retval 0  设置成功
/// \retval 0  设置失败
int ExCaptureSetVstdEx(int channel,unsigned int dwStandard);	


/// 设置捕获时间和格式。应用程序需要定时调用此函数与捕获的时间进行同步。
/// 
/// \param [in] channel 通道号。
/// \param [in] pTime 指向系统时间结构SYSTEM_TIME的指针。
/// \param [in] datefmt 日期格式，取date_fmt枚举值。
/// \param [in] datespc 日期分割符，取date_spec枚举值。
/// \param [in] timefmt 时间格式，取time_fmt枚举值。
/// \retval 0  设置成功。
/// \retval 0  设置失败。
int ExCaptureSetTimeEx(int channel, const SYSTEM_TIME * pTime, int datefmt,int datespc,int timefmt);


/// 设置标题叠加。
/// 
/// \param [in] channel 通道号。
/// \param [in] pParam 指向标题叠加结构CAPTURE_TITLE_PARAM的指针。
/// \retval 0  设置成功。
/// \retval 0  设置失败。
int ExCaptureSetTitleEx(int channel, CAPTURE_TITLE_PARAM *pParam);


/// 设置覆盖区域。
/// 
/// \param [in] channel 通道号。
/// \param [in] pParam 指向视频覆盖结构VIDEO_COVER_PARAM的指针。
/// \retval 0  设置成功。
/// \retval 0  设置失败。
int ExCaptureSetCoverEx(int channel,int index, struct VIDEO_COVER_PARAM *pParam);



/// 设置捕获的音量。
/// 
/// \param [in] channel 通道号。
/// \param [in] dwLVolume 左声道音量，取值0-100。
/// \param [in] dwRVolume 右声道音量，取值0-100。
/// \retval 0  设置成功
/// \retval 0  设置失败
int ExCaptureSetVolumeEx(int channel, unsigned int dwLVolume, unsigned int dwRVolume);


/// 强制编码器产生I帧。 
/// 
/// \param [in] channel 通道号。
/// \param [in] dwType
/// \retval 0  设置成功。
/// \retval 0  设置失败。
int ExCaptureForceIFrameEx(int  channel, unsigned int dwType);


/// 设置捕获数据压缩的格式。
/// 
/// \param [in] channel 通道号。
/// \param [in] dwType
/// \param [in] pFormat 指向捕获格式结构CAPTURE_FORMAT的指针。
/// \retval 0  设置成功
/// \retval 0  设置失败
int ExCaptureSetFormatEx(int channel, unsigned int dwType, CAPTURE_FORMAT * pFormat);


/// 开始编码。在视频制式、捕获选项、图像质量、帧率、码流控制方式、分辨率、编码
/// 模式等参数被改变时，应用程序会停止捕获，然后重新开始捕获。
/// 
/// \param [in] channel 通道号。
/// \param [in] dwType 参数表示启动捕获的选项，是capture_start_t类型的值的组合。
/// \retval 0  开始成功
/// \retval 0  开始失败
int ExCaptureStartEx(int  channel, unsigned int dwType);


/// 停止编码，当前操作立即返回。
/// 
/// \param [in]  channel 通道号。
/// \param [in]  dwType
/// \retval 0  停止成功
/// \retval 0  停止失败
int ExCaptureStopEx(int  channel, unsigned int dwType);


/// 读取采样数据，读为阻塞超时模式。内存块由设备申请和填充，设备得到适当的数据
/// 后返回。超时时立即返回；若内存块中已经填充数据，则设置实际的数据长度并返回；
/// 若内存块中没有数据，返回错误；将超时时间设置的较小，可以提高数据的实时性。
/// 
/// \param [in] pchannel 通道号，-1表示读所有通道的数据，读到的通道号作为函数
///        返回值返回。
/// \param [in] pdwType
/// \param [out] phMemory 内存块句柄指针，用来保存取到的内存块句柄。内存块的实际数据长
///        度表示捕获到的数据长度。
/// \return>=0 通道号（在输入通道号为-1时）
/// \retval 0  读成功
/// \retval 0  读失败
int ExCaptureGetBufferEx(int *pchannel, unsigned int *pdwType, void* *phMemory);


/// 对编码通道的输出进行排列组合。可以由多个通道的视频输出组合成一个输出画面。
/// 
/// \param [in] channel 编码通道号
/// \param [in] dwMode 组合中的通道数目，取splitt类型的值。
/// \param [in] dwIndex 当前通道数目下组合方式的序号。
/// \retval 0  设置成功。
/// \retval <0  设置失败。
int ExCaptureCombineEx(int channel, unsigned int dwMode, unsigned int dwIndex);


typedef struct EXCAPTURE_CAPS
{
	int Enable;
} EXCAPTURE_CAPS;
int ExCaptureCreate(int channel);
int ExCaptureDestory(int channel);
int ExCaptureStart(unsigned int dwFlags);
int ExCaptureStop(void);
int ExCaptureSetVstd(unsigned int dwStandard);	
int ExCaptureGetBufferSize (unsigned int * pCount);
int ExCaptureGetBuffer (unsigned char * pBuffer, unsigned int dwCount);

#ifdef __cplusplus
}
#endif

#endif

