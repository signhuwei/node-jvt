//
//  "$Id: Keyboard.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_KEYBOARD_H__
#define __PAL_KEYBOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup KeyboardAPI API Keyboard
/// 键盘API。
///	\n 调用流程图:
/// \code
///    ===========================
///                |
///           KeyboardCreate
///                |-----------------------------+
///           KeyboardGetData  KeyboardGetData   |
///                |-----------------------------+
///           KeyboardDestory
///                |
///    ===========================
/// \endcode
/// @{


/// 鼠标输入数据结构
typedef struct KEYBOARD_DATA
{
	/// 键盘消息类型
	unsigned long	msg;

	/// 键盘消息代码
	unsigned long	wpa;
	
	/// 键盘消息键值
	unsigned long lpa;
	
} KEYBOARD_DATA;


/// 创建鼠标设备
/// 
/// \param 无
/// \retval <0 创建失败
/// \retval 0 创建成功
int KeyboardCreate(void);


/// 销毁鼠标设备
/// 
/// \param 无
/// \retval <0 销毁失败
/// \retval 0 销毁成功
int KeyboardDestory(void);


/// 一直等到读到一个完整的键盘事件才返回，否则阻塞。如果键盘外设被拔掉或不存在，
/// 立即返回错误。出错时应用程序需要定时重试，周期不小于500ms，以实现热插拔功能。
/// 
/// \param [out] pData 指向键盘事件结构KEYBOARD_DATA的指针。
/// \param [in/out] iMax 输入最大存放消息的数量，读取到的消息数量
/// \retval 0 读成功
/// \retval <0 读失败
int KeyboardGetData(KEYBOARD_DATA * pData, int *iMax);


/// 写入键盘数据
/// \param [in] pData 指向键盘事件结构KEYBOARD_DATA的指针
/// \retval 0 写成功
/// \retval <0 写失败 
int KeyboardSetData(const KEYBOARD_DATA *pData);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
