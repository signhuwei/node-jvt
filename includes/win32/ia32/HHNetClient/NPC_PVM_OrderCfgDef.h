/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_PVM_OrderCfgDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2013-10-04
 * Description   :  设备协议接口命令配置定义
 *----------------------------------------------------------------------------*/

#ifndef __NPC_PVM_ORDERCFGDEF_H
#define __NPC_PVM_ORDERCFGDEF_H

#include "NPC_TypeDef.h"


//------------------------------------------------------------------------------
//常量定义
#define NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM						6				//检测时间段数
#define NPC_D_PVM_CFG_REC_PLAN_TIME_SECT_NUM					6				//录像计划时间段数


//------------------------------------------------------------------------------
//配置功能ID定义
#define NPC_D_PVM_CFG_FUNCID_DEV_NAME							1				//设备名称（暂停使用）
#define NPC_D_PVM_CFG_FUNCID_DEV_IP								2				//设备有线IP地址
#define NPC_D_PVM_CFG_FUNCID_DEV_WIFI							3				//设备WIFI信息
#define NPC_D_PVM_CFG_FUNCID_GET_WIFIAP_LIST					4				//获取WIFIAP列表（只有获取配置功能）
#define NPC_D_PVM_CFG_FUNCID_DEV_CODEC							5				//编码配置

#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_MOTION_DETECT			6				//移动侦测报警
#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_PROBE					7				//探头输入报警
#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_BLIND_DETECT				8				//视频遮挡侦测
#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_LOSS_DETECT				9				//视频丢失侦测
#define NPC_D_PVM_CFG_FUNCID_DEV_ALARM_EMAIL                    10				//报警邮件配置


#define NPC_D_PVM_CFG_FUNCID_DEV_SYS_TIME						20				//设备系统时间
#define NPC_D_PVM_CFG_FUNCID_DEV_INFO							21				//设备信息
#define NPC_D_PVM_CFG_FUNCID_CH_NAME							22				//通道名称
#define NPC_D_PVM_CFG_FUNCID_DEV_SYS_TIME_ZONE                  23				//设备系统时间时区

#define NPC_D_PVM_CFG_FUNCID_CAMERA_PARAM						40				//摄像机参数
#define NPC_D_PVM_CFG_FUNCID_CAMERA_VIDEO_COLOR					41				//摄像机图像颜色配置参数

#define NPC_D_PVM_CFG_FUNCID_DEV_RECORD_PLAN					50				//录像计划配置
#define NPC_D_PVM_CFG_FUNCID_ALARM_CLOUD_STORAGE				51				//报警云存储配置

#define NPC_D_PVM_CFG_FUNCID_STORAGE_QUERY_SIZE					60				//查询存储容量（只有获取配置功能）
#define NPC_D_PVM_CFG_FUNCID_STORAGE_FORMAT						61				//格式化存储器（只有设置配置功能）

#define NPC_D_PVM_CFG_FUNCID_DEV_AVENC_VIDEOWIDGET              71				//视频通道名、时间显示配置

#define NPC_D_PVM_CFG_FUNCID_DEV_LOCK_CONTROL_1                 81				//开锁控制1
#define NPC_D_PVM_CFG_FUNCID_DEV_LOCK_CONTROL_2                 82				//开锁控制2

//------------------------------------------------------------------------------
//设备名称
typedef struct _NPC_S_PVM_IMD_CFG_DEV_NAME
{
	NPC_CHAR									sDevName[64];					//设备名称

} NPC_S_PVM_IMD_CFG_DEV_NAME, *PNPC_S_PVM_IMD_CFG_DEV_NAME;

//设备有线IP地址
typedef struct _NPC_S_PVM_IMD_CFG_DEV_IP
{
	NPC_CHAR									sNetcardName[32];				//网卡名称
	NPC_CHAR									sMac[32];						//网卡MAC地址，格式为XX-XX-

	NPC_BOOL									bDhcpEnable;					//DHCP使能
	NPC_CHAR									sIpaddr[16];					//IP地址
	NPC_CHAR									sNetmask[16];					//子网掩码
	NPC_CHAR									sGateway[16];					//网关地址

} NPC_S_PVM_IMD_CFG_DEV_IP, *PNPC_S_PVM_IMD_CFG_DEV_IP;

//设备WIFI信息
typedef struct _NPC_S_PVM_IMD_CFG_DEV_WIFI
{
	NPC_CHAR									sNetcardName[32];				//网卡名称（可选）
	NPC_CHAR									sMac[32];						//网卡MAC地址（可选，为空，则为默认WIFI网卡），格式为XX-XX-

	NPC_BOOL									bEnable;						//是否启用（必填）

	NPC_CHAR									sWifiSSID[32];					//WIFI SSID（必填）
	NPC_CHAR									sWifiPwd[32];					//WIFI密码（必填）

	NPC_BOOL									bFieldEnable_AuthType;			//字段使能：安全类型，TRUE表示sAuthType字段有效，否则无效，下同
	NPC_BOOL									bFieldEnable_EncrypType;		//字段使能：加密类型
	NPC_BOOL									bFieldEnable_Channel;			//字段使能：信道号
	NPC_BOOL									bFieldEnable_RSSI;				//字段使能：信号强度

	NPC_CHAR									sAuthType[32];					//安全类型（可选）
	NPC_CHAR									sEncrypType[32];				//加密类型（可选）
	NPC_INT										iChannel;						//信道号（可选）
	NPC_INT										iRSSI;							//信号强度（可选），值范围为0~100，0为信号最低，100为信号最强

	NPC_BOOL									bIfSetNetParam;					//是否设置网络参数（必填），TRUE：设置，以下参数有效，FALSE：不设置，保持原网络参数
	NPC_BOOL									bDhcpEnable;					//DHCP使能（可选）
	NPC_CHAR									sIpaddr[16];					//IP地址（可选）
	NPC_CHAR									sNetmask[16];					//子网掩码（可选）
	NPC_CHAR									sGateway[16];					//网关地址（可选）

} NPC_S_PVM_IMD_CFG_DEV_WIFI, *PNPC_S_PVM_IMD_CFG_DEV_WIFI;


//报警邮箱配置
typedef struct _NPC_S_PVM_IMD_CFG_DEV_NETWORK_EMAIL
{
    NPC_CHAR												sEMailServerName[128];			//邮件服务名称
    NPC_CHAR												sUserName[128];			//邮箱登录账号
    NPC_CHAR												sUserPwd[128];			//邮箱登录密码
    NPC_BOOL												bAanonymity;				//HTTP端口号
    NPC_INT													iPort;                  //smtp端口
    NPC_CHAR												sReceiverEMail[128];    //收件人邮箱
    NPC_CHAR												sSendEMail[128];       //收件人邮箱
    NPC_CHAR												sTitle[128];            //邮箱主题
    struct _ScheduleTime{
        NPC_BOOL										bIfEnable;				//是否启用
        NPC_S_TD_TIME									tBeginTime;				//开始时间
        NPC_S_TD_TIME									tEndTime;				//结束时间
    } sScheduleTime[2];
    NPC_BOOL                                                bEnableSSL;
    NPC_BOOL                                                bEnable;
    
} NPC_S_PVM_IMD_CFG_DEV_NETWORK_EMAIL, *PNPC_S_PVM_IMD_CFG_DEV_NETWORK_EMAIL;

//widget属性
typedef struct _NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE
{
    NPC_CHAR    sBackColor[32];                                 //标题背景颜色,0x80000000
    NPC_BOOL    bIfEncodeBlend;                                 //是否开启标题显示
    NPC_CHAR    sFrontColor[32];                                //标题颜色,0xf0ffffff
    NPC_BOOL    bIfPreviewBlend;                                //缺省:true
    NPC_INT     tRelativePos[4];
} NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE, *PNPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE;

//配置信息：AVEnc.VideoWidget
typedef struct _NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_TABLE
{
    NPC_INT                                                 iChannelNum;                //通道数
    
    struct _VideoWidget{
        
        struct _ChannelTitle{
            NPC_CHAR    sName[128];     //通道名称
            NPC_CHAR    sSerialNo[128]; //通道序号
        } tChannelTitle;                //通道标题结构体
        
        NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE   tChannelTitleAttribute;     //通道标题属性
        NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE   tCovers[8];                 //covers
        NPC_INT                                         iCoversNum;                 //covers数,0
        NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_ATTRIBUTE   tTimeTitleAttribute;        //通道标题属性
        
    }tVideoWidget[64];                          //通道和时间标题信息
    
} NPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_TABLE, *PNPC_S_PVM_IMD_CFG_DEV_VIDEO_WIDGET_TABLE;


//获取WIFIAP列表，该结构体之后为NPC_S_PVM_IMD_WIFIAP_INFO数组
typedef struct _NPC_S_PVM_IMD_CFG_GET_WIFIAP_LIST
{
	NPC_INT										iWifiApNum;						//WIFIAP数

} NPC_S_PVM_IMD_CFG_GET_WIFIAP_LIST, *PNPC_S_PVM_IMD_CFG_GET_WIFIAP_LIST;

//WIFIAP信息
typedef struct _NPC_S_PVM_IMD_CFG_WIFIAP_INFO
{
	NPC_CHAR									sSSID[32];						//SSID（必填）
	NPC_CHAR									sAuthType[32];					//安全类型（可选）
	NPC_CHAR									sEncrypType[32];				//加密类型（可选）
	NPC_INT										iChannel;						//信道号（可选）
	NPC_INT										iRSSI;							//信号强度（可选），值范围为0~100，0为信号最低，100为信号最强

} NPC_S_PVM_IMD_CFG_WIFIAP_INFO, *PNPC_S_PVM_IMD_CFG_WIFIAP_INFO;

//编码信息
typedef struct _NPC_S_PVM_IMD_CFG_CODEC_INFO
{
	NPC_BOOL									bVideoEnable;					//是否启用视频
	NPC_BOOL									bAudioEnable;					//是否启用音频

	struct _VideoFormat
	{
		NPC_INT									iCodecId;						//视频编码ID，参见NPC_D_MON_CSD_CODEC_ID_VEDIO_*定义
		NPC_INT									iResolution;					//分辨率，参见NPC_D_MON_CSD_VEDIO_RESOLUTION_*定义
		NPC_INT									iBitRateControl;				//码流控制模式，参见NPC_D_MON_CSD_BITRATECTRL_*定义，如："CBR"固定码流，"VBR"可变码流，"MBR"混和码流
		NPC_INT									iBitRate;						//视频码流（kbps）
		NPC_INT									iFrameRate;						//视频帧率，负数表示多秒一帧，比如-3表示3秒一帧，取值范围-5~30
		NPC_INT									iGOP;							//I帧间隔
		NPC_INT									iQuality;						//图像质量，只有在可变码流下才起作用，取值1-6，值越大，图像质量越好

	} tVideoFormat;

	struct _AudioFormat
	{
		NPC_INT									iCodecId;						//音频编码ID，参见NPC_D_MON_CSD_CODEC_ID_AUDIO_*定义
		NPC_INT									iBitRate;						//比特率（kbps）
		NPC_INT									iSampleRate;					//采样率
		NPC_INT									iMaxVolume;						//最大音量

	} tAudioFormat;

} NPC_S_PVM_IMD_CFG_CODEC_INFO, *PNPC_S_PVM_IMD_CFG_CODEC_INFO;

//设备编码配置
typedef struct _NPC_S_PVM_IMD_CFG_DEV_CODEC
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）

	NPC_INT										iCodecNum;						//编码数
	NPC_S_PVM_IMD_CFG_CODEC_INFO				tCodecInfo[5];					//编码信息，第一个为主码流，第二个为子码流1，第三个为子码流2，如此类推

} NPC_S_PVM_IMD_CFG_DEV_CODEC, *PNPC_S_PVM_IMD_CFG_DEV_CODEC;

//移动侦测报警参数
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）
	NPC_BOOL									bIfEnable;						//是否开启检测

	NPC_BOOL									bFuncEnable_Level;				//功能是否有效：灵敏度，TRUE：灵敏度参数项有效，FALSE：为无效（下同）
	NPC_BOOL									bFuncEnable_Region;				//功能是否有效：检测区域块
	NPC_BOOL									bFuncEnable_Photo;				//功能是否有效：拍照
	NPC_BOOL									bFuncEnable_Record;				//功能是否有效：录像
	NPC_BOOL									bFuncEnable_AlarmOut;			//功能是否有效：报警输出
	NPC_BOOL									bFuncEnable_Beep;				//功能是否有效：蜂鸣
	NPC_BOOL									bFuncEnable_WeekSect;			//功能是否有效：检测时间段

	NPC_INT										iLevel;							//灵敏度
	NPC_DWORD									dwRegion[32];					//检测区域块，每一位为一个点（0表示不检测，1表示要检测，左边的点在低位），每个32位为一行（即一个双字），共32行，即32*32的矩形，可以根据实际图像比例选择部分点处理
	NPC_BOOL									bPhotoEnable;					//拍照使能
	NPC_BOOL									bRecordEnable;					//录像使能
	NPC_INT										iRecordDelayedTime;				//录像延时时间（秒）
	NPC_BOOL									bAlarmOutEnable;				//报警输出使能
	NPC_INT										iAlarmOutDelayedTime;			//报警输出延时时间（秒）
    NPC_BOOL									bBeepEnable;					//蜂鸣使能
	//检测时间段
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bIfEnable;						//是否启用
			NPC_S_TD_TIME						tBeginTime;						//开始时间
			NPC_S_TD_TIME						tEndTime;						//结束时间
		} tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
	} tWeekSect[7];
    NPC_BOOL									bEmailEnable;					//邮件通知
    NPC_CHAR									sRegion[32][32];				//检测区域块，每一位为一个点（0表示不检测，1表示要检测，左边的点在低位），每个32位为一行（即一个双字），共32行，即32*32的矩形，可以根据实际图像比例选择部分点处理

} NPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT;


//移动侦测报警参数
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT_UMSP
{
    NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）
    NPC_BOOL									bIfEnable;						//是否开启检测
    
    NPC_BOOL									bFuncEnable_Level;				//功能是否有效：灵敏度，TRUE：灵敏度参数项有效，FALSE：为无效（下同）
    NPC_BOOL									bFuncEnable_Region;				//功能是否有效：检测区域块
    NPC_BOOL									bFuncEnable_Photo;				//功能是否有效：拍照
    NPC_BOOL									bFuncEnable_Record;				//功能是否有效：录像
    NPC_BOOL									bFuncEnable_AlarmOut;			//功能是否有效：报警输出
    NPC_BOOL									bFuncEnable_Beep;				//功能是否有效：蜂鸣
    NPC_BOOL									bFuncEnable_WeekSect;			//功能是否有效：检测时间段
    
    NPC_INT										iLevel;							//灵敏度
    NPC_DWORD									dwRegion[32];					//检测区域块，每一位为一个点（0表示不检测，1表示要检测，左边的点在低位），每个32位为一行（即一个双字），共32行，即32*32的矩形，可以根据实际图像比例选择部分点处理
    NPC_BOOL									bPhotoEnable;					//拍照使能
    NPC_BOOL									bRecordEnable;					//录像使能
    NPC_INT										iRecordDelayedTime;				//录像延时时间（秒）
    NPC_BOOL									bAlarmOutEnable;				//报警输出使能
    NPC_INT										iAlarmOutDelayedTime;			//报警输出延时时间（秒）
    NPC_BOOL									bBeepEnable;					//蜂鸣使能
    
    //检测时间段
    struct _WeekSect{
        struct _TimeSect{
            NPC_BOOL							bIfEnable;						//是否启用
            NPC_S_TD_TIME						tBeginTime;						//开始时间
            NPC_S_TD_TIME						tEndTime;						//结束时间
        } tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
    } tWeekSect[7];
    
} NPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT_UMSP, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_MOTION_DETECT_UMSP;

//探头输入报警参数
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_PROBE
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）
	NPC_BOOL									bIfEnable;						//是否开启检测

	NPC_BOOL									bFuncEnable_SensorType;			//功能是否有效：传感器类型，TRUE：传感器类型参数项有效，FALSE：为无效（下同）
	NPC_BOOL									bFuncEnable_Photo;				//功能是否有效：拍照
	NPC_BOOL									bFuncEnable_Record;				//功能是否有效：录像
	NPC_BOOL									bFuncEnable_AlarmOut;			//功能是否有效：报警输出
	NPC_BOOL									bFuncEnable_Beep;				//功能是否有效：蜂鸣
	NPC_BOOL									bFuncEnable_WeekSect;			//功能是否有效：检测时间段

	NPC_INT										iSensorType;					//传感器类型，0：常闭，1：常开
	NPC_BOOL									bPhotoEnable;					//拍照使能
	NPC_BOOL									bRecordEnable;					//录像使能
	NPC_INT										iRecordDelayedTime;				//录像延时时间（秒）
	NPC_BOOL									bAlarmOutEnable;				//报警输出使能
	NPC_INT										iAlarmOutDelayedTime;			//报警输出延时时间（秒）
	NPC_BOOL									bBeepEnable;					//蜂鸣使能

	//检测时间段
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bIfEnable;						//是否启用
			NPC_S_TD_TIME						tBeginTime;						//开始时间
			NPC_S_TD_TIME						tEndTime;						//结束时间
		} tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
	} tWeekSect[7];

} NPC_S_PVM_IMD_CFG_DEV_ALARM_PROBE, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_PROBE;

//视频遮挡侦测参数
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_BLIND_DETECT
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）
	NPC_BOOL									bIfEnable;						//是否开启检测

	NPC_BOOL									bFuncEnable_Level;				//功能是否有效：灵敏度，TRUE：灵敏度参数项有效，FALSE：为无效（下同）
	NPC_BOOL									bFuncEnable_Photo;				//功能是否有效：拍照
	NPC_BOOL									bFuncEnable_Record;				//功能是否有效：录像
	NPC_BOOL									bFuncEnable_AlarmOut;			//功能是否有效：报警输出
	NPC_BOOL									bFuncEnable_Beep;				//功能是否有效：蜂鸣
	NPC_BOOL									bFuncEnable_WeekSect;			//功能是否有效：检测时间段

	NPC_INT										iLevel;							//灵敏度
	NPC_BOOL									bPhotoEnable;					//拍照使能
	NPC_BOOL									bRecordEnable;					//录像使能
	NPC_INT										iRecordDelayedTime;				//录像延时时间（秒）
	NPC_BOOL									bAlarmOutEnable;				//报警输出使能
	NPC_INT										iAlarmOutDelayedTime;			//报警输出延时时间（秒）
	NPC_BOOL									bBeepEnable;					//蜂鸣使能

	//检测时间段
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bIfEnable;						//是否启用
			NPC_S_TD_TIME						tBeginTime;						//开始时间
			NPC_S_TD_TIME						tEndTime;						//结束时间
		} tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
	} tWeekSect[7];

} NPC_S_PVM_IMD_CFG_DEV_ALARM_BLIND_DETECT, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_BLIND_DETECT;

//视频丢失侦测参数
typedef struct _NPC_S_PVM_IMD_CFG_DEV_ALARM_LOSS_DETECT
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）
	NPC_BOOL									bIfEnable;						//是否开启检测

	NPC_BOOL									bFuncEnable_AlarmOut;			//功能是否有效：报警输出
	NPC_BOOL									bFuncEnable_Beep;				//功能是否有效：蜂鸣
	NPC_BOOL									bFuncEnable_WeekSect;			//功能是否有效：检测时间段

	NPC_INT										iRecordDelayedTime;				//录像延时时间（秒）
	NPC_BOOL									bAlarmOutEnable;				//报警输出使能
	NPC_INT										iAlarmOutDelayedTime;			//报警输出延时时间（秒）
	NPC_BOOL									bBeepEnable;					//蜂鸣使能

	//检测时间段
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bIfEnable;						//是否启用
			NPC_S_TD_TIME						tBeginTime;						//开始时间
			NPC_S_TD_TIME						tEndTime;						//结束时间
		} tTimeSect[NPC_D_PVM_CFG_CHECK_TIME_SECT_NUM];
	} tWeekSect[7];

} NPC_S_PVM_IMD_CFG_DEV_ALARM_LOSS_DETECT, *PNPC_S_PVM_IMD_CFG_DEV_ALARM_LOSS_DETECT;


//设备系统时间
typedef struct _NPC_S_PVM_IMD_CFG_DEV_SYS_TIME
{
	NPC_S_TD_DATE_TIME							tDevTime;						//设备时间

} NPC_S_PVM_IMD_CFG_DEV_SYS_TIME, *PNPC_S_PVM_IMD_CFG_DEV_SYS_TIME;

//设备信息
typedef struct _NPC_S_PVM_IMD_CFG_DEV_INFO
{
	NPC_CHAR									sDevType[8];					//设备类型
	NPC_CHAR									sDevVer[36];					//设备版本
	NPC_CHAR									sDevModel[32];					//设备型号
	NPC_CHAR									sDeviceName[36];				//设备名称
	NPC_CHAR									sMacAddr[32];					//设备MAC地址

	NPC_INT										iVideoChNum;					//视频通道数
	NPC_INT										iAudioChNum;					//音频通道数
	NPC_INT										iPtzChNum;						//PTZ通道数
	NPC_INT										iAlarmInputNum;					//报警输入数
	NPC_INT										iAlarmOutputNum;				//报警输出数
	NPC_INT										iDiskNum;						//硬盘个数
	NPC_INT										iSubProtoNum;					//子码流数
	NPC_BOOL									bIfSupportZeroChannel;			//是否支持零通道

} NPC_S_PVM_IMD_CFG_DEV_INFO, *PNPC_S_PVM_IMD_CFG_DEV_INFO;

//通道名称
typedef struct _NPC_S_PVM_IMD_CFG_CH_NAME
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）
	NPC_CHAR									sChName[64][64];					//通道名称

} NPC_S_PVM_IMD_CFG_CH_NAME, *PNPC_S_PVM_IMD_CFG_CH_NAME;

//摄像机参数
typedef struct _NPC_S_PVM_IMD_CFG_CAMERA_PARAM
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）

	NPC_BOOL									bIfPictureFlip;					//是否图象翻转

} NPC_S_PVM_IMD_CFG_CAMERA_PARAM, *PNPC_S_PVM_IMD_CFG_CAMERA_PARAM;

//摄像机图像颜色配置参数
typedef struct _NPC_S_PVM_IMD_CFG_CAMERA_VIDEO_COLOR
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）

	NPC_INT										iBrightness;					//亮度
	NPC_INT										iContrast;						//对比度
	NPC_INT										iGain;							//增益
	NPC_INT										iHue;							//色度
	NPC_INT										iSaturation;					//饱和度
	NPC_INT										iWhitebalance;					//白平衡

} NPC_S_PVM_IMD_CFG_CAMERA_VIDEO_COLOR, *PNPC_S_PVM_IMD_CFG_CAMERA_VIDEO_COLOR;


//-----------------------------------------------------------------------------------------
//录像计划配置
typedef struct _NPC_S_PVM_IMD_CFG_DEV_RECORD_PLAN
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号有效，其它参数无效）

	NPC_INT										iRecState;						//录像状态，0：关闭，1：始终录像，2：配置录像

	NPC_INT										iPacketLength;					//每个录像文件的录像时长，以分钟为单位
	NPC_INT										iPreRecord;						//预录时长（秒）
	NPC_BOOL									bOpenAudio;						//是否开启音频录像
	NPC_INT										iRecStream;						//录像码流，0：主码流，1：子码流

	//以下三个参数在录像状态为始终录像时有效
	NPC_BOOL									bOpenGeneral;					//是否开启常规录像（定时录像）
	NPC_BOOL									bOpenCheckAlarm;				//是否开启检测报警录像（移动报警、视频遮挡、视频丢失等）
	NPC_BOOL									bOpenInputAlarm;				//是否开启输入报警录像（指探头，如红外等）

	//时间段（按配置录像时该参数才有效）
	struct _WeekSect{
		struct _TimeSect{
			NPC_BOOL							bOpenGeneral;					//是否开启常规录像（定时录像）
			NPC_BOOL							bOpenCheckAlarm;				//是否开启检测报警录像（移动报警、视频遮挡、视频丢失等）
			NPC_BOOL							bOpenInputAlarm;				//是否开启输入报警录像（指探头，如红外等）

			NPC_S_TD_TIME						tBeginTime;						//开始时间
			NPC_S_TD_TIME						tEndTime;						//结束时间
		} tTimeSect[NPC_D_PVM_CFG_REC_PLAN_TIME_SECT_NUM];
	} tWeekSect[7];

} NPC_S_PVM_IMD_CFG_DEV_RECORD_PLAN, *PNPC_S_PVM_IMD_CFG_DEV_RECORD_PLAN;

//报警云存储配置
typedef struct _NPC_S_PVM_IMD_CFG_ALARM_CLOUD_STORAGE
{
	NPC_INT										iChNo;							//通道号（查询请求消息中只有通道号和报警类型有效，其它参数无效）
	NPC_INT										iAlarmType;						//报警类型，参见NPC_D_MON_CSD_ALARM_EVENT_*定义
																				//只适合移动侦测、视频遮挡、视频丢失、探头报警、人体感应报警、门铃报警等（或以后新增的报警类型）

	NPC_BOOL									bOpenAlarmRecord;				//是否开启报警录像
	NPC_INT										iPreRecordTime;					//录像预录时长（秒），指录制报警产生之前的N秒的录像
	NPC_INT										iTotalRecordTime;				//录像时长（秒）

	NPC_BOOL									bOpenAlarmPhotos;				//是否开启报警拍照
	NPC_INT										iPhotosIntervalTime;			//拍照间隔时间（毫秒）
	NPC_INT										iPhotosPicNum;					//拍照张数

} NPC_S_PVM_IMD_CFG_ALARM_CLOUD_STORAGE, *PNPC_S_PVM_IMD_CFG_ALARM_CLOUD_STORAGE;


//-----------------------------------------------------------------------------------------
//查询存储容量
typedef struct _NPC_S_PVM_IMD_CFG_STORAGE_QUERY_SIZE
{
	NPC_INT										iStorageNum;					//存储块数
	struct _Storage{
		NPC_INT									iSerialNo;						//序列号
		NPC_DWORD								dwStorageSize;					//存储容量（单位为M）
		NPC_DWORD								dwRemainSize;					//剩余空间（单位为M）
	} tStorage[16];

} NPC_S_PVM_IMD_CFG_STORAGE_QUERY_SIZE, *PNPC_S_PVM_IMD_CFG_STORAGE_QUERY_SIZE;

//格式化存储器
typedef struct _NPC_S_PVM_IMD_CFG_STORAGE_FORMAT
{
	NPC_INT										iSerialNo;						//序列号，与查询存储容量中的序列号一致

} NPC_S_PVM_IMD_CFG_STORAGE_FORMAT, *PNPC_S_PVM_IMD_CFG_STORAGE_FORMAT;



//-----------------------------------------------------------------------------------------
//能力集头
typedef struct _NPC_S_PVM_IMD_CFG_ABILITY_HEAD
{
	NPC_USHORT									usAbVerNo;						//能力集版本号
	NPC_USHORT									usAbDataLen;					//能力集数据长度

} NPC_S_PVM_IMD_CFG_ABILITY_HEAD, *PNPC_S_PVM_IMD_CFG_ABILITY_HEAD;

//版本一：能力集数据
typedef struct _NPC_S_PVM_IMD_CFG_ABILITY_DATA_V1
{
	struct _Net{
		NPC_BOOL								bIfCableNet;					//是否有有线网络
		NPC_BOOL								bIfWifiNet;						//是否有WIFI网络
	} tNet;

	NPC_INT										iCodecSchemeNum;				//编码方案数
	struct _CodecScheme{
		NPC_BOOL								bSupportAudio;					//是否支持音频
		NPC_INT									iStreamNum;						//码流数，最大5个

		struct _SubCh{
			NPC_BYTE							ucVedioCodecTable[4];			//视频编码列表，如果值为0表示该项不存在，参见NPC_D_MON_CSD_CODEC_ID_VEDIO_*定义
			NPC_BYTE							ucResolutionTable[16];			//分辨率列表，如果值为0表示该项不存在，参见NPC_D_MON_CSD_VEDIO_RESOLUTION_*定义
			NPC_USHORT							usBitRateStart;					//视频码流范围开始（kbps）
			NPC_USHORT							usBitRateEnd;					//视频码流范围结束（kbps）
			NPC_BYTE							ucFrameRateStart;				//视频帧率范围开始
			NPC_BYTE							ucFrameRateEnd;					//视频帧率范围结束
			NPC_BYTE							ucGOPStart;						//I帧间隔范围开始
			NPC_BYTE							ucGOPEnd;						//I帧间隔范围结束
		} tSubCh[5];															//子通道表

		NPC_BYTE								ucUseChTable[32];				//适用通道表
		NPC_INT									iUseChNum;						//适用通道数
	} tCodecScheme[8];															//编码方案表

	struct _Alarm{
		NPC_BOOL								bMotionDetect;					//是否支持移动侦测
		NPC_BOOL								bProbeInput;					//是否支持探头输入
		NPC_BOOL								bBlindDetect;					//是否支持视频遮挡侦测
		NPC_BOOL								bLossDetect;					//是否支持视频丢失侦测
	} tAlarm;

} NPC_S_PVM_IMD_CFG_ABILITY_DATA_V1, *PNPC_S_PVM_IMD_CFG_ABILITY_DATA_V1;



#endif




