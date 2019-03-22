/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_Camera.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-11
 * Description   :  监控摄像机接口定义
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_CAMERA_H
#define __NPC_MPI_MON_CAMERA_H

#include "NPC_TypeDef.h"
#include "NPC_MPI_MON_DataDef.h"


//---------------------------------------------------------------------------------
//媒体流输出回调函数定义
typedef		void	(*PNPC_F_MPI_MON_CALLBACK_CameraMediaData)(
	IN		PNPC_VOID							in_pUserData,										//[IN]用户数据
	IN		PNPC_S_MON_MEDIA_FRAME_HEAD			in_pMediaHead,										//[IN]媒体帧头
	IN		PNPC_BYTE							in_pMediaDataBuf,									//[IN]媒体数据缓冲区
	IN		NPC_INT								in_iMediaDataLen									//[IN]媒体数据长度
	);

//报警信息输出回调函数定义
typedef		void	(*PNPC_F_MPI_MON_CALLBACK_CameraAlarmData)(
	IN		PNPC_VOID							in_pUserData,										//[IN]用户数据
	IN		PNPC_S_MPI_MON_ALARM_HEAD			in_pAlarmHead,										//[IN]报警信息头
	IN		PNPC_BYTE							in_pAlarmDataBuf,									//[IN]报警数据缓冲区
	IN		NPC_INT								in_iAlarmDataLen									//[IN]报警数据长度
	);


//---------------------------------------------------------------------------------
//监控摄像机接口定义
class NPC_I_MPI_MON_Camera
{
public:
	NPC_INT										m_iConnMode;										//连接模式，参见NPC_D_MON_DEV_CONN_MODE_*定义
	NPC_DWORD									m_dwVendorId;										//厂商ID

	NPC_HANDLE									m_hMonClient;										//监控客户端句柄，可以使用NPC_MPI_MON_Client.h中的函数
	NPC_HANDLE									m_hVpComSrv;										//通讯服务句柄，可以使用NPC_VP_COM_TcpClient.h、NPC_VP_COM_NetServer.h中的函数
	NPC_CHAR									m_sCameraId[NPC_D_MON_DEVID_BUFSIZE];				//摄像机ID
	NPC_CHAR									m_sConnParam[NPC_D_MON_DEV_CONN_PARAM_BUFSIZE];		//连接参数
	NPC_INT										m_iRealMediaTransMode;								//实时媒体传输模式，0：可靠模式，1：实时模式

	NPC_INT										m_iCameraState;										//摄像机状态，值参见NPC_D_MPI_MON_CAMERA_CONN_STATE_*定义
	NPC_INT										m_iDisconnectCause;									//摄像机断开连接的原因，值参见NPC_D_MPI_MON_CAMERA_DISCAUSE_*定义
	NPC_INT										m_iPlayType;										//播放类型，0：实时预览，1：录像回放
	NPC_INT										m_iPlayState;										//播放状态，值参见NPC_D_MPI_MON_CAMERA_PLAY_STATE_*定义
	NPC_INT										m_iTalkState;										//语音对讲状态，0：未开始对讲，1：正在对讲

	NPC_INT										m_iLastErrorCode;									//最后的错误码
	NPC_CHAR									m_sLastErrorBuf[NPC_D_MPI_MON_MAX_ERROR_BUFSIZE];	//最后的错误信息

	NPC_S_MON_MEDIA_FRAME_HEAD					m_tMediaHead;										//媒体头

public:
	//连接摄像机，返回连接结果，0：成功，其它失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_Connect(
		IN		NPC_INT							in_iTimeout=6000			//[IN]超时时长（毫秒）
		) = 0;

	//断开连接摄像机的设备
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_Disconnect() = 0;


	//--------------------------------------------------------------------------------------
	//获取摄像机的当前状态，状态值参考NPC_D_MPI_MON_CAMERA_CONN_STATE_*定义
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetState() = 0;

	//获取摄像机的断开连接的原因，只有状态为NPC_D_MPI_MON_CAMERA_CONN_STATE_DISCONNECT时才能获取原因值，否则返回-1，原因值参考NPC_D_MPI_MON_CAMERA_DISCAUSE_*定义
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetDisconnectCause() = 0;

	//获取摄像机的当前播放类型，0：实时预览，1：录像回放
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetPlayType() = 0;

	//获取摄像机的当前播放状态，状态值参考NPC_D_MPI_MON_CAMERA_PLAY_STATE_*定义
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetPlayState() = 0;

	//获取最后的错误信息，返回错误码，返回值为0表示成功，其它为失败，错误码参见NPC_D_MPI_MON_ERROR_*定义
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetLastError(
		IN		NPC_INT							in_iErrorBufSize,			//[IN]错误信息缓冲区大小
		OUT		PNPC_CHAR						out_pErrorBuf				//[OUT]错误信息缓冲区，调用者分配内存，如果为NULL，则不返回错误信息
		) = 0;

	//获取与设备的连接模式，返回错误码，返回值为0表示成功，其它为失败，错误码参见NPC_D_MPI_MON_ERROR_*定义
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetDevConnectMode(
		OUT		PNPC_INT						out_pDevConnMode			//[OUT]设备连接模式，参见NPC_D_MON_DEV_CONN_TYPE_*定义
		) = 0;


	//--------------------------------------------------------------------------------------
	//设置媒体流回调函数
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_SetMediaStreamCallback(
		IN		PNPC_F_MPI_MON_CALLBACK_CameraMediaData	in_pMediaCallback,	//[IN]媒体流回调函数
		IN		PNPC_VOID						in_pUserData				//[IN]回调用户数据
		) = 0;

	//设置实时媒体传输模式
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_SetRealMediaTransMode(
		IN		NPC_INT							in_iTransMode				//[IN]传输模式，0：可靠模式，1：实时模式
		) = 0;


	//--------------------------------------------------------------------------------------
	//搜索设备上的录像文件，搜索该摄像机关联的录像文件，返回搜索集合句柄，如果返回NULL，表示搜索失败；
	//使用完后必须调用NPC_F_MPI_MON_Camera_SearchColl_Release释放搜索集合
	virtual		NPC_HANDLE	NPC_F_MPI_MON_Camera_SearchRecFileFromDev(
		IN		PNPC_S_TD_DATE_TIME				in_pStartTime,				//[IN]开始时间
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime,				//[IN]结束时间
		IN		NPC_DWORD						in_dwFileType				//[IN]搜索文件类型，参见NPC_D_MON_REC_FILE_TYPE_*定义
		) = 0;

	//释放搜索集合
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_SearchColl_Release(
		IN		NPC_HANDLE						in_hSearchColl				//[IN]搜索集合句柄
		) = 0;

	//移动到第一条
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_SearchColl_MoveFirst(
		IN		NPC_HANDLE						in_hSearchColl				//[IN]搜索集合句柄
		) = 0;

	//从搜索集合中获取下一个录像文件，返回FALSE表示没有下一个录像文件
	//该函数不会移除记录，需要调用NPC_F_MPI_MON_Camera_SearchColl_Release函数内存
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_SearchColl_GetNextRecFile(
		IN		NPC_HANDLE						in_hSearchColl,				//[IN]搜索集合句柄
		OUT		PNPC_S_MPI_MON_REC_FILE			out_pRecFile				//[OUT]录像文件，由调用者分配内存
		) = 0;


	//--------------------------------------------------------------------------------------
	//查询设备上的文件（包括录像和图片文件），返回文件列表句柄，如果返回NULL，表示查询失败；
	//使用完后必须调用NPC_F_MPI_MON_Camera_FileList_Release释放文件列表
	virtual		NPC_HANDLE	NPC_F_MPI_MON_Camera_QueryFile(
		IN		NPC_INT							in_iChNo,					//[IN]通道号，如果为-1表示查询所有通道的文件
		IN		NPC_INT							in_iStreamNo,				//[IN]码流号，如果为-1表示查询所有码流的文件
		IN		NPC_INT							in_iFileType,				//[IN]文件类型，参见NPC_D_MON_FILE_TYPE_*定义
		IN		NPC_INT							in_iCreateMode,				//[IN]创建方式，参见NPC_D_MON_FILE_CREATE_MODE_*定义
		IN		PNPC_BYTE						in_pAlarmEventTable,		//[IN]报警事件表（最大16个事件），参见NPC_D_MON_ALARM_EVENT_*定义，只有创建方式为NPC_D_MON_FILE_CREATE_MODE_ALARM时有效
		IN		NPC_INT							in_iAlarmEventNum,			//[IN]报警事件数
		IN		PNPC_S_TD_DATE_TIME				in_pStartTime,				//[IN]开始时间
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime					//[IN]结束时间
		) = 0;

	//释放文件列表
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_FileList_Release(
		IN		NPC_HANDLE						in_hFileList				//[IN]文件列表句柄
		) = 0;

	//移动到第一条
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_FileList_MoveFirst(
		IN		NPC_HANDLE						in_hFileList				//[IN]文件列表句柄
		) = 0;

	//从文件列表中获取下一个文件，返回FALSE表示没有下一个文件，该函数不会移除记录
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_FileList_GetNextFile(
		IN		NPC_HANDLE						in_hFileList,				//[IN]文件列表句柄
		OUT		PNPC_S_MON_FILE_HEAD_INFO		out_pFileHeadInfo			//[OUT]文件头信息，由调用者分配内存
		) = 0;


	//--------------------------------------------------------------------------------
	//开始实时预览（队列模式），返回操作结果码，返回0表示成功，其它为失败
	//同时只能播放一个流，或者为实时预览，或者为回放录像文件
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_Play(
		IN		NPC_INT							in_iStreamType,				//[IN]码流类型，-1：缺省码流，0：主码流，1：子码流1，2：子码流2，如此类推
		IN		NPC_INT							in_iPlayType				//[IN]播放类型，0：音视频，1：视频，2：音频
		) = 0;

	//开始实时预览（回调模式），返回操作结果码，返回0表示成功，其它为失败
	//该函数设置媒体流回调函数，媒体流从回调函数传回，不能调用NPC_F_MPI_MON_Camera_GetMediaFrame获取
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_Play(
		IN		NPC_INT							in_iStreamType,				//[IN]码流类型，-1：缺省码流，0：主码流，1：子码流1，2：子码流2，如此类推
		IN		NPC_INT							in_iPlayType,				//[IN]播放类型，0：音视频，1：视频，2：音频
		IN		PNPC_F_MPI_MON_CALLBACK_CameraMediaData	in_pMediaCallback,	//[IN]媒体流回调函数
		IN		PNPC_VOID						in_pUserData				//[IN]回调用户数据
		) = 0;

	//播放文件（队列模式），返回操作结果码，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartPlayFile(
		IN		PNPC_S_MPI_MON_REC_FILE			in_pRecFile,				//[IN]录像文件信息
		IN		NPC_INT							in_iPlayType				//[IN]播放类型，0：音视频，1：视频，2：音频
		) = 0;

	//播放文件（回调模式），返回操作结果码，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartPlayFile(
		IN		PNPC_S_MPI_MON_REC_FILE			in_pRecFile,				//[IN]录像文件信息
		IN		NPC_INT							in_iPlayType,				//[IN]播放类型，0：音视频，1：视频，2：音频
		IN		PNPC_F_MPI_MON_CALLBACK_CameraMediaData	in_pMediaCallback,	//[IN]媒体流回调函数
		IN		PNPC_VOID						in_pUserData				//[IN]回调用户数据
		) = 0;

	//播放文件（控制时间，队列模式），返回操作结果码，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartPlayFile(
		IN		PNPC_S_MPI_MON_REC_FILE			in_pRecFile,				//[IN]录像文件信息
		IN		NPC_BOOL						in_bIfCtrlTime,				//[IN]是否控制时间，即开始时间和结束时间是否有效，如果FALSE，表示从文件开始处理
		IN		PNPC_S_TD_DATE_TIME				in_pBeginTime,				//[IN]开始时间，必须在文件时间范围内
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime,				//[IN]结束时间，必须在文件时间范围内，并大于开始时间
		IN		NPC_INT							in_iPlayType				//[IN]播放类型，0：音视频，1：视频，2：音频
		) = 0;

	//按时间段回放录像，返回操作结果码，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartPlaybackByTimeSect(
		IN		PNPC_S_TD_DATE_TIME				in_pBeginTime,				//[IN]开始时间
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime,				//[IN]结束时间，必须大于开始时间
		IN		NPC_INT							in_iPlayType				//[IN]播放类型，0：音视频，1：视频，2：音频
		) = 0;

	//停止播放，返回操作结果码，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_Stop() = 0;

	//控制播放（只适合录像文件回放），返回操作结果码，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_PlayControl(
		IN		NPC_INT							in_iCtrlCode,				//[IN]控制码，参见NPC_D_MON_PLAY_CTRL_*定义
		IN		NPC_DWORD						in_dwCtrlParam				//[IN]控制参数，根据控制码确定值含义
		) = 0;


	//--------------------------------------------------------------------------------
	//开始语音对讲，必须首先打开实时预览，才能开始语音对讲，接收语音数据通过NPC_F_MPI_MON_Camera_GetMediaFrame函数获取，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartTalk(
		IN		NPC_INT							in_iEncodeType=NPC_D_MON_CODEC_ID_AUDIO_16BITPCM,	//[IN]编码类型，参见NPC_D_MON_CODEC_ID_AUDIO_*定义
		IN		NPC_INT							in_iSampleBit=16,									//[IN]采样位数
		IN		NPC_INT							in_iSampleRate=8000									//[IN]采样率
		) = 0;

	//停止语音对讲
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_StopTalk() = 0;

	//发送语音数据，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SendVocData(
		IN		NPC_DWORD						in_dwTimestamp,				//[IN]时间戳
		IN		PNPC_BYTE						in_pVocDataBuf,				//[IN]语音数据缓冲区
		IN		NPC_INT							in_iVocDataLen,				//[IN]语音数据长度
		IN		NPC_INT							in_iTimeout					//[IN]发送超时长度（毫秒）
		) = 0;

	//控制媒体流（暂停或继续），暂停后，服务器将不再发送媒体数据给客户端，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_CtrlMediaStream(
		IN		NPC_INT							in_iCtrlOrder,				//[IN]控制命令，0：暂停，1：继续
		IN		NPC_INT							in_iMediaType				//[IN]媒体类型，0：视频，1：音频，2：音视频
		) = 0;

	//请求只发I帧或恢复发送全帧，恢复发送全帧后，会从I帧开始发送，该函数不具有强制I帧功能，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_OnlyIFrame(
		IN		NPC_INT							in_iCtrlCode				//[IN]控制码，0：只发I帧，1：恢复发送全帧
		) = 0;

	//请求强制发送I帧，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_RequForceIFrame() = 0;

	//切换通道，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SwitchChannel(
		IN		NPC_INT							in_iSwitchChNo,				//[IN]切换后的通道号，-1表示通道号不变
		IN		NPC_INT							in_iSwitchStreamNo			//[IN]切换后的码流号，0：主码流，1：子码流，-1表示码流号不变
		) = 0;

	//查询当前通道号和码流号，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_QueryChannelStreamNo(
		OUT		PNPC_INT						out_pCurChNo,				//[OUT]当前通道号
		OUT		PNPC_INT						out_pCurStreamNo			//[OUT]当前码流号
		) = 0;

	//获取视频质量等级能力列表，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetVideoQualityCapList(
		OUT		PNPC_S_MPI_MON_VIDEO_CODEC_LEVEL_LIST	out_pVideoCodecLevelList	//[OUT]视频编码等级列表
		) = 0;

	//获取当前视频质量等级
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetCurVideoQualityLevel(
		OUT		PNPC_INT						out_pLevelValue				//[OUT]等级值，如果为-1表示缺省设置，即没有设备等级
		) = 0;

	//设置视频质量等级
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SetVideoQualityLevel(
		IN		NPC_INT							in_iLevelValue				//[IN]等级值，大于等于0，或为-1，如果为-1表示缺省编码
		) = 0;


	//--------------------------------------------------------------------------------
	//获取帧数据，返回NULL表示没有获取到，函数立即返回，帧数据使用完后，须调用NPC_F_MPI_MON_Camera_ReleaseFrameData函数释放
	virtual		PNPC_S_MPI_MON_MEDIA_FRAME	NPC_F_MPI_MON_Camera_GetMediaFrame(
		IN		NPC_INT							in_iGetMediaType			//[IN]获取媒体类型，0：混合方式，1：视频，2：音频，100：开始帧
		) = 0;

	//等待获取帧数据，包括音视频帧，以混合方式获取，帧数据使用完后，须调用NPC_F_MPI_MON_Camera_ReleaseFrameData函数释放
	virtual		PNPC_S_MPI_MON_MEDIA_FRAME	NPC_F_MPI_MON_Camera_GetMediaFrameFromQueue(
		IN		NPC_INT							in_iTimeout					//[IN]超时时长（毫秒）
		) = 0;

	//释放帧数据
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_ReleaseFrameData(
		IN		PNPC_S_MPI_MON_MEDIA_FRAME		in_pFrameData				//[IN]帧数据指针，释放后该指针不可再用
		) = 0;

	//获取剩下的帧数
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetResidualFrameNum(
		IN		NPC_INT							in_iGetMediaType			//[IN]获取媒体类型，0：混合方式，1：视频，2：音频
		) = 0;


	//--------------------------------------------------------------------------------
	//PTZ控制，返回操作结果码，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_PtzControl(
		IN		NPC_INT							in_iPtzCmd,					//[IN]PTZ命令，参见NPC_D_MON_PTZ_CMD_*定义
		IN		NPC_DWORD						in_dwPtzData,				//[IN]PTZ数据
		IN		NPC_DWORD						in_dwPtzExtParam1,			//[IN]PTZ扩展参数1
		IN		NPC_DWORD						in_dwPtzExtParam2			//[IN]PTZ扩展参数2
		) = 0;


	//--------------------------------------------------------------------------------
	//手动启动录像，返回操作结果码，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartRecord() = 0;

	//手动停止录像，返回操作结果码，返回0表示成功，其它为失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StopRecord() = 0;

	//检测当前录像状态及录像时长，返回TRUE表示正在录像，FALSE表示未录像
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_CheckRecordState() = 0;


	//----------------------------------------------------------------------------------
	//开启获取报警信息，获取该摄像机所在设备的所有报警信息，调用NPC_F_MPI_MON_Camera_GetAlarmInfo循环检测报警信息
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_StartGetAlarmInfo() = 0;

	//停止获取报警信息
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_StopGetAlarmInfo() = 0;

	//检测当前报警状态，返回TRUE表示已打开获取报警信息开关，FALSE表示未打开
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_CheckAlarmState() = 0;

	//获取报警信息，报警信息缓冲区使用完后须调用NPC_F_MPI_MON_Camera_ReleaseAlarmBuf释放
	virtual		PNPC_S_MPI_MON_ALARM_DATA	NPC_F_MPI_MON_Camera_GetAlarmInfo(
		IN		NPC_INT							in_iTimeout					//[IN]等待超时时长（毫秒）
		) = 0;

	//设置报警信息回调函数，缺省为队列方式，如果调用该函数设置了回调函数，则不再将报警信息存入队列
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_SetAlarmCallback(
		IN		PNPC_F_MPI_MON_CALLBACK_CameraAlarmData		in_pCallback,	//[IN]回调函数指针，如果为NULL，则取消回调，采用队列方式
		IN		PNPC_VOID									in_pUserData	//[IN]用户数据
		) = 0;

	//释放报警信息缓冲区
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_ReleaseAlarmBuf(
		IN		PNPC_S_MPI_MON_ALARM_DATA		in_pAlarmBuf				//[IN]报警信息缓冲区
		) = 0;


	//----------------------------------------------------------------------------------
	//开始下载录像文件
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_RecFile_StartDown(
		IN		PNPC_CHAR						in_pFileName,				//[IN]下载文件名，为查询函数返回的文件名
		IN		NPC_BOOL						in_bIfCtrlTime,				//[IN]是否控制时间，即开始时间和结束时间是否有效，如果FALSE，表示从文件开始处理
		IN		PNPC_S_TD_DATE_TIME				in_pBeginTime,				//[IN]开始时间，必须在文件时间范围内
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime,				//[IN]结束时间，必须在文件时间范围内，并大于开始时间
		OUT		PNPC_DWORD						out_pDownloadId				//[OUT]下载ID
		) = 0;

	//停止下载录像文件
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_RecFile_StopDown(
		IN		NPC_DWORD						in_dwDownloadId				//[IN]下载ID
		) = 0;

	//查询下载状态，状态值参见NPC_D_MPI_MON_CAMERA_DOWN_STATE_*定义
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_RecFile_QueryDownState(
		IN		NPC_DWORD						in_dwDownloadId				//[IN]下载ID
		) = 0;

	//获取下载百分比，返回值为0~100
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_RecFile_GetDownPercent(
		IN		NPC_DWORD						in_dwDownloadId				//[IN]下载ID
		) = 0;

	//等待获取下载的帧数据，包括音视频帧，帧数据使用完后，须调用NPC_F_MPI_MON_Camera_ReleaseFrameData函数释放
	virtual		PNPC_S_MPI_MON_MEDIA_FRAME	NPC_F_MPI_MON_Camera_RecFile_GetDownFrameData(
		IN		NPC_DWORD						in_dwDownloadId,			//[IN]下载ID
		IN		NPC_INT							in_iTimeout					//[IN]超时时长（毫秒）
		) = 0;


	//----------------------------------------------------------------------------------
	//修改设备密码，返回0：表示成功，其它为其它原因失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ModifyDevPwd(
		IN		PNPC_CHAR						in_pUserName,				//[IN]用户名
		IN		PNPC_CHAR						in_pOldPwd,					//[IN]原密码
		IN		PNPC_CHAR						in_pNewPwd					//[IN]新密码
		) = 0;


	//----------------------------------------------------------------------------------
	//获取配置，返回0：表示成功，其它表示失败（过时函数，请使用下面的扩展函数）
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetConfig(
		IN		NPC_INT							in_iCfgFuncId,				//[IN]配置功能ID，参见NPC_D_PVM_CFG_FUNCID_*定义
		OUT		PNPC_BYTE*						out_ppRspCfgDataBuf,		//[OUT]应答配置数据缓冲区，由该函数分配内存，需要调用NPC_F_MPI_MON_Camera_ReleaseBuf函数释放，配置数据结构参见NPC_PVM_OrderCfgDef.h文件中的定义
		OUT		PNPC_INT						out_pRspCfgDataLen			//[OUT]应答配置数据长度
		) = 0;

	//获取配置（扩展），返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetConfig(
		IN		NPC_INT							in_iCfgFuncId,				//[IN]配置功能ID，参见NPC_D_PVM_CFG_FUNCID_*定义
		IN		PNPC_BYTE						in_pReqCfgDataBuf,			//[IN]请求配置数据缓冲区，配置数据结构参见NPC_PVM_OrderCfgDef.h文件中的定义
		IN		NPC_INT							in_iReqCfgDataLen,			//[IN]请求配置数据长度
		OUT		PNPC_BYTE*						out_ppRspCfgDataBuf,		//[OUT]应答配置数据缓冲区，由该函数分配内存，需要调用NPC_F_MPI_MON_Camera_ReleaseBuf函数释放，配置数据结构参见NPC_PVM_OrderCfgDef.h文件中的定义
		OUT		PNPC_INT						out_pRspCfgDataLen			//[OUT]应答配置数据长度
		) = 0;

	//设置配置，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SetConfig(
		IN		NPC_INT							in_iCfgFuncId,				//[IN]配置功能ID，参见NPC_D_PVM_CFG_FUNCID_*定义
		IN		PNPC_BYTE						in_pCfgDataBuf,				//[IN]配置数据缓冲区，配置数据结构参见NPC_PVM_OrderCfgDef.h文件中的定义
		IN		NPC_INT							in_iCfgDataLen				//[IN]配置数据长度
		) = 0;

	//获取缺省配置参数，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetDefConfig(
		IN		NPC_INT							in_iCfgFuncId,				//[IN]配置功能ID，参见NPC_D_PVM_CFG_FUNCID_*定义
		IN		NPC_INT							in_iChNo,					//[IN]通道号
		OUT		PNPC_BYTE*						out_ppRspCfgDataBuf,		//[OUT]应答配置数据缓冲区，由该函数分配内存，需要调用NPC_F_MPI_MON_Camera_ReleaseBuf函数释放，配置数据结构参见NPC_PVM_OrderCfgDef.h文件中的定义
		OUT		PNPC_INT						out_pRspCfgDataLen			//[OUT]应答配置数据长度
		) = 0;

	//导入配置，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ImportConfig(
		IN		PNPC_BYTE						in_pCfgDataBuf,				//[IN]配置数据缓冲区，配置数据结构参见NPC_PVM_OrderCfgDef.h文件中的定义
		IN		NPC_INT							in_iCfgDataLen				//[IN]配置数据长度
		) = 0;

	//导出配置，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ExportConfig(
		OUT		PNPC_BYTE*						out_ppRspCfgDataBuf,		//[OUT]应答配置数据缓冲区，由该函数分配内存，需要调用NPC_F_MPI_MON_Camera_ReleaseBuf函数释放，配置数据结构参见NPC_PVM_OrderCfgDef.h文件中的定义
		OUT		PNPC_INT						out_pRspCfgDataLen			//[OUT]应答配置数据长度
		) = 0;


	//----------------------------------------------------------------------------------
	//打开串口，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ComOpen(
		IN		NPC_INT							in_iComType,				//[IN]串口类型，0：RS232串口，1：RS485串口
		IN		NPC_INT							in_iPortNo,					//[IN]端口号
		IN		NPC_INT							in_iBaudRate,				//[IN]波特率，如4800，14400，28800，36600
		IN		NPC_INT							in_iDataBit,				//[IN]数据位，如8位
		IN		NPC_INT							in_iStopBit,				//[IN]停止位，如1
		IN		NPC_INT							in_iCheckBit				//[IN]奇偶校验位
		) = 0;

	//关闭串口
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_ComClose(
		IN		NPC_INT							in_iComType,				//[IN]串口类型，0：RS232串口，1：RS485串口
		IN		NPC_INT							in_iPortNo					//[IN]端口号
		) = 0;

	//发送串口数据，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ComSendData(
		IN		NPC_INT							in_iComType,				//[IN]串口类型，0：RS232串口，1：RS485串口
		IN		NPC_INT							in_iPortNo,					//[IN]端口号
		IN		PNPC_BYTE						in_pSendDataBuf,			//[IN]发送数据缓冲区，指发送给串口的数据
		IN		NPC_INT							in_iSendDataLen				//[IN]发送数据长度
		) = 0;


	//----------------------------------------------------------------------------------
	//增加用户，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_AddUser(
		IN		PNPC_CHAR						in_pUserName,				//[IN]用户名
		IN		PNPC_CHAR						in_pUserPwd,				//[IN]用户密码
		IN		NPC_DWORD						in_dwGlobalPop,				//[IN]全局权限，位值参考NPC_D_MON_DEV_POP_*定义
		IN		NPC_INT							in_iChNum,					//[IN]通道数，该结构体之后为通道权限表，每4字节为一个通道的权限，4字节的顺序号为通道号，位值参考NPC_D_MON_DEV_POP_*定义
		IN		PNPC_DWORD						in_pChPopTable				//[IN]通道权限表，数组索引号为通道号，位值参考NPC_D_MON_DEV_POP_*定义，最大64个通道
		) = 0;

	//删除用户，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_DeleteUser(
		IN		PNPC_CHAR						in_pUserName				//[IN]用户名
		) = 0;

	//获取用户权限列表，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetUserPop(
		IN		PNPC_CHAR						in_pUserName,				//[IN]用户名
		OUT		PNPC_DWORD						out_pGlobalPop,				//[IN]全局权限，位值参考NPC_D_MON_DEV_POP_*定义
		OUT		PNPC_INT						out_pChNum,					//[IN]通道数，该结构体之后为通道权限表，每4字节为一个通道的权限，4字节的顺序号为通道号，位值参考NPC_D_MON_DEV_POP_*定义
		OUT		PNPC_DWORD						out_pChPopTable				//[IN]通道权限表，数组索引号为通道号，缓冲区由上层分配，分配64个4字节整型数组，位值参考NPC_D_MON_DEV_POP_*定义，最大64个通道
		) = 0;

	//设置用户权限列表，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SetUserPop(
		IN		PNPC_CHAR						in_pUserName,				//[IN]用户名
		IN		NPC_DWORD						in_dwGlobalPop,				//[IN]全局权限，位值参考NPC_D_MON_DEV_POP_*定义
		IN		NPC_INT							in_iChNum,					//[IN]通道数，该结构体之后为通道权限表，每4字节为一个通道的权限，4字节的顺序号为通道号，位值参考NPC_D_MON_DEV_POP_*定义
		IN		PNPC_DWORD						in_pChPopTable				//[IN]通道权限表，数组索引号为通道号，位值参考NPC_D_MON_DEV_POP_*定义，最大64个通道
		) = 0;


	//----------------------------------------------------------------------------------
	//调用定制功能，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_CallCustomFunc(
		IN		NPC_INT							in_iCusFuncId,				//[IN]定制功能ID，参见相关文件中的定义
		IN		PNPC_BYTE						in_pCusBodyBuf,				//[IN]定制包体缓冲区
		IN		NPC_INT							in_iCusBodyLen,				//[IN]定制包体长度
		OUT		PNPC_BYTE*						out_ppRespBodyBuf,			//[OUT]应答包体缓冲区，由该函数分配内存，需调用NPC_F_MPI_MON_Camera_ReleaseBuf释放
		OUT		PNPC_INT						out_pRespBodyLen			//[OUT]应答包体长度
		) = 0;


	//----------------------------------------------------------------------------------
	//查询能力集，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_QueryAbility(
		IN		NPC_INT							in_iRequVerNo,				//[IN]请求版本号
		OUT		PNPC_BYTE*						out_ppAbilityDataBuf,		//[OUT]能力集数据缓冲区，由该函数分配内存，需调用NPC_F_MPI_MON_Camera_ReleaseBuf释放
		OUT		PNPC_INT						out_pAbilityDataLen			//[OUT]能力集数据长度
		) = 0;

	//重启设备，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_DevReboot() = 0;

	//关闭设备，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_DevClose() = 0;


	//----------------------------------------------------------------------------------
	//查询设备版本信息，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_QueryDevVerInfo(
		OUT		PNPC_USHORT						out_pModuleType,			//模块类型,0:未知类型,1:UI,2:SYS,3:UI&SYS，由上层分配内存，为4个NPC_USHORT数组
		OUT		PNPC_UINT						out_pModuleVerNo			//模块版本号,按顺序对应模块类型,格式为:x.x.x.x,每字节为一个号，由上层分配内存，为4个NPC_UINT数组
		) = 0;

	//请求升级，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_RequestUpgrade(
		IN		NPC_USHORT						in_usModuleType,			//模块类型,0:未知类型,1:UI,2:SYS,3:UI&SYS
		IN		NPC_USHORT						in_usCheckSum,				//文件检验和
		IN		NPC_INT							in_iFileSize,				//升级文件大小(字节)
		OUT		PNPC_UINT						out_pUpgradeId				//升级ID
		) = 0;

	//查询升级进度，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_QueryUpgradeProgress(
		IN		NPC_UINT						in_uiUpgradeId,				//升级ID
		OUT		PNPC_INT						out_pUpgProgress			//升级进度,值为0~100,指写FLASH的进度
		) = 0;

	//发送升级文件数据，可以多次发送，返回0：表示成功，其它表示失败
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SendUpgradeFileData(
		IN		NPC_UINT						in_uiUpgradeId,				//升级ID
		IN		PNPC_BYTE						in_pFileDataBuf,			//文件数据缓冲区
		IN		NPC_INT							in_iFileDataLen				//文件数据长度
		) = 0;


	//----------------------------------------------------------------------------------
	//释放数据缓冲区，由底层分配的缓冲区
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_ReleaseBuf(
		IN		PNPC_BYTE						in_pDataBuf					//[IN]缓冲区，由底层分配的缓冲区
		) = 0;
};



#endif

