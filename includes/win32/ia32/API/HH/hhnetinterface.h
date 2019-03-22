/******************************************************************************
* ϵͳ���ƣ�HHNetClient
* �ļ����ƣ�HHNetInterface.h
* �汾    ��V6.0.1
* ˵��	  ������ģ��,�ṩ�ͱ������������������ӿ�,���ü������豸
			���ļ����������֣�һ���궨�壻����ö�����Ͷ��壻�����ص��������ġ��ӿڽṹ���Ͷ��壻�塢�����ӿڶ��壻����������Ƶ��������������Ϣ�ṹ
* ��    ��: 2005��10��10��
  �������:	2008��09��10��			���ӷ����������ӷ�ʽ֧��
            2009��03��09��			���ӽṹALARM_MSG_NOTIFY_NEW
			2009��04��01��			�޸ĽṹHH_TALK_INFO
			2009��04��15��			���ӽṹWF_AUTH_TYPE
* ����˵��: ��
******************************************************************************/
#ifndef  HH_NET_INTERFACE_H_
#define  HH_NET_INTERFACE_H_
 
#ifdef __cplusplus
extern "C" {
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef HHNET_CLIET_INTERFACE
#define HHNET_API __declspec(dllexport)
#else
#define HHNET_API __declspec(dllimport)
#endif

/*****************************************************************************/
/*********************************  һ���궨��  ******************************/
/*****************************************************************************/

//1��ϵͳ����
#define MAX_VIDEO_NUM			4	//������Ƶ���������ͨ����
#define MAX_AUDIO_NUM			4	//������Ƶ��������Ƶ���ͨ����
#define MAX_SENSOR_NUM			4	//̽ͷ�������·��
#define MAX_RF_SENSOR_NUM		8	//����̽ͷ���·��
#define MAX_OUTPUT_NUM			4	//̽ͷ���·��
#define MAX_COM_NUM				2	//����������	
#define MAX_USER_NUM			5	//�û�����
#define	MAX_LOGON_NUM			10	//���ͬʱ��¼�û���
#define MAX_LINKVIEW_NUM		16	//���ͬʱTCP��UDPԤ���û���
#define MAX_MULTIVIEW_NUM		60	//���ಥ�û���
#define DVS_NAME_LEN            32	//������Ƶ���������Ƴ���

#define CAM_TITLE_LEN_NEW		64	//31�����֣�63���ַ�
#define CAM_TITLE_LEN			16	//��������ⳤ��(8�����֣�16���ַ�)
#define USER_NAME_LEN 			16	//�û�������󳤶�
#define USER_PASSWD_LEN   		16	//�û�������󳤶�
	
#define DDNS_NAME_LEN			32	//ע���������Ƴ���
#define DDNS_PASS_LEN			16	//ע���������볤��	
#define	DDNS_SERVER_NAME_LEN	32
#define PPPPOE_NAME_LEN			32	//�����û�������
#define PPPPOE_PASSWD_LEN		16	//�����û�������
#define YUNTAI_NAME_LEN			32	//��̨Э�����Ƴ���
#define	MAX_YUNTAI_PROTOCOL_NUM	36	//���������̨Э����
#define MAX_PTZ_PROTOCOL_NUM  	4	//�����̨Э����
#define	MAX_IP_NAME_LEN			128	//����IP�����ֵ���󳤶�
#define	IP_STR_LEN				16	//IP��

#define	DOMAIN_NAME_LEN			32  //�����ĳ���
#define EMAIL_TITLE_LEN         32	//EMAILͷ�����ݳ�
#define DD_URL_ADDR_LEN			32	//URL��ַ����
#define	DD_MAX_ADDR_NUM			32	//��ַ���ĵ�ַ����
#define	DD_MAX_ALARMINFO_NUM	64	//������¼�������ֵ

//2����̨����
#define	YT_UP					1	//��̨��
#define	YT_DOWN					2	//��̨��	
#define	YT_LEFT					3	//��̨��
#define	YT_RIGHT				4	//��̨��
#define	YT_FOCUSADD				5	//�۽�+
#define	YT_FOCUSSUB				6	//�۽�-
#define	YT_IRISADD				7	//��Ȧ+
#define	YT_IRISSUB				8	//��Ȧ-
#define	YT_ZOOMADD				9	//�䱶+
#define	YT_ZOOMSUB				10	//�䱶-
#define	YT_AUTOOPEN				11	//�Զ���
#define	YT_AUTOCLOSE			12	//�Զ���
#define	YT_LAMPOPEN				13	//�ƹ⿪
#define	YT_LAMPCLOSE			14	//�ƹ��
#define	YT_BRUSHOPEN			15	//��ο�
#define	YT_BRUSHCLOSE			16	//��ι�
#define	YT_WATEROPEN			17	//��ˮ��
#define	YT_WATERCLOSE			18	//��ˮ��
#define	YT_PRESET				19	//Ԥ�� + ��
#define	YT_CALL					20	//���� + ��
#define	YT_STOP					21	//ֹͣ
#define	YT_UP_STOP				30	//��̨��-ͣ	
#define	YT_DOWN_STOP			31	//��̨��-ͣ	
#define	YT_LEFT_STOP			32	//��̨��-ͣ
#define	YT_RIGHT_STOP			33	//��̨��-ͣ
#define	YT_FOCUSADD_STOP		34	//�۽�+ -ͣ
#define	YT_FOCUSSUB_STOP		35	//�۽�- -ͣ
#define	YT_IRISADD_STOP			36	//��Ȧ+ -ͣ
#define	YT_IRISSUB_STOP			37	//��Ȧ- -ͣ
#define	YT_ZOOMADD_STOP			38	//�䱶+ -ͣ
#define	YT_ZOOMSUB_STOP			39	//�䱶- -ͣ	

#define YT_UP_LIMIT				50	//����λ
#define YT_DOWN_LIMIT			51	//����λ
#define YT_LEFT_LIMIT			52	//����λ
#define YT_RIGHT_LIMIT			53	//����λ
#define YT_PREST_SCAN1			54	//Ԥ��λѲ��1
#define YT_PREST_SCAN2			55	//Ԥ��λѲ��2
#define YT_PREST_SCAN_STOP		56	//Ԥ��λѲ��ֹͣ
#define YT_APPLE_SCAN 			57	//��ƻ��ɨ��
#define YT_APPLE_SCAN_STOP		58	//��ƻ��ɨ��ֹͣ
#define YT_X_SCAN_SET			60	//����ɨ������
#define YT_X_SCAN_SAVE			61	//����ɨ�����ý���
#define YT_X_SCAN_RUN			62	//����ɨ������
#define YT_X_SCAN_STOP			63	//����ɨ��ֹͣ
#define YT_X_FLIP				64	//ˮƽ��ת
#define YT_VZERO_DETECT			65	//������λ���
#define YT_VZERO_SET			66	//������λ  ����
#define YT_VZERO_OK				67	//������λ	ȷ��
#define YT_VZERO_CANCEL			68	//������λ  ȡ��
#define YT_PTZ_RESET			69	//�����̨��λ
/*****************************************************************************/
/***************************  ����ö�����Ͷ���  ******************************/
/*****************************************************************************/

//1��������Ƶ��������������
typedef enum	DVS_MACHINE_TYPE_
{
	HH5001C  = 0x00,				//һ·CIF������
	HH5002H  = 0x01,				//��·HalfD1������
	HH5001D  = 0x02,				//һ·D1������
	HH5004C  = 0x03,				//��·CIF������
	HH5104   = 0x04,				//��·������
	HH5108   = 0x05,				//��·������
	HH6104   = 0x06,				//��·���뿨
	
	HH5200   = 0x10,				//����
	HH5201   = 0x11,				//IPCamһ·CCD,D1����,HH9000ϵ��
	HH5201DI = 0X11,
	HH5201CI = 0x12,				//IPCamһ·CCD,CIF����,HH9000ϵ��
	HH5201MI = 0x13,				//IPCamһ·CMOS,HH9000ϵ��

	HH5201C  = 0x20,				//DVSһ·CIF
	HH5201D  = 0x21,				//DVSһ·D1
	HH5202C  = 0x22,				//DVS��·CIF
	HH5202H  = 0x23,				//DVS��·HD1
	HH5204C  = 0x24,				//DVS��·CIF
	HH5204D  = 0x25,				//DVS��·d1
	
	HH5301   = 0x30,				//H.264 ��·������(IPCam,  HH52ϵ��, HH56ϵ��DVS)

	HH5700   = 0x35,				//HH57ϵ�� ������ (IPCam,  HH52ϵ��, HH56ϵ��DVS)

	HH9800CI = 0x40,				//HH98ϵ�� IPCamһ·CCD
	HH9800MI,						//HH98ϵ�� IPCamһ·CMOS
	HH9800MIX,						//HH98ϵ�� IPCamһ·CMOS(����)
	HH9800CIX,						//HH98ϵ�� IPCamһ·CCD (����)
	HH9800CIH,						//HH98ϵ�� IPCamһ·CCD (���������)

	HH5801C  = 0x45,				//HH58ϵ�� DVS			
	HH5801D,		
	HH5802C,
	HH5802H,
	HH5802D,	
	HH5804C,
	HH5804H,
	HH5804D, 

	HH7000   = 0x50,					
}DVS_MACHINE_TYPE;

//3����������
typedef enum _UPDATE_TYPE
{
	UPDATE_KERNEL,					//�����ں�
	UPDATE_YUNTAI1,					//������̨Э��1
	UPDATE_YUNTAI2,					//������̨Э��2
	UPDATE_YUNTAI3,					//������̨Э��3
	UPDATE_YUNTAI4,					//������̨Э��4
	UPDATE_YUNTAI5,					//������̨Э��5
	UPDATE_YUNTAI6,					//������̨Э��6
	UPDATE_OCX,						//�����ؼ�
	UPDATE_WEBPAGE,					//����ҳ��
	UPDATE_PATHFILE,				//�����ض�Ŀ¼�ļ�
}UPDATE_TYPE;

//4������Э������
typedef enum _NET_PROTOCOL_TYPE
{
    NET_PROTOCOL_TCP = 0,			//TCPЭ��
	NET_PROTOCOL_UDP = 1,			//UDPЭ��
	NET_PROTOCOL_MULTI = 2			//�ಥЭ��
}NET_PROTOCOL_TYPE;

//5������״̬
typedef enum _CONNECT_STATUS
{
	CONNECT_STATUS_NONE,			//δ����
	CONNECT_STATUS_OK,				//�Ѿ�����
	CONNECT_STATUS_DATA,
	CONNECT_STATUS_EXIST,
}CONNECT_STATUS;

//6��ת������
typedef enum _RELAY_TYPE
{
	RELAY_LOGON,					//ת����¼����
	RELAY_PREVIEW,					//ת����ƵԤ������
	RELAY_TALK,						//ת���Խ�
	RELAY_AUDIOBRD,					//ת�������㲥
	RELAY_QUERY						//ת���Ĳ�ѯ
}RELAY_TYPE;

//7��֪ͨӦ�ó��򴰿���Ϣ����
typedef enum _HHMSG_NOTIFY
{
	HHMSG_CONNECT_CLOSE,			//��¼���ӹر�
	HHMSG_CHANNEL_CLOSE,			//ͨ�����ӹر�
	HHMSG_TALK_CLOSE,				//�Խ����ӹر�
	HHMSG_ALARM_OUTPUT,				//�������
	HHMSG_UPDATE_SEND_PERCENT,		//���������Ͱٷֱ�
	HHMSG_UPDATE_SAVE_PERCENT,		//����д�뷢�Ͱٷֱ�
	HHMSG_BROADCAST_ADD_FAILURE,	//���������㲥��ʧ��
	HHMSG_BROADCAST_CLOSE,			//�����㲥��һ���Ͽ�
	HHMSG_SENSOR_CAPTURE,			//̽ͷ������ץ��
	HHMSG_COM_DATA,					//���ڲɼ�����
	HHMSG_ALARM_LOST,				//������ʧ
	HHMSG_ALARM_OUTPUT_NEW,			//�������(��)
	HHMSG_ALARM_LOST_NEW,			//������ʧ(��)
	HHMSG_PICCHN_CLOSE,				//ץ��ͨ�����ӹر�
	HHMSG_LOGON_SUCCESS,			//��¼���ӳɹ�
	HHMSG_CHANNEL_SUCCESS,			//ͨ�����ӳɹ�
	HHMSG_TALK_SUCCESS,				//�Խ����ӳɹ�
	HHMSG_BROADCAST_SUCCESS,		//���������㲥��ɹ�
	HHMSG_PICCHN_SUCCESS,			//ץ��ͨ�����ӳɹ�
	HHMSG_VIEWPUSH_SUCCESS,			//�򿪽�������Ƶ����ɹ�
	HHMSG_GPS_STATUS,				//GPS��Ϣ,add by huangtao
	HHMSG_NETREPLAY_CLOSE,			//Զ�̻ط�ͨ���ر�
	HHMSG_VIEWPUSH_CLOSE,			//����ͨ���ر�
}HHMSG_NOTIFY;

//8��������
typedef enum _HHERR_CODE
{
	HHERR_SUCCESS,					//�����ɹ�
	HHERR_FAILURE,					//����ʧ��
	HHERR_REFUSE_REQ,				//���󱻾ܾ�
	HHERR_USER_FULL,				//��¼�û�����
	HHERR_PREVIEW_FULL,				//Ԥ���û�����
	HHERR_TASK_FULL,				//ϵͳ����æ�����᳢������
	HHERR_CHANNEL_NOT_EXIST,		//Ҫ�򿪵�ͨ�������ڻ�����
	HHERR_DEVICE_NAME,				//�򿪵��豸������
	HHERR_IS_TALKING,				//���ڶԽ�
	HHERR_QUEUE_FAILUE,				//���г���
	HHERR_USER_PASSWORD,			//�û����������ϵͳ��ƥ��
	HHERR_SHARE_SOCKET,				//socket ����
	HHERR_RELAY_NOT_OPEN,			//ת������ķ���δ��
	HHERR_RELAY_MULTI_PORT,			//ת���ಥ�˿ڴ���
	HHERR_VIEWPUSH_CHANNEL_USING,	//��Ƶ�����ͨ���Ѿ���ռ��
	HHERR_VIEWPUSH_DECODE_TYPE,		//��Ƶ����ͨ���Ľ����ʽ����0ͨ��(4cif,2cif,cif),1ͨ��(2cif,cif),2ͨ��(cif),3ͨ��(cif)
	HHERR_AUTO_LINK_FAILURE,		//ת�����Զ�����ʧ��
	HHERR_NOT_LOGON,				//�豸��δ��¼
	HHERR_IS_SETTING,				//�豸��������
	HHERR_COMMAND_FAILURE,			//����ʧ��
	HHERR_RESTRICT_ID,				//IDʹ������
	
	HHERR_INVALID_PARAMETER=100,	//���������Ч
	HHERR_LOGON_FAILURE,			//��¼ʧ��
	HHERR_TIME_OUT,					//������ʱ
	HHERR_SOCKET_ERR,				//SOCKET����
	HHERR_NOT_LINKSERVER,			//��δ���ӷ�����
	HHERR_BUFFER_EXTCEED_LIMIT,		//ʹ�û��峬������	
	HHERR_LOW_PRIORITY,				//����Ȩ�޲���
	HHERR_BUFFER_SMALL,				//����̫С
	HHERR_IS_BUSY,					//ϵͳ������æ
	HHERR_UPDATE_FILE,				//�����ļ�����
	HHERR_UPDATE_UNMATCH,			//�����ļ��ͻ�����ƥ��
	HHERR_PORT_INUSE,				//�˿ڱ�ռ��
	HHERR_RELAY_DEVICE_EXIST,		//�豸���Ѿ�����
	HHERR_CONNECT_REFUSED,			//����ʱ���ܾ�
	HHERR_PROT_NOT_SURPPORT,		//��֧�ָ�Э��

	HHERR_FILE_OPEN_ERR,            //���ļ�ʧ��
	HHERR_FILE_SEEK_ERR,            //fseekʧ�� 
	HHERR_FILE_WRITE_ERR,           //fwriteʧ�� 
	HHERR_FILE_READ_ERR,            //freadʧ�� 
	HHERR_FILE_CLOSING,             //���ڹر��ļ� 
	
	HHERR_ALLOC_BUF_ERR,
}HHERR_CODE;

//9��������������
typedef enum _HHCMD_NET
{
	//����������
	HHCMD_GET_ALL_PARAMETER,		//0. �õ����б���������
	HHCMD_SET_DEFAULT_PARAMETER,	//1. �ָ����б�����Ĭ�ϲ���
	HHCMD_SET_RESTART_DVS,			//2. ����������
	HHCMD_GET_SYS_CONFIG,			//3. ��ȡϵͳ����
	HHCMD_SET_SYS_CONFIG,			//4. ����ϵͳ����
	HHCMD_GET_TIME,					//5. ��ȡ������ʱ��
	HHCMD_SET_TIME,					//6. ���ñ�����ʱ��
	HHCMD_GET_AUDIO_CONFIG,			//7. ��ȡ��Ƶ����
	HHCMD_SET_AUDIO_CONFIG,			//8. ������Ƶ����
	HHCMD_GET_VIDEO_CONFIG,			//9. ��ȡ��Ƶ����
	HHCMD_SET_VIDEO_CONFIG,			//10.������Ƶ����
	HHCMD_GET_VMOTION_CONFIG,		//11.��ȡ�ƶ��������
	HHCMD_SET_VMOTION_CONFIG,		//12.�����ƶ��������
	HHCMD_GET_VMASK_CONFIG,			//13.��ȡͼ����������
	HHCMD_SET_VMASK_CONFIG,			//14.����ͼ����������
	HHCMD_GET_VLOST_CONFIG,			//15.��ȡ��Ƶ��ʧ����
	HHCMD_SET_VLOST_CONFIG,			//16.������Ƶ��ʧ����
	HHCMD_GET_SENSOR_ALARM,			//17.��ȡ̽ͷ�����������
	HHCMD_SET_SENSOR_ALARM,			//18.����̽ͷ�����������
	HHCMD_GET_USER_CONFIG,			//19.��ȡ�û�����
	HHCMD_SET_USER_CONFIG,			//20.�����û�����
	HHCMD_GET_NET_CONFIG,			//21.��ȡ�������ýṹ
	HHCMD_SET_NET_CONFIG,			//22.�����������ýṹ
	HHCMD_GET_COM_CONFIG,			//23.��ȡ��������
	HHCMD_SET_COM_CONFIG,			//24.���ô�������
	HHCMD_GET_YUNTAI_CONFIG,		//25.��ȡ������̨��Ϣ
	HHCMD_SET_YUNTAI_CONFIG,		//26.����������̨��Ϣ
	HHCMD_GET_VIDEO_SIGNAL_CONFIG,	//27.��ȡ��Ƶ�źŲ��������ȡ�ɫ�ȡ��Աȶȡ����Ͷȣ�
	HHCMD_SET_VIDEO_SIGNAL_CONFIG,	//28.������Ƶ�źŲ��������ȡ�ɫ�ȡ��Աȶȡ����Ͷȣ�
	HHCMD_SET_PAN_CTRL,				//29.��̨����
	HHCMD_SET_COMM_SENDDATA,		//30.͸�����ݴ���
	HHCMD_SET_COMM_START_GETDATA,	//31.��ʼ�ɼ�͸������
	HHCMD_SET_COMM_STOP_GETDATA,	//32.ֹͣ�ɼ�͸������
	HHCMD_SET_OUTPUT_CTRL,			//33.�̵�������
	HHCMD_SET_PRINT_DEBUG,			//34.������Ϣ����
	HHCMD_SET_ALARM_CLEAR,			//35.�������
	HHCMD_GET_ALARM_INFO,			//36.��ȡ����״̬�ͼ̵���״̬
	HHCMD_SET_TW2824,				//37.���ö໭��оƬ����(����)
	HHCMD_SET_SAVE_PARAM,			//38.���ñ������
	HHCMD_GET_USERINFO,				//39.��ȡ��ǰ��½���û���Ϣ
	HHCMD_GET_DDNS,					//40.��ȡDDNS
	HHCMD_SET_DDNS,					//41.����DDNS
	HHCMD_GET_CAPTURE_PIC,			//42.ǰ��ץ��
	HHCMD_GET_SENSOR_CAP,			//43.��ȡ����ץ������
	HHCMD_SET_SENSOR_CAP,			//44.���ô���ץ������
	HHCMD_GET_EXTINFO,				//45.��ȡ��չ����
	HHCMD_SET_EXTINFO,				//46.������չ����
	HHCMD_GET_USERDATA,				//47.��ȡ�û�����
	HHCMD_SET_USERDATA,				//48.�����û�����
	HHCMD_GET_NTP,					//49.��ȡNTP����
	HHCMD_SET_NTP,					//50.����NTP����
	HHCMD_GET_UPNP,					//51.��ȡUPNP����
	HHCMD_SET_UPNP,					//52.����UPNP����
	HHCMD_GET_MAIL,					//53.��ȡMAIL����
	HHCMD_SET_MAIL,					//54.����MAIL����
	HHCMD_GET_ALARMNAME,			//55.��ȡ����������
	HHCMD_SET_ALARMNAME,			//56.���ñ���������
	HHCMD_GET_WFNET,				//57.��ȡ������������
	HHCMD_SET_WFNET,				//58.����������������
	HHCMD_GET_SEND_DEST,			//59.������Ƶ������Ŀ���
	HHCMD_SET_SEND_DEST,			//60.������Ƶ������Ŀ���
	HHCMD_GET_AUTO_RESET,			//61.ȡ�ö�ʱ����ע��
	HHCMD_SET_AUTO_RESET,			//62.���ö�ʱ����ע��
	HHCMD_GET_REC_SCHEDULE,			//63.ȡ��¼�����
	HHCMD_SET_REC_SCHEDULE,			//64.����¼�����
	HHCMD_GET_DISK_INFO,			//65.ȡ�ô�����Ϣ
	HHCMD_SET_MANAGE,				//66.��������Ͳ���
	HHCMD_GET_CMOS_REG,				//67.ȡ��CMOS����
	HHCMD_SET_CMOS_REG,				//68.����CMOS����
	HHCMD_SET_SYSTEM_CMD,			//69.����ִ������
	HHCMD_SET_KEYFRAME_REQ,			//70.���ùؼ�֡����
	HHCMD_GET_CONFIGENCPAR,			//71.ȡ����Ƶ����
	HHCMD_SET_CONFIGENCPAR,			//72.������Ƶ����

	//--------------------------    HH58ϵ�С�HH98ϵ�м��Ժ���豸��(���)
	HHCMD_GET_ALL_PARAMETER_NEW,	//73.��ȡ���в���
	HHCMD_FING_LOG,					//74.������־(��ѯ��ʽ:0��ȫ����1�������ͣ�2����ʱ�䣬3����ʱ������� 0xFF-�رձ�������)
	HHCMD_GET_LOG,					//75.��ȡ���ҵ�����־	
	HHCMD_GET_SUPPORT_AV_FMT,		//76.��ȡ�豸֧�ֵı����ʽ����߼���Ƶ��ʽ
	HHCMD_GET_VIDEO_CONFIG_NEW,		//77.ȡ����Ƶ�������£�
	HHCMD_SET_VIDEO_CONFIG_NEW,		//78.������Ƶ�������£�
	HHCMD_GET_VMOTION_CONFIG_NEW,	//79.ȡ���ƶ������������£�
	HHCMD_SET_VMOTION_CONFIG_NEW,	//80.�����ƶ������������£�
	HHCMD_GET_VLOST_CONFIG_NEW,		//81.ȡ����Ƶ��ʧ�����������£�
	HHCMD_SET_VLOST_CONFIG_NEW,		//82.������Ƶ��ʧ�����������£�
	HHCMD_GET_SENSOR_ALARM_NEW,		//83.ȡ��̽ͷ�����������£�
	HHCMD_SET_SENSOR_ALARM_NEW,		//84.����̽ͷ�����������£�
	HHCMD_GET_NET_ALARM_CONFIG,		//85.ȡ��������ϱ����������£�
	HHCMD_SET_NET_ALARM_CONFIG,		//86.����������ϱ����������£�
	HHCMD_GET_RECORD_CONFIG,		//87.ȡ�ö�ʱ¼�����
	HHCMD_SET_RECORD_CONFIG,		//88.���ö�ʱ¼�����
	HHCMD_GET_SHOOT_CONFIG,			//89.ȡ�ö�ʱץ�Ĳ���
	HHCMD_SET_SHOOT_CONFIG,			//90.���ö�ʱץ�Ĳ���
	HHCMD_GET_FTP_CONFIG,			//91.ȡ��FTP����
	HHCMD_SET_FTP_CONFIG,			//92.���ö�ʱץ�Ĳ���
	HHCMD_GET_RF_ALARM_CONFIG,		//93.ȡ�����߱�������
	HHCMD_SET_RF_ALARM_CONFIG,		//94.���ö�ʱץ�Ĳ���
	HHCMD_GET_EXT_DATA_CONFIG,		//95.ȡ��������չ����(��ƽ̨������������)
	HHCMD_SET_EXT_DATA_CONFIG,		//96.���ö�ʱץ�Ĳ���
	HHCMD_GET_FORMAT_PROCESS,		//97.ȡ�û�ȡӲ�̸�ʽ������
	HHCMD_GET_PING_CONFIG,			//98.ȡ��PING ���û�ȡ
	HHCMD_SET_PING_CONFIG,			//99.����PING ��������

	//����������
	DDCMD_GET_ALL_PARAMETER = 100,	//��ȡ��������������
	DDCMD_GET_TIME,					//��ȡϵͳʱ��
	DDCMD_SET_TIME,					//����ϵͳʱ��
	DDCMD_GET_SYS_CONFIG,			//��ȡϵͳ����
	DDCMD_SET_SYS_CONFIG,			//����ϵͳ����
	DDCMD_GET_NET_CONFIG,			//��ȡ��������
	DDCMD_SET_NET_CONFIG,			//������������
	DDCMD_GET_COM_CONFIG,			//��ȡ��������
	DDCMD_SET_COM_CONFIG,			//���ô�������
	DDCMD_GET_VIDEO_CONFIG,			//��ȡ��Ƶ����
	DDCMD_SET_VIDEO_CONFIG,			//������Ƶ����
	DDCMD_GET_ALARM_OPT,			//��ȡ����ѡ��
	DDCMD_SET_ALARM_OPT,			//���ñ���ѡ��
	DDCMD_GET_USER_INFO,			//��ȡ�û�������Ϣ
	DDCMD_SET_USER_INFO,			//�����û�������Ϣ
	DDCMD_GET_ALARM_RECORD,			//��ȡ������¼��Ϣ
	DDCMD_GET_ADRRESS_BOOK,			//��ȡ��ַ������
	DDCMD_SET_ADRRESS_BOOK,			//���õ�ַ������
	DDCMD_SET_COMM,					//���÷��ʹ�������
	DDCMD_SET_CMD,					//����͸��������
	DDCMD_GET_YUNTAI_INFO,			//��ȡ��̨��Ϣ
	DDCMD_GET_YUNTAI_CONFIG,		//��ȡ��̨����
	DDCMD_SET_YUNTAI_CONFIG,		//������̨����
	DDCMD_GET_ONELINK_ADDR,			//��ȡ��������·���ӵ���Ϣ
	DDCMD_SET_ONELINK_ADDR,			//���ý�������·���ӵ���Ϣ
	DDCMD_GET_CYCLELINK_ADDR,		//��ȡ������ѭ�����ӵ���Ϣ
	DDCMD_SET_CYCLELINK_ADDR,		//���ý�����ѭ�����ӵ���Ϣ
	DDCMD_GET_EXTINFO,				//��ȡ��չ����
	DDCMD_SET_EXTINFO,				//������չ����
	DDCMD_GET_NTP,					//��ȡNTP����
	DDCMD_SET_NTP,					//����NTP����
	DDCMD_GET_UPNP,					//��ȡUPNP����
	DDCMD_SET_UPNP,					//����UPNP����
	DDCMD_GET_MAIL,					//��ȡMAIL����
	DDCMD_SET_MAIL,					//����MAIL����
	DDCMD_GET_ALARMNAME,			//��ȡ����������
	DDCMD_SET_ALARMNAME,			//���ñ���������
	DDCMD_GET_WFNET,				//��ȡ������������
	DDCMD_SET_WFNET,				//����������������
	DDCMD_GET_SEND_DEST,			//������Ƶ������Ŀ���
	DDCMD_SET_SEND_DEST,			//������Ƶ������Ŀ���
}HHCMD_NET;

//10��ת���ж�
typedef enum _RELAY_CHECK_RET
{
	RCRET_SUCCESS = 0,
	RCRET_FAILURE = -1,
	RCRET_AUTO_LINK = 0x0101,	
}RELAY_CHECK_RET;

//11��¼������(��)
typedef enum  _HIDISK_RECTYPE_E
{
	HIDISK_RECTYPE_NONE		= 0x00000000,		

	HIDISK_RECTYPE_SENSOR	= 0x00000001,		//̽ͷ����¼��
	HIDISK_RECTYPE_MOTION	= 0x00000002,		//�ƶ���ⱨ��¼��
	HIDISK_RECTYPE_VILOST	= 0x00000004,		//��Ƶ��ʧ
	HIDISK_RECTYPE_RFALM	= 0x00000008,		//RF��������¼��
	HIDISK_RECTYPE_NETALM	= 0x00000010,		//������ϱ���

	HIDISK_RECTYPE_TIMER	= 0x00000020,		//��ʱ¼��
	HIDISK_RECTYPE_MANUAL	= 0x00000040,		//�ֶ�¼��
	
	HIDISK_RECTYPE_PREREC	= 0x40000000,		//Ԥ¼���־λ
	HIDISK_RECTYPE_PHOTO	= 0x80000000,		//ͼƬ�ļ�
}HIDISK_RECTYPE_E;
/*****************************************************************************/
/*********************************  �����ص�����  ****************************/
/*****************************************************************************/

//1��ʵʱ����Ƶ�������ص�
typedef int  (WINAPI *ChannelStreamCallback)(HANDLE hOpenChannel,void *pStreamData,DWORD dwClientID,void *pContext,ENCODE_VIDEO_TYPE encodeVideoType,HHAV_INFO *pAVInfo);

//2��ʵʱ�Խ���Ƶ�������ص�
typedef int  (WINAPI *TalkStreamCallback)(HANDLE hOpenChannel,void *pTalkData,UINT nTalkDataLen,void *pContext);

//3��ת��������û����ص�
typedef int	 (WINAPI *RelayCheckUserCallback)(RELAY_TYPE relayType,DWORD dwClientIP,WORD wClientPort,char *pszUserName,char *pszPassword,char *pszDeviceName,DWORD dwRequstChannel,BOOL bOnline,char *pDeviceIP,DWORD *pdwDevicePort,char *pContext);

//4�����ķ�����ģʽ�û����ص�
typedef int	 (WINAPI *CenterCheckUserCallback)(BOOL bOnLine,DVS_MACHINE_TYPE machineType,DWORD dwDeviceID,DWORD dwChannelNum,DWORD ip,WORD port,char *pszDeviceName,char *pszUserName,char *pszPassword,LPVOID pNetPar);

//5������¼��NVS�ص�
typedef void (WINAPI *SearchRecNVSCallback)(char *szNvsBuffer,int nBufferLen);

//6������¼���ļ�
//typedef void (WINAPI *SearchRecFileCallback)(void *pRecFile);
typedef void  (WINAPI *SearchRecFileCallback)(DWORD dwClientID,void *pRecFile);
typedef void  (WINAPI *SearchRecFileCallbackEx)(DWORD dwClientID,void *pRecFile);

//7������Ϣ�ص�����
typedef int	 (WINAPI *MessageNotifyCallback)(WPARAM wParam,LPARAM lParam);

//8��ץ��ͼƬ�ص�
typedef int  (WINAPI *PictureCallback)(HANDLE hPictureChn,void *pPicData,int nPicLen,DWORD dwClientID,void *pContext);

//9,¼��طŻص�
typedef int  (WINAPI *NetPlayCallback)(HANDLE hOpenChannel,void *pStreamData,BOOL bStream,int nDataLen,DWORD dwClientID,void *pContext);

/*****************************************************************************/
/******************************  �ġ��ӿڽṹ���Ͷ���  ***********************/
/*****************************************************************************/

//1,�������
typedef struct _ALARM_STATUS_OUTPUT
{
	BYTE			year;
	BYTE			month;
	BYTE			day;
	BYTE			week;
	BYTE			hour;
	BYTE			minute;
	BYTE			second;
	
	unsigned char	statusSensorAlarm;
	unsigned char	statusMotionAlarm;
	unsigned char	statusViLoseAlarm;
	unsigned char	SensorAlarmRec[MAX_SENSOR_NUM];
	unsigned char	MotionAlarmRec[MAX_VIDEO_NUM];
	unsigned char	ViLoseAlarmRec[MAX_VIDEO_NUM];
	unsigned char	statusAlarmOutput;
}ALARM_STATUS_OUTPUT;

//2������֪ͨ��Ϣ�ṹ
typedef struct _ALARM_MSG_NOTIFY
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	ALARM_STATUS_OUTPUT		alarmStatus;
}ALARM_MSG_NOTIFY;

//3���������(��)
typedef struct _ALARM_STATUS_OUTPUT_NEW
{
        unsigned char   year;
        unsigned char   month;
        unsigned char   day;
        unsigned char   week;
        unsigned char   hour;
        unsigned char   minute;
        unsigned char   second;
		unsigned char	millsecond;   

        unsigned int    SensorAlarm;
        unsigned int    MotionAlarm;
        unsigned int    ViLoseAlarm;
		unsigned int    RFSensorAlarm;
		unsigned int    NetAlarm;

        unsigned int    SensorAlarmRec[MAX_SENSOR_NUM];
        unsigned int    MotionAlarmRec[MAX_VIDEO_NUM];
        unsigned int    ViLoseAlarmRec[MAX_VIDEO_NUM];
        unsigned int    RFSensorAlarmRec[MAX_RF_SENSOR_NUM];
        unsigned int    NetAlarmRec;

        unsigned int    OutputStatus;
		
		unsigned int    reserved[19];
}ALARM_STATUS_OUTPUT_NEW;

//4������֪ͨ��Ϣ�ṹ(��)
typedef struct _ALARM_MSG_NOTIFY_NEW
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	ALARM_STATUS_OUTPUT_NEW	alarmStatus;			//2009.03.09
}ALARM_MSG_NOTIFY_NEW;


//5������ץ��ͼ��
typedef struct _SENSOR_PIC_NOTIFY
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	
	ALARM_STATUS_OUTPUT		alarmStatus;
	
	DWORD					dwChannelNo;
	DWORD					dwPicLen;
	LPVOID					pPicBuffer;
}SENSOR_PIC_NOTIFY;

//6�����ڲɼ�����
//��������
typedef struct __COM_CONFIG
{
	DWORD 				Baudrate;						//���ڲ�����				300---115200
	BYTE				Databit;						//��������λ����			5=5λ 6=6λ 7=7λ 8=8λ	����=8λ
	BYTE				Stopbit;						//ֹͣλλ��				1=1λ 2=2λ ����=1λ
	BYTE				CheckType;						//У��						0=��  1=��  2=ż  3=��1  4=��0 
	BYTE				Flowctrl; 						//������/Ӳ����/������		����
}COM_CONFIG;

//͸��ͨѶ
typedef struct __COMM_CTRL
{
	BYTE				COMMNo;							//���ں�	0 ~ 1
	COM_CONFIG			COMConfig;						//��������
	WORD				DataLength;						//���ݳ���
	BYTE				Data[256];						//����
}COMM_CTRL;

typedef struct _COMM_DATA_NOTIFY
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	COMM_CTRL				commCtrl;
}COMM_DATA_NOTIFY;

//7������Ƶͨ������
typedef struct _HHOPEN_CHANNEL_INFO
{
	DWORD					dwClientID;
	UINT					nOpenChannel;
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
}HHOPEN_CHANNEL_INFO;

//HH58ϵ�С�HH98ϵ�м��Ժ���豸��, ������ǰ���豸
typedef struct _HHOPEN_CHANNEL_INFO_EX
{
	DWORD					dwClientID;
	UINT					nOpenChannel:8;				//ͨ���ţ�0 �� 3��
	UINT					nSubChannel:8;				//0: ��������      1: �򿪴�����	
	UINT					res:16;	
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
}HHOPEN_CHANNEL_INFO_EX;

//8������Ƶͨ������
typedef struct _HHOPEN_VIEWPUSH_INFO
{
	DWORD					dwClientID;
	UINT					nViewPushChannel;
	NET_PROTOCOL_TYPE		protocolType;
	HHAV_INFO				avInformation;
	
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	
	UINT					nScreenCount;
	UINT					nScreenIndex;
}HHOPEN_VIEWPUSH_INFO;

//9���򿪵ķ�������Ϣ
typedef struct _HH_SERVER_INFO
{
	HANDLE					hServer;
	char					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	char					szDeviceName[DVS_NAME_LEN+1];
	UINT					nDeviceID;
	
	char					szUserName[USER_NAME_LEN+1];
	char					szUserPassword[USER_PASSWD_LEN+1];
		
	DWORD					dwClientID;
	
	CONNECT_STATUS			logonStatus;
	UINT					nVersion;
	UINT					nLogonID;
	UINT					nPriority;
	UINT					nServerChannelNum;
	UINT					nLanguageNo;
	DVS_MACHINE_TYPE		nMachineType;
	BOOL					bPalStandard;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	HHAV_INFO				avInformation[MAX_VIDEO_NUM];
}HH_SERVER_INFO;

//10���򿪵�ͨ����Ϣ
typedef struct _HH_CHANNEL_INFO
{
	HANDLE					hOpenChannel;
	char					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	char					szDeviceName[DVS_NAME_LEN+1];
	
	char					szUserName[USER_NAME_LEN+1];
	char					szUserPassword[USER_PASSWD_LEN+1];
	
	DWORD					dwClientID;
	
	CONNECT_STATUS			openStatus;
	UINT					nVersion;
	UINT					nOpenID;
	UINT					nPriority;
	UINT					nOpenChannelNo;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	HHAV_INFO				avInformation;
	ENCODE_VIDEO_TYPE		encodeVideoType;
	
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
	
	DWORD					dwDeviceID;	//V4.0 add
}HH_CHANNEL_INFO;

//11���򿪵Ľ���������ͨ����Ϣ
typedef struct _HH_VIEWPUSH_INFO
{
	HANDLE				hOpenChannel;
	char				szServerIP[MAX_IP_NAME_LEN+1];
	UINT				nServerPort;
	char				szDeviceName[DVS_NAME_LEN+1];
	
	char				szUserName[USER_NAME_LEN+1];
	char				szUserPassword[USER_PASSWD_LEN+1];
	
	DWORD				dwClientID;
	
	CONNECT_STATUS		openStatus;
	UINT				nVersion;
	UINT				nOpenID;
	UINT				nPriority;
	UINT				nOpenChannelNo;
	UINT				nMulticastAddr;
	UINT				nMulticastPort;
	HHAV_INFO			avInformation;
	ENCODE_VIDEO_TYPE	encodeVideoType;
	NET_PROTOCOL_TYPE	protocolType;
	
	DVS_MACHINE_TYPE	nMachineType;
	DWORD				dwChannelNum;	//���������·��
}HH_VIEWPUSH_INFO;

//12���Խ�����Ϣ
typedef struct _HH_TALK_INFO 
{
	HANDLE				hServer;
	char				szServerIP[MAX_IP_NAME_LEN+1];
	UINT				nServerPort;
	char				szDeviceName[DVS_NAME_LEN+1];
	
	char				szUserName[USER_NAME_LEN+1];
	char				szUserPassword[USER_PASSWD_LEN+1];
	
	//unsigned long		version;	
	void			   *pTalkContext;			//2009.04.01
	unsigned long		nMachineType;
	
	CONNECT_STATUS		logonStatus;
	//audio parameter
	UINT				nAudioEncodeType;
    UINT				nAudioChannels;
    UINT				nAudioBits;
    UINT				nAudioSamples;
}HH_TALK_INFO;

//13�������㲥���û���Ϣ
typedef struct _HH_BROADCAST_USER
{
	HANDLE	hBroadcastUser;
	char	szServerIP[MAX_IP_NAME_LEN+1];
	DWORD	port;
	char	szDeviceName[DVS_NAME_LEN+1];	
	char	szUserName[USER_NAME_LEN+1];
	char	szUserPassword[USER_PASSWD_LEN+1];
	
	BOOL	bConnect;
	SOCKET	hSock;
	PVOID	pPar;
	//add v4.2
	DWORD				machineType;
	ENCODE_VIDEO_TYPE	audioType;
	HANDLE	hEventSigExist;
}HH_BROADCAST_USER;

//14��ת����Ƶ������
typedef struct _HH_RELAY_NVS
{
	RELAY_TYPE			relayType;
	char				szServerIP[MAX_IP_NAME_LEN+1];
	WORD				wServerPort;
	char				szDeviceName[DVS_NAME_LEN+1];
	DWORD				dwChannelNo;
	DWORD				dwCount;
}HH_RELAY_NVS;	

//15���ٷֱ���Ϣ֪ͨ
typedef struct _HH_PERCENT_NOTIFY
{
	HANDLE				hLogon;
	DWORD				dwClientID;
	DWORD				dwPercent;
}HH_PERCENT_NOTIFY;

//16����Ƶ�ļ�����
typedef struct _HHFILE_INFO
{
	char                szFileName[MAX_PATH];
	char				szServerIP[MAX_IP_NAME_LEN+1];
	WORD				wServerPort;
	char				szUserName[USER_NAME_LEN+1];
	char				szUserPassword[USER_PASSWD_LEN+1];
	BOOL                bRelay     ; // ���ļ��Ƿ�ͨ��ת��
}HH_FILE_INFO;

typedef struct _HHFILE_INFO_EX
{
	HIDISK_RECTYPE_E	nRecType;		//¼������
	BYTE				nOpenChannel;	//ͨ����0~3
	BYTE				nSubChannel;	//0��������1������
	BYTE				mark;			//���һ��1,����0
	BYTE				rsvd;		
	time_t				tmStart;		//��ʼʱ��� time_t����
	time_t				tmEnd;			//����ʱ��� time_t����
	long				nRecSize;		//¼�����ֽ���		
	char                szFileName[MAX_PATH]; //yyyymmddhhmmss-yyymmddhhmmss
}HH_FILE_INFO_EX;

//17������Ƶ�ļ�����
typedef struct _HHOPEN_FILE_INFO
{
	DWORD				dwClientID  ;
	UINT				nOpenChannel;
	NET_PROTOCOL_TYPE	protocolType;
	char				szDeviceName[DVS_NAME_LEN+1];
	HH_FILE_INFO        hhFile      ;       
	char                szOpenMode[5];
	DWORD				dwSocketTimeOut;
	
    // ���
	DWORD				dwFileSize;         // �ļ���С
	DWORD				dwStartTime;        // ���ſ�ʼʱ��(����)
	DWORD				dwEndTime;          // ���Ž���ʱ��(����)
	
	UINT				nVideoEncodeType;	//��Ƶ�����ʽ
	UINT				nAudioEncodeType;	//��Ƶ�����ʽ	
}HHOPEN_FILE_INFO;

typedef struct _INNER_OPEN_FILE_INFO_EX
{
	BYTE nOpenChannel;	//ͨ����0~3
	BYTE nSubChannel;	//0��������1������
	BYTE nPlayMode;		//����ģʽ��0��������Speed��Ч����1��ֱ������
	BYTE nPlaySpeed;	//�����ٶȣ�0��������1����2X��2:��4X��-1����2X��-2����4X
	long nRecType;		//0:¼��,1:ͼƬ
	long tmStart;		//��ʼ����ʱ��� time_t����
	long tmEnd;		    //��������ʱ��� time_t����
}INNER_OPEN_FILE_INFO_EX;

typedef struct _HHOPEN_FILE_INFO_EX
{
	INNER_OPEN_FILE_INFO_EX	inner_ofi;
	DWORD					dwClientID;
	NetPlayCallback			funcNetRePlayCallback;
	void					*pCallbackContext;	
}HHOPEN_FILE_INFO_EX;

//18��������������������NVS
typedef struct _HH_SEARCH_REC_NVS
{
	DWORD				dwClientID  ;
	// �洢¼���ļ�������
	char                Date[11];// ����1 ¼������ yyyy-mm-dd
    BYTE                recType ;// ����2 ¼������: 0-���У�1-������2-�ֶ���3-��ʱ
	
	SearchRecNVSCallback	funcSearchRecNvsCallback;	
}HH_SEARCH_REC_NVS;

// 19��������������������¼���ļ�
typedef struct _HH_SEARCH_REC_FILE
{
	DWORD				dwClientID  ;
	
	// �洢¼���ļ�������
    char                szDir[MAX_PATH]; // ����1: " Datae\\Ip-NVS\\Camera\\"
	char				szTime1[6];      // ����2 ʱ���1 hh:mm
	char				szTime2[6];      // ����2 ʱ���2 hh:mm
    BYTE                recType ;	     // ����3 ¼������: 0-���У�1-������2-�ֶ���3-��ʱ
	
	SearchRecFileCallback	funcSearchRecFileCallback;
}HH_SEARCH_REC_FILE;

typedef struct _INNER_SEARCH_REC_FILE_EX
{
    HIDISK_RECTYPE_E    nRecType;	        // ¼������
	BYTE				nOpenChannel;		// ͨ����0~3
	BYTE				nSubChannel; 		// 0:��������1:������
	BYTE				rsvd[2];
	long				tmStart;			// ��ѯ�Ŀ�ʼʱ�䣬time_t
	long				tmEnd;				// ��ѯ�Ľ���ʱ�䣬time_t
}INNER_SEARCH_REC_FILE_EX;

typedef struct _HH_SEARCH_REC_FILE_EX
{
	INNER_SEARCH_REC_FILE_EX inner_srf;
	DWORD				dwClientID;			//������
	DWORD				dwSocketTimeOut;
	SearchRecFileCallbackEx	funcSearchRecFileCallback;
}HH_SEARCH_REC_FILE_EX;

//20��ת����ѯ
typedef struct _RELAY_QUERY_INFO
{
	DWORD		dwSize;
	DWORD		dwServerLogonNum;
	DWORD		dwServerPreviewNum;
	DWORD		dwServerTalkNum;
	DWORD		dwServerBrdNum;
	DWORD		dwClientLogonNum;
	DWORD		dwClientPreviewNum;
	DWORD		dwClientTalkNum;
	DWORD		dwClientBrdNum;
	char		reserve[16];
}RELAY_QUERY_INFO;

//21����ץ�Ĳ���
typedef struct _HHOPEN_PICTURE_INFO
{
	DWORD					dwClientID;
	DWORD					nOpenChannel;	
	NET_PROTOCOL_TYPE		protocolType;
	PictureCallback			funcPictureCallback;
	void					*pCallbackContext;
}HHOPEN_PICTURE_INFO;

//22���򿪵�ͨ����Ϣ
typedef struct _HH_PICTURE_INFO
{
	HANDLE					hOpenChannel;
	char					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	char					szDeviceName[DVS_NAME_LEN+1];
	
	char					szUserName[USER_NAME_LEN+1];
	char					szUserPassword[USER_PASSWD_LEN+1];
	
	DWORD					dwClientID;
	
	CONNECT_STATUS			openStatus;
	UINT					nVersion;
	UINT					nOpenID;
	UINT					nPriority;
	UINT					nOpenChannelNo;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	UINT					nPicWidth;
	UINT					nPicHeight;
	UINT					nPicBits;
	int						picFormatType;//0:JPEG,1:BMP
	
	NET_PROTOCOL_TYPE		protocolType;
	PictureCallback			funcStreamCallback;
	void					*pCallbackContext;
	
	DWORD					dwDeviceID;
}HH_PICTURE_INFO;

typedef struct _HH_NET_TIME
{
	DWORD				dwYear;					// Year
	DWORD				dwMonth;				// Month
	DWORD				dwDay;					// Date
	DWORD				dwHour;					// Hour
	DWORD				dwMinute;				// Minute
	DWORD				dwSecond;				// Second
} HH_NET_TIME;

/*****************************************************************************/
/********************************  �塢�����ӿڶ���  *************************/
/*****************************************************************************/

//------------------------------  1���������ر�  -------------------------------//
//��������
HHNET_API HHERR_CODE		WINAPI	HHNET_Startup(IN  HWND hNotifyWnd,IN  UINT nCommandID,IN DWORD dwFrameBufNum = 0,IN BOOL bReadyRelay = FALSE,IN BOOL bReadyCenter=FALSE,IN char *pLocalAddr=NULL);
//�رշ���
HHNET_API HHERR_CODE		WINAPI	HHNET_Cleanup();
//�ı��֪ͨӦ�õķ�ʽΪ�ص�����
HHNET_API HHERR_CODE		WINAPI	HHNET_MessageCallback(MessageNotifyCallback pCallback);


//------------------------------  2����¼����  ----------------------------------//
//��¼������
HHNET_API HHERR_CODE		WINAPI	HHNET_LogonServer(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN	 char *pUserName,IN	 char *pUserPassword,IN DWORD dwClientID,OUT  HANDLE &hLogonServer,IN HWND hNotifyWindow = NULL);
//ע��������
HHNET_API HHERR_CODE		WINAPI	HHNET_LogoffServer(IN  HANDLE hServer);
//��ȡ��¼��������Ϣ
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadServerInfo(IN  HANDLE hServer,OUT  HH_SERVER_INFO &serverInfo);

//��������
HHNET_API HHERR_CODE		WINAPI	HHNET_Update(IN HANDLE hServer,IN UPDATE_TYPE nUpdateType,IN char *pFilePathName);

//��ȡ��¼������������Ϣ
HHNET_API HHERR_CODE		WINAPI  HHNET_GetServerConfig(IN  HANDLE hServer,IN  HHCMD_NET nConfigCommand,OUT  char *pConfigBuf,IN OUT  UINT &nConfigBufSize,IN  OUT  DWORD *pAppend=NULL);
//���õ�¼������������Ϣ
HHNET_API HHERR_CODE		WINAPI  HHNET_SetServerConfig(IN  HANDLE hServer,IN  HHCMD_NET nConfigCommand,IN   char *pConfigBuf,IN  UINT nConfigBufSize,IN  DWORD dwAppend=0);



//-------------------------------  3��Ԥ��ͨ��  ---------------------------------//
//����Ƶͨ��
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenChannel(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,IN  HHOPEN_CHANNEL_INFO *pOpenInfo,OUT  HANDLE &hOpenChannel,IN HWND hNotifyWindow = NULL);
//�ر���Ƶͨ��
HHNET_API HHERR_CODE		WINAPI	HHNET_CloseChannel(IN  HANDLE hOpenChannel);

//��ȡ����Ƶͨ����Ϣ
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadChannelInfo(IN  HANDLE hOpenChannel,OUT  HH_CHANNEL_INFO &channelInfo);



//-------------------------------  4���Խ�����  ---------------------------------//
//����򿪶Խ�
HHNET_API HHERR_CODE		WINAPI	HHNET_TalkRequsest(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN	 char *pUserName,IN	 char *pUserPassword,IN TalkStreamCallback funcTalkCallback,IN void *pContext,OUT  HANDLE &hTalk,IN HWND hNotifyWindow = NULL);
//�����Խ�
HHNET_API HHERR_CODE		WINAPI	HHNET_TalkStop(IN HANDLE hTalk);

//��ȡ�򿪶Խ���Ϣ
HHNET_API HHERR_CODE		WINAPI	HHNET_TalkReadInfo(IN HANDLE hTalk,HH_TALK_INFO &talkInfo);
//���ͶԽ�����
HHNET_API HHERR_CODE		WINAPI	HHNET_TalkSend(IN HANDLE hTalk,IN char *pTalkData,IN UINT nDataLen);



//------------------------------  5�������㲥  ---------------------------------//
//���������㲥
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastStart(IN HWND hNotifyWindow = NULL);
//�ر������㲥
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastStop();

//���һ����Ƶ�������������㲥��
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastAddClient(IN  char *pServerIP,IN  WORD wServerPort,IN char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,OUT HANDLE	&hBrdClient);

//�����㲥����ɾ��һ���û�
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastDelClient(IN HANDLE hBrdClient);

//�õ��㲥�����û���Ϣ
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastClientInfo(IN HANDLE hBrdClient,OUT HH_BROADCAST_USER *clientInfo);

//ȡ�����������㲥�û���״̬
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastAllClientInfo(IN  void *pInfoBuf,IN DWORD &dwInfoBufSize);

//���������㲥����
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastSend(IN char *pTalkData,IN UINT nDataLen,ENCODE_VIDEO_TYPE audoEncType=EV_TYPE_NONE);



//------------------------------  6����Ƶ����  ---------------------------------//
//����򿪽���������ͨ��
HHNET_API HHERR_CODE		WINAPI	HHNET_ViewPushRequest(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,IN HHOPEN_VIEWPUSH_INFO *pOpenViewPushInfo,OUT  HANDLE &hViewPush,IN HWND hNotifyWindow = NULL);

//�رմ򿪵Ľ���������ͨ��
HHNET_API HHERR_CODE		WINAPI	HHNET_ViewPushStop(IN HANDLE hViewPush);

//��ȡ�򿪵Ľ���������ͨ����Ϣ
HHNET_API HHERR_CODE		WINAPI	HHNET_ViewPushReadInfo(IN HANDLE hViewPush,OUT HH_VIEWPUSH_INFO &viewPushInfo);

//���򿪵Ľ���������ͨ����������
HHNET_API int				WINAPI	HHNET_ViewPushSend(IN HANDLE hViewPush,IN char *pViewPushData,IN UINT nDataLen,ENCODE_VIDEO_TYPE encodeVideoType);

//�л���ʾ����
HHNET_API HHERR_CODE		WINAPI	HHNET_ViewPushScreenMode(IN HANDLE hViewPush,IN UINT nScreenCount,IN UINT nScreenIndex);



//------------------------------  7��ת������  ---------------------------------//
//����ת������
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayStart(IN WORD wListenPort = 5000,IN char *pMultiAddr = "234.100.100.100",IN WORD wMultiPort = 5000,
													 IN DWORD dwVideoBufNum = 1024,IN DWORD dwAudioBufNum = 100,IN DWORD dwChannelPreviewNum = 50,
													 IN DWORD dwAllPreviewNum = 200,IN RelayCheckUserCallback funcRelayCheck = NULL,
													 IN char *pRelayAddr = NULL,IN HWND hNotifyWindow = NULL);

//�ر�ת������
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayStop();

//�õ�ת����NVS��Ϣ
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayGetNVS(IN RELAY_TYPE relayType,OUT HH_RELAY_NVS *pRelayNVS,IN OUT DWORD *pRelayNVSBufSize);

//ɾ��ת����NVS
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayDeleteNVS(IN HH_RELAY_NVS relayNVS);

//�õ�ת����NVS���û���Ϣ
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayGetNVSClient(IN HH_RELAY_NVS relayNVS,OUT SOCKADDR_IN *pAddrList,IN OUT DWORD *pAddrListSize);

//ת����������ѯ
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayServerQuery(IN char *pRelayServerIP,IN WORD wRelayServerPort,IN char *pUserName,IN char *pPassword,OUT RELAY_QUERY_INFO *pRelayQueryInfo,IN OUT DWORD &dwSize);


//----------------------------  8�����Ĺ��������  -------------------------------//
//�������Ĺ������
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_Start(IN CenterCheckUserCallback checkNvsCallback,IN WORD wListenPort = 6000,IN HWND hNotifyWindow = NULL);

//�ر����Ĺ������
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_Stop();

//������ģʽ��¼
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_LogonServer(IN DWORD dwDeviceID,IN DWORD dwClientID,OUT HANDLE &hLogon);

//������ģʽ��Ԥ�� 
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_OpenChannel(IN DWORD dwDeviceID,IN  HHOPEN_CHANNEL_INFO *pOpenInfo,OUT HANDLE &hPreview);

//������ģʽ�򿪶Խ�
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_TalkRequest(IN DWORD dwDeviceID,IN TalkStreamCallback funcTalkCallback,IN void *pContext,OUT HANDLE &hTalk);

//������ģʽ�������㲥
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_BroadcastAddClient(IN DWORD dwDeviceID,OUT HANDLE &hBrdClient);



//------------------------------  9��DDNS��������  ---------------------------------//
//��������������ȡ��Ϣ
HHNET_API HHERR_CODE		WINAPI	HHNET_GetInfoByDDNS(IN char *pDDNSIP,IN WORD wDDNSPort,IN char *pRegisterName,OUT char *pRegisterIP,OUT WORD *pRegisterWebPort,OUT WORD *pRegisterDataPort);



//------------------------------   10����������    ---------------------------------//
//���������豸
HHNET_API HHERR_CODE		WINAPI	HHNET_SearchAllServer(UINT nTimeWait,
														  void(WINAPI *CallbackServerFind)(DVS_MACHINE_TYPE nDeviceType,char *pDeviceName,
														  char *pIP,BYTE macAddr[6],WORD wPortWeb,WORD wPortListen,char *pSubMask,
														  char *pGateway,char *pMultiAddr,char *pDnsAddr,WORD wMultiPort,int nChannelNum,int nFindCount,DWORD dwDeviceID));
//������Ƶ��������������
HHNET_API HHERR_CODE		WINAPI	HHNET_ConfigServer(BYTE macAddr[6],char *pUserName,char *pUserPassword,
													   char *pIP,char *pDeviceName,char *pSubMask,char *pGateway,char *pMultiAddr,
													   char *pDnsAddr,WORD wPortWeb,WORD wPortListen,WORD wPortMulti);


//------------------------------  11����¼���ļ�  -------------------------------//
//����Ƶ�ļ�	fopen
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenFile(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,HHOPEN_FILE_INFO *pOpenInfo,OUT  HANDLE &hFile);
//�ر���Ƶ�ļ�	fclose
HHNET_API HHERR_CODE		WINAPI	HHNET_CloseFile(IN  HANDLE hFile);
//����Ƶ�ļ�	fread
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadFile(IN  HANDLE hFile ,IN UINT size,IN UINT count,OUT void *buffer,OUT UINT &nRealReadLen);
//д��Ƶ�ļ�	fwrite
HHNET_API HHERR_CODE		WINAPI	HHNET_WriteFile(IN  HANDLE hFile,IN const void *buffer, IN UINT size, IN UINT count, OUT UINT &nRealWriteLen);
//��λ�ļ�ָ��	fseek
HHNET_API HHERR_CODE		WINAPI	HHNET_SeekFile(IN  HANDLE hFile, IN long offset, IN int origin );
//��ȡָ��λ��	ftell
HHNET_API HHERR_CODE		WINAPI	HHNET_TellFile(IN  HANDLE hFile, OUT long &pos);
//���ļ��Ƿ����feof
HHNET_API HHERR_CODE		WINAPI	HHNET_EofFile(IN  HANDLE hFile, OUT int &ret);


//����һ�� ������� HHERR_SUCCESS �� nOutLen=0��־�����ļ�β,������Ч)
//���ݱ������ bRemain ֵ��ȷ���Ƿ�����һ��ɶ�
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadFirstFrame(IN  HANDLE hFile, void *outBuf, OUT UINT &nOutLen,OUT long &dwRemain);
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadNextFrame(IN  HANDLE hFile,  void *outBuf, OUT UINT &nOutLen,OUT long &dwRemain);


//------------------------------  12������NVS¼���ļ�  -------------------------------//
//��������
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenSearchRecInfo(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pUserName,IN  char *pUserPassword,OUT  HANDLE &hSearch);
//�ر�����
HHNET_API HHERR_CODE		WINAPI	HHNET_CloseSearchRecInfo(IN  HANDLE hSearch);
//����¼��NVS
HHNET_API HHERR_CODE		WINAPI	HHNET_SearchRecNVS( IN  HANDLE hSearch,HH_SEARCH_REC_NVS  *pSearchInfo);
//����¼���ļ�
HHNET_API HHERR_CODE		WINAPI	HHNET_SearchRecFile(IN  HANDLE hSearch,HH_SEARCH_REC_FILE *pSearchInfo);


//------------------------------  13��ǰ��ץ��  -------------------------------//
//��ץ��ͨ��
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenPicture(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,IN  HHOPEN_PICTURE_INFO *pOpenInfo,OUT  HANDLE &hOpenChannel,IN HWND hNotifyWindow = NULL);
//�ر�ץ��ͨ��
HHNET_API HHERR_CODE		WINAPI	HHNET_ClosePicture(IN  HANDLE hOpenPicture);
//����ץ��һ��ͼƬ
HHNET_API HHERR_CODE		WINAPI	HHNET_CapturePicture(IN  HANDLE hOpenPicture);
//��ȡץ��ͨ����Ϣ
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadPictureInfo(IN  HANDLE hOpenPicture,OUT  HH_PICTURE_INFO &channelInfo);


//------------------------------- 14������Զ�̻ط� -----------------------------//
//��������
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenSearchRecInfoEx(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pUserName,IN  char *pUserPassword,OUT  HANDLE &hSearch,OUT BOOL & bSupportNew);
//����¼���ļ�
HHNET_API HHERR_CODE		WINAPI	HHNET_SearchRecFileEX(IN  HANDLE hSearch,HH_SEARCH_REC_FILE_EX *pSearchInfo);
//��Զ��¼���ļ�
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenFileEx(char *pServerIP,WORD wServerPort,char *pDeviceName,char *pUserName,char *pUserPassword,HHOPEN_FILE_INFO_EX *pOpenInfo,HANDLE &hFile);
//���¶�λ¼���ļ�
HHNET_API HHERR_CODE		WINAPI	HHNET_SeekFileEx(IN  HANDLE hFile, IN long nSeekTime,IN BOOL bKeyFrame);
//����Զ�̻طŵ��ٶ�
HHNET_API HHERR_CODE		WINAPI	HHNET_SpeedFile(IN  HANDLE hFile, IN short nMask, IN BYTE nPlayMode,IN BYTE nPlaySpeed);
//����Զ�̻ط�
HHNET_API HHERR_CODE		WINAPI	HHNET_StepFile(IN  HANDLE hFile, IN BYTE bKeyFrame,IN BYTE nStepMode);

/*****************************************************************************/
/************************  �����豸��(NVS��IPCamera)��������Ϣ�ṹ  **********/
/*****************************************************************************/

//------------------------------(I)�������������ýṹ------------------------//
//1������ʱ��ṹ
typedef  struct  _DVS_DATE
{
	BYTE		year;									//��
	BYTE		month;									//��
	BYTE		day;									//��
	BYTE		week;									//��
	BYTE		hour;									//Сʱ
	BYTE		minute;									//����
	BYTE		second;									//��
}DVS_DATE;

//2��ʱ��νṹ������һ�����ʼʱ��ͽ���ʱ��
typedef struct _TIME_SEGMENT
{
	BYTE 		bDetectOpen;							//��⿪��
	BYTE        nBgnHour ;								//��ʼʱ
	BYTE        nBgnMinute ;							//��ʼ��
	BYTE        nEndHour ;								//����ʱ
	BYTE        nEndMinute ;							//������
}TIME_SEGMENT;

//3����Ƶ����
typedef struct _AUDIO_CONFIG
{
	BYTE		Open:1;									//��Ƶ�Ƿ��
	BYTE		MicOrLine:1;							//��Ƶ����ģʽ����˻�������
	BYTE		resver:6;
	BYTE		Type;									//ѹ����ʽ
	DWORD		Bitrate ;								//����
	DWORD		SampleBitrate ;							//������
}AUDIO_CONFIG;

//4����Ƶ����
typedef struct _VIDEO_CONFIG
{	
	DWORD		KeyInterval;							//I ֡���
	DWORD		Bitrate ;								//����
	BYTE		Qulity;									//����1--31
	float		FrameRate ;								//֡��
	BYTE		BitflowType; 							//�������� 		   0:VBR,1:CBR
	
	BYTE		DateOSD; 								// 0:����������,   1:�������� 
	BYTE		TimeOSD; 								// 0:������ʱ��,   1:����ʱ�� 
	BYTE		WeekOSD; 								// 0:����������,   1:�������� 
	BYTE		TitleOSD;								// 0:�����ӱ���,   1:���ӱ��� 
	BYTE		BitrateOSD;								// 0:����������,   1:�������� 	
	char    	Title[CAM_TITLE_LEN+ 1];				// �����ַ�        16���ַ�  8������
	
	BYTE 		Brightness;								//����
	BYTE 		Hue;									//ɫ��
	BYTE 		Saturation;								//���Ͷ�
	BYTE 		Contrast;								//�Աȶ�
	BYTE 		Protocol;								//Э��
	BYTE 		YTAddr;									//��������ַ
}VIDEO_CONFIG;

//5���ƶ��������
typedef struct _VIDEO_MOTION_CONFIG
{
	BYTE 		DetectLevel;							//�ƶ����������
	BYTE 		DetectOpen;								//�ƶ���⿪��
	WORD 		AutoClearTime;							//�ƶ������Զ����ʱ��	
	BYTE 		Output;									//�ƶ������������				 0---3	
	BYTE 		Record;									//�ƶ���������¼��				 0---3	
	BYTE 		DetectTest;								//�ƶ����������Կ���
	DWORD 		DetectArea[18];							//�ƶ��������	
	TIME_SEGMENT	tSchTable[8] ;						//�ƶ����ʱ���1				 0: ÿ��
}VIDEO_MOTION_CONFIG;

//6��ͼ����������
typedef struct _VIDEOMASK_CONFIG 
{
	BYTE 		MaskOpen;								//��Ƶ���ο���		0:��         1����
	DWORD 		MaskArea[18];							//��Ƶ��������	
} VIDEOMASK_CONFIG;

//7����Ƶ��ʧ����
typedef struct _VIDEOLOSE_CONFIG
{
	BYTE		DetectOpen;								//��Ƶ��ʧ���
	BYTE 		Output;									//��Ƶ��ʧ�����������			 0---3		
	BYTE 		Record;									//��Ƶ��ʧ����¼��				 0---3	
	WORD		AutoClearTime;							//��Ƶ��ʧ�����Զ����ʱ��
} VIDEOLOSE_CONFIG;

//8��̽ͷ�����������
typedef struct _SENSOR_CONFIG 
{
	BYTE		SensorType;								//0:����̽ͷ	1:����̽ͷ
	BYTE 		DetectOpen;								//��⿪��
	WORD 		AutoClearTime;							//̽ͷ�����Զ����ʱ��	
	BYTE 		Output;									//̽ͷ�����������				 0---3	
	BYTE 		Record;									//̽ͷ��������¼��				 0---3	
	TIME_SEGMENT	tSchTable[8] ;						//̽ͷ���ʱ���1				 0: ÿ��
} SENSOR_CONFIG;

//9���û�����
typedef struct _USER_CONFIG
{
	DWORD 		Level;									//Ȩ��
	char 		Name[USER_NAME_LEN + 1];				//�û���
	char 		Password[USER_PASSWD_LEN + 1];			//�û�����
} USER_CONFIG;

//10���������ýṹ
typedef struct _NET_CONFIG
{	
	DWORD             	IPAddr ;						//IP��ַ
	DWORD             	SubNetMask ;					//����
	DWORD             	GateWay ;						//����

   	WORD             	ComPortNo;						//���ý��տͻ�������˿ں�        UDP	
   	WORD             	WebPortNo;						//Webserver�˿�     			  TCP
	DWORD             	MultiCastIPAddr ;				//�ಥIP��ַ
   	WORD             	MultiCastPortNo;				//UDP������ʼ�˿�<�ಥ����>
	
	BYTE			   	RT8139MAC[6];      				//�˹�����������MAC��ַ		5---0��Ч
   	BYTE             	DHCP;							//DHCP ����					0	��		1:��
   	
	BYTE             	PppoeOpen;						//PPPOE ����     	
	char				PppoeName[PPPPOE_NAME_LEN+1];	//�����û���
	char				PppoePass[PPPPOE_PASSWD_LEN+1]; //��������	
	DWORD             	PppoeTimes;   					//����ʱ��
	DWORD             	PppoeIPAddr ;					//PPPOEIP��ַ		�����ش�IP	
	
	DWORD				DdnsOpen;						//DDNS����
	char				DdnsName[DDNS_NAME_LEN+1];		//ע����������
	char				DdnsPass[DDNS_PASS_LEN+1];		//ע����������	
	
	char				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS������
	WORD				DdnsPortNo;						//DDNS�������˿�
	WORD				DdnsMapWebPort;					//����WEBӳ��˿�
	WORD				DdnsMapDataPort;				//��������ӳ��˿�

	DWORD				DNSHostIP;						//DNS��IP
	
	BOOL				ConnectCenter;					//�Ƿ�������������
	char				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//����IP
	WORD				ConnectCenterPort;						//���Ķ˿�

	WORD				appFunction;					//ʵ�ֹ��ܶ���,��bitλ��ʾ:0-PPPOE,1-NTP,2-UPNP,3-WF,4-MAIL,5-�����ͣ�6:-����̽ͷ 8-���洢����
	BYTE				tcpSendInterval;
	BYTE				udpSendInterval;
	WORD				PacketMTU;

	BYTE				CaptureMode;					//ץ��ģʽ
	BYTE				CapturePort[MAX_SENSOR_NUM];	//ץ��ͨ��(0-3bit: �ֱ��ʾ1 ~ 4��ͨ��  1:��  0: ��)

	union
	{
		DWORD			DdnsIP2;						//DDNS 2��IP,�������ֽڴ���
		DWORD			DNSHostIP2;						//DNS  2
	};

	WORD				DdnsPortNo2;					//DDNS 2�Ķ˿�

	char				sysByname[DVS_NAME_LEN+1];		//����
	BYTE				domainSetState;					//0���ɹ���1�����ִ��ڣ��޸���������2���������룻3��ʧ��
} NET_CONFIG;

//11��������Ϣ����
typedef struct _DEBUG_CONFIG
{
	BYTE				Status;							//0����		1: ��
}DEBUG_CONFIG;

//12������̵�������
typedef struct __OUTPUT_CTRL
{
	BYTE				ChannelNo;						//�̵�����	0 ~ MAX_OUTPUT_NUM - 1
	BYTE				Status;							//0����		1: ��	
}OUTPUT_CTRL;

//13����̨����
typedef struct __PAN_CTRL
{
	BYTE				ChannelNo;						//ͨ����	0 ~ PORTNUM - 1
	BYTE				COMMNo;							//���ں�	0 ~ 1
	BYTE				PanType;						//��̨Э����� 0 ~ YUNTAI_PROTOCOL_NUM - 1
	BYTE				PanCmd;							//��̨��������
	BYTE				Data1;							//����1		��Ԥ�á����úţ�
	BYTE				Data2;							//����2		�����ã�
}PAN_CTRL;

//14����Ƶ�źŲ���
typedef struct __VIDEO_SIGNAL_CONFIG
{
	BYTE				ChannelNo;						//ͨ����	0 ~ PORTNUM - 1
	BYTE 				ChannelNum;						//ͨ����<NVS�ܵ�ͨ��������Ϊ��·����·�Ĳ���Ĭ��ֵ�ǲ�ͬ��>
	BYTE 				Brightness;						//����
	BYTE 				Hue;							//ɫ��
	BYTE 				Saturation;						//���Ͷ�
	BYTE 				Contrast;						//�Աȶ�
}VIDEO_SIGNAL_CONFIG;

//15��TW2824����
typedef struct _TW2824_CTRL
{
	BYTE				Page;							//ҳ
	BYTE 				RegNo;							//�Ĵ���
	BYTE 				Data;							//����
	UINT				nReserved[8];					//����
}TW2824_CTRL;

//16��������Ϣ
typedef  struct  _ALARM_INFO
{
	BYTE	SensorAlarm[MAX_SENSOR_NUM];				//̽ͷ����
	BYTE	SensorAlarmOut[MAX_SENSOR_NUM];				//̽ͷ�������
	BYTE	MotionAlarm[MAX_VIDEO_NUM];					//��Ƶ�ƶ�
	BYTE	MotionAlarmOut[MAX_VIDEO_NUM];				//��Ƶ�ƶ��������
	BYTE	ViLoseAlarm[MAX_VIDEO_NUM];					//��Ƶ��ʧ
	BYTE	ViLoseAlarmOut[MAX_VIDEO_NUM];				//��Ƶ��ʧ�������
} ALARM_INFO;

//17����̨��Ϣ
typedef struct _YUNTAI_INFO
{
	char 		Name[YUNTAI_NAME_LEN + 1];				//��̨����
	COM_CONFIG	ComSet;									//ͨѶЭ��<������...>
}YUNTAI_INFO;

//18��������Ϣ
typedef struct _DVS_CONFIG
{
   	char               	sysName[DVS_NAME_LEN + 1];		//����
	BYTE				sysInputNum;					//·��
	BYTE				sysType;						//�����ͺ�	0:CIF  1:HD1  2:D1  
	BYTE				sysVideoFormat;					//�����ʽ	
    BYTE				sysLanguage;					//����
    BYTE				sysStandard;					//��ʽ		0:PAL  1:NTSC
	DWORD      			sysID;  						//ÿ̨�����и�ID��  	
	DWORD      			sysVer;  						//����汾  		
}DVS_CONFIG;

//19����¼���û��û���Ϣ
typedef struct _USER_DETAIL
{
	BOOL				bLogon;							//TRUE-��½�û�,FALSE-Ԥ���û�
	DWORD 				Level;							//Ȩ��
	char 				Name[USER_NAME_LEN+1];			//�û���
	char 				Password[USER_PASSWD_LEN+1];	//�û�����
	NET_PROTOCOL_TYPE	protocolType;					//Э��
	DWORD				clientIP;						//IP
	DWORD				clientPort;						//�˿�
}USER_DETAIL;

typedef struct _USER_INFO_HUANGHE
{
	DWORD				dwLogonNum;
	DWORD				dwPreviewNum;
	USER_DETAIL			userDetail[MAX_LOGON_NUM+MAX_LINKVIEW_NUM+MAX_MULTIVIEW_NUM];
}USER_INFO_HUANGHE;

//20��DDNS����
typedef struct _DDNS_SET
{
	BOOL				bDdnsStart;
	char				szDdnsIP[DDNS_SERVER_NAME_LEN+1];
	DWORD				dwDdnsPort;
	char				szDdnsName[DVS_NAME_LEN+1];
	DWORD				dwMapWebPort;
	DWORD				dwMapDataPort;
}DDNS_SET;

//21�����в�����Ϣ
typedef struct _DVS_Parameter 
{
   	char               	sysName[DVS_NAME_LEN + 1];		//����
	BYTE				sysInputNum;					//·��
	BYTE				sysType;						//�����ͺ�	0:CIF  1:HD1  2:D1  
	BYTE				sysVideoFormat;					//�����ʽ	
    BYTE				sysLanguage;					//����
    BYTE				sysStandard;					//��ʽ		0:PAL  1:NTSC
	DWORD      			sysID;  						//ÿ̨�����и�ID��  	
	DWORD      			sysVer;  						//����汾  			
	VIDEO_CONFIG		sysVideo[MAX_VIDEO_NUM];		//��Ƶ
	VIDEO_MOTION_CONFIG	sysVideoMotion[MAX_VIDEO_NUM];	//��Ƶ�ƶ�
	VIDEOMASK_CONFIG	sysVideoMask[MAX_VIDEO_NUM];	//��Ƶ����
	VIDEOLOSE_CONFIG	sysVideoLose[MAX_VIDEO_NUM];	//��Ƶ��ʧ
	AUDIO_CONFIG		sysAudio[MAX_AUDIO_NUM];		//��Ƶ
	NET_CONFIG			sysNet;							//��������
	COM_CONFIG			sysCom[MAX_COM_NUM];			//����
	SENSOR_CONFIG		sysSensor[MAX_SENSOR_NUM];		//���
	USER_CONFIG			sysUser[MAX_USER_NUM];			//�û�
	BYTE				YunTaiProtocolNum;				//��ͷЭ����
	YUNTAI_INFO 		YunTaiInfo[MAX_YUNTAI_PROTOCOL_NUM];//Э����Ϣ
} DVS_Parameter ;

//22��NTP����
typedef struct _NTP_CONFIG
{
	DWORD			ntpOpen;					//NTP����
	DWORD			ntpTimeZone;				//ʱ��
	char			ntpHost[DOMAIN_NAME_LEN];	//NTP Server
}NTP_CONFIG;

//23��UPNP����
typedef struct _UPNP_CONFIG
{
	WORD			upnpOpen;					//UPNP����
	BYTE			upnpEthNo;					//UPNP���� 0�����ߣ�1������
	BYTE			upnpMode;					//UPNPģʽ 0��ָ����1���Զ�
	WORD			upnpPortWeb;				//UPNP WEB�˿�
	WORD			upnpPortData;				//UPNP DATA�˿�
	DWORD			upnpHost;					//UPNP����
	WORD			upnpStatusWeb;				//UPNP WEB״̬
	WORD			upnpStatusData;				//UPNP DATA״̬
}UPNP_CONFIG;

//24��Email����
typedef struct _MAIL_CONFIG
{
	char			smtpServer[DOMAIN_NAME_LEN];	//���ͷ�����
	char			pop3Server[DOMAIN_NAME_LEN];	//���շ�����
	char			fromMailAddr[DOMAIN_NAME_LEN];	//�ʼ����͵�ַ
	char			toMailAddr[DOMAIN_NAME_LEN];	//�ʼ����յ�ַ
	char			ccMailAddr[DOMAIN_NAME_LEN];	//�ʼ����͵�ַ
	char			smtpUser[DOMAIN_NAME_LEN];		//SMTP �û���
	char			smtpPassword[DOMAIN_NAME_LEN];  //SMTP �û�����
	char			pop3User[DOMAIN_NAME_LEN];		//POP3 �û���
	char			pop3Password[DOMAIN_NAME_LEN];	//POP3 �û�����
		
	DWORD			motionMailOpen;					//��Ƶ�ƶ�����MAIL����
	DWORD			motionMail[MAX_VIDEO_NUM];		//��Ƶ�ƶ�����ץ�ķ���MAIL����
	DWORD			sensorMailOpen;					//̽ͷ��������MAIL����
	DWORD			sensorMail[MAX_SENSOR_NUM];		//̽ͷ��������ץ�ķ���MAIL����
	DWORD			viloseMailOpen;		

	DWORD			timeMailOpen;					//��ʱ����(/��)
	DWORD			timeVideoMail[MAX_VIDEO_NUM];	//��Ƶ��ʱץ�ķ���MAIL����
	
	char			subjectMail[EMAIL_TITLE_LEN];	//�ʼ�ͷ
	char			textMail[EMAIL_TITLE_LEN];		//�ʼ�����
		
	DWORD			sendMailCount;					//״̬: ���͵�email����	
	DWORD			sendNow;						//��������
	WORD			smtpPort;						//SMTP �˿�
	WORD			popPort;						//POP3 �˿�
	WORD			protocolType;					//SSL
	char			res[6];
}MAIL_CONFIG;

typedef enum _WF_AUTH_TYPE		//����֤��������
{
	WF_AUTH_NONE	= 0x00,
	WF_AUTH_WEP		= 0x01,
	WF_AUTH_WPA		= 0x02,
	WF_AUTH_WPA2	= 0x03,
	WF_AUTH_WPAWPA2	= 0x04,
}WF_AUTH_TYPE;


typedef enum _WF_ENC_TYPE		//������֤����
{
	WF_ENC_NONE		= 0x00,		//WEP  ����ϵͳ
	WF_ENC_WEP		= 0x01,		//WEP  �����ܳ�
	WF_ENC_TKIP		= 0x02,		//WEP  �Զ�ѡ��
	WF_ENC_AES		= 0x03,
}WF_ENC_TYPE;

//25��������������
typedef struct _WF_NET_CONFIG
{
	DWORD			dwSize;							//��С
	WORD			wfOpen;							//�Ƿ������
	WORD			dhcpOpen;						//DHCP����
	//
	DWORD			ipAddress;						//IP��ַ
	DWORD			subMask;						//��������
	DWORD			gateWay;						//����
	DWORD			dnsIP1;							//DNS������1 IP
	DWORD			dnsIP2;							//DNS������2 IP
	BYTE			macAddress[6];
	//
	BYTE			ssidLen;						//SSID���Ƴ���
	BYTE			pswLen;							//���볤��

	char			ssidName[34];					//SSID����
	char			pswText[34];					//����
	DWORD			channel;						//ͨ��
	DWORD			bps;							//����
	DWORD			type;
	BYTE			wfAuthType;						//����֤��������
	BYTE			wfEncType;						//������֤����
	char			reserve[10];
}WF_NET_CONFIG;

//26����������������ƶ���
typedef struct _ALARM_INOUT_NAME
{
	char			alarmInName[MAX_SENSOR_NUM][CAM_TITLE_LEN+2];	//̽ͷ��
	char			alarmOutName[MAX_OUTPUT_NUM][CAM_TITLE_LEN+2];	//���������
}ALARM_INOUT_NAME;

//27����Ƶ����������
typedef struct _SEND_DEST
{	
	DWORD			dwSet[MAX_VIDEO_NUM];			//���Ϳ���
	DWORD			dwStreamSend[MAX_VIDEO_NUM];	//���Ϳ���
	DWORD			dwStreamDestIP[MAX_VIDEO_NUM];	//Ŀ��IP,�����ֽ�˳��
	DWORD			dwStreamDestPort[MAX_VIDEO_NUM];//Ŀ�Ķ˿�
	char			res[16];
}SEND_DEST;

//28���Զ�����ע��
typedef struct _AUTO_RESET_TIME
{
	BYTE			open;				//bit 1:hour,bit 2:day,bit 3:week	
	BYTE			second;
	BYTE			minute;
	BYTE			hour;
	BYTE			week;				//0 �����գ�1 ����һ��2 ���ڶ� 

	BYTE			res[3];
}AUTO_RESET_TIME;

//29��¼�����
//��HH52ϵ����ʹ��
//��HH58��HH98ϵ���в���ʹ��
typedef struct _CH_RECORD_CONFIG		//sizeof() = 84
{
	WORD 			KeepTime;			//ĳ��ͨ����¼���ļ���������
	WORD     		reserve;
	TIME_SEGMENT	tSchTable1[8] ;		//ĳ��ͨ���Ķ�ʱ¼��ʱ���1 (40)
	TIME_SEGMENT	tSchTable2[8] ;		//ĳ��ͨ���Ķ�ʱ¼��ʱ���2 (40)
}CH_RECORD_CONFIG;

typedef struct _RECORD_CONFIG_HUANGHE			//sizeof() = 360
{
	BYTE		 PackageTime;	  		//�ļ����ʱ��
	BYTE 		 OverWrite;        		//auto overwrite 
	BYTE     	 reserve[22];
	CH_RECORD_CONFIG ChRecordCfg[MAX_VIDEO_NUM];//ͨ����¼�����(336)
}RECORD_CONFIG_HUANGHE;

//30��������Ϣ
//��HH58��HH98ϵ��������ṹ����4���ֽ�
typedef struct _DISK_INFO
{
	DWORD	DiskNum;					//���̸���
	BYTE	DiskType[8];				//��������
	DWORD	TotalSize[8];				//�����ܿռ��С
	DWORD	FreeSize[8];				//����ʣ��ռ�
	BYTE	Reserved[8];				//BYTE	Reserved[4];	2008.9.23
}DISK_INFO;

//31�����̲���
typedef struct _DISK_MANAGE
{
	BYTE	Cmd;
	BYTE	Data;
	BYTE	Reserved[126];
}DISK_MANAGE;

//32�����̸�ʽ������
typedef struct _DISK_FORMAT_PROCESS
{
	DWORD	DiskType;					//��������
	DWORD	Status;						//��ʽ��״̬
	DWORD	Process;					//����()
	DWORD	Reserved[5];
}DISK_FORMAT_PROCESS;


//33����չ��Ϣ�ṹ
typedef struct _EXTINFO_CONFIG
{
	DWORD			nSize;						//�ṹ��С(1328)

	NTP_CONFIG		ntpConfig;					//ntp
	
	UPNP_CONFIG		upnpConfig;					//upnp
		
	MAIL_CONFIG		mailConfig;					//MAIL
	
	ALARM_INOUT_NAME alarmInOutName;			//ALARM IN/OUT NAME
	
	WF_NET_CONFIG	wfConfig;					//WF NETWORK
	
	SEND_DEST		sendDest;					//SEND DEST
	
	AUTO_RESET_TIME autoResetTime;				//AUTO RESET 

	//��HH5800ϵ���У����ṹ�ﲻ�ٰ���recordConfig��diskInfo
	//��HH5800ϵ����, FTP_CONFIG ftpCfg;	char reserve[48];  
	//��HH5800ϵ���У�ʹ���½ṹEXTINFO_CONFIG_NEW(�޸Ķ��壬 ��С��ԭ�ṹ��ͬ�� ��������Ҳ��ͬ)
	//RECORD_CONFIG	recordConfig;				//RECORD CONFIG
	DISK_INFO		diskInfo;					//DISK INFO
	char			reserve[28];				//diskInfo + 4, here - 4
}EXTINFO_CONFIG;

//34���û�����
typedef struct __USERDATA_CONFIG
{
	int		nDataLen;
	char	userData[252];
}USERDATA_CONFIG;

//=================================================================================
//��HH5800ϵ�м�֮��ϵ�ж������½ṹ
//=================================================================================
typedef  struct  _DVS_TIME
{
	BYTE		year ;
	BYTE		month ;
	BYTE		day ;
	BYTE		week ;
	BYTE		hour   ;
	BYTE		minute ;
	BYTE		second ;
	BYTE		millisecond;							
} DVS_TIME, *PDVS_TIME;

typedef struct _TIME_SEGMENT_NEW 
{
	DWORD 		bDetectOpen;				//��⿪��
	BYTE        nBgnHour ;					//��ʼʱ
	BYTE        nBgnMinute ;				//��ʼ��
	BYTE        nEndHour ;					//����ʱ
	BYTE        nEndMinute ;				//������
}TIME_SEGMENT_NEW;

//=======================================
//������������
//=======================================
typedef struct _ALARM_LINKAGE 
{
	DWORD 		Output;						//�����������				     bit.0---bit.3	
	DWORD 		AutoClearTime;		        //�����Զ����ʱ��	

	DWORD 		Record_PC;					//PC�˱�������¼��ͨ��			 bit.0---bit.3
	DWORD 		Record_Dev;					//�豸�˱�������¼��ͨ��		 bit.0---bit.3
	DWORD		RecordSvaeMode;				//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email
	DWORD		RecordTime;					//����¼��ʱ��(��)

	DWORD		ShootSaveMode;				//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email
	DWORD		ShootChns;					//ץ��ͨ��(bit.0 ~ bit.3)
	DWORD		ShootNum;					//����ץ������()
	float		ShootInterval;				//����ץ��ʱ����(��)  0: ����ץ��

	DWORD		EMail;						//����email
	DWORD		Reserved;					//����
} ALARM_LINKAGE;

//=======================================
//��Ƶ����(��)
//=======================================
typedef struct _HH_OSD_CTRL_ST
{
	DWORD		Show;						//0: ��  1: ��
	WORD		X;							//x��y����ʾ��λ�ã���λ�õķ�ΧΪ0-704��0-576����ͼ��ķֱ����޹أ�x����Ϊ4�ı�����
	WORD		Y;
} HH_OSD_CTRL_ST ;

typedef struct _HH_VENC_CTRL_ST
{
	DWORD       Open;						//�Ƿ������루��������
	DWORD		EncType;					//�����㷨
	DWORD		EncFormat;					//�����ʽ(D1, HD1, CIF)
	DWORD		Width;						//���
	DWORD		Height;						//�߶�
	
	DWORD		KeyInterval;			    //I ֡���
	DWORD		Bitrate ;					//����
	float		FrameRate ;					//֡��float
	DWORD		BitflowType; 			    //��������(0:VBR, 1:CBR)
	DWORD		Qulity;						//����0--5
	DWORD       Reserved[8];
} HH_VENC_CTRL_ST ;

//=======================================
//ץ��ͼƬ����
//=======================================
typedef struct _PICTURE_CONFIG				//sizeof() = 148
{
	DWORD		dwSize;						//���ṹ����

	DWORD     	EncType;					//ץͼ��ʽ(.jpg, bmp) 
	DWORD     	EncFormat;					//ͼƬ��������(24λ�� 32λ) 
	DWORD     	Width;
	DWORD     	Height;

	BYTE     	reseved[44];
}PICTURE_CONFIG;

//��Ƶ���
typedef struct _VIDEO_SIZE
{
	WORD		Width;						//��
	WORD		Height;						//��
}VIDEO_SIZE;

//�豸֧�ֵı����ʽ�Ϳ��
typedef struct _SUPPORT_AV_FMT
{
	DWORD		dwSize;						//���ṹ����
	
	DWORD		MainVideoFmt[8];			//�����������ʽ
	DWORD		MinVideoFmt[8];				//�����������ʽ
	DWORD		PictureFmt[8];				//ͼƬ�����ʽ

	VIDEO_SIZE  MainVideoSize[8];			//������ ����	
	VIDEO_SIZE  MinVideoSize[8];			//������ ����	
	VIDEO_SIZE  PictureSize[8];				//ͼƬ ����	

	DWORD		AudioFmt[8];				//��Ƶ�����ʽ
	DWORD		AudioSampleRate[8];			//��Ƶ������
	DWORD		AudioBitrate[8];			//��Ƶ����
	DWORD		AuidoAEC;					//�Ƿ�֧�ֻ�������

	BYTE     	reserve[32];	
}SUPPORT_AV_FMT;


//��Ƶ����
typedef struct _VIDEO_CONFIG_NEW
{
	DWORD			dwSize;					//���ṹ����

	HH_VENC_CTRL_ST stMainVEncCtrl;			//����������
	HH_VENC_CTRL_ST stMinVEncCtrl;			//����������
	PICTURE_CONFIG	stPictureCfg;			//ץ��ͼƬ����

	HH_OSD_CTRL_ST	stDateOSD; 				// 0:����������,   1:��������
	HH_OSD_CTRL_ST	stTimeOSD; 				// 0:������ʱ��,   1:����ʱ��
	HH_OSD_CTRL_ST	stWeekOSD; 				// 0:����������,   1:�������� 
	HH_OSD_CTRL_ST	stTitleOSD;				// 0:�����ӱ���,   1:���ӱ��� 
	HH_OSD_CTRL_ST	stBitrateOSD;			// 0:����������,   1:�������� 	
	
	char    	Title[CAM_TITLE_LEN_NEW];	//�����ַ�(64���ַ�  31������)

    BYTE 		Brightness;				    //����
	BYTE 		Hue;						//ɫ��
	BYTE 		Saturation;				    //���Ͷ�
	BYTE 		Contrast;					//�Աȶ�

	WORD 		Protocol;					//Э����(0 ~ MAX_PAN_PROTOCOL_NUM - 1)
	WORD 		YTAddr;						//��������ַ

	BYTE		mtClear;
	BYTE		mtRed;
	BYTE		mtBlue;
	BYTE		mtGamma;
	
	BYTE        reseved[28];
}VIDEO_CONFIG_NEW;

typedef struct _AREA_RECT
{
	WORD		X;							//X����	
	WORD		Y;							//Y����
	WORD		W;							//���
	WORD		H;							//�߶�
} AREA_RECT;

//=======================================
//�ƶ��������(��)
//=======================================
typedef struct _VIDEOMOTION_CONFIG_NEW
{
	DWORD			dwSize;						//���ṹ����

	DWORD 			DetectLevel;			    //�ƶ����������
	DWORD 			DetectOpen;				    //�ƶ���⿪��

	AREA_RECT		DetectArea[9];				//�ƶ��������			

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //�ƶ����ʱ���1				 0: ÿ��
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //�ƶ����ʱ���1				 0: ÿ��

	ALARM_LINKAGE	stAlarmLink;				//��������

	BYTE			reseved[128];
}VIDEOMOTION_CONFIG_NEW ;

//=======================================
//ͼ����������(��) ���ȣ��Ͻṹ��������������
//=======================================
typedef struct _VIDEOMASK_CONFIG_NEW
{
	BYTE 			MaskOpen;					//��Ƶ���ο���		0:��         1����
	BYTE			AA[3];
	AREA_RECT		MaskArea[9];				//��Ƶ��������		
}VIDEOMASK_CONFIG_NEW;

//=======================================
//��Ƶ��ʧ����(��)
//=======================================
typedef struct _VIDEOLOSE_CONFIG_NEW
{
	DWORD			dwSize;						//���ṹ����

	DWORD			DetectOpen;					//��Ƶ��ʧ���

	ALARM_LINKAGE	stAlarmLink;				//��������

	BYTE			reseved[32];
} VIDEOLOSE_CONFIG_NEW;

//=======================================
//̽ͷ�����������(��)
//=======================================
typedef struct _SENSOR_CONFIG_NEW 
{
	DWORD			dwSize;						//���ṹ����

	DWORD			SensorType;					//0:����̽ͷ	1:����̽ͷ
	DWORD 			DetectOpen;				    //��⿪��

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��

	ALARM_LINKAGE	stAlarmLink;				//��������

	BYTE			reseved[32];
}SENSOR_CONFIG_NEW;

//=======================================
//����̽ͷ����
//=======================================
typedef struct _RF_ALARM_CONFIG
{
	DWORD			dwSize;						//���ṹ����

	DWORD			SensorType;					//0:����̽ͷ	1:����̽ͷ
	DWORD 			DetectOpen;				    //��⿪��

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //̽ͷ���ʱ��1				     0: ÿ��

	ALARM_LINKAGE	stAlarmLink;				//��������

	BYTE			reseved[32];
}RF_ALARM_CONFIG;


//=======================================
//������߱�������
//=======================================
typedef struct _NET_ALARM_CONFIG 
{
	DWORD			dwSize;						//���ṹ����

	DWORD 			DetectOpen;				    //��⿪��
	
	ALARM_LINKAGE	stAlarmLink;				//��������

	BYTE			reseved[32];
} NET_ALARM_CONFIG;

//=======================================
// FTP ����������
//=======================================
typedef struct __FTP_CONFIG
{
    char			ftpURL[64];
    char			ftpPath[64];
    DWORD			ftpPort;
    char			ftpUser[32];
    char			ftpPsw[32];

    char			ftpURL2[64];
    char			ftpPath2[64];
    DWORD			ftpPort2;
    char			ftpUser2[32];
    char			ftpPsw2[32];

    char			res[32];
}FTP_CONFIG;

//=======================================
//��ý�����
//=======================================
typedef struct _MEDIA_SERVER
{
	BYTE				bRtspOpen;
	BYTE				bMmsOpen;
	WORD				rtspPort;
	WORD				mmsPort;
	WORD				res;
}MEDIA_SERVER;

//suncz 20090602
typedef struct _GPS_INFO
{
	BYTE		bGpsOpen;
	BYTE		gpsStatus;
	WORD		serverPort;
	DWORD		serverIP;
	BYTE		bGpsOSD;
	BYTE		gpsPlatform;
	BYTE		phoneNum[11];
	BYTE		res[3];
}GPS_INFO;
//24.0 ��չ��Ϣ�ṹ(�޸Ķ��壬 ��С��ԭ�ṹ��ͬ�� ��������Ҳ��ͬ)
typedef struct _EXTINFO_CONFIG_NEW
{
	DWORD				nSize;						//�ṹ��С(1328)

	NTP_CONFIG			ntpConfig;					//ntp
	
	UPNP_CONFIG			upnpConfig;					//upnp
		
	MAIL_CONFIG			mailConfig;					//MAIL
	
	ALARM_INOUT_NAME	alarmInOutName;				//ALARM IN/OUT NAME
	
	WF_NET_CONFIG		wfConfig;					//WF NETWORK
	
	SEND_DEST			sendDest;					//SEND DEST
	
	AUTO_RESET_TIME		autoResetTime;				//AUTO RESET 

	FTP_CONFIG			ftpCfg;						//FTP ����������

	MEDIA_SERVER		mediaServer;			//��ý�����

	GPS_INFO			gpsInfo;				//GPS ��Ϣ,

	char				reserve[16];  
	//char				reserve[40];  
}EXTINFO_CONFIG_NEW;

//=======================================
//����̽ͷ
//=======================================
typedef struct _RF_KEY_CONFIG
{
	unsigned char		rf_close;
	unsigned char		rf_help_key;
	unsigned char		rf_alarm_noset;
	unsigned char		rf_disconnect_vidio;

	unsigned char		rf_res[32];
}RF_KEY_CONFIG;

//=======================================
//��ʱ¼��
//=======================================
typedef struct _CH_TIMER_RECORD_CONFIG		//sizeof() = 140
{
	WORD					KeepTime;								//��������(��)
	WORD					RecordSvaeMode;							//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email
	DWORD					reserve[2];

	TIME_SEGMENT_NEW		tSchTable1[8] ;							//ĳ��ͨ���Ķ�ʱ¼��ʱ���1 (64)
	TIME_SEGMENT_NEW		tSchTable2[8] ;							//ĳ��ͨ���Ķ�ʱ¼��ʱ���2 (64)
}CH_TIMER_RECORD_CONFIG;	

typedef struct _TIMER_RECORD_CONFIG			//sizeof() = 592
{
	BYTE					PackageTime;	  						//���ʱ��(����)
	BYTE 					OverWrite;        						//�Զ�����
	BYTE     				MainVEnc;								//¼����� 0: ������  1: ������
	BYTE     				CheckDisk;								//ϵͳ����ʱ���д���ɨ��
	BYTE     				reserve[28];

	CH_TIMER_RECORD_CONFIG	ChRecordCfg[MAX_VIDEO_NUM];				//ͨ����¼�����(140 * 4 = 560)
}TIMER_RECORD_CONFIG;


//=======================================
//��ʱץ��
//=======================================
typedef struct _CH_TIMER_SHOOT_CONFIG		//sizeof() = 140
{
	WORD 					KeepTime;								//��������(��)
	WORD					ShootSaveMode;							//bit0 ���ش洢  bit1 ftp�ϴ�  bit2 email

	DWORD					ShootNum;								//����ץ������()
	float					ShootInterval;							//����ץ��ʱ����(��)  0: ����ץ��

	TIME_SEGMENT_NEW		tSchTable1[8] ;							//ĳ��ͨ���Ķ�ʱץ��ʱ���1 (40)
	TIME_SEGMENT_NEW		tSchTable2[8] ;							//ĳ��ͨ���Ķ�ʱץ��ʱ���2 (40)
}CH_TIMER_SHOOT_CONFIG;

typedef struct _TIMER_SHOOT_CONFIG			//sizeof() = 592
{
	BYTE 					OverWrite;								//�Զ�����
	BYTE     				reserve[31];

	CH_TIMER_SHOOT_CONFIG	ChShootCfg[MAX_VIDEO_NUM];				//ͨ����¼�����(92 * 4 = 368)
}TIMER_SHOOT_CONFIG;

//=======================================
//������չ����(��ƽ̨������������)
//=======================================
typedef struct __EXT_DATA_CONFIG
{
	DWORD		nSize;					//�ṹ��С
	DWORD		nType;	
    DWORD		nDataLen;
    char		szData[512];
}EXT_DATA_CONFIG;

//=======================================
//��־��ѯ
//=======================================
typedef struct _FIND_LOG_S
{
	DWORD		nSize;					//�ṹ��С
	DWORD		nSelectMode;			//��ѯ��ʽ:0��ȫ����1�������ͣ�2����ʱ�䣬3����ʱ�������
	DWORD		nType;					//��������
    DVS_TIME	stStartTime;
	DVS_TIME	stEndTime;
}FIND_LOG_S;

typedef struct _LOG_ITEM_S
{
	DWORD		nSize;					//�ṹ��С
	DWORD		nAlarmType;				//��������
	DWORD       nChn;					//ͨ���š����߱�����IP��ַ
	DVS_TIME	tAlarmTime;	
	char		szNote[12];
}LOG_ITEM_S;

//=======================================
//�豸���в�����sizeof = 10248��
//=======================================
typedef struct _DVS_Parameter_New
{
	DWORD					dwSize;						//���ṹ����

    char                    sysName[DVS_NAME_LEN + 4];

	BYTE					sysInputNum;		        //·��
	BYTE					sysType;			        //�����ͺ�	0:CIF  1:HD1  2:D1  
	BYTE					sysVideoFormat;		        //�����ʽ	0:D1,1:HD1,2:CIF,3:VGA 4:HVGA 5:CVGA 6:QCIF 7:QVGA
    BYTE					sysLanguage;		        //����

    DWORD					sysStandard;		        //��ʽ		0:PAL  1:NTSC

    DWORD      				sysID;  	                //ÿ̨�����и�ID
	DWORD      				sysVer;  	                //����汾  

	VIDEO_CONFIG_NEW	    sysVideo[MAX_VIDEO_NUM];	
	VIDEOMOTION_CONFIG_NEW	sysVideoMotion[MAX_VIDEO_NUM];
	VIDEOMASK_CONFIG_NEW    sysVideoMask[MAX_VIDEO_NUM];	
	VIDEOLOSE_CONFIG_NEW    sysVideoLose[MAX_VIDEO_NUM];	
	AUDIO_CONFIG		    sysAudio[MAX_AUDIO_NUM];
	NET_CONFIG			    sysNet;
	COM_CONFIG			    sysCom[MAX_COM_NUM];
	SENSOR_CONFIG_NEW	    sysSensor[MAX_SENSOR_NUM];
	USER_CONFIG			    sysUser[MAX_USER_NUM];

    EXTINFO_CONFIG_NEW		sysExtConfig;				//��չ����

	DISK_INFO				DiskInfo;					//�洢�豸��Ϣ

	TIMER_RECORD_CONFIG		TimerRecordCfg;
	TIMER_SHOOT_CONFIG		TimerShootCfg;				//��ʱץ�Ĳ���

	RF_ALARM_CONFIG			rfAlarmCfg[MAX_RF_SENSOR_NUM];	//����̽ͷ����
	NET_ALARM_CONFIG		netAlarmCfg;					//������߱���

	USERDATA_CONFIG			userData;					//�û�����

	DWORD					YunTaiProtocolNum;
	YUNTAI_INFO 			YunTaiInfo[MAX_PTZ_PROTOCOL_NUM];	

	BYTE					reserved[256];				//����

} DVS_Parameter_New;

//=======================================
//GPS��Ϣadd by huangtao
//=======================================
typedef struct _REALTIME_GPS_STATUS
{
	BYTE  nDevId[4];
	BYTE  nEastJin;    //1����  0���� 
	BYTE  nJinDu[9];   //���� 12345678 ǰ��λΪ����λ
	BYTE  nNorthWei;   //1��γ  0��γ  
	BYTE  nWeiDu[8];   //γ�� 1234567  ǰ��λΪ����λ
	BYTE  nGpsPW   ;   //gps ��Դ״̬ 1����   0����
	BYTE  nGpsDW   ;   //gps �Ƿ�λ 1�Ѷ�λ 0δ��λ
	BYTE  nAccStatus;  //Acc״̬ 1 ACC�� 0 ACC��
	BYTE  nGpsTX   ;   //����״̬ 1 �������� 0 �����쳣
	BYTE  nSpeed;      //�ٶ� 
	BYTE  nLiCheng[9]; //���
	BYTE  res;
	WORD  nDirection;  //����
	BYTE  tag[16];
}REALTIME_GPS_STATUS;

//add by huangtao
typedef struct _GPS_MSG_NOTIFY
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	REALTIME_GPS_STATUS		gpsStatus;
}GPS_MSG_NOTIFY;


//����1
typedef struct _CONFIG_ENCPAR
{ 
    DWORD u32PicWidth;   
    DWORD u32PicHeight;     
    DWORD u32CapSel; 
    DWORD u32StaticParam; 
    DWORD u32TargetBitrate; 
    DWORD u32TargetFramerate; 
    DWORD u32Gop;             
    DWORD u32MaxQP;        
    DWORD u32PreferFrameRate; 
    DWORD u32Strategy; 
    DWORD u32VencMode;        
    DWORD u32BaseQP;         
    DWORD u32MaxBitRate;   
}CONFIG_ENCPAR; 

//����2
typedef struct _PING_CONFIG
{
	BOOL	bPingOpen;
	BOOL	bDisconnectReboot;
	BOOL	bDisconnectAlarm;
	DWORD	dwPingNum;
	DWORD   dwPingPeriod;
	char	szPingServer[64];
}PING_CONFIG;

//���������
typedef struct _HH_DOOM_AUTOSCAN	
{
	BYTE   nPresetNo[16];		//0: û����	 Ԥ�õ��(1 ~ 255)
	WORD   nKeepTime[16];		//ͣ��ʱ��(0 ~ 3600��)	
	char   szReserved[8];		
}HH_DOOM_AUTOSCAN;

//������������
typedef struct _HH_DOOM_CONFIG	//sizeof = 248
{
	//����ͷ����
	DWORD			dwSize;					//�ṹ��С

	BYTE			bZoomSpeed;     		//�䱶�ٶȿ���		0 ����    1 �����ٶ�  			
	BYTE			bFocusManl;       		//�������			0 �Զ�    1 �ֶ�				
	BYTE			bIrisCtrl;        		//��Ȧ����			0 �Զ�    1 �ֶ�

	BYTE			bAWB;         			//��ƽ�����		0 �Զ�    1 �ֶ�				
	WORD			nAWBRed;     			//��ƽ��			R gain	  0 ~ 255	
	WORD			nAWBBlue;     			//��ƽ�� 			B gain	  0 ~ 255

	BYTE			bBLC;         			//���ⲹ��			1 ��  	  0 ��
	BYTE			nBLCValue;     			//���ⲹ��					  0 ~ 255
	BYTE			bWDRMode;     			//��̬ģʽ		1 ��  	  0 ��				
	BYTE			bMirror;      			//����				1 ��      0 ��				

	BYTE			bImageMode;   			//ͼ��ģʽ			0 ģʽһ  1 ͼ��ģʽ��	
	BYTE			bIRCFMode;    			//IRcfģʽ			0 OUT=>IN 1 IN=>OUT      		
	BYTE			bIRLight;     			//�����			0 ������  1 850mm   2 950mm 		
	BYTE			nPgmAE;       			//Program AE
	
	DWORD			nShutterPriValue;		//Shutter priority  ����ֵ����	1/1=1    1/2=2   ���� 1/10000=10000 //����
	DWORD			nExposurePriValue;		//Exposure priority	����ֵ����	F1.6=16  F2.2=22 ���� F34.0=340//�ع�
	DWORD			nAGCPriValue;			//AGC priority		����ֵ����	0dB=0    6dB=6   ���� 30dB=30//�Զ�����

	BYTE			nVideoHZ;               //(0)50HZ (1)60HZ (2)OUT DOOR

	//��̨����
	BYTE			bAutoFlip;				//�Զ���ת			   			1 ��  	0 ��
	BYTE			bAutoSpeed;				//�����������		 			1 ��  	0 ��
	BYTE			bManualLimit;			//�ֶ���λ			 			1 ��  	0 ��
	
	BYTE			bScanLimit;				//ɨ����λ			 			1 ��  	0 ��
	BYTE			bAux1;					//��������һ		 			1 ��  	0 ��
	BYTE			bAux2;					//�������ض�		 			1 ��  	0 ��
	BYTE			nHSpeed;				//ˮƽɨ���ٶ�		 			1 - 40������
	
	BYTE			nVSpeed;				//����ɨ���ٶ�		 			1 - 20������
	BYTE			nWatchMode;				//����λģʽ		        	0  ��
											//	  			                1  Ԥ��λ1   																																																												
											//	  			                2  Ԥ��λ2   																																																												
											//	  			                3  Ԥ��λ3   																																																												
											//	  			                4  Ԥ��λ4   																																																												
											//	  			                5  Ԥ��λ5   																																																												
											//	  			                6  Ԥ��λ6   																																																												
											//	  			                7  Ԥ��λ7   																																																												
											//	  			                8  Ԥ��λ8   																																																												
											//	  			                9  �Զ�ɨ��  																																																												
											//	  			                10 ��ƻ��ɨ�� 																																																												
											//	  			                11 Ԥ��λѲ��1																																																												
											//	 			                12 Ԥ��λѲ��2		
	BYTE			nWatchTime;				//����λ��ʱ��	        	2-60��
	BYTE			nReserved;				//����

	HH_DOOM_AUTOSCAN	szDoomAutoScan[2];	//Ԥ��λѲ��
	TIME_SEGMENT_NEW	tSchTable[5];		//��ʱ����

	char				szReserved[52];		//����
}HH_DOOM_CONFIG;

//------------------------------------------------------��-------------------//
//------------------------------(II)�������������ýṹ-----------------------//
//------------------------------------------------------��-------------------//
//1��ϵͳʱ��
typedef  struct  _DD_NVD_DATE
{
	BYTE		year;									//��
	BYTE		month;									//��
	BYTE		day;									//��
	BYTE		week;									//��
	BYTE		hour;									//Сʱ
	BYTE		minute;									//��
	BYTE		second;									//��
}DD_NVD_DATE, *PDD_NVD_DATE;

//2��ϵͳ����
typedef struct _DD_SYSTEM_PARAM 
{
   	char               	Name[DVS_NAME_LEN + 1];			//����
	BYTE				Type;							//�����ͺ�	0:CIF  1:HD1  2:D1  
    BYTE				Language;						//����
    BYTE				Standard;						//��ʽ		0:PAL  1:NTSC
	DWORD      			ID;  	        				//ÿ̨�����и�ID��  	
	DWORD      			RS485Addr;       				//RS485��ַ  		
	DWORD      			RS485Func;       				//RS485����  			
	DWORD      			RS485Baud;       				//RS485������  			
	DWORD      			Version;         				//����汾  
	BYTE      			RemoteID;         				//ң��ID��  	
	BYTE				Audio;							//��������	
	BYTE				TimeOn;							//ʱ����ʾ����				
	BYTE				DispMode;						//��ʾģʽ(1�����桢4�Ļ���)
	BYTE				ImageQulity;					//����ͼ������
	BYTE				Reserve[31];					//����
}DD_SYSTEM_PARAM;

//3���������
typedef struct _DD_NET_CONFIG
{
	DWORD             	IPAddr ;						//IP��ַ
	DWORD             	SubNetMask ;					//����
	DWORD             	GateWay ;						//����

   	WORD             	ComPortNo;						//���ý��տͻ�������˿ں�        UDP	
   	WORD             	WebPortNo;						//Webserver�˿�     			  TCP
	DWORD             	MultiCastIPAddr ;				//�ಥIP��ַ
   	WORD             	MultiCastPortNo;				//UDP������ʼ�˿�<�ಥ����>
	
	BYTE			   	RT8139MAC[6];      				//�˹�����������MAC��ַ		5---0��Ч
   	BYTE             	DHCP;							//DHCP ����					0	��		1:��
   	
   	WORD             	PppoeOpen;						//PPPOE ����         	
	DWORD             	PppoeIPAddr ;					//PPPOEIP��ַ �������ش�IP��
	char				PppoeName[PPPPOE_NAME_LEN+1];	//�����û���
	char				PppoePass[PPPPOE_PASSWD_LEN+1];	//��������		
	
	DWORD				DdnsOpen;						//DDNS����
	char				DdnsName[DDNS_NAME_LEN+1];		//ע����������
	char				DdnsPass[DDNS_PASS_LEN+1];		//ע����������	
	
	char				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS������
	WORD				DdnsPortNo;						//DDNS�������˿�
	WORD				DdnsMapWebPort;					//����WEBӳ��˿�
	WORD				DdnsMapDataPort;				//��������ӳ��˿�

	DWORD				DNSHostIP;						//DNS��IP
	
	BOOL				ConnectCenter;					//�Ƿ�������������
	char				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//����IP
	WORD				ConnectCenterPort;						//���Ķ˿�

	WORD				appFunction;
	BYTE				tcpSendInterval;
	BYTE				udpSendInterval;
	WORD				PacketMTU;

	BYTE				CaptureMode;					//ץ��ģʽ
	BYTE				CapturePort[MAX_SENSOR_NUM];	//ץ��ͨ��(0-3bit: �ֱ��ʾ1 ~ 4��ͨ��  1:��  0: ��)

	DWORD				DdnsIP2;						//DDNS 2��IP,�������ֽڴ���
	WORD				DdnsPortNo2;					//DDNS 2�Ķ˿�

	char				sysByname[DVS_NAME_LEN+1];		//����
	BYTE				NetReserve[1];					//����
} DD_NET_CONFIG ;

//4����������
typedef struct __DD_COM_PARAM
{
	DWORD 				Baudrate;						//���ڲ�����				300---115200
	BYTE				Databit;						//��������λ����			5=5λ 6=6λ 7=7λ 8=8λ	����=8λ
	BYTE				Stopbit;						//ֹͣλλ��				1=1λ 2=2λ ����=1λ
	BYTE				CheckType;						//У��						0=��  1=��  2=ż  3=��1  4=��0 
	BYTE				Flowctrl; 						//������/Ӳ����/������		����
}DD_COM_CONFIG;

//5��ͼ�����
typedef struct _DD_IMAGE_PARAM
{
	BYTE 	Bright;										// ����
	BYTE 	Shades;										// ɫ��
	BYTE 	Contrast;									// �Աȶ�
	BYTE 	Saturate;									// ���Ͷ�
	BYTE 	MenuBright;									// �˵�����
}DD_IMAGE_CONFIG;

//6����������
typedef struct __DD_ALARMOUT_PARAM
{
	BYTE 				Open;							//��������<0: ��  1: ��>
	BYTE				SensorAlarm[4];					//̽ͷ��������	.0 ~ 3 1--4��̽ͷ	0,1λ: �ֱ��ʾ�̵���1 2��״̬  <0: ��  1: ��>
	BYTE				MotionAlarm[4];					//��Ƶ�ƶ�����	.0 ~ 3 1--4��̽ͷ	0,1λ: �ֱ��ʾ�̵���1 2��״̬  <0: ��  1: ��>
	BYTE				ViLoseAlarm[4];					//��Ƶ��ʧ����	.0 ~ 3 1--4��̽ͷ	0,1λ: �ֱ��ʾ�̵���1 2��״̬  <0: ��  1: ��>
	BYTE				Reserve[8];						//����	
}DD_ALARMOUT_CONFIG;

//7���û�����
typedef struct _DD_USER_CONFIG
{
	DWORD 		Level;									//Ȩ��
	char 		Name[USER_NAME_LEN + 1];				//�û���
	char 		Password[USER_PASSWD_LEN + 1];			//�û�����
} DD_USER_CONFIG;

//8��������Ϣ��Ŀ
typedef struct __DD_ALARM_ITEM
{
	DWORD 				IPAddr;							//IP
	char				URL[DD_URL_ADDR_LEN + 1];		//URL��ַ
	DWORD				ComPortNo;						//ͨѶ�˿�
	DD_NVD_DATE			AlarmTime;						//����ʱ��
	BYTE				SensorAlarm;					//̽ͷ��������	.0 ~ 3 1--4��̽ͷ	<0: �ޱ���  1: �б���>
	BYTE				MotionAlarm;					//��Ƶ�ƶ�����	.0 ~ 3 1--4����Ƶ	<0: �ޱ���  1: �б���>
	BYTE				ViLoseAlarm;					//��Ƶ��ʧ����	.0 ~ 3 1--4����Ƶ	<0: �ޱ���  1: �б���>
	BYTE				Reserve[8];						//����
}DD_ALARM_ITEM;

//9��������Ϣ��¼
typedef struct __DD_ALARM_INFO
{
	WORD				Count;							//������¼����
	DD_ALARM_ITEM		Alarms[DD_MAX_ALARMINFO_NUM];	//������¼����
}DD_ALARM_INFO;

//10����ַ��
typedef struct __DD_ADDRBOOK_PARAM
{
	char				Name[DDNS_NAME_LEN + 1];			//����
	char				URL[DD_URL_ADDR_LEN + 1];		//URL��ַ
	WORD             	ComPortNo;						//ͨѶ�˿�
	BYTE				ChannelNo;						//ͨ����
	BYTE				Protocol;						//0: TCP  1:�ಥ   2:UDP
	BYTE				DNSOpen;						//0: ��   1:��
	WORD				StayTime;						//ͣ��ʱ��	5--3600��
	BYTE				AutoLink;						//�Զ�����	0:��  1:��
	BYTE				AudioOpen;						//������	0:��  1:��	
	BYTE				TalkOpen;						//�Խ���	0:��  1:��
	char				UserName[USER_NAME_LEN + 1];	//�û���
	char				UserPass[USER_PASSWD_LEN + 1];	//�û�����	
	BYTE				Reserve[8];						//����	
}DD_ADDRBOOK_CONFIG;

//11��͸��ͨѶ
typedef struct __DD_COMM_CTRL
{
	BYTE				COMMNo;							//���ں�	0 ~ 1
	COM_CONFIG			COMConfig;						//��������
	WORD				DataLength;						//���ݳ���
	BYTE				Data[256];						//����
}DD_COMM_CTRL;

//12��������������ṹ
typedef struct __DD_DEVICE_CTRL
{
	BYTE				CMD;							//����
	BYTE 				Data1;							//����1
	BYTE 				Data2;							//����2
	DWORD				nReserved[8];					//����
}DD_DEVICE_CTRL;

//13����̨��Ϣ
typedef struct _DD_PROTOCOL_INFO
{
	char 		Name[YUNTAI_NAME_LEN + 1];				//��̨����
	BYTE		Exist;									//�Ƿ����
	BYTE		nReserved[8];							//����
}DD_PROTOCOL_INFO;

//14����̨����
typedef struct _DD_YUNTAI_SET
{
	char 		Name[YUNTAI_NAME_LEN + 1];				//��̨����
	BYTE 		YTAddr;									//��������ַ
	COM_CONFIG	ComSet;									//ͨѶЭ��<������...>
	BYTE		nReserved[8];							//����
}DD_YUNTAI_SET;

//15��ϵͳ���в���(�������ò��������紫����)
typedef struct _DD_NVD_CONFIG 
{
	DD_SYSTEM_PARAM 		sysParam;					//ϵͳ����
	DD_NET_CONFIG			sysNet;						//��������
	DD_COM_CONFIG			sysCom[MAX_COM_NUM];		//��������
	DD_IMAGE_CONFIG			sysImage;					//ͼ�����
	DD_USER_CONFIG			sysUser[MAX_USER_NUM];		//�û�
	DD_ALARMOUT_CONFIG		sysAlarmOut;				//�������
		
	DD_PROTOCOL_INFO 		YunTaiInfo[MAX_VIDEO_NUM];	//��̨��Ϣ
	DD_YUNTAI_SET 			YunTaiSet[MAX_VIDEO_NUM];	//��̨Э������		
} DD_NVD_CONFIG ;

//16����չ��Ϣ�ṹ
typedef struct _DD_EXTINFO_CONFIG
{
	DWORD			nSize;						//�ṹ��С

	//ntp
	NTP_CONFIG		ntpConfig;

	//upnp
	UPNP_CONFIG		upnpConfig;
	
	//MAIL
	MAIL_CONFIG		mailConfig;

	//ALARM IN/OUT NAME
	ALARM_INOUT_NAME alarmInOutName;

	//WF NETWORK
	WF_NET_CONFIG	wfConfig;

	//SEND DEST
	SEND_DEST		sendDest;
	
	char			reserve[480];
}DD_EXTINFO_CONFIG;

#ifdef __cplusplus
}
#endif


#endif



