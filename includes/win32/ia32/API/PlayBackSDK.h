#ifndef PLAYBACK_H
#define PLAYBACK_H

#ifdef PLAYBACK_EXPORTS
#define PLAYBACK_API extern "C"	__declspec(dllexport)
#else
#define PLAYBACK_API extern "C"	__declspec(dllimport)   //VC 用
#endif



//标题显示模式
enum MENU_TYPE
{
	HEADER_HIDE,		//隐藏
	HEADER_SHOW,		//显示
	HEADER_HIDE_V2,		//隐藏V2版本
	HEADER_SHOW_V2,		//显示V2版本
};	

//播放类型
enum PLAY_TYPE
{
	PLAYSDK_NOTHING = 0,
	PLAYSDK_LOCAL,		//本地回放
	PLAYSDK_NET,
	PLAYSDK_IPS,
	PLAYSDK_SAVESERVER,
	PLAYSDK_TIME,		//时间段回放
};	


//回调消息类型
enum MSGCALL_TYPE
{
	MSG_NET_PLAY,
	MSG_NET_TIMEPLAY,
	MSG_NET_CLOSE,
	MSG_NET_RESUME,
	MSG_NET_PAUSE,
	MSG_NET_SEEK,
	MSG_NET_DOWNLOAD,	//录像下载
	MSG_NET_ENDLOAD,	//停止下载
	MSG_NET_SEARCH,	//录像查询
	MSG_NET_FAST,
	MSG_NET_SLOW,
	MSG_NET_DOWNLOADBYTIME,//按时间下载
	MSG_OPEN_AUDIO,
	MSG_CLOSE_AUDIO,
};	


//设备网络回放结构体
typedef struct _NETPLAY_INFO
{
	H264_DVR_FILE_DATA	fileInfo;		//文件信息
	DEVICE_INFO			sDevInfo;		//设备信息
}NETPLAY_INFO;

//设备网络回放结构体
typedef struct _TIME_NETPLAY_INFO
{
	DWORD				dwLoginID;		//设备登陆句柄或者流媒体句柄
	DEVICE_INFO			sDevInfo;		//设备信息
	int					nChannelNo;		//通道号
	H264_DVR_TIME			TmStart;		//开始时间
	H264_DVR_TIME			TmEnd;			//结束时间
	int nRecType;                          //录像类型
}TIME_NETPLAY_INFO;

//设备网络回放控制结构体
typedef struct _NETPLAYCONTROL_INFO
{
	DWORD				dwLoginID;		//设备登陆句柄或者流媒体句柄
	DWORD				dwHandle;		//播放句柄(open时候返回)
	DWORD				dwDevID;		//设备ID
	int					nChannelNo;		//播放通道
	unsigned int		offsetTime;		//时间偏移
	unsigned int		offsetByte;		//位置偏移
}NETPLAYCONTROL_INFO;	


//设备网络回放控制结构体
typedef struct _DOWNLOAD_INFO
{
	DWORD				dwLoginID;		//设备登陆句柄或者流媒体句柄
	DWORD				dwDevID;		//设备ID
	H264_DVR_FILE_DATA	fileInfo;		//文件信息
	char				szFileName[256];
	int nFileType;
}DOWNLOAD_INFO;


//错误码
#define PLAYBACK_OPENFILE_ERROR		-1000	//打开文件失败(本地回放)
#define PLAYBACK_HSAPLAY			-1001	//当前通道已经在回放
#define PLAYBACK_NETDATA_ERROR		-1002	//请求网络数据失败
#define PLAYBACK_DECODE_FAILED		-1003	//打开解码失败
#define PLAYBACK_MAX_CHANNEL		-1004	//超过最大回放路数
#define PLAYBACK_NATCONNET_MAX       -1005    //超过NAT 最大连接
















typedef int (CALLBACK *fMsgCallBack)(char* pMsgInfo, DWORD dwMsgType, 
									 void *pDownloadPosCallback,
									 void *pNetDataCallback, 
									 DWORD dwUser);

/*	$Function		:	Playback_Init
==  ===============================================================
==	Description		:	初始化
==	Argument		:	nLanguage		语言ID
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/	
//PLAYBACK_API BOOL Playback_languageInit(int nLanguage);

/*	$Function		:	Playback_Init
==  ===============================================================
==	Description		:	初始化
==	Argument		:	strLanguage		语言名称
== 	Return			:	TRUE,FALSE
==  ===============================================================
*/	
PLAYBACK_API BOOL Playback_languageInit(CString strLanguage);

/*	$Function		:	Playback_Init
==  ===============================================================
==	Description		:	初始化
==	Argument		:	pWnd		内部窗口的父窗体
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/	
PLAYBACK_API CWnd* Playback_Init(CWnd* pWnd, fMsgCallBack fcallback);



/*	$Function		:	Playback_UnInit
==  ===============================================================
==	Description		:	反初始化
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_UnInit();


/*	$Function		:	Playback_SetStyle
==  ===============================================================
==	Description		:	设置显示模式
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_SetStyle(int nStyle);


/*	$Function		:	Playback_Move
==  ===============================================================
==	Description		:	移动窗体
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_Move(LPCRECT lpRect);


/*	$Function		:	Playback_ShowWindow
==  ===============================================================
==	Description		:	显示或者隐藏
==	Argument		:	
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_ShowWindow(int nCmdShow);


/*	$Function		:	Playback_InsertDevice
==  ===============================================================
==	Description		:	加入新的设备
==	Argument		:	pDevInfo	设备信息
						nType		1 == 加入 2 == 删除
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API BOOL Playback_InsertDevice(char* pDevInfo, int nType);


/*	$Function		:	Playback_OpenVideo
==  ===============================================================
==	Description		:	打开回放
==	Argument		:	pFileInfo	播放的文件信息	
					:	dwSize		播放个数(可能存在连续回放)			
					:	dwType		播放类型(本地文件播放: pFileInfo 代表文件路径 )
									(设备端网络回放, IPS回放,存储服务回放)
					:	dwReserved	保留字节
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API int Playback_OpenVideo(char* pFileInfo, DWORD dwInfoSize, DWORD dwSize, DWORD dwType, DWORD dwReserved = 0, DWORD dwWndIndex  = -1 );


/*	$Function		:	Playback_CloseVideo
==  ===============================================================
==	Description		:	关闭回放
==	Argument		:	当没有参数
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API int Playback_CloseVideo(long lLoginID = 0, long lDevID = 0, int nChannelNo = 0, DWORD dwType = 0, DWORD dwReserved = 0);


/*	$Function		:	Playback_StartDownload
==  ===============================================================
==	Description		:	下载录像
==	Argument		:	pFileInfo		下载的文件信息
					:	pSaveFileName	保存的文件名称,包含绝对路径	
					:	dwSize			播放个数(可能存在连续回放)	
					:	dwType			播放类型(设备端网络回放, IPS回放,存储服务回放)
					:	poscallback		进度回调	
					:	dwUserd			回调句柄
					:	dwReserved		保留
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API int Playback_StartDownload(char* pFileInfo, char *pSaveFileName, DWORD dwSize, DWORD dwType, void *poscallback, DWORD dwUserd, DWORD dwReserved = 0);


/*	$Function		:	Playback_EndDownload
==  ===============================================================
==	Description		:	停止下载录像
==	Argument		:	暂时只能同时下载一个, 所以关闭的时候什么参数都可以不输入
== 	Return			:	TRUE,FALSE
==	Modification	:	2008-09-26     sunjie    Create
==  ===============================================================
*/
PLAYBACK_API int Playback_EndDownload(long lDevID = 0, int nChannelNo = 0, DWORD dwType = 0, DWORD dwReserved = 0);


PLAYBACK_API BOOL Playback_ControlAudio(bool bAudio = FALSE);




#endif