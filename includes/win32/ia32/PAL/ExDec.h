#ifndef __EX_DECODE_20110812_H
#define __EX_DECODE_20110812_H
#ifdef __cplusplus
extern "C"
{
#endif
#define MAX_HVR_CHNCAP			32

//用于区分需要屏蔽的分辨率，使用时用对应掩码
//目前只在PageDigitalChannelInfo和Opconfig里调用
enum HVR_RESOLUTION
{
	HVR_CIF = 0,
	HVR_HD1,
	HVR_D1,
	HVR_960H,
	HVR_720P,
	HVR_1080P,	
	HVR_960P,
	HVR_WUXGA,
	HVR_3M,
	HVR_5M,
	HVR_NR = 10,
	HVR_1080N = 10,
	HVR_4M,
	HVR_6M,
	HVR_8M,
	HVR_12M,
	HVR_4K,
	HVR_EX_NR=16,
	HVR_720N=16,
	HVR_WSVGA,
	HVR_RES2,
	HVR_RES3,
	HVR_RES4,
	HVR_RES5,
	HVR_RES6,
	HVR_EX_V2_NR,
};

typedef struct HVR_CHNCAP //改用HVR_CHNCAPV2，为了兼容老的保留
{
	int nD1Chn;		// 支持的D1路数
	int n960HChn;	// 支持的960H路数
	int n720PChn;	// 支持的720P路数
	int n1080PChn;	// 支持的1080P路数
	int nCIFChn;	//支持的CIF通道数
	int nHD1Chn;	//支持的HD1通道数
	unsigned char nPlayChn; //支持回放路数
	unsigned char nDigiTalChn; //支持最大数字通道路数
	unsigned char n960PChn; //支持的960P通道数
	unsigned char n3MChn; //支持的3M通道数
	unsigned char n5MChn; //支持的5M通道数
	unsigned char nWUXGAChn; //支持的WUXGA通道数
	unsigned char n1080NChn;//支持1080N通道数
	unsigned char n4MChn;//支持4M通道数
	#ifdef _USE_4K_MODE //modify by luo
	unsigned char n4KChn;	//支持4K通道数
	#endif
}HVR_CHNCAP, *PHVR_CHNCAP;

typedef struct HVR_CHNCAPV2
{
	unsigned char nD1Chn;		// 支持的D1路数
	unsigned char n960HChn;	// 支持的960H路数
	unsigned char n720PChn;	// 支持的720P路数
	unsigned char n1080PChn;	// 支持的1080P路数
	unsigned char nCIFChn;	//支持的CIF通道数
	unsigned char nHD1Chn;	//支持的HD1通道数
	unsigned char nPlayChn; //支持回放路数
	unsigned char nDigiTalChn; //支持最大数字通道路数
	unsigned char n960PChn; //支持的960P通道数
	unsigned char n3MChn; //支持的3M通道数
	unsigned char n5MChn; //支持的5M通道数
	unsigned char nWUXGAChn; //支持的WUXGA通道数
	unsigned char n1080NChn;//支持1080N通道数
	unsigned char n4MChn;//支持4M通道数
	unsigned char n720NChn;//支持720N通道数
	unsigned char nWSVGAChn;//支持WSVGA通道数
	#ifdef _USE_4K_MODE //modify by luo
	unsigned char n4KChn;	//支持4K通道数
	#endif
	unsigned char nRes[16];
}HVR_CHNCAPV2, *PHVR_CHNCAPV2;

struct DigitalChCap
{
	HVR_CHNCAPV2 DigChnCap[HVR_EX_V2_NR][4];
};

typedef struct CAPTURE_HVRCAP //改用CAPTURE_HVRCAPV2，为了兼容老的保留
{
	HVR_CHNCAP DigitalCap;		// 支持的数字通道信息
	HVR_CHNCAP AnalogCap;		// 支持的模拟通道信息
}CAPTURE_HVRCAP, *PCAPTURE_HVRCAP;

typedef struct CAPTURE_HVRCAPV2
{
	HVR_CHNCAPV2 DigitalCap;		// 支持的数字通道信息
	HVR_CHNCAPV2 AnalogCap;		// 支持的模拟通道信息
}CAPTURE_HVRCAPV2, *PCAPTURE_HVRCAPV2;

typedef struct CAPTURE_TOTAL_HVRCAP //改用CAPTURE_TOTAL_HVRCAPV2，为了兼容老的保留
{
	int		nHVRCap;			// 实际支持的模式
	CAPTURE_HVRCAP	HVRCap[MAX_HVR_CHNCAP];		// 所有模式的汇总
}CAPTURE_TOTAL_HVRCAP, *PCAPTURE_TOTAL_HVRCAP;

typedef struct CAPTURE_TOTAL_HVRCAPV2
{
	int		nHVRCap;			// 实际支持的模式
	CAPTURE_HVRCAPV2	HVRCap[MAX_HVR_CHNCAP];		// 所有模式的汇总
}CAPTURE_TOTAL_HVRCAPV2, *PCAPTURE_TOTAL_HVRCAPV2;
 
///不能直接调用，调用封装接口CaptureGetCurHVRCapEx
///  
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAP的指针。
/// \retval 0  获取成功。
/// \retval -1  获取失败。
int CaptureSetHVRCap(const CAPTURE_HVRCAP *pHVRCap); //改用CaptureSetHVRCapV2，为了兼容老的库保留

///不能直接调用，调用封装接口CaptureGetCurHVRCapEx
///  
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAPV2的指针。
/// \retval 0  获取成功。
/// \retval -1  获取失败。
#ifdef LINUX
int CaptureSetHVRCapV2(const CAPTURE_HVRCAPV2 *pHVRCap)  __attribute__ ((weak));
#else
int CaptureSetHVRCapV2(const CAPTURE_HVRCAPV2 *pHVRCap);
#endif


/// 设置HVR的应用模式
/// CaptureSetHVRCap封装接口，便于统一5000系列NVR的结构体不一样
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAP的指针。
/// \retval 0  获取成功。
/// \retval -1  获取失败
int CaptureSetHVRCapEx(const CAPTURE_HVRCAPV2 *pHVRCap); 

///不能直接调用，调用封装接口CaptureGetCurHVRCapEx
////
/// 
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAP的指针。
/// \retval 0  获取成功。
/// \retval -1  获取失败。
int CaptureGetCurHVRCap(CAPTURE_HVRCAP *pHVRCap);//改用CaptureGetCurHVRCapV2，为了兼容老的库保留

///不能直接调用，调用封装接口CaptureGetCurHVRCapEx
////
/// 
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAPV2的指针。
/// \retval 0  获取成功。
/// \retval -1  获取失败。
#ifdef LINUX
int CaptureGetCurHVRCapV2(CAPTURE_HVRCAPV2 *pHVRCap)  __attribute__ ((weak));
#else
int CaptureGetCurHVRCapV2(CAPTURE_HVRCAPV2 *pHVRCap);
#endif



//! 获得当前HVR的应用模
/// CaptureSetHVRCap封装接口，便于统一5000系列NVR的结构体不一样
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAP的指针。
/// \retval 0  获取成功。
/// \retval -1  获取失败。
int CaptureGetCurHVRCapEx(CAPTURE_HVRCAPV2 *pHVRCap);


///不能直接调用，调用封装接口CaptureGetTotalHVRCapEx
////
/// 
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAP的指针。
/// \retval 0  获取成功。
/// \retval -1  获取失败。

int CaptureGetTotalHVRCap(CAPTURE_TOTAL_HVRCAP *pHVRCap);//改用CaptureGetTotalHVRCapV2，为了兼容老的库保留

///不能直接调用，调用封装接口CaptureGetTotalHVRCapEx
////
/// 
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAPV2的指针。
/// \retval 0  获取成功。
/// \retval -1  获取失败。
#ifdef LINUX
int CaptureGetTotalHVRCapV2(CAPTURE_TOTAL_HVRCAPV2 *pHVRCap)  __attribute__ ((weak));
#else
int CaptureGetTotalHVRCapV2(CAPTURE_TOTAL_HVRCAPV2 *pHVRCap);
#endif


//! 获得HVR支持的应用模式
///
/// CaptureSetHVRCap封装接口，便于统一5000系列NVR的结构体不一?
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAP的指针。
/// \retval 0  获取成功。
/// \retval -1  获取失败?
int CaptureGetTotalHVRCapEx(CAPTURE_TOTAL_HVRCAPV2 *pHVRCap);


//! 获得模拟通道路数
///本函数必须在CaptureGetCurHVRCapEx 调用后用
/// 
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAP的指针。
/// \retval 获取通道数
int CaptureGetOneChnEx(HVR_CHNCAPV2 *pHVRCap);


//! 获得模拟通道路数
///本函数必须在CaptureGetCurHVRCapEx 调用后用
/// 
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAP的指针。
/// \retval 获取通道数
int CaptureGetAnalogCapChnEx(CAPTURE_HVRCAPV2 *pHVRCap);

//! 获得数字通道路数
///
///本函数必须在CaptureGetCurHVRCapEx 调用后用
//
/// \param [out] pHVRCap 指向HVR特性结构CAPTURE_HVRCAP的指针。
/// \retval 获取通道数
int CaptureGetDigitalChnEx(CAPTURE_HVRCAPV2 *pHVRCap);


// HVR的接口做了一些调整，3个接口，一个获取支持的所有工作模式，一个设置工作模式，一个获取当前工作模式
#ifdef __cplusplus
}
#endif

#endif

