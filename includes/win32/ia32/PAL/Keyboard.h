//
//  "$Id: Keyboard.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_KEYBOARD_H__
#define __PAL_KEYBOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup KeyboardAPI API Keyboard
/// ����API��
///	\n ��������ͼ:
/// \code
///    ===========================
///                |
///           KeyboardCreate
///                |-----------------------------+
///           KeyboardGetData  KeyboardGetData   |
///                |-----------------------------+
///           KeyboardDestory
///                |
///    ===========================
/// \endcode
/// @{


/// ����������ݽṹ
typedef struct KEYBOARD_DATA
{
	/// ������Ϣ����
	unsigned long	msg;

	/// ������Ϣ����
	unsigned long	wpa;
	
	/// ������Ϣ��ֵ
	unsigned long lpa;
	
} KEYBOARD_DATA;


/// ��������豸
/// 
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int KeyboardCreate(void);


/// ��������豸
/// 
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 ���ٳɹ�
int KeyboardDestory(void);


/// һֱ�ȵ�����һ�������ļ����¼��ŷ��أ���������������������豻�ε��򲻴��ڣ�
/// �������ش��󡣳���ʱӦ�ó�����Ҫ��ʱ���ԣ����ڲ�С��500ms����ʵ���Ȳ�ι��ܡ�
/// 
/// \param [out] pData ָ������¼��ṹKEYBOARD_DATA��ָ�롣
/// \param [in/out] iMax �����������Ϣ����������ȡ������Ϣ����
/// \retval 0 ���ɹ�
/// \retval <0 ��ʧ��
int KeyboardGetData(KEYBOARD_DATA * pData, int *iMax);


/// д���������
/// \param [in] pData ָ������¼��ṹKEYBOARD_DATA��ָ��
/// \retval 0 д�ɹ�
/// \retval <0 дʧ�� 
int KeyboardSetData(const KEYBOARD_DATA *pData);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
