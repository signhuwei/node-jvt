#pragma once

#pragma once

/**
* @brief Specifies the video format detection method.
*/
enum VideoFormatDetection
{
    /**
    * Indicates the video format is detected by source video.
    */
    VideoFormatDetection_Auto,

    /**
    * Indicates the video format is NTSC.
    */
    VideoFormatDetection_FixedNTSC,

    /**
    * Indicates the video format is PAL.
    */
    VideoFormatDetection_FixedPAL,

    /**
    * Indicates the video format is decided by DIP switch (usually in rear panel).
    */
    VideoFormatDetection_DIP,
};
