#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a <b>Resolution</b>.
*/
class PEERSDK_API QName
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    QName();

    /**
    * @private
    */
    QName(String const& ns, String const& localpart);

    /**
    * @private
    */
    QName(QName const& value);

    /**
    * @private
    */
    ~QName();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets the namespace part.
    */
    String Namespace() const;

    /**
    * Gets the local part name.
    */
    String LocalPart() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * Replaces the elements of the <b>Resolution</b> with a copy of another <b>Resolution</b>.
    */
    QName& operator=(QName const& value);
    //@}
};
