#ifndef __DEV_ABILITY_H__
#define __DEV_ABILITY_H__

#include "Infra/Singleton.h"
#include "ExchangeAL/Exchange.h"
#include "PAL/Capture.h"
#include "PAL/ExDec.h"
enum DevEXMODEL				//额外扩展的属性
{
	DEVEX_NORMAL	= 0x00000000,
 	DEVEX_ALLSDI	= 0x00000001,		//全SDI
	DEVEX_NR ,
};
enum NetConnectType			//最大链接数类型
{
 	NETCONNECT_NAT,
	NETCONNECT_TCP,
	NETCONNECT_NR,
};
class CDevAbility
{

	PATTERN_SINGLETON_DECLARE(CDevAbility);
public:

	bool Start(void);
	int GetDigDecChns();
	//获得采集通道数+解码通道数
	int GetCapDecChns();
	int GetVTotalChns();
	int GetVCapChns();
	int GetMaxNetConnectNum(int ConnetType);//获取最大网络视频链接数
	//获得数字通道数
	int GetVDigitChns();
	int GetVMaxDecChns();
	int GetVPlayChns();
	int GetVPlayMaxChns();
	int GetVExCapChns();	
	
	int GetVOutChns();
	int GetVideoStandard();
	

	int GetAudioCapChns();
	int GetAudioInChns();
	
	int GetAlarmInChns();
	int GetAlarmOutChns();

	int GetLanguage();

	int GetMaxVPlayChns();

	int GetCommChns();//得到当前启用的232串口数目
	int GetPtzChns(); //得到当前启用的云台设备数目

	const CAPTURE_CHNINFO & getChannelInfo();
	int GetDevType();
	int HasSnapShot();
	int HasNatFunc();
	int HasSpotFunc();
	int HasIntelFunc();
	int HasOnvifFunc();

	//智能PEA支持，位对应通道	
	uint GetIntelPEAFunc();
	//智能OSC支持，位对应通道
	uint GetIntelOSCFunc();
	//智能AVD支持，位对应通道
	uint GetIntelAVDFunc();
	//智能CPC支持，位对应通道
	uint GetIntelCPCFunc();
	uint getFrontSwithType();//获取前面板是否需要转换
	bool MacRepeat(char* mac);// 判断MAC地址是否与出厂默认MAC相同
	uint DevExModel();	//得到EX属性
	bool CaptureGetProTotalHVRCap(CAPTURE_TOTAL_HVRCAP *pHVRCap); //得到用于存储显示的模式
private:
	int m_nVTotalChns; 	//总的视频通道数(采集+数字)
	int m_nDigDecChns;	//数字通道数(解码)
	int m_nCapSumDec; //采集通道数+解码通道数
	int m_nVCapChns; 	//采集通道数
	int m_nVDigitChns;	//数字通道数(视频)
	int m_nVPlayChns;	//回放通道数
	int m_nVPlayMaxChns; //最大回放路数
	int m_nVExCapChns;	//
	int m_nVOutChns;	//视频输出通道数
	int m_nAudioInCHns;	//音频输入通道数
	int m_nAudioCapChns;//音频采集通道数
	int m_nAlarmInChns;	//报警输入通道数
	int m_nAlarmOutChns;//报警输出通道数
	int m_nVideoStandard; //视频制式
	int m_nLanguage;	//语言
	int m_nMaxVPlayChns;	// HVR各种模式中最大的通道数

	int m_nCommChannel;//当前启用的232串口数目
	int m_nPtzChannel; //当前启用的云台设备数目
	int m_nMaxNetConnectNum[NETCONNECT_NR];//最大网络视频链接数
	
	Bool m_bSnapShot; //支持抓拍
	Bool m_bNatFunc; //支持NAT功能
	Bool m_bSpotFunc; //支持Spot功能
	Bool m_bIntelFunc; //支持Inte功能
	uint m_uIntelPEA; //智能PEA支持，位对应通道
	uint m_uIntelOSC; //智能OSC支持，位对应通道
	uint m_uIntelAVD; //智能AVD支持，位对应通道
	uint m_uIntelCPC; //人流量记数支持，位对应通道
	uint m_nFrontSwithType;//需要前面板转换
	CAPTURE_CHNINFO m_ChnInfo;
	int m_nMaxDecorderChns; //最大解码通道数
	uint m_DevExModel;//扩展模式SDI相关
	CAPTURE_TOTAL_HVRCAP m_ProHVRCAP; //当数字通道数大于解码通道数时，用于存储显示的模式
	Bool m_bOnvifFunc; //支持onvif
	int getAudioInNum();
	
	void onHookDevDesc(CConfigTable &cfgDevDesc, int &ret);
};

#define g_DevAbility (*CDevAbility::instance())
#endif
