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
	MD5_16_LOWERCASE = 0,	//16位小写字母
	MD5_16_UPPERCASE,	//16位大写字母	
	MD5_32_LOWERCASE,	//32位小写字母
	MD5_32_UPPERCASE,	//32位大写字母
}MD5_STYLE;

/// 3DES加密算法
/// pResult 加密后的缓存位置 
///		缓存的长度 >= ((iOrigLen+7)/8)*8 
///		即比iOrigLen大，且是8的倍数的最少整数
///	\param	pResult可以为pOrig，但是会覆盖原有东西
///	\param	pOrig 待加密的缓存位置
/// \param  iOrigLen 待加密缓存长度
/// \param  pKey 密钥 超过16字节后只取前16字节
/// \param  iKeylen 密钥长度
/// \return : true 成功, false 失败
bool DesEncrypt(char *pResult, char *pOrig, long iOrigLen, const char *pKey, int iKeylen);


/// 3DES解密算法
/// \param [out] Result 解密后的缓存位置
/// \param [in]pOrig 待解密的缓存位置
/// \param  iOrigLen 待解密缓存长度
/// \param  pKey 密钥
/// \param  iKeylen 密钥长度
/// \return : true 成功, false 失败
bool DesDecrypt(char *pResult, char *pOrig, long iOrigLen, const char *pKey, int iKeylen);


/// MD5加密算法
/// \param [out] strOutput 加密后的秘文
/// \param [in] strInput 要加密的秘文
void MD5Encrypt(signed char *strOutput, unsigned char *strInput);


/// MD5加密算法
/// \param [out] strOutput 加密后的秘文
/// \param [in] strInput 要加密的秘文
// \param [int] mode MD5_STYLE 加密输出的格式
void MD5EncryptV2(signed char *strOutput, unsigned char *strInput, int mode);


/// Blowfish解密算法
/// \param [out] sSrc 要加密的秘文
/// \param [in] sDst 加密后的秘文
bool BlowfishEncrypt(const char *sSrc,char *sDst, bool bAccOrPas);


/// Blowfish加密算法
/// \param [out] sSrc 要加密的秘文
/// \param [in] sDst 加密后的秘文
bool BlowfishDecrypt(const char *sSrc,char *sDst, bool bAccOrPas);

#endif
