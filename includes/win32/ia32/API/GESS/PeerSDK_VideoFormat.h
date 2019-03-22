#pragma once

/**
* @brief Specifies the video format.
*/
enum VideoFormat
{
    /**
    * Indicates the video format is unspecified.
    */
    VideoFormat_None,

    /**
    * Indicates the video format is NTSC.
    */
    VideoFormat_NTSC,

    /**
    * Indicates the video format is PAL.
    */
    VideoFormat_PAL,

    /**
    * Indicates the video format is 720p, 24 frames/s.
    */
    VideoFormat_720p24,

    /**
    * Indicates the video format is 720p, 25 frames/s.
    */
    VideoFormat_720p25,

    /**
    * Indicates the video format is 720p, 30 frames/s.
    */
    VideoFormat_720p30,

    /**
    * Indicates the video format is 720p, 50 frames/s.
    */
    VideoFormat_720p50,

    /**
    * Indicates the video format is 720p, 60 frames/s.
    */
    VideoFormat_720p60,

    /**
    * Indicates the video format is 1080i, 50 fields/s.
    */
    VideoFormat_1080i50,

    /**
    * Indicates the video format is 1080i, 60 fields/s.
    */
    VideoFormat_1080i60,

    /**
    * Indicates the video format is 1080p, 24 frames/s.
    */
    VideoFormat_1080p24,

    /**
    * Indicates the video format is 1080p, 25 frames/s.
    */
    VideoFormat_1080p25,

    /**
    * Indicates the video format is 1080p, 30 frames/s.
    */
    VideoFormat_1080p30,

    /**
    * Indicates the video format is 1080p, 50 frames/s.
    */
    VideoFormat_1080p50,

    /**
    * Indicates the video format is 1080p, 60 frames/s.
    */
    VideoFormat_1080p60,
};
