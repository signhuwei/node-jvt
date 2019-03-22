//Add by fanguanggao 2012-04-12 15:30:26
//HookOperate.h
//KeyBoard an Mouse Hooking
#ifdef __cplusplus
#define DLLEXPORT extern "C" __declspec (dllexport)
#else
#define DLLEXPORT __declspec (dllexport)
#endif

//Hook��Ϣ�ص�,����һΪ��Ϣ���������Ϊ�û�����
typedef int (CALLBACK * HookMsgCallFunc)(long MsgCommand,DWORD dwUserParam);

//HOOK��Ҫ������Ϣ����
typedef enum _HOOK_MSG_TYPE_
{
	HOOK_NOTHING = 0,
	HOOK_SCREENLOCK, //����
}HOOK_MSG_TYPE;

// ��ʼ��
DLLEXPORT BOOL HOOK_Init();
// ��װ���ӣ�nHookTypeΪ�������ͣ�0Ϊ��깳��WH_MOUSE,1ΪWH_KEYBOARD,2Ϊ����
DLLEXPORT void HOOK_StartHook(int nHookType = 2);
// жװ��ǰ�����й���
DLLEXPORT void HOOK_StopHook();
//�ָ�ԭʼʱ��
DLLEXPORT void HOOK_ResetTime();
//��ȡ��ǰʱ��
DLLEXPORT DWORD HOOK_GetCurTime();
//�����Ƿ��������
DLLEXPORT void HOOK_SetScreenLock(bool bLock = FALSE);
//��Ϣ�ص�
DLLEXPORT BOOL HOOK_SetMsgCallback(void* MsgCall,DWORD dwUser);
// �ͷ���Դ
DLLEXPORT BOOL HOOK_UnInit();