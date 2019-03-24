#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Contains state information and event data associated with a <b>VideoLossChangedEvent</b> event.
*/
class PEERSDK_API VideoLossChangedEventArgs
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    VideoLossChangedEventArgs(_R const& e);

    /**
    * @private
    */
    ~VideoLossChangedEventArgs();
    //@}

public:
     /** @name Properties
    */
    //@{

    /**
    * Gets channels that video is from non-video-loss to video-loss state.
    */
    IntList const& Active() const;

    /**
    * Gets channels that video is from video-loss to non-video-loss state.
    */
    IntList const& Deactive() const;
    //@}
};
