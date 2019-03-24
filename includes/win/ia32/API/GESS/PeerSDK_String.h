#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

#if defined (ICARCH_WIN32)
    #include "PeerSDK_String_WinAPI.h"
#elif defined (ICARCH_IOS) \
    ||defined (ICARCH_MAC)
    #include "PeerSDK_String_Cocoa.h"
#elif defined (ICARCH_LINUX32) \
    ||defined (ICARCH_LINUX64) \
    ||defined (ICARCH_ANDROID) \
    ||defined (ICARCH_HI3531)
    #include "PeerSDK_String_wchar_t.h"
#endif
