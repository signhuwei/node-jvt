//
//  "$Id: Flash.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_FLASH_H__
#define __PAL_FLASH_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup FLASH API
/// Flash设备访问接口，升级管理器基于此构建
///	\n 调用流程图
/// \code
///    ===========================
///                |
///            FlashInit
///                |
///           FlashGetSectorSize
///                |-------------+
///            FlashRead         |
///            FlashErase        |
///            FlashWrite        |
///                |-------------+
///           FlashGetSectorSize
///                |
///    ===========================
/// \endcode
/// @{

/// \defgroup FlashAPI API Flash
/// Flash直接访问API。有些应用程序升级是使用lua控制的，lua脚本通过直接访问flash，
///	更新映像文件。
/// \note 函数FlashGetSectorSize和FlashGetClientArea暂时未使用。
/// @{

/// 初始化Flash访问
/// \return 0 初始化成功
/// \return < 0初始化失败
int FlashInit(void);

/// 读出Flash上的数据
/// 
/// \param [out] buf 用来接收读出数据的缓冲。
/// \param [in] addr 读出点的扇区偏移。
/// \param [in] cnt 要读出数据的扇区数。
/// \retval 0  读成功
/// \retval <0  读失败
int	FlashRead(unsigned char *buf, unsigned long addr, unsigned long cnt);

/// 擦除Flash上的数据
/// \param [in] addr 擦除设备的地址
/// \return 0 擦除成功
/// \return -1 擦除失败
int	 FlashErase(unsigned long addr);

/// 将数据写入Flash
/// 
/// \param [out] buf 待写入的数据的缓冲。
/// \param [in] addr 写入点的扇区偏移。
/// \param [in] cnt 要写入数据的扇区数。
/// \retval 0  写成功
/// \retval <0  写失败
int	FlashWrite(unsigned char *buf, unsigned long addr, unsigned long cnt);

/// 得到Flash的物理扇区大小。
/// 
/// \param [out] size 一个扇区包含的字节数
/// \retval 0  操作成功
/// \retval <0  操作失败
int FlashGetSectorSize(unsigned long *size);

/// 销毁Flash设备访问
/// \return 0 销毁设备访问成功
/// \return < 0 销毁失败
int FlashDestroy(void);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif //__FLASH_API_H__

