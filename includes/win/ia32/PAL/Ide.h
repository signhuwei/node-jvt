//
//  "$Id: Ide.h 11 2009-08-21 14:31:22Z liwj $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_IDE_H__
#define __PAL_IDE_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
	typedef unsigned __int64		_uint64;
#else
	typedef long long				_uint64;
#endif

/// \defgroup IDEAPI API IDE
/// 存储设备直接访问API，文件系统构建在此接口之上。 存储设备包括IDE硬盘，
///	SD Card等等，总线接口不限。
///	\n 调用流程图
/// \code
///    ===========================
///                |
///            ide_init
///                |
///           *ide_getinfo
///                |------------+
///            ide_read         |
///            ide_write        |
///            ide_wakeup       |
///         ide_setstandby      |
///      ide_setstandby_multi   |
///                |------------+
///    ===========================
/// \endcode
/// \note ide_read，ide_write用于IPO访问，ide_read_dma和ide_write_dma用于DMA访问，
/// \n部分平台下IPO访问已经废弃，两种接口都采用DMA实现。
/// @{

#define IDE_SECTOR_SIZE 512


/// IDE设备信息结构
typedef struct IDE_INFO64
{
	/// 已挂载的硬盘的数量,，不包括坏盘。硬盘个数也等于ide_msk中置1的位个数减去
	/// ide_bad中置1的位个数. 应用程序访问硬盘时, 硬盘序号规则如下: 第一个被置1
	/// 的位对应的IDE通道上挂载的正常硬盘的硬盘序号为0，第二个被置1的位对应正常
	/// 硬盘的硬盘序号为1，依次类推。
	int		ide_num;

	///< IDE通道的数目，包括扩展的IDE通道。
	int		ide_port;

	/// 指示各个IDE通道上是否挂载硬盘，包括坏盘。每一位对应IDE通道的主盘或从盘，
	/// 置位表示以挂载硬盘，否则没有。对应关系为bit0对应IDE0的主盘，bit1对应IDE0
	/// 的从盘，bit2对应IDE1的主盘，bit3对应IDE1的从盘，依次类推。
	unsigned int	ide_msk;
	
	/// 指示各个IDE通道上是否挂载了坏的硬盘。每一位对应IDE通道的主盘或从盘，置位
	/// 表示以有坏硬盘，否则没有。对应关系同ide_msk。
	unsigned int	ide_bad;
	
	/// 已挂载的正常硬盘的容量，以扇区为单位，扇区大小为IDE_SECTOR_SIZE。扇区数用
	/// 32位来表示，数组下标是正常硬盘的序号。
	_uint64			ide_cap[32];
} IDE_INFO64, *pIDE_INFO64;


/// 初始化所有IDE设备。
/// 
/// \param 无
/// \retval 0  操作成功
/// \retval <0  操作失败
int ide_init(void);


/// 得到IDE的信息。
/// 
/// \param [out] info 指向用户申请的用来接收硬盘信息的结构IDE_INFO的指针。
/// \return>=0  硬盘数目
/// \retval <0  操作失败
int ide_getinfo64(IDE_INFO64 *info);


/// PIO方式读数据。因硬件故障而出错时, 应当设置硬盘信息中ide_bad对应的位, 但是
/// ide_num不应改变。
/// 
/// \param [in] dev 硬盘序号。
/// \param [in] sectors 要读出的扇区数。
/// \param [in] offs 读出点的扇区偏移。
/// \param [out] pdat 用来接收读出数据的缓冲。
/// \retval 0  操作成功
/// \retval <0  操作失败
int ide_read64(unsigned short dev, unsigned short sectors, _uint64 offs, void * pdat);


/// PIO方式读数据。
/// 
/// \param [in] dev 硬盘序号。
/// \param [in] sectors 要写入的扇区数。
/// \param [in] offs 写入点的扇区偏移。
/// \param [in] pdat 待写入的数据的缓冲。
/// \retval 0  操作成功
/// \retval <0  操作失败
int ide_write64(unsigned short dev, unsigned short sectors, _uint64 offs, void * pdat);


/// 唤醒硬盘。如果硬盘处于活动状态，也要执行唤醒命令，保证不会在超时后自动进入
/// 睡眠状态。
/// 
/// \param [in] ide_no 硬盘序号。
/// \retval 0  操作成功
/// \retval <0  操作失败
int ide_wakeup(unsigned short ide_no);


/// 同时设置多个硬盘的待命时间，以节约设置时间。
/// 
/// \param [in] ide_mask 硬盘掩码，定义和IDE_INFO中掩码定义相同。
/// \param [in] minutes 超时时间，分钟为单位。 
/// \retval 0  操作成功
/// \retval <0  操作失败
/// \see IDE_INFO
int ide_setstandby_multi(unsigned long ide_mask, int minutes);


/// 注册存储设备变动回调函数
/// \param [in] hotplug 存储设备变动回调函数,diskno变动的存储设备号，
///					remove 1表示存储设备被删除，0表示存储设备被插入
/// \retval 0	操作成功
/// \retval < 0 炒作失败
int ide_hotplug_proc(void (*hotplug)(unsigned int diskno, int remove));

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
