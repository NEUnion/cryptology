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

//向窗口发送用户自定义消息,以便把处理进度返回给用户
void ZMD5Ex::OnProcessing(int ProcessNum)
{
	//向窗口类发送自定义消息,窗口类中收到这个消息后
	//根据ProcessNum显示处理进度
	::SendMessage(m_hWnd,USER_PROCESSING,ProcessNum,0);
}

void ZMD5Ex::SetHwnd(HWND hwnd)
{
	m_hWnd=hwnd;
}
