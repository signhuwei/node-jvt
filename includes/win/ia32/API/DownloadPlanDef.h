#ifndef DOWNLOADPLAN_DEF_H
#define DOWNLOADPLAN_DEF_H

typedef struct _DOWNLOAD_PERIOD_
{	
	bool bEnable;
	int nFileType;        //下载类型掩码
	int nDownloadTimeBegin;			//下载开始时间（分钟）
	int nDownloadTimeEnd;			//下载结束时间（分钟）
	int	nfileTimeBegin;				//文件开始时间（秒）
	int nfileTimeEnd;				//文件结束时间（秒）
	int nTaskType;			//0 -All 1- Week 2 Date
	int nWeekMask;			//星期掩码               从右往左依次为周日到周六
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
	DOWNLOAD_NONE,				//没有下载
	DOWNLOAD_START,				//开始下载（正在下载）
	DOWNLOAD_PAUSE,				//暂停下载
	DOWNLOAD_STOP,				//停止下载
	DOWNLOAD_ERROR_NOSPACE,		//下载失败，没有可用空间
};

typedef enum DOWNLOAD_FILE_TYPE
{
	DOWNLOAD_FILE_NONE = 0,
	DOWNLOAD_FILE_NORMAL = 1,
	DOWNLOAD_FILE_DETECT = 2,
	DOWNLOAD_FILE_ALARM = 3,
};

typedef struct{
	int lLoginID;   //登录ID号
	int lDevID;     //设备ID号
	int nChannel;	//通道号
	DOWNLOAD_FILE_INFO FileCurInfo;	//当前下载文件信息
	SDK_SYSTEM_TIME timeBegin;		//开始时间
	SDK_SYSTEM_TIME timeEnd;		//结束时间
}DOWNLOADPLAN_INFO,*LPDOWNLOADPLAN_INFO;

//计划录像数据
typedef struct _DOWNLOAD_PLAN_DATA_
{
	long lLoginID;  //登陆句柄
	long lDevID;    //设备ID
	char szDevName[64]; //设备名
	int nChannel;   //通道号
	DOWNLOAD_PLAN DownloadPlan[7]; //录像计划时间表
}DOWNLOAD_PLAN_DATA;


#endif  //DOWNLOADPLAN_DEF_H