#pragma once

/**
* @brief Specifies type of audio sample.
*/
enum AudioType
{
    /**
    * Indicates empty audio sample.
    */
    AudioType_None = 0,

    /**
    * Indicates <b>IMA ADPCM</b>, mono, 16-bit depth, 8000Hz.
    */
    AudioType_IMA_ADPCM_16Bits_8000Hz = 1,

    /**
    * Indicates <b>Linear PCM</b>, mono, 16-bit depth, 8000Hz.
    */
    AudioType_LPCM_16Bits_8000Hz = 2,

    /**
    * Indicates <b>Linear PCM</b>, mono, 8-bit depth, 8000Hz.
    */
    AudioType_LPCM_8Bits_8000Hz = 3,
};
