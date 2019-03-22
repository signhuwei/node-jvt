//
//  "$Id: GUIExchange.h 13342 2014-09-15 11:47:26Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __EXCHANAGEAL_GUI_EXCHANGE_H__
#define __EXCHANAGEAL_GUI_EXCHANGE_H__

#include "Types/Defs.h"
#include "ExchangeAL/Exchange.h"


/// GUI设置
struct GUISetConfig
{
	int iWindowAlpha;			///< 窗口透明度	[128, 255]
	bool bTimeTitleEn;			///< 时间标题显示使能
	bool bChannelTitleEn;		///< 通道标题显示使能	
	bool bAlarmStatus;			///<  报警状态
	bool bRecordStatus;			///<  录像状态显示使能
	bool bChanStateRecEn;		///< 录像标志显示使能
	bool bChanStateVlsEn;		///< 视频丢失标志显示使能
	bool bChanStateLckEn;		///< 通道锁定标志显示使能	
	bool bChanStateMtdEn;		///< 动态检测标志显示使能
	bool bBitRateEn;			///< 码流显示使能
	bool bRemoteEnable;			///< 遥控器使能
	bool bDeflick;				///< 抗抖动
};

//向导设置
struct Guideconfig
{
	int bEnable; 				///<向导是否开启。1开启，0关闭
	int reserved[3];
};

struct AppDownloadLink
{
	bool IOSEnable;    //是否显示iphone客户端二维码
	bool AndroidEnable;//是否显示安卓客户端二维码
	bool SNEnable;     //是否显示序列号对应的二维码
	bool OtherEnable;  //是否显示客户自定义二维码

	std::string linkIOS;
	std::string linkAndroid;
	std::string nameOther;  //客户自定义二维码名称
	std::string linkOther;  //客户自定义二维码
};

//VGA分辨率
struct VGAresolution
{
	int nHeight;
	int nWidth;
};
/// 得到系统总的语言列表
ConfigPair *getSystemLanguageList();

#endif
