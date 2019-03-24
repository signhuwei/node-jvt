#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>PeerRelay</b> list of objects that can be accessed by index.
*/
class PEERSDK_API RelayCollection
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    RelayCollection();

    /**
    * @private
    */
    RelayCollection(RelayCollection const& value);

    /**
    * @private
    */
    ~RelayCollection();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>RelayCollection</b>.
    */
    int32 Count() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>RelayCollection</b> with a copy of another <b>RelayCollection</b>.
    */
    RelayCollection& operator=(RelayCollection const& value);

    /**
    * Returns a pointer in the <b>RelayCollection</b> element at a specified position.
    */
    PeerRelay* operator[](int32 index) const;
    //@}
};
