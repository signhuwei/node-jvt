#ifndef CONF_MOD_H
#define CONF_MOD_H



#ifdef CONF_MOD_EXPORTS
#define CONF_MOD_API  __declspec(dllexport) 
#else
#define CONF_MOD_API  __declspec(dllimport)   //VC ��
#endif

typedef enum _XM_CFG_TYPE
{
	    XM_CFG_ROOT = 1,
		//¼��
		XM_CFG_RECORD,
		XM_CFG_RECSET,  //¼������
		XM_CFG_PICSET,    //ͼƬ����

		//����
		XM_CFG_ALARM,
		XM_CFG_MOTION,  //�ƶ����
		XM_CFG_INPUT,  //��������
		XM_CFG_OUTPUT,  //�������
		XM_CFG_VIDEOLOSS,  //��Ƶ��ʧ
		XM_CFG_BLIND,  //��Ƶ�ڵ�
		
		//ϵͳ����
		XM_CFG_SYS,
		XM_CFG_NORMAL,   //��ͨ����
		XM_CFG_ENCODE,   //��������
		XM_CFG_NETWORK,  //��������
		XM_CFG_SERVER,   //�������
		XM_CFG_OUTMODE,  //���ģʽ
		XM_CFG_PTZ,    //��̨����
		XM_CFG_COMM,  //��������
		XM_CFG_TOUR,   //��Ѳ����

		//������
		XM_CFG_TOOLMANAGER,
		XM_CFG_HARDDISK,  //Ӳ�̹���
		XM_CFG_ACCOUT,   //�û�����
		XM_CFG_AUTOMAIN,  //�Զ�ά��
		XM_CFG_DEFAULT,  //�ָ�Ĭ��
		XM_CFG_UPGRADE,  //ϵͳ����
		XM_CFG_DEVINFO,  //�豸��Ϣ
		XM_CFG_REBOOT,   //ϵͳ����

		//ϵͳ��Ϣ
		XM_CFG_SYSINFO,
		XM_CFG_DISKINFO,   //Ӳ����Ϣ
		XM_CFG_LOG,   //��־��Ϣ
		XM_CFG_VESION,  //�汾��Ϣ
		
		//����
		XM_CFG_CARINFO,
		XM_CFG_CARSTATUS,//����״̬
		XM_CFG_DELAYSET,//��ʱ����
		XM_CFG_MAX	=   500,
}XM_CFG_TYPE;

// ����һ:�豸��Ϣ��������ȡ�������ͣ������û�����.
typedef int (CALLBACK * GetParmBackCallFunc)(long ConfigType, int nChannel,char* pConfigBuf,DWORD dwBufSize, DWORD dwUserParam, DWORD *lpRet /*= NULL*/);
typedef int (CALLBACK * SaveParmBackCallFunc)(long ConfigType, int nChannel,char* pConfigBuf,DWORD dwBufSize,DWORD dwUserParam);


				   
//��ʼ��
CONF_MOD_API BOOL DeviceManagerPlugInit(CWnd *pParent,DWORD id=1);

//����ʼ��
CONF_MOD_API BOOL DeviceManagerPlugUnInit(DWORD id=1);


//��ʼ������
//pLanguagePath ���Ծ���·���������ļ���
CONF_MOD_API BOOL DeviceManagerPlugLoadLanguage(TCHAR *pLanguagePath,DWORD id=1);


//�豸��ȡ���ݺͱ������ݻص�
CONF_MOD_API BOOL DeviceManagerPlugSetCallback(void * getCalback, void * saveCallback, DWORD dwUser,DWORD id=1);

//�ƶ�����λ��
CONF_MOD_API BOOL DeviceManagerPlugMoveRect(CRect *rect, BOOL bShow,DWORD id=1);


//�豸���ģ����»�ȡ��������
CONF_MOD_API BOOL DeviceManagerPlugRefushData(DWORD id=1);

CONF_MOD_API CRect DeviceManagerPlugGetRect();





#endif