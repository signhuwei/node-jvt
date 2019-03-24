//
//  "$Id: Play.h 2296 2011-12-02 11:28:03Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_VIDEODEC_H__
#define __PAL_VIDEODEC_H__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup PlayAPI API Play
/// ��·����Ƶ�طŽ���ӿڡ�
///	\n ��������ͼ:
/// \code
///    =======================================================
///                   |                            
///	         *PlayGetChannels       
///             PlayGetCaps            
///                   |                            
///              PlayCreate                      
///       +-----------|      
///       |      PlaySetVstd                 	
///       |           |           	 
///       |       PlayStart       
///       | +---------|-------------+--------------+     
///       | |         |(Data)       |(Ctrl)        |(Ctrl)
///       | |   PlayGetBuffer   PlayPause     PlaySetRect          
///       | |         |             |        PlaySetVolume
///       | |    PlayPutBuffer  PlayStep      PlayGetTime
///       | |         |             |       PlaySetDirection
///       | |    PlaySetEof     PlayResume   PlaySetSpeed
///       | |     PlayFlush         |              |
///       | +---------|-------------+--------------+          
///       |        PlayStop   
///       +-----------|      
///              PlayDestory                       
///                   |                            
///    =======================================================
/// \endcode
/// @{

enum search_type
{
	BY_TIME = 0,
	BY_CARD,
	BY_MAX,
};

/// �ط����ݰ��ṹ
#ifndef  FUNC_NEW_PLAY
typedef struct PLAY_BLOCK
{
	/// ��Ҫ�����ݿ��ֽ�����
	unsigned int		length;

	/// ��Ҫƫ�Ƶ��ֽ���������ط�ʱ�����ֵһֱ��0���ɣ�����ط�ʱ��
	/// ��Ҫ����ǰƫ�Ƶĳ��ȣ�Ϊһ��������
	int			offset;		
}PLAY_BLOCK;
#else
typedef struct PLAY_BLOCK
{
	/// ��Ҫ�����ݿ��ֽ�����
	unsigned int		length;

	/// ��Ҫƫ�Ƶ��ֽ���������ط�ʱ�����ֵһֱ��0���ɣ�����ط�ʱ��
	/// ��Ҫ����ǰƫ�Ƶĳ��ȣ�Ϊһ��������
	int			offset;	

	///������ݵ�ָ�룬����Ҫ���ڻ��ߵ���length
	unsigned char* buffer;	
	
	/// �����ֽ�
	int reserved[32];	
}PLAY_BLOCK;
#endif


/// �ط����Խṹ
typedef struct PLAY_CAPS
{
	/// ֧�ֵ����򲥷��ٶȵ����룬λ��Ŷ�Ӧö������play_speed_t��ÿһ��ֵ��
	/// ��1��ʾ֧�ָ�ö��ֵ��Ӧ�����ԣ���0��ʾ��֧�֡�
	unsigned int ForwardSpeed;

	/// ֧�ֵĵ��򲥷��ٶȵ����룬λ��Ŷ�Ӧö������play_speed_t��ÿһ��ֵ��
	/// ��1��ʾ֧�ָ�ö��ֵ��Ӧ�����ԣ���0��ʾ��֧�֡�
	unsigned int BackwardSpeed;

	/// ֧�ֵĵ������ŷ�������룬λ��Ŷ�Ӧö������play_direction_t��ÿһ��ֵ��
	/// ��1��ʾ֧�ָ�ö��ֵ��Ӧ�����ԣ���0��ʾ��֧�֡�
	unsigned int StepDirection;

	/// �Ƿ�֧���������ƣ�0-��֧�֣�1-֧�֡�
	unsigned char  VolumeControl;

	/// ����
	unsigned char  Reserved[3];		
}PLAY_CAPS;

/// �طŽ��������ṹ,�ܹ�512�ֽ�.
typedef struct PLAY_INFO 
{
	unsigned int	nMaxDecodePower;	///< ֧�ֵ���߽���������
	unsigned int	nMaxSupportChannel;	///< ֧�����������Ƶͨ������
	unsigned int	nCompression;		///< ��������,�����ʾ
	unsigned int	nImageSize[32];		///< ����ͨ����ͼ���С
	unsigned int	nDecodePower[32];	///< ����ͨ���Ľ�������
	unsigned int	reserved[61];
} PLAY_INFO, *PPLAY_INFO;

/// �ط��ٶ�ö��ֵ
enum play_speed_t {
	PLAY_SPEED_SLOW4,		///< ����4
	PLAY_SPEED_SLOW3,		///< ����3
	PLAY_SPEED_SLOW2,		///< ����2
	PLAY_SPEED_SLOW1,		///< ����1
	PLAY_SPEED_NORMAL,		///< �����ٶ�
	PLAY_SPEED_FAST1,		///< ����1
	PLAY_SPEED_FAST2,		///< ����2
	PLAY_SPEED_FAST3,		///< ����3
	PLAY_SPEED_FAST4		///< ����4
};

/// �طŷ���ö��ֵ
enum play_direction_t {	
	PLAY_DIRECTION_FORWARD,	///< ���򲥷š�
	PLAY_DIRECTION_BACKWARD	///< ���򲥷š�
};

/// �طŽ���������Ϣ�ṹ,�ܹ�128�ֽ�.
typedef struct PLAY_STREAM_INFO 
{
	unsigned int	nImageWidth;	///< ����ͼ��Ŀ��
	unsigned int	nImageHeiht;	///< ����ͼ��ĸ߶�
	unsigned int	nCompression;	///< ��������,�����ʾ��H264��
	unsigned int	nFrameRate;		///< ����������֡��
	unsigned int	reserved[28];
} PLAY_STREAM_INFO, *PPLAY_STREAM_INFO;


typedef struct PLAY_STREAM_INFO2
{
	unsigned int nDecodeWidth; ///< ����ͨ���Ŀ��
	unsigned int nDecodeHeiht;
	unsigned int nStreamWidth; ///<��ǰ�����Ŀ��
	unsigned int nStreamHeiht;
} PLAY_STREAM_INFO2, *PPLAY_STREAM_INFO2;

int PlayGetStreamInfo2(int channel, PLAY_STREAM_INFO2 *pStreamInfo);

/// ��ûطŵĽ�������
///
int PlayGetDecInfo(PLAY_INFO *pDspInfo);


/// �õ��طŵ�ͨ����Ŀ�������������طŵ�ͨ���������ط�ͨ�������ط�ͨ���ż�1��
/// ���������ÿ����Ƶ������ϵĻط�ͨ����һ�£���PlayGetChannels����2��������
/// ��Ƶ����ˣ��������0�ϵĻط�ͨ�����Ϊ0��1�������1�ϵĻط�ͨ�����Ϊ2��3��
/// ����ϵͳ�������������ƣ����ֻ���������ط�ͨ����������ͬһ������˿ڣ�Ҳ
/// �����ڲ�ͬ�Ķ˿ڡ�
/// 
/// \param ��
/// \returnӳ�䵽��һ��Ƶ����˿��ϵ����طŵ�ͨ����Ŀ��
int PlayGetChannels(void);


/// �õ�HVR֧�ֵ�������ͨ����Ŀ��
/// \param ��
/// \returnӳ�䵽��һ��Ƶ����˿��ϵ��������ͨ����Ŀ��
int PlayGetDecoderChannels(void);

/// �����ط��豸
/// 
/// \param [in] channel ͨ���š�
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int PlayCreate(int channel);


/// ���ٻط��豸
/// 
/// \param [in] channel ͨ���š�
/// \retval <0 ����ʧ��
/// \retval 0 ���ٳɹ�
int PlayDestory(int channel);


/// ��ʼ����, �ײ���ջط�EOF��־, ���TOF��־.
/// 
/// \param [in] channel ͨ���š�
/// \retval 0  ��ʼ�ɹ�
/// \retval <0  ��ʼʧ��
int PlayStart(int channel);


/// ֹͣ���룬��ǰ���ڽ��е���������Ӧ�������ء�
/// 
/// \param [in] channel ͨ���š�
/// \retval 0  ֹͣ�ɹ�
/// \retval <0  ֹͣʧ��
int PlayStop(int channel);


/// ��ͣ���롣
/// 
/// \param [in] channel ͨ���š�
/// \retval 0  ��ͣ�ɹ�
/// \retval <0  ��ͣʧ��
int PlayPause(int channel);


/// �ָ����롣
/// 
/// \param [in] channel ͨ���š�
/// \retval 0  �ָ��ɹ�
/// \retval <0  �ָ�ʧ��
int PlayResume(int channel);


/// ��ս��뻺�壬������ѰI֡��
/// 
/// \param [in] channel ͨ���š�
/// \retval 0  ��ճɹ�
/// \retval <0  ���ʧ��
int PlayFlush(int channel);


/// ��ûط���Ҫ�����ݿ����Ϣ�����طŵ�EOF��־����ʱ, ����ײ㻺���Ѿ�ȫ������
/// ��ɣ�Ӧ�ó����´ε���PlayGetBufferʱ�᷵�ط��سɹ�, ����pBlock�еĻ��峤��
/// ����Ϊ0, Ӧ�ó���ݴ�ֹͣ�ط�, �ﵽ�طŽ���ͬ����Ŀ��.
///
/// \param [in] channel ͨ���š�
/// \param [out] pBlock ָ��ط����ݿ���Ϣ�ṹPLAY_BLOCK��ָ�롣Ӧ�ó���������
///        �ṹ��ƫ���ļ�ָ�룬��׼����Ӧ��С�����ݣ�Ȼ�����PlayPutBuffer�ӿ���
/// 	   �����ݡ��൱�ڻط�ʱ�ļ��ķ��ʲ�����API�������ƣ�Ӧ�ó���ֻ�����ļ���
///        ��ȡ��
/// \retval 0  ��óɹ��������峤�ȿ���Ϊ0
/// \retval <0  �طŻ��������� Ӧ�ó��������Ҫ˯��һ���ٳ��ԡ�
/// \see   PlaySetEof, PlaySetTof, PlayPutBuffer
int PlayGetBuffer(int channel, PLAY_BLOCK *pBlock);


/// ������ݵ��طŻ��壬�첽��ʽ���ײ�������ʱ, ��Ҫ��ջ����ڵ����ݡ�
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pBuffer ��д������ݻ���ָ�롣
/// \param [in] dwCount ��д������ݳ��ȡ�
/// \retval 0  д�ɹ�
/// \retval <0  дʧ��
int PlayPutBuffer(int channel, unsigned char * pBuffer, unsigned int dwCount);


/// ���ûطŵ��ٶȡ�
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwSpeed �ٶȴ�С��ȡ\a  play_speed_t ���͵�ֵ�����ٵ�����Խ��
///       ��ʾԽ�������ٵ�����Խ�󣬱�ʾԽ�졣
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int PlaySetSpeed(int channel, unsigned int dwSpeed);


/// ���ûطŵ�������ʵ�ֶ�·�طźͻطŻ������ŵ�Ŀ�ġ������õ���ʵ�ʻ�������
/// �ɵײ�����ײ���ڷֱ���ҲӦ���Զ�ʶ���ת����
/// 
/// \param [in] channel ͨ���š�
/// \param [in] pSourceRect ��ƵԴ���򣬲������������ϵ��
/// \param [in] pDestRect ��ƵĿ�����򣬲���ͼ��������ϵ��
/// \param [in] priority ��Ƶ��ʾ���ȼ��������ȼ����ϣ������ȼ�����.
/// \retval 0  д�ɹ�
/// \retval <0  дʧ��
int PlaySetRect(int channel, VIDEO_RECT *pSourceRect, VIDEO_RECT *pDestRect);
int PlaySetRect2(int channel, VIDEO_RECT *pSourceRect, VIDEO_RECT *pDestRect, int priority);


/// ���ûطŵ���ʽ��
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwStandard �ط���ʽ
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ�ܡ�
int PlaySetVstd(int channel,unsigned int dwStandard);


/// ���ûطŵķ���
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwDirection �طŷ���ȡplay_direction_t���͵�ֵ��
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
/// \see play_direction_t
int PlaySetDirection(int channel, unsigned int dwDirection);


/// ���ûطŵ�������
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwLVolume ������������ȡֵ0-100��
/// \param [in] dwRVolume ������������ȡֵ0-100��
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int PlaySetVolume(int channel, unsigned int dwLVolume, unsigned int dwRVolume);


/// �ֶ��������ţ���Ҫ�ڲ�����ͣ����ã�������������Ӧ֡�����Զ��ٴ���ͣ������
/// Ϊ��������ʽ������˺�������ʱ�ϴε������Ż�û����ɣ���ȡʣ��֡����������
/// ֡�������ֵ��Ϊ��Ҫ�������ŵ�֡����
/// 
/// \param [in] channel ͨ���š�
/// \param [in] dwFrames ÿ�β������ŵ�֡����
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int PlayStep(int channel, unsigned int dwFrames);


/// ȡ��ǰ���ڻط���Ƶ�����ڵ�ʱ���롣ʱ����Ҫ�ڱ���ʱ��ӵ���Ƶ�����У��Ա�֤
/// �ط�ʱ׼ȷ��ʾʱ�䡣ͬʱ�طŽ���Ľ�����Ҳ�Ǹ������ʱ����ȷ�������, �ڴ�
/// �������ش���ʱ,�ط�ģ������ʱ��, ��ȷ���طŽ������������.
/// 
/// \param [in] channel ͨ���š�
/// \param [out] pTime �ط�ʱ�䣬ָ��ϵͳʱ��ṹSystemTime��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval <0  ��ȡʧ�ܡ�
int PlayGetTime(int channel, SYSTEM_TIME* pTime);


/// ���ûطŵĻ��ʡ�
/// 
/// \param [in] channel ͨ���š�
/// \param [in] iLevel ���ʵȼ�1-4
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int PlaySetQuality(int channel, int iLevel);


/// �õ��ط�֧�ֵ����ԡ�
/// 
/// \param [out] pCaps ָ��ط����ԽṹPLAY_CAPS��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval <0  ��ȡʧ�ܡ�
int PlayGetCaps(PLAY_CAPS * pCaps);


/// ���������ļ���ȡ��ϱ�־��End of File����
/// �ײ�ط�ģ���ڻ��������ȫ��������ɺ���������־�� 
/// 
/// \param [in] iChannel ͨ���š�
/// \param [in] bIsEof true-���ñ�־��FALST-��ձ�־��
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
/// \see	PlayGetBuffer, PlayStart
void PlaySetEof(int iChannel, int bIsEof);

/// ���ûط�ʱ��Ƶ����֮��Ļط��������ɫ.
/// 
/// \param [in] color Ҫ���õ���ɫ��16���Ʊ�ʾΪ0x00BBGGRR������ֽڱ�����
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int PlaySetBkColor(unsigned int color);


/// ���������ļ�����ĩβ��־��Tail of File����
/// �ײ�ط�ģ���ڽ��������������־������Tof��ʱ����Ӧ�ó�������� һ����
/// �ļ��������һ��ʱ���ã� �������Ա�֤�ļ��м�����ݴ��󱻺��ԣ����Ժ������
/// �����ˣ������ļ�ĩβ�����ݴ���ᴥ���ط�ֹͣ������ػ��ļ�ĩβ���������⣩��
///
/// \param [in] channel ͨ���š�
/// \param [in] bIsTof true-���ñ�־��FALST-��ձ�־��
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
/// \see	PlayGetBuffer, PlayStart
int PlaySetTof(int channel, int bIsTof);

/// �õ���ǰ���ڽ����������Ϣ
int PlayGetStreamInfo(int channel, PLAY_STREAM_INFO *pStreamInfo);

/// ���ûط���֡���ٶ�
void PlaySetFPS(int iChannel, int fps);


/// �Ƿ񴴽�ͼƬ����ͨ��
/// \param [in] create �Ƿ񴴽�ͼƬ����ͨ��
int PlayJPEGCreate(int create);


/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
