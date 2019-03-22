#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>Resolution</b> list of objects that can be accessed by index.
*/
class PEERSDK_API ResolutionList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>ResolutionList</b> class.
    */
    ResolutionList();

    /**
    * Initializes a new instance of the <b>ResolutionList</b> class with specified <b>ResolutionList</b> object.
    * @param [in] value  The <b>ResolutionList</b> instance.
    */
    ResolutionList(ResolutionList const& value);
    
    /**
    * Destroyed the <b>ResolutionList</b> instance.
    */
    ~ResolutionList();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>ResolutionList</b>.
    */
    int32 Count() const;

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>ResolutionList</b> with a copy of another <b>ResolutionList</b>.
    */
    ResolutionList& operator=(ResolutionList const& value);

    /**
    * Returns a reference in the <b>ResolutionList</b> element at a specified position.
    */
    Resolution const& operator[](int32 index) const;
    //@}
};
