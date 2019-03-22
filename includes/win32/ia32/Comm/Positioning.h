//
//  "$Id: Positioning.h 874 2013-01-29 10:32:39Z dyn $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef _COMM_POSITIONING_H_
#define _COMM_POSITIONING_H_

//#include "../Infra/Time.h"

enum POSITIONING_INFO_TYPE
{
	POS_INFO_GSA,	//��ǰ������Ϣ
	POS_INFO_GSV,	//�ɼ�������Ϣ
	POS_INFO_GGA,	//GPS��λ��Ϣ
	POS_INFO_RMC,	//�Ƽ���λ��Ϣ
	POS_INFO_VTG,	//�����ٶ���Ϣ
	POS_INFO_NR
};

enum POSITIONING_DIRECTION
{
	POS_DIRECTION_EAST  = 'E',
	POS_DIRECTION_WEST  = 'W',
	POS_DIRECTION_SOUTH = 'S',
	POS_DIRECTION_NORTH = 'N'
};

enum POSITIONING_STATUS
{
	POSITIONING_OK,      //��λ�ɹ�
	POSITIONING_FAILED,  //��λʧ�ܣ�δ�յ������ź�
	POSITIONING_NO_DATA, //�������ô����GPS�豸����
	POSITIONING_INVALIDE,
};


struct POSITIONING_POS//��γ��
{
	int  degree;     //��(��/1000)Ϊ��λ
	char direction;  //��λ ȡֵ��ö��ֵPOSITIONING_DIRECTION��ʾ
	char res[3];
};

struct POSITION_INFO
{
	SystemTime        time;	//ʱ��
	POSITIONING_POS   longitude;	//����
	POSITIONING_POS   latitude;	//γ��
	int               speed;		//�ٶ�, ��λm/h
	char              res[16];
};


class IPositioning
{
public:
	static IPositioning* instance();

	//���ã���GPS��Ϣ���н���(Ҫ��pData����������GPS����)
	//���أ������ɹ���������
	virtual int parse(const uchar* pData, int len) = 0;

	//���ã���ȡ���һ�εĶ�λ״̬
	virtual int getPositioningState() = 0;

	//���ã���ȡ���һ�ζ�λ�ɹ�ʱ�Ķ�λ��Ϣ
	virtual bool getPositonInfo(POSITION_INFO &positionData) = 0;

	//���ã���ȡ���һ�ζ�λ�ɹ�ʱ�����Ƕ�ʱ��(��׼ʱ��)
	virtual bool getTime(SystemTime &time) = 0;

	//���ã���ȡ���һ�ζ�λ�ɹ�ʱ�Ķ�λλ��
	virtual bool getPos(POSITIONING_POS &longitude,POSITIONING_POS &latitude) = 0;

	//���ã���ȡ���һ�ζ�λ�ɹ�ʱ���ٶ�(��λm/s)
	virtual int getSpeed() = 0;

	//��ȡ���һ�ν��յ���ĳ����λ��Ϣ��ԭʼ����
	virtual bool getOriginalData(char* pPositionData, int bufLen, int infoType = POS_INFO_RMC) = 0;
};

#define g_Position (*IPositioning::instance())


#endif // _MEDIA_POSITIONING_H_
