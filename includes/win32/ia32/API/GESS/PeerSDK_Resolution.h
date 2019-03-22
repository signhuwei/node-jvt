#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>Resolution</b>.
*/
class PEERSDK_API Resolution
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a <b>Resolution</b> instance.
    */
    Resolution();

    /**
    * Initializes a new instance of the <b>Resolution</b> class with specified <b>Resolution</b> object.
    * @param [in] value  The <b>Resolution</b> instance.
    */
    Resolution(Resolution const& value);

    /**
    * Destroyed the <b>Resolution</b> instance.
    */
    ~Resolution();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the width.
    */
    int32 Width() const;

    /**
    * Gets the height.
    */
    int32 Height() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>Resolution</b> with a copy of another <b>Resolution</b>.
    */
    Resolution& operator=(Resolution const& value);
    //@}
};
