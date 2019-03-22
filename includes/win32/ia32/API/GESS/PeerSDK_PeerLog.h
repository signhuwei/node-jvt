#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

/**
* @brief Represents a system log.
*/
class PEERSDK_API PeerLog
{
    PEERSDK_DECLARE_IMPL()

public:
    /** @name Constructors
    */
    //@{

    /**
    * @private
    */
    PeerLog();

    /**
    * @private
    */
    PeerLog(PeerLog const& value);

    /**
    * @private
    */
    ~PeerLog();
    //@}

public:
    /** @name Properties
    */
    //@{

    /**
    * Gets time of the log.
    */
    DateTime Time() const;

    /**
    * Gets type of the log.
    */
    LogType Type() const;

    /**
    * Gets a value that indicates whether the time has recording segment.
    */
    bool Playable() const;

public:
    /**
    * Gets a value that indicates whether the <i>Channel</i> field has value.
    */
    bool HasChannel() const;

    /**
    * Gets channel value.
    */
    int32 Channel() const;
    //@}

public:
    /** @name Operators
    */
    //@{

    /**
    * @private
    */
    PeerLog& operator=(PeerLog const& value);
    //@}
};
