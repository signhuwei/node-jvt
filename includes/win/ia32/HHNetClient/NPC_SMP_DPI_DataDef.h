/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_SMP_DPI_DataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-15
 * Description   :  厂商设备接入接口数据定义部分
 *----------------------------------------------------------------------------*/

#ifndef __NPC_SMP_DPI_DATADEF_H
#define __NPC_SMP_DPI_DATADEF_H

#include "NPC_TypeDef.h"
#include "NPC_MON_DataDef.h"
#include "NPC_LOG_Server.h"


//导出导入定义
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
