#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents the attached audio of channels.
*/
class PEERSDK_API PeerAudio
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerAudio(_R* peer, int32 index);

    /**
    * @private
    */
    ~PeerAudio();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets a value that indicates whether the audio is present.
    */
    bool IsPresent() const;
    //@}
};
