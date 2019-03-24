//
//  "$Id: AudioIn.h 371 2010-03-05 06:20:50Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_AUDIO_IN_H__
#define __PAL_AUDIO_IN_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup AudioInAPI API Audio Input 
/// 音频输入接口
/// \n 调用流程图:
/// \code
///    ================================
///               |
///        getAudioInputChannels
///               |
///    ================================
/// \endcode
/// @{


/// 得到音频输入通道的个数
int getAudioInputChannels();


/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
