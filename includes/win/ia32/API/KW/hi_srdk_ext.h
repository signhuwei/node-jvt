
/******************************************************************************
 *	File Name		: hi_srdk_ext.h
 *	Description		: SRDK API Header file
 *	Version			: Initial Draft
 *	Author			: LAN CASTLE Technologies Co., LTD
 *	Created			: 	
 *	History			:
 *	  1.Date			: 2010/09/15
 *		Author			: 
 *		Modification	: Created file
 ******************************************************************************/



#ifndef __HI_SRDK_EXT_H__
#define __HI_SRDK_EXT_H__

#include "hi_srdk_define.h"
#define WINAPI __stdcall



/******************************************************************************
 * API Function Declaration
 ******************************************************************************/


/*----------------------------------------------------------------------------
 \brief set the encryption property of the stream
 \attention  no

 \param[in] HI_S32 s32StreamType 			stream type(main stream,sub stream,see HI_CFG_STREAM_TYPE_E)
 \param[in] HI_CFG_ENCRYPT_S astAttr[]		encryption property
 \param[in] HI_S32 s32ChnCnt				channel count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_GetStreamEncryptAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_SetStreamEncryptAttr(HANDLE DvrHandle, HI_S32 s32StreamType, const HI_CFG_ENCRYPT_S astAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get the encryption property of the stream
 \attention no

 \param[in] 	HI_S32 s32StreamType 			stream type(main stream,sub stream,see HI_CFG_STREAM_TYPE_E)
 \param[out] 	HI_CFG_ENCRYPT_S astAttr[]		encryption property
 \param[in] 	HI_S32 *ps32ChnCnt				channel count
 \param[out] 	HI_S32 *ps32ChnCnt				return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_SetStreamEncryptAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_GetStreamEncryptAttr(HANDLE DvrHandle, HI_S32 s32StreamType, HI_CFG_ENCRYPT_S astAttr[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
 \brief set the property of the video
 \attention no

 \param[in] HI_S32 s32StreamType 			    stream type(main stream,sub stream,see HI_CFG_STREAM_TYPE_E)
 \param[in] HI_CFG_VIDEO_ATTR_S astAttr[]	    video property
 \param[in] HI_S32 s32ChnCnt				    channel count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_GetVideoAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_SetVideoAttr(HANDLE DvrHandle, HI_S32 s32StreamType, const HI_CFG_VIDEO_ATTR_S astAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get the property of the video
 \attention no

 \param[in]    	HI_S32 s32StreamType 			stream type(main stream,sub stream,see HI_CFG_STREAM_TYPE_E)
 \param[out]  	HI_CFG_VIDEO_ATTR_S astAttr[]	video property
 \param[in] 	HI_S32 *ps32ChnCnt				channel count
 \param[out] 	HI_S32 *ps32ChnCnt				return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_SetVideoAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_GetVideoAttr(HANDLE DvrHandle, HI_S32 s32StreamType, HI_CFG_VIDEO_ATTR_S astAttr[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
 \brief set the property of the audio
 \attention no

 \param[in]	HI_S32 s32StreamType 				stream type(main stream,sub stream,see HI_CFG_STREAM_TYPE_E)
 \param[in]	HI_CFG_AUDIO_ATTR_S astAttr[]		audio property
 \param[in]	HI_S32 s32ChnCnt					channel count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_GetAudioAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_SetAudioAttr(HANDLE DvrHandle, HI_S32 s32StreamType, const HI_CFG_AUDIO_ATTR_S astAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get the property of the audio
 \attention no

 \param[in]    	HI_S32 s32StreamType 			stream type(main stream,sub stream,see HI_CFG_STREAM_TYPE_E)
 \param[out] 	HI_CFG_AUDIO_ATTR_S astAttr[]	audio property
 \param[in] 	HI_S32 *ps32ChnCnt				channel count
 \param[out] 	HI_S32 *ps32ChnCnt				return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_SetAudioAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_GetAudioAttr(HANDLE DvrHandle, HI_S32 s32StreamType, HI_CFG_AUDIO_ATTR_S astAttr[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
 \brief set watermark property
 \attention no

 \param[in]    	HI_S32 s32StreamType 		    stream type(main stream,sub stream,see HI_CFG_STREAM_TYPE_E)
 \param[in] 	HI_CFG_WATERMARK_S astAttr[]	watermark property
 \param[in]	    HI_S32 s32ChnCnt				channel count

 \retval ::HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_GetWaterMarkAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_SetWaterMarkAttr(HANDLE DvrHandle, HI_S32 s32StreamType, const HI_CFG_WATERMARK_S astAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get watermark property
 \attention no

 \param[in]     HI_S32 s32StreamType 			stream type(main stream,sub stream,see HI_CFG_STREAM_TYPE_E)
 \param[out]    HI_CFG_WATERMARK_S astAttr[]	watermark property
 \param[in] 	HI_S32 *ps32ChnCnt				channel count
 \param[out] 	HI_S32 *ps32ChnCnt				return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_SetWaterMarkAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_GetWaterMarkAttr(HANDLE DvrHandle, HI_S32 s32StreamType, HI_CFG_WATERMARK_S astAttr[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
 \brief set bind(A/V) property
 \attention no

 \param[in] HI_CFG_AV_BIND_S astAttr[]	bind(A/V) property
 \param[in] HI_S32 s32ChnCnt			channel count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_GetAVBindAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_SetAVBindAttr(HANDLE DvrHandle, const HI_CFG_AV_BIND_S astAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get bind(A/V) property
 \attention no

 \param[out]    HI_CFG_AV_BIND_S astAttr[]	    bind(A/V) property
 \param[in] 	HI_S32 *ps32ChnCnt				channel count
 \param[out] 	HI_S32 *ps32ChnCnt				return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_MEDIA_SetAVBindAttr
 -----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_GetAVBindAttr(HANDLE DvrHandle, HI_CFG_AV_BIND_S astAttr[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
\brief set OSD, Cover, Overlay
\attention no

\param[in] HI_CFG_OSD_CHN_S astOsdAttr[]	property of Vi OSD, Cover, Overlay, VO OSD
\param[in] HI_S32 s32ChnCnt					channel count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_MEDIA_GetOsd
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_SetOsd(HANDLE DvrHandle, const HI_CFG_OSD_CHN_S astOsdAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
\brief get OSD, Cover, Overlay
\attention no

\param[out]     HI_CFG_OSD_CHN_S astOsdAttr[]   property of Vi OSD, Cover, Overlay, VO OSD
\param[in] 		HI_S32 *ps32ChnCnt				channel count
\param[out] 	HI_S32 *ps32ChnCnt				return member(channel) count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_MEDIA_SetOsd
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_GetOsd(HANDLE DvrHandle, HI_CFG_OSD_CHN_S astOsdAttr[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
\brief set display property
\attention no

\param[in] HI_CFG_DISPLAYERDEV_ATTR_S astDevDispAttr[]		display property
\param[in] HI_S32 s32DevCnt									device count,<=HI_CFG_DISPLAYER_DEV_BUTT

\retval HI_SUCCESS

\see 
    ::HI_SRDK_MEDIA_GetDevDisplayerAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_SetDevDisplayerAttr(HANDLE DvrHandle, const HI_CFG_DISPLAYERDEV_ATTR_S astDevDispAttr[], HI_S32 s32DevCnt);


/*----------------------------------------------------------------------------
\brief get diaplay property
\attention no

\param[out] HI_CFG_DISPLAYERDEV_ATTR_S astDevDispAttr[]		display property
\param[in] HI_S32 *ps32DevCnt								device count,<=HI_CFG_DISPLAYER_DEV_BUTT
\param[out] HI_S32 *ps32DevCnt								return member(device) count

\retval HI_SUCCESS 

\see 
    ::HI_SRDK_MEDIA_SetDevDisplayerAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_GetDevDisplayerAttr(HANDLE DvrHandle, HI_CFG_DISPLAYERDEV_ATTR_S astDevDispAttr[], HI_S32 *ps32DevCnt);


/*----------------------------------------------------------------------------
\brief set channel property
\attention no

\param[in] HI_CFG_CHNDISPLAYER_ATTR_S astChnDisplayAttr[]	channel property,<=HI_CFG_MAX_CHN
\param[in] HI_S32 s32ChnCnt									channel count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_MEDIA_GetChnDisp
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_SetChnDisp(HANDLE DvrHandle, const HI_CFG_CHNDISPLAYER_ATTR_S astChnDisplayAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
\brief get channel property
\attention no

\param[out] HI_CFG_CHNDISPLAYER_ATTR_S astChnDisplayAttr[]  channel property,<=HI_CFG_MAX_CHN
 \param[in] 	HI_S32 *ps32ChnCnt							channel count
 \param[out] 	HI_S32 *ps32ChnCnt							return member(channel) count

\retval HI_SUCCESS 

\see 
    ::HI_SRDK_MEDIA_SetChnDisp
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_GetChnDisp(HANDLE DvrHandle, HI_CFG_CHNDISPLAYER_ATTR_S astChnDisplayAttr[],  HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
\brief set audio output property
\attention no

\param[in] HI_CFG_AO_ARRT_S astAoAttr[]		audio output property,<=HI_CFG_MAX_CHN
\param[in] HI_S32 s32ChnCnt					channel count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_MEDIA_GetAoAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_SetAoAttr(HANDLE DvrHandle, const HI_CFG_AO_ARRT_S astAoAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
\brief get audio output property
\attention no

\param[out] HI_CFG_AO_ARRT_S astAoAttr[]	audio output property,<=HI_CFG_MAX_CHN
 \param[in] 	HI_S32 *ps32ChnCnt			channel count
 \param[out] 	HI_S32 *ps32ChnCnt			return member(channel) count

\retval HI_SUCCESS 

\see 
    ::HI_SRDK_MEDIA_SetAoAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_MEDIA_GetAoAttr(HANDLE DvrHandle, HI_CFG_AO_ARRT_S astAoAttr[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
\brief set GUI property
\attention no

\param[in] HI_CFG_GUI_ATTR_S *pstGuiAttr	GUI property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_GUI_GetAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_GUI_SetAttr(HANDLE DvrHandle, const HI_CFG_GUI_ATTR_S *pstGuiAttr);


/*----------------------------------------------------------------------------
\brief get GUI property
\attention no

\param[out] HI_CFG_GUI_ATTR_S *pstGuiAttr	GUI property

\retval HI_SUCCESS 

\see 
    ::HI_SRDK_GUI_SetAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_GUI_GetAttr(HANDLE DvrHandle, HI_CFG_GUI_ATTR_S *pstGuiAttr);


/*----------------------------------------------------------------------------
 \brief set record property
 \attention no

 \param[in] HI_CFG_RECORDCHNATTR_S astMode[]	record mode
 \param[in] HI_S32 s32ChnCnt					channel count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_RECORDER_GetRecordAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_RECORDER_SetRecordAttr(HANDLE DvrHandle, const HI_CFG_RECORDCHNATTR_S astMode[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get record property
 \attention no

 \param[out] HI_CFG_RECORDCHNATTR_S astMode[]	record mode
 \param[in]  HI_S32 *ps32ChnCnt					channel count
 \param[out] HI_S32 *ps32ChnCnt					return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_RECORDER_SetRecordAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_RECORDER_GetRecordAttr(HANDLE DvrHandle, HI_CFG_RECORDCHNATTR_S astMode[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
 \brief set record schedule
 \attention no

 \param[in] HI_CFG_RECORDCHNSCHEDULE_S astSchedule[]	record schedule
 \param[in] HI_S32 s32ChnCnt							channel count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_RECORDER_GetRecordSchedule
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_RECORDER_SetRecordSchedule(HANDLE DvrHandle, const HI_CFG_RECORDCHNSCHEDULE_S astSchedule[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get record schedule
 \attention no

 \param[out] HI_CFG_RECORDCHNSCHEDULE_S astSchedule[]	record schedule
 \param[in] HI_S32 *ps32ChnCnt							channel count
 \param[out] HI_S32 *ps32ChnCnt							return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_RECORDER_SetRecordSchedule
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_RECORDER_GetRecordSchedule(HANDLE DvrHandle, HI_CFG_RECORDCHNSCHEDULE_S astSchedule[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
 \brief set playback property
 \attention no

 \param[in] HI_CFG_PLAYBACK_ATTR_S astAttr[]	playback property
 \param[in] HI_S32 s32ChnCnt					channel count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_RECORDER_SetPlaybackAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_RECORDER_SetPlaybackAttr(HANDLE DvrHandle, const HI_CFG_PLAYBACK_ATTR_S astAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get playback property
 \attention no

 \param[out] HI_CFG_PLAYBACK_ATTR_S astAttr[]		playback property
 \param[in]    HI_S32 *ps32ChnCnt					channel count
 \param[out] HI_S32 *ps32ChnCnt			         	return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_RECORDER_GetPlaybackAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_RECORDER_GetPlaybackAttr(HANDLE DvrHandle, HI_CFG_PLAYBACK_ATTR_S astAttr[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
 \brief set alarm in property
 \attention no

 \param[in] HI_CFG_ALARM_IN_ATTR_S* pstAttr   alarm property

 \retval HI_SUCCESS   

 \see 
   ::HI_SRDK_ALARM_GetAlarmInAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_ALARM_SetAlarmInAttr(HANDLE DvrHandle, const HI_CFG_ALARM_IN_ATTR_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief get alarm in property
 \attention no

 \param[out] HI_CFG_ALARM_IN_ATTR_S* pstAttr	alarm property

 \retval ::HI_SUCCESS

 \see 
   ::HI_SRDK_ALARM_SetAlarmInAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_ALARM_GetAlarmInAttr(HANDLE DvrHandle, HI_CFG_ALARM_IN_ATTR_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief set alarm out property
 \attention no

 \param[in] HI_CFG_ALARM_OUT_ATTR_S* pstAttr   alarm property

 \retval ::HI_SUCCESS

 \see 
   ::HI_SRDK_ALARM_GetAlarmOutAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_ALARM_SetAlarmOutAttr(HANDLE DvrHandle, const HI_CFG_ALARM_OUT_ATTR_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief get alarm out property
 \attention no

 \param[out] HI_CFG_ALARM_OUT_ATTR_S* pstAttr	alarm property

 \retval HI_SUCCESS

 \see 
   ::HI_SRDK_ALARM_SetAlarmOutAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_ALARM_GetAlarmOutAttr(HANDLE DvrHandle, HI_CFG_ALARM_OUT_ATTR_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief set alarm in schedule
 \attention no

 \param[in] HI_S32 s32AlarmType						alarm type,see HI_CFG_ALARM_TYPE_E
 \param[in] HI_CFG_ALARM_SCHEDULE_S* pstSchedule	alarm schedule

 \retval HI_SUCCESS

 \see 
   ::HI_SRDK_ALARM_GetAlarmInSchedule
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_ALARM_SetAlarmInSchedule(HANDLE DvrHandle, HI_S32 s32AlarmType, const HI_CFG_ALARM_SCHEDULE_S* pstSchedule);


/*----------------------------------------------------------------------------
 \brief get alarm in schedule
 \attention no

 \param[in] HI_S32 s32AlarmType						alarm type,see HI_CFG_ALARM_TYPE_E
 \param[out] HI_CFG_ALARM_SCHEDULE_S* pstSchedule	alarm schedule

 \retval HI_SUCCESS

 \see 
   ::HI_SRDK_ALARM_SetAlarmInSchedule
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_ALARM_GetAlarmInSchedule(HANDLE DvrHandle, HI_S32 s32AlarmType, HI_CFG_ALARM_SCHEDULE_S* pstSchedule);


/*----------------------------------------------------------------------------
 \brief set alarm out schedule
 \attention no

 \param[in] HI_S32 s32AlarmType						alarm type,see HI_CFG_ALARM_TYPE_E
 \param[in] HI_CFG_ALARM_SCHEDULE_S* pstSchedule	alarm schedule

 \retval HI_SUCCESS

 \see 
   ::HI_SRDK_ALARM_GetAlarmOutSchedule
 */
HI_S32 WINAPI HI_SRDK_ALARM_SetAlarmOutSchedule(HANDLE DvrHandle, HI_S32 s32AlarmType, const HI_CFG_ALARM_SCHEDULE_S* pstSchedule);


/*----------------------------------------------------------------------------
 \brief get alarm out schedule
 \attention no

 \param[in] HI_S32 s32AlarmType						alarm type,see HI_CFG_ALARM_TYPE_E
 \param[out] HI_CFG_ALARM_SCHEDULE_S* pstSchedule	alarm schedule

 \retval HI_SUCCESS

 \see 
   ::HI_SRDK_ALARM_SetAlarmOutSchedule
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_ALARM_GetAlarmOutSchedule(HANDLE DvrHandle, HI_S32 s32AlarmType, HI_CFG_ALARM_SCHEDULE_S* pstSchedule);


/*----------------------------------------------------------------------------
 \brief set motion detect property
 \attention no

 \param[in] HI_CFG_MD_ATTR_S astMotionDetect[]	MD property
 \param[in] HI_S32 s32ChnCnt					channel count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_ALARM_GetMDAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_ALARM_SetMDAttr(HANDLE DvrHandle, const HI_CFG_MD_ATTR_S astMotionDetect[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get motion detect property
 \attention no

 \param[out] HI_CFG_MD_ATTR_S astMotionDetect[]		MD property
 \param[in] HI_S32 *ps32ChnCnt						channel count
 \param[out] HI_S32 *ps32ChnCnt						return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_ALARM_SetMDAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_ALARM_GetMDAttr(HANDLE DvrHandle, HI_CFG_MD_ATTR_S astMotionDetect[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
\brief set webserver port
\attention no

\param[in] HI_U16 u16Port		webserver port

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_GetWebServerPort
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_SetWebServerPort(HANDLE DvrHandle, HI_U16 u16Port);


/*----------------------------------------------------------------------------
\brief get webserver port
\attention no

\param[out] HI_U16 *pu16Port   webserver port

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_SetWebServerPort
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_GetWebServerPort(HANDLE DvrHandle, HI_U16 *pu16Port);


/*----------------------------------------------------------------------------
\brief set mctp server port
\attention no

\param[in] HI_U16 u16Port   mctp server port

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_GetMctpServerPort
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_SetMctpServerPort(HANDLE DvrHandle, HI_U16 u16Port);


/*----------------------------------------------------------------------------
\brief get mctp server port
\attention no

\param[out] HI_U16 *pu16Port   mctp server port

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_SetMctpServerPort
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_GetMctpServerPort(HANDLE DvrHandle, HI_U16 *pu16Port);


/*----------------------------------------------------------------------------
\brief set PPPoE property
\attention no

\param[in] const HI_CFG_PPPOE_ATTR_S *pstPppoeAttr   PPPoE property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_GetPppoeAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_SetPppoeAttr(HANDLE DvrHandle, const HI_CFG_PPPOE_ATTR_S *pstPppoeAttr);


/*----------------------------------------------------------------------------
\brief get PPPoE property
\attention no

\param[out] const HI_CFG_PPPOE_ATTR_S *pstPppoeAttr   PPPoE property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_SetPppoeAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_GetPppoeAttr(HANDLE DvrHandle, HI_CFG_PPPOE_ATTR_S *pstPppoeAttr);


/*----------------------------------------------------------------------------
\brief set DDNS property
\attention no

\param[in] HI_CFG_DDNS_ATTR_S astDdnsAttr[]		DDNS property
\param[in] HI_U32 s32DdnsCnt					DDNS count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_GetDdnsAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_SetDdnsAttr(HANDLE DvrHandle, const HI_CFG_DDNS_ATTR_S astDdnsAttr[], HI_S32 s32DdnsCnt);


/*----------------------------------------------------------------------------
\brief get DDNS property
\attention no

\param[in] HI_CFG_DDNS_ATTR_S astDdnsAttr[]			DDNS property
\param[out] ps32DdnsCnt								DDNS count
\param[out] HI_U32 *pu32DdnsCnt						return member(channel) count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_SetDdnsAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_GetDdnsAttr(HANDLE DvrHandle, HI_CFG_DDNS_ATTR_S astDdnsAttr[], HI_S32 *ps32DdnsCnt);


/*----------------------------------------------------------------------------
\brief set IP preview property
\attention no

\param[in] const HI_CFG_IPPREVIEW_VODATTR_S astIppreviewAttr[]		IP preview property
\param[in] HI_U32 s32IpPreviewCnt									IP preview count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_GetIppreviewVodAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_SetIppreviewVodAttr(HANDLE DvrHandle, 
                            const HI_CFG_IPPREVIEW_VODATTR_S astIppreviewAttr[],
                            HI_S32 s32IpPreviewCnt);


/*----------------------------------------------------------------------------
\brief get IP preview property
\attention no

\param[out] HI_CFG_IPPREVIEW_VODATTR_S astIppreviewAttr[]	IP preview property
\param[in] HI_U32 *ps32IpPreviewCnt							IP preview count
\param[out] HI_U32 *ps32IpPreviewCnt						return member(IP preview) count
\retval ::HI_SUCCESS

\see 
    ::HI_SRDK_NET_SetIppreviewVodAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_GetIppreviewVodAttr(HANDLE DvrHandle,
                                  HI_CFG_IPPREVIEW_VODATTR_S astIppreviewAttr[],
                                  HI_S32 *ps32IpPreviewCnt);


/*----------------------------------------------------------------------------
\brief set Email property
\attention no

\param[in] HI_CFG_EMAIL_ATTR_S astEmailAttr[]   E-mail property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_GetEmailAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_SetEmailAttr(HANDLE DvrHandle, const HI_CFG_EMAIL_ATTR_S *pstEmailAttr);


/*----------------------------------------------------------------------------
\brief get Email property
\attention no

\param[out] HI_CFG_EMAIL_ATTR_S astEmailAttr[]   E-mail property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_SetEmailAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_GetEmailAttr(HANDLE DvrHandle, HI_CFG_EMAIL_ATTR_S *pstEmailAttr);


/*----------------------------------------------------------------------------
\brief set mobile property
\attention no

\param[in] const HI_CFG_MOBILE_COMMON_ATTR_S *pstMAttr   mobile property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_MOBILE_GetAttr 
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_MOBILE_SetAttr(HANDLE DvrHandle, const HI_CFG_MOBILE_COMMON_ATTR_S *pstMAttr);


/*----------------------------------------------------------------------------
\brief get mobile property
\attention no

\param[out] HI_CFG_MOBILE_COMMON_ATTR_S *pstMAttr   mobile property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_MOBILE_SetAttr 
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_MOBILE_GetAttr(HANDLE DvrHandle, HI_CFG_MOBILE_COMMON_ATTR_S *pstMAttr);


/*----------------------------------------------------------------------------
\brief set mobile(OWSP) property
\attention no

\param[in] const HI_CFG_MOBILE_OWSP_ATTR_S *pstMAttr   mobile(OWSP) property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_MOBILE_GetOwspAttr 
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_MOBILE_SetOwspAttr(HANDLE DvrHandle, const HI_CFG_MOBILE_OWSP_ATTR_S *pstMAttr);


/*----------------------------------------------------------------------------
\brief get mobile(OWSP) property
\attention no

\param[out] HI_CFG_MOBILE_OWSP_ATTR_S *pstMAttr   mobile(OWSP) property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_MOBILE_SetOwspAttr 
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_MOBILE_GetOwspAttr(HANDLE DvrHandle, HI_CFG_MOBILE_OWSP_ATTR_S *pstMAttr);


/*----------------------------------------------------------------------------
\brief set DNS address
\attention no

\param[in] const HI_CFG_IP_INFO_S astDNSs[2]  DNS address

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_Network_GetDNSList
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_Network_SetDNSList(HANDLE DvrHandle, const HI_CHAR aastDNSs[HI_CFG_DNS_MAX][HI_CFG_IPV4_MAXLEN]);


/*----------------------------------------------------------------------------
\brief get DNS list
\attention no

\param[in] HI_CFG_IP_INFO_S astDNSs[2]   DNS address

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_Network_SetDNSList
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_Network_GetDNSList(HANDLE DvrHandle, HI_CHAR aastDNSs[HI_CFG_DNS_MAX][HI_CFG_IPV4_MAXLEN]);


/*----------------------------------------------------------------------------
\brief get network device name
\attention no

\param[in] HI_S32 s32NetdevNum             network device count
\param[out] HI_CHAR aaszNetdevName[][32]   network device name
\param[out] HI_S32 *ps32NetdevNum          return device count

\retval HI_SUCCESS

\see no
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_Network_GetNetdevName(HANDLE DvrHandle, HI_S32 s32NetdevNum,
                                            HI_CHAR aaszNetdevName[][32],
                                            HI_S32 *ps32NetdevNum);


/*----------------------------------------------------------------------------
\brief set DHCP property
\attention no

\param[in] const HI_CFG_DHCP_CLIENT_ATTR_S *pstAttr		DHCP property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_Network_DHCP_Client_Disable
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_Network_DHCP_Client_SetAttr(HANDLE DvrHandle, const HI_CFG_DHCP_CLIENT_ATTR_S *pstAttr);


/*----------------------------------------------------------------------------
\brief get DHCP property
\attention no

\param[in] HI_CFG_DHCP_CLIENT_ATTR_S *pstAttr->aszNetdevName	network device name
\param[out] HI_CFG_DHCP_CLIENT_ATTR_S *pstAttr					DHCP property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_Network_DHCP_Client_Enable
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_Network_DHCP_Client_GetAttr(HANDLE DvrHandle, HI_CFG_DHCP_CLIENT_ATTR_S *pstAttr);


/*----------------------------------------------------------------------------
\brief set network device property
\attention no

\param[in] const HI_CHAR *pszNetdevName					network device name
\param[in] const HI_CFG_NETDEVATTR_S *pstNetworkAttr	network property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_Network_GetNetdevAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_Network_SetNetdevAttr(HANDLE DvrHandle, const HI_CHAR *pszNetdevName,
                                       const HI_CFG_NETDEVATTR_S *pstNetworkAttr);


/*----------------------------------------------------------------------------
\brief get network device property
\attention no

\param[in] const HI_CHAR *pszNetdevName					network device name
\param[out] const HI_CFG_NETDEVATTR_S *pstNetworkAttr	network property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_Network_SetNetdevAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_Network_GetNetdevAttr(HANDLE DvrHandle, const HI_CHAR *pszNetdevName,
                                            HI_CFG_NETDEVATTR_S *pstNetworkAttr);


HI_S32 WINAPI HI_SRDK_NET_Network_SetUPnpState(HANDLE DvrHandle, const char flag);
HI_S32 WINAPI HI_SRDK_NET_Network_GetUPnpState(HANDLE DvrHandle, char *flag);

HI_S32 WINAPI HI_SRDK_NET_Network_SetWifiAttr(HANDLE DvrHandle, const HI_CFG_WifiSetting_S *pstWifiSetting);
HI_S32 WINAPI HI_SRDK_NET_Network_GetWifiAttr(HANDLE DvrHandle, HI_CFG_WifiSetting_S *pstWifiSetting);

/*----------------------------------------------------------------------------
\brief set default gateway
\attention no

\param[in] const HI_CFG_DEFAULT_GWIP_S *pstDefaultGWIP   default gateway property

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_Network_GetDefaultGateway
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_Network_SetDefaultGateway(HANDLE DvrHandle, const HI_CFG_DEFAULT_GWIP_S *pstDefaultGWIP);


/*----------------------------------------------------------------------------
\brief get default gateway
\attention no

\param[out] HI_CHAR aszNetdevName[HI_CFG_NETWORK_NAME_MAXLEN]   network device name
\param[out] HI_CHAR aszDefaultGWIP[HI_CFG_IPV4_MAXLEN]          default gateway IP

\retval HI_SUCCESS

\see 
    ::HI_SRDK_NET_Network_SetDefaultGateway
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_NET_Network_GetDefaultGateway(HANDLE DvrHandle, HI_CFG_DEFAULT_GWIP_S *pstDefaultGWIP);


/*----------------------------------------------------------------------------
 \brief set system property
 \attention no

 \param[in] HI_CFG_SYSTEM_ATTR_S* pstAttr	system property

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_SYS_GetSystemAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_SetSystemAttr(HANDLE DvrHandle, const HI_CFG_SYSTEM_ATTR_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief get system property
 \attention no

 \param[out] HI_CFG_SYSTEM_ATTR_S* pstAttr	system property

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_SYS_SetSystemAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_GetSystemAttr(HANDLE DvrHandle, HI_CFG_SYSTEM_ATTR_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief set DST property
 \attention no

 \param[in] HI_CFG_DAYLIGHT_S* pstAttr	DST property

 \retval HI_SUCCESS

 \see 
    ::HI_RDK_CFG_GetDaylightAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_SetDaylightAttr(HANDLE DvrHandle, const HI_CFG_DAYLIGHT_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief get DST property
 \attention no

 \param[out] HI_CFG_DAYLIGHT_S* pstAttr	DST property

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_SYS_SetDaylightAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_GetDaylightAttr(HANDLE DvrHandle, HI_CFG_DAYLIGHT_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief set maintenance property
 \attention no

 \param[in] HI_CFG_SYSTEM_MAINTAIN_S* pstAttr	maintenance property

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_SYS_GetSysMaintainAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_SetSysMaintainAttr(HANDLE DvrHandle, const HI_CFG_SYSTEM_MAINTAIN_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief get maintenance property
 \attention no

 \param[out] HI_CFG_SYSTEM_MAINTAIN_S* pstAttr	maintenance property

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_SYS_SetSysMaintainAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_GetSysMaintainAttr(HANDLE DvrHandle, HI_CFG_SYSTEM_MAINTAIN_S* pstAttr);


/*----------------------------------------------------------------------------
\brief enable user manager
\attention no

\param no

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_Disable
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_Enable(HANDLE DvrHandle);


/*----------------------------------------------------------------------------
\brief disable user manager
\attention no

\param no

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_Enable
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_Disable(HANDLE DvrHandle);


/*----------------------------------------------------------------------------
\brief add user
\attention no

\param[in] LB_CFG_USERINFO_S *pstUserInfo     user info
\param[out] LB_CFG_USERINFOLIST_S *pstUserInfoList	return user info list

\param[in] const HI_CFG_USERINFO_S *pstUserInfo     user info
\param[out] HI_U32 *pu32UserID						return user ID

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_DelUser
    ::HI_SRDK_SYS_USERMNG_ModifyUserInfo
    ::HI_SRDK_SYS_USERMNG_GetUserList
-----------------------------------------------------------------------------*/
#ifdef NEW_USERMANAGER
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_AddUser(HANDLE DvrHandle, LB_CFG_USERINFO_S *pstUserInfo,
										  LB_CFG_USERINFOLIST_S *pstUserInfoList);
#else
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_AddUser(HANDLE DvrHandle, const HI_CFG_USERINFO_S *pstUserInfo,
                                           HI_U32 *pu32UserID);
#endif


/*----------------------------------------------------------------------------
\brief delete user
\attention no

\param[in] LB_CFG_DELUSERINFO_S *pstDelUserInfo     user info
\param[out] LB_CFG_USERINFOLIST_S *pstUserInfoList	return user info list

\param[in] HI_U32 u32UserID     user ID

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_AddUser
    ::HI_SRDK_SYS_USERMNG_ModifyUserInfo
    ::HI_SRDK_SYS_USERMNG_GetUserList
-----------------------------------------------------------------------------*/
#ifdef NEW_USERMANAGER
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_DelUser(HANDLE DvrHandle, LB_CFG_DELUSERINFO_S *pstDelUserInfo, LB_CFG_USERINFOLIST_S *pstUserInfoList);
#else
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_DelUser(HANDLE DvrHandle, HI_U32 u32UserID);
#endif


/*----------------------------------------------------------------------------
\brief modify user info
\attention no

\param[in] LB_CFG_USERINFOLIST_S *pstUserInfoListIn		user info list
\param[out] LB_CFG_USERINFOLIST_S *pstUserInfoListOut	return user info list

\param[in] const HI_CFG_USERINFO_S astUserInfo[]		user info
\param[in] HI_U32 u32UserInfoCnt						user count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_AddUser
    ::HI_SRDK_SYS_USERMNG_DelUser
    ::HI_SRDK_SYS_USERMNG_GetUserList
-----------------------------------------------------------------------------*/
#ifdef NEW_USERMANAGER
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_ModifyUserInfo(HANDLE DvrHandle, LB_CFG_USERINFOLIST_S *pstUserInfoListIn,
												 LB_CFG_USERINFOLIST_S *pstUserInfoListOut);
#else
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_ModifyUserInfo(HANDLE DvrHandle, const HI_CFG_USERINFO_S astUserInfo[], 
                                     HI_U32 u32UserInfoCnt);
#endif


/*----------------------------------------------------------------------------
\brief get user info list
\attention no

\param[out] LB_CFG_USERINFOLIST_S *pstUserInfoList	user info list

\param[out] HI_CFG_USERINFO_S astUserInfo[]			user info list
\param[in] HI_U32 *pu32UserInfoCnt					user count
\param[out] HI_U32 *pu32UserInfoCnt					return member(user) count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_AddUser
    ::HI_SRDK_SYS_USERMNG_DelUser
    ::HI_SRDK_SYS_USERMNG_ModifyUserInfo
-----------------------------------------------------------------------------*/
#ifdef NEW_USERMANAGER
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_GetUserList(HANDLE DvrHandle, LB_CFG_USERINFOLIST_S *pstUserInfoList);
#else
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_GetUserList(HANDLE DvrHandle, HI_CFG_USERINFO_S astUserInfo[],
                                          HI_U32 *pu32UserInfoCnt);
#endif


/*----------------------------------------------------------------------------
\brief add group
\attention no

\param[in] const HI_CFG_GROUPINFO_S *pstGroupInfo	group info
\param[out] HI_U32 *pu32GroupID						return group ID

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_DelGroup
    ::HI_SRDK_SYS_USERMNG_ModifyGroupInfo
    ::HI_SRDK_SYS_USERMNG_GetGroupList
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_AddGroup(HANDLE DvrHandle, const HI_CFG_GROUPINFO_S *pstGroupInfo,HI_U32 *pu32GroupID);


/*----------------------------------------------------------------------------
\brief delete group
\attention no

\param[in] HI_U32 u32GroupID	group ID

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_AddGroup
    ::HI_SRDK_SYS_USERMNG_ModifyGroupInfo
    ::HI_SRDK_SYS_USERMNG_GetGroupList
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_DelGroup(HANDLE DvrHandle, HI_U32 u32GroupID);


/*----------------------------------------------------------------------------
\brief modify group info
\attention no

\param[in] const HI_CFG_GROUPINFO_S astGroupInfo[]		group info
\param[in] HI_U32 u32GroupCnt							group count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_AddGroup
    ::HI_SRDK_SYS_USERMNG_DelGroup
    ::HI_SRDK_SYS_USERMNG_GetGroupList
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_ModifyGroupInfo(HANDLE DvrHandle, const HI_CFG_GROUPINFO_S astGroupInfo[],HI_U32 u32GroupCnt);


/*----------------------------------------------------------------------------
\brief get group list
\attention no

\param[out] HI_CFG_GROUPINFO_S astGroupInfo[]	group info
\param[in] HI_U32 *pu32GroupCnt					group count
\param[out] HI_U32 *pu32GroupCnt				return member(group) count

\retval HI_SUCCESS

\see 
    ::HI_SRDK_SYS_USERMNG_AddGroup
    ::HI_SRDK_SYS_USERMNG_DelGroup
    ::HI_SRDK_SYS_USERMNG_ModifyGroupInfo
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_GetGroupList(HANDLE DvrHandle, HI_CFG_GROUPINFO_S astGroupInfo[],HI_U32 *pu32GroupCnt);


/*----------------------------------------------------------------------------
\brief get authority list
\attention no

\param[out]HI_CHAR aaszGroupInfo[][HI_CFG_USRMNG_AUTHORITY_DESCRIPTION_MAXLEN]  authority info
\param[in] HI_U32 *pu32AuthorityCnt												group count
\param[out] HI_U32 *pu32AuthorityCnt											return member(group) count 

\retval HI_SUCCESS

\see no
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_SYS_USERMNG_GetAuthorityList(HANDLE DvrHandle, HI_CHAR aaszGroupInfo[][HI_CFG_USRMNG_AUTHORITY_DESCRIPTION_MAXLEN],
                                               HI_U32 *pu32AuthorityCnt);


/*----------------------------------------------------------------------------
 \brief get USB disk info
 \attention no

 \param[out] HI_CFG_USBDISK_INFO_S* pstInfo		USB disk info

 \retval HI_SUCCESS

 \see no
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_DEV_GetUsbDiskInfo(HANDLE DvrHandle, HI_CFG_USBDISK_INFO_S* pstInfo);


/*----------------------------------------------------------------------------
 \brief get HDD info
 \attention no

 \param[out] HI_CFG_HDD_INFO_S* pstInfo	  	HDD info

 \retval HI_SUCCESS

 \see no
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_DEV_GetHddInfo(HANDLE DvrHandle, HI_CFG_HDD_INFO_S* pstInfo);


/*----------------------------------------------------------------------------
 \brief set HDD property
 \attention no

 \param[in] HI_CFG_HDD_ATTR_S* pstAttr   	HDD property

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_DEV_GetHddAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_DEV_SetHddAttr(HANDLE DvrHandle, const HI_CFG_HDD_ATTR_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief get HDD property
 \attention no

 \param[out] HI_CFG_HDD_ATTR_S* pstAttr		HDD property

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_DEV_SetHddAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_DEV_GetHddAttr(HANDLE DvrHandle, HI_CFG_HDD_ATTR_S* pstAttr);


/*----------------------------------------------------------------------------
 \brief get device info
 \attention no

 \param[out] HI_CFG_DEVICE_INFO_S* pstInfo	device info

 \retval HI_SUCCESS

 \see no
----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_DEV_GetDeviceInfo(HANDLE DvrHandle, HI_CFG_DEVICE_INFO_S* pstInfo);


/*----------------------------------------------------------------------------
 \brief set PTZ property
 \attention no

 \param[in] HI_CFG_PTZ_ATTR_S astAttr[]	    PTZ property
 \param[in] HI_S32 s32ChnCnt			    channel count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_DEV_GetPtzAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_DEV_SetPtzAttr(HANDLE DvrHandle, const HI_CFG_PTZ_ATTR_S astAttr[], HI_S32 s32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get PTZ property
 \attention no

 \param[out] HI_CFG_PTZ_ATTR_S astAttr[]	PTZ property
 \param[in] HI_S32 *ps32ChnCnt				channel count
 \param[out] HI_S32 *ps32ChnCnt				return member(channel) count

 \retval HI_SUCCESS

 \see 
    ::HI_SRDK_DEV_SetPtzAttr
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_DEV_GetPtzAttr(HANDLE DvrHandle, HI_CFG_PTZ_ATTR_S astAttr[], HI_S32 *ps32ChnCnt);


/*----------------------------------------------------------------------------
 \brief get device capacity
 \attention no

 \param[out] HI_CFG_DEVICE_CAPS_S* pstCaps	    device capacity

 \retval HI_SUCCESS

 \see no
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_DEV_GetDevCaps(HANDLE DvrHandle, HI_CFG_DEVICE_CAPS_S* pstCaps);


/*----------------------------------------------------------------------------
 \brief save flash
 \attention no

 \param no

 \retval HI_SUCCESS

 \see no
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_DEV_SaveFlash(HANDLE DvrHandle);


/*----------------------------------------------------------------------------
 \brief Close device
 \attention  After setting parameter, must apply this API to close the device handle.

 \param no

 \retval HI_SUCCESS

 \see 
	:: HI_SRDK_Open_Device
-----------------------------------------------------------------------------*/
HI_S32 WINAPI HI_SRDK_Close_Device(HANDLE DvrHandle);


/*----------------------------------------------------------------------------
 \brief Open device
 \attention   Before setting parameter, must apply this API to get the device handle.

 \param[in] char* IPAdress	    	IP address
 \param[in] long nPort	    		Port
 \param[in] char* username	    	User name
 \param[in] char* passwd	    	Password
 \param[in] char *ip2	    		IP 2

 \retval HI_SUCCESS

 \see
	:: HI_SRDK_Close_Device
-----------------------------------------------------------------------------*/
HANDLE WINAPI HI_SRDK_Open_Device(char* IPAdress, long nPort,  char* username,  char* passwd, char *ip2);


/**
\brief Get DVR status

\attention no

\param[out] HI_CFG_DVRSTATUS_S *pstStatus   DVR status

\retval ::HI_SUCCESS
*/
HI_S32 WINAPI HI_SRDK_DVR_GetStatus(HANDLE DvrHandle, HI_CFG_DVRSTATUS_S *pstStatus);

// add by zk [2011/2/21]
HI_S32 WINAPI HI_SRDK_TV_GetTVAttr(HANDLE DvrHandle, HI_CFG_TV_ATTR_S *pstAttr);
HI_S32 WINAPI HI_SRDK_TV_SetTVAttr(HANDLE DvrHandle, const HI_U32 *pu32Attr);
HI_S32 WINAPI HI_SRDK_TV_ProgramInc(HANDLE DvrHandle, HI_U32 *pu32Attr);
HI_S32 WINAPI HI_SRDK_TV_ProgramDec(HANDLE DvrHandle, HI_U32 *pu32Attr);
HI_S32 WINAPI HI_SRDK_TV_AutoSearch(HANDLE DvrHandle);
HI_S32 WINAPI HI_SRDK_TV_OutPutSwitch(HANDLE DvrHandle, HI_U8 *u8OTVSTATE);
HI_S32 WINAPI HI_SRDK_TV_GetTVState(HANDLE DvrHandle, HI_U8 *u8OTVSTATE);

// add by zk [2011/4/26]
HI_S32 WINAPI HI_SRDK_SYS_GetUserPrewPri(HANDLE DvrHandle, LB_CFG_USERPREWPRI_S *stUserViewPriW, LB_CFG_USERPREWPRI_S *stUserViewPriR);
HI_S32 WINAPI HI_SRDK_SYS_SetUserPrewPri(HANDLE DvrHandle, LB_CFG_USERPREWPRI_S *stUserViewPriW, LB_CFG_USERPREWPRI_S *stUserViewPriR);

// add by zk [2011/5/5]
HI_S32 WINAPI HI_SRDK_PHONE_SetAttr(HANDLE DvrHandle, HI_CFG_PHONE_ATTR_S *stPhoneAttr);
HI_S32 WINAPI HI_SRDK_PHONE_GetAttr(HANDLE DvrHandle, HI_CFG_PHONE_ATTR_S *stPhoneAttr);

// add by zk [2011/9/30]
HI_S32 WINAPI HI_SRDK_BWIP_SetAttr(HANDLE DvrHandle, BWIpparameter_t *pstBWIp);
HI_S32 WINAPI HI_SRDK_BWIP_GetAttr(HANDLE DvrHandle, BWIpparameter_t *pstBWIp);
HI_S32 WINAPI HI_SRDK_FTP_GetAttr(HANDLE DvrHandle, FtpSetting_t *pstFtp);
HI_S32 WINAPI HI_SRDK_FTP_SetAttr(HANDLE DvrHandle, FtpSetting_t *pstFtp);
HI_S32 WINAPI HI_SRDK_NETSMS_SetAttr(HANDLE DvrHandle, netsmssetting_t *pstNetSms);
HI_S32 WINAPI HI_SRDK_NETSMS_GetAttr(HANDLE DvrHandle, netsmssetting_t *pstNetSms);
HI_S32 WINAPI HI_SRDK_RTSP_SetAttr(HANDLE DvrHandle, HI_CFG_RTSP_ATTR_S *pstRTSP);
HI_S32 WINAPI HI_SRDK_RTSP_GetAttr(HANDLE DvrHandle, HI_CFG_RTSP_ATTR_S *pstRTSP);
HI_S32 WINAPI HI_SRDK_NTP_GetAttr(HANDLE DvrHandle, HI_CFG_DVRNTP_S *pstNTP);
HI_S32 WINAPI HI_SRDK_NTP_SetAttr(HANDLE DvrHandle, HI_CFG_DVRNTP_S *pstNTP);

// add by zk [2011/12/10]
HI_S32 WINAPI HI_SRDK_NET_Network_3GWireless_Client_GetAttr(HANDLE DvrHandle, HI_CFG_3GWIRLE_CLIENT_ATTR_S *pstAttr);
HI_S32 WINAPI HI_SRDK_NET_Network_3GWireless_Client_SetAttr(HANDLE DvrHandle, HI_CFG_3GWIRLE_CLIENT_ATTR_S *pstAttr);
 
// add by dee,2010.09.09
HI_S32 WINAPI HI_SRDK_DEV_RestartMachine(HANDLE DvrHandle);
HI_S32 WINAPI HI_SRDK_DEV_ResetParameter(HANDLE DvrHandle);
HI_S32 WINAPI HI_SRDK_SD_GetDeviceInfo(HANDLE DvrHandle, HI_CFG_SDCARD_INFO_S* pstInfo);
HI_S32 WINAPI HI_SRDK_SD_SetFormat(HANDLE DvrHandle);

#endif


