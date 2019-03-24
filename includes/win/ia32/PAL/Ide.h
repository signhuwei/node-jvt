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
/// �洢�豸ֱ�ӷ���API���ļ�ϵͳ�����ڴ˽ӿ�֮�ϡ� �洢�豸����IDEӲ�̣�
///	SD Card�ȵȣ����߽ӿڲ��ޡ�
///	\n ��������ͼ
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
/// \note ide_read��ide_write����IPO���ʣ�ide_read_dma��ide_write_dma����DMA���ʣ�
/// \n����ƽ̨��IPO�����Ѿ����������ֽӿڶ�����DMAʵ�֡�
/// @{

#define IDE_SECTOR_SIZE 512


/// IDE�豸��Ϣ�ṹ
typedef struct IDE_INFO64
{
	/// �ѹ��ص�Ӳ�̵�����,�����������̡�Ӳ�̸���Ҳ����ide_msk����1��λ������ȥ
	/// ide_bad����1��λ����. Ӧ�ó������Ӳ��ʱ, Ӳ����Ź�������: ��һ������1
	/// ��λ��Ӧ��IDEͨ���Ϲ��ص�����Ӳ�̵�Ӳ�����Ϊ0���ڶ�������1��λ��Ӧ����
	/// Ӳ�̵�Ӳ�����Ϊ1���������ơ�
	int		ide_num;

	///< IDEͨ������Ŀ��������չ��IDEͨ����
	int		ide_port;

	/// ָʾ����IDEͨ�����Ƿ����Ӳ�̣��������̡�ÿһλ��ӦIDEͨ�������̻���̣�
	/// ��λ��ʾ�Թ���Ӳ�̣�����û�С���Ӧ��ϵΪbit0��ӦIDE0�����̣�bit1��ӦIDE0
	/// �Ĵ��̣�bit2��ӦIDE1�����̣�bit3��ӦIDE1�Ĵ��̣��������ơ�
	unsigned int	ide_msk;
	
	/// ָʾ����IDEͨ�����Ƿ�����˻���Ӳ�̡�ÿһλ��ӦIDEͨ�������̻���̣���λ
	/// ��ʾ���л�Ӳ�̣�����û�С���Ӧ��ϵͬide_msk��
	unsigned int	ide_bad;
	
	/// �ѹ��ص�����Ӳ�̵�������������Ϊ��λ��������СΪIDE_SECTOR_SIZE����������
	/// 32λ����ʾ�������±�������Ӳ�̵���š�
	_uint64			ide_cap[32];
} IDE_INFO64, *pIDE_INFO64;


/// ��ʼ������IDE�豸��
/// 
/// \param ��
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int ide_init(void);


/// �õ�IDE����Ϣ��
/// 
/// \param [out] info ָ���û��������������Ӳ����Ϣ�ĽṹIDE_INFO��ָ�롣
/// \return>=0  Ӳ����Ŀ
/// \retval <0  ����ʧ��
int ide_getinfo64(IDE_INFO64 *info);


/// PIO��ʽ�����ݡ���Ӳ�����϶�����ʱ, Ӧ������Ӳ����Ϣ��ide_bad��Ӧ��λ, ����
/// ide_num��Ӧ�ı䡣
/// 
/// \param [in] dev Ӳ����š�
/// \param [in] sectors Ҫ��������������
/// \param [in] offs �����������ƫ�ơ�
/// \param [out] pdat �������ն������ݵĻ��塣
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int ide_read64(unsigned short dev, unsigned short sectors, _uint64 offs, void * pdat);


/// PIO��ʽ�����ݡ�
/// 
/// \param [in] dev Ӳ����š�
/// \param [in] sectors Ҫд�����������
/// \param [in] offs д��������ƫ�ơ�
/// \param [in] pdat ��д������ݵĻ��塣
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int ide_write64(unsigned short dev, unsigned short sectors, _uint64 offs, void * pdat);


/// ����Ӳ�̡����Ӳ�̴��ڻ״̬��ҲҪִ�л��������֤�����ڳ�ʱ���Զ�����
/// ˯��״̬��
/// 
/// \param [in] ide_no Ӳ����š�
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
int ide_wakeup(unsigned short ide_no);


/// ͬʱ���ö��Ӳ�̵Ĵ���ʱ�䣬�Խ�Լ����ʱ�䡣
/// 
/// \param [in] ide_mask Ӳ�����룬�����IDE_INFO�����붨����ͬ��
/// \param [in] minutes ��ʱʱ�䣬����Ϊ��λ�� 
/// \retval 0  �����ɹ�
/// \retval <0  ����ʧ��
/// \see IDE_INFO
int ide_setstandby_multi(unsigned long ide_mask, int minutes);


/// ע��洢�豸�䶯�ص�����
/// \param [in] hotplug �洢�豸�䶯�ص�����,diskno�䶯�Ĵ洢�豸�ţ�
///					remove 1��ʾ�洢�豸��ɾ����0��ʾ�洢�豸������
/// \retval 0	�����ɹ�
/// \retval < 0 ����ʧ��
int ide_hotplug_proc(void (*hotplug)(unsigned int diskno, int remove));

/// @} end of group

#ifdef __cplusplus
}
#endif

#endif 
