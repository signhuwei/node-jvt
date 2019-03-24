//
//  "$Id: Memory.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_MEMORY_H__
#define __PAL_MEMORY_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup MemoryAPI API Memory
/// 内存管理API，用来来支持内存块的页式管理及多线程共享。此接口比较特殊，它是由
///	上层实现，底层如果需要申请/释放可以和应用层交互的内存块， 一定要使用这套接口。
///	\n 调用流程图:
/// \code
///    ===========================
///                |
///           MemoryAlloc
///   +------------|            
///   |     MemorySetLength 
///   |      MemoryAddRef  
///   |      MemoryRelease  
///   +------------|             
///    ===========================
/// \endcode
/// @{

typedef struct MEMORY_BLOCK
{
	/// 内存块句柄。
	void *		handle;

	/// 内存块的缓冲指针。
	unsigned char*		ptr;

	/// 32字节头，用来放额外的数据。
	unsigned char*		header;

	/// 内存块的缓冲有效字节数。
	unsigned int		length;	

	/// 实际申请到的缓冲最大字节数，一定是2nKbytes，n为整数。且指针的地址以1Kbytes
	/// 为单位对齐。
	unsigned int		size;

	/// 下一个结构指针，仅供底层使用。
	struct MEMORY_BLOCK *next;

	/// 上一个结构指针，仅供底层使用。
	struct MEMORY_BLOCK *prev;

	/// 标志1，仅供底层使用。
	unsigned int		flag1;

	/// 标志2，仅供底层使用。
	unsigned int		flag2;
}MEMORY_BLOCK;


/// 申请内存块。
/// 
/// \param [out] pBlock 指向内存块结构MEMORY_BLOCK的指针。
/// \param [in] dwBytes 需要申请的内存块的字节数.
/// \retval 0  申请成功
/// \retval <0  申请失败
int MemoryAlloc(MEMORY_BLOCK * pBlock, unsigned int dwBytes);


/// 设置内存块内实际数据的长度。
/// 
/// \param [in] hMemory 内存块句柄。 
/// \param [in] dwBytes 内存块内实际数据的长度。
/// \retval 0  读成功
/// \retval <0  读失败
int MemorySetLength(void *hMemory, unsigned int dwBytes);


/// 增加内存块的引用计数。
/// 
/// \param [in] hMemory 内存块句柄。
/// \retval 0  增加成功
/// \retval <0  增加失败
int MemoryAddRef(void *hMemory);


/// 释放内存块。内存块得到后初始引用计数为1，一次调用MemoryAddRef即可释放。如果
/// 引用计数被增加过，则还需要释放对应的次数，内存块才真正被释放。
/// 
/// \param [in] hMemory 内存块句柄。
/// \retval 0  释放成功
/// \retval <0  释放失败
int MemoryRelease(void * hMemory);


/// 申请额外内存块，参考malloc。
/// 
/// \param [in] nSize 需要申请的内存块的字节数.
/// \retval 0  申请失败
/// \retval !0 申请到的内存块的指针
void *ExtraMemoryAlloc(int nSize);


/// 释放额外内存块，参考free。
/// 
/// \param [in] pBuf 需要释放的内存块的指针.
/// \return无
void ExtraMemoryFree(void *pBuf);

/// @}

#ifdef __cplusplus
}
#endif

#endif 
