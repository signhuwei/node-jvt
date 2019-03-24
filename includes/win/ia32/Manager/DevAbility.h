#ifndef __DEV_ABILITY_H__
#define __DEV_ABILITY_H__

#include "Infra/Singleton.h"
#include "ExchangeAL/Exchange.h"
#include "PAL/Capture.h"
#include "PAL/ExDec.h"
enum DevEXMODEL				//������չ������
{
	DEVEX_NORMAL	= 0x00000000,
 	DEVEX_ALLSDI	= 0x00000001,		//ȫSDI
	DEVEX_NR ,
};
enum NetConnectType			//�������������
{
 	NETCONNECT_NAT,
	NETCONNECT_TCP,
	NETCONNECT_NR,
};
class CDevAbility
{

	PATTERN_SINGLETON_DECLARE(CDevAbility);
public:

	bool Start(void);
	int GetDigDecChns();
	//��òɼ�ͨ����+����ͨ����
	int GetCapDecChns();
	int GetVTotalChns();
	int GetVCapChns();
	int GetMaxNetConnectNum(int ConnetType);//��ȡ���������Ƶ������
	//�������ͨ����
	int GetVDigitChns();
	int GetVMaxDecChns();
	int GetVPlayChns();
	int GetVPlayMaxChns();
	int GetVExCapChns();	
	
	int GetVOutChns();
	int GetVideoStandard();
	

	int GetAudioCapChns();
	int GetAudioInChns();
	
	int GetAlarmInChns();
	int GetAlarmOutChns();

	int GetLanguage();

	int GetMaxVPlayChns();

	int GetCommChns();//�õ���ǰ���õ�232������Ŀ
	int GetPtzChns(); //�õ���ǰ���õ���̨�豸��Ŀ

	const CAPTURE_CHNINFO & getChannelInfo();
	int GetDevType();
	int HasSnapShot();
	int HasNatFunc();
	int HasSpotFunc();
	int HasIntelFunc();
	int HasOnvifFunc();

	//����PEA֧�֣�λ��Ӧͨ��	
	uint GetIntelPEAFunc();
	//����OSC֧�֣�λ��Ӧͨ��
	uint GetIntelOSCFunc();
	//����AVD֧�֣�λ��Ӧͨ��
	uint GetIntelAVDFunc();
	//����CPC֧�֣�λ��Ӧͨ��
	uint GetIntelCPCFunc();
	uint getFrontSwithType();//��ȡǰ����Ƿ���Ҫת��
	bool MacRepeat(char* mac);// �ж�MAC��ַ�Ƿ������Ĭ��MAC��ͬ
	uint DevExModel();	//�õ�EX����
	bool CaptureGetProTotalHVRCap(CAPTURE_TOTAL_HVRCAP *pHVRCap); //�õ����ڴ洢��ʾ��ģʽ
private:
	int m_nVTotalChns; 	//�ܵ���Ƶͨ����(�ɼ�+����)
	int m_nDigDecChns;	//����ͨ����(����)
	int m_nCapSumDec; //�ɼ�ͨ����+����ͨ����
	int m_nVCapChns; 	//�ɼ�ͨ����
	int m_nVDigitChns;	//����ͨ����(��Ƶ)
	int m_nVPlayChns;	//�ط�ͨ����
	int m_nVPlayMaxChns; //���ط�·��
	int m_nVExCapChns;	//
	int m_nVOutChns;	//��Ƶ���ͨ����
	int m_nAudioInCHns;	//��Ƶ����ͨ����
	int m_nAudioCapChns;//��Ƶ�ɼ�ͨ����
	int m_nAlarmInChns;	//��������ͨ����
	int m_nAlarmOutChns;//�������ͨ����
	int m_nVideoStandard; //��Ƶ��ʽ
	int m_nLanguage;	//����
	int m_nMaxVPlayChns;	// HVR����ģʽ������ͨ����

	int m_nCommChannel;//��ǰ���õ�232������Ŀ
	int m_nPtzChannel; //��ǰ���õ���̨�豸��Ŀ
	int m_nMaxNetConnectNum[NETCONNECT_NR];//���������Ƶ������
	
	Bool m_bSnapShot; //֧��ץ��
	Bool m_bNatFunc; //֧��NAT����
	Bool m_bSpotFunc; //֧��Spot����
	Bool m_bIntelFunc; //֧��Inte����
	uint m_uIntelPEA; //����PEA֧�֣�λ��Ӧͨ��
	uint m_uIntelOSC; //����OSC֧�֣�λ��Ӧͨ��
	uint m_uIntelAVD; //����AVD֧�֣�λ��Ӧͨ��
	uint m_uIntelCPC; //����������֧�֣�λ��Ӧͨ��
	uint m_nFrontSwithType;//��Ҫǰ���ת��
	CAPTURE_CHNINFO m_ChnInfo;
	int m_nMaxDecorderChns; //������ͨ����
	uint m_DevExModel;//��չģʽSDI���
	CAPTURE_TOTAL_HVRCAP m_ProHVRCAP; //������ͨ�������ڽ���ͨ����ʱ�����ڴ洢��ʾ��ģʽ
	Bool m_bOnvifFunc; //֧��onvif
	int getAudioInNum();
	
	void onHookDevDesc(CConfigTable &cfgDevDesc, int &ret);
};

#define g_DevAbility (*CDevAbility::instance())
#endif
