#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>Recording</b> list of objects that can be accessed by index.
*/
class PEERSDK_API RecordingList
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>RecordingList</b> class.
    */
    RecordingList();

    /**
    * Initializes a new instance of the <b>RecordingList</b> class with specified <b>RecordingList</b> object.
    * @param [in] value  The <b>RecordingList</b> instance.
    */
    RecordingList(RecordingList const& value);

    /**
    * Destroyed the <b>RecordingList</b> instance.
    */
    ~RecordingList();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of elements actually contained in the <b>RecordingList</b>.
    */
    int32 Count() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>RecordingList</b> with a copy of another <b>RecordingList</b>.
    */
    RecordingList& operator=(RecordingList const& value);

    /**
    * Returns the value in the <b>RecordingList</b> element at a specified position.
    */
    Recording operator[](int32 index) const;
    //@}
};
