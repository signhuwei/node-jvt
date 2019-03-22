#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

class Peer;

/**
* @brief Represents an instant in time, typically expressed as a date and time of day for the specified <b>Peer</b>.
*/
class PEERSDK_API DateTime
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>DateTime</b> class.
    */
    DateTime();

    /**
    * Initializes a new instance of the <b>DateTime</b> class to the specified year, month, and day for the specified <b>Peer</b>.
    * @param [in] year   The year (1970 through 2038).
    * @param [in] month  The month (1 through 12).
    * @param [in] day    The day (1 through the number of days in <i>month</i>.
    * @param [in] peer   The <b>Peer</b> instance.
    */
    DateTime(int32 year, int32 month, int32 day, Peer* peer);

    /**
    * Initializes a new instance of the <b>DateTime</b> class to the specified year, month, day, hour, minute, and second for the specified <b>Peer</b>.
    * @param [in] year    The year (1970 through 2038).
    * @param [in] month   The month (1 through 12).
    * @param [in] day     The day (1 through the number of days in <i>month</i>.
    * @param [in] hour    The hours (0 through 23).
    * @param [in] minute  The minutes (0 through 59).
    * @param [in] second  The seconds (0 through 59).
    * @param [in] peer    The <b>Peer</b> instance.
    */
    DateTime(int32 year, int32 month, int32 day, int32 hour, int32 minute, int32 second, Peer* peer);

    /**
    * Initializes a new instance of the <b>DateTime</b> class with specified <b>DateTime</b> object.
    * @param [in] value  The <b>DateTime</b> instance.
    */
    DateTime(DateTime const& value);

    /**
    * Destroyed the <b>DateTime</b> instance.
    */
    ~DateTime();
    //@}
    
public:
    /** @name Methods
    */
    //@{

    /**
     * Returns a new <b>DateTime</b> object that is set to a given number of seconds.
     * @param [in]  seconds  Seconds.
     * @return  A new <b>DateTime</b> object that is set to seconds seconds.
     */
    DateTime Add(int32 seconds);
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the time difference between the current time zone's standard time and UTC.
    */
    time_t Time() const;

    /**
    * Gets difference in seconds between local time and UTC.
    */
    time_t TZ() const;

    /**
    * Gets the bias in the number of seconds that daylight time for the specified time zone differs from UTC.
    */
    time_t DST() const;

public:
    /**
    * Gets the year component of the date represented by this instance.
    */
    int32 Year() const;

    /**
    * Gets the month component of the date represented by this instance.
    */
    int32 Month() const;

    /**
    * Gets the day of the month represented by this instance.
    */
    int32 Day() const;

    /**
    * Gets the hour component of the date represented by this instance.
    */
    int32 Hour() const;

    /**
    * Gets the minute component of the date represented by this instance.
    */
    int32 Minute() const;

    /**
    * Gets the seconds component of the date represented by this instance.
    */
    int32 Second() const;

    /**
    * Gets the day of the week represented by this instance.
    */
    int32 Weekday() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>DateTime</b> with a copy of another <b>DateTime</b>.
    */
    DateTime& operator=(DateTime const& value);
    //@}
};
