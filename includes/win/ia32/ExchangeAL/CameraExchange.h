#ifndef _EXCHANGEAL_CAMERAEXCHANGE_H
#define _EXCHANGEAL_CAMERAEXCHANGE_H

#include "Types/Defs.h"
#include "Types/Types.h"


typedef enum CAMERA_SCENE //��ƽ��
{
	SCENE_AUTO,
	SCENE_INDOOR, //����
	SCENE_OUTDOOR //����
}CAMERA_SCENE;

typedef enum DNC_MODE //��ҹģʽȡֵ
{
	DNC_AUTO,			// �Զ��л�
	DNC_MULTICOLOR,		// ��ɫ
	DNC_BLACKWHITE,		// ǿ��Ϊ�ڰ�ģʽ
	DNC_NR
}DNC_MODE;

typedef enum APERTURE_MODE //�Զ���Ȧģʽ
{
	APERTURE_AUTO_ON,
	APERTURE_AUTO_OFF,
}APERTURE_MODE;

typedef enum BLC_MODE //���ⲹ��ģʽ
{
	BLC_AUTO,
	BLC_ON,
	BLC_OFF
}BLC_MODE;





//�ع�����
struct ExposureParam
{
	int  level;    //�ع�ȼ�
	uint leastTime;//�Զ��ع�ʱ�����޻��ֶ��ع�ʱ�䣬��λ΢��
	uint mostTime; //�Զ��ع�ʱ�����ޣ���λ΢��
	int levelTime;//�ع�ʱ�� ��λ΢��   //by zjh 20170802
};


//��������
struct GainParam
{
	int gain;    //�Զ���������(�Զ���������)��̶�����ֵ
	int autoGain;//�Զ������Ƿ����ã�0:������  1:����
};
//��˼IPCͼ���񣬲�ͬ���֮�仭�汥�Ͷ�֮�������ͬ�������ɵײ����
enum IMG_TYPE
{
	IMG_TYPE_DEFAULT,
	IMG_TYPE_1,
	IMG_TYPE_2,
	IMG_TYPE_NR,
};
//��������ͷ��չ����
struct CameraParamEx
{
	GainParam broadTrends;	//��̬
	int style;	//enum IMG_TYPE
	uint exposureTime;//ʵ����Ч���ع�ʱ��
	int res[62];	//����
};

//��������ͷ����
struct CameraParam
{
	uint whiteBalance;		//��ƽ��
	uint dayNightColor;		//��ҹģʽ��ȡֵ�в�ɫ���Զ��л��ͺڰ�
	int  elecLevel;		//�ο���ƽֵ
	uint apertureMode;		 //�Զ���Ȧģʽ
	uint BLCMode;		//���ⲹ��ģʽ
	ExposureParam exposureParam;//�ع�����
	GainParam gainParam;	//��������
	uint PictureFlip;		//ͼƬ���·�ת
	uint PictureMirror;		//ͼƬ���ҷ�ת
	uint RejectFlicker;		//�չ�Ʒ�������
	uint EsShutter;		//���������Ź���
	int ircut_mode;		//IR-CUT�л� 0 = �����ͬ���л� 1 = �Զ��л�
	int dnc_thr;		//��ҹת����ֵ
	int ae_sensitivity;	//ae����������
	int Day_nfLevel;		//noise filter �ȼ���0-5,0���˲���1-5 ֵԽ���˲�Ч��Խ����
	int Night_nfLevel;
	int Ircut_swap;		//ircut ������= 0        ����= 1
	int BLCValue;       //���ⲹ��ֵ   //by zjh 20170802
};


//�������ͷ�Ĳ���
struct CameraParamAll
{
	CameraParam vCameraParamAll[N_SYS_CH];
};

// ����ͷ������չ����
struct CameraParamExAll
{
	CameraParamEx vCameraParamExAll[N_SYS_CH];
};

//����ͷ������
struct CameraAbility
{
	int  count;      //֧���ع��ٶ�����
	uint speeds[16]; //�ع��ٶ�
	int  status;     //����״̬  >= 0 ����    < 0 �쳣
	int  elecLevel;  //�ο���ƽֵ
	int  luminance;  //ƽ������
	char pVersion[64];//xm 2a�汾
	char reserve[32];//����
};
struct CameraClearFog
{
	bool enable; //0 �򿪣�1 ����
	int  level ; // ǿ�ȵȼ�[0,100] 
	char rev[4];
};
struct CameraClearFogAll
{
	CameraClearFog vCameraClearFogAll[N_SYS_CH];
};

//������������
struct CameraMotorCtrl
{
	bool UDDireOverturn;   //���·���ת
	bool LRDireOverturn;   //���ҷ���ת
	bool UDRestOverturn;   //������λ��ת
	bool LRRestOverturn;   //������λ��ת
	int  rev[8];
};


//  -----  ���������۹�����ؽṹ��  --------------------
//��װλ��
typedef enum{
	FISHEYE_APP_CEIL = 0, //�컨��
	FISHEYE_APP_TABL = 1, //����
	FISHEYE_APP_WALL = 2, //ǽ��
}FISHEYE_APP_TYPE_E;

//����ģʽ
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
	int appType;	//��ö��FISHEYE_APP_TYPE_E
	int secene;		//��ö��FISHEYE_SECENE_E
	unsigned int reserv[8];
};

#endif // _EXCHANGEAL_CAMERAEXCHANGE_H
