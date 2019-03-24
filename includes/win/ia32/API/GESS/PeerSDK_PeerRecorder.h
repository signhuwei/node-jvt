#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents the encoder/recorder of source video and audio.
*/
class PEERSDK_API PeerRecorder
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerRecorder(_R* peer);

    /**
    * @private
    */
    ~PeerRecorder();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Enable or disable recorder.
    */
    PeerResult SetEnabled(bool enabled);

    /**
    * Set the scheme to change default recording setting.
    */
    PeerResult SetDefaultRecordScheme(RecordScheme const& scheme);

    /**
    * Get the resolutions which recorder supported.
    */
    PeerResult GetSupportedRecordResolutions(int32 channel, int32 stream, ResolutionList& resolutions);
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Get the recording status of every channel.
    */
    RecordingList RecordStatus() const;
    //@}

    /**
    * Get value indicating whether the recorder is enabled.
    */
    bool Enabled() const;

    /**
    * Get the default record setting scheme.
    */
    RecordScheme DefaultRecordScheme() const;
    //@}
};
