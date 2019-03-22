//
//  "$Id: GUIExchange.h 13342 2014-09-15 11:47:26Z zhaochanglong $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __EXCHANAGEAL_GUI_EXCHANGE_H__
#define __EXCHANAGEAL_GUI_EXCHANGE_H__

#include "Types/Defs.h"
#include "ExchangeAL/Exchange.h"


/// GUI����
struct GUISetConfig
{
	int iWindowAlpha;			///< ����͸����	[128, 255]
	bool bTimeTitleEn;			///< ʱ�������ʾʹ��
	bool bChannelTitleEn;		///< ͨ��������ʾʹ��	
	bool bAlarmStatus;			///<  ����״̬
	bool bRecordStatus;			///<  ¼��״̬��ʾʹ��
	bool bChanStateRecEn;		///< ¼���־��ʾʹ��
	bool bChanStateVlsEn;		///< ��Ƶ��ʧ��־��ʾʹ��
	bool bChanStateLckEn;		///< ͨ��������־��ʾʹ��	
	bool bChanStateMtdEn;		///< ��̬����־��ʾʹ��
	bool bBitRateEn;			///< ������ʾʹ��
	bool bRemoteEnable;			///< ң����ʹ��
	bool bDeflick;				///< ������
};

//������
struct Guideconfig
{
	int bEnable; 				///<���Ƿ�����1������0�ر�
	int reserved[3];
};

struct AppDownloadLink
{
	bool IOSEnable;    //�Ƿ���ʾiphone�ͻ��˶�ά��
	bool AndroidEnable;//�Ƿ���ʾ��׿�ͻ��˶�ά��
	bool SNEnable;     //�Ƿ���ʾ���кŶ�Ӧ�Ķ�ά��
	bool OtherEnable;  //�Ƿ���ʾ�ͻ��Զ����ά��

	std::string linkIOS;
	std::string linkAndroid;
	std::string nameOther;  //�ͻ��Զ����ά������
	std::string linkOther;  //�ͻ��Զ����ά��
};

//VGA�ֱ���
struct VGAresolution
{
	int nHeight;
	int nWidth;
};
/// �õ�ϵͳ�ܵ������б�
ConfigPair *getSystemLanguageList();

#endif
