/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_Camera.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-11
 * Description   :  ���������ӿڶ���
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_CAMERA_H
#define __NPC_MPI_MON_CAMERA_H

#include "NPC_TypeDef.h"
#include "NPC_MPI_MON_DataDef.h"


//---------------------------------------------------------------------------------
//ý��������ص���������
typedef		void	(*PNPC_F_MPI_MON_CALLBACK_CameraMediaData)(
	IN		PNPC_VOID							in_pUserData,										//[IN]�û�����
	IN		PNPC_S_MON_MEDIA_FRAME_HEAD			in_pMediaHead,										//[IN]ý��֡ͷ
	IN		PNPC_BYTE							in_pMediaDataBuf,									//[IN]ý�����ݻ�����
	IN		NPC_INT								in_iMediaDataLen									//[IN]ý�����ݳ���
	);

//������Ϣ����ص���������
typedef		void	(*PNPC_F_MPI_MON_CALLBACK_CameraAlarmData)(
	IN		PNPC_VOID							in_pUserData,										//[IN]�û�����
	IN		PNPC_S_MPI_MON_ALARM_HEAD			in_pAlarmHead,										//[IN]������Ϣͷ
	IN		PNPC_BYTE							in_pAlarmDataBuf,									//[IN]�������ݻ�����
	IN		NPC_INT								in_iAlarmDataLen									//[IN]�������ݳ���
	);


//---------------------------------------------------------------------------------
//���������ӿڶ���
class NPC_I_MPI_MON_Camera
{
public:
	NPC_INT										m_iConnMode;										//����ģʽ���μ�NPC_D_MON_DEV_CONN_MODE_*����
	NPC_DWORD									m_dwVendorId;										//����ID

	NPC_HANDLE									m_hMonClient;										//��ؿͻ��˾��������ʹ��NPC_MPI_MON_Client.h�еĺ���
	NPC_HANDLE									m_hVpComSrv;										//ͨѶ������������ʹ��NPC_VP_COM_TcpClient.h��NPC_VP_COM_NetServer.h�еĺ���
	NPC_CHAR									m_sCameraId[NPC_D_MON_DEVID_BUFSIZE];				//�����ID
	NPC_CHAR									m_sConnParam[NPC_D_MON_DEV_CONN_PARAM_BUFSIZE];		//���Ӳ���
	NPC_INT										m_iRealMediaTransMode;								//ʵʱý�崫��ģʽ��0���ɿ�ģʽ��1��ʵʱģʽ

	NPC_INT										m_iCameraState;										//�����״̬��ֵ�μ�NPC_D_MPI_MON_CAMERA_CONN_STATE_*����
	NPC_INT										m_iDisconnectCause;									//������Ͽ����ӵ�ԭ��ֵ�μ�NPC_D_MPI_MON_CAMERA_DISCAUSE_*����
	NPC_INT										m_iPlayType;										//�������ͣ�0��ʵʱԤ����1��¼��ط�
	NPC_INT										m_iPlayState;										//����״̬��ֵ�μ�NPC_D_MPI_MON_CAMERA_PLAY_STATE_*����
	NPC_INT										m_iTalkState;										//�����Խ�״̬��0��δ��ʼ�Խ���1�����ڶԽ�

	NPC_INT										m_iLastErrorCode;									//���Ĵ�����
	NPC_CHAR									m_sLastErrorBuf[NPC_D_MPI_MON_MAX_ERROR_BUFSIZE];	//���Ĵ�����Ϣ

	NPC_S_MON_MEDIA_FRAME_HEAD					m_tMediaHead;										//ý��ͷ

public:
	//������������������ӽ����0���ɹ�������ʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_Connect(
		IN		NPC_INT							in_iTimeout=6000			//[IN]��ʱʱ�������룩
		) = 0;

	//�Ͽ�������������豸
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_Disconnect() = 0;


	//--------------------------------------------------------------------------------------
	//��ȡ������ĵ�ǰ״̬��״ֵ̬�ο�NPC_D_MPI_MON_CAMERA_CONN_STATE_*����
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetState() = 0;

	//��ȡ������ĶϿ����ӵ�ԭ��ֻ��״̬ΪNPC_D_MPI_MON_CAMERA_CONN_STATE_DISCONNECTʱ���ܻ�ȡԭ��ֵ�����򷵻�-1��ԭ��ֵ�ο�NPC_D_MPI_MON_CAMERA_DISCAUSE_*����
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetDisconnectCause() = 0;

	//��ȡ������ĵ�ǰ�������ͣ�0��ʵʱԤ����1��¼��ط�
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetPlayType() = 0;

	//��ȡ������ĵ�ǰ����״̬��״ֵ̬�ο�NPC_D_MPI_MON_CAMERA_PLAY_STATE_*����
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetPlayState() = 0;

	//��ȡ���Ĵ�����Ϣ�����ش����룬����ֵΪ0��ʾ�ɹ�������Ϊʧ�ܣ�������μ�NPC_D_MPI_MON_ERROR_*����
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetLastError(
		IN		NPC_INT							in_iErrorBufSize,			//[IN]������Ϣ��������С
		OUT		PNPC_CHAR						out_pErrorBuf				//[OUT]������Ϣ�������������߷����ڴ棬���ΪNULL���򲻷��ش�����Ϣ
		) = 0;

	//��ȡ���豸������ģʽ�����ش����룬����ֵΪ0��ʾ�ɹ�������Ϊʧ�ܣ�������μ�NPC_D_MPI_MON_ERROR_*����
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetDevConnectMode(
		OUT		PNPC_INT						out_pDevConnMode			//[OUT]�豸����ģʽ���μ�NPC_D_MON_DEV_CONN_TYPE_*����
		) = 0;


	//--------------------------------------------------------------------------------------
	//����ý�����ص�����
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_SetMediaStreamCallback(
		IN		PNPC_F_MPI_MON_CALLBACK_CameraMediaData	in_pMediaCallback,	//[IN]ý�����ص�����
		IN		PNPC_VOID						in_pUserData				//[IN]�ص��û�����
		) = 0;

	//����ʵʱý�崫��ģʽ
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_SetRealMediaTransMode(
		IN		NPC_INT							in_iTransMode				//[IN]����ģʽ��0���ɿ�ģʽ��1��ʵʱģʽ
		) = 0;


	//--------------------------------------------------------------------------------------
	//�����豸�ϵ�¼���ļ��������������������¼���ļ��������������Ͼ�����������NULL����ʾ����ʧ�ܣ�
	//ʹ�����������NPC_F_MPI_MON_Camera_SearchColl_Release�ͷ���������
	virtual		NPC_HANDLE	NPC_F_MPI_MON_Camera_SearchRecFileFromDev(
		IN		PNPC_S_TD_DATE_TIME				in_pStartTime,				//[IN]��ʼʱ��
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime,				//[IN]����ʱ��
		IN		NPC_DWORD						in_dwFileType				//[IN]�����ļ����ͣ��μ�NPC_D_MON_REC_FILE_TYPE_*����
		) = 0;

	//�ͷ���������
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_SearchColl_Release(
		IN		NPC_HANDLE						in_hSearchColl				//[IN]�������Ͼ��
		) = 0;

	//�ƶ�����һ��
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_SearchColl_MoveFirst(
		IN		NPC_HANDLE						in_hSearchColl				//[IN]�������Ͼ��
		) = 0;

	//�����������л�ȡ��һ��¼���ļ�������FALSE��ʾû����һ��¼���ļ�
	//�ú��������Ƴ���¼����Ҫ����NPC_F_MPI_MON_Camera_SearchColl_Release�����ڴ�
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_SearchColl_GetNextRecFile(
		IN		NPC_HANDLE						in_hSearchColl,				//[IN]�������Ͼ��
		OUT		PNPC_S_MPI_MON_REC_FILE			out_pRecFile				//[OUT]¼���ļ����ɵ����߷����ڴ�
		) = 0;


	//--------------------------------------------------------------------------------------
	//��ѯ�豸�ϵ��ļ�������¼���ͼƬ�ļ����������ļ��б������������NULL����ʾ��ѯʧ�ܣ�
	//ʹ�����������NPC_F_MPI_MON_Camera_FileList_Release�ͷ��ļ��б�
	virtual		NPC_HANDLE	NPC_F_MPI_MON_Camera_QueryFile(
		IN		NPC_INT							in_iChNo,					//[IN]ͨ���ţ����Ϊ-1��ʾ��ѯ����ͨ�����ļ�
		IN		NPC_INT							in_iStreamNo,				//[IN]�����ţ����Ϊ-1��ʾ��ѯ�����������ļ�
		IN		NPC_INT							in_iFileType,				//[IN]�ļ����ͣ��μ�NPC_D_MON_FILE_TYPE_*����
		IN		NPC_INT							in_iCreateMode,				//[IN]������ʽ���μ�NPC_D_MON_FILE_CREATE_MODE_*����
		IN		PNPC_BYTE						in_pAlarmEventTable,		//[IN]�����¼������16���¼������μ�NPC_D_MON_ALARM_EVENT_*���壬ֻ�д�����ʽΪNPC_D_MON_FILE_CREATE_MODE_ALARMʱ��Ч
		IN		NPC_INT							in_iAlarmEventNum,			//[IN]�����¼���
		IN		PNPC_S_TD_DATE_TIME				in_pStartTime,				//[IN]��ʼʱ��
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime					//[IN]����ʱ��
		) = 0;

	//�ͷ��ļ��б�
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_FileList_Release(
		IN		NPC_HANDLE						in_hFileList				//[IN]�ļ��б���
		) = 0;

	//�ƶ�����һ��
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_FileList_MoveFirst(
		IN		NPC_HANDLE						in_hFileList				//[IN]�ļ��б���
		) = 0;

	//���ļ��б��л�ȡ��һ���ļ�������FALSE��ʾû����һ���ļ����ú��������Ƴ���¼
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_FileList_GetNextFile(
		IN		NPC_HANDLE						in_hFileList,				//[IN]�ļ��б���
		OUT		PNPC_S_MON_FILE_HEAD_INFO		out_pFileHeadInfo			//[OUT]�ļ�ͷ��Ϣ���ɵ����߷����ڴ�
		) = 0;


	//--------------------------------------------------------------------------------
	//��ʼʵʱԤ��������ģʽ�������ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	//ͬʱֻ�ܲ���һ����������ΪʵʱԤ��������Ϊ�ط�¼���ļ�
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_Play(
		IN		NPC_INT							in_iStreamType,				//[IN]�������ͣ�-1��ȱʡ������0����������1��������1��2��������2���������
		IN		NPC_INT							in_iPlayType				//[IN]�������ͣ�0������Ƶ��1����Ƶ��2����Ƶ
		) = 0;

	//��ʼʵʱԤ�����ص�ģʽ�������ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	//�ú�������ý�����ص�������ý�����ӻص��������أ����ܵ���NPC_F_MPI_MON_Camera_GetMediaFrame��ȡ
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_Play(
		IN		NPC_INT							in_iStreamType,				//[IN]�������ͣ�-1��ȱʡ������0����������1��������1��2��������2���������
		IN		NPC_INT							in_iPlayType,				//[IN]�������ͣ�0������Ƶ��1����Ƶ��2����Ƶ
		IN		PNPC_F_MPI_MON_CALLBACK_CameraMediaData	in_pMediaCallback,	//[IN]ý�����ص�����
		IN		PNPC_VOID						in_pUserData				//[IN]�ص��û�����
		) = 0;

	//�����ļ�������ģʽ�������ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartPlayFile(
		IN		PNPC_S_MPI_MON_REC_FILE			in_pRecFile,				//[IN]¼���ļ���Ϣ
		IN		NPC_INT							in_iPlayType				//[IN]�������ͣ�0������Ƶ��1����Ƶ��2����Ƶ
		) = 0;

	//�����ļ����ص�ģʽ�������ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartPlayFile(
		IN		PNPC_S_MPI_MON_REC_FILE			in_pRecFile,				//[IN]¼���ļ���Ϣ
		IN		NPC_INT							in_iPlayType,				//[IN]�������ͣ�0������Ƶ��1����Ƶ��2����Ƶ
		IN		PNPC_F_MPI_MON_CALLBACK_CameraMediaData	in_pMediaCallback,	//[IN]ý�����ص�����
		IN		PNPC_VOID						in_pUserData				//[IN]�ص��û�����
		) = 0;

	//�����ļ�������ʱ�䣬����ģʽ�������ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartPlayFile(
		IN		PNPC_S_MPI_MON_REC_FILE			in_pRecFile,				//[IN]¼���ļ���Ϣ
		IN		NPC_BOOL						in_bIfCtrlTime,				//[IN]�Ƿ����ʱ�䣬����ʼʱ��ͽ���ʱ���Ƿ���Ч�����FALSE����ʾ���ļ���ʼ����
		IN		PNPC_S_TD_DATE_TIME				in_pBeginTime,				//[IN]��ʼʱ�䣬�������ļ�ʱ�䷶Χ��
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime,				//[IN]����ʱ�䣬�������ļ�ʱ�䷶Χ�ڣ������ڿ�ʼʱ��
		IN		NPC_INT							in_iPlayType				//[IN]�������ͣ�0������Ƶ��1����Ƶ��2����Ƶ
		) = 0;

	//��ʱ��λط�¼�񣬷��ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartPlaybackByTimeSect(
		IN		PNPC_S_TD_DATE_TIME				in_pBeginTime,				//[IN]��ʼʱ��
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime,				//[IN]����ʱ�䣬������ڿ�ʼʱ��
		IN		NPC_INT							in_iPlayType				//[IN]�������ͣ�0������Ƶ��1����Ƶ��2����Ƶ
		) = 0;

	//ֹͣ���ţ����ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_Stop() = 0;

	//���Ʋ��ţ�ֻ�ʺ�¼���ļ��طţ������ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_PlayControl(
		IN		NPC_INT							in_iCtrlCode,				//[IN]�����룬�μ�NPC_D_MON_PLAY_CTRL_*����
		IN		NPC_DWORD						in_dwCtrlParam				//[IN]���Ʋ��������ݿ�����ȷ��ֵ����
		) = 0;


	//--------------------------------------------------------------------------------
	//��ʼ�����Խ����������ȴ�ʵʱԤ�������ܿ�ʼ�����Խ���������������ͨ��NPC_F_MPI_MON_Camera_GetMediaFrame������ȡ������0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartTalk(
		IN		NPC_INT							in_iEncodeType=NPC_D_MON_CODEC_ID_AUDIO_16BITPCM,	//[IN]�������ͣ��μ�NPC_D_MON_CODEC_ID_AUDIO_*����
		IN		NPC_INT							in_iSampleBit=16,									//[IN]����λ��
		IN		NPC_INT							in_iSampleRate=8000									//[IN]������
		) = 0;

	//ֹͣ�����Խ�
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_StopTalk() = 0;

	//�����������ݣ�����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SendVocData(
		IN		NPC_DWORD						in_dwTimestamp,				//[IN]ʱ���
		IN		PNPC_BYTE						in_pVocDataBuf,				//[IN]�������ݻ�����
		IN		NPC_INT							in_iVocDataLen,				//[IN]�������ݳ���
		IN		NPC_INT							in_iTimeout					//[IN]���ͳ�ʱ���ȣ����룩
		) = 0;

	//����ý��������ͣ�����������ͣ�󣬷����������ٷ���ý�����ݸ��ͻ��ˣ�����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_CtrlMediaStream(
		IN		NPC_INT							in_iCtrlOrder,				//[IN]�������0����ͣ��1������
		IN		NPC_INT							in_iMediaType				//[IN]ý�����ͣ�0����Ƶ��1����Ƶ��2������Ƶ
		) = 0;

	//����ֻ��I֡��ָ�����ȫ֡���ָ�����ȫ֡�󣬻��I֡��ʼ���ͣ��ú���������ǿ��I֡���ܣ�����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_OnlyIFrame(
		IN		NPC_INT							in_iCtrlCode				//[IN]�����룬0��ֻ��I֡��1���ָ�����ȫ֡
		) = 0;

	//����ǿ�Ʒ���I֡������0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_RequForceIFrame() = 0;

	//�л�ͨ��������0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SwitchChannel(
		IN		NPC_INT							in_iSwitchChNo,				//[IN]�л����ͨ���ţ�-1��ʾͨ���Ų���
		IN		NPC_INT							in_iSwitchStreamNo			//[IN]�л���������ţ�0����������1����������-1��ʾ�����Ų���
		) = 0;

	//��ѯ��ǰͨ���ź������ţ�����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_QueryChannelStreamNo(
		OUT		PNPC_INT						out_pCurChNo,				//[OUT]��ǰͨ����
		OUT		PNPC_INT						out_pCurStreamNo			//[OUT]��ǰ������
		) = 0;

	//��ȡ��Ƶ�����ȼ������б�����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetVideoQualityCapList(
		OUT		PNPC_S_MPI_MON_VIDEO_CODEC_LEVEL_LIST	out_pVideoCodecLevelList	//[OUT]��Ƶ����ȼ��б�
		) = 0;

	//��ȡ��ǰ��Ƶ�����ȼ�
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetCurVideoQualityLevel(
		OUT		PNPC_INT						out_pLevelValue				//[OUT]�ȼ�ֵ�����Ϊ-1��ʾȱʡ���ã���û���豸�ȼ�
		) = 0;

	//������Ƶ�����ȼ�
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SetVideoQualityLevel(
		IN		NPC_INT							in_iLevelValue				//[IN]�ȼ�ֵ�����ڵ���0����Ϊ-1�����Ϊ-1��ʾȱʡ����
		) = 0;


	//--------------------------------------------------------------------------------
	//��ȡ֡���ݣ�����NULL��ʾû�л�ȡ���������������أ�֡����ʹ����������NPC_F_MPI_MON_Camera_ReleaseFrameData�����ͷ�
	virtual		PNPC_S_MPI_MON_MEDIA_FRAME	NPC_F_MPI_MON_Camera_GetMediaFrame(
		IN		NPC_INT							in_iGetMediaType			//[IN]��ȡý�����ͣ�0����Ϸ�ʽ��1����Ƶ��2����Ƶ��100����ʼ֡
		) = 0;

	//�ȴ���ȡ֡���ݣ���������Ƶ֡���Ի�Ϸ�ʽ��ȡ��֡����ʹ����������NPC_F_MPI_MON_Camera_ReleaseFrameData�����ͷ�
	virtual		PNPC_S_MPI_MON_MEDIA_FRAME	NPC_F_MPI_MON_Camera_GetMediaFrameFromQueue(
		IN		NPC_INT							in_iTimeout					//[IN]��ʱʱ�������룩
		) = 0;

	//�ͷ�֡����
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_ReleaseFrameData(
		IN		PNPC_S_MPI_MON_MEDIA_FRAME		in_pFrameData				//[IN]֡����ָ�룬�ͷź��ָ�벻������
		) = 0;

	//��ȡʣ�µ�֡��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetResidualFrameNum(
		IN		NPC_INT							in_iGetMediaType			//[IN]��ȡý�����ͣ�0����Ϸ�ʽ��1����Ƶ��2����Ƶ
		) = 0;


	//--------------------------------------------------------------------------------
	//PTZ���ƣ����ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_PtzControl(
		IN		NPC_INT							in_iPtzCmd,					//[IN]PTZ����μ�NPC_D_MON_PTZ_CMD_*����
		IN		NPC_DWORD						in_dwPtzData,				//[IN]PTZ����
		IN		NPC_DWORD						in_dwPtzExtParam1,			//[IN]PTZ��չ����1
		IN		NPC_DWORD						in_dwPtzExtParam2			//[IN]PTZ��չ����2
		) = 0;


	//--------------------------------------------------------------------------------
	//�ֶ�����¼�񣬷��ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StartRecord() = 0;

	//�ֶ�ֹͣ¼�񣬷��ز�������룬����0��ʾ�ɹ�������Ϊʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_StopRecord() = 0;

	//��⵱ǰ¼��״̬��¼��ʱ��������TRUE��ʾ����¼��FALSE��ʾδ¼��
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_CheckRecordState() = 0;


	//----------------------------------------------------------------------------------
	//������ȡ������Ϣ����ȡ������������豸�����б�����Ϣ������NPC_F_MPI_MON_Camera_GetAlarmInfoѭ����ⱨ����Ϣ
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_StartGetAlarmInfo() = 0;

	//ֹͣ��ȡ������Ϣ
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_StopGetAlarmInfo() = 0;

	//��⵱ǰ����״̬������TRUE��ʾ�Ѵ򿪻�ȡ������Ϣ���أ�FALSE��ʾδ��
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_CheckAlarmState() = 0;

	//��ȡ������Ϣ��������Ϣ������ʹ����������NPC_F_MPI_MON_Camera_ReleaseAlarmBuf�ͷ�
	virtual		PNPC_S_MPI_MON_ALARM_DATA	NPC_F_MPI_MON_Camera_GetAlarmInfo(
		IN		NPC_INT							in_iTimeout					//[IN]�ȴ���ʱʱ�������룩
		) = 0;

	//���ñ�����Ϣ�ص�������ȱʡΪ���з�ʽ��������øú��������˻ص����������ٽ�������Ϣ�������
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_SetAlarmCallback(
		IN		PNPC_F_MPI_MON_CALLBACK_CameraAlarmData		in_pCallback,	//[IN]�ص�����ָ�룬���ΪNULL����ȡ���ص������ö��з�ʽ
		IN		PNPC_VOID									in_pUserData	//[IN]�û�����
		) = 0;

	//�ͷű�����Ϣ������
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_ReleaseAlarmBuf(
		IN		PNPC_S_MPI_MON_ALARM_DATA		in_pAlarmBuf				//[IN]������Ϣ������
		) = 0;


	//----------------------------------------------------------------------------------
	//��ʼ����¼���ļ�
	virtual		NPC_BOOL	NPC_F_MPI_MON_Camera_RecFile_StartDown(
		IN		PNPC_CHAR						in_pFileName,				//[IN]�����ļ�����Ϊ��ѯ�������ص��ļ���
		IN		NPC_BOOL						in_bIfCtrlTime,				//[IN]�Ƿ����ʱ�䣬����ʼʱ��ͽ���ʱ���Ƿ���Ч�����FALSE����ʾ���ļ���ʼ����
		IN		PNPC_S_TD_DATE_TIME				in_pBeginTime,				//[IN]��ʼʱ�䣬�������ļ�ʱ�䷶Χ��
		IN		PNPC_S_TD_DATE_TIME				in_pEndTime,				//[IN]����ʱ�䣬�������ļ�ʱ�䷶Χ�ڣ������ڿ�ʼʱ��
		OUT		PNPC_DWORD						out_pDownloadId				//[OUT]����ID
		) = 0;

	//ֹͣ����¼���ļ�
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_RecFile_StopDown(
		IN		NPC_DWORD						in_dwDownloadId				//[IN]����ID
		) = 0;

	//��ѯ����״̬��״ֵ̬�μ�NPC_D_MPI_MON_CAMERA_DOWN_STATE_*����
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_RecFile_QueryDownState(
		IN		NPC_DWORD						in_dwDownloadId				//[IN]����ID
		) = 0;

	//��ȡ���ذٷֱȣ�����ֵΪ0~100
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_RecFile_GetDownPercent(
		IN		NPC_DWORD						in_dwDownloadId				//[IN]����ID
		) = 0;

	//�ȴ���ȡ���ص�֡���ݣ���������Ƶ֡��֡����ʹ����������NPC_F_MPI_MON_Camera_ReleaseFrameData�����ͷ�
	virtual		PNPC_S_MPI_MON_MEDIA_FRAME	NPC_F_MPI_MON_Camera_RecFile_GetDownFrameData(
		IN		NPC_DWORD						in_dwDownloadId,			//[IN]����ID
		IN		NPC_INT							in_iTimeout					//[IN]��ʱʱ�������룩
		) = 0;


	//----------------------------------------------------------------------------------
	//�޸��豸���룬����0����ʾ�ɹ�������Ϊ����ԭ��ʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ModifyDevPwd(
		IN		PNPC_CHAR						in_pUserName,				//[IN]�û���
		IN		PNPC_CHAR						in_pOldPwd,					//[IN]ԭ����
		IN		PNPC_CHAR						in_pNewPwd					//[IN]������
		) = 0;


	//----------------------------------------------------------------------------------
	//��ȡ���ã�����0����ʾ�ɹ���������ʾʧ�ܣ���ʱ��������ʹ���������չ������
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetConfig(
		IN		NPC_INT							in_iCfgFuncId,				//[IN]���ù���ID���μ�NPC_D_PVM_CFG_FUNCID_*����
		OUT		PNPC_BYTE*						out_ppRspCfgDataBuf,		//[OUT]Ӧ���������ݻ��������ɸú��������ڴ棬��Ҫ����NPC_F_MPI_MON_Camera_ReleaseBuf�����ͷţ��������ݽṹ�μ�NPC_PVM_OrderCfgDef.h�ļ��еĶ���
		OUT		PNPC_INT						out_pRspCfgDataLen			//[OUT]Ӧ���������ݳ���
		) = 0;

	//��ȡ���ã���չ��������0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetConfig(
		IN		NPC_INT							in_iCfgFuncId,				//[IN]���ù���ID���μ�NPC_D_PVM_CFG_FUNCID_*����
		IN		PNPC_BYTE						in_pReqCfgDataBuf,			//[IN]�����������ݻ��������������ݽṹ�μ�NPC_PVM_OrderCfgDef.h�ļ��еĶ���
		IN		NPC_INT							in_iReqCfgDataLen,			//[IN]�����������ݳ���
		OUT		PNPC_BYTE*						out_ppRspCfgDataBuf,		//[OUT]Ӧ���������ݻ��������ɸú��������ڴ棬��Ҫ����NPC_F_MPI_MON_Camera_ReleaseBuf�����ͷţ��������ݽṹ�μ�NPC_PVM_OrderCfgDef.h�ļ��еĶ���
		OUT		PNPC_INT						out_pRspCfgDataLen			//[OUT]Ӧ���������ݳ���
		) = 0;

	//�������ã�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SetConfig(
		IN		NPC_INT							in_iCfgFuncId,				//[IN]���ù���ID���μ�NPC_D_PVM_CFG_FUNCID_*����
		IN		PNPC_BYTE						in_pCfgDataBuf,				//[IN]�������ݻ��������������ݽṹ�μ�NPC_PVM_OrderCfgDef.h�ļ��еĶ���
		IN		NPC_INT							in_iCfgDataLen				//[IN]�������ݳ���
		) = 0;

	//��ȡȱʡ���ò���������0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetDefConfig(
		IN		NPC_INT							in_iCfgFuncId,				//[IN]���ù���ID���μ�NPC_D_PVM_CFG_FUNCID_*����
		IN		NPC_INT							in_iChNo,					//[IN]ͨ����
		OUT		PNPC_BYTE*						out_ppRspCfgDataBuf,		//[OUT]Ӧ���������ݻ��������ɸú��������ڴ棬��Ҫ����NPC_F_MPI_MON_Camera_ReleaseBuf�����ͷţ��������ݽṹ�μ�NPC_PVM_OrderCfgDef.h�ļ��еĶ���
		OUT		PNPC_INT						out_pRspCfgDataLen			//[OUT]Ӧ���������ݳ���
		) = 0;

	//�������ã�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ImportConfig(
		IN		PNPC_BYTE						in_pCfgDataBuf,				//[IN]�������ݻ��������������ݽṹ�μ�NPC_PVM_OrderCfgDef.h�ļ��еĶ���
		IN		NPC_INT							in_iCfgDataLen				//[IN]�������ݳ���
		) = 0;

	//�������ã�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ExportConfig(
		OUT		PNPC_BYTE*						out_ppRspCfgDataBuf,		//[OUT]Ӧ���������ݻ��������ɸú��������ڴ棬��Ҫ����NPC_F_MPI_MON_Camera_ReleaseBuf�����ͷţ��������ݽṹ�μ�NPC_PVM_OrderCfgDef.h�ļ��еĶ���
		OUT		PNPC_INT						out_pRspCfgDataLen			//[OUT]Ӧ���������ݳ���
		) = 0;


	//----------------------------------------------------------------------------------
	//�򿪴��ڣ�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ComOpen(
		IN		NPC_INT							in_iComType,				//[IN]�������ͣ�0��RS232���ڣ�1��RS485����
		IN		NPC_INT							in_iPortNo,					//[IN]�˿ں�
		IN		NPC_INT							in_iBaudRate,				//[IN]�����ʣ���4800��14400��28800��36600
		IN		NPC_INT							in_iDataBit,				//[IN]����λ����8λ
		IN		NPC_INT							in_iStopBit,				//[IN]ֹͣλ����1
		IN		NPC_INT							in_iCheckBit				//[IN]��żУ��λ
		) = 0;

	//�رմ���
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_ComClose(
		IN		NPC_INT							in_iComType,				//[IN]�������ͣ�0��RS232���ڣ�1��RS485����
		IN		NPC_INT							in_iPortNo					//[IN]�˿ں�
		) = 0;

	//���ʹ������ݣ�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_ComSendData(
		IN		NPC_INT							in_iComType,				//[IN]�������ͣ�0��RS232���ڣ�1��RS485����
		IN		NPC_INT							in_iPortNo,					//[IN]�˿ں�
		IN		PNPC_BYTE						in_pSendDataBuf,			//[IN]�������ݻ�������ָ���͸����ڵ�����
		IN		NPC_INT							in_iSendDataLen				//[IN]�������ݳ���
		) = 0;


	//----------------------------------------------------------------------------------
	//�����û�������0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_AddUser(
		IN		PNPC_CHAR						in_pUserName,				//[IN]�û���
		IN		PNPC_CHAR						in_pUserPwd,				//[IN]�û�����
		IN		NPC_DWORD						in_dwGlobalPop,				//[IN]ȫ��Ȩ�ޣ�λֵ�ο�NPC_D_MON_DEV_POP_*����
		IN		NPC_INT							in_iChNum,					//[IN]ͨ�������ýṹ��֮��Ϊͨ��Ȩ�ޱ�ÿ4�ֽ�Ϊһ��ͨ����Ȩ�ޣ�4�ֽڵ�˳���Ϊͨ���ţ�λֵ�ο�NPC_D_MON_DEV_POP_*����
		IN		PNPC_DWORD						in_pChPopTable				//[IN]ͨ��Ȩ�ޱ�����������Ϊͨ���ţ�λֵ�ο�NPC_D_MON_DEV_POP_*���壬���64��ͨ��
		) = 0;

	//ɾ���û�������0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_DeleteUser(
		IN		PNPC_CHAR						in_pUserName				//[IN]�û���
		) = 0;

	//��ȡ�û�Ȩ���б�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_GetUserPop(
		IN		PNPC_CHAR						in_pUserName,				//[IN]�û���
		OUT		PNPC_DWORD						out_pGlobalPop,				//[IN]ȫ��Ȩ�ޣ�λֵ�ο�NPC_D_MON_DEV_POP_*����
		OUT		PNPC_INT						out_pChNum,					//[IN]ͨ�������ýṹ��֮��Ϊͨ��Ȩ�ޱ�ÿ4�ֽ�Ϊһ��ͨ����Ȩ�ޣ�4�ֽڵ�˳���Ϊͨ���ţ�λֵ�ο�NPC_D_MON_DEV_POP_*����
		OUT		PNPC_DWORD						out_pChPopTable				//[IN]ͨ��Ȩ�ޱ�����������Ϊͨ���ţ����������ϲ���䣬����64��4�ֽ��������飬λֵ�ο�NPC_D_MON_DEV_POP_*���壬���64��ͨ��
		) = 0;

	//�����û�Ȩ���б�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SetUserPop(
		IN		PNPC_CHAR						in_pUserName,				//[IN]�û���
		IN		NPC_DWORD						in_dwGlobalPop,				//[IN]ȫ��Ȩ�ޣ�λֵ�ο�NPC_D_MON_DEV_POP_*����
		IN		NPC_INT							in_iChNum,					//[IN]ͨ�������ýṹ��֮��Ϊͨ��Ȩ�ޱ�ÿ4�ֽ�Ϊһ��ͨ����Ȩ�ޣ�4�ֽڵ�˳���Ϊͨ���ţ�λֵ�ο�NPC_D_MON_DEV_POP_*����
		IN		PNPC_DWORD						in_pChPopTable				//[IN]ͨ��Ȩ�ޱ�����������Ϊͨ���ţ�λֵ�ο�NPC_D_MON_DEV_POP_*���壬���64��ͨ��
		) = 0;


	//----------------------------------------------------------------------------------
	//���ö��ƹ��ܣ�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_CallCustomFunc(
		IN		NPC_INT							in_iCusFuncId,				//[IN]���ƹ���ID���μ�����ļ��еĶ���
		IN		PNPC_BYTE						in_pCusBodyBuf,				//[IN]���ư��建����
		IN		NPC_INT							in_iCusBodyLen,				//[IN]���ư��峤��
		OUT		PNPC_BYTE*						out_ppRespBodyBuf,			//[OUT]Ӧ����建�������ɸú��������ڴ棬�����NPC_F_MPI_MON_Camera_ReleaseBuf�ͷ�
		OUT		PNPC_INT						out_pRespBodyLen			//[OUT]Ӧ����峤��
		) = 0;


	//----------------------------------------------------------------------------------
	//��ѯ������������0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_QueryAbility(
		IN		NPC_INT							in_iRequVerNo,				//[IN]����汾��
		OUT		PNPC_BYTE*						out_ppAbilityDataBuf,		//[OUT]���������ݻ��������ɸú��������ڴ棬�����NPC_F_MPI_MON_Camera_ReleaseBuf�ͷ�
		OUT		PNPC_INT						out_pAbilityDataLen			//[OUT]���������ݳ���
		) = 0;

	//�����豸������0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_DevReboot() = 0;

	//�ر��豸������0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_DevClose() = 0;


	//----------------------------------------------------------------------------------
	//��ѯ�豸�汾��Ϣ������0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_QueryDevVerInfo(
		OUT		PNPC_USHORT						out_pModuleType,			//ģ������,0:δ֪����,1:UI,2:SYS,3:UI&SYS�����ϲ�����ڴ棬Ϊ4��NPC_USHORT����
		OUT		PNPC_UINT						out_pModuleVerNo			//ģ��汾��,��˳���Ӧģ������,��ʽΪ:x.x.x.x,ÿ�ֽ�Ϊһ���ţ����ϲ�����ڴ棬Ϊ4��NPC_UINT����
		) = 0;

	//��������������0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_RequestUpgrade(
		IN		NPC_USHORT						in_usModuleType,			//ģ������,0:δ֪����,1:UI,2:SYS,3:UI&SYS
		IN		NPC_USHORT						in_usCheckSum,				//�ļ������
		IN		NPC_INT							in_iFileSize,				//�����ļ���С(�ֽ�)
		OUT		PNPC_UINT						out_pUpgradeId				//����ID
		) = 0;

	//��ѯ�������ȣ�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_QueryUpgradeProgress(
		IN		NPC_UINT						in_uiUpgradeId,				//����ID
		OUT		PNPC_INT						out_pUpgProgress			//��������,ֵΪ0~100,ָдFLASH�Ľ���
		) = 0;

	//���������ļ����ݣ����Զ�η��ͣ�����0����ʾ�ɹ���������ʾʧ��
	virtual		NPC_INT		NPC_F_MPI_MON_Camera_SendUpgradeFileData(
		IN		NPC_UINT						in_uiUpgradeId,				//����ID
		IN		PNPC_BYTE						in_pFileDataBuf,			//�ļ����ݻ�����
		IN		NPC_INT							in_iFileDataLen				//�ļ����ݳ���
		) = 0;


	//----------------------------------------------------------------------------------
	//�ͷ����ݻ��������ɵײ����Ļ�����
	virtual		NPC_VOID	NPC_F_MPI_MON_Camera_ReleaseBuf(
		IN		PNPC_BYTE						in_pDataBuf					//[IN]���������ɵײ����Ļ�����
		) = 0;
};



#endif

