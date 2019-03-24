/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_Client.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-08
 * Description   :  监控客户端通讯接口定义，该接口为客户端与服务器和设备提供通讯功能
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_CLIENT_H
#define __NPC_MPI_MON_CLIENT_H

#include "NPC_TypeDef.h"
#include "NPC_MPI_MON_DataDef.h"
#include "NPC_MPI_MON_Camera.h"


// C++ support
#ifdef __cplusplus
extern "C"
{
#endif


//----------------------------------------------------------------------------------------
//创建摄像机对象
NPC_MPI_MON_API	NPC_I_MPI_MON_Camera*	NPC_F_MPI_MON_CreateCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId					//[IN]设备ID
	);

//创建配置摄像机对象
NPC_MPI_MON_API	NPC_I_MPI_MON_Camera*	NPC_F_MPI_MON_CreateCfgCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwVendorId,				//[IN]设备厂商
	IN		PNPC_CHAR							in_pUmid,					//[IN]UMID
	IN		PNPC_CHAR							in_pDevUserName,			//[IN]设备用户名
	IN		PNPC_CHAR							in_pDevPwd					//[IN]设备密码
	);

//销毁摄像机对象
NPC_MPI_MON_API	NPC_VOID	NPC_F_MPI_MON_DestroyCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_I_MPI_MON_Camera*				in_pCamera					//[IN]摄像机指针
	);


//底层版本信息
NPC_MPI_MON_API		NPC_CHAR	*NPC_F_MPI_MON_CLT_VERSION();
    //----------------------------------------------------------------------------------------
//初始化客户端环境
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_InitClientEnv();
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_InitClientLog(IN NPC_BOOL IfShowLog);

//反初始化客户端环境
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_UninitClientEnv();

//启动客户端模块
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_StartClient(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]服务器IP地址或域名
	IN		NPC_USHORT							in_usServerPort				//[IN]服务器端口号
	);

    
//启动客户端模块（扩展）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_StartClientEx(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]服务器IP地址或域名
	IN		NPC_USHORT							in_usServerPort,			//[IN]服务器端口号
	IN		NPC_INT								in_iSaveMode=0				//[IN]保存模式，0：服务器，1：本地
	);

//停止客户端模块
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_StopClient();

//设置网络状态
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetNetState(
	IN		NPC_INT								in_iNetConnState			//[IN]网络连接状态，0：断开状态，1：连接状态
	);

//设置客户标识
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetClientFlag(
	IN		NPC_INT								in_iClientFlag				//[IN]客户标识，参见NPC_D_MON_CLIENT_FLAG_*定义
	);

//设置是否采用连接指定地址的服务器，不需要分析服务器，缺省为FALSE，即需要分析服务器
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetConnectSpecServer(
	IN		NPC_BOOL							in_bIfConnSpecSrv			//[IN]是否连接指定服务器
	);

#ifdef _WIN32
//UTF8到GB2312的转换
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CHARSET_Utf8ToGb2312(
	IN		PNPC_CHAR							in_pUtf8Buf,				//[IN]UTF8编码数据缓冲区
	IN		NPC_INT								in_iGb2312BufSize,			//[IN]GB2312数据缓冲区大小
	OUT		PNPC_CHAR							out_pGb2312Buf				//[OUT]GB2312数据缓冲区
	);

//GB2312到UTF8的转换
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CHARSET_Gb2312ToUtf8(
	IN		PNPC_CHAR							in_pGb2312Buf,				//[IN]GB2312数据缓冲区
	IN		NPC_INT								in_iUtf8BufSize,			//[IN]UTF8数据缓冲区大小
	OUT		PNPC_CHAR							out_pUtf8Buf				//[OUT]UTF8数据缓冲区
	);
#endif


//----------------------------------------------------------------------------------------

//创建监控客户端
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_CreateClient(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]服务器IP地址或域名
	IN		NPC_USHORT							in_usServerPort,			//[IN]服务器端口号，如8300
	IN		NPC_INT								in_iSaveMode=0				//[IN]保存模式，0：服务器，1：本地
	);

//销毁监控客户端对象
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DestroyClient(
	IN		NPC_HANDLE							in_hMonClient				//[IN]客户端句柄
	);

//设置设备厂商标识及客户端定制标识
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetVendorClientFlag(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevVendorFlag,			//[IN]设备厂商标识
	IN		PNPC_CHAR							in_pClientCustomFlag		//[IN]客户端定制标识
	);

//连接服务器
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ConnectServer(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iTimeout=4000			//[IN]连接服务器的超时时长（毫秒）
	);

//断开服务器连接
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DisconnectServer(
	IN		NPC_HANDLE							in_hMonClient				//[IN]客户端句柄
	);

//设置字符集
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetCharset(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iCharset					//[IN]字符集，参见NPC_D_MON_CHARSET_*定义
	);

//启动日志网络服务
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_StartLogNetServer(
	IN		NPC_USHORT							in_usLogListenPort			//[IN]日志监听端口号
	);

//停止日志网络服务
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_StopLogNetServer();

//启动日志上传服务
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_StartLogUpServer(
	IN		PNPC_CHAR							in_pLogName,				//[IN]日志名称
	IN		PNPC_CHAR							in_pLogObjId,				//[IN]日志对象ID
	IN		PNPC_CHAR							in_pLogServerAddr,			//[IN]日志服务器IP地址或域名
	IN		NPC_USHORT							in_usLogServerPort			//[IN]日志服务器端口号
	);

//停止日志上传服务
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_StopLogUpServer();

//设置返回结果消息语言种类，缺省为中文
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetMsgLanguage(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iMsgLanguage				//[IN]消息语言种类型，0：中文，1：英文
	);

//设置等待应答消息的超时值，缺省为20000毫秒
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetWaitRespTimeout(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iWaitRespTimeout			//[IN]等待应答消息的超时值（毫秒）
	);

//设置摄像机等待媒体流的超时时长，缺省为20秒
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetWaitMediaStreamTimeout(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iWaitTimeout				//[IN]等待超时值（秒）
	);

//设置检测直连设备是否在线的间隔时间，缺省为30秒，可设置的值范围为5~3600秒
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetCheckDevStateIntervalTime(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iIntervalTime			//[IN]检测间隔时间（秒）
	);


//----------------------------------------------------------------------------------------
//获取客户端配置参数表
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetClientConfigTable(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	OUT		PNPC_INT							out_pCfgParamNum,			//[OUT]客户端配置参数数
	OUT		PNPC_S_MPI_MON_CLIENT_CONFIG_DATA*	out_ppClientCfgParamTable	//[OUT]客户端配置参数表，由底层分配内存，调用者使用完后须调用NPC_F_MPI_MON_CLT_ReleaseClientConfigTable函数释放内存
	);

//释放客户端配置参数表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ReleaseClientConfigTable(
	IN		PNPC_S_MPI_MON_CLIENT_CONFIG_DATA	in_pClientCfgParamTable		//[IN]客户端配置参数表
	);

//查询最新版本
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetNewVerInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iClientType,				//[IN]客户端类型，参见NPC_D_MON_CLIENT_TYPE_定义
	IN		PNPC_CHAR							in_pClientCustomFlag,		//[IN]客户端定制标识
	IN		PNPC_CHAR							in_pCurVerNo,				//[IN]当前版本号，格式为：vA.B.C.D
	OUT		PNPC_CHAR							out_pNewVerNo,				//[OUT]新版本号
	OUT		PNPC_INT							out_pUpRequire,				//[OUT]升级要求，0：无新版本，1：有新版本但可以不升级，2：有新版本必须升级才可以使用
	OUT		PNPC_CHAR							out_pFileName,				//[OUT]升级安装文件名
	OUT		PNPC_INT							out_pFileSize,				//[OUT]升级文件大小（KB）
	OUT		PNPC_CHAR							out_pUpPromptMsg,			//[OUT]升级提示消息
	OUT		PNPC_CHAR							out_pUpDownLinkAddr			//[OUT]升级软件下载地址
	);

//获取存储服务器地址，返回TRUE表示已经获取到，FALSE表示未获取到
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetStorageSrvAddr(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	OUT		PNPC_S_MPI_MON_STORAGE_SRV_ADDR		out_pStorageSrvAddr			//[OUT]存储服务器地址
	);


//----------------------------------------------------------------------------------------
//获取最后的错误信息，返回错误码，返回值为0表示成功，其它为失败
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetLastError(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iErrorBufSize,			//[IN]错误信息缓冲区大小
	OUT		PNPC_CHAR							out_pErrorBuf				//[OUT]错误信息缓冲区，调用者分配内存，如果为NULL，则不返回错误信息
	);

//获取最后的错误信息，返回错误码，返回值为0表示成功，其它为失败
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetLastErrorEx(
	IN		NPC_INT								in_iErrorBufSize,			//[IN]错误信息缓冲区大小
	OUT		PNPC_CHAR							out_pErrorBuf				//[OUT]错误信息缓冲区，调用者分配内存，如果为NULL，则不返回错误信息
	);

//获取日志或调试信息，底层维护一个日志队列，将产生的日志保存入该队列中，调用该函数将从该队列取出日志数，调用函数将删除队列的数据；
//如果长时间不调用，底层将删除最早的日志，默认最大保存100条日志
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetLogData(
	IN		NPC_INT								in_iLogBufSize,				//[IN]日志信息缓冲区大小
	OUT		PNPC_INT							out_pLogInfoType,			//[OUT]日志类型，参见NPC_D_MON_LOG_INFO_TYPE_*定义
	OUT		PNPC_CHAR							out_pLogBuf,				//[OUT]日志信息缓冲区，调用者分配内存
	IN		NPC_INT								in_iTimeout					//[IN]超时时长（毫秒）
	);

//获取日志通知事件句柄，当有日志产生时，该事件有信号
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_GetLogNotifyEvent();

//设置是否写日志信息到文件
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetIfWriteLogToFile(
	IN		NPC_BOOL							in_bIfWriteLogToFile		//[IN]是否写日志到文件
	);

//设置日志文件目录
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetLogDir(
	IN		PNPC_CHAR							in_pLogDir					//[IN]日志目录
	);

//修改日志队列大小
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetLogQueueSize(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iQueueSize				//[IN]队列大小
	);

//设置调试开关，开启调试，则底层将产生跟踪信息，并保存在日志队列中
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetDebugFlag(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_BOOL							in_bEnableDebug				//[IN]使能调度，TRUE表示开启，FALSE表示关闭
	);

//获取客户端状态，状态值参见NPC_D_MPI_MON_CLIENT_CONN_STATE_*定义
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetClientState(
	IN		NPC_HANDLE							in_hMonClient				//[IN]客户端句柄
	);

//获取客户端断开原因，原因值参见NPC_D_MPI_MON_CLIENT_DISCAUSE_定义
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetClientDiscause(
	IN		NPC_HANDLE							in_hMonClient				//[IN]客户端句柄
	);

//查询P2P服务器连接状态，0：未连接，1：正在连接，2：已连接
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_QueryP2pServerConnState(
	IN		NPC_HANDLE							in_hMonClient				//[IN]客户端句柄
	);


//----------------------------------------------------------------------------------------
//注册帐号
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Register(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID，即用户帐号
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]用户密码
	IN		PNPC_CHAR							in_pClientId				//[IN]客户端ID（或客户端标识，如IMSI等）
	);

//注销帐号
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Unregister(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID，即用户帐号
	IN		PNPC_CHAR							in_pUserPwd					//[IN]用户密码
	);

//请求发送短信验证码，可能的失败码如下：
//NPC_D_MPI_MON_ERROR_SYS_ERROR
//NPC_D_MPI_MON_ERROR_DBACCESS_FAIL
//NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_NOPERM
//NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_ATBLACK
//NPC_D_MPI_MON_ERROR_ACCOUNT_EXIST
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RequestSendSecurityCode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pMobilePhone,			//[IN]接收验证码的手机号码
	OUT		PNPC_DWORD							out_pCheckId				//[OUT]验证码检测ID（非验证码），用于注册时使用，该ID有效期为10分钟（可配置）
	);

//注册帐号（带验证码），可能的失败码如下：
//NPC_D_MPI_MON_ERROR_SYS_ERROR
//NPC_D_MPI_MON_ERROR_DBACCESS_FAIL
//NPC_D_MPI_MON_ERROR_SECCODE_HAVE_EXPIRED
//NPC_D_MPI_MON_ERROR_SECCODE_ERROR
//NPC_D_MPI_MON_ERROR_ACCOUNT_EXIST
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RegisterBySecurityCode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwCheckId,				//[IN]验证码检测ID（非验证码），由NPC_F_MPI_MON_CLT_RequestSendSecurityCode函数获取到的验证码检测ID
	IN		PNPC_CHAR							in_pSecurityCode,			//[IN]验证码（手机接收到的验证码）
	INOUT	PNPC_CHAR							inout_pUserId,				//[INOUT]用户ID，即用户帐号，如果字符串为空，则由服务器分配帐号并返回，如果非空，则采用该字段串为帐号
	INOUT	PNPC_CHAR							inout_pUserPwd,				//[INOUT]用户密码，如果字符串为空，则由服务器随机分配密码并返回，如果非空，则密码设置该字符串
	IN		PNPC_CHAR							in_pClientId				//[IN]客户端ID（或客户端标识，如IMSI等）
	);


//----------------------------------------------------------------------------------------
//请求分配用户ID
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RequestAllocUserId(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pClientId,				//[IN]客户端ID（或客户端标识，如IMSI等），同一个客户端ID，在一段时间内分配的用户ID相同。
	OUT		PNPC_CHAR							out_pUserId					//[OUT]用户ID
	);

//注册帐号（扩展2，无须邮箱激活）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RegisterAccountByNoActive(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pClientId,				//[IN]客户端ID（或客户端标识，如IMSI等）
	IN		NPC_INT								in_iClientType,				//[IN]客户端类型，参见NPC_D_MON_CLIENT_TYPE_*定义
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID，即用户帐号
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]用户密码
	IN		PNPC_CHAR							in_pFindPwdEmail,			//[IN]找回密码邮箱
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户姓名
	IN		PNPC_CHAR							in_pLinkTelno				//[IN]联系电话
	);

//注册帐号（扩展2，无须邮箱激活）（V2）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RegisterAccountByNoActive_V2(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pClientId,				//[IN]客户端ID（或客户端标识，如IMSI等）
	IN		NPC_INT								in_iClientType,				//[IN]客户端类型，参见NPC_D_MON_CLIENT_TYPE_*定义
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID，即用户帐号
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]用户密码
	IN		PNPC_CHAR							in_pFindPwdEmail,			//[IN]找回密码邮箱
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户姓名
	IN		PNPC_CHAR							in_pLinkTelno,				//[IN]联系电话
	IN		PNPC_CHAR							in_pIdentityCard			//[IN]身份证
	);

//查询注册帐号的邮箱，即注册时接收验证码的邮箱
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryRegEmail(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID
	OUT		PNPC_CHAR							out_pRegEmail				//[OUT]注册邮箱
	);

//发送重置密码邮件
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SendResetPasswordEmail(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId					//[IN]用户ID
	);

//获取绑定登录用户（即只允许绑定的用户登录）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetBindLoginUser(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	OUT		PNPC_BOOL							out_pIfBindLogin			//[OUT]是否绑定登录（即只允许绑定的用户登录）
	);

//设置绑定登录用户（即只允许绑定的用户登录）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetBindLoginUser(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_BOOL							in_bIfBindLogin				//[IN]是否绑定登录（即只允许绑定的用户登录）
	);

//获取设备限制添加权限（即是否允许其它用户添加设备）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetDevLimitAddPop(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即摄像机ID
	OUT		PNPC_BOOL							out_pIfDevReg,				//[OUT]设备是否注册到服务器
	OUT		PNPC_BOOL							out_pIfP2pDev,				//[OUT]是否为P2P设备，必须为P2P设备才有限制功能
	OUT		PNPC_BOOL							out_pIfLimitAddPop			//[OUT]是否限制添加，TRUE表示不允许其它用户添加，FALSE表示其它用户可以添加
	);

//设置设备限制添加权限（即是否允许其它用户添加设备）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetDevLimitAddPop(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即摄像机ID
	IN		NPC_BOOL							in_bIfLimitAddPop			//[IN]是否限制添加，TRUE表示不允许其它用户添加，FALSE表示其它用户可以添加
	);

NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_LocalDeviceList(
    IN		NPC_HANDLE							in_hMonClient,				//客户端句柄
    IN		PNPC_CHAR							in_pUserId					//用户ID，即用户帐号
    );
//----------------------------------------------------------------------------------------
//客户端登录，返回TRUE表示登录成功，FALSE表示登录失败，NPC_F_MPI_MON_CLT_GetLastError可获取错误码，可能的错误码如下：
//NPC_D_MPI_MON_ERROR_USERID_ERROR
//NPC_D_MPI_MON_ERROR_USERPWD_ERROR
//NPC_D_MPI_MON_ERROR_USER_PWD_ERROR
//NPC_D_MPI_MON_ERROR_ACCOUNT_HAVE_EXPIRED
//NPC_D_MPI_MON_ERROR_ACCOUNT_NO_ACTIVE
//NPC_D_MPI_MON_ERROR_ACCOUNT_DEBT_STOP
//NPC_D_MPI_MON_ERROR_IPADDR_BAN_LOGIN
//NPC_D_MPI_MON_ERROR_EXEC_ORDER_RET_FAIL
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_LoginEx(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID，即用户帐号
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]用户密码
	IN		PNPC_CHAR							in_pClientId,				//[IN]客户端ID（或客户端标识，如IMSI等）
	IN		PNPC_S_MPI_MON_USER_LOGIN_PR_IN_PARAM	in_pPrInParam,			//[IN]登录附带参数
	OUT		PNPC_S_MPI_MON_USER_LOGIN_PR_OUT_PARAM	out_pPrOutParam			//[OUT]登录返回参数
	);

//客户端注销
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_Logout(
	IN		NPC_HANDLE							in_hMonClient				//[IN]客户端句柄
	);

//获取当前登录状态  
//<0：获取出错  
//0：初始状态
//1：内部状态
//2：正在连接状态
//3：正在登录状态
//4：登录成功状态
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetLoginStatus(
	IN		NPC_HANDLE							in_hMonClient				//客户端句柄
	);

//更新客户端信息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_UpdateClientInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iClientType,				//[IN]客户端类型，0：PC，1：手机或平板
	IN		PNPC_CHAR							in_pDevVendorName,			//[IN]设备厂商名称
	IN		PNPC_CHAR							in_pDevName,				//[IN]设备产品名称
	IN		PNPC_CHAR							in_pDevModel,				//[IN]设备型号
	IN		PNPC_CHAR							in_pDevVersion,				//[IN]设备版本号
	IN		PNPC_CHAR							in_pDevCPUModel,			//[IN]设备CPU型号
	IN		NPC_DWORD							in_dwDevMemorySize,			//[IN]设备内存大小（MB）
	IN		NPC_DWORD							in_dwDevStorageSize,		//[IN]设备存储大小（MB），如硬盘或闪存
	IN		PNPC_CHAR							in_pDevNetInfo,				//[IN]设备网络信息
	IN		PNPC_CHAR							in_pDevParam1,				//[IN]设备参数1
	IN		PNPC_CHAR							in_pDevParam2,				//[IN]设备参数2
	IN		PNPC_CHAR							in_pDevParam3,				//[IN]设备参数3
	IN		PNPC_CHAR							in_pDevInfo					//[IN]设备其它信息
	);

//修改用户密码
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyUserPwd(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID，即用户帐号
	IN		PNPC_CHAR							in_pOldPwd,					//[IN]原密码
	IN		PNPC_CHAR							in_pNewPwd					//[IN]新密码
	);

//查询用户的全局权限表，该权限可操作所有设备
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryUserGlobalPopedom(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID，即用户帐号
	OUT		PNPC_BOOL							out_pIfAllPop,				//[OUT]是否有全部权限，如果为TRUE，则不需要查询其它，所有功能都可以使用
	OUT		PNPC_INT							out_pPopNum,				//[OUT]权限数
	OUT		PNPC_INT							out_pPopIdTable				//[OUT]权限ID表，最大128个权限，由调用者分配内存，权限ID参见NPC_D_MPI_MON_USER_POP_*定义
	);

//查询用户的设备权限表，操作指定设备的权限
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryUserDevPopedom(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID，即用户帐号
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	OUT		PNPC_INT							out_pPopNum,				//[OUT]权限数
	OUT		PNPC_INT							out_pPopIdTable				//[OUT]权限ID表，最大128个权限，由调用者分配内存，权限ID参见NPC_D_MPI_MON_USER_POP_*定义
	);

//获取设备提示消息列表
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetDevPromptList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	OUT		PNPC_INT							out_pPromptNum,				//[OUT]提示消息数
	OUT		PNPC_S_MPI_MON_DEV_PROMPT*			out_ppPromptList			//[OUT]提示消息列表，由底层分配，使用完后必须调用NPC_F_MPI_MON_CLT_ReleaseDevPromptList函数释放内存
	);

//释放提示消息列表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ReleaseDevPromptList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_PROMPT			in_pPromptList				//[IN]提示消息列表
	);

//忘记密码，请求发送消息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ForgetPwd(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID
	OUT		PNPC_CHAR							out_pSendMsgTypeName		//[OUT]发送消息类型名称，如短信、邮件
	);


//----------------------------------------------------------------------------------------
//添加设备结点
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_AddDevNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iNodeType,				//[IN]结点类型，参见NPC_D_MPI_MON_DEV_NODE_TYPE_*定义
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]父结点，如果添加的结点为顶层，则该字段值为NULL
	IN		PNPC_CHAR							in_pNodeName,				//[IN]结点名称
	IN		NPC_INT								in_iConnMode,				//[IN]连接模式，参见NPC_D_MON_DEV_CONN_MODE_*定义
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pConnParam,				//[IN]连接参数
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]返回添加的设备结点数据
	);

//添加设备结点（扩展）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_AddDevNodeEx(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iNodeType,				//[IN]结点类型，参见NPC_D_MPI_MON_DEV_NODE_TYPE_*定义
	IN		NPC_DWORD							in_dwParentNodeId,			//[IN]父结点ID，如果为0，则为顶层
	IN		PNPC_CHAR							in_pNodeName,				//[IN]结点名称
	IN		NPC_INT								in_iConnMode,				//[IN]连接模式，参见NPC_D_MON_DEV_CONN_MODE_*定义
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pConnParam,				//[IN]连接参数
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]返回添加的设备结点数据
	);

//删除设备结点
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_DelDevNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode					//[IN]设备结点
	);

//修改设备连接参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点
	IN		PNPC_CHAR							in_pConnParam				//[IN]连接参数
	);

//修改结点名称
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyNodeName(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点
	IN		PNPC_CHAR							in_pNodeName				//[IN]结点名称
	);

//查询设备信息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDevNodeInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点
	OUT		PNPC_S_MPI_MON_DEV_INFO				out_pDevInfo				//[OUT]设备信息
	);

//在服务器中查询设备信息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_AtSrvQueryDevInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	OUT		PNPC_S_MPI_MON_DEV_INFO				out_pDevInfo				//[OUT]设备信息
	);

//查询设备状态
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDevState(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点
	OUT		PNPC_INT							out_pDevState				//[OUT]设备状态，0：离线，1：在线，2：故障
	);

//根据设备连接参数查询设备ID
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDevIdByConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pConnParam,				//[IN]连接参数
	OUT		PNPC_CHAR							out_pDevId					//[OUT]设备ID
	);

//查询设备列表
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDevList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iQueryType,				//[IN]查询类型，0：查询所有设备，1：查询在线设备，2：查询离线设备
	OUT		PNPC_INT							out_pDevNum,				//[OUT]设备数
	OUT		PNPC_BYTE*							out_ppDevListBuf			//[OUT]设备列表缓冲区，由该函数分配，调用者释放，由NPC_S_MPI_MON_DEV_LIST_ITEM结构体组成
	);

//释放设备列表缓冲区
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ReleaseDevListBuf(
	IN		PNPC_BYTE							in_pDevListBuf				//[IN]设备列表缓冲区，由NPC_F_MPI_MON_CLT_QueryDevList函数产生的
	);

//查询P2P云设备的连接参数（即连接类型为NPC_D_MON_DEV_CONN_MODE_CLOUD_P2P或者NPC_D_MON_DEV_CONN_MODE_CLOUD_STREAM）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryP2pCloudDevConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID（即摄像机ID）
	OUT		PNPC_INT							out_pVendorId,				//[OUT]设备厂商ID
	OUT		PNPC_CHAR							out_pDevUmid,				//[OUT]设备UMID
	OUT		PNPC_CHAR							out_pDevUserName,			//[OUT]设备用户名
	OUT		PNPC_CHAR							out_pDevUserPwd,			//[OUT]设备密码
	OUT		PNPC_INT							out_pDevChNo,				//[OUT]设备通道号
	OUT		PNPC_INT							out_pDevStreamNo			//[OUT]设备子码流号
	);

//查询直连设备的连接参数（即连接类型为NPC_D_MON_DEV_CONN_MODE_DIRECT）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryDirectDevConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID（即摄像机ID）
	OUT		PNPC_INT							out_pVendorId,				//[OUT]设备厂商ID
	OUT		PNPC_CHAR							out_pDevAddr,				//[OUT]设备地址
	OUT		PNPC_USHORT							out_pDevPort,				//[OUT]设备端口号
	OUT		PNPC_CHAR							out_pDevUserName,			//[OUT]设备用户名
	OUT		PNPC_CHAR							out_pDevUserPwd,			//[OUT]设备密码
	OUT		PNPC_INT							out_pDevChNo,				//[OUT]设备通道号
	OUT		PNPC_INT							out_pDevStreamNo			//[OUT]设备子码流号
	);



//----------------------------------------------------------------------------------------
//查询设备列表，返回列表句柄，返回NULL表示查询失败，使用完列表后必须调用NPC_F_MPI_MON_CLT_DevList_Release函数释放
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_DevList_Query(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwQueryNodeId			//[IN]查询结点ID，查访该结点之下的结点，只查询一层，如果为0表示查询顶层结点
	);

//释放设备列表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DevList_Release(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_HANDLE							in_hDevList					//[IN]设备列表
	);

//移动到设备列表的第一条
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DevList_MoveFirst(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_HANDLE							in_hDevList					//[IN]设备列表
	);

//获取下一条设备信息，返回NULL表示获取完成，该函数不会从列表中删除记录
NPC_MPI_MON_API		PNPC_S_MPI_MON_DEV_NODE		NPC_F_MPI_MON_CLT_DevList_GetNextDevNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_HANDLE							in_hDevList					//[IN]设备列表
	);


//----------------------------------------------------------------------------------------
//设置或清除PTZ名称（指预置点或巡航路径名称）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetPtzName(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		NPC_INT								in_iOpFlag,					//[IN]操作标志，1表示设置，0表示清除
	IN		NPC_INT								in_iPtzType,				//[IN]PTZ类型，0：预置点，1：巡航路径
	IN		NPC_INT								in_iPtzIndex,				//[IN]PTZ号，即预置点号或巡航路径号，预置点号值范围为1至255，巡航路径号值范围为1至32
	IN		PNPC_CHAR							in_pPtzName					//[IN]PTZ名称，指预置点或巡航路径的名称，最大15个汉字或31个字符
	);

//查询PTZ名称列表，返回列表句柄，返回NULL表示查询失败，使用完列表后必须调用NPC_F_MPI_MON_CLT_PtzNameList_Release函数释放
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_PtzNameList_Query(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId					//[IN]设备ID
	);

//释放PTZ名称列表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_PtzNameList_Release(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_HANDLE							in_hPtzNameList				//[IN]PTZ名称列表
	);

//移动到PTZ名称列表的第一条
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_PtzNameList_MoveFirst(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_HANDLE							in_hPtzNameList				//[IN]PTZ名称列表
	);

//获取下一条PTZ名称，返回NULL表示获取完成，该函数不会从列表中删除记录
NPC_MPI_MON_API		PNPC_S_MPI_MON_PTZ_NAME		NPC_F_MPI_MON_CLT_PtzNameList_GetNextDevNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_HANDLE							in_hPtzNameList				//[IN]PTZ名称列表
	);


//----------------------------------------------------------------------------------------
//设置设备的经纬度坐标，如果不存在，则添加
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Coordinate_SetDevCoor(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		NPC_INT								in_iLongitude,				//[IN]经度，低6位为小数部分，其它为整数部分，值范围为-180000000~180000000
	IN		NPC_INT								in_iLatitude				//[IN]纬度，低6位为小数部分，其它为整数部分，值范围为-90000000~90000000
	);

//删除设备的经纬度坐标
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Coordinate_DelDevCoor(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId					//[IN]设备ID
	);


//----------------------------------------------------------------------------------------
//查询厂商连接参数定义表
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_Vendor_QueryConnParamTable(
	IN		NPC_HANDLE								in_hMonClient,			//[IN]客户端句柄
	OUT		PNPC_S_MPI_MON_CONNPARAM_VENDOR_DATA*	out_ppVendorTable,		//[OUT]厂商表，由NPC_S_MPI_MON_CONNPARAM_VENDOR_DATA组成的数组，由底层分配内存，上层使用完后必须调用函数释放内存
	OUT		PNPC_INT								out_pVendorNum			//[OUT]厂商数
	);

//释放厂商连接参数表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_Vendor_ReleaseConnParamTable(
	IN		PNPC_S_MPI_MON_CONNPARAM_VENDOR_DATA	in_pVendorTable,		//[IN]厂商表
	IN		NPC_INT									in_iVendorNum			//[IN]厂商数
	);


//----------------------------------------------------------------------------------------
//获取推送消息，返回TRUE表示有推送消息，FALSE表示没有
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetPushMsg(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	OUT		PNPC_S_MPI_MON_PUSH_MSG_DATA		out_pPushMsgData,			//[OUT]推送消息数据
	IN		NPC_INT								in_iTimeout					//[IN]等待超时时长（毫秒）
	);


//----------------------------------------------------------------------------------------
//设备授权
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EMP_DevEmpower(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		PNPC_CHAR							in_pPopIdTable,				//[IN]权限ID表，以逗号分隔
	IN		PNPC_CHAR							in_pAccepterUserIdTable		//[IN]接收者用户ID表，以逗号分隔
	);

//取消设备授权
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EMP_CancelDevEmpower(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		PNPC_CHAR							in_pAccepterUserIdTable		//[IN]接收者用户ID表，以逗号分隔
	);

//查询设备的接收授权用户列表
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EMP_QueryDevAccepterUserList(
	IN		NPC_HANDLE								in_hMonClient,			//[IN]客户端句柄
	IN		PNPC_CHAR								in_pDevId,				//[IN]设备ID
	OUT		PNPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA*	out_pAccUserTable,		//[OUT]接收者用户表，由底层分配内存，使用完后必须调用NPC_F_MPI_MON_CLT_EMP_ReleaseDevAccepterUserList函数释放
	OUT		PNPC_INT								out_pAccUserNum			//[OUT]接收者用户数
	);

//释放接收者用户表缓冲区
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_EMP_ReleaseDevAccepterUserList(
	IN		PNPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA		in_pAccUserTable		//[IN]接收者用户表，由底层分配内存，使用完后必须调用函数释放
	);

//查询设备的授权者
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EMP_QueryDevEmpowerUserId(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	OUT		PNPC_CHAR							out_pEmpowerUserId			//[OUT]授权者用户ID
	);


//----------------------------------------------------------------------------------------
//布防
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetAlarm(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		PNPC_CHAR							in_pAlarmTypeTable			//[IN]报警类型表，以逗号分隔，值参考NPC_D_MON_ALARM_TYPE_*定义
	);

//布防（扩展），该函数默认开启推送功能
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetAlarmEx(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		PNPC_CHAR							in_pAlarmTypeTable,			//[IN]报警类型表，以逗号分隔，值参考NPC_D_MON_ALARM_TYPE_*定义
	IN		PNPC_CHAR							in_pToken					//[IN]消息推送的TOKEN，IPHONE为推送的TOKEN，安卓和PC为客户端ID
	);

//撤防
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_CancelAlarm(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId					//[IN]设备ID
	);

//设置布防通知参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetNotifyParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		NPC_INT								in_iNotifyType,				//[IN]通知类型，参考NPC_D_MON_ALARM_NOTIFY_TYPE_*定义
	IN		PNPC_CHAR							in_pNotifyParam				//[IN]通知参数，根据通知类型确定通知参数内容，如手机推送为TOKEN，短信为手机号码，EMAIL为EMAIL地址
	);

//取消布防通知参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_CancelNotifyParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		NPC_INT								in_iNotifyType,				//[IN]通知类型，参考NPC_D_MON_ALARM_NOTIFY_TYPE_*定义
	IN		PNPC_CHAR							in_pNotifyParam				//[IN]通知参数，根据通知类型确定通知参数内容，如手机推送为TOKEN，短信为手机号码，EMAIL为EMAIL地址
	);

//设置报警联动
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetAlarmAction(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		NPC_INT								in_iActionType,				//[IN]联动类型，参考NPC_D_MON_ALARM_ACTION_TYPE_*定义
	IN		NPC_INT								in_iStopType,				//[IN]停止类型，0：报警停止时停止，1：固定时长停止
	IN		NPC_INT								in_iPhotoSpaceTime,			//[IN]拍照间隔时间（秒）
	IN		NPC_INT								in_iActionTotalTime,		//[IN]联动总时间（秒）
	IN		NPC_INT								in_iPtzCruiseId				//[IN]PTZ联动巡航ID
	);

//取消报警联动
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_CancelAlarmAction(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		NPC_INT								in_iActionType				//[IN]联动类型，参考NPC_D_MON_ALARM_ACTION_TYPE_*定义
	);

//查询布防信息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_QueryArmInfo(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	OUT		PNPC_S_MPI_MON_ARM_SET_ALARM_INFO	out_pArmInfo				//[OUT]报警布防信息
	);

//布防控制
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_ArmCtrl(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		NPC_INT								in_iCtrlCode				//[IN]控制代码，参考NPC_D_MON_ALARM_CTRL_*定义
	);

//查询报警记录，返回查询列表句柄，返回NULL表示查询失败，调用者使用完查询列表后，必调用NPC_F_MPI_MON_CLT_ARM_ReleaseAlarmRecordList释放
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Query(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pQueryDevId,				//[IN]查询设备ID（即摄像机ID），如果为NULL或空值，则该条件无效
	IN		NPC_INT								in_iQueryAlarmType,			//[IN]查询报警类型，参考NPC_D_MON_ALARM_TYPE_*定义，如果为0，表示该条件无效
	IN		PNPC_S_TD_DATE_TIME					in_pQueryBeginTime,			//[IN]查询开始时间，如果为NULL，则该条件无效
	IN		PNPC_S_TD_DATE_TIME					in_pQueryEndTime			//[IN]查询结束时间，如果为NULL，则该条件无效
	);

//释放报警记录列表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_ReleaseList(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]报警记录列表
	);

//记录指针移动到第一条（查询后初始状态为第一条，所以查询后可以不调用该函数，该函数用于提取完后，再次提取使用）
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_MoveFirst(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]报警记录列表
	);

//提取下一条记录，返回NULL表示提取完必，返回的指针只能使用，不能释放，释放由释放报警记录列表函数统一释放
NPC_MPI_MON_API		PNPC_S_MPI_MON_ARM_ALARM_RECORD		NPC_F_MPI_MON_CLT_ARM_AlarmRecord_GetNext(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]报警记录列表
	);

//删除报警记录
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Delete(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pAlarmRecordId			//[IN]报警记录ID
	);

//删除所有报警记录
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_DeleteAll(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iDelMode,				//[IN]删除模式，0：用户下的所有报警记录，1：用户下的设备的报警记录
	IN		PNPC_CHAR							in_pDevId					//[IN]设备ID（即摄像机ID，非UMID）
	);

//获取客户端的报警通知参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_GetClientAlarmNotifyParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	OUT		PNPC_BOOL							out_pIfMsgNotify			//[OUT]是否要消息通知
	);

//设置客户端的报警通知参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetClientAlarmNotifyParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_BOOL							in_bIfMsgNotify				//[IN]是否要消息通知
	);

//更新客户端TOKEN
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_UpdateClientToken(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pClientToken				//[IN]客户端TOKEN
	);

//获取客户端是否接收推送
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_GetClientIfRecvPush(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	OUT		PNPC_BOOL							out_pIfRecvPush				//[IN]是否接收推送
	);

//设置客户端是否接收推送
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetClientIfRecvPush(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_BOOL							in_bIfRecvPush				//[IN]是否接收推送
	);

//获取客户端推送参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_GetClientPushParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	OUT		PNPC_BOOL							out_pIfRecvPush,			//[IN]是否接收推送
	OUT		PNPC_INT							out_pNotReadCount			//[IN]未读取记录数
	);

//设置客户端推送参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetClientPushParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_BOOL							in_bEnableIfRecvPush,		//[IN]参数in_bIfRecvPush是否有效，如果为TRUE，表示in_bIfRecvPush参数有效，否则为无效，即不设置该参数
	IN		NPC_BOOL							in_bEnableNotReadCount,		//[IN]参数in_iNotReadCount是否有效
	IN		NPC_BOOL							in_bIfRecvPush,				//[IN]是否接收推送
	IN		NPC_INT								in_iNotReadCount			//[IN]未读取记录数
	);

//激活用户推送（主要用于IOS客户端切换帐号时使用）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_ActivateUserPush(
	IN		NPC_HANDLE							in_hMonClient,					//[IN]客户端句柄
	IN		NPC_INT								in_iRecvPushCtrl,				//[IN]本帐号是否接收推送，0：不设置，1：不接收，2：接收
	IN		NPC_BOOL							in_bIfDisableOtherUserRecvPush	//[IN]是否需要禁用其它帐号接收推送
	);


//--------------------------------------------------------------------------------------------
//查询小区报警记录，返回查询列表句柄，返回NULL表示查询失败，调用者使用完查询列表后，必调用NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_ReleaseList释放
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_Query(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_TD_DATE_TIME					in_pQueryBeginTime,			//[IN]查询开始时间，如果为NULL，则该条件无效
	IN		PNPC_S_TD_DATE_TIME					in_pQueryEndTime			//[IN]查询结束时间，如果为NULL，则该条件无效
	);

//释放小区报警记录列表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_ReleaseList(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]报警记录列表
	);

//记录指针移动到第一条（查询后初始状态为第一条，所以查询后可以不调用该函数，该函数用于提取完后，再次提取使用）
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_MoveFirst(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]报警记录列表
	);

//提取下一条记录，返回NULL表示提取完必，返回的指针只能使用，不能释放，释放由释放报警记录列表函数统一释放
NPC_MPI_MON_API		PNPC_S_MPI_MON_ARM_VILLAGE_ALARM_RECORD		NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_GetNext(
	IN		NPC_HANDLE							in_hAlarmRecordList			//[IN]报警记录列表
	);

//设置报警结果
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_AlarmRecord_Village_SetAlarmResult(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pAlarmRecordId,			//[IN]报警记录ID
	IN		PNPC_CHAR							in_pAlarmResult				//[IN]报警结果
	);

//获取通知语言
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_GetNotifyLanguage(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iGetType,				//[IN]获取类型，0：推送，1：短信
	IN		PNPC_CHAR							in_pToken,					//[IN]TOKEN，如果是推送，则为手机TOKEN，如果短信，则为手机号码
	OUT		PNPC_CHAR							out_pNotifyLanguage			//[OUT]通知语言
	);

//设置通知语言
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ARM_SetNotifyLanguage(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iGetType,				//[IN]获取类型，0：推送，1：短信
	IN		PNPC_CHAR							in_pToken,					//[IN]TOKEN，如果是推送，则为手机TOKEN，如果短信，则为手机号码
	IN		PNPC_CHAR							in_pNotifyLanguage			//[IN]通知语言
	);


//--------------------------------------------------------------------------------------------
//验证全局权限，返回TRUE表有此权限，FALSE表示无此权限
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_CheckGlobalPop(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iPopId					//[IN]权限ID
	);

//验证设备权限，返回TRUE表有此权限，FALSE表示无此权限
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_CheckDevPop(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点
	IN		NPC_INT								in_iPopId					//[IN]权限ID
	);


//--------------------------------------------------------------------------------------------
//开始搜索设备
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_StartSearchDev(
	IN		NPC_BOOL							in_bIfAutoRefresh=TRUE,		//[IN]是否自动刷新
	IN		NPC_INT								in_iRefreshIntervalTime=2	//[IN]刷新间隔时间（秒）
	);

//开始搜索设备（扩展）
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_StartSearchDevEx(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_BOOL							in_bIfAutoRefresh=TRUE,		//[IN]是否自动刷新
	IN		NPC_INT								in_iRefreshIntervalTime=2	//[IN]刷新间隔时间（秒）
	);

//停止搜索设备
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_StopSearchDev(
	IN		NPC_HANDLE							in_hSearchDev				//[IN]搜索设备句柄
	);

//设置刷新模式
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SetRefreshMode(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	IN		NPC_BOOL							in_bIfAutoRefresh,			//[IN]是否自动刷新
	IN		NPC_INT								in_iRefreshIntervalTime		//[IN]刷新间隔时间（秒）
	);

//请求刷新
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_RequRefresh(
	IN		NPC_HANDLE							in_hSearchDev				//[IN]搜索设备句柄
	);

//获取搜索设备列表（定时调用获取设备列表）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetSearchDevTable(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	OUT		PNPC_INT							out_pSearchDevNum,			//[OUT]设备数
	OUT		PNPC_S_MPI_MON_SEARCH_DEV_DATA*		out_ppSearchDevTable		//[OUT]搜索设备表，即设备数组，指针指向的内存空间，上层只能使用，不能修改和释放
	);

//修改搜索设备ID
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifySearchDevId(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	IN		PNPC_CHAR							in_pOldDevId,				//[IN]原设备ID
	IN		PNPC_CHAR							in_pNewDevId				//[IN]新设备ID
	);

//修改搜索设备名称
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifySearchDevName(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		PNPC_CHAR							in_pDevName					//[IN]设备名称
	);

//跟踪设备日志信息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_TraceDevLogInfo(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	IN		PNPC_CHAR							in_pDevMac,					//[IN]设备MAC，格式为XX-XX-
	IN		NPC_BOOL							in_bIfOpenTrace				//[IN]是否打开跟踪，TRUE表示打开，FALSE表示关闭
	);

//提取设备日志信息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetDevLogInfo(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	IN		PNPC_CHAR							in_pLogBuf,					//[IN]日志缓冲区，由上层分配内存
	IN		NPC_INT								in_iLogBufSize				//[IN]日志缓冲区大小
	);



//--------------------------------------------------------------------------------------------
//请求搜索SDK设备
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RequSearchSdkDev(
	IN		NPC_HANDLE							in_hSearchDev				//[IN]搜索设备句柄
	);

//获取搜索SDK设备列表（只支持上层单线程调用和使用内存）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetSearchSdkDevTable(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	OUT		PNPC_INT							out_pSearchSdkDevNum,		//[OUT]SDK设备数
	OUT		PNPC_S_MPI_MON_SEARCH_SDK_DEV_DATA*	out_ppSearchSdkDevTable		//[OUT]搜索SDK设备表，即设备数组，指针指向的内存空间，上层只能使用，不能修改和释放
	);

//跟踪SDK设备日志信息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_TraceSdkDevLogInfo(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	IN		NPC_UINT							in_uiDevFlag,				//[IN]设备标识，与搜索设备数据中的一致
	IN		NPC_BOOL							in_bIfOpenTrace				//[IN]是否打开跟踪，TRUE表示打开，FALSE表示关闭
	);

//设置SDK设备调试参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SetSdkDevParam(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	IN		NPC_UINT							in_uiDevFlag,				//[IN]设备标识，与搜索设备数据中的一致
	IN		NPC_BOOL							in_bIfOpenDebug				//[IN]是否打开调试开关
	);

//提取SDK设备日志信息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_GetSdkDevLogInfo(
	IN		NPC_HANDLE							in_hSearchDev,				//[IN]搜索设备句柄
	IN		PNPC_CHAR							in_pLogBuf,					//[IN]日志缓冲区，由上层分配内存
	IN		NPC_INT								in_iLogBufSize				//[IN]日志缓冲区大小
	);


//--------------------------------------------------------------------------------------------
//查询NTS设备的参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_QueryNtsDevParam(
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	OUT		PNPC_S_MPI_MON_NTS_DEV_PARAM		out_pNtsDevParam			//[OUT]NTS设备参数
	);

//修改设备中的注册服务器地址
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevRegSrvAddr(
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]服务器地址（IP地址或域名）
	IN		NPC_USHORT							in_usServerPort				//[IN]服务器端口号
	);

//修改设备中的跟踪参数
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevTraceParam(
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		NPC_BOOL							in_bIfWriteLogFile,			//[IN]是否写日志文件
	IN		NPC_BOOL							in_bIfStartLogNetSrv,		//[IN]是否需要启动日志网络服务
	IN		NPC_USHORT							in_usLogNetSrvPort,			//[IN]日志网络服务端口号
	IN		NPC_BOOL							in_bIfStartLogUpClient,		//[IN]是否需要启动日志上传客户端
	IN		PNPC_CHAR							in_pLogUpSrvIpaddr,			//[IN]日志上传服务IP地址
	IN		NPC_USHORT							in_usLogUpSrvPort			//[IN]日志上传服务端口号
	);

//修改设备中的设备ID（即UMID），返回0表示成功，50：表示不是手动设置模式，51：表示设置配置参数失败
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_ModifyDevId(
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]网卡MAC地址，格式为：XX-XX-
	IN		PNPC_CHAR							in_pDevId					//[IN]设备ID（即UMID）
	);

//修改设备中的设备的认证码（只能在认证码授权模式可用），返回0表示成功，50：表示不是认证码授权模式，51：表示设置配置参数失败
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_ModifyDevAuthCode(
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]网卡MAC地址，格式为：XX-XX-
	IN		PNPC_CHAR							in_pAuthCode				//[IN]授权码
	);

//获取设备中的授权码，返回0表示成功，其它表示失败
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_GetDevEmpower(
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]网卡MAC地址，格式为：XX-XX-
	OUT		PNPC_INT							out_pEmpowerMode,			//[OUT]授权模式，1：UMID授权模式，3：服务器授权模式
	OUT		PNPC_CHAR							out_pEmpowerCode,			//[OUT]授权码
	OUT		PNPC_INT							out_pDevIdType,				//[OUT]设备ID类型，0：手动设置方式，2：按MAC地址生成方式（如果配置文件中设备ID存在，则不会再生成）
	OUT		PNPC_CHAR							out_pDevId					//[OUT]设备ID
	);

//设置设备中的授权码，返回0表示成功，50：表示不是认证码授权模式，51~54：表示设置配置参数失败
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_CLT_SetDevEmpower(
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]网卡MAC地址，格式为：XX-XX-
	IN		NPC_INT								in_iEmpowerMode,			//[IN]授权模式，1：UMID授权模式，3：服务器授权模式
	IN		PNPC_CHAR							in_pEmpowerCode,			//[IN]授权码
	IN		NPC_INT								in_iDevIdType,				//[IN]设备ID类型，0：手动设置方式，2：按MAC地址生成方式（如果配置文件中设备ID存在，则不会再生成）
	IN		PNPC_CHAR							in_pDevId					//[IN]设备ID
	);


//--------------------------------------------------------------------------------------------
//修改设备的IP地址
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevIpaddr(
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]网卡MAC地址，格式为：XX-XX-
	IN		PNPC_CHAR							in_pOldIpaddr,				//[IN]源IP地址
	IN		PNPC_CHAR							in_pNewIpaddr,				//[IN]新IP地址
	IN		PNPC_CHAR							in_pNewNetmask,				//[IN]新子网掩码
	IN		PNPC_CHAR							in_pNewGateway				//[IN]新网关地址
	);

//使能设备的DHCP功能
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_EnableDevDhcp(
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]网卡MAC地址，格式为：XX-XX-
	IN		PNPC_CHAR							in_pAdapterName,			//[IN]网卡名称
	IN		NPC_BOOL							in_bEnable					//[IN]使能DHCP，TRUE：启动DHCP，FALSE：禁用DHCP
	);

//修改设备密码
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevPwd(
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]网卡MAC地址，格式为：XX-XX-
	IN		PNPC_CHAR							in_pOldPwd,					//[IN]原密码，如果设备未设置过密码，则该参数为NULL
	IN		PNPC_CHAR							in_pNewPwd					//[IN]新密码
	);

//修改设备名称
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_ModifyDevName(
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pAdapterMac,				//[IN]网卡MAC地址，格式为：XX-XX-
	IN		PNPC_CHAR							in_pDevName					//[IN]设备名称
	);


//--------------------------------------------------------------------------------------------
//添加通用设备
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_AddCommonDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwParentNodeId,			//[IN]父结点ID，如果添加的结点为顶层，则该字段值为0
	IN		NPC_INT								in_iConnMode,				//[IN]连接模式，参见NPC_D_MON_DEV_CONN_MODE_*定义
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pName,					//[IN]名称
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]设备UMID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]设备地址
	IN		NPC_USHORT							in_usDevPort,				//[IN]设备端口号
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iStreamNo,				//[IN]码流，0：主码流，1：子码流
	IN		NPC_INT								in_iChNum,					//[IN]通道数
	IN		NPC_INT								in_iDevNodeTableSize,		//[IN]设备结点表大小（字节），应为(in_iChNum+1)*sizeof(NPC_S_MPI_MON_DEV_NODE)
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNodeTable,			//[OUT]返回添加的设备结点表，内存上调用者分配
	OUT		PNPC_INT							out_pDevNodeNum				//[OUT]设备结点数
	);

//添加通用摄像机
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_AddCommonCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwParentNodeId,			//[IN]父结点ID，如果添加的结点为顶层，则该字段值为0
	IN		NPC_INT								in_iConnMode,				//[IN]连接模式，参见NPC_D_MON_DEV_CONN_MODE_*定义
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pName,					//[IN]名称
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]设备UMID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]设备地址
	IN		NPC_USHORT							in_usDevPort,				//[IN]设备端口号
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iStreamNo,				//[IN]码流，0：主码流，1：子码流
	IN		NPC_INT								in_iChNo,					//[IN]通道号
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]返回添加的设备结点数据
	);

//删除通用设备
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_DeleteCommonDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwNodeId					//[IN]结点ID，值大于0
	);

//修改P2P设备的连接参数（暂停）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_ModifyP2pDevConnParam(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwNodeId,				//[IN]结点ID，值大于0
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID（如摄像机ID等）
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]设备UMID
	IN		PNPC_CHAR							in_pDevUserName,			//[IN]设备用户名
	IN		PNPC_CHAR							in_pDevUserPwd,				//[IN]设备用户密码
	IN		NPC_BOOL							in_bIfModifyStreamNo,		//[IN]是否需要修改子码流
	IN		NPC_INT								in_iDevStreamNo				//[IN]设备子码流号，0：主码流，1：子码流，i_bIfModifyStreamNo为TRUE是有效
	);

//修改通用设备（或摄像机）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_ModifyCommonDevAndCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwNodeId,				//[IN]结点ID
	IN		PNPC_CHAR							in_pDevUmid,				//[IN]设备UMID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]设备地址
	IN		NPC_USHORT							in_usDevPort,				//[IN]设备端口号
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iChNo,					//[IN]通道号，如果为-1表示不修改，如果为DVR，也不修改
	IN		NPC_INT								in_iStreamNo,				//[IN]码流，0：主码流，1：子码流
	IN		NPC_BOOL							in_bIfModifyStreamNo		//[IN]是否需要修改子码流
	);

//添加目录结点
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_AddCatalogNode(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwParentNodeId,			//[IN]父结点ID，如果添加的结点为顶层，则该字段值为0
	IN		PNPC_CHAR							in_pNodeName,				//[IN]结点名称
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]返回添加的设备结点数据
	);

//修改结点名称（包括目录、DVR、镜头的名称）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_KPS_ModifyNodeName(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_DWORD							in_dwNodeId,				//[IN]结点ID
	IN		PNPC_CHAR							in_pNodeName				//[IN]结点名称
	);


//--------------------------------------------------------------------------------------------
//添加P2P云设备
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddP2pCloudDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]父结点，如果添加的结点为顶层，则该字段值为NULL
	IN		PNPC_CHAR							in_pName,					//[IN]名称
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iStreamNo,				//[IN]码流，0：主码流，1：子码流
	IN		NPC_INT								in_iChNum,					//[IN]通道数
	IN		NPC_INT								in_iDevNodeTableSize,		//[IN]设备结点表大小（字节），应为(in_iChNum+1)*sizeof(NPC_S_MPI_MON_DEV_NODE)
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNodeTable,			//[OUT]返回添加的设备结点表，内存上调用者分配
	OUT		PNPC_INT							out_pDevNodeNum				//[OUT]设备结点数
	);

//添加P2P云镜头
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddP2pCloudCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]父结点，如果添加的结点为顶层，则该字段值为NULL
	IN		PNPC_CHAR							in_pName,					//[IN]名称
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iStreamNo,				//[IN]码流，0：主码流，1：子码流
	IN		NPC_INT								in_iChNo,					//[IN]通道号
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]返回添加的设备结点数据
	);

//添加直连设备
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddDirectDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]父结点，如果添加的结点为顶层，则该字段值为NULL
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pName,					//[IN]名称
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]设备地址
	IN		NPC_USHORT							in_usDevPort,				//[IN]设备端口
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iStreamNo,				//[IN]码流，0：主码流，1：子码流
	IN		NPC_INT								in_iChNum,					//[IN]通道数
	IN		NPC_INT								in_iDevNodeTableSize,		//[IN]设备结点表大小（字节），应为(in_iChNum+1)*sizeof(NPC_S_MPI_MON_DEV_NODE)
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNodeTable,			//[OUT]返回添加的设备结点表，内存上调用者分配
	OUT		PNPC_INT							out_pDevNodeNum				//[OUT]设备结点数
	);

//添加直连镜头
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddDirectCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]父结点，如果添加的结点为顶层，则该字段值为NULL
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pName,					//[IN]设备名称
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]设备地址
	IN		NPC_USHORT							in_usDevPort,				//[IN]设备端口
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iStreamNo,				//[IN]码流，0：主码流，1：子码流
	IN		NPC_INT								in_iChNo,					//[IN]通道号
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]返回添加的设备结点数据
	);

//添加云流媒体设备
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddCloudStreamDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]父结点，如果添加的结点为顶层，则该字段值为NULL
	IN		PNPC_CHAR							in_pName,					//[IN]名称
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iStreamNo,				//[IN]码流，0：主码流，1：子码流
	IN		NPC_INT								in_iChNum,					//[IN]通道数
	IN		NPC_INT								in_iDevNodeTableSize,		//[IN]设备结点表大小（字节），应为(in_iChNum+1)*sizeof(NPC_S_MPI_MON_DEV_NODE)
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNodeTable,			//[OUT]返回添加的设备结点表，内存上调用者分配
	OUT		PNPC_INT							out_pDevNodeNum				//[OUT]设备结点数
	);

//添加云流媒体镜头
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_AddCloudStreamCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pParentNode,				//[IN]父结点，如果添加的结点为顶层，则该字段值为NULL
	IN		PNPC_CHAR							in_pName,					//[IN]名称
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iStreamNo,				//[IN]码流，0：主码流，1：子码流
	IN		NPC_INT								in_iChNo,					//[IN]通道号
	OUT		PNPC_S_MPI_MON_DEV_NODE				out_pDevNode				//[OUT]返回添加的设备结点数据
	);


//--------------------------------------------------------------------------------------------
//修改P2P云设备
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyP2pCloudDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点数据
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]是否修改码流
	IN		NPC_INT								in_iStreamNo				//[IN]码流，0：主码流，1：子码流
	);

//修改P2P云镜头
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyP2pCloudCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点数据
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iChNo,					//[IN]通道号
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]是否修改码流
	IN		NPC_INT								in_iStreamNo				//[IN]码流，0：主码流，1：子码流
	);

//修改直连设备
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyDirectDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点数据
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]设备地址
	IN		NPC_USHORT							in_usDevPort,				//[IN]设备端口
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]是否修改码流
	IN		NPC_INT								in_iStreamNo				//[IN]码流，0：主码流，1：子码流
	);

//修改直连镜头
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyDirectCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点数据
	IN		NPC_DWORD							in_dwVendorId,				//[IN]厂商ID
	IN		PNPC_CHAR							in_pDevAddr,				//[IN]设备地址
	IN		NPC_USHORT							in_usDevPort,				//[IN]设备端口
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iChNo,					//[IN]通道号
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]是否修改码流
	IN		NPC_INT								in_iStreamNo				//[IN]码流，0：主码流，1：子码流
	);

//修改云流媒体设备（即DVR）
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyCloudStreamDev(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点数据
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]是否修改码流
	IN		NPC_INT								in_iStreamNo				//[IN]码流，0：主码流，1：子码流
	);

//修改云流媒体镜头
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_RAT_ModifyCloudStreamCamera(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_S_MPI_MON_DEV_NODE				in_pDevNode,				//[IN]设备结点数据
	IN		PNPC_CHAR							in_pDevId,					//[IN]设备ID，即UMID
	IN		PNPC_CHAR							in_pUserName,				//[IN]用户名
	IN		PNPC_CHAR							in_pUserPwd,				//[IN]密码
	IN		NPC_INT								in_iChNo,					//[IN]通道号
	IN		NPC_BOOL							in_bIfModStreamNo,			//[IN]是否修改码流
	IN		NPC_INT								in_iStreamNo				//[IN]码流，0：主码流，1：子码流
	);


//------------------------------------------------------------------------------------------------------
//获取低层所支持的厂商协议列表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_GetProVendorList(
	OUT		PNPC_INT							out_pVendorNum,				//[OUT]厂商数
	OUT		PNPC_S_MPI_MON_VENDOR_NAME			out_pVendorTable			//[OUT]厂商表（数组），由调用者分配内存，大小为64*sizeof(NPC_S_MPI_MON_VENDOR_NAME)
	);


//------------------------------------------------------------------------------------------------------
//获取操作文件命令
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_SFI_GetOpFileOrder(
	OUT		PNPC_S_MPI_MON_FILE_OP_ORDER*		out_ppFileOpOrder,			//[OUT]文件操作命令，内存由低层分配，上层只能使用，并需要调用NPC_F_MPI_MON_SFI_ReleaseOpFileOrderBuf函数释放
	IN		NPC_INT								in_iTimeout					//[IN]超时时长（毫秒）
	);

//返回操作文件应答消息
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_SFI_ReturnOpFileResp(
	IN		PNPC_S_MPI_MON_FILE_OP_ORDER		in_pFileOpOrder				//[IN]文件操作命令，内存由上层分配及释放，底层只有使用
	);

//释放文件操作命令缓冲区
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_SFI_ReleaseOpFileOrderBuf(
	IN		PNPC_S_MPI_MON_FILE_OP_ORDER		in_pFileOpOrder				//[IN]文件操作命令，由NPC_F_MPI_MON_SFI_GetOpFileOrder函数创建的缓冲区
	);

#ifdef _WIN32
//启动文件读写线程
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_SFI_StartFileReadWriteThread();

//关闭文件读写线程
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_SFI_StopFileReadWriteThread();
#endif



//------------------------------------------------------------------------------------------------------
//获取定制的配置参数表，返回配置列表句柄，如果为NULL，表示调用失败，配置参数的数据结构为NPC_S_MPI_MON_CLIENT_CONFIG_DATA_V2
//列表访问请参考NPC_TOOLS_List.h文件的函数，上层需要释放该列表。（该函数可以在未登录情况下调用）
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_GetCustomConfigTable(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iClientType,				//[IN]客户端类型，参见NPC_D_MON_CLIENT_TYPE_*定义
	IN		PNPC_CHAR							in_pClientId,				//[IN]客户端ID
	IN		PNPC_CHAR							in_pCustomFlag				//[IN]定制标识
	);

//获取定制的厂商列表，返回厂商列表句柄，如果为NULL，表示调用失败，厂商定义的数据结构为NPC_S_MPI_MON_CLIENT_VENDOR_CFG_DATA
//列表访问请参考NPC_TOOLS_List.h文件的函数，上层需要释放该列表。（该函数可以在未登录情况下调用）
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_GetCustomVendorTable(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		NPC_INT								in_iClientType,				//[IN]客户端类型，参见NPC_D_MON_CLIENT_TYPE_*定义
	IN		PNPC_CHAR							in_pClientId,				//[IN]客户端ID
	IN		PNPC_CHAR							in_pCustomFlag				//[IN]定制标识
	);


//------------------------------------------------------------------------------------------------------
//查询系统消息列表，返回列表句柄，必须调用NPC_F_MPI_MON_CLT_SysMsgList_ReleaseSysMsgList函数释放列表
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_SysMsgList_QuerySysMsgList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pCustomFlag,				//[IN]定制标识
	OUT		PNPC_INT							out_pMsgNum					//[IN]消息数
	);

//移动到第一条消息（初始为第一条消息）
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SysMsgList_MoveFirstMsg(
	IN		NPC_HANDLE							in_hSysMsgList				//[IN]系统消息列表
	);

//获取下一条消息，返回TRUE表示有，FALSE表示没有
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_SysMsgList_GetNextMsg(
	IN		NPC_HANDLE							in_hSysMsgList,				//[IN]系统消息列表
	OUT		PNPC_S_MPI_MON_SYSTEM_MSG			out_pSysMsg					//[OUT]系统消息
	);

//释放系统消息列表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_SysMsgList_ReleaseSysMsgList(
	IN		NPC_HANDLE							in_hSysMsgList				//[IN]系统消息列表
	);


//------------------------------------------------------------------------------------------------------
//查询演示点列表，返回列表句柄，必须调用NPC_F_MPI_MON_CLT_DemoList_ReleaseList函数释放列表
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_DemoList_QueryVideodemoList(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pCustomFlag,				//[IN]定制标识
	IN		NPC_INT								in_iLangKind,				//[IN]语言种类，参见NPC_D_MON_LAND_KIND_*定义
	OUT		PNPC_CHAR							out_pStreamSrvIpaddr,		//[OUT]流媒体服务器IP地址
	OUT		PNPC_USHORT							out_pStreamSrvPort,			//[OUT]流媒体服务器端口号
	OUT		PNPC_INT							out_pDevNum					//[OUT]设备数
	);

//移动到第一条设备（初始为第一条设备）
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DemoList_MoveFirstDev(
	IN		NPC_HANDLE							in_hDemoDevList				//[IN]演示点列表
	);

//获取下一条设备，返回TRUE表示有，FALSE表示没有
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_DemoList_GetNextDev(
	IN		NPC_HANDLE							in_hDemoDevList,			//[IN]演示点列表
	OUT		PNPC_S_MPI_MON_VIDEO_DEMO_DEV_DATA	out_pDevData				//[OUT]设备数据
	);

//释放演示点列表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_DemoList_ReleaseList(
	IN		NPC_HANDLE							in_hDemoDevList				//[IN]演示点列表
	);


//------------------------------------------------------------------------------------------------------
//查询摄像机缩略图URL
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_THUMB_QueryCameraThumbUrl(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pCameraId,				//[IN]摄像机ID
	OUT		PNPC_CHAR							out_pThumbUrl,				//[OUT]缩略图URL
	OUT		PNPC_BOOL							out_pIfEnable				//[OUT]是否启用
	);

//请求上传摄像机缩略图
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_THUMB_RequUpCameraThumbUrl(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pCameraId,				//[IN]摄像机ID
	OUT		PNPC_CHAR							out_pThumbUrl,				//[OUT]缩略图URL
	OUT		PNPC_BOOL							out_pIfEnable				//[OUT]是否启用
	);

//查询用户的所有摄像机缩略图URL，返回列表句柄
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_CLT_THUMB_QueryUserAllCameraThumbUrl(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pUserId					//[IN]用户ID
	);

//移动到第一条URL（初始为第一条）
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_THUMB_MoveFirst(
	IN		NPC_HANDLE							in_hThumbUrlList			//[IN]缩略图URL列表句柄
	);

//获取下一个缩略图URL，返回TRUE表示获取成功，FALSE表示没有记录
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_THUMB_GetNext(
	IN		NPC_HANDLE							in_hThumbUrlList,			//[IN]缩略图URL列表句柄
	OUT		PNPC_CHAR							out_pCameraId,				//[OUT]摄像机ID
	OUT		PNPC_CHAR							out_pThumbUrl,				//[OUT]缩略图URL
	OUT		PNPC_BOOL							out_pIfEnable				//[OUT]是否启用
	);

//释放缩略图URL列表
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_CLT_THUMB_ReleaseList(
	IN		NPC_HANDLE							in_hThumbUrlList			//[IN]缩略图URL列表句柄
	);

//设置摄像机缩略图URL是否可用
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_CLT_THUMB_SetCameraThumbUrlIfEnable(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄
	IN		PNPC_CHAR							in_pCameraId,				//[IN]摄像机ID
	IN		NPC_BOOL							in_bIfEnable				//[IN]是否启用
	);


//------------------------------------------------------------------------------------------------------
//转换time_t时间值为字符串
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_SNH_Timet2Str(
	IN		NPC_TIME_T							in_tTimeValue,				//[IN]时间值
	OUT		PNPC_CHAR							out_pTimeStr				//[OUT]时间字符串
	);

//转换字符串时间为time_t
NPC_MPI_MON_API		NPC_TIME_T	NPC_F_MPI_MON_SNH_Str2Timet(
	IN		PNPC_CHAR							in_pTimeStr					//[IN]时间字符串
	);


//-------------------------------------------------------------------------------------------
//启动报警消息接收服务
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_AS_StartAlarmRecvServer(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]服务器地址
	IN		NPC_USHORT							in_usServerPort,			//[IN]服务器端口号，如8300
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID
	IN		NPC_INT								in_iClientType,				//[IN]客户端类型，参见NPC_D_MON_CLIENT_TYPE_*定义
	IN		PNPC_CHAR							in_pClientId,				//[IN]客户端ID（或客户端标识，如IMSI等）
	IN		PNPC_CHAR							in_pClientOwner,			//[IN]客户端使用者
	IN		PNPC_CHAR							in_pClientLanguage,			//[IN]客户端语言，如：英文：English，简体中文：SimpChinese
	IN		PNPC_CHAR							in_pClientCustomFlag		//[IN]客户端定制标识
	);

//停止报警消息接收服务
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_AS_StopAlarmRecvServer(
	IN		NPC_HANDLE							in_hAlarmRecvServer			//[IN]报警消息接收服务句柄
	);

//获取推送消息，返回TRUE表示有推送消息，FALSE表示没有
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_AS_GetAlarmMsg(
	IN		NPC_HANDLE							in_hAlarmRecvServer,		//[IN]报警消息接收服务句柄
	OUT		PNPC_S_MPI_MON_PUSH_MSG_DATA		out_pPushMsgData,			//[OUT]推送消息数据
	IN		NPC_INT								in_iTimeout					//[IN]等待超时时长（毫秒）
	);

//查询服务器连接状态
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_AS_QuerySrvConnState(
	IN		NPC_HANDLE							in_hAlarmRecvServer,		//[IN]报警消息接收服务句柄
	OUT		PNPC_INT							out_pSrvConnState			//[OUT]服务器连接状态，0：未连接，1：正在连接，2：已连接
	);

//是否需要显示跟踪信息，缺省为不显示
NPC_MPI_MON_API		NPC_BOOL	NPC_F_MPI_MON_AS_IfShowInfoTraceInfo(
	IN		NPC_HANDLE							in_hAlarmRecvServer,		//[IN]报警消息接收服务句柄
	IN		NPC_BOOL							in_bIfShowTraceInfo			//[IN]是否显示跟踪信息
	);



//----------------------------------------------------------------------------------------
//创建监控客户端并连接服务器，需要调用NPC_F_MPI_MON_HNP_DestroyClient销毁客户端对象
NPC_MPI_MON_API		NPC_HANDLE	NPC_F_MPI_MON_HNP_CreateClient(
	IN		PNPC_CHAR							in_pServerAddr,				//[IN]服务器IP地址或域名
	IN		NPC_USHORT							in_usServerPort,			//[IN]服务器端口号，如8300
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID
	IN		NPC_INT								in_iClientType,				//[IN]客户端类型，参见NPC_D_MON_CLIENT_TYPE_*定义
	IN		PNPC_CHAR							in_pClientId,				//[IN]客户端ID
	OUT		PNPC_INT							out_pFailCode				//[OUT]失败码（参见NPC_D_MPI_MON_ERROR_*定义），返回值为NULL时，该参数有效
	);

//销毁监控客户端对象，则NPC_F_MPI_MON_HNP_CreateClient函数创建的客户端对象
NPC_MPI_MON_API		NPC_VOID	NPC_F_MPI_MON_HNP_DestroyClient(
	IN		NPC_HANDLE							in_hMonClient				//[IN]客户端句柄
	);


//修改用户密码，返回0表示成功，其它表示失败，失败码参见NPC_D_MPI_MON_ERROR_*定义
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_HNP_ModifyUserPwd(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄，由NPC_F_MPI_MON_HNP_CreateClient该函数创建的客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID，即用户帐号
	IN		PNPC_CHAR							in_pOldPwd,					//[IN]原密码
	IN		PNPC_CHAR							in_pNewPwd					//[IN]新密码
	);

//查询注册帐号的邮箱，即注册时接收验证码的邮箱，返回0表示成功，其它表示失败，失败码参见NPC_D_MPI_MON_ERROR_*定义
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_HNP_QueryRegEmail(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄，由NPC_F_MPI_MON_HNP_CreateClient该函数创建的客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID
	OUT		PNPC_CHAR							out_pRegEmail				//[OUT]注册邮箱
	);

//发送重置密码邮件，返回0表示成功，其它表示失败，失败码参见NPC_D_MPI_MON_ERROR_*定义
NPC_MPI_MON_API		NPC_INT		NPC_F_MPI_MON_HNP_SendResetPasswordEmail(
	IN		NPC_HANDLE							in_hMonClient,				//[IN]客户端句柄，由NPC_F_MPI_MON_HNP_CreateClient该函数创建的客户端句柄
	IN		PNPC_CHAR							in_pUserId,					//[IN]用户ID
	IN		PNPC_CHAR							in_pSendLanguage			//[IN]发送语言，如：英文：English，简体中文：SimpChinese
	);


// C++ support
#ifdef __cplusplus
}
#endif

#endif

