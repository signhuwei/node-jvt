//
//  "$Id: Ptz.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_PTZ_H__
#define __PAL_PTZ_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup PTZAPI API PTZ
/// 云台设备通讯接口。
/// \n 调用流程图:
/// \code
///    =========================================
///                   |                         
///              PtzCreate                  
///       +-----------|	          
///       |     PtzSetAttribute  	
///       |           |           	 
///       |      PtzOpen    
///       | +---------|      
///       | |    PtzRead    
///       | |    PtzWrite   
///       | +---------|      	
///       |      PtzClose   
///       +-----------|
///             PtzDestory                  
///                   |                         
///    =========================================
/// \endcode
/// @{

/// 云台设备属性
typedef struct PTZ_ATTR
 {
	unsigned int	baudrate;		
	unsigned char	databits;
	unsigned char	parity;
	unsigned char	stopbits;	
	unsigned char	reserved;
} PTZ_ATTR;


/// 创建云台设备
/// 
/// \param	无
/// \retval <0 创建失败
/// \retval 0 创建成功
int PtzCreate(void);


/// 销毁云台设备
/// 
/// \param 无
/// \retval <0 销毁失败
/// \retval 0 销毁成功
int PtzDestory(void);

	
/// 打开云台设备。
/// 
/// \param 无
/// \retval 0  打开成功
/// \retval <0  打开失败
int PtzOpen(void);


/// 设置云台设备属性。
/// 
/// \param [in] pattr 云台属性结构PTZ_ATTR指针。
/// \retval 0  设置成功
/// \retval <0  设置失败
int PtzSetAttribute(PTZ_ATTR *pattr);


/// 关闭云台设备，当前读写操作立即返回。
/// 
/// \param 无
/// \retval 0  关闭成功
/// \retval <0  关闭失败
int PtzClose(void);


/// 写云台控制命令，一直等到写入指定的字节或出错时才返回，否则阻塞。
/// 
/// \param [in] pData 数据缓冲的指针。
/// \param [in] len 要写入的字节数
/// \retval >0  写入的字节数
/// \retval <=0 写失败
int PtzWrite(void* pData, unsigned int len);


/// 读云台数据，一直等到读到指定的字节或出错时才返回，否则阻塞。
/// 
/// \param [in] pData 数据缓冲的指针。
/// \param [in] len 要读出的字节数
/// \return >0  读出的字节数
/// \retval <=0 读失败
int PtzRead(void* pData, unsigned int len);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
