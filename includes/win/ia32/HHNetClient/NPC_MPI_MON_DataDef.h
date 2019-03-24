/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_DataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-08
 * Description   :  ��ؿͻ���ͨѶ�ӿڶ���
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_DATADEF_H
#define __NPC_MPI_MON_DATADEF_H

#include "NPC_TypeDef.h"
#include "NPC_MON_DataDef.h"
#include "NPC_MON_VendorDef.h"
#include "NPC_MPI_MON_VarDataDef.h"
//#include "vld.h"

//�������붨��
#ifdef _WIN32
	#ifdef _NPC_MPI_MON_EXPORTS
		#define NPC_MPI_MON_API __declspec(dllexport)
	#else
		#ifdef _NPC_MPI_MON_IMPORT
			#define NPC_MPI_MON_API __declspec(dllimport)
		#else
			#define NPC_MPI_MON_API
		#endif
	#endif
#else
	#define NPC_MPI_MON_API
#endif


//��������
#define NPC_D_MPI_MON_CH_NAME_BUFSIZE							128			//ͨ������������С
#define NPC_D_MPI_MON_DEVID_BUFSIZE								NPC_D_MON_NODEID_BUFSIZE	//�豸ID��������С
#define NPC_D_MPI_MON_CAMERANAME_BUFSIZE						64			//��������ƻ�������С
#define NPC_D_MPI_MON_CAMERA_DIRNAME_BUFSIZE					128			//�����Ŀ¼����������С
#define NPC_D_MPI_MON_NODENAME_BUFSIZE							32			//������ƻ�������С
#define NPC_D_MPI_MON_MAX_ERROR_BUFSIZE							512			//��������Ϣ��������С
#define NPC_D_MPI_MON_MAX_USER_POP_NUM							64			//����û�Ȩ����
#define NPC_D_MPI_MON_MAX_USER_DEVPOP_NUM						64			//����û��豸Ȩ����
#define NPC_D_MPI_MON_MAX_VENDOR_CP_FIELD_NUM					8			//��������Ӳ����ֶ���
#define NPC_D_MPI_MON_NODENAME_BUFSIZE							32			//�������������С
#define NPC_D_MPI_MON_USERID_BUFSIZE							32			//�û�ID��������С
#define NPC_D_MPI_MON_MAX_ALARM_NOTIFY_NUM						20			//��󱨾�֪ͨ��
#define NPC_D_MPI_MON_MAX_ALARM_ACTION_NUM						6			//��󱨾�������
#define NPC_D_MPI_MON_SEARCH_MAX_ADAPTER_NUM					5			//���������

//����ģʽ����
#define NPC_D_MPI_MON_COM_CONNMODE_DIRECT						0			//ֱ��ģʽ���������Զ�IP��ַ�Ͷ˿ڣ�ֱ�����ӶԶ�
#define NPC_D_MPI_MON_COM_CONNMODE_SERVER						1			//����������ģʽ�����ɷ������������ӶԶˣ�����ΪNAT����ת��ֱ����

//�豸Ŀ¼�������
#define NPC_D_MPI_MON_DEV_NODE_TYPE_DIR							0			//Ŀ¼��
#define NPC_D_MPI_MON_DEV_NODE_TYPE_DVR							1			//DVR
#define NPC_D_MPI_MON_DEV_NODE_TYPE_CAMERA						2			//�����
#define NPC_D_MPI_MON_DEV_NODE_TYPE_IPC							3			//IPC

//�豸���״̬
#define NPC_D_MPI_MON_DEV_NODE_STATE_OFFLINE					0			//����
#define NPC_D_MPI_MON_DEV_NODE_STATE_ONLINE						1			//����

//������Ϣ����
#define NPC_D_MPI_MON_PUSH_TYPE_CONFIG							1			//���ò���
#define NPC_D_MPI_MON_PUSH_TYPE_ORDER							2			//��������������
#define NPC_D_MPI_MON_PUSH_TYPE_PROMPT							3			//������������ʾ��Ϣ
#define NPC_D_MPI_MON_PUSH_TYPE_DEVN_UPDATE_NODE				4			//�����������豸��������½�㣨��ӡ��޸ģ�
#define NPC_D_MPI_MON_PUSH_TYPE_DEVN_DEL_NODE					5			//�����������豸�����ɾ����㣨�豸��Ŀ¼
#define NPC_D_MPI_MON_PUSH_TYPE_UPDATE_GPOP						6			//����������ȫ��Ȩ�ޱ��
#define NPC_D_MPI_MON_PUSH_TYPE_DEV_ALARM						7			//�����������豸������Ϣ
#define NPC_D_MPI_MON_PUSH_TYPE_DEV_ALARM_VILLAGE				8			//�����������豸������Ϣ��С��������
#define NPC_D_MPI_MON_PUSH_TYPE_REQU_REFRESH_DEVLIST			9			//�����ϲ�ˢ���豸�б�
//#define NPC_D_MPI_MON_PUSH_TYPE_PWD_MODIFYED					10			//���뱻�����û��޸�
#define NPC_D_MPI_MON_PUSH_TYPE_RE_LOGIN_NOTIFY					10			//���µ�¼֪ͨ
#define NPC_D_MPI_MON_PUSH_TYPE_ANNO_MSG						11			//���������͹�����Ϣ

//�ͻ�������״̬
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_NO_CONNECT				0			//δ���ӷ�����
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_CONNECTING				1			//�������ӷ�����
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_CONNECT_OK				2			//�����ӷ�������δ��¼
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_LOGIN_OK				3			//�ѵ�¼״̬����������
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_DISCONNECT				4			//���ӶϿ�״̬

//���������״̬
#define NPC_D_MPI_MON_CAMERA_CONN_STATE_NO_CONNECT				0			//δ����״̬
#define NPC_D_MPI_MON_CAMERA_CONN_STATE_CONNECTING				1			//�������������
#define NPC_D_MPI_MON_CAMERA_CONN_STATE_CONNECT_OK				2			//�����Ӳ���¼״̬
#define NPC_D_MPI_MON_CAMERA_CONN_STATE_DISCONNECT				3			//���ӶϿ�״̬���Ͽ�ԭ��ο�NPC_D_MPI_MON_CAMERA_DISCAUSE_*����

//���������״̬������ʵʱԤ�����¼��طţ�
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_NOPLAY					0			//δ����״̬
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_PLAYING					1			//���ڲ���״̬
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_PAUSE					2			//��ͣ״̬
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_OPENING					3			//���ڴ򿪲���
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_REJECT_ACCESS			4			//��Ȩ��

//�ͻ��˶Ͽ�����ԭ��
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_PEER_CLOSE				1			//�Զ˹ر�����
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_LOGIN_FAIL				2			//��¼ʧ�ܶ��Ͽ�����
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_RECV_ERR_PACK				3			//���յ��������ݰ������������ر�����
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_RESP_TIMEOUT				4			//�ȴ�Ӧ����Ϣ��ʱ�����������ر�����
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_HEART_TIMEOUT				5			//�ȴ�����Ӧ����Ϣ��ʱ�����������ر�����

//������Ͽ�����ԭ��
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_PEER_CLOSE				1			//�Զ˹ر�����
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_LOGIN_FAIL				2			//��¼ʧ�ܶ��Ͽ�����
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_RECV_ERR_PACK				3			//���յ��������ݰ������������ر�����
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_RESP_TIMEOUT				4			//�ȴ�Ӧ����Ϣ��ʱ�����������ر�����
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_HEART_TIMEOUT				5			//�ȴ�����Ӧ����Ϣ��ʱ�����������ر�����
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_NON_MEDIA_DATA			6			//��ʱ����ý���������������ر�����
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_DEV_DISCONNECT			7			//�豸�˶Ͽ�������
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_USERNAME_ERROR			8			//�û�������
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_PWD_ERROR					9			//�������
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_USERNAMEPWD_ERROR			10			//�û������������
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_DEV_OFFLINE				11			//�豸����

//����������ļ�״̬
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_INIT					0			//��ʼ״̬
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_OPENING					1			//���ڴ�״̬
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_DOWNING					2			//��������״̬
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_DOWN_OVER				3			//�������״̬
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_OPEN_FAIL				4			//��ʧ��״̬

//���µ�¼��ԭ����
#define NPC_D_MPI_MON_RELOGIN_CAUSE_USER_ERROR					1			//�û�������
#define NPC_D_MPI_MON_RELOGIN_CAUSE_PWD_ERROR					2			//�������
#define NPC_D_MPI_MON_RELOGIN_CAUSE_USER_OR_PWD_ERROR			3			//�û������������
#define NPC_D_MPI_MON_RELOGIN_CAUSE_ACCOUNT_NO_ACTIVE			4			//�û��ʺ�δ����
#define NPC_D_MPI_MON_RELOGIN_CAUSE_HAVE_EXPIRED				5			//�û��ʺ��ѹ���Ч��
#define NPC_D_MPI_MON_RELOGIN_CAUSE_CLIENTID_NOT_ALLOW_LOGIN	6			//�ͻ���ID�������¼
#define NPC_D_MPI_MON_RELOGIN_CAUSE_REJECT_LOGIN				7			//�ܾ���¼��IP��ַ�������¼��
#define NPC_D_MPI_MON_RELOGIN_CAUSE_OTHER						99			//����ԭ��

//�豸���ӷ�����״̬����
#define NPC_D_MPI_MON_DEV_SRV_CONN_STATE_NON_CONNECT			0			//δ����
#define NPC_D_MPI_MON_DEV_SRV_CONN_STATE_CONNECTING				1			//��������
#define NPC_D_MPI_MON_DEV_SRV_CONN_STATE_CONNECT_OK				2			//������
#define NPC_D_MPI_MON_DEV_SRV_CONN_STATE_CONNECT_FAIL			3			//����ʧ��

//�豸���ӷ�������ʧ���붨��
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_SUCCESS			0			//�ɹ�
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_DNS_FAIL			1			//��������ʧ�ܣ�����Ϊ�豸δ���빫����������������
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_CONN_SRV_FAIL		2			//���ӷ�����ʧ�ܣ�����Ϊ������δ���У����߷���ǽ��ֹ��ͨѶ��
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_LOGIN_AUTH_FAIL	3			//��¼��֤ʧ�ܣ�������UMIDδ��Ȩ������֤�����
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_UMID_REGISTERED	4			//UMID�Ѿ�ע�ᣨUMID�������豸ע�ᵽ��������
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_OTHER_FAIL			99			//����ʧ��

//�����붨��
#define NPC_D_MPI_MON_ERROR_SUCCESS								0			//�ɹ�

#define NPC_D_MPI_MON_ERROR_SYS_ERROR							1			//ϵͳ����
#define NPC_D_MPI_MON_ERROR_CONNECT_FAIL						2			//����ʧ��
#define NPC_D_MPI_MON_ERROR_DBACCESS_FAIL						3			//�������ݿ�ʧ��
#define NPC_D_MPI_MON_ERROR_ALLOC_RES_FAIL						4			//������Դʧ��
#define NPC_D_MPI_MON_ERROR_INNER_OP_FAIL						5			//�ڲ�����ʧ�ܣ����ڴ����ʧ��
#define NPC_D_MPI_MON_ERROR_EXEC_ORDER_CALL_FAIL				6			//ִ���������ʧ��
#define NPC_D_MPI_MON_ERROR_EXEC_ORDER_RET_FAIL					7			//ִ��������ʧ��
#define NPC_D_MPI_MON_ERROR_FILE_NONENTITY						8			//�ļ�������
#define NPC_D_MPI_MON_ERROR_OTHER_FAIL							9			//����ԭ��ʧ��
#define NPC_D_MPI_MON_ERROR_NET_ERROR							10			//�������
#define NPC_D_MPI_MON_ERROR_REDIRECT							11			//����������ͻ����ض���
#define NPC_D_MPI_MON_ERROR_PARAM_ERROR							12			//���������ʽ����
#define NPC_D_MPI_MON_ERROR_ERROR_FUNCID						13			//����Ĺ���ID��Ϣ
#define NPC_D_MPI_MON_ERROR_MSG_PAST_TIME						14			//����ϢID�ѹ�ʱ����������
#define NPC_D_MPI_MON_ERROR_SYS_NO_GRANT						15			//ϵͳδ��Ȩ
#define NPC_D_MPI_MON_ERROR_DNS_FAIL							16			//��������ʧ��
#define NPC_D_MPI_MON_ERROR_USERNAME_FORMAT_ERROR				17			//�û�����ʽ����
#define NPC_D_MPI_MON_ERROR_RESP_TIMEOUT						18			//�ȴ�Ӧ����Ϣ��ʱ
#define NPC_D_MPI_MON_ERROR_PROTOCOL_ERROR						19			//Э�����

#define NPC_D_MPI_MON_ERROR_USERID_ERROR						101			//�û�ID���û�������
#define NPC_D_MPI_MON_ERROR_USERPWD_ERROR						102			//�û��������
#define NPC_D_MPI_MON_ERROR_USER_PWD_ERROR						103			//�û������������
#define NPC_D_MPI_MON_ERROR_CONNECTING							104			//��������
#define NPC_D_MPI_MON_ERROR_CONNECTED							105			//������
#define NPC_D_MPI_MON_ERROR_PLAY_FAIL							106			//����ʧ��
#define NPC_D_MPI_MON_ERROR_NO_CONNECT_CAMERA					107			//δ���������
#define NPC_D_MPI_MON_ERROR_PLAYING								108			//���ڲ���
#define NPC_D_MPI_MON_ERROR_NO_PLAY								109			//δ����
#define NPC_D_MPI_MON_ERROR_NONSUP_VENDOR						110			//��֧�ֵĳ���
#define NPC_D_MPI_MON_ERROR_REJECT_ACCESS						111			//Ȩ�޲���
#define NPC_D_MPI_MON_ERROR_CAMERA_OFFLINE						112			//���������
#define NPC_D_MPI_MON_ERROR_ACCOUNT_LOGINED						113			//�ʺ��ѵ�¼
#define NPC_D_MPI_MON_ERROR_ACCOUNT_HAVE_EXPIRED				114			//�û��ʺ��ѹ���Ч��
#define NPC_D_MPI_MON_ERROR_ACCOUNT_NO_ACTIVE					115			//�û��ʺ�δ����
#define NPC_D_MPI_MON_ERROR_ACCOUNT_DEBT_STOP					116			//�û��ʺ���Ƿ��ͣ��
#define NPC_D_MPI_MON_ERROR_USER_EXIST							117			//�û���ע��
#define NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_NOPERM				118			//������ע�ᣨ������ɱ��У�
#define NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_ATBLACK				119			//������ע�ᣨ�ں������У�
#define NPC_D_MPI_MON_ERROR_SECCODE_HAVE_EXPIRED				120			//��֤���ѹ���
#define NPC_D_MPI_MON_ERROR_SECCODE_ERROR						121			//��֤�����
#define NPC_D_MPI_MON_ERROR_ACCOUNT_EXIST						122			//�ʺ��Ѵ���
#define NPC_D_MPI_MON_ERROR_NO_IDLE_STREAMSERVER				123			//�޿�����ý�������
#define NPC_D_MPI_MON_ERROR_USER_NO_LOGIN						124			//�û�δ��¼
#define NPC_D_MPI_MON_ERROR_ACCOUNT_LEN_ERROR					125			//�ʺų��ȴ���
#define NPC_D_MPI_MON_ERROR_EMP_ACC_USERID_NOT_EXIST			126			//������Ȩ���û�ID������
#define NPC_D_MPI_MON_ERROR_IPADDR_BAN_LOGIN					127			//IP��ַ��ֹ��¼
#define NPC_D_MPI_MON_ERROR_CLIENTID_NOT_ALLOW_LOGIN			128			//�ͻ���ID�������¼
#define NPC_D_MPI_MON_ERROR_TIMESECT_NOT_ALLOW_CAMERA			129			//��ʱ��β�������ʸ������
#define NPC_D_MPI_MON_ERROR_VOD_FILE_NOT_EXIST					130			//VOD�ļ�������
#define NPC_D_MPI_MON_ERROR_REJECT_LOGIN						131			//�ܾ���¼
#define NPC_D_MPI_MON_ERROR_OBJ_NOT_EXIST						132			//��ѯ���󲻴���
#define NPC_D_MPI_MON_ERROR_NO_SUBSCRIBE						133			//û�ж���
#define NPC_D_MPI_MON_ERROR_RESOURCE_USED						134			//��Դ�ѱ�ռ��
#define NPC_D_MPI_MON_ERROR_RESOURCE_NOT_OPEN					135			//��Դ��δ����
#define NPC_D_MPI_MON_ERROR_SUCCESS_AND_RESTART					136			//�����ɹ�������Ҫ�����豸����Ч
#define NPC_D_MPI_MON_ERROR_OPNO_DEVGROUP						137			//�豸���µĽ�㲻�ܲ���
#define NPC_D_MPI_MON_ERROR_RESOURCE_NO_IDLE					138			//�޿�����Դ��ʹ��
#define NPC_D_MPI_MON_ERROR_RESOURCE_NOT_EXIST					139			//��Դ������
#define NPC_D_MPI_MON_ERROR_RESOURCE_OPEN_FAIL					140			//����Դʧ��
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_OP						141			//��֧�ָò���
#define NPC_D_MPI_MON_ERROR_BAN_MODIFY							142			//��ֹ�޸�
#define NPC_D_MPI_MON_ERROR_OPEN_STREAM_FAIL					143			//��ý����ʧ�ܣ���ʵʱԤ��ʧ�ܣ�
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_SUBSTREAM				144			//��֧�ָ�������
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_PTZ						145			//��֧����̨����
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_FORCE_I_FRAME			146			//��֧��ǿ��I֡
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_TALK					147			//��֧�������Խ�
#define NPC_D_MPI_MON_ERROR_FILE_OP_FAIL						148			//�ļ�����ʧ��
#define NPC_D_MPI_MON_ERROR_ID_ERROR							149			//ID����
#define NPC_D_MPI_MON_ERROR_CHANNEL_NO_ERROR					150			//ͨ���Ŵ���
#define NPC_D_MPI_MON_ERROR_SUB_STREAM_NO_ERROR					151			//�������Ŵ���
#define NPC_D_MPI_MON_ERROR_START_TALK_FAIL						152			//�����Խ�ʧ��



//�Զ�������뷶Χ��6150~6179����ӦЭ��Ĵ�����Ϊ150~179�����ô������ȥ6000�������豸�˷��صĴ���ֵ


//-------------------------------------------------------------------------------------
//ͨ����Ϣ����
typedef struct _NPC_S_MPI_MON_CHANNEL_INFO
{	
	NPC_CHAR									sDevId[NPC_D_MPI_MON_DEVID_BUFSIZE];			//�豸ID
	NPC_INT										iChNo;											//ͨ���ţ����Ϊ0xFFFFFFFF��ʾ����ͨ������ʱ�������ͨ������ֻ�����ò�������
	NPC_CHAR									sChName[NPC_D_MPI_MON_CH_NAME_BUFSIZE];			//ȫΪ0�Ͳ�������ʾ��������
	NPC_INT										iRecordBitRate;									//¼��λbit�����������10��ֵ ������ 1�� 2�� 3��
	NPC_INT										iVideoBitRate;									//Ԥ����λbit�����������10��ֵ ������ 1�� 2�� 3��
	NPC_BYTE									ucRecordFramesize;								//byte 1 2 3 4 5 �ֱ��Ӧqcif qvga cif hd1 d1
	NPC_BYTE									ucRecordFrameRate;								//֡�� 1-25
	NPC_BYTE									ucVideoFramesize;								//byte 1 2 3 4 5 �ֱ��Ӧqcif qvga cif hd1 d1
	NPC_BYTE									ucVideoFrameRate;								//֡�� 1-25
	NPC_BYTE									ucAlarmonordown;								//0Ϊ�ر� 1Ϊ��
	NPC_BYTE									ucVideoPorn;									//0ΪP�� 1ΪN�� ��ʱ����
	NPC_BYTE									ucSupportSize[5];								//SupportSize[0]����qcif �����֧�־�����Ϊ1��֧������Ϊ0 �Դ����� ��������豸���ظ��ͻ������ã��ͻ������õ�DVR�ϲ������
	NPC_BYTE									ucReserve[2];

} NPC_S_MPI_MON_CHANNEL_INFO, *PNPC_S_MPI_MON_CHANNEL_INFO;

//֡���ݶ���
typedef struct _NPC_S_MPI_MON_MEDIA_FRAME
{
	NPC_S_MON_MEDIA_FRAME_HEAD					tMediaHead;										//ý��ͷ

	PNPC_BYTE									pMediaDataBuf;									//ý�����ݻ�����
	NPC_INT										iMediaDataLen;									//ý�����ݳ���

} NPC_S_MPI_MON_MEDIA_FRAME, *PNPC_S_MPI_MON_MEDIA_FRAME;

//�������ݶ���
typedef struct _NPC_S_MPI_MON_ALARM_HEAD
{
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//�豸ID
	NPC_INT										iAlarmType;										//�������ͣ��μ�NPC_D_MON_ALARM_TYPE_*����
	NPC_S_TD_DATE_TIME							tAlarmTime;										//����ʱ��
	NPC_INT										iAlarmState;									//����״̬��0����ʼ��1��ֹͣ
	NPC_DWORD									dwParam1;										//��չ����1
	NPC_DWORD									dwParam2;										//��չ����2

} NPC_S_MPI_MON_ALARM_HEAD, *PNPC_S_MPI_MON_ALARM_HEAD;

//�������ݶ���
typedef struct _NPC_S_MPI_MON_ALARM_DATA
{
	NPC_S_MPI_MON_ALARM_HEAD					tAlarmHead;										//����ͷ

	PNPC_CHAR									pAlarmInfoBuf;									//������Ϣ������
	NPC_INT										iAlarmInfoLen;									//������Ϣ����

} NPC_S_MPI_MON_ALARM_DATA, *PNPC_S_MPI_MON_ALARM_DATA;

//¼���ļ����ݶ���
typedef struct _NPC_S_MPI_MON_REC_FILE
{
	NPC_CHAR									sFileName[NPC_D_MON_FILENAME_BUFSIZE];			//�ļ���
	NPC_DWORD									dwFileSize;										//�ļ���С
	NPC_DWORD									dwFileType;										//�ļ����ͣ��μ�NPC_D_MON_REC_FILE_TYPE_*����
	NPC_S_TD_DATE_TIME							tStartTime;										//�ļ���ʼʱ��
	NPC_S_TD_DATE_TIME							tEndTime;										//�ļ�����ʱ��
	NPC_DWORD									dwRecTimeLen;									//�ļ�ʱ�䣨�룩
	NPC_USHORT									usFileFormat;									//�ļ���ʽ���μ�NPC_D_MON_FILE_FORMAT_*����
	NPC_USHORT									usParam1;										//��չ����1
	NPC_DWORD									dwParam2;										//��չ����2

} NPC_S_MPI_MON_REC_FILE, *PNPC_S_MPI_MON_REC_FILE;

//�豸�������
typedef struct _NPC_S_MPI_MON_DEV_NODE
{
	NPC_DWORD									dwNodeId;										//���ID��ֵ����0
	NPC_DWORD									dwParentNodeId;									//�ϼ����ID�����Ϊ0����ʾ��ѯ������
	NPC_INT										iNodeType;										//������ͣ��μ�NPC_D_MPI_MON_DEV_NODE_TYPE_*����
	NPC_BYTE									ucNodeKind;										//������࣬���ڽ����ʾ��ͼ�����ֵ࣬��0��ʼ
	NPC_USHORT									usVendorId;										//����ID
	NPC_BYTE									ucNodeOwnerType;								//����������ͣ�0���û�ID��1���豸��ID��2����Ȩ�豸
	NPC_CHAR									sNodeName[128];									//��ʾ����
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//�豸ID���������ID��

	NPC_BYTE									ucIfPtz;										//�Ƿ�֧��PTZ��0����֧��PTZ��1��֧��PTZ
	NPC_BYTE									ucIfVocTalk;									//�Ƿ�֧�������Խ���0����֧�������Խ���1��֧�������Խ�
	NPC_BYTE									ucIfLongLat;									//�Ƿ����þ�γ�ȣ�0��δ���þ�γ�ȣ�1�������þ�γ�ȣ�ֵ�ο�iLongitude��iLatitude�ֶ�
	NPC_BYTE									ucDevState;										//�豸״̬��0�����ߣ�1������
	NPC_BYTE									ucIfRecording;									//�Ƿ���¼��0��δ¼��1����¼��
	NPC_BYTE									ucIfArming;										//�Ƿ񲼷���0��δ������1���Ѳ���
	NPC_BYTE									ucReserve2[2];									//����2

	NPC_INT										iLongitude;										//���ȣ���6λΪС�����֣�����Ϊ�������֣�ֵ��ΧΪ-180000000~180000000
	NPC_INT										iLatitude;										//γ�ȣ���6λΪС�����֣�����Ϊ�������֣�ֵ��ΧΪ-90000000~90000000
	NPC_BYTE									ucDevPopTable[NPC_D_MPI_MON_MAX_USER_DEVPOP_NUM];	//�û��Ը��豸��Ȩ�ޣ����ֵΪ0��ʾû��Ȩ�ޣ�ֵ�ο�NPC_D_MPI_MON_USER_POP_����
	NPC_INT										iDevPopNum;										//�豸Ȩ����
	NPC_INT										iPromptId;										//��ʾ��ϢID��ֵ����0��Ϊ0��ʾû����ʾ��Ϣ

} NPC_S_MPI_MON_DEV_NODE, *PNPC_S_MPI_MON_DEV_NODE;

//PTZ��������
typedef struct _NPC_S_MPI_MON_PTZ_NAME
{
	NPC_INT										iPtzType;										//PTZ���ͣ�0��Ԥ�õ㣬1��Ѳ��·��
	NPC_INT										iPtzIndex;										//PTZ�ţ���Ԥ�õ�Ż�Ѳ��·���ţ�Ԥ�õ��ֵ��ΧΪ1��255��Ѳ��·����ֵ��ΧΪ1��32
	NPC_CHAR									sPtzName[32];									//PTZ���ƣ�ָԤ�õ��Ѳ��·�������ƣ����15�����ֻ�31���ַ�

} NPC_S_MPI_MON_PTZ_NAME, *PNPC_S_MPI_MON_PTZ_NAME;

//�豸��Ϣ
typedef struct _NPC_S_MPI_MON_DEV_INFO
{
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//�豸ID���������ID��
	NPC_INT										iConnMode;										//����ģʽ���μ�NPC_D_MON_DEV_CONN_MODE_*����
	NPC_DWORD									dwVendorId;										//����ID
	NPC_CHAR									sConnParam[NPC_D_MON_DEV_CONN_PARAM_BUFSIZE];	//���Ӳ���
	NPC_CHAR									sDevPlace[512];									//�豸λ��
	NPC_BOOL									bIfPtz;											//�Ƿ�֧��PTZ
	NPC_BOOL									bIfLongLat;										//�Ƿ����þ�γ��
	NPC_INT										iLongitude;										//���ȣ���6λΪС�����֣�����Ϊ�������֣�ֵ��ΧΪ-180000000~180000000
	NPC_INT										iLatitude;										//γ�ȣ���6λΪС�����֣�����Ϊ�������֣�ֵ��ΧΪ-90000000~90000000
	NPC_INT										iDevState;										//�豸״̬,0:����,1:����
	NPC_BOOL									bIfRecording;									//�Ƿ���¼��
	NPC_BOOL									bIfRealplaying;									//�Ƿ���ʵʱԤ��

} NPC_S_MPI_MON_DEV_INFO, *PNPC_S_MPI_MON_DEV_INFO;

//�豸�б�������
typedef struct _NPC_S_MPI_MON_DEV_LIST_ITEM
{
	NPC_DWORD									dwVendorId;										//����ID
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//�豸ID���������ID��

} NPC_S_MPI_MON_DEV_LIST_ITEM, *PNPC_S_MPI_MON_DEV_LIST_ITEM;

//�û���¼��������
typedef struct _NPC_S_MPI_MON_USER_LOGIN_PR_IN_PARAM
{
	NPC_INT										iClientType;									//�ͻ������ͣ��μ�NPC_D_MON_CLIENT_TYPE_*����
	NPC_CHAR									sDevVendorName[32];								//�豸��������
	NPC_CHAR									sDevName[32];									//�豸��Ʒ����
	NPC_CHAR									sDevModel[32];									//�豸�ͺ�
	NPC_CHAR									sDevVersion[32];								//�豸�汾��
	NPC_CHAR									sDevCPUModel[32];								//�豸CPU�ͺ�
	NPC_DWORD									dwDevMemorySize;								//�豸�ڴ��С��MB��
	NPC_DWORD									dwDevStorageSize;								//�豸�洢��С��MB������Ӳ�̻�����
	NPC_CHAR									sDevNetInfo[32];								//�豸������Ϣ
	NPC_CHAR									sDevParam1[32];									//�豸����1
	NPC_CHAR									sDevParam2[32];									//�豸����2
	NPC_CHAR									sDevParam3[32];									//�豸����3
	NPC_CHAR									sDevInfo[64];									//�豸������Ϣ

	NPC_CHAR									sClientOwner[32];								//�ͻ���ʹ����
	NPC_CHAR									sClientLanguage[32];							//�ͻ������ԣ��磺Ӣ�ģ�English���������ģ�SimpChinese
	NPC_CHAR									sClientCustomFlag[32];							//�ͻ��˶��Ʊ�ʶ
	NPC_CHAR									sClientToken[128];								//�ͻ���TOKEN

	NPC_CHAR									sReserve[224];									//����

	NPC_CHAR									sClientVerNo[32];								//�ͻ�������汾��

} NPC_S_MPI_MON_USER_LOGIN_PR_IN_PARAM, *PNPC_S_MPI_MON_USER_LOGIN_PR_IN_PARAM;

//�û���¼���ظ�������
typedef struct _NPC_S_MPI_MON_USER_LOGIN_PR_OUT_PARAM
{
	NPC_BOOL									bIfAllPop;										//�Ƿ���ȫ��Ȩ��
	NPC_BYTE									ucUserPopTable[NPC_D_MPI_MON_MAX_USER_POP_NUM];	//�û�Ȩ�ޣ�NPC_D_MPI_MON_MAX_USER_POP_NUM
	NPC_INT										iUserPopNum;									//�û�Ȩ����

} NPC_S_MPI_MON_USER_LOGIN_PR_OUT_PARAM, *PNPC_S_MPI_MON_USER_LOGIN_PR_OUT_PARAM;

//�ͻ������ò���
typedef struct _NPC_S_MPI_MON_CLIENT_CONFIG_PARAM
{
	NPC_BYTE									ucEnable_UserReg;								//�Ƿ��ṩ�û�ע�Ṧ�ܣ�0�����ã�1������
	NPC_BYTE									ucEnable_UserUnreg;								//�Ƿ��ṩ�û�ע�����ܣ�0�����ã�1������
	NPC_BYTE									ucEnable_Tryout;								//�Ƿ��ṩ���ù��ܣ�0�����ã�1������
	NPC_BYTE									ucEnable_DevManager;							//�Ƿ��ṩ�豸�����ܣ�0�����ã�1������
	NPC_BYTE									ucEnable_PTZ;									//�Ƿ��ṩ��̨���ƹ��ܣ�0�����ã�1������
	NPC_BYTE									ucReserve[3];									//����

	NPC_CHAR									sTryAccount[32];								//�����ʺ�

} NPC_S_MPI_MON_CLIENT_CONFIG_PARAM, *PNPC_S_MPI_MON_CLIENT_CONFIG_PARAM;

//�ͻ������ò���
typedef struct _NPC_S_MPI_MON_CLIENT_CONFIG_DATA
{
	NPC_DWORD									dwParamId;										//����ID���μ�NPC_D_MPI_MON_CLIENT_CFGID_*����
	NPC_CHAR									sParamName[64];									//������
	NPC_INT										iDataType;										//�������ͣ�0�����ͣ�1�������ͣ�2���ַ�����

	NPC_INT										iValueInteger;									//����ֵ
	NPC_DOUBLE									dValueDouble;									//����ֵ
	NPC_CHAR									sValueString[64];								//�ַ���ֵ

} NPC_S_MPI_MON_CLIENT_CONFIG_DATA, *PNPC_S_MPI_MON_CLIENT_CONFIG_DATA;

//�ͻ������ò���
typedef struct _NPC_S_MPI_MON_CLIENT_CONFIG_DATA_V2
{
	NPC_CHAR									sParamName[64];									//������
	NPC_CHAR									sParamValue[128];								//����ֵ

} NPC_S_MPI_MON_CLIENT_CONFIG_DATA_V2, *PNPC_S_MPI_MON_CLIENT_CONFIG_DATA_V2;

//�������ö���
typedef struct _NPC_S_MPI_MON_CLIENT_VENDOR_CFG_DATA
{
	NPC_DWORD									dwVendorId;										//����ID
	NPC_CHAR									sVendorName[32];								//��������
	NPC_DWORD									dwProVendorId;									//��Ӧ��Э�鳧��ID
	NPC_BYTE									ucReserve[64];									//����

} NPC_S_MPI_MON_CLIENT_VENDOR_CFG_DATA, *PNPC_S_MPI_MON_CLIENT_VENDOR_CFG_DATA;

//�豸��ʾ��Ϣ
typedef struct _NPC_S_MPI_MON_DEV_PROMPT
{
	NPC_INT										iPromptId;										//��ʾ��ϢID
	NPC_CHAR									sPromptMsg[64];									//��ʾ��Ϣ

} NPC_S_MPI_MON_DEV_PROMPT, *PNPC_S_MPI_MON_DEV_PROMPT;

//���Ӳ����ֶζ���
typedef struct _NPC_S_MPI_MON_CONNPARAM_FIELD_DATA
{
	NPC_DWORD									dwVendorId;										//����ID
	NPC_CHAR									sShowName[32];									//��ʾ��
	NPC_CHAR									sParamName[32];									//������
	NPC_INT										iParamType;										//�������ͣ�0�����ͣ�1�������ͣ�2���ֶδ�
	NPC_INT										iStrMaxLen;										//�ֶδ���󳤶�
	NPC_INT										iNumMinValue;									//��ֵ����Сֵ
	NPC_INT										iNumMaxValue;									//��ֵ�����ֵ
	NPC_CHAR									sDefaultValue[64];								//Ĭ��ֵ
	NPC_BOOL									bIfMustInput;									//�Ƿ����
	NPC_BOOL									bIfHide;										//�Ƿ�������ʾ������Ĭ��ֵ
	NPC_BOOL									bIfNeedEncrypt;									//�Ƿ���Ҫ����

} NPC_S_MPI_MON_CONNPARAM_FIELD_DATA, *PNPC_S_MPI_MON_CONNPARAM_FIELD_DATA;

//�������ݶ���
typedef struct _NPC_S_MPI_MON_CONNPARAM_VENDOR_DATA
{
	NPC_DWORD									dwVendorId;										//����ID
	NPC_CHAR									sVendorName[64];								//��������
	NPC_BOOL									bIfNatFunc;										//�Ƿ����NAT��͸����

	NPC_INT										iFieldNum;										//�ֶ���
	PNPC_S_MPI_MON_CONNPARAM_FIELD_DATA			pFieldTable;									//�ֶα�

} NPC_S_MPI_MON_CONNPARAM_VENDOR_DATA, *PNPC_S_MPI_MON_CONNPARAM_VENDOR_DATA;

//�������ƶ���
typedef struct _NPC_S_MPI_MON_VENDOR_NAME
{
	NPC_DWORD									dwVendorId;										//����ID
	NPC_CHAR									sVendorName[32];								//��������

} NPC_S_MPI_MON_VENDOR_NAME, *PNPC_S_MPI_MON_VENDOR_NAME;

//�û���Ϣ
typedef struct _NPC_S_MPI_MON_USER_INFO
{
	NPC_CHAR									sUserId[32];									//�û�ID
	NPC_CHAR									sUserName[32];									//�û�����
	NPC_CHAR									sPaperType[12];									//֤������
	NPC_CHAR									sPaperNo[32];									//֤������
	NPC_CHAR									sMobilePhone[32];								//�ƶ��绰����
	NPC_CHAR									sEmail[64];										//EMAIL
	NPC_S_TD_DATE_TIME							tValidifyDate;									//��Ч�ڽ���ʱ��
	NPC_S_TD_DATE_TIME							tRegDate;										//ע��ʱ��

} NPC_S_MPI_MON_USER_INFO, *PNPC_S_MPI_MON_USER_INFO;


//----------------------------------------------------------------------------------------------------
//��������������
typedef struct _NPC_S_MPI_MON_PUSH_ORDER
{
	NPC_CHAR									sOrderStr[32];									//�����ַ���
	NPC_CHAR									sParamStr[64];									//�����ַ���

} NPC_S_MPI_MON_PUSH_ORDER, *PNPC_S_MPI_MON_PUSH_ORDER;

//������������ʾ��Ϣ
typedef struct _NPC_S_MPI_MON_PUSH_PROMPT
{
	NPC_INT										iMsgType;										//��Ϣ���ͣ���ͣʹ�ã�
	NPC_INT										iShowMode;										//��ʾ��ʽ����ͣʹ�ã�
	NPC_CHAR									sMsgContent[512];								//��Ϣ����

} NPC_S_MPI_MON_PUSH_PROMPT, *PNPC_S_MPI_MON_PUSH_PROMPT;

//���������͸��½�㣨����ӡ��޸ģ�
typedef struct _NPC_S_MPI_MON_PUSH_DEVN_UPDATE_NODE
{
	NPC_INT										iUpdateMode;									//���·�ʽ��0�����ӣ�1���޸�

	NPC_S_MPI_MON_DEV_NODE						tNodeData;										//�������

} NPC_S_MPI_MON_PUSH_DEVN_UPDATE_NODE, *PNPC_S_MPI_MON_PUSH_DEVN_UPDATE_NODE;

//�����������豸�����ɾ����㣨�豸��Ŀ¼��
typedef struct _NPC_S_MPI_MON_PUSH_DEVN_DEL_NODE
{
	NPC_DWORD									dwNodeId;										//���ID

} NPC_S_MPI_MON_PUSH_DEVN_DEL_NODE, *PNPC_S_MPI_MON_PUSH_DEVN_DEL_NODE;

//����������ȫ��Ȩ�ޱ��
typedef struct _NPC_S_MPI_MON_PUSH_UPDATE_GPOP
{
	NPC_BOOL									bIfAllPop;										//�Ƿ���ȫ��Ȩ��
	NPC_INT										iPopNum;										//Ȩ����
	NPC_INT										iPopIdTable[128];								//Ȩ��ID��

} NPC_S_MPI_MON_PUSH_UPDATE_GPOP, *PNPC_S_MPI_MON_PUSH_UPDATE_GPOP;

//�����������豸������Ϣ
typedef struct _NPC_S_MPI_MON_PUSH_DEV_ALARM
{
	NPC_CHAR									sAlarmId[32];									//����ID���豸��Ψһ�����Ϊ�գ����豸��Ϊ���豸
	NPC_CHAR									sDevUmid[32];									//�豸UMID�����Ϊ�գ����ʾ��������ʽ���͵ı�������Ҫ�ο�sDevId����
	NPC_INT										iDevChNo;										//�豸ͨ����
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//�豸ID���������ID
	NPC_CHAR									sDevName[128];									//�豸���ƣ�����ͷ����
	NPC_INT										iAlarmType;										//�������ͣ��μ�NPC_D_MON_ALARM_TYPE_*����
	NPC_S_TD_DATE_TIME							tAlarmTime;										//����ʱ��
	NPC_INT										iAlarmState;									//����״̬��0��ֹͣ�����ߣ���1����ʼ�����ߣ���2���豸���ϣ�3��Ӳ����
	NPC_CHAR									sAlarmInfo[128];								//������Ϣ
	NPC_DWORD									dwParam1;										//��չ����1
	NPC_DWORD									dwParam2;										//��չ����2

} NPC_S_MPI_MON_PUSH_DEV_ALARM, *PNPC_S_MPI_MON_PUSH_DEV_ALARM;

//�����������豸������Ϣ��С��������
typedef struct _NPC_S_MPI_MON_PUSH_DEV_ALARM_VILLAGE
{
	NPC_CHAR									sAlarmId[32];									//����ID
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//�豸ID
	NPC_CHAR									sDevName[128];									//�豸���ƣ�����ͷ����
	NPC_INT										iAlarmType;										//�������ͣ��μ�NPC_D_MON_ALARM_TYPE_*����
	NPC_S_TD_DATE_TIME							tAlarmTime;										//����ʱ��
	NPC_INT										iAlarmState;									//����״̬��0��ֹͣ�����ߣ���1����ʼ�����ߣ���2���豸���ϣ�3��Ӳ����
	NPC_CHAR									sAlarmInfo[128];								//������Ϣ
	NPC_DWORD									dwParam1;										//��չ����1
	NPC_DWORD									dwParam2;										//��չ����2
	NPC_CHAR									sUserId[32];									//�û�ID
	NPC_CHAR									sUserName[32];									//�û�����
	NPC_CHAR									sUserPhone[20];									//�û��ֻ�����
	NPC_CHAR									sUserAddr[68];									//�û���ַ

} NPC_S_MPI_MON_PUSH_DEV_ALARM_VILLAGE, *PNPC_S_MPI_MON_PUSH_DEV_ALARM_VILLAGE;

//���µ�¼֪ͨ
typedef struct _NPC_S_MPI_MON_PUSH_RE_LOGIN_NOTIFY
{
	NPC_INT										iCause;											//ԭ�򣬲μ�NPC_D_MPI_MON_RELOGIN_CAUSE_*����

} NPC_S_MPI_MON_PUSH_RE_LOGIN_NOTIFY, *PNPC_S_MPI_MON_PUSH_RE_LOGIN_NOTIFY;

//���������͹�����Ϣ
typedef struct _NPC_S_MPI_MON_PUSH_ANNO_MSG
{
	NPC_CHAR									sMsgBuf[1024];									//��Ϣ������

} NPC_S_MPI_MON_PUSH_ANNO_MSG, *PNPC_S_MPI_MON_PUSH_ANNO_MSG;


//--------------------------------------------------------------------------------------------------
//������Ϣ���ݶ���
typedef struct _NPC_S_MPI_MON_PUSH_MSG_DATA
{
	NPC_INT										iMsgType;										//��Ϣ���ͣ��μ�NPC_D_MPI_MON_PUSH_TYPE_*����

	union _Data
	{
		NPC_S_MPI_MON_CLIENT_CONFIG_PARAM		tConfig;										//���ò���
		NPC_S_MPI_MON_PUSH_ORDER				tOrder;											//��������������
		NPC_S_MPI_MON_PUSH_PROMPT				tPrompt;										//������������ʾ��Ϣ
		NPC_S_MPI_MON_PUSH_DEVN_UPDATE_NODE		tDevnUpdateDev;									//���������͸��½�㣨����ӡ��޸ģ�
		NPC_S_MPI_MON_PUSH_DEVN_DEL_NODE		tDevnDelNode;									//�����������豸�����ɾ����㣨�豸��Ŀ¼
		NPC_S_MPI_MON_PUSH_UPDATE_GPOP			tGPop;											//����������ȫ��Ȩ�ޱ��
		NPC_S_MPI_MON_PUSH_DEV_ALARM			tDevAlarm;										//�����������豸������Ϣ
		NPC_S_MPI_MON_PUSH_DEV_ALARM_VILLAGE	tDevAlarmVillage;								//�����������豸������Ϣ��С��������
		NPC_S_MPI_MON_PUSH_RE_LOGIN_NOTIFY		tReLoginNotify;									//���µ�¼֪ͨ
		NPC_S_MPI_MON_PUSH_ANNO_MSG				tAnnoMsg;										//���������͹�����Ϣ

	} uData;

} NPC_S_MPI_MON_PUSH_MSG_DATA, *PNPC_S_MPI_MON_PUSH_MSG_DATA;


//--------------------------------------------------------------------------------------------------
//�豸��Ȩ���ݶ���
typedef struct _NPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA
{
	NPC_CHAR									sUserId[NPC_D_MPI_MON_USERID_BUFSIZE];			//�û�ID
	NPC_CHAR									sPopIdTable[128];								//Ȩ��ID���Զ��ŷָ�

} NPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA, *PNPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA;

//������Ϣ
typedef struct _NPC_S_MPI_MON_ARM_SET_ALARM_INFO
{
	NPC_BOOL									bIfSetAlarm;									//�Ƿ񲼷���TRUE��ʾ�����˲�����FALSE��ʾδ���ò���
	NPC_CHAR									sAlarmTypeTable[64];							//�������ͱ��Զ��ŷָ���ֵ�ο�NPC_D_MON_ALARM_TYPE_*����
	NPC_INT										iArmState;										//����״̬��0����ͣ״̬��1������״̬
	NPC_INT										iNotifyState;									//֪ͨ״̬��0����ͣ״̬��1������״̬
	NPC_INT										iActionState;									//����״̬��0����ͣ״̬��1������״̬

	//֪ͨ��
	NPC_INT										iNotifyNum;										//֪ͨ��
	struct _NotifyTable
	{
		NPC_INT									iNotifyType;									//֪ͨ���ͣ��ο�NPC_D_MON_ALARM_NOTIFY_TYPE_*����
		NPC_CHAR								sNotifyParam[128];								//֪ͨ����������֪ͨ����ȷ��֪ͨ�������ݣ����ֻ�����ΪTOKEN������Ϊ�ֻ����룬EMAILΪEMAIL��ַ

	} tNotifyTable[NPC_D_MPI_MON_MAX_ALARM_NOTIFY_NUM];

	//������
	NPC_INT										iActionNum;										//������
	struct _ActionTable
	{
		NPC_INT									iActionType;									//�������ͣ��ο�NPC_D_MON_ALARM_ACTION_TYPE_*����
		NPC_INT									iStopType;										//ֹͣ���ͣ�0������ֹͣʱֹͣ��1���̶�ʱ��ֹͣ
		NPC_INT									iPhotoSpaceTime;								//���ռ��ʱ�䣨�룩
		NPC_INT									iActionTotalTime;								//������ʱ�䣨�룩
		NPC_INT									iPtzCruiseId;									//PTZ����Ѳ��ID

	} tActionTable[NPC_D_MPI_MON_MAX_ALARM_ACTION_NUM];

} NPC_S_MPI_MON_ARM_SET_ALARM_INFO, *PNPC_S_MPI_MON_ARM_SET_ALARM_INFO;

//������¼
typedef struct _NPC_S_MPI_MON_ARM_ALARM_RECORD
{
	NPC_CHAR									sAlarmRecordId[32];								//������¼ID
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//�豸ID���������ID��
	NPC_CHAR									sDevShowName[128];								//�豸��ʾ����
	NPC_INT										iAlarmType;										//�������ͣ��μ�NPC_D_MON_ALARM_TYPE_*����
	NPC_INT										iAlarmState;									//����״̬��0��ֹͣ�����ߣ���1����ʼ�����ߣ���2���豸���ϣ�3��Ӳ����
	NPC_S_TD_DATE_TIME							tAlarmTime;										//����ʱ��
	NPC_CHAR									sAlarmInfo[128];								//������Ϣ

} NPC_S_MPI_MON_ARM_ALARM_RECORD, *PNPC_S_MPI_MON_ARM_ALARM_RECORD;

//С��������¼
typedef struct _NPC_S_MPI_MON_ARM_VILLAGE_ALARM_RECORD
{
	NPC_CHAR									sAlarmRecordId[32];								//������¼ID
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//�豸ID���������ID��
	NPC_CHAR									sDevShowName[128];								//�豸��ʾ����
	NPC_INT										iAlarmType;										//�������ͣ��μ�NPC_D_MON_ALARM_TYPE_*����
	NPC_INT										iAlarmState;									//����״̬��0��ֹͣ�����ߣ���1����ʼ�����ߣ���2���豸���ϣ�3��Ӳ����
	NPC_S_TD_DATE_TIME							tAlarmTime;										//����ʱ��
	NPC_CHAR									sAlarmInfo[128];								//������Ϣ
	NPC_CHAR									sDoAlarmInfo[64];								//������Ϣ
	NPC_CHAR									sUserId[32];									//�û�ID
	NPC_CHAR									sUserName[32];									//�û�����
	NPC_CHAR									sUserPhone[20];									//�û��ֻ�����
	NPC_CHAR									sUserAddr[68];									//�û���ַ

} NPC_S_MPI_MON_ARM_VILLAGE_ALARM_RECORD, *PNPC_S_MPI_MON_ARM_VILLAGE_ALARM_RECORD;


//--------------------------------------------------------------------------------------------------
//��������
typedef struct _NPC_S_MPI_MON_SEARCH_ADAPTER_DATA
{
	NPC_CHAR									sAdapterName[32];								//��������
	NPC_CHAR									sAdapterMac[20];								//����MAC��ַ����ʽΪXX-XX-
	NPC_CHAR									sIpaddr[16];									//IP��ַ
	NPC_CHAR									sNetmask[16];									//��������
	NPC_CHAR									sGateway[16];									//���ص�ַ
	NPC_INT										iIpConnMode;									//IP����ģʽ��0��ԭ�汾��1��IP�����ԣ�2��������

} NPC_S_MPI_MON_SEARCH_ADAPTER_DATA, *PNPC_S_MPI_MON_SEARCH_ADAPTER_DATA;

//�����豸����
typedef struct _NPC_S_MPI_MON_SEARCH_DEV_DATA
{
	NPC_INT										iMsgVerNo;						//��Ϣ�汾��

	NPC_DWORD									dwVendorId;						//����ID
	NPC_CHAR									sDevModel[32];					//�����豸�ͺ�
	NPC_CHAR									sUMDevModel[32];				//UM�豸�ͺ�
	NPC_CHAR									sVersion[16];					//�汾��
	NPC_CHAR									sDevName[32];					//�豸����
	NPC_CHAR									sDevId[32];						//�豸ID
	NPC_CHAR									sDevUserName[32];				//�豸�û���
	NPC_BOOL									bIfSetPwd;						//�Ƿ�����������
	NPC_CHAR									sCloudServerAddr[64];			//�Ʒ����ַ
	NPC_USHORT									usCloudServerPort;				//�Ʒ���˿ں�
	NPC_CHAR									sDevIpaddr[16];					//�豸��IP��ַ
	NPC_USHORT									usDevPort;						//�豸�Ķ˿ں�
	NPC_USHORT									usChNum;						//ͨ����
	NPC_USHORT									usDevNtsUdpPort;				//�豸NTS��UDP�˿ں�
	NPC_USHORT									usDevMnVerNo;					//�豸�˹���汾��

	NPC_INT										iEmpowerMode;					//��Ȩģʽ��0������ģʽ��1��UMIDģʽ��2����֤��ģʽ��3����������Ȩģʽ
	NPC_CHAR									sEmpowerCode[64];				//��Ȩ��

	NPC_INT										iDevIdType;						//�豸ID���ͣ�0���ֶ����ã�1�����������䣬2�����кţ�MAC������
	NPC_BOOL									bIfAllowSetIpaddr;				//�Ƿ��������IP��ַ
	NPC_BOOL									bIfEnableDhcp;					//�Ƿ�����DHCP

	NPC_BOOL									bIfConnState;					//�Ƿ�������״̬
	NPC_INT										iSrvConnState;					//����������״̬���μ�NPC_D_MPI_MON_DEV_SRV_CONN_STATE_*����
	NPC_INT										iSrvConnResult;					//���������ӽ�����μ�NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_*����

	NPC_INT										iAdapterNum;											//������
	NPC_S_MPI_MON_SEARCH_ADAPTER_DATA			tAdapterTable[NPC_D_MPI_MON_SEARCH_MAX_ADAPTER_NUM];	//������

} NPC_S_MPI_MON_SEARCH_DEV_DATA, *PNPC_S_MPI_MON_SEARCH_DEV_DATA;

//SDK�豸����
typedef struct _NPC_S_MPI_MON_SEARCH_SDK_DEV_DATA
{
	NPC_UINT									uiDevFlag;						//�豸�˱�ʶ
	NPC_CHAR									sDevIpaddr[16];					//�豸IP��ַ

	NPC_CHAR									sDevType[12];					//�豸���ͣ��磺DEV��IPC
	NPC_CHAR									sDevModel[32];					//�豸�ͺ�
	NPC_CHAR									sSerialNumber[32];				//���к�
	NPC_INT										iVideoChanNum;					//�豸ͨ������
	NPC_INT										iAudioChanNum;					//�豸����ͨ����
	NPC_INT										iPtzChNum;						//PTZͨ����
	NPC_INT										iAlarmInPortNum;				//�����������
	NPC_INT										iAlarmOutPortNum;				//�����������
	NPC_INT										iDiskNum;						//Ӳ�̸���
	NPC_INT										iSubProtoNum;					//����������0��ʾ��֧��������

	NPC_BOOL									bIfDpsDebug;					//�Ƿ����״̬
	NPC_BOOL									bIfDpsShowStreamLog;			//�Ƿ���ʾ����־����ý�����շ���־��Ϣ
	NPC_BOOL									bIfShowRunState;				//�Ƿ���ʾ����״̬��Ϣ

} NPC_S_MPI_MON_SEARCH_SDK_DEV_DATA, *PNPC_S_MPI_MON_SEARCH_SDK_DEV_DATA;

//NTS�豸����
typedef struct _NPC_S_MPI_MON_NTS_DEV_PARAM
{
	NPC_CHAR									sDevId[32];						//�豸ID

	NPC_CHAR									sServerAddr[128];				//��������ַ��IP��ַ��������
	NPC_USHORT									usServerPort;					//�������˿ں�
	NPC_USHORT									usReserve;						//����

	NPC_BOOL									bIfWriteLogFile;				//�Ƿ�д��־�ļ�

	NPC_BOOL									bIfStartLogNetSrv;				//�Ƿ���Ҫ������־�������
	NPC_USHORT									usLogNetSrvPort;				//��־�������˿ں�

	NPC_BOOL									bIfStartLogUpClient;			//�Ƿ���Ҫ������־�ϴ��ͻ���
	NPC_CHAR									sLogUpSrvIpaddr[16];			//��־�ϴ�����IP��ַ
	NPC_USHORT									usLogUpSrvPort;					//��־�ϴ�����˿ں�

} NPC_S_MPI_MON_NTS_DEV_PARAM, *PNPC_S_MPI_MON_NTS_DEV_PARAM;

//�ļ�������������ļ���ȡ��д�룬�ýṹ��֮��Ϊʵ������
typedef struct _NPC_S_MPI_MON_FILE_OP_ORDER
{
	NPC_INT										iOrderId;						//����ID��0�����ļ����룬1��д�ļ����룬2�����ļ�Ӧ��3��д�ļ�Ӧ��
	NPC_DWORD									dwRequId;						//����ID��Ψһ��ʶ�ô�����
	NPC_CHAR									sFileName[64];					//�ļ������ļ�����Ŀ¼�����ϲ����
	NPC_DWORD									dwRet;							//�����0���ɹ�������ʧ��
	NPC_DWORD									dwDataLen;						//���ݳ��ȣ��ֽڣ�

} NPC_S_MPI_MON_FILE_OP_ORDER, *PNPC_S_MPI_MON_FILE_OP_ORDER;

//ϵͳ��Ϣ
typedef struct _NPC_S_MPI_MON_SYSTEM_MSG
{
	NPC_CHAR									sMsgId[32];						//��ϢID
	NPC_CHAR									sMsgTime[20];					//��Ϣʱ��
	NPC_CHAR									sMsgTitle[128];					//��Ϣ����
	NPC_CHAR									sMsgContent[1024];				//��Ϣ���ݣ�TXT��ʽ��

} NPC_S_MPI_MON_SYSTEM_MSG, *PNPC_S_MPI_MON_SYSTEM_MSG;

//��ʾ���豸
typedef struct _NPC_S_MPI_MON_VIDEO_DEMO_DEV_DATA
{
	NPC_CHAR									sDevName[128];					//�豸����
	NPC_CHAR									sShareName[128];				//��������
	NPC_CHAR									sCameraId[32];					//�����ID
	NPC_INT										iVendorId;						//����ID
	NPC_INT										iConnMode;						//����ģʽ���μ�NPC_D_MON_DEV_CONN_MODE_*����
	NPC_CHAR									sConnParam[256];				//���Ӳ���
	NPC_CHAR									sPicLink[128];					//ͼƬ����

} NPC_S_MPI_MON_VIDEO_DEMO_DEV_DATA, *PNPC_S_MPI_MON_VIDEO_DEMO_DEV_DATA;

//��Ƶ����ȼ�����
typedef struct _NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_PARAM
{
	NPC_CHAR									sLevelName[16];					//�ȼ�����
	NPC_INT										iLevelValue;					//�ȼ�ֵ��������ڵ���0
	NPC_USHORT									usWidth;						//ͼ���
	NPC_USHORT									usHeight;						//ͼ���
	NPC_USHORT									usFrameRate;					//֡��
	NPC_USHORT									usBitRate;						//���ʣ���λ��kbps

} NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_PARAM, *PNPC_S_MPI_MON_VIDEO_CODEC_LEVEL_PARAM;

//��Ƶ����ȼ��б�
typedef struct _NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_LIST
{
	NPC_INT										iLevelNum;						//�ȼ���
	NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_PARAM		tLevelList[8];					//�ȼ��б�

} NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_LIST, *PNPC_S_MPI_MON_VIDEO_CODEC_LEVEL_LIST;

//�洢��������ַ
typedef struct _NPC_S_MPI_MON_STORAGE_SRV_ADDR
{
	NPC_INT										iSrvAddrNum;					//��������ַ��
	struct _SrvAddrTable{
		NPC_CHAR								sIpaddr[16];					//������IP��ַ
		NPC_USHORT								usPort;							//�������˿ں�
		NPC_USHORT								usReserve;						//����
	} tSrvAddrTable[32];

} NPC_S_MPI_MON_STORAGE_SRV_ADDR, *PNPC_S_MPI_MON_STORAGE_SRV_ADDR;


#endif

