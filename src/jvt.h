#ifdef __linux__
    #ifdef __x86_64__
        #include "../includes/linux/x64/API/VideoNetAPI.h"
    #else
        #include "../includes/linux/ia32/API/VideoNetAPI.h"
    #endif
#elif _WIN32
    #ifdef _WIN64
        #include "../includes/win32/x64/API/VideoNetAPI.h"
    #else
        #include "../includes/win32/ia32/API/VideoNetAPI.h"
    #endif
#else
#error "Unsupported platform!"
#endif