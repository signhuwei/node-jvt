#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents an DVR/surveillance device.
*/
class PEERSDK_API Peer
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>Peer</b> class.
    */
    Peer();
    /**
    * Destroyed the <b>Peer</b> instance.
    */
    ~Peer();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Connect to remote device.
    * @param [in] host       The IP address of the remote host.
    * @param [in] port       The port number of the remote host.
    * @param [in] user       Login user name.
    * @param [in] password   Password.
    * @param [in] type       Connect to some kind of DVR/surveillance device.
    * @param [in] tryOthers  Try to connect other kinds of DVR/surveillance if <i>type</i> can't connect.
    * @return  A value that represents the error.
    */
    PeerResult Connect(String const& host, int32 port, String const& user, String const& password, String const& type, bool tryOthers);

    /**
    * Create a stream for live view.
    * @param [out] result   New stream for live view.
    * @return  A value that represents the error.
    */
    PeerResult CreateLiveStream(PeerStream** result);

    /**
    * Create a stream for playback.
    * @param [in]  start    The start time to play.
    * @param [out] result   New stream for playback.
    * @return  A value that represents the error.
    */
    PeerResult CreateRecordedStream(DateTime const& start, PeerStream** result);

    /**
    * Create a stream for backup.
    * @param [in]  start    Start time of the recording segment.
    * @param [in]  end      End time of the recording segment.
    * @param [out] result   New stream for backup.
    * @return  A value that represents the error.
    */
    PeerResult CreateRecordedStream(DateTime const& start, DateTime const& end, PeerStream** result);

    /**
    * Create <b>PeerRecordList</b> instance.
    * @param [out] result   New <b>PeerRecordList</b> instance.
    * @return  A value that represents the error.
    */
    PeerResult CreateRecordList(PeerRecordList** result);

    /**
    * Get all system logs.
    * @param [out] list   The system logs collection.
    * @return  A value that represents the error.
    */
    PeerResult GetLogList(PeerLogList& list);

    /**
    * Get current HDD list.
    * @param [out] list   The HDD collection.
    * @return  A value that represents the error.
    */
    PeerResult GetHDDList(PeerHDDList& list);

    /**
    * Send an ack command to test connection status.
    * @return  A value that represents the error.
    */
    PeerResult Ack();

public:
    /**
    * Create a stream for live view.
    * @param [in]  detection   The video format detect method.
    * @param [out] available   The method is available or not.
    * @return  A value that represents the error.
    */
    PeerResult IsAvailableVideoFormatDetection(VideoFormatDetection detection, bool& available);

    /**
    * Create a stream for live view.
    * @param [in]  detection   How to detect source video format.
    * @return  A value that represents the error.
    */
    PeerResult SetVideoFormatDetectMethod(VideoFormatDetection detection);
    //@}

public:
    /** @name Static Methods
    */
    //@{

    /**
    * Initialize Peer SDK.
    * @return  A value that represents the error.
    */
    static PeerResult Startup();

    /**
    * Shutdown Peer SDK.
    * @return  A value that represents the error.
    */
    static PeerResult Cleanup();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets type of remote device.
    */
    String Type() const;

public:
    /**
    * Gets current video format detect method.
    */
    VideoFormatDetection VideoFormatDetectMethod();

    /**
    * Gets output video format.
    */
    VideoFormat OutputVideoFormat();

public:
    /**
    * Gets the list of channels in the device.
    */
    ChannelCollection& Channels() const;

    /**
    * Gets the list of relays in the device.
    */
    RelayCollection& Relays() const;

    /**
    * Gets the recorder.
    */
    PeerRecorder* Recorder() const;

    /**
    * Gets the scheduler.
    */
    PeerScheduler* Scheduler() const;
    //@}

public:
    /** @name Events
    */
    //@{

    /**
    * Occurs when error.
    */
    ErrorOccurredEvent& ErrorOccurred();

    /**
    * Occurs when video loss status changed.
    */
    VideoLossChangedEvent& VideoLossChanged();

    /**
    * Occurs when video motion status changed.
    */
    VideoMotionChangedEvent& VideoMotionChanged();

    /**
    * Occurs when record status of a channel changed.
    */
    RecordStatusChangedEvent& RecordStatusChanged();
    //@}
};
