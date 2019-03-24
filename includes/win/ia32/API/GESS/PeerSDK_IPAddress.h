#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Provides an Internet Protocol (IP) address.
*/
class PEERSDK_API IPAddress
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    IPAddress();

    /**
    * @private
    */
    IPAddress(_R* ipv4, _R* ipv6);

    /**
    * @private
    */
    IPAddress(IPAddress const& value);

    /**
    * @private
    */
    ~IPAddress();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Gets the address family of the IP address.
    */
    String ToString() const;
    //@}

public:
    /** @name Static Methods
    */
    //@{

    /**
    * Gets the address family of the IP address.
    */
    static IPAddress Parse(String const& s);
    //@}

public:
    /** @name Static Fields
    */
    //@{

    /**
    * Gets the address family of the IP address.
    */
    static IPAddress Any();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the address family of the IP address.
    */
    AddressFamily Family() const;

    /**
    * Get the IPAddress as an array of bytes.
    */
    Memory AddressBytes() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>DateTime</b> with a copy of another <b>DateTime</b>.
    */
    IPAddress& operator=(IPAddress const& value);
    //@}
};
