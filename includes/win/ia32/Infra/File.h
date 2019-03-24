//
//  "$Id: File.h 4 2009-08-17 14:09:00Z liwj $"
//
//  Copyright (c)2008-2010, ZheJiang JuFeng Technology Stock CO.LTD.
//  All Rights Reserved.
//
//	Description:	
//	Revisions:		Year-Month-Day  SVN-Author  Modification
//

#ifndef __INFRA_FILE_H__
#define __INFRA_FILE_H__

#include <string>
#include "Types.h"

#ifndef FILE_INFO_DEFINED
/// \struct FileInfo
/// \brief �ļ���Ϣ�ṹ
typedef struct _FileInfo
{
	char	name[108];		///< �ļ���(���ļ������������)
	uint	attrib;			///< �ļ�����
	uint64	time;			///< �ļ��޸�ʱ��
	uint64	size;			///< �ļ���С
}FileInfo;
#define FILE_INFO_DEFINED
#endif

struct FSOperations;

/// \class CFile
/// \brief �ļ������װ
class CFile
{
public:

	/// �ļ��򿪱�־
	enum OpenFlags {
		modeRead =         (int) 0x00000, ///< Ϊ����һ���ļ�������ļ������ڻ��޷��򿪣�Open����ʧ�ܡ�
		modeWrite =        (int) 0x00001, ///< Ϊд����һ�����ļ�������ļ����ڣ������ݽ������١�
		modeReadWrite =    (int) 0x00002, ///< Ϊ��д��һ���ļ�������ļ������ڻ��޷��򿪣�Open����ʧ�ܡ�
		shareCompat =      (int) 0x00000,
		shareExclusive =   (int) 0x00010,
		shareDenyWrite =   (int) 0x00020,
		shareDenyRead =    (int) 0x00030,
		shareDenyNone =    (int) 0x00040,
		modeNoInherit =    (int) 0x00080,
		modeCreate =       (int) 0x01000, ///< ����ļ������ڣ��Զ������ļ�����modeReadWrite���ʹ�á�
		modeNoTruncate =   (int) 0x02000, ///< ��modeCreateһ��ʹ�ã����Ҫ�������ļ��Ѿ����ڣ�ԭ�������ݱ�����
		typeText =         (int) 0x04000, 
		typeBinary =       (int) 0x08000, 
		osNoBuffer =       (int) 0x10000, ///< �ϲ㴦���壬��ʱ��д��ƫ�ƺͳ��ȶ���Ҫ��ҳ���С���롣
		osWriteThrough =   (int) 0x20000,
		osRandomAccess =   (int) 0x40000,
		osSequentialScan = (int) 0x80000,
	};


	/// �ļ�����
	enum Attribute {
		normal =    0x00,
		readOnly =  0x01,
		hidden =    0x02,
		system =    0x04,
		volume =    0x08,
		directory = 0x10,
		archive =   0x20
	};


	/// �ļ���λ�ο�λ��
	enum SeekPosition
	{
		begin = 0x0,
		current = 0x1,
		end = 0x2 
	};


	/// �ļ�����ģʽ
	enum AccessMode
	{
		accessExist = 0,		///< �ļ��Ƿ����
		accessWrite = 2,		///< �ļ��Ƿ����дȨ��
		accessRead = 4,			///< �ļ��Ƿ���ж�Ȩ��
		accessReadWrite = 6,	///< �ļ��Ƿ���ж�дȨ��
	};
	

	/// ���캯����
	CFile();


	/// ����������������ݻ��廹��Ч���ᱻ�ͷš�
	virtual ~CFile();


	/// ���ļ����򿪺��ļ�ָ��ƫ����0��������modeAppend��־�򿪵��ļ��ļ�ָ�����ļ�ĩβ��
	/// \param [in] pFileName �ļ�����
	/// \param [in] dwFlags �򿪱�־��Ĭ��ΪmodeReadWrite��
	/// \retval true  �򿪳ɹ�
	/// \retval false  ��ʧ�ܣ��ļ������ڻ��޷��򿪡�
	virtual bool Open(const char* pFileName, uint dwFlags = modeReadWrite);


	/// �ر��ļ���
	virtual void Close();


	/// װ�����ݣ�������ļ�����һ����С�Ļ��壬���ļ����ݶ����û��壬���ػ���ָ�롣
	/// ��UnLoad����һ���ṩ����
	/// \param [in] pFileName �ļ�����
	/// \retval NULL  װ��ʧ��
	/// \retval !NULL  ���ݻ���ָ�롣
	unsigned char * Load(const char* pFileName);


	/// �ͷ����ݻ���
	void UnLoad();


	/// ���ļ����ݡ����������ļ�ָ���Զ��ۼӡ�
	/// \param [out] pBuffer ���ݻ����ָ�롣
	/// \param [in] dwCount Ҫ�������ֽ���
	/// \retval >0  �������ֽ���
	/// \retval <=0 ��ʧ��
	virtual uint Read(void *pBuffer, uint dwCount);


	/// д�ļ����ݡ����������ļ�ָ���Զ��ۼӡ�
	/// \param [out] pBuffer ���ݻ����ָ�롣
	/// \param [in] dwCount Ҫд����ֽ���
	/// \retval >0  д����ֽ���
	/// \retval <=0 дʧ��
	virtual uint Write(const void *pBuffer, uint dwCount);


	/// ͬ���ļ��ײ㻺�壬��д��������ã�ȷ��д��������Ѿ���������ϵͳ��
	virtual void Flush();


	/// �ļ���λ��
	/// \param [in] lOff ƫ�������ֽ�Ϊ��λ��
	/// \param [in] nFrom ƫ�����λ�ã����õ���ƫ��ΪlOff+nFrom��
	/// \return ƫ�ƺ��ļ���ָ��λ�á�
	virtual uint Seek(long lOff, uint nFrom);


	/// ���ص�ǰ���ļ�ָ��λ��
	virtual uint GetPosition();


	/// �����ļ�����
	virtual uint GetLength();


	/// ���ı��ļ���ǰƫ�ƴ���ȡһ���ַ��������������ļ�ָ���Զ��ۼӡ�
	/// \param [out] s ���ݻ��塣
	/// \param [in] size ��Ҫ��ȡ���ַ������ȡ�
	/// \retval NULL  ��ȡʧ��
	/// \retval !NULL  �ַ���ָ�롣
	virtual char * Gets(char *s, int size);


	/// ���ı��ļ���ǰƫ�ƴ�д��һ���ַ�����д�������ļ�ָ���Զ��ۼӡ�
	/// \param [in] s ���ݻ��塣
	/// \return  ʵ��д���ַ������ȡ�
	virtual int Puts(const char *s);


	/// �ж��ļ��Ƿ��
	virtual bool IsOpened();


	/// ��ȡ�ļ�·��
	/// \return �ļ�·��ָ��
	virtual const char *GetFilePath() const;


	/// �������ļ�
	/// \param oldName �ɵ��ļ���
	/// \param newName �µ��ļ���
	static bool Rename(const char* oldName, const char* newName);


	/// ɾ���ļ�
	/// \param fileName �ļ���
	static bool Remove(const char* fileName);


	/// ����Ŀ¼
	/// \param Ŀ¼��
	static bool MakeDirectory(const char* dirName);


	/// ɾ��Ŀ¼
	/// \param Ŀ¼��
	static bool RemoveDirectory(const char* dirName);


	/// ����ļ��Ƿ������Ӧ��Ȩ��
	/// \param [in] filename Ҫ�����ļ���
	/// \param [in] mode ����Ȩ��
	/// \return �Ƿ���и÷���Ȩ��
	static bool Access(const char *filename, AccessMode mode);


	/// �ļ�ϵͳͳ��
	/// \param path ����·������һ���Ƿ�����Ŀ¼��
	/// \param userFreeBytes Ŀ¼�����ļ�ϵͳ��������û���ʣ��ռ��ֽ���
	/// \param totalBytes Ŀ¼�����ļ�ϵͳ�ܵ��ֽ���
	/// \param totalFreeBytes Ŀ¼�����ļ�ϵͳ�ܵ�ʣ��ռ��ֽ��������ʹ����Ӳ��
	///        �ռ���userFreeBytes���ܻ��totalFreeBytesС
 	static bool StatFS(const char* path, uint64* userFreeBytes, uint64* totalBytes, uint64* totalFreeBytes);


protected:
	FILE *m_pFile;							///< ��׼����ļ��ṹָ�롣
	char m_pFilePath[260];
	unsigned char *m_pBuffer;		///< �ļ����ݻ��壬Load��UnLoad�ӿ�ʹ�á�
	uint m_dwLength;						///< �ļ����ȡ�
	FSOperations* m_opt;				///< �ļ�ϵͳ������
};

/// \brief �ļ������֧࣬��'*','?'ͨ�������
class CFileFind
{
public:
	
	CFileFind();
	virtual ~CFileFind();
	virtual bool findFile(const char* fileName);
	virtual bool findNextFile();
	virtual void close();
	virtual uint64 getLength();
	virtual std::string getFileName();
	virtual std::string getFilePath();
	virtual bool isReadOnly();
	virtual bool isDirectory();
	virtual bool isHidden();
	virtual bool isNormal();

protected:
	long m_handle;
	FileInfo m_fileInfo;
	FSOperations* m_opt;		///< �ļ�ϵͳ������
	std::string m_path;			///< ����·����
};

/// �ļ�ϵͳ����������
struct FSOperations
{
	FILE* (*fopen)(const char *, const char *);
	int (*fclose)(FILE *);
	size_t (*fread)(void *, size_t, size_t, FILE *);
	size_t (*fwrite)(const void *, size_t, size_t, FILE *);
	int (*fflush)(FILE *);
	int (*fseek)(FILE *, long, int);
	long (*ftell)(FILE *);
	char * (*fgets)(char *, int, FILE *);
	int (*fputs)(const char *, FILE *);
	int (*access)(const char *fileName, int mode);
	int (*rename)(const char *oldname, const char *newname);
	int (*remove)(const char *path);
	long (*findfirst)(const char *, FileInfo *);
	int (*findnext)(long, FileInfo * );
	int (*findclose)(long);
	int (*mkdir)(const char *dirName);
	int (*rmdir)(const char *dirName);
	int (*statfs)( const char *path, uint64* userFreeBytes, uint64* totalBytes, uint64* totalFreeBytes);
};

/// Ϊ�˼����������ں��ļ�ϵͳ��֧�����ù��ӽӿڣ�ͨ����װ��ģ��ʵ����Щ�ӿڡ�
/// \param path ƥ���·��
/// \param opts �ļ�ϵͳ�ļ�������������0��ʾȡ������
void hookFS(const char* path, const FSOperations* opts);

#endif 
