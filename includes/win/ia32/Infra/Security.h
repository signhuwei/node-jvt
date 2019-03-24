//
//  "$Id: Security.h 4566 2012-09-26 11:21:48Z chenchangbao $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_SECURITY_H__
#define __INFRA_SECURITY_H__

typedef enum
{
	MD5_16_LOWERCASE = 0,	//16λСд��ĸ
	MD5_16_UPPERCASE,	//16λ��д��ĸ	
	MD5_32_LOWERCASE,	//32λСд��ĸ
	MD5_32_UPPERCASE,	//32λ��д��ĸ
}MD5_STYLE;

/// 3DES�����㷨
/// pResult ���ܺ�Ļ���λ�� 
///		����ĳ��� >= ((iOrigLen+7)/8)*8 
///		����iOrigLen������8�ı�������������
///	\param	pResult����ΪpOrig�����ǻḲ��ԭ�ж���
///	\param	pOrig �����ܵĻ���λ��
/// \param  iOrigLen �����ܻ��泤��
/// \param  pKey ��Կ ����16�ֽں�ֻȡǰ16�ֽ�
/// \param  iKeylen ��Կ����
/// \return : true �ɹ�, false ʧ��
bool DesEncrypt(char *pResult, char *pOrig, long iOrigLen, const char *pKey, int iKeylen);


/// 3DES�����㷨
/// \param [out] Result ���ܺ�Ļ���λ��
/// \param [in]pOrig �����ܵĻ���λ��
/// \param  iOrigLen �����ܻ��泤��
/// \param  pKey ��Կ
/// \param  iKeylen ��Կ����
/// \return : true �ɹ�, false ʧ��
bool DesDecrypt(char *pResult, char *pOrig, long iOrigLen, const char *pKey, int iKeylen);


/// MD5�����㷨
/// \param [out] strOutput ���ܺ������
/// \param [in] strInput Ҫ���ܵ�����
void MD5Encrypt(signed char *strOutput, unsigned char *strInput);


/// MD5�����㷨
/// \param [out] strOutput ���ܺ������
/// \param [in] strInput Ҫ���ܵ�����
// \param [int] mode MD5_STYLE ��������ĸ�ʽ
void MD5EncryptV2(signed char *strOutput, unsigned char *strInput, int mode);


/// Blowfish�����㷨
/// \param [out] sSrc Ҫ���ܵ�����
/// \param [in] sDst ���ܺ������
bool BlowfishEncrypt(const char *sSrc,char *sDst, bool bAccOrPas);


/// Blowfish�����㷨
/// \param [out] sSrc Ҫ���ܵ�����
/// \param [in] sDst ���ܺ������
bool BlowfishDecrypt(const char *sSrc,char *sDst, bool bAccOrPas);

#endif
