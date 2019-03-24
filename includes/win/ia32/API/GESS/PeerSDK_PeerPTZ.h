#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents the attached PTZ of video.
*/
class PEERSDK_API PeerPTZ
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerPTZ(_R* peer, int32 index);

    /**
    * @private
    */
    ~PeerPTZ();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Stop PTZ operation.
    * @return  A value that represents the error.
    */
    PeerResult Stop();

    /**
    * Move/Rotate PTZ.
    * @param [in] x     X-axis (-1.0 through 1.0).
    * @param [in] y     Y-axis (-1.0 through 1.0).
    * @param [in] stop  Send stop after send move command.
    * @return  A value that represents the error.
    */
    PeerResult Move(double x, double y, bool stop);

    /**
    * Zoom.
    * @param [in] speed  Zoom speed. (-1.0 through 1.0).
    * @param [in] stop   Send stop after send move command.
    * @return  A value that represents the error.
    */
    PeerResult DoZoom(double speed, bool stop);

    /**
    * Focus.
    * @param [in] speed  Focus speed. (-1.0 through 1.0).
    * @param [in] stop   Send stop after send move command.
    * @return  A value that represents the error.
    */
    PeerResult DoFocus(double speed, bool stop);

    /**
    * Adjust IRIS.
    * @param [in] speed  IRIS open/close speed. (-1.0 through 1.0).
    * @param [in] stop   Send stop after send move command.
    * @return  A value that represents the error.
    */
    PeerResult DoIris(double speed, bool stop);

    /**
    * Auto adjust focus.
    * @return  A value that represents the error.
    */
    PeerResult DoAutoFocus();

    /**
    * Auto adjust IRIS.
    * @return  A value that represents the error.
    */
    PeerResult DoAutoIris();

    /**
    * Set a preset point.
    * @param [in] preset  present number.
    * @return  A value that represents the error.
    */
    PeerResult SetPreset(int32 preset);

    /**
    * Go to a preset point.
    * @param [in] preset  present number.
    * @return  A value that represents the error.
    */
    PeerResult GoPreset(int32 preset);
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets a value that indicates whether the PTZ support zoom capacity.
    */
    bool CanZoom() const;

    /**
    * Gets a value that indicates whether the PTZ support focus capacity.
    */
    bool CanFocus() const;

    /**
    * Gets a value that indicates whether the PTZ support IRIS capacity.
    */
    bool CanIris() const;

    /**
    * Gets a value that indicates whether the PTZ support auto focus capacity.
    */
    bool CanAutoFocus() const;

    /**
    * Gets a value that indicates whether the PTZ support auto IRIS capacity.
    */
    bool CanAutoIris() const;

    /**
    * Gets a value that indicates whether the PTZ support go/set preset capacity.
    */
    bool CanPreset() const;

    /**
    * Gets a list that indicates whether the PTZ's available preset points.
    */
    IntList AvailablePreset() const;

public: // Properties
    /**
    * Gets a value that indicates whether the PTZ is enabled or not.
    */
    bool get_Enabled() const;
    //@}
};
