//
//  "$Id: AnalyzeExchange.h 1056 2012-03-09 16:33:32Z zcl $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//  
//

#ifndef __EXCHANGEAL_IMP_EXCHANGE_H__
#define __EXCHANGEAL_IMP_EXCHANGE_H__

#include "PAL/Imp.h"
#include "GUIExchange.h"
#include "Manager/EventManager.h"
#include "ExchangeAL/MediaExchange.h"
//#include "Infra/Timer.h"

enum _module_type
{
	MODULE_TYPE_PEA = 0,
	MODULE_TYPE_OSC,
	MODULE_TYPE_AVD,
	MODULE_TYPE_CPC,
	MODULE_TYPE_ALL,
};

enum
{
	maxCPCDataItem = 2048,
	maxCPCDataReturn = 512,
	itemtotalLength = 96,	//2λͨ���ţ�20λ��ʼʱ�䣬20λ����ʱ�䣬������13λ������,������
};

//�����㷨�Ĺ������ü���
typedef struct tagRuleConfig
{
	PEA_RULE_S stRulePea;   //�ܽ������������
	OSC_RULE_S stRuleOSC; //��Ʒ���ơ��������Ƿ�ͣ������
	AVD_RULE_S stRuleAVD;//�쳣��Ƶ�ź��������
	CPC_RULE_S stRuleCPC;//��ͷ�����㷨����
}RuleConfig;


//һ��ͨ�������ܷ�������
typedef struct tagAnalyzeConfig
{
	bool         bEnable;      //�Ƿ�������Ƶ��������
	int          moduleType;   //ʹ�õ������㷨ģ��
	EventHandler hEvent;  //�����¼�
	RuleConfig   stRuleConfig; //�����㷨�Ĺ�������
}AnalyzeConfig;

//����ͨ�������ܷ�������
typedef struct tagAnalyzeConfigAll
{
	AnalyzeConfig vAnalyzeAll[N_SYS_CH];
}AnalyzeConfigAll;

//���ܷ�������
struct AnalyzeAbility
{
	uint uIntelPEA; //����PEA֧�֣�λ��Ӧͨ��
	uint uAlgorithmPEA;//PEA֧�ֵ��㷨���ͣ��������
	uint uIntelOSC; //����OSC֧�֣�λ��Ӧͨ��
	uint uAlgorithmOSC;//OSC֧�ֵ��㷨����
	uint uIntelAVD; //����AVD֧�֣�λ��Ӧͨ��
	uint uAlgorithmAVD;//AVD֧�ֵ��㷨����
	uint uIntelCPC; //����������֧�֣�λ��Ӧͨ��
	uint uAlgorithmCPC;//CPC֧�ֵ��㷨����
	

};

struct CPCLink
{
	int NoteTime;
	VIDEO_WIDGET CPCInfo;
};

struct AnalyzeLink
{
	CPCLink CPCLinkConfig;
};

struct AnalyzeLinkAll
{
	AnalyzeLink vAnalyzeLinkAll[N_SYS_CH];
};

struct CPCDataItem		//����ͳ����ṹ��
{
	int channel;			//��Ӧ��ͨ����
	SystemTime startTime;	//��ʼʱ��
	SystemTime endTime;	//����ʱ��
	int inNum;			//��������
	int outNum;			//�뿪����
};

struct CPCDataAll
{
	int nItemNum;
	CPCDataItem CPCData[maxCPCDataReturn];
};

#endif //__EXCHANGEAL_IMP_EXCHANGE_H__
