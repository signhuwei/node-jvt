/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_DPS_PRO_NI_Custom.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2013-10-14
 * Description   :  MP3定制协议定义
 *----------------------------------------------------------------------------*/

#ifndef __NPC_DPS_PRO_NI_CUSTOM_H
#define __NPC_DPS_PRO_NI_CUSTOM_H

#include "NPC_TypeDef.h"


//------------------------------------------------------------------------------
//常量定义
#define NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN					256				//最大MP3文件名长度


//------------------------------------------------------------------------------
//功能ID定义
#define NPC_D_DPS_CUSTOM_NI_FUNCID_QUERY_MP3_FILE_LIST				0x0101			//查询MP3文件列表
#define NPC_D_DPS_CUSTOM_NI_FUNCID_DELETE_MP3_FILE					0x0102			//删除MP3文件
#define NPC_D_DPS_CUSTOM_NI_FUNCID_START_PLAY_MP3_FILE				0x0103			//开始播放MP3文件
#define NPC_D_DPS_CUSTOM_NI_FUNCID_STOP_PLAY_MP3_FILE				0x0104			//停止播放MP3文件
#define NPC_D_DPS_CUSTOM_NI_FUNCID_CTRL_VOLUME						0x0105			//控制音量
#define NPC_D_DPS_CUSTOM_NI_FUNCID_START_UPLOAD_MP3_FILE			0x0106			//开始上传文件
#define NPC_D_DPS_CUSTOM_NI_FUNCID_STOP_UPLOAD_MP3_FILE				0x0107			//停止上传文件
#define NPC_D_DPS_CUSTOM_NI_FUNCID_UPLOAD_FILE_DATA					0x0108			//上传文件数据


//------------------------------------------------------------------------------
//查询MP3文件列表
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_QUERY_MP3_FILE_LIST
{
	NPC_INT											o_iFilNum;						//文件数

} NPC_S_DPS_CUSTOM_NI_BODY_QUERY_MP3_FILE_LIST, *PNPC_S_DPS_CUSTOM_NI_BODY_QUERY_MP3_FILE_LIST;

//MP3文件信息
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_MP3_FILE_INFO
{
	NPC_CHAR										sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//文件名
	NPC_BOOL										bIfPlaying;												//是否在播放

} NPC_S_DPS_CUSTOM_NI_BODY_MP3_FILE_INFO, *PNPC_S_DPS_CUSTOM_NI_BODY_MP3_FILE_INFO;

//删除MP3文件
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_DELETE_MP3_FILE
{
	NPC_CHAR										sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//文件名

} NPC_S_DPS_CUSTOM_NI_BODY_DELETE_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_DELETE_MP3_FILE;

//开始播放MP3文件
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_START_PLAY_MP3_FILE
{
	NPC_CHAR										sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//文件名

} NPC_S_DPS_CUSTOM_NI_BODY_START_PLAY_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_START_PLAY_MP3_FILE;

//停止播放MP3文件
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_STOP_PLAY_MP3_FILE
{
	NPC_CHAR										sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//文件名

} NPC_S_DPS_CUSTOM_NI_BODY_STOP_PLAY_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_STOP_PLAY_MP3_FILE;

//控制音量
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_CTRL_VOLUME
{
	NPC_CHAR										i_sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//文件名
	NPC_INT											i_iVolumeSize;											//音量大小，0~20

} NPC_S_DPS_CUSTOM_NI_BODY_CTRL_VOLUME, *PNPC_S_DPS_CUSTOM_NI_BODY_CTRL_VOLUME;

//开始上传文件
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_START_UPLOAD_MP3_FILE
{
	NPC_CHAR										i_sFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//文件名（客户端本地的文件名）
	NPC_DWORD										i_dwFileSize;											//文件大小（字节）

	NPC_DWORD										o_dwUploadId;											//上传ID
	NPC_CHAR										o_sSaveFileName[NPC_D_DPS_CUSTOM_NI_MAX_MP3_FILENAME_LEN];	//存储在设备中的文件名

} NPC_S_DPS_CUSTOM_NI_BODY_START_UPLOAD_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_START_UPLOAD_MP3_FILE;

//停止上传文件
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_STOP_UPLOAD_MP3_FILE
{
	NPC_DWORD										i_dwUploadId;											//上传ID

} NPC_S_DPS_CUSTOM_NI_BODY_STOP_UPLOAD_MP3_FILE, *PNPC_S_DPS_CUSTOM_NI_BODY_STOP_UPLOAD_MP3_FILE;

//上传文件数据，在该结构体之后为文件数据
typedef struct _NPC_S_DPS_CUSTOM_NI_BODY_UPLOAD_FILE_DATA
{
	NPC_DWORD										i_dwUploadId;											//上传ID
	NPC_INT											i_iDataLen;												//数据长度

} NPC_S_DPS_CUSTOM_NI_BODY_UPLOAD_FILE_DATA, *PNPC_S_DPS_CUSTOM_NI_BODY_UPLOAD_FILE_DATA;


#endif


