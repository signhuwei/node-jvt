#ifndef _SDKDEFINE_H
#define _SDKDEFINE_H

/*******************************#Define Global************************************/
#include <map>
#include <afxtempl.h>
#include <VECTOR>

#include "VideoNetAPI.h"
//回调类型
enum CALLBACK_TYPE
{
	CALLBACK_ALARM_INFO,				//报警信息
	CALLBACK_UPDATE_DEVC,				//更新设备信息
	CALLBACK_CENTER_CONTROL,			//
	CALLBACK_DEVC_DISCONNECT,			//设备断线
	CALLBACK_SUB_DISCONNECT,			//子链接断开
	CALLBACK_MOBILE_DVR_INFO,			//移动DVR信息
	CALLBACK_MEET_DATA,					//会议
	CALLBACK_TALKING_DATA,				//语音对讲
	CALLBACK_MEDIA_DATA,					
	CALLBACK_MEDIA_PLAYBACK_DATA,
	CALLBACK_PLAYBACK_POS,
};
enum VERSION_CLASS
{
	XM_EPSS = 0X0,		//EPSS版本
	XM_PSS,				//PSS版本
	XM_MINI,			//迷你版本
};

enum VENDOR_TYPE
{
	XMDEVC_TYPE = 0,       //雄迈
	HKDEVC_TYPE,       //海康设备
	DHDEVC_TYPE,       //大华设备
	HHDEVC_TYPE,		//黄河设备
	ONVIFDEVC_TYPE,		//支持Onvif协议的设备
	TMDEVC_TYPE,		//天敏设备
	GESSDEVC_TYPE,		//GESS设备
	KWDEVC_TYPE,		//KINGWAVE设备
	XMBACK_TYPE,       //雄迈回放
	HKBACK_TYPE,        //海康回放
	DHBACK_TYPE,        //大华回放
	HHBACK_TYPE,		//黄河回放
	ONVIFBACK_TYPE,		//支持Onvif协议的设备回放
	TMBACK_TYPE,		//天敏回放
	GESSBACK_TYPE,		//GESS回放
	KWBACK_TYPE,		//KINGWAVE回放
};

enum DEVC_CLASS
{
	DEVC_NOTHING = 0X0,
	DEVC_DVR,				//一般DVR
	DEVC_MOBILE_DVR,		//移动DVR
	DEVC_IPS,				//IP存储
};

typedef enum _Data_Type
{
	XM_Data_NULL = -1,
	XM_Data_Dev	= 0,											//设备数据
	XM_Data_EicMap,												//电子地图
	XM_Data_RECORD,												//自动录像
	XM_Data_USER,												//用户管理
	XM_Data_Scheme,												//轮巡数据
	XM_Data_ORG,												//组织结构数据
	XM_LOCAL_DATA,												//本地修改
	XM_SSVR_LIST,												//存储服务列表
	XM_POWER_DEVLIST,											//权限设备列表
	XM_ALARM_DATA,												//报警数据
	XM_USER_LIST,												//用户列表
	XM_LICENCE_INFO,											//证书信息
	XM_NTDC_INFO,												//流媒体服务器的相关信息
	XM_NRU_INFO,												//存储单元相关信息
	XM_LOGDIR_INFO,      										//日志系统目录信息
	XM_LOGFILE_INFO,     										//日志文件信息
	XM_LOCAL_ALARMDATA,	 										//本地报警数据
	XM_LOCAL_ALARM_ENABLE,										//报警使能
	XM_DATA_IPS,												//IPS设备
	XM_DATA_DEV_MOBILE_DVR,										//主动注册设备
	XM_DATA_DEV_MOBILEINFO,										//主动注册设备信息
	XM_MOBILE_SNAPPIC,											//移动DVR抓图数据
	XM_DECODER_ENABLE,                                      //解码器
	XM_Data_All = 255,											//所有数据
} XM_DataType;

// 设备事件枚举.
typedef enum _DEVICE_EVENT										//各单元合并
{
//EPSS....................................................
	DEVENT_NOTHING = 0x0,
	DEVENT_CONNECT,												// 连接.
	DEVENT_DELETE,												// 设备删除.
	DEVENT_TALK,												// 对讲。
	DEVENT_REBOOT,  											// 远程重启
	DEVENT_UPGRADE, 											// 设备升级
	DEVENT_ALARM,   											// 设备报警事件
	DEVENT_MULTIVIEW = 19,										// 多画面.实时预览,//.目前netsdk只有一个预览接口,以后如分了四,九等画面预览,再依次添加
	DEVENT_MODIFY,												// 修改设备
	DEVENT_CONNFAIL,											// 连接失败
	DEVENT_SYNCHRO, 											// 时间同步
	DEVENT_SNAPPIC,												// 移动DVR抓图

	DEVENT_ADD,													// 添加设备
	DEVENT_RELOAD,												//重新更新设备信息
	DEVENT_STOP_TALK,
	DEVENT_ZONE_ADD,                                            //区域增加
	DEVENT_ZONE_DEL,                                            //区域删除
	DEVENT_ZONE_MODIFY,                                         //区域修改   

	DEVENT_STARTRECORD,										    //开始录像
	DEVENT_ENDRECORD,											//停止录像

	DEVENT_ENDRECORDCHANGEICON                                  //停止录像修改图标

}DEVICE_EVENT;

// 通道事件枚举.
typedef enum _CHANNEL_EVENT										//各单元合并
{
//EPSS....................................................
	CHNLENT_NOTHING = 0x0,
	CHNLENT_AV,													// 视音频同时控制.
	CHNLENT_VIDEO,												// 视频.
	CHNLENT_AUDIO,												// 音频.
	CHNLENT_RECORDPLAY,											// 录像播放.
	CHNLENT_TALK,												// 对讲。
	CHNLENT_VIDEO_EX,											// 双击地图节点打开实时监视
	CHNLENT_MULTIVIEW,											// 多画面预览
	CHNLENT_VIDEO_ALARM,										// 报警联动监视
	CHNLENT_MOTION_DETECT,  									// 动态检测
	CHNLENT_CLICK_WND,											// 选择窗口
	CHNLENT_OPEN_VIDEO,											// 打开视频
	CHNLENT_CLOSE_VIDEO,										// 关闭视频

	CHNLENT_SELECTRECORD,										//选中录像通道
	CHNLENT_ADDRECORD,											//增加录像通道
	CHNLENT_MODIFYRECORD,										//修改录像通道
	CHNLENT_NO_DISKSPACE,										//录像无硬盘空间
	CHNLENT_DISK_ERROR,											//可能磁盘损坏
	CHNLENT_DEV_DISCONNET,										//设备断线
	CHNLENT_REAL_BACKUP,										//实时备份
	
	CHNLENT_STARTRECORD,										//开始录像
	CHNLENT_ENDRECORD,											//停止录像
	CHNLENT_NODATA,												//无数据
	CHNLENT_NO_RECORD,											//没有录像文件
	CHNLENT_START_BACKUP,										//开始备份
	CHNLENT_STOP_BACKUP,										//停止自动备份,没有下载完
	CHNLENT_END_BACKUP,											//自动备份结束
	CHNLENT_MANUAL_BACKUP,										//手动备份
	CHNLENT_STOP_MANUAL,										//停止手动备份
	CHNLENT_END_MANUAL,											//手动备份结束
	CHNLENT_NO_DISKSPACE_BACKUP,								//没有磁盘空间
	CHNLENT_NO_POWER,											//没有权限
}CHANNEL_EVENT;

typedef enum _ALARM_ENUM
{
	ALARM_SENSOR,						//外部报警
	ALARM_MOTION,						//动态检测
	ALARM_LOSS,							//视频丢失
	ALRAM_MASK,							//视频遮挡
	ALARM_VIDEOANALYSE,					//智能分析
	ALRAM_DISKFULL,						//硬盘满
	ALARM_DISKERROR,					//硬盘坏
	ALARM_VideoAnalyze,
	ALARM_DISCONNECT = 20,					//设备断线
	ALARM_SOUND_DETECT,
	ALARM_NM,
}ALARM_ENUM;


//本地用户管理中的权限类型
typedef enum __PowerType
{
	TYPE_MONITOR,						//实时监视
	TYPE_PLAYFILE,						//录像回放
	TYPE_UPGRADE,						//远程升级
	TYPE_REMOTE_REBOOT,					//远程重启
	TYPE_REMOTE_CONFIG,					//远程配置
	TYPE_REMOTE_USER_MNG,				//远程用户管理
	TYPE_PTZ_CTRL,						//云台控制
	TYPE_RECORD_CTRL,					//录像控制
	TYPE_LOCAL_RECORD,					//本地录像
	TYPE_DEVICE_MNG,					//设备管理
	TYPE_PROJECT_MNG,					//方案管理
	TYPE_EMAP,							//电子地图
	TYPE_SIXWINDOW,						//视频6窗口
	TYPE_RECORD_QUERY,					//录像查询
	TYPE_RECORD_DOWNLOAD,				//录像下载
	TYPE_RECORD_COPY,					//录像复制
	TYPE_CONNDEV_DIRECTLY,				//直连设备
	TYPE_DOOR_CTRL,						//门禁控制
	TYPE_ALARMDEV_CTRL,					//报警布撤防控制
}POWER_TYPE;

typedef enum _RECORD_EVENT
{
//EPSS....................................................
	RECORD_NOTHING = 0x0,
	RECORD_PLAY,						//网络回放
	RECORD_TIMEPLAY,					//时间段回放
//.......................................................
	RECORD_STOP,						//回放结束
	RECORD_SEARCH,						//水印查询
	RECORD_SEARCHOVER,					//水印查询终止
	RECORD_CLOSE,                       //关闭回放
	RECORD_NODATA,						//长时间无数据
}RECORD_EVENT;



// 业务层变化事件，通知界面层.
//............................
enum INFO_EVENT
{
	INFO_NOTHING = 0x0,	
	INFO_CREATE,						// 初始化
	INFO_UPDATECHANNEL,					// 通道变化
	INFO_UPDATEDEVICE,					// 设备变化（包括网络连接）
	INFO_RECORDPLAY,					// 录像文件播放（包括网络回放）
	INFO_DESTROY,						// 反始化	
	INFO_STOPPLAY,						// 停止播放.
	INFO_SHOWWNDNUM,					// 显示视窗数.
	INFO_SETWNDCOLOR,					// 设置报警视窗颜色
	INFO_RESETWNDCOLOR,					// 恢复视窗颜色
	INFO_DISCONNECT,					//异常断开连接
	INFO_SETWNDCOLOR_ALARM,				// 设置外部报警视窗颜色
	INFO_SETWNDCOLOR_MOTION,			// 设置动态报警视窗颜色
	INFO_GETWNDCOLOR,					// 得到报警视窗颜色
	INFO_MAX_ONEWND,					//报警全屏幕窗口
	INFO_RESTORWNDNUM,					//恢复原始窗口
	INFO_DEVMANAGE,						// 设备管理（删除）
	INFO_CONNECTREALVIDEO,  //连接实时视频
};


typedef enum _OTHER_LOG_EVENT
{
	NO_RECORD = 0x0,
}OTHER_LOG_EVENT;

//权限类别
enum {
	//设备相关权限
	//实时监视
	MULTI_MUTUAL_MONITOR1, 	              //实时监视1
	MULTI_MUTUAL_MONITOR2,	              //实时监视2
	MULTI_MUTUAL_MONITOR3,	              //实时监视3
	MULTI_MUTUAL_MONITOR4,	              //实时监视4
	MULTI_MUTUAL_MONITOR5,	              //实时监视5
	MULTI_MUTUAL_MONITOR6,	              //实时监视6
	MULTI_MUTUAL_MONITOR7,	              //实时监视7
	MULTI_MUTUAL_MONITOR8,	              //实时监视8
	MULTI_MUTUAL_MONITOR9,	              //实时监视9
	MULTI_MUTUAL_MONITOR10,	              //实时监视10
	MULTI_MUTUAL_MONITOR11,	              //实时监视11
	MULTI_MUTUAL_MONITOR12,	              //实时监视12
	MULTI_MUTUAL_MONITOR13,	              //实时监视13
	MULTI_MUTUAL_MONITOR14,	              //实时监视14
	MULTI_MUTUAL_MONITOR15,	              //实时监视15
	MULTI_MUTUAL_MONITOR16,	              //实时监视16
		
	//网络回放	
	SINGLE_MUTUAL_PLAYFILE1, 	          //网络回放1	
	SINGLE_MUTUAL_PLAYFILE2, 	          //网络回放2
	SINGLE_MUTUAL_PLAYFILE3, 	          //网络回放3		
	SINGLE_MUTUAL_PLAYFILE4, 	          //网络回放4	
	SINGLE_MUTUAL_PLAYFILE5, 	          //网络回放5	
	SINGLE_MUTUAL_PLAYFILE6, 	          //网络回放6
	SINGLE_MUTUAL_PLAYFILE7, 	          //网络回放7		
	SINGLE_MUTUAL_PLAYFILE8, 	          //网络回放8			
	SINGLE_MUTUAL_PLAYFILE9, 	          //网络回放9	
	SINGLE_MUTUAL_PLAYFILE10, 	          //网络回放10
	SINGLE_MUTUAL_PLAYFILE11, 	          //网络回放11		
	SINGLE_MUTUAL_PLAYFILE12, 	          //网络回放12	
	SINGLE_MUTUAL_PLAYFILE13, 	          //网络回放13	
	SINGLE_MUTUAL_PLAYFILE14, 	          //网络回放14
	SINGLE_MUTUAL_PLAYFILE15, 	          //网络回放15		
	SINGLE_MUTUAL_PLAYFILE16, 	          //网络回放16	

	OTHER_RECORD_CONTROL,					//录像控制
	REMOTE_USER_MANAGE,						//远程设备用户管理
	REMOTE_REBOOT_DEVICE,					//远程重启
	RECORD_QUERY,							//录像查询
	RECORD_DOWNLOAD,						//录像下载
	RECORD_COPY,							//录像复制
	CONNDEV_DIRECTLY,						//直连设备

	END_OF_DEV_RIGHTS,						//设备相关权限结束
	
	//设备无关权限
	LOCAL_RECORD = 100,						//本地录像
	SINGLE_MUTUAL_UPGRADE_BIOS,				//升级BIOS
	ELECTRIC_MAP,							//电子地图
	DEVICE_MANAGE,							//设备管理
	PROJECT_MANAGE,							//方案管理
	MULTI_MUTUAL_CONFIG,					//配置信息
	BROADCAST_PAN_CONTROL,					//云台控制
	PROJECT_PLAY,							//方案播放
	SHOW_SIXWINDOW,							//6窗口视频
	DOOR_CTRL,								//门禁控制
	ALARMDEV_CTRL,							//报警布撤防控制

	END_OF_USER_RIGHTS,						//设备无关权限结束
};

//权限范围
enum 
{
	//需要记录权限的功能
	REGISTER_DEV_RIGHTS_BEGIN = MULTI_MUTUAL_MONITOR1,
	REGISTER_DEV_RIGHTS_END = END_OF_DEV_RIGHTS,
	REGISTER_USER_RIGHTS_BEGIN = LOCAL_RECORD,
	REGISTER_UESR_RIGHTS_END = END_OF_USER_RIGHTS,
};

// 播放状态.
enum PLAY_STUTAS
{
	PLAY_NOTHING = 0x0,	// 无.
	PLAY_REAL,			// 实时监视.
	PLAY_MULTIVIEW,     //多画面预览
	PLAY_NETBACK,		// 网络回放.
	PLAY_AUTORECORD		//自动录像
};

//录像类型
typedef enum _RECORD_TYPE
{
	RECORD_NORMAL = 0x0,	// 定时录像
	RECORD_ALARM,			// 报警录像
	RECORD_MD,				// 动态检测报警
	RECORD_BACKUP,			//备份录像
	RECORD_ALL	=  255,				//所有通道
}RECORD_TYPE;

typedef enum _LOG_EVENT
{
	LOGEVENT_NOTHING = 0x0,
	LOGEVENT_DEVICE,
	LOGEVENT_CHANNL,
	LOGEVENT_PROJECT
//	LOGEVENT_DEVICECONNECT,        //设备连接连接
//	LOGEVENT_DEVICEDISCONNECT,     //设备断开
//	LOGEVENT_CHANNLCONNECT,        //通道连接
//	LOGEVENT_CHANNLDISCONNECT     //通道断开
 	//LOGEVENT_AUTODISCON,     //自动断开(程序检查到和设备网络断开)

}LOG_EVENT;

typedef enum _LOGENT_STATUS
{
	STATUS_REQUESTING = 0x0,          //请求中
	STATUS_CONNECT,                 //连接
	STATUS_CONNECTFAIL,				//连接失败
	STATUS_DISCONNECT ,             //断开
	//EPSS............................................
	STATUS_BEGINPROJECT,             //开始轮巡     
	STATUS_STOPPROJECT,               //停止轮巡
	//.................................................
	STATUS_VIDEO,					//开始存储
	STATUS_DISVIDEO,				//停止存储 
	STATUS_NODATA,					//停住存储,无数据
	STATUS_BACKUP,					//开始备份
	STATUS_NO_RECORD,				//没有录像文件
	STATUS_MANUAL,					//手动备份
	STATUS_STOP_MANUAL,				//停止手动备份
	STATUS_STOP_BACKUP,				//停止自动备份
	STATUS_END_MANUAL,				//结束手动备份
	STATUS_END_BACKUP,				//结束自动备份
	STATUS_NO_DISK_BACK,			//没有空间
}LOGENT_STATUS;

//设备回调类型
typedef enum _CALLTYPE
{
	DEV_ALARM,
	DEV_DISCONNECT,
}Dev_CallType;


//树节点类型枚举
typedef enum
{
	ITEM_ORG,		//组织结构
	ITEM_DEV,		//设备
	ITEM_CHNNL,		//通道
	ITEM_PREVCHANL,     //预览通道
	ITEM_REAL_ROOT,	//实时存储根节点
	ITEM_BACK_ROOT,	//备份根节点
	ITEM_PROJECT,	//实时存储方案
	ITEM_BACKUP_PROJECT,	//从DVR备份数据方案

	ITEM_IPS,		//IP存储
	ITEM_IPS_DEV,	//ips设备下的DVR
	ITEM_DECODER_DEV,
	ITEM_ALARM_CHANNEL,
	ITEM_DECODER_CHANNEL,
	ITEM_MAIN_CHANNEL,
	ITEM_SUB_CHANNEL,
	ITEM_DECODER_TOURPLAN,
	ITEM_DECODER_PLANNODE,
	ITEM_DECODER_LAYOUT,
	ITEM_DECODER_LAYOUTNODE,
	ITEM_DECODER_PROGRAM,
	ITEM_DECODER_PROGRAMNODE,
	ITEM_DECODER_OUTPUT
}TREE_ITEM_TYPE;

//组织结构事件枚举
typedef enum
{
	ORGENT_ADD,		//添加
	ORGENT_MOD,		//修改
	ORGENT_DEL,		//删除
}ORG_EVENT;

typedef enum _LOG_TYPE
{
	LOGTYPE_OPERATION = 0x1,//操作
	LOGTYPE_ALARM = 0x2,	//告警
}LOG_TYPE;

#ifdef OEM_YILITUO
typedef enum _LOG_OPERATION_TYPE_
{
	OPERATION_VIDEO = 0,
	OPERATION_PLAYBACK,
	OPERATION_TALK,
	OPERATION_USERMANAGER,
	OPERATION_CLIENTCONFIG,
	OPERATION_DEVICECONFIG,
	OPERATION_SYSTEMCONTROL,
	OPERATION_NUM ,
}LOG_OPERATION_TYPE;
#else
#ifdef OEM_LIANTENG
typedef enum _LOG_OPERATION_TYPE_
{
	OPERATION_VIDEO = 0,
	OPERATION_PLAYBACK,
	OPERATION_TALK,
	OPERATION_BACKUP,
	OPERATION_USERMANAGER,
	OPERATION_MAP,
	OPERATION_CLIENTCONFIG,
	OPERATION_DEVICECONFIG,
	OPERATION_SYSTEMCONTROL,
	OPERATION_COMALARM_CONFIRM,
	OPERATION_COMALARM_ARM,
	OPERATION_COMALARM_DISARM,
	OPERATION_NUM,
}LOG_OPERATION_TYPE;

typedef enum _LOG_ALARM_TYPE_
{
	ALARM_IOTRIGGER = 0,
	ALARM_MOTIONDETECT,
	ALARM_LOSSDETECT,
	ALARM_BLINDDETECT,
	ALARM_VIDEOANALYSEDETECT,
	ALARM_DSIKEEROR,
	ALARM_DISKFULL,
	ALARM_COM,
	ALARM_NUM,
}LOG_ALARM_TYPE;

#else
typedef enum _LOG_OPERATION_TYPE_
{
	OPERATION_VIDEO = 0,
	OPERATION_PLAYBACK,
	OPERATION_TALK,
	OPERATION_BACKUP,
	OPERATION_USERMANAGER,
	OPERATION_MAP,
	OPERATION_CLIENTCONFIG,
	OPERATION_DEVICECONFIG,
	OPERATION_SYSTEMCONTROL,
	OPERATION_NUM,
}LOG_OPERATION_TYPE;

typedef enum _LOG_ALARM_TYPE_
{
	ALARM_IOTRIGGER = 0,
	ALARM_MOTIONDETECT,
	ALARM_LOSSDETECT,
	ALARM_BLINDDETECT,
	ALARM_VIDEOANALYSEDETECT,
	ALARM_DSIKEEROR,
	ALARM_DISKFULL,
	ALARM_NUM,
}LOG_ALARM_TYPE;

#endif //OEM_LIANTENG
#endif //OEM_YILITUO



//寻找流媒体过程中的一些返回值
enum 
{
	FIND_SECCESS,		//成功
	REC_FLUX_EXCEED,	//接收数据超限
	SEND_FLUX_EXCEED,	//发送数据超过
};

typedef enum _DEV_LOGIN_TYPE_
{
	LOGIN_TYPE_DOMAIN,			//域名
	LOGIN_TYPE_IP,				//IP地址
	LOGIN_TYPE_ARSP_SERIAL,		// ARSP 序列号（目前是设备mac地址去掉中间分隔符）
	LOGIN_TYPE_CLOUD_SERIAL,		// 云 序列号 （目前是根据设备mac地址计算出的一个16位字符串）
#ifdef ADDALLDEVICESINLAN
	LOGIN_TYPE_MAC					//先根据MAC地址找到局域网内的设备，登陆，找不到根据MAC计算序列号用云方式登陆
#endif
}DEV_LOGIN_TYPE;

typedef enum _PLAYBACK_TYPE_
{
	PLAYBACK_TYPE_REMOTE,		//远程回放
	PLAYBACK_TYPE_LOCAL		 //本地回放
}PLAYBACK_TYPE;

typedef enum _DEV_DISCONNECT_TYPE_
{ 
	DISCONNECT_PREVIEW,       //用于预览的设备连接断开
	DISCONNECT_LOCALRECORD,	  //录像计划的设备连接断开
	DISCONNECT_DOWNLOADPLAN,  //下载计划
	DISCONNECT_DECODER,		  //解码器设备连接断开
	DISCONNECT_TYPE_NUM
}DEV_DISCONNECT_TYPE;
struct ModuleFileInfomations
{
	CString		strFullPath;
	CString		strPath;
	CString		strDrive;
	CString		strDir;
	CString		strName;
	CString		strExt;
};

#define _DELETE_(x)											if(x){delete x;x = NULL;}
#define _DEL_ARRAY_(x) 										if(x){delete [] x;x = NULL;}

#define	 LOGIN_FILE											_T("ConfigModule.ini")
#define	 CMS_CONFIG											_T("User.ini")
#define	 CMS_SKIN_DIR										_T("Skin\\")
#define	 CMS_XML_DIR										_T("XML\\")
#define	 CMS_LOG_DIR										_T("LOG")
#define	 CMS_ALARM_LOG										_T("alarmlog.xml")
#define	 CMS_OPR_LOG										_T("oprlog.xml")
#define	 CMS_SOUND_FILE										_T("Sound\\AlarmSound.wav")
#define	 THEME_FILE											_T("theme.ini")

#define	 HEARTBEETINTER										40*1000
#define  DHDEVCPORT											37777 					//大华设备端口
#define  HKDEVCPORT											8000  					//海康设备端口

const char NAME_INVALID_CHARS[]								= {'\\','/','*','?',':','"','<','>','|'}; //名称中的无效的特殊字符（因文件或文件夹名称不能包含这些字符）
const int FILE_BUF_SIZE										= 4096;
const int FILE_TOTAL_NUM									= 2;
//const int TALK_PORT									= 100;   //在H264play.h中定义对讲端口

//轮巡时间段,开始年月日和结束年月日
const int BYEAR   											= 1981;
const int BMONTH  											= 8;
const int BDAY    											= 21;
const int EYEAR   											= 1982;
const int EMONTH  											= 2;
const int EDAY 	  											= 15;


const int			MAXALARMBUF								= 100;
const int			MAXUSERPSWLENGTH						= 128;
const int			TIMEOUT									= 2000;
const int			MAX_BUF_SIZE 							= 180 * 1024;
static const int	MAXNAMESIZE 							= 64;						//32;
static const int	MAXWNDTOTAL								= 144;		   //最大支持视频窗口数为128				
static const int	MAXDESSCRIPTION							= 200;
static const int	ALARMFIRSTWND							= 0;		
static const int	ALARMWNDTOTAL							= 4;
static const int	TIMELIMIT								= 90;
static const int	MAXALARMTOTALWND						= 20;						//报警最多显示的窗口数
static const int	MAXPATH 								= 128;						//目前存放长度
static const int	MAXDEVIC 								= 16;						//最大设备树
static const int	COUNTPREVCHANNL 						= 0;						//预览通道总数
static const int	PREVIEWCHANNL 							= NET_MAX_CHANNUM;						//预览通道号 
static const int	CHANNELS_MAX 							= PREVIEWCHANNL + COUNTPREVCHANNL ;   
static const int	MAX_PSW_LENGTH 							= 256;						

static const int	MAX_IP_SIZE								= 16;
static const int	MAX_SINGLE_BUF_SIZE						= 4 * 1024;					//每个视频包的长度
static const int	HEAD_SIZE								= 32;
//static const int	CHANNELS_MAX = 16;
static const int	TOP_HIGHT								= 72;			//顶部图片的高
static const int	MAX_RECORD_FILE							= 100;			//最大录像文件保存数
static const int	MAX_AREA_NODE							= 100;
static const int    MAX_CMS_CHN                             = 1024;
static const int    MAX_SEARCH_DEVICE                       = 500;

#define MAX_HDDECODER_CHANNEL_NUM                           4
#define MAX_TOURPLAN_NUM                                    64
#define DISK_DEL_MIN				                         (256*1024*1024) // 存储空间只有128M时不能再录像
#define DISK_FREE_MIN				                         (128*1024*1024) // 存储空间只有128M时不能再录像

#define SYSTEM_LOGFILE 										_T("SYSTEMLOG.dat")
#define MAP_FOLDER											_T("Temp_SCMap\\")					//
#define ENERGEBT_RECORD 									_T("Record\\")   //紧急录像文件夹名,
#define DH_LOG												_T("LOG\\")
#define LOCAL_MAP_FOLDER									_T("XML\\map\\")
#define REMOTE_MAP_FOLDER									_T("R_map\\")
#define LICENCE_FILE  										_T("Licence.dat")

#ifdef OEM_Airlink
#define	SYSTEM_USER											_T("admin")
#else
#define	SYSTEM_USER											_T("super")
#endif // OEM_Airlink

#define SYSTEM_GROUP										_T("administrator")
#define DATA_XML											_T("xml\\Temp_SCData.xml")
#define ALARM_XML   										_T("xml\\Alarm.xml")				//报警设置数据（监控单元用）
#define ALARM_WATCH_XML										_T("xml\\Alarm_watch.xml")			//报警设置数据（监控单元用）
#define ALARM_XML_SHOW										_T("xml\\Alarm_show.xml")			//新设置报警数据（报警单元用）
#define ALARM_ENABLE_XML 									_T("AlarmEnable.xml")
#define DECODER_ENABLE_XML 									_T("DecoderEnable.xml")
#define ALARM_PERIOD_XML 									_T("xml\\AlarmPeriod.xml")
#define LOGINDATA_XML										_T("xml\\Login_DevData.xml")
#define	XM_DEVICE_XML										_T("Data.xml")
#define	XM_USER_XML											_T("Users.xml")
#define	XM_ALARM_XML										_T("XML\\AlarmPlan.xml")
#define	XM_FILE_XML											_T("XML\\XMLManager.xml")
#define LOCAL_DATA_XML										_T("XML\\Data.xml")
#define LOCAL_USER_XML										_T("XML\\Users.xml")
#define REMOTE_DATA_XML										_T("XML\\R_Data.xml")
#define REMOTE_USER_XML										_T("XML\\R_Users.xml")
#define VIDEO_COLOR_XML 									_T("VideoColor.xml")
#define DECODER_PREPROGRAM_XML								_T("XML\\DecoderPreProgram.xml")

#define	MAX_CHILD  											9							//最大子解码器个数
#define XM_DEVICE_DICALARM									0x1009						//设备断线报警
#define	MAX_NAME_SIZE										64							//用户名长度
#define	MAX_DEV_NUM											256							//每个转发服务器连接的最大机器数
#define MAX_IP_SIZE											16							//IP地址长度
#define LISTEN_PORT											39999						//侦听端口号
//#define PACKHEAD_LENGTH										32							//包头长度
#define PACKAGEBUF_SIZE										180 * 1024
#define RECEIVE_BUFFER										16 * 1024					//接收的最大程度
#define MAX_TOTAL_CHANNEL									500
#define MAX_IPS_DEV											1000

#define MAX_LENGTH											255							//用户最大长度
#define ID_RECORD_CHANNEL									0
#define ID_RECORD_RUNING									1
#define ID_CAM_IAMGE										2
#define ID_DEVICE_CONNECT_IMAGE								3
#define ID_DEVICE_UNCON_IMAGE								4

#define MAX_BACKUP_CHANNEL									50							//最大允许同时备份通道数
#define MAX_CONNECT_DEVNUM									1							//于转发的每个连接处理5台设备的数据

#define DEFAULTBUF_SIZE										16*1024						//默认每个缓冲大小
#define SAVE_BUFF_SIZE										160*1024					//保留缓冲大小
#define SEND_DATA_LENGTH									4*1024
#define TIMER_ONCE											1							//计时器间隔
#define N_TSECT												6							//时间段个数
#define MAX_USERNAME_LENGTH									16							//DVR用户名最大长度
#define MAX_USER_PSW										16							//DVR密码最大长度
#define DEV_TREEHEIGHT										200							//设备树高度
#define DEV_TREEWIDTH										200							//设备树宽度
#define MAX_STREAM				2		//组多有几种码流

#define  SPLIT_HIGHT 50
#define  MAX_DECODERCHNNEL_SUP   32                  //当前设备本身最大支持解码通道数位32

#define UM_ICONNOTIFY										WM_USER + 100					//添加图标
#define ID_SHOW_WINDOW										WM_USER + 101					//显示程序
#define ID_EXIT_SYSTEM										WM_USER + 102					//退出系统
#define ID_SHOW_ABOUT										WM_USER + 103					//关于
#define ID_ADD_NETDRIVES									WM_USER + 1111				//添加网络映射盘
#define ID_ADD_BACKUP_DISK									WM_USER + 1116				//添加备份盘
#define ID_MODIFY_BACKUP_DISK								WM_USER + 1119				//修改备份磁盘
#define ID_STOP_RECORD										WM_USER + 1121
#define ID_CONFIG											WM_USER + 1122
#define ID_START_PROJECT									WM_USER + 1123
#define ID_CONFIG_PROJECT									WM_USER + 1124
#define ID_SELECT_ALL										WM_USER + 1125
#define ID_UNSELECT_ALL										WM_USER + 1126
#define ID_REAL_BACKUP										WM_USER + 1127
#define ID_BACKUP_DVR										WM_USER + 1128
#define ID_MANUAL_BACKUP									WM_USER + 1129
#define ID_STOP_MANUAL_BACKUP								WM_USER + 1130
#define IDC_SYSTEMUSER										WM_USER + 3000

typedef struct {
	char nName[64];			//名称
	char nVer[64];			//版本号
	char nPrivided[64];		//提供商
	char nZhuChe[64];		//注册商
	char nLicence[64];		//注册号
	int	 nMaxDay;			//使用日期(天)
	int  nMaxChannel;		//通道数
	char szFirstDay[10];	//首次使用日期
	int  nComfirm;			//验证码
	int  nUsedDay;			//已经使用天数
	BOOL bPSS;				//是否是PSS
}LICENCE_INFO;

typedef union {	//IP addr
	char	c[4];
	short	s[2];
	long	l;
} UNION_LONG;

typedef struct _ALARM_TYPE
{
	BOOL bEnable;						//是否有效
	BOOL bAutoWatch;					//是否自动监视
	BOOL bSound;						//是否提示报警声
	unsigned int	iIgnoredSecond;		//报警忽略时间
	char szSoundPath[256];	//报警声音路径
	
	_ALARM_TYPE()
	{
		bEnable = TRUE;
		bAutoWatch = FALSE;
		bSound     = FALSE;
		iIgnoredSecond = 5;
		memset( szSoundPath , 0 , sizeof( szSoundPath ) );
	}
}Alarm_Type; //不同类型的报警设置

typedef struct _AREA_INFO
{	
	char szArea[MAXNAMESIZE];                   // 所属区域
}AREA_INFO,*pAREA_INFO;

typedef struct _DEVICE_INFO
{	
	long			ID;										// 唯一标识符.
	char			szArea[MAXNAMESIZE];                   // 所属区域
	char			szDevName[MAXNAMESIZE];   				// 机器名.
	char			szDevIP[MAXNAMESIZE];     				// 机器ip.，启用DDNS后表示DDNS服务的地址
	char            szLanIP[MAXNAMESIZE];                   //内网IP 
	char			szUserName[MAXNAMESIZE];  				// 登陆用户名.	
	char			szPassWord[MAXNAMESIZE];  				// 登陆用户密码.
	char			szHostName[MAXNAMESIZE];				//DDNS主机名
	int				nTotalChannel;   						// 设备的通道数.
	int				nAlarmChannel;							//报警通道
	int				nError;          						//保留字节,记录了设备登陆返回的失败信息
	int				nDDNSFlag;		 						//DDNS开关量，1:使用, 0:不使用
	DWORD			dwLoginType;		 						// 登陆方式   enum DEV_LOGIN_TYPE
	DWORD			dwDevIP;		 						// 机器ip.
    DWORD			dwPort;          						// 登陆端口号.	
	DWORD			nFlag;           						// 保留字节. (暂记录设备登录ID)
	DWORD			dwPos;		 						    //记录在窗口中的位置
	DWORD			dwTreeItem;								//记录设备树中的节点句柄，可以节省查找事件
	DWORD			dwOrgID;								//组织结构ID
	DEVC_CLASS      devcType;        					    //设备类型，目前包含了dvr，门禁设备，报警设备三种
	VIDEONET_DEVICEINFO  NetDeviceInfo;  				    // DVR报警输入个数，DVR硬盘个数，DVR类型，DVR通道个数
	VENDOR_TYPE     vendorType;                             // 产家：雄迈，大华，海康,黄河
	DWORD           dwSearchTreeItem;   			        //记录查找树中的节点句柄，可以节省查找事件，
	int             nLinkMode;                              //连接模式,TCP和UDP,0为TCP,1为UDP
	char			szMacAddress[MAXNAMESIZE];
	int             nARSPStatus;                                 //用于ARSP用户名获取的设备是否在线。 1在线，0不在线            
}DEVICE_INFO,Devc_Info,In_DeviceInfo,*pDEVICE_INFO;

typedef enum 
{
	 TV_TYPE_NONE = 0,
	 TV_TYPE_LAYOUT = 1,
	 TV_TYPE_TOUR = 2,
	 TV_TYPE_SINGLECAMERA = 3
};

typedef struct DECODER_WND
{
	int nWndNo;
	CRect rtWnd;
	char chName[64];
	int nDecoderID;
	int nDecoderOutput;
	int bConnected;
	int nType;
	int nID;
	int nChannelNo;
	bool bTourStart;
};

typedef struct PREPROGRAM
{
	int nID;
	bool bUse;
	char chName[64];
	DECODER_WND wnd[MAXWNDTOTAL];
};
// 通道信息.
typedef struct _CHANNEL_INFO
{
	char				szChnnelName[MAXNAMESIZE];			// 通道名称.
	int					nChnnID;							// 用于地图节点管理
	int					nChannelNo;							// 通道号.
	int					bUserRight;							// 用户权限(使能).
	int					PreViewChannel;						// 预览通道
	int					nStreamType;						// 码流类型
	DEVICE_INFO			DeviceInfo;							// 设备信息.
	int					nCombinType;						// 组合编码模式
	DWORD				dwTreeItem;							//记录设备树中的节点句柄，可以节省查找事件
	int                 nFlag;								//1为选择为录像 0 为没有被选择 2 为正在录像
	unsigned int        nWndIndex;
}CHANNEL_INFO,*pCHANNEL_INFO;

typedef struct CameraLayout
{
	int nLayoutID;
	int nUsed;
	char szLayoutName[64];
	int nCameraCount;
	CHANNEL_INFO Cameras[36];
};
typedef struct _HDDECODER_INFO
{	
	long			ID;										// 唯一标识符.
	char			szDevName[MAXNAMESIZE];   				// 机器名.
	char			szPassWord[MAXNAMESIZE];  				// 登陆用户密码.
	int             nOutPuts; //输出通道数
	DEVICE_INFO    outputsInfo[MAX_HDDECODER_CHANNEL_NUM];  				
}DECODER_INFO;
// 通道信息.
typedef struct _CHANNEL_INFO_EX
{
	char				szChnnelName[MAXNAMESIZE];		// 通道名称.
	int					nFlag;              			//0为通道连接,1为通道断开
	int					nChnnID;						// 用于地图节点管理
	int	 				nChannelNo;						// 通道号.
	int					bUserRight;						// 用户权限(使能).
	int					PreViewChannel;					//预览通道
	int					nStreamType;					//码流类型
	DWORD				dwTreeItem;						//记录设备树中的节点句柄，可以节省查找事件
	DWORD               dwSearchTreeItem;   			//记录查找树中的节点句柄，可以节省查找事件，
	NET_RealPlayType		MultiType;						//预览方式
}CHANNEL_INFO_EX,*pCHANNEL_INFO_EX;

// 设备信息表.
typedef struct _DEVICE_INFO_EX
{
	DEVICE_INFO			DeviceInfo;
	pCHANNEL_INFO_EX	pChnlInfo; 					// 通道数组头地址.
	int                 nSize;     					// 通道数组单位长度(通道个数)
	bool                bIOControlFlag;  			// 12v开关控制
	DWORD				dwResarchTreeItem;			// 记录查找树中的节点句柄，可以节省查找事件，
	char                szAlarmPlanName[MAXNAMESIZE]; //设备所属于的报警方案
}DEVICE_INFO_EX,Devc_Info_EX,*pDEVICE_INFO_EX;

// 设备状态.
typedef struct _DEVICE_STATUS
{
	DEVICE_INFO			DeviceInfo;					// 设备信息.
	DEVICE_EVENT		DeviceEvent;				// 设备事件(状态类型).	
	int					nStatus;					// 所处状态(开关).
	long				lParam;						// 预留字.
}DEVICE_STATUS,*pDEVICE_STATUS;

// 通道状态.
typedef struct _CHANNEL_STATUS
{
	CHANNEL_INFO		ChannelInfo;				// 通道信息.
	CHANNEL_EVENT		ChannelEvent;				// 通道事件(状态类型).
	int					nStatus;					// 所处状态(开关).
	long				lParam;						// 预留字.准备记录播放句柄
}CHANNEL_STATUS,*pCHANNEL_STATUS;


//组织结构信息
typedef struct 
{
	long				nID;							//id
	long				lParentID;						//父节点ID	
	char				szName[MAXNAMESIZE];			//名称
}ORGANIZATION_INFO;

typedef struct _DISCHANNELINFO
{
	int					nWndID;							//窗口号
	int					nSubWnd;						//子窗口好
	int					nChannelNo;
	int                 nStream;                        //码流类型
	int					PreViewChannel;					//预览通道
	NET_RealPlayType		MultiType;						//预览方式
}DISCHANNELINFO, *pDISCHANNELINFO;


//本地用户管理接收的设备信息结构
typedef struct _USER_DEVICE_INFO
{
	int					nDeviceID;
	DWORD 				dwPort;
	int					nChannelTotal;
	char				szDevName[MAXNAMESIZE];
	char				szDevIP[MAXNAMESIZE];
}USER_DEVICE_INFO, *pUSER_DEVICE_INFO;


// 通道控制.
//..........
typedef struct _CHANNEL_CTRL
{
	CHANNEL_INFO	ChannelInfo;					// 通道信息.
	CHANNEL_EVENT		ChannelEvent;					// 通道事件(状态类型).
	int					nSwith;							// 要求状态(开关).
	long				lParam;							// 预留字.
	long				lResevred[5];					//预留字
}CHANNEL_CTRL,*pCHANNEL_CTRL;

// 设备控制.
//..........
typedef struct _DEVICE_CTRL
{
	DEVICE_INFO			DeviceInfo;						// 设备信息.
	DEVICE_EVENT		DeviceEvent;					// 设备事件(状态类型).
	int					nSwith;							// 要求状态(开关).
	long				lParam;							// 预留字.
}DEVICE_CTRL,*pDEVICE_CTRL;


//报警使能结构
typedef struct _ALARM_ENABLE
{
	long 				lDevID;
	char 				nChannel[NET_MAX_CHANNUM];
}ALARM_ENABLE;


typedef struct _OTHER_LOG
{
	OTHER_LOG_EVENT		LogEvent;      				//其他消息的类型
	long				lParam;						//保留用
}OTHER_LOG, *pOTHER_LOG;

//断开设备信息
typedef struct _DISDEVINFO
{
	DEVICE_INFO			DeviceInfo;					// 设备信息.
	DISCHANNELINFO		ChannelInfo[CHANNELS_MAX];	//通道信息
	int					nSize;
	DEV_DISCONNECT_TYPE DisconnectType;
}DISDEVINFO,*p_DisDevInfo;



//常量定义
typedef struct _RECORD_QUERY_INFO 
{
	DWORD				dwUserData;					//用户参数，给线程使用
	DWORD               dwFileHandle;              //用户参数，给线程使用
	int                 nQueryMode;                 //0: by name 1: by time
	long				lDevID;						//设备ID
	unsigned __int64	nChannelNO;					//通道号, 按时间查询时通道号用掩码表示
	int					nMaxSize;					//最大录像条数
	int					nRecType;					//录像类型
	int					nRecSource;					//录像来源，见QUERY_MODE
	char				szCardNO[64];				//卡号数据
	VIDEONET_TIME			BegTime;
	VIDEONET_TIME			EndTime;
	int    iSync;               ///< 是否需要同步
}RECORD_QUERY_INFO;

typedef struct _PACKET_BUF
{
	unsigned char		szDataBuf[MAX_BUF_SIZE];
	int					nDataSize;
}PACKET_BUF;

enum QUERY_MODE
{
	DEVICE_BY_NAME, //设备回放，按文件名
	LOCAL_BY_NAME,  //本地回放，按文件名
	DEVICE_BY_TIME, //设备回放，按时间
	LOCAL_BY_TIME,  //本地回放，按时间
};

typedef struct _RECORD_QUERY_PARAM
{
	long				lDevID;
	unsigned __int64	nChannelNO;
	int					nMaxSize;					//最大录像条数
	int					nRecType;					//录像类型
	int					nRecSource;					//录像来源( 0 - 设备按文件名  1 - 本地按文件名 2 - 设备按时间 3 - 本地按时间)
	char				szCardNO[64];				//卡号数据
	VIDEONET_TIME			BeTime;
	VIDEONET_TIME			EndTime;
	int    iSync;               ///< 是否需要同步
}RECORD_QUERY_PARAM;

typedef struct _TIME_NETPLAY_PARAM
{
	NEW_NET_TIME			BeTime;
	NEW_NET_TIME			EndTime;
}TIME_NETPLAY_PARAM;

typedef struct _LOG_INFO
{
	LOG_TYPE			type;                    //类型,有告警和操作
	unsigned int		subType;                 //子类型, 告警和操作分别有不同的子类型
	VIDEONET_TIME		time;                    //日期时间
	long				lDevID;					 //设备ID
	char				DevcName[MAXNAMESIZE];       //设备名
	char				UserName[MAXNAMESIZE];       //用户名
	LOG_EVENT			event;                       //事件
	LOGENT_STATUS       status;                      //事件3种状态,请求中,成功和失败 0, 1 , 2
	int					nNo;
	char				DescrInfo[MAXDESSCRIPTION];  //描述信息
}LOG_INFO, *pLOG_INFO;

//树节点数据的结构
typedef struct 
{
	TREE_ITEM_TYPE		nItemType;			//节点类型，参考TREE_ITEM_TYPE
	long				lItemParam;			//节点数据
	long				lReserve;			//保留数据
}TREE_ITEM_DATA;

typedef struct 
{
	int						nID;					//id
	DWORD					dwTreeItem;				//设备树位置
	char					szName[MAXNAMESIZE];	//名称
}ORG_MSG_INFO;

//信息
typedef struct _INFO_TYPE
{
	INFO_EVENT				infoType;				//信息类型
	long					lParam;					// 预留字.
}INFO_TYPE;

//组织结构变更
typedef struct _ORG_CTRL
{
	ORG_EVENT				event;
	ORG_MSG_INFO			orgInfo;
}ORG_CTRL;

typedef struct 
{
	long lDevID;
	int nChannelNo;
	long lReserve;
}ALARM_LINK_CHANNEL, DECODER_LINK_CHANNEL;
typedef std::vector<ALARM_LINK_CHANNEL> VectorPort;

typedef struct 
{
	long			lDevID;
	int				nPort;
	VectorPort	vecPortPlan;
}ALARM_LINK_PORT,DECODER_LINK_PORT;

typedef CList<ALARM_LINK_PORT, ALARM_LINK_PORT> LIST_LINK_PLAN;

//日志事件的类型
typedef enum
{
	EN_EVENT_TYP_INFORMATION,	//信息
		EN_EVENT_TYP_WARNING,		//告警
		EN_EVENT_TYP_ERROR,			//错误
}EN_EVENT_TYP;


//录像查询类型
typedef enum 
{
	SEARCH_RECORD_COMMON = 0,
	SEARCH_RECORD_ALARM = 1,
	SEARCH_RECORD_MOTION = 2,
	SEARCH_RECORD_HAND = 0x03,		///< 手动录像
	SEARCH_RECORD_SNAP = 0x04,		///< 抓图
}ERECORD_SEARCH_TYPE;





//XML管理盘符结构
typedef struct {
	char				Drives[4];
	int					bType;
	char				XMLPath[MAXPATH];
}DRIVES_XML;

//XML管理结构
typedef struct {
	long				lID;				//记录ID号
	VIDEONET_TIME			begintime;			//开始时间
	VIDEONET_TIME			endtime;			//结束时间
	char				path[MAXPATH];		//文件路径
}XML_MANAGER;

//XML管理结构
typedef struct {
	long				lDevID;				//设备ID
	int					nChnlNo;			//通道号
	char				path[MAXPATH];		//文件路径
}CHNL_XML_MANAGER;

//文件信息结构
typedef struct  {
	long	lID;			//记录ID号
	char Drive[4];			//盘符
	VIDEONET_TIME begintime;			//开始时间
	VIDEONET_TIME endtime;			//结束时间
	long devID;				//设备ID
	int nChannelNo;			//通道号
	long size;				//当前文件大小
	char path[MAXPATH];		//文件路径
	char type;				//文件类型 RECORD_TYPE
}FILE_RECORD;


//客户端录象信息结构
typedef struct{
	DEVICE_INFO DeviceInfo;
	FILE_RECORD fileRecord;
}LOCALREC_FILE;

//录像通道结构
typedef struct {	// 定时时段
	BYTE				StartHour;
	BYTE				StartMin;
	BYTE				StartSec;
	BYTE				EndHour;
	BYTE				EndMin;
	BYTE				EndSec;
	BYTE				State;						//第二位是定时，第三位是动态检测，第四位是报警
	BYTE				Reserve;
} TSECT;
typedef struct {
	TSECT				Sector[7][N_TSECT];			//定时时段7
	BYTE				PreRecord;					//预录开关（时间）
	BYTE				Reserved[3];
} CONFIG_RECORD;


//自动录像结构
typedef struct _PSS_RECORD_CONFIG
{
	long				lChannelID;
	int					nChannlNo;
	long				lDevID;
	CONFIG_RECORD		RecordTime;					//时间结构
}PSS_RECORD_CONFIG;
//自动录像结构
typedef struct _PSS_HDD_CONFIG
{
	char				szBeginPartition[4];		// 第一个盘符.
	char				szEndPartition[4];			// 最后一个盘符.
	long				lFileSize;					//文件大小
	long				lAlarmSize;					//报警文件大小
	long				lModSize;					//动态检测文件大小
	BOOL				bAutoReocrd;				//自动录像
	BOOL				bOverMode;					//自动覆盖
}PSS_HDD_CONFIG;
//自动录像结构
typedef struct _RECORD_CONFIG
{
	char				szProjectName[16];			//方案名称
	CONFIG_RECORD		RecordTime;					//时间结构
	long				nFileTime;					// 录像文件打包长度.
	bool				bOverMode;					// 是否循环覆盖.
	bool				bAutoRecord;				//是否自动录像
	char				szBeginPartition[4];		// 第一个盘符.
	char				szEndPartition[4];			// 最后一个盘符.
	long				lFileSize;					//文件大小
	long				lAlarmSize;					//报警文件大小
	long				lModSize;					//动态检测文件大小
	long				lProjectID;					//方案ID
	BOOL				bRun;						//是否正在运行
	DWORD				dwTreeItem;
}RECORD_CONFIG,*pRECORD_CONFIG;

typedef struct {
	TSECT	Sector[N_TSECT];		//定时时段7
	BYTE	PreRecord;				//预录开关（时间）
	BYTE	Reserved[3];
} B_CONFIG_RECORD;
//从DVR备份录像结构
typedef struct _BACKUP_CONFIG
{
	char				szProjectName[16];			//方案名称
	long				lProjectID;					//方案ID
	char				szBeginPartition[4];		// 第一个盘符.
	char				szEndPartition[4];			// 最后一个盘符.
	TSECT				Sector[2];					//定时时段2
	B_CONFIG_RECORD		RecordTime;					//时间结构
	BOOL				bRun;						//是否正在运行
	DWORD				dwTreeItem;
	long			nDaysBefore;
}BACKUP_CONFIG;
//时间
typedef struct 
{
	DWORD dwYear;		//年
	DWORD dwMonth;		//月
	DWORD dwDay;		//日
	DWORD dwHour;		//时
	DWORD dwMinute;		//分
	DWORD dwSecond;		//秒
} NET_TIME;
//用于通道录像
typedef struct _MANUAL_BACKUP_CHANNEL
{
	int                 nFlag;              //1为选择为录像 0 为没有被选择 2 为正在录像
	int	 				nChannelNo;			// 通道号.
	char				szChnnelName[MAXNAMESIZE];	// 通道名称.
	DWORD				dwTreeItem;			//记录设备树中的节点句柄，可以节省查找事件
	DEVICE_INFO			DeviceInfo;
	int					nRecord;
	int					nSwith;				//记录需要开启还是关闭
	char				Drive[4];
	NET_TIME			BeTime;
	NET_TIME			EndTime;
}MANUAL_BACKUP_CHANNEL,*pMANUAL_BACKUP_CHANNEL;
typedef enum _MANUAL_EVENT
{
	START_MANUAL = 0x0,
		STOP_MANUAL,
}MANUAL_EVENT;
typedef struct _MANUAL_BACKUP_CTRL
{
	MANUAL_BACKUP_CHANNEL	ManualInfo;		// 通道信息.
	MANUAL_EVENT			ManualEvent;	// 通道事件(状态类型).
	int						nSwith;			// 要求状态(开关).
	long					lParam;			// 预留字.
}MANUAL_BACKUP_CTRL,*pMANUAL_BACKUP_CTRL;
typedef enum _PROJECT_EVENT
{
	PEVENT_REALTIME,
	PEVENT_BACKUP,
}PROJECT_EVENT;

//用于通道录像
typedef struct _CHANNEL_INFO_RECORD
{
	int                 nFlag;						//1为选择为录像 0 为没有被选择 2 为正在录像
	int					nChnnID;					// 用于地图节点管理
	int	 				nChannelNo;					// 通道号.
	char				szChnnelName[MAXNAMESIZE];	// 通道名称.
	DWORD				dwTreeItem;					//记录设备树中的节点句柄，可以节省查找事件
	DEVICE_INFO			DeviceInfo;
}CHANNEL_INFO_RECORD;

//// 解码器配置
//typedef struct _DECODER_INFO_
//{
//	char szHostAddr[MAXNAMESIZE];
//	char szUserName[MAX_USERNAME_LENGTH];
//	char szPassword[MAX_USER_PSW];
//	int  nPort;
//	char szDesc[MAX_PSW_LENGTH];
//}DECODER_INFO,Decoder_Info,*pDECODER_INFO;

typedef enum
{
	TOUR_STOP = 0,
	TOUR_START,
	TOUR_FAIL,
};

// 轮巡方案
typedef struct _VIDEO_TOUR_NODE_
{
	int nDevID;     //设备ID
	int nChannel;   //通道号
	int nInterval;  //间隔时间
	int nStatus;    //0:停止轮巡  1;正在轮巡 2:开启轮巡失败
	int nVWndID;    //原来处于什么状态，是开启还是关闭
	int nStream;
}VIDEO_TOUR_NODE,*pVIDEO_TOUR_NODE;

// 解码器轮巡方案
typedef struct _DECODER_TOUR_NODE_
{
	int nLayoutID;
	CHANNEL_INFO chanInfo;

}DECODER_TOUR_NODE;
typedef std::vector<VIDEO_TOUR_NODE> VectorTourNode;
typedef std::vector<DECODER_TOUR_NODE> VectorDecoderTourNode;

typedef struct _VIDEO_TOUR_PLAN_
{
	int nPlanID;
	CString strName;
	int nIndex;
	VectorTourNode TourNodes;
}VIDEO_TOUR_PLAN,*pVIDEO_TOUR_PLAN;

typedef struct _DECODER_TOUR_PLAN_
{
	int nPlanID;
	CString strName;
	int nIndex;
	int nInterval;
	VectorDecoderTourNode TourNodes;
}DECODER_TOUR_PLAN;

//Task部分
enum TASK_STATUS
{
	TASK_STOP = 0,
	TASK_START,
	TASK_FAIL,
};

//Task计划节点
typedef struct _DEVICE_TASK_NODE_
{
	int nDevID;  //设备ID
	int nChannel;  //设备通道
	int nStatus;  //状态，0为播放，1为停止
	int nStream;  //0为辅码流，1为主码流
	int nRes;  //保留便于扩展
}DEVICE_TASK_NODE, *pDEVICE_TASK_NODE;

typedef std::vector<DEVICE_TASK_NODE> VectorTaskNode;

//Task方案
typedef struct _DEVICE_TASK_MAN_
{
	int nTaskID;
	CString strTaskName;
	VectorTaskNode TaskNodes;
}DEVICE_TASK_MAN, *pDEVICE_TASK_MAN;

//////////////////////////////////////////////////////////////////////////
//与电子地图的数据交换结构
#define  MAX_NAME_LEN		128
#define  MAX_FILE_LEN		128
#define  MAX_DESC_LEN		256

enum  ItemType
{
	IMG,			//图片
	DEV,			//设备
	CAMERA,			//摄像头
	ALARMDEV,		//报警器
};

enum DataType
{
	DATA_DEVICE = 0,	//设备数据	
	DATA_IMAGE	= 1,	//图片数据
	DATA_MAP	= 2,	//地图信息
	DATA_ALL_DEV,		//所有设备数据	

};

enum OperateType
{
	ADD,
	DEL,
	MOD,
};

#define  MAX_WIDTH_NUM		2
#define  MAX_HEIGHT_NUM		48
#define ROOTITEM	0

typedef struct _DEVICEINFO
{
	int		nID;
	int		nType;
	int		nSubType;		//摄像头的子类型
	int		nDevId;			//设备ID
	int		nChnnlNO;		//通道号, 这两个信息在nType==CAMERA时有用
	char	szName[MAX_NAME_LEN];
	char	szDesc[MAX_DESC_LEN];
}DEVICEINFO;

//地图的逻辑位置坐标系为640*480，在父地图显示时需要转换为父地图的坐标系,
//每个宏快大小10*10,每bit表示一个列,该结构体只有地图使用
typedef struct _IMAGE_INFO
{
	int		nImageId;
	int     nMainMap;   //主地图
	char	szImageName[MAX_NAME_LEN];
	char	szIamgeFile[MAX_FILE_LEN];
	char	szIamgeDesc[MAX_DESC_LEN];	
	int     nArea[MAX_HEIGHT_NUM][MAX_WIDTH_NUM];
}IMAGE_INFO, *pIMAGE_INFO;

typedef struct _MAPITEM
{
	int nID;
	int nParentID;
	int nType;
	int nxPos;
	int nyPos;
}MAPITEM, *pMAPITEM;

struct ChildItem
{
	int nID;
	int nType;
	int xPos;
	int yPos;
};

struct MAPINFO
{
	int nID;
	std::vector<ChildItem> vectorChild;
};


struct MAP_CHANNEL_INFO
{
	int		nID;
	int		nSubType;
	char	szName[MAX_NAME_LEN];
	char	szDesc[MAX_DESC_LEN];
};

struct MAP_ALARMDEV_INFO
{
	int		nID;
	char	szName[MAX_NAME_LEN];
	char	szDesc[MAX_DESC_LEN];
};
struct MAP_DEVICE_INFO
{
	int		nID;
	char	szName[MAX_NAME_LEN];
	char	szDesc[MAX_DESC_LEN];
	MAP_CHANNEL_INFO* pChannelInfo;
	int		nChannelNum;
	MAP_ALARMDEV_INFO* pAlarmDevInfo;
	int		nAlarmDevNum;
};

typedef enum
{
	NO_BACKUP,				//不需要备份
	END_BACKUP,				//已经备份完毕
	BACK_ING,				//正在备份
	NEED_BACKUP,			//需要继续备份
	PAUSE_BACKUP,			//暂停备份
	FIRST_BACKUP = 8,		//第一次备份
	
	END_MANUALBACK = 10,	//手动备份结束
	MANUALBACK_ING,
	NEED_MANUALBACK,
	FIRST_MANUALBACK,
	PAUSE_MANUALBACK,		//暂停手动备份
}BACKUP_OPERATE;

typedef enum 
{		
	R_MONITOR = 0,				//实时监视
	R_PLAY_BACK,				//回放单元权限	
	R_BACKUP,					//实时备份
	R_REMOTE_CONFIG,			//设备远程配置
	R_LOG_VIEW,					//日志管理
	R_USER_MANAGER, 			//用户管理			
	R_OPERATE_DEV,				//设备管理			
	R_MAPCTRL,					//电子地图
	R_LOCAL_CONFIG,             //客户端配置
	R_PTZ,						//云台
	R_RIGHT_NUM
}R_USER_RIGHTS;

typedef enum 
{		
	PTZ_FALSE = 0,
	PTZ_TRUE,
	PTZ_FORBID,			//PTZ权限禁用
}PTZ_RESULT;

//定时下载
#define   TIME_ZREA  64  //暂定64个时间段
typedef struct _CLOCK_DOWNLOAD_INFO_
{
	int nIndex;  //时间段编号
	VIDEONET_TIME BeginTime;  //开始时间，只具体到Min
	VIDEONET_TIME EndTime;  //结束时间,只具体到Hour
}CLOCK_DOWNLOAD_INFO, *pCLOCK_DOWNLOAD_INFO;

typedef struct _TIME_DOWNLOAD_INFO_
{
	char	 szName[MAX_NAME_LEN];
	int nNum;  //时间段数
	CLOCK_DOWNLOAD_INFO Info[TIME_ZREA];
}TIME_DOWNLOAD_INFO;

typedef std::vector<TIME_DOWNLOAD_INFO> TIME_INFO_LIST; //时间段信息

//通道时间信息
typedef struct _CHN_TIME_INFO_
{
	int nNum;
	char szName[MAX_NAME_LEN]; //时间方案
}CHN_TIME_INFO;

typedef struct _CHN_INFO_
{
	int nType; //0为录像，1为图片，2为所有
	CHN_TIME_INFO TimeInfo;
	VIDEONET_TIME BeginTime;  //之前已经下载的文件开始
}CHN_INFO, *pCHN_INFO;
typedef std::map<int, CHN_INFO> MAP_CHN_INFO;  //通道时间段信息

typedef enum KaiCongLink
{
	KAICONG_LINK_CFG,
		KAICONG_RECORD_CFG,
		KAICONG_ALARM_CFG,
		KAICONG_SYS_CFG,
		KAICONG_MAN_TOOL_CFG,
		KAICONG_SYS_INFO_CFG,
		KAICONG_TECHNOLOGY_LOGO,
		KAICONG_ALARM_LOG,
		KAICONG_CFG_MANAGER,
		KAICONG_PLAYBACK
};
typedef enum KaiCongCfgType
{
		KAICONG_TECHNOLOGY_LOGO_LINK=65531,
		KAICONG_SYS_INFO_CFG_LINK,
		KAICONG_MAN_TOOL_CFG_LINK,
		KAICONG_SYS_CFG_LINK,
		KAICONG_ALARM_CFG_LINK,
		KAICONG_RECORD_CFG_LINK,	
};
//////////////////////////////////////////////////////////////////////////
//以下是返回信息
#define RET_SUCCESS						1		//返回成功
#define RET_LOGINED						2		//程序注册成功

//错误提示宏定义
#define EXCEPTION_ERROR       			-1        //异常错误,资源创建失败等 
#define WAITTIME_OUT          			-2        //等待超时
#define CONNECTCENTER_FAILED  			-3	      //连接控制中心失败
#define NO_RIGHT              			-4        //没有权限
#define CONNECTTS_FAILED      			-5        //连接转发服务器失败
#define CONNECTDEVC_FAILED    			-6        //(转发服务器)连接设备失败
#define INVALID_TS            			-7        //无效的转发服务器或转发服务器没有向控制中心注册连接
#define CONNECTCHANNL_FAILED  			-8        //转发通知通道连接失败
#define SENDDATATOTS_FAILED   			-9	      //发送数据失败(到转发)
#define SENDDATATOCENTER_FAILED		  	-10	      //发送数据失败(到中心)
#define DISCONNECT_DEVICE     			-11       //设备断开(正常断开,手动操作)
#define OPENFILE_FAILED	      			-12	      //文件打开失败
#define INVALID_USERPSW       			-13       //无效的用户名密码
#define CENTER_DISCONNECT     			-14	      //中心服务断开
#define TS_DISCONNECT	      			-15	      //转发已断开

#define  MAX_DECODEWND          36 //解码器最大支持窗口数
#define  MAX_PLAYBACK_WND		16 //回放最大支持窗口数
#define  MAX_DECODERPREVOEW_WND  8
#define  PLAY_DECODE_INDEX      ( MAX_DECODEWND*MAX_DECODERPREVOEW_WND + MAXWNDTOTAL ) //回放开始
#define  HH_MAX_PREVIEWWND_NUM	64

//#define COLOR_DEFAULT_BRIGHT            67
//#define COLOR_DEFAULT_CONTRAST          80
//#define COLOR_DEFAULT_HUE               64
//#define COLOR_DEFAULT_SATURATION        80

#define COLOR_DEFAULT_BRIGHT            64
#define COLOR_DEFAULT_CONTRAST          64
#define COLOR_DEFAULT_HUE               64
#define COLOR_DEFAULT_SATURATION        64
#define SPLIT_DEFAULT_VOLUME            100

#define PLAYBACK_MAX_FILE_NUM           64
#define MAX_PLAYBACK_CHANNEL            16


#define CONFIG_PROTOCOL_ONVIF  65534
#define CONFIG_PROTOCOL_MAC    65535
#define CONFIG_PROTOCOL_NR_V2  65536

#define RGB_REC_NORMAL	RGB(0,255,0)
#define RGB_REC_DETECT  RGB(100,100,100)
#define RGB_REC_ALARM  RGB(255,0,0)
#define RGB_REC_HAND   RGB(0,0,255)
#endif
