//
//  "$Id: Flash.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_FLASH_H__
#define __PAL_FLASH_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup FLASH API
/// Flash�豸���ʽӿڣ��������������ڴ˹���
///	\n ��������ͼ
/// \code
///    ===========================
///                |
///            FlashInit
///                |
///           FlashGetSectorSize
///                |-------------+
///            FlashRead         |
///            FlashErase        |
///            FlashWrite        |
///                |-------------+
///           FlashGetSectorSize
///                |
///    ===========================
/// \endcode
/// @{

/// \defgroup FlashAPI API Flash
/// Flashֱ�ӷ���API����ЩӦ�ó���������ʹ��lua���Ƶģ�lua�ű�ͨ��ֱ�ӷ���flash��
///	����ӳ���ļ���
/// \note ����FlashGetSectorSize��FlashGetClientArea��ʱδʹ�á�
/// @{

/// ��ʼ��Flash����
/// \return 0 ��ʼ���ɹ�
/// \return < 0��ʼ��ʧ��
int FlashInit(void);

/// ����Flash�ϵ�����
/// 
/// \param [out] buf �������ն������ݵĻ��塣
/// \param [in] addr �����������ƫ�ơ�
/// \param [in] cnt Ҫ�������ݵ���������
/// \retval 0  ���ɹ�
/// \retval <0  ��ʧ��
int	FlashRead(unsigned char *buf, unsigned long addr, unsigned long cnt);

/// ����Flash�ϵ�����
/// \param [in] addr �����豸�ĵ�ַ
/// \return 0 �����ɹ�
/// \return -1 ����ʧ��
int	 FlashErase(unsigned long addr);

/// ������д��Flash
/// 
/// \param [out] buf ��д������ݵĻ��塣
/// \param [in] addr д��������ƫ�ơ�
/// \param [in] cnt Ҫд�����ݵ���������
/// \retval 0  д�ɹ�
/// \retval <0  дʧ��
int	FlashWrite(unsigned char *buf, unsigned long addr, unsigned long cnt);

/// �õ�Flash������������С��
/// 
/// \param [out] size һ�������������ֽ���
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int FlashGetSectorSize(unsigned long *size);

/// ����Flash�豸����
/// \return 0 �����豸���ʳɹ�
/// \return < 0 ����ʧ��
int FlashDestroy(void);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif //__FLASH_API_H__

