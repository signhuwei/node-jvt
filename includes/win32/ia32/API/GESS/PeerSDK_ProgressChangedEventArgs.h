#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Contains state information and event data associated with a <b>ProgressChangedEvent</b> event.
*/
class PEERSDK_API ProgressChangedEventArgs
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    ProgressChangedEventArgs(_R const& e);

    /**
    * @private
    */
    ~ProgressChangedEventArgs();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the progress percentage.
    */
    int32 Percentage() const;
    //@}
};
