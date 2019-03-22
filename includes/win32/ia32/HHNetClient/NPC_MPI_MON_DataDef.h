/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_DataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-08
 * Description   :  监控客户端通讯接口定义
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_DATADEF_H
#define __NPC_MPI_MON_DATADEF_H

#include "NPC_TypeDef.h"
#include "NPC_MON_DataDef.h"
#include "NPC_MON_VendorDef.h"
#include "NPC_MPI_MON_VarDataDef.h"
//#include "vld.h"

//导出导入定义
#ifdef _WIN32
	#ifdef _NPC_MPI_MON_EXPORTS
		#define NPC_MPI_MON_API __declspec(dllexport)
	#else
		#ifdef _NPC_MPI_MON_IMPORT
			#define NPC_MPI_MON_API __declspec(dllimport)
		#else
			#define NPC_MPI_MON_API
		#endif
	#endif
#else
	#define NPC_MPI_MON_API
#endif


//常量定义
#define NPC_D_MPI_MON_CH_NAME_BUFSIZE							128			//通道名缓冲区大小
#define NPC_D_MPI_MON_DEVID_BUFSIZE								NPC_D_MON_NODEID_BUFSIZE	//设备ID缓冲区大小
#define NPC_D_MPI_MON_CAMERANAME_BUFSIZE						64			//摄像机名称缓冲区大小
#define NPC_D_MPI_MON_CAMERA_DIRNAME_BUFSIZE					128			//摄像机目录名缓冲区大小
#define NPC_D_MPI_MON_NODENAME_BUFSIZE							32			//结点名称缓冲区大小
#define NPC_D_MPI_MON_MAX_ERROR_BUFSIZE							512			//最大错误信息缓冲区大小
#define NPC_D_MPI_MON_MAX_USER_POP_NUM							64			//最大用户权限数
#define NPC_D_MPI_MON_MAX_USER_DEVPOP_NUM						64			//最大用户设备权限数
#define NPC_D_MPI_MON_MAX_VENDOR_CP_FIELD_NUM					8			//最大厂商连接参数字段数
#define NPC_D_MPI_MON_NODENAME_BUFSIZE							32			//结点名缓冲区大小
#define NPC_D_MPI_MON_USERID_BUFSIZE							32			//用户ID缓冲区大小
#define NPC_D_MPI_MON_MAX_ALARM_NOTIFY_NUM						20			//最大报警通知数
#define NPC_D_MPI_MON_MAX_ALARM_ACTION_NUM						6			//最大报警联动数
#define NPC_D_MPI_MON_SEARCH_MAX_ADAPTER_NUM					5			//最大网卡数

//连接模式定义
#define NPC_D_MPI_MON_COM_CONNMODE_DIRECT						0			//直连模式，即给出对端IP地址和端口，直接连接对端
#define NPC_D_MPI_MON_COM_CONNMODE_SERVER						1			//服务器管理模式，即由服务器管理连接对端，可能为NAT、中转、直连等

//设备目录结点类型
#define NPC_D_MPI_MON_DEV_NODE_TYPE_DIR							0			//目录名
#define NPC_D_MPI_MON_DEV_NODE_TYPE_DVR							1			//DVR
#define NPC_D_MPI_MON_DEV_NODE_TYPE_CAMERA						2			//摄像机
#define NPC_D_MPI_MON_DEV_NODE_TYPE_IPC							3			//IPC

//设备结点状态
#define NPC_D_MPI_MON_DEV_NODE_STATE_OFFLINE					0			//离线
#define NPC_D_MPI_MON_DEV_NODE_STATE_ONLINE						1			//在线

//推送消息类型
#define NPC_D_MPI_MON_PUSH_TYPE_CONFIG							1			//配置参数
#define NPC_D_MPI_MON_PUSH_TYPE_ORDER							2			//服务器推送命令
#define NPC_D_MPI_MON_PUSH_TYPE_PROMPT							3			//服务器推送提示消息
#define NPC_D_MPI_MON_PUSH_TYPE_DEVN_UPDATE_NODE				4			//服务器推送设备变更：更新结点（添加、修改）
#define NPC_D_MPI_MON_PUSH_TYPE_DEVN_DEL_NODE					5			//服务器推送设备变更：删除结点（设备或目录
#define NPC_D_MPI_MON_PUSH_TYPE_UPDATE_GPOP						6			//服务器推送全局权限变更
#define NPC_D_MPI_MON_PUSH_TYPE_DEV_ALARM						7			//服务器推送设备报警消息
#define NPC_D_MPI_MON_PUSH_TYPE_DEV_ALARM_VILLAGE				8			//服务器推送设备报警消息（小区报警）
#define NPC_D_MPI_MON_PUSH_TYPE_REQU_REFRESH_DEVLIST			9			//请求上层刷新设备列表
//#define NPC_D_MPI_MON_PUSH_TYPE_PWD_MODIFYED					10			//密码被其它用户修改
#define NPC_D_MPI_MON_PUSH_TYPE_RE_LOGIN_NOTIFY					10			//重新登录通知
#define NPC_D_MPI_MON_PUSH_TYPE_ANNO_MSG						11			//服务器推送公告消息

//客户端连接状态
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_NO_CONNECT				0			//未连接服务器
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_CONNECTING				1			//正在连接服务器
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_CONNECT_OK				2			//已连接服务器但未登录
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_LOGIN_OK				3			//已登录状态并连接正常
#define NPC_D_MPI_MON_CLIENT_CONN_STATE_DISCONNECT				4			//连接断开状态

//摄像机连接状态
#define NPC_D_MPI_MON_CAMERA_CONN_STATE_NO_CONNECT				0			//未连接状态
#define NPC_D_MPI_MON_CAMERA_CONN_STATE_CONNECTING				1			//正在连接摄像机
#define NPC_D_MPI_MON_CAMERA_CONN_STATE_CONNECT_OK				2			//已连接并登录状态
#define NPC_D_MPI_MON_CAMERA_CONN_STATE_DISCONNECT				3			//连接断开状态，断开原因参考NPC_D_MPI_MON_CAMERA_DISCAUSE_*定义

//摄像机播放状态（包括实时预浏览和录像回放）
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_NOPLAY					0			//未播放状态
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_PLAYING					1			//正在播放状态
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_PAUSE					2			//暂停状态
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_OPENING					3			//正在打开播放
#define NPC_D_MPI_MON_CAMERA_PLAY_STATE_REJECT_ACCESS			4			//无权限

//客户端断开连接原因
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_PEER_CLOSE				1			//对端关闭连接
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_LOGIN_FAIL				2			//登录失败而断开连接
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_RECV_ERR_PACK				3			//接收到错误数据包而本端主动关闭连接
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_RESP_TIMEOUT				4			//等待应答消息超时而本端主动关闭连接
#define NPC_D_MPI_MON_CLIENT_DISCAUSE_HEART_TIMEOUT				5			//等待心跳应答消息超时而本端主动关闭连接

//摄像机断开连接原因
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_PEER_CLOSE				1			//对端关闭连接
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_LOGIN_FAIL				2			//登录失败而断开连接
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_RECV_ERR_PACK				3			//接收到错误数据包而本端主动关闭连接
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_RESP_TIMEOUT				4			//等待应答消息超时而本端主动关闭连接
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_HEART_TIMEOUT				5			//等待心跳应答消息超时而本端主动关闭连接
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_NON_MEDIA_DATA			6			//长时间无媒体流而本端主动关闭连接
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_DEV_DISCONNECT			7			//设备端断开了连接
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_USERNAME_ERROR			8			//用户名错误
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_PWD_ERROR					9			//密码错误
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_USERNAMEPWD_ERROR			10			//用户名或密码错误
#define NPC_D_MPI_MON_CAMERA_DISCAUSE_DEV_OFFLINE				11			//设备离线

//摄像机下载文件状态
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_INIT					0			//初始状态
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_OPENING					1			//正在打开状态
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_DOWNING					2			//正在下载状态
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_DOWN_OVER				3			//下载完必状态
#define NPC_D_MPI_MON_CAMERA_DOWN_STATE_OPEN_FAIL				4			//打开失败状态

//重新登录的原因定义
#define NPC_D_MPI_MON_RELOGIN_CAUSE_USER_ERROR					1			//用户名错误
#define NPC_D_MPI_MON_RELOGIN_CAUSE_PWD_ERROR					2			//密码错误
#define NPC_D_MPI_MON_RELOGIN_CAUSE_USER_OR_PWD_ERROR			3			//用户名或密码错误
#define NPC_D_MPI_MON_RELOGIN_CAUSE_ACCOUNT_NO_ACTIVE			4			//用户帐号未激活
#define NPC_D_MPI_MON_RELOGIN_CAUSE_HAVE_EXPIRED				5			//用户帐号已过有效期
#define NPC_D_MPI_MON_RELOGIN_CAUSE_CLIENTID_NOT_ALLOW_LOGIN	6			//客户端ID不允许登录
#define NPC_D_MPI_MON_RELOGIN_CAUSE_REJECT_LOGIN				7			//拒绝登录（IP地址不允许登录）
#define NPC_D_MPI_MON_RELOGIN_CAUSE_OTHER						99			//其它原因

//设备连接服务器状态定义
#define NPC_D_MPI_MON_DEV_SRV_CONN_STATE_NON_CONNECT			0			//未连接
#define NPC_D_MPI_MON_DEV_SRV_CONN_STATE_CONNECTING				1			//正在连接
#define NPC_D_MPI_MON_DEV_SRV_CONN_STATE_CONNECT_OK				2			//已连接
#define NPC_D_MPI_MON_DEV_SRV_CONN_STATE_CONNECT_FAIL			3			//连接失败

//设备连接服务器的失败码定义
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_SUCCESS			0			//成功
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_DNS_FAIL			1			//域名解析失败（可能为设备未接入公网，或者域名错误）
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_CONN_SRV_FAIL		2			//连接服务器失败（可能为服务器未运行，或者防火墙阻止了通讯）
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_LOGIN_AUTH_FAIL	3			//登录认证失败（可能是UMID未授权，或认证码错误）
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_UMID_REGISTERED	4			//UMID已经注册（UMID被其它设备注册到服务器）
#define NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_OTHER_FAIL			99			//其它失败

//错误码定义
#define NPC_D_MPI_MON_ERROR_SUCCESS								0			//成功

#define NPC_D_MPI_MON_ERROR_SYS_ERROR							1			//系统错误
#define NPC_D_MPI_MON_ERROR_CONNECT_FAIL						2			//连接失败
#define NPC_D_MPI_MON_ERROR_DBACCESS_FAIL						3			//访问数据库失败
#define NPC_D_MPI_MON_ERROR_ALLOC_RES_FAIL						4			//分配资源失败
#define NPC_D_MPI_MON_ERROR_INNER_OP_FAIL						5			//内部操作失败，如内存操作失败
#define NPC_D_MPI_MON_ERROR_EXEC_ORDER_CALL_FAIL				6			//执行命令调用失败
#define NPC_D_MPI_MON_ERROR_EXEC_ORDER_RET_FAIL					7			//执行命令结果失败
#define NPC_D_MPI_MON_ERROR_FILE_NONENTITY						8			//文件不存在
#define NPC_D_MPI_MON_ERROR_OTHER_FAIL							9			//其它原因失败
#define NPC_D_MPI_MON_ERROR_NET_ERROR							10			//网络错误
#define NPC_D_MPI_MON_ERROR_REDIRECT							11			//服务器请求客户端重定向
#define NPC_D_MPI_MON_ERROR_PARAM_ERROR							12			//传入参数格式错误
#define NPC_D_MPI_MON_ERROR_ERROR_FUNCID						13			//错误的功能ID消息
#define NPC_D_MPI_MON_ERROR_MSG_PAST_TIME						14			//该消息ID已过时，即已作废
#define NPC_D_MPI_MON_ERROR_SYS_NO_GRANT						15			//系统未授权
#define NPC_D_MPI_MON_ERROR_DNS_FAIL							16			//解析域名失败
#define NPC_D_MPI_MON_ERROR_USERNAME_FORMAT_ERROR				17			//用户名格式错误
#define NPC_D_MPI_MON_ERROR_RESP_TIMEOUT						18			//等待应答消息超时
#define NPC_D_MPI_MON_ERROR_PROTOCOL_ERROR						19			//协议错误

#define NPC_D_MPI_MON_ERROR_USERID_ERROR						101			//用户ID或用户名错误
#define NPC_D_MPI_MON_ERROR_USERPWD_ERROR						102			//用户密码错误
#define NPC_D_MPI_MON_ERROR_USER_PWD_ERROR						103			//用户名或密码错误
#define NPC_D_MPI_MON_ERROR_CONNECTING							104			//正在连接
#define NPC_D_MPI_MON_ERROR_CONNECTED							105			//已连接
#define NPC_D_MPI_MON_ERROR_PLAY_FAIL							106			//播放失败
#define NPC_D_MPI_MON_ERROR_NO_CONNECT_CAMERA					107			//未连接摄像机
#define NPC_D_MPI_MON_ERROR_PLAYING								108			//正在播放
#define NPC_D_MPI_MON_ERROR_NO_PLAY								109			//未播放
#define NPC_D_MPI_MON_ERROR_NONSUP_VENDOR						110			//不支持的厂家
#define NPC_D_MPI_MON_ERROR_REJECT_ACCESS						111			//权限不够
#define NPC_D_MPI_MON_ERROR_CAMERA_OFFLINE						112			//摄像机离线
#define NPC_D_MPI_MON_ERROR_ACCOUNT_LOGINED						113			//帐号已登录
#define NPC_D_MPI_MON_ERROR_ACCOUNT_HAVE_EXPIRED				114			//用户帐号已过有效期
#define NPC_D_MPI_MON_ERROR_ACCOUNT_NO_ACTIVE					115			//用户帐号未激活
#define NPC_D_MPI_MON_ERROR_ACCOUNT_DEBT_STOP					116			//用户帐号已欠费停机
#define NPC_D_MPI_MON_ERROR_USER_EXIST							117			//用户已注册
#define NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_NOPERM				118			//不允许注册（不在许可表中）
#define NPC_D_MPI_MON_ERROR_NOT_ALLOW_REG_ATBLACK				119			//不允许注册（在黑名单中）
#define NPC_D_MPI_MON_ERROR_SECCODE_HAVE_EXPIRED				120			//验证码已过期
#define NPC_D_MPI_MON_ERROR_SECCODE_ERROR						121			//验证码错误
#define NPC_D_MPI_MON_ERROR_ACCOUNT_EXIST						122			//帐号已存在
#define NPC_D_MPI_MON_ERROR_NO_IDLE_STREAMSERVER				123			//无空闲流媒体服务器
#define NPC_D_MPI_MON_ERROR_USER_NO_LOGIN						124			//用户未登录
#define NPC_D_MPI_MON_ERROR_ACCOUNT_LEN_ERROR					125			//帐号长度错误
#define NPC_D_MPI_MON_ERROR_EMP_ACC_USERID_NOT_EXIST			126			//接收授权的用户ID不存在
#define NPC_D_MPI_MON_ERROR_IPADDR_BAN_LOGIN					127			//IP地址禁止登录
#define NPC_D_MPI_MON_ERROR_CLIENTID_NOT_ALLOW_LOGIN			128			//客户端ID不允许登录
#define NPC_D_MPI_MON_ERROR_TIMESECT_NOT_ALLOW_CAMERA			129			//该时间段不允许访问该摄像机
#define NPC_D_MPI_MON_ERROR_VOD_FILE_NOT_EXIST					130			//VOD文件不存在
#define NPC_D_MPI_MON_ERROR_REJECT_LOGIN						131			//拒绝登录
#define NPC_D_MPI_MON_ERROR_OBJ_NOT_EXIST						132			//查询对象不存在
#define NPC_D_MPI_MON_ERROR_NO_SUBSCRIBE						133			//没有订阅
#define NPC_D_MPI_MON_ERROR_RESOURCE_USED						134			//资源已被占用
#define NPC_D_MPI_MON_ERROR_RESOURCE_NOT_OPEN					135			//资源已未被打开
#define NPC_D_MPI_MON_ERROR_SUCCESS_AND_RESTART					136			//操作成功，但需要重启设备才生效
#define NPC_D_MPI_MON_ERROR_OPNO_DEVGROUP						137			//设备组下的结点不能操作
#define NPC_D_MPI_MON_ERROR_RESOURCE_NO_IDLE					138			//无空闲资源可使用
#define NPC_D_MPI_MON_ERROR_RESOURCE_NOT_EXIST					139			//资源不存在
#define NPC_D_MPI_MON_ERROR_RESOURCE_OPEN_FAIL					140			//打开资源失败
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_OP						141			//不支持该操作
#define NPC_D_MPI_MON_ERROR_BAN_MODIFY							142			//禁止修改
#define NPC_D_MPI_MON_ERROR_OPEN_STREAM_FAIL					143			//打开媒体流失败（打开实时预览失败）
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_SUBSTREAM				144			//不支持该子码流
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_PTZ						145			//不支持云台控制
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_FORCE_I_FRAME			146			//不支持强制I帧
#define NPC_D_MPI_MON_ERROR_NOT_SUPPORT_TALK					147			//不支持语音对讲
#define NPC_D_MPI_MON_ERROR_FILE_OP_FAIL						148			//文件操作失败
#define NPC_D_MPI_MON_ERROR_ID_ERROR							149			//ID错误
#define NPC_D_MPI_MON_ERROR_CHANNEL_NO_ERROR					150			//通道号错误
#define NPC_D_MPI_MON_ERROR_SUB_STREAM_NO_ERROR					151			//子码流号错误
#define NPC_D_MPI_MON_ERROR_START_TALK_FAIL						152			//启动对讲失败



//自定义错误码范围：6150~6179，对应协议的错误码为150~179，即该错误码减去6000，等于设备端返回的错误值


//-------------------------------------------------------------------------------------
//通道信息定义
typedef struct _NPC_S_MPI_MON_CHANNEL_INFO
{	
	NPC_CHAR									sDevId[NPC_D_MPI_MON_DEVID_BUFSIZE];			//设备ID
	NPC_INT										iChNo;											//通道号，如果为0xFFFFFFFF表示所有通道，此时不用理会通道名称只管设置参数即可
	NPC_CHAR									sChName[NPC_D_MPI_MON_CH_NAME_BUFSIZE];			//全为0就不用理会表示不用设置
	NPC_INT										iRecordBitRate;									//录像单位bit，如果是少于10的值 代表画质 1差 2中 3好
	NPC_INT										iVideoBitRate;									//预览单位bit，如果是少于10的值 代表画质 1差 2中 3好
	NPC_BYTE									ucRecordFramesize;								//byte 1 2 3 4 5 分别对应qcif qvga cif hd1 d1
	NPC_BYTE									ucRecordFrameRate;								//帧率 1-25
	NPC_BYTE									ucVideoFramesize;								//byte 1 2 3 4 5 分别对应qcif qvga cif hd1 d1
	NPC_BYTE									ucVideoFrameRate;								//帧率 1-25
	NPC_BYTE									ucAlarmonordown;								//0为关闭 1为打开
	NPC_BYTE									ucVideoPorn;									//0为P制 1为N制 暂时不用
	NPC_BYTE									ucSupportSize[5];								//SupportSize[0]代表qcif 如果是支持就设置为1不支持设置为0 以此类推 这个是在设备返回给客户端有用，客户端设置到DVR上不用理会
	NPC_BYTE									ucReserve[2];

} NPC_S_MPI_MON_CHANNEL_INFO, *PNPC_S_MPI_MON_CHANNEL_INFO;

//帧数据定义
typedef struct _NPC_S_MPI_MON_MEDIA_FRAME
{
	NPC_S_MON_MEDIA_FRAME_HEAD					tMediaHead;										//媒体头

	PNPC_BYTE									pMediaDataBuf;									//媒体数据缓冲区
	NPC_INT										iMediaDataLen;									//媒体数据长度

} NPC_S_MPI_MON_MEDIA_FRAME, *PNPC_S_MPI_MON_MEDIA_FRAME;

//报警数据定义
typedef struct _NPC_S_MPI_MON_ALARM_HEAD
{
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//设备ID
	NPC_INT										iAlarmType;										//报警类型，参见NPC_D_MON_ALARM_TYPE_*定义
	NPC_S_TD_DATE_TIME							tAlarmTime;										//报警时间
	NPC_INT										iAlarmState;									//报警状态，0：开始，1：停止
	NPC_DWORD									dwParam1;										//扩展参数1
	NPC_DWORD									dwParam2;										//扩展参数2

} NPC_S_MPI_MON_ALARM_HEAD, *PNPC_S_MPI_MON_ALARM_HEAD;

//报警数据定义
typedef struct _NPC_S_MPI_MON_ALARM_DATA
{
	NPC_S_MPI_MON_ALARM_HEAD					tAlarmHead;										//报警头

	PNPC_CHAR									pAlarmInfoBuf;									//报警信息缓冲区
	NPC_INT										iAlarmInfoLen;									//报警信息长度

} NPC_S_MPI_MON_ALARM_DATA, *PNPC_S_MPI_MON_ALARM_DATA;

//录像文件数据定义
typedef struct _NPC_S_MPI_MON_REC_FILE
{
	NPC_CHAR									sFileName[NPC_D_MON_FILENAME_BUFSIZE];			//文件名
	NPC_DWORD									dwFileSize;										//文件大小
	NPC_DWORD									dwFileType;										//文件类型，参见NPC_D_MON_REC_FILE_TYPE_*定义
	NPC_S_TD_DATE_TIME							tStartTime;										//文件开始时间
	NPC_S_TD_DATE_TIME							tEndTime;										//文件结束时间
	NPC_DWORD									dwRecTimeLen;									//文件时间（秒）
	NPC_USHORT									usFileFormat;									//文件格式，参见NPC_D_MON_FILE_FORMAT_*定义
	NPC_USHORT									usParam1;										//扩展参数1
	NPC_DWORD									dwParam2;										//扩展参数2

} NPC_S_MPI_MON_REC_FILE, *PNPC_S_MPI_MON_REC_FILE;

//设备结点数据
typedef struct _NPC_S_MPI_MON_DEV_NODE
{
	NPC_DWORD									dwNodeId;										//结点ID，值大于0
	NPC_DWORD									dwParentNodeId;									//上级结点ID，如果为0，表示查询顶层结点
	NPC_INT										iNodeType;										//结点类型，参见NPC_D_MPI_MON_DEV_NODE_TYPE_*定义
	NPC_BYTE									ucNodeKind;										//结点种类，用于结点显示的图标种类，值从0开始
	NPC_USHORT									usVendorId;										//厂商ID
	NPC_BYTE									ucNodeOwnerType;								//结点所属类型，0：用户ID，1：设备组ID，2：授权设备
	NPC_CHAR									sNodeName[128];									//显示名称
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//设备ID（如摄像机ID）

	NPC_BYTE									ucIfPtz;										//是否支持PTZ，0：不支持PTZ，1：支持PTZ
	NPC_BYTE									ucIfVocTalk;									//是否支持语音对讲，0：不支持语音对讲，1：支持语音对讲
	NPC_BYTE									ucIfLongLat;									//是否设置经纬度，0：未设置经纬度，1：已设置经纬度，值参考iLongitude和iLatitude字段
	NPC_BYTE									ucDevState;										//设备状态，0：离线，1：在线
	NPC_BYTE									ucIfRecording;									//是否在录像，0：未录像，1：在录像
	NPC_BYTE									ucIfArming;										//是否布防，0：未布防，1：已布防
	NPC_BYTE									ucReserve2[2];									//备用2

	NPC_INT										iLongitude;										//经度，低6位为小数部分，其它为整数部分，值范围为-180000000~180000000
	NPC_INT										iLatitude;										//纬度，低6位为小数部分，其它为整数部分，值范围为-90000000~90000000
	NPC_BYTE									ucDevPopTable[NPC_D_MPI_MON_MAX_USER_DEVPOP_NUM];	//用户对该设备的权限，如果值为0表示没有权限，值参考NPC_D_MPI_MON_USER_POP_定义
	NPC_INT										iDevPopNum;										//设备权限数
	NPC_INT										iPromptId;										//提示消息ID，值大于0，为0表示没有提示消息

} NPC_S_MPI_MON_DEV_NODE, *PNPC_S_MPI_MON_DEV_NODE;

//PTZ名称数据
typedef struct _NPC_S_MPI_MON_PTZ_NAME
{
	NPC_INT										iPtzType;										//PTZ类型，0：预置点，1：巡航路径
	NPC_INT										iPtzIndex;										//PTZ号，即预置点号或巡航路径号，预置点号值范围为1至255，巡航路径号值范围为1至32
	NPC_CHAR									sPtzName[32];									//PTZ名称，指预置点或巡航路径的名称，最大15个汉字或31个字符

} NPC_S_MPI_MON_PTZ_NAME, *PNPC_S_MPI_MON_PTZ_NAME;

//设备信息
typedef struct _NPC_S_MPI_MON_DEV_INFO
{
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//设备ID（如摄像机ID）
	NPC_INT										iConnMode;										//连接模式，参见NPC_D_MON_DEV_CONN_MODE_*定义
	NPC_DWORD									dwVendorId;										//厂商ID
	NPC_CHAR									sConnParam[NPC_D_MON_DEV_CONN_PARAM_BUFSIZE];	//连接参数
	NPC_CHAR									sDevPlace[512];									//设备位置
	NPC_BOOL									bIfPtz;											//是否支持PTZ
	NPC_BOOL									bIfLongLat;										//是否设置经纬度
	NPC_INT										iLongitude;										//经度，低6位为小数部分，其它为整数部分，值范围为-180000000~180000000
	NPC_INT										iLatitude;										//纬度，低6位为小数部分，其它为整数部分，值范围为-90000000~90000000
	NPC_INT										iDevState;										//设备状态,0:离线,1:在线
	NPC_BOOL									bIfRecording;									//是否在录像
	NPC_BOOL									bIfRealplaying;									//是否在实时预览

} NPC_S_MPI_MON_DEV_INFO, *PNPC_S_MPI_MON_DEV_INFO;

//设备列表项数据
typedef struct _NPC_S_MPI_MON_DEV_LIST_ITEM
{
	NPC_DWORD									dwVendorId;										//厂商ID
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//设备ID（如摄像机ID）

} NPC_S_MPI_MON_DEV_LIST_ITEM, *PNPC_S_MPI_MON_DEV_LIST_ITEM;

//用户登录附带参数
typedef struct _NPC_S_MPI_MON_USER_LOGIN_PR_IN_PARAM
{
	NPC_INT										iClientType;									//客户端类型，参见NPC_D_MON_CLIENT_TYPE_*定义
	NPC_CHAR									sDevVendorName[32];								//设备厂商名称
	NPC_CHAR									sDevName[32];									//设备产品名称
	NPC_CHAR									sDevModel[32];									//设备型号
	NPC_CHAR									sDevVersion[32];								//设备版本号
	NPC_CHAR									sDevCPUModel[32];								//设备CPU型号
	NPC_DWORD									dwDevMemorySize;								//设备内存大小（MB）
	NPC_DWORD									dwDevStorageSize;								//设备存储大小（MB），如硬盘或闪存
	NPC_CHAR									sDevNetInfo[32];								//设备网络信息
	NPC_CHAR									sDevParam1[32];									//设备参数1
	NPC_CHAR									sDevParam2[32];									//设备参数2
	NPC_CHAR									sDevParam3[32];									//设备参数3
	NPC_CHAR									sDevInfo[64];									//设备其它信息

	NPC_CHAR									sClientOwner[32];								//客户端使用者
	NPC_CHAR									sClientLanguage[32];							//客户端语言，如：英文：English，简体中文：SimpChinese
	NPC_CHAR									sClientCustomFlag[32];							//客户端定制标识
	NPC_CHAR									sClientToken[128];								//客户端TOKEN

	NPC_CHAR									sReserve[224];									//备用

	NPC_CHAR									sClientVerNo[32];								//客户端软件版本号

} NPC_S_MPI_MON_USER_LOGIN_PR_IN_PARAM, *PNPC_S_MPI_MON_USER_LOGIN_PR_IN_PARAM;

//用户登录返回附带参数
typedef struct _NPC_S_MPI_MON_USER_LOGIN_PR_OUT_PARAM
{
	NPC_BOOL									bIfAllPop;										//是否有全部权限
	NPC_BYTE									ucUserPopTable[NPC_D_MPI_MON_MAX_USER_POP_NUM];	//用户权限，NPC_D_MPI_MON_MAX_USER_POP_NUM
	NPC_INT										iUserPopNum;									//用户权限数

} NPC_S_MPI_MON_USER_LOGIN_PR_OUT_PARAM, *PNPC_S_MPI_MON_USER_LOGIN_PR_OUT_PARAM;

//客户端配置参数
typedef struct _NPC_S_MPI_MON_CLIENT_CONFIG_PARAM
{
	NPC_BYTE									ucEnable_UserReg;								//是否提供用户注册功能，0：禁用，1：启用
	NPC_BYTE									ucEnable_UserUnreg;								//是否提供用户注销功能，0：禁用，1：启用
	NPC_BYTE									ucEnable_Tryout;								//是否提供试用功能，0：禁用，1：启用
	NPC_BYTE									ucEnable_DevManager;							//是否提供设备管理功能，0：禁用，1：启用
	NPC_BYTE									ucEnable_PTZ;									//是否提供云台控制功能，0：禁用，1：启用
	NPC_BYTE									ucReserve[3];									//备用

	NPC_CHAR									sTryAccount[32];								//试用帐号

} NPC_S_MPI_MON_CLIENT_CONFIG_PARAM, *PNPC_S_MPI_MON_CLIENT_CONFIG_PARAM;

//客户端配置参数
typedef struct _NPC_S_MPI_MON_CLIENT_CONFIG_DATA
{
	NPC_DWORD									dwParamId;										//参数ID，参见NPC_D_MPI_MON_CLIENT_CFGID_*定义
	NPC_CHAR									sParamName[64];									//参数名
	NPC_INT										iDataType;										//数据类型，0：整型，1：浮点型，2：字符串型

	NPC_INT										iValueInteger;									//整型值
	NPC_DOUBLE									dValueDouble;									//浮点值
	NPC_CHAR									sValueString[64];								//字符串值

} NPC_S_MPI_MON_CLIENT_CONFIG_DATA, *PNPC_S_MPI_MON_CLIENT_CONFIG_DATA;

//客户端配置参数
typedef struct _NPC_S_MPI_MON_CLIENT_CONFIG_DATA_V2
{
	NPC_CHAR									sParamName[64];									//参数名
	NPC_CHAR									sParamValue[128];								//参数值

} NPC_S_MPI_MON_CLIENT_CONFIG_DATA_V2, *PNPC_S_MPI_MON_CLIENT_CONFIG_DATA_V2;

//厂商配置定义
typedef struct _NPC_S_MPI_MON_CLIENT_VENDOR_CFG_DATA
{
	NPC_DWORD									dwVendorId;										//厂商ID
	NPC_CHAR									sVendorName[32];								//厂商名称
	NPC_DWORD									dwProVendorId;									//对应的协议厂商ID
	NPC_BYTE									ucReserve[64];									//备用

} NPC_S_MPI_MON_CLIENT_VENDOR_CFG_DATA, *PNPC_S_MPI_MON_CLIENT_VENDOR_CFG_DATA;

//设备提示消息
typedef struct _NPC_S_MPI_MON_DEV_PROMPT
{
	NPC_INT										iPromptId;										//提示消息ID
	NPC_CHAR									sPromptMsg[64];									//提示消息

} NPC_S_MPI_MON_DEV_PROMPT, *PNPC_S_MPI_MON_DEV_PROMPT;

//连接参数字段定义
typedef struct _NPC_S_MPI_MON_CONNPARAM_FIELD_DATA
{
	NPC_DWORD									dwVendorId;										//厂商ID
	NPC_CHAR									sShowName[32];									//显示名
	NPC_CHAR									sParamName[32];									//参数名
	NPC_INT										iParamType;										//参数类型，0：整型，1：浮点型，2：字段串
	NPC_INT										iStrMaxLen;										//字段串最大长度
	NPC_INT										iNumMinValue;									//数值型最小值
	NPC_INT										iNumMaxValue;									//数值型最大值
	NPC_CHAR									sDefaultValue[64];								//默认值
	NPC_BOOL									bIfMustInput;									//是否必填
	NPC_BOOL									bIfHide;										//是否隐藏显示并采用默认值
	NPC_BOOL									bIfNeedEncrypt;									//是否需要加密

} NPC_S_MPI_MON_CONNPARAM_FIELD_DATA, *PNPC_S_MPI_MON_CONNPARAM_FIELD_DATA;

//厂商数据定义
typedef struct _NPC_S_MPI_MON_CONNPARAM_VENDOR_DATA
{
	NPC_DWORD									dwVendorId;										//厂商ID
	NPC_CHAR									sVendorName[64];								//厂商名称
	NPC_BOOL									bIfNatFunc;										//是否具有NAT穿透功能

	NPC_INT										iFieldNum;										//字段数
	PNPC_S_MPI_MON_CONNPARAM_FIELD_DATA			pFieldTable;									//字段表

} NPC_S_MPI_MON_CONNPARAM_VENDOR_DATA, *PNPC_S_MPI_MON_CONNPARAM_VENDOR_DATA;

//厂商名称定义
typedef struct _NPC_S_MPI_MON_VENDOR_NAME
{
	NPC_DWORD									dwVendorId;										//厂商ID
	NPC_CHAR									sVendorName[32];								//厂商名称

} NPC_S_MPI_MON_VENDOR_NAME, *PNPC_S_MPI_MON_VENDOR_NAME;

//用户信息
typedef struct _NPC_S_MPI_MON_USER_INFO
{
	NPC_CHAR									sUserId[32];									//用户ID
	NPC_CHAR									sUserName[32];									//用户姓名
	NPC_CHAR									sPaperType[12];									//证件类型
	NPC_CHAR									sPaperNo[32];									//证件号码
	NPC_CHAR									sMobilePhone[32];								//移动电话号码
	NPC_CHAR									sEmail[64];										//EMAIL
	NPC_S_TD_DATE_TIME							tValidifyDate;									//有效期结束时间
	NPC_S_TD_DATE_TIME							tRegDate;										//注册时间

} NPC_S_MPI_MON_USER_INFO, *PNPC_S_MPI_MON_USER_INFO;


//----------------------------------------------------------------------------------------------------
//服务器推送命令
typedef struct _NPC_S_MPI_MON_PUSH_ORDER
{
	NPC_CHAR									sOrderStr[32];									//命令字符串
	NPC_CHAR									sParamStr[64];									//参数字符串

} NPC_S_MPI_MON_PUSH_ORDER, *PNPC_S_MPI_MON_PUSH_ORDER;

//服务器推送提示消息
typedef struct _NPC_S_MPI_MON_PUSH_PROMPT
{
	NPC_INT										iMsgType;										//消息类型（暂停使用）
	NPC_INT										iShowMode;										//显示方式（暂停使用）
	NPC_CHAR									sMsgContent[512];								//消息内容

} NPC_S_MPI_MON_PUSH_PROMPT, *PNPC_S_MPI_MON_PUSH_PROMPT;

//服务器推送更新结点（如添加、修改）
typedef struct _NPC_S_MPI_MON_PUSH_DEVN_UPDATE_NODE
{
	NPC_INT										iUpdateMode;									//更新方式，0：增加，1：修改

	NPC_S_MPI_MON_DEV_NODE						tNodeData;										//结点数据

} NPC_S_MPI_MON_PUSH_DEVN_UPDATE_NODE, *PNPC_S_MPI_MON_PUSH_DEVN_UPDATE_NODE;

//服务器推送设备变更：删除结点（设备或目录）
typedef struct _NPC_S_MPI_MON_PUSH_DEVN_DEL_NODE
{
	NPC_DWORD									dwNodeId;										//结点ID

} NPC_S_MPI_MON_PUSH_DEVN_DEL_NODE, *PNPC_S_MPI_MON_PUSH_DEVN_DEL_NODE;

//服务器推送全局权限变更
typedef struct _NPC_S_MPI_MON_PUSH_UPDATE_GPOP
{
	NPC_BOOL									bIfAllPop;										//是否有全部权限
	NPC_INT										iPopNum;										//权限数
	NPC_INT										iPopIdTable[128];								//权限ID表

} NPC_S_MPI_MON_PUSH_UPDATE_GPOP, *PNPC_S_MPI_MON_PUSH_UPDATE_GPOP;

//服务器推送设备报警消息
typedef struct _NPC_S_MPI_MON_PUSH_DEV_ALARM
{
	NPC_CHAR									sAlarmId[32];									//报警ID，设备端唯一，如果为空，则设备端为老设备
	NPC_CHAR									sDevUmid[32];									//设备UMID，如果为空，则表示是其它方式推送的报警，需要参考sDevId参数
	NPC_INT										iDevChNo;										//设备通道号
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//设备ID，即摄像机ID
	NPC_CHAR									sDevName[128];									//设备名称，即镜头名称
	NPC_INT										iAlarmType;										//报警类型，参见NPC_D_MON_ALARM_TYPE_*定义
	NPC_S_TD_DATE_TIME							tAlarmTime;										//报警时间
	NPC_INT										iAlarmState;									//报警状态，0：停止（离线），1：开始（在线），2：设备故障，3：硬盘满
	NPC_CHAR									sAlarmInfo[128];								//报警信息
	NPC_DWORD									dwParam1;										//扩展参数1
	NPC_DWORD									dwParam2;										//扩展参数2

} NPC_S_MPI_MON_PUSH_DEV_ALARM, *PNPC_S_MPI_MON_PUSH_DEV_ALARM;

//服务器推送设备报警消息（小区报警）
typedef struct _NPC_S_MPI_MON_PUSH_DEV_ALARM_VILLAGE
{
	NPC_CHAR									sAlarmId[32];									//报警ID
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//设备ID
	NPC_CHAR									sDevName[128];									//设备名称，即镜头名称
	NPC_INT										iAlarmType;										//报警类型，参见NPC_D_MON_ALARM_TYPE_*定义
	NPC_S_TD_DATE_TIME							tAlarmTime;										//报警时间
	NPC_INT										iAlarmState;									//报警状态，0：停止（离线），1：开始（在线），2：设备故障，3：硬盘满
	NPC_CHAR									sAlarmInfo[128];								//报警信息
	NPC_DWORD									dwParam1;										//扩展参数1
	NPC_DWORD									dwParam2;										//扩展参数2
	NPC_CHAR									sUserId[32];									//用户ID
	NPC_CHAR									sUserName[32];									//用户姓名
	NPC_CHAR									sUserPhone[20];									//用户手机号码
	NPC_CHAR									sUserAddr[68];									//用户地址

} NPC_S_MPI_MON_PUSH_DEV_ALARM_VILLAGE, *PNPC_S_MPI_MON_PUSH_DEV_ALARM_VILLAGE;

//重新登录通知
typedef struct _NPC_S_MPI_MON_PUSH_RE_LOGIN_NOTIFY
{
	NPC_INT										iCause;											//原因，参见NPC_D_MPI_MON_RELOGIN_CAUSE_*定义

} NPC_S_MPI_MON_PUSH_RE_LOGIN_NOTIFY, *PNPC_S_MPI_MON_PUSH_RE_LOGIN_NOTIFY;

//服务器推送公告消息
typedef struct _NPC_S_MPI_MON_PUSH_ANNO_MSG
{
	NPC_CHAR									sMsgBuf[1024];									//消息缓冲区

} NPC_S_MPI_MON_PUSH_ANNO_MSG, *PNPC_S_MPI_MON_PUSH_ANNO_MSG;


//--------------------------------------------------------------------------------------------------
//推送消息数据定义
typedef struct _NPC_S_MPI_MON_PUSH_MSG_DATA
{
	NPC_INT										iMsgType;										//消息类型，参见NPC_D_MPI_MON_PUSH_TYPE_*定义

	union _Data
	{
		NPC_S_MPI_MON_CLIENT_CONFIG_PARAM		tConfig;										//配置参数
		NPC_S_MPI_MON_PUSH_ORDER				tOrder;											//服务器推送命令
		NPC_S_MPI_MON_PUSH_PROMPT				tPrompt;										//服务器推送提示消息
		NPC_S_MPI_MON_PUSH_DEVN_UPDATE_NODE		tDevnUpdateDev;									//服务器推送更新结点（如添加、修改）
		NPC_S_MPI_MON_PUSH_DEVN_DEL_NODE		tDevnDelNode;									//服务器推送设备变更：删除结点（设备或目录
		NPC_S_MPI_MON_PUSH_UPDATE_GPOP			tGPop;											//服务器推送全局权限变更
		NPC_S_MPI_MON_PUSH_DEV_ALARM			tDevAlarm;										//服务器推送设备报警消息
		NPC_S_MPI_MON_PUSH_DEV_ALARM_VILLAGE	tDevAlarmVillage;								//服务器推送设备报警消息（小区报警）
		NPC_S_MPI_MON_PUSH_RE_LOGIN_NOTIFY		tReLoginNotify;									//重新登录通知
		NPC_S_MPI_MON_PUSH_ANNO_MSG				tAnnoMsg;										//服务器推送公告消息

	} uData;

} NPC_S_MPI_MON_PUSH_MSG_DATA, *PNPC_S_MPI_MON_PUSH_MSG_DATA;


//--------------------------------------------------------------------------------------------------
//设备授权数据定义
typedef struct _NPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA
{
	NPC_CHAR									sUserId[NPC_D_MPI_MON_USERID_BUFSIZE];			//用户ID
	NPC_CHAR									sPopIdTable[128];								//权限ID表，以逗号分隔

} NPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA, *PNPC_S_MPI_MON_EMP_DEV_EMPOWER_DATA;

//布防信息
typedef struct _NPC_S_MPI_MON_ARM_SET_ALARM_INFO
{
	NPC_BOOL									bIfSetAlarm;									//是否布防，TRUE表示设置了布防，FALSE表示未设置布防
	NPC_CHAR									sAlarmTypeTable[64];							//报警类型表，以逗号分隔，值参考NPC_D_MON_ALARM_TYPE_*定义
	NPC_INT										iArmState;										//布防状态，0：暂停状态，1：开启状态
	NPC_INT										iNotifyState;									//通知状态，0：暂停状态，1：开启状态
	NPC_INT										iActionState;									//联动状态，0：暂停状态，1：开启状态

	//通知表
	NPC_INT										iNotifyNum;										//通知数
	struct _NotifyTable
	{
		NPC_INT									iNotifyType;									//通知类型，参考NPC_D_MON_ALARM_NOTIFY_TYPE_*定义
		NPC_CHAR								sNotifyParam[128];								//通知参数，根据通知类型确定通知参数内容，如手机推送为TOKEN，短信为手机号码，EMAIL为EMAIL地址

	} tNotifyTable[NPC_D_MPI_MON_MAX_ALARM_NOTIFY_NUM];

	//联动表
	NPC_INT										iActionNum;										//联动数
	struct _ActionTable
	{
		NPC_INT									iActionType;									//联动类型，参考NPC_D_MON_ALARM_ACTION_TYPE_*定义
		NPC_INT									iStopType;										//停止类型，0：报警停止时停止，1：固定时长停止
		NPC_INT									iPhotoSpaceTime;								//拍照间隔时间（秒）
		NPC_INT									iActionTotalTime;								//联动总时间（秒）
		NPC_INT									iPtzCruiseId;									//PTZ联动巡航ID

	} tActionTable[NPC_D_MPI_MON_MAX_ALARM_ACTION_NUM];

} NPC_S_MPI_MON_ARM_SET_ALARM_INFO, *PNPC_S_MPI_MON_ARM_SET_ALARM_INFO;

//报警记录
typedef struct _NPC_S_MPI_MON_ARM_ALARM_RECORD
{
	NPC_CHAR									sAlarmRecordId[32];								//报警记录ID
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//设备ID（即摄像机ID）
	NPC_CHAR									sDevShowName[128];								//设备显示名称
	NPC_INT										iAlarmType;										//报警类型，参见NPC_D_MON_ALARM_TYPE_*定义
	NPC_INT										iAlarmState;									//报警状态，0：停止（离线），1：开始（在线），2：设备故障，3：硬盘满
	NPC_S_TD_DATE_TIME							tAlarmTime;										//报警时间
	NPC_CHAR									sAlarmInfo[128];								//报警信息

} NPC_S_MPI_MON_ARM_ALARM_RECORD, *PNPC_S_MPI_MON_ARM_ALARM_RECORD;

//小区报警记录
typedef struct _NPC_S_MPI_MON_ARM_VILLAGE_ALARM_RECORD
{
	NPC_CHAR									sAlarmRecordId[32];								//报警记录ID
	NPC_CHAR									sDevId[NPC_D_MON_DEVID_BUFSIZE];				//设备ID（即摄像机ID）
	NPC_CHAR									sDevShowName[128];								//设备显示名称
	NPC_INT										iAlarmType;										//报警类型，参见NPC_D_MON_ALARM_TYPE_*定义
	NPC_INT										iAlarmState;									//报警状态，0：停止（离线），1：开始（在线），2：设备故障，3：硬盘满
	NPC_S_TD_DATE_TIME							tAlarmTime;										//报警时间
	NPC_CHAR									sAlarmInfo[128];								//报警信息
	NPC_CHAR									sDoAlarmInfo[64];								//处警信息
	NPC_CHAR									sUserId[32];									//用户ID
	NPC_CHAR									sUserName[32];									//用户姓名
	NPC_CHAR									sUserPhone[20];									//用户手机号码
	NPC_CHAR									sUserAddr[68];									//用户地址

} NPC_S_MPI_MON_ARM_VILLAGE_ALARM_RECORD, *PNPC_S_MPI_MON_ARM_VILLAGE_ALARM_RECORD;


//--------------------------------------------------------------------------------------------------
//网卡数据
typedef struct _NPC_S_MPI_MON_SEARCH_ADAPTER_DATA
{
	NPC_CHAR									sAdapterName[32];								//网卡名称
	NPC_CHAR									sAdapterMac[20];								//网卡MAC地址，格式为XX-XX-
	NPC_CHAR									sIpaddr[16];									//IP地址
	NPC_CHAR									sNetmask[16];									//子网掩码
	NPC_CHAR									sGateway[16];									//网关地址
	NPC_INT										iIpConnMode;									//IP连接模式，0：原版本，1：IP待测试，2：可连接

} NPC_S_MPI_MON_SEARCH_ADAPTER_DATA, *PNPC_S_MPI_MON_SEARCH_ADAPTER_DATA;

//搜索设备数据
typedef struct _NPC_S_MPI_MON_SEARCH_DEV_DATA
{
	NPC_INT										iMsgVerNo;						//消息版本号

	NPC_DWORD									dwVendorId;						//厂商ID
	NPC_CHAR									sDevModel[32];					//厂商设备型号
	NPC_CHAR									sUMDevModel[32];				//UM设备型号
	NPC_CHAR									sVersion[16];					//版本号
	NPC_CHAR									sDevName[32];					//设备名称
	NPC_CHAR									sDevId[32];						//设备ID
	NPC_CHAR									sDevUserName[32];				//设备用户名
	NPC_BOOL									bIfSetPwd;						//是否设置了密码
	NPC_CHAR									sCloudServerAddr[64];			//云服务地址
	NPC_USHORT									usCloudServerPort;				//云服务端口号
	NPC_CHAR									sDevIpaddr[16];					//设备的IP地址
	NPC_USHORT									usDevPort;						//设备的端口号
	NPC_USHORT									usChNum;						//通道数
	NPC_USHORT									usDevNtsUdpPort;				//设备NTS的UDP端口号
	NPC_USHORT									usDevMnVerNo;					//设备端管理版本号

	NPC_INT										iEmpowerMode;					//授权模式，0：测试模式，1：UMID模式，2：认证码模式，3：服务器授权模式
	NPC_CHAR									sEmpowerCode[64];				//授权码

	NPC_INT										iDevIdType;						//设备ID类型，0：手动设置，1：服务器分配，2：序列号（MAC产生）
	NPC_BOOL									bIfAllowSetIpaddr;				//是否可以设置IP地址
	NPC_BOOL									bIfEnableDhcp;					//是否启用DHCP

	NPC_BOOL									bIfConnState;					//是否有连接状态
	NPC_INT										iSrvConnState;					//服务器连接状态，参见NPC_D_MPI_MON_DEV_SRV_CONN_STATE_*定义
	NPC_INT										iSrvConnResult;					//服务器连接结果，参见NPC_D_MPI_MON_DEV_SRV_CONN_FAIL_CODE_*定义

	NPC_INT										iAdapterNum;											//网卡数
	NPC_S_MPI_MON_SEARCH_ADAPTER_DATA			tAdapterTable[NPC_D_MPI_MON_SEARCH_MAX_ADAPTER_NUM];	//网卡表

} NPC_S_MPI_MON_SEARCH_DEV_DATA, *PNPC_S_MPI_MON_SEARCH_DEV_DATA;

//SDK设备数据
typedef struct _NPC_S_MPI_MON_SEARCH_SDK_DEV_DATA
{
	NPC_UINT									uiDevFlag;						//设备端标识
	NPC_CHAR									sDevIpaddr[16];					//设备IP地址

	NPC_CHAR									sDevType[12];					//设备类型，如：DEV，IPC
	NPC_CHAR									sDevModel[32];					//设备型号
	NPC_CHAR									sSerialNumber[32];				//序列号
	NPC_INT										iVideoChanNum;					//设备通道个数
	NPC_INT										iAudioChanNum;					//设备语音通道数
	NPC_INT										iPtzChNum;						//PTZ通道数
	NPC_INT										iAlarmInPortNum;				//报警输入个数
	NPC_INT										iAlarmOutPortNum;				//报警输出个数
	NPC_INT										iDiskNum;						//硬盘个数
	NPC_INT										iSubProtoNum;					//子码流数，0表示不支持子码流

	NPC_BOOL									bIfDpsDebug;					//是否调试状态
	NPC_BOOL									bIfDpsShowStreamLog;			//是否显示流日志，即媒体流收发日志信息
	NPC_BOOL									bIfShowRunState;				//是否显示运行状态信息

} NPC_S_MPI_MON_SEARCH_SDK_DEV_DATA, *PNPC_S_MPI_MON_SEARCH_SDK_DEV_DATA;

//NTS设备参数
typedef struct _NPC_S_MPI_MON_NTS_DEV_PARAM
{
	NPC_CHAR									sDevId[32];						//设备ID

	NPC_CHAR									sServerAddr[128];				//服务器地址（IP地址或域名）
	NPC_USHORT									usServerPort;					//服务器端口号
	NPC_USHORT									usReserve;						//备用

	NPC_BOOL									bIfWriteLogFile;				//是否写日志文件

	NPC_BOOL									bIfStartLogNetSrv;				//是否需要启动日志网络服务
	NPC_USHORT									usLogNetSrvPort;				//日志网络服务端口号

	NPC_BOOL									bIfStartLogUpClient;			//是否需要启动日志上传客户端
	NPC_CHAR									sLogUpSrvIpaddr[16];			//日志上传服务IP地址
	NPC_USHORT									usLogUpSrvPort;					//日志上传服务端口号

} NPC_S_MPI_MON_NTS_DEV_PARAM, *PNPC_S_MPI_MON_NTS_DEV_PARAM;

//文件操作命令，完整文件读取或写入，该结构体之后为实际数据
typedef struct _NPC_S_MPI_MON_FILE_OP_ORDER
{
	NPC_INT										iOrderId;						//命令ID，0：读文件申请，1：写文件申请，2：读文件应答，3：写文件应答
	NPC_DWORD									dwRequId;						//请求ID，唯一标识该次请求
	NPC_CHAR									sFileName[64];					//文件名，文件保存目录，由上层决定
	NPC_DWORD									dwRet;							//结果，0：成功，其它失败
	NPC_DWORD									dwDataLen;						//数据长度（字节）

} NPC_S_MPI_MON_FILE_OP_ORDER, *PNPC_S_MPI_MON_FILE_OP_ORDER;

//系统消息
typedef struct _NPC_S_MPI_MON_SYSTEM_MSG
{
	NPC_CHAR									sMsgId[32];						//消息ID
	NPC_CHAR									sMsgTime[20];					//消息时间
	NPC_CHAR									sMsgTitle[128];					//消息标题
	NPC_CHAR									sMsgContent[1024];				//消息内容（TXT格式）

} NPC_S_MPI_MON_SYSTEM_MSG, *PNPC_S_MPI_MON_SYSTEM_MSG;

//演示点设备
typedef struct _NPC_S_MPI_MON_VIDEO_DEMO_DEV_DATA
{
	NPC_CHAR									sDevName[128];					//设备名称
	NPC_CHAR									sShareName[128];				//分享名称
	NPC_CHAR									sCameraId[32];					//摄像机ID
	NPC_INT										iVendorId;						//厂商ID
	NPC_INT										iConnMode;						//连接模式，参见NPC_D_MON_DEV_CONN_MODE_*定义
	NPC_CHAR									sConnParam[256];				//连接参数
	NPC_CHAR									sPicLink[128];					//图片链接

} NPC_S_MPI_MON_VIDEO_DEMO_DEV_DATA, *PNPC_S_MPI_MON_VIDEO_DEMO_DEV_DATA;

//视频编码等级参数
typedef struct _NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_PARAM
{
	NPC_CHAR									sLevelName[16];					//等级名称
	NPC_INT										iLevelValue;					//等级值，必须大于等于0
	NPC_USHORT									usWidth;						//图像宽
	NPC_USHORT									usHeight;						//图像高
	NPC_USHORT									usFrameRate;					//帧率
	NPC_USHORT									usBitRate;						//码率，单位：kbps

} NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_PARAM, *PNPC_S_MPI_MON_VIDEO_CODEC_LEVEL_PARAM;

//视频编码等级列表
typedef struct _NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_LIST
{
	NPC_INT										iLevelNum;						//等级数
	NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_PARAM		tLevelList[8];					//等级列表

} NPC_S_MPI_MON_VIDEO_CODEC_LEVEL_LIST, *PNPC_S_MPI_MON_VIDEO_CODEC_LEVEL_LIST;

//存储服务器地址
typedef struct _NPC_S_MPI_MON_STORAGE_SRV_ADDR
{
	NPC_INT										iSrvAddrNum;					//服务器地址数
	struct _SrvAddrTable{
		NPC_CHAR								sIpaddr[16];					//服务器IP地址
		NPC_USHORT								usPort;							//服务器端口号
		NPC_USHORT								usReserve;						//备用
	} tSrvAddrTable[32];

} NPC_S_MPI_MON_STORAGE_SRV_ADDR, *PNPC_S_MPI_MON_STORAGE_SRV_ADDR;


#endif

