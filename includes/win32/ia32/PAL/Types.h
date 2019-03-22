//
//  "$Id: Types.h 1171 2010-10-21 06:23:02Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_TYPES_H__
#define __PAL_TYPES_H__


/// ϵͳʱ��ṹ
typedef struct tagSYSTEM_TIME
{
	int  year;		///< �ꡣ   
	int  month;		///< �£�January = 1, February = 2, and so on.   
	int  day;		///< �ա�   
	int  wday;		///< ���ڣ�Sunday = 0, Monday = 1, and so on   
	int  hour;		///< ʱ��   
	int  minute;	///< �֡�   
	int  second;	///< �롣   
	int  isdst;		///< ����ʱ��ʶ��   
} SYSTEM_TIME;

/// ��Ƶ����ṹ
/// - ����ʾ������Ƶ���������ʱ, ʹ��ͼ��������ϵ, Ҳ������ָ��ͼ��������ϵ����Ƶ�߽�
/// ������, �ṹ��Ա��ȡֵ��ͼ�ηֱ���, ͼ�κ���Ƶ����ʱ��ƫ�ƺ����Ų���, ��ǰ�ָ�ģ
/// ʽ�ȶ��й�ϵ;
/// - ����ʾ����������Ƶ�����е�һ��������, ��ʹ���������, �����һ������ķֱ���
/// (0, 0, RELATIVE_MAX_X, RELATIVE_MAX_Y), ʹ�������������ڲ�֪��ʵ����Ƶ�ֱ��ʵ�
/// ������趨��Ƶ��������, ���Ա�֤һ��ת�������1��������. ת����ʽ����(������Է�
/// ����Ϊaw*ah):
/// ��������(ax, ay)ת�����������(rx, ry):
/// \code
/// rx = ax * RELATIVE_MAX_X / aw;
/// ry = ay * RELATIVE_MAX_Y / ah;
/// \endcode
/// �������(rx, ry)ת���ɾ�������(ax, ay):
/// \code
/// ax = rx * aw / RELATIVE_MAX_X;
/// ay = ry * ah / RELATIVE_MAX_Y;
/// \endcode
/// ��Էֱ��ʶ�������:
/// \code
/// #define RELATIVE_MAX_X 8192
/// #define RELATIVE_MAX_Y 8192
/// \endcode
///
typedef struct VIDEO_RECT
{
	unsigned short	left;			///< ���Ͻ�x���ꡣ
	unsigned short	top;			///< ���Ͻ�y���ꡣ
	unsigned short	right;			///< ���½�x���ꡣ
	unsigned short	bottom;			///< ���½�y���ꡣ
}VIDEO_RECT;

#endif
