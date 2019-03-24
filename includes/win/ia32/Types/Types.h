//
//  "$Id: Types.h 2046 2011-10-11 04:45:24Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//


#ifndef __XC_TYPES_H__
#define __XC_TYPES_H__

#include "Infra/Types.h"

//////////////////////////////////////////////////////////////////////////
// base types definition
// compilers should be restricted to ensure the following equalities!

#ifndef __SMALL_FILE_TIME_DEFINED__
#define __SMALL_FILE_TIME_DEFINED__
//ʱ��ṹ
typedef struct _DATETIME								
{
#ifdef __BIG_ENDIAN__
	uint year		:6;				//	��	2000-2063	
	uint month		:4;				//	��	1-12		
	uint day		:5;				//	��	1-31		
	uint hour		:5;				//	ʱ	0-23		
	uint minute		:6;				//	��	0-59		
	uint second		:6;				//	��	0-59	
#else
	uint second		:6;				//	��	0-59		
	uint minute		:6;				//	��	0-59		
	uint hour		:5;				//	ʱ	0-23		
	uint day		:5;				//	��	1-31		
	uint month		:4;				//	��	1-12		
	uint year		:6;				//	��	2000-2063	
#endif
}DateTime,*pDATETIME;

#endif

typedef union {	//IP addr
	uchar	c[4];
	ushort	s[2];
	uint	l;
} IPAddress;

#include "GDI/Types.h"
//#ifndef _WIN32_STIMULATE

// 	typedef struct {
// 		int left;
// 		int top;
// 		int right;
// 		int bottom;
// 	}RECT;

//#endif

#endif
