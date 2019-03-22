#ifndef DOWNLOADPLAN_DEF_H
#define DOWNLOADPLAN_DEF_H

typedef struct _DOWNLOAD_PERIOD_
{	
	bool bEnable;
	int nFileType;        //������������
	int nDownloadTimeBegin;			//���ؿ�ʼʱ�䣨���ӣ�
	int nDownloadTimeEnd;			//���ؽ���ʱ�䣨���ӣ�
	int	nfileTimeBegin;				//�ļ���ʼʱ�䣨�룩
	int nfileTimeEnd;				//�ļ�����ʱ�䣨�룩
	int nTaskType;			//0 -All 1- Week 2 Date
	int nWeekMask;			//��������               ������������Ϊ���յ�����
	SDK_SYSTEM_TIME	dateBegin;
	SDK_SYSTEM_TIME dateEnd;
}DOWNLOAD_PERIOD,*pDOWNLOAD_PERIOD;

typedef struct _DOWNLOAD_PLAN_
{	
	int nPeriodNum;
	DOWNLOAD_PERIOD recPeriod[6];
}DOWNLOAD_PLAN,*pDOWNLOAD_PLAN;

typedef struct _DWONLOAD_FILE_INFO_
{
	HANDLE hFileHandle;
	int  nFileType;
	H264_DVR_FILE_DATA fileData;
	char szPath[256];
	int nDownloadSize;
}DOWNLOAD_FILE_INFO;

typedef enum DOWNLOAD_MSG
{
	DOWNLOAD_PLAN_SEARCH,
	DOWNLOAD_PLAN_REGISTER,
	DOWNLOAD_PLAN_UNREGISTER,
	DOWNLOAD_PLAN_START,
	DOWNLOAD_PLAN_STOP,
	DOWNLOAD_PLAN_LOGINDEV,
	DOWNLOAD_PLAN_LOGOUTDEV,
};

typedef enum DOWNLOAD_STATUS
{
	DOWNLOAD_NONE,				//û������
	DOWNLOAD_START,				//��ʼ���أ��������أ�
	DOWNLOAD_PAUSE,				//��ͣ����
	DOWNLOAD_STOP,				//ֹͣ����
	DOWNLOAD_ERROR_NOSPACE,		//����ʧ�ܣ�û�п��ÿռ�
};

typedef enum DOWNLOAD_FILE_TYPE
{
	DOWNLOAD_FILE_NONE = 0,
	DOWNLOAD_FILE_NORMAL = 1,
	DOWNLOAD_FILE_DETECT = 2,
	DOWNLOAD_FILE_ALARM = 3,
};

typedef struct{
	int lLoginID;   //��¼ID��
	int lDevID;     //�豸ID��
	int nChannel;	//ͨ����
	DOWNLOAD_FILE_INFO FileCurInfo;	//��ǰ�����ļ���Ϣ
	SDK_SYSTEM_TIME timeBegin;		//��ʼʱ��
	SDK_SYSTEM_TIME timeEnd;		//����ʱ��
}DOWNLOADPLAN_INFO,*LPDOWNLOADPLAN_INFO;

//�ƻ�¼������
typedef struct _DOWNLOAD_PLAN_DATA_
{
	long lLoginID;  //��½���
	long lDevID;    //�豸ID
	char szDevName[64]; //�豸��
	int nChannel;   //ͨ����
	DOWNLOAD_PLAN DownloadPlan[7]; //¼��ƻ�ʱ���
}DOWNLOAD_PLAN_DATA;


#endif  //DOWNLOADPLAN_DEF_H