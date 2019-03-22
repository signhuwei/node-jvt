//
//  "$Id: NetIPDeviceInfo.h 14324 2014-12-16 07:32:29Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:			2008-12-04 liwj create the file
//					用户管理相关配置转换
//

#ifndef __EXCHANGE_ALARM_INFO_H__
#define __EXCHANGE_ALARM_INFO_H__

#include "Types/Defs.h"
#include "Infra/Time.h"
#include <string>
#include "Comm/Positioning.h"


/// 设备信息
struct SystemInformation
{
	std::string sSoftWareVersion;	///< 软件版本信息
	std::string sHardWareVersion;	///< 硬件版本信息
	std::string sEncryptVersion;	///< 加密版本信息
	SystemTime tmBuildTime;		///< 软件创建时间
	std::string sSerialNo;			///< 设备序列号
	int iVideoInChannel;	///< 视频输入通道数
	int iVideoOutChannel;	///< 视频输出通道数
	int iAlarmInChannel;	///< 报警输入通道数
	int iAlarmOutChannel;	///< 报警输出通道数
	int iTalkInChannel;		///< 对讲输入通道数
	int iTalkOutChannel;	///< 对讲输出通道数	
	int iExtraChannel;		///< 扩展通道数	
	int iAudioInChannel;	///< 音频输入通道数
	int iCombineSwitch;		///< 组合编码通道分割模式是否支持切换
	int iDigChannel;		///<数字通道数
	uint uiDeviceRunTime;	///<系统运行时间
	std::string sHardWare;	///<设备型号
	std::string uUpdataTime;	///<更新日期
	uint uUpdataType;	///<更新内容
};

///< 驱动器信息结构
struct DriverInformation 
{
	int		iDriverType;		///< 驱动器类型
	bool	bIsCurrent;			///< 是否为当前工作盘
	uint	uiTotalSpace;		///< 总容量，MB为单位
	uint	uiRemainSpace;		///< 剩余容量，MB为单位
	int		iStatus;			///< 错误标志，文件系统初始化时被设置
	int		iLogicSerialNo;				///< 逻辑序号
	SystemTime  tmStartTimeNew;		///< 新录像时间段的开始时间
	SystemTime	 tmEndTimeNew;			///< 新录像时间段的结束时间
	SystemTime	 tmStartTimeOld;		///< 老录像时间段的开始时间
	SystemTime	 tmEndTimeOld;			///< 老录像时间段的结束时间
};

/// 磁盘信息结构
struct StorageDeviceInformation
{
	int		iPhysicalNo;		// 硬盘物理序号，从0开始
	int		iPartNumber;		// 分区数
	DriverInformation diPartitions[MAX_DRIVER_PER_DISK];
};

struct StorageDeviceInformationAll
{
	int iDiskNumber;
	StorageDeviceInformation vStorageDeviceInfoAll[MAX_DISK_PER_MACHINE];
};


/// 告警状态
struct AlarmState
{
	int iVideoMotion; ///< 移动侦测状态,用掩码表示通道号,bit0代表通道一,以此类推 1: 有告警 0: 无告警
	int iVideoBlind; ///< 视频遮挡状态,用掩码表示通道号,bit0代表通道一,以此类推 1: 有告警 0: 无告警
	int iVideoLoss;	///< 视频丢失状态,用掩码表示通道号,bit0代表通道一,以此类推 1: 有告警 0: 无告警
	int iAlarmIn;	///< 告警输入状态,用掩码表示通道号,bit0代表通道一,以此类推 1: 有告警 0: 无告警
	int iAlarmOut;	///< 告警输出状态,用掩码表示通道号,bit0代表通道一,以此类推 1: 有告警 0: 无告警
};

struct ChannelState
{
	bool bRecord; ///< 是否正在录像
	int iBitrate;	///< 当前码率
};

struct WorkState
{
	ChannelState vChnState[N_SYS_CH];
	AlarmState vAlarmState;
};

enum RSSI_SINGNAL
{
	RSSI_NO_SIGNAL,   //<= -90db
	RSSI_VERY_LOW,     //<= -81db
	RSSI_LOW,          //<= -71db
	RSSI_GOOD,         //<= -67db
	RSSI_VERY_GOOD,    //<= -57db
	RSSI_EXCELLENT     //>-57db
};

struct NetWifiDevice
{
	std::string strSSID;            //SSID Number
	int nRSSI;                      //SEE RSSI_SINGNAL
	int nChannel;
	std::string strNetType;         //Infra, Adhoc
	std::string strEncrypType;      //NONE, WEP, TKIP, AES
	std::string strAuth;            //OPEN, SHARED, WEPAUTO, WPAPSK, WPA2PSK, WPANONE, WPA, WPA2
};

struct NetWifiDeviceAll
{
	int nDevNumber;
	NetWifiDevice vNetWifiDeviceAll[MAX_AP_NUMBER];
};

enum VENDOR_ID
{
	VENDOR_GENERAL,       //xm
	VENDOR_TKL,           //德加拉
	VENDOR_ZHOUSHIDA,     //宙视达
	VENDOR_HONGFA,
};

struct OEMInfo
{
	int nOEMID;
	std::string strName;
	std::string strTel;
	std::string strAddr;
};

enum INFO_NET_LINK_STATUS
{
	INFO_NET_LINK_OK         = 0,
	INFO_NET_LINK_FAILED     = 1,
	INFO_NET_LINK_NO_DEVICE  = 2,
	INFO_NET_LINK_INVALID    = 9,
};

//GPS状态
struct GPSStatusInfo
{
	int             positioningStatus; //定位状态，取值如枚举POSITIONING_STATUS所述
	POSITIONING_POS longitudePos;      //经度
	POSITIONING_POS latitudePos;       //纬度
	char            rev[12];
};

//wifi状态
struct WifiStatusInfo
{
	int  connectStatus;  //wifi连接状态  如枚举INFO_NET_LINK_STATUS所述
	int  strength;       //信号强度
	char rev[24];
};

//3G状态
struct WirelessStatusInfo
{
	int  connectStatus;  //3G连接状态  如枚举INFO_NET_LINK_STATUS所述
	int  strength;       //信号强度
	char rev[24];
};

//主动注册状态
struct DASStatusInfo
{
	int  connectStatus;  //DAS连接状态  如枚举INFO_NET_LINK_STATUS所述
	char rev[28];
};

/*该信息只提供给客户，用于管理客户自己的产品的
该信息不是由我们来维护的
该信息不显示在任何可见的管理软件界面或IE界面
只有修改配置工具软件可见。
*/
struct CorrespondentOwnInfo
{
	char brand[64];
	char pModel[32];
	char pFirmwareVersion[32];
	char pHardwareId[32];
	int port;
};


#endif
