//
//  "$Id: Mutex.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_MUTEX_H__
#define __PAL_MUTEX_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup MutexAPI API Mutex
/// ������API����װ�˲�ͬ����ϵͳ�Ļ���������
///	\n ��������ͼ:
/// \code
///    ===========================
///                |
///           RWMutexCreate
///                |-------------------+
///      ReadMutexEnter,ReadMutexEnter  |
///                |------------+
///           RWMutexDestory
///                |
///    ===========================
/// \endcode
/// @{


/// ������д����
/// 
/// \param [out] phMutex ��д�������ɹ�ʱ�������Ķ�д�������
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int RWMutexCreate(void * *phMutex);


/// ���ٶ�д����
/// 
/// \param [in] hMutex ��д�������
/// \retval 0  ���ٳɹ�
/// \retval <0 ����ʧ��
int RWMutexDestory(void * hMutex);


/// ������ٽ�����
/// 
/// \param [in] hMutex ��д�������
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int ReadMutexEnter(void * hMutex);


/// ����д�ٽ�����
/// 
/// \param [in] hMutex ��д�������
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int WriteMutexEnter(void * hMutex);

/// �뿪���ٽ�����
/// 
/// \param [in] hMutex ��д�������
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int ReadMutexLeave(void * hMutex);

/// �뿪д�ٽ�����
/// 
/// \param [in] hMutex ��д�������
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int WriteMutexLeave(void * hMutex);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
