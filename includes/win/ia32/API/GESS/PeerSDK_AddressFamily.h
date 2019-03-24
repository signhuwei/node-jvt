#pragma once

/**
* @brief Specifies the addressing scheme.
*/
enum AddressFamily
{
    /**
    * Unknown address family.
    */
    AddressFamily_Unknown = 0,

    /**
    * Address for IP version 4.
    */
    AddressFamily_InterNetwork = 1,

    /**
    * Address for IP version 6.
    */
    AddressFamily_InterNetworkV6 = 2,
};
