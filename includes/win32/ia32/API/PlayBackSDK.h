#ifndef PLAYBACK_H
#define PLAYBACK_H

#ifdef PLAYBACK_EXPORTS
#define PLAYBACK_API extern "C"	__declspec(dllexport)
#else
#define PLAYBACK_API extern "C"	__declspec(dllimport)   //VC ��
#endif



//������ʾģʽ
enum MENU_TYPE
{
	HEADER_HIDE,		//����
	HEADER_SHOW,		//��ʾ
	HEADER_HIDE_V2,		//����V2�汾
	HEADER_SHOW_V2,		//��ʾV2�汾
};	

//��������
enum PLAY_TYPE
{
	PLAYSDK_NOTHING = 0,
	PLAYSDK_LOCAL,		//���ػط�
	PLAYSDK_NET,
	PLAYSDK_IPS,
	PLAYSDK_SAVESERVER,
	PLAYSDK_TIME,		//ʱ��λط�
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
	MSG_NET_FAST,
	MSG_NET_SLOW,
	MSG_NET_DOWNLOADBYTIME,//��ʱ������
	MSG_OPEN_AUDIO,
	MSG_CLOSE_AUDIO,
};	


//�豸����طŽṹ��
typedef struct _NETPLAY_INFO
{
	H264_DVR_FILE_DATA	fileInfo;		//�ļ���Ϣ
	DEVICE_INFO			sDevInfo;		//�豸��Ϣ
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
}TIME_NETPLAY_INFO;

//�豸����طſ��ƽṹ��
typedef struct _NETPLAYCONTROL_INFO
{
	DWORD				dwLoginID;		//�豸��½���������ý����
	DWORD				dwHandle;		//���ž��(openʱ�򷵻�)
	DWORD				dwDevID;		//�豸ID
	int					nChannelNo;		//����ͨ��
	unsigned int		offsetTime;		//ʱ��ƫ��
	unsigned int		offsetByte;		//λ��ƫ��
}NETPLAYCONTROL_INFO;	


//�豸����طſ��ƽṹ��
typedef struct _DOWNLOAD_INFO
{
	DWORD				dwLoginID;		//�豸��½���������ý����
	DWORD				dwDevID;		//�豸ID
	H264_DVR_FILE_DATA	fileInfo;		//�ļ���Ϣ
	char				szFileName[256];
	int nFileType;
}DOWNLOAD_INFO;


//������
#define PLAYBACK_OPENFILE_ERROR		-1000	//���ļ�ʧ��(���ػط�)
#define PLAYBACK_HSAPLAY			-1001	//��ǰͨ���Ѿ��ڻط�
#define PLAYBACK_NETDATA_ERROR		-1002	//������������ʧ��
#define PLAYBACK_DECODE_FAILED		-1003	//�򿪽���ʧ��
#define PLAYBACK_MAX_CHANNEL		-1004	//�������ط�·��
#define PLAYBACK_NATCONNET_MAX       -1005    //����NAT �������
















typedef int (CALLBACK *fMsgCallBack)(char* pMsgInfo, DWORD dwMsgType, 
									 void *pDownloadPosCallback,
									 void *pNetDataCallback, 
									 DWORD dwUser);

/*	$Function		:	Playback_Init
==  ===============================================================
==	Description		:	��ʼ��
==	Argument		:	nLanguage		����ID
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/	
//PLAYBACK_API BOOL Playback_languageInit(int nLanguage);

/*	$Function		:	Playback_Init
==  ===============================================================
==	Description		:	��ʼ��
==	Argument		:	strLanguage		��������
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/	
PLAYBACK_API BOOL Playback_languageInit(CString strLanguage);

/*	$Function		:	Playback_Init
==  ===============================================================
==	Description		:	��ʼ��
==	Argument		:	pWnd		�ڲ����ڵĸ�����
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/	
PLAYBACK_API CWnd* Playback_Init(CWnd* pWnd, fMsgCallBack fcallback);



/*	$Function		:	Playback_UnInit
==  ===============================================================
==	Description		:	����ʼ��
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_UnInit();


/*	$Function		:	Playback_SetStyle
==  ===============================================================
==	Description		:	������ʾģʽ
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_SetStyle(int nStyle);


/*	$Function		:	Playback_Move
==  ===============================================================
==	Description		:	�ƶ�����
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_Move(LPCRECT lpRect);


/*	$Function		:	Playback_ShowWindow
==  ===============================================================
==	Description		:	��ʾ��������
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_ShowWindow(int nCmdShow);


/*	$Function		:	Playback_InsertDevice
==  ===============================================================
==	Description		:	�����µ��豸
==	Argument		:	pDevInfo	�豸��Ϣ
						nType		1 == ���� 2 == ɾ��
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_InsertDevice(char* pDevInfo, int nType);


/*	$Function		:	Playback_OpenVideo
==  ===============================================================
==	Description		:	�򿪻ط�
==	Argument		:	pFileInfo	���ŵ��ļ���Ϣ	
					:	dwSize		���Ÿ���(���ܴ��������ط�)			
					:	dwType		��������(�����ļ�����: pFileInfo �����ļ�·�� )
									(�豸������ط�, IPS�ط�,�洢����ط�)
					:	dwReserved	�����ֽ�
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API int Playback_OpenVideo(char* pFileInfo, DWORD dwInfoSize, DWORD dwSize, DWORD dwType, DWORD dwReserved = 0, DWORD dwWndIndex  = -1 );


/*	$Function		:	Playback_CloseVideo
==  ===============================================================
==	Description		:	�رջط�
==	Argument		:	��û�в���
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
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
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API int Playback_StartDownload(char* pFileInfo, char *pSaveFileName, DWORD dwSize, DWORD dwType, void *poscallback, DWORD dwUserd, DWORD dwReserved = 0);


/*	$Function		:	Playback_EndDownload
==  ===============================================================
==	Description		:	ֹͣ����¼��
==	Argument		:	��ʱֻ��ͬʱ����һ��, ���Թرյ�ʱ��ʲô���������Բ�����
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API int Playback_EndDownload(long lDevID = 0, int nChannelNo = 0, DWORD dwType = 0, DWORD dwReserved = 0);


PLAYBACK_API BOOL Playback_ControlAudio(bool bAudio = FALSE);




#endif