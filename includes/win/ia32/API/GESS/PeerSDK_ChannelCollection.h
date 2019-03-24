#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>PeerChannel</b> list of objects that can be accessed by index.
*/
class PEERSDK_API ChannelCollection
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    ChannelCollection();

    /**
    * @private
    */
    ChannelCollection(ChannelCollection const& value);

    /**
    * @private
    */
    ~ChannelCollection();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>ChannelCollection</b>.
    */
    int32 Count() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>ChannelCollection</b> with a copy of another <b>ChannelCollection</b>.
    */
    ChannelCollection& operator=(ChannelCollection const& value);

    /**
    * Returns a pointer in the <b>ChannelCollection</b> element at a specified position.
    */
    PeerChannel* operator[](int32 index) const;
    //@}
};
