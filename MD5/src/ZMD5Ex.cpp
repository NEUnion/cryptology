// ZMD5Ex.cpp: implementation of the ZMD5Ex class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyMD5.h"
#include "ZMD5Ex.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ZMD5Ex::ZMD5Ex()
{
	// nothing to do
}

ZMD5Ex::~ZMD5Ex()
{
	// nothing to do
}

//�򴰿ڷ����û��Զ�����Ϣ,�Ա�Ѵ�����ȷ��ظ��û�
void ZMD5Ex::OnProcessing(int ProcessNum)
{
	//�򴰿��෢���Զ�����Ϣ,���������յ������Ϣ��
	//����ProcessNum��ʾ�������
	::SendMessage(m_hWnd,USER_PROCESSING,ProcessNum,0);
}

void ZMD5Ex::SetHwnd(HWND hwnd)
{
	m_hWnd=hwnd;
}
