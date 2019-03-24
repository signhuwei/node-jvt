
#ifndef	_HI_MEDIA_PLAYER_TYPES_H_
#define	_HI_MEDIA_PLAYER_TYPES_H_

#pragma pack(4)


// frame type
#define	FRAMETYPE_NONE			0L
#define	FRAMETYPE_I				0x00000001L	// I frame
#define	FRAMETYPE_P				0x00000002L	// p frame
#define	FRAMETYPE_VIDEO			0x00000003L	// Video	
#define	FRAMETYPE_A				0x00000004L	// audio frame
#define FRAMETYPE_HEADER		0x00000005L	// file header: 512 butes
#define	FRAMETYPE_JPEG			0x00000008L	// JPEG capture
#define	FRAMETYPE_UPGRADE		0x00000009L	// Network upgrade file transmit finish
#define	FRAMETYPE_COVER			0x0000000AL	// cover frame
#define	FRAMETYPE_END			0x000000FFL	// the end of remote playback


// image format
#define	HIIF_BMP				1L
#define	HIIF_JPG				2L
#define	HIIF_GIF				3L

// Hide and Show 
#define	HI_HIDE			0L
#define	HI_SHOW			1L

// start and end task
#define	HITASK_START	0L
#define	HITASK_END		1L

// play control
#define	HI_PCPLAY		0L
#define	HI_PCPAUSE		1L
#define	HI_PCNORMAL		2L
#define	HI_PCBACK		3L

// offset type
#define	HI_POOFFSET		0L			// By file's length
#define	HI_POFRAME		1L			// By frame count	
#define	HI_POTIME		2L			// By time

// file position
#define	HI_FPSTART		0L			// the start of file 
#define	HI_FPCURRENT	1L			// the current position
#define	HI_FPEND		2L			// the end of file



// OSD show the position
typedef enum E_OSDShowPos
{
	OSD_LEFT_TOP = 0,				// top left
		OSD_RIGHT_TOP ,					// top right
		OSD_LEFT_BOTTOM ,				// bottom left
		OSD_RIGHT_BOTTOM 				// bottom right
}E_OSDShowPos;

/*****************************
Decoder type
This type is a part of all decoder types. Some specific decode will use specific API to create the decoder.
*****************************/
enum HI_STREAM_TYPE_E
{
	HI_STREAM_STREAMING	= 1L,
	HI_STREAM_DECODPICT	= 2L,
	HI_STREAM_AVI		= 3L
};

/* Definition of audio format: The initial purpose is only used in the streams which have the standard audio frame header structure. */
enum HI_AUDIO_ENC_TYPE
{
	HI_AUDIO_FORMAT_AMR   = 1,   // AMR, encode type: MIME, bit rate: 4.75kbit/s
	HI_AUDIO_FORMAT_G726  = 2,   // G726
	HI_AUDIO_FORMAT_ADPCM = 3,   // ADPCM
	HI_AUDIO_FORMAT_G711A = 4,   // G711A
	HI_AUDIO_FORMAT_G711U = 5,   // G711U
	HI_AUDIO_FORMAT_PCM   = 6	 // PCM
};


/**************************************************************************************
The following parts are used for the message transmission between remote player (V2 or V3) and OCX.
 The message is defined by users and the defined value are all for the wParam value. The highest 4 digit are 2
***************************************************************************************/
#define RPUM_WSTARTDECODER			0x20000001			// start decode
#define	RPUM_WPLAYPOS				0x20000002			// play position, unit: byte
#define	RPUM_WPLAYFINISH			0x20000003			// play finish
#define	RPUM_WDOWNING				0x20000004			// Downloading to buffer
#define	RPUM_TIMECURRENT			0x20000005			/* Current playing time which obtained from the frame header. The lParam is the pointer which points to TimeInfo.*/
#define RPUM_TLCURRENT				0x20000006			/* The time length (Second) between the current play position and the start position. TL = Time Length*/
#define	RPUM_WCLIPFAILED			0x20000010			// clip failed
#define	RPUM_WDFILELENGTH			0x20000011			// get file length
#define	RPUM_WDFTIMESTART			0x20000012			// Start time of file
#define	RPUM_WDFTIMEEND				0x20000013			// End time of file
#define	RPUM_WDWNDCOUNT				0x20000014			// Get the number of used windows, including the video channel count
#define	RPUM_WDOPENFILEFAILED		0x20000015			// open file Failed 
#define	RPUM_HAVENOVEDIOFRAME		0x20000016			// File does not have video frame, so can¡¯t decode
#define	RPUM_NEXTRP3FILENAME		0x20000017			// Transmit the next file name during playing
#define	RPUM_RPCUSHIONING			0x20000018			// To display the message of PC buffer during remote playback
#define RPUM_RPFIRSTIFRAMEPOS		0x20000019			// The first I frame position corresponded to the start position of file during remote playback
//#define	RPUM_WFRAMEINDEX			0x20000016
#define RPUM_FRAMEINFO				0x20000101			// frame information, lParam is a pointer which point to the structure, Mdvr_FrameInfoEx



/*****************************
 usMilliSecond£ºBecause this member might not be always valid, so use the highest bit to shows whether this member is valid or not.
*****************************/
typedef struct
{
	unsigned char	cYear;
	unsigned char	cMonth;
	unsigned char	cDay;
	unsigned char	cHour;
	unsigned char	cMinute;
	unsigned char	cSecond;
	unsigned short	usMilliSecond:10;
	unsigned short	usWeek:3;
	unsigned short	usReserved:2;
	unsigned short	usMilliValidate:1;
}  HI_MEDIA_DATETIME;

#define T_AUDIO16		0x01
#define T_RGB32     0x02
#define T_YUV				0x03

typedef struct 
{ 
	long nWidth; 
	long nHeight; 
	long nStamp; 
	long nType;			// T_AUDIO16, T_RGB32, T_YUV
}KW_FRAME_INFO;
typedef void (CALLBACK* pfnDecCBFun)(HANDLE hDecoder, int iChn, char *pBuf, long nSize, FRAME_INFO *pFrameInfo, long nReserved, DWORD dwUserData); 



#pragma pack()


#endif // _HI_MEDIA_PLAYER_TYPES_H_