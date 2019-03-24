#ifdef __linux__
    #ifdef __x86_64__
        #include <linux/x64/API/VideoNetAPI.h>
    #else
        #include <linux/ia32/API/VideoNetAPI.h>
    #endif
#elif _WIN32
    #ifdef _WIN64
        #include <win32/x64/API/VideoNetAPI.h>
    #else
        #include <win32/ia32/API/VideoNetAPI.h>
    #endif
#else
#error "Unsupported platform!"
#endif