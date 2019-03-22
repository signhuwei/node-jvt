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
/// ͳһ���ݽӿڣ�֧�ֵ����ػ�Զ�̱�׼�ļ�ϵͳ�Ŀ������߹��̿�¼��
///	\n ��������ͼ:
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

/// �����豸����
typedef enum BDEV_TYTE
{
	BT_WFS,			///< �����ļ�ϵͳ��
	BT_DISK,			///< �ƶ�Ӳ�̡�
	BT_CDRW				///< ���̿�¼��
} BDEV_TYPE;

/// �����豸��������
typedef enum BDEV_BUS
{
	BB_USB = 0,				///< USB�ӿ�
	BB_1394,			///< 1394�ӿڡ�
	BB_IDE,				///< IDE�ӿڡ�
	BB_SATA,			///< SATA�ӿڡ�
	BB_MMC				///<SD�ӿ�
} BDEV_BUS;

/// �����豸�ṹ
typedef struct BACKUP_DEVICE
{
	struct BACKUP_DEVICE		*prev;	///< ָ����һ���豸ָ��
	struct BACKUP_DEVICE		*next;	///< ָ����һ���豸ָ��
	char		name[32];		///< �����豸�����ơ�
	int			type;			///< �����豸�Ľ������ͣ�ȡö������BDEV_TYTE��ֵ��
	int			bus;			///< �����豸�Ľӿ����ͣ�ȡö������BDEV_BUS��ֵ��
	unsigned int	capability;	///< ����������Kilo-BytesΪ��λ��
	unsigned int	remain;		///< ʣ����������Kilo-BytesΪ��λ��
	char		directory[128];	///< Զ�̱��ݵ�Ŀ¼ 
	int			flag;			///< ��־1�������ײ�ʹ�á�
	void		*priv;			///< ˽�����ݣ������ײ�ʹ�á�
} BACKUP_DEVICE;

/// �����ļ��ṹ
typedef struct BACKUP_FILE
{
	char				name[128];	///< �����ݵ��ļ�����	
	_uint64				length;		///< �ļ����ȣ���Kilo-BytesΪ��λ������ĳ��ֽ�Ϊ��λ 2006-01-05 
} BACKUP_FILE;

/// ���ݷ���ֵ
enum backup_ret_t 
{
	BACKUP_RET_OK,					///< 
	BACKUP_RET_DEVERR,				///< 
	BACKUP_RET_OVER					///< 
};

/// �õ����б����豸����Ϣ��
/// 
/// \param [out] pDevList ��������豸��Ϣ��һ��BACKUP_DEVICE���顣
/// \param [in,out]  iMax �����ֵ�������Ԫ�ظ�����������ֵ��ʵ��ȡ���ĸ�����
///        ���ʵ�ʵ��豸���������鳤�ȣ���ֻȡ����ĳ��ȡ�
/// \retval 0  �ɹ�
/// \retval <0  ʧ��
int BackupGetDevices(BACKUP_DEVICE *pDevList, int *iMax);


/// �����ļ��б�����ʼ���ݡ�
/// 
/// \param [in] pDev ���ػ�Զ�̱����豸��ָ�롣
/// \param [in] pFileList ��Ŵ������ļ���Ϣ��BACKUP_FILE���顣
/// \param [in] dwCount �������ļ��ĸ�����
/// \retval 0  ��ʼ�ɹ�
/// \retval <0  ��ʼʧ��
int BackupStart(BACKUP_DEVICE * pDev, BACKUP_FILE *pFileList, unsigned int dwCount);


/// ֹͣ���ݣ�������ڱ�������ֹ���ݡ�
/// 
/// \param [in] pDev ���ػ�Զ�̱����豸��ָ�롣
/// \param [in] iEjectFlag �Թ����豸��Ч��1������Ƭ��0���������ǹ����豸��Ч
/// \retval 0  ֹͣ�ɹ�
/// \retval <0  ֹͣʧ��
int BackupStop(BACKUP_DEVICE * pDev, int iEjectFlag);


/// ��ʽ�������豸��
/// 
/// \param [in] pDev ���ػ�Զ�̱����豸��ָ�롣 
/// \retval 0  ����ɹ�
/// \retval <0  ���ʧ��
int BackupFormat(BACKUP_DEVICE * pDev);


/// �õ��豸��ʣ��ռ䡣
/// 
/// \param [in] pDev ���ػ�Զ�̱����豸��ָ�롣
/// \param [out] pLength ʣ���С����Kilo-BytesΪ��λ��
/// \retval 0  ֹͣ�ɹ�
/// \retval <0  ֹͣʧ��
int BackupGetRemainSpace(BACKUP_DEVICE * pDev, unsigned int *pLength);


/// �򿪱����ļ���
/// 
/// \param [in] pDev ���ػ�Զ�̱����豸��ָ�롣
/// \param [in] pFile ���ļ�����Ϣ
/// \retval 0  ֹͣ�ɹ�
/// \retval <0  ֹͣʧ��
int BackupFileOpen(BACKUP_DEVICE * pDev, BACKUP_FILE * pFile);


/// ������д�������豸�������ļ�������������д��ģ���iFile�����֡�
/// 
/// \param [in] pDev ���ػ�Զ�̱����豸��ָ�롣
/// \param [in] pBuffer ��д������ݻ���ָ�롣
/// \param [in] dwLength ��д������ݳ��ȡ�
/// \retval 0  д��ɹ�
/// \retval -1�� д��ʧ��
int BackupFileStuff(BACKUP_DEVICE * pDev, unsigned char * pBuffer, unsigned int dwLength);


/// �رձ����ļ���
/// 
/// \param [in] pDev ���ػ�Զ�̱����豸��ָ�롣
/// \retval 0  ֹͣ�ɹ�
/// \retval <0  ֹͣʧ��
int BackupFileClose(BACKUP_DEVICE * pDev);


/// ���ݻطţ����ظ��豸
/// \param [in] pdev Ҫ���ص��豸
/// \retval 0 ���سɹ�
/// \retval <0 ����ʧ��
int BackupPlayMount(BACKUP_DEVICE *pdev);


/// ���ݻطţ�ж�ظ��豸
/// \param [in] pdev Ҫж�ص��豸
/// \retval 0 ж�سɹ�
/// \retval 0 ж��ʧ��
int BackupPlayUmount(BACKUP_DEVICE *pdev);


/// �õ������豸�µ��ļ�
int BackupPlayGetFiles(BACKUP_DEVICE *pdev, BACKUP_FILE *plist, int *pnum, void *condition);

////���ع���
/// 
/// \param [in] pDev ���ػ�Զ�̱����豸��ָ�롣
/// \retval 0  �زֳɹ�
/// \retval <0  �ز�ʧ��
int BackupMediaLoad(BACKUP_DEVICE *pdev);

////�˳�����
/// 
/// \param [in] pDev ���ػ�Զ�̱����豸��ָ�롣
/// \retval 0  ���ֳɹ�
/// \retval <0  ����ʧ��
int BackupMediaEject(BACKUP_DEVICE *pdev);

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
