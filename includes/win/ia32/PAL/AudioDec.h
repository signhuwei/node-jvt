//
//  "$Id: AudioDec.h 1140 2010-10-11 09:04:03Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_AUDIO_DEC_H__
#define __PAL_AUDIO_DEC_H__

#include "Types.h"
#include "Types/Types.h"
#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup AudioDecAPI API Audio Decoder
/// ��Ƶ����ӿڣ���Ƶ�������������Խ���������ʾ�ȶ��ֳ��ϡ�
/// \n ��������ͼ:
/// \code
///    ==========================================
///               |
///	      createAudioDecorder
///               |
///            addRef
///               |-----------------+
///             start               |
///               |---------+    setVolume
///           putBuffer     |       |
///               |---------+       |
///             stop                |
///               |-----------------+
///            release
///               |
///    ==========================================
/// \endcode
/// @{

enum AudioEncType;


/// �����ѹ������֡�ṹ��128�ֽ�
typedef struct AudioDecFormat
{
	AudioEncType type:8;	///< ��Ƶ���������
	int reserved[31];		///< ����
} AudioDecFormat;

/// ��Ƶ�������ݰ��ṹ��128�ֽ�
typedef struct AudioDecPacket
{
	/// ��д���֡���ݻ���ָ�룬���֡����ƴ��һ��
	uchar * buffer;

	/// ��д���֡���ݳ��ȡ�
	ulong	length;

	/// �������Ƶ���岥�����ʣ�����������ٶȵı��ٱ�ʾ������0.5��ʾ���ٲ��ţ�
	/// 1.0��ʾԭ�ٲ��ţ�2.0��ʾ�����ٲ��š������Ƶ������֧����Ƶ�����Ƶ�ʿ��ƣ�
	/// ��Ӧ�ø���speed��ֵ��Ƶ�ʿ��ƴ�������ֱ�Ӿ�����
	float speed;

	/// ����
	int reserved[29];
}AudioDecPacket;

/// ��Ƶ���������ṹ��128�ֽ�
typedef struct AudioDecCaps
{
	int reserved[32];	///< ����
}AudioDecCaps;

/// ��Ƶ����ӿڣ�512�ֽ�
typedef struct AudioDecoder
{
	/// �ײ�˽������
	void *priv;


	/// ���ӽӿ�����
	int (*addRef)(struct AudioDecoder *thiz);


	/// �ͷŽӿ�
	int (*release)(struct AudioDecoder *thiz);


	/// ��ȡ�ӿ���������
	///
	/// \param [in] thiz ������ָ��
	/// \param [out] caps ��Ƶ���������ṹ
	/// \return <0 ��ȡʧ��
	/// \retval 0 ��ȡ�ɹ�
	int (*getCaps)(struct AudioDecoder *thiz, AudioDecCaps *caps);


	/// ������Ƶ���롣���û�л����豸����������Ƶ����Զ��л�����ǰ����ͨ������Ƶ��
	///
	/// \param [in] thiz ������ָ��
	/// \return <0 ����ʧ��
	/// \retval 0 �����ɹ�
	int (*start)(struct AudioDecoder *thiz);


	/// ֹͣ��Ƶ���롣���û�л����豸��ֹͣ����Ƶ����Զ��л������жϵĽ���ͨ������Ƶ��
	/// ����޽�����Ƶ�������������Ƶ��
	///
	/// \param [in] thiz ������ָ��
	/// \return <0 ֹͣʧ��
	/// \retval 0 ֹͣ�ɹ�
	int (*stop)(struct AudioDecoder *thiz);


	/// ��ս������Ƶ���壬��������putFrame�����������ء�
	/// 
	/// \param [in] thiz ������ָ��
	/// \retval 0  ��ճɹ�
	/// \retval <0  ���ʧ��
	int (*flush)(struct AudioDecoder *thiz);


	/// ������󻺳��Ƿ�Ϊ�գ�����Ƶ�Ƿ��Ѿ���ȫ�����֡�
	/// 
	/// \param [in] thiz ��Ƶ����ӿ�ָ��
	/// \retval 0  �ǿ�
	/// \retval 1  �ѿ�
	/// \return <0 ������
	int (*empty)(struct AudioDecoder *thiz);


	/// ������Ƶ���ݽ���ĸ�ʽ��
	///
	/// \param [in] thiz ������ָ�롣
	/// \param [in] format ��Ƶ�����ʽAudioDecFormatָ�롣
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*setFormat)(struct AudioDecoder *thiz, AudioDecFormat* format);


	/// ���֡���ݵ���Ƶ���뻺�壬����ģʽ��������ɺ󷵻ء���������Ƶ��һ��������ʾ��
	/// �ײ㻹��Ҫ����Ƶ�ʿ��ƣ����������ͼ�񻺳������������ý��ᱻ��������ʱ�䣬
	/// ֱ������󻺳����㹻�ռ䣬�ñ��ν�����ɡ�
	///
	/// \param [in] thiz ������ָ��
	/// \param [in] packet �������ݰ�AudioDecPacketָ��
	/// \return <0 ���ʧ��
	/// \retval 0 ���ɹ�
	int (*putPacket)(struct AudioDecoder *thiz, AudioDecPacket *packet);


	/// ������Ƶ�����������
	///
	/// \param [in] thiz ������ָ�롣
	/// \param [in] volume ������ȡֵ0-100��
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*setVolume)(struct AudioDecoder *thiz, int volume);

	/// ����
	int reserved[117];
}AudioDecoder;

/// ��Ƶ����ӿ�������128�ֽ�
typedef struct AudioDecDesc
{
	int	dest;			///< �������Ƶ���ͨ����			
	int reserved[31];	///< ����
} AudioDecDesc;


/// ������Ƶ����ӿ�
///
/// \param [in] desc ��Ƶ����ӿ������ṹAudioDecDescָ��
/// \param [out] audioEncoder ��Ƶ����ӿ�ָ���ָ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int createAudioDecoder(AudioDecDesc *desc, AudioDecoder** audioDecoder);


#ifdef __cplusplus
}
#endif

#endif
