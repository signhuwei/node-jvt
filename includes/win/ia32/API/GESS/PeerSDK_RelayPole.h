#pragma once

/**
* @brief Specifies pole type of relay.
*/
enum RelayPole
{
    /**
    * Indicates relay switch its pole in seconds.
    */
    RelayPole_Legacy = 0,

    /**
    * Indicates pole of relay is controlled by DVR.
    */
    RelayPole_Auto = 1,

    /**
    * Indicates pole of relay is normally-open.
    */
    RelayPole_NO = 2,

    /**
    * Indicates pole of relay is normally-close.
    */
    RelayPole_NC = 3,
};
