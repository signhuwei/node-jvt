#ifndef _COMMDEVICESDK_
#define _COMMDEVICESDK_


#define COMMDEVICE_API  extern "C" __declspec(dllexport)

#pragma pack(1)

/**************************************************************
人脸抓拍参数配置类型
***************************************************************/
typedef enum _FACE_CONFIG_TYPE
{
	SDK_SMARTFACE_COMMON = 0x01,		//人脸基本参数配置
	SDK_SMARTFACE_AREA_DETECT,			//人脸检测区域
	SDK_SMARTFACE_WBLIST,				//黑白名单，暂时没做参数配置
	SDK_SMARTFACE_VERSION,				//版本
}FACE_CONFIG_TYPE;



typedef struct _SDK_SMART_FACE_S
{
	INT 		nEnable;
	INT 		nSensitivity;
	BYTE 		nExposureMode; 							//人脸曝光模式
	BYTE		nRes;
	BYTE 		nTrackmode;								//人脸跟踪  		 0:关闭 1:过滤跟踪 2:非过滤跟踪
	BYTE        nFtpEnable;								//FTP上传开关	0:关闭 1:开启
	INT 		nFaceSize;								//人脸识别最小尺寸(30~300)
	BYTE		nFaceBLC;
	BYTE 		nParamCheckFlag;
	BYTE		byRes[54];
}SDK_SMART_FACE;


//区域
typedef struct _AREA_RECT_S
{
	short			x;									//X坐标
	short			y;									//Y坐标
	short			w;									//宽度
	short			h;									//高度
}AREA_RECT_S;


typedef struct _SDK_VI_DETECT_S
{
	DWORD				dwSize;			
	INT					bEnable;
	AREA_RECT_S			stFaceMaskArea;
	BYTE				byRes[32];
}SDK_VI_DETECT;


typedef struct _SDK_SMART_VERSION_S
{
	char szLib_version[16] ;    
	char szModel_version[16];
	BYTE  nbyLic;
	BYTE  byRes[7];
}SDK_SMART_VERSION;

#pragma pack()


/**************************************************************
brief:		功能 		获取图片回调函数
param[in] 	pBuf 		数据缓存
param[in] 	nDataLen	数据长度
param[in]	bOver		表示是否最后一包数据:0表示不是，1表示是
return		返回结果	1表示正常，其他失败
***************************************************************/
typedef int (__stdcall *SDK_GetJpgDataCB)( char *pBuf, int nDataLen, int bOver ,void *pConfig);



/**************************************************************
brief:		功能 		获取图片回调函数
param[in] 	pBuf 		数据缓存
param[in] 	nDataLen	数据长度
param[in]	bOver		表示是否最后一包数据:0表示不是，1表示是
return		返回结果	1表示正常，其他失败
***************************************************************/
typedef int (__stdcall *SDK_GetSendPictureState)( int nSendPercent, void *pConfig );



/**************************************************************
brief:		功能 		初始化SDK
return		返回结果	1表示正常，其他失败
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_init(void);


/**************************************************************
brief:		功能 		登录设备
param[in] 	ip	 		设备ip地址
param[in] 	port		设备端口
param[in]	usrname		登录用户名
param[in]	pwd			登录密码
return		返回结果socket	socket大于0表示登录成功	
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_login(char *ip, int port, char* usrname, char* pwd);


/**************************************************************
brief:		功能 		注销设备
return		返回结果	0表示注销正常，其他失败
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_logout(int socket );


/**************************************************************
brief:		功能 		获取参数配置
param[in] 	sockfd 		登录设备的socket
param[in] 	configType	获取参数配置类型
param[in]	pData		获取数据缓存
return		返回结果	1表示获取正常，其他失败
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_get_config(int sockfd, FACE_CONFIG_TYPE configType, char *pData );


/**************************************************************
brief:		功能 		设置参数配置
param[in] 	sockfd 		登录设备的socket
param[in] 	configType	获取参数配置类型
param[in]	pData		数据缓存
return		返回结果	1表示设置正常，其他失败
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_set_config(int sockfd, FACE_CONFIG_TYPE configType, char *pData);


/**************************************************************
brief:		功能 		获取抓拍图片
param[in] 	sockfd 		登录设备的socket
param[in] 	getJpgDataCB获取图片数据回调函数
return		返回结果	0表示获取正常，其他失败
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_open_jpg_stream(int sockfd, SDK_GetJpgDataCB getJpgDataCB,void *pConfig);



/**************************************************************
brief:		功能 		关闭图片获取
param[in] 	sockfd 		登录设备的socket
return		返回结果	0表示关闭正常，其他失败
***************************************************************/
COMMDEVICE_API int __stdcall sdk_device_close_jpg_stream(int sockfd);



/**************************************************************
brief:		功能 		发送一张图片
param[in] 	filepath 	图片路径
param[in]   ip          目标IP地址
return		返回结果	0表示发送正常，其他失败
***************************************************************/

COMMDEVICE_API int __stdcall sdk_device_send_one_jpg(char *filepath,char *ip,unsigned char  picType,char *pPicNumber,SDK_GetSendPictureState pCallback,void *pConfig);


#endif


//DESCRIPTION 'SmartFace Windows Dynamic Link Library'