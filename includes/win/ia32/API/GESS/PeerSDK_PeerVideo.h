#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents the attached video of channels.
*/
class PEERSDK_API PeerVideo
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerVideo(_R* peer, int32 index);

    /**
    * @private
    */
    ~PeerVideo();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Set video sharpness.
    * @param [in] value    Sharpness (0 through 1.0).
    * @return  A value that represents the error.
    */
    PeerResult SetSharpness(double value);

    /**
    * Set video brightness.
    * @param [in] value    Brightness (0 through 1.0).
    * @return  A value that represents the error.
    */
    PeerResult SetBrightness(double value);

    /**
    * Set video contrast.
    * @param [in] value    Contrast (0 through 1.0).
    * @return  A value that represents the error.
    */
    PeerResult SetContrast(double value);

    /**
    * Set video saturation.
    * @param [in] value    Saturation (0 through 1.0).
    * @return  A value that represents the error.
    */
    PeerResult SetSaturation(double value);

    /**
    * Set video hue.
    * @param [in] value    Hue (0 through 1.0).
    * @return  A value that represents the error.
    */
    PeerResult SetHue(double value);
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the associated PTZ.
    */
    PeerPTZ* PTZ() const;
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Check video is loss or not.
    */
    bool IsLoss() const;

    /**
    * Check video is motion or not.
    */
    bool IsMotion() const;

public:
    /**
    * Get source video format.
    */
    VideoFormat Format() const;

public:
    /**
    * Get source video sharpness (0 through 1.0).
    */
    double Sharpness() const;

    /**
    * Get source video brightness (0 through 1.0).
    */
    double Brightness() const;

    /**
    * Get source video contrast (0 through 1.0).
    */
    double Contrast() const;

    /**
    * Get source video saturation (0 through 1.0).
    */
    double Saturation() const;

    /**
    * Get source video hue (0 through 1.0).
    */
    double Hue() const;
    //@}
};
