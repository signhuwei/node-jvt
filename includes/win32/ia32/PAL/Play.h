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
/// 多路音视频回放解码接口。
///	\n 调用流程图:
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

/// 回放数据包结构
#ifndef  FUNC_NEW_PLAY
typedef struct PLAY_BLOCK
{
	/// 需要的数据块字节数。
	unsigned int		length;

	/// 需要偏移的字节数。正向回放时，这个值一直传0即可，反相回放时，
	/// 需要传向前偏移的长度，为一个负数。
	int			offset;		
}PLAY_BLOCK;
#else
typedef struct PLAY_BLOCK
{
	/// 需要的数据块字节数。
	unsigned int		length;

	/// 需要偏移的字节数。正向回放时，这个值一直传0即可，反相回放时，
	/// 需要传向前偏移的长度，为一个负数。
	int			offset;	

	///存放数据的指针，必须要大于或者等于length
	unsigned char* buffer;	
	
	/// 保留字节
	int reserved[32];	
}PLAY_BLOCK;
#endif


/// 回放特性结构
typedef struct PLAY_CAPS
{
	/// 支持的正向播放速度的掩码，位序号对应枚举类型play_speed_t的每一个值。
	/// 置1表示支持该枚举值对应的特性，置0表示不支持。
	unsigned int ForwardSpeed;

	/// 支持的倒向播放速度的掩码，位序号对应枚举类型play_speed_t的每一个值。
	/// 置1表示支持该枚举值对应的特性，置0表示不支持。
	unsigned int BackwardSpeed;

	/// 支持的单步播放方向的掩码，位序号对应枚举类型play_direction_t的每一个值。
	/// 置1表示支持该枚举值对应的特性，置0表示不支持。
	unsigned int StepDirection;

	/// 是否支持音量控制，0-不支持，1-支持。
	unsigned char  VolumeControl;

	/// 保留
	unsigned char  Reserved[3];		
}PLAY_CAPS;

/// 回放解码能力结构,总共512字节.
typedef struct PLAY_INFO 
{
	unsigned int	nMaxDecodePower;	///< 支持的最高解码能力。
	unsigned int	nMaxSupportChannel;	///< 支持最多输入视频通道数。
	unsigned int	nCompression;		///< 解码类型,掩码表示
	unsigned int	nImageSize[32];		///< 各个通道的图像大小
	unsigned int	nDecodePower[32];	///< 各个通道的解码能力
	unsigned int	reserved[61];
} PLAY_INFO, *PPLAY_INFO;

/// 回放速度枚举值
enum play_speed_t {
	PLAY_SPEED_SLOW4,		///< 慢速4
	PLAY_SPEED_SLOW3,		///< 慢速3
	PLAY_SPEED_SLOW2,		///< 慢速2
	PLAY_SPEED_SLOW1,		///< 慢速1
	PLAY_SPEED_NORMAL,		///< 正常速度
	PLAY_SPEED_FAST1,		///< 快速1
	PLAY_SPEED_FAST2,		///< 快速2
	PLAY_SPEED_FAST3,		///< 快速3
	PLAY_SPEED_FAST4		///< 快速4
};

/// 回放方向枚举值
enum play_direction_t {	
	PLAY_DIRECTION_FORWARD,	///< 正向播放。
	PLAY_DIRECTION_BACKWARD	///< 倒向播放。
};

/// 回放解码码流信息结构,总共128字节.
typedef struct PLAY_STREAM_INFO 
{
	unsigned int	nImageWidth;	///< 解码图像的宽度
	unsigned int	nImageHeiht;	///< 解码图像的高度
	unsigned int	nCompression;	///< 解码类型,掩码表示，H264等
	unsigned int	nFrameRate;		///< 解码码流的帧率
	unsigned int	reserved[28];
} PLAY_STREAM_INFO, *PPLAY_STREAM_INFO;


typedef struct PLAY_STREAM_INFO2
{
	unsigned int nDecodeWidth; ///< 解码通道的宽高
	unsigned int nDecodeHeiht;
	unsigned int nStreamWidth; ///<当前码流的宽高
	unsigned int nStreamHeiht;
} PLAY_STREAM_INFO2, *PPLAY_STREAM_INFO2;

int PlayGetStreamInfo2(int channel, PLAY_STREAM_INFO2 *pStreamInfo);

/// 获得回放的解码能力
///
int PlayGetDecInfo(PLAY_INFO *pDspInfo);


/// 得到回放的通道数目。不包括语音回放的通道，语音回放通道是最大回放通道号加1。
/// 假设输出到每个视频输出断上的回放通道数一致，如PlayGetChannels返回2，有两个
/// 视频输出端，则输出端0上的回放通道序号为0，1，输出端1上的回放通道序号为2，3，
/// 由于系统编码能力的限制，最多只能有两个回放通道，可能在同一个输出端口，也
/// 可能在不同的端口。
/// 
/// \param 无
/// \return映射到任一视频输出端口上的最大回放的通道数目。
int PlayGetChannels(void);


/// 得到HVR支持的最大解码通道数目。
/// \param 无
/// \return映射到任一视频输出端口上的最大解码的通道数目。
int PlayGetDecoderChannels(void);

/// 创建回放设备
/// 
/// \param [in] channel 通道号。
/// \retval <0 创建失败
/// \retval 0 创建成功
int PlayCreate(int channel);


/// 销毁回放设备
/// 
/// \param [in] channel 通道号。
/// \retval <0 销毁失败
/// \retval 0 销毁成功
int PlayDestory(int channel);


/// 开始解码, 底层清空回放EOF标志, 清空TOF标志.
/// 
/// \param [in] channel 通道号。
/// \retval 0  开始成功
/// \retval <0  开始失败
int PlayStart(int channel);


/// 停止解码，当前正在进行的其他调用应立即返回。
/// 
/// \param [in] channel 通道号。
/// \retval 0  停止成功
/// \retval <0  停止失败
int PlayStop(int channel);


/// 暂停解码。
/// 
/// \param [in] channel 通道号。
/// \retval 0  暂停成功
/// \retval <0  暂停失败
int PlayPause(int channel);


/// 恢复解码。
/// 
/// \param [in] channel 通道号。
/// \retval 0  恢复成功
/// \retval <0  恢复失败
int PlayResume(int channel);


/// 清空解码缓冲，重新搜寻I帧。
/// 
/// \param [in] channel 通道号。
/// \retval 0  清空成功
/// \retval <0  清空失败
int PlayFlush(int channel);


/// 获得回放需要的数据块的信息。当回放的EOF标志设置时, 如果底层缓冲已经全部解码
/// 完成，应用程序下次调用PlayGetBuffer时会返回返回成功, 但是pBlock中的缓冲长度
/// 被设为0, 应用程序据此停止回放, 达到回放结束同步的目的.
///
/// \param [in] channel 通道号。
/// \param [out] pBlock 指向回放数据块信息结构PLAY_BLOCK的指针。应用程序根据这个
///        结构来偏移文件指针，并准备相应大小的数据，然后调用PlayPutBuffer接口填
/// 	   入数据。相当于回放时文件的访问参数由API库来控制，应用程序只负责文件的
///        读取。
/// \retval 0  获得成功，但缓冲长度可能为0
/// \retval <0  回放缓冲已满， 应用程序可能需要睡眠一下再尝试。
/// \see   PlaySetEof, PlaySetTof, PlayPutBuffer
int PlayGetBuffer(int channel, PLAY_BLOCK *pBlock);


/// 填充数据到回放缓冲，异步方式。底层解码出错时, 需要清空缓冲内的数据。
/// 
/// \param [in] channel 通道号。
/// \param [in] pBuffer 待写入的数据缓冲指针。
/// \param [in] dwCount 待写入的数据长度。
/// \retval 0  写成功
/// \retval <0  写失败
int PlayPutBuffer(int channel, unsigned char * pBuffer, unsigned int dwCount);


/// 设置回放的速度。
/// 
/// \param [in] channel 通道号。
/// \param [in] dwSpeed 速度大小，取\a  play_speed_t 类型的值，慢速的数字越大，
///       表示越慢，快速的数字越大，表示越快。
/// \retval 0  设置成功
/// \retval <0  设置失败
int PlaySetSpeed(int channel, unsigned int dwSpeed);


/// 设置回放的区域，以实现多路回放和回放画面缩放的目的。解码用到的实际缓冲区域
/// 由底层管理，底层对于分辨率也应该自动识别和转换。
/// 
/// \param [in] channel 通道号。
/// \param [in] pSourceRect 视频源区域，采用相对坐标体系。
/// \param [in] pDestRect 视频目标区域，采用图形坐标体系。
/// \param [in] priority 视频显示优先级，高优先级在上，低优先级在下.
/// \retval 0  写成功
/// \retval <0  写失败
int PlaySetRect(int channel, VIDEO_RECT *pSourceRect, VIDEO_RECT *pDestRect);
int PlaySetRect2(int channel, VIDEO_RECT *pSourceRect, VIDEO_RECT *pDestRect, int priority);


/// 设置回放的制式。
/// 
/// \param [in] channel 通道号。
/// \param [in] dwStandard 回放制式
/// \retval 0  设置成功
/// \retval <0  设置失败。
int PlaySetVstd(int channel,unsigned int dwStandard);


/// 设置回放的方向。
/// 
/// \param [in] channel 通道号。
/// \param [in] dwDirection 回放方向，取play_direction_t类型的值。
/// \retval 0  设置成功
/// \retval <0  设置失败
/// \see play_direction_t
int PlaySetDirection(int channel, unsigned int dwDirection);


/// 设置回放的音量。
/// 
/// \param [in] channel 通道号。
/// \param [in] dwLVolume 左声道音量，取值0-100。
/// \param [in] dwRVolume 右声道音量，取值0-100。
/// \retval 0  设置成功
/// \retval <0  设置失败
int PlaySetVolume(int channel, unsigned int dwLVolume, unsigned int dwRVolume);


/// 手动单步播放，需要在播放暂停后调用，解码器播放相应帧数后自动再次暂停。调用
/// 为非阻塞方式，如果此函数调用时上次单步播放还没有完成，则取剩余帧数和新设置
/// 帧数的最大值作为需要继续播放的帧数。
/// 
/// \param [in] channel 通道号。
/// \param [in] dwFrames 每次操作播放的帧数。
/// \retval 0  设置成功
/// \retval <0  设置失败
int PlayStep(int channel, unsigned int dwFrames);


/// 取当前正在回放视频数据内的时间码。时间需要在编码时添加到视频数据中，以保证
/// 回放时准确显示时间。同时回放界面的进度条也是根据这个时间来确定坐标的, 在此
/// 函数返回错误时,回放模块会估算时间, 再确定回放界面进度条坐标.
/// 
/// \param [in] channel 通道号。
/// \param [out] pTime 回放时间，指向系统时间结构SystemTime的指针。
/// \retval 0  获取成功。
/// \retval <0  获取失败。
int PlayGetTime(int channel, SYSTEM_TIME* pTime);


/// 设置回放的画质。
/// 
/// \param [in] channel 通道号。
/// \param [in] iLevel 画质等级1-4
/// \retval 0  设置成功
/// \retval <0  设置失败
int PlaySetQuality(int channel, int iLevel);


/// 得到回放支持的特性。
/// 
/// \param [out] pCaps 指向回放特性结构PLAY_CAPS的指针。
/// \retval 0  获取成功。
/// \retval <0  获取失败。
int PlayGetCaps(PLAY_CAPS * pCaps);


/// 设置数据文件读取完毕标志（End of File）。
/// 底层回放模块在缓冲的数据全部解码完成后会检测这个标志。 
/// 
/// \param [in] iChannel 通道号。
/// \param [in] bIsEof true-设置标志，FALST-清空标志。
/// \retval 0  设置成功
/// \retval <0  设置失败
/// \see	PlayGetBuffer, PlayStart
void PlaySetEof(int iChannel, int bIsEof);

/// 设置回放时视频区域之外的回放区域的颜色.
/// 
/// \param [in] color 要设置的颜色，16进制表示为0x00BBGGRR，最高字节保留。
/// \retval 0  设置成功
/// \retval <0  设置失败
int PlaySetBkColor(unsigned int color);


/// 设置数据文件读到末尾标志（Tail of File）。
/// 底层回放模块在解码出错会检测这个标志。设置Tof的时机由应用程序决定， 一般在
/// 文件读到最后一簇时设置， 这样可以保证文件中间的数据错误被忽略（忽略后会引起
/// 马赛克），而文件末尾的数据错误会触发回放停止（解决关机文件末尾马赛克问题）。
///
/// \param [in] channel 通道号。
/// \param [in] bIsTof true-设置标志，FALST-清空标志。
/// \retval 0  设置成功
/// \retval <0  设置失败
/// \see	PlayGetBuffer, PlayStart
int PlaySetTof(int channel, int bIsTof);

/// 得到当前正在解码的码流信息
int PlayGetStreamInfo(int channel, PLAY_STREAM_INFO *pStreamInfo);

/// 设置回放满帧的速度
void PlaySetFPS(int iChannel, int fps);


/// 是否创建图片解码通道
/// \param [in] create 是否创建图片解码通道
int PlayJPEGCreate(int create);


/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
