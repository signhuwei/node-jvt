
/******************************************************************************
 *	File Name		: HiDvrMedia.h
 *	Description		: Media API Header file
 *	Version			: Initial Draft
 *	Author			: LAN CASTLE Technologies Co., LTD
 *	Created			: 	
 *	History			:
 *	  1.Date			: 2010/09/15
 *		Author			: 
 *		Modification	: Created file
 ******************************************************************************/


#ifndef DECODERAPI_H
#define DECODERAPI_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "hi_media_type.h"
#include "hi_commom_errcode.h"
#include "hi_common_structs.h"
#include "VMS_pubDefine.h"


// Define the version of the media library
#define	HI_DVR_MEDIA_SDK_VERSION	"1.1.0.3"
#define	HI_DVR_MEDIA_SDK_COMPILED	"2010.10.27"

#ifdef	DECODERAPI_SDK
#else
#define DECODERAPI_SDK extern "C" __declspec(dllimport)
#endif

#define WINAPI __stdcall



// Get the version of the media library
DECODERAPI_SDK	char *WINAPI HI_DVR_MEDIA_GetDecoderSDKVersion();



/******************************** 1. Open Decoder *******************************/

// Open the decoder to play the video or decode the picture
DECODERAPI_SDK HANDLE  WINAPI HI_DVR_MEDIA_OpenDecoder( HI_DVR_TYPE enuDeviceType, 
														HI_DVR_SUBTYPE enuDeviceSubType,
														HI_STREAM_TYPE_E enuDecoderType = HI_STREAM_STREAMING, 
														long lDecoderNetType = 0);

// Open the decoder to playback file, third version
DECODERAPI_SDK HANDLE	WINAPI	HI_DVR_MEDIA_OpenFileDecoderRP3(LPCTSTR pszFileName,
																LPCTSTR pszFileNameDev = NULL );



/********************************* 2. Start Decode ********************************/
  
// Start play
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_StartPlay( HANDLE hDecoder,
															HWND *phWindow,
															unsigned long lHwndCount,
															unsigned long *plChannelPlay,
															unsigned long lChannelCount,
															long lOffset );



/********************************** 3. Stop Play *******************************/

// Stop play
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_StopPlay(	HANDLE hDecoder, 
															long lChannel );


// Set decode callback
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_SetDecCallBack( 
																							HANDLE hDecoder, 
																							int iChn,
																							pfnDecCBFun fnDecCBFun, 
																							DWORD dwUserData);	
/********************************* 4. Close Decoder ******************************/

// Close decoder
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_CloseDecoder( HANDLE hDecoder );



/********************************** 5. Audio Operation ***************************
 * Operate audio, include open decoder, close decoder, set volume and set mute.
 * Before the audio was operated, you need to request AV stream first with the function HI_DVR_NET_OpenStreamSound 
 * or HI_DVR_NET_CloseStreamSound in ¡§HiDvrNet.h¡¨ file.
 *********************************************************************************/

// Open sound
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_OpenSound( HANDLE hDecoder, 
															long lChannel );

// Close sound
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_CloseSound(HANDLE hDecoder, 
															long lChannel );

// Set volume in preview or playback mode
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_SetVolume( HANDLE hDecoder, 
															long lChannel,  
															long lValue );

// Set mute
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_SetMute(	HANDLE hDecoder, 
															long lChannel, 
															BOOL bMute );

// Open the encoder for the intercom
DECODERAPI_SDK HANDLE WINAPI	HI_DVR_MEDIA_OpenTalk(	VMS_Talk_S *pTalkCmd,
														AudioEncodeCallBack AudioEncData,
														long lNetType,
														void *pUserData);

// Close encoder
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_CloseTalk( HANDLE hDecoder);

DECODERAPI_SDK void	WINAPI  HI_DVR_MEDIA_TalkPlay(HANDLE Talkhd ); // add by dee,2010.11.10

// Throw the intercom data to the decoder
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_InputTalkData( HANDLE hTalkHandle, 
																unsigned char *pDataBuffer, 
																long lDataLength, 
																unsigned __int64 Pts );



/********************************* 6. Decode stream data ******************************/

// Throw the stream data to the decoder,in preview mode
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_InputDataToDecoder(HANDLE hDecoder,
																	unsigned long lFrameType,
																	unsigned char* pszData,
																	unsigned long lDataLength );
// Get the frame count in the video buffer
//DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_GetBufferFrameCount( HANDLE hDecoder );

// Clear decoder buffer
//DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_ClearDecoderBuffer( HANDLE hDecoder );




/********************************** 7. Playback Control *******************************/

// Set play direction
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_PCSetDirection(	HANDLE hDecoder, 
																	unsigned long lDirection );

// Play or pause
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_PCPause(	HANDLE hDecoder, 
															unsigned long lPause );

// Set playback speed; 0:normal speed, -1:1/2 speed, -2:1/4 speed, -3:1/8 speed, -4:1/16 speed, 
// 1:2 speed, 2:4 speed, 3:8 speed, 4:16 speed
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_PCSetRate( HANDLE hDecoder, 
															long lPlayRate );

// Set frame interval time
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_PCSetFrameInterval(HANDLE hDecoder,
																	long lInterval );

// Set position
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_PCSetPos(	HANDLE hDecoder,
															long lOffset = 0,
															HI_MEDIA_DATETIME *pstuPosTime = NULL,
															unsigned long lPosType = HI_POOFFSET,
															unsigned long lSearchStart = HI_FPCURRENT );

// Play next frame
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_PCNextFrame( HANDLE hDecoder );

// Play previous frame
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_PCPrevFrame( HANDLE hDecoder );



/******************************* 8. Image Property Setting ******************************/

// Set OSD display
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_SetOsd(HANDLE hDecoder, 
														long lChannel, 
														unsigned long lShow = HI_HIDE,
														LPCTSTR pszOsd = NULL,
														E_OSDShowPos enuShowPos = OSD_LEFT_TOP,
														unsigned long lBrightness = 0 );

// Display info on the image, which includes longitude,latitude,speed,direction,temperature...
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_SetShowInfo(	HANDLE hDecoder, 
																unsigned long lShow);

// Set brightness
DECODERAPI_SDK  unsigned long WINAPI HI_DVR_MEDIA_SetChBrightness(	HANDLE hDecoder,
																	long lChannel,
																	unsigned long lBrightness );

/*
// Adjust brightness,for direct3d
DECODERAPI_SDK  unsigned long WINAPI HI_DVR_MEDIA_SetBrightness(HANDLE hDecoder, 
																long lChannel,
																long lRed = 50, 
																long lGreen = 50, 
																long lBlue = 50 );
*/



/****************************** 9. CALLBACK Function Registry *****************************/

// Set CALLBACK	function in playback mode
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_RegistFilePlayInfoCallBack( HANDLE hDecoder,
														unsigned long lUserData, 
														HI_CB_INTCALLBACK pfnCallBack );



/************************************* 10. Other Function *******************************/

/*
// Get the video size
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_GetVideoSize(	HANDLE hDecoder,
																unsigned long *plWidth,
																unsigned long *plHeight,
																long lChannel = 1);

// Save the frame data to the image file
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_SaveFrameToImage(	HANDLE hDecoder,
																	LPCTSTR pszDirectory,
																	unsigned long lStart = HITASK_START,
																	unsigned long lCount = 1,
																	unsigned long lFormat = HIIF_BMP );
*/

// Playback for the third version
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_SetFileLengthRP3(	HANDLE hDecoder,
																	unsigned long ulFileLength,
																	LPCTSTR pszDeviceFileName );

// Capture image when preview, playback or vod play
DECODERAPI_SDK unsigned long WINAPI HI_DVR_MEDIA_CaptureVideoImage(	HANDLE hDecoder,
																	long lChannel,
																	unsigned char *pszRGB24Data,
																	unsigned long *plWidth,
																	unsigned long *plHeight,
																	unsigned long lFlipVert );

// Save the RGB data to the BMP file
DECODERAPI_SDK unsigned long WINAPI	HI_DVR_MEDIA_Save2BMPFile(	LPCTSTR pszFileName,
																unsigned char *pszRGBData,
																long lWidth, 
																long lHeight );


#ifdef __cplusplus
}
#endif

#endif