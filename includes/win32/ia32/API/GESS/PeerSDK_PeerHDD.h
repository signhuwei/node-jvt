#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a HDD of peer device.
*/
class PEERSDK_API PeerHDD
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerHDD();

    /**
    * @private
    */
    PeerHDD(PeerHDD const& value);

    /**
    * @private
    */
    ~PeerHDD();
    //@}

public:
    /**
    * @private
    */
    PeerResult Initialize(_R* peer, int32 index);

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets total capacity of the HDD.
    */
    int64 Capacity() const;

    /**
    * Gets available capacity of the HDD.
    */
    int64 Available() const;

public:
    /** @name Operators
    */
    //@{

    /**
    * @private
    */
    PeerHDD& operator=(PeerHDD const& value);
    //@}
};
