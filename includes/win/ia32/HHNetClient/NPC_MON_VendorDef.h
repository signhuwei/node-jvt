/*----------------------------------------------------------------------------
 * Copyright(c)  :  NPC CORPORTAION All Rights Reserved                       
 * FileName      :  NPC_MON_VendorDef.h
 * Version       :  1.0
 * Author        :  CCH
 * DateTime      :  2012-03-11
 * Description   :  监控平台常量定义
 *----------------------------------------------------------------------------*/

#ifndef __NPC_MON_VENDORDEF_H
#define __NPC_MON_VENDORDEF_H

#include "NPC_TypeDef.h"


//服务器类型
#define NPC_D_MON_SERVER_TYPE_SMP_DISP							1				//调度服务器
#define NPC_D_MON_SERVER_TYPE_MON_AUTH							2				//认证服务器
#define NPC_D_MON_SERVER_TYPE_SMP_DEVACC						4				//流媒体平台设备接入服务器
#define NPC_D_MON_SERVER_TYPE_SMP_UPCOMGW						5				//流媒体平台上连通讯网关服务器（NAT穿透通讯网关）
#define NPC_D_MON_SERVER_TYPE_SMP_HKSP							6				//原华科流媒体服务器(HKSP)
#define NPC_D_MON_SERVER_TYPE_SMP_RTSP							7				//RTSP流媒体服务器
#define NPC_D_MON_SERVER_TYPE_SMP_HTTP							8				//HTTP流媒体服务器
#define NPC_D_MON_SERVER_TYPE_SMP_ALARM							9				//报警服务器
#define NPC_D_MON_SERVER_TYPE_SMP_VOD							10				//VOD服务器
#define NPC_D_MON_SERVER_TYPE_SMP_PATR							11				//巡检服务器
#define NPC_D_MON_SERVER_TYPE_SMP_UST							12				//NAT穿透UDP服务器（UST服务器）
#define NPC_D_MON_SERVER_TYPE_SMP_SOAP							13				//SOAP服务器
#define NPC_D_MON_SERVER_TYPE_SMP_TRANS							14				//转发服务器

//客户端类型定义
#define NPC_D_MON_CLIENT_TYPE_PC								1				//PC客户端
#define NPC_D_MON_CLIENT_TYPE_IPHONE							2				//IPHONE
#define NPC_D_MON_CLIENT_TYPE_ANDRIOD_PHONE						3				//ANDRIOD手机
#define NPC_D_MON_CLIENT_TYPE_IPAD								4				//IPAD
#define NPC_D_MON_CLIENT_TYPE_ANDRIOD_PANEL						5				//ANDRIOD平板
#define NPC_D_MON_CLIENT_TYPE_WEB_OCX							6				//WEB控件
#define NPC_D_MON_CLIENT_TYPE_APPLE_MAC							7				//苹果Mac
#define NPC_D_MON_CLIENT_TYPE_WINDOWS_PHONE						8				//windows phone
#define NPC_D_MON_CLIENT_TYPE_APPLE_SAFARI						9				//苹果Safari

#define NPC_D_MON_CLIENT_TYPE_VIALARM_PC						30				//小区报警监听PC客户端

//客户标识定义
#define NPC_D_MON_CLIENT_FLAG_TDKS								10				//天地宽视

//厂商或协议ID定义
#define NPC_D_MON_VENDOR_ID_NSPB								1001			//华科流媒体协议（bit）
#define NPC_D_MON_VENDOR_ID_NSPX								1002			//华科流媒体协议（XML）
#define NPC_D_MON_VENDOR_ID_NSPJ								1003			//华科流媒体协议（JSON）
#define NPC_D_MON_VENDOR_ID_OWSP								1004			//华科流媒体协议（OWSP）
#define NPC_D_MON_VENDOR_ID_HKSP								1005			//原华科流媒体服务器协议（HKSP）
#define NPC_D_MON_VENDOR_ID_FCAM								1006			//文件摄像机协议（FCAM）
#define NPC_D_MON_VENDOR_ID_HMCP								1007			//华科监控通讯协议（HMCP）
#define NPC_D_MON_VENDOR_ID_HDTP								1008			//华科设备上连协议（HDTP）
#define NPC_D_MON_VENDOR_ID_UMSP								1009			//UMSP
#define NPC_D_MON_VENDOR_ID_EPMY								1010			//EPMY

#define NPC_D_MON_VENDOR_ID_RTSP								1011			//RTSP
#define NPC_D_MON_VENDOR_ID_HTTP								1012			//HTTP
#define NPC_D_MON_VENDOR_ID_SIP									1013			//SIP
#define NPC_D_MON_VENDOR_ID_RTMP								1014			//RTMP

#define NPC_D_MON_VENDOR_ID_HZHK								2010			//杭州海康（通用参数解析）
#define NPC_D_MON_VENDOR_ID_HKPU								2011			//杭州海康推模式
#define NPC_D_MON_VENDOR_ID_HZDH								2020			//杭州大华（通用参数解析）
#define NPC_D_MON_VENDOR_ID_SZRM								2030			//深圳锐明（通用参数解析）
#define NPC_D_MON_VENDOR_ID_SZHH								2040			//深圳黄河（通用参数解析）
#define NPC_D_MON_VENDOR_ID_SZHB								2050			//深圳汉邦（通用参数解析）
#define NPC_D_MON_VENDOR_ID_HZXM								2060			//杭州雄迈（通用参数解析）
#define NPC_D_MON_VENDOR_ID_ZSLB								2070			//中山立堡（通用参数解析）
#define NPC_D_MON_VENDOR_ID_CDSB								2080			//成都索贝（通用参数解析）
#define NPC_D_MON_VENDOR_ID_SHHW								2090			//上海皓维（通用参数解析）
#define NPC_D_MON_VENDOR_ID_JSLP								2100			//金三立（通用参数解析）
#define NPC_D_MON_VENDOR_ID_SHTL								2110			//上海通立
#define NPC_D_MON_VENDOR_ID_SZLC								2120			//深圳郎驰（通用参数解析）
#define NPC_D_MON_VENDOR_ID_WST									2130			//网视通（通用参数解析）
#define NPC_D_MON_VENDOR_ID_GZQH								2140			//广州奇幻（通用参数解析）
#define NPC_D_MON_VENDOR_ID_ALRS								2150			//安联锐视（通用参数解析）
#define NPC_D_MON_VENDOR_ID_GZJK								2160			//广州佳可（通用参数解析）
#define NPC_D_MON_VENDOR_ID_SZQH								2170			//深圳旗翰（通用参数解析）
#define NPC_D_MON_VENDOR_ID_HHWS								2180			//瀚晖威视（通用参数解析）
#define NPC_D_MON_VENDOR_ID_HZZN								2190			//杭州智诺（通用参数解析）



#endif
