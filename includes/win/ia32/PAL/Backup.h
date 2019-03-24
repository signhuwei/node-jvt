//
//  "$Id: Backup.h 3642 2012-06-18 02:03:27Z renxusheng $"
//
//  Copyright (c)2008-2008, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __PAL_BACKUP_H__
#define __PAL_BACKUP_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
	typedef unsigned __int64		_uint64;
#else
	typedef long long				_uint64;
#endif

/// \defgroup BackupAPI API Backup
/// 统一备份接口，支持到本地或远程标准文件系统的拷贝或者光盘刻录。
///	\n 调用流程图:
/// \code
///    ===========================
///                |
///         BackupGetDevices
///                |
///            BackupFormat
///                |
///            BackupStart
///                |
///                |------------+
///           BackupFileOpen    |
///                |            | 
///           BackupFileStuff   |
///                |            |
///           BackupFileClose   | 
///                |            |
///                |------------+
///            BackupStop
///                |
///    ===========================
/// \endcode
/// @{

/// 备份设备类型
typedef enum BDEV_TYTE
{
	BT_WFS,			///< 本地文件系统。
	BT_DISK,			///< 移动硬盘。
	BT_CDRW				///< 光盘刻录。
} BDEV_TYPE;

/// 备份设备总线类型
typedef enum BDEV_BUS
{
	BB_USB = 0,				///< USB接口
	BB_1394,			///< 1394接口。
	BB_IDE,				///< IDE接口。
	BB_SATA,			///< SATA接口。
	BB_MMC				///<SD接口
} BDEV_BUS;

/// 备份设备结构
typedef struct BACKUP_DEVICE
{
	struct BACKUP_DEVICE		*prev;	///< 指向上一个设备指针
	struct BACKUP_DEVICE		*next;	///< 指向下一个设备指针
	char		name[32];		///< 备份设备的名称。
	int			type;			///< 备份设备的介质类型，取枚举类型BDEV_TYTE的值。
	int			bus;			///< 备份设备的接口类型，取枚举类型BDEV_BUS的值。
	unsigned int	capability;	///< 总容量，以Kilo-Bytes为单位。
	unsigned int	remain;		///< 剩余容量，以Kilo-Bytes为单位。
	char		directory[128];	///< 远程备份的目录 
	int			flag;			///< 标志1，仅供底层使用。
	void		*priv;			///< 私有数据，仅供底层使用。
} BACKUP_DEVICE;

/// 备份文件结构
typedef struct BACKUP_FILE
{
	char				name[128];	///< 待备份的文件名。	
	_uint64				length;		///< 文件长度，以Kilo-Bytes为单位。这里改成字节为单位 2006-01-05 
} BACKUP_FILE;

/// 备份返回值
enum backup_ret_t 
{
	BACKUP_RET_OK,					///< 
	BACKUP_RET_DEVERR,				///< 
	BACKUP_RET_OVER					///< 
};

/// 得到所有备份设备的信息。
/// 
/// \param [out] pDevList 用来存放设备信息的一个BACKUP_DEVICE数组。
/// \param [in,out]  iMax 传入的值是数组的元素个数，传出的值是实际取到的个数。
///        如果实际的设备数大于数组长度，则只取传入的长度。
/// \retval 0  成功
/// \retval <0  失败
int BackupGetDevices(BACKUP_DEVICE *pDevList, int *iMax);


/// 设置文件列表，并开始备份。
/// 
/// \param [in] pDev 本地或远程备份设备的指针。
/// \param [in] pFileList 存放待备份文件信息的BACKUP_FILE数组。
/// \param [in] dwCount 待备份文件的个数。
/// \retval 0  开始成功
/// \retval <0  开始失败
int BackupStart(BACKUP_DEVICE * pDev, BACKUP_FILE *pFileList, unsigned int dwCount);


/// 停止备份，如果正在备份则中止备份。
/// 
/// \param [in] pDev 本地或远程备份设备的指针。
/// \param [in] iEjectFlag 对光驱设备有效，1弹出盘片，0不弹出；非光驱设备无效
/// \retval 0  停止成功
/// \retval <0  停止失败
int BackupStop(BACKUP_DEVICE * pDev, int iEjectFlag);


/// 格式化备份设备。
/// 
/// \param [in] pDev 本地或远程备份设备的指针。 
/// \retval 0  清除成功
/// \retval <0  清除失败
int BackupFormat(BACKUP_DEVICE * pDev);


/// 得到设备的剩余空间。
/// 
/// \param [in] pDev 本地或远程备份设备的指针。
/// \param [out] pLength 剩余大小，以Kilo-Bytes为单位。
/// \retval 0  停止成功
/// \retval <0  停止失败
int BackupGetRemainSpace(BACKUP_DEVICE * pDev, unsigned int *pLength);


/// 打开备份文件。
/// 
/// \param [in] pDev 本地或远程备份设备的指针。
/// \param [in] pFile 待文件的信息
/// \retval 0  停止成功
/// \retval <0  停止失败
int BackupFileOpen(BACKUP_DEVICE * pDev, BACKUP_FILE * pFile);


/// 将数据写到备份设备。各个文件的数据是连续写入的，以iFile来区分。
/// 
/// \param [in] pDev 本地或远程备份设备的指针。
/// \param [in] pBuffer 待写入的数据缓冲指针。
/// \param [in] dwLength 待写入的数据长度。
/// \retval 0  写入成功
/// \retval -1　 写入失败
int BackupFileStuff(BACKUP_DEVICE * pDev, unsigned char * pBuffer, unsigned int dwLength);


/// 关闭备份文件。
/// 
/// \param [in] pDev 本地或远程备份设备的指针。
/// \retval 0  停止成功
/// \retval <0  停止失败
int BackupFileClose(BACKUP_DEVICE * pDev);


/// 备份回放，挂载该设备
/// \param [in] pdev 要挂载的设备
/// \retval 0 挂载成功
/// \retval <0 挂载失败
int BackupPlayMount(BACKUP_DEVICE *pdev);


/// 备份回放，卸载该设备
/// \param [in] pdev 要卸载的设备
/// \retval 0 卸载成功
/// \retval 0 卸载失败
int BackupPlayUmount(BACKUP_DEVICE *pdev);


/// 得到备份设备下的文件
int BackupPlayGetFiles(BACKUP_DEVICE *pdev, BACKUP_FILE *plist, int *pnum, void *condition);

////加载光盘
/// 
/// \param [in] pDev 本地或远程备份设备的指针。
/// \retval 0  关仓成功
/// \retval <0  关仓失败
int BackupMediaLoad(BACKUP_DEVICE *pdev);

////退出光盘
/// 
/// \param [in] pDev 本地或远程备份设备的指针。
/// \retval 0  开仓成功
/// \retval <0  开仓失败
int BackupMediaEject(BACKUP_DEVICE *pdev);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
