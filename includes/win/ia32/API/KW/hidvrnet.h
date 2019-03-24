
/******************************************************************************
 *	File Name		: HiDvrNet.h
 *	Description		: Net API Header file
 *	Version			: Initial Draft
 *	Author			: LAN CASTLE Technologies Co., LTD
 *	Created			: 	
 *	History			:
 *	  1.Date			: 2010/09/15
 *		Author			: 
 *		Modification	: Created file
 ******************************************************************************/
#ifndef NET_DLLAPI_H
#define NET_DLLAPI_H

#include <time.h>



#define WINAPI __stdcall
#include <windows.h>
#include "hi_type.h"
#include "hi_commom_errcode.h"
#include "hi_common_structs.h"
#include "hi_net_type.h"
#include "VMS_pubDefine.h"




#define NEW_USERMANAGER		//add by zk[2010/9/25]
#define NEW_ALARM			//add by zk[2010/10/18]
//#define USE_GPRS			//add by zk[2011/5/3]

#ifdef NEW_USERMANAGER
#define MAX_USERNAME_LEN	8
#define MAX_USERNUM			8		//admin + 7 general user
#define MAX_USERPSW_LEN     6
#endif

/*===========add zk [2010/11/29]=============*/
#define QUESTINFORMATION	0x32
#define QUESTSUCESS			0x24
#define QUESTFAILED			0x25
/*===========================================*/

#ifdef NEW_USERMANAGER
typedef struct tag_VMSRES_MSG_HEAD_EXT
{
	int     packagelen;
	int     errorcode;
	int     userpri;
	int     remoteuserpri;
}vms_resp_headext;

 typedef struct 
{
	   int    UserPri;						//user permission
	   int    RemoteUserPri;				//remote user permission
}userpswpri_setting_vms;
#endif

/*==============add zk [2010/11/29]==========================*/
//struct stRegisterMessage
//{
//	char userID[40];
//	unsigned int	ip;
//	unsigned short	m_VideoPort;
//	unsigned short	m_CommandPort;
//};
//
//struct stUNRegisterMessage
//{
//	char userID[40];
//	unsigned int	ip;
//	unsigned short	m_VideoPort;
//	unsigned short	m_CommandPort;
//};

struct stQuestMessage
{
	char userID[40];
	unsigned int	ip;
	unsigned short	m_VideoPort;
	unsigned short	m_CommandPort;
	unsigned short	m_HttpPort;
	//unsigned short  m_MobilePort;
	char			Reserve[16];//[14];
};

struct stMessage
{
	int iMessageType;
	//union _message
	//{
		//stRegisterMessage	registermember;
		//stUNRegisterMessage	unregistermember;
		stQuestMessage		questIpPort;
	//}message;
};
/*===============================================================*/



// Define the version of the network library
#define	NET_SDK_VERSION	    	"1.1.1.3"
#define NET_SRDK_VERSION        "1.1.1.3"
#define NET_SDK_COMPILE_TIME	"2010-10-27"

// Initialize and Uninitiaize
long WINAPI HI_DVR_NET_Init();
void WINAPI HI_DVR_NET_Cleanup();

// Get the version of the network library
char *WINAPI HI_DVR_NET_GetSDKVersion();
char *WINAPI HI_DVR_NET_GetSRDKVersion();

#ifdef NEW_USERMANAGER

HANDLE	WINAPI  HI_DVR_NET_Open_Device_Ex(char *IPAdress, long nPortconst, long nCPort,char * username,  char * passwd,
									HI_DVR_TYPE *type, HI_DVR_SUBTYPE *subType ,long* lErr, vms_resp_headext* pPri, long serverType=0);

HANDLE	WINAPI  HI_DVR_NET_Open_Device(char *IPAdress, long nPortconst, char * username,  char * passwd,
									HI_DVR_TYPE *type, HI_DVR_SUBTYPE *subType ,long* lErr, vms_resp_headext* pPri, long serverType=0);

#else
HANDLE	WINAPI  HI_DVR_NET_Open_Device(char *IPAdress, long nPortconst, char * username,  char * passwd,
									HI_DVR_TYPE *type, HI_DVR_SUBTYPE *subType ,long* lErr, long serverType=0 );
#endif

long	WINAPI  HI_DVR_NET_Close_Device(HANDLE DvrHandle);

////////////////////////////////////////////////////////////////////////
long WINAPI	HI_DVR_NET_GetDvrUID(HANDLE hDvrHandle, unsigned char *pUID/*maximum size 10bytes*/, int *pUIDLen);
////////////////////////////////////////////////////////////////////////
// Capture data
long	WINAPI	HI_DVR_NET_SetRealDataCallBack(HANDLE DvrHandle, long ch_id, 
													  DWORD dwUserData, kwRealDataCallBack pfn);

// chid:0~17
long	WINAPI	HI_DVR_NET_StartRealAV(HANDLE DvrHandle, BOOL RealTimeVideo, long ch_id, HWND hWnd, 
		        RECT *DesRect, long transMode=TRANS_VIDEO_FRAME_VMS, long stream=TRANS_MAINSTREAM, 
				char* userName=NULL, char* userPwd=NULL);

long	WINAPI  HI_DVR_NET_StopRealAV(HANDLE DvrHandle, long ch_id);

long	WINAPI	HI_DVR_NET_OpenStreamSound(HANDLE DvrHandle, long ch_id);  //in use
long	WINAPI	HI_DVR_NET_CloseStreamSound(HANDLE DvrHandle, long ch_id); //in use
long	WINAPI	HI_DVR_NET_SetStreamVolume(HANDLE DvrHandle, long ch_id, long Value);

long	WINAPI  HI_DVR_NET_UpdateFiletoDvr(HANDLE DvrHandle, char *SourceFilename);
long	WINAPI	HI_DVR_NET_SetFileDataCallBackVMS(HANDLE DvrHandle, DWORD dwUserData, DataCallBack pfn);
long	WINAPI	HI_DVR_NET_VodDownloadClipVMS( HANDLE hDvrHandle, char* pszSouFileName, long lOffSetFlag,
										  long lBeginOffSet, long lEndOffSet, long lOffSet );
long	WINAPI  HI_DVR_NET_StopDownLoadVideoFile(HANDLE DvrHandle);

HANDLE WINAPI HI_DVR_NET_PlayBackByTime(HANDLE hDvrHandle, int iChn, LPNET_DVR_TIME lpStartTime, 
											LPNET_DVR_TIME lpStopTime, HWND hWnd);
long WINAPI HI_DVR_NET_StopPlayBack(HANDLE hPlayHandle);
long WINAPI HI_DVR_NET_SetPlayBackDataCallBack(HANDLE hPlayHandle, pfnPlayBackDataCallback fnPlayBackDataCallback, DWORD dwUserData);
long WINAPI HI_DVR_NET_PlayBackControl(HANDLE hPlayHandle, DWORD dwControlCode, char *lpInBuffer, DWORD dwInLen, char *lpOutBuffer, DWORD *lpOutLen);


// Search file
long	WINAPI  HI_DVR_NET_FreeFileList( file_list_t  *filelst );
long	WINAPI  HI_DVR_NET_SearchAVFileList(HANDLE DvrHandle, long channel, tm * tm_start, tm *tm_end, 
				file_list_t *FileList, char* cardnum = NULL, long fileType=1, file_list_VMS* FileListvms=NULL);


// Control PTZ
long	WINAPI	HI_DVR_NET_PZTAction(  HANDLE DvrHandle, house_netcontrol *hn, long iChl, char* devid=NULL );


// Intercom
long	WINAPI	HI_DVR_NET_OpenTalk( HANDLE hDvrHandle, VMS_Talk_S *pStuTalkParam, MediaDataEventCallBack RecvAudioData, void *pUserData );
long	WINAPI	HI_DVR_NET_CloseTalk( HANDLE hDvrHandle, VMS_Talk_S *pStuTalkParam);
long	WINAPI	HI_DVR_NET_SendAudioData( HANDLE hDvrHandle, unsigned char *pDataBuffer, long lDataLength, unsigned __int64 Pts );
long	WINAPI	HI_DVR_NET_SendTalkQst(HANDLE hDvrHandle); // add by dee,2011.01.26 	

long	WINAPI    HI_DVR_NET_GetHostByName(char* szHostName, char* szIP);
char*	WINAPI	HI_DVR_NET_GetMD5Code( char* buffer, long bufferLen );


// For C2/MINI and the new added device
long	WINAPI	HI_DVR_NET_SetAllConfigParaEx( HANDLE DvrHandle, DVR_ConfigPara_S* ConfigPara);
long	WINAPI	HI_DVR_NET_GetAllConfigParaEx( HANDLE DvrHandle, DVR_ConfigPara_S* ConfigPara);


// Shutdown machine
long	WINAPI	HI_DVR_NET_ShutDownMachine(HANDLE DvrHandle, long nType);


// Format HD
long	WINAPI HI_DVR_NET_FormatHdd( HANDLE DvrHandle, HI_HDI_FORMAT &hdi );


long	WINAPI	HI_DVR_NET_GetVideoFileCalendar(HANDLE DvrHandle, datetime_setting_t date, char* devid, long* lCalendarMap=NULL);
long	WINAPI	HI_DVR_NET_GetLogCalendar(HANDLE DvrHandle, datetime_setting_t date, char* devid);

#ifdef NEW_USERMANAGER
long	WINAPI	HI_DVR_NET_CheckAdminPwd( HANDLE hDvrHandle, char* pszUserName, char* pszUserPwd, char* pszDevId, vms_resp_headext* pPri);
#else
long	WINAPI	HI_DVR_NET_CheckAdminPwd( HANDLE hDvrHandle, char* pszUserName, char* pszUserPwd, char* pszDevId );
#endif

/*================add zk [2010/11/29]=========================*/
long	WINAPI	HI_DVR_NET_GetDvrIpPort(LPCSTR SendID /*,LPCSTR SendIP, int SendPort*/, stMessage *stRecv);
/*============================================================*/

long WINAPI HI_DVR_NET_CreateSearchDevRes();
void WINAPI HI_DVR_NET_DestroySearchDevRes();
void WINAPI HI_DVR_NET_SetSearchDevCallback(pfnSearchDevCallback fnSearchDevCallback, DWORD dwUser);
long WINAPI HI_DVR_NET_SearchDVR();

void WINAPI	HI_DVR_NET_SetAlarmDataCallback(pfnAlarmDataCallback pfnAlarmCallback, DWORD dwAlarmUser);

long WINAPI HI_DVR_NET_RequestIFrame(HANDLE DvrHandle, enciqr_vms *pstIFrameCmd );	//add by zk [2011/8/4]

#endif

