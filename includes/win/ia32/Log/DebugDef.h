#ifndef __DEBUG_DEF_H__
#define __DEBUG_DEF_H__
#include "Log/IDebug.h"

#define MODE_APP		"APP"  //Sofia”¶”√≥Ã–Ú
#define MODE_MANAGER 	"MANAGER"
#define MODE_NETSERVICE "NETSERVICE"
#define MODE_NETIP		"NETIP"
#define MODE_COMM		"COMM"
#define MODE_RTSP		"RTSP"
#define MODE_HTTP		"HTTPD"
#define MODE_STORAGE	"STORAGE"
#define MODE_GUI		"GUI"
#define MODE_GDI		"GDI"
#define MODE_ENC		"ENC"
#define MODE_PLAY		"PLAY"
#define MODE_SNAP		"SNAP"
#define MODE_TPBASE		"TPBASE"
#define MODE_NETPLATFORM	"PLATFORM"
#define MODE_EXCHANGE	"EXCHANGE"

#if 0
//APP
#define AppDebugReg()	g_XMdebug.RegisterDebug(MODE_APP)
#define AppDebug(fmt, ...) g_XMdebug.Print(MODE_APP, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define AppErr(fmt, ...) g_XMdebug.Print(MODE_APP, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define AppWraning(fmt, ...) g_XMdebug.Print(MODE_APP, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define AppInfo(fmt, ...) g_XMdebug.Print(MODE_APP, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Manager
#define ManagerDebugReg()	g_XMdebug.RegisterDebug(MODE_MANAGER)
#define ManagerDebug(fmt, ...) g_XMdebug.Print(MODE_MANAGER, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define ManagerErr(fmt, ...) g_XMdebug.Print(MODE_MANAGER, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define ManagerWraning(fmt, ...) g_XMdebug.Print(MODE_MANAGER, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define ManagerInfo(fmt, ...) g_XMdebug.Print(MODE_MANAGER, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Netservice
#define NsDebugReg()	g_XMdebug.RegisterDebug(MODE_NETSERVICE)
#define NsDebug(fmt, ...) g_XMdebug.Print(MODE_NETSERVICE, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define NsErr(fmt, ...) g_XMdebug.Print(MODE_NETSERVICE, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define NsWraning(fmt, ...) g_XMdebug.Print(MODE_NETSERVICE, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define NsInfo(fmt, ...) g_XMdebug.Print(MODE_NETSERVICE, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//netip
#define NiDebugReg()	g_XMdebug.RegisterDebug(MODE_NETIP)
#define NiDebug(fmt, ...) g_XMdebug.Print(MODE_NETIP, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define NiErr(fmt, ...) g_XMdebug.Print(MODE_NETIP, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define NiWraning(fmt, ...) g_XMdebug.Print(MODE_NETIP, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define NiInfo(fmt, ...) g_XMdebug.Print(MODE_NETIP, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Comm
#define CommDebugReg()	g_XMdebug.RegisterDebug(MODE_COMM)
#define CommDebug(fmt, ...) g_XMdebug.Print(MODE_COMM, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define CommErr(fmt, ...) g_XMdebug.Print(MODE_COMM, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define CommWraning(fmt, ...) g_XMdebug.Print(MODE_COMM, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define CommInfo(fmt, ...) g_XMdebug.Print(MODE_COMM, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Rtsp
#define RtspDebugReg()	g_XMdebug.RegisterDebug(MODE_RTSP)
#define RtspDebug(fmt, ...) g_XMdebug.Print(MODE_RTSP, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define RtspErr(fmt, ...) g_XMdebug.Print(MODE_RTSP, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define RtspWraning(fmt, ...) g_XMdebug.Print(MODE_RTSP, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define RtspInfo(fmt, ...) g_XMdebug.Print(MODE_RTSP, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Http
#define HttpDebugReg()	g_XMdebug.RegisterDebug(MODE_HTTP)
#define HttpDebug(fmt, ...) g_XMdebug.Print(MODE_HTTP, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define HttpErr(fmt, ...) g_XMdebug.Print(MODE_HTTP, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define HttpWraning(fmt, ...) g_XMdebug.Print(MODE_HTTP, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define HttpInfo(fmt, ...) g_XMdebug.Print(MODE_HTTP, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Storage
#define StorageDebugReg()	g_XMdebug.RegisterDebug(MODE_STORAGE)
#define StorageDebug(fmt, ...) g_XMdebug.Print(MODE_STORAGE, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define StorageErr(fmt, ...) g_XMdebug.Print(MODE_STORAGE, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define StorageWraning(fmt, ...) g_XMdebug.Print(MODE_STORAGE, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define StorageInfo(fmt, ...) g_XMdebug.Print(MODE_STORAGE, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Gui
#define GuiDebugReg()	g_XMdebug.RegisterDebug(MODE_GUI)
#define GuiDebug(fmt, ...) g_XMdebug.Print(MODE_GUI, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define GuiErr(fmt, ...) g_XMdebug.Print(MODE_GUI, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define GuiWraning(fmt, ...) g_XMdebug.Print(MODE_GUI, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define GuiInfo(fmt, ...) g_XMdebug.Print(MODE_GUI, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Gdi
#define GdiDebugReg()	g_XMdebug.RegisterDebug(MODE_GDI)
#define GdiDebug(fmt, ...) g_XMdebug.Print(MODE_GDI, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define GdiErr(fmt, ...) g_XMdebug.Print(MODE_GDI, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define GdiWraning(fmt, ...) g_XMdebug.Print(MODE_GDI, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define GdiInfo(fmt, ...) g_XMdebug.Print(MODE_GDI, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Enc
#define EncDebugReg()	g_XMdebug.RegisterDebug(MODE_ENC)
#define EncDebug(fmt, ...) g_XMdebug.Print(MODE_ENC, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define EncErr(fmt, ...) g_XMdebug.Print(MODE_ENC, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define EncWraning(fmt, ...) g_XMdebug.Print(MODE_ENC, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define EncInfo(fmt, ...) g_XMdebug.Print(MODE_ENC, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Play
#define PlayDebugReg()	g_XMdebug.RegisterDebug(MODE_PLAY)
#define PlayDebug(fmt, ...) g_XMdebug.Print(MODE_PLAY, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define PlayErr(fmt, ...) g_XMdebug.Print(MODE_PLAY, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define PlayWraning(fmt, ...) g_XMdebug.Print(MODE_PLAY, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define PlayInfo(fmt, ...) g_XMdebug.Print(MODE_PLAY, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Snap
#define SnapDebugReg()	g_XMdebug.RegisterDebug(MODE_SNAP)
#define SnapDebug(fmt, ...) g_XMdebug.Print(MODE_SNAP, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define SnapErr(fmt, ...) g_XMdebug.Print(MODE_SNAP, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define SnapWraning(fmt, ...) g_XMdebug.Print(MODE_SNAP, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define SnapInfo(fmt, ...) g_XMdebug.Print(MODE_SNAP, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Tpbase
#define TpbDebugReg()	g_XMdebug.RegisterDebug(MODE_TPBASE)
#define TpbDebug(fmt, ...) g_XMdebug.Print(MODE_TPBASE, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define TpbErr(fmt, ...) g_XMdebug.Print(MODE_TPBASE, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define TpbWraning(fmt, ...) g_XMdebug.Print(MODE_TPBASE, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define TpbInfo(fmt, ...) g_XMdebug.Print(MODE_TPBASE, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//NetPlatform
#define NpDebugReg()	g_XMdebug.RegisterDebug(MODE_NETPLATFORM)
#define NpDebug(fmt, ...) g_XMdebug.Print(MODE_NETPLATFORM, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define NpErr(fmt, ...) g_XMdebug.Print(MODE_NETPLATFORM, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define NpWraning(fmt, ...) g_XMdebug.Print(MODE_NETPLATFORM, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define NpInfo(fmt, ...) g_XMdebug.Print(MODE_NETPLATFORM, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

//Exchange
#define ExChgDebugReg()	g_XMdebug.RegisterDebug(MODE_EXCHANGE)
#define ExChgDebug(fmt, ...) g_XMdebug.Print(MODE_EXCHANGE, IDebug::DL_DEBUG, fmt, ##__VA_ARGS__)
#define ExChgErr(fmt, ...) g_XMdebug.Print(MODE_EXCHANGE, IDebug::DL_ERROR, fmt, ##__VA_ARGS__)
#define ExChgWraning(fmt, ...) g_XMdebug.Print(MODE_EXCHANGE, IDebug::DL_WARNING, fmt, ##__VA_ARGS__)
#define ExChgInfo(fmt, ...) g_XMdebug.Print(MODE_EXCHANGE, IDebug::DL_INFO, fmt, ##__VA_ARGS__)

#else

//APP
#define AppDebugReg()
#define AppDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define AppErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define AppWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define AppInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Manager
#define ManagerDebugReg()
#define ManagerDebug(fmt, ...)   printf(fmt, ##__VA_ARGS__)
#define ManagerErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define ManagerWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define ManagerInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Netservice
#define NsDebugReg()
#define NsDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NsErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NsWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NsInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//netip
#define NiDebugReg()
#define NiDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NiErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NiWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NiInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Comm
#define CommDebugReg()
#define CommDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define CommErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define CommWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define CommInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Rtsp
#define RtspDebugReg()
#define RtspDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define RtspErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define RtspWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define RtspInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Http
#define HttpDebugReg()
#define HttpDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define HttpErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define HttpWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define HttpInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Storage
#define StorageDebugReg()
#define StorageDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define StorageErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define StorageWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define StorageInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Gui
#define GuiDebugReg()
#define GuiDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define GuiErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define GuiWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define GuiInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Gdi
#define GdiDebugReg()
#define GdiDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define GdiErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define GdiWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define GdiInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Enc
#define EncDebugReg()
#define EncDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define EncErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define EncWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define EncInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Play
#define PlayDebugReg()
#define PlayDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define PlayErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define PlayWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define PlayInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Snap
#define SnapDebugReg()
#define SnapDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define SnapErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define SnapWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define SnapInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//Tpbase
#define TpbDebugReg()
#define TpbDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define TpbErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define TpbWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define TpbInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)

//NetPlatform
#define NpDebugReg()
#define NpDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NpErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NpWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define NpInfo(fmt, ...)  printf(fmt, ##__VA_ARGS__)

//Exchange
#define ExChgDebugReg()
#define ExChgDebug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define ExChgErr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define ExChgWraning(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define ExChgInfo(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif
#endif

