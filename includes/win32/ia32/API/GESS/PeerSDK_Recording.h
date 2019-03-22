#pragma once

/**
* @brief Specifies status of record.
*/
enum Recording
{
    /**
    * Indicates not recording.
    */
    Recording_None = 0,

    /**
    * Indicates recording regular.
    */
    Recording_Regular = 1,

    /**
    * Indicates recording due to event triggering.
    */
    Recording_Event = 2,
};
