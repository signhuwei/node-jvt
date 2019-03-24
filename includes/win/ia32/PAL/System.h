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


/// ϵͳ���Խṹ
typedef struct SYSTEM_CAPS
{
	/// �ܹ��ڴ��С����Kilo-BytesΪ��λ��
	unsigned int MemoryTotal;

	/// ʣ���ڴ��С����Kilo-BytesΪ��λ������ϵ��Ӧ�ó�����ڴ�ʹ�ò��ԡ�
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
	MBD65XXT_LS = 5,//���ӵĿͻ�5*4����
	//21 31 20A
	MBD6016V_E = 6,  //Һ��һ���
	//3520A    ���������(1 2 3 4 ��)
	DVB6504E_P_1 = 7,
	DVB6504E_P_2 = 8,
	DVB6504E_P_3 = 9,
	DVB6504E_P_4 = 10,
};


typedef struct tagSYSTEM_CAPS_EX
{
	unsigned int ForNRT;			//�Ƿ�Ϊ��ʵʱ, ��λ��ʾ����ͨ���Ƿ���Ϊ��ʵʱ.��0xffff��ʾǰ16·���Ƿ�ʵʱ.
	unsigned char ForATM;			//�Ƿ�ΪATM��, 1��ʾ����Һ��ATM,2��ʾ��Һ��ATM
	unsigned char HasAudioBoard;	 //����Ƶ��
	unsigned char HasLoopBoard;		//����ͨ��
	unsigned char HasMatrixBoard;	//�������
	unsigned char HasPtzBoard;      //����̨��
	unsigned char HasWlanBoard;     //�����߰� 
	unsigned char BoardModel;	//��������
	unsigned char CpuType;
	//unsigned char reserved[2];	//֮ǰ�Ǳ���λ�������������ͺ�cpu����֮�󣬲���Ҫ��
}SYSTEM_CAPS_EX;

enum SYSTEM_FRONT_SWITCH_TYPE{
	NO_SUPPORT_SYSTEM_FRONT_SWITCH = 0, 	//0-��֧��SWITCH
	SYSTEM_FRONT_SWITCH_T,					//֧��Ŀǰ��6000 18K��10 GPIO
	SYSTEM_FRONT_SWITCH_BUF,
};

typedef struct tagSYSTEM_FUNC_EX
{
	unsigned char HasNatFunc;		//�Ƿ�֧��NAT ����,1֧�֣�0��֧��
	unsigned char HasPIPFunc;		//�Ƿ�֧��PIP ����,1֧�֣�0��֧��
	unsigned char HasSpotFunc;	//�Ƿ�֧��SPOT ����,1֧�֣�0��֧��
	unsigned char HasIntelFunc;	//�Ƿ�֧������ ����,1֧�֣�0��֧��
	unsigned char HasHVRFunc;	//�Ƿ�֧��HVR ����,1֧�֣�0��֧��
	unsigned char HasCPCFunc;	//�Ƿ�֧������CPC ����,1֧�֣�0��֧��
	unsigned char reserved[2];
	unsigned int FrontSwithType;	//ǰ���֧������
	unsigned int reserved1[5];
}SYSTEM_FUNC_EX;


/// ϵͳ����״̬
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
	unsigned int	dwMainHWType;      // Ӳ�����汾��
	unsigned int	dwMinorHWType;     // Ӳ���ΰ汾��
	unsigned int	dwProductType;     // ��Ʒ����𣬼�PRODUCT_TYPE
	unsigned int	dwMainSeriesType;  // ����� ��MAIN_SERIES_TYPE
	unsigned int	dwMinorSeriesType;  // ����𣬼�MINOR_SERIES_TYPE
	unsigned int	dwOEMType;         // OEM����
	unsigned int	dwReserved[4];   
}SYSTEM_PRODUCT_INFO;

/// �õ�ϵͳ���ԡ�
/// 
/// \param [out] pCaps ָ��ϵͳ���ԽṹSYSTEM_CAPS��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval <0  ��ȡʧ�ܡ�
int SystemGetCaps(SYSTEM_CAPS * pCaps);



/// �õ�ϵͳ��չ����
/// \param [out] pCaps ָ��ϵͳ��չ���ԽṹSYSTEM_CAPS_EX��ָ��
/// \retval 0 ��ȡ�ɹ�
/// \retval < 0 ��ȡʧ��
int SystemGetCapsEx(SYSTEM_CAPS_EX * pCaps);


/// ��ϵͳ��������������������������ͬ��ģʽ��ʱ�䵽�ŷ��ء�
/// 
/// \param [in] dwFrequence ����Ƶ�ʡ�
/// \param [in] dwDuration ������ʱ�䡣
void SystemBeep(unsigned int dwFrequence, unsigned int dwDuration );


/// ϵͳ��λ��
void SystemReboot(void);


/// ϵͳ�رա�
void SystemShutdown(void);


/// �˳��������е�Ӧ�ó���
void ApplicationExit(void);

/// ��������оƬ�豸
/// \return 0 �����ɹ�
/// \return < 0 ����ʧ��
int CryptoCreate(void);

/// ���ټ���оƬ�豸
/// \return 0 ���ٳɹ�
/// \return < 0 ����ʧ��
int CryptoDestory(void);

/// д����оƬ,��128���ֽڣ�ÿ32���ֽ�һ������
/// \param [in] zone ָʾҪ���ʵļ���оƬ����(0 ... 3)
/// \param [in] wdata Ҫд�ļ���оƬ������Ϣ
/// \param [in] len ���峤��
/// \return �������ֽ���
int CryptoWrite(int zone, const unsigned char *wdata, int len);

/// ������оƬ����128���ֽڣ�ÿ32���ֽ�һ������
/// \param [in] zone ָʾҪ���ʵļ���оƬ����(0 ... 3)
/// \param [out] wdata ��Ŷ����ļ���оƬ����
/// \param [in] len ���峤��
/// \return �������ֽ���
int CryptoRead(int zone, unsigned char *rdata, int len);

/// 
int CryptoFuse(void);

/// 
int CryptoCheck(void);

int SysteSyncTime(SYSTEM_TIME *ptime);

/// ���豸��Ϣ
/// \param [out] ��Ʒ��Ϣ
/// \return 0: succ
int SystemGetProductInfo(SYSTEM_PRODUCT_INFO *pInfo);

int SystemGetExFunction(SYSTEM_FUNC_EX *pExFunc);

//Һ��һ����������ܵ��õĽӿ�
int VGAShutDown();
int VGABoot();

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif
