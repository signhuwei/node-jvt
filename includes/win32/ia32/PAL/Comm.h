//
//  "$Id: Comm.h 2431 2011-12-22 07:01:54Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_COMM_H__
#define __PAL_COMM_H__

#include "Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup CommAPI API Comm
/// ��׼�Ĵ���ͨѶ�ӿڣ�֧��RS232,RS485,ǰ�����豸
/// \n ��������ͼ:
/// \code
///    =========================================
///                   |                         
///              createCommPort                  
///                   |                         
///                addRef                  
///       +-----------|	          
///       |      setAttribute  	
///       |		      |    	
///       |           |           	 
///       |         open    
///       | +---------|      
///       | |       read    
///       | |       write   
///       | |       purge   
///       | +---------|      	
///       |         close   
///       +-----------|
///                release                  
///                   |                         
///    =========================================
/// \endcode
/// @{

/// ���ڲ����ж�����
typedef enum CommPurgeFlags
{
	commPurgeTxAbort = 0x0001,	///< ��ֹд����
	commPurgeRxAbort = 0x0002,	///< ��ֹ������
	commPurgeTxClear = 0x0004,	///< ����������
	commPurgeRxClear = 0x0008 	///< ������뻺��
} CommPurgeFlags;

/// ����ֹͣλ����
typedef enum CommStopBit
{
	commOneStopBit = 0,		///< 1 stop bit
	commOne5StopBits,		///< 1.5 stop bit
	commTwoStopBits			//< 2 stop bit
} CommStopBit;

/// ����У��λ����
typedef enum CommParityType 
{
	commNoParity = 0,	///< No parity
	commOddParity,		///< Odd parity
	commEvenParity,		///< Even parity
	commMarkParity,		///< Mark parity
	commSpaceParity		///< Space parity
} CommParityType;

/// ����ģʽ
typedef enum CommMode
{
	commFullDuplex = 0,	///< ȫ˫��
	commSemiDuplex,		///< ��˫��
} CommMode;

/// ���������ṹ��128�ֽ�
typedef struct CommCaps
{
	CommMode mode;		///< ����ģʽ
	int reserved[31];	///< �����ֽ�
} CommCaps;

/// �������Խṹ��128�ֽ�
typedef struct CommAttribute
{
	int		baudrate;	///< ʵ�ʵĲ�����ֵ��		
	char	dataBits;	///< ʵ�ʵ�����λ ȡֵΪ5,6,7,8	
	char	parity;		///< ��żУ��ѡ�ȡCommParityType���͵�ö��ֵ��	
	char	stopBits;	///< ֹͣλ����ȡCommStopBit���͵�ö��ֵ��	
	char	resv;		///< �����ֽ�
	int		reserved[30];///< �����ֽ�
} CommAttribute;



/// ���ڽӿ������ṹ��128�ֽ�
typedef struct CommPortDesc
{
	int port;			///< ����˿ں�
	int reserved[31];	///< �����ֽ�
} CommPortDesc;


/// �������ڽӿ�
///
/// \param [in] desc ���ڽӿ������ṹCommPortDescָ��
/// \param [out] commPort ���ڽӿ�ָ���ָ��
/// \retval 0  ���ӳɹ���
/// \retval <0  ����ʧ�ܡ�


/// �õ�������Ŀ
///
/// \retval ������Ŀ��
int getCommPortCount();

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
