//
//  "$Id: AudioEnc.h 1140 2010-10-11 09:04:03Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_AUDIO_ENC_H__
#define __PAL_AUDIO_ENC_H__

#include "Types.h"
#include "Types/Types.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup AudioEncAPI API Audio Encoder
/// ��Ƶ���ݱ���ӿڣ�����ͨ����Ƶ���ݱ��룬�����Խ��ȵȡ�
/// \n ��������ͼ:
/// \code
///    =========================================
///                   |                         
///            createAudioEncoder                  
///                   |                         
///                addRef                  
///                   |----------------+        	 
///               setFormat            |        	
///                   |                |        	 
///                 start              |        	 
///         +---------|            setVolume
///         |     getPacket            |        	 
///         |   releasePacket          |        	 
///         +---------|                |           	
///                 stop               |         	
///                   |----------------+         	
///               release                  
///                   |                         
///    =========================================
/// \endcode
/// @{

/// ��Ƶ�����ʽ
typedef enum AudioEncType
{
	audioEncPCM = 0,
	audioEncADPCM,
	audioEncG711A,
	audioEncG711Mu,
	audioEncG726,
	audioEncMPEG2Layer1,
	audioEncAMR,
} AudioEncType;


/// ��Ƶ�����豸���ԣ�128�ֽ�
typedef struct AudioEncCaps
{
	/// ֧�ֵ�ѹ����׼�����룬λ��Ŷ�Ӧö������AudioEncType��ÿһ��ֵ��
	/// ��λ��ʾ֧�ָ�ö��ֵ��Ӧ�����ԣ������ʾ��֧�֡�
	ulong	format;

	/// ����
	int reserved[31];
} AudioEncCaps;


/// ��Ƶ�����ʽ��128�ֽ�
typedef struct AudioEncFormat
{
	AudioEncType	type;			///< ��Ƶ���������
	int				frequency;		///< �����ʣ�HzΪ��λ������44100Hz	
	char			depth;			///< ����λ�֧��8λ��16λ
	char			packetPeriod;	///< ������ڣ�msΪ��λ����10ms��20ms��0��ʾʹ��Ĭ������
	int				reserved[29];	///< ����
} AudioEncFormat;


/// ��Ƶ�������128�ֽ�
typedef struct AudioEncPacket
{
	uchar *			buffer;		///< ���ݻ���ָ��
	ulong			length;		///< ���ݻ�����Ч����
	uint64			pts;		///< ʱ�����msΪ��λ
	ulong			sequence;	///< ����ţ�����У���Ƿ񶪰�
	char			head;		///< �Ƿ����֡ͷ��1-������0-������
	char			tail;		///< �Ƿ����֡β��1-������0-������
	char			newFormat;	///< �����ʽ�Ƿ����˱䶯��0��δ�䶯��1���ѱ䶯
	char			remain;		///< ����������ݰ������в�������
	int				reserved[26];///< ����
} AudioEncPacket;


/// ��Ƶ����ӿڣ�512�ֽ�
typedef struct AudioEncoder
{
	/// �ײ�˽������
	void *priv;


	/// ���ӽӿ�����
	int (*addRef)(struct AudioEncoder *thiz);


	/// �ͷŽӿ�
	int (*release)(struct AudioEncoder *thiz);


	/// �õ���Ƶ����֧�ֵ����ԡ�
	///
	/// \param [in] thiz ������ָ��
	/// \param [out] caps ָ����Ƶ�������ԽṹAudioEncCaps��ָ�롣
	/// \retval 0  ��ȡ�ɹ���
	/// \retval <0  ��ȡʧ�ܡ�
	int (*getCaps)(struct AudioEncoder *thiz, AudioEncCaps * caps);


	/// ��ʼ��Ƶ����
	///
	/// \param [in] thiz ������ָ��
	/// \retval <0 ��ʼʧ��
	/// \retval 0 ��ʼ�ɹ�
	int (*start)(struct AudioEncoder *thiz);


	/// ֹͣ��Ƶ����
	///
	/// \param [in] thiz ������ָ��
	/// \retval <0 ֹͣʧ��
	/// \retval 0 ֹͣ�ɹ�
	int (*stop)(struct AudioEncoder *thiz);


	/// ��ȡ�������ݣ���Ϊ������ģʽ��ÿ�δ���һ�����������ݿ飬��������Ѿ��ֿ飬
	/// ��ֶ�δ��������û�����ݣ��򷵻ش���
	///
	/// \param [in] thiz ������ָ��
	/// \param [in] packet ��Ƶ���ṹAudioEncPacketָ�롣
	/// \return>=0 ͨ���ţ�������ͨ����Ϊ-1ʱ��
	/// \retval 0  ���ɹ�
	/// \retval <0  ��ʧ��
	int (*getPacket)(struct AudioEncoder *thiz, AudioEncPacket * packet);


	/// �ͷŲ�������
	/// \param [in] thiz ������ָ��
	int (*releasePacket)(struct AudioEncoder *thiz);


	/// ������Ƶ���ݱ���ĸ�ʽ��
	///
	/// \param [in] thiz ������ָ�롣
	/// \param [in] format ָ����Ƶ�����ʽ�ṹAudioEncFormat��ָ�롣
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*setFormat)(struct AudioEncoder *thiz, AudioEncFormat * format);


	/// ������Ƶ�����������
	///
	/// \param [in] thiz ������ָ�롣
	/// \param [in] volume ������ȡֵ0-100��
	/// \retval 0  ���óɹ�
	/// \retval <0  ����ʧ��
	int (*setVolume)(struct AudioEncoder *thiz, int volume);


	/// ����
	int reserved[118];
} AudioEncoder;

/// ��������
typedef enum AudioEncStream
{
	audioEncStreamMain = 0,	///< ������
	audioEncStreamExtra1,	///< ������1
	audioEncStreamExtra2,	///< ������2
	audioEncStreamExtra3,	///< ������3
	audioEncStreamTalkback,	///< �Խ�����
	audioEncStreamNumber	///< ������
} AudioEncStream;

/// ��Ƶ����ӿ�������128�ֽ�
typedef struct AudioEncDesc
{
	ulong	srcs;		///< ��Ƶ��������ͨ�������룬ÿһλ��Ӧһ����Ƶ����ͨ��			
	AudioEncStream	stream;		///< ָ����������������
	int reserved[30];	///< ����
} AudioEncDesc;


/// ������Ƶ����ӿ�
///
/// \param [in] desc ��Ƶ����ӿ������ṹAudioEncDescָ��
/// \param [out] audioEncoder ��Ƶ����ӿ�ָ���ָ��
/// \retval <0 ����ʧ��
/// \retval 0 �����ɹ�
int createAudioEncoder(AudioEncDesc *desc, AudioEncoder **audioEncoder);


/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
