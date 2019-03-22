#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>ChannelSchemeList</b> list of objects that can be accessed by index.
*/
class PEERSDK_API ChannelSchemeList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    ChannelSchemeList(_R& scheme);

    /**
    * @private
    */
    ChannelSchemeList(ChannelSchemeList const& value);
    
    /**
    * @private
    */
    ~ChannelSchemeList();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>ChannelSchemeList</b>.
    */
    int32 Count() const;

public:
    /** @name Operators
    */
    //@{

    /**
    * @private
    */
    ChannelSchemeList& operator=(ChannelSchemeList const& value);

    /**
    * Returns a reference in the <b>ChannelSchemeList</b> element at a specified position.
    */
    ChannelScheme operator[](int32 index) const;
    //@}
};
