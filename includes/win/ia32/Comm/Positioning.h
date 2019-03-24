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
	POS_INFO_GSA,	//当前卫星信息
	POS_INFO_GSV,	//可见卫星信息
	POS_INFO_GGA,	//GPS定位信息
	POS_INFO_RMC,	//推荐定位信息
	POS_INFO_VTG,	//地面速度信息
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
	POSITIONING_OK,      //定位成功
	POSITIONING_FAILED,  //定位失败，未收到卫星信号
	POSITIONING_NO_DATA, //串口配置错误或GPS设备故障
	POSITIONING_INVALIDE,
};


struct POSITIONING_POS//经纬度
{
	int  degree;     //以(度/1000)为单位
	char direction;  //方位 取值如枚举值POSITIONING_DIRECTION所示
	char res[3];
};

struct POSITION_INFO
{
	SystemTime        time;	//时间
	POSITIONING_POS   longitude;	//经度
	POSITIONING_POS   latitude;	//纬度
	int               speed;		//速度, 单位m/h
	char              res[16];
};


class IPositioning
{
public:
	static IPositioning* instance();

	//作用：对GPS信息进行解析(要求pData中有完整的GPS数据)
	//返回：解析成功的命令数
	virtual int parse(const uchar* pData, int len) = 0;

	//作用：获取最近一次的定位状态
	virtual int getPositioningState() = 0;

	//作用：获取最近一次定位成功时的定位信息
	virtual bool getPositonInfo(POSITION_INFO &positionData) = 0;

	//作用：获取最近一次定位成功时的卫星端时间(标准时间)
	virtual bool getTime(SystemTime &time) = 0;

	//作用：获取最近一次定位成功时的定位位置
	virtual bool getPos(POSITIONING_POS &longitude,POSITIONING_POS &latitude) = 0;

	//作用：获取最近一次定位成功时的速度(单位m/s)
	virtual int getSpeed() = 0;

	//获取最近一次接收到的某条定位信息的原始数据
	virtual bool getOriginalData(char* pPositionData, int bufLen, int infoType = POS_INFO_RMC) = 0;
};

#define g_Position (*IPositioning::instance())


#endif // _MEDIA_POSITIONING_H_
