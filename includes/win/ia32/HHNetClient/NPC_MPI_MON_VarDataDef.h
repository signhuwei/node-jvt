/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_VarDataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-09-18
 * Description   :  ��ؿͻ��˿ɱ����ݶ���
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_VARDATADEF_H
#define __NPC_MPI_MON_VARDATADEF_H

#include "NPC_TypeDef.h"


//�û�Ȩ�޶���
#define NPC_D_MPI_MON_USER_POP_ADD_CAMERA						1			//����������Ŀ¼��������ȫ��Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_DEL_CAMERA						2			//ɾ���������Ŀ¼��������ȫ��Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_CH_CAMERA_CONN_PARAM				3			//�޸���������Ӳ�����ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_CH_CAMERA_NAME					4			//�޸���������ƣ�ȫ��/�豸Ȩ�ޣ�

#define NPC_D_MPI_MON_USER_POP_TRY_DISABLE						60			//���ý��ã��豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_REALPLAY							61			//ʵʱԤ����ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_MANUAL_RECORD					62			//�ֶ�¼��ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_PTZ								63			//��̨���ƣ�ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_BACKPLAY							64			//�ط�¼��ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_RECV_ALARM						65			//���ձ�����ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_DEV_EMP							66			//�豸��Ȩ��ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_ARMING							67			//����������ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_VOC_TALK							68			//�����Խ���ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_LOCAL_RECORD						69			//����¼��ȫ��/�豸Ȩ�ޣ�
#define NPC_D_MPI_MON_USER_POP_LOCAL_PHOTO						70			//�������գ�ȫ��/�豸Ȩ�ޣ�

//ע���û�Ȩ��ֵ+100Ϊ��ֹȨ�ޣ�����������Ȩ��ֵΪ1����101Ϊ��ֹ��������Ȩ��


//�ͻ������ò���ID����
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_USER_REG				1			//�Ƿ��ṩ�û�ע�Ṧ�ܣ�0�����ã�1������
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_USER_UNREG			2			//�Ƿ��ṩ�û�ע�����ܣ�0�����ã�1������
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_TRYOUT				3			//�Ƿ��ṩ���ù��ܣ�0�����ã�1������
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_DEV_MANAGER			4			//�Ƿ��ṩ�豸�����ܣ�0�����ã�1������
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_PTZ					5			//�Ƿ��ṩ��̨���ƹ��ܣ�0�����ã�1������
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_BACKPLAY				6			//�Ƿ��ṩ¼��طŹ��ܣ�0�����ã�1������
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_UP_LOG_SRV			7			//�Ƿ������ϴ���־����0�����ã�1������

#define NPC_D_MPI_MON_CLIENT_CFGID_IVAR_PLAY_TIMEOUT			50			//������Ƶ��ʱʱ�������룩


#endif


