/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_SMP_DPI_DataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-15
 * Description   :  �����豸����ӿ����ݶ��岿��
 *----------------------------------------------------------------------------*/

#ifndef __NPC_SMP_DPI_DATADEF_H
#define __NPC_SMP_DPI_DATADEF_H

#include "NPC_TypeDef.h"
#include "NPC_MON_DataDef.h"
#include "NPC_LOG_Server.h"


//�������붨��
#ifdef _WIN32
	#ifdef _NPC_SMP_DPI_EXPORTS
		#define NPC_SMP_DPI_API __declspec(dllexport)
	#else
		#ifdef _NPC_SMP_DPI_IMPORT
			#define NPC_SMP_DPI_API __declspec(dllexport)
		#else
			#define NPC_SMP_DPI_API
		#endif
	#endif
#else
	#define NPC_SMP_DPI_API
#endif



#endif
