#ifndef _EXCHANGEAL_CAMERAEXCHANGE_H
#define _EXCHANGEAL_CAMERAEXCHANGE_H

#include "Types/Defs.h"
#include "Types/Types.h"


typedef enum CAMERA_SCENE //白平衡
{
	SCENE_AUTO,
	SCENE_INDOOR, //室内
	SCENE_OUTDOOR //室外
}CAMERA_SCENE;

typedef enum DNC_MODE //日夜模式取值
{
	DNC_AUTO,			// 自动切换
	DNC_MULTICOLOR,		// 彩色
	DNC_BLACKWHITE,		// 强制为黑白模式
	DNC_NR
}DNC_MODE;

typedef enum APERTURE_MODE //自动光圈模式
{
	APERTURE_AUTO_ON,
	APERTURE_AUTO_OFF,
}APERTURE_MODE;

typedef enum BLC_MODE //背光补偿模式
{
	BLC_AUTO,
	BLC_ON,
	BLC_OFF
}BLC_MODE;





//曝光配置
struct ExposureParam
{
	int  level;    //曝光等级
	uint leastTime;//自动曝光时间下限或手动曝光时间，单位微秒
	uint mostTime; //自动曝光时间上限，单位微秒
	int levelTime;//曝光时间 单位微妙   //by zjh 20170802
};


//增益配置
struct GainParam
{
	int gain;    //自动增益上限(自动增益启用)或固定增益值
	int autoGain;//自动增益是否启用，0:不开启  1:开启
};
//海思IPC图像风格，不同风格之间画面饱和度之类参数不同，具体由底层控制
enum IMG_TYPE
{
	IMG_TYPE_DEFAULT,
	IMG_TYPE_1,
	IMG_TYPE_2,
	IMG_TYPE_NR,
};
//网络摄像头扩展参数
struct CameraParamEx
{
	GainParam broadTrends;	//宽动态
	int style;	//enum IMG_TYPE
	uint exposureTime;//实际生效的曝光时间
	int res[62];	//冗余
};

//网络摄像头参数
struct CameraParam
{
	uint whiteBalance;		//白平衡
	uint dayNightColor;		//日夜模式，取值有彩色、自动切换和黑白
	int  elecLevel;		//参考电平值
	uint apertureMode;		 //自动光圈模式
	uint BLCMode;		//背光补偿模式
	ExposureParam exposureParam;//曝光配置
	GainParam gainParam;	//增益配置
	uint PictureFlip;		//图片上下翻转
	uint PictureMirror;		//图片左右翻转
	uint RejectFlicker;		//日光灯防闪功能
	uint EsShutter;		//电子慢快门功能
	int ircut_mode;		//IR-CUT切换 0 = 红外灯同步切换 1 = 自动切换
	int dnc_thr;		//日夜转换阈值
	int ae_sensitivity;	//ae灵敏度配置
	int Day_nfLevel;		//noise filter 等级，0-5,0不滤波，1-5 值越大滤波效果越明显
	int Night_nfLevel;
	int Ircut_swap;		//ircut 正常序= 0        反序= 1
	int BLCValue;       //背光补偿值   //by zjh 20170802
};


//多个摄像头的参数
struct CameraParamAll
{
	CameraParam vCameraParamAll[N_SYS_CH];
};

// 摄像头所有扩展参数
struct CameraParamExAll
{
	CameraParamEx vCameraParamExAll[N_SYS_CH];
};

//摄像头能力集
struct CameraAbility
{
	int  count;      //支持曝光速度数量
	uint speeds[16]; //曝光速度
	int  status;     //工作状态  >= 0 正常    < 0 异常
	int  elecLevel;  //参考电平值
	int  luminance;  //平均亮度
	char pVersion[64];//xm 2a版本
	char reserve[32];//保留
};
struct CameraClearFog
{
	bool enable; //0 打开，1 不打开
	int  level ; // 强度等级[0,100] 
	char rev[4];
};
struct CameraClearFogAll
{
	CameraClearFog vCameraClearFogAll[N_SYS_CH];
};

//机器人马达控制
struct CameraMotorCtrl
{
	bool UDDireOverturn;   //上下方向翻转
	bool LRDireOverturn;   //左右方向翻转
	bool UDRestOverturn;   //上下限位翻转
	bool LRRestOverturn;   //左右限位翻转
	int  rev[8];
};


//  -----  下面是鱼眼功能相关结构体  --------------------
//安装位置
typedef enum{
	FISHEYE_APP_CEIL = 0, //天花板
	FISHEYE_APP_TABL = 1, //桌上
	FISHEYE_APP_WALL = 2, //墙上
}FISHEYE_APP_TYPE_E;

//鱼眼模式
typedef enum{
	FISHEYE_SECENE_ORIG	= 0,
	FISHEYE_SECENE_R = 1,
	FISHEYE_SECENE_P180_ALL = 2,
	FISHEYE_SECENE_P180_ONE = 3,
	FISHEYE_SECENE_P180_TWO = 4,
	FISHEYE_SECENE_P360_FULL = 5,
	FISHEYE_SECENE_P360_SEPE = 6,
	FISHEYE_SECENE_P360_HALF = 7,
	FISHEYE_SECENE_ROP_R = 8,
	FISHEYE_SECENE_RORR_R = 9,
	FISHEYE_SECENE_RRRR_R = 10,
	FISHEYE_SECENE_RRP_R = 11
}FISHEYE_SECENE_E;


struct FishEyeParam
{
	int appType;	//如枚举FISHEYE_APP_TYPE_E
	int secene;		//如枚举FISHEYE_SECENE_E
	unsigned int reserv[8];
};

#endif // _EXCHANGEAL_CAMERAEXCHANGE_H
