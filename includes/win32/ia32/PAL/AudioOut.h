
#ifndef __AUDIO_OUT_API_H__
#define __AUDIO_OUT_API_H__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup AudioOutAPI API Audio Output 
/// ��Ƶ����ӿ�
/// \n ��������ͼ:
/// \code
///    ================================
///               |
///     getAudioOutputChannels
///               |
///       createAudioOutput
///               |
///            addRef
///               |-----------+
///             fromIn     setVolume
///               |-----------+
///            release
///               |
///    ================================
/// \endcode
/// @{

/// ��Ƶ��������ṹ��128�ֽ�
typedef struct AudioOutCaps
{
	int reserved[32];	///< ����
}AudioOutCaps;

/// ��Ƶ����ӿڣ�512�ֽ�
typedef struct AudioOutput
{
	/// �ײ�˽������
	void *priv;


	/// ���ӽӿ�����
	int (*addRef)(struct AudioOutput *thiz);


	/// �ͷŽӿ�
	int (*release)(struct AudioOutput *thiz);


	/// �õ���Ƶ���֧�ֵ����ԡ�
	///
	/// \param [in] thiz ������ָ��
	/// \param [out] caps ָ����Ƶ������ԽṹAudioOutCaps��ָ�롣
	/// \retval 0  ��ȡ�ɹ���
	/// \retval <0  ��ȡʧ�ܡ�
	int (*getCaps)(struct AudioOutput *thiz, AudioOutCaps * caps);


	/// �л���Ƶ��������ػ�
	///
	/// \param [in] thiz ��Ƶ����ӿ�ָ��
	/// \param [in] srcs ��Ƶ����ͨ�������룬ÿһλ��Ӧһ����Ƶ����ͨ��
	/// \retval <0 �л�ʧ��
	/// \retval 0 �л��ɹ�
	int (*fromIn)(struct AudioOutput *thiz, ulong srcs);


	/// ������Ƶ���������
	///
	/// \param [in] thiz ��Ƶ����ӿ�ָ��
	/// \param [in] volume ������ȡֵ0-100��0��ʾ����
	/// \retval <0 �л�ʧ��
	/// \retval 0 �л��ɹ�
	int (*setVolume)(struct AudioOutput *thiz, int volume);


	/// ����
	int reserved[112];
} AudioOutput;


/// �õ���Ƶ���ͨ���ĸ���
int getAudioOutputChannels();


/// ��Ƶ����ӿ�������128�ֽ�
typedef struct AudioOutDesc
{
	int	channel;		///< ��Ƶ�������ͨ����		
	int reserved[31];	///< ����
} AudioOutDesc;


/// ������Ƶ����ӿ�
///
/// \param [in] desc ��Ƶ����ӿ������ṹAudioOutDescָ��
/// \param [out] audioOutput ��Ƶ����ӿ�ָ���ָ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int createAudioOutput(AudioOutDesc *desc, AudioOutput **audioOutput);


/// @} end of group

#ifdef __cplusplus
}
#endif

#endif
