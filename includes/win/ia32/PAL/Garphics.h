//
//  "$Id: Garphics.h 337 2010-02-22 08:18:57Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_GARPHICS_H__
#define __PAL_GARPHICS_H__

#include "Types/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup GraphicsAPI API Graphics
/// ��ͼ���豸�ӿڣ���ȡFrameBuffer��֡���壩����������Overlay�����ӣ������ȵȡ�
/// ��Ⱦ�������ϲ�ʵ�֣���ʱ��֧��Ӳ�����١�
/// \n ��������ͼ:
/// \code
///    =========================================
///                   |                         
///             CreateGraphicsLayer 
///					  |
/// 				 Start
///         +---------|
///			|	UpdateSurface
///			|		  |
///         |     SetAlpha
///         |         |
///         |    SetKeycolor
///         |         |
///         +---------|
///					 Stop                  
///                   |                         
///    =========================================
/// \endcode
/// @{

/// ͼ����ɫ��ʽ����
typedef enum GraphicsColorFormat{  
	graphicsColorRGB555,	///< 16λ��ʾһ�����ء���ɫ����λ����ΪXRRRRRGG GGGBBBBB��
	graphicsColorRGB565,	///< 16λ��ʾһ�����ء���ɫ����λ����ΪRRRRRGGG GGGBBBBB��
	graphicsColorRGB888,	///< 24λ��ʾһ�����ء���ɫ����λ����ΪRRRRRRRR GGGGGGGG BBBBBBBB��
} GraphicsColorFormat;

/// ͼ����ɫ��ʽ����
typedef enum GraphicsLayerType {  
	graphicsPrimary,		///< ��ͼ�㡣
	graphicsCursor,			///< ���ͼ�㡣
	graphicsButt,
} GraphicsLayerType;


/// ͼ��֡����ṹ��128�ֽ�
typedef struct GraphicsSurface
{
	uchar *mem;			///< ���Դ��ָ�롣
	uchar *mem0;		///< ���Դ��ָ�룬��ʾʱ���ڴ���ʾ������ʾ����ɺ�Flip������������������ʾ������
						///< �����֧�ַ�תֻ�轫mem0���ó�mem,Filp����Ϊ�գ�GUI���Զ����������档
	uchar *mem1;		///< ������
	int pitch;			///< ��ȣ����Դ�һ��ɨ���ߵĿ�ʼ����һ��ɨ���ߵĿ�ʼ�洢�ռ��ƫ�ƣ��ֽ�Ϊ��λ��
	int width;			///< ���ȣ�����Ϊ��λ��
	int height;			///< ��߶ȣ�����Ϊ��λ��
	int format;			///< ��ɫ��ʽ��ȡGraphicsColorFormat����ֵ��ֵ��
	int reserved[25];	///< �����ֽ�
} GraphicsSurface;

/// ͼ�β�ӿڽṹ��512�ֽڡ�
/// \detail ��Ƶ����ӿڿ��ܰ�������㣬ͼ�β������е�һ�����ֱ�������Ƶ����ֱ��ʱ仯��
typedef struct GraphicsLayer
{
	/// �ײ�˽������
	void *priv;	


	/// ���ӽӿ�����
	int (*addRef)(struct GraphicsLayer *thiz);


	/// �ͷŽӿ�
	int (*release)(struct GraphicsLayer *thiz);


	/// �õ�ͼ�β�ȫ�ֱ��档��Ƶ��ʽ�ı������Ƶ����ֱ��ʸı�ʱ���ܻ�ı䣬GDI��Ҫ���»�ȡ��
	/// 
	/// \param [in] thiz ͼ�β�ӿ�ָ��
	/// \param [out] surface ָ����ʾ���������ṹGraphicsSurface��ָ�롣GDIֱ��ͨ��
	///        �Դ��ָ������Դ档ͼ���豸ֻ��ѡ��GDI֧�ֵ���ɫ��ʽ�е�һ�֣����GDI
	///        ����֧�֣�����Ҫ�����µ���ɫ��ʽ��������GDI���ܡ�
	/// \retval 0  ��ȡ�ɹ�
	/// \retval <0  ��ȡʧ��
	int (*getSurface)(struct GraphicsLayer *thiz, GraphicsSurface *surface);


	/// ����ͼ�ε�͸���ȡ�ͼ����ͼ����ȫ����Χ�ڰ���͸���ȵ��ӡ�
	/// 
	/// \param [in] thiz ͼ�β�ӿ�ָ��
	/// \param [in] alpha Ҫ���õĵ�ǰ͸���ȣ�ֵԽ�ͱ�ʾ����ʱͼ����ɫ�ķ���Խ�ͣ�Ҳ��
	///        Խ͸����ȡֵ0-255��
	/// \param [in] delta ͸�����Զ�����ֵ��ÿ֡ʱ��͸���ȼ��ϴ�ֵ��ֱ��͸���ȱ�����
	///        ����СΪֹ��ֵΪ0��ʾ�����䡣
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*setAlpha)(struct GraphicsLayer *thiz, int alpha, int delta);


	/// ����������ɫ����ͼ����ͼ��������ɫ����ʱ��ͼ����Դ�㣬ͼ����Ŀ�Ĳ㣬ͼ�ε���
	/// ��ɫ���򽫱���Ƶ�滻��
	/// 
	/// \param [in] thiz ͼ�β�ӿ�ָ��
	/// \param [in] dwKeyLow ��Ӧ����ɫ�������ɫ������Сֵ��16���Ʊ�ʾΪ0x00BBGGRR������ֽڱ�����
	/// \param [in] dwKeyHigh ��Ӧ����ɫ�������ɫ�������ֵ��16���Ʊ�ʾΪ0x00BBGGRR������ֽڱ�����
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*setKeyColor)(struct GraphicsLayer *thiz, int keylow, int keyhigh);


	/// ����Ӳ������ȵ�λ�ã���GDIһ��ʹ�������꣬����ӿ���Ҫ�ǹ�Windowsģ�����ʹ�á�
	///
	/// \param [in] thiz ͼ�β�ӿ�ָ��
	/// \param [in] x x����
	/// \param [in] y y����
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*setCursorPos)(struct GraphicsLayer *thiz, int x, int y);


	/// ��ʾ������GUIͼ��
	///
	/// \param [in] thiz ͼ�β�ӿ�ָ��
	/// \param [in] nShow �Ƿ���ʾͼ��
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*showLayer)(struct GraphicsLayer *thiz, int nShow);


	/// ͼ�㷭ת,ʵ��GUI��˫���壬�ϲ㽫����ҳ�������д���󱳻����Ժ���øýӿڽ��󱳻����е�������ʾ����
	/// \param [in] thiz ͼ�β�ӿ�ָ��
	/// \param [in] srcRect Ҫ��ת����ʾ����
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*flip)(struct GraphicsLayer *thiz, const Rect *srcRect, int dwRop);
	
	/// ͼ��������
	/// \param [in] thiz Ҫ����ͼ��
	/// \param [in] rect Ҫ����ͼ������
	/// \param [in] ulFillData Ҫ��������
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*blt)(struct GraphicsLayer *thiz, const Rect *rect, ulong ulFillData, int dwRop);

	/// ����
	void *reserved[119];
} GraphicsLayer;


/// ͼ�β�ӿ�������128�ֽ�
typedef struct GraphicsLayerDesc
{
	int layerType;		///< ͼ������
	int reserved[31];	///< ����
} GraphicsLayerDesc;


/// ����ͼ�β�ӿ�
///
/// \param [in] desc ͼ�β�ӿ������ṹGraphicsLayerDescָ��
/// \param [out] layer ͼ�β�ӿ�ָ���ָ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int createGraphicsLayer(GraphicsLayerDesc *desc, GraphicsLayer **layer);

/// @} end of group

#ifdef __cplusplus
}
#endif
#endif
