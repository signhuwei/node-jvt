//
//  "$Id: Types.h 131 2009-11-14 06:12:32Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//


#ifndef __INFRA_TYPES_H__
#define __INFRA_TYPES_H__

//////////////////////////////////////////////////////////////////////////
// base types definition
// compilers should be restricted to ensure the following equalities!
typedef signed char							schar;		///< sizeof(uchar) == sizeof(schar) == sizeof(char) == 1
typedef unsigned char						uchar;	
typedef unsigned int						uint;			///< sizeof(uint) == sizeof(int) == 4
typedef unsigned short					ushort;		///< sizeof(ushort) == sizeof(short) == 2
typedef unsigned long						ulong;		///< sizeof(ulong) == sizeof(long) == 4
#ifdef WIN32
	typedef __int64								int64;		///< sizeof(int64) == sizeof(uint64) == 8
	typedef unsigned __int64			uint64;
#elif defined(__GNUC__)
	typedef unsigned long long		int64;
	typedef long long							uint64;
#endif

// Join two variables
#define MACRO_JOIN( X, Y ) MACRO_DO_JOIN( X, Y )
#define MACRO_DO_JOIN( X, Y ) MACRO_DO_JOIN2(X,Y)
#define MACRO_DO_JOIN2( X, Y ) X##Y

#define DISABLE_COPY(Class) \
	Class(const Class &); \
	Class &operator=(const Class &);

#define TP_TIMER		 2		//1
#define trace printf

#define BITMSK(bit)				(int)(1 << (bit))

#endif
