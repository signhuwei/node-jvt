#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>byte</b> buffer.
*/
class PEERSDK_API Memory
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new empty byte buffer.
    */
    Memory();

    /**
    * Initializes a byte buffer from another.
    */
    Memory(Memory const& value);

    /**
    * Destroyed the <b>Memory</b> instance.
    */
    ~Memory();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the buffer length.
    */
    int32 Length() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>DateTime</b> with a copy of another <b>DateTime</b>.
    */
    Memory& operator=(Memory const& value);
    //@}

    /**
    * Gets the byte buffer pointer.
    */
    operator byte const*() const;
    //@}
};
