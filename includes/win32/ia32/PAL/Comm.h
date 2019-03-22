//
//  "$Id: Comm.h 2431 2011-12-22 07:01:54Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_COMM_H__
#define __PAL_COMM_H__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup CommAPI API Comm
/// 标准的串口通讯接口，支持RS232,RS485,前面板等设备
/// \n 调用流程图:
/// \code
///    =========================================
///                   |                         
///              createCommPort                  
///                   |                         
///                addRef                  
///       +-----------|	          
///       |      setAttribute  	
///       |		      |    	
///       |           |           	 
///       |         open    
///       | +---------|      
///       | |       read    
///       | |       write   
///       | |       purge   
///       | +---------|      	
///       |         close   
///       +-----------|
///                release                  
///                   |                         
///    =========================================
/// \endcode
/// @{

/// 串口操作中断类型
typedef enum CommPurgeFlags
{
	commPurgeTxAbort = 0x0001,	///< 中止写操作
	commPurgeRxAbort = 0x0002,	///< 中止读操作
	commPurgeTxClear = 0x0004,	///< 清空输出缓冲
	commPurgeRxClear = 0x0008 	///< 清空输入缓冲
} CommPurgeFlags;

/// 串口停止位类型
typedef enum CommStopBit
{
	commOneStopBit = 0,		///< 1 stop bit
	commOne5StopBits,		///< 1.5 stop bit
	commTwoStopBits			//< 2 stop bit
} CommStopBit;

/// 串口校验位类型
typedef enum CommParityType 
{
	commNoParity = 0,	///< No parity
	commOddParity,		///< Odd parity
	commEvenParity,		///< Even parity
	commMarkParity,		///< Mark parity
	commSpaceParity		///< Space parity
} CommParityType;

/// 串口模式
typedef enum CommMode
{
	commFullDuplex = 0,	///< 全双工
	commSemiDuplex,		///< 半双工
} CommMode;

/// 串口能力结构，128字节
typedef struct CommCaps
{
	CommMode mode;		///< 工作模式
	int reserved[31];	///< 保留字节
} CommCaps;

/// 串口属性结构，128字节
typedef struct CommAttribute
{
	int		baudrate;	///< 实际的波特率值。		
	char	dataBits;	///< 实际的数据位 取值为5,6,7,8	
	char	parity;		///< 奇偶校验选项，取CommParityType类型的枚举值。	
	char	stopBits;	///< 停止位数，取CommStopBit类型的枚举值。	
	char	resv;		///< 保留字节
	int		reserved[30];///< 保留字节
} CommAttribute;



/// 串口接口描述结构，128字节
typedef struct CommPortDesc
{
	int port;			///< 物理端口号
	int reserved[31];	///< 保留字节
} CommPortDesc;


/// 创建串口接口
///
/// \param [in] desc 串口接口描述结构CommPortDesc指针
/// \param [out] commPort 串口接口指针的指针
/// \retval 0  连接成功。
/// \retval <0  连接失败。


/// 得到串口数目
///
/// \retval 串口数目。
int getCommPortCount();

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
