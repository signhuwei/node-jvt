
#ifndef __STREAM_READER_H__
#define __STREAM_READER_H__

#ifdef WIN32
#	include <WTypes.h>
#	define VIDEO_ANALYSIS_API extern "C"
#	define CALL_METHOD		__stdcall
#else
#	define VIDEO_ANALYSIS_API extern "C"
#	define CALL_METHOD
#	define HANDLE void* 
#endif


//最大图像分辨率
#define MAX_FRAME_WIDTH		4000 //by zjh modify 20170829
#define MAX_FRAME_HEIGTH	3000 //by zjh modify 20170829

typedef struct 
{
	unsigned char *pHeader;				///< 帧数据缓冲起始地址,包含我们私有的码流头
	unsigned char *pContent;			///< H264帧起始缓冲地址，标准的H264码流
	unsigned long nLength;				///< 缓冲长度(起始位pHeader)
	unsigned long nFrameLength;			///< H264帧长度(起始为pContent)
	
	unsigned int nType;
	unsigned int nSubType;
	
	unsigned int nEncodeType;
	
	unsigned long nYear;				///< 帧时间戳
	unsigned long nMonth;
	unsigned long nDay;
	unsigned long nHour;
	unsigned long nMinute;
	unsigned long nSecond;
	unsigned long nTimeStamp;	
	
	unsigned int  nFrameRate;			///< 视频图像帧率
	int nWidth;							///< 视频图像大小，宽度和高度
	int nHeight;
	unsigned long nRequence;

	unsigned int nChannels;
	unsigned int nBitsPerSample;		///< 音频采样位深
	unsigned int nSamplesPerSecond;		///< 音频采样率
	
	unsigned long nParam1;		// 播放器参数
	unsigned long nParam2;
	unsigned long version;			// 版本号
	unsigned long reserved[10];	// 扩展用
} H264_FRAME_INFO;

/// 码流类型StreamType
#define streamTypeEmpty	0
#define streamTypeH264	2
#define streamTypeJpeg	3
#define streamTypeGeneral 4
#define streamTypeH265	6
#define streamTypePCM8	7
#define streamTypeStd	8

/// 码流分析复位类型ResetType
#define resetRefind		0
#define resetContinue	1


/// 图像帧类型FrameType
#define frameTypeUnknown	0
#define frameTypeVideo		1
#define frameTypeAudio		2
#define frameTypeData		3


/// 图像帧子类型FrameSubType
#define frameSubTypeIFrame 0
#define frameSubTypePFrame 1
#define frameSubTypeBFrame 2
#define frameSubTypeSFrame 3
#define frameSubTypeDataText 5
#define frameSubTypeDataIntl 6

///版本号定义
#define H264_ANALYSIS_V1 		0
#define H264_ANALYSIS_V2 		1

/// 创建码流分析器
/// \param [in] iStreamType 码流分析器类型,见StreamType
/// \return 0 创建成功
/// \return < 0 创建失败
VIDEO_ANALYSIS_API HANDLE CALL_METHOD VideoAnalysis_Create(int iStreamType);


/// 销毁码流分析器
/// \param [in] lHandle 要销毁码流分析器的句柄
/// \return 0 销毁成功
/// \return < 0 销毁失败
VIDEO_ANALYSIS_API int CALL_METHOD VideoAnalysis_Destroy(HANDLE lHandle);


/// 输入码流分析数据
/// \param [in] lHandle 要操作的码流分析器的句柄
/// \param [in] pData 输入数据buf地址
/// \param [in] nDataLen 数据长度
/// \return 0 输入成功
/// \return < 0 输入失败
VIDEO_ANALYSIS_API int CALL_METHOD VideoAnalysis_InputData(HANDLE lHandle, unsigned char *pData, int nDataLen);


/// 复位码流分析器
/// \param [in] lHandle 要操作的码流分析器的句柄
/// \param [in] resetFlag 要操作的码流分析器的句柄，ResetFlag
/// \param [in] streamtype 复位后初始化的码流类型
/// \return 0 复位成功
/// \return < 0 复位失败
VIDEO_ANALYSIS_API int CALL_METHOD VideoAnalysis_Reset(HANDLE lHandle, int resetFlag, int streamtype);	


/// 得到下一个有效的帧数据
/// \param [in] lHandle 要操作的码流分析器的句柄
/// \return H264帧数据信息
VIDEO_ANALYSIS_API H264_FRAME_INFO * CALL_METHOD VideoAnalysis_GetNextFrame(HANDLE lHandle);


/// 得到下一个有效的关键帧数据
/// \param [in] lHandle 要操作的码流分析器的句柄
/// \return H264帧数据信息
VIDEO_ANALYSIS_API H264_FRAME_INFO * CALL_METHOD VideoAnalysis_GetNextKeyFrame(HANDLE lHandle);


/// 得到当前的码流类型，StreamType
/// \param [in] lHandle 要操作的码流分析器的句柄
/// \return 当前的码流类型
VIDEO_ANALYSIS_API int CALL_METHOD VideoAnalysis_GetStreamType(HANDLE lHandle);

#endif
