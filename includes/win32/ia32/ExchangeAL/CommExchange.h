//
//  "$Id: CommExchange.h 18649 2015-12-14 08:08:58Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  
//

#ifndef __EXCHANGEAL_COMM_EXCHANGE_H__
#define __EXCHANGEAL_COMM_EXCHANGE_H__

#include "ExchangeAL/CommExchange.h"
#include "Types/Defs.h"
#include "Types/Types.h"
#include "Infra/Time.h"
#include "Manager/EventManager.h"

#define SHOW_STR_LEN 32


/// 工作表名称索引
enum WorksheetName
{
	RECORD_WORKSHEET = 0,		///< 录像工作表
	ALARM_WORKSHEET = 1,		///< 报警工作表
	MOTION_WORKSHEET = 2,		///< 动检工作表
	BLIND_WORKSHEET = 3,		///< 遮挡工作表
	VIDEOLOSS_WORKSHEET = 4,	///< 视频丢失工作表
	NETALARM_WORKSHEET = 5,	    ///< 网络报警工作表
	VIDEOANALYZE_WORKSHEET = 6,	///<视频分析工作表
	IPC_ALARM_WORKSHEET = 7,	///< IPC报警工作表
	SERIALPORT_ALARM_WORKSHEET = 8,///<串口报警工作表
	WORKSHEET_NR,
};


/// 云台联动类型
enum PtzLinkTypes
{
	PTZ_LINK_NONE,			// 不需要联动 
	PTZ_LINK_PRESET,		// 转至预置点 
	PTZ_LINK_TOUR,			// 巡航 
	PTZ_LINK_PATTERN		// 轨迹 
};

/// 速度报警类型
enum SpeedAlarmTypes
{
	SPEED_ALARM_HIGH = 0,		// 高速报警
	SPEED_ALARM_LOW,		// 低速报警
	SPEED_ALARM_NR
};

///< 基本事件结构
struct GenericEventConfig
{
	bool bEnable;			///< 使能
	EventHandler hEvent;	///< 处理参数
};

/// 所有通道的基本时间结构
struct GenericEventConfigAll
{
	GenericEventConfig vGenericEventConfig[N_SYS_CH];
};

///< 动态检测设置
struct MotionDetectConfig
{
	bool bEnable;							// 动态检测开启 
	int iLevel;								// 灵敏度 
	uint mRegion[MD_REGION_ROW];			// 区域，每一行使用一个二进制串 	
	EventHandler hEvent;					// 动态检测联动 
};

/// 全通道动态检测配置
struct MotionDetectConfigAll
{
	MotionDetectConfig vMotionDetectAll[N_SYS_CH];
};

///< 遮挡检测配置
struct BlindDetectConfig
{
	bool	bEnable;		///< 遮挡检测开启
	int		iLevel;			///< 灵敏度：1～6
	EventHandler hEvent;	///< 遮挡检测联动参数
};

/// 全通道遮挡检测配置
struct BlindDetectConfigAll
{
	BlindDetectConfig vBlindDetectAll[N_SYS_CH];
};

///< 速度报警配置
struct SpeedAlarmConfig
{
	bool	bEnable;		///< 速度报警使能
	int		iSpeed;			///< 速度
	EventHandler hEvent;	///< 速度报警联动参数
};

/// 全部类型的速度报警配置
struct SpeedAlarmConfigAll
{
	SpeedAlarmConfig vSpeedAlarmAll[SPEED_ALARM_NR];
};


// GSensor报警配置
struct GSensorAlarmConfig
{
	bool	bEnable;		// GSensor报警使能
	int 	iXThreshold;	// X轴报警阈值，单位g，即一个重力加速度
	int 	iYThreshold;	// Y轴报警阈值，单位g，即一个重力加速度
	int		iZThreshold;	// Z轴报警阈值，单位g，即一个重力加速度
	EventHandler hEvent;	// GSensorAlarmConfig报警联动参数
};

struct	LossShowStrConfig
{
	char ShowStr[SHOW_STR_LEN];
};

struct LossShowStrConfigALL
{
	LossShowStrConfig vLossShowStrAll[N_SYS_CH];
};


///< 本地报警配置
struct AlarmConfig
{
	bool	bEnable;		///< 报警输入开关
	int		iSensorType;	///< 传感器类型常开 or 常闭
	EventHandler hEvent;	///< 报警联动
};

///< 所有通道的报警配置
struct AlarmConfigAll
{
	AlarmConfig vAlarmConfigAll[N_ALM_IN];
};

///< 本地报警输出配置
struct AlarmOutConfig
{
	int nAlarmOutType;		///< 报警输出类型: 配置,手动,关闭
	int nAlarmOutStatus;    ///< 报警状态: 0:打开 1;闭合
};

///< 所有通道的报警输出配置
struct AlarmOutConfigAll
{
	AlarmOutConfig vAlarmOutConfigAll[N_ALM_OUT];
};

//< 硬盘容量不足事件剩余容量类型
enum StorageLowSpaceType
{
	PERSENT = 0,
	MB,
	GB,
};

///< 硬盘容量不足事件结构
struct StorageLowSpaceConfig
{
	bool bEnable;
	int iLowerLimit;		///< 硬盘剩余容量下限, 百分数
	EventHandler hEvent;	///< 处理参数
	bool bRecordTimeEnable;
	int iRecordTime;		///<录像天数
	int iLowerLimitSpace;		///< 硬盘剩余容量MB或者GB为单位
	int EnableType;		///< 0为用百分比，1为用MB，见枚举StorageLowSpaceType
};

///<硬盘出错事件结构
struct StorageFailConfig
{
	bool 	bEnable;
	EventHandler hEvent;	///< 处理参数
	bool	bRebootEnable;		//系统重启全能:hutianhao
	int		bRebooted;			//是否出错重启过;0:未出错重启过;非0:出错重启过
};

// 串口协议
enum CommProtocol
{
	CONSOLE = 0,
	KEYBOARD,
	COM_TYPES,
};

enum PtzConfigType
{
	CONFIG_PTZ_LOCAL,
	CONFIG_PTZ_ALARM,
	CONFIG_PTZ_PRESETINFO,
	CONFIG_PTZ_TOURINFO,
};
#define PTZ_CHANNELS 8
#define	PTZ_PRESETNUM 80
#define MAX_PROTOCOL_LENGTH 32

struct COMMATTRI
{
	int	iDataBits;	// 数据位取值为5,6,7,8 
	int	iStopBits;	// 停止位
	int	iParity;	// 校验位
	int	iBaudRate;	// 实际波特率
};

// 串口配置
struct CONFIG_COMM_X
{
	char sProtocolName[MAX_PROTOCOL_LENGTH];	// 串口协议:“Console” 
	int iPortNo;		// 端口号 
	COMMATTRI aCommAttri;		// 串口属性 
};

struct CommConfigAll
{
	CONFIG_COMM_X vCommConfig[COM_TYPES];
};

// 云台设置
struct CONFIG_PTZ
{
	char sProtocolName[MAX_PROTOCOL_LENGTH];	// 协议名称 	
	int	ideviceNo;				// 云台设备地址编号 	
	int	iNumberInMatrixs;		// 在矩阵中的统一编号	
	int iPortNo;				// 串口端口号	[1, 4] 	
	COMMATTRI dstComm;			// 串口属性 	
};

struct PTZConfigAll
{
	CONFIG_PTZ ptzAll[N_SYS_CH];
};

struct RS485ConfigAll
{
	CONFIG_PTZ rs485All[N_SYS_CH];
};


//车辆状态
enum CAR_STATUS_TYPE
{
	CAR_WORKING,             //是否在运行
	CAR_LIGHT_LEFT_TURN,     //左转灯是否点亮
	CAR_LIGHT_RIGHT_TURN,    //右转灯是否点亮
	CAR_DOOR_LEFT_FRONT,     //左前门是否打开
	CAR_DOOR_RIGHT_FRONT,    //右前门是否打开
	CAR_DOOR_LEFT_BACK,      //左后门是否打开
	CAR_DOOR_RIGHT_BACK,     //右后门是否打开
	CAR_DOOR_BACK,           //后门是否打开
	CAR_BRAKE,			     //是否踩刹车
	CAR_URGENCY_ALARM,       //紧急报警
	CAR_STATUS_NR, //状态种类数目
};

//外部输入类型
enum IO_INPUT_TYPE
{
	LOCAL_ALARM_INPUT,//本地报警输入
	RS232_INPUT,      //通过232串口输入
	RS485_INPUT,      //通过485串口输入
};

//外部信息输入与车辆状态的对应关系
struct CarStatusExchange
{
	int  statusType; //哪一种车辆状态，比如左转灯
	bool bExist;     //是否有该种状态的信息输入，根据车辆的实际情况进行设置
	bool bEnable;    //是否检测该种状态
	int  inputType;  //该种状态对应的信息输入类型，从IO_INPUT_TYPE枚举的值中取
	int  addr;       //地址，比如是本地报警输入口一对应0，输入口二对应1
	int  sensorType; //常开(NO)或常闭(NC)，当inputType是本地报警输入时有效
};

struct CarStatusExchangeAll
{
	CarStatusExchange exchangeAll[16];
};

struct CarDelayTimeConfig
{
	bool bStartDelay;
	bool bCloseDelay;
	
	int timeStartDelay;		//单位:分钟
	int timeCloseDelay;		//单位:分钟
};

//GPS校时配置
struct GPSTimingConfig
{
	bool bEnable;      // 是否启用
	int  timeChange;   // 相对于UTC时间需要改变多少，单位:秒
	int  updatePeriod; // 更新周期  单位:分钟
};

enum CAR_BOOT_TYPE
{
	CAR_BOOT_TYPE_SPARK,  //点火熄火开关机
	CAR_BOOT_TYPE_TIMING, //定时开关机
	CAR_BOOT_TYPE_NR,
};

//点火开关机延时配置
struct CarSparkWork
{
	int bootDelayMinute;  //开机延时分钟数
	int shutDelayMinute;  //关机延时分钟数
	char resv[24];        //保留
};

//车载定时开关机配置
struct CarTimingWork
{
	TimeSection workSection1; //工作时间段1
	TimeSection workSection2; //工作时间段2

	char resv[32]; //保留
};

//车载DVR启动和关闭方式
struct CarBootTypeConfig
{
	int           bootType;         //如枚举 CAR_BOOT_TYPE 所述
	CarSparkWork  sparkWorkConfig;  //点火开关机配置
	CarTimingWork timingWorkConfig; //定时开关机时间段1
	char          resv[48];
};


//点间巡航
struct TourState
{
	bool bRunning;
	int  lineID;   //点间巡航线路编号
};

//巡迹
struct PatternState
{
	bool bRunning;
	int  lineID;  //巡迹线路编号 (未使用)
};

//线扫
struct ScanState
{
	bool bRunning;
	int  lineID;  //线扫线路编号 (未使用)
};

//水平旋转
struct PanonState
{
	bool bRunning;
	int  lineID;  //水平旋转线路编号 (未使用)
};

//开机转到指定预置点
struct PresetState
{
	bool bEnable;
	int  iPresetID;  
};

//断电前位置
struct PoweroffState
{
	bool bEnable;
	int  iPresetID;  
};

//一个通道的云台操作状态
struct PtzState
{
	TourState    tourState;
	PatternState patternState;
	ScanState    scanState;
	PanonState   panonState;
	PresetState  presetState;
	PoweroffState poweroffState;
};

//重启后恢复之前的云台操作状态
struct ResumePtzState
{
	bool     bEnable;                    //是否启用设备重启后恢复云台状态功能
	PtzState ptzStateAll[N_SYS_CH];
};

///< 所有数字通道的报警配置
struct IPCAlarmConfigAll
{
	AlarmConfig vAlarmConfigAll[N_DECORDR_CH];
};

// 空闲动作
struct PtzIdleState
{
	bool bEnable;			// 空闲动作使能位
	int iTime;				// 空闲时间 单位: 秒
	int iIdleState;			// 空闲动作类型  0为预置点，1为点间巡航，2为无动作
	int iId;				// 相应空闲动作类型的动作编号
};
struct PtzIdleStateAll
{
	PtzIdleState pPtzIdleStateAll[N_SYS_CH];
};
///<串口报警配置
struct SerialPortAlarmConfig
{
	AlarmConfig vAlarmConfigAll[N_SYS_CH];
};


//=====================智能分析精简版=======================
typedef int SIMPLE_IMP_S32;
typedef short SIMPLE_IMP_S16;

#define SIMPLE_IMP_MAX_POINT_NUM 4

//物品遗留-begin
#define SIMPLE_IMP_MAX_OSC_NUM 4

/** 最大边界点数 */
#define SIMPLE_IMP_MAX_BOUNDARY_POINT_NUM 8

/** URP单绊线最多条数 */
#define SIMPLE_IMP_URP_MAX_TRIPWIRE_CNT 8

/**坐标点*/
typedef struct SIMPLE_impURP_IMP_POINT_S
{
	SIMPLE_IMP_S16 s16X;					/**< x */
	SIMPLE_IMP_S16 s16Y;					/**< y */
}SIMPLE_URP_IMP_POINT_S;

//===================CPC算法精简版====================
typedef struct SIMPLE_tagCPC_RULE_S
{
	SIMPLE_URP_IMP_POINT_S stRulePoint[SIMPLE_IMP_MAX_POINT_NUM];	//检测规则，需要画满4个点
	int s32Sizemin;			///最小像距(0,height/2)
	int s32Sizemax;			///最大像距(sizemin, height/2)
	int s32Countmax;			///最大目标数[1~15],
	int s32Sensitivity;			/// 灵敏度档位1-5,数值越大越容易报警	
	unsigned int u32Flag;		///标志位，用来判别进出，默认设0
	int s32EnterDirection;		///进入的方向
}SIMPLE_CPC_RULE_S;

typedef struct  SIMPLE_CONFIG_CPC_RULE_ALL
{
	SIMPLE_CPC_RULE_S channel[N_SYS_CH];
}SIMPLE_CONFIG_CPC_RULE_ALL;

//===================AVD算法精简版====================
typedef struct SIMPLE_tagAVD_RULE_S
{
	int iLevel;					///灵敏度档位
	int itBrightAbnmlEnable;		///亮度异常使能
	int iClarityEnable;			///清晰度检测使能
	int iNoiseEnable;			///噪声检测使能
	int iColorEnable;			///偏色检测使能
	int iFreezeEnable;			///画面冻结检测使能
	int iNosignalEnable;		///信号缺失检测使能
	int iChangeEnable;			///场景变换检测使能
	int iInterfereEnable;		///人为干扰检测使能
	int iPtzLoseCtlEnable;		///PTZ失控检测使能
}SIMPLE_AVD_RULE_S;

typedef struct  SIMPLE_CONFIG_AVD_RULE_ALL
{
	SIMPLE_AVD_RULE_S channel[N_SYS_CH];
}SIMPLE_CONFIG_AVD_RULE_ALL;

//===================OSC算法精简版====================
typedef struct SIMPLE_impURP_OSC_SPECL_REGIONS_S
{
	SIMPLE_IMP_S32 s32Valid; 							//是否有效
	SIMPLE_IMP_S32 s32PointNum;
	SIMPLE_URP_IMP_POINT_S astPoint[SIMPLE_IMP_MAX_BOUNDARY_POINT_NUM];
}SIMPLE_URP_OSC_SPECL_REGIONS_S;

typedef struct SIMPLE_impURP_OSC_RULE_PARA_S
{
	SIMPLE_IMP_S32 s32TimeMin;		//时间约束
	SIMPLE_IMP_S32 s32SizeMin;		//最小尺寸
	SIMPLE_IMP_S32 s32SizeMax; 		//最大尺寸
	SIMPLE_URP_OSC_SPECL_REGIONS_S astSpclRgs[SIMPLE_IMP_MAX_OSC_NUM]; //要处理的区域个数
}SIMPLE_URP_OSC_RULE_PARA_S;

typedef struct SIMPLE_tagOCS_RULE_S
{
	int iShowTrack;				//是否显示轨迹
	int iLevel;						//警戒级别:低级(2), 中级(1), 高级(0)
	int iAbandumEnable;		   	//物品遗留使能
	SIMPLE_URP_OSC_RULE_PARA_S stObjAbandumRulePara; //物品遗留参数
	int iStolenEnable;			  	 //物品被盗使能
	SIMPLE_URP_OSC_RULE_PARA_S stObjStolenRulePara;   //物品被盗参数
	int iNoParkingEnable;		 	 //非法停车使能
	SIMPLE_URP_OSC_RULE_PARA_S stNoParkingRulePara;   //非法停车参数
}SIMPLE_OSC_RULE_S;

typedef struct  SIMPLE_CONFIG_OSC_RULE_ALL
{
	SIMPLE_OSC_RULE_S channel[N_SYS_CH];
}SIMPLE_CONFIG_OSC_RULE_ALL;

//===================PEA算法精简版====================
/** URP单绊线结构*/
typedef struct SIMPLE_impURP_TRIPWIRE_S
{
	SIMPLE_IMP_S32     s32Valid;					//是否有效
	SIMPLE_IMP_S32     s32IsDoubleDirection;		//表示该绊线是否为双向绊线（0：否；1：是）
	SIMPLE_URP_IMP_POINT_S stStartPt;		//线段起点
	SIMPLE_URP_IMP_POINT_S stEndPt;		//线段终点
}SIMPLE_URP_TRIPWIRE_S;

/** URP周界检测规则参数 */
typedef struct SIMPLE_impURP_PERIMETER_RULE_PARA_S
{
	SIMPLE_IMP_S32  s32Mode;				//周界模式
	SIMPLE_IMP_S32  s32MinDist;				//最小像素距离
	SIMPLE_IMP_S32  s32BoundaryPtNum;		//边界点数目
	//边界点集合
	SIMPLE_URP_IMP_POINT_S  astBoundaryPts[SIMPLE_IMP_MAX_BOUNDARY_POINT_NUM];			
}SIMPLE_URP_PERIMETER_RULE_PARA_S;


/** URP单绊线规则参数*/
typedef struct SIMPLE_impURP_TRIPWIRE_RULE_PARA_S
{
	SIMPLE_IMP_S32  s32MinDist;				//最小像素距离
	SIMPLE_URP_TRIPWIRE_S astLines[SIMPLE_IMP_URP_MAX_TRIPWIRE_CNT]; //8条单绊线
}SIMPLE_URP_TRIPWIRE_RULE_PARA_S;

typedef struct SIMPLE_tagPEA_RULE_S
{
	int iShowTrack;						/// 是否显示轨迹
	int iLevel;						   	/// 警戒级别:低级(2), 中级(1), 高级(0)
	int iPerimeterEnable;				/// 周界规则使能
	SIMPLE_URP_PERIMETER_RULE_PARA_S	stPerimeterRulePara;	//周界检测
	int iTripWireEnable;					///单绊线规则使能
	SIMPLE_URP_TRIPWIRE_RULE_PARA_S	stTripwireRulePara;		//单绊线检测
}SIMPLE_PEA_RULE_S;

typedef struct  SIMPLE_CONFIG_PEA_RULE_ALL
{
	SIMPLE_PEA_RULE_S channel[N_SYS_CH];
}SIMPLE_CONFIG_PEA_RULE_ALL;

//==================智能分析中通用配置====================
typedef struct SIMPLE_AnalyzePub
{
	bool bEnable;			//智能分析是否使能
	int moduleType;			//当前选择的算法模块
}SIMPLE_AnalyzePub;

typedef struct  SIMPLE_AnalyzePub_ALL
{
	SIMPLE_AnalyzePub channel[N_SYS_CH];
}SIMPLE_AnalyzePub_ALL;

#endif
