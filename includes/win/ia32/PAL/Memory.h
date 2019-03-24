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
/// �ڴ����API��������֧���ڴ���ҳʽ�������̹߳����˽ӿڱȽ����⣬������
///	�ϲ�ʵ�֣��ײ������Ҫ����/�ͷſ��Ժ�Ӧ�ò㽻�����ڴ�飬 һ��Ҫʹ�����׽ӿڡ�
///	\n ��������ͼ:
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
	/// �ڴ������
	void *		handle;

	/// �ڴ��Ļ���ָ�롣
	unsigned char*		ptr;

	/// 32�ֽ�ͷ�������Ŷ�������ݡ�
	unsigned char*		header;

	/// �ڴ��Ļ�����Ч�ֽ�����
	unsigned int		length;	

	/// ʵ�����뵽�Ļ�������ֽ�����һ����2nKbytes��nΪ��������ָ��ĵ�ַ��1Kbytes
	/// Ϊ��λ���롣
	unsigned int		size;

	/// ��һ���ṹָ�룬�����ײ�ʹ�á�
	struct MEMORY_BLOCK *next;

	/// ��һ���ṹָ�룬�����ײ�ʹ�á�
	struct MEMORY_BLOCK *prev;

	/// ��־1�������ײ�ʹ�á�
	unsigned int		flag1;

	/// ��־2�������ײ�ʹ�á�
	unsigned int		flag2;
}MEMORY_BLOCK;


/// �����ڴ�顣
/// 
/// \param [out] pBlock ָ���ڴ��ṹMEMORY_BLOCK��ָ�롣
/// \param [in] dwBytes ��Ҫ������ڴ����ֽ���.
/// \retval 0  ����ɹ�
/// \retval <0  ����ʧ��
int MemoryAlloc(MEMORY_BLOCK * pBlock, unsigned int dwBytes);


/// �����ڴ����ʵ�����ݵĳ��ȡ�
/// 
/// \param [in] hMemory �ڴ������ 
/// \param [in] dwBytes �ڴ����ʵ�����ݵĳ��ȡ�
/// \retval 0  ���ɹ�
/// \retval <0  ��ʧ��
int MemorySetLength(void *hMemory, unsigned int dwBytes);


/// �����ڴ������ü�����
/// 
/// \param [in] hMemory �ڴ������
/// \retval 0  ���ӳɹ�
/// \retval <0  ����ʧ��
int MemoryAddRef(void *hMemory);


/// �ͷ��ڴ�顣�ڴ��õ����ʼ���ü���Ϊ1��һ�ε���MemoryAddRef�����ͷš����
/// ���ü��������ӹ�������Ҫ�ͷŶ�Ӧ�Ĵ������ڴ����������ͷš�
/// 
/// \param [in] hMemory �ڴ������
/// \retval 0  �ͷųɹ�
/// \retval <0  �ͷ�ʧ��
int MemoryRelease(void * hMemory);


/// ��������ڴ�飬�ο�malloc��
/// 
/// \param [in] nSize ��Ҫ������ڴ����ֽ���.
/// \retval 0  ����ʧ��
/// \retval !0 ���뵽���ڴ���ָ��
void *ExtraMemoryAlloc(int nSize);


/// �ͷŶ����ڴ�飬�ο�free��
/// 
/// \param [in] pBuf ��Ҫ�ͷŵ��ڴ���ָ��.
/// \return��
void ExtraMemoryFree(void *pBuf);

/// @}

#ifdef __cplusplus
}
#endif

#endif 
