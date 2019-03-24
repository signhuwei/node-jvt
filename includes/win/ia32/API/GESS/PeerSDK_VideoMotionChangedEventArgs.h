#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Contains state information and event data associated with a <b>VideoMotionChangedEvent</b> event.
*/
class PEERSDK_API VideoMotionChangedEventArgs
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    VideoMotionChangedEventArgs(_R const& e);

    /**
    * @private
    */
    ~VideoMotionChangedEventArgs();
    //@}

public:
     /** @name Properties
    */
    //@{

    /**
    * Gets channels that video is from non-motion to motion state.
    */
    IntList const& Active() const;

    /**
    * Gets channels that video is from motion to non-motion state.
    */
    IntList const& Deactive() const;
    //@}
};
