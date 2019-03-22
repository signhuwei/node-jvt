#pragma once

#define PEERSDK_PROTECT

#if defined (ICARCH_WIN32)
    #include "PeerSDK_WinAPI.h"
#elif defined (ICARCH_IOS) \
    ||defined (ICARCH_MAC)
    #include "PeerSDK_Cocoa.h"
#elif defined (ICARCH_LINUX32) \
    ||defined (ICARCH_LINUX64) \
    ||defined (ICARCH_ANDROID) \
    ||defined (ICARCH_HI3531)
    #include "PeerSDK_POSIX.h"
#endif

typedef void* _R;

#define PEERSDK_DECLARE_IMPL()  private: class Impl; Impl* m_impl; public: _R& get__R(); _R const& get__R() const;

// Event | Type
#include "PeerSDK_AudioType.h"
#include "PeerSDK_VideoType.h"
#include "PeerSDK_HDDFlag.h"
#include "PeerSDK_LogType.h"
#include "PeerSDK_Recording.h"
#include "PeerSDK_RelayPole.h"
#include "PeerSDK_VideoFormat.h"
#include "PeerSDK_VideoFormatDetection.h"
#include "PeerSDK_DayOfWeek.h"
#include "PeerSDK_AddressFamily.h"

namespace PeerSDK
{
    // Type
    #include "PeerSDK_DateTime.h"
    #include "PeerSDK_IntList.h"
    #include "PeerSDK_Memory.h"
    #include "PeerSDK_RecordingList.h"
    #include "PeerSDK_String.h"
    #include "PeerSDK_StringList.h"
    #include "PeerSDK_IPAddress.h"
    #include "PeerSDK_TimeRange.h"
    #include "PeerSDK_TimeRangeList.h"
    #include "PeerSDK_TimeSpan.h"
    #include "PeerSDK_TimeSpanList.h"
    #include "PeerSDK_Resolution.h"
    #include "PeerSDK_ResolutionList.h"
    #include "PeerSDK_QName.h"
    #include "PeerSDK_QNameList.h"

    // Debug
    #include "PeerSDK_PeerResult.h"

    #include "PeerSDK_ChannelScheme.h"
    #include "PeerSDK_ChannelSchemeList.h"
    #include "PeerSDK_RecordScheme.h"

    // Event | Args
    #include "PeerSDK_AudioArrivedEventArgs.h"
    #include "PeerSDK_CompletedEventArgs.h"
    #include "PeerSDK_ErrorOccurredEventArgs.h"
    #include "PeerSDK_ProgressChangedEventArgs.h"
    #include "PeerSDK_RecordStatusChangedEventArgs.h"
    #include "PeerSDK_VideoArrivedEventArgs.h"
    #include "PeerSDK_VideoLossChangedEventArgs.h"
    #include "PeerSDK_VideoMotionChangedEventArgs.h"
    #include "PeerSDK_DiscoveryMatchEventArgs.h"

    // Event
    #include "PeerSDK_Event.h"

    // Peer | Stream
    #include "PeerSDK_PeerStream.h"

    // Peer | Record List
    #include "PeerSDK_PeerRecordList.h"

    // Peer | Log List
    #include "PeerSDK_PeerLog.h"
    #include "PeerSDK_PeerLogList.h"

    // Peer | HDD List
    #include "PeerSDK_PeerHDD.h"
    #include "PeerSDK_PeerHDDList.h"

    // Peer | IO
    #include "PeerSDK_PeerPTZ.h"
    #include "PeerSDK_PeerRelay.h"

    // Peer | Channel
    #include "PeerSDK_PeerAudio.h"
    #include "PeerSDK_PeerVideo.h"
    #include "PeerSDK_PeerChannel.h"

    // Peer | Recorder
    #include "PeerSDK_PeerRecorder.h"

    // Peer | Scheduler
    #include "PeerSDK_PeerScheduler.h"

    // Peer | Type
    #include "PeerSDK_ChannelCollection.h"
    #include "PeerSDK_RelayCollection.h"

    // Peer
    #include "PeerSDK_Peer.h"

    // Others
    #include "PeerSDK_PeerHelper.h"
    #include "PeerSDK_IrfAudioFrame.h"
    #include "PeerSDK_IrfVideoFrame.h"
    #include "PeerSDK_IrfFile.h"

    // Discovery
    #include "PeerSDK_DiscoveryService.h"
}
