#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Contains state information and event data associated with a <b>CompletedEvent</b> event.
*/
class PEERSDK_API CompletedEventArgs
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    CompletedEventArgs(_R const& e);

    /**
    * @private
    */
    ~CompletedEventArgs();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets a value that indicates the action is terminated by user.
    */
    bool IsTerminated() const;
    //@}
};
