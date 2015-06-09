#ifndef IMAGEPROCESSBASE_H
#define IMAGEPROCESSBASE_H

#include "sysdef.h"
#include "imageprocess_global.h"

/*! \typedef typedef ReturnCurPos
*  \brief Pass������ȷ���
*
* ��ǰPass������ȷ���
*/
typedef void(__cdecl *ProcessPosCallback)(int nPos);


/*! \typedef typedef ReturnCurPos
*  \brief Pass�����ϴ����ݻص�
*
* ��ǰPass�ϴ����ݻص�
*/
typedef void(__cdecl *DownloadImageDataToHardware)(unsigned char* lpWriteData, unsigned int uiBufferID, unsigned int uiBytes);


/*! \typedef typedef ReturnCurPos
*  \brief ��ӡ����ӿ���
*
* ��ӡ���ݴ���
*/
class IMAGEPROCESS_EXPORT CImgProcessBase
{
public:
	//virtual ~CImgProcessBase() = 0;

public:
	// ��ӡǰ��ʼ��
	virtual IMAGEPROCESS_EXCEPTION ProcessInit(PROCESS_PARAM* lpParam) = 0;
	// ���´�ӡ������(��ͷ/��ɫ�ȴ�ӡ�����ò���)
	virtual void UpdateSysInfo(PRINTER& sSysInfo, bool bCurTask, bool bInitSys) = 0;
	// ��ӡ�����������ͷŹ���
	virtual IMAGEPROCESS_EXCEPTION CleanUp() = 0;
	// ���ݴ����ϴ�
	virtual IMAGEPROCESS_EXCEPTION ProcessImg(int nCount, bool bDir, LPCUR_PASS_INFO pCurPassInfo
		, bool bWaitingProcessEnd = true, ProcessPosCallback callbackPos = NULL, DownloadImageDataToHardware downloadData = NULL) = 0;
	// ��ӡ�ȴ���ǰPass�����ϴ���ϣ�pSmartPrintInfo ���ص�������Ϣ�������˶�����ʵ�����׶�����
	virtual IMAGEPROCESS_EXCEPTION WaitingForProcessOK(long dwMilliseconds = 10000, LPSMART_PRINT_INFO pSmartPrintInfo = NULL) = 0;
};

CImgProcessBase* CreareImageProcessObj();
void CDestoryImageProcessObj(CImgProcessBase* p);

#endif // IMAGEPROCESSBASE_H
