#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents errors that occur during application execution.
*/
class PEERSDK_API PeerResult
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * Initializes a new instance of the <b>PeerResult</b> class.
    */
    PeerResult();

    /**
    * Initializes a new instance of the <b>PeerResult</b> class with specified <b>PeerResult</b> object.
    * @param [in] value  The <b>PeerResult</b> instance.
    */
    PeerResult(PeerResult const& value);

    /**
    * Destroyed the <b>PeerResult</b> instance.
    */
    ~PeerResult();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets a message that describes the current exception.
    */
    String Message() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>PeerResult</b> with a copy of another <b>PeerResult</b>.
    */
    PeerResult& operator=(PeerResult const& value);

    /**
    * The operator returns a value convertible to <i>true</i> only if successful.
    */
    operator bool() const;

    /**
    * The operator returns a value convertible to <i>true</i> only if successful.
    */
    bool operator!() const;
    //@}
};
