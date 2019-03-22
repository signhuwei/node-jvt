/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/
/*
 * - _explain_
 *
 * Copyright (C) 2005 JUFENG Technologies, All Rights Reserved.
 *
 * $Id: MsgDef.h 1823 2011-07-28 14:01:01Z renxusheng $
 *
 *  Explain:
 *     -explain-
 */
/*-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-*/

#ifndef _MSGDEF_H
#define _MSGDEF_H

#if defined(WIN32)
#pragma pack()
#endif

#include "../Types/Types.h"

#define MSG_VERSION		(0x01)
#define MSG_HEADFLAG	(0xFF)

#define MSG_HEAD_LEN   (sizeof(DVRIP_MSG_HEAD_T))
#define MAX_MSG_DATA_LEN	(64*1024)

typedef struct netipmsg_h
{
	uchar		HeadFlag;		/* head flag = 0xFF */
	uchar		Version;			/* version  */
	uchar		Reserved1;		/* reserved1 */
	uchar		Reserved2;		/* reserved2 */
	uint		SID;					/* session ID */
	uint		Seq;					/* sequence number */
	union
	{
		struct
		{
			uchar		TotalPacket;	/* total packet */
			uchar		CurPacket;		/* current packet */
		}
		#ifdef LINUX
		__attribute__((packed))
		#endif
		c;
		
		struct
		{
			uchar		Channel;			/* channel */
			uchar		EndFlag;			/* end flag */
		}
		#ifdef LINUX
		__attribute__((packed))
		#endif
		m;
	}
	#ifdef LINUX
	__attribute__((packed))
	#endif
	;
	unsigned short		MsgId;			/* mesage id */
	uint		DataLen;			/* data len */
}DVRIP_MSG_HEAD_T;

#if defined(WIN32)
#pragma warning (disable : 4200)
#endif

typedef enum ret_code
{
	OK = 100,
	UNKNOWNERROR = 101,		/// δ֪����
	NOTSUPPORT = 102,		/// �汾��֧��
	NOTVALID = 103,			/// �Ƿ�����
	LOGINED = 104,			/// ���û��Ѿ���¼
	UNLOGINED = 105,		/// ���û�δ��¼
	USERORPWDERROR = 106,	/// �û����������
	NOPOWER = 107,			/// ��Ȩ��
	TIMEOUT = 108,			/// ��ʱ
	NOTFOUND = 109,			/// ����ʧ�ܣ�û���ҵ���Ӧ�ļ�
	FOUND = 110,			/// ���ҳɹ�������ȫ���ļ�
	FOUNDPART = 111,		/// ���ҳɹ������ز����ļ�
	USEREXIST = 112,		/// ���û��Ѿ�����
	USENOTEXIST = 113,		/// ���û�������
	GROUPEXIST = 114,		/// ���û����Ѿ�����
	GROUPNOTEXIST = 115,	/// ���û��鲻����
	PIRATESOFTWARE = 116,	/// �������
	NEEDREBOOT = 150,		/// �ɹ����豸��Ҫ����
	NETIP_ERR_MSGFORMATERR = 117,	///< ��Ϣ��ʽ����
	NETIP_ERR_NOPTZPROTOCOL = 118,	///< δ������̨Э��
	NETIP_ERR_NOFILEFOUND = 119,	///< û�в�ѯ���ļ�
	CONFIG_NOT_ENABLE = 120,	    ///< ����Ϊ����
	MEDIA_CHN_NOTCONNECT = 121,			//����ͨ��δ����
	NATCONNET_REACHED_MAX=122,//Nat��Ƶ���Ӵﵽ��󣬲������µ�Nat��Ƶ����
	TCPCONNET_REACHED_MAX=123,//Tcp��Ƶ���Ӵﵽ��󣬲������µ�Tcp��Ƶ����
}RET_CODE;

//��Ϣ���Ͷ���
typedef enum ctrl_msg
{
//C1: ��¼,�ǳ�,����
#ifdef _NETIP_PROTOCOL_SPECIAL
	LOGIN_REQ	= 999,
#else
	LOGIN_REQ	= 1000,
#endif
	LOGIN_RSP	= 1001,
	LOGOUT_REQ = 1002,
	LOGOUT_RSP = 1003,
	FORCELOGOUT_REQ = 1004,
	FORCELOGOUT_RSP	= 1005,
	KEEPALIVE_REQ	= 1006,
	KEEPALIVE_RSP	= 1007,

	LOGIN_DAS_REQ	= 1008,
	LOGIN_DAS_RSP	= 1009,

//C2: ϵͳ��Ϣ,�洢��Ϣ
	SYSINFO_REQ	= 1020,
	SYSINFO_RSP	= 1021,

//C3: ��������, �ڵ�,����,ͼ����ɫ
//C4: ¼������
//C5: ����,�ڵ�,��Ƶ��ʧ,�ⲿ�澯,����澯,�洢�澯
//C6: ͨ����������,�����������
//C7: ��������
//C8: ��̨����,Ԥ�õ�,Ѳ��
//C9: ������Ѳ,TV����,��Ƶ����,���,��Ƶ����
//C10: ͨ������,���ػ�����
//C11: �Զ�ά��
	CONFIG_SET = 1040,
	CONFIG_SET_RSP = 1041,
	CONFIG_GET = 1042,
	CONFIG_GET_RSP = 1043,
	DEFAULT_CONFIG_GET = 1044,
	DEFAULT_CONFIG_GET_RSP = 1045,
	CONFIG_CHANNELTILE_SET = 1046,
	CONFIG_CHANNELTILE_SET_RSP = 1047,
	CONFIG_CHANNELTILE_GET = 1048,
	CONFIG_CHANNELTILE_GET_RSP = 1049,

	CONFIG_CHANNELTILE_DOT_SET = 1050,
	CONFIG_CHANNELTILE_DOT_SET_RSP = 1051,

	//ϵͳ����
	SYSTEM_DEBUG_REQ = 1052,
	SYSTEM_DEBUG_RSP = 1053,

//C12: ��������ѯ
	ABILITY_GET = 1360,
	ABILITY_GET_RSP = 1361,

//C13: ��̨����
	PTZ_REQ	= 1400,
	PTZ_RSP = 1401,

//C14: ���ӿ���
	MONITOR_REQ	= 1410,
	MONITOR_RSP	= 1411,
	MONITOR_DATA = 1412,
	MONITOR_CLAIM = 1413,
	MONITOR_CLAIM_RSP = 1414,

//C15: �طſ���
	PLAY_REQ = 1420,
	PLAY_RSP = 1421,
	PLAY_DATA = 1422,
	PLAY_EOF = 1423,
	PLAY_CLAIM = 1424,
	PLAY_CLAIM_RSP = 1425,
	DOWNLOAD_DATA = 1426,

//C16: �����Խ�����
	TALK_REQ = 1430,
	TALK_RSP = 1431,
	TALK_CU_PU_DATA = 1432,
	TALK_PU_CU_DATA = 1433,
	TALK_CLAIM = 1434,
	TALK_CLAIM_RSP = 1435,
	TALK_NVR_TO_IPC_REQ = 1436, //NVR�������ӵ�ǰ�˿�ʼ�Խ�
	TALK_NVR_TO_IPC_RSP = 1437,

//C17: �ļ���ѯ����¼���ļ�,ͼƬ�ļ�,��־�ļ�
	FILESEARCH_REQ = 1440,
	FILESEARCH_RSP = 1441,
	LOGSEARCH_REQ = 1442,
	LOGSEARCH_RSP = 1443,
	FILESEARCH_BYTIME_REQ = 1444,
	FILESEARCH_BYTIME_RSP = 1445,

//C18: ϵͳ����
	SYSMANAGER_REQ = 1450,
	SYSMANAGER_RSP = 1451,

// ϵͳʱ���¼��ģʽ��ѯ
	TIMEQUERY_REQ = 1452,
	TIMEQUERY_RSP = 1453,

//C19: Ӳ�̹���
	DSIKMANAGER_REQ = 1460,
	DSIKMANAGER_RSP	= 1461,

//C20: �û�����
	FULLAUTHORITYLIST_GET = 1470,
	FULLAUTHORITYLIST_GET_RSP = 1471,
	USERS_GET	= 1472,
	USERS_GET_RSP = 1473,
	GROUPS_GET = 1474,
	GROUPS_GET_RSP = 1475,
	ADDGROUP_REQ = 1476,
	ADDGROUP_RSP = 1477,
	MODIFYGROUP_REQ = 1478,
	MODIFYGROUP_RSP = 1479,
	DELETEGROUP_REQ = 1480,
	DELETEGROUP_RSP = 1481,
	ADDUSER_REQ = 1482,
	ADDUSER_RSP = 1483,
	MODIFYUSER_REQ = 1484,
	MODIFYUSER_RSP = 1485,
	DELETEUSER_REQ = 1486,
	DELETEUSER_RSP = 1487,
	MODIFYPASSWORD_REQ = 1488,
	MODIFYPASSWORD_RSP = 1489,

//C21: ����/����,�澯�ϱ�
	GUARD_REQ = 1500,
	GUARD_RSP = 1501,
	UNGUARD_REQ	= 1502,
	UNGUARD_RSP = 1503,
	ALARM_REQ	= 1504,
	ALARM_RSP	= 1505,
	NET_ALARM_REQ = 1506,
	NET_ALARM_RSP = 1507,
	ALARMCENTER_MSG_REQ	= 1508,
	
//C22: ϵͳ��������
	UPGRADE_REQ = 1520,
	UPGRADE_RSP	 = 1521,
	UPGRADE_DATA = 1522,
	UPGRADE_DATA_RSP = 1523,
	UPGRADE_PROGRESS = 1524,
	UPGRADE_INFO_REQ = 1525,
	UPGRADE_INFO_RSQ = 1526,

//C23: �豸�Զ�����
	IPSEARCH_REQ = 1530,
	IPSEARCH_RSP = 1531,
	IP_SET_REQ = 1532,
	IP_SET_RSP = 1533,

//C24: ϵͳ��Ϣ���뵼��
	CONFIG_IMPORT_REQ = 1540,
	CONFIG_IMPORT_RSP = 1541,
	CONFIG_EXPORT_REQ = 1542,
	CONFIG_EXPORT_RSP = 1543,
	LOG_EXPORT_REQ = 1544,
	LOG_EXPORT_RSP = 1545,

//C25: �������
	NET_KEYBOARD_REQ = 1550,
	NET_KEYBOARD_RSP = 1551,

//  ����ץ��
	NET_SNAP_REQ = 1560,
	NET_SNAP_RSP = 1561,

	SET_IFRAME_REQ = 1562,
	SET_IFRAME_RSP = 1563,

//  ͸������
	RS232_READ_REQ = 1570,
	RS232_READ_RSP = 1571,
	RS232_WRITE_REQ = 1572,
	RS232_WRITE_RSP = 1573,
	RS485_READ_REQ = 1574,
	RS485_READ_RSP = 1575,
	RS485_WRITE_REQ = 1576,
	RS485_WRITE_RSP = 1577,

	TRANSPARENT_COMM_REQ = 1578,
	TRANSPARENT_COMM_RSP = 1579,
	RS485_TRANSPARENT_DATA_REQ = 1580,
	RS485_TRANSPARENT_DATA_RSP = 1581,
	RS232_TRANSPARENT_DATA_REQ = 1582,
	RS232_TRANSPARENT_DATA_RSP = 1583,

	

//�����¼ʱ��ͬ��
	SYNC_TIME_REQ = 1590,
	SYNC_TIME_RSP = 1591,
	//ui��ͼ
	PHOTO_GET_REQ = 1600,
	PHOTO_GET_RSP = 1601,

//�ϴ�����
	UPLOAD_DATA_START_REQ = 1610,
	UPLOAD_DATA_START_RSP = 1611,
	UPLOAD_DATA_STOP_REQ = 1612,
	UPLOAD_DATA_STOP_RSP = 1613,
/*1614 - 1629Ԥ��MSG�������ϴ���������*/
	VEHICLE_INFO_REQ = 1614,
	VEHICLE_INFO_RSP = 1615,

	RECORD_STATE_REQ = 1616,
	RECORD_STATE_RSP = 1617,

	DIGITCHN_STATE_REQ = 1618,
	DIGITCHN_STATE_RSP = 1619,

	TITLE_INFO_REQ = 1620,
	TITLE_INFO_RSP = 1621,

//����ͳ������
	CPC_DATA_SEARCH_REQ = 1630,
	CPC_DATA_SEARCH_RSP = 1631,
	CPC_DATA_CLEAR_REQ = 1632,
	CPC_DATA_CLEAR_RSP = 1633,
	
//Զ������
	NET_LOCALSEARCH_REQ = 1634,
	NET_LOCALSEARCH_RSP = 1635,

//�ʼ�����
	NET_MAILTEST_REQ = 1636,
	NET_MAILTEST_RSP = 1637,

	//�ֻ���Ϣ
	PHONE_INFO_SET = 1638,
	PHONE_INFO_SET_RSP = 1639,

	//Ӳ����Ϣ
	NET_RECORD_INFO_REQ = 1640,
	NET_RECORD_INFO_RSP = 1641,

	//�ļ�����������ɾ�������ļ���
	NET_FILE_OPRATE_REQ = 1642,
	NET_FILE_OPRATE_RSP = 1643,
	
	//Ĭ�����õ������ͳ�����Ĭ�ϵ�����
	NET_CUSTOM_CFG_EXPORT_REQ = 1644,
	NET_CUSTOM_CFG_EXPORT_RSP= 1645,
	
	//������Ƶ�ļ�����
	MUSICFILESEARCH_REQ = 1646,
	MUSICFILESEARCH_RSP = 1647,
	
	//������Ƶ�ļ����ſ���
	MUSICPLAY_REQ = 1648,
	MUSICPLAY_RSP = 1649,
	
	AUTHORIZATION_REQ = 1650,
	AUTHORIZATION_RSQ = 1651,


	FACE_IMAGE_CLAIM      =    2100,   //ץ��ͼƬ��������
	FACE_IMAGE_CLAIM_RSP  =    2101,   //ץ��ͼƬ����������Ӧ
	FACE_IMAGE_REQ        =    2102,   //ץ��ͼƬ��������
	FACE_IMAGE_RSP        =    2103,   //ץ��ͼƬ����������Ӧ
	FACE_IMAGE_DATA		  =	   2108,   //����ץ��ͼƬ����
	
	FACE_WBLIST_CLAIM       =        2104,   //�ڰ�������������
	FACE_WBLIST_CLAIM_RSP   =        2105,   //�ڰ���������������Ӧ
	FACE_WBLIST_REQ         =        2106,   //�ڰ�������������
	FACE_WBLIST_RSP         =        2107,   //�ڰ���������������Ӧ

	FACE_WBLIST_COMPARE_CLAIM     =  2109,    //�ڰ������ȶ���������
	FACE_WBLIST_COMPARE_CLAIM_RSP =  2110,    //�ڰ������ȶ�����������Ӧ
	FACE_WBLIST_COMPARE_REQ       =  2111,    //�ڰ������ȶ�����
	FACE_WBLIST_COMPARE_RSP       =  2112,    //�ڰ������ȶ�������Ӧ



	 FACE_JPG_WBLIST_DATA_IN		=  2122,    //�ڰ��������ݵ���,ͨ��ͼƬ���뷽ʽ
	 FACE_JPG_WBLIST_DATA_INRES		=  2123,    //������Ӧ
	 FACE_JPG_WBLIST_DATA_OUT		=  2124,    //�ڰ��������ݵ���
	 FACE_JPG_WBLIST_DATA_OUTRES	=  2125,    //������Ӧ

	 FACE_WBLIST_COMPARE_DATA		=  2128,    //�ȶԽ������

	 FACE_JPG_WBLIST_SNAP_DATA_IN  	=  2130,	//�ڰ��������ݵ��룬ͨ��ʵʱץ�ĵ���
	 FACE_JPG_WBLIST_SNAP_DATA_INRES  =  2131, 	//Զ��ץ�ĵ�����Ӧ

	 FACE_JPG_FEATURE_OUT		=	2134,	//��ȡ��������ֵ
	 FACE_JPG_FEATURE_OUT_RES	=	2135,

	 //����ʶ��
	 CAR_JPG_RESULT_CLAIM       =      2200,     //����ʶ��ͼƬ����
	 CAR_JPG_RESULT_CLAIM_RSP   =      2201,     //����ʶ��ͼƬ������Ӧ
	 CAR_JPG_RESULT_REQ         =      2202,     //����ʶ��ͼƬ��������
	 CAR_JPG_RESULT_RSP         =      2203,     //����ʶ��ͼƬ����������Ӧ
	 CAR_JPG_RESULT_DATA        =      2204,     //����ʶ����ͼƬ����
}CMSG_TYPE;

#define KeepAliveCircle 20

enum NetOprResult
{
	oprOK = 0, 	/*����ok��ʲôҲû����*/
	oprError,	/*����ʧ��*/
	oprRespData,/*����ok�����ػظ���Ϣ*/
	oprResustData,/*����ok�����ؽ��ս��*/

};

#endif //_MSGDEF_H

