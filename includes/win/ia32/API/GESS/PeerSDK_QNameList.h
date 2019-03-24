#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>int32</b> list of objects that can be accessed by index.
*/
class PEERSDK_API QNameList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>IntList</b> class.
    */
    QNameList();

    /**
    * Initializes a new instance of the <b>IntList</b> class with specified <b>IntList</b> object.
    * @param [in] value  The <b>IntList</b> instance.
    */
    QNameList(QNameList const& value);

    /**
    * Destroyed the <b>IntList</b> instance.
    */
    ~QNameList();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>IntList</b>.
    */
    int32 Count() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>IntList</b> with a copy of another <b>IntList</b>.
    */
    QNameList& operator=(QNameList const& value);

    /**
    * Returns the value in the <b>IntList</b> element at a specified position.
    */
    QName operator[](int32 index) const;
    //@}
};
