//
//  "$Id: Cursor.h 2863 2012-03-26 09:18:37Z chenchangbao $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_CURSOR_H__
#define __GDI_CURSOR_H__

#include "Types.h"
#include <string>

class ICursor
{
public:

	/// �����״ö������
	enum Shape
	{
		shapeNormal,	///< ��ͨ
		shapeBusy,		///< æ
		shapeWait,		///< �ȴ�
		shapeMove,		///< �ƶ�
		shapeSize1,		///< ��б�϶�
		shapeSize2,		///< ��б�϶�
		shapeSize3,		///< �����϶�
		shapeSize4,		///< �����϶�
		shapeZoomin,	///< �Ŵ�
		shapeNr			///< ȫ��
	};

	/// ������
	static ICursor* instance();

	/// ����������
	virtual ~ICursor();

	/// ���ع��
	/// \param [in] path Ҫ���صĹ���ļ�·��(.ico��β���ļ�)
	/// \param [in] shape ·����Ӧ�Ĺ����״��ʾ��ȡenum Shape
	/// \return ���ع���Ƿ�ɹ�
	static bool loadCursor(const std::string &path, Shape shape);
	
	/// ���õ�ǰ�����״
	/// \param [in] shape Ҫ���õĹ����״
	virtual void setCursor(Shape shape) = 0;

	/// �õ���굱ǰ����״
	virtual Shape getCursor() = 0;

	/// ���ù��λ��
	/// \param [in] x Ҫ���ù��λ�õ�x����
	/// \param [in] y Ҫ���ù��λ�õ�y����
	/// \param [in] update �Ƿ���¹��
	virtual void setCursorPos(int x, int y, bool update = false) = 0;

	/// �õ���굱ǰ��λ��
	/// \param [out] pPoint ��ǰ����λ��
	virtual void getCursorPos(PPOINT pPoint) = 0;

	/// ��ʾ,���ع��
	/// \param [in] bShow true������ʾ���,false����Ӱ�ع��
	virtual void showCursor(bool bShow) = 0;

	/// ʹ��,���ù��
	/// \param [in] �Ƿ�ʹ�ܹ��
	virtual void enableCursor(bool bEnable) = 0;
};

#endif
