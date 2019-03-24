#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents an DVR/surveillance device.
*/
class PEERSDK_API PeerHelper
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>PeerHelper</b> class.
    */
    PeerHelper();
    /**
    * Destroyed the <b>PeerHelper</b> instance.
    */
    ~PeerHelper();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Takes the peer system snapshot.
    * @return  A value that represents the error.
    */
    PeerResult GetSystemSnapshot(String const& host, int32 port, String const& user, String const& password, Memory& snapshot);
    //@}
};
