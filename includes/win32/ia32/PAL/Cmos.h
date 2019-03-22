//
//  "$Id: Cmos.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_CMOS_H__
#define __PAL_CMOS_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup CMOSAPI API CMOS
/// CMOS访问API。应用程序使用CMOS来保存访问非常频繁而且实时性较高的数据。
/// 占用32字节, 一般使用RTC芯片的存储区域。
/// @{


/// 从CMOS中读数据。
/// 
/// \param [in] offs 读出点的字节偏移。
/// \param [out] pdat 用来接收读出数据的缓冲。
/// \param [in] len 要读出的字节数。
/// \retval 0  成功
/// \retval <0  失败
int CMOSRead(int offs, void * pdat, int len);


/// 写数据到CMOS。
/// 
/// \param [in] offs 写入点的字节偏移。
/// \param [in] pdat 待写入的数据的缓冲。
/// \param [in] len 要写入的字节数。
/// \retval 0  成功
/// \retval <0  失败
int CMOSWrite(int offs, void * pdat, int len);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
