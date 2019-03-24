#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>TimeRange</b> list of objects that can be accessed by index.
*/
class PEERSDK_API TimeRangeList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>TimeRangeList</b> class.
    */
    TimeRangeList();

    /**
    * Initializes a new instance of the <b>TimeRangeList</b> class with specified <b>TimeRangeList</b> object.
    * @param [in] value  The <b>TimeRangeList</b> instance.
    */
    TimeRangeList(TimeRangeList const& value);
    
    /**
    * Destroyed the <b>TimeRangeList</b> instance.
    */
    ~TimeRangeList();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>TimeRangeList</b>.
    */
    int32 Count() const;

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>TimeRangeList</b> with a copy of another <b>TimeRangeList</b>.
    */
    TimeRangeList& operator=(TimeRangeList const& value);

    /**
    * Returns a reference in the <b>TimeRangeList</b> element at a specified position.
    */
    TimeRange const& operator[](int32 index) const;
    //@}
};
