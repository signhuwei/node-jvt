//
//  "$Id: Audio.h 2169 2011-11-16 09:10:56Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_AUDIO_H__
#define __PAL_AUDIO_H__

#ifdef __cplusplus
extern "C" {
#endif
	
/// \defgroup AudioOutAPI API Audio Output 
/// ��Ƶ��������������豸�ӿڣ������ڻط��豸��
/// \n ��������ͼ:
/// \code
///    ===============================================
///               |
///          AudioCreate
///               |------------+------------------+
///               |            |                  |  
///               |      AudioOutSetFormat        | 
///               |            |                  |
///               |      AudioOutStart            |	
///        AudioSwitch         |--------------+   |
///               |      AudioOutPutBuf       |   |
///               |            |--------------+   |
///               |        AudioOutStop           |
///               |            |                  |
///               |------------+------------------+
///          AudioDestory
///               |
///    ===============================================
/// \endcode
/// @{

/// ��Ƶ�л�����
enum audio_switch_t{
	AUDIO_SWITCH_MONITOR,	///< �л������������
	AUDIO_SWITCH_PLAY,		///< �л����ط������
	AUDIO_SWITCH_MUTE		///< ������
};

/// ������Ƶ�豸
///
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int AudioCreate(void);

/// ������Ƶ�豸
///
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 ���ٳɹ�
int AudioDestory(void);


/// �л�����Ƶ��������͡�
///
/// \param [in] dwType ��������ͣ�ȡ�±��е�ֵ��
/// \param [in] dwChannel ���ӻ�طŵ�ͨ���š�
/// \retval 0  �л��ɹ���
/// \retval <0  �л�ʧ�ܡ�
int AudioSwitch(unsigned int dwType, unsigned int dwChannel);

/// ���������Խ�����
///
/// \param ��
/// \return>0 ����ʧ��
/// \retval 0 �����ɹ�
int AudioOutStart(void);

/// ֹͣ�����Խ�����
///
/// \param ��
/// \return>0 ֹͣʧ��
/// \retval 0 ֹͣ�ɹ�
int AudioOutStop(void);

/// �����Խ������������
///
/// \param [in] src �������ݻ����ַ
/// \param [in] size �������ݻ��峤��
/// \return>0 ���ʧ��
/// \retval 0 ���ɹ�
void AudioOutPutBuf(unsigned char *src, int size);

/// �������ݵ�ѹ����ʽ
///
/// \param [in] coderType ѹ����ʽ
/// \return>0 ����ʧ��
/// \retval 0 ���óɹ�
int AudioOutSetFormat(int coderType);

/// @}

enum audio_encode_type
{
	NONE = 0,
	G729_8KBIT,
	G726_16KBIT,
	G726_24KBIT,
	G726_32KBIT,
	G726_40KBIT,
	PCM_8TO16BIT,
	PCM_ALAW,
	PCM_ULAW,
	ADPCM8K16BIT,
	ADPCM16K16BIT,
	G711_ALAW,
	MPEG2_LAYER1,
	AMR8K16BIT,
	G711_ULAW,
	IMA_ADPCM_8K16BIT
};

typedef struct tagAUDIOIN_FORMAT
{
	unsigned int	BitRate;		///< ������С��kbpsΪ��λ������192kbps��128kbps
	unsigned int	SampleRate;		///< �����ʣ�HzΪ��λ������44100Hz
	unsigned int	SampleBit;		///< ������λ��
	int		EncodeType;		///< ���뷽ʽ������audio_encode_type����
} AUDIOIN_FORMAT;


typedef struct tagAUDIOIN_CAPS
{
	unsigned int	Reserved;
} AUDIOIN_CAPS;

/// ��������Խ�֧�ֵı����ʽ
/// \param [in] pFormat ����ĸ�ʽ
/// \param [in] iMax ������
/// \return 0 ��ȡ�ɹ�
/// \return < 0 ��ȡʧ��
int AudioGetFormat(AUDIOIN_FORMAT* pFormat, int iMax);


//////////////////////////////////////////////////////////////////////////////
/// \defgroup AudioInAPI API Audio Input
/// ��Ƶ���ݱ���ӿڣ������ڲ����豸��
/// \n ��������ͼ:
/// \code
///    =========================================
///                   |                         
///      *AudioInGetChannels,AudioInGetCaps      
///                   |                         
///              AudioInCreate                  
///       +-----------|----------------+        	 
///       |     AudioInSetFormat       |        	
///       +-----------|                |        	 
///       |      AudioInStart          |        	 
///       | +---------|         AudioInSetVolume
///       | |  AudioInGetBuffer        |        	 
///       | +---------|                |           	
///       |      AudioInStop           |         	
///       +-----------|----------------+         	
///             AudioInDestroy                  
///                   |                         
///    =========================================
/// \endcode
/// @{

/// �õ��������Ƶ����ͨ����, ������¼��ͨ������������AudioIn����ʾ�������Ƶ���롣
///
/// \param ��
/// \return�������Ƶ����ͨ����Ŀ��
int AudioInGetChannels(void);


/// ������Ƶ�����豸
///
/// \param [in] iChannel ͨ����
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int AudioInCreate(int iChannel);


/// ������Ƶ�����豸
///
/// \param [in] iChannel ͨ����
/// \retval <0 ����ʧ��
/// \retval 0 ���ٳɹ�
int AudioInDestroy(int iChannel);


/// ��ʼ��Ƶ����
///
/// \param [in] iChannel ͨ����
/// \retval <0 ��ʼʧ��
/// \retval 0 ��ʼ�ɹ�
int AudioInStart(int iChannel);


/// ֹͣ��Ƶ����
///
/// \param [in] iChannel ͨ����
/// \retval <0 ֹͣʧ��
/// \retval 0 ֹͣ�ɹ�
int AudioInStop(int iChannel);


/// ��ȡ�������ݣ���Ϊ������ʱģʽ����ʱʱ�������أ�����ʵ�ʶ��������ݣ�����ʱʱ��
/// ���õĽ�С������������ݵ�ʵʱ�ԡ�
///
/// \param [in] iChannel ͨ���ţ�-1��ʾ������ͨ�������ݣ�������ͨ������Ϊ��������ֵ���ء�
/// \param [in] pBuffer ���������Ƶ�������ݵĻ���ָ�롣
/// \param [in,out] pdwCount �����ֵ�ǻ����С��������ֵ��ʵ�ʶ������ݵĳ��ȡ�
/// \param [in] dwTimeout ����ʱ��ʱ�䣬��λΪ���룬��Ϊ0��ʾһֱ�ȵ��������ݻ����Ϊֹ��
/// \return>=0 ͨ���ţ�������ͨ����Ϊ-1ʱ��
/// \retval 0  ���ɹ�
/// \retval <0  ��ʧ��
int AudioInGetBuffer(int iChannel, unsigned char* pBuffer, unsigned int* pdwCount, unsigned int dwTimeout);


/// ������Ƶ���ݱ���ĸ�ʽ��
///
/// \param [in] iChannel ͨ���š�
/// \param [in] pFormat ָ����Ƶ�����ʽ�ṹAUDIOIN _FORMAT��ָ�롣
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int AudioInSetFormat(int iChannel, AUDIOIN_FORMAT * pFormat);


/// ������Ƶ�����������
///
/// \param [in] iChannel ͨ���š�
/// \param [in] dwLVolume ������������ȡֵ0-100��
/// \param [in] dwRVolume ������������ȡֵ0-100��
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
//int AudioInSetVolume(int iChannel, unsigned int dwLVolume, unsigned int dwRVolume);
int FrontAudioInSetVolume(int iChannel, unsigned int dwLVolume, unsigned int dwRVolume);



/// �õ���Ƶ����֧�ֵ����ԡ�
///
/// \param [out] pCaps ָ����Ƶ�������ԽṹAUDIOIN_CAPS��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval <0  ��ȡʧ�ܡ�
int AudioInGetCaps(AUDIOIN_CAPS * pCaps);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif
