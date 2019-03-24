#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Contains state information and event data associated with a <b>ErrorOccurredEvent</b> event.
*/
class PEERSDK_API ErrorOccurredEventArgs
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    ErrorOccurredEventArgs(_R const& e);

    /**
    * @private
    */
    ~ErrorOccurredEventArgs();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the error.
    */
    PeerResult Error() const;
    //@}
};
