#pragma once

/**
* @brief Specifies type of video frame.
*/
enum VideoType
{
    /**
    * Indicates empty video frame.
    */
    VideoType_None = 0,

    /**
    * Indicates \b H264 I-frame.
    */
    VideoType_H264_IFrame = 1,

    /**
    * Indicates \b H264 P-frame.
    */
    VideoType_H264_PFrame = 2,
};
