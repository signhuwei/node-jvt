/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_VendorConnParam.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-26
 * Description   :  设备厂商的连接参数打包和解析模块
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_VENDORCONNPARAM_H
#define __NPC_MPI_MON_VENDORCONNPARAM_H

#include "NPC_TypeDef.h"
#include "NPC_MPI_MON_DataDef.h"


//--------------------通用连接参数设置和获取----------------------------------------------------------
//设置通用连接参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_General_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		NPC_INT								in_iVendorId,				//厂商ID
	IN		PNPC_CHAR							in_pDevIpAddr,				//设备IP地址
	IN		NPC_USHORT							in_usDevPort,				//设备端口号
	IN		PNPC_CHAR							in_pUserName,				//设备用户名
	IN		PNPC_CHAR							in_pUserPwd,				//设备登录密码
	IN		NPC_INT								in_iChNo					//设备通道号或ID号
	);

//获取通用连接参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_General_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_INT							out_pVendorId,				//厂商ID
	OUT		PNPC_CHAR							out_pDevAddr,				//设备地址
	IN		NPC_INT								in_iDevAddrBufSize,			//设备地址缓冲区大小
	OUT		PNPC_USHORT							out_pDevPort,				//设备端口号
	OUT		PNPC_CHAR							out_pUserName,				//设备用户名
	IN		NPC_INT								in_iUserNameBufSize,		//设备用户名缓冲区大小
	OUT		PNPC_CHAR							out_pUserPwd,				//设备登录密码
	IN		NPC_INT								in_iUserPwdBufSize,			//设备登录密码缓冲区大小
	OUT		PNPC_INT							out_pChNo					//设备通道号或ID号
	);


//--------------------通用连接参数设置和获取（扩展）----------------------------------------------------------
//设置通用连接参数（扩展）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_General_SetConnParamEx(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		NPC_INT								in_iVendorId,				//厂商ID
	IN		PNPC_CHAR							in_pDevIpAddr,				//设备IP地址
	IN		NPC_USHORT							in_usDevPort,				//设备端口号
	IN		PNPC_CHAR							in_pUserName,				//设备用户名
	IN		PNPC_CHAR							in_pUserPwd,				//设备登录密码
	IN		NPC_INT								in_iChNo,					//设备通道号或ID号
	IN		NPC_INT								in_iStreamNo				//设备码流号，0：主码流，1：子码流
	);

//获取通用连接参数（扩展）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_General_GetConnParamEx(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_INT							out_pVendorId,				//厂商ID
	OUT		PNPC_CHAR							out_pDevAddr,				//设备地址
	IN		NPC_INT								in_iDevAddrBufSize,			//设备地址缓冲区大小
	OUT		PNPC_USHORT							out_pDevPort,				//设备端口号
	OUT		PNPC_CHAR							out_pUserName,				//设备用户名
	IN		NPC_INT								in_iUserNameBufSize,		//设备用户名缓冲区大小
	OUT		PNPC_CHAR							out_pUserPwd,				//设备登录密码
	IN		NPC_INT								in_iUserPwdBufSize,			//设备登录密码缓冲区大小
	OUT		PNPC_INT							out_pChNo,					//设备通道号或ID号
	OUT		PNPC_INT							out_pStreamNo				//设备码流号，0：主码流，1：子码流
	);


//--------------------通用P2P连接参数设置和获取----------------------------------------------------------
//设置通用P2P连接参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_P2PGeneral_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		NPC_INT								in_iVendorId,				//厂商ID
	IN		PNPC_CHAR							in_pNetAgentDevId,			//网络代理设备ID
	IN		PNPC_CHAR							in_pDevIpAddr,				//设备IP地址
	IN		NPC_USHORT							in_usDevPort,				//设备端口号
	IN		PNPC_CHAR							in_pUserName,				//设备用户名
	IN		PNPC_CHAR							in_pUserPwd,				//设备登录密码
	IN		NPC_INT								in_iChNo,					//设备通道号或ID号
	IN		NPC_INT								in_iSubStream				//子码流号，0：主码流，1：子码流1。。。
	);

//获取通用P2P连接参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_P2PGeneral_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_INT							out_pVendorId,				//厂商ID
	OUT		PNPC_CHAR							out_pNetAgentDevId,			//网络代理设备ID
	IN		NPC_INT								in_iNetAgentDevIdBufSize,	//网络代理设备ID缓冲区大小
	OUT		PNPC_CHAR							out_pDevAddr,				//设备地址（域名或IP地址）
	IN		NPC_INT								in_iDevAddrBufSize,			//设备地址缓冲区大小
	OUT		PNPC_USHORT							out_pDevPort,				//设备端口号
	OUT		PNPC_CHAR							out_pUserName,				//设备用户名
	IN		NPC_INT								in_iUserNameBufSize,		//设备用户名缓冲区大小
	OUT		PNPC_CHAR							out_pUserPwd,				//设备登录密码
	IN		NPC_INT								in_iUserPwdBufSize,			//设备登录密码缓冲区大小
	OUT		PNPC_INT							out_pChNo,					//设备通道号或ID号
	OUT		PNPC_INT							out_pSubStream				//子码流号，0：主码流，1：子码流1。。。
	);


//------------------------------------------------------------------------------
//设置连接参数：华科流媒体服务器协议（HKSP）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HKSP_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pSrvIpAddr,				//流媒体服务器IP地址
	IN		NPC_USHORT							in_usSrvPort,				//流媒体服务器端口号
	IN		PNPC_CHAR							in_pUserName,				//流媒体服务器用户名
	IN		PNPC_CHAR							in_pUserPwd,				//流媒体服务器登录密码
	IN		NPC_INT								in_iACQID					//摄像机的ACQID
	);

//获取连接参数：华科流媒体服务器协议（HKSP）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HKSP_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pSrvIpAddr,				//流媒体服务器IP地址
	IN		NPC_INT								in_iSrvIpAddrBufSize,		//流媒体服务器IP地址缓冲区大小
	OUT		PNPC_USHORT							out_pSrvPort,				//流媒体服务器端口号
	OUT		PNPC_CHAR							out_pUserName,				//流媒体服务器用户名
	IN		NPC_INT								in_iUserNameBufSize,		//流媒体服务器用户名缓冲区大小
	OUT		PNPC_CHAR							out_pUserPwd,				//流媒体服务器登录密码
	IN		NPC_INT								in_iUserPwdBufSize,			//流媒体服务器登录密码缓冲区大小
	OUT		PNPC_INT							out_pACQID					//摄像机的ACQID
	);


//------------------------------------------------------------------------------
//设置连接参数：成都索贝（CDSB）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_CDSB_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pSrvIpAddr,				//索贝流媒体服务器IP地址
	IN		NPC_USHORT							in_usSrvPort,				//索贝流媒体服务器端口号
	IN		PNPC_CHAR							in_pUserName,				//索贝流媒体服务器用户名
	IN		PNPC_CHAR							in_pUserPwd,				//索贝流媒体服务器登录密码
	IN		NPC_INT								in_iDevId					//设备ID号
	);

//获取连接参数：成都索贝（CDSB）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_CDSB_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pSrvIpAddr,				//索贝流媒体服务器IP地址
	OUT		PNPC_USHORT							out_pSrvPort,				//索贝流媒体服务器端口号
	OUT		PNPC_CHAR							out_pUserName,				//索贝流媒体服务器用户名
	OUT		PNPC_CHAR							out_pUserPwd,				//索贝流媒体服务器登录密码
	OUT		PNPC_INT							out_pDevId					//设备ID号
	);


//------------------------------------------------------------------------------
//设置连接参数：文件摄像机（FCAM）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_FCAM_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pDirName,				//目录名
	IN		NPC_INT								in_iChNo					//设备通道号
	);

//获取连接参数：文件摄像机（FCAM）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_FCAM_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pDirName,				//目录名
	OUT		PNPC_INT							out_pChNo					//设备通道号
	);


//------------------------------------------------------------------------------
//设置连接参数：华科监控通讯协议（HMCP）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HMCP_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pDevIpAddr,				//设备IP地址或目录名
	IN		NPC_USHORT							in_usDevPort,				//设备端口号
	IN		PNPC_CHAR							in_pUserName,				//设备用户名
	IN		PNPC_CHAR							in_pUserPwd,				//设备登录密码
	IN		NPC_INT								in_iChNo					//设备通道号
	);

//获取连接参数：华科监控通讯协议（HMCP）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HMCP_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pDevIpAddr,				//设备IP地址或目录名
	OUT		PNPC_USHORT							out_pDevPort,				//设备端口号
	OUT		PNPC_CHAR							out_pUserName,				//设备用户名
	OUT		PNPC_CHAR							out_pUserPwd,				//设备登录密码
	OUT		PNPC_INT							out_pChNo					//设备通道号
	);



//------------------------------------------------------------------------------
//设置连接参数：华科流媒体协议（OWSP）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_OWSP_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		NPC_INT								in_iDevId,					//设备ID
	IN		NPC_INT								in_iChNo					//通道号
	);

//获取连接参数：华科流媒体协议（OWSP）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_OWSP_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_INT							out_pDevId,					//设备ID
	OUT		PNPC_INT							out_pChNo					//通道号
	);


//------------------------------------------------------------------------------
//设置连接参数：华科设备上连协议（HDTP）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HDTP_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pDevId,					//设备ID
	IN		PNPC_CHAR							in_pDevPwd,					//设备密码
	IN		NPC_INT								in_iChNo					//通道号
	);

//获取连接参数：华科设备上连协议（HDTP）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HDTP_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pDevId,					//设备ID
	OUT		PNPC_CHAR							out_pDevPwd,				//设备密码
	OUT		PNPC_INT							out_pChNo					//通道号
	);


//------------------------------------------------------------------------------
//设置连接参数：华科设备上连协议（HDTP）（扩展）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HDTP_SetConnParamEx(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pDevId,					//设备ID
	IN		PNPC_CHAR							in_pDevUser,				//设备用户名
	IN		PNPC_CHAR							in_pDevPwd,					//设备密码
	IN		NPC_INT								in_iChNo,					//通道号
	IN		NPC_INT								in_iStreamNo				//码流，0：主码流，1：子码流
	);

//获取连接参数：华科设备上连协议（HDTP）（扩展）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HDTP_GetConnParamEx(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pDevId,					//设备ID
	OUT		PNPC_CHAR							out_pDevUser,				//设备用户名
	OUT		PNPC_CHAR							out_pDevPwd,				//设备密码
	OUT		PNPC_INT							out_pChNo,					//通道号
	OUT		PNPC_INT							out_pStreamNo				//码流，0：主码流，1：子码流
	);


//------------------------------------------------------------------------------
//设置连接参数：上海通立（SHTL）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_SHTL_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pDevIpAddr,				//设备IP地址
	IN		NPC_USHORT							in_usDevPort,				//设备端口号
	IN		PNPC_CHAR							in_pUserName,				//设备用户名
	IN		PNPC_CHAR							in_pUserPwd,				//设备登录密码
	IN		NPC_INT								in_iChNo,					//设备通道号
	IN		PNPC_CHAR							in_pDevId					//设备ID
	);

//获取连接参数：上海通立（SHTL）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_SHTL_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pDevIpAddr,				//设备IP地址
	OUT		PNPC_USHORT							out_pDevPort,				//设备端口号
	OUT		PNPC_CHAR							out_pUserName,				//设备用户名
	OUT		PNPC_CHAR							out_pUserPwd,				//设备登录密码
	OUT		PNPC_INT							out_pChNo,					//设备通道号
	OUT		PNPC_CHAR							out_pDevId					//设备ID
	);


//------------------------------------------------------------------------------
//设置连接参数：杭州海康推模式（HKPU）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HKPU_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pDevId,					//设备ID
	IN		NPC_INT								in_iChNo					//设备通道号
	);

//获取连接参数：杭州海康推模式（HKPU）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_HKPU_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pDevId,					//设备ID
	OUT		PNPC_INT							out_pChNo					//设备通道号
	);


//------------------------------------------------------------------------------
//设置连接参数：P2P端点服务（EPMY）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_EPMY_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pDevId,					//设备ID（设备UMID）
	IN		NPC_INT								in_iIfConnDestAddr,			//是否使用目标地址连接，0：不使用，1：使用
	IN		PNPC_CHAR							in_pDestIpaddr,				//目标IP地址（设备端连接的IP地址），in_iIfConnDestAddr参数为1时有效
	IN		NPC_USHORT							in_usDestPort,				//目标端口号
	IN		NPC_INT								in_iConnDestChNo,			//连接的目标通道号，如果为0，则为缺省通道号，in_iIfConnDestAddr参数为0时有效
	IN		NPC_USHORT							in_usPort					//端口号
	);

//获取连接参数：P2P端点服务（EPMY）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_EPMY_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pDevId,					//设备ID（设备UMID）
	OUT		PNPC_INT							out_pIfConnDestAddr,		//是否使用目标地址连接，0：不使用，1：使用
	OUT		PNPC_CHAR							out_pDestIpaddr,			//目标IP地址（设备端连接的IP地址），in_iIfConnDestAddr参数为1时有效
	OUT		PNPC_USHORT							out_pDestPort,				//目标端口号
	OUT		PNPC_INT							out_pConnDestChNo,			//连接的目标通道号，如果为0，则为缺省通道号，in_iIfConnDestAddr参数为0时有效
	OUT		PNPC_USHORT							out_pPort					//端口号
	);


//------------------------------------------------------------------------------
//设置连接参数：深圳郎驰（序列号）（SZLC）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_SZLC_SetConnParam(
	OUT		PNPC_CHAR							out_pConnParamBuf,			//连接参数缓冲区，缓冲区大小为NPC_D_MON_DEV_CONN_PARAM_BUFSIZE定义大小
	IN		PNPC_CHAR							in_pDevId,					//设备ID
	IN		NPC_INT								in_iChNo					//设备通道号
	);

//获取连接参数：深圳郎驰（序列号）（SZLC）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_VCP_SZLC_GetConnParam(
	IN		PNPC_CHAR							in_pConnParamBuf,			//连接参数缓冲区
	OUT		PNPC_CHAR							out_pDevId,					//设备ID
	OUT		PNPC_INT							out_pChNo					//设备通道号
	);


#endif

