//
//  "$Id: EventManager.h 2159 2011-11-11 09:15:32Z renxusheng $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __MANAGER_EVENT_H__
#define __MANAGER_EVENT_H__

#include "Infra/Signals.h"
#include "Infra/Time.h"
#include "Types/Defs.h"
#include <Json/value.h>
#include <string>

//  ��̨�����ṹ
struct PtzLinkConfig
{
	int iType;		// ���������ͣ���PtzLinkTypes
	int iValue;		// ���������Ͷ�Ӧ��ֵ 
};

/// ������
struct WorkSheet
{	
	TimeSection	tsSchedule[N_WEEKS][N_TSECT];
};

/// �¼��������
struct EventHandler
{
	uint	dwRecord;				// ¼������ 
	int		iRecordLatch;			// ¼����ʱ��10��300 sec  	
	uint	dwTour;					// ��Ѳ���� 	
	uint	dwSnapShot;				// ץͼ���� 
	uint	dwAlarmOut;				// �������ͨ������ 
	uint	dwMatrix;				// �������� 
	int		iEventLatch;			// ������ʼ��ʱʱ�䣬sΪ��λ 
	int		iAOLatch;				// ���������ʱ��10��300 sec  
	PtzLinkConfig PtzLink[N_SYS_CH];		// ��̨������ 
	WorkSheet schedule;		// ¼��ʱ���

	bool	bRecordEn;				// ¼��ʹ�� 
	bool	bTourEn;				// ��Ѳʹ�� 
	bool	bSnapEn;				// ץͼʹ�� 	
	bool	bAlarmOutEn;			// ����ʹ�� 
	bool	bPtzEn;					// ��̨����ʹ�� 
	bool	bTip;					// ��Ļ��ʾʹ�� 	
	bool	bMail;					// �����ʼ� 	
	bool	bMessage;				// ������Ϣ���������� 	
	bool	bBeep;					// ���� 	
	bool	bVoice;					// ������ʾ 		
	bool	bFTP;					// ����FTP���� 
	bool	bMatrixEn;				// ����ʹ�� 
	bool	bLog;					// ��־ʹ��
	bool	bMessagetoNet;			// ��Ϣ�ϴ�������ʹ�� 

	bool	bShowInfo;              // �Ƿ���GUI�Ϻͱ�������ʾ������Ϣ
	uint	dwShowInfoMask;         // Ҫ������ʾ������Ϣ��ͨ������
	char	pAlarmInfo[CHANNEL_NAME_MAX_LEN];//Ҫ��ʾ�ı�����Ϣ

	bool    bShortMsg;              //���Ͷ���
	bool    bMultimediaMsg;         //���Ͳ���
};

typedef struct tagEVENT_INFO
{
	std::string		code;
	int				index;
	const EventHandler*	parameter;			// �¼��������
}EVENT_INFO;

#define MAX_EVENT_LATCH_NUMBER 4

class IEventManager
{
public:
	typedef TSignal5<std::string, int, appEventAction, const EventHandler *, Json::Value*> SIG_EVENT;
	typedef SIG_EVENT::SigProc Proc;

	static IEventManager* instance();
	virtual ~IEventManager();
	virtual bool attach(Proc proc) = 0;
	virtual bool detach(Proc proc) = 0;
	virtual bool checkTimeSection(const WorkSheet*workSheet) = 0;
	virtual void notify(std::string code, int index = 0, appEventAction action = appEventStart, const EventHandler *param = NULL, const WorkSheet *workSheet = NULL, Json::Value* data = NULL) = 0;
	virtual void getNextEvent() = 0;
	virtual bool getNextEvent(void* handler, EVENT_INFO* info) = 0;
	virtual void latchEvent(void *handler, IEventManager::Proc proc, std::string code, int index, int second) = 0;
};

#endif
