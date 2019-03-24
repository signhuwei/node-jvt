#ifndef _COMMDEVICESDK_
#define _COMMDEVICESDK_


#define COMMDEVICE_API  extern "C" __declspec(dllexport)

#pragma pack(1)

/**************************************************************
����ץ�Ĳ�����������
***************************************************************/
typedef enum _FACE_CONFIG_TYPE
{
	SDK_SMARTFACE_COMMON = 0x01,		//����������������
	SDK_SMARTFACE_AREA_DETECT,			//�����������
	SDK_SMARTFACE_WBLIST,				//�ڰ���������ʱû����������
	SDK_SMARTFACE_VERSION,				//�汾
}FACE_CONFIG_TYPE;



typedef struct _SDK_SMART_FACE_S
{
	INT 		nEnable;
	INT 		nSensitivity;
	BYTE 		nExposureMode; 							//�����ع�ģʽ
	BYTE		nRes;
	BYTE 		nTrackmode;								//��������  		 0:�ر� 1:���˸��� 2:�ǹ��˸���
	BYTE        nFtpEnable;								//FTP�ϴ�����	0:�ر� 1:����
	INT 		nFaceSize;								//����ʶ����С�ߴ�(30~300)
	BYTE		nFaceBLC;
	BYTE 		nParamCheckFlag;
	BYTE		byRes[54];
}SDK_SMART_FACE;


//����
typedef struct _AREA_RECT_S
{
	short			x;									//X����
	short			y;									//Y����
	short			w;									//���
	short			h;									//�߶�
}AREA_RECT_S;


typedef struct _SDK_VI_DETECT_S
{
	DWORD				dwSize;			
	INT					bEnable;
	AREA_RECT_S			stFaceMaskArea;
	BYTE				byRes[32];
}SDK_VI_DETECT;


typedef struct _SDK_SMART_VERSION_S
{
	char szLib_version[16] ;    
	char szModel_version[16];
	BYTE  nbyLic;
	BYTE  byRes[7];
}SDK_SMART_VERSION;

#pragma pack()


/**************************************************************
brief:		���� 		��ȡͼƬ�ص�����
param[in] 	pBuf 		���ݻ���
param[in] 	nDataLen	���ݳ���
param[in]	bOver		��ʾ�Ƿ����һ������:0��ʾ���ǣ�1��ʾ��
return		���ؽ��	1��ʾ����������ʧ��
***************************************************************/
typedef int (__stdcall *SDK_GetJpgDataCB)( char *pBuf, int nDataLen, int bOver ,void *pConfig);



/**************************************************************
brief:		���� 		��ȡͼƬ�ص�����
param[in] 	pBuf 		���ݻ���
param[in] 	nDataLen	���ݳ���
param[in]	bOver		��ʾ�Ƿ����һ������:0��ʾ���ǣ�1��ʾ��
return		���ؽ��	1��ʾ����������ʧ��
***************************************************************/
typedef int (__stdcall *SDK_GetSendPictureState)( int nSendPercent, void *pConfig );



/**************************************************************
brief:		���� 		��ʼ��SDK
return		���ؽ��	1��ʾ����������ʧ��
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_init(void);


/**************************************************************
brief:		���� 		��¼�豸
param[in] 	ip	 		�豸ip��ַ
param[in] 	port		�豸�˿�
param[in]	usrname		��¼�û���
param[in]	pwd			��¼����
return		���ؽ��socket	socket����0��ʾ��¼�ɹ�	
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_login(char *ip, int port, char* usrname, char* pwd);


/**************************************************************
brief:		���� 		ע���豸
return		���ؽ��	0��ʾע������������ʧ��
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_logout(int socket );


/**************************************************************
brief:		���� 		��ȡ��������
param[in] 	sockfd 		��¼�豸��socket
param[in] 	configType	��ȡ������������
param[in]	pData		��ȡ���ݻ���
return		���ؽ��	1��ʾ��ȡ����������ʧ��
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_get_config(int sockfd, FACE_CONFIG_TYPE configType, char *pData );


/**************************************************************
brief:		���� 		���ò�������
param[in] 	sockfd 		��¼�豸��socket
param[in] 	configType	��ȡ������������
param[in]	pData		���ݻ���
return		���ؽ��	1��ʾ��������������ʧ��
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_set_config(int sockfd, FACE_CONFIG_TYPE configType, char *pData);


/**************************************************************
brief:		���� 		��ȡץ��ͼƬ
param[in] 	sockfd 		��¼�豸��socket
param[in] 	getJpgDataCB��ȡͼƬ���ݻص�����
return		���ؽ��	0��ʾ��ȡ����������ʧ��
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_open_jpg_stream(int sockfd, SDK_GetJpgDataCB getJpgDataCB,void *pConfig);



/**************************************************************
brief:		���� 		�ر�ͼƬ��ȡ
param[in] 	sockfd 		��¼�豸��socket
return		���ؽ��	0��ʾ�ر�����������ʧ��
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_close_jpg_stream(int sockfd);



/**************************************************************
brief:		���� 		����һ��ͼƬ
param[in] 	filepath 	ͼƬ·��
param[in]   ip          Ŀ��IP��ַ
return		���ؽ��	0��ʾ��������������ʧ��
***************************************************************/

COMMDEVICE_API int __stdcall sdk_device_send_one_jpg(char *filepath,char *ip,unsigned char  picType,char *pPicNumber,SDK_GetSendPictureState pCallback,void *pConfig);


#endif


//DESCRIPTION 'SmartFace Windows Dynamic Link Library'