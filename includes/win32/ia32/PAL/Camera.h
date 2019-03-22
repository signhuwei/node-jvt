
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

// 设置白平衡参数
int camera_set_scene(uint scene);

// 设置日夜模式
int camera_set_dnc_mode(uint mode);

// 获取支持的曝光等级数
// 返回值<0，获取失败，>=0表示等级数，具体等级保存在数组speeds中。
// speeds数组长度必须足够大，取16差不多了。
int camera_get_exposure_speeds(int vstd, uint *speeds);

// 设置曝光等级
// 0     自动曝光
// 1~n-1 手动曝光等级
// n     带时间上下限的自动曝光
// n+1   自定义时间手动曝光
// (n表示支持的曝光等级数，即camera_get_exposure_speeds接口返回值）
// value1:自动曝光时间下限或者手动曝光自定义时间，微秒为单位，取值100us~80000us
// value2:自动曝光时间上限，微秒为单位，取值100us~80000us，且必须不小于exposureValue1取值
int camera_set_exposure_level(int level, uint value1, uint value2);

// 设置增益值
// gain:固定增益值，或者自动增益的上限，取值0-100。
// auto_gain:自动增益，0-不开启，1-开启，同时gain成员表示自动增益的上限。
int camera_set_gain(int gain, int auto_gain);

// 设置参考电平值
// level:参考电平值，取值0-100。
int camera_set_refrence_level(int level);

// 获取参考电平值
int camera_get_refrence_level(void);

// 获取平均亮度值
int camera_get_luminance(void);

//获取状态码,>=0表示状态正常,<0表示状态异常
int camera_get_status(int *status);

//用于调试
int camera_debug(char *cmd);

//返回xm 2a库的版本信息
int camera_aew_get_version(char *str);

//返回WB增益
void  camera_get_wb_params(void *param);

//设置自动光圈模式
int camera_set_aperture(uint mode);

//设置背光补偿模式
int camera_set_blc(uint mode);

//图片上下翻转
int camera_set_flip(uint PictureFlip);		

//图片左右翻转
int camera_set_mirror(uint PictureMirror);

///开启日光灯防闪功能
//en = 0 不开启 en= 1开启
int camera_set_reject_flicker(uint en);

///开启电子慢快门功能
///es_shutter为0，不开启，>0为帧数，目前取值2,4,8,CMS上,对应CMS上界面弱/中/强
int camera_set_es_shutter(uint es_shutter);

//IR-CUT切换模式
int camera_set_ircut_mode(int ircut_mode);

//日夜转换阈值 10-50，默认20
int camera_set_dnc_thr(int dnc_thr); 

//ae灵敏度配置 1-10，默认为5
int camera_set_ae_sensitivity(int ae_sensitivity); 

//  2,无此功能,返回1开 返回0关
int camera_get_Infrared();

//保存摄像机调试命令
int camera_save_debug_cmd(char* cmd);

//设置IRCUT : 0-夜间模式 1-白天模式；返回值: 0-成功   1-不支持   -1-失败
int camera_set_Ircut(int mode);

//daynight:白天or晚上
//nf_level:  noise filter 等级，0-5,0不滤波，1-5 值越大滤波效果越明显，默认为5
int CameraSetNFLevel(int daynight, int nf_level);

//swap 0:正常序 1：反序
int CameraSwapICR(int swap);

#ifdef __cplusplus
}
#endif // __cplusplus


#endif //_INCLUDE_PAL_CAMERA_H
