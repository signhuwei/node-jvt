
#ifndef	_HI_COMMON_DEFINE_ERR_H_
#define	_HI_COMMON_DEFINE_ERR_H_


#ifdef __cplusplus
extern "C" {
#endif

//  4 byte align
#pragma pack(4)



// Error source definition, S = Source
#define		HI_ERR_SRC_NETWORK				0x00000001L
#define		HI_ERR_SRC_IO					0x00000002L
#define		HI_ERR_SRC_REMOTE				0x00000003L
#define		HI_ERR_SRC_AVDATA				0x00000004L
#define		HI_ERR_SRC_MEMORY				0x00000005L
#define		HI_ERR_SRC_PARAMETER			0x00000006L
#define		HI_ERR_SRC_THREAD				0x00000007L
#define		HI_ERR_SRC_OTHER				0x000000F0L
#define		HI_ERR_SRC_RESERVED				0x000000FEL		//Reserved
#define		HI_ERR_SRC_UNKNOWN				0x000000FFL




/***********************************************************************
 The definition of successful return value
************************************************************************/
#define     HI_ERR_SUCCESS					0x00000000L		// Completely success




/************************************************************************
 Unknown error, begin with HI_ERR_UNKNOWN_, 0xFF
************************************************************************/
#define		HI_ERR_UNKNOWN					0x80FF0000L		// Unknown error
#define		HI_ERR_UNKNOWN_ALL				0x80FF0000L		// General unknown error. If you could not judge or don't want to judge where the error is, you could use this error number.




/************************************************************************
Network error; begin with HI_ERR_NET_, 0x01
************************************************************************/
#define		HI_ERR_NET_NOTINIT				0x80010001L		// Not initial or failed
#define		HI_ERR_NET_CRSCK_FAILED			0x80010002L		// Create socket failed
#define		HI_ERR_NET_CONNECT_FAILED 		0x80010003L 	// Connect device failed
#define		HI_ERR_NET_SENDDATA_FAILED		0x80010004L		// Send data failed
#define		HI_ERR_NET_IP_INVALID			0x80010005L		// Invalid IP; Ex.¡°w.4¡±
#define		HI_ERR_NET_HOST_INVALID			0x80010006L		// Invalid host
#define		HI_ERR_NET_GETHOST_FAILED		0x80010007L		// Get host failed 
#define		HI_ERR_NET_READDATA_FAILED		0x80010008L   	// Read data failed 
#define		HI_ERR_NET_DEVICENOTONLINE		0x80010009L		// Device off-line
#define		HI_ERR_NET_DISCONNECTED			0x8001000AL		// Disconnected
#define		HI_ERR_NET_TIMEOUT_CONNECT		0x8001000BL		// Connect timeout
#define		HI_ERR_NET_INIT_FAILED			0x8001000CL		// Initialize failed 
#define		HI_ERR_NET_UNINIT_FAILED		0x8001000DL 	// Uninitialized failed 
#define		HI_ERR_NET_NOTALL_FAILED		0x8001000EL   	// Not all failed 
#define		HI_ERR_NET_LOGIN_FAILED			0x8001000FL 	// User name or password error
#define		HI_ERR_NET_BINDADDR_FAILED		0x80010010L 	// Bind memory address failed 
#define		HI_ERR_NET_BINDIP_FAILED		0x80010011L		// Bind local IP failed 
#define		HI_ERR_NET_GETACCEPT_FAILED		0x80010012L		// Get accept failed
#define		HI_ERR_NET_LISTEN_FAILED		0x80010013L		// Listen failed
#define		HI_ERR_NET_REGEVENT_ACCEPT		0x80010014L		// Register event failed
#define		HI_ERR_NET_BINDCPORT_FAILED		0x80010015L		// Bind port failed
#define		HI_ERR_NET_NODATA				0x80010016L		// No data in buffer 
#define		HI_ERR_NET_IOPENDING			0x80010017L		// IO pending 
#define		HI_ERR_NET_SETRECVSOCKET		0x80010018L    	// Set receive socket failed
#define		HI_ERR_NET_TASK_NOTSUPPORT		0x80010019L   	// Not support type




/************************************************************************
File error; begin with HI_ERR_IO_, 0x02
The control is all about IO include the control of preview etc.
************************************************************************/
#define		HI_ERR_IO_PLAYING					0x80020001L		// Playing
#define		HI_ERR_IO_NOTPLAYING				0x80020002L		// Not playing
#define		HI_ERR_IO_SAVING					0x80020003L		// Saving
#define		HI_ERR_IO_NOTSAVEING				0x80020004L		// Not saving
#define		HI_ERR_IO_OPENFILE_FAILED			0x80020005L		// Open file failed
#define		HI_ERR_IO_FILELEN_ERROR				0x80020006L		// File length incorrect 
#define		HI_ERR_IO_NOSPACE					0x80020007L		// HDD no free space
#define		HI_ERR_IO_ALARMEMPTY				0x80020008L		// Alarm list empty
#define		HI_ERR_IO_READ_FILE_FAILED			0x80020009L		// Read file failed
#define		HI_ERR_IO_TYPE_NOT_SUPPORT			0x8002000AL		// Not support
#define		HI_ERR_IO_OPENDECODER_FAILED		0x8002000BL		// Open decoder failed 
#define		HI_ERR_IO_FILEEXIST					0x8002000CL		// File already exist
#define		HI_ERR_IO_READHEADER_FAILED			0x8002000DL		// Read header failed 
#define		HI_ERR_IO_OFFSETTOOLONG				0x8002000EL		// Offset too long 
#define		HI_ERR_IO_OFFSETTOOLSHORT			0x8002000FL		// Offset too short 
#define		HI_ERR_IO_NOTCLIPALL				0x80020010L		// Not clip all
#define		HI_ERR_IO_TIMEFMTINCORRECT			0x80020011L		// Date format incorrect 
#define		HI_ERR_IO_FILEOPENED				0x80020012L		// File already opened
#define		HI_ERR_IO_FILENAMEINCORRECT			0x80020013L		// File name incorrect
#define		HI_ERR_IO_FILENOTOPENED				0x80020014L		// File not open 
#define		HI_ERR_IO_CREATETIMERFAILED			0x80020015L		// Create timer failed
#define		HI_ERR_IO_CLIPPING					0x80020016L		// Clipping 
#define		HI_ERR_IO_GETFULLPATH_FAILED		0x80020017L		// Get full path failed
#define		HI_ERR_IO_DIRTOODEEP				0x80020018L		// Directory too deep 
#define		HI_ERR_IO_SPEEDNOTSUPPORT			0x80020019L		// Speed not support 
#define		HI_ERR_IO_GETFILELIST_FAILED		0x8002001AL		// Get file list failed 
#define		HI_ERR_IO_NOFILEINLIST				0x8002001BL		// No file in list
#define		HI_ERR_IO_FILENOTMODIFY				0x8002001CL		// File not modify




/************************************************************************
Device error, begin with HI_ERR_REMOTE_, 0x03
REMOTE means which relative to this PC.
************************************************************************/
#define		HI_ERR_REMOTE_UNKNOWN				0x8003FFFFL		// Unknown error 
#define		HI_ERR_REMOTE_NOSIGNAL				0x80030001L		// No signal 
#define		HI_ERR_REMOTE_DOWNING				0x80030002L		// Downloading
#define		HI_ERR_REMOTE_UPDATING				0x80030004L		// Updating
#define		HI_ERR_REMOTE_VODING				0x80030006L		// Playing file 
#define		HI_ERR_REMOTE_ALMTRANING			0x80030008L		// Alarm transmitting on
#define		HI_ERR_REMOTE_FILERECORDING			0x8003000AL		// Recording file (Last file)
#define		HI_ERR_REMOTE_EXCUTE_FAILED			0x8003000BL		// Execute command failed
#define		HI_ERR_REMOTE_TRANSDATA				0x8003000CL		// Transmit data error 
#define		HI_ERR_REMOTE_CNNLIMITED			0x8003000DL		// Connect number limitation
#define		HI_ERR_REMOTE_CLIPPING				0x8003000EL		// Remote clipping
#define		HI_ERR_REMOTE_RPLAYING				0x8003000FL		// Remote playing 
#define		HI_ERR_REMOTE_PROTO_ANSFAILED		0x80030010L		// Parse protocol failed
#define     HI_ERR_REMOTE_CNNMEDIASVR_FAILED  	0x80030011L		// Connect media server failed
#define		HI_ERR_REMOTE_MEDIALINK_CFAILED		0x80030012L		// Check media link failed 
#define		HI_ERR_REMOTE_MEDIATHREAD_CFAILED	0x80030013L		// Create thread failed
#define		HI_ERR_REMOTE_NOFILE				0x80030014L		// No file 
#define		HI_ERR_REMOTE_PLAYBACK_FAILED		0x80030015L		// Playback failed
#define		HI_ERR_REMOTE_NOT_IMPLEMENT			0x80030016L		// Function not implement 
#define		HI_ERR_REMOTE_CNNBROKEN				0x80030017L		// Connect broken 
#define		HI_ERR_REMOTE_WAITACK_FAILED		0x80030018L		// Waiting ACK failed 
#define		HI_ERR_REMOTE_SENDDATA_FAILED		0x80030019L		// Send data failed 
#define		HI_ERR_REMOTE_RECVDATA_FAILED		0x8003001AL		// Receive data failed

/* Restricted Operation,when the operation conflict with others operation.
 For example, it is not be allowed when downloading file and other customer want to snapshot */
#define		HI_ERR_REMOTE_OPERATION_IMPACT		0x8003001BL		// Operate restricted 
#define		HI_ERR_REMOTE_GETUSERPW_FAILED		0x8003001CL		// Get password failed 
#define		HI_ERR_REMOTE_FILE_ERROR			0x8003001DL		// General file error 
#define		HI_ERR_REMOTE_PASSWORD_INVFMT		0x8003001EL		// Password format incorrect 
#define		HI_ERR_REMOTE_FILEEXIST				0x8003001FL		// File already existed 
#define		HI_ERR_REMOTE_UPGRADING				0x80030020L		// Upgrading 
#define		HI_ERR_REMOTE_PARAMETER_INVALID		0x80030021L		// Parameter incorrect 
#define		HI_ERR_REMOTE_MSGTYPE_INVALID		0x80030022L		// Message type incorrect




/************************************************************************
Stream error; begin with HI_ERR_AVDATA_, 0x04
************************************************************************/
#define		HI_ERR_AVDATA_NOTRIGHT				0x80040001L		// AV data incorrect 
#define		HI_ERR_AVDATA_NOFRAME				0x80040002L		// No frame in AV data 
#define		HI_ERR_AVDATA_NOIFRAME				0x80040003L		// No I frame in AV data




/************************************************************************
Memory error, begin with HI_ERR_MEM_, 0x05
************************************************************************/
#define		HI_ERR_MEM_OUT						0x80050001L		// Allocate memory failed 
#define		HI_ERR_MEM_OPENDECODER_FAILED		0x80050002L		// Open decoder failed 
#define		HI_ERR_MEM_OPERATION_FAILED			0x80050003L		// Operate memory failed 
#define		HI_ERR_MEM_CREATEEVENT_FAILED		0x80050004L		// Create event failed 




/************************************************************************
Parameter error, Begin with HI_ERR_PAR_, 0x06
This error number begins from 0 to 255, which means from 0x80060000 to 0x800600FF.
The last number(0x01~0xFF) which begins from 1 expresses the number of the error parameter. 
0x80060000 only expresses the general parameter error.
************************************************************************/
#define		HI_ERR_PAR_PARAMETER				0x80060000L		// Parameter error




/************************************************************************
Thread error; begin with HI_ERR_THREAD_, 0x07
************************************************************************/
#define		HI_ERR_THREAD_CREATE_FAILED			0x80070001L		// Create thread failed
#define		HI_ERR_THREAD_CTIMER_FAILED			0x80070002L		// Create timer failed




/************************************************************************
Other error, begin with HI_ERR_OTHER_, 0xF0
************************************************************************/
#define		HI_ERR_OTHER_NORIGHT				0x80F00001L		// No right
#define		HI_ERR_OTHER_NOTSUPPORT				0x80F00002L		// Not support
#define		HI_ERR_OTHER_TASKGOING				0x80F00003L		// Task running
#define		HI_ERR_OTHER_TASKNOTGO				0x80F00004L		// Task not run
#define		HI_ERR_OTHER_BEGDECODE_FAILED		0x80F00005L		// Start decode failed
#define		HI_ERR_OTHER_PROT_NOTSUPPORTED		0x80F00006L		// Protocol not support 
#define		HI_ERR_OTHER_NOTINIT				0x80F00007L		// Uninitialized 
#define		HI_ERR_OTHER_UNKNOWN_DEVICE			0x80F00008L		// Unknown device type 
#define		HI_ERR_OTHER_NOSUBCLASS_FUNCTION	0x80F00009L		// No sub class function 
#define		HI_ERR_OTHER_NOTFIND				0x80F0000AL		// Not found 
#define		HI_ERR_OTHER_ENDALREADY				0x80F0000BL		// Task end already 
#define		HI_ERR_OTHER_NONEED					0x80F0000CL		// No need 
#define		HI_ERR_OTHER_INITFAILED				0x80F0000DL		// Initialize failed 
#define		HI_ERR_OTHER_NOT_IMPLEMENT			0x80F0000EL		// Not implement 
#define		HI_ERR_OTHER_NOT_EXIST				0x80F0000FL		// Not exist


#pragma pack()

#ifdef __cplusplus
}
#endif


#endif