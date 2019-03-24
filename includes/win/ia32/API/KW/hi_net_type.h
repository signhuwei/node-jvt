
#ifndef _RMNETYPES_H_
#define _RMNETYPES_H_


#define TRANS_NODIVSTREAM					-1			// No matter main or sub stream
#define TRANS_MAINSTREAM					0x01		// Main stream	
#define TRANS_SUBSTREAM						0x00		// Sub stream

// upgrade error


/*------------------ Status of remote playback ----------------------*/
/*******************************************************************************
While playback, user will get the register message. Here we define the meaning of lParam parameter which correspond to the wParam parameter.
Ex. The lParam which correspond to RPUM_WFILELENGTH is the file length. If the highest 4 digits are 1, it defined by Network library. 
If the highest 4 digits are 2, it defined by Decoder library.

RP = Remote Play
UM = User Message
W = Wparam

*******************************************************************************/
#define	RPUM_WNFILELENGTH				0x20000011			// file's length
#define	RPUM_WDOWNINGPOS				0x10000002			// Position to start download. Each time send this message before starting download
#define	RPUM_WDOWNSIZE					0x10000003			// Download size. It’s the size for each time; not the total downloaded size
#define	RPUM_WDOWNEDSIZE				0x10000013			// Total downloaded size
//#define	RPUM_WPLAYINGPOS				0x20000001			//  the position of playing , the definition is saved in the decorder.
#define	RPUM_WDOWNFINISH				0x10000004			// Download finish

#define	RPUM_WCNNBREAK					0x10000005			// Connection broken，lParam is defined below
#define	RPUM_LCBUNKNOWN					0x10100000			// Unknown reason. because received the “exit” message
#define	RPUM_LREADCNNFAILED				0x10100001			// Read data faileded
#define	RPUM_LFLTOOLSHORT				0x10100002			// File too short
#define	RPUM_LOPENDECODERFAILED			0x10100003			// Open decoder failed
#define	RPUM_LFINISHD					0x10100004			// Download finish
#define	RPUM_LBYUSER					0x10100005			// Closed by user

#define	RPUM_WCREATINGFILE				0x10000006			// Creating file.lParam invalid
#define	RPUM_WCREATEDFILE				0x10000007			// Created file.lParam invalid

#define	RPUM_WOPENFILEFAILED			0x10000008			// Open file failed，lParam invalid
#define	RPUM_WCNNFAILED					0x10000009			// Connection failed
#define	RPUM_WMEMOUT					0x1000000A			// Memory error
#define	RPUM_WSCKSENDFAILED				0x1000000B			// Socket send failed
					

#define RPUM_WDOWNLOADFAILED			0x1000000C			// Download failed, causeed by lParam, the reason include:
/*
 E_DOWNING_ERROR,			File downloading…, can not download again 
 E_MEMRY_OUT,				Memory out 
 E_OPENFILE_ERROR,			Open file error 
 E_CREATETHREAD_ERROR,		Create thread error 
 E_FILE_RECORDING,			File recording 
*/

#define	RPUM_WOPENDECODERFAILED			0x10000010			// Open decoder failed.lParam invalid

// For testing 
#define RPUM_WTRYTIMES					0x1000001F			// Retry time


// Clip the third interface 
#define RPUM_WNCLIPSTART				0x10000021			// Start clip
#define RPUM_WNCLIPEND					0x10000022			// Clip end. lParam is the result. 1 for success, 2 for failed

// Format HDD
#define RPUM_WNFMTHDD					0x10000030
#define RPUM_LNFMTHDDSTART				0x10100011			// Format HDD start
#define RPUM_LNFMTHDDFINISH				0x10100012			// Format HDD finish
#define RPUM_LNFMTHDDNOHDD				0x10100013			// No HDD
#define RPUM_LNFMTHDDFAILED				0x10100014			// Format HDD failed
#define RPUM_LNFMTHDDGOING				0x10100015			// Formatting HDD
#define RPUM_LNFMTHDDUNKNOWN			0x101000FF			// Unknown status

// search file
#define RPUM_WNSEARCHFILE				0x10000040
#define RPUM_WNSEARCHFILEFOK			0x10000041			// search finish, lParam is the filelist

#define RPUM_WSENTFINISH				0x10000042			// Sent file finish
#define RPUM_WSENTING					0x10000043			// Sending file
#define RPUM_HDSPACE					0x10000044			// HDD free space




/**************************** C/S start ***************************/
/* Length of ID field. Actually 16 bytes. For Hex., it divide to 4 sections (add 3 pieces“-”in the middle), so change to 16 * 2 + 3 = 35 */
#define	HI_NET_LEN_ID				36

/* trans_mode type */
#define TRANS_I_FRAME_VMS						0x00
#define TRANS_VIDEO_FRAME_VMS					0x01
#define TRANS_I_AUDIO_FRAME_VMS					0x02
#define TRANS_ALL_FRAME_VMS						0x03


// #define TRANS_MAINSTREAM						0x01
// #define TRANS_SUBSTREAM						0x00


/*************************************************
回放时播放控制命令宏定义 
具体支持查看函数说明和代码
**************************************************/	
#define NET_DVR_PLAYSTART				1//开始播放
#define NET_DVR_PLAYSTOP				2//停止播放
#define NET_DVR_PLAYPAUSE				3//暂停播放
#define NET_DVR_PLAYRESTART			4//恢复播放
#define NET_DVR_PLAYFAST				5//快放
#define NET_DVR_PLAYSLOW				6//慢放
#define NET_DVR_PLAYNORMAL			7//正常速度
#define NET_DVR_PLAYFRAME				8//单帧放
#define NET_DVR_PLAYSTARTAUDIO	9//打开声音
#define NET_DVR_PLAYSTOPAUDIO		10//关闭声音
#define NET_DVR_PLAYAUDIOVOLUME	11//调节音量
#define NET_DVR_PLAYSETPOS			12//改变文件回放的进度
#define NET_DVR_PLAYGETPOS			13//获取文件回放的进度
#define NET_DVR_PLAYGETTIME			14//获取当前已经播放的时间(按文件回放的时候有效)
#define NET_DVR_PLAYGETFRAME		15//获取当前已经播放的帧数(按文件回放的时候有效)
#define NET_DVR_GETTOTALFRAMES  16//获取当前播放文件总的帧数(按文件回放的时候有效)
#define NET_DVR_GETTOTALTIME    17//获取当前播放文件总的时间(按文件回放的时候有效)
#define NET_DVR_THROWBFRAME			20//丢B帧
#define NET_DVR_PLAYBACK   					21//回退

// 报警回调命令类型
#define CMD_UPLOADALARMDATA		0x0001
#define CMD_DEVNETSTATUS		0x0002

// Record file parameter searched for 
typedef struct
{
	int				file_size;		// Record file size; By byte
	int 			rec_type;		// Record type; 1: Normal record, 2: Alarm record,3: Record all
	
	int				channel;		/* Channel; which channel are searched for specifically. Using 4 ASCII code to show 2 bytes of hexadecimal system.The bit value set to 1 expresses to search for the corresponding channel. Bit 0 to bit 15 means 1 to 16 channel */
	
	char			file_name[128];	/* Record file name, use the full path of device */
	
	/* The start time of recorded file */
	unsigned char	start_hour;
	unsigned char	start_min;
	unsigned char	start_sec;
	
	/* The end time of recorded file */
	unsigned char	end_hour;
	unsigned char 	end_min;
	unsigned char	end_sec;
	unsigned char reserve[2];
}search_file_setting_VMS;


typedef struct tag_file_list
{
	int num;				// File number 
	//char ** f_list;			// File name
	search_file_setting_VMS	*pFileInfo;
}file_list_VMS;


typedef struct
{
	unsigned char	year;	/* Year for log search, between 0 to 255 to present 2000 to 2255 year */
	unsigned char	month;	// Month for log search，between 1 to 12
	unsigned char	day;	// Day for log search, Not use now 
	unsigned char	type;	// Log type; 0-record file, 1-log file 
}calenda_setting_vms;



/*
The ID information of remote side
Decribe the information part: If sent from the remote side, then add to the end of this structure.
If inside this SDK or communicate with the upper level, then need to add the last member.
In order to distinguish this two situation, we defined two kind of structure.
N - Net, which means transmit by network. S – SDK, which means inside the SDK or communicate with the upper level. 
The HI_ID_NINFO is defined inside the SDK.
*/
struct HI_ID_SINFO
{
	char			szID[ HI_NET_LEN_ID ];
	char			szName[ HI_NET_LEN_ID ];
	short			shChannel;
	unsigned short	usLengthDesc;
	TCHAR			*pszDescription;	// If usLengthDesc==0，then this member is NULL or ""
};

/*************************************************************************************
The requested video channel; lValueCount means the channel acount. Ex. Asked for the channel 0, channel 2：lValueCount = 2; szValue[0] = 0; szValue[1] = 2;
*************************************************************************************/
struct HI_NP_LAPVALUE
{
	long	lValueCount;
	char	szValue[16];
};



// media data call-back
struct HI_NP_MEDIADATA
{
	unsigned long	lErrorCode;
	HI_ID_SINFO		stuRemoteID;			//Device ID and describe information
	unsigned short	shCMD;					//Data type
	HI_NP_LAPVALUE	stuChannel;				//Channel; Valid when stuCMD==RMCMD_REG_MVIEW
	char			szFileName[256];		//File name; Valid when stuCMD==RMCMD_REG_MDOWNLOAD
	char			szSessionID[HI_NET_LEN_ID];	//Session ID
	union _CI_INFO
	{
		struct _BI_INFO
		{
			long	lLenBuf;				// Data length
			char	*pVoid;
		} stuBufInfo;
		struct _REQ_INFO					// Use when apply CALLBACK
		{
			bool	bSwitch;				// Request open or close
		} stuReqInfo;
	} exInfo;
};

/************************** C/S END *************************/

// Information of format HDD 
struct HI_HDI_FORMAT
{
	unsigned long	hddIndex;				// HDD index，begin from 0
	unsigned long	driverIndex;			// Driver index，begin from 0
};


#pragma pack(push, 2)
// time parameter
typedef struct tag_datetime_setting {
	unsigned char year;			
	unsigned char month;		
	unsigned char day;
	unsigned char week;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
} datetime_setting_t;



// Information of file list 
typedef struct file_info
{
	char	*pszFileName;
	int		iLenTime;			// Time length, by minute, use on MDVR only 
} file_info_t;


typedef struct file_list
{
	int num;		//	File number
	//char ** f_list;	// File name
	file_info	*pFileInfo;
}file_list_t;


typedef struct tag_house_netcontrol
{
    unsigned long order_type;  
	unsigned long pointer;		//Preset pointer; value: 1-127
	unsigned long speed;		//Preset speed; value: 1-255; Setting up the speed of the previous and the next preset
	unsigned long dwell_time;	//Preset dwell time; value: 0-255; Setting up the interval speed between the previous and the next preset
	unsigned long times;        //Cruise times
}house_netcontrol;


// For c2, mini use 
typedef struct tag_CONFIGPARAEx{
	unsigned long		ChipNumber;			// clip number
	unsigned long		len;				// Length of the structure
	unsigned long		para1;
	char*				para2;
}DVR_ConfigPara_S;


#define	CALLBACK_OTHER	-1
#define CALLBACK_LINKBUILD		-2
#define CALLBACK_LINKBREAK		-3


struct CallBackData 
{ 
	long lBufferLen;	//lBufferLen=CALLBACK_OTHER or lBufferLen>0
	long lTotalLen;		//if(lBufferLen==CALLBACK_OTHER) {lTotalLen=CALLBACK_LINKBUILD or CALLBACK_LINKBREAK}
	void* pVoid;
};

typedef struct tag_SearchDevInfo
{
	int iType;								// 1DVR, 2IPCamera, 0 Completely
	unsigned char IPAddr[4];	
	unsigned char sMac[6];
}SearchDevInfo;

typedef struct hiCFG_ALARMSTATUS_S
{
    unsigned char  u8Record[16];		/**< DVR recording: 0-no, 1-recording*/
    unsigned char  u8Motion[16];		/**< MD alarming: 0-no,1-alarming*/
    unsigned char  u8Sensor[16];		/**< sensor alarming: 0-no,1-alarming*/
    unsigned char  u8VideoLoss[16];      /**< video loss?: 0-no，1-loss*/
    unsigned char  u8Hdd;		/**< HDD loss?: 0-no，1-loss*/
    unsigned char  u8Align[7];       /**< 8 byte align*/
} HI_CFG_ALARMSTATUS_S;


typedef struct lbCFG_UPLOADALARMDATA_S
{
	unsigned short nID;		// 帧包类型ID	0xa1
	unsigned short nLength;	// 帧包长度	
	HI_CFG_ALARMSTATUS_S stAlarmStatus;
}LB_CFG_UPLOADALARMDATA_S;

typedef struct tagDEVNETSTATUS
{
	bool bOnlineFlag;
}DEVNETSTATUS;

typedef struct 
{
	int iYear;
	int iMon;
	int iDay;
	int iHour;
	int iMin;
	int iSec;
}KW_NET_DVR_TIME, *KW_LPNET_DVR_TIME;


typedef struct 
{
	int iYear;
	int iMon;
	int iDay;
	int iHour;
	int iMin;
	int iSec;
	int iMilSec;
}FRAMETIME;

/******************* Define all CALLBACK functions **********************/
typedef void (CALLBACK* kwRealDataCallBack) (HANDLE DvrHandle, long ch_id, \
										   DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, DWORD dwUser);
typedef void (CALLBACK* DataCallBack)(DWORD dwUserData, const CallBackData* pstuDataInfo);

// Video and Audio CALLBACK 
typedef void (CALLBACK* MediaDataEventCallBack)(/*DWORD*/void* dwUserData, HI_NP_MEDIADATA *pConnection);

typedef int (CALLBACK* pfnSearchDevCallback)(void *pData, int iDataLen, DWORD dwUser);

typedef int (CALLBACK* pfnAlarmDataCallback)(char* pIpAddress,int iCmdType, void *pData, int iDataLen, DWORD dwUser);
typedef void (CALLBACK *pfnPlayBackDataCallback)(HANDLE lPlayHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, DWORD dwUserData);

#pragma pack(pop)

#endif
