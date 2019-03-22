
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef _INCLUDE_PAL_CAMERA_H
#define _INCLUDE_PAL_CAMERA_H


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// ���ð�ƽ�����
int camera_set_scene(uint scene);

// ������ҹģʽ
int camera_set_dnc_mode(uint mode);

// ��ȡ֧�ֵ��ع�ȼ���
// ����ֵ<0����ȡʧ�ܣ�>=0��ʾ�ȼ���������ȼ�����������speeds�С�
// speeds���鳤�ȱ����㹻��ȡ16����ˡ�
int camera_get_exposure_speeds(int vstd, uint *speeds);

// �����ع�ȼ�
// 0     �Զ��ع�
// 1~n-1 �ֶ��ع�ȼ�
// n     ��ʱ�������޵��Զ��ع�
// n+1   �Զ���ʱ���ֶ��ع�
// (n��ʾ֧�ֵ��ع�ȼ�������camera_get_exposure_speeds�ӿڷ���ֵ��
// value1:�Զ��ع�ʱ�����޻����ֶ��ع��Զ���ʱ�䣬΢��Ϊ��λ��ȡֵ100us~80000us
// value2:�Զ��ع�ʱ�����ޣ�΢��Ϊ��λ��ȡֵ100us~80000us���ұ��벻С��exposureValue1ȡֵ
int camera_set_exposure_level(int level, uint value1, uint value2);

// ��������ֵ
// gain:�̶�����ֵ�������Զ���������ޣ�ȡֵ0-100��
// auto_gain:�Զ����棬0-��������1-������ͬʱgain��Ա��ʾ�Զ���������ޡ�
int camera_set_gain(int gain, int auto_gain);

// ���òο���ƽֵ
// level:�ο���ƽֵ��ȡֵ0-100��
int camera_set_refrence_level(int level);

// ��ȡ�ο���ƽֵ
int camera_get_refrence_level(void);

// ��ȡƽ������ֵ
int camera_get_luminance(void);

//��ȡ״̬��,>=0��ʾ״̬����,<0��ʾ״̬�쳣
int camera_get_status(int *status);

//���ڵ���
int camera_debug(char *cmd);

//����xm 2a��İ汾��Ϣ
int camera_aew_get_version(char *str);

//����WB����
void  camera_get_wb_params(void *param);

//�����Զ���Ȧģʽ
int camera_set_aperture(uint mode);

//���ñ��ⲹ��ģʽ
int camera_set_blc(uint mode);

//ͼƬ���·�ת
int camera_set_flip(uint PictureFlip);		

//ͼƬ���ҷ�ת
int camera_set_mirror(uint PictureMirror);

///�����չ�Ʒ�������
//en = 0 ������ en= 1����
int camera_set_reject_flicker(uint en);

///�������������Ź���
///es_shutterΪ0����������>0Ϊ֡����Ŀǰȡֵ2,4,8,CMS��,��ӦCMS�Ͻ�����/��/ǿ
int camera_set_es_shutter(uint es_shutter);

//IR-CUT�л�ģʽ
int camera_set_ircut_mode(int ircut_mode);

//��ҹת����ֵ 10-50��Ĭ��20
int camera_set_dnc_thr(int dnc_thr); 

//ae���������� 1-10��Ĭ��Ϊ5
int camera_set_ae_sensitivity(int ae_sensitivity); 

//  2,�޴˹���,����1�� ����0��
int camera_get_Infrared();

//�����������������
int camera_save_debug_cmd(char* cmd);

//����IRCUT : 0-ҹ��ģʽ 1-����ģʽ������ֵ: 0-�ɹ�   1-��֧��   -1-ʧ��
int camera_set_Ircut(int mode);

//daynight:����or����
//nf_level:  noise filter �ȼ���0-5,0���˲���1-5 ֵԽ���˲�Ч��Խ���ԣ�Ĭ��Ϊ5
int CameraSetNFLevel(int daynight, int nf_level);

//swap 0:������ 1������
int CameraSwapICR(int swap);

#ifdef __cplusplus
}
#endif // __cplusplus


#endif //_INCLUDE_PAL_CAMERA_H
