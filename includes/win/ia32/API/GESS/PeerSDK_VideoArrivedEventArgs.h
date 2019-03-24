#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Contains state information and event data associated with a <b>VideoArrivedEvent</b> event.
*/
class PEERSDK_API VideoArrivedEventArgs
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    VideoArrivedEventArgs(_R const& e);

    /**
    * @private
    */
    ~VideoArrivedEventArgs();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets type of video frame.
    */
    VideoType Type() const;

    /**
    * Gets channel id of video frame.
    */
    int32 Channel() const;

    /**
    * Gets length of video frame.
    */
    int32 BufferLength() const;

    /**
    * Gets a pointer to a buffer containing video frame.
    */
    byte const* Buffer() const;

    /**
    * Gets PTS of video frame.
    */
    int64 PTS() const;

    /**
    * Gets time of video frame.
    */
    DateTime Time() const;

    /**
    * Gets width of video image.
    */
    int32 Width() const;

    /**
    * Gets height of video image.
    */
    int32 Height() const;
    //@}
};
