
#ifndef __DVRDEF_H__
#define __DVRDEF_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Types.h"

typedef unsigned int			Param;
typedef void *					Handle;
typedef int						Bool;

#ifdef WIN32
	#define snprintf _snprintf
#endif

#define FOR(i, max)				for (i = 0; i < (max); i++)
#define BITMSK(bit)				(int)(1 << (bit))

#define INTEGER_MIN (int)(0x80000000)
#define INTEGER_MAX (int)(0x7FFFFFFF)
#define UINTEGER_MAX (unsigned int)0xFFFFFFFF

#define TRUE					1
#define FALSE					0

#ifndef NULL
#define NULL					0
#endif

#define ON						1
#define OFF						0

#define MPG1					1
#define MPG4					4

#define CIF1					1	//1 CIF
#define CIF2					2	//2 CIF
#define CIF4					4	//4 CIF

#define NC						0	//����

#define NO						1	//����

#ifndef MAX
#define MAX(a,b)				(((a) > (b)) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a,b)				(((a) < (b)) ? (a) : (b))
#endif

#define ABS(x) ((x)>=0?(x):-(x))

#ifdef FUNC_BUILD_CHANNEL
#define channel_utol(x) (2 * x - x % 2)
#define channel_ltou(x) ((x + 1) / 2)
#else
#define channel_utol(x) (x)
#define channel_ltou(x) (x)
#endif

#define trace printf

#define tracepoint() 			do {trace("tracepoint: %s,%d\n",__FILE__,__LINE__); } while(0)

#define NAME_LEN		32
#define CHANNEL_NAME_SIZE		64
#define LABEL_LEN		32

/// ȫ�̶��峣��
enum DVRGlobal
{
	MAX_PATH_LENGTH		= 260,		///< ·����󳤶�
	MAX_USERNAME_LENGTH = 128,		///< �û�����󳤶ȣ��ֽ�
	MAX_PASSWORD_LENGTH	= 128,		///< �û�������󳤶�
	N_SYS_CH			= 32,		///< ���ͨ����
	N_CHMAX_PERLINE		= 16,		///< һ�����ͨ����
	N_SYS_COMB_CH		= 2,		///< �����ϱ���ͨ����
	N_ALM_IN			= 32,		///< ��󱨾�����ͨ����
	N_ALM_OUT			= 32,		///< ��󱨾����ͨ����
	N_PLY_CH			= 32,		///< ���ط�·��
	N_DECORDR_CH		= 32,		///< ���������·��
	N_AUDIO_IN			= 32,		///< �����Ƶ����·��
	N_PTZ_ALARM			= 16,		///< �����̨����·��
	N_WEEKS				= 7,		///< һ������
	N_TSECT				= 6,		///< ʱ�������
	N_SPLIT				= 15,		///< ���ָ�ģʽ
	N_VIDEO_OUT			= 4,		///< �����Ƶ���
	N_MATRIX_OUT		= 4,		///< ����֤���·��
	MAX_DDNS_TYPE		= 5,		///< ���DDNS����
	MAX_ALARMSERVER_TYPE= 5,		///< ��󱨾�����������
	MAX_ARSP_TYPE		= 5,		///< �������ע�����������
	MAX_CHANNEL_WIDTH 	= 320,		///< ͨ�����������
	MD_REGION_ROW		= 32,		///< �����������
	MAX_EXTRA_STREAM_TYPE = 3,		///< ����������
	MAX_COVER_COUNT		= 8,		///< ��󸲸�������
	CHANNEL_NAME_MAX_LEN = 64,		///< ͨ��������󳤶�
	N_COLOR_SECTION		= 2,		///< ��Ƶ��ɫʱ�����
	MAX_DRIVER_PER_DISK = 2,		///< ÿ���������ķ�����
	MAX_DISK_PER_MACHINE = 8,		///< ���֧��8��Ӳ��
	MAX_AP_NUMBER		= 32,		///< ���AP�ڵ����
	MAX_SPOT_NUMBER		= 4,		///<����SPOT�ӿ���
	MAX_DEV_DEC_CHNS	= (N_PLY_CH+N_DECORDR_CH),
	MAX_RECIVE_MSG_PHONE_COUNT = 3, ///<���֧�ֵ����ڽ��ձ�����ʾ��Ϣ���ֻ���Ŀ
	MAX_CAR_INFO_WIDTH  = 24,       ///<������Ϣ�����ռ�õ��ֽ���
	MAX_LINE_PER_OSD_AREA   = 6,    ///<������һ��OSD������������ʾ���ַ�����
};

/// ����
enum WeekDays
{
	WEEK_DAY_SUNDAY,		///< ������
	WEEK_DAY_MONDAY,
	WEEK_DAY_TUESDAY,
	WEEK_DAY_WEDNESDAY,	
	WEEK_DAY_THRUSDAY,
	WEEK_DAY_FRIDAY,
	WEEK_DAY_SATURDAY,
	WEEK_DAY_NR,	
};

#define RELATIVE_MAX_X 0x7FF
#define RELATIVE_MAX_Y 0x7FF

//Ӧ�ó����¼�
typedef enum app_event_action
{
	appEventStart = 0,		// �¼���ʼ
	appEventStop,			// �¼�����
	appEventConfig,			// �¼����ñ仯������Ϊ���ղ���
	appEventLatch,			// �¼���ʱ����������Ϊ�������
	appEventPulse,			// �����¼���û�п�ʼ�ͽ���
}appEventAction;

//thread priority fifo 0-29
#define TP_COM			 1		//1
#define TP_TIMER		 2		//1
#define TP_ALARM		 3		//1
#define TP_PLAY			 4		//4

#define TP_REC			 6
#define TP_CAPTURE	20		//16
#define TP_MEDIAFILE		24		//1
#define TP_GUI			25		//1
#define TP_PTZ			26

//thread priority other 30-99
#define TP_SMTP     30
#define WATCH_DOG   31

#define TP_BACKUP		35		//1
#define TP_SVR			37		//2
#define TP_NET			39		//16
#define TP_TEL			55		//1
#define TP_FRONTBOARD	56		//1
#define TP_MOUSE		57		//1
#define TP_FTP			58
#define TP_WEB          58
#define TP_DEFAULT		64
#define TP_PRE			 127

enum fmt_time_flag{
	FT_NORMAL = 0,
	FT_HALF_YEAR = 0x0001,
	FT_NO_SECOND = 0x0002,
	FT_NO_SIGNS  = 0x0004,
	FT_ONLY_DATE = 0x0008,
	FT_ONLY_TIME = 0x0010,
	FT_FULL_AMPM = 0x0020
};

enum LanguageTypes
{
	ENGLISH,		//Ӣ��
	CHINESE_S,		//��������
	CHINESE_T,		//��������
	ITALIAN,		//�������
	SPANISH,		//��������
	JAPANESE,		//����
	RUSSIAN,		//����
	FRENCH,			//����
	GERMAN,			//����
	PORTUGAL,		//��������
	TURKEY,			//��������
	POLAND,			//������
	ROMANIAN,       //��������
	HUNGARIAN,      //��������
	FINNISH,		//������
	ESTONIAN,	    //��ɳ������
	KOREAN,		    //����
	FARSI,          //��˹�� 
	DANSK,			//������
	THAI,			//̩����
	GREEK,			//ϣ����
	VIETNAMESE,		//Խ����
	UKRAINIAN,      //�ڿ�����
	BRAZILIAN,      //������
	HEBREW,         //ϣ������
	INDONESIAN,     //ӡ����
	ARABIC,         //��������
	SWEDISH,        //�����
	CZECH,          //�ݿ���
	BULGARIAN,      //��������
	SLOVAKIA,		//˹�工����
	DUTCH,			//������
	SERBIAN,		//����ά����
	CROATIAN,		//���޵���
	LANG_NR
};

/// ģ������
enum ModuleErrorNumber
{
	ERROR_OK = 100,						///< ����
	ERROR_BEGIN_ACCOUNT = 201,			///< Manager��ʼ�����
	ERROR_BEGIN_NETCOMMON = 301,		///< ͨ�����翪ʼ�����
	ERROR_BEGIN_NETSERVICE = 401,		///< �������ʼ�����
	ERROR_BEGIN_NETOPERATION = 501,		///< ������ʼ�����
	ERROR_BEGIN_CONFIG = 601,			///< ���ò�����ʼ�����
	ERROR_BEGIN_ABILITY = 701,			///< ��������ش����
	ERROR_BEGIN_DEVINFO = 801,			///< �豸��Ϣ��ش����
};

// Join two variables
#define MACRO_JOIN( X, Y ) MACRO_DO_JOIN( X, Y )
#define MACRO_DO_JOIN( X, Y ) MACRO_DO_JOIN2(X,Y)
#define MACRO_DO_JOIN2( X, Y ) X##Y

#endif //__DVRDEF_H__
