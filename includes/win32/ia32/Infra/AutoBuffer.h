//
//  "$Id: AutoBuffer.h 131 2009-11-14 06:12:32Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang XiongMai Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_AUTOBUFFER_H__
#define __INFRA_AUTOBUFFER_H__

#include "Referable.h"

class CAutoBuffer : public IReferable
{
	friend class IReferable;
public:
	typedef CReferableObj<CAutoBuffer> IBufferRef;

	//创建以缓冲区aBuffer为内容的自维护缓存，isbackup表示内部是否复制一份
	//如果部分管理，必须复制，如果全部管理，可不复制,并接管外部缓存区；复制后不再管理外部缓冲区
	static CAutoBuffer * CreateBuffer(char * aBuffer,  int nSize, bool backup = false);

	virtual ~CAutoBuffer(void);

	char * GetBuf();
	unsigned int BufferSize();

private:
	CAutoBuffer(void);
	bool SetBuf( int nSize, char * aBuffer = 0 );
	bool CopyBuf( int nSize, const char * aBuffer );

	char * m_buff;
	unsigned int m_datalen;
};

#endif
