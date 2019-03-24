#ifndef __EX_DECODE_20110812_H
#define __EX_DECODE_20110812_H
#ifdef __cplusplus
extern "C"
{
#endif
#define MAX_HVR_CHNCAP			32

//����������Ҫ���εķֱ��ʣ�ʹ��ʱ�ö�Ӧ����
//Ŀǰֻ��PageDigitalChannelInfo��Opconfig�����
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

typedef struct HVR_CHNCAP //����HVR_CHNCAPV2��Ϊ�˼����ϵı���
{
	int nD1Chn;		// ֧�ֵ�D1·��
	int n960HChn;	// ֧�ֵ�960H·��
	int n720PChn;	// ֧�ֵ�720P·��
	int n1080PChn;	// ֧�ֵ�1080P·��
	int nCIFChn;	//֧�ֵ�CIFͨ����
	int nHD1Chn;	//֧�ֵ�HD1ͨ����
	unsigned char nPlayChn; //֧�ֻط�·��
	unsigned char nDigiTalChn; //֧���������ͨ��·��
	unsigned char n960PChn; //֧�ֵ�960Pͨ����
	unsigned char n3MChn; //֧�ֵ�3Mͨ����
	unsigned char n5MChn; //֧�ֵ�5Mͨ����
	unsigned char nWUXGAChn; //֧�ֵ�WUXGAͨ����
	unsigned char n1080NChn;//֧��1080Nͨ����
	unsigned char n4MChn;//֧��4Mͨ����
	#ifdef _USE_4K_MODE //modify by luo
	unsigned char n4KChn;	//֧��4Kͨ����
	#endif
}HVR_CHNCAP, *PHVR_CHNCAP;

typedef struct HVR_CHNCAPV2
{
	unsigned char nD1Chn;		// ֧�ֵ�D1·��
	unsigned char n960HChn;	// ֧�ֵ�960H·��
	unsigned char n720PChn;	// ֧�ֵ�720P·��
	unsigned char n1080PChn;	// ֧�ֵ�1080P·��
	unsigned char nCIFChn;	//֧�ֵ�CIFͨ����
	unsigned char nHD1Chn;	//֧�ֵ�HD1ͨ����
	unsigned char nPlayChn; //֧�ֻط�·��
	unsigned char nDigiTalChn; //֧���������ͨ��·��
	unsigned char n960PChn; //֧�ֵ�960Pͨ����
	unsigned char n3MChn; //֧�ֵ�3Mͨ����
	unsigned char n5MChn; //֧�ֵ�5Mͨ����
	unsigned char nWUXGAChn; //֧�ֵ�WUXGAͨ����
	unsigned char n1080NChn;//֧��1080Nͨ����
	unsigned char n4MChn;//֧��4Mͨ����
	unsigned char n720NChn;//֧��720Nͨ����
	unsigned char nWSVGAChn;//֧��WSVGAͨ����
	#ifdef _USE_4K_MODE //modify by luo
	unsigned char n4KChn;	//֧��4Kͨ����
	#endif
	unsigned char nRes[16];
}HVR_CHNCAPV2, *PHVR_CHNCAPV2;

struct DigitalChCap
{
	HVR_CHNCAPV2 DigChnCap[HVR_EX_V2_NR][4];
};

typedef struct CAPTURE_HVRCAP //����CAPTURE_HVRCAPV2��Ϊ�˼����ϵı���
{
	HVR_CHNCAP DigitalCap;		// ֧�ֵ�����ͨ����Ϣ
	HVR_CHNCAP AnalogCap;		// ֧�ֵ�ģ��ͨ����Ϣ
}CAPTURE_HVRCAP, *PCAPTURE_HVRCAP;

typedef struct CAPTURE_HVRCAPV2
{
	HVR_CHNCAPV2 DigitalCap;		// ֧�ֵ�����ͨ����Ϣ
	HVR_CHNCAPV2 AnalogCap;		// ֧�ֵ�ģ��ͨ����Ϣ
}CAPTURE_HVRCAPV2, *PCAPTURE_HVRCAPV2;

typedef struct CAPTURE_TOTAL_HVRCAP //����CAPTURE_TOTAL_HVRCAPV2��Ϊ�˼����ϵı���
{
	int		nHVRCap;			// ʵ��֧�ֵ�ģʽ
	CAPTURE_HVRCAP	HVRCap[MAX_HVR_CHNCAP];		// ����ģʽ�Ļ���
}CAPTURE_TOTAL_HVRCAP, *PCAPTURE_TOTAL_HVRCAP;

typedef struct CAPTURE_TOTAL_HVRCAPV2
{
	int		nHVRCap;			// ʵ��֧�ֵ�ģʽ
	CAPTURE_HVRCAPV2	HVRCap[MAX_HVR_CHNCAP];		// ����ģʽ�Ļ���
}CAPTURE_TOTAL_HVRCAPV2, *PCAPTURE_TOTAL_HVRCAPV2;
 
///����ֱ�ӵ��ã����÷�װ�ӿ�CaptureGetCurHVRCapEx
///  
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
int CaptureSetHVRCap(const CAPTURE_HVRCAP *pHVRCap); //����CaptureSetHVRCapV2��Ϊ�˼����ϵĿⱣ��

///����ֱ�ӵ��ã����÷�װ�ӿ�CaptureGetCurHVRCapEx
///  
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAPV2��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
#ifdef LINUX
int CaptureSetHVRCapV2(const CAPTURE_HVRCAPV2 *pHVRCap)  __attribute__ ((weak));
#else
int CaptureSetHVRCapV2(const CAPTURE_HVRCAPV2 *pHVRCap);
#endif


/// ����HVR��Ӧ��ģʽ
/// CaptureSetHVRCap��װ�ӿڣ�����ͳһ5000ϵ��NVR�Ľṹ�岻һ��
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ��
int CaptureSetHVRCapEx(const CAPTURE_HVRCAPV2 *pHVRCap); 

///����ֱ�ӵ��ã����÷�װ�ӿ�CaptureGetCurHVRCapEx
////
/// 
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
int CaptureGetCurHVRCap(CAPTURE_HVRCAP *pHVRCap);//����CaptureGetCurHVRCapV2��Ϊ�˼����ϵĿⱣ��

///����ֱ�ӵ��ã����÷�װ�ӿ�CaptureGetCurHVRCapEx
////
/// 
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAPV2��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
#ifdef LINUX
int CaptureGetCurHVRCapV2(CAPTURE_HVRCAPV2 *pHVRCap)  __attribute__ ((weak));
#else
int CaptureGetCurHVRCapV2(CAPTURE_HVRCAPV2 *pHVRCap);
#endif



//! ��õ�ǰHVR��Ӧ��ģ
/// CaptureSetHVRCap��װ�ӿڣ�����ͳһ5000ϵ��NVR�Ľṹ�岻һ��
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
int CaptureGetCurHVRCapEx(CAPTURE_HVRCAPV2 *pHVRCap);


///����ֱ�ӵ��ã����÷�װ�ӿ�CaptureGetTotalHVRCapEx
////
/// 
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�

int CaptureGetTotalHVRCap(CAPTURE_TOTAL_HVRCAP *pHVRCap);//����CaptureGetTotalHVRCapV2��Ϊ�˼����ϵĿⱣ��

///����ֱ�ӵ��ã����÷�װ�ӿ�CaptureGetTotalHVRCapEx
////
/// 
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAPV2��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ�ܡ�
#ifdef LINUX
int CaptureGetTotalHVRCapV2(CAPTURE_TOTAL_HVRCAPV2 *pHVRCap)  __attribute__ ((weak));
#else
int CaptureGetTotalHVRCapV2(CAPTURE_TOTAL_HVRCAPV2 *pHVRCap);
#endif


//! ���HVR֧�ֵ�Ӧ��ģʽ
///
/// CaptureSetHVRCap��װ�ӿڣ�����ͳһ5000ϵ��NVR�Ľṹ�岻һ?
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval 0  ��ȡ�ɹ���
/// \retval -1  ��ȡʧ��?
int CaptureGetTotalHVRCapEx(CAPTURE_TOTAL_HVRCAPV2 *pHVRCap);


//! ���ģ��ͨ��·��
///������������CaptureGetCurHVRCapEx ���ú���
/// 
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval ��ȡͨ����
int CaptureGetOneChnEx(HVR_CHNCAPV2 *pHVRCap);


//! ���ģ��ͨ��·��
///������������CaptureGetCurHVRCapEx ���ú���
/// 
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval ��ȡͨ����
int CaptureGetAnalogCapChnEx(CAPTURE_HVRCAPV2 *pHVRCap);

//! �������ͨ��·��
///
///������������CaptureGetCurHVRCapEx ���ú���
//
/// \param [out] pHVRCap ָ��HVR���ԽṹCAPTURE_HVRCAP��ָ�롣
/// \retval ��ȡͨ����
int CaptureGetDigitalChnEx(CAPTURE_HVRCAPV2 *pHVRCap);


// HVR�Ľӿ�����һЩ������3���ӿڣ�һ����ȡ֧�ֵ����й���ģʽ��һ�����ù���ģʽ��һ����ȡ��ǰ����ģʽ
#ifdef __cplusplus
}
#endif

#endif

