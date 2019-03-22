//
//  "$Id: Ptz.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_PTZ_H__
#define __PAL_PTZ_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup PTZAPI API PTZ
/// ��̨�豸ͨѶ�ӿڡ�
/// \n ��������ͼ:
/// \code
///    =========================================
///                   |                         
///              PtzCreate                  
///       +-----------|	          
///       |     PtzSetAttribute  	
///       |           |           	 
///       |      PtzOpen    
///       | +---------|      
///       | |    PtzRead    
///       | |    PtzWrite   
///       | +---------|      	
///       |      PtzClose   
///       +-----------|
///             PtzDestory                  
///                   |                         
///    =========================================
/// \endcode
/// @{

/// ��̨�豸����
typedef struct PTZ_ATTR
 {
	unsigned int	baudrate;		
	unsigned char	databits;
	unsigned char	parity;
	unsigned char	stopbits;	
	unsigned char	reserved;
} PTZ_ATTR;


/// ������̨�豸
/// 
/// \param	��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int PtzCreate(void);


/// ������̨�豸
/// 
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 ���ٳɹ�
int PtzDestory(void);

	
/// ����̨�豸��
/// 
/// \param ��
/// \retval 0  �򿪳ɹ�
/// \retval <0  ��ʧ��
int PtzOpen(void);


/// ������̨�豸���ԡ�
/// 
/// \param [in] pattr ��̨���ԽṹPTZ_ATTRָ�롣
/// \retval 0  ���óɹ�
/// \retval <0  ����ʧ��
int PtzSetAttribute(PTZ_ATTR *pattr);


/// �ر���̨�豸����ǰ��д�����������ء�
/// 
/// \param ��
/// \retval 0  �رճɹ�
/// \retval <0  �ر�ʧ��
int PtzClose(void);


/// д��̨�������һֱ�ȵ�д��ָ�����ֽڻ����ʱ�ŷ��أ�����������
/// 
/// \param [in] pData ���ݻ����ָ�롣
/// \param [in] len Ҫд����ֽ���
/// \retval >0  д����ֽ���
/// \retval <=0 дʧ��
int PtzWrite(void* pData, unsigned int len);


/// ����̨���ݣ�һֱ�ȵ�����ָ�����ֽڻ����ʱ�ŷ��أ�����������
/// 
/// \param [in] pData ���ݻ����ָ�롣
/// \param [in] len Ҫ�������ֽ���
/// \return >0  �������ֽ���
/// \retval <=0 ��ʧ��
int PtzRead(void* pData, unsigned int len);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
