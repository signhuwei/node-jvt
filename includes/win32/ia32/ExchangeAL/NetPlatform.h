//
//  "$Id: NetIPOperation.h 4 2009-06-11 13:01:43Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
// 	Description:	
// 	Revisions:		Year-Month-Day  SVN-Author  Modification
//	Modify:			���������Json��ʽ����
//

#ifndef __EXCHANGE_AL_NETPLATFORM_OPERATION_H__
#define __EXCHANGE_AL_NETPLATFORM_OPERATION_H__

#include "Types/Defs.h"
#include "NetWorkExchange.h"

struct CONFIG_NET_MEGA
{
	bool bEnable;
	bool bNetManEnable;
	IPAddress ServerIP;
	int iServerPort;
	char sDeviceId[32];
	char sUserName[24];
	char sPasswd[32];
	int iMaxCon;
	int iVideoPort;
	int iAudioPort;
	int iMsgPort;
	int iUpdatePort;
};

struct MegaMotion
{
	/*Rect*/RECT mRect[MAX_COVER_COUNT];
};

struct MegaMotionAll
{
	MegaMotion MotionRect[N_SYS_CH];
};


// ����ƽ̨
struct CONFIG_NET_XINWANG
{
	bool bEnable;
	bool bSyncTime;
	bool bSubStream;
	IPAddress ServerIP;
	int iServerPort;
	int iDownLoadPort;
	char sPasswd[32];
	char szSID[32];
};

// ����ƽ̨
struct CONFIG_NET_SHISOU
{
	bool bEnable;
	RemoteServerConfig Server;
	char szSID[MAX_USERNAME_LENGTH];
};

// ������̩��ƽ̨
struct CONFIG_NET_BJHONGTAIHENG
{
	bool bEnable;
	char ServerUrl[64]; //��������ַ
	char DevID[16];     //�豸id
	char Password[16];  //�豸��֤��
	char DevModel[16];     //�豸�ͺ�
	char SerialNo[20]; //�豸���к�	
};

// VVEYEƽ̨
struct CONFIG_NET_VVEYE
{
	bool bEnable;                
	bool bCorpEnable;            //ֻ����ʹ����ҵ������ʱ����Ҫ����Server
	RemoteServerConfig Server;
	char szDeviceName[MAX_USERNAME_LENGTH];
};

//WELLSUNƽ̨
struct CONFIG_NET_WELLSUN
{
	bool bEnable;
	RemoteServerConfig Server;
	unsigned int    uiDevID;            //device id
	int nGPSHeartBeat;                  //gps hearbeat
	int nSysHeartBeat;                  //svr hearbeat
};

// ���ƽ̨
struct CONFIG_NET_NANRUI
{
	bool bEnable;
	RemoteServerConfig Server;
	char szSID[MAX_USERNAME_LENGTH];
};

//���ݿ���ƽ̨
/***�û���Ϣ***/ 
typedef union {	//IP addr
	unsigned char	c[4];
	unsigned short	s[2];
	uint	l;
}LOCALSDK_IPAddress;

struct CONFIG_KAINENG_USERINFO
{
	char szUserName[16];           //�û�������5�����ֻ�ʮ����ĸ;
	char szUserAddr[128];          //�û���ַ��30�����ֻ�60����ĸ;
	char szUserAttr[16];           //�û����ʣ�5�����ֻ�ʮ����ĸ��
	
	char szBelongUnit[64];         //��ܵ�λ��15�����ֻ�30����ĸ;
	char szBelongUnitPhone[16];    //��ܵ�λ�绰��14λ���֣��ֻ���"-" �����;
	
	char szPoliceUnit[64];         //������λ��15�����ֻ�30����ĸ;
	char szPoliceUnitAddr[128];    //������λ��ַ��30�����ֻ�60����ĸ;
	char szPoliceUnitPhone[16];    //������λ�绰��14λ���֣��ֻ���"-"�����;
	
	char szPolicePhone[4][16];
	char szPolOrCenPhone[2][16];   //����/���ĵ绰1��2��14λ���֣��ֻ���"-" �����;

	char szFTP[64];                //FTP��50���ַ���
	char szEMail[64];              //E-Mail: 50���ַ���
	LOCALSDK_IPAddress PoliceIP;   //�Ӿ�����IP��ַ
	int nHttpPort;                 //�Ӿ�����IP�˿�
};

/***�豸��Ϣ***/
//���ò�������ö��
typedef enum GuardType
{
	FORBID = 0,      //��ֹ
	TEN_MIN,         //ʮ����
	THIRTY_MIN,      //��ʮ����
	SIXTY_MIN,       //��ʮ����
	MAX,
}GUARDTYEP;

struct CONFIG_KAINENG_DEVINFO
{
	char ProbeNum1;                //��������������������ÿ��������� 1�ŵ�10��̽����ѡ�� ��Ĭ������Ϊ <1��̽����>
	char ProbeNum2;                //��������������������ÿ��������� 1�ŵ�10��̽����ѡ�� ��Ĭ������Ϊ <1��̽����>	
	char nProbeType;			   //������������ ��ѡ��3��Ϊ <��ֹ>  <AND>  <OR>  Ĭ��Ϊ <��ֹ>
	char nGuardType;               //���ò���, ����GUARDTYEP

	int AlarmTime;                //���ѿ���ʱ�䣺��λ���ִ�000-999  Ĭ��Ϊ��180
	int nGuardArea;               //���߷������ͣ���λ���֣�ÿλ��С0���3����00000000 ��33333333;  Ĭ�ϣ�00000000��
	
	char szRemConAddr[4][4];       //ң����1-4�ŵ�ַ ����λ16�����ַ�����գ���0-9  A-F����Ĭ��Ϊ�գ�
	char szLinDevAddr[6][4];       //�����豸��1-6��ַ����λ16�����ַ�����գ���0-9  A-F����Ĭ��Ϊ�գ�
	char szProbeAddr[10][4];       //̽����1-10�ŵ�ַ����λ16�����ַ�����գ���0-9  A-F����Ĭ��Ϊ�գ�
	
	//��ʱ������
	char szGuardTime[3][9];        //��ʱ������,ÿ�鶼Ϊchar [8] ���� ��00 00 00 00������ɿ�ʼʱ�ֵ�����ʱ�֣�����Ҫ��������
};


/***��������***/
//��������ö��
typedef enum KNAlarmLink
{
	LINK_EMPTY = 0,
	LINK_SWITH,
	LINK_10S,
	LINK_30S,
	LINK_60S,
	LINK_200S,
	LINK_600S,
	LINK_METHOD_1,
	LINK_METHOD_2,
	LINK_MAX,
}KNALARMLINK;

struct CONFIG_KAINENG_LINKINFO
{
	char eLink[10][7];        //��������,ȡֵΪ��������ö��
};

//���ܶ��ƣ�3��������Ϣȫ�����
struct CONFIG_KAINENG_INFO
{
	CONFIG_KAINENG_USERINFO UserInfo;
	CONFIG_KAINENG_DEVINFO DevInfo;
	CONFIG_KAINENG_LINKINFO LinkInfo;
};

//���ܻص��ṹ��
typedef struct 
{	
	CONFIG_KAINENG_DEVINFO DevInfo;
	CONFIG_KAINENG_LINKINFO LinkInfo;
}LOCALSDK_CBCONFIG_KAINENG_INFO;
#endif
