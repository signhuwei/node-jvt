/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_DevNetPortServer.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-07-18
 * Description   :  设备网络端口映射服务模块
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_DEVNETPORTSERVER_H
#define __NPC_MPI_MON_DEVNETPORTSERVER_H

#include "NPC_TypeDef.h"

//导出导入定义
#ifdef _WIN32
	#ifdef _NPC_MPI_MON_DNP_EXPORTS
		#define NPC_MPI_MON_DNP_API __declspec(dllexport)
	#else
		#ifdef _NPC_MPI_MON_DNP_IMPORT
			#define NPC_MPI_MON_DNP_API __declspec(dllimport)
		#else
			#define NPC_MPI_MON_DNP_API
		#endif
	#endif
#else
	#define NPC_MPI_MON_DNP_API
#endif


// C++ support
#ifdef __cplusplus
extern "C"
{
#endif


//----------------------------------------------------------------------------------------
//创建设备网络端口映射服务
NPC_MPI_MON_DNP_API		NPC_HANDLE	NPC_F_MPI_MON_DNP_CreateDevNetPortServer(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]服务器IP地址或域名
	IN		NPC_USHORT							in_usServerPort,			//[IN]服务器端口号
	IN		PNPC_CHAR							in_pAuthId,					//[IN]认证ID
	IN		PNPC_CHAR							in_pAuthPwd					//[IN]认证密码
	);

//销毁设备网络端口映射服务
NPC_MPI_MON_DNP_API		NPC_VOID	NPC_F_MPI_MON_DNP_DestroyDevNetPortServer(
	IN		NPC_HANDLE							in_hDevNetPort				//[IN]设备网络端口
	);

//添加映射端口，返回值：0：成功，其它失败
//失败码：
//7：等待登录服务器超时
//8：查找空闲TCP监听端口失败
//9：参数错误
//600001：解析连接参数失败
//600002：创建对象失败
//600004：创建映射端口失败
//600009：参数错误
//630001：协议错误或系统调用失败
//630002：连接设备失败
//630004：分配资源失败
//630006：访问服务器失败（访问超时或连接断开或服务器操作失败）
//630009：其它原因失败
//630101：用户名错误
//630102：密码错误
//630104：正在连接服务器
//630105：未连接服务器
//630111：权限不够
//630112：设备离线
NPC_MPI_MON_DNP_API		NPC_INT		NPC_F_MPI_MON_DNP_AddPort(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]设备网络端口
	IN		PNPC_CHAR							in_pUmid,					//[IN]UMID
	INOUT	PNPC_USHORT							inout_pLocalPort,			//[INOUT]本地端口号，如果值为0，则由系统分配端口号
	IN		NPC_INT								in_iTimeout=20000			//[IN]超时时长（毫秒）
	);

//添加映射端口（连接目标地址），返回值：0：成功，其它失败
//失败码：
//7：等待登录服务器超时
//8：查找空闲TCP监听端口失败
//9：参数错误
//600001：解析连接参数失败
//600002：创建对象失败
//600004：创建映射端口失败
//600009：参数错误
//630001：协议错误或系统调用失败
//630002：连接设备失败
//630004：分配资源失败
//630006：访问服务器失败（访问超时或连接断开或服务器操作失败）
//630009：其它原因失败
//630101：用户名错误
//630102：密码错误
//630104：正在连接服务器
//630105：未连接服务器
//630111：权限不够
//630112：设备离线
NPC_MPI_MON_DNP_API		NPC_INT		NPC_F_MPI_MON_DNP_AddPortByDestAddr(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]设备网络端口
	IN		PNPC_CHAR							in_pUmid,					//[IN]UMID
	IN		PNPC_CHAR							in_pDestIpaddr,				//[IN]目标IP地址（设备端连接的IP地址）
	IN		NPC_USHORT							in_usDestPort,				//[IN]目标端口号
	INOUT	PNPC_USHORT							inout_pLocalPort,			//[INOUT]本地端口号，如果值为0，则由系统分配端口号
	IN		NPC_INT								in_iTimeout=20000			//[IN]超时时长（毫秒）
	);

//添加映射端口（连接指定通道），返回值：0：成功，其它失败
//失败码：
//7：等待登录服务器超时
//8：查找空闲TCP监听端口失败
//9：参数错误
//600001：解析连接参数失败
//600002：创建对象失败
//600004：创建映射端口失败
//600009：参数错误
//630001：协议错误或系统调用失败
//630002：连接设备失败
//630004：分配资源失败
//630006：访问服务器失败（访问超时或连接断开或服务器操作失败）
//630009：其它原因失败
//630101：用户名错误
//630102：密码错误
//630104：正在连接服务器
//630105：未连接服务器
//630111：权限不够
//630112：设备离线
NPC_MPI_MON_DNP_API		NPC_INT		NPC_F_MPI_MON_DNP_AddPortByChNo(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]设备网络端口
	IN		PNPC_CHAR							in_pUmid,					//[IN]UMID
	IN		NPC_INT								in_iDestChNo,				//[IN]目标通道号，0为缺省通道号
	INOUT	PNPC_USHORT							inout_pLocalPort,			//[INOUT]本地端口号，如果值为0，则由系统分配端口号
	IN		NPC_INT								in_iTimeout=20000			//[IN]超时时长（毫秒）
	);

//删除映射端口
NPC_MPI_MON_DNP_API		NPC_VOID	NPC_F_MPI_MON_DNP_DelPort(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]设备网络端口
	IN		NPC_USHORT							in_usLocalPort				//[IN]本地端口号
	);


//----------------------------------------------------------------------------------------
//检测服务器连接状态，返回：0：未连接，1：正在连接，2：已连接，返回9表示错误
NPC_MPI_MON_DNP_API		NPC_INT		NPC_F_MPI_MON_DNP_CheckSrvConnState(
	IN		NPC_HANDLE							in_hDevNetPort				//[IN]设备网络端口
	);


//----------------------------------------------------------------------------------------
//清除设备状态查询列表
NPC_MPI_MON_DNP_API		NPC_VOID	NPC_F_MPI_MON_DNP_DevState_ClearList(
	IN		NPC_HANDLE							in_hDevNetPort				//[IN]设备网络端口
	);

//添加查询设备
NPC_MPI_MON_DNP_API		NPC_BOOL	NPC_F_MPI_MON_DNP_DevState_AddDev(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]设备网络端口
	IN		PNPC_CHAR							in_pDevUmid					//[IN]设备UMID
	);

//请求查询设备状态（请采用批量查询设备状态，减小服务器查询负荷）
NPC_MPI_MON_DNP_API		NPC_BOOL	NPC_F_MPI_MON_DNP_DevState_RequQueryDevState(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]设备网络端口
	OUT		PNPC_INT							out_pQueryDevSpaceTime,		//[OUT]查询设备状态的间隔时间（秒）
	IN		NPC_INT								in_iTimeout					//[IN]超时时长（毫秒）
	);

//获取设备状态（在查询列表中获取状态）
NPC_MPI_MON_DNP_API		NPC_BOOL	NPC_F_MPI_MON_DNP_DevState_GetDevState(
	IN		NPC_HANDLE							in_hDevNetPort,				//[IN]设备网络端口
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]设备UMID
	OUT		PNPC_INT							out_pDevState				//[OUT]设备状态，0：离线，1：在线
	);


//----------------------------------------------------------------------------------------
//获取日志或调试信息，底层维护一个日志队列，将产生的日志保存入该队列中，调用该函数将从该队列取出日志数，调用函数将删除队列的数据；
//如果长时间不调用，底层将删除最早的日志，默认最大保存100条日志
NPC_MPI_MON_DNP_API		NPC_BOOL	NPC_F_MPI_MON_DNP_GetLogData(
	IN		NPC_INT								in_iLogBufSize,				//[IN]日志信息缓冲区大小
	OUT		PNPC_INT							out_pLogInfoType,			//[OUT]日志类型，参见NPC_D_MON_LOG_INFO_TYPE_*定义
	OUT		PNPC_CHAR							out_pLogBuf,				//[OUT]日志信息缓冲区，调用者分配内存
	IN		NPC_INT								in_iTimeout					//[IN]超时时长（毫秒）
	);


// C++ support
#ifdef __cplusplus
}
#endif

#endif
