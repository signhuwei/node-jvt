//
//  "$Id: Net.h 3756 2012-07-03 01:36:52Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_NETWORK_H__
#define __PAL_NETWORK_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup NetAPI API Net
/// ����ӿڡ�DDNS��PPPoE�Ĳ����������ȡ��
/// @{

/// ����������IP��ַ
/// 
/// \param [in] pEthName ��������NULL��ʾ��ǰʹ�õ�����
/// \param [in] pHostIp ����IPpHostIp
/// \param [in] pNetMask �����������ַ���
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetSetHostIP(const char *pEthName,
				 const char *pHostIp,
                 const char *pNetMask);


/// �������ص�ַ
/// 
/// \param [in] pEthName ��������NULL��ʾ��ǰʹ�õ�����
/// \param [in] pGateway ���ص�ַ����ַ���
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetSetGateway(const char *pEthName,
				  const char *pGateway);


/// ��ȡ������IP��ַ
/// 
/// \param [in] pEthName ��������NULL��ʾ��ǰʹ�õ�����
/// \param [out] pHostIp ����IP��ַ����ַ���
/// \param [in] iHLen ����IP��ַ�ַ������峤��
/// \param [out] pNetMask �����������ַ���
/// \param [in] iNLen ���������ַ������峤��
/// \retval 0  ��ȡ�ɹ�
/// \retval <0  ��ȡʧ��
int NetGetHostIP(const char *pEthName,
				 char *pHostIp,
                 const int iHLen,
                 char *pNetMask,
                 const int iNLen);


/// ��ȡ���ص�ַ
/// 
/// \param [in] pEthName ��������NULL��ʾ��ǰʹ�õ�����
/// \param [out] pGateway ���ص�ַ����ַ���
/// \param [in] iGLen ���ص�ַ�ַ������峤��
/// \retval 0  ��ȡ�ɹ�
/// \retval <0  ��ȡʧ��
int NetGetGateway(const char *pEthName,
				  char *pGateway,
                  const int iGLen);


/// ����ARP��
/// 
/// \param [in] pEthName ��������NULL��ʾ��ǰʹ�õ�����
/// \retval 0  ���ͳɹ�
/// \retval <0  ����ʧ��
int NetSendarp(const char *pEthName);

/// ȡ�ñ�����Mac��ַ
/// 
/// \param [in] pEthName �ӿ����ƣ���eth0,eth1����NULL��ʾ��ǰʹ�õ�����
/// \param [out] pEthMac Mac16���Ƶ�ַ���ַ���������00:05:0e:11:12:15��
/// \param [in] iEthMacLen MAC��ַ���볤�ȡ�
/// \retval 0  ��ȡ�ɹ�
/// \retval <0  ��ȡʧ��
int NetGetMAC(const char *pEthName,
                 char *pEthMac,
                 const int iEthMacLen);


/// ���ñ�����Mac��ַ
/// 
/// \param [in] pEthName �ӿ����ƣ���eth0,eth1����NULL��ʾ��ǰʹ�õ�����
/// \param [in] pEthMac Mac16���Ƶ�ַ���ַ���������00:05:0e:11:12:15
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetSetMAC(const char *pEthName, const char *pEthMac);

/// ��ȡDNS��ַ
/// 
/// \param [out] pPrimary ��ѡ��DNS��������ַ�ַ�����
/// \param [in] iPlen ����,Ҫ����16
/// \param [out] pSecondary ��ѡ��DNS��������ַ�ַ�����
/// \param [in] iSlen ����,Ҫ����16
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetGetDNSAddress(char *pprimary, int iPlen ,char *psecondary, int iSlen);
/// ����DNS��ַ
/// 
/// \param [in] pPrimary ��ѡ��DNS��������ַ�ַ�����
/// \param [in] pSecondary ��ѡ��DNS��������ַ�ַ�����
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetSetDNSAddress(const char * pPrimary, const char * pSecondary);

/// ����DNS����
/// 
/// \param [in] pDomain DNS�����ַ�����
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetSetDNSDomain(const char * pDomain);


/// ���ü������
/// 
/// \param [in] pHostName ��������ַ�����
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetSetDNSHostName(const char * pHostName);

//int NetSetMac(const char * pMac);

/// ��ʼ��DVR web�ؼ�
/// 
/// \param [in] iWebPort web����˿ں�
/// \param [in] iAppPort Ӧ�ó���˿ں�
/// \param [in] iLanguage web�ؼ��������
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��

//int	WebInitialize(int iWebPort, int iAppPort, int iLanguage);

/// WEN���ýṹ
typedef struct WEB_PARAM_CONFIG
{
	int		iWebPort;		 ///< HTTP �˿�
	int 	iTCPPort;	     ///< TCP �˿�
	int 	iUDPPort;	     ///< UDP �˿�
	int 	iRtspPort;	     ///< RTSP �˿�
	int 	iLanguage;	     ///< ����
	char*   strWebRoot;		 ///< WEB��Դ�ļ���Ŀ¼
	char*   strLangFile;     ///< �����ļ�
	int     iResev[4];       ///< ����
}WEB_PARAM;

int WebConfig(int cfgKind, const char *pConfig, int nSize);
int WebStart(int iWebPort, int iAppPort, int iLanguage, const char* strWebRoot, const char* webFile);
int WebStartV2(int iWebPort, int iAppPort, int iRtspPort, int iLanguage, const char* strWebRoot, const char* webFile);

int WebStartV3(WEB_PARAM *pWebParam);
int WebStop(void);
int WebRestart(void);
int WebStatus(void);

typedef int (*funcHttpProc)(int nCmd, void *pParm, int nLen, unsigned int dwUser);

int WebSetCallBack(funcHttpProc, void*);

/// ����DVR web�ؼ���ӳ��˿�
/// 
/// \param [in] iWebPort web����ӳ���Ĺ����˿ں�
/// \param [in] iAppPort Ӧ�ó��򾭹�ӳ���Ĺ����˿ں�
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int WebSetMapPort(int iWebPort, int iAppPort);

/// ����DVR web�ؼ����ص�URL
/// 
/// \param [in] pURL WEB�ؼ�URL
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int WebSetActiveXUrl(const char* pURL);

/////////////////////////////////////////////////////
/// ����������IP/����/���ص�ַ
///���麯���������ö�������������ʱͨ������pEthName������������"eth0","eth2"
///������������μ������Ӧ����
int NetSetHostIP2(const char *pEthName,  
		   const char *pHostIp,
                 const char *pNetMask);


/// �������ص�ַ
int NetSetGateway2(const char *pEthName,
				const char *pGateway);


/// ��ȡ������IP��ַ
int NetGetHostIP2(const char *pEthName,
		   char *pHostIp,
                 const int iHLen,
                 char *pNetMask,
                 const int iNLen);


/// ��ȡ���ص�ַ
int NetGetGateway2(const char *pEthName,
		    char *pGateway,
                  const int iGLen);

// ����·��
/// 
/// \param [in] pEthName ������
/// \param [in] addr IP
/// \param [in] mask ����
/// \param [in] gw ����
/// \param [in] nFlag 0: host route 1: default route
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��

int NetAddRoute(const char *pEthName, struct in_addr addr, struct in_addr mask, struct in_addr gw, int nFlag);

// ɾ��·��
/// 
/// \param [in] pEthName ������
/// \param [in] nFlag 0: host route 1: default route
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetDelRoute(const char *pEthName, int nFlag);


//////////////////////////////////////////////


/// DDNS���ýṹ
typedef struct NET_DDNS_CONFIG
{
	int		enable;			///< �Ƿ�����DDNS��0-��������1-����
	char	hostname[32];	///< ����������0���������ַ�����
	char	username[32];	///< DDNS�����û�������0���������ַ�����
	char	password[32];	///< DDNS�������룬��0���������ַ�����
	char	serverip[32];	///< DDNS������IP��ַ����0���������ַ����������ʽ����192.168.0.6��
	int		serverport;		///< DDNS����˿ڡ�
} NET_DDNS_CONFIG;


/// ����DDNS����̬�������������á�
/// 
/// \param [in] pConfig ���ýṹNET_DDNS_CONFIGָ�롣
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetSetDDNSConfig(NET_DDNS_CONFIG *pConfig);


/// ��ȡDDNS����̬�������������ã� ���û�����ã�Ӧ������һ����ʼ���Ľṹ��
/// 
/// \param [out] pConfig ���ýṹNET_DDNS_CONFIGָ�롣
/// \retval 0  ��ȡ�ɹ�
/// \retval <0  ��ȡʧ��
int NetGetDDNSConfig(NET_DDNS_CONFIG *pConfig);

/// PPPoE���ýṹ
typedef struct NET_PPPOE_CONFIG
{
	int		enable;			///< �Ƿ�����PPPoE��0-��������1-����
	char	username[64];	///< �ʻ��û�������0���������ַ�����
	char	password[64];	///< �ʻ����룬��0���������ַ���, ��ΪCMOS�ռ������������Ϊ8�ֽڡ�
} NET_PPPOE_CONFIG;


/// ����PPPoE����̫����Ե㣩���á�
/// 
/// \param [in] pConfig ���ýṹNET_PPPOE_CONFIGָ�롣
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetSetPPPoEConfig(NET_PPPOE_CONFIG *pConfig);


/// ��ȡPPPoE����̫����Ե㣩���ã����û�����ã�Ӧ������һ����ʼ���Ľṹ��
/// 
/// \param [out] pConfig ���ýṹNET_PPPOE_CONFIGָ�롣
/// \retval 0  ��ȡ�ɹ�
/// \retval <0  ��ȡʧ��
int NetGetPPPoEConfig(NET_PPPOE_CONFIG *pConfig);


/// ��ȡPPPoE���ź�����IP��ַ
int NetGetDialIpAddress(char *pDailIp);


/// ����DHCPʹ�ܱ�־��
/// 
/// \param [in] enable Bit0~bit31�ֱ�����Ӧ�ڼ���������DHCPʹ�ܱ�־ 0�� ��ʹ�� 1�� ʹ��
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int NetSetDhcpEnable(int enable);

/// ��ȡDHCP��ʹ�ܱ�־
/// 
/// \param [out] pEnable Bit0~bit31�ֱ�����Ӧ�ڼ���������DHCPʹ�ܱ�־ 0�� ��ʹ�� 1�� ʹ��
/// \retval 0  ��ȡ�ɹ�
/// \retval <0  ��ȡʧ��
int NetGetDhcpEnable(int *pEnable);

/// ��ȡ��������״̬
/// 
/// \param [out] ethname ������, һ��Ϊ"eth0"
/// \retval 0 ��������
/// \retval other �쳣
int mii_diag(char *ethname);


/// ���IP��ַ�Ƿ��ͻ
/// 
/// \retval 0 ����
/// \retval other ��ͻ
int ArpCheck();


/// @} end of group


#define IW_ENCODING_TOKEN_MAX 128 //64

typedef struct 
{
	int nEnable;
	char	 SSID[36];
	int  nChannel;      //
	char  NetType[32];	 //Infra, Adhoc
	char  Encode[32];  // NONE, WEP, TKIP, AES
	char  Auth[32];    // OPEN, SHARED, WEPAUTO, WPAPSK, WPA2PSK, WPANONE, WPA, WPA2
	int  nKeyType;    //0:Hex 1:ASCII
	char   Keys[IW_ENCODING_TOKEN_MAX]; 
	//int  KeyID;
}CONFIG_WLAN;

typedef struct 
{
	char	SSID[36];
	int nRSSI;                          //SEE RSSI_SINGNAL
	int nChannel;
	char  NetType[32];	 //Infra, Adhoc
	char  Encode[32];   // NONE, WEP, TKIP, AES
	char  Auth[32];      // OPEN, SHARED, WEPAUTO, WPAPSK, WPA2PSK, WPANONE, WPA, WPA2
}WLAN_DEVICE;

int WLanOpen();
int WLanClose();
int WLanSetConfig(CONFIG_WLAN* pconfig);
int WLanGetConfig(CONFIG_WLAN* pconfig);
WLAN_DEVICE* WLanScanDevices(int *pNum);

//wifi�豸�Ƿ����
//����ֵ�� 1  �豸����    0 �豸������
int WLanIsDeviceExist(void);

//wifi�Ƿ����ӳɹ�
//����ֵ�� 1  ���ӳɹ�    0 ����ʧ��
int WLanIsConnect(void);

//��ȡ����������
int WLanGetIfname(char * ifname);

//���麯�����ڶ���������
int NetSetHostIPEx(const char *pEthName,  
		   			const char *pHostIp,
                 			const char *pNetmask);
/// �������ص�ַ
int NetSetGatewayEx(const char *pEthName,
					     const char *pGateway);


/// ��ȡ������IP��ַ
int NetGetHostIPEx(const char *pEthName,
		   			 char *pHostIp,
                 			 const int iHLen,
                 			 char *pNetmask,
                 			 const int iNLen);
/// ��ȡ���ص�ַ
int NetGetGatewayEx(const char *pEthName,
		    			     char *pGateway,
                  			     const int iGLen);
//��ȡEthName����Ӧ�ò���á��ɴ�ϵͳ��ȡ����д��
//int NetGetEthName(int EthNo, char *pEthName, int len_EthName);

//*pEthName :	����֧�ֵ�������,��::�ָ�,��eth0::eth2::
//len_EthName:	����֧�ֵ�������BUF����,һ��Ҫ����,����ʧ��
//*Ethnum:		ʵ���ҵ�����������

int NetGetEthName( char *pEthName, int len_EthName, int *iEthnum);

int NetGetDefaultEth(char *pEthName);
int NetSetDefaultEth(const char *pEthName);

enum network_media {
 NM_WIRED = 0,  //��������
 NM_WLAN,       //Wifi
 NM_3G,         //3G����
 NM_NR,    //������
};
#define NM_WIRELESS NM_WLAN

typedef struct tagNetDevice
{
	unsigned char valid;			//��ǰ�����Ƿ�����
	unsigned char trans_media;	//����ý��
	unsigned char reserved[6];	//����
	char name[32];		//��������
	
}NetDevice;

//�����������ȼ�
typedef struct tagNetLinkOrder
{
	int netType;  //ȡֵ��network_media���͵�
	int netOrder; //����ԽС�����ȼ�Խ��,0��������ȼ�
}NetLinkOrder;

/********************************************************************
**
**	������	:	NetGetEthDevice
**	���	:	
**				1.	pNetDev:ָ���������ԽṹNetDevice��ָ�����顣
**				2.	iMax   :���֧�ֵ���������(��������Ϊ10,Ŀǰʵ��Ϊ3��)
**	����	:	> 0 ֧�ֵ�ʵ����������
**				= 0 ֧����������Ϊ0,��ʧ��
**	����˵��:	�˺�������Ӧ�ò��ȡ����֧�ֵĸ���,�Լ���Ӧ����������͵�ǰ�Ƿ����
**
*********************************************************************/
int NetGetEthDevice(NetDevice *pNetDev, int iMax);


/*
* ��  �ã����������޸Ĵ�����ָ��
* ��  ����[in] newNetTpye �л��ɹ��Ժ�ʹ�õ��������ͣ�����ֵ��ö��ֵnetwork_media��ʾ
* ����ֵ���Ⱥ���
* ˵  ����������ᴴ��һ�����ָ�ʽ�ĺ�����Ȼ����ע�ᵽ������صĿ����������״̬�л��Ժ���øú���ָ�룬
*         ����newNetType���л��ɹ��Ժ�ʹ�õ���������
*/
typedef int (*pFunc_NetTypeChange)(network_media newNetType);

/*
* ��  �ã�ע�����������л��ص�����
* ��  ����[in] changeEditProc Ҫע��Ļص�����
* ����ֵ��0��ע��ɹ�  -1��ע��ʧ��
* ˵  ���������������л���ɺ�Ż�ִ�лص�����
*/
int NetAttchTypeChangeProc(pFunc_NetTypeChange changeEditProc);

/*
* ��  �ã�����ָ�����������˳��
* ��  ����[in] enable    �Ƿ����øù���  0������  -1��������
*         [in] netCount  ��Ҫ���������������Ŀ
*         [in] pNetOrder �ṹ�����飬�����������ͺ����Ӧ�����ȼ�������ԽС�����ȼ�Խ��
* ����ֵ��0�����óɹ�  -1������ʧ��
* ˵  ���������ʱ��ؾ�������ַʱ��������������Ӧ�ı��ص�ַ����һ�������ڣ������õ�����˳����Ч��
*         �����ߵ�ַ��10.6.2.38������������255.255.0.0��Wifi�ĵ�ַ��192.168.1.5������������255.255.255.0��
*         �򵱷��ʵĵ�ַ��10.6.5.38ʱ�����ݻ�ֱ��ͨ�����߷��ͳ�ȥ����Ϊ���ߵı��ص�ַ��Ŀ�ĵ�ַ��ͬһ�������ڣ���ʱ�������ȼ���Ч��
*/
int NetSetLinkOrder(int enable, int netCount, NetLinkOrder* pNetOrder);



/* �������� */
typedef enum tagWirelessType
{
	WIRELESS_TYPE_AUTOSEL=0,		/* �Զ�ѡ��*/
	WIRELESS_TYPE_TD_SCDMA=1,	/* TD-SCDMA���� */
	WIRELESS_TYPE_WCDMA=2,		/* WCDMA���� */
	WIRELESS_TYPE_CDMA_1x=3,		/* CDMA 1.x���� */
	WIRELESS_TYPE_EDGE=4,		/* GPRS���� */
	WIRELESS_TYPE_EVDO=5,		/*EVDO����*/
	WIRELESS_TYPE_MAX
}WirelessType;

// �����豸
typedef struct tagWIRELESS_DEVICE
{
	unsigned int	typeMask; ///< ֧�ֵ������������룬��λ��ʾ��ÿһλ��ӦWirelessType����
	char	info[32]; ///< ������Ϣ
	int reserved[23];
}WIRELESS_DEVICE;


typedef struct tagWIRELESS_CONFIG
{
	int iEnable;					/* ����ģ��ʹ�ܱ�־ */
	WirelessType iNetType;			/* ������������*/
	char szAPN[32];		         	/* ��������ƣ��ַ���, ����'\0'��������32bytes */
	char szDialNum[32];  			/* ���ź��룬�ַ���, ����'\0'��������32bytes */
	char  szUserName[128];  		/* �����û������ַ���, ����'\0'��������16bytes */
	char szPWD[128];  				/* �������룬�ַ���, ����'\0'��������16bytes */
	char Reserved[8]; 				/* Ԥ��8�ֽڣ�����չ */
}WIRELESS_CONFIG;


// ��������״̬
typedef struct tagWIRELESS_STATUS
{
	int iAccessStat; /* ��������ע��״̬*/
	char szDevIP[16];   /* ǰ���豸����IP���ַ���, ����'\0'��������16byte*/
	char szSubNetMask [16];   /* ǰ���豸�����������룬�ַ���, ����'\0'��������16byte */
	char szGateWay[16];  /* ǰ���豸�������أ��ַ���, ����'\0'��������16byte */
	WirelessType iNetType : 8; /* ������������*/
	char Reserved1[3];   /* �����ֽڣ�������չ*/
	char Reserved[4];   /* �����ֽڣ�������չ*/
}WIRELESS_STATUS;

typedef  enum tagNetworkDevType
{
	NWDEV_ETH0 = 0,				/* ��̫�� */
	NWDEV_WLAN = 8,				/* W-lan */
	NWDEV_3G_= 16				/* TD-SCDMA */
} NWDevType;
// ���������ź�ǿ��,���ظ�����ʽ�����ź�ǿ��ָʾ����Χ0-100��100��ʾ����

typedef struct  tagWIRELESS_RSSI
{
	int td_scdma;
	int wcdma;  
	int cdma_1x;  
	int edge; 
	int evdo;  
	int reserved[11]; /*�����ֽڣ�������չ*/
}WIRELESS_RSSI;

int WirelessCreat( void );
int WirelessRelease( void );

int WirelessGetConfig(WIRELESS_CONFIG* pconfig );
int WirelessSetConfig(WIRELESS_CONFIG *pconfig );
int WirelessGetStatus(WIRELESS_STATUS* pstatus );
int GetNetWorkDevice(NWDevType *pType);
int WirelessGetRSSI (WIRELESS_RSSI* prssi);
int WirelessGetSMS (char* sender, char * pstring);
int WirelessPutSMS (const char* receivers[32], const char * pstring);
int PPPOEGetIP( char * ip, int const ip_len, char * netmask, int const mask_len );
int WirelessGetDialog(char* caller);
int WirelessNeedBlock(void);
int WirelessGetDevice( WIRELESS_DEVICE* device );

//��  �ã��ж�3G�豸�Ƿ����
//����ֵ��0 �豸����  ����ֵ���豸������
int isWirelessDeviceExist(void);

//��  �ã��ж�3G�豸�Ƿ񲦺ųɹ�
//����ֵ��0 ���ųɹ�  ����ֵ������ʧ��
int isWirelessDialUp(void);

 // USB 3Gģ��ӿ�������128�ֽ�
typedef struct usb3GDesc
{
	char		manufacturer[32];	//��������
	char		product[32];		      //��Ʒ����
	char		version[16];		      //�汾��
	char		speed[8];		     //usb�ٶ�
	char		vendor[16];  
	char		prodID[16];
	char		reserved[40];	    //< ����
} usb3GDesc;
 
/*********************************************************
*����:���wireless�豸�Ƿ����ӣ����ӳɹ������豸��Ϣ
*����desc: [out] �����豸��Ϣ
*����ֵ: 	>0:   �ɹ�<0:     ʧ��
*********************************************************/
int scan_wireless_device(usb3GDesc *desc);

#ifdef __cplusplus
}
#endif

#endif 
