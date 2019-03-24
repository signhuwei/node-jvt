/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MON_DataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-11
 * Description   :  ���ƽ̨��������
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MON_DATADEF_H
#define __NPC_MON_DATADEF_H

#include "NPC_TypeDef.h"


//��������
#define NPC_D_MON_IPADDR_BUFSIZE								40				//IP��ַ��������С
#define NPC_D_MON_NODEID_BUFSIZE								32				//���ID��������С
#define NPC_D_MON_FILENAME_BUFSIZE								128				//�ļ�����������С
#define NPC_D_MON_CAMERAID_BUFSIZE								32				//�����ID��������С
#define NPC_D_MON_DEVID_BUFSIZE									32				//�豸ID��������С���������ID��DVRID��
#define NPC_D_MON_DEV_CONN_PARAM_BUFSIZE						1024			//���Ӳ�����������С

#define NPC_D_MON_USERID_BUFSIZE								32				//�û�ID��������С
#define NPC_D_MON_USERNAME_BUFSIZE								32				//�û�����������С
#define NPC_D_MON_USERPWD_BUFSIZE								32				//�û����뻺������С
#define NPC_D_MON_SERVER_ID_BUFSIZE								32				//������ID��������С
#define NPC_D_MON_ALARM_BUF_SIZE								512				//������Ϣ��������С

//�豸����ģʽ����
#define NPC_D_MON_DEV_CONN_MODE_DIRECT							0				//ֱ��ģʽ
#define NPC_D_MON_DEV_CONN_MODE_STREAM							1				//��ý�������ģʽ
#define NPC_D_MON_DEV_CONN_MODE_CLOUD_P2P						2				//P2P��ģʽ
#define NPC_D_MON_DEV_CONN_MODE_CLOUD_STREAM					3				//����ý��ģʽ

//ý�����Ͷ���
#define NPC_D_MON_MEDIA_TYPE_VIDEO								0				//��Ƶ
#define NPC_D_MON_MEDIA_TYPE_AUDIO								1				//��Ƶ
#define NPC_D_MON_MEDIA_TYPE_PICTURE							2				//ͼƬ
#define NPC_D_MON_MEDIA_TYPE_START								100				//��ʼ֡

//��Ƶ֡���Ͷ���
#define NPC_D_MON_VIDEO_FRAME_TYPE_I							1				//I֡
#define NPC_D_MON_VIDEO_FRAME_TYPE_P							2				//P֡
#define NPC_D_MON_VIDEO_FRAME_TYPE_B							3				//B֡
#define NPC_D_MON_VIDEO_FRAME_TYPE_SPS							10				//H264��SPS֡
#define NPC_D_MON_VIDEO_FRAME_TYPE_PPS							11				//H264��PPS֡
#define NPC_D_MON_VIDEO_FRAME_TYPE_VOL							12				//MPEG4��VOL֡

//����ID����
#define NPC_D_MON_CODEC_ID_VEDIO_H264							10				//H264
#define NPC_D_MON_CODEC_ID_VEDIO_MPEG4							11				//MPEG4
#define NPC_D_MON_CODEC_ID_VEDIO_MJPG							12				//MJPG
#define NPC_D_MON_CODEC_ID_VEDIO_H265							13				//H265

#define NPC_D_MON_CODEC_ID_AUDIO_AAC							20				//AAC
#define NPC_D_MON_CODEC_ID_AUDIO_PCMA							21				//PCMA��G711A��
#define NPC_D_MON_CODEC_ID_AUDIO_PCMU							22				//PCMU��G711U��
#define NPC_D_MON_CODEC_ID_AUDIO_ADPCM							23				//ADPCM
#define NPC_D_MON_CODEC_ID_AUDIO_G726							24				//G726
#define NPC_D_MON_CODEC_ID_AUDIO_AMRNB							25				//AMRNB
#define NPC_D_MON_CODEC_ID_AUDIO_ADPCM_DJ						26				//ADPCM_DJ

#define NPC_D_MON_CODEC_ID_AUDIO_16BITPCM						30				//16����PCM

//��Ƶ�ֱ���
#define NPC_D_MON_VEDIO_RESOLUTION_1080P						1				//1080P
#define NPC_D_MON_VEDIO_RESOLUTION_720P							2				//720P
#define NPC_D_MON_VEDIO_RESOLUTION_D1							3				//D1
#define NPC_D_MON_VEDIO_RESOLUTION_HD1							4				//HD1
#define NPC_D_MON_VEDIO_RESOLUTION_BCIF							5				//BCIF
#define NPC_D_MON_VEDIO_RESOLUTION_CIF							6				//CIF
#define NPC_D_MON_VEDIO_RESOLUTION_QCIF							7				//QCIF
#define NPC_D_MON_VEDIO_RESOLUTION_VGA							8				//VGA
#define NPC_D_MON_VEDIO_RESOLUTION_QVGA							9				//QVGA
#define NPC_D_MON_VEDIO_RESOLUTION_SVCD							10				//SVCD
#define NPC_D_MON_VEDIO_RESOLUTION_QQVGA						11				//QQVGA
#define NPC_D_MON_VEDIO_RESOLUTION_SXVGA						12				//SXVGA
#define NPC_D_MON_VEDIO_RESOLUTION_UXGA							13				//UXGA

//��������ģʽ
#define NPC_D_MON_BITRATECTRL_CBR								1				//�̶�����
#define NPC_D_MON_BITRATECTRL_VBR								2				//�ɱ�����
#define NPC_D_MON_BITRATECTRL_MBR								3				//�������

//¼��طŻ�㲥�����붨��
#define NPC_D_MON_PLAY_CTRL_PAUSE								1				//��ͣ���޲�����
#define NPC_D_MON_PLAY_CTRL_RESUME								2				//�������޲�����
#define NPC_D_MON_PLAY_CTRL_SET_FRAME_RATE						3				//����֡�ʣ�����Ϊ֡�ʣ�
#define NPC_D_MON_PLAY_CTRL_SET_PLAY_POS						4				//���ò���λ�ã�����Ϊλ�ã��룩��
#define NPC_D_MON_PLAY_CTRL_SET_FAST_FORWARD					5				//������޲�����������ԭ֡�ʣ���������֡
#define NPC_D_MON_PLAY_CTRL_SET_SLOW_FORWARD					6				//�������޲�����
#define NPC_D_MON_PLAY_CTRL_SET_FAST_BACKWARD					7				//���ˣ��޲�����������ԭ֡�ʣ���������֡
#define NPC_D_MON_PLAY_CTRL_SET_SLOW_BACKWARD					8				//���ˣ��޲�����
#define NPC_D_MON_PLAY_CTRL_SET_FRAME_FORWARD					9				//��֡�����޲�����
#define NPC_D_MON_PLAY_CTRL_SET_FRAME_BACKWARD					10				//��֡�ˣ��޲�����
#define NPC_D_MON_PLAY_CTRL_ONLY_IFRAME							11				//����ֻ�ط�I֡���ݣ�����Ϊ����I֡����0������I֡��1������1��I֡�������1��I֡���䣩��2������2��I֡��������ƣ�
#define NPC_D_MON_PLAY_CTRL_RECOVER_ALLFRAME					12				//����ָ��ط�ȫ֡���ݣ��޲�����

//¼���ļ�λ��
#define NPC_D_MON_REC_FILE_POS_DEV								1				//�豸��
#define NPC_D_MON_REC_FILE_POS_SERVER							2				//��������

//��־��Ϣ���Ͷ���
#define NPC_D_MON_LOG_INFO_TYPE_ERROR							0				//������־
#define NPC_D_MON_LOG_INFO_TYPE_TRACE							1				//������־


//PTZ�����
#define NPC_D_MON_PTZ_CMD_STOP									0				//ֹͣ�˶���ֹͣǰһ����������

#define NPC_D_MON_PTZ_CMD_LIGHT_PWRON							2				//��ͨ�ƹ��Դ���޲���
#define NPC_D_MON_PTZ_CMD_WIPER_PWRON							3				//��ͨ��ˢ���أ��޲���
#define NPC_D_MON_PTZ_CMD_FAN_PWRON								4				//��ͨ���ȿ��أ��޲���
#define NPC_D_MON_PTZ_CMD_HEATER_PWRON							5				//��ͨ���������أ��޲���
#define NPC_D_MON_PTZ_CMD_AUX_PWRON1							6				//��ͨ�����豸����1���޲���
#define NPC_D_MON_PTZ_CMD_AUX_PWRON2							7				//��ͨ�����豸����2���޲���
#define NPC_D_MON_PTZ_CMD_SET_PRESET							8				//����Ԥ�õ㣬in_dwPtzDataΪԤ�õ����ţ�1��255��
#define NPC_D_MON_PTZ_CMD_CLE_PRESET							9				//���Ԥ�õ㣬in_dwPtzDataΪԤ�õ����ţ�1��255��

#define NPC_D_MON_PTZ_CMD_ZOOM_IN								11				//�������ٶ�SS��󣨱��ʱ�󣩣�in_dwPtzDataΪ�ٶȣ�1��10�����ƾ��ٶȳ�ʼֵΪ4��in_dwPtzExtParam1Ϊ�Ƿ��Զ�ֹͣ��1��0����in_dwPtzExtParam2Ϊ�Զ�ֹͣ�ļ��ʱ�䣨1��255�룩
#define NPC_D_MON_PTZ_CMD_ZOOM_OUT								12				//�������ٶ�SS��С�����ʱ�С����ͬ��
#define NPC_D_MON_PTZ_CMD_FOCUS_NEAR							13  			//�������ٶ�SSǰ����ͬ��
#define NPC_D_MON_PTZ_CMD_FOCUS_FAR								14  			//�������ٶ�SS�����ͬ��
#define NPC_D_MON_PTZ_CMD_IRIS_OPEN								15  			//��Ȧ���ٶ�SS����ͬ��
#define NPC_D_MON_PTZ_CMD_IRIS_CLOSE							16  			//��Ȧ���ٶ�SS��С��ͬ��

#define NPC_D_MON_PTZ_CMD_TILT_UP								21				//��̨��SS���ٶ�������in_dwPtzDataΪ�ٶȣ�1��10������̨�ٶȳ�ʼֵΪ4��in_dwPtzExtParam1Ϊ�Ƿ��Զ�ֹͣ��1��0����in_dwPtzExtParam2Ϊ�Զ�ֹͣ�ļ��ʱ�䣨1��255�룩
#define NPC_D_MON_PTZ_CMD_TILT_DOWN								22				//��̨��SS���ٶ��¸���ͬ��
#define NPC_D_MON_PTZ_CMD_PAN_LEFT								23				//��̨��SS���ٶ���ת��ͬ��
#define NPC_D_MON_PTZ_CMD_PAN_RIGHT								24				//��̨��SS���ٶ���ת��ͬ��
#define NPC_D_MON_PTZ_CMD_UP_LEFT								25				//��̨��SS���ٶ���������ת��ͬ��
#define NPC_D_MON_PTZ_CMD_UP_RIGHT								26				//��̨��SS���ٶ���������ת��ͬ��
#define NPC_D_MON_PTZ_CMD_DOWN_LEFT								27				//��̨��SS���ٶ��¸�����ת��ͬ��
#define NPC_D_MON_PTZ_CMD_DOWN_RIGHT							28				//��̨��SS���ٶ��¸�����ת��ͬ��
#define NPC_D_MON_PTZ_CMD_PAN_AUTO								29				//��̨��SS���ٶ������Զ�ɨ�裬ͬ��

#define NPC_D_MON_PTZ_CMD_FILL_PRE_SEQ							30				//��Ԥ�õ����Ѳ�����У�in_dwPtzDataΪѲ��·���ţ�1��32����in_dwPtzExtParam1ΪԤ�õ�ţ�1��255����in_dwPtzExtParam2Ϊͣ��ʱ�䣨1��255�룩
#define NPC_D_MON_PTZ_CMD_SET_SEQ_DWELL							31				//����Ѳ����ͣ��ʱ�䣬in_dwPtzDataΪѲ��·���ţ�1��32����in_dwPtzExtParam1ΪԤ�õ�ţ�1��32����in_dwPtzExtParam2Ϊͣ��ʱ�䣨1��255�룩
#define NPC_D_MON_PTZ_CMD_SET_SEQ_SPEED							32				//����Ѳ���ٶȣ�in_dwPtzDataΪѲ��·���ţ�1��32����in_dwPtzExtParam1ΪԤ�õ�ţ�1��32����in_dwPtzExtParam2Ϊ�ٶȣ�1��10��
#define NPC_D_MON_PTZ_CMD_CLE_PRE_SEQ							33				//��Ԥ�õ��Ѳ��������ɾ����in_dwPtzDataΪѲ��·���ţ�1��32����in_dwPtzExtParam1ΪԤ�õ�ţ�1��255��
#define NPC_D_MON_PTZ_CMD_STA_MEM_CRUISE						34				//��ʼ��¼�켣�����޲���
#define NPC_D_MON_PTZ_CMD_STO_MEM_CRUISE						35				//ֹͣ��¼�켣���޲���
#define NPC_D_MON_PTZ_CMD_RUN_CRUISE							36				//��ʼ�켣���޲���
#define NPC_D_MON_PTZ_CMD_RUN_SEQ								37				//��ʼѲ����in_dwPtzDataΪѲ��·����
#define NPC_D_MON_PTZ_CMD_STOP_SEQ								38				//ֹͣѲ����in_dwPtzDataΪѲ��·����
#define NPC_D_MON_PTZ_CMD_GOTO_PRESET							39				//����ת��Ԥ�õ㣬in_dwPtzDataΪԤ�õ��
#define NPC_D_MON_PTZ_CMD_CLEAR_TOUR							40				//���Ѳ����in_dwPtzDataΪѲ��·����

//�������Ͷ���
#define NPC_D_MON_ALARM_TYPE_DEV_FAULT							1				//�豸���ϱ����������������Ӳ��ϣ�ע��ģʽ���ߣ�
#define NPC_D_MON_ALARM_TYPE_MOTION								2				//�ƶ���ⱨ��
#define NPC_D_MON_ALARM_TYPE_VIDEO_BLIND						3				//��Ƶ�ڵ�����
#define NPC_D_MON_ALARM_TYPE_VIDEO_LOSS							4				//��Ƶ��ʧ����
#define NPC_D_MON_ALARM_TYPE_PROBE								5				//̽ͷ����
#define NPC_D_MON_ALARM_TYPE_PIR								6				//�����Ӧ����
#define NPC_D_MON_ALARM_TYPE_DOORBELL							7				//���屨��

//����֪ͨ���Ͷ���
#define NPC_D_MON_ALARM_NOTIFY_TYPE_PHONE_PUSH					1				//�ֻ�������Ϣ
#define NPC_D_MON_ALARM_NOTIFY_TYPE_SMS							2				//����
#define NPC_D_MON_ALARM_NOTIFY_TYPE_EMAIL						3				//EMAIL

//�����������Ͷ���
#define NPC_D_MON_ALARM_ACTION_TYPE_PHOTO						1				//����
#define NPC_D_MON_ALARM_ACTION_TYPE_VIDEO						2				//¼��
#define NPC_D_MON_ALARM_ACTION_TYPE_PTZ							3				//PTZ����

//��������
#define NPC_D_MON_ALARM_CTRL_ARM_PAUSE							1				//��ͣ����
#define NPC_D_MON_ALARM_CTRL_ARM_CONTINUE						2				//��������
#define NPC_D_MON_ALARM_CTRL_NFT_PAUSE							3				//��֪ͣͨ
#define NPC_D_MON_ALARM_CTRL_NFT_CONTINUE						4				//����֪ͨ
#define NPC_D_MON_ALARM_CTRL_ACT_PAUSE							5				//��ͣ��������
#define NPC_D_MON_ALARM_CTRL_ACT_CONTINUE						6				//������������

//¼���ļ�����
#define NPC_D_MON_REC_FILE_TYPE_ALL								0x00FF			//����¼��
#define NPC_D_MON_REC_FILE_TYPE_GENERAL							0x0001			//����¼�񣨶�ʱ¼��
#define NPC_D_MON_REC_FILE_TYPE_ALARM							0x0002			//�ƶ���ⱨ��¼��
#define NPC_D_MON_REC_FILE_TYPE_MALUAL							0x0004			//�ֶ�¼��
#define NPC_D_MON_REC_FILE_TYPE_PROBE							0x0008			//���루̽ͷ������¼��
#define NPC_D_MON_REC_FILE_TYPE_PIR								0x0010			//�����Ӧ����¼��
#define NPC_D_MON_REC_FILE_TYPE_DOORBELL						0x0020			//���屨��¼��
#define NPC_D_MON_REC_FILE_TYPE_SMART_IPC_CROSS_LINE			0x0040			//Խ����ⱨ��¼��
#define NPC_D_MON_REC_FILE_TYPE_SMART_IPC_AREA_INTRUSION		0x0080			//�������ֱ���¼��

#define NPC_D_MON_REC_FILE_TYPE_PIC_ALL							0xFF00			//����ͼƬ�ļ�
#define NPC_D_MON_REC_FILE_TYPE_PIC_GENERAL						0x0100			//����ͼƬ����ʱ��
#define NPC_D_MON_REC_FILE_TYPE_PIC_ALARM						0x0200			//�ƶ���ⱨ��ͼƬ
#define NPC_D_MON_REC_FILE_TYPE_PIC_MALUAL						0x0400			//�ֶ�ͼƬ
#define NPC_D_MON_REC_FILE_TYPE_PIC_PROBE						0x0800			//���루̽ͷ������ͼƬ
#define NPC_D_MON_REC_FILE_TYPE_PIC_PIR							0x1000			//�����Ӧ����ͼƬ
#define NPC_D_MON_REC_FILE_TYPE_PIC_DOORBELL					0x2000			//���屨��ͼƬ
#define NPC_D_MON_REC_FILE_TYPE_PIC_SMART_IPC_CROSS_LINE		0x4000			//Խ����ⱨ��ͼƬ
#define NPC_D_MON_REC_FILE_TYPE_PIC_SMART_IPC_AREA_INTRUSION	0x8000			//�������ֱ���ͼƬ

//�ļ���ʽ
#define NPC_D_MON_FILE_FORMAT_VIDEO_H264						0x0001			//H264�ļ�
#define NPC_D_MON_FILE_FORMAT_VIDEO_MPEG4						0x0002			//MPEG4�ļ�
#define NPC_D_MON_FILE_FORMAT_VIDEO_H265						0x0003			//H265�ļ�

#define NPC_D_MON_FILE_FORMAT_PIC_BMP							0x0101			//BMP�ļ�
#define NPC_D_MON_FILE_FORMAT_PIC_JPEG							0x0102			//JPEG�ļ�

#define NPC_D_MON_FILE_FORMAT_VESSEL_MP4						0x0301			//MP4�ļ�
#define NPC_D_MON_FILE_FORMAT_VESSEL_AVI						0x0301			//AVI�ļ�

//�������ඨ��
#define NPC_D_MON_LAND_KIND_SIMPCHINESE							0				//��������
#define NPC_D_MON_LAND_KIND_ENGLISH								1				//Ӣ��

//�ַ�������
#define NPC_D_MON_CHARSET_GB2312								0				//gb2312
#define NPC_D_MON_CHARSET_UTF8									1				//utf8

//�豸����Ȩ��λ����
#define NPC_D_MON_DEV_POP_REALPLAY								0x00000001		//ʵʱԤ��Ȩ�ޣ�����ȫ�ֺ�ͨ��Ȩ�ޣ�
#define NPC_D_MON_DEV_POP_PTZ_CTRL								0x00000002		//��̨����Ȩ�ޣ�����ȫ�ֺ�ͨ��Ȩ�ޣ�
#define NPC_D_MON_DEV_POP_TALK									0x00000004		//�����Խ�Ȩ�ޣ�����ȫ�ֺ�ͨ��Ȩ�ޣ�
#define NPC_D_MON_DEV_POP_QUERY_FILE							0x00000008		//¼���ļ���ѯȨ�ޣ�����ȫ�ֺ�ͨ��Ȩ�ޣ�
#define NPC_D_MON_DEV_POP_BACKPLAY								0x00000010		//¼��ط�Ȩ�ޣ�����ȫ�ֺ�ͨ��Ȩ�ޣ�
#define NPC_D_MON_DEV_POP_ALARM									0x00000020		//��������Ȩ�ޣ�ֻ��ȫ��Ȩ�ޣ�
#define NPC_D_MON_DEV_POP_GET_CONFIG							0x00000040		//��ѯ����Ȩ�ޣ�ֻ��ȫ��Ȩ�ޣ�
#define NPC_D_MON_DEV_POP_SET_CONFIG							0x00000080		//��������Ȩ�ޣ�ֻ��ȫ��Ȩ�ޣ�

//�豸����ģʽ����
//#define NPC_D_MON_DEV_CONN_MODE_NON								0				//δ����
//#define NPC_D_MON_DEV_CONN_MODE_P2P								1				//P2P����
//#define NPC_D_MON_DEV_CONN_MODE_TRANS							2				//��ת����
//#define NPC_D_MON_DEV_CONN_MODE_TCPDIRECT						3				//TCPֱ��
//#define NPC_D_MON_DEV_CONN_MODE_MEDIASTREAM						4				//��ý������

#define NPC_D_MON_DEV_CONN_TYPE_NON								0				//δ����
#define NPC_D_MON_DEV_CONN_TYPE_P2P								1				//P2P����
#define NPC_D_MON_DEV_CONN_TYPE_TRANS							2				//��ת����
#define NPC_D_MON_DEV_CONN_TYPE_TCPDIRECT						3				//TCPֱ��
#define NPC_D_MON_DEV_CONN_TYPE_MEDIASTREAM						4				//��ý������

//ͼƬ��ʽ����
#define NPC_D_MON_PIC_FORMAT_BMP								1				//BMP�ļ�
#define NPC_D_MON_PIC_FORMAT_JPEG								2				//JPEG�ļ�

//�ļ����Ͷ���
#define NPC_D_MON_FILE_TYPE_ALL									0				//�����ļ�����
#define NPC_D_MON_FILE_TYPE_RECORD								1				//¼���ļ�
#define NPC_D_MON_FILE_TYPE_PICTRUE								2				//�����ļ�

//�ļ�������ʽ����
#define NPC_D_MON_FILE_CREATE_MODE_ALL							0				//���з�ʽ
#define NPC_D_MON_FILE_CREATE_MODE_ALARM						1				//������ʽ
#define NPC_D_MON_FILE_CREATE_MODE_MANUAL						2				//�ֶ���ʽ
#define NPC_D_MON_FILE_CREATE_MODE_TIMER						3				//��ʱ��ʽ

//�����¼�����
#define NPC_D_MON_ALARM_EVENT_ALL								0				//���б����¼�
#define NPC_D_MON_ALARM_EVENT_FAULT								1				//�豸���ϱ���
#define NPC_D_MON_ALARM_EVENT_MOTION							2				//�ƶ���ⱨ��
#define NPC_D_MON_ALARM_EVENT_VIDEO_BLIND						3				//��Ƶ�ڵ�����
#define NPC_D_MON_ALARM_EVENT_VIDEO_LOSS						4				//��Ƶ��ʧ����
#define NPC_D_MON_ALARM_EVENT_PROBE								5				//̽ͷ�������ⲿ���뱨����
#define NPC_D_MON_ALARM_EVENT_PIR								6				//�����Ӧ����
#define NPC_D_MON_ALARM_EVENT_DOORBELL							7				//���屨��
#define NPC_D_MON_ALARM_EVENT_HDD_ERROR							8				//Ӳ�̴���
#define NPC_D_MON_ALARM_EVENT_HDD_FULL							9				//Ӳ����
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_CROSS_LINE				10				//Խ����ⱨ��
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_AREA_INTRUSION			11				//�������ֱ���
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_AREA_IN					12				//������뱨��
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_AREA_OUT				13				//�����뿪����
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_OBJECT_FORGET			14				//��Ʒ��������
#define NPC_D_MON_ALARM_EVENT_SMART_IPC_OBJECT_PICKUP			15				//��Ʒʰȡ����


//------------------------------------------------------------------------
//ý��֡ͷ����
typedef struct _NPC_S_MON_MEDIA_FRAME_HEAD
{
	NPC_INT										iMediaType;						//ý�����ͣ��μ�NPC_D_MON_MEDIA_TYPE_*����
	NPC_DWORD									dwTimestamp;					//ʱ���

	NPC_INT										iVideoCodecId;					//��Ƶ����ID���ο�NPC_D_MON_CODEC_ID_*����
	NPC_INT										iVideoWidth;					//��Ƶ���
	NPC_INT										iVideoHeight;					//��Ƶ�߶�
	NPC_INT										iVideoBitRate;					//��Ƶ����
	NPC_INT										iVideoFrameRate;				//��Ƶ֡��
	NPC_INT										iVideoFrameType;				//��Ƶ֡���ͣ��μ�NPC_D_MON_VIDEO_FRAME_TYPE_*����

	NPC_INT										iAudioCodecId;					//��Ƶ����ID���ο�NPC_D_MON_CODEC_ID_*����
	NPC_INT										iAudioBitRate;					//��Ƶ����
	NPC_INT										iAudioSampleRate;				//��Ƶ������
	NPC_INT										iAudioChNum;					//��Ƶ������

	NPC_INT										iFrameFlag;						//֡��־��0���ǽ���֡��1�����һ֡��2��ֹͣ����־���򲥷���������ֹͣ������ʵʱԤ����¼��ط���Ч�������ʵʱԤ����ֵΪ2��ʾ������ʾ��رս����������´򿪽�������
	NPC_DWORD									dwPlayPos;						//����λ�ã��룩��¼��ط���Ч
	NPC_DWORD									dwFileTotalLen;					//�ļ��ܳ��ȣ��룩��¼��ط���Ч

} NPC_S_MON_MEDIA_FRAME_HEAD, *PNPC_S_MON_MEDIA_FRAME_HEAD;

//ý���ͷ����
typedef struct _NPC_S_MON_MEDIA_PACKET_HEAD
{
	NPC_DWORD									dwPacketFlag;					//����־��ֵΪ0xFFFFFFFF
	NPC_INT										iPacketSize;					//����С�������ð�ͷ����
	NPC_BYTE									ucPacketType;					//�����ͣ�0������Ƶ����1��ͼƬ����2���Զ�������
	NPC_BYTE									ucPercent;						//�ٷֱȣ�ֵ��0~100
	NPC_BYTE									ucReserve[2];					//����

} NPC_S_MON_MEDIA_PACKET_HEAD, *PNPC_S_MON_MEDIA_PACKET_HEAD;

//�ļ�ͷ��Ϣ
typedef struct _NPC_S_MON_FILE_HEAD_INFO
{
	NPC_CHAR									sFileFlag[128];					//�ļ���ʶ��Ψһ��ʶ���ļ������ļ�ʱ����ԭ�����أ����ļ���
	NPC_INT										iChNo;							//ͨ����
	NPC_INT										iStreamNo;						//������
	NPC_INT										iFileType;						//�ļ����ͣ��μ�NPC_D_MON_FILE_TYPE_*����
	NPC_INT										iCreateMode;					//������ʽ���μ�NPC_D_MON_FILE_CREATE_MODE_*����
	NPC_INT										iAlarmEvent;					//�����¼����μ�NPC_D_MON_ALARM_EVENT_*���壬ֻ�д�����ʽΪNPC_D_MON_FILE_CREATE_MODE_ALARMʱ��Ч
	NPC_S_TD_DATE_TIME							tStartTime;						//�ļ���ʼʱ�䣬�����ļ�Ϊ���յ�ʱ��
	NPC_S_TD_DATE_TIME							tEndTime;						//�ļ�����ʱ�䣬�����ļ��ò�����Ч
	NPC_DWORD									dwFileTimeLen;					//�ļ���ʱ�����룩��¼���ļ���Ч
	NPC_DWORD									dwFileSize;						//�ļ���С����λ��KB��

	//���²�����iFileTypeֵΪNPC_D_MON_FILE_TYPE_RECORDʱ��Ч
	NPC_BOOL									bVideoFlag;						//��Ƶ��־��TRUE����ʾ����Ƶ��FALSE����ʾû����Ƶ
	NPC_BOOL									bAudioFlag;						//��Ƶ��־��TRUE����ʾ����Ƶ��FALSE����ʾû����Ƶ

	NPC_INT										iVideoCodecId;					//��Ƶ����ID���μ�NPC_D_MON_CODEC_ID_VEDIO_*����
	NPC_INT										iVideoFrameRate;				//��Ƶ֡��
	NPC_INT										iVideoBitRate;					//��Ƶ���ʣ�kbps��
	NPC_USHORT									usVideoWidth;					//��Ƶ���
	NPC_USHORT									usVideoHeight;					//��Ƶ�߶�

	NPC_INT										iAudioCodecId;					//��Ƶ����ID���μ�NPC_D_MON_CODEC_ID_AUDIO_*����
	NPC_INT										iAudioBitRate;					//��Ƶ���ʣ�kbps��
	NPC_INT										iAudioSampleRate;				//��Ƶ������
	NPC_INT										iAudioChNum;					//��Ƶ������

	//���²�����iFileTypeֵΪNPC_D_MON_FILE_TYPE_PICTRUEʱ��Ч
	NPC_INT										iPictureFormat;					//ͼƬ��ʽ���μ�NPC_D_MON_PIC_FORMAT_*����

} NPC_S_MON_FILE_HEAD_INFO, *PNPC_S_MON_FILE_HEAD_INFO;



#endif

