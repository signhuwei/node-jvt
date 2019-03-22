//
//  "$Id: Frontboard.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_FRONTBOARD_H__
#define __PAL_FRONTBOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup FrontboardAPI API Frontboard
/// 前面板访问API。用于和各种前面板物理设备通讯，获取键值或发送指示灯控制命令。
/// 接在USB接口上的标准104（或其他）键盘键值转换后也可以通过这个接口返回上来。
/// \n 调用流程图:
/// \code
///    =========================================
///                   |                         
///              FrontboardCreate                  
///         +---------|      
///         |    FrontboardRead    
///         |    FrontboardWrite   
///         +---------|      	
///             FrontboardDestory                  
///                   |                         
///    =========================================
/// \endcode
/// @{


/// 创建前面板设备
/// 
/// \param 无
/// \retval <0 创建失败
/// \retval 0 创建成功
int FrontboardCreate(void);


/// 销毁前面板设备
/// 
/// \param 无
/// \retval <0 销毁失败
/// \retval 0 销毁成功
int FrontboardDestory(void);


/// 读前面板数据，一直等到读出指定的字节或出错时才返回，否则阻塞。
/// 
/// \param [out] pData 数据缓冲的指针。
/// \param [in] nBytes 要读出的字节数
/// \return>0  读出的字节数
/// \retval <=0 读失败
int FrontboardRead(void* pData, unsigned int nBytes);


/// 写前面板数据，一直等到写入指定的字节或出错时才返回，否则阻塞。
/// 
/// \param [in] pData 数据缓冲的指针。
/// \param [in] nBytes 要写入的字节数
/// \return>0  写入的字节数
/// \retval <=0  写失败
int FrontboardWrite(void* pData, unsigned int nBytes);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
