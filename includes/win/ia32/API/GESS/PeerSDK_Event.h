#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

#define PEERSDK_EVENT_DECLARE(name) \
    typedef void (PEERSDK_CALLBACK *name##EventHandler)(void*, name##EventArgs const&); \
    class PEERSDK_API name##Event \
    { \
        PEERSDK_DECLARE_IMPL() \
    public: \
        name##Event(); \
        ~name##Event(); \
    public: \
        void Add(void* tag, name##EventHandler handler); \
        void Remove(void* tag, name##EventHandler handler); \
        void Invoke(name##EventArgs const& e); \
    }

PEERSDK_EVENT_DECLARE(ErrorOccurred);

PEERSDK_EVENT_DECLARE(VideoLossChanged);
PEERSDK_EVENT_DECLARE(VideoMotionChanged);
PEERSDK_EVENT_DECLARE(RecordStatusChanged);

PEERSDK_EVENT_DECLARE(VideoArrived);
PEERSDK_EVENT_DECLARE(AudioArrived);
PEERSDK_EVENT_DECLARE(ProgressChanged);
PEERSDK_EVENT_DECLARE(Completed);

PEERSDK_EVENT_DECLARE(DiscoveryMatch);
