
#ifndef __AUDIO_OUT_API_H__
#define __AUDIO_OUT_API_H__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup AudioOutAPI API Audio Output 
/// 音频输出接口
/// \n 调用流程图:
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

/// 音频输出能力结构，128字节
typedef struct AudioOutCaps
{
	int reserved[32];	///< 保留
}AudioOutCaps;

/// 音频输出接口，512字节
typedef struct AudioOutput
{
	/// 底层私有数据
	void *priv;


	/// 增加接口引用
	int (*addRef)(struct AudioOutput *thiz);


	/// 释放接口
	int (*release)(struct AudioOutput *thiz);


	/// 得到音频输出支持的特性。
	///
	/// \param [in] thiz 本对象指针
	/// \param [out] caps 指向音频输出特性结构AudioOutCaps的指针。
	/// \retval 0  获取成功。
	/// \retval <0  获取失败。
	int (*getCaps)(struct AudioOutput *thiz, AudioOutCaps * caps);


	/// 切换音频输入输出回环
	///
	/// \param [in] thiz 音频输出接口指针
	/// \param [in] srcs 音频输入通道号掩码，每一位对应一个音频输入通道
	/// \retval <0 切换失败
	/// \retval 0 切换成功
	int (*fromIn)(struct AudioOutput *thiz, ulong srcs);


	/// 设置音频输出的音量
	///
	/// \param [in] thiz 音频输出接口指针
	/// \param [in] volume 音量，取值0-100，0表示静音
	/// \retval <0 切换失败
	/// \retval 0 切换成功
	int (*setVolume)(struct AudioOutput *thiz, int volume);


	/// 保留
	int reserved[112];
} AudioOutput;


/// 得到音频输出通道的个数
int getAudioOutputChannels();


/// 音频输出接口描述，128字节
typedef struct AudioOutDesc
{
	int	channel;		///< 音频输出物理通道号		
	int reserved[31];	///< 保留
} AudioOutDesc;


/// 创建音频输出接口
///
/// \param [in] desc 音频输出接口描述结构AudioOutDesc指针
/// \param [out] audioOutput 音频输出接口指针的指针
/// \retval <0 创建失败
/// \retval 0 创建成功
int createAudioOutput(AudioOutDesc *desc, AudioOutput **audioOutput);


/// @} end of group

#ifdef __cplusplus
}
#endif

#endif
