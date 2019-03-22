//
//  "$Id: GraphicsManager.h 447 2010-04-14 12:21:08Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __GDI_GRAPHICS_MANAGER_H__
#define __GDI_GRAPHICS_MANAGER_H__

#include "Types.h"
#include "PAL/Garphics.h"

/// ͼ���豸�ӿ�
/// 
class IGraphicsManager 
{
public:

	/// ����ʵ��
	static IGraphicsManager *instance();

	/// ����������
	virtual ~IGraphicsManager();

	/// ��ȡͼ�λ��ƻ���
	/// \param [out] nLayer ָʾҪ��ȡͼ�λ�������֡
	/// \param [out] surface �����ȡ����ͼ��֡����ṹ
	virtual void getSurface(int nLayer, GraphicsSurface *surface) = 0;
	
	/// �õ�ͼ������,���䲻ͬʱ�ؼ���Ҫ����
	/// \param [in] nLayer Ҫ�õ������ͼ��
	/// \return ��ͼ�������
	virtual int getAge(int nLayer) = 0;

	/// ����ͼ��GUI�ֱ���
	/// \param [in] Ҫ���÷ֱ��ʵ�ͼ��
	/// \param [in] w x�ֱ���
	/// \param [in] h y�ֱ���
	/// \return �����Ƿ�ɹ�
	virtual bool setResolution(int nLayer, int w, int h) = 0;

	/// ����ͼ���豸����
	/// \return ����ͼ���Ƿ�ɹ�
	virtual bool updateSurface(int nLayer) = 0;


	/// �õ����Ʋ����ṹ
	virtual GraphicsLayer *getGraphicsLayer(int nLayer) = 0;

	/// �õ�ͼ���豸��������
	virtual void getRect(int nLayer, PRECT pRect) = 0;

	/// ��������ͼ���GUI͸����
	/// \param [in] alpha alpha͸����
	/// \param [in] delta delta͸����
	virtual void setAlpha(int alpha, int delta = 0) = 0;

	/// ��������ͼ��GUI����ɫ,����ɫ����ֻ��ʾ��Ƶ
	/// \param [in] dwKeyLow 
	/// \param [in] dwKeyHigh
	virtual void setKeyColor(RGBA32 dwKeyLow, RGBA32 dwKeyHigh) = 0;

	/// �õ���ǰͼ�������ɫ
	virtual RGBA32 getKeyColor() = 0;
};

#endif
