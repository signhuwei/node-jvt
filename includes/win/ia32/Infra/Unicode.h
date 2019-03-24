//
//  "$Id: Unicode.h 131 2009-11-14 06:12:32Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_UNICODE_H__
#define __INFRA_UNICODE_H__

/*
 * linux/fs/nls_cp936.c
 *
 * Charset cp936 translation tables.
 * This translation table was generated automatically, the
 * original table can be download from the Microsoft website.
 * (http://www.microsoft.com/typography/unicode/unicodecp.htm)
 */
#include "Types.h"

int UniTGb2312(unsigned short* pUnicode,int nUnicLen, char* pStr,int nStrLen);

int Gb2312ToUni(char* pSource,unsigned short* pTag,int nLenTag);

int Gb2312TUtf8(char* pSource,unsigned char* pUtf8,int nUtf8Len);

int utf8TGb2312(unsigned char* putf8,char* pStr,int nUtf8Len,int nStrLen);

int uni2char(const ushort uni,unsigned char *out, int boundlen);

int char2uni(const unsigned char *rawstring, int boundlen,ushort *uni);

int utf8_mbtowc(ushort *p, const uchar *s, int n);

int utf8_mbstowcs(ushort *pwcs, const uchar *s, int n);

int utf8_wctomb(uchar *s, ushort wc, int maxlen);


int utf8_wcstombs(uchar *s, const ushort *pwcs, int maxlen);

#endif
