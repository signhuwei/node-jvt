#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>TimeSpan</b> list of objects that can be accessed by index.
*/
class PEERSDK_API TimeSpanList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>TimeSpanList</b> class.
    */
    TimeSpanList();

    /**
    * Initializes a new instance of the <b>TimeSpanList</b> class with specified <b>TimeSpanList</b> object.
    * @param [in] value  The <b>TimeSpanList</b> instance.
    */
    TimeSpanList(TimeSpanList const& value);

    /**
    * Destroyed the <b>TimeSpanList</b> instance.
    */
    ~TimeSpanList();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>TimeSpanList</b>.
    */
    int32 Count() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>TimeSpanList</b> with a copy of another <b>TimeSpanList</b>.
    */
    TimeSpanList& operator=(TimeSpanList const& value);

    /**
    * Returns a reference in the <b>TimeSpanList</b> element at a specified position.
    */
    TimeSpan const& operator[](int32 index) const;
    //@}
};
