#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents the scheduler in DVR/peer.
*/
class PEERSDK_API PeerScheduler
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerScheduler(_R* peer);

    /**
    * @private
    */
    ~PeerScheduler();
    //@}
};
