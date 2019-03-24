#ifndef __LVR_PLAY_H__
#define __LVR_PLAY_H__

#ifdef __LVR_PLAY_EXPORT__
#define LVR_PLAY_API  extern "C" __declspec(dllexport)
#else
#define LVR_PLAY_API  extern "C" __declspec(dllimport)
#endif

#define LVR_PLAY_OUTOF_MEMORY						0x00000001L // 分配内存失败
#define LVR_PLAY_INVALID_PARAMETER					0x00000002L // 非法参数

typedef void (CALLBACK *pCompletePlay)(LONG lvrPlayHandle, LONG lUserData);
typedef void (CALLBACK *pPlaybackDraw)(LONG lvrPlayHandle, HDC hDC, DWORD dwUser);

LVR_PLAY_API void __stdcall LvrPlayStartup();
LVR_PLAY_API void __stdcall LvrPlayCleanup();

LVR_PLAY_API LONG __stdcall LvrPlayConvertToAviFile(CHAR *pLvfFile, CHAR *pAviFile);
LVR_PLAY_API LONG __stdcall LvrPlayGetConvertAviFilePos(LONG lvrFileHandle);
LVR_PLAY_API BOOL __stdcall LvrPlayConvertAviFileClose(LONG lvrFileHandle);

LVR_PLAY_API LONG __stdcall LvrPlayOpenFile(CHAR *pPlayFile, HWND hWnd);
LVR_PLAY_API BOOL __stdcall LvrPlayCloseFile(LONG lvrPlayHandle);

LVR_PLAY_API BOOL __stdcall LvrPlayGetFileTime(LONG lvrPlayHandle, LONG *pFileTime);
LVR_PLAY_API BOOL __stdcall LvrPlayGetFileFrames(LONG lvrPlayHandle, LONG *pFileFrames);
LVR_PLAY_API BOOL __stdcall LvrPlayGetFrameRate(LONG lvrPlayHandle, FLOAT *pFrameRate);
LVR_PLAY_API BOOL __stdcall LvrPlayGetPlayedFrames(LONG lvrPlayHandle, LONG *pPlayFrames);
LVR_PLAY_API BOOL __stdcall LvrPlayGetPictureSize(LONG lvrPlayHandle, LONG *pWidth, LONG *pHeight);

LVR_PLAY_API BOOL __stdcall LvrPlayPalybackDraw(LONG lvrPlayHandle, pPlaybackDraw playbackDraw, COLORREF crMask, DWORD dwUser);
LVR_PLAY_API BOOL __stdcall LvrPlayFuncCallback(LONG lvrPlayHandle, pCompletePlay completePlay, LONG lUserData);
LVR_PLAY_API BOOL __stdcall LvrPlayCompleteNotify(LONG lvrPlayHandle, HWND hWnd, UINT uMsg, LONG lUserData);

LVR_PLAY_API BOOL __stdcall LvrPlayPlay(LONG lvrPlayHandle);
LVR_PLAY_API BOOL __stdcall LvrPlayPause(LONG lvrPlayHandle);
LVR_PLAY_API BOOL __stdcall LvrPlayStop(LONG lvrPlayHandle);

LVR_PLAY_API BOOL __stdcall LvrPlaySetPlayedTime(LONG lvrPlayHandle, LONG lPlayTime);
LVR_PLAY_API BOOL __stdcall LvrPlayGetPlayedTime(LONG lvrPlayHandle, LONG *pPlayTime);

LVR_PLAY_API BOOL __stdcall LvrPlaySetPosition(LONG lvrPlayHandle, FLOAT fSeekPos);
LVR_PLAY_API FLOAT __stdcall LvrPlayGetPosition(LONG lvrPlayHandle);

LVR_PLAY_API BOOL __stdcall LvrPlaySetRate(LONG lvrPlayHandle, DOUBLE dRate);
LVR_PLAY_API BOOL __stdcall LvrPlayGetRate(LONG lvrPlayHandle, DOUBLE *pRate);

LVR_PLAY_API BOOL __stdcall LvrPlayStepPlay(LONG lvrPlayHandle, DWORD dwStep);
LVR_PLAY_API BOOL __stdcall LvrPlayCaptureImage(LONG lvrPlayHandle, CHAR *pFileName);

LVR_PLAY_API BOOL __stdcall LvrPlaySetVoice(LONG lvrPlayHandle, LONG lBalance, LONG lVolume);
LVR_PLAY_API BOOL __stdcall LvrPlayGetVoice(LONG lvrPlayHandle, LONG *pBalance, LONG *pVolume);

LVR_PLAY_API BOOL __stdcall LvrPlaySetRect(LONG lvrPlayHandle, LPRECT pSrcRect);

LVR_PLAY_API DWORD __stdcall LvrPlayGetSdkVersion();

#endif