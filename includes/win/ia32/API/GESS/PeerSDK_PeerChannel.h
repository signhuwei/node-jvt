#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents the channel of peers.
*/
class PEERSDK_API PeerChannel
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerChannel(_R* peer, int32 index);

    /**
    * @private
    */
    ~PeerChannel();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the channel index.
    */
    int32 Index() const;

public:
    /**
    * Gets the channel name.
    */
    String Name() const;

public:
    /**
    * Gets the associated video.
    */
    PeerVideo* Video() const;

    /**
    * Gets the associated audio.
    */
    PeerAudio* Audio() const;
    //@}
};
