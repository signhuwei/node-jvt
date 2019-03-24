//
//  "$Id: Time.h 734 2010-07-12 01:14:00Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_TIME_H__
#define __INFRA_TIME_H__

#include "Types.h"
#include <string>

struct TimeSection
{
	int enable;
	int startHour;
	int	startMinute;
	int	startSecond;
	int	endHour;
	int	endMinute;
	int	endSecond;
};

/// ϵͳʱ��ṹ,��Ҫ��SYSTEM_TIME����һ��
struct SystemTime
{
	int  year;		///< �ꡣ   
	int  month;		///< �£�January = 1, February = 2, and so on.   
	int  day;		///< �ա�   
	int  wday;		///< ���ڣ�Sunday = 0, Monday = 1, and so on   
	int  hour;		///< ʱ��   
	int  minute;	///< �֡�   
	int  second;	///< �롣   
	int  isdst;		///< ����ʱ��ʶ��   
};

#ifndef __SMALL_FILE_TIME_DEFINED__
#define __SMALL_FILE_TIME_DEFINED__
// ʱ��ṹ
typedef struct _DATETIME								
{
#ifdef __BIG_ENDIAN__
	uint year		:6;				//	��	2000-2063	
	uint month		:4;				//	��	1-12		
	uint day		:5;				//	��	1-31		
	uint hour		:5;				//	ʱ	0-23		
	uint minute		:6;				//	��	0-59		
	uint second		:6;				//	��	0-59	
#else
	uint second		:6;				//	��	0-59		
	uint minute		:6;				//	��	0-59		
	uint hour		:5;				//	ʱ	0-23		
	uint day		:5;				//	��	1-31		
	uint month		:4;				//	��	1-12		
	uint year		:6;				//	��	2000-2063	
#endif
} DateTime,*pDATETIME;
#endif

#ifdef WIN32
/// ���ڸ�ʽ
enum DateFormat
{
	DF_YYMMDD = 0,		///< �� �� ��
	DF_MMDDYY,			///< �� �� ��
	DF_DDMMYY			///< �� �� ��
};

/// ʱ���˹
enum TimeFormat
{
	TF_24	= 0,		///< 24Сʱ
	TF_12				///< 12Сʱ
};

/// ���ڷָ���
enum DateSpliter
{
	DS_DOT	= 0,		//��ָ�ʽ
	DS_DASH,			//�ָܷ�ʽ
	DS_SLASH			//б�߸�ʽ
};

/// ʱ���ʽ������
enum TimeFormatType
{
	fmtNormal = 0,
	fmtHalfYear = 0x0001,
	fmtNoSecond = 0x0002,
	fmtNoSign  = 0x0004,
	fmtOnlyDate = 0x0008,
	fmtOnlyTime = 0x0010,
	fmtFullAMPM = 0x0020
};
#else

/// \brief ʱ������װ
/// 
class CTime : public SystemTime
{
public:

	/// ���ڸ�ʽ
	enum DateFormat
	{
		DF_YYMMDD = 0,		///< �� �� ��
		DF_MMDDYY,			///< �� �� ��
		DF_DDMMYY			///< �� �� ��
	};

	/// ʱ���˹
	enum TimeFormat
	{
		TF_24	= 0,		///< 24Сʱ
		TF_12				///< 12Сʱ
	};

	/// ���ڷָ���
	enum DateSpliter
	{
		DS_DOT	= 0,		//��ָ�ʽ
		DS_DASH,			//�ָܷ�ʽ
		DS_SLASH			//б�߸�ʽ
	};

	/// ʱ���ʽ������
	enum TimeFormatType
	{
		fmtNormal = 0,
		fmtHalfYear = 0x0001,
		fmtNoSecond = 0x0002,
		fmtNoSign  = 0x0004,
		fmtOnlyDate = 0x0008,
		fmtOnlyTime = 0x0010,
		fmtFullAMPM = 0x0020
	};

	/// Ĭ�Ϲ��캯��
	CTime();

	/// ��ͨʱ�乹�캯��
	CTime(const SystemTime &time);

	/// ��ͨʱ�乹�캯��
	CTime( int vyear, int vmonth, int vday, int vhour, int vmin, int vsec);

	/// ʱ�����
	/// \param seconds ���ڵ�����
	/// \return ���ں��µ�ʱ�����
	CTime operator +(int64 seconds ) const;

	/// ʱ�����
	/// \param seconds ���ڵ�����
	/// \return ���ں��µ�ʱ�����
	CTime operator -(int64 seconds ) const;

	/// ʱ�����
	/// \param seconds ���ڵ�����
	/// \return ������
	CTime& operator +=(int64 seconds );

	/// ʱ�����
	/// \param seconds ���ڵ�����
	/// \return ������
	CTime& operator -=(int64 seconds );
	
	/// ʱ�������
	/// \param time ��Ƚϵ�ʱ��
	/// \return �ȽϵĽ����Ϊ(*this - time)�õ�������
	int64 operator -(const CTime& time ) const;

	/// ʱ��Ƚ�
	/// \param time ��Ƚϵ�ʱ��
	/// \return ��ȷ���true�����򷵻�false
	bool operator == (const CTime& time) const;

	/// ʱ��Ƚ�
	/// \param time ��Ƚϵ�ʱ��
	/// \return ���ȷ���true�����򷵻�false
	bool operator != (const CTime& time) const;

	/// ʱ��Ƚ�
	/// \param time ��Ƚϵ�ʱ��
	/// \return <����true�����򷵻�false
	bool operator < (const CTime& time) const;

	/// ʱ��Ƚ�
	/// \param time ��Ƚϵ�ʱ��
	/// \return <=����true�����򷵻�false
	bool operator <= (const CTime& time) const;

	/// ʱ��Ƚ�
	/// \param time ��Ƚϵ�ʱ��
	/// \return >����true�����򷵻�false
	bool operator > (const CTime& time) const;

	/// ʱ��Ƚ�
	/// \param time ��Ƚϵ�ʱ��
	/// \return >=����true�����򷵻�false
	bool operator >= (const CTime& time) const;

	/// ʱ�丳ֵ
	CTime& operator = (const CTime& time);

	/// �õ����ʱ�䣬���ʱ��ָ��1900-1-1 00:00:00��ĳ��ʱ�̾���������
	/// \return ���ʱ��
	time_t makeTime() const;

	/// �����ʱ��õ�����ʱ�䣬��maketime���Ӧ
	void breakTime(uint64 time);

	/// ʱ���ʽ�����
	std::string format(uint format = fmtNormal) const;

	/// ��ȡ��ǰϵͳʱ��
	static CTime getCurrentTime();

	/// �õ���ǰϵͳʱ�䡣����������ܵ��õĺ�Ƶ��, ���е���ʱӦ���Ǵ��ڴ���ȡ��
	/// ʱ��,������ֱ�Ӵ�Ӳ��, �ڶ�ʱ��������ڴ��е�ֵ.
	/// \retval true  �ɹ�
	/// \retval false ʧ��
	static bool getCurrentTime(SystemTime &time);

	/// ���õ�ǰϵͳʱ��
	static void setCurrentTime(const CTime &time);

	/// ���õ�ǰϵͳʱ��
	static void setCurrentTime(SystemTime &time);

	/// �õ�ϵͳ�ĺ�����������ε���֮��ļ��ʱ����ǵõ��ļ����Ĳ�ֵ��
	/// 
	/// \param ��
	/// \return ��ǰ������
	/// \note һ������£�49.7���õ������������ʹ�õ��ĵط�Ҫ���������
	static uint64 getCurrentMicroSecond();

	/// ��ȡ��ǰϵͳʱ���΢����
	static uint64 getCurrentMillSecond();

	/// ���ߺ�����
	static void sleep(int millsecond);

	//// ����ϵͳʱ���ʽ
	/// \param [in] dateFormat ���ڸ�ʽ
	/// \param [in] timeFormat ʱ���ʽ
	static void setTimeFormat(int dataFormat, int timeFormat, int timeSpliter);

	/// ��ȡϵͳʱ���ʽ
	static int getDateFormat();

	/// ��ȡ��ǰʱ���ʽ
	static int getTimeFormat();

	/// ��ȡʱ��ָ��
	static int getTimeSpliter();

	/// �õ�ָ���·ݵ�����
	static int getDaysOfMonth(int year,int month);

	static int hour12To24(int hour12, int ampm);

	static int hour24To12(int hour24);

	static int hour24ToAMPM(int hour24);

	static bool isLeapYear(int year);

public:
	const static CTime minTime;		///< ϵͳ��Сʱ��
	const static CTime maxTime;		///< ϵͳ���ʱ��

private:
	static int sm_dateFormat;
	static int sm_timeFormat;
	static int sm_timeSpliter;
};

#endif

void FormatTimeString(SystemTime *p,char* buf,int flag);
void FormatTimeStringDate(DateTime *p,char* buf,int flag);
void TimeDate2Sys(SystemTime * systime, DateTime * dateTime);
void TimeSys2Date(DateTime * dateTime, SystemTime * systime);
int TimeCompare(SystemTime * pSysTime1, SystemTime * pSysTime2);
void TimeAdd(SystemTime * pOldTime, SystemTime * pNewTime, int second);
int Time2Second(SystemTime * pSysTime1, SystemTime * pSysTime2);
int GetCurDateTime(DateTime* ptime);
void ClearDateTime(DateTime *ptime);
uint IsZeroDateTime(DateTime t);
int CompareDateTime(DateTime t1,DateTime t2);
int DateTimeToDay(DateTime t);
int DateTimeToSecond(DateTime t);
DateTime SecondToDateTime(int second);
int DateTimeChangeSecond(DateTime end_time, DateTime start_time);
int CompareDateTime(DateTime t,DateTime t1,DateTime t2);
DateTime AddDateTime(DateTime time, int second);

#endif