#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Contains state information and event data associated with a <b>AudioArrivedEvent</b> event.
*/
class PEERSDK_API DiscoveryMatchEventArgs
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    DiscoveryMatchEventArgs(String const& id, QNameList const& types, IPAddress const& ip, StringList const& services, StringList const& scopes, String const& metadataversion);

    /**
    * @private
    */
    ~DiscoveryMatchEventArgs();
    //@}

public: // Properties
    /** @name Properties
    */
    //@{

    /**
    * Gets type of audio samples.
    */
    String ID() const;
    
    /**
    * Gets type of audio samples.
    */
    QNameList Types() const;
    
    /**
    * Gets type of audio samples.
    */
    IPAddress IP() const;
    
    /**
    * Gets type of audio samples.
    */
    StringList Services() const;
    
    /**
    * Gets type of audio samples.
    */
    StringList Scopes() const;
    
    /**
    * Gets type of audio samples.
    */
    String MetadataVersion() const;
    //@}
};
