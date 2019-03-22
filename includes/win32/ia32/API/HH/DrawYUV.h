/******************************************************************************
* ϵͳ���ƣ�DrawYUV
* �ļ����ƣ�DrawYUV.h
* �汾    ��V5.5.2
* ˵��	  ����ģ���ṩ��Ƶ��ʾ֧��
			
* ��    ��: 2005��10��10��
  �������:	
* ����˵��: ��
******************************************************************************/
#ifdef DRAWYUV_EXPORTS
#define DRAWYUV_API __declspec(dllexport)
#else
#define DRAWYUV_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************/
/********************************  һ�������ӿڶ���  *************************/
/*****************************************************************************/

//����DDrawʵ��
DRAWYUV_API HANDLE	WINAPI CreateDrawYUV();
//����DDrawʵ��
DRAWYUV_API void	WINAPI ReleaseDrawYUV(HANDLE m_handle);
//��ʼ��DDrawʵ��
DRAWYUV_API	BOOL	WINAPI InitDirectDraw(HANDLE m_handle,HWND hWnd,DWORD dwWidth,DWORD dwHeight,WORD nType);
//����ʾ����(YUV)
DRAWYUV_API	BOOL	WINAPI DrawImageFormYUVBuf(HANDLE m_handle,PBYTE  in_Y,PBYTE in_U,PBYTE in_V,RECT *Rectdes = NULL);
//������ʾ����
DRAWYUV_API	BOOL	WINAPI SetDisplayClipper(HANDLE m_handle,HWND hWnd);
//�����ʾ����
DRAWYUV_API	BOOL	WINAPI FillDisplay(HANDLE m_handle,DWORD dwColor);
//ˢ����ʾ�߽�
DRAWYUV_API	void	WINAPI UpdateBounds(HANDLE m_handle);
//ˢ����ʾͼ��
DRAWYUV_API	BOOL	WINAPI UpdataImage(HANDLE m_handle,RECT *Rectdes = NULL);

#ifdef __cplusplus
}
#endif