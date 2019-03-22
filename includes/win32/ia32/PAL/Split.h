//
//  "$Id: Split.h 2296 2011-12-02 11:28:03Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_SPLIT_H__
#define __PAL_SPLIT_H__

#include "Types.h"
#include "Types/Types.h"
#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup VideoSplit API API Video Split 
/// ��Ƶ����ӿ�
/// \n ��������ͼ:
/// \code
///    ================================
///               |
///       createVideoSplit
///               |
///            addRef
///               |
///            setVstd
///               |-----------+
///               |           |
///               |        setRect
///               |           |
///               |-----------+
///            release
///               |
///    ================================
/// \endcode
/// @{
//#ifdef WIN32
#if 0
struct RECT
{
	int left;
	int top;
	int right;
	int bottom;
};
#endif

/// ����ָ�ӿڣ�512�ֽ�
typedef struct VideoSplit
{
	/// �ײ�˽������
	void *priv;


	/// ���ӽӿ�����
	int (*addRef)(struct VideoSplit *thiz);


	/// �ͷŽӿ�
	int (*release)(struct VideoSplit *thiz);

	/// ������Ƶ��ʽ��
	/// 
	/// \param [in] dwStandard ��Ƶ��ʽ��ȡvideo_standard_t���͵�ֵ��
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*setVstd)(struct VideoSplit *thiz, int dwStandard);
	
	
	/// ����Ԥ����ʾ������ʵ��Ԥ��������ӷŴ�
	/// 
	/// \param [in] channel ͨ���š�
	/// \param [in] pSourceRect ��ƵԴ���򣬲������������ϵ��������ʱpSourceRect��NULL��
	/// \param [in] pDestRect ��ƵĿ�����򣬲���ͼ��������ϵ��
	/// \retval 0  д�ɹ�
	/// \retval <0  дʧ��
	int (*setRect)(struct VideoSplit *thiz, int channel, const RECT *pSourceRect, const RECT *pDestRect, int nPriority);

	int (*setDeflick)(struct VideoSplit *thiz, int dwDeflick);

	int (*setVoPosition)(struct VideoSplit *thiz, int splitMode, int subIndex, const RECT *pDestRect, int rectNum);
	/// ����
	int reserved[121];
} VideoSplit;


//�ָ�����
typedef struct tagSPLIT_CAPS
{
	unsigned int dwCombine;
}SPLIT_CAPS;


/// �ָ�����������128�ֽ�
typedef struct _SplitDesc
{
	int resv[32];
} SplitDesc;


//����ָ�ģʽ
typedef struct tagSPLIT_MODE
{
	unsigned int dwMode;
	unsigned int dwIndex; 
	unsigned int Rev[4];
}SPLIT_MODE;

int setVoPosition(int splitMode, int subIndex, const RECT *pDestRect, int rectNum);
/// ��������ָ���
///
/// \param [in] desc ��Ƶ����ӿ������ṹAudioOutDescָ��
/// \param [out] videoSplit ��Ƶ�ָ�ָ���ָ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int createVideoSplit(SplitDesc *desc, VideoSplit **videoSplit);


#ifdef __cplusplus
}
#endif

#endif 
