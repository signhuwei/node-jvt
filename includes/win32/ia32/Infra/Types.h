//
//  "$Id: Types.h 10309 2013-12-02 02:31:44Z chenbo $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//


#ifndef __INFRA_TYPES_H__
#define __INFRA_TYPES_H__
#include <memory.h>

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

#define	MAX_MSK_SIZE 16 //掩码数组的大小
#define TP_TIMER		 2		//1
#define trace printf

#define BITMSK(bit)				(int)(1 << (bit))
#define BITMSKC(bit)			(uchar)(1 << ((bit)%8))

void ArrayBitTrue(uchar *mask, int index);//数组对应位置1
//{
	//mask[index>>3] |= BITMSKC(index);
//}

void ArrayBitFalse(uchar *mask, int index);//数组对应位置0
//{
	//mask[index>>3] &= ~BITMSKC(index);
//}

void ArrayOrBoth(uchar *maskd, uchar *masks1,const uchar *masks2, int size);//得到两个数组相与的结果
//{
	//int i=0;
	//for(;i<size;i++)
	//{
		//maskd[i]=masks1[i]|masks2[i];
	//}
//}

void ArrayXorBoth(uchar *maskd, uchar *masks1,uchar *masks2, int size);//得到两个数组异或的结果
//{
	//int i=0;
	//for(;i<size;i++)
	//{
		//maskd[i]=masks1[i]^masks2[i];
	//}
//}

void ArrayAndBoth(uchar *maskd, uchar *masks1,uchar *masks2, int size);//得到两个数组异或的结果
//{
	//int i=0;
	//for(;i<size;i++)
	//{
		//maskd[i]=masks1[i]&masks2[i];
	//}
//}

void ArrayNot(uchar *mask,int size);//数组取反操作
//{
	//int i=0;
	//for(;i<size;i++)
	//{
		//mask[i]= ~mask[i];
	//}
//}

int GetArrayBitAnd(const uchar *mask, int index);//判断数组对应位是否为1
//{
	//return mask[index>>3]&BITMSKC(index);
//}

void ArrayBitXOR(uchar *mask, int index);//数组对应进行异或操作
//{
	//mask[index>>3] ^= BITMSKC(index);
//}

int GetArrayBitXOR(const uchar *mask, int index);//判断数组的对应位的异或结果
//{
	//return mask[index>>3]^BITMSKC(index);
//}

int GetArrayClear(const uchar *mask);//判断数组是否为空
//{
	//uchar tmp_mask[MAX_MSK_SIZE]={0};
	//return memcmp(mask,tmp_mask,sizeof(tmp_mask));
//}

#endif
