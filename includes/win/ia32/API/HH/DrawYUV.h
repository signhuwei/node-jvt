/******************************************************************************
* 系统名称：DrawYUV
* 文件名称：DrawYUV.h
* 版本    ：V5.5.2
* 说明	  ：该模块提供视频显示支持
			
* 日    期: 2005年10月10日
  最近更新:	
* 其他说明: 无
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
/********************************  一、函数接口定义  *************************/
/*****************************************************************************/

//构造DDraw实例
DRAWYUV_API HANDLE	WINAPI CreateDrawYUV();
//析构DDraw实例
DRAWYUV_API void	WINAPI ReleaseDrawYUV(HANDLE m_handle);
//初始化DDraw实例
DRAWYUV_API	BOOL	WINAPI InitDirectDraw(HANDLE m_handle,HWND hWnd,DWORD dwWidth,DWORD dwHeight,WORD nType);
//送显示数据(YUV)
DRAWYUV_API	BOOL	WINAPI DrawImageFormYUVBuf(HANDLE m_handle,PBYTE  in_Y,PBYTE in_U,PBYTE in_V,RECT *Rectdes = NULL);
//设置显示区域
DRAWYUV_API	BOOL	WINAPI SetDisplayClipper(HANDLE m_handle,HWND hWnd);
//填充显示区域
DRAWYUV_API	BOOL	WINAPI FillDisplay(HANDLE m_handle,DWORD dwColor);
//刷新显示边界
DRAWYUV_API	void	WINAPI UpdateBounds(HANDLE m_handle);
//刷新显示图像
DRAWYUV_API	BOOL	WINAPI UpdataImage(HANDLE m_handle,RECT *Rectdes = NULL);

#ifdef __cplusplus
}
#endif