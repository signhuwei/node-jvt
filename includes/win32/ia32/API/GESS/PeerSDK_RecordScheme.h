#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>RecordScheme</b>.
*/
class PEERSDK_API RecordScheme
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a <b>RecordScheme</b> instance.
    */
    RecordScheme();

    /**
    * Initializes a new instance of the <b>RecordScheme</b> class with specified <b>RecordScheme</b> object.
    * @param [in] value  The <b>RecordScheme</b> instance.
    */
    RecordScheme(RecordScheme const& value);

    /**
    * Destroyed the <b>RecordScheme</b> instance.
    */
    ~RecordScheme();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the list of channel scheme list in the scheme.
    */
    ChannelSchemeList Channels();
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>RecordScheme</b> with a copy of another <b>RecordScheme</b>.
    */
    RecordScheme& operator=(RecordScheme const& value);
    //@}
};
