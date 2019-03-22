#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

#ifdef PEERSDK_EXPORT
    #define PEERSDK_API  __declspec(dllexport)
#else
    #define PEERSDK_API
#endif

#define PEERSDK_CALLBACK CALLBACK

typedef unsigned char        byte;
typedef signed char          sbyte;
typedef signed short         int16;
typedef unsigned short       uint16;
typedef signed int           int32;
typedef unsigned int         uint32;
typedef signed long long     int64;
typedef unsigned long long   uint64;

#define _WINSOCKAPI_
#include <Windows.h>
