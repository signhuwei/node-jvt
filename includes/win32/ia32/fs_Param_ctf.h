#ifndef _FS_PARAM_H_
#define _FS_PARAM_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifndef PACKED
#define PACKED		__attribute__((packed, aligned(1)))
#define PACKED4		__attribute__((packed, aligned(4)))
#endif

#define DETECT_AREA_NUM	4							//���·��

#define  MAX_ROI_AREA 4
#define  MAX_OVERSTRP_AREA 4


//---------------------------------------------
//���ܱ��룺
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
	short			x;									//X����
	short			y;									//Y����
	short			w;									//���
	short			h;									//�߶�
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
			......//��8��
		]
	}
	"SessionID" : "0x" 
}
*/

//���ܼ�⣺
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

//����
typedef struct _AREA_RECT_S
{
	short			x;									//X����
	short			y;									//Y����
	short			w;									//���
	short			h;									//�߶�
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
//���ܿ��ƣ�
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
//����
typedef struct _AREA_RECT_S
{
	int			x;									//X����
	int			y;									//Y����
	int			w;									//���
	int			h;									//�߶�
}PACKED AREA_RECT_S;

//��������
typedef struct _CROSS_RECT_S
{
	int			x0;									//X0����
	int			y0;									//Y0����
	int			x1;									//X1����
	int			y1;									//Y1����
	int			x2;									//X2����
	int			y2;									//Y2����
	int			x3;									//X3����
	int			y3;									//Y3����
}CROSS_RECT_S;

//��
typedef struct _LINE_POINT_S
{
	int			x0;									//x0����
	int			y0;									//y0����
	int			x1;									//x1���
	int			y1;									//y1�߶�
}LINE_POINT_S;

//=============================================================================

/*
{
	"Name" : "SmartDetection.LumaDetect",
	"SmartDetection.LumaDetect":
	{
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
	}
	"SessionID" : "0x" 
}
*/
//����������ݽṹ
typedef struct SM_LUMADETECT_S						//size 512
{
	int	bEnable;									//ʹ��
	int sensitivity;								//��ֵ  Ĭ��ֵ  160    ��Χ��0��255
	char res[504];
}SM_LUMADETECT;

/*
{
	"Name" : "SmartDetection.MotionDetect",
	"SmartDetection.MotionDetect":
	{
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
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
//�ƶ�������ݽṹ
typedef struct SM_MDDETECT_S						//size 512
{
	int	bEnable;									//ʹ��
	int sensitivity;								//��ֵ
	AREA_RECT_S	stMDArea[DETECT_AREA_NUM];			//�ƶ��������
	char res[440];
}SM_MDDETECT;


/*
{
	"Name" : "SmartDetection.OdDetect",
	"SmartDetection.OdDetect":
	{
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
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
//�ڵ�������ݽṹ
typedef struct SM_ODDETECT_S						// 512
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int sensitivity;								//��ֵ  Ĭ��ֵ  20      ��Χ��0��255
	AREA_RECT_S	stMDArea[DETECT_AREA_NUM];			//�ڵ�����
	char res[432];
}SM_ODDETECT;

/*
{
	"Name" : "SmartDetection.CrossLine",
	"SmartDetection.CrossLine":
	{
		"Enable" : 0,			//ʹ��
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
//���⾯�������ݽṹ
typedef struct SM_CROSSLINE_S						//512
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int direction[DETECT_AREA_NUM];					//��ⷽ��   0:��->�һ�����->��  1:��->�� ������->��  2:��<->�һ�����<->��   Ĭ��ֵ:0
	LINE_POINT_S	stCrossLine[DETECT_AREA_NUM];  	//���������
	char res[420];
}SM_CROSSLINE;


/*
{
	"Name" : "SmartDetection.CrossArea",
	"SmartDetection.CrossArea":
	{
		"Enable" : 0,			//ʹ��	
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
//��������������ݽṹ
typedef struct SM_CROSSAREA_S						//512
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int direction[DETECT_AREA_NUM];					//��ⷽ��  0:��->��   1:��->��    Ĭ�ϣ�0
	CROSS_RECT_S stCrossArea[DETECT_AREA_NUM];  	//����
	char  res[356];
}SM_CROSSAREA;

/*
{
	"Name" : "SmartDetection.DetectColor",
	"SmartDetection.DetectColor":
	{
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
	}
	"SessionID" : "0x0" 
}
*/
//��ɫ���
typedef struct SM_DETECTCOLOR_S						//
{
	int	bEnable;									//ʹ��
	int sensitivity;								//��ֵ   Ĭ��ֵ  1200  ��Χ��0��2000
	char res[504];
}SM_DETECTCOLOR;

/*
{
	"Name" : "SmartDetection.DetectSound",
	"SmartDetection.DetectSound":
	{
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
	}
	"SessionID" : "0x0" 
}
*/
//�������
typedef struct SM_DETECTSOUND_S
{
	int	bEnable;									//ʹ��
	int aType;	
	int sensitivity;								//��ֵ  Ĭ��ֵ  20      ��Χ��0��255
	char res[500];
}SM_DETECTSOUND;

/*
{
	"Name" : "SmartDetection.LoseObj",
	"SmartDetection.LoseObj":
	{
		"Enable" : 0,			//ʹ��
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
//��������������ݽṹ
typedef struct SM_LOSEOBJ_S
{
	int	bEnable;									//ʹ��
	float nRateX;									//X�������
	float nRateY;									//Y�������
	int direction[DETECT_AREA_NUM];					//��ⷽ��    0:����  1:ȡ��  Ĭ�ϣ�0
	AREA_RECT_S stLoseobjArea[DETECT_AREA_NUM];  	//���������������
	int time;											//����ʱ��     Ĭ��ֵ 5��
	char res[416];
}SM_LOSEOBJ;

/*
{
	"Name" : "SmartDetection.SmartAnalysis",
	"LumaDetect":
	{
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
	}
	"MotionDetect":
	{
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
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
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
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
		"Enable" : 0,			//ʹ��	
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
		"Enable" : 0,			//ʹ��
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
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
	}
	"DetectSound":
	{
		"Enable" : 0,			//ʹ��
		"Sensitivity" : 1600	//��ֵ
	}
	"LoseObj":
	{
		"Enable" : 0,			//ʹ��	
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
	SM_LUMADETECT 	sm_lumadetect;					//�������
	SM_MDDETECT     sm_mddetect;  					//�ƶ����
	SM_ODDETECT     sm_oddetect;  					//�ڵ����
	SM_CROSSLINE	sm_crossline;					//���⾯����
	SM_CROSSAREA    sm_crossarea;					//��������
	SM_DETECTCOLOR  sm_detectcolor;					//��ɫ���
	SM_DETECTSOUND  sm_detectsound;					//�������
	SM_LOSEOBJ		sm_loseobj;						//�����������
	char 			res[4096];						//����
}SMART_ANALYSIS_S;

SMART_ANALYSIS_S SysSmartConfig;


int FS_Init_SmartParam(void);
int FS_Get_SmartParam(int CMD,void  *pSmart);

#endif

