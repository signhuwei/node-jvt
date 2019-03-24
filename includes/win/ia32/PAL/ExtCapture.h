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
/// ƴͼ����������Ƶ����ӿڣ�������Memory�ӿڡ�
///	\n ��������ͼ:
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

/// ���DSP�ı�������
///
int ExCaptureGetDspInfoEx(CAPTURE_DSPINFO *pDspInfo);
/// �õ���չ�����ͨ����Ŀ�����������������ͨ�������������ͨ������󲶻�ͨ���ż�1��
/// 
/// \return�����ͨ����Ŀ��
int ExCaptureGetChannelsEx(void);


/// �õ�����֧�ֵ����ԡ�
/// 
/// \param [out] pCaps ָ�򲶻����ԽṹCAPTURE_CAPS��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval 0  ��ȡʧ�ܡ�
int ExCaptureGetCapsEx(CAPTURE_CAPS * pCaps);


/// �õ�����˫����֧�ֵ����ԡ�������CaptureGetCapsһ�������õ�����˫����֧�ֵ����ԣ�
/// ��������ͨ�������ԡ� 
/// 
/// \param [out] pCaps ָ�򲶻����ԽṹCAPTURE_CAPS��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval 0  ��ȡʧ�ܡ�
int ExCaptureGetExtCapsEx(CAPTURE_EXT_STREAM *pCaps);


/// ���������豸
/// 
/// \param [in] channel ͨ���š�
/// \retval 0 ����ʧ��
/// \retval 0 �����ɹ�
int ExCaptureCreateEx(int channel);


/// ���ٲ����豸
/// 
/// \param [in] channel ͨ���š�
/// \retval 0 ����ʧ��
/// \retval 0 ���ٳɹ�
int ExCaptureDestroyEx(int channel);


/// Ӧ�ó���ʱ���ã� ֪ͨ����ģ��������״̬�� ����д��� ����ģ�顣 
/// 
void ExCaptureSynchronizeEx(void);


/// ������Ƶ��ʽ��
/// 
/// \param [in]  channel ͨ���š�
/// \param [in]  dwStandard ��Ƶ��ʽ��ȡvideo_standard_t���͵�ֵ��
/// \retval 0  ���óɹ�
/// \retval 0  ����ʧ��
int ExCaptureSetVstdEx(int channel,unsigned int dwStandard);	


/// ���ò���ʱ��͸�ʽ��Ӧ�ó�����Ҫ��ʱ���ô˺����벶���ʱ�����ͬ����
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pTime ָ��ϵͳʱ��ṹSYSTEM_TIME��ָ�롣
/// \param [in] datefmt ���ڸ�ʽ��ȡdate_fmtö��ֵ��
/// \param [in] datespc ���ڷָ����ȡdate_specö��ֵ��
/// \param [in] timefmt ʱ���ʽ��ȡtime_fmtö��ֵ��
/// \retval 0  ���óɹ���
/// \retval 0  ����ʧ�ܡ�
int ExCaptureSetTimeEx(int channel, const SYSTEM_TIME * pTime, int datefmt,int datespc,int timefmt);


/// ���ñ�����ӡ�
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pParam ָ�������ӽṹCAPTURE_TITLE_PARAM��ָ�롣
/// \retval 0  ���óɹ���
/// \retval 0  ����ʧ�ܡ�
int ExCaptureSetTitleEx(int channel, CAPTURE_TITLE_PARAM *pParam);


/// ���ø�������
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pParam ָ����Ƶ���ǽṹVIDEO_COVER_PARAM��ָ�롣
/// \retval 0  ���óɹ���
/// \retval 0  ����ʧ�ܡ�
int ExCaptureSetCoverEx(int channel,int index, struct VIDEO_COVER_PARAM *pParam);



/// ���ò����������
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwLVolume ������������ȡֵ0-100��
/// \param [in] dwRVolume ������������ȡֵ0-100��
/// \retval 0  ���óɹ�
/// \retval 0  ����ʧ��
int ExCaptureSetVolumeEx(int channel, unsigned int dwLVolume, unsigned int dwRVolume);


/// ǿ�Ʊ���������I֡�� 
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwType
/// \retval 0  ���óɹ���
/// \retval 0  ����ʧ�ܡ�
int ExCaptureForceIFrameEx(int  channel, unsigned int dwType);


/// ���ò�������ѹ���ĸ�ʽ��
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwType
/// \param [in] pFormat ָ�򲶻��ʽ�ṹCAPTURE_FORMAT��ָ�롣
/// \retval 0  ���óɹ�
/// \retval 0  ����ʧ��
int ExCaptureSetFormatEx(int channel, unsigned int dwType, CAPTURE_FORMAT * pFormat);


/// ��ʼ���롣����Ƶ��ʽ������ѡ�ͼ��������֡�ʡ��������Ʒ�ʽ���ֱ��ʡ�����
/// ģʽ�Ȳ������ı�ʱ��Ӧ�ó����ֹͣ����Ȼ�����¿�ʼ����
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwType ������ʾ���������ѡ���capture_start_t���͵�ֵ����ϡ�
/// \retval 0  ��ʼ�ɹ�
/// \retval 0  ��ʼʧ��
int ExCaptureStartEx(int  channel, unsigned int dwType);


/// ֹͣ���룬��ǰ�����������ء�
/// 
/// \param [in]  channel ͨ���š�
/// \param [in]  dwType
/// \retval 0  ֹͣ�ɹ�
/// \retval 0  ֹͣʧ��
int ExCaptureStopEx(int  channel, unsigned int dwType);


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
int ExCaptureGetBufferEx(int *pchannel, unsigned int *pdwType, void* *phMemory);


/// �Ա���ͨ�����������������ϡ������ɶ��ͨ������Ƶ�����ϳ�һ��������档
/// 
/// \param [in] channel ����ͨ����
/// \param [in] dwMode ����е�ͨ����Ŀ��ȡsplitt���͵�ֵ��
/// \param [in] dwIndex ��ǰͨ����Ŀ����Ϸ�ʽ����š�
/// \retval 0  ���óɹ���
/// \retval <0  ����ʧ�ܡ�
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

