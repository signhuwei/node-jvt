//
//  "$Id: AudioDec.h 1140 2010-10-11 09:04:03Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_AUDIO_DEC_H__
#define __PAL_AUDIO_DEC_H__

#include "Types.h"
#include "Types/Types.h"
#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup AudioDecAPI API Audio Decoder
/// 音频解码接口，音频解码用于语音对讲，语音提示等多种场合。
/// \n 调用流程图:
/// \code
///    ==========================================
///               |
///	      createAudioDecorder
///               |
///            addRef
///               |-----------------+
///             start               |
///               |---------+    setVolume
///           putBuffer     |       |
///               |---------+       |
///             stop                |
///               |-----------------+
///            release
///               |
///    ==========================================
/// \endcode
/// @{

enum AudioEncType;


/// 解码的压缩数据帧结构，128字节
typedef struct AudioDecFormat
{
	AudioEncType type:8;	///< 音频编码的类型
	int reserved[31];		///< 保留
} AudioDecFormat;

/// 音频解码数据包结构，128字节
typedef struct AudioDecPacket
{
	/// 待写入的帧数据缓冲指针，多个帧不能拼在一起。
	uchar * buffer;

	/// 待写入的帧数据长度。
	ulong	length;

	/// 解码后音频缓冲播放速率，用相对正常速度的倍速表示，比如0.5表示半速播放，
	/// 1.0表示原速播放，2.0表示两倍速播放。如果音频解码器支持音频输出的频率控制，
	/// 就应该根据speed的值做频率控制处理，否则直接静音。
	float speed;

	/// 保留
	int reserved[29];
}AudioDecPacket;

/// 音频解码能力结构，128字节
typedef struct AudioDecCaps
{
	int reserved[32];	///< 保留
}AudioDecCaps;

/// 音频解码接口，512字节
typedef struct AudioDecoder
{
	/// 底层私有数据
	void *priv;


	/// 增加接口引用
	int (*addRef)(struct AudioDecoder *thiz);


	/// 释放接口
	int (*release)(struct AudioDecoder *thiz);


	/// 获取接口能力特性
	///
	/// \param [in] thiz 本对象指针
	/// \param [out] caps 音频解码能力结构
	/// \return <0 获取失败
	/// \retval 0 获取成功
	int (*getCaps)(struct AudioDecoder *thiz, AudioDecCaps *caps);


	/// 开启音频解码。如果没有混音设备，开启后音频输出自动切换到当前解码通道的音频。
	///
	/// \param [in] thiz 本对象指针
	/// \return <0 开启失败
	/// \retval 0 开启成功
	int (*start)(struct AudioDecoder *thiz);


	/// 停止音频解码。如果没有混音设备，停止后音频输出自动切换到被中断的解码通道的音频。
	/// 如果无解码音频，则输出监视音频。
	///
	/// \param [in] thiz 本对象指针
	/// \return <0 停止失败
	/// \retval 0 停止成功
	int (*stop)(struct AudioDecoder *thiz);


	/// 清空解码后音频缓冲，被阻塞的putFrame将会立即返回。
	/// 
	/// \param [in] thiz 本对象指针
	/// \retval 0  清空成功
	/// \retval <0  清空失败
	int (*flush)(struct AudioDecoder *thiz);


	/// 检查解码后缓冲是否为空，即音频是否已经被全部呈现。
	/// 
	/// \param [in] thiz 视频解码接口指针
	/// \retval 0  非空
	/// \retval 1  已空
	/// \return <0 检查出错
	int (*empty)(struct AudioDecoder *thiz);


	/// 设置音频数据解码的格式。
	///
	/// \param [in] thiz 本对象指针。
	/// \param [in] format 音频解码格式AudioDecFormat指针。
	/// \retval 0  设置成功
	/// \retval <0  设置失败
	int (*setFormat)(struct AudioDecoder *thiz, AudioDecFormat* format);


	/// 填充帧数据到音频解码缓冲，阻塞模式，解码完成后返回。解码后的音频不一定立即显示，
	/// 底层还需要进行频率控制，如果解码后的图像缓冲已满，本调用将会被阻塞更长时间，
	/// 直到解码后缓冲有足够空间，让本次解码完成。
	///
	/// \param [in] thiz 本对象指针
	/// \param [in] packet 解码数据包AudioDecPacket指针
	/// \return <0 填充失败
	/// \retval 0 填充成功
	int (*putPacket)(struct AudioDecoder *thiz, AudioDecPacket *packet);


	/// 设置音频解码的音量。
	///
	/// \param [in] thiz 本对象指针。
	/// \param [in] volume 音量，取值0-100。
	/// \retval 0  设置成功
	/// \retval <0  设置失败
	int (*setVolume)(struct AudioDecoder *thiz, int volume);

	/// 保留
	int reserved[117];
}AudioDecoder;

/// 音频解码接口描述，128字节
typedef struct AudioDecDesc
{
	int	dest;			///< 解码后音频输出通道号			
	int reserved[31];	///< 保留
} AudioDecDesc;


/// 创建音频解码接口
///
/// \param [in] desc 音频解码接口描述结构AudioDecDesc指针
/// \param [out] audioEncoder 音频解码接口指针的指针
/// \retval <0 创建失败
/// \retval 0 创建成功
int createAudioDecoder(AudioDecDesc *desc, AudioDecoder** audioDecoder);


#ifdef __cplusplus
}
#endif

#endif
