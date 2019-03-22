#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents errors that occur during application execution.
*/
class PEERSDK_API DiscoveryService
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>PeerResult</b> class.
    */
    DiscoveryService();

    /**
    * Destroyed the <b>PeerResult</b> instance.
    */
    ~DiscoveryService();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Send discovery probe message.
    * @return  A value that represents the error.
    */
    PeerResult Start();

    /**
    * Send discovery probe message.
    * @return  A value that represents the error.
    */
    PeerResult Probe(IPAddress const& ip, QName const& type);
    //@}

    /**
    * Send discovery probe message.
    * @return  A value that represents the error.
    */
    PeerResult ProbeIPCam(IPAddress const& ip);
    //@}

public:
    /** @name Events
    */
    //@{

    /**
    * Occurs when error.
    */
    DiscoveryMatchEvent& DiscoveryMatch();
    //@}
};
