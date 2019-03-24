#ifndef _FS_PARAM_H_
#define _FS_PARAM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef PACKED
#define PACKED		__attribute__((packed, aligned(1)))
#define PACKED4		__attribute__((packed, aligned(4)))
#endif

#define DETECT_AREA_NUM	4							//侦测路数

#define  MAX_ROI_AREA 4
#define  MAX_OVERSTRP_AREA 4


//---------------------------------------------
//智能编码：
typedef struct _AUTOCODEC_CONFIG_S
{
	BYTE bySensitive; // 0  low  1 mid  2 high
	BYTE bySaveCurBitrate;
	BYTE byLowBitrate;
	BYTE byStopTime;
	BYTE byRes[256];
}AUTOCODEC_CONFIG;

typedef struct _AREA_RECT_S
{
	short			x;									//X坐标
	short			y;									//Y坐标
	short			w;									//宽度
	short			h;									//高度
}AREA_RECT_S;

typedef struct _ROI_CONFIG_S
{
	AREA_RECT_S stROIRect; //Roi   area  rect
	INT s32Qp;
	INT dwIndex;
	BYTE byEnable;
	BYTE byAbsQp;
	BYTE byRes[14];
}ROT_CONFIG;

typedef struct _SMART_CODEC_CONFIG_S
{
	ROT_CONFIG  stROI[MAX_ROI_AREA];   // 
	AUTOCODEC_CONFIG stAutoCodec;
	BYTE     	 byCodecEnable;  // 0  close,  1  Enable auto update all stream (auto check) ,  2  ROI  (set Rect)
	BYTE 		 byRes1[3];
	BYTE		 byRes[256];	
}SMART_CODEC_CONFIG;
/*
{
	"Name" : "SmartDetection.Codec",
	"SmartDetection.Codec":
	{
		"Enable": 0,
		"AutoCodec":
		{
			"Sensitivity" : 0,
			"SaveCurBitrate": 0,
			"LowBitrate": 0,
			"StopTime": 0,
		}
		"ROI"://size 8
		[
			{
				"Enable": 0,
				"ROIRect":{"x": 0,"y": 0,"w": 0,"h": 0}
				"32Qp": 0,
				"Index": 0,
				"AbsQp": 0,	
			},
			......//共8个
		]
	}
	"SessionID" : "0x" 
}
*/

//智能检测：
typedef struct _SMART_DETECT_CONFIG_S
{
	SMART_SHUNTTER stSmartShuntter;
	SMART_OVERSTEP stSmartOverStep;	
	SMART_FOCUS	   stSmartFocus;
	BYTE		   byRes[256];
} SMART_DETECT_CONFIG;

typedef struct _SMART_SHUNTTER_S
{
	BYTE         byshutterEnable;  // 0 close  1 Enable
	BYTE 		 bySensitive;
	BYTE 		 byShowOsd;
	BYTE 		 bySynMotion; //Synchronous motion detecting alarm
	char 		 szOsd[32];
	BYTE		 byRes[256];	
} SMART_SHUNTTER;

typedef struct _SMART_OVERSTEP_S
{
	BYTE         byOverStepEnable;  // 0 close  1 Enable
	BYTE 		 bySensitive;
	BYTE 		 byShowOsd;
	BYTE 		 bySynMotion; //Synchronous motion detecting alarm
	AREA_RECT_S  stOverStepRect[MAX_OVERSTRP_AREA];
	char 		 szOsd[32];
	BYTE		 byRes[256];	
} SMART_OVERSTEP;


typedef struct _SMART_FOCUS_S
{
	BYTE         byAfFocusEnable;  // 0 close  1 Enable
	BYTE 		 bySensitive;
	BYTE 		 byShowOsd;
	BYTE 		 bySynMotion; //Synchronous motion detecting alarm
	DWORD		 dwCurAfVaule;
	DWORD		 dwCurLumaVaule;
	char 		 szOsd[32];
	BYTE		 byAfFocusStudy; // Af Focus Study Again
	BYTE 		 byStudyPresetNum; //Af  Focus Study Preset Num
	BYTE		 byRes1[2];
	BYTE		 byRes[252];	
}SMART_FOCUS;

//区域
typedef struct _AREA_RECT_S
{
	short			x;									//X坐标
	short			y;									//Y坐标
	short			w;									//宽度
	short			h;									//高度
}AREA_RECT_S;
/*
{
	"Name" : "SmartDetection.Detect",
	"SmartDetection.Detect":
	{
		"SmartShuntter":
		{
			"Enable": 0,
			"Sensitivity": 0,
			"ShowOsd": 0,
			"Alarm": 0
			"Osd":" ",
		}
		"SmartFocus":
		{
			"Enable": 0,
			"Sensitivity": 0,
			"ShowOsd": 0,
			"Alarm": 0
			"Osd":" ",
			"CurAfValue": 0,
			"CurLumaValue": 0,
			"AfFoucusStudy": 0,
			"StudyPresetNum": 0,
		}
	}
	"SessionID" : "0x" 
}
*/
//智能控制：
typedef struct _SMART_CONTROL_CONFIG_S
{
	BYTE		 bySmartCtlEnable;
	BYTE		 bySmartOpenAlarm;
	BYTE		 bySmartCloseAlarm;
	BYTE		 bySmartCleanHappern;
	BYTE 		 bySmartCleanFlag;
	BYTE		 byRes1[3];
	BYTE		 byRes[512];
} SMART_CONTROL_CONFIG;

/*
{
	"Name" : "SmartDetection.Control",
	"SmartDetection.Control":
	{
		"Enable": 0,
		"OpenAlarm": 0,
		"CloseAlarm": 0,
		"CleanHappen": 0
	}
	"SessionID" : "0x" 
}
*/



//----------------------------------------------
//区域
typedef struct _AREA_RECT_S
{
	int			x;									//X坐标
	int			y;									//Y坐标
	int			w;									//宽度
	int			h;									//高度
}PACKED AREA_RECT_S;

//区域入侵
typedef struct _CROSS_RECT_S
{
	int			x0;									//X0坐标
	int			y0;									//Y0坐标
	int			x1;									//X1坐标
	int			y1;									//Y1坐标
	int			x2;									//X2坐标
	int			y2;									//Y2坐标
	int			x3;									//X3坐标
	int			y3;									//Y3坐标
}CROSS_RECT_S;

//线
typedef struct _LINE_POINT_S
{
	int			x0;									//x0坐标
	int			y0;									//y0坐标
	int			x1;									//x1宽度
	int			y1;									//y1高度
}LINE_POINT_S;

//=============================================================================

/*
{
	"Name" : "SmartDetection.LumaDetect",
	"SmartDetection.LumaDetect":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
	}
	"SessionID" : "0x" 
}
*/
//亮度侦测数据结构
typedef struct SM_LUMADETECT_S						//size 512
{
	int	bEnable;									//使能
	int sensitivity;								//阀值  默认值  160    范围：0～255
	char res[504];
}SM_LUMADETECT;

/*
{
	"Name" : "SmartDetection.MotionDetect",
	"SmartDetection.MotionDetect":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
		"MDArea" :
		[
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
		]
	}
	"SessionID" : "0x0" 
}
*/
//移动侦测数据结构
typedef struct SM_MDDETECT_S						//size 512
{
	int	bEnable;									//使能
	int sensitivity;								//阀值
	AREA_RECT_S	stMDArea[DETECT_AREA_NUM];			//移动侦测区域
	char res[440];
}SM_MDDETECT;


/*
{
	"Name" : "SmartDetection.OdDetect",
	"SmartDetection.OdDetect":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
		"ODArea" :
		[
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
		]
	}
	"SessionID" : "0x0" 
}
*/
//遮挡侦测数据结构
typedef struct SM_ODDETECT_S						// 512
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int sensitivity;								//阀值  默认值  20      范围：0～255
	AREA_RECT_S	stMDArea[DETECT_AREA_NUM];			//遮挡区域
	char res[432];
}SM_ODDETECT;

/*
{
	"Name" : "SmartDetection.CrossLine",
	"SmartDetection.CrossLine":
	{
		"Enable" : 0,			//使能
		"Direction": [0, 0, 0, 0],
		"Line" :
		[
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0};
		]
	}
	"SessionID" : "0x0" 
}
*/
//虚拟警戒线数据结构
typedef struct SM_CROSSLINE_S						//512
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int direction[DETECT_AREA_NUM];					//侦测方向   0:左->右或者上->下  1:右->左 或者下->上  2:左<->右或者上<->下   默认值:0
	LINE_POINT_S	stCrossLine[DETECT_AREA_NUM];  	//侦测虚拟线
	char res[420];
}SM_CROSSLINE;


/*
{
	"Name" : "SmartDetection.CrossArea",
	"SmartDetection.CrossArea":
	{
		"Enable" : 0,			//使能	
		"Direction": [0, 0, 0, 0],
		"Area" :
		[
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0, "x2" :0 , "y2" : 0, "x3" : 0, "y3" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0, "x2" :0 , "y2" : 0, "x3" : 0, "y3" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0, "x2" :0 , "y2" : 0, "x3" : 0, "y3" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0, "x2" :0 , "y2" : 0, "x3" : 0, "y3" : 0};
		]
	}
	"SessionID" : "0x0" 
}
*/
//区域入侵侦测数据结构
typedef struct SM_CROSSAREA_S						//512
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int direction[DETECT_AREA_NUM];					//侦测方向  0:外->内   1:内->外    默认：0
	CROSS_RECT_S stCrossArea[DETECT_AREA_NUM];  	//区域
	char  res[356];
}SM_CROSSAREA;

/*
{
	"Name" : "SmartDetection.DetectColor",
	"SmartDetection.DetectColor":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
	}
	"SessionID" : "0x0" 
}
*/
//颜色侦测
typedef struct SM_DETECTCOLOR_S						//
{
	int	bEnable;									//使能
	int sensitivity;								//阀值   默认值  1200  范围：0～2000
	char res[504];
}SM_DETECTCOLOR;

/*
{
	"Name" : "SmartDetection.DetectSound",
	"SmartDetection.DetectSound":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
	}
	"SessionID" : "0x0" 
}
*/
//声音侦测
typedef struct SM_DETECTSOUND_S
{
	int	bEnable;									//使能
	int aType;	
	int sensitivity;								//阀值  默认值  20      范围：0～255
	char res[500];
}SM_DETECTSOUND;

/*
{
	"Name" : "SmartDetection.LoseObj",
	"SmartDetection.LoseObj":
	{
		"Enable" : 0,			//使能
		"Direction": [0, 0, 0, 0],
		"Area" :
		[
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
		]
		"time" : 0
	}
	"SessionID" : "0x0" 
}
*/
//遗留物体侦测数据结构
typedef struct SM_LOSEOBJ_S
{
	int	bEnable;									//使能
	float nRateX;									//X坐标比例
	float nRateY;									//Y坐标比例
	int direction[DETECT_AREA_NUM];					//侦测方向    0:遗留  1:取走  默认：0
	AREA_RECT_S stLoseobjArea[DETECT_AREA_NUM];  	//遗留物体侦测区域
	int time;											//遗留时间     默认值 5秒
	char res[416];
}SM_LOSEOBJ;

/*
{
	"Name" : "SmartDetection.SmartAnalysis",
	"LumaDetect":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
	}
	"MotionDetect":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
		"MDArea" :
		[
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
		]
	}
	"OdDetect":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
		"ODArea" :
		[
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
		]
	}
	"CrossLine":
	{
		"Enable" : 0,			//使能	
		"Direction": [0, 0, 0, 0],
		"Line" :
		[
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0};
		]
	}
	"CrossArea":
	{
		"Enable" : 0,			//使能
		"Direction": [0, 0, 0, 0],
		"Line" :
		[
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0, "x2" :0 , "y2" : 0, "x3" : 0, "y3" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0, "x2" :0 , "y2" : 0, "x3" : 0, "y3" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0, "x2" :0 , "y2" : 0, "x3" : 0, "y3" : 0};
			{"x0" : 0, "y0" : 0, "x1" : 0, "y1" : 0, "x2" :0 , "y2" : 0, "x3" : 0, "y3" : 0};
		]
	}
	"DetectColor":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
	}
	"DetectSound":
	{
		"Enable" : 0,			//使能
		"Sensitivity" : 1600	//阀值
	}
	"LoseObj":
	{
		"Enable" : 0,			//使能	
		"Direction": [0, 0, 0, 0],
		"Area" :
		[
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
			{"x" : 0, "y" : 0, "w" : 0, "h" : 0};
		]
	}
	"SessionID" : "0x0" 
}
*/

typedef struct _SMART_ANALYSIS_S
{
	SM_LUMADETECT 	sm_lumadetect;					//亮度侦测
	SM_MDDETECT     sm_mddetect;  					//移动侦测
	SM_ODDETECT     sm_oddetect;  					//遮挡检测
	SM_CROSSLINE	sm_crossline;					//虚拟警戒线
	SM_CROSSAREA    sm_crossarea;					//区域入侵
	SM_DETECTCOLOR  sm_detectcolor;					//颜色侦测
	SM_DETECTSOUND  sm_detectsound;					//声音侦测
	SM_LOSEOBJ		sm_loseobj;						//遗留物体侦测
	char 			res[4096];						//保留
}SMART_ANALYSIS_S;

SMART_ANALYSIS_S SysSmartConfig;


int FS_Init_SmartParam(void);
int FS_Get_SmartParam(int CMD,void  *pSmart);

#endif

