/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_DPS_PRO_NI_Custom.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2013-10-14
 * Description   :  MP3����Э�鶨��
 *----------------------------------------------------------------------------*/

#ifndef __NPC_DPS_PRO_NI_CUSTOM_H
#define __NPC_DPS_PRO_NI_CUSTOM_H

#include "NPC_TypeDef.h"


//------------------------------------------------------------------------------
//��������
#define NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN					256				//���MP3�ļ�������


//------------------------------------------------------------------------------
//����ID����
#define NPC_D_DPS_CUSTOM_NI_FUNCID_QUERY_MP3_FILE_LIST				0x0101			//��ѯMP3�ļ��б�
#define NPC_D_DPS_CUSTOM_NI_FUNCID_DELETE_MP3_FILE					0x0102			//ɾ��MP3�ļ�
#define NPC_D_DPS_CUSTOM_NI_FUNCID_START_PLAY_MP3_FILE				0x0103			//��ʼ����MP3�ļ�
#define NPC_D_DPS_CUSTOM_NI_FUNCID_STOP_PLAY_MP3_FILE				0x0104			//ֹͣ����MP3�ļ�
#define NPC_D_DPS_CUSTOM_NI_FUNCID_CTRL_VOLUME						0x0105			//��������
#define NPC_D_DPS_CUSTOM_NI_FUNCID_START_UPLOAD_MP3_FILE			0x0106			//��ʼ�ϴ��ļ�
#define NPC_D_DPS_CUSTOM_NI_FUNCID_STOP_UPLOAD_MP3_FILE				0x0107			//ֹͣ�ϴ��ļ�
#define NPC_D_DPS_CUSTOM_NI_FUNCID_UPLOAD_FILE_DATA					0x0108			//�ϴ��ļ�����


//------------------------------------------------------------------------------
//��ѯMP3�ļ��б�
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_QUERY_MP3_FILE_LIST
{
	NPC_INT											o_iFilNum;						//�ļ���

} NPC_S_DPS_CUSTOM_NI_BODY_QUERY_MP3_FILE_LIST, *PNPC_S_DPS_CUSTOM_NI_BODY_QUERY_MP3_FILE_LIST;

//MP3�ļ���Ϣ
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_MP3_FILE_INFO
{
	NPC_CHAR										sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//�ļ���
	NPC_BOOL										bIfPlaying;												//�Ƿ��ڲ���

} NPC_S_DPS_CUSTOM_NI_BODY_MP3_FILE_INFO, *PNPC_S_DPS_CUSTOM_NI_BODY_MP3_FILE_INFO;

//ɾ��MP3�ļ�
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_DELETE_MP3_FILE
{
	NPC_CHAR										sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//�ļ���

} NPC_S_DPS_CUSTOM_NI_BODY_DELETE_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_DELETE_MP3_FILE;

//��ʼ����MP3�ļ�
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_START_PLAY_MP3_FILE
{
	NPC_CHAR										sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//�ļ���

} NPC_S_DPS_CUSTOM_NI_BODY_START_PLAY_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_START_PLAY_MP3_FILE;

//ֹͣ����MP3�ļ�
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_STOP_PLAY_MP3_FILE
{
	NPC_CHAR										sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//�ļ���

} NPC_S_DPS_CUSTOM_NI_BODY_STOP_PLAY_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_STOP_PLAY_MP3_FILE;

//��������
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_CTRL_VOLUME
{
	NPC_CHAR										i_sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//�ļ���
	NPC_INT											i_iVolumeSize;											//������С��0~20

} NPC_S_DPS_CUSTOM_NI_BODY_CTRL_VOLUME, *PNPC_S_DPS_CUSTOM_NI_BODY_CTRL_VOLUME;

//��ʼ�ϴ��ļ�
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_START_UPLOAD_MP3_FILE
{
	NPC_CHAR										i_sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//�ļ������ͻ��˱��ص��ļ�����
	NPC_DWORD										i_dwFileSize;											//�ļ���С���ֽڣ�

	NPC_DWORD										o_dwUploadId;											//�ϴ�ID
	NPC_CHAR										o_sSaveFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//�洢���豸�е��ļ���

} NPC_S_DPS_CUSTOM_NI_BODY_START_UPLOAD_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_START_UPLOAD_MP3_FILE;

//ֹͣ�ϴ��ļ�
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_STOP_UPLOAD_MP3_FILE
{
	NPC_DWORD										i_dwUploadId;											//�ϴ�ID

} NPC_S_DPS_CUSTOM_NI_BODY_STOP_UPLOAD_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_STOP_UPLOAD_MP3_FILE;

//�ϴ��ļ����ݣ��ڸýṹ��֮��Ϊ�ļ�����
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_UPLOAD_FILE_DATA
{
	NPC_DWORD										i_dwUploadId;											//�ϴ�ID
	NPC_INT											i_iDataLen;												//���ݳ���

} NPC_S_DPS_CUSTOM_NI_BODY_UPLOAD_FILE_DATA, *PNPC_S_DPS_CUSTOM_NI_BODY_UPLOAD_FILE_DATA;


#endif


