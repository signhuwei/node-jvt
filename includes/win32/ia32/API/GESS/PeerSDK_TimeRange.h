#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a range of time.
*/
class PEERSDK_API TimeRange
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>TimeRange</b> class.
    */
    TimeRange();

    /**
    * Initializes a new instance of the <b>TimeRange</b> class with specified <b>TimeRange</b> object.
    * @param [in] value  The <b>TimeRange</b> instance.
    */
    TimeRange(TimeRange const& value);
    
    /**
    * Destroyed the <b>TimeRange</b> instance.
    */
    ~TimeRange();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the begin time in the <b>TimeRange</b>.
    */
    DateTime Begin() const;

    /**
    * Gets the end time in the <b>TimeRange</b>.
    */
    DateTime End() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>TimeRange</b> with a copy of another <b>TimeRange</b>.
    */
    TimeRange& operator=(TimeRange const& value);
    //@}
};
