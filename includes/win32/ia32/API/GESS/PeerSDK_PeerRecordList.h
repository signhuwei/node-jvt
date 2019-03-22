#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents the collection of recording segments.
*/
class PEERSDK_API PeerRecordList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>PeerRecordList</b> class.
    */
    PeerRecordList();
    //@}

private:
    ~PeerRecordList();

public:
    /**
    * @private
    */
    PeerResult Initialize(_R* peer);

public:
    /** @name Methods
    */
    //@{

    /**
    * Get days in the month which has any recording segment.
    * @param [in] year     The year (1970 through 2038).
    * @param [in] month    The month (1 through 12).
    * @param [out] result  The days has any recording segment.
    * @return  A value that represents the error.
    */
    PeerResult GetRecordedDaysOfMonth(int32 year, int32 month, IntList& result);

    /**
    * Get minutes in the date which has recording segment.
    * @param [in] year     The year (1970 through 2038).
    * @param [in] month    The month (1 through 12).
    * @param [in] day      The day (1 through the number of days in <i>month</i>.
    * @param [out] result  The minutes has recording segment.
    * @return  A value that represents the error.
    */
    PeerResult GetRecordedMinutesOfDay(int32 year, int32 month, int32 day, TimeSpanList& result);

    /**
    * Get all recording segments.
    * @param [out] result  The segment list.
    * @return  A value that represents the error.
    */
    PeerResult GetList(TimeRangeList& result);

    /**
    * Delete the <b>PeerRecordList</b> instance.
    * @return  A value that represents the error.
    */
    PeerResult Dispose();
    //@}
};
