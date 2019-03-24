#ifndef __LVR_NET_SDK_H__
#define __LVR_NET_SDK_H__

#ifdef __LVR_NET_EXPORT__
#define LVR_NET_API  extern "C" __declspec(dllexport)
#else
#define LVR_NET_API  extern "C" __declspec(dllimport)
#endif


#define MAX_CHANNEL_NUM							32 // ���ͨ����
#define MAX_ACCOUNT_NUM							8  // ����û�����
#define MAX_ALARMIN_NUM							32 // ��󱨾�������
#define MAX_ALARMOUT_NUM						16 // ��󱨾������
#define MAX_HARDDISK_NUM						16 // ���Ӳ����
#define MAX_DDNS_NUM							 4 //���ddns��

// Э������
#define TCP_PROTOCOL_MODE						0x00000001 // TCP
#define UDP_PROTOCOL_MODE						0x00000002 // UDP
#define MULTICAST_MODE							0x00000004 // �鲥
#define RTP_PROTOCOL_MODE						0x00000008 // RTP
#define SELECT_SUB_STREAM						0x80000000 // ������ѡ��

// �ص���������
#define	LVR_NET_IFRAME							0x1000 // ��ƵI֡
#define	LVR_NET_PFRAME							0x2000 // ��ƵP֡
#define	LVR_NET_BFRAME							0x3000 // ��ƵB֡
#define	LVR_NET_AUDIO							0x4000 // ��Ƶ֡
#define LVR_NET_VIDEOEND						0xD000 // Զ�̻ط�������Ƶ֡
#define LVR_NET_AUDIOEND						0xE000 // Զ�̻ط�������Ƶ֡

// �������
#define LVR_NET_RETURN_NO_ERROR                 0 /* û�д��� */
#define LVR_NET_ERROR_NO_PRIVI                  0x80000001 /* �޴�Ȩ�� */
#define LVR_NET_ERROR_MUST_REBOOT               0x80000002 /* ��Ҫ���� */
#define LVR_NET_ERROR_INVALID_CMD               0xFFFFFFFF /* ��Ч���� */

#define LVR_NET_OUTOF_MEMORY					0x00000001 // �����ڴ�ʧ��
#define LVR_NET_INVALID_PARAMETER				0x00000002 // �Ƿ�����
#define LVR_NET_SEND_FAIL						0x00000003 // ����ʧ��
#define LVR_NET_TRY_TIMEOUT						0x00000004 // ���Գ�ʱ
#define LVR_NET_CONNECT_FAIL					0x00000005 // ����������ʧ��
#define LVR_NET_INVALID_FILE					0x00000006 // �Ƿ��ļ�
#define LVR_NET_LINK_FAIL						0x00000007 // ���ݴ��佨��ʧ��
#define LVR_NET_WINSOCK_INIT					0x00000008 // Winsock���ʼ��ʧ��
#define LVR_NET_LOGIN_FAIL						0x00000009 // �û���¼ʧ��
#define LVR_NET_TIME_ERROR						0x0000000A // �Ƿ�ʱ�����
#define LVR_NET_LOG_NOMORE						0x0000000B // û�и�����־
#define LVR_NET_FILE_NOMORE						0x0000000C // û�и����ļ�
#define LVR_NET_DDNS_ERROR						0x0000000D // ������������
#define LVR_NET_INVALID_TIME					0x0000000E // ʱ�����
#define LVR_NET_FILE_CREATE_FAIL				0x0000000F // �ļ�����ʧ��
#define LVR_NET_VERSION_NOTMATCH				0x00000010 // ����������汾̫��
#define LVR_NET_PRECREATE_FAIL					0x00000020 // ��ƵԤ����ʧ��
#define LVR_NET_SERVER_SUSPEND					0x00000030 // ���������ڹ���״̬
#define LVR_NET_REALPLAY_SUSPEND				0x00000040 // ͨ�����ڹ���״̬
#define LVR_NET_INTERNAL_ERROR					0x00000050 // �ڲ�����
#define LVR_NET_NO_PRIVI						0x00000060 // �޴�Ȩ��


// ��̨Э������
#define PTZ_NO_EXIST							0
#define PROTOCOL_PELCO_D1						1
#define PROTOCOL_PELCO_D2						2
#define PROTOCOL_PELCO_D3						3
#define PROTOCOL_PELCO_D4						4
#define PROTOCOL_PELCO_D5						5
#define PROTOCOL_PELCO_D6						6
#define PROTOCOL_PELCO_D7						7
#define PROTOCOL_PELCO_D8						8

#define PROTOCOL_PELCO_P1						16
#define PROTOCOL_PELCO_P2						17
#define PROTOCOL_PELCO_P3						18
#define PROTOCOL_PTZ_MLP2						19
// #define PROTOCOL_PELCO_P4						12
// #define PROTOCOL_PELCO_P5						13
// #define PROTOCOL_PELCO_P6						14
// #define PROTOCOL_PELCO_P7						15
// #define PROTOCOL_PELCO_P8						16

// ��̨����
#define LVR_NET_TILT_UP							1 // ��̨����
#define LVR_NET_TILT_DOWN						2 // ��̨����
#define LVR_NET_PAN_LEFT						3 // ��̨��ת
#define LVR_NET_PAN_RIGHT						4 // ��̨��ת
#define LVR_NET_UP_LEFT							5 // ��̨����
#define LVR_NET_UP_RIGHT						6 // ��̨����
#define LVR_NET_DOWN_LEFT						7 // ��̨����
#define LVR_NET_DOWN_RIGHT						8 // ��̨����
#define LVR_NET_IRIS_SMALL						9 // ��Ȧ��С
#define LVR_NET_IRIS_BIG						10 // ��Ȧ����
#define LVR_NET_FOCUS_NEAR						11 // ����ǰ��
#define LVR_NET_FOCUS_FAR						12 // ������
#define LVR_NET_ZOOM_WIDE						13 // ������(���ʱ��)
#define LVR_NET_ZOOM_TELE						14 // �����С(���ʱ�С)
#define LVR_NET_SET_PRESET						15 // ����Ԥ�õ�
#define LVR_NET_CLR_PRESET						16 // ���Ԥ�õ�
#define LVR_NET_CALL_PRESET						17 // ����Ԥ�õ�
#define LVR_NET_AUX_ON							18 // ��ͨ�����豸����
#define LVR_NET_AUX_OFF							19 // �رո����豸����
#define LVR_NET_PRESET_ADD						20 // Ѳ�����Ԥ�õ�
#define LVR_NET_PRESET_REMOVE					21 // Ѳ���Ƴ�Ԥ�õ�
#define LVR_NET_TOUR_DELAY						22 // Ѳ��ͣ��ʱ��
#define LVR_NET_TOUR_DELETE						23 // ���Ѳ����
#define LVR_NET_TOUR_START						24 // ��ʼѲ��
#define LVR_NET_TOUR_STOP						25 // ֹͣѲ��
#define LVR_NET_PATTERN_BEGIN					26 // �켣���
#define LVR_NET_PATTERN_END						27 // �켣�յ�
#define LVR_NET_PATTERN_RUN						28 // ��ʼ�켣
#define LVR_NET_PATTERN_STOP					29 // ֹͣ�켣
#define LVR_NET_SCAN_LEFT						30 // ��߽�
#define LVR_NET_SCAN_RIGHT						31 // �ұ߽�
#define LVR_NET_SCAN_START						32 // �߽�ɨ������
#define LVR_NET_SCAN_STOP						33 // �߽�ɨ��ֹͣ
#define LVR_NET_AUTO_PAN						34 // ��̨�Զ���ת
#define LVR_NET_RESET_PAN						35 // ��̨��λ

// ��������
#define LVR_PARA_DEVICE_INFO					0x1000 // �豸����LVR_NET_DEVICE_INFO
#define LVR_PARA_DATE_TIME						0x1001 // ʱ������LVR_NET_DATE_TIME
#define LVR_PARA_ENCODE_CONFIG					0x1002 // ��������LVR_NET_ENCODE_CONFIG
#define LVR_PARA_SUB_ENCODE						0x1003 // ����������LVR_NET_SUB_ENCODE
#define LVR_PARA_BLEND_CONFIG					0x1004 // ¼�����LVR_NET_BLEND_CONFIG
#define LVR_PARA_RECORD_MODE					0x1005 // ¼��ģʽLVR_NET_RECORD_MODE
#define LVR_PARA_RECORD_SCHEDULE				0x1006 // ¼��ƻ�LVR_NET_RECORD_SCHEDULE
#define LVR_PARA_PTZ_CONFIG						0x1007 // ��̨����LVR_NET_PTZ_CONFIG
#define LVR_PARA_NETWORK_CONFIG					0x1008 // ��������LVR_NET_NETWORK_CONFIG
#define LVR_PARA_PPPOE_CONFIG					0x1009 // ��������LVR_NET_PPPOE_CONFIG
#define LVR_PARA_DDNS_CONFIG					0x100A // ��������LVR_NET_DDNS_CONFIG
#define LVR_PARA_EMAIL_CONFIG					0x100B // �ʼ�����LVR_NET_EMAIL_CONFIG
#define LVR_PARA_ALARM_CONFIG					0x100C // ��������LVR_NET_ALARM_CONFIG
#define LVR_PARA_VIDEO_LOSS						0x100D // ��Ƶ��ʧ����LVR_NET_VIDEO_LOSS
#define LVR_PARA_MOTION_DETECT					0x100E // ��������LVR_NET_MOTION_DETECT
#define LVR_PARA_VIDEO_PRIVACY					0x100F // ��˽�ڵ�LVR_NET_PRIVACY_CONFIG
#define LVR_PARA_USER_INFO						0x1010 // �û��ʺ�LVR_NET_USER_INFO
#define LVR_PARA_OUTPUT_SCHEDULE				0x1011 // ����ƻ�LVR_NET_OUTPUT_SCHEDULE
#define LVR_PARA_VIDEOFORMAT_CONFIG				0x1012 // ��Ƶ��ʽLVR_NET_VEDIO_FORMAT
#define LVR_PARA_TIME_INFO						0x1013 // ʱ������LVR_NET_TIME_CONFIG
#define LVR_PARA_PTZ_ALARM_RELATE				0x1014 // ��̨����
#define LVR_PARA_CHANNELNAME					0x1015 // ͨ����������
#define LVR_PARA_CHANNELNAMEUTF8				0x1016 // ͨ����������
#define LVR_PARA_NTP_CONFIG						0x1017 // NTP����
#define LVR_PARA_OUTPUT_CONFIG					0x1018 // �������
#define LVR_PARA_ONLINE_USERINFO_CONFIG			0x1019 // �����û�

// Զ�̿���DVR¼��ʽ
#define REMOTE_RECORD_STOP						0 // ֹͣ¼��
#define REMOTE_RECORD_MANUAL					1 // �ֶ�¼��
#define REMOTE_RECORD_AUTO						2 // �ƻ�¼��


#define NOT_RECORD           0
#define NORMAL_RECORD        1
#define MOTION_RECORD        2
#define ALARM_RECORD         4
#define MOTION_ALARM_RECORD  8

// ��Ƶ�����ʽ
#define ENCODE_FORMAT_QCIF						0 // QCIF����
#define ENCODE_FORMAT_CIF						1 // CIF����
#define ENCODE_FORMAT_HD1						3 // HALF D1����
#define ENCODE_FORMAT_D1I						6 // ����D1����
#define ENCODE_FORMAT_D1P						7 // ����D1����
#define ENCODE_FORMAT_720P						8 // HD720P
#define ENCODE_FORMAT_1080P						9 // HD1080P
#define ENCODE_FORMAT_D1						10// SYSTEMINFO�е�GlobalAbility�������GLOBAL_D1_INTERVAL�������ʾD1�����Ǹ��е�ENCODE_D1I��������ENCODE_D1P

// ¼���ļ�����
#define LVR_ALL_FILE							0xFF // ȫ���ļ�
#define LVR_NORMAL_FILE							0x00 // ��ͨ¼��
#define LVR_ALARM_FILE							0x01 // ����¼��
#define LVR_MOTION_FILE							0x02 // �ƶ����¼��

// ��־����
#define LVR_NET_LOG_ALL_LOG							0xFFFFFFFF // ȫ����־
#define LVR_NET_LOG_SYSTEM_OPERATE					0x0001 // ϵͳ����
#define LVR_NET_LOG_SYSTEM_CONFIG					0x0002 // ��������
#define LVR_NET_LOG_SYSTEM_ALARM					0x0004 // ������־	
#define LVR_NET_LOG_SYSTEM_ERROR					0x0008 // ������Ϣ
#define LVR_NET_LOG_SYSTEM_UNKNOW					0x00FF	//δ֪��־����
//��������
#define LVR_NET_LOG_OPERATE_START					0x0001 // ��ʼ
#define LVR_NET_LOG_OPERATE_STOP					0x0002 // ֹͣ
#define LVR_NET_LOG_OPERATE_WRITE					0x0003 // д��
#define LVR_NET_LOG_OPERATE_READ					0x0004 // ��ʼ
#define LVR_NET_LOG_OPERATE_UNKNOW					0x00FF // δ֪����

// LVR_NET_SYSTEM_ALARM
#define LVR_NET_LOG_ALARM_ALARM						0x0001  // ��������
#define LVR_NET_LOG_ALARM_VIDEO_LOSS				0x0002	// ��Ƶ��ʧ				
#define LVR_NET_LOG_ALARM_UNKNOW					0x00FF	// δ֪��������				

// LVR_NET_SYSTEM_OPERATE
#define LVR_NET_LOG_SYSTEM_POWERON					0x0001	// ϵͳ��ʼ  
#define LVR_NET_LOG_SYSTEM_REBOOT					0x0002	//ϵͳ����
#define LVR_NET_LOG_SYSTEM_POWEROFF					0x0003	//ϵͳ�ػ�  
#define LVR_NET_LOG_SYSTEM_UPDATE					0x0004	//ϵͳ����  
#define LVR_NET_LOG_NET_SYSTEM_UPGRADE				0x0005	//����������ʼ  
#define LVR_NET_LOG_USER_LOGIN						0x0006	//�û���¼  
#define LVR_NET_LOG_USER_LOGOUT						0x0007	//�û��ǳ�  
#define LVR_NET_LOG_HARDDISK_FORMAT					0x0008	//Ӳ�̸�ʽ��  
#define LVR_NET_LOG_CONFIG_RESTORE					0x0009	//�ָ�Ĭ�� 
#define LVR_NET_LOG_BACKUP_RECORD_FILE				0x000A	//¼�񱸷�  
#define LVR_NET_LOG_SEGMENT_RECORD_PLAY				0x000B	//¼��ط�  
#define LVR_NET_LOG_NET_FILE_DOWNLOAD				0x000C	//¼����������  
#define LVR_NET_LOG_RECORD_CONTROL					0x000D	//¼�����  
#define LVR_NET_LOG_ALARM_INPUT_CONTROL				0x000E	//��������  
#define LVR_NET_LOG_ABNORMAL_SHUTDOWN				0x000F	//�������ػ�  
#define LVR_NET_LOG_SYSTEM_OPERATE_UNKNOW			0xFF	//δ֪ϵͳ����
//LVR_NET_SYSTEM_CONFIG
#define LVR_NET_LOG_SYSTEM_DATE_TIME				0x0001	//ʱ������  
#define LVR_NET_LOG_USER_ACCOUNT					0x0002	//�û�����  
#define LVR_NET_LOG_NET_CONFIG						0x0003	//�������  
#define LVR_NET_LOG_NET_PPPOE_CONFIG				0x0004	//��������  
#define LVR_NET_LOG_NET_DDNS_CONFIG					0x0005	//DDNS����  
#define LVR_NET_LOG_NET_EMAIL_CONFIG				0x0006	//EMAIL����  
#define LVR_NET_LOG_NET_ACCESS						0x0007	//�������Ȩ��  
#define LVR_NET_LOG_VIDEO_EFFECT					0x0008	//��Ƶ����  
#define LVR_NET_LOG_RECORD_PLAN_CONFIG				0x0009	//¼��ƻ�  
#define LVR_NET_LOG_RECORD_ENCODE_CONFIG			0x000A	//�������  
#define LVR_NET_LOG_ALARM_CONFIG					0x000B	//��������  
#define LVR_NET_LOG_MOTION_DETECTION_CONFIG			0x000C	//��������  
#define LVR_NET_LOG_PTZ_CONFIG						0x000D	//��̨����  
#define LVR_NET_LOG_SYSTEM_CONFIG_UNKNOW			0xFF	//δ֪ϵͳ����

//LVR_NET_SYSTEM_ERROR
#define LVR_NET_LOG_ALARM_DISK_FULL					0x0001	//¼��Ӳ����  
#define LVR_NET_LOG_ALARM_NO_DISK					0x0002	//û��Ӳ��  
#define LVR_NET_LOG_ALARM_DISK_ERROR				0x0003	//Ӳ�̶�д����  
#define LVR_NET_LOG_SYSTEM_ERROR_UNKNOW				0xFF	//δ֪ϵͳ����

//NTP����
#define LVR_NTP_NULL							0x00
#define LVR_NTP_NIST							0x01
#define LVR_NTP_ACCN							0x02
#define LVR_NTP_CUSTOM							0x03



//DDNS����
#define LVR_NET_DOMAIN_CAN_SUBMIT						1 //������ע��
#define LVR_NET_DOMAIN_CAN_MODIFY						2 //�������޸�
#define LVR_NET_ACCOUNT_CAN_MODIFY						4//�ʺſ��޸� 
#define LVR_NET_DDNS_KEEP_ALIVE							8 //�����豣��
#define LVR_NET_POSTFIX_CAN_APPEND						16//��׺�ɸ���
#define LVR_NET_CURRENT_USED_DDNS						64 //��ǰʹ�õ�


//DDNS����
#define LVR_NET_DDNS_TYPE_NULL						0
#define LVR_NET_DDNS_3322_ORG						1
#define LVR_NET_DDNS_DYNDNS_ORG						2
#define LVR_NET_DDNS_ANYVISION_ORG					3

//NTP����������
#define LVR_NET_NTP_NULL							0
#define LVR_NET_NTP_NIST							1
#define LVR_NET_NTP_ACCN							2
#define LVR_NET_NTP_CUSTOM							3

// LvrNetSetWindowMsg��Ϣ����
#define MSG_EXP_REALPLAY_FAILED					0x1001 // ʵʱԤ����ʼ���쳣
#define MSG_EXP_RECORD_CREATE					0x1101 // ¼�񴴽��쳣
#define MSG_EXP_RECORD_CONFIG					0x1102 // ¼���ʼ���쳣
#define MSG_EXP_RECORD_STOP						0x1104 // ������ʽ�仯,¼��ֹͣ

#define MSG_EXP_SERVER_CONNECT					0x1501 // ������������ӳ����쳣
#define MSG_EXP_REALPLAY_CONNECT				0x1502 // ͨ�����ӳ����쳣
#define MSG_EXP_DATA_RECV						0x1503 // ���ݽ��ճ����쳣
#define MSG_EXP_CMD_RECV						0x1504 // ������ճ����쳣
#define MSG_EXP_PLAYBACK_RECV					0x1505 // �طŽ��ճ����쳣
#define MSG_EXP_DOWNLOAD_RECV					0x1506 // ���ؽ��ճ����쳣
#define MSG_EXP_UPGRADE_RECV					0x1507 // �������Ƚ���ʧ��
#define MSG_EXP_UPGRADE_SEND					0x1508 // �������ͳ����쳣

#define MSG_RES_SERVER_CONNECT					0x1601 // ������������ӻָ�
#define MSG_RES_REALPLAY_CONNECT				0x1602 // ͨ�����ӻָ�

#define MSG_ERR_REALPLAY_NOPRIVI				0x1701 // ��Ƶû��Ԥ��Ȩ��
#define MSG_ERR_DISCONNECT_SUCCESS				0x1702 // �ɹ��Ͽ�����
#define	MSG_ERR_DISCONNECT_ERROR				0x1703 // ���Ͽ�����ʧ��
#define MSG_ERR_BEENDISCONNECT_SUCCESS			0x1704 // ���Ͽ�����ʧ��
// �ص�����
#define LVR_COMM_ALARM							0x1000 // ������Ϣ

// Զ�̻طſ��Ʋ���
#define LVR_PLAY_START							0x4001 // ��ʼ����
#define LVR_PLAY_STOP							0x4002 // ֹͣ����
#define LVR_PLAY_PAUSE							0x4003 // ��ͣ����
#define LVR_PLAY_SET_RATE						0x4004 // ���ò����ٶ�
#define LVR_PLAY_GET_RATE						0x4005 // �õ������ٶ�
#define LVR_PLAY_FRAME							0x4006 // ��֡����
#define LVR_SET_POS								0x4007 // ���ûطŽ���
#define LVR_GET_POS								0x4008 // ��ȡ�طŽ���
#define LVR_GET_FRAMES							0x4009 // ��ȡ�Ѳ��ŵ�֡��
#define LVR_TOTAL_FRAMES						0x400A // ��ȡ�����ļ���֡��
#define LVR_GET_TIME							0x400B // ��ȡ�Ѳ��ŵ�ʱ��
#define LVR_TOTAL_TIME							0x400C // ��ȡ�����ļ���ʱ��


//�û�Ȩ��
#define	LVR_PRIVI_REC_ENCODE      0          /* �������� */
#define	LVR_PRIVI_SUB_ENCODE      1          /* ������ */
#define	LVR_PRIVI_CH_BLEND        2          /* ¼����� */
#define	LVR_PRIVI_REC_PLAN        3          /* ¼��ƻ� */
#define	LVR_PRIVI_PTZ_CONFIG      4          /* ��̨���� */
#define	LVR_PRIVI_VIDEO_CONFIG    5          /* ��Ƶ���� */
#define	LVR_PRIVI_MOTION_DETECT   6          /* �ƶ���� */
#define	LVR_PRIVI_NET_CONFIG      7          /* �������� */
#define	LVR_PRIVI_PPPOE_CONFIG    8          /* �������� */
#define	LVR_PRIVI_DDNS_CONFIG     9          /* DDNS���� */
#define	LVR_PRIVI_EMAIL_CONFIG    10         /* EMAIL���� */
#define	LVR_PRIVI_NET_ACCESS      11         /* ���ʿ��� */
#define	LVR_PRIVI_TIME_MACHINE    12         /* ʱ���� */
#define	LVR_PRIVI_DISK_MANAGE     13         /* Ӳ�̹��� */
#define	LVR_PRIVI_ALARM_CONFIG    14         /* �ⲿ���� */
#define	LVR_PRIVI_OUTPUT_PLAN     15         /* ������� */
#define	LVR_PRIVI_EXCEPTION_CONFIG 16        /* �쳣���� */
#define	LVR_PRIVI_DISPLAY_CONFIG   17        /* ������ʾ */


#define	LVR_PRIVI_RECORD_CONTROL   0          /* ¼����� */
#define	LVR_PRIVI_RECORD_BACKUP    1          /* ¼�񱸷� */
#define	LVR_PRIVI_PLAY_CONTROL     2          /* ¼��ط� */
#define	LVR_PRIVI_PTZ_CONTROL      3          /* ��̨���� */
#define	LVR_PRIVI_ALARM_CONTROL    4          /* �������� */
#define	LVR_PRIVI_ALARM_CLEAR      5          /* ������� */
#define	LVR_PRIVI_DISPLAY_ADJUST   6          /* ��ʾ���� */
#define	LVR_PRIVI_LOG_VIEW         7          /* ��־�鿴 */
#define	LVR_PRIVI_SYSTEM_UPGRADE   8          /* ϵͳ���� */
#define	LVR_PRIVI_SYSTEM_REBOOT    9          /* ����ϵͳ */
#define	LVR_PRIVI_SYSTEM_POWEROFF  10         /* �ر�ϵͳ */
#define	LVR_PRIVI_REMOTE_LOGIN     11         /* Զ�̵�¼ */
#define	LVR_PRIVI_SYSTEM_ADMIN     12         /* ϵͳ���� */
#define LVR_PRIVI_ONLINE_USER	   13		  /* �����û� */

#define	LVR_PRIVI_CHANNEL_REVIEW   0          /* ͨ��Ԥ�� */

// pDataCallBackʵʱ���ݺ�Զ���ļ��ط����ݻص�
// pBufferָ���׼������,dwDataLen���ݳ���,��ָ���벻Ҫ�ͷ�
// �����Զ�̻ط����ݻص�,dwDataTypeΪLVR_NET_AUDIOEND��LVR_NET_VIDEOEND��ʾ���Ĳ���֡
// �����Զ�̻ط������Ѿ�ȫ������ʱ,pBufferΪNULL
// dwTimeStamp������ʱ���,��ʼ�������,1000HZ/��
// ��������Ϊ��Ƶʱ,���Զ�dwDataFlagsʹ�ñ�־VIDEO_SYSTEM_MASK��ENCODE_FORMAT_MASK��ø�����Ϣ
// PAL��ʽ��Ƶ�ֱ���: CIF:352*288 HALF D1:704*288 D1:720*576
// NTSC��ʽ��Ƶ�ֱ���: CIF:352*240 HALF D1:704*240 D1:720*480
#define VIDEO_SYSTEM_MASK		0x0040 // ��Ƶ��ʽ 0:PAL 0x40:NTSC
#define ENCODE_FORMAT_MASK		0x0f00 // �����ʽ 0x0100:CIF 0x0300:HALF D1 0x0600:D1I(����D1) 0x0700:D1P(����D1)

typedef void (CALLBACK *pMessageCallBack)(LONG lvrNetHandle, LONG lCommand, CHAR *pBuf, DWORD dwBufLen);
typedef void (CALLBACK *pLvrNetPlayDraw)(LONG lvrHandle, HDC hDC, DWORD dwUser);
typedef void (CALLBACK *pDataCallBack)(LONG lvrHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwDataLen, DWORD dwTimeStamp, DWORD dwDataFlags, DWORD dwUser);
typedef void (CALLBACK *pDevScanCallBack)(CHAR* pBuf);

/* ����ʱ�� */
typedef struct  {
	DWORD dwYear;				// ��
	DWORD dwMonth;				// ��
	DWORD dwDay;				// ��
	DWORD dwHour;				// ʱ
	DWORD dwMinute;				// ��
	DWORD dwSecond;				// ��
}LVR_NET_DATE_TIME, *LPLVR_NET_DATE_TIME;

//SYSTEMINFO�е�
//GlobalAbility�������GLOBAL_D1_INTERVAL�������ʾD1�����Ǹ��е�ENCODE_D1I��������ENCODE_D1P
/* �豸��Ϣ */
typedef struct  {
	BYTE byChannelNum;			// �豸ͨ����
	BYTE byAlarmInputNum;		// ����������
	BYTE byAlarmOutputNum;		// ���������
	BYTE byAudioInputNum;		// ��Ƶ��
    BYTE byDecodeNum;           // �طŽ�����
	BYTE byNetPortNum;			// ������
    BYTE byDiskPortNum;         // Ӳ�̽ӿ���
	BYTE bySpotNum;             // SPOT�ӿ���
	BYTE byMicrophoneNum;		// ��˷�ӿ���
	BYTE bySDPortNum;			// SD�ӿ���
    BYTE byUSBPortNum;          // USB�ӿ���
    BYTE byCVBSPortNum;         // CVBS�ӿ���
    BYTE byVGAPortNum;          // VGA�ӿ���
    BYTE byHDMIPortNum;         // HDMI�ӿ���
	BYTE byRS232PortNum;		// RS232�ӿ���
	BYTE byRS485PortNum;		// RS485�ӿ���
	DWORD dwAlarmInput;			// ����֧�֣�λ��ʾ��Ӧͨ����0����֧�֣�1��֧��
    DWORD dwAlarmOutput;        // �������(λ)
	DWORD dwSubStream;			// ������֧�֣�λ��ʾ��Ӧͨ����0����֧�֣�1��֧��
	DWORD dwAudioInput;			// ��Ƶ֧�֣�λ��ʾ��Ӧͨ����0����֧�֣�1��֧��
	DWORD dwNetCameraStream;    // ���紮��(λ)
    DWORD dwLocalAbility;       // �豸�������� LOCAL_UART_PORT0 ... 
    DWORD dwGlobalAbility;      // �豸ȫ������ GLOBAL_D1_INTERVAL ... 
    WORD woMotionCellHorzNum;   // ��������ˮƽ��Ԫ�� 
    WORD woMotionCellVertNum;   // ��������ֱ��Ԫ��
	DWORD dwCIFChannel;			// CIF����֧�֣�λ��ʾ��Ӧͨ����0����֧�֣�1��֧��
	DWORD dwHalfD1Channel;		// Half D1����֧�֣�λ��ʾ��Ӧͨ����0����֧�֣�1��֧��
	DWORD dwFullD1Channel;		// Full D1����֧�֣�λ��ʾ��Ӧͨ����0����֧�֣�1��֧��
	DWORD dwHD720PChannel;		// HD 720P����֧�֣�λ��ʾ��Ӧͨ����0����֧�֣�1��֧��
	DWORD dwHD1080PChannel;		// HD 1080P����֧�֣�λ��ʾ��Ӧͨ����0����֧�֣�1��֧��
    WORD byEncodeFrames[2];     // ��������(��CIF����) 0 NTSC 1 PAL
	BYTE byCIFFrameRate[2];		// CIF����֡��,�ֱ��ӦNTSC�ƺ�PAL���µ����֡��
	BYTE byHalfD1FrameRate[2];	// Half D1����֡��,�ֱ��ӦNTSC�ƺ�PAL���µ����֡��
	BYTE byFullD1FrameRate[2];	// Full D1����֡��,�ֱ��ӦNTSC�ƺ�PAL���µ����֡��
	BYTE byHD720PFrameRate;		// HD 720P����֡��
	BYTE byHD1080PFrameRate;	// HD 1080P����֡��
	LVR_NET_DATE_TIME IssueDate;// ����ʱ��
	WORD woLvrMajorVersion;		// ����汾��
    WORD woLvrMinorVersion;     // GUI�汾��
    WORD woMobileVersion;       // �ֻ��汾��
    WORD woMCUVersion;          // MCU�汾��
	WORD woHardwareVersion;	    // Ӳ���汾��
    WORD woFactoryCode;           // ���̴���
    BYTE bySerialNumber[16];              /* ���к� */
//    BYTE byReserve[48];          // ����
//���¶���������3�汾���Ժ����Ч
	BYTE byConfigPrivi[32];     // ����Ȩ�� PRIVI_REC_ENCODE ~ PRIVI_DISPLAY_CONFIG
    BYTE byControlPrivi[32];    // ����Ȩ�� PRIVI_RECORD_CONTROL ~ PRIVI_SYSTEM_ADMIN
	BYTE byLiveviewPrivi[32];	// ʵʱԤ����ÿһλ����һ��ͨ����0Ϊ�رգ�1Ϊ��
	BYTE byRecordPrivi[32];		// ¼��ÿһλ����һ��ͨ����0Ϊ�رգ�1Ϊ�� 
	BYTE byPlaybackPrivi[32];	// ¼��طţ�ÿһλ����һ��ͨ����0Ϊ�رգ�1Ϊ�� 
	BYTE byRemoteViewPrivi[32];	// Զ��Ԥ����ÿһλ����һ��ͨ����0Ϊ�رգ�1Ϊ��
}LVR_NET_DEVICE_INFO, *LPLVR_NET_DEVICE_INFO;

/* ��Ƶ��ʽ */
typedef struct  {
	DWORD dwVedioFormat;		// 0:NTSC 1:PAL
}LVR_NET_VEDIO_FORMAT, *LPLVR_NET_VEDIO_FORMAT;

/* ʱ���ʽ */
typedef struct  {	
	BYTE byDateMode;			// ������ʾ��ʽ 0:������, 1:������, 2:������
	BYTE byTimeMode;			// ʱ���ʽ 0:12Сʱ��, 1:24Сʱ��
//	BYTE byTimeZone;			// ʱ��
	BYTE byDayLight;			// ����ʱ
}LVR_NET_TIME_CONFIG, *LPLVR_NET_TIME_CONFIG;

typedef struct {
    BYTE byNtpType;							// NTP���� NTP_NULL ~ NTP_CUSTOM
    BYTE byTimeZone;						// ʱ��
    WORD woUpdatePeriods;					// ��������(����)
    CHAR chNtpServer[32];		// �Զ���NTP������
    WORD byNtpPort;							// �Զ���NTP�������˿�
	BYTE byReserve[2];
} LVR_NET_NTP_CONFIG, *LPLVR_NET_PNTP_CONFIG;

/* ������� */
typedef struct  {
	BYTE byEncodeFormat;		// �����ʽ ENCODE_FORMAT_CIF~ENCODE_FORMAT_D1P���μ�LVR_NET_DEVICE_INFO֧�ֵı����ʽ
	BYTE byBitrateMode;			// �������� 0 : VBR, 1 : CBR
	BYTE byEncodeQuality;		// �������� 0~5,0����5�����
	BYTE byFramesRate;			// ֡�ʣ�0�����֡�ʣ��μ�LVR_NET_DEVICE_INFO��Ӧ�����ʽ��֡�ʷ�Χ
	BYTE byEncodeAudio;			// ��Ƶ���룬�μ�LVR_NET_DEVICE_INFO֧�ֵ���Ƶͨ��
	BYTE byAlarmPreRec;			// ����Ԥ¼��
	BYTE byDigitalWatermark;	// ����ˮӡ 0 �ر�; 1 �� */
	BYTE Reserve[5];			// ����
}LVR_NET_ENCODE_CONFIG, *LPLVR_NET_ENCODE_CONFIG;

/* ���������� */
typedef struct {
	BYTE byEncodeFormat;		// �����ʽ ENCODE_FORMAT_CIF
	BYTE byEncodeQuality;		// �������� 0~5, 0����5�����
	BYTE byEncodeFrames;		// ֡�� 0~5, 0:Ĭ��֡��
	BYTE Reserve[5];				// ����
}LVR_NET_SUB_ENCODE, *LPLVR_NET_SUB_ENCODE;

typedef struct {
	CHAR  ChName[32];      /* ͨ���� */
}LVR_NET_CHANNEL_NAME, *LPLVR_NET_CHANNEL_NAME;


/* ����λ�� */
typedef struct  {
	BYTE byTitlePostion;		// ͨ��������λ�� 0:���ϣ� 1���� 2�����£� 3���ϣ� 4���У� 5���£� 6�����ϣ� 7���ң� 8������
	BYTE byTimePostion;			// ʱ�����λ��  0:���ϣ� 1���� 2�����£� 3���ϣ� 4���У� 5���£� 6�����ϣ� 7���ң� 8������
	BYTE byLiveTitlePos;			// ͨ��������ʹ��
	BYTE byLiveTimePos;			// ʱ�����ʹ��
	BYTE  byReserve[4];
}LVR_NET_BLEND_CONFIG, *LPLVR_NET_BLEND_CONFIG;


typedef struct  {
	BYTE byRecordMode[32];                    /* ¼��ģʽ 0 �ֶ�; 1 �ƻ� */
    BYTE byStartRecord[32];                   /* ¼����� 0 ֹͣ; 1 ���� */
}LVR_NET_RECORD_CONTROL ,*LPLVR_NET_RECORD_CONTROL;


/* ¼��ʽ */
typedef struct  {
	WORD woRecordCover;			// ¼�񸲸Ƿ�ʽ 0 - ѭ�����ǣ�1 - Ӳ����ʱֹͣ¼��
	WORD woRecordTime;			// ¼����ʱ��(���120����)
}LVR_NET_RECORD_MODE, *LPLVR_NET_RECORD_MODE;


/* ¼��ƻ�(һ��7��*24Сʱ) */
typedef struct  {
	BYTE lvrRecordSchedule[7][24]; // 0 ��¼��; 1 ��ʱ¼��; 4 ���춨ʱ¼��; 8 ������ʱ¼��; 16 ����ͱ�����ʱ¼��
}LVR_NET_RECORD_SCHEDULE, *LPLVR_NET_RECORD_SCHEDULE;

/* ͨѶ���� */
typedef struct  {
	BYTE woBitRate;				// ����(bps) 0 - 1200, 1 - 2400, 2 - 4800, 3 - 9600, 4 - 19200, 5 - 38400, 6 - 57600, 7 - 115200
	BYTE byDateBit;				// ����λ DATABIT_4 ~ DATABIT_8
	BYTE byStartBit;			// ��ʼλ ��ʼλ 1
	BYTE byStopBit;				// ֹͣλ STOPBIT_1 ~ STOPBIT_2 
	BYTE byDataCheck;			//����У�� CHECK_NULL ~ CHECK_SPACE */
	BYTE byDataControl;			// ���� 0
	BYTE byReceive[2];				// ����
}LVR_NET_SERIAL_CONFIG, *LPLVR_NET_SERIAL_CONFIG;

/* ��̨���� */
typedef struct  {
	LVR_NET_SERIAL_CONFIG lvrSerial;	// ͨѶ����
	WORD byDevType;						// �豸���� 0 - ��, 1 - PelcoD1, 2 - PelcoD2, 2 - PelcoD3,
	WORD byDevAddress;					// �豸��ַ 0 ~ 255
}LVR_NET_PTZ_CONFIG, *LPLVR_NET_PTZ_CONFIG;


/* ������� */
typedef struct {
    BYTE  byBeepOutputPlan[24];                /* ������ */
    BYTE  byEmailSendPlan[24];                 /* Email���� */
    BYTE  byAlarmOutputPlan[24];               /* ������� */
    BYTE  byReserve[24];
} LVR_NET_OUTPUTPLAN, *LPLVR_NET_OUTPUTPLAN;

/* ������� */
typedef struct  {
	BOOL bEnableUPnP;			// UPnP֧��
	BOOL bEnableDHCP;			// DHCP֧��
	CHAR sEthernetIP[16];		// IP��ַ
	CHAR sEthernetIPMask[16];	// ��������
	CHAR sGatewayIP[16];		// ���ص�ַ
	CHAR sDNSIP[16];			// DNS��ַ
	WORD woServerPort;			// �������˿�
	WORD woHttpPort;			// HTTP�˿�
	WORD woMobilePort;			// �ֻ����ʶ˿�
	BYTE byMacAdderss[6];		// MAC��ַ(ֻ��)
}LVR_NET_NETWORK_CONFIG, *LPLVR_NET_NETWORK_CONFIG;

typedef struct  {
	CHAR PPPoEUser[32];			// PPPOE�û���
    CHAR PPPoEPassword[32];		// PPPOE����
    CHAR sPPPoEIP[16];			// PPPoE IP��ַ(ֻ��)
    BOOL bStartup;				// �Զ�����PPPOE
    BOOL bLinkState;			// PPPoE����״̬
}LVR_NET_PPPOE_CONFIG, *LPLVR_NET_PPPOE_CONFIG;


typedef struct  {
	BOOL bSSLEnable;			// SSL��¼
    BOOL bAlarmNotify;			// ��������֪ͨ �����汾3����û�д��ֶ�
    BOOL bVideoLossNotify;		// ������Ƶ��ʧ֪ͨ  �����汾3����û�д��ֶ�
    CHAR RecverEmail1[64];		// ���շ���ַ
    CHAR RecverEmail2[64];		// ���շ���ַ
    CHAR SMTPServer[64];		// SMTP������
    CHAR SenderEmail[64];		// �����ߵ�ַ
    CHAR SenderUser[32];		// �û���
    CHAR SenderPassword[32];	// ����
//���������������汾3�����ϲ���Ч
	UINT nSmtpPort;				// SMTP�˿� δ����SSL��SMTPĬ�϶˿�Ϊ25������SSL��SMTPĬ�϶˿�Ϊ485
}LVR_NET_EMAIL_CONFIG, *LPLVR_NET_EMAIL_CONFIG;

typedef struct {
	DWORD  		byDevType;        		/* �豸����*/
	DWORD		dwDevIP;				/* �豸IP��ַ*/
    WORD		dwDevPort;				/* �豸�˿ں�*/
	WORD  		byDevChannelsNum;		/* �豸ͨ���� */
	DWORD 		woDevSwVersion;			/* LVR�汾�� */
	DWORD 		woDevHwVersion;			/* Ӳ���汾�� */
	CHAR		chDevName[32];			/* �豸���� */
	BYTE  		byDevSerialNumber[16];  /* ���к� */
	BYTE  		byDevMacAddr[6];		/*  MAC��ַ */
   	BYTE  		byReserve[30];
}LVR_NET_DEVSCAN, *LPLVR_NET_DEVSCAN;

/* DDNS���� */
typedef struct {
    WORD	 woDDNSFlags;                     /* DDNS���� DOMAIN_CAN_SUBMIT ~ POSTFIX_CAN_APPEND */
    WORD	 woDDNSType;                      /* DDNS���� */
    CHAR     DDNSName[32];					  /* DDNS���� */
    CHAR     DDNSDomainName[64];			  /* DDNS���� */
    CHAR     DDNSUser[32];					  /* DDNS�û��� */
    CHAR     DDNSPassword[32];				  /* DDNS���� */
    BYTE	 byCurrentState;                  /* ״̬ 0 δʹ��; 1 ʹ�� */
    BYTE	 byKeepAliveTime;                 /* ����ʱ��(����) */
    BYTE	 byMinKeepAlive;                  /* �������ʱ�� */
    BYTE	 byMaxKeepAlive;                  /* �����ʱ�� */
	BYTE	 byReserve[21];
} LVR_NET_DDNS_DATA, *LPLVR_NET_DDNS_DATA;

typedef struct {
  LVR_NET_DDNS_DATA lvrDDNS[MAX_DDNS_NUM];
} LVR_NET_DDNS_CONFIG, *LPLVR_NET_DDNS_CONFIG;

typedef struct  {
	BYTE byAlarmType;					// �������� 0:����(N/O), 1:����(N/C)
	WORD woDelayTime;					// �����Զ����(0 ~ 255��,0:�����)
	WORD woAlarmUpload;					// �����ϴ� 
	BOOL bAlarmBeep;					// ����������
	BYTE byRecChannel[MAX_CHANNEL_NUM];	// ����¼��ͨ��
	BYTE byAlarmOut[MAX_ALARMOUT_NUM];	// �������ͨ��
// �������������汾3�����ϲ���Ч
	BOOL bAlarmSendMail;
}LVR_NET_ALARM_CONFIG, *LPLVR_NET_ALARM_CONFIG;


/* �������� */
typedef struct {
    BYTE byRelatePtzType;      /* �������� RELATE_NULL ~ RELATE_PATTERN */
    BYTE byRelatePtzNum;      /* �������� */
    BYTE byReserve[2];
} LVR_NET_ALARMPTZRELATEDATA, *LPLVR_NET_ALARMPTZRELATEDATA;

typedef struct {
	LVR_NET_ALARMPTZRELATEDATA alarmPTZRelate[MAX_CHANNEL_NUM];
} LVR_NET_ALARMPTZRELATE, *LPLVR_NET_ALARMPTZRELATE;


typedef struct  {
	BOOL bLossBeep;						// ����������
	BYTE byAlarmOut[MAX_ALARMOUT_NUM];	// �������ͨ�� 0:�������1�����
// �������������汾3�����ϲ���Ч
	BOOL bVideoLossSendMail;            // �ʼ�����
}LVR_NET_VIDEO_LOSS, *LPLVR_NET_VIDEO_LOSS;

typedef struct  {
	BOOL bMotionBeep;					// ����������
	WORD woSensitive;					// ������ 0~4,0 - �����, 4 - ������
	BYTE byHorzCell;					// ��������ˮƽ����,32
	BYTE byVertCell;					// ��������ֱ���������24
//	BYTE byDetectArea[24][32];			// ������������
	BYTE byDetectArea[32][24];			// ������������
	BYTE byRecChannel[MAX_CHANNEL_NUM];	// ����¼��ͨ��
	BYTE byAlarmOut[MAX_ALARMOUT_NUM];	// �������ͨ��
// �������������汾3�����ϲ���Ч
	BOOL bMotionSendMail;               // �ʼ����� 
}LVR_NET_MOTION_DETECT, *LPLVR_NET_MOTION_DETECT;


typedef struct  {
//	DWORD dwPrivacyMode;				// ģʽ 0�������ã�1������
	BYTE byEncEnable;                   // �������
    BYTE byLiveEnable;                  // Ԥ������
	WORD woPrivacyPosX;					// ������ʼx����
	WORD woPrivacyPosY;					// ������ʼy����
	WORD woPrivacyWidth;				// ������
	WORD woPrivacyHeight;				// ����߶�
	BYTE Reserve[2];
}LVR_NET_PRIVACY_CONFIG, *LPLVR_NET_PRIVACY_CONFIG;

#define MAX_ONLINE_USER						20
enum{
	DVR_CONNECT_PC,
	DVR_CONNECT_MOBILE
};

/* �����û� �����汾3�����ϲ��д˹��� */
typedef struct{
	CHAR     sUserName[8];		//����
	CHAR	 sUserIP[16];			            //IP��ַ
	UINT	 nUserConnectType;                  //���ӷ�ʽ
	BOOL	 bKillConnect;						//�Ͽ�����
} ONLINE_USER, *PONLINE_USER;

typedef struct  {
	DWORD dwUserNum;						// �û���
	ONLINE_USER lvrUser[MAX_ONLINE_USER];	// �û��б�
}LVR_NET_ONLINE_USER, *LPLVR_NET_ONLINE_USER;
/* �ʺ���Ϣ */
typedef struct  {
	CHAR sUserName[8];						// �û���,���8λ,����8λʱ��0��β
	CHAR sPassword[8];						// ����,���8λ,����8λʱ��0��β
	BYTE byChannelPrivi[32];				// ͨ��Ȩ�� 0 �ر�; 1 �� �����汾3��������Ч
	BYTE byConfigPrivi[32];					// ��������Ȩ��
	BYTE byControlPrivi[32];				// ����Ȩ��
// �������������汾3�����ϲ���Ч
	BYTE byLiveviewPrivi[32];				// ʵʱԤ����ÿһλ����һ��ͨ����0Ϊ�رգ�1Ϊ��
	BYTE byRecordPrivi[32];					// ¼��ÿһλ����һ��ͨ����0Ϊ�رգ�1Ϊ�� 
	BYTE byPlaybackPrivi[32];				// ¼��طţ�ÿһλ����һ��ͨ����0Ϊ�رգ�1Ϊ�� 
	BYTE byRemoteViewPrivi[32];				// Զ��Ԥ����ÿһλ����һ��ͨ����0Ϊ�رգ�1Ϊ��
}LVR_NET_USER_ACCOUNT, *LPLVR_NET_USER_ACCOUNT;

typedef struct  {
	DWORD dwUserNum;								// �û���
	LVR_NET_USER_ACCOUNT lvrUser[MAX_ACCOUNT_NUM];	// �û��б�
}LVR_NET_USER_INFO, *LPLVR_NET_USER_INFO;

/* �û����� */
typedef struct{
	CHAR sUserName[8];			// �û���(��ĸ������)
	CHAR sOldPassword[8];		// ������(��ĸ������)
	CHAR sNewPassword[8];		// ������(��ĸ������)
}LVR_NET_CHANGE_PASSWORD, *PLVR_NET_CHANGE_PASSWORD;

typedef struct  {
	BYTE  byVideoLoss;			// ��Ƶ��ʧ
	BYTE  byVideoCover;			// ��Ƶ�ڵ�
	BYTE  byMotionDetect;		// ��̬���
	BYTE  byChRecord;			// ͨ��¼��
	DWORD dwEncodeBitRate;		// ��������
}LVR_NET_CHANNEL_INFO, LPLVR_NET_CHANNEL_INFO;

typedef struct  {
	DWORD dwDiskState;			// Ӳ��״̬ 0 - ����, 1 - ����, 2 - δ��ʽ��, 3 - ��д����
	DWORD dwDiskCapacity;		// ������(MB)
	DWORD dwFreeSpace;			// ��������(MB)
}LVR_NET_HARDDISK_INFO, LPLVR_NET_HARDDISK_INFO;

/* ����״̬ */
typedef struct  {
	LVR_NET_CHANNEL_INFO lvrChannel[MAX_CHANNEL_NUM];	// ͨ��״̬
	LVR_NET_HARDDISK_INFO lvrDisk[MAX_HARDDISK_NUM];	// Ӳ��״̬
	BYTE byAlarmInput[MAX_ALARMIN_NUM];					// ��������״̬ 0: �ޣ�1��������2��������3������
	BYTE byAlarmOutput[MAX_ALARMOUT_NUM];				// �������״̬ 0: �ޣ�1���������2�����
}LVR_NET_WORKING_STATE, *LPLVR_NET_WORKING_STATE;

/* ������Ϣ */
typedef struct {
	WORD woAlarmType; // ���� 1 ��Ƶ��ʧ 2 ���� 3 ��Ƶ�ڵ� 4 �ⲿ���� 5 ������� 6 ��Ӳ�� 7 Ӳ��δ��ʽ�� 8 Ӳ���� 9 Ӳ�̴���
	WORD woAlarmState; // ״̬ 0 ֹͣ 1 ����
	BYTE byChannel[MAX_CHANNEL_NUM];		// ͨ��״̬ 0:������1������
	BYTE byAlarmInput[MAX_ALARMIN_NUM];		// ��������״̬ 0:������1������
	BYTE byAlarmOutput[MAX_ALARMOUT_NUM];	// �������״̬ 0:�رգ�1������
	BYTE byDiskState[MAX_HARDDISK_NUM];		// Ӳ��״̬
}LVR_NET_ALARM_STATE, *LPLVR_NET_ALARM_STATE;

typedef struct  {
	LONG  lChannel;				// ���ͨ����
	DWORD dwLinkMode;			// ͨ��Э��,��־SELECT_SUB_STREAM��������
	HWND  hPlayWnd;				// ��ʾ���ھ��,ΪNULLʱ����ʾ
}LVR_NET_PREVIEW, *LPLVR_NET_PREVIEW;

typedef struct  {
	float fAlpha;				// ͸���� 0.0 ~ 1.0
	DWORD dwUser;				// �û��Զ���������
	COLORREF crMask;			// ͸����ɫ
	pLvrNetPlayDraw pPlayDraw;	// ����ָ��
}LVR_NET_MIXER, *LPLVR_NET_MIXER;


typedef struct  {
	WORD woType;				// ��־����
	WORD woOperate;				// ��������
	DWORD dwLogCommond;			// ��������
	LVR_NET_DATE_TIME logTime;	// ��־ʱ��
	CHAR logString[32];			// ��־��Ϣ
}LVR_NET_LOG, *LPLVR_NET_LOG;

typedef struct {
	CHAR sFileName[32];			// �ļ���
	DWORD dwFileSize;			// �ļ���С
	LVR_NET_DATE_TIME startTime;	// �ļ��Ŀ�ʼʱ��
	LVR_NET_DATE_TIME stopTime;		// �ļ��Ľ���ʱ��
}LVR_NET_FILE, *LPLVR_NET_FILE;

/* ������� */
typedef struct {
	BYTE byBeeperOutput[24];	// ���������
	BYTE byEmailSend[24];		// �ʼ�����
	BYTE byAlarmOutput[24];		// �������
}LVR_NET_OUTPUT_SCHEDULE, *LPLVR_NET_OUTPUT_SCHEDULE;

/* �������� */
typedef struct  {
	BYTE byInState[MAX_ALARMIN_NUM];		// 0: ����, 1: ����
}LVR_NET_ALARM_INPUT, *LPLVR_NET_ALARM_INPUT;

/* ������� */
typedef struct  {
	BYTE byOutState[MAX_ALARMOUT_NUM];		// 0: �ر�, 1: ��
}LVR_NET_ALARM_OUTPUT, *LPLVR_NET_ALARM_OUTPUT;

LVR_NET_API BOOL __stdcall LvrNetStartup(void);
LVR_NET_API void __stdcall LvrNetCleanup(void);

LVR_NET_API BOOL __stdcall LvrNetCheckEnv(void);
LVR_NET_API DWORD __stdcall LvrNetGetLastError(void);

LVR_NET_API BOOL __stdcall LvrNetConnectTimes(DWORD dwWaitTime, DWORD dwTryTimes);
LVR_NET_API BOOL __stdcall LvrNetSetWindowMsg(HWND hWnd, UINT nMsg);
LVR_NET_API BOOL __stdcall LvrNetSetCallback(pMessageCallBack pUserCallback);

LVR_NET_API BOOL __stdcall LvrNetGetIPByDDNS(CHAR *sDDNS, WORD woDDNSPort, CHAR *sDomainName, WORD woDomainNameLen, CHAR *sGetIP);
LVR_NET_API LONG __stdcall LvrNetLogin(CHAR *sServerIP, WORD woServerPort, CHAR *sUserName, CHAR *sUserPassword, LPLVR_NET_DEVICE_INFO pDeviceInfo);
LVR_NET_API BOOL __stdcall LvrNetLogout(LONG lvrNetHandle, BOOL ActiveDisconnect);

LVR_NET_API BOOL __stdcall LvrNetSetConfig(LONG lvrNetHandle, DWORD dwCommand, LONG lChannel, LPVOID pSetBuffer, DWORD dwBufferSize);
LVR_NET_API BOOL __stdcall LvrNetGetConfig(LONG lvrNetHandle, DWORD dwCommand, LONG lChannel, LPVOID pGetBuffer, DWORD dwBufferSize, LPDWORD pBytesReturned);

LVR_NET_API BOOL __stdcall LvrNetGenKeyFrame(LONG lvrNetHandle, LONG lChannel);
LVR_NET_API BOOL __stdcall LvrNetGenSubKeyFrame(LONG lvrNetHandle, LONG lChannel);

LVR_NET_API LONG __stdcall LvrNetRealPlay(LONG lvrNetHandle, LPLVR_NET_PREVIEW lvrPreview);
LVR_NET_API BOOL __stdcall LvrNetRealDataCallBack(LONG lvrRealHandle, pDataCallBack pUserCallback, DWORD dwUser);
LVR_NET_API BOOL __stdcall LvrNetStopRealPlay(LONG lvrRealHandle);

LVR_NET_API BOOL __stdcall LvrNetSetPlayBuffer(LONG lvrRealHandle, DWORD dwBufferNum);

LVR_NET_API BOOL __stdcall LvrNetOpenSound(LONG lvrHandle);
LVR_NET_API BOOL __stdcall LvrNetCloseSound(LONG lvrHandle);

LVR_NET_API LONG __stdcall LvrNetStartVoiceCom(LONG lvrNetHandle);
LVR_NET_API BOOL __stdcall LvrNetStopVoiceCom(LONG lVoiceComHandle);
LVR_NET_API BOOL __stdcall LvrNetSetVoiceComClientVolume(LONG lVoiceComHandle, LONG lVolume);

LVR_NET_API BOOL __stdcall LvrNetSetVolume(LONG lvrHandle, LONG lBalance, LONG lVolume);
LVR_NET_API BOOL __stdcall LvrNetGetVolume(LONG lvrHandle, LONG *pBalance, LONG *pVolume);

LVR_NET_API	BOOL __stdcall LvrNetPlayMixer(LONG lvrHandle, LPLVR_NET_MIXER lvrMixer);
LVR_NET_API	BOOL __stdcall LvrNetCaptureImage(LONG lvrHandle, CHAR *pImageFile);

LVR_NET_API BOOL __stdcall LvrNetStartSave(LONG lvrRealHandle, CHAR *pFileName);
LVR_NET_API BOOL __stdcall LvrNetStopSave(LONG lvrRealHandle);

LVR_NET_API BOOL __stdcall LvrNetGetDVRWorkState(LONG lvrNetHandle, LPLVR_NET_WORKING_STATE pState);
LVR_NET_API BOOL __stdcall LvrNetRemoteFormatDisk(LONG lvrNetHandle, LONG lDiskNumber);

LVR_NET_API BOOL __stdcall LvrNetGetOnlineUserInfo(LONG lvrNetHandle, LPLVR_NET_ONLINE_USER pGetInfo);
LVR_NET_API BOOL __stdcall LvrNetDisconnectOnlineUser(LONG lvrNetHandle, LPLVR_NET_ONLINE_USER pGetInfo);

LVR_NET_API BOOL __stdcall LvrNetSetAlarmInput(LONG lvrNetHandle, LPLVR_NET_ALARM_INPUT pInput);
LVR_NET_API BOOL __stdcall LvrNetGetAlarmInput(LONG lvrNetHandle, LPLVR_NET_ALARM_INPUT pInput);

LVR_NET_API BOOL __stdcall LvrNetSetAlarmOutput(LONG lvrNetHandle, LPLVR_NET_ALARM_OUTPUT pOutput);
LVR_NET_API BOOL __stdcall LvrNetGetAlarmOutput(LONG lvrNetHandle, LPLVR_NET_ALARM_OUTPUT pOutput);

LVR_NET_API BOOL __stdcall LvrNetSetRecordControl(LONG lvrNetHandle, LPLVR_NET_RECORD_CONTROL pInPut);
LVR_NET_API BOOL __stdcall LvrNetGetRecordControl(LONG lvrNetHandle, LPLVR_NET_RECORD_CONTROL pOutPut);

LVR_NET_API BOOL __stdcall LvrNetSetVideoEffect(LONG lvrRealHandle, DWORD dwBrightness, DWORD dwContrast, DWORD dwSaturation, DWORD dwHue);
LVR_NET_API BOOL __stdcall LvrNetGetVideoEffect(LONG lvrRealHandle, DWORD *pBrightness, DWORD *pContrast, DWORD *pSaturation, DWORD *pHue);

LVR_NET_API BOOL __stdcall LvrNetRemoteKeyControl(LONG lvrNetHandle, LONG lKeyValue);
LVR_NET_API BOOL __stdcall LvrNetRemoteRecControl(LONG lvrNetHandle, LONG lChannel, LONG lRecordType);

LVR_NET_API BOOL __stdcall LvrNetRealPTZControl(LONG lvrRealHandle, DWORD dwCommand, BOOL bStop);
LVR_NET_API BOOL __stdcall LvrNetRealPTZControlWithSpeed(LONG lvrRealHandle, DWORD dwCommand, BOOL bStop, DWORD dwSpeed);
LVR_NET_API BOOL __stdcall LvrNetRealPTZPreset(LONG lvrRealHandle, DWORD dwCommand, DWORD dwPresetNumber);
LVR_NET_API BOOL __stdcall LvrNetRealPTZTrack(LONG lvrRealHandle, DWORD dwCommand);

LVR_NET_API BOOL __stdcall LvrNetPTZControl(LONG lvrNetHandle, LONG lChannel, DWORD dwCommand, BOOL bStop);
LVR_NET_API BOOL __stdcall LvrNetPTZControlWithSpeed(LONG lvrNetHandle, LONG lChannel, DWORD dwCommand, BOOL bStop, DWORD dwSpeed);
LVR_NET_API BOOL __stdcall LvrNetPTZPreset(LONG lvrNetHandle, LONG lChannel, DWORD dwCommand, DWORD dwPresetNumber);
LVR_NET_API BOOL __stdcall LvrNetPTZTrack(LONG lvrNetHandle, LONG lChannel, DWORD dwCommand);

LVR_NET_API LONG __stdcall LvrNetFindFile(LONG lvrNetHandle, LONG lChannel, DWORD dwFileType, BOOL bPlayback, LPLVR_NET_DATE_TIME pStart, LPLVR_NET_DATE_TIME pStop);
LVR_NET_API BOOL __stdcall LvrNetFindNextFile(LONG lvrFileHandle, LPLVR_NET_FILE pLvrFile);
LVR_NET_API BOOL __stdcall LvrNetFindFileClose(LONG lvrFileHandle);

LVR_NET_API LONG __stdcall LvrNetPlayByFile(LONG lvrNetHandle, CHAR *pFile, HWND hPlayWnd);
LVR_NET_API BOOL __stdcall LvrNetPlayControl(LONG lvrPlayHandle, DWORD dwCommand, LPARAM lParam);
LVR_NET_API BOOL __stdcall LvrNetPlayDataCallBack(LONG lvrPlayHandle, pDataCallBack pUserCallback, DWORD dwUser);
LVR_NET_API BOOL __stdcall LvrNetPlayClose(LONG lvrPlayHandle);

LVR_NET_API LONG __stdcall LvrNetStreamDataPlay(HWND hPlayWnd, DWORD dwReserve);
LVR_NET_API BOOL __stdcall LvrNetStreamDataInput(LONG lvrStreamHandle, BYTE *pBuffer, DWORD dwDataLen, DWORD dwTimeStamp, DWORD dwDataFlags);
LVR_NET_API BOOL __stdcall LvrNetStreamPlayClose(LONG lvrStreamHandle);

LVR_NET_API LONG __stdcall LvrNetGetFileByName(LONG lvrNetHandle, CHAR *pGetFile, CHAR *pSaveFile);
LVR_NET_API BOOL __stdcall LvrNetStopGetFile(LONG lvrGetHandle);
LVR_NET_API LONG __stdcall LvrNetGetFilePos(LONG lvrGetHandle);

LVR_NET_API LONG __stdcall LvrNetFindLog(LONG lvrNetHandle, DWORD dwLogType, LPLVR_NET_DATE_TIME pStart, LPLVR_NET_DATE_TIME pStop);
LVR_NET_API BOOL __stdcall LvrNetFindNextLog(LONG lvrLogHandle, LPLVR_NET_LOG pLvrLog);
LVR_NET_API BOOL __stdcall LvrNetFindLogClose(LONG lvrLogHandle);

LVR_NET_API LONG __stdcall LvrNetUpgrade(LONG lvrNetHandle, CHAR *pFileName);
LVR_NET_API LONG __stdcall LvrNetGetUpgradeState(LONG lvrUpgradeHandle, LONG *pComplete);
LVR_NET_API BOOL __stdcall LvrNetStopUpgrade(LONG lvrUpgradeHandle);

LVR_NET_API BOOL __stdcall LvrNetPlaySwitch(LONG lvrNetHandle, DWORD LiveCh, DWORD PlayCh);

LVR_NET_API BOOL __stdcall LvrNetRebootDevice(LONG lvrNetHandle);
LVR_NET_API BOOL __stdcall LvrNetShutdownDevice(LONG lvrNetHandle);

LVR_NET_API BOOL __stdcall LvrNetStartScanDevice(pDevScanCallBack pUserCallback);
LVR_NET_API BOOL __stdcall LvrNetStopScanDevice(void);

LVR_NET_API DWORD __stdcall LvrNetGetSdkVersion(void);

#endif // #ifndef __LVR_NET_SDK_H__
