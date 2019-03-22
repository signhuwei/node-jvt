//
//  "$Id: Split.h 2296 2011-12-02 11:28:03Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_SPLIT_H__
#define __PAL_SPLIT_H__

#include "Types.h"
#include "Types/Types.h"
#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup VideoSplit API API Video Split 
/// 音频输出接口
/// \n 调用流程图:
/// \code
///    ================================
///               |
///       createVideoSplit
///               |
///            addRef
///               |
///            setVstd
///               |-----------+
///               |           |
///               |        setRect
///               |           |
///               |-----------+
///            release
///               |
///    ================================
/// \endcode
/// @{
//#ifdef WIN32
#if 0
struct RECT
{
	int left;
	int top;
	int right;
	int bottom;
};
#endif

/// 画面分割接口，512字节
typedef struct VideoSplit
{
	/// 底层私有数据
	void *priv;


	/// 增加接口引用
	int (*addRef)(struct VideoSplit *thiz);


	/// 释放接口
	int (*release)(struct VideoSplit *thiz);

	/// 设置视频制式。
	/// 
	/// \param [in] dwStandard 视频制式，取video_standard_t类型的值。
	/// \retval 0  设置成功
	/// \retval <0  设置失败
	int (*setVstd)(struct VideoSplit *thiz, int dwStandard);
	
	
	/// 设置预览显示区域，以实现预览区域电子放大。
	/// 
	/// \param [in] channel 通道号。
	/// \param [in] pSourceRect 视频源区域，采用相对坐标体系，不缩放时pSourceRect传NULL。
	/// \param [in] pDestRect 视频目标区域，采用图形坐标体系。
	/// \retval 0  写成功
	/// \retval <0  写失败
	int (*setRect)(struct VideoSplit *thiz, int channel, const RECT *pSourceRect, const RECT *pDestRect, int nPriority);

	int (*setDeflick)(struct VideoSplit *thiz, int dwDeflick);

	int (*setVoPosition)(struct VideoSplit *thiz, int splitMode, int subIndex, const RECT *pDestRect, int rectNum);
	/// 保留
	int reserved[121];
} VideoSplit;


//分割能力
typedef struct tagSPLIT_CAPS
{
	unsigned int dwCombine;
}SPLIT_CAPS;


/// 分割器描述，共128字节
typedef struct _SplitDesc
{
	int resv[32];
} SplitDesc;


//画面分割模式
typedef struct tagSPLIT_MODE
{
	unsigned int dwMode;
	unsigned int dwIndex; 
	unsigned int Rev[4];
}SPLIT_MODE;

int setVoPosition(int splitMode, int subIndex, const RECT *pDestRect, int rectNum);
/// 创建画面分割器
///
/// \param [in] desc 音频输出接口描述结构AudioOutDesc指针
/// \param [out] videoSplit 视频分割指针的指针
/// \retval <0 创建失败
/// \retval 0 创建成功
int createVideoSplit(SplitDesc *desc, VideoSplit **videoSplit);


#ifdef __cplusplus
}
#endif

#endif 
