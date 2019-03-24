
#ifndef __SERIALPORT_H__
#define __SERIALPORT_H__

#define WM_COMM_BREAK_DETECTED		WM_USER+1	// A break was detected on input.
#define WM_COMM_CTS_DETECTED		WM_USER+2	// The CTS (clear-to-send) signal changed state. 
#define WM_COMM_DSR_DETECTED		WM_USER+3	// The DSR (data-set-ready) signal changed state. 
#define WM_COMM_ERR_DETECTED		WM_USER+4	// A line-status error occurred. Line-status errors are CE_FRAME, CE_OVERRUN, and CE_RXPARITY. 
#define WM_COMM_RING_DETECTED		WM_USER+5	// A ring indicator was detected. 
#define WM_COMM_RLSD_DETECTED		WM_USER+6	// The RLSD (receive-line-signal-detect) signal changed state. 
#define WM_COMM_RXCHAR				WM_USER+7	// A character was received and placed in the input buffer. 
#define WM_COMM_RXFLAG_DETECTED		WM_USER+8	// The event character was received and placed in the input buffer.  
#define WM_COMM_TXEMPTY_DETECTED	WM_USER+9	// The last character in the output buffer was sent.  
enum 
{
	SC_OK = 0, //确定或者停止
	SC_UP ,//云台 向上
	SC_DOWN,// 云台 向下
	SC_LEFT,// 云台 向左
	SC_RIGHT,// 云台 向右
	SC_LEFT_UP,// 云台 左上
	SC_LEFT_DOWN,//云台 左下
	SC_RIGHT_UP,//云台 右上
	SC_RIGHT_DOWN,//云台 右下
	SC_WIDE,//变倍-
	SC_TELE,//变倍+
	SC_SET,//设置预置点

	SC_CALL,//转到预置点
	OPEN,//光圈+
	CLOSE,//光圈-
	SC_FAR,//焦距+
	SC_NEAR,//焦距-
	SC_CLEAR,//
	SC_DEL,//删除预置点
	SC_SEL,//选择设备或通道
	SC_LOGIN,//登陆设备或通道
	SC_DEV_CTRL,//选择列表操作
	SC_NONE,//取消选择操作
};
typedef struct __PTZ_CONTROL_INFO 
{
	BYTE	byCommand;
	BYTE	byValue;		//步长或预置点号
	BYTE	byReserved;		//扩展命令中的参数2
	BYTE	byReserved1;	//lparam3,点间巡航用
	BYTE	byHSpeed;       //水平速度
	BYTE    byVSpeed;		//垂直速度
	BYTE	byStop;			//是否停止
	BYTE	byWndID;		//选择通道序号
	BYTE	byIsPTZ;		//是否云台控制
}NKB_PTZ_CONTROL_INFO;
typedef void ( CALLBACK* ReceiveMsg)( NKB_PTZ_CONTROL_INFO *info,DWORD dwUserParam); 
class CSerialPort
{														 
public:
	int m_nWriteSize; 
	void ClosePort();
	// contruction and destruction
	CSerialPort();
	virtual		~CSerialPort();

	// port initialisation											
	BOOL		InitPort(CWnd* pPortOwner, UINT portnr = 1, UINT baud = 19200, char parity = 'N', UINT databits = 8, UINT stopbits = 1, DWORD dwCommEvents = EV_RXCHAR, UINT writebuffersize = 1024);
	HANDLE				m_hComm;

	// start/stop comm watching
	BOOL		StartMonitoring(ReceiveMsg CallbackFunc, DWORD dwParm);
	BOOL		RestartMonitoring();
	BOOL		StopMonitoring();

	DWORD		GetWriteBufferSize();
	DWORD		GetCommEvents();
	DCB			GetDCB();

	void		WriteToPort(char* string);
	void		WriteToPort(char* string,int n);
	void		WriteToPort(LPCTSTR string);
	void		WriteToPort(LPCTSTR string,int n);
protected:
	// protected memberfunctions
	void		ProcessErrorMessage(char* ErrorText);
	static UINT	CommThread(LPVOID pParam);
	static void	ReceiveChar(CSerialPort* port, COMSTAT comstat);
	static void	WriteChar(CSerialPort* port);
	
	// thread
	CWinThread*			m_Thread;

	// synchronisation objects
	CRITICAL_SECTION	m_csCommunicationSync;
	BOOL				m_bThreadAlive;

	// handles
	HANDLE				m_hWriteEvent;
	HANDLE				m_hShutdownEvent;

	// Event array. 
	// One element is used for each event. There are two event handles for each port.
	// A Write event and a receive character event which is located in the overlapped structure (m_ov.hEvent).
	// There is a general shutdown when the port is closed. 
	HANDLE				m_hEventArray[3];

	// structures
	OVERLAPPED			m_ov;
	COMMTIMEOUTS		m_CommTimeouts;
	DCB					m_dcb;

	// owner window
	CWnd*				m_pOwner;

	// misc
	UINT				m_nPortNr;
	char*				m_szWriteBuffer;
	DWORD				m_dwCommEvents;
	DWORD				m_nWriteBufferSize;
protected:
	ReceiveMsg          m_receivermsg;
	DWORD				m_UserParm;
	BOOL				m_bExit;
	bool				m_bInit;
private:
	int ReadCommBlock(LPBYTE lpszBlock,int nMaxLength);
};

#endif __SERIALPORT_H__


