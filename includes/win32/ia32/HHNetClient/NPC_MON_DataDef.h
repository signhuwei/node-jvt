/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MON_DataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-11
 * Description   :  监控平台常量定义
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MON_DATADEF_H
#define __NPC_MON_DATADEF_H

#include "NPC_TypeDef.h"


//常量定义
#define NPC_D_MON_IPADDR_BUFSIZE								40				//IP地址缓冲区大小
#define NPC_D_MON_NODEID_BUFSIZE								32				//结点ID缓冲区大小
#define NPC_D_MON_FILENAME_BUFSIZE								128				//文件名缓冲区大小
#define NPC_D_MON_CAMERAID_BUFSIZE								32				//摄像机ID缓冲区大小
#define NPC_D_MON_DEVID_BUFSIZE									32				//设备ID缓冲区大小（如摄像机ID或DVRID）
#define NPC_D_MON_DEV_CONN_PARAM_BUFSIZE						1024			//连接参数缓冲区大小

#define NPC_D_MON_USERID_BUFSIZE								32				//用户ID缓冲区大小
#define NPC_D_MON_USERNAME_BUFSIZE								32				//用户名缓冲区大小
#define NPC_D_MON_USERPWD_BUFSIZE								32				//用户密码缓冲区大小
#define NPC_D_MON_SERVER_ID_BUFSIZE								32				//服务器ID缓冲区大小
#define NPC_D_MON_ALARM_BUF_SIZE								512				//报警信息缓冲区大小

//设备连接模式定义
#define NPC_D_MON_DEV_CONN_MODE_DIRECT							0				//直连模式
#define NPC_D_MON_DEV_CONN_MODE_STREAM							1				//流媒体服务器模式
#define NPC_D_MON_DEV_CONN_MODE_CLOUD_P2P						2				//P2P云模式
#define NPC_D_MON_DEV_CONN_MODE_CLOUD_STREAM					3				//云流媒体模式

//媒体类型定义
#define NPC_D_MON_MEDIA_TYPE_VIDEO								0				//视频
#define NPC_D_MON_MEDIA_TYPE_AUDIO								1				//音频
#define NPC_D_MON_MEDIA_TYPE_PICTURE							2				//图片
#define NPC_D_MON_MEDIA_TYPE_START								100				//开始帧

//视频帧类型定义
#define NPC_D_MON_VIDEO_FRAME_TYPE_I							1				//I帧
#define NPC_D_MON_VIDEO_FRAME_TYPE_P							2				//P帧
#define NPC_D_MON_VIDEO_FRAME_TYPE_B							3				//B帧
#define NPC_D_MON_VIDEO_FRAME_TYPE_SPS							10				//H264的SPS帧
#define NPC_D_MON_VIDEO_FRAME_TYPE_PPS							11				//H264的PPS帧
#define NPC_D_MON_VIDEO_FRAME_TYPE_VOL							12				//MPEG4的VOL帧

//编码ID定义
#define NPC_D_MON_CODEC_ID_VEDIO_H264							10				//H264
#define NPC_D_MON_CODEC_ID_VEDIO_MPEG4							11				//MPEG4
#define NPC_D_MON_CODEC_ID_VEDIO_MJPG							12				//MJPG
#define NPC_D_MON_CODEC_ID_VEDIO_H265							13				//H265

#define NPC_D_MON_CODEC_ID_AUDIO_AAC							20				//AAC
#define NPC_D_MON_CODEC_ID_AUDIO_PCMA							21				//PCMA（G711A）
#define NPC_D_MON_CODEC_ID_AUDIO_PCMU							22				//PCMU（G711U）
#define NPC_D_MON_CODEC_ID_AUDIO_ADPCM							23				//ADPCM
#define NPC_D_MON_CODEC_ID_AUDIO_G726							24				//G726
#define NPC_D_MON_CODEC_ID_AUDIO_AMRNB							25				//AMRNB
#define NPC_D_MON_CODEC_ID_AUDIO_ADPCM_DJ						26				//ADPCM_DJ

#define NPC_D_MON_CODEC_ID_AUDIO_16BITPCM						30				//16线性PCM

//视频分辨率
#define NPC_D_MON_VEDIO_RESOLUTION_1080P						1				//1080P
#define NPC_D_MON_VEDIO_RESOLUTION_720P							2				//720P
#define NPC_D_MON_VEDIO_RESOLUTION_D1							3				//D1
#define NPC_D_MON_VEDIO_RESOLUTION_HD1							4				//HD1
#define NPC_D_MON_VEDIO_RESOLUTION_BCIF							5				//BCIF
#define NPC_D_MON_VEDIO_RESOLUTION_CIF							6				//CIF
#define NPC_D_MON_VEDIO_RESOLUTION_QCIF							7				//QCIF
#define NPC_D_MON_VEDIO_RESOLUTION_VGA							8				//VGA
#define NPC_D_MON_VEDIO_RESOLUTION_QVGA							9				//QVGA
#define NPC_D_MON_VEDIO_RESOLUTION_SVCD							10				//SVCD
#define NPC_D_MON_VEDIO_RESOLUTION_QQVGA						11				//QQVGA
#define NPC_D_MON_VEDIO_RESOLUTION_SXVGA						12				//SXVGA
#define NPC_D_MON_VEDIO_RESOLUTION_UXGA							13				//UXGA

//码流控制模式
#define NPC_D_MON_BITRATECTRL_CBR								1				//固定码流
#define NPC_D_MON_BITRATECTRL_VBR								2				//可变码流
#define NPC_D_MON_BITRATECTRL_MBR								3				//混和码流

//录像回放或点播控制码定义
#define NPC_D_MON_PLAY_CTRL_PAUSE								1				//暂停（无参数）
#define NPC_D_MON_PLAY_CTRL_RESUME								2				//继续（无参数）
#define NPC_D_MON_PLAY_CTRL_SET_FRAME_RATE						3				//设置帧率（参数为帧率）
#define NPC_D_MON_PLAY_CTRL_SET_PLAY_POS						4				//设置播放位置（参数为位置（秒））
#define NPC_D_MON_PLAY_CTRL_SET_FAST_FORWARD					5				//快进（无参数），保持原帧率，丢掉部分帧
#define NPC_D_MON_PLAY_CTRL_SET_SLOW_FORWARD					6				//慢进（无参数）
#define NPC_D_MON_PLAY_CTRL_SET_FAST_BACKWARD					7				//快退（无参数），保持原帧率，丢掉部分帧
#define NPC_D_MON_PLAY_CTRL_SET_SLOW_BACKWARD					8				//慢退（无参数）
#define NPC_D_MON_PLAY_CTRL_SET_FRAME_FORWARD					9				//单帧进（无参数）
#define NPC_D_MON_PLAY_CTRL_SET_FRAME_BACKWARD					10				//单帧退（无参数）
#define NPC_D_MON_PLAY_CTRL_ONLY_IFRAME							11				//请求只回放I帧数据（参数为丢弃I帧数，0：不丢I帧，1：丢弃1个I帧（即间隔1个I帧传输），2：丢弃2个I帧，如此类推）
#define NPC_D_MON_PLAY_CTRL_RECOVER_ALLFRAME					12				//请求恢复回放全帧数据（无参数）

//录像文件位置
#define NPC_D_MON_REC_FILE_POS_DEV								1				//设备上
#define NPC_D_MON_REC_FILE_POS_SERVER							2				//服务器上

//日志信息类型定义
#define NPC_D_MON_LOG_INFO_TYPE_ERROR							0				//错误日志
#define NPC_D_MON_LOG_INFO_TYPE_TRACE							1				//跟踪日志


//PTZ命令定义
#define NPC_D_MON_PTZ_CMD_STOP									0				//停止运动，停止前一个启动命令

#define NPC_D_MON_PTZ_CMD_LIGHT_PWRON							2				//接通灯光电源，无参数
#define NPC_D_MON_PTZ_CMD_WIPER_PWRON							3				//接通雨刷开关，无参数
#define NPC_D_MON_PTZ_CMD_FAN_PWRON								4				//接通风扇开关，无参数
#define NPC_D_MON_PTZ_CMD_HEATER_PWRON							5				//接通加热器开关，无参数
#define NPC_D_MON_PTZ_CMD_AUX_PWRON1							6				//接通辅助设备开关1，无参数
#define NPC_D_MON_PTZ_CMD_AUX_PWRON2							7				//接通辅助设备开关2，无参数
#define NPC_D_MON_PTZ_CMD_SET_PRESET							8				//设置预置点，in_dwPtzData为预置点的序号（1至255）
#define NPC_D_MON_PTZ_CMD_CLE_PRESET							9				//清除预置点，in_dwPtzData为预置点的序号（1至255）

#define NPC_D_MON_PTZ_CMD_ZOOM_IN								11				//焦距以速度SS变大（倍率变大），in_dwPtzData为速度（1至10），云镜速度初始值为4，in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）
#define NPC_D_MON_PTZ_CMD_ZOOM_OUT								12				//焦距以速度SS变小（倍率变小），同上
#define NPC_D_MON_PTZ_CMD_FOCUS_NEAR							13  			//焦点以速度SS前调，同上
#define NPC_D_MON_PTZ_CMD_FOCUS_FAR								14  			//焦点以速度SS后调，同上
#define NPC_D_MON_PTZ_CMD_IRIS_OPEN								15  			//光圈以速度SS扩大，同上
#define NPC_D_MON_PTZ_CMD_IRIS_CLOSE							16  			//光圈以速度SS缩小，同上

#define NPC_D_MON_PTZ_CMD_TILT_UP								21				//云台以SS的速度上仰，in_dwPtzData为速度（1至10），云台速度初始值为4，in_dwPtzExtParam1为是否自动停止（1或0），in_dwPtzExtParam2为自动停止的间隔时间（1至255秒）
#define NPC_D_MON_PTZ_CMD_TILT_DOWN								22				//云台以SS的速度下俯，同上
#define NPC_D_MON_PTZ_CMD_PAN_LEFT								23				//云台以SS的速度左转，同上
#define NPC_D_MON_PTZ_CMD_PAN_RIGHT								24				//云台以SS的速度右转，同上
#define NPC_D_MON_PTZ_CMD_UP_LEFT								25				//云台以SS的速度上仰和左转，同上
#define NPC_D_MON_PTZ_CMD_UP_RIGHT								26				//云台以SS的速度上仰和右转，同上
#define NPC_D_MON_PTZ_CMD_DOWN_LEFT								27				//云台以SS的速度下俯和左转，同上
#define NPC_D_MON_PTZ_CMD_DOWN_RIGHT							28				//云台以SS的速度下俯和右转，同上
#define NPC_D_MON_PTZ_CMD_PAN_AUTO								29				//云台以SS的速度左右自动扫描，同上

#define NPC_D_MON_PTZ_CMD_FILL_PRE_SEQ							30				//将预置点加入巡航序列，in_dwPtzData为巡航路径号（1至32），in_dwPtzExtParam1为预置点号（1至255），in_dwPtzExtParam2为停顿时间（1至255秒）
#define NPC_D_MON_PTZ_CMD_SET_SEQ_DWELL							31				//设置巡航点停顿时间，in_dwPtzData为巡航路径号（1至32），in_dwPtzExtParam1为预置点号（1至32），in_dwPtzExtParam2为停顿时间（1至255秒）
#define NPC_D_MON_PTZ_CMD_SET_SEQ_SPEED							32				//设置巡航速度，in_dwPtzData为巡航路径号（1至32），in_dwPtzExtParam1为预置点号（1至32），in_dwPtzExtParam2为速度（1至10）
#define NPC_D_MON_PTZ_CMD_CLE_PRE_SEQ							33				//将预置点从巡航序列中删除，in_dwPtzData为巡航路径号（1至32），in_dwPtzExtParam1为预置点号（1至255）
#define NPC_D_MON_PTZ_CMD_STA_MEM_CRUISE						34				//开始记录轨迹，，无参数
#define NPC_D_MON_PTZ_CMD_STO_MEM_CRUISE						35				//停止记录轨迹，无参数
#define NPC_D_MON_PTZ_CMD_RUN_CRUISE							36				//开始轨迹，无参数
#define NPC_D_MON_PTZ_CMD_RUN_SEQ								37				//开始巡航，in_dwPtzData为巡航路径号
#define NPC_D_MON_PTZ_CMD_STOP_SEQ								38				//停止巡航，in_dwPtzData为巡航路径号
#define NPC_D_MON_PTZ_CMD_GOTO_PRESET							39				//快球转到预置点，in_dwPtzData为预置点号
#define NPC_D_MON_PTZ_CMD_CLEAR_TOUR							40				//清除巡航，in_dwPtzData为巡航路径号

//报警类型定义
#define NPC_D_MON_ALARM_TYPE_DEV_FAULT							1				//设备故障报警（包括主动连接不上，注册模式离线）
#define NPC_D_MON_ALARM_TYPE_MOTION								2				//移动侦测报警
#define NPC_D_MON_ALARM_TYPE_VIDEO_BLIND						3				//视频遮挡报警
#define NPC_D_MON_ALARM_TYPE_VIDEO_LOSS							4				//视频丢失报警
#define NPC_D_MON_ALARM_TYPE_PROBE								5				//探头报警
#define NPC_D_MON_ALARM_TYPE_PIR								6				//人体感应报警
#define NPC_D_MON_ALARM_TYPE_DOORBELL							7				//门铃报警

//报警通知类型定义
#define NPC_D_MON_ALARM_NOTIFY_TYPE_PHONE_PUSH					1				//手机推送消息
#define NPC_D_MON_ALARM_NOTIFY_TYPE_SMS							2				//短信
#define NPC_D_MON_ALARM_NOTIFY_TYPE_EMAIL						3				//EMAIL

//报警联动类型定义
#define NPC_D_MON_ALARM_ACTION_TYPE_PHOTO						1				//拍照
#define NPC_D_MON_ALARM_ACTION_TYPE_VIDEO						2				//录像
#define NPC_D_MON_ALARM_ACTION_TYPE_PTZ							3				//PTZ联动

//报警控制
#define NPC_D_MON_ALARM_CTRL_ARM_PAUSE							1				//暂停布防
#define NPC_D_MON_ALARM_CTRL_ARM_CONTINUE						2				//继续布防
#define NPC_D_MON_ALARM_CTRL_NFT_PAUSE							3				//暂停通知
#define NPC_D_MON_ALARM_CTRL_NFT_CONTINUE						4				//继续通知
#define NPC_D_MON_ALARM_CTRL_ACT_PAUSE							5				//暂停报警联动
#define NPC_D_MON_ALARM_CTRL_ACT_CONTINUE						6				//继续报警联动

//录像文件类型
#define NPC_D_MON_REC_FILE_TYPE_ALL								0x00FF			//所有录像
#define NPC_D_MON_REC_FILE_TYPE_GENERAL							0x0001			//常规录像（定时录像）
#define NPC_D_MON_REC_FILE_TYPE_ALARM							0x0002			//移动侦测报警录像
#define NPC_D_MON_REC_FILE_TYPE_MALUAL							0x0004			//手动录像
#define NPC_D_MON_REC_FILE_TYPE_PROBE							0x0008			//输入（探头）报警录像
#define NPC_D_MON_REC_FILE_TYPE_PIR								0x0010			//人体感应报警录像
#define NPC_D_MON_REC_FILE_TYPE_DOORBELL						0x0020			//门铃报警录像
#define NPC_D_MON_REC_FILE_TYPE_SMART_IPC_CROSS_LINE			0x0040			//越线侦测报警录像
#define NPC_D_MON_REC_FILE_TYPE_SMART_IPC_AREA_INTRUSION		0x0080			//区域入侵报警录像

#define NPC_D_MON_REC_FILE_TYPE_PIC_ALL							0xFF00			//所有图片文件
#define NPC_D_MON_REC_FILE_TYPE_PIC_GENERAL						0x0100			//常规图片（定时）
#define NPC_D_MON_REC_FILE_TYPE_PIC_ALARM						0x0200			//移动侦测报警图片
#define NPC_D_MON_REC_FILE_TYPE_PIC_MALUAL						0x0400			//手动图片
#define NPC_D_MON_REC_FILE_TYPE_PIC_PROBE						0x0800			//输入（探头）报警图片
#define NPC_D_MON_REC_FILE_TYPE_PIC_PIR							0x1000			//人体感应报警图片
#define NPC_D_MON_REC_FILE_TYPE_PIC_DOORBELL					0x2000			//门铃报警图片
#define NPC_D_MON_REC_FILE_TYPE_PIC_SMART_IPC_CROSS_LINE		0x4000			//越线侦测报警图片
#define NPC_D_MON_REC_FILE_TYPE_PIC_SMART_IPC_AREA_INTRUSION	0x8000			//区域入侵报警图片

//文件格式
#define NPC_D_MON_FILE_FORMAT_VIDEO_H264						0x0001			//H264文件
#define NPC_D_MON_FILE_FORMAT_VIDEO_MPEG4						0x0002			//MPEG4文件
#define NPC_D_MON_FILE_FORMAT_VIDEO_H265						0x0003			//H265文件

#define NPC_D_MON_FILE_FORMAT_PIC_BMP							0x0101			//BMP文件
#define NPC_D_MON_FILE_FORMAT_PIC_JPEG							0x0102			//JPEG文件

#define NPC_D_MON_FILE_FORMAT_VESSEL_MP4						0x0301			//MP4文件
#define NPC_D_MON_FILE_FORMAT_VESSEL_AVI						0x0301			//AVI文件

//语言种类定义
#define NPC_D_MON_LAND_KIND_SIMPCHINESE							0				//简体中文
#define NPC_D_MON_LAND_KIND_ENGLISH								1				//英文

//字符集定义
#define NPC_D_MON_CHARSET_GB2312								0				//gb2312
#define NPC_D_MON_CHARSET_UTF8									1				//utf8

//设备访问权限位定义
#define NPC_D_MON_DEV_POP_REALPLAY								0x00000001		//实时预览权限（具有全局和通道权限）
#define NPC_D_MON_DEV_POP_PTZ_CTRL								0x00000002		//云台控制权限（具有全局和通道权限）
#define NPC_D_MON_DEV_POP_TALK									0x00000004		//语音对讲权限（具有全局和通道权限）
#define NPC_D_MON_DEV_POP_QUERY_FILE							0x00000008		//录像文件查询权限（具有全局和通道权限）
#define NPC_D_MON_DEV_POP_BACKPLAY								0x00000010		//录像回放权限（具有全局和通道权限）
#define NPC_D_MON_DEV_POP_ALARM									0x00000020		//报警布防权限（只有全局权限）
#define NPC_D_MON_DEV_POP_GET_CONFIG							0x00000040		//查询配置权限（只有全局权限）
#define NPC_D_MON_DEV_POP_SET_CONFIG							0x00000080		//设置配置权限（只有全局权限）

//设备连接模式定义
//#define NPC_D_MON_DEV_CONN_MODE_NON								0				//未连接
//#define NPC_D_MON_DEV_CONN_MODE_P2P								1				//P2P连接
//#define NPC_D_MON_DEV_CONN_MODE_TRANS							2				//中转连接
//#define NPC_D_MON_DEV_CONN_MODE_TCPDIRECT						3				//TCP直连
//#define NPC_D_MON_DEV_CONN_MODE_MEDIASTREAM						4				//流媒体连接

#define NPC_D_MON_DEV_CONN_TYPE_NON								0				//未连接
#define NPC_D_MON_DEV_CONN_TYPE_P2P								1				//P2P连接
#define NPC_D_MON_DEV_CONN_TYPE_TRANS							2				//中转连接
#define NPC_D_MON_DEV_CONN_TYPE_TCPDIRECT						3				//TCP直连
#define NPC_D_MON_DEV_CONN_TYPE_MEDIASTREAM						4				//流媒体连接

//图片格式定义
#define NPC_D_MON_PIC_FORMAT_BMP								1				//BMP文件
#define NPC_D_MON_PIC_FORMAT_JPEG								2				//JPEG文件

//文件类型定义
#define NPC_D_MON_FILE_TYPE_ALL									0				//所有文件类型
#define NPC_D_MON_FILE_TYPE_RECORD								1				//录像文件
#define NPC_D_MON_FILE_TYPE_PICTRUE								2				//拍照文件

//文件创建方式定义
#define NPC_D_MON_FILE_CREATE_MODE_ALL							0				//所有方式
#define NPC_D_MON_FILE_CREATE_MODE_ALARM						1				//报警方式
#define NPC_D_MON_FILE_CREATE_MODE_MANUAL						2				//手动方式
#define NPC_D_MON_FILE_CREATE_MODE_TIMER						3				//定时方式

//报警事件定义
#define NPC_D_MON_ALARM_EVENT_ALL								0				//所有报警事件
#define NPC_D_MON_ALARM_EVENT_FAULT								1				//设备故障报警
#define NPC_D_MON_ALARM_EVENT_MOTION							2				//移动侦测报警
#define NPC_D_MON_ALARM_EVENT_VIDEO_BLIND						3				//视频遮挡报警
#define NPC_D_MON_ALARM_EVENT_VIDEO_LOSS						4				//视频丢失报警
#define NPC_D_MON_ALARM_EVENT_PROBE								5				//探头报警（外部输入报警）
#define NPC_D_MON_ALARM_EVENT_PIR								6				//人体感应报警
#define NPC_D_MON_ALARM_EVENT_DOORBELL							7				//门铃报警
#define NPC_D_MON_ALARM_EVENT_HDD_ERROR							8				//硬盘错误
#define NPC_D_MON_ALARM_EVENT_HDD_FULL							9				//硬盘满
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_CROSS_LINE				10				//越线侦测报警
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_AREA_INTRUSION			11				//区域入侵报警
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_AREA_IN					12				//区域进入报警
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_AREA_OUT				13				//区域离开报警
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_OBJECT_FORGET			14				//物品遗留报警
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_OBJECT_PICKUP			15				//物品拾取报警


//------------------------------------------------------------------------
//媒体帧头定义
typedef struct _NPC_S_MON_MEDIA_FRAME_HEAD
{
	NPC_INT										iMediaType;						//媒体类型，参见NPC_D_MON_MEDIA_TYPE_*定义
	NPC_DWORD									dwTimestamp;					//时间戳

	NPC_INT										iVideoCodecId;					//视频编码ID，参考NPC_D_MON_CODEC_ID_*定义
	NPC_INT										iVideoWidth;					//视频宽度
	NPC_INT										iVideoHeight;					//视频高度
	NPC_INT										iVideoBitRate;					//视频码率
	NPC_INT										iVideoFrameRate;				//视频帧率
	NPC_INT										iVideoFrameType;				//视频帧类型，参见NPC_D_MON_VIDEO_FRAME_TYPE_*定义

	NPC_INT										iAudioCodecId;					//音频编码ID，参考NPC_D_MON_CODEC_ID_*定义
	NPC_INT										iAudioBitRate;					//音频码率
	NPC_INT										iAudioSampleRate;				//音频采样率
	NPC_INT										iAudioChNum;					//音频声道数

	NPC_INT										iFrameFlag;						//帧标志，0：非结束帧，1：最后一帧，2：停止流标志（因播放完或错误导致停止）。（实时预览和录像回放有效，如果是实时预览，值为2表示请求显示层关闭解码器，重新打开解码器）
	NPC_DWORD									dwPlayPos;						//播放位置（秒），录像回放有效
	NPC_DWORD									dwFileTotalLen;					//文件总长度（秒），录像回放有效

} NPC_S_MON_MEDIA_FRAME_HEAD, *PNPC_S_MON_MEDIA_FRAME_HEAD;

//媒体包头定义
typedef struct _NPC_S_MON_MEDIA_PACKET_HEAD
{
	NPC_DWORD									dwPacketFlag;					//包标志，值为0xFFFFFFFF
	NPC_INT										iPacketSize;					//包大小，包括该包头长度
	NPC_BYTE									ucPacketType;					//包类型，0：音视频包，1：图片包，2：自定义数据
	NPC_BYTE									ucPercent;						//百分比，值：0~100
	NPC_BYTE									ucReserve[2];					//备用

} NPC_S_MON_MEDIA_PACKET_HEAD, *PNPC_S_MON_MEDIA_PACKET_HEAD;

//文件头信息
typedef struct _NPC_S_MON_FILE_HEAD_INFO
{
	NPC_CHAR									sFileFlag[128];					//文件标识，唯一标识该文件，打开文件时必须原样传回，如文件名
	NPC_INT										iChNo;							//通道号
	NPC_INT										iStreamNo;						//码流号
	NPC_INT										iFileType;						//文件类型，参见NPC_D_MON_FILE_TYPE_*定义
	NPC_INT										iCreateMode;					//创建方式，参见NPC_D_MON_FILE_CREATE_MODE_*定义
	NPC_INT										iAlarmEvent;					//报警事件，参见NPC_D_MON_ALARM_EVENT_*定义，只有创建方式为NPC_D_MON_FILE_CREATE_MODE_ALARM时有效
	NPC_S_TD_DATE_TIME							tStartTime;						//文件开始时间，拍照文件为拍照的时间
	NPC_S_TD_DATE_TIME							tEndTime;						//文件结束时间，拍照文件该参数无效
	NPC_DWORD									dwFileTimeLen;					//文件总时长（秒），录像文件有效
	NPC_DWORD									dwFileSize;						//文件大小（单位：KB）

	//以下参数在iFileType值为NPC_D_MON_FILE_TYPE_RECORD时有效
	NPC_BOOL									bVideoFlag;						//视频标志，TRUE：表示有视频，FALSE：表示没有视频
	NPC_BOOL									bAudioFlag;						//音频标志，TRUE：表示有音频，FALSE：表示没有音频

	NPC_INT										iVideoCodecId;					//视频编码ID，参见NPC_D_MON_CODEC_ID_VEDIO_*定义
	NPC_INT										iVideoFrameRate;				//视频帧率
	NPC_INT										iVideoBitRate;					//视频码率（kbps）
	NPC_USHORT									usVideoWidth;					//视频宽度
	NPC_USHORT									usVideoHeight;					//视频高度

	NPC_INT										iAudioCodecId;					//音频编码ID，参见NPC_D_MON_CODEC_ID_AUDIO_*定义
	NPC_INT										iAudioBitRate;					//音频码率（kbps）
	NPC_INT										iAudioSampleRate;				//音频采样率
	NPC_INT										iAudioChNum;					//音频声道数

	//以下参数在iFileType值为NPC_D_MON_FILE_TYPE_PICTRUE时有效
	NPC_INT										iPictureFormat;					//图片格式，参见NPC_D_MON_PIC_FORMAT_*定义

} NPC_S_MON_FILE_HEAD_INFO, *PNPC_S_MON_FILE_HEAD_INFO;



#endif

