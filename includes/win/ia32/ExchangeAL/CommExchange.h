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


/// ��������������
enum WorksheetName
{
	RECORD_WORKSHEET = 0,		///< ¼������
	ALARM_WORKSHEET = 1,		///< ����������
	MOTION_WORKSHEET = 2,		///< ���칤����
	BLIND_WORKSHEET = 3,		///< �ڵ�������
	VIDEOLOSS_WORKSHEET = 4,	///< ��Ƶ��ʧ������
	NETALARM_WORKSHEET = 5,	    ///< ���籨��������
	VIDEOANALYZE_WORKSHEET = 6,	///<��Ƶ����������
	IPC_ALARM_WORKSHEET = 7,	///< IPC����������
	SERIALPORT_ALARM_WORKSHEET = 8,///<���ڱ���������
	WORKSHEET_NR,
};


/// ��̨��������
enum PtzLinkTypes
{
	PTZ_LINK_NONE,			// ����Ҫ���� 
	PTZ_LINK_PRESET,		// ת��Ԥ�õ� 
	PTZ_LINK_TOUR,			// Ѳ�� 
	PTZ_LINK_PATTERN		// �켣 
};

/// �ٶȱ�������
enum SpeedAlarmTypes
{
	SPEED_ALARM_HIGH = 0,		// ���ٱ���
	SPEED_ALARM_LOW,		// ���ٱ���
	SPEED_ALARM_NR
};

///< �����¼��ṹ
struct GenericEventConfig
{
	bool bEnable;			///< ʹ��
	EventHandler hEvent;	///< �������
};

/// ����ͨ���Ļ���ʱ��ṹ
struct GenericEventConfigAll
{
	GenericEventConfig vGenericEventConfig[N_SYS_CH];
};

///< ��̬�������
struct MotionDetectConfig
{
	bool bEnable;							// ��̬��⿪�� 
	int iLevel;								// ������ 
	uint mRegion[MD_REGION_ROW];			// ����ÿһ��ʹ��һ�������ƴ� 	
	EventHandler hEvent;					// ��̬������� 
};

/// ȫͨ����̬�������
struct MotionDetectConfigAll
{
	MotionDetectConfig vMotionDetectAll[N_SYS_CH];
};

///< �ڵ��������
struct BlindDetectConfig
{
	bool	bEnable;		///< �ڵ���⿪��
	int		iLevel;			///< �����ȣ�1��6
	EventHandler hEvent;	///< �ڵ������������
};

/// ȫͨ���ڵ��������
struct BlindDetectConfigAll
{
	BlindDetectConfig vBlindDetectAll[N_SYS_CH];
};

///< �ٶȱ�������
struct SpeedAlarmConfig
{
	bool	bEnable;		///< �ٶȱ���ʹ��
	int		iSpeed;			///< �ٶ�
	EventHandler hEvent;	///< �ٶȱ�����������
};

/// ȫ�����͵��ٶȱ�������
struct SpeedAlarmConfigAll
{
	SpeedAlarmConfig vSpeedAlarmAll[SPEED_ALARM_NR];
};


// GSensor��������
struct GSensorAlarmConfig
{
	bool	bEnable;		// GSensor����ʹ��
	int 	iXThreshold;	// X�ᱨ����ֵ����λg����һ���������ٶ�
	int 	iYThreshold;	// Y�ᱨ����ֵ����λg����һ���������ٶ�
	int		iZThreshold;	// Z�ᱨ����ֵ����λg����һ���������ٶ�
	EventHandler hEvent;	// GSensorAlarmConfig������������
};

struct	LossShowStrConfig
{
	char ShowStr[SHOW_STR_LEN];
};

struct LossShowStrConfigALL
{
	LossShowStrConfig vLossShowStrAll[N_SYS_CH];
};


///< ���ر�������
struct AlarmConfig
{
	bool	bEnable;		///< �������뿪��
	int		iSensorType;	///< ���������ͳ��� or ����
	EventHandler hEvent;	///< ��������
};

///< ����ͨ���ı�������
struct AlarmConfigAll
{
	AlarmConfig vAlarmConfigAll[N_ALM_IN];
};

///< ���ر����������
struct AlarmOutConfig
{
	int nAlarmOutType;		///< �����������: ����,�ֶ�,�ر�
	int nAlarmOutStatus;    ///< ����״̬: 0:�� 1;�պ�
};

///< ����ͨ���ı����������
struct AlarmOutConfigAll
{
	AlarmOutConfig vAlarmOutConfigAll[N_ALM_OUT];
};

//< Ӳ�����������¼�ʣ����������
enum StorageLowSpaceType
{
	PERSENT = 0,
	MB,
	GB,
};

///< Ӳ�����������¼��ṹ
struct StorageLowSpaceConfig
{
	bool bEnable;
	int iLowerLimit;		///< Ӳ��ʣ����������, �ٷ���
	EventHandler hEvent;	///< �������
	bool bRecordTimeEnable;
	int iRecordTime;		///<¼������
	int iLowerLimitSpace;		///< Ӳ��ʣ������MB����GBΪ��λ
	int EnableType;		///< 0Ϊ�ðٷֱȣ�1Ϊ��MB����ö��StorageLowSpaceType
};

///<Ӳ�̳����¼��ṹ
struct StorageFailConfig
{
	bool 	bEnable;
	EventHandler hEvent;	///< �������
	bool	bRebootEnable;		//ϵͳ����ȫ��:hutianhao
	int		bRebooted;			//�Ƿ����������;0:δ����������;��0:����������
};

// ����Э��
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
	int	iDataBits;	// ����λȡֵΪ5,6,7,8 
	int	iStopBits;	// ֹͣλ
	int	iParity;	// У��λ
	int	iBaudRate;	// ʵ�ʲ�����
};

// ��������
struct CONFIG_COMM_X
{
	char sProtocolName[MAX_PROTOCOL_LENGTH];	// ����Э��:��Console�� 
	int iPortNo;		// �˿ں� 
	COMMATTRI aCommAttri;		// �������� 
};

struct CommConfigAll
{
	CONFIG_COMM_X vCommConfig[COM_TYPES];
};

// ��̨����
struct CONFIG_PTZ
{
	char sProtocolName[MAX_PROTOCOL_LENGTH];	// Э������ 	
	int	ideviceNo;				// ��̨�豸��ַ��� 	
	int	iNumberInMatrixs;		// �ھ����е�ͳһ���	
	int iPortNo;				// ���ڶ˿ں�	[1, 4] 	
	COMMATTRI dstComm;			// �������� 	
};

struct PTZConfigAll
{
	CONFIG_PTZ ptzAll[N_SYS_CH];
};

struct RS485ConfigAll
{
	CONFIG_PTZ rs485All[N_SYS_CH];
};


//����״̬
enum CAR_STATUS_TYPE
{
	CAR_WORKING,             //�Ƿ�������
	CAR_LIGHT_LEFT_TURN,     //��ת���Ƿ����
	CAR_LIGHT_RIGHT_TURN,    //��ת���Ƿ����
	CAR_DOOR_LEFT_FRONT,     //��ǰ���Ƿ��
	CAR_DOOR_RIGHT_FRONT,    //��ǰ���Ƿ��
	CAR_DOOR_LEFT_BACK,      //������Ƿ��
	CAR_DOOR_RIGHT_BACK,     //�Һ����Ƿ��
	CAR_DOOR_BACK,           //�����Ƿ��
	CAR_BRAKE,			     //�Ƿ��ɲ��
	CAR_URGENCY_ALARM,       //��������
	CAR_STATUS_NR, //״̬������Ŀ
};

//�ⲿ��������
enum IO_INPUT_TYPE
{
	LOCAL_ALARM_INPUT,//���ر�������
	RS232_INPUT,      //ͨ��232��������
	RS485_INPUT,      //ͨ��485��������
};

//�ⲿ��Ϣ�����복��״̬�Ķ�Ӧ��ϵ
struct CarStatusExchange
{
	int  statusType; //��һ�ֳ���״̬��������ת��
	bool bExist;     //�Ƿ��и���״̬����Ϣ���룬���ݳ�����ʵ�������������
	bool bEnable;    //�Ƿ������״̬
	int  inputType;  //����״̬��Ӧ����Ϣ�������ͣ���IO_INPUT_TYPEö�ٵ�ֵ��ȡ
	int  addr;       //��ַ�������Ǳ��ر��������һ��Ӧ0������ڶ���Ӧ1
	int  sensorType; //����(NO)�򳣱�(NC)����inputType�Ǳ��ر�������ʱ��Ч
};

struct CarStatusExchangeAll
{
	CarStatusExchange exchangeAll[16];
};

struct CarDelayTimeConfig
{
	bool bStartDelay;
	bool bCloseDelay;
	
	int timeStartDelay;		//��λ:����
	int timeCloseDelay;		//��λ:����
};

//GPSУʱ����
struct GPSTimingConfig
{
	bool bEnable;      // �Ƿ�����
	int  timeChange;   // �����UTCʱ����Ҫ�ı���٣���λ:��
	int  updatePeriod; // ��������  ��λ:����
};

enum CAR_BOOT_TYPE
{
	CAR_BOOT_TYPE_SPARK,  //���Ϩ�𿪹ػ�
	CAR_BOOT_TYPE_TIMING, //��ʱ���ػ�
	CAR_BOOT_TYPE_NR,
};

//��𿪹ػ���ʱ����
struct CarSparkWork
{
	int bootDelayMinute;  //������ʱ������
	int shutDelayMinute;  //�ػ���ʱ������
	char resv[24];        //����
};

//���ض�ʱ���ػ�����
struct CarTimingWork
{
	TimeSection workSection1; //����ʱ���1
	TimeSection workSection2; //����ʱ���2

	char resv[32]; //����
};

//����DVR�����͹رշ�ʽ
struct CarBootTypeConfig
{
	int           bootType;         //��ö�� CAR_BOOT_TYPE ����
	CarSparkWork  sparkWorkConfig;  //��𿪹ػ�����
	CarTimingWork timingWorkConfig; //��ʱ���ػ�ʱ���1
	char          resv[48];
};


//���Ѳ��
struct TourState
{
	bool bRunning;
	int  lineID;   //���Ѳ����·���
};

//Ѳ��
struct PatternState
{
	bool bRunning;
	int  lineID;  //Ѳ����·��� (δʹ��)
};

//��ɨ
struct ScanState
{
	bool bRunning;
	int  lineID;  //��ɨ��·��� (δʹ��)
};

//ˮƽ��ת
struct PanonState
{
	bool bRunning;
	int  lineID;  //ˮƽ��ת��·��� (δʹ��)
};

//����ת��ָ��Ԥ�õ�
struct PresetState
{
	bool bEnable;
	int  iPresetID;  
};

//�ϵ�ǰλ��
struct PoweroffState
{
	bool bEnable;
	int  iPresetID;  
};

//һ��ͨ������̨����״̬
struct PtzState
{
	TourState    tourState;
	PatternState patternState;
	ScanState    scanState;
	PanonState   panonState;
	PresetState  presetState;
	PoweroffState poweroffState;
};

//������ָ�֮ǰ����̨����״̬
struct ResumePtzState
{
	bool     bEnable;                    //�Ƿ������豸������ָ���̨״̬����
	PtzState ptzStateAll[N_SYS_CH];
};

///< ��������ͨ���ı�������
struct IPCAlarmConfigAll
{
	AlarmConfig vAlarmConfigAll[N_DECORDR_CH];
};

// ���ж���
struct PtzIdleState
{
	bool bEnable;			// ���ж���ʹ��λ
	int iTime;				// ����ʱ�� ��λ: ��
	int iIdleState;			// ���ж�������  0ΪԤ�õ㣬1Ϊ���Ѳ����2Ϊ�޶���
	int iId;				// ��Ӧ���ж������͵Ķ������
};
struct PtzIdleStateAll
{
	PtzIdleState pPtzIdleStateAll[N_SYS_CH];
};
///<���ڱ�������
struct SerialPortAlarmConfig
{
	AlarmConfig vAlarmConfigAll[N_SYS_CH];
};


//=====================���ܷ��������=======================
typedef int SIMPLE_IMP_S32;
typedef short SIMPLE_IMP_S16;

#define SIMPLE_IMP_MAX_POINT_NUM 4

//��Ʒ����-begin
#define SIMPLE_IMP_MAX_OSC_NUM 4

/** ���߽���� */
#define SIMPLE_IMP_MAX_BOUNDARY_POINT_NUM 8

/** URP������������� */
#define SIMPLE_IMP_URP_MAX_TRIPWIRE_CNT 8

/**�����*/
typedef struct SIMPLE_impURP_IMP_POINT_S
{
	SIMPLE_IMP_S16 s16X;					/**< x */
	SIMPLE_IMP_S16 s16Y;					/**< y */
}SIMPLE_URP_IMP_POINT_S;

//===================CPC�㷨�����====================
typedef struct SIMPLE_tagCPC_RULE_S
{
	SIMPLE_URP_IMP_POINT_S stRulePoint[SIMPLE_IMP_MAX_POINT_NUM];	//��������Ҫ����4����
	int s32Sizemin;			///��С���(0,height/2)
	int s32Sizemax;			///������(sizemin, height/2)
	int s32Countmax;			///���Ŀ����[1~15],
	int s32Sensitivity;			/// �����ȵ�λ1-5,��ֵԽ��Խ���ױ���	
	unsigned int u32Flag;		///��־λ�������б������Ĭ����0
	int s32EnterDirection;		///����ķ���
}SIMPLE_CPC_RULE_S;

typedef struct  SIMPLE_CONFIG_CPC_RULE_ALL
{
	SIMPLE_CPC_RULE_S channel[N_SYS_CH];
}SIMPLE_CONFIG_CPC_RULE_ALL;

//===================AVD�㷨�����====================
typedef struct SIMPLE_tagAVD_RULE_S
{
	int iLevel;					///�����ȵ�λ
	int itBrightAbnmlEnable;		///�����쳣ʹ��
	int iClarityEnable;			///�����ȼ��ʹ��
	int iNoiseEnable;			///�������ʹ��
	int iColorEnable;			///ƫɫ���ʹ��
	int iFreezeEnable;			///���涳����ʹ��
	int iNosignalEnable;		///�ź�ȱʧ���ʹ��
	int iChangeEnable;			///�����任���ʹ��
	int iInterfereEnable;		///��Ϊ���ż��ʹ��
	int iPtzLoseCtlEnable;		///PTZʧ�ؼ��ʹ��
}SIMPLE_AVD_RULE_S;

typedef struct  SIMPLE_CONFIG_AVD_RULE_ALL
{
	SIMPLE_AVD_RULE_S channel[N_SYS_CH];
}SIMPLE_CONFIG_AVD_RULE_ALL;

//===================OSC�㷨�����====================
typedef struct SIMPLE_impURP_OSC_SPECL_REGIONS_S
{
	SIMPLE_IMP_S32 s32Valid; 							//�Ƿ���Ч
	SIMPLE_IMP_S32 s32PointNum;
	SIMPLE_URP_IMP_POINT_S astPoint[SIMPLE_IMP_MAX_BOUNDARY_POINT_NUM];
}SIMPLE_URP_OSC_SPECL_REGIONS_S;

typedef struct SIMPLE_impURP_OSC_RULE_PARA_S
{
	SIMPLE_IMP_S32 s32TimeMin;		//ʱ��Լ��
	SIMPLE_IMP_S32 s32SizeMin;		//��С�ߴ�
	SIMPLE_IMP_S32 s32SizeMax; 		//���ߴ�
	SIMPLE_URP_OSC_SPECL_REGIONS_S astSpclRgs[SIMPLE_IMP_MAX_OSC_NUM]; //Ҫ������������
}SIMPLE_URP_OSC_RULE_PARA_S;

typedef struct SIMPLE_tagOCS_RULE_S
{
	int iShowTrack;				//�Ƿ���ʾ�켣
	int iLevel;						//���伶��:�ͼ�(2), �м�(1), �߼�(0)
	int iAbandumEnable;		   	//��Ʒ����ʹ��
	SIMPLE_URP_OSC_RULE_PARA_S stObjAbandumRulePara; //��Ʒ��������
	int iStolenEnable;			  	 //��Ʒ����ʹ��
	SIMPLE_URP_OSC_RULE_PARA_S stObjStolenRulePara;   //��Ʒ��������
	int iNoParkingEnable;		 	 //�Ƿ�ͣ��ʹ��
	SIMPLE_URP_OSC_RULE_PARA_S stNoParkingRulePara;   //�Ƿ�ͣ������
}SIMPLE_OSC_RULE_S;

typedef struct  SIMPLE_CONFIG_OSC_RULE_ALL
{
	SIMPLE_OSC_RULE_S channel[N_SYS_CH];
}SIMPLE_CONFIG_OSC_RULE_ALL;

//===================PEA�㷨�����====================
/** URP�����߽ṹ*/
typedef struct SIMPLE_impURP_TRIPWIRE_S
{
	SIMPLE_IMP_S32     s32Valid;					//�Ƿ���Ч
	SIMPLE_IMP_S32     s32IsDoubleDirection;		//��ʾ�ð����Ƿ�Ϊ˫����ߣ�0����1���ǣ�
	SIMPLE_URP_IMP_POINT_S stStartPt;		//�߶����
	SIMPLE_URP_IMP_POINT_S stEndPt;		//�߶��յ�
}SIMPLE_URP_TRIPWIRE_S;

/** URP�ܽ��������� */
typedef struct SIMPLE_impURP_PERIMETER_RULE_PARA_S
{
	SIMPLE_IMP_S32  s32Mode;				//�ܽ�ģʽ
	SIMPLE_IMP_S32  s32MinDist;				//��С���ؾ���
	SIMPLE_IMP_S32  s32BoundaryPtNum;		//�߽����Ŀ
	//�߽�㼯��
	SIMPLE_URP_IMP_POINT_S  astBoundaryPts[SIMPLE_IMP_MAX_BOUNDARY_POINT_NUM];			
}SIMPLE_URP_PERIMETER_RULE_PARA_S;


/** URP�����߹������*/
typedef struct SIMPLE_impURP_TRIPWIRE_RULE_PARA_S
{
	SIMPLE_IMP_S32  s32MinDist;				//��С���ؾ���
	SIMPLE_URP_TRIPWIRE_S astLines[SIMPLE_IMP_URP_MAX_TRIPWIRE_CNT]; //8��������
}SIMPLE_URP_TRIPWIRE_RULE_PARA_S;

typedef struct SIMPLE_tagPEA_RULE_S
{
	int iShowTrack;						/// �Ƿ���ʾ�켣
	int iLevel;						   	/// ���伶��:�ͼ�(2), �м�(1), �߼�(0)
	int iPerimeterEnable;				/// �ܽ����ʹ��
	SIMPLE_URP_PERIMETER_RULE_PARA_S	stPerimeterRulePara;	//�ܽ���
	int iTripWireEnable;					///�����߹���ʹ��
	SIMPLE_URP_TRIPWIRE_RULE_PARA_S	stTripwireRulePara;		//�����߼��
}SIMPLE_PEA_RULE_S;

typedef struct  SIMPLE_CONFIG_PEA_RULE_ALL
{
	SIMPLE_PEA_RULE_S channel[N_SYS_CH];
}SIMPLE_CONFIG_PEA_RULE_ALL;

//==================���ܷ�����ͨ������====================
typedef struct SIMPLE_AnalyzePub
{
	bool bEnable;			//���ܷ����Ƿ�ʹ��
	int moduleType;			//��ǰѡ����㷨ģ��
}SIMPLE_AnalyzePub;

typedef struct  SIMPLE_AnalyzePub_ALL
{
	SIMPLE_AnalyzePub channel[N_SYS_CH];
}SIMPLE_AnalyzePub_ALL;

#endif
