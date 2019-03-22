//Add by fanguanggao 2012-04-12 15:30:26
//HookOperate.h
//KeyBoard an Mouse Hooking
#ifdef __cplusplus
#define DLLEXPORT extern "C" __declspec (dllexport)
#else
#define DLLEXPORT __declspec (dllexport)
#endif

//Hook消息回调,参数一为消息命令，参数二为用户数据
typedef int (CALLBACK * HookMsgCallFunc)(long MsgCommand,DWORD dwUserParam);

//HOOK需要处理消息类型
typedef enum _HOOK_MSG_TYPE_
{
	HOOK_NOTHING = 0,
	HOOK_SCREENLOCK, //锁屏
}HOOK_MSG_TYPE;

// 初始化
DLLEXPORT BOOL HOOK_Init();
// 安装钩子，nHookType为钩子类型，0为鼠标钩子WH_MOUSE,1为WH_KEYBOARD,2为两者
DLLEXPORT void HOOK_StartHook(int nHookType = 2);
// 卸装当前的所有钩子
DLLEXPORT void HOOK_StopHook();
//恢复原始时间
DLLEXPORT void HOOK_ResetTime();
//获取当前时间
DLLEXPORT DWORD HOOK_GetCurTime();
//设置是否进行锁屏
DLLEXPORT void HOOK_SetScreenLock(bool bLock = FALSE);
//消息回调
DLLEXPORT BOOL HOOK_SetMsgCallback(void* MsgCall,DWORD dwUser);
// 释放资源
DLLEXPORT BOOL HOOK_UnInit();