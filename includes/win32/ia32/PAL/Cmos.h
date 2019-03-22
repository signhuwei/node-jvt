//
//  "$Id: Cmos.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_CMOS_H__
#define __PAL_CMOS_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup CMOSAPI API CMOS
/// CMOS����API��Ӧ�ó���ʹ��CMOS��������ʷǳ�Ƶ������ʵʱ�Խϸߵ����ݡ�
/// ռ��32�ֽ�, һ��ʹ��RTCоƬ�Ĵ洢����
/// @{


/// ��CMOS�ж����ݡ�
/// 
/// \param [in] offs ��������ֽ�ƫ�ơ�
/// \param [out] pdat �������ն������ݵĻ��塣
/// \param [in] len Ҫ�������ֽ�����
/// \retval 0  �ɹ�
/// \retval <0  ʧ��
int CMOSRead(int offs, void * pdat, int len);


/// д���ݵ�CMOS��
/// 
/// \param [in] offs д�����ֽ�ƫ�ơ�
/// \param [in] pdat ��д������ݵĻ��塣
/// \param [in] len Ҫд����ֽ�����
/// \retval 0  �ɹ�
/// \retval <0  ʧ��
int CMOSWrite(int offs, void * pdat, int len);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
