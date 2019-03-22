//
//  "$Id: Alarm.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_ALARM_H__
#define __PAL_ALARM_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup AlarmAPI API Alarm
/// 报警输入输出端口（串口）的使用，接受外部电平输入或者触发继电器控制外部电路。
///	\n 调用流程图:
/// \code
///    ===========================
///                |
///   *AlarmGetInSlots,AlarmGetOutSlots
///                |
///           AlarmCreate
///                |------------+
///       AlarmRead,AlarmWrite  |
///                |------------+
///           AlarmDestory
///                |
///    ===========================
/// \endcode
/// @{


/// 得到报警端口的输入通道数目。
/// \return 报警端口的输入通道数目
int AlarmGetInSlots(void);

/// 得到报警端口的输出通道数目。
/// \return 报警端口的输出通道数目
int AlarmGetOutSlots(void);

/// 创建报警设备
/// \retval <0 创建失败
/// \retval 0 创建成功
int AlarmCreate(void);

/// 销毁报警设备
/// \retval <0 销毁失败
/// \retval 0 销毁成功
int AlarmDestory(void);

/// 读报警输入状态，状态改变时或出错时返回，否则阻塞。
/// \param [out] pData 指向一个unsigned int值的指针，unsigned int值是各个报警输入通道电平状态的掩码。
///	       低通道在低位，高通道在高位。高电平置1，低电平置0，不存在的通道置0。
/// \retval >0  读出的字节数
/// \retval <=0 读失败
int AlarmRead(unsigned int* pData);

/// 写读取报警输出状态。
/// \param [in] pData 指向一个unsigned int值的指针，unsigned int值是各个报警输出通道的掩码。低通道在
///	       低位，高通道在高位。置1输出高电平，置0输出低电平，不存在的通道位无效。
/// \return >0  写入的字节数
/// \retval <=0 写失败
int AlarmWrite(unsigned int* pData);

/// 复位智能模块
/// \param [out] iValue 高电平置1，低电平置0。
/// \retval <0 复位失败
/// \retval 0 复位成功
int ExDeviceReset(unsigned int iValue);

/// 读取智能模块GPIO端口状态
/// \param [out] pData 指向一个uint值的指针，uint值是各个GPIO端口电平状态的掩码。
///        低通道在低位，高通道在高位。高电平置1，低电平置0，不存在的通道置0。
///        目前4路的设备只有一个GPIO端口，用bit0表示
/// \retval 0  成功
/// \retval <0 读失败
int ExDeviceRead(unsigned int* pData);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif

