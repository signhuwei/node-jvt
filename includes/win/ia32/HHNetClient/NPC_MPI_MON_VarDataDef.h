/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MPI_MON_VarDataDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-09-18
 * Description   :  监控客户端可变数据定义
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MPI_MON_VARDATADEF_H
#define __NPC_MPI_MON_VARDATADEF_H

#include "NPC_TypeDef.h"


//用户权限定义
#define NPC_D_MPI_MON_USER_POP_ADD_CAMERA						1			//添加摄像机或目录（仅限于全局权限）
#define NPC_D_MPI_MON_USER_POP_DEL_CAMERA						2			//删除摄像机或目录（仅限于全局权限）
#define NPC_D_MPI_MON_USER_POP_CH_CAMERA_CONN_PARAM				3			//修改摄像机连接参数（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_CH_CAMERA_NAME					4			//修改摄像机名称（全局/设备权限）

#define NPC_D_MPI_MON_USER_POP_TRY_DISABLE						60			//试用禁用（设备权限）
#define NPC_D_MPI_MON_USER_POP_REALPLAY							61			//实时预览（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_MANUAL_RECORD					62			//手动录像（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_PTZ								63			//云台控制（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_BACKPLAY							64			//回放录像（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_RECV_ALARM						65			//接收报警（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_DEV_EMP							66			//设备授权（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_ARMING							67			//布防撤防（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_VOC_TALK							68			//语音对讲（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_LOCAL_RECORD						69			//本地录像（全局/设备权限）
#define NPC_D_MPI_MON_USER_POP_LOCAL_PHOTO						70			//本地拍照（全局/设备权限）

//注：用户权限值+100为禁止权限，如添加摄像机权限值为1，则101为禁止添加摄像机权限


//客户端配置参数ID定义
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_USER_REG				1			//是否提供用户注册功能，0：禁用，1：启用
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_USER_UNREG			2			//是否提供用户注销功能，0：禁用，1：启用
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_TRYOUT				3			//是否提供试用功能，0：禁用，1：启用
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_DEV_MANAGER			4			//是否提供设备管理功能，0：禁用，1：启用
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_PTZ					5			//是否提供云台控制功能，0：禁用，1：启用
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_BACKPLAY				6			//是否提供录像回放功能，0：禁用，1：启用
#define NPC_D_MPI_MON_CLIENT_CFGID_ENABLE_UP_LOG_SRV			7			//是否启动上传日志服务，0：禁用，1：启用

#define NPC_D_MPI_MON_CLIENT_CFGID_IVAR_PLAY_TIMEOUT			50			//播放视频超时时长（毫秒）


#endif


