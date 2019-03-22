#ifndef PLAYBACK_H
#define PLAYBACK_H

#ifdef PLAYBACK_EXPORTS
#define PLAYBACK_API	extern "C" __declspec(dllexport)
#else
#define PLAYBACK_API	extern "C" __declspec(dllimport)   //VC ��
#endif

#include "..\\SdkDefine.h"

//������ʾģʽ
enum MENU_TYPE
{
	HEADER_HIDE,		//����
	HEADER_SHOW,		//��ʾ
};	

//��������
enum PLAY_TYPE
{
	PLAYSDK_NOTHING = 0,
	PLAYSDK_LOCAL,		//���ػط�
	PLAYSDK_NET,
	PLAYSDK_IPS,
	PLAYSDK_SAVESERVER,
	PLAYSDK_NET_TIME,	//����ʱ��λط�
	PLAYSDK_LOCAL_TIME,	//����ʱ��λط�
};	


//�ص���Ϣ����
enum MSGCALL_TYPE
{
	MSG_NET_PLAY,
	MSG_NET_TIMEPLAY,
	MSG_NET_CLOSE,
	MSG_NET_RESUME,
	MSG_NET_PAUSE,
	MSG_NET_SEEK,
	MSG_NET_DOWNLOAD,	//¼������
	MSG_NET_ENDLOAD,	//ֹͣ����
	MSG_NET_SEARCH,	//¼���ѯ
	MSG_LOCAL_DOWNLOAD,	//����¼������
	MSG_LOCAL_ENDLOAD,	//ֹͣ��������
	MSG_NET_FAST,
	MSG_NET_SLOW,
	MSG_LOCAL_PLAY,
	MSG_NET_DOWNLOADBYTIME,
	MSG_LOCAL_RECORDSTORE,  //�洢�طŶ˵Ŀͻ���¼��
	MSG_CLOSE_AUDIO,  //�ر�Ԥ���������Ƶ
	MSG_OPEN_AUDIO,   //����Ԥ���������Ƶ
	MSG_CHN_POWER_BYTIME,  //�жϵ�ǰͨ����Ȩ��,ֻ��԰�ʱ��
};	


//�豸����طŽṹ��
typedef struct _NETPLAY_INFO
{
	H264_DVR_FILE_DATA	fileInfo;		//�ļ���Ϣ
	DEVICE_INFO			sDevInfo;		//�豸��Ϣ
	char				szFileName[256]; //�����ļ���
	int nFileType;
}NETPLAY_INFO;

//�豸����طŽṹ��
typedef struct _TIME_NETPLAY_INFO
{
	DWORD				dwLoginID;		//�豸��½���������ý����
	DEVICE_INFO			sDevInfo;		//�豸��Ϣ
	int					nChannelNo;		//ͨ����
	H264_DVR_TIME			TmStart;		//��ʼʱ��
	H264_DVR_TIME			TmEnd;			//����ʱ��
	int nRecType;                          //¼������
	HWND hWnd;
}TIME_NETPLAY_INFO;

//�豸����طſ��ƽṹ��
typedef struct _NETPLAYCONTROL_INFO
{
	DWORD				dwLoginID;		//�豸��½���������ý����
	DWORD				dwHandle;		//���ž��(openʱ�򷵻�)
	DWORD				dwDevID;		//�豸ID
	int					nChannelNo;		//����ͨ��
	unsigned int		offsetTime;		//ʱ��ƫ��
	unsigned int		offsetPos;		//�ٷݱ�(0~100)ƫ��,��ʱ��ƫ��Ϊ-1ʱ��Ч
}NETPLAYCONTROL_INFO;	


//�豸����طſ��ƽṹ��
typedef struct _DOWNLOAD_INFO
{
	DWORD				dwLoginID;		//�豸��½���������ý����
	DWORD				dwDevID;		//�豸ID
	H264_DVR_FILE_DATA	fileInfo;		//�ļ���Ϣ
	char				szFileName[256];
}DOWNLOAD_INFO;


//������
#define PLAYBACK_OPENFILE_ERROR		-1000	//���ļ�ʧ��(���ػط�)
#define PLAYBACK_HSAPLAY			-1001	//��ǰͨ���Ѿ��ڻط�
#define PLAYBACK_NETDATA_ERROR		-1002	//������������ʧ��
#define PLAYBACK_DECODE_FAILED		-1003	//�򿪽���ʧ��
#define PLAYBACK_MAX_CHANNEL		-1004	//�������ط�·��
#define PLAYBACK_AVI_ERROR			-1005	//���ܲ���AVI














typedef int (CALLBACK *fMsgCallBack)(char* pMsgInfo, DWORD dwMsgType, 
									 void *pDownloadPosCallback,
									 void *pNetDataCallback, 
									 DWORD dwUser, VENDOR_TYPE vendor);

/*	$Function		:	Playback_Init
==  ===============================================================
==	Description		:	��ʼ��
==	Argument		:	nLanguage		����ID
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/	
PLAYBACK_API BOOL Playback_languageInit(int nLanguage);

/*	$Function		:	Playback_Init
==  ===============================================================
==	Description		:	��ʼ��
==	Argument		:	pWnd		�ڲ����ڵĸ�����
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/	
PLAYBACK_API CWnd* Playback_Init(CWnd* pWnd, fMsgCallBack fcallback);



/*	$Function		:	Playback_UnInit
==  ===============================================================
==	Description		:	����ʼ��
==	Argument		:	
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_UnInit();


/*	$Function		:	Playback_SetStyle
==  ===============================================================
==	Description		:	������ʾģʽ
==	Argument		:	
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_SetStyle(int nStyle);

/*	$Function		:	Playback_SetSource
==  ===============================================================
==	Description		:	���ûط�ģʽ 0: Զ�̻ط� 1: ���ػط�
==	Argument		:	
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_SetSource(int nSource);

/*	$Function		:	Playback_Move
==  ===============================================================
==	Description		:	�ƶ�����
==	Argument		:	
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_Move(LPCRECT lpRect);


/*	$Function		:	Playback_ShowWindow
==  ===============================================================
==	Description		:	��ʾ��������
==	Argument		:	
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_ShowWindow(int nCmdShow);


/*	$Function		:	Playback_InsertDevice
==  ===============================================================
==	Description		:	�����µ��豸
==	Argument		:	pDevInfo	�豸��Ϣ
						nType		1 == ���� 0 == ɾ��
						nSoure      1 == ���� 0 == Զ��
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_InsertDevice(char* pDevInfo, int nType, int nSoure);


/*	$Function		:	Playback_OpenVideo
==  ===============================================================
==	Description		:	�򿪻ط�
==	Argument		:	pFileInfo	���ŵ��ļ���Ϣ	
					:	dwSize		���Ÿ���(���ܴ��������ط�)			
					:	dwType		��������(�����ļ�����: pFileInfo �����ļ�·�� )
									(�豸������ط�, IPS�ط�,�洢����ط�)
					:	dwReserved	�����ֽ�
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API int Playback_OpenVideo(char* pFileInfo, DWORD dwInfoSize, DWORD dwSize, DWORD dwType, DWORD dwWndIndex = -1, VENDOR_TYPE vender = XMDEVC_TYPE);


/*	$Function		:	Playback_CloseVideo
==  ===============================================================
==	Description		:	�رջط�
==	Argument		:	��û�в���
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API int Playback_CloseVideo(long lLoginID = 0, long lDevID = 0, int nChannelNo = 0, DWORD dwType = 0, DWORD dwReserved = 0);


/*	$Function		:	Playback_StartDownload
==  ===============================================================
==	Description		:	����¼��
==	Argument		:	pFileInfo		���ص��ļ���Ϣ
					:	pSaveFileName	������ļ�����,��������·��	
					:	dwSize			���Ÿ���(���ܴ��������ط�)	
					:	dwType			��������(�豸������ط�, IPS�ط�,�洢����ط�)
					:	poscallback		���Ȼص�	
					:	dwUserd			�ص����
					:	dwReserved		����
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API int Playback_StartDownload(char* pFileInfo, char *pSaveFileName, DWORD dwSize, DWORD dwType, void *poscallback, DWORD dwUserd, DWORD dwReserved = 0);


/*	$Function		:	Playback_EndDownload
==  ===============================================================
==	Description		:	ֹͣ����¼��
==	Argument		:	��ʱֻ��ͬʱ����һ��, ���Թرյ�ʱ��ʲô���������Բ�����
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/
PLAYBACK_API int Playback_EndDownload(long lDevID = 0, int nChannelNo = 0, DWORD dwType = 0, DWORD dwReserved = 0);

/* $Funcktion : Playback_ControlAudio
   Description: ����Ԥ���������Ƶ�����ƻطŵ���Ƶ
   Return	:	TRUE,FALSE
*/
PLAYBACK_API BOOL Playback_ControlAudio(bool bAudio = FALSE);

/* $Funcktion : Playback_ControlLeft��Playback_ControlRight
Description: ���ü��������Ҽ�������¼��ط�ʱ��������ţ���Ϊ���ţ���Ϊ���
Return	:	TRUE,FALSE
*/
PLAYBACK_API BOOL Playback_ControlLeft();
PLAYBACK_API BOOL Playback_ControlRight();

#endif