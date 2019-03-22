#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents relay switch.
*/
class PEERSDK_API PeerRelay
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerRelay(_R* peer, int32 index);

    /**
    * @private
    */
    ~PeerRelay();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Turn on relay in seconds.
    * @param [in]  seconds  Seconds.
    * @return  A value that represents the error.
    */
    PeerResult Activate(int32 seconds);

    /**
    * Change the relay pole.
    * @param [in]  pole  Relay pole.
    * @return  A value that represents the error.
    */
    PeerResult Switch(RelayPole pole);
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets current relay pole.
    */
    RelayPole Pole() const;
    //@}
};
