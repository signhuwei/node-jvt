
/******************************************************************************
 *	File Name		: hi_srdk_define.h
 *	Description		: Macro/Types definition
 *	Version			: Initial Draft
 *	Author			: LAN CASTLE Technologies Co., LTD
 *	Created			: 	
 *	History			:
 *	  1.Date			: 2010/09/15
 *		Author			: 
 *		Modification	: Created file
 ******************************************************************************/


#ifndef __HI_SRDK_DEFINCE_H__
#define __HI_SRDK_DEFINCE_H__

#include "hi_type.h"

#ifndef NEW_USERMANAGER
#define NEW_USERMANAGER		//add by zk[2010/9/25]
#endif

#ifndef NEW_ALARM
#define NEW_ALARM
#endif

#ifdef NEW_USERMANAGER
#ifndef MAX_USERNAME_LEN
#define MAX_USERNAME_LEN	8
#endif
#ifndef MAX_USERNUM
#define MAX_USERNUM			8		//admin + 7 general user
#endif
#ifndef MAX_USERPSW_LEN
#define MAX_USERPSW_LEN     6
#endif
#endif

/*----------------------------------------------*
* Macro Definition
*----------------------------------------------*/

#define HI_CFG_WATERMARK_CONTENT_LEN 16
#define HI_CFG_WATERMARK_KEY_LEN     8
#define HI_CFG_ENCRYPT_KEY_LEN       8
#define HI_CFG_MAX_CHN               16
#define HI_CFG_MAX_WINDOWS_NUM       64
#define HI_CFG_CHNNAME_LEN           32
#define HI_CFG_OSDCONTENT_LEN        128
#define HI_CFG_MAX_DISPLAYERDEV_NUM  4
#define HI_CFG_MAX_OSD_NUM           4
#define HI_CFG_ALARM_MAX_CHN 16
#define HI_CFG_MD_REGION 32
#define HI_CFG_NET_MAX_DEV (4)
#define HI_CFG_MAX_DDNS   (4)
#define HI_CFG_DNS_MAX     (2)

/* Maximum length of host name */
#define HI_CFG_HOSTNAME_MAXLEN (128)


/* Maximum length of network device name */
#define HI_CFG_NETDEVNAME_MAXLEN (64)

/* Maximum length of IP address */
#define HI_CFG_IPADDR_STR_MAXLEN (128)

/* Maximum length of channel ID */
#define HI_CFG_CHN_ID_STR_MAXLEN (64)

/* Maximum length of domain name */
#define HI_CFG_DOMAIN_NAME_MAXLEN (128)

/* Maximum number of E-mail address */
#define HI_CFG_EMAIL_ADDR_MAXNUM (4)

/* Maximum length of E-mail title */
#define HI_CFG_EMAIL_TITLE_MAXLEN (128)

/* Maximum length of E-mail content */
#define HI_CFG_EMAIL_CONTENT_MAXLEN (400)

/* Max. length of reserve word, in bytes */
#define HI_CFG_RESERVE_MAXLEN (32)

/* Maximum length of network device name */
#define HI_CFG_NETWORK_NAME_MAXLEN (64)

/* Maximum length of mac address */
#define HI_CFG_MAC_MAXLEN (8)

/* Maximum length of IPV6 address */
#define HI_IPV6_MAXLEN (16)

/* Maximum length of IPV4 address */
#define HI_CFG_IPV4_MAXLEN (4)

/* Maximum length of user name */
#define HI_CFG_USRMNG_USRNAME_MAXLEN (32)


/* Maximum length of password */
#define HI_CFG_USRMNG_PASSWD_MAXLEN (64)

/* Maximum count of user group */
#define HI_CFG_USRMNG_GROUP_MAXCNT (128)

/* Max. count of user authority */
#define HI_CFG_USRMNG_AUTHORITY_MAXCNT (128)
#define HI_CFG_USRMNG_AUTHORITY_DESCRIPTION_MAXLEN (128)

#define HI_CFG_MAX_USER_CNT			8
#define HI_CFG_MAX_GROUP_CNT		4

#define HI_CFG_MAX_USBDISK_NUM		4			/* Maximum number of usb disk */
#define HI_CFG_MAX_HDD_NUM			8			/* Maximum number of HDD */
#define HI_CFG_NAME_BUFFER_LEN		64			/* Length of device name */
#define HI_CFG_SN_BUFFER_LEN		32			/* SN Length */
#define HI_CFG_VERSION_BUFFER_LEN	24			/* Length of SDK version number */
#define HI_CFG_LABEL_BUFFER_LEN		32			/* Length of label

/*------------ Macro Definition End -----------*/



/*----------------------------------------------*
* Types Definition
*----------------------------------------------*/

typedef enum hiCFG_STREAM_TYPE_E
{
    HI_CFG_STREAM_TYPE_MAIN,    /**< Main stream */
    HI_CFG_STREAM_TYPE_NETSUB,  /**< Net sub stream */
    HI_CFG_STREAM_TYPE_MOBILE,  /**< Mobile phone stream*/
    HI_CFG_STREAM_TYPE_MOBILE1, /**< Mobile phone stream */
    HI_CFG_STREAM_TYPE_BUTT     /**< Invalid value */
} HI_CFG_STREAM_TYPE_E;

typedef enum hiCFG_RES_E
{
    HI_CFG_RES_CUSTOM,         /**< User defined resolution */
    HI_CFG_RES_CIF,            /**< CIF resolution */
    HI_CFG_RES_HD1,            /**< HD1 resolution  */
    HI_CFG_RES_D1,             /**< D1 resolution */
    HI_CFG_RES_800_600,        /**< 800 x 600 resolution */
    HI_CFG_RES_1024_768,       /**< 1024 x 768 resolution */
    HI_CFG_RES_1280_1024,      /**< 1280 x 1024 resolution */
    HI_CFG_RES_1440_900,       /**< 1440 x 900 resolution */
    HI_CFG_RES_1920_1080,      /**< 1920 x 1080 resolution */
    HI_CFG_RES_BUTT            /**< Invalid value */
} HI_CFG_RES_E;

typedef enum hiCFG_VIDEO_ENC_E
{
    HI_CFG_VIDEO_ENC_H264,       /**< H264 encoding */
    HI_CFG_VIDEO_ENC_AVS,        /**< AVS encoding */
    HI_CFG_VIDEO_ENC_MJPEG,      /**< MJPEG encoding */    
    HI_CFG_VIDEO_ENC_MPEG4,      /**< MPEG4 encoding */
    HI_CFG_VIDEO_ENC_SVAC,       /**< SVAC encoding */
    HI_CFG_VIDEO_ENC_BUTT        /**< Invalid value */
} HI_CFG_VIDEO_ENC_E;

typedef enum hiCFG_VIDEO_RATECRTL_MODE_E
{
    HI_CFG_VIDEO_RATECRTL_MODE_VBR,  /**< VBR */
    HI_CFG_VIDEO_RATECRTL_MODE_CBR,  /**< CBR */
    HI_CFG_VIDEO_RATECRTL_MODE_BUTT  /**< Invalid value */    
} HI_CFG_VIDEO_RATECRTL_MODE_E;

typedef enum hiCFG_AUDIO_ENC_E
{
    HI_CFG_AUDIO_ENC_AMR,        /**< AMR encoding */        
    HI_CFG_AUDIO_ENC_ADPCM,      /**< ADPCM encoding */
    HI_CFG_AUDIO_ENC_G711A,      /**< G.711A encoding */
    HI_CFG_AUDIO_ENC_G711U,      /**< G.711U encoding */
    HI_CFG_AUDIO_ENC_G726,       /**< G.726 encoding */    
    HI_CFG_AUDIO_ENC_BUTT        /**< Invalid value */
} HI_CFG_AUDIO_ENC_E;

typedef enum hiCFG_AUDIO_SAMPLE_RATE_E
{
    HI_CFG_AUDIO_SAMPLE_RATE_8,       /**< 8K sample rate */        
    HI_CFG_AUDIO_SAMPLE_RATE_1102,    /**< 11.025K sample rate */
    HI_CFG_AUDIO_SAMPLE_RATE_16,      /**< 16K sample rate */        
    HI_CFG_AUDIO_SAMPLE_RATE_22050,   /**< 22.050K sample rate */            
    HI_CFG_AUDIO_SAMPLE_RATE_24,      /**< 24K sample rate */        
    HI_CFG_AUDIO_SAMPLE_RATE_32,      /**< 32K sample rate */            
    HI_CFG_AUDIO_SAMPLE_RATE_441,     /**< 44.1K sample rate */                
    HI_CFG_AUDIO_SAMPLE_RATE_48,      /**< 48K sample rate */                        
    HI_CFG_AUDIO_SAMPLE_RATE_BUTT     /**< Invalid value */
} HI_CFG_AUDIO_SAMPLE_RATE_E;

typedef enum hiCFG_AUDIO_SAMPLE_BITWIDTH_E
{
    HI_CFG_AUDIO_SAMPLE_BITWIDTH_8,    /**< 8 bit width */        
    HI_CFG_AUDIO_SAMPLE_BITWIDTH_16,   /**< 16 bit width */    
    HI_CFG_AUDIO_SAMPLE_BITWIDTH_BUTT  /**< Invalid value */
} HI_CFG_AUDIO_SAMPLE_BITWIDTH_E;

typedef enum hiCFG_OSD_TYPE_E
{
    HI_CFG_OSD_TYPE_TEXT = 0,		/**< OSD type:TEXT */
    HI_CFG_OSD_TYPE_TIME = 1,		/**< OSD type:Time */
    HI_CFG_OSD_TYPE_IMAGE = 2,		/**< OSD type:Image */
    HI_CFG_OSD_TYPE_IMAGE_MEM = 3,	/**< OSD type:ImageMem */
    HI_CFG_OSD_TYPE_BUTT			/**< Invalid value */
}HI_CFG_OSD_TYPE_E;

typedef enum hiCFG_COVER_TYPE_E
{
    HI_CFG_COVER_TYPE_SINGLE_COLOR, /**< Single color cover */
    HI_CFG_COVER_TYPE_MASAK,        /**< Mosaic cover */
    HI_CFG_COVER_TYPE_BUTT          /**< Invalid value*/
}HI_CFG_COVER_TYPE_E;

typedef enum hiCFG_DISPLAYER_DEV_E
{
    HI_CFG_DISPLAYER_DEV_VOUT,   /**< Vout output */        
    HI_CFG_DISPLAYER_DEV_VSPOT,  /**< VSpot output */
    HI_CFG_DISPLAYER_DEV_VGA,    /**< VGA output */        
    HI_CFG_DISPLAYER_DEV_HDMI,   /**< HDMI output */
    HI_CFG_DISPLAYER_DEV_BUTT    /**< Invalid value */
}HI_CFG_DISPLAYER_DEV_E;

typedef enum hiCFG_OUTPUT_MODE_E
{
    HI_CFG_OUTPUT_MODE_ONE,    /**< one window*/        
    HI_CFG_OUTPUT_MODE_FOUR,   /**< quad window*/
    HI_CFG_OUTPUT_MODE_NINE,   /**< nine window*/        
    HI_CFG_OUTPUT_MODE_SIXTEEN,/**< sixteen window*/
    HI_CFG_OUTPUT_MODE_BUTT    /**< Invalid value */
}HI_CFG_OUTPUT_MODE_E;


typedef enum hiCFG_INTERFACE_E
{
    HI_CFG_INTERFACE_VGA,       /**< VGA out */
    HI_CFG_INTERFACE_BT1120,	/**< BT1120 out */
    HI_CFG_INTERFACE_BT656,		/**< BT656 out */
    HI_CFG_INTERFACE_BUTT		/**< Invalid value */
}HI_CFG_INTERFACE_E;

typedef enum hiCFG_RECORD_PACKEDTIME_E
{
    HI_CFG_RECORD_PACKEDTIME_15,        /**< 15 minute */
    HI_CFG_RECORD_PACKEDTIME_30,        /**< 30 minute */
    HI_CFG_RECORD_PACKEDTIME_45,        /**< 45 minute */
    HI_CFG_RECORD_PACKEDTIME_60,        /**< 60 minute */
    HI_CFG_RECORD_PACKEDTIME_BUTT       /**< Invalid value */
}HI_CFG_RECORD_PACKEDTIME_E;

typedef enum hiCFG_ALARM_TYPE_E
{
    HI_CFG_ALARM_TYPE_MD,       /**< MD alarm */
    HI_CFG_ALARM_TYPE_COVER,    /**< cover alarm */
    HI_CFG_ALARM_TYPE_IO,		/**< IO alarm */                      
    HI_CFG_ALARM_TYPE_BUTT		/**< Invalid value */
} HI_CFG_ALARM_TYPE_E;

typedef enum hiCFG_ALARM_BUZZER_TIME_E
{
    HI_CFG_ALARM_BUZZER_TIME_0,     /**< OFF */
    HI_CFG_ALARM_BUZZER_TIME_10,    /**< duration 10s */
    HI_CFG_ALARM_BUZZER_TIME_20,    /**< duration 20s */
    HI_CFG_ALARM_BUZZER_TIME_40,    /**< duration 40s */
    HI_CFG_ALARM_BUZZER_TIME_60,    /**< duration 60s */
    HI_CFG_ALARM_BUZZER_TIME_BUTT   /**< Invalid value */
} HI_CFG_ALARM_BUZZER_TIME_E;

typedef enum hiCFG_ALARM_OUT_TIME_E
{
    HI_CFG_ALARM_OUT_TIME_0,     /**< Alarm out OFF */
    HI_CFG_ALARM_OUT_TIME_10,    /**< output 10s */
    HI_CFG_ALARM_OUT_TIME_20,    /**< output 20s */
    HI_CFG_ALARM_OUT_TIME_40,    /**< output 40s */
    HI_CFG_ALARM_OUT_TIME_60,    /**< output 60s */
    HI_CFG_ALARM_OUT_TIME_BUTT   /**< Invalid value */
} HI_CFG_ALARM_OUT_TIME_E;

typedef enum hiDDNS_SVR_ID
{
	HI_DDNS_SVR_ID_3322,        /**< 3322 */
	HI_DDNS_SVR_ID_Dyndns,      /**< dyndns */
	HI_DDNS_SVR_ID_Perfecteyes, /**< perfecteyes */
	HI_DDNS_SVR_ID_BUTT
}HI_DDNS_SVR_ID;

typedef enum hiCFG_ALARM_RECORDDELAY_TIME_E
{
    HI_CFG_ALARM_RECORDDELAY_TIME_30,  /**< record delay 30s */
    HI_CFG_ALARM_RECORDDELAY_TIME_60,  /**< record delay 1m */
    HI_CFG_ALARM_RECORDDELAY_TIME_120, /**< record delay 2m */
    HI_CFG_ALARM_RECORDDELAY_TIME_300, /**< record delay 5m */
    HI_CFG_ALARM_RECORDDELAY_TIME_BUTT /**< invalid */
} HI_CFG_ALARM_RECORDDELAY_TIME_E;

typedef enum hiCFG_MD_SENSITIVITY_E
{
    HI_CFG_MD_SENSITIVITY_5,	/**< highest sensitivity */
    HI_CFG_MD_SENSITIVITY_10,	/**< high sensitivity */
    HI_CFG_MD_SENSITIVITY_15,	/**< low sensitivity */
    HI_CFG_MD_SENSITIVITY_20,	/**< lowest sensitivity */
    HI_CFG_MD_SENSITIVITY_BUTT	/**< invalid value */
} HI_CFG_MD_SENSITIVITY_E;
	
typedef enum hiCFG_EMAIL_INTERVAL_E
{
    HI_CFG_EMAIL_INTERVAL_180,  /**< email interval 3m */
    HI_CFG_EMAIL_INTERVAL_300,  /**< email interval 5m */
    HI_CFG_EMAIL_INTERVAL_600,  /**< email interval 10m */
    HI_CFG_EMAIL_INTERVAL_BUTT  /**< invalid value */
} HI_CFG_EMAIL_INTERVAL_E;
	
typedef enum hiCFG_PPPOE_SECURITY_PROTOCOL_E
{
    HI_CFG_PPPOE_SP_PAP,    /**< PAP */
    HI_CFG_PPPOE_SP_CHAP,   /**< CHAP */
    HI_CFG_PPPOE_SP_SPAP,   /**< SPAP */
    HI_CFG_PPPOE_SP_BUTT,
    HI_CFG_PPPOE_SP_END = 0xFFFFFFFF
} HI_CFG_PPPOE_SECURITY_PROTOCOL_E;

typedef enum hiCFG_IPTYPE_E
{
    HI_CFG_IPTYPE_IPV4, /**< IP V4 */
    HI_CFG_IPTYPE_IPV6, /**< IP V6 */
    HI_CFG_IPTYPE_DN,   /**< domain name */
    HI_CFG_IPTYPE_BUTT,
    HI_CFG_IPTYPE_END = 0xFFFFFFFF
} HI_CFG_IPTYPE_E;

typedef enum hiCFG_MOBILE_BANDWIDTH_E
{
    HI_CFG_MOBILE_BANDWIDTH_32K,  /**< bandwidth 32K */
    HI_CFG_MOBILE_BANDWIDTH_64K,  /**< bandwidth 64K */
    HI_CFG_MOBILE_BANDWIDTH_96K,  /**< bandwidth 96K */
    HI_CFG_MOBILE_BANDWIDTH_128K, /**< bandwidth 128K */
    HI_CFG_MOBILE_BANDWIDTH_BUTT  /**< invalid value*/
} HI_CFG_MOBILE_BANDWIDTH_E;

typedef enum hiCFG_LANGUAGE_E
{
    HI_CFG_LANGUAGE_CHINESE,    /**< chinese */
    HI_CFG_LANGUAGE_ENGLISH,    /**< english */
    HI_CFG_LANGUAGE_BUTT		/**< invalid value*/
}HI_CFG_LANGUAGE_E;

typedef enum hiCFG_TV_MODE_E
{
    HI_CFG_TV_MODE_PAL,      /**< PAL */
    HI_CFG_TV_MODE_NTSC,     /**< NTSC */
    HI_CFG_TV_MODE_BUTT      /**< invalid value */	
}HI_CFG_TV_MODE_E;

typedef enum hiCFG_DATE_MODE_E
{
    HI_CFG_DATE_MODE_MMDDYY,		/**< date format:  MM-DD-YY */
    HI_CFG_DATE_MODE_YYMMDD,		/**< date format:  YY-MM-DD */
    HI_CFG_DATE_MODE_BUTT			/**< invalid value */	
}HI_CFG_DATE_MODE_E;

typedef enum hiCFG_TIME_MODE_E
{
    HI_CFG_TIME_MODE_24HOUR,       /**< time mode: 24 hour */
    HI_CFG_TIME_MODE_12HOUR,       /**< time mode: 12 hour */
    HI_CFG_TIME_MODE_BUTT          /**< invalid value */	
}HI_CFG_TIME_MODE_E;

typedef enum hiCFG_TIME_ZONE_E
{
    HI_CFG_TIME_ZONE_GMTD1200,   /**< GMT-12 */
    HI_CFG_TIME_ZONE_GMTD1100,   /**< GMT-11 */
    HI_CFG_TIME_ZONE_GMTD1000,   /**< GMT-10 */
    HI_CFG_TIME_ZONE_GMTD0900,   /**< GMT-09 */
    HI_CFG_TIME_ZONE_GMTD0800,   /**< GMT-08 */
    HI_CFG_TIME_ZONE_GMTD0700,   /**< GMT-07 */
    HI_CFG_TIME_ZONE_GMTD0600,   /**< GMT-06 */
    HI_CFG_TIME_ZONE_GMTD0500,   /**< GMT-05 */
    HI_CFG_TIME_ZONE_GMTD0400,   /**< GMT-04 */
    HI_CFG_TIME_ZONE_GMTD0300,   /**< GMT-03 */
    HI_CFG_TIME_ZONE_GMTD0200,   /**< GMT-02 */
    HI_CFG_TIME_ZONE_GMTD0100,   /**< GMT-01 */
    HI_CFG_TIME_ZONE_GMT,        /**< GMT*/
    HI_CFG_TIME_ZONE_GMTA0100,   /**< GMT+01 */
    HI_CFG_TIME_ZONE_GMTA0200,   /**< GMT+02 */
    HI_CFG_TIME_ZONE_GMTA0300,   /**< GMT+03 */
    HI_CFG_TIME_ZONE_GMTA0400,   /**< GMT+04 */
    HI_CFG_TIME_ZONE_GMTA0430,   /**< GMT+04:30 */
    HI_CFG_TIME_ZONE_GMTA0500,   /**< GMT+05 */
    HI_CFG_TIME_ZONE_GMTA0530,   /**< GMT+05:30 */
    HI_CFG_TIME_ZONE_GMTA0545,   /**< GMT+05:45 */
    HI_CFG_TIME_ZONE_GMTA0600,   /**< GMT+06 */
    HI_CFG_TIME_ZONE_GMTA0700,   /**< GMT+07 */
    HI_CFG_TIME_ZONE_GMTA0800,   /**< GMT+08 */
    HI_CFG_TIME_ZONE_GMTA0900,   /**< GMT+09 */
    HI_CFG_TIME_ZONE_GMTA0930,   /**< GMT+09:30 */
    HI_CFG_TIME_ZONE_GMTA1000,   /**< GMT+10 */
    HI_CFG_TIME_ZONE_GMTA1100,   /**< GMT+11 */
    HI_CFG_TIME_ZONE_GMTA1200,   /**< GMT+12 */
    HI_CFG_TIME_ZONE_GMTA1300,   /**< GMT+13 */
    HI_CFG_TIME_ZONE_BUTT        /**< invalid value*/
} HI_CFG_TIME_ZONE_E;

typedef enum hiCFG_OVERWRITE_E
{
    HI_CFG_OVERWRITE_OFF,		/* close overwrite */
    HI_CFG_OVERWRITE_FULL,		/* full overwrite */
    HI_CFG_OVERWRITE_DAY,		/* overwrite by day */
    HI_CFG_OVERWRITE_HOUR,		/* overwrite by hour */
    HI_CFG_OVERWRITE_BUTT		/* invalid value */
} HI_CFG_OVERWRITE_E;

typedef enum hiCFG_PTZ_BAUDRATE_E
{
    HI_CFG_PTZ_BAUDRATE_1200,        /**< 1200 bps */
    HI_CFG_PTZ_BAUDRATE_2400,        /**< 2400 bps */        
    HI_CFG_PTZ_BAUDRATE_4800,        /**< 4800 bps */            
    HI_CFG_PTZ_BAUDRATE_9600,        /**< 9600 bps */            
    HI_CFG_PTZ_BAUDRATE_115200,		 /**< 115200 bps */            
    HI_CFG_PTZ_BAUDRATE_BUTT         /**< invalid value */
}HI_CFG_PTZ_BAUDRATE_E;

typedef enum hiCFG_PTZ_PROTOTOL_E
{
    HI_CFG_PTZ_PROTOCAL_PELCOD,          /**< Pelco-D */
    HI_CFG_PTZ_PROTOCAL_PELCOP,          /**< Pelco-P */
    HI_CFG_PTZ_PROTOCAL_BUTT             /**< invalid value */
}HI_CFG_PTZ_PROTOCOL_E;

typedef struct hiCFG_ENCRYPT_S
{
    HI_S32 s32ChnID;                         /**< channel ID */
    HI_U32 u32EncryptEnable;                 /**< encryption switch: 0 disable, 1 enable */
    HI_S8  as8Key[HI_CFG_ENCRYPT_KEY_LEN];   /**< encryption key */
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];/**< reserved */
} HI_CFG_ENCRYPT_S;

typedef struct hiCFG_VIDEO_ATTR_S
{
    HI_S32 s32ChnID;            /**< channel ID */
    HI_S32 s32VideoEnable;      /**< video stream switch: 0 disable, 1 enable */
    HI_U32 u32EncodeType;       /**< encode type:see HI_CFG_VIDEO_ENC_E */
    HI_U32 u32FrameRate;        /**< frame rate:1~100 */
    HI_U32 u32RateCtrlMode;     /**< rate control mode: see HI_CFG_VIDEO_RATECRTL_MODE_E */
    HI_U32 u32VideoBitRate;     /**< bit rate:unit kbps */
    HI_U32 u32Resolution;       /**< resolution:see HI_CFG_RES_E */
    HI_S32 s32VideoHeight;      /**< user defined video height: 24~576 */
    HI_S32 s32VideoWidth;       /**< user defined video width: 32~720 */
    HI_S32 s32Gop;              /**< I frame interval */
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< reserved */
} HI_CFG_VIDEO_ATTR_S;

typedef struct hiCFG_AUDIO_ATTR_S
{
    HI_S32 s32ChnID;            /**< channel ID */
    HI_S32 s32AudioEnable;      /**< audio stream switch: 0 disable, 1 enable */
    HI_U32 u32Protocol;         /**< audio encode protocol:see HI_CFG_AUDIO_ENC_E */
    HI_U32 u32SampleRate;       /**< sample rate: see HI_CFG_AUDIO_SAMPLE_RATE_E */
    HI_U32 u32SampleBitWidth;   /**< sample bit width: see HI_CFG_AUDIO_SAMPLE_BITWIDTH_E */
	HI_U8  au8Align[4];         /**< 8 byte align */
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< reserved */
} HI_CFG_AUDIO_ATTR_S;

typedef struct hiCFG_WATERMARK_S
{
    HI_S32 s32ChnID;                                   /**< channel ID*/
    HI_S32 s32WmEnable;                                /**< watermark switch: 0 disable, 1 enable*/
    HI_S8  as8WaterMark[HI_CFG_WATERMARK_CONTENT_LEN]; /**< content */
    HI_S8  as8Key[HI_CFG_WATERMARK_KEY_LEN];           /**< key */
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];          /**< reserved */
} HI_CFG_WATERMARK_S;

typedef struct hiCFG_AV_BIND_S
{
    HI_S32 s32ChnID;            /**< channel ID*/
    HI_S32 s32BindAiChn;        /**< bind audio channel ID,-1 unbind*/
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];  /**< reserved */
} HI_CFG_AV_BIND_S;

typedef struct hiCFG_OSD_S
{
    HI_S32 s32OsdEnable;         /**< OSD enable*/
    HI_U32 u32OsdContentType;    /**< OSD content type: see HI_CFG_OSD_TYPE_E */
    HI_U32 u32Layer;             /**< layer,0 ~100*/
    HI_U32 u32AreaAlpha;         /**< OSD Alpha value*/
    HI_U32 u32FgColor;           /**< OSD foreground,pixel format RGB8888 */
    HI_U32 u32BgColor;           /**< OSD background, pixel format RGB8888 */
    HI_S32 s32X;       /**< top left corner,X coordinate scale:0~255*/
    HI_S32 s32Y;       /**< top left corner,Y coordinate scale:0~255*/
    HI_S32 s32W;       /**< width*/
    HI_S32 s32H;       /**< height*/
    HI_CHAR aszOsdCotent[HI_CFG_OSDCONTENT_LEN];/**< if the content type is TEXT, support input string;
											     if the content type is IMAGE, support path, for example: "/bin/osd.bmp";
											     if the content type is IMAGEMEM, the front 4 byte are memory address*/
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];   /**< reserved*/
}HI_CFG_OSD_S;

typedef struct hiCFG_COVER_S
{
    HI_S32 s32CoverEnable; /**< cover switch:0 disable,1 enable*/
    HI_U32 u32CoverType;   /**< cover type:see HI_CFG_COVER_TYPE_E*/
    HI_U32 u32Layer;       /**< layer,0 ~100*/
    HI_S32 s32X;           /**< top left corner,X coordinate scale:0~255*/
    HI_S32 s32Y;           /**< top left corner,Y coordinate scale:0~255*/
    HI_S32 s32W;           /**< width*/
    HI_S32 s32H;           /**< height*/
    HI_U32 u32Color;       /**< cover area color, pixel format RGB8888 */
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< reserved*/
}HI_CFG_COVER_S;

typedef struct hiCFG_OSD_CHN_S
{
    HI_S32         s32ChnID;                             /**< channel ID*/
    HI_U8  au8Align[4];                                  /**< 8字节对齐 */
    HI_CFG_OSD_S   stViChnTime;                          /**< video input channel time*/
    HI_CFG_OSD_S   stViChnName;                          /**< video input channel name*/
    HI_CFG_COVER_S astCoverAttr[HI_CFG_MAX_OSD_NUM];     /**< video cover, Max.4*/
    HI_CFG_OSD_S   astViOverlayAttr[HI_CFG_MAX_OSD_NUM]; /**< video input OSD , Max.4, the first OSD is time info*/
    HI_CFG_OSD_S   stVoChnName;                          /**< video output channel name*/
    HI_CFG_OSD_S   stVoChnNum;                           /**< video output channel number*/
    HI_CFG_OSD_S   stVoStatusBar;                        /**< video output status bar*/
    HI_CFG_OSD_S   astVoOsdAttr[HI_CFG_MAX_DISPLAYERDEV_NUM][HI_CFG_MAX_OSD_NUM]; /**< video out OSD*/
    HI_CFG_OSD_S   au8Reserve[2];                          /**< reserved*/
}HI_CFG_OSD_CHN_S;


typedef struct hiCFG_TIME
{
	HI_U8 year;
	HI_U8 month;
	HI_U8 day;
	HI_U8 hour;
	HI_U8 minute;
	HI_U8 second;
	HI_U8 week;
	HI_U8 au8Align;
		
}HI_CFG_TIME;

typedef struct hiCFG_DISPLAYERDEV_ATTR_S
{
    HI_U32 u32DevID;                  /**< display device ID:see HI_CFG_DISPLAYER_DEV_E*/
    HI_U32 u32PollingTime;            /**< polling time interval,unit second, 0 not polling*/
    HI_U32 as32Margin[4];             /**< 0:left margin, 1:right margin, 2:top margin, 3:bottom margin*/
    HI_U32 u32Resolution;             /**< display resolution:see HI_CFG_RES_E*/
    HI_U32 u32RefreshRate;            /**< display refresh rate*/
    HI_U32 u32StaticOrDynamic;        /**< 0-static, 1-dynamic*/
    HI_U32 u32OutputMode;             /**< output mode:see HI_CFG_OUTPUT_MODE_E*/
    HI_U8 au8Windows[HI_CFG_MAX_WINDOWS_NUM];       /**< preview channel*/
    HI_CFG_OSD_S stDevTimeAttr;                     /**< device time OSD*/
    HI_CFG_OSD_S astDevOsdAttr[HI_CFG_MAX_OSD_NUM]; /**< device OSD*/
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN];        /**< reserved*/
}HI_CFG_DISPLAYERDEV_ATTR_S;  

typedef struct hiCFG_CHNDISPLAYER_ATTR_S
{
    HI_S32 s32ChnID;	     /**< channel ID*/
    HI_U32 u32PreviewEnable; /**< preview switch: 0-disable, 1-enable*/
    HI_U32 au32Color[8];     /**< color setup: 0-hue, 1-brightness, 2- contrast, 3-saturation, 4-sharpness(0~64) */
    HI_S8 as8ChnName[HI_CFG_CHNNAME_LEN];		/**< channel name*/
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN];    /**< reserved*/
}HI_CFG_CHNDISPLAYER_ATTR_S;

typedef struct hiCFG_GUI_ATTR_S
{
    HI_U32 u32InterfaceType; /**< interface type:see HI_CFG_INTERFACE_E*/
    HI_U32 u32IsVoutOrSpot;  /**< display device: see HI_CFG_DISPLAYER_DEV_E*/
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< reserved*/
}HI_CFG_GUI_ATTR_S;

typedef struct hiCFG_AO_ARRT_S
{
    HI_S32 s32ChnID;       /**< channel ID*/
    HI_U32 u32Volume;      /**< volume: 0~63*/
    HI_U32 u32Mute;        /**< mute switch:0-close, 1-open*/
	HI_U8  au8Align[4];    /**< 8 byte align */
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< reserved*/
}HI_CFG_AO_ARRT_S;


typedef struct hiCFG_COLOR_ARRT_S
{
	HI_U32 Color;                         //色  度
	HI_U32 Bright;                       //亮  度
	HI_U32 Contrast;                   //对比度
	HI_U32 Saturation;                //饱和度
	HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< 保留字节*/
}HI_CFG_COLOR_ARRT_S;

typedef struct hiCFG_RECORDCHNATTR_S
{
    HI_S32  s32ChnID;           /**< channel ID*/
    HI_U32  u32RecordEnabe;     /**< record switch: 0 not record, 1 record*/
    HI_U32  u32RecordMode;      /**< record mode:0-schedule, 1-always, 2-manual*/
    HI_U32  u32PackedTime;      /**< packed time: see HI_CFG_RECORD_PACKEDTIME_E*/
    HI_U32  u32AudioEnable;     /**< audio record switch: 1-enable, 0-disable*/
	HI_U8   au8Align[4];         /**< 8 byte align */
    HI_U8   au8Reserve[HI_CFG_RESERVE_MAXLEN];     /**< reserved */
} HI_CFG_RECORDCHNATTR_S;

typedef struct hiCFG_RECORDCHNSCHEDULE_S
{
    HI_S32  s32ChnID;           /**< channel ID*/
    HI_U32  u32ScheduleEnable;  /**< schedule enable: 0 disable ; 1 enable */
    HI_U8   au8hour[7][24];     /**< schedule time*/
    HI_U8   au8Reserve[HI_CFG_RESERVE_MAXLEN];     /**< reserved*/
} HI_CFG_RECORDCHNSCHEDULE_S;

typedef struct hiCFG_PLAYBACK_ATTR_S
{
    HI_S32 s32ChnID;            /**< channel ID*/
    HI_U32 u32Enable;   		/**< if enable, 0 disable 1 enable*/
    HI_U32 u32Volume;           /**< volume: 0~63 */
    HI_U32 u32Mute;             /**< mute switch: 0-close, 1-open*/
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];      /**< reserved*/
} HI_CFG_PLAYBACK_ATTR_S;

typedef struct hiCFG_ALARM_IN_ATTR_S
{
    HI_U8 au8IOAlarm[HI_CFG_ALARM_MAX_CHN];         /**< I/O alarm: 0-NO, 1-NC, 2-OFF*/
    HI_U8 au8VideoLossAlarm[HI_CFG_ALARM_MAX_CHN];  /**< video loss switch: 0-close, 1-open*/
    HI_U8 au8VideoCoverAlarm[HI_CFG_ALARM_MAX_CHN]; /**< cover alarm:0-close,1-open*/
    HI_U8 u8HddInvalidAlarm;                    /**< invalid HDD alarm: 0-close, 1-open*/
    HI_U8 u8HddNoSpaceAlarm;                    /**< no space alarm: 0-close, 1-open*/
    HI_U8 u8DoorRec;
	HI_U8 au8Align[5];                          /**< 8 byte align */
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN];                       /**< reserved*/
} HI_CFG_ALARM_IN_ATTR_S;

typedef struct hiCFG_ALARM_OUT_ATTR_S
{
    HI_U32 u32BuzzerEnable;         /**< buzzer switch: 0-close; 1-open*/
    HI_U32 u32BuzzerMooTime;        /**< duration time: see HI_CFG_ALARM_BUZZER_TIME_E*/
    HI_U32 u32AlarmOutTime;         /**< alarm out time: see HI_CFG_ALARM_OUT_TIME_E*/    
    HI_U32 u32RecordDelayTime;      /**< record delay time: see HI_CFG_ALARM_RECORDDELAY_TIME_E*/
    HI_U32 u32PreRecordTime;        /**< prerecord time: 0-close,1-10s*/
    HI_U32 u32InvalidAlarmIOOut;	/**< IO out switch for invalid HDD: 0-close, 1-open*/
    HI_U32 u32NoSpaceAlarmIOOut;	/**< IO out switch for no space: 0-close, 1-open*/
	HI_U8  au8Align[4];             /**< 8 byte align */
	HI_U8 au8VideoLossAlarmIOOut[HI_CFG_ALARM_MAX_CHN];		/**< IO out switch for video loss: 0-close, 1-open*/
    HI_U8 au8IOAlarmOutFlag[HI_CFG_ALARM_MAX_CHN];			/**< IO out switch for IO alarm: 0-close, 1-open*/
    HI_U8 au8IOAlarmRecordFlag[HI_CFG_ALARM_MAX_CHN];		/**< record switch for IO alarm: 0-close, 1-open*/
    HI_U8 au8IOAlarmBuzzerFlag[HI_CFG_ALARM_MAX_CHN];		/**< buzzser switch for IO alarm: 0-close, 1-open*/
    HI_U8 au8IOAlarmprerecordFlag[HI_CFG_ALARM_MAX_CHN];	/**< prerecord switch for IO alarm: 0-close, 1-open*/
    HI_U8 au8IOemailFlag[HI_CFG_ALARM_MAX_CHN];		/**< E-mail switch for IO alarm: 0-close, 1-open*/
	HI_U8 au8IOPhoneSMSFlag[HI_CFG_ALARM_MAX_CHN];      //有IO时是否需要发送短信0-关闭，1-开启
	HI_U8 au8IONetSMSFlag[HI_CFG_ALARM_MAX_CHN];      //有MD时是否需要发送短信0-关闭，1-开启
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];		/**< reserved*/
} HI_CFG_ALARM_OUT_ATTR_S;


typedef struct hiCFG_ALARM_SCHEDULE_S
{
    HI_U32 u32AlarmScheduleEnable;   /**< alarm schedule enable: 0 -close, 1 -open*/
    HI_U8  au8Align[4];              /**< 8 byte align */
	HI_U32 au32Hour[7][2];           /**< alarm time*/
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];           /**< reserved */
} HI_CFG_ALARM_SCHEDULE_S;



typedef struct hiCFG_MD_OLDATTR_S
{
    HI_S32 s32ChnID;             /**< channel ID*/
    HI_U32 u32MDEnable;          /**< motion detect switch: 0-close, 1-open*/    
    HI_U32 u32Sensitivity;       /**< sensitivity: see HI_CFG_MD_SENSITIVITY_E*/
    HI_U32 u32TriggerPercent;    /**< trigger percent: : 0~100 */
    HI_U8  au8RegionSetting[HI_CFG_MD_REGION];	/**< region setting,in bit: 0 not detect; 1 detect*/
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];	/**< reserved */
} HI_CFG_MD_OLDATTR_S;

//fengqx 20111021 add
typedef struct hiCFG_MD_IPCAM_ATTR_S
{
    HI_S32 s32ChnID;             /**< 视频通道号*/
    HI_U32 u32MDEnable;          /**< 移动侦测使能:  0-关闭，1-开启*/    
    HI_U32 u32Sensitivity;       /**< 灵敏度: HI_CFG_MD_SENSITIVITY_E*/
    HI_U32 u32TriggerPercent;    /**< 区域侦测触发运动宏块百分比: : 范围(0~100)  */
    HI_U8  au8RegionSetting[HI_CFG_MD_REGION]; /**< 区域设置区域: 每Bit 表示一个区域: 0 不检测; 1 检测*/
    //bluesky 2011-08-26
    HI_U32 u32MDNetSMSFlag;      //有MD时是否需要发送短信0-关闭，1-开启
    HI_U32 u32MDAlarmOutFlag;      //有MD时是否有IO输出0-关闭，1-开启
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN/2];       /**< 保留字节 */
} HI_CFG_MD_IPCAM_ATTR_S;

typedef struct hiCFG_MD_ATTR_S
{
    HI_S32 s32ChnID;             /**< channel ID*/
    HI_U32 u32MDEnable;          /**< motion detect switch: 0-close, 1-open*/    
    HI_U32 u32Sensitivity;       /**< sensitivity: see HI_CFG_MD_SENSITIVITY_E*/
    HI_U32 u32TriggerPercent;    /**< trigger percent: : 0~100 */

	HI_U32 u32MDAlarmOutFlag;		/**< IO out switch for MD: 0-close, 1-open*/
    HI_U32 u32MDRecordFlag;			/**< record switch for MD: 0-close, 1-open*/
    HI_U32 u32MDBuzzerFlag;			/**< buzzer switch for MD: 0-close, 1-open*/
    HI_U32 u32MDPrerecordFlag;      /**< prerecord switch for MD: 0-close, 1-open*/
    HI_U32 u32MDemailFlag;			/**< E-mail switch for MD: 0-close, 1-open*/
	HI_U32 u32MDPhoneSMSFlag;      //有MD时是否需要发送短信0-关闭，1-开启
	HI_U32 u32MDNetSMSFlag;      //有MD时是否需要发送短信0-关闭，1-开启
    HI_U8  au8Align[4];              /**< 8字节对齐 */
    HI_U8  au8RegionSetting[HI_CFG_MD_REGION];	/**< region setting,in bit: 0 not detect; 1 detect*/
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];       /**< reserved */
} HI_CFG_MD_ATTR_S;

typedef struct hiCFG_IP_INFO_S
{
    HI_U32 u32Type;                 /**< IP type,IPV4/IPV6,see HI_CFG_IPTYPE_E*/
    HI_U8 u8Align[4];               /**< 8 byte align*/
    HI_CHAR aszIP[HI_CFG_IPADDR_STR_MAXLEN];  /**< IP address
                                    	for example,IPV4:192.168.1.2
                                        aszIP[0]==192, 
                                        aszIP[1]==168, 
                                        aszIP[2]==1, 
                                        aszIP[3]==2*/
    HI_U8 u8Reserve[64];           /**< reserved */
} HI_CFG_IP_INFO_S;

typedef struct hiCFG_PPPOE_ATTR_S
{
    HI_U32 u32PppoeState;       /**< PPPoE state */
    HI_U32 u32SecurityProtocol; /**< encryption protocol:see HI_CFG_PPPOE_SECURITY_PROTOCOL_E*/
    HI_CHAR aszNetdevName[HI_CFG_NETWORK_NAME_MAXLEN];/**< network device name */
    HI_CHAR aszUserName[HI_CFG_USRMNG_USRNAME_MAXLEN];/**< user name*/
    HI_CHAR aszPassword[HI_CFG_USRMNG_PASSWD_MAXLEN]; /**< password */
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];                  /**< reserved*/
} HI_CFG_PPPOE_ATTR_S;

typedef struct hiCFG_DDNS_ATTR_S
{
    HI_U32 u32DdnsID;       /**< DDNS ID */
    HI_U32 u32DdnsState;    /**< DDNS state */
    HI_CHAR aszNetdevName[HI_CFG_NETWORK_NAME_MAXLEN];  /**< network device name */
    HI_CHAR aszHostName[HI_CFG_HOSTNAME_MAXLEN];        /**< host name */
    //HI_CFG_IP_INFO_S stServerAddr;                    /**< server address*/
	HI_U32 u32SvrID;        /**< HI_DDNS_SVR_ID*/
    HI_U8 u8Align[4];       /**< 8 byte align*/
    HI_CHAR aszUserName[HI_CFG_USRMNG_USRNAME_MAXLEN];  /**< user name */
    HI_CHAR aszPassword[HI_CFG_USRMNG_PASSWD_MAXLEN];   /**< password */
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];             /**< reserved*/
} HI_CFG_DDNS_ATTR_S;


typedef struct hiCFG_IPPREVIEW_VODATTR_S
{
    HI_U32 u32ChnNo;                                /**< IP preview channel No */
    HI_U32 u32IppreviewState;                       /**< IP preview state */
    HI_CFG_IP_INFO_S stServerAddr;                  /**< server address */
    HI_U16 u16ServicePort;                          /**< port */
    HI_U16 u16MediaCtrlProtocolType;                /**< media control protocol */
    HI_U16 u16MediaTransferProtocolType;            /**< media transfer protocol */
    HI_U16 u16CmdCtrlProtocolType;                  /**< command control protocol */
    HI_CHAR aszUserName[HI_CFG_USRMNG_USRNAME_MAXLEN];	 /**< user name  */
    HI_CHAR aszPassword[HI_CFG_USRMNG_PASSWD_MAXLEN];	 /**< password  */
    HI_CHAR aszChnID[HI_CFG_CHN_ID_STR_MAXLEN];          /**< channel ID */
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];              /**< reserved */
} HI_CFG_IPPREVIEW_VODATTR_S;

typedef struct hiCFG_EMAIL_ADDR_S
{
    HI_CHAR  aszName[HI_CFG_USRMNG_USRNAME_MAXLEN];		/**< email user name */
    HI_CHAR  aszAddress[HI_CFG_DOMAIN_NAME_MAXLEN];		/**< email address,for example: xxx888@sina.com */
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];             /**< reserved */
} HI_CFG_EMAIL_ADDR_S;


typedef struct hiCFG_EMAIL_ATTR_S
{
    HI_U32 u32EmailID;              /**< Email ID */
    HI_U32 u32EmailState;           /**< Email state */
    HI_CFG_IP_INFO_S stServerAddr;  /**< server address */
    HI_U16 u16ServicePort;          /**< SMTP port */
    HI_U16 u16EncryptionType;       /**< SSL*/
    HI_U8 u8Align[4];               /**< 8 byte align*/
    HI_CHAR aszUserName[HI_CFG_USRMNG_USRNAME_MAXLEN];  /**< user name */
    HI_CHAR aszPassword[HI_CFG_USRMNG_PASSWD_MAXLEN];   /**< password */
    HI_CHAR aszTitle[HI_CFG_EMAIL_TITLE_MAXLEN];        /**< email title */
    HI_CFG_EMAIL_ADDR_S astToAddrList[HI_CFG_EMAIL_ADDR_MAXNUM]; /**< receiver address */
    HI_CFG_EMAIL_ADDR_S astCcAddrList[HI_CFG_EMAIL_ADDR_MAXNUM]; /**< CC address */
    HI_CFG_EMAIL_ADDR_S astBccAddrList[HI_CFG_EMAIL_ADDR_MAXNUM];/**< BCC address */
    HI_CFG_EMAIL_ADDR_S stSendAddrList;                          /**< sender address */
    HI_CHAR aszContent[HI_CFG_EMAIL_CONTENT_MAXLEN];    /**< email content  */
    HI_U32 u32Accessories;                              /**< if have accessories: see HI_BOOL */
	HI_U32 u32Intervaltime;							    /**< send interval time:see HI_CFG_EMAIL_INTERVAL_E*/
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];             /**< reserved*/
} HI_CFG_EMAIL_ATTR_S;
    
typedef struct hiCFG_MOBILE_COMMON_ATTR_S
{
    HI_U32 u32MobileState;  /**< mobile state*/
    HI_U32 u32MinBandwidth; /**< minimum band width: see HI_CFG_MOBILE_BANDWIDTH_E*/
    HI_U32 u32ChnStatus;    /**< channel status, in bit */
    HI_U8 u8Align[4];       /**< 8 byte align*/
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< reserved*/
} HI_CFG_MOBILE_COMMON_ATTR_S;

typedef struct hiCFG_MOBILE_OWSP_ATTR_S
{
    HI_U16 u16Port;     /**< port*/
    HI_U16 u16MaxUser;  /**< maximum connected user number */
    HI_U32 u32WDevID;   /**< device ID */
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];/**< reserved*/
}HI_CFG_MOBILE_OWSP_ATTR_S; 

typedef struct hiCFG_NETDEV_ATTR_S
{
	HI_CHAR aszNetdevName[HI_CFG_NETDEVNAME_MAXLEN];/*network device name*/

    HI_CHAR aszIP[HI_CFG_IPV4_MAXLEN];      /**< IP address,
                                        	for example,IPV4:192.168.1.2 
                                            aszIP[0]==192, 
                                            aszIP[1]==168, 
                                            aszIP[2]==1, 
                                            aszIP[3]==2 */
    HI_CHAR aszNetmask[HI_CFG_IPV4_MAXLEN]; /**< Netmask,
                                        	for example,IPV4 Netmask:255.255.254.0
                                            aszNetmask[0]==255, 
                                            aszNetmask[1]==255, 
                                            aszNetmask[2]==254, 
                                            aszNetmask[3]==0 */
    HI_CHAR aszMac[HI_CFG_MAC_MAXLEN];      /**< Mac address,
                                        	for example,Mac address:00:EC:01:20:EE:EC
                                            aszMac[0]==0x00, 
                                            aszMac[1]==0xEC, 
                                            aszMac[2]==0x01, 
                                            aszMac[3]==0x20, 
                                            aszMac[4]==0xEE, 
                                            aszMac[5]==0xEC */
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< reserved */
} HI_CFG_NETDEVATTR_S;

//used by ipcam
typedef struct hiCFG_WifiSetting_S
{
	char ssid[16];
	char key[16];
	char sswitch;	//0-close  1-open
	char AuthMode;	//0- WPA-PSK  1- WPA2-PSK
	char EncrypType;  //0- TKIP  1- AES	
	unsigned char openFlag;
	unsigned char IPAddr[4];
	unsigned char NetMask[4];
	unsigned char GateWay[4];
	unsigned char MacAddr[6];
	unsigned char reserve[6];
}HI_CFG_WifiSetting_S;

typedef struct hiCFG_DEFAULT_GWIP_S
{
	HI_CHAR aszNetdevName[HI_CFG_NETDEVNAME_MAXLEN];/*network device name*/
	HI_CHAR aszDefaultGWIP[HI_CFG_IPV4_MAXLEN];     /**< default gateway */
    HI_U8 u8Align[4];                               /**< 8 byte align*/
}HI_CFG_DEFAULT_GWIP_S;

typedef struct hiCFG_DHCP_CLIENT_ATTR_S
{
	HI_CHAR aszNetdevName[HI_CFG_NETDEVNAME_MAXLEN];/*network device name*/
    HI_U32 u32DhcpStatus;   /**< DHCP Client status:0 close;1 open */
    HI_U32 u32AutoAllocDNS; /**< Get DNS server by DHCP client: see HI_BOOL */
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];/**< reserved */
} HI_CFG_DHCP_CLIENT_ATTR_S;
typedef struct hiCFG_3GWIRLE_CLIENT_ATTR_S
{
    HI_U32 u32WirlessStatus;   /**< 3G Client status:0 close;1 open */
	HI_U8  u8Align[4];
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];/**< reserved */
} HI_CFG_3GWIRLE_CLIENT_ATTR_S;

typedef struct lbCFG_DEVID
{
	HI_S32 validlen;	
	HI_U8 DevId[13];  
	HI_U8 u8Align[7];    /**< 8字节对齐位*/
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];/**< 保留字,按讨论结果预留32字节 */
}LB_CFG_DEVID;

typedef struct hiCFG_SYSTEM_ATTR_S
{
    HI_U32 u32Language;           /**< system language: see HI_CFG_LANGUAGE_E */
    HI_U32 u32VideoSystem;        /**< TV mode: see HI_CFG_TV_MODE_E */
    HI_U32 u32DateMode;           /**< date mode: see HI_CFG_DATE_MODE_E */
    HI_U32 u32TimeMode;           /**< time mode: see HI_CFG_TIME_MODE_E */
    HI_S32 s32TimeZone;           /**< time zone: see HI_CFG_TIME_ZONE_E*/
    HI_U32 u32UpgradeAddr;        /**< upgrade address,user can't set */    
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];        /**< reserved */
} HI_CFG_SYSTEM_ATTR_S;

typedef struct hiCFG_DAYLIGHT_S
{
    HI_U8 u8DstEnable;      /**< Daylight Saving Time switch: 0-close, 1-open*/
    HI_U8 u8DstMode;        /**< DST mode: 0-default, 1-custom*/
    HI_U8 u8StartMonth;     /**< DST start month:0---11*/
    HI_U8 u8StartWeek;      /**< DST start week: 0-first week, 1-second week, 2-third week, 3-fourth week, 4-fifth week*/
    HI_U8 u8StartHour;      /**< DST start hour*/
    HI_U8 u8EndMonth;       /**< DST end month: 0---11*/
    HI_U8 u8EndWeek;        /**< DST end week: 0-first week, 1-second week, 2-third week, 3-fourth week, 4-fifth week*/
    HI_U8 u8EndHour;        /**< DST end hour*/
    HI_S8 s8Offset;         /**< DST offset, Not use now*/
    HI_U8 u8Align[7];       /**< 8 byte align*/
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN];   /**< reserved */
} HI_CFG_DAYLIGHT_S;

typedef struct hiCFG_SYSTEM_MAINTAIN_S
{
    HI_U8 au8MaintainTime[4];   /**< maintenance time,hour:minute*/
    HI_U32 u32MaintainEnable;   /**< maintenance switch:0-close, 1-open*/
    HI_U32 u32MaintainPeriod1;  /**< maintenance period 1:0-everyday, 1-weekly, 2-monthly*/
    HI_U32 u32MaintainPeriod2;  /**< maintenance period 2;0--6:which day in week;7--37:which day in month*/
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN];   /**< reserved */
}HI_CFG_SYSTEM_MAINTAIN_S;

typedef struct hiCFG_USERINFO_S
{
    HI_S32 s32UserID;                                    /**< user ID,ID>=0 valid, -1 invalid*/
    HI_U32 u32UserState;                                 /**< user state: 1 -enable, 0 -disable*/
    HI_CHAR aszUserName[HI_CFG_USRMNG_USRNAME_MAXLEN];   /**< user name */
    HI_CHAR aszPasswd[HI_CFG_USRMNG_PASSWD_MAXLEN];      /**< password */
    HI_CHAR aszPasswd2[HI_CFG_USRMNG_PASSWD_MAXLEN];     /**< confirm password*/    
    HI_U32 au32GroupID[HI_CFG_USRMNG_GROUP_MAXCNT];      /**< group ID */
    HI_U8 au8Authority[HI_CFG_USRMNG_AUTHORITY_MAXCNT/8];/**< authority list, by bit;
                                                                    0-off,
                                                                    1-on
																	
                                                         */
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];              /**< reserved */
} HI_CFG_USERINFO_S;

//Preview permission [2011/4/26]
typedef struct lbCFG_USERPREWPRI_S
{
	HI_CHAR UserName[MAX_USERNUM][MAX_USERNAME_LEN + 1];
	bool bUserPrewPri;	
	HI_U8 u8Align[7];
	bool UserPrewPri[MAX_USERNUM][16];	 //16为通道数，每个通道占用一个，
	//MAX_USERNUM为最大用户数，与用//户权限定义的最大用户数相同
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];          
}LB_CFG_USERPREWPRI_S;

typedef struct lbCFG_USERINFO_S	//add [2010/9/7]
{
      HI_CHAR     UserId;								//user ID
      HI_CHAR 	   UserName[MAX_USERNAME_LEN + 1];		//user name
      HI_CHAR 	   UserPsw[MAX_USERPSW_LEN + 1];		//password
	  HI_U8 	u8Align[7];       /**< 8字节对齐位*/ 
      HI_S32   	   UserPri;								//user authority
      HI_S32  	   RemoteUserPri;						//remote authority   
      HI_U8			u8Reserve[HI_CFG_RESERVE_MAXLEN];
}LB_CFG_USERINFO_S;

typedef struct lbCFG_USERINFOLIST_S	// add [2010/9/7]
{
      HI_CHAR  UserName[MAX_USERNUM][MAX_USERNAME_LEN + 1];		//user name
      HI_CHAR 	   UserPsw[MAX_USERNUM][MAX_USERPSW_LEN + 1];	//password
      HI_S32   	   UserPri[MAX_USERNUM];						//user authority
      HI_S32  	   RemoteUserPri[MAX_USERNUM];					//remote authority	   
      HI_U8		   DeviceID[13];									//device ID
      HI_U8 	   HavePwd;										//if useful
      HI_U8         u8Align[2];       /**< 8字节对齐位*/ 											//保留字节
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];                                    /**< 保留字段 */
}LB_CFG_USERINFOLIST_S;

typedef struct lbCFG_DELUSERINFO_S
{
	LB_CFG_USERINFOLIST_S oldUserInfo;
	HI_S32    DelUserId;
	HI_U8         u8Align[4];       /**< 8字节对齐位*/ 											//保留字节
}LB_CFG_DELUSERINFO_S;

typedef struct hiCFG_GROUPINFO_S
{
    HI_U32 u32GroupID;                                   /**< group ID,ignore the field while adding user*/
    HI_U32  u32Authority;                                /**< authority list, by bit;
                                                                    0-off,
                                                                    1-on                                                                 
                                                         */
    HI_CHAR aszGroupName[HI_CFG_USRMNG_USRNAME_MAXLEN];  /**< group name */
    HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];              /**< reserved */
} HI_CFG_GROUPINFO_S;

typedef struct hiCFG_PTZ_ATTR_S
{
    HI_S32 s32ChnID;        /**< channel ID*/
    HI_U32 u32Protocol;     /**< protocol type: see HI_CFG_PTZ_PROTOCOL_E */
    HI_U8 u8Baudrate;       /**< baud rate: see HI_CFG_PTZ_BAUDRATE_E */
    HI_U8 u8DataBit;        /**< data bit:  0-8, 1-7, 2-6, 3-5*/
    HI_U8 u8StopBit;        /**< stop bit:  0-1, 1-2*/
    HI_U8 u8Check;          /**< check mode: 0-None, 1-Odd, 2-Even, 3-Mark, 4-Space*/
    HI_U8 u8Address;        /**< address: 1--255 */
    HI_U8 u8CruiseEnable;   /**< cruise switch: 0-close, 1-open*/  
    HI_U8 u8Align[2];       /**< 8 byte align*/          
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN];   /**< reserved*/
} HI_CFG_PTZ_ATTR_S;

//PHONE SMS [2011/5/3]
//手机警报信息
typedef struct hiCFG_PHONE_BASEATTR_S{
	HI_U8 PhoneNumber[6][20]; //MAX_PHONE_NUM组电话号码
	HI_U8 PhoneVideoLoss;  //视频丢失报警号码 0-5
	HI_U8 SMSEnable[6];
	HI_U8 PhoneVLState;  //视频丢失报警开关 0 -2  0:CPTP 1:SMS 2 off
	HI_U8 PhoneHDDLoss;  //硬盘丢失报警号码 0- 5 
	HI_U8 PhoneHDDState;  //硬盘丢失报警开关 0-1 0:SMS 1:off
	HI_U8 u8Align[6];       /**< 8字节对齐位*/   
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];              /**< 保留字段 */
}HI_CFG_PHONE_BASEATTR_S;
//彩信设置信息
typedef struct hiCFG_PHONE_MMSATTR_S{
	HI_U8 APN[30];
	HI_U8 proxy[30];
	HI_U8 MMSC[30];
	HI_U32 port;
	HI_U8 u8Align[2];       /**< 8字节对齐位*/   
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];              /**< 保留字段 */
}HI_CFG_PHONE_MMSATTR_S;
//
typedef struct hiCFG_PHONE_ATTR_S{
	HI_CFG_PHONE_BASEATTR_S stPhoneBaseAttr;
	HI_CFG_PHONE_MMSATTR_S stPhoneMMSAttr;
}HI_CFG_PHONE_ATTR_S;

typedef struct hiCFG_RTSP_ATTR_S{
  	unsigned long rtspport;                
  	unsigned long rtpstartport;     
  	unsigned long connectnumber;
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];              /**< 保留字段 */
}HI_CFG_RTSP_ATTR_S; 

#define MAX_BWIP_NUM 6
typedef struct _BWIpAddr_{
	HI_U8 	enble;
	HI_U8	listboxNum;
	HI_U8  	IPAddr[4];
	HI_U8    u8Align[2];       /**< 8字节对齐位*/   
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];              /**< 保留字段 */
} BWIpAddr;
typedef struct _BWIpParameter_{
	BWIpAddr  	BIP[MAX_BWIP_NUM];
	BWIpAddr  	WIP[MAX_BWIP_NUM];
	HI_U8 	mode;
	HI_U8 	BNum;
	HI_U8 	WNum;
	HI_U8 u8Align[5];       /**< 8字节对齐位*/   
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];      
} BWIpparameter_t;

typedef struct _netsmssetting_{
	unsigned char netsmsswitch;/*1：开2:关*/
	unsigned char sleeptime;/*间隔时间*/
	HI_U8 u8Align[6];       /**< 8字节对齐位*/  
	/*用户名*/
	char username[24];
	/*密码*/
	char password[24];
	char Phone[3][24]; /*电话号码*/	
 
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];        
}netsmssetting_t;

typedef struct _FtpSetting_{
	unsigned char ftpSwitch;
	unsigned int port;
	char remoteHost[30];
	unsigned char sleepTime;
	HI_U8 u8Align[4];       /**< 8字节对齐位*/   
	char user[24];
	char password[24];
	HI_U8 u8Reserve[HI_CFG_RESERVE_MAXLEN];              /**< 保留字段 */
}FtpSetting_t;	

typedef struct hiCFG_USBDISK_INFO_S
{
    HI_U32 u32USBDiskNum;   /**< USB disk number: 0~4 */
    HI_U8 u8Align[4];       /**< 8 byte align*/
    HI_CHAR aszLabel[HI_CFG_MAX_USBDISK_NUM][HI_CFG_LABEL_BUFFER_LEN];  /**< USB disk label */    
    HI_U64 au64TotalSpace[HI_CFG_MAX_USBDISK_NUM];                      /**< total capacity, unit:  byte */
    HI_U64 au64LeftSpace[HI_CFG_MAX_USBDISK_NUM];                       /**< free capacity, unit: byte */
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN];                            /**< reserved*/
} HI_CFG_USBDISK_INFO_S;

typedef struct hiCFG_HDD_INFO_S
{
    HI_U32 u32HddNum;   /**< HDD number: 0~16 */
    HI_U8 u8Align[4];   /**< 8 byte align*/
    HI_CHAR aszModel[HI_CFG_MAX_HDD_NUM][HI_CFG_NAME_BUFFER_LEN];   /**< HDD model*/
    HI_U32 au32State[HI_CFG_MAX_HDD_NUM];                           /**< HDD state */
    HI_U64 au64TotalSize[HI_CFG_MAX_HDD_NUM];                       /**< total capacity, unit:  byte */
    HI_U64 au64FreeSize[HI_CFG_MAX_HDD_NUM];                        /**< free capacity, unit: byte */
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN];                        /**< reserved*/
} HI_CFG_HDD_INFO_S;

typedef struct hiCFG_HDD_ATTR_S
{
    HI_U32 u32OverWriteMode;                /**< overwrite mode:see HI_CFG_OVERWRITE_E */
    HI_U32 u32OverWritePeriod;              /**< overwrite period,  unit:  minute*/
    HI_U8 au8WorkMode[HI_CFG_MAX_HDD_NUM];  /**< work mode:  0-read-write, 1-redundancy, 2-read only*/
    HI_U8 au8WorkGroup[HI_CFG_MAX_HDD_NUM]; /**< work group*/
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN];/**< reserved*/
} HI_CFG_HDD_ATTR_S;

typedef struct hiCFG_DEVICE_INFO_S
{
    HI_CHAR aszDeviceName[HI_CFG_NAME_BUFFER_LEN];          /**< device name*/
    HI_CHAR aszDeviceSN[HI_CFG_SN_BUFFER_LEN];              /**< device SN*/
    HI_CHAR aszDeviceType[HI_CFG_NAME_BUFFER_LEN];          /**< device type */
    HI_U32 u32DeviceID;                                     /**< device ID*/    
    HI_U32 u32HardwareVersion;                              /**< hardware version */
    HI_CHAR aszSoftVer[HI_CFG_VERSION_BUFFER_LEN];			/**< software version */
	HI_CHAR	aszReleaseDate[HI_CFG_VERSION_BUFFER_LEN];		/**< release date */
    HI_CHAR aszAppVer[HI_CFG_VERSION_BUFFER_LEN];           /**< APP version*/
    HI_CHAR aszUbootVer[HI_CFG_VERSION_BUFFER_LEN];         /**< master Uboot version*/
    HI_CHAR aszKernelVer[HI_CFG_VERSION_BUFFER_LEN];        /**< master kernel version*/
    HI_CHAR aszRootfsVer[HI_CFG_VERSION_BUFFER_LEN];        /**< master rootfs version*/
    HI_CHAR aszSlaveUbootVer[HI_CFG_VERSION_BUFFER_LEN];    /**< slave Uboot version*/
    HI_CHAR aszSlaveKernelVer[HI_CFG_VERSION_BUFFER_LEN];   /**< slave kernel version*/
    HI_CHAR aszSlaveRootfsVer[HI_CFG_VERSION_BUFFER_LEN];   /**< slave rootfs version*/
    HI_CHAR aszStartupLogoVer[HI_CFG_VERSION_BUFFER_LEN];   /**< startup logo version*/
    HI_CHAR aszUpgradeLogoVer[HI_CFG_VERSION_BUFFER_LEN];   /**< upgrade logo version*/
    HI_U64 u64ParaID;                                       /**< startup parameter */
    HI_U8 au8Reserve[HI_CFG_RESERVE_MAXLEN];                /**< reserved*/
} HI_CFG_DEVICE_INFO_S;

typedef struct hiCFG_DEVICE_CAPS_S
{
    HI_S32 s32MaxVIChnCnt;          /**< maximum video input channel count*/
    HI_S32 s32MaxAIChnCnt;          /**< maximum audio input channel count,A:audio*/
    HI_S32 s32MaxVODevCnt;          /**< maximum video output device count:see HI_CFG_DISPLAYER_DEV_E*/    
    HI_S32 s32MaxVOChnCnt;          /**< maximum video output channel count*/    
    HI_S32 s32MaxAOChnCnt;          /**< maximum audio output channel count*/    
    HI_S32 s32MaxAlarmInCnt;        /**< maximum alarm input count*/
    HI_S32 s32MaxAlarmOutCnt;       /**< maximum alarm output count*/   
    HI_S32 s32MaxPTZCnt;            /**< maximum PTZ count*/
    HI_S32 s32H264Caps;             /**< H264 encode capability */
    HI_S32 s32MaxVideoResolution;   /**< maximum resolution:see HI_CFG_RES_E*/
	HI_S32 s32MaxRecordeCnt;      	/*maximum record count*/
	HI_S32 s32MaxDisplayCnt;	  	/*maximum display count*/
	HI_S32 s32MaxNetDdnsCnt;		/*maximum DDNS count*/
	HI_S32 s32MaxNetIpPrevCnt;		/*maximum IP preview count*/
	HI_S32 s32MaxNetEmailCnt;		/*maximum E-mail count*/
	HI_S32 s32MaxNewworkDevCnt;     /*maximum network device count*/
	HI_S32 s32MaxUserCnt;           /*maximum user count*/
	HI_S32 s32MaxUserGroupCnt;      /*maximum group count*/
	HI_S32 s32MaxAuthCnt;           /*maximum authority count*/
	HI_S32 s32MaxHddCnt;            /*maximum HDD count*/
    HI_S32 s32MaxMainVBitRate;      /**< maximum bit rate of mainstream*/
    HI_S32 s32MaxSubVBitRate;       /**< maximum bit rate of substream*/
    HI_S32 s32MinSubVBitRate;       /**< minimum bit rate of substream*/
    HI_U8 u8Align[4];               /**< 8 byte align*/
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< reserved */    
}HI_CFG_DEVICE_CAPS_S;

/*---------- Types Definition End ----------*/
// add by dee, 2010.09.24,ipcam
typedef struct hiCFG_SDCARD_INFO_S
{
	int nCardNo;
	int nCardType;
	int nCardConnect;
	int nCardFileFormat;
	unsigned __int64  nCardLeftCapacity;
	unsigned __int64  nCardSize;
} HI_CFG_SDCARD_INFO_S;


///DVR status, add [2010/10/30]
typedef struct hiCFG_DVRSTATUS_S
{
    HI_U8 u8Record[16];		/**< DVR recording: 0-no, 1-recording*/
    HI_U8 u8Motion[16];		/**< MD alarming: 0-no,1-alarming*/
    HI_U8 u8Sensor[16];		/**< sensor alarming: 0-no,1-alarming*/
    HI_U8 u8VideoLoss;      /**< video loss?: 0-no，1-loss*/
    HI_U8 u8HddLoss;		/**< HDD loss?: 0-no，1-loss*/
    HI_U8 u8HddFull;		/**< full Hdd?: 0-no，1-full*/
    HI_U8 u8Align[5];       /**< 8 byte align*/
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< 保留字节 */  	
} HI_CFG_DVRSTATUS_S;

//TV ADD  [2011/2/19]
typedef struct hiCFG_TV_ATTR_S
{
    HI_U32 u32TVCurProg;              /**< 频道号*/
    HI_U32 u32TVSTAND;                /**< 制式 */
    HI_U8  au8Reserve[HI_CFG_RESERVE_MAXLEN]; /**< 保留字节 */  	
} HI_CFG_TV_ATTR_S;


typedef struct _hiCFG_DVRNTP_S
{
	HI_U8 ntpSwitch;
	HI_U8 clycetime;
	HI_U8 timeZone;
	HI_U8 u8Align[5];
	unsigned long port;	
	HI_CHAR hostName[36];
	HI_U8 au8Reserve[28];
}HI_CFG_DVRNTP_S;




#endif
