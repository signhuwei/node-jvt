#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Contains state information and event data associated with a <b>RecordStatusChangedEventArgs</b> event.
*/
class PEERSDK_API RecordStatusChangedEventArgs
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    RecordStatusChangedEventArgs(_R const& e);

    /**
    * @private
    */
    ~RecordStatusChangedEventArgs();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets id of changed channel.
    */
    int32 Channel() const;
    //@}
};
