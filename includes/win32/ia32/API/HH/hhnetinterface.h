/******************************************************************************
* 系统名称：HHNetClient
* 文件名称：HHNetInterface.h
* 版本    ：V6.0.1
* 说明	  ：网络模块,提供和编码器、解码器交互接口,设置及控制设备
			该文件包含六部分：一、宏定义；二、枚举类型定义；三、回调函数；四、接口结构类型定义；五、函数接口定义；六、数字视频服务器的配置信息结构
* 日    期: 2005年10月10日
  最近更新:	2008年09月10日			增加反向中心连接方式支持
            2009年03月09日			增加结构ALARM_MSG_NOTIFY_NEW
			2009年04月01日			修改结构HH_TALK_INFO
			2009年04月15日			增加结构WF_AUTH_TYPE
* 其他说明: 无
******************************************************************************/
#ifndef  HH_NET_INTERFACE_H_
#define  HH_NET_INTERFACE_H_
 
#ifdef __cplusplus
extern "C" {
#endif

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifdef HHNET_CLIET_INTERFACE
#define HHNET_API __declspec(dllexport)
#else
#define HHNET_API __declspec(dllimport)
#endif

/*****************************************************************************/
/*********************************  一、宏定义  ******************************/
/*****************************************************************************/

//1，系统常量
#define MAX_VIDEO_NUM			4	//数字视频服务器最大通道数
#define MAX_AUDIO_NUM			4	//数字视频服务器音频最大通道数
#define MAX_SENSOR_NUM			4	//探头输入最大路数
#define MAX_RF_SENSOR_NUM		8	//无线探头最大路数
#define MAX_OUTPUT_NUM			4	//探头输出路数
#define MAX_COM_NUM				2	//串口最大个数	
#define MAX_USER_NUM			5	//用户个数
#define	MAX_LOGON_NUM			10	//最大同时登录用户数
#define MAX_LINKVIEW_NUM		16	//最大同时TCP、UDP预览用户数
#define MAX_MULTIVIEW_NUM		60	//最大多播用户数
#define DVS_NAME_LEN            32	//数字视频服务器名称长度

#define CAM_TITLE_LEN_NEW		64	//31个汉字，63个字符
#define CAM_TITLE_LEN			16	//摄像机标题长度(8个汉字，16个字符)
#define USER_NAME_LEN 			16	//用户名的最大长度
#define USER_PASSWD_LEN   		16	//用户密码最大长度
	
#define DDNS_NAME_LEN			32	//注册主机名称长度
#define DDNS_PASS_LEN			16	//注册主机密码长度	
#define	DDNS_SERVER_NAME_LEN	32
#define PPPPOE_NAME_LEN			32	//拨号用户名长度
#define PPPPOE_PASSWD_LEN		16	//拨号用户名长度
#define YUNTAI_NAME_LEN			32	//云台协议名称长度
#define	MAX_YUNTAI_PROTOCOL_NUM	36	//内置最大云台协议数
#define MAX_PTZ_PROTOCOL_NUM  	4	//最大云台协议数
#define	MAX_IP_NAME_LEN			128	//输入IP或名字的最大长度
#define	IP_STR_LEN				16	//IP长

#define	DOMAIN_NAME_LEN			32  //域名的长度
#define EMAIL_TITLE_LEN         32	//EMAIL头和内容长
#define DD_URL_ADDR_LEN			32	//URL地址长度
#define	DD_MAX_ADDR_NUM			32	//地址薄的地址数量
#define	DD_MAX_ALARMINFO_NUM	64	//报警记录个数最大值

//2，云台控制
#define	YT_UP					1	//云台上
#define	YT_DOWN					2	//云台下	
#define	YT_LEFT					3	//云台左
#define	YT_RIGHT				4	//云台右
#define	YT_FOCUSADD				5	//聚焦+
#define	YT_FOCUSSUB				6	//聚焦-
#define	YT_IRISADD				7	//光圈+
#define	YT_IRISSUB				8	//光圈-
#define	YT_ZOOMADD				9	//变倍+
#define	YT_ZOOMSUB				10	//变倍-
#define	YT_AUTOOPEN				11	//自动开
#define	YT_AUTOCLOSE			12	//自动关
#define	YT_LAMPOPEN				13	//灯光开
#define	YT_LAMPCLOSE			14	//灯光关
#define	YT_BRUSHOPEN			15	//雨刮开
#define	YT_BRUSHCLOSE			16	//雨刮关
#define	YT_WATEROPEN			17	//放水开
#define	YT_WATERCLOSE			18	//放水关
#define	YT_PRESET				19	//预置 + 号
#define	YT_CALL					20	//调用 + 号
#define	YT_STOP					21	//停止
#define	YT_UP_STOP				30	//云台上-停	
#define	YT_DOWN_STOP			31	//云台下-停	
#define	YT_LEFT_STOP			32	//云台左-停
#define	YT_RIGHT_STOP			33	//云台右-停
#define	YT_FOCUSADD_STOP		34	//聚焦+ -停
#define	YT_FOCUSSUB_STOP		35	//聚焦- -停
#define	YT_IRISADD_STOP			36	//光圈+ -停
#define	YT_IRISSUB_STOP			37	//光圈- -停
#define	YT_ZOOMADD_STOP			38	//变倍+ -停
#define	YT_ZOOMSUB_STOP			39	//变倍- -停	

#define YT_UP_LIMIT				50	//上限位
#define YT_DOWN_LIMIT			51	//下限位
#define YT_LEFT_LIMIT			52	//左限位
#define YT_RIGHT_LIMIT			53	//右限位
#define YT_PREST_SCAN1			54	//预置位巡视1
#define YT_PREST_SCAN2			55	//预置位巡视2
#define YT_PREST_SCAN_STOP		56	//预置位巡视停止
#define YT_APPLE_SCAN 			57	//削苹果扫描
#define YT_APPLE_SCAN_STOP		58	//削苹果扫描停止
#define YT_X_SCAN_SET			60	//花样扫描设置
#define YT_X_SCAN_SAVE			61	//花样扫描设置结束
#define YT_X_SCAN_RUN			62	//花样扫描运行
#define YT_X_SCAN_STOP			63	//花样扫描停止
#define YT_X_FLIP				64	//水平翻转
#define YT_VZERO_DETECT			65	//虚拟零位检测
#define YT_VZERO_SET			66	//虚拟零位  设置
#define YT_VZERO_OK				67	//虚拟零位	确认
#define YT_VZERO_CANCEL			68	//虚拟零位  取消
#define YT_PTZ_RESET			69	//球机云台复位
/*****************************************************************************/
/***************************  二、枚举类型定义  ******************************/
/*****************************************************************************/

//1，数字视频服务器机器类型
typedef enum	DVS_MACHINE_TYPE_
{
	HH5001C  = 0x00,				//一路CIF编码器
	HH5002H  = 0x01,				//二路HalfD1编码器
	HH5001D  = 0x02,				//一路D1编码器
	HH5004C  = 0x03,				//四路CIF编码器
	HH5104   = 0x04,				//四路解码器
	HH5108   = 0x05,				//八路解码器
	HH6104   = 0x06,				//四路解码卡
	
	HH5200   = 0x10,				//保留
	HH5201   = 0x11,				//IPCam一路CCD,D1编码,HH9000系列
	HH5201DI = 0X11,
	HH5201CI = 0x12,				//IPCam一路CCD,CIF编码,HH9000系列
	HH5201MI = 0x13,				//IPCam一路CMOS,HH9000系列

	HH5201C  = 0x20,				//DVS一路CIF
	HH5201D  = 0x21,				//DVS一路D1
	HH5202C  = 0x22,				//DVS两路CIF
	HH5202H  = 0x23,				//DVS两路HD1
	HH5204C  = 0x24,				//DVS四路CIF
	HH5204D  = 0x25,				//DVS四路d1
	
	HH5301   = 0x30,				//H.264 单路解码器(IPCam,  HH52系列, HH56系列DVS)

	HH5700   = 0x35,				//HH57系列 解码器 (IPCam,  HH52系列, HH56系列DVS)

	HH9800CI = 0x40,				//HH98系列 IPCam一路CCD
	HH9800MI,						//HH98系列 IPCam一路CMOS
	HH9800MIX,						//HH98系列 IPCam一路CMOS(高清)
	HH9800CIX,						//HH98系列 IPCam一路CCD (高清)
	HH9800CIH,						//HH98系列 IPCam一路CCD (高清高速球)

	HH5801C  = 0x45,				//HH58系列 DVS			
	HH5801D,		
	HH5802C,
	HH5802H,
	HH5802D,	
	HH5804C,
	HH5804H,
	HH5804D, 

	HH7000   = 0x50,					
}DVS_MACHINE_TYPE;

//3，升级类型
typedef enum _UPDATE_TYPE
{
	UPDATE_KERNEL,					//升级内核
	UPDATE_YUNTAI1,					//升级云台协议1
	UPDATE_YUNTAI2,					//升级云台协议2
	UPDATE_YUNTAI3,					//升级云台协议3
	UPDATE_YUNTAI4,					//升级云台协议4
	UPDATE_YUNTAI5,					//升级云台协议5
	UPDATE_YUNTAI6,					//升级云台协议6
	UPDATE_OCX,						//升级控件
	UPDATE_WEBPAGE,					//升级页面
	UPDATE_PATHFILE,				//升级特定目录文件
}UPDATE_TYPE;

//4，网络协议类型
typedef enum _NET_PROTOCOL_TYPE
{
    NET_PROTOCOL_TCP = 0,			//TCP协议
	NET_PROTOCOL_UDP = 1,			//UDP协议
	NET_PROTOCOL_MULTI = 2			//多播协议
}NET_PROTOCOL_TYPE;

//5，连接状态
typedef enum _CONNECT_STATUS
{
	CONNECT_STATUS_NONE,			//未连接
	CONNECT_STATUS_OK,				//已经连接
	CONNECT_STATUS_DATA,
	CONNECT_STATUS_EXIST,
}CONNECT_STATUS;

//6，转发类型
typedef enum _RELAY_TYPE
{
	RELAY_LOGON,					//转发登录设置
	RELAY_PREVIEW,					//转发视频预览数据
	RELAY_TALK,						//转发对讲
	RELAY_AUDIOBRD,					//转发语音广播
	RELAY_QUERY						//转发的查询
}RELAY_TYPE;

//7，通知应用程序窗口消息命令
typedef enum _HHMSG_NOTIFY
{
	HHMSG_CONNECT_CLOSE,			//登录连接关闭
	HHMSG_CHANNEL_CLOSE,			//通道连接关闭
	HHMSG_TALK_CLOSE,				//对讲连接关闭
	HHMSG_ALARM_OUTPUT,				//报警输出
	HHMSG_UPDATE_SEND_PERCENT,		//升级程序发送百分比
	HHMSG_UPDATE_SAVE_PERCENT,		//升级写入发送百分比
	HHMSG_BROADCAST_ADD_FAILURE,	//加入语音广播组失败
	HHMSG_BROADCAST_CLOSE,			//语音广播中一个断开
	HHMSG_SENSOR_CAPTURE,			//探头触发的抓拍
	HHMSG_COM_DATA,					//串口采集数据
	HHMSG_ALARM_LOST,				//报警消失
	HHMSG_ALARM_OUTPUT_NEW,			//报警输出(新)
	HHMSG_ALARM_LOST_NEW,			//报警消失(新)
	HHMSG_PICCHN_CLOSE,				//抓拍通道连接关闭
	HHMSG_LOGON_SUCCESS,			//登录连接成功
	HHMSG_CHANNEL_SUCCESS,			//通道连接成功
	HHMSG_TALK_SUCCESS,				//对讲连接成功
	HHMSG_BROADCAST_SUCCESS,		//加入语音广播组成功
	HHMSG_PICCHN_SUCCESS,			//抓拍通道连接成功
	HHMSG_VIEWPUSH_SUCCESS,			//打开解码器视频输入成功
	HHMSG_GPS_STATUS,				//GPS信息,add by huangtao
	HHMSG_NETREPLAY_CLOSE,			//远程回放通道关闭
	HHMSG_VIEWPUSH_CLOSE,			//解码通道关闭
}HHMSG_NOTIFY;

//8，错误码
typedef enum _HHERR_CODE
{
	HHERR_SUCCESS,					//操作成功
	HHERR_FAILURE,					//操作失败
	HHERR_REFUSE_REQ,				//请求被拒绝
	HHERR_USER_FULL,				//登录用户已满
	HHERR_PREVIEW_FULL,				//预览用户已满
	HHERR_TASK_FULL,				//系统任务繁忙，待会尝试连接
	HHERR_CHANNEL_NOT_EXIST,		//要打开的通道不存在或已满
	HHERR_DEVICE_NAME,				//打开的设备不存在
	HHERR_IS_TALKING,				//正在对讲
	HHERR_QUEUE_FAILUE,				//队列出错
	HHERR_USER_PASSWORD,			//用户名或密码和系统不匹配
	HHERR_SHARE_SOCKET,				//socket 错误
	HHERR_RELAY_NOT_OPEN,			//转发请求的服务还未打开
	HHERR_RELAY_MULTI_PORT,			//转发多播端口错误
	HHERR_VIEWPUSH_CHANNEL_USING,	//视频输入的通道已经被占用
	HHERR_VIEWPUSH_DECODE_TYPE,		//视频输入通道的解码格式错误，0通道(4cif,2cif,cif),1通道(2cif,cif),2通道(cif),3通道(cif)
	HHERR_AUTO_LINK_FAILURE,		//转发的自动连接失败
	HHERR_NOT_LOGON,				//设备还未登录
	HHERR_IS_SETTING,				//设备正在设置
	HHERR_COMMAND_FAILURE,			//命令失败
	HHERR_RESTRICT_ID,				//ID使用受限
	
	HHERR_INVALID_PARAMETER=100,	//输入参数无效
	HHERR_LOGON_FAILURE,			//登录失败
	HHERR_TIME_OUT,					//操作超时
	HHERR_SOCKET_ERR,				//SOCKET错误
	HHERR_NOT_LINKSERVER,			//还未连接服务器
	HHERR_BUFFER_EXTCEED_LIMIT,		//使用缓冲超过限制	
	HHERR_LOW_PRIORITY,				//操作权限不足
	HHERR_BUFFER_SMALL,				//缓冲太小
	HHERR_IS_BUSY,					//系统任务正忙
	HHERR_UPDATE_FILE,				//升级文件错误
	HHERR_UPDATE_UNMATCH,			//升级文件和机器不匹配
	HHERR_PORT_INUSE,				//端口被占用
	HHERR_RELAY_DEVICE_EXIST,		//设备名已经存在
	HHERR_CONNECT_REFUSED,			//连接时被拒绝
	HHERR_PROT_NOT_SURPPORT,		//不支持该协议

	HHERR_FILE_OPEN_ERR,            //打开文件失败
	HHERR_FILE_SEEK_ERR,            //fseek失败 
	HHERR_FILE_WRITE_ERR,           //fwrite失败 
	HHERR_FILE_READ_ERR,            //fread失败 
	HHERR_FILE_CLOSING,             //正在关闭文件 
	
	HHERR_ALLOC_BUF_ERR,
}HHERR_CODE;

//9，参数操作命令
typedef enum _HHCMD_NET
{
	//编码器命令
	HHCMD_GET_ALL_PARAMETER,		//0. 得到所有编码器参数
	HHCMD_SET_DEFAULT_PARAMETER,	//1. 恢复所有编码器默认参数
	HHCMD_SET_RESTART_DVS,			//2. 重启编码器
	HHCMD_GET_SYS_CONFIG,			//3. 获取系统设置
	HHCMD_SET_SYS_CONFIG,			//4. 设置系统设置
	HHCMD_GET_TIME,					//5. 获取编码器时间
	HHCMD_SET_TIME,					//6. 设置编码器时间
	HHCMD_GET_AUDIO_CONFIG,			//7. 获取音频设置
	HHCMD_SET_AUDIO_CONFIG,			//8. 设置音频设置
	HHCMD_GET_VIDEO_CONFIG,			//9. 获取视频设置
	HHCMD_SET_VIDEO_CONFIG,			//10.设置视频设置
	HHCMD_GET_VMOTION_CONFIG,		//11.获取移动侦测设置
	HHCMD_SET_VMOTION_CONFIG,		//12.设置移动侦测设置
	HHCMD_GET_VMASK_CONFIG,			//13.获取图像屏蔽设置
	HHCMD_SET_VMASK_CONFIG,			//14.设置图像屏蔽设置
	HHCMD_GET_VLOST_CONFIG,			//15.获取视频丢失设置
	HHCMD_SET_VLOST_CONFIG,			//16.设置视频丢失设置
	HHCMD_GET_SENSOR_ALARM,			//17.获取探头报警侦测设置
	HHCMD_SET_SENSOR_ALARM,			//18.设置探头报警侦测设置
	HHCMD_GET_USER_CONFIG,			//19.获取用户设置
	HHCMD_SET_USER_CONFIG,			//20.设置用户设置
	HHCMD_GET_NET_CONFIG,			//21.获取网络设置结构
	HHCMD_SET_NET_CONFIG,			//22.设置网络设置结构
	HHCMD_GET_COM_CONFIG,			//23.获取串口设置
	HHCMD_SET_COM_CONFIG,			//24.设置串口设置
	HHCMD_GET_YUNTAI_CONFIG,		//25.获取内置云台信息
	HHCMD_SET_YUNTAI_CONFIG,		//26.设置内置云台信息
	HHCMD_GET_VIDEO_SIGNAL_CONFIG,	//27.获取视频信号参数（亮度、色度、对比度、饱和度）
	HHCMD_SET_VIDEO_SIGNAL_CONFIG,	//28.设置视频信号参数（亮度、色度、对比度、饱和度）
	HHCMD_SET_PAN_CTRL,				//29.云台控制
	HHCMD_SET_COMM_SENDDATA,		//30.透明数据传输
	HHCMD_SET_COMM_START_GETDATA,	//31.开始采集透明数据
	HHCMD_SET_COMM_STOP_GETDATA,	//32.停止采集透明数据
	HHCMD_SET_OUTPUT_CTRL,			//33.继电器控制
	HHCMD_SET_PRINT_DEBUG,			//34.调试信息开关
	HHCMD_SET_ALARM_CLEAR,			//35.清除报警
	HHCMD_GET_ALARM_INFO,			//36.获取报警状态和继电器状态
	HHCMD_SET_TW2824,				//37.设置多画面芯片参数(保留)
	HHCMD_SET_SAVE_PARAM,			//38.设置保存参数
	HHCMD_GET_USERINFO,				//39.获取当前登陆的用户信息
	HHCMD_GET_DDNS,					//40.获取DDNS
	HHCMD_SET_DDNS,					//41.设置DDNS
	HHCMD_GET_CAPTURE_PIC,			//42.前端抓拍
	HHCMD_GET_SENSOR_CAP,			//43.获取触发抓拍设置
	HHCMD_SET_SENSOR_CAP,			//44.设置触发抓拍设置
	HHCMD_GET_EXTINFO,				//45.获取扩展配置
	HHCMD_SET_EXTINFO,				//46.设置扩展配置
	HHCMD_GET_USERDATA,				//47.获取用户配置
	HHCMD_SET_USERDATA,				//48.设置用户配置
	HHCMD_GET_NTP,					//49.获取NTP配置
	HHCMD_SET_NTP,					//50.设置NTP配置
	HHCMD_GET_UPNP,					//51.获取UPNP配置
	HHCMD_SET_UPNP,					//52.设置UPNP配置
	HHCMD_GET_MAIL,					//53.获取MAIL配置
	HHCMD_SET_MAIL,					//54.设置MAIL配置
	HHCMD_GET_ALARMNAME,			//55.获取报警名配置
	HHCMD_SET_ALARMNAME,			//56.设置报警名配置
	HHCMD_GET_WFNET,				//57.获取无线网络配置
	HHCMD_SET_WFNET,				//58.设置无线网络配置
	HHCMD_GET_SEND_DEST,			//59.设置视频定向发送目标机
	HHCMD_SET_SEND_DEST,			//60.设置视频定向发送目标机
	HHCMD_GET_AUTO_RESET,			//61.取得定时重新注册
	HHCMD_SET_AUTO_RESET,			//62.设置定时重新注册
	HHCMD_GET_REC_SCHEDULE,			//63.取得录像策略
	HHCMD_SET_REC_SCHEDULE,			//64.设置录像策略
	HHCMD_GET_DISK_INFO,			//65.取得磁盘信息
	HHCMD_SET_MANAGE,				//66.设置命令和操作
	HHCMD_GET_CMOS_REG,				//67.取得CMOS参数
	HHCMD_SET_CMOS_REG,				//68.设置CMOS参数
	HHCMD_SET_SYSTEM_CMD,			//69.设置执行命令
	HHCMD_SET_KEYFRAME_REQ,			//70.设置关键帧请求
	HHCMD_GET_CONFIGENCPAR,			//71.取得视频参数
	HHCMD_SET_CONFIGENCPAR,			//72.设置视频参数

	//--------------------------    HH58系列、HH98系列及以后的设备用(添加)
	HHCMD_GET_ALL_PARAMETER_NEW,	//73.获取所有参数
	HHCMD_FING_LOG,					//74.查找日志(查询方式:0－全部，1－按类型，2－按时间，3－按时间和类型 0xFF-关闭本次搜索)
	HHCMD_GET_LOG,					//75.读取查找到的日志	
	HHCMD_GET_SUPPORT_AV_FMT,		//76.获取设备支持的编码格式、宽高及音频格式
	HHCMD_GET_VIDEO_CONFIG_NEW,		//77.取得视频参数（新）
	HHCMD_SET_VIDEO_CONFIG_NEW,		//78.设置视频参数（新）
	HHCMD_GET_VMOTION_CONFIG_NEW,	//79.取得移动报警参数（新）
	HHCMD_SET_VMOTION_CONFIG_NEW,	//80.设置移动报警参数（新）
	HHCMD_GET_VLOST_CONFIG_NEW,		//81.取得视频丢失报警参数（新）
	HHCMD_SET_VLOST_CONFIG_NEW,		//82.设置视频丢失报警参数（新）
	HHCMD_GET_SENSOR_ALARM_NEW,		//83.取得探头报警参数（新）
	HHCMD_SET_SENSOR_ALARM_NEW,		//84.设置探头报警参数（新）
	HHCMD_GET_NET_ALARM_CONFIG,		//85.取得网络故障报警参数（新）
	HHCMD_SET_NET_ALARM_CONFIG,		//86.设置网络故障报警参数（新）
	HHCMD_GET_RECORD_CONFIG,		//87.取得定时录像参数
	HHCMD_SET_RECORD_CONFIG,		//88.设置定时录像参数
	HHCMD_GET_SHOOT_CONFIG,			//89.取得定时抓拍参数
	HHCMD_SET_SHOOT_CONFIG,			//90.设置定时抓拍参数
	HHCMD_GET_FTP_CONFIG,			//91.取得FTP参数
	HHCMD_SET_FTP_CONFIG,			//92.设置定时抓拍参数
	HHCMD_GET_RF_ALARM_CONFIG,		//93.取得无线报警参数
	HHCMD_SET_RF_ALARM_CONFIG,		//94.设置定时抓拍参数
	HHCMD_GET_EXT_DATA_CONFIG,		//95.取得其它扩展参数(如平台设置其它参数)
	HHCMD_SET_EXT_DATA_CONFIG,		//96.设置定时抓拍参数
	HHCMD_GET_FORMAT_PROCESS,		//97.取得获取硬盘格式化进度
	HHCMD_GET_PING_CONFIG,			//98.取得PING 设置获取
	HHCMD_SET_PING_CONFIG,			//99.设置PING 设置设置

	//解码器命令
	DDCMD_GET_ALL_PARAMETER = 100,	//获取解码器所有设置
	DDCMD_GET_TIME,					//获取系统时间
	DDCMD_SET_TIME,					//设置系统时间
	DDCMD_GET_SYS_CONFIG,			//获取系统配置
	DDCMD_SET_SYS_CONFIG,			//设置系统配置
	DDCMD_GET_NET_CONFIG,			//获取网络配置
	DDCMD_SET_NET_CONFIG,			//设置网络配置
	DDCMD_GET_COM_CONFIG,			//获取串口配置
	DDCMD_SET_COM_CONFIG,			//设置串口配置
	DDCMD_GET_VIDEO_CONFIG,			//获取视频配置
	DDCMD_SET_VIDEO_CONFIG,			//设置视频配置
	DDCMD_GET_ALARM_OPT,			//获取报警选项
	DDCMD_SET_ALARM_OPT,			//设置报警选项
	DDCMD_GET_USER_INFO,			//获取用户设置信息
	DDCMD_SET_USER_INFO,			//设置用户设置信息
	DDCMD_GET_ALARM_RECORD,			//获取报警记录信息
	DDCMD_GET_ADRRESS_BOOK,			//获取地址薄配置
	DDCMD_SET_ADRRESS_BOOK,			//设置地址薄配置
	DDCMD_SET_COMM,					//设置发送串口数据
	DDCMD_SET_CMD,					//设置透明的命令
	DDCMD_GET_YUNTAI_INFO,			//获取云台信息
	DDCMD_GET_YUNTAI_CONFIG,		//获取云台配置
	DDCMD_SET_YUNTAI_CONFIG,		//设置云台配置
	DDCMD_GET_ONELINK_ADDR,			//获取解码器单路连接的信息
	DDCMD_SET_ONELINK_ADDR,			//设置解码器单路连接的信息
	DDCMD_GET_CYCLELINK_ADDR,		//获取解码器循环连接的信息
	DDCMD_SET_CYCLELINK_ADDR,		//设置解码器循环连接的信息
	DDCMD_GET_EXTINFO,				//获取扩展配置
	DDCMD_SET_EXTINFO,				//设置扩展配置
	DDCMD_GET_NTP,					//获取NTP配置
	DDCMD_SET_NTP,					//设置NTP配置
	DDCMD_GET_UPNP,					//获取UPNP配置
	DDCMD_SET_UPNP,					//设置UPNP配置
	DDCMD_GET_MAIL,					//获取MAIL配置
	DDCMD_SET_MAIL,					//设置MAIL配置
	DDCMD_GET_ALARMNAME,			//获取报警名配置
	DDCMD_SET_ALARMNAME,			//设置报警名配置
	DDCMD_GET_WFNET,				//获取无线网络配置
	DDCMD_SET_WFNET,				//设置无线网络配置
	DDCMD_GET_SEND_DEST,			//设置视频定向发送目标机
	DDCMD_SET_SEND_DEST,			//设置视频定向发送目标机
}HHCMD_NET;

//10，转发判断
typedef enum _RELAY_CHECK_RET
{
	RCRET_SUCCESS = 0,
	RCRET_FAILURE = -1,
	RCRET_AUTO_LINK = 0x0101,	
}RELAY_CHECK_RET;

//11，录像类型(新)
typedef enum  _HIDISK_RECTYPE_E
{
	HIDISK_RECTYPE_NONE		= 0x00000000,		

	HIDISK_RECTYPE_SENSOR	= 0x00000001,		//探头报警录像
	HIDISK_RECTYPE_MOTION	= 0x00000002,		//移动侦测报警录像
	HIDISK_RECTYPE_VILOST	= 0x00000004,		//视频丢失
	HIDISK_RECTYPE_RFALM	= 0x00000008,		//RF报警联动录像
	HIDISK_RECTYPE_NETALM	= 0x00000010,		//网络故障报警

	HIDISK_RECTYPE_TIMER	= 0x00000020,		//定时录像
	HIDISK_RECTYPE_MANUAL	= 0x00000040,		//手动录像
	
	HIDISK_RECTYPE_PREREC	= 0x40000000,		//预录像标志位
	HIDISK_RECTYPE_PHOTO	= 0x80000000,		//图片文件
}HIDISK_RECTYPE_E;
/*****************************************************************************/
/*********************************  三、回调函数  ****************************/
/*****************************************************************************/

//1，实时音视频数据流回调
typedef int  (WINAPI *ChannelStreamCallback)(HANDLE hOpenChannel,void *pStreamData,DWORD dwClientID,void *pContext,ENCODE_VIDEO_TYPE encodeVideoType,HHAV_INFO *pAVInfo);

//2，实时对讲音频数据流回调
typedef int  (WINAPI *TalkStreamCallback)(HANDLE hOpenChannel,void *pTalkData,UINT nTalkDataLen,void *pContext);

//3，转发服务的用户检测回调
typedef int	 (WINAPI *RelayCheckUserCallback)(RELAY_TYPE relayType,DWORD dwClientIP,WORD wClientPort,char *pszUserName,char *pszPassword,char *pszDeviceName,DWORD dwRequstChannel,BOOL bOnline,char *pDeviceIP,DWORD *pdwDevicePort,char *pContext);

//4，中心服务器模式用户检测回调
typedef int	 (WINAPI *CenterCheckUserCallback)(BOOL bOnLine,DVS_MACHINE_TYPE machineType,DWORD dwDeviceID,DWORD dwChannelNum,DWORD ip,WORD port,char *pszDeviceName,char *pszUserName,char *pszPassword,LPVOID pNetPar);

//5，搜索录像NVS回调
typedef void (WINAPI *SearchRecNVSCallback)(char *szNvsBuffer,int nBufferLen);

//6，搜索录像文件
//typedef void (WINAPI *SearchRecFileCallback)(void *pRecFile);
typedef void  (WINAPI *SearchRecFileCallback)(DWORD dwClientID,void *pRecFile);
typedef void  (WINAPI *SearchRecFileCallbackEx)(DWORD dwClientID,void *pRecFile);

//7，库消息回掉函数
typedef int	 (WINAPI *MessageNotifyCallback)(WPARAM wParam,LPARAM lParam);

//8，抓拍图片回调
typedef int  (WINAPI *PictureCallback)(HANDLE hPictureChn,void *pPicData,int nPicLen,DWORD dwClientID,void *pContext);

//9,录像回放回调
typedef int  (WINAPI *NetPlayCallback)(HANDLE hOpenChannel,void *pStreamData,BOOL bStream,int nDataLen,DWORD dwClientID,void *pContext);

/*****************************************************************************/
/******************************  四、接口结构类型定义  ***********************/
/*****************************************************************************/

//1,报警输出
typedef struct _ALARM_STATUS_OUTPUT
{
	BYTE			year;
	BYTE			month;
	BYTE			day;
	BYTE			week;
	BYTE			hour;
	BYTE			minute;
	BYTE			second;
	
	unsigned char	statusSensorAlarm;
	unsigned char	statusMotionAlarm;
	unsigned char	statusViLoseAlarm;
	unsigned char	SensorAlarmRec[MAX_SENSOR_NUM];
	unsigned char	MotionAlarmRec[MAX_VIDEO_NUM];
	unsigned char	ViLoseAlarmRec[MAX_VIDEO_NUM];
	unsigned char	statusAlarmOutput;
}ALARM_STATUS_OUTPUT;

//2，报警通知信息结构
typedef struct _ALARM_MSG_NOTIFY
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	ALARM_STATUS_OUTPUT		alarmStatus;
}ALARM_MSG_NOTIFY;

//3，报警输出(新)
typedef struct _ALARM_STATUS_OUTPUT_NEW
{
        unsigned char   year;
        unsigned char   month;
        unsigned char   day;
        unsigned char   week;
        unsigned char   hour;
        unsigned char   minute;
        unsigned char   second;
		unsigned char	millsecond;   

        unsigned int    SensorAlarm;
        unsigned int    MotionAlarm;
        unsigned int    ViLoseAlarm;
		unsigned int    RFSensorAlarm;
		unsigned int    NetAlarm;

        unsigned int    SensorAlarmRec[MAX_SENSOR_NUM];
        unsigned int    MotionAlarmRec[MAX_VIDEO_NUM];
        unsigned int    ViLoseAlarmRec[MAX_VIDEO_NUM];
        unsigned int    RFSensorAlarmRec[MAX_RF_SENSOR_NUM];
        unsigned int    NetAlarmRec;

        unsigned int    OutputStatus;
		
		unsigned int    reserved[19];
}ALARM_STATUS_OUTPUT_NEW;

//4，报警通知信息结构(新)
typedef struct _ALARM_MSG_NOTIFY_NEW
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	ALARM_STATUS_OUTPUT_NEW	alarmStatus;			//2009.03.09
}ALARM_MSG_NOTIFY_NEW;


//5，触发抓拍图像
typedef struct _SENSOR_PIC_NOTIFY
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	
	ALARM_STATUS_OUTPUT		alarmStatus;
	
	DWORD					dwChannelNo;
	DWORD					dwPicLen;
	LPVOID					pPicBuffer;
}SENSOR_PIC_NOTIFY;

//6，串口采集数据
//串口设置
typedef struct __COM_CONFIG
{
	DWORD 				Baudrate;						//串口波特率				300---115200
	BYTE				Databit;						//串口数据位长度			5=5位 6=6位 7=7位 8=8位	其他=8位
	BYTE				Stopbit;						//停止位位数				1=1位 2=2位 其他=1位
	BYTE				CheckType;						//校验						0=无  1=奇  2=偶  3=恒1  4=恒0 
	BYTE				Flowctrl; 						//软流控/硬流控/无流控		备用
}COM_CONFIG;

//透明通讯
typedef struct __COMM_CTRL
{
	BYTE				COMMNo;							//串口号	0 ~ 1
	COM_CONFIG			COMConfig;						//串口配置
	WORD				DataLength;						//数据长度
	BYTE				Data[256];						//数据
}COMM_CTRL;

typedef struct _COMM_DATA_NOTIFY
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	COMM_CTRL				commCtrl;
}COMM_DATA_NOTIFY;

//7，打开视频通道参数
typedef struct _HHOPEN_CHANNEL_INFO
{
	DWORD					dwClientID;
	UINT					nOpenChannel;
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
}HHOPEN_CHANNEL_INFO;

//HH58系列、HH98系列及以后的设备用, 兼容以前的设备
typedef struct _HHOPEN_CHANNEL_INFO_EX
{
	DWORD					dwClientID;
	UINT					nOpenChannel:8;				//通道号（0 ～ 3）
	UINT					nSubChannel:8;				//0: 打开主码流      1: 打开从码流	
	UINT					res:16;	
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
}HHOPEN_CHANNEL_INFO_EX;

//8，打开视频通道参数
typedef struct _HHOPEN_VIEWPUSH_INFO
{
	DWORD					dwClientID;
	UINT					nViewPushChannel;
	NET_PROTOCOL_TYPE		protocolType;
	HHAV_INFO				avInformation;
	
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	
	UINT					nScreenCount;
	UINT					nScreenIndex;
}HHOPEN_VIEWPUSH_INFO;

//9，打开的服务器信息
typedef struct _HH_SERVER_INFO
{
	HANDLE					hServer;
	char					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	char					szDeviceName[DVS_NAME_LEN+1];
	UINT					nDeviceID;
	
	char					szUserName[USER_NAME_LEN+1];
	char					szUserPassword[USER_PASSWD_LEN+1];
		
	DWORD					dwClientID;
	
	CONNECT_STATUS			logonStatus;
	UINT					nVersion;
	UINT					nLogonID;
	UINT					nPriority;
	UINT					nServerChannelNum;
	UINT					nLanguageNo;
	DVS_MACHINE_TYPE		nMachineType;
	BOOL					bPalStandard;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	HHAV_INFO				avInformation[MAX_VIDEO_NUM];
}HH_SERVER_INFO;

//10，打开的通道信息
typedef struct _HH_CHANNEL_INFO
{
	HANDLE					hOpenChannel;
	char					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	char					szDeviceName[DVS_NAME_LEN+1];
	
	char					szUserName[USER_NAME_LEN+1];
	char					szUserPassword[USER_PASSWD_LEN+1];
	
	DWORD					dwClientID;
	
	CONNECT_STATUS			openStatus;
	UINT					nVersion;
	UINT					nOpenID;
	UINT					nPriority;
	UINT					nOpenChannelNo;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	HHAV_INFO				avInformation;
	ENCODE_VIDEO_TYPE		encodeVideoType;
	
	NET_PROTOCOL_TYPE		protocolType;
	ChannelStreamCallback	funcStreamCallback;
	void					*pCallbackContext;
	
	DWORD					dwDeviceID;	//V4.0 add
}HH_CHANNEL_INFO;

//11，打开的解码器输入通道信息
typedef struct _HH_VIEWPUSH_INFO
{
	HANDLE				hOpenChannel;
	char				szServerIP[MAX_IP_NAME_LEN+1];
	UINT				nServerPort;
	char				szDeviceName[DVS_NAME_LEN+1];
	
	char				szUserName[USER_NAME_LEN+1];
	char				szUserPassword[USER_PASSWD_LEN+1];
	
	DWORD				dwClientID;
	
	CONNECT_STATUS		openStatus;
	UINT				nVersion;
	UINT				nOpenID;
	UINT				nPriority;
	UINT				nOpenChannelNo;
	UINT				nMulticastAddr;
	UINT				nMulticastPort;
	HHAV_INFO			avInformation;
	ENCODE_VIDEO_TYPE	encodeVideoType;
	NET_PROTOCOL_TYPE	protocolType;
	
	DVS_MACHINE_TYPE	nMachineType;
	DWORD				dwChannelNum;	//解码器最大路数
}HH_VIEWPUSH_INFO;

//12，对讲的信息
typedef struct _HH_TALK_INFO 
{
	HANDLE				hServer;
	char				szServerIP[MAX_IP_NAME_LEN+1];
	UINT				nServerPort;
	char				szDeviceName[DVS_NAME_LEN+1];
	
	char				szUserName[USER_NAME_LEN+1];
	char				szUserPassword[USER_PASSWD_LEN+1];
	
	//unsigned long		version;	
	void			   *pTalkContext;			//2009.04.01
	unsigned long		nMachineType;
	
	CONNECT_STATUS		logonStatus;
	//audio parameter
	UINT				nAudioEncodeType;
    UINT				nAudioChannels;
    UINT				nAudioBits;
    UINT				nAudioSamples;
}HH_TALK_INFO;

//13，语音广播的用户信息
typedef struct _HH_BROADCAST_USER
{
	HANDLE	hBroadcastUser;
	char	szServerIP[MAX_IP_NAME_LEN+1];
	DWORD	port;
	char	szDeviceName[DVS_NAME_LEN+1];	
	char	szUserName[USER_NAME_LEN+1];
	char	szUserPassword[USER_PASSWD_LEN+1];
	
	BOOL	bConnect;
	SOCKET	hSock;
	PVOID	pPar;
	//add v4.2
	DWORD				machineType;
	ENCODE_VIDEO_TYPE	audioType;
	HANDLE	hEventSigExist;
}HH_BROADCAST_USER;

//14，转发视频服务器
typedef struct _HH_RELAY_NVS
{
	RELAY_TYPE			relayType;
	char				szServerIP[MAX_IP_NAME_LEN+1];
	WORD				wServerPort;
	char				szDeviceName[DVS_NAME_LEN+1];
	DWORD				dwChannelNo;
	DWORD				dwCount;
}HH_RELAY_NVS;	

//15，百分比消息通知
typedef struct _HH_PERCENT_NOTIFY
{
	HANDLE				hLogon;
	DWORD				dwClientID;
	DWORD				dwPercent;
}HH_PERCENT_NOTIFY;

//16，视频文件参数
typedef struct _HHFILE_INFO
{
	char                szFileName[MAX_PATH];
	char				szServerIP[MAX_IP_NAME_LEN+1];
	WORD				wServerPort;
	char				szUserName[USER_NAME_LEN+1];
	char				szUserPassword[USER_PASSWD_LEN+1];
	BOOL                bRelay     ; // 此文件是否通过转发
}HH_FILE_INFO;

typedef struct _HHFILE_INFO_EX
{
	HIDISK_RECTYPE_E	nRecType;		//录像类型
	BYTE				nOpenChannel;	//通道号0~3
	BYTE				nSubChannel;	//0主码流，1次码流
	BYTE				mark;			//最后一条1,否则0
	BYTE				rsvd;		
	time_t				tmStart;		//开始时间段 time_t类型
	time_t				tmEnd;			//结束时间段 time_t类型
	long				nRecSize;		//录像总字节数		
	char                szFileName[MAX_PATH]; //yyyymmddhhmmss-yyymmddhhmmss
}HH_FILE_INFO_EX;

//17，打开视频文件参数
typedef struct _HHOPEN_FILE_INFO
{
	DWORD				dwClientID  ;
	UINT				nOpenChannel;
	NET_PROTOCOL_TYPE	protocolType;
	char				szDeviceName[DVS_NAME_LEN+1];
	HH_FILE_INFO        hhFile      ;       
	char                szOpenMode[5];
	DWORD				dwSocketTimeOut;
	
    // 输出
	DWORD				dwFileSize;         // 文件大小
	DWORD				dwStartTime;        // 播放开始时间(毫秒)
	DWORD				dwEndTime;          // 播放结束时间(毫秒)
	
	UINT				nVideoEncodeType;	//视频编码格式
	UINT				nAudioEncodeType;	//音频编码格式	
}HHOPEN_FILE_INFO;

typedef struct _INNER_OPEN_FILE_INFO_EX
{
	BYTE nOpenChannel;	//通道号0~3
	BYTE nSubChannel;	//0主码流，1次码流
	BYTE nPlayMode;		//播放模式，0：正常（Speed有效），1：直接下载
	BYTE nPlaySpeed;	//播放速度，0：正常，1：快2X，2:快4X，-1：慢2X，-2：慢4X
	long nRecType;		//0:录像,1:图片
	long tmStart;		//开始播放时间点 time_t类型
	long tmEnd;		    //结束播放时间点 time_t类型
}INNER_OPEN_FILE_INFO_EX;

typedef struct _HHOPEN_FILE_INFO_EX
{
	INNER_OPEN_FILE_INFO_EX	inner_ofi;
	DWORD					dwClientID;
	NetPlayCallback			funcNetRePlayCallback;
	void					*pCallbackContext;	
}HHOPEN_FILE_INFO_EX;

//18，启动搜索符合条件的NVS
typedef struct _HH_SEARCH_REC_NVS
{
	DWORD				dwClientID  ;
	// 存储录像文件的条件
	char                Date[11];// 条件1 录像日期 yyyy-mm-dd
    BYTE                recType ;// 条件2 录像类型: 0-所有，1-报警，2-手动，3-定时
	
	SearchRecNVSCallback	funcSearchRecNvsCallback;	
}HH_SEARCH_REC_NVS;

// 19，启动搜索符合条件的录像文件
typedef struct _HH_SEARCH_REC_FILE
{
	DWORD				dwClientID  ;
	
	// 存储录像文件的条件
    char                szDir[MAX_PATH]; // 条件1: " Datae\\Ip-NVS\\Camera\\"
	char				szTime1[6];      // 条件2 时间段1 hh:mm
	char				szTime2[6];      // 条件2 时间段2 hh:mm
    BYTE                recType ;	     // 条件3 录像类型: 0-所有，1-报警，2-手动，3-定时
	
	SearchRecFileCallback	funcSearchRecFileCallback;
}HH_SEARCH_REC_FILE;

typedef struct _INNER_SEARCH_REC_FILE_EX
{
    HIDISK_RECTYPE_E    nRecType;	        // 录像类型
	BYTE				nOpenChannel;		// 通道号0~3
	BYTE				nSubChannel; 		// 0:主码流，1:次码流
	BYTE				rsvd[2];
	long				tmStart;			// 查询的开始时间，time_t
	long				tmEnd;				// 查询的结束时间，time_t
}INNER_SEARCH_REC_FILE_EX;

typedef struct _HH_SEARCH_REC_FILE_EX
{
	INNER_SEARCH_REC_FILE_EX inner_srf;
	DWORD				dwClientID;			//上下文
	DWORD				dwSocketTimeOut;
	SearchRecFileCallbackEx	funcSearchRecFileCallback;
}HH_SEARCH_REC_FILE_EX;

//20，转发查询
typedef struct _RELAY_QUERY_INFO
{
	DWORD		dwSize;
	DWORD		dwServerLogonNum;
	DWORD		dwServerPreviewNum;
	DWORD		dwServerTalkNum;
	DWORD		dwServerBrdNum;
	DWORD		dwClientLogonNum;
	DWORD		dwClientPreviewNum;
	DWORD		dwClientTalkNum;
	DWORD		dwClientBrdNum;
	char		reserve[16];
}RELAY_QUERY_INFO;

//21，打开抓拍参数
typedef struct _HHOPEN_PICTURE_INFO
{
	DWORD					dwClientID;
	DWORD					nOpenChannel;	
	NET_PROTOCOL_TYPE		protocolType;
	PictureCallback			funcPictureCallback;
	void					*pCallbackContext;
}HHOPEN_PICTURE_INFO;

//22，打开的通道信息
typedef struct _HH_PICTURE_INFO
{
	HANDLE					hOpenChannel;
	char					szServerIP[MAX_IP_NAME_LEN+1];
	UINT					nServerPort;
	char					szDeviceName[DVS_NAME_LEN+1];
	
	char					szUserName[USER_NAME_LEN+1];
	char					szUserPassword[USER_PASSWD_LEN+1];
	
	DWORD					dwClientID;
	
	CONNECT_STATUS			openStatus;
	UINT					nVersion;
	UINT					nOpenID;
	UINT					nPriority;
	UINT					nOpenChannelNo;
	UINT					nMulticastAddr;
	UINT					nMulticastPort;
	UINT					nPicWidth;
	UINT					nPicHeight;
	UINT					nPicBits;
	int						picFormatType;//0:JPEG,1:BMP
	
	NET_PROTOCOL_TYPE		protocolType;
	PictureCallback			funcStreamCallback;
	void					*pCallbackContext;
	
	DWORD					dwDeviceID;
}HH_PICTURE_INFO;

typedef struct _HH_NET_TIME
{
	DWORD				dwYear;					// Year
	DWORD				dwMonth;				// Month
	DWORD				dwDay;					// Date
	DWORD				dwHour;					// Hour
	DWORD				dwMinute;				// Minute
	DWORD				dwSecond;				// Second
} HH_NET_TIME;

/*****************************************************************************/
/********************************  五、函数接口定义  *************************/
/*****************************************************************************/

//------------------------------  1、服务开启关闭  -------------------------------//
//启动服务
HHNET_API HHERR_CODE		WINAPI	HHNET_Startup(IN  HWND hNotifyWnd,IN  UINT nCommandID,IN DWORD dwFrameBufNum = 0,IN BOOL bReadyRelay = FALSE,IN BOOL bReadyCenter=FALSE,IN char *pLocalAddr=NULL);
//关闭服务
HHNET_API HHERR_CODE		WINAPI	HHNET_Cleanup();
//改变库通知应用的方式为回调函数
HHNET_API HHERR_CODE		WINAPI	HHNET_MessageCallback(MessageNotifyCallback pCallback);


//------------------------------  2、登录管理  ----------------------------------//
//登录服务器
HHNET_API HHERR_CODE		WINAPI	HHNET_LogonServer(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN	 char *pUserName,IN	 char *pUserPassword,IN DWORD dwClientID,OUT  HANDLE &hLogonServer,IN HWND hNotifyWindow = NULL);
//注销服务器
HHNET_API HHERR_CODE		WINAPI	HHNET_LogoffServer(IN  HANDLE hServer);
//读取登录服务器信息
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadServerInfo(IN  HANDLE hServer,OUT  HH_SERVER_INFO &serverInfo);

//程序升级
HHNET_API HHERR_CODE		WINAPI	HHNET_Update(IN HANDLE hServer,IN UPDATE_TYPE nUpdateType,IN char *pFilePathName);

//读取登录服务器配置信息
HHNET_API HHERR_CODE		WINAPI  HHNET_GetServerConfig(IN  HANDLE hServer,IN  HHCMD_NET nConfigCommand,OUT  char *pConfigBuf,IN OUT  UINT &nConfigBufSize,IN  OUT  DWORD *pAppend=NULL);
//设置登录服务器配置信息
HHNET_API HHERR_CODE		WINAPI  HHNET_SetServerConfig(IN  HANDLE hServer,IN  HHCMD_NET nConfigCommand,IN   char *pConfigBuf,IN  UINT nConfigBufSize,IN  DWORD dwAppend=0);



//-------------------------------  3、预览通道  ---------------------------------//
//打开视频通道
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenChannel(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,IN  HHOPEN_CHANNEL_INFO *pOpenInfo,OUT  HANDLE &hOpenChannel,IN HWND hNotifyWindow = NULL);
//关闭视频通道
HHNET_API HHERR_CODE		WINAPI	HHNET_CloseChannel(IN  HANDLE hOpenChannel);

//读取打开视频通道信息
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadChannelInfo(IN  HANDLE hOpenChannel,OUT  HH_CHANNEL_INFO &channelInfo);



//-------------------------------  4、对讲服务  ---------------------------------//
//请求打开对讲
HHNET_API HHERR_CODE		WINAPI	HHNET_TalkRequsest(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN	 char *pUserName,IN	 char *pUserPassword,IN TalkStreamCallback funcTalkCallback,IN void *pContext,OUT  HANDLE &hTalk,IN HWND hNotifyWindow = NULL);
//结束对讲
HHNET_API HHERR_CODE		WINAPI	HHNET_TalkStop(IN HANDLE hTalk);

//读取打开对讲信息
HHNET_API HHERR_CODE		WINAPI	HHNET_TalkReadInfo(IN HANDLE hTalk,HH_TALK_INFO &talkInfo);
//发送对讲数据
HHNET_API HHERR_CODE		WINAPI	HHNET_TalkSend(IN HANDLE hTalk,IN char *pTalkData,IN UINT nDataLen);



//------------------------------  5、语音广播  ---------------------------------//
//启动语音广播
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastStart(IN HWND hNotifyWindow = NULL);
//关闭语音广播
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastStop();

//添加一个视频服务器到语音广播组
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastAddClient(IN  char *pServerIP,IN  WORD wServerPort,IN char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,OUT HANDLE	&hBrdClient);

//语音广播组中删除一个用户
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastDelClient(IN HANDLE hBrdClient);

//得到广播组中用户信息
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastClientInfo(IN HANDLE hBrdClient,OUT HH_BROADCAST_USER *clientInfo);

//取得所有语音广播用户的状态
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastAllClientInfo(IN  void *pInfoBuf,IN DWORD &dwInfoBufSize);

//发送语音广播数据
HHNET_API HHERR_CODE		WINAPI	HHNET_BroadcastSend(IN char *pTalkData,IN UINT nDataLen,ENCODE_VIDEO_TYPE audoEncType=EV_TYPE_NONE);



//------------------------------  6、视频输入  ---------------------------------//
//请求打开解码器输入通道
HHNET_API HHERR_CODE		WINAPI	HHNET_ViewPushRequest(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,IN HHOPEN_VIEWPUSH_INFO *pOpenViewPushInfo,OUT  HANDLE &hViewPush,IN HWND hNotifyWindow = NULL);

//关闭打开的解码器输入通道
HHNET_API HHERR_CODE		WINAPI	HHNET_ViewPushStop(IN HANDLE hViewPush);

//读取打开的解码器输入通道信息
HHNET_API HHERR_CODE		WINAPI	HHNET_ViewPushReadInfo(IN HANDLE hViewPush,OUT HH_VIEWPUSH_INFO &viewPushInfo);

//往打开的解码器输入通道里送数据
HHNET_API int				WINAPI	HHNET_ViewPushSend(IN HANDLE hViewPush,IN char *pViewPushData,IN UINT nDataLen,ENCODE_VIDEO_TYPE encodeVideoType);

//切换显示窗口
HHNET_API HHERR_CODE		WINAPI	HHNET_ViewPushScreenMode(IN HANDLE hViewPush,IN UINT nScreenCount,IN UINT nScreenIndex);



//------------------------------  7、转发服务  ---------------------------------//
//启动转发服务
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayStart(IN WORD wListenPort = 5000,IN char *pMultiAddr = "234.100.100.100",IN WORD wMultiPort = 5000,
													 IN DWORD dwVideoBufNum = 1024,IN DWORD dwAudioBufNum = 100,IN DWORD dwChannelPreviewNum = 50,
													 IN DWORD dwAllPreviewNum = 200,IN RelayCheckUserCallback funcRelayCheck = NULL,
													 IN char *pRelayAddr = NULL,IN HWND hNotifyWindow = NULL);

//关闭转发服务
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayStop();

//得到转发的NVS信息
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayGetNVS(IN RELAY_TYPE relayType,OUT HH_RELAY_NVS *pRelayNVS,IN OUT DWORD *pRelayNVSBufSize);

//删除转发的NVS
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayDeleteNVS(IN HH_RELAY_NVS relayNVS);

//得到转发的NVS的用户信息
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayGetNVSClient(IN HH_RELAY_NVS relayNVS,OUT SOCKADDR_IN *pAddrList,IN OUT DWORD *pAddrListSize);

//转发服务器查询
HHNET_API HHERR_CODE		WINAPI	HHNET_RelayServerQuery(IN char *pRelayServerIP,IN WORD wRelayServerPort,IN char *pUserName,IN char *pPassword,OUT RELAY_QUERY_INFO *pRelayQueryInfo,IN OUT DWORD &dwSize);


//----------------------------  8、中心管理服务器  -------------------------------//
//启动中心管理服务
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_Start(IN CenterCheckUserCallback checkNvsCallback,IN WORD wListenPort = 6000,IN HWND hNotifyWindow = NULL);

//关闭中心管理服务
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_Stop();

//以中心模式登录
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_LogonServer(IN DWORD dwDeviceID,IN DWORD dwClientID,OUT HANDLE &hLogon);

//以中心模式打开预览 
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_OpenChannel(IN DWORD dwDeviceID,IN  HHOPEN_CHANNEL_INFO *pOpenInfo,OUT HANDLE &hPreview);

//以中心模式打开对讲
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_TalkRequest(IN DWORD dwDeviceID,IN TalkStreamCallback funcTalkCallback,IN void *pContext,OUT HANDLE &hTalk);

//以中心模式打开语音广播
HHNET_API HHERR_CODE		WINAPI	HHNET_CS_BroadcastAddClient(IN DWORD dwDeviceID,OUT HANDLE &hBrdClient);



//------------------------------  9、DDNS域名解析  ---------------------------------//
//从域名服务器获取信息
HHNET_API HHERR_CODE		WINAPI	HHNET_GetInfoByDDNS(IN char *pDDNSIP,IN WORD wDDNSPort,IN char *pRegisterName,OUT char *pRegisterIP,OUT WORD *pRegisterWebPort,OUT WORD *pRegisterDataPort);



//------------------------------   10、搜索配置    ---------------------------------//
//搜索网上设备
HHNET_API HHERR_CODE		WINAPI	HHNET_SearchAllServer(UINT nTimeWait,
														  void(WINAPI *CallbackServerFind)(DVS_MACHINE_TYPE nDeviceType,char *pDeviceName,
														  char *pIP,BYTE macAddr[6],WORD wPortWeb,WORD wPortListen,char *pSubMask,
														  char *pGateway,char *pMultiAddr,char *pDnsAddr,WORD wMultiPort,int nChannelNum,int nFindCount,DWORD dwDeviceID));
//设置视频服务器网络配置
HHNET_API HHERR_CODE		WINAPI	HHNET_ConfigServer(BYTE macAddr[6],char *pUserName,char *pUserPassword,
													   char *pIP,char *pDeviceName,char *pSubMask,char *pGateway,char *pMultiAddr,
													   char *pDnsAddr,WORD wPortWeb,WORD wPortListen,WORD wPortMulti);


//------------------------------  11、读录像文件  -------------------------------//
//打开视频文件	fopen
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenFile(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,HHOPEN_FILE_INFO *pOpenInfo,OUT  HANDLE &hFile);
//关闭视频文件	fclose
HHNET_API HHERR_CODE		WINAPI	HHNET_CloseFile(IN  HANDLE hFile);
//读视频文件	fread
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadFile(IN  HANDLE hFile ,IN UINT size,IN UINT count,OUT void *buffer,OUT UINT &nRealReadLen);
//写视频文件	fwrite
HHNET_API HHERR_CODE		WINAPI	HHNET_WriteFile(IN  HANDLE hFile,IN const void *buffer, IN UINT size, IN UINT count, OUT UINT &nRealWriteLen);
//定位文件指针	fseek
HHNET_API HHERR_CODE		WINAPI	HHNET_SeekFile(IN  HANDLE hFile, IN long offset, IN int origin );
//获取指针位置	ftell
HHNET_API HHERR_CODE		WINAPI	HHNET_TellFile(IN  HANDLE hFile, OUT long &pos);
//读文件是否结束feof
HHNET_API HHERR_CODE		WINAPI	HHNET_EofFile(IN  HANDLE hFile, OUT int &ret);


//读下一桢 如果返回 HHERR_SUCCESS 且 nOutLen=0标志读到文件尾,本桢无效)
//根据本次输出 bRemain 值，确定是否还有下一桢可读
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadFirstFrame(IN  HANDLE hFile, void *outBuf, OUT UINT &nOutLen,OUT long &dwRemain);
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadNextFrame(IN  HANDLE hFile,  void *outBuf, OUT UINT &nOutLen,OUT long &dwRemain);


//------------------------------  12、搜索NVS录像文件  -------------------------------//
//开启搜索
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenSearchRecInfo(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pUserName,IN  char *pUserPassword,OUT  HANDLE &hSearch);
//关闭搜索
HHNET_API HHERR_CODE		WINAPI	HHNET_CloseSearchRecInfo(IN  HANDLE hSearch);
//搜索录像NVS
HHNET_API HHERR_CODE		WINAPI	HHNET_SearchRecNVS( IN  HANDLE hSearch,HH_SEARCH_REC_NVS  *pSearchInfo);
//搜索录像文件
HHNET_API HHERR_CODE		WINAPI	HHNET_SearchRecFile(IN  HANDLE hSearch,HH_SEARCH_REC_FILE *pSearchInfo);


//------------------------------  13、前端抓拍  -------------------------------//
//打开抓拍通道
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenPicture(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pDeviceName,IN  char *pUserName,IN  char *pUserPassword,IN  HHOPEN_PICTURE_INFO *pOpenInfo,OUT  HANDLE &hOpenChannel,IN HWND hNotifyWindow = NULL);
//关闭抓拍通道
HHNET_API HHERR_CODE		WINAPI	HHNET_ClosePicture(IN  HANDLE hOpenPicture);
//立即抓拍一副图片
HHNET_API HHERR_CODE		WINAPI	HHNET_CapturePicture(IN  HANDLE hOpenPicture);
//读取抓拍通道信息
HHNET_API HHERR_CODE		WINAPI	HHNET_ReadPictureInfo(IN  HANDLE hOpenPicture,OUT  HH_PICTURE_INFO &channelInfo);


//------------------------------- 14、新增远程回放 -----------------------------//
//开启搜索
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenSearchRecInfoEx(IN  char *pServerIP,IN  WORD wServerPort,IN  char *pUserName,IN  char *pUserPassword,OUT  HANDLE &hSearch,OUT BOOL & bSupportNew);
//搜索录像文件
HHNET_API HHERR_CODE		WINAPI	HHNET_SearchRecFileEX(IN  HANDLE hSearch,HH_SEARCH_REC_FILE_EX *pSearchInfo);
//打开远程录像文件
HHNET_API HHERR_CODE		WINAPI	HHNET_OpenFileEx(char *pServerIP,WORD wServerPort,char *pDeviceName,char *pUserName,char *pUserPassword,HHOPEN_FILE_INFO_EX *pOpenInfo,HANDLE &hFile);
//重新定位录像文件
HHNET_API HHERR_CODE		WINAPI	HHNET_SeekFileEx(IN  HANDLE hFile, IN long nSeekTime,IN BOOL bKeyFrame);
//调整远程回放的速度
HHNET_API HHERR_CODE		WINAPI	HHNET_SpeedFile(IN  HANDLE hFile, IN short nMask, IN BYTE nPlayMode,IN BYTE nPlaySpeed);
//单步远程回放
HHNET_API HHERR_CODE		WINAPI	HHNET_StepFile(IN  HANDLE hFile, IN BYTE bKeyFrame,IN BYTE nStepMode);

/*****************************************************************************/
/************************  六、设备端(NVS、IPCamera)的配置信息结构  **********/
/*****************************************************************************/

//------------------------------(I)编码器参数设置结构------------------------//
//1，日期时间结构
typedef  struct  _DVS_DATE
{
	BYTE		year;									//年
	BYTE		month;									//月
	BYTE		day;									//日
	BYTE		week;									//周
	BYTE		hour;									//小时
	BYTE		minute;									//分钟
	BYTE		second;									//秒
}DVS_DATE;

//2，时间段结构：定义一天的起始时间和结束时间
typedef struct _TIME_SEGMENT
{
	BYTE 		bDetectOpen;							//检测开关
	BYTE        nBgnHour ;								//开始时
	BYTE        nBgnMinute ;							//开始分
	BYTE        nEndHour ;								//结束时
	BYTE        nEndMinute ;							//结束分
}TIME_SEGMENT;

//3，音频设置
typedef struct _AUDIO_CONFIG
{
	BYTE		Open:1;									//音频是否打开
	BYTE		MicOrLine:1;							//音频输入模式：麦克或线输入
	BYTE		resver:6;
	BYTE		Type;									//压缩格式
	DWORD		Bitrate ;								//码率
	DWORD		SampleBitrate ;							//采样率
}AUDIO_CONFIG;

//4，视频设置
typedef struct _VIDEO_CONFIG
{	
	DWORD		KeyInterval;							//I 帧间隔
	DWORD		Bitrate ;								//码率
	BYTE		Qulity;									//质量1--31
	float		FrameRate ;								//帧率
	BYTE		BitflowType; 							//码流类型 		   0:VBR,1:CBR
	
	BYTE		DateOSD; 								// 0:不叠加日期,   1:叠加日期 
	BYTE		TimeOSD; 								// 0:不叠加时间,   1:叠加时间 
	BYTE		WeekOSD; 								// 0:不叠加星期,   1:叠加星期 
	BYTE		TitleOSD;								// 0:不叠加标题,   1:叠加标题 
	BYTE		BitrateOSD;								// 0:不叠加码率,   1:叠加码率 	
	char    	Title[CAM_TITLE_LEN+ 1];				// 标题字符        16个字符  8个汉字
	
	BYTE 		Brightness;								//亮度
	BYTE 		Hue;									//色调
	BYTE 		Saturation;								//饱和度
	BYTE 		Contrast;								//对比度
	BYTE 		Protocol;								//协议
	BYTE 		YTAddr;									//解码器地址
}VIDEO_CONFIG;

//5，移动侦测设置
typedef struct _VIDEO_MOTION_CONFIG
{
	BYTE 		DetectLevel;							//移动检测灵敏度
	BYTE 		DetectOpen;								//移动检测开关
	WORD 		AutoClearTime;							//移动报警自动清除时间	
	BYTE 		Output;									//移动报警联动输出				 0---3	
	BYTE 		Record;									//移动报警联动录像				 0---3	
	BYTE 		DetectTest;								//移动报警检测测试开关
	DWORD 		DetectArea[18];							//移动检测区域	
	TIME_SEGMENT	tSchTable[8] ;						//移动检测时间表1				 0: 每天
}VIDEO_MOTION_CONFIG;

//6，图像屏蔽设置
typedef struct _VIDEOMASK_CONFIG 
{
	BYTE 		MaskOpen;								//视频屏蔽开关		0:关         1：开
	DWORD 		MaskArea[18];							//视频屏蔽区域	
} VIDEOMASK_CONFIG;

//7，视频丢失设置
typedef struct _VIDEOLOSE_CONFIG
{
	BYTE		DetectOpen;								//视频丢失检测
	BYTE 		Output;									//视频丢失报警联动输出			 0---3		
	BYTE 		Record;									//视频丢失联动录像				 0---3	
	WORD		AutoClearTime;							//视频丢失报警自动清除时间
} VIDEOLOSE_CONFIG;

//8，探头报警侦测设置
typedef struct _SENSOR_CONFIG 
{
	BYTE		SensorType;								//0:常开探头	1:常闭探头
	BYTE 		DetectOpen;								//检测开关
	WORD 		AutoClearTime;							//探头报警自动清除时间	
	BYTE 		Output;									//探头报警联动输出				 0---3	
	BYTE 		Record;									//探头报警联动录像				 0---3	
	TIME_SEGMENT	tSchTable[8] ;						//探头检测时间表1				 0: 每天
} SENSOR_CONFIG;

//9，用户设置
typedef struct _USER_CONFIG
{
	DWORD 		Level;									//权限
	char 		Name[USER_NAME_LEN + 1];				//用户名
	char 		Password[USER_PASSWD_LEN + 1];			//用户密码
} USER_CONFIG;

//10，网络设置结构
typedef struct _NET_CONFIG
{	
	DWORD             	IPAddr ;						//IP地址
	DWORD             	SubNetMask ;					//掩码
	DWORD             	GateWay ;						//网关

   	WORD             	ComPortNo;						//设置接收客户端命令端口号        UDP	
   	WORD             	WebPortNo;						//Webserver端口     			  TCP
	DWORD             	MultiCastIPAddr ;				//多播IP地址
   	WORD             	MultiCastPortNo;				//UDP传输起始端口<多播传输>
	
	BYTE			   	RT8139MAC[6];      				//人工设置网卡的MAC地址		5---0有效
   	BYTE             	DHCP;							//DHCP 开关					0	关		1:开
   	
	BYTE             	PppoeOpen;						//PPPOE 开关     	
	char				PppoeName[PPPPOE_NAME_LEN+1];	//拨号用户名
	char				PppoePass[PPPPOE_PASSWD_LEN+1]; //拨号密码	
	DWORD             	PppoeTimes;   					//在线时间
	DWORD             	PppoeIPAddr ;					//PPPOEIP地址		报警回传IP	
	
	DWORD				DdnsOpen;						//DDNS开关
	char				DdnsName[DDNS_NAME_LEN+1];		//注册主机名称
	char				DdnsPass[DDNS_PASS_LEN+1];		//注册主机密码	
	
	char				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS服务器
	WORD				DdnsPortNo;						//DDNS服务器端口
	WORD				DdnsMapWebPort;					//本地WEB映射端口
	WORD				DdnsMapDataPort;				//本地数据映射端口

	DWORD				DNSHostIP;						//DNS的IP
	
	BOOL				ConnectCenter;					//是否主动连接中心
	char				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//中心IP
	WORD				ConnectCenterPort;						//中心端口

	WORD				appFunction;					//实现功能定义,以bit位表示:0-PPPOE,1-NTP,2-UPNP,3-WF,4-MAIL,5-定向发送，6:-无线探头 8-带存储功能
	BYTE				tcpSendInterval;
	BYTE				udpSendInterval;
	WORD				PacketMTU;

	BYTE				CaptureMode;					//抓拍模式
	BYTE				CapturePort[MAX_SENSOR_NUM];	//抓拍通道(0-3bit: 分别表示1 ~ 4号通道  1:开  0: 关)

	union
	{
		DWORD			DdnsIP2;						//DDNS 2的IP,非网络字节次序
		DWORD			DNSHostIP2;						//DNS  2
	};

	WORD				DdnsPortNo2;					//DDNS 2的端口

	char				sysByname[DVS_NAME_LEN+1];		//域名
	BYTE				domainSetState;					//0－成功；1－名字存在，修改新域名；2－正在申请；3－失败
} NET_CONFIG;

//11，调试信息开关
typedef struct _DEBUG_CONFIG
{
	BYTE				Status;							//0：关		1: 开
}DEBUG_CONFIG;

//12，输出继电器控制
typedef struct __OUTPUT_CTRL
{
	BYTE				ChannelNo;						//继电器号	0 ~ MAX_OUTPUT_NUM - 1
	BYTE				Status;							//0：关		1: 开	
}OUTPUT_CTRL;

//13，云台控制
typedef struct __PAN_CTRL
{
	BYTE				ChannelNo;						//通道号	0 ~ PORTNUM - 1
	BYTE				COMMNo;							//串口号	0 ~ 1
	BYTE				PanType;						//云台协议序号 0 ~ YUNTAI_PROTOCOL_NUM - 1
	BYTE				PanCmd;							//云台控制命令
	BYTE				Data1;							//数据1		（预置、调用号）
	BYTE				Data2;							//数据2		（备用）
}PAN_CTRL;

//14，视频信号参数
typedef struct __VIDEO_SIGNAL_CONFIG
{
	BYTE				ChannelNo;						//通道号	0 ~ PORTNUM - 1
	BYTE 				ChannelNum;						//通道数<NVS总的通道数，因为单路、四路的参数默认值是不同的>
	BYTE 				Brightness;						//亮度
	BYTE 				Hue;							//色调
	BYTE 				Saturation;						//饱和度
	BYTE 				Contrast;						//对比度
}VIDEO_SIGNAL_CONFIG;

//15，TW2824参数
typedef struct _TW2824_CTRL
{
	BYTE				Page;							//页
	BYTE 				RegNo;							//寄存器
	BYTE 				Data;							//数据
	UINT				nReserved[8];					//保留
}TW2824_CTRL;

//16，报警信息
typedef  struct  _ALARM_INFO
{
	BYTE	SensorAlarm[MAX_SENSOR_NUM];				//探头报警
	BYTE	SensorAlarmOut[MAX_SENSOR_NUM];				//探头报警输出
	BYTE	MotionAlarm[MAX_VIDEO_NUM];					//视频移动
	BYTE	MotionAlarmOut[MAX_VIDEO_NUM];				//视频移动报警输出
	BYTE	ViLoseAlarm[MAX_VIDEO_NUM];					//视频丢失
	BYTE	ViLoseAlarmOut[MAX_VIDEO_NUM];				//视频丢失报警输出
} ALARM_INFO;

//17，云台信息
typedef struct _YUNTAI_INFO
{
	char 		Name[YUNTAI_NAME_LEN + 1];				//云台名称
	COM_CONFIG	ComSet;									//通讯协议<波特率...>
}YUNTAI_INFO;

//18，配置信息
typedef struct _DVS_CONFIG
{
   	char               	sysName[DVS_NAME_LEN + 1];		//名字
	BYTE				sysInputNum;					//路数
	BYTE				sysType;						//机器型号	0:CIF  1:HD1  2:D1  
	BYTE				sysVideoFormat;					//编码格式	
    BYTE				sysLanguage;					//语言
    BYTE				sysStandard;					//制式		0:PAL  1:NTSC
	DWORD      			sysID;  						//每台机器有个ID号  	
	DWORD      			sysVer;  						//软件版本  		
}DVS_CONFIG;

//19，登录的用户用户信息
typedef struct _USER_DETAIL
{
	BOOL				bLogon;							//TRUE-登陆用户,FALSE-预览用户
	DWORD 				Level;							//权限
	char 				Name[USER_NAME_LEN+1];			//用户名
	char 				Password[USER_PASSWD_LEN+1];	//用户密码
	NET_PROTOCOL_TYPE	protocolType;					//协议
	DWORD				clientIP;						//IP
	DWORD				clientPort;						//端口
}USER_DETAIL;

typedef struct _USER_INFO_HUANGHE
{
	DWORD				dwLogonNum;
	DWORD				dwPreviewNum;
	USER_DETAIL			userDetail[MAX_LOGON_NUM+MAX_LINKVIEW_NUM+MAX_MULTIVIEW_NUM];
}USER_INFO_HUANGHE;

//20，DDNS设置
typedef struct _DDNS_SET
{
	BOOL				bDdnsStart;
	char				szDdnsIP[DDNS_SERVER_NAME_LEN+1];
	DWORD				dwDdnsPort;
	char				szDdnsName[DVS_NAME_LEN+1];
	DWORD				dwMapWebPort;
	DWORD				dwMapDataPort;
}DDNS_SET;

//21，所有参数信息
typedef struct _DVS_Parameter 
{
   	char               	sysName[DVS_NAME_LEN + 1];		//名字
	BYTE				sysInputNum;					//路数
	BYTE				sysType;						//机器型号	0:CIF  1:HD1  2:D1  
	BYTE				sysVideoFormat;					//编码格式	
    BYTE				sysLanguage;					//语言
    BYTE				sysStandard;					//制式		0:PAL  1:NTSC
	DWORD      			sysID;  						//每台机器有个ID号  	
	DWORD      			sysVer;  						//软件版本  			
	VIDEO_CONFIG		sysVideo[MAX_VIDEO_NUM];		//视频
	VIDEO_MOTION_CONFIG	sysVideoMotion[MAX_VIDEO_NUM];	//视频移动
	VIDEOMASK_CONFIG	sysVideoMask[MAX_VIDEO_NUM];	//视频屏蔽
	VIDEOLOSE_CONFIG	sysVideoLose[MAX_VIDEO_NUM];	//视频丢失
	AUDIO_CONFIG		sysAudio[MAX_AUDIO_NUM];		//音频
	NET_CONFIG			sysNet;							//网络设置
	COM_CONFIG			sysCom[MAX_COM_NUM];			//串口
	SENSOR_CONFIG		sysSensor[MAX_SENSOR_NUM];		//侦测
	USER_CONFIG			sysUser[MAX_USER_NUM];			//用户
	BYTE				YunTaiProtocolNum;				//云头协议数
	YUNTAI_INFO 		YunTaiInfo[MAX_YUNTAI_PROTOCOL_NUM];//协议信息
} DVS_Parameter ;

//22，NTP配置
typedef struct _NTP_CONFIG
{
	DWORD			ntpOpen;					//NTP开关
	DWORD			ntpTimeZone;				//时区
	char			ntpHost[DOMAIN_NAME_LEN];	//NTP Server
}NTP_CONFIG;

//23，UPNP配置
typedef struct _UPNP_CONFIG
{
	WORD			upnpOpen;					//UPNP开关
	BYTE			upnpEthNo;					//UPNP网卡 0－有线，1－无线
	BYTE			upnpMode;					//UPNP模式 0－指定，1－自动
	WORD			upnpPortWeb;				//UPNP WEB端口
	WORD			upnpPortData;				//UPNP DATA端口
	DWORD			upnpHost;					//UPNP主机
	WORD			upnpStatusWeb;				//UPNP WEB状态
	WORD			upnpStatusData;				//UPNP DATA状态
}UPNP_CONFIG;

//24，Email配置
typedef struct _MAIL_CONFIG
{
	char			smtpServer[DOMAIN_NAME_LEN];	//发送服务器
	char			pop3Server[DOMAIN_NAME_LEN];	//接收服务器
	char			fromMailAddr[DOMAIN_NAME_LEN];	//邮件发送地址
	char			toMailAddr[DOMAIN_NAME_LEN];	//邮件接收地址
	char			ccMailAddr[DOMAIN_NAME_LEN];	//邮件抄送地址
	char			smtpUser[DOMAIN_NAME_LEN];		//SMTP 用户名
	char			smtpPassword[DOMAIN_NAME_LEN];  //SMTP 用户密码
	char			pop3User[DOMAIN_NAME_LEN];		//POP3 用户名
	char			pop3Password[DOMAIN_NAME_LEN];	//POP3 用户密码
		
	DWORD			motionMailOpen;					//视频移动触发MAIL开关
	DWORD			motionMail[MAX_VIDEO_NUM];		//视频移动触发抓拍发送MAIL开关
	DWORD			sensorMailOpen;					//探头报警触发MAIL开关
	DWORD			sensorMail[MAX_SENSOR_NUM];		//探头报警触发抓拍发送MAIL开关
	DWORD			viloseMailOpen;		

	DWORD			timeMailOpen;					//定时发送(/分)
	DWORD			timeVideoMail[MAX_VIDEO_NUM];	//视频定时抓拍发送MAIL开关
	
	char			subjectMail[EMAIL_TITLE_LEN];	//邮件头
	char			textMail[EMAIL_TITLE_LEN];		//邮件内容
		
	DWORD			sendMailCount;					//状态: 发送的email记数	
	DWORD			sendNow;						//立即发送
	WORD			smtpPort;						//SMTP 端口
	WORD			popPort;						//POP3 端口
	WORD			protocolType;					//SSL
	char			res[6];
}MAIL_CONFIG;

typedef enum _WF_AUTH_TYPE		//主认证加密类型
{
	WF_AUTH_NONE	= 0x00,
	WF_AUTH_WEP		= 0x01,
	WF_AUTH_WPA		= 0x02,
	WF_AUTH_WPA2	= 0x03,
	WF_AUTH_WPAWPA2	= 0x04,
}WF_AUTH_TYPE;


typedef enum _WF_ENC_TYPE		//辅助认证加密
{
	WF_ENC_NONE		= 0x00,		//WEP  开放系统
	WF_ENC_WEP		= 0x01,		//WEP  共享密匙
	WF_ENC_TKIP		= 0x02,		//WEP  自动选择
	WF_ENC_AES		= 0x03,
}WF_ENC_TYPE;

//25，无线网络配置
typedef struct _WF_NET_CONFIG
{
	DWORD			dwSize;							//大小
	WORD			wfOpen;							//是否打开无线
	WORD			dhcpOpen;						//DHCP开关
	//
	DWORD			ipAddress;						//IP地址
	DWORD			subMask;						//子网掩码
	DWORD			gateWay;						//网关
	DWORD			dnsIP1;							//DNS服务器1 IP
	DWORD			dnsIP2;							//DNS服务器2 IP
	BYTE			macAddress[6];
	//
	BYTE			ssidLen;						//SSID名称长度
	BYTE			pswLen;							//密码长度

	char			ssidName[34];					//SSID名称
	char			pswText[34];					//密码
	DWORD			channel;						//通道
	DWORD			bps;							//码率
	DWORD			type;
	BYTE			wfAuthType;						//主认证加密类型
	BYTE			wfEncType;						//辅助认证加密
	char			reserve[10];
}WF_NET_CONFIG;

//26，报警输入输出名称定义
typedef struct _ALARM_INOUT_NAME
{
	char			alarmInName[MAX_SENSOR_NUM][CAM_TITLE_LEN+2];	//探头名
	char			alarmOutName[MAX_OUTPUT_NUM][CAM_TITLE_LEN+2];	//报警输出名
}ALARM_INOUT_NAME;

//27，视频定向发送设置
typedef struct _SEND_DEST
{	
	DWORD			dwSet[MAX_VIDEO_NUM];			//发送开关
	DWORD			dwStreamSend[MAX_VIDEO_NUM];	//发送开关
	DWORD			dwStreamDestIP[MAX_VIDEO_NUM];	//目的IP,网络字节顺序
	DWORD			dwStreamDestPort[MAX_VIDEO_NUM];//目的端口
	char			res[16];
}SEND_DEST;

//28，自动重新注册
typedef struct _AUTO_RESET_TIME
{
	BYTE			open;				//bit 1:hour,bit 2:day,bit 3:week	
	BYTE			second;
	BYTE			minute;
	BYTE			hour;
	BYTE			week;				//0 星期日，1 星期一，2 星期二 

	BYTE			res[3];
}AUTO_RESET_TIME;

//29，录像参数
//在HH52系列中使用
//在HH58、HH98系列中不再使用
typedef struct _CH_RECORD_CONFIG		//sizeof() = 84
{
	WORD 			KeepTime;			//某个通道的录像文件保存天数
	WORD     		reserve;
	TIME_SEGMENT	tSchTable1[8] ;		//某个通道的定时录像时间段1 (40)
	TIME_SEGMENT	tSchTable2[8] ;		//某个通道的定时录像时间段2 (40)
}CH_RECORD_CONFIG;

typedef struct _RECORD_CONFIG_HUANGHE			//sizeof() = 360
{
	BYTE		 PackageTime;	  		//文件打包时间
	BYTE 		 OverWrite;        		//auto overwrite 
	BYTE     	 reserve[22];
	CH_RECORD_CONFIG ChRecordCfg[MAX_VIDEO_NUM];//通道的录像参数(336)
}RECORD_CONFIG_HUANGHE;

//30，磁盘信息
//在HH58、HH98系列中下面结构加了4个字节
typedef struct _DISK_INFO
{
	DWORD	DiskNum;					//磁盘个数
	BYTE	DiskType[8];				//磁盘类型
	DWORD	TotalSize[8];				//磁盘总空间大小
	DWORD	FreeSize[8];				//磁盘剩余空间
	BYTE	Reserved[8];				//BYTE	Reserved[4];	2008.9.23
}DISK_INFO;

//31，磁盘操作
typedef struct _DISK_MANAGE
{
	BYTE	Cmd;
	BYTE	Data;
	BYTE	Reserved[126];
}DISK_MANAGE;

//32，磁盘格式化进度
typedef struct _DISK_FORMAT_PROCESS
{
	DWORD	DiskType;					//磁盘类型
	DWORD	Status;						//格式化状态
	DWORD	Process;					//进度()
	DWORD	Reserved[5];
}DISK_FORMAT_PROCESS;


//33，扩展信息结构
typedef struct _EXTINFO_CONFIG
{
	DWORD			nSize;						//结构大小(1328)

	NTP_CONFIG		ntpConfig;					//ntp
	
	UPNP_CONFIG		upnpConfig;					//upnp
		
	MAIL_CONFIG		mailConfig;					//MAIL
	
	ALARM_INOUT_NAME alarmInOutName;			//ALARM IN/OUT NAME
	
	WF_NET_CONFIG	wfConfig;					//WF NETWORK
	
	SEND_DEST		sendDest;					//SEND DEST
	
	AUTO_RESET_TIME autoResetTime;				//AUTO RESET 

	//在HH5800系列中，本结构里不再包括recordConfig和diskInfo
	//在HH5800系列中, FTP_CONFIG ftpCfg;	char reserve[48];  
	//在HH5800系列中，使用新结构EXTINFO_CONFIG_NEW(修改定义， 大小和原结构相同， 所以命令也相同)
	//RECORD_CONFIG	recordConfig;				//RECORD CONFIG
	DISK_INFO		diskInfo;					//DISK INFO
	char			reserve[28];				//diskInfo + 4, here - 4
}EXTINFO_CONFIG;

//34，用户数据
typedef struct __USERDATA_CONFIG
{
	int		nDataLen;
	char	userData[252];
}USERDATA_CONFIG;

//=================================================================================
//在HH5800系列及之后系列都用以下结构
//=================================================================================
typedef  struct  _DVS_TIME
{
	BYTE		year ;
	BYTE		month ;
	BYTE		day ;
	BYTE		week ;
	BYTE		hour   ;
	BYTE		minute ;
	BYTE		second ;
	BYTE		millisecond;							
} DVS_TIME, *PDVS_TIME;

typedef struct _TIME_SEGMENT_NEW 
{
	DWORD 		bDetectOpen;				//检测开关
	BYTE        nBgnHour ;					//开始时
	BYTE        nBgnMinute ;				//开始分
	BYTE        nEndHour ;					//结束时
	BYTE        nEndMinute ;				//结束分
}TIME_SEGMENT_NEW;

//=======================================
//报警联动操作
//=======================================
typedef struct _ALARM_LINKAGE 
{
	DWORD 		Output;						//报警联动输出				     bit.0---bit.3	
	DWORD 		AutoClearTime;		        //报警自动清除时间	

	DWORD 		Record_PC;					//PC端报警联动录像通道			 bit.0---bit.3
	DWORD 		Record_Dev;					//设备端报警联动录像通道		 bit.0---bit.3
	DWORD		RecordSvaeMode;				//bit0 本地存储  bit1 ftp上传  bit2 email
	DWORD		RecordTime;					//报警录像时间(秒)

	DWORD		ShootSaveMode;				//bit0 本地存储  bit1 ftp上传  bit2 email
	DWORD		ShootChns;					//抓拍通道(bit.0 ~ bit.3)
	DWORD		ShootNum;					//连续抓拍张数()
	float		ShootInterval;				//连续抓拍时间间隔(秒)  0: 连续抓拍

	DWORD		EMail;						//发送email
	DWORD		Reserved;					//备用
} ALARM_LINKAGE;

//=======================================
//视频参数(新)
//=======================================
typedef struct _HH_OSD_CTRL_ST
{
	DWORD		Show;						//0: 关  1: 开
	WORD		X;							//x，y：显示的位置，该位置的范围为0-704，0-576，与图像的分辨率无关，x必须为4的倍数；
	WORD		Y;
} HH_OSD_CTRL_ST ;

typedef struct _HH_VENC_CTRL_ST
{
	DWORD       Open;						//是否开启编码（从码流）
	DWORD		EncType;					//编码算法
	DWORD		EncFormat;					//编码格式(D1, HD1, CIF)
	DWORD		Width;						//宽度
	DWORD		Height;						//高度
	
	DWORD		KeyInterval;			    //I 帧间隔
	DWORD		Bitrate ;					//码率
	float		FrameRate ;					//帧率float
	DWORD		BitflowType; 			    //码流类型(0:VBR, 1:CBR)
	DWORD		Qulity;						//质量0--5
	DWORD       Reserved[8];
} HH_VENC_CTRL_ST ;

//=======================================
//抓拍图片参数
//=======================================
typedef struct _PICTURE_CONFIG				//sizeof() = 148
{
	DWORD		dwSize;						//本结构长度

	DWORD     	EncType;					//抓图格式(.jpg, bmp) 
	DWORD     	EncFormat;					//图片其它参数(24位， 32位) 
	DWORD     	Width;
	DWORD     	Height;

	BYTE     	reseved[44];
}PICTURE_CONFIG;

//视频宽高
typedef struct _VIDEO_SIZE
{
	WORD		Width;						//宽
	WORD		Height;						//高
}VIDEO_SIZE;

//设备支持的编码格式和宽高
typedef struct _SUPPORT_AV_FMT
{
	DWORD		dwSize;						//本结构长度
	
	DWORD		MainVideoFmt[8];			//主码流编码格式
	DWORD		MinVideoFmt[8];				//从码流编码格式
	DWORD		PictureFmt[8];				//图片编码格式

	VIDEO_SIZE  MainVideoSize[8];			//主码流 宽、高	
	VIDEO_SIZE  MinVideoSize[8];			//从码流 宽、高	
	VIDEO_SIZE  PictureSize[8];				//图片 宽、高	

	DWORD		AudioFmt[8];				//音频编码格式
	DWORD		AudioSampleRate[8];			//音频采样率
	DWORD		AudioBitrate[8];			//音频码率
	DWORD		AuidoAEC;					//是否支持回声抵消

	BYTE     	reserve[32];	
}SUPPORT_AV_FMT;


//视频设置
typedef struct _VIDEO_CONFIG_NEW
{
	DWORD			dwSize;					//本结构长度

	HH_VENC_CTRL_ST stMainVEncCtrl;			//主码流控制
	HH_VENC_CTRL_ST stMinVEncCtrl;			//从码流控制
	PICTURE_CONFIG	stPictureCfg;			//抓拍图片参数

	HH_OSD_CTRL_ST	stDateOSD; 				// 0:不叠加日期,   1:叠加日期
	HH_OSD_CTRL_ST	stTimeOSD; 				// 0:不叠加时间,   1:叠加时间
	HH_OSD_CTRL_ST	stWeekOSD; 				// 0:不叠加星期,   1:叠加星期 
	HH_OSD_CTRL_ST	stTitleOSD;				// 0:不叠加标题,   1:叠加标题 
	HH_OSD_CTRL_ST	stBitrateOSD;			// 0:不叠加码率,   1:叠加码率 	
	
	char    	Title[CAM_TITLE_LEN_NEW];	//标题字符(64个字符  31个汉字)

    BYTE 		Brightness;				    //亮度
	BYTE 		Hue;						//色调
	BYTE 		Saturation;				    //饱和度
	BYTE 		Contrast;					//对比度

	WORD 		Protocol;					//协议编号(0 ~ MAX_PAN_PROTOCOL_NUM - 1)
	WORD 		YTAddr;						//解码器地址

	BYTE		mtClear;
	BYTE		mtRed;
	BYTE		mtBlue;
	BYTE		mtGamma;
	
	BYTE        reseved[28];
}VIDEO_CONFIG_NEW;

typedef struct _AREA_RECT
{
	WORD		X;							//X坐标	
	WORD		Y;							//Y坐标
	WORD		W;							//宽度
	WORD		H;							//高度
} AREA_RECT;

//=======================================
//移动侦测设置(新)
//=======================================
typedef struct _VIDEOMOTION_CONFIG_NEW
{
	DWORD			dwSize;						//本结构长度

	DWORD 			DetectLevel;			    //移动检测灵敏度
	DWORD 			DetectOpen;				    //移动检测开关

	AREA_RECT		DetectArea[9];				//移动检测区域			

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //移动检测时间表1				 0: 每天
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //移动检测时间表1				 0: 每天

	ALARM_LINKAGE	stAlarmLink;				//报警联动

	BYTE			reseved[128];
}VIDEOMOTION_CONFIG_NEW ;

//=======================================
//图像屏蔽设置(新) 长度＝老结构，可以用老命令
//=======================================
typedef struct _VIDEOMASK_CONFIG_NEW
{
	BYTE 			MaskOpen;					//视频屏蔽开关		0:关         1：开
	BYTE			AA[3];
	AREA_RECT		MaskArea[9];				//视频屏蔽区域		
}VIDEOMASK_CONFIG_NEW;

//=======================================
//视频丢失设置(新)
//=======================================
typedef struct _VIDEOLOSE_CONFIG_NEW
{
	DWORD			dwSize;						//本结构长度

	DWORD			DetectOpen;					//视频丢失检测

	ALARM_LINKAGE	stAlarmLink;				//报警联动

	BYTE			reseved[32];
} VIDEOLOSE_CONFIG_NEW;

//=======================================
//探头报警侦测设置(新)
//=======================================
typedef struct _SENSOR_CONFIG_NEW 
{
	DWORD			dwSize;						//本结构长度

	DWORD			SensorType;					//0:常开探头	1:常闭探头
	DWORD 			DetectOpen;				    //检测开关

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //探头检测时间1				     0: 每天
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //探头检测时间1				     0: 每天

	ALARM_LINKAGE	stAlarmLink;				//报警联动

	BYTE			reseved[32];
}SENSOR_CONFIG_NEW;

//=======================================
//无线探头报警
//=======================================
typedef struct _RF_ALARM_CONFIG
{
	DWORD			dwSize;						//本结构长度

	DWORD			SensorType;					//0:常开探头	1:常闭探头
	DWORD 			DetectOpen;				    //检测开关

	TIME_SEGMENT_NEW  tSchTable1[8] ;		    //探头检测时间1				     0: 每天
	TIME_SEGMENT_NEW  tSchTable2[8] ;		    //探头检测时间1				     0: 每天

	ALARM_LINKAGE	stAlarmLink;				//报警联动

	BYTE			reseved[32];
}RF_ALARM_CONFIG;


//=======================================
//网络断线报警设置
//=======================================
typedef struct _NET_ALARM_CONFIG 
{
	DWORD			dwSize;						//本结构长度

	DWORD 			DetectOpen;				    //检测开关
	
	ALARM_LINKAGE	stAlarmLink;				//报警联动

	BYTE			reseved[32];
} NET_ALARM_CONFIG;

//=======================================
// FTP 服务器参数
//=======================================
typedef struct __FTP_CONFIG
{
    char			ftpURL[64];
    char			ftpPath[64];
    DWORD			ftpPort;
    char			ftpUser[32];
    char			ftpPsw[32];

    char			ftpURL2[64];
    char			ftpPath2[64];
    DWORD			ftpPort2;
    char			ftpUser2[32];
    char			ftpPsw2[32];

    char			res[32];
}FTP_CONFIG;

//=======================================
//流媒体服务
//=======================================
typedef struct _MEDIA_SERVER
{
	BYTE				bRtspOpen;
	BYTE				bMmsOpen;
	WORD				rtspPort;
	WORD				mmsPort;
	WORD				res;
}MEDIA_SERVER;

//suncz 20090602
typedef struct _GPS_INFO
{
	BYTE		bGpsOpen;
	BYTE		gpsStatus;
	WORD		serverPort;
	DWORD		serverIP;
	BYTE		bGpsOSD;
	BYTE		gpsPlatform;
	BYTE		phoneNum[11];
	BYTE		res[3];
}GPS_INFO;
//24.0 扩展信息结构(修改定义， 大小和原结构相同， 所以命令也相同)
typedef struct _EXTINFO_CONFIG_NEW
{
	DWORD				nSize;						//结构大小(1328)

	NTP_CONFIG			ntpConfig;					//ntp
	
	UPNP_CONFIG			upnpConfig;					//upnp
		
	MAIL_CONFIG			mailConfig;					//MAIL
	
	ALARM_INOUT_NAME	alarmInOutName;				//ALARM IN/OUT NAME
	
	WF_NET_CONFIG		wfConfig;					//WF NETWORK
	
	SEND_DEST			sendDest;					//SEND DEST
	
	AUTO_RESET_TIME		autoResetTime;				//AUTO RESET 

	FTP_CONFIG			ftpCfg;						//FTP 服务器配置

	MEDIA_SERVER		mediaServer;			//流媒体服务

	GPS_INFO			gpsInfo;				//GPS 信息,

	char				reserve[16];  
	//char				reserve[40];  
}EXTINFO_CONFIG_NEW;

//=======================================
//无线探头
//=======================================
typedef struct _RF_KEY_CONFIG
{
	unsigned char		rf_close;
	unsigned char		rf_help_key;
	unsigned char		rf_alarm_noset;
	unsigned char		rf_disconnect_vidio;

	unsigned char		rf_res[32];
}RF_KEY_CONFIG;

//=======================================
//定时录像
//=======================================
typedef struct _CH_TIMER_RECORD_CONFIG		//sizeof() = 140
{
	WORD					KeepTime;								//保留天数(天)
	WORD					RecordSvaeMode;							//bit0 本地存储  bit1 ftp上传  bit2 email
	DWORD					reserve[2];

	TIME_SEGMENT_NEW		tSchTable1[8] ;							//某个通道的定时录像时间段1 (64)
	TIME_SEGMENT_NEW		tSchTable2[8] ;							//某个通道的定时录像时间段2 (64)
}CH_TIMER_RECORD_CONFIG;	

typedef struct _TIMER_RECORD_CONFIG			//sizeof() = 592
{
	BYTE					PackageTime;	  						//打包时间(分钟)
	BYTE 					OverWrite;        						//自动覆盖
	BYTE     				MainVEnc;								//录像采用 0: 从码流  1: 主码流
	BYTE     				CheckDisk;								//系统启动时进行磁盘扫描
	BYTE     				reserve[28];

	CH_TIMER_RECORD_CONFIG	ChRecordCfg[MAX_VIDEO_NUM];				//通道的录像参数(140 * 4 = 560)
}TIMER_RECORD_CONFIG;


//=======================================
//定时抓拍
//=======================================
typedef struct _CH_TIMER_SHOOT_CONFIG		//sizeof() = 140
{
	WORD 					KeepTime;								//保留天数(天)
	WORD					ShootSaveMode;							//bit0 本地存储  bit1 ftp上传  bit2 email

	DWORD					ShootNum;								//连续抓拍张数()
	float					ShootInterval;							//连续抓拍时间间隔(秒)  0: 连续抓拍

	TIME_SEGMENT_NEW		tSchTable1[8] ;							//某个通道的定时抓拍时间段1 (40)
	TIME_SEGMENT_NEW		tSchTable2[8] ;							//某个通道的定时抓拍时间段2 (40)
}CH_TIMER_SHOOT_CONFIG;

typedef struct _TIMER_SHOOT_CONFIG			//sizeof() = 592
{
	BYTE 					OverWrite;								//自动覆盖
	BYTE     				reserve[31];

	CH_TIMER_SHOOT_CONFIG	ChShootCfg[MAX_VIDEO_NUM];				//通道的录像参数(92 * 4 = 368)
}TIMER_SHOOT_CONFIG;

//=======================================
//其它扩展参数(如平台设置其它参数)
//=======================================
typedef struct __EXT_DATA_CONFIG
{
	DWORD		nSize;					//结构大小
	DWORD		nType;	
    DWORD		nDataLen;
    char		szData[512];
}EXT_DATA_CONFIG;

//=======================================
//日志查询
//=======================================
typedef struct _FIND_LOG_S
{
	DWORD		nSize;					//结构大小
	DWORD		nSelectMode;			//查询方式:0－全部，1－按类型，2－按时间，3－按时间和类型
	DWORD		nType;					//报警类型
    DVS_TIME	stStartTime;
	DVS_TIME	stEndTime;
}FIND_LOG_S;

typedef struct _LOG_ITEM_S
{
	DWORD		nSize;					//结构大小
	DWORD		nAlarmType;				//报警类型
	DWORD       nChn;					//通道号、断线报警的IP地址
	DVS_TIME	tAlarmTime;	
	char		szNote[12];
}LOG_ITEM_S;

//=======================================
//设备所有参数（sizeof = 10248）
//=======================================
typedef struct _DVS_Parameter_New
{
	DWORD					dwSize;						//本结构长度

    char                    sysName[DVS_NAME_LEN + 4];

	BYTE					sysInputNum;		        //路数
	BYTE					sysType;			        //机器型号	0:CIF  1:HD1  2:D1  
	BYTE					sysVideoFormat;		        //编码格式	0:D1,1:HD1,2:CIF,3:VGA 4:HVGA 5:CVGA 6:QCIF 7:QVGA
    BYTE					sysLanguage;		        //语言

    DWORD					sysStandard;		        //制式		0:PAL  1:NTSC

    DWORD      				sysID;  	                //每台机器有个ID
	DWORD      				sysVer;  	                //软件版本  

	VIDEO_CONFIG_NEW	    sysVideo[MAX_VIDEO_NUM];	
	VIDEOMOTION_CONFIG_NEW	sysVideoMotion[MAX_VIDEO_NUM];
	VIDEOMASK_CONFIG_NEW    sysVideoMask[MAX_VIDEO_NUM];	
	VIDEOLOSE_CONFIG_NEW    sysVideoLose[MAX_VIDEO_NUM];	
	AUDIO_CONFIG		    sysAudio[MAX_AUDIO_NUM];
	NET_CONFIG			    sysNet;
	COM_CONFIG			    sysCom[MAX_COM_NUM];
	SENSOR_CONFIG_NEW	    sysSensor[MAX_SENSOR_NUM];
	USER_CONFIG			    sysUser[MAX_USER_NUM];

    EXTINFO_CONFIG_NEW		sysExtConfig;				//扩展参数

	DISK_INFO				DiskInfo;					//存储设备信息

	TIMER_RECORD_CONFIG		TimerRecordCfg;
	TIMER_SHOOT_CONFIG		TimerShootCfg;				//定时抓拍参数

	RF_ALARM_CONFIG			rfAlarmCfg[MAX_RF_SENSOR_NUM];	//无线探头报警
	NET_ALARM_CONFIG		netAlarmCfg;					//网络断线报警

	USERDATA_CONFIG			userData;					//用户数据

	DWORD					YunTaiProtocolNum;
	YUNTAI_INFO 			YunTaiInfo[MAX_PTZ_PROTOCOL_NUM];	

	BYTE					reserved[256];				//备用

} DVS_Parameter_New;

//=======================================
//GPS信息add by huangtao
//=======================================
typedef struct _REALTIME_GPS_STATUS
{
	BYTE  nDevId[4];
	BYTE  nEastJin;    //1东经  0西经 
	BYTE  nJinDu[9];   //经度 12345678 前三位为整数位
	BYTE  nNorthWei;   //1北纬  0南纬  
	BYTE  nWeiDu[8];   //纬度 1234567  前两位为整数位
	BYTE  nGpsPW   ;   //gps 电源状态 1正常   0故障
	BYTE  nGpsDW   ;   //gps 是否定位 1已定位 0未定位
	BYTE  nAccStatus;  //Acc状态 1 ACC关 0 ACC开
	BYTE  nGpsTX   ;   //天线状态 1 天线正常 0 天线异常
	BYTE  nSpeed;      //速度 
	BYTE  nLiCheng[9]; //里程
	BYTE  res;
	WORD  nDirection;  //方向
	BYTE  tag[16];
}REALTIME_GPS_STATUS;

//add by huangtao
typedef struct _GPS_MSG_NOTIFY
{
	HANDLE					hLogonServer;
	DWORD					dwClientID;
	DWORD					dwServerIP;
	DWORD					dwServerPort;
	REALTIME_GPS_STATUS		gpsStatus;
}GPS_MSG_NOTIFY;


//备用1
typedef struct _CONFIG_ENCPAR
{ 
    DWORD u32PicWidth;   
    DWORD u32PicHeight;     
    DWORD u32CapSel; 
    DWORD u32StaticParam; 
    DWORD u32TargetBitrate; 
    DWORD u32TargetFramerate; 
    DWORD u32Gop;             
    DWORD u32MaxQP;        
    DWORD u32PreferFrameRate; 
    DWORD u32Strategy; 
    DWORD u32VencMode;        
    DWORD u32BaseQP;         
    DWORD u32MaxBitRate;   
}CONFIG_ENCPAR; 

//备用2
typedef struct _PING_CONFIG
{
	BOOL	bPingOpen;
	BOOL	bDisconnectReboot;
	BOOL	bDisconnectAlarm;
	DWORD	dwPingNum;
	DWORD   dwPingPeriod;
	char	szPingServer[64];
}PING_CONFIG;

//高清高速球
typedef struct _HH_DOOM_AUTOSCAN	
{
	BYTE   nPresetNo[16];		//0: 没设置	 预置点号(1 ~ 255)
	WORD   nKeepTime[16];		//停留时间(0 ~ 3600秒)	
	char   szReserved[8];		
}HH_DOOM_AUTOSCAN;

//高清高速球参数
typedef struct _HH_DOOM_CONFIG	//sizeof = 248
{
	//摄像头参数
	DWORD			dwSize;					//结构大小

	BYTE			bZoomSpeed;     		//变倍速度控制		0 高速    1 正常速度  			
	BYTE			bFocusManl;       		//焦距控制			0 自动    1 手动				
	BYTE			bIrisCtrl;        		//光圈控制			0 自动    1 手动

	BYTE			bAWB;         			//白平衡控制		0 自动    1 手动				
	WORD			nAWBRed;     			//白平衡			R gain	  0 ~ 255	
	WORD			nAWBBlue;     			//白平衡 			B gain	  0 ~ 255

	BYTE			bBLC;         			//背光补偿			1 开  	  0 关
	BYTE			nBLCValue;     			//背光补偿					  0 ~ 255
	BYTE			bWDRMode;     			//宽动态模式		1 开  	  0 关				
	BYTE			bMirror;      			//镜像				1 开      0 关				

	BYTE			bImageMode;   			//图像模式			0 模式一  1 图像模式二	
	BYTE			bIRCFMode;    			//IRcf模式			0 OUT=>IN 1 IN=>OUT      		
	BYTE			bIRLight;     			//红外灯			0 正常光  1 850mm   2 950mm 		
	BYTE			nPgmAE;       			//Program AE
	
	DWORD			nShutterPriValue;		//Shutter priority  调节值对象	1/1=1    1/2=2   …… 1/10000=10000 //快门
	DWORD			nExposurePriValue;		//Exposure priority	调节值对象	F1.6=16  F2.2=22 …… F34.0=340//曝光
	DWORD			nAGCPriValue;			//AGC priority		调节值对象	0dB=0    6dB=6   …… 30dB=30//自动增益

	BYTE			nVideoHZ;               //(0)50HZ (1)60HZ (2)OUT DOOR

	//云台参数
	BYTE			bAutoFlip;				//自动翻转			   			1 开  	0 关
	BYTE			bAutoSpeed;				//景深比例变速		 			1 开  	0 关
	BYTE			bManualLimit;			//手动限位			 			1 开  	0 关
	
	BYTE			bScanLimit;				//扫描限位			 			1 开  	0 关
	BYTE			bAux1;					//辅助开关一		 			1 开  	0 关
	BYTE			bAux2;					//辅助开关二		 			1 开  	0 关
	BYTE			nHSpeed;				//水平扫描速度		 			1 - 40度设置
	
	BYTE			nVSpeed;				//俯仰扫描速度		 			1 - 20度设置
	BYTE			nWatchMode;				//看守位模式		        	0  无
											//	  			                1  预置位1   																																																												
											//	  			                2  预置位2   																																																												
											//	  			                3  预置位3   																																																												
											//	  			                4  预置位4   																																																												
											//	  			                5  预置位5   																																																												
											//	  			                6  预置位6   																																																												
											//	  			                7  预置位7   																																																												
											//	  			                8  预置位8   																																																												
											//	  			                9  自动扫描  																																																												
											//	  			                10 削苹果扫描 																																																												
											//	  			                11 预置位巡视1																																																												
											//	 			                12 预置位巡视2		
	BYTE			nWatchTime;				//看守位起动时间	        	2-60分
	BYTE			nReserved;				//备用

	HH_DOOM_AUTOSCAN	szDoomAutoScan[2];	//预置位巡视
	TIME_SEGMENT_NEW	tSchTable[5];		//定时设置

	char				szReserved[52];		//备用
}HH_DOOM_CONFIG;

//------------------------------------------------------－-------------------//
//------------------------------(II)解码器参数设置结构-----------------------//
//------------------------------------------------------－-------------------//
//1，系统时间
typedef  struct  _DD_NVD_DATE
{
	BYTE		year;									//年
	BYTE		month;									//月
	BYTE		day;									//日
	BYTE		week;									//周
	BYTE		hour;									//小时
	BYTE		minute;									//分
	BYTE		second;									//秒
}DD_NVD_DATE, *PDD_NVD_DATE;

//2，系统配置
typedef struct _DD_SYSTEM_PARAM 
{
   	char               	Name[DVS_NAME_LEN + 1];			//名字
	BYTE				Type;							//机器型号	0:CIF  1:HD1  2:D1  
    BYTE				Language;						//语言
    BYTE				Standard;						//制式		0:PAL  1:NTSC
	DWORD      			ID;  	        				//每台机器有个ID号  	
	DWORD      			RS485Addr;       				//RS485地址  		
	DWORD      			RS485Func;       				//RS485功能  			
	DWORD      			RS485Baud;       				//RS485波特率  			
	DWORD      			Version;         				//软件版本  
	BYTE      			RemoteID;         				//遥控ID号  	
	BYTE				Audio;							//监听开关	
	BYTE				TimeOn;							//时间显示开关				
	BYTE				DispMode;						//显示模式(1单画面、4四画面)
	BYTE				ImageQulity;					//解码图像质量
	BYTE				Reserve[31];					//备用
}DD_SYSTEM_PARAM;

//3，网络参数
typedef struct _DD_NET_CONFIG
{
	DWORD             	IPAddr ;						//IP地址
	DWORD             	SubNetMask ;					//掩码
	DWORD             	GateWay ;						//网关

   	WORD             	ComPortNo;						//设置接收客户端命令端口号        UDP	
   	WORD             	WebPortNo;						//Webserver端口     			  TCP
	DWORD             	MultiCastIPAddr ;				//多播IP地址
   	WORD             	MultiCastPortNo;				//UDP传输起始端口<多播传输>
	
	BYTE			   	RT8139MAC[6];      				//人工设置网卡的MAC地址		5---0有效
   	BYTE             	DHCP;							//DHCP 开关					0	关		1:开
   	
   	WORD             	PppoeOpen;						//PPPOE 开关         	
	DWORD             	PppoeIPAddr ;					//PPPOEIP地址 （报警回传IP）
	char				PppoeName[PPPPOE_NAME_LEN+1];	//拨号用户名
	char				PppoePass[PPPPOE_PASSWD_LEN+1];	//拨号密码		
	
	DWORD				DdnsOpen;						//DDNS开关
	char				DdnsName[DDNS_NAME_LEN+1];		//注册主机名称
	char				DdnsPass[DDNS_PASS_LEN+1];		//注册主机密码	
	
	char				DdnsIP[DDNS_SERVER_NAME_LEN+1];	//DDNS服务器
	WORD				DdnsPortNo;						//DDNS服务器端口
	WORD				DdnsMapWebPort;					//本地WEB映射端口
	WORD				DdnsMapDataPort;				//本地数据映射端口

	DWORD				DNSHostIP;						//DNS的IP
	
	BOOL				ConnectCenter;					//是否主动连接中心
	char				ConnectCenterIP[DDNS_SERVER_NAME_LEN+1];//中心IP
	WORD				ConnectCenterPort;						//中心端口

	WORD				appFunction;
	BYTE				tcpSendInterval;
	BYTE				udpSendInterval;
	WORD				PacketMTU;

	BYTE				CaptureMode;					//抓拍模式
	BYTE				CapturePort[MAX_SENSOR_NUM];	//抓拍通道(0-3bit: 分别表示1 ~ 4号通道  1:开  0: 关)

	DWORD				DdnsIP2;						//DDNS 2的IP,非网络字节次序
	WORD				DdnsPortNo2;					//DDNS 2的端口

	char				sysByname[DVS_NAME_LEN+1];		//域名
	BYTE				NetReserve[1];					//保留
} DD_NET_CONFIG ;

//4，串口设置
typedef struct __DD_COM_PARAM
{
	DWORD 				Baudrate;						//串口波特率				300---115200
	BYTE				Databit;						//串口数据位长度			5=5位 6=6位 7=7位 8=8位	其他=8位
	BYTE				Stopbit;						//停止位位数				1=1位 2=2位 其他=1位
	BYTE				CheckType;						//校验						0=无  1=奇  2=偶  3=恒1  4=恒0 
	BYTE				Flowctrl; 						//软流控/硬流控/无流控		备用
}DD_COM_CONFIG;

//5，图像参数
typedef struct _DD_IMAGE_PARAM
{
	BYTE 	Bright;										// 亮度
	BYTE 	Shades;										// 色度
	BYTE 	Contrast;									// 对比度
	BYTE 	Saturate;									// 饱和度
	BYTE 	MenuBright;									// 菜单亮度
}DD_IMAGE_CONFIG;

//6，报警联动
typedef struct __DD_ALARMOUT_PARAM
{
	BYTE 				Open;							//联动开关<0: 关  1: 开>
	BYTE				SensorAlarm[4];					//探头报警联动	.0 ~ 3 1--4号探头	0,1位: 分别表示继电器1 2的状态  <0: 关  1: 开>
	BYTE				MotionAlarm[4];					//视频移动联动	.0 ~ 3 1--4号探头	0,1位: 分别表示继电器1 2的状态  <0: 关  1: 开>
	BYTE				ViLoseAlarm[4];					//视频丢失联动	.0 ~ 3 1--4号探头	0,1位: 分别表示继电器1 2的状态  <0: 关  1: 开>
	BYTE				Reserve[8];						//备用	
}DD_ALARMOUT_CONFIG;

//7，用户设置
typedef struct _DD_USER_CONFIG
{
	DWORD 		Level;									//权限
	char 		Name[USER_NAME_LEN + 1];				//用户名
	char 		Password[USER_PASSWD_LEN + 1];			//用户密码
} DD_USER_CONFIG;

//8，报警信息条目
typedef struct __DD_ALARM_ITEM
{
	DWORD 				IPAddr;							//IP
	char				URL[DD_URL_ADDR_LEN + 1];		//URL地址
	DWORD				ComPortNo;						//通讯端口
	DD_NVD_DATE			AlarmTime;						//报警时间
	BYTE				SensorAlarm;					//探头报警联动	.0 ~ 3 1--4号探头	<0: 无报警  1: 有报警>
	BYTE				MotionAlarm;					//视频移动联动	.0 ~ 3 1--4号视频	<0: 无报警  1: 有报警>
	BYTE				ViLoseAlarm;					//视频丢失联动	.0 ~ 3 1--4号视频	<0: 无报警  1: 有报警>
	BYTE				Reserve[8];						//保留
}DD_ALARM_ITEM;

//9，报警信息记录
typedef struct __DD_ALARM_INFO
{
	WORD				Count;							//报警记录个数
	DD_ALARM_ITEM		Alarms[DD_MAX_ALARMINFO_NUM];	//报警记录内容
}DD_ALARM_INFO;

//10，地址薄
typedef struct __DD_ADDRBOOK_PARAM
{
	char				Name[DDNS_NAME_LEN + 1];			//名称
	char				URL[DD_URL_ADDR_LEN + 1];		//URL地址
	WORD             	ComPortNo;						//通讯端口
	BYTE				ChannelNo;						//通道号
	BYTE				Protocol;						//0: TCP  1:多播   2:UDP
	BYTE				DNSOpen;						//0: 关   1:开
	WORD				StayTime;						//停留时间	5--3600秒
	BYTE				AutoLink;						//自动连接	0:关  1:开
	BYTE				AudioOpen;						//声音打开	0:关  1:开	
	BYTE				TalkOpen;						//对讲打开	0:关  1:开
	char				UserName[USER_NAME_LEN + 1];	//用户名
	char				UserPass[USER_PASSWD_LEN + 1];	//用户密码	
	BYTE				Reserve[8];						//保留	
}DD_ADDRBOOK_CONFIG;

//11，透明通讯
typedef struct __DD_COMM_CTRL
{
	BYTE				COMMNo;							//串口号	0 ~ 1
	COM_CONFIG			COMConfig;						//串口配置
	WORD				DataLength;						//数据长度
	BYTE				Data[256];						//数据
}DD_COMM_CTRL;

//12，其它控制命令结构
typedef struct __DD_DEVICE_CTRL
{
	BYTE				CMD;							//命令
	BYTE 				Data1;							//数据1
	BYTE 				Data2;							//数据2
	DWORD				nReserved[8];					//保留
}DD_DEVICE_CTRL;

//13，云台信息
typedef struct _DD_PROTOCOL_INFO
{
	char 		Name[YUNTAI_NAME_LEN + 1];				//云台名称
	BYTE		Exist;									//是否可用
	BYTE		nReserved[8];							//保留
}DD_PROTOCOL_INFO;

//14，云台设置
typedef struct _DD_YUNTAI_SET
{
	char 		Name[YUNTAI_NAME_LEN + 1];				//云台名称
	BYTE 		YTAddr;									//解码器地址
	COM_CONFIG	ComSet;									//通讯协议<波特率...>
	BYTE		nReserved[8];							//保留
}DD_YUNTAI_SET;

//15，系统所有参数(所有配置参数，网络传输用)
typedef struct _DD_NVD_CONFIG 
{
	DD_SYSTEM_PARAM 		sysParam;					//系统配置
	DD_NET_CONFIG			sysNet;						//网络设置
	DD_COM_CONFIG			sysCom[MAX_COM_NUM];		//串口设置
	DD_IMAGE_CONFIG			sysImage;					//图像参数
	DD_USER_CONFIG			sysUser[MAX_USER_NUM];		//用户
	DD_ALARMOUT_CONFIG		sysAlarmOut;				//报警输出
		
	DD_PROTOCOL_INFO 		YunTaiInfo[MAX_VIDEO_NUM];	//云台信息
	DD_YUNTAI_SET 			YunTaiSet[MAX_VIDEO_NUM];	//云台协议设置		
} DD_NVD_CONFIG ;

//16，扩展信息结构
typedef struct _DD_EXTINFO_CONFIG
{
	DWORD			nSize;						//结构大小

	//ntp
	NTP_CONFIG		ntpConfig;

	//upnp
	UPNP_CONFIG		upnpConfig;
	
	//MAIL
	MAIL_CONFIG		mailConfig;

	//ALARM IN/OUT NAME
	ALARM_INOUT_NAME alarmInOutName;

	//WF NETWORK
	WF_NET_CONFIG	wfConfig;

	//SEND DEST
	SEND_DEST		sendDest;
	
	char			reserve[480];
}DD_EXTINFO_CONFIG;

#ifdef __cplusplus
}
#endif


#endif



