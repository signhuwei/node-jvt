//
//  "$Id: Frontboard.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_FRONTBOARD_H__
#define __PAL_FRONTBOARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup FrontboardAPI API Frontboard
/// ǰ������API�����ں͸���ǰ��������豸ͨѶ����ȡ��ֵ����ָʾ�ƿ������
/// ����USB�ӿ��ϵı�׼104�������������̼�ֵת����Ҳ����ͨ������ӿڷ���������
/// \n ��������ͼ:
/// \code
///    =========================================
///                   |                         
///              FrontboardCreate                  
///         +---------|      
///         |    FrontboardRead    
///         |    FrontboardWrite   
///         +---------|      	
///             FrontboardDestory                  
///                   |                         
///    =========================================
/// \endcode
/// @{


/// ����ǰ����豸
/// 
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int FrontboardCreate(void);


/// ����ǰ����豸
/// 
/// \param ��
/// \retval <0 ����ʧ��
/// \retval 0 ���ٳɹ�
int FrontboardDestory(void);


/// ��ǰ������ݣ�һֱ�ȵ�����ָ�����ֽڻ����ʱ�ŷ��أ�����������
/// 
/// \param [out] pData ���ݻ����ָ�롣
/// \param [in] nBytes Ҫ�������ֽ���
/// \return>0  �������ֽ���
/// \retval <=0 ��ʧ��
int FrontboardRead(void* pData, unsigned int nBytes);


/// дǰ������ݣ�һֱ�ȵ�д��ָ�����ֽڻ����ʱ�ŷ��أ�����������
/// 
/// \param [in] pData ���ݻ����ָ�롣
/// \param [in] nBytes Ҫд����ֽ���
/// \return>0  д����ֽ���
/// \retval <=0  дʧ��
int FrontboardWrite(void* pData, unsigned int nBytes);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
