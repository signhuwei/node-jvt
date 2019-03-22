#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a time interval.
*/
class PEERSDK_API TimeSpan
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>TimeSpan</b> class.
    */
    TimeSpan();

    /**
    * Initializes a new instance of the <b>TimeSpan</b> class with specified <b>TimeSpan</b> object.
    * @param [in] value  The <b>TimeSpan</b> instance.
    */
    TimeSpan(TimeSpan const& value);

    /**
    * Destroyed the <b>TimeSpan</b> instance.
    */
    ~TimeSpan();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the hours component of the time interval represented by the current <b>TimeSpan</b> structure.
    */
    int32 Hours() const;

    /**
    * Gets the minutes component of the time interval represented by the current <b>TimeSpan</b> structure.
    */
    int32 Minutes() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>TimeSpan</b> with a copy of another <b>TimeSpan</b>.
    */
    TimeSpan& operator=(TimeSpan const& value);
    //@}
};
