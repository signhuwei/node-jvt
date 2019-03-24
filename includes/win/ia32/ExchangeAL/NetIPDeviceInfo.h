//
//  "$Id: NetIPDeviceInfo.h 14324 2014-12-16 07:32:29Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:			2008-12-04 liwj create the file
//					�û������������ת��
//

#ifndef __EXCHANGE_ALARM_INFO_H__
#define __EXCHANGE_ALARM_INFO_H__

#include "Types/Defs.h"
#include "Infra/Time.h"
#include <string>
#include "Comm/Positioning.h"


/// �豸��Ϣ
struct SystemInformation
{
	std::string sSoftWareVersion;	///< ����汾��Ϣ
	std::string sHardWareVersion;	///< Ӳ���汾��Ϣ
	std::string sEncryptVersion;	///< ���ܰ汾��Ϣ
	SystemTime tmBuildTime;		///< �������ʱ��
	std::string sSerialNo;			///< �豸���к�
	int iVideoInChannel;	///< ��Ƶ����ͨ����
	int iVideoOutChannel;	///< ��Ƶ���ͨ����
	int iAlarmInChannel;	///< ��������ͨ����
	int iAlarmOutChannel;	///< �������ͨ����
	int iTalkInChannel;		///< �Խ�����ͨ����
	int iTalkOutChannel;	///< �Խ����ͨ����	
	int iExtraChannel;		///< ��չͨ����	
	int iAudioInChannel;	///< ��Ƶ����ͨ����
	int iCombineSwitch;		///< ��ϱ���ͨ���ָ�ģʽ�Ƿ�֧���л�
	int iDigChannel;		///<����ͨ����
	uint uiDeviceRunTime;	///<ϵͳ����ʱ��
	std::string sHardWare;	///<�豸�ͺ�
	std::string uUpdataTime;	///<��������
	uint uUpdataType;	///<��������
};

///< ��������Ϣ�ṹ
struct DriverInformation 
{
	int		iDriverType;		///< ����������
	bool	bIsCurrent;			///< �Ƿ�Ϊ��ǰ������
	uint	uiTotalSpace;		///< ��������MBΪ��λ
	uint	uiRemainSpace;		///< ʣ��������MBΪ��λ
	int		iStatus;			///< �����־���ļ�ϵͳ��ʼ��ʱ������
	int		iLogicSerialNo;				///< �߼����
	SystemTime  tmStartTimeNew;		///< ��¼��ʱ��εĿ�ʼʱ��
	SystemTime	 tmEndTimeNew;			///< ��¼��ʱ��εĽ���ʱ��
	SystemTime	 tmStartTimeOld;		///< ��¼��ʱ��εĿ�ʼʱ��
	SystemTime	 tmEndTimeOld;			///< ��¼��ʱ��εĽ���ʱ��
};

/// ������Ϣ�ṹ
struct StorageDeviceInformation
{
	int		iPhysicalNo;		// Ӳ��������ţ���0��ʼ
	int		iPartNumber;		// ������
	DriverInformation diPartitions[MAX_DRIVER_PER_DISK];
};

struct StorageDeviceInformationAll
{
	int iDiskNumber;
	StorageDeviceInformation vStorageDeviceInfoAll[MAX_DISK_PER_MACHINE];
};


/// �澯״̬
struct AlarmState
{
	int iVideoMotion; ///< �ƶ����״̬,�������ʾͨ����,bit0����ͨ��һ,�Դ����� 1: �и澯 0: �޸澯
	int iVideoBlind; ///< ��Ƶ�ڵ�״̬,�������ʾͨ����,bit0����ͨ��һ,�Դ����� 1: �и澯 0: �޸澯
	int iVideoLoss;	///< ��Ƶ��ʧ״̬,�������ʾͨ����,bit0����ͨ��һ,�Դ����� 1: �и澯 0: �޸澯
	int iAlarmIn;	///< �澯����״̬,�������ʾͨ����,bit0����ͨ��һ,�Դ����� 1: �и澯 0: �޸澯
	int iAlarmOut;	///< �澯���״̬,�������ʾͨ����,bit0����ͨ��һ,�Դ����� 1: �и澯 0: �޸澯
};

struct ChannelState
{
	bool bRecord; ///< �Ƿ�����¼��
	int iBitrate;	///< ��ǰ����
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
	VENDOR_TKL,           //�¼���
	VENDOR_ZHOUSHIDA,     //���Ӵ�
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

//GPS״̬
struct GPSStatusInfo
{
	int             positioningStatus; //��λ״̬��ȡֵ��ö��POSITIONING_STATUS����
	POSITIONING_POS longitudePos;      //����
	POSITIONING_POS latitudePos;       //γ��
	char            rev[12];
};

//wifi״̬
struct WifiStatusInfo
{
	int  connectStatus;  //wifi����״̬  ��ö��INFO_NET_LINK_STATUS����
	int  strength;       //�ź�ǿ��
	char rev[24];
};

//3G״̬
struct WirelessStatusInfo
{
	int  connectStatus;  //3G����״̬  ��ö��INFO_NET_LINK_STATUS����
	int  strength;       //�ź�ǿ��
	char rev[24];
};

//����ע��״̬
struct DASStatusInfo
{
	int  connectStatus;  //DAS����״̬  ��ö��INFO_NET_LINK_STATUS����
	char rev[28];
};

/*����Ϣֻ�ṩ���ͻ������ڹ���ͻ��Լ��Ĳ�Ʒ��
����Ϣ������������ά����
����Ϣ����ʾ���κοɼ��Ĺ�����������IE����
ֻ���޸����ù�������ɼ���
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
