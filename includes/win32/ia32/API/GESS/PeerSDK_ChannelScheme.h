#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a record scheme of a channel.
*/
class PEERSDK_API ChannelScheme
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    ChannelScheme(_R& channel);

    /**
    * @private
    */
    ChannelScheme(ChannelScheme const& value);
    
    /**
    * Destroyed the <b>ChannelScheme</b> instance.
    */
    ~ChannelScheme();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * 
    */
    PeerResult DisableRegularRecord();

    /**
    * 
    */
    PeerResult EnableRegularRecord(Resolution resolution, int32 fps, double quality, bool recordAudio);

    /**
    * 
    */
    PeerResult DisableEventRecord();

    /**
    * 
    */
    PeerResult EnableEventRecord(Resolution resolution, int32 fps, double quality, int32 preAlarm, int32 postAlarm, bool recordAudio);
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * 
    */
    bool RegularRecordEnabled() const;

    /**
    * 
    */
    Resolution RegularResolution() const;

    /**
    * 
    */
    int32 RegularFPS() const;

    /**
    * 
    */
    double RegularQuality() const;

    /**
    * 
    */
    bool RegularRecordAudio() const;

    /**
    * 
    */
    bool EventRecordEnabled() const;

    /**
    * 
    */
    Resolution EventResolution() const;

    /**
    * 
    */
    int32 EventFPS() const;

    /**
    * 
    */
    double EventQuality() const;

    /**
    * 
    */
    int32 EventPreAlarm() const;

    /**
    * 
    */
    int32 EventPostAlarm() const;

    /**
    * 
    */
    bool EventRecordAudio() const;

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>ChannelScheme</b> with a copy of another <b>ChannelScheme</b>.
    */
    ChannelScheme& operator=(ChannelScheme const& value);
    //@}
};
