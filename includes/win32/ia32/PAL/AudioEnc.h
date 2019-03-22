//
//  "$Id: AudioEnc.h 1140 2010-10-11 09:04:03Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_AUDIO_ENC_H__
#define __PAL_AUDIO_ENC_H__

#include "Types.h"
#include "Types/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup AudioEncAPI API Audio Encoder
/// 音频数据编码接口，用于通道音频数据编码，语音对讲等等。
/// \n 调用流程图:
/// \code
///    =========================================
///                   |                         
///            createAudioEncoder                  
///                   |                         
///                addRef                  
///                   |----------------+        	 
///               setFormat            |        	
///                   |                |        	 
///                 start              |        	 
///         +---------|            setVolume
///         |     getPacket            |        	 
///         |   releasePacket          |        	 
///         +---------|                |           	
///                 stop               |         	
///                   |----------------+         	
///               release                  
///                   |                         
///    =========================================
/// \endcode
/// @{

/// 音频编码格式
typedef enum AudioEncType
{
	audioEncPCM = 0,
	audioEncADPCM,
	audioEncG711A,
	audioEncG711Mu,
	audioEncG726,
	audioEncMPEG2Layer1,
	audioEncAMR,
} AudioEncType;


/// 音频编码设备特性，128字节
typedef struct AudioEncCaps
{
	/// 支持的压缩标准的掩码，位序号对应枚举类型AudioEncType的每一个值。
	/// 置位表示支持该枚举值对应的特性，清零表示不支持。
	ulong	format;

	/// 保留
	int reserved[31];
} AudioEncCaps;


/// 音频编码格式，128字节
typedef struct AudioEncFormat
{
	AudioEncType	type;			///< 音频编码的类型
	int				frequency;		///< 采样率，Hz为单位，比如44100Hz	
	char			depth;			///< 采样位深，支持8位，16位
	char			packetPeriod;	///< 打包周期，ms为单位，如10ms，20ms，0表示使用默认周期
	int				reserved[29];	///< 保留
} AudioEncFormat;


/// 音频编码包，128字节
typedef struct AudioEncPacket
{
	uchar *			buffer;		///< 数据缓冲指针
	ulong			length;		///< 数据缓冲有效长度
	uint64			pts;		///< 时间戳，ms为单位
	ulong			sequence;	///< 包序号，用于校验是否丢包
	char			head;		///< 是否包含帧头，1-包含，0-不包含
	char			tail;		///< 是否包含帧尾，1-包含，0-不包含
	char			newFormat;	///< 编码格式是否发生了变动，0：未变动，1：已变动
	char			remain;		///< 除了这个数据包，否还有残留数据
	int				reserved[26];///< 保留
} AudioEncPacket;


/// 音频编码接口，512字节
typedef struct AudioEncoder
{
	/// 底层私有数据
	void *priv;


	/// 增加接口引用
	int (*addRef)(struct AudioEncoder *thiz);


	/// 释放接口
	int (*release)(struct AudioEncoder *thiz);


	/// 得到音频编码支持的特性。
	///
	/// \param [in] thiz 本对象指针
	/// \param [out] caps 指向音频编码特性结构AudioEncCaps的指针。
	/// \retval 0  获取成功。
	/// \retval <0  获取失败。
	int (*getCaps)(struct AudioEncoder *thiz, AudioEncCaps * caps);


	/// 开始音频编码
	///
	/// \param [in] thiz 本对象指针
	/// \retval <0 开始失败
	/// \retval 0 开始成功
	int (*start)(struct AudioEncoder *thiz);


	/// 停止音频编码
	///
	/// \param [in] thiz 本对象指针
	/// \retval <0 停止失败
	/// \retval 0 停止成功
	int (*stop)(struct AudioEncoder *thiz);


	/// 读取编码数据，读为非阻塞模式；每次传出一个连续的数据块，如果数据已经分块，
	/// 则分多次传出。如果没有数据，则返回错误。
	///
	/// \param [in] thiz 本对象指针
	/// \param [in] packet 音频包结构AudioEncPacket指针。
	/// \return>=0 通道号（在输入通道号为-1时）
	/// \retval 0  读成功
	/// \retval <0  读失败
	int (*getPacket)(struct AudioEncoder *thiz, AudioEncPacket * packet);


	/// 释放采样数据
	/// \param [in] thiz 本对象指针
	int (*releasePacket)(struct AudioEncoder *thiz);


	/// 设置音频数据编码的格式。
	///
	/// \param [in] thiz 本对象指针。
	/// \param [in] format 指向音频编码格式结构AudioEncFormat的指针。
	/// \retval 0  设置成功
	/// \retval <0  设置失败
	int (*setFormat)(struct AudioEncoder *thiz, AudioEncFormat * format);


	/// 设置音频编码的音量。
	///
	/// \param [in] thiz 本对象指针。
	/// \param [in] volume 音量，取值0-100。
	/// \retval 0  设置成功
	/// \retval <0  设置失败
	int (*setVolume)(struct AudioEncoder *thiz, int volume);


	/// 保留
	int reserved[118];
} AudioEncoder;

/// 码流类型
typedef enum AudioEncStream
{
	audioEncStreamMain = 0,	///< 主码流
	audioEncStreamExtra1,	///< 辅码流1
	audioEncStreamExtra2,	///< 辅码流2
	audioEncStreamExtra3,	///< 辅码流3
	audioEncStreamTalkback,	///< 对讲码流
	audioEncStreamNumber	///< 种类数
} AudioEncStream;

/// 音频编码接口描述，128字节
typedef struct AudioEncDesc
{
	ulong	srcs;		///< 音频输入物理通道号掩码，每一位对应一个音频输入通道			
	AudioEncStream	stream;		///< 指定编码码流的类型
	int reserved[30];	///< 保留
} AudioEncDesc;


/// 创建音频编码接口
///
/// \param [in] desc 音频编码接口描述结构AudioEncDesc指针
/// \param [out] audioEncoder 音频编码接口指针的指针
/// \retval <0 创建失败
/// \retval 0 创建成功
int createAudioEncoder(AudioEncDesc *desc, AudioEncoder **audioEncoder);


/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
