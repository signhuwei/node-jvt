#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>PeerLogList</b> list of objects that can be accessed by index.
*/
class PEERSDK_API PeerLogList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>PeerLogList</b> class.
    */
    PeerLogList();

    /**
    * Initializes a new instance of the <b>PeerLogList</b> class with specified <b>PeerLogList</b> object.
    * @param [in] value  The <b>PeerLogList</b> instance.
    */
    PeerLogList(PeerLogList const& value);

    /**
    * Destroyed the <b>PeerLogList</b> instance.
    */
    ~PeerLogList();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>PeerLogList</b>.
    */
    int32 Count() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>PeerLogList</b> with a copy of another <b>PeerLogList</b>.
    */
    PeerLogList& operator=(PeerLogList const& value);

    /**
    * Returns a reference in the <b>PeerLogList</b> element at a specified position.
    */
    PeerLog const& operator[](int32 index) const;
    //@}
};
