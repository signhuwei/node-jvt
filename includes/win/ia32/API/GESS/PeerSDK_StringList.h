#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>String</b> list of objects that can be accessed by index.
*/
class PEERSDK_API StringList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>StringList</b> class.
    */
    StringList();

    /**
    * Initializes a new instance of the <b>StringList</b> class with specified <b>StringList</b> object.
    * @param [in] value  The <b>StringList</b> instance.
    */
    StringList(StringList const& value);
    
    /**
    * Destroyed the <b>StringList</b> instance.
    */
    ~StringList();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>StringList</b>.
    */
    int32 Count() const;

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>StringList</b> with a copy of another <b>StringList</b>.
    */
    StringList& operator=(StringList const& value);

    /**
    * Returns a reference in the <b>StringList</b> element at a specified position.
    */
    String operator[](int32 index) const;
    //@}
};
