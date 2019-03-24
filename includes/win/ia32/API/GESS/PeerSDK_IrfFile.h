#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Specifies type of IRF file frame.
*/
enum IrfFrameType
{
    /**
    * Indicates non-IRF data.
    */
    IrfFrameType_None = 0,

    /**
    * Indicates video.
    */
    IrfFrameType_Video = 1,

    /**
    * Indicates audio.
    */
    IrfFrameType_Audio = 2,

    /**
    * Indicates IRF EOF.
    */
    IrfFrameType_EOF = 3,
};

/**
* @brief Represents an IRF file.
*/
class PEERSDK_API IrfFile
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>IrfFile</b> class.
    */
    IrfFile();
    /**
    * Destroyed the <b>IrfFile</b> instance.
    */
    ~IrfFile();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Opens an IRF file.
    * @param [in] path     The name of the file.
    * @return  A value that represents the error.
    */
    PeerResult Open(String const& path);

    /**
    * Closes the file currently in use.
    * @return  A value that represents the error.
    */
    PeerResult Close();

    /**
    * 
    * @return  A value that represents the error.
    */
    PeerResult CheckNextFrameType(IrfFrameType& type);

    /**
    * 
    * @return  A value that represents the error.
    */
    PeerResult GetNextVideoFrame(IrfVideoFrame& frame);

    /**
    * 
    * @return  A value that represents the error.
    */
    PeerResult GetNextAudioFrame(IrfAudioFrame& frame);
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the version of this IRF file.
    */
    int32 Version() const;

    /**
    * Gets count of video channel of this IRF file.
    */
    int32 VideoCount() const;

    /**
    * Gets count of audio channel of this IRF file.
    */
    int32 AudioCount() const;

public:
    /**
    * Gets all name of channel of this IRF file.
    */
    StringList ChannelNames() const;
    //@}
};
