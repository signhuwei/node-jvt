#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents the video/audio streaming of remote device.
*/
class PEERSDK_API PeerStream
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerStream();
    //@}

private:
    ~PeerStream();

public:
    /** @name Methods
    */
    //@{

    /**
    * @private
    */
    PeerResult Initialize(_R* peer);

    /**
    * @private
    */
    PeerResult Initialize(_R* peer, _R const& start);

    /**
    * @private
    */
    PeerResult Initialize(_R* peer, _R const& start, _R const& end);
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Start to receive streaming
    * @return  A value that represents the error.
    */
    PeerResult Start();

    /**
    * Create a stream for backup.
    * @param [in]  active  Active stream (0 through Available - 1).
    * @return  A value that represents the error.
    */
    PeerResult SetActive(int32 active);

    /**
    * Set video/audio bit mask of the streaming.
    * @param [in]  videoMask    Start time of the recording segment.
    * @param [in]  audioMask    End time of the recording segment.
    * @return  A value that represents the error.
    */
    PeerResult SetChannelMask(uint32 videoMask, uint32 audioMask);

    /**
    * Play with normal speed (1.0).
    * @return  A value that represents the error.
    */
    PeerResult Play();

    /**
    * Pause the playback.
    * @return  A value that represents the error.
    */
    PeerResult Pause();

    /**
    * Play next video frame.
    * @return  A value that represents the error.
    */
    PeerResult Step();

    /**
    * Seek to specific time.
    * @param [in]  time  Time.
    * @return  A value that represents the error.
    */
    PeerResult Seek(DateTime const& time);

    /**
    * Set playback speed.
    * @param [in]  speed  Playback speed (1.0 is 1x speed, negative speed to rewind).
    * @return  A value that represents the error.
    */
    PeerResult SetSpeed(double speed);

    /**
    * Calculate backup required space.
    * @param [in]  space  Required space (bytes).
    * @return  A value that represents the error.
    */
    PeerResult CalculateRequiredSpace(int64& space);

    /**
    * Set stream download speed limit.
    * @param [in]  limit  Network download limit (bytes); 0 represents unlimit speed.
    * @return  A value that represents the error.
    */
    PeerResult SetDownloadLimit(int64 limit);

    /**
    * Delete the <b>PeerStream</b> instance.
    * @return  A value that represents the error.
    */
    PeerResult Dispose();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets available stream number.
    */
    int32 Available() const;

    /**
    * Gets current active stream (0 through Available - 1).
    */
    int32 Active() const;

    /**
    * Gets a value that indicates whether the stream support seek capacity.
    */
    bool CanSeek() const;

public:
    /**
    * Gets current playback speed.
    */
    double Speed() const;

    /**
    * Gets current download limit.
    */
    int64 DownloadLimit() const;

    /**
    * Gets current download speed rate (in bytes).
    */
    int64 DownloadRate() const;

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
    * Occurs when receive a video frame.
    */
    VideoArrivedEvent& VideoArrived();

    /**
    * Occurs when receive audio samples.
    */
    AudioArrivedEvent& AudioArrived();

    /**
    * Occurs when backup progress has changed.
    */
    ProgressChangedEvent& BackupProgressChanged();

    /**
    * Occurs when end of streaming.
    */
    CompletedEvent& Completed();
    //@}
};
