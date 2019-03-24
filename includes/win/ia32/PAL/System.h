//
//  "$Id: System.h 5911 2013-01-10 07:25:45Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_SYSTEMM_H__
#define __PAL_SYSTEMM_H__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif


/// 系统特性结构
typedef struct SYSTEM_CAPS
{
	/// 总共内存大小，以Kilo-Bytes为单位。
	unsigned int MemoryTotal;

	/// 剩余内存大小，以Kilo-Bytes为单位。将关系到应用程序的内存使用策略。
	unsigned int MemoryLeft;
}SYSTEM_CAPS;

enum CPU_TYPE
{
	TYPE_HI3511 = 1,
	TYPE_HI3512,
	TYPE_HI3520,
	TYPE_HI3515,
	TYPE_HI3531,
	TYPE_HI3520a,
	TYPE_HI3521,
};

enum DVR_BOARD_MODEL
{
	//3521 20A 31
	MBD65xxE_H = 0,
	MBD65xxE_E = 1,
	// 3520a 21
	MBD65XXT_E = 2,
	MBD65XXA_E = 3,
	MBD65XXA_EX = 4,
	MBD65XXT_LS = 5,//朗视的客户5*4按键
	//21 31 20A
	MBD6016V_E = 6,  //液晶一体机
	//3520A    高清解码器(1 2 3 4 块)
	DVB6504E_P_1 = 7,
	DVB6504E_P_2 = 8,
	DVB6504E_P_3 = 9,
	DVB6504E_P_4 = 10,
};


typedef struct tagSYSTEM_CAPS_EX
{
	unsigned int ForNRT;			//是否为非实时, 按位表示各个通道是否设为非实时.如0xffff表示前16路都是非实时.
	unsigned char ForATM;			//是否为ATM机, 1表示不带液晶ATM,2表示带液晶ATM
	unsigned char HasAudioBoard;	 //带音频板
	unsigned char HasLoopBoard;		//带环通板
	unsigned char HasMatrixBoard;	//带矩阵板
	unsigned char HasPtzBoard;      //带云台板
	unsigned char HasWlanBoard;     //带无线板 
	unsigned char BoardModel;	//主板类型
	unsigned char CpuType;
	//unsigned char reserved[2];	//之前是保留位，加上主板类型和cpu类型之后，不需要了
}SYSTEM_CAPS_EX;

enum SYSTEM_FRONT_SWITCH_TYPE{
	NO_SUPPORT_SYSTEM_FRONT_SWITCH = 0, 	//0-不支持SWITCH
	SYSTEM_FRONT_SWITCH_T,					//支持目前的6000 18K和10 GPIO
	SYSTEM_FRONT_SWITCH_BUF,
};

typedef struct tagSYSTEM_FUNC_EX
{
	unsigned char HasNatFunc;		//是否支持NAT 功能,1支持，0不支持
	unsigned char HasPIPFunc;		//是否支持PIP 功能,1支持，0不支持
	unsigned char HasSpotFunc;	//是否支持SPOT 功能,1支持，0不支持
	unsigned char HasIntelFunc;	//是否支持智能 功能,1支持，0不支持
	unsigned char HasHVRFunc;	//是否支持HVR 功能,1支持，0不支持
	unsigned char HasCPCFunc;	//是否支持智能CPC 功能,1支持，0不支持
	unsigned char reserved[2];
	unsigned int FrontSwithType;	//前面板支持类型
	unsigned int reserved1[5];
}SYSTEM_FUNC_EX;


/// 系统升级状态
enum system_upgrade_state
{
	SYSTEM_UPGRADE_OVER = 0,
	SYSTEM_UPGRADE_INIT = 1,
	SYSTEM_UPGRADE_RUNNING = 2
};

enum PRODUCT_TYPE
{
	PRODUCT_DVR,
	PRODUCT_HVR,
	PRODUCT_IPC,
	PRODUCT_MVR,
	PRODUCT_IVR,
};

enum MAIN_SERIES_TYPE
{
	SERIES_3000,
	SERIES_5000,
	SERIES_5500,
	SERIES_6000,
};

enum MINOR_SERIES_TYPE
{
	SERIES_T,
	SERIES_A,
	SERIES_B,
	SERIES_E,
	SERIES_D,
	SERIES_H,
	SERIES_EH,
};

typedef struct tagSYSTEM_PRODUCT_INFO
{
	unsigned int	dwMainHWType;      // 硬件主版本号
	unsigned int	dwMinorHWType;     // 硬件次版本号
	unsigned int	dwProductType;     // 产品线类别，见PRODUCT_TYPE
	unsigned int	dwMainSeriesType;  // 主类别， 见MAIN_SERIES_TYPE
	unsigned int	dwMinorSeriesType;  // 子类别，见MINOR_SERIES_TYPE
	unsigned int	dwOEMType;         // OEM类型
	unsigned int	dwReserved[4];   
}SYSTEM_PRODUCT_INFO;

/// 得到系统特性。
/// 
/// \param [out] pCaps 指向系统特性结构SYSTEM_CAPS的指针。
/// \retval 0  获取成功。
/// \retval <0  获取失败。
int SystemGetCaps(SYSTEM_CAPS * pCaps);



/// 得到系统扩展特性
/// \param [out] pCaps 指向系统扩展特性结构SYSTEM_CAPS_EX的指针
/// \retval 0 获取成功
/// \retval < 0 获取失败
int SystemGetCapsEx(SYSTEM_CAPS_EX * pCaps);


/// 让系统蜂鸣器发出单音调的声音，是同步模式，时间到才返回。
/// 
/// \param [in] dwFrequence 音调频率。
/// \param [in] dwDuration 持续的时间。
void SystemBeep(unsigned int dwFrequence, unsigned int dwDuration );


/// 系统复位。
void SystemReboot(void);


/// 系统关闭。
void SystemShutdown(void);


/// 退出正在运行的应用程序。
void ApplicationExit(void);

/// 创建加密芯片设备
/// \return 0 创建成功
/// \return < 0 创建失败
int CryptoCreate(void);

/// 销毁加密芯片设备
/// \return 0 销毁成功
/// \return < 0 销毁失败
int CryptoDestory(void);

/// 写加密芯片,共128个字节，每32个字节一个区域
/// \param [in] zone 指示要访问的加密芯片区域(0 ... 3)
/// \param [in] wdata 要写的加密芯片数据信息
/// \param [in] len 缓冲长度
/// \return 读到的字节数
int CryptoWrite(int zone, const unsigned char *wdata, int len);

/// 读加密芯片，共128个字节，每32个字节一个区域
/// \param [in] zone 指示要访问的加密芯片区域(0 ... 3)
/// \param [out] wdata 存放读到的加密芯片数据
/// \param [in] len 缓冲长度
/// \return 读到的字节数
int CryptoRead(int zone, unsigned char *rdata, int len);

/// 
int CryptoFuse(void);

/// 
int CryptoCheck(void);

int SysteSyncTime(SYSTEM_TIME *ptime);

/// 读设备信息
/// \param [out] 产品信息
/// \return 0: succ
int SystemGetProductInfo(SYSTEM_PRODUCT_INFO *pInfo);

int SystemGetExFunction(SYSTEM_FUNC_EX *pExFunc);

//液晶一体机待机功能调用的接口
int VGAShutDown();
int VGABoot();

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif
