#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents text as a series of Unicode characters.
*/
class PEERSDK_API String
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>String</b> class.
    */
    String();

    /**
    * Initializes a new instance of the <b>String</b> class to the value indicated by a specified pointer to an array of ANSI characters.
    */
    String(char const* value);

    /**
    * Initializes a new instance of the <b>String</b> class to the value indicated by a specified pointer to an array of Unicode characters.
    */
    String(wchar_t const* value);

    /**
    * Initializes a new instance of the <b>String</b> class to the value indicated by a specified <b>String</b>.
    */
    String(String const& value);

    /**
    * Destroyed the <b>String</b> instance.
    */
    ~String();
    //@}

public:
    /** @name Methods
    */
    //@{

    /**
    * Create a Cocoa NSString from the <b>String</b> instance.
    */
    void* CreateNSString() const;

public:
    /**
    * Get the pointer of ANSI string.
    */
    char const* ToAnsi() const;

    /**
    * Get the pointer of Unicode string.
    */
    wchar_t const* ToNative() const;

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the number of characters in the current <b>String</b> object.
    */
    int32 Length() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>String</b> with a copy of another ANSI string.
    */
    String& operator=(char const* value);

    /**
    * Replaces the elements of the <b>String</b> with a copy of another Unicode string.
    */
    String& operator=(wchar_t const* value);

    /**
    * Replaces the elements of the <b>String</b> with a copy of another <b>String</b> object.
    */
    String& operator=(String const& value);

    /**
    * Converts the value of this instance to an Unicode string pointer.
    */
    operator wchar_t const*() const;
    //@}
};
