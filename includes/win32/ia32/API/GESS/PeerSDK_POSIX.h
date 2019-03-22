#pragma once

#ifndef PEERSDK_PROTECT
#pragma message("please include PeerSDK.h instead of me")
#endif

#define PEERSDK_API

#define PEERSDK_CALLBACK

typedef unsigned char        byte;
typedef signed char          sbyte;
typedef signed short         int16;
typedef unsigned short       uint16;
typedef signed int           int32;
typedef unsigned int         uint32;
typedef signed long long     int64;
typedef unsigned long long   uint64;

#include <time.h>
#include <unistd.h>
