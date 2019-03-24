/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MON_VendorDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-11
 * Description   :  ���ƽ̨��������
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MON_VENDORDEF_H
#define __NPC_MON_VENDORDEF_H

#include "NPC_TypeDef.h"


//����������
#define NPC_D_MON_SERVER_TYPE_SMP_DISP							1				//���ȷ�����
#define NPC_D_MON_SERVER_TYPE_MON_AUTH							2				//��֤������
#define NPC_D_MON_SERVER_TYPE_SMP_DEVACC						4				//��ý��ƽ̨�豸���������
#define NPC_D_MON_SERVER_TYPE_SMP_UPCOMGW						5				//��ý��ƽ̨����ͨѶ���ط�������NAT��͸ͨѶ���أ�
#define NPC_D_MON_SERVER_TYPE_SMP_HKSP							6				//ԭ������ý�������(HKSP)
#define NPC_D_MON_SERVER_TYPE_SMP_RTSP							7				//RTSP��ý�������
#define NPC_D_MON_SERVER_TYPE_SMP_HTTP							8				//HTTP��ý�������
#define NPC_D_MON_SERVER_TYPE_SMP_ALARM							9				//����������
#define NPC_D_MON_SERVER_TYPE_SMP_VOD							10				//VOD������
#define NPC_D_MON_SERVER_TYPE_SMP_PATR							11				//Ѳ�������
#define NPC_D_MON_SERVER_TYPE_SMP_UST							12				//NAT��͸UDP��������UST��������
#define NPC_D_MON_SERVER_TYPE_SMP_SOAP							13				//SOAP������
#define NPC_D_MON_SERVER_TYPE_SMP_TRANS							14				//ת��������

//�ͻ������Ͷ���
#define NPC_D_MON_CLIENT_TYPE_PC								1				//PC�ͻ���
#define NPC_D_MON_CLIENT_TYPE_IPHONE							2				//IPHONE
#define NPC_D_MON_CLIENT_TYPE_ANDRIOD_PHONE						3				//ANDRIOD�ֻ�
#define NPC_D_MON_CLIENT_TYPE_IPAD								4				//IPAD
#define NPC_D_MON_CLIENT_TYPE_ANDRIOD_PANEL						5				//ANDRIODƽ��
#define NPC_D_MON_CLIENT_TYPE_WEB_OCX							6				//WEB�ؼ�
#define NPC_D_MON_CLIENT_TYPE_APPLE_MAC							7				//ƻ��Mac
#define NPC_D_MON_CLIENT_TYPE_WINDOWS_PHONE						8				//windows phone
#define NPC_D_MON_CLIENT_TYPE_APPLE_SAFARI						9				//ƻ��Safari

#define NPC_D_MON_CLIENT_TYPE_VIALARM_PC						30				//С����������PC�ͻ���

//�ͻ���ʶ����
#define NPC_D_MON_CLIENT_FLAG_TDKS								10				//��ؿ���

//���̻�Э��ID����
#define NPC_D_MON_VENDOR_ID_NSPB								1001			//������ý��Э�飨bit��
#define NPC_D_MON_VENDOR_ID_NSPX								1002			//������ý��Э�飨XML��
#define NPC_D_MON_VENDOR_ID_NSPJ								1003			//������ý��Э�飨JSON��
#define NPC_D_MON_VENDOR_ID_OWSP								1004			//������ý��Э�飨OWSP��
#define NPC_D_MON_VENDOR_ID_HKSP								1005			//ԭ������ý�������Э�飨HKSP��
#define NPC_D_MON_VENDOR_ID_FCAM								1006			//�ļ������Э�飨FCAM��
#define NPC_D_MON_VENDOR_ID_HMCP								1007			//���Ƽ��ͨѶЭ�飨HMCP��
#define NPC_D_MON_VENDOR_ID_HDTP								1008			//�����豸����Э�飨HDTP��
#define NPC_D_MON_VENDOR_ID_UMSP								1009			//UMSP
#define NPC_D_MON_VENDOR_ID_EPMY								1010			//EPMY

#define NPC_D_MON_VENDOR_ID_RTSP								1011			//RTSP
#define NPC_D_MON_VENDOR_ID_HTTP								1012			//HTTP
#define NPC_D_MON_VENDOR_ID_SIP									1013			//SIP
#define NPC_D_MON_VENDOR_ID_RTMP								1014			//RTMP

#define NPC_D_MON_VENDOR_ID_HZHK								2010			//���ݺ�����ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_HKPU								2011			//���ݺ�����ģʽ
#define NPC_D_MON_VENDOR_ID_HZDH								2020			//���ݴ󻪣�ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_SZRM								2030			//����������ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_SZHH								2040			//���ڻƺӣ�ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_SZHB								2050			//���ں��ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_HZXM								2060			//����������ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_ZSLB								2070			//��ɽ������ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_CDSB								2080			//�ɶ�������ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_SHHW								2090			//�Ϻ��ά��ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_JSLP								2100			//��������ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_SHTL								2110			//�Ϻ�ͨ��
#define NPC_D_MON_VENDOR_ID_SZLC								2120			//�����ɳۣ�ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_WST									2130			//����ͨ��ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_GZQH								2140			//������ã�ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_ALRS								2150			//�������ӣ�ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_GZJK								2160			//���ݼѿɣ�ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_SZQH								2170			//�����캲��ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_HHWS								2180			//������ӣ�ͨ�ò���������
#define NPC_D_MON_VENDOR_ID_HZZN								2190			//������ŵ��ͨ�ò���������



#endif
