
#ifndef _HI_COMMON_STRUCTS_H_
#define _HI_COMMON_STRUCTS_H_


#ifdef __cplusplus
extern "C" {
#endif



// 4 byte align
#pragma pack(4)



/******************************************************************************************************
Device type name 
******************************************************************************************************/
enum HI_DVR_TYPE
{
	DVR_NO_SUPPORT_TYPE		= 0L,
	DVR_COMPUTER_TYPE		= 0x0F000101L,			// Device type to connect PC
	DVR_TEMP_TYPE			= 0x0F000200L,			// Temporary device type

	DVR_STM_REALTIME_TYPE	= 0x01000101L,			// 6304, 6308
	DVR_ATM_REALTIME_TYPE	= 0x01000102L,			// 6204, 6214
	DVR_65xx_REALTIME_TYPE	= 0x01000103L,			// 6508, 6516
	DVR_D82xx_TYPE			= 0x01000104L,			// 8204
	DVR_MDVR_V6_TYPE		= 0x01000201L,
	DVR_MDVR_6N_TYPE		= 0x01000202L,			// V6N, REI, G6N
	DVR_MDVR_C2_TYPE		= 0x01000203L,			// C2
	DVR_MDVR_G10_TYPE		= 0x01000204L,			// MDVR, G10
	DVR_MDVR_G11_TYPE		= 0x01000205L,			// Reserved
	DVR_MDVR_M26_TYPE		= 0x01000206L,			// 26(67)
	DVR_MDVR_M96_TYPE		= 0x01000207L,			// 9600
	DVR_MDVR_A16_TYPE		= 0x01000208L,			// A16
	DVR_MDVR_X11_TYPE		= 0x01000209L,			// X11
	DVR_MDVR_HD_TYPE		= 0x01000210L,			// HD	
	DVR_DVS_TYPE			= 0x01000301L,			// DVS
	DVR_HYBRID_TYPE         = 0x01000401L,          // HYBRID
	DVR_15NVR8_TYPE         = 0x01000402L,          // 3515 8 chn NVR
	DVR_20HYBRID_TYPE         = 0x01000403L,          // 3520 16 chn NVR
//	DVR_6N_REALTIME_TYPE,			//6N  mainboard	
};

enum HI_DVR_SUBTYPE
{
	DVR_SUB_NONEED			= 0L,					// Not need this subclass
	DVR_SUB_NOT_SUPPORT		= 1L,

	// ---> DVR_STM_REALTIME_TYPE
	DVR_SUB_STM_6304		= 0x01010200L,			// 63xx = STM
	DVR_SUB_STM_6308		= 0x01010300L,

	// ---> DVR_65xx_REALTIME_TYPE
	DVR_SUB_65xx_6516		= 0x01030600L,			// 65xx
	DVR_SUB_65xx_6508		= 0x01030601L,
	DVR_SUB_65xx_6508_S		= 0x01030606L,			// 6508_S, 8 channel; The difference to 6508 is the record file only stores a single video channel.
	DVR_SUB_65xx_6504_S		= 0x01030607L,			// 6504_S, 4 channel; The record file only stores a single video channel.

	// ---> DVR_ATM_REALTIME_TYPE
	DVR_SUB_ATM_6204		= 0x01020100L,			// ATM
	DVR_SUB_ATM_6214		= 0x01020500L,
   	DVR_SUB_ATM_KL_6214     = 0x01020501L,			// some specific users use; The difference to DVR_SUB_ATM_6214 is the cut style of picture.

	// ---> DVR_D82XX_TYPE
	DVR_SUB_D82_8204_STD_4	= 0x01020512L,			// 8204

	// ---> DVR_MDVR_V6_TYPE
	DVR_SUB_V6_CAR			= 0x02016100L,			//MDVR--v6, 4 channel

	// ---> DVR_MDVR_6N_TYPE
	// DVR_SUB_V6_M65,								//8 channel, 6N series
	DVR_SUB_MV6N_STD_1		= 0x02026201L,			//0x6201, V6N standard 1 channel
	DVR_SUB_MV6N_STD_4		= 0x02026202L,			//0x6202, V6N standard 4 channels
	DVR_SUB_MV6N_STD_8		= 0x02026203L,			//0x6203, V6N standard 8 channels

	DVR_SUB_MV6N2_STD_4		= 0x02026272L,			// V6N2 standard 4 channels
	DVR_SUB_MV6N2_STD_8		= 0x02026273L,			// V6N2 standard 8 channels

	DVR_SUB_MV6N_NT_1		= 0x02026211L,			// NT = Net Translation, V6N 1 channel
	DVR_SUB_MV6N_NT_4		= 0x02026212L,			// V6N net translation edition
	DVR_SUB_MV6N_NT_8		= 0x02026213L,

	DVR_SUB_MV6N_REI_STD_1	= 0x02026221L,			// REI standard x channels
	DVR_SUB_MV6N_REI_STD_4	= 0x02026222L,
	DVR_SUB_MV6N_REI_STD_8	= 0x02026223L,

	// Reserved
	DVR_SUB_MV6N_REI_NT_1	= 0x02026231L,			// REI net translation edition x channels
	DVR_SUB_MV6N_REI_NT_4	= 0x02026232L,
	DVR_SUB_MV6N_REI_NT_8	= 0x02026233L,

	DVR_SUB_MG6N_STD_1		= 0x02026241L,			// G6N standard x channels
	DVR_SUB_MG6N_STD_4		= 0x02026242L,
	DVR_SUB_MG6N_STD_8		= 0x02026243L,

	DVR_SUB_MG6N_NT_1		= 0x02026251L,			// G6N net translation edition x channels
	DVR_SUB_MG6N_NT_4		= 0x02026252L,
	DVR_SUB_MG6N_NT_8		= 0x02026253L,

	// ---> DVR_MDVR_C2_TYPE
	DVR_SUB_MC2_STD_2		= 0x02036412L,			// C2 standard 4 channels

	DVR_SUB_MC2_MINI_1		= 0x02036421L,			// Mini 1 channel
	DVR_SUB_MC2_MINI_4		= 0x02036422L,			// Mini 4 channels
	DVR_SUB_MC2_MINI_8		= 0x02036423L,			// Mini 8 channels
	DVR_SUB_MC2_MINI_16		= 0x02036424L,			// Mini 16 channels

	DVR_SUB_MC2_MINI_NT_1	= 0x02036431L,			// Mini net translation edition
	DVR_SUB_MC2_MINI_NT_4	= 0x02036432L,
	DVR_SUB_MC2_MINI_NT_8	= 0x02036433L,

	// ---> DVR_MDVR_G10_TYPE
	DVR_SUB_MG10_D1_3		= 0x02046301L,			// 3 channels D1
	DVR_SUB_MG10_D1_4		= 0x02046300L,			// Original DVR_SUB_MDVR_M1001
	//DVR_SUB_MDVR_M1001,							// 4 channels d1 machine base on MDVR M10 mainboard

	// ---> DVR_MDVR_G11_TYPE
	DVR_SUB_MG11_STD_4		= 0x02056702L,			// G11's 4 channels

	// ---> DVR_MDVR_M26_TYPE
	DVR_SUB_M26_NT_4		= 0x02066602L,			// 6700 Net 4 channels
	DVR_SUB_M26_NT_8		= 0x02066603L,			// 6700 Net 8 channels

	// ---> DVR_MDVR_M96_TYPE
	DVR_SUB_M96_NT_4		= 0x02079602L,			// 9600 Net 4 channel, 8304 Net 4 channel
	DVR_SUB_M96_NT_8		= 0x02079603L,			// 9600 Net 8 channel, 8304 Net 8 channel
	DVR_SUB_M96_NTAL_4		= 0x02079612L,			// For specific user
	DVR_SUB_M96_NTAL_8		= 0x02079613L,			// For specific user
	DVR_SUB_M96_NTAL_16		= 0x02079614L,			// For specific user
	DVR_SUB_M96_NTAL_16D	= 0x10009615L,
	DVR_SUB_M96_NTAL_8D		= 0x10009617L,

	// ---> DVR_MDVR_A16_TYPE
	DVR_SUB_MA16_NT_4		= 0x02086712L,			// Internal standard A16, Net 4 channel
	DVR_SUB_MA16IND_NT_4	= 0x02086722L,			// Indian version A16 Net 4 channel

	// ---> DVR_MDVR_X11_TYPE
	DVR_SUB_MX11_NT_4		= 0x02091112L,			// x11 Net 4 channel

	// ---> DVR_DVS_TYPE
	DVR_SUB_DVS_STD_1		= 0x03018601L,			// DVS	1 channel
	DVR_SUB_DVS_STD_2		= 0x03018602L,			// DVS	2 channel
	DVR_SUB_DVS_STD_4		= 0x03018604L,			// DVS	4 channel

	DVR_SUB_HYBRID3515_4_4  = 0x04000008L,          // HI3515, 4 analog + 4 digital 
	DVR_SUB_NVR3515_0_8     = 0x04000009L,          // HI3515, 0 analog + 8 digital 
	DVR_SUB_HYBRID3520_8_8     = 0x0400000AL,          // HI3520, 8 analog + 8 digital

	// ipcam
	IPCAM_SUB_M96_1			= 0x05019610L,					// IPCAM DEVICE
	IPCAM_SUB_M96_720P_1    = 0x0501961AL,			// IPCAM DEVICE 720p

	DVR_SUB_HD_4			= 0x06000004L
};


// List of device type; for device search 
struct HI_DEVICE_TYPELIST
{
	HI_DVR_TYPE		devDataType;		// Device type
	HI_DVR_SUBTYPE	devSubType;			// Sub type
	unsigned long	device_id;			// Device ID
	unsigned char	devSign[20];		// String of device type
	unsigned char	szDevType[64];
	unsigned char	szDevSubType[64];
};

static const HI_DEVICE_TYPELIST gDeviceTypeList[] = {
	{DVR_STM_REALTIME_TYPE,		DVR_SUB_STM_6304,		0x0200,	"DVR6304_1_RM",	"DVR_STM_REALTIME_TYPE",	"DVR_SUB_STM_6304"			},
	{DVR_STM_REALTIME_TYPE,		DVR_SUB_STM_6308,		0x0300,	"DVR6308_1_RM",	"DVR_STM_REALTIME_TYPE",	"DVR_SUB_STM_6308"			},

	{DVR_ATM_REALTIME_TYPE,		DVR_SUB_ATM_6214,		0x0500,	"DVR6214_1_RM",	"DVR_ATM_REALTIME_TYPE",	"DVR_SUB_ATM_6214"			},
	{DVR_ATM_REALTIME_TYPE,		DVR_SUB_ATM_KL_6214,	0x0501,	"DVR6214kl_1_",	"DVR_ATM_REALTIME_TYPE",	"DVR_SUB_ATM_KL_6214"		},

	{DVR_65xx_REALTIME_TYPE,	DVR_SUB_65xx_6516,		0x0600,	"DVR6516_1_RM",	"DVR_65xx_REALTIME_TYPE",	"DVR_SUB_65xx_6516"			},
	{DVR_65xx_REALTIME_TYPE,	DVR_SUB_65xx_6516,		0x0601,	"DVR6616_2_RM",	"DVR_65xx_REALTIME_TYPE",	"DVR_SUB_65xx_6516"			},
	{DVR_65xx_REALTIME_TYPE,	DVR_SUB_65xx_6508,		0x0602,	"DVR6508_1_RM",	"DVR_65xx_REALTIME_TYPE",	"DVR_SUB_65xx_6508"			},
	{DVR_65xx_REALTIME_TYPE,	DVR_SUB_65xx_6508,		0x0603,	"DVR6508_2_RM",	"DVR_65xx_REALTIME_TYPE",	"DVR_SUB_65xx_6508"			},

	{DVR_D82xx_TYPE,			DVR_SUB_D82_8204_STD_4,	0x0512,	"DVRLOW8204_2",	"DVR_D82xx_TYPE",			"DVR_SUB_D82_8204_STD_4"	},

	{DVR_MDVR_V6_TYPE,			DVR_SUB_V6_CAR,			0x6100,	"CARDVRV6_1_R",	"DVR_MDVR_V6_TYPE",			"DVR_SUB_V6_CAR"			},

	// MDVR - 6N series
	// V6N
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_STD_1,		0x6201,	"MDVR6NV6NS_1",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_STD_1"		},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_STD_4,		0x6202,	"MDVR6NV6NS_2",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_STD_4"		},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_STD_8,		0x6203,	"MDVR6NV6NS_3",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_STD_8"		},

	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N2_STD_4,	0x6272,	"MDVRV6N2-ST2",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N2_STD_4"		},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N2_STD_8,	0x6273,	"MDVRV6N2-ST3",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N2_STD_8"		},

	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_NT_1,		0x6211,	"MDVR6NV6NN_1",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_NT_1"			},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_NT_4,		0x6212,	"MDVR6NV6NN_2",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_NT_4"			},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_NT_8,		0x6213,	"MDVR6NV6NN_3",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_NT_8"			},

	// REI standard edition
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_REI_STD_1,	0x6221,	"MDVR6NREIS_1",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_REI_STD_1"	},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_REI_STD_4,	0x6222,	"MDVR6NREIS_2",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_REI_STD_4"	},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_REI_STD_8,	0x6223,	"MDVR6NREIS_3",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_REI_STD_8"	},

	// REI net translation edition, reserved
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_REI_NT_1,	0x6231,	"MDVR6NREIN_1",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_REI_NT_1"		},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_REI_NT_4,	0x6232,	"MDVR6NREIN_2",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_REI_NT_4"		},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MV6N_REI_NT_8,	0x6233,	"MDVR6NREIN_3",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MV6N_REI_NT_8"		},

	// G6N standard edition
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MG6N_STD_1,		0x6241,	"MDVR6NG6NS_1",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MG6N_STD_1"		},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MG6N_STD_4,		0x6242,	"MDVR6NG6NS_2",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MG6N_STD_4"		},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MG6N_STD_8,		0x6243,	"MDVR6NG6NS_3",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MG6N_STD_8"		},

	// G6N Net edition
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MG6N_NT_1,		0x6251,	"MDVR6NG6NN_1",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MG6N_NT_1"			},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MG6N_NT_4,		0x6252,	"MDVR6NG6NN_2",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MG6N_NT_4"			},
	{DVR_MDVR_6N_TYPE,			DVR_SUB_MG6N_NT_8,		0x6253,	"MDVR6NG6NN_3",	"DVR_MDVR_6N_TYPE",			"DVR_SUB_MG6N_NT_8"			},

	// ---> DVR_MDVR_C2_TYPE
	{DVR_MDVR_C2_TYPE,			DVR_SUB_MC2_STD_2,		0x6412,	"MDVRC2_STD_2",	"DVR_MDVR_C2_TYPE",			"DVR_SUB_MC2_STD_2"			},

	{DVR_MDVR_C2_TYPE,			DVR_SUB_MC2_MINI_1,		0x6421,	"MDVRC2MINI_1",	"DVR_MDVR_C2_TYPE",			"DVR_SUB_MC2_MINI_1"		},
	{DVR_MDVR_C2_TYPE,			DVR_SUB_MC2_MINI_4,		0x6422,	"MDVRC2MINI_2",	"DVR_MDVR_C2_TYPE",			"DVR_SUB_MC2_MINI_4"		},
	{DVR_MDVR_C2_TYPE,			DVR_SUB_MC2_MINI_8,		0x6423,	"MDVRC2MINI_3",	"DVR_MDVR_C2_TYPE",			"DVR_SUB_MC2_MINI_8"		},
	{DVR_MDVR_C2_TYPE,			DVR_SUB_MC2_MINI_16,	0x6424,	"MDVRC2MINI_4",	"DVR_MDVR_C2_TYPE",			"DVR_SUB_MC2_MINI_16"		},

	// Mini net translation edition
	{DVR_MDVR_C2_TYPE,			DVR_SUB_MC2_MINI_NT_1,	0x6431,	"MDVRC2MINN_1",	"DVR_MDVR_C2_TYPE",			"DVR_SUB_MC2_MINI_NT_1"		},
	{DVR_MDVR_C2_TYPE,			DVR_SUB_MC2_MINI_NT_4,	0x6432,	"MDVRC2MINN_2",	"DVR_MDVR_C2_TYPE",			"DVR_SUB_MC2_MINI_NT_4"		},
	{DVR_MDVR_C2_TYPE,			DVR_SUB_MC2_MINI_NT_8,	0x6433,	"MDVRC2MINN_3",	"DVR_MDVR_C2_TYPE",			"DVR_SUB_MC2_MINI_NT_8"		},

	// ---> DVR_MDVR_G10_TYPE
	{DVR_MDVR_G10_TYPE,			DVR_SUB_MG10_D1_4,		0x6300,	"CARDVRM10_1_",	"DVR_MDVR_G10_TYPE",		"DVR_SUB_MG10_D1_4"			},
	{DVR_MDVR_G10_TYPE,			DVR_SUB_MG10_D1_3,		0x6301,	"CARDVRM10_0_",	"DVR_MDVR_G10_TYPE",		"DVR_SUB_MG10_D1_3"			},

	//{0x4100, "DVRVS-1_2_R"},
	//{0x4200, "DVRVS-4_2_R"}

	// ---> DVR_MDVR_G11_TYPE
	{DVR_MDVR_G11_TYPE,			DVR_SUB_MG11_STD_4,		0x6702,	"MDVRG11_14_R",	"DVR_MDVR_G11_TYPE",		"DVR_SUB_MG11_STD_4"		},

	// ---> DVR_MDVR_M26_TYPE
	{DVR_MDVR_M26_TYPE,			DVR_SUB_M26_NT_4,		0x6602,	"MDVR26NT_2_R",	"DVR_MDVR_M26_TYPE",		"DVR_SUB_M26_NT_4"			},
	{DVR_MDVR_M26_TYPE,			DVR_SUB_M26_NT_8,		0x6603,	"MDVR26NT_3_R",	"DVR_MDVR_M26_TYPE",		"DVR_SUB_M26_NT_8"			},

	// ---> DVR_MDVR_M96_TYPE
	{DVR_MDVR_M96_TYPE,			DVR_SUB_M96_NT_4,		0x9602,	"MDVR96NT_2_R",	"DVR_MDVR_M96_TYPE",		"DVR_SUB_M96_NT_4"			},
	{DVR_MDVR_M96_TYPE,			DVR_SUB_M96_NT_8,		0x9603,	"MDVR96NT_3_R",	"DVR_MDVR_M96_TYPE",		"DVR_SUB_M96_NT_8"			},
	{DVR_MDVR_M96_TYPE,			DVR_SUB_M96_NTAL_4,		0x9612,	"MDVR96NTAL_2",	"DVR_MDVR_M96_TYPE",		"DVR_SUB_M96_NTAL_4"		},
	{DVR_MDVR_M96_TYPE,			DVR_SUB_M96_NTAL_8,		0x9613,	"MDVR96NTAL_3",	"DVR_MDVR_M96_TYPE",		"DVR_SUB_M96_NTAL_8"		},
	{DVR_MDVR_M96_TYPE,			DVR_SUB_M96_NTAL_16,	0x9614,	"MDVR96NTAL_4",	"DVR_MDVR_M96_TYPE",		"DVR_SUB_M96_NTAL_16"		},

	// ---> DVR_MDVR_A16_TYPE
	{DVR_MDVR_A16_TYPE,			DVR_SUB_MA16_NT_4,		0x6712,	"MDVRA16NT_4_",	"DVR_MDVR_A16_TYPE",		"DVR_SUB_MA16_NT_4"			},
	{DVR_MDVR_A16_TYPE,			DVR_SUB_MA16IND_NT_4,	0x6722,	"MDVRA16NIND4",	"DVR_MDVR_A16_TYPE",		"DVR_SUB_MA16IND_NT_4"		},

	// --> DVR_MDVR_X11_TYPE
	{DVR_MDVR_X11_TYPE,			DVR_SUB_MX11_NT_4,		0x1112,	"MDVRX11_2_RM",	"DVR_MDVR_X11_TYPE",		"DVR_SUB_MX11_NT_4"			},

	// DVS
	// 0x8601 and 0x4400 are the same device
	{DVR_DVS_TYPE,				DVR_SUB_DVS_STD_1,		0x8601,	"DVSVS8601_1_",	"DVR_DVS_TYPE",				"DVR_SUB_DVS_STD_1"			},
	{DVR_DVS_TYPE,				DVR_SUB_DVS_STD_1,		0x4400,	"DVSVS8601_1_",	"DVR_DVS_TYPE",				"DVR_SUB_DVS_STD_1"			},
	{DVR_DVS_TYPE,				DVR_SUB_DVS_STD_2,		0x8602,	"DVSVS8602_1_",	"DVR_DVS_TYPE",				"DVR_SUB_DVS_STD_2"			},
	{DVR_DVS_TYPE,				DVR_SUB_DVS_STD_4,		0x8604,	"DVSVS8604_1_",	"DVR_DVS_TYPE",				"DVR_SUB_DVS_STD_4"			},
};


//-----------------------------------------definition of standard record's file header --------------------------------------//

//-------------audio and video frame header definition ----------//
struct HI_VFI_HEADER
{
	unsigned long	lFrameType;			// Frame type; I frame - x0dc, P frame - x1dc
	unsigned long	lStreamType;		// Stream format; H264, the other is not defined
	unsigned long	lFrameLen;			// Length of the video data
	unsigned short	usExtendLen;		// Extend data length
	unsigned short	usExtendMode;		// Extend mode
	ULONGLONG		ullPts;				// Time stamp , the unit is microsecond, 1 second == 1,000,000 microsecond

};

/**********************
Audio packet header structure, maybe more than one audio frame in a package. The number of audio frame == PacketLen/FrameLen
FrameType: XYwb, the X means channels number, the Y means audio format:
 Y == 1 : AMR
 Y == 2 : G726
 Y == 3 : ADPCM
**********************/
struct HI_AFI_HEADER
{
	unsigned long	lFrameType;			// XYwb, the X means channel number, the Y means audio format
	unsigned short	usFrameLen;			// a audio frame's length
	unsigned short	usPacketLen;		// In the package, all audio data's total length.
};



/******************************************************************************************************
The header structure of file header
******************************************************************************************************/
// verFile = 1
// corresponding document version: 1.00.00	


struct HI_VIDEO_AUDIO
{
	unsigned char		chlCount;
	unsigned char		sampleBits;
	char				reserved1[2];
	unsigned int		bitRate;
	unsigned int		sampleRate;
};

struct HI_VIDEO_STHDR
{
	char				attribute[4];
	unsigned int		size;
};


struct HI_VIDEO_FILEHEADER_1
{
	HI_VIDEO_STHDR		hdr;
	char				verDev[28];
	unsigned char		verFile;			// 1
	unsigned char		begYear;
	unsigned char		begMonth;
	unsigned char		begDay;
	unsigned char		begHour;
	unsigned char		begMinute;
	unsigned char		begSecond;
	unsigned char		endYear;
	unsigned char		endMonth;
	unsigned char		endDay;
	unsigned char		endHour;
	unsigned char		endMinute;
	unsigned char		endSecond;
	unsigned char		chlCount;
	unsigned char		recordType;
	unsigned char		fileProtected;
	unsigned char		recordMode;
	unsigned char		videoType;
	char				reserved1[2];
	HI_VIDEO_AUDIO		audio;
	char				reserved2[8];
	unsigned short		usdevType;
	char				reserved3[2];
	char				szdevType[12];
};

// verFile = 2; structure is upward-compatible
// corresponding document version: 1.00.02
struct HI_VIDEO_FILEHEADER_2
{
	HI_VIDEO_STHDR		hdr;
	char				verDev[28];
	unsigned char		verFile;			// 2 or 3
	unsigned char		begYear;
	unsigned char		begMonth;
	unsigned char		begDay;
	unsigned char		begHour;
	unsigned char		begMinute;
	unsigned char		begSecond;
	unsigned char		endYear;
	unsigned char		endMonth;
	unsigned char		endDay;
	unsigned char		endHour;
	unsigned char		endMinute;
	unsigned char		endSecond;
	unsigned char		chlCount;
	unsigned char		recordType;
	unsigned char		fileProtected;
	unsigned char		recordMode;
	unsigned char		videoType;
	unsigned short		devNo;				// impropriate primary "reserved"
	HI_VIDEO_AUDIO		audio;
	char				reserved2[8];
	unsigned short		usdevType;
	char				reserved3;
	unsigned char		dateShowFmt;		//  be separated from resrved3
	char				szdevType[12];
};

// For some reason, there is not structure edition 3. If you see the edition 3 , you can treat it as edition 2.

// verFile = 4, 5; structure upward-compatible
// corresponding document version: 1.00.04, 1.00.05
struct HI_VIDEO_FILEHEADER_4
{
	HI_VIDEO_STHDR		hdr;
	char				verDev[28];
	unsigned char		verFile;				// 4
	unsigned char		begYear;
	unsigned char		begMonth;
	unsigned char		begDay;
	unsigned char		begHour;
	unsigned char		begMinute;
	unsigned char		begSecond;
	unsigned char		endYear;
	unsigned char		endMonth;
	unsigned char		endDay;
	unsigned char		endHour;
	unsigned char		endMinute;
	unsigned char		endSecond;
	unsigned char		chlCount;
	unsigned char		recordType;
	unsigned char		fileProtected;
	unsigned char		recordMode;
	unsigned char		videoType;
	unsigned short		devNo;
	HI_VIDEO_AUDIO		audio;
	unsigned long		lIndexTableOffset;		//  be separated from reserved2
	unsigned long		ulHeadLen;         		//  be separated from reserved2
	unsigned short		usdevType;
	char				reserved3;
	unsigned char		dateShowFmt;
	char				szdevType[12];
};

// 92
// header structure
union HI_VIDEO_FILEHEADER
{
	HI_VIDEO_FILEHEADER_1	hdr1;
	HI_VIDEO_FILEHEADER_2	hdr2;
	HI_VIDEO_FILEHEADER_4	hdr4;
};

struct HI_VIDEO_CHLHEADER
{
	HI_VIDEO_STHDR		hdr;
	unsigned char		chlIndex;
	unsigned char		frameRate:5;
	unsigned char		frameRFixed:1;
	unsigned char		frameRUnit:1;
	unsigned char		frameRVer:1;
	unsigned char		resolution;
	char				reserved1;
	char				chlName[16];
};

struct HI_VIDEO_CHLDVRP
{
		unsigned char	recover;
		unsigned char	pointLeft;
		unsigned char	pointTop;
		unsigned char	pointRight;
		unsigned char	pointBottom;
		char			reserved1[3];
		char			reserved2[4];
};

struct HI_VIDEO_CHLM8P
{
	unsigned char	clockinsert;
	char			reserved1[3];
	char			reserved2[8];
};

struct HI_VIDEO_CHANNEL
{
	HI_VIDEO_CHLHEADER		chlHeader;
	union HI_VIDEO_CHLSP
	{
		char				reserved[12];
		HI_VIDEO_CHLDVRP	dvrchlp;
		HI_VIDEO_CHLM8P		mdvrm8;
	}uchlsp;
};

// 160
struct HI_VIDEO_CHLPARS
{
	HI_VIDEO_CHANNEL		channel[4];
};

// 172 < 204
struct HI_VIDEO_SMDVR
{
	HI_VIDEO_STHDR		hdr;
	char				senor_name[9][8];
	char				md_name[8];
	char				speeding_name[2][8];
	char				company_name[16];
	char				vehicle_ID[16];
	char				driver_name[16];
	char				sensor_short_name[9][2];
	char				reserved[2];
};

// 204
union HI_VIDEO_PAREX
{
	char				reserved[204];
	HI_VIDEO_SMDVR		mdvr;
};

// 8
// channel's voice attribute 
struct HI_VIDEO_CHAUDIO
{
	unsigned char cChlIndex;
	unsigned char cAudioChannels:3;
	unsigned char cSampleBits:5;
	unsigned char reserved[2];
	unsigned long lSampleRate;
};

/*
56
This member begin from version 4 
There is "stuAudio" member start from version 5.
*/
struct HI_VIDEO_FILEHEADEREX
{
	HI_VIDEO_STHDR	hdr;
	unsigned long	ulPrevRecodSecond;
	HI_VIDEO_CHAUDIO stuAudio[4];
	char			reserved[12];
};

// 512 - 92 - 160 = 260
// combo in the edition 4
struct HI_VIDEO_PAREX_4
{
	HI_VIDEO_PAREX			parEx;

	// This structure is invalid if version below 4
	HI_VIDEO_FILEHEADEREX	fileHdrEx;
};

// 92 + 160 + 260 = 512
struct HI_VIDEO_HEADER
{
	HI_VIDEO_FILEHEADER		fileHdr;
	HI_VIDEO_CHLPARS		chlPars;
	HI_VIDEO_PAREX_4		parEx;
};

/********************** the definitions of record file header **************************/



// The information which can use integer to express
struct HI_CBD_INTMSG
{
	unsigned long	lFlag;
	unsigned long	lValue;
};

/***********************************************************************************
General call-back function
parameter:
	lUserData: the data that user define
	lFlag: flag
	lValue: Specific value
***********************************************************************************/
typedef	void (* HI_CB_INTCALLBACK)( unsigned long lUserData, const HI_CBD_INTMSG *pstuIntMsg );


#pragma pack()

#ifdef __cplusplus
}
#endif

#endif