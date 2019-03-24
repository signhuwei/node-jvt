#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>PeerHDDList</b> list of objects that can be accessed by index.
*/
class PEERSDK_API PeerHDDList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>PeerHDDList</b> class.
    */
    PeerHDDList();

    /**
    * Initializes a new instance of the <b>PeerHDDList</b> class with specified <b>PeerHDDList</b> object.
    * @param [in] value  The <b>PeerHDDList</b> instance.
    */
    PeerHDDList(PeerHDDList const& value);

    /**
    * Destroyed the <b>PeerHDDList</b> instance.
    */
    ~PeerHDDList();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>PeerHDDList</b>.
    */
    int32 Count() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>PeerHDDList</b> with a copy of another <b>PeerHDDList</b>.
    */
    PeerHDDList& operator=(PeerHDDList const& value);

    /**
    * Returns a reference in the <b>PeerHDDList</b> element at a specified position.
    */
    PeerHDD const& operator[](int32 index) const;
    //@}
};
