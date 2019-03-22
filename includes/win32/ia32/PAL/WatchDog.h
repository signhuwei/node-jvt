//
//  "$Id: WatchDog.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_WATCHDOG_H__
#define __PAL_WATCHDOG_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup WatchDogAPI API Watch Dog
/// ���Ź�API����Ӳ�������ʵ��ϵͳ�Ĺ��ϴ���.
/// @{

/// �������Ź��豸
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int WatchdogCreate(void);

/// ���ٿ��Ź��豸
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 ���ٳɹ�
int WatchdogDestory(void);

/// ι��
/// \param [in] data Ҫд�����ݻ����ַ
/// \param [in] nBytes д�������
/// \return 0 д��ɹ�
/// \return < 0 д��ʧ��
int WatchdogWrite(void* pdata, unsigned int nBytes);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
