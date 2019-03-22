#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Contains state information and event data associated with a <b>AudioArrivedEvent</b> event.
*/
class PEERSDK_API AudioArrivedEventArgs
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    AudioArrivedEventArgs(_R const& e);

    /**
    * @private
    */
    ~AudioArrivedEventArgs();
    //@}

public: // Properties
    /** @name Properties
    */
    //@{

    /**
    * Gets type of audio samples.
    */
    AudioType Type() const;

    /**
    * Gets channel id of audio samples.
    */
    int32 Channel() const;

    /**
    * Gets length of audio samples.
    */
    int32 BufferLength() const;

    /**
    * Gets a pointer to a buffer containing audio samples.
    */
    byte const* Buffer() const;

    /**
    * Gets PTS of audio samples.
    */
    int64 PTS() const;

    /**
    * Gets time of audio samples.
    */
    DateTime Time() const;
    //@}
};
