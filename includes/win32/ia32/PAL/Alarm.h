//
//  "$Id: Alarm.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_ALARM_H__
#define __PAL_ALARM_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup AlarmAPI API Alarm
/// ������������˿ڣ����ڣ���ʹ�ã������ⲿ��ƽ������ߴ����̵��������ⲿ��·��
///	\n ��������ͼ:
/// \code
///    ===========================
///                |
///   *AlarmGetInSlots,AlarmGetOutSlots
///                |
///           AlarmCreate
///                |------------+
///       AlarmRead,AlarmWrite  |
///                |------------+
///           AlarmDestory
///                |
///    ===========================
/// \endcode
/// @{


/// �õ������˿ڵ�����ͨ����Ŀ��
/// \return �����˿ڵ�����ͨ����Ŀ
int AlarmGetInSlots(void);

/// �õ������˿ڵ����ͨ����Ŀ��
/// \return �����˿ڵ����ͨ����Ŀ
int AlarmGetOutSlots(void);

/// ���������豸
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int AlarmCreate(void);

/// ���ٱ����豸
/// \retval <0 ����ʧ��
/// \retval 0 ���ٳɹ�
int AlarmDestory(void);

/// ����������״̬��״̬�ı�ʱ�����ʱ���أ�����������
/// \param [out] pData ָ��һ��unsigned intֵ��ָ�룬unsigned intֵ�Ǹ�����������ͨ����ƽ״̬�����롣
///	       ��ͨ���ڵ�λ����ͨ���ڸ�λ���ߵ�ƽ��1���͵�ƽ��0�������ڵ�ͨ����0��
/// \retval >0  �������ֽ���
/// \retval <=0 ��ʧ��
int AlarmRead(unsigned int* pData);

/// д��ȡ�������״̬��
/// \param [in] pData ָ��һ��unsigned intֵ��ָ�룬unsigned intֵ�Ǹ����������ͨ�������롣��ͨ����
///	       ��λ����ͨ���ڸ�λ����1����ߵ�ƽ����0����͵�ƽ�������ڵ�ͨ��λ��Ч��
/// \return >0  д����ֽ���
/// \retval <=0 дʧ��
int AlarmWrite(unsigned int* pData);

/// ��λ����ģ��
/// \param [out] iValue �ߵ�ƽ��1���͵�ƽ��0��
/// \retval <0 ��λʧ��
/// \retval 0 ��λ�ɹ�
int ExDeviceReset(unsigned int iValue);

/// ��ȡ����ģ��GPIO�˿�״̬
/// \param [out] pData ָ��һ��uintֵ��ָ�룬uintֵ�Ǹ���GPIO�˿ڵ�ƽ״̬�����롣
///        ��ͨ���ڵ�λ����ͨ���ڸ�λ���ߵ�ƽ��1���͵�ƽ��0�������ڵ�ͨ����0��
///        Ŀǰ4·���豸ֻ��һ��GPIO�˿ڣ���bit0��ʾ
/// \retval 0  �ɹ�
/// \retval <0 ��ʧ��
int ExDeviceRead(unsigned int* pData);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif

