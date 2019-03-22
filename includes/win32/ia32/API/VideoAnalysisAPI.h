
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


//���ͼ��ֱ���
#define MAX_FRAME_WIDTH		4000 //by zjh modify 20170829
#define MAX_FRAME_HEIGTH	3000 //by zjh modify 20170829

typedef struct 
{
	unsigned char *pHeader;				///< ֡���ݻ�����ʼ��ַ,��������˽�е�����ͷ
	unsigned char *pContent;			///< H264֡��ʼ�����ַ����׼��H264����
	unsigned long nLength;				///< ���峤��(��ʼλpHeader)
	unsigned long nFrameLength;			///< H264֡����(��ʼΪpContent)
	
	unsigned int nType;
	unsigned int nSubType;
	
	unsigned int nEncodeType;
	
	unsigned long nYear;				///< ֡ʱ���
	unsigned long nMonth;
	unsigned long nDay;
	unsigned long nHour;
	unsigned long nMinute;
	unsigned long nSecond;
	unsigned long nTimeStamp;	
	
	unsigned int  nFrameRate;			///< ��Ƶͼ��֡��
	int nWidth;							///< ��Ƶͼ���С����Ⱥ͸߶�
	int nHeight;
	unsigned long nRequence;

	unsigned int nChannels;
	unsigned int nBitsPerSample;		///< ��Ƶ����λ��
	unsigned int nSamplesPerSecond;		///< ��Ƶ������
	
	unsigned long nParam1;		// ����������
	unsigned long nParam2;
	unsigned long version;			// �汾��
	unsigned long reserved[10];	// ��չ��
} H264_FRAME_INFO;

/// ��������StreamType
#define streamTypeEmpty	0
#define streamTypeH264	2
#define streamTypeJpeg	3
#define streamTypeGeneral 4
#define streamTypeH265	6
#define streamTypePCM8	7
#define streamTypeStd	8

/// ����������λ����ResetType
#define resetRefind		0
#define resetContinue	1


/// ͼ��֡����FrameType
#define frameTypeUnknown	0
#define frameTypeVideo		1
#define frameTypeAudio		2
#define frameTypeData		3


/// ͼ��֡������FrameSubType
#define frameSubTypeIFrame 0
#define frameSubTypePFrame 1
#define frameSubTypeBFrame 2
#define frameSubTypeSFrame 3
#define frameSubTypeDataText 5
#define frameSubTypeDataIntl 6

///�汾�Ŷ���
#define H264_ANALYSIS_V1 		0
#define H264_ANALYSIS_V2 		1

/// ��������������
/// \param [in] iStreamType ��������������,��StreamType
/// \return 0 �����ɹ�
/// \return < 0 ����ʧ��
VIDEO_ANALYSIS_API HANDLE CALL_METHOD VideoAnalysis_Create(int iStreamType);


/// ��������������
/// \param [in] lHandle Ҫ���������������ľ��
/// \return 0 ���ٳɹ�
/// \return < 0 ����ʧ��
VIDEO_ANALYSIS_API int CALL_METHOD VideoAnalysis_Destroy(HANDLE lHandle);


/// ����������������
/// \param [in] lHandle Ҫ�����������������ľ��
/// \param [in] pData ��������buf��ַ
/// \param [in] nDataLen ���ݳ���
/// \return 0 ����ɹ�
/// \return < 0 ����ʧ��
VIDEO_ANALYSIS_API int CALL_METHOD VideoAnalysis_InputData(HANDLE lHandle, unsigned char *pData, int nDataLen);


/// ��λ����������
/// \param [in] lHandle Ҫ�����������������ľ��
/// \param [in] resetFlag Ҫ�����������������ľ����ResetFlag
/// \param [in] streamtype ��λ���ʼ������������
/// \return 0 ��λ�ɹ�
/// \return < 0 ��λʧ��
VIDEO_ANALYSIS_API int CALL_METHOD VideoAnalysis_Reset(HANDLE lHandle, int resetFlag, int streamtype);	


/// �õ���һ����Ч��֡����
/// \param [in] lHandle Ҫ�����������������ľ��
/// \return H264֡������Ϣ
VIDEO_ANALYSIS_API H264_FRAME_INFO * CALL_METHOD VideoAnalysis_GetNextFrame(HANDLE lHandle);


/// �õ���һ����Ч�Ĺؼ�֡����
/// \param [in] lHandle Ҫ�����������������ľ��
/// \return H264֡������Ϣ
VIDEO_ANALYSIS_API H264_FRAME_INFO * CALL_METHOD VideoAnalysis_GetNextKeyFrame(HANDLE lHandle);


/// �õ���ǰ���������ͣ�StreamType
/// \param [in] lHandle Ҫ�����������������ľ��
/// \return ��ǰ����������
VIDEO_ANALYSIS_API int CALL_METHOD VideoAnalysis_GetStreamType(HANDLE lHandle);

#endif
