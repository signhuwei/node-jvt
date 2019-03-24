
#ifndef DHSYSABLE_H
#define DHSYSABLE_H


//////////////////////////////////////////////////////////////////////////
//	Search Type
typedef enum
{
	ABILITY_WATERMARK_CFG = 17,			// Watermark configuration capacity
	ABILITY_WIRELESS_CFG = 18,			// wireless  confuguration capacity
	ABILITY_DEVALL_INFO = 26,			// Device capacity list 
	ABILITY_CARD_QUERY = 0x0100,		// Card number search capacity 
	ABILITY_MULTIPLAY = 0x0101,			// Multiple-window preview capacity 
	ABILITY_QUICK_QUERY_CFG = 0x0102,	// Fast query configuration Capabilities
	ABILITY_INFRARED = 0x0121,			// Wireless alarm capacity 
	ABILITY_TRIGGER_MODE = 0x0131,		// Alarm activation mode function 
	ABILITY_DISK_SUBAREA = 0x0141,		// Network hard disk partition
	ABILITY_DSP_CFG = 0x0151,			// Query DSP Capabilities
	ABILITY_STREAM_MEDIA = 0x0161,		// Query SIP,RTSP Capabilities
} DH_SYS_ABILITY;

//////////////////////////////////////////////////////////////////////////
//	The function list device supported 
enum 
{
	EN_FTP = 0,							// FTP bitwise��1��send out record file;  2��Send out snapshot file
	EN_SMTP,							// SMTP bitwise��1��alarm send out text mail 2��Alarm send out image
	EN_NTP,								// NTP	 Bitwise��1��Adjust system time 
	EN_AUTO_MAINTAIN,					// Auto maintenance  Bitwise��1��reboot 2��close  3:delete file
	EN_VIDEO_COVER,						// Privacy mask Bitwise  ��1��multiple-window privacy mask 
	EN_AUTO_REGISTER,					// Auto registration	Bitwise��1:SDK auto log in after registration 
	EN_DHCP,							// DHCP	Bitwise��1��DHCP
	EN_UPNP,							// UPNP	Bitwise ��1��UPNP
	EN_COMM_SNIFFER,					// COM sniffer  Bitwise ��1:CommATM
	EN_NET_SNIFFER,						// Network sniffer Bitwise �� 1��NetSniffer
	EN_BURN,							// Burn function Bitwise 1��Search burn status 
	EN_VIDEO_MATRIX,					// Video matrix Bitwise  1��Support video matrix or not
	EN_AUDIO_DETECT,					// Video detection Bitwise ��1��Support video detection or not 
	EN_STORAGE_STATION,					// Storage position Bitwise��1��Ftp server (Ips) 2��SBM 3��NFS 16��DISK 17��Flash disk 
	EN_IPSSEARCH,						// IPS storage search  Bitwise  1��IPS storage search 	
	EN_SNAP,							// Snapshot Bitwise  1��Resoluiton 2��Frame rate 3��Snapshoot  4��Snapshoot file image; 5��Image quality 
	EN_DEFAULTNIC,						// Search default network card search  Bitwise  1��Support
	EN_SHOWQUALITY,						// Image quality configuration time in CBR mode 1:support 
	EN_CONFIG_IMEXPORT,					// Configuration import& emport function capacity.  Bitwise   1:support 
	EN_LOG,								// Support search log page by page or not. Bitwise 1��support 
	EN_SCHEDULE,						// Record setup capacity. Bitwise  1:Redandunce  2:Pre-record 3:Record period
	EN_NETWORK_TYPE,					// Network type. Bitwise 1:Wire Network 2:Wireless Network 3:CDMA/GPRS
	EN_MARK_IMPORTANTRECORD,			// Important record. Bitwise 1��Important record mark
	EN_ACFCONTROL,						// Frame rate control activities. Bitwise 1��support frame rate control activities;2:support timing alarm type activate frame rate control(it does not support dynamic detection), this ability mutually exclusive with ACF ability.
	EN_MULTIASSIOPTION,					// Multiple-channel extra stream. Bitwise��1��support three channel extra stream
	EN_DAVINCIMODULE,					// Component modules bitwise: 1.Separate processing the schedule 2.Standard I franme Interval setting
	EN_GPS,                             // GPS function bitwise:1:Gps locate function	
	EN_MULTIETHERNET,					// Support multi net card query   bitwise: 1: support
	EN_LOGIN_ATTRIBUTE,                 // Login properties   bitwise: 1: support query login properties  
	EN_RECORD_GENERAL,					// Recording associated  bitwise: 1:Normal recording; 2:Alarm recording; 
										// 3:Motion detection recording;  4:Local storage; 5: Network storage ;  
										// 6:Redundancy storage;  7:Local emergency storage
	EN_JSON_CONFIG,						// Whether support Json configuration, bitwise: 1: support Json
	EN_HIDE_FUNCTION,					// Hide function:bitwise::1��hide PTZ function
	EN_DISK_DAMAGE,                     // Harddisk damage information support ability: bitwisw��1��harddisk damage information
};

typedef struct 
{
	DWORD IsFucEnable[512];				// Function list capacity set. Corresponding to the above mentioned enumeration. Use bit to represent sub-function.
} DH_DEV_ENABLE_INFO;

//////////////////////////////////////////////////////////////////////////
//Card number search function structure 
typedef struct 
{
	char		IsCardQueryEnable;
	char		iRev[3];
} DH_CARD_QUERY_EN;

//////////////////////////////////////////////////////////////////////////
//	Wireless capacity structure 
typedef struct 
{
	char		IsWirelessEnable;
	char		iRev[3];
} DH_WIRELESS_EN;

//////////////////////////////////////////////////////////////////////////
//	Image watermark capacity structure 
typedef struct 
{
	char		isSupportWM;			// 1:Support��0 Do not support
	char		supportWhat;			// 0��Characrer watermark��1��Image watermark��2��Support character watermark and image watermark at the same time.
	char		reserved[2];
} DH_WATERMAKE_EN;

//////////////////////////////////////////////////////////////////////////
//	Multiple-window preview capacity structure 
typedef struct  
{
	int			nEnable;				// 1:Support��  0 :Do not support 
	DWORD		dwMultiPlayMask;		// Multiple-window preview mask 
	char		reserved[4];			// Reserved 
} DH_MULTIPLAY_EN;

//////////////////////////////////////////////////////////////////////////
//	Wireless alarm capacity structure 
typedef struct  
{
	BOOL		bSupport;				// Support or not 
	int			nAlarmInCount;			// Input amount
	int			nAlarmOutCount;			// Output amount 
	int			nRemoteAddrCount;		// Remote control amount 
	BYTE		reserved[32];
}DH_WIRELESS_ALARM_INFO;

//////////////////////////////////////////////////////////////////////////
// Network hard disk partition capacity structure
typedef struct 
{
	BOOL		bSupported;				// Support or not
	int			nSupportNum;			// Support the number of disk partition
	BYTE		bReserved[32];
} DH_DISK_SUBAREA_EN;

// DSP capabilities query ��use when DSP capabilities algorithm with ID 2.
typedef struct  
{
	BYTE bMainFrame[32];		//Use the resolution enumeration value (CAPTURE_SIZE) as index, the main code stream corresponds to the max resolution it support, if do not support, the value should be 0.
	BYTE bExtraFrame_1[32];		//Extra code stream1,use the same method as: bMainFrame
	BYTE bReserved[128];		//obligate for extra code stream 2 and 3.		
}DH_DSP_CFG_ITEM;

typedef struct  
{
	int nItemNum;						//Valid number of DH_DSP_CFG_ITEM, equals to channel number
	DH_DSP_CFG_ITEM	stuDspCfgItem[32];	//Main code stream Information
	BYTE bReserved[128];				//Retain
}DH_DSP_CFG; 

//////////////////////////////////////////////////////////////////////////
//	Fast query configuration capabilities struct 
typedef struct 
{
	char		IsQuickQueryEnable;    //1 is device support configuration command go back easily,please set enough configuration time to ensure reading the configuration in narrowband. Recommended for 60S
	char		iRev[3];
} DH_QUICK_QUERY_CFG_EN;

typedef struct  
{
	int			nStreamType;			// 0,null 1,SIP 2,RTSP
	BYTE		bReserved[16];			// Reserved
} DH_STREAM_MEDIA_EN;
#endif // DHSYSABLE_H

